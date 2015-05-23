/****************************************************************
 *
 *        Copyright 2013-2015, Big Switch Networks, Inc.
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

#include <SocketManager/socketmanager.h>
#include <OFConnectionManager/ofconnectionmanager.h>
#include <Configuration/configuration.h>

#include <indigo/memory.h>
#include <indigo/assert.h>

#include <loci/loci_dump.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <netdb.h>

#include "ofconnectionmanager_int.h"


static int init_done = 0;
static int module_enabled = 0;

static indigo_cxn_async_channel_selector_f ind_cxn_async_channel_selector_handler;

/*------------------------------------------------------------
 * Forward declarations
 *------------------------------------------------------------*/

static indigo_error_t
remove_aux_cxns(controller_t *controller, uint32_t num_aux);


/*------------------------------------------------------------
 * Connection Manager Data shared within module
 *------------------------------------------------------------*/

uint32_t ind_cxn_read_errors;


/* for role request message validation */
uint64_t ind_cxn_generation_id;


/*------------------------------------------------------------
 * Connection Manager Private Data
 *------------------------------------------------------------*/
static ind_cxn_config_t cxn_config;

/**
 * Controller control blocks, indexed by controller index
 */
static controller_t controllers[MAX_CONTROLLERS];

#define INVALID_ID -1


/*------------------------------------------------------------
 * Controller instance bookkeeping
 *------------------------------------------------------------*/

#define CONTROLLER_ID_VALID(id)                                         \
    (((id) >= 0) && ((id) < MAX_CONTROLLERS))

#define CONTROLLER_ID_ACTIVE(id)                                        \
    CONTROLLER_ACTIVE(&controllers[controller_id])

#define FOREACH_ACTIVE_CONTROLLER(id, controller)                       \
    for (id = 0, controller = &controllers[0];                          \
         id < MAX_CONTROLLERS;                                          \
         ++id, controller = &controllers[id])                           \
        if (CONTROLLER_ACTIVE(controller))

/* Only remote controllers */
#define FOREACH_REMOTE_ACTIVE_CONTROLLER(id, controller)                \
    for (id = 0, controller = &controllers[0];                          \
         id < MAX_CONTROLLERS;                                          \
         ++id, controller = &controllers[id])                           \
        if (CONTROLLER_ACTIVE(controller) &&                            \
            !(controller->config_params.local))

/**
 * Convert controller ID to pointer to controller block
 */
#define ID_TO_CONTROLLER(id) (&controllers[id])

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


/*------------------------------------------------------------
 * Status change callback bookkeeping
 *------------------------------------------------------------*/

/**
 * Status change callback control block
 *
 * If a callback is non-NULL it is considered active and will
 * receive all connection status change notifications.
 */

typedef struct status_change_s {
    indigo_cxn_status_change_f callback;
    void *cookie;
} status_change_t;

#define MAX_STATUS_CHANGE_CALLBACKS 32

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
 * This function is called on any state change.
 * But only entering and exiting the handshake_complete state results in
 * registered callbacks being called.
 */
void
ind_cxn_status_change(connection_t *cxn)
{
    void *cookie;
    int idx;
    indigo_cxn_status_change_f callback;

    if (!CXN_LOCAL(cxn)) {
        if (cxn->state == CXN_S_HANDSHAKE_COMPLETE ||
            cxn->state == CXN_S_CLOSING) {
            /* Notify registered callbacks */
            FOREACH_STATUS_CALLBACK(idx, callback, cookie) {
                callback(cxn->controller->controller_id,
                         cxn->aux_id,
                         get_connection_params(cxn),
                         ind_cxn_is_handshake_complete(cxn),
                         cookie);
            }
            ind_cxn_send_cxn_list();
        }
    }
}

/*
 * Send an of_bsn_controller_connections_reply to each connection
 *
 * HACK reusing the reply message for this async notification.
 */
void
ind_cxn_send_cxn_list(void)
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


/*
 * To help debug controller-switch connection issues,
 * syslog a space-separated list of connected controllers.
 */
void
ind_cxn_syslog_active_controllers(void)
{
    int id;
    controller_t *controller;
    /* +1 for space between controller descriptions */
    char buf[MAX_CONTROLLERS*(MAX_CONTROLLER_DESC_LEN+1)] = { 0 };
    int count = 0;

    FOREACH_REMOTE_ACTIVE_CONTROLLER(id, controller) {
        connection_t *maincxn = controller->cxns[0];
        if (maincxn && maincxn->status.is_connected) {
            strcat(buf, " ");
            strncat(buf, controller->desc, MAX_CONTROLLER_DESC_LEN);
            count++;
        }
    }

    AIM_SYSLOG_INFO("Connected controllers: <count>: <ip-address>:<port> ...",
                    "Space-separated listing of connected controllers.",
                    "Connected controllers: %d:%s", 
                    count, count > 0? buf: " None");
}


/*
 * populate destbuf with useful connection identifying info.
 * destbuf has maximum length destbuflen.
 */
static int
proto_ip_string(indigo_cxn_protocol_params_t *params,
                char *destbuf, int destbuflen)
{
    const char inv[] = "invalid";
    int len;

    switch (params->header.protocol) {
    case INDIGO_CXN_PROTO_TCP_OVER_IPV4:
        len = snprintf(destbuf, destbuflen, "%s:%d",
                       params->tcp_over_ipv4.controller_ip,
                       params->tcp_over_ipv4.controller_port);
        break;
    case INDIGO_CXN_PROTO_TCP_OVER_IPV6:
        len = snprintf(destbuf, destbuflen, "%s:%d",
                       params->tcp_over_ipv6.controller_ip,
                       params->tcp_over_ipv6.controller_port);
        break;
    case INDIGO_CXN_PROTO_UNIX:
        len = snprintf(destbuf, destbuflen, "%s",
                       params->unx.unix_path);
        break;
    case INDIGO_CXN_PROTO_INVALID:  /* fall-through */
    default:
        strcpy(destbuf, inv);
        len = sizeof(inv)-1;
        break;
    }

    return len;
}


