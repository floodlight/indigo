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

/**************************************************************************//**
 *
 *
 *
 *
 *****************************************************************************/
#include <AIM/aim_config.h>
#include <AIM/aim_daemon.h>
#include <AIM/aim.h>

#if AIM_CONFIG_INCLUDE_DAEMONIZE == 1

#include <stdlib.h>
#include <stdio.h>

#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * This special return code should always be masked from restarts.
 */
#define AIM_DAEMON_EXIT_CODE_ABORT_RESTART 0x42

/**
 * Initialize a restart config structure.
 */
void
aim_daemon_restart_config_init(aim_daemon_restart_config_t* config,
                               int signalbits, int exitbits)
{
    AIM_MEMSET(config, 0, sizeof(*config));

    AIM_BITMAP_INIT(&config->signal_restarts, 256);
    AIM_BITMAP_INIT(&config->exit_restarts, 256);

    if(signalbits) {
        AIM_BITMAP_SET_ALL(&config->signal_restarts);
    }
    if(exitbits) {
        AIM_BITMAP_SET_ALL(&config->exit_restarts);
    }

    AIM_BITMAP_CLR(&config->exit_restarts, AIM_DAEMON_EXIT_CODE_ABORT_RESTART);
}


/**
 * There are restart cases where we need to communicate to a newly
 * exec'ed process that it has already been daemonized, and that
 * future calls to aim_daemonize() should just return.
 *
 * This special environment variable is passed to those
 * child processes and checked at daemonize time.
 */

#define AIM_PROCESS_IS_DAEMONIZED "AIM_PROCESS_IS_DAEMONIZED"


/**
 * This environment variable will store the name of a file
 * to output debug messages (for development and debug of this
 * code only; optional)
 */
#define AIM_DAEMONIZE_DEBUG_LOG "AIM_DAEMONIZE_DEBUG_LOG"


/**
 * This is for basic debugging of the daemon code itself.
 */
static FILE* daemon_debug_fp__ = NULL;

static void
daemon_dbg__(const char* fmt, ...)
{
    va_list vargs;
    if(daemon_debug_fp__) {
        va_start(vargs, fmt);
        vfprintf(daemon_debug_fp__, fmt, vargs);
        fprintf(daemon_debug_fp__, "\n");
        fflush(daemon_debug_fp__);
        va_end(vargs);
        fflush(stdout);
    }
}

/**
 * If there is a daemon log specified, it will be set here.
 */
static FILE* daemon_log_fp__ = NULL;

/**
 * If there is a deemon log PVS, it will be set here.
 */
static aim_pvs_t* daemon_log_pvs__ = NULL;

/* Output a daemon operational message */
static void
daemon_msg__(const char* fmt, ...)
{
    va_list vargs;
    char msg[128];

    va_start(vargs, fmt);
    vsnprintf(msg, sizeof(msg)-1, fmt, vargs);
    va_end(vargs);

    /* Debug output */
    daemon_dbg__("msg: %s", msg);

    /* Output to daemon log file, if configured */
    if(daemon_log_fp__) {
        fprintf(daemon_log_fp__, "%s\n", msg);
        fflush(daemon_log_fp__);
    }

    if(daemon_log_pvs__) {
        aim_printf(daemon_log_pvs__, "%s", msg);
    }

    /*
     * Our current stdout points to the original stdout
     * specified in 'config->stdlog'.
     *
     * If this happens to go somewhere useful, drop our
     * message into that log file as well.
     *
     */
    printf("%s\n", msg);
    fflush(stdout);
}

