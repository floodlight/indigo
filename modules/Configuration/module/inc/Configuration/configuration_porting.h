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
 * @brief Configuration Porting Macros.
 *
 * @addtogroup configuration_porting
 * @{
 *
 *****************************************************************************/
#ifndef __CONFIGURATION_PORTING_H__
#define __CONFIGURATION_PORTING_H__


/* <auto.start.portingmacro(ALL).define> */
#if CONFIGURATION_CONFIG_PORTING_INCLUDE_STDLIB_HEADERS == 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <memory.h>
#endif

#ifndef CONFIGURATION_MALLOC
    #if defined(GLOBAL_MALLOC)
        #define CONFIGURATION_MALLOC GLOBAL_MALLOC
    #elif CONFIGURATION_CONFIG_PORTING_STDLIB == 1
        #define CONFIGURATION_MALLOC malloc
    #else
        #error The macro CONFIGURATION_MALLOC is required but cannot be defined.
    #endif
#endif

#ifndef CONFIGURATION_FREE
    #if defined(GLOBAL_FREE)
        #define CONFIGURATION_FREE GLOBAL_FREE
    #elif CONFIGURATION_CONFIG_PORTING_STDLIB == 1
        #define CONFIGURATION_FREE free
    #else
        #error The macro CONFIGURATION_FREE is required but cannot be defined.
    #endif
#endif

#ifndef CONFIGURATION_MEMSET
    #if defined(GLOBAL_MEMSET)
        #define CONFIGURATION_MEMSET GLOBAL_MEMSET
    #elif CONFIGURATION_CONFIG_PORTING_STDLIB == 1
        #define CONFIGURATION_MEMSET memset
    #else
        #error The macro CONFIGURATION_MEMSET is required but cannot be defined.
    #endif
#endif

#ifndef CONFIGURATION_MEMCPY
    #if defined(GLOBAL_MEMCPY)
        #define CONFIGURATION_MEMCPY GLOBAL_MEMCPY
    #elif CONFIGURATION_CONFIG_PORTING_STDLIB == 1
        #define CONFIGURATION_MEMCPY memcpy
    #else
        #error The macro CONFIGURATION_MEMCPY is required but cannot be defined.
    #endif
#endif

#ifndef CONFIGURATION_STRNCPY
    #if defined(GLOBAL_STRNCPY)
        #define CONFIGURATION_STRNCPY GLOBAL_STRNCPY
    #elif CONFIGURATION_CONFIG_PORTING_STDLIB == 1
        #define CONFIGURATION_STRNCPY strncpy
    #else
        #error The macro CONFIGURATION_STRNCPY is required but cannot be defined.
    #endif
#endif

#ifndef CONFIGURATION_VSNPRINTF
    #if defined(GLOBAL_VSNPRINTF)
        #define CONFIGURATION_VSNPRINTF GLOBAL_VSNPRINTF
    #elif CONFIGURATION_CONFIG_PORTING_STDLIB == 1
        #define CONFIGURATION_VSNPRINTF vsnprintf
    #else
        #error The macro CONFIGURATION_VSNPRINTF is required but cannot be defined.
    #endif
#endif

#ifndef CONFIGURATION_SNPRINTF
    #if defined(GLOBAL_SNPRINTF)
        #define CONFIGURATION_SNPRINTF GLOBAL_SNPRINTF
    #elif CONFIGURATION_CONFIG_PORTING_STDLIB == 1
        #define CONFIGURATION_SNPRINTF snprintf
    #else
        #error The macro CONFIGURATION_SNPRINTF is required but cannot be defined.
    #endif
#endif

#ifndef CONFIGURATION_STRLEN
    #if defined(GLOBAL_STRLEN)
        #define CONFIGURATION_STRLEN GLOBAL_STRLEN
    #elif CONFIGURATION_CONFIG_PORTING_STDLIB == 1
        #define CONFIGURATION_STRLEN strlen
    #else
        #error The macro CONFIGURATION_STRLEN is required but cannot be defined.
    #endif
#endif

/* <auto.end.portingmacro(ALL).define> */


#endif /* __CONFIGURATION_PORTING_H__ */
/* @} */
