/****************************************************************
 *
 *        Copyright 2013-2014,2018-2020, Big Switch Networks, Inc.
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
#include <ofstatemanager_int.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <loci/loci.h>
#include <SocketManager/socketmanager.h>

#include "gentable_test.h"
#include "test_infra.h"

#define TABLE_ID 1
#define NUM_ENTRIES 10

extern void handle_message(of_object_t *obj);
extern int do_barrier(void);

static void do_add(uint32_t port, of_mac_addr_t mac, uint8_t csum_hi);
static void do_delete(uint32_t port);
static void do_add1(uint32_t port, of_mac_addr_t mac, uint8_t csum_hi);
static void do_delete1(uint32_t port);
static void do_clear(void);
static void do_entry_stats(void);
static void do_set_buckets_size(uint32_t buckets_size);
static void parse_key(of_list_bsn_tlv_t *key, of_port_no_t *port);

struct test_entry {
    of_mac_addr_t mac;
    int count_op;
    int count_add;
    int count_modify;
    int count_delete;
    int count_stats;
};

struct test_table {
    int count_op;
    int count_add;
    int count_modify;
    int count_delete;
    int count_stats;
    int count_starts;
    int count_finishes;
    int count_added;
    int count_modified;
    int count_deleted;
    int count_add_pending;
    int count_modify_pending;
    int count_del_pending;
    int count_add_timeout;
    int count_modify_timeout;
    int count_del_timeout;
    struct test_entry entries[NUM_ENTRIES];
};

static struct test_table table;

static indigo_core_gentable_ops_t test_ops;
static indigo_core_gentable_ops_t test_ops2;
static indigo_core_gentable_ops_t test_ops3;
static indigo_core_gentable_ops_t test_ops4;

static const of_mac_addr_t mac1 = { { 0xab, 0xcd, 0xef, 0xff, 0xff, 0x01 } };
static const of_mac_addr_t mac2 = { { 0xab, 0xcd, 0xef, 0xff, 0xff, 0x02 } };
static const of_mac_addr_t mac3 = { { 0xab, 0xcd, 0xef, 0xff, 0xff, 0x03 } };

static int async_delay = 0;
static int async_timeout = 0;

/* used by indigo_cxn_send_bsn_gentable_error */
int bsn_err_count = 0;
char bsn_err_txt[256];

static int
test_gentable_entry_add(void)
{
    indigo_core_gentable_t *gentable;
    of_table_name_t name = "gentable 0";

    memset(&table, 0, sizeof(table));
    indigo_core_gentable_register(name, &test_ops, &table, 10, 8, &gentable);
    AIM_TRUE_OR_DIE(indigo_core_gentable_id(gentable) == TABLE_ID);
    AIM_TRUE_OR_DIE(table.count_op == 0);

    memset(&table, 0, sizeof(table));
    do_add(1, mac1, 0);
    do_add(2, mac2, 0);
    AIM_TRUE_OR_DIE(!memcmp(&table.entries[1].mac, &mac1, sizeof(of_mac_addr_t)));
    AIM_TRUE_OR_DIE(table.entries[1].count_add == 1);
    AIM_TRUE_OR_DIE(table.entries[1].count_op == 1);
    AIM_TRUE_OR_DIE(!memcmp(&table.entries[2].mac, &mac2, sizeof(of_mac_addr_t)));
    AIM_TRUE_OR_DIE(table.entries[2].count_add == 1);
    AIM_TRUE_OR_DIE(table.entries[2].count_op == 1);
    AIM_TRUE_OR_DIE(table.count_add == 2);
    AIM_TRUE_OR_DIE(table.count_op == 2);

    memset(&table, 0, sizeof(table));
    indigo_core_gentable_unregister(gentable);
    AIM_TRUE_OR_DIE(table.entries[1].count_delete == 1);
    AIM_TRUE_OR_DIE(table.entries[1].count_op == 1);
    AIM_TRUE_OR_DIE(table.entries[2].count_delete == 1);
    AIM_TRUE_OR_DIE(table.entries[2].count_op == 1);
    AIM_TRUE_OR_DIE(table.count_delete == 2);
    AIM_TRUE_OR_DIE(table.count_op == 2);

    return TEST_PASS;
}

static int
test_gentable_entry_delete(void)
{
    indigo_core_gentable_t *gentable;
    of_table_name_t name = "gentable 0";

    memset(&table, 0, sizeof(table));
    indigo_core_gentable_register(name, &test_ops, &table, 10, 8, &gentable);
    AIM_TRUE_OR_DIE(indigo_core_gentable_id(gentable) == TABLE_ID);
    AIM_TRUE_OR_DIE(table.count_op == 0);

    memset(&table, 0, sizeof(table));
    do_add(1, mac1, 0);
    do_add(2, mac2, 0);

    memset(&table, 0, sizeof(table));
    do_delete(1);
    AIM_TRUE_OR_DIE(table.entries[1].count_delete == 1);
    AIM_TRUE_OR_DIE(table.entries[1].count_op == 1);
    AIM_TRUE_OR_DIE(table.count_delete == 1);
    AIM_TRUE_OR_DIE(table.count_op == 1);

    memset(&table, 0, sizeof(table));
    do_delete(2);
    AIM_TRUE_OR_DIE(table.entries[2].count_delete == 1);
    AIM_TRUE_OR_DIE(table.entries[2].count_op == 1);
    AIM_TRUE_OR_DIE(table.count_delete == 1);
    AIM_TRUE_OR_DIE(table.count_op == 1);

    memset(&table, 0, sizeof(table));
    indigo_core_gentable_unregister(gentable);
    AIM_TRUE_OR_DIE(table.count_op == 0);

    return TEST_PASS;
}

