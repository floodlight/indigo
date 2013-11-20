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
 *  /module/src/configuration_config.c
 *
 *  Configuration Config Information
 *
 *****************************************************************************/


#include "Configuration/configuration_config.h"
#include "Configuration/configuration.h"
#include "configuration_int.h"
#include <stdlib.h>



/* <auto.start.cdefs(CONFIGURATION_CONFIG_HEADER).source> */
#define __configuration_config_STRINGIFY_NAME(_x) #_x
#define __configuration_config_STRINGIFY_VALUE(_x) __configuration_config_STRINGIFY_NAME(_x)
configuration_config_settings_t configuration_config_settings[] =
{
#ifdef CONFIGURATION_CONFIG_INCLUDE_LOGGING
    { __configuration_config_STRINGIFY_NAME(CONFIGURATION_CONFIG_INCLUDE_LOGGING), __configuration_config_STRINGIFY_VALUE(CONFIGURATION_CONFIG_INCLUDE_LOGGING) },
#else
{ CONFIGURATION_CONFIG_INCLUDE_LOGGING(__configuration_config_STRINGIFY_NAME), "__undefined__" },
#endif
#ifdef CONFIGURATION_CONFIG_LOG_OPTIONS_DEFAULT
    { __configuration_config_STRINGIFY_NAME(CONFIGURATION_CONFIG_LOG_OPTIONS_DEFAULT), __configuration_config_STRINGIFY_VALUE(CONFIGURATION_CONFIG_LOG_OPTIONS_DEFAULT) },
#else
{ CONFIGURATION_CONFIG_LOG_OPTIONS_DEFAULT(__configuration_config_STRINGIFY_NAME), "__undefined__" },
#endif
#ifdef CONFIGURATION_CONFIG_LOG_BITS_DEFAULT
    { __configuration_config_STRINGIFY_NAME(CONFIGURATION_CONFIG_LOG_BITS_DEFAULT), __configuration_config_STRINGIFY_VALUE(CONFIGURATION_CONFIG_LOG_BITS_DEFAULT) },
#else
{ CONFIGURATION_CONFIG_LOG_BITS_DEFAULT(__configuration_config_STRINGIFY_NAME), "__undefined__" },
#endif
#ifdef CONFIGURATION_CONFIG_LOG_CUSTOM_BITS_DEFAULT
    { __configuration_config_STRINGIFY_NAME(CONFIGURATION_CONFIG_LOG_CUSTOM_BITS_DEFAULT), __configuration_config_STRINGIFY_VALUE(CONFIGURATION_CONFIG_LOG_CUSTOM_BITS_DEFAULT) },
#else
{ CONFIGURATION_CONFIG_LOG_CUSTOM_BITS_DEFAULT(__configuration_config_STRINGIFY_NAME), "__undefined__" },
#endif
#ifdef CONFIGURATION_CONFIG_PORTING_STDLIB
    { __configuration_config_STRINGIFY_NAME(CONFIGURATION_CONFIG_PORTING_STDLIB), __configuration_config_STRINGIFY_VALUE(CONFIGURATION_CONFIG_PORTING_STDLIB) },
#else
{ CONFIGURATION_CONFIG_PORTING_STDLIB(__configuration_config_STRINGIFY_NAME), "__undefined__" },
#endif
#ifdef CONFIGURATION_CONFIG_PORTING_INCLUDE_STDLIB_HEADERS
    { __configuration_config_STRINGIFY_NAME(CONFIGURATION_CONFIG_PORTING_INCLUDE_STDLIB_HEADERS), __configuration_config_STRINGIFY_VALUE(CONFIGURATION_CONFIG_PORTING_INCLUDE_STDLIB_HEADERS) },
#else
{ CONFIGURATION_CONFIG_PORTING_INCLUDE_STDLIB_HEADERS(__configuration_config_STRINGIFY_NAME), "__undefined__" },
#endif
#ifdef CONFIGURATION_CONFIG_INCLUDE_UCLI
    { __configuration_config_STRINGIFY_NAME(CONFIGURATION_CONFIG_INCLUDE_UCLI), __configuration_config_STRINGIFY_VALUE(CONFIGURATION_CONFIG_INCLUDE_UCLI) },
#else
{ CONFIGURATION_CONFIG_INCLUDE_UCLI(__configuration_config_STRINGIFY_NAME), "__undefined__" },
#endif
    { NULL, NULL }
};
#undef __configuration_config_STRINGIFY_VALUE
#undef __configuration_config_STRINGIFY_NAME

const char*
configuration_config_lookup(const char* setting)
{
    int i;
    for(i = 0; configuration_config_settings[i].name; i++) {
        if(strcmp(configuration_config_settings[i].name, setting)) {
            return configuration_config_settings[i].value;
        }
    }
    return NULL;
}

int
configuration_config_show(struct aim_pvs_s* pvs)
{
    int i;
    for(i = 0; configuration_config_settings[i].name; i++) {
        aim_printf(pvs, "%s = %s\n", configuration_config_settings[i].name, configuration_config_settings[i].value);
    }
    return i;
}

/* <auto.end.cdefs(CONFIGURATION_CONFIG_HEADER).source> */



