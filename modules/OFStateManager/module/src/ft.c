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
 * @brief Implementation of flow table routines
 */

#include <OFStateManager/ofstatemanager_config.h>
#include <indigo/indigo.h>
#include <murmur/murmur.h>

#include "ofstatemanager_log.h"
#include "ft.h"
#include "expiration.h"

static indigo_error_t ft_entry_create(indigo_flow_id_t id, of_flow_add_t *flow_add, minimatch_t *minimatch, ft_entry_t **entry_p);
static void ft_entry_destroy(ft_instance_t ft, ft_entry_t *entry);
static indigo_error_t ft_entry_set_effects(ft_entry_t *entry, of_flow_modify_t *flow_mod);
static void ft_entry_link(ft_instance_t ft, ft_entry_t *entry);
static void ft_entry_unlink(ft_instance_t ft, ft_entry_t *entry);
static int ft_entry_has_out_port(ft_entry_t *entry, of_port_no_t port);
static void ft_checksum_add(ft_instance_t ft, ft_entry_t *entry);
static void ft_checksum_subtract(ft_instance_t ft, ft_entry_t *entry);

#define FT_HASH_SEED 0
#define FT_MAX_CHECKSUM_BUCKETS 65536

static int
ft_strict_match_hash(ft_instance_t ft,
                     minimatch_t *minimatch,
                     uint16_t priority)
{
    uint32_t h = FT_HASH_SEED;
    h = minimatch_hash(minimatch, h);
    h = murmur_hash(&priority, sizeof(priority), h);
    return h;
}

static int
ft_flow_id_hash(ft_instance_t ft, indigo_flow_id_t flow_id)
{
    return murmur_hash(&flow_id, sizeof(flow_id), FT_HASH_SEED);
}

static int
ft_cookie_to_bucket_index(ft_instance_t ft, uint64_t cookie)
{
    return cookie >> (64-FT_COOKIE_PREFIX_LEN);
}

ft_instance_t
ft_create(void)
{
    ft_instance_t ft;
    int bytes;
    int idx;

    /* Allocate the flow table itself */
    ft = aim_zmalloc(sizeof(*ft));

    list_init(&ft->all_list);

    /* Allocate and init buckets for each search type */
    ft->strict_match_hashtable = bighash_table_create(BIGHASH_AUTOGROW);
    ft->flow_id_hashtable = bighash_table_create(BIGHASH_AUTOGROW);

    bytes = sizeof(list_head_t) * (1 << FT_COOKIE_PREFIX_LEN);
    ft->cookie_buckets = aim_zmalloc(bytes);
    for (idx = 0; idx < (1 << FT_COOKIE_PREFIX_LEN); idx++) {
        list_init(&ft->cookie_buckets[idx]);
    }

    for (idx = 0; idx < FT_MAX_TABLES; idx++) {
        ft_table_t *table = &ft->tables[idx];
        table->checksum_buckets_size = 128;
        table->checksum_shift = 64 - aim_log2_u32(table->checksum_buckets_size);
        table->checksum_buckets = aim_zmalloc(table->checksum_buckets_size * sizeof(uint64_t));
    }

    return ft;
}

void
ft_destroy(ft_instance_t ft)
{
    ft_entry_t *entry;
    list_links_t *cur, *next;
    int i;

    if (ft == NULL) {
        return;
    }

    FT_ITER(ft, entry, cur, next) {
        ft_entry_unlink(ft, entry);
        ft_entry_destroy(ft, entry);
    }

    if (ft->strict_match_hashtable != NULL) {
        bighash_table_destroy(ft->strict_match_hashtable, NULL);
        ft->strict_match_hashtable = NULL;
    }
    if (ft->flow_id_hashtable != NULL) {
        bighash_table_destroy(ft->flow_id_hashtable, NULL);
        ft->flow_id_hashtable = NULL;
    }
    if (ft->cookie_buckets != NULL) {
        aim_free(ft->cookie_buckets);
        ft->cookie_buckets = NULL;
    }

    for (i = 0; i < FT_MAX_TABLES; i++) {
        aim_free(ft->tables[i].checksum_buckets);
    }

    aim_free(ft);
}