static int
test_gentable_entry_modify(void)
{
    indigo_core_gentable_t *gentable;
    of_table_name_t name = "gentable 0";

    memset(&table, 0, sizeof(table));
    indigo_core_gentable_register(name, &test_ops, &table, 10, 8, &gentable);
    AIM_TRUE_OR_DIE(indigo_core_gentable_id(gentable) == TABLE_ID);
    AIM_TRUE_OR_DIE(table.count_op == 0);

    do_add(1, mac1, 0);
    do_add(2, mac2, 0);

    memset(&table, 0, sizeof(table));
    do_add(1, mac3, 0);
    AIM_TRUE_OR_DIE(!memcmp(&table.entries[1].mac, &mac3, sizeof(of_mac_addr_t)));
    AIM_TRUE_OR_DIE(table.entries[1].count_modify == 1);
    AIM_TRUE_OR_DIE(table.entries[1].count_op == 1);
    AIM_TRUE_OR_DIE(table.count_modify == 1);
    AIM_TRUE_OR_DIE(table.count_op == 1);

    memset(&table, 0, sizeof(table));
    indigo_core_gentable_unregister(gentable);
    AIM_TRUE_OR_DIE(table.count_op == 2);

    return TEST_PASS;
}

static int
test_gentable_clear(void)
{
    indigo_core_gentable_t *gentable;
    of_table_name_t name = "gentable 0";

    memset(&table, 0, sizeof(table));
    indigo_core_gentable_register(name, &test_ops, &table, 10, 8, &gentable);
    AIM_TRUE_OR_DIE(indigo_core_gentable_id(gentable) == TABLE_ID);
    AIM_TRUE_OR_DIE(table.count_op == 0);

    do_add(1, mac1, 0);
    do_add(2, mac2, 0);

    memset(&table, 0, sizeof(table));
    do_clear();
    AIM_TRUE_OR_DIE(table.entries[1].count_delete == 1);
    AIM_TRUE_OR_DIE(table.entries[1].count_op == 1);
    AIM_TRUE_OR_DIE(table.entries[2].count_delete == 1);
    AIM_TRUE_OR_DIE(table.entries[2].count_op == 1);
    AIM_TRUE_OR_DIE(table.count_delete == 2);
    AIM_TRUE_OR_DIE(table.count_op == 2);

    memset(&table, 0, sizeof(table));
    indigo_core_gentable_unregister(gentable);
    AIM_TRUE_OR_DIE(table.count_op == 0);

    return TEST_PASS;
}

static int
test_gentable_entry_stats(void)
{
    indigo_core_gentable_t *gentable;
    of_table_name_t name = "gentable 0";

    memset(&table, 0, sizeof(table));
    indigo_core_gentable_register(name, &test_ops, &table, 10, 8, &gentable);
    AIM_TRUE_OR_DIE(indigo_core_gentable_id(gentable) == TABLE_ID);
    AIM_TRUE_OR_DIE(table.count_op == 0);

    do_add(1, mac1, 0);
    do_add(2, mac2, 0);

    memset(&table, 0, sizeof(table));
    do_entry_stats();
    AIM_TRUE_OR_DIE(table.entries[1].count_stats == 1);
    AIM_TRUE_OR_DIE(table.entries[1].count_op == 1);
    AIM_TRUE_OR_DIE(table.entries[2].count_stats == 1);
    AIM_TRUE_OR_DIE(table.entries[2].count_op == 1);
    AIM_TRUE_OR_DIE(table.count_stats == 2);
    AIM_TRUE_OR_DIE(table.count_op == 2);

    memset(&table, 0, sizeof(table));
    indigo_core_gentable_unregister(gentable);
    AIM_TRUE_OR_DIE(table.count_op == 2);

    return TEST_PASS;
}

static int
test_gentable_long_running_task(void)
{
    int i;
    indigo_core_gentable_t *gentable;
    of_table_name_t name = "gentable 0";

    memset(&table, 0, sizeof(table));
    indigo_core_gentable_register(name, &test_ops, &table, 10, 4, &gentable);
    AIM_TRUE_OR_DIE(indigo_core_gentable_id(gentable) == TABLE_ID);
    AIM_TRUE_OR_DIE(table.count_op == 0);

    /* Two entries per checksum bucket */
    for (i = 0; i < 8; i++) {
        do_add(i, mac1, i << 5);
    }

    memset(&table, 0, sizeof(table));

    of_object_t *request = of_bsn_gentable_entry_stats_request_new(OF_VERSION_1_3);
    of_bsn_gentable_entry_stats_request_xid_set(request, 0x12345678);
    of_bsn_gentable_entry_stats_request_table_id_set(request, TABLE_ID);
    handle_message(request);

    AIM_TRUE_OR_DIE(table.count_op == 0);

    /* Process first bucket normally */
    ind_soc_select_and_run(0);
    AIM_TRUE_OR_DIE(table.entries[0].count_op == 1);
    AIM_TRUE_OR_DIE(table.entries[1].count_op == 1);
    AIM_TRUE_OR_DIE(table.count_op == 2);

    /* Shrink buckets, process second half of first bucket */
    do_set_buckets_size(2);
    ind_soc_select_and_run(0);
    AIM_TRUE_OR_DIE(table.entries[2].count_op == 1);
    AIM_TRUE_OR_DIE(table.entries[3].count_op == 1);
    AIM_TRUE_OR_DIE(table.count_op == 4);

    /* Expand buckets, process third bucket */
    do_set_buckets_size(8);
    ind_soc_select_and_run(0);
    AIM_TRUE_OR_DIE(table.entries[4].count_op == 1);
    AIM_TRUE_OR_DIE(table.count_op == 5);

    /* Shrink buckets, process second half of third bucket */
    do_set_buckets_size(4);
    ind_soc_select_and_run(0);
    AIM_TRUE_OR_DIE(table.entries[5].count_op == 1);
    AIM_TRUE_OR_DIE(table.count_op == 6);

    /* Process fourth bucket */
    ind_soc_select_and_run(0);
    AIM_TRUE_OR_DIE(table.entries[6].count_op == 1);
    AIM_TRUE_OR_DIE(table.entries[7].count_op == 1);
    AIM_TRUE_OR_DIE(table.count_op == 8);

    do_barrier();
    ind_soc_select_and_run(0);

    AIM_TRUE_OR_DIE(table.count_stats == 8);
    AIM_TRUE_OR_DIE(table.count_op == 8);

    memset(&table, 0, sizeof(table));
    indigo_core_gentable_unregister(gentable);
    AIM_TRUE_OR_DIE(table.count_op == 8);

    return TEST_PASS;
}

