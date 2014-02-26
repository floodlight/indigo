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
 * @brief OpenFlow message handlers for BSN port/VLAN stats messages
 */

#include "ofstatemanager_log.h"

#include <OFStateManager/ofstatemanager_config.h>
#include <indigo/indigo.h>
#include <indigo/forwarding.h>
#include <indigo/port_manager.h>
#include <loci/loci.h>
#include "handlers.h"

/* TODO move into LOXI */
#define OF_BSN_VLAN_ALL 0xffff

static void
append_uint64(of_list_uint64_t *list, uint64_t value)
{
    of_uint64_t elem;
    of_uint64_init(&elem, OF_VERSION_1_3, -1, 1);
    of_list_uint64_append_bind(list, &elem);
    of_uint64_value_set(&elem, value);
}

/*
 * Truncate the object to its initial length.
 *
 * This is called by the stats handlers to reuse a single allocated entry.
 */
static void
truncate_of_object(of_object_t *obj)
{
    of_object_init_map[obj->object_id](obj, obj->version, -1, 0);
    obj->wire_object.wbuf->current_bytes = obj->length;
}

static void
ind_core_bsn_vlan_counter_stats_entry_populate(of_bsn_vlan_counter_stats_entry_t *entry,
                                               uint16_t vlan_vid)
{
    indigo_fi_vlan_stats_t stats;
    of_list_uint64_t values;

    /* Default to "counter not supported" */
    memset(&stats, 0xff, sizeof(stats));

    indigo_fwd_vlan_stats_get(vlan_vid, &stats);

    of_bsn_vlan_counter_stats_entry_vlan_vid_set(entry, vlan_vid);
    of_bsn_vlan_counter_stats_entry_values_bind(entry, &values);

    append_uint64(&values, stats.rx_bytes);
    append_uint64(&values, stats.rx_packets);
    append_uint64(&values, stats.tx_bytes);
    append_uint64(&values, stats.tx_packets);
}

void
ind_core_bsn_vlan_counter_stats_request_handler(of_object_t *_obj,
                                                indigo_cxn_id_t cxn_id)
{
    of_bsn_vlan_counter_stats_request_t *obj = _obj;
    of_bsn_vlan_counter_stats_reply_t *reply;
    of_list_bsn_vlan_counter_stats_entry_t entries;
    of_bsn_vlan_counter_stats_entry_t *entry;
    uint32_t xid;
    uint16_t vlan_vid;

    of_bsn_vlan_counter_stats_request_vlan_vid_get(obj, &vlan_vid);

    if ((vlan_vid == 0 || vlan_vid > 4095) && (vlan_vid != OF_BSN_VLAN_ALL)) {
        AIM_LOG_WARN("Invalid VLAN %u", vlan_vid);
        indigo_cxn_send_error_reply(cxn_id, obj,
                                    OF_ERROR_TYPE_BAD_REQUEST,
                                    OF_REQUEST_FAILED_EPERM);
        return;
    }

    reply = of_bsn_vlan_counter_stats_reply_new(obj->version);
    AIM_TRUE_OR_DIE(reply != NULL);

    of_bsn_vlan_counter_stats_request_xid_get(obj, &xid);
    of_bsn_vlan_counter_stats_reply_xid_set(reply, xid);
    of_bsn_vlan_counter_stats_reply_entries_bind(reply, &entries);

    entry = of_bsn_vlan_counter_stats_entry_new(entries.version);
    AIM_TRUE_OR_DIE(entry != NULL);

    if (vlan_vid == OF_BSN_VLAN_ALL) {
        for (vlan_vid = 1; vlan_vid < 4096; vlan_vid++) {
            ind_core_bsn_vlan_counter_stats_entry_populate(entry, vlan_vid);

            if (of_list_append(&entries, entry) < 0) {
                /* This entry didn't fit, send out the current message and
                 * allocate a new one. */
                of_bsn_vlan_counter_stats_reply_flags_set(
                    reply, OF_STATS_REPLY_FLAG_REPLY_MORE);
                indigo_cxn_send_controller_message(cxn_id, reply);

                reply = of_bsn_vlan_counter_stats_reply_new(obj->version);
                AIM_TRUE_OR_DIE(reply != NULL);

                of_bsn_vlan_counter_stats_reply_xid_set(reply, xid);
                of_bsn_vlan_counter_stats_reply_entries_bind(reply, &entries);

                if (of_list_append(&entries, entry) < 0) {
                    AIM_DIE("unexpected failure appending single bsn_vlan_counter stats entry");
                }
            }

            truncate_of_object(entry);
        }
    } else {
        ind_core_bsn_vlan_counter_stats_entry_populate(entry, vlan_vid);

        if (of_list_append(&entries, entry) < 0) {
            AIM_DIE("unexpected failure appending single bsn_vlan_counter stats entry");
        }
    }

    of_object_delete(entry);

    indigo_cxn_send_controller_message(cxn_id, reply);
}

