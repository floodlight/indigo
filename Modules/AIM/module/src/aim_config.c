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
 *  /module/src/aim_config.c
 *
 *  AIM Config Information
 *
 *****************************************************************************/
#include <AIM/aim_config.h>
#include <AIM/aim.h>
#include "aim_int.h"
#include <stdlib.h>
#include <string.h>



/* <auto.start.cdefs(AIM_CONFIG_HEADER).source> */
#define __aim_config_STRINGIFY_NAME(_x) #_x
#define __aim_config_STRINGIFY_VALUE(_x) __aim_config_STRINGIFY_NAME(_x)
aim_config_settings_t aim_config_settings[] =
{
#ifdef AIM_CONFIG_INCLUDE_LOGGING
    { __aim_config_STRINGIFY_NAME(AIM_CONFIG_INCLUDE_LOGGING), __aim_config_STRINGIFY_VALUE(AIM_CONFIG_INCLUDE_LOGGING) },
#else
{ AIM_CONFIG_INCLUDE_LOGGING(__aim_config_STRINGIFY_NAME), "__undefined__" },
#endif
#ifdef AIM_CONFIG_PORTING_STDLIB
    { __aim_config_STRINGIFY_NAME(AIM_CONFIG_PORTING_STDLIB), __aim_config_STRINGIFY_VALUE(AIM_CONFIG_PORTING_STDLIB) },
#else
{ AIM_CONFIG_PORTING_STDLIB(__aim_config_STRINGIFY_NAME), "__undefined__" },
#endif
#ifdef AIM_CONFIG_PORTING_INCLUDE_STDLIB_HEADERS
    { __aim_config_STRINGIFY_NAME(AIM_CONFIG_PORTING_INCLUDE_STDLIB_HEADERS), __aim_config_STRINGIFY_VALUE(AIM_CONFIG_PORTING_INCLUDE_STDLIB_HEADERS) },
#else
{ AIM_CONFIG_PORTING_INCLUDE_STDLIB_HEADERS(__aim_config_STRINGIFY_NAME), "__undefined__" },
#endif
#ifdef AIM_CONFIG_LOG_MESSAGE_SIZE
    { __aim_config_STRINGIFY_NAME(AIM_CONFIG_LOG_MESSAGE_SIZE), __aim_config_STRINGIFY_VALUE(AIM_CONFIG_LOG_MESSAGE_SIZE) },
#else
{ AIM_CONFIG_LOG_MESSAGE_SIZE(__aim_config_STRINGIFY_NAME), "__undefined__" },
#endif
#ifdef AIM_CONFIG_LOG_INCLUDE_LINUX_TIMESTAMP
    { __aim_config_STRINGIFY_NAME(AIM_CONFIG_LOG_INCLUDE_LINUX_TIMESTAMP), __aim_config_STRINGIFY_VALUE(AIM_CONFIG_LOG_INCLUDE_LINUX_TIMESTAMP) },
#else
{ AIM_CONFIG_LOG_INCLUDE_LINUX_TIMESTAMP(__aim_config_STRINGIFY_NAME), "__undefined__" },
#endif
#ifdef AIM_CONFIG_LOG_INCLUDE_ENV_VARIABLES
    { __aim_config_STRINGIFY_NAME(AIM_CONFIG_LOG_INCLUDE_ENV_VARIABLES), __aim_config_STRINGIFY_VALUE(AIM_CONFIG_LOG_INCLUDE_ENV_VARIABLES) },
#else
{ AIM_CONFIG_LOG_INCLUDE_ENV_VARIABLES(__aim_config_STRINGIFY_NAME), "__undefined__" },
#endif
#ifdef AIM_CONFIG_PVS_INCLUDE_TTY
    { __aim_config_STRINGIFY_NAME(AIM_CONFIG_PVS_INCLUDE_TTY), __aim_config_STRINGIFY_VALUE(AIM_CONFIG_PVS_INCLUDE_TTY) },
#else
{ AIM_CONFIG_PVS_INCLUDE_TTY(__aim_config_STRINGIFY_NAME), "__undefined__" },
#endif
#ifdef AIM_CONFIG_LOG_INCLUDE_TTY_COLOR
    { __aim_config_STRINGIFY_NAME(AIM_CONFIG_LOG_INCLUDE_TTY_COLOR), __aim_config_STRINGIFY_VALUE(AIM_CONFIG_LOG_INCLUDE_TTY_COLOR) },
#else
{ AIM_CONFIG_LOG_INCLUDE_TTY_COLOR(__aim_config_STRINGIFY_NAME), "__undefined__" },
#endif
#ifdef AIM_CONFIG_INCLUDE_MODULES_INIT
    { __aim_config_STRINGIFY_NAME(AIM_CONFIG_INCLUDE_MODULES_INIT), __aim_config_STRINGIFY_VALUE(AIM_CONFIG_INCLUDE_MODULES_INIT) },
#else
{ AIM_CONFIG_INCLUDE_MODULES_INIT(__aim_config_STRINGIFY_NAME), "__undefined__" },
#endif
#ifdef AIM_CONFIG_INCLUDE_MODULES_DENIT
    { __aim_config_STRINGIFY_NAME(AIM_CONFIG_INCLUDE_MODULES_DENIT), __aim_config_STRINGIFY_VALUE(AIM_CONFIG_INCLUDE_MODULES_DENIT) },
#else
{ AIM_CONFIG_INCLUDE_MODULES_DENIT(__aim_config_STRINGIFY_NAME), "__undefined__" },
#endif
#ifdef AIM_CONFIG_INCLUDE_MAIN
    { __aim_config_STRINGIFY_NAME(AIM_CONFIG_INCLUDE_MAIN), __aim_config_STRINGIFY_VALUE(AIM_CONFIG_INCLUDE_MAIN) },
#else
{ AIM_CONFIG_INCLUDE_MAIN(__aim_config_STRINGIFY_NAME), "__undefined__" },
#endif
#ifdef AIM_CONFIG_INCLUDE_ENV_ARGV
    { __aim_config_STRINGIFY_NAME(AIM_CONFIG_INCLUDE_ENV_ARGV), __aim_config_STRINGIFY_VALUE(AIM_CONFIG_INCLUDE_ENV_ARGV) },
#else
{ AIM_CONFIG_INCLUDE_ENV_ARGV(__aim_config_STRINGIFY_NAME), "__undefined__" },
#endif
#ifdef AIM_CONFIG_ENV_ARGV_NAME
    { __aim_config_STRINGIFY_NAME(AIM_CONFIG_ENV_ARGV_NAME), __aim_config_STRINGIFY_VALUE(AIM_CONFIG_ENV_ARGV_NAME) },
#else
{ AIM_CONFIG_ENV_ARGV_NAME(__aim_config_STRINGIFY_NAME), "__undefined__" },
#endif
#ifdef AIM_CONFIG_INCLUDE_VALGRIND
    { __aim_config_STRINGIFY_NAME(AIM_CONFIG_INCLUDE_VALGRIND), __aim_config_STRINGIFY_VALUE(AIM_CONFIG_INCLUDE_VALGRIND) },
#else
{ AIM_CONFIG_INCLUDE_VALGRIND(__aim_config_STRINGIFY_NAME), "__undefined__" },
#endif
#ifdef AIM_CONFIG_INCLUDE_DAEMONIZE
    { __aim_config_STRINGIFY_NAME(AIM_CONFIG_INCLUDE_DAEMONIZE), __aim_config_STRINGIFY_VALUE(AIM_CONFIG_INCLUDE_DAEMONIZE) },
#else
{ AIM_CONFIG_INCLUDE_DAEMONIZE(__aim_config_STRINGIFY_NAME), "__undefined__" },
#endif
#ifdef AIM_CONFIG_INCLUDE_PVS_SYSLOG
    { __aim_config_STRINGIFY_NAME(AIM_CONFIG_INCLUDE_PVS_SYSLOG), __aim_config_STRINGIFY_VALUE(AIM_CONFIG_INCLUDE_PVS_SYSLOG) },
#else
{ AIM_CONFIG_INCLUDE_PVS_SYSLOG(__aim_config_STRINGIFY_NAME), "__undefined__" },
#endif
#ifdef AIM_CONFIG_PVS_SYSLOG_IDENT_DEFAULT
    { __aim_config_STRINGIFY_NAME(AIM_CONFIG_PVS_SYSLOG_IDENT_DEFAULT), __aim_config_STRINGIFY_VALUE(AIM_CONFIG_PVS_SYSLOG_IDENT_DEFAULT) },
#else
{ AIM_CONFIG_PVS_SYSLOG_IDENT_DEFAULT(__aim_config_STRINGIFY_NAME), "__undefined__" },
#endif
#ifdef AIM_CONFIG_PVS_SYSLOG_OPTIONS_DEFAULT
    { __aim_config_STRINGIFY_NAME(AIM_CONFIG_PVS_SYSLOG_OPTIONS_DEFAULT), __aim_config_STRINGIFY_VALUE(AIM_CONFIG_PVS_SYSLOG_OPTIONS_DEFAULT) },
#else
{ AIM_CONFIG_PVS_SYSLOG_OPTIONS_DEFAULT(__aim_config_STRINGIFY_NAME), "__undefined__" },
#endif
#ifdef AIM_CONFIG_PVS_SYSLOG_FACILITY_DEFAULT
    { __aim_config_STRINGIFY_NAME(AIM_CONFIG_PVS_SYSLOG_FACILITY_DEFAULT), __aim_config_STRINGIFY_VALUE(AIM_CONFIG_PVS_SYSLOG_FACILITY_DEFAULT) },
#else
{ AIM_CONFIG_PVS_SYSLOG_FACILITY_DEFAULT(__aim_config_STRINGIFY_NAME), "__undefined__" },
#endif
    { NULL, NULL }
};
#undef __aim_config_STRINGIFY_VALUE
#undef __aim_config_STRINGIFY_NAME

const char*
aim_config_lookup(const char* setting)
{
    int i;
    for(i = 0; aim_config_settings[i].name; i++) {
        if(strcmp(aim_config_settings[i].name, setting)) {
            return aim_config_settings[i].value;
        }
    }
    return NULL;
}

int
aim_config_show(struct aim_pvs_s* pvs)
{
    int i;
    for(i = 0; aim_config_settings[i].name; i++) {
        aim_printf(pvs, "%s = %s\n", aim_config_settings[i].name, aim_config_settings[i].value);
    }
    return i;
}

/* <auto.end.cdefs(AIM_CONFIG_HEADER).source> */



