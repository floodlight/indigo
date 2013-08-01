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
 * Implementations of some generic flow table routines
 */

#include "ofstatemanager_log.h"

#include "ft_utils.h"

/**
 * Query the flow table and return the first match if found
 * @param ft Handle for a flow table instance
 * @param query The meta-match data for the query
 * @param entry_ptr (out) Pointer to where to store the result if found
 * @returns INDIGO_ERROR_NONE if found; otherwise INDIGO_ERROR_NOT_FOUND
 *
 * entry_ptr may be NULL; Normally this is called with priority checked.
 */

indigo_error_t
ft_flow_first_match(ft_instance_t instance,
                    of_meta_match_t *query,
                    ft_entry_t **entry_ptr)
{
    int bucket_idx;
    ft_entry_t *entry;
    list_links_t *cur, *next;

    if (query->mode == OF_MATCH_STRICT) {
        bucket_idx = match_to_bucket_index(instance, &(query->match));
        FT_MATCH_ITER(instance, &(query->match), bucket_idx, entry,
                      cur, next) {
            if (!FT_FLOW_STATE_IS_DELETED(entry->state) &&
                    ft_flow_meta_match(query, entry)) {
                if (entry_ptr) {
                    *entry_ptr = entry;
                }
                return INDIGO_ERROR_NONE;
            }
        }
    } else if (query->check_priority) { /* Iterate thru prio hash list */
        uint32_t state = 0;
        while ((entry = hindex_lookup(instance->priority_index,
                                    &query->priority, &state)) != NULL) {
            if (!FT_FLOW_STATE_IS_DELETED(entry->state) &&
                    ft_flow_meta_match(query, entry)) {
                if (entry_ptr) {
                    *entry_ptr = entry;
                }
                return INDIGO_ERROR_NONE;
            }
        }
    } else { /* Iterate thru whole list */
        FT_ITER(instance, entry, cur, next) {
            if (!FT_FLOW_STATE_IS_DELETED(entry->state) &&
                    ft_flow_meta_match(query, entry)) {
                if (entry_ptr) {
                    *entry_ptr = entry;
                }
                return INDIGO_ERROR_NONE;
            }
        }
    }

    return INDIGO_ERROR_NOT_FOUND;
}

/**
 * Query the flow table and return all matches
 * @param ft Handle for a flow table instance
 * @param query The meta-match data for the query
 * @returns A list with pointers to ft_entry_t
 *
 * @fixme Currently we don't/can't check for failed alloc in biglist.
 */

biglist_t *
ft_flow_query(ft_instance_t instance, of_meta_match_t *query)
{
    int bucket_idx;
    ft_entry_t *entry;
    list_links_t *cur, *next;
    biglist_t *list = NULL;
    int count = 0;

    if (query->mode == OF_MATCH_STRICT) {
        bucket_idx = match_to_bucket_index(instance, &(query->match));
        FT_MATCH_ITER(instance, &(query->match), bucket_idx, entry,
                      cur, next) {
            if (!FT_FLOW_STATE_IS_DELETED(entry->state) &&
                    ft_flow_meta_match(query, entry)) {
                list = biglist_prepend(list, (void *)entry);
                count += 1;
            }
        }
    } else if (query->check_priority) {
        /* Iterate thru prio hash list */
        uint32_t state = 0;
        while ((entry = hindex_lookup(instance->priority_index,
                                    &query->priority, &state)) != NULL) {
            if (!FT_FLOW_STATE_IS_DELETED(entry->state) &&
                    ft_flow_meta_match(query, entry)) {
                list = biglist_prepend(list, (void *)entry);
                count += 1;
            }
        }
    } else { /* Iterate thru whole list */
        FT_ITER(instance, entry, cur, next) {
            if (!FT_FLOW_STATE_IS_DELETED(entry->state) &&
                    ft_flow_meta_match(query, entry)) {
                list = biglist_prepend(list, (void *)entry);
                count += 1;
            }
        }
    }

    LOG_TRACE("Query generated %d entries", count);
    return list;
}


/*
 * Flowtable iterator task
 *
 * Several operations follow a pattern of iterating over the entire flowtable
 * to make calls to Forwarding. Since the flowtable can be very large we need
 * to break up the work to allow processing higher priority events in between.
 *
 * These functions wrap the SocketManager task API to provide a simple method
 * for iterating over the flowtable without delaying higher priority events.
 */

struct ft_iter_task_state {
    ft_iter_task_callback_f callback;
    void *cookie;
    ft_instance_t flowtable;
    of_meta_match_t query;
    int use_query;
    int idx;
};

static ind_soc_task_status_t
ft_iter_task_callback(void *cookie)
{
    struct ft_iter_task_state *state = cookie;

    do {
        if (state->idx == state->flowtable->config.max_entries) {
            /* Finished */
            state->callback(state->cookie, NULL);
            INDIGO_MEM_FREE(state);
            return IND_SOC_TASK_FINISHED;
        } else {
            ft_entry_t *entry = &state->flowtable->flow_entries[state->idx++];

            if (entry->state == FT_FLOW_STATE_FREE ||
                FT_FLOW_STATE_IS_DELETED(entry->state)) {
                continue;
            }

            if (state->use_query && !ft_flow_meta_match(&state->query, entry)) {
                continue;
            }

            state->callback(state->cookie, entry);
        }
    } while (!ind_soc_should_yield());

    return IND_SOC_TASK_CONTINUE;
}

/**
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

indigo_error_t
ft_spawn_iter_task(ft_instance_t instance,
                   of_meta_match_t *query,
                   ft_iter_task_callback_f callback,
                   void *cookie,
                   int priority)
{
    indigo_error_t rv;

    struct ft_iter_task_state *state = INDIGO_MEM_ALLOC(sizeof(*state));
    if (state == NULL) {
        return INDIGO_ERROR_RESOURCE;
    }

    state->callback = callback;
    state->cookie = cookie;
    state->flowtable = instance;
    state->idx = 0;

    if (query != NULL) {
        state->query = *query;
        state->use_query = 1;
    } else {
        state->use_query = 0;
    }

    rv = ind_soc_task_register(ft_iter_task_callback, state, priority);
    if (rv != INDIGO_ERROR_NONE) {
        INDIGO_MEM_FREE(state);
        return rv;
    }

    return INDIGO_ERROR_NONE;
}