static int
test_gentable_lookup(void)
{
    indigo_core_gentable_t *gentable;
    of_table_name_t name = "gentable 0";

    memset(&table, 0, sizeof(table));
    indigo_core_gentable_register(name, &test_ops, &table, 10, 8, &gentable);
    AIM_TRUE_OR_DIE(indigo_core_gentable_id(gentable) == TABLE_ID);
    AIM_TRUE_OR_DIE(table.count_op == 0);

    do_add(1, mac1, 0);

    /* Lookup an entry */
    {
        of_object_t *tlv = of_bsn_tlv_port_new(OF_VERSION_1_3);
        of_bsn_tlv_port_value_set(tlv, 1);
        void *priv = indigo_core_gentable_lookup(gentable, tlv);
        AIM_TRUE_OR_DIE(priv == &table.entries[1]);
        of_object_delete(tlv);
    }

    /* Lookup a nonexistent entry */
    {
        of_object_t *tlv = of_bsn_tlv_port_new(OF_VERSION_1_3);
        of_bsn_tlv_port_value_set(tlv, 2);
        void *priv = indigo_core_gentable_lookup(gentable, tlv);
        AIM_TRUE_OR_DIE(priv == NULL);
        of_object_delete(tlv);
    }

    memset(&table, 0, sizeof(table));
    indigo_core_gentable_unregister(gentable);

    return TEST_PASS;
}

static int
test_gentable_acquire(void)
{
    indigo_core_gentable_t *gentable;
    of_table_name_t name = "gentable 0";

    memset(&table, 0, sizeof(table));
    indigo_core_gentable_register(name, &test_ops, &table, 10, 8, &gentable);
    AIM_TRUE_OR_DIE(indigo_core_gentable_id(gentable) == TABLE_ID);
    AIM_TRUE_OR_DIE(table.count_op == 0);

    /* Acquire/release an entry */
    {
        do_add(1, mac1, 0);

        of_object_t *tlv = of_bsn_tlv_port_new(OF_VERSION_1_3);
        of_bsn_tlv_port_value_set(tlv, 1);

        void *priv = indigo_core_gentable_acquire(gentable, tlv);
        AIM_TRUE_OR_DIE(priv == &table.entries[1]);

        /* Deletion is not allowed while a reference exists to the entry */
        memset(&table, 0, sizeof(table));
        do_delete(1);
        AIM_TRUE_OR_DIE(table.count_op == 0);

        indigo_core_gentable_release(gentable, tlv);

        /* Reference released, entry can be deleted */
        memset(&table, 0, sizeof(table));
        do_delete(1);
        AIM_TRUE_OR_DIE(table.entries[1].count_delete == 1);
        AIM_TRUE_OR_DIE(table.count_op == 1);

        of_object_delete(tlv);
    }

    /* Attempt to acquire/release a nonexistent entry */
    {
        of_object_t *tlv = of_bsn_tlv_port_new(OF_VERSION_1_3);
        of_bsn_tlv_port_value_set(tlv, 1);

        void *priv = indigo_core_gentable_acquire(gentable, tlv);
        AIM_TRUE_OR_DIE(priv == NULL);

        indigo_core_gentable_release(gentable, tlv);

        of_object_delete(tlv);
    }

    memset(&table, 0, sizeof(table));
    indigo_core_gentable_unregister(gentable);

    return TEST_PASS;
}

static int
test_gentable_lookup_by_name(void)
{
    indigo_core_gentable_t *gt0;
    of_table_name_t gt0name = "gentable 0";
    indigo_core_gentable_t *gt1;
    of_table_name_t gt1name = "gentable 1";

    indigo_core_gentable_register(gt0name, &test_ops, (void*)1, 10, 8, &gt0);
    indigo_core_gentable_register(gt1name, &test_ops, (void*)2, 10, 8, &gt1);

    AIM_TRUE_OR_DIE(indigo_core_gentable_id_lookup("gentable 1") ==
                    indigo_core_gentable_id(gt1));
    AIM_TRUE_OR_DIE(indigo_core_gentable_id_lookup("gentable 0") ==
                    indigo_core_gentable_id(gt0));
    AIM_TRUE_OR_DIE(indigo_core_gentable_id_lookup("gentable 55") ==
                    GENTABLE_ID_INVALID);

    indigo_core_gentable_unregister(gt0);
    indigo_core_gentable_unregister(gt1);
    return TEST_PASS;
}

static int
test_gentable_start_finish(void)
{
    indigo_core_gentable_t *gentable;
    of_table_name_t name = "gentable 0";

    indigo_core_gentable_register(name, &test_ops, &table, 10, 8, &gentable);
    AIM_TRUE_OR_DIE(indigo_core_gentable_start(
        indigo_core_gentable_id(gentable), 0) == INDIGO_ERROR_NONE);
    AIM_TRUE_OR_DIE(indigo_core_gentable_finish(
        indigo_core_gentable_id(gentable), 0) == INDIGO_ERROR_NONE);
    AIM_TRUE_OR_DIE(table.count_starts == 0);
    AIM_TRUE_OR_DIE(table.count_finishes == 0);
    indigo_core_gentable_unregister(gentable);

    indigo_core_gentable_register(name, &test_ops2, &table, 10, 8, &gentable);
    AIM_TRUE_OR_DIE(indigo_core_gentable_start(
        indigo_core_gentable_id(gentable), 0) == INDIGO_ERROR_NONE);
    AIM_TRUE_OR_DIE(indigo_core_gentable_finish(
        indigo_core_gentable_id(gentable), 0) == INDIGO_ERROR_NONE);
    AIM_TRUE_OR_DIE(table.count_starts == 1);
    AIM_TRUE_OR_DIE(table.count_finishes == 1);
    indigo_core_gentable_unregister(gentable);

    return TEST_PASS;
}

