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
 *  /module/src/socketmanager_config.c
 *
 *  SocketManager Config Information
 *
 *****************************************************************************/


#include <SocketManager/socketmanager_config.h>
#include <SocketManager/socketmanager.h>
#include "socketmanager_int.h"
#include "socketmanager_log.h"
#include <stdlib.h>
#include <cjson/cJSON.h>
#include <Configuration/configuration.h>

/* <auto.start.cdefs(SOCKETMANAGER_CONFIG_HEADER).source> */
#define __socketmanager_config_STRINGIFY_NAME(_x) #_x
#define __socketmanager_config_STRINGIFY_VALUE(_x) __socketmanager_config_STRINGIFY_NAME(_x)
socketmanager_config_settings_t socketmanager_config_settings[] =
{
#ifdef SOCKETMANAGER_CONFIG_INCLUDE_LOGGING
    { __socketmanager_config_STRINGIFY_NAME(SOCKETMANAGER_CONFIG_INCLUDE_LOGGING), __socketmanager_config_STRINGIFY_VALUE(SOCKETMANAGER_CONFIG_INCLUDE_LOGGING) },
#else
{ SOCKETMANAGER_CONFIG_INCLUDE_LOGGING(__socketmanager_config_STRINGIFY_NAME), "__undefined__" },
#endif
#ifdef SOCKETMANAGER_CONFIG_LOG_OPTIONS_DEFAULT
    { __socketmanager_config_STRINGIFY_NAME(SOCKETMANAGER_CONFIG_LOG_OPTIONS_DEFAULT), __socketmanager_config_STRINGIFY_VALUE(SOCKETMANAGER_CONFIG_LOG_OPTIONS_DEFAULT) },
#else
{ SOCKETMANAGER_CONFIG_LOG_OPTIONS_DEFAULT(__socketmanager_config_STRINGIFY_NAME), "__undefined__" },
#endif
#ifdef SOCKETMANAGER_CONFIG_LOG_BITS_DEFAULT
    { __socketmanager_config_STRINGIFY_NAME(SOCKETMANAGER_CONFIG_LOG_BITS_DEFAULT), __socketmanager_config_STRINGIFY_VALUE(SOCKETMANAGER_CONFIG_LOG_BITS_DEFAULT) },
#else
{ SOCKETMANAGER_CONFIG_LOG_BITS_DEFAULT(__socketmanager_config_STRINGIFY_NAME), "__undefined__" },
#endif
#ifdef SOCKETMANAGER_CONFIG_LOG_CUSTOM_BITS_DEFAULT
    { __socketmanager_config_STRINGIFY_NAME(SOCKETMANAGER_CONFIG_LOG_CUSTOM_BITS_DEFAULT), __socketmanager_config_STRINGIFY_VALUE(SOCKETMANAGER_CONFIG_LOG_CUSTOM_BITS_DEFAULT) },
#else
{ SOCKETMANAGER_CONFIG_LOG_CUSTOM_BITS_DEFAULT(__socketmanager_config_STRINGIFY_NAME), "__undefined__" },
#endif
#ifdef SOCKETMANAGER_CONFIG_PORTING_STDLIB
    { __socketmanager_config_STRINGIFY_NAME(SOCKETMANAGER_CONFIG_PORTING_STDLIB), __socketmanager_config_STRINGIFY_VALUE(SOCKETMANAGER_CONFIG_PORTING_STDLIB) },
#else
{ SOCKETMANAGER_CONFIG_PORTING_STDLIB(__socketmanager_config_STRINGIFY_NAME), "__undefined__" },
#endif
#ifdef SOCKETMANAGER_CONFIG_PORTING_INCLUDE_STDLIB_HEADERS
    { __socketmanager_config_STRINGIFY_NAME(SOCKETMANAGER_CONFIG_PORTING_INCLUDE_STDLIB_HEADERS), __socketmanager_config_STRINGIFY_VALUE(SOCKETMANAGER_CONFIG_PORTING_INCLUDE_STDLIB_HEADERS) },
#else
{ SOCKETMANAGER_CONFIG_PORTING_INCLUDE_STDLIB_HEADERS(__socketmanager_config_STRINGIFY_NAME), "__undefined__" },
#endif
#ifdef SOCKETMANAGER_CONFIG_INCLUDE_UCLI
    { __socketmanager_config_STRINGIFY_NAME(SOCKETMANAGER_CONFIG_INCLUDE_UCLI), __socketmanager_config_STRINGIFY_VALUE(SOCKETMANAGER_CONFIG_INCLUDE_UCLI) },
#else
{ SOCKETMANAGER_CONFIG_INCLUDE_UCLI(__socketmanager_config_STRINGIFY_NAME), "__undefined__" },
#endif
#ifdef SOCKETMANAGER_CONFIG_TIMESLICE_MS
    { __socketmanager_config_STRINGIFY_NAME(SOCKETMANAGER_CONFIG_TIMESLICE_MS), __socketmanager_config_STRINGIFY_VALUE(SOCKETMANAGER_CONFIG_TIMESLICE_MS) },
#else
{ SOCKETMANAGER_CONFIG_TIMESLICE_MS(__socketmanager_config_STRINGIFY_NAME), "__undefined__" },
#endif
#ifdef SOCKETMANAGER_CONFIG_MAX_TIMERS
    { __socketmanager_config_STRINGIFY_NAME(SOCKETMANAGER_CONFIG_MAX_TIMERS), __socketmanager_config_STRINGIFY_VALUE(SOCKETMANAGER_CONFIG_MAX_TIMERS) },
#else
{ SOCKETMANAGER_CONFIG_MAX_TIMERS(__socketmanager_config_STRINGIFY_NAME), "__undefined__" },
#endif
    { NULL, NULL }
};
#undef __socketmanager_config_STRINGIFY_VALUE
#undef __socketmanager_config_STRINGIFY_NAME

