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
 * @brief OpenFlow state manager module public functions
 *
 * See detailed documentation in the Indigo architecture headers.
 */

#include "ofstatemanager_log.h"

#include <OFStateManager/ofstatemanager_config.h>
#include <OFConnectionManager/ofconnectionmanager.h>
#include <Configuration/configuration.h>
#include <indigo/forwarding.h>
#include <indigo/indigo.h>
#include <indigo/of_state_manager.h>
#include <loci/loci_dump.h>
#include <loci/loci_show.h>
#include "ofstatemanager_int.h"
#include "ofstatemanager_log.h"
#include "ofstatemanager_decs.h"
#include "handlers.h"
#include "ft.h"

static void flow_expiration_timer(void *cookie);

/**
 * @brief Core configuration for the module
 */

ind_core_config_t ind_core_config;

/**
 * @brief Core configuration object for OF related data
 */
ind_core_of_config_t ind_core_of_config;

/**
 * @brief Core flow table instance
 */
ft_instance_t ind_core_ft;

int ind_core_init_done = 0;
int ind_core_module_enabled = 0;

/**
 * Maintain the current connection count.
 *
 * In case the disconnect mode configuration changes, we may need to change the
 * system behavior because of its current state.
 */
static int ind_core_connection_count;

#define INIT_CHECK do {                         \
        if (!ind_core_init_done) {              \
            LOG_ERROR("Not initialized");       \
            return INDIGO_ERROR_INIT;           \
        }                                       \
    } while(0)

#define ENABLED_CHECK do {                      \
        if (!ind_core_module_enabled) {         \
            LOG_ERROR("Not enabled");           \
            return INDIGO_ERROR_INIT;           \
        }                                       \
    } while(0)


/* Handle a packet in from forwarding */
indigo_error_t
indigo_core_packet_in(of_packet_in_t *packet_in)
{
    int rv;

    if (!ind_core_module_enabled) {
        LOG_TRACE("Packet in called when not enabled");
        of_object_delete(packet_in);
        return INDIGO_ERROR_INIT;
    }

    LOG_TRACE("Packet in rcvd");

    rv = indigo_cxn_send_controller_message(INDIGO_CXN_ID_UNSPECIFIED,
                                            packet_in);

    /* PAN-163.  Not sure why these get printed out; changed to TRACE */
    /* Don't log error when there is no preferred connection in cxn manager */
    if (rv != INDIGO_ERROR_NONE && rv != INDIGO_ERROR_NOT_READY) {
        LOG_TRACE("Error forwarding packet in to controller");
    }

    return rv;
}


/****************************************************************/

/**
 * @brief Send a flow removed message for the given entry
 * @param entry The local flow table entry
 */

static void
send_flow_removed_message(ft_entry_t *entry)
{
    of_flow_removed_t *msg;
    int rv = 0;
    uint32_t secs;
    uint32_t nsecs;
    indigo_time_t current;
    indigo_fi_flow_removed_t reason;

    current = INDIGO_CURRENT_TIME;
    if ((msg = of_flow_removed_new(entry->match.version)) == NULL) {
        return;
    }

    calc_duration(current, entry->insert_time, &secs, &nsecs);

    of_flow_removed_xid_set(msg, ind_core_xid_alloc());

    of_flow_removed_cookie_set(msg, entry->cookie);
    of_flow_removed_priority_set(msg, entry->priority);
    of_flow_removed_idle_timeout_set(msg, entry->idle_timeout);

    if (msg->version >= OF_VERSION_1_1) {
        of_flow_removed_table_id_set(msg, entry->table_id);
    }

    if (msg->version >= OF_VERSION_1_2) {
        of_flow_removed_hard_timeout_set(msg, entry->hard_timeout);
    }

    if (of_flow_removed_match_set(msg, &entry->match)) {
        LOG_ERROR("Failed to set match in flow removed message");
        of_object_delete(msg);
        return;
    }

    reason = entry->removed_reason;
    if (reason > INDIGO_FLOW_REMOVED_DELETE) {
        /* Normalize entry */
        reason = INDIGO_FLOW_REMOVED_DELETE;
    }
    of_flow_removed_reason_set(msg, reason);
    of_flow_removed_duration_sec_set(msg, secs);
    of_flow_removed_duration_nsec_set(msg, nsecs);
    of_flow_removed_packet_count_set(msg, entry->packets);
    of_flow_removed_byte_count_set(msg, entry->bytes);

    /* @fixme hard_timeout and table_id are not in OF 1.0 */

    /* @fixme Should a cxn-id be specified? */
    rv = indigo_cxn_send_controller_message(INDIGO_CXN_ID_UNSPECIFIED, msg);
    if (rv != INDIGO_ERROR_NONE) {
        LOG_ERROR("Error sending flow removed message");
        return;
    }

    return;
}

/****************************************************************/