static int
test_gentable_errs(void)
{
    indigo_core_gentable_t *gentable;
    of_table_name_t name = "gentable 3";

    indigo_core_gentable_register(name, &test_ops3, &table, 10, 8, &gentable);
    memset(&table, 0, sizeof(table));
    bsn_err_count = 0;
    do_add(1, mac1, 0);
    AIM_TRUE_OR_DIE(bsn_err_count == 1 &&
                    strcmp("add failure 1", bsn_err_txt) == 0);
    bsn_err_count = 0;
    do_add(1, mac1, 0);
    AIM_TRUE_OR_DIE(bsn_err_count == 0);
    bsn_err_count = 0;
    do_add(1, mac1, 0);
    AIM_TRUE_OR_DIE(bsn_err_count == 1 &&
                    strcmp("modify failure 1", bsn_err_txt) == 0);
    bsn_err_count = 0;
    do_delete(1);
    AIM_TRUE_OR_DIE(bsn_err_count == 1 &&
                    strcmp("delete failure 1", bsn_err_txt) == 0);
    bsn_err_count = 0;
    do_delete(1);
    AIM_TRUE_OR_DIE(bsn_err_count == 0);

    indigo_core_gentable_unregister(gentable);
    return TEST_PASS;
}

int
test_gentable_async(void)
{
    indigo_core_gentable_t *gentable;
    of_table_name_t name = "gentable 4";

    indigo_core_gentable_register(name, &test_ops4, &table, 10, 8, &gentable);
    memset(&table, 0, sizeof(table));
    async_delay = 10;
    async_timeout = 15;
    bsn_err_count = 0;
    /* Create a of message to Add an entry. add4() will return pending status */
    do_add1(1, mac1, 0);
    AIM_TRUE_OR_DIE(table.count_add_pending == 1);
    /* run 12 ms. The async delay will get invoked before timeout. */
    ind_soc_select_and_run(12);
    /* Should get added */
    AIM_TRUE_OR_DIE(table.count_add_pending == 0 &&
                    table.count_added == 1 &&
                    strcmp("async added", bsn_err_txt) == 0);
    /* modify */
    do_add1(1, mac2, 0);
    AIM_TRUE_OR_DIE(table.count_modify_pending == 1);
    ind_soc_select_and_run(12);
    /* Should get added */
    AIM_TRUE_OR_DIE(table.count_modify_pending == 0 &&
                    table.count_modified == 1 &&
                    strcmp("async modified", bsn_err_txt) == 0);
    
    /* delete */
    do_delete1(1);
    AIM_TRUE_OR_DIE(table.count_del_pending == 1);
    ind_soc_select_and_run(12);
    AIM_TRUE_OR_DIE(table.count_del_pending == 0 &&
                    table.count_deleted == 1 &&
                    strcmp("async deleted", bsn_err_txt) == 0);

    /* async timeout test */
    async_delay = 15;
    async_timeout = 10;
    bsn_err_count = 0;
    /* Create a of message to Add an entry. add4() will return pending status */
    do_add1(1, mac1, 0);
    AIM_TRUE_OR_DIE(table.count_add_pending == 1);
    /* run 12 ms. The async timeout will get invoked before bottom half. */
    ind_soc_select_and_run(12);
    /* Should get timeout */
    AIM_TRUE_OR_DIE(table.count_add_pending == 0 &&
                    table.count_add_timeout == 1 &&
                    strcmp("add timeout", bsn_err_txt) == 0);

    async_delay = 10;
    async_timeout = 15;
    bsn_err_count = 0;
    /* Create a of message to Add an entry. add4() will return pending status */
    do_add1(1, mac1, 0);
    AIM_TRUE_OR_DIE(table.count_add_pending == 1);
    /* run 12 ms. The async delay will get invoked before timeout. */
    ind_soc_select_and_run(12);

    /* modify */
    async_delay = 15;
    async_timeout = 10;
    bsn_err_count = 0;
    do_add1(1, mac2, 0);
    AIM_TRUE_OR_DIE(table.count_modify_pending == 1);
    ind_soc_select_and_run(12);
    /* Should get added */
    AIM_TRUE_OR_DIE(table.count_modify_pending == 0 &&
                    table.count_modify_timeout == 1 &&
                    strcmp("modify timeout", bsn_err_txt) == 0);
    
    /* delete */
    do_delete1(1);
    AIM_TRUE_OR_DIE(table.count_del_pending == 1);
    ind_soc_select_and_run(12);
    AIM_TRUE_OR_DIE(table.count_del_pending == 0 &&
                    table.count_del_timeout == 1 &&
                    strcmp("delete timeout", bsn_err_txt) == 0);

    indigo_core_gentable_unregister(gentable);
    return TEST_PASS;
}

int
test_gentable(void)
{
    RUN_TEST(gentable_entry_add);
    RUN_TEST(gentable_entry_delete);
    RUN_TEST(gentable_entry_modify);
    RUN_TEST(gentable_clear);
    RUN_TEST(gentable_entry_stats);
    RUN_TEST(gentable_long_running_task);
    RUN_TEST(gentable_lookup);
    RUN_TEST(gentable_acquire);
    RUN_TEST(gentable_lookup_by_name);
    RUN_TEST(gentable_start_finish);
    RUN_TEST(gentable_errs);
    RUN_TEST(gentable_async);
    return TEST_PASS;
}


/* Utility functions to send OpenFlow messages */

