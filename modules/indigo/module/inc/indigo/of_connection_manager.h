/****************************************************************
 *
 *        Copyright 2013-2015,2017-2020, Arista Networks, Inc.
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

#include <dependmodules.x>


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

#define INDIGO_CONTROLLER_INVALID(_id) ((_id) < 0)
#define INDIGO_CONTROLLER_VALID(_id)  ((_id) >= 0)

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
 * INDIGO_CXN_PROTO_TCP_OVER_IPV6 Use TCP over IPv6 for the connection
 * INDIGO_CXN_PROTO_UNIX Use Unix domain socket for the connection
 */

typedef enum indigo_cxn_protocol_e {
    INDIGO_CXN_PROTO_INVALID            = -1,
    INDIGO_CXN_PROTO_TCP_OVER_IPV4      = 0,
    INDIGO_CXN_PROTO_TCP_OVER_IPV6      = 1,
#ifdef DEPENDMODULE_INCLUDE_OFCONNECTIONMANAGER2
    INDIGO_CXN_PROTO_UNIX               = 2,
    INDIGO_CXN_PROTO_TLS_OVER_IPV4      = 3,
    INDIGO_CXN_PROTO_TLS_OVER_IPV6      = 4,
#endif /* DEPENDMODULE_INCLUDE_OFCONNECTIONMANAGER2 */
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
 * TCP over IPv6 parameters
 *     controller_ip IPv6 address of controller
 *     controller_port Port number to use for connection
 */
#define INDIGO_CXN_IPV6_STRING_LEN 64
typedef struct indigo_cxn_params_tcp_over_ipv6_s {
    indigo_cxn_protocol_t protocol;
    char controller_ip[INDIGO_CXN_IPV6_STRING_LEN];
    uint16_t controller_port;
} indigo_cxn_params_tcp_over_ipv6_t;

#ifdef DEPENDMODULE_INCLUDE_OFCONNECTIONMANAGER2
/**
 * Unix domain socket parameters
 *     unix_path Path of unix domain socket
 */
#define INDIGO_CXN_UNIX_PATH_LEN 64
typedef struct indigo_cxn_params_unix_s {
    indigo_cxn_protocol_t protocol;
    char unix_path[INDIGO_CXN_UNIX_PATH_LEN];
} indigo_cxn_params_unix_t;
#endif /* DEPENDMODULE_INCLUDE_OFCONNECTIONMANAGER2 */

/**
 * The super class for connection parameters
 */

typedef union indigo_cxn_protocol_params_u {
    indigo_cxn_params_header_t header;
    indigo_cxn_params_tcp_over_ipv4_t tcp_over_ipv4;
    indigo_cxn_params_tcp_over_ipv6_t tcp_over_ipv6;
#ifdef DEPENDMODULE_INCLUDE_OFCONNECTIONMANAGER2
    indigo_cxn_params_unix_t unx;
    indigo_cxn_params_tcp_over_ipv4_t tls_over_ipv4;
    indigo_cxn_params_tcp_over_ipv6_t tls_over_ipv6;
#endif /* DEPENDMODULE_INCLUDE_OFCONNECTIONMANAGER2 */
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

/* FIXME deprecated */
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

#ifdef DEPENDMODULE_INCLUDE_OFCONNECTIONMANAGER2
/**
 * Status of a connection instance.
 *    is_connected True if the handshake has completed
 *    negotiated_version If connected, the version used by the connection
 *    disconnect_count Number of times controller has disconnected from switch
 *    forced_disconnect_count Number of times the switch disconnected
 *    bytes_in Number of bytes read in since last connect
 *    bytes_out Number of bytes written in since last connect
 *    messages_in Number of messages received since last connect
 *    messages_out Number of messages sent to controller since last connect
 */

typedef struct indigo_cxn_status_s {
    bool is_connected;
    of_version_t negotiated_version;
    uint32_t disconnect_count;
    uint32_t forced_disconnect_count;
    uint64_t bytes_in;
    uint64_t bytes_out;
    uint64_t messages_in;
    uint64_t messages_out;
} indigo_cxn_status_t;
#else
/**
 * Status of a connection instance.
 *    state The current connection state (see indigo_cxn_state_t)
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
    of_version_t negotiated_version;
    uint32_t disconnect_count;
    uint32_t forced_disconnect_count;
    uint64_t bytes_in;
    uint64_t bytes_out;
    uint64_t messages_in;
    uint64_t messages_out;
} indigo_cxn_status_t;
#endif /* DEPENDMODULE_INCLUDE_OFCONNECTIONMANAGER2 */

/****************************************************************
 *
 * Prototypes of routines provided by connection manager
 *
 ****************************************************************/

#ifdef DEPENDMODULE_INCLUDE_OFCONNECTIONMANAGER2
/**
 * Maximum length of TLS configuration parameters,
 * including NULL termination.
 */
#define INDIGO_TLS_CFG_PARAM_LEN 256

/**
 * Configure TLS parameters; each parameter has a maximum length given by
 * INDIGO_TLS_CFG_PARAM_LEN above.
 * @param cipher_list One or more cipher strings separated by colons.
 * See https://www.openssl.org/docs/manmaster/apps/ciphers.html for examples.
 * @param ca_cert Path to certificate authority's PEM-formatted certificate.
 * Set to NULL to allow self-signed certificates.
 * @param switch_cert Path to switch's PEM-formatted certificate.
 * @param switch_priv_key Path to switch's PEM-formatted private key.
 * @param exp_controller_suffix If not NULL and ca_cert is not NULL,
 * will verify that the controller's commonName ends with this string.
 */
extern indigo_error_t
indigo_cxn_config_tls(char *cipher_list,
                      char *ca_cert,
                      char *switch_cert,
                      char *switch_priv_key,
                      char *exp_controller_suffix);
#endif /* DEPENDMODULE_INCLUDE_OFCONNECTIONMANAGER2 */

/**
 * Add a controller instance
 * @param params Parameters specific to the connection protocol; see above
 * @param id (out) Descriptor (small integer) returned identifying the
 * controller instance
 * @param config_params Configuration parameters; see above
 */

extern indigo_error_t indigo_controller_add(
    indigo_cxn_protocol_params_t *protocol_params,
    indigo_cxn_config_params_t *config_params,
    indigo_controller_id_t *id);

/**
 * Remove the controller indexed by id
 * @param id The controller descriptor returned by controller add
 */

extern indigo_error_t indigo_controller_remove(indigo_controller_id_t id);

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


#ifdef DEPENDMODULE_INCLUDE_OFCONNECTIONMANAGER2
/**
 * Connection status change handler callback prototype
 * @param controller_id The descriptor of the controller that has changed
 * @param aux_id The connection's auxiliary identifier
 * @param cxn_proto_params Protocol parameters associated with the controller
 * @param is_connected True if the connection has completed handshake
 * @param cookie Passed in to register function
 *
 * For complete information, do a status_get on the connection
 */

typedef void (*indigo_cxn_status_change_f)(
    indigo_controller_id_t       controller_id,
    uint8_t                      aux_id,
    indigo_cxn_protocol_params_t *cxn_proto_params,
    bool                         is_connected,
    void                         *cookie);
#else
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
#endif /* DEPENDMODULE_INCLUDE_OFCONNECTIONMANAGER2 */

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
 * Connection Manager takes responsibility for obj. This means that if you
 * send the object to more than one connection you must first duplicate it.
 */

extern void indigo_cxn_send_controller_message(
    indigo_cxn_id_t cxn_id,
    of_object_t *obj);

/**
 * Send an async OpenFlow message to multiple controller connections
 *
 * @param obj The LOCI object representing the message
 *
 * Provided by connection manager, required by state manager
 *
 * The connections sent to are determined by the message version
 * and the connections' async config.
 *
 * Connection Manager takes responsibility for obj.
 */

extern void indigo_cxn_send_async_message(of_object_t *obj);

/**
 * Send an error message to a controller connection
 *
 * @param cxn_id Controller to receive msg
 * @param orig Message this error is in response to
 * @param type Type of error message
 * @param code Code of error message for this type
 *
 * The version, XID, and header data are taken from orig.
 */
extern void
indigo_cxn_send_error_reply(indigo_cxn_id_t cxn_id, of_object_t *orig,
                            uint16_t type, uint16_t code);

/**
 * Send a BSN error message to a controller connection
 * @param cxn_id Controller to receive msg
 * @param orig Message this error is in response to
 * @param err_txt Informative text to be copied into error msg
 */
void
indigo_cxn_send_bsn_error(indigo_cxn_id_t cxn_id, of_object_t *orig,
                          char *err_txt);

/**
 * Send a BSN gentable error message to a controller connection
 * @param cxn_id Controller to receive msg
 * @param orig Message this error is in response to
 * @param gentable_id Table on which error occurred
 * @param code Error code to be sent
 * @param err_txt Informative text to be copied into error msg
 */
void
indigo_cxn_send_bsn_gentable_error(indigo_cxn_id_t cxn_id,
                                   of_object_t *orig,
                                   uint16_t gentable_id,
                                   uint16_t code,
                                   char *err_txt);

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
 * Controller information structure.
 */
typedef struct indigo_controller_info_s {
    struct indigo_controller_info_s* next;

    /** The id for this controller . */
    indigo_controller_id_t controller_id;

    /** Controller Role */
    indigo_cxn_role_t role;

    /** The protocol parameters for this controller. */
    indigo_cxn_protocol_params_t protocol_params;

    /** The configuration parameters for this controller. */
    indigo_cxn_config_params_t config_params;

    /** The auxillary connections for this controller */
    uint32_t num_aux;

    /** The connection id for this controller's main connection */
    indigo_cxn_id_t main_cxn_id;
    
} indigo_controller_info_t;

/**
 * @brief Get a list of all current controllers.
 * @param [out] Receives the controller list.
 */
extern void 
indigo_controller_list(indigo_controller_info_t** list);

/**
 * @brief Destroy a list returned by indigo_controller_list()
 * @param list The list.
 */
extern void 
indigo_controller_list_destroy(indigo_controller_info_t* list);

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

/**
 * @brief Get Auxiliary id associated with the connection
 * @param cxn_id Connection id for this connection 
 * @param [out] auxiliary_id Auxiliary id for this connection
 */
extern indigo_error_t
indigo_cxn_get_auxiliary_id(indigo_cxn_id_t cxn_id, uint8_t *auxiliary_id);

/**
 * @brief Async msg channel selector handler
 * @param obj The LOCI object representing the message 
 * @param num_aux Number of aux cxn's available to the controller
 * @param auxiliary_id Auxiliary id of the cxn to send the msg on, 
 * should be <= num_aux
 */
typedef void (*indigo_cxn_async_channel_selector_f)(const of_object_t *obj, 
                                                    uint32_t num_aux,
                                                    uint8_t *auxiliary_id);
/**
 * @brief Register application specific auxiliary channel selector for asyc msgs
 * @param fn Application specific function for channel selector
 */
void indigo_cxn_async_channel_selector_register(
                                    indigo_cxn_async_channel_selector_f fn);
/**
 * @brief Deregister application specific auxiliary channel selector for asyc msgs
 * @param fn Application specific function for channel selector
 */
void indigo_cxn_async_channel_selector_unregister(
                                    indigo_cxn_async_channel_selector_f fn);

/*
 * Barrier blocking
 *
 * Requests from the controller that aren't handled synchronously need to
 * delay later barriers until completion. Examples are non-strict flow
 * deletion and flow stats.
 *
 * When a barrier blocker is created with indigo_cxn_block_barrier a
 * reference count is incremented on the connection. When the barrier
 * blocker is destroyed with indigo_cxn_unblock_barrier, the reference
 * count is decremented. No barrier reply will be sent in response to
 * a barrier request until the reference count is zero.
 *
 * On debug builds, an extra allocation is performed so that we can use
 * Valgrind to debug reference counting errors. A missing unblock will
 * result in a memory leak and a double unblock will result in a double
 * free, both of which will be caught by Valgrind.
 *
 * This struct should be treated as opaque.
 */

typedef struct indigo_cxn_barrier_blocker_s {
    indigo_cxn_id_t cxn_id;
#ifndef NDEBUG
    void *tracker;
#endif
} indigo_cxn_barrier_blocker_t;

/**
 * @brief Create a barrier blocker
 * @param cxn_id Connection ID
 * @param [out] blocker Uninitialized indigo_cxn_barrier_blocker_t
 */
void indigo_cxn_block_barrier(indigo_cxn_id_t cxn_id, indigo_cxn_barrier_blocker_t *blocker);

/**
 * @brief Destroy a barrier blocker
 * @param blocker Previously created by indigo_cxn_block_barrier
 */
void indigo_cxn_unblock_barrier(indigo_cxn_barrier_blocker_t *blocker);

/**
 * @brief Create an async op blocker
 * @param cxn_id Connection ID
 */
void indigo_cxn_block_async_op(indigo_cxn_id_t cxn_id);

/**
 * @brief Destroy an async op blocker
 * @param cxn_id Connection ID
 */
extern void indigo_cxn_unblock_async_op(indigo_cxn_id_t cxn_id);

/**
 * @brief Pause reading messages from a connection
 * @param cxn_id Connection ID
 *
 * We handle messages that require more than a small amount of CPU time
 * asynchronously. Each of these long-running tasks consumes some resources,
 * so we don't want to run more than a small constant number in parallel.
 * OFStateManager will use this interface to pause reading messages from the
 * connection requesting a long-running task until the task completes.
 */
void indigo_cxn_pause(indigo_cxn_id_t cxn_id);

/**
 * @brief Resume reading messages from a connection
 * @param cxn_id Connection ID
 */
void indigo_cxn_resume(indigo_cxn_id_t cxn_id);

/**
 * Barrier notification callback
 *
 * @param cxn_id Connection ID where the barrier was received
 * @param cookie Passed in on register
 */

typedef void (*indigo_cxn_barrier_notify_f)(
    indigo_cxn_id_t              cxn_id,
    void                         *cookie);

/**
 * Register a barrier notification handler
 * @param handler The handler to register
 * @param cookie Anonymous data passed back to handler
 *
 * Registered functions are called when any connection receives a barrier
 * and barriers on that connection are currently blocked.
 */
void indigo_cxn_barrier_notify_register(
    indigo_cxn_barrier_notify_f handler,
    void *cookie);

/**
 * Unregister a barrier notification handler
 * @param handler The handler to unregister
 * @param cookie Cookie associated with handler
 *
 * The cookie is part of the lookup key
 */
void indigo_cxn_barrier_notify_unregister(
    indigo_cxn_barrier_notify_f handler,
    void *cookie);

typedef int (*indigo_cxn_bundle_comparator_t)(of_object_t *a, of_object_t *b);

/**
 * Set the bundle sort comparison function
 *
 * To simplify controller implementation, the switch can reorder messages in a
 * bundle before committing them. The comparison function is similar to the one
 * used by qsort(3) - it should return a negative number if message A should be
 * processed before message B.
 *
 * Example comparator that sorts group-adds before other messages and
 * group-deletes after:
 *
 * int
 * bundle_comparator(of_object_t *a, of_object_t *b)
 * {
 *     if (a->object_id == b->object_id) {
 *         return 0;
 *     } else if (a->object_id == OF_GROUP_ADD) {
 *         return -1;
 *     } else if (a->object_id == OF_GROUP_DELETE) {
 *         return 1;
 *     } else {
 *         return 0;
 *     }
 * }
 */
void
indigo_cxn_bundle_comparator_set(indigo_cxn_bundle_comparator_t fn);

typedef uint32_t (*indigo_cxn_subbundle_designator_t)(of_object_t *obj);

/**
 * Set up the subbundle infrastructure
 *
 * Sorting 100k+ messages with a single comparator may take seconds,
 * stalling the main thread.
 *
 * Instead, we can divide a bundle into a number of subbundles, and provide
 * a subbundle designator function that takes a message as input and
 * returns the index of the subbundle to which that message should be
 * assigned.
 * On receipt of a bundle_add message, the encapsulated message is added to
 * the subbundle specified by the designator.
 *
 * An array of subbundle comparator functions can also be provided.
 * If the array is non-NULL, it must be num_subbundles in length.
 * Once the bundle commit message is received, the subbundles for which
 * non-NULL comparators are specified are sorted, and then the messages
 * are processed in a long-running task.
 * The i-th subbundle comparator is used to sort the i-th subbundle.
 *
 * @param num_subbundles Number of subbundles in a bundle
 * @param designator Returns the subbundle to which the input message is added
 * @param comparators Array of comparators for sorting subbundles
 * @return INDIGO_ERROR_PARAM if input parameters are invalid,
 *    INDIGO_ERROR_NONE otherwise
 *
 * To disable subbundling, use "indigo_cxn_subbundle_set(0, NULL, NULL);"
 */
indigo_error_t
indigo_cxn_subbundle_set(uint32_t num_subbundles,
                         indigo_cxn_subbundle_designator_t designator,
                         indigo_cxn_bundle_comparator_t comparators[]);

typedef void (*indigo_cxn_subbundle_start_t)(indigo_cxn_id_t cxn_id,
                                             uint32_t subbundle_idx);
typedef void (*indigo_cxn_subbundle_finish_t)(indigo_cxn_id_t cxn_id,
                                              uint32_t subbundle_idx);

/**
 * Extends the subbundle infrastructure from indigo_cxn_subbundle_set above.
 * First three parameters are the same as for indigo_cxn_subbundle_set.
 * @param starts Array of start functions; the ith function is called
 * before the ith subbundle is started.
 * @param finishes Array of finish functions; the ith function is called
 * after the ith subbundle is finished.
 *
 * The intent is to provide hooks so that operations on the flowtables or
 * gentables in a subbundle can be bookended by start and finish functions.
 *
 * If the subbundle_designator is written to assign all openflow messages
 * concerning a particular set of flowtables and/or gentables to a specific
 * subbundle, the start and finish functions can facilitate processing of
 * blocks of flow/gentable entries, rather than the usual per-entry
 * processing.
 *
 * For gentables, indigo_core_gentable_start() and
 * indigo_core_gentable_finish() can be called from the registered
 * subbundle_start and subbundle_finish functions to invoke the
 * start and finish functions of a given gentable.
 */
indigo_error_t
indigo_cxn_subbundle_set2(uint32_t num_subbundles,
                          indigo_cxn_subbundle_designator_t designator,
                          indigo_cxn_bundle_comparator_t comparators[],
                          indigo_cxn_subbundle_start_t starts[],
                          indigo_cxn_subbundle_finish_t finishes[]);

/**
 * Adjust the OpenFlow connection timeout in switch by changing the
 * connection allowed outstanding count of keepalive messages.
 * @param cxn_id Connection ID where the barrier was received
 * @param max_outstanding_count Outstanding keepalive message count allowed
 */
void
indigo_cxn_keepalive_max_outstanding_count_set(indigo_cxn_id_t cxn_id,
                                               uint32_t max_outstanding_count);

#endif /* _INDIGO_OF_CONNECTION_MANAGER_H_ */
/* @} */