/**
 * @brief Handle an OF message from the controller
 * @param cxn The connection id from which the request came
 * @param obj The generic LOXI object holding the message
 *
 * If a handler is called, the handler takes ownership of the LOXI object
 *
 * In any case, ownership of obj is NOT returned to the caller.
 */

indigo_error_t
indigo_core_receive_controller_message(indigo_cxn_id_t cxn, of_object_t *obj)
{
    int rv = INDIGO_ERROR_NONE;

    ENABLED_CHECK;

    LOG_TRACE("Received msg type %s (%d)",
             of_object_id_str[obj->object_id], obj->object_id);

    /* Add non-default jump table mechanism here */
    // if (dynamic_handlers[obj->object_id] != NULL) {
    //     rv = dynamic_handlers[obj->object_id](obj, cxn);
    //     LOG_TRACE("Handled msg %s with dynamic hndlr. rv %d (%s)",
    //           of_object_id_str[obj->object_id], rv, ls_error_strings[rv]);
    //     return rv;
    // }

    /* Default handlers */
    switch (obj->object_id) {

    case OF_HELLO:
        rv = ind_core_hello_handler(obj, cxn);
        break;

    case OF_PACKET_OUT:
        rv = ind_core_packet_out_handler(obj, cxn);
        break;

    case OF_FLOW_ADD:
        rv = ind_core_flow_add_handler(obj, cxn);
        break;

    case OF_FLOW_MODIFY:
        rv = ind_core_flow_modify_handler(obj, cxn);
        break;

    case OF_FLOW_MODIFY_STRICT:
        rv = ind_core_flow_modify_strict_handler(obj, cxn);
        break;

    case OF_FLOW_DELETE:
        rv = ind_core_flow_delete_handler(obj, cxn);
        break;

    case OF_FLOW_DELETE_STRICT:
        rv = ind_core_flow_delete_strict_handler(obj, cxn);
        break;

    case OF_PORT_STATS_REQUEST:
        rv = ind_core_port_stats_request_handler(obj, cxn);
        break;

    case OF_GET_CONFIG_REQUEST:
        rv = ind_core_get_config_request_handler(obj, cxn);
        break;

    case OF_SET_CONFIG:
        rv = ind_core_set_config_handler(obj, cxn);
        break;

    case OF_FLOW_STATS_REQUEST:
        rv = ind_core_flow_stats_request_handler(obj, cxn);
        break;

    case OF_AGGREGATE_STATS_REQUEST:
        rv = ind_core_aggregate_stats_request_handler(obj, cxn);
        break;

    case OF_TABLE_STATS_REQUEST:
        rv = ind_core_table_stats_request_handler(obj, cxn);
        break;

    case OF_DESC_STATS_REQUEST:
        rv = ind_core_desc_stats_request_handler(obj, cxn);
        break;

    case OF_PORT_DESC_STATS_REQUEST:
        rv = ind_core_port_desc_stats_request_handler(obj, cxn);
        break;

    case OF_FEATURES_REQUEST:
        rv = ind_core_features_request_handler(obj, cxn);
        break;

    case OF_ECHO_REPLY: /* Handled by cxn_instance for now */
        rv = ind_core_echo_reply_handler(obj, cxn);
        break;

    case OF_EXPERIMENTER:
        rv = ind_core_experimenter_handler(obj, cxn);
        break;

    case OF_PORT_MOD:
        rv = ind_core_port_mod_handler(obj, cxn);
        break;

    case OF_QUEUE_GET_CONFIG_REQUEST:
        rv = ind_core_queue_get_config_request_handler(obj, cxn);
        break;

    case OF_QUEUE_STATS_REQUEST:
        rv = ind_core_queue_stats_request_handler(obj, cxn);
        break;

    /****************************************************************
     * Extension messages
     ****************************************************************/

    case OF_BSN_SET_IP_MASK:
        rv = ind_core_bsn_set_ip_mask_handler(obj, cxn);
        break;

    case OF_BSN_GET_IP_MASK_REQUEST:
        rv = ind_core_bsn_get_ip_mask_request_handler(obj, cxn);
        break;

    /* These all use the experimenter handler */
    case OF_BSN_GET_MIRRORING_REQUEST:
    case OF_BSN_SET_MIRRORING:
    case OF_BSN_SHELL_COMMAND:
    case OF_BSN_GET_INTERFACES_REQUEST:
    case OF_BSN_SET_PKTIN_SUPPRESSION_REQUEST:
    case OF_BSN_SET_L2_TABLE_REQUEST:
    case OF_BSN_GET_L2_TABLE_REQUEST:
    case OF_BSN_VIRTUAL_PORT_CREATE_REQUEST:
    case OF_BSN_VIRTUAL_PORT_REMOVE_REQUEST:
    case OF_BSN_BW_CLEAR_DATA_REQUEST:
    case OF_BSN_BW_ENABLE_GET_REQUEST:
    case OF_BSN_BW_ENABLE_SET_REQUEST:
        rv = ind_core_experimenter_handler(obj, cxn);
        break;

    /****************************************************************
     * These are not yet implemented
     ****************************************************************/

#if NOT_YET

    case OF_TABLE_MOD:
        rv = ind_core_table_mod_handler(obj, cxn);
        break;

    case OF_EXPERIMENTER_STATS_REQUEST:
        rv = ind_core_experimenter_stats_request_handler(obj, cxn);
        break;

    case OF_GROUP_DESC_STATS_REQUEST:
        rv = ind_core_group_desc_stats_request_handler(obj, cxn);
        break;

    case OF_GROUP_FEATURES_STATS_REQUEST:
        rv = ind_core_group_features_stats_request_handler(obj, cxn);
        break;
#endif

    /****************************************************************
     * These will never be handled by a switch
     ****************************************************************/
    case OF_AGGREGATE_STATS_REPLY:
    case OF_BARRIER_REPLY:
    case OF_DESC_STATS_REPLY:
    case OF_ERROR_MSG:
    case OF_EXPERIMENTER_STATS_REPLY:
    case OF_FEATURES_REPLY:
    case OF_FLOW_REMOVED:
    case OF_FLOW_STATS_REPLY:
    case OF_GET_CONFIG_REPLY:
    case OF_GROUP_DESC_STATS_REPLY:
    case OF_GROUP_FEATURES_STATS_REPLY:
    case OF_GROUP_MOD:
    case OF_GROUP_STATS_REPLY:
    case OF_GROUP_STATS_REQUEST:
    case OF_PACKET_IN:
    case OF_PORT_STATS_REPLY:
    case OF_PORT_STATUS:
    case OF_QUEUE_GET_CONFIG_REPLY:
    case OF_QUEUE_STATS_REPLY:
    case OF_ROLE_REPLY:
    case OF_TABLE_STATS_REPLY:
        rv = ind_core_unhandled_message(obj, cxn);
        break;

    default:
        LOG_ERROR("Unhandled message type %d\n", obj->object_id);
        rv = ind_core_unhandled_message(obj, cxn);
        break;
    }

    LOG_TRACE("Handled msg %p with rv %d", obj, rv);

    return rv;
}

