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

static indigo_core_gentable_t *find_gentable_by_id(uint32_t table_id);
static uint16_t alloc_table_id(void);
static uint8_t calc_checksum_buckets_shift(uint32_t checksum_buckets_size);
static struct ind_core_gentable_checksum_bucket *find_checksum_bucket(indigo_core_gentable_t *gentable, of_checksum_128_t *checksum);
static void update_checksum(of_checksum_128_t *dst, const of_checksum_128_t *src);
static uint32_t hash_key(of_list_bsn_tlv_t *key);
static list_head_t *find_key_bucket(indigo_core_gentable_t *gentable, uint32_t key_hash);
static indigo_error_t delete_entry(indigo_core_gentable_t *gentable, struct ind_core_gentable_entry *entry);

struct ind_core_gentable_checksum_bucket {
    of_checksum_128_t checksum;
    list_head_t entries;
};

struct indigo_core_gentable {
    const indigo_core_gentable_ops_t *ops;
    void *priv;
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


/* Registration */

void
indigo_core_gentable_register(
    const of_table_name_t name,
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

    gentable->key_buckets = aim_malloc(sizeof(*gentable->key_buckets) *
                                       gentable->checksum_buckets_size);

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

    of_bsn_gentable_entry_add_table_id_get(obj, &table_id);
    of_bsn_gentable_entry_add_key_bind(obj, &key);
    of_bsn_gentable_entry_add_value_bind(obj, &value);

    gentable = find_gentable_by_id(table_id);
    if (gentable == NULL) {
        /* TODO error */
        AIM_DIE("Nonexistent gentable id %d", table_id);
    }

    /* TODO lookup on key to see if this is a modify */

    rv = gentable->ops->add(gentable->priv, &key, &value, &priv);
    if (rv != INDIGO_ERROR_NONE) {
        /* TODO error */
        AIM_LOG_ERROR("%s gentable add failed: %s",
                      gentable->name, indigo_strerror(rv));
        AIM_DIE("NYI");
        of_object_delete(obj);
    }

    /* Allocate new entry */
    struct ind_core_gentable_entry *entry = aim_zmalloc(sizeof(*entry));
    entry->key = of_object_dup(&key);
    entry->value = of_object_dup(&value);
    of_bsn_gentable_entry_add_checksum_get(obj, &entry->checksum);

    entry->key_hash = hash_key(&key);
    entry->priv = priv;

    /* Insert into key bucket */
    list_push(find_key_bucket(gentable, entry->key_hash), &entry->key_links);

    /* Insert into checksum bucket */
    checksum_bucket = find_checksum_bucket(gentable, &entry->checksum);
    list_push(&checksum_bucket->entries, &entry->checksum_links);
    update_checksum(&checksum_bucket->checksum, &entry->checksum);

    /* Update table checksum */
    update_checksum(&gentable->checksum, &entry->checksum);

    of_object_delete(obj);
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

    rv = gentable->ops->del(gentable->priv, entry->priv, entry->key);
    if (rv < 0) {
        return rv;
    }

    of_object_delete(entry->key);
    of_object_delete(entry->value);
    aim_free(entry);

    return INDIGO_ERROR_NONE;
}
