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
 *  /module/inc/ofstatemanager_config.h
 *
 *  OFStateManager Config Header
 *
 *****************************************************************************/
#ifndef __OFSTATEMANAGER_CONFIG_H__
#define __OFSTATEMANAGER_CONFIG_H__

#ifdef GLOBAL_INCLUDE_CUSTOM_CONFIG
#include <global_custom_config.h>
#endif

#ifdef OFSTATEMANAGER_INCLUDE_CUSTOM_CONFIG
#include <ofstatemanager_custom_config.h>
#endif



/* <auto.start.cdefs(OFSTATEMANAGER_CONFIG_HEADER).header> */
#include <AIM/aim.h>
/**
 * OFSTATEMANAGER_CONFIG_INCLUDE_LOGGING
 *
 * Include or exclude logging. */


#ifndef OFSTATEMANAGER_CONFIG_INCLUDE_LOGGING
#define OFSTATEMANAGER_CONFIG_INCLUDE_LOGGING 1
#endif

/**
 * OFSTATEMANAGER_CONFIG_LOG_OPTIONS_DEFAULT
 *
 * Default enabled log options. */


#ifndef OFSTATEMANAGER_CONFIG_LOG_OPTIONS_DEFAULT
#define OFSTATEMANAGER_CONFIG_LOG_OPTIONS_DEFAULT AIM_LOG_OPTIONS_DEFAULT
#endif

/**
 * OFSTATEMANAGER_CONFIG_LOG_BITS_DEFAULT
 *
 * Default enabled log bits. */


#ifndef OFSTATEMANAGER_CONFIG_LOG_BITS_DEFAULT
#define OFSTATEMANAGER_CONFIG_LOG_BITS_DEFAULT AIM_LOG_BITS_DEFAULT
#endif

/**
 * OFSTATEMANAGER_CONFIG_LOG_CUSTOM_BITS_DEFAULT
 *
 * Default enabled custom log bits. */


#ifndef OFSTATEMANAGER_CONFIG_LOG_CUSTOM_BITS_DEFAULT
#define OFSTATEMANAGER_CONFIG_LOG_CUSTOM_BITS_DEFAULT 0
#endif

/**
 * OFSTATEMANAGER_CONFIG_PORTING_STDLIB
 *
 * Default all porting macros to use the C standard libraries. */


#ifndef OFSTATEMANAGER_CONFIG_PORTING_STDLIB
#define OFSTATEMANAGER_CONFIG_PORTING_STDLIB 1
#endif

/**
 * OFSTATEMANAGER_CONFIG_PORTING_INCLUDE_STDLIB_HEADERS
 *
 * Include standard library headers for stdlib porting macros. */


#ifndef OFSTATEMANAGER_CONFIG_PORTING_INCLUDE_STDLIB_HEADERS
#define OFSTATEMANAGER_CONFIG_PORTING_INCLUDE_STDLIB_HEADERS OFSTATEMANAGER_CONFIG_PORTING_STDLIB
#endif

/**
 * OFSTATEMANAGER_CONFIG_INCLUDE_UCLI
 *
 * Include generic uCli support. */


#ifndef OFSTATEMANAGER_CONFIG_INCLUDE_UCLI
#define OFSTATEMANAGER_CONFIG_INCLUDE_UCLI 0
#endif

/**
 * OFSTATEMANAGER_CONFIG_DPID_DEFAULT
 *
 * Default DPID for OpenFlow datapath */


#ifndef OFSTATEMANAGER_CONFIG_DPID_DEFAULT
#define OFSTATEMANAGER_CONFIG_DPID_DEFAULT 55930
#endif



/**
 * All compile time options can be queried or displayed
 */

/** Configuration settings structure. */
typedef struct ofstatemanager_config_settings_s {
    /** name */
    const char* name;
    /** value */
    const char* value;
} ofstatemanager_config_settings_t;

/** Configuration settings table. */
/** ofstatemanager_config_settings table. */
extern ofstatemanager_config_settings_t ofstatemanager_config_settings[];

/**
 * @brief Lookup a configuration setting.
 * @param setting The name of the configuration option to lookup.
 */
const char* ofstatemanager_config_lookup(const char* setting);

/**
 * @brief Show the compile-time configuration.
 * @param pvs The output stream.
 */
int ofstatemanager_config_show(struct aim_pvs_s* pvs);

/* <auto.end.cdefs(OFSTATEMANAGER_CONFIG_HEADER).header> */



#endif /* __OFSTATEMANAGER_CONFIG_H__ */