static of_dpid_t ind_core_dpid = OFSTATEMANAGER_CONFIG_DPID_DEFAULT;

/* Allow the DPID to be set by the configuration */
indigo_error_t
indigo_core_dpid_set(of_dpid_t dpid)
{
    if (ind_core_dpid != dpid) {
        LOG_INFO("Changing switch DPID\n");
        INDIGO_MEM_COPY(&ind_core_dpid, &dpid, sizeof(ind_core_dpid));
        ind_cxn_reset(IND_CXN_RESET_ALL);
    } else {
        LOG_VERBOSE("Switch DPID set called but unchanged\n");
    }

    return INDIGO_ERROR_NONE;
}

/* Return the DPID; exposed to all functions in the module */
indigo_error_t
indigo_core_dpid_get(of_dpid_t *dpid)
{
    INIT_CHECK;

    INDIGO_MEM_COPY(dpid, &ind_core_dpid, sizeof(ind_core_dpid));

    return INDIGO_ERROR_NONE;
}


#define INIT_STR(var, val) INDIGO_MEM_COPY(&(var), (val), sizeof(val))

indigo_error_t
ind_core_init(ind_core_config_t *config)
{
    ft_config_t ft_config;

    INDIGO_MEM_COPY(&ind_core_config, config, sizeof(*config));

    LOG_TRACE("OF state mgr init called");

    if (ind_core_init_done) {
        return INDIGO_ERROR_NONE;
    }

    ind_cfg_register(&ind_core_cfg_ops);

    /* Give some values to desc stats members */
    INIT_STR(ind_core_of_config.desc_stats.sw_desc,
             IND_CORE_SW_DESC_DEFAULT);
    INIT_STR(ind_core_of_config.desc_stats.hw_desc,
             IND_CORE_HW_DESC_DEFAULT);
    INIT_STR(ind_core_of_config.desc_stats.dp_desc,
             IND_CORE_DP_DESC_DEFAULT);
    INIT_STR(ind_core_of_config.desc_stats.mfr_desc,
             IND_CORE_MFR_DESC_DEFAULT);
    INIT_STR(ind_core_of_config.desc_stats.serial_num,
             IND_CORE_SERIAL_NUM_DEFAULT);

    /* Create flow table */
    if (config->max_flowtable_entries == 0) {
        /* Default value */
        config->max_flowtable_entries = 16384;
    }
    ft_config.max_entries = config->max_flowtable_entries;
    ft_config.strict_match_bucket_count = config->max_flowtable_entries;
    ft_config.flow_id_bucket_count = config->max_flowtable_entries;

    if ((ind_core_ft = ft_create(&ft_config)) == NULL) {
        LOG_ERROR("Unable to allocate flow table\n");
        return INDIGO_ERROR_RESOURCE;
    }

    ind_core_connection_count = 0;

    ind_core_init_done = 1;

    return INDIGO_ERROR_NONE;
}

