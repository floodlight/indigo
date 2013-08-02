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

/**
 * @file
 * @brief Interface for OFStateManager flow table module
 *
 * Normally, the flow table is used in the following way:
 *
 * Create an instance based on fixed or external configuration
 * For each flow add that comes in:
 *    Create a new entry in the local table in a "creating" state
 *    Push the flow add across the HAL boundary
 *    When the successful response comes back
 *        Change the state in the local table to "stable"
 *
 * Usage Conventions
 *
 * The flow table entry structure is published here.  It has a pointer
 * to the original flow add.  After an implementation completes the "add"
 * operation, it should never refer to that pointer.
 *
 * The flow table is logically a database with a single primary key, the
 * integer flow ID.  This value is determined by the client of the flow
 * table instance.
 *
 * When a client receives a reference to a flow table entry, it must
 * treat the entire structure as read-only.
 */

#ifndef _OFSTATEMANAGER_FT_H_
#define _OFSTATEMANAGER_FT_H_

#include <indigo/indigo.h>
#include <indigo/fi.h>
#include <loci/loci.h>
#include <BigList/biglist.h>
#include <hindex/hindex.h>
#include <AIM/aim_list.h>
#include <indigo/of_connection_manager.h>

#include "ft_entry.h"

/**
 * Need forward declarations of table structure before including driver
 */

/**
 * Forward declaration of connection handle for other typedefs
 */

typedef struct ft_public_s ft_public_t;

/**
 * A handle is a pointer to an instance.
 */

typedef ft_public_t *ft_instance_t;

/**
 * Map from a list entry to a flow entry pointer.
 *
 * The flow table abstraction uses BigLists for queries.  These
 * use ft_entry_t pointers for their data.
 */

#define FT_LIST_TO_ENTRY(elt) ((ft_entry_t *)((elt)->data))

/**
 * Map from a list entry to a flow ID.
 */

#define FT_LIST_TO_FLOW_ID(elt)                            \
    (INDIGO_POINTER_TO_COOKIE(FT_LIST_TO_ENTRY(elt)->id))

/****************************************************************
 * Managing a flow table instance: Configuration, status, handle
 ****************************************************************/

/**
 * Callback prototype for notifying of a deleted entry
 * @param ft Handle for a flow table instance
 * @param entry Pointer to the entry that was deleted
 * @param cookie Data passed on flow table create
 *
 * It is required that the table driver will make no reference to the flow_add
 * pointer after this callback returns.
 */
typedef void (*ft_entry_deleted_f)(ft_instance_t ft,
                                   ft_entry_t *entry,
                                   void *cookie);



/**
 * Flow table configuration structure
 * @param max_entries Maximum number of entries to support
 * @param prio_bucket_count How many buckets for priority hash table
 * @param match_bucket_count How many buckets for match hash table
 * @param flow_id_bucket_count How many buckets for flow_id hash table
 * @param entry_deleted_callback Callback made for async deletes
 * @param deleted_cookie Data passed to entry_deleted_callback
 *
 * If entry_deleted_callback is NULL, no callbacks will be made when table
 * entries are deleted.
 *
 * Note that entry_deleted_callback may be called when the flow_delete
 * driver function is called based on the flags passed to the flow_delete call.
 */

typedef struct ft_config_s {
    int max_entries;
    int prio_bucket_count;
    int match_bucket_count;
    int flow_id_bucket_count;
    ft_entry_deleted_f entry_deleted_cb;
    void *deleted_cookie;
} ft_config_t;

/**
 * Flow table status structure
 * @param current_count Current number of entries in the table not
 * in the init state (including pending deletes)
 * @param pending_deletes Number of entries in the table in the process of
 * being deleted (in the DELETE_MARKED or DELETING state).  DEBUG ONLY.
 * @param deletes Number of delete operation called
 * @param hard_expires Number of hard timeouts
 * @param idle_expires Number of idle timeouts
 * @param updates Number of calls that modified a flow entry including
 * effects_modify, cookie_modify and clear_counters.
 * @param table_full_errors Number of adds that failed due to no space
 * in the table.
 * @param forwarding_add_errors Number of adds that failed due to a
 * failure in the forwarding layer.
 */

typedef struct ft_status_s {
    int current_count;
    int pending_deletes;
    uint64_t adds;
    uint64_t deletes;
    uint64_t hard_expires;
    uint64_t idle_expires;
    uint64_t updates;
    uint64_t table_full_errors;
    uint64_t forwarding_add_errors;
} ft_status_t;

/**
 * The public view of the instance for easier dereference
 *
 * With the driver table implementation gone, this exposes more of
 * the internals now.
 *
 * This should be treated as read-only outside of the
 * flow table instance implementation
 */
struct ft_public_s {
    ft_config_t config;
    ft_status_t status;

    ft_entry_t *flow_entries;      /* All entries */

    list_head_t free_list;         /* List of unused entries */
    list_head_t all_list;          /* Single list of all current entries */

    list_head_t *prio_buckets;     /* Array of priority based buckets */
    list_head_t *match_buckets;    /* Array of strict match based buckets */

    struct hindex *flow_id_index;  /* hashtable keyed on flow id */

    uint32_t magic; /* For debug/error checking */
};

