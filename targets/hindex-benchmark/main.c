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
#include <unistd.h>
#include <stddef.h>
#include <time.h>
#include <AIM/aim.h>
#include <hindex/hindex.h>

#ifdef USE_CALLGRIND
#include <valgrind/callgrind.h>
#else
#define CALLGRIND_START_INSTRUMENTATION
#define CALLGRIND_STOP_INSTRUMENTATION
#endif

/* 1 million-ish buckets at a load factor of 0.875 */
#define LOAD_FACTOR 7/8
#define N ((1<<20) * LOAD_FACTOR)
#define ITERS 10

struct obj {
    uint32_t key;
};

static struct obj objs[N];

static uint64_t
monotonic_ns(void)
{
    struct timespec tp;
    clock_gettime(CLOCK_MONOTONIC, &tp);
    return ((uint64_t)tp.tv_sec * 1000*1000*1000) + tp.tv_nsec;
}

void
benchmark_iteration(void)
{
    int i;

    struct hindex *hindex =
            hindex_create(hindex_uint32_hash, hindex_uint32_equality,
                          offsetof(struct obj, key), 1.0 * LOAD_FACTOR);

    {
        uint64_t start_time = monotonic_ns();
        for (i = 0; i < N; i++) {
            hindex_insert(hindex, &objs[i]);
        }
        uint64_t elapsed = monotonic_ns() - start_time;
        fprintf(stderr, "insert: avg %f ns\n", (double)elapsed/N);
    }

    hindex_stats(hindex);

    {
        uint64_t start_time = monotonic_ns();
        for (i = 0; i < N; i++) {
            assert(hindex_lookup(hindex, &objs[i].key, NULL) == &objs[i]);
        }
        uint64_t elapsed = monotonic_ns() - start_time;
        fprintf(stderr, "successful lookup: avg %f ns\n", (double)elapsed/N);
    }

    {
        uint64_t start_time = monotonic_ns();
        for (i = 0; i < N; i++) {
            uint64_t bad_key = (1ull << 31) | objs[i].key;
            assert(hindex_lookup(hindex, &bad_key, NULL) == NULL);
        }
        uint64_t elapsed = monotonic_ns() - start_time;
        fprintf(stderr, "failed lookup: avg %f ns\n", (double)elapsed/N);
    }

    {
        uint64_t start_time = monotonic_ns();
        for (i = 0; i < N; i++) {
            hindex_remove(hindex, &objs[i]);
        }
        uint64_t elapsed = monotonic_ns() - start_time;
        fprintf(stderr, "remove: avg %f ns\n", (double)elapsed/N);
    }

    assert(hindex_count(hindex) == 0);
    hindex_destroy(hindex);
}

static void
generate_keys(void)
{
    srand(42);

    /* Use an hindex to ensure key uniqueness */
    struct hindex *hindex =
            hindex_create(hindex_uint32_hash, hindex_uint32_equality,
                          offsetof(struct obj, key), 0.5);

    int i;
    for (i = 0; i < N; i++) {
        uint32_t key;
        do {
            key = rand();
        } while (hindex_lookup(hindex, &key, NULL) != NULL);
        objs[i].key = key;
        hindex_insert(hindex, &objs[i]);
    }

    hindex_destroy(hindex);
}

int
main(int argc, char **argv)
{
    fprintf(stderr, "generating unique random keys\n");
    generate_keys();

    CALLGRIND_START_INSTRUMENTATION;

    int i;
    for (i = 0; i < ITERS; i++) {
        fprintf(stderr, "\niteration %d\n", i);
        benchmark_iteration();
    }

    CALLGRIND_STOP_INSTRUMENTATION;

    return 0;
}