const char*
socketmanager_config_lookup(const char* setting)
{
    int i;
    for(i = 0; socketmanager_config_settings[i].name; i++) {
        if(strcmp(socketmanager_config_settings[i].name, setting)) {
            return socketmanager_config_settings[i].value;
        }
    }
    return NULL;
}

int
socketmanager_config_show(struct aim_pvs_s* pvs)
{
    int i;
    for(i = 0; socketmanager_config_settings[i].name; i++) {
        aim_printf(pvs, "%s = %s\n", socketmanager_config_settings[i].name, socketmanager_config_settings[i].value);
    }
    return i;
}

/* <auto.end.cdefs(SOCKETMANAGER_CONFIG_HEADER).source> */

static struct {
    uint32_t log_flags;
} staged_config;

static indigo_error_t
ind_soc_cfg_stage(cJSON *config)
{
    indigo_error_t err;

    err = ind_cfg_parse_loglevel(config, "logging.connection",
                                 SOCKETMANAGER_CONFIG_LOG_BITS_DEFAULT,
                                 &staged_config.log_flags);
    if (err != INDIGO_ERROR_NONE) {
        return err;
    }

    /* Always remove tracing when logging set via this interface */
    staged_config.log_flags &= ~AIM_LOG_BIT_TRACE;

    /* Not supporting setting log options yet */

    return INDIGO_ERROR_NONE;
}

static void
ind_soc_cfg_commit(void)
{
    aim_log_t *lobj;

    if ((lobj = aim_log_find("socketmanager")) == NULL) {
        AIM_LOG_WARN("Could not find log module");
    } else {
        lobj->common_flags = staged_config.log_flags;
    }
}

const struct ind_cfg_ops ind_soc_cfg_ops = {
    .stage = ind_soc_cfg_stage,
    .commit = ind_soc_cfg_commit,
};
