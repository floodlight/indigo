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

typedef enum indigo_error_e {
    INDIGO_ERROR_NONE            = 0,     /**< Success, no error */
    INDIGO_ERROR_PENDING         = 1,     /**< Operation is pending */
    INDIGO_ERROR_RESOURCE        = -1,    /**< Could not allocate space */
    INDIGO_ERROR_PARAM           = -2,    /**< Bad parameter */
    INDIGO_ERROR_VERSION         = -3,    /**< Version not supported */
    INDIGO_ERROR_RANGE           = -4,    /**< Out of range */
    INDIGO_ERROR_COMPAT          = -5,    /**< Incompatible assignment */
    INDIGO_ERROR_PARSE           = -6,    /**< Error in parsing data */
    INDIGO_ERROR_INIT            = -7,    /**< Uninitialized component */
    INDIGO_ERROR_EXISTS          = -8,    /**< Object exists unexpectedly */
    INDIGO_ERROR_NOT_FOUND       = -9,    /**< Object was not found */
    INDIGO_ERROR_NOT_SUPPORTED   = -10,   /**< Operation not supported */
    INDIGO_ERROR_TIME_OUT        = -11,   /**< Operation timed out */
    INDIGO_ERROR_PROTOCOL        = -12,   /**< Protocol error */
    INDIGO_ERROR_CONNECTION      = -13,   /**< Connection error */
    INDIGO_ERROR_NOT_READY       = -14,   /**< Agent not ready */
    INDIGO_ERROR_UNKNOWN         = -15    /**< Unknown error */
} indigo_error_t;

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
