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
 * module/inc/biglist_locked.h
 *
 * @file
 * @brief Locked List Interface
 *
 * @addtogroup biglist-locked
 * @{
 *
 *****************************************************************************/
#ifndef __BIGLIST_LOCKED_H__
#define __BIGLIST_LOCKED_H__

#include <BigList/biglist_config.h>

#if BIGLIST_CONFIG_INCLUDE_LOCKED == 1
#include <semaphore.h>
#endif

/**
 * Locked struct head.
 */
typedef struct biglist_locked_s {
    /** The list */
    biglist_t* list;
#if BIGLIST_CONFIG_INCLUDE_LOCKED == 1
    /** The locking semaphore */
    sem_t lock;
#endif
} biglist_locked_t;

/**
 * @brief Create a locked list object.
 * @returns The locked list object.
 */
biglist_locked_t* biglist_locked_create(void);

/**
 * @brief Lock a list.
 * @param bl The list object.
 */
int biglist_lock(biglist_locked_t* bl);

/**
 * @brief Unlock a list.
 * @param bl The list object.
 */
int biglist_unlock(biglist_locked_t* bl);

/**
 * @brief Prepend to the list.
 * @param bl The list object.
 * @param data The data to prepend.
 */
int biglist_locked_prepend(biglist_locked_t* bl, void* data);

/**
 * @brief Append to the list.
 * @param bl The list object.
 * @param data The data to append.
 */
int biglist_locked_append(biglist_locked_t* bl, void* data);

/**
 * @brief Remove an element from the list.
 * @param bl The list object.
 * @param data The data to remove.
 */
int biglist_locked_remove(biglist_locked_t* bl, const void* data);

/**
 * @brief Remove a link from the list.
 * @param bl The list object.
 * @param blink The list link to remove.
 */
int biglist_locked_remove_link(biglist_locked_t* bl, biglist_t* blink);

/**
 * @brief Remove and free a link from the list.
 * @param bl The list object.
 * @param blink The list link to remove.
 *
 * @note The link element is removed the list and it's memory is deallocated.
 * @note The client data pointer contained in the link is NOT freed.
 */
int biglist_locked_remove_link_free(biglist_locked_t* bl, biglist_t* blink);

/**
 * @brief Find the given data.
 * @param bl The list object.
 * @param data The data to find.
 * @returns NULL if the data is not in the list.
 * @returns The data element's link if found.
 */
biglist_t* biglist_locked_find(biglist_locked_t* bl, void* data);

/**
 * @brief Get the number of elements in the list.
 * @param bl The list object.
 * @returns The number of elements in the list.
 */
int biglist_locked_length(biglist_locked_t* bl);

/**
 * @brief Free an entire list.
 * @param bl The list to free.
 * @note The client data is NOT freed, only the list elements.
 */
int biglist_locked_free(biglist_locked_t* bl);

/**
 * @brief Free an entire list, including client data.
 * @param bl The list object.
 * @param free_function The function to free each client data pointer.
 */
int biglist_locked_free_all(biglist_locked_t* bl, biglist_free_f free_function);

#endif /* __BIGLIST_LOCKED_H__ */

/* @} */
