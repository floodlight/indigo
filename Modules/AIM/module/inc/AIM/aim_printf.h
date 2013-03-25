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
 * @file
 * @brief AIM Printf and Custom Datatype Formatting
 *
 * @addtogroup aim-printf
 * @{
 *
 *****************************************************************************/
#ifndef __AIM_PRINTF_H__
#define __AIM_PRINTF_H__

#include <AIM/aim_pvs.h>

/**
 * @brief printf-style output to any PVS with custom datatype formatting.
 * @param pvs The PVS output stream.
 * @param fmt The format string.
 */
int aim_printf(aim_pvs_t* pvs, const char* fmt, ...);

/**
 * @brief vprintf-style output to any PVS with custom datatype formatting.
 * @param pvs The PVS output stream.
 * @param fmt The format string.
 * @param vargs The format arguments.
 * @note This does not include custom datatype processing.
 * @note Most clients should call aim_vprintf() instead.
 */
int aim_vprintf(aim_pvs_t* pvs, const char* fmt, va_list vargs);

/**
 * @brief vprintf-style output to any PVS with custom datatype formatting.
 * @param pvs The PVS output stream.
 * @param fmt The format string.
 * @param vargs The AIM variable argument structure.
 * @note This does not include custom datatype processing.
 * @note Most clients should call aim_avprintf() instead.
 */
int aim_avprintf(aim_pvs_t* pvs, const char* fmt, aim_va_list_t* vargs);

#endif /* __AIM_PRINTF_H__ */
/* @}*/
