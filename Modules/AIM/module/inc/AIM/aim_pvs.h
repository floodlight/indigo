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
 *  /module/inc/AIM/aim_pvs_file.h
 *
 *
 * @file
 * @brief AIM Output Virtualization.
 *
 * @addtogroup aim-pvs-file
 * @{
 *
 *****************************************************************************/
#ifndef __AIM_PVS_H__
#define __AIM_PVS_H__

#include <AIM/aim_config.h>
#include <AIM/aim_valist.h>
#include <AIM/aim_object.h>
#include <stdarg.h>

/** aim_pvs_t */
typedef struct aim_pvs_s aim_pvs_t;

/**
 * All fundamental output vectors share this signature.
 */
typedef int (*aim_vprint_f)(aim_pvs_t* pvs, const char* fmt, va_list vargs);


/**
 * This structure represents a fundamental output stream.
 * All functions which produce output should be written to
 * accept a pointer to this structure.
 */
struct aim_pvs_s {
    /** AIM object. */
    aim_object_t object;

    /**
     * This is the vector that will eventually receive the output for
     * this stream.
     */
    aim_vprint_f vprintf;

    /**
     * Any output stream can be enabled or disabled.
     */
    int enabled;

    /** Call counter */
    uint32_t counter;

    /**
     * Optional:
     * returns whether this PVS can be considered a tty, where applicable
     */
    int (*isatty)(aim_pvs_t* pvs);

}; /* aim_pvs_t */

/**
 * Use this builtin PVS structure for output to stdout.
 */
extern aim_pvs_t aim_pvs_stdout;

/**
 * Use this builtin PVS structure for output to stderr.
 */
extern aim_pvs_t aim_pvs_stderr;

/**
 * Use this builtin PVS structure for discarding output.
 */
extern aim_pvs_t aim_pvs_none;

/**
 * @brief printf-style output to any PVS.
 * @param pvs The PVS output stream.
 * @param fmt The format string.
 * @note This does not include custom datatype processing.
 * @note Most clients should call aim_printf() instead.
 */
int aim_pvs_printf(aim_pvs_t* pvs, const char* fmt, ...);

/**
 * @brief vprintf-style output to any PVS.
 * @param pvs The PVS output stream.
 * @param fmt The format string.
 * @param vargs The format arguments.
 * @note This does not include custom datatype processing.
 * @note Most clients should call aim_vprintf() instead.
 */
int aim_pvs_vprintf(aim_pvs_t* pvs, const char* fmt, va_list vargs);

/**
 * @brief vprintf-style output to any PVS.
 * @param pvs The PVS output stream.
 * @param fmt The format string.
 * @param vargs The AIM variable argument structure.
 * @note This does not include custom datatype processing.
 * @note Most clients should call aim_avprintf() instead.
 */
int aim_pvs_avprintf(aim_pvs_t* pvs, const char* fmt, aim_va_list_t* vargs);

/**
 * @brief Enable or disable output on the given PVS.
 * @param pvs The PVS output stream.
 * @param enable Enable/Disable state.
 *
 * @note All output for the PVS will be silently discarded when
 * the PVS is disabled.
 */
int aim_pvs_enable(aim_pvs_t* pvs, int enable);

/**
 * @brief Destroy a PVS object.
 * @param pvs The object to destroy.
 */
void aim_pvs_destroy(aim_pvs_t* pvs);

/**
 * @brief Determine whether a PVS is a tty.
 * @param pvs The object to query.
 * @returns 1 If the object is a tty.
 * @returns 0 If the object is not a tty.
 * @returns -1 If unknown.
 */
int aim_pvs_isatty(aim_pvs_t* pvs);

#endif /* __AIM_PVS_H__ */
/*@}*/
