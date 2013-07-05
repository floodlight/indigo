/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */

/**
 * Test code for setup from flow add routines
 */

#include <locitest/test_common.h>

/* mcheck is a glibc extension */
#if defined(__linux__)
#include <mcheck.h>
#define MCHECK_INIT mcheck(NULL)
#else
#define MCHECK_INIT do { } while (0)
#endif


static int
test_removed_setup_from_add(void)
{
    of_flow_removed_t *removed;
    of_flow_add_t *add;
    of_match_t m1, m2;

    TEST_ASSERT((add = of_flow_add_new(OF_VERSION_1_0)) != NULL);
    TEST_ASSERT((removed = of_flow_removed_new(OF_VERSION_1_0)) != NULL);

    TEST_ASSERT(of_flow_add_OF_VERSION_1_0_populate(add, 1) != 0);
    TEST_ASSERT(of_flow_add_match_get(add, &m1) == 0);

    TEST_ASSERT(of_flow_removed_setup_from_flow_add(removed, add) == 0);
    TEST_ASSERT(of_flow_removed_match_get(removed, &m2) == 0);
    TEST_ASSERT(memcmp(&m1, &m2, sizeof(m1)) == 0);

    of_flow_add_delete(add);
    of_flow_removed_delete(removed);

    return TEST_PASS;
}


static int
test_stats_entry_setup_from_add(void)
{
    of_flow_add_t *add;
    of_flow_stats_entry_t *entry;
    of_match_t m1, m2;
    of_list_action_t *list;
    of_list_action_t list_out;

    TEST_ASSERT((add = of_flow_add_new(OF_VERSION_1_0)) != NULL);
    TEST_ASSERT((entry = of_flow_stats_entry_new(OF_VERSION_1_0)) != NULL);

    TEST_ASSERT(of_flow_add_OF_VERSION_1_0_populate(add, 1) != 0);
    TEST_ASSERT(of_flow_add_match_get(add, &m1) == 0);

    TEST_ASSERT(of_flow_stats_entry_setup_from_flow_add(entry, add, NULL) == 0);
    TEST_ASSERT(of_flow_stats_entry_match_get(entry, &m2) == 0);
    TEST_ASSERT(memcmp(&m1, &m2, sizeof(m1)) == 0);

    of_flow_add_delete(add);
    of_flow_stats_entry_delete(entry);

    /* @todo check action lists agree */

    /* Same with an external action list */

    TEST_ASSERT((add = of_flow_add_new(OF_VERSION_1_0)) != NULL);
    TEST_ASSERT((entry = of_flow_stats_entry_new(OF_VERSION_1_0)) != NULL);

    TEST_ASSERT(of_flow_add_OF_VERSION_1_0_populate(add, 1) != 0);
    TEST_ASSERT(of_flow_add_match_get(add, &m1) == 0);

    list = of_list_action_new(OF_VERSION_1_0);
    TEST_ASSERT(list != NULL);
    TEST_ASSERT(of_list_action_OF_VERSION_1_0_populate(list, 1) != 0);

    /* Verify matches agree */
    TEST_ASSERT(of_flow_stats_entry_setup_from_flow_add(entry, add, list) == 0);
    TEST_ASSERT(of_flow_stats_entry_match_get(entry, &m2) == 0);
    TEST_ASSERT(memcmp(&m1, &m2, sizeof(m1)) == 0);

    of_list_action_init(&list_out, OF_VERSION_1_0, 0, 1);
    of_flow_stats_entry_actions_bind(entry, &list_out);

    /* Verify lists agree */
    TEST_ASSERT(list->length == list_out.length);
    TEST_ASSERT(memcmp(WBUF_BUF(list->wire_object.wbuf),
                       WBUF_BUF(list_out.wire_object.wbuf),
                       list->length));

    of_flow_add_delete(add);
    of_list_action_delete(list);
    of_flow_stats_entry_delete(entry);

    return TEST_PASS;
}


int run_setup_from_add_tests(void)
{
    RUN_TEST(removed_setup_from_add);
    RUN_TEST(stats_entry_setup_from_add);

    return TEST_PASS;
}