/**
 * @brief Callback for response to flow stats request
 *
 * The ind_core_flow_stats_state struct was allocated by the caller of
 * indigo_fwd_flow_stats_get and is shared by multiple concurrent
 * calls.
 *
 * The callback function pointer in the state struct is called for
 * each result. Callers are intended to allocate any extra space
 * necessary after the end of the state struct.
 *
 * The callback will be called with flow_stats == NULL after the
 * last result. This is when any private data should be cleaned up.
 *
 * The caller must call this function with a NULL flow_stats argument
 * after finishing making indigo_fwd_flow_stats_get calls. This
 * serves two purposes:
 * 1. Giving this function and the callback a chance to clean up if
 *    the caller didn't actually make any flow stats requests.
 * 2. Cleaning up if the Forwarding module made all the callbacks
 *    synchronously.
 */

void
indigo_core_flow_stats_get_callback(indigo_error_t result,
                                    indigo_fi_flow_stats_t *flow_stats,
                                    indigo_cookie_t cookie)
{
    ind_core_flow_stats_state_t *state = INDIGO_COOKIE_TO_POINTER(cookie);

    if (!ind_core_init_done) {
        return;
    }

    if (flow_stats != NULL) {
        state->received_count++;
        state->callback(state, flow_stats);
    } else {
        state->finished_calls = 1;
    }

    if ((state->received_count == state->expected_count) &&
            state->finished_calls) {
        state->callback(state, NULL);
        INDIGO_MEM_FREE(state);
    }
}

/**
 * @brief Do the necessary processing to delete a flow entry
 *
 * Assumes the entry still exists in forwarding.  If not, use the
 * call indigo_core_flow_removed.
 *
 * Mark the entry deleted in the flow table.  If the entry is
 * stable (no op pending) then actually process the deletion here by
 * calling into forwarding.
 *
 * Should we need to decouple this from the delete call to forwarding,
 * we would just do the marking here and then a separate thread would be
 * signalled (or called periodically) to do the fwd_flow_delete.
 */

void
ind_core_flow_entry_delete(ft_entry_t *entry, indigo_fi_flow_removed_t reason)
{
    /* Mark the flow deleted or pending in OF state mgr table */
    ft_entry_mark_deleted(ind_core_ft, entry, reason);

    /* If it is not pending, notify forwarding; final cleanup occurs in
     * flow deleted callback. */
    if (entry->state == FT_FLOW_STATE_DELETE_MARKED) {
        LOG_TRACE("Removing flow " INDIGO_FLOW_ID_PRINTF_FORMAT,
                  INDIGO_FLOW_ID_PRINTF_ARG(entry->id));
        entry->state = FT_FLOW_STATE_DELETING;
        indigo_fwd_flow_delete(entry->id, INDIGO_POINTER_TO_COOKIE(entry));
    }
}

/**
 * @brief Process a flow removal from the local flow table
 */

static void
process_flow_removal(ft_entry_t *entry,
                     indigo_fi_flow_stats_t *final_stats)
{
    indigo_error_t rv;
    biglist_t      *ble;

    if (entry->state == FT_FLOW_STATE_FREE) {
        LOG_VERBOSE("Remove flow in state %d; ignoring", entry->state);
        return;
    }

    if (entry->flags & OF_FLOW_MOD_FLAG_SEND_FLOW_REM) {
        /* See OF spec 1.0.1, section 3.5, page 6 */
        if (entry->removed_reason != INDIGO_FLOW_REMOVED_OVERWRITE) {
            if (final_stats != NULL) {
                INDIGO_ASSERT(final_stats->flow_id == entry->id);
                entry->packets = final_stats->packets;
                entry->bytes = final_stats->bytes;
            } else {
                entry->packets = (uint64_t)-1;
                entry->bytes = (uint64_t)-1;
            }

            send_flow_removed_message(entry);
        }
    }

    /* Delete the entry from the local table */
    BIGLIST_FOREACH(ble, entry->queued_reqs) {
       INDIGO_MEM_FREE(BIGLIST_CAST(void *, ble));
    }
    entry->queued_reqs = NULL;
    rv = ft_delete(ind_core_ft, entry);
    if (rv != INDIGO_ERROR_NONE) {
        LOG_ERROR("Error deleting flow from state mgr. id: "
                  INDIGO_FLOW_ID_PRINTF_FORMAT,
                  INDIGO_FLOW_ID_PRINTF_ARG(entry->id));
    }
    LOG_TRACE("Flow table now has %d entries",
              FT_STATUS(ind_core_ft)->current_count);
}

