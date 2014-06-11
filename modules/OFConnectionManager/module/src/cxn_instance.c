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
 * @brief Routines to manage a connection instance
 */

#include "ofconnectionmanager_log.h"

#include <string.h>
#include <errno.h>
#include <unistd.h>

#include "cxn_instance.h"
#include "ofconnectionmanager_int.h"

#include <SocketManager/socketmanager.h>
#include <OFConnectionManager/ofconnectionmanager.h>

#include <indigo/memory.h>
#include <indigo/assert.h>

#include <loci/loci_dump.h>
#include <loci/loci_show.h>
#include <loci/loci_validator.h>

#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <fcntl.h>


/* Short hand logging macros */
#define LOG_ERROR(cxn, fmt, ...)                                        \
    AIM_LOG_ERROR("cxn " CXN_FMT ": " fmt, CXN_FMT_ARGS(cxn) , ##__VA_ARGS__)
#define LOG_WARN(cxn, fmt, ...)                                        \
    AIM_LOG_WARN("cxn " CXN_FMT ": " fmt, CXN_FMT_ARGS(cxn) , ##__VA_ARGS__)
#define LOG_INFO(cxn, fmt, ...)                                         \
    AIM_LOG_INFO("cxn " CXN_FMT ": " fmt, CXN_FMT_ARGS(cxn) , ##__VA_ARGS__)
#define LOG_VERBOSE(cxn, fmt, ...)                                      \
    AIM_LOG_VERBOSE("cxn " CXN_FMT ": " fmt, CXN_FMT_ARGS(cxn) , ##__VA_ARGS__)
#define LOG_TRACE(cxn, fmt, ...)                                        \
    AIM_LOG_TRACE("cxn " CXN_FMT ": " fmt, CXN_FMT_ARGS(cxn) , ##__VA_ARGS__)

#define NO_CXN_LOG_VERBOSE(fmt, ...)                                    \
    AIM_LOG_VERBOSE(fmt, ##__VA_ARGS__)

#define STATE_INFO_INIT(s, t) { .name = #s, .timeout = t }
state_info_t state_info[INDIGO_CXN_S_COUNT] = {
    STATE_INFO_INIT(DISCONNECTED, 0),
    STATE_INFO_INIT(CONNECTING, 5000),
    STATE_INFO_INIT(HANDSHAKE_COMPLETE, 0),
    STATE_INFO_INIT(CLOSING, 5000)
};


/* Maximum number of messages to send per write callback */
#define MAX_WRITE_MSGS 32


/****************************************************************
 *
 * Connection utility routines
 *
 ****************************************************************/

static void periodic_keepalive(void *cookie);

#define VERSION_IS_SET(cxn) ((cxn)->status.negotiated_version > 0)

/**
 * Disconnect and clean up
 *
 * @param icb The connection control block
 */
static void
cleanup_disconnect(connection_t *cxn)
{
    uint8_t *data;
    biglist_t *ble;

    cxn->status.disconnect_count++;

    /* Close this socket. */
    if (cxn->sd >= 0) {
        ind_soc_socket_unregister(cxn->sd);
        close(cxn->sd);
    }
    cxn->sd = -1;

    cxn->generation_id++;

    /* @fixme Is it possible there's a message that should be processed? */
    LOG_VERBOSE(cxn, "Closing connection, current read buf has %d bytes",
                cxn->read_bytes);
    cxn->read_bytes = 0;
    /* Clear write queue */
    BIGLIST_FOREACH_DATA(ble, cxn->output_list, uint8_t *, data) {
        LOG_TRACE(cxn, "Freeing outgoing msg %p", data);
        aim_free(data);
    }
    biglist_free(cxn->output_list);
    cxn->output_list = NULL;

    cxn->bytes_enqueued = 0;
    cxn->pkts_enqueued = 0;
    cxn->output_head_offset = 0;
}


/****************************************************************
 *
 * CONNECTION INSTANCE STATE MACHINE HANDLING
 *
 ****************************************************************/

/**
 * State machine for (non-listen, non-local) Connection Instance
 *
 * +-> disconnected: initial state during connection_add
 * |      |
 * |      | try_to_connect completes successfully,
 * |      |    hello sent
 * |      |
 * |      v
 * |   connecting: TCP connection is established------- error ----+
 * |      |                                                       |
 * |      | features reply sent, handshake done                   |
 * |      |                                                       |
 * |      v                                                       |
 * |   handshake_complete: controller connection is usable        |
 * |           periodically generate echo requests                |
 * |      |                                                       |
 * |      | connection error                                      |
 * |      |                                                       |
 * |      v                                                       |
 * |   closing: cleanup_disconnect called                  <------+
 * |           allow outstanding_op_cnt to be decremented
 * |      |
 * |      | outstanding_op_cnt == 0 or timeout
 * |      |
 * +------+
 *
 * ASSUMPTIONS:
 *
 * The closing state is the only way that a connection instance may
 * transition to disconnected.
 *
 * The state transition routine below is the only one that may call
 * cleanup_disconnect on socket once the TCP connection is established.
 *
 * Transitions in the state manager are edge triggered by events in
 * this connection instance routine.
 *
 * Reconnection attempts while in disconnected are prompted by the
 * connection manager as per its programming.
 *
 * Echo requests are managed by a separate timer event while in
 * handshake_complete.
 *
 */


static inline void
cxn_state_set(connection_t *cxn, indigo_cxn_state_t new_state);

void
ind_cxn_state_set(connection_t *cxn, indigo_cxn_state_t new_state)
{
    cxn_state_set(cxn, new_state);
}


/**
 * @brief Timeout handler for connecting state
 *
 * @param cookie The connection handle
 *
 * Force transition to closing state
 */

static void
cxn_connecting_timeout(void *cookie)
{
    connection_t *cxn;

    cxn = (connection_t *) cookie;

    INDIGO_ASSERT(CONNECTION_STATE(cxn) == INDIGO_CXN_S_CONNECTING);

    LOG_WARN(cxn, "Timeout in connecting state");

    ind_controller_disconnect(cxn->controller);
}

/**
 * @brief Timeout handler for closing state
 *
 * @param cookie The connection handle
 *
 * Force transition to disconnected state
 */

static void
cxn_closing_timeout(void *cookie)
{
    connection_t *cxn;

    cxn = (connection_t *) cookie;

    INDIGO_ASSERT(CONNECTION_STATE(cxn) == INDIGO_CXN_S_CLOSING);

    LOG_WARN(cxn, "Timeout in closing state");

    cxn_state_set(cxn, INDIGO_CXN_S_DISCONNECTED);
}

/**
 * @brief Handle a connection state change event
 * @param cxn The connection being updated
 * @param new_state The state to transition to
 *
 * The new state and old state should be different, but for now just a
 * trace message is printed if that happens.
 *
 * Anything that affects the connection instance state should go through
 * this routine.  In particular, connection disconnect events should all
 * go through here

 */

static inline void
cxn_state_set(connection_t *cxn, indigo_cxn_state_t new_state)
{
    indigo_cxn_state_t old_state;

    old_state = CONNECTION_STATE(cxn);

    if (old_state == new_state) {
        LOG_TRACE(cxn, "Non-state change in %s", CXN_STATE_NAME(new_state));
        return;
    }

    LOG_INFO(cxn, "%s->%s", CXN_STATE_NAME(old_state),
             CXN_STATE_NAME(new_state));

    /****************************************************************
     *
     * Verify pre-conditions
     *
     * @fixme Check here for illegal state transitions
     *
     ****************************************************************/

    switch (new_state) {
    case INDIGO_CXN_S_DISCONNECTED:
        /* If moving to disconnected, must be closing (or disconnected) */
        if ((old_state != INDIGO_CXN_S_CLOSING)) {
            LOG_ERROR(cxn, "Error in cxn SM: disconnected from %s",
                      CXN_STATE_NAME(old_state));
            /* Clean up and hope for the best */
        }
        break;

    default:
        break;
    }


    /****************************************************************
     *
     * Exit conditions for old state
     *
     ****************************************************************/

    switch (old_state) {
    case INDIGO_CXN_S_CLOSING:
        ind_soc_timer_event_unregister(cxn_closing_timeout, (void *)cxn);
        break;
    case INDIGO_CXN_S_CONNECTING:
        if (!(CXN_LOCAL(cxn))) {
            ind_soc_timer_event_unregister(cxn_connecting_timeout,
                                           (void *)cxn);
        }
        break;

    default:
        break;
    }

    /****************************************************************
     *
     * Process change to new state
     *
     ****************************************************************/

    /* Change state of connection */
    cxn->status.state = new_state;

    /* External notification of state change before processing */
    ind_cxn_status_change(cxn);

    /* Post-processing of state transition. */
    switch (new_state) {
    case INDIGO_CXN_S_DISCONNECTED:
        if (cxn->flags & CXN_TO_BE_REMOVED) {
            LOG_VERBOSE(cxn, "Completing cxn removal");
            cxn->active = 0;
        } else if (CXN_LOCAL(cxn)) {
            cxn->active = 0;
        } else {
            /* Disconnected but still active - start connecting again */
            ind_soc_timer_event_register_with_priority(
                ind_cxn_connection_retry_timer, cxn,
                IND_SOC_TIMER_IMMEDIATE, IND_CXN_EVENT_PRIORITY);
        }
        ind_cxn_unregister_debug_counters(cxn);
        ind_cxn_disconnected_init(cxn);
        break;

    case INDIGO_CXN_S_CONNECTING:
        /* Register with socket manager */
        ind_soc_socket_register_with_priority(
            cxn->sd, indigo_cxn_socket_ready_callback,
            cxn, IND_CXN_EVENT_PRIORITY);
        ind_cxn_register_debug_counters(cxn);
        ind_cxn_send_hello(cxn);
        if (CXN_LOCAL(cxn)) {
            /* Recursive call; transition to connected */
            cxn_state_set(cxn, INDIGO_CXN_S_HANDSHAKE_COMPLETE);
        } else {
            ind_soc_timer_event_register_with_priority(
                cxn_connecting_timeout, (void *)cxn,
                CXN_STATE_TIMEOUT(new_state), IND_CXN_EVENT_PRIORITY);
        }
        break;

    case INDIGO_CXN_S_CLOSING:
        ind_soc_timer_event_unregister(periodic_keepalive, (void *)cxn);
        ind_soc_timer_event_register_with_priority(
            cxn_closing_timeout, (void *)cxn,
            CXN_STATE_TIMEOUT(new_state), IND_CXN_EVENT_PRIORITY);
        cleanup_disconnect(cxn);
        break;
    case INDIGO_CXN_S_HANDSHAKE_COMPLETE:
        if (cxn->keepalive.period_ms > 0) {
            /* Set up periodic echo request */
            ind_soc_timer_event_register_with_priority(
                periodic_keepalive, (void *)cxn,
                cxn->keepalive.period_ms, IND_CXN_EVENT_PRIORITY);
        }

        break;

    default:
        break;
    }
}

/****************************************************************
 *
 * Connection instance read buffer management
 *
 ****************************************************************/

/**
 * Check if a hello message has been received
 * @param cxn The connection instance
 * @param obj Pointer to an OF object
 *
 * Before doing anything else, a connection must exchange a hello
 * to negotiate the version to use for the interaction.
 *
 * Since this is only being called if the version is not
 * set, this routine takes ownership of the object obj.
 */
static inline int
check_for_hello(connection_t *cxn, of_object_t *obj)
{
    int rv = INDIGO_ERROR_NONE;

    if (obj->object_id != OF_HELLO) {
        LOG_ERROR(cxn, "Expecting HELLO but received %s message",
                  of_object_id_str[obj->object_id]);
        rv = INDIGO_ERROR_PROTOCOL;
    } else {
        LOG_VERBOSE(cxn, "Received HELLO message (version %d)",
                    obj->version);
        
        indigo_cxn_config_params_t *config_params = get_connection_config(cxn);
        INDIGO_ASSERT(config_params != NULL);
        
        cxn->status.negotiated_version = aim_imin(config_params->version,
                                                  obj->version);

        LOG_VERBOSE(cxn, "Negotiated version %d",
                    cxn->status.negotiated_version);
    }

    return rv;
}

/**
 * Timer handler to send an echo request on a given connection and
 * to check if too many echo requests have been lost.
 *
 * Main connection: Aggressive Echo/Timeout frequency of 2/6 sec
 * On timeout: Disconnect
 * Echo frequency duration is set external to this module
 * 
 * Aux connections: Echo frequency/timeout of 15/45 sec 
 * On timeout: Log an error but do not disconnect
 * Echo frequency duration is set locally
 * 
 * Any time a message is received from the controller, 
 * the outstanding count set to 0.
 */

static void
periodic_keepalive(void *cookie)
{
    of_echo_request_t *echo;
    uint32_t xid = ind_cxn_xid_get();
    connection_t *cxn;

    cxn = (connection_t *)cookie;

    LOG_TRACE(cxn, "Periodic echo request");
    if (CONNECTION_STATE(cxn) != INDIGO_CXN_S_HANDSHAKE_COMPLETE) {
        LOG_VERBOSE(cxn, "Send echo request, but not connected");
        return;
    }

    if (cxn->keepalive.outstanding_echo_cnt > cxn->keepalive.threshold) {
        if (cxn->auxiliary_id == 0) {
            LOG_INFO(cxn, "Exceeded outstanding echo requests. Resetting cxn");
            ind_controller_disconnect(cxn->controller);
        } else {
            LOG_WARN(cxn, "Exceeded outstanding echo requests.");
        } 
        return;
    }

    if ((echo = of_echo_request_new(cxn->status.negotiated_version)) == NULL) {
        LOG_TRACE(cxn, "Could not allocate echo request obj");
        return;
    }

    of_echo_request_xid_set(echo, xid);

    indigo_cxn_send_controller_message(cxn->cxn_id, echo);

    LOG_VERBOSE(cxn, "Sending echo request xid %u", xid);
    cxn->keepalive.outstanding_echo_cnt++;
}

/**
 * Generate a barrier reply and send it to the controller
 */

static indigo_error_t
send_barrier_reply(connection_t *cxn)
{
   of_barrier_reply_t *obj = 0;

   if ((obj = of_barrier_reply_new(cxn->status.negotiated_version)) == 0) {
      LOG_ERROR(cxn, "Failed to allocate barrier reply");
      return INDIGO_ERROR_UNKNOWN;
   }

   of_barrier_reply_xid_set(obj, cxn->barrier.xid);
   LOG_TRACE(cxn, "Responding to barrier request xid %u", cxn->barrier.xid);

   indigo_cxn_send_controller_message(cxn->cxn_id, obj);
   return INDIGO_ERROR_NONE;
}

/**
 * Handle an echo request
 */

static indigo_error_t
echo_request_handle(connection_t *cxn, of_object_t *_obj)
{
    of_echo_request_t *echo = _obj;
    of_echo_reply_t *reply = NULL;
    of_octets_t data;
    uint32_t xid;

    of_echo_request_xid_get(echo, &xid);
    LOG_TRACE(cxn, "Responding to echo with xid %u", xid);

    if ((reply = of_echo_reply_new(echo->version)) == NULL) {
        LOG_TRACE(cxn, "Could not allocate echo response obj");
        return INDIGO_ERROR_RESOURCE;
    }

    of_echo_reply_xid_set(reply, xid);
    of_echo_request_data_get(echo, &data);
    if (data.bytes > 0) {
        if (of_echo_reply_data_set(reply, &data) < 0) {
            of_object_delete(reply);
            return INDIGO_ERROR_UNKNOWN;
        }
    }

    indigo_cxn_send_controller_message(cxn->cxn_id, reply);

    return INDIGO_ERROR_NONE;
}

/**
 * Handle an echo reply
 */

static indigo_error_t
echo_reply_handle(connection_t *cxn, of_object_t *_obj)
{
    of_echo_reply_t *reply = _obj;
    uint32_t xid;
    int rv = INDIGO_ERROR_NONE;

    of_echo_reply_xid_get(reply, &xid);

    LOG_VERBOSE(cxn, "Received echo reply with xid %u", xid);

    return rv;
}

/**
 * Handle a barrier request message
 */

static indigo_error_t
barrier_request_handle(connection_t *cxn, of_object_t *_obj)
{
    of_barrier_request_t *obj = _obj;

    of_barrier_request_xid_get(obj, &cxn->barrier.xid);
    LOG_TRACE(cxn, "Got barrier req with xid %u", cxn->barrier.xid);

    /* No outstanding operations; send reply immediately */
    if (cxn->outstanding_op_cnt == 0)  {
        return (send_barrier_reply(cxn));
    }
    LOG_TRACE(cxn, "Outstanding op count %d", cxn->outstanding_op_cnt);

    /* Pause the socket and mark a barrier is pending */
    if (ind_soc_data_in_pause(cxn->sd) < 0) {
        LOG_ERROR(cxn, "Error pausing soc read on barrier request");
    }
    cxn->barrier.pendingf = 1;

    return (INDIGO_ERROR_NONE);
}

static const char *
role_to_string(indigo_cxn_role_t role)
{
    switch (role) {
    case INDIGO_CXN_R_MASTER: return "master";
    case INDIGO_CXN_R_SLAVE: return "slave";
    case INDIGO_CXN_R_EQUAL: return "equal";
    default: AIM_ASSERT(0); return "unknown";
    }
}

static indigo_cxn_role_t
translate_from_nicira_role(uint32_t wire_role)
{
    switch (wire_role) {
    case 0: return INDIGO_CXN_R_EQUAL;
    case 1: return INDIGO_CXN_R_MASTER;
    case 2: return INDIGO_CXN_R_SLAVE;
    default: return INDIGO_CXN_R_UNKNOWN;
    }
}

static uint32_t
translate_to_nicira_role(indigo_cxn_role_t role)
{
    switch (role) {
    case INDIGO_CXN_R_MASTER: return 1;
    case INDIGO_CXN_R_SLAVE: return 2;
    case INDIGO_CXN_R_EQUAL: return 0;
    default: AIM_ASSERT(0); return 0;
    }
}

/**
 * Handle a Nicira role request
 */

static indigo_error_t
nicira_controller_role_request_handle(connection_t *cxn, of_object_t *_obj)
{
    of_nicira_controller_role_request_t *request;
    of_nicira_controller_role_reply_t *reply = NULL;
    uint32_t xid;
    uint32_t wire_role;
    indigo_cxn_role_t role;

    if ((reply = of_nicira_controller_role_reply_new(_obj->version)) == NULL) {
        return INDIGO_ERROR_RESOURCE;
    }

    request = (of_nicira_controller_role_request_t *)_obj;
    of_nicira_controller_role_request_xid_get(request, &xid);
    of_nicira_controller_role_request_role_get(request, &wire_role);

    role = translate_from_nicira_role(wire_role);
    if (role == INDIGO_CXN_R_UNKNOWN) {
        LOG_ERROR(cxn, "Invalid role in role request message");
        of_object_delete(reply);
        return INDIGO_ERROR_UNKNOWN;
    }

    LOG_VERBOSE(cxn, "Controller %d role request: %s", 
                cxn->controller->controller_id, role_to_string(role));
    if (role != cxn->controller->role) {
        if (role == INDIGO_CXN_R_MASTER) {
            ind_controller_change_master(cxn->controller->controller_id);
        } else {
            LOG_INFO(cxn, "Setting role for controller %d to %s", 
                     cxn->controller->controller_id, role_to_string(role));
            cxn->controller->role = role;
        }
    }

    of_nicira_controller_role_reply_xid_set(reply, xid);
    of_nicira_controller_role_reply_role_set(reply,
        translate_to_nicira_role(cxn->controller->role));

    indigo_cxn_send_controller_message(cxn->cxn_id, reply);
    return INDIGO_ERROR_NONE;
}

static indigo_cxn_role_t
translate_from_openflow_role(uint32_t wire_role)
{
    switch (wire_role) {
    case OF_CONTROLLER_ROLE_EQUAL: return INDIGO_CXN_R_EQUAL;
    case OF_CONTROLLER_ROLE_MASTER: return INDIGO_CXN_R_MASTER;
    case OF_CONTROLLER_ROLE_SLAVE: return INDIGO_CXN_R_SLAVE;
    default: return INDIGO_CXN_R_UNKNOWN;
    }
}

static uint32_t
translate_to_openflow_role(indigo_cxn_role_t role)
{
    switch (role) {
    case INDIGO_CXN_R_MASTER: return OF_CONTROLLER_ROLE_MASTER;
    case INDIGO_CXN_R_SLAVE: return OF_CONTROLLER_ROLE_SLAVE;
    case INDIGO_CXN_R_EQUAL: return OF_CONTROLLER_ROLE_EQUAL;
    default: AIM_ASSERT(0); return 0;
    }
}

/**
 * Handle a role request
 */
static void
role_request_handle(connection_t *cxn, of_object_t *_obj)
{
    of_role_request_t *request = _obj;
    of_role_reply_t *reply = NULL;
    uint32_t xid;
    uint32_t wire_role;
    indigo_cxn_role_t role;
    uint64_t generation_id;

    if ((reply = of_role_reply_new(_obj->version)) == NULL) {
        return;
    }

    request = (of_role_request_t *)_obj;
    of_role_request_xid_get(request, &xid);
    of_role_request_role_get(request, &wire_role);
    of_role_request_generation_id_get(request, &generation_id);

    if (wire_role != OF_CONTROLLER_ROLE_NOCHANGE) {
        role = translate_from_openflow_role(wire_role);
        if (role == INDIGO_CXN_R_UNKNOWN) {
            LOG_VERBOSE(cxn, "Failed role request (bad role)");
            indigo_cxn_send_error_reply(
                cxn->cxn_id, request,
                OF_ERROR_TYPE_ROLE_REQUEST_FAILED,
                OF_ROLE_REQUEST_FAILED_BAD_ROLE);
            of_object_delete(reply);
            return;
        }

        LOG_VERBOSE(cxn, "Controller %d role request: %s gen %"PRIu64,
                    cxn->controller->controller_id, role_to_string(role),
                    generation_id);

        if (role == INDIGO_CXN_R_MASTER || role == INDIGO_CXN_R_SLAVE) {
            if ((int64_t)(generation_id - ind_cxn_generation_id) < 0) {
                LOG_VERBOSE(cxn, "Failed role request (stale generation ID)");
                indigo_cxn_send_error_reply(
                    cxn->cxn_id, request,
                    OF_ERROR_TYPE_ROLE_REQUEST_FAILED,
                    OF_ROLE_REQUEST_FAILED_STALE);
                of_object_delete(reply);
                return;
            } else {
                ind_cxn_generation_id = generation_id;
            }
        }

        if (role != cxn->controller->role) {
            if (role == INDIGO_CXN_R_MASTER) {
                ind_controller_change_master(cxn->controller->controller_id);
            } else {
                LOG_INFO(cxn, "Setting role to %s", role_to_string(role));
                cxn->controller->role = role;
            }
        }
    }

    of_role_reply_xid_set(reply, xid);
    of_role_reply_role_set(reply,
        translate_to_openflow_role(cxn->controller->role));
    of_role_reply_generation_id_set(reply, ind_cxn_generation_id);

    indigo_cxn_send_controller_message(cxn->cxn_id, reply);
}

/**
 * Handle a BSN time request
 */

static void
bsn_time_request_handle(connection_t *cxn, of_object_t *_obj)
{
    of_bsn_time_request_t *request = _obj;
    of_bsn_time_reply_t *reply;
    uint32_t xid;
    uint64_t time_ms;

    of_bsn_time_request_xid_get(request, &xid);

    reply = of_bsn_time_reply_new(request->version);
    if (reply == NULL) {
        LOG_ERROR(cxn, "Failed to allocate of_bsn_time_reply");
        return;
    }

    time_ms = INDIGO_TIME_DIFF_ms(cxn->hello_time, INDIGO_CURRENT_TIME);

    of_bsn_time_reply_xid_set(reply, xid);
    of_bsn_time_reply_time_ms_set(reply, time_ms);

    indigo_cxn_send_controller_message(cxn->cxn_id, reply);
}

/**
 * Handle a BSN controller connections request
 */

static void
bsn_controller_connections_request_handle(connection_t *cxn, of_object_t *_obj)
{
    of_bsn_controller_connections_request_t *request = _obj;
    of_bsn_controller_connections_reply_t *reply;
    uint32_t xid;

    of_bsn_controller_connections_request_xid_get(request, &xid);

    reply = of_bsn_controller_connections_reply_new(request->version);
    if (reply == NULL) {
        LOG_ERROR(cxn, "Failed to allocate of_bsn_controller_connections_reply");
        return;
    }

    of_bsn_controller_connections_reply_xid_set(reply, xid);

    of_list_bsn_controller_connection_t list;
    of_bsn_controller_connections_reply_connections_bind(reply, &list);

    ind_cxn_populate_connection_list(&list);

    indigo_cxn_send_controller_message(cxn->cxn_id, reply);
}

/**
 * Handle a BSN auxiliary connections request
 */

static void
aux_connections_request_handle(connection_t *cxn, of_object_t *_obj)
{
    of_bsn_set_aux_cxns_request_t *request = _obj;
    of_bsn_set_aux_cxns_reply_t *reply;
    uint32_t xid;
    uint32_t num_aux;
    uint32_t status = 0;

    of_bsn_set_aux_cxns_request_xid_get(request, &xid);

    reply = of_bsn_set_aux_cxns_reply_new(request->version);
    if (reply == NULL) {
        LOG_ERROR(cxn, "Failed to allocate of_bsn_set_aux_cxns_reply");
        return;
    }

    of_bsn_set_aux_cxns_reply_xid_set(reply, xid);
    
    /* get the number of aux connections to set up */
    of_bsn_set_aux_cxns_request_num_aux_get(request, &num_aux);    
 
    LOG_TRACE(cxn, "of_bsn_set_aux_cxns_request received to setup %d aux cxn's"
              " for controller %d", num_aux, cxn->controller->controller_id);    
   
    status = ind_aux_connection_add(cxn, num_aux);  
    of_bsn_set_aux_cxns_reply_status_set(reply, status);
    indigo_cxn_send_controller_message(cxn->cxn_id, reply);
}


/**
 * Increment the outstanding op count
 * @param cxn
 */

void
ind_cxn_block_barrier(connection_t *cxn)
{
    cxn->outstanding_op_cnt++;
}

/**
 * Decrement the outstanding op count and possibly send a barrier reply
 * @param cxn
 */

void
ind_cxn_unblock_barrier(connection_t *cxn)
{
    INDIGO_ASSERT(cxn->outstanding_op_cnt > 0);
    cxn->outstanding_op_cnt -= 1;

    LOG_TRACE(cxn, "Op count %d", cxn->outstanding_op_cnt);

    /* Check if outstanding ops is now 0 and clean up if needed */
    if (cxn->outstanding_op_cnt == 0) {
        if (CONNECTION_STATE(cxn) == INDIGO_CXN_S_CLOSING) {
            LOG_TRACE(cxn, "Op count 0, disconnecting");
            cxn_state_set(cxn, INDIGO_CXN_S_DISCONNECTED);
        } else if (cxn->barrier.pendingf) {
            LOG_TRACE(cxn, "Op count 0, sending barrier reply");
            send_barrier_reply(cxn);
            cxn->barrier.pendingf = 0;
            (void)ind_soc_data_in_resume(cxn->sd);
        }
    }
}


/**
 * Process an object pulled off a connection.
 *
 * @param cxn Connection from which message arrived
 * @param obj The message object
 *
 * Handle echo request, echo reply and barrier request locally
 */
static void
of_msg_process(connection_t *cxn, of_object_t *obj)
{
    /* Note that the messages handled in cxn_instance are not tracked */
    switch (obj->object_id) {
    case OF_ECHO_REQUEST:
        echo_request_handle(cxn, obj);
        return;

    case OF_ECHO_REPLY:
        echo_reply_handle(cxn, obj);
        return;

    case OF_BARRIER_REQUEST:
        barrier_request_handle(cxn, obj);
        return;

    case OF_NICIRA_CONTROLLER_ROLE_REQUEST:
        nicira_controller_role_request_handle(cxn, obj);
        return;

    case OF_ROLE_REQUEST:
        role_request_handle(cxn, obj);
        return;

    case OF_BSN_TIME_REQUEST:
        bsn_time_request_handle(cxn, obj);
        return;

    case OF_BSN_CONTROLLER_CONNECTIONS_REQUEST:
        bsn_controller_connections_request_handle(cxn, obj);
        return;

    case OF_BSN_SET_AUX_CXNS_REQUEST:
        aux_connections_request_handle(cxn, obj);
        return;

    /* Check permissions and fall through */
    case OF_FLOW_ADD:
    case OF_FLOW_DELETE:
    case OF_FLOW_DELETE_STRICT:
    case OF_FLOW_MODIFY:
    case OF_FLOW_MODIFY_STRICT:
    case OF_PACKET_OUT:
    case OF_PORT_MOD:
    case OF_SET_CONFIG:
    case OF_BSN_SET_MIRRORING:
    case OF_BSN_SET_PKTIN_SUPPRESSION_REQUEST:
    case OF_GROUP_ADD:
    case OF_GROUP_MODIFY:
    case OF_GROUP_DELETE:
    case OF_BSN_SET_SWITCH_PIPELINE_REQUEST:
        if (cxn->controller->role == INDIGO_CXN_R_SLAVE) {
            uint16_t code = cxn->status.negotiated_version < OF_VERSION_1_2 ?
                OF_REQUEST_FAILED_EPERM : OF_REQUEST_FAILED_IS_SLAVE;
            LOG_VERBOSE(cxn, "Rejecting %s from slave connection",
                        of_object_id_str[obj->object_id]);
            indigo_cxn_send_error_reply(cxn->cxn_id, obj,
                                        OF_ERROR_TYPE_BAD_REQUEST, code);
            return;
        }

    default:
        break;
    }

    OF_MSG_CALLBACK(cxn, obj);
}

/**
 * Is object a message?  Should be if we're sending it
 */
#define IS_MSG_OBJ(obj) \
    ((obj)->object_id >= 0 && (obj)->object_id < OF_MESSAGE_OBJECT_COUNT)

#define READING_HEADER(cxn) (((cxn)->read_bytes) < OF_MESSAGE_HEADER_LENGTH)

/**
 * Read from the cxn, up to cxn->bytes_needed bytes; update bytes needed
 *
 * Return number of bytes read if no error
 * Return < 0, error number, if error.
 *
 * Read returning 0 is always an error.
 * Note that EAGAIN, EWOULDBLOCK are not considered errors
 * when read returns < 0.
 */

static int
read_from_cxn(connection_t *cxn)
{
    ssize_t bytes_in;
    uint8_t *inbuf_start;

    inbuf_start = &cxn->read_buffer[cxn->read_bytes];
    bytes_in = read(cxn->sd, inbuf_start, cxn->bytes_needed);

    /*
     * Reading 0 bytes indicates connection has closed, although we allow
     * for EAGAIN and EWOULDBLOCK
     */

    if (bytes_in <= 0) {
        if (bytes_in == 0) { /* Socket is closed */
            LOG_INFO(cxn, "Connection closed by remote host");
            return INDIGO_ERROR_CONNECTION;
        }

        if (errno == EAGAIN || errno == EWOULDBLOCK) {
            LOG_TRACE(cxn, "Error reading from socket: %s", strerror(errno));
            return 0;
        }

        LOG_ERROR(cxn, "Error reading from socket: %s", strerror(errno));
        ++ind_cxn_internal_errors;
        return INDIGO_ERROR_CONNECTION;
    }

    cxn->status.bytes_in += bytes_in;
#if defined(DUMP_OBJECTS_AND_DATA)
    cxn_data_hexdump(&cxn->read_buffer[cxn->read_bytes], bytes_in);
#endif

    INDIGO_ASSERT((int)bytes_in <= cxn->bytes_needed);
    cxn->read_bytes += bytes_in;
    cxn->bytes_needed -= bytes_in;

    return bytes_in;
}

/**
 * Try to read a full message from the connnection
 *
 * @returns INDIGO_ERROR_NONE if message is ready
 * @returns INDIGO_ERROR_PENDING if message is not ready
 * @returns INDIGO_ERROR_CONNECTION if a read error has occurred
 * @returns INDIGO_ERROR_PROTOCOL if the data stream has illegal values
 *
 * If INDIGO_ERROR_NONE is returned, a message is ready to be processed
 * in the connection's read buffer.
 */

static inline int
read_message(connection_t *cxn)
{
    uint8_t *msg = NULL;
    int msg_bytes;
    int rv = INDIGO_ERROR_NONE;

    /* Break out of message processing loop after a barrier */
    if (cxn->barrier.pendingf) {
        return INDIGO_ERROR_PENDING;
    }

    /* No bytes needed; must be stuck. */
    if (cxn->bytes_needed == 0) {
        LOG_TRACE(cxn, "Processing appears to be blocked");
        return INDIGO_ERROR_PENDING;
    }

    if (READING_HEADER(cxn)) {
        INDIGO_ASSERT(cxn->bytes_needed + cxn->read_bytes ==
                      OF_MESSAGE_HEADER_LENGTH);
        if ((rv = read_from_cxn(cxn)) < 0) {
            return rv;
        }

        if (cxn->bytes_needed != 0) {
            LOG_TRACE(cxn, "Still need %d bytes for msg hdr",
                      cxn->bytes_needed);
            return INDIGO_ERROR_PENDING;
        }

        msg = cxn->read_buffer;
        msg_bytes = of_message_length_get(msg);
        if (msg_bytes < OF_MESSAGE_HEADER_LENGTH) {
            LOG_TRACE(cxn, "Illegal msg length %d. Framing error?", msg_bytes);
            ++ind_cxn_internal_errors;
            return INDIGO_ERROR_PROTOCOL;
        }
        cxn->bytes_needed = msg_bytes - OF_MESSAGE_HEADER_LENGTH;
    }

    /* Check if the message only needed the header */
    if (cxn->bytes_needed == 0) {
        return INDIGO_ERROR_NONE;
    }

    /* Read the rest of the message; return if error */
    if ((rv = read_from_cxn(cxn)) < 0) {
        return rv;
    }
    if (cxn->bytes_needed == 0) { /* Read full message, return ready */
        return INDIGO_ERROR_NONE;
    }

    /* Still need more bytes; return pending */
    return INDIGO_ERROR_PENDING;
}

/**
 * Send an error for a message that we couldn't parse
 *
 * This is trickier than usual because we can't trust the message
 * (it failed validation).
 */
static void
send_parse_error_message(connection_t *cxn, uint8_t *buf, int len)
{
    of_object_t *error_msg;
    uint32_t xid;
    uint16_t code;
    of_octets_t payload;

    if (len < OF_MESSAGE_MIN_LENGTH) {
        xid = 0;
    } else {
        xid = of_message_xid_get(OF_BUFFER_TO_MESSAGE(buf));
    }

    if (len < OF_MESSAGE_MIN_LENGTH) {
        code = OF_REQUEST_FAILED_BAD_LEN;
    } else if (!OF_VERSION_OKAY(of_message_version_get(
            OF_BUFFER_TO_MESSAGE(buf)))) {
        code = OF_REQUEST_FAILED_BAD_VERSION;
    } else {
        code = OF_REQUEST_FAILED_BAD_TYPE;
    }

    payload.data = buf;
    payload.bytes = len;

    error_msg = of_bad_request_error_msg_new(cxn->status.negotiated_version);
    if (error_msg == NULL) {
        LOG_ERROR(cxn, "Could not allocate error message");
        return;
    }

    of_bad_request_error_msg_xid_set(error_msg, xid);
    of_bad_request_error_msg_code_set(error_msg, code);

    if (of_bad_request_error_msg_data_set(error_msg, &payload) < 0) {
        LOG_WARN(cxn, "Failed to append original request to error message");
    }

    indigo_cxn_send_controller_message(cxn->cxn_id, error_msg);
}

/**
 * Process a message from the read buffer
 *
 * The read buffer must have a valid message in it to be processed
 *
 * The LOCI object is created on the stack and points directly to the read
 * buffer, so its lifetime is limited to this stack frame. Message handlers
 * that need to keep it around for longer must copy it with of_object_dup.
 */

static inline void
process_message(connection_t *cxn)
{
    of_object_t *obj;
    int len;
    int rv;
    of_object_storage_t obj_storage;

    /* Clear read buffer for next read */
    len = cxn->read_bytes;
    cxn->read_bytes = 0;
    cxn->bytes_needed = OF_MESSAGE_HEADER_LENGTH;

    obj = of_object_new_from_message_preallocated(&obj_storage, cxn->read_buffer, len);
    if (obj == NULL) {
        LOG_ERROR(cxn, "Could not parse msg to OF object, len %d", len);
        send_parse_error_message(cxn, cxn->read_buffer, len);
        return;
    }

    if(cxn->trace_pvs) {
        aim_printf(cxn->trace_pvs, "** of_msg_trace: received from cxn " CXN_FMT "\n",
                   CXN_FMT_ARGS(cxn));
        of_object_dump((loci_writer_f)aim_printf, cxn->trace_pvs, obj);
        aim_printf(cxn->trace_pvs, "**\n\n");
    }

    if (CXN_HANDSHAKE_COMPLETE(cxn)) {
        /* We have a message from the controller.  Reset keepalive timeout */
        cxn->keepalive.outstanding_echo_cnt = 0;

#if OFCONNECTIONMANAGER_CONFIG_ECHO_OPTIMIZATION == 1
        if (cxn->keepalive.period_ms > 0) {
            ind_soc_timer_event_register_with_priority(
                periodic_keepalive, (void *)cxn,
                cxn->keepalive.period_ms, IND_CXN_EVENT_PRIORITY);
        }
#endif

    }

    {       /***** Debug info about message *****/
        uint32_t xid = of_message_xid_get(OF_BUFFER_TO_MESSAGE(
            OF_OBJECT_BUFFER_INDEX(obj, 0)));
        LOG_VERBOSE(cxn, "Received %s message xid %u",
                    of_object_id_str[obj->object_id], xid);
        LOG_OBJECT(obj);

        AIM_ASSERT(IS_MSG_OBJ(obj));
        debug_counter_inc(&cxn->rx_counters[obj->object_id]);
        cxn->status.messages_in++;
    }

    /* FIXME:  Needs to be generalized to "handshake" state */
    if (!VERSION_IS_SET(cxn)) {/* Get version from initial hello message */
        if ((rv = check_for_hello(cxn, obj)) < 0) {
            LOG_ERROR(cxn, "Failed to check for hello", indigo_strerror(rv));
            /* @fixme Should state be updated for some return codes? */
        }
    } else {
        /* Process received message */
        of_msg_process(cxn, obj);
    }
}

/**
 * Process the connection socket for reading
 *
 * @returns INDIGO_ERROR_NONE if no socket error
 * @returns INDIGO_ERROR_CONNECTION if socket error
 */

int
ind_cxn_process_read_buffer(connection_t *cxn)
{
    int rv = INDIGO_ERROR_NONE;
    int i = 0;

    while ((rv = read_message(cxn)) == INDIGO_ERROR_NONE) {
        process_message(cxn);
        if (++i >= OFCONNECTIONMANAGER_CONFIG_MAX_MSGS_PER_TICK ||
                ind_soc_should_yield()) {
            break;
        }
    }

    return rv;
}

/**
 * Force a connection to start the disconnection process
 */

void ind_cxn_disconnect(connection_t *cxn)
{
    LOG_VERBOSE(cxn, "Forcing disconnection");

    if (CONNECTION_STATE(cxn) != INDIGO_CXN_S_DISCONNECTED) {
        if (CONNECTION_STATE(cxn) == INDIGO_CXN_S_HANDSHAKE_COMPLETE) {
            cxn->status.forced_disconnect_count++;
        }
        ind_cxn_state_set(cxn, INDIGO_CXN_S_CLOSING);
        if (cxn->outstanding_op_cnt == 0) {
            cxn_state_set(cxn, INDIGO_CXN_S_DISCONNECTED);
        }
    } else {
        cleanup_disconnect(cxn);
    }
}

/****************************************************************
 *
 * Connection instance write buffer management
 *
 ****************************************************************/

/**
 * Process messages waiting to be sent to a connection socket
 *
 * @returns The number of bytes written or an error code
 */

int
ind_cxn_process_write_buffer(connection_t *cxn)
{
    int written, left;
    int num_iovecs = 0;
    struct iovec iovecs[MAX_WRITE_MSGS];
    biglist_t *cur_node;
    int i;

    /* Iterate over cxn->output_list adding buffers to iovecs */
    cur_node = cxn->output_list;
    while (cur_node != NULL && num_iovecs < MAX_WRITE_MSGS) {
        struct iovec *iov = &iovecs[num_iovecs];
        iov->iov_base = BIGLIST_CAST(void *, cur_node);
        iov->iov_len = of_message_length_get(iov->iov_base);
        if (num_iovecs == 0) {
            /* First buffer may be partially written */
            iov->iov_base += cxn->output_head_offset;
            iov->iov_len -= cxn->output_head_offset;
        }
        num_iovecs++;
        cur_node = biglist_next(cur_node);
    }

    written = writev(cxn->sd, iovecs, num_iovecs);

    if (written < 0) {
        /* Error writing to connection socket */
        LOG_ERROR(cxn, "Error writing to socket: %s", strerror(errno));
        return INDIGO_ERROR_UNKNOWN;
    }

    /*
     * Iterate over cxn->output_list and iovecs together, freeing completely
     * sent messages.
     */
    left = written;
    for (i = 0; i < num_iovecs; i++) {
        struct iovec *iov = &iovecs[i];
        int to_write, bytes_out;
        cur_node = cxn->output_list;

        /* Number of bytes we attempted to send in this message */
        to_write = iov->iov_len;

        /* Number of bytes we actually sent in this message */
        bytes_out = aim_imin(left, to_write);
        cxn->bytes_enqueued -= bytes_out;

        if (bytes_out == to_write) { /* Completed this message */
            aim_free(BIGLIST_CAST(void *, cur_node));
            cxn->output_list =
                biglist_remove_link_free(cxn->output_list, cur_node);
            cxn->pkts_enqueued--;
            cxn->status.messages_out++;
            cxn->output_head_offset = 0;
        } else {
            /* Partial write */
            INDIGO_ASSERT(bytes_out < to_write);
            cxn->output_head_offset += bytes_out;
            break;
        }

        left -= bytes_out;
    }

    if (cxn->output_list == NULL) { /* Nothing (more) to send */
        LOG_TRACE(cxn, "No more data to write");
        INDIGO_ASSERT(cxn->bytes_enqueued == 0);
        INDIGO_ASSERT(cxn->pkts_enqueued == 0);
        CXN_WRITE_CLEAR(cxn->sd);
    }

    return written;
}

/**
 * Enqueue data into the write buffer for transmission to a controller
 *
 * @param cxn The connection handle
 * @param data Pointer to a message to be sent
 * @param len Number of bytes to be sent out
 *
 * @returns Error code
 *
 * Takes ownership of data unless an error is returned.
 */

int
ind_cxn_instance_enqueue(connection_t *cxn, uint8_t *data, int len)
{
    int msg_len;

    LOG_TRACE(cxn, "Enqueuing %d bytes", len);
    LOG_TRACE(cxn, "Cur len %d bytes, %d pkts",
              cxn->bytes_enqueued, cxn->pkts_enqueued);

    /* See notes about WRITE_BUFFER_SIZE in cxn_instance.h */
    if (len > CXN_WRITE_BYTES_AVAIL(cxn)) {
        return INDIGO_ERROR_RESOURCE;
    }

    /* Verify that the length is what is reported by the OF msg */
    msg_len = of_message_length_get(data);
    if (len != msg_len) {
        LOG_ERROR(cxn, "Error in message length: %d != %d, discarding",
                  len, msg_len);
        return INDIGO_ERROR_UNKNOWN;
    }
    cxn->output_list = biglist_append(cxn->output_list, (void *)data);
    cxn->bytes_enqueued += len;
    cxn->pkts_enqueued += 1;

    /* Indicate data is ready to the socket manager */
    INDIGO_ASSERT(cxn->bytes_enqueued > 0);
    INDIGO_ASSERT(cxn->pkts_enqueued > 0);
    CXN_WRITE_READY(cxn->sd);

    return INDIGO_ERROR_NONE;
}

/**
 * Send a hello message to the given connection
 */

int
ind_cxn_send_hello(connection_t *cxn)
{
    of_hello_t *hello;
    int rv = INDIGO_ERROR_NONE;
    indigo_cxn_config_params_t *config_params;

    LOG_TRACE(cxn, "Sending hello");
    
    config_params = get_connection_config(cxn);
    INDIGO_ASSERT(config_params != NULL);

    if ((hello = of_hello_new(config_params->version)) == NULL) {
        LOG_ERROR(cxn, "Could not allocate hello object");
        return INDIGO_ERROR_RESOURCE;
    }

    of_hello_xid_set(hello, (uint32_t)ind_cxn_xid_get());

    indigo_cxn_send_controller_message(cxn->cxn_id, hello);

    cxn->hello_time = INDIGO_CURRENT_TIME;

    return rv;
}


/**
 * Attempt to connect to a controller instance.
 * @param cxn The instance control block
 * @returns 0 if TCP connection is successful and state is now CONNECTING
 * @returns -1 if no connection established
 *
 * Assumes connection is not local
 */
int
ind_cxn_try_to_connect(connection_t *cxn)
{
    int rv;
    indigo_cxn_protocol_params_t *protocol_params;
    indigo_cxn_params_tcp_over_ipv4_t *params;
    struct sockaddr_in cxn_addr;
    cxn->fail_count++;

    if (CONNECTION_STATE(cxn) != INDIGO_CXN_S_DISCONNECTED) {
        LOG_ERROR(cxn, "Called try to connect when state is %s",
                  CXN_STATE_NAME(CONNECTION_STATE(cxn)));
        return -1;
    }

    protocol_params = get_connection_params(cxn);
    INDIGO_ASSERT(protocol_params != NULL);
    params = &protocol_params->tcp_over_ipv4;

    if (cxn->sd < 0) {
        /* Attempt to create the socket */
        int soc_flags;

        cxn->sd = socket(AF_INET, SOCK_STREAM, 0);
        if (cxn->sd < 0) {
            LOG_ERROR(cxn, "Failed to create controller connection socket: %s",
                      strerror(errno));
            return -1;
        }

        soc_flags = fcntl(cxn->sd, F_GETFL, 0);
        if (soc_flags == -1 || fcntl(cxn->sd, F_SETFL,
                                     soc_flags | O_NONBLOCK) == -1) {
            LOG_ERROR(cxn, "Failed to set non-blocking flag for socket: %s",
                      strerror(errno));
            close(cxn->sd);
            cxn->sd = -1;
            return -1;
        }

        /* Disable Nagle's algorithm */
        {
            int flag = 1;
            (void) setsockopt(cxn->sd, IPPROTO_TCP, TCP_NODELAY,
                              (char *) &flag, sizeof(int));
        }
    }

    LOG_TRACE(cxn, "Attempting to connect");

    cxn_addr.sin_family = AF_INET;
    cxn_addr.sin_port = htons(params->controller_port);
    if (inet_pton(AF_INET, params->controller_ip, &cxn_addr.sin_addr) != 1) {
        LOG_ERROR(cxn, "Could not convert %s to inet address",
                  params->controller_ip);
        close(cxn->sd);
        cxn->sd = -1;
        return -1;
    }

    rv = connect(cxn->sd, (struct sockaddr *) &cxn_addr, sizeof(cxn_addr));
    if (rv != 0 && errno == EISCONN) {
        LOG_VERBOSE(cxn, "errno is EISCONN, treating as connected");
        rv = 0;
    } else if ((rv != 0) &&
               (errno != EAGAIN) &&
               (errno != EINPROGRESS) &&
               (errno != EALREADY)) {
        if ((cxn->fail_count & (cxn->fail_count - 1)) == 0) {
            LOG_INFO(cxn, "Could not connect in %d tries: %s",
                     cxn->fail_count, strerror(errno));
        }
        close(cxn->sd);
        cxn->sd = -1;
        return -1;
    }

    if (rv == 0) {
        cxn->fail_count = 0;
        cxn_state_set(cxn, INDIGO_CXN_S_CONNECTING);
    }

    return rv;
}

/**
 * Initialize an instance of a connection as disconnected
 *
 * Assumes the protocol and config params are initialized
 */
void
ind_cxn_disconnected_init(connection_t *cxn)
{
    cxn->status.state = INDIGO_CXN_S_DISCONNECTED;
    cxn->controller->role = INDIGO_CXN_R_EQUAL;
    cxn->status.negotiated_version = OF_VERSION_UNKNOWN;
    cxn->bytes_needed = OF_MESSAGE_HEADER_LENGTH;
    cxn->flags = 0;
    cxn->outstanding_op_cnt = 0;
    cxn->barrier.pendingf = 0;
    cxn->keepalive.outstanding_echo_cnt = 0;
    cxn->status.bytes_in = 0;
    cxn->status.bytes_out = 0;
    cxn->status.messages_in = 0;
    cxn->status.messages_out = 0;
    cxn->fail_count = 0;
    cxn->hello_time = 0;
}

/**
 * @brief Calculate timeout between connection attempts.
 *
 * Exponential backoff up to a limit of 1 second.
 */

static int
connection_retry_ms(const connection_t *cxn)
{
    if (cxn->fail_count < 10) {
        return 1 << cxn->fail_count;
    } else {
        return 1000;
    }
}

/**
 * @brief Attempt to connect and reschedule if failed or in progress.
 *
 * @param cookie The connection (connection_t *)
 */

void
ind_cxn_connection_retry_timer(void *cookie)
{
    connection_t *cxn = cookie;
    INDIGO_ASSERT(CXN_ACTIVE(cxn));
    INDIGO_ASSERT(CONNECTION_STATE(cxn) == INDIGO_CXN_S_DISCONNECTED);
    if (ind_cxn_try_to_connect(cxn) == 0) {
        ind_soc_timer_event_unregister(ind_cxn_connection_retry_timer, cxn);
    } else {
        ind_soc_timer_event_register_with_priority(
            ind_cxn_connection_retry_timer, cxn,
            connection_retry_ms(cxn), IND_CXN_EVENT_PRIORITY);
    }
}

void
ind_cxn_register_debug_counters(connection_t *cxn)
{
    int i;
    const int skip = 3; /* "of_" prefix */

    {
        char name[DEBUG_COUNTER_NAME_SIZE];
        aim_snprintf(name, sizeof(name), "cxn." CXN_FMT ".tx_drop", CXN_FMT_ARGS(cxn));
        name[sizeof(name)-1] = '\0';
        char *description = "Outgoing message dropped by the switch due to long send queue";
        debug_counter_register(&cxn->tx_drop_counter, aim_strdup(name), description);
    }

    for (i = 0; i < OF_MESSAGE_OBJECT_COUNT; i++) {
        char name[DEBUG_COUNTER_NAME_SIZE];
        aim_snprintf(name, sizeof(name), "cxn." CXN_FMT ".rx.%s", CXN_FMT_ARGS(cxn), of_object_id_str[i]+skip);
        name[sizeof(name)-1] = '\0';
        char *description = "Message received by the switch";
        debug_counter_register(&cxn->rx_counters[i], aim_strdup(name), description);
    }

    for (i = 0; i < OF_MESSAGE_OBJECT_COUNT; i++) {
        char name[DEBUG_COUNTER_NAME_SIZE];
        aim_snprintf(name, sizeof(name), "cxn." CXN_FMT ".tx.%s", CXN_FMT_ARGS(cxn), of_object_id_str[i]+skip);
        name[sizeof(name)-1] = '\0';
        char *description = "Message sent from the switch";
        debug_counter_register(&cxn->tx_counters[i], aim_strdup(name), description);
    }
}

void
ind_cxn_unregister_debug_counters(connection_t *cxn)
{
    int i;

    {
        char *name = (char *) cxn->tx_drop_counter.name;
        debug_counter_unregister(&cxn->tx_drop_counter);
        aim_free(name);
    }

    for (i = 0; i < OF_MESSAGE_OBJECT_COUNT; i++) {
        debug_counter_t *counter = &cxn->rx_counters[i];
        char *name = (char *) counter->name;
        debug_counter_unregister(counter);
        aim_free(name);
    }

    for (i = 0; i < OF_MESSAGE_OBJECT_COUNT; i++) {
        debug_counter_t *counter = &cxn->tx_counters[i];
        char *name = (char *) counter->name;
        debug_counter_unregister(counter);
        aim_free(name);
    }
}
