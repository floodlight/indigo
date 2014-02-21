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
 * @brief Implementation of OF Connection Manager for Indigo Linux Ref
 */

#include "ofconnectionmanager_log.h"

#include <SocketManager/socketmanager.h>
#include "cxn_instance.h"
#include <OFConnectionManager/ofconnectionmanager.h>
#include <Configuration/configuration.h>

#include <indigo/of_state_manager.h>
#include <indigo/memory.h>
#include <indigo/assert.h>

#include <loci/loci_dump.h>
#include <loci/loci_show.h>

#include <cjson/cJSON.h>

#include <sys/socket.h>
#include <fcntl.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <sys/errno.h>

#include "ofconnectionmanager_int.h"

/* Short hand logging macros */
#define LOG_ERROR AIM_LOG_ERROR
#define LOG_WARN AIM_LOG_WARN
#define LOG_INFO AIM_LOG_INFO
#define LOG_VERBOSE AIM_LOG_VERBOSE
#define LOG_TRACE AIM_LOG_TRACE

static int init_done = 0;
static int module_enabled = 0;

/****************************************************************
 * Forward declarations
 ****************************************************************/

static void
ind_cxn_listen_socket_ready(int socket_id, void *cookie, int read_ready,
                            int write_ready, int error_seen);

/****************************************************************
 * Connection Manager Data shared within module
 ****************************************************************/

int have_local_connection;
int remote_connection_count;
int successful_handshakes; /* Number of times handshake completes */

uint32_t ind_cxn_internal_errors;

uint64_t ind_cxn_generation_id;

/****************************************************************
 * Connection Manager Private Data
 ****************************************************************/
static ind_cxn_config_t cxn_config;

/* @fixme Make this a module parameter */
#define MAX_CONTROLLER_CONNECTIONS 32

/**
 * Connection control blocks, indexed by connection index
 */
static connection_t connection[MAX_CONTROLLER_CONNECTIONS];

#define CXN_ID_ACTIVE(cxn_id) CXN_ACTIVE(&connection[cxn_id])
#define CXN_ID_TCP_CONNECTED(cxn_id) CXN_TCP_CONNECTED(&connection[cxn_id])

#if 0
/**
 * Support one special local connection
 */
static int local_cxn_id = -1;

#define LOCAL_ACTIVE CXN_ID_ACTIVE(local_cxn_id)
#define LOCAL_TCP_CONNECTED CXN_ID_TCP_CONNECTED(local_cxn_id)
#endif

/**
 * Preferred connection when UNSPECIFIED is used
 *
 * For now, preferred is always a remote connection
 */
static int preferred_cxn_id = -1;

/****************************************************************
 * Connection instance bookkeeping
 ****************************************************************/
#define INVALID_CXN_ID -1

#define CXN_ID_VALID(cxn_id)                                        \
    (((cxn_id) >= 0) && ((cxn_id) < MAX_CONTROLLER_CONNECTIONS))

#define CXN_TO_CXN_ID(cxn) ((cxn)->cxn_id)

#define ACTIVE_ENTRY(cxn_id)                                \
    (CXN_ID_VALID(cxn_id) && (connection[cxn_id].active))

#define TCP_CONNECTED_ENTRY(cxn_id)                                     \
    (ACTIVE_ENTRY(cxn_id) && (CXN_TCP_CONNECTED(&connection[cxn_id])))

/* Includes local connection */
#define FOREACH_ACTIVE_CXN(cxn_id, cxn)                                 \
    for (cxn_id = 0, cxn = &connection[0];                              \
         cxn_id < MAX_CONTROLLER_CONNECTIONS;                           \
         ++cxn_id, cxn = &connection[cxn_id])                           \
        if (CXN_ACTIVE(cxn))

/* Only remote connections */
#define FOREACH_REMOTE_ACTIVE_CXN(cxn_id, cxn)                          \
    for (cxn_id = 0, cxn = &connection[0];                              \
         cxn_id < MAX_CONTROLLER_CONNECTIONS;                           \
         ++cxn_id, cxn = &connection[cxn_id])                           \
        if (CXN_ACTIVE(cxn) && !((cxn)->config_params.local))

/* All remote connections which completed hand-shake and with requested role */
#define FOREACH_HS_COMPLETE_CXN_WITH_ROLE(cxn_id, cxn, cxn_role)        \
    for (cxn_id = 0, cxn = &connection[0];                              \
         cxn_id < MAX_CONTROLLER_CONNECTIONS;                           \
         ++cxn_id, cxn = &connection[cxn_id])                           \
        if (CXN_ACTIVE(cxn) && !(cxn->config_params.local) &&           \
            (cxn->status.role == cxn_role) &&                           \
            (cxn->status.state == INDIGO_CXN_S_HANDSHAKE_COMPLETE))

/**
 * Convert connection ID to pointer to cxn block
 */

#define CXN_ID_TO_CONNECTION(cxn_id) (&connection[cxn_id])


#define GEN_ID_SHIFT 16
#define GEN_ID_MASK 0xffff
#define CXN_ID_MASK 0xffff

void *cxn_to_cookie(connection_t *cxn)
{
    void *cookie;
    if (CXN_ACTIVE(cxn)) {
        cookie = (void *)
            ((uintptr_t)
             (((cxn->generation_id & GEN_ID_MASK) << GEN_ID_SHIFT) |
              (cxn->cxn_id & CXN_ID_MASK)));
    } else {
        cookie = NULL;
    }
    return cookie;
}

connection_t* cookie_to_cxn(void* cookie)
{
    uintptr_t val = (uintptr_t) cookie;
    uint32_t gen_id = (val >> GEN_ID_SHIFT) & GEN_ID_MASK;
    indigo_cxn_id_t cxn_id = val & CXN_ID_MASK;

    if (ACTIVE_ENTRY(cxn_id)) {
        connection_t *cxn = CXN_ID_TO_CONNECTION(cxn_id);
        if ((cxn->generation_id & GEN_ID_MASK) == gen_id) {
            return cxn;
        } else {
            return NULL;
        }
    } else {
        return NULL;
    }
}


