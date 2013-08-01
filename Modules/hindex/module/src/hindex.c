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

#include "hindex_int.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <assert.h>
#include <AIM/aim.h>

/*
 * Comments on the overall datastructure are in hindex_int.h
 */

#define HINDEX_INITIAL_SIZE 8
#define HINDEX_DEFAULT_LOAD_FACTOR 0.8

struct hindex *
hindex_create(hindex_hash_f hash, hindex_equals_f equals,
            uint32_t key_offset, float max_load_factor)
{
    struct hindex *hindex = malloc(sizeof(*hindex));
    AIM_TRUE_OR_DIE(hindex != NULL, "hindex allocation failed");

    hindex->hash = hash;
    hindex->equals = equals;
    hindex->key_offset = key_offset;
    if (max_load_factor == 0.0f) {
        hindex->max_load_factor = HINDEX_DEFAULT_LOAD_FACTOR;
    } else {
        hindex->max_load_factor = max_load_factor;
    }

    hindex->count = 0;
    hindex->size = HINDEX_INITIAL_SIZE;
    hindex->threshold = hindex->size * hindex->max_load_factor;

    hindex->hashes = calloc(hindex->size, sizeof(*hindex->hashes));
    hindex->objects = malloc(hindex->size * sizeof(*hindex->objects));
    AIM_TRUE_OR_DIE(hindex->hashes != NULL && hindex->objects != NULL, "hindex allocation failed");

    return hindex;
}

uint32_t
hindex_count(const struct hindex *hindex)
{
    return hindex->count;
}

static uint32_t
hindex_index(const struct hindex *hindex, uint32_t hash, uint32_t distance)
{
    return (hash + distance) & (hindex->size - 1);
}

/*
 * Calculate how far this hash value is from its desired bucket
 */
static uint32_t
hindex_distance(const struct hindex *hindex, uint32_t idx, uint32_t hash)
{
    uint32_t start_idx = hindex_index(hindex, hash, 0);
    return (idx + hindex->size - start_idx) & (hindex->size - 1);
}

/*
 * Return a pointer to the key embedded in 'object'
 */
static const void *
hindex_object_key(const struct hindex *hindex, const void *object)
{
    return (const void *)((const char *)object + hindex->key_offset);
}

/*
 * Call the user-supplied hash function and munge the result to
 * not conflict with the special hash codes.
 */
static uint32_t
hindex_calc_hash(const struct hindex *hindex, const void *key)
{
    uint32_t hash = hindex->hash(key);
    hash &= ~HINDEX_HASH_DELETED_BIT;
    hash |= hash == HINDEX_HASH_FREE;
    return hash;
}

void *
hindex_lookup(const struct hindex *hindex, const void *key, uint32_t *state)
{
    uint32_t hash = hindex_calc_hash(hindex, key);
    uint32_t distance = 0;

    if (state != NULL) {
        distance = *state;
    } else {
        distance = 0;
    }

    for (; distance < hindex->size; distance++) {
        uint32_t idx = hindex_index(hindex, hash, distance);
        uint32_t bucket_hash = hindex->hashes[idx];
        if (bucket_hash == hash) {
            void *object = hindex->objects[idx];
            if (hindex->equals(key, hindex_object_key(hindex, object))) {
                if (state != NULL) {
                    *state = distance + 1;
                }
                return object;
            }
        } else if (bucket_hash == HINDEX_HASH_FREE
                   || hindex_distance(hindex, idx, bucket_hash) < distance) {
            break;
        }
    }

    return NULL;
}

/*
 * Helper function for hindex_insert() and hindex_grow(). Inserts using the given
 * hash code without growing.
 */
static void
hindex_insert__(struct hindex *hindex, void *object, uint32_t hash)
{
    uint32_t distance;

    for (distance = 0; distance < hindex->size; distance++) {
        uint32_t idx = hindex_index(hindex, hash, distance);
        uint32_t bucket_hash = hindex->hashes[idx];
        uint32_t bucket_distance = hindex_distance(hindex, idx, bucket_hash);
        bool should_steal = distance > bucket_distance;

        if (bucket_hash == HINDEX_HASH_FREE
            || ((bucket_hash & HINDEX_HASH_DELETED_BIT) && should_steal)) {
            hindex->hashes[idx] = hash;
            hindex->objects[idx] = object;
            hindex->count++;
            return;
        } else if (should_steal) {
            /*
             * Swap with the current bucket owner and keep going to find
             * a new bucket for it.
             */
            void *bucket_object = hindex->objects[idx];
            hindex->hashes[idx] = hash;
            hindex->objects[idx] = object;
            hash = bucket_hash;
            object = bucket_object;
            distance = bucket_distance;
        }
    }

    assert(0);
}

/*
 * Double the hashtable size.
 */
