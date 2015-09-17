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


#include <AIM/aim.h>
#include <OFConnectionManager/ofconnectionmanager_config.h>
#include <OFConnectionManager/ofconnectionmanager.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>
#include <poll.h>

#include <indigo/of_connection_manager.h>
#include <indigo/of_state_manager.h>
#include <indigo/assert.h>
#include <indigo/memory.h>

#include <SocketManager/socketmanager.h>

#include <loci/loci.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <netdb.h>
#include <fcntl.h>
#include <errno.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

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
/* sudo ip addr add fe80::b00b:4cff:fe2f:1fe3/64 dev lo */
#define CONTROLLER_IPV6_LINKLOCAL "fe80::b00b:4cff:fe2f:1fe3%lo"
#define CONTROLLER_LISTEN_PORT 25267
#define CONTROLLER_PORT1 12345
#define CONTROLLER_PORT2 12444
#define CONTROLLER_UNIX "/tmp/controller_unix"


/* SSL configuration */
#define TEST_FS "%s/../../../../../../modules/%s/utest/%s"
/* FIXME this should be defined somewhere */
#define MOD_NAME "OFConnectionManager2"
#define CA_CERT_FILE "ca.cert"
#define CONTROLLER_CERT_FILE "controller.cert"
#define CONTROLLER_PRIV_KEY_FILE "controller.key"
#define SWITCH_CERT_FILE "switch.cert"
#define SWITCH_PRIV_KEY_FILE "switch.key"
/* concatenate with the appropriate file name */
char *basedir;


static int
setup_cxn(bool use_tls, char *controller_ip, int controller_port)
{
    indigo_cxn_protocol_params_t protocol_params;
    indigo_cxn_config_params_t config_params;
    indigo_controller_id_t id;

    memset(&config_params, 0, sizeof(config_params));
    config_params.version = OF_VERSION_1_4;

    protocol_params.tcp_over_ipv4.protocol = use_tls?
        INDIGO_CXN_PROTO_TLS_OVER_IPV4: INDIGO_CXN_PROTO_TCP_OVER_IPV4;
    sprintf(protocol_params.tcp_over_ipv4.controller_ip, "%s", controller_ip);
    protocol_params.tcp_over_ipv4.controller_port = controller_port;

    OK(indigo_controller_add(&protocol_params, &config_params, &id));

    ind_cxn_stats_show(&aim_pvs_stdout, 1);

    return id;
}

static int
setup_cxn_v6(bool use_tls, char *controller_ip, int controller_port)
{
    indigo_cxn_protocol_params_t protocol_params;
    indigo_cxn_config_params_t config_params;
    indigo_controller_id_t id;

    memset(&config_params, 0, sizeof(config_params));
    config_params.version = OF_VERSION_1_4;

    protocol_params.tcp_over_ipv6.protocol = use_tls?
        INDIGO_CXN_PROTO_TLS_OVER_IPV6: INDIGO_CXN_PROTO_TCP_OVER_IPV6;
    sprintf(protocol_params.tcp_over_ipv6.controller_ip, "%s",
            controller_ip);
    protocol_params.tcp_over_ipv6.controller_port = controller_port;

    OK(indigo_controller_add(&protocol_params, &config_params, &id));

    ind_cxn_stats_show(&aim_pvs_stdout, 1);

    return id;
}

