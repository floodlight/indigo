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

#include <loci/loci.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <fcntl.h>
#include <errno.h>

#include "ofconnectionmanager_int.h"


#define OK(op)  INDIGO_ASSERT((op) == INDIGO_ERROR_NONE)


static ind_cxn_config_t cm_config;

/* indexed by cxn_id and aux_id */
static int cxn_is_connected[MAX_CONTROLLERS][MAX_AUX_CONNECTIONS];

static void
cxn_status_change(indigo_controller_id_t controller_id,
                  uint8_t aux_id,
		  indigo_cxn_protocol_params_t *cxn_proto_params,
                  bool is_connected,
                  void *cookie)
{
    char desc[64];

    if (cxn_proto_params->header.protocol == INDIGO_CXN_PROTO_TCP_OVER_IPV4) {
        snprintf(desc, sizeof(desc), "%s:%d:%d",
                 cxn_proto_params->tcp_over_ipv4.controller_ip,
                 cxn_proto_params->tcp_over_ipv4.controller_port,
                 aux_id);
    } else {
        snprintf(desc, sizeof(desc), "%s:%d:%d",
                 cxn_proto_params->tcp_over_ipv6.controller_ip,
                 cxn_proto_params->tcp_over_ipv6.controller_port,
                 aux_id);
    }

    printf("Status for %s (id %d, aux %d), now %s\n", 
           desc, controller_id, aux_id,
           is_connected? "connected": "disconnected");
    INDIGO_ASSERT(controller_id < MAX_CONTROLLERS);
    INDIGO_ASSERT(aux_id < MAX_AUX_CONNECTIONS);
    cxn_is_connected[controller_id][aux_id] = is_connected;
}


#define CONTROLLER_IP "127.0.0.1"
#define CONTROLLER_IPV6 "::1"
/* FIXME need to run this before unit tests */
/* sudo ifconfig lo add fe80::b00b:4cff:fe2f:1fe3/64 */
#define CONTROLLER_IPV6_LINKLOCAL "fe80::b00b:4cff:fe2f:1fe3%lo"
#define CONTROLLER_LISTEN_PORT 25267
#define CONTROLLER_PORT1 12345
#define CONTROLLER_PORT2 12444


static int
setup_cxn(char *controller_ip, int controller_port)
{
    indigo_cxn_protocol_params_t protocol_params;
    indigo_cxn_config_params_t config_params;
    indigo_controller_id_t id;

    memset(&config_params, 0, sizeof(config_params));
    config_params.version = OF_VERSION_1_3;

    protocol_params.tcp_over_ipv4.protocol = INDIGO_CXN_PROTO_TCP_OVER_IPV4;
    sprintf(protocol_params.tcp_over_ipv4.controller_ip, "%s", controller_ip);
    protocol_params.tcp_over_ipv4.controller_port = controller_port;

    OK(indigo_controller_add(&protocol_params, &config_params, &id));

    ind_cxn_stats_show(&aim_pvs_stdout, 1);

    return id;
}

static int
setup_cxn_v6(char *controller_ip, int controller_port)
{
    indigo_cxn_protocol_params_t protocol_params;
    indigo_cxn_config_params_t config_params;
    indigo_controller_id_t id;

    memset(&config_params, 0, sizeof(config_params));
    config_params.version = OF_VERSION_1_3;

    protocol_params.tcp_over_ipv6.protocol = INDIGO_CXN_PROTO_TCP_OVER_IPV6;
    sprintf(protocol_params.tcp_over_ipv6.controller_ip, "%s",
            controller_ip);
    protocol_params.tcp_over_ipv6.controller_port = controller_port;

    OK(indigo_controller_add(&protocol_params, &config_params, &id));

    ind_cxn_stats_show(&aim_pvs_stdout, 1);

    return id;
}


