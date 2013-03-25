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

/**************************************************************************//**
 *
 * Intrusive, circular, doubly linked list.
 *
 * The implementation of this module is deliberately not private. It is
 * expected that users will use the next/prev pointers directly.
 *
 * @file
 * @addtogroup aim-list
 * @{
 *
 *****************************************************************************/
#ifndef __AIM_LIST_H__
#define __AIM_LIST_H__

#include <AIM/aim_config.h>
#include <stddef.h>

/** Link structure. */
typedef struct list_links {
    /** Previous */
    struct list_links *prev;
    /** Next */
    struct list_links *next;
} list_links_t;

/** List head. */
typedef struct list_head {
    /** Links */
    struct list_links links;
} list_head_t;

/**
 * Calculate the address of the struct (of type `type`) containing the given
 * field `field` at address `ptr`.
 */
#ifndef container_of
#define container_of(ptr, field, type) \
    (type *)((char *)(ptr) - offsetof(type, field))
#endif

/**
 * cur should be a struct list_links * variable.
 */
#define LIST_FOREACH(head, cur) \
    for (cur = (head)->links.next; cur != &(head)->links; cur = cur->next)

/**
 * This version of LIST_FOREACH saves the next pointer in a temporary variable
 * so that the current links can be safely freed.
 * cur and next should be struct list_links * variables.
 */
#define LIST_FOREACH_SAFE(head, cur, next) \
    for (cur = (head)->links.next; next = cur->next, cur != &(head)->links; cur = next)

/** Only used to initialize the list head, not the individual elements. */
static inline void
list_init(struct list_head *head)
{
    head->links.next = &head->links;
    head->links.prev = &head->links;
}

/** Used for static definition and initialization. */
#define __LIST_STATIC_INIT(_head) { { &_head.links, &_head.links } }
/** Used for static definition and initialization. */
#define LIST_DEFINE(_name) list_head_t _name = __LIST_STATIC_INIT(_name)

/** List empty */
static inline int
list_empty(struct list_head *head)
{
    return head->links.next == &head->links;
}
/** List insert before */
static inline void
list_insert_before(struct list_links *target, struct list_links *el)
{
    el->next = target;
    el->prev = target->prev;
    target->prev->next = el;
    target->prev = el;
}

static inline void
list_insert_after(struct list_links *target, struct list_links *el)
{
    el->next = target->next;
    el->prev = target;
    target->next->prev = el;
    target->next = el;
}

static inline void
list_remove(struct list_links *el)
{
    el->prev->next = el->next;
    el->next->prev = el->prev;
}

/* Insert at tail */
static inline void
list_push(struct list_head *head, struct list_links *el)
{
    list_insert_before(&head->links, el);
}

/* Remove at tail */
static inline struct list_links *
list_pop(struct list_head *head)
{
    struct list_links *tmp;
    if (list_empty(head)) {
        return NULL;
    }
    tmp = head->links.prev;
    list_remove(tmp);
    return tmp;
}

/* Insert at head */
static inline void
list_unshift(struct list_head *head, struct list_links *el)
{
    list_insert_after(&head->links, el);
}

/* Remove at head */
static inline struct list_links *
list_shift(struct list_head *head)
{
    struct list_links *tmp;
    if (list_empty(head)) {
        return NULL;
    }
    tmp = head->links.next;
    list_remove(tmp);
    return tmp;
}

static inline void
list_move(struct list_head *src_head, struct list_head *dst_head)
{
    if (!list_empty(src_head)) {
        *dst_head = *src_head;
        list_init(src_head);
        dst_head->links.next->prev = &dst_head->links;
        dst_head->links.prev->next = &dst_head->links;
    } else {
        list_init(dst_head);
    }
}

static inline int
list_length(struct list_head *head)
{
    int n = 0;
    struct list_links *cur;
    LIST_FOREACH(head, cur) {
        n++;
    }
    return n;
}

#endif /* __AIM_LIST_H__ */
/* @}*/
