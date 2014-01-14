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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <loci/loci.h>
#include <locitest/unittest.h>
#include <locitest/test_common.h>
#include <SocketManager/socketmanager.h>

#define TABLE_ID 1
#define NUM_ENTRIES 10

extern void handle_message(of_object_t *obj);
extern int do_barrier(void);

static void do_add(uint32_t port, of_mac_addr_t mac, uint8_t csum_hi);
static void do_delete(uint32_t port);
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
    struct test_entry entries[NUM_ENTRIES];
};

static struct test_table table;

static indigo_core_gentable_ops_t test_ops;

static const of_mac_addr_t mac1 = { { 0xab, 0xcd, 0xef, 0xff, 0xff, 0x01 } };
static const of_mac_addr_t mac2 = { { 0xab, 0xcd, 0xef, 0xff, 0xff, 0x02 } };
static const of_mac_addr_t mac3 = { { 0xab, 0xcd, 0xef, 0xff, 0xff, 0x03 } };

static int
test_gentable_entry_add(void)
{
    indigo_core_gentable_t *gentable;
    of_table_name_t name = "gentable 0";

    memset(&table, 0, sizeof(table));
    indigo_core_gentable_register(name, &test_ops, &table, 10, 8, &gentable);
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

int
test_gentable(void)
{
    RUN_TEST(gentable_entry_add);
    RUN_TEST(gentable_entry_delete);
    RUN_TEST(gentable_entry_modify);
    RUN_TEST(gentable_clear);
    RUN_TEST(gentable_entry_stats);
    RUN_TEST(gentable_long_running_task);
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
do_clear()
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
    of_bsn_tlv_t tlv;
    int loop_rv = 0;
    int count = 0;

    OF_LIST_BSN_TLV_ITER(key, &tlv, loop_rv) {
        count++;
        if (tlv.header.object_id == OF_BSN_TLV_PORT) {
            of_bsn_tlv_port_value_get(&tlv.port, port);
        } else {
            AIM_DIE("unexpected TLV");
        }
    }

    AIM_TRUE_OR_DIE(count == 1);
}

static void
parse_value(of_list_bsn_tlv_t *value, of_mac_addr_t *mac)
{
    of_bsn_tlv_t tlv;
    int loop_rv = 0;
    int count = 0;

    OF_LIST_BSN_TLV_ITER(value, &tlv, loop_rv) {
        count++;
        if (tlv.header.object_id == OF_BSN_TLV_MAC) {
            of_bsn_tlv_mac_value_get(&tlv.mac, mac);
        } else {
            AIM_DIE("unexpected TLV");
        }
    }

    AIM_TRUE_OR_DIE(count == 1);
}

static indigo_error_t
test_gentable_add(void *table_priv, of_list_bsn_tlv_t *key, of_list_bsn_tlv_t *value, void **entry_priv)
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
test_gentable_modify(void *table_priv, void *entry_priv, of_list_bsn_tlv_t *key, of_list_bsn_tlv_t *value)
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
test_gentable_delete(void *table_priv, void *entry_priv, of_list_bsn_tlv_t *key)
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
    test_gentable_add,
    test_gentable_modify,
    test_gentable_delete,
    test_gentable_get_stats,
};
