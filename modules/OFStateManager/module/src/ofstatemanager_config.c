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
 *  /module/src/ofstatemanager_config.c
 *
 *  OFStateManager Config Information
 *
 *****************************************************************************/


#include <OFStateManager/ofstatemanager_config.h>
#include <OFStateManager/ofstatemanager.h>
#include "ofstatemanager_int.h"
#include <stdlib.h>



/* <auto.start.cdefs(OFSTATEMANAGER_CONFIG_HEADER).source> */
#define __ofstatemanager_config_STRINGIFY_NAME(_x) #_x
#define __ofstatemanager_config_STRINGIFY_VALUE(_x) __ofstatemanager_config_STRINGIFY_NAME(_x)
ofstatemanager_config_settings_t ofstatemanager_config_settings[] =
{
#ifdef OFSTATEMANAGER_CONFIG_INCLUDE_LOGGING
    { __ofstatemanager_config_STRINGIFY_NAME(OFSTATEMANAGER_CONFIG_INCLUDE_LOGGING), __ofstatemanager_config_STRINGIFY_VALUE(OFSTATEMANAGER_CONFIG_INCLUDE_LOGGING) },
#else
{ OFSTATEMANAGER_CONFIG_INCLUDE_LOGGING(__ofstatemanager_config_STRINGIFY_NAME), "__undefined__" },
#endif
#ifdef OFSTATEMANAGER_CONFIG_LOG_OPTIONS_DEFAULT
    { __ofstatemanager_config_STRINGIFY_NAME(OFSTATEMANAGER_CONFIG_LOG_OPTIONS_DEFAULT), __ofstatemanager_config_STRINGIFY_VALUE(OFSTATEMANAGER_CONFIG_LOG_OPTIONS_DEFAULT) },
#else
{ OFSTATEMANAGER_CONFIG_LOG_OPTIONS_DEFAULT(__ofstatemanager_config_STRINGIFY_NAME), "__undefined__" },
#endif
#ifdef OFSTATEMANAGER_CONFIG_LOG_BITS_DEFAULT
    { __ofstatemanager_config_STRINGIFY_NAME(OFSTATEMANAGER_CONFIG_LOG_BITS_DEFAULT), __ofstatemanager_config_STRINGIFY_VALUE(OFSTATEMANAGER_CONFIG_LOG_BITS_DEFAULT) },
#else
{ OFSTATEMANAGER_CONFIG_LOG_BITS_DEFAULT(__ofstatemanager_config_STRINGIFY_NAME), "__undefined__" },
#endif
#ifdef OFSTATEMANAGER_CONFIG_LOG_CUSTOM_BITS_DEFAULT
    { __ofstatemanager_config_STRINGIFY_NAME(OFSTATEMANAGER_CONFIG_LOG_CUSTOM_BITS_DEFAULT), __ofstatemanager_config_STRINGIFY_VALUE(OFSTATEMANAGER_CONFIG_LOG_CUSTOM_BITS_DEFAULT) },
#else
{ OFSTATEMANAGER_CONFIG_LOG_CUSTOM_BITS_DEFAULT(__ofstatemanager_config_STRINGIFY_NAME), "__undefined__" },
#endif
#ifdef OFSTATEMANAGER_CONFIG_PORTING_STDLIB
    { __ofstatemanager_config_STRINGIFY_NAME(OFSTATEMANAGER_CONFIG_PORTING_STDLIB), __ofstatemanager_config_STRINGIFY_VALUE(OFSTATEMANAGER_CONFIG_PORTING_STDLIB) },
#else
{ OFSTATEMANAGER_CONFIG_PORTING_STDLIB(__ofstatemanager_config_STRINGIFY_NAME), "__undefined__" },
#endif
#ifdef OFSTATEMANAGER_CONFIG_PORTING_INCLUDE_STDLIB_HEADERS
    { __ofstatemanager_config_STRINGIFY_NAME(OFSTATEMANAGER_CONFIG_PORTING_INCLUDE_STDLIB_HEADERS), __ofstatemanager_config_STRINGIFY_VALUE(OFSTATEMANAGER_CONFIG_PORTING_INCLUDE_STDLIB_HEADERS) },
#else
{ OFSTATEMANAGER_CONFIG_PORTING_INCLUDE_STDLIB_HEADERS(__ofstatemanager_config_STRINGIFY_NAME), "__undefined__" },
#endif
#ifdef OFSTATEMANAGER_CONFIG_INCLUDE_UCLI
    { __ofstatemanager_config_STRINGIFY_NAME(OFSTATEMANAGER_CONFIG_INCLUDE_UCLI), __ofstatemanager_config_STRINGIFY_VALUE(OFSTATEMANAGER_CONFIG_INCLUDE_UCLI) },
#else
{ OFSTATEMANAGER_CONFIG_INCLUDE_UCLI(__ofstatemanager_config_STRINGIFY_NAME), "__undefined__" },
#endif
#ifdef OFSTATEMANAGER_CONFIG_DPID_DEFAULT
    { __ofstatemanager_config_STRINGIFY_NAME(OFSTATEMANAGER_CONFIG_DPID_DEFAULT), __ofstatemanager_config_STRINGIFY_VALUE(OFSTATEMANAGER_CONFIG_DPID_DEFAULT) },
#else
{ OFSTATEMANAGER_CONFIG_DPID_DEFAULT(__ofstatemanager_config_STRINGIFY_NAME), "__undefined__" },
#endif
    { NULL, NULL }
};
#undef __ofstatemanager_config_STRINGIFY_VALUE
#undef __ofstatemanager_config_STRINGIFY_NAME

const char*
ofstatemanager_config_lookup(const char* setting)
{
    int i;
    for(i = 0; ofstatemanager_config_settings[i].name; i++) {
        if(strcmp(ofstatemanager_config_settings[i].name, setting)) {
            return ofstatemanager_config_settings[i].value;
        }
    }
    return NULL;
}

int
ofstatemanager_config_show(struct aim_pvs_s* pvs)
{
    int i;
    for(i = 0; ofstatemanager_config_settings[i].name; i++) {
        aim_printf(pvs, "%s = %s\n", ofstatemanager_config_settings[i].name, ofstatemanager_config_settings[i].value);
    }
    return i;
}

/* <auto.end.cdefs(OFSTATEMANAGER_CONFIG_HEADER).source> */



