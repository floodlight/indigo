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
#include <AIM/aim_list.h>

#include "ft_entry.h"

/**
 * Forward declaration of flowtable handle for other typedefs
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
 * Flow table configuration structure
 * @param max_entries Maximum number of entries to support
 * @param prio_bucket_count How many buckets for priority hash table
 * @param match_bucket_count How many buckets for match hash table
 * @param flow_id_bucket_count How many buckets for flow_id hash table
 */

typedef struct ft_config_s {
    int max_entries;
    int prio_bucket_count;
    int match_bucket_count;
    int flow_id_bucket_count;
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
 * effects_modify and clear_counters.
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
    list_head_t *flow_id_buckets;  /* Array of flow_id based buckets */
};

#define FT_CONFIG(_ft) (&(_ft)->config)
#define FT_STATUS(_ft) (&(_ft)->status)

/* These defines come from the original table driven version */
/* Redefine FT macros to use hash table or generic calls */
#define FT_ADD(_ft, _id, _flow_add, _entry_p)                           \
    ft_add(_ft, _id, _flow_add, _entry_p)
#define FT_DELETE_ID(_ft, _id)                                          \
    ft_delete_id(_ft, _id)
#define FT_MARK_ENTRIES(_ft, _q, _state, _reason)                       \
    (FT_DRIVER(_ft)->mark_entries((_ft), (_q), (_state), (_reason)))
#define FT_ENTRY_FREE(_ft, _entry)                                      \
    ft_delete(_ft, _entry)
#define FT_QUERY(_ft, _q)                                               \
    ft_query(_ft, _q)
#define FT_FIRST_MATCH(_ft, _q, _entry_p)                               \
    ft_first_match(_ft, _q, _entry_p)
#define FT_MODIFY_EFFECTS(_ft, _entry, _flow_mod)                       \
    ft_entry_modify_effects(_ft, _entry, _flow_mod)
#define FT_CLEAR_COUNTERS(_ft, _entry, _pkts, _bytes)                   \
    ft_entry_clear_counters(_ft, _entry, _pkts, _bytes)

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

/**
 * Iterate across flows of a given flow ID
 *
 * @param _ft The instance of the flow table being iterated
 * @param flow_id The flow ID to match
 * @param _idx Index of the match bucket hash list
 * @param _entry Pointer to the "current" entry in the iteration
 * @param _cur list_link_t bookkeeping pointer, do not reference
 * @param _next list_link_t bookkeeping pointer, do not refernece
 *
 * You need to compute the bucket index (using the hash function on
 * the flow_id object) before calling this macro.  Suggest you use an
 * auto variable to hold the result as the result is instantiated
 * multiple times.
 *
 * Assumes the ft_instance is initialized
 *
 * This is included for completeness and convenience.  In general,
 * there should be at most one match in the table.  Note that entry
 * SHOULD NOT BE REFERENCED OUTSIDE THE LOOP.
 */

#define FT_FLOW_ID_ITER(_ft, _id, _idx, _entry, _cur, _next)            \
    if (!list_empty(&(_ft)->flow_id_buckets[_idx]))                     \
        for ((_cur) = (_ft)->flow_id_buckets[_idx].links.next,          \
                 _entry = FT_ENTRY_CONTAINER(_cur, flow_id);                \
             _next = (_cur)->next,                                      \
                 _cur != &((_ft)->flow_id_buckets[_idx].links);         \
             _cur = _next, _entry = FT_ENTRY_CONTAINER(_cur, flow_id))  \
            if (_id == (_entry)->id)

/*
 * Create a flow table instance
 *
 * @param config Pointer to configuration structure
 * @returns A handle for the flow table instance
 *
 * If config->max_entries <= 0, use the default size
 */

ft_instance_t ft_create(ft_config_t *config);

/**
 * Delete a flow table instance and free resources
 * @param ft A handle for the flow table instance to be deleted
 *
 * Will call ft_entry_clear on all entries.
 *
 * Free underlying data structures
 */

void ft_destroy(ft_instance_t ft);

/**
 * Add a flow entry to the table
 * @param ft The flow table handle
 * @param id The external flow identifier
 * @param flow_add The LOCI flow mod object resulting in the add
 * @param entry_p Output; pointer to place to store entry if successful
 *
 * If the entry already exists, an error is returned.
 */

