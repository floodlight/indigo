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

static indigo_error_t ft_entry_create(indigo_flow_id_t id, of_flow_add_t *flow_add, ft_entry_t **entry_p);
static void ft_entry_destroy(ft_instance_t ft, ft_entry_t *entry);
static indigo_error_t ft_entry_set_effects(ft_entry_t *entry, of_flow_modify_t *flow_mod);
static void ft_entry_link(ft_instance_t ft, ft_entry_t *entry);
static void ft_entry_unlink(ft_instance_t ft, ft_entry_t *entry);
static int ft_entry_has_out_port(ft_entry_t *entry, of_port_no_t port);

#define FT_HASH_SEED 0

/**
 * @fixme Consider using something other than murmur for small data
 * hash calculations.  Multiplying by a prime is a good option
 */

static int
ft_strict_match_to_bucket_index(ft_instance_t ft,
                                of_match_t *match,
                                uint16_t priority)
{
    uint32_t h = FT_HASH_SEED;
    h = murmur_hash(match, sizeof(*match), h);
    h = murmur_hash(&priority, sizeof(priority), h);
    return h % ft->config.strict_match_bucket_count;
}

static int
ft_flow_id_to_bucket_index(ft_instance_t ft, indigo_flow_id_t *flow_id)
{
    return (murmur_hash(flow_id, sizeof(*flow_id), FT_HASH_SEED) %
            ft->config.flow_id_bucket_count);
}

static int
ft_cookie_to_bucket_index(ft_instance_t ft, uint64_t cookie)
{
    return cookie >> (64-FT_COOKIE_PREFIX_LEN);
}

ft_instance_t
ft_create(ft_config_t *config)
{
    ft_instance_t ft;
    int bytes;
    int idx;

    /* Allocate the flow table itself */
    ft = INDIGO_MEM_ALLOC(sizeof(*ft));
    if (ft == NULL) {
        LOG_ERROR("ERROR: Flow table (hash) creation failed");
        return NULL;
    }
    INDIGO_MEM_SET(ft, 0, sizeof(*ft));
    INDIGO_MEM_COPY(&ft->config,  config, sizeof(ft_config_t));

    list_init(&ft->all_list);

    /* Allocate and init buckets for each search type */
    bytes = sizeof(list_head_t) * config->strict_match_bucket_count;
    ft->strict_match_buckets = INDIGO_MEM_ALLOC(bytes);
    if (ft->strict_match_buckets == NULL) {
        LOG_ERROR("ERROR: Flow table, strict_match bucket alloc failed");
        ft_destroy(ft);
        return NULL;
    }
    INDIGO_MEM_SET(ft->strict_match_buckets, 0, bytes);
    for (idx = 0; idx < config->strict_match_bucket_count; idx++) {
        list_init(&ft->strict_match_buckets[idx]);
    }

    bytes = sizeof(list_head_t) * config->flow_id_bucket_count;
    ft->flow_id_buckets = INDIGO_MEM_ALLOC(bytes);
    if (ft->flow_id_buckets == NULL) {
        LOG_ERROR("ERROR: Flow table, flow id bucket alloc failed");
        ft_destroy(ft);
        return NULL;
    }
    INDIGO_MEM_SET(ft->flow_id_buckets, 0, bytes);
    for (idx = 0; idx < config->flow_id_bucket_count; idx++) {
        list_init(&ft->flow_id_buckets[idx]);
    }

    bytes = sizeof(list_head_t) * (1 << FT_COOKIE_PREFIX_LEN);
    ft->cookie_buckets = INDIGO_MEM_ALLOC(bytes);
    if (ft->cookie_buckets == NULL) {
        LOG_ERROR("ERROR: Flow table, flow id bucket alloc failed");
        ft_destroy(ft);
        return NULL;
    }
    INDIGO_MEM_SET(ft->cookie_buckets, 0, bytes);
    for (idx = 0; idx < (1 << FT_COOKIE_PREFIX_LEN); idx++) {
        list_init(&ft->cookie_buckets[idx]);
    }

    return ft;
}

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
ft_destroy(ft_instance_t ft)
{
    ft_entry_t *entry;
    list_links_t *cur, *next;

    if (ft == NULL) {
        return;
    }

    FT_ITER(ft, entry, cur, next) {
        ft_entry_unlink(ft, entry);
        ft_entry_destroy(ft, entry);
    }

    if (ft->strict_match_buckets != NULL) {
        CHECK_BUCKETS(strict_match);
        INDIGO_MEM_FREE(ft->strict_match_buckets);
        ft->strict_match_buckets = NULL;
    }
    if (ft->flow_id_buckets != NULL) {
        CHECK_BUCKETS(flow_id);
        INDIGO_MEM_FREE(ft->flow_id_buckets);
        ft->flow_id_buckets = NULL;
    }
    if (ft->cookie_buckets != NULL) {
        INDIGO_MEM_FREE(ft->cookie_buckets);
        ft->cookie_buckets = NULL;
    }

    INDIGO_MEM_FREE(ft);
}

