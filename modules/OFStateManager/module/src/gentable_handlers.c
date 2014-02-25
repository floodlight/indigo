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
 * @brief OpenFlow message handlers for gentable messages
 *
 * See detailed documentation in the Indigo architecture headers.
 *
 * TODO:
 *  - Reduce LOCI allocation overhead per entry.
 *  - Reuse stats entry during stats tasks.
 *  - Automatically resize key hashtable buckets.
 */

#include "ofstatemanager_log.h"

#include <OFStateManager/ofstatemanager_config.h>
#include <indigo/indigo.h>
#include <loci/loci.h>
#include "ofstatemanager_decs.h"
#include "ofstatemanager_int.h"
#include "handlers.h"
#include <murmur/murmur.h>

#define MAX_GENTABLES 16

struct ind_core_gentable_entry;

typedef void (*ind_core_gentable_iter_task_callback_f)(
    void *cookie, indigo_core_gentable_t *gentable, struct ind_core_gentable_entry *entry);

static indigo_core_gentable_t *find_gentable_by_id(uint32_t table_id);
static uint16_t alloc_table_id(void);
static uint8_t calc_checksum_buckets_shift(uint32_t checksum_buckets_size);
static struct ind_core_gentable_checksum_bucket *find_checksum_bucket(indigo_core_gentable_t *gentable, of_checksum_128_t *checksum);
static void update_checksum(of_checksum_128_t *dst, const of_checksum_128_t *src);
static uint32_t hash_key(of_list_bsn_tlv_t *key);
static list_head_t *find_key_bucket(indigo_core_gentable_t *gentable, uint32_t key_hash);
static indigo_error_t delete_entry(indigo_core_gentable_t *gentable, struct ind_core_gentable_entry *entry);
static struct ind_core_gentable_entry *find_entry_by_key(indigo_core_gentable_t *gentable, of_list_bsn_tlv_t *key);
static bool key_equality(of_list_bsn_tlv_t *a, of_list_bsn_tlv_t *b);
static indigo_error_t ind_core_gentable_spawn_iter_task(indigo_core_gentable_t *gentable, ind_core_gentable_iter_task_callback_f callback, void *cookie, int priority, of_checksum_128_t checksum_prefix, of_checksum_128_t checksum_mask);

struct ind_core_gentable_checksum_bucket {
    of_checksum_128_t checksum;
    list_head_t entries;
};

struct indigo_core_gentable {
    const indigo_core_gentable_ops_t *ops;
    void *priv;
    uint64_t generation_id;
    list_head_t *key_buckets;
    struct ind_core_gentable_checksum_bucket *checksum_buckets;
    uint32_t max_entries;
    uint32_t num_entries;
    uint32_t key_buckets_size; /* always a power of 2 */
    uint32_t checksum_buckets_size; /* always a power of 2 */
    uint16_t table_id;
    uint8_t checksum_buckets_shift; /* see checksum_buckets_shift */
    of_checksum_128_t checksum;
    of_table_name_t name;
};

struct ind_core_gentable_entry {
    list_links_t key_links;
    list_links_t checksum_links;
    uint32_t key_hash;
    void *priv;
    of_list_bsn_tlv_t *key;
    of_list_bsn_tlv_t *value;
    of_checksum_128_t checksum;
};

static indigo_core_gentable_t *gentables[MAX_GENTABLES];

/*
 * Used to fix an ABA problem with iteration.
 */
static uint64_t next_generation_id = 0;


/* Registration */

void
indigo_core_gentable_register(
    const char *name,
    const indigo_core_gentable_ops_t *ops,
    void *table_priv,
    uint32_t max_entries,
    uint32_t buckets_size,
    indigo_core_gentable_t **gentable_ptr)
{
    int i;

    AIM_TRUE_OR_DIE(ops->add != NULL);
    AIM_TRUE_OR_DIE(ops->modify != NULL);
    AIM_TRUE_OR_DIE(ops->del != NULL);
    AIM_TRUE_OR_DIE(ops->get_stats != NULL);

    struct indigo_core_gentable *gentable = aim_zmalloc(sizeof(*gentable));

    strncpy(gentable->name, name, sizeof(gentable->name));
    gentable->ops = ops;
    gentable->priv = table_priv;
    gentable->max_entries = max_entries;
    gentable->checksum_buckets_size = buckets_size;
    gentable->key_buckets_size = buckets_size;

    gentable->checksum_buckets_shift =
        calc_checksum_buckets_shift(gentable->checksum_buckets_size);

    gentable->table_id = alloc_table_id();
    gentable->generation_id = next_generation_id++;

    gentable->key_buckets = aim_malloc(sizeof(*gentable->key_buckets) *
                                       gentable->key_buckets_size);

    for (i = 0; i < gentable->key_buckets_size; i++) {
        list_init(&gentable->key_buckets[i]);
    }

    gentable->checksum_buckets = aim_malloc(sizeof(*gentable->checksum_buckets) *
                                            gentable->checksum_buckets_size);

    for (i = 0; i < gentable->checksum_buckets_size; i++) {
        struct ind_core_gentable_checksum_bucket *bucket =
            &gentable->checksum_buckets[i];
        bucket->checksum.lo = 0;
        bucket->checksum.hi = 0;
        list_init(&bucket->entries);
    }

    gentables[gentable->table_id] = gentable;
    *gentable_ptr = gentable;

    AIM_LOG_INFO("Registered gentable \"%s\" with table id %d",
                 gentable->name, gentable->table_id);
}