/**
 * @brief Handle the async notice (from fwding) that a flow was removed
 *
 * @param reason The reason the flow was removed
 * @param stats Pointer to final stats which includes the flow ID
 */

void
indigo_core_flow_removed(indigo_fi_flow_removed_t reason,
                         indigo_fi_flow_stats_t *stats)
{
    ft_entry_t *entry;

    if (!ind_core_init_done) {
        return;
    }

    LOG_TRACE("Async flow removed. reason %d. id "
              INDIGO_FLOW_ID_PRINTF_FORMAT, reason,
              INDIGO_FLOW_ID_PRINTF_ARG((indigo_cookie_t) stats->flow_id));

    /* After entry look up, this looks like flow delete callback */
    entry = ft_lookup(ind_core_ft, stats->flow_id);
    if (entry == NULL) {
        LOG_TRACE("Async flow removed: did not find entry in SM table. id "
                  INDIGO_FLOW_ID_PRINTF_FORMAT,
                  INDIGO_FLOW_ID_PRINTF_ARG((indigo_cookie_t) stats->flow_id));
        return;
    }

    entry->removed_reason = reason;
    process_flow_removal(entry, stats);
}

/**
 * @brief Callback for response to flow delete request
 *
 * The cookie is a pointer to the local flow table entry
 */

void
indigo_core_flow_delete_callback(indigo_error_t result,
                                 indigo_fi_flow_stats_t *flow_stats,
                                 indigo_cookie_t cookie)
{
    ft_entry_t      *entry;

    if (!ind_core_init_done) {
        return;
    }

    entry  = INDIGO_COOKIE_TO_POINTER(cookie);

    LOG_TRACE("Flow delete callback, id " INDIGO_FLOW_ID_PRINTF_FORMAT,
              INDIGO_FLOW_ID_PRINTF_ARG(entry->id));
    if (result != INDIGO_ERROR_NONE) {
        LOG_ERROR("Error deleting flow, id " INDIGO_FLOW_ID_PRINTF_FORMAT,
                  INDIGO_FLOW_ID_PRINTF_ARG(entry->id));
    }

    process_flow_removal(entry, flow_stats);
}

#define CORE_EXPIRES_FLOWS(_cfg) \
    ((_cfg)->expire_flows && ((_cfg)->stats_check_ms > 0))

indigo_error_t
ind_core_enable_set(int enable)
{
    LOG_TRACE("OF state mgr enable called");

    INIT_CHECK;

    if (enable && !ind_core_module_enabled) {
        LOG_INFO("Enabling OF state mgr");
        if (CORE_EXPIRES_FLOWS(&ind_core_config)) {
            ind_soc_timer_event_register_with_priority(
                flow_expiration_timer, NULL,
                ind_core_config.stats_check_ms, -10);
        }
        ind_core_module_enabled = 1;
    } else if (!enable && ind_core_module_enabled) {
        LOG_INFO("Disabling OF state mgr");
        if (CORE_EXPIRES_FLOWS(&ind_core_config)) {
            ind_soc_timer_event_unregister(flow_expiration_timer, NULL);
        }
        ind_core_module_enabled = 0;
    } else {
        LOG_VERBOSE("Redundant enable call.  Currently %s",
                    ind_core_module_enabled ? "enabled" : "disabled");
    }

    return INDIGO_ERROR_NONE;
}


indigo_error_t
ind_core_enable_get(int *enable)
{
    LOG_TRACE("OF state mgr enable get called");
    if (enable == NULL) {
        return INDIGO_ERROR_PARAM;
    }
    *enable = ind_core_module_enabled;

    return INDIGO_ERROR_NONE;
}


indigo_error_t
ind_core_finish(void)
{
    LOG_TRACE("OF state mgr finish called");

    /* Indicate core is shutting down */
    if (ind_core_module_enabled) {
        LOG_VERBOSE("Finish is calling disable");
        ind_core_enable_set(0);
    }

    ft_destroy(ind_core_ft);

    ind_core_init_done = 0;

    return INDIGO_ERROR_NONE;
}


indigo_error_t
ind_core_sw_desc_set(of_desc_str_t desc)
{
    if (!ind_core_init_done) {
        return INDIGO_ERROR_INIT;
    }

    INDIGO_MEM_COPY(ind_core_of_config.desc_stats.sw_desc,
                    desc, OF_DESC_STR_LEN);

    return INDIGO_ERROR_NONE;
}

indigo_error_t
ind_core_sw_desc_get(of_desc_str_t desc)
{
    if (!ind_core_init_done) {
        return INDIGO_ERROR_INIT;
    }
    if (desc == NULL) {
        return INDIGO_ERROR_PARAM;
    }

    INDIGO_MEM_COPY(desc, ind_core_of_config.desc_stats.sw_desc,
                    OF_DESC_STR_LEN);

    return INDIGO_ERROR_NONE;
}