void
aim_daemonize(aim_daemon_config_t* config,
              aim_daemon_restart_config_t* restart_config)
{
    int pid;

    /**
     * Have we been restarted while already a daemon?
     */
    if(getenv(AIM_PROCESS_IS_DAEMONIZED)) {
        return;
    }

    if(getppid() == 1) {
        /*
         * We are already a child of the init process (pid=1).
         * This mean's we've already been orphaned, and are already in
         * daemon mode.
         *
         * We shouldn't ever get here -- the AIM_PROCESS_IS_DAEMONIZED
         * check should always succeed first.
         */
        daemon_dbg__("getppid() == 1");
        return;
    }

    /*
     * Internal debug and trace messages will go here.
     */
    if(getenv(AIM_DAEMONIZE_DEBUG_LOG)) {
        daemon_debug_fp__ = fopen(getenv(AIM_DAEMONIZE_DEBUG_LOG), "w");
    }


    /* First Fork */
    pid = fork();

    if(pid < 0) {
        perror("fork: ");
        exit(1);
    }

    if(pid != 0) {
        /*
         * We're the parent process. Exit now and make our forked
         * child an orphan.
         */
        exit(0);
    }

    /*
     * We're the orphaned child.
     *
     * If a lockfile was specified, check that our instance
     * can proceed at all.
     *
     */
#if NOTYET
    if(config && config->lockfile) {
        lockfd = open(config->lockfile, O_RDWR|O_CREAT);
        if(lockfd < 0) {
            exit(1);
        }
        if(lockf(lockfd, F_TLOCK, 0) < 0) {
            /* Already running */
            if(read(lockfd, pids, sizeof(pids)) > 0) {
                printf("daemon already running with pid=%s\n", pids);
            }
            exit(0);
        }
    }
#endif

    /*
     * Detach ourselves from our previous process group.
     */
    setsid();

    /*
     * Set a new working directory, if specified.
     */
    if(config && config->wd) {
        chdir(config->wd);
    }

    /*
     * Reopen stdin as /dev/null
     */
    freopen("/dev/null", "r", stdin);

    if(config && config->stdlog != NULL) {
        /* stdout and stderr should go to the given file. */
        daemon_dbg__("opening %s as new stdout/stderr", config->stdlog);
        unlink(config->stdlog);
        freopen(config->stdlog, "w", stdout);
        freopen(config->stdlog, "w", stderr);
    }
    else {
        /* stdout and stderr should go to /dev/null as well. */
        daemon_dbg__("opening /dev/null as new stdout/stderr");
        freopen("/dev/null", "w", stdout);
        freopen("/dev/null", "w", stderr);
    }


    /* TODO: Signals Go Here */



    /*
     * Communicate to all future children that they are already
     * daemonized. Only important for restarts, so they don't fork
     * again.
     */
    setenv(AIM_PROCESS_IS_DAEMONIZED, "1", 1);

    if(restart_config) {
        daemon_dbg__("restart config");
        /*
         * Fork again.
         * - The child will be the daemon.
         * - The parent will wait and restart if the child exits
         *   based on conditions specified in restart_config,
         *
         * This may seem wasteful, but it actually costs very little,
         * as the kernel will share all code pages between the two processes.
         * There won't be two full copies, one of which is just sitting there,
         * doing nothing.
         *
         * Assuming you haven't done significant heap allocations prior to
         * calling daemonize(), or have large BSS segments, it should  cost
         * nothing more than the current stack memory and a new process
         * context (which you would have anyways).
         */
        pid = fork();

        if(pid == 0) {
            /*
             * Child again. Now we can finally do something.
             * At this point, there is no need to do anything
             * but allow continued execution.
             */
            daemon_dbg__("forked child returning...");
            return;
        }
        else {
            int status;
            int counter = 0;
            daemon_dbg__("restart loop started.");

            if(restart_config->restart_log) {
                daemon_log_fp__ = fopen(restart_config->restart_log, "w");
            }

            if(restart_config->pvs) {
                daemon_log_pvs__ = restart_config->pvs;
                daemon_msg__("daemon_msg");
            }

            for(counter = 0;
                restart_config->maximum_restarts <= 0 ||
                    counter < restart_config->maximum_restarts; counter++) {

                /*
                 * Wait for child termination.
                 */
                daemon_dbg__("waitpid(%d)...", pid);
                waitpid(pid, &status, 0);
                daemon_dbg__("waitpid(%d) returned, status=0x%x", pid, status);

                if(WIFSIGNALED(status)) {
                    /* Child terminated with a signal */
                    int sig = WTERMSIG(status);
                    daemon_dbg__("signal termination");

                    /* Is this signal part of the restart mask? */
                    if(AIM_BITMAP_GET(&restart_config->signal_restarts,
                                      sig) == 0) {
                        /* Restarts are not indicated for this signal */
                        daemon_msg__("Process %d died with signal %d (%s) (status = 0x%.4x). Not restarted.",
                                     pid, sig, strsignal(sig), status);
                        exit(0);
                    }
                    else {
                        /* Restart */
                        daemon_msg__("Process %d died with signal %d (%s) (status = 0x%.4x). Restarting...",
                                     pid, sig, strsignal(sig), status);
                        /* restart happens below */
                    }
                }
                else if(WIFEXITED(status)) {
                    /* Child exited normally */
                    int ecode = WEXITSTATUS(status);

                    daemon_dbg__("exit termination");

                    /* Is this exit code part of the restart mask? */
                    if(AIM_BITMAP_GET(&restart_config->exit_restarts,
                                      ecode) == 0) {
                        /* Restarts are not indicated for this exit code */
                        daemon_msg__("Process %d exited with code %d (status = 0x%.4x). Not restarting.",
                                     pid, ecode, status);
                        exit(0);
                    }
                    else {
                        daemon_msg__("Process %d exited with code %d (status = 0x%.5x). Restarting...",
                                     pid, ecode, status);
                        /* restart below */
                    }
                }
                else {
                    /* This shouldn't happen */
                    daemon_msg__("Process %d exit without signal or exit code set (status = 0x%.4x). Not restarting.",
                                 pid, status);
                    exit(1);
                }

                /*
                 * If we get here, we need to restart.
                 */
                daemon_dbg__("Forking again...");
                pid = fork();
                if(pid == 0) {
                    /* New child -- exec with original arguments. (Fixme) */
                    extern char** __aim_argv__;
                    daemon_msg__("execvp %s ...", __aim_argv__[0]);
                    if(execvp(__aim_argv__[0], __aim_argv__) < 0) {
                        daemon_msg__("execvp failed: %d (%s)\n",
                                     errno, strerror(errno));

                        /*
                         * We're supposed to be the daemon process, but
                         * our exec() failed. It probably means we'll never
                         * be able to restart. This special return code
                         * should be configured to never restart...
                         */
                        exit(AIM_DAEMON_EXIT_CODE_ABORT_RESTART);
                    }
                }

                /* Continue loop to wait on new child */
            }
        }
    }
    else {
        /* No restart processing requested. Allow execution to continue. */
        return;
    }
}


#else
int __not_empty__;
#endif
