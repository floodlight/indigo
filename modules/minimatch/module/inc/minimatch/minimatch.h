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

/*
 * Minimatch
 *
 * The of_match_t is very large, over 480 bytes. Most flows do not use the vast
 * majority of the fields in the match; the mask is sparse. This module
 * implements a lossless compressed match representation. A VLAN+MAC match will
 * use only 48 bytes, saving 90% of the space. Match comparisons are also
 * faster when done directly on the compressed representation.
 */

#ifndef __MINIMATCH_H__
#define __MINIMATCH_H__

#include <loci/loci.h>
#include <stdbool.h>

#define OF_MATCH_FIELDS_WORDS (sizeof(of_match_fields_t)/sizeof(uint32_t))

/* Exposed to allow embedding. Treat as private */
typedef struct minimatch {
    /* of_version_t from the original match */
    uint8_t version;

    /* Length of the words array */
    uint8_t num_words;

    /* Bits are set when the corresponding mask word is nonzero */
    uint32_t bitmap[(OF_MATCH_FIELDS_WORDS+31)/32];

    /* Array of (field, mask) pairs. One pair for each bit set in the bitmap. */
    uint32_t *words;
} minimatch_t;

/**
 * Initialize a minimatch
 *
 * @param minimatch Minimatch to be initialized
 * @param match Match to compress
 *
 * Must be cleaned up with minimatch_cleanup.
 */
void minimatch_init(minimatch_t *minimatch, const of_match_t *match);

/**
 * Clean up a minimatch
 *
 * @param minimatch
 */
void minimatch_cleanup(minimatch_t *minimatch);

/**
 * Expand a minimatch
 *
 * Produces an of_match_t identical to the one passed to minimatch_init.
 *
 * @param minimatch Minimatch to decompress
 * @param match Match to be initialized
 */
void minimatch_expand(const minimatch_t *minimatch, of_match_t *match);

/*
 * Match comparisons
 *
 * See documentation for of_match_eq, of_match_more_specific, and
 * of_match_overlap.
 */
bool minimatch_equal(const minimatch_t *a, const minimatch_t *b);
bool minimatch_more_specific(const minimatch_t *a, const minimatch_t *b);
bool minimatch_overlap(const minimatch_t *a, const minimatch_t *b);

/**
 * Hash a minimatch
 *
 * @param minimatch
 * @param seed Seed for the hash function
 */
uint32_t minimatch_hash(const minimatch_t *minimatch, uint32_t seed);

/**
 * Move a minimatch
 *
 * 'dst' becomes a copy of 'src' and 'src' is initialized to be empty.
 * 'src' may be passed to minimatch_cleanup, but this is not necessary.
 * 'dst' must be cleaned up with minimatch_cleanup.
 */
void minimatch_move(minimatch_t *dst, minimatch_t *src);

#endif
