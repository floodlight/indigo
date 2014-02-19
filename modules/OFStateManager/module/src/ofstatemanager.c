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
#include "expiration.h"
#include "listener.h"
#include "table.h"

static void
process_flow_removal(ft_entry_t *entry,
                     indigo_fi_flow_stats_t *final_stats,
                     indigo_fi_flow_removed_t reason);

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
 * @brief Statistics for debugging
 */
static uint32_t ind_core_flow_mods = 0;
static uint32_t ind_core_packet_ins = 0;
static uint32_t ind_core_packet_outs = 0;


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
    if (!ind_core_module_enabled) {
        LOG_TRACE("Packet in called when not enabled");
        of_object_delete(packet_in);
        return INDIGO_ERROR_INIT;
    }

    LOG_TRACE("Packet in rcvd");
    ind_core_packet_ins++;

    if (ind_core_packet_in_notify(packet_in) == INDIGO_CORE_LISTENER_RESULT_DROP) {
        LOG_TRACE("Listener dropped packet-in");
        of_object_delete(packet_in);
        return INDIGO_ERROR_NONE;
    }

    indigo_cxn_send_async_message(packet_in);

    return INDIGO_ERROR_NONE;
}


/****************************************************************/

/**
 * @brief Send a flow removed message for the given entry
 * @param entry The local flow table entry
 */

