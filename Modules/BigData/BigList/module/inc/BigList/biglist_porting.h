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
 * @brief BigList Porting Definitions.
 *
 * @addtogroup biglist-porting
 * @{
 *
 *****************************************************************************/
#ifndef __BIGLIST_PORTING_H__
#define __BIGLIST_PORTING_H__


#include <BigList/biglist_config.h>


/* <auto.start.portingmacro(ALL).define> */
#if BIGLIST_CONFIG_PORTING_INCLUDE_STDLIB_HEADERS == 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <memory.h>
#endif

#ifndef BIGLIST_MALLOC
    #if defined(GLOBAL_MALLOC)
        #define BIGLIST_MALLOC GLOBAL_MALLOC
    #elif BIGLIST_CONFIG_PORTING_STDLIB == 1
        #define BIGLIST_MALLOC malloc
    #else
        #error The macro BIGLIST_MALLOC is required but cannot be defined.
    #endif
#endif

#ifndef BIGLIST_FREE
    #if defined(GLOBAL_FREE)
        #define BIGLIST_FREE GLOBAL_FREE
    #elif BIGLIST_CONFIG_PORTING_STDLIB == 1
        #define BIGLIST_FREE free
    #else
        #error The macro BIGLIST_FREE is required but cannot be defined.
    #endif
#endif

#ifndef BIGLIST_MEMSET
    #if defined(GLOBAL_MEMSET)
        #define BIGLIST_MEMSET GLOBAL_MEMSET
    #elif BIGLIST_CONFIG_PORTING_STDLIB == 1
        #define BIGLIST_MEMSET memset
    #else
        #error The macro BIGLIST_MEMSET is required but cannot be defined.
    #endif
#endif

#ifndef BIGLIST_MEMCPY
    #if defined(GLOBAL_MEMCPY)
        #define BIGLIST_MEMCPY GLOBAL_MEMCPY
    #elif BIGLIST_CONFIG_PORTING_STDLIB == 1
        #define BIGLIST_MEMCPY memcpy
    #else
        #error The macro BIGLIST_MEMCPY is required but cannot be defined.
    #endif
#endif

#ifndef BIGLIST_STRNCPY
    #if defined(GLOBAL_STRNCPY)
        #define BIGLIST_STRNCPY GLOBAL_STRNCPY
    #elif BIGLIST_CONFIG_PORTING_STDLIB == 1
        #define BIGLIST_STRNCPY strncpy
    #else
        #error The macro BIGLIST_STRNCPY is required but cannot be defined.
    #endif
#endif

#ifndef BIGLIST_VSNPRINTF
    #if defined(GLOBAL_VSNPRINTF)
        #define BIGLIST_VSNPRINTF GLOBAL_VSNPRINTF
    #elif BIGLIST_CONFIG_PORTING_STDLIB == 1
        #define BIGLIST_VSNPRINTF vsnprintf
    #else
        #error The macro BIGLIST_VSNPRINTF is required but cannot be defined.
    #endif
#endif

#ifndef BIGLIST_SNPRINTF
    #if defined(GLOBAL_SNPRINTF)
        #define BIGLIST_SNPRINTF GLOBAL_SNPRINTF
    #elif BIGLIST_CONFIG_PORTING_STDLIB == 1
        #define BIGLIST_SNPRINTF snprintf
    #else
        #error The macro BIGLIST_SNPRINTF is required but cannot be defined.
    #endif
#endif

#ifndef BIGLIST_STRLEN
    #if defined(GLOBAL_STRLEN)
        #define BIGLIST_STRLEN GLOBAL_STRLEN
    #elif BIGLIST_CONFIG_PORTING_STDLIB == 1
        #define BIGLIST_STRLEN strlen
    #else
        #error The macro BIGLIST_STRLEN is required but cannot be defined.
    #endif
#endif

/* <auto.end.portingmacro(ALL).define> */

#endif /* __BIGLIST_PORTING_H__ */
/* @}*/