void
indigo_core_gentable_unregister(indigo_core_gentable_t *gentable)
{
    indigo_error_t rv;
    int i;

    AIM_TRUE_OR_DIE(gentables[gentable->table_id] == gentable);

    /* Delete all entries */
    for (i = 0; i < gentable->key_buckets_size; i++) {
        list_links_t *cur, *next;
        LIST_FOREACH_SAFE(&gentable->key_buckets[i], cur, next) {
            struct ind_core_gentable_entry *entry =
                container_of(cur, key_links, struct ind_core_gentable_entry);
            rv = delete_entry(gentable, entry);
            if (rv < 0) {
                AIM_LOG_ERROR("failed to delete %s gentable entry during unregister, leaking", gentable->name);
            }
        }
    }

    gentables[gentable->table_id] = NULL;

    aim_free(gentable->key_buckets);
    aim_free(gentable->checksum_buckets);
    aim_free(gentable);
}


/* OpenFlow message handlers */

void
ind_core_bsn_gentable_entry_add_handler(
    of_object_t *obj,
    indigo_cxn_id_t cxn_id)
{
    uint16_t table_id;
    indigo_core_gentable_t *gentable;
    of_list_bsn_tlv_t key, value;
    void *priv = NULL;
    indigo_error_t rv;
    struct ind_core_gentable_checksum_bucket *checksum_bucket;
    struct ind_core_gentable_entry *entry;

    of_bsn_gentable_entry_add_table_id_get(obj, &table_id);
    of_bsn_gentable_entry_add_key_bind(obj, &key);
    of_bsn_gentable_entry_add_value_bind(obj, &value);

    gentable = find_gentable_by_id(table_id);
    if (gentable == NULL) {
        AIM_LOG_ERROR("Nonexistent gentable id %d", table_id);
        indigo_cxn_send_error_reply(
            cxn_id, obj,
            OF_ERROR_TYPE_BAD_REQUEST,
            OF_REQUEST_FAILED_BAD_TABLE_ID);
        return;
    }

    entry = find_entry_by_key(gentable, &key);

    if (entry == NULL) {
        /* Adding a new entry */
        rv = gentable->ops->add(gentable->priv, &key, &value, &priv);
        if (rv != INDIGO_ERROR_NONE) {
            AIM_LOG_ERROR("%s gentable add failed: %s",
                          gentable->name, indigo_strerror(rv));
            goto error;
        }

        /* Allocate new entry */
        entry = aim_zmalloc(sizeof(*entry));
        entry->key = of_object_dup(&key);

        entry->key_hash = hash_key(&key);
        entry->priv = priv;

        /* Insert into key bucket */
        list_push(find_key_bucket(gentable, entry->key_hash), &entry->key_links);

        gentable->num_entries++;
    } else {
        /* Modifying an existing entry */
        rv = gentable->ops->modify(gentable->priv, entry->priv, &key, &value);
        if (rv != INDIGO_ERROR_NONE) {
            AIM_LOG_ERROR("%s gentable modify failed: %s",
                          gentable->name, indigo_strerror(rv));
            goto error;
        }

        of_object_delete(entry->value);

        /* Remove from old checksum bucket */
        checksum_bucket = find_checksum_bucket(gentable, &entry->checksum);
        list_remove(&entry->checksum_links);
        update_checksum(&checksum_bucket->checksum, &entry->checksum);

        /* Remove from table checksum */
        update_checksum(&gentable->checksum, &entry->checksum);
    }

    /* Update value and checksum */
    entry->value = of_object_dup(&value);
    of_bsn_gentable_entry_add_checksum_get(obj, &entry->checksum);

    /* Insert into checksum bucket */
    checksum_bucket = find_checksum_bucket(gentable, &entry->checksum);
    list_push(&checksum_bucket->entries, &entry->checksum_links);
    update_checksum(&checksum_bucket->checksum, &entry->checksum);

    /* Add to table checksum */
    update_checksum(&gentable->checksum, &entry->checksum);

    return;

error:
    /* Not a great error code but we don't have many options */
    indigo_cxn_send_error_reply(
        cxn_id, obj,
        OF_ERROR_TYPE_BAD_REQUEST,
        OF_REQUEST_FAILED_EPERM);
}

