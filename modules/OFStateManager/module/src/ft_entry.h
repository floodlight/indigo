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

#include <AIM/aim_list.h>
#include <indigo/indigo.h>
#include <loci/loci.h>
#include <minimatch/minimatch.h>

#include "ofstatemanager_int.h"

/****************************************************************
 * The flow entry structure
 ****************************************************************/

/**
 * The data in a flow table entry
 *
 * @param id The externally determined unique flow ID
 * @param minimatch The compressed match structure recorded from the original add
 * @param priority The priority, from the original add
 * @param idle_timeout The idle_timeout, from the original add
 * @param hard_timeout The hard_timeout, from the original add
 * @param flags The flags, from the original add
 * @param table_id The table id, from the original add
 * @param priv Opaque data returned by the entry_create operation
 * @param cookie The cookie, from the original or as updated
 * @param effects The actions or instructions from the add or as updated.
 * See below.
 * @param insert_time The timestamp when the entry was inserted
 * @param last_counter_change Last update when counters changed
 * @param table_links For iterating across the flow table
 * @param strict_match_hash_entry Search by strict match
 * @param cookie_links Search by cookie
 * @param expiration_links Linked into expiration_queue if a timeout was specified
 * @param iterators List of ft_iterator_t objects pointing to this entry
 *
 * The effects (actions or instructions) are tied to a specific OpenFlow
 * version. For example, a flow may be added using OpenFlow 1.0 but
 * modified using OpenFlow 1.3. Either union member may be used to check
 * the version and LOCI object type.
 *
 * The match, priority, and table-id are invariant once the entry has been
 * added to the table. The timeouts and flags may be updated by overwriting the
 * entry with a flow-add. The cookie and effects may be updated by a flow-modify.
 */

typedef struct ft_entry_s {
    indigo_flow_id_t id;
    minimatch_t minimatch;
    uint16_t priority;
    uint16_t idle_timeout;
    uint16_t hard_timeout;
    uint8_t flags;
    uint8_t table_id;
    void *priv;

    /* May be changed by flow-modify */
    uint64_t cookie;
    union {
        of_list_action_t *actions;
        of_list_instruction_t *instructions;
    } effects;

    /* Updated by implementation */
    indigo_time_t insert_time;
    indigo_time_t last_counter_change;

    /* Datastructure links */
    list_links_t table_links;      /* For iterating across the flow table */
    bighash_entry_t strict_match_hash_entry;  /* Search by strict match */
    list_links_t cookie_links;     /* Search by cookie */
    list_links_t expiration_links; /* Expiration list entry */
    list_head_t iterators;         /* List of ft_iterator_t objects
                                      pointing to this entry */
} ft_entry_t;

/**
 * Get the container of a links pointer
 * @param link_ptr Pointer to the list_links_t of interest
 * @param type One of prio, flow_id, table to get the proper variable
 */

#define FT_ENTRY_CONTAINER(links_ptr, type)             \
    container_of((links_ptr), type ## _links, ft_entry_t)

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
 */

/**
 * How to treat match criteria
 * Mq is match for query; Me is match for entry
 */
typedef enum of_match_mode_e {
    OF_MATCH_NON_STRICT,    /* FS(Mq) contains FS(Me) */
    OF_MATCH_STRICT,        /* Strict match as per spec */
    OF_MATCH_OVERLAP,       /* Check for overlap */
} of_match_mode_t;

/**
 * General meta match criteria
 *
 */
#define TABLE_ID_ANY (0xff)

typedef struct of_meta_match_s {
    minimatch_t minimatch;  /* Compressed match object for the query */
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

extern int ft_entry_meta_match(of_meta_match_t *query, ft_entry_t *entry);

void metamatch_cleanup(of_meta_match_t *metamatch);

#endif /* _OFSTATEMANAGER_FT_ENTRY_H_ */
