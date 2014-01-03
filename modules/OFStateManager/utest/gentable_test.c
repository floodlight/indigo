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

#define NUM_TABLES 16
#define NUM_ENTRIES 10

static void do_add(uint16_t table_id, uint32_t port, of_mac_addr_t mac);
static void do_delete(uint16_t table_id, uint32_t port);
static void do_clear(uint16_t table_id);
static void do_entry_stats(uint16_t table_id);
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

static struct test_table tables[NUM_TABLES];

static indigo_core_gentable_ops_t test_ops;

static const of_mac_addr_t mac1 = { { 0xab, 0xcd, 0xef, 0xff, 0xff, 0x01 } };
static const of_mac_addr_t mac2 = { { 0xab, 0xcd, 0xef, 0xff, 0xff, 0x02 } };
static const of_mac_addr_t mac3 = { { 0xab, 0xcd, 0xef, 0xff, 0xff, 0x03 } };

static int
test_gentable_register(void)
{
    int i;
    indigo_core_gentable_t *gentables[NUM_TABLES];

    for (i = 0; i < NUM_TABLES; i++) {
        of_table_name_t name;
        snprintf(name, sizeof(name), "gentable %d", i);
        indigo_core_gentable_register(name, &test_ops, &tables[i], 10, 8, &gentables[i]);
    }

    for (i = 0; i < NUM_TABLES; i++) {
        indigo_core_gentable_unregister(gentables[i]);
    }

    return TEST_PASS;
}

static int
test_gentable_entry_add(void)
{
    indigo_core_gentable_t *gentable;
    of_table_name_t name = "gentable 0";

    memset(tables, 0, sizeof(tables));
    indigo_core_gentable_register(name, &test_ops, &tables[0], 10, 8, &gentable);
    AIM_TRUE_OR_DIE(tables[0].count_op == 0);

    memset(tables, 0, sizeof(tables));
    do_add(0, 1, mac1);
    do_add(0, 2, mac2);
    AIM_TRUE_OR_DIE(!memcmp(&tables[0].entries[1].mac, &mac1, sizeof(of_mac_addr_t)));
    AIM_TRUE_OR_DIE(tables[0].entries[1].count_add == 1);
    AIM_TRUE_OR_DIE(tables[0].entries[1].count_op == 1);
    AIM_TRUE_OR_DIE(!memcmp(&tables[0].entries[2].mac, &mac2, sizeof(of_mac_addr_t)));
    AIM_TRUE_OR_DIE(tables[0].entries[2].count_add == 1);
    AIM_TRUE_OR_DIE(tables[0].entries[2].count_op == 1);
    AIM_TRUE_OR_DIE(tables[0].count_add == 2);
    AIM_TRUE_OR_DIE(tables[0].count_op == 2);

    memset(tables, 0, sizeof(tables));
    indigo_core_gentable_unregister(gentable);
    AIM_TRUE_OR_DIE(tables[0].entries[1].count_delete == 1);
    AIM_TRUE_OR_DIE(tables[0].entries[1].count_op == 1);
    AIM_TRUE_OR_DIE(tables[0].entries[2].count_delete == 1);
    AIM_TRUE_OR_DIE(tables[0].entries[2].count_op == 1);
    AIM_TRUE_OR_DIE(tables[0].count_delete == 2);
    AIM_TRUE_OR_DIE(tables[0].count_op == 2);

    return TEST_PASS;
}

static int
test_gentable_entry_delete(void)
{
    indigo_core_gentable_t *gentable;
    of_table_name_t name = "gentable 0";

    memset(tables, 0, sizeof(tables));
    indigo_core_gentable_register(name, &test_ops, &tables[0], 10, 8, &gentable);
    AIM_TRUE_OR_DIE(tables[0].count_op == 0);

    memset(tables, 0, sizeof(tables));
    do_add(0, 1, mac1);
    do_add(0, 2, mac2);

    memset(tables, 0, sizeof(tables));
    do_delete(0, 1);
    AIM_TRUE_OR_DIE(tables[0].entries[1].count_delete == 1);
    AIM_TRUE_OR_DIE(tables[0].entries[1].count_op == 1);
    AIM_TRUE_OR_DIE(tables[0].count_delete == 1);
    AIM_TRUE_OR_DIE(tables[0].count_op == 1);

    memset(tables, 0, sizeof(tables));
    do_delete(0, 2);
    AIM_TRUE_OR_DIE(tables[0].entries[2].count_delete == 1);
    AIM_TRUE_OR_DIE(tables[0].entries[2].count_op == 1);
    AIM_TRUE_OR_DIE(tables[0].count_delete == 1);
    AIM_TRUE_OR_DIE(tables[0].count_op == 1);

    memset(tables, 0, sizeof(tables));
    indigo_core_gentable_unregister(gentable);
    AIM_TRUE_OR_DIE(tables[0].count_op == 0);

    return TEST_PASS;
}

static int
test_gentable_entry_modify(void)
{
    indigo_core_gentable_t *gentable;
    of_table_name_t name = "gentable 0";

    memset(tables, 0, sizeof(tables));
    indigo_core_gentable_register(name, &test_ops, &tables[0], 10, 8, &gentable);
    AIM_TRUE_OR_DIE(tables[0].count_op == 0);

    do_add(0, 1, mac1);
    do_add(0, 2, mac2);

    memset(tables, 0, sizeof(tables));
    do_add(0, 1, mac3);
    AIM_TRUE_OR_DIE(!memcmp(&tables[0].entries[1].mac, &mac3, sizeof(of_mac_addr_t)));
    AIM_TRUE_OR_DIE(tables[0].entries[1].count_modify == 1);
    AIM_TRUE_OR_DIE(tables[0].entries[1].count_op == 1);
    AIM_TRUE_OR_DIE(tables[0].count_modify == 1);
    AIM_TRUE_OR_DIE(tables[0].count_op == 1);

    memset(tables, 0, sizeof(tables));
    indigo_core_gentable_unregister(gentable);
    AIM_TRUE_OR_DIE(tables[0].count_op == 2);

    return TEST_PASS;
}

