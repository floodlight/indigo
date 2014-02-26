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

/******************************************************************************
 *
 *  /utest/main.c
 *
 *  OFConnectionManager Unit Testing
 *
 *****************************************************************************/


#include <OFConnectionManager/ofconnectionmanager_config.h>
#include <OFConnectionManager/ofconnectionmanager.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <indigo/of_connection_manager.h>
#include <indigo/of_state_manager.h>
#include <indigo/assert.h>
#include <indigo/memory.h>

#include <SocketManager/socketmanager.h>

#include "ofconnectionmanager_log.h"

#define OK(op)  INDIGO_ASSERT((op) == INDIGO_ERROR_NONE)

void
indigo_core_connection_count_notify(int new_count)
{
    printf("Connection count is %d\n", new_count);
}


static ind_cxn_config_t cm_config;

/* Status change handler */
static int status_change_called;

static void
cxn_status_change(indigo_cxn_id_t cxn_id,
		  indigo_cxn_protocol_params_t *cxn_proto_params,
                  indigo_cxn_state_t state,
                  void *cookie)
{
    printf("Status change called\n");
    status_change_called = 1;
}


#define CONTROLLER_IP "127.0.0.1"
#define CONTROLLER_PORT 12345

/* Return connection ID */
static indigo_cxn_protocol_params_t protocol_params;
static indigo_cxn_config_params_t config_params;

static int
setup_cxn(void)
{
    indigo_cxn_id_t id;

    config_params.version = OF_VERSION_1_0;

    protocol_params.tcp_over_ipv4.protocol = INDIGO_CXN_PROTO_TCP_OVER_IPV4;
    sprintf(protocol_params.tcp_over_ipv4.controller_ip, "%s", CONTROLLER_IP);
    protocol_params.tcp_over_ipv4.controller_port = CONTROLLER_PORT;

    OK(indigo_cxn_connection_add(&protocol_params, &config_params, &id));

    return id;
}

static int got_cxn_msg;

static void
cxn_msg_rx(indigo_cxn_id_t cxn_id, of_object_t *obj)
{
    printf("Got msg from %d: type %d\n", cxn_id, obj->object_id);

    /* Just respond to echo request */
    if (obj->object_id == OF_ECHO_REQUEST) {
        of_echo_request_t *echo;
        of_echo_reply_t *reply;
        of_octets_t data;
        uint32_t xid;

        echo = (of_echo_request_t *)obj;
        of_echo_request_xid_get(echo, &xid);
        printf("Respond to echo with xid 0x%x\n", xid);
        if ((reply = of_echo_reply_new(echo->version)) == NULL) {
            printf("Could not allocate echo response obj\n");
            goto done;
        }

        of_echo_request_data_get(echo, &data);
        if (data.bytes) {
            OK(of_echo_reply_data_set(reply, &data));
        }

        of_echo_reply_xid_set(reply, xid);

        indigo_cxn_send_controller_message(cxn_id, reply);
    }

 done:
    got_cxn_msg = 1;
}

/*
 * Implement Forwarding function
 */

void
indigo_core_receive_controller_message(indigo_cxn_id_t cxn_id,
                                       of_object_t *obj)
{
    cxn_msg_rx(cxn_id, obj);
}

int main(int argc, char* argv[])
{
    int cxn_id;
    int idx;
    ind_soc_config_t config; /* Currently ignored */

    INDIGO_MEM_CLEAR(&config, sizeof(config));
    OK(ind_soc_init(&config));

    OK(ind_cxn_init(&cm_config));

    OK(indigo_cxn_status_change_register(cxn_status_change, NULL));

    OK(ind_cxn_enable_set(1));
    INDIGO_ASSERT((cxn_id = setup_cxn()) >= 0);

    for (idx = 1; idx < 5; idx++) {
        printf("run %d\n", idx);
        OK(ind_soc_select_and_run(2000));
    }

    /* Now remove and add the cxn a few times */
    for (idx = 1; idx < 5; idx++) {
        OK(indigo_cxn_connection_remove(cxn_id));
        INDIGO_ASSERT((cxn_id = setup_cxn()) >= 0);
    }

    OK(indigo_cxn_connection_remove(cxn_id));

    OK(ind_cxn_enable_set(0));
    OK(ind_cxn_finish());

    return 0;
}
