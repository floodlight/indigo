/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */

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
