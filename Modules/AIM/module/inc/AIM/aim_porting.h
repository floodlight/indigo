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
 *  /module/inc/AIM/aim_porting.h
 *
 * @file
 * @brief AIM Porting Definitions.
 *
 * @addtogroup aim-porting
 * @{
 *
 *****************************************************************************/
#ifndef __AIM_PORTING_H__
#define __AIM_PORTING_H__


#include <AIM/aim_config.h>


/* <auto.start.portingmacro(ALL).define> */
#if AIM_CONFIG_PORTING_INCLUDE_STDLIB_HEADERS == 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <memory.h>
#endif

#ifndef AIM_MALLOC
    #if defined(GLOBAL_MALLOC)
        #define AIM_MALLOC GLOBAL_MALLOC
    #elif AIM_CONFIG_PORTING_STDLIB == 1
        #define AIM_MALLOC malloc
    #else
        #error The macro AIM_MALLOC is required but cannot be defined.
    #endif
#endif

#ifndef AIM_FREE
    #if defined(GLOBAL_FREE)
        #define AIM_FREE GLOBAL_FREE
    #elif AIM_CONFIG_PORTING_STDLIB == 1
        #define AIM_FREE free
    #else
        #error The macro AIM_FREE is required but cannot be defined.
    #endif
#endif

#ifndef AIM_MEMSET
    #if defined(GLOBAL_MEMSET)
        #define AIM_MEMSET GLOBAL_MEMSET
    #elif AIM_CONFIG_PORTING_STDLIB == 1
        #define AIM_MEMSET memset
    #else
        #error The macro AIM_MEMSET is required but cannot be defined.
    #endif
#endif

#ifndef AIM_MEMCPY
    #if defined(GLOBAL_MEMCPY)
        #define AIM_MEMCPY GLOBAL_MEMCPY
    #elif AIM_CONFIG_PORTING_STDLIB == 1
        #define AIM_MEMCPY memcpy
    #else
        #error The macro AIM_MEMCPY is required but cannot be defined.
    #endif
#endif

#ifndef AIM_STRNCPY
    #if defined(GLOBAL_STRNCPY)
        #define AIM_STRNCPY GLOBAL_STRNCPY
    #elif AIM_CONFIG_PORTING_STDLIB == 1
        #define AIM_STRNCPY strncpy
    #else
        #error The macro AIM_STRNCPY is required but cannot be defined.
    #endif
#endif

#ifndef AIM_STRSTR
    #if defined(GLOBAL_STRSTR)
        #define AIM_STRSTR GLOBAL_STRSTR
    #elif AIM_CONFIG_PORTING_STDLIB == 1
        #define AIM_STRSTR strstr
    #else
        #error The macro AIM_STRSTR is required but cannot be defined.
    #endif
#endif

#ifndef AIM_VSNPRINTF
    #if defined(GLOBAL_VSNPRINTF)
        #define AIM_VSNPRINTF GLOBAL_VSNPRINTF
    #elif AIM_CONFIG_PORTING_STDLIB == 1
        #define AIM_VSNPRINTF vsnprintf
    #else
        #error The macro AIM_VSNPRINTF is required but cannot be defined.
    #endif
#endif

#ifndef AIM_SNPRINTF
    #if defined(GLOBAL_SNPRINTF)
        #define AIM_SNPRINTF GLOBAL_SNPRINTF
    #elif AIM_CONFIG_PORTING_STDLIB == 1
        #define AIM_SNPRINTF snprintf
    #else
        #error The macro AIM_SNPRINTF is required but cannot be defined.
    #endif
#endif

#ifndef AIM_PRINTF
    #if defined(GLOBAL_PRINTF)
        #define AIM_PRINTF GLOBAL_PRINTF
    #elif AIM_CONFIG_PORTING_STDLIB == 1
        #define AIM_PRINTF printf
    #else
        #error The macro AIM_PRINTF is required but cannot be defined.
    #endif
#endif

#ifndef AIM_STRLEN
    #if defined(GLOBAL_STRLEN)
        #define AIM_STRLEN GLOBAL_STRLEN
    #elif AIM_CONFIG_PORTING_STDLIB == 1
        #define AIM_STRLEN strlen
    #else
        #error The macro AIM_STRLEN is required but cannot be defined.
    #endif
#endif

#ifndef AIM_STRCMP
    #if defined(GLOBAL_STRCMP)
        #define AIM_STRCMP GLOBAL_STRCMP
    #elif AIM_CONFIG_PORTING_STDLIB == 1
        #define AIM_STRCMP strcmp
    #else
        #error The macro AIM_STRCMP is required but cannot be defined.
    #endif
#endif

#ifndef AIM_STRCPY
    #if defined(GLOBAL_STRCPY)
        #define AIM_STRCPY GLOBAL_STRCPY
    #elif AIM_CONFIG_PORTING_STDLIB == 1
        #define AIM_STRCPY strcpy
    #else
        #error The macro AIM_STRCPY is required but cannot be defined.
    #endif
#endif

#ifndef AIM_STRCHR
    #if defined(GLOBAL_STRCHR)
        #define AIM_STRCHR GLOBAL_STRCHR
    #elif AIM_CONFIG_PORTING_STDLIB == 1
        #define AIM_STRCHR strchr
    #else
        #error The macro AIM_STRCHR is required but cannot be defined.
    #endif
#endif

#ifndef AIM_STRCAT
    #if defined(GLOBAL_STRCAT)
        #define AIM_STRCAT GLOBAL_STRCAT
    #elif AIM_CONFIG_PORTING_STDLIB == 1
        #define AIM_STRCAT strcat
    #else
        #error The macro AIM_STRCAT is required but cannot be defined.
    #endif
#endif

#ifndef AIM_SSCANF
    #if defined(GLOBAL_SSCANF)
        #define AIM_SSCANF GLOBAL_SSCANF
    #elif AIM_CONFIG_PORTING_STDLIB == 1
        #define AIM_SSCANF sscanf
    #else
        #error The macro AIM_SSCANF is required but cannot be defined.
    #endif
#endif

/* <auto.end.portingmacro(ALL).define> */

#endif /* __AIM_PORTING_H__ */
/*@}*/