indigo_error_t
ft_add(ft_instance_t ft, indigo_flow_id_t id,
       of_flow_add_t *flow_add, minimatch_t *minimatch,
       ft_entry_t **entry_p)
{
    ft_entry_t *entry = NULL;
    indigo_error_t rv;

    LOG_TRACE("Adding flow " INDIGO_FLOW_ID_PRINTF_FORMAT, id);

    /* If flow ID already exists, error. */
    if (ft_lookup(ft, id) != NULL) {
        minimatch_cleanup(minimatch);
        return INDIGO_ERROR_EXISTS;
    }

    if ((rv = ft_entry_create(id, flow_add, minimatch, &entry)) < 0) {
        return rv;
    }

    ft_entry_link(ft, entry);
    ft->current_count++;
    debug_counter_inc(&ft_add_counter);
    debug_counter_inc(&ft_flow_counter);

    ft_checksum_add(ft, entry);

    if (entry_p != NULL) {
        *entry_p = entry;
    }

    return INDIGO_ERROR_NONE;
}

void
ft_delete(ft_instance_t ft, ft_entry_t *entry)
{
    LOG_TRACE("Delete flow " INDIGO_FLOW_ID_PRINTF_FORMAT, entry->id);

    ft_checksum_subtract(ft, entry);
    ft_entry_unlink(ft, entry);
    ft_entry_destroy(ft, entry);

    ft->current_count--;
    debug_counter_add(&ft_flow_counter, -1);
    debug_counter_inc(&ft_delete_counter);
}

void
ft_overwrite(ft_instance_t ft, ft_entry_t *entry, of_flow_add_t *flow_add)
{
    ft_checksum_subtract(ft, entry);
    ft_entry_unlink(ft, entry);

    of_flow_add_cookie_get(flow_add, &entry->cookie);
    of_flow_add_flags_get(flow_add, &entry->flags);
    of_flow_add_idle_timeout_get(flow_add, &entry->idle_timeout);
    of_flow_add_hard_timeout_get(flow_add, &entry->hard_timeout);

    indigo_error_t err = ft_entry_set_effects(entry, flow_add);
    AIM_ASSERT(err == INDIGO_ERROR_NONE);

    entry->insert_time = INDIGO_CURRENT_TIME;
    entry->last_counter_change = entry->insert_time;

    ft_entry_link(ft, entry);
    ft_checksum_add(ft, entry);
}

indigo_error_t
ft_strict_match(ft_instance_t instance,
               of_meta_match_t *query,
               ft_entry_t **entry_ptr)
{
    uint32_t hash;
    bighash_entry_t *hash_entry;

    INDIGO_ASSERT(query->mode == OF_MATCH_STRICT);

    hash = ft_strict_match_hash(instance, &query->minimatch, query->priority);

    for (hash_entry = bighash_first(instance->strict_match_hashtable, hash);
         hash_entry != NULL; hash_entry = bighash_next(hash_entry)) {
        ft_entry_t *entry = container_of(hash_entry, strict_match_hash_entry, ft_entry_t);
        if (ft_entry_meta_match(query, entry)) {
            *entry_ptr = entry;
            return INDIGO_ERROR_NONE;
        }
    }

    return INDIGO_ERROR_NOT_FOUND;
}

ft_entry_t *
ft_lookup(ft_instance_t ft, indigo_flow_id_t id)
{
    uint32_t hash;
    bighash_entry_t *hash_entry;

    hash = ft_flow_id_hash(ft, id);

    for (hash_entry = bighash_first(ft->flow_id_hashtable, hash);
         hash_entry != NULL; hash_entry = bighash_next(hash_entry)) {
        ft_entry_t *entry = container_of(hash_entry, flow_id_hash_entry, ft_entry_t);
        if (entry->id == id) {
            return entry;
        }
    }

    return NULL;
}

