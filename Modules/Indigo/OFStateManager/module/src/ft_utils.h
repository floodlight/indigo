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

/****************************************************************
 * Flow table utilties header file
 *
 * REQUIRES ft.h to be included
 *
 ****************************************************************/

#ifndef _OFSTATEMANAGER_FT_UTILS_H_
#define _OFSTATEMANAGER_FT_UTILS_H_

#include <BigList/biglist.h>
#include <loci/loci.h>
#include <indigo/indigo.h>

#include <AIM/aim_list.h>
#include <murmur/murmur.h>

#include "ofstatemanager_int.h"
#include "ft.h"

/* Unless directed otherwise, do basic sanity checking */
#if !defined(FT_NO_ERROR_CHECKING)
#define FT_ASSERT(cond) INDIGO_ASSERT(cond)
#else
#define FT_ASSERT(cond)
#endif

/**
 * Populate a list of output ports from actions
 */

static inline biglist_t *
out_port_list_populate_from_actions(of_list_action_t *actions)
{
    of_action_t elt;
    of_action_output_t *output;
    int loop_rv;
    of_port_no_t port_no;
    biglist_t *bl = NULL;

    output = &elt.output;
    OF_LIST_ACTION_ITER(actions, &elt, loop_rv) {
        if (output->object_id == OF_ACTION_OUTPUT) {
            of_action_output_port_get(output, &port_no);
            bl = biglist_prepend(bl, (void*)((uintptr_t)(port_no)));
        }
    }

    return bl;
}

static inline biglist_t *
out_port_list_populate_from_instructions(of_list_instruction_t *instructions)
{
    of_instruction_t inst;
    int loop_rv;
    biglist_t *bl = NULL;

    OF_LIST_INSTRUCTION_ITER(instructions, &inst, loop_rv) {
        if (inst.header.object_id == OF_INSTRUCTION_APPLY_ACTIONS) {
            of_list_action_t actions;
            of_instruction_apply_actions_actions_bind(&inst.apply_actions, &actions);
            bl = biglist_append_list(bl, out_port_list_populate_from_actions(&actions));
        }
    }

    return bl;
}

/* Populate the output port list and effects */
static inline indigo_error_t
ft_flow_set_effects(ft_entry_t *entry,
                    of_flow_modify_t *flow_mod)
{
    if (flow_mod->version == OF_VERSION_1_0)
    {
        of_list_action_t *actions;
        if ((actions = of_flow_modify_actions_get(flow_mod)) == NULL) {
            LOG_ERROR("Could not get action list");
            return INDIGO_ERROR_RESOURCE;
        }
        biglist_free(entry->output_ports);
        of_list_action_delete(entry->effects.actions);
        entry->output_ports = out_port_list_populate_from_actions(actions);
        entry->effects.actions = actions;
    } else {
        of_list_instruction_t *instructions;
        if ((instructions = of_flow_modify_instructions_get(flow_mod)) == NULL) {
            LOG_ERROR("Could not get instruction list");
            return INDIGO_ERROR_RESOURCE;
        }
        biglist_free(entry->output_ports);
        of_list_instruction_delete(entry->effects.instructions);
        entry->output_ports = out_port_list_populate_from_instructions(instructions);
        entry->effects.instructions = instructions;
    }

    return INDIGO_ERROR_NONE;
}

#define FT_HASH_SEED 0

/**
 * @fixme Consider using something other than murmur for small data
 * hash calculations.  Multiplying by a prime is a good option
 */

/**
 * Map a priority to a hash bucket
 */

static inline int
prio_to_bucket_index(ft_instance_t ft, uint16_t priority)
{
    return (murmur_hash(&priority, sizeof(priority), FT_HASH_SEED) %
            ft->config.prio_bucket_count);
}

/**
 * Map a match structure to a hash bucket
 */

static inline int
match_to_bucket_index(ft_instance_t ft, of_match_t *match)
{
    return (murmur_hash(match, sizeof(*match), FT_HASH_SEED) %
            ft->config.match_bucket_count);
}

/**
 * Map a flow id to a hash bucket
 */

static inline int
flow_id_to_bucket_index(ft_instance_t ft, indigo_flow_id_t *flow_id)
{
    return (murmur_hash(flow_id, sizeof(*flow_id), FT_HASH_SEED) %
            ft->config.flow_id_bucket_count);
}

