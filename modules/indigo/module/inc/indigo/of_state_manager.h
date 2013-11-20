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
 * @brief OpenFlow state manager module function prototypes
 * @addtogroup indigo-OFStateManager
 *
 * This defines the API for all functions provided by the OpenFlow
 * state manager.  This includes fi_ and configuration interface
 * functions.
 *
 * @{
 */

#ifndef _INDIGO_OF_STATE_MANAGER_H_
#define _INDIGO_OF_STATE_MANAGER_H_

#include <indigo/of_connection_manager.h>
#include <indigo/forwarding.h>
#include <loci/loci.h>
#include <indigo/fi.h>

/****************************************************************
 * Remote disconnect modes (formerly fail open, closed, etc).
 ****************************************************************/

/**
 * Representations of fail (disconnected) modes.  Determines what the
 * switch should do on the loss of all remote connections.
 *
 * STICKY:      Keep flowtable, stop processing expires
 * CLOSED:      Keep flowtable, but continue expires
 * DISABLED:    Clear flowtable
 * LOCKDOWN:    Clear flowtable, disable ports
 * LOCAL:       Enable local controller
 */

typedef enum indigo_core_disconnected_e {
    INDIGO_CORE_DISCONNECTED_MODE_STICKY     = 0,
    INDIGO_CORE_DISCONNECTED_MODE_CLOSED     = 1,
    INDIGO_CORE_DISCONNECTED_MODE_DISABLED   = 2,
    INDIGO_CORE_DISCONNECTED_MODE_LOCKDOWN   = 3,
    INDIGO_CORE_DISCONNECTED_MODE_LOCAL      = 4,
    IND_CORE_DISCONNECTED_MODE_COUNT         = 5   /* Last entry */
} indigo_core_disconnected_mode_t;

/****************************************************************
 * Forwarding Interface functions provided by the state manager
 ****************************************************************/

/**
 * Handle a packet in from the forwarding module
 * @param packet_in Pointer to the packet in object
 *
 * The state manager takes responsibility for the object
 */

extern indigo_error_t indigo_core_packet_in(of_packet_in_t *packet_in);


/****************************************************************
 * Controller message handling by the state manager
 ****************************************************************/

/**
 * Handle an OpenFlow message from a controller connection
 *
 * @param cxn The handle of the connection on which the message was received
 * @param obj The LOCI object representing the message
 *
 * Provided by state manager, required by connection manager
 *
 * State Manager takes responsibility for the object
 */

extern void indigo_core_receive_controller_message(
    indigo_cxn_id_t cxn,
    of_object_t *obj);


/****************************************************************
 * Configuration Interface functions provided by the state manager
 ****************************************************************/

/**
 * Set the datapath ID for the switch instance
 * @param dpid The datapath ID
 * @param returns indigo_error_t
 */

extern indigo_error_t indigo_core_dpid_set(of_dpid_t dpid);

/**
 * Get the datapath ID for the switch instance
 * @param dpid Pointer to where to store the DPID
 * @param returns indigo_error_t
 */

extern indigo_error_t indigo_core_dpid_get(of_dpid_t *dpid);

/****************************************************************
 * Asynchronous port event notification call
 ****************************************************************/

/**
 * @brief Notify state manager of port status change
 * @param port_status A LOXI message describing the change
 * in the port status
 *
 * The receiver becomes the owner of the port_status object.
 */
extern void indigo_core_port_status_update(of_port_status_t *port_status);


/****************************************************************
 * Asynchronous forwarding flow removed event notification call
 *
 ****************************************************************/

/**
 * @brief Notify state manager that a flow has been removed
 * @param reason The reason the flow was removed.  See fi.h.
 * @param stats A stats structure identifying the flow and related info
 *
 * This call is made from forwarding to the state manager to indicate
 * that a flow has been removed for some reason.
 *
 * Not all implementations may support this.  It is provided for
 * those which may do all flow expiration processing in the
 * forwarding module, and for those which may evict flows due
 * to resource or other constraints.
 *
 * It is not recommended that this call be made if a flow was removed because
 * of a call from the state manager to indigo_fwd_flow_delete.
 */

extern void indigo_core_flow_removed(
    indigo_fi_flow_removed_t reason,
    indigo_fi_flow_stats_t *stats);

/****************************************************************
 * Asynchronous connection manager notification, disconnection mode
 ****************************************************************/

/**
 * Set/get the disconnected mode
 */
extern indigo_error_t
indigo_core_disconnected_mode_set(indigo_core_disconnected_mode_t mode);

extern indigo_error_t
indigo_core_disconnected_mode_get(indigo_core_disconnected_mode_t *mode);

/**
 * @brief Notify state manager that the remote connection count has changed
 * @param new_count The new connection count
 *
 * This call is made from the connection manager to the state manager
 * to indicate that the number of connections to controllers has
 * changed.  This is intended to provide the state to core in order to
 * invoke the necessary changes to implement the configured disconnect mode.
 */

extern void indigo_core_connection_count_notify(
    int new_count);


/**
 * @brief Returns state manager statistics.
 * @param total_flows Current number of flows.
 * @param flow_mods Number of flow mod messages.
 * @param packet_ins Number of packet in messages.
 * @param packet_outs Number of packet out messages.
 *
 * Returns the number of current flows, flow mods, packet ins, and packet outs.
 * The last three quantities are cumulative as of the last time this function
 * was called.
 */

extern void
indigo_core_stats_get(uint32_t *total_flows,
                      uint32_t *flow_mods,
                      uint32_t *packet_ins,
                      uint32_t *packet_outs);

#endif /* _INDIGO_OF_STATE_MANAGER_H_ */
/** @} */
