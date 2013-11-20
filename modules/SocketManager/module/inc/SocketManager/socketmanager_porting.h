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
 * @brief SocketManager Porting Macros.
 *
 *****************************************************************************/
#ifndef __SOCKETMANAGER_PORTING_H__
#define __SOCKETMANAGER_PORTING_H__


/* <auto.start.portingmacro(ALL).define> */
#if SOCKETMANAGER_CONFIG_PORTING_INCLUDE_STDLIB_HEADERS == 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <memory.h>
#endif

#ifndef SOCKETMANAGER_MALLOC
    #if defined(GLOBAL_MALLOC)
        #define SOCKETMANAGER_MALLOC GLOBAL_MALLOC
    #elif SOCKETMANAGER_CONFIG_PORTING_STDLIB == 1
        #define SOCKETMANAGER_MALLOC malloc
    #else
        #error The macro SOCKETMANAGER_MALLOC is required but cannot be defined.
    #endif
#endif

#ifndef SOCKETMANAGER_FREE
    #if defined(GLOBAL_FREE)
        #define SOCKETMANAGER_FREE GLOBAL_FREE
    #elif SOCKETMANAGER_CONFIG_PORTING_STDLIB == 1
        #define SOCKETMANAGER_FREE free
    #else
        #error The macro SOCKETMANAGER_FREE is required but cannot be defined.
    #endif
#endif

#ifndef SOCKETMANAGER_MEMSET
    #if defined(GLOBAL_MEMSET)
        #define SOCKETMANAGER_MEMSET GLOBAL_MEMSET
    #elif SOCKETMANAGER_CONFIG_PORTING_STDLIB == 1
        #define SOCKETMANAGER_MEMSET memset
    #else
        #error The macro SOCKETMANAGER_MEMSET is required but cannot be defined.
    #endif
#endif

#ifndef SOCKETMANAGER_MEMCPY
    #if defined(GLOBAL_MEMCPY)
        #define SOCKETMANAGER_MEMCPY GLOBAL_MEMCPY
    #elif SOCKETMANAGER_CONFIG_PORTING_STDLIB == 1
        #define SOCKETMANAGER_MEMCPY memcpy
    #else
        #error The macro SOCKETMANAGER_MEMCPY is required but cannot be defined.
    #endif
#endif

#ifndef SOCKETMANAGER_STRNCPY
    #if defined(GLOBAL_STRNCPY)
        #define SOCKETMANAGER_STRNCPY GLOBAL_STRNCPY
    #elif SOCKETMANAGER_CONFIG_PORTING_STDLIB == 1
        #define SOCKETMANAGER_STRNCPY strncpy
    #else
        #error The macro SOCKETMANAGER_STRNCPY is required but cannot be defined.
    #endif
#endif

#ifndef SOCKETMANAGER_VSNPRINTF
    #if defined(GLOBAL_VSNPRINTF)
        #define SOCKETMANAGER_VSNPRINTF GLOBAL_VSNPRINTF
    #elif SOCKETMANAGER_CONFIG_PORTING_STDLIB == 1
        #define SOCKETMANAGER_VSNPRINTF vsnprintf
    #else
        #error The macro SOCKETMANAGER_VSNPRINTF is required but cannot be defined.
    #endif
#endif

#ifndef SOCKETMANAGER_SNPRINTF
    #if defined(GLOBAL_SNPRINTF)
        #define SOCKETMANAGER_SNPRINTF GLOBAL_SNPRINTF
    #elif SOCKETMANAGER_CONFIG_PORTING_STDLIB == 1
        #define SOCKETMANAGER_SNPRINTF snprintf
    #else
        #error The macro SOCKETMANAGER_SNPRINTF is required but cannot be defined.
    #endif
#endif

#ifndef SOCKETMANAGER_STRLEN
    #if defined(GLOBAL_STRLEN)
        #define SOCKETMANAGER_STRLEN GLOBAL_STRLEN
    #elif SOCKETMANAGER_CONFIG_PORTING_STDLIB == 1
        #define SOCKETMANAGER_STRLEN strlen
    #else
        #error The macro SOCKETMANAGER_STRLEN is required but cannot be defined.
    #endif
#endif

/* <auto.end.portingmacro(ALL).define> */


#endif /* __SOCKETMANAGER_PORTING_H__ */
