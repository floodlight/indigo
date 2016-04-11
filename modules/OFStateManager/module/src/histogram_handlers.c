/****************************************************************
 *
 *        Copyright 2016, Big Switch Networks, Inc.
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

/*
 * Histogram generic stats handler
 *
 * The "histogram" generic stats request is used to get the contents of
 * a single histogram. Pass the name of the histogram in a name TLV.
 * The reply uses a single uint64_list TLV, which contains the first key
 * and count for each nonzero bucket.
 *
 * The "histograms" generic stats request returns an entry per histogram
 * with a single name TLV.
 */

#include "ofstatemanager_log.h"

#include <OFStateManager/ofstatemanager_config.h>
#include <indigo/indigo.h>
#include <loci/loci.h>
#include <histogram/histogram.h>
#include "ofstatemanager_decs.h"

static void handle_histogram_request(indigo_cxn_id_t cxn_id, of_bsn_generic_stats_request_t *req, void *priv);
static void handle_histograms_request(indigo_cxn_id_t cxn_id, of_bsn_generic_stats_request_t *req, void *priv);
static struct histogram *test_histogram;

void
ind_core_histogram_handlers_init(void)
{
    indigo_core_generic_stats_register("histogram", handle_histogram_request, NULL);
    indigo_core_generic_stats_register("histograms", handle_histograms_request, NULL);

    /* Simple histogram for testing OpenFlow messaging */
    test_histogram = histogram_create("test");
    int i;
    for (i = 0; i < 256; i++) {
        histogram_inc(test_histogram, i);
    }
}

static void
handle_histogram_request(
    indigo_cxn_id_t cxn_id,
    of_bsn_generic_stats_request_t *req,
    void *priv)
{
    uint32_t xid;
    of_bsn_generic_stats_request_xid_get(req, &xid);

    of_object_t tlvs;
    of_bsn_generic_stats_request_tlvs_bind(req, &tlvs);

    of_object_t tlv;
    if (of_list_bsn_tlv_first(&tlvs, &tlv) < 0) {
        indigo_cxn_send_bsn_error(cxn_id, req, "Expected name TLV, found empty list");
        return;
    }

    if (tlv.object_id != OF_BSN_TLV_NAME) {
        char err[128];
        snprintf(err, sizeof(err), "Expected name TLV, found %s", of_class_name(&tlv));
        indigo_cxn_send_bsn_error(cxn_id, req, err);
        return;
    }

    of_octets_t name_octets;
    of_bsn_tlv_name_value_get(&tlv, &name_octets);

    if (of_list_bsn_tlv_next(&tlvs, &tlv) == 0) {
        char err[128];
        snprintf(err, sizeof(err), "Expected end of TLV list, found %s", of_class_name(&tlv));
        indigo_cxn_send_bsn_error(cxn_id, req, err);
        return;
    }

    /* Copy octets to a null-terminated string */
    char name[128];
    snprintf(name, sizeof(name), "%.*s", name_octets.bytes, name_octets.data);

    struct histogram *hist = histogram_find(name);
    if (hist == NULL) {
        indigo_cxn_send_bsn_error(cxn_id, req, "Histogram not found");
        return;
    }

    of_object_t *reply = of_bsn_generic_stats_reply_new(req->version);
    if (reply == NULL) {
        return;
    }

    of_bsn_generic_stats_reply_xid_set(reply, xid);

    of_object_t entries;
    of_bsn_generic_stats_reply_entries_bind(reply, &entries);

    of_object_t entry;
    of_bsn_generic_stats_entry_init(&entry, entries.version, -1, 1);
    of_list_bsn_generic_stats_entry_append_bind(&entries, &entry);

    of_bsn_generic_stats_entry_tlvs_bind(&entry, &tlvs);

    of_bsn_tlv_uint64_list_init(&tlv, tlvs.version, -1, 1);
    of_list_bsn_tlv_append_bind(&tlvs, &tlv);

    of_list_uint64_t uint64s;
    of_bsn_tlv_uint64_list_value_bind(&tlv, &uint64s);

    int i;
    for (i = 0; i < HISTOGRAM_BUCKETS; i++) {
        uint64_t v = hist->counts[i];
        if (v == 0) {
            continue;
        }

        uint32_t k = histogram_key(i);

        of_uint64_t elem;
        of_uint64_init(&elem, uint64s.version, -1, 1);

        of_list_uint64_append_bind(&uint64s, &elem);
        of_uint64_value_set(&elem, k);

        of_list_uint64_append_bind(&uint64s, &elem);
        of_uint64_value_set(&elem, v);
    }

    indigo_cxn_send_controller_message(cxn_id, reply);
}

static void
handle_histograms_request(
    indigo_cxn_id_t cxn_id,
    of_bsn_generic_stats_request_t *req,
    void *priv)
{
    uint32_t xid;
    of_bsn_generic_stats_request_xid_get(req, &xid);

    of_object_t *reply = of_bsn_generic_stats_reply_new(req->version);
    if (reply == NULL) {
        AIM_LOG_ERROR("Failed to allocate bsn_generic_stats_reply");
        return;
    }

    of_bsn_generic_stats_reply_xid_set(reply, xid);

    of_object_t entries;
    of_bsn_generic_stats_reply_entries_bind(reply, &entries);

    of_object_t *entry = of_bsn_generic_stats_entry_new(entries.version);
    if (entry == NULL) {
        AIM_LOG_ERROR("Failed to allocate bsn_generic_stats_entry");
        of_object_delete(reply);
        return;
    }

    struct list_links *cur;
    struct list_head *head = histogram_list();
    LIST_FOREACH(head, cur) {
        struct histogram *hist = container_of(cur, links, struct histogram);

        of_object_t tlvs;
        of_bsn_generic_stats_entry_tlvs_bind(entry, &tlvs);

        of_object_t tlv;
        of_bsn_tlv_name_init(&tlv, tlvs.version, -1, 1);
        of_list_bsn_tlv_append_bind(&tlvs, &tlv);

        of_octets_t octets = { .data=(uint8_t *)hist->name, .bytes=strlen(hist->name) };
        if (of_bsn_tlv_name_value_set(&tlv, &octets) < 0) {
            AIM_LOG_ERROR("Unexpectedly failed to set name TLV value");
            break;
        }

        if (of_list_bsn_generic_stats_entry_append(&entries, entry) < 0) {
            /* Current message full, send it and start another */
            of_bsn_generic_stats_reply_flags_set(reply, OF_STATS_REPLY_FLAG_REPLY_MORE);
            indigo_cxn_send_controller_message(cxn_id, reply);

            reply = of_bsn_generic_stats_reply_new(req->version);
            if (reply == NULL) {
                AIM_LOG_ERROR("Failed to allocate bsn_generic_stats_reply");
                break;
            }

            of_bsn_generic_stats_reply_xid_set(reply, xid);

            of_bsn_generic_stats_reply_entries_bind(reply, &entries);
            if (of_list_bsn_generic_stats_entry_append(&entries, entry) < 0) {
                AIM_LOG_ERROR("Unexpectedly failed to add stats entry to empty message");
                break;
            }
        }

        of_object_truncate(entry);
    }

    of_object_delete(entry);

    if (reply) {
        indigo_cxn_send_controller_message(cxn_id, reply);
    }
}
