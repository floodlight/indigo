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
#include <indigo/forwarding.h>

#define TABLE_ID 1
#define NUM_ENTRIES 10
#define TABLE_MAGIC 0xabc01234
#define ENTRY_MAGIC 0xdef56789

extern void handle_message(of_object_t *obj);
extern int do_barrier(void);

static void do_add(uint32_t port, uint32_t meter);
static void do_modify(uint32_t port, uint32_t meter) __attribute__((unused));
static void do_delete(uint32_t port) __attribute__((unused));
static void do_entry_stats(void) __attribute__((unused));

struct test_entry_stats;

struct test_entry {
    uint32_t magic;
    uint32_t meter;
    struct test_entry_stats *stats;
};

struct test_table {
    uint32_t magic;
    struct test_entry entries[NUM_ENTRIES];
};

struct test_entry_stats {
    int count_op;
    int count_add;
    int count_modify;
    int count_delete;
    int count_stats;
    int count_hit_status;
};

struct test_table_stats {
    int count_op;
    int count_add;
    int count_modify;
    int count_delete;
    int count_stats;
    int count_hit_status;
    struct test_entry_stats entries[NUM_ENTRIES];
};

static struct test_table table;
static struct test_table_stats stats;

static indigo_core_table_ops_t test_ops;

static int
test_table_entry_add(void)
{
    memset(&table, 0, sizeof(table));
    memset(&stats, 0, sizeof(stats));
    table.magic = TABLE_MAGIC;
    indigo_core_table_register(TABLE_ID, "test", &test_ops, &table);
    AIM_TRUE_OR_DIE(stats.count_op == 0);

    memset(&stats, 0, sizeof(stats));
    do_add(1, 1000);
    do_add(2, 2000);
    AIM_TRUE_OR_DIE(table.entries[1].meter == 1000);
    AIM_TRUE_OR_DIE(stats.entries[1].count_add == 1);
    AIM_TRUE_OR_DIE(stats.entries[1].count_op == 1);
    AIM_TRUE_OR_DIE(table.entries[2].meter == 2000);
    AIM_TRUE_OR_DIE(stats.entries[2].count_add == 1);
    AIM_TRUE_OR_DIE(stats.entries[2].count_op == 1);
    AIM_TRUE_OR_DIE(stats.count_add == 2);
    AIM_TRUE_OR_DIE(stats.count_op == 2);

    memset(&stats, 0, sizeof(stats));
    indigo_core_table_unregister(TABLE_ID);
    AIM_TRUE_OR_DIE(stats.entries[1].count_delete == 1);
    AIM_TRUE_OR_DIE(stats.entries[1].count_op == 1);
    AIM_TRUE_OR_DIE(stats.entries[2].count_delete == 1);
    AIM_TRUE_OR_DIE(stats.entries[2].count_op == 1);
    AIM_TRUE_OR_DIE(stats.count_delete == 2);
    AIM_TRUE_OR_DIE(stats.count_op == 2);

    return TEST_PASS;
}

static int
test_table_entry_delete(void)
{
    memset(&table, 0, sizeof(table));
    memset(&stats, 0, sizeof(stats));
    table.magic = TABLE_MAGIC;
    indigo_core_table_register(TABLE_ID, "test", &test_ops, &table);
    AIM_TRUE_OR_DIE(stats.count_op == 0);

    memset(&stats, 0, sizeof(stats));
    do_add(1, 1000);
    do_add(2, 2000);
    AIM_TRUE_OR_DIE(stats.count_add == 2);
    AIM_TRUE_OR_DIE(stats.count_op == 2);

    memset(&stats, 0, sizeof(stats));
    do_delete(1);
    AIM_TRUE_OR_DIE(stats.entries[1].count_delete == 1);
    AIM_TRUE_OR_DIE(stats.entries[1].count_op == 1);
    AIM_TRUE_OR_DIE(stats.count_delete == 1);
    AIM_TRUE_OR_DIE(stats.count_op == 1);

    memset(&stats, 0, sizeof(stats));
    do_delete(2);
    AIM_TRUE_OR_DIE(stats.entries[2].count_delete == 1);
    AIM_TRUE_OR_DIE(stats.entries[2].count_op == 1);
    AIM_TRUE_OR_DIE(stats.count_delete == 1);
    AIM_TRUE_OR_DIE(stats.count_op == 1);

    memset(&stats, 0, sizeof(stats));
    indigo_core_table_unregister(TABLE_ID);
    AIM_TRUE_OR_DIE(stats.count_op == 0);

    return TEST_PASS;
}