static int
setup_cxn_unix(char *unix_path)
{
    indigo_cxn_protocol_params_t protocol_params;
    indigo_cxn_config_params_t config_params;
    indigo_controller_id_t id;

    memset(&config_params, 0, sizeof(config_params));
    config_params.version = OF_VERSION_1_4;

    protocol_params.unx.protocol = INDIGO_CXN_PROTO_UNIX;
    snprintf(protocol_params.unx.unix_path, sizeof(protocol_params.unx.unix_path), "%s", unix_path);

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


of_version_t of_version = OF_VERSION_1_4;

static uint32_t
xid_get(void)
{
    static uint32_t xid = 0;
    xid++;
    return xid;
}


static void
of_sendmsg(bool is_tls, intptr_t tl, of_object_t *obj)
{
    uint8_t *data;
    of_object_xid_set(obj, xid_get());
    of_object_wire_buffer_steal(obj, &data);
    if (is_tls) {
        ERR_clear_error();
        int rv = SSL_write((SSL*)tl, data, of_message_length_get(data));
        if (rv != of_message_length_get(data)) {
            if (rv == -1) {
                ERR_print_errors_fp(stderr);
            }
            INDIGO_ASSERT(rv == of_message_length_get(data),
                          "Expected to write %d bytes, got rv %d\n", 
                          of_message_length_get(data), rv);
        }
    } else {
        write((int)tl, data, of_message_length_get(data));
    }
    aim_free(data);
    of_object_delete(obj);
}


static void
of_send_hello(bool is_tls, intptr_t tl)
{
    of_sendmsg(is_tls, tl, of_hello_new(of_version));
}

static void
of_send_features_request(bool is_tls, intptr_t tl)
{
    of_sendmsg(is_tls, tl, of_features_request_new(of_version));
}

static void
of_send_aux_cxn_req(bool is_tls, intptr_t tl, int num_aux)
{
    of_bsn_set_aux_cxns_request_t* obj = 
        of_bsn_set_aux_cxns_request_new(of_version);
    of_bsn_set_aux_cxns_request_num_aux_set(obj, num_aux);
    of_sendmsg(is_tls, tl, obj);
}

static void
of_send_controller_connections_request(bool is_tls, intptr_t tl)
{
    printf("sending controller connections request\n");
    of_sendmsg(is_tls, tl,
               of_bsn_controller_connections_request_new(of_version));
}

static void
of_send_role_request(bool is_tls, intptr_t tl,
                     indigo_cxn_role_t newrole, uint64_t genid)
{
    of_role_request_t *req = of_role_request_new(of_version);
    of_role_request_role_set(req, newrole);
    of_role_request_generation_id_set(req, genid);
    of_sendmsg(is_tls, tl, req);
}


static of_object_t *
tcp_recvmsg(int tl, uint8_t buf[], int buflen,
            of_object_storage_t *storage)
{
    const int header_bytes = 8;
    int ret = 0;
    uint16_t msglen;
    int i = 0;

    do {
        ret = read(tl, buf, header_bytes);
        i++;
    } while (i < 256 && ret == -1 && errno == EAGAIN);
    INDIGO_ASSERT(ret != -1, "read error: %s", strerror(errno));
    INDIGO_ASSERT(ret == header_bytes, "read %d bytes, expected %d", 
                  ret, header_bytes);
    msglen = ntohs(*((uint16_t*)(buf+2)));
    INDIGO_ASSERT(msglen <= buflen, "message len %d exceeds buffer len %d",
                  msglen, buflen);
    ret = read(tl, buf+header_bytes, msglen-header_bytes);
    INDIGO_ASSERT(ret == msglen-header_bytes, 
                  "body read %d bytes, expected %d",
                  ret, msglen-header_bytes);

    return of_object_new_from_message_preallocated(storage, buf, msglen);
}

static of_object_t *
tls_recvmsg(SSL *ssl, uint8_t buf[], int buflen,
            of_object_storage_t *storage)
{
    const int header_bytes = 8;
    int ret = 0;
    uint16_t msglen;
    int i = 0;

    do {
        ERR_clear_error();
        ret = SSL_read(ssl, buf, header_bytes);
        i++;
    } while (i < 256 && ret == -1 && 
             SSL_get_error(ssl, ret) == SSL_ERROR_WANT_READ);
    if (ret == -1) {
        ERR_print_errors_fp(stderr);
    }
    INDIGO_ASSERT(ret == header_bytes, "read %d bytes, expected %d", 
                  ret, header_bytes);
    msglen = ntohs(*((uint16_t*)(buf+2)));
    INDIGO_ASSERT(msglen <= buflen, "message len %d exceeds buffer len %d",
                  msglen, buflen);
    if (msglen - header_bytes > 0) {
        ERR_clear_error();
        ret = SSL_read(ssl, buf+header_bytes, msglen-header_bytes);
        INDIGO_ASSERT(ret == msglen-header_bytes, 
                      "body read %d bytes, expected %d",
                      ret, msglen-header_bytes);
    }

    return of_object_new_from_message_preallocated(storage, buf, msglen);
}

static of_object_t *
of_recvmsg(bool is_tls, intptr_t tl, uint8_t buf[], int buflen,
           of_object_storage_t *storage)
{
    if (is_tls) {
        return tls_recvmsg((SSL*)tl, buf, buflen, storage);
    } else {
        return tcp_recvmsg((int)tl, buf, buflen, storage);
    }
}


/* returns listening socket */
static int
setup_server(int domain, char *addr, uint16_t port)
{
    int lsd;
    const int listen_backlog = 5;
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
    INDIGO_ASSERT(setsockopt(lsd, SOL_SOCKET, SO_REUSEADDR,
                             &flag, sizeof(int)) == 0, 
                  "could not set socket for reuse");

    if (domain == AF_UNIX) {
        struct sockaddr_un sun;
        sun.sun_family = AF_UNIX;
        snprintf(sun.sun_path, sizeof(sun.sun_path), "%s", addr);

        unlink(addr);
        INDIGO_ASSERT(bind(lsd, (struct sockaddr *) &sun, sizeof(sun)) == 0);
    } else {
        struct addrinfo hints;
        struct addrinfo *result;

        memset(&hints, 0, sizeof(struct addrinfo));
        hints.ai_family = AF_UNSPEC;
        hints.ai_socktype = SOCK_STREAM;
        hints.ai_flags = AI_PASSIVE;    /* For wildcard IP address */
        hints.ai_protocol = 0;          /* Any protocol */
        hints.ai_canonname = NULL;
        hints.ai_addr = NULL;
        hints.ai_next = NULL;

        snprintf(port_str, sizeof(port_str), "%u", port);
        INDIGO_ASSERT(getaddrinfo(addr, port_str, &hints, &result) == 0);
        int rv = bind(lsd, result->ai_addr, result->ai_addrlen);
        INDIGO_ASSERT(rv == 0, "bind returned %d, %s", rv, strerror(errno));
        freeaddrinfo(result);
    }

    INDIGO_ASSERT(listen(lsd, listen_backlog) == 0);

    return lsd;
}


/* returns the socket accepted from the specified listening socket */
static int
server_accept(int lsd)
{
    int sd;
    struct sockaddr_storage fromaddr;
    socklen_t fromaddrlen;
    int flag;
    int i = 0;

    fromaddrlen = sizeof(fromaddr);
    do {
        sd = accept(lsd, (struct sockaddr*) &fromaddr, &fromaddrlen);
        i++;
    } while (i < 256 && sd == -1 && errno == EAGAIN);
    INDIGO_ASSERT(sd != -1, "accept failed: %s", strerror(errno));

    if (fromaddr.ss_family == AF_INET) {
        struct sockaddr_in *sa = (struct sockaddr_in*) &fromaddr;
        printf("accepted from [IPv4addr]:%d\n",
               ntohs(sa->sin_port));
    } if (fromaddr.ss_family == AF_INET6) {
        struct sockaddr_in6 *sa6 = (struct sockaddr_in6*) &fromaddr;
        printf("accepted from [IPv6addr]:%d",
               ntohs(sa6->sin6_port));
    }

    INDIGO_ASSERT(sd >= 0);
    flag = fcntl(sd, F_GETFL, 0);
    INDIGO_ASSERT(flag != -1);
    INDIGO_ASSERT(fcntl(sd, F_SETFL, flag | O_NONBLOCK) != -1);

    return sd;
}


/*
 * to sidestep having to also manage SSL_CTXs,
 * each SSL structure will have its own SSL_CTX
 */
static SSL *
tls_attach(int sd)
{
    SSL_CTX *ctx;
    SSL *ssl;
    char filename[256];

    ctx = SSL_CTX_new(TLSv1_2_server_method());
    if (ctx == NULL) {
        ERR_print_errors_fp(stderr);
        assert(0);
    }

    SSL_CTX_set_options(ctx, SSL_OP_ALL |
                        SSL_OP_NO_SESSION_RESUMPTION_ON_RENEGOTIATION);

    if (SSL_CTX_set_cipher_list(ctx, "HIGH") != 1) {
        ERR_print_errors_fp(stderr);
        assert(0);
    }
    sprintf(filename, TEST_FS, basedir, MOD_NAME, CA_CERT_FILE);
    if (SSL_CTX_load_verify_locations(ctx, filename, NULL) != 1) {
        ERR_print_errors_fp(stderr);
        assert(0);
    }
    sprintf(filename, TEST_FS, basedir, MOD_NAME, CONTROLLER_CERT_FILE);
    if (SSL_CTX_use_certificate_file(ctx, filename, SSL_FILETYPE_PEM) != 1) {
        ERR_print_errors_fp(stderr);
        assert(0);
    }
    sprintf(filename, TEST_FS, basedir, MOD_NAME, CONTROLLER_PRIV_KEY_FILE);
    if (SSL_CTX_use_PrivateKey_file(ctx, filename, SSL_FILETYPE_PEM) != 1) {
        ERR_print_errors_fp(stderr);
        assert(0);
    }
    if (SSL_CTX_check_private_key(ctx) != 1) {
        fprintf(stderr, "private key does not match public certificate\n");
        assert(0);
    }
    SSL_CTX_set_verify(ctx, SSL_VERIFY_PEER | SSL_VERIFY_FAIL_IF_NO_PEER_CERT,
                       NULL);
    ssl = SSL_new(ctx);
    if (ssl == NULL) {
        ERR_print_errors_fp(stderr);
        assert(0);
    }
    SSL_set_mode(ssl, SSL_MODE_ENABLE_PARTIAL_WRITE);
    SSL_set_accept_state(ssl);
    if (SSL_set_fd(ssl, sd) != 1) {
        ERR_print_errors_fp(stderr);
        assert(0);
    }

    return ssl;
}

/* WARNING: frees associated SSL_CTX and closes underlying socket */
static void
tls_detach(SSL *ssl)
{
    SSL_CTX *ctx = SSL_get_SSL_CTX(ssl);
    int sd;

    sd = SSL_get_fd(ssl);
    close(sd);

    SSL_free(ssl);
    SSL_CTX_free(ctx);
}


static void
do_tls_handshake(SSL *ssl)
{
    int rv;
    int count = 0;
    do {
        OK(ind_soc_select_and_run(1));
        ERR_clear_error();
        rv = SSL_do_handshake(ssl);
        printf("do_handshake returns %d\n", rv);
        if (rv == 0) {
            fprintf(stderr, "shutdown controlled\n");
        } else if (rv < 0) {
            fprintf(stderr, "TLS error %d\n", SSL_get_error(ssl, rv));
            ERR_print_errors_fp(stderr);
        }
        count++;
    } while (rv != 1 && count < 256);
    INDIGO_ASSERT(rv == 1, "Failed to complete TLS handshake");
    printf("handshake complete, cipher %s\n", SSL_get_cipher(ssl));
}


/*
 * returns intptr_t containing transport layer:
 * int socket if is_tls is false
 * SSL* ssl if is_tls is true
 */
static intptr_t
advance_to_handshake_complete(bool use_tls,
                              int controller_id, int aux_id, int lsd)
{
    int sd;
    of_object_t *obj;
    of_object_storage_t storage;
    uint8_t buf[256];  /* may need to be increased */
    intptr_t tl;

    sd = server_accept(lsd);
    OK(ind_soc_select_and_run(1));
    INDIGO_ASSERT(!cxn_is_connected[controller_id][aux_id]);

    if (use_tls) {
        INDIGO_ASSERT(unit_test_cxn_state_get(controller_id, aux_id) ==
                      CXN_S_TLS_HANDSHAKING);
        tl = (intptr_t) tls_attach(sd);
        do_tls_handshake((SSL *)tl);
    } else {
        INDIGO_ASSERT(unit_test_cxn_state_get(controller_id, aux_id) ==
                      CXN_S_HANDSHAKING);
        tl = (intptr_t) sd;
    }

    of_send_hello(use_tls, tl);
    OK(ind_soc_select_and_run(100));
    /* check for hello */
    printf("check for hello\n");
    obj = of_recvmsg(use_tls, tl, buf, sizeof(buf), &storage);
    INDIGO_ASSERT(obj->object_id == OF_HELLO, "did not receive OF_HELLO");
    of_send_features_request(use_tls, tl);
    OK(ind_soc_select_and_run(100));
    INDIGO_ASSERT(cxn_is_connected[controller_id][aux_id], 
                  "controller_id %d, aux_id %d should be connected after features_req sent",
                  controller_id, aux_id);
    /* check for features reply */
    printf("check for features reply\n");
    obj = of_recvmsg(use_tls, tl, buf, sizeof(buf), &storage);
    INDIGO_ASSERT(obj->object_id == OF_FEATURES_REPLY,
                  "did not receive OF_FEATURES_REPLY");
    OK(ind_soc_select_and_run(1));
    INDIGO_ASSERT(cxn_is_connected[controller_id][aux_id], 
                  "controller_id %d, aux_id %d should be connected after features_reply received",
                  controller_id, aux_id);
    INDIGO_ASSERT(unit_test_cxn_state_get(controller_id, aux_id) ==
                  CXN_S_HANDSHAKE_COMPLETE);

    return tl;
}


static void
tl_close(bool use_tls, intptr_t tl)
{
    if (tl) {
        if (use_tls) {
            tls_detach((SSL*)tl);
        } else {
            close((int)tl);
        }
    }
}


static void
indigo_setup(void)
{
    char ca_cert_filename[256];
    char switch_cert_filename[256];
    char switch_priv_key_filename[256];
    ind_soc_config_t config; /* Currently ignored */

    sprintf(ca_cert_filename, TEST_FS, basedir, MOD_NAME, CA_CERT_FILE);
    sprintf(switch_cert_filename, TEST_FS, basedir, MOD_NAME,
            SWITCH_CERT_FILE);
    sprintf(switch_priv_key_filename, TEST_FS, basedir, MOD_NAME,
            SWITCH_PRIV_KEY_FILE);

    INDIGO_MEM_CLEAR(&config, sizeof(config));
    OK(ind_soc_init(&config));
    OK(ind_cxn_init(&cm_config));

    OK(indigo_cxn_status_change_register(cxn_status_change, NULL));

    indigo_cxn_config_tls("HIGH",
                          ca_cert_filename,
                          switch_cert_filename,
                          switch_priv_key_filename);

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
check_connection_list(of_object_t *obj, uint32_t expectedrole)
{
    int rv;
    of_bsn_controller_connections_reply_t *reply = obj;
    of_list_bsn_controller_connection_t list;
    of_bsn_controller_connection_t entry;

    of_bsn_controller_connections_reply_connections_bind(reply, &list);
    OF_LIST_BSN_CONTROLLER_CONNECTION_ITER(&list, &entry, rv) {
        uint8_t state;
        uint32_t role;
        of_bsn_controller_connection_state_get(&entry, &state);
        of_bsn_controller_connection_role_get(&entry, &role);
        INDIGO_ASSERT(state == 1, "expected state to be connected");
        INDIGO_ASSERT(role == expectedrole,
                      "expected role to be %d, got %d", expectedrole, role);
    }
}

static char*
get_tcp_tls(bool use_tls)
{
    return use_tls? "tls": "tcp";
}

static char*
get_domain_name(int domain)
{
    switch(domain) {
    case AF_UNIX:
        return "unix";
    case AF_INET:
        return "ipv4";
    case AF_INET6:
        return "ipv6";
    default:
        return "unknown";
    }
}

static void
test_normal(bool use_tls, int domain, char *addr)
{
    indigo_controller_id_t id;
    int lsd;
    intptr_t tl;
    of_object_t *obj;
    of_object_storage_t storage;
    uint8_t buf[512];  /* may need to be increased */

    printf("***Start %s, %s, domain %s, addr %s\n", __FUNCTION__, 
           get_tcp_tls(use_tls),
           get_domain_name(domain), addr);

    /* set up listening socket */
    lsd = setup_server(domain, addr, CONTROLLER_PORT1);

    indigo_setup();

    if (domain == AF_INET) {
        id = setup_cxn(use_tls, addr, CONTROLLER_PORT1);
    } else if (domain == AF_INET6) {
        id = setup_cxn_v6(use_tls, addr, CONTROLLER_PORT1);
    } else if (domain == AF_UNIX) {
        id = setup_cxn_unix(addr);
    } else {
        AIM_DIE("unknown domain %d", domain);
    }

    INDIGO_ASSERT(id >= 0);
    INDIGO_ASSERT(((domain == AF_INET || domain == AF_INET6) &&
                   unit_test_cxn_state_get(id, 0) == CXN_S_INIT) || 
                  ((domain == AF_UNIX) &&
                   unit_test_cxn_state_get(id, 0) == CXN_S_HANDSHAKING));

    OK(ind_soc_select_and_run(1));
    INDIGO_ASSERT(!cxn_is_connected[id][0]);
    INDIGO_ASSERT((!use_tls && 
                   unit_test_cxn_state_get(id, 0) == CXN_S_HANDSHAKING) ||
                  (use_tls &&
                   unit_test_cxn_state_get(id, 0) == CXN_S_TLS_HANDSHAKING));

    tl = advance_to_handshake_complete(use_tls, id, 0, lsd);
    INDIGO_ASSERT(unit_test_connection_count_get() == 1);

    printf("cxn socket events %d\n", unit_test_cxn_events_get(id, 0));
    INDIGO_ASSERT(unit_test_cxn_events_get(id, 0) == POLLIN);

    /* on handshake complete, unsolicited controller_connections_reply is sent */
    obj = of_recvmsg(use_tls, tl, buf, sizeof(buf), &storage);
    INDIGO_ASSERT(obj->object_id == OF_BSN_CONTROLLER_CONNECTIONS_REPLY,
                  "did not receive OF_BSN_CONTROLLER_CONNECTIONS_REPLY");
    check_connection_list(obj, OF_CONTROLLER_ROLE_EQUAL);

    /* change role to master */
    of_send_role_request(use_tls, tl, OF_CONTROLLER_ROLE_MASTER, 1);
    OK(ind_soc_select_and_run(50));

    /* on role change, unsolicited controller_connections_reply is sent */
    obj = of_recvmsg(use_tls, tl, buf, sizeof(buf), &storage);
    INDIGO_ASSERT(obj->object_id == OF_BSN_CONTROLLER_CONNECTIONS_REPLY,
                  "did not receive OF_BSN_CONTROLLER_CONNECTIONS_REPLY");
    check_connection_list(obj, OF_CONTROLLER_ROLE_MASTER);
    OK(ind_soc_select_and_run(50));

    /* check for role reply */
    obj = of_recvmsg(use_tls, tl, buf, sizeof(buf), &storage);
    INDIGO_ASSERT(obj->object_id == OF_ROLE_REPLY,
                  "did not receive OF_ROLE_REPLY, got %d", obj->object_id);

    printf("cxn socket events %d\n", unit_test_cxn_events_get(id, 0));
    INDIGO_ASSERT(unit_test_cxn_events_get(id, 0) == POLLIN);

    /* force rehandshake */
    if (use_tls) {
        int rv;
        int err;
        int i;
        printf("start renegotiate\n");
        ERR_clear_error();
        rv = SSL_renegotiate((SSL*)tl);
        INDIGO_ASSERT(rv == 1, "SSL_renegotiate returns rv %d", rv);
        ERR_clear_error();
        rv = SSL_do_handshake((SSL*)tl);
        INDIGO_ASSERT(rv == 1, "first SSL_do_handshake returns rv %d", rv);
        printf("cxn socket events %d\n", unit_test_cxn_events_get(id, 0));
        OK(ind_soc_select_and_run(100));
        printf("cxn socket events %d\n", unit_test_cxn_events_get(id, 0));
        ((SSL*)tl)->state = SSL_ST_ACCEPT;
        i = 0;
        do {
            printf("cxn socket events %d\n", unit_test_cxn_events_get(id, 0));
            OK(ind_soc_select_and_run(10));
            printf("cxn socket events %d\n", unit_test_cxn_events_get(id, 0));
            ERR_clear_error();
            rv = SSL_do_handshake((SSL*)tl);
            err = SSL_get_error((SSL*)tl, rv);
            i++;
        } while (i < 256 && rv == -1 && err == SSL_ERROR_WANT_READ);
        if (rv == -1) {
            ERR_print_errors_fp(stderr);
        }
        INDIGO_ASSERT(rv == 1, "second SSL_do_handshake returns rv %d, err %d", rv, err);
        printf("end renegotiate\n");
        printf("cxn socket events %d\n", unit_test_cxn_events_get(id, 0));
        OK(ind_soc_select_and_run(10));
        printf("cxn socket events %d\n", unit_test_cxn_events_get(id, 0));
    }

    /* once more for fun */
    of_send_controller_connections_request(use_tls, tl);
    OK(ind_soc_select_and_run(100));
    /* check for controller_connections_reply */
    obj = of_recvmsg(use_tls, tl, buf, sizeof(buf), &storage);
    INDIGO_ASSERT(obj->object_id == OF_BSN_CONTROLLER_CONNECTIONS_REPLY,
                  "did not receive OF_BSN_CONTROLLER_CONNECTIONS_REPLY");
    check_connection_list(obj, OF_CONTROLLER_ROLE_MASTER);

    tl_close(use_tls, tl);
    OK(ind_soc_select_and_run(1));
    INDIGO_ASSERT(!cxn_is_connected[id][0]);

    /* check that the client reconnected */
    OK(ind_soc_select_and_run(100));
    tl = advance_to_handshake_complete(use_tls, id, 0, lsd);
    INDIGO_ASSERT(unit_test_connection_count_get() == 1);

    OK(ind_soc_select_and_run(10));
    /* check for controller_connections_reply */
    obj = of_recvmsg(use_tls, tl, buf, sizeof(buf), &storage);
    INDIGO_ASSERT(obj->object_id == OF_BSN_CONTROLLER_CONNECTIONS_REPLY,
                  "did not receive OF_BSN_CONTROLLER_CONNECTIONS_REPLY");
    check_connection_list(obj, OF_CONTROLLER_ROLE_EQUAL);

    tl_close(use_tls, tl);

    ind_cxn_stats_show(&aim_pvs_stdout, 1);

    OK(indigo_controller_remove(id));
    OK(ind_soc_select_and_run(5));

    indigo_teardown();

    close(lsd);

    printf("***Stop %s, %s, domain %s, addr %s\n", __FUNCTION__, 
           get_tcp_tls(use_tls),
           get_domain_name(domain), addr);
}


static void
test_no_hello(bool use_tls)
{
    indigo_controller_id_t id;
    int lsd;
    int sd;
    intptr_t tl;
    of_object_t *obj;
    of_object_storage_t storage;
    uint8_t buf[256];  /* may need to be increaed */

    printf("***Start %s, %s\n", __FUNCTION__, get_tcp_tls(use_tls));

    /* set up listening socket */
    lsd = setup_server(AF_INET, CONTROLLER_IP, CONTROLLER_PORT1);

    indigo_setup();

    INDIGO_ASSERT((id = setup_cxn(use_tls, CONTROLLER_IP, CONTROLLER_PORT1)) >= 0);
    INDIGO_ASSERT(unit_test_cxn_state_get(id, 0) == CXN_S_INIT);

    OK(ind_soc_select_and_run(1));
    INDIGO_ASSERT(!cxn_is_connected[id][0]);
    INDIGO_ASSERT((!use_tls && 
                   unit_test_cxn_state_get(id, 0) == CXN_S_HANDSHAKING) ||
                  (use_tls &&
                   unit_test_cxn_state_get(id, 0) == CXN_S_TLS_HANDSHAKING));

    sd = server_accept(lsd);
    OK(ind_soc_select_and_run(1));
    INDIGO_ASSERT(!cxn_is_connected[id][0]);

    if (use_tls) {
        INDIGO_ASSERT(unit_test_cxn_state_get(id, 0) == CXN_S_TLS_HANDSHAKING);
        tl = (intptr_t) tls_attach(sd);
        do_tls_handshake((SSL *)tl);
    } else {
        INDIGO_ASSERT(unit_test_cxn_state_get(id, 0) == CXN_S_HANDSHAKING);
        tl = (intptr_t) sd;
    }

    OK(ind_soc_select_and_run(100));

    /* check for hello, but don't send hello */
    printf("checking for hello\n");
    obj = of_recvmsg(use_tls, tl, buf, sizeof(buf), &storage);
    INDIGO_ASSERT(obj->object_id == OF_HELLO);

    /* wait at least 5 seconds for timeout */
    OK(ind_soc_select_and_run(4*1000));
    INDIGO_ASSERT(!cxn_is_connected[id][0]);
    OK(ind_soc_select_and_run(1000+10));
    tl_close(use_tls, tl);

    /* check that the client reconnected */
    OK(ind_soc_select_and_run(10));
    sd = server_accept(lsd);
    INDIGO_ASSERT(!cxn_is_connected[id][0]);
    if (use_tls) {
        INDIGO_ASSERT(unit_test_cxn_state_get(id, 0) == CXN_S_TLS_HANDSHAKING);
        tl = (intptr_t) tls_attach(sd);
        do_tls_handshake((SSL *)tl);
    } else {
        INDIGO_ASSERT(unit_test_cxn_state_get(id, 0) == CXN_S_HANDSHAKING);
        tl = (intptr_t) sd;
    }

    tl_close(use_tls, tl);

    ind_cxn_stats_show(&aim_pvs_stdout, 1);

    OK(indigo_controller_remove(id));
    OK(ind_soc_select_and_run(5));

    indigo_teardown();

    close(lsd);

    printf("***Stop %s, %s\n", __FUNCTION__, get_tcp_tls(use_tls));
}


static void
test_no_features_request(bool use_tls)
{
    indigo_controller_id_t id;
    int lsd;
    int sd;
    intptr_t tl;
    of_object_t *obj;
    of_object_storage_t storage;
    uint8_t buf[256];  /* may need to be increaed */

    printf("***Start %s, %s\n", __FUNCTION__, get_tcp_tls(use_tls));

    /* set up listening socket */
    lsd = setup_server(AF_INET, CONTROLLER_IP, CONTROLLER_PORT1);

    indigo_setup();

    INDIGO_ASSERT((id = setup_cxn(use_tls, CONTROLLER_IP, CONTROLLER_PORT1)) >= 0);
    INDIGO_ASSERT(unit_test_cxn_state_get(id, 0) == CXN_S_INIT);

    OK(ind_soc_select_and_run(1));
    INDIGO_ASSERT(!cxn_is_connected[id][0]);
    INDIGO_ASSERT((!use_tls && 
                   unit_test_cxn_state_get(id, 0) == CXN_S_HANDSHAKING) ||
                  (use_tls &&
                   unit_test_cxn_state_get(id, 0) == CXN_S_TLS_HANDSHAKING));

    sd = server_accept(lsd);
    OK(ind_soc_select_and_run(1));
    INDIGO_ASSERT(!cxn_is_connected[id][0]);

    if (use_tls) {
        INDIGO_ASSERT(unit_test_cxn_state_get(id, 0) == CXN_S_TLS_HANDSHAKING);
        tl = (intptr_t) tls_attach(sd);
        do_tls_handshake((SSL *)tl);
    } else {
        INDIGO_ASSERT(unit_test_cxn_state_get(id, 0) == CXN_S_HANDSHAKING);
        tl = (intptr_t) sd;
    }

    of_send_hello(use_tls, tl);
    OK(ind_soc_select_and_run(100));
    /* check for hello */
    printf("checking for hello\n");
    obj = of_recvmsg(use_tls, tl, buf, sizeof(buf), &storage);
    INDIGO_ASSERT(obj->object_id == OF_HELLO);

    /* wait at least 5 seconds for timeout */
    OK(ind_soc_select_and_run(4*1000));
    INDIGO_ASSERT(!cxn_is_connected[id][0]);
    OK(ind_soc_select_and_run(1000+10));
    tl_close(use_tls, tl);

    /* check that the client reconnected */
    OK(ind_soc_select_and_run(10));
    sd = server_accept(lsd);
    INDIGO_ASSERT(!cxn_is_connected[id][0]);
    if (use_tls) {
        INDIGO_ASSERT(unit_test_cxn_state_get(id, 0) == CXN_S_TLS_HANDSHAKING);
        tl = (intptr_t) tls_attach(sd);
        do_tls_handshake((SSL *)tl);
    } else {
        INDIGO_ASSERT(unit_test_cxn_state_get(id, 0) == CXN_S_HANDSHAKING);
        tl = (intptr_t) sd;
    }

    tl_close(use_tls, tl);

    ind_cxn_stats_show(&aim_pvs_stdout, 1);

    OK(indigo_controller_remove(id));
    OK(ind_soc_select_and_run(5));

    indigo_teardown();

    close(lsd);

    printf("***Stop %s, %s\n", __FUNCTION__, get_tcp_tls(use_tls));
}


static void
test_aux3(bool use_tls, int delta)
{
    indigo_controller_id_t id;
    int lsd;
    intptr_t tl;
    of_object_t *obj;
    of_object_storage_t storage;
    uint8_t buf[2048];  /* may need to be increaed */
    const int num_aux = 3;
    const int max_aux = 8;
    uint32_t status;
    intptr_t aux_tl[max_aux];
    int i;

    printf("***Start %s, %s with delta %d\n", __FUNCTION__,
           get_tcp_tls(use_tls), delta);

    for (i = 0; i < max_aux; i++) {
        aux_tl[i] = 0;
    }

    /* set up listening socket */
    lsd = setup_server(AF_INET, CONTROLLER_IP, CONTROLLER_PORT1);

    indigo_setup();

    INDIGO_ASSERT((id = setup_cxn(use_tls, CONTROLLER_IP, CONTROLLER_PORT1)) >= 0);
    INDIGO_ASSERT(unit_test_cxn_state_get(id, 0) == CXN_S_INIT);

    OK(ind_soc_select_and_run(1));
    INDIGO_ASSERT(!cxn_is_connected[id][0]);
    INDIGO_ASSERT((!use_tls && 
                   unit_test_cxn_state_get(id, 0) == CXN_S_HANDSHAKING) ||
                  (use_tls &&
                   unit_test_cxn_state_get(id, 0) == CXN_S_TLS_HANDSHAKING));

    printf("Advance main connection to handshake complete\n");
    tl = advance_to_handshake_complete(use_tls, id, 0, lsd);

    printf("Start aux connections\n");
    of_send_aux_cxn_req(use_tls, tl, num_aux);
    OK(ind_soc_select_and_run(50));

    /* check for aux cxns reply */
    i = 0;
    do {
        obj = of_recvmsg(use_tls, tl, buf, sizeof(buf), &storage);
        i++;
    } while (i < 256 && obj->object_id != OF_BSN_SET_AUX_CXNS_REPLY);
    INDIGO_ASSERT(obj->object_id == OF_BSN_SET_AUX_CXNS_REPLY,
                  "did not receive OF_BSN_SET_AUX_CXNS_REPLY");
    of_bsn_set_aux_cxns_reply_status_get(obj, &status);
    INDIGO_ASSERT(status == 0, "aux connections reply status should be zero");

    /* note we are off by 1 on aux_id */
    for (i = 0; i < num_aux; i++) {
        aux_tl[i] = advance_to_handshake_complete(use_tls, id, i+1, lsd);
    }

    if (delta) {
        printf("Handle delta of %d\n", delta);

        of_send_aux_cxn_req(use_tls, tl, num_aux + delta);
        OK(ind_soc_select_and_run(50));

        i = 0;
        do {
            obj = of_recvmsg(use_tls, tl, buf, sizeof(buf), &storage);
            i++;
        } while (i < 256 && obj->object_id != OF_BSN_SET_AUX_CXNS_REPLY);
        INDIGO_ASSERT(obj->object_id == OF_BSN_SET_AUX_CXNS_REPLY,
                      "did not receive OF_BSN_SET_AUX_CXNS_REPLY");
        of_bsn_set_aux_cxns_reply_status_get(obj, &status);
        INDIGO_ASSERT(status == 0,
                      "aux connections reply status should be zero");

        if (delta > 0) {
            /* aux_tl index is aux_id-1 */
            for (i = 0; i < delta; i++) {
                aux_tl[num_aux+i] =
                    advance_to_handshake_complete(use_tls, id,
                                                  num_aux+i+1, lsd);
                INDIGO_ASSERT(aux_tl[num_aux+i] > 0);
            }
        } else {
            /* just give some time to clean up */
            OK(ind_soc_select_and_run(50));
        }
    }

    tl_close(use_tls, tl);
    OK(ind_soc_select_and_run(1));
    for (i = 0; i < MAX_AUX_CONNECTIONS; i++) {
        INDIGO_ASSERT(!cxn_is_connected[id][i]);
        tl_close(use_tls, aux_tl[i]);
    }

    /* check that the client reconnected */
    OK(ind_soc_select_and_run(100));
    tl = advance_to_handshake_complete(use_tls, id, 0, lsd);
    INDIGO_ASSERT(unit_test_connection_count_get() == 1);
    tl_close(use_tls, tl);

    ind_cxn_stats_show(&aim_pvs_stdout, 1);

    OK(indigo_controller_remove(id));
    OK(ind_soc_select_and_run(5));

    indigo_teardown();

    close(lsd);

    printf("***Stop %s, %s with delta %d\n", __FUNCTION__,
           get_tcp_tls(use_tls), delta);
}


/* returns connected socket */
static int
setup_ipv4_client(char *ip, uint16_t port)
{
    int sd;
    struct addrinfo hints;
    struct addrinfo *result;
    char port_str[16];
    int flag;
    int rv;
    int i = 0;

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    snprintf(port_str, sizeof(port_str), "%u", port);
    INDIGO_ASSERT(getaddrinfo(ip, port_str, &hints, &result) == 0);

    sd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    INDIGO_ASSERT(sd > 0, "error creating client socket: %s",
                  strerror(errno));

    flag = fcntl(sd, F_GETFL, 0);
    INDIGO_ASSERT(flag != -1);
    INDIGO_ASSERT(fcntl(sd, F_SETFL, flag | O_NONBLOCK) != -1);

    do {
        rv = connect(sd, result->ai_addr, result->ai_addrlen);
        i++;
    } while (i < 256 && 
             ((rv == -1) && ((errno == EINPROGRESS) || (errno == EAGAIN))));
    INDIGO_ASSERT(rv == 0, "error connecting: %s", strerror(errno));

    freeaddrinfo(result);

    return sd;
}

/* returns connected socket */
static int
setup_unix_client(char *addr)
{
    int sd;
    struct sockaddr_un sun;

    sd = socket(AF_UNIX, SOCK_STREAM, 0);
    INDIGO_ASSERT(sd > 0, "error creating client socket: %s",
                  strerror(errno));

    sun.sun_family = AF_UNIX;
    snprintf(sun.sun_path, sizeof(sun.sun_path), "%s", addr);
    INDIGO_ASSERT(connect(sd, (struct sockaddr *) &sun, sizeof(sun)) == 0,
                  "error connecting: %s", strerror(errno));

    return (intptr_t) sd;
}

static int
setup_ipv4_listener(bool use_tls, char *ip, int controller_port)
{
    indigo_cxn_protocol_params_t protocol_params;
    indigo_cxn_config_params_t config_params;
    indigo_controller_id_t id;

    memset(&config_params, 0, sizeof(config_params));
    config_params.version = OF_VERSION_1_4;
    config_params.local = 1;
    config_params.listen = 1;

    protocol_params.tcp_over_ipv4.protocol = use_tls?
        INDIGO_CXN_PROTO_TLS_OVER_IPV4: INDIGO_CXN_PROTO_TCP_OVER_IPV4;
    sprintf(protocol_params.tcp_over_ipv4.controller_ip, "%s", ip);
    protocol_params.tcp_over_ipv4.controller_port = controller_port;

    OK(indigo_controller_add(&protocol_params, &config_params, &id));

    return id;
}

static int
setup_unix_listener(char *path)
{
    indigo_cxn_protocol_params_t protocol_params;
    indigo_cxn_config_params_t config_params;
    indigo_controller_id_t id;

    memset(&config_params, 0, sizeof(config_params));
    config_params.version = OF_VERSION_1_4;
    config_params.local = 1;
    config_params.listen = 1;

    protocol_params.unx.protocol = INDIGO_CXN_PROTO_UNIX;
    snprintf(protocol_params.unx.unix_path,
             sizeof(protocol_params.unx.unix_path), "%s", path);

    OK(indigo_controller_add(&protocol_params, &config_params, &id));

    return id;
}


static void
test_listener(bool use_tls, int domain)
{
    indigo_controller_id_t id;
    int sd;
    intptr_t tl; 
    of_object_t *obj;
    of_object_storage_t storage;
    uint8_t buf[256];  /* may need to be increaed */

    printf("***Start %s, %s, domain %s\n", __FUNCTION__,
           get_tcp_tls(use_tls),
           get_domain_name(domain));

    indigo_setup();

    /* set up connection manager listening connection */
    if (domain == AF_UNIX) {
        id = setup_unix_listener(CONTROLLER_UNIX);
    } else {
        id = setup_ipv4_listener(use_tls, 
                                 CONTROLLER_IP, CONTROLLER_LISTEN_PORT);
    }
    OK(ind_soc_select_and_run(1));

    /* connect to listener */
    if (domain == AF_UNIX) {
        sd = setup_unix_client(CONTROLLER_UNIX);
    } else {
        sd = setup_ipv4_client(CONTROLLER_IP, CONTROLLER_LISTEN_PORT);
    }

    if (use_tls) {
        tl = (intptr_t) tls_attach(sd);
        do_tls_handshake((SSL *)tl);
    } else {
        tl = (intptr_t) sd;
    }

    OK(ind_soc_select_and_run(1));
    /* send hello */
    of_send_hello(use_tls, tl);
    OK(ind_soc_select_and_run(100));
    /* check for hello */
    printf("check for hello\n");
    obj = of_recvmsg(use_tls, tl, buf, sizeof(buf), &storage);
    INDIGO_ASSERT(obj->object_id == OF_HELLO, "did not receive OF_HELLO");
    of_send_features_request(use_tls, tl);
    OK(ind_soc_select_and_run(100));
    /* check for features reply */
    printf("check for features reply\n");
    obj = of_recvmsg(use_tls, tl, buf, sizeof(buf), &storage);
    INDIGO_ASSERT(obj->object_id == OF_FEATURES_REPLY,
                  "did not receive OF_FEATURES_REPLY");
    /* close */
    tl_close(use_tls, tl);

    /* verify that we can reconnect to listener */
    if (domain == AF_UNIX) {
        sd = setup_unix_client(CONTROLLER_UNIX);
    } else {
        sd = setup_ipv4_client(CONTROLLER_IP, CONTROLLER_LISTEN_PORT);
    }

    if (use_tls) {
        tl = (intptr_t) tls_attach(sd);
        do_tls_handshake((SSL *)tl);
    } else {
        tl = (intptr_t) sd;
    }

    OK(ind_soc_select_and_run(1));
    /* send hello */
    of_send_hello(use_tls, tl);
    OK(ind_soc_select_and_run(100));
    /* check for hello */
    printf("listener reconnect: check for hello\n");
    obj = of_recvmsg(use_tls, tl, buf, sizeof(buf), &storage);
    INDIGO_ASSERT(obj->object_id == OF_HELLO, "did not receive OF_HELLO");
    of_send_features_request(use_tls, tl);
    OK(ind_soc_select_and_run(100));
    /* check for features reply */
    printf("check for features reply\n");
    obj = of_recvmsg(use_tls, tl, buf, sizeof(buf), &storage);
    INDIGO_ASSERT(obj->object_id == OF_FEATURES_REPLY,
                  "did not receive OF_FEATURES_REPLY");
    /* close */
    tl_close(use_tls, tl);

    OK(indigo_controller_remove(id));
    /* increased time to allow second controller/connection pair to be
     * removed */
    OK(ind_soc_select_and_run(50));

    indigo_teardown();

    printf("***Stop %s, %s, domain %s\n", __FUNCTION__,
           get_tcp_tls(use_tls),
           get_domain_name(domain));
}


/*
 * add and remove two controllers from cxnmgr.
 * each time no controllers are configured,
 * decide to add either the first or the second, and then add the other.
 * each time two controllers are configured,
 * decide to remove either the first or the second, and then remove the other.
 */
static void
test_dual(bool use_tls)
{
#define NUM_CONTROLLERS 2
    int controller_ports[NUM_CONTROLLERS] = {
        CONTROLLER_PORT1, CONTROLLER_PORT2,
    };
    indigo_controller_id_t cid[NUM_CONTROLLERS];
    int lsd[NUM_CONTROLLERS];
    intptr_t tl[NUM_CONTROLLERS];

    /* bit number corresponds to controller state: 0 removed, 1 added */
    int events[] = {
        0, 1, 3, 1, 0, 2, 3, 2, 0, 1, 3, 2, 0, 2, 3, 1, 0,
    };
    int num_events = sizeof(events)/sizeof(int);
    int mapcount[] = { 0, 1, 1, 2 };
    int idx;

    printf("***Start %s, %s\n", __FUNCTION__, get_tcp_tls(use_tls));

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
            cid[con_idx] = setup_cxn(use_tls, CONTROLLER_IP,
                                     controller_ports[con_idx]);
            tl[con_idx] = advance_to_handshake_complete(use_tls, 
                                                        cid[con_idx], 0,
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
            tl_close(use_tls, tl[con_idx]);
        }
    }

    indigo_teardown();

    for (idx = 0; idx < NUM_CONTROLLERS; idx++) {
        close(lsd[idx]);
    }

    printf("***Stop %s, %s\n", __FUNCTION__, get_tcp_tls(use_tls));
}


/* provide bad non-listener parameters to indigo_controller_add() */
static void
test_bad_controller(bool use_tls)
{
    indigo_cxn_protocol_params_t protocol_params;
    indigo_cxn_config_params_t config_params;
    indigo_controller_id_t id;

    printf("***Start %s, %s\n", __FUNCTION__, get_tcp_tls(use_tls));

    indigo_setup();

    memset(&config_params, 0, sizeof(config_params));
    config_params.version = OF_VERSION_1_4;

    protocol_params.tcp_over_ipv4.protocol = use_tls?
        INDIGO_CXN_PROTO_TLS_OVER_IPV4: INDIGO_CXN_PROTO_TCP_OVER_IPV4;
    /* use bogus ip address */
    sprintf(protocol_params.tcp_over_ipv4.controller_ip, "%s", 
            "192.168.0.255.0");
    protocol_params.tcp_over_ipv4.controller_port = CONTROLLER_PORT1;

    INDIGO_ASSERT(indigo_controller_add(&protocol_params, &config_params, &id)
                  != INDIGO_ERROR_NONE);

    indigo_teardown();

    printf("***Stop %s, %s\n", __FUNCTION__, get_tcp_tls(use_tls));
}


/* provide bad listener parameters to indigo_controller_add() */
static void
test_bad_listener(bool use_tls)
{
    indigo_cxn_protocol_params_t protocol_params;
    indigo_cxn_config_params_t config_params;
    indigo_controller_id_t id;

    printf("***Start %s, %s\n", __FUNCTION__, get_tcp_tls(use_tls));

    indigo_setup();

    memset(&config_params, 0, sizeof(config_params));
    config_params.version = OF_VERSION_1_4;
    config_params.local = 1;
    config_params.listen = 1;

    protocol_params.tcp_over_ipv4.protocol = use_tls?
        INDIGO_CXN_PROTO_TLS_OVER_IPV4: INDIGO_CXN_PROTO_TCP_OVER_IPV4;
    /* use bogus ip address */
    sprintf(protocol_params.tcp_over_ipv4.controller_ip, "%s", 
            "192.168.0.255.0");
    protocol_params.tcp_over_ipv4.controller_port = CONTROLLER_LISTEN_PORT;

    INDIGO_ASSERT(indigo_controller_add(&protocol_params, &config_params, &id)
                  != INDIGO_ERROR_NONE);

    indigo_teardown();

    printf("***Stop %s, %s\n", __FUNCTION__, get_tcp_tls(use_tls));
}


/* send valid parameters to indigo_controller_add(), 
 * but do not set up a controller in the first place */
static void
test_no_controller(bool use_tls)
{
    indigo_controller_id_t id;

    printf("***Start %s, %s\n", __FUNCTION__, get_tcp_tls(use_tls));

    indigo_setup();

    id = setup_cxn(use_tls, CONTROLLER_IP, CONTROLLER_PORT1);
    INDIGO_ASSERT(id >= 0);
    INDIGO_ASSERT(unit_test_cxn_state_get(id, 0) == CXN_S_INIT);
    OK(ind_soc_select_and_run(2500));

    ind_cxn_stats_show(&aim_pvs_stdout, 1);

    OK(indigo_controller_remove(id));
    OK(ind_soc_select_and_run(50));

    indigo_teardown();

    printf("***Stop %s, %s\n", __FUNCTION__, get_tcp_tls(use_tls));
}


void run_all_tests(bool use_tls)
{
    test_bad_controller(use_tls);
    test_bad_listener(use_tls);
    test_no_controller(use_tls);

    test_normal(use_tls, AF_INET, CONTROLLER_IP);
    test_normal(use_tls, AF_INET6, CONTROLLER_IPV6);
    /* disable linklocal test; address is currently hardcoded */
    /* test_normal(AF_INET6, CONTROLLER_IPV6_LINKLOCAL); */
    if (!use_tls) {
        test_normal(use_tls, AF_UNIX, CONTROLLER_UNIX);
    }

    test_no_hello(use_tls);
    test_no_features_request(use_tls);

    test_aux3(use_tls, 0);
    test_aux3(use_tls, 1);
    test_aux3(use_tls, -1);

    test_dual(use_tls);

    test_listener(use_tls, AF_INET);
    if (!use_tls) {
        test_listener(use_tls, AF_UNIX);
    }
}


/* KHC FIXME add test_no_tls_handshake */
/* none started, or partial handshake done */
/* KHC FIXME barrier test */
/* KHC FIXME barrier inside of bundle */


int aim_main(int argc, char* argv[])
{
    bool use_tls;

    basedir = dirname(argv[0]);

    use_tls = false;
    run_all_tests(use_tls);

    use_tls = true;
    run_all_tests(use_tls);

    return 0;
}

