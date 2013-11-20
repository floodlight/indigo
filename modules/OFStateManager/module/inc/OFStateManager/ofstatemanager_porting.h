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
 * @brief OFStateManager Porting Macros.
 *
 * @addtogroup ofstatemanager_porting
 * @{
 *
 *****************************************************************************/
#ifndef __OFSTATEMANAGER_PORTING_H__
#define __OFSTATEMANAGER_PORTING_H__


/* <auto.start.portingmacro(ALL).define> */
#if OFSTATEMANAGER_CONFIG_PORTING_INCLUDE_STDLIB_HEADERS == 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <memory.h>
#endif

#ifndef OFSTATEMANAGER_MALLOC
    #if defined(GLOBAL_MALLOC)
        #define OFSTATEMANAGER_MALLOC GLOBAL_MALLOC
    #elif OFSTATEMANAGER_CONFIG_PORTING_STDLIB == 1
        #define OFSTATEMANAGER_MALLOC malloc
    #else
        #error The macro OFSTATEMANAGER_MALLOC is required but cannot be defined.
    #endif
#endif

#ifndef OFSTATEMANAGER_FREE
    #if defined(GLOBAL_FREE)
        #define OFSTATEMANAGER_FREE GLOBAL_FREE
    #elif OFSTATEMANAGER_CONFIG_PORTING_STDLIB == 1
        #define OFSTATEMANAGER_FREE free
    #else
        #error The macro OFSTATEMANAGER_FREE is required but cannot be defined.
    #endif
#endif

#ifndef OFSTATEMANAGER_MEMSET
    #if defined(GLOBAL_MEMSET)
        #define OFSTATEMANAGER_MEMSET GLOBAL_MEMSET
    #elif OFSTATEMANAGER_CONFIG_PORTING_STDLIB == 1
        #define OFSTATEMANAGER_MEMSET memset
    #else
        #error The macro OFSTATEMANAGER_MEMSET is required but cannot be defined.
    #endif
#endif

#ifndef OFSTATEMANAGER_MEMCPY
    #if defined(GLOBAL_MEMCPY)
        #define OFSTATEMANAGER_MEMCPY GLOBAL_MEMCPY
    #elif OFSTATEMANAGER_CONFIG_PORTING_STDLIB == 1
        #define OFSTATEMANAGER_MEMCPY memcpy
    #else
        #error The macro OFSTATEMANAGER_MEMCPY is required but cannot be defined.
    #endif
#endif

#ifndef OFSTATEMANAGER_STRNCPY
    #if defined(GLOBAL_STRNCPY)
        #define OFSTATEMANAGER_STRNCPY GLOBAL_STRNCPY
    #elif OFSTATEMANAGER_CONFIG_PORTING_STDLIB == 1
        #define OFSTATEMANAGER_STRNCPY strncpy
    #else
        #error The macro OFSTATEMANAGER_STRNCPY is required but cannot be defined.
    #endif
#endif

#ifndef OFSTATEMANAGER_VSNPRINTF
    #if defined(GLOBAL_VSNPRINTF)
        #define OFSTATEMANAGER_VSNPRINTF GLOBAL_VSNPRINTF
    #elif OFSTATEMANAGER_CONFIG_PORTING_STDLIB == 1
        #define OFSTATEMANAGER_VSNPRINTF vsnprintf
    #else
        #error The macro OFSTATEMANAGER_VSNPRINTF is required but cannot be defined.
    #endif
#endif

#ifndef OFSTATEMANAGER_SNPRINTF
    #if defined(GLOBAL_SNPRINTF)
        #define OFSTATEMANAGER_SNPRINTF GLOBAL_SNPRINTF
    #elif OFSTATEMANAGER_CONFIG_PORTING_STDLIB == 1
        #define OFSTATEMANAGER_SNPRINTF snprintf
    #else
        #error The macro OFSTATEMANAGER_SNPRINTF is required but cannot be defined.
    #endif
#endif

#ifndef OFSTATEMANAGER_STRLEN
    #if defined(GLOBAL_STRLEN)
        #define OFSTATEMANAGER_STRLEN GLOBAL_STRLEN
    #elif OFSTATEMANAGER_CONFIG_PORTING_STDLIB == 1
        #define OFSTATEMANAGER_STRLEN strlen
    #else
        #error The macro OFSTATEMANAGER_STRLEN is required but cannot be defined.
    #endif
#endif

/* <auto.end.portingmacro(ALL).define> */


#endif /* __OFSTATEMANAGER_PORTING_H__ */
/* @} */