indigo_error_t ft_add(ft_instance_t ft,
                      indigo_flow_id_t id,
                      of_flow_add_t *flow_add,
                      ft_entry_t **entry_p);

/**
 * Remove a specific flow entry from the table
 * @param ft The flow table handle
 * @param entry Pointer to the entry to be removed
 */

indigo_error_t ft_delete(ft_instance_t ft,
                         ft_entry_t *entry);

/**
 * Remove a flow entry from the table indicated by flow ID
 * @param ft The flow table handle
 * @param id Flow ID of the entry to remove
 *
 * Just looks up the entry and calls ft_delete.
 */

indigo_error_t ft_delete_id(ft_instance_t ft,
                            indigo_flow_id_t id);

/**
 * Query the flow table and return the first match if found
 * @param ft Handle for a flow table instance
 * @param query The meta-match data for the query
 * @param entry_ptr (out) Pointer to where to store the result if found
 * @returns INDIGO_ERROR_NONE if found; otherwise INDIGO_ERROR_NOT_FOUND
 *
 * entry_ptr may be NULL; Normally this is called with priority checked.
 */

indigo_error_t ft_first_match(ft_instance_t instance,
                              of_meta_match_t *query,
                              ft_entry_t **entry_ptr);

/**
 * Query the flow table and return all matches
 * @param ft Handle for a flow table instance
 * @param query The meta-match data for the query
 * @returns A list with pointers to ft_entry_t
 *
 * @fixme Currently we don't/can't check for failed alloc in biglist.
 */

biglist_t *ft_query(ft_instance_t instance,
                    of_meta_match_t *query);

/**
 * Look up a flow by ID
 *
 * @param ft The flow table instance
 * @param id The flow ID being checked
 */

ft_entry_t *
ft_lookup(ft_instance_t ft, indigo_flow_id_t id);

/**
 * Modify the effects of a flow entry in the table
 * @param ft The flow table handle
 * @param entry Pointer to the entry to update
 * @param flow_mod The LOCI flow mod object resulting in the modification
 *
 * The actions (instructions) and related metadata are updated for the flow
 */

indigo_error_t
ft_entry_modify_effects(ft_instance_t instance,
                        ft_entry_t *entry,
                        of_flow_modify_t *flow_mod);

/**
 * Clear the counters associated with a specific entry in the table
 * @param entry The entry to update
 * @param packets (out) If non-NULL, store current packet count here
 * @param bytes (out) If non-NULL, store current byte count here
 *
 * The output parameters may be NULL in which case they are ignored.
 */

indigo_error_t
ft_entry_clear_counters(ft_entry_t *entry, uint64_t *packets, uint64_t *bytes);

/**
 * Start the delete process for an entry.
 * @param ft The flow table instance
 * @param entry Pointer to the entry
 * @param reason Reason the flow is being removed
 *
 * The delete operation is either started (MARKED) or indicated
 * as waiting due to an outstanding operation.
 *
 * The pending delete count is incremented.
 */

void
ft_entry_mark_deleted(ft_instance_t ft, ft_entry_t *entry,
                      indigo_fi_flow_removed_t reason);

/**
 * Map a priority to a hash bucket
 */

int
ft_prio_to_bucket_index(ft_instance_t ft, uint16_t priority);

/**
 * Map a match structure to a hash bucket
 */

int
ft_match_to_bucket_index(ft_instance_t ft, of_match_t *match);

/**
 * Map a flow id to a hash bucket
 */

int
ft_flow_id_to_bucket_index(ft_instance_t ft, indigo_flow_id_t *flow_id);

/*
 * Spawn a task that iterates over the flowtable
 *
 * @param ft Handle for a flow table instance
 * @param query The meta-match data for the query (or NULL)
 * @param callback Function called for each flowtable entry
 * @returns An error code
 *
 * This function does not guarantee a consistent view of the
 * flowtable over the course of the task.
 *
 * This function does not use any indexes on the flowtable.
 *
 * The callback function will be called with a NULL entry argument at
 * the end of the iteration.
 *
 * Deleted entries are skipped.
 */

typedef void (*ft_iter_task_callback_f)(void *cookie, ft_entry_t *entry);

indigo_error_t
ft_spawn_iter_task(ft_instance_t instance,
                   of_meta_match_t *query,
                   ft_iter_task_callback_f callback,
                   void *cookie,
                   int priority);

#endif /* _OFSTATEMANAGER_FT_H_ */