static void
do_add(uint32_t port, of_mac_addr_t mac, uint8_t csum_hi)
{
    of_object_t *obj = of_bsn_gentable_entry_add_new(OF_VERSION_1_3);
    of_bsn_gentable_entry_add_xid_set(obj, 0x12345678);
    of_bsn_gentable_entry_add_table_id_set(obj, TABLE_ID);
    {
        of_checksum_128_t checksum = { (uint64_t)csum_hi << 56, 0xFFEECCBBAA998877L };
        of_bsn_gentable_entry_add_checksum_set(obj, checksum);
    }
    {
        of_object_t *list = of_list_bsn_tlv_new(OF_VERSION_1_3);;
        {
            of_object_t *tlv = of_bsn_tlv_port_new(OF_VERSION_1_3);
            of_bsn_tlv_port_value_set(tlv, port);
            of_list_append(list, tlv);
            of_object_delete(tlv);
        }
        AIM_TRUE_OR_DIE(of_bsn_gentable_entry_add_key_set(obj, list) == 0);
        of_object_delete(list);
    }
    {
        of_object_t *list = of_list_bsn_tlv_new(OF_VERSION_1_3);;
        {
            of_object_t *tlv = of_bsn_tlv_mac_new(OF_VERSION_1_3);
            of_bsn_tlv_mac_value_set(tlv, mac);
            of_list_append(list, tlv);
            of_object_delete(tlv);
        }
        AIM_TRUE_OR_DIE(of_bsn_gentable_entry_add_value_set(obj, list) == 0);
        of_object_delete(list);
    }

    handle_message(obj);
    do_barrier();
}

static void
do_delete(uint32_t port)
{
    of_object_t *obj = of_bsn_gentable_entry_delete_new(OF_VERSION_1_3);
    of_bsn_gentable_entry_delete_xid_set(obj, 0x12345678);
    of_bsn_gentable_entry_delete_table_id_set(obj, TABLE_ID);
    {
        of_object_t *list = of_list_bsn_tlv_new(OF_VERSION_1_3);;
        {
            of_object_t *tlv = of_bsn_tlv_port_new(OF_VERSION_1_3);
            of_bsn_tlv_port_value_set(tlv, port);
            of_list_append(list, tlv);
            of_object_delete(tlv);
        }
        AIM_TRUE_OR_DIE(of_bsn_gentable_entry_delete_key_set(obj, list) == 0);
        of_object_delete(list);
    }

    handle_message(obj);
    do_barrier();
}

static void
do_add1(uint32_t port, of_mac_addr_t mac, uint8_t csum_hi)
{
    of_object_t *obj = of_bsn_gentable_entry_add_new(OF_VERSION_1_3);
    of_bsn_gentable_entry_add_xid_set(obj, 0x12345678);
    of_bsn_gentable_entry_add_table_id_set(obj, TABLE_ID);
    {
        of_checksum_128_t checksum = { (uint64_t)csum_hi << 56, 0xFFEECCBBAA998877L };
        of_bsn_gentable_entry_add_checksum_set(obj, checksum);
    }
    {
        of_object_t *list = of_list_bsn_tlv_new(OF_VERSION_1_3);;
        {
            of_object_t *tlv = of_bsn_tlv_port_new(OF_VERSION_1_3);
            of_bsn_tlv_port_value_set(tlv, port);
            of_list_append(list, tlv);
            of_object_delete(tlv);
        }
        AIM_TRUE_OR_DIE(of_bsn_gentable_entry_add_key_set(obj, list) == 0);
        of_object_delete(list);
    }
    {
        of_object_t *list = of_list_bsn_tlv_new(OF_VERSION_1_3);;
        {
            of_object_t *tlv = of_bsn_tlv_mac_new(OF_VERSION_1_3);
            of_bsn_tlv_mac_value_set(tlv, mac);
            of_list_append(list, tlv);
            of_object_delete(tlv);
        }
        AIM_TRUE_OR_DIE(of_bsn_gentable_entry_add_value_set(obj, list) == 0);
        of_object_delete(list);
    }

    handle_message(obj);
    do_barrier();
}

static void
do_delete1(uint32_t port)
{
    of_object_t *obj = of_bsn_gentable_entry_delete_new(OF_VERSION_1_3);
    of_bsn_gentable_entry_delete_xid_set(obj, 0x12345678);
    of_bsn_gentable_entry_delete_table_id_set(obj, TABLE_ID);
    {
        of_object_t *list = of_list_bsn_tlv_new(OF_VERSION_1_3);;
        {
            of_object_t *tlv = of_bsn_tlv_port_new(OF_VERSION_1_3);
            of_bsn_tlv_port_value_set(tlv, port);
            of_list_append(list, tlv);
            of_object_delete(tlv);
        }
        AIM_TRUE_OR_DIE(of_bsn_gentable_entry_delete_key_set(obj, list) == 0);
        of_object_delete(list);
    }

    handle_message(obj);
    do_barrier();
}

static void
do_clear(void)
{
    of_object_t *obj = of_bsn_gentable_clear_request_new(OF_VERSION_1_3);
    of_bsn_gentable_clear_request_xid_set(obj, 0x12345678);
    of_bsn_gentable_clear_request_table_id_set(obj, TABLE_ID);
    {
        of_checksum_128_t checksum = { 0x0, 0x0 };
        of_bsn_gentable_clear_request_checksum_set(obj, checksum);
        of_bsn_gentable_clear_request_checksum_mask_set(obj, checksum);
    }

    handle_message(obj);
    do_barrier();
}

static void
do_entry_stats()
{
    of_object_t *obj = of_bsn_gentable_entry_stats_request_new(OF_VERSION_1_3);
    of_bsn_gentable_entry_stats_request_xid_set(obj, 0x12345678);
    of_bsn_gentable_entry_stats_request_table_id_set(obj, TABLE_ID);
    {
        of_checksum_128_t checksum = { 0x0, 0x0 };
        of_bsn_gentable_entry_stats_request_checksum_set(obj, checksum);
        of_bsn_gentable_entry_stats_request_checksum_mask_set(obj, checksum);
    }

    handle_message(obj);
    do_barrier();
}

static void
do_set_buckets_size(uint32_t buckets_size)
{
    of_object_t *obj = of_bsn_gentable_set_buckets_size_new(OF_VERSION_1_3);
    of_bsn_gentable_set_buckets_size_xid_set(obj, 0x12345678);
    of_bsn_gentable_set_buckets_size_table_id_set(obj, TABLE_ID);
    of_bsn_gentable_set_buckets_size_buckets_size_set(obj, buckets_size);

    handle_message(obj);

    // HACK we want to send this in the middle of a long running task
    //do_barrier();
}


/* Table operations */

