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
 *  /module/src/biglist_config.c
 *
 *  BigList Config Information
 *
 *****************************************************************************/
#include <BigList/biglist_config.h>
#include <BigList/biglist.h>
#include "biglist_int.h"
#include <stdlib.h>
#include <string.h>



/* <auto.start.cdefs(BIGLIST_CONFIG_HEADER).source> */
#define __biglist_config_STRINGIFY_NAME(_x) #_x
#define __biglist_config_STRINGIFY_VALUE(_x) __biglist_config_STRINGIFY_NAME(_x)
biglist_config_settings_t biglist_config_settings[] =
{
#ifdef BIGLIST_CONFIG_INCLUDE_LOGGING
    { __biglist_config_STRINGIFY_NAME(BIGLIST_CONFIG_INCLUDE_LOGGING), __biglist_config_STRINGIFY_VALUE(BIGLIST_CONFIG_INCLUDE_LOGGING) },
#else
{ BIGLIST_CONFIG_INCLUDE_LOGGING(__biglist_config_STRINGIFY_NAME), "__undefined__" },
#endif
#ifdef BIGLIST_CONFIG_LOG_OPTIONS_DEFAULT
    { __biglist_config_STRINGIFY_NAME(BIGLIST_CONFIG_LOG_OPTIONS_DEFAULT), __biglist_config_STRINGIFY_VALUE(BIGLIST_CONFIG_LOG_OPTIONS_DEFAULT) },
#else
{ BIGLIST_CONFIG_LOG_OPTIONS_DEFAULT(__biglist_config_STRINGIFY_NAME), "__undefined__" },
#endif
#ifdef BIGLIST_CONFIG_LOG_BITS_DEFAULT
    { __biglist_config_STRINGIFY_NAME(BIGLIST_CONFIG_LOG_BITS_DEFAULT), __biglist_config_STRINGIFY_VALUE(BIGLIST_CONFIG_LOG_BITS_DEFAULT) },
#else
{ BIGLIST_CONFIG_LOG_BITS_DEFAULT(__biglist_config_STRINGIFY_NAME), "__undefined__" },
#endif
#ifdef BIGLIST_CONFIG_LOG_CUSTOM_BITS_DEFAULT
    { __biglist_config_STRINGIFY_NAME(BIGLIST_CONFIG_LOG_CUSTOM_BITS_DEFAULT), __biglist_config_STRINGIFY_VALUE(BIGLIST_CONFIG_LOG_CUSTOM_BITS_DEFAULT) },
#else
{ BIGLIST_CONFIG_LOG_CUSTOM_BITS_DEFAULT(__biglist_config_STRINGIFY_NAME), "__undefined__" },
#endif
#ifdef BIGLIST_CONFIG_PORTING_STDLIB
    { __biglist_config_STRINGIFY_NAME(BIGLIST_CONFIG_PORTING_STDLIB), __biglist_config_STRINGIFY_VALUE(BIGLIST_CONFIG_PORTING_STDLIB) },
#else
{ BIGLIST_CONFIG_PORTING_STDLIB(__biglist_config_STRINGIFY_NAME), "__undefined__" },
#endif
#ifdef BIGLIST_CONFIG_PORTING_INCLUDE_STDLIB_HEADERS
    { __biglist_config_STRINGIFY_NAME(BIGLIST_CONFIG_PORTING_INCLUDE_STDLIB_HEADERS), __biglist_config_STRINGIFY_VALUE(BIGLIST_CONFIG_PORTING_INCLUDE_STDLIB_HEADERS) },
#else
{ BIGLIST_CONFIG_PORTING_INCLUDE_STDLIB_HEADERS(__biglist_config_STRINGIFY_NAME), "__undefined__" },
#endif
#ifdef BIGLIST_CONFIG_INCLUDE_LOCKED
    { __biglist_config_STRINGIFY_NAME(BIGLIST_CONFIG_INCLUDE_LOCKED), __biglist_config_STRINGIFY_VALUE(BIGLIST_CONFIG_INCLUDE_LOCKED) },
#else
{ BIGLIST_CONFIG_INCLUDE_LOCKED(__biglist_config_STRINGIFY_NAME), "__undefined__" },
#endif
    { NULL, NULL }
};
#undef __biglist_config_STRINGIFY_VALUE
#undef __biglist_config_STRINGIFY_NAME

const char*
biglist_config_lookup(const char* setting)
{
    int i;
    for(i = 0; biglist_config_settings[i].name; i++) {
        if(strcmp(biglist_config_settings[i].name, setting)) {
            return biglist_config_settings[i].value;
        }
    }
    return NULL;
}

int
biglist_config_show(struct aim_pvs_s* pvs)
{
    int i;
    for(i = 0; biglist_config_settings[i].name; i++) {
        aim_printf(pvs, "%s = %s\n", biglist_config_settings[i].name, biglist_config_settings[i].value);
    }
    return i;
}

/* <auto.end.cdefs(BIGLIST_CONFIG_HEADER).source> */



