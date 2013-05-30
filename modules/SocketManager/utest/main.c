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

#include <SocketManager/socketmanager.h>
#include <stdio.h>
#include <indigo/assert.h>
#include <indigo/time.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "socketmanager_log.h"

static int sigalrm_write_fd = -1;

struct sock_counters {
    int read;
    int write;
};

static void
socket_callback(
    int socket_id,
    void *cookie,
    int read_ready,
    int write_ready,
    int error_seen)
{
    struct sock_counters *counters = cookie;
    printf("Socket callback called: id %d. rd %d. wr %d. er %d\n",
           socket_id, read_ready, write_ready, error_seen);
    INDIGO_ASSERT(!error_seen);

    if (write_ready) {
        counters->write++;
        if (write(socket_id, "x", 1) != 1) {
            perror("write");
            abort();
        }
        ind_soc_data_out_clear(socket_id);
    }

    if (read_ready) {
        char buf;
        counters->read++;
        if (read(socket_id, &buf, 1) != 1) {
            perror("read");
            abort();
        }
        INDIGO_ASSERT(buf == 'x');
    }
}

static void
sigalrm(int signum)
{
    if (write(sigalrm_write_fd, "x", 1) != 1) {
        perror("write");
        abort();
    }
}

static void
test_socket(void)
{
    int fds[2];
    struct sock_counters counters[2];
    indigo_time_t start_time, end_time;
    struct itimerval itv;

    signal(SIGALRM, sigalrm);

    if (socketpair(AF_UNIX, SOCK_STREAM, 0, fds) < 0) {
        perror("socketpair");
        abort();
    }

    INDIGO_ASSERT(ind_soc_socket_register(fds[0], socket_callback, &counters[0]) == 0);
    INDIGO_ASSERT(ind_soc_socket_register(fds[1], socket_callback, &counters[1]) == 0);

    /* No events ready */
    memset(counters, 0, sizeof(counters));
    ind_soc_select_and_run(0);
    INDIGO_ASSERT(counters[0].read == 0);
    INDIGO_ASSERT(counters[0].write == 0);
    INDIGO_ASSERT(counters[1].read == 0);
    INDIGO_ASSERT(counters[1].write == 0);

    /* Write one byte to fds[0] */
    ind_soc_data_out_ready(fds[0]);
    memset(counters, 0, sizeof(counters));
    ind_soc_select_and_run(0);
    INDIGO_ASSERT(counters[0].read == 0);
    INDIGO_ASSERT(counters[0].write == 1);
    INDIGO_ASSERT(counters[1].read == 0);
    INDIGO_ASSERT(counters[1].write == 0);

    /* Read one byte from fds[1] */
    memset(counters, 0, sizeof(counters));
    ind_soc_select_and_run(0);
    INDIGO_ASSERT(counters[0].read == 0);
    INDIGO_ASSERT(counters[0].write == 0);
    INDIGO_ASSERT(counters[1].read == 1);
    INDIGO_ASSERT(counters[1].write == 0);

    /* Write one byte to each of fds[0] and fds[1] */
    ind_soc_data_out_ready(fds[0]);
    ind_soc_data_out_ready(fds[1]);
    memset(counters, 0, sizeof(counters));
    ind_soc_select_and_run(0);
    INDIGO_ASSERT(counters[0].read == 0);
    INDIGO_ASSERT(counters[0].write == 1);
    INDIGO_ASSERT(counters[1].read == 0);
    INDIGO_ASSERT(counters[1].write == 1);

    /* Read one byte from each of fds[0] and fds[1] */
    memset(counters, 0, sizeof(counters));
    ind_soc_select_and_run(0);
    INDIGO_ASSERT(counters[0].read == 1);
    INDIGO_ASSERT(counters[0].write == 0);
    INDIGO_ASSERT(counters[1].read == 1);
    INDIGO_ASSERT(counters[1].write == 0);

    /* Write one byte to fds[0] */
    ind_soc_data_out_ready(fds[0]);
    memset(counters, 0, sizeof(counters));
    ind_soc_select_and_run(0);
    INDIGO_ASSERT(counters[0].read == 0);
    INDIGO_ASSERT(counters[0].write == 1);
    INDIGO_ASSERT(counters[1].read == 0);
    INDIGO_ASSERT(counters[1].write == 0);

    /* Pause data in from fds[1], expect no reads */
    ind_soc_data_in_pause(fds[1]);
    memset(counters, 0, sizeof(counters));
    ind_soc_select_and_run(0);
    INDIGO_ASSERT(counters[0].read == 0);
    INDIGO_ASSERT(counters[0].write == 0);
    INDIGO_ASSERT(counters[1].read == 0);
    INDIGO_ASSERT(counters[1].write == 0);

    /* Resume data in from fds[1] */
    ind_soc_data_in_resume(fds[1]);
    memset(counters, 0, sizeof(counters));
    ind_soc_select_and_run(0);
    INDIGO_ASSERT(counters[0].read == 0);
    INDIGO_ASSERT(counters[0].write == 0);
    INDIGO_ASSERT(counters[1].read == 1);
    INDIGO_ASSERT(counters[1].write == 0);

    /* Block for some time with no events */
    memset(counters, 0, sizeof(counters));
    start_time = INDIGO_CURRENT_TIME;
    ind_soc_select_and_run(100);
    end_time = INDIGO_CURRENT_TIME;
    INDIGO_ASSERT(counters[0].read == 0);
    INDIGO_ASSERT(counters[0].write == 0);
    INDIGO_ASSERT(counters[1].read == 0);
    INDIGO_ASSERT(counters[1].write == 0);
    INDIGO_ASSERT((end_time - start_time) >= 100 &&
                  (end_time - start_time) < 200);

    /* Block for some time until SIGALRM, which causes read ready on fd[1] */
    memset(counters, 0, sizeof(counters));
    memset(&itv, 0, sizeof(itv));
    sigalrm_write_fd = fds[0];
    itv.it_value.tv_usec = 100*1000;
    setitimer(ITIMER_REAL, &itv, NULL);
    ind_soc_select_and_run(200);
    INDIGO_ASSERT(counters[0].read == 0);
    INDIGO_ASSERT(counters[0].write == 0);
    INDIGO_ASSERT(counters[1].read == 1);
    INDIGO_ASSERT(counters[1].write == 0);

    INDIGO_ASSERT(ind_soc_socket_unregister(fds[0]) == 0);
    INDIGO_ASSERT(ind_soc_socket_unregister(fds[1]) == 0);

    close(fds[0]);
    close(fds[1]);
}

