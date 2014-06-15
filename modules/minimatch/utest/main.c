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

static void
test_basic(void)
{
    minimatch_t a, b, c;
    of_match_t match_tmp;

    of_match_t match1 = {
        .version = OF_VERSION_1_0,
        .fields = {
            .vlan_vid = 0x567,
            .eth_dst = { { 0x12, 0x34, 0x56, 0x78, 0x9a, 0xbc } },
        },
        .masks = {
            .vlan_vid = 0xffff,
            .eth_dst = { { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff } },
        },
    };

    /* Same mask as match1, different fields */
    of_match_t match2 = {
        .version = OF_VERSION_1_0,
        .fields = {
            .vlan_vid = 0x567,
            .eth_dst = { { 0x12, 0x34, 0x56, 0x78, 0x9a, 0xbd } },
        },
        .masks = {
            .vlan_vid = 0xffff,
            .eth_dst = { { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff } },
        },
    };

    /* More specific version of match2 */
    of_match_t match3 = {
        .version = OF_VERSION_1_0,
        .fields = {
            .vlan_vid = 0x567,
            .eth_dst = { { 0x12, 0x34, 0x56, 0x78, 0x9a, 0xbd } },
            .eth_type = 0x0800,
        },
        .masks = {
            .vlan_vid = 0xffff,
            .eth_dst = { { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff } },
            .eth_type = 0xffff,
        },
    };

    /* Verify match more-specific */
    AIM_ASSERT(of_match_more_specific(&match1, &match1));
    AIM_ASSERT(!of_match_more_specific(&match1, &match2));
    AIM_ASSERT(!of_match_more_specific(&match1, &match3));
    AIM_ASSERT(!of_match_more_specific(&match2, &match1));
    AIM_ASSERT(of_match_more_specific(&match2, &match2));
    AIM_ASSERT(!of_match_more_specific(&match2, &match3));
    AIM_ASSERT(!of_match_more_specific(&match3, &match1));
    AIM_ASSERT(of_match_more_specific(&match3, &match2));
    AIM_ASSERT(of_match_more_specific(&match3, &match3));

    /* Verify match overlap */
    AIM_ASSERT(of_match_overlap(&match1, &match1));
    AIM_ASSERT(!of_match_overlap(&match1, &match2));
    AIM_ASSERT(!of_match_overlap(&match1, &match3));
    AIM_ASSERT(!of_match_overlap(&match2, &match1));
    AIM_ASSERT(of_match_overlap(&match2, &match2));
    AIM_ASSERT(of_match_overlap(&match2, &match3));
    AIM_ASSERT(!of_match_overlap(&match3, &match1));
    AIM_ASSERT(of_match_overlap(&match3, &match2));
    AIM_ASSERT(of_match_overlap(&match3, &match3));

    minimatch_init(&a, &match1);
    minimatch_init(&b, &match2);
    minimatch_init(&c, &match3);

    /* Minimatches should expand to the original match */
    minimatch_expand(&a, &match_tmp);
    AIM_ASSERT(of_match_eq(&match1, &match_tmp), "");
    minimatch_expand(&b, &match_tmp);
    AIM_ASSERT(of_match_eq(&match2, &match_tmp), "");
    minimatch_expand(&c, &match_tmp);
    AIM_ASSERT(of_match_eq(&match3, &match_tmp), "");

    /* Test equality */
    AIM_ASSERT(minimatch_equal(&a, &a), "");
    AIM_ASSERT(!minimatch_equal(&a, &b), "");
    AIM_ASSERT(!minimatch_equal(&a, &c), "");
    AIM_ASSERT(!minimatch_equal(&b, &a), "");
    AIM_ASSERT(minimatch_equal(&b, &b), "");
    AIM_ASSERT(!minimatch_equal(&b, &c), "");
    AIM_ASSERT(!minimatch_equal(&c, &a), "");
    AIM_ASSERT(!minimatch_equal(&c, &b), "");
    AIM_ASSERT(minimatch_equal(&c, &c), "");

    /* Test more-specific */
    AIM_ASSERT(minimatch_more_specific(&a, &a), "");
    AIM_ASSERT(!minimatch_more_specific(&a, &b), "");
    AIM_ASSERT(!minimatch_more_specific(&a, &c), "");
    AIM_ASSERT(!minimatch_more_specific(&b, &a), "");
    AIM_ASSERT(minimatch_more_specific(&b, &b), "");
    AIM_ASSERT(!minimatch_more_specific(&b, &c), "");
    AIM_ASSERT(!minimatch_more_specific(&c, &a), "");
    AIM_ASSERT(minimatch_more_specific(&c, &b), "");
    AIM_ASSERT(minimatch_more_specific(&c, &c), "");

    /* Test overlap */
    AIM_ASSERT(minimatch_overlap(&a, &a), "");
    AIM_ASSERT(!minimatch_overlap(&a, &b), "");
    AIM_ASSERT(!minimatch_overlap(&a, &c), "");
    AIM_ASSERT(!minimatch_overlap(&b, &a), "");
    AIM_ASSERT(minimatch_overlap(&b, &b), "");
    AIM_ASSERT(minimatch_overlap(&b, &c), "");
    AIM_ASSERT(!minimatch_overlap(&c, &a), "");
    AIM_ASSERT(minimatch_overlap(&c, &b), "");
    AIM_ASSERT(minimatch_overlap(&c, &c), "");

    minimatch_cleanup(&a);
    minimatch_cleanup(&b);
    minimatch_cleanup(&c);
}

