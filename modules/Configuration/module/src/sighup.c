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

#include <unistd.h>
#include <signal.h>
#include <indigo/error.h>
#include <SocketManager/socketmanager.h>
#include "configuration_int.h"
#include "configuration_log.h"


/* Pipe used to signal the main event loop from the SIGHUP handler. */
static int pipefd[2];

static void
sighup(int signum)
{
    if (write(pipefd[1], "x", 1) < 0) {
        /* silence warn_unused_result */
    }
}

static void
sighup_callback(int socket_id, void *cookie,
                int read_ready, int write_ready, int error_seen)
{
    char buf;
    if (read(pipefd[0], &buf, 1) < 0) {
        /* silence warn_unused_result */
    }
    AIM_LOG_MSG("received SIGHUP");
    ind_cfg_load();
}

/* Set up the SIGHUP handler to load the new configuration. */
indigo_error_t
ind_cfg_install_sighup_handler(void)
{
    if (pipe(pipefd) < 0) {
        return INDIGO_ERROR_UNKNOWN;
    }

    (void) signal(SIGHUP, sighup);

    return ind_soc_socket_register_with_priority(
        pipefd[0], sighup_callback, NULL, 20);
}
