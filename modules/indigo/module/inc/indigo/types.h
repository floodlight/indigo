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

/**
 * @file
 * @brief Defines the basic indigo and OpenFlow types
 *
 * Normally LOCI will be included for Indigo implementations.  In some
 * cases, it is useful to assume no LOCI; for this, define NO_LOCI_TYPES.
 * The result is that a few basic types are defined allowing compilation
 * of the Indigo headers.
 */

#ifndef _INDIGO_TYPES_H_
#define _INDIGO_TYPES_H_

#include <inttypes.h>
#include <stdbool.h>

/**
 * @brief Generic cookie type
 *
 * Cookies are generically defined to a length specific type
 * to avoid problems such as carrying pointers across different
 * address spaces where the pointer type may change.
 *
 * Note that you may get warnings if converting these cookies to
 * pointers when pointers are less than 8 bytes.
 *
 * Important:  Cookies must always be big enough to hold a pointer.
 */

typedef uint64_t indigo_cookie_t;

/**
 * @brief Null cookie definition
 */

#define INDIGO_COOKIE_NULL ((indigo_cookie_t)0)

/**
 * @brief Format for cookie in printf style statements
 */

#define INDIGO_COOKIE_PRINTF_FORMAT "0x%" PRIx64
#define INDIGO_FLOW_ID_PRINTF_FORMAT "0x%" PRIx64

/**
 * @brief Arguments for cookie in printf style statements
 */

#define INDIGO_COOKIE_PRINTF_ARG(cookie) (cookie)
#define INDIGO_FLOW_ID_PRINTF_ARG(flow_id) (flow_id)

/**
 * @brief Convert a cookie to a pointer
 */

#define INDIGO_COOKIE_TO_POINTER(cookie) ((void *)((intptr_t)(cookie)))

/**
 * @brief Convert a pointer to a cookie
 */

#define INDIGO_POINTER_TO_COOKIE(pointer)       \
    ((indigo_cookie_t)((intptr_t)(pointer)))

/**
 * Connection instances are identified with small integers
 * like file and socket descriptors.  This value is returned
 * by the "indigo_cxn_connection_add" routine.
 */

typedef int indigo_cxn_id_t;


/* Indexing type for a flow */
typedef indigo_cookie_t indigo_flow_id_t;

/* Flow IDs must be non-zero; 0 is used to mark empty entries */
#define INDIGO_FLOW_ID_INVALID ((indigo_flow_id_t)0)

/* Flow IDs must be non-zero; 0 is used to mark empty entries */
#define INDIGO_FLOW_ID_IS_INVALID(flow_id) ((flow_id) == 0)


/*
 * Currently in transition where some of these types will be defined.
 * The following can be defined to define some of these values internal to
 * indigo
 */

#if defined(NO_LOCI_TYPES)

/**
 * OpenFlow port number
 */

typedef uint32_t of_port_no_t;

/**
 * Enumeration of OpenFlow versions
 *
 * The wire protocol numbers are used for values of the corresponding
 * version identifiers.
 */

typedef enum of_version_e {
    OF_VERSION_UNKNOWN = 0,
    OF_VERSION_1_0 = 1,
    OF_VERSION_1_1 = 2,
    OF_VERSION_1_2 = 3,
    OF_VERSION_1_3 = 4
} of_version_t;

#define OF_VERSION_NAMES "Unknown ",        \
        "Version 1.0",                      \
        "Version 1.1",                      \
        "Version 1.2",                      \
        "Version 1.3"

/* To allow compiling of interface types */
typedef struct of_object_s of_object_t;

#else

#include <loci/loci.h>

#endif

/* These are not currently defined in loci */

/**
 * OpenFlow datapath ID
 */

typedef uint64_t of_dpid_t;

#endif /* _INDIGO_TYPES_H_ */