/* initialize controller_t structure */
static void
controller_t_init(controller_t *controller, 
                  indigo_controller_id_t controller_id,
                  indigo_cxn_protocol_params_t *protocol_params,
                  indigo_cxn_config_params_t *config_params)
{
    INDIGO_MEM_CLEAR(controller, sizeof(controller_t));
    controller->active = true;
    controller->role = INDIGO_CXN_R_EQUAL;
    controller->controller_id = controller_id;
    INDIGO_MEM_COPY(&controller->protocol_params,
                    protocol_params,
                    sizeof(controller->protocol_params));
    INDIGO_MEM_COPY(&controller->config_params,
                    config_params,
                    sizeof(controller->config_params));
    proto_ip_string(&controller->protocol_params,
                    controller->desc, sizeof(controller->desc));
}


/*------------------------------------------------------------
 * Listening connection handling
 *------------------------------------------------------------*/

/* depth of listen backlog queue */
#define LISTEN_CXN_BACKLOG 5

/*
 * A listening controller opens a 'main' listening connection
 * that waits for clients to connect.
 * When a client is accepted, another controller is allocated
 * that inherits attributes from the main listening controller,
 * and a connection is established with the client.
 *
 * Unlike non-listening controllers, the underlying connection
 * associated with a listening controller is not restartable.
 *
 * Listening connections may not receive all async messages.
 *
 * Currently, derived listening controllers are not tracked, and
 * there is no cleanup of derived controllers/connections
 * if the main listening controller is removed.
 *
 * When the listening controller is removed, the main listening
 * connection is stopped by calling controller_stop_cxn,
 * which in turn calls ind_cxn_stop.  The connection's state advances
 * from initialized (since the connection state machine is not
 * used by the listener) to closing, and then immediately to closed.
 * This will close the underlying socket and unregister from 
 * socket manager.
 */

/**
 * Handle a listening socket ready event
 *
 * @param socket_id The socket that is ready
 * @param cookie Pointer to the connection instance
 * @param read_ready Was read-ready signaled by select
 * @param write_ready Was write-ready signaled by select
 * @param error_seen Was an error signaled by select
 *
 * This usually means a new socket connection is ready to be
 * accepted.  Spin up a new connection instance for it.
 */
static void
listen_socket_ready(int socket_id, void *cookie, int read_ready,
                    int write_ready, int error_seen)
{
    connection_t *listen_cxn;
    socklen_t addrlen;
    struct sockaddr_storage cxn_addr;
    int new_sd;
    connection_t *cxn;
    indigo_controller_id_t controller_id;
    controller_t *controller;

    listen_cxn = (connection_t *)cookie;

    AIM_LOG_TRACE("Listen soc %d ready, cxn %p. rd %d. wr %d. er %d",
                  socket_id, cookie, read_ready, write_ready, error_seen);

    if (!CXN_ID_VALID(listen_cxn->cxn_id)) {
        AIM_LOG_INTERNAL("Listen socket ready with bad cxn %p", listen_cxn);
        return;
    }

    if (!CXN_ACTIVE(listen_cxn)) {
        AIM_LOG_INTERNAL("Listen socket ready on non active cxn %p",
                         listen_cxn);
        return;
    }

    AIM_ASSERT(listen_cxn->controller != NULL);
    AIM_ASSERT(listen_cxn->sd == socket_id);

    if (error_seen) {
        int socket_error = 0;
        socklen_t len = sizeof(socket_error);
        getsockopt(listen_cxn->sd, SOL_SOCKET, SO_ERROR, &socket_error, &len);
        AIM_LOG_ERROR("listen %s: %s", 
                      listen_cxn->desc, strerror(socket_error));
        return;
    }

    /* Ready for an accept */
    if (!read_ready) {
        AIM_LOG_ERROR("listen %s: read not ready",
                      listen_cxn->desc);
        return;
    }

    /* Accept the new client */
    addrlen = sizeof(cxn_addr);
    new_sd = accept(listen_cxn->sd, (struct sockaddr*) &cxn_addr, &addrlen);
    if (new_sd == -1) {
        AIM_LOG_ERROR("Accept on listen %s: %s",
                      listen_cxn->desc, strerror(errno));
        return;
    }
    if (cxn_addr.ss_family == AF_INET) {
        struct sockaddr_in *sa = (struct sockaddr_in*) &cxn_addr;
        AIM_LOG_VERBOSE("Accepted cxn from %{ipv4a}:%d", 
                        ntohl(sa->sin_addr.s_addr), ntohs(sa->sin_port));
    } else if (cxn_addr.ss_family == AF_INET6) {
        struct sockaddr_in6 *sa6 = (struct sockaddr_in6*) &cxn_addr;
        /* FIXME use AIM datatype when available */
        AIM_LOG_VERBOSE("Accepted cxn from [IPv6addr]:%d",
                        ntohs(sa6->sin6_port));
    } else if (cxn_addr.ss_family == AF_UNIX) {
        struct sockaddr_un *sun = (struct sockaddr_un*) &cxn_addr;
        AIM_LOG_VERBOSE("Accepted cxn from %s", sun->sun_path);
    }

    controller_id = find_free_controller();
    if (INDIGO_CONTROLLER_INVALID(controller_id)) {
        AIM_LOG_INTERNAL("Could not allocate space for controller");
        close(new_sd);
        return;
    }

    controller = ID_TO_CONTROLLER(controller_id);
    controller_t_init(controller, controller_id,
                      &listen_cxn->controller->protocol_params,
                      &listen_cxn->controller->config_params);
    AIM_LOG_VERBOSE("Allocated controller %d(%p) for %s",
                    controller_id, controller, controller->desc);

    /* Add the new connection with the socket */
    cxn = ind_cxn_alloc(controller, 0, new_sd);
    if (cxn == NULL) {
        AIM_LOG_ERROR("Could not set up accepted connection");
        controller->active = false;
        close(new_sd);
        return;
    }

    AIM_LOG_TRACE("Allocated cxn %p", cxn);

    /* Inherit the tracer - move to config_params? */
    cxn->trace_pvs = listen_cxn->trace_pvs;

    controller->cxns[0] = cxn;
    controller->restartable = false;

    ind_cxn_start(cxn);
}


