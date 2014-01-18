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
 * @brief Generic Indigo Error Codes
 */

#ifndef _INDIGO_ERROR_H_
#define _INDIGO_ERROR_H_

#define INDIGO_ERRORS \
    ERROR(NONE,             0, "Success") \
    ERROR(PENDING,          1, "Operation is pending") \
    ERROR(RESOURCE,        -1, "Could not allocate space") \
    ERROR(PARAM,           -2, "Bad parameter") \
    ERROR(VERSION,         -3, "Version not supported") \
    ERROR(RANGE,           -4, "Out of range") \
    ERROR(COMPAT,          -5, "Incompatible assignment") \
    ERROR(PARSE,           -6, "Error in parsing data") \
    ERROR(INIT,            -7, "Uninitialized component") \
    ERROR(EXISTS,          -8, "Object exists unexpectedly") \
    ERROR(NOT_FOUND,       -9, "Object was not found") \
    ERROR(NOT_SUPPORTED,  -10, "Operation not supported") \
    ERROR(TIME_OUT,       -11, "Operation timed out") \
    ERROR(PROTOCOL,       -12, "Protocol error") \
    ERROR(CONNECTION,     -13, "Connection error") \
    ERROR(NOT_READY,      -14, "Agent not ready") \
    ERROR(UNKNOWN,        -15, "Unknown error") \
    ERROR(BAD_MATCH,      -16, "Bad match") \
    ERROR(BAD_INSTRUCTION, -17, "Bad instruction") \
    ERROR(BAD_ACTION,     -18, "Bad action") \
    ERROR(BAD_TABLE_ID,   -19, "Bad table id") \
    ERROR(TABLE_FULL,     -20, "Table full") \

typedef enum indigo_error_e {
#define ERROR(name, value, description) INDIGO_ERROR_##name = value,
    INDIGO_ERRORS
#undef ERROR
} indigo_error_t;

/**
 * Translate an error code to a description string
 */
const char *indigo_strerror(indigo_error_t code);

/**
 * Error code test macros.
 *
 * @note PENDING is not considered an error for these checks.  You
 * must explicitly check for pending if it matters to your logic.
 */

/**
 * @brief Check return code for success
 */
#define INDIGO_SUCCESS(x)  ((x) >= INDIGO_ERROR_NONE)

/**
 * @brief Check return code for failure
 */
#define INDIGO_FAILURE(x)  ((x) < INDIGO_ERROR_NONE)

#endif /* _INDIGO_ERROR_H_ */