static void
send_flow_removed_message(ft_entry_t *entry,
                          indigo_fi_flow_removed_t reason,
                          indigo_fi_flow_stats_t *final_stats)
{
    of_flow_removed_t *msg;
    uint32_t secs;
    uint32_t nsecs;
    indigo_time_t current;
    uint64_t packets, bytes;
    of_version_t ver;

    current = INDIGO_CURRENT_TIME;

    if (indigo_cxn_get_async_version(&ver) < 0) {
        /* No controllers connected */
        return;
    }

    if ((msg = of_flow_removed_new(ver)) == NULL) {
        LOG_ERROR("Failed to allocate flow_removed message");
        return;
    }

    calc_duration(current, entry->insert_time, &secs, &nsecs);

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

    if (reason > INDIGO_FLOW_REMOVED_DELETE) {
        /* Normalize entry */
        reason = INDIGO_FLOW_REMOVED_DELETE;
    }
    of_flow_removed_reason_set(msg, reason);
    of_flow_removed_duration_sec_set(msg, secs);
    of_flow_removed_duration_nsec_set(msg, nsecs);

    if (final_stats != NULL) {
        INDIGO_ASSERT(final_stats->flow_id == entry->id);
        packets = final_stats->packets;
        bytes = final_stats->bytes;
    } else {
        packets = (uint64_t)-1;
        bytes = (uint64_t)-1;
    }
    of_flow_removed_packet_count_set(msg, packets);
    of_flow_removed_byte_count_set(msg, bytes);

    indigo_cxn_send_async_message(msg);
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

void
indigo_core_receive_controller_message(indigo_cxn_id_t cxn, of_object_t *obj)
{
    if (!ind_core_module_enabled) {
        LOG_ERROR("Not enabled");
        return;
    }

    LOG_TRACE("Received %s message from cxn %d",
              of_object_id_str[obj->object_id], cxn);

    if (ind_core_message_notify(cxn, obj) == INDIGO_CORE_LISTENER_RESULT_DROP) {
        LOG_TRACE("Listener dropped message");
        of_object_delete(obj);
        return;
    }

    /* Default handlers */
    switch (obj->object_id) {

    case OF_PACKET_OUT:
        ind_core_packet_outs++;
        ind_core_packet_out_handler(obj, cxn);
        break;

    case OF_FLOW_ADD:
        ind_core_flow_mods++;
        ind_core_flow_add_handler(obj, cxn);
        break;

    case OF_FLOW_MODIFY:
        ind_core_flow_mods++;
        ind_core_flow_modify_handler(obj, cxn);
        break;

    case OF_FLOW_MODIFY_STRICT:
        ind_core_flow_mods++;
        ind_core_flow_modify_strict_handler(obj, cxn);
        break;

    case OF_FLOW_DELETE:
        ind_core_flow_mods++;
        ind_core_flow_delete_handler(obj, cxn);
        break;

    case OF_FLOW_DELETE_STRICT:
        ind_core_flow_mods++;
        ind_core_flow_delete_strict_handler(obj, cxn);
        break;

    case OF_PORT_STATS_REQUEST:
        ind_core_port_stats_request_handler(obj, cxn);
        break;

    case OF_GET_CONFIG_REQUEST:
        ind_core_get_config_request_handler(obj, cxn);
        break;

    case OF_SET_CONFIG:
        ind_core_set_config_handler(obj, cxn);
        break;

    case OF_FLOW_STATS_REQUEST:
        ind_core_flow_stats_request_handler(obj, cxn);
        break;

    case OF_AGGREGATE_STATS_REQUEST:
        ind_core_aggregate_stats_request_handler(obj, cxn);
        break;

    case OF_TABLE_STATS_REQUEST:
        ind_core_table_stats_request_handler(obj, cxn);
        break;

    case OF_DESC_STATS_REQUEST:
        ind_core_desc_stats_request_handler(obj, cxn);
        break;

    case OF_PORT_DESC_STATS_REQUEST:
        ind_core_port_desc_stats_request_handler(obj, cxn);
        break;

    case OF_FEATURES_REQUEST:
        ind_core_features_request_handler(obj, cxn);
        break;

    case OF_EXPERIMENTER:
        ind_core_experimenter_handler(obj, cxn);
        break;

    case OF_PORT_MOD:
        ind_core_port_mod_handler(obj, cxn);
        break;

    case OF_QUEUE_GET_CONFIG_REQUEST:
        ind_core_queue_get_config_request_handler(obj, cxn);
        break;

    case OF_QUEUE_STATS_REQUEST:
        ind_core_queue_stats_request_handler(obj, cxn);
        break;

    /****************************************************************
     * Group messages
     ****************************************************************/

    case OF_GROUP_ADD:
        ind_core_group_add_handler(obj, cxn);
        break;

    case OF_GROUP_MODIFY:
        ind_core_group_modify_handler(obj, cxn);
        break;

    case OF_GROUP_DELETE:
        ind_core_group_delete_handler(obj, cxn);
        break;

    case OF_GROUP_STATS_REQUEST:
        ind_core_group_stats_request_handler(obj, cxn);
        break;

    case OF_GROUP_DESC_STATS_REQUEST:
        ind_core_group_desc_stats_request_handler(obj, cxn);
        break;

    case OF_GROUP_FEATURES_STATS_REQUEST:
        ind_core_group_features_stats_request_handler(obj, cxn);
        break;

    /****************************************************************
     * Gentable messages
     ****************************************************************/

    case OF_BSN_GENTABLE_ENTRY_ADD:
        ind_core_bsn_gentable_entry_add_handler(obj, cxn);
        break;

    case OF_BSN_GENTABLE_ENTRY_DELETE:
        ind_core_bsn_gentable_entry_delete_handler(obj, cxn);
        break;

    case OF_BSN_GENTABLE_CLEAR_REQUEST:
        ind_core_bsn_gentable_clear_request_handler(obj, cxn);
        break;

    case OF_BSN_GENTABLE_SET_BUCKETS_SIZE:
        ind_core_bsn_gentable_set_buckets_size_handler(obj, cxn);
        break;

    case OF_BSN_GENTABLE_ENTRY_STATS_REQUEST:
        ind_core_bsn_gentable_entry_stats_request_handler(obj, cxn);
        break;

    case OF_BSN_GENTABLE_ENTRY_DESC_STATS_REQUEST:
        ind_core_bsn_gentable_entry_desc_stats_request_handler(obj, cxn);
        break;

    case OF_BSN_GENTABLE_DESC_STATS_REQUEST:
        ind_core_bsn_gentable_desc_stats_request_handler(obj, cxn);
        break;

    case OF_BSN_GENTABLE_STATS_REQUEST:
        ind_core_bsn_gentable_stats_request_handler(obj, cxn);
        break;

    case OF_BSN_GENTABLE_BUCKET_STATS_REQUEST:
        ind_core_bsn_gentable_bucket_stats_request_handler(obj, cxn);
        break;

    /****************************************************************
     * Extension messages
     ****************************************************************/

    case OF_BSN_SET_IP_MASK:
        ind_core_bsn_set_ip_mask_handler(obj, cxn);
        break;

    case OF_BSN_GET_IP_MASK_REQUEST:
        ind_core_bsn_get_ip_mask_request_handler(obj, cxn);
        break;

    case OF_BSN_HYBRID_GET_REQUEST:
        ind_core_bsn_hybrid_get_request_handler(obj, cxn);
        break;

    case OF_BSN_GET_SWITCH_PIPELINE_REQUEST:
        ind_core_bsn_sw_pipeline_get_request_handler(obj, cxn);
        break;

    case OF_BSN_SET_SWITCH_PIPELINE_REQUEST:
        ind_core_bsn_sw_pipeline_set_request_handler(obj, cxn);
        break;

    case OF_BSN_SWITCH_PIPELINE_STATS_REQUEST:
        ind_core_bsn_sw_pipeline_stats_request_handler(obj, cxn);
        break;

    case OF_BSN_VLAN_COUNTER_STATS_REQUEST:
        ind_core_bsn_vlan_counter_stats_request_handler(obj, cxn);
        break;

    case OF_BSN_PORT_COUNTER_STATS_REQUEST:
        ind_core_bsn_port_counter_stats_request_handler(obj, cxn);
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
        ind_core_experimenter_handler(obj, cxn);
        break;

    /****************************************************************
     * These are not yet implemented
     ****************************************************************/
    case OF_TABLE_MOD:
    case OF_EXPERIMENTER_STATS_REQUEST:
        ind_core_unhandled_message(obj, cxn);
        break;

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
    case OF_GROUP_STATS_REPLY:
    case OF_PACKET_IN:
    case OF_PORT_STATS_REPLY:
    case OF_PORT_STATUS:
    case OF_QUEUE_GET_CONFIG_REPLY:
    case OF_QUEUE_STATS_REPLY:
    case OF_ROLE_REPLY:
    case OF_TABLE_STATS_REPLY:
        ind_core_unhandled_message(obj, cxn);
        break;

    /* These are implemented in OFConnectionManager */
    case OF_HELLO:
    case OF_ECHO_REQUEST:
    case OF_ECHO_REPLY:
    case OF_BARRIER_REQUEST:
    case OF_NICIRA_CONTROLLER_ROLE_REQUEST:
        LOG_ERROR("Expected OFConnectionManager to handle %s",
                  of_object_id_str[obj->object_id]);
        ind_core_unhandled_message(obj, cxn);
        break;

    default:
        ind_core_unhandled_message(obj, cxn);
        break;
    }
}

static of_dpid_t ind_core_dpid = OFSTATEMANAGER_CONFIG_DPID_DEFAULT;

/* Allow the DPID to be set by the configuration */
indigo_error_t
indigo_core_dpid_set(of_dpid_t dpid)
{
    if (ind_core_dpid != dpid) {
        LOG_INFO("Changing switch DPID to %016x", dpid);
        INDIGO_MEM_COPY(&ind_core_dpid, &dpid, sizeof(ind_core_dpid));
        ind_cxn_reset(IND_CXN_RESET_ALL);
    } else {
        LOG_VERBOSE("Switch DPID set called but unchanged");
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
    ft_config.strict_match_bucket_count = config->max_flowtable_entries;
    ft_config.flow_id_bucket_count = config->max_flowtable_entries;

    if ((ind_core_ft = ft_create(&ft_config)) == NULL) {
        LOG_ERROR("Unable to allocate flow table");
        return INDIGO_ERROR_RESOURCE;
    }

    ind_core_connection_count = 0;

    ind_core_group_init();

    ind_core_test_gentable_init();

    ind_core_init_done = 1;

    return INDIGO_ERROR_NONE;
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
 */

void
ind_core_flow_entry_delete(ft_entry_t *entry, indigo_fi_flow_removed_t reason)
{
    indigo_error_t rv;
    indigo_fi_flow_stats_t flow_stats = {
        .flow_id = entry->id,
        .duration_ns = 0,
        .packets = -1,
        .bytes = -1,
    };

    LOG_TRACE("Removing flow " INDIGO_FLOW_ID_PRINTF_FORMAT,
              INDIGO_FLOW_ID_PRINTF_ARG(entry->id));

    ind_core_table_t *table = ind_core_table_get(entry->table_id);
    if (table != NULL) {
        rv = table->ops->entry_delete(table->priv, entry->priv, &flow_stats);
    } else {
        rv = indigo_fwd_flow_delete(entry->id, &flow_stats);
    }

    if (rv != INDIGO_ERROR_NONE) {
        LOG_ERROR("Error deleting flow " INDIGO_FLOW_ID_PRINTF_FORMAT ": %s",
                  INDIGO_FLOW_ID_PRINTF_ARG(entry->id), indigo_strerror(rv));
        /* Ignoring failure */
    }

    process_flow_removal(entry, &flow_stats, reason);
}

/**
 * @brief Process a flow removal from the local flow table
 */

static void
process_flow_removal(ft_entry_t *entry,
                     indigo_fi_flow_stats_t *final_stats,
                     indigo_fi_flow_removed_t reason)
{
    if (entry->flags & OF_FLOW_MOD_FLAG_SEND_FLOW_REM) {
        /* See OF spec 1.0.1, section 3.5, page 6 */
        if (reason != INDIGO_FLOW_REMOVED_OVERWRITE) {
            send_flow_removed_message(entry, reason, final_stats);
        }
    }

    ft_delete(ind_core_ft, entry);

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

    /* After entry look up, this looks like ind_core_flow_entry_delete */
    entry = ft_lookup(ind_core_ft, stats->flow_id);
    if (entry == NULL) {
        LOG_TRACE("Async flow removed: did not find entry in SM table. id "
                  INDIGO_FLOW_ID_PRINTF_FORMAT,
                  INDIGO_FLOW_ID_PRINTF_ARG((indigo_cookie_t) stats->flow_id));
        return;
    }

    process_flow_removal(entry, stats, reason);
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
                ind_core_expiration_timer, NULL,
                ind_core_config.stats_check_ms, -10);
        }
        ind_core_module_enabled = 1;
    } else if (!enable && ind_core_module_enabled) {
        LOG_INFO("Disabling OF state mgr");
        if (CORE_EXPIRES_FLOWS(&ind_core_config)) {
            ind_soc_timer_event_unregister(ind_core_expiration_timer, NULL);
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

    ind_core_test_gentable_finish();

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
    /*
     * Special case: We allow this call to pass thru even if not enabled.
     */

    LOG_TRACE("OF state mgr port status update");

    if (ind_core_port_status_notify(of_port_status) == INDIGO_CORE_LISTENER_RESULT_DROP) {
        LOG_TRACE("Listener dropped port status update");
        of_object_delete(of_port_status);
        return;
    }

    indigo_cxn_send_async_message(of_port_status);
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

        if (entry->match.version == OF_VERSION_1_0) {
            int rv;
            of_action_t elt;
            OF_LIST_ACTION_ITER(entry->effects.actions, &elt, rv) {
                of_object_dump((loci_writer_f)aim_printf, pvs, &elt.header);
            }
        } else {
            int rv;
            of_instruction_t inst;
            OF_LIST_INSTRUCTION_ITER(entry->effects.instructions, &inst, rv) {
                of_object_dump((loci_writer_f)aim_printf, pvs, &inst.header);
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

        if (entry->match.version == OF_VERSION_1_0) {
            int rv;
            of_action_t elt;
            OF_LIST_ACTION_ITER(entry->effects.actions, &elt, rv) {
                aim_printf(pvs, "%s(", of_object_id_str[elt.header.object_id]);
                of_object_show((loci_writer_f)aim_printf, pvs, &elt.header);
                aim_printf(pvs, ") ");
            }
        } else {
            int rv;
            of_instruction_t inst;
            OF_LIST_INSTRUCTION_ITER(entry->effects.instructions, &inst, rv) {
                aim_printf(pvs, "%s(", of_object_id_str[inst.header.object_id]);
                of_object_show((loci_writer_f)aim_printf, pvs, &inst.header);
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


/**
 * Returns the number of current flows, flow mods, packet ins, and packet outs.
 * The last three quantities are cumulative as of the last time this function
 * was called.
 */

void
indigo_core_stats_get(uint32_t *total_flows,
                      uint32_t *flow_mods,
                      uint32_t *packet_ins,
                      uint32_t *packet_outs)
{
    *total_flows = ind_core_ft->status.current_count;
    *flow_mods = ind_core_flow_mods;
    *packet_ins = ind_core_packet_ins;
    *packet_outs = ind_core_packet_outs;

    ind_core_flow_mods = 0;
    ind_core_packet_ins = 0;
    ind_core_packet_outs = 0;
}
