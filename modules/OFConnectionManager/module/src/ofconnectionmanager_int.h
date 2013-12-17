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
 * @brief Private module definitions for OF connection manager
 */


#ifndef __OFCONNECTIONMANAGER_INT_H__
#define __OFCONNECTIONMANAGER_INT_H__

#include <OFConnectionManager/ofconnectionmanager_config.h>
#include "ofconnectionmanager_log.h"
#include "cxn_instance.h"
#include <cjson/cJSON.h>

/* Very verbose for debugging */
/* #define OF_CXN_DUMP_ALL_OBJECTS 1 */

#if defined(OF_CXN_DUMP_ALL_OBJECTS) /* Global enable for logging OF objects */
#define LOG_OBJECT(obj) of_object_log(obj)
#else
#define LOG_OBJECT(obj)
#endif

/**
 * Try an operation and return the error code on failure.
 */
#define _TRY(op) do {                                                   \
        int _rv;                                                        \
        if ((_rv = (op)) < 0) {                                         \
            AIM_LOG_ERROR("ERROR %d at %s:%d\n", _rv, __FILE__, __LINE__); \
            return _rv;                                                 \
        }                                                               \
    } while (0)

/**
 * Does the connection manager have a local connection?
 */
extern int have_local_connection;

/**
 * How many remote connections does the connection manager have?
 */
extern int remote_connection_count;

/**
 * Role request generation ID
 */
extern uint64_t ind_cxn_generation_id;


/* conversion functions from cookie with generation id to connection and vice versa */
void *cxn_to_cookie(connection_t *cxn);
connection_t* cookie_to_cxn(void* cookie);


/*
 * Priority for sockets and timers registered with SocketManager.
 */
#define IND_CXN_EVENT_PRIORITY 10

extern void indigo_cxn_socket_ready_callback(int socket_id,
                                             void *cookie,
                                             int read_ready,
                                             int write_ready,
                                             int error_seen);
extern void ind_cxn_local_listen_socket_ready(int socket_id,
                                              void *cookie,
                                              int read_ready,
                                              int write_ready,
                                              int error_seen);

extern int ind_cxn_xid_get(void);

extern indigo_error_t ind_cxn_send_controller_message(indigo_cxn_id_t cxn_id,
                                                      of_object_t *obj);


extern void cxn_message_track_setup(connection_t *cxn, of_object_t *obj);

void ind_cxn_change_master(indigo_cxn_id_t master_id);

void ind_cxn_populate_connection_list(of_list_bsn_controller_connection_t *list);

/**
 * The OF message callback vector from state manager
 */

#define OF_MSG_CALLBACK(cxn, obj)                           \
    indigo_core_receive_controller_message((cxn)->cxn_id, obj)

/**
 * A connection instance calls this when it has data ready for output
 * @param sd The socket descriptor that will be written to
 */
#define CXN_WRITE_READY(sd) ind_soc_data_out_ready(sd)
#define CXN_WRITE_CLEAR(sd) ind_soc_data_out_clear(sd)

/****************************************************************
 * Status change callback bookkeeping
 ****************************************************************/

extern void ind_cxn_status_change(connection_t *cxn);


/****************************************************************
 * State machine timeout handler
 ****************************************************************/

extern void ind_cxn_state_timeout(void *cookie);


/****************************************************************
 * Logging/debug helpers
 ****************************************************************/

extern void ind_cxn_stats_show(aim_pvs_t* pvs, int details);

/**
 * @brief Update the configuration of the connection manager
 * @param config Pointer to the implementation specific configuration
 * structure
 */

extern const struct ind_cfg_ops ind_cxn_cfg_ops;

#include <OFConnectionManager/ofconnectionmanager.h>

#endif /* __OFCONNECTIONMANAGER_INT_H__ */