/* Test add/remove of sockets */
static void
test_socket_mgmt(void)
{
    int fds[2];
    struct sock_counters counters[2];

    if (socketpair(AF_UNIX, SOCK_STREAM, 0, fds) < 0) {
        perror("socketpair");
        abort();
    }

    /* Unregistering a not-registered socket should fail */
    INDIGO_ASSERT(ind_soc_socket_unregister(fds[0]) < 0);

    /* Adding and then unregistering a socket should succeed */
    INDIGO_ASSERT(ind_soc_socket_register(fds[0], socket_callback, &counters[0]) == 0);
    INDIGO_ASSERT(ind_soc_socket_unregister(fds[0]) == 0);

    /* Trying to unregister twice should fail */
    INDIGO_ASSERT(ind_soc_socket_unregister(fds[0]) < 0);

    /* Trying to register twice should fail */
    INDIGO_ASSERT(ind_soc_socket_register(fds[0], socket_callback, &counters[0]) == 0);
    INDIGO_ASSERT(ind_soc_socket_register(fds[0], socket_callback, &counters[0]) < 0);

    /* Add another socket, then remove the first */
    INDIGO_ASSERT(ind_soc_socket_register(fds[1], socket_callback, &counters[1]) == 0);
    INDIGO_ASSERT(ind_soc_socket_unregister(fds[0]) == 0);

    /* Write one byte to fds[1] */
    ind_soc_data_out_ready(fds[1]);
    memset(counters, 0, sizeof(counters));
    ind_soc_select_and_run(0);
    INDIGO_ASSERT(counters[0].read == 0);
    INDIGO_ASSERT(counters[0].write == 0);
    INDIGO_ASSERT(counters[1].read == 0);
    INDIGO_ASSERT(counters[1].write == 1);

    /* Expect no events from the not-registered fds[0] */
    memset(counters, 0, sizeof(counters));
    ind_soc_select_and_run(0);
    INDIGO_ASSERT(counters[0].read == 0);
    INDIGO_ASSERT(counters[0].write == 0);
    INDIGO_ASSERT(counters[1].read == 0);
    INDIGO_ASSERT(counters[1].write == 0);

    /* Register fds[0] and expect a read event */
    INDIGO_ASSERT(ind_soc_socket_register(fds[0], socket_callback, &counters[0]) == 0);
    memset(counters, 0, sizeof(counters));
    ind_soc_select_and_run(0);
    INDIGO_ASSERT(counters[0].read == 1);
    INDIGO_ASSERT(counters[0].write == 0);
    INDIGO_ASSERT(counters[1].read == 0);
    INDIGO_ASSERT(counters[1].write == 0);

    INDIGO_ASSERT(ind_soc_socket_unregister(fds[0]) == 0);
    INDIGO_ASSERT(ind_soc_socket_unregister(fds[1]) == 0);

    close(fds[0]);
    close(fds[1]);
}