indigo_error_t
ind_core_hw_desc_set(of_desc_str_t desc)
{
    if (!ind_core_init_done) {
        return INDIGO_ERROR_INIT;
    }

    INDIGO_MEM_COPY(ind_core_of_config.desc_stats.hw_desc,
                    desc, OF_DESC_STR_LEN);

    return INDIGO_ERROR_NONE;
}

indigo_error_t
ind_core_hw_desc_get(of_desc_str_t desc)
{
    if (!ind_core_init_done) {
        return INDIGO_ERROR_INIT;
    }
    if (desc == NULL) {
        return INDIGO_ERROR_PARAM;
    }

    INDIGO_MEM_COPY(desc, ind_core_of_config.desc_stats.hw_desc,
                    OF_DESC_STR_LEN);

    return INDIGO_ERROR_NONE;
}

indigo_error_t
ind_core_dp_desc_set(of_desc_str_t desc)
{
    if (!ind_core_init_done) {
        return INDIGO_ERROR_INIT;
    }

    INDIGO_MEM_COPY(ind_core_of_config.desc_stats.dp_desc,
                    desc, OF_DESC_STR_LEN);

    return INDIGO_ERROR_NONE;
}

indigo_error_t
ind_core_dp_desc_get(of_desc_str_t desc)
{
    if (!ind_core_init_done) {
        return INDIGO_ERROR_INIT;
    }
    if (desc == NULL) {
        return INDIGO_ERROR_PARAM;
    }

    INDIGO_MEM_COPY(desc, ind_core_of_config.desc_stats.dp_desc,
                    OF_DESC_STR_LEN);

    return INDIGO_ERROR_NONE;
}

indigo_error_t
ind_core_mfr_desc_set(of_desc_str_t desc)
{
    if (!ind_core_init_done) {
        return INDIGO_ERROR_INIT;
    }

    INDIGO_MEM_COPY(ind_core_of_config.desc_stats.mfr_desc,
                    desc, OF_DESC_STR_LEN);

    return INDIGO_ERROR_NONE;
}

indigo_error_t
ind_core_mfr_desc_get(of_desc_str_t desc)
{
    if (!ind_core_init_done) {
        return INDIGO_ERROR_INIT;
    }
    if (desc == NULL) {
        return INDIGO_ERROR_PARAM;
    }

    INDIGO_MEM_COPY(desc, ind_core_of_config.desc_stats.mfr_desc,
                    OF_DESC_STR_LEN);

    return INDIGO_ERROR_NONE;
}

indigo_error_t
ind_core_serial_num_set(of_serial_num_t serial_num)
{
    if (!ind_core_init_done) {
        return INDIGO_ERROR_INIT;
    }

    INDIGO_MEM_COPY(ind_core_of_config.desc_stats.serial_num,
                    serial_num, OF_SERIAL_NUM_LEN);

    return INDIGO_ERROR_NONE;
}

indigo_error_t
ind_core_serial_num_get(of_serial_num_t serial_num)
{
    if (!ind_core_init_done) {
        return INDIGO_ERROR_INIT;
    }
    if (serial_num == NULL) {
        return INDIGO_ERROR_PARAM;
    }

    INDIGO_MEM_COPY(serial_num, ind_core_of_config.desc_stats.serial_num,
                    OF_SERIAL_NUM_LEN);

    return INDIGO_ERROR_NONE;
}


/**
 * Set/get the disconnected mode
 */
indigo_error_t
indigo_core_disconnected_mode_set(indigo_core_disconnected_mode_t mode)
{
    if (!ind_core_init_done) {
        return INDIGO_ERROR_INIT;
    }

    switch (mode) {
    case INDIGO_CORE_DISCONNECTED_MODE_STICKY:
    case INDIGO_CORE_DISCONNECTED_MODE_CLOSED:
        break;
    default:
        LOG_ERROR("Bad disconnect mode set; %d", mode);
        return INDIGO_ERROR_PARAM;
    }

    if (mode == ind_core_config.disconnected_mode) {
        return INDIGO_ERROR_NONE;
    }

    /* @FIXME: If mode change and this would affect current state, update */
    LOG_TRACE("Setting disconnect mode to %d", mode);
    ind_core_config.disconnected_mode = mode;

    return INDIGO_ERROR_NONE;
}

indigo_error_t
indigo_core_disconnected_mode_get(indigo_core_disconnected_mode_t *mode)
{
    if (!ind_core_init_done) {
        return INDIGO_ERROR_INIT;
    }

    if (mode == NULL) {
        return INDIGO_ERROR_PARAM;
    }

    *mode = ind_core_config.disconnected_mode;

    return INDIGO_ERROR_NONE;
}


/**
 * Notify state manager of a change in remote connection count
 */