#define FT_CONFIG(_ft) (&(_ft)->config)
#define FT_STATUS(_ft) (&(_ft)->status)

/* These defines come from the original table driven version */
/* Redefine FT macros to use hash table or generic calls */
#define FT_ADD(_ft, _id, _flow_add, _entry_p)                           \
    ft_hash_flow_add(_ft, _id, _flow_add, _entry_p)
#define FT_DELETE_ID(_ft, _id, _cb)                                     \
    ft_hash_flow_delete_id(_ft, _id, _cb)
#define FT_MARK_ENTRIES(_ft, _q, _state, _reason)                       \
    (FT_DRIVER(_ft)->mark_entries((_ft), (_q), (_state), (_reason)))
#define FT_ENTRY_FREE(_ft, _entry, _cb)                                 \
    ft_hash_flow_delete(_ft, _entry, _cb)
#define FT_QUERY(_ft, _q)                                               \
    ft_flow_query(_ft, _q)
#define FT_FIRST_MATCH(_ft, _q, _entry_p)                               \
    ft_flow_first_match(_ft, _q, _entry_p)
#define FT_MODIFY_EFFECTS(_ft, _entry, _flow_mod)                       \
    ft_flow_modify_effects(_ft, _entry, _flow_mod)
#define FT_MODIFY_COOKIE(_ft, _entry, _cookie, _mask)                   \
    ft_flow_modify_cookie(_ft, _entry, _cookie, _mask)
#define FT_CLEAR_COUNTERS(_ft, _entry, _pkts, _bytes)                   \
    ft_flow_clear_counters(_ft, _entry, _pkts, _bytes)

/**
 * Safe iterator for entire flow table
 *
 * This is a more efficient alternative to using the iter object
 * from the driver.
 *
 * The current entry may be deleted during this iteration.
 * @param _ft The instance of the flow table being iterated
 * @param _entry Pointer to the "current" entry in the iteration
 * @param _cur list_link_t bookkeeping pointer, do not reference
 * @param _next list_link_t bookkeeping pointer, do not refernece
 *
 * Assumes the ft_instance is initialized
 */

#define FT_ITER(_ft, _entry, _cur, _next)                               \
    if (!list_empty(&(_ft)->all_list))                                  \
        for ((_cur) = (_ft)->all_list.links.next,                       \
                 _entry = FT_ENTRY_CONTAINER(_cur, table);              \
             _next = _cur->next, _cur != &((_ft)->all_list.links);      \
             _cur = _next, _entry = FT_ENTRY_CONTAINER((_cur), table))

/**
 * Iterate across flows of a given priority (hash value)
 *
 * @param _ft The instance of the flow table being iterated
 * @param _prio The priority of the entries being sought
 * @param _idx Index of the priority bucket hash list
 * @param _entry Pointer to the "current" entry in the iteration
 * @param _cur list_link_t bookkeeping pointer, do not reference
 * @param _next list_link_t bookkeeping pointer, do not refernece
 *
 * You need to compute the bucket index (using the hash function on
 * the priority) before calling this macro.  Suggest you use an
 * auto variable to hold the result as the result is instantiated
 * multiple times.
 *
 * Assumes the ft_instance is initialized
 */

#define FT_PRIO_ITER(_ft, _prio, _idx, _entry, _cur, _next)             \
    if (!list_empty(&(_ft)->prio_buckets[_idx]))                        \
        for ((_cur) = (_ft)->prio_buckets[_idx].links.next,             \
                 _entry = FT_ENTRY_CONTAINER(_cur, prio);               \
             _next = _cur->next,                                        \
                 _cur != &((_ft)->prio_buckets[_idx].links);            \
             _cur = _next, _entry = FT_ENTRY_CONTAINER(_cur, prio))     \
            if ((_entry)->priority == _prio)

/**
 * Iterate across flows with a given match
 *
 * @param _ft The instance of the flow table being iterated
 * @param _match The match of the entries being sought strictly
 * @param _idx Index of the match bucket hash list
 * @param _entry Pointer to the "current" entry in the iteration
 * @param _cur list_link_t bookkeeping pointer, do not reference
 * @param _next list_link_t bookkeeping pointer, do not refernece
 *
 * You need to compute the bucket index (using the hash function on
 * the match object) before calling this macro.  Suggest you use an
 * auto variable to hold the result as the result is instantiated
 * multiple times.
 *
 * Assumes the ft_instance is initialized
 *
 * @fixme of_match_eq may not work on non-canonicalized flows
 *
 * @note Note that this does not check that the priority of the
 * entry matches any particular priority.
 */

#define FT_MATCH_ITER(_ft, _match, _idx, _entry, _cur, _next)           \
    if (!list_empty(&(_ft)->match_buckets[_idx]))                       \
        for ((_cur) = (_ft)->match_buckets[_idx].links.next,            \
                 _entry = FT_ENTRY_CONTAINER(_cur, match);              \
             _next = _cur->next,                                        \
                 _cur != &((_ft)->match_buckets[_idx].links);           \
             _cur = _next, _entry = FT_ENTRY_CONTAINER(_cur, match))    \
            if (of_match_eq((_match), &((_entry)->match)))

#endif /* _OFSTATEMANAGER_FT_H_ */

