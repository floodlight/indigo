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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stddef.h>
#include "hindex_int.h"

struct obj {
    uint32_t key;
};

static struct obj *
make_obj(uint32_t key)
{
    struct obj *obj = malloc(sizeof(*obj));
    obj->key = key;
    return obj;
}

/*
 * Trivial hash function used to allow the test to deliberately cause
 * collisions.
 */
static uint32_t
hash_uint32(const void *key)
{
    return *(uint32_t *)key;
}

static void
test_basic(void)
{
    struct hindex *hindex = hindex_create(hash_uint32, hindex_uint32_equality,
                                    offsetof(struct obj, key), 0.875);
    assert(hindex_count(hindex) == 0);

    struct obj *obj1 = make_obj(1);

    hindex_insert(hindex, obj1);
    assert(hindex_lookup(hindex, &obj1->key, NULL) == obj1);
    assert(hindex_count(hindex) == 1);

    hindex_remove(hindex, obj1);
    assert(hindex_lookup(hindex, &obj1->key, NULL) == NULL);
    assert(hindex_count(hindex) == 0);

    free(obj1);

    hindex_destroy(hindex);
}

/* qsort comparator */
static int compare_ptr(const void *_a, const void *_b)
{
    const void *a = *(const void **)_a;
    const void *b = *(const void **)_b;
    if (a < b) {
        return -1;
    } else if (a > b) {
        return 1;
    } else {
        return 0;
    }
}

/* Test multiple objects with the same key */
static void
test_multi(void)
{
    uint32_t key = 1;
    const int n = 3;
    int i;

    struct hindex *hindex = hindex_create(hash_uint32, hindex_uint32_equality,
                                    offsetof(struct obj, key), 0.875);
    assert(hindex_count(hindex) == 0);

    struct obj objs[n];

    for (i = 0; i < n; i++) {
        objs[i].key = key;
        hindex_insert(hindex, &objs[i]);
    }

    assert((int)hindex_count(hindex) == n);

    uint32_t state = 0;
    struct obj *results[n];
    for (i = 0; i < n; i++) {
        results[i] = hindex_lookup(hindex, &key, &state);
        assert(results[i] != NULL);
    }

    qsort(results, n, sizeof(*results), compare_ptr);
    for (i = 0; i < n; i++) {
        assert(results[i] == &objs[i]);
    }

    for (i = 0; i < n; i++) {
        hindex_remove(hindex, &objs[i]);
    }

    assert(hindex_count(hindex) == 0);

    hindex_destroy(hindex);
}

static void
test_fill(void)
{
    uint32_t key;
    const uint32_t n = 1024*10;

    struct hindex *hindex = hindex_create(hash_uint32, hindex_uint32_equality,
                                    offsetof(struct obj, key), 0.875);

    struct obj *objs = malloc(sizeof(*objs) * n);

    for (key = 0; key < n; key++) {
        objs[key].key = key;
    }

    for (key = 0; key < n; key++) {
        assert(hindex_lookup(hindex, &key, NULL) == NULL);
        hindex_insert(hindex, &objs[key]);
        assert(hindex_lookup(hindex, &key, NULL) == &objs[key]);
        assert(hindex_count(hindex) == key + 1);
    }

    for (key = 0; key < n; key++) {
        assert(hindex_lookup(hindex, &key, NULL) == &objs[key]);
    }

    assert(key == n);
    assert(hindex_lookup(hindex, &key, NULL) == NULL);

    for (key = 0; key < n; key++) {
        assert(hindex_lookup(hindex, &key, NULL) == &objs[key]);
        hindex_remove(hindex, &objs[key]);
        assert(hindex_lookup(hindex, &key, NULL) == NULL);
        assert(hindex_count(hindex) == n - key - 1);
    }

    free(objs);

    hindex_destroy(hindex);
}

