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
 * @brief Routines to manage a connection instance
 */

#include "ofconnectionmanager_log.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>

#include "ofconnectionmanager_int.h"

#include <SocketManager/socketmanager.h>
#include <OFConnectionManager/ofconnectionmanager.h>

#include <indigo/memory.h>
#include <indigo/assert.h>

#include <loci/loci_dump.h>

#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <fcntl.h>

#include <openssl/ssl.h>
#include <openssl/err.h>

#include "cxn_instance.h"


/* Short hand logging macros */
#define LOG_MSG(cxn, fmt, ...)                                  \
    AIM_LOG_MSG("cxn %s: " fmt, cxn->desc, ##__VA_ARGS__)
#define LOG_ERROR(cxn, fmt, ...)                                \
    AIM_LOG_ERROR("cxn %s: " fmt, cxn->desc, ##__VA_ARGS__)
#define LOG_WARN(cxn, fmt, ...)                                 \
    AIM_LOG_WARN("cxn %s: " fmt, cxn->desc, ##__VA_ARGS__)
#define LOG_INFO(cxn, fmt, ...)                                 \
    AIM_LOG_INFO("cxn %s: " fmt, cxn->desc, ##__VA_ARGS__)
#define LOG_VERBOSE(cxn, fmt, ...)                              \
    AIM_LOG_VERBOSE("cxn %s: " fmt, cxn->desc, ##__VA_ARGS__)
#define LOG_TRACE(cxn, fmt, ...)                                \
    AIM_LOG_TRACE("cxn %s: " fmt, cxn->desc, ##__VA_ARGS__)
#define LOG_INTERNAL(cxn, fmt, ...)                             \
    AIM_LOG_INTERNAL("cxn %s(%p): " fmt, cxn->desc, cxn, ##__VA_ARGS__)


/* Forward declaractions */
static void
cxn_state_set(connection_t *cxn, cxn_state_t new_state);
static indigo_error_t
cxn_try_to_connect(connection_t *cxn);
static indigo_error_t
cxn_try_to_tls_handshake(connection_t *cxn);


/* Maximum number of messages to send per write callback */
#define MAX_WRITE_MSGS 32


/**
 * Connection control blocks, indexed by connection index
 */
static connection_t connection[MAX_CONNECTIONS];

/****************************************************************
 * Connection instance bookkeeping
 ****************************************************************/

#define ITERATE_OVER_ALL_CXNS(_idx, _cxn)                               \
    for (_idx = 0, _cxn = &connection[0];                               \
         _idx < MAX_CONNECTIONS;                                        \
         ++_idx, _cxn = &connection[_idx])

/* Includes local connection */
#define FOREACH_ACTIVE_CXN(_idx, _cxn)                                  \
    ITERATE_OVER_ALL_CXNS(_idx, _cxn)                                   \
    if (CXN_ACTIVE(_cxn))

/* Only remote connections */
#define FOREACH_REMOTE_ACTIVE_CXN(_idx, _cxn)                           \
    ITERATE_OVER_ALL_CXNS(_idx, _cxn)                                   \
    if (CXN_ACTIVE(_cxn) && !CXN_LOCAL(_cxn))

/* All remote main connections which completed hand-shake and with 
 * requested role */
#define FOREACH_MAIN_HS_COMPLETE_CXN_WITH_ROLE(_idx, _cxn, _cxn_role)   \
    ITERATE_OVER_ALL_CXNS(_idx, _cxn)                                   \
    if (CXN_ACTIVE(_cxn) && !CXN_LOCAL(_cxn) &&                         \
        (_cxn->aux_id == 0) &&                                          \
        (_cxn->controller->role == _cxn_role) &&                        \
        ind_cxn_is_handshake_complete(_cxn))


static connection_t *
find_free_connection(void) {
    int idx;
    for (idx = 0; idx < MAX_CONNECTIONS; ++idx) {
        if (!connection[idx].active) {
            return &connection[idx];
        }
    }

    return NULL;
}

static void
init_single_instance(connection_t *cxn, indigo_cxn_id_t cxn_id)
{
    INDIGO_MEM_CLEAR(cxn, sizeof(connection_t));
    cxn->cxn_id = cxn_id;
}

void
ind_cxn_init_instances(void)
{
    int idx;

    for (idx = 0; idx < MAX_CONNECTIONS; ++idx) {
        /* implicitly zero generation id */
        init_single_instance(&connection[idx], (indigo_cxn_id_t) idx);
    }
}

connection_t *
ind_cxn_id_to_connection(indigo_cxn_id_t cxn_id)
{
    AIM_ASSERT(CXN_ID_TO_INDEX(cxn_id) < MAX_CONNECTIONS,
               "invalid connection id %d", cxn_id);
    connection_t *cxn = &connection[CXN_ID_TO_INDEX(cxn_id)];
    if (cxn->cxn_id != cxn_id) {
        return NULL;
    }
    AIM_ASSERT(cxn->active);
    return cxn;
}


/*------------------------------------------------------------
 * Debug counter handling
 *------------------------------------------------------------*/

static void
cxn_register_debug_counters(connection_t *cxn)
{
    int i;
    const int skip = 3; /* "of_" prefix */

    {
        char name[DEBUG_COUNTER_NAME_SIZE];
        aim_snprintf(name, sizeof(name), "cxn.%s.tx_drop", cxn->desc);
        name[sizeof(name)-1] = '\0';
        char *description = "Outgoing message dropped by the switch due to long send queue";
        debug_counter_register(&cxn->tx_drop_counter, aim_strdup(name), description);
    }

    for (i = 0; i < OF_MESSAGE_OBJECT_COUNT; i++) {
        char name[DEBUG_COUNTER_NAME_SIZE];
        aim_snprintf(name, sizeof(name), "cxn.%s.rx.%s",
                     cxn->desc, of_object_id_str[i]+skip);
        name[sizeof(name)-1] = '\0';
        char *description = "Message received by the switch";
        debug_counter_register(&cxn->rx_counters[i], aim_strdup(name), description);
    }

    for (i = 0; i < OF_MESSAGE_OBJECT_COUNT; i++) {
        char name[DEBUG_COUNTER_NAME_SIZE];
        aim_snprintf(name, sizeof(name), "cxn.%s.tx.%s",
                     cxn->desc, of_object_id_str[i]+skip);
        name[sizeof(name)-1] = '\0';
        char *description = "Message sent from the switch";
        debug_counter_register(&cxn->tx_counters[i], aim_strdup(name), description);
    }

    cxn->has_debug_counters = true;
}

static void
cxn_unregister_debug_counters(connection_t *cxn)
{
    int i;

    if (!cxn->has_debug_counters) {
        return;
    }

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

    cxn->has_debug_counters = false;
}


/*------------------------------------------------------------
 * Connection read/write event management
 *------------------------------------------------------------*/

/* FIXME can we get rid of the TLS_HANDSHAKING state? */

#define IS_TLS_HANDSHAKING(cxn) \
    ((cxn->ssl) && SSL_renegotiate_pending(cxn->ssl))

#define FORCE_SET_READ_READY(cxn) set_read_event__(cxn, true)
#define FORCE_CLEAR_READ_READY(cxn) clear_read_event__(cxn, true)
#define FORCE_SET_WRITE_READY(cxn) set_write_event__(cxn, true)
#define FORCE_CLEAR_WRITE_READY(cxn) clear_write_event__(cxn, true)

#define SET_READ_READY(cxn) set_read_event__(cxn, false)
#define CLEAR_READ_READY(cxn) clear_read_event__(cxn, false)
#define SET_WRITE_READY(cxn) set_write_event__(cxn, false)
#define CLEAR_WRITE_READY(cxn) clear_write_event__(cxn, false)

static void
set_read_event__(connection_t *cxn, bool force)
{
    if (force || !IS_TLS_HANDSHAKING(cxn)) {
        int rv = ind_soc_data_in_resume(cxn->sd);
        INDIGO_ASSERT(rv == INDIGO_ERROR_NONE,
                      "Cannot set read event on socket %d", cxn->sd);
    }
}

static void
clear_read_event__(connection_t *cxn, bool force)
{
    if (force || !IS_TLS_HANDSHAKING(cxn)) {
        int rv = ind_soc_data_in_pause(cxn->sd);
        INDIGO_ASSERT(rv == INDIGO_ERROR_NONE,
                      "Cannot clear read event on socket %d", cxn->sd);
    }
}

static void
set_write_event__(connection_t *cxn, bool force)
{
    if (force || !IS_TLS_HANDSHAKING(cxn)) {
        int rv = ind_soc_data_out_ready(cxn->sd);
        INDIGO_ASSERT(rv == INDIGO_ERROR_NONE,
                      "Cannot set write event on socket %d", cxn->sd);
    }
}

static void
clear_write_event__(connection_t *cxn, bool force)
{
    if (force || !IS_TLS_HANDSHAKING(cxn)) {
        int rv = ind_soc_data_out_clear(cxn->sd);
        INDIGO_ASSERT(rv == INDIGO_ERROR_NONE,
                      "Cannot clear write event on socket %d", cxn->sd);
    }
}


/*------------------------------------------------------------
 * Connection instance read buffer management
 *------------------------------------------------------------*/

/**
 * Send a hello message to the given connection
 */
int
cxn_send_hello(connection_t *cxn)
{
    of_hello_t *hello;
    int rv = INDIGO_ERROR_NONE;
    indigo_cxn_config_params_t *config_params;

    LOG_TRACE(cxn, "Sending hello");
    
    config_params = get_connection_config(cxn);

    if ((hello = of_hello_new(config_params->version)) == NULL) {
        AIM_DIE("Could not allocate hello object");
    }

    of_hello_xid_set(hello, ind_cxn_xid_get());

    indigo_cxn_send_controller_message(cxn->cxn_id, hello);

    cxn->hello_time = INDIGO_CURRENT_TIME;

    return rv;
}


/**
 * Check if a hello message has been received
 * @param cxn The connection instance
 * @param obj Pointer to an OF object
 *
 * Before doing anything else, a connection must exchange a hello
 * to negotiate the version to use for the interaction.
 */
static inline int
check_for_hello(connection_t *cxn, of_object_t *obj)
{
    int rv = INDIGO_ERROR_NONE;

    if (obj->object_id != OF_HELLO) {
        LOG_WARN(cxn, "Expecting HELLO but received %s message",
                 of_object_id_str[obj->object_id]);
        rv = INDIGO_ERROR_PROTOCOL;
    } else {
        LOG_VERBOSE(cxn, "Received HELLO message (version %d)",
                    obj->version);
        
        indigo_cxn_config_params_t *config_params = get_connection_config(cxn);
        
        cxn->status.negotiated_version = aim_imin(config_params->version,
                                                  obj->version);

        LOG_VERBOSE(cxn, "Negotiated version %d",
                    cxn->status.negotiated_version);
    }

    return rv;
}


bool
ind_cxn_is_handshake_complete(const connection_t *cxn)
{
    return (CXN_ACTIVE(cxn) &&
            (cxn->state == CXN_S_HANDSHAKE_COMPLETE))? true: false;
}


bool
ind_cxn_is_closed(const connection_t *cxn)
{
    return (CXN_ACTIVE(cxn) &&
            (cxn->state == CXN_S_CLOSED))? true: false;
}


void 
ind_cxn_notify_features_reply_sent(connection_t *cxn)
{
    if (cxn->state == CXN_S_HANDSHAKING) {
        cxn_state_set(cxn, CXN_S_HANDSHAKE_COMPLETE);
    }
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
    if (cxn->state != CXN_S_HANDSHAKE_COMPLETE) {
        LOG_VERBOSE(cxn, "Send echo request, but not connected");
        return;
    }

    if (cxn->keepalive.outstanding_echo_cnt > cxn->keepalive.threshold) {
        if (cxn->aux_id == 0) {
            LOG_WARN(cxn, "Exceeded maximum outstanding echo requests (%d) "
                     "on main connection, disconnecting",
                     cxn->keepalive.threshold);
            controller_disconnect(cxn->controller);
        } else {
            LOG_WARN(cxn, "Exceeded maximum outstanding echo requests (%d) "
                     "on auxiliary connection",
                     cxn->keepalive.threshold);
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
 * Generate a barrier reply and send it to the controller
 */
static indigo_error_t
send_barrier_reply(connection_t *cxn)
{
   of_barrier_reply_t *obj = 0;

   if ((obj = of_barrier_reply_new(cxn->status.negotiated_version)) == NULL) {
      AIM_DIE("Failed to allocate barrier reply");
   }

   of_barrier_reply_xid_set(obj, cxn->barrier.xid);
   LOG_TRACE(cxn, "Responding to barrier request xid %u", cxn->barrier.xid);

   indigo_cxn_send_controller_message(cxn->cxn_id, obj);
   return INDIGO_ERROR_NONE;
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
    ind_cxn_pause(cxn);
    cxn->barrier.pendingf = true;

    /* Notify other modules to finish their delayed processing and unblock the
     * barrier */
    ind_cxn_barrier_notify(cxn->cxn_id);

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
                LOG_VERBOSE(cxn, "Setting role to %s", role_to_string(role));
                cxn->controller->role = role;
            }

            ind_cxn_send_cxn_list();
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
        AIM_DIE("Failed to allocate of_bsn_time_reply");
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
        AIM_DIE("Failed to allocate of_bsn_controller_connections_reply");
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
        AIM_DIE("Failed to allocate of_bsn_set_aux_cxns_reply");
    }

    of_bsn_set_aux_cxns_reply_xid_set(reply, xid);
    
    /* get the number of aux connections to set up */
    of_bsn_set_aux_cxns_request_num_aux_get(request, &num_aux);    
 
    LOG_VERBOSE(cxn, "Request for %d aux cxns", num_aux);

    status = ind_cxn_set_aux_cxns(cxn, num_aux);  
    of_bsn_set_aux_cxns_reply_num_aux_set(reply, num_aux);
    of_bsn_set_aux_cxns_reply_status_set(reply, status);
    indigo_cxn_send_controller_message(cxn->cxn_id, reply);
}


/**
 * Handle a BSN log message
 */

static void
bsn_log_handle(connection_t *cxn, of_object_t *_obj)
{
    of_bsn_log_t *obj = _obj;
    uint8_t loglevel;
    of_octets_t data;

    of_bsn_log_loglevel_get(obj, &loglevel);
    of_bsn_log_data_get(obj, &data);

    /*
     * No easy way to pass the log flag and get all the features of
     * the logging macros.
     */
    switch (loglevel) {

#define level(name) \
    case OFP_BSN_LOGLEVEL_ ## name: \
        LOG_ ## name(cxn, "from controller: %.*s", data.bytes, data.data); \
        break;

    level(MSG)
    level(ERROR)
    level(WARN)
    level(INFO)
    level(VERBOSE)
    level(TRACE)

#undef level

    default:
        LOG_WARN(cxn, "Invalid loglevel in bsn_log message");
        indigo_cxn_send_error_reply(
            cxn->cxn_id, obj,
            OF_ERROR_TYPE_BAD_REQUEST,
            OF_REQUEST_FAILED_EPERM);
        return;
    }
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
    AIM_ASSERT(cxn->outstanding_op_cnt > 0);
    cxn->outstanding_op_cnt -= 1;

    LOG_TRACE(cxn, "Op count %d", cxn->outstanding_op_cnt);

    /* Check if outstanding ops is now 0 and clean up if needed */
    if (cxn->outstanding_op_cnt == 0) {
        if (cxn->state == CXN_S_CLOSING) {
            LOG_VERBOSE(cxn, "Op count 0, disconnecting");
            cxn_state_set(cxn, CXN_S_CLOSED);
        } else if (cxn->barrier.pendingf) {
            LOG_TRACE(cxn, "Op count 0, sending barrier reply");
            send_barrier_reply(cxn);
            cxn->barrier.pendingf = false;
            ind_cxn_resume(cxn);
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

    case OF_BSN_LOG:
        bsn_log_handle(cxn, obj);
        return;

    case OF_BUNDLE_CTRL_MSG:
        ind_cxn_bundle_ctrl_handle(cxn, obj);
        return;

    case OF_BUNDLE_ADD_MSG:
        ind_cxn_bundle_add_handle(cxn, obj);
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

    indigo_core_receive_controller_message(cxn->cxn_id, obj);
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

    if (cxn->ssl) {
        ERR_clear_error();
        bytes_in = SSL_read(cxn->ssl, inbuf_start, cxn->bytes_needed);
        if (bytes_in <= 0) {
            if (bytes_in == 0) {
                LOG_VERBOSE(cxn, "Connection closed");
                return INDIGO_ERROR_CONNECTION;
            } else {
                switch(SSL_get_error(cxn->ssl, bytes_in)) {
                case SSL_ERROR_WANT_READ:
                    /* do nothing */
                    LOG_VERBOSE(cxn, "SSL_read returns WANT_READ");
                    return INDIGO_ERROR_PENDING;
                    break;
                case SSL_ERROR_WANT_WRITE:
                    LOG_VERBOSE(cxn, "SSL_read returns WANT_WRITE");
                    return INDIGO_ERROR_PENDING;
                    break;
                case SSL_ERROR_SYSCALL:
                    LOG_ERROR(cxn, "TLS syscall: %s", strerror(errno));
                    return INDIGO_ERROR_CONNECTION;
                    break;
                default:
                    {
                        char buf[IND_SSL_ERR_LEN];
                        ERR_error_string(ERR_get_error(), buf);
                        LOG_ERROR(cxn, "TLS error: %s", buf);
                    }
                    return INDIGO_ERROR_CONNECTION;
                }
            }
        }
    } else {
        bytes_in = read(cxn->sd, inbuf_start, cxn->bytes_needed);

        /*
         * Reading 0 bytes indicates connection has closed, although we allow
         * for EAGAIN and EWOULDBLOCK
         */
        if (bytes_in <= 0) {
            if (bytes_in == 0) { /* Socket is closed */
                if (!CXN_LOCAL(cxn)) {
                    LOG_VERBOSE(cxn, "Connection closed by remote host");
                }
                return INDIGO_ERROR_CONNECTION;
            }

            if (errno == EAGAIN || errno == EWOULDBLOCK) {
                LOG_TRACE(cxn, "Error reading from socket: %s", strerror(errno));
                return 0;
            }

            LOG_ERROR(cxn, "Error reading from socket: %s", strerror(errno));
            ++ind_cxn_read_errors;
            return INDIGO_ERROR_CONNECTION;
        }
    }

    cxn->status.bytes_in += bytes_in;
#if defined(DUMP_OBJECTS_AND_DATA)
    cxn_data_hexdump(&cxn->read_buffer[cxn->read_bytes], bytes_in);
#endif

    AIM_ASSERT((int)bytes_in <= cxn->bytes_needed);
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
    if (cxn->pause_refcount > 0) {
        return INDIGO_ERROR_PENDING;
    }

    /* No bytes needed; must be stuck. */
    if (cxn->bytes_needed == 0) {
        LOG_TRACE(cxn, "Processing appears to be blocked");
        return INDIGO_ERROR_PENDING;
    }

    if (READING_HEADER(cxn)) {
        AIM_ASSERT(cxn->bytes_needed + cxn->read_bytes == 
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
            ++ind_cxn_read_errors;
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
        AIM_DIE("Could not allocate error message");
    }

    of_bad_request_error_msg_xid_set(error_msg, xid);
    of_bad_request_error_msg_code_set(error_msg, code);

    if (of_bad_request_error_msg_data_set(error_msg, &payload) < 0) {
        LOG_INTERNAL(cxn, "Failed to append original request to error message");
    }

    indigo_cxn_send_controller_message(cxn->cxn_id, error_msg);
}


#define OFVERSION_IS_SET(cxn) ((cxn)->status.negotiated_version > 0)

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
    of_object_storage_t obj_storage;

    /* Clear read buffer for next read */
    len = cxn->read_bytes;
    cxn->read_bytes = 0;
    cxn->bytes_needed = OF_MESSAGE_HEADER_LENGTH;

    obj = of_object_new_from_message_preallocated(&obj_storage, cxn->read_buffer, len);
    if (obj == NULL) {
        LOG_WARN(cxn, "Failed to parse OpenFlow message version=%u type=%u length=%u xid=%u",
                 of_message_version_get(cxn->read_buffer),
                 of_message_type_get(cxn->read_buffer),
                 of_message_length_get(cxn->read_buffer),
                 of_message_xid_get(cxn->read_buffer));
        send_parse_error_message(cxn, cxn->read_buffer, len);
        return;
    }

    ind_cxn_process_message(cxn, obj);
}

/* exposed for process_message and message bundling code to call */
void
ind_cxn_process_message(connection_t *cxn, of_object_t *obj)
{
    if(cxn->trace_pvs) {
        aim_printf(cxn->trace_pvs, "** of_msg_trace: received from cxn %s\n",
                   cxn->desc);
        of_object_dump((loci_writer_f)aim_printf, cxn->trace_pvs, obj);
        aim_printf(cxn->trace_pvs, "**\n\n");
    }

    if (ind_cxn_is_handshake_complete(cxn)) {
        /* We have a message from the controller.  Reset keepalive timeout */
        cxn->keepalive.outstanding_echo_cnt = 0;

#if OFCONNECTIONMANAGER_CONFIG_ECHO_OPTIMIZATION == 1
        if (cxn->keepalive.period_ms > 0) {
            indigo_error_t rv;
            rv = ind_soc_timer_event_register_with_priority(
                periodic_keepalive, (void *)cxn,
                cxn->keepalive.period_ms, IND_CXN_EVENT_PRIORITY);
            AIM_ASSERT(rv == INDIGO_ERROR_NONE,
                       "Failed to register periodic keepalive for %s",
                       cxn->desc);
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

    if (!OFVERSION_IS_SET(cxn)) {
        /* Get version from initial hello message.
         * If we never receive a hello, we never process any other message,
         * and the connection will time out */
        check_for_hello(cxn, obj);
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

static indigo_error_t
cxn_process_read_buffer(connection_t *cxn)
{
    indigo_error_t rv = INDIGO_ERROR_NONE;
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


/*------------------------------------------------------------
 * Connection instance write buffer management
 *------------------------------------------------------------*/

/* helper function */
static int
ssl_writev(connection_t *cxn, const struct iovec *iov, int iovcnt)
{
    int i;
    int total = 0;
    int written;

    for (i = 0; i < iovcnt; i++) {
        const struct iovec *curr = iov + i;
        ERR_clear_error();
        written = SSL_write(cxn->ssl, curr->iov_base, curr->iov_len);
        if (written == 0) {
            if (SSL_get_error(cxn->ssl, 0) == SSL_ERROR_ZERO_RETURN) {
                LOG_VERBOSE(cxn, "Connection closed");
                return -1;
            } else { 
                return total;
            }
        } else if (written < 0) {
            switch(SSL_get_error(cxn->ssl, written)) {
            case SSL_ERROR_WANT_READ:
                /* do nothing */
                LOG_VERBOSE(cxn, "SSL_write returns WANT_READ");
                return total;
                break;
            case SSL_ERROR_WANT_WRITE:
                /* do nothing */
                LOG_VERBOSE(cxn, "SSL_write returns WANT_WRITE");
                return total;
                break;
            case SSL_ERROR_SYSCALL:
                LOG_ERROR(cxn, "TLS syscall: %s", strerror(errno));
                return -1;
                break;
            default:
                {
                    char buf[IND_SSL_ERR_LEN];
                    ERR_error_string(ERR_get_error(), buf);
                    LOG_ERROR(cxn, "TLS error: %s", buf);
                }
                return -1;
            }
        } else if (written != curr->iov_len) {
            /* partial write */
            return total + written;
        } else {
            total += written;
        }
    }

    return total;
}


/**
 * Process messages waiting to be sent to a connection socket
 */

static indigo_error_t
cxn_process_write_buffer(connection_t *cxn)
{
    /*
     * Iterate over enqueued packets until none are left or socket buffer is
     * full or we should yield; do-while delays the should_yield check until
     * we've iterated at least once.
     */
    do {
        int written, left;
        int total = 0; /* number of bytes we expect to write */
        int num_iovecs = 0;
        struct iovec iovecs[MAX_WRITE_MSGS];
        int i, queue_iter;

        bigring_iter_start(cxn->write_queue, &queue_iter);

        /*
         * Iterate over write queue adding buffers to iovecs until we have
         * collected the maximum number of msgs or none are left.
         */
        while (num_iovecs < MAX_WRITE_MSGS) {
            void *data = bigring_iter_next(cxn->write_queue, &queue_iter);
            if (data == NULL) {
                break;
            }
            struct iovec *iov = &iovecs[num_iovecs];
            iov->iov_base = data;
            iov->iov_len = of_message_length_get(iov->iov_base);
            if (num_iovecs == 0) {
                /* First buffer may be partially written */
                iov->iov_base += cxn->write_queue_head_offset;
                iov->iov_len -= cxn->write_queue_head_offset;
            }
            num_iovecs++;
            total += iov->iov_len;
        }

        if (cxn->ssl) {
            written = ssl_writev(cxn, iovecs, num_iovecs);
            if (written < 0) {
                return INDIGO_ERROR_UNKNOWN;
            }
        } else {
            written = writev(cxn->sd, iovecs, num_iovecs);
            if (written < 0) {
                if (errno == EAGAIN) {
                    /* Socket buffer full and nothing was written */
                    written = 0;
                } else {
                    /* Error writing to connection socket */
                    LOG_ERROR(cxn, "Error writing to socket: %s",
                              strerror(errno));
                    return INDIGO_ERROR_UNKNOWN;
                }
            }
        }

        /*
        * Iterate over cxn->output_list and iovecs together, freeing completely
        * sent messages.
        */
        left = written;
        for (i = 0; i < num_iovecs; i++) {
            struct iovec *iov = &iovecs[i];
            int to_write, bytes_out;

            /* Number of bytes we attempted to send in this message */
            to_write = iov->iov_len;

            /* Number of bytes we actually sent in this message */
            bytes_out = aim_imin(left, to_write);
            cxn->bytes_enqueued -= bytes_out;

            if (bytes_out == to_write) { /* Completed this message */
                aim_free(bigring_shift(cxn->write_queue));
                cxn->pkts_enqueued--;
                cxn->status.messages_out++;
                cxn->write_queue_head_offset = 0;
            } else {
                /* Partial write */
                AIM_ASSERT(bytes_out < to_write);
                cxn->write_queue_head_offset += bytes_out;
                break;
            }

            left -= bytes_out;
        }

        if (written != total) {
            /* Short write, the socket buffer is full */
            break;
        }
    } while (cxn->pkts_enqueued > 0 && !ind_soc_should_yield());

    if (cxn->pkts_enqueued == 0) {
        LOG_TRACE(cxn, "No more data to write");
        AIM_ASSERT(cxn->bytes_enqueued == 0);
        AIM_ASSERT(bigring_count(cxn->write_queue) == 0);
        CLEAR_WRITE_READY(cxn);
    }

    return INDIGO_ERROR_NONE;
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

indigo_error_t
ind_cxn_instance_enqueue(connection_t *cxn, uint8_t *data, int len)
{
    int msg_len;

    LOG_TRACE(cxn, "Enqueuing %d bytes", len);
    LOG_TRACE(cxn, "Cur len %d bytes, %d pkts",
              cxn->bytes_enqueued, cxn->pkts_enqueued);

    /* See notes about WRITE_BUFFER_SIZE in cxn_instance.h */
    if (len > CXN_WRITE_BYTES_AVAIL(cxn)) {
        LOG_ERROR(cxn, "Dropping message due to full write buffer (%d bytes in %d messages enqueued)",
                  cxn->bytes_enqueued, cxn->pkts_enqueued);
        return INDIGO_ERROR_RESOURCE;
    }

    /* Verify that the length is what is reported by the OF msg */
    msg_len = of_message_length_get(data);
    AIM_ASSERT(len == msg_len, "Inconsistent message length");
    if (len != msg_len) {
        LOG_INTERNAL(cxn, "Error in message length: %d != %d, discarding",
                     len, msg_len);
        return INDIGO_ERROR_UNKNOWN;
    }

    if (bigring_count(cxn->write_queue) < bigring_size(cxn->write_queue)) {
        bigring_push(cxn->write_queue, data);
    } else {
        LOG_ERROR(cxn, "Dropping message due to full ringbuffer (%d bytes in %d messages enqueued)",
                  cxn->bytes_enqueued, cxn->pkts_enqueued);
        return INDIGO_ERROR_RESOURCE;
    }

    cxn->bytes_enqueued += len;
    cxn->pkts_enqueued += 1;

    /* Indicate data is ready to the socket manager */
    AIM_ASSERT(cxn->bytes_enqueued > 0);
    AIM_ASSERT(cxn->pkts_enqueued > 0);
    SET_WRITE_READY(cxn);

    return INDIGO_ERROR_NONE;
}


/*----------*/

/**
 * @brief Callback to process "socket ready"
 *
 * @param socket_id The socket that is ready
 * @param cookie Pointer to the connection instance
 * @param read_ready Was read-ready signaled by select
 * @param write_ready Was write-ready signaled by select
 * @param error_seen Was an error signaled by select
 */
static void
cxn_socket_ready(
    int socket_id,
    void *cookie,
    int read_ready,
    int write_ready,
    int error_seen)
{
    connection_t *cxn;
    indigo_error_t rv;

    cxn = (connection_t *)cookie;
    AIM_LOG_TRACE("Soc %d ready, cxn %p, controller %p. rd %d. wr %d. er %d",
                  socket_id, cookie, cxn->controller,
                  read_ready, write_ready, error_seen);

    if (!CXN_ID_VALID(cxn->cxn_id)) {
        AIM_LOG_INTERNAL("Socket ready with bad cxn %p", cxn);
        return;
    }

    if (!CXN_ACTIVE(cxn)) {
        AIM_LOG_INTERNAL("Socket ready on non active cxn %p", cxn);
        return;
    }

    AIM_ASSERT(cxn->controller != NULL);
    AIM_ASSERT(cxn->sd == socket_id);

    if (error_seen) {
        int socket_error = 0;
        socklen_t len = sizeof(socket_error);
        getsockopt(cxn->sd, SOL_SOCKET, SO_ERROR, &socket_error, &len);
        if (cxn->aux_id == 0 && socket_error == ECONNREFUSED) {
            LOG_VERBOSE(cxn, "Socket error: Connection refused");
            cxn->controller->fail_count++;
        } else {
            LOG_ERROR(cxn, "%s", strerror(socket_error));
        }
        controller_disconnect(cxn->controller);
        return;
    }

    /* handle TLS handshake */
    if (cxn->state == CXN_S_TLS_HANDSHAKING) {
        switch (cxn_try_to_tls_handshake(cxn)) {
        case INDIGO_ERROR_NONE:
            /* transition to handshaking */
            cxn_state_set(cxn, CXN_S_HANDSHAKING);
            break;
        case INDIGO_ERROR_PENDING:
            /* do nothing, wait for next iteration of cxn_socket_ready */
            break;
        default:
            /* something bad happened, close connection */
            /* transition to closing */
            cxn_state_set(cxn, CXN_S_CLOSING);
        }
        return;
    }

    /* handle rehandshaking if necessary */
    if (IS_TLS_HANDSHAKING(cxn)) {
        LOG_VERBOSE(cxn, "handle TLS handshaking");
        switch (cxn_try_to_tls_handshake(cxn)) {
        case INDIGO_ERROR_NONE:
            /* done; wait for next iteration */
            break;
        case INDIGO_ERROR_PENDING:
            /* do nothing, wait for next iteration of cxn_socket_ready */
            break;
        default:
            /* something bad happened, close connection */
            /* transition to closing */
            cxn_state_set(cxn, CXN_S_CLOSING);
        }
        return;
    }

    if (read_ready) {
        if ((rv = cxn_process_read_buffer(cxn)) < 0) {
            LOG_VERBOSE(cxn, "Error processing read buffer, resetting");
            controller_disconnect(cxn->controller);
            return;
        }
    }

    if (write_ready) {
        if (cxn->state == CXN_S_INIT && !CXN_LISTEN(cxn)) {
            rv = cxn_try_to_connect(cxn);
            if (rv == INDIGO_ERROR_NONE) {
                /* success, move to next state */
                if (cxn->ssl) {
                    cxn_state_set(cxn, CXN_S_TLS_HANDSHAKING);
                } else {
                    cxn_state_set(cxn, CXN_S_HANDSHAKING);
                    FORCE_SET_READ_READY(cxn);
                }
            } else if (rv == INDIGO_ERROR_PENDING) {
                AIM_DIE("In-flight connection cannot be write ready");
            } else {
                LOG_INTERNAL(cxn, "Error trying to connect, resetting");
                controller_disconnect(cxn->controller);
            }
        } else {
            if ((rv = cxn_process_write_buffer(cxn)) < 0) {
                LOG_ERROR(cxn, "Error processing write buffer, resetting");
                controller_disconnect(cxn->controller);
                return;
            }
        }
    }
}


/*------------------------------------------------------------
 * Connection instance state machine
 *------------------------------------------------------------*/

/**
 * State machine for (non-listen, non-local) Connection Instance
 *
 * init: initial state --------------------------- timeout ---+
 *         |                                                  |
 *         | trigger: connect() completes                     |
 *         | action: move to TLS decision box                 |
 *         |                                                  |
 *  +---- TLS? ---+                                           |
 *  |             |                                           |
 *  | no TLS:     | yes TLS: SSL_do_handshake()               |
 *  | send        v                                           |
 *  | hello    TLS_handshaking ------------------- timeout ---+
 *  |             |                                           |
 *  |             | trigger: TLS_do_handshake() completes     |
 *  |             | action: send hello                        |
 *  v             v                                           |
 * handshaking: transport layer established ------ timeout ---+
 *    |                                                       |
 *    | trigger: hello received, features_request received    |
 *    | action: send features_reply                           |
 *    v                                                       |
 * handshake_complete: controller connection is usable        |
 *    |    periodically generate echo requests                |
 *    |                                                       |
 *    | openflow error or transport layer closed              |
 *    v                                                       |
 * closing: clean up                                   <------+
 *    |    allow outstanding_op_cnt to be decremented
 *    |
 *    | outstanding_op_cnt == 0 or timeout
 *    v
 * closed: terminal state, connection is dead
 *
 * ASSUMPTIONS:
 *
 * The closing state is the only way that a connection instance may
 * transition to closed.
 *
 * Transitions in the state manager are edge triggered by events
 * or timeouts.
 *
 * Reconnection attempts while in disconnected are prompted by the
 * connection manager as per its programming.
 *
 * Echo requests are managed by a separate timer event while in
 * handshake_complete.
 */

/**
 * Once a connection is accepted on the main listener connection,
 * that connection follows the state machine with some differences:
 * 
 * - Local connections immediately transition through handshaking state
 *   to handshake complete.
 * - There is no keepalive.
 */

const char*
cxn_state_names[] = {
#define cxn_s_desc(_val, _id, _name, _timeout) _name,
    CXN_S_DESCS
#undef cxn_s_desc
};
#define CXN_STATE_NAME(cxn) cxn_state_names[cxn->state]

const int
cxn_state_timeouts[] = {
#define cxn_s_desc(_val, _id, _name, _timeout) _timeout,
    CXN_S_DESCS
#undef cxn_s_desc
};


/**
 * Force transition to closing state
 */
static void
cxn_state_timeout(void *cookie)
{
    connection_t *cxn = (connection_t *) cookie;

    LOG_WARN(cxn, "Timeout in state %s", CXN_STATE_NAME(cxn));

    switch (cxn->state) {
    case CXN_S_INIT:  /* fall-through */
    case CXN_S_TLS_HANDSHAKING:  /* fall-through */
    case CXN_S_HANDSHAKING:  /* fall-through */
    case CXN_S_CLOSING:
        ind_cxn_stop(cxn);
        break;
    default:
        AIM_DIE("Timeout in state %s should not occur",
                CXN_STATE_NAME(cxn));
    }
}


/**
 * @brief Handle a connection state change event
 * @param cxn The connection being updated
 * @param new_state The state to transition to
 *
 * The new state and old state should be different.
 *
 * Anything that affects the connection instance state should go through
 * this routine, especially connection disconnect events.
 */
static void
cxn_state_set(connection_t *cxn, cxn_state_t new_state)
{
    cxn_state_t old_state = cxn->state;

    if (old_state == new_state) {
        LOG_VERBOSE(cxn, "Non-state change in %s", 
                    cxn_state_names[new_state]);
        return;
    }

    LOG_VERBOSE(cxn, "%s->%s (id "CXN_ID_FMT")",
                cxn_state_names[old_state],
                cxn_state_names[new_state],
                CXN_ID_FMT_ARGS(cxn->cxn_id));

    /* Verify pre-conditions */
    switch (new_state) {
    case CXN_S_CLOSED:
        /* If moving to disconnected, must be closing (or disconnected) */
        if ((old_state != CXN_S_CLOSING)) {
            LOG_INTERNAL(cxn, "Error: moved to closed state from %s",
                         cxn_state_names[old_state]);
        }
        break;
    default:
        break;
    }

    /* Exit conditions for old state */
    switch (old_state) {
    case CXN_S_INIT:  /* fall-through */
    case CXN_S_TLS_HANDSHAKING:  /* fall-through */
    case CXN_S_CLOSING:
        ind_soc_timer_event_unregister(cxn_state_timeout, (void *)cxn);
        break;
    case CXN_S_HANDSHAKING:
        /* local connections do not have a timeout */
        if (!CXN_LOCAL(cxn)) {
            ind_soc_timer_event_unregister(cxn_state_timeout, (void *)cxn);
        }
        break;
    case CXN_S_HANDSHAKE_COMPLETE:
        cxn->status.is_connected = false;
        if (!CXN_LOCAL(cxn) && cxn->aux_id == 0) {
            AIM_SYSLOG_INFO("Disconnected from controller <ip-address>:<port>",
                            "The switch disconnected from the specified controller.",
                            "Disconnected from controller %s",
                            cxn->desc);
            ind_cxn_syslog_active_controllers();
        }
        break;
    default:
        break;
    }

    /* Change state of connection */
    cxn->state = new_state;

    /* External notification of state change before processing */
    if ((old_state == CXN_S_HANDSHAKING &&
         new_state == CXN_S_HANDSHAKE_COMPLETE) ||
        (old_state == CXN_S_HANDSHAKE_COMPLETE &&
         new_state == CXN_S_CLOSING)) {
        ind_cxn_status_change(cxn);
    }

    /* Post-processing of state transition. */
    switch (new_state) {
    case CXN_S_INIT:
        /* this should never happen */
        AIM_DIE("Error: transitioned to INIT");
        break;

    case CXN_S_TLS_HANDSHAKING:
        /* trigger TLS handshake */
        switch (cxn_try_to_tls_handshake(cxn)) {
        case INDIGO_ERROR_NONE:
            /* Recursive call; transition to handshaking */
            cxn_state_set(cxn, CXN_S_HANDSHAKING);
            break;
        case INDIGO_ERROR_PENDING:
            /* do nothing, wait for next iteration of cxn_socket_ready */
            break;
        default:
            /* something bad happened, close connection */
            /* Recursive call; transition to closing */
            cxn_state_set(cxn, CXN_S_CLOSING);
        }
        break;

    case CXN_S_HANDSHAKING:
        cxn->controller->fail_count = 0;
        cxn_register_debug_counters(cxn);
        ind_cxn_bundle_init(cxn);
        cxn_send_hello(cxn);
        if (CXN_LOCAL(cxn)) {
            /* Recursive call; transition to connected */
            cxn_state_set(cxn, CXN_S_HANDSHAKE_COMPLETE);
        } else {
            indigo_error_t rv;
            rv = ind_soc_timer_event_register_with_priority(
                cxn_state_timeout, (void *)cxn,
                cxn_state_timeouts[new_state], IND_CXN_EVENT_PRIORITY);
            AIM_ASSERT(rv == INDIGO_ERROR_NONE,
                       "Failed to register HANDSHAKING state timeout for %s",
                       cxn->desc);
        }
        break;

    case CXN_S_HANDSHAKE_COMPLETE:
        if (cxn->keepalive.period_ms > 0) {
            indigo_error_t rv;
            /* Set up periodic echo request */
            rv = ind_soc_timer_event_register_with_priority(
                periodic_keepalive, (void *)cxn,
                cxn->keepalive.period_ms, IND_CXN_EVENT_PRIORITY);
            AIM_ASSERT(rv == INDIGO_ERROR_NONE,
                       "Failed to register periodic keepalive for %s",
                       cxn->desc);
        }

        cxn->status.is_connected = true;
        if (!CXN_LOCAL(cxn) && cxn->aux_id == 0) {
            AIM_SYSLOG_INFO("Connected to controller <ip-address>:<port>",
                            "The switch successfully connected to the specified controller.",
                            "Connected to controller %s",
                            cxn->desc);
            ind_cxn_syslog_active_controllers();
        }
        break;

    case CXN_S_CLOSING:
        if (cxn->keepalive.period_ms > 0) {
            ind_soc_timer_event_unregister(periodic_keepalive, (void *)cxn);
        }
        {
            indigo_error_t rv;
            rv = ind_soc_timer_event_register_with_priority(
                cxn_state_timeout, (void *)cxn,
                cxn_state_timeouts[new_state], IND_CXN_EVENT_PRIORITY);
            AIM_ASSERT(rv == INDIGO_ERROR_NONE,
                       "Failed to register CLOSING state timeout for %s",
                       cxn->desc);
        }
        cxn_unregister_debug_counters(cxn);
        ind_cxn_bundle_cleanup(cxn);

        AIM_ASSERT(cxn->sd >= 0);
        LOG_VERBOSE(cxn, "Closing socket %d", cxn->sd);
        ind_soc_socket_unregister(cxn->sd);
        close(cxn->sd);
        cxn->sd = -1;
        break;

    case CXN_S_CLOSED:
        ind_cxn_notify_closed(cxn);
        break;

    default:
        AIM_DIE("cxn %s: Unknown state %d", cxn->desc, new_state);
    }
}


/**
 * Set up a connection instance.
 * @param controller  Parent controller, with configuration params.
 * @param aux_id  Connection's auxiliary id.
 * @param sock_id If >=0, use this socket id.
 *   If -1, call socket() to create the associated socket.
 *
 * Typically, sd is >= 0 when this comes from an accept call.
 */
connection_t *
ind_cxn_alloc(controller_t *controller, uint8_t aux_id, int sock_id)
{
    indigo_cxn_id_t saved_cxn_id;
    int soc_flags;
    connection_t *cxn;
    struct sockaddr_storage sockaddr;
    socklen_t sockaddrlen;

    cxn = find_free_connection();
    if (cxn == NULL) {
        AIM_LOG_INTERNAL("Could not allocate connection to %s:%d",
                         controller->desc, aux_id);
        goto error;
    }

    /* Preserve cxn_id */
    saved_cxn_id = cxn->cxn_id;

    /* Initialize connection structure */
    init_single_instance(cxn, saved_cxn_id);
    cxn->write_queue = bigring_create(WRITE_QUEUE_SIZE, 
                                      bigring_aim_free_entry);
    cxn->controller = controller;
    cxn->aux_id = aux_id;
    snprintf(cxn->desc, sizeof(cxn->desc), "%s:%d", controller->desc, aux_id);
    cxn->bytes_needed = OF_MESSAGE_HEADER_LENGTH;
    cxn->sd = -1;

    if (!CXN_LOCAL(cxn)) {
        if (aux_id != 0) {
            /* Aux cxns have a different echo frequency than main cxn */
            cxn->keepalive.period_ms = IND_AUX_CXN_PERIODIC_ECHO_MS_DEFAULT;
        } else {
            cxn->keepalive.period_ms = 
                controller->config_params.periodic_echo_ms;
        }
        cxn->keepalive.threshold = controller->config_params.reset_echo_count;
    } else {
        cxn->keepalive.period_ms = 0;
        cxn->keepalive.threshold = 0;
    }

    if (sock_id == -1) {
        /* Parse the protocol params just to get the family */
        if (ind_cxn_parse_sockaddr(&controller->protocol_params,
                                   &sockaddr, &sockaddrlen) < 0) {
            goto error;
        }

        /* Attempt to create the socket */
        cxn->sd = socket(sockaddr.ss_family, SOCK_STREAM, 0);
        if (cxn->sd < 0) {
            LOG_INTERNAL(cxn, "Failed to create socket, %s", strerror(errno));
            goto error;
        }
    } else if (sock_id >= 0) {
        cxn->sd = sock_id;
    }

    if (cxn->sd >= 0) {
        soc_flags = fcntl(cxn->sd, F_GETFL, 0);
        if (soc_flags == -1 || 
            fcntl(cxn->sd, F_SETFL, soc_flags | O_NONBLOCK) == -1) {
            LOG_ERROR(cxn, "Failed to set socket non-blocking, %s",
                      strerror(errno));
            goto error;
        }

        /* Disable Nagle's algorithm */
        {
            int flag = 1;
            (void) setsockopt(cxn->sd, IPPROTO_TCP, TCP_NODELAY,
                              &flag, sizeof(int));
        }

        LOG_VERBOSE(cxn, "Created non-blocking socket %d, controller %p",
                    cxn->sd, cxn->controller);
    }

    if (cxn->controller->ssl_ctx) {
        cxn->ssl = SSL_new(cxn->controller->ssl_ctx);
        if (cxn->ssl == NULL) {
            LOG_ERROR(cxn, "Failed allocating encryption block");
            goto error;
        }
        SSL_set_mode(cxn->ssl, SSL_MODE_ENABLE_PARTIAL_WRITE);
        SSL_set_connect_state(cxn->ssl);
        if (SSL_set_fd(cxn->ssl, cxn->sd) != 1) {
            LOG_ERROR(cxn, "Failed linking encryption to socket");
            goto error;
        }
    }

    cxn->active = true;

    return cxn;

 error:
    if (cxn) {
        if (cxn->ssl) {
            ERR_clear_error();
            SSL_free(cxn->ssl);
            cxn->ssl = NULL;
        }
        if (cxn->sd >= 0) {
            close(cxn->sd);
            cxn->sd = -1;
        }
        ind_cxn_free(cxn);
    }
    return NULL;
}


/**
 * Disconnect and clean up
 * @param cxn Connection to be freed
 */
void
ind_cxn_free(connection_t *cxn)
{
    AIM_ASSERT(cxn->sd == -1);

    /* Increment the generation ID for this connection */
    cxn->cxn_id += (1 << CXN_ID_GENERATION_SHIFT);
    cxn->cxn_id &= 0x7fffffff; /* force non-negative */

    LOG_VERBOSE(cxn, "Closing connection with %d bytes in read buf",
                cxn->read_bytes);
    cxn->read_bytes = 0;

    bigring_destroy(cxn->write_queue);

    cxn->bytes_enqueued = 0;
    cxn->pkts_enqueued = 0;
    cxn->write_queue_head_offset = 0;

    if (cxn->ssl) {
        SSL_free(cxn->ssl);
        cxn->ssl = NULL;
    }

    cxn->active = false;
}


/**
 * Attempt to connect() to the specified controller.
 * Returns INDIGO_ERROR_PARAM or INDIGO_ERROR_UNKNOWN on error,
 * INDIGO_ERROR_NONE on success,
 * INDIGO_ERROR_PENDING on in-flight connection.
 * Caller's responsibility to clean up on error.
 */
static indigo_error_t
cxn_try_to_connect(connection_t *cxn)
{
    int rv;
    struct sockaddr_storage sockaddr;
    socklen_t sockaddrlen;

    if (ind_cxn_parse_sockaddr(&cxn->controller->protocol_params,
                               &sockaddr, &sockaddrlen) != INDIGO_ERROR_NONE) {
        LOG_INTERNAL(cxn, "Failed to parse address");
        return INDIGO_ERROR_PARAM;
    }

    rv = connect(cxn->sd, (struct sockaddr *) &sockaddr, sockaddrlen);
    if ((rv == 0) ||
        ((rv == -1) && errno == EISCONN)) {
        return INDIGO_ERROR_NONE;
    } else if ((rv == -1) &&
               (errno == EAGAIN || errno == EALREADY || 
                errno == EINPROGRESS)) {
        /* mark socket for writing so that second connect() call can be made,
         * because nonblocking socket may return EINPROGRESS */
        FORCE_SET_WRITE_READY(cxn);
        return INDIGO_ERROR_PENDING;
    } else {
        LOG_INTERNAL(cxn, "connect: %s", strerror(errno));
        if (cxn->aux_id == 0) {
            cxn->controller->fail_count++;
        }
        return INDIGO_ERROR_UNKNOWN;
    }
}


/**
 * Attempt to start and/or complete TLS handshake to the specified controller.
 * Returns INDIGO_ERROR_PARAM or INDIGO_ERROR_UNKNOWN on error,
 * INDIGO_ERROR_NONE on success,
 * INDIGO_ERROR_PENDING on in-flight connection.
 * Caller's responsibility to clean up on error.
 */
static indigo_error_t
cxn_try_to_tls_handshake(connection_t *cxn)
{
    int rv;

    ERR_clear_error();
    rv = SSL_do_handshake(cxn->ssl);
    if (rv == 1) {
        LOG_INFO(cxn, "TLS handshake completed, cipher %s",
                 SSL_get_cipher(cxn->ssl));
        LOG_VERBOSE(cxn, "restoring socket read/write state");
        /* restore desired read/write event state */
        if (cxn->pause_refcount) {
            CLEAR_READ_READY(cxn);
        } else {
            SET_READ_READY(cxn);
        }
        if (cxn->pkts_enqueued) {
            SET_WRITE_READY(cxn);
        } else {
            CLEAR_WRITE_READY(cxn);
        }
        return INDIGO_ERROR_NONE;
    } else {
        int err = SSL_get_error(cxn->ssl, rv);
        if (err == SSL_ERROR_WANT_READ) {
            LOG_VERBOSE(cxn, "SSL_do_handshake returns WANT_READ");
            FORCE_SET_READ_READY(cxn);
            FORCE_CLEAR_WRITE_READY(cxn);
            return INDIGO_ERROR_PENDING;
        } else if (err == SSL_ERROR_WANT_WRITE) {
            LOG_VERBOSE(cxn, "SSL_do_handshake returns WANT_WRITE");
            FORCE_CLEAR_READ_READY(cxn);
            FORCE_SET_WRITE_READY(cxn);
            return INDIGO_ERROR_PENDING;
        } else if (err == SSL_ERROR_ZERO_RETURN) {
            LOG_ERROR(cxn, "TLS handshake shutdown controlled");
            return INDIGO_ERROR_UNKNOWN;
        } else {
            LOG_ERROR(cxn, "TLS handshake fatal error %d", rv);
            if (err == SSL_ERROR_SYSCALL) {
                LOG_ERROR(cxn, "TLS syscall: %s", strerror(errno));
            } else {
                char buf[IND_SSL_ERR_LEN];
                ERR_error_string(ERR_get_error(), buf);
                LOG_ERROR(cxn, "TLS other: %s", buf);
            }
            return INDIGO_ERROR_UNKNOWN;
        }
    }    
}


/**
 * Start the specified connection.
 */
void
ind_cxn_start(connection_t *cxn)
{
    indigo_error_t rv;

    LOG_TRACE(cxn, "Starting cxn %p", cxn);

    AIM_ASSERT(cxn->state == CXN_S_INIT);

    /* register with socket manager to catch socket-writeable event,
     * so that connect() can successfully complete;
     * see comment in cxn_try_to_connect():EINPROGRESS handling */
    rv = ind_soc_socket_register_with_priority(cxn->sd, cxn_socket_ready,
                                               cxn, IND_CXN_EVENT_PRIORITY);
    AIM_ASSERT(rv == INDIGO_ERROR_NONE,
               "Unable to register socket for %s", cxn->desc);

    /* block reads until connect() has completed */
    FORCE_CLEAR_READ_READY(cxn);

    rv = cxn_try_to_connect(cxn);
    LOG_TRACE(cxn, "cxn_try_to_connect returns %d", rv);
    if (rv == INDIGO_ERROR_NONE) {
        /* success, move to next state;
         * connections started from the listener will also return 0 */
        if (cxn->ssl) {
            cxn_state_set(cxn, CXN_S_TLS_HANDSHAKING);
        } else {
            cxn_state_set(cxn, CXN_S_HANDSHAKING);
            FORCE_SET_READ_READY(cxn);
        }
    } else if (rv == INDIGO_ERROR_PENDING) {
        /* connect is in-flight, register timeout */
        rv = ind_soc_timer_event_register_with_priority(
            cxn_state_timeout, cxn, cxn_state_timeouts[CXN_S_INIT],
            IND_CXN_EVENT_PRIORITY);
        AIM_ASSERT(rv == INDIGO_ERROR_NONE,
                   "Failed to register INIT state timeout for %s",
                   cxn->desc);
    } else {
        LOG_INTERNAL(cxn, "Error trying to connect when starting, closing");
        ind_cxn_stop(cxn);
    }
}


/**
 * Force a connection to start the disconnection process
 */
void 
ind_cxn_stop(connection_t *cxn)
{
    LOG_VERBOSE(cxn, "Stopping");

    if (cxn->state != CXN_S_CLOSED) {
        cxn_state_set(cxn, CXN_S_CLOSING);
        if (cxn->outstanding_op_cnt == 0) {
            cxn_state_set(cxn, CXN_S_CLOSED);
        }
    } else {
        LOG_VERBOSE(cxn, "Already stopped");
    }
}


void
ind_cxn_pause(connection_t *cxn)
{
    if (cxn->pause_refcount++ == 0) {
        /* FIXME were there cases where we could not clear?! */
        CLEAR_READ_READY(cxn);
    }
}

void
ind_cxn_resume(connection_t *cxn)
{
    AIM_ASSERT(cxn->pause_refcount > 0);
    if (--cxn->pause_refcount == 0) {
        SET_READ_READY(cxn);
    }
}


/*------------------------------------------------------------
 * Miscellaneous routines
 *------------------------------------------------------------*/

/*
 * for the given connection, log received openflow messages
 * to the specified pvs.
 * if the cxn_id is -1, log for all currently active connections.
 */
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

        if (ind_cxn_is_handshake_complete(cxn)) {
            of_bsn_controller_connection_state_set(&entry, 1);
        } else {
            of_bsn_controller_connection_state_set(&entry, 0);
        }

        of_bsn_controller_connection_auxiliary_id_set(&entry, cxn->aux_id);

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

        switch(protocol_params->header.protocol) {
        case INDIGO_CXN_PROTO_TCP_OVER_IPV4:
            snprintf(uri, sizeof(uri), "tcp://%s:%d",
                     protocol_params->tcp_over_ipv4.controller_ip,
                     protocol_params->tcp_over_ipv4.controller_port);
            break;
        case INDIGO_CXN_PROTO_TLS_OVER_IPV4:
            snprintf(uri, sizeof(uri), "tls://%s:%d",
                     protocol_params->tcp_over_ipv4.controller_ip,
                     protocol_params->tcp_over_ipv4.controller_port);
            break;
        case INDIGO_CXN_PROTO_TCP_OVER_IPV6:
            snprintf(uri, sizeof(uri), "tcp://[%s]:%d",
                     protocol_params->tcp_over_ipv6.controller_ip,
                     protocol_params->tcp_over_ipv6.controller_port);
            break;
        case INDIGO_CXN_PROTO_TLS_OVER_IPV6:
            snprintf(uri, sizeof(uri), "tls://[%s]:%d",
                     protocol_params->tcp_over_ipv6.controller_ip,
                     protocol_params->tcp_over_ipv6.controller_port);
            break;
        case INDIGO_CXN_PROTO_UNIX:
            snprintf(uri, sizeof(uri), "unix://%s",
                     protocol_params->unx.unix_path);
            break;
        default:
            AIM_DIE("unhandled protocol type %d\n",
                    protocol_params->header.protocol);
        }

        of_bsn_controller_connection_uri_set(&entry, uri);
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
    if (ind_cxn_read_errors) {
        aim_printf(pvs, "    Socket read errors: %u\n", ind_cxn_read_errors);
    }

    FOREACH_ACTIVE_CXN(cxn_idx, cxn) {
        cxn_count++;
        aim_printf(pvs, "Stats for%s%s connection %s:\n",
                   CXN_LOCAL(cxn) ? " local" : "",
                   CXN_LISTEN(cxn) ? " listening" : "",
                   cxn->desc);
        aim_printf(pvs, "    Id: %d\n", cxn->cxn_id);
        aim_printf(pvs, "    Auxiliary Id: %d\n", cxn->aux_id);
        aim_printf(pvs, "    Controller Id: %d\n", 
                   cxn->controller->controller_id);
        aim_printf(pvs, "    State: %s\n", ind_cxn_is_handshake_complete(cxn)?
                   "Connected" : "Not connected");
        aim_printf(pvs, "    Keepalive timeout: %d ms\n", 
                   cxn->keepalive.period_ms);
        aim_printf(pvs, "    Threshold: %d\n", cxn->keepalive.threshold);
        aim_printf(pvs, "    Outstanding Echo Count: %d\n", 
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


/*------------------------------------------------------------
 * Utility functions for unit testing only
 *------------------------------------------------------------*/

int unit_test_connection_count_get(void)
{
    int idx;
    connection_t *cxn;

    int count = 0;

    FOREACH_ACTIVE_CXN(idx, cxn) {
        count++;
    }

    return count;
}
