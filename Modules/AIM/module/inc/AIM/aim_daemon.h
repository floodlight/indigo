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
 * @file
 * @brief AIM Daemon and Supervisor Support.
 *
 * Provides:
 * - daemonization() support.
 * - conditional automatic restart.
 *
 * @addtogroup aim-daemon
 * @{
 *
 *****************************************************************************/
#ifndef __AIM_DAEMON_H__
#define __AIM_DAEMON_H__

#include <AIM/aim_config.h>

#if AIM_CONFIG_INCLUDE_DAEMONIZE == 1

#include <AIM/aim_bitmap.h>
#include <AIM/aim_pvs.h>

/**
 * Configuration for automatic daemon restarts.
 */
typedef struct aim_daemon_restart_config_s {

    /**
     * Bitmap of signal codes that should cause an automatic restart.
     *
     * If the daemonized process exits with a signal, and that signal bit
     * is set in this bitmask, then the process will be automatically
     * restarted with the original command line arguments.
     *
     * If the signal bit is not set then everything is allowed to terminate.
     */
    aim_bitmap256_t signal_restarts;

    /**
     * Bitmap of exit codes that should cause an automatic restart.
     *
     * If the daemonized process exits normally, and the exit code
     * from the process is set in this bitmask, then the process will
     * be automatically restarted with the original command line arguments.
     *
     * If the exit code bit is not set then everything is allowed to terminate.
     */
    aim_bitmap256_t exit_restarts;

    /**
     * Maximum restart count, if applicable.
     * Set to zero for infinite restarts.
     */
    int maximum_restarts;

    /**
     * Maximum restart rate, if applicable.
     * Abort if restarts occur faster than the given rate.
     *
     * Not currently implemented.
     */
    int maximum_restart_rate;

    /**
     * Logfile for the watchdog restart process.
     * Process restart events will be logged to this file, if specified.
     */
    const char* restart_log;

    /**
     * Output PVS for the watchdog restart process.
     * Process restart events will be logged to this PVS if specified.
     */
    aim_pvs_t* pvs;

} aim_daemon_restart_config_t;


/**
 * Daemon configuration.
 */
typedef struct aim_daemon_config_s {

    /** Working Directory */
    const char* wd;

    /** Set stdout/stderr to this file. /dev/null if unspecified. */
    const char* stdlog;

    /**
     * Use a lockfile.
     *
     * Not currently implemented.
     */
    const char* lockfile;

} aim_daemon_config_t;


/**
 * @brief Initialize an aim_daemon_restart_t structure.
 * @param [out] config The configuration to initialize.
 * @param signalbits Initial value for all signal_restart bits.
 * @param exitbits Initial value for all exit_restart bits.
 * @note This must be called prior to modifing it or passing it
 * to aim_daemonize()
 */
void aim_daemon_restart_config_init(aim_daemon_restart_config_t* config,
                                    int signalbits, int exitbits);


/**
 * @brief Daemonize ourselves.
 * @param daemon_config Daemon configuration.
 * @param restart_config Restart configuration (Optional).
 *
 * @note daemon_config can be NULL, in which case all configuration
 * values will be treated as unset.
 *
 * @note restart_config can be NULL, in which case no restart processing
 * is enabled. We fork and daemonize only, with no additional watchdog process.
 *
 * @note If restart_config is not NULL, a restart process will be forked()
 * which monitors the exit status of the original daemon. If the conditions
 * in the restart_config are satisfied, the entire daemon will be restarted
 * using the original AIM commandline arguments.
 *
 * @note Simply calling aim_daemonize(NULL, NULL) is sufficient to perform traditional daemonization.
 */

void aim_daemonize(aim_daemon_config_t* daemon_config,
                   aim_daemon_restart_config_t* restart_config);


#endif /* AIM_CONFIG_INCLUDE_DAEMONIZE */
#endif /* __AIM_DAEMON_H__ */
/* @} */