/**
 * Initialize a connection instance accepted from a listening socket.
 */
static indigo_error_t
listen_cxn_init(connection_t *cxn)
{
    struct sockaddr_storage cxn_addr;
    socklen_t cxn_addr_len;
    indigo_error_t rv;
    indigo_cxn_protocol_params_t *protocol_params;

    AIM_LOG_VERBOSE("Initializing listening socket");

    protocol_params = get_connection_params(cxn);

    if (ind_cxn_parse_sockaddr(protocol_params,
                               &cxn_addr, &cxn_addr_len) < 0) {
        return INDIGO_ERROR_PARAM;
    }

    {
        int flag = 1;
        (void) setsockopt(cxn->sd, SOL_SOCKET, SO_REUSEADDR,
                          (char *) &flag, sizeof(int));
    }

    if (cxn_addr.ss_family == AF_UNIX) {
        /* remove unix domain socket so bind does not fail */
        struct sockaddr_un *sun = (struct sockaddr_un *) &cxn_addr;
        unlink(sun->sun_path);
    }

    /* bind the socket to the port number */
    if (bind(cxn->sd, (struct sockaddr *) &cxn_addr, cxn_addr_len) == -1) {
        AIM_LOG_INTERNAL("Could not bind socket for listen cxn: %s",
                         strerror(errno));
        return INDIGO_ERROR_UNKNOWN;
    }

    /* show that we are willing to listen */
    if (listen(cxn->sd, LISTEN_CXN_BACKLOG) == -1) {
        AIM_LOG_INTERNAL("Could not listen on socket for listen cxn: %s",
                         strerror(errno));
        return INDIGO_ERROR_UNKNOWN;
    }

    /* Register the socket */
    rv = ind_soc_socket_register_with_priority(cxn->sd, listen_socket_ready,
                                               cxn, IND_CXN_EVENT_PRIORITY);
    if (rv < 0) {
        AIM_LOG_INTERNAL("Could not register listen socket: %s",
                         indigo_strerror(rv));
        return INDIGO_ERROR_UNKNOWN;
    }

    return INDIGO_ERROR_NONE;
}


/* Add a nonlocal,nonlistening connection instance */
static connection_t *
controller_add_cxn(controller_t *controller, uint8_t aux_id)
{
    connection_t *cxn = NULL;

    AIM_LOG_VERBOSE("Connection add: %s:%d",
                    controller->desc, aux_id);

    cxn = ind_cxn_alloc(controller, aux_id, -1);
    if (cxn == NULL) {
        AIM_LOG_ERROR("Could not allocate connection");
        return NULL;
    }

    controller->cxns[aux_id] = cxn;

    ind_cxn_start(cxn);

    return cxn;
}


/*------------------------------------------------------------
 * Closed connection and restart connection handling
 *------------------------------------------------------------*/

/**
 * @brief Calculate timeout between connection attempts.
 *
 * Exponential backoff up to a limit of 1 second.
 */
static int
controller_retry_ms(const controller_t *controller)
{
    if (controller->fail_count < 10) {
        return 1 << controller->fail_count;
    } else {
        return 1000;
    }
}

/* Note that cookie is the underlying controller of the main cxn */
static void
main_cxn_restart_handler(void *cookie)
{
    controller_t *controller = (controller_t *) cookie;
    connection_t *cxn;

    ind_soc_timer_event_unregister(main_cxn_restart_handler, cookie);

    AIM_LOG_VERBOSE("Restarting %s(%p)", controller->desc, controller);

    cxn = controller_add_cxn(controller, 0);
    if (cxn == NULL) {
        indigo_error_t rv;
        AIM_LOG_INTERNAL("Error allocating controller %s, "
                         "rescheduling for %d ms", 
                         controller->desc, controller_retry_ms(controller));
        rv = ind_soc_timer_event_register_with_priority(
            main_cxn_restart_handler, controller,
            controller_retry_ms(controller), IND_CXN_EVENT_PRIORITY);
        AIM_ASSERT(rv == INDIGO_ERROR_NONE,
                   "Failed to register main_cxn_restart_handler for %s",
                   controller->desc);
    }
}