indigo_error_t
ft_set_checksum_buckets_size(ft_instance_t ft, uint8_t table_id, uint32_t buckets_size)
{
    if (table_id >= FT_MAX_TABLES) {
        return INDIGO_ERROR_NOT_FOUND;
    }

    if (buckets_size > FT_MAX_CHECKSUM_BUCKETS) {
        return INDIGO_ERROR_PARAM;
    }

    if (!aim_is_pow2_u32(buckets_size)) {
        return INDIGO_ERROR_PARAM;
    }

    ft_table_t *table = &ft->tables[table_id];

    if (table->checksum_buckets_size == buckets_size) {
        return INDIGO_ERROR_NONE;
    }

    aim_free(table->checksum_buckets);
    table->checksum = 0;
    table->checksum_buckets_size = buckets_size;
    table->checksum_shift = 64 - aim_log2_u32(buckets_size);
    table->checksum_buckets = aim_zmalloc(sizeof(uint64_t) * buckets_size);

    list_links_t *cur;
    LIST_FOREACH(&ft->all_list, cur) {
        ft_entry_t *entry = FT_ENTRY_CONTAINER(cur, table);
        ft_checksum_add(ft, entry);
    }

    return INDIGO_ERROR_NONE;
}

int
ft_entry_meta_match(of_meta_match_t *query, ft_entry_t *entry)
{
    uint64_t mask;
    int rv = 0; /* Default is no match */

    if ((mask = query->cookie_mask)) {
        if ((query->cookie & mask) != (entry->cookie & mask)) {
            return rv;
        }
    }

    if (query->table_id != TABLE_ID_ANY) {
        if (query->table_id != entry->table_id) {
            return rv;
        }
    }

    if (query->check_priority) {
        if (entry->priority != query->priority) {
            return rv;
        }
    }

    switch (query->mode) {
    case OF_MATCH_NON_STRICT:
        /* Check if the entry's match is more specific than the query's */
        if (!minimatch_more_specific(&entry->minimatch, &query->minimatch)) {
            break;
        }
        if (query->out_port != OF_PORT_DEST_WILDCARD) {
            if (!ft_entry_has_out_port(entry, query->out_port)) {
                break;
            }
        }
        rv = 1;
        break;
    case OF_MATCH_STRICT:
        if (!minimatch_equal(&entry->minimatch, &query->minimatch)) {
            break;
        }
        if (query->out_port != OF_PORT_DEST_WILDCARD) {
            if (!ft_entry_has_out_port(entry, query->out_port)) {
                break;
            }
        }
        rv = 1;
        break;
    case OF_MATCH_COOKIE_ONLY:
        /* Checked cookie above */
        rv = 1;
        break;
    case OF_MATCH_OVERLAP:
        if (!minimatch_overlap(&entry->minimatch, &query->minimatch)) {
            break;
        }
        rv = 1;
        break;
    default:
        /* Internal error */
        AIM_LOG_ERROR("Internal error: unknown query mode %d", query->mode);
        break;
    }

    return rv;
}

indigo_error_t
ft_entry_modify_effects(ft_instance_t instance,
                        ft_entry_t *entry,
                        of_flow_modify_t *flow_mod)
{
    indigo_error_t err;

    LOG_TRACE("Modifying effects of entry " INDIGO_FLOW_ID_PRINTF_FORMAT,
              entry->id);

    err = ft_entry_set_effects(entry, flow_mod);
    if (err == INDIGO_ERROR_NONE) {
        debug_counter_inc(&ft_modify_counter);
    }

    return err;
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
    ft_iterator_t iter;
};

static ind_soc_task_status_t
ft_iter_task_callback(void *cookie)
{
    struct ft_iter_task_state *state = cookie;

    do {
        ft_entry_t *entry = ft_iterator_next(&state->iter);
        if (entry == NULL) {
            /* Finished */
            state->callback(state->cookie, NULL);
            ft_iterator_cleanup(&state->iter);
            aim_free(state);
            return IND_SOC_TASK_FINISHED;
        } else {
            state->callback(state->cookie, entry);
        }
    } while (!ind_soc_should_yield());

    return IND_SOC_TASK_CONTINUE;
}