static void
cxn_msg_rx(indigo_cxn_id_t cxn_id, of_object_t *obj)
{
    printf("Got msg from cxn_id %08x: type %s(%d)\n", 
           cxn_id, of_class_name(obj), obj->object_id);

    /* respond to echo request */
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

    /* respond to features request */
    if (obj->object_id == OF_FEATURES_REQUEST) {
        of_features_request_t *req;
        of_features_reply_t *reply;
        uint32_t xid;

        req = (of_features_request_t *)obj;
        of_features_request_xid_get(req, &xid);
        printf("Respond to features_request with xid 0x%x\n", xid);
        if ((reply = of_features_reply_new(req->version)) == NULL) {
            printf("Could not allocate features_reply obj\n");
            goto done;
        }

        if (obj->version >= OF_VERSION_1_3) {
            uint8_t auxiliary_id;
            indigo_cxn_get_auxiliary_id(cxn_id, &auxiliary_id);
            of_features_reply_auxiliary_id_set(reply, auxiliary_id);
            printf("Populating aux_id %d\n", auxiliary_id);
        }

        /* FIXME populate anything else? */

        of_features_reply_xid_set(reply, xid);

        indigo_cxn_send_controller_message(cxn_id, reply);
    }

 done:
    return;
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


of_version_t of_version = OF_VERSION_1_3;

static uint32_t
xid_get(void)
{
    static uint32_t xid = 0;
    xid++;
    return xid;
}


static void
of_sendmsg(int sd, of_object_t *obj)
{
    uint8_t *data;
    of_object_xid_set(obj, xid_get());
    of_object_wire_buffer_steal(obj, &data);
    write(sd, data, of_message_length_get(data));
    aim_free(data);
}


static void
of_send_hello(int sd)
{
    of_sendmsg(sd, of_hello_new(of_version));
}

static void
of_send_features_request(int sd)
{
    of_sendmsg(sd, of_features_request_new(of_version));
}

static void
of_send_aux_cxn_req(int sd, int num_aux)
{
    of_bsn_set_aux_cxns_request_t* obj = 
        of_bsn_set_aux_cxns_request_new(of_version);
    of_bsn_set_aux_cxns_request_num_aux_set(obj, num_aux);
    of_sendmsg(sd, obj);
}


static of_object_t *
of_recvmsg(int sd, uint8_t buf[], int buflen,
           of_object_storage_t *storage)
{
    const int header_bytes = 8;
    int ret = 0;
    uint16_t msglen;
    int i = 0;

    do {
        ret = read(sd, buf, header_bytes);
        i++;
    } while (i < 256 && ret == -1 && errno == EAGAIN);
    INDIGO_ASSERT(ret != -1, "read error: %s", strerror(errno));
    INDIGO_ASSERT(ret == header_bytes, "read %d bytes, expected %d", 
                  ret, header_bytes);
    msglen = ntohs(*((uint16_t*)(buf+2)));
    INDIGO_ASSERT(msglen <= buflen, "message len %d exceeds buffer len %d",
                  msglen, buflen);
    ret = read(sd, buf+header_bytes, msglen-header_bytes);
    INDIGO_ASSERT(ret == msglen-header_bytes, 
                  "body read %d bytes, expected %d",
                  ret, msglen-header_bytes);

    return of_object_new_from_message_preallocated(storage, buf, msglen);
}


/* returns listening socket */
static int
setup_server(int domain, char *ip, uint16_t port)
{
    int lsd;
    const int listen_backlog = 5;
    struct addrinfo hints;
    struct addrinfo *result;
    int flag;
    char port_str[16];

    lsd = socket(domain, SOCK_STREAM, 0);
    INDIGO_ASSERT(lsd != -1, "error creating listening socket: %s",
                  strerror(errno));
    flag = fcntl(lsd, F_GETFL, 0);
    INDIGO_ASSERT(flag != -1, "could not read socket flags");
    INDIGO_ASSERT(fcntl(lsd, F_SETFL, flag | O_NONBLOCK) != -1,
                  "could not set socket nonblocking");
    flag = 1;
    setsockopt(lsd, SOL_SOCKET, SO_REUSEADDR, &flag, sizeof(int));

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;    /* For wildcard IP address */
    hints.ai_protocol = 0;          /* Any protocol */
    hints.ai_canonname = NULL;
    hints.ai_addr = NULL;
    hints.ai_next = NULL;

    snprintf(port_str, sizeof(port_str), "%u", port);
    INDIGO_ASSERT(getaddrinfo(ip, port_str, &hints, &result) == 0);
    INDIGO_ASSERT(bind(lsd, result->ai_addr, result->ai_addrlen) == 0);

    INDIGO_ASSERT(listen(lsd, listen_backlog) == 0);

    return lsd;
}


/* returns the socket accepted from the specified listening socket */
static int
server_accept(int lsd)
{
    int sd;
    struct sockaddr fromaddr;
    socklen_t fromaddrlen;
    struct sockaddr_in addr4;
    struct sockaddr_in6 addr6;
    int flag;
    int i = 0;

    fromaddrlen = sizeof(fromaddr);
    do {
        sd = accept(lsd, (struct sockaddr*) &fromaddr, &fromaddrlen);
        i++;
    } while (i < 256 && sd == -1 && errno == EAGAIN);
    if (sd == -1) {
        printf("accept failed: %s\n", strerror(errno));
    }

    /* FIXME refactor */
    if (fromaddr.sa_family == AF_INET) {
        memcpy(&addr4, &fromaddr, sizeof(addr4));
        printf("accepted from port %d\n", addr4.sin_port);
    } else {
        memcpy(&addr6, &fromaddr, sizeof(addr6));
        printf("accepted from port %d\n", addr6.sin6_port);
    }

    INDIGO_ASSERT(sd >= 0);
    flag = fcntl(sd, F_GETFL, 0);
    INDIGO_ASSERT(flag != -1);
    INDIGO_ASSERT(fcntl(sd, F_SETFL, flag | O_NONBLOCK) != -1);

    return sd;
}


static int 
advance_to_handshake_complete(int controller_id, int aux_id, int lsd)
{
    int sd;
    of_object_t *obj;
    of_object_storage_t storage;
    uint8_t buf[256];  /* may need to be increaed */

    sd = server_accept(lsd);
    OK(ind_soc_select_and_run(1));
    INDIGO_ASSERT(!cxn_is_connected[controller_id][aux_id]);
    INDIGO_ASSERT(unit_test_cxn_state_get(controller_id, aux_id) ==
                  CXN_S_HANDSHAKING);

    of_send_hello(sd);
    OK(ind_soc_select_and_run(10));
    /* check for hello */
    obj = of_recvmsg(sd, buf, sizeof(buf), &storage);
    INDIGO_ASSERT(obj->object_id == OF_HELLO, "did not receive OF_HELLO");
    of_send_features_request(sd);
    OK(ind_soc_select_and_run(10));
    INDIGO_ASSERT(cxn_is_connected[controller_id][aux_id], 
                  "controller_id %d, aux_id %d should be connected after features_req sent",
                  controller_id, aux_id);
    /* check for features reply */
    obj = of_recvmsg(sd, buf, sizeof(buf), &storage);
    INDIGO_ASSERT(obj->object_id == OF_FEATURES_REPLY,
                  "did not receive OF_FEATURES_REPLY");

    OK(ind_soc_select_and_run(1));
    INDIGO_ASSERT(cxn_is_connected[controller_id][aux_id], 
                  "controller_id %d, aux_id %d should be connected after features_reply received",
                  controller_id, aux_id);
    INDIGO_ASSERT(unit_test_cxn_state_get(controller_id, aux_id) ==
                  CXN_S_HANDSHAKE_COMPLETE);

    return sd;
}


static void
indigo_setup(void)
{
    ind_soc_config_t config; /* Currently ignored */

    INDIGO_MEM_CLEAR(&config, sizeof(config));
    OK(ind_soc_init(&config));
    OK(ind_cxn_init(&cm_config));

    OK(indigo_cxn_status_change_register(cxn_status_change, NULL));

    OK(ind_soc_enable_set(1));
    OK(ind_cxn_enable_set(1));
}


static void
indigo_teardown(void)
{
    INDIGO_ASSERT(unit_test_controller_count_get() == 0,
                  "actual controller count %d, expected 0", 
                  unit_test_controller_count_get());
    INDIGO_ASSERT(unit_test_connection_count_get() == 0,
                  "actual connection count %d, expected 0", 
                  unit_test_connection_count_get());

    INDIGO_ASSERT(unit_test_soc_socket_count_get() == 0,
                  "actual soc event count %d, expected 0", 
                  unit_test_soc_socket_count_get());
    INDIGO_ASSERT(unit_test_soc_timer_event_count_get() == 0,
                  "actual soc timer count %d, expected 0", 
                  unit_test_soc_timer_event_count_get());

    OK(ind_cxn_enable_set(0));
    OK(ind_soc_enable_set(0));
    OK(ind_cxn_finish());
    OK(ind_soc_finish());
}


static void
test_normal(int domain, char *addr)
{
    indigo_controller_id_t id;
    int lsd;
    int sd;

    printf("***Start %s, domain %s, addr %s\n", __FUNCTION__, 
           domain == AF_INET? "ipv4": "ipv6", addr);

    /* set up listening socket */
    lsd = setup_server(domain, addr, CONTROLLER_PORT1);

    indigo_setup();

    if (domain == AF_INET) {
        id = setup_cxn(addr, CONTROLLER_PORT1);
    } else {
        id = setup_cxn_v6(addr, CONTROLLER_PORT1);
    }

    INDIGO_ASSERT(id >= 0);
    INDIGO_ASSERT(unit_test_cxn_state_get(id, 0) == CXN_S_INIT);

    OK(ind_soc_select_and_run(1));
    INDIGO_ASSERT(!cxn_is_connected[id][0]);
    INDIGO_ASSERT(unit_test_cxn_state_get(id, 0) == CXN_S_HANDSHAKING);

    sd = advance_to_handshake_complete(id, 0, lsd);
    INDIGO_ASSERT(unit_test_connection_count_get() == 1);

    close(sd);
    OK(ind_soc_select_and_run(1));
    INDIGO_ASSERT(!cxn_is_connected[id][0]);

    /* check that the client reconnected */
    OK(ind_soc_select_and_run(10));
    sd = server_accept(lsd);
    INDIGO_ASSERT(!cxn_is_connected[id][0]);
    close(sd);

    ind_cxn_stats_show(&aim_pvs_stdout, 1);

    OK(indigo_controller_remove(id));
    OK(ind_soc_select_and_run(1));

    indigo_teardown();

    close(lsd);

    printf("***Stop %s, domain %s, addr %s\n", __FUNCTION__, 
           domain == AF_INET? "ipv4": "ipv6", addr);
}


static void
test_no_hello(void)
{
    indigo_controller_id_t id;
    int lsd;
    int sd;
    of_object_t *obj;
    of_object_storage_t storage;
    uint8_t buf[256];  /* may need to be increaed */

    printf("***Start %s\n", __FUNCTION__);

    /* set up listening socket */
    lsd = setup_server(AF_INET, CONTROLLER_IP, CONTROLLER_PORT1);

    indigo_setup();

    INDIGO_ASSERT((id = setup_cxn(CONTROLLER_IP, CONTROLLER_PORT1)) >= 0);
    INDIGO_ASSERT(unit_test_cxn_state_get(id, 0) == CXN_S_INIT);

    OK(ind_soc_select_and_run(1));
    INDIGO_ASSERT(!cxn_is_connected[id][0]);
    INDIGO_ASSERT(unit_test_cxn_state_get(id, 0) == CXN_S_HANDSHAKING);

    sd = server_accept(lsd);
    OK(ind_soc_select_and_run(1));
    INDIGO_ASSERT(!cxn_is_connected[id][0]);
    INDIGO_ASSERT(unit_test_cxn_state_get(id, 0) == CXN_S_HANDSHAKING);

    /* check for hello, but don't send hello */
    obj = of_recvmsg(sd, buf, sizeof(buf), &storage);
    INDIGO_ASSERT(obj->object_id == OF_HELLO);

    /* wait at least 5 seconds for timeout */
    OK(ind_soc_select_and_run(4*1000));
    INDIGO_ASSERT(!cxn_is_connected[id][0]);
    OK(ind_soc_select_and_run(1000+10));
    close(sd);

    /* check that the client reconnected */
    OK(ind_soc_select_and_run(10));
    sd = server_accept(lsd);
    INDIGO_ASSERT(!cxn_is_connected[id][0]);
    close(sd);

    ind_cxn_stats_show(&aim_pvs_stdout, 1);

    OK(indigo_controller_remove(id));
    OK(ind_soc_select_and_run(1));

    indigo_teardown();

    close(lsd);

    printf("***Stop %s\n", __FUNCTION__);
}


static void
test_no_features_request(void)
{
    indigo_controller_id_t id;
    int lsd;
    int sd;
    of_object_t *obj;
    of_object_storage_t storage;
    uint8_t buf[256];  /* may need to be increaed */

    printf("***Start %s\n", __FUNCTION__);

    /* set up listening socket */
    lsd = setup_server(AF_INET, CONTROLLER_IP, CONTROLLER_PORT1);

    indigo_setup();

    INDIGO_ASSERT((id = setup_cxn(CONTROLLER_IP, CONTROLLER_PORT1)) >= 0);
    INDIGO_ASSERT(unit_test_cxn_state_get(id, 0) == CXN_S_INIT);

    OK(ind_soc_select_and_run(1));
    INDIGO_ASSERT(!cxn_is_connected[id][0]);
    INDIGO_ASSERT(unit_test_cxn_state_get(id, 0) == CXN_S_HANDSHAKING);

    sd = server_accept(lsd);
    OK(ind_soc_select_and_run(1));
    INDIGO_ASSERT(!cxn_is_connected[id][0]);
    INDIGO_ASSERT(unit_test_cxn_state_get(id, 0) == CXN_S_HANDSHAKING);

    of_send_hello(sd);
    OK(ind_soc_select_and_run(10));
    /* check for hello */
    obj = of_recvmsg(sd, buf, sizeof(buf), &storage);
    INDIGO_ASSERT(obj->object_id == OF_HELLO);

    /* wait at least 5 seconds for timeout */
    OK(ind_soc_select_and_run(4*1000));
    INDIGO_ASSERT(!cxn_is_connected[id][0]);
    OK(ind_soc_select_and_run(1000+10));
    close(sd);

    /* check that the client reconnected */
    OK(ind_soc_select_and_run(10));
    sd = server_accept(lsd);
    INDIGO_ASSERT(!cxn_is_connected[id][0]);
    close(sd);

    ind_cxn_stats_show(&aim_pvs_stdout, 1);

    OK(indigo_controller_remove(id));
    OK(ind_soc_select_and_run(1));

    indigo_teardown();

    close(lsd);

    printf("***Stop %s\n", __FUNCTION__);
}


static void
test_aux3(int delta)
{
    indigo_controller_id_t id;
    int lsd;
    int sd;
    of_object_t *obj;
    of_object_storage_t storage;
    uint8_t buf[2048];  /* may need to be increaed */
    const int num_aux = 3;
    uint32_t status;
    int aux_sd[num_aux];
    int i;

    printf("***Start %s with delta %d\n", __FUNCTION__, delta);

    /* set up listening socket */
    lsd = setup_server(AF_INET, CONTROLLER_IP, CONTROLLER_PORT1);

    indigo_setup();

    INDIGO_ASSERT((id = setup_cxn(CONTROLLER_IP, CONTROLLER_PORT1)) >= 0);
    INDIGO_ASSERT(unit_test_cxn_state_get(id, 0) == CXN_S_INIT);

    OK(ind_soc_select_and_run(1));
    INDIGO_ASSERT(!cxn_is_connected[id][0]);
    INDIGO_ASSERT(unit_test_cxn_state_get(id, 0) == CXN_S_HANDSHAKING);

    printf("Advance main connection to handshake complete\n");
    sd = advance_to_handshake_complete(id, 0, lsd);
    INDIGO_ASSERT(sd > 0);

    printf("Start aux connections\n");
    of_send_aux_cxn_req(sd, num_aux);
    OK(ind_soc_select_and_run(10));

    /* check for aux cxns reply */
    i = 0;
    do {
        obj = of_recvmsg(sd, buf, sizeof(buf), &storage);
        i++;
    } while (i < 256 && obj->object_id != OF_BSN_SET_AUX_CXNS_REPLY);
    INDIGO_ASSERT(obj->object_id == OF_BSN_SET_AUX_CXNS_REPLY,
                  "did not receive OF_BSN_SET_AUX_CXNS_REPLY");
    of_bsn_set_aux_cxns_reply_status_get(obj, &status);
    INDIGO_ASSERT(status == 0, "aux connections reply status should be zero");

    /* note we are off by 1 on aux_id */
    for (i = 0; i < num_aux; i++) {
        aux_sd[i] = advance_to_handshake_complete(id, i+1, lsd);
        INDIGO_ASSERT(aux_sd[i] > 0,
                      "aux_sd %d is not set", i);
    }

    if (delta) {
        printf("Handle delta of %d\n", delta);

        of_send_aux_cxn_req(sd, num_aux + delta);
        OK(ind_soc_select_and_run(5));

        i = 0;
        do {
            obj = of_recvmsg(sd, buf, sizeof(buf), &storage);
            i++;
        } while (i < 256 && obj->object_id != OF_BSN_SET_AUX_CXNS_REPLY);
        INDIGO_ASSERT(obj->object_id == OF_BSN_SET_AUX_CXNS_REPLY,
                      "did not receive OF_BSN_SET_AUX_CXNS_REPLY");
        of_bsn_set_aux_cxns_reply_status_get(obj, &status);
        INDIGO_ASSERT(status == 0,
                      "aux connections reply status should be zero");

        if (delta > 0) {
            /* note we are off by 1 on aux_id */
            for (i = 0; i < delta; i++) {
                aux_sd[num_aux+i] = 
                    advance_to_handshake_complete(id, num_aux+i+1, lsd);
                INDIGO_ASSERT(aux_sd[num_aux+i] > 0);
            }
        } else {
            /* just give some time to clean up */
            OK(ind_soc_select_and_run(5));
        }
    }

    close(sd);
    OK(ind_soc_select_and_run(1));
    for (i = 0; i < MAX_AUX_CONNECTIONS; i++) {
        INDIGO_ASSERT(!cxn_is_connected[id][i]);
    }

    /* check that the client reconnected */
    OK(ind_soc_select_and_run(10));
    sd = server_accept(lsd);
    INDIGO_ASSERT(!cxn_is_connected[id][0]);
    close(sd);

    ind_cxn_stats_show(&aim_pvs_stdout, 1);

    OK(indigo_controller_remove(id));
    OK(ind_soc_select_and_run(1));

    indigo_teardown();

    close(lsd);

    printf("***Stop %s with delta %d\n", __FUNCTION__, delta);
}


/* returns connected socket */
static int
setup_client(char *ip, uint16_t port)
{
    int sd;
    struct addrinfo hints;
    struct addrinfo *result;
    char port_str[16];

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    snprintf(port_str, sizeof(port_str), "%u", port);
    INDIGO_ASSERT(getaddrinfo(ip, port_str, &hints, &result) == 0);

    sd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    INDIGO_ASSERT(sd > 0, "error creating client socket: %s",
                  strerror(errno));

    INDIGO_ASSERT(connect(sd, result->ai_addr, result->ai_addrlen) == 0,
                  "error connecting: %s", strerror(errno));

    return sd;
}


static int
setup_listener(char *ip, int controller_port)
{
    indigo_cxn_protocol_params_t protocol_params;
    indigo_cxn_config_params_t config_params;
    indigo_controller_id_t id;

    memset(&config_params, 0, sizeof(config_params));
    config_params.version = OF_VERSION_1_3;
    config_params.local = 1;
    config_params.listen = 1;

    protocol_params.tcp_over_ipv4.protocol = INDIGO_CXN_PROTO_TCP_OVER_IPV4;
    sprintf(protocol_params.tcp_over_ipv4.controller_ip, "%s", ip);
    protocol_params.tcp_over_ipv4.controller_port = controller_port;

    OK(indigo_controller_add(&protocol_params, &config_params, &id));

    return id;
}


static void
test_listener(void)
{
    indigo_controller_id_t id;
    int sd;
    of_object_t *obj;
    of_object_storage_t storage;
    uint8_t buf[256];  /* may need to be increaed */

    printf("***Start %s\n", __FUNCTION__);

    indigo_setup();

    /* set up connection manager listening connection */
    id = setup_listener(CONTROLLER_IP, CONTROLLER_LISTEN_PORT);
    OK(ind_soc_select_and_run(1));

    /* connect to listener */
    sd = setup_client(CONTROLLER_IP, CONTROLLER_LISTEN_PORT);
    OK(ind_soc_select_and_run(1));
    /* send hello */
    of_send_hello(sd);
    OK(ind_soc_select_and_run(1));
    /* check for hello */
    obj = of_recvmsg(sd, buf, sizeof(buf), &storage);
    INDIGO_ASSERT(obj->object_id == OF_HELLO);
    of_send_features_request(sd);
    OK(ind_soc_select_and_run(5));
    /* check for features reply */
    obj = of_recvmsg(sd, buf, sizeof(buf), &storage);
    INDIGO_ASSERT(obj->object_id == OF_FEATURES_REPLY);
    /* close */
    close(sd);

    /* verify that we can reconnect to listener */
    sd = setup_client(CONTROLLER_IP, CONTROLLER_LISTEN_PORT);
    OK(ind_soc_select_and_run(1));
    /* send hello */
    of_send_hello(sd);
    OK(ind_soc_select_and_run(1));
    /* check for hello */
    obj = of_recvmsg(sd, buf, sizeof(buf), &storage);
    INDIGO_ASSERT(obj->object_id == OF_HELLO);
    of_send_features_request(sd);
    OK(ind_soc_select_and_run(5));
    /* check for features reply */
    obj = of_recvmsg(sd, buf, sizeof(buf), &storage);
    INDIGO_ASSERT(obj->object_id == OF_FEATURES_REPLY);
    /* close */
    close(sd);

    OK(indigo_controller_remove(id));
    /* increased time to allow second controller/connection pair to be
     * removed */
    OK(ind_soc_select_and_run(5));

    indigo_teardown();

    close(sd);

    printf("***Stop %s\n", __FUNCTION__);
}


/*
 * add and remove two controllers from cxnmgr.
 * each time no controllers are configured,
 * decide to add either the first or the second, and then add the other.
 * each time two controllers are configured,
 * decide to remove either the first or the second, and then remove the other.
 */
static void
test_dual(void)
{
#define NUM_CONTROLLERS 2
    int controller_ports[NUM_CONTROLLERS] = {
        CONTROLLER_PORT1, CONTROLLER_PORT2,
    };
    indigo_controller_id_t cid[NUM_CONTROLLERS];
    int lsd[NUM_CONTROLLERS];
    int sd[NUM_CONTROLLERS];

    /* bit number corresponds to controller state: 0 removed, 1 added */
    int events[] = {
        0, 1, 3, 1, 0, 2, 3, 2, 0, 1, 3, 2, 0, 2, 3, 1, 0,
    };
    int num_events = sizeof(events)/sizeof(int);
    int mapcount[] = { 0, 1, 1, 2 };
    int idx;

    printf("***Start %s\n", __FUNCTION__);

    /* set up listening socket */
    for (idx = 0; idx < NUM_CONTROLLERS; idx++) {
        lsd[idx] = setup_server(AF_INET, CONTROLLER_IP, controller_ports[idx]);
    }

    indigo_setup();

    for (idx = 1; idx < num_events; idx++) {
        int con_idx = (events[idx-1] ^ events[idx]) - 1;
        int active_count = mapcount[events[idx]]; 

        printf("****Event %d: %d->%d, %s %d\n",
               idx, events[idx-1], events[idx],
               events[idx-1] < events[idx]? "Add": "Remove", con_idx);

        if (events[idx-1] < events[idx]) {
            /* add */
            cid[con_idx] = setup_cxn(CONTROLLER_IP, controller_ports[con_idx]);
            sd[con_idx] = advance_to_handshake_complete(cid[con_idx], 0,
                                                        lsd[con_idx]);
            INDIGO_ASSERT(unit_test_controller_count_get() == active_count,
                          "actual controller count %d, expected %d",
                          unit_test_controller_count_get(), active_count);
            INDIGO_ASSERT(unit_test_connection_count_get() == active_count,
                          "actual connection count %d, expected %d",
                          unit_test_connection_count_get(), active_count);
        } else {
            /* remove */
            OK(indigo_controller_remove(cid[con_idx]));
            OK(ind_soc_select_and_run(1));
            INDIGO_ASSERT(!cxn_is_connected[cid[con_idx]][0],
                          "controller_id %d, aux_id %d should be disconnected",
                          cid[con_idx], 0);
            INDIGO_ASSERT(unit_test_controller_count_get() == active_count,
                          "actual controller count %d, expected %d",
                          unit_test_controller_count_get(), active_count);
            INDIGO_ASSERT(unit_test_connection_count_get() == active_count,
                          "actual connection count %d, expected %d",
                          unit_test_connection_count_get(), active_count);
            close(sd[con_idx]);
        }
    }

    indigo_teardown();

    printf("***Stop %s\n", __FUNCTION__);
}


static void
test_bad_controller(void)
{
    indigo_cxn_protocol_params_t protocol_params;
    indigo_cxn_config_params_t config_params;
    indigo_controller_id_t id;

    printf("***Start %s\n", __FUNCTION__);

    indigo_setup();

    memset(&config_params, 0, sizeof(config_params));
    config_params.version = OF_VERSION_1_3;

    protocol_params.tcp_over_ipv4.protocol = INDIGO_CXN_PROTO_TCP_OVER_IPV4;
    /* use bogus ip address */
    sprintf(protocol_params.tcp_over_ipv4.controller_ip, "%s", 
            "192.168.0.255.0");
    protocol_params.tcp_over_ipv4.controller_port = CONTROLLER_PORT1;

    INDIGO_ASSERT(indigo_controller_add(&protocol_params, &config_params, &id)
                  != INDIGO_ERROR_NONE);

    indigo_teardown();

    printf("***Stop %s\n", __FUNCTION__);
}


static void
test_bad_listener(void)
{
    indigo_cxn_protocol_params_t protocol_params;
    indigo_cxn_config_params_t config_params;
    indigo_controller_id_t id;

    printf("***Start %s\n", __FUNCTION__);

    indigo_setup();

    memset(&config_params, 0, sizeof(config_params));
    config_params.version = OF_VERSION_1_3;
    config_params.local = 1;
    config_params.listen = 1;

    protocol_params.tcp_over_ipv4.protocol = INDIGO_CXN_PROTO_TCP_OVER_IPV4;
    /* use bogus ip address */
    sprintf(protocol_params.tcp_over_ipv4.controller_ip, "%s", 
            "192.168.0.255.0");
    protocol_params.tcp_over_ipv4.controller_port = CONTROLLER_LISTEN_PORT;

    INDIGO_ASSERT(indigo_controller_add(&protocol_params, &config_params, &id)
                  != INDIGO_ERROR_NONE);

    indigo_teardown();

    printf("***Stop %s\n", __FUNCTION__);
}


int main(int argc, char* argv[])
{
    test_bad_controller();
    test_bad_listener();

    test_normal(AF_INET, CONTROLLER_IP);
    test_normal(AF_INET6, CONTROLLER_IPV6);
    test_normal(AF_INET6, CONTROLLER_IPV6_LINKLOCAL);

    test_no_hello();
    test_no_features_request();

    test_aux3(0);
    test_aux3(1);
    test_aux3(-1);

    test_dual();

    test_listener();

    return 0;
}