static void
cxn_closed_handler(void *cookie)
{
    connection_t *cxn = (connection_t *) cookie;
    uint8_t aux_id = cxn->aux_id;
    controller_t *controller = cxn->controller;

    AIM_LOG_TRACE("%s: handling %s(%p)", __FUNCTION__, cxn->desc, cxn);

    ind_cxn_free(cxn);
    controller->cxns[aux_id] = NULL;

    /* only restart the main connection */
    if (aux_id == 0) {
        if (controller->restartable) {
            indigo_error_t rv;

            controller->role = INDIGO_CXN_R_EQUAL;

            AIM_LOG_VERBOSE("Main cxn for controller %s rescheduled for %d ms",
                            controller->desc, controller_retry_ms(controller));
            rv = ind_soc_timer_event_register_with_priority(
                main_cxn_restart_handler, controller,
                controller_retry_ms(controller), IND_CXN_EVENT_PRIORITY);
            AIM_ASSERT(rv == INDIGO_ERROR_NONE,
                       "Failed to register main_cxn_restart_handler for %s",
                       controller->desc);
        } else {
            AIM_LOG_VERBOSE("Controller %s marked inactive",
                            controller->desc);
            controller->active = false;
        }
    }
}

/* called by cxn_instance to launch the cxn_closed_handler */
void
ind_cxn_notify_closed(connection_t *cxn)
{
    indigo_error_t rv;

    AIM_LOG_TRACE("%s: notifying for %s(%p), fail count %d",
                  __FUNCTION__, cxn->desc, cxn,
                  cxn->controller->fail_count);

    /* use immediate timer to yield */
    rv = ind_soc_timer_event_register_with_priority(cxn_closed_handler, cxn,
                                               IND_SOC_TIMER_IMMEDIATE,
                                               IND_CXN_EVENT_PRIORITY);
    AIM_ASSERT(rv == INDIGO_ERROR_NONE, 
               "Failed to register cxn_closed_handler for %s",
               cxn->desc);
}


/**
 * Stop the specified connection if it is not yet closed.
 * If it is closed, send a notification to clean up and restart.
 */
static void
controller_stop_cxn(connection_t *cxn)
{
    if (cxn == NULL) {
        AIM_LOG_INTERNAL("Controller stop on null cxn, skipping");
        return;
    }

    AIM_LOG_TRACE("Controller stop cxn %s(%p)", cxn->desc, cxn);
    if (!ind_cxn_is_closed(cxn)) {
        ind_cxn_stop(cxn);
    } else {
        ind_cxn_notify_closed(cxn);
    }
}


/**
 * For the specified controller:
 * - remove all auxiliary connections
 * - disconnect the main connection
 */
void
controller_disconnect(controller_t *controller)
{
    connection_t *main_cxn;

    AIM_LOG_TRACE("Controller disconnect %s(%p)", 
                  controller->desc, controller);

    remove_aux_cxns(controller, 0);

    main_cxn = controller->cxns[0];
    if (main_cxn != NULL) {
        controller_stop_cxn(main_cxn);
    } else {
        AIM_LOG_INTERNAL("Controller %s has no main connection",
                         controller->desc);
    }
}


/*------------------------------------------------------------
 * Aux cxn handling
 *------------------------------------------------------------*/

/**
 * Remove extra auxiliary connections for this controller, setting the new
 * number of aux cxns to the specified num_aux.
 * If num_aux is set to zero, shut down all aux cxns for this controller.
 */
static indigo_error_t
remove_aux_cxns(controller_t *controller, uint32_t num_aux)
{
    int idx;
    uint32_t num_aux_current;

    if (!CONTROLLER_ACTIVE(controller)) {
        return INDIGO_ERROR_UNKNOWN;
    }

    if (num_aux == controller->num_aux) {
        return INDIGO_ERROR_NONE;
    }

    if (num_aux > controller->num_aux) {
        AIM_LOG_TRACE("Requested num_aux %d is greater than current aux cxn's "
                      "for controller %s", num_aux, controller->desc);
        return INDIGO_ERROR_PARAM;
    }

    AIM_LOG_VERBOSE("Aux cxns for controller %s changed from %d to %d",
                    controller->desc, controller->num_aux, num_aux);
    num_aux_current = controller->num_aux;
    controller->num_aux = num_aux;

    for (idx = num_aux_current; idx > num_aux; --idx) {
        controller_stop_cxn(controller->cxns[idx]);
        controller->cxns[idx] = NULL;
    }

    return INDIGO_ERROR_NONE;
}


/**
 * Main and aux connection rules:
 * If main is closed for any reason, all aux are closed.
 * If any aux is closed for any error or if the main fails to respond to echo,
 * all main and aux are closed.
 * If any aux is closed gracefully, only that aux is closed.
 * Aux echo timeouts are advisory only; i.e. they do not cause the aux to be
 * closed.
 * Only main cxns can be restarted.
 * Aux cxns are created by controller request and are not restarted when they 
 * close.
 */

/**
 * Set up num_aux auxiliary connections for controller associated
 * with the specified main connection.
 *
 * If num_aux requested is greater than aux cxns we already have,
 * the extra aux cxns will be removed.
 */
