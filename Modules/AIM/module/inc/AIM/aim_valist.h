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
 *  /module/inc/AIM/aim_valist.h
 *
 * @file
 * @brief AIM Variable Argument List Definitions.
 *
 * @addtogroup aim-valist
 * @{
 *
 *****************************************************************************/
#ifndef __AIM_VALIST_H__
#define __AIM_VALIST_H__

#include <AIM/aim_config.h>
#include <stdarg.h>

/**
 * Sometimes we must pass va_lists as pointers to be shared
 * between different functions processing (and updating) the same
 * va_list.
 *
 * This is allowed in the C99 specification, but
 * actually doing it becomes problematic when va_list is defined
 * as an array, rather than a pointer, as taking the address of the local
 * array is not equivalent to "va_list*". This has nothing to do with
 * va_lists per se, but the way C handles arrays as parameters to functions.
 *
 * We get around this portability problem by defining a structure to
 * contain the va_list, and pass a pointer to that structure
 * instead.
 *
 * We could have defined a macro to create a va_list* from a va_list,
 * but this would have to be configured by hand, and on architectures
 * where va_list is a pointer, you would not see a warning or a bug
 * to indicate you have introduced a portability problem for other
 * architectures.
 *
 * If we always pass aim_va_list_t*, instead of va_list*, we will
 * always get typechecking and portability for all platforms.
 *
 */

typedef struct aim_va_list_s {
    /** The va_list structure */
    va_list val;
} aim_va_list_t;




/**
 * These macros help manage C99 variadic macro parameter lists,
 * particularly pulling and separating the first argument from
 * the rest in a standard compliant way.
 *
 * This idea shamelessly stolen from those that struggled before us.
 *
 */

/** Expands to the first argument only */
#define AIM_VA_ARGS_FIRST(...) AIM_VA_ARGS_FIRST_HELPER(__VA_ARGS__, ignore)

/**
 * Expands to nothing if there is only one argument.
 * Expands to a comma followed by the remaining arguments if there are more
 * than one.
 */
#define AIM_VA_ARGS_REST(...) \
    AIM_VA_ARGS_REST_HELPER(AIM_VA_ARGS_NUM(__VA_ARGS__), __VA_ARGS__)


/** Internal helpers for the above macros */

/** internal */
#define AIM_VA_ARGS_FIRST_HELPER(_first, ...) _first

/** internal */
#define AIM_VA_ARGS_REST_HELPER(qty, ...) \
    AIM_VA_ARGS_REST_HELPER2(qty, __VA_ARGS__)

/** internal */
#define AIM_VA_ARGS_REST_HELPER2(qty, ...) \
    AIM_VA_ARGS_REST_HELPER_##qty(__VA_ARGS__)

/** internal */
#define AIM_VA_ARGS_REST_HELPER_ONE(_first)
/** internal */
#define AIM_VA_ARGS_REST_HELPER_TWOORMORE(_first, ...) , __VA_ARGS__
/** internal */
#define AIM_VA_ARGS_NUM(...)                                            \
    AIM_VA_ARGS_SELECT_30TH(__VA_ARGS__, \
                            TWOORMORE, TWOORMORE, TWOORMORE, TWOORMORE, \
                            TWOORMORE, TWOORMORE, TWOORMORE, TWOORMORE, \
                            TWOORMORE, TWOORMORE, TWOORMORE, TWOORMORE, \
                            TWOORMORE, TWOORMORE, TWOORMORE, TWOORMORE, \
                            TWOORMORE, TWOORMORE, TWOORMORE, TWOORMORE, \
                            TWOORMORE, TWOORMORE, TWOORMORE, TWOORMORE, \
                            TWOORMORE, TWOORMORE, TWOORMORE, TWOORMORE, \
                            ONE, ignore)
/** internal */
#define AIM_VA_ARGS_SELECT_30TH(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, \
                                a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, \
                                a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, ...) a30






















#endif /* __AIM_VALIST_H__ */
/*@}*/