void
ind_core_bsn_gentable_entry_delete_handler(
    of_object_t *obj,
    indigo_cxn_id_t cxn_id)
{
    uint16_t table_id;
    indigo_core_gentable_t *gentable;
    of_list_bsn_tlv_t key;
    struct ind_core_gentable_entry *entry;
    indigo_error_t rv;

    of_bsn_gentable_entry_delete_table_id_get(obj, &table_id);
    of_bsn_gentable_entry_delete_key_bind(obj, &key);

    gentable = find_gentable_by_id(table_id);
    if (gentable == NULL) {
        AIM_LOG_ERROR("Nonexistent gentable id %d", table_id);
        indigo_cxn_send_error_reply(
            cxn_id, obj,
            OF_ERROR_TYPE_BAD_REQUEST,
            OF_REQUEST_FAILED_BAD_TABLE_ID);
        return;
    }

    entry = find_entry_by_key(gentable, &key);
    if (entry == NULL) {
        AIM_LOG_TRACE("Nonexistent %s gentable entry", gentable->name);
        return;
    }

    rv = delete_entry(gentable, entry);
    if (rv < 0) {
        AIM_LOG_ERROR("%s gentable delete failed: %s",
                      gentable->name, indigo_strerror(rv));
        indigo_cxn_send_error_reply(
            cxn_id, obj,
            OF_ERROR_TYPE_BAD_REQUEST,
            OF_REQUEST_FAILED_EPERM);
        return;
    }
}

struct ind_core_gentable_clear_state {
    indigo_cxn_id_t cxn_id;
    of_object_t *request;
    uint32_t error_count;
    uint32_t deleted_count;
};

static void
clear_iter(void *cookie, indigo_core_gentable_t *gentable,
           struct ind_core_gentable_entry *entry)
{
    struct ind_core_gentable_clear_state *state = cookie;

    if (entry != NULL) {
        indigo_error_t rv = delete_entry(gentable, entry);
        if (rv < 0) {
            state->error_count++;
        } else {
            state->deleted_count++;
        }
    } else {
        uint32_t xid;
        of_bsn_gentable_clear_request_xid_get(state->request, &xid);

        of_bsn_gentable_clear_reply_t *reply =
            of_bsn_gentable_clear_reply_new(state->request->version);
        of_bsn_gentable_clear_reply_xid_set(reply, xid);
        of_bsn_gentable_clear_reply_deleted_count_set(reply, state->deleted_count);
        of_bsn_gentable_clear_reply_error_count_set(reply, state->error_count);
        indigo_cxn_send_controller_message(state->cxn_id, reply);

        of_object_delete(state->request);
        aim_free(state);
    }
}

void
ind_core_bsn_gentable_clear_request_handler(
    of_object_t *obj,
    indigo_cxn_id_t cxn_id)
{
    uint16_t table_id;
    indigo_core_gentable_t *gentable;
    indigo_error_t rv;
    of_checksum_128_t checksum, checksum_mask;

    of_bsn_gentable_clear_request_table_id_get(obj, &table_id);
    of_bsn_gentable_clear_request_checksum_get(obj, &checksum);
    of_bsn_gentable_clear_request_checksum_mask_get(obj, &checksum_mask);

    gentable = find_gentable_by_id(table_id);
    if (gentable == NULL) {
        AIM_LOG_ERROR("Nonexistent gentable id %d", table_id);
        indigo_cxn_send_error_reply(
            cxn_id, obj,
            OF_ERROR_TYPE_BAD_REQUEST,
            OF_REQUEST_FAILED_BAD_TABLE_ID);
        return;
    }

    struct ind_core_gentable_clear_state *state = aim_zmalloc(sizeof(*state));
    state->cxn_id = cxn_id;
    state->request = ind_core_dup_tracking(obj, cxn_id);

    rv = ind_core_gentable_spawn_iter_task(gentable, clear_iter, state,
                                           IND_SOC_DEFAULT_PRIORITY,
                                           checksum, checksum_mask);
    if (rv < 0) {
        AIM_LOG_ERROR("Failed to spawn gentable iter task: %s", indigo_strerror(rv));
        of_object_delete(state->request);
        aim_free(state);
    }
}