int
ind_cxn_set_aux_cxns(connection_t *main_cxn, uint32_t num_aux)
{
    int idx;

    AIM_ASSERT(main_cxn != NULL);

    if (num_aux > MAX_AUX_CONNECTIONS) {
        AIM_LOG_WARN("%s: Requested aux connections %d "
                     "greater than supported %d",
                     main_cxn->desc, num_aux, MAX_AUX_CONNECTIONS);
        return 1;
    }

    /* Check to make sure this is not a local connection */
    if (CXN_LOCAL(main_cxn)) {
        AIM_LOG_WARN("%s: Aux cxn request not supported on local connection",
                     main_cxn->desc);
        return 1;
    }

    /* Check if this is the main connection of the attached controller */
    if (main_cxn->aux_id != 0) {
        AIM_LOG_WARN("%s: Aux cxn request ignored on non main connection",
                     main_cxn->desc);
        return 1;
    }

    if (num_aux == main_cxn->controller->num_aux) {
        AIM_LOG_VERBOSE("%s: Requested num_aux %d equal to current aux cxns",
                        main_cxn->desc, num_aux);
        return 0;
    } else if (num_aux < main_cxn->controller->num_aux) {
        AIM_LOG_VERBOSE("%s: Requested num_aux %d, removing %d",
                        main_cxn->desc, num_aux,
                        main_cxn->controller->num_aux - num_aux);
        if (remove_aux_cxns(main_cxn->controller, num_aux) < 0) {
            return 1;
        }
    } else {
        for (idx = main_cxn->controller->num_aux+1; idx <= num_aux; ++idx) {
            if (controller_add_cxn(main_cxn->controller, idx) == NULL) {
                return 1;
            }
        }

        AIM_LOG_VERBOSE("%s: aux cxns changed from %d to %d",
                        main_cxn->desc, 
                        main_cxn->controller->num_aux, num_aux);
        main_cxn->controller->num_aux = num_aux;
    }

    return 0;
}


/*------------------------------------------------------------
 * Exported indigo_controller_add and indigo_controller_remove
 *------------------------------------------------------------*/

/**
 * Add a Controller instance and create the main connection with the
 * controller using auxiliary_id = 0
 */

indigo_error_t
indigo_controller_add(indigo_cxn_protocol_params_t *protocol_params,
                      indigo_cxn_config_params_t *config_params,
                      indigo_controller_id_t *controller_id)
{
    indigo_error_t rv = INDIGO_ERROR_NONE;
    controller_t *controller = NULL;
    connection_t *cxn = NULL;

    AIM_ASSERT(protocol_params != NULL);
    AIM_ASSERT(config_params != NULL);
    AIM_ASSERT(controller_id != NULL);

    if (config_params->local &&
        (config_params->periodic_echo_ms ||
         config_params->reset_echo_count)) {
        AIM_LOG_INTERNAL("Local connection with nonzero echo params "
                         "unsupported");
        rv = INDIGO_ERROR_PARAM;
        goto error;
    }

    if (protocol_params->header.protocol != INDIGO_CXN_PROTO_TCP_OVER_IPV4 &&
        protocol_params->header.protocol != INDIGO_CXN_PROTO_TCP_OVER_IPV6 &&
        protocol_params->header.protocol != INDIGO_CXN_PROTO_UNIX) {
        AIM_LOG_INTERNAL("Unsupported protocol for connection add: %d",
                         protocol_params->header.protocol);
        rv = INDIGO_ERROR_NOT_SUPPORTED;
        goto error;
    }

    *controller_id = find_free_controller();
    if (INDIGO_CONTROLLER_INVALID(*controller_id)) {
        AIM_LOG_INTERNAL("Could not allocate space for controller");
        rv = INDIGO_ERROR_RESOURCE;
        goto error;
    }

    controller = ID_TO_CONTROLLER(*controller_id);

    controller_t_init(controller, *controller_id,
                      protocol_params, config_params);

    AIM_LOG_INFO("Controller add: %s (%s, v%d)",
                 controller->desc,
                 config_params->listen ? "listen" : "remote",
                 config_params->version);

    if (!config_params->listen) {
        /* Create the main connection (aux_id 0) */
        cxn = controller_add_cxn(controller, 0);
        if (cxn == NULL) {
            rv = INDIGO_ERROR_RESOURCE;
            goto error;
        }
        controller->restartable = true;
    } else {
        /* Create listening socket */
        cxn = ind_cxn_alloc(controller, 0, -1);
        if (cxn == NULL) {
            AIM_LOG_ERROR("Could not allocate listening connection");
            rv = INDIGO_ERROR_UNKNOWN;
            goto error;
        }

        /* Listening connection does not call ind_cxn_start */
        rv = listen_cxn_init(cxn);
        if (rv != INDIGO_ERROR_NONE) {
            AIM_LOG_ERROR("Could not initialize listening connection");
            goto error;
        }
        
        controller->cxns[0] = cxn;
    }

 error:
    if (rv < INDIGO_ERROR_NONE) {
        if (cxn) {
            close(cxn->sd);
            cxn->sd = -1;
            ind_cxn_free(cxn);
        }
        if (controller) {
            controller->active = false;
        }
    }

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
    controller_t *controller = NULL;

    if (!CONTROLLER_ID_VALID(controller_id) ||
        !CONTROLLER_ID_ACTIVE(controller_id)) {
        AIM_LOG_INTERNAL("Remove controller id %d invalid or not active",
                         controller_id);
        return INDIGO_ERROR_PARAM;
    }

    controller = ID_TO_CONTROLLER(controller_id);
    AIM_LOG_INFO("Controller remove: %s", controller->desc);

    /* Remove all the aux connections first */
    rv = remove_aux_cxns(controller, 0);
    if (rv < 0) {
        return rv;
    }

    /* Remove the main connection */
    controller->restartable = false;
    controller_stop_cxn(controller->cxns[0]);
    controller->cxns[0] = NULL;

    /* controller remains active until cxn_closed_handler marks it inactive */

    return rv;
}

/* Return the config of a specific connection */
indigo_error_t
indigo_cxn_connection_config_get(
    indigo_cxn_id_t cxn_id,
    indigo_cxn_config_params_t *config)
{
    connection_t *cxn = ind_cxn_id_to_connection(cxn_id);

    if (!cxn) {
        AIM_LOG_INTERNAL("Attempted to get config for nonexistent connection "
                         CXN_ID_FMT,
                         CXN_ID_FMT_ARGS(cxn_id));
        return INDIGO_ERROR_NOT_FOUND;
    }

    AIM_ASSERT(cxn->controller != NULL);

    INDIGO_MEM_COPY(config, &cxn->controller->config_params, sizeof(*config));

    return INDIGO_ERROR_NONE;
}

