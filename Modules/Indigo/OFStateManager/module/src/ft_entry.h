/****************************************************************
 *
 *        Copyright 2013, Big Switch Networks, Inc. 
 * 
 * Licensed under the Eclipse Public License, Version 1.0 (the
 * "License"); you may not use this file except in compliance
 * with the License. You may obtain a copy of the License at
 * 
 *        http://www.eclipse.org/legal/epl-v10.html
 * 
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
 * either express or implied. See the License for the specific
 * language governing permissions and limitations under the
 * License.
 *
 ****************************************************************/

#ifndef _OFSTATEMANAGER_FT_ENTRY_H_
#define _OFSTATEMANAGER_FT_ENTRY_H_

#include <indigo/of_connection_manager.h>
#include <AIM/aim_list.h>
#include <indigo/indigo.h>
#include <loci/loci.h>

#include "ofstatemanager_int.h"

/**
 * Flow state enumeration
 *
 * Indicates the state in the flow table of a flow entry.  These are
 * only valid when the entry's ID is valid (not INDIGO_FLOW_ID_INVALID).
 *
 * Due to the async nature of flow table modifications, we maintain
 * these states for each flow.  Note that if a flow is deleted while
 * an operation is outstanding for that flow, we must queue the operation
 * until it has completed.  If a delete operation occurs on a flow, we
 * ignore further operations on that flow, wait for any pending operation
 * to complete and then remove any other queued operations.
 *
 * There are still some corner cases; for example, if a queued operation
 * would have failed, but a later delete operation occurs, no error
 * message will be generated for the op that would have failed.
 *
 * States:
 *
 * FREE => Not in use.
 * NEW => Allocated but not committed; call is being made to fwding
 * CREATED => Flow is stable, successfully added to forwarding, nothing pending
 * MODIFYING => Modify request is pending with forwarding, but entry
 * should be counted as active.
 * DELETE_MARKED => Flow is marked for deletion; other modify calls pending
 * DELETING => Request to delete the entry has been made to forwarding
 */

enum ft_flow_state {
    FT_FLOW_STATE_FREE,
    FT_FLOW_STATE_NEW,
    FT_FLOW_STATE_CREATED,
    FT_FLOW_STATE_MODIFYING,
    FT_FLOW_STATE_DELETE_MARKED,
    FT_FLOW_STATE_DELETING
};

#define FT_FLOW_STATE_IS_STABLE(x)  ((x) == FT_FLOW_STATE_CREATED)
#define FT_FLOW_STATE_IS_DELETED(x) ((x) >= FT_FLOW_STATE_DELETE_MARKED)

/****************************************************************
 * The flow entry structure
 ****************************************************************/

/**
 * The data in a flow table entry
 *
 * @param id The externally determined flow ID; primary key
 * @param delete_reason Why deleted; see below
 * @param match The match structure recorded from the original add
 * @param priority The priority, from the original add
 * @param idle_timeout The idle_timeout, from the original add
 * @param hard_timeout The hard_timeout, from the original add
 * @param flow_add Pointer to the original add object
 * @param cookie The cookie, from the original or as updated
 * @param effects The actions or instructions from the add or as updated.
 * See below.  May not be maintained by all implementations.
 * @param output_ports The list of output ports for the action for searching
 * @param insert_time The timestamp when the entry was inserted
 * @param packets Number of packets matched by the entry
 * @param bytes Number of bytes matched by the entry
 * @param last_counter_update When counters were last checked
 * @param last_counter_change Last update when counters changed
 * @param table_links For iterating across the flow table
 *
 * The version of the entry is determined by the value in the match
 * structure.  This is used in determining whether actions or instructions
 * are active.
 *
 * The match, priority, timeouts and flow_add are invariant once the entry
 * has been added to the table.  The cookie and effects may be updated by
 * modify commands.
 */

