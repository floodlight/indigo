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

#ifndef _HINDEX_H
#define _HINDEX_H

#include <stdint.h>

/**
 * Hash function pointer type
 *
 * Return a hash of the key.
 */
typedef uint32_t (*hindex_hash_f)(const void *key);

/**
 * Equality function pointer type
 *
 * Return true if the two keys are equal.
 */
typedef int (*hindex_equals_f)(const void *key1, const void *key2);

/**
 * Create a hindex
 *
 * 'hash', 'equals', and 'key_offset' define the key used by this hindex.
 * 'key_offset', which should generally be computed with offsetof(),
 * is the location of the key in the containing "object". The 'hash'
 * and 'equality' functions should agree such that two keys that are
 * equal have the same hash code.
 *
 * 'max_load_factor' is a number between 0 and 1 expressing the fraction
 * of the table that can be filled before it automatically grows.
 * Suggested values are between 0.75 and 0.875. The lower the load factor
 * the faster most operations will be, but the hindex will use more memory.
 * Passing 0 for 'max_load_factor' will use a good default.
 */
struct hindex *hindex_create(hindex_hash_f hash, hindex_equals_f equals,
                         uint32_t key_offset, float max_load_factor);

/**
 * Return the number of objects in a hindex
 */
uint32_t hindex_count(const struct hindex *hindex);

/**
 * Look up an object by 'key' in a hindex
 *
 * 'state' is an optional parameter used for iterating over multiple objects
 * with the same key. If given it should be initialized to 0 for the first
 * lookup. Calling hindex_lookup() again with the same state pointer will
 * return successive objects with the given key. NULL will be returned
 * when the iteration is finished. The hindex must not be modified during the
 * iteration.
 *
 * Returns a pointer to the object, or NULL if not found.
 */
void *hindex_lookup(const struct hindex *hindex, const void *key, uint32_t *state);

/**
 * Insert an object into a hindex
 */
void hindex_insert(struct hindex *hindex, void *object);

/**
 * Remove an object from a hindex
 *
 * The object must already exist in the hindex.
 */
void hindex_remove(struct hindex *hindex, const void *object);

/**
 * Destroy a hindex
 *
 * Does not free any objects still in the hindex.
 */
void hindex_destroy(struct hindex *hindex);

/**
 * Output stats for this hindex to stderr
 */
void hindex_stats(struct hindex *hindex);

/* Hash/equality functions for common datatypes */

uint32_t hindex_uint16_hash(const void *key);
int hindex_uint16_equality(const void *key1, const void *key2);
uint32_t hindex_uint32_hash(const void *key);
int hindex_uint32_equality(const void *key1, const void *key2);
uint32_t hindex_uint64_hash(const void *key);
int hindex_uint64_equality(const void *key1, const void *key2);

#endif
