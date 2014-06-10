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

#include <minimatch/minimatch.h>
#include <AIM/aim.h>
#include <murmur/murmur.h>

void
minimatch_init(minimatch_t *minimatch, const of_match_t *match)
{
    int i;
    int num_words = 0;
    int idx = 0;
    uint32_t *fields = (uint32_t *)&match->fields;
    uint32_t *masks = (uint32_t *)&match->masks;

    minimatch->version = match->version;
    memset(minimatch->bitmap, 0, sizeof(minimatch->bitmap));

    /*
     * Find the nonzero match words and set their bit in the bitmap.
     */
    for (i = 0; i < OF_MATCH_FIELDS_WORDS; i++) {
        if (masks[i]) {
            num_words += 2;
            minimatch->bitmap[i/32] |= (1 << (i % 32));
        }
    }

    minimatch->num_words = num_words;
    minimatch->words = aim_malloc(sizeof(uint32_t) * num_words);

    /*
     * For each bit set in the bitmap, copy the corresponding words from the
     * fields and masks to our words array.
     */
    for (i = 0; i < OF_MATCH_FIELDS_WORDS; i++) {
        if (masks[i]) {
            minimatch->words[idx++] = fields[i];
            minimatch->words[idx++] = masks[i];
        }
    }
}

void
minimatch_cleanup(minimatch_t *minimatch)
{
    aim_free(minimatch->words);
}

void
minimatch_expand(const minimatch_t *minimatch, of_match_t *match)
{
    int i;
    int idx = 0;
    uint32_t *fields = (uint32_t *)&match->fields;
    uint32_t *masks = (uint32_t *)&match->masks;

    memset(match, 0, sizeof(*match));
    match->version = minimatch->version;

    /*
     * For each bit set in the bitmap, copy the corresponding words from the
     * words array to the match fields and masks.
     */
    for (i = 0; i < OF_MATCH_FIELDS_WORDS; i++) {
        uint32_t bitmap_word = minimatch->bitmap[i/32];
        uint32_t bit = i % 32;
        if ((bitmap_word >> bit) & 1) {
            fields[i] = minimatch->words[idx++];
            masks[i] = minimatch->words[idx++];
        }
    }
}

bool
minimatch_equal(const minimatch_t *a, const minimatch_t *b)
{
    if (memcmp(a->bitmap, b->bitmap, sizeof(a->bitmap))) {
        return false;
    }

    AIM_ASSERT(a->num_words == b->num_words, "length mismatch");

    if (memcmp(a->words, b->words, a->num_words*sizeof(uint32_t))) {
        return false;
    }

    if (a->version != b->version) {
        return false;
    }

    return true;
}

bool
minimatch_more_specific(const minimatch_t *a, const minimatch_t *b)
{
    /*
     * For each match word, check that a's mask is at least as specific as b's
     * mask and that a and b agree on the fields where b's mask is set.
     */
    /* TODO optimize */
    of_match_t match_a, match_b;
    minimatch_expand(a, &match_a);
    minimatch_expand(b, &match_b);
    return of_match_more_specific(&match_a, &match_b);
}

bool
minimatch_overlap(const minimatch_t *a, const minimatch_t *b)
{
    /*
     * For each match word, check that a and b agree on the fields where
     * the intersection of the masks is set.
     */
    of_match_t match_a, match_b;
    minimatch_expand(a, &match_a);
    minimatch_expand(b, &match_b);
    return of_match_overlap(&match_a, &match_b);
}

uint32_t
minimatch_hash(const minimatch_t *minimatch, uint32_t seed)
{
    /* TODO optimize */
    of_match_t match;
    minimatch_expand(minimatch, &match);
    return murmur_hash(&match, sizeof(match), seed);
}

void
minimatch_move(minimatch_t *dst, minimatch_t *src)
{
    *dst = *src;
    memset(src, 0, sizeof(*src));
}