void
indigo_core_connection_count_notify(int new_count)
{
    if (!ind_core_init_done) {
        return;
    }

    ind_core_connection_count = new_count;

    if (new_count == 0) {
        if (ind_core_config.disconnected_mode ==
                INDIGO_CORE_DISCONNECTED_MODE_STICKY) {
            /* Notify forwarding of change in behavior */
            indigo_fwd_expiration_enable_set(0);
        }
    } else {
        indigo_fwd_expiration_enable_set(1);
    }
}


void
indigo_core_port_status_update(of_port_status_t *of_port_status)
{
    int rv;

    /*
     * Special case: We allow this call to pass thru even if not enabled.
     */

    LOG_TRACE("OF state mgr port status update");

    rv = indigo_cxn_send_controller_message(INDIGO_CXN_ID_UNSPECIFIED,
                                            of_port_status);

    /* Don't log error if controller is not connected */
    if (rv != INDIGO_ERROR_NONE && rv != INDIGO_ERROR_NOT_READY) {
        LOG_ERROR("Error sending port status message to controller");
    }
}


/**
 * Send an error message to a controller
 * @param version The version to use for the msg
 * @param cxn_id Controller to receive msg
 * @param xid The transaction ID to use for the message
 * @param type Type of error message
 * @param code Code of error message for this type
 * @param bad_obj If not NULL, convert to octets and use for data
 * @param octets If not NULL use this for the data
 *
 * Note that bad_obj has precendence over octets; if bad_obj is not NULL
 * then octets is ignored.
 *
 */

int
ind_core_send_error_msg(of_version_t version, indigo_cxn_id_t cxn_id,
                        uint32_t xid, uint16_t type, uint16_t code,
                        of_object_t *bad_obj, of_octets_t *octets)
{
    of_octets_t obj_octets;

    if (!ind_core_module_enabled) {
        return INDIGO_ERROR_INIT;
    }

    if (bad_obj != NULL) {
        obj_octets.data = OF_OBJECT_BUFFER_INDEX(bad_obj, 0);
        obj_octets.bytes = bad_obj->length;
        octets = &obj_octets;
    }

    return indigo_cxn_send_error_msg(version, cxn_id, xid, type, code, octets);
}


/**
 * Expiration processing stats callback op
 *
 * This routine is called after the expiration process calls stats get.
 * The resulting stats are used to check if the entry
 * indigo_core_flow_stats_get_callback handler for flow expiration.
 *
 * If module is disabled, we still process the call.  If the module
 * is not initialized, ignore the call.
 */
static void
flow_expiration_timer_cb(struct ind_core_flow_stats_state *state,
                         indigo_fi_flow_stats_t *flow_stats)
{
    uint32_t delta;
    indigo_time_t current_time;
    ft_entry_t *entry;

    if ((flow_stats == NULL) || !ind_core_init_done) {
        return;
    }

    /* @fixme Too bad we have to lookup here */
    entry = ft_lookup(ind_core_ft, flow_stats->flow_id);
    if (entry == NULL) {
        LOG_ERROR("failed to lookup flow during flow expiration callback");
        return;
    }

    current_time = INDIGO_CURRENT_TIME;

    if (entry->packets != flow_stats->packets) {
        entry->packets = flow_stats->packets;
        entry->last_counter_change = current_time;
    }
    if (entry->bytes != flow_stats->bytes) {
        entry->bytes = flow_stats->bytes;
        entry->last_counter_change = current_time;
    }

    /* Mark entry if expired */

    delta = INDIGO_TIME_DIFF_ms(entry->last_counter_change,
                                current_time) / 1000;
    if ((entry->idle_timeout > 0) && (delta >= entry->idle_timeout)) {
        LOG_TRACE("Marking idle TO (%d): " INDIGO_FLOW_ID_PRINTF_FORMAT,
                  entry->idle_timeout, INDIGO_FLOW_ID_PRINTF_ARG(entry->id));
        ind_core_flow_entry_delete(entry, INDIGO_FLOW_REMOVED_IDLE_TIMEOUT);
    }
}

/**
 * Timer operation to expire flows.
 *
 * Calls indigo_fwd_flow_stats_get for each flow in the table. The expiration
 * is done in flow_expiration_timer_cb when the reply is received.
 *
 * Ignore this call if the module is not enabled.
 */