static void
test_collisions(void)
{
    uint32_t key;

    struct hindex *hindex = hindex_create(hash_uint32, hindex_uint32_equality,
                                    offsetof(struct obj, key), 0.875);

    struct obj *obj1 = make_obj(1);
    struct obj *obj9 = make_obj(9);
    struct obj *obj2 = make_obj(2);

    hindex_insert(hindex, obj1);
    hindex_insert(hindex, obj9); /* collides with 1 */
    hindex_insert(hindex, obj2); /* bucket taken by 9 */
    assert(hindex_count(hindex) == 3);

    /* Dig into internals to validate collision handling */
    assert(hindex->objects[1] == obj1);
    assert(hindex->objects[2] == obj9);
    assert(hindex->objects[3] == obj2);

    key = 1; assert(hindex_lookup(hindex, &key, NULL) == obj1);
    key = 9; assert(hindex_lookup(hindex, &key, NULL) == obj9);
    key = 2; assert(hindex_lookup(hindex, &key, NULL) == obj2);

    hindex_remove(hindex, obj1);
    hindex_remove(hindex, obj9);
    hindex_remove(hindex, obj2);
    assert(hindex_count(hindex) == 0);

    free(obj1);
    free(obj9);
    free(obj2);

    hindex_destroy(hindex);
}

/* Test stealing bucket from another object */
static void
test_robin_hood(void)
{
    uint32_t key;

    struct hindex *hindex = hindex_create(hash_uint32, hindex_uint32_equality,
                                    offsetof(struct obj, key), 0.875);

    struct obj *obj1 = make_obj(1);
    struct obj *obj2 = make_obj(2);
    struct obj *obj9 = make_obj(9);

    hindex_insert(hindex, obj1); /* bucket 1, distance 0 */
    assert(hindex->objects[1] == obj1);

    hindex_insert(hindex, obj2); /* bucket 2, distance 0 */
    assert(hindex->objects[2] == obj2);

    hindex_insert(hindex, obj9); /* bucket 2, distance 1 */
    /* displaces obj2 */
    assert(hindex->objects[2] == obj9);
    assert(hindex->objects[3] == obj2);

    key = 1; assert(hindex_lookup(hindex, &key, NULL) == obj1);
    key = 2; assert(hindex_lookup(hindex, &key, NULL) == obj2);
    key = 9; assert(hindex_lookup(hindex, &key, NULL) == obj9);

    hindex_remove(hindex, obj1);
    hindex_remove(hindex, obj2);
    hindex_remove(hindex, obj9);

    free(obj1);
    free(obj2);
    free(obj9);

    hindex_destroy(hindex);
}

/* Test scenario where an object in the middle of a hash chain is deleted */
static void
test_robin_hood_deleted(void)
{
    uint32_t key;

    struct hindex *hindex = hindex_create(hash_uint32, hindex_uint32_equality,
                                    offsetof(struct obj, key), 0.875);

    struct obj *obj1 = make_obj(1);
    struct obj *obj2 = make_obj(2);
    struct obj *obj9 = make_obj(9);
    struct obj *obj17 = make_obj(17);

    hindex_insert(hindex, obj1); /* bucket 1, distance 0 */
    assert(hindex->objects[1] == obj1);

    hindex_insert(hindex, obj9); /* bucket 2, distance 1 */
    assert(hindex->objects[2] == obj9);

    hindex_insert(hindex, obj17); /* bucket 3, distance 2 */
    assert(hindex->objects[3] == obj17);

    key = 1; assert(hindex_lookup(hindex, &key, NULL) == obj1);
    key = 9; assert(hindex_lookup(hindex, &key, NULL) == obj9);
    key = 17; assert(hindex_lookup(hindex, &key, NULL) == obj17);

    /* Replace bucket 2 with a tombstone */
    hindex_remove(hindex, obj9);

    key = 1; assert(hindex_lookup(hindex, &key, NULL) == obj1);
    key = 17; assert(hindex_lookup(hindex, &key, NULL) == obj17);

    /*
     * obj2 is not allowed in bucket 2 because that would disrupt the
     * bucket 0 chain.
     */
    hindex_insert(hindex, obj2); /* bucket 4, distance 2 */
    assert(hindex->objects[4] == obj2);

    key = 1; assert(hindex_lookup(hindex, &key, NULL) == obj1);
    key = 2; assert(hindex_lookup(hindex, &key, NULL) == obj2);
    key = 17; assert(hindex_lookup(hindex, &key, NULL) == obj17);

    hindex_remove(hindex, obj1);
    hindex_remove(hindex, obj2);
    hindex_remove(hindex, obj17);

    free(obj1);
    free(obj2);
    free(obj9);
    free(obj17);

    hindex_destroy(hindex);
}

int main(int argc, char **argv)
{
    (void) argc;
    (void) argv;
    test_basic();
    test_multi();
    test_fill();
    test_collisions();
    test_robin_hood();
    test_robin_hood_deleted();
    return 0;
}
