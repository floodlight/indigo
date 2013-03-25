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

/* Copyright 2013, Big Switch Networks, Inc. */

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
