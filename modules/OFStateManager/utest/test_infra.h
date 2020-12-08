
#ifndef __TEST_INFRA__
#define __TEST_INFRA__

#define TEST_PASS 1
#define TEST_FAIL 0

#define TESTCASE(foo, rv) do {                                          \
        fprintf(stderr, "test %s:", #foo);                              \
        fprintf(stderr, "  %s\n", (rv = test_##foo()) ? "PASS" : "FAIL"); \
    } while (0)

#define TEST_ASSERT(result) if (!(result)) do {                         \
        fprintf(stderr, "\nTEST LOCI_ASSERT FAILURE "                   \
               #result " :: %s:%d\n",__FILE__,__LINE__);                \
        LOCI_ASSERT(0);                                                 \
        return TEST_FAIL;                                               \
    } while (0)

extern int global_error;
extern int exit_on_error;

#define RUN_TEST(test) do {                                             \
        int rv;                                                         \
        TESTCASE(test, rv);                                             \
        if (rv != TEST_PASS) {                                          \
            global_error=1;                                             \
            if (exit_on_error) return(1);                               \
        }                                                               \
    } while(0)

#define TEST_OK(op) TEST_ASSERT((op) == OF_ERROR_NONE)
#define TEST_INDIGO_OK(op) TEST_ASSERT((op) == INDIGO_ERROR_NONE)

#endif