indigo_error_t
ft_spawn_iter_task(ft_instance_t instance,
                   of_meta_match_t *query,
                   ft_iter_task_callback_f callback,
                   void *cookie,
                   int priority)
{
    indigo_error_t rv;

    struct ft_iter_task_state *state = aim_malloc(sizeof(*state));

    state->callback = callback;
    state->cookie = cookie;

    ft_iterator_init(&state->iter, instance, query);

    rv = ind_soc_task_register(ft_iter_task_callback, state, priority);
    if (rv != INDIGO_ERROR_NONE) {
        ft_iterator_cleanup(&state->iter);
        aim_free(state);
        return rv;
    }

    return INDIGO_ERROR_NONE;
}

static ft_entry_t *
ft_iterator_links_to_entry(ft_iterator_t *iter, list_links_t *links)
{
    return (ft_entry_t *)(((char *)links) - iter->links_offset);
}

static list_links_t *
ft_iterator_entry_to_links(ft_iterator_t *iter, ft_entry_t *entry)
{
    return (list_links_t *)(((char *)entry) + iter->links_offset);
}

void
ft_iterator_init(ft_iterator_t *iter, ft_instance_t ft, of_meta_match_t *query)
{
    if (query != NULL) {
        iter->query = *query;
        iter->use_query = true;
    } else {
        iter->use_query = false;
    }

    if (query && (query->cookie_mask & FT_COOKIE_PREFIX_MASK) == FT_COOKIE_PREFIX_MASK) {
        /* Using cookie bucket */
        iter->head = &ft->cookie_buckets[ft_cookie_to_bucket_index(ft, query->cookie)];
        iter->links_offset = offsetof(ft_entry_t, cookie_links);
    } else {
        iter->head = &ft->all_list;
        iter->links_offset = offsetof(ft_entry_t, table_links);
    }

    if (list_empty(iter->head)) {
        iter->next_entry = NULL;
    } else {
        iter->next_entry = ft_iterator_links_to_entry(iter, iter->head->links.next);
        list_push(&iter->next_entry->iterators, &iter->entry_links);
    }
}

ft_entry_t *
ft_iterator_next(ft_iterator_t *iter)
{
    if (iter->next_entry != NULL) {
        list_remove(&iter->entry_links);
    }

    while (iter->next_entry != NULL) {
        ft_entry_t *entry = iter->next_entry;

        list_links_t *next_links = ft_iterator_entry_to_links(iter, iter->next_entry)->next;
        if (next_links == &iter->head->links) {
            /* Finished iteration */
            iter->next_entry = NULL;
        } else {
            iter->next_entry = ft_iterator_links_to_entry(iter, next_links);
        }

        if (iter->use_query && !ft_entry_meta_match(&iter->query, entry)) {
            continue;
        }

        if (iter->next_entry != NULL) {
            list_push(&iter->next_entry->iterators, &iter->entry_links);
        }

        return entry;
    }

    return NULL;
}

void
ft_iterator_cleanup(ft_iterator_t *iter)
{
    if (iter->next_entry != NULL) {
        list_remove(&iter->entry_links);
        iter->next_entry = NULL;
    }

    if (iter->use_query) {
        metamatch_cleanup(&iter->query);
    }
}

/**
 * Link an entry into the appropriate lists for the FT
 */

