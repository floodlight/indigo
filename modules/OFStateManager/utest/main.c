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

/******************************************************************************
 *
 *  /utest/main.c
 *
 *  OFStateManager Unit Testing
 *
 *****************************************************************************/
#define AIM_LOG_MODULE_NAME ofstatemanager_utest
#include <AIM/aim_log.h>

#include <OFStateManager/ofstatemanager.h>
#include <OFStateManager/ofstatemanager_config.h>
#include <indigo/of_connection_manager.h>
#include <indigo/of_state_manager.h>
#include <indigo/forwarding.h>
#include <indigo/port_manager.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <ft.h>

#include <loci/loci.h>
#include <locitest/unittest.h>
#include <locitest/test_common.h>

#include "ofstatemanager_decs.h"

/* Defined in gentable_test.c */
int test_gentable(void);

/* Defined in table_test.c */
int test_table(void);

/* Must be an even number */
#define TEST_FLOW_COUNT 1000

#define OK(op)  INDIGO_ASSERT((op) == INDIGO_ERROR_NONE)

/**
 * Try an operation and return the error code on failure.
 */
#define TRY(op) do {                                                    \
        int _rv;                                                        \
        AIM_LOG_TRACE("%s", #op);                                       \
        if ((_rv = (op)) < 0) {                                         \
            AIM_LOG_ERROR("%s: ERROR %d at %s:%d",                      \
                          #op, _rv, __FILE__, __LINE__);                \
            return _rv;                                                 \
        }                                                               \
    } while (0)

/****************************************************************
 * These are taken from utest in OFConnection Manager
 ****************************************************************/

/****************************************************************/

#define TEST_ENT_ID 17
#define TEST_ETH_TYPE(idx) ((idx) + 1)
#define TEST_KEY(idx) (2 * ((idx) + 1))

/*
 * Track messages in flight like OFConnectionManager does, for barriers
 */
static int outstanding_op_cnt;
static void message_deleted(of_object_t *obj);

/****************************************************************
 * Stubs
 ****************************************************************/
indigo_error_t
indigo_fwd_flow_modify(indigo_cookie_t flow_id,
                       of_flow_modify_t *flow_modify)
{
    AIM_LOG_VERBOSE("flow modify called\n");
    return INDIGO_ERROR_NONE;
}

indigo_error_t create_error = INDIGO_ERROR_NONE;

#define CHECK_FLOW_COUNT(status, count) \
   if (create_error == INDIGO_ERROR_NONE) \
       TEST_ASSERT((status)->current_count == (count))

indigo_error_t
indigo_fwd_flow_create(indigo_cookie_t flow_id,
                       of_flow_add_t *flow_add,
                       uint8_t *table_id)
{
    AIM_LOG_VERBOSE("flow create called\n");
    *table_id = 0;
    return INDIGO_ERROR_NONE;
}


indigo_error_t
indigo_fwd_table_stats_get(of_table_stats_request_t *request,
                           of_table_stats_reply_t **reply)
{
    AIM_LOG_VERBOSE("table stats get called\n");
    *reply = of_table_stats_reply_new(request->version);
    return INDIGO_ERROR_NONE;
}

indigo_error_t delete_error = INDIGO_ERROR_NONE;

indigo_error_t
indigo_fwd_flow_delete(indigo_cookie_t flow_id,
                       indigo_fi_flow_stats_t *flow_stats)
{
    AIM_LOG_VERBOSE("flow delete called\n");
    memset(flow_stats, 0, sizeof(*flow_stats));
    return INDIGO_ERROR_NONE;
}

indigo_error_t indigo_fwd_flow_stats_get(
    indigo_cookie_t flow_id,
    indigo_fi_flow_stats_t *flow_stats)
{
    AIM_LOG_VERBOSE("flow stats get called\n");
    memset(flow_stats, 0, sizeof(*flow_stats));
    return INDIGO_ERROR_NONE;
}

indigo_error_t
indigo_fwd_flow_hit_status_get(indigo_cookie_t flow_id,
                               bool *is_hit)
{
    AIM_LOG_VERBOSE("flow hit status get called\n");
    *is_hit = 0;
    return INDIGO_ERROR_NONE;
}

indigo_error_t
indigo_fwd_packet_out(of_packet_out_t *of_packet_out)
{
    AIM_LOG_VERBOSE("packet out called\n");
    return INDIGO_ERROR_NONE;
}

indigo_error_t
indigo_port_features_get(of_features_reply_t *features)
{
    AIM_LOG_VERBOSE("port features get called\n");
    return INDIGO_ERROR_NONE;
}

indigo_error_t
indigo_fwd_forwarding_features_get(of_features_reply_t *features)
{
    AIM_LOG_VERBOSE("forwarding features get called\n");
    return INDIGO_ERROR_NONE;
}


void
ind_cxn_reset(indigo_cxn_id_t cxn_id)
{
    AIM_LOG_VERBOSE("cxn reset called %d", cxn_id);
    return;
}

void
indigo_cxn_send_error_reply(indigo_cxn_id_t cxn_id, of_object_t *orig,
                            uint16_t type, uint16_t code)
{
    AIM_LOG_VERBOSE("Send error msg called for cxn id %d\n",
                      cxn_id);
}

static int controller_message_counters[OF_MESSAGE_OBJECT_COUNT];

void
indigo_cxn_send_controller_message(indigo_cxn_id_t cxn_id, of_object_t *obj)
{
    AIM_LOG_VERBOSE("Send msg called for cxn id %d, obj type %d\n",
                      cxn_id, obj->object_id);
    controller_message_counters[obj->object_id]++;
    of_object_delete(obj);
}

static int async_message_counters[OF_MESSAGE_OBJECT_COUNT];

void
indigo_cxn_send_async_message(of_object_t *obj)
{
    AIM_LOG_VERBOSE("Send async msg called for type %s",
                    of_object_id_str[obj->object_id]);
    async_message_counters[obj->object_id]++;
    of_object_delete(obj);
}

indigo_error_t
indigo_cxn_get_async_version(of_version_t *ver)
{
    *ver = OF_VERSION_1_0;
    return INDIGO_ERROR_NONE;
}

indigo_error_t
ind_cxn_message_track_setup(indigo_cxn_id_t cxn_id, of_object_t *obj)
{
    AIM_LOG_VERBOSE("Cxn message track cxn id %d, obj type %d\n",
                         cxn_id, obj->object_id);
    assert(outstanding_op_cnt >= 0);
    outstanding_op_cnt++;
    obj->track_info.delete_cb = message_deleted;
    obj->track_info.delete_cookie = NULL;
    return INDIGO_ERROR_NONE;
}

indigo_error_t
indigo_port_modify(of_port_mod_t *port_mod)
{
    AIM_LOG_VERBOSE("port mod called\n");
    return INDIGO_ERROR_NONE;
}

indigo_error_t
indigo_port_stats_get(of_port_stats_request_t *request,
                      of_port_stats_reply_t **reply_ptr)
{
    *reply_ptr = of_port_stats_reply_new(request->version);
    return INDIGO_ERROR_NONE;
}

indigo_error_t
indigo_port_queue_config_get(of_queue_get_config_request_t *request,
                             of_queue_get_config_reply_t **reply_ptr)
{
    AIM_LOG_VERBOSE("queue config get called\n");
    *reply_ptr = of_queue_get_config_reply_new(request->version);
    return INDIGO_ERROR_NONE;
}


indigo_error_t
indigo_port_queue_stats_get(of_queue_stats_request_t *request,
                            of_queue_stats_reply_t **reply_ptr)
{

    AIM_LOG_VERBOSE("queue stats get called\n");
    *reply_ptr = of_queue_stats_reply_new(request->version);
    return INDIGO_ERROR_NONE;
}


indigo_error_t
indigo_port_experimenter(of_experimenter_t *experimenter,
                         indigo_cxn_id_t cxn_id)
{
    AIM_LOG_VERBOSE("port experimenter called\n");
    return INDIGO_ERROR_NONE;
}

indigo_error_t
indigo_fwd_experimenter(of_experimenter_t *experimenter,
                        indigo_cxn_id_t cxn_id)
{
    AIM_LOG_VERBOSE("port experimenter called\n");
    return INDIGO_ERROR_NONE;
}

indigo_error_t
indigo_port_interface_list(indigo_port_info_t **list)
{
    *list = NULL;
    return INDIGO_ERROR_NONE;
}

void
indigo_port_interface_list_destroy(indigo_port_info_t *list)
{
}

/**
 * Notify forwarding of changes in expiration processing behavior
 */
indigo_error_t indigo_fwd_expiration_enable_set(int is_enabled)
{
    AIM_LOG_VERBOSE("fwd expiration set: %d", is_enabled);
    return INDIGO_ERROR_NONE;
}

indigo_error_t indigo_fwd_expiration_enable_get(int *is_enabled)
{
    AIM_LOG_VERBOSE("fwd expiration get");
    return INDIGO_ERROR_NONE;
}

indigo_error_t indigo_port_desc_stats_get(
    of_port_desc_stats_reply_t *port_desc_stats_reply)
{
    AIM_LOG_VERBOSE("port desc stats get called");
    return INDIGO_ERROR_NONE;
}

indigo_error_t
indigo_fwd_group_add(uint32_t id, uint8_t group_type, of_list_bucket_t *buckets)
{
    return INDIGO_ERROR_NOT_SUPPORTED;
}

indigo_error_t
indigo_fwd_group_modify(uint32_t id, of_list_bucket_t *buckets)
{
    return INDIGO_ERROR_NOT_SUPPORTED;
}

void
indigo_fwd_group_delete(uint32_t id)
{
}

void
indigo_fwd_group_stats_get(uint32_t id, of_group_stats_entry_t *entry)
{
}

void
indigo_fwd_pipeline_get(of_desc_str_t pipeline)
{
    AIM_LOG_VERBOSE("fwd switch pipeline get");
    strcpy(pipeline, "some_pipeline");
}

indigo_error_t
indigo_fwd_pipeline_set(of_desc_str_t pipeline)
{
    AIM_LOG_VERBOSE("fwd switch pipeline set: %s", pipeline);
    return INDIGO_ERROR_NONE;
}

void
indigo_fwd_pipeline_stats_get(of_desc_str_t **pipeline, int *num_pipelines)
{
    AIM_LOG_VERBOSE("fwd switch pipeline stats get");
    *num_pipelines = 0;
}

static int
check_table_entry_states(ft_instance_t ft)
{
    int counted = 0;
    ft_entry_t *entry;
    list_links_t *cur, *next;

    FT_ITER(ft, entry, cur, next) {
        (void) entry;
        counted += 1;
    }

    TEST_ASSERT(counted == ft->status.current_count);

    return 0;
}

/**
 * Create count flows that differ only in the eth_type
 *
 * Insert with id every-other index.
 */

static int
populate_table(ft_instance_t ft, int count, of_match_t *match)
{
    int idx;
    of_flow_add_t *flow_add_base;
    of_flow_add_t *flow_add;
    ft_entry_t    *entry;

    flow_add_base = of_flow_add_new(OF_VERSION_1_0);
    TEST_ASSERT(of_flow_add_OF_VERSION_1_0_populate(flow_add_base, 1) != 0);
    of_flow_add_flags_set(flow_add_base, 0);
    TEST_OK(of_flow_add_match_get(flow_add_base, match));

    for (idx = 0; idx < count; ++idx) {
        TEST_ASSERT((flow_add = of_object_dup((of_object_t *)flow_add_base))
                    != NULL);
        match->fields.eth_type = TEST_ETH_TYPE(idx);
        TEST_OK(of_flow_add_match_set(flow_add, match));
        TEST_INDIGO_OK(ft_add(ft, TEST_KEY(idx), flow_add, &entry));
        of_object_delete(flow_add);
        TEST_ASSERT(check_table_entry_states(ft) == 0);
    }

    CHECK_FLOW_COUNT(&ft->status, TEST_FLOW_COUNT);
    of_flow_add_delete(flow_add_base);

    return 0;
}

/**
 * Undo above
 */
static int
depopulate_table(ft_instance_t ft)
{
    int idx;
    ft_entry_t *entry;
    int count;

    count = ft->status.current_count;
    for (idx = 0; idx < count; ++idx) {
        entry = ft_lookup(ft, TEST_KEY(idx));
        TEST_ASSERT(entry != NULL);
        TEST_ASSERT(entry->match.fields.eth_type == TEST_ETH_TYPE(idx));
        ft_delete(ft, entry);
        TEST_ASSERT(check_table_entry_states(ft) == 0);
    }

    return 0;
}

static int
check_bucket_counts(ft_instance_t ft, int expected)
{
    int count = 0;
    ft_entry_t *_entry;
    list_links_t *cur, *next;
    int idx;

    FT_ITER(ft, _entry, cur, next) {
        (void)_entry;
        count += 1;
    }
    TEST_ASSERT(count == expected);

    /* Check the buckets */
    count = 0;
    for (idx = 0; idx < ft->config.flow_id_bucket_count; idx++) {
        count += list_length(&ft->flow_id_buckets[idx]);
    }
    TEST_ASSERT(count == expected);

    count = 0;
    for (idx = 0; idx < ft->config.strict_match_bucket_count; idx++) {
        count += list_length(&ft->strict_match_buckets[idx]);
    }
    TEST_ASSERT(count == expected);

    return 0;
}

static void
message_deleted(of_object_t *obj)
{
    assert(outstanding_op_cnt > 0);
    outstanding_op_cnt--;
}

void
handle_message(of_object_t *obj)
{
    indigo_core_receive_controller_message(0, obj);
    of_object_delete(obj);
}

int
do_barrier(void)
{
    int count = 0;
    assert(outstanding_op_cnt >= 0);
    while (outstanding_op_cnt > 0) {
        LOG_VERBOSE("Waiting for barrier (outstanding_op_cnt %d)", outstanding_op_cnt);
        ind_soc_select_and_run(0);
        count++;
    }
    if (count > 0) {
        LOG_VERBOSE("Ran %d event loop iterations while waiting for barrier", count);
    }
    return 0;
}

static int
count_matching(ft_instance_t ft, of_meta_match_t *query)
{
    int count = 0;
    ft_entry_t *entry;
    list_links_t *cur, *next;

    FT_ITER(ft, entry, cur, next) {
        if (ft_entry_meta_match(query, entry)) {
            count += 1;
        }
    }

    return count;
}

static int
first_match(ft_instance_t ft, of_meta_match_t *query, ft_entry_t **result)
{
    ft_entry_t *entry;
    list_links_t *cur, *next;

    FT_ITER(ft, entry, cur, next) {
        if (ft_entry_meta_match(query, entry)) {
            *result = entry;
            return INDIGO_ERROR_NONE;
        }
    }

    return INDIGO_ERROR_NOT_FOUND;
}

static int
test_ft_hash(void)
{
    ft_instance_t ft;
    ft_config_t config = {
        1024, /* strict_match buckets */
        1024, /* flow_id buckets */
    };
    of_flow_add_t *flow_add;
    of_meta_match_t query;
    ft_entry_t *entry = NULL;
    uint16_t orig_prio;
    uint64_t orig_cookie;
    uint16_t orig_eth_type;
    int idx;
    ft_entry_t *lookup_entry;

    /* Test edge cases for create/destroy */
    ft_destroy(NULL);

    ft = ft_create(&config);
    TEST_ASSERT(ft != NULL);
    ft_destroy(ft);

    /* Create, add two entries, delete without emptying */
    ft = ft_create(&config);
    TEST_ASSERT(ft != NULL);

    flow_add = of_flow_add_new(OF_VERSION_1_0);
    TEST_ASSERT(of_flow_add_OF_VERSION_1_0_populate(flow_add, 1) != 0);
    of_flow_add_flags_set(flow_add, 0);

    TEST_INDIGO_OK(ft_add(ft, TEST_ENT_ID, flow_add, &entry));
    TEST_INDIGO_OK(ft_add(ft, TEST_ENT_ID + 1, flow_add, &entry));

    TEST_ASSERT(ft->status.current_count == 2);
    TEST_ASSERT(check_table_entry_states(ft) == 0);
    entry = ft_lookup(ft, TEST_ENT_ID);
    ft_destroy(ft);
    of_object_delete(flow_add);

    /* Test simple cases for hash table */
    ft = ft_create(&config);
    TEST_ASSERT(ft != NULL);

    /* Set up flow add structure */
    flow_add = of_flow_add_new(OF_VERSION_1_0);
    TEST_ASSERT(of_flow_add_OF_VERSION_1_0_populate(flow_add, 1) != 0);
    of_flow_add_flags_set(flow_add, 0);
    of_flow_add_priority_get(flow_add, &orig_prio);
    of_flow_add_cookie_get(flow_add, &orig_cookie);

    TEST_INDIGO_OK(ft_add(ft, TEST_ENT_ID, flow_add, &entry));
    TEST_ASSERT(ft->status.current_count == 1);
    TEST_ASSERT(check_table_entry_states(ft) == 0);
    entry = ft_lookup(ft, TEST_ENT_ID);

    /* Should not find next id */
    lookup_entry = ft_lookup(ft, TEST_ENT_ID + 1);
    TEST_ASSERT(lookup_entry == NULL);

    /* Set up the query structure */
    INDIGO_MEM_SET(&query, 0, sizeof(query));
    TEST_OK(of_flow_add_match_get(flow_add, &query.match));
    orig_eth_type = query.match.fields.eth_type;

    /* These don't change */
    query.check_priority                = 1;
    query.check_overlap                 = 1;
    query.cookie                        = orig_cookie;
    query.priority                      = orig_prio;

    /* Test success on non-strict match */
    query.out_port                      = OF_PORT_DEST_WILDCARD;
    query.mode                          = OF_MATCH_NON_STRICT;
    query.match.fields.eth_type         = orig_eth_type;
    query.match.masks.eth_type          = 0xffff;

    TEST_ASSERT(count_matching(ft, &query) == 1);
    TEST_INDIGO_OK(first_match(ft, &query, &lookup_entry));
    TEST_ASSERT(lookup_entry->id == TEST_ENT_ID);

    /* Test success on strict match */
    query.out_port                      = OF_PORT_DEST_WILDCARD;
    query.mode                          = OF_MATCH_STRICT;
    query.match.fields.eth_type         = orig_eth_type;
    query.match.masks.eth_type          = 0xffff;

    TEST_ASSERT(count_matching(ft, &query) == 1);
    TEST_INDIGO_OK(ft_strict_match(ft, &query, &lookup_entry));
    TEST_ASSERT(lookup_entry->id == TEST_ENT_ID);

    /* Test fail lookup for port, strict */
    query.out_port                      = 1;
    query.mode                          = OF_MATCH_STRICT;
    query.match.fields.eth_type         = orig_eth_type;
    query.match.masks.eth_type          = 0xffff;

    TEST_ASSERT(count_matching(ft, &query) == 0);
    TEST_ASSERT(ft_strict_match(ft, &query, &lookup_entry) ==
                INDIGO_ERROR_NOT_FOUND);

    /* Test fail lookup for strict value */
    query.out_port                      = OF_PORT_DEST_WILDCARD;
    query.mode                          = OF_MATCH_STRICT;
    query.match.fields.eth_type         = orig_eth_type + 1;
    query.match.masks.eth_type          = 0xffff;

    TEST_ASSERT(count_matching(ft, &query) == 0);
    TEST_ASSERT(ft_strict_match(ft, &query, &lookup_entry) ==
                INDIGO_ERROR_NOT_FOUND);

    /* Test fail lookup for non-strict value */
    query.out_port                      = OF_PORT_DEST_WILDCARD;
    query.mode                          = OF_MATCH_NON_STRICT;
    query.match.fields.eth_type         = orig_eth_type + 1;
    query.match.masks.eth_type          = 0xffff;

    TEST_ASSERT(count_matching(ft, &query) == 0);

    /* Test fail lookup for strict mask */
    query.out_port                      = OF_PORT_DEST_WILDCARD;
    query.mode                          = OF_MATCH_STRICT;
    query.match.fields.eth_type         = orig_eth_type;
    query.match.masks.eth_type          = 0;

    TEST_ASSERT(count_matching(ft, &query) == 0);
    TEST_ASSERT(ft_strict_match(ft, &query, &lookup_entry) ==
                INDIGO_ERROR_NOT_FOUND);

    /* Test success for non-strict with varying mask */
    query.out_port                      = OF_PORT_DEST_WILDCARD;
    query.mode                          = OF_MATCH_NON_STRICT;
    query.match.fields.eth_type         = orig_eth_type;
    query.match.masks.eth_type          = 0;

    TEST_ASSERT(count_matching(ft, &query) == 1);
    TEST_INDIGO_OK(first_match(ft, &query, &lookup_entry));
    TEST_ASSERT(lookup_entry->id == TEST_ENT_ID);

    ft_delete(ft, entry);
    of_object_delete(flow_add);

    /* Delete the table */
    ft_destroy(ft);

    /* Create a new flow table and add TEST_FLOW_COUNT entries. Do some queries */
    ft = ft_create(&config);
    TEST_ASSERT(ft != NULL);
    TEST_OK(populate_table(ft, TEST_FLOW_COUNT, &query.match));
    orig_eth_type = query.match.fields.eth_type; /* Last ethtype added */

    /* Query table and expect to get all results */
    query.out_port                      = OF_PORT_DEST_WILDCARD;
    query.mode                          = OF_MATCH_NON_STRICT;
    query.match.fields.eth_type         = 0;
    query.match.masks.eth_type          = 0;

    TEST_ASSERT(count_matching(ft, &query) == TEST_FLOW_COUNT);

    /* Query table and expect to get one match */
    query.out_port                      = OF_PORT_DEST_WILDCARD;
    query.mode                          = OF_MATCH_NON_STRICT;
    query.match.fields.eth_type         = orig_eth_type;
    query.match.masks.eth_type          = 0xffff;

    TEST_ASSERT(count_matching(ft, &query) == 1);

    /* Query table and expect to get 50 matches (every other one) */
    query.out_port                      = OF_PORT_DEST_WILDCARD;
    query.mode                          = OF_MATCH_NON_STRICT;
    query.match.fields.eth_type         = 0x1;
    query.match.masks.eth_type          = 0x1;

    TEST_ASSERT(count_matching(ft, &query) == TEST_FLOW_COUNT/2);

    TEST_ASSERT(check_bucket_counts(ft, TEST_FLOW_COUNT) == 0);
    TEST_ASSERT(check_table_entry_states(ft) == 0);

    /* Query table for each individual flow with exact match */
    for (idx = 0; idx < TEST_FLOW_COUNT; idx++) {
        query.out_port                      = OF_PORT_DEST_WILDCARD;
        query.mode                          = OF_MATCH_STRICT;
        query.match.fields.eth_type         = TEST_ETH_TYPE(idx);
        query.match.masks.eth_type          = 0xffff;

        TEST_ASSERT(count_matching(ft, &query) == 1);

        TEST_INDIGO_OK(ft_strict_match(ft, &query, &entry));
        TEST_ASSERT(entry->id == TEST_KEY(idx));
    }

    TEST_OK(depopulate_table(ft));
    TEST_ASSERT(check_bucket_counts(ft, 0) == 0);
    ft_destroy(ft);
    ft = NULL;

    /* @todo Check for memory consistency */

    return TEST_PASS;
}

static int
add_flow(ft_instance_t ft, int id, ft_entry_t **entry_p)
{
    of_flow_add_t *flow_add;
    ft_entry_t *entry;
    flow_add = of_flow_add_new(OF_VERSION_1_0);
    of_flow_add_OF_VERSION_1_0_populate(flow_add, id);
    of_flow_add_flags_set(flow_add, 0);
    of_flow_add_cookie_set(flow_add, id);
    TEST_INDIGO_OK(ft_add(ft, id, flow_add, &entry));
    of_object_delete(flow_add);
    *entry_p = entry;
    return 0;
}

static int
test_ft_iterator(void)
{
    ft_instance_t ft;
    ft_config_t config = {
        1024, /* strict_match buckets */
        1024, /* flow_id buckets */
    };
    int i;
    const int num_flows = 3;
    ft_entry_t *entries[num_flows];

    ft = ft_create(&config);

    for (i = 0; i < num_flows; i++) {
        TEST_OK(add_flow(ft, i, &entries[i]));
        TEST_ASSERT(entries[i]->id == i);
    }

    /* Cleanup at start */
    {
        ft_iterator_t iter;
        ft_iterator_init(&iter, ft, NULL);
        ft_iterator_cleanup(&iter);
    }

    /* Cleanup in middle */
    {
        ft_iterator_t iter;
        ft_iterator_init(&iter, ft, NULL);
        ft_iterator_next(&iter);
        ft_iterator_cleanup(&iter);
    }

    /* Cleanup at end */
    {
        ft_iterator_t iter;
        ft_iterator_init(&iter, ft, NULL);
        while (ft_iterator_next(&iter) != NULL);
        ft_iterator_cleanup(&iter);
    }

    /* Verify we get all entries with no duplicates */
    {
        ft_entry_t *results[num_flows];
        ft_entry_t *entry;
        ft_iterator_t iter;
        ft_iterator_init(&iter, ft, NULL);
        memset(results, 0, sizeof(results));
        while ((entry = ft_iterator_next(&iter)) != NULL) {
            TEST_ASSERT(entry->id >= 0 && entry->id < 3);
            TEST_ASSERT(entry == entries[entry->id]);
            TEST_ASSERT(results[entry->id] == NULL);
            results[entry->id] = entry;
        }
        for (i = 0; i < num_flows; i++) {
            TEST_ASSERT(results[i] == entries[i]);
        }
        ft_iterator_cleanup(&iter);
    }

    /* Verify we get all entries with no duplicates when deleting the current flow */
    {
        ft_entry_t *results[num_flows];
        ft_entry_t *entry;
        ft_iterator_t iter;
        ft_iterator_init(&iter, ft, NULL);
        memset(results, 0, sizeof(results));
        while ((entry = ft_iterator_next(&iter)) != NULL) {
            TEST_ASSERT(entry->id >= 0 && entry->id < 3);
            TEST_ASSERT(entry == entries[entry->id]);
            TEST_ASSERT(results[entry->id] == NULL);
            results[entry->id] = entry;
            ft_delete(ft, entry);
        }
        for (i = 0; i < num_flows; i++) {
            TEST_ASSERT(results[i] == entries[i]);
        }
        ft_iterator_cleanup(&iter);
    }

    /* Repopulate table */
    for (i = 0; i < num_flows; i++) {
        TEST_OK(add_flow(ft, i, &entries[i]));
        TEST_ASSERT(entries[i]->id == i);
    }

    /* Check iteration order */
    /* Implementation dependent */
    {
        ft_iterator_t iter;
        ft_iterator_init(&iter, ft, NULL);
        for (i = 0; i < num_flows; i++) {
            TEST_ASSERT(ft_iterator_next(&iter) == entries[i]);
        }
        TEST_ASSERT(ft_iterator_next(&iter) == NULL);
        TEST_ASSERT(ft_iterator_next(&iter) == NULL);
        ft_iterator_cleanup(&iter);
    }

    /* Check iteration order with concurrent delete/add */
    /* Implementation dependent */
    {
        ft_iterator_t iter;
        ft_iterator_init(&iter, ft, NULL);
        TEST_ASSERT(ft_iterator_next(&iter) == entries[0]);
        ft_delete(ft, entries[0]);
        TEST_ASSERT(ft_iterator_next(&iter) == entries[1]);
        TEST_OK(add_flow(ft, 0, &entries[0]));
        TEST_ASSERT(ft_iterator_next(&iter) == entries[2]);
        TEST_ASSERT(ft_iterator_next(&iter) == entries[0]);
        TEST_ASSERT(ft_iterator_next(&iter) == NULL);
        ft_iterator_cleanup(&iter);
    }

    /* Check query by cookie */
    /* Wildcards lowest cookie bit, so cookies 0 and 1 match while 2 does not */
    {
        of_meta_match_t query;
        ft_entry_t *results[num_flows];
        ft_entry_t *entry;
        ft_iterator_t iter;
        memset(&query, 0, sizeof(query));
        query.mode = OF_MATCH_NON_STRICT;
        query.cookie = 0;
        query.cookie_mask = 0xfffffffffffffffeULL;
        query.out_port = OF_PORT_DEST_WILDCARD;
        query.table_id = TABLE_ID_ANY;
        ft_iterator_init(&iter, ft, &query);
        memset(results, 0, sizeof(results));
        while ((entry = ft_iterator_next(&iter)) != NULL) {
            TEST_ASSERT(entry->id >= 0 && entry->id < 3);
            TEST_ASSERT(entry == entries[entry->id]);
            TEST_ASSERT(results[entry->id] == NULL);
            results[entry->id] = entry;
            ft_delete(ft, entry);
        }
        TEST_ASSERT(ft_iterator_next(&iter) == NULL);
        TEST_ASSERT(ft_iterator_next(&iter) == NULL);
        for (i = 0; i < num_flows; i++) {
            if (i == 0 || i == 1) {
                TEST_ASSERT(results[i] == entries[i]);
            } else {
                TEST_ASSERT(results[i] == NULL);
            }
        }
        ft_iterator_cleanup(&iter);
    }

    ft_destroy(ft);

    return TEST_PASS;
}

struct iter_task_state {
    ft_instance_t ft;
    int finished;
    int entries_seen;
};

static void
iter_task_cb(void *cookie, ft_entry_t *entry)
{
    struct iter_task_state *state = cookie;
    if (entry != NULL) {
        state->finished = 0;
        state->entries_seen++;
        ft_delete(state->ft, entry);
    } else {
        state->finished = 1;
    }
}

static int
test_ft_iter_task(void)
{
    ft_instance_t ft;
    ft_config_t config = {
        1024, /* strict_match buckets */
        1024, /* flow_id buckets */
    };
    of_flow_add_t *flow_add1, *flow_add2;
    ft_entry_t *entry1, *entry2;
    struct iter_task_state state;

    ft = ft_create(&config);

    flow_add1 = of_flow_add_new(OF_VERSION_1_0);
    of_flow_add_OF_VERSION_1_0_populate(flow_add1, 1);
    of_flow_add_flags_set(flow_add1, 0);

    flow_add2 = of_flow_add_new(OF_VERSION_1_0);
    of_flow_add_OF_VERSION_1_0_populate(flow_add2, 2);
    of_flow_add_flags_set(flow_add2, 0);

    TEST_INDIGO_OK(ft_add(ft, 1, flow_add1, &entry1));
    TEST_INDIGO_OK(ft_add(ft, 2, flow_add2, &entry2));

    state = (struct iter_task_state) { .ft = ft, .finished = -1, .entries_seen = 0 };
    ft_spawn_iter_task(ft, NULL, iter_task_cb, &state, IND_SOC_DEFAULT_PRIORITY);
    TEST_ASSERT(state.finished == -1);
    TEST_ASSERT(state.entries_seen == 0);
    TEST_ASSERT(ft->status.current_count == 2);
    while (state.finished != 1) {
        ind_soc_select_and_run(0);
    }
    TEST_ASSERT(state.finished == 1);
    TEST_ASSERT(state.entries_seen == 2);
    TEST_ASSERT(ft->status.current_count == 0);

    ft_destroy(ft);
    of_object_delete(flow_add1);
    of_object_delete(flow_add2);

    return TEST_PASS;
}

static int
test_hello(void)
{
    of_hello_t *hello;

    hello = of_hello_new(OF_VERSION_1_0);
    indigo_core_receive_controller_message(0, hello);
    of_object_delete(hello);

    return TEST_PASS;
}

static int
test_packet_out(void)
{
    of_packet_out_t *pkt_out;

    pkt_out = of_packet_out_new(OF_VERSION_1_0);
    /* Could add params, but core doesn't do anything with them */
    indigo_core_receive_controller_message(0, pkt_out);
    of_object_delete(pkt_out);

    return TEST_PASS;
}

static int
test_packet_in(void)
{
    of_packet_in_t *pkt_in;

    pkt_in = of_packet_in_new(OF_VERSION_1_0);
    /* Could add params, but core doesn't do anything with them */
    TEST_INDIGO_OK(indigo_core_packet_in(pkt_in));

    return TEST_PASS;
}

static int
test_experimenter(void)
{
    of_experimenter_t *exp;

    exp = of_experimenter_new(OF_VERSION_1_0);
    /* Could add params, but core doesn't do anything with them */
    indigo_core_receive_controller_message(0, exp);
    of_object_delete(exp);

    return TEST_PASS;
}

static int
test_desc_strings(void)
{
    of_desc_str_t desc_get;
    of_desc_str_t desc_set;
    of_serial_num_t ser_num_set;
    of_serial_num_t ser_num_get;

    INDIGO_MEM_SET(ser_num_set, 0xee, OF_SERIAL_NUM_LEN);
    INDIGO_MEM_CLEAR(ser_num_get, OF_SERIAL_NUM_LEN);
    TEST_INDIGO_OK(ind_core_serial_num_set(ser_num_set));
    TEST_INDIGO_OK(ind_core_serial_num_get(ser_num_get));
    TEST_ASSERT(INDIGO_MEM_COMPARE(ser_num_set, ser_num_get,
                                   OF_SERIAL_NUM_LEN) == 0);

    INDIGO_MEM_SET(desc_set, 0xee, OF_DESC_STR_LEN);
    INDIGO_MEM_CLEAR(desc_get, OF_DESC_STR_LEN);
    TEST_INDIGO_OK(ind_core_sw_desc_set(desc_set));
    TEST_INDIGO_OK(ind_core_sw_desc_get(desc_get));
    TEST_ASSERT(INDIGO_MEM_COMPARE(desc_set, desc_get, OF_DESC_STR_LEN) == 0);

    INDIGO_MEM_SET(desc_set, 0xee, OF_DESC_STR_LEN);
    INDIGO_MEM_CLEAR(desc_get, OF_DESC_STR_LEN);
    TEST_INDIGO_OK(ind_core_hw_desc_set(desc_set));
    TEST_INDIGO_OK(ind_core_hw_desc_get(desc_get));
    TEST_ASSERT(INDIGO_MEM_COMPARE(desc_set, desc_get, OF_DESC_STR_LEN) == 0);

    INDIGO_MEM_SET(desc_set, 0xee, OF_DESC_STR_LEN);
    INDIGO_MEM_CLEAR(desc_get, OF_DESC_STR_LEN);
    TEST_INDIGO_OK(ind_core_dp_desc_set(desc_set));
    TEST_INDIGO_OK(ind_core_dp_desc_get(desc_get));
    TEST_ASSERT(INDIGO_MEM_COMPARE(desc_set, desc_get, OF_DESC_STR_LEN) == 0);

    INDIGO_MEM_SET(desc_set, 0xee, OF_DESC_STR_LEN);
    INDIGO_MEM_CLEAR(desc_get, OF_DESC_STR_LEN);
    TEST_INDIGO_OK(ind_core_dp_desc_set(desc_set));
    TEST_INDIGO_OK(ind_core_dp_desc_get(desc_get));
    TEST_ASSERT(INDIGO_MEM_COMPARE(desc_set, desc_get, OF_DESC_STR_LEN) == 0);

    INDIGO_MEM_SET(desc_set, 0xee, OF_DESC_STR_LEN);
    INDIGO_MEM_CLEAR(desc_get, OF_DESC_STR_LEN);
    TEST_INDIGO_OK(ind_core_mfr_desc_set(desc_set));
    TEST_INDIGO_OK(ind_core_mfr_desc_get(desc_get));
    TEST_ASSERT(INDIGO_MEM_COMPARE(desc_set, desc_get, OF_DESC_STR_LEN) == 0);

    return TEST_PASS;
}

static int
delete_all_entries(ft_instance_t ft)
{
    of_flow_delete_t *flow_del;
    of_match_t match;

    INDIGO_MEM_CLEAR(&match, sizeof(match));
    flow_del = of_flow_delete_new(OF_VERSION_1_0);
    TEST_ASSERT(flow_del != NULL);
    of_flow_delete_out_port_set(flow_del, OF_PORT_DEST_WILDCARD);
    TEST_OK(of_flow_delete_match_set(flow_del, &match));
    handle_message(flow_del);
    TEST_INDIGO_OK(do_barrier());

    TEST_OK(depopulate_table(ft));

    return TEST_PASS;
}

/* Add n flows, delete them all */
int
test_simple_add_del(void)
{
    of_flow_add_t *flow_add;
    ft_status_t *status;
    int idx;

    status = FT_STATUS(ind_core_ft);
    for (idx = 0; idx < TEST_FLOW_COUNT; idx++) {
        flow_add = of_flow_add_new(OF_VERSION_1_0);
        TEST_ASSERT(flow_add != NULL);
        TEST_ASSERT(of_flow_add_OF_VERSION_1_0_populate(flow_add, idx) != 0);
        of_flow_add_flags_set(flow_add, 0);
        handle_message(flow_add);
        TEST_INDIGO_OK(do_barrier());
        CHECK_FLOW_COUNT(status, idx + 1);
    }

    TEST_ASSERT(delete_all_entries(ind_core_ft) == TEST_PASS);
    TEST_ASSERT(status->current_count == 0);

    return TEST_PASS;
}

/* Add n flows, delete one by one */
int
test_exact_add_del(void)
{
    of_flow_add_t *flow_add_keep[TEST_FLOW_COUNT];
    of_flow_add_t *flow_add;
    of_flow_delete_t *flow_del;
    ft_status_t *status;
    int idx;
    of_match_t match;
    uint16_t prio;

    status = FT_STATUS(ind_core_ft);
    for (idx = 0; idx < TEST_FLOW_COUNT; idx++) {
        flow_add = of_flow_add_new(OF_VERSION_1_0);
        TEST_ASSERT(flow_add != NULL);
        TEST_ASSERT(of_flow_add_OF_VERSION_1_0_populate(flow_add, idx) != 0);
        of_flow_add_flags_set(flow_add, 0);
        flow_add_keep[idx] = of_object_dup(flow_add);
        handle_message(flow_add);
        TEST_INDIGO_OK(do_barrier());
        CHECK_FLOW_COUNT(status, idx + 1);
    }

    for (idx = 0; idx < TEST_FLOW_COUNT; idx++) {
        INDIGO_MEM_CLEAR(&match, sizeof(match));
        /* Match the source mac addr which should be diff for each entry */
        TEST_OK(of_flow_add_match_get(flow_add_keep[idx], &match));
        of_flow_add_priority_get(flow_add_keep[idx], &prio);
        flow_del = of_flow_delete_strict_new(OF_VERSION_1_0);
        TEST_ASSERT(flow_del != NULL);
        of_flow_delete_strict_out_port_set(flow_del, OF_PORT_DEST_WILDCARD);
        of_flow_delete_strict_priority_set(flow_del, prio);
        TEST_OK(of_flow_delete_strict_match_set(flow_del, &match));
        handle_message(flow_del);
        TEST_INDIGO_OK(do_barrier());
        CHECK_FLOW_COUNT(status, TEST_FLOW_COUNT - (idx + 1));
        of_flow_add_delete(flow_add_keep[idx]);
    }
    TEST_ASSERT(status->current_count == 0);

    return TEST_PASS;
}

/* Add n flows, delete one by one */
int
test_modify(void)
{
    of_flow_add_t *flow_add_keep[TEST_FLOW_COUNT];
    of_flow_add_t *flow_add;
    of_flow_modify_t *flow_mod;
    ft_status_t *status;
    int idx;
    of_match_t match;
    uint16_t prio;

    status = FT_STATUS(ind_core_ft);
    for (idx = 0; idx < TEST_FLOW_COUNT; idx++) {
        flow_add = of_flow_add_new(OF_VERSION_1_0);
        TEST_ASSERT(flow_add != NULL);
        TEST_ASSERT(of_flow_add_OF_VERSION_1_0_populate(flow_add, idx) != 0);
        of_flow_add_flags_set(flow_add, 0);
        flow_add_keep[idx] = of_object_dup(flow_add);
        handle_message(flow_add);
        TEST_INDIGO_OK(do_barrier());
        CHECK_FLOW_COUNT(status, idx + 1);
    }

    for (idx = 0; idx < TEST_FLOW_COUNT; idx++) {
        INDIGO_MEM_CLEAR(&match, sizeof(match));
        /* Match the source mac addr which should be diff for each entry */
        TEST_OK(of_flow_add_match_get(flow_add_keep[idx], &match));
        of_flow_add_priority_get(flow_add_keep[idx], &prio);
        flow_mod = of_flow_modify_new(OF_VERSION_1_0);
        TEST_ASSERT(flow_mod != NULL);
        of_flow_modify_out_port_set(flow_mod, OF_PORT_DEST_WILDCARD);
        of_flow_modify_priority_set(flow_mod, prio);
        TEST_OK(of_flow_modify_match_set(flow_mod, &match));
        handle_message(flow_mod);
        TEST_OK(do_barrier());
        CHECK_FLOW_COUNT(status, TEST_FLOW_COUNT);
        of_flow_add_delete(flow_add_keep[idx]);
    }
    CHECK_FLOW_COUNT(status, TEST_FLOW_COUNT);
    /* Delete all the entries */
    TEST_ASSERT(delete_all_entries(ind_core_ft) == TEST_PASS);
    TEST_ASSERT(status->current_count == 0);

    return TEST_PASS;
}

/* Add n flows, delete one by one */
int
test_modify_strict(void)
{
    of_flow_add_t *flow_add_keep[TEST_FLOW_COUNT];
    of_flow_add_t *flow_add;
    of_flow_modify_strict_t *flow_mod;
    ft_status_t *status;
    int idx;
    of_match_t match;
    uint16_t prio;

    status = FT_STATUS(ind_core_ft);
    for (idx = 0; idx < TEST_FLOW_COUNT; idx++) {
        flow_add = of_flow_add_new(OF_VERSION_1_0);
        TEST_ASSERT(flow_add != NULL);
        TEST_ASSERT(of_flow_add_OF_VERSION_1_0_populate(flow_add, idx) != 0);
        of_flow_add_flags_set(flow_add, 0);
        flow_add_keep[idx] = of_object_dup(flow_add);
        handle_message(flow_add);
        TEST_INDIGO_OK(do_barrier());
        CHECK_FLOW_COUNT(status, idx + 1);
    }

    for (idx = 0; idx < TEST_FLOW_COUNT; idx++) {
        INDIGO_MEM_CLEAR(&match, sizeof(match));
        /* Match the source mac addr which should be diff for each entry */
        TEST_OK(of_flow_add_match_get(flow_add_keep[idx], &match));
        of_flow_add_priority_get(flow_add_keep[idx], &prio);
        flow_mod = of_flow_modify_strict_new(OF_VERSION_1_0);
        TEST_ASSERT(flow_mod != NULL);
        of_flow_modify_strict_out_port_set(flow_mod, OF_PORT_DEST_WILDCARD);
        of_flow_modify_strict_priority_set(flow_mod, prio);
        TEST_OK(of_flow_modify_strict_match_set(flow_mod, &match));
        handle_message(flow_mod);
        TEST_INDIGO_OK(do_barrier());
        CHECK_FLOW_COUNT(status, TEST_FLOW_COUNT);
        of_flow_add_delete(flow_add_keep[idx]);
    }
    CHECK_FLOW_COUNT(status, TEST_FLOW_COUNT);

    TEST_ASSERT(delete_all_entries(ind_core_ft) == TEST_PASS);
    TEST_ASSERT(status->current_count == 0);

    return TEST_PASS;
}


int
test_flow_stats(void)
{
    return TEST_PASS;
}

struct listener_state {
    int count;
    indigo_core_listener_result_t result;
};

struct listener_state listener_states[3];

indigo_core_listener_result_t
listener0(void *arg)
{
    listener_states[0].count++;
    return listener_states[0].result;
}

indigo_core_listener_result_t
listener1(void *arg)
{
    listener_states[1].count++;
    return listener_states[1].result;
}

indigo_core_listener_result_t
listener2(void *arg)
{
    listener_states[2].count++;
    return listener_states[2].result;
}

int
test_packet_in_listeners(void)
{
    memset(async_message_counters, 0, sizeof(async_message_counters));

    /* Register 3 listeners */
    TEST_INDIGO_OK(indigo_core_packet_in_listener_register(
        (indigo_core_packet_in_listener_f)listener0));
    TEST_INDIGO_OK(indigo_core_packet_in_listener_register(
        (indigo_core_packet_in_listener_f)listener1));
    TEST_INDIGO_OK(indigo_core_packet_in_listener_register(
        (indigo_core_packet_in_listener_f)listener2));

    memset(listener_states, 0, sizeof(listener_states));
    listener_states[0].result = INDIGO_CORE_LISTENER_RESULT_PASS;
    listener_states[1].result = INDIGO_CORE_LISTENER_RESULT_PASS;
    listener_states[2].result = INDIGO_CORE_LISTENER_RESULT_PASS;

    /* Pass event through listeners */
    TEST_INDIGO_OK(indigo_core_packet_in(of_packet_in_new(OF_VERSION_1_0)));
    TEST_ASSERT(listener_states[0].count == 1);
    TEST_ASSERT(listener_states[1].count == 1);
    TEST_ASSERT(listener_states[2].count == 1);
    TEST_ASSERT(async_message_counters[OF_PACKET_IN] == 1);

    /* Drop event in one listener */
    listener_states[1].result = INDIGO_CORE_LISTENER_RESULT_DROP;
    TEST_INDIGO_OK(indigo_core_packet_in(of_packet_in_new(OF_VERSION_1_0)));
    TEST_ASSERT(listener_states[0].count == 2);
    TEST_ASSERT(listener_states[1].count == 2);
    TEST_ASSERT(listener_states[2].count == 2);
    TEST_ASSERT(async_message_counters[OF_PACKET_IN] == 1);

    /* Unregister listeners */
    indigo_core_packet_in_listener_unregister(
        (indigo_core_packet_in_listener_f)listener1);
    indigo_core_packet_in_listener_unregister(
        (indigo_core_packet_in_listener_f)listener2);
    indigo_core_packet_in_listener_unregister(
        (indigo_core_packet_in_listener_f)listener0);

    TEST_INDIGO_OK(indigo_core_packet_in(of_packet_in_new(OF_VERSION_1_0)));
    TEST_ASSERT(listener_states[0].count == 2);
    TEST_ASSERT(listener_states[1].count == 2);
    TEST_ASSERT(listener_states[2].count == 2);
    TEST_ASSERT(async_message_counters[OF_PACKET_IN] == 2);

    return TEST_PASS;
}

int
test_port_status_listeners(void)
{
    memset(async_message_counters, 0, sizeof(async_message_counters));

    /* Register 3 listeners */
    TEST_INDIGO_OK(indigo_core_port_status_listener_register(
        (indigo_core_port_status_listener_f)listener0));
    TEST_INDIGO_OK(indigo_core_port_status_listener_register(
        (indigo_core_port_status_listener_f)listener1));
    TEST_INDIGO_OK(indigo_core_port_status_listener_register(
        (indigo_core_port_status_listener_f)listener2));

    memset(listener_states, 0, sizeof(listener_states));
    listener_states[0].result = INDIGO_CORE_LISTENER_RESULT_PASS;
    listener_states[1].result = INDIGO_CORE_LISTENER_RESULT_PASS;
    listener_states[2].result = INDIGO_CORE_LISTENER_RESULT_PASS;

    /* Pass event through listeners */
    indigo_core_port_status_update(of_port_status_new(OF_VERSION_1_0));
    TEST_ASSERT(listener_states[0].count == 1);
    TEST_ASSERT(listener_states[1].count == 1);
    TEST_ASSERT(listener_states[2].count == 1);
    TEST_ASSERT(async_message_counters[OF_PORT_STATUS] == 1);

    /* Drop event in one listener */
    listener_states[1].result = INDIGO_CORE_LISTENER_RESULT_DROP;
    indigo_core_port_status_update(of_port_status_new(OF_VERSION_1_0));
    TEST_ASSERT(listener_states[0].count == 2);
    TEST_ASSERT(listener_states[1].count == 2);
    TEST_ASSERT(listener_states[2].count == 2);
    TEST_ASSERT(async_message_counters[OF_PORT_STATUS] == 1);

    /* Unregister listeners */
    indigo_core_port_status_listener_unregister(
        (indigo_core_port_status_listener_f)listener1);
    indigo_core_port_status_listener_unregister(
        (indigo_core_port_status_listener_f)listener2);
    indigo_core_port_status_listener_unregister(
        (indigo_core_port_status_listener_f)listener0);

    indigo_core_port_status_update(of_port_status_new(OF_VERSION_1_0));
    TEST_ASSERT(listener_states[0].count == 2);
    TEST_ASSERT(listener_states[1].count == 2);
    TEST_ASSERT(listener_states[2].count == 2);
    TEST_ASSERT(async_message_counters[OF_PORT_STATUS] == 2);

    return TEST_PASS;
}

int
test_message_listeners(void)
{
    memset(controller_message_counters, 0, sizeof(controller_message_counters));

    /* Register 3 listeners */
    TEST_INDIGO_OK(indigo_core_message_listener_register(
        (indigo_core_message_listener_f)listener0));
    TEST_INDIGO_OK(indigo_core_message_listener_register(
        (indigo_core_message_listener_f)listener1));
    TEST_INDIGO_OK(indigo_core_message_listener_register(
        (indigo_core_message_listener_f)listener2));

    memset(listener_states, 0, sizeof(listener_states));
    listener_states[0].result = INDIGO_CORE_LISTENER_RESULT_PASS;
    listener_states[1].result = INDIGO_CORE_LISTENER_RESULT_PASS;
    listener_states[2].result = INDIGO_CORE_LISTENER_RESULT_PASS;

    /* Pass event through listeners */
    handle_message(of_features_request_new(OF_VERSION_1_0));
    TEST_ASSERT(listener_states[0].count == 1);
    TEST_ASSERT(listener_states[1].count == 1);
    TEST_ASSERT(listener_states[2].count == 1);
    TEST_ASSERT(controller_message_counters[OF_FEATURES_REPLY] == 1);

    /* Drop event in one listener */
    listener_states[1].result = INDIGO_CORE_LISTENER_RESULT_DROP;
    handle_message(of_features_request_new(OF_VERSION_1_0));
    TEST_ASSERT(listener_states[0].count == 2);
    TEST_ASSERT(listener_states[1].count == 2);
    TEST_ASSERT(listener_states[2].count == 2);
    TEST_ASSERT(controller_message_counters[OF_FEATURES_REPLY] == 1);

    /* Unregister listeners */
    indigo_core_message_listener_unregister(
        (indigo_core_message_listener_f)listener1);
    indigo_core_message_listener_unregister(
        (indigo_core_message_listener_f)listener2);
    indigo_core_message_listener_unregister(
        (indigo_core_message_listener_f)listener0);

    handle_message(of_features_request_new(OF_VERSION_1_0));
    TEST_ASSERT(listener_states[0].count == 2);
    TEST_ASSERT(listener_states[1].count == 2);
    TEST_ASSERT(listener_states[2].count == 2);
    TEST_ASSERT(controller_message_counters[OF_FEATURES_REPLY] == 2);

    return TEST_PASS;
}

int
aim_main(int argc, char* argv[])
{
    ind_core_config_t core;
    ind_soc_config_t soc_cfg = { 0 };

    ind_soc_init(&soc_cfg);
    ind_soc_enable_set(1);

    RUN_TEST(ft_hash);
    RUN_TEST(ft_iterator);
    RUN_TEST(ft_iter_task);

    /* Init Core */
    MEMSET(&core, 0, sizeof(core));
    core.expire_flows = 1;
    core.stats_check_ms = 1000;
    core.max_flowtable_entries = 1024;

    TRY(ind_core_init(&core));
    TRY(ind_core_enable_set(1));

    RUN_TEST(hello);
    RUN_TEST(packet_out);
    RUN_TEST(packet_in);
    RUN_TEST(experimenter);
    RUN_TEST(desc_strings);
    RUN_TEST(simple_add_del);
    RUN_TEST(exact_add_del);
    RUN_TEST(modify);
    RUN_TEST(modify_strict);

    RUN_TEST(packet_in_listeners);
    RUN_TEST(port_status_listeners);
    RUN_TEST(message_listeners);

    if (test_gentable() != TEST_PASS) {
        return 1;
    }

    if (test_table() != TEST_PASS) {
        return 1;
    }

    /* Kill logging for OFStateManager as next tests gen errors */
    aim_log_pvs_set(aim_log_find("ofstatemanager"), NULL);

    /* Run with delete returning an error */
    delete_error = INDIGO_ERROR_NOT_FOUND;
    RUN_TEST(simple_add_del);
    RUN_TEST(modify);
    RUN_TEST(modify_strict);

    /* Run with create returning an error */
    create_error = INDIGO_ERROR_UNKNOWN;
    delete_error = INDIGO_ERROR_NONE;
    RUN_TEST(simple_add_del);
    RUN_TEST(modify);
    RUN_TEST(modify_strict);

    /* Run with both add/delete returning an error */
    delete_error = INDIGO_ERROR_NOT_FOUND;
    RUN_TEST(simple_add_del);
    RUN_TEST(modify);
    RUN_TEST(modify_strict);

    TRY(ind_core_enable_set(0));
    TRY(ind_core_finish());

    return global_error;
}

AIM_LOG_STRUCT_DEFINE(
                      AIM_LOG_OPTIONS_DEFAULT,
                      AIM_LOG_BITS_DEFAULT /* | AIM_LOG_BIT_VERBOSE | AIM_LOG_BIT_TRACE */,
                      NULL, /* Custom log map */
                      0
                      );
