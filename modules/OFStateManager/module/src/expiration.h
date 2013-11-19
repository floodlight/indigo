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

/**
 * @file
 * @brief Flow expiration interfaces
 *
 * These functions implement efficient timeouts for large numbers of
 * flowtable entries.
 */

#ifndef _OFSTATEMANAGER_EXPIRATION_H_
#define _OFSTATEMANAGER_EXPIRATION_H_

#include <indigo/indigo.h>

#include "ft_entry.h"

/**
 * Add a flow entry to the expiration datastructure
 * @param entry Pointer to the entry to be added
 */
void ind_core_expiration_add(ft_entry_t *entry);

/**
 * Remove a flow entry from the expiration datastructure
 * @param entry Pointer to the entry to be removed
 */
void ind_core_expiration_remove(ft_entry_t *entry);

/**
 * Expire flows that have exceeded their timeout
 *
 * Should be called periodically.
 */
void ind_core_expiration_timer(void *cookie);

#endif /* _OFSTATEMANAGER_EXPIRATION_H_ */