void
ind_core_bsn_gentable_set_buckets_size_handler(
    of_object_t *obj,
    indigo_cxn_id_t cxn_id)
{
    uint16_t table_id;
    indigo_core_gentable_t *gentable;
    uint32_t xid;
    uint32_t new_buckets_size;
    uint32_t old_buckets_size;
    struct ind_core_gentable_checksum_bucket *old_buckets;
    int i;

    of_bsn_gentable_set_buckets_size_xid_get(obj, &xid);
    of_bsn_gentable_set_buckets_size_table_id_get(obj, &table_id);
    of_bsn_gentable_set_buckets_size_buckets_size_get(obj, &new_buckets_size);

    gentable = find_gentable_by_id(table_id);
    if (gentable == NULL) {
        AIM_LOG_ERROR("Nonexistent gentable id %d", table_id);
        indigo_cxn_send_error_reply(
            cxn_id, obj,
            OF_ERROR_TYPE_BAD_REQUEST,
            OF_REQUEST_FAILED_BAD_TABLE_ID);
        return;
    }

    if (new_buckets_size == 0 || (new_buckets_size & (new_buckets_size - 1)) != 0) {
        AIM_LOG_ERROR("Attempted to set a non power of 2 buckets size (%d) for gentable %s",
                      new_buckets_size, gentable->name);
        indigo_cxn_send_error_reply(
            cxn_id, obj,
            OF_ERROR_TYPE_BAD_REQUEST,
            OF_REQUEST_FAILED_EPERM);
        return;
    }

    if (new_buckets_size == gentable->checksum_buckets_size) {
        return;
    }

    old_buckets_size = gentable->checksum_buckets_size;
    old_buckets = gentable->checksum_buckets;

    gentable->checksum_buckets_size = new_buckets_size;
    gentable->checksum_buckets = aim_malloc(sizeof(*gentable->checksum_buckets) *
                                            gentable->checksum_buckets_size);

    gentable->checksum_buckets_shift =
        calc_checksum_buckets_shift(gentable->checksum_buckets_size);

    for (i = 0; i < gentable->checksum_buckets_size; i++) {
        struct ind_core_gentable_checksum_bucket *bucket =
            &gentable->checksum_buckets[i];
        bucket->checksum.lo = 0;
        bucket->checksum.hi = 0;
        list_init(&bucket->entries);
    }

    for (i = 0; i < old_buckets_size; i++) {
        list_links_t *cur, *next;
        LIST_FOREACH_SAFE(&old_buckets[i].entries, cur, next) {
            struct ind_core_gentable_entry *entry =
                container_of(cur, checksum_links, struct ind_core_gentable_entry);

            /* Remove from old bucket */
            list_remove(&entry->checksum_links);

            /* Insert into new bucket */
            struct ind_core_gentable_checksum_bucket *new_bucket;
            new_bucket = find_checksum_bucket(gentable, &entry->checksum);
            list_push(&new_bucket->entries, &entry->checksum_links);
            update_checksum(&new_bucket->checksum, &entry->checksum);
        }
    }

    aim_free(old_buckets);
}

struct ind_core_gentable_entry_stats_state {
    indigo_cxn_id_t cxn_id;
    of_object_t *request;
    of_object_t *reply;
};

static void
entry_stats_iter(void *cookie, indigo_core_gentable_t *gentable,
                 struct ind_core_gentable_entry *entry)
{
    struct ind_core_gentable_entry_stats_state *state = cookie;

    if (entry != NULL) {
        of_list_bsn_gentable_entry_stats_entry_t stats_entries;
        of_bsn_gentable_entry_stats_entry_t *stats_entry;
        of_list_bsn_tlv_t stats;

        stats_entry = of_bsn_gentable_entry_stats_entry_new(OF_VERSION_1_3);
        AIM_TRUE_OR_DIE(of_bsn_gentable_entry_stats_entry_key_set(stats_entry, entry->key) == 0);
        of_bsn_gentable_entry_stats_entry_stats_bind(stats_entry, &stats);

        gentable->ops->get_stats(gentable->priv, entry->priv, entry->key, &stats);

        of_bsn_gentable_entry_stats_reply_entries_bind(state->reply, &stats_entries);
        if (of_list_append(&stats_entries, stats_entry) < 0) {
            of_bsn_gentable_entry_stats_reply_flags_set(state->reply,
                                                        OF_STATS_REPLY_FLAG_REPLY_MORE);
            indigo_cxn_send_controller_message(state->cxn_id, state->reply);

            state->reply = of_bsn_gentable_entry_stats_reply_new(state->request->version);

            uint32_t xid;
            of_bsn_gentable_entry_stats_request_xid_get(state->request, &xid);
            of_bsn_gentable_entry_stats_reply_xid_set(state->reply, xid);

            of_bsn_gentable_entry_stats_reply_entries_bind(state->reply, &stats_entries);
            if (of_list_append(&stats_entries, stats_entry) < 0) {
                AIM_DIE("unexpected failure appending to an empty stats list");
            }
        }

        of_object_delete(stats_entry);
    } else {
        indigo_cxn_send_controller_message(state->cxn_id, state->reply);
        of_object_delete(state->request);
        aim_free(state);
    }
}

