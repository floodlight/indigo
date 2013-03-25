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
 *  /module/src/ofconnectionmanager_config.c
 *
 *  OFConnectionManager Config Information
 *
 * Most of the contents of this file are automatically generated
 *
 *****************************************************************************/


#include <OFConnectionManager/ofconnectionmanager_config.h>
#include <OFConnectionManager/ofconnectionmanager.h>
#include "ofconnectionmanager_int.h"
#include <stdlib.h>



/* <auto.start.cdefs(OFCONNECTIONMANAGER_CONFIG_HEADER).source> */
#define __ofconnectionmanager_config_STRINGIFY_NAME(_x) #_x
#define __ofconnectionmanager_config_STRINGIFY_VALUE(_x) __ofconnectionmanager_config_STRINGIFY_NAME(_x)
ofconnectionmanager_config_settings_t ofconnectionmanager_config_settings[] =
{
#ifdef OFCONNECTIONMANAGER_CONFIG_INCLUDE_LOGGING
    { __ofconnectionmanager_config_STRINGIFY_NAME(OFCONNECTIONMANAGER_CONFIG_INCLUDE_LOGGING), __ofconnectionmanager_config_STRINGIFY_VALUE(OFCONNECTIONMANAGER_CONFIG_INCLUDE_LOGGING) },
#else
{ OFCONNECTIONMANAGER_CONFIG_INCLUDE_LOGGING(__ofconnectionmanager_config_STRINGIFY_NAME), "__undefined__" },
#endif
#ifdef OFCONNECTIONMANAGER_CONFIG_LOG_OPTIONS_DEFAULT
    { __ofconnectionmanager_config_STRINGIFY_NAME(OFCONNECTIONMANAGER_CONFIG_LOG_OPTIONS_DEFAULT), __ofconnectionmanager_config_STRINGIFY_VALUE(OFCONNECTIONMANAGER_CONFIG_LOG_OPTIONS_DEFAULT) },
#else
{ OFCONNECTIONMANAGER_CONFIG_LOG_OPTIONS_DEFAULT(__ofconnectionmanager_config_STRINGIFY_NAME), "__undefined__" },
#endif
#ifdef OFCONNECTIONMANAGER_CONFIG_LOG_BITS_DEFAULT
    { __ofconnectionmanager_config_STRINGIFY_NAME(OFCONNECTIONMANAGER_CONFIG_LOG_BITS_DEFAULT), __ofconnectionmanager_config_STRINGIFY_VALUE(OFCONNECTIONMANAGER_CONFIG_LOG_BITS_DEFAULT) },
#else
{ OFCONNECTIONMANAGER_CONFIG_LOG_BITS_DEFAULT(__ofconnectionmanager_config_STRINGIFY_NAME), "__undefined__" },
#endif
#ifdef OFCONNECTIONMANAGER_CONFIG_LOG_CUSTOM_BITS_DEFAULT
    { __ofconnectionmanager_config_STRINGIFY_NAME(OFCONNECTIONMANAGER_CONFIG_LOG_CUSTOM_BITS_DEFAULT), __ofconnectionmanager_config_STRINGIFY_VALUE(OFCONNECTIONMANAGER_CONFIG_LOG_CUSTOM_BITS_DEFAULT) },
#else
{ OFCONNECTIONMANAGER_CONFIG_LOG_CUSTOM_BITS_DEFAULT(__ofconnectionmanager_config_STRINGIFY_NAME), "__undefined__" },
#endif
#ifdef OFCONNECTIONMANAGER_CONFIG_PORTING_STDLIB
    { __ofconnectionmanager_config_STRINGIFY_NAME(OFCONNECTIONMANAGER_CONFIG_PORTING_STDLIB), __ofconnectionmanager_config_STRINGIFY_VALUE(OFCONNECTIONMANAGER_CONFIG_PORTING_STDLIB) },
#else
{ OFCONNECTIONMANAGER_CONFIG_PORTING_STDLIB(__ofconnectionmanager_config_STRINGIFY_NAME), "__undefined__" },
#endif
#ifdef OFCONNECTIONMANAGER_CONFIG_PORTING_INCLUDE_STDLIB_HEADERS
    { __ofconnectionmanager_config_STRINGIFY_NAME(OFCONNECTIONMANAGER_CONFIG_PORTING_INCLUDE_STDLIB_HEADERS), __ofconnectionmanager_config_STRINGIFY_VALUE(OFCONNECTIONMANAGER_CONFIG_PORTING_INCLUDE_STDLIB_HEADERS) },
#else
{ OFCONNECTIONMANAGER_CONFIG_PORTING_INCLUDE_STDLIB_HEADERS(__ofconnectionmanager_config_STRINGIFY_NAME), "__undefined__" },
#endif
#ifdef OFCONNECTIONMANAGER_CONFIG_INCLUDE_UCLI
    { __ofconnectionmanager_config_STRINGIFY_NAME(OFCONNECTIONMANAGER_CONFIG_INCLUDE_UCLI), __ofconnectionmanager_config_STRINGIFY_VALUE(OFCONNECTIONMANAGER_CONFIG_INCLUDE_UCLI) },
#else
{ OFCONNECTIONMANAGER_CONFIG_INCLUDE_UCLI(__ofconnectionmanager_config_STRINGIFY_NAME), "__undefined__" },
#endif
    { NULL, NULL }
};
#undef __ofconnectionmanager_config_STRINGIFY_VALUE
#undef __ofconnectionmanager_config_STRINGIFY_NAME

const char*
ofconnectionmanager_config_lookup(const char* setting)
{
    int i;
    for(i = 0; ofconnectionmanager_config_settings[i].name; i++) {
        if(strcmp(ofconnectionmanager_config_settings[i].name, setting)) {
            return ofconnectionmanager_config_settings[i].value;
        }
    }
    return NULL;
}

int
ofconnectionmanager_config_show(struct aim_pvs_s* pvs)
{
    int i;
    for(i = 0; ofconnectionmanager_config_settings[i].name; i++) {
        aim_printf(pvs, "%s = %s\n", ofconnectionmanager_config_settings[i].name, ofconnectionmanager_config_settings[i].value);
    }
    return i;
}

/* <auto.end.cdefs(OFCONNECTIONMANAGER_CONFIG_HEADER).source> */



