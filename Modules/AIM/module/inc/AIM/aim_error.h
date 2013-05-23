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

/**************************************************************************//**
 *
 *
 *
 *
 *****************************************************************************/
#ifndef __AIM_ERROR_H__
#define __AIM_ERROR_H__

#include <AIM/aim_config.h>
#include <AIM/aim_valist.h>

/* <auto.start.enum(aim_error).header> */
/** aim_error */
typedef enum aim_error_e {
    AIM_ERROR_NONE,
    AIM_ERROR_PARAM = -1,
    AIM_ERROR_NOT_FOUND = -2,
    AIM_ERROR_INTERNAL = -3,
} aim_error_t;

/** Enum names. */
const char* aim_error_name(aim_error_t e);

/** Enum values. */
int aim_error_value(const char* str, aim_error_t* e, int substr);

/** Enum descriptions. */
const char* aim_error_desc(aim_error_t e);

/** Enum validator. */
int aim_error_valid(aim_error_t e);

/** validator */
#define AIM_ERROR_VALID(_e) \
    (aim_error_valid((_e)))

/** aim_error_map table. */
extern aim_map_si_t aim_error_map[];
/** aim_error_desc_map table. */
extern aim_map_si_t aim_error_desc_map[];
/* <auto.end.enum(aim_error).header> */

/**
 * @brief Report an unrecoverable error.
 * @param fmt Message format.
 * @note The behavior of this function is platform
 * specific, but should always be considered a termination event.
 *
 */
void aim_die(const char* function,
             const char* file,
             int line,
             const char* fmt, ...);

/** This macro should usually be used */
#define AIM_DIE(...)                                            \
    aim_die(__func__, __FILE__, __LINE__,  __VA_ARGS__ );

#endif /* __AIM_ERROR_H__ */
