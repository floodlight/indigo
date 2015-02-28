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
#include <netdb.h>

#include "ofconnectionmanager_int.h"

static int init_done = 0;
static int module_enabled = 0;

static indigo_cxn_async_channel_selector_f ind_cxn_async_channel_selector_handler;

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

/**
 * Connection control blocks, indexed by connection index
 */
static connection_t connection[MAX_CONTROLLER_CONNECTIONS];

/**
 * Controller control blocks, indexed by controller index
 */
static controller_t controllers[MAX_CONTROLLERS];

#define INVALID_ID -1

/****************************************************************
 * Connection instance bookkeeping
 ****************************************************************/
#define CXN_ID_VALID(cxn_id)                                        \
    (((cxn_id) >= 0) && (CXN_ID_TO_INDEX(cxn_id) < MAX_CONTROLLER_CONNECTIONS))

#define CXN_TO_CXN_ID(cxn) ((cxn)->cxn_id)

/* Includes local connection */
#define FOREACH_ACTIVE_CXN(idx, cxn)                                    \
    for (idx = 0, cxn = &connection[0];                                 \
         idx < MAX_CONTROLLER_CONNECTIONS;                              \
         ++idx, cxn = &connection[idx])                                 \
        if (CXN_ACTIVE(cxn))

/* Only remote connections */
#define FOREACH_REMOTE_ACTIVE_CXN(idx, cxn)                             \
    for (idx = 0, cxn = &connection[0];                                 \
         idx < MAX_CONTROLLER_CONNECTIONS;                              \
         ++idx, cxn = &connection[idx])                                 \
        if (CXN_ACTIVE(cxn) && !CXN_LOCAL(cxn))

/* All remote main connections which completed hand-shake and with
 * requested role */
#define FOREACH_MAIN_HS_COMPLETE_CXN_WITH_ROLE(idx, cxn, cxn_role)      \
    for (idx = 0, cxn = &connection[0];                                 \
         idx < MAX_CONTROLLER_CONNECTIONS;                              \
         ++idx, cxn = &connection[idx])                                 \
        if (CXN_ACTIVE(cxn) && !CXN_LOCAL(cxn) &&                       \
            (cxn->auxiliary_id == 0) &&                                 \
            (cxn->controller->role == cxn_role) &&                      \
            (cxn->status.state == INDIGO_CXN_S_HANDSHAKE_COMPLETE))

/**
 * Convert connection ID to pointer to cxn block
 */

#define CXN_ID_TO_CONNECTION(cxn_id) cxn_id_to_connection(cxn_id)

static connection_t *
cxn_id_to_connection(indigo_cxn_id_t cxn_id)
{
    AIM_ASSERT(CXN_ID_TO_INDEX(cxn_id) < MAX_CONTROLLER_CONNECTIONS, "invalid connection ID");
    connection_t *cxn = &connection[CXN_ID_TO_INDEX(cxn_id)];
    if (cxn->cxn_id != cxn_id) {
        return NULL;
    }
    AIM_ASSERT(cxn->active);
    return cxn;
}

/****************************************************************
 * Controller instance bookkeeping
 ****************************************************************/
#define CONTROLLER_ID_VALID(id)                                         \
    (((id) >= 0) && ((id) < MAX_CONTROLLERS))

#define CONTROLLER_ID_ACTIVE(id)                                        \
    CONTROLLER_ACTIVE(&controllers[controller_id])

#define FOREACH_ACTIVE_CONTROLLER(id, ctrl)                             \
    for (id = 0, ctrl = &controllers[0];                                 \
         id < MAX_CONTROLLERS;                                          \
         ++id, ctrl = &controllers[id])                                  \
        if (CONTROLLER_ACTIVE(ctrl))

/* Only remote controllers */
#define FOREACH_REMOTE_ACTIVE_CONTROLLER(id, ctrl)                      \
    for (id = 0, ctrl = &controllers[0];                                 \
         id < MAX_CONTROLLERS;                                          \
         ++id, ctrl = &controllers[id])                                  \
        if (CONTROLLER_ACTIVE(ctrl) && !(ctrl->config_params.local))

/**
 * Convert controller ID to pointer to controller block
 */

#define ID_TO_CONTROLLER(id) (&controllers[id])


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
    AIM_LOG_TRACE("Soc %d ready, cxn %p. rd %d. wr %d. er %d",
                  socket_id, cookie, read_ready, write_ready, error_seen);

    if (!(CXN_ID_VALID(cxn->cxn_id))) {
        AIM_LOG_INTERNAL("Bad cxn callback %p", cxn);
        ++ind_cxn_internal_errors;
        return;
    }

    if (!(CXN_ACTIVE(cxn))) {
        AIM_LOG_INTERNAL("Socket ready callback on non active cxn %p", cxn);
        ++ind_cxn_internal_errors;
        return;
    }

    if (!(CXN_TCP_CONNECTED(cxn))) {
        AIM_LOG_INTERNAL("Socket ready callback on non connected cxn %p", cxn);
        ++ind_cxn_internal_errors;
        return;
    }

    INDIGO_ASSERT(cxn->controller != NULL);

    if (error_seen) {
        int socket_error = 0;
        socklen_t len = sizeof(socket_error);
        getsockopt(cxn->sd, SOL_SOCKET, SO_ERROR, &socket_error, &len);
        AIM_LOG_ERROR("Error seen on connection " CXN_FMT ": %s",
                      CXN_FMT_ARGS(cxn), strerror(socket_error));
        ind_controller_disconnect(cxn->controller);
        ++ind_cxn_internal_errors;
        return;
    }

    if (read_ready) {
        if ((rv = ind_cxn_process_read_buffer(cxn)) < 0) {
            AIM_LOG_VERBOSE("Error processing read buffer, resetting");
            ind_controller_disconnect(cxn->controller);
            return;
        }
    }

    if (write_ready) {
        if ((rv = ind_cxn_process_write_buffer(cxn)) < 0) {
            AIM_LOG_ERROR("Error processing write buffer, resetting");
            ind_controller_disconnect(cxn->controller);
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
		 get_connection_params(cxn),
		 cxn->status.state,
		 cookie
		 );
    }

    if (!CXN_LOCAL(cxn)) {
        if (CONNECTION_STATE(cxn) == INDIGO_CXN_S_CONNECTING) {
            ++remote_connection_count;
        } if (CONNECTION_STATE(cxn) == INDIGO_CXN_S_HANDSHAKE_COMPLETE) {
            ind_cxn_status_notify();
        } else if (CONNECTION_STATE(cxn) == INDIGO_CXN_S_CLOSING) {
            --remote_connection_count;
            ind_cxn_status_notify();
        }
    }

    AIM_LOG_TRACE("Cxn status change, rmt count %d", remote_connection_count);
}

/*
 * Send an of_bsn_controller_connections_reply to each connection
 *
 * HACK reusing the reply message for this async notification.
 */