static int
test_gentable_clear(void)
{
    indigo_core_gentable_t *gentable;
    of_table_name_t name = "gentable 0";

    memset(tables, 0, sizeof(tables));
    indigo_core_gentable_register(name, &test_ops, &tables[0], 10, 8, &gentable);
    AIM_TRUE_OR_DIE(tables[0].count_op == 0);

    do_add(0, 1, mac1);
    do_add(0, 2, mac2);

    memset(tables, 0, sizeof(tables));
    do_clear(0);
    AIM_TRUE_OR_DIE(tables[0].entries[1].count_delete == 1);
    AIM_TRUE_OR_DIE(tables[0].entries[1].count_op == 1);
    AIM_TRUE_OR_DIE(tables[0].entries[2].count_delete == 1);
    AIM_TRUE_OR_DIE(tables[0].entries[2].count_op == 1);
    AIM_TRUE_OR_DIE(tables[0].count_delete == 2);
    AIM_TRUE_OR_DIE(tables[0].count_op == 2);

    memset(tables, 0, sizeof(tables));
    indigo_core_gentable_unregister(gentable);
    AIM_TRUE_OR_DIE(tables[0].count_op == 0);

    return TEST_PASS;
}

static int
test_gentable_entry_stats(void)
{
    indigo_core_gentable_t *gentable;
    of_table_name_t name = "gentable 0";

    memset(tables, 0, sizeof(tables));
    indigo_core_gentable_register(name, &test_ops, &tables[0], 10, 8, &gentable);
    AIM_TRUE_OR_DIE(tables[0].count_op == 0);

    do_add(0, 1, mac1);
    do_add(0, 2, mac2);

    memset(tables, 0, sizeof(tables));
    do_entry_stats(0);
    AIM_TRUE_OR_DIE(tables[0].entries[1].count_stats == 1);
    AIM_TRUE_OR_DIE(tables[0].entries[1].count_op == 1);
    AIM_TRUE_OR_DIE(tables[0].entries[2].count_stats == 1);
    AIM_TRUE_OR_DIE(tables[0].entries[2].count_op == 1);
    AIM_TRUE_OR_DIE(tables[0].count_stats == 2);
    AIM_TRUE_OR_DIE(tables[0].count_op == 2);

    memset(tables, 0, sizeof(tables));
    indigo_core_gentable_unregister(gentable);
    AIM_TRUE_OR_DIE(tables[0].count_op == 2);

    return TEST_PASS;
}

int
test_gentable(void)
{
    RUN_TEST(gentable_register);
    RUN_TEST(gentable_entry_add);
    RUN_TEST(gentable_entry_delete);
    RUN_TEST(gentable_entry_modify);
    RUN_TEST(gentable_clear);
    RUN_TEST(gentable_entry_stats);
    return TEST_PASS;
}


/* Utility functions to send OpenFlow messages */

static void
do_add(uint16_t table_id, uint32_t port, of_mac_addr_t mac)
{
    of_object_t *obj = of_bsn_gentable_entry_add_new(OF_VERSION_1_3);
    of_bsn_gentable_entry_add_xid_set(obj, 0x12345678);
    of_bsn_gentable_entry_add_table_id_set(obj, table_id);
    {
        of_checksum_128_t checksum = { 0xFEDCBA9876543210L, 0xFFEECCBBAA998877L };
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

    indigo_core_receive_controller_message(0, obj);
}

static void
do_delete(uint16_t table_id, uint32_t port)
{
    of_object_t *obj = of_bsn_gentable_entry_delete_new(OF_VERSION_1_3);
    of_bsn_gentable_entry_delete_xid_set(obj, 0x12345678);
    of_bsn_gentable_entry_delete_table_id_set(obj, table_id);
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

    indigo_core_receive_controller_message(0, obj);
}

static void
do_clear(uint16_t table_id)
{
    of_object_t *obj = of_bsn_gentable_clear_request_new(OF_VERSION_1_3);
    of_bsn_gentable_clear_request_xid_set(obj, 0x12345678);
    of_bsn_gentable_clear_request_table_id_set(obj, table_id);
    {
        of_checksum_128_t checksum = { 0x0, 0x0 };
        of_bsn_gentable_clear_request_checksum_set(obj, checksum);
        of_bsn_gentable_clear_request_checksum_mask_set(obj, checksum);
    }

    indigo_core_receive_controller_message(0, obj);
}

static void
do_entry_stats(uint16_t table_id)
{
    of_object_t *obj = of_bsn_gentable_entry_stats_request_new(OF_VERSION_1_3);
    of_bsn_gentable_entry_stats_request_xid_set(obj, 0x12345678);
    of_bsn_gentable_entry_stats_request_table_id_set(obj, table_id);
    {
        of_checksum_128_t checksum = { 0x0, 0x0 };
        of_bsn_gentable_entry_stats_request_checksum_set(obj, checksum);
        of_bsn_gentable_entry_stats_request_checksum_mask_set(obj, checksum);
    }

    indigo_core_receive_controller_message(0, obj);
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

    table->count_op++;
    table->count_stats++;

    entry->count_op++;
    entry->count_stats++;
}

static indigo_core_gentable_ops_t test_ops = {
    test_gentable_add,
    test_gentable_modify,
    test_gentable_delete,
    test_gentable_get_stats,
};
