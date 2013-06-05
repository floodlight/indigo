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

/******************************************************************************
 *
 *  /utest/main.c
 *
 *  BigList Unit Testing
 *
 *****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <BigList/biglist.h>

#define FAIL(list, fmt, ...)                                        \
    do {                                                            \
        printf("\n");                                               \
        printf("%s:%d: failure: ", __FUNCTION__, __LINE__);         \
        printf(fmt, __VA_ARGS__);                                   \
        printf("\n");                                               \
        biglist_dump(list, NULL);                                   \
        printf("\n\n");                                             \
        return -1;                                                  \
    } while(0)


#define FATAL(fmt, ...)                                     \
    do {                                                    \
        printf("%s:%d: fatal: ", __FUNCTION__, __LINE__);   \
        printf(fmt, __VA_ARGS__);                           \
        printf("\n");                                       \
        return -1;                                          \
    } while(0)

#define IP(i) ( (void*)(long)(i) )
#define PI(i) ( (int)(long)(i) )

biglist_t*
__makeList(int start, int end, int step)
{
    biglist_t* bl = NULL;
    int i;
    for(i = start; i != end; i += step) {
        bl = biglist_append(bl, IP(i));
    }
    return bl;
}

#define BLFREE(_bl, _count)                                             \
    do {                                                                \
        int _c = biglist_free(_bl);                                     \
        if(_c != _count) {                                              \
            FAIL(_bl, "error during free: count=%d, free=%d", _count, _c); \
        }                                                               \
        _bl= NULL;                                                      \
    } while(0)

static int
__compare(const void* a, const void* b)
{
    if(a == b) {
        return 0;
    }
    return (a > b) ? 1 : -1;
}

static int iterCount = 0;

static int
__iter(void* data, void* cookie)
{
    if(cookie != (void*)0xDEAD) {
        FAIL(NULL, "fail in iter, cookie=%p", cookie);
    }
    iterCount += PI(data);
    return 0;
}
static int
__iterStop(void* data, void* cookie)
{
    if(cookie == data) {
        iterCount = PI(data);
        return -1;
    }
    return 0;
}

static int
__find(void* data, void* cookie)
{
    if(cookie == data) {
        return 0;
    }
    return -1;
}

int utest_BigList(void)
{
    biglist_t* ble;
    biglist_t* bl = NULL;
    int i = 0;

    /* biglist_append */
    for(i = 0; i < 10; i++) {
        bl = biglist_append(bl, IP(i));
    }
    for(i = 0, ble = bl; ble; ble = ble->next, i++) {
        if(ble->data != IP(i)) {
            FAIL(bl, "elements do not match at %d", i);
        }
    }
    BLFREE(bl, 10);

    /* biglist_length */
    bl = __makeList(0, 10, 1);
    if((i=biglist_length(bl)) != 10) {
        FAIL(bl, "biglist_length fail, is %d, should be 10", i);
    }
    BLFREE(bl, 10);

    /* biglist_last */
    bl = __makeList(0, 10, 1);
    ble = biglist_last(bl);
    if(ble == NULL || ble->data != (IP(9))) {
        FAIL(bl, "last fail, last=%p", (ble) ? ble->data : NULL);
    }
    BLFREE(bl, 10);

    /* biglist_prepend */
    for(i = 0; i < 10; i++) {
        bl = biglist_prepend(bl, IP(i));
    }
    for(i = 9, ble=bl; ble; ble = ble->next, i--) {
        if(ble->data != IP(i)) {
            FAIL(bl, "biglist_prepend: elements do not match at %d", i);
        }
    }
    BLFREE(bl, 10);

    /* biglist_remove */
    bl = __makeList(0, 10, 1);
    ble = biglist_find(bl, (void*)7);
    if(ble == NULL || ble->data != (void*)7) {
        FAIL(bl, "could not find element %d", 7);
    }
    bl = biglist_remove(bl, (void*)7);
    if((i=biglist_length(bl)) != 9) {
        FAIL(bl, "length of %d incorrect after remove", i);
    }
    ble = biglist_find(bl, (void*)7);
    if(ble != NULL) {
        FAIL(bl, "found element %d", 7);
    }
    BLFREE(bl, 9);

    /* biglist_reverse */
    bl = __makeList(0, 10, 1);
    bl = biglist_reverse(bl);
    for(i = 9, ble = bl; ble; ble = ble->next, i--) {
        if(ble->data != IP(i)) {
            FAIL(bl, "reverse fail at %d", i);
        }
    }
    BLFREE(bl, 10);

    /* biglist_next */
    bl = __makeList(0, 10, 1);
    for(i = 0, ble = bl; ble; ble = biglist_next(ble), i++) {
        if(ble->data != IP(i)) {
            FAIL(bl, "biglist_next: element wrong at %d, data=%p", i, ble->data);
        }
    }
    BLFREE(bl, 10);


    /* biglist_to_array */
    {
        int size = 0;
        biglist_t** bla;
        bl = __makeList(0, 10, 1);
        bla = biglist_to_array(bl, &size);
        if(bla == NULL || size==0) {
            FAIL(bl, "to_array: failed bla=%p size=%d", (void*)bla, size);
            if(size != 10) {
                FAIL(bl, "to_array: size is wrong at %d", size);
            }
        }
        for(i = 0, ble = bl; i < size; ble = biglist_next(ble), i++) {
            if(bla[i] != ble) {
                FAIL(bl, "to_array: incorrect at %d", i);
            }
        }
        free(bla);
        BLFREE(bl, 10);
    }

    /* biglist_from_array */
    {
        biglist_t* a[5];
        for(i = 0; i < 5; i++) {
            a[i] = biglist_alloc(IP(i), NULL, NULL);
        }
        bl = biglist_from_array(a, 5);
        if(bl == NULL) {
            FAIL(bl, "from_array: failed %p", (void*)bl);
        }
        if(biglist_length(bl) != 5) {
            FAIL(bl, "from_array: failed len=%d", biglist_length(bl));
        }
    }
    BLFREE(bl, 5);

    {
        /* biglist_sort */
        biglist_t* b1 = __makeList(0, 10, 1);
        biglist_t* b2 = __makeList(20, 30, 1);
        biglist_t* b3 = __makeList(10, 20, 1);
        biglist_t* b4 = __makeList(30, 40, 1);
        bl = biglist_append_list(b1, b2);
        bl = biglist_append_list(bl, b3);
        bl = biglist_append_list(bl, b4);
        bl = biglist_sort(bl, (biglist_compare_f)__compare);
        for(i = 0, ble = bl; ble; ble = biglist_next(ble), i++) {
            if(ble->data != IP(i)) {
                FAIL(bl, "biglist_sort: failed at %d", i);
            }
        }
        /* biglist_insert_sorted */
        bl = biglist_remove(bl, IP(20));
        if(biglist_find(bl, IP(20))) {
            FAIL(bl, "remove 20 failed %p", NULL);
        }
        bl = biglist_insert_sorted(bl, IP(20), (biglist_compare_f)__compare);
        for(i = 0, ble = bl; ble; ble = biglist_next(ble), i++) {
            if(ble->data != IP(i)) {
                FAIL(bl, "biglist_insert_sorted: failed at %d", i);
            }
        }
        BLFREE(bl, 40);
    }

    /* biglist_foreach */
    iterCount = 0;
    bl = __makeList(0, 10, 1);
    i = biglist_foreach(bl, __iter, (void*)0xDEAD);
    if(i != 0 || iterCount != 45) {
        FAIL(bl, "biglist_iter failed, i=%d, count=%d", i, iterCount);
    }
    i = biglist_foreach(bl, __iterStop, IP(19));
    if(i != 0) {
        FAIL(bl, "biglist_iter failed i=%d", i);
    }
    i = biglist_foreach(bl, __iterStop, IP(5));
    if(i >= 0|| iterCount != 5) {
        FAIL(bl, "biglist_iter failed, i=%d count=%d", i, iterCount);
    }
    BLFREE(bl, 10);

    /* biglist_find_custom */
    bl = __makeList(0, 10, 1);
    ble = biglist_find_custom(bl, (biglist_compare_f)__find, IP(4));
    if(ble == NULL || ble->data != IP(4)) {
        FAIL(bl, "find_custom failed ble=%p data=%p", (void*)ble, (ble) ? (void*)ble->data : NULL);
    }
    ble = biglist_find_custom(bl, (biglist_compare_f)__find, IP(10));
    if (ble != NULL) {
        FAIL(bl, "expected biglist_find_custom to fail ble=%p", ble);
    }
    BLFREE(bl, 10);

    /* biglist_remove_link */
    bl = __makeList(0, 10, 1);
    ble = bl->next->next;
    bl = biglist_remove_link(bl, ble);
    if((i=biglist_length(bl)) != 9) {
        FAIL(bl, "biglist_length fail, is %d, should be 9", i);
    }
    BLFREE(bl, 9);
    biglist_free(ble);

    /* biglist_remove_link_free */
    bl = __makeList(0, 10, 1);
    ble = bl->next->next;
    bl = biglist_remove_link_free(bl, ble);
    if((i=biglist_length(bl)) != 9) {
        FAIL(bl, "biglist_length fail, is %d, should be 9", i);
    }
    BLFREE(bl, 9);

    /* biglist_copy */
    {
        bl = __makeList(0, 10, 1);
        biglist_t* copy = biglist_copy(bl);
        biglist_t* src;
        biglist_t* dst;
        if((i=biglist_length(copy))!=10) {
            FAIL(copy, "biglist_length of copy failed, is %d, should be 10", i);
        }
        for(i = 0, src=bl, dst=copy; src && dst;
            src=src->next, dst=dst->next, i++) {
            if(src->data != dst->data) {
                FAIL(copy, "Element %d in srclist (%p) does not match copied list (%p)",
                     i, src->data, dst->data);
            }
        }
        BLFREE(bl, 10);
        BLFREE(copy, 10);
    }
    return 0;
}

int main(int argc, char* argv[])
{
    int rc;

    (void) argc;
    (void) argv;

    rc = utest_BigList();
    if(rc < 0) {
        return rc;
    }
    printf("PASS\n");
    return 0;
}
