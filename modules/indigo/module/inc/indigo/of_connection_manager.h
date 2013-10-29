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
 * @brief OpenFlow connection manager module function prototypes
 * @addtogroup indigo-OFConnectionManager
 *
 * This defines the API for all functions provided by the OpenFlow
 * connection manager.
 *
 * @{
 */

#ifndef _INDIGO_OF_CONNECTION_MANAGER_H_
#define _INDIGO_OF_CONNECTION_MANAGER_H_

#include <indigo/error.h>
#include <indigo/types.h>


/****************************************************************
 *
 * Basic controller instance definitions
 *
 ****************************************************************/

/**
 * Special connection instance values: invalid and unspecified
 *
 * For synchronous responses, a client of the connection manager is
 * expected to use the connection ID associated with the original
 * request message.
 *
 * For asynchronous messages, a client of the connection manager may
 * use the value "UNSPECIFIED" to indicate to the connection manager
 * that it should use its current HA algorithm to determine the proper
 * recipient(s) of the message.
 *
 * Note that UNSPECIFIED is a specific invalid value.  So implementers
 * should note that if UNSPECIFIED is acceptable for a function, it must
 * be checked before "invalid" is checked.
 */

#define INDIGO_CXN_ID_UNSPECIFIED ((indigo_cxn_id_t)-1)

#define INDIGO_CXN_INVALID(_id)  ((_id) < 0)
#define INDIGO_CXN_VALID(_id)  ((_id) >= 0)
#define INDIGO_CXN_UNSPECIFIED(_id)  ((_id) == INDIGO_CXN_ID_UNSPECIFIED)


/****************************************************************
 *
 * Controller connection definitions
 *
 ****************************************************************/

/**
 * Type of protocol to use for connection
 *
 * INDIGO_CXN_PROTO_INVALID A marker used to indicate an undefined protocol
 * INDIGO_CXN_PROTO_TCP_OVER_IPV4 Use TCP over IPv4 for the connection
 */

typedef enum indigo_cxn_protocol_e {
    INDIGO_CXN_PROTO_INVALID            = -1,
    INDIGO_CXN_PROTO_TCP_OVER_IPV4      = 0
} indigo_cxn_protocol_t;

/**
 * Parameters for protocol, depending on type.
 *
 * indigo_cxn_params_header_t holds the common part (just the
 * protocol identifier for demultiplexing the union below).
 *
 * To add a type, make sure it starts with a indigo_cxn_protocol_t value
 * initially and then add the parameters needed for that protocol.
 */

typedef struct indigo_cxn_params_header_s {
    indigo_cxn_protocol_t protocol;
} indigo_cxn_params_header_t;

/**
 * TCP over IPv4 parameters
 *     controller_ip IPv4 address of controller
 *     controller_port Port number to use for connection
 */
#define INDIGO_CXN_IPV4_STRING_LEN 32
typedef struct indigo_cxn_params_tcp_over_ipv4_s {
    indigo_cxn_protocol_t protocol;
    char controller_ip[INDIGO_CXN_IPV4_STRING_LEN];
    uint16_t controller_port;
} indigo_cxn_params_tcp_over_ipv4_t;

/**
 * The super class for connection parameters
 */

typedef union indigo_cxn_protocol_params_u {
    indigo_cxn_params_header_t header;
    indigo_cxn_params_tcp_over_ipv4_t tcp_over_ipv4;
} indigo_cxn_protocol_params_t;

/**
 * Structure for connection configuration
 * @param version The version for the connection (negotiation TBD)
 * @param flags OF specific flags sent in switch config structure
 * @param miss_send_len OF specific value sent in switch config structure
 * @param cxn_priority TBD but probably the priority of connection attempts
 * when connecting serially.
 * @param local Boolean indicates that this is a local connection; see below
 * @param listen This socket listens on a port and accepts new connections
 * @param periodic_echo_ms For non-local connections, period of echo requests;
 * set to 0 to disable.
 * @param reset_echo_count For non-local connections, if this number of
 * consecutive echo replies is not received, the connection is closed.
 *
 * For listen connections, the parameters of the original connection
 * instance are copied to the new connections.
 *
 * See the switch_config structure in the OpenFlow protocol specification
 * for information on flags and miss_send_len.
 *
 * Also, for flags, see OF_FRAG and OF_INVALID_TTL in loci_base.h
 *
 * Local connections are intended to represent UI and other
 * management connections, but handled thru the same machinery. Details
 * are implementation specific, but typically:
 *
 * (1) It listens on its socket (listen is set)
 * (2) It does not require a handshake
 * (3) Async messages such as packet-in or port-status are not sent
 * (4) It can exist simultaneously with remote connections
 * (5) It may only be open for one transaction at a time
 *
 * Remote connections are usually active connect (non-listen) controller
 * connections that require a handshake to continue processing.  Echo
 * requests may be done on these connections as a keepalive.
 */

typedef struct indigo_cxn_config_params_s {
    of_version_t version;
    int cxn_priority;
    int local;
    int listen;
    uint32_t periodic_echo_ms;
    uint32_t reset_echo_count;
} indigo_cxn_config_params_t;

/****************************************************************
 *
 * Connection state structures
 *
 ****************************************************************/

/**
 * Connection state values
 *    INDIGO_CXN_S_DISCONNECTED  Not connected
 *    INDIGO_CXN_S_CONNECTING    TCP Connection established
 *    INDIGO_CXN_S_HANDSHAKE_COMPLETE  OpenFlow handshake (features) complete
 *    INDIGO_CXN_S_CLOSING       Connection broken, cleaning up
 *                                 outstanding operations
 */

typedef enum indigo_cxn_state_e {
    INDIGO_CXN_S_DISCONNECTED           = 0,
    INDIGO_CXN_S_CONNECTING             = 1,
    INDIGO_CXN_S_HANDSHAKE_COMPLETE     = 2,
    INDIGO_CXN_S_CLOSING                = 3,
    INDIGO_CXN_S_COUNT                  = 4
} indigo_cxn_state_t;

/**
 * Connection roles
 *   Only applicable if the instance is connected.
 *   Needs doc.
 */

typedef enum indigo_cxn_role_e {
    INDIGO_CXN_R_UNKNOWN                = 0,
    INDIGO_CXN_R_MASTER                 = 1,
    INDIGO_CXN_R_SLAVE                  = 2,
    INDIGO_CXN_R_EQUAL                  = 3,
    INDIGO_CXN_R_COUNT                  = 4
} indigo_cxn_role_t;

/**
 * Status of a connection instance.
 *    state The current connection state (see indigo_cxn_state_t)
 *    role The HA role, if applicable; only valid if state is CONNECTED
 *    negotiated_version If connected, the version used by the connection
 *    disconnect_count Number of times controller has disconnected from switch
 *    forced_disconnect_count Number of times the switch disconnected
 *    bytes_in Number of bytes read in since last connect
 *    bytes_out Number of bytes written in since last connect
 *    messages_in Number of messages received since last connect
 *    messages_out Number of messages sent to controller since last connect
 */

typedef struct indigo_cxn_status_s {
    /* Current status of connection */
    indigo_cxn_state_t state;
    indigo_cxn_role_t role;
    of_version_t negotiated_version;
    uint32_t disconnect_count;
    uint32_t forced_disconnect_count;
    uint64_t bytes_in;
    uint64_t bytes_out;
    uint64_t messages_in;
    uint64_t messages_out;
    uint64_t packet_in_drop;
    uint64_t flow_removed_drop;
} indigo_cxn_status_t;

/****************************************************************
 *
 * Prototypes of routines provided by connection manager
 *
 ****************************************************************/

/**
 * Add a controller connection instance
 * @param params Parameters specific to the connection protocol; see above
 * @param cxn_id (out) Descriptor (small integer) returned identifying the
 * connection instance
 * @param priority Used for serial connection attempts, highest first
 * @param config_params Configuration parameters; see above
 */

extern indigo_error_t indigo_cxn_connection_add(
    indigo_cxn_protocol_params_t *protocol_params,
    indigo_cxn_config_params_t *config_params,
    indigo_cxn_id_t *id);

/**
 * Remove the connection indexed by cxn_id
 * @param cxn_id The connection descriptor returned by connection add
 */

extern indigo_error_t indigo_cxn_connection_remove(indigo_cxn_id_t cxn_id);

/**
 * Return the config parameters of a specific connection
 * @param cxn_id The descriptor of the connection to look up
 * @param config (out) Pointer to structure to be filled out with
 *    config parameters
 */

extern indigo_error_t indigo_cxn_connection_config_get(
    indigo_cxn_id_t cxn_id,
    indigo_cxn_config_params_t *config);

/**
 * Return the status of a specific connection
 * @param cxn_id The descriptor of the connection to look up
 * @param status (out) Pointer to structure to be filled out with status
 */

extern indigo_error_t indigo_cxn_connection_status_get(
    indigo_cxn_id_t cxn_id,
    indigo_cxn_status_t *status);

/**
 * Connection status change handler callback prototype
 * @param cxn_id The descriptor of the connection that has changed
 * @param state The new state of the connection
 * @param cookie Passed in on register
 *
 * For complete information, do a status_get on the connection
 */

typedef void (*indigo_cxn_status_change_f)(
    indigo_cxn_id_t              cxn_id,
    indigo_cxn_protocol_params_t *cxn_proto_params,
    indigo_cxn_state_t           state,
    void                         *cookie);

/**
 * Connection status change handler registration function
 * @param handler The handler to register
 * @param cookie Anonymous data passed back to handler
 *
 * Registered functions are called when any connection's status changes
 */
extern indigo_error_t indigo_cxn_status_change_register(
    indigo_cxn_status_change_f handler,
    void *cookie);

/**
 * Unregister a connection status change handler
 * @param handler The handler to unregister
 * @param cookie Cookie associated with handler
 *
 * The cookie is part of the lookup key
 */
extern indigo_error_t indigo_cxn_status_change_unregister(
    indigo_cxn_status_change_f handler, void *cookie);

extern void indigo_cxn_outstanding_op_incr(indigo_cxn_id_t cxn_id, int incr);

/****************************************************************
 *
 * The OF Connection to OF State Manager Interface
 *
 ****************************************************************/

/**
 * Send an OpenFlow message to a controller connection
 *
 * @param cxn_id The id of the connection to which the message is to be sent
 * @param obj The LOCI object representing the message
 *
 * Provided by connection manager, required by state manager
 *
 * Connection Manager takes responsibility for obj even if an error
 * is returned.  This means that if you send the object to more than
 * one connection you must first duplicate it.
 */

extern indigo_error_t indigo_cxn_send_controller_message(
    indigo_cxn_id_t cxn_id,
    of_object_t *obj);

/**
 * Send an error message to a controller connection
 * @param version The version to use for the msg
 * @param cxn_id Controller to receive msg
 * @param xid The transaction ID to use for the message
 * @param type Type of error message
 * @param code Code of error message for this type
 * @param octets If not NULL use this for the data
 *
 * If version is invalid, uses the connection's configured version
 */
extern indigo_error_t
indigo_cxn_send_error_msg(of_version_t version, indigo_cxn_id_t cxn_id,
                          uint32_t xid, uint16_t type, uint16_t code,
                          of_octets_t *octets);


/**
 * Connection information structure.
 */
typedef struct indigo_cxn_info_s {
    struct indigo_cxn_info_s* next;

    /** The connection id for this connection . */
    indigo_cxn_id_t cxn_id;

    /** Connection Status */
    indigo_cxn_status_t cxn_status;

    /** The protocol parameters for this connection. */
    indigo_cxn_protocol_params_t cxn_proto_params;

    /** The configuration parameters for this connection. */
    indigo_cxn_config_params_t cxn_config_params;

} indigo_cxn_info_t;

/**
 * @brief Get a list of all current connections.
 * @param [out] Receives the connection list.
 */
extern indigo_error_t indigo_cxn_list(indigo_cxn_info_t** list);

/**
 * @brief Destroy a list returned by indigo_cxn_list()
 * @param list The list.
 */
void indigo_cxn_list_destroy(indigo_cxn_info_t* list);

/**
 * @brief Get OpenFlow version of the controller connection for async messages.
 * @param [out] of_version OpenFlow version 
 */
extern indigo_error_t
indigo_cxn_get_async_version(of_version_t* of_version);

#endif /* _INDIGO_OF_CONNECTION_MANAGER_H_ */
/* @} */