static void
parse_key(of_list_bsn_tlv_t *key, of_port_no_t *port)
{
    of_object_t tlv;
    int loop_rv = 0;
    int count = 0;

    OF_LIST_BSN_TLV_ITER(key, &tlv, loop_rv) {
        count++;
        if (tlv.object_id == OF_BSN_TLV_PORT) {
            of_bsn_tlv_port_value_get(&tlv, port);
        } else {
            AIM_DIE("unexpected TLV");
        }
    }

    AIM_TRUE_OR_DIE(count == 1);
}

static void
parse_value(of_list_bsn_tlv_t *value, of_mac_addr_t *mac)
{
    of_object_t tlv;
    int loop_rv = 0;
    int count = 0;

    OF_LIST_BSN_TLV_ITER(value, &tlv, loop_rv) {
        count++;
        if (tlv.object_id == OF_BSN_TLV_MAC) {
            of_bsn_tlv_mac_value_get(&tlv, mac);
        } else {
            AIM_DIE("unexpected TLV");
        }
    }

    AIM_TRUE_OR_DIE(count == 1);
}

static indigo_error_t
test_gentable_add(indigo_cxn_id_t cxn_id, void *table_priv, of_list_bsn_tlv_t *key, of_list_bsn_tlv_t *value, void **entry_priv)
{
    struct test_table *table = table_priv;

    of_port_no_t port;
    parse_key(key, &port);

    AIM_TRUE_OR_DIE(port < NUM_ENTRIES);

    struct test_entry *entry = &table->entries[port];

    parse_value(value, &entry->mac);

    table->count_op++;
    table->count_add++;

    entry->count_op++;
    entry->count_add++;

    *entry_priv = entry;
    return INDIGO_ERROR_NONE;
}

static indigo_error_t
test_gentable_modify(indigo_cxn_id_t cxn_id, void *table_priv, void *entry_priv, of_list_bsn_tlv_t *key, of_list_bsn_tlv_t *value)
{
    struct test_table *table = table_priv;

    of_port_no_t port;
    parse_key(key, &port);

    AIM_TRUE_OR_DIE(port < NUM_ENTRIES);

    struct test_entry *entry = &table->entries[port];
    AIM_TRUE_OR_DIE(entry == entry_priv);

    parse_value(value, &entry->mac);

    table->count_op++;
    table->count_modify++;

    entry->count_op++;
    entry->count_modify++;

    return INDIGO_ERROR_NONE;
}

static indigo_error_t
test_gentable_delete(indigo_cxn_id_t cxn_id, void *table_priv, void *entry_priv, of_list_bsn_tlv_t *key)
{
    struct test_table *table = table_priv;

    of_port_no_t port;
    parse_key(key, &port);

    AIM_TRUE_OR_DIE(port < NUM_ENTRIES);

    struct test_entry *entry = &table->entries[port];
    AIM_TRUE_OR_DIE(entry == entry_priv);

    table->count_op++;
    table->count_delete++;

    entry->count_op++;
    entry->count_delete++;

    return INDIGO_ERROR_NONE;
}

static void
test_gentable_get_stats(void *table_priv, void *entry_priv, of_list_bsn_tlv_t *key, of_list_bsn_tlv_t *stats)
{
    struct test_table *table = table_priv;

    of_port_no_t port;
    parse_key(key, &port);

    AIM_TRUE_OR_DIE(port < NUM_ENTRIES);

    struct test_entry *entry = &table->entries[port];

    AIM_TRUE_OR_DIE(entry == entry_priv);

    {
        of_object_t *tlv = of_bsn_tlv_rx_packets_new(OF_VERSION_1_3);
        of_bsn_tlv_rx_packets_value_set(tlv, 100);
        of_list_append(stats, tlv);
        of_object_delete(tlv);
    }
    {
        of_object_t *tlv = of_bsn_tlv_tx_packets_new(OF_VERSION_1_3);
        of_bsn_tlv_tx_packets_value_set(tlv, 101);
        of_list_append(stats, tlv);
        of_object_delete(tlv);
    }

    table->count_op++;
    table->count_stats++;

    entry->count_op++;
    entry->count_stats++;

    indigo_time_t start_time = INDIGO_CURRENT_TIME;
    do {
        AIM_USLEEP(10 * 1000);
    } while (INDIGO_TIME_DIFF_ms(start_time, INDIGO_CURRENT_TIME) < 10);
}

static indigo_core_gentable_ops_t test_ops = {
    .add2 = test_gentable_add,
    .modify2 = test_gentable_modify,
    .del2 = test_gentable_delete,
    .get_stats = test_gentable_get_stats,
};

static indigo_error_t
test_gentable_start(indigo_cxn_id_t cxn_id, void *table_priv)
{
    struct test_table *table = table_priv;
    table->count_op++;
    table->count_starts++;
    return INDIGO_ERROR_NONE;
}

static indigo_error_t
test_gentable_finish(indigo_cxn_id_t cxn_id, void *table_priv)
{
    struct test_table *table = table_priv;
    table->count_op++;
    table->count_finishes++;
    return INDIGO_ERROR_NONE;
}

static indigo_core_gentable_ops_t test_ops2 = {
    .add2 = test_gentable_add,
    .modify2 = test_gentable_modify,
    .del2 = test_gentable_delete,
    .get_stats = test_gentable_get_stats,
    .start = test_gentable_start,
    .finish = test_gentable_finish,
};

static indigo_error_t
test_gentable_add3(indigo_cxn_id_t cxn_id, void *table_priv, of_list_bsn_tlv_t *key, of_list_bsn_tlv_t *value, void **entry_priv, of_desc_str_t err_txt)
{
    struct test_table *table = table_priv;
    table->count_op++;
    table->count_add++;

    /* fail every other time */
    if (table->count_add % 2 == 1) {
        char fmt[] = "add failure %d";
      
        sprintf(err_txt, fmt, table->count_add);
        return INDIGO_ERROR_PARAM;
    }
    return INDIGO_ERROR_NONE;
}

