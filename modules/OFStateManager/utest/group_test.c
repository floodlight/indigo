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

static void do_add(uint32_t id, uint8_t type, uint32_t port);
static void do_modify(uint32_t id, uint8_t type, uint32_t port) __attribute__((unused));
static void do_delete(uint32_t id) __attribute__((unused));
static void do_entry_stats(void) __attribute__((unused));

struct test_entry_stats;

struct test_entry {
    uint32_t magic;
    uint32_t port;
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
};

struct test_table_stats {
    int count_op;
    int count_add;
    int count_modify;
    int count_delete;
    int count_stats;
    struct test_entry_stats entries[NUM_ENTRIES];
};

static struct test_table table;
static struct test_table_stats stats;

static indigo_core_group_table_ops_t test_ops;

static inline uint32_t
entry_id_to_group_id(uint32_t entry_id)
{
    return (TABLE_ID << 24) | entry_id;
}

static inline uint32_t
group_id_to_entry_id(uint32_t group_id)
{
    AIM_TRUE_OR_DIE(group_id >> 24 == TABLE_ID);
    return group_id & 0xffffff;
}

static int
test_group_table_entry_add(void)
{
    memset(&table, 0, sizeof(table));
    memset(&stats, 0, sizeof(stats));
    table.magic = TABLE_MAGIC;
    indigo_core_group_table_register(TABLE_ID, "test", &test_ops, &table);
    AIM_TRUE_OR_DIE(stats.count_op == 0);

    memset(&stats, 0, sizeof(stats));
    do_add(1, OF_GROUP_TYPE_SELECT, 1000);
    do_add(2, OF_GROUP_TYPE_SELECT, 2000);
    AIM_TRUE_OR_DIE(table.entries[1].port == 1000);
    AIM_TRUE_OR_DIE(stats.entries[1].count_add == 1);
    AIM_TRUE_OR_DIE(stats.entries[1].count_op == 1);
    AIM_TRUE_OR_DIE(table.entries[2].port == 2000);
    AIM_TRUE_OR_DIE(stats.entries[2].count_add == 1);
    AIM_TRUE_OR_DIE(stats.entries[2].count_op == 1);
    AIM_TRUE_OR_DIE(stats.count_add == 2);
    AIM_TRUE_OR_DIE(stats.count_op == 2);

    memset(&stats, 0, sizeof(stats));
    indigo_core_group_table_unregister(TABLE_ID);
    AIM_TRUE_OR_DIE(stats.entries[1].count_delete == 1);
    AIM_TRUE_OR_DIE(stats.entries[1].count_op == 1);
    AIM_TRUE_OR_DIE(stats.entries[2].count_delete == 1);
    AIM_TRUE_OR_DIE(stats.entries[2].count_op == 1);
    AIM_TRUE_OR_DIE(stats.count_delete == 2);
    AIM_TRUE_OR_DIE(stats.count_op == 2);

    return TEST_PASS;
}

static int
test_group_table_entry_delete(void)
{
    memset(&table, 0, sizeof(table));
    memset(&stats, 0, sizeof(stats));
    table.magic = TABLE_MAGIC;
    indigo_core_group_table_register(TABLE_ID, "test", &test_ops, &table);
    AIM_TRUE_OR_DIE(stats.count_op == 0);

    memset(&stats, 0, sizeof(stats));
    do_add(1, OF_GROUP_TYPE_SELECT, 1000);
    do_add(2, OF_GROUP_TYPE_SELECT, 2000);
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
    indigo_core_group_table_unregister(TABLE_ID);
    AIM_TRUE_OR_DIE(stats.count_op == 0);

    return TEST_PASS;
}

