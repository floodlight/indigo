/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */
/**
 *
 * AUTOMATICALLY GENERATED FILE.  Edits will be lost on regen.
 *
 * Message-scalar tests for all versions
 * @fixme These are mostly hard coded now.
 */

#include <locitest/test_common.h>

static int
test_match_1(void)
{
    of_match_v1_t *m_v1;
    of_match_v2_t *m_v2;
    of_match_v3_t *m_v3;
    of_match_v4_t *m_v4;
    of_match_t match;
    int value = 1;
    int idx;
    uint32_t exp_value;

    /* Verify default values for ip mask map */
    for (idx = 0; idx < OF_IP_MASK_MAP_COUNT; idx++) {
        exp_value = (idx < 32) ? ~((1 << idx) - 1) : 0;
        TEST_ASSERT(of_ip_index_to_mask(idx) == exp_value);
        if (idx < 32) {
            TEST_ASSERT(of_ip_mask_to_index(exp_value) == idx);
        }
    }

    TEST_ASSERT(of_ip_mask_map_set(17, 0xabcdef00) == OF_ERROR_NONE);
    TEST_ASSERT(of_ip_mask_to_index(0xabcdef00) == 17);
    TEST_ASSERT(of_ip_index_to_mask(17) == 0xabcdef00);

    TEST_ASSERT(of_ip_mask_map_set(62, 0xabcdefff) == OF_ERROR_NONE);
    TEST_ASSERT(of_ip_mask_to_index(0xabcdefff) == 62);
    TEST_ASSERT(of_ip_index_to_mask(62) == 0xabcdefff);

    /* Test re-init */
    of_ip_mask_map_init();
    for (idx = 0; idx < OF_IP_MASK_MAP_COUNT; idx++) {
        exp_value = (idx < 32) ? ~((1 << idx) - 1) : 0;
        TEST_ASSERT(of_ip_index_to_mask(idx) == exp_value);
        if (idx < 32) {
            TEST_ASSERT(of_ip_mask_to_index(exp_value) == idx);
        }
    }

    /* Create/populate/convert and delete for version OF_VERSION_1_0 */
    m_v1 = of_match_v1_new(OF_VERSION_1_0);
    TEST_ASSERT(m_v1 != NULL);
    TEST_ASSERT((value = of_match_populate(&match, OF_VERSION_1_0, value)) > 0);
    TEST_OK(of_match_to_wire_match_v1(&match, m_v1));
    of_match_v1_delete(m_v1);

    /* Create/populate/convert and delete for version OF_VERSION_1_1 */
    m_v2 = of_match_v2_new(OF_VERSION_1_1);
    TEST_ASSERT(m_v2 != NULL);
    TEST_ASSERT((value = of_match_populate(&match, OF_VERSION_1_1, value)) > 0);
    TEST_OK(of_match_to_wire_match_v2(&match, m_v2));
    of_match_v2_delete(m_v2);

    /* Create/populate/convert and delete for version OF_VERSION_1_2 */
    m_v3 = of_match_v3_new(OF_VERSION_1_2);
    TEST_ASSERT(m_v3 != NULL);
    TEST_ASSERT((value = of_match_populate(&match, OF_VERSION_1_2, value)) > 0);
    TEST_OK(of_match_to_wire_match_v3(&match, m_v3));
    of_match_v3_delete(m_v3);

    /* Create/populate/convert and delete for version OF_VERSION_1_3 */
    m_v4 = of_match_v4_new(OF_VERSION_1_3);
    TEST_ASSERT(m_v4 != NULL);
    TEST_ASSERT((value = of_match_populate(&match, OF_VERSION_1_3, value)) > 0);
    TEST_OK(of_match_to_wire_match_v4(&match, m_v4));
    of_match_v4_delete(m_v4);

    return TEST_PASS;
}