void
ind_core_bsn_gentable_entry_stats_request_handler(
    of_object_t *obj,
    indigo_cxn_id_t cxn_id)
{
    uint16_t table_id;
    indigo_core_gentable_t *gentable;
    uint32_t xid;
    of_bsn_gentable_entry_stats_reply_t *reply;
    struct ind_core_gentable_entry_stats_state *state;
    indigo_error_t rv;
    of_checksum_128_t checksum, checksum_mask;

    of_bsn_gentable_entry_stats_request_xid_get(obj, &xid);
    of_bsn_gentable_entry_stats_request_table_id_get(obj, &table_id);
    of_bsn_gentable_entry_stats_request_checksum_get(obj, &checksum);
    of_bsn_gentable_entry_stats_request_checksum_mask_get(obj, &checksum_mask);

    gentable = find_gentable_by_id(table_id);
    if (gentable == NULL) {
        AIM_LOG_ERROR("Nonexistent gentable id %d", table_id);
        indigo_cxn_send_error_reply(
            cxn_id, obj,
            OF_ERROR_TYPE_BAD_REQUEST,
            OF_REQUEST_FAILED_BAD_TABLE_ID);
        return;
    }

    reply = of_bsn_gentable_entry_stats_reply_new(obj->version);
    of_bsn_gentable_entry_stats_reply_xid_set(reply, xid);

    state = aim_zmalloc(sizeof(*state));
    state->cxn_id = cxn_id;
    state->request = ind_core_dup_tracking(obj, cxn_id);
    state->reply = reply;

    rv = ind_core_gentable_spawn_iter_task(gentable, entry_stats_iter, state,
                                           IND_SOC_DEFAULT_PRIORITY,
                                           checksum, checksum_mask);
    if (rv < 0) {
        AIM_LOG_ERROR("Failed to spawn gentable iter task: %s", indigo_strerror(rv));
        of_object_delete(state->reply);
        of_object_delete(state->request);
        aim_free(state);
    }
}

struct ind_core_gentable_entry_desc_stats_state {
    indigo_cxn_id_t cxn_id;
    of_object_t *request;
    of_object_t *reply;
};

static void
entry_desc_stats_iter(void *cookie, indigo_core_gentable_t *gentable,
                      struct ind_core_gentable_entry *entry)
{
    struct ind_core_gentable_entry_desc_stats_state *state = cookie;

    if (entry != NULL) {
        of_list_bsn_gentable_entry_desc_stats_entry_t stats_entries;
        of_bsn_gentable_entry_desc_stats_entry_t *stats_entry;

        stats_entry = of_bsn_gentable_entry_desc_stats_entry_new(OF_VERSION_1_3);
        of_bsn_gentable_entry_desc_stats_entry_checksum_set(stats_entry, entry->checksum);
        AIM_TRUE_OR_DIE(of_bsn_gentable_entry_desc_stats_entry_key_set(stats_entry, entry->key) == 0);
        AIM_TRUE_OR_DIE(of_bsn_gentable_entry_desc_stats_entry_value_set(stats_entry, entry->value) == 0);

        of_bsn_gentable_entry_desc_stats_reply_entries_bind(state->reply, &stats_entries);
        if (of_list_append(&stats_entries, stats_entry) < 0) {
            of_bsn_gentable_entry_desc_stats_reply_flags_set(state->reply,
                                                             OF_STATS_REPLY_FLAG_REPLY_MORE);
            indigo_cxn_send_controller_message(state->cxn_id, state->reply);

            state->reply = of_bsn_gentable_entry_desc_stats_reply_new(state->request->version);

            uint32_t xid;
            of_bsn_gentable_entry_desc_stats_request_xid_get(state->request, &xid);
            of_bsn_gentable_entry_desc_stats_reply_xid_set(state->reply, xid);

            of_bsn_gentable_entry_desc_stats_reply_entries_bind(state->reply, &stats_entries);
            if (of_list_append(&stats_entries, stats_entry) < 0) {
                AIM_DIE("unexpected failure appending to an empty stats list");
            }
        }

        of_object_delete(stats_entry);
    } else {
        indigo_cxn_send_controller_message(state->cxn_id, state->reply);
        of_object_delete(state->request);
        aim_free(state);
    }
}

void
ind_core_bsn_gentable_entry_desc_stats_request_handler(
    of_object_t *obj,
    indigo_cxn_id_t cxn_id)
{
    uint16_t table_id;
    indigo_core_gentable_t *gentable;
    uint32_t xid;
    of_bsn_gentable_entry_desc_stats_reply_t *reply;
    struct ind_core_gentable_entry_desc_stats_state *state;
    indigo_error_t rv;
    of_checksum_128_t checksum, checksum_mask;

    of_bsn_gentable_entry_desc_stats_request_xid_get(obj, &xid);
    of_bsn_gentable_entry_desc_stats_request_table_id_get(obj, &table_id);
    of_bsn_gentable_entry_desc_stats_request_checksum_get(obj, &checksum);
    of_bsn_gentable_entry_desc_stats_request_checksum_mask_get(obj, &checksum_mask);

    gentable = find_gentable_by_id(table_id);
    if (gentable == NULL) {
        AIM_LOG_ERROR("Nonexistent gentable id %d", table_id);
        indigo_cxn_send_error_reply(
            cxn_id, obj,
            OF_ERROR_TYPE_BAD_REQUEST,
            OF_REQUEST_FAILED_BAD_TABLE_ID);
        return;
    }

    reply = of_bsn_gentable_entry_desc_stats_reply_new(obj->version);
    of_bsn_gentable_entry_desc_stats_reply_xid_set(reply, xid);

    state = aim_zmalloc(sizeof(*state));
    state->cxn_id = cxn_id;
    state->request = ind_core_dup_tracking(obj, cxn_id);
    state->reply = reply;

    rv = ind_core_gentable_spawn_iter_task(gentable, entry_desc_stats_iter, state,
                                           IND_SOC_DEFAULT_PRIORITY,
                                           checksum, checksum_mask);
    if (rv < 0) {
        AIM_LOG_ERROR("Failed to spawn gentable iter task: %s", indigo_strerror(rv));
        of_object_delete(state->request);
        of_object_delete(state->reply);
        aim_free(state);
    }
}

