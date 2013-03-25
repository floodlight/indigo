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
 *  SocketManager Unit Testing
 *
 *****************************************************************************/


#include <SocketManager/socketmanager_config.h>

/*
 * Very simple test code for socket manager
 *
 * To complete the test, you need to start a TCP server on port 12345 of
 * localhost which will send some data and can accept data.  OFTest
 * works nicely...:)
 */

#include <SocketManager/socketmanager.h>
#include <stdio.h>
#include <indigo/assert.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "socketmanager_log.h"

/* Indigo globals */

static int socket_called = 0;
static int timer_called = 0;
static int sock_write_seen = 0;
static int sock_read_seen = 0;


static void
socket_callback(
    int socket_id,
    void *cookie,
    int read_ready,
    int write_ready,
    int error_seen)
{
    char buf[2048];
    int bytes_read;

    printf("Socket callback called: id %d. rd %d. wr %d. er %d\n",
           socket_id, read_ready, write_ready, error_seen);
    socket_called = 1;
    if (write_ready) {
        sock_write_seen = 1;
        send(socket_id, "x", 1, MSG_DONTWAIT);
        ind_soc_data_out_clear(socket_id);
    }
    if (read_ready) {
        printf("Reading from socket %d\n", socket_id);
        bytes_read = read(socket_id, buf, 2048);
        printf("Read in %d bytes\n", bytes_read);
        sock_read_seen = 1;
        ind_soc_data_out_ready(socket_id);
    }
    INDIGO_ASSERT(!error_seen);
}


static void
timer_callback(void *cookie)
{
    printf("Timer callback called: cookie %p\n", cookie);
    timer_called = 1;

    ind_soc_timer_event_unregister(timer_callback, NULL);
}

static void
timer_callback_repeat(void *cookie)
{
    printf("%d: Timer repeat callback called: cookie %p.\n",
           timer_called, cookie);
    timer_called += 1;
}

int
main(int argc, char* argv[])
{
    ind_soc_config_t config = {0};
    int fds[2];

    printf("Init returned %d\n", ind_soc_init(&config));

    /* Should be called once */
    ind_soc_timer_event_register(timer_callback, NULL,
                                 IND_SOC_TIMER_IMMEDIATE);
    ind_soc_select_and_run(10);
    INDIGO_ASSERT(timer_called);
    timer_called = 0;
    ind_soc_select_and_run(1000);
    INDIGO_ASSERT(!timer_called);

    ind_soc_timer_event_register(timer_callback, NULL, 100);
    ind_soc_select_and_run(1000);
    INDIGO_ASSERT(timer_called);

    timer_called = 0;
    ind_soc_timer_event_register(timer_callback_repeat, NULL, 100);
    ind_soc_select_and_run(1000);
    INDIGO_ASSERT(timer_called >= 9);
    ind_soc_timer_event_unregister(timer_callback_repeat, NULL);

    if (socketpair(AF_UNIX, SOCK_STREAM, 0, fds) < 0) {
        perror("socketpair");
        abort();
    }

    INDIGO_ASSERT(ind_soc_socket_register(fds[0], socket_callback, NULL) == 0);
    INDIGO_ASSERT(ind_soc_socket_register(fds[1], socket_callback, NULL) == 0);
    ind_soc_data_out_ready(fds[0]);
    ind_soc_data_out_ready(fds[1]);
    /* Do stuff for 3 seconds */
    ind_soc_select_and_run(3000);

    INDIGO_ASSERT(socket_called > 0);
    INDIGO_ASSERT(sock_read_seen > 0);
    INDIGO_ASSERT(sock_write_seen > 0);

    return 0;
}