static void
ft_entry_link(ft_instance_t ft, ft_entry_t *entry)
{
    int idx;

    if (ft == NULL || entry == NULL) {
        INDIGO_ASSERT(!"ft_entry_link called with NULL ft or entry");
        return;
    }

    /* Link to full table iteration */
    list_push(&ft->all_list, &entry->table_links);

    /* Strict match hash */
    bighash_insert(
        ft->strict_match_hashtable,
        &entry->strict_match_hash_entry,
        ft_strict_match_hash(ft, &entry->minimatch, entry->priority));

    /* Flow ID hash */
    bighash_insert(
        ft->flow_id_hashtable,
        &entry->flow_id_hash_entry,
        ft_flow_id_hash(ft, entry->id));

    if (ft->cookie_buckets) { /* Cookie prefix */
        idx = ft_cookie_to_bucket_index(ft, entry->cookie);
        list_push(&ft->cookie_buckets[idx], &entry->cookie_links);
    }

    list_init(&entry->iterators);

    if (entry->idle_timeout || entry->hard_timeout) {
        ind_core_expiration_add(entry);
    }
}

/**
 * Unlink an entry from the appropriate lists for the FT
 */

static void
ft_entry_unlink(ft_instance_t ft, ft_entry_t *entry)
{
    if (ft == NULL || entry == NULL) {
        INDIGO_ASSERT(!"ft_entry_unlink called with NULL ft or entry");
        return;
    }

    INDIGO_ASSERT(!list_empty(&ft->all_list));

    /* Advance iterators pointing to this entry */
    list_links_t *cur, *next;
    LIST_FOREACH_SAFE(&entry->iterators, cur, next) {
        ft_iterator_next(container_of(cur, entry_links, ft_iterator_t));
    }

    /* Remove from full table iteration */
    list_remove(&entry->table_links);

    /* Strict match hash */
    bighash_remove(ft->strict_match_hashtable, &entry->strict_match_hash_entry);

    /* Flow ID hash */
    bighash_remove(ft->flow_id_hashtable, &entry->flow_id_hash_entry);

    if (ft->cookie_buckets) { /* Cookie prefix */
        INDIGO_ASSERT(!list_empty(&ft->cookie_buckets[ft_cookie_to_bucket_index(ft,
            entry->cookie)]));
        list_remove(&entry->cookie_links);
    }

    if (entry->idle_timeout || entry->hard_timeout) {
        ind_core_expiration_remove(entry);
    }
}

/**
 * Allocate and initialize a new flowtable entry
 *
 * @param id The flow ID to use
 * @param flow_add Pointer to the flow add object for the entry
 * @param minimatch Pointer to the minimatch already extracted from the flow
 * @param_p entry Populated with pointer to new flowtable entry on success
 *
 * The list links are not modified by this call.
 *
 * The minimatch is moved.
 */
static indigo_error_t
ft_entry_create(indigo_flow_id_t id, of_flow_add_t *flow_add,
                minimatch_t *minimatch, ft_entry_t **entry_p)
{
    indigo_error_t err;
    ft_entry_t *entry;

    entry = aim_zmalloc(sizeof(*entry));

    entry->id = id;

    minimatch_move(&entry->minimatch, minimatch);

    of_flow_add_cookie_get(flow_add, &entry->cookie);
    of_flow_add_priority_get(flow_add, &entry->priority);
    of_flow_add_flags_get(flow_add, &entry->flags);
    of_flow_add_idle_timeout_get(flow_add, &entry->idle_timeout);
    of_flow_add_hard_timeout_get(flow_add, &entry->hard_timeout);

    err = ft_entry_set_effects(entry, flow_add);
    if (err < 0) {
        aim_free(entry);
        minimatch_cleanup(&entry->minimatch);
        return err;
    }

    entry->insert_time = INDIGO_CURRENT_TIME;
    entry->last_counter_change = entry->insert_time;

    if (flow_add->version >= OF_VERSION_1_1) {
        of_flow_add_table_id_get(flow_add, &entry->table_id);
    } else {
        entry->table_id = 0;
    }

    *entry_p = entry;

    return INDIGO_ERROR_NONE;
}

/**
 * Release the data associated with an entry
 *
 * @param entry Pointer to entry being initialized
 *
 * The list links are not modified by this call.
 */