/* Generate IP string from a connection ID */
static inline char *
cxn_id_ip_string(indigo_cxn_id_t cxn_id)
{
    return proto_ip_string(&connection[cxn_id].protocol_params);
}

/**
 * @brief Callback to process "socket ready"
 *
 * @param socket_id The socket that is ready
 * @param cookie Pointer to the connection instance
 * @param read_ready Was read-ready signaled by select
 * @param write_ready Was write-ready signaled by select
 * @param error_seen Was an error signaled by select
 *
 * This is exposed so that cxn instances can register it.
 */

void
indigo_cxn_socket_ready_callback(
    int socket_id,
    void *cookie,
    int read_ready,
    int write_ready,
    int error_seen)
{
    connection_t *cxn;
    int rv;

    cxn = (connection_t *)cookie;
    LOG_TRACE("Soc %d ready, cxn %p. rd %d. wr %d. er %d",
              socket_id, cookie, read_ready, write_ready, error_seen);

    if (!(CXN_ID_VALID(cxn->cxn_id))) {
        LOG_ERROR("Bad cxn callback %p", cxn);
        ++ind_cxn_internal_errors;
        return;
    }

    if (!(CXN_ACTIVE(cxn))) {
        LOG_ERROR("Socket ready callback on non active cxn %p", cxn);
        ++ind_cxn_internal_errors;
        return;
    }

    if (!(CXN_TCP_CONNECTED(cxn))) {
        LOG_ERROR("Socket ready callback on non connected cxn %p", cxn);
        ++ind_cxn_internal_errors;
        return;
    }

    if (error_seen) {
        int socket_error = 0;
        socklen_t len = sizeof(socket_error);
        getsockopt(cxn->sd, SOL_SOCKET, SO_ERROR, &socket_error, &len);
        LOG_ERROR("Error seen on connection %s: %s",
                  cxn_ip_string(cxn), strerror(socket_error));
        ind_cxn_disconnect(cxn);
        ++ind_cxn_internal_errors;
        return;
    }

    if (read_ready) {
        if ((rv = ind_cxn_process_read_buffer(cxn)) < 0) {
            LOG_VERBOSE("Error processing read buffer, resetting");
            ind_cxn_disconnect(cxn);
            return;
        }
    }

    if (write_ready) {
        if ((rv = ind_cxn_process_write_buffer(cxn)) < 0) {
            LOG_ERROR("Error processing write buffer, resetting");
            ind_cxn_disconnect(cxn);
            ++ind_cxn_internal_errors;
            return;
        }
    }
}


/****************************************************************
 * Status change callback bookkeeping
 ****************************************************************/

/**
 * Status change callback control block
 *
 * If a callback is non-NULL it is considered active and will
 * receive all connection status chagne notifications.
 */

typedef struct status_change_s {
    indigo_cxn_status_change_f callback;
    void *cookie;
} status_change_t;

#define MAX_STATUS_CHANGE_CALLBACKS 32 /* Make this a param? */

static status_change_t status_change[MAX_STATUS_CHANGE_CALLBACKS];

/**
 * For each status callback iterator
 * @param _idx An integer index variable
 * @param _cb Callback variable
 * @param _ck Cookie variable
 */

#define FOREACH_STATUS_CALLBACK(_idx, _cb, _ck)                      \
    for (_idx = 0, _cb = status_change[_idx].callback,               \
             _ck = status_change[_idx].cookie;                       \
         _idx < MAX_STATUS_CHANGE_CALLBACKS;                         \
         ++_idx, _cb = status_change[_idx].callback,                 \
             _ck = status_change[_idx].cookie)                       \
        if (_cb != NULL)

/**
 * Connection instance notifies the connection manager of a
 * change in state by calling this function
 *
 * @param cxn The connection handle
 *
 * See cxn_instance.c for details of the per-instance state machine.
 *
 * Current connection programming is as follows.
 *
 * A connection may be marked "local" which removes it from the
 * calculations mentioned below.
 *
 * At most one remote connection is supported, though a count is used
 * for future extensions to multiple connected controllers.
 *
 * "State changes" related to remote_connection_count are edge
 * triggered by calls to this function resulting from cxn_instance
 * state changes
 *
 * No combining of state changes.  Every state change results in a call
 * to this function
 */

void
ind_cxn_status_change(connection_t *cxn)
{
    void *cookie;
    int idx;
    indigo_cxn_status_change_f callback;

    /* Notify registered callbacks */
    FOREACH_STATUS_CALLBACK(idx, callback, cookie) {
        callback(cxn->cxn_id,
		 &cxn->protocol_params,
		 cxn->status.state,
		 cookie
		 );
    }

    /* Select this as preferred if no other connection known */
    if (!cxn->config_params.local) {
        if (CONNECTION_STATE(cxn) == INDIGO_CXN_S_CONNECTING) {
            ++remote_connection_count;
            indigo_core_connection_count_notify(remote_connection_count);
            if (preferred_cxn_id == -1) {
                LOG_VERBOSE("Setting preferred cxn to %s",
                            cxn_ip_string(cxn));
                preferred_cxn_id = cxn->cxn_id;
                LOG_VERBOSE("Clearing IP mask map");
                of_ip_mask_map_init();
            }
        } else if (CONNECTION_STATE(cxn) == INDIGO_CXN_S_CLOSING) {
            --remote_connection_count;
            indigo_core_connection_count_notify(remote_connection_count);
            if (CONNECTION_STATE(cxn) == INDIGO_CXN_S_CLOSING) {
                LOG_VERBOSE("Clearing preferred connection");
                preferred_cxn_id = -1;
            }
        }
    }

    LOG_TRACE("Cxn status change, rmt count %d", remote_connection_count);
}

/****************************************************************
 *
 * Connection management functions
 *
 ****************************************************************/


/**
 * Clear all state for the module
 */
