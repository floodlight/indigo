/****************************************************************
 *
 *        Copyright 2014,2017 Big Switch Networks, Inc.
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
 * @brief OpenFlow message handlers for BSN debug counter messages
 */

#include "ofstatemanager_log.h"

#include <OFStateManager/ofstatemanager_config.h>
#include <indigo/indigo.h>
#include <loci/loci.h>
#include <debug_counter/debug_counter.h>
#include "handlers.h"
#include "ofstatemanager_decs.h"

void
ind_core_bsn_debug_counter_desc_stats_request_handler(of_object_t *_obj,
                                                      indigo_cxn_id_t cxn_id)
{
    of_bsn_debug_counter_desc_stats_request_t *obj = _obj;
    of_bsn_debug_counter_desc_stats_reply_t *reply;
    of_list_bsn_debug_counter_desc_stats_entry_t entries;
    of_bsn_debug_counter_desc_stats_entry_t *entry;
    uint32_t xid;
    of_str64_t name;
    of_desc_str_t description;
    list_links_t *cur;

    reply = of_bsn_debug_counter_desc_stats_reply_new(obj->version);
    AIM_TRUE_OR_DIE(reply != NULL);

    of_bsn_debug_counter_desc_stats_request_xid_get(obj, &xid);
    of_bsn_debug_counter_desc_stats_reply_xid_set(reply, xid);
    of_bsn_debug_counter_desc_stats_reply_entries_bind(reply, &entries);

    entry = of_bsn_debug_counter_desc_stats_entry_new(entries.version);
    AIM_TRUE_OR_DIE(entry != NULL);

    list_head_t *counters = debug_counter_list();
    LIST_FOREACH(counters, cur) {
        debug_counter_t *counter = container_of(cur, links, debug_counter_t);

        if (debug_counter_get(counter) == 0) {
            continue;
        }

        of_bsn_debug_counter_desc_stats_entry_counter_id_set(entry, counter->counter_id);

        memset(name, 0, sizeof(name));
        strncpy(name, counter->name, sizeof(name)-1);
        of_bsn_debug_counter_desc_stats_entry_name_set(entry, name);

        memset(description, 0, sizeof(description));
        strncpy(description, counter->description, sizeof(description)-1);
        of_bsn_debug_counter_desc_stats_entry_description_set(entry, description);

        if (of_list_append(&entries, entry) < 0) {
            /* This entry didn't fit, send out the current message and
                * allocate a new one. */
            of_bsn_debug_counter_desc_stats_reply_flags_set(
                reply, OF_STATS_REPLY_FLAG_REPLY_MORE);
            indigo_cxn_send_controller_message(cxn_id, reply);

            reply = of_bsn_debug_counter_desc_stats_reply_new(obj->version);
            AIM_TRUE_OR_DIE(reply != NULL);

            of_bsn_debug_counter_desc_stats_reply_xid_set(reply, xid);
            of_bsn_debug_counter_desc_stats_reply_entries_bind(reply, &entries);

            if (of_list_append(&entries, entry) < 0) {
                AIM_DIE("unexpected failure appending single bsn_debug_counter_desc stats entry");
            }
        }
    }

    of_object_delete(entry);

    indigo_cxn_send_controller_message(cxn_id, reply);
}

void
ind_core_bsn_debug_counter_stats_request_handler(of_object_t *_obj,
                                                 indigo_cxn_id_t cxn_id)
{
    of_bsn_debug_counter_stats_request_t *obj = _obj;
    of_bsn_debug_counter_stats_reply_t *reply;
    of_list_bsn_debug_counter_stats_entry_t entries;
    of_bsn_debug_counter_stats_entry_t *entry;
    uint32_t xid;
    list_links_t *cur;

    reply = of_bsn_debug_counter_stats_reply_new(obj->version);
    AIM_TRUE_OR_DIE(reply != NULL);

    of_bsn_debug_counter_stats_request_xid_get(obj, &xid);
    of_bsn_debug_counter_stats_reply_xid_set(reply, xid);
    of_bsn_debug_counter_stats_reply_entries_bind(reply, &entries);

    entry = of_bsn_debug_counter_stats_entry_new(entries.version);
    AIM_TRUE_OR_DIE(entry != NULL);

    list_head_t *counters = debug_counter_list();
    LIST_FOREACH(counters, cur) {
        debug_counter_t *counter = container_of(cur, links, debug_counter_t);

        if (debug_counter_get(counter) == 0) {
            continue;
        }

        of_bsn_debug_counter_stats_entry_counter_id_set(entry, counter->counter_id);
        of_bsn_debug_counter_stats_entry_value_set(entry, debug_counter_get(counter));

        if (of_list_append(&entries, entry) < 0) {
            /* This entry didn't fit, send out the current message and
                * allocate a new one. */
            of_bsn_debug_counter_stats_reply_flags_set(
                reply, OF_STATS_REPLY_FLAG_REPLY_MORE);
            indigo_cxn_send_controller_message(cxn_id, reply);

            reply = of_bsn_debug_counter_stats_reply_new(obj->version);
            AIM_TRUE_OR_DIE(reply != NULL);

            of_bsn_debug_counter_stats_reply_xid_set(reply, xid);
            of_bsn_debug_counter_stats_reply_entries_bind(reply, &entries);

            if (of_list_append(&entries, entry) < 0) {
                AIM_DIE("unexpected failure appending single bsn_debug_counter stats entry");
            }
        }
    }

    of_object_delete(entry);

    indigo_cxn_send_controller_message(cxn_id, reply);
}