static void
ft_entry_destroy(ft_instance_t ft, ft_entry_t *entry)
{
    if (entry->effects.actions != NULL) {
        of_list_action_delete(entry->effects.actions);
        entry->effects.actions = NULL;
    }

    minimatch_cleanup(&entry->minimatch);
    aim_free(entry);
}

/* Populate the output port list and effects */
static indigo_error_t
ft_entry_set_effects(ft_entry_t *entry,
                    of_flow_modify_t *flow_mod)
{
    if (flow_mod->version == OF_VERSION_1_0)
    {
        of_list_action_t *actions;
        if ((actions = of_flow_modify_actions_get(flow_mod)) == NULL) {
            LOG_ERROR("Could not get action list");
            return INDIGO_ERROR_RESOURCE;
        }
        of_list_action_delete(entry->effects.actions);
        entry->effects.actions = actions;
    } else {
        of_list_instruction_t *instructions;
        if ((instructions = of_flow_modify_instructions_get(flow_mod)) == NULL) {
            LOG_ERROR("Could not get instruction list");
            return INDIGO_ERROR_RESOURCE;
        }
        of_list_instruction_delete(entry->effects.instructions);
        entry->effects.instructions = instructions;
    }

    return INDIGO_ERROR_NONE;
}

static int
action_list_has_out_port(of_list_action_t *actions, of_port_no_t port)
{
    of_action_t act;
    int loop_rv;
    of_port_no_t out_port;

    OF_LIST_ACTION_ITER(actions, &act, loop_rv) {
        if (act.header.object_id == OF_ACTION_OUTPUT) {
            of_action_output_port_get(&act.output, &out_port);
            if (out_port == port) {
                return 1;
            }
        }
    }

    return 0;
}

static int
instruction_list_has_out_port(of_list_instruction_t *instructions, of_port_no_t port)
{
    of_instruction_t inst;
    int loop_rv;

    OF_LIST_INSTRUCTION_ITER(instructions, &inst, loop_rv) {
        if (inst.header.object_id == OF_INSTRUCTION_APPLY_ACTIONS) {
            of_list_action_t actions;
            of_instruction_apply_actions_actions_bind(&inst.apply_actions, &actions);
            if (action_list_has_out_port(&actions, port)) {
                return 1;
            }
        } else if (inst.header.object_id == OF_INSTRUCTION_WRITE_ACTIONS) {
            of_list_action_t actions;
            of_instruction_write_actions_actions_bind(&inst.write_actions, &actions);
            if (action_list_has_out_port(&actions, port)) {
                return 1;
            }
        }
    }

    return 0;
}

/**
 * Determine if the given entry has port as an output port
 */
static int
ft_entry_has_out_port(ft_entry_t *entry, of_port_no_t port)
{
    if (entry->effects.actions->version == OF_VERSION_1_0) {
        return action_list_has_out_port(entry->effects.actions, port);
    } else {
        return instruction_list_has_out_port(entry->effects.instructions, port);
    }

    return 0;
}

static void
ft_checksum_add(ft_instance_t ft, ft_entry_t *entry)
{
    if (entry->table_id >= FT_MAX_TABLES) {
        return;
    }

    ft_table_t *table = &ft->tables[entry->table_id];
    table->checksum += entry->cookie;
    int bucket = table->checksum_shift < 64 ? entry->cookie >> table->checksum_shift : 0;
    table->checksum_buckets[bucket] += entry->cookie;
}

static void
ft_checksum_subtract(ft_instance_t ft, ft_entry_t *entry)
{
    if (entry->table_id >= FT_MAX_TABLES) {
        return;
    }

    ft_table_t *table = &ft->tables[entry->table_id];
    table->checksum -= entry->cookie;
    int bucket = table->checksum_shift < 64 ? entry->cookie >> table->checksum_shift : 0;
    table->checksum_buckets[bucket] -= entry->cookie;
}

void
metamatch_cleanup(of_meta_match_t *metamatch)
{
    minimatch_cleanup(&metamatch->minimatch);
}
