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
 *  /module/inc/BigList/biglist_config.h
 *
 * @file
 * @brief Biglist Configuration Definitions.
 *
 * @addtogroup biglist-config
 * @{
 *
 *****************************************************************************/
#ifndef __BIGLIST_CONFIG_H__
#define __BIGLIST_CONFIG_H__


#ifdef GLOBAL_INCLUDE_CUSTOM_CONFIG
#include <global_custom_config.h>
#endif
#ifdef BIGLIST_INCLUDE_CUSTOM_CONFIG
#include <biglist_custom_config.h>
#endif




/* <auto.start.cdefs(BIGLIST_CONFIG_HEADER).header> */
#include <AIM/aim.h>
/**
 * BIGLIST_CONFIG_INCLUDE_LOGGING
 *
 * Include or exclude logging. */


#ifndef BIGLIST_CONFIG_INCLUDE_LOGGING
#define BIGLIST_CONFIG_INCLUDE_LOGGING 1
#endif

/**
 * BIGLIST_CONFIG_LOG_OPTIONS_DEFAULT
 *
 * Default enabled log options. */


#ifndef BIGLIST_CONFIG_LOG_OPTIONS_DEFAULT
#define BIGLIST_CONFIG_LOG_OPTIONS_DEFAULT AIM_LOG_OPTIONS_DEFAULT
#endif

/**
 * BIGLIST_CONFIG_LOG_BITS_DEFAULT
 *
 * Default enabled log options. */


#ifndef BIGLIST_CONFIG_LOG_BITS_DEFAULT
#define BIGLIST_CONFIG_LOG_BITS_DEFAULT AIM_LOG_BITS_DEFAULT
#endif

/**
 * BIGLIST_CONFIG_LOG_CUSTOM_BITS_DEFAULT
 *
 * Default enabled custom log options. */


#ifndef BIGLIST_CONFIG_LOG_CUSTOM_BITS_DEFAULT
#define BIGLIST_CONFIG_LOG_CUSTOM_BITS_DEFAULT 0
#endif

/**
 * BIGLIST_CONFIG_PORTING_STDLIB
 *
 * Default all porting macros to use the C standard libraries. */


#ifndef BIGLIST_CONFIG_PORTING_STDLIB
#define BIGLIST_CONFIG_PORTING_STDLIB 1
#endif

/**
 * BIGLIST_CONFIG_PORTING_INCLUDE_STDLIB_HEADERS
 *
 * Include standard library headers for stdlib porting macros. */


#ifndef BIGLIST_CONFIG_PORTING_INCLUDE_STDLIB_HEADERS
#define BIGLIST_CONFIG_PORTING_INCLUDE_STDLIB_HEADERS BIGLIST_CONFIG_PORTING_STDLIB
#endif

/**
 * BIGLIST_CONFIG_INCLUDE_LOCKED
 *
 * Include semaphore-locked list support. */


#ifndef BIGLIST_CONFIG_INCLUDE_LOCKED
#define BIGLIST_CONFIG_INCLUDE_LOCKED 1
#endif



/**
 * All compile time options can be queried or displayed
 */

/** Configuration settings structure. */
typedef struct biglist_config_settings_s {
    /** name */
    const char* name;
    /** value */
    const char* value;
} biglist_config_settings_t;

/** Configuration settings table. */
extern biglist_config_settings_t biglist_config_settings[];

/**
 * @brief Lookup a configuration setting.
 * @param setting The name of the configuration option to lookup.
 */
const char* biglist_config_lookup(const char* setting);

/**
 * @brief Show the compile-time configuration.
 * @param pvs The output stream.
 */
int biglist_config_show(struct aim_pvs_s* pvs);

/* <auto.end.cdefs(BIGLIST_CONFIG_HEADER).header> */


/**
 * @brief Module init function.
 */
void __biglist_module_init__(void);

#include "biglist_porting.h"

#endif /* __BIGLIST_CONFIG_H__ */
/* @} */