/**
 * Link an entry into the appropriate lists for the FT
 */

static inline void
ft_entry_link(ft_instance_t ft, ft_entry_t *entry)
{
    int idx;

    if (ft == NULL || entry == NULL) {
        FT_ASSERT(!"ft_entry_link called with NULL ft or entry");
        return;
    }

    /* Link to full table iteration */
    list_push(&ft->all_list, &entry->table_links);

    if (ft->prio_buckets) { /* Priority hash */
        idx = prio_to_bucket_index(ft, entry->priority);
        list_push(&ft->prio_buckets[idx], &entry->prio_links);
    }
    if (ft->match_buckets) { /* Strict match hash */
        idx = match_to_bucket_index(ft, &entry->match);
        list_push(&ft->match_buckets[idx], &entry->match_links);
    }
    if (ft->flow_id_buckets) { /* Flow ID hash */
        idx = flow_id_to_bucket_index(ft, &entry->id);
        list_push(&ft->flow_id_buckets[idx], &entry->flow_id_links);
    }
}

/**
 * Unlink an entry into the appropriate lists for the FT
 */

static inline void
ft_entry_unlink(ft_instance_t ft, ft_entry_t *entry)
{
    if (ft == NULL || entry == NULL) {
        FT_ASSERT(!"ft_entry_unlink called with NULL ft or entry");
        return;
    }

    FT_ASSERT(!list_empty(&ft->all_list));

    /* Remove from full table iteration */
    list_remove(&entry->table_links);

    if (ft->prio_buckets) { /* Priority hash */
        FT_ASSERT(!list_empty(&ft->prio_buckets[prio_to_bucket_index(ft,
            entry->priority)]));
        list_remove(&entry->prio_links);
    }
    if (ft->match_buckets) { /* Strict match hash */
        FT_ASSERT(!list_empty(&ft->match_buckets[match_to_bucket_index(ft,
            &entry->match)]));
        list_remove(&entry->match_links);
    }
    if (ft->flow_id_buckets) { /* Flow ID hash */
        FT_ASSERT(!list_empty(&ft->flow_id_buckets[flow_id_to_bucket_index(ft,
            &entry->id)]));
        list_remove(&entry->flow_id_links);
    }
}

/**
 * Look up a flow in a hash table instance by ID
 *
 * @param ft The flow table instance
 * @param id The flow ID being checked
 */

static inline ft_entry_t *
ft_id_lookup(ft_instance_t ft, indigo_flow_id_t id)
{
    int idx;
    ft_entry_t *entry = NULL, *iter_entry;
    list_links_t *cur, *next;

    idx = flow_id_to_bucket_index(ft, &id);
    FT_FLOW_ID_ITER(ft, id, idx, iter_entry, cur, next) {
        /* Found a match, break */
        entry = iter_entry;
        break;
    }
    return entry;
}


/**
 * Modify the cookie associated with a specific entry in the table
 * @param ft Handle for a flow table instance
 * @param id The flow ID associated with the entry to delete
 * @param cookie Cookie value to use for modify
 * @param cookie_mask Indicates part of cookie to update
 * @returns INDIGO_ERROR_NOT_FOUND Entry with this ID was not found the table
 */

static inline indigo_error_t
ft_flow_modify_cookie(ft_instance_t instance, ft_entry_t *entry,
                      uint64_t cookie, uint64_t cookie_mask)
{
    entry->cookie = (entry->cookie & cookie_mask) | (cookie & cookie_mask);

    return INDIGO_ERROR_NONE;
}

/**
 * Modify the effects of a flow entry in the table
 * @param ft The flow table handle
 * @param entry Pointer to the entry to update
 * @param flow_mod The LOCI flow mod object resulting in the modification
 *
 * The actions (instructions) and related metadata are updated for the flow
 */

static inline indigo_error_t
ft_flow_modify_effects(ft_instance_t instance,
                       ft_entry_t *entry,
                       of_flow_modify_t *flow_mod)
{
    indigo_error_t err;

    LOG_TRACE("Modifying effects of entry " INDIGO_FLOW_ID_PRINTF_FORMAT,
              entry->id);

    err = ft_flow_set_effects(entry, flow_mod);
    if (err == INDIGO_ERROR_NONE) {
        instance->status.updates += 1;
    }

    return err;
}