void
ind_cxn_status_notify(void)
{
    of_version_t version;

    if (indigo_cxn_get_async_version(&version) < 0) {
        return;
    }

    if (version < OF_VERSION_1_3) {
        return;
    }

    of_object_t *msg = of_bsn_controller_connections_reply_new(version);
    AIM_TRUE_OR_DIE(msg != NULL);

    of_list_bsn_controller_connection_t list;
    of_bsn_controller_connections_reply_connections_bind(msg, &list);

    ind_cxn_populate_connection_list(&list);

    indigo_cxn_send_async_message(msg);
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

    INDIGO_MEM_CLEAR(controllers, sizeof(controllers));
    INDIGO_MEM_CLEAR(connection, sizeof(connection));
    INDIGO_MEM_CLEAR(status_change, sizeof(status_change));
    for (idx = 0; idx < MAX_CONTROLLERS; ++idx) {
        controllers[idx].controller_id = (indigo_controller_id_t)idx;
    }
    for (idx = 0; idx < MAX_CONTROLLER_CONNECTIONS; ++idx) {
        connection[idx].cxn_id = (indigo_cxn_id_t)idx; /* Zero generation ID */
        connection[idx].write_queue = bigring_create(WRITE_QUEUE_SIZE, NULL);
    }

    ind_cfg_register(&ind_cxn_cfg_ops);

    ind_cxn_generation_id = 0;

    AIM_LOG_VERBOSE("Initial generation id: 0x%016"PRIx64, ind_cxn_generation_id);

    return INDIGO_ERROR_NONE;
}

static connection_t *
find_free_connection(void) {
    int idx;
    for (idx = 0; idx < MAX_CONTROLLER_CONNECTIONS; ++idx) {
        if (!connection[idx].active) {
            return &connection[idx];
        }
    }

    return NULL;
}

static indigo_controller_id_t
find_free_controller(void) {
    int idx;
    for (idx = 0; idx < MAX_CONTROLLERS; ++idx) {
        if (!controllers[idx].active) {
            return (indigo_controller_id_t)idx;
        }
    }

    return INVALID_ID;
}

/* @fixme What should the cxn backlog be? */
#define LOCAL_CXN_BACKLOG 5

/**
 * Initialize a local connection instance
 */
static int
listen_cxn_init(connection_t *cxn)
{
    struct sockaddr_storage cxn_addr;
    indigo_error_t rv;
    indigo_cxn_protocol_params_t *protocol_params;

    AIM_LOG_VERBOSE("Initializing listening socket");

    protocol_params = get_connection_params(cxn);
    INDIGO_ASSERT(protocol_params != NULL);

    if (ind_cxn_parse_sockaddr(protocol_params, &cxn_addr) < 0) {
        return INDIGO_ERROR_UNKNOWN;
    }

    /* bind the socket to the port number */
    if (bind(cxn->sd, (struct sockaddr *) &cxn_addr, sizeof(cxn_addr)) == -1) {
        AIM_LOG_ERROR("Could not bind to socket for local cxn: %s", strerror(errno));
        return INDIGO_ERROR_UNKNOWN;
    }

    /* show that we are willing to listen */
    if (listen(cxn->sd, LOCAL_CXN_BACKLOG) == -1) {
        AIM_LOG_ERROR("Could not listen to socket for local cxn: %s", strerror(errno));
        return INDIGO_ERROR_UNKNOWN;
    }

    /* Register the socket */
    rv = ind_soc_socket_register_with_priority(
            cxn->sd, ind_cxn_listen_socket_ready,
            cxn, IND_CXN_EVENT_PRIORITY);
    if (rv < 0) {
        AIM_LOG_INTERNAL("Could not register with socket manager: %s", indigo_strerror(rv));
        return INDIGO_ERROR_UNKNOWN;
    }

    /* Register with the scoket manager */

    return INDIGO_ERROR_NONE;
}


/**
 * Set up a connection instance.
 * @param sd If >=0, use this socket id; otherwise call socket().
 *
 * Typically, sd is >= 0 when this comes from an accept call.
 */

