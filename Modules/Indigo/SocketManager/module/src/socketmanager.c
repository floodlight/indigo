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
 * Implementation of SocketManager functionality
 *
 * Uses the socket ID as an index.
 *
 * @todo Make the max socket ID supported a parameter to the module
 * @todo Make the max timer events supported a parameter to the module
 * @todo "current_socket_id_max" never decreases now.  Fix that
 *
 * @todo Consider supporting both periodic and single events.  Currently
 * periodic events are supported with a special one-shot, immediate
 * operation.  Other than for one-shot events, events are responsible for
 * unregistering.
 *
 * For scheduling one-time events, the call should return an index.  The
 * "cancel" call should require both the index as well as the callback and
 * cookie pointers.
 *
 * See header file for detailed function documentation.
 *
 *****************************************************************************/

#include "socketmanager_log.h"

#include <SocketManager/socketmanager.h>

#include <indigo/assert.h>
#include <indigo/time.h>

#include <sys/select.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

static int init_done = 0;
static int module_enabled = 0;

/* Short hand logging macros */
#define LOG_ERROR AIM_LOG_ERROR
#define LOG_WARN AIM_LOG_WARN
#define LOG_INFO AIM_LOG_INFO
#define LOG_VERBOSE AIM_LOG_VERBOSE
#define LOG_TRACE AIM_LOG_TRACE

#define INVALID_SOCKET_ID -1

/* Maximum simultaneous sockets to support */
#define SOCKET_COUNT_MAX 1024
typedef struct soc_map_s {
    int socket_id;
    int data_out_ready;
    int data_in_paused;
    ind_soc_socket_ready_callback_f callback;
    void *cookie;
} soc_map_t;

/* Indexed by socket descriptor */
static soc_map_t soc_map[SOCKET_COUNT_MAX];
static int current_socket_id_max = 0; /* Highest index to check */

#define IS_ACTIVE_SOCKET_ID(_id) (soc_map[_id].socket_id == (_id))
#define IS_LEGAL_SOCKET_ID(_id) (((_id) >= 0) && ((_id) < SOCKET_COUNT_MAX))
#define DATA_OUT_READY(_id) (soc_map[_id].data_out_ready)
#define DATA_IN_PAUSED(_id) (soc_map[_id].data_in_paused)

#define FOREACH_ACTIVE_SOCKET_ID(_id)                       \
    for ((_id) = 0; (_id) < current_socket_id_max; (_id)++)     \
        if (IS_ACTIVE_SOCKET_ID(_id))

/*
 * Timer event structure
 * Lookup is (callback, cookie)
 */
typedef struct timer_event_s {
    ind_soc_timer_callback_f callback;
    void *cookie;
    int repeat_time_ms;
    indigo_time_t last_call;
} timer_event_t;

#define TIMER_EVENT_MAX 16
static timer_event_t timer_event[TIMER_EVENT_MAX];

#define TIMER_EVENT_VALID(idx) (timer_event[idx].callback != NULL)
#define TIMER_LAST(idx)

#define FOREACH_TIMER_EVENT(idx)                        \
    for ((idx) = 0; (idx) < TIMER_EVENT_MAX; (idx)++)   \
        if (TIMER_EVENT_VALID(idx))

/* Return index for timer; -1 if not found.  Use only with valid callback */
static int
timer_event_find(ind_soc_timer_callback_f callback, void *cookie)
{
    int idx;

    FOREACH_TIMER_EVENT(idx) {
        if ((timer_event[idx].callback == callback) &&
                (timer_event[idx].cookie == cookie)) {
            return idx;
        }
    }

    return -1;
}

/* Return index of first free timer slot */
static int
timer_event_free_slot(void)
{
    int idx;

    for (idx = 0; idx < TIMER_EVENT_MAX; idx++) {
        if (timer_event[idx].callback == NULL) {
            return idx;
        }
    }

    return -1;
}

static void
soc_mgr_init(void)
{
    int idx;
    for (idx = 0; idx < SOCKET_COUNT_MAX; idx++) {
        soc_map[idx].socket_id = INVALID_SOCKET_ID;
    }
    current_socket_id_max = 0;

    for (idx = 0; idx < TIMER_EVENT_MAX; idx++) {
        timer_event[idx].callback = NULL;
    }
}


