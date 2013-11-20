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
 *
 * @addtogroup OFConnectionManager
 * @{
 *
 * This file defines the implementation-specific interfaces exposed by
 * OFConnectionManager. Most functions provided by this module are defined
 * in the Indigo @ref indigo-OFConnectionManager headers.
 */


#ifndef __OFCONNECTIONMANAGER_H__
#define __OFCONNECTIONMANAGER_H__

#include "ofconnectionmanager_config.h"

#include <indigo/error.h>

#include <OFConnectionManager/ofconnectionmanager_config.h>

#include <indigo/of_connection_manager.h>
#include <indigo/of_state_manager.h>
#include <SocketManager/socketmanager.h>

/**
 * Global (read-only) counter for connection related errors.
 */

extern uint32_t ind_cxn_internal_errors;

/**
 * Configuration structure for the configuration manager
 * @param flags Currently ignored
 */

typedef struct ind_cxn_config_s {
    uint32_t flags;
} ind_cxn_config_t;



/****************************************************************
 *
 * The Connection Manager API
 *
 ****************************************************************/


/**
 * Configure the connection manager
 * @param config The connection manager specific config data
 * @returns An error code
 *
 */

extern indigo_error_t ind_cxn_init(ind_cxn_config_t *config);

/**
 * Enable set/get for the connection manager
 */

extern indigo_error_t ind_cxn_enable_set(int enable);
extern indigo_error_t ind_cxn_enable_get(int *enable);

/**
 * Tear down and clean up the connection manager
 */
extern indigo_error_t ind_cxn_finish(void);


/**
 * Track objects for outstanding op count
 *
 * @param cxn The connection requesting the op
 * @param obj The object associated with the request
 *
 * This function is exposed to allow other agents to register duplicates
 * of messages that are generated to process complex operations.
 * It is mostly used for tracking objects as required for barrier processing.
 */

extern indigo_error_t
ind_cxn_message_track_setup(indigo_cxn_id_t cxn_id, of_object_t *obj);

/**
 * Set the pvs (I/O mgmt structure) to the given value
 *
 * @param cxn_id The Connection ID to set.
 * @param pvs Pointer to the I/O mgmt structure
 *
 * cxn_id may be -1 which will apply to all active connections.  Copies the
 * pointer to the pvs object; not a deep copy.
 */
extern indigo_error_t
ind_cxn_message_trace(indigo_cxn_id_t cxn_id, aim_pvs_t* pvs);

/**
 * Value to indicate to cxn_reset to reset all active connections
 */
#define IND_CXN_RESET_ALL ((indigo_cxn_id_t)-1)

/**
 * Reset an existing connection
 * @param cxn_id The connection ID to reset
 *
 * If cxn_id is invalid (< 0), then all active connections are reset
 */
extern void
ind_cxn_reset(indigo_cxn_id_t cxn_id);


#endif /* __OFCONNECTIONMANAGER_H__ */
/** @} */