static int
module_init(void)
{
    int idx;

    INDIGO_MEM_CLEAR(connection, sizeof(connection));
    INDIGO_MEM_CLEAR(status_change, sizeof(status_change));
    for (idx = 0; idx < MAX_CONTROLLER_CONNECTIONS; ++idx) {
        connection[idx].cxn_id = (indigo_cxn_id_t)idx;
    }

    ind_cfg_register(&ind_cxn_cfg_ops);

    ind_cxn_generation_id = 0;

    LOG_VERBOSE("Initial generation id: 0x%016"PRIx64, ind_cxn_generation_id);

    return INDIGO_ERROR_NONE;
}

static indigo_cxn_id_t
find_free_connection(void) {
    int idx;
    for (idx = 0; idx < MAX_CONTROLLER_CONNECTIONS; ++idx) {
        if (!connection[idx].active) {
            return (indigo_cxn_id_t)idx;
        }
    }

    return INVALID_CXN_ID;
}

/* @fixme What should the cxn backlog be? */
#define LOCAL_CXN_BACKLOG 5

/**
 * Initialize a local connection instance
 */
static int
listen_cxn_init(connection_t *cxn)
{
    struct sockaddr_in cxn_addr;
    indigo_error_t rv;
    indigo_cxn_params_tcp_over_ipv4_t *params;

    LOG_VERBOSE("Initializing listening socket");

    params = &cxn->protocol_params.tcp_over_ipv4;

    /* complete the socket structure */
    memset(&cxn_addr, 0, sizeof(cxn_addr));
    cxn_addr.sin_family = AF_INET;
    if (inet_pton(AF_INET, params->controller_ip, &cxn_addr.sin_addr) != 1) {
        LOG_ERROR("Could not convert %s to inet address", params->controller_ip);
        return INDIGO_ERROR_UNKNOWN;
    }
    cxn_addr.sin_port = htons(params->controller_port);

    /* bind the socket to the port number */
    if (bind(cxn->sd, (struct sockaddr *) &cxn_addr, sizeof(cxn_addr)) == -1) {
        LOG_ERROR("Could not bind to socket for local cxn: %s", strerror(errno));
        return INDIGO_ERROR_UNKNOWN;
    }

    /* show that we are willing to listen */
    if (listen(cxn->sd, LOCAL_CXN_BACKLOG) == -1) {
        LOG_ERROR("Could not listen to socket for local cxn: %s", strerror(errno));
        return INDIGO_ERROR_UNKNOWN;
    }

    /* Register the socket */
    rv = ind_soc_socket_register_with_priority(
            cxn->sd, ind_cxn_listen_socket_ready,
            cxn, IND_CXN_EVENT_PRIORITY);
    if (rv < 0) {
        LOG_ERROR("Could not register with socket manager: %s", indigo_strerror(rv));
        return INDIGO_ERROR_UNKNOWN;
    }

    /* Register with the scoket manager */

    LOG_INFO("Added local connection: %s", cxn_ip_string(cxn));
    return INDIGO_ERROR_NONE;
}


/**
 * Set up a connection instance.
 * @param sd If >=0, use this socket id; otherwise call socket().
 *
 * Typically, sd is >= 0 when this comes from an accept call.
 */

static connection_t *
connection_socket_setup(indigo_cxn_protocol_params_t *protocol_params,
                        indigo_cxn_config_params_t *config_params,
                        indigo_cxn_id_t *cxn_id,
                        int sd)
{
    int soc_flags;
    connection_t *cxn;

    *cxn_id = find_free_connection();
    if (INDIGO_CXN_INVALID(*cxn_id)) {
        LOG_ERROR("Could not allocate space for connection");
        return NULL;
    }

    cxn = CXN_ID_TO_CONNECTION(*cxn_id);

    /* Initialize connection structure */
    INDIGO_MEM_COPY(&cxn->protocol_params, protocol_params,
                    sizeof(*protocol_params));
    INDIGO_MEM_COPY(&cxn->config_params, config_params,
                    sizeof(*config_params));
    INDIGO_MEM_CLEAR(&cxn->status, sizeof(cxn->status));

    if (!CXN_LOCAL(cxn)) {
        cxn->keepalive.period_ms = config_params->periodic_echo_ms;
        cxn->keepalive.threshold = config_params->reset_echo_count;
    } else {
        cxn->keepalive.period_ms = 0;
        cxn->keepalive.threshold = 0;
    }

    ind_cxn_disconnected_init(cxn);

    if (sd < 0) {
        /* Attempt to create the socket */
        cxn->sd = socket(AF_INET, SOCK_STREAM, 0);
        if (cxn->sd < 0) {
            LOG_ERROR("Failed to create controller connection socket: %s", strerror(errno));
            return NULL;
        }
    } else {
        cxn->sd = sd;
    }

    soc_flags = fcntl(cxn->sd, F_GETFL, 0);
    if (soc_flags == -1 || fcntl(cxn->sd, F_SETFL,
                                 soc_flags | O_NONBLOCK) == -1) {
        LOG_ERROR("Failed to set non-blocking flag for socket: %s", strerror(errno));
        close(cxn->sd);
        return NULL;
    }

    /* Disable Nagle's algorithm */
    {
        int flag = 1;
        (void) setsockopt(cxn->sd, IPPROTO_TCP, TCP_NODELAY,
                          (char *) &flag, sizeof(int));
    }

    LOG_VERBOSE("Created non-blocking socket %d for %s",
                cxn->sd, cxn_id_ip_string(*cxn_id));

    cxn->active = 1;
    if (sd >= 0) { /* Assume connection is good to go */
        /* Set state to connecting */
        ind_cxn_state_set(cxn, INDIGO_CXN_S_CONNECTING);
    } else if (!CXN_LISTEN(cxn)) {
        /* Force immediate connection check event */
        ind_soc_timer_event_register_with_priority(
            ind_cxn_connection_retry_timer, cxn,
            IND_SOC_TIMER_IMMEDIATE, IND_CXN_EVENT_PRIORITY);
    }

    return cxn;
}


/* Add a controller connection instance */

