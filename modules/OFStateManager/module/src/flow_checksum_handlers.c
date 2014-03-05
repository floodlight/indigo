/****************************************************************
 *
 *        Copyright 2014, Big Switch Networks, Inc.
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
 * @brief OpenFlow message handlers for BSN flow checksum messages
 */

#include "ofstatemanager_log.h"

#include <OFStateManager/ofstatemanager_config.h>
#include <indigo/indigo.h>
#include <loci/loci.h>
#include "handlers.h"
#include "ft.h"
#include "ofstatemanager_decs.h"

void
ind_core_bsn_flow_checksum_bucket_stats_request_handler(of_object_t *_obj,
                                                        indigo_cxn_id_t cxn_id)
{
    of_bsn_flow_checksum_bucket_stats_request_t *obj = _obj;
    of_bsn_flow_checksum_bucket_stats_reply_t *reply;
    of_list_bsn_flow_checksum_bucket_stats_entry_t entries;
    of_bsn_flow_checksum_bucket_stats_entry_t *entry;
    uint32_t xid;
    uint8_t table_id;
    ft_table_t *table;
    int bucket_idx;

    of_bsn_flow_checksum_bucket_stats_request_table_id_get(obj, &table_id);

    if (table_id >= FT_MAX_TABLES) {
        AIM_LOG_WARN("Invalid table ID %u", table_id);
        indigo_cxn_send_error_reply(cxn_id, obj,
                                    OF_ERROR_TYPE_BAD_REQUEST,
                                    OF_REQUEST_FAILED_EPERM);
        return;
    }

    table = &ind_core_ft->tables[table_id];

    reply = of_bsn_flow_checksum_bucket_stats_reply_new(obj->version);
    AIM_TRUE_OR_DIE(reply != NULL);

    of_bsn_flow_checksum_bucket_stats_request_xid_get(obj, &xid);
    of_bsn_flow_checksum_bucket_stats_reply_xid_set(reply, xid);
    of_bsn_flow_checksum_bucket_stats_reply_entries_bind(reply, &entries);

    entry = of_bsn_flow_checksum_bucket_stats_entry_new(entries.version);
    AIM_TRUE_OR_DIE(entry != NULL);

    for (bucket_idx = 0; bucket_idx < table->checksum_buckets_size; bucket_idx++) {
        of_bsn_flow_checksum_bucket_stats_entry_checksum_set(
            entry, table->checksum_buckets[bucket_idx]);

        if (of_list_append(&entries, entry) < 0) {
            /* This entry didn't fit, send out the current message and
                * allocate a new one. */
            of_bsn_flow_checksum_bucket_stats_reply_flags_set(
                reply, OF_STATS_REPLY_FLAG_REPLY_MORE);
            indigo_cxn_send_controller_message(cxn_id, reply);

            reply = of_bsn_flow_checksum_bucket_stats_reply_new(obj->version);
            AIM_TRUE_OR_DIE(reply != NULL);

            of_bsn_flow_checksum_bucket_stats_reply_xid_set(reply, xid);
            of_bsn_flow_checksum_bucket_stats_reply_entries_bind(reply, &entries);

            if (of_list_append(&entries, entry) < 0) {
                AIM_DIE("unexpected failure appending single bsn_flow_checksum_bucket stats entry");
            }
        }
    }

    of_object_delete(entry);

    indigo_cxn_send_controller_message(cxn_id, reply);
}

void
ind_core_bsn_table_checksum_stats_request_handler(of_object_t *_obj,
                                                        indigo_cxn_id_t cxn_id)
{
    of_bsn_table_checksum_stats_request_t *obj = _obj;
    of_bsn_table_checksum_stats_reply_t *reply;
    of_list_bsn_table_checksum_stats_entry_t entries;
    of_bsn_table_checksum_stats_entry_t *entry;
    uint32_t xid;
    uint8_t table_id;

    reply = of_bsn_table_checksum_stats_reply_new(obj->version);
    AIM_TRUE_OR_DIE(reply != NULL);

    of_bsn_table_checksum_stats_request_xid_get(obj, &xid);
    of_bsn_table_checksum_stats_reply_xid_set(reply, xid);
    of_bsn_table_checksum_stats_reply_entries_bind(reply, &entries);

    entry = of_bsn_table_checksum_stats_entry_new(entries.version);
    AIM_TRUE_OR_DIE(entry != NULL);

    for (table_id = 0; table_id < FT_MAX_TABLES; table_id++) {
        ft_table_t *table = &ind_core_ft->tables[table_id];
        of_bsn_table_checksum_stats_entry_checksum_set(entry, table->checksum);

        if (of_list_append(&entries, entry) < 0) {
            /* This entry didn't fit, send out the current message and
                * allocate a new one. */
            of_bsn_table_checksum_stats_reply_flags_set(
                reply, OF_STATS_REPLY_FLAG_REPLY_MORE);
            indigo_cxn_send_controller_message(cxn_id, reply);

            reply = of_bsn_table_checksum_stats_reply_new(obj->version);
            AIM_TRUE_OR_DIE(reply != NULL);

            of_bsn_table_checksum_stats_reply_xid_set(reply, xid);
            of_bsn_table_checksum_stats_reply_entries_bind(reply, &entries);

            if (of_list_append(&entries, entry) < 0) {
                AIM_DIE("unexpected failure appending single bsn_table_checksum stats entry");
            }
        }
    }

    of_object_delete(entry);

    indigo_cxn_send_controller_message(cxn_id, reply);
}
