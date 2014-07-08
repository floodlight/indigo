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
 *  /module/src/ofconnectionmanager_log.h
 *
 *  OFConnectionManager Log Header
 *
 *****************************************************************************/
#ifndef __OFCONNECTIONMANAGER_LOG_H__
#define __OFCONNECTIONMANAGER_LOG_H__


#include <OFConnectionManager/ofconnectionmanager_config.h>

#define AIM_LOG_MODULE_NAME ofconnectionmanager
#include <AIM/aim_log.h>

/* <auto.start.aim_custom_log_macro(ALL).header> */

/******************************************************************************
 *
 * Custom Module Log Macros
 *
 *****************************************************************************/

/** Log a module-level local */
#define OFCONNECTIONMANAGER_LOG_MOD_LOCAL(...) \
    AIM_LOG_MOD_CUSTOM(OFCONNECTIONMANAGER_LOG_FLAG_LOCAL, "LOCAL", __VA_ARGS__)
/** Log a module-level local with ratelimiting */
#define OFCONNECTIONMANAGER_LOG_MOD_RL_LOCAL(_rl, _time, ...)           \
    AIM_LOG_MOD_RL_CUSTOM(OFCONNECTIONMANAGER_LOG_FLAG_LOCAL, "LOCAL", _rl, _time, __VA_ARGS__)

/******************************************************************************
 *
 * Custom Object Log Macros
 *
 *****************************************************************************/

/** Log an object-level local */
#define OFCONNECTIONMANAGER_LOG_OBJ_LOCAL(_obj, ...) \
    AIM_LOG_OBJ_CUSTOM(_obj, OFCONNECTIONMANAGER_LOG_FLAG_LOCAL, "LOCAL", __VA_ARGS__)
/** Log an object-level local with ratelimiting */
#define OFCONNECTIONMANAGER_LOG_OBJ_RL_LOCAL(_obj, _rl, _time, ...) \
    AIM_LOG_OBJ_RL_CUSTOM(_obj, OFCONNECTIONMANAGER_LOG_FLAG_LOCAL, "LOCAL", _rl, _time, __VA_ARGS__)

/******************************************************************************
 *
 * Default Macro Mappings
 *
 *****************************************************************************/
#ifdef AIM_LOG_OBJ_DEFAULT

/** LOCAL -> OBJ_LOCAL */
#define OFCONNECTIONMANAGER_LOG_LOCAL OFCONNECTIONMANAGER_LOG_OBJ_LOCAL
/** RL_LOCAL -> OBJ_RL_LOCAL */
#define OFCONNECTIONMANAGER_LOG_RL_LOCAL OFCONNECTIONMANAGER_LOG_RL_OBJ_LOCAL


#else

/** LOCAL -> MOD_LOCAL */
#define OFCONNECTIONMANAGER_LOG_LOCAL OFCONNECTIONMANAGER_LOG_MOD_LOCAL
/** RL_LOCAL -> MOD_RL_LOCAL */
#define OFCONNECTIONMANAGER_LOG_RL_LOCAL OFCONNECTIONMANAGER_LOG_MOD_RL_LOCAL

#endif
/* <auto.end.aim_custom_log_macro(ALL).header> */


/* <auto.start.enum(ofconnectionmanager_log_flag).header> */
/** ofconnectionmanager_log_flag */
typedef enum ofconnectionmanager_log_flag_e {
    OFCONNECTIONMANAGER_LOG_FLAG_LOCAL,
    OFCONNECTIONMANAGER_LOG_FLAG_LAST = OFCONNECTIONMANAGER_LOG_FLAG_LOCAL,
    OFCONNECTIONMANAGER_LOG_FLAG_COUNT,
    OFCONNECTIONMANAGER_LOG_FLAG_INVALID = -1,
} ofconnectionmanager_log_flag_t;

/** Strings macro. */
#define OFCONNECTIONMANAGER_LOG_FLAG_STRINGS \
{\
    "local", \
}
/** Enum names. */
const char* ofconnectionmanager_log_flag_name(ofconnectionmanager_log_flag_t e);

/** Enum values. */
int ofconnectionmanager_log_flag_value(const char* str, ofconnectionmanager_log_flag_t* e, int substr);

/** Enum descriptions. */
const char* ofconnectionmanager_log_flag_desc(ofconnectionmanager_log_flag_t e);

/** validator */
#define OFCONNECTIONMANAGER_LOG_FLAG_VALID(_e) \
    ( (0 <= (_e)) && ((_e) <= OFCONNECTIONMANAGER_LOG_FLAG_LOCAL))

/** ofconnectionmanager_log_flag_map table. */
extern aim_map_si_t ofconnectionmanager_log_flag_map[];
/** ofconnectionmanager_log_flag_desc_map table. */
extern aim_map_si_t ofconnectionmanager_log_flag_desc_map[];
/* <auto.end.enum(ofconnectionmanager_log_flag).header> */


#endif /* __OFCONNECTIONMANAGER_LOG_H__ */