/* Return the status of a specific connection */
indigo_error_t
indigo_cxn_connection_status_get(
    indigo_cxn_id_t cxn_id,
    indigo_cxn_status_t *status)
{
    connection_t *cxn = ind_cxn_id_to_connection(cxn_id);

    if (!cxn) {
        AIM_LOG_INTERNAL("Attempted to get status for nonexistent connection "
                         CXN_ID_FMT,
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
    AIM_ASSERT(cxn->controller->role == INDIGO_CXN_R_SLAVE);

    /* The BSN backport and the standard message use the same reason values */
    AIM_ASSERT(reason == OFPCRR_MASTER_REQUEST);
    AIM_ASSERT(OFPCRR_MASTER_REQUEST == OFP_BSN_CONTROLLER_ROLE_REASON_MASTER_REQUEST);

    if (cxn->status.negotiated_version == OF_VERSION_1_3) {
        of_bsn_role_status_t *msg = of_bsn_role_status_new(OF_VERSION_1_3);
        if (msg == NULL) {
            AIM_DIE("Failed to allocate role status message");
        }
        of_bsn_role_status_role_set(msg, OF_CONTROLLER_ROLE_SLAVE);
        of_bsn_role_status_reason_set(msg, reason);
        of_bsn_role_status_generation_id_set(msg, ind_cxn_generation_id);
        indigo_cxn_send_controller_message(cxn->cxn_id, msg);
    } else if (cxn->status.negotiated_version >= OF_VERSION_1_4) {
        of_role_status_t *msg = of_role_status_new(cxn->status.negotiated_version);
        if (msg == NULL) {
            AIM_DIE("Failed to allocate role status message");
        }
        of_role_status_role_set(msg, OF_CONTROLLER_ROLE_SLAVE);
        of_role_status_reason_set(msg, reason);
        of_role_status_generation_id_set(msg, ind_cxn_generation_id);
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
    controller_t *controller;
    int id;

    FOREACH_REMOTE_ACTIVE_CONTROLLER(id, controller) {
        if (controller->controller_id == master_id) {
            AIM_LOG_INFO("Upgrading controller %s role to master",
                         controller->desc);
            controller->role = INDIGO_CXN_R_MASTER;
        } else if (controller->role == INDIGO_CXN_R_MASTER) {
            AIM_LOG_INFO("Downgrading controller %s role to slave",
                         controller->desc);
            controller->role = INDIGO_CXN_R_SLAVE;
            ind_cxn_send_role_status(controller->cxns[0],
                                     OFPCRR_MASTER_REQUEST);
        }
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

/*
 * Send an OpenFlow message to a controller connection
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

    cxn = ind_cxn_id_to_connection(cxn_id);
    if (!cxn || !CXN_TCP_CONNECTED(cxn)) {
        AIM_LOG_VERBOSE("Attempted to send %s message to disconnected "
                        "connection " CXN_ID_FMT,
                        of_class_name(obj), CXN_ID_FMT_ARGS(cxn_id));
        goto done;
    }

    xid = of_message_xid_get(OF_BUFFER_TO_MESSAGE(
            OF_OBJECT_BUFFER_INDEX(obj, 0)));

    AIM_LOG_VERBOSE("cxn %s: Sending %s message xid %u",
                    cxn->desc, of_class_name(obj), xid);

    if(cxn->trace_pvs) {
        aim_printf(cxn->trace_pvs, "** of_msg_trace: send to cxn=%d\n",
                   cxn->cxn_id);
        of_object_dump((loci_writer_f)aim_printf, cxn->trace_pvs, obj);
        aim_printf(cxn->trace_pvs, "**\n\n");
    }


    if (!ind_cxn_is_handshake_complete(cxn)) {
        if (IS_ASYNC_MSG(obj)) {
            AIM_LOG_TRACE("Handshake not complete; drop async msg %s",
                          of_class_name(obj));
            goto done;
        }
    }

    /* Drop noncritical messages before the write buffer fills up completely */
    if (cxn->pkts_enqueued > NONCRITICAL_DROP_THRESHOLD) {
        if (cxn_message_is_noncritical(obj->object_id)) {
            AIM_LOG_TRACE("Dropping noncritical %s message",
                          of_class_name(obj));
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
        AIM_LOG_ERROR("Could not enqueue %s message data to cxn %s, "
                      "disconnecting",
                      of_class_name(obj), cxn->desc);
        aim_free(data);
        controller_disconnect(cxn->controller);
    }

    if (obj->object_id == OF_FEATURES_REPLY) {
        ind_cxn_notify_features_reply_sent(cxn);
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

    if (!ind_cxn_is_handshake_complete(cxn)) {
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
ind_controller_accepts_async_message(const controller_t *controller,
                                     const of_object_t *obj,
                                     connection_t **cxn)
{
    uint8_t aux_id = 0;

    /* Only send certain async messages to the slave */
    if (controller->role == INDIGO_CXN_R_SLAVE &&
        obj->object_id != OF_PORT_STATUS &&
        obj->object_id != OF_BSN_CONTROLLER_CONNECTIONS_REPLY) {
        return 0;
    }

    if (ind_cxn_async_channel_selector_handler != NULL) {
        (*ind_cxn_async_channel_selector_handler)(obj, controller->num_aux,
                                                  &aux_id);
    }

    AIM_ASSERT(aux_id <= controller->num_aux);

    /* If there is no selector for this application or the selected
       channel is not ready for communication, then we should just try
       to send on the main controller connection */
    *cxn = controller->cxns[aux_id];
    if (*cxn) {
        if (ind_cxn_accepts_async_message(*cxn) == 0) {
            if (aux_id != 0) {
                AIM_LOG_INTERNAL("cxn %s state %d, not ready, try on main cxn",
                                 (*cxn)->desc, (*cxn)->state);
                aux_id = 0;
                *cxn = controller->cxns[aux_id];
                if (ind_cxn_accepts_async_message(*cxn) == 0) {
                    return 0;
                }
            } else {
                return 0;
            }
        }
    } else {
        return 0;
    }

    AIM_LOG_TRACE("Selected aux_id: %d, cxn: %s for async %s message",
                  aux_id, (*cxn)->desc, of_object_id_str[obj->object_id]);

    return 1;
}

/**
 * Send an async message to all interested connections.
 */
void
indigo_cxn_send_async_message(of_object_t *obj)
{
    connection_t *cxn;
    controller_t *controller;
    int id;

    /*
     * The connection that will end up sending the original 'obj',
     * rather than a duplicate. indigo_cxn_send_controller_message
     * consumes the LOCI object so we need to call it on the
     * original last.
     */
    indigo_cxn_id_t first_cxn_id = INDIGO_CXN_ID_UNSPECIFIED;

    FOREACH_REMOTE_ACTIVE_CONTROLLER(id, controller) {
        if (ind_controller_accepts_async_message(controller, obj, &cxn) &&
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
                        of_class_name(obj));
        of_object_delete(obj);
    }
}

/**
 * Source for transaction IDs
 */
uint32_t
ind_cxn_xid_get(void)
{
    static uint32_t cur_transaction_id = 0;

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
    int idx;

    AIM_LOG_TRACE("%s", __FUNCTION__);

    if (config == NULL) {
        AIM_LOG_INTERNAL("NULL configuration parameter");
        return INDIGO_ERROR_PARAM;
    }

    INDIGO_MEM_COPY(&cxn_config, config, sizeof(*config));

    /* initialize module state */
    INDIGO_MEM_CLEAR(controllers, sizeof(controllers));
    for (idx = 0; idx < MAX_CONTROLLERS; ++idx) {
        controllers[idx].controller_id = (indigo_controller_id_t)idx;
    }
    INDIGO_MEM_CLEAR(status_change, sizeof(status_change));

    ind_cxn_init_instances();

    ind_cfg_register(&ind_cxn_cfg_ops);

    ind_cxn_generation_id = 0;
    AIM_LOG_VERBOSE("Initial generation id: 0x%016"PRIx64,
                    ind_cxn_generation_id);

    ind_cxn_async_channel_selector_handler = NULL;

    init_done = 1;

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
        controller_t *controller;
        AIM_LOG_VERBOSE("Disabling OF connection mgr");
        /* unregister state timeout handlers */
        FOREACH_ACTIVE_CONTROLLER(id, controller) {
            controller_disconnect(controller);
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
    ind_cfg_unregister(&ind_cxn_cfg_ops);
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

    connection_t *cxn = ind_cxn_id_to_connection(cxn_id);
    if (cxn == NULL) {
        AIM_LOG_ERROR("Attempted to send error message to nonexistent connection " CXN_ID_FMT,
                      CXN_ID_FMT_ARGS(cxn_id));
        return;
    }

    payload.data = OF_OBJECT_BUFFER_INDEX(orig, 0);
    payload.bytes = orig->length;

    xid = of_message_xid_get(OF_BUFFER_TO_MESSAGE(payload.data));

    AIM_LOG_TRACE("Sending error msg to %s, type %d, code %d",
                  cxn->desc, type, code);

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


/* controller list */
void
indigo_controller_list(indigo_controller_info_t** list)
{
    indigo_controller_info_t* head = NULL;
    indigo_controller_id_t id;
    controller_t *controller;
    FOREACH_ACTIVE_CONTROLLER(id, controller) {
        indigo_controller_info_t* entry = aim_malloc(sizeof(*entry));
        AIM_TRUE_OR_DIE(entry != NULL);
        entry->controller_id = id;
        entry->role = controller->role;
        entry->protocol_params = controller->protocol_params;
        entry->config_params = controller->config_params;
        entry->num_aux = controller->num_aux;
        entry->main_cxn_id = controller->cxns[0]? 
            controller->cxns[0]->cxn_id: INDIGO_CXN_ID_UNSPECIFIED;
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

/* reset all nonlistening controllers */
void
ind_cxn_reset(indigo_cxn_id_t cxn_id)
{
    connection_t *cxn;
    controller_t *controller;

    if (!module_enabled) {
        return;
    }

    AIM_LOG_VERBOSE("Connection reset for id " CXN_ID_FMT,
                    CXN_ID_FMT_ARGS(cxn_id));
    if (cxn_id == IND_CXN_RESET_ALL) {
        /* Iterate thru active controllers and reset all but listening */
        indigo_controller_id_t id;
        FOREACH_ACTIVE_CONTROLLER(id, controller) {
            if (!controller->config_params.listen) {
                controller_disconnect(controller);
            }
        }
    } else if (!INDIGO_CXN_INVALID(cxn_id)) {
        cxn = ind_cxn_id_to_connection(cxn_id);
        if (cxn != NULL) {
            controller_stop_cxn(cxn);
        }
    }
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

    connection_t *cxn = ind_cxn_id_to_connection(cxn_id);

    AIM_LOG_TRACE("%s: getting aux id for " CXN_ID_FMT,
                  __FUNCTION__, CXN_ID_FMT_ARGS(cxn_id));

    if (cxn == NULL) {
        AIM_LOG_INTERNAL("Attempted to get auxiliary ID of "
                         "nonexistent connection " CXN_ID_FMT,
                         CXN_ID_FMT_ARGS(cxn_id));
        return INDIGO_ERROR_NOT_FOUND;
    }

    AIM_ASSERT(cxn->controller != NULL);

    *auxiliary_id = cxn->aux_id;
    return INDIGO_ERROR_NONE;
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


/*------------------------------------------------------------
 * Barrier blockers
 *------------------------------------------------------------*/

void
indigo_cxn_block_barrier(indigo_cxn_id_t cxn_id,
                         indigo_cxn_barrier_blocker_t *blocker)
{
    connection_t *cxn;

    if (CXN_ID_VALID(cxn_id)) {
        cxn = ind_cxn_id_to_connection(cxn_id);
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
        connection_t *cxn = ind_cxn_id_to_connection(blocker->cxn_id);
        if (cxn != NULL) {
            ind_cxn_unblock_barrier(cxn);
        }
        blocker->cxn_id = INDIGO_CXN_ID_UNSPECIFIED;
    }

#ifndef NDEBUG
    aim_free(blocker->tracker);

    /* Deliberately leave blocker->tracker as-is to let valgrind catch double
     * frees */
#endif
}

void
indigo_cxn_pause(indigo_cxn_id_t cxn_id)
{
    connection_t *cxn = ind_cxn_id_to_connection(cxn_id);
    AIM_ASSERT(cxn != NULL);
    if (cxn != NULL) {
        ind_cxn_pause(cxn);
    }
}

void
indigo_cxn_resume(indigo_cxn_id_t cxn_id)
{
    connection_t *cxn = ind_cxn_id_to_connection(cxn_id);
    if (cxn != NULL) {
        ind_cxn_resume(cxn);
    }
}


/*------------------------------------------------------------
 * Barrier notification callback bookkeeping
 *------------------------------------------------------------*/

struct barrier_notify_callback {
    indigo_cxn_barrier_notify_f callback;
    void *cookie;
};

#define MAX_BARRIER_NOTIFY_CALLBACKS 4

static struct barrier_notify_callback 
barrier_notify_callbacks[MAX_BARRIER_NOTIFY_CALLBACKS];

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

    AIM_ASSERT(0, "Could not find free slot for barrier callback, "
               "consider increasing MAX_BARRIER_NOTIFY_CALLBACKS");
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


/*------------------------------------------------------------
 * Address parsing
 *------------------------------------------------------------*/

static indigo_error_t
parse_sockaddr_getaddrinfo(int family, const char *addr, int port,
                           struct sockaddr_storage *sockaddr, 
                           socklen_t *sockaddrlen)
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
    *sockaddrlen = ai->ai_addrlen;
    freeaddrinfo(ai);
    return INDIGO_ERROR_NONE;
}

static indigo_error_t
parse_sockaddr_unix(const char *path,
                    struct sockaddr_storage *sockaddr,
                    socklen_t *sockaddrlen)
{
    struct sockaddr_un *sun = (struct sockaddr_un *) sockaddr;
    sun->sun_family = AF_UNIX;
    snprintf(sun->sun_path, sizeof(sun->sun_path), "%s", path);
    *sockaddrlen = sizeof(*sun);
    return INDIGO_ERROR_NONE;
}

indigo_error_t
ind_cxn_parse_sockaddr(const indigo_cxn_protocol_params_t *protocol_params,
                       struct sockaddr_storage *sockaddr,
                       socklen_t *sockaddrlen)
{
    switch (protocol_params->header.protocol) {
    case INDIGO_CXN_PROTO_TCP_OVER_IPV4:
        return parse_sockaddr_getaddrinfo(
            AF_INET,
            protocol_params->tcp_over_ipv4.controller_ip,
            protocol_params->tcp_over_ipv4.controller_port,
            sockaddr, sockaddrlen);
    case INDIGO_CXN_PROTO_TCP_OVER_IPV6:
        return parse_sockaddr_getaddrinfo(
            AF_INET6,
            protocol_params->tcp_over_ipv6.controller_ip,
            protocol_params->tcp_over_ipv6.controller_port,
            sockaddr, sockaddrlen);
    case INDIGO_CXN_PROTO_UNIX:
        return parse_sockaddr_unix(protocol_params->unx.unix_path,
                                   sockaddr, sockaddrlen);
    default:
        AIM_LOG_INTERNAL("Invalid protocol %d",
                         protocol_params->header.protocol);
        return INDIGO_ERROR_PARAM;
    }

    return INDIGO_ERROR_NONE;
}


/*------------------------------------------------------------
 * Utility functions for unit testing only
 *------------------------------------------------------------*/

cxn_state_t unit_test_cxn_state_get(indigo_controller_id_t controller_id,
                                    uint8_t aux_id)
{
    controller_t *controller;

    AIM_ASSERT(CONTROLLER_ID_VALID(controller_id) &&
               CONTROLLER_ID_ACTIVE(controller_id));
    controller = ID_TO_CONTROLLER(controller_id);

    AIM_ASSERT(aux_id < MAX_AUX_CONNECTIONS);

    return controller->cxns[aux_id]->state;
}

int unit_test_controller_count_get(void)
{
    int id;
    controller_t *controller;

    int count = 0;

    FOREACH_ACTIVE_CONTROLLER(id, controller) {
        AIM_LOG_VERBOSE("controller %d:%s(%p) still active",
                        id, controller->desc, controller);
        count++;
    }

    return count;
}