static indigo_error_t
test_gentable_modify3(indigo_cxn_id_t cxn_id, void *table_priv, void *entry_priv, of_list_bsn_tlv_t *key, of_list_bsn_tlv_t *value, of_desc_str_t err_txt)
{
    struct test_table *table = table_priv;
    table->count_op++;
    table->count_modify++;

    /* fail every other time */
    if (table->count_modify % 2 == 1) {
        char fmt[] = "modify failure %d";
        sprintf(err_txt, fmt, table->count_modify);
        return INDIGO_ERROR_PARAM;
    }
    return INDIGO_ERROR_NONE;
}

static indigo_error_t
test_gentable_delete3(indigo_cxn_id_t cxn_id, void *table_priv, void *entry_priv, of_list_bsn_tlv_t *key, of_desc_str_t err_txt)
{
    struct test_table *table = table_priv;
    table->count_op++;
    table->count_delete++;

    /* fail every other time */
    if (table->count_delete % 2 == 1) {
        char fmt[] = "delete failure %d";
        sprintf(err_txt, fmt, table->count_delete);
        return INDIGO_ERROR_PARAM;
    }
    return INDIGO_ERROR_NONE;
}

static indigo_core_gentable_ops_t test_ops3 = {
    .add3 = test_gentable_add3,
    .modify3 = test_gentable_modify3,
    .del3 = test_gentable_delete3,
    .get_stats = test_gentable_get_stats,
    .start = test_gentable_start,
    .finish = test_gentable_finish,
};

static void gentable_add4_async_timeout(void *cookie);
static void gentable_modify4_async_timeout(void *cookie);
static void gentable_del4_async_timeout(void *cookie);

typedef struct {
    indigo_core_op_context_t *op_ctx;
    void *priv;                    /* entry under operation */
    void *tmp_priv;                /* used by the add/modify */
    struct test_table *table_priv;    
} gt_async_op_data_t;

static void
gentable_add4_async_bt(void *cookie)
{
    gt_async_op_data_t *resume_params = cookie;
    struct test_table *table = resume_params->table_priv;
    of_desc_str_t err_txt = "async added";
    
    /* cancel timer */
    ind_soc_timer_event_unregister(gentable_add4_async_timeout, cookie);
    ind_soc_timer_event_unregister(gentable_add4_async_bt, cookie);

    /* copy new data to entry and free temp buffer */
    *(struct test_entry *)resume_params->priv = *(struct test_entry *)resume_params->tmp_priv;
    aim_free(resume_params->tmp_priv);

    /* call indigo resume function */
    table->count_add_pending--;
    table->count_added++;
    strcpy(bsn_err_txt, err_txt);
    indigo_core_gentable_entry_resume(resume_params->op_ctx,
                                      resume_params->priv,
                                      err_txt,
                                      INDIGO_ERROR_NONE);
    aim_free(cookie);
    /* object is freed in resume */
}

static void
gentable_modify4_async_bt(void *cookie)
{
    gt_async_op_data_t *resume_params = (gt_async_op_data_t *) cookie;
    struct test_table *table = resume_params->table_priv;
    of_desc_str_t err_txt = "async modified";

    /* cancel timer */
    ind_soc_timer_event_unregister(gentable_modify4_async_timeout, cookie);
    ind_soc_timer_event_unregister(gentable_modify4_async_bt, cookie);

    /* copy new data to entry and free temp buffer */
    *(struct test_entry *)resume_params->priv = *(struct test_entry *)resume_params->tmp_priv;
    aim_free(resume_params->tmp_priv);

    /* call indigo resume function */
    table->count_modify_pending--;
    table->count_modified++;
    strcpy(bsn_err_txt, err_txt);
    indigo_core_gentable_entry_resume(resume_params->op_ctx,
                                      resume_params->priv,
                                      err_txt,
                                      INDIGO_ERROR_NONE);
    aim_free(cookie);
    /* object is freed in resume */
}

static void
gentable_del4_async_bt(void *cookie)
{
    gt_async_op_data_t *resume_params = (gt_async_op_data_t *) cookie;
    struct test_table *table = resume_params->table_priv;
    of_desc_str_t err_txt = "async deleted";

    /* cancel timer */
    ind_soc_timer_event_unregister(gentable_del4_async_timeout, cookie);
    ind_soc_timer_event_unregister(gentable_del4_async_bt, cookie);

    /* call indigo resume function */
    table->count_del_pending--;
    table->count_deleted++;
    memset(resume_params->priv, 0, sizeof (struct test_entry));
    strcpy(bsn_err_txt, err_txt);
    indigo_core_gentable_entry_resume(resume_params->op_ctx,
                                      NULL,
                                      err_txt,
                                      INDIGO_ERROR_NONE);
    aim_free(cookie);
    /* object is freed in resume */
}

static void
gentable_add4_async_timeout(void *cookie)
{
    gt_async_op_data_t *resume_params = (gt_async_op_data_t *) cookie;
    struct test_table *table = resume_params->table_priv;
    of_desc_str_t err_txt = "add timeout";

    /* cancel async op event */
    ind_soc_timer_event_unregister(gentable_add4_async_bt, cookie);
    ind_soc_timer_event_unregister(gentable_add4_async_timeout, cookie);

    /* call resume function */
    table->count_add_pending--;
    table->count_add_timeout++;
    if (resume_params->tmp_priv) { 
        aim_free(resume_params->tmp_priv);
    }
    strcpy(bsn_err_txt, err_txt);
    indigo_core_gentable_entry_resume(resume_params->op_ctx,
                                      resume_params->priv,
                                      err_txt,
                                      INDIGO_ERROR_TIME_OUT);
    aim_free(cookie);
    /* object is freed in resume */
}

static void
gentable_modify4_async_timeout(void *cookie)
{
    gt_async_op_data_t *resume_params = (gt_async_op_data_t *) cookie;
    struct test_table *table = resume_params->table_priv;
    of_desc_str_t err_txt = "modify timeout";

    /* cancel async op event */
    ind_soc_timer_event_unregister(gentable_modify4_async_bt, cookie);
    ind_soc_timer_event_unregister(gentable_modify4_async_timeout, cookie);

    /* call resume function */
    table->count_modify_pending--;
    table->count_modify_timeout++;
    if (resume_params->tmp_priv) { 
        aim_free(resume_params->tmp_priv);
    }
    strcpy(bsn_err_txt, err_txt);
    indigo_core_gentable_entry_resume(resume_params->op_ctx,
                                      resume_params->priv,
                                      err_txt,
                                      INDIGO_ERROR_TIME_OUT);
    aim_free(cookie);
    /* object is freed in resume */
}