indigo_error_t
indigo_cxn_connection_add(indigo_cxn_protocol_params_t *protocol_params,
                          indigo_cxn_config_params_t *config_params,
                          indigo_cxn_id_t *cxn_id)
{
    connection_t *cxn;
    indigo_error_t rv = INDIGO_ERROR_NONE;

    if (protocol_params == NULL) {
        LOG_ERROR("Protocol params is NULL on cxn add");
        return INDIGO_ERROR_PARAM;
    }

    if (config_params == NULL) {
        LOG_ERROR("Config params is NULL on cxn add");
        return INDIGO_ERROR_PARAM;
    }

    if (config_params->local &&
        (config_params->periodic_echo_ms ||
         config_params->reset_echo_count)) {
        LOG_ERROR("Local connection with nonzero echo params on cxn add");
        return INDIGO_ERROR_PARAM;
    }

    LOG_TRACE("Connection add: %s", proto_ip_string(protocol_params));

    if (cxn_id == NULL) {
        LOG_ERROR("Connection ID output is NULL");
        return INDIGO_ERROR_PARAM;
    }

    if (protocol_params->header.protocol != INDIGO_CXN_PROTO_TCP_OVER_IPV4) {
        LOG_ERROR("Unsupported protocol for connection add: %d",
                     protocol_params->header.protocol);
        return INDIGO_ERROR_NOT_SUPPORTED;
    }

    cxn = connection_socket_setup(protocol_params, config_params, cxn_id, -1);

    if (cxn == NULL) {
        LOG_ERROR("Could not set up connection");
        /* @fixme clean up? */
    } else {
        if (config_params->listen) {
            rv = listen_cxn_init(cxn);
            if (rv != INDIGO_ERROR_NONE) {
                /* @fixme clean up connection? */
                cxn->active = 0;
            }
        } else {
            LOG_INFO("Added remote connection: %s", cxn_ip_string(cxn));
        }
    }

    return rv;
}


/* Look for a controller connection with the given params and remove it */
indigo_error_t
indigo_cxn_connection_remove(indigo_cxn_id_t cxn_id)
{
    if (!CXN_ID_VALID(cxn_id) || !CXN_ID_ACTIVE(cxn_id)) {
        LOG_ERROR("Remove connection id %d invalid or not active", cxn_id);
        return INDIGO_ERROR_PARAM;
    }

    LOG_INFO("Connection remove: %s", cxn_id_ip_string(cxn_id));

    if (CONNECTION_STATE(&connection[cxn_id]) != INDIGO_CXN_S_DISCONNECTED) {
        connection[cxn_id].flags |= CXN_TO_BE_REMOVED;
        ind_cxn_disconnect(&connection[cxn_id]);
    } else {
        ind_soc_timer_event_unregister(ind_cxn_connection_retry_timer,
                                       &connection[cxn_id]);
        connection[cxn_id].active = 0;
    }

    /* @fixme If no connections active, turn off periodic timeout */

    return INDIGO_ERROR_NONE;
}

/* Return the config of a specific connection */
indigo_error_t
indigo_cxn_connection_config_get(
    indigo_cxn_id_t cxn_id,
    indigo_cxn_config_params_t *config)
{
    if (!CXN_ID_VALID(cxn_id) || !CXN_ID_ACTIVE(cxn_id)) {
        LOG_TRACE("Config_get id %d invalid or not active", cxn_id);
        return INDIGO_ERROR_PARAM;
    }

    INDIGO_MEM_COPY(config, &connection[cxn_id].config_params,
                    sizeof(*config));

    return INDIGO_ERROR_NONE;
}

/* Return the status of a specific connection */
indigo_error_t
indigo_cxn_connection_status_get(
    indigo_cxn_id_t cxn_id,
    indigo_cxn_status_t *status)
{
    if (!CXN_ID_VALID(cxn_id) || !CXN_ID_ACTIVE(cxn_id)) {
        LOG_TRACE("Status_get id %d invalid or not active", cxn_id);
        return INDIGO_ERROR_PARAM;
    }

    INDIGO_MEM_COPY(status, &connection[cxn_id].status, sizeof(*status));

    return INDIGO_ERROR_NONE;
}

/**
 * Send a role status message
 *
 * These are sent when a controller's role changes for any reason
 * other than it directly sending a role request message.
 */
void
ind_cxn_send_role_status(connection_t *cxn, int reason)
{
    /* Need to make translate_to_openflow_role public */
    /* Master -> slave is currently the only possible case */
    INDIGO_ASSERT(cxn->status.role == INDIGO_CXN_R_SLAVE);

    if (cxn->status.negotiated_version == OF_VERSION_1_3) {
        of_bsn_role_status_t *msg = of_bsn_role_status_new(OF_VERSION_1_3);
        if (msg == NULL) {
            LOG_INFO("Failed to allocate role status message");
            return;
        }
        of_bsn_role_status_role_set(msg, OF_CONTROLLER_ROLE_SLAVE);
        of_bsn_role_status_reason_set(msg, reason);
        of_bsn_role_status_generation_id_set(msg, ind_cxn_generation_id);
        indigo_cxn_send_controller_message(cxn->cxn_id, msg);
    }
}

/**
 * Change the master connection
 *
 * @param master_id The connection id of the new master
 *
 * Downgrades the current master, if any, to a slave.
 */
void
ind_cxn_change_master(indigo_cxn_id_t master_id)
{
    indigo_cxn_id_t cxn_id;
    connection_t *cxn;
    FOREACH_REMOTE_ACTIVE_CXN(cxn_id, cxn) {
        if (cxn->cxn_id == master_id) {
            LOG_INFO("Upgrading cxn %s to master", cxn_id_ip_string(cxn_id));
            cxn->status.role = INDIGO_CXN_R_MASTER;
        } else if (cxn->status.role == INDIGO_CXN_R_MASTER) {
            LOG_INFO("Downgrading cxn %s to slave", cxn_id_ip_string(cxn_id));
            cxn->status.role = INDIGO_CXN_R_SLAVE;
            ind_cxn_send_role_status(
                cxn, OFP_BSN_CONTROLLER_ROLE_REASON_MASTER_REQUEST);
        }
    }
}