void
ind_core_bsn_gentable_desc_stats_request_handler(
    of_object_t *obj,
    indigo_cxn_id_t cxn_id)
{
    indigo_core_gentable_t *gentable;
    uint32_t xid;
    of_bsn_gentable_desc_stats_reply_t *reply;
    int i;
    of_list_bsn_gentable_desc_stats_entry_t stats_entries;
    of_bsn_gentable_desc_stats_entry_t *stats_entry;

    of_bsn_gentable_desc_stats_request_xid_get(obj, &xid);

    reply = of_bsn_gentable_desc_stats_reply_new(obj->version);
    of_bsn_gentable_desc_stats_reply_xid_set(reply, xid);
    of_bsn_gentable_desc_stats_reply_entries_bind(reply, &stats_entries);

    for (i = 0; i < MAX_GENTABLES; i++) {
        gentable = gentables[i];
        if (gentable == NULL) {
            continue;
        }

        stats_entry = of_bsn_gentable_desc_stats_entry_new(OF_VERSION_1_3);
        of_bsn_gentable_desc_stats_entry_table_id_set(stats_entry, gentable->table_id);
        of_bsn_gentable_desc_stats_entry_name_set(stats_entry, gentable->name);
        of_bsn_gentable_desc_stats_entry_buckets_size_set(stats_entry, gentable->checksum_buckets_size);
        of_bsn_gentable_desc_stats_entry_max_entries_set(stats_entry, gentable->max_entries);

        if (of_list_append(&stats_entries, stats_entry) < 0) {
            /* MAX_GENTABLES would have to be > 1000 to hit this */
            AIM_DIE("unexpected failure appending to gentable desc stats entry list");
        }

        of_object_delete(stats_entry);
    }

    indigo_cxn_send_controller_message(cxn_id, reply);
}

void
ind_core_bsn_gentable_stats_request_handler(
    of_object_t *obj,
    indigo_cxn_id_t cxn_id)
{
    indigo_core_gentable_t *gentable;
    uint32_t xid;
    of_bsn_gentable_stats_reply_t *reply;
    int i;
    of_list_bsn_gentable_stats_entry_t stats_entries;

    of_bsn_gentable_stats_request_xid_get(obj, &xid);

    reply = of_bsn_gentable_stats_reply_new(obj->version);
    of_bsn_gentable_stats_reply_xid_set(reply, xid);
    of_bsn_gentable_stats_reply_entries_bind(reply, &stats_entries);

    for (i = 0; i < MAX_GENTABLES; i++) {
        gentable = gentables[i];
        if (gentable == NULL) {
            continue;
        }

        of_bsn_gentable_stats_entry_t stats_entry;
        of_bsn_gentable_stats_entry_init(&stats_entry, reply->version, -1, 1);
        if (of_list_bsn_gentable_stats_entry_append_bind(&stats_entries, &stats_entry)) {
            /* MAX_GENTABLES would have to be > 1000 to hit this */
            AIM_DIE("unexpected failure appending to gentable stats entry list");
        }


        of_bsn_gentable_stats_entry_table_id_set(&stats_entry, gentable->table_id);
        of_bsn_gentable_stats_entry_entry_count_set(&stats_entry, gentable->num_entries);
        of_bsn_gentable_stats_entry_checksum_set(&stats_entry, gentable->checksum);
    }

    indigo_cxn_send_controller_message(cxn_id, reply);
}