indigo_error_t
ind_soc_socket_register(int socket_id,
                        ind_soc_socket_ready_callback_f callback,
                        void *cookie)
{
    LOG_VERBOSE("Register socket %d", socket_id);
    if (!IS_LEGAL_SOCKET_ID(socket_id)) {
        LOG_ERROR("Socket ID out of range: id %d", socket_id);
        return INDIGO_ERROR_PARAM;
    }

    if (callback == NULL) {
        LOG_ERROR("No callback specified");
        return INDIGO_ERROR_PARAM;
    }

    if (IS_ACTIVE_SOCKET_ID(socket_id)) {
        LOG_INFO("Socket %d exists", socket_id);
        return INDIGO_ERROR_EXISTS;
    }

    INDIGO_ASSERT(soc_map[socket_id].socket_id == INVALID_SOCKET_ID);
    soc_map[socket_id].socket_id = socket_id;
    soc_map[socket_id].callback = callback;
    soc_map[socket_id].cookie = cookie;

    if (current_socket_id_max <= socket_id) {
        current_socket_id_max = socket_id + 1;
    }

    return INDIGO_ERROR_NONE;
}


indigo_error_t
ind_soc_data_out_ready(int socket_id)
{
    if (!IS_LEGAL_SOCKET_ID(socket_id)) {
        LOG_ERROR("data_out_ready: Socket ID out of range: id %d", socket_id);
        return INDIGO_ERROR_PARAM;
    }

    if (!IS_ACTIVE_SOCKET_ID(socket_id)) {
        LOG_INFO("data_out_ready: Socket %d not registered", socket_id);
        return INDIGO_ERROR_PARAM;
    }

    soc_map[socket_id].data_out_ready = 1;

    return INDIGO_ERROR_NONE;
}

indigo_error_t
ind_soc_data_out_clear(int socket_id)
{
    if (!IS_LEGAL_SOCKET_ID(socket_id)) {
        LOG_ERROR("data_out_clear: Socket ID out of range: id %d", socket_id);
        return INDIGO_ERROR_PARAM;
    }

    if (!IS_ACTIVE_SOCKET_ID(socket_id)) {
        LOG_INFO("data_out_clear: Socket %d not registered", socket_id);
        return INDIGO_ERROR_PARAM;
    }

    soc_map[socket_id].data_out_ready = 0;

    return INDIGO_ERROR_NONE;
}

indigo_error_t
ind_soc_data_in_pause(int socket_id)
{
    if (!IS_LEGAL_SOCKET_ID(socket_id)) {
        LOG_ERROR("data_in_pause: Socket ID out of range: id %d", socket_id);
        return INDIGO_ERROR_PARAM;
    }

    if (!IS_ACTIVE_SOCKET_ID(socket_id)) {
        LOG_INFO("data_in_pause: Socket %d not registered", socket_id);
        return INDIGO_ERROR_PARAM;
    }

    soc_map[socket_id].data_in_paused = 1;

    return INDIGO_ERROR_NONE;
}

indigo_error_t
ind_soc_data_in_resume(int socket_id)
{
    if (!IS_LEGAL_SOCKET_ID(socket_id)) {
        LOG_ERROR("data_in_resume: Socket ID out of range: id %d", socket_id);
        return INDIGO_ERROR_PARAM;
    }

    if (!IS_ACTIVE_SOCKET_ID(socket_id)) {
        LOG_INFO("data_in_resume: Socket %d not registered", socket_id);
        return INDIGO_ERROR_PARAM;
    }

    soc_map[socket_id].data_in_paused = 0;

    return INDIGO_ERROR_NONE;
}

/*
 * Unregister a socket for processing by the socket manager
 */

indigo_error_t
ind_soc_socket_unregister(int socket_id)
{
    LOG_VERBOSE("Unregister socket %d", socket_id);

    if (!IS_LEGAL_SOCKET_ID(socket_id)) {
        LOG_INFO("unregister: Socket ID out of range: id %d", socket_id);
        return INDIGO_ERROR_PARAM;
    }

    soc_map[socket_id].socket_id = INVALID_SOCKET_ID;

    return INDIGO_ERROR_NONE;
}


static ind_soc_run_status_t ind_soc_run_status__;

void
ind_soc_run_status_set(ind_soc_run_status_t s)
{
    if(s < IND_SOC_RUN_STATUS_COUNT) {
        ind_soc_run_status__ = s;
    }
}




/*
 * Check timer events.  Return number of ms until next event or -1 if none.
 *
 * Returns ms to next event if any; -1 if no events.
 */
