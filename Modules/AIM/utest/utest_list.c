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
 *  list Unit Testing
 *
 *****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <AIM/aim_list.h>

int utest_list(void)
{
    /* test init */
    {
        struct list_head head;
        list_init(&head);
        assert(list_empty(&head));
        assert(list_length(&head) == 0);
    }

    /* Test push/pop (stack) */
    {
        struct list_head head;
        struct list_links a, b, c;
        list_init(&head);
        assert(list_pop(&head) == NULL);

        list_push(&head, &a);
        list_push(&head, &b);
        list_push(&head, &c);
        assert(list_length(&head) == 3);

        assert(list_pop(&head) == &c);
        assert(list_pop(&head) == &b);
        assert(list_pop(&head) == &a);
        assert(list_empty(&head));
    }

    /* Test unshift/shift (stack) */
    {
        struct list_head head;
        struct list_links a, b, c;
        list_init(&head);
        assert(list_shift(&head) == NULL);

        list_unshift(&head, &a);
        list_unshift(&head, &b);
        list_unshift(&head, &c);
        assert(list_length(&head) == 3);

        assert(list_shift(&head) == &c);
        assert(list_shift(&head) == &b);
        assert(list_shift(&head) == &a);
        assert(list_empty(&head));
    }

    /* Test push/shift (queue) */
    {
        struct list_head head;
        struct list_links a, b, c;
        list_init(&head);

        list_push(&head, &a);
        list_push(&head, &b);
        list_push(&head, &c);
        assert(list_length(&head) == 3);

        assert(list_shift(&head) == &a);
        assert(list_shift(&head) == &b);
        assert(list_shift(&head) == &c);
        assert(list_empty(&head));
    }

    /* Test remove */
    {
        struct list_head head;
        struct list_links a, b, c;
        list_init(&head);

        list_push(&head, &a);
        list_push(&head, &b);
        list_push(&head, &c);
        assert(list_length(&head) == 3);

        list_remove(&b);
        assert(list_length(&head) == 2);
        list_remove(&c);
        assert(list_length(&head) == 1);
        list_remove(&a);
        assert(list_length(&head) == 0);
        assert(list_empty(&head));
    }

    /* Test insert_before */
    {
        struct list_head head;
        struct list_links a, b;
        list_init(&head);

        list_push(&head, &a);
        list_insert_before(&a, &b);
        assert(list_length(&head) == 2);
        assert(head.links.next == &b);
        assert(a.prev == &b);
    }

    /* Test insert_after */
    {
        struct list_head head;
        struct list_links a, b;
        list_init(&head);

        list_push(&head, &a);
        list_insert_after(&a, &b);
        assert(list_length(&head) == 2);
        assert(a.next == &b);
        assert(head.links.prev == &b);
    }

    /* Test move */
    {
        struct list_head head1, head2;
        struct list_links a;
        list_init(&head1);

        list_push(&head1, &a);
        list_move(&head1, &head2);
        assert(list_empty(&head1));
        assert(list_length(&head2) == 1);
    }

    /* Test foreach */
    {
        struct list_head head;
        struct list_links a, b, c, *cur;
        int i = 0;
        list_init(&head);
        list_push(&head, &a);
        list_push(&head, &b);
        list_push(&head, &c);
        assert(list_length(&head) == 3);

        LIST_FOREACH(&head, cur) {
            if (i == 0) assert(cur == &a);
            else if (i == 1) assert(cur == &b);
            else if (i == 2) assert(cur == &c);
            else (assert(0));
            i++;
        }

        assert(i == 3);
    }

    /* Test foreach_safe */
    {
        struct list_head head;
        struct list_links a, b, c, *cur, *next;
        int i = 0;
        list_init(&head);
        list_push(&head, &a);
        list_push(&head, &b);
        list_push(&head, &c);
        assert(list_length(&head) == 3);

        LIST_FOREACH_SAFE(&head, cur, next) {
            if (i == 0) assert(cur == &a);
            else if (i == 1) { assert(cur == &b); list_remove(cur); }
            else if (i == 2) assert(cur == &c);
            else (assert(0));
            i++;
        }

        assert(i == 3);
    }

    return 0;
}