static void
flow_expiration_timer(void *cookie)
{
    struct ind_core_flow_stats_state *state;
    uint32_t delta;
    indigo_time_t current_time;
    ft_entry_t *entry;
    list_links_t *cur, *next;
    int deleted = 0;

    if (!ind_core_module_enabled) {
        return;
    }

    state = INDIGO_MEM_ALLOC(sizeof(*state));
    if (state == NULL) {
       LOG_ERROR("Failed to allocate flow stats state object.");
       return;
    }

    state->finished_calls = 0;
    state->expected_count = 0;
    state->received_count = 0;
    state->callback = flow_expiration_timer_cb;

    FT_ITER(ind_core_ft, entry, cur, next) {
        if (!FT_FLOW_STATE_IS_DELETED(entry->state)) {
            if (entry->hard_timeout > 0) {
                current_time = INDIGO_CURRENT_TIME;
                delta = INDIGO_TIME_DIFF_ms(entry->insert_time,
                                            current_time) / 1000;
                if (delta >= entry->hard_timeout) {
                    LOG_TRACE("Hard TO (%d): " INDIGO_FLOW_ID_PRINTF_FORMAT,
                              entry->hard_timeout,
                              INDIGO_FLOW_ID_PRINTF_ARG(entry->id));
                    ind_core_flow_entry_delete(entry,
                                              INDIGO_FLOW_REMOVED_HARD_TIMEOUT);
                    deleted = 1;
                }
            }

            /* @fixme Add support for getting stats locally */
            /* May have been marked deleted by above, so check again */
            if (!deleted && !FT_FLOW_STATE_IS_DELETED(entry->state) &&
                    entry->idle_timeout > 0) {
                /* Get stats; check for timeout in callback */
                state->expected_count++;
                indigo_fwd_flow_stats_get(entry->id,
                                          INDIGO_POINTER_TO_COOKIE(state));
            }
        }
    }

    indigo_core_flow_stats_get_callback(INDIGO_ERROR_NONE, NULL,
                                        INDIGO_POINTER_TO_COOKIE(state));
}

void
ind_core_ft_dump(aim_pvs_t* pvs)
{
    ft_entry_t *entry;
    list_links_t *cur, *next;

    FT_ITER(ind_core_ft, entry, cur, next) {
        aim_printf(pvs, "Flow %d:\n", entry->id);
        loci_dump_match((loci_writer_f)aim_printf, pvs, &entry->match);
        aim_printf(pvs, "cookie: 0x%016"PRIx64"\n", entry->cookie);
        aim_printf(pvs, "idle_timeout: %hu\n", entry->idle_timeout);
        aim_printf(pvs, "hard_timeout: %hu\n", entry->hard_timeout);
        aim_printf(pvs, "priority: %hu\n", entry->priority);
        aim_printf(pvs, "flags: %hu\n", entry->flags);
        aim_printf(pvs, "table_id: %hhu\n", entry->table_id);
        aim_printf(pvs, "packets: %"PRIu64"\n", entry->packets);
        aim_printf(pvs, "bytes: %"PRIu64"\n", entry->bytes);

        {
            int rv;
            of_action_t elt;
            OF_LIST_ACTION_ITER(entry->effects.actions, &elt, rv) {
                of_object_dump((loci_writer_f)aim_printf, pvs, &elt.header);
            }
        }

        aim_printf(pvs, "\n");
    }
}

void
ind_core_ft_show(aim_pvs_t* pvs)
{
    ft_entry_t *entry;
    list_links_t *cur, *next;

    FT_ITER(ind_core_ft, entry, cur, next) {
        aim_printf(pvs, "Flow %d: ", entry->id);
        loci_show_match((loci_writer_f)aim_printf, pvs, &entry->match);
        aim_printf(pvs, "cookie=0x%016"PRIx64" ", entry->cookie);
        aim_printf(pvs, "priority=%hu ", entry->priority);
        aim_printf(pvs, "table_id=%hhu ", entry->table_id);

        {
            int rv;
            of_action_t elt;
            OF_LIST_ACTION_ITER(entry->effects.actions, &elt, rv) {
                aim_printf(pvs, "%s(", of_object_id_str[elt.header.object_id]);
                of_object_show((loci_writer_f)aim_printf, pvs, &elt.header);
                aim_printf(pvs, ") ");
            }
        }

        aim_printf(pvs, "\n");
    }
}

void
ind_core_ft_stats(aim_pvs_t *pvs)
{
    ft_instance_t ft;

    ft = ind_core_ft;
    aim_printf(pvs, "Flow table stats:\n");
    aim_printf(pvs, "  Current count:  %d\n", ft->status.current_count);
    aim_printf(pvs, "  Pending del:    %d\n", ft->status.pending_deletes);
    aim_printf(pvs, "  Adds:           %d\n", (int)ft->status.adds);
    aim_printf(pvs, "  Deletes:        %d\n", (int)ft->status.deletes);
    aim_printf(pvs, "  Hard Exp:       %d\n", (int)ft->status.hard_expires);
    aim_printf(pvs, "  Idle Exp:       %d\n", (int)ft->status.idle_expires);
    aim_printf(pvs, "  Updates:        %d\n", (int)ft->status.updates);
    aim_printf(pvs, "  Full Errors:    %d\n",
               (int)ft->status.table_full_errors);
    aim_printf(pvs, "  Fwd Add Errors: %d\n",
               (int)ft->status.forwarding_add_errors);
}