typedef struct ft_entry_s {
    /* Key */
    indigo_flow_id_t     id;

    /* Flow state -- see above */
    enum ft_flow_state state;

    /* Reason why flow was deleted */
    indigo_fi_flow_removed_t removed_reason;

    /* Queue of pending requests from controller for flow.
       In practice, this queue will only hold either:
       (1) a sequence of modify requests, or
       (2) a single delete request.
       Rationale:
       - Create requests can't be queued (they create *new* flows)
       - Modify requests must be queued, since the state of a flow must be
         that of the last successful modify request
       - Delete requests can short-circuit any pending modifies; there's no
         point in doing a modify on a flow that you know is going to go away
         (Minor point: if any short-circuited modify would have generated an
         error message, that error message will not be generated)
     */
    biglist_t *queued_reqs;

    /* Invariant */
    of_match_t match;
    uint16_t priority;
    uint16_t idle_timeout;
    uint16_t hard_timeout;
    uint16_t flags;
    of_flow_add_t *flow_add;

    /* Modifiable thru API calls */
    uint64_t cookie;
    union { /* May not be maintained by some implementations */
        of_list_action_t *actions;
        of_list_instruction_t *instructions;
    } effects;

    /* Updated by implementation */
    uint8_t table_id;
    biglist_t *output_ports;
    indigo_time_t insert_time;
    uint64_t packets;
    uint64_t bytes;
    indigo_time_t last_counter_change;

    /* For linear flow table:  DEPRECATED */
    struct ft_entry_s *id_bucket_next;

    /* For linked list maintance */
    list_links_t table_links;      /* For iterating across the flow table */
} ft_entry_t;

/**
 * Get the container of a links pointer
 * @param link_ptr Pointer to the list_links_t of interest
 * @param type One of prio, flow_id, table to get the proper variable
 */

#define FT_ENTRY_CONTAINER(links_ptr, type)             \
    container_of((links_ptr), type ## _links, ft_entry_t)

/* Simple deferencing macro for OF 1.0 actions */
#define FT_FLOW_ACTIONS(entry) ((entry)->effects.actions)

/***** MATCHING *****/

/**
 * Flow table queries
 *
 * Since matching is based on properties of an entry, these declarations
 * are here in ft_entry
 *
 * There are two types of flow table queries:
 *
 * (1) Match a packet:  match packet fields to the entry's match structure;
 * (2) Query for a set of flow entries:  Use meta-match criteria including
 * the entry's match structure as well as cookies, priority or time since added.
 *
 * For core, the first is only needed for the "table" action on packet out,
 * and possibly not even then.  We do not currently optimize for this case.
 *
 * For the second, we can use "flow space" to describe the relationship.
 * This is described more fully elsewhere.  In short: Given a match, M,
 * let FS(M) be the subset of flow space that is determined by the match.
 *
 * The OpenFlow spec refers to a "strict match".  Given a query match, Mq,
 * the strict match is a match, M, (whose priority must be specified and) such
 * that FS(M) == FS(Mq).
 *
 * For a query match, Mq, the "non-strict match" is the set of entries for
 * which each M in the set satisfies FS(M) is a subset of FS(Mq).
 *
 * For queries, the called routine will allocate the the variable length
 * list of flow IDs and the caller is responsible freeing it.
 */

/**
 * How to treat match criteria
 * Mq is match for query; Me is match for entry
 */
typedef enum of_match_mode_e {
    OF_MATCH_NON_STRICT = 0,
    OF_MATCH_SUPER_SET = 0,     /* FS(Mq) contains FS(Me);
                                   Same as non-strict match */
    OF_MATCH_STRICT = 1,        /* Strict match as per spec */
    OF_MATCH_EQUAL = 1,         /* FS(Mq) == FS(Me) */
    OF_MATCH_COOKIE_ONLY = 2,   /* Matching only on cookie */
    OF_MATCH_OVERLAP = 3        /* Check for overlap */
} of_match_mode_t;

/**
 * General meta match criteria
 *
 */
#define TABLE_ID_ANY (0xff)

typedef struct of_meta_match_s {
    of_match_t match;       /* The match object for the query */
    of_match_mode_t mode;   /* See above */
    uint64_t cookie;
    uint64_t cookie_mask;   /* If 0, do not match cookie */
    uint16_t priority;
    int check_priority;     /* Boolean; should priority be checked */
    int check_overlap;      /* Boolean, for adds */
    of_port_no_t out_port;  /* OFPP_ANY means do not match */
    uint8_t table_id;       /* Set to TABLE_ID_ANY to wildcard */
} of_meta_match_t;

/**
 * @brief Determine if an entry's match agrees with the metamatch data
 * @param query The match information from the query
 * @param entry Pointer to the flow table entry being checked
 * @returns Boolean, true if entry matches meta_match data
 */

extern int ft_flow_meta_match(of_meta_match_t *query, ft_entry_t *entry);

#endif /* _OFSTATEMANAGER_FT_ENTRY_H_ */