static void
timer_callback(void *cookie)
{
    int *count_ptr = cookie;
    (*count_ptr)++;
    printf("Timer callback called count=%d\n", *count_ptr);
}

static void
timer_callback_reregister(void *cookie)
{
    int *count_ptr = cookie;
    (*count_ptr)++;
    printf("Timer reregister callback called count=%d\n", *count_ptr);
    ind_soc_timer_event_register(timer_callback_reregister, cookie, 10);
}

static void
timer_callback_unregister(void *cookie)
{
    int *count_ptr = cookie;
    (*count_ptr)++;
    printf("Timer unregister callback called count=%d\n", *count_ptr);
    ind_soc_timer_event_unregister(timer_callback_unregister, cookie);
}

static void
test_periodic_timer(void)
{
    int count;

    /* Should fire every 'repeat_time_ms' */
    count = 0;
    ind_soc_timer_event_register(timer_callback, &count, 100);
    ind_soc_select_and_run(1000);
    INDIGO_ASSERT(count >= 9 && count <= 11);
    INDIGO_ASSERT(ind_soc_timer_event_unregister(timer_callback, &count) == 0);

    /* A timer may re-register itself with a different period during its callback */
    count = 0;
    ind_soc_timer_event_register(timer_callback_reregister, &count, 100);
    ind_soc_select_and_run(1000);
    INDIGO_ASSERT(count > 50 && count < 100);
    INDIGO_ASSERT(ind_soc_timer_event_unregister(timer_callback_reregister, &count) == 0);

    /* A timer may unregister itself during its callback */
    count = 0;
    ind_soc_timer_event_register(timer_callback_unregister, &count, 100);
    ind_soc_select_and_run(1000);
    INDIGO_ASSERT(count == 1);
    INDIGO_ASSERT(ind_soc_timer_event_unregister(timer_callback_unregister, &count) < 0);
}

static void
test_immediate_timer(void)
{
    int count = 0;
    INDIGO_ASSERT(ind_soc_timer_event_register(
        timer_callback, &count, IND_SOC_TIMER_IMMEDIATE) == 0);

    /* Should run immediately */
    ind_soc_select_and_run(0);
    INDIGO_ASSERT(count == 1);

    /* Should be unregistered after firing */
    count = 0;
    ind_soc_select_and_run(100);
    INDIGO_ASSERT(count == 0);

    /* Should be unregistered after firing */
    INDIGO_ASSERT(ind_soc_timer_event_unregister(timer_callback, &count) < 0);
}

static void
test_timer_mgmt(void)
{
    /* Should be able to register a timer */
    INDIGO_ASSERT(ind_soc_timer_event_register(
        timer_callback, (void*)1, 10) == 0);

    /* Should be able to re-register a timer */
    INDIGO_ASSERT(ind_soc_timer_event_register(
        timer_callback, (void*)1, 100) == 0);

    /* Should be able to unregister a timer */
    INDIGO_ASSERT(ind_soc_timer_event_unregister(
        timer_callback, (void*)1) == 0);

    /* Should not be able to unregister a timer twice */
    INDIGO_ASSERT(ind_soc_timer_event_unregister(
        timer_callback, (void*)1) < 0);

    /* Should not be able to unregister a NULL callback */
    INDIGO_ASSERT(ind_soc_timer_event_unregister(
        NULL, (void*)1) < 0);

    /* Should be able to register and unregister a bunch of timers */
    {
        int i, j;

        for (i = 0; 1; i++) {
            indigo_error_t err = ind_soc_timer_event_register(
                timer_callback, (void *)(uintptr_t)i, 100);
            if (err < 0) {
                INDIGO_ASSERT(err == INDIGO_ERROR_RESOURCE);
                break;
            }
        }

        for (j = 0; 1; j++) {
            indigo_error_t err = ind_soc_timer_event_unregister(
                timer_callback, (void *)(uintptr_t)j);
            if (err < 0) {
                INDIGO_ASSERT(err == INDIGO_ERROR_NOT_FOUND);
                break;
            }
        }

        INDIGO_ASSERT(i == j);
        INDIGO_ASSERT(i >= 16);
    }
}