void
ind_cxn_populate_connection_list(of_list_bsn_controller_connection_t *list)
{
    indigo_cxn_id_t cxn_id;
    connection_t *cxn;
    FOREACH_REMOTE_ACTIVE_CXN(cxn_id, cxn) {
        of_bsn_controller_connection_t entry;
        of_desc_str_t uri;
        uint32_t role;

        of_bsn_controller_connection_init(&entry, list->version, -1, 1);
        if (of_list_bsn_controller_connection_append_bind(list, &entry) < 0) {
            LOG_ERROR("Failed to append controller connection to list");
            break;
        }

        if (CXN_HANDSHAKE_COMPLETE(cxn)) {
            of_bsn_controller_connection_state_set(&entry, 1);
        } else {
            of_bsn_controller_connection_state_set(&entry, 0);
        }

        switch (cxn->status.role) {
        case INDIGO_CXN_R_MASTER:
            role = OF_CONTROLLER_ROLE_MASTER;
            break;
        case INDIGO_CXN_R_SLAVE:
            role = OF_CONTROLLER_ROLE_SLAVE;
            break;
        case INDIGO_CXN_R_EQUAL:
            role = OF_CONTROLLER_ROLE_EQUAL;
            break;
        default:
            AIM_ASSERT(0);
            role = -1;
            break;
        }

        of_bsn_controller_connection_role_set(&entry, role);

        memset(uri, 0, sizeof(uri));

        if (cxn->protocol_params.header.protocol == INDIGO_CXN_PROTO_TCP_OVER_IPV4) {
            indigo_cxn_params_tcp_over_ipv4_t *proto =
                &cxn->protocol_params.tcp_over_ipv4;
            snprintf(uri, sizeof(uri), "tcp://%s:%d",
                proto->controller_ip, proto->controller_port);
        }

        of_bsn_controller_connection_uri_set(&entry, uri);
    }
}

/**
 * Is the given LOCI object actually a message object?
 */

#define IS_MSG_OBJ(obj)                                                 \
    ((obj)->object_id >= 0 && (obj)->object_id < OF_MESSAGE_OBJECT_COUNT)

/* Assumes obj is a message */
#define IS_ASYNC_MSG(obj) (((obj)->object_id == OF_PACKET_IN) ||    \
                           ((obj)->object_id == OF_PORT_STATUS) ||  \
                           ((obj)->object_id == OF_FLOW_REMOVED))

/* Send an OpenFlow message to a controller connection
 *
 * This routine takes ownership of the object.
 *
 * In some cases the message may be dropped.
 */
void
indigo_cxn_send_controller_message(indigo_cxn_id_t cxn_id, of_object_t *obj)
{
    uint8_t *data = NULL;
    int len;
    connection_t *cxn;
    uint32_t xid;

    if (INDIGO_CXN_INVALID(cxn_id)) {
        LOG_ERROR("Invalid or no active connection: %d", cxn_id);
        goto done;
    }

    cxn = CXN_ID_TO_CONNECTION(cxn_id);
    if (!CXN_TCP_CONNECTED(cxn)) {
        LOG_ERROR("Connection id %d is not connected", cxn_id);
        goto done;
    }

    xid = of_message_xid_get(OF_BUFFER_TO_MESSAGE(OF_OBJECT_BUFFER_INDEX(obj, 0)));

    LOG_VERBOSE("cxn %s: Sending %s message xid %u",
                cxn_ip_string(cxn), of_object_id_str[obj->object_id], xid);

    if(cxn->trace_pvs) {
        aim_printf(cxn->trace_pvs, "** of_msg_trace: send to cxn=%d\n", cxn->cxn_id);
        of_object_dump((loci_writer_f)aim_printf, cxn->trace_pvs, obj);
        aim_printf(cxn->trace_pvs, "**\n\n");
    }


    if (obj->object_id == OF_FEATURES_REPLY) {
        if (CONNECTION_STATE(cxn) == INDIGO_CXN_S_CONNECTING) {
            ++successful_handshakes;
            ind_cxn_state_set(cxn, INDIGO_CXN_S_HANDSHAKE_COMPLETE);
        }
    }

    if (!CXN_HANDSHAKE_COMPLETE(cxn)) {
        if (IS_ASYNC_MSG(obj)) {
            LOG_TRACE("Handshake not complete; drop async msg %s",
                      of_object_id_str[obj->object_id]);
            goto done;
        }
    }

    /* async message throttling */
    if (obj->object_id == OF_PACKET_IN) {
        cxn->packet_ins++;
        if (CXN_DROP_PACKET_IN(cxn, obj)) {
            LOG_TRACE("Dropping packetIn");
            cxn->status.packet_in_drop++;
            goto done;
        }
    } else if (obj->object_id == OF_FLOW_REMOVED) {
        if (CXN_DROP_FLOW_REMOVED(cxn, obj)) {
            LOG_TRACE("Dropping flowRemoved");
            cxn->status.flow_removed_drop++;
            goto done;
        }
    }

    /* Steal the buffer and enqueue the data */
    LOG_OBJECT(obj);

    of_object_wire_buffer_steal((of_object_t *)obj, &data);
    len = obj->length;

    if (IS_MSG_OBJ(obj)) {
        cxn->messages_out_by_type[obj->object_id]++;
    } else {
        LOG_ERROR("Enqueue unknown msg obj id: %d", obj->object_id);
        cxn->messages_out_unknown++;
    }

    if (ind_cxn_instance_enqueue(cxn, data, len) < 0) {
        LOG_ERROR("Could not enqueue message data, disconnecting");
        aim_free(data);
        ind_cxn_disconnect(cxn);
    }

 done:
    of_object_delete(obj);
}

/**
 * Check whether the given connection is interested in the message.
 */
int
ind_cxn_accepts_async_message(const connection_t *cxn, const of_object_t *obj)
{
    if (CONNECTION_STATE(cxn) != INDIGO_CXN_S_HANDSHAKE_COMPLETE) {
        return 0;
    }

    if (cxn->config_params.local) {
        return 0;
    }

    if (cxn->status.role == INDIGO_CXN_R_SLAVE) {
        if ((obj->object_id == OF_PACKET_IN) ||
            (obj->object_id == OF_FLOW_REMOVED)) {
            return 0;
        }
    }

    return 1;
}

