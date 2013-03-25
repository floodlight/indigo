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
 * @brief loci Porting Macros.
 *
 * @addtogroup loci_porting
 * @{
 *
 *****************************************************************************/
#ifndef __LOCI_PORTING_H__
#define __LOCI_PORTING_H__


/* <auto.start.portingmacro(ALL).define> */
#if LOCI_CONFIG_PORTING_INCLUDE_STDLIB_HEADERS == 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <memory.h>
#endif

#ifndef LOCI_MALLOC
    #if defined(GLOBAL_MALLOC)
        #define LOCI_MALLOC GLOBAL_MALLOC
    #elif LOCI_CONFIG_PORTING_STDLIB == 1
        #define LOCI_MALLOC malloc
    #else
        #error The macro LOCI_MALLOC is required but cannot be defined.
    #endif
#endif

#ifndef LOCI_FREE
    #if defined(GLOBAL_FREE)
        #define LOCI_FREE GLOBAL_FREE
    #elif LOCI_CONFIG_PORTING_STDLIB == 1
        #define LOCI_FREE free
    #else
        #error The macro LOCI_FREE is required but cannot be defined.
    #endif
#endif

#ifndef LOCI_MEMSET
    #if defined(GLOBAL_MEMSET)
        #define LOCI_MEMSET GLOBAL_MEMSET
    #elif LOCI_CONFIG_PORTING_STDLIB == 1
        #define LOCI_MEMSET memset
    #else
        #error The macro LOCI_MEMSET is required but cannot be defined.
    #endif
#endif

#ifndef LOCI_MEMCPY
    #if defined(GLOBAL_MEMCPY)
        #define LOCI_MEMCPY GLOBAL_MEMCPY
    #elif LOCI_CONFIG_PORTING_STDLIB == 1
        #define LOCI_MEMCPY memcpy
    #else
        #error The macro LOCI_MEMCPY is required but cannot be defined.
    #endif
#endif

#ifndef LOCI_STRNCPY
    #if defined(GLOBAL_STRNCPY)
        #define LOCI_STRNCPY GLOBAL_STRNCPY
    #elif LOCI_CONFIG_PORTING_STDLIB == 1
        #define LOCI_STRNCPY strncpy
    #else
        #error The macro LOCI_STRNCPY is required but cannot be defined.
    #endif
#endif

#ifndef LOCI_VSNPRINTF
    #if defined(GLOBAL_VSNPRINTF)
        #define LOCI_VSNPRINTF GLOBAL_VSNPRINTF
    #elif LOCI_CONFIG_PORTING_STDLIB == 1
        #define LOCI_VSNPRINTF vsnprintf
    #else
        #error The macro LOCI_VSNPRINTF is required but cannot be defined.
    #endif
#endif

#ifndef LOCI_SNPRINTF
    #if defined(GLOBAL_SNPRINTF)
        #define LOCI_SNPRINTF GLOBAL_SNPRINTF
    #elif LOCI_CONFIG_PORTING_STDLIB == 1
        #define LOCI_SNPRINTF snprintf
    #else
        #error The macro LOCI_SNPRINTF is required but cannot be defined.
    #endif
#endif

#ifndef LOCI_STRLEN
    #if defined(GLOBAL_STRLEN)
        #define LOCI_STRLEN GLOBAL_STRLEN
    #elif LOCI_CONFIG_PORTING_STDLIB == 1
        #define LOCI_STRLEN strlen
    #else
        #error The macro LOCI_STRLEN is required but cannot be defined.
    #endif
#endif

/* <auto.end.portingmacro(ALL).define> */


#endif /* __LOCI_PORTING_H__ */
/* @} */