static void
test_priority(void)
{
    int read_fds[3], write_fds[3];
    struct sock_counters counters[3];
    int timer_counters[3];
    int i;

    for (i = 0; i < 3; i++) {
        int fds[2];
        if (pipe(fds) < 0) {
            perror("pipe");
            abort();
        }
        read_fds[i] = fds[0];
        write_fds[i] = fds[1];
    }

    /* High priority */
    INDIGO_ASSERT(ind_soc_socket_register_with_priority(
        read_fds[0], socket_callback, &counters[0], 1) == 0);

    INDIGO_ASSERT(ind_soc_timer_event_register_with_priority(
        timer_callback, &timer_counters[0], IND_SOC_TIMER_IMMEDIATE, 1) == 0);

    /* Medium priority */
    INDIGO_ASSERT(ind_soc_socket_register_with_priority(
        read_fds[1], socket_callback, &counters[1], 0) == 0);

    INDIGO_ASSERT(ind_soc_timer_event_register_with_priority(
        timer_callback, &timer_counters[1], IND_SOC_TIMER_IMMEDIATE, 0) == 0);

    /* Low priority */
    INDIGO_ASSERT(ind_soc_socket_register_with_priority(
        read_fds[2], socket_callback, &counters[2], -1) == 0);

    INDIGO_ASSERT(ind_soc_timer_event_register_with_priority(
        timer_callback, &timer_counters[2], IND_SOC_TIMER_IMMEDIATE, -1) == 0);

    /* Make all sockets ready */
    for (i = 0; i < 3; i++) {
        write(write_fds[i], "x", 1);
    }

    /* Higher priority events should run first */
    memset(counters, 0, sizeof(counters));
    memset(timer_counters, 0, sizeof(timer_counters));
    ind_soc_select_and_run(0);
    INDIGO_ASSERT(counters[0].read == 1);
    INDIGO_ASSERT(counters[1].read == 0);
    INDIGO_ASSERT(counters[2].read == 0);
    INDIGO_ASSERT(timer_counters[0] == 1);
    INDIGO_ASSERT(timer_counters[1] == 0);
    INDIGO_ASSERT(timer_counters[2] == 0);

    /* Medium priority events should run next */
    memset(counters, 0, sizeof(counters));
    memset(timer_counters, 0, sizeof(timer_counters));
    ind_soc_select_and_run(0);
    INDIGO_ASSERT(counters[0].read == 0);
    INDIGO_ASSERT(counters[1].read == 1);
    INDIGO_ASSERT(counters[2].read == 0);
    INDIGO_ASSERT(timer_counters[0] == 0);
    INDIGO_ASSERT(timer_counters[1] == 1);
    INDIGO_ASSERT(timer_counters[2] == 0);

    /* New high priority events should run next */
    write(write_fds[0], "x", 1);
    memset(counters, 0, sizeof(counters));
    memset(timer_counters, 0, sizeof(timer_counters));
    ind_soc_select_and_run(0);
    INDIGO_ASSERT(counters[0].read == 1);
    INDIGO_ASSERT(counters[1].read == 0);
    INDIGO_ASSERT(counters[2].read == 0);
    INDIGO_ASSERT(timer_counters[0] == 0);
    INDIGO_ASSERT(timer_counters[1] == 0);
    INDIGO_ASSERT(timer_counters[2] == 0);

    /* Low priority events should run last */
    memset(counters, 0, sizeof(counters));
    memset(timer_counters, 0, sizeof(timer_counters));
    ind_soc_select_and_run(0);
    INDIGO_ASSERT(counters[0].read == 0);
    INDIGO_ASSERT(counters[1].read == 0);
    INDIGO_ASSERT(counters[2].read == 1);
    INDIGO_ASSERT(timer_counters[0] == 0);
    INDIGO_ASSERT(timer_counters[1] == 0);
    INDIGO_ASSERT(timer_counters[2] == 1);

    INDIGO_ASSERT(ind_soc_socket_unregister(read_fds[0]) == 0);
    INDIGO_ASSERT(ind_soc_socket_unregister(read_fds[1]) == 0);
    INDIGO_ASSERT(ind_soc_socket_unregister(read_fds[2]) == 0);

    /* One-shot timers, already unregistered */
    INDIGO_ASSERT(ind_soc_timer_event_unregister(
        timer_callback, &timer_counters[0]) < 0);
    INDIGO_ASSERT(ind_soc_timer_event_unregister(
        timer_callback, &timer_counters[1]) < 0);
    INDIGO_ASSERT(ind_soc_timer_event_unregister(
        timer_callback, &timer_counters[3]) < 0);

    for (i = 0; i < 3; i++) {
        close(read_fds[i]);
        close(write_fds[i]);
    }
}

int
main(int argc, char* argv[])
{
    ind_soc_config_t config = {0};

    printf("Init returned %d\n", ind_soc_init(&config));

    test_timer_mgmt();
    test_periodic_timer();
    test_immediate_timer();
    test_socket();
    test_socket_mgmt();
    test_priority();

    return 0;
}