static int
check_timer_events(void)
{
    int idx;
    int next_ms = -1;
    indigo_time_t now;
    int elapsed;
    int tmp_ms;
    ind_soc_timer_callback_f callback;

    now = INDIGO_CURRENT_TIME;

    FOREACH_TIMER_EVENT(idx) {

        if(ind_soc_run_status__ == IND_SOC_RUN_STATUS_EXIT) {
            return 0;
        }

        elapsed = INDIGO_TIME_DIFF_ms(timer_event[idx].last_call, now);
        tmp_ms = timer_event[idx].repeat_time_ms - elapsed; /* Time to next */
        if (tmp_ms <= 0) {
            timer_event[idx].last_call = now;

            /* The callback may change its registration, so need to track
             * current value if this is one-shot.
             */

            callback = timer_event[idx].callback;
            if (timer_event[idx].repeat_time_ms == IND_SOC_TIMER_IMMEDIATE) {
                /* De-register one-shot immediate timers */
                timer_event[idx].callback = NULL;
            }

            callback(timer_event[idx].cookie);
            /* If not de-registered by callback or one-shot, reschedule */
            if (timer_event[idx].callback != NULL) {
                tmp_ms = timer_event[idx].repeat_time_ms;
            } else {
                tmp_ms = -1;
            }
        }
        if ((next_ms == -1) || ((tmp_ms > 0) && (tmp_ms < next_ms))) {
            next_ms = tmp_ms;
        }
    }

    return next_ms;
}

indigo_error_t
ind_soc_timer_event_register(ind_soc_timer_callback_f callback, void *cookie,
                             int repeat_time_ms)
{
    int idx;

    if (callback == NULL) {
        LOG_ERROR("Null callback for timer register");
        return INDIGO_ERROR_PARAM;
    }
    if (repeat_time_ms <= 0) {
        LOG_ERROR("Invalid repeat time for timer register: %d", repeat_time_ms);
        return INDIGO_ERROR_PARAM;
    }
    /* Allow re-registering which resets the timer */
    if ((idx = timer_event_find(callback, cookie)) >= 0) {
        LOG_TRACE("Resetting event timer for %p to %d", callback, repeat_time_ms);
        timer_event[idx].repeat_time_ms = repeat_time_ms;
        timer_event[idx].last_call = INDIGO_CURRENT_TIME;
        return INDIGO_ERROR_NONE;
    }
    if ((idx = timer_event_free_slot()) < 0) {
        LOG_ERROR("No space for timer event %p, %p", callback, cookie);
        return INDIGO_ERROR_RESOURCE;
    }

    timer_event[idx].repeat_time_ms = repeat_time_ms;
    timer_event[idx].callback = callback;
    timer_event[idx].cookie = cookie;
    timer_event[idx].last_call = INDIGO_CURRENT_TIME;

    return INDIGO_ERROR_NONE;
}

indigo_error_t
ind_soc_timer_event_unregister(ind_soc_timer_callback_f callback, void *cookie)
{
    int idx;

    if ((idx = timer_event_find(callback, cookie)) < 0) {
        LOG_TRACE("Timer event %p, %p not found for unregister",
                  callback, cookie);
        return INDIGO_ERROR_NOT_FOUND;
    }

    timer_event[idx].callback = NULL;

    return INDIGO_ERROR_NONE;
}

/*
 * Find the next timeout based on the next timer event and the timeout passed
 * to the original run call
 * @param timeout (out) Structure to fill out
 * @param start The time when select_and_run was called
 * @param current The current time
 * @param passed_ms The run_for_ms passed to select_and_run
 * @param next_event_ms The ms until the next timer event
 * @returns pointer to timeout parameter if timeout applies
 * @returns NULL if no timeout
 */

static struct timeval *
calculate_next_timeout(struct timeval *timeout, indigo_time_t start,
                       indigo_time_t current, int run_for_ms, int next_event_ms)
{
    int min_val;
    int remaining_ms;

    /* Take min of positive values of next_event_ms and run_for_ms */

    /* If neither is positive, return NULL (no timeout) */
    if ((run_for_ms < 0) && (next_event_ms < 0)) {
        return NULL;
    }

    if (run_for_ms >= 0) {
        remaining_ms = run_for_ms - INDIGO_TIME_DIFF_ms(start, current);
        if (remaining_ms < 0) {
            remaining_ms = 0;
        }
        if (next_event_ms >= 0) {
            min_val = remaining_ms < next_event_ms ? run_for_ms : next_event_ms;
        } else {
            min_val = remaining_ms;
        }
    } else { /* next_event_ms must be >= 0 */
        min_val = next_event_ms;
    }

    timeout->tv_sec = min_val / 1000;
    timeout->tv_usec = (min_val % 1000) * 1000;

    return timeout;
}