static connection_t *
connection_socket_setup(indigo_controller_id_t controller_id,
                        indigo_cxn_id_t *cxn_id, int sd)
{
    int soc_flags;
    connection_t *cxn;
    controller_t *ctrl;
    struct sockaddr_storage sockaddr;

    cxn = find_free_connection();
    if (cxn == NULL) {
        AIM_LOG_INTERNAL("Could not allocate space for connection");
        return NULL;
    }

    *cxn_id = cxn->cxn_id;

    ctrl = ID_TO_CONTROLLER(controller_id);

    /* Initialize connection structure */
    INDIGO_MEM_CLEAR(&cxn->status, sizeof(cxn->status));
    cxn->controller = ctrl;

    if (!CXN_LOCAL(cxn)) {
        cxn->keepalive.period_ms = ctrl->config_params.periodic_echo_ms;
        cxn->keepalive.threshold = ctrl->config_params.reset_echo_count;
    } else {
        cxn->keepalive.period_ms = 0;
        cxn->keepalive.threshold = 0;
    }

    ind_cxn_disconnected_init(cxn);

    /* Parsed the protocol params just to get the family */
    if (ind_cxn_parse_sockaddr(&ctrl->protocol_params, &sockaddr) < 0) {
        return NULL;
    }

    if (sd < 0) {
        /* Attempt to create the socket */
        cxn->sd = socket(sockaddr.ss_family, SOCK_STREAM, 0);
        if (cxn->sd < 0) {
            AIM_LOG_ERROR("Failed to create connection socket: %s", strerror(errno));
            return NULL;
        }
    } else {
        cxn->sd = sd;
    }

    soc_flags = fcntl(cxn->sd, F_GETFL, 0);
    if (soc_flags == -1 || fcntl(cxn->sd, F_SETFL,
                                 soc_flags | O_NONBLOCK) == -1) {
        AIM_LOG_ERROR("Failed to set non-blocking flag for socket: %s", strerror(errno));
        close(cxn->sd);
        return NULL;
    }

    /* Disable Nagle's algorithm */
    {
        int flag = 1;
        (void) setsockopt(cxn->sd, IPPROTO_TCP, TCP_NODELAY,
                          (char *) &flag, sizeof(int));
    }

    AIM_LOG_VERBOSE("Created non-blocking socket %d for " CXN_FMT,
                    cxn->sd, CXN_FMT_ARGS(cxn));

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


/* Add a connection instance */

static indigo_error_t
ind_cxn_connection_add(indigo_controller_id_t controller_id,
                       uint8_t auxiliary_id, indigo_cxn_id_t *cxn_id)
{
    connection_t *cxn = NULL;
    indigo_error_t rv = INDIGO_ERROR_NONE;
    controller_t *ctrl = ID_TO_CONTROLLER(controller_id);

    AIM_LOG_VERBOSE("Connection add: %s:%d",
                    proto_ip_string(&ctrl->protocol_params),
                    auxiliary_id);

    INDIGO_ASSERT(cxn_id != NULL);

    cxn = connection_socket_setup(controller_id, cxn_id, -1);

    if (cxn == NULL) {
        AIM_LOG_ERROR("Could not set up connection");
        return INDIGO_ERROR_RESOURCE;
    } else {
        if (CXN_LISTEN(cxn)) {
            rv = listen_cxn_init(cxn);
            if (rv != INDIGO_ERROR_NONE) {
                /* @fixme clean up connection? */
                cxn->active = 0;
            }
        } else {
            /* Aux id is only relevant for remote connections */
            cxn->auxiliary_id = auxiliary_id;

            /* Aux cxns have a different echo frequency than main connection */
            if (auxiliary_id != 0) {
                cxn->keepalive.period_ms = IND_AUX_CXN_PERIODIC_ECHO_MS_DEFAULT;
            }
        }
    }

    return rv;
}


/* Look for a controller connection with the given params and remove it */
static indigo_error_t
ind_cxn_connection_remove(indigo_cxn_id_t cxn_id)
{
    connection_t *cxn = cxn_id_to_connection(cxn_id);

    if (!cxn) {
        AIM_LOG_INTERNAL("Attempted to remove nonexistent connection " CXN_ID_FMT,
                         CXN_ID_FMT_ARGS(cxn_id));
        return INDIGO_ERROR_NOT_FOUND;
    }

    AIM_LOG_VERBOSE("Connection remove: " CXN_FMT, CXN_FMT_ARGS(cxn));

    if (CONNECTION_STATE(cxn) != INDIGO_CXN_S_DISCONNECTED) {
        cxn->flags |= CXN_TO_BE_REMOVED;
        ind_cxn_disconnect(cxn);
    } else {
        ind_soc_timer_event_unregister(ind_cxn_connection_retry_timer, cxn);
        ind_cxn_disconnect(cxn);
        cxn->active = 0;
    }

    /* @fixme If no connections active, turn off periodic timeout */

    return INDIGO_ERROR_NONE;
}

/**
 * Remove extra auxiliary connections for this controller and set the new
 * number of aux cxn's to num_aux
 *
 * If num_aux is set to zero, it would mean tear down request for all
 * aux cxn's associated with this controller
 */

static indigo_error_t
ind_aux_connection_remove(controller_t *ctrl, uint32_t num_aux)
{
    int idx;
    uint32_t num_aux_current;
    indigo_error_t ret;

    if (!CONTROLLER_ACTIVE(ctrl)) return INDIGO_ERROR_UNKNOWN;

    if (num_aux == ctrl->num_aux) return INDIGO_ERROR_NONE;

    if (num_aux > ctrl->num_aux) {
        AIM_LOG_TRACE("Requested num_aux %d is greater than current aux cxn's "
                      "for controller %s", num_aux, proto_ip_string(
                      &ctrl->protocol_params));
        return INDIGO_ERROR_PARAM;
    }

    AIM_LOG_VERBOSE("Aux cxn's for controller %s, changed from %d to %d",
                    proto_ip_string(&ctrl->protocol_params), ctrl->num_aux, num_aux);
    num_aux_current = ctrl->num_aux;
    ctrl->num_aux = num_aux;

    for (idx = num_aux_current; idx > num_aux; --idx) {
        ret = ind_cxn_connection_remove(ctrl->aux_id_to_cxn_id[idx]);
        if (ret < 0) return ret;
        ctrl->aux_id_to_cxn_id[idx] = INVALID_ID;
    }

    return INDIGO_ERROR_NONE;

}

/**
 * Set up num_aux auxiliary connections for controller associated
 * with this main connection
 *
 * If num_aux requested is greater than aux cxn's we already have,
 * teardown extra aux cxn's
 */

int
ind_aux_connection_add(connection_t *cxn, uint32_t num_aux)
{
    int idx;
    indigo_cxn_id_t cxn_id;

    AIM_ASSERT(cxn != NULL);

    if (num_aux > MAX_AUX_CONNECTIONS) {
        AIM_LOG_WARN("Requested number of auxiliary connections %d is greater than supported %d",
                     num_aux, MAX_AUX_CONNECTIONS);
        return 1;
    }

    /* Check to make sure this is not a local connection */
    if (CXN_LOCAL(cxn)) {
        AIM_LOG_WARN("Aux cxn request received on local connection " CXN_FMT,
                     CXN_FMT_ARGS(cxn));
        return 1;
    }

    /* Check if this is the main connection of the attached controller */
    if (cxn->auxiliary_id != 0) {
        AIM_LOG_WARN("Aux cxn request received on non main connection " CXN_FMT ", "
                     "with aux id %d", CXN_FMT_ARGS(cxn), cxn->auxiliary_id);
        return 1;
    }

    if (num_aux == cxn->controller->num_aux) {
        AIM_LOG_TRACE("Requested num_aux %d is equal to current aux cxn's for "
                      "controller " CXN_FMT, num_aux, CXN_FMT_ARGS(cxn));
        return 0;
    } else if (num_aux < cxn->controller->num_aux) {
        AIM_LOG_TRACE("Requested num_aux %d is less than current aux cxn's %d for "
                      "controller " CXN_FMT, num_aux, cxn->controller->num_aux,
                      CXN_FMT_ARGS(cxn));

        if (ind_aux_connection_remove(cxn->controller, num_aux) < 0) {
            return 1;
        }
    } else {

        for (idx = cxn->controller->num_aux+1; idx <= num_aux; ++idx) {
            if (ind_cxn_connection_add(cxn->controller->controller_id, idx,
                                       &cxn_id) < 0) return 1;
            cxn->controller->aux_id_to_cxn_id[idx] = cxn_id;
        }

        AIM_LOG_VERBOSE("Number of auxiliary connections for controller " CXN_FMT " changed from %d to %d",
                        CXN_FMT_ARGS(cxn), cxn->controller->num_aux, num_aux);
        cxn->controller->num_aux = num_aux;
    }

    return 0;
}

/**
 * Add a Controller instance and create the main connection with the
 * controller using auxiliary_id = 0
 */

indigo_error_t
indigo_controller_add(indigo_cxn_protocol_params_t *protocol_params,
                      indigo_cxn_config_params_t *config_params,
                      indigo_controller_id_t *controller_id)
{
    indigo_cxn_id_t cxn_id;
    controller_t *ctrl;
    indigo_error_t rv = INDIGO_ERROR_NONE;

    INDIGO_ASSERT(protocol_params != NULL);
    INDIGO_ASSERT(config_params != NULL);
    INDIGO_ASSERT(controller_id != NULL);

    if (config_params->local &&
        (config_params->periodic_echo_ms ||
         config_params->reset_echo_count)) {
        AIM_LOG_INTERNAL("Local connection with nonzero echo params on cxn add");
        return INDIGO_ERROR_PARAM;
    }

    if (protocol_params->header.protocol != INDIGO_CXN_PROTO_TCP_OVER_IPV4 &&
        protocol_params->header.protocol != INDIGO_CXN_PROTO_TCP_OVER_IPV6) {
        AIM_LOG_INTERNAL("Unsupported protocol for connection add: %d",
                         protocol_params->header.protocol);
        return INDIGO_ERROR_NOT_SUPPORTED;
    }

    *controller_id = find_free_controller();
    if (INDIGO_CONTROLLER_INVALID(*controller_id)) {
        AIM_LOG_INTERNAL("Could not allocate space for controller");
        return INDIGO_ERROR_RESOURCE;
    }

    AIM_LOG_INFO("Controller add: %s (%s, v%d)",
                 proto_ip_string(protocol_params),
                 config_params->listen ? "listen" : "remote",
                 config_params->version);

    ctrl = ID_TO_CONTROLLER(*controller_id);

    /* Initialize controller structure */
    INDIGO_MEM_COPY(&ctrl->protocol_params, protocol_params,
                    sizeof(*protocol_params));
    INDIGO_MEM_COPY(&ctrl->config_params, config_params,
                    sizeof(*config_params));

    /* Create the main connection with auxiliary id = 0 */
    rv = ind_cxn_connection_add(*controller_id, 0, &cxn_id);
    if (rv < 0) return rv;

    ctrl->active = 1;
    ctrl->aux_id_to_cxn_id[0] = cxn_id;
    ctrl->ephemeral = 0;

    return rv;
}

/**
 * Remove the controller indexed by controller id
 * This will remove all the connections corresponding to this controller
 * i.e. both the main connection and any auxiliary connections available
 */

indigo_error_t
indigo_controller_remove(indigo_controller_id_t controller_id)
{
    indigo_error_t rv = INDIGO_ERROR_NONE;
    controller_t *ctrl = NULL;

    if (!CONTROLLER_ID_VALID(controller_id) ||
        !CONTROLLER_ID_ACTIVE(controller_id)) {
        AIM_LOG_INTERNAL("Remove controller id %d invalid or not active",
                         controller_id);
        return INDIGO_ERROR_PARAM;
    }

    ctrl = ID_TO_CONTROLLER(controller_id);
    AIM_LOG_INFO("Controller remove: %s", proto_ip_string(&ctrl->protocol_params));

    /* Remove all the aux connections first */
    rv = ind_aux_connection_remove(ctrl, 0);
    if (rv < 0) {
        return rv;
    }

    /* Remove the main connection */
    rv = ind_cxn_connection_remove(ctrl->aux_id_to_cxn_id[0]);
    if (rv < 0) {
        return rv;
    }

    ctrl->aux_id_to_cxn_id[0] = INVALID_ID;
    ctrl->active = 0;
    return rv;
}

/* Return the config of a specific connection */
indigo_error_t
indigo_cxn_connection_config_get(
    indigo_cxn_id_t cxn_id,
    indigo_cxn_config_params_t *config)
{
    connection_t *cxn = CXN_ID_TO_CONNECTION(cxn_id);

    if (!cxn) {
        AIM_LOG_INTERNAL("Attempted to get config for nonexistent connection " CXN_ID_FMT,
                         CXN_ID_FMT_ARGS(cxn_id));
        return INDIGO_ERROR_NOT_FOUND;
    }

    INDIGO_ASSERT(cxn->controller != NULL);

    INDIGO_MEM_COPY(config, &cxn->controller->config_params, sizeof(*config));

    return INDIGO_ERROR_NONE;
}

/* Return the status of a specific connection */
indigo_error_t
indigo_cxn_connection_status_get(
    indigo_cxn_id_t cxn_id,
    indigo_cxn_status_t *status)
{
    connection_t *cxn = CXN_ID_TO_CONNECTION(cxn_id);

    if (!cxn) {
        AIM_LOG_INTERNAL("Attempted to get status for nonexistent connection " CXN_ID_FMT,
                         CXN_ID_FMT_ARGS(cxn_id));
        return INDIGO_ERROR_NOT_FOUND;
    }

    INDIGO_MEM_COPY(status, &cxn->status, sizeof(*status));

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
    INDIGO_ASSERT(cxn->controller->role == INDIGO_CXN_R_SLAVE);

    if (cxn->status.negotiated_version == OF_VERSION_1_3) {
        of_bsn_role_status_t *msg = of_bsn_role_status_new(OF_VERSION_1_3);
        if (msg == NULL) {
            AIM_DIE("Failed to allocate role status message");
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
ind_controller_change_master(indigo_controller_id_t master_id)
{
    controller_t *ctrl;
    int id;

    FOREACH_REMOTE_ACTIVE_CONTROLLER(id, ctrl) {
        if (ctrl->controller_id == master_id) {
            AIM_LOG_INFO("Upgrading controller %s role to master",
                         proto_ip_string(&ctrl->protocol_params));
            ctrl->role = INDIGO_CXN_R_MASTER;
        } else if (ctrl->role == INDIGO_CXN_R_MASTER) {
            AIM_LOG_INFO("Downgrading controller %s role to slave",
                         proto_ip_string(&ctrl->protocol_params));
            ctrl->role = INDIGO_CXN_R_SLAVE;
            ind_cxn_send_role_status(
                CXN_ID_TO_CONNECTION(ctrl->aux_id_to_cxn_id[0]),
                OFP_BSN_CONTROLLER_ROLE_REASON_MASTER_REQUEST);
        }
    }
}

void
ind_cxn_populate_connection_list(of_list_bsn_controller_connection_t *list)
{
    int idx;
    connection_t *cxn;
    indigo_cxn_protocol_params_t *protocol_params;
    FOREACH_REMOTE_ACTIVE_CXN(idx, cxn) {
        of_bsn_controller_connection_t entry;
        of_desc_str_t uri;
        uint32_t role;

        of_bsn_controller_connection_init(&entry, list->version, -1, 1);
        if (of_list_bsn_controller_connection_append_bind(list, &entry) < 0) {
            AIM_LOG_INTERNAL("Failed to append controller connection to list");
            break;
        }

        if (CXN_HANDSHAKE_COMPLETE(cxn)) {
            of_bsn_controller_connection_state_set(&entry, 1);
        } else {
            of_bsn_controller_connection_state_set(&entry, 0);
        }

        of_bsn_controller_connection_auxiliary_id_set(&entry, cxn->auxiliary_id);

        switch (cxn->controller->role) {
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

        protocol_params = get_connection_params(cxn);
        INDIGO_ASSERT(protocol_params != NULL);

        if (protocol_params->header.protocol == INDIGO_CXN_PROTO_TCP_OVER_IPV4) {
            indigo_cxn_params_tcp_over_ipv4_t *proto =
                &protocol_params->tcp_over_ipv4;
            snprintf(uri, sizeof(uri), "tcp://%s:%d",
                proto->controller_ip, proto->controller_port);
        } else if (protocol_params->header.protocol == INDIGO_CXN_PROTO_TCP_OVER_IPV6) {
            indigo_cxn_params_tcp_over_ipv6_t *proto =
                &protocol_params->tcp_over_ipv6;
            snprintf(uri, sizeof(uri), "tcp://[%s]:%d",
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

/*
 * Decide which messages can be dropped due to a long write queue
 */
static bool
cxn_message_is_noncritical(of_object_id_t object_id)
{
    switch (object_id) {
    case OF_FLOW_REMOVED: return true;
    case OF_PACKET_IN: return true;
    case OF_BSN_FLOW_IDLE: return true;
    case OF_BSN_ARP_IDLE: return true;
    case OF_BSN_PDU_RX_TIMEOUT: return true;
    default: return false;
    }
}

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
        AIM_LOG_INTERNAL("Invalid or no active connection: %d", cxn_id);
        goto done;
    }

    cxn = CXN_ID_TO_CONNECTION(cxn_id);
    if (!cxn || !CXN_TCP_CONNECTED(cxn)) {
        AIM_LOG_VERBOSE("Attempted to send %s message to disconnected connection " CXN_ID_FMT,
                        of_object_id_str[obj->object_id], CXN_ID_FMT_ARGS(cxn_id));
        goto done;
    }

    xid = of_message_xid_get(OF_BUFFER_TO_MESSAGE(OF_OBJECT_BUFFER_INDEX(obj, 0)));

    AIM_LOG_VERBOSE("cxn " CXN_FMT ": Sending %s message xid %u",
                    CXN_FMT_ARGS(cxn), of_object_id_str[obj->object_id], xid);

    if(cxn->trace_pvs) {
        aim_printf(cxn->trace_pvs, "** of_msg_trace: send to cxn=%d\n", cxn->cxn_id);
        of_object_dump((loci_writer_f)aim_printf, cxn->trace_pvs, obj);
        aim_printf(cxn->trace_pvs, "**\n\n");
    }


    if (!CXN_HANDSHAKE_COMPLETE(cxn)) {
        if (IS_ASYNC_MSG(obj)) {
            AIM_LOG_TRACE("Handshake not complete; drop async msg %s",
                          of_object_id_str[obj->object_id]);
            goto done;
        }
    }

    /* Drop noncritical messages before the write buffer fills up completely */
    if (cxn->pkts_enqueued > NONCRITICAL_DROP_THRESHOLD) {
        if (cxn_message_is_noncritical(obj->object_id)) {
            AIM_LOG_TRACE("Dropping noncritical %s message", of_object_id_str[obj->object_id]);
            debug_counter_inc(&cxn->tx_drop_counter);
            goto done;
        }
    }

    /* Steal the buffer and enqueue the data */
    LOG_OBJECT(obj);

    of_object_wire_buffer_steal((of_object_t *)obj, &data);
    len = obj->length;

    AIM_ASSERT(IS_MSG_OBJ(obj));
    debug_counter_inc(&cxn->tx_counters[obj->object_id]);

    if (ind_cxn_instance_enqueue(cxn, data, len) < 0) {
        AIM_LOG_ERROR("Could not enqueue %s message data to cxn " CXN_FMT ", disconnecting",
                      of_object_id_str[obj->object_id], CXN_FMT_ARGS(cxn));
        aim_free(data);
        ind_controller_disconnect(cxn->controller);
    }

    if (obj->object_id == OF_FEATURES_REPLY) {
        if (CONNECTION_STATE(cxn) == INDIGO_CXN_S_CONNECTING) {
            ++successful_handshakes;
            ind_cxn_state_set(cxn, INDIGO_CXN_S_HANDSHAKE_COMPLETE);
        }
    }

 done:
    of_object_delete(obj);
}

/**
 * Check whether the given connection is interested in the message.
 */
int
ind_cxn_accepts_async_message(const connection_t *cxn)
{
    if (!CXN_ACTIVE(cxn)) {
        return 0;
    }

    if (CONNECTION_STATE(cxn) != INDIGO_CXN_S_HANDSHAKE_COMPLETE) {
        return 0;
    }

    if (CXN_LOCAL(cxn)) {
        return 0;
    }

    return 1;
}

/**
 * Check whether the given controller is interested in the message.
 */
int
ind_controller_accepts_async_message(const controller_t *ctrl,
                                     const of_object_t *obj,
                                     connection_t **cxn)
{
    uint8_t auxiliary_id = 0;

    /* Only send certain async messages to the slave */
    if (ctrl->role == INDIGO_CXN_R_SLAVE &&
        obj->object_id != OF_PORT_STATUS &&
        obj->object_id != OF_BSN_CONTROLLER_CONNECTIONS_REPLY) {
        return 0;
    }

    if (ind_cxn_async_channel_selector_handler != NULL) {
        (*ind_cxn_async_channel_selector_handler)(obj, ctrl->num_aux,
                                                  &auxiliary_id);
    }

    INDIGO_ASSERT(auxiliary_id <= ctrl->num_aux);

    /* If there is no selector for this application or the selected
       channel is not ready for communication, then we should just try
       to send on the main controller connection */
    *cxn = CXN_ID_TO_CONNECTION(ctrl->aux_id_to_cxn_id[auxiliary_id]);
    AIM_ASSERT(*cxn != NULL);
    if (ind_cxn_accepts_async_message(*cxn) == 0) {
        if (auxiliary_id != 0) {
            AIM_LOG_TRACE("cxn: " CXN_FMT " state: %s, not ready, try on main cxn",
                          CXN_FMT_ARGS(*cxn),
                          CXN_STATE_NAME(CONNECTION_STATE(*cxn)));
            auxiliary_id = 0;
            *cxn = CXN_ID_TO_CONNECTION(ctrl->aux_id_to_cxn_id[auxiliary_id]);
            AIM_ASSERT(*cxn != NULL);
            if (ind_cxn_accepts_async_message(*cxn) == 0) {
                return 0;
            }
        } else {
            return 0;
        }
    }

    AIM_LOG_TRACE("Selected aux_id: %d, cxn: " CXN_FMT " for async %s message", auxiliary_id,
                  CXN_FMT_ARGS(*cxn), of_object_id_str[obj->object_id]);

    return 1;
}

/**
 * Send an async message to all interested connections.
 */
void
indigo_cxn_send_async_message(of_object_t *obj)
{
    connection_t *cxn;
    controller_t *ctrl;
    int id;

    /*
     * The connection that will end up sending the original 'obj',
     * rather than a duplicate. indigo_cxn_send_controller_message
     * consumes the LOCI object so we need to call it on the
     * original last.
     */
    indigo_cxn_id_t first_cxn_id = INDIGO_CXN_ID_UNSPECIFIED;

    FOREACH_REMOTE_ACTIVE_CONTROLLER(id, ctrl) {
        if (ind_controller_accepts_async_message(ctrl, obj, &cxn) &&
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
        AIM_LOG_VERBOSE("Dropping async %s message, no interested connections",
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

    AIM_LOG_TRACE("Register status callback %p, cookie %p",
                  handler, cookie);
    if (handler == NULL) {
        AIM_LOG_INTERNAL("Cannot register NULL status change fn");
        return INDIGO_ERROR_PARAM;
    }
    for (idx = 0; idx < MAX_STATUS_CHANGE_CALLBACKS; ++idx) {
        if (status_change[idx].callback == NULL) {
            status_change[idx].callback = handler;
            status_change[idx].cookie = cookie;
            return INDIGO_ERROR_NONE;
        }
    }

    AIM_LOG_INTERNAL("Could not find free slot for status change callback");
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

    AIM_LOG_TRACE("Unregister status callback %p, cookie %p",
                  handler, cookie);
    FOREACH_STATUS_CALLBACK(idx, fn, ck) {
        if ((fn == handler) && (ck == cookie)) {
            status_change[idx].callback = NULL;
            return INDIGO_ERROR_NONE;
        }
    }

    AIM_LOG_TRACE("Did not find status change callback fn");
    return INDIGO_ERROR_NONE;
}


/****************************************************************
 * Implementation specific functions
 ****************************************************************/


/*
 * Configure the connection manager
 * @param core The functions provided by core
 * @returns An error code
 *
 */

indigo_error_t
ind_cxn_init(ind_cxn_config_t *config)
{
    AIM_LOG_TRACE("Cxn init called");

    if (config == NULL) {
        AIM_LOG_INTERNAL("NULL configuration parameter");
        return INDIGO_ERROR_PARAM;
    }

    /* Verify required functions are non-NULL */
    INDIGO_MEM_COPY(&cxn_config, config, sizeof(*config));

    module_init();

    init_done = 1;

    ind_cxn_async_channel_selector_handler = NULL;

    return INDIGO_ERROR_NONE;
}

/**
 * Enable the connection manager
 */
indigo_error_t
ind_cxn_enable_set(int enable)
{
    AIM_LOG_TRACE("OF connection mgr enable called");

    if (!init_done) {
        return INDIGO_ERROR_INIT;
    }

    if (enable && !module_enabled) {
        AIM_LOG_VERBOSE("Enabling OF connection mgr");
        module_enabled = 1;
        ofconnectionmanager_config_commit();
    } else if (!enable && module_enabled) {
        int id;
        controller_t *ctrl;
        AIM_LOG_VERBOSE("Disabling OF connection mgr");
        /* unregister state timeout handlers */
        FOREACH_ACTIVE_CONTROLLER(id, ctrl) {
            ind_controller_disconnect(ctrl);
        }
        module_enabled = 0;
        /* @todo Anything need to be done here? */
    } else {
        AIM_LOG_VERBOSE("Redundant enable call.  Currently %s",
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
    AIM_LOG_TRACE("Indigo connection manager finish");
    ind_cxn_enable_set(0);
    ind_cxn_async_channel_selector_handler = NULL;
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

    connection_t *cxn = CXN_ID_TO_CONNECTION(cxn_id);
    if (cxn == NULL) {
        AIM_LOG_ERROR("Attempted to send error message to nonexistent connection " CXN_ID_FMT,
                      CXN_ID_FMT_ARGS(cxn_id));
        return;
    }

    payload.data = OF_OBJECT_BUFFER_INDEX(orig, 0);
    payload.bytes = orig->length;

    xid = of_message_xid_get(OF_BUFFER_TO_MESSAGE(payload.data));

    AIM_LOG_TRACE("Sending error msg to " CXN_FMT ". type %d. code %d.",
                  CXN_FMT_ARGS(cxn), type, code);

    if ((msg = of_hello_failed_error_msg_new(orig->version)) == NULL) {
        AIM_DIE("Could not allocate error message");
    }

    of_hello_failed_error_msg_xid_set(msg, xid);
    of_hello_failed_error_msg_code_set(msg, code);

    if (of_hello_failed_error_msg_data_set(msg, &payload) < 0) {
        AIM_LOG_INTERNAL("Failed to append original request to error message");
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
    indigo_controller_id_t controller_id;
    controller_t *ctrl;

    listen_cxn = (connection_t *)cookie;

    AIM_LOG_TRACE("Lcl soc %d ready, cxn %p. rd %d. wr %d. er %d",
                  socket_id, cookie, read_ready, write_ready, error_seen);

    if (!(CXN_ID_VALID(listen_cxn->cxn_id))) {
        AIM_LOG_INTERNAL("Bad cxn callback %p", listen_cxn);
        ++ind_cxn_internal_errors;
        return;
    }

    if (!(CXN_ACTIVE(listen_cxn))) {
        AIM_LOG_INTERNAL("Socket ready callback on non active cxn %p", listen_cxn);
        ++ind_cxn_internal_errors;
        return;
    }

    INDIGO_ASSERT(listen_cxn->controller != NULL);
    INDIGO_ASSERT(listen_cxn->sd == socket_id);

    if (error_seen) {
        AIM_LOG_ERROR("Error seen on connection " CXN_FMT, CXN_FMT_ARGS(listen_cxn));
        /* @todo What to do on socket error */
        ++ind_cxn_internal_errors;
        /* Close the socket? */
        return;
    }

    /* Ready for an accept */
    if (!read_ready) {
        AIM_LOG_ERROR("Error: read not ready for connection " CXN_FMT,
                      CXN_FMT_ARGS(listen_cxn));
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
        AIM_LOG_ERROR("Error on accept for local cxn: %s", strerror(errno));
        ++ind_cxn_internal_errors;
        return;
    }
    AIM_LOG_VERBOSE("New cxn instance, port %d", ntohs(cxn_addr.sin_port));

    controller_id = find_free_controller();
    if (INDIGO_CONTROLLER_INVALID(controller_id)) {
        AIM_LOG_INTERNAL("Could not allocate space for controller");
        return;
    }

    ctrl = ID_TO_CONTROLLER(controller_id);

    /* Initialize controller structure */
    INDIGO_MEM_COPY(&ctrl->protocol_params, &listen_cxn->controller->protocol_params,
                    sizeof(ctrl->protocol_params));
    INDIGO_MEM_COPY(&ctrl->config_params, &listen_cxn->controller->config_params,
                    sizeof(ctrl->config_params));

    /* Okay, add the new connection with the socket */
    cxn = connection_socket_setup(ctrl->controller_id, &cxn_id, new_sd);

    if (cxn == NULL) {
        AIM_LOG_ERROR("Could not set up accepted connection");
        /* @fixme clean up? */
        return;
    }

    /* Inherit the tracer - move to config_params? */
    cxn->trace_pvs = listen_cxn->trace_pvs;

    ctrl->active = 1;
    ctrl->aux_id_to_cxn_id[0] = cxn_id;
    ctrl->ephemeral = 1;
}

indigo_error_t
ind_cxn_message_trace(indigo_cxn_id_t cxn_id, aim_pvs_t* pvs)
{
    connection_t *cxn;
    int idx;
    FOREACH_ACTIVE_CXN(idx, cxn) {
        if(cxn_id == -1 || cxn_id == cxn->cxn_id) {
            cxn->trace_pvs = pvs;
            if(cxn_id == cxn->cxn_id) {
                break;
            }
        }
    }
    return INDIGO_ERROR_NONE;
}

void
indigo_controller_list(indigo_controller_info_t** list)
{
    indigo_controller_info_t* head = NULL;
    indigo_controller_id_t id;
    controller_t *ctrl;
    FOREACH_ACTIVE_CONTROLLER(id, ctrl) {
        indigo_controller_info_t* entry = aim_malloc(sizeof(*entry));
        AIM_TRUE_OR_DIE(entry != NULL);
        entry->controller_id = id;
        entry->role = ctrl->role;
        entry->protocol_params = ctrl->protocol_params;
        entry->config_params = ctrl->config_params;
        entry->num_aux = ctrl->num_aux;
        entry->main_cxn_id = ctrl->aux_id_to_cxn_id[0];
        entry->next = head;
        head = entry;
    }
    *list = head;
}

void
indigo_controller_list_destroy(indigo_controller_info_t* list)
{
    indigo_controller_info_t* e = list;
    while(e) {
        indigo_controller_info_t* link = e->next;
        aim_free(e);
        e = link;
    }
}

indigo_error_t
indigo_cxn_list(indigo_cxn_info_t** list)
{
    indigo_cxn_info_t* head = NULL;
    int idx;
    connection_t *cxn;
    FOREACH_ACTIVE_CXN(idx, cxn) {
        indigo_cxn_info_t* entry = aim_malloc(sizeof(*entry));
        entry->cxn_id = cxn->cxn_id;
        entry->cxn_status = cxn->status;
        entry->cxn_proto_params = cxn->controller->protocol_params;
        entry->cxn_config_params = cxn->controller->config_params;
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
    controller_t *ctrl;

    if (!module_enabled) {
        return;
    }

    AIM_LOG_VERBOSE("Connection reset for id " CXN_ID_FMT, CXN_ID_FMT_ARGS(cxn_id));
    if (cxn_id == IND_CXN_RESET_ALL) {
        /* Iterate thru active controllers and reset all but listening */
        indigo_controller_id_t id;
        FOREACH_ACTIVE_CONTROLLER(id, ctrl) {
            if (!ctrl->config_params.listen) {
                ind_controller_disconnect(ctrl);
            }
        }
    } else if (!INDIGO_CXN_INVALID(cxn_id)) {
        cxn = CXN_ID_TO_CONNECTION(cxn_id);
        if (cxn != NULL) {
            ind_cxn_disconnect(cxn);
        }
    }
}

/**
 * Show the stats for each connection.  If details
 * is true, show per-message data
 */

void
ind_cxn_stats_show(aim_pvs_t *pvs, int details)
{
    connection_t *cxn;
    int idx;
    int cxn_idx;
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

    FOREACH_ACTIVE_CXN(cxn_idx, cxn) {
        cxn_count++;
        aim_printf(pvs, "Stats for%s%s connection " CXN_FMT ":\n",
                   CXN_LOCAL(cxn) ? " local" : "",
                   CXN_LISTEN(cxn) ? " listening" : "",
                   CXN_FMT_ARGS(cxn));
        aim_printf(pvs, "    Id: %d.\n", cxn->cxn_id);
        aim_printf(pvs, "    Auxiliary Id: %d.\n", cxn->auxiliary_id);
        aim_printf(pvs, "    Controller Id: %d.\n",
                   cxn->controller->controller_id);
        aim_printf(pvs, "    State: %s.\n", CXN_HANDSHAKE_COMPLETE(cxn) ?
                   "Connected" : "Not connected");
        aim_printf(pvs, "    Keepalive timeout: %d ms.\n",
                   cxn->keepalive.period_ms);
        aim_printf(pvs, "    Threshold: %d.\n", cxn->keepalive.threshold);
        aim_printf(pvs, "    Outstanding Echo Count: %d.\n",
                   cxn->keepalive.outstanding_echo_cnt);

        aim_printf(pvs, "    Messages in, current connection: %"PRIu64"\n",
                   cxn->status.messages_in);
        counter = 0;
        for (idx = 0; idx < OF_MESSAGE_OBJECT_COUNT; idx++) {
            counter += debug_counter_get(&cxn->rx_counters[idx]);
        }
        aim_printf(pvs, "    Cumulative messages in: %"PRIu64"\n", counter);
        if (details) {
            for (idx = 0; idx < OF_MESSAGE_OBJECT_COUNT; idx++) {
                if (debug_counter_get(&cxn->rx_counters[idx]) > 0) {
                    aim_printf(pvs, "        %s: %"PRIu64"\n",
                               of_object_id_str[idx],
                               debug_counter_get(&cxn->rx_counters[idx]));
                }
            }
        }

        aim_printf(pvs, "    Messages out, current connection: %"PRIu64"\n",
                   cxn->status.messages_out);
        counter = 0;
        for (idx = 0; idx < OF_MESSAGE_OBJECT_COUNT; idx++) {
            counter += debug_counter_get(&cxn->tx_counters[idx]);
        }
        aim_printf(pvs, "    Cumulative messages out: %"PRIu64"\n", counter);
        aim_printf(pvs, "    Dropped outgoing messages: %"PRIu64"\n",
                   debug_counter_get(&cxn->tx_drop_counter));
        if (details) {
            for (idx = 0; idx < OF_MESSAGE_OBJECT_COUNT; idx++) {
                if (debug_counter_get(&cxn->tx_counters[idx]) > 0) {
                    aim_printf(pvs, "        %s: %"PRIu64"\n",
                               of_object_id_str[idx],
                               debug_counter_get(&cxn->tx_counters[idx]));
                }
            }
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
    int idx;
    connection_t *cxn;

    /* See if there is any connection with role as MASTER */
    FOREACH_MAIN_HS_COMPLETE_CXN_WITH_ROLE(idx, cxn, INDIGO_CXN_R_MASTER) {
        *of_version = cxn->status.negotiated_version;
        return INDIGO_ERROR_NONE;
    }

    /* See if there is any connection with role as EQUAL */
    FOREACH_MAIN_HS_COMPLETE_CXN_WITH_ROLE(idx, cxn, INDIGO_CXN_R_EQUAL) {
        *of_version = cxn->status.negotiated_version;
        return INDIGO_ERROR_NONE;
    }

    /* See if there is any connection with role as SLAVE */
    FOREACH_MAIN_HS_COMPLETE_CXN_WITH_ROLE(idx, cxn, INDIGO_CXN_R_SLAVE) {
        *of_version = cxn->status.negotiated_version;
        return INDIGO_ERROR_NONE;
    }

    /* See if there is any connection with role as UNKNOWN, e.g. oftest */
    FOREACH_MAIN_HS_COMPLETE_CXN_WITH_ROLE(idx, cxn, INDIGO_CXN_R_UNKNOWN) {
        *of_version = cxn->status.negotiated_version;
        return INDIGO_ERROR_NONE;
    }

    /* If there's no controller we still need to send the packet-in through the
     * agents */
    *of_version = OFCONNECTIONMANAGER_CONFIG_ASYNC_MSG_OF_VERSION;
    return INDIGO_ERROR_NONE;
}

/**
 * Get Auxiliary id associated with the connection.
 */

indigo_error_t
indigo_cxn_get_auxiliary_id(indigo_cxn_id_t cxn_id, uint8_t *auxiliary_id)
{
    if (auxiliary_id == NULL) {
        return INDIGO_ERROR_PARAM;
    }

    connection_t *cxn = CXN_ID_TO_CONNECTION(cxn_id);

    if (cxn == NULL) {
        AIM_LOG_INTERNAL("Attempted to get auxiliary ID of nonexistent connection " CXN_ID_FMT,
                         CXN_ID_FMT_ARGS(cxn_id));
        return INDIGO_ERROR_NOT_FOUND;
    }

    INDIGO_ASSERT(cxn->controller != NULL);

    *auxiliary_id = cxn->auxiliary_id;
    return INDIGO_ERROR_NONE;
}

/**
 * Remove all the auxiliary connections associated with this controller and
 * disconnect the main connection
 */

void
ind_controller_disconnect(controller_t *ctrl)
{
    if (!ctrl->config_params.local) {
        AIM_SYSLOG_INFO("Disconnected from controller <ip-address>:<port>",
                        "The switch disconnected from the specified controller.",
                        "Disconnected from controller %s",
                        proto_ip_string(&ctrl->protocol_params));
    }

    ind_aux_connection_remove(ctrl, 0);

    connection_t *main_cxn = CXN_ID_TO_CONNECTION(ctrl->aux_id_to_cxn_id[0]);
    if (main_cxn != NULL) {
        ind_cxn_disconnect(main_cxn);
    }

    if (ctrl->ephemeral) {
        ctrl->active = 0;
    }
}

void
indigo_cxn_async_channel_selector_register(indigo_cxn_async_channel_selector_f fn)
{
    ind_cxn_async_channel_selector_handler = fn;
}

void
indigo_cxn_async_channel_selector_unregister(indigo_cxn_async_channel_selector_f fn)
{
    if (ind_cxn_async_channel_selector_handler != fn) {
        return;
    }

    ind_cxn_async_channel_selector_handler = NULL;
}

/* Barrier blockers */

void
indigo_cxn_block_barrier(indigo_cxn_id_t cxn_id, indigo_cxn_barrier_blocker_t *blocker)
{
    connection_t *cxn;

    if (CXN_ID_VALID(cxn_id)) {
        cxn = CXN_ID_TO_CONNECTION(cxn_id);
        /* cxn may be NULL */
    } else {
        cxn = NULL;
    }

    if (cxn != NULL) {
        ind_cxn_block_barrier(cxn);
        blocker->cxn_id = cxn_id;
    } else {
        blocker->cxn_id = INDIGO_CXN_ID_UNSPECIFIED;
    }

#ifndef NDEBUG
    blocker->tracker = aim_malloc(1);
#endif
}

void
indigo_cxn_unblock_barrier(indigo_cxn_barrier_blocker_t *blocker)
{
    if (CXN_ID_VALID(blocker->cxn_id)) {
        connection_t *cxn = CXN_ID_TO_CONNECTION(blocker->cxn_id);
        if (cxn != NULL) {
            ind_cxn_unblock_barrier(cxn);
        }
        blocker->cxn_id = INDIGO_CXN_ID_UNSPECIFIED;
    }

#ifndef NDEBUG
    aim_free(blocker->tracker);

    /* Deliberately leave blocker->tracker as is to let valgrind catch double
     * frees */
#endif
}

void
indigo_cxn_pause(indigo_cxn_id_t cxn_id)
{
    connection_t *cxn = CXN_ID_TO_CONNECTION(cxn_id);
    AIM_ASSERT(cxn != NULL);
    if (cxn != NULL) {
        ind_cxn_pause(cxn);
    }
}

void
indigo_cxn_resume(indigo_cxn_id_t cxn_id)
{
    connection_t *cxn = CXN_ID_TO_CONNECTION(cxn_id);
    if (cxn != NULL) {
        ind_cxn_resume(cxn);
    }
}

/****************************************************************
 * Barrier notification callback bookkeeping
 ****************************************************************/

struct barrier_notify_callback {
    indigo_cxn_barrier_notify_f callback;
    void *cookie;
};

#define MAX_BARRIER_NOTIFY_CALLBACKS 4

static struct barrier_notify_callback barrier_notify_callbacks[MAX_BARRIER_NOTIFY_CALLBACKS];

void
indigo_cxn_barrier_notify_register(
    indigo_cxn_barrier_notify_f handler, void *cookie)
{
    int idx;

    AIM_LOG_TRACE("Register barrier callback %p, cookie %p",
                  handler, cookie);
    AIM_ASSERT(handler != NULL);
    for (idx = 0; idx < MAX_BARRIER_NOTIFY_CALLBACKS; ++idx) {
        struct barrier_notify_callback *cb = &barrier_notify_callbacks[idx];
        if (cb->callback == NULL) {
            cb->callback = handler;
            cb->cookie = cookie;
            return;
        }
    }

    AIM_ASSERT(0, "Could not find free slot for barrier callback, consider increasing MAX_BARRIER_NOTIFY_CALLBACKS");
}

void
indigo_cxn_barrier_notify_unregister(
    indigo_cxn_barrier_notify_f handler, void *cookie)
{
    int idx;

    AIM_LOG_TRACE("Unregister barrier callback %p, cookie %p",
                  handler, cookie);
    for (idx = 0; idx < MAX_BARRIER_NOTIFY_CALLBACKS; ++idx) {
        struct barrier_notify_callback *cb = &barrier_notify_callbacks[idx];
        if ((cb->callback == handler) && (cb->cookie == cookie)) {
            cb->callback = NULL;
            cb->cookie = NULL;
            return;
        }
    }
}

void
ind_cxn_barrier_notify(indigo_cxn_id_t cxn_id)
{
    int idx;
    for (idx = 0; idx < MAX_BARRIER_NOTIFY_CALLBACKS; ++idx) {
        struct barrier_notify_callback *cb = &barrier_notify_callbacks[idx];
        if (cb->callback != NULL) {
            cb->callback(cxn_id, cb->cookie);
        }
    }
}

static indigo_error_t
parse_sockaddr_getaddrinfo(int family, const char *addr, int port,
                           struct sockaddr_storage *sockaddr)
{
    char port_str[8];
    snprintf(port_str, sizeof(port_str), "%u", port);

    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_flags = AI_NUMERICHOST|AI_NUMERICSERV;
    hints.ai_family = family;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = 0;

    struct addrinfo *ai;
    int ret;

    if ((ret = getaddrinfo(addr, port_str, &hints, &ai)) < 0) {
        AIM_LOG_ERROR("Could not convert %s:%d to an %s socket address: %s",
                      addr, port,
                      family == AF_INET ? "ipv4" : "ipv6",
                      gai_strerror(ret));
        return INDIGO_ERROR_PARAM;
    }

    memcpy(sockaddr, ai->ai_addr, ai->ai_addrlen);
    freeaddrinfo(ai);
    return INDIGO_ERROR_NONE;
}

indigo_error_t
ind_cxn_parse_sockaddr(
    const indigo_cxn_protocol_params_t *protocol_params,
    struct sockaddr_storage *sockaddr)
{
    switch (protocol_params->header.protocol) {
    case INDIGO_CXN_PROTO_TCP_OVER_IPV4:
        return parse_sockaddr_getaddrinfo(
            AF_INET,
            protocol_params->tcp_over_ipv4.controller_ip,
            protocol_params->tcp_over_ipv4.controller_port,
            sockaddr);
    case INDIGO_CXN_PROTO_TCP_OVER_IPV6: {
        return parse_sockaddr_getaddrinfo(
            AF_INET6,
            protocol_params->tcp_over_ipv6.controller_ip,
            protocol_params->tcp_over_ipv6.controller_port,
            sockaddr);
    }
    default:
        AIM_LOG_INTERNAL("Invalid protocol %d", protocol_params->header.protocol);
        return INDIGO_ERROR_PARAM;
    }

    return INDIGO_ERROR_NONE;
}