/**
 * Send an async message to all interested connections.
 */
void
indigo_cxn_send_async_message(of_object_t *obj)
{
    indigo_cxn_id_t cxn_id;
    connection_t *cxn;

    /*
     * The connection that will end up sending the original 'obj',
     * rather than a duplicate. indigo_cxn_send_controller_message
     * consumes the LOCI object so we need to call it on the
     * original last.
     */
    indigo_cxn_id_t first_cxn_id = INDIGO_CXN_ID_UNSPECIFIED;

    FOREACH_ACTIVE_CXN(cxn_id, cxn) {
        if (ind_cxn_accepts_async_message(cxn, obj) &&
            (cxn->status.negotiated_version == obj->version)) {
            if (first_cxn_id == INDIGO_CXN_ID_UNSPECIFIED) {
                first_cxn_id = cxn->cxn_id;
            } else {
                of_object_t *dup = of_object_dup(obj);
                if (dup != NULL) {
                    indigo_cxn_send_controller_message(cxn->cxn_id, dup);
                }
            }
        }
    }

    if (first_cxn_id != INDIGO_CXN_ID_UNSPECIFIED) {
        indigo_cxn_send_controller_message(first_cxn_id, obj);
    } else {
        LOG_VERBOSE("Dropping async %s message, no interested connections",
                    of_object_id_str[obj->object_id]);
        of_object_delete(obj);
    }
}

/**
 * Source for transaction IDs
 */
int
ind_cxn_xid_get(void)
{
    static int cur_transaction_id = 0;

    return cur_transaction_id++;
}

/**
 * Connection status change handler registration function
 * @param handler The handler to register
 * @param cookie Anonymous data passed back to handler
 *
 * Registered functions are called when any connection's status changes
 */
indigo_error_t
indigo_cxn_status_change_register(indigo_cxn_status_change_f handler,
                                  void *cookie)
{
    int idx;

    LOG_TRACE("Register status callback %p, cookie %p",
              handler, cookie);
    if (handler == NULL) {
        LOG_ERROR("Cannot register NULL status change fn");
        return INDIGO_ERROR_PARAM;
    }
    for (idx = 0; idx < MAX_STATUS_CHANGE_CALLBACKS; ++idx) {
        if (status_change[idx].callback == NULL) {
            status_change[idx].callback = handler;
            status_change[idx].cookie = cookie;
            return INDIGO_ERROR_NONE;
        }
    }

    LOG_ERROR("Could not find free slot for status change callback");
    return INDIGO_ERROR_RESOURCE;
}

/**
 * Connection status change handler registration function
 * @param handler The handler to register
 * @param cookie Anonymous data passed back to handler
 *
 * Registered functions are called when any connection's status changes
 */
indigo_error_t
indigo_cxn_status_change_unregister(indigo_cxn_status_change_f handler,
                                    void *cookie)
{
    int idx;
    indigo_cxn_status_change_f fn;
    void *ck;

    LOG_TRACE("Unregister status callback %p, cookie %p",
              handler, cookie);
    FOREACH_STATUS_CALLBACK(idx, fn, ck) {
        if ((fn == handler) && (ck == cookie)) {
            status_change[idx].callback = NULL;
            return INDIGO_ERROR_NONE;
        }
    }

    LOG_TRACE("Did not find status change callback fn");
    return INDIGO_ERROR_NONE;
}


/****************************************************************
 * Implementation specific functions
 ****************************************************************/


/**
 * Track objects for outstanding op count
 *
 * @param cxn The connection requesting the op
 * @param obj The object associated with the request
 *
 * This function is exposed to allow other agents to register duplicates
 * of messages that are generated to process complex operations
 */

indigo_error_t
ind_cxn_message_track_setup(indigo_cxn_id_t cxn_id, of_object_t *obj)
{
    connection_t *cxn;

    if (!CXN_ID_VALID(cxn_id) || !CXN_ID_TCP_CONNECTED(cxn_id)) {
        return INDIGO_ERROR_PARAM;
    }

    cxn = CXN_ID_TO_CONNECTION(cxn_id);

    cxn_message_track_setup(cxn, obj);

    return INDIGO_ERROR_NONE;
}



/*
 * Configure the connection manager
 * @param core The functions provided by core
 * @returns An error code
 *
 */

indigo_error_t
ind_cxn_init(ind_cxn_config_t *config)
{
    LOG_TRACE("Cxn init called");

    if (config == NULL) {
        LOG_ERROR("NULL configuration paremeter");
        return INDIGO_ERROR_PARAM;
    }

    /* Verify required functions are non-NULL */
    INDIGO_MEM_COPY(&cxn_config, config, sizeof(*config));

    module_init();

    init_done = 1;

    return INDIGO_ERROR_NONE;
}

/**
 * Enable the connection manager
 */
indigo_error_t
ind_cxn_enable_set(int enable)
{
    LOG_TRACE("OF connection mgr enable called");

    if (!init_done) {
        return INDIGO_ERROR_INIT;
    }

    if (enable && !module_enabled) {
        LOG_INFO("Enabling OF connection mgr");
        module_enabled = 1;
    } else if (!enable && module_enabled) {
        int cxn_id;
        connection_t *cxn;
        LOG_INFO("Disabling OF connection mgr");
        /* unregister state timeout handlers */
        FOREACH_ACTIVE_CXN(cxn_id, cxn) {
            ind_cxn_disconnect(cxn);
        }
        module_enabled = 0;
        /* @todo Anything need to be done here? */
    } else {
        LOG_VERBOSE("Redundant enable call.  Currently %s",
                    module_enabled ? "enabled" : "disabled");
    }

    return INDIGO_ERROR_NONE;
}

/**
 * Get the enable state for the manager
 */
indigo_error_t
ind_cxn_enable_get(int *enable)
{
    if (enable == NULL) {
        return INDIGO_ERROR_PARAM;
    }
    *enable = module_enabled;

    return INDIGO_ERROR_NONE;
}

/**
 * Clean up and de-initialize the connection manager
 */
