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
 * @brief OFConnectionManager Porting Macros.
 *
 * @addtogroup ofconnectionmanager_porting
 * @{
 *
 *****************************************************************************/
#ifndef __OFCONNECTIONMANAGER_PORTING_H__
#define __OFCONNECTIONMANAGER_PORTING_H__


/* <auto.start.portingmacro(ALL).define> */
#if OFCONNECTIONMANAGER_CONFIG_PORTING_INCLUDE_STDLIB_HEADERS == 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <memory.h>
#endif

#ifndef OFCONNECTIONMANAGER_MALLOC
    #if defined(GLOBAL_MALLOC)
        #define OFCONNECTIONMANAGER_MALLOC GLOBAL_MALLOC
    #elif OFCONNECTIONMANAGER_CONFIG_PORTING_STDLIB == 1
        #define OFCONNECTIONMANAGER_MALLOC malloc
    #else
        #error The macro OFCONNECTIONMANAGER_MALLOC is required but cannot be defined.
    #endif
#endif

#ifndef OFCONNECTIONMANAGER_FREE
    #if defined(GLOBAL_FREE)
        #define OFCONNECTIONMANAGER_FREE GLOBAL_FREE
    #elif OFCONNECTIONMANAGER_CONFIG_PORTING_STDLIB == 1
        #define OFCONNECTIONMANAGER_FREE free
    #else
        #error The macro OFCONNECTIONMANAGER_FREE is required but cannot be defined.
    #endif
#endif

#ifndef OFCONNECTIONMANAGER_MEMSET
    #if defined(GLOBAL_MEMSET)
        #define OFCONNECTIONMANAGER_MEMSET GLOBAL_MEMSET
    #elif OFCONNECTIONMANAGER_CONFIG_PORTING_STDLIB == 1
        #define OFCONNECTIONMANAGER_MEMSET memset
    #else
        #error The macro OFCONNECTIONMANAGER_MEMSET is required but cannot be defined.
    #endif
#endif

#ifndef OFCONNECTIONMANAGER_MEMCPY
    #if defined(GLOBAL_MEMCPY)
        #define OFCONNECTIONMANAGER_MEMCPY GLOBAL_MEMCPY
    #elif OFCONNECTIONMANAGER_CONFIG_PORTING_STDLIB == 1
        #define OFCONNECTIONMANAGER_MEMCPY memcpy
    #else
        #error The macro OFCONNECTIONMANAGER_MEMCPY is required but cannot be defined.
    #endif
#endif

#ifndef OFCONNECTIONMANAGER_STRNCPY
    #if defined(GLOBAL_STRNCPY)
        #define OFCONNECTIONMANAGER_STRNCPY GLOBAL_STRNCPY
    #elif OFCONNECTIONMANAGER_CONFIG_PORTING_STDLIB == 1
        #define OFCONNECTIONMANAGER_STRNCPY strncpy
    #else
        #error The macro OFCONNECTIONMANAGER_STRNCPY is required but cannot be defined.
    #endif
#endif

#ifndef OFCONNECTIONMANAGER_VSNPRINTF
    #if defined(GLOBAL_VSNPRINTF)
        #define OFCONNECTIONMANAGER_VSNPRINTF GLOBAL_VSNPRINTF
    #elif OFCONNECTIONMANAGER_CONFIG_PORTING_STDLIB == 1
        #define OFCONNECTIONMANAGER_VSNPRINTF vsnprintf
    #else
        #error The macro OFCONNECTIONMANAGER_VSNPRINTF is required but cannot be defined.
    #endif
#endif

#ifndef OFCONNECTIONMANAGER_SNPRINTF
    #if defined(GLOBAL_SNPRINTF)
        #define OFCONNECTIONMANAGER_SNPRINTF GLOBAL_SNPRINTF
    #elif OFCONNECTIONMANAGER_CONFIG_PORTING_STDLIB == 1
        #define OFCONNECTIONMANAGER_SNPRINTF snprintf
    #else
        #error The macro OFCONNECTIONMANAGER_SNPRINTF is required but cannot be defined.
    #endif
#endif

#ifndef OFCONNECTIONMANAGER_STRLEN
    #if defined(GLOBAL_STRLEN)
        #define OFCONNECTIONMANAGER_STRLEN GLOBAL_STRLEN
    #elif OFCONNECTIONMANAGER_CONFIG_PORTING_STDLIB == 1
        #define OFCONNECTIONMANAGER_STRLEN strlen
    #else
        #error The macro OFCONNECTIONMANAGER_STRLEN is required but cannot be defined.
    #endif
#endif

/* <auto.end.portingmacro(ALL).define> */


#endif /* __OFCONNECTIONMANAGER_PORTING_H__ */
/* @} */
