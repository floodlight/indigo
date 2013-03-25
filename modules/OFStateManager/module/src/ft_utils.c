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
        bucket_idx = prio_to_bucket_index(instance, query->priority);
        FT_PRIO_ITER(instance, query->priority, bucket_idx, entry, cur, next) {
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
        bucket_idx = prio_to_bucket_index(instance, query->priority);
        FT_PRIO_ITER(instance, query->priority, bucket_idx, entry, cur, next) {
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
