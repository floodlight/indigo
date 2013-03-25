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
 *  /module/inc/AIM/aim_string.h
 *
 * @file
 * @brief AIM String Definitions.
 *
 * @addtogroup aim-string
 * @{
 *
 *****************************************************************************/
#ifndef __AIM_STRING_H__
#define __AIM_STRING_H__

/**
 * @brief String duplication.
 * @param s The string to duplicate.
 * @returns The duplicated string.
 *
 * @note The strdup() function is not a C99 standard library function.
 * We provide our own for portability.
 */
char* aim_strdup(const char* s);

/**
 * @brief Safe, reentrant strtok_r()
 * @param str The string to tokenize.
 * @param delim The delimiter list.
 * @param saveptr Pointer for internal state.
 *
 * @note The strtok_r() function is not a standard library function.
 * We provide our own for portability.
 */
char* aim_strtok_r(char* str, const char* delim, char** saveptr);


/**
 * @brief Predictable, C99-compliant version of snprintf()
 * @param str The buffer
 * @param size The size
 * @param fmt The format
 *
 * @note Implemented because we rely on the C99 behavior wrt character counts
 * and not all platforms implement it.
 */
int aim_snprintf(char* str, int size, const char* fmt, ...);

/**
 * @brief Predicatable, C99-compliant version of vsnprintf()
 * @param str The buffer
 * @param size The size
 * @param fmt The format
 * @param vargs The arguments
 *
 * @note Implemented because we rely on the C99 behavior wrt character counts
 * and not all platforms implement it.
 */
int aim_vsnprintf(char* str, int size, const char* fmt, va_list vargs);

/**
 * @brief Duplicate a string with formatting.
 * @param fmt The format
 */
char* aim_fstrdup(const char* fmt, ...);

/**
 * @brief Duplicate a string with formatting.
 * @param fmt The format.
 * @param vargs The args.
 */
char* aim_vfstrdup(const char* fmt, va_list vargs);

/**
 * @brief Portable strlcpy
 * @param dst Destination
 * @param src Source
 * @param size Size
 */
int aim_strlcpy(char* dst, const char* src, int size);

/**
 * @brief Format a byte buffer as a printable string.
 * @param data Data buffer.
 * @param size size of the data.
 * @param columns Number of output columns.
 * @note You must free the result when finished.
 */
char* aim_bytes_to_string(uint8_t* data, int size, int columns);

/**
 * @brief Interpret a string as a byte buffer.
 * @param src Source string.
 * @param [out] size Receives the size of the returned buffer.
 * @note You must free the result when finished.
 */
uint8_t* aim_bytes_from_string(const char* src, int* size);

/**
 * @brief Join strings.
 * @param string The join string.
 * @param strings The strings to join.
 * @param count The number of strings.
 * @note You must free the returned buffer.
 */
char* aim_strjoin(const char* string, const char** strings, int count);

#endif /* __AIM_STRING_H__ */
/*@}*/
