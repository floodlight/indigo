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
 * module/inc/biglist.h
 *
 * @file
 * @brief Biglist Doubly Linked List Implementation
 *
 * @addtogroup biglist-biglist
 * @{
 *
 *****************************************************************************/
#ifndef __BIGLIST_H__
#define __BIGLIST_H__

#include <AIM/aim.h>

/**
 * BigList Element.
 */
typedef struct biglist_s {
    /** Client data pointer. */
    void* data;

    /** next */
    struct biglist_s* next;
    /** previous */
    struct biglist_s* previous;
} biglist_t;

/**
 * @brief Allocate a biglist element structure.
 * @param data The value for the element's data pointer.
 * @param previous The value for the element's previous pointer.
 * @param next The value for the element's next pointer.
 */
biglist_t* biglist_alloc(void* data, biglist_t* previous, biglist_t* next);

/**
 * Function used to compare client data.
 */
typedef int (*biglist_compare_f)(const void* a, const void* b);

/**
 * Function used to iterate over client data.
 */
typedef int (*biglist_iter_f)(void* data, void* cookie);

/**
 * @brief Get the next element.
 * @param ble The current element.
 * @returns The next element in the list.
 */
biglist_t* biglist_next(biglist_t* ble);

/**
 * @brief Get the final element.
 * @param bl The list.
 * @returns The final element in the list.
 */
biglist_t* biglist_last(biglist_t* bl);

/**
 * @brief Prepend an element.
 * @param bl The list
 * @param data The client data to prepend.
 * @returns The new list.
 */
biglist_t* biglist_prepend(biglist_t* bl, void* data);

/**
 * @brief Append an element.
 * @param bl The list
 * @param data The client data to append.
 * @returns The new list.
 */
biglist_t* biglist_append(biglist_t* bl, void* data);

/**
 * @brief Append a list to another list.
 * @param bl The list.
 * @param back The list to append.
 * @returns The new list.
 */
biglist_t* biglist_append_list(biglist_t* bl, biglist_t* back);

/**
 * @brief Prepend a list to another list.
 * @param bl The list.
 * @param front The list to prepend.
 * @returns The new list.
 */
biglist_t* biglist_prepend_list(biglist_t* bl, biglist_t* front);

/**
 * @brief Reverse the elements in a list.
 * @param bl The list
 * @returns The new list.
 */
biglist_t* biglist_reverse(biglist_t* bl);

/**
 * @brief Iterate over all elements in the list.
 * @param bl The list
 * @param iter The iteration function.
 * @param cookie Cookie passed to your iterator.
 * @returns 0 if iter returned 0 for all elements, nonzero otherwise
 *
 * If iter returns a nonzero value for any element then iteration will
 * stop and that value will be returned by biglist_foreach.
 */
int biglist_foreach(biglist_t* bl, biglist_iter_f iter, void* cookie);

/**
 * @brief Sort the list.
 * @param bl The list.
 * @param cmp The element comparator function.
 * @returns The new list.
 */
biglist_t* biglist_sort(biglist_t* bl, biglist_compare_f cmp);

/**
 * @brief Insert an element into a sorted list.
 * @param bl The list
 * @param data The data to insert.
 * @param cmp The element comparator function.
 * @returns The new list.
 */
biglist_t* biglist_insert_sorted(biglist_t* bl, void* data, biglist_compare_f cmp);

/**
 * @brief Remove the given pointer from the list.
 * @param bl The list
 * @param data The data to remove.
 * @returns The new list.
 */
biglist_t* biglist_remove(biglist_t* bl, const void* data);

/**
 * @brief Remove a specific link from the list.
 * @param bl The list
 * @param blink The link to remove.
 * @returns The new list.
 *
 * @note This operation is constant time.
 * @note The link is just pruned from the list -- it is not freed.
 * You can call biglist_free() on it if you are done with it.
 */
biglist_t* biglist_remove_link(biglist_t* bl, biglist_t* blink);

/**
 * @brief Remove and free a specific link from the list.
 * @param bl The list
 * @param blink The link to remove and free.
 * @returns The new list.
 * @note The client data pointer is NOT freed.
 */
biglist_t* biglist_remove_link_free(biglist_t* bl, biglist_t* blink);

/**
 * @brief Find an element.
 * @param bl The list
 * @param cmp The function which discovers the desired element.
 * @param cookie Cookie passed to your compare function.
 * @returns The element if found.
 * @returns NULL if the element was not found.
 */
biglist_t* biglist_find_custom(biglist_t* bl, biglist_compare_f cmp, void* cookie);

/**
 * @brief Find an element.
 * @param bl The list
 * @param data The data element to find.
 * @returns The link containing the data if found.
 * @returns NULL if the data is not found in the list.
 */
biglist_t* biglist_find(biglist_t* bl, void* data);

/**
 * @brief Get the number of elements.
 * @param bl The list
 * @returns The number of elements in the list.
 */
int biglist_length(biglist_t* bl);

/**
 * @brief Convert a list to an array of pointers in the same order.
 * @param bl The list
 * @param [out] size Receives the element count.
 * @returns An array of biglist_t pointers.
 *
 * @note You should free the resulting array, but NOT the elements.
 * @note The previous/next pointers are unmodified.
 */
biglist_t** biglist_to_array(biglist_t* bl, int* size);

/**
 * @brief Convert a list to an array of data pointers in the same order.
 * @param bl The list
 * @param [out] size Receives the element count.
 * @returns An array of void* client pointers.
 *
 * @note You should free the resulting array, but NOT the elements.
 */
void** biglist_to_data_array(biglist_t* bl, int* size);

/**
 * @brief Convert an array of biglist elements to a list in the same order.
 * @param bl The array of elements.
 * @param size The count.
 * @note The returned list is composed of the elements pointed to by
 * the given array instead of being newly allocated.
 */
biglist_t* biglist_from_array(biglist_t** bl, int size);

/**
 * @brief Convert an array of data pointers to a list in the same order.
 * @param data The array of data elements.
 * @param size The number of elements.
 * @returns A list containing the given data.
 */
biglist_t* biglist_from_data_array(void** data, int size);

/**
 * @brief Free a list.
 * @param bl The list
 * @returns The number of elements freed.
 * @note The data elements are NOT freed.
 */
int biglist_free(biglist_t* bl);

/**
 * Client element free function.
 */
typedef void (*biglist_free_f)(void* data);

/**
 * @brief Free a list and all client data.
 * @param bl The list.
 * @param free_function The function used for freeing client pointers.
 * @returns The number of elements freed.
 */
int biglist_free_all(biglist_t* bl, biglist_free_f free_function);

/**
 * @brief Dump the contents of a list.
 * @param bl The list
 * @param dump_element The data element dumper function.
 * @returns The current list.
 *
 * @note If 'dump_element' is NULL, only the list structure will be dumped.
 * @note If 'dump_element' is specified, the list data will be handed to the
 * given function during the dump for data-specific dumping.
 */
biglist_t* biglist_dump(biglist_t* bl, void (*dump_element)(biglist_t* el));


/**
 * Cast your data pointer.
 */
#define BIGLIST_CAST(_your_type, _biglist_element)                      \
    AIM_PCAST_SAFE(_your_type, _biglist_element, (_biglist_element)->data)

/**
 * Retrieve and cast your data pointer.
 */
#define BIGLIST_GET_DATA(_your_type, _your_pointer, _biglist_element)   \
    _your_type _your_pointer = AIM_PCAST_SAFE(_your_type, _biglist_element, _biglist_element->data)

/**
 * Iterate over all elements in the list.
 */
#define BIGLIST_FOREACH(_biglist_element, _biglist)    \
    for(_biglist_element = _biglist; _biglist_element; \
        _biglist_element = _biglist_element->next)

/**
 * Iterate over all data elements in the list.
 */
#define BIGLIST_FOREACH_DATA(_biglist_element, _biglist, _type, _data)  \
    for(_biglist_element = _biglist,                                    \
            _data = AIM_PCAST_SAFE(_type, _biglist_element, _biglist_element->data); \
        _biglist_element;                                               \
        _biglist_element = _biglist_element->next,                      \
            _data = AIM_PCAST_SAFE(_type, _biglist_element, _biglist_element->data))


#endif /* __BIGLIST_H__ */
/* @} */


