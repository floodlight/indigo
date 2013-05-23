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
 * @brief AIM Datatype String Parsing
 *
 * @addtogroup aim-sparse
 * @{
 *
 *****************************************************************************/
#ifndef __AIM_SPARSE_H__
#define __AIM_SPARSE_H__

#include <AIM/aim_config.h>

#include <AIM/aim_datatypes.h>

/**
 * @brief Parse the given datatypes.
 * @param args The arguments containing the string representations of the
 * the given types.
 * @param epvs Output PVS for parsing error messages, if relevent.
 * @param fmt The datatype format specifiers.
 */
int aim_sparse(char** args, aim_pvs_t* epvs, const char* fmt, ...);

/**
 * @brief Parse the given datatypes (vararg version).
 * @param args The arguments contaiining the string representations fo the
 * given types.
 * @param epvs Output PVS for parsing error messages, if relevent.
 * @param fmt The datatype format specifiers.
 * @param vargs The datatype arguments.
 */
int aim_vsparse(char** args, aim_pvs_t* epvs, const char* fmt, va_list vargs);

/**
 * @brief Parse the given datatypes (AIM vararg version).
 * @param args The arguments contaiining the string representations fo the
 * given types.
 * @param epvs Output PVS for parsing error messages, if relevent.
 * @param fmt The datatype format specifiers.
 * @param vargs The datatype arguments.
 */
int aim_avsparse(char** args, aim_pvs_t* epvs, const char* fmt, aim_va_list_t* vargs);

/**
 * @brief Parse the given string as the given datatype.
 * @param arg Input string.
 * @param epvs Output PVS for error messages, if relevent.
 * @param c The datatype character shortcut, if relevent.
 * @param type The datatype namne, if relevent.
 * @param vargs The datatype argument(s).
 */
int aim_avsparse_type(const char* arg, aim_pvs_t* epvs,
                      char c, char* type, aim_va_list_t* vargs);

#endif /* __AIM_SPARSE_H__ */
/* @}*/
