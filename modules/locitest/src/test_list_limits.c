/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */

/**
 * Test that list append fails gracefully when running out of wire buffer
 * space.
 */

#include <locitest/test_common.h>

static int
test_list_limits(void)
{
    of_flow_stats_reply_t *obj = of_flow_stats_reply_new(OF_VERSION_1_0);
    of_list_flow_stats_entry_t list;
    of_flow_stats_entry_t *element = of_flow_stats_entry_new(OF_VERSION_1_0);
    int i = 0;

    of_flow_stats_reply_entries_bind(obj, &list);

    ASSERT(element != NULL);


    while (1) {
        int rv = of_list_flow_stats_entry_append(&list, element);
        ASSERT(rv == OF_ERROR_NONE || rv == OF_ERROR_RESOURCE);
        if (rv != OF_ERROR_NONE) {
            break;
        }
        i++;
    }

    ASSERT(i == 744);

    of_flow_stats_entry_delete(element);
    of_flow_stats_reply_delete(obj);
    return TEST_PASS;
}

static int
test_list_limits_bind(void)
{
    of_flow_stats_reply_t *obj = of_flow_stats_reply_new(OF_VERSION_1_0);
    of_list_flow_stats_entry_t list;
    int i = 0;
    of_flow_stats_reply_entries_bind(obj, &list);


    while (1) {
        of_flow_stats_entry_t element;
        int rv; 
        of_flow_stats_entry_init(&element, OF_VERSION_1_0, -1, 1);
        rv = of_list_flow_stats_entry_append_bind(&list, &element);
        ASSERT(rv == OF_ERROR_NONE || rv == OF_ERROR_RESOURCE);
        if (rv != OF_ERROR_NONE) {
            break;
        }
        i++;
    }

    ASSERT(i == 744);

    of_flow_stats_reply_delete(obj);
    return TEST_PASS;
}

int
run_list_limits_tests(void)
{
    RUN_TEST(list_limits);
    RUN_TEST(list_limits_bind);

    return TEST_PASS;
}