static void
gentable_del4_async_timeout(void *cookie)
{
    gt_async_op_data_t *resume_params = (gt_async_op_data_t *) cookie;
    struct test_table *table = resume_params->table_priv;
    of_desc_str_t err_txt = "delete timeout";

    /* cancel timer */
    ind_soc_timer_event_unregister(gentable_del4_async_timeout, cookie);
    ind_soc_timer_event_unregister(gentable_del4_async_bt, cookie);

    /* call indigo resume function */
    table->count_del_pending--;
    table->count_del_timeout++;
    strcpy(bsn_err_txt, err_txt);
    indigo_core_gentable_entry_resume(resume_params->op_ctx,
                                      NULL,
                                      err_txt,
                                      INDIGO_ERROR_TIME_OUT);
    aim_free(cookie);
    /* object is freed in resume */
}

static indigo_error_t
test_gentable_add4(
    indigo_cxn_id_t cxn_id,
    void *table_priv, of_list_bsn_tlv_t *key, of_list_bsn_tlv_t *value, void **entry_priv, of_desc_str_t err_txt,
    void *op_ctx1)
{
    indigo_core_op_context_t *op_ctx = (indigo_core_op_context_t *)op_ctx1;
    struct test_table *table = table_priv;
    of_port_no_t port;
    struct test_entry *entry, *tmp_entry;

    /* get port - index of the table->entries*/
    parse_key(key, &port);

    AIM_TRUE_OR_DIE(port < NUM_ENTRIES);

    entry = &table->entries[port];

    tmp_entry = aim_zmalloc(sizeof(*tmp_entry));

    /* get value */
    parse_value(value, &tmp_entry->mac);

    table->count_op++;
    table->count_add++;
    gt_async_op_data_t *resume_params = aim_zmalloc(sizeof(*resume_params));

    resume_params->op_ctx = (void *) op_ctx;
    resume_params->table_priv = table_priv;
    resume_params->priv = entry;
    resume_params->tmp_priv = tmp_entry;

    /* register timer */
    ind_soc_timer_event_register(gentable_add4_async_timeout, (void *)resume_params,
                                 async_timeout);

    /* Test async operation */
    ind_soc_timer_event_register(gentable_add4_async_bt, (void *)resume_params,
                                 async_delay);
    table->count_add_pending++;
    return INDIGO_ERROR_PENDING;
}

static indigo_error_t
test_gentable_modify4(
    indigo_cxn_id_t cxn_id,
    void *table_priv, void *entry_priv, of_list_bsn_tlv_t *key, of_list_bsn_tlv_t *value, of_desc_str_t err_txt,
    void *op_ctx1)
{
    indigo_core_op_context_t *op_ctx = (indigo_core_op_context_t *)op_ctx1;
    struct test_table *table = table_priv;
    of_port_no_t port;
    struct test_entry *entry, *tmp_entry;

    /* get port - index of the table->entries*/
    parse_key(key, &port);

    AIM_TRUE_OR_DIE(port < NUM_ENTRIES);

    entry = &table->entries[port];
    AIM_TRUE_OR_DIE(entry_priv == entry);

    tmp_entry = aim_zmalloc(sizeof(*tmp_entry));
    /* copy existing entry content */
    *tmp_entry = *((struct test_entry *)entry_priv);    

    /* get value */
    parse_value(value, &tmp_entry->mac);

    table->count_op++;
    table->count_modify++;
    gt_async_op_data_t *resume_params = aim_zmalloc(sizeof(*resume_params));

    resume_params->op_ctx = (void *) op_ctx;
    resume_params->table_priv = table_priv;
    resume_params->priv = entry;
    resume_params->tmp_priv = tmp_entry;

    /* register timer */
    ind_soc_timer_event_register(gentable_modify4_async_timeout, (void *)resume_params,
                                 async_timeout);

    /* Test async operation */
    ind_soc_timer_event_register(gentable_modify4_async_bt, (void *)resume_params,
                                 async_delay);
    table->count_modify_pending++;
    return INDIGO_ERROR_PENDING;
}

static indigo_error_t
test_gentable_delete4(
    indigo_cxn_id_t cxn_id,
    void *table_priv, void *entry_priv, of_list_bsn_tlv_t *key, of_desc_str_t err_txt,
    void *op_ctx1)
{
    indigo_core_op_context_t *op_ctx = (indigo_core_op_context_t *)op_ctx1;
    struct test_table *table = table_priv;
    of_port_no_t port;
    struct test_entry *entry;

    /* get port - index of the table->entries*/
    parse_key(key, &port);

    AIM_TRUE_OR_DIE(port < NUM_ENTRIES);

    entry = &table->entries[port];
    AIM_TRUE_OR_DIE(entry_priv == entry);

    table->count_op++;
    table->count_delete++;

    gt_async_op_data_t *resume_params = aim_zmalloc(sizeof(*resume_params));

    resume_params->op_ctx = (void *) op_ctx;
    resume_params->table_priv = table_priv;
    resume_params->priv = entry;

    /* register timer */
    ind_soc_timer_event_register(gentable_del4_async_timeout, (void *)resume_params,
                                 async_timeout);

    /* Test async operation */
    ind_soc_timer_event_register(gentable_del4_async_bt, (void *)resume_params,
                                 async_delay);
    table->count_del_pending++;
    return INDIGO_ERROR_PENDING;
}

static indigo_core_gentable_ops_t test_ops4 = {
    .add4 = test_gentable_add4,
    .modify4 = test_gentable_modify4,
    .del4 = test_gentable_delete4,
    .get_stats = test_gentable_get_stats,
#if 0
    .start = test_gentable_start,
    .finish = test_gentable_finish,
#else
    .start = NULL,
    .finish = NULL,
#endif
};
