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

#ifndef _INDIGO_MODULE_H_
#define _INDIGO_MODULE_H_

#include <indigo/error.h>

#include <indigo/of_state_manager.h>
#include <indigo/of_connection_manager.h>
#include <indigo/forwarding.h>
#include <indigo/port_manager.h>

/**
 * @file
 * @brief Documentation file for Indigo architecture modules
 * @addtogroup indigo-module
 *
 * This file has no definitions in it and is intended to document
 * conventions for Indigo module implementations.
 *
 * The normal sequence of operations for modules is:
 * @li init: Allow internal data structures to be allocated and initialized;
 * pass configuration data to the module.
 * @li enable (set enable to true): Indicate that the module should be
 * come active and respond to calls.
 * @li disable (set enable to false): Module should not respond to calls
 * @li finish: Deallocate any resources used by the module
 *
 * Conventions:
 * @li Do not respond to calls until enable is set to true
 *
 * @{
 */

/**
 * Configure a module with drivers from other functions
 *
 * @param example_module_config Implementation specific module configuration
 * @returns An error code
 *
 * A module implementation is recommended to implement a function
 * which takes pointers to the driver functions of other modules as well
 * as any implementation specific configuration data.
 *
 * This is an example prototype.
 */

typedef indigo_error_t (*indigo_example_module_init)(
    void *example_module_config);

/**
 * Enable/disable a module
 *
 * @param enable Boolean indication of whether module should become active
 * @returns An error code
 *
 * This is an example prototype.
 */

typedef indigo_error_t (*indigo_example_module_enable_set)(int enable);
typedef indigo_error_t (*indigo_example_module_enable_get)(int *enable);

/**
 * Disable and deallocate resources used by the module
 *
 * @returns An error code
 *
 * This is an example prototype.
 */

typedef indigo_error_t (*indigo_example_module_finish)(void);

#endif /* _INDIGO_MODULE_H_ */
/* @} */
