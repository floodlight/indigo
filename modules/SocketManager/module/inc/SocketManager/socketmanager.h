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
 * @brief The Indigo Reference Implementation Socket Manager Interfaces
 *
 * This file defines the interfaces for the socket manager.  This
 * module provides a socket registration mechanism for centralized
 * control of socket select calls.  It also provides a lightweight
 * timer interface for repeating events.
 *
 * @addtogroup SocketManager
 * @{
 */


#ifndef __SOCKETMANAGER_H__
#define __SOCKETMANAGER_H__

#include "socketmanager_config.h"

#include <indigo/error.h>
#include <stdint.h>
#include <limits.h>

/****************************************************************
 * Socket register functions
 ****************************************************************/

/*
 * Priorities are signed integers. Higher priority events are handled first.
 */
#define IND_SOC_DEFAULT_PRIORITY 0
#define IND_SOC_HIGHEST_PRIORITY INT_MAX
#define IND_SOC_LOWEST_PRIORITY  INT_MIN

/**
 * Run status.
 *
 * See ind_soc_run_status_set.
 */
typedef enum ind_soc_run_status_e {

    /** OK. Processing will continue. */
    IND_SOC_RUN_STATUS_OK,
    /** EXIT. Return immediately from select_and_run(). */
    IND_SOC_RUN_STATUS_EXIT,

    /** Count. */
    IND_SOC_RUN_STATUS_COUNT

} ind_soc_run_status_t;


/**
 * Callback for socket ready
 *
 * @param socket_id The ID of the socket that is ready
 * @param cookie Data passed to ind_soc_socket_register
 * @param read_ready The socket indicated read is ready (boolean)
 * @param write_ready The socket indicated write is ready (boolean)
 * @param error The socket indicated an error occurred (boolean)
 */

typedef void (*ind_soc_socket_ready_callback_f)(
    int socket_id,
    void *cookie,
    int read_ready,
    int write_ready,
    int error_seen);

/**
 * Register a socket for processing by the socket manager
 *
 * @param socket_id The socket on which to select
 * @param callback The function to call on socket event
 * @param cookie Data to pass to the callback
 * @param priority Priority when handling events
 *
 * Provided by socket manager, required by various
 */

indigo_error_t ind_soc_socket_register_with_priority(
    int socket_id,
    ind_soc_socket_ready_callback_f callback,
    void *cookie,
    int priority);

/**
 * Register a socket for processing by the socket manager
 *
 * @param socket_id The socket on which to select
 * @param callback The function to call on socket event
 * @param cookie Data to pass to the callback
 *
 * This is a wrapper around ind_soc_socket_register_with_priority which
 * passes IND_SOC_DEFAULT_PRIORITY for the priority.
 *
 * Provided by socket manager, required by various
 */

indigo_error_t ind_soc_socket_register(
    int socket_id,
    ind_soc_socket_ready_callback_f callback,
    void *cookie);

/**
 * Unregister a socket for processing by the socket manager
 *
 * @param socket_id The socket id to be unregistered
 *
 * Provided by socket manager, required by various
 */

indigo_error_t ind_soc_socket_unregister(int socket_id);

/**
 * Indicate that data is ready to be sent out socket
 *
 * @param socket_id The socket id
 *
 * The socket will be marked for write in the select; if
 * write is ready, the write variable will be set on the
 * callback.
 *
 * Provided by socket manager, required by various
 */

indigo_error_t ind_soc_data_out_ready(int socket_id);

/**
 * Indicate no data is ready to be sent out socket
 *
 * @param socket_id The socket id
 *
 * Provided by socket manager, required by various
 */

indigo_error_t ind_soc_data_out_clear(int socket_id);

/**
 * Indicate that the reads from the socket should be disabled
 *
 * @param socket_id The socket id
 *
 * The socket manager should assume that no more reads on the
 * socket will be serviced until ind_soc_data_in_resume is called.
 *
 * Provided by socket manager, required by various
 */

indigo_error_t ind_soc_data_in_pause(int socket_id);

/**
 * Indicate that reads from the socket will be serviced
 *
 * @param socket_id The socket id
 *
 * The process reading from the socket is ready to process
 * data available on the socket.
 *
 * Provided by socket manager, required by various
 */

indigo_error_t ind_soc_data_in_resume(int socket_id);

/****************************************************************
 * Timer register functions
 ****************************************************************/

/**
 * Callback for timer event
 *
 * @param cookie Data passed to ind_soc_timer_event_register
 */

typedef void  (*ind_soc_timer_callback_f)(void *cookie);

/**
 * Value to use when you wish to invoke something "immediately"
 *
 * NOTE: Timers registered with this timeout will only be invoked once.
 */

#define IND_SOC_TIMER_IMMEDIATE 0

/**
 * Register a timer event
 *
 * @param callback Timer callback function
 * @param cookie Opaque data passed to callback
 * @param repeat_time_ms Minimum time (ms) between timer callbacks,
 *                       or IND_SOC_TIMER_IMMEDIATE
 *
 * If a timer already exists with the given callback and cookie then
 * its period will be modified and it will be reset to run repeat_time_ms
 * milliseconds in the future.
 *
 * If no timer exists with the given callback and cookie then it will
 * be created.
 */

indigo_error_t ind_soc_timer_event_register_with_priority(
    ind_soc_timer_callback_f callback,
    void *cookie,
    int repeat_time_ms,
    int priority);

/**
 * Register a timer event
 *
 * @param callback Timer callback function
 * @param cookie Opaque data passed to callback
 * @param repeat_time_ms Minimum time (ms) between timer callbacks,
 *                       or IND_SOC_TIMER_IMMEDIATE
 *
 * This function is a wrapper around ind_soc_timer_event_register which passes
 * IND_SOC_DEFAULT_PRIORITY for the priority.
 */

indigo_error_t ind_soc_timer_event_register(
    ind_soc_timer_callback_f callback,
    void *cookie,
    int repeat_time_ms);

/**
 * Unregister a timer event
 *
 * @param callback Timer callback function
 * @param cookie Opaque data passed to callback
 *
 * The timer to unregister is keyed on both the callback and cookie.
 */

indigo_error_t ind_soc_timer_event_unregister(
    ind_soc_timer_callback_f callback,
    void *cookie);

/****************************************************************
 * Task functions
 ****************************************************************/

typedef enum ind_soc_task_status {
    IND_SOC_TASK_CONTINUE,
    IND_SOC_TASK_FINISHED,
} ind_soc_task_status_t;

/**
 * Callback for task
 *
 * @param task Task handle (used to unregister)
 * @param cookie Data passed to ind_soc_task_register
 * @returns Whether the task is finished
 */

typedef ind_soc_task_status_t (*ind_soc_task_callback_f)(void *cookie);

/**
 * Register a task
 *
 * @param callback Task callback function
 * @param cookie Opaque data passed to callback
 * @param priority Priority level
 */

indigo_error_t ind_soc_task_register(
    ind_soc_task_callback_f callback,
    void *cookie, int priority);


typedef struct ind_soc_config_s {
    uint32_t flags; /* Ignored */
} ind_soc_config_t;

/****************************************************************
 *
 * The Socket Manager API
 *
 ****************************************************************/

/**
 * Configure the socket manager
 * @param config The configuration structure for the socket manager
 * @returns An error code
 *
 * The socket manager does not require any routines from other
 * modules.
 */

extern indigo_error_t ind_soc_init(ind_soc_config_t *config);

/**
 * Process events and run callbacks
 *
 * @param run_for_ms How long to run before returning
 * @returns INDIGO_ERROR_NOT_FOUND if no sockets or events are available
 * @returns INDIGO_ERROR_UNKNOWN if select returns an error
 * @returns INDIGO_ERROR_NONE if normal timeout occurs
 *
 * If run_for_ms is 0, do not block.  If it is -1, do not return except
 * on error (either no sockets and no timer events; or socket error).
 *
 * First, all timer events are checked and ready events have their callback
 * run.  Then select is run on all registered sockets.  Those that have called
 * data_out_ready will be checked for write availability as well.
 *
 * Provided by socket manager, required by application
 */

extern indigo_error_t ind_soc_select_and_run(int run_for_ms);

/**
 * Set explicit run status.
 *
 * If status is IND_SOC_RUN_STATUS_EXIT then ind_soc_select_and_run
 * will exit immediately with INDIGO_ERROR_NONE. The run status is
 * reset to IND_SOC_RUN_STATUS_OK when ind_soc_select_and_run is
 * next called.
 */

extern void ind_soc_run_status_set(ind_soc_run_status_t status);

/**
 * Check whether the current callback should yield
 *
 * This function will return true if too much time has passed
 * since the callback began.
 *
 * This should be only called after the callback has done some
 * minimal amount of work to ensure forward progress.
 *
 * Only valid from a SocketManager callback.
 *
 * @returns Boolean
 */

int ind_soc_should_yield(void);


/**
 * Enable the socket manager
 */

extern indigo_error_t ind_soc_enable_set(int enable);

/**
 * Get the enable state for the manager
 */

extern indigo_error_t ind_soc_enable_get(int *enable);

/**
 * Tear down and clean up the socket manager
 */

extern indigo_error_t ind_soc_finish(void);

#endif /* __SOCKETMANAGER_H__ */
/* @} */