static int
test_table_entry_modify(void)
{
    memset(&table, 0, sizeof(table));
    memset(&stats, 0, sizeof(stats));
    table.magic = TABLE_MAGIC;
    indigo_core_table_register(TABLE_ID, "test", &test_ops, &table);
    AIM_TRUE_OR_DIE(stats.count_op == 0);

    do_add(1, 1000);
    do_add(2, 2000);

    memset(&stats, 0, sizeof(stats));
    do_modify(1, 3000);
    AIM_TRUE_OR_DIE(table.entries[1].meter == 3000);
    AIM_TRUE_OR_DIE(stats.entries[1].count_modify == 1);
    AIM_TRUE_OR_DIE(stats.entries[1].count_op == 1);
    AIM_TRUE_OR_DIE(stats.count_modify == 1);
    AIM_TRUE_OR_DIE(stats.count_op == 1);

    memset(&stats, 0, sizeof(stats));
    indigo_core_table_unregister(TABLE_ID);
    AIM_TRUE_OR_DIE(stats.count_op == 2);

    return TEST_PASS;
}

static int
test_table_entry_stats(void)
{
    memset(&table, 0, sizeof(table));
    memset(&stats, 0, sizeof(stats));
    table.magic = TABLE_MAGIC;
    indigo_core_table_register(TABLE_ID, "test", &test_ops, &table);
    AIM_TRUE_OR_DIE(stats.count_op == 0);

    memset(&stats, 0, sizeof(stats));
    do_add(1, 1000);
    do_add(2, 2000);
    AIM_TRUE_OR_DIE(stats.count_add == 2);
    AIM_TRUE_OR_DIE(stats.count_op == 2);

    memset(&stats, 0, sizeof(stats));
    do_entry_stats();
    AIM_TRUE_OR_DIE(stats.entries[1].count_stats == 1);
    AIM_TRUE_OR_DIE(stats.entries[1].count_op == 1);
    AIM_TRUE_OR_DIE(stats.entries[2].count_stats == 1);
    AIM_TRUE_OR_DIE(stats.entries[2].count_op == 1);
    AIM_TRUE_OR_DIE(stats.count_stats == 2);
    AIM_TRUE_OR_DIE(stats.count_op == 2);

    memset(&stats, 0, sizeof(stats));
    indigo_core_table_unregister(TABLE_ID);
    AIM_TRUE_OR_DIE(stats.count_delete == 2);
    AIM_TRUE_OR_DIE(stats.count_op == 2);

    return TEST_PASS;
}

int
test_table(void)
{
    RUN_TEST(table_entry_add);
    RUN_TEST(table_entry_delete);
    RUN_TEST(table_entry_modify);
    RUN_TEST(table_entry_stats);
    return TEST_PASS;
}

/* Utility functions to send OpenFlow messages */

static void
do_add(uint32_t port, uint32_t meter)
{
    of_object_t *obj = of_flow_add_new(OF_VERSION_1_3);
    of_flow_add_xid_set(obj, 0x12345678);
    of_flow_add_table_id_set(obj, TABLE_ID);
    {
        of_match_t match;
        memset(&match, 0, sizeof(match));
        match.fields.in_port = port;
        match.masks.in_port = ~0;
        if (of_flow_add_match_set(obj, &match) < 0) {
            AIM_DIE("unexpected failure in of_flow_add_match_set");
        }
    }
    {
        of_object_t *list = of_list_instruction_new(OF_VERSION_1_3);
        {
            of_object_t *inst = of_instruction_meter_new(OF_VERSION_1_3);
            of_instruction_meter_meter_id_set(inst, meter);
            of_list_append(list, inst);
            of_object_delete(inst);
        }
        AIM_TRUE_OR_DIE(of_flow_add_instructions_set(obj, list) == 0);
        of_object_delete(list);
    }

    handle_message(obj);
    do_barrier();
}

static void
do_modify(uint32_t port, uint32_t meter)
{
    of_object_t *obj = of_flow_modify_strict_new(OF_VERSION_1_3);
    of_flow_modify_strict_xid_set(obj, 0x12345678);
    of_flow_modify_strict_table_id_set(obj, TABLE_ID);
    {
        of_match_t match;
        memset(&match, 0, sizeof(match));
        match.fields.in_port = port;
        match.masks.in_port = ~0;
        if (of_flow_modify_strict_match_set(obj, &match) < 0) {
            AIM_DIE("unexpected failure in of_flow_modify_strict_match_set");
        }
    }
    {
        of_object_t *list = of_list_instruction_new(OF_VERSION_1_3);
        {
            of_object_t *inst = of_instruction_meter_new(OF_VERSION_1_3);
            of_instruction_meter_meter_id_set(inst, meter);
            of_list_append(list, inst);
            of_object_delete(inst);
        }
        AIM_TRUE_OR_DIE(of_flow_modify_strict_instructions_set(obj, list) == 0);
        of_object_delete(list);
    }

    handle_message(obj);
    do_barrier();
}

static void
do_delete(uint32_t port)
{
    of_object_t *obj = of_flow_delete_strict_new(OF_VERSION_1_3);
    of_flow_delete_strict_xid_set(obj, 0x12345678);
    of_flow_delete_strict_table_id_set(obj, TABLE_ID);
    {
        of_match_t match;
        memset(&match, 0, sizeof(match));
        match.fields.in_port = port;
        match.masks.in_port = ~0;
        if (of_flow_delete_match_set(obj, &match) < 0) {
            AIM_DIE("unexpected failure in of_flow_add_match_set");
        }
    }
    of_flow_delete_strict_out_port_set(obj, OF_PORT_DEST_WILDCARD);
    of_flow_delete_strict_out_group_set(obj, OF_GROUP_ANY);

    handle_message(obj);
    do_barrier();
}

