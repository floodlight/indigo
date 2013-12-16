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
 * @brief Port manager module function prototypes
 * @addtogroup indigo-PortManager
 *
 * This defines the API for all functions provided by the Port
 * manager.  This includes the packet output function as well
 * as configuration related functions.
 *
 * @{
 */

#ifndef _INDIGO_PORT_MANAGER_H_
#define _INDIGO_PORT_MANAGER_H_

#include <indigo/error.h>
#include <indigo/types.h>
#include <indigo/fi.h>

#ifdef __cplusplus
extern "C" {
#endif

/* A system (platform) port reference */
#define INDIGO_PORT_NAME_MAX 128
typedef char indigo_port_name_t[INDIGO_PORT_NAME_MAX];

/**
 * Port configuration specified on add port
 */
typedef struct indigo_port_config_s {
    uint32_t disable_on_add; /**< Disable port on add for init sequencing */
} indigo_port_config_t;


/**
 * @brief Handle a features get request
 * @param features The features reply message to be filled out
 *
 * Ownership of the features object is maintained by the caller
 */
extern indigo_error_t indigo_port_features_get(
    of_features_reply_t *features);


/**
 * @brief Handle a port_desc_stats get request
 * @param port_desc_stats_reply The port_desc_stats_reply reply message
 * to be filled out
 *
 * Ownership of the port_desc_stats_reply object is maintained by the caller
 */
extern indigo_error_t indigo_port_desc_stats_get(
    of_port_desc_stats_reply_t *port_desc_stats_reply);


/****************************************************************
 * Configuration interface routines provided by port manager
 ****************************************************************/


/**
 * Associate a system interface to an OpenFlow port on the switch instance
 * @param system_port The platform specific name of the port
 * @param of_port The OpenFlow port number to assign.
 * @param config The configuration structure for the port
 *
 * @returns INDIGO_ERROR_EXISTS if the OpenFlow port number already
 * exists for the switch instance
 * @returns INDIGO_ERROR_NOT_FOUND if the interface name is not understood
 * by the switch instance
 * @returns INDIGO_ERROR_PARAM if unable to support other parameters in the
 * configuration structure such as "disable_on_add".
 */

/* Add a port to the OpenFlow switch */
extern indigo_error_t indigo_port_interface_add(
    indigo_port_name_t port_name,
    of_port_no_t of_port,
    indigo_port_config_t *config);


/**
 * Inform port manager that something about the interface has changed, and
 * a port status / port modified notification needs to be issued.
 * @param port_name The system name of the interface that changed.
 * @returns INDIGO_ERROR_NOT_FOUND if the interface name is not understood
 * by the switch instance
 */

extern indigo_error_t indigo_port_interface_modified(
    indigo_port_name_t port_name);

/**
 * De-associate an interface from an OpenFlow port on the switch instance
 * @param port_name The system name of the port to remove from the
 * switch instance configuration.
 * @returns INDIGO_ERROR_NOT_FOUND if the interface name is not understood
 * by the switch instance
 */

extern indigo_error_t indigo_port_interface_remove(indigo_port_name_t port_name);

/**
 * Port information structure.
 */
typedef struct indigo_port_info_s {
    struct indigo_port_info_s* next;

    indigo_port_name_t port_name;
    of_port_no_t of_port;

} indigo_port_info_t;

/**
 * @brief Get a list of all current ports.
 * @param [out] list Receives the port list.
 */
indigo_error_t indigo_port_interface_list(indigo_port_info_t** list);

/**
 * @brief Destroy a list returned by indigo_port_interface_list()
 * @param list The list.
 */
void indigo_port_interface_list_destroy(indigo_port_info_t* list);


/****************************************************************
 * Functions provided for core state manager
 ****************************************************************/

/**
 * @brief Process an OF port modification request
 * @param port_mod The LOXI modification message
 * @return Return code from operation
 *
 * Ownership of the port_mod LOXI object is maintained by the
 * caller (OF state manager).
 */

extern indigo_error_t indigo_port_modify(of_port_mod_t *port_mod);

/**
 * @brief Process an OF port status request
 * @param port_stats_request The LOXI request message
 * @param [out] port_stats_reply The LOXI reply message
 * @return Return code from operation
 *
 * Ownership of the port_stats_request LOXI object is maintained by the
 * caller (OF state manager).
 */

extern indigo_error_t indigo_port_stats_get(
    of_port_stats_request_t *port_stats_request,
    of_port_stats_reply_t **port_stats_reply);

/**
 * @brief Process an extended port stats request
 * @param port_no The OpenFlow port number
 * @param [out] port_stats Statistics for the port
 *
 * Only supported counters need to be set. The rest will default to -1.
 *
 * If the port number is invalid or no stats are available, don't set any
 * of the counters.
 */

void indigo_port_extended_stats_get(
    of_port_no_t port_no,
    indigo_fi_port_stats_t *port_stats);

/**
 * @brief Process an OF queue config request
 * @param queue_config_request The LOXI request message
 * @param [out] queue_config_reply The LOXI reply message
 * @return Return code from operation
 *
 * Ownership of the queue_config_request LOXI object is maintained by the
 * caller (OF state manager).
 */

extern indigo_error_t indigo_port_queue_config_get(
    of_queue_get_config_request_t *queue_config_request,
    of_queue_get_config_reply_t **queue_config_reply);


/**
 * @brief Process an OF queue stats request
 * @param queue_stats_request The LOXI request message
 * @param [out] queue_stats_reply The LOXI reply message
 * @return Return code from operation
 *
 * Ownership of the queue_stats_request LOXI object is maintained by the
 * caller (OF state manager).
 */

extern indigo_error_t indigo_port_queue_stats_get(
    of_queue_stats_request_t *queue_stats_request,
    of_queue_stats_reply_t **queue_stats_reply);


/**
 * @brief Experimenter (vendor) extension
 * @param experimenter The message from the controller
 * @param cxn_id Connection ID on which the message arrived
 *
 * Ownership of the experimenter LOXI object is maintained by the
 * caller (OF state manager).
 */

extern indigo_error_t indigo_port_experimenter(
    of_experimenter_t *experimenter,
    indigo_cxn_id_t cxn_id);

/****************************************************************
 * Forwarding part of port interface
 ****************************************************************/

/**
 * Send a data plane packet out a port
 *
 * @param egress_port The OpenFlow port on which the packet should be sent
 * @param data Pointer to a monolithic buffer holding the packet data
 * @param length Length of the packet in bytes
 *
 * Provided by port manager, required by forwarding
 *
 * Ownership of the buffer is maintained by the caller (forwarding).
 *
 * Most implementations will have a more direct connection between the port
 * manager and forwarding modules, and will not implement this interface.
 */

extern indigo_error_t indigo_port_packet_emit(
    of_port_no_t egress_port,
    unsigned queue_id,
    uint8_t *data,
    unsigned length);

/**
 * Send a data plane packet out all ports
 *
 * @param skip_egress_port Do not send to this port if a valid port number
 * @param data Pointer to a monolithic buffer holding the packet data
 * @param length Length of the packet in bytes
 *
 * Provided by port manager, required by forwarding
 *
 * Ownership of the buffer is maintained by the caller (forwarding).
 *
 * Most implementations will have a more direct connection between the port
 * manager and forwarding modules, and will not implement this interface.
 */

extern indigo_error_t indigo_port_packet_emit_all(
    of_port_no_t skip_egress_port,
    uint8_t *data,
    unsigned length);

/**
 * Send a data plane packet out to a group of ports
 *
 * @param group_id The group id to send to (see below)
 * @param ingress_port The ingress port
 * @param data Pointer to a monolithic buffer holding the packet data
 * @param length Length of the packet in bytes
 *
 * Provided by port manager, required by forwarding
 *
 * Ownership of the buffer is maintained by the caller (forwarding).
 *
 * Most implementations will have a more direct connection between the port
 * manager and forwarding modules, and will not implement this interface.
 */

extern indigo_error_t indigo_port_packet_emit_group(
    uint32_t group_id,
    of_port_no_t ingress_port_num,
    uint8_t *data,
    unsigned len);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* _INDIGO_PORT_MANAGER_H_ */
/* @} */
