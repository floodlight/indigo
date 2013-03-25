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
 *  /module/src/loci_config.c
 *
 *  loci Config Information
 *
 *****************************************************************************/
#include <loci/loci_config.h>
#include <loci/loci.h>
#include "loci_int.h"
#include <stdlib.h>
#include <string.h>



/* <auto.start.cdefs(LOCI_CONFIG_HEADER).source> */
#define __loci_config_STRINGIFY_NAME(_x) #_x
#define __loci_config_STRINGIFY_VALUE(_x) __loci_config_STRINGIFY_NAME(_x)
loci_config_settings_t loci_config_settings[] =
{
#ifdef LOCI_CONFIG_INCLUDE_LOGGING
    { __loci_config_STRINGIFY_NAME(LOCI_CONFIG_INCLUDE_LOGGING), __loci_config_STRINGIFY_VALUE(LOCI_CONFIG_INCLUDE_LOGGING) },
#else
{ LOCI_CONFIG_INCLUDE_LOGGING(__loci_config_STRINGIFY_NAME), "__undefined__" },
#endif
#ifdef LOCI_CONFIG_LOG_OPTIONS_DEFAULT
    { __loci_config_STRINGIFY_NAME(LOCI_CONFIG_LOG_OPTIONS_DEFAULT), __loci_config_STRINGIFY_VALUE(LOCI_CONFIG_LOG_OPTIONS_DEFAULT) },
#else
{ LOCI_CONFIG_LOG_OPTIONS_DEFAULT(__loci_config_STRINGIFY_NAME), "__undefined__" },
#endif
#ifdef LOCI_CONFIG_LOG_BITS_DEFAULT
    { __loci_config_STRINGIFY_NAME(LOCI_CONFIG_LOG_BITS_DEFAULT), __loci_config_STRINGIFY_VALUE(LOCI_CONFIG_LOG_BITS_DEFAULT) },
#else
{ LOCI_CONFIG_LOG_BITS_DEFAULT(__loci_config_STRINGIFY_NAME), "__undefined__" },
#endif
#ifdef LOCI_CONFIG_LOG_CUSTOM_BITS_DEFAULT
    { __loci_config_STRINGIFY_NAME(LOCI_CONFIG_LOG_CUSTOM_BITS_DEFAULT), __loci_config_STRINGIFY_VALUE(LOCI_CONFIG_LOG_CUSTOM_BITS_DEFAULT) },
#else
{ LOCI_CONFIG_LOG_CUSTOM_BITS_DEFAULT(__loci_config_STRINGIFY_NAME), "__undefined__" },
#endif
#ifdef LOCI_CONFIG_PORTING_STDLIB
    { __loci_config_STRINGIFY_NAME(LOCI_CONFIG_PORTING_STDLIB), __loci_config_STRINGIFY_VALUE(LOCI_CONFIG_PORTING_STDLIB) },
#else
{ LOCI_CONFIG_PORTING_STDLIB(__loci_config_STRINGIFY_NAME), "__undefined__" },
#endif
#ifdef LOCI_CONFIG_PORTING_INCLUDE_STDLIB_HEADERS
    { __loci_config_STRINGIFY_NAME(LOCI_CONFIG_PORTING_INCLUDE_STDLIB_HEADERS), __loci_config_STRINGIFY_VALUE(LOCI_CONFIG_PORTING_INCLUDE_STDLIB_HEADERS) },
#else
{ LOCI_CONFIG_PORTING_INCLUDE_STDLIB_HEADERS(__loci_config_STRINGIFY_NAME), "__undefined__" },
#endif
#ifdef LOCI_CONFIG_INCLUDE_UCLI
    { __loci_config_STRINGIFY_NAME(LOCI_CONFIG_INCLUDE_UCLI), __loci_config_STRINGIFY_VALUE(LOCI_CONFIG_INCLUDE_UCLI) },
#else
{ LOCI_CONFIG_INCLUDE_UCLI(__loci_config_STRINGIFY_NAME), "__undefined__" },
#endif
    { NULL, NULL }
};
#undef __loci_config_STRINGIFY_VALUE
#undef __loci_config_STRINGIFY_NAME

const char*
loci_config_lookup(const char* setting)
{
    int i;
    for(i = 0; loci_config_settings[i].name; i++) {
        if(strcmp(loci_config_settings[i].name, setting)) {
            return loci_config_settings[i].value;
        }
    }
    return NULL;
}

int
loci_config_show(struct aim_pvs_s* pvs)
{
    int i;
    for(i = 0; loci_config_settings[i].name; i++) {
        aim_printf(pvs, "%s = %s\n", loci_config_settings[i].name, loci_config_settings[i].value);
    }
    return i;
}

/* <auto.end.cdefs(LOCI_CONFIG_HEADER).source> */

/**
 * Necessary for module initialization infrastructure.
 * This should register with AIM.
 */
void
__loci_module_init__(void)
{
}

