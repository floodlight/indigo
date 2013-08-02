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

#ifndef _HINDEX_INT_H
#define _HINDEX_INT_H

#include <hindex/hindex.h>

/*
 * This hashtable uses Robin Hood hashing to reduce variance in chain lengths.
 * See https://cs.uwaterloo.ca/research/tr/1986/CS-86-14.pdf. The basic idea
 * is to steal buckets during insertion when the victim is closer to its
 * desired bucket than we are.
 *
 * The hashes and object pointers are stored in separate arrays to improve
 * cache performance (more hash checks per cache line) and total memory usage.
 */

/* The hash array also encodes the bucket state */
#define HINDEX_HASH_FREE 0
#define HINDEX_HASH_DELETED_BIT 0x80000000

struct hindex {
    hindex_hash_f hash;
    hindex_equals_f equals;
    uint32_t key_offset;
    uint32_t size;
    uint32_t threshold;
    uint32_t count;
    float max_load_factor;
    uint32_t *hashes;
    void **objects;
};

#endif