void
random_match(of_match_t *match)
{
    memset(match, 0, sizeof(*match));
    match->version = OF_VERSION_1_3;

    uint8_t *fields = (uint8_t *)&match->fields;
    uint8_t *masks = (uint8_t *)&match->masks;

    /* Use a very small portion of the match to ensure we get some
     * equal/overlap/more-specific matches. */
    const int match_bytes = 12;
    AIM_ASSERT(match_bytes < sizeof(of_match_t));
    AIM_ASSERT(match_bytes*2 <= 32);

    uint32_t r = random();

    int i;
    for (i = 0; i < match_bytes; i++) {
        uint8_t mask = r & 1;
        r >>= 1;
        uint8_t field = r & mask;
        r >>= 1;
        fields[i] = field;
        masks[i] = mask;
    }
}

void
test_random(void)
{
    int i;
    int collisions = 0;
    const int num_iters = 1000000;

    for (i = 0; i < num_iters; i++) {
        of_match_t match_a, match_b, match_tmp;
        minimatch_t minimatch_a, minimatch_b;

        random_match(&match_a);
        random_match(&match_b);

        minimatch_init(&minimatch_a, &match_a);
        minimatch_init(&minimatch_b, &match_b);

        minimatch_expand(&minimatch_a, &match_tmp);
        AIM_ASSERT(of_match_eq(&match_a, &match_tmp), "");

        minimatch_expand(&minimatch_b, &match_tmp);
        AIM_ASSERT(of_match_eq(&match_b, &match_tmp), "");

        AIM_ASSERT(minimatch_equal(&minimatch_a, &minimatch_b) == of_match_eq(&match_a, &match_b));
        AIM_ASSERT(minimatch_more_specific(&minimatch_a, &minimatch_b) == of_match_more_specific(&match_a, &match_b));
        AIM_ASSERT(minimatch_overlap(&minimatch_a, &minimatch_b) == of_match_overlap(&match_a, &match_b));

        if (minimatch_hash(&minimatch_a, 0) == minimatch_hash(&minimatch_b, 0)) {
            if (!minimatch_equal(&minimatch_a, &minimatch_b)) {
                collisions++;
            }
        }
    }

    AIM_ASSERT(collisions < num_iters/10000, "too many hash collisions (%d)", collisions);
}

int
main(int argc, char* argv[])
{
    test_basic();
    test_random();
    return 0;
}