static int
test_match_2(void)
{
    of_match_v1_t *m_v1;
    of_match_v2_t *m_v2;
    of_match_v3_t *m_v3;
    of_match_v3_t *m_v4;
    of_match_t match1;
    of_match_t match2;
    int value = 1;

    TEST_ASSERT((value = of_match_populate(&match1, OF_VERSION_1_0, value)) > 0);
    m_v1 = of_match_v1_new(OF_VERSION_1_0);
    TEST_ASSERT(m_v1 != NULL);
    TEST_OK(of_match_to_wire_match_v1(&match1, m_v1));
    TEST_OK(of_match_v1_to_match(m_v1, &match2));
    TEST_ASSERT(memcmp(&match1, &match2, sizeof(match1)) == 0);
    of_match_v1_delete(m_v1);

    TEST_ASSERT((value = of_match_populate(&match1, OF_VERSION_1_1, value)) > 0);
    m_v2 = of_match_v2_new(OF_VERSION_1_1);
    TEST_ASSERT(m_v2 != NULL);
    TEST_OK(of_match_to_wire_match_v2(&match1, m_v2));
    TEST_OK(of_match_v2_to_match(m_v2, &match2));
    TEST_ASSERT(memcmp(&match1, &match2, sizeof(match1)) == 0);
    of_match_v2_delete(m_v2);

    TEST_ASSERT((value = of_match_populate(&match1, OF_VERSION_1_2, value)) > 0);
    m_v3 = of_match_v3_new(OF_VERSION_1_2);
    TEST_ASSERT(m_v3 != NULL);
    TEST_OK(of_match_to_wire_match_v3(&match1, m_v3));
    TEST_OK(of_match_v3_to_match(m_v3, &match2));
    TEST_ASSERT(memcmp(&match1, &match2, sizeof(match1)) == 0);
    of_match_v3_delete(m_v3);

    TEST_ASSERT((value = of_match_populate(&match1, OF_VERSION_1_3, value)) > 0);
    m_v4 = of_match_v4_new(OF_VERSION_1_3);
    TEST_ASSERT(m_v4 != NULL);
    TEST_OK(of_match_to_wire_match_v4(&match1, m_v4));
    TEST_OK(of_match_v4_to_match(m_v4, &match2));
    TEST_ASSERT(memcmp(&match1, &match2, sizeof(match1)) == 0);
    of_match_v4_delete(m_v4);

    return TEST_PASS;
}

static int
test_match_3(void)
{
    of_match_t match1;
    of_match_t match2;
    int value = 1;
    of_octets_t octets;

    /* Serialize to version OF_VERSION_1_0 */
    TEST_ASSERT((value = of_match_populate(&match1, OF_VERSION_1_0, value)) > 0);
    TEST_ASSERT(of_match_serialize(OF_VERSION_1_0, &match1, &octets) ==
        OF_ERROR_NONE);
    TEST_ASSERT(of_match_deserialize(OF_VERSION_1_0, &match2, &octets) ==
        OF_ERROR_NONE);
    TEST_ASSERT(memcmp(&match1, &match2, sizeof(match1)) == 0);
    FREE(octets.data);

    /* Serialize to version OF_VERSION_1_1 */
    TEST_ASSERT((value = of_match_populate(&match1, OF_VERSION_1_1, value)) > 0);
    TEST_ASSERT(of_match_serialize(OF_VERSION_1_1, &match1, &octets) ==
        OF_ERROR_NONE);
    TEST_ASSERT(of_match_deserialize(OF_VERSION_1_1, &match2, &octets) ==
        OF_ERROR_NONE);
    TEST_ASSERT(memcmp(&match1, &match2, sizeof(match1)) == 0);
    FREE(octets.data);

    /* Serialize to version OF_VERSION_1_2 */
    TEST_ASSERT((value = of_match_populate(&match1, OF_VERSION_1_2, value)) > 0);
    TEST_ASSERT(of_match_serialize(OF_VERSION_1_2, &match1, &octets) ==
        OF_ERROR_NONE);
    TEST_ASSERT(of_match_deserialize(OF_VERSION_1_2, &match2, &octets) ==
        OF_ERROR_NONE);
    TEST_ASSERT(memcmp(&match1, &match2, sizeof(match1)) == 0);
    FREE(octets.data);

    /* Serialize to version OF_VERSION_1_3 */
    TEST_ASSERT((value = of_match_populate(&match1, OF_VERSION_1_3, value)) > 0);
    TEST_ASSERT(of_match_serialize(OF_VERSION_1_3, &match1, &octets) ==
        OF_ERROR_NONE);
    TEST_ASSERT(of_match_deserialize(OF_VERSION_1_3, &match2, &octets) ==
        OF_ERROR_NONE);
    TEST_ASSERT(memcmp(&match1, &match2, sizeof(match1)) == 0);
    FREE(octets.data);

    return TEST_PASS;
}

int run_match_tests(void)
{
    RUN_TEST(match_1);
    RUN_TEST(match_2);
    RUN_TEST(match_3);
    RUN_TEST(match_utils);

    return TEST_PASS;
}