/**
 * Clear the counters associated with a specific entry in the table
 * @param entry The entry to update
 * @param packets (out) If non-NULL, store current packet count here
 * @param bytes (out) If non-NULL, store current byte count here
 *
 * The output parameters may be NULL in which case they are ignored.
 */

static inline indigo_error_t
ft_flow_clear_counters(ft_entry_t *entry, uint64_t *packets, uint64_t *bytes)
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

/**
 * Initialize the data for a flow entry that is being added
 *
 * @param entry Pointer to entry being initialized
 * @param id The flow ID to use
 * @param flow_add Pointer to the flow add object for the entry
 *
 * The list links are not modified by this call.
 */
static inline indigo_error_t
ft_entry_setup(ft_entry_t *entry, indigo_flow_id_t id, of_flow_add_t *flow_add)
{
    of_flow_add_t *dup;
    indigo_error_t err;

    INDIGO_ASSERT(entry->state == FT_FLOW_STATE_FREE);

    entry->id = id;
    dup = (of_flow_add_t *)of_object_dup(flow_add);
    if (dup == NULL) {
        return INDIGO_ERROR_RESOURCE;
    }

    entry->state = FT_FLOW_STATE_NEW;
    entry->queued_reqs = NULL;
    entry->flow_add = dup;
    if (of_flow_add_match_get(flow_add, &entry->match) < 0) {
        of_object_delete(dup);
        return INDIGO_ERROR_UNKNOWN;
    }
    of_flow_add_cookie_get(flow_add, &entry->cookie);
    of_flow_add_priority_get(flow_add, &entry->priority);
    of_flow_add_flags_get(flow_add, &entry->flags);
    of_flow_add_idle_timeout_get(flow_add, &entry->idle_timeout);
    of_flow_add_hard_timeout_get(flow_add, &entry->hard_timeout);

    err = ft_flow_set_effects(entry, flow_add);
    if (err != INDIGO_ERROR_NONE) {
        return err;
    }

    entry->insert_time = INDIGO_CURRENT_TIME;
    entry->last_counter_change = entry->insert_time;

    return INDIGO_ERROR_NONE;
}

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

static inline void
ft_flow_mark_deleted(ft_instance_t ft, ft_entry_t *entry,
                     indigo_fi_flow_removed_t reason)
{
    if (FT_FLOW_STATE_IS_DELETED(entry->state)) {
        return;
    }

    entry->state = FT_FLOW_STATE_DELETE_MARKED;
    entry->removed_reason = reason;

    ft->status.pending_deletes += 1;
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
static inline void
ft_entry_clear(ft_instance_t ft, ft_entry_t *entry)
{
    if (entry->output_ports != NULL) {
        biglist_free(entry->output_ports);
        entry->output_ports = NULL;
    }
    if (entry->effects.actions != NULL) {
        of_list_action_delete(entry->effects.actions);
        entry->effects.actions = NULL;
    }
    if (entry->flow_add != NULL) {
        of_flow_add_delete(entry->flow_add);
        entry->flow_add = NULL;
    }

    biglist_free(entry->queued_reqs);
    entry->id = INDIGO_FLOW_ID_INVALID;

    /* If entry was being deleted, pending deletes gets decremented */
    if (FT_FLOW_STATE_IS_DELETED(entry->state)) {
        ft->status.pending_deletes -= 1;
    }
    entry->state = FT_FLOW_STATE_FREE;
}

extern indigo_error_t ft_flow_first_match(ft_instance_t instance,
                                          of_meta_match_t *query,
                                          ft_entry_t **entry_ptr);

extern biglist_t *ft_flow_query(ft_instance_t instance,
                                of_meta_match_t *query);


typedef void (*ft_iter_task_callback_f)(void *cookie, ft_entry_t *entry);

indigo_error_t
ft_spawn_iter_task(ft_instance_t instance,
                   of_meta_match_t *query,
                   ft_iter_task_callback_f callback,
                   void *cookie,
                   int priority);

#endif /* _OFSTATEMANAGER_FT_UTILS_H_ */