static void
ind_core_bsn_port_counter_stats_entry_populate(of_bsn_port_counter_stats_entry_t *entry,
                                               of_port_no_t port_no)
{
    indigo_fi_port_stats_t stats;
    of_list_uint64_t values;

    /* Default to "counter not supported" */
    memset(&stats, 0xff, sizeof(stats));

    indigo_port_extended_stats_get(port_no, &stats);

    of_bsn_port_counter_stats_entry_port_no_set(entry, port_no);
    of_bsn_port_counter_stats_entry_values_bind(entry, &values);

    append_uint64(&values, stats.rx_bytes);
    append_uint64(&values, stats.rx_packets_unicast);
    append_uint64(&values, stats.rx_packets_broadcast);
    append_uint64(&values, stats.rx_packets_multicast);
    append_uint64(&values, stats.rx_dropped);
    append_uint64(&values, stats.rx_errors);
    append_uint64(&values, stats.tx_bytes);
    append_uint64(&values, stats.tx_packets_unicast);
    append_uint64(&values, stats.tx_packets_broadcast);
    append_uint64(&values, stats.tx_packets_multicast);
    append_uint64(&values, stats.tx_dropped);
    append_uint64(&values, stats.tx_errors);
}

void
ind_core_bsn_port_counter_stats_request_handler(of_object_t *_obj,
                                                indigo_cxn_id_t cxn_id)
{
    of_bsn_port_counter_stats_request_t *obj = _obj;
    of_bsn_port_counter_stats_reply_t *reply;
    of_list_bsn_port_counter_stats_entry_t entries;
    of_bsn_port_counter_stats_entry_t *entry;
    uint32_t xid;
    of_port_no_t port_no;

    of_bsn_port_counter_stats_request_port_no_get(obj, &port_no);

    reply = of_bsn_port_counter_stats_reply_new(obj->version);
    AIM_TRUE_OR_DIE(reply != NULL);

    of_bsn_port_counter_stats_request_xid_get(obj, &xid);
    of_bsn_port_counter_stats_reply_xid_set(reply, xid);
    of_bsn_port_counter_stats_reply_entries_bind(reply, &entries);

    entry = of_bsn_port_counter_stats_entry_new(entries.version);
    AIM_TRUE_OR_DIE(entry != NULL);

    if (port_no == OF_PORT_DEST_ALL) {
        indigo_port_info_t *port_list, *port_info;

        if (indigo_port_interface_list(&port_list) < 0) {
            of_object_delete(reply);
            of_object_delete(entry);
            indigo_cxn_send_error_reply(cxn_id, obj,
                                        OF_ERROR_TYPE_BAD_REQUEST,
                                        OF_REQUEST_FAILED_EPERM);
            return;
        }

        for (port_info = port_list; port_info; port_info = port_info->next) {
            port_no = port_info->of_port;

            ind_core_bsn_port_counter_stats_entry_populate(entry, port_no);

            if (of_list_append(&entries, entry) < 0) {
                /* This entry didn't fit, send out the current message and
                 * allocate a new one. */
                of_bsn_port_counter_stats_reply_flags_set(
                    reply, OF_STATS_REPLY_FLAG_REPLY_MORE);
                indigo_cxn_send_controller_message(cxn_id, reply);

                reply = of_bsn_port_counter_stats_reply_new(obj->version);
                AIM_TRUE_OR_DIE(reply != NULL);

                of_bsn_port_counter_stats_reply_xid_set(reply, xid);
                of_bsn_port_counter_stats_reply_entries_bind(reply, &entries);

                if (of_list_append(&entries, entry) < 0) {
                    AIM_DIE("unexpected failure appending single bsn_port_counter stats entry");
                }
            }

            truncate_of_object(entry);
        }

        indigo_port_interface_list_destroy(port_list);
    } else {
        ind_core_bsn_port_counter_stats_entry_populate(entry, port_no);

        if (of_list_append(&entries, entry) < 0) {
            AIM_DIE("unexpected failure appending single bsn_port_counter stats entry");
        }
    }

    of_object_delete(entry);

    indigo_cxn_send_controller_message(cxn_id, reply);
}