static int
test_group_table_entry_modify(void)
{
    memset(&table, 0, sizeof(table));
    memset(&stats, 0, sizeof(stats));
    table.magic = TABLE_MAGIC;
    indigo_core_group_table_register(TABLE_ID, "test", &test_ops, &table);
    AIM_TRUE_OR_DIE(stats.count_op == 0);

    do_add(1, OF_GROUP_TYPE_SELECT, 1000);
    do_add(2, OF_GROUP_TYPE_SELECT, 2000);

    memset(&stats, 0, sizeof(stats));
    do_modify(1, OF_GROUP_TYPE_SELECT, 3000);
    AIM_TRUE_OR_DIE(table.entries[1].port == 3000);
    AIM_TRUE_OR_DIE(stats.entries[1].count_modify == 1);
    AIM_TRUE_OR_DIE(stats.entries[1].count_op == 1);
    AIM_TRUE_OR_DIE(stats.count_modify == 1);
    AIM_TRUE_OR_DIE(stats.count_op == 1);

    memset(&stats, 0, sizeof(stats));
    indigo_core_group_table_unregister(TABLE_ID);
    AIM_TRUE_OR_DIE(stats.count_op == 2);

    return TEST_PASS;
}

/* Changing the type becomes a delete+add */
static int
test_group_table_entry_modify_type(void)
{
    memset(&table, 0, sizeof(table));
    memset(&stats, 0, sizeof(stats));
    table.magic = TABLE_MAGIC;
    indigo_core_group_table_register(TABLE_ID, "test", &test_ops, &table);
    AIM_TRUE_OR_DIE(stats.count_op == 0);

    do_add(1, OF_GROUP_TYPE_SELECT, 1000);
    do_add(2, OF_GROUP_TYPE_SELECT, 2000);

    memset(&stats, 0, sizeof(stats));
    do_modify(1, OF_GROUP_TYPE_ALL, 3000);
    AIM_TRUE_OR_DIE(table.entries[1].port == 3000);
    AIM_TRUE_OR_DIE(stats.entries[1].count_add == 1);
    AIM_TRUE_OR_DIE(stats.entries[1].count_delete == 1);
    AIM_TRUE_OR_DIE(stats.entries[1].count_op == 2);
    AIM_TRUE_OR_DIE(stats.count_add == 1);
    AIM_TRUE_OR_DIE(stats.count_delete == 1);
    AIM_TRUE_OR_DIE(stats.count_op == 2);

    memset(&stats, 0, sizeof(stats));
    indigo_core_group_table_unregister(TABLE_ID);
    AIM_TRUE_OR_DIE(stats.count_op == 2);

    return TEST_PASS;
}

/* Duplicate add becomes a modify */
static int
test_group_table_entry_dup_add(void)
{
    memset(&table, 0, sizeof(table));
    memset(&stats, 0, sizeof(stats));
    table.magic = TABLE_MAGIC;
    indigo_core_group_table_register(TABLE_ID, "test", &test_ops, &table);
    AIM_TRUE_OR_DIE(stats.count_op == 0);

    do_add(1, OF_GROUP_TYPE_SELECT, 1000);
    do_add(2, OF_GROUP_TYPE_SELECT, 2000);

    memset(&stats, 0, sizeof(stats));
    do_add(1, OF_GROUP_TYPE_SELECT, 3000);
    AIM_TRUE_OR_DIE(table.entries[1].port == 3000);
    AIM_TRUE_OR_DIE(stats.entries[1].count_modify == 1);
    AIM_TRUE_OR_DIE(stats.entries[1].count_op == 1);
    AIM_TRUE_OR_DIE(stats.count_modify == 1);
    AIM_TRUE_OR_DIE(stats.count_op == 1);

    memset(&stats, 0, sizeof(stats));
    indigo_core_group_table_unregister(TABLE_ID);
    AIM_TRUE_OR_DIE(stats.count_op == 2);

    return TEST_PASS;
}

