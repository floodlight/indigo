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
 *  /module/inc/socketmanager_config.h
 *
 *  SocketManager Config Header
 *
 *****************************************************************************/
#ifndef __SOCKETMANAGER_CONFIG_H__
#define __SOCKETMANAGER_CONFIG_H__

#ifdef GLOBAL_INCLUDE_CUSTOM_CONFIG
#include <global_custom_config.h>
#endif

#ifdef SOCKETMANAGER_INCLUDE_CUSTOM_CONFIG
#include <socketmanager_custom_config.h>
#endif


/* <auto.start.cdefs(SOCKETMANAGER_CONFIG_HEADER).header> */
#include <AIM/aim.h>
/**
 * SOCKETMANAGER_CONFIG_INCLUDE_LOGGING
 *
 * Include or exclude logging. */


#ifndef SOCKETMANAGER_CONFIG_INCLUDE_LOGGING
#define SOCKETMANAGER_CONFIG_INCLUDE_LOGGING 1
#endif

/**
 * SOCKETMANAGER_CONFIG_LOG_OPTIONS_DEFAULT
 *
 * Default enabled log options. */


#ifndef SOCKETMANAGER_CONFIG_LOG_OPTIONS_DEFAULT
#define SOCKETMANAGER_CONFIG_LOG_OPTIONS_DEFAULT AIM_LOG_OPTIONS_DEFAULT
#endif

/**
 * SOCKETMANAGER_CONFIG_LOG_BITS_DEFAULT
 *
 * Default enabled log bits. */


#ifndef SOCKETMANAGER_CONFIG_LOG_BITS_DEFAULT
#define SOCKETMANAGER_CONFIG_LOG_BITS_DEFAULT AIM_LOG_BITS_DEFAULT
#endif

/**
 * SOCKETMANAGER_CONFIG_LOG_CUSTOM_BITS_DEFAULT
 *
 * Default enabled custom log options. */


#ifndef SOCKETMANAGER_CONFIG_LOG_CUSTOM_BITS_DEFAULT
#define SOCKETMANAGER_CONFIG_LOG_CUSTOM_BITS_DEFAULT 0
#endif

/**
 * SOCKETMANAGER_CONFIG_PORTING_STDLIB
 *
 * Default all porting macros to use the C standard libraries. */


#ifndef SOCKETMANAGER_CONFIG_PORTING_STDLIB
#define SOCKETMANAGER_CONFIG_PORTING_STDLIB 1
#endif

/**
 * SOCKETMANAGER_CONFIG_PORTING_INCLUDE_STDLIB_HEADERS
 *
 * Include standard library headers for stdlib porting macros. */


#ifndef SOCKETMANAGER_CONFIG_PORTING_INCLUDE_STDLIB_HEADERS
#define SOCKETMANAGER_CONFIG_PORTING_INCLUDE_STDLIB_HEADERS SOCKETMANAGER_CONFIG_PORTING_STDLIB
#endif

/**
 * SOCKETMANAGER_CONFIG_INCLUDE_UCLI
 *
 * Include generic uCli support. */


#ifndef SOCKETMANAGER_CONFIG_INCLUDE_UCLI
#define SOCKETMANAGER_CONFIG_INCLUDE_UCLI 0
#endif

/**
 * SOCKETMANAGER_CONFIG_TIMESLICE_MS
 *
 * Milliseconds before ind_soc_should_yield() returns true. */


#ifndef SOCKETMANAGER_CONFIG_TIMESLICE_MS
#define SOCKETMANAGER_CONFIG_TIMESLICE_MS 10
#endif

/**
 * SOCKETMANAGER_CONFIG_MAX_TIMERS
 *
 * Maximum number of timers supported */


#ifndef SOCKETMANAGER_CONFIG_MAX_TIMERS
#define SOCKETMANAGER_CONFIG_MAX_TIMERS 48
#endif



/**
 * All compile time options can be queried or displayed
 */

/** Configuration settings structure. */
typedef struct socketmanager_config_settings_s {
    /** name */
    const char* name;
    /** value */
    const char* value;
} socketmanager_config_settings_t;

/** Configuration settings table. */
/** socketmanager_config_settings table. */
extern socketmanager_config_settings_t socketmanager_config_settings[];

/**
 * @brief Lookup a configuration setting.
 * @param setting The name of the configuration option to lookup.
 */
const char* socketmanager_config_lookup(const char* setting);

/**
 * @brief Show the compile-time configuration.
 * @param pvs The output stream.
 */
int socketmanager_config_show(struct aim_pvs_s* pvs);

/* <auto.end.cdefs(SOCKETMANAGER_CONFIG_HEADER).header> */



#endif /* __SOCKETMANAGER_CONFIG_H__ */
