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
 * Hash based flow table implementation
 *
 * The linear implementation originally provided with Indigo-2
 * suffered from two deficiencies:  It was linear and very slow;
 * It had too much code overhead for a very simple problem.
 *
 * This implementation replaces the driver structure with direct
 * calls (which means changes to ft.h).
 *
 * This driver uses a pre-allocates a fixed number of flow entries
 * at init time.  (An alternative implementation with dynamic reallocation
 * could be added in the future).
 */

#include "ofstatemanager_log.h"

#include "ft.h"
#include "ft_utils.h"
#include "ft_hash.h"

#define FT_HASH_MAGIC_NUMBER 0xf005ba11

/**
 * Create a flow table instance
 * @param config Pointer to configuration structure
 * @returns A handle for the flow table instance to be used
 * in all calls affecting this table instance
 *
 * If max_entries <= 0, use the default size
 *
 * The implementation of this function does not attempt to be abstract
 *
 */

ft_instance_t
ft_hash_create(ft_config_t *config)
{
    ft_instance_t ft;
    int bytes;
    int idx;

    if (config->max_entries <= 0) {
        LOG_ERROR("Hash flow table only supports fixed number of buckets");
        return NULL;
    }

    /* Allocate the flow table itself */
    ft = INDIGO_MEM_ALLOC(sizeof(*ft));
    if (ft == NULL) {
        LOG_ERROR("ERROR: Flow table (hash) creation failed");
        return NULL;
    }
    INDIGO_MEM_SET(ft, 0, sizeof(*ft));
    INDIGO_MEM_COPY(&ft->config,  config, sizeof(ft_config_t));
    ft->magic = FT_HASH_MAGIC_NUMBER;

    list_init(&ft->free_list);
    list_init(&ft->all_list);

    /* Allocate and init the flow entries */
    bytes = sizeof(ft_entry_t) * config->max_entries;
    ft->flow_entries = INDIGO_MEM_ALLOC(bytes);
    if (ft->flow_entries == NULL) {
        LOG_ERROR("ERROR: Flow table (hash) creation failed");
        INDIGO_MEM_FREE(ft);
        return NULL;
    }
    INDIGO_MEM_SET(ft->flow_entries, 0, bytes);

    /* Put the flow entries on the free list */
    for (idx = 0; idx < config->max_entries; idx++) {
        list_push(&ft->free_list, &ft->flow_entries[idx].table_links);
    }

    /* Allocate and init buckets for each search type */

    bytes = sizeof(list_head_t) * config->match_bucket_count;
    ft->match_buckets = INDIGO_MEM_ALLOC(bytes);
    if (ft->match_buckets == NULL) {
        LOG_ERROR("ERROR: Flow table, match bucket alloc failed");
        ft_hash_delete(ft);
        return NULL;
    }
    INDIGO_MEM_SET(ft->match_buckets, 0, bytes);
    for (idx = 0; idx < config->match_bucket_count; idx++) {
        list_init(&ft->match_buckets[idx]);
    }

    ft->flow_id_index = hindex_create(hindex_uint64_hash, hindex_uint64_equality,
                                  offsetof(struct ft_entry_s, id), 0);

    ft->priority_index = hindex_create(hindex_uint16_hash, hindex_uint16_equality,
                                   offsetof(struct ft_entry_s, priority), 0);

    return ft;
}

/**
 * Add a flow entry to the table
 * @param ft The flow table handle
 * @param id The external flow identifier
 * @param flow_add The LOCI flow mod object resulting in the add
 * @param entry_p Output; pointer to place to store entry if successful
 *
 * If the an entry already exists, an error is returned.
 */

indigo_error_t
ft_hash_flow_add(ft_instance_t ft, indigo_flow_id_t id,
                 of_flow_add_t *flow_add, ft_entry_t **entry_p)
{
    ft_entry_t *entry;
    list_links_t *links;
    indigo_error_t rv;

    INDIGO_ASSERT(ft->magic == FT_HASH_MAGIC_NUMBER);

    LOG_TRACE("Adding flow " INDIGO_FLOW_ID_PRINTF_FORMAT, id);

    /* If flow ID already exists, error. */
    if (ft_id_lookup(ft, id) != NULL) {
        return INDIGO_ERROR_EXISTS;
    }

    /* Grab an entry from the free list */
    if ((links = list_pop(&ft->free_list)) == NULL) {
        ++(ft->status.table_full_errors);
        return INDIGO_ERROR_RESOURCE;
    }
    entry = FT_ENTRY_CONTAINER(links, table);

    if ((rv = ft_entry_setup(entry, id, flow_add)) < 0) {
        return rv;
    }

    ft_entry_link(ft, entry);
    ft->status.adds += 1;
    ft->status.current_count += 1;

    if (entry_p != NULL) {
        *entry_p = entry;
    }

    return INDIGO_ERROR_NONE;
}