static int
test_group_table_entry_stats(void)
{
    memset(&table, 0, sizeof(table));
    memset(&stats, 0, sizeof(stats));
    table.magic = TABLE_MAGIC;
    indigo_core_group_table_register(TABLE_ID, "test", &test_ops, &table);
    AIM_TRUE_OR_DIE(stats.count_op == 0);

    memset(&stats, 0, sizeof(stats));
    do_add(1, OF_GROUP_TYPE_SELECT, 1000);
    do_add(2, OF_GROUP_TYPE_SELECT, 2000);
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
    indigo_core_group_table_unregister(TABLE_ID);
    AIM_TRUE_OR_DIE(stats.count_delete == 2);
    AIM_TRUE_OR_DIE(stats.count_op == 2);

    return TEST_PASS;
}

static int
test_group_table_entry_refcount(void)
{
    memset(&table, 0, sizeof(table));
    memset(&stats, 0, sizeof(stats));
    table.magic = TABLE_MAGIC;
    indigo_core_group_table_register(TABLE_ID, "test", &test_ops, &table);
    AIM_TRUE_OR_DIE(stats.count_op == 0);

    memset(&stats, 0, sizeof(stats));
    do_add(1, OF_GROUP_TYPE_SELECT, 1000);
    AIM_TRUE_OR_DIE(stats.count_add == 1);
    AIM_TRUE_OR_DIE(stats.count_op == 1);

    void *priv = indigo_core_group_acquire(entry_id_to_group_id(1));
    AIM_TRUE_OR_DIE(priv == &table.entries[1]);

    AIM_TRUE_OR_DIE(indigo_core_group_lookup(entry_id_to_group_id(1)) == &table.entries[1]);

    memset(&stats, 0, sizeof(stats));
    do_delete(1);
    AIM_TRUE_OR_DIE(stats.count_op == 0);

    indigo_core_group_release(entry_id_to_group_id(1));

    memset(&stats, 0, sizeof(stats));
    do_delete(1);
    AIM_TRUE_OR_DIE(stats.entries[1].count_delete == 1);
    AIM_TRUE_OR_DIE(stats.entries[1].count_op == 1);
    AIM_TRUE_OR_DIE(stats.count_delete == 1);
    AIM_TRUE_OR_DIE(stats.count_op == 1);

    AIM_TRUE_OR_DIE(indigo_core_group_lookup(entry_id_to_group_id(1)) == NULL);

    memset(&stats, 0, sizeof(stats));
    indigo_core_group_table_unregister(TABLE_ID);
    AIM_TRUE_OR_DIE(stats.count_op == 0);

    return TEST_PASS;
}

int
test_group_table(void)
{
    RUN_TEST(group_table_entry_add);
    RUN_TEST(group_table_entry_delete);
    RUN_TEST(group_table_entry_modify);
    RUN_TEST(group_table_entry_modify_type);
    RUN_TEST(group_table_entry_dup_add);
    RUN_TEST(group_table_entry_stats);
    RUN_TEST(group_table_entry_refcount);
    return TEST_PASS;
}

/* Utility functions to send OpenFlow messages */

static void
do_add(uint32_t entry_id, uint8_t type, uint32_t port)
{
    of_object_t *obj = of_group_add_new(OF_VERSION_1_3);
    of_group_add_xid_set(obj, 0x12345678);
    of_group_add_group_id_set(obj, entry_id_to_group_id(entry_id));
    of_group_add_group_type_set(obj, type);

    of_list_bucket_t buckets;
    of_group_add_buckets_bind(obj, &buckets);
    of_bucket_t bucket;
    of_bucket_init(&bucket, OF_VERSION_1_3, -1, 1);
    of_list_append_bind(&buckets, &bucket);
    of_bucket_watch_port_set(&bucket, port);

    handle_message(obj);
    do_barrier();
}

