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
#include "ofstatemanager_log.h"
#include <stdlib.h>
#include <cjson/cJSON.h>
#include <Configuration/configuration.h>

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

static struct {
    uint32_t log_flags;
    of_desc_str_t hw_desc;
    of_desc_str_t sw_desc;
    of_desc_str_t dp_desc;
    of_desc_str_t mfr_desc;
    of_serial_num_t serial_num;
    of_dpid_t dpid;
    indigo_core_disconnected_mode_t disconnected_mode;
} staged_config;

/*
 * Parse a string into INDIGO_CORE_DISCONNECTED_*.
 * Returns -1 if the input is invalid.
 */
static int
parse_disconnected_mode(const char *str)
{
    if (!strcmp(str, "sticky")) {
        return INDIGO_CORE_DISCONNECTED_MODE_STICKY;
    } else if (!strcmp(str, "closed")) {
        return INDIGO_CORE_DISCONNECTED_MODE_CLOSED;
    } else if (!strcmp(str, "disabled")) {
        return INDIGO_CORE_DISCONNECTED_MODE_DISABLED;
    } else if (!strcmp(str, "lockdown")) {
        return INDIGO_CORE_DISCONNECTED_MODE_LOCKDOWN;
    } else if (!strcmp(str, "local")) {
        return INDIGO_CORE_DISCONNECTED_MODE_LOCAL;
    } else {
        AIM_LOG_ERROR("Config: unrecognized disconnected_mode %s", str);
        AIM_LOG_ERROR("  Must be sticky, closed, disabled, lockdown or local");
        return -1;
    }
}

/**
 * Get a fixed length string from the JSON object with given key
 *
 * @returns 0 on success, -1 if key is not present and a string
 *
 * If string is longer than len, it is truncated and
 * dest[len-1] is set to 0.
 */

static int
get_fixed_len_string(char *dest, int len, cJSON *root, char *key)
{
    indigo_error_t err;
    char *str;

    err = ind_cfg_lookup_string(root, key, &str);
    if (err < 0) {
        if (err == INDIGO_ERROR_PARAM) {
            AIM_LOG_ERROR("Config: Could not parse %s", key);
        } else if (err == INDIGO_ERROR_NOT_FOUND) {
            AIM_LOG_ERROR("Config: Missing required key %s", key);
        }
        return -1;
    }

    strncpy(dest, str, len);

    return 0;
}

static indigo_error_t
ind_core_cfg_stage(cJSON *config)
{
    char *str;
    indigo_error_t err;

    err = ind_cfg_parse_loglevel(config, "logging.flowtable",
                                 OFSTATEMANAGER_CONFIG_LOG_BITS_DEFAULT,
                                 &staged_config.log_flags);
    if (err != INDIGO_ERROR_NONE) {
        return err;
    }

    /* Not supporting setting log options yet */

    err = 0;
    err |= get_fixed_len_string(staged_config.hw_desc, OF_DESC_STR_LEN,
                                config, "of_hw_desc");
    err |= get_fixed_len_string(staged_config.sw_desc, OF_DESC_STR_LEN,
                                config, "of_sw_desc");
    err |= get_fixed_len_string(staged_config.mfr_desc, OF_DESC_STR_LEN,
                                config, "of_mfr_desc");
    err |= get_fixed_len_string(staged_config.dp_desc, OF_DESC_STR_LEN,
                                config, "of_dp_desc");
    err |= get_fixed_len_string(staged_config.serial_num, OF_SERIAL_NUM_LEN,
                                config, "of_serial_num");
    if (err != 0) {
        /* Error message logged by get_fixed_len_string */
        return INDIGO_ERROR_PARAM;
    }

    err = ind_cfg_lookup_string(config, "of_datapath_id", &str);
    if (err == INDIGO_ERROR_NONE) {
        char *endptr;
        staged_config.dpid = strtoull(str, &endptr, 16);
        if (*endptr) { /* Did not parse string */
            AIM_LOG_ERROR("Config: Could not parse of_datapath_id; "
                          "must be hex digit string");
            return INDIGO_ERROR_PARAM;
        }
    } else {
        if (err == INDIGO_ERROR_PARAM) {
            AIM_LOG_ERROR("Config: Could not parse of_datapath_id");
        } else if (err == INDIGO_ERROR_NOT_FOUND) {
            AIM_LOG_ERROR("Config: Missing required key of_datapath_id");
        }
        return err;
    }

    err = ind_cfg_lookup_string(config, "disconnected_mode", &str);
    if (err == INDIGO_ERROR_NONE) {
        staged_config.disconnected_mode = parse_disconnected_mode(str);
        if (staged_config.disconnected_mode == -1) {
            AIM_LOG_ERROR("Config: Could not parse disconnected_mode");
            return INDIGO_ERROR_PARAM;
        }
    } else if (err == INDIGO_ERROR_NOT_FOUND) {
        staged_config.disconnected_mode = INDIGO_CORE_DISCONNECTED_MODE_STICKY;
    } else {
        if (err == INDIGO_ERROR_PARAM) {
            AIM_LOG_ERROR("Config: Could not parse disconnected_mode");
        }
        return err;
    }

    return INDIGO_ERROR_NONE;
}

static void
ind_core_cfg_commit(void)
{
    aim_log_t *lobj;

    if ((lobj = aim_log_find("ofstatemanager")) == NULL) {
        AIM_LOG_WARN("Could not find log module");
    } else {
        lobj->common_flags = staged_config.log_flags;
    }

    /* Set whether or not changed */
    (void)ind_core_hw_desc_set(staged_config.hw_desc);
    (void)ind_core_sw_desc_set(staged_config.sw_desc);
    (void)ind_core_dp_desc_set(staged_config.dp_desc);
    (void)ind_core_mfr_desc_set(staged_config.mfr_desc);
    (void)ind_core_serial_num_set(staged_config.serial_num);
    (void)indigo_core_dpid_set(staged_config.dpid);
    (void)indigo_core_disconnected_mode_set(staged_config.disconnected_mode);
}

const struct ind_cfg_ops ind_core_cfg_ops = {
    .stage = ind_core_cfg_stage,
    .commit = ind_core_cfg_commit,
};
