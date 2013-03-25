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

#ifndef UNITTEST_H
#define UNITTEST_H

#include <stdio.h>

#define TEST_PASS 1
#define TEST_FAIL 0

#define TESTCASE(foo, rv) do {                                          \
        fprintf(stderr, "test %s:", #foo);                              \
        fprintf(stderr, "  %s\n", (rv = test_##foo()) ? "PASS" : "FAIL"); \
    } while (0)

#define TEST_ASSERT(result) if (!(result)) do {                         \
        fprintf(stderr, "\nTEST ASSERT FAILURE "                        \
               #result " :: %s:%d\n",__FILE__,__LINE__);                \
        ASSERT(0);                                                      \
        return TEST_FAIL;                                               \
    } while (0)

#define TEST_ASSERT_EQUAL(expected, result) \
    TEST_ASSERT(((expected) == (result)))

#define TEST_ASSERT_NOT_EQUAL(expected, result) \
    TEST_ASSERT(((expected) != (result)))

#endif