static void
hindex_grow(struct hindex *hindex)
{
    uint32_t *old_hashes = hindex->hashes;
    void **old_objects = hindex->objects;

    uint32_t old_size = hindex->size;

    hindex->count = 0;
    hindex->size *= 2;
    hindex->threshold = hindex->size * hindex->max_load_factor;

    hindex->hashes = calloc(hindex->size, sizeof(*hindex->hashes));
    hindex->objects = malloc(hindex->size * sizeof(*hindex->objects));
    AIM_TRUE_OR_DIE(hindex->hashes != NULL && hindex->objects != NULL, "hindex growth failed");

    uint32_t idx;
    for (idx = 0; idx < old_size; idx++) {
        uint32_t hash = old_hashes[idx];
        void *object = old_objects[idx];
        if ((hash != HINDEX_HASH_FREE) && !(hash & HINDEX_HASH_DELETED_BIT)) {
            hindex_insert__(hindex, object, hash);
        }
    }

    free(old_hashes);
    free(old_objects);
}

void
hindex_insert(struct hindex *hindex, void *object)
{
    assert(object != NULL);

    if (hindex->count >= hindex->threshold) {
        hindex_grow(hindex);
    }

    uint32_t hash = hindex_calc_hash(hindex, hindex_object_key(hindex, object));

    hindex_insert__(hindex, object, hash);
}

void
hindex_remove(struct hindex *hindex, const void *object)
{
    uint32_t hash = hindex_calc_hash(hindex, hindex_object_key(hindex, object));
    uint32_t distance;

    for (distance = 0; distance < hindex->size; distance++) {
        uint32_t idx = hindex_index(hindex, hash, distance);
        uint32_t bucket_hash = hindex->hashes[idx];
        if (bucket_hash == hash) {
            void *bucket_object = hindex->objects[idx];
            if (bucket_object == object) {
                hindex->hashes[idx] = hash | HINDEX_HASH_DELETED_BIT;
                hindex->count--;
                return;
            }
        }
    }

    assert(0);
}

void
hindex_destroy(struct hindex *hindex)
{
    free(hindex->hashes);
    free(hindex->objects);
    free(hindex);
}

int compare_uint32(const void *_a, const void *_b)
{
    uint32_t a = *(const uint32_t *)_a;
    uint32_t b = *(const uint32_t *)_b;
    if (a < b) {
        return -1;
    } else if (a > b) {
        return 1;
    } else {
        return 0;
    }
}

void hindex_stats(struct hindex *hindex)
{
    uint32_t idx;
    double distance_sum = 0;
    double distance_squared_sum = 0;
    for (idx = 0; idx < hindex->size; idx++) {
        uint32_t bucket_hash = hindex->hashes[idx];
        if (bucket_hash != HINDEX_HASH_FREE
            && !(bucket_hash & HINDEX_HASH_DELETED_BIT)) {
            uint32_t dist = hindex_distance(hindex, idx, bucket_hash);
            distance_sum += dist;
            distance_squared_sum += dist * dist;
        }
    }

    fprintf(stderr, "count=%u size=%u load=%f\n", hindex->count, hindex->size, (double)hindex->count/hindex->size);
    fprintf(stderr, "memory consumption: %u kilobytes\n", (uint32_t)(hindex->size * (sizeof(uint32_t) + sizeof(void *)) / 1024));

    double mean = distance_sum / hindex->count;
    double variance = (distance_squared_sum - distance_sum*distance_sum/hindex->count)/hindex->count;
    fprintf(stderr, "mean=%f\n", mean);
    fprintf(stderr, "variance=%f\n", variance);
}

uint32_t
hindex_uint16_hash(const void *key)
{
    /* 32-bit MurmurHash3 finalizer */
    uint32_t h = *(const uint16_t *)key;
    h ^= h >> 16;
    h *= 0x85ebca6b;
    h ^= h >> 13;
    h *= 0xc2b2ae35;
    h ^= h >> 16;
    return h;
}

int
hindex_uint16_equality(const void *key1, const void *key2)
{
    return *(const uint16_t *)key1 == *(const uint16_t *)key2;
}

uint32_t
hindex_uint32_hash(const void *key)
{
    /* 32-bit MurmurHash3 finalizer */
    uint32_t h = *(const uint32_t *)key;
    h ^= h >> 16;
    h *= 0x85ebca6b;
    h ^= h >> 13;
    h *= 0xc2b2ae35;
    h ^= h >> 16;
    return h;
}

int
hindex_uint32_equality(const void *key1, const void *key2)
{
    return *(const uint32_t *)key1 == *(const uint32_t *)key2;
}

uint32_t
hindex_uint64_hash(const void *key)
{
    /* 64-bit MurmurHash3 finalizer */
    uint64_t h = *(const uint64_t *)key;
    h ^= h >> 33;
    h *= 0xff51afd7ed558ccd;
    h ^= h >> 33;
    h *= 0xc4ceb9fe1a85ec53;
    h ^= h >> 33;
    return h;
}

int
hindex_uint64_equality(const void *key1, const void *key2)
{
    return *(const uint64_t *)key1 == *(const uint64_t *)key2;
}