indigo_error_t
ind_soc_init(ind_soc_config_t *config)
{
    LOG_INFO("Initializing socket manager");

    soc_mgr_init();
    init_done = 1;
    (void)config;

    return INDIGO_ERROR_NONE;
}


indigo_error_t
ind_soc_enable_set(int enable)
{
    LOG_TRACE("OF socket mgr enable called");

    if (enable && !module_enabled) {
        LOG_INFO("Enabling OF socket mgr");
        module_enabled = 1;
    } else if (!enable && module_enabled) {
        LOG_INFO("Disabling OF socket mgr");
        module_enabled = 0;
    } else {
        LOG_VERBOSE("Redundant enable call.  Currently %s",
                    module_enabled ? "enabled" : "disabled");
    }

    return INDIGO_ERROR_NONE;
}


indigo_error_t
ind_soc_enable_get(int *enable)
{
    if (enable == NULL) {
        return INDIGO_ERROR_PARAM;
    }
    *enable = module_enabled;

    return INDIGO_ERROR_NONE;
}


indigo_error_t
ind_soc_finish(void)
{
    LOG_INFO("Shutting down socket manager");
    soc_mgr_init();
    init_done = 0;

    return INDIGO_ERROR_NONE;
}


/*
 * Run timer events, select and make callbacks for sockets marked ready
 *
 * If timeout < 0, block indefinitely; if timeout == 0, poll.
 */

int
ind_soc_select_and_run(int run_for_ms)
{
    fd_set read_sds;
    fd_set write_sds;
    fd_set error_sds;
    int num_sds = 0;
    struct timeval timeout = {0, 0};
    struct timeval *timeout_p = NULL;
    int rv;
    int sd;
    int read_ready, write_ready, error_seen;
    indigo_time_t start, current;
    int elapsed;
    int next_event_ms;

    ind_soc_run_status_set(IND_SOC_RUN_STATUS_OK);

    start = INDIGO_CURRENT_TIME;

    do {
        next_event_ms = check_timer_events();

        if(ind_soc_run_status__ == IND_SOC_RUN_STATUS_EXIT) {
            return INDIGO_ERROR_NONE;
        }

        current = INDIGO_CURRENT_TIME;
        timeout_p = calculate_next_timeout(&timeout, start, current,
                                           run_for_ms, next_event_ms);

        /* Form the select sets */
        FD_ZERO(&read_sds);
        FD_ZERO(&write_sds);
        FD_ZERO(&error_sds);

        num_sds = 0;
        FOREACH_ACTIVE_SOCKET_ID(sd) {
            if (!DATA_IN_PAUSED(sd)) {
                FD_SET(sd, &read_sds);
            }
            FD_SET(sd, &error_sds);
            if (DATA_OUT_READY(sd)) {
                FD_SET(sd, &write_sds);
            }
            if (sd >= num_sds) {
                num_sds = sd + 1;
            }
        }

        if (num_sds == 0) {
            if (next_event_ms < 0) {
                LOG_VERBOSE("No sockets, no next event");
                return INDIGO_ERROR_NOT_FOUND;
            }
            LOG_TRACE("Sleeping for %d ms", next_event_ms);
            usleep(next_event_ms * 1000);
        } else {
            LOG_TRACE("Calling select: timeout %d s %d us",
                      (int)(timeout_p ? timeout_p->tv_sec : -1),
                      (int)(timeout_p ? timeout_p->tv_usec : -1));
            rv = select(num_sds, &read_sds, &write_sds, &error_sds, timeout_p);
            LOG_TRACE("Select returned %d", rv);

            if (rv < 0 && errno != EINTR) {
                LOG_ERROR("Error in select: %s", strerror(errno));
                return INDIGO_ERROR_UNKNOWN;
            }

            if (rv > 0) {
                FOREACH_ACTIVE_SOCKET_ID(sd) {

                    if(ind_soc_run_status__ == IND_SOC_RUN_STATUS_EXIT) {
                        return INDIGO_ERROR_NONE;
                    }

                    read_ready = FD_ISSET(sd, &read_sds);
                    write_ready = FD_ISSET(sd, &write_sds);
                    error_seen = FD_ISSET(sd, &error_sds);
                    if (read_ready || write_ready || error_seen) {
                        soc_map[sd].callback(sd, soc_map[sd].cookie,
                                             read_ready, write_ready, error_seen);

                    }
                }
            }
        }
        current = INDIGO_CURRENT_TIME;
        elapsed = INDIGO_TIME_DIFF_ms(start, current);
    } while ((run_for_ms < 0) || ((run_for_ms > 0) && (elapsed < run_for_ms)));

    return INDIGO_ERROR_NONE;
}