void
ind_core_bsn_gentable_bucket_stats_request_handler(
    of_object_t *obj,
    indigo_cxn_id_t cxn_id)
{
    indigo_core_gentable_t *gentable;
    uint32_t xid;
    uint16_t table_id;
    of_bsn_gentable_bucket_stats_reply_t *reply;
    int i;
    of_list_bsn_gentable_bucket_stats_entry_t stats_entries;

    of_bsn_gentable_bucket_stats_request_xid_get(obj, &xid);
    of_bsn_gentable_bucket_stats_request_table_id_get(obj, &table_id);

    reply = of_bsn_gentable_bucket_stats_reply_new(obj->version);
    of_bsn_gentable_bucket_stats_reply_xid_set(reply, xid);
    of_bsn_gentable_bucket_stats_reply_entries_bind(reply, &stats_entries);

    gentable = find_gentable_by_id(table_id);
    if (gentable == NULL) {
        AIM_LOG_ERROR("Nonexistent gentable id %d", table_id);
        indigo_cxn_send_error_reply(
            cxn_id, obj,
            OF_ERROR_TYPE_BAD_REQUEST,
            OF_REQUEST_FAILED_BAD_TABLE_ID);
        of_object_delete(reply);
        return;
    }

    for (i = 0; i < gentable->checksum_buckets_size; i++) {
        struct ind_core_gentable_checksum_bucket *bucket =
            &gentable->checksum_buckets[i];

        of_bsn_gentable_bucket_stats_entry_t stats_entry;
        of_bsn_gentable_bucket_stats_entry_init(&stats_entry, reply->version, -1, 1);
        if (of_list_bsn_gentable_bucket_stats_entry_append_bind(&stats_entries, &stats_entry)) {
            of_bsn_gentable_bucket_stats_reply_flags_set(reply, OF_STATS_REPLY_FLAG_REPLY_MORE);
            indigo_cxn_send_controller_message(cxn_id, reply);

            reply = of_bsn_gentable_bucket_stats_reply_new(obj->version);
            of_bsn_gentable_bucket_stats_reply_xid_set(reply, xid);
            of_bsn_gentable_bucket_stats_reply_entries_bind(reply, &stats_entries);

            if (of_list_bsn_gentable_bucket_stats_entry_append_bind(&stats_entries, &stats_entry)) {
                AIM_DIE("unexpected failure appending to an empty bucket stats list");
            }
        }

        of_bsn_gentable_bucket_stats_entry_checksum_set(&stats_entry, bucket->checksum);
    }

    indigo_cxn_send_controller_message(cxn_id, reply);
}


/* Utility functions */

static __attribute__((unused)) indigo_core_gentable_t *
find_gentable_by_id(uint32_t table_id)
{
    if (table_id >= MAX_GENTABLES) {
        return NULL;
    }

    return gentables[table_id];
}

static uint16_t
alloc_table_id()
{
    int i;
    for (i = 0; i < MAX_GENTABLES; i++) {
        if (gentables[i] == NULL) {
            return i;
        }
    }

    AIM_DIE("attempted to register more than %d gentables", MAX_GENTABLES);
}

/*
 * Calculate how far we need to right-shift to get the upper bits of the
 * checksum used for bucketing into the lower bits of a word.
 *
 * Assumes (as elsewhere) that only the upper 64 bits of a checksum are
 * usable for bucketing.
 *
 * Examples:
 *   1 -> 64
 *   2 -> 63
 *   4 -> 62
 *   8 -> 61
 */
static uint8_t
calc_checksum_buckets_shift(uint32_t checksum_buckets_size)
{
    uint8_t i = 0;
    while (checksum_buckets_size != 0) {
        i++;
        checksum_buckets_size >>= 1;
    }
    return 64 - i + 1;
}

static struct ind_core_gentable_checksum_bucket *
find_checksum_bucket(indigo_core_gentable_t *gentable, of_checksum_128_t *checksum)
{
    uint32_t idx = checksum->hi >> gentable->checksum_buckets_shift;
    return &gentable->checksum_buckets[idx];
}

static void
update_checksum(of_checksum_128_t *dst, const of_checksum_128_t *src)
{
    dst->lo ^= src->lo;
    dst->hi ^= src->hi;
}

static uint32_t
hash_key(of_list_bsn_tlv_t *key)
{
    return murmur_hash(OF_OBJECT_BUFFER_INDEX(key, 0), key->length, 0);
}

static list_head_t *
find_key_bucket(indigo_core_gentable_t *gentable, uint32_t key_hash)
{
    return &gentable->key_buckets[key_hash & (gentable->key_buckets_size - 1)];
}

static indigo_error_t
delete_entry(indigo_core_gentable_t *gentable, struct ind_core_gentable_entry *entry)
{
    indigo_error_t rv;
    struct ind_core_gentable_checksum_bucket *checksum_bucket;

    rv = gentable->ops->del(gentable->priv, entry->priv, entry->key);
    if (rv < 0) {
        return rv;
    }

    list_remove(&entry->key_links);
    list_remove(&entry->checksum_links);

    checksum_bucket = find_checksum_bucket(gentable, &entry->checksum);

    update_checksum(&checksum_bucket->checksum, &entry->checksum);
    update_checksum(&gentable->checksum, &entry->checksum);

    of_object_delete(entry->key);
    of_object_delete(entry->value);
    aim_free(entry);

    gentable->num_entries--;

    return INDIGO_ERROR_NONE;
}

static struct ind_core_gentable_entry *
find_entry_by_key(indigo_core_gentable_t *gentable, of_list_bsn_tlv_t *key)
{
    list_links_t *cur, *next;

    uint32_t hash = hash_key(key);
    list_head_t *bucket = find_key_bucket(gentable, hash);

    LIST_FOREACH_SAFE(bucket, cur, next) {
        struct ind_core_gentable_entry *entry =
            container_of(cur, key_links, struct ind_core_gentable_entry);
        if (entry->key_hash == hash && key_equality(key, entry->key)) {
            return entry;
        }
    }

    return NULL;
}