static void
do_entry_stats()
{
    of_object_t *obj = of_flow_stats_request_new(OF_VERSION_1_3);
    of_flow_stats_request_xid_set(obj, 0x12345678);
    of_flow_stats_request_table_id_set(obj, TABLE_ID);
    of_flow_stats_request_out_port_set(obj, OF_PORT_DEST_WILDCARD);
    of_flow_stats_request_out_group_set(obj, OF_GROUP_ANY);

    handle_message(obj);
    do_barrier();
}


/* Table operations */

static indigo_error_t
op_entry_create(void *table_priv, of_flow_add_t *obj, indigo_cookie_t flow_id, void **entry_priv)
{
    struct test_table *table = table_priv;
    AIM_TRUE_OR_DIE(table->magic == TABLE_MAGIC);

    of_match_t match;
    if (of_flow_add_match_get(obj, &match) < 0) {
        AIM_DIE("unexpected failure in of_flow_add_match_get");
    }

    AIM_TRUE_OR_DIE(match.fields.in_port < NUM_ENTRIES);

    struct test_entry *entry = &table->entries[match.fields.in_port];
    entry->magic = ENTRY_MAGIC;
    entry->stats = &stats.entries[match.fields.in_port];

    entry->meter = -1;

    of_list_instruction_t instructions;
    of_flow_add_instructions_bind(obj, &instructions);
    of_instruction_t inst;
    int loop_rv;
    OF_LIST_INSTRUCTION_ITER(&instructions, &inst, loop_rv) {
        if (inst.header.object_id == OF_INSTRUCTION_METER) {
            of_instruction_meter_meter_id_get(&inst.meter, &entry->meter);
        }
    }

    stats.count_op++;
    stats.count_add++;

    entry->stats->count_op++;
    entry->stats->count_add++;

    *entry_priv = entry;
    return INDIGO_ERROR_NONE;
}

static indigo_error_t
op_entry_modify(void *table_priv, void *entry_priv, of_flow_modify_t *obj)
{
    struct test_table *table = table_priv;
    AIM_TRUE_OR_DIE(table->magic == TABLE_MAGIC);
    struct test_entry *entry = entry_priv;
    AIM_TRUE_OR_DIE(entry->magic == ENTRY_MAGIC);

    entry->meter = -1;

    of_list_instruction_t instructions;
    of_flow_add_instructions_bind(obj, &instructions);
    of_instruction_t inst;
    int loop_rv;
    OF_LIST_INSTRUCTION_ITER(&instructions, &inst, loop_rv) {
        if (inst.header.object_id == OF_INSTRUCTION_METER) {
            of_instruction_meter_meter_id_get(&inst.meter, &entry->meter);
        }
    }

    stats.count_op++;
    stats.count_modify++;

    entry->stats->count_op++;
    entry->stats->count_modify++;

    return INDIGO_ERROR_NONE;
}

static indigo_error_t
op_entry_delete(void *table_priv, void *entry_priv, indigo_fi_flow_stats_t *flow_stats)
{
    struct test_table *table = table_priv;
    AIM_TRUE_OR_DIE(table->magic == TABLE_MAGIC);
    struct test_entry *entry = entry_priv;
    AIM_TRUE_OR_DIE(entry->magic == ENTRY_MAGIC);

    stats.count_op++;
    stats.count_delete++;

    entry->stats->count_op++;
    entry->stats->count_delete++;

    return INDIGO_ERROR_NONE;
}

static indigo_error_t
op_entry_stats_get(void *table_priv, void *entry_priv, indigo_fi_flow_stats_t *flow_stats)
{
    struct test_table *table = table_priv;
    AIM_TRUE_OR_DIE(table->magic == TABLE_MAGIC);
    struct test_entry *entry = entry_priv;
    AIM_TRUE_OR_DIE(entry->magic == ENTRY_MAGIC);

    flow_stats->packets = 100;
    flow_stats->bytes = 101;

    stats.count_op++;
    stats.count_stats++;

    entry->stats->count_op++;
    entry->stats->count_stats++;

    return INDIGO_ERROR_NONE;
}

static indigo_error_t
op_entry_hit_status_get(void *table_priv, void *entry_priv, bool *hit_status)
{
    struct test_table *table = table_priv;
    AIM_TRUE_OR_DIE(table->magic == TABLE_MAGIC);
    struct test_entry *entry = entry_priv;
    AIM_TRUE_OR_DIE(entry->magic == ENTRY_MAGIC);

    stats.count_op++;
    stats.count_hit_status++;

    entry->stats->count_op++;
    entry->stats->count_hit_status++;

    *hit_status = true;

    return INDIGO_ERROR_NONE;
}

static indigo_core_table_ops_t test_ops = {
    op_entry_create,
    op_entry_modify,
    op_entry_delete,
    op_entry_stats_get,
    op_entry_hit_status_get,
};