static void
do_modify(uint32_t entry_id, uint8_t type, uint32_t port)
{
    of_object_t *obj = of_group_modify_new(OF_VERSION_1_3);
    of_group_modify_xid_set(obj, 0x12345678);
    of_group_modify_group_id_set(obj, entry_id_to_group_id(entry_id));
    of_group_modify_group_type_set(obj, type);

    of_list_bucket_t buckets;
    of_group_modify_buckets_bind(obj, &buckets);
    of_bucket_t bucket;
    of_bucket_init(&bucket, OF_VERSION_1_3, -1, 1);
    of_list_append_bind(&buckets, &bucket);
    of_bucket_watch_port_set(&bucket, port);

    handle_message(obj);
    do_barrier();
}

static void
do_delete(uint32_t entry_id)
{
    of_object_t *obj = of_group_delete_new(OF_VERSION_1_3);
    of_group_delete_xid_set(obj, 0x12345678);
    of_group_delete_group_id_set(obj, entry_id_to_group_id(entry_id));

    handle_message(obj);
    do_barrier();
}

static void
do_entry_stats(void)
{
    of_object_t *obj = of_group_stats_request_new(OF_VERSION_1_3);
    of_group_stats_request_xid_set(obj, 0x12345678);
    of_group_stats_request_group_id_set(obj, OF_GROUP_ALL);

    handle_message(obj);
    do_barrier();
}


/* Table operations */

static indigo_error_t
op_entry_create(void *table_priv, indigo_cxn_id_t cxn_id,
                uint32_t group_id, uint8_t group_type, of_list_bucket_t *buckets,
                void **entry_priv)
{
    struct test_table *table = table_priv;
    AIM_TRUE_OR_DIE(table->magic == TABLE_MAGIC);

    uint32_t entry_id = group_id_to_entry_id(group_id);

    AIM_TRUE_OR_DIE(entry_id < NUM_ENTRIES);

    struct test_entry *entry = &table->entries[entry_id];
    entry->magic = ENTRY_MAGIC;
    entry->stats = &stats.entries[entry_id];

    entry->port = -1;

    of_bucket_t bucket;
    int rv;
    OF_LIST_BUCKET_ITER(buckets, &bucket, rv) {
        of_bucket_watch_port_get(&bucket, &entry->port);
    }

    stats.count_op++;
    stats.count_add++;

    entry->stats->count_op++;
    entry->stats->count_add++;

    *entry_priv = entry;
    return INDIGO_ERROR_NONE;
}

static indigo_error_t
op_entry_modify(void *table_priv, indigo_cxn_id_t cxn_id,
                void *entry_priv, of_list_bucket_t *buckets)
{
    struct test_table *table = table_priv;
    AIM_TRUE_OR_DIE(table->magic == TABLE_MAGIC);
    struct test_entry *entry = entry_priv;
    AIM_TRUE_OR_DIE(entry->magic == ENTRY_MAGIC);

    entry->port = -1;

    of_bucket_t bucket;
    int rv;
    OF_LIST_BUCKET_ITER(buckets, &bucket, rv) {
        of_bucket_watch_port_get(&bucket, &entry->port);
    }

    stats.count_op++;
    stats.count_modify++;

    entry->stats->count_op++;
    entry->stats->count_modify++;

    return INDIGO_ERROR_NONE;
}

static indigo_error_t
op_entry_delete(void *table_priv, indigo_cxn_id_t cxn_id, void *entry_priv)
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
op_entry_stats_get(void *table_priv,
                   void *entry_priv, of_group_stats_entry_t *group_stats)
{
    struct test_table *table = table_priv;
    AIM_TRUE_OR_DIE(table->magic == TABLE_MAGIC);
    struct test_entry *entry = entry_priv;
    AIM_TRUE_OR_DIE(entry->magic == ENTRY_MAGIC);

    of_group_stats_entry_packet_count_set(group_stats, 1);

    stats.count_op++;
    stats.count_stats++;

    entry->stats->count_op++;
    entry->stats->count_stats++;

    return INDIGO_ERROR_NONE;
}

static indigo_core_group_table_ops_t test_ops = {
    op_entry_create,
    op_entry_modify,
    op_entry_delete,
    op_entry_stats_get,
};