static bool
key_equality(of_list_bsn_tlv_t *a, of_list_bsn_tlv_t *b)
{
    if (a->length != b->length) {
        return false;
    }

    return memcmp(OF_OBJECT_BUFFER_INDEX(a, 0),
                  OF_OBJECT_BUFFER_INDEX(b, 0), a->length) == 0;
}


/*
 * Gentable iterator task
 *
 * Several operations follow a pattern of iterating over a range of checksums
 * in a table. Since the table can be very large we need to break up the work
 * to allow processing higher priority events in between.
 *
 * These functions wrap the SocketManager task API to provide a simple method
 * for iterating over a gentable without delaying higher priority events.
 */

struct ind_core_gentable_iter_task_state {
    ind_core_gentable_iter_task_callback_f callback;
    void *cookie;
    uint16_t table_id;
    uint64_t generation_id;
    of_checksum_128_t next_checksum;
    of_checksum_128_t checksum_prefix;
    of_checksum_128_t checksum_mask;
};

static ind_soc_task_status_t
ind_core_gentable_iter_task_callback(void *cookie)
{
    struct ind_core_gentable_iter_task_state *state = cookie;
    indigo_core_gentable_t *gentable = find_gentable_by_id(state->table_id);

    if (gentable == NULL || gentable->generation_id != state->generation_id) {
        AIM_LOG_WARN("gentable %s disappeared during iteration");
        state->callback(state->cookie, NULL, NULL);
        aim_free(state);
        return IND_SOC_TASK_FINISHED;
    }

    /*
     * This code needs to handle resizing of the checksum buckets array between
     * task invocations.
     *
     * Between invocations, the next_checksum field is the lowest possible
     * checksum we haven't iterated over. Normally this is the lowest possible
     * checksum in the next bucket. If the buckets were shrunk then this may be
     * somewhere in the middle of the checksum range of a bucket, in which case
     * we'll ignore the entries we've already seen.
     */

    do {
        struct ind_core_gentable_checksum_bucket *bucket =
            find_checksum_bucket(gentable, &state->next_checksum);

        list_links_t *cur, *next;
        LIST_FOREACH_SAFE(&bucket->entries, cur, next) {
            struct ind_core_gentable_entry *entry =
                container_of(cur, checksum_links, struct ind_core_gentable_entry);

            if (entry->checksum.hi < state->next_checksum.hi) {
                /* Buckets were shrunk */
                continue;
            }

            if ((entry->checksum.hi & state->checksum_mask.hi) != state->checksum_prefix.hi) {
                continue;
            }

            if ((entry->checksum.lo & state->checksum_mask.lo) != state->checksum_prefix.lo) {
                continue;
            }

            state->callback(state->cookie, gentable, entry);
        }

        const uint64_t bucket_interval = (uint64_t)1 << gentable->checksum_buckets_shift;
        const uint64_t bucket_mask = ~(uint64_t)0 << gentable->checksum_buckets_shift;

        /* Advance to next bucket */
        state->next_checksum.hi += bucket_interval;

        /* Reset to the lowest checksum in the bucket */
        state->next_checksum.hi &= bucket_mask;

        /*
         * Calculate the end of our bucket range.
         *
         * Basically, add the length of the checksum range to the start of the
         * range and then mask to the beginning of a bucket.
         */
        uint64_t end_checksum_hi =
            (state->checksum_prefix.hi + (~state->checksum_mask.hi + 1)) & bucket_mask;

        if (state->next_checksum.hi == end_checksum_hi) {
            /* Finished */
            state->callback(state->cookie, gentable, NULL);
            aim_free(state);
            return IND_SOC_TASK_FINISHED;
        }
    } while (!ind_soc_should_yield());

    return IND_SOC_TASK_CONTINUE;
}

/*
 * Spawn a task that iterates over a gentable
 *
 * @param gentable Handle for a gentable instance
 * @param callback Function called for each flowtable entry
 * @param cookie Opaque value passed to callback
 * @param priority SocketManager task priority
 * @returns An error code
 *
 * This function does not guarantee a consistent view of the
 * gentable over the course of the task.
 *
 * The callback function will be called with a NULL entry argument at
 * the end of the iteration.
 */

static indigo_error_t
ind_core_gentable_spawn_iter_task(
    indigo_core_gentable_t *gentable,
    ind_core_gentable_iter_task_callback_f callback,
    void *cookie,
    int priority,
    of_checksum_128_t checksum_prefix,
    of_checksum_128_t checksum_mask)
{
    indigo_error_t rv;

    struct ind_core_gentable_iter_task_state *state = aim_zmalloc(sizeof(*state));

    state->callback = callback;
    state->cookie = cookie;
    state->table_id = gentable->table_id;
    state->generation_id = gentable->generation_id;
    state->checksum_prefix = checksum_prefix;
    state->checksum_mask = checksum_mask;
    state->next_checksum = checksum_prefix;

    rv = ind_soc_task_register(ind_core_gentable_iter_task_callback, state, priority);
    if (rv != INDIGO_ERROR_NONE) {
        aim_free(state);
        return rv;
    }

    return INDIGO_ERROR_NONE;
}