/**
 * Remove a specific flow entry from the table
 * @param ft The flow table handle
 * @param entry Pointer to the entry to be removed
 * @param make_callback Boolean indicating if a callback should be
 * made on the entry
 */

indigo_error_t
ft_hash_flow_delete(ft_instance_t ft, ft_entry_t *entry, int make_callback)
{
    INDIGO_ASSERT(ft->magic == FT_HASH_MAGIC_NUMBER);

    LOG_TRACE("Delete rsn %d flow " INDIGO_FLOW_ID_PRINTF_FORMAT,
              entry->removed_reason, entry->id);

    if (entry->id == INDIGO_FLOW_ID_INVALID) {
        LOG_ERROR("Deleting invalid flow table entry");
        return INDIGO_ERROR_UNKNOWN;
    }

    if (make_callback && ft->config.entry_deleted_cb) {
        ft->config.entry_deleted_cb(ft, entry, ft->config.deleted_cookie);
    }

    /* Unlink from hash lists; clear entry; put it on the free list */
    ft_entry_unlink(ft, entry);
    ft_entry_clear(ft, entry);

    INDIGO_ASSERT(entry->state == FT_FLOW_STATE_FREE);
    list_push(&ft->free_list, &entry->table_links);
    ft->status.current_count -= 1;
    ft->status.deletes += 1;

    return INDIGO_ERROR_NONE;
}

/**
 * Remove a flow entry from the table indicated by flow ID
 * @param ft The flow table handle
 * @param id Flow ID of the entry to remove
 * @param make_callback Boolean indicating if a callback should be
 * made on the entry
 *
 * Just looks up the entry and calls the above.
 */

indigo_error_t
ft_hash_flow_delete_id(ft_instance_t ft,
                       indigo_flow_id_t id,
                       int make_callback)
{
    ft_entry_t *entry;

    if ((entry = ft_id_lookup(ft, id)) == NULL) {
        LOG_VERBOSE("Delete: Failed to find flow "
                    INDIGO_FLOW_ID_PRINTF_FORMAT, id);
        return INDIGO_ERROR_NOT_FOUND;
    }
    return ft_hash_flow_delete(ft, entry, make_callback);
}

/**
 * Find the highest priority match in the flow table for a packet
 * @param ft Handle for a flow table instance
 * @param msg Pointer to a buffer containing the packet data
 * @param len The length of the packet in bytes
 * @returns A flow id; INDIGO_FLOW_ID_INVALID if no match is found
 *
 * This is really a convenience function for prototyping.  It is
 * assumed that this interface will generally not implement functions
 * optimized for packet matching.
 */

ft_entry_t *
ft_hash_match_packet(ft_instance_t ft, uint8_t *msg, int len)
{
    /* @fixme */
    return NULL;
}

/**
 * Delete a flow table instance and free resources
 * @param ft A handle for the flow table instance to be deleted
 *
 * Will call delete entry on each instance without making callback
 *
 * Free underlying data structures
 */

/* Macro for checking bucket lists are empty */
#if !defined(FT_NO_ERROR_CHECKING)
#define CHECK_BUCKETS(type) do {                                           \
        int idx, cnt;                                                      \
        for (idx = 0; idx < ft->config.type##_bucket_count; idx++) {       \
            if ((cnt = list_length(&ft->type##_buckets[idx])) != 0) {      \
                LOG_ERROR("ERROR: bucket list %s has len %d on delete",    \
                          #type, cnt);                                     \
                break;                                                     \
            }                                                              \
        }                                                                  \
    } while (0)
#else
#define CHECK_BUCKETS(type)
#endif

void
ft_hash_delete(ft_instance_t ft)
{
    ft_entry_t *entry;
    list_links_t *cur, *next;

    if (ft == NULL) {
        return;
    }
    INDIGO_ASSERT(ft->magic == FT_HASH_MAGIC_NUMBER);

    FT_ITER(ft, entry, cur, next) {
        ft_entry_unlink(ft, entry);
        ft_entry_clear(ft, entry);
    }

    if (ft->flow_entries != NULL) {
        INDIGO_MEM_FREE(ft->flow_entries);
        ft->flow_entries = NULL;
    }
    if (ft->match_buckets != NULL) {
        CHECK_BUCKETS(match);
        INDIGO_MEM_FREE(ft->match_buckets);
        ft->match_buckets = NULL;
    }

    if (ft->flow_id_index != NULL) {
        hindex_destroy(ft->flow_id_index);
    }

    if (ft->priority_index != NULL) {
        hindex_destroy(ft->priority_index);
    }

    ft->magic = 0;
    INDIGO_MEM_FREE(ft);
}