indigo_error_t
ind_cxn_finish(void)
{
    LOG_TRACE("Indigo connection manager fini");
    ind_cxn_enable_set(0);
    return INDIGO_ERROR_NONE;
}

/**
 * Send an error message to a controller connection
 * @param version The version to use for the msg
 * @param cxn_id Controller to receive msg
 * @param xid The transaction ID to use for the message
 * @param type Type of error message
 * @param code Code of error message for this type
 * @param octets If not NULL use this for the data
 *
 * If version is invalid, uses the connection's negotiated version
 *
 * LOCI has one class per error message type. This is necessary to support
 * experimenter error messages, but is inconvenient when we just want to
 * set the normal type/code. This function works around it by creating
 * a hello failed error message (error type 0) and setting the error type
 * directly in the wire buffer.
 */

void
indigo_cxn_send_error_reply(indigo_cxn_id_t cxn_id, of_object_t *orig,
                            uint16_t type, uint16_t code)
{
    of_error_msg_t *msg;
    of_octets_t payload;
    uint32_t xid;

    payload.data = OF_OBJECT_BUFFER_INDEX(orig, 0);
    payload.bytes = orig->length;

    xid = of_message_xid_get(OF_BUFFER_TO_MESSAGE(payload.data));

    LOG_TRACE("Sending error msg to %s. type %d. code %d.",
              cxn_id_ip_string(cxn_id), type, code);

    if ((msg = of_hello_failed_error_msg_new(orig->version)) == NULL) {
        LOG_ERROR("Could not allocate error message");
        return;
    }

    of_hello_failed_error_msg_xid_set(msg, xid);
    of_hello_failed_error_msg_code_set(msg, code);

    if (of_hello_failed_error_msg_data_set(msg, &payload) < 0) {
        LOG_WARN("Failed to append original request to error message");
    }

    /* HACK manually set the type field */
    of_wire_buffer_u16_set(OF_OBJECT_TO_WBUF(msg), 8, type);

    indigo_cxn_send_controller_message(cxn_id, msg);
}

/****************************************************************
 *
 * Listening connection management routines
 *
 * Once connected, listen connection instances are treated like
 * any other, though they may not receive all asynchronous messages.
 *
 ****************************************************************/

/**
 * Handle a local (listening) socket ready event
 *
 * @param socket_id The socket that is ready
 * @param cookie Pointer to the connection instance
 * @param read_ready Was read-ready signaled by select
 * @param write_ready Was write-ready signaled by select
 * @param error_seen Was an error signaled by select
 *
 * This usually means a new socket connection is ready to be
 * accepted.  Spin up a new local connection instance for it.
 */

static void
ind_cxn_listen_socket_ready(int socket_id, void *cookie, int read_ready,
                            int write_ready, int error_seen)
{
    indigo_cxn_id_t cxn_id;
    connection_t *listen_cxn;
    socklen_t addrlen;
    struct sockaddr_in cxn_addr;
    int new_sd;
    connection_t *cxn;

    listen_cxn = (connection_t *)cookie;

    LOG_TRACE("Lcl soc %d ready, cxn %p. rd %d. wr %d. er %d",
              socket_id, cookie, read_ready, write_ready, error_seen);

    if (!(CXN_ID_VALID(listen_cxn->cxn_id))) {
        LOG_ERROR("Bad cxn callback %p", listen_cxn);
        ++ind_cxn_internal_errors;
        return;
    }

    if (!(CXN_ACTIVE(listen_cxn))) {
        LOG_ERROR("Socket ready callback on non active cxn %p", listen_cxn);
        ++ind_cxn_internal_errors;
        return;
    }

    INDIGO_ASSERT(listen_cxn->sd == socket_id);

    if (error_seen) {
        LOG_ERROR("Error seen on connection %s", cxn_ip_string(listen_cxn));
        /* @todo What to do on socket error */
        ++ind_cxn_internal_errors;
        /* Close the socket? */
        return;
    }

    /* Ready for an accept */
    if (!read_ready) {
        LOG_ERROR("Error: read not ready for connection %s",
                  cxn_ip_string(listen_cxn));
        /* @todo What to do on socket error */
        ++ind_cxn_internal_errors;
        /* Close the socket? */
        return;
    }

    /* Accept the new client */
    addrlen = sizeof(cxn_addr);
    new_sd = accept(listen_cxn->sd, (struct sockaddr *)&cxn_addr,
                    &addrlen);

    if (new_sd == -1) {
        LOG_ERROR("Error on accept for local cxn: %s", strerror(errno));
        ++ind_cxn_internal_errors;
        return;
    }
    LOG_VERBOSE("New cxn instance, port %d", ntohs(cxn_addr.sin_port));

    /* Okay, add the new connection with the socket */
    cxn = connection_socket_setup(&listen_cxn->protocol_params,
                                  &listen_cxn->config_params,
                                  /* @fixme Should track this for remove */
                                  &cxn_id, new_sd);

    if (cxn == NULL) {
        LOG_ERROR("Could not set up accepted connection");
        /* @fixme clean up? */
    } else {
        /* Inherit the tracer - move to config_params? */
        cxn->trace_pvs = listen_cxn->trace_pvs;
    }
}

indigo_error_t
ind_cxn_message_trace(indigo_cxn_id_t cxn_id, aim_pvs_t* pvs)
{
    connection_t *cxn;
    indigo_cxn_id_t _cxn_id;
    FOREACH_ACTIVE_CXN(_cxn_id, cxn) {
        if(cxn_id == -1 || cxn_id == _cxn_id) {
            cxn->trace_pvs = pvs;
            if(cxn_id == _cxn_id) {
                break;
            }
        }
    }
    return INDIGO_ERROR_NONE;
}

indigo_error_t
indigo_cxn_list(indigo_cxn_info_t** list)
{
    indigo_cxn_info_t* head = NULL;
    indigo_cxn_id_t cxn_id;
    connection_t *cxn;
    FOREACH_ACTIVE_CXN(cxn_id, cxn) {
        indigo_cxn_info_t* entry = aim_malloc(sizeof(*entry));
        entry->cxn_id = cxn_id;
        entry->cxn_status = cxn->status;
        entry->cxn_proto_params = cxn->protocol_params;
        entry->cxn_config_params = cxn->config_params;
        entry->next = head;
        head = entry;
    }
    *list = head;
    return INDIGO_ERROR_NONE;
}