indigo_error_t
ft_add(ft_instance_t ft, indigo_flow_id_t id,
       of_flow_add_t *flow_add, ft_entry_t **entry_p)
{
    ft_entry_t *entry = NULL;
    indigo_error_t rv;

    LOG_TRACE("Adding flow " INDIGO_FLOW_ID_PRINTF_FORMAT, id);

    /* If flow ID already exists, error. */
    if (ft_lookup(ft, id) != NULL) {
        return INDIGO_ERROR_EXISTS;
    }

    if ((rv = ft_entry_create(id, flow_add, &entry)) < 0) {
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

indigo_error_t
ft_delete(ft_instance_t ft, ft_entry_t *entry)
{
    LOG_TRACE("Delete rsn %d flow " INDIGO_FLOW_ID_PRINTF_FORMAT,
              entry->removed_reason, entry->id);

    ft_entry_unlink(ft, entry);
    ft_entry_destroy(ft, entry);

    ft->status.current_count -= 1;
    ft->status.deletes += 1;

    return INDIGO_ERROR_NONE;
}

indigo_error_t
ft_delete_id(ft_instance_t ft,
                       indigo_flow_id_t id)
{
    ft_entry_t *entry;

    if ((entry = ft_lookup(ft, id)) == NULL) {
        LOG_VERBOSE("Delete: Failed to find flow "
                    INDIGO_FLOW_ID_PRINTF_FORMAT, id);
        return INDIGO_ERROR_NOT_FOUND;
    }
    return ft_delete(ft, entry);
}

indigo_error_t
ft_strict_match(ft_instance_t instance,
               of_meta_match_t *query,
               ft_entry_t **entry_ptr)
{
    int bucket_idx;
    list_links_t *cur;

    INDIGO_ASSERT(query->mode == OF_MATCH_STRICT);

    bucket_idx = ft_strict_match_to_bucket_index(instance, &query->match,
                                                 query->priority);
    list_head_t *bucket = &instance->strict_match_buckets[bucket_idx];

    LIST_FOREACH(bucket, cur) {
        ft_entry_t *entry = FT_ENTRY_CONTAINER(cur, strict_match);
        if (!FT_FLOW_STATE_IS_DELETED(entry->state) &&
                ft_entry_meta_match(query, entry)) {
            *entry_ptr = entry;
            return INDIGO_ERROR_NONE;
        }
    }

    return INDIGO_ERROR_NOT_FOUND;
}

ft_entry_t *
ft_lookup(ft_instance_t ft, indigo_flow_id_t id)
{
    int bucket_idx = ft_flow_id_to_bucket_index(ft, &id);
    list_head_t *bucket = &ft->flow_id_buckets[bucket_idx];
    list_links_t *cur;

    LIST_FOREACH(bucket, cur) {
        ft_entry_t *entry = FT_ENTRY_CONTAINER(cur, flow_id);
        if (!FT_FLOW_STATE_IS_DELETED(entry->state) && entry->id == id) {
            return entry;
        }
    }

    return NULL;
}

int
ft_entry_meta_match(of_meta_match_t *query, ft_entry_t *entry)
{
    uint64_t mask;
    int rv = 0; /* Default is no match */

    if (FT_FLOW_STATE_IS_DELETED(entry->state)) return (rv);

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
        if (!of_match_more_specific(&entry->match, &query->match)) {
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
        if (!of_match_eq(&entry->match, &query->match)) {
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
        if (!of_match_overlap(&entry->match, &query->match)) {
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

void
ft_entry_mark_deleted(ft_instance_t ft, ft_entry_t *entry,
                      indigo_fi_flow_removed_t reason)
{
    if (FT_FLOW_STATE_IS_DELETED(entry->state)) {
        return;
    }

    entry->state = FT_FLOW_STATE_DELETE_MARKED;
    entry->removed_reason = reason;

    ft->status.pending_deletes += 1;
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
        instance->status.updates += 1;
    }

    return err;
}

indigo_error_t
ft_entry_clear_counters(ft_entry_t *entry, uint64_t *packets, uint64_t *bytes)
{
    if (packets) {
        *packets = entry->packets;
    }
    if (bytes) {
        *bytes = entry->bytes;
    }

    entry->packets = 0;
    entry->bytes = 0;

    /* @fixme Update last counter update/change? */

    return INDIGO_ERROR_NONE;
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
            INDIGO_MEM_FREE(state);
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

    struct ft_iter_task_state *state = INDIGO_MEM_ALLOC(sizeof(*state));
    if (state == NULL) {
        return INDIGO_ERROR_RESOURCE;
    }

    state->callback = callback;
    state->cookie = cookie;

    ft_iterator_init(&state->iter, instance, query);

    rv = ind_soc_task_register(ft_iter_task_callback, state, priority);
    if (rv != INDIGO_ERROR_NONE) {
        INDIGO_MEM_FREE(state);
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
    while (iter->next_entry != NULL) {
        ft_entry_t *entry = iter->next_entry;

        list_remove(&iter->entry_links);

        list_links_t *next_links = ft_iterator_entry_to_links(iter, iter->next_entry)->next;
        if (next_links == &iter->head->links) {
            /* Finished iteration */
            iter->next_entry = NULL;
        } else {
            iter->next_entry = ft_iterator_links_to_entry(iter, next_links);
            list_push(&iter->next_entry->iterators, &iter->entry_links);
        }

        if (FT_FLOW_STATE_IS_DELETED(entry->state)) {
            continue;
        }

        if (iter->use_query && !ft_entry_meta_match(&iter->query, entry)) {
            continue;
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

    if (ft->strict_match_buckets) { /* Strict match hash */
        idx = ft_strict_match_to_bucket_index(ft, &entry->match, entry->priority);
        list_push(&ft->strict_match_buckets[idx], &entry->strict_match_links);
    }
    if (ft->flow_id_buckets) { /* Flow ID hash */
        idx = ft_flow_id_to_bucket_index(ft, &entry->id);
        list_push(&ft->flow_id_buckets[idx], &entry->flow_id_links);
    }
    if (ft->cookie_buckets) { /* Cookie prefix */
        idx = ft_cookie_to_bucket_index(ft, entry->cookie);
        list_push(&ft->cookie_buckets[idx], &entry->cookie_links);
    }

    list_init(&entry->iterators);
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

    if (ft->strict_match_buckets) { /* Strict match hash */
        INDIGO_ASSERT(!list_empty(&ft->strict_match_buckets[
            ft_strict_match_to_bucket_index(ft, &entry->match, entry->priority)]));
        list_remove(&entry->strict_match_links);
    }
    if (ft->flow_id_buckets) { /* Flow ID hash */
        INDIGO_ASSERT(!list_empty(&ft->flow_id_buckets[ft_flow_id_to_bucket_index(ft,
            &entry->id)]));
        list_remove(&entry->flow_id_links);
    }
    if (ft->cookie_buckets) { /* Cookie prefix */
        INDIGO_ASSERT(!list_empty(&ft->cookie_buckets[ft_cookie_to_bucket_index(ft,
            entry->cookie)]));
        list_remove(&entry->cookie_links);
    }
}

/**
 * Allocate and initialize a new flowtable entry
 *
 * @param id The flow ID to use
 * @param flow_add Pointer to the flow add object for the entry
 * @param_p entry Populated with pointer to new flowtable entry on success
 *
 * The list links are not modified by this call.
 */
static indigo_error_t
ft_entry_create(indigo_flow_id_t id, of_flow_add_t *flow_add, ft_entry_t **entry_p)
{
    indigo_error_t err;
    ft_entry_t *entry;

    entry = INDIGO_MEM_ALLOC(sizeof(*entry));
    if (entry == NULL) {
        return INDIGO_ERROR_RESOURCE;
    }
    INDIGO_MEM_SET(entry, 0, sizeof(*entry));

    entry->id = id;

    entry->state = FT_FLOW_STATE_NEW;
    entry->queued_reqs = NULL;
    if (of_flow_add_match_get(flow_add, &entry->match) < 0) {
        INDIGO_MEM_FREE(entry);
        return INDIGO_ERROR_UNKNOWN;
    }
    of_flow_add_cookie_get(flow_add, &entry->cookie);
    of_flow_add_priority_get(flow_add, &entry->priority);
    of_flow_add_flags_get(flow_add, &entry->flags);
    of_flow_add_idle_timeout_get(flow_add, &entry->idle_timeout);
    of_flow_add_hard_timeout_get(flow_add, &entry->hard_timeout);

    err = ft_entry_set_effects(entry, flow_add);
    if (err != INDIGO_ERROR_NONE) {
        INDIGO_MEM_FREE(entry);
        return err;
    }

    entry->insert_time = INDIGO_CURRENT_TIME;
    entry->last_counter_change = entry->insert_time;

    *entry_p = entry;

    return INDIGO_ERROR_NONE;
}

/**
 * Release the data associated with an entry
 *
 * @param entry Pointer to entry being initialized
 *
 * The list links are not modified by this call.
 *
 * The entry ID and state are updated and pending deletes count is
 * decremented.
 */
static void
ft_entry_destroy(ft_instance_t ft, ft_entry_t *entry)
{
    if (entry->effects.actions != NULL) {
        of_list_action_delete(entry->effects.actions);
        entry->effects.actions = NULL;
    }

    biglist_free(entry->queued_reqs);

    /* If entry was being deleted, pending deletes gets decremented */
    if (FT_FLOW_STATE_IS_DELETED(entry->state)) {
        ft->status.pending_deletes -= 1;
    }

    INDIGO_MEM_FREE(entry);
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
