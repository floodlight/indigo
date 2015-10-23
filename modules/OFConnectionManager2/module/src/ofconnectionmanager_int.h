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
 * @brief Private module definitions for OF connection manager
 */


#ifndef __OFCONNECTIONMANAGER_INT_H__
#define __OFCONNECTIONMANAGER_INT_H__


#include <sys/types.h>
#include <sys/socket.h>
#include "ofconnectionmanager_log.h"
#include "cxn_instance.h"


/* Very verbose for debugging */
/* #define OF_CXN_DUMP_ALL_OBJECTS 1 */

#if defined(OF_CXN_DUMP_ALL_OBJECTS) /* Global enable for logging OF objects */
#define LOG_OBJECT(obj) of_object_log(obj)
#else
#define LOG_OBJECT(obj)
#endif

/**
 * Default value for the aux connections echo period in milliseconds
 */
#define IND_AUX_CXN_PERIODIC_ECHO_MS_DEFAULT 15000

/* SSL error buffer length */
#define IND_SSL_ERR_LEN 128

/**
 * Module error counters
 */
extern uint32_t ind_cxn_read_errors;

/**
 * Role request generation ID
 */
extern uint64_t ind_cxn_generation_id;

/*
 * Priority for sockets and timers registered with SocketManager.
 */
#define IND_CXN_EVENT_PRIORITY IND_SOC_HIGH_PRIORITY

uint32_t ind_cxn_xid_get(void);

void ind_controller_change_master(indigo_cxn_id_t master_id);

int ind_cxn_set_aux_cxns(connection_t *main_cxn, uint32_t num_aux);

void controller_disconnect(controller_t *controller);

void ind_cxn_notify_closed(connection_t *cxn);

void ind_cxn_syslog_active_controllers(void);

void ind_cxn_send_cxn_list(void);

void ind_cxn_status_change(connection_t *cxn);

indigo_error_t
ind_cxn_verify_tls(char *cipher_list,
                   char *ca_cert,
                   char *switch_cert,
                   char *switch_priv_key);

void ind_cxn_stats_show(aim_pvs_t* pvs, int details);

void ind_cxn_tls_config_show(aim_pvs_t *pvs);


/**
 * @brief Update the configuration of the connection manager
 * @param config Pointer to the implementation specific configuration
 * structure
 */
extern const struct ind_cfg_ops ind_cxn_cfg_ops;

/* Run all barrier notify callbacks */
void ind_cxn_barrier_notify(indigo_cxn_id_t cxn_id);

/* Parse the protocol params into a struct sockaddr */
indigo_error_t
ind_cxn_parse_sockaddr(const indigo_cxn_protocol_params_t *protocol_params,
                       struct sockaddr_storage *sockaddr,
                       socklen_t *sockaddrlen);

/* Bundle interfaces */
void ind_cxn_bundle_init(connection_t *cxn);
void ind_cxn_bundle_cleanup(connection_t *cxn);
void ind_cxn_bundle_ctrl_handle(connection_t *cxn, of_object_t *_obj);
void ind_cxn_bundle_add_handle(connection_t *cxn, of_object_t *_obj);

/*
 * populate destbuf with useful connection identifying info.
 * destbuf has maximum length destbuflen.
 */
int
ind_cxn_proto_ip_string(indigo_cxn_protocol_params_t *params,
                        char *destbuf, int destbuflen);

/*
 * helper functions for unit testing only; 
 * do not call from outside of connectionmanager
 */
cxn_state_t unit_test_cxn_state_get(indigo_controller_id_t controller_id,
                                    uint8_t aux_id);

int unit_test_controller_count_get(void);
int unit_test_connection_count_get(void);

int unit_test_cxn_events_get(indigo_controller_id_t controller_id,
                             uint8_t aux_id);

#endif /* __OFCONNECTIONMANAGER_INT_H__ */