void
indigo_cxn_list_destroy(indigo_cxn_info_t* list)
{
    indigo_cxn_info_t* e = list;
    while(e) {
        indigo_cxn_info_t* link = e->next;
        aim_free(e);
        e = link;
    }
}

void
ind_cxn_reset(indigo_cxn_id_t cxn_id)
{
    connection_t *cxn;

    if (!module_enabled) {
        return;
    }

    LOG_VERBOSE("Connection reset for id %d", cxn_id);
    if (cxn_id == IND_CXN_RESET_ALL) {
        /* Iterate thru active connections */
        FOREACH_ACTIVE_CXN(cxn_id, cxn) {
            ind_cxn_disconnect(cxn);
        }
    } else if (!INDIGO_CXN_INVALID(cxn_id)) {
        cxn = CXN_ID_TO_CONNECTION(cxn_id);
        ind_cxn_disconnect(cxn);
    }
}

/**
 * Show the stats for each connection.  If details
 * is true, show per-message data
 */

void
ind_cxn_stats_show(aim_pvs_t *pvs, int details)
{
    indigo_cxn_id_t cxn_id;
    connection_t *cxn;
    int idx;
    int cxn_count = 0;
    uint64_t counter;

    aim_printf(pvs, "Connection statistics report\n");
    aim_printf(pvs, "    Number of successful connections: %d\n",
               successful_handshakes);
    aim_printf(pvs, "    Current remote connection count: %d\n",
               remote_connection_count);
    if (ind_cxn_internal_errors) {
        aim_printf(pvs, "    Socket disconnects: %u\n",
                   ind_cxn_internal_errors);
    }

    FOREACH_ACTIVE_CXN(cxn_id, cxn) {
        cxn_count++;
        aim_printf(pvs, "Stats for%s%s connection %s:\n",
                   CXN_LOCAL(cxn) ? " local" : "",
                   CXN_LISTEN(cxn) ? " listening" : "",
                   cxn_ip_string(cxn));
        aim_printf(pvs, "    Id: %d.\n", cxn_id);
        aim_printf(pvs, "    State: %s.\n", CXN_HANDSHAKE_COMPLETE(cxn) ?
                   "Connected" : "Not connected");
        aim_printf(pvs, "    Packet ins: %"PRIu64"\n",
                   cxn->packet_ins);
        aim_printf(pvs, "    Packet in drops: %"PRIu64"\n",
                   cxn->status.packet_in_drop);

        aim_printf(pvs, "    Messages in, current connection: %"PRIu64"\n",
                   cxn->status.messages_in);
        counter = 0;
        for (idx = 0; idx < OF_MESSAGE_OBJECT_COUNT; idx++) {
            counter += cxn->messages_in_by_type[idx];
        }
        aim_printf(pvs, "    Cumulative messages in: %"PRIu64"\n", counter);
        if (details) {
            for (idx = 0; idx < OF_MESSAGE_OBJECT_COUNT; idx++) {
                if (cxn->messages_in_by_type[idx]) {
                    aim_printf(pvs, "        %s: %"PRIu64"\n",
                               of_object_id_str[idx],
                               cxn->messages_in_by_type[idx]);
                }
            }
        }
        if (cxn->messages_in_unknown) {
            aim_printf(pvs, "        Unknown type: %"PRIu64"\n",
                       cxn->messages_in_unknown);
        }

        aim_printf(pvs, "    Messages out, current connection: %"PRIu64"\n",
                   cxn->status.messages_out);
        counter = 0;
        for (idx = 0; idx < OF_MESSAGE_OBJECT_COUNT; idx++) {
            counter += cxn->messages_out_by_type[idx];
        }
        aim_printf(pvs, "    Cumulative messages out: %"PRIu64"\n", counter);
        if (details) {
            for (idx = 0; idx < OF_MESSAGE_OBJECT_COUNT; idx++) {
                if (cxn->messages_out_by_type[idx]) {
                    aim_printf(pvs, "        %s: %"PRIu64"\n",
                               of_object_id_str[idx],
                               cxn->messages_out_by_type[idx]);
                }
            }
        }
        if (cxn->messages_out_unknown) {
            aim_printf(pvs, "        Unknown type: %"PRIu64"\n",
                       cxn->messages_out_unknown);
        }
    }
    if (!cxn_count) {
        aim_printf(pvs, "No active connections\n");
    }
}

/**
 * Get OpenFlow version for async messages.
 */
indigo_error_t
indigo_cxn_get_async_version(of_version_t* of_version)
{
    indigo_cxn_id_t cxn_id;
    connection_t *cxn;

    /* See if there is any connection with role as MASTER */
    FOREACH_HS_COMPLETE_CXN_WITH_ROLE(cxn_id, cxn, INDIGO_CXN_R_MASTER) {
        *of_version = cxn->status.negotiated_version;
        return INDIGO_ERROR_NONE;
    }

    /* See if there is any connection with role as EQUAL */
    FOREACH_HS_COMPLETE_CXN_WITH_ROLE(cxn_id, cxn, INDIGO_CXN_R_EQUAL) {
        *of_version = cxn->status.negotiated_version;
        return INDIGO_ERROR_NONE;
    }

    /* See if there is any connection with role as SLAVE */
    FOREACH_HS_COMPLETE_CXN_WITH_ROLE(cxn_id, cxn, INDIGO_CXN_R_SLAVE) {
        *of_version = cxn->status.negotiated_version;
        return INDIGO_ERROR_NONE;
    }

    /* See if there is any connection with role as UNKNOWN, e.g. oftest */
    FOREACH_HS_COMPLETE_CXN_WITH_ROLE(cxn_id, cxn, INDIGO_CXN_R_UNKNOWN) {
        *of_version = cxn->status.negotiated_version;
        return INDIGO_ERROR_NONE;
    }

    return INDIGO_ERROR_NOT_FOUND;
}

