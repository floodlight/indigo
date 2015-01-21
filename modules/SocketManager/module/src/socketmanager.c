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
 * SocketManager implements a fixed priority scheduler. Higher priority events
 * (timer or socket) are processed before lower priority events. Events with
 * the same priority are processed round-robin. Each iteration of the event
 * loop processes one priority level before polling for potential new high
 * priority events.
 *
 * @todo Make the max socket ID supported a parameter to the module
 * @todo Make the max timer events supported a parameter to the module
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
#include "socketmanager_int.h"

#include <SocketManager/socketmanager.h>
#include <Configuration/configuration.h>

#include <indigo/assert.h>
#include <indigo/time.h>
#include <indigo/memory.h>
#include <AIM/aim_list.h>
#include <timer_wheel/timer_wheel.h>

#include <poll.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <limits.h>

static void before_callback(void);
static void after_callback(void);

static int init_done = 0;
static int module_enabled = 0;

#define INVALID_SOCKET_ID -1

typedef struct soc_map_s {
    short socket_id;
    uint16_t pollfd_index;
    ind_soc_priority_t priority;
    ind_soc_socket_ready_callback_f callback;
    void *cookie;
} soc_map_t;

/* Indexed by socket descriptor */
static soc_map_t soc_map[SOCKETMANAGER_CONFIG_MAX_SOCKETS];

/* Dense array passed to poll(2) */
static struct pollfd pollfds[SOCKETMANAGER_CONFIG_MAX_SOCKETS];
static int num_pollfds = 0;

#define IS_ACTIVE_SOCKET_ID(_id) (soc_map[_id].socket_id == (_id))
#define IS_LEGAL_SOCKET_ID(_id) (((_id) >= 0) && ((_id) < SOCKETMANAGER_CONFIG_MAX_SOCKETS))
#define POLLFD_INDEX(_id) soc_map[(_id)].pollfd_index

enum timer_state {
    TIMER_STATE_FREE,
    TIMER_STATE_WAITING,
    TIMER_STATE_READY,
};

/*
 * Timer event structure
 * Lookup is (callback, cookie)
 */
typedef struct timer_event_s {
    enum timer_state state;
    /*
     * The timer can either be waiting in the timer wheel, or
     * ready in the ready list, but not at the same time.
     */
    union {
        timer_wheel_entry_t timer_wheel_entry; /* valid when state == WAITING */
        list_links_t ready_links; /* valid when state == READY */
    };
    ind_soc_timer_callback_f callback;
    void *cookie;
    int repeat_time_ms;
    ind_soc_priority_t priority;
} timer_event_t;

static timer_event_t timer_event[SOCKETMANAGER_CONFIG_MAX_TIMERS];
static timer_wheel_t *timer_wheel;
static list_head_t ready_timers; /* contains timer_event_t through ready_links */

#define TIMER_EVENT_VALID(idx) (timer_event[idx].callback != NULL)

#define FOREACH_TIMER_EVENT(idx)                        \
    for ((idx) = 0; (idx) < SOCKETMANAGER_CONFIG_MAX_TIMERS; (idx)++)   \
        if (TIMER_EVENT_VALID(idx))

/*
 * Task structure
 */
typedef struct ind_soc_task_s {
    list_links_t links; /* global tasks */
    ind_soc_task_callback_f callback;
    void *cookie;
    ind_soc_priority_t priority;
} ind_soc_task_t;

/* Sorted in descending priority order */
static list_head_t tasks;


/* Return index for timer; -1 if not found.  Use only with valid callback */
static int
timer_event_find(ind_soc_timer_callback_f callback, void *cookie)
{
    int idx;

    FOREACH_TIMER_EVENT(idx) {
        if ((timer_event[idx].state != TIMER_STATE_FREE) &&
                (timer_event[idx].callback == callback) &&
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

    for (idx = 0; idx < SOCKETMANAGER_CONFIG_MAX_TIMERS; idx++) {
        if (timer_event[idx].state == TIMER_STATE_FREE) {
            return idx;
        }
    }

    return -1;
}

static void
soc_mgr_init(void)
{
    int idx;
    for (idx = 0; idx < SOCKETMANAGER_CONFIG_MAX_SOCKETS; idx++) {
        soc_map[idx].socket_id = INVALID_SOCKET_ID;
    }

    for (idx = 0; idx < SOCKETMANAGER_CONFIG_MAX_TIMERS; idx++) {
        timer_event[idx].state = TIMER_STATE_FREE;
    }

    list_init(&tasks);
    list_init(&ready_timers);
}


indigo_error_t
ind_soc_socket_register_with_priority(int socket_id,
                                      ind_soc_socket_ready_callback_f callback,
                                      void *cookie,
                                      ind_soc_priority_t priority)
{
    struct pollfd *pfd;

    AIM_ASSERT(priority >= IND_SOC_LOWEST_PRIORITY &&
               priority <= IND_SOC_HIGHEST_PRIORITY);

    AIM_LOG_VERBOSE("Register socket %d", socket_id);
    if (!IS_LEGAL_SOCKET_ID(socket_id)) {
        AIM_LOG_INTERNAL("Socket ID out of range: id %d", socket_id);
        return INDIGO_ERROR_PARAM;
    }

    if (callback == NULL) {
        AIM_LOG_INTERNAL("No callback specified");
        return INDIGO_ERROR_PARAM;
    }

    if (IS_ACTIVE_SOCKET_ID(socket_id)) {
        AIM_LOG_INTERNAL("Socket %d exists", socket_id);
        return INDIGO_ERROR_EXISTS;
    }

    INDIGO_ASSERT(soc_map[socket_id].socket_id == INVALID_SOCKET_ID);
    soc_map[socket_id].socket_id = socket_id;
    soc_map[socket_id].pollfd_index = num_pollfds;
    soc_map[socket_id].callback = callback;
    soc_map[socket_id].cookie = cookie;
    soc_map[socket_id].priority = priority;

    INDIGO_ASSERT(num_pollfds < SOCKETMANAGER_CONFIG_MAX_SOCKETS);
    pfd = &pollfds[num_pollfds++];
    pfd->fd = socket_id;
    pfd->events = POLLIN;
    pfd->revents = 0;

    return INDIGO_ERROR_NONE;
}

indigo_error_t
ind_soc_socket_register(int socket_id,
                        ind_soc_socket_ready_callback_f callback,
                        void *cookie)
{
    return ind_soc_socket_register_with_priority(
        socket_id, callback, cookie, IND_SOC_NORMAL_PRIORITY);
}

indigo_error_t
ind_soc_data_out_ready(int socket_id)
{
    if (!IS_LEGAL_SOCKET_ID(socket_id)) {
        AIM_LOG_INTERNAL("data_out_ready: Socket ID out of range: id %d", socket_id);
        return INDIGO_ERROR_PARAM;
    }

    if (!IS_ACTIVE_SOCKET_ID(socket_id)) {
        AIM_LOG_INTERNAL("data_out_ready: Socket %d not registered", socket_id);
        return INDIGO_ERROR_PARAM;
    }

    pollfds[POLLFD_INDEX(socket_id)].events |= POLLOUT;

    return INDIGO_ERROR_NONE;
}

indigo_error_t
ind_soc_data_out_clear(int socket_id)
{
    if (!IS_LEGAL_SOCKET_ID(socket_id)) {
        AIM_LOG_INTERNAL("data_out_clear: Socket ID out of range: id %d", socket_id);
        return INDIGO_ERROR_PARAM;
    }

    if (!IS_ACTIVE_SOCKET_ID(socket_id)) {
        AIM_LOG_INTERNAL("data_out_clear: Socket %d not registered", socket_id);
        return INDIGO_ERROR_PARAM;
    }

    pollfds[POLLFD_INDEX(socket_id)].events &= ~POLLOUT;

    return INDIGO_ERROR_NONE;
}

indigo_error_t
ind_soc_data_in_pause(int socket_id)
{
    if (!IS_LEGAL_SOCKET_ID(socket_id)) {
        AIM_LOG_INTERNAL("data_in_pause: Socket ID out of range: id %d", socket_id);
        return INDIGO_ERROR_PARAM;
    }

    if (!IS_ACTIVE_SOCKET_ID(socket_id)) {
        AIM_LOG_INTERNAL("data_in_pause: Socket %d not registered", socket_id);
        return INDIGO_ERROR_PARAM;
    }

    pollfds[POLLFD_INDEX(socket_id)].events &= ~POLLIN;

    return INDIGO_ERROR_NONE;
}

indigo_error_t
ind_soc_data_in_resume(int socket_id)
{
    if (!IS_LEGAL_SOCKET_ID(socket_id)) {
        AIM_LOG_INTERNAL("data_in_resume: Socket ID out of range: id %d", socket_id);
        return INDIGO_ERROR_PARAM;
    }

    if (!IS_ACTIVE_SOCKET_ID(socket_id)) {
        AIM_LOG_INTERNAL("data_in_resume: Socket %d not registered", socket_id);
        return INDIGO_ERROR_PARAM;
    }

    pollfds[POLLFD_INDEX(socket_id)].events |= POLLIN;

    return INDIGO_ERROR_NONE;
}

/*
 * Unregister a socket for processing by the socket manager
 */

indigo_error_t
ind_soc_socket_unregister(int socket_id)
{
    AIM_LOG_VERBOSE("Unregister socket %d", socket_id);

    if (!IS_LEGAL_SOCKET_ID(socket_id)) {
        AIM_LOG_INTERNAL("unregister: Socket ID out of range: id %d", socket_id);
        return INDIGO_ERROR_PARAM;
    }

    if (!IS_ACTIVE_SOCKET_ID(socket_id)) {
        AIM_LOG_INTERNAL("socket_unregister: Socket %d not registered", socket_id);
        return INDIGO_ERROR_PARAM;
    }

    /*
     * Need to maintain the dense property of the pollfds array.
     * Move the element at the end to the index being freed.
     */
    INDIGO_ASSERT(num_pollfds > 0);
    if (num_pollfds > 1) {
        int dst_index = POLLFD_INDEX(socket_id);
        struct pollfd *src_pfd = &pollfds[num_pollfds-1];
        struct pollfd *dst_pfd = &pollfds[dst_index];
        if (src_pfd != dst_pfd) {
            soc_map[src_pfd->fd].pollfd_index = dst_index;
            *dst_pfd = *src_pfd;
        }
    }

    num_pollfds--;

    memset(&soc_map[socket_id], 0, sizeof(soc_map_t));
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
 * Return the time in ms until the next timer fires, or -1 if no timers
 * are active.
 */
static int
find_next_timer_expiration(indigo_time_t now)
{
    if (!list_empty(&ready_timers)) {
        return 0;
    }

    timer_wheel_entry_t *entry =
        timer_wheel_peek(timer_wheel, now + SOCKETMANAGER_CONFIG_TIMER_PEEK_MS);
    if (entry) {
        return entry->deadline - now;
    }

    return -1;
}

/* Pull expired timers off the timer wheel and add them to the ready list */
static void
find_ready_timers(indigo_time_t now)
{
   timer_wheel_entry_t *entry;

   while ((entry = timer_wheel_next(timer_wheel, now)) != NULL) {
       timer_event_t *timer = container_of(entry, timer_wheel_entry, timer_event_t);
       list_push(&ready_timers, &timer->ready_links);
       timer->state = TIMER_STATE_READY;
   }
}

/*
 * Run callbacks for timer events.
 *
 * The ready list is treated as a queue to allow timer callbacks to arbitrarily
 * unregister themselves or other timers. The slight difficulty is that
 * timers with a different priority level need to remain on the ready list. Doing
 * this while treating the ready list as a queue requires a temporary list.
 *
 * A timer in the READY state may be either on the ready list or the temporary
 * list. In either case, the list_remove in ind_soc_timer_event_unregister will
 * remove it from the correct list.
 */
static void
process_timers(ind_soc_priority_t priority)
{
    indigo_time_t now;
    ind_soc_timer_callback_f callback;
    void *cookie;
    list_head_t tmp_list;

    list_move(&ready_timers, &tmp_list);
    now = INDIGO_CURRENT_TIME;

    while (!list_empty(&tmp_list)) {
        timer_event_t *timer = container_of(list_shift(&tmp_list), ready_links, timer_event_t);
        AIM_ASSERT(timer->state == TIMER_STATE_READY);

        list_remove(&timer->ready_links);

        if (timer->priority != priority) {
            /* Not processing this priority, add it back to the ready list */
            list_push(&ready_timers, &timer->ready_links);
            continue;
        }

        /* The callback may change its registration, so need to track
         * current value if this is one-shot.
         */

        callback = timer->callback;
        cookie = timer->cookie;
        if (timer->repeat_time_ms == IND_SOC_TIMER_IMMEDIATE) {
            /* De-register one-shot immediate timers */
            timer->state = TIMER_STATE_FREE;
        } else {
            timer_wheel_insert(timer_wheel, &timer->timer_wheel_entry,
                               now + timer->repeat_time_ms);
            timer->state = TIMER_STATE_WAITING;
        }


        before_callback();
        callback(cookie);
        after_callback();
    }
}

indigo_error_t
ind_soc_timer_event_register_with_priority(
    ind_soc_timer_callback_f callback, void *cookie,
    int repeat_time_ms, ind_soc_priority_t priority)
{
    int idx;

    AIM_ASSERT(priority >= IND_SOC_LOWEST_PRIORITY &&
               priority <= IND_SOC_HIGHEST_PRIORITY);

    if (callback == NULL) {
        AIM_LOG_INTERNAL("Null callback for timer register");
        return INDIGO_ERROR_PARAM;
    }
    if (repeat_time_ms < 0) {
        AIM_LOG_INTERNAL("Invalid repeat time for timer register: %d", repeat_time_ms);
        return INDIGO_ERROR_PARAM;
    }
    /* Allow re-registering which resets the timer */
    if ((idx = timer_event_find(callback, cookie)) >= 0) {
        AIM_LOG_TRACE("Resetting event timer for %p to %d", callback, repeat_time_ms);
        if (timer_event[idx].state == TIMER_STATE_READY) {
            list_remove(&timer_event[idx].ready_links);
        } else if (timer_event[idx].state == TIMER_STATE_WAITING) {
            timer_wheel_remove(timer_wheel, &timer_event[idx].timer_wheel_entry);
        }
        timer_event[idx].repeat_time_ms = repeat_time_ms;
        timer_event[idx].state = TIMER_STATE_WAITING;
        timer_wheel_insert(timer_wheel, &timer_event[idx].timer_wheel_entry,
                           INDIGO_CURRENT_TIME + repeat_time_ms);
        return INDIGO_ERROR_NONE;
    }
    if ((idx = timer_event_free_slot()) < 0) {
        AIM_LOG_ERROR("Failed to register timer, exceeded maximum of %d",
                      SOCKETMANAGER_CONFIG_MAX_TIMERS);
        return INDIGO_ERROR_RESOURCE;
    }

    timer_event[idx].repeat_time_ms = repeat_time_ms;
    timer_event[idx].callback = callback;
    timer_event[idx].cookie = cookie;
    timer_event[idx].priority = priority;
    timer_wheel_insert(timer_wheel, &timer_event[idx].timer_wheel_entry,
                       INDIGO_CURRENT_TIME + repeat_time_ms);
    timer_event[idx].state = TIMER_STATE_WAITING;

    return INDIGO_ERROR_NONE;
}

indigo_error_t
ind_soc_timer_event_register(
    ind_soc_timer_callback_f callback, void *cookie,
    int repeat_time_ms)
{
    return ind_soc_timer_event_register_with_priority(
        callback, cookie, repeat_time_ms, IND_SOC_NORMAL_PRIORITY);
}

indigo_error_t
ind_soc_timer_event_unregister(ind_soc_timer_callback_f callback, void *cookie)
{
    int idx;

    if ((idx = timer_event_find(callback, cookie)) < 0) {
        AIM_LOG_TRACE("Timer event %p, %p not found for unregister",
                      callback, cookie);
        return INDIGO_ERROR_NOT_FOUND;
    }

    if (timer_event[idx].state == TIMER_STATE_READY) {
        list_remove(&timer_event[idx].ready_links);
    } else if (timer_event[idx].state == TIMER_STATE_WAITING) {
        timer_wheel_remove(timer_wheel, &timer_event[idx].timer_wheel_entry);
    }

    timer_event[idx].state = TIMER_STATE_FREE;

    return INDIGO_ERROR_NONE;
}

/*
 * Find the next timeout based on the next timer event and the timeout passed
 * to the original run call
 * @param start The time when select_and_run was called
 * @param current The current time
 * @param passed_ms The run_for_ms passed to select_and_run
 * @param next_event_ms The ms until the next timer event
 * @returns timeout in milliseconds, or -1 if no timeout
 */

static int
calculate_next_timeout(indigo_time_t start, indigo_time_t current,
                       int run_for_ms, int next_event_ms)
{
    int min_val;
    int remaining_ms;

    /* Take min of positive values of next_event_ms and run_for_ms */

    /* If neither is positive, return -1 (no timeout) */
    if ((run_for_ms < 0) && (next_event_ms < 0)) {
        return -1;
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

    return min_val;
}


indigo_error_t
ind_soc_task_register(ind_soc_task_callback_f callback,
                      void *cookie, ind_soc_priority_t priority)
{
    list_links_t *cur;

    AIM_ASSERT(priority >= IND_SOC_LOWEST_PRIORITY &&
               priority <= IND_SOC_HIGHEST_PRIORITY);

    ind_soc_task_t *task = aim_malloc(sizeof(*task));
    task->callback = callback;
    task->cookie = cookie;
    task->priority = priority;

    /* Maintain descending priority order */
    LIST_FOREACH(&tasks, cur) {
        ind_soc_task_t *cur_task = container_of(cur, links, ind_soc_task_t);
        if (cur_task->priority <= priority) {
            break;
        }
    }

    /*
     * If we're inserting the new lowest priority task then cur will be left
     * pointing to the list head. Otherwise it points to the first task with
     * lower priority. In both cases we insert the new task before cur.
     */
    list_insert_before(cur, &task->links);

    return INDIGO_ERROR_NONE;
}


indigo_error_t
ind_soc_init(ind_soc_config_t *config)
{
    AIM_LOG_VERBOSE("Initializing socket manager");

    ind_cfg_register(&ind_soc_cfg_ops);

    soc_mgr_init();

    timer_wheel = timer_wheel_create(SOCKETMANAGER_CONFIG_MAX_TIMERS,
                                     SOCKETMANAGER_CONFIG_TIMER_GRANULARITY_MS,
                                     INDIGO_CURRENT_TIME);

    init_done = 1;
    (void)config;

    return INDIGO_ERROR_NONE;
}


indigo_error_t
ind_soc_enable_set(int enable)
{
    AIM_LOG_TRACE("OF socket mgr enable called");

    if (enable && !module_enabled) {
        AIM_LOG_VERBOSE("Enabling OF socket mgr");
        module_enabled = 1;
    } else if (!enable && module_enabled) {
        AIM_LOG_VERBOSE("Disabling OF socket mgr");
        module_enabled = 0;
    } else {
        AIM_LOG_VERBOSE("Redundant enable call.  Currently %s",
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
    AIM_LOG_VERBOSE("Shutting down socket manager");
    soc_mgr_init();
    timer_wheel_destroy(timer_wheel);
    timer_wheel = NULL;
    init_done = 0;

    return INDIGO_ERROR_NONE;
}

/* Time since the current callback started */
static indigo_time_t callback_start_time;

static void
before_callback(void)
{
    callback_start_time = INDIGO_CURRENT_TIME;
}

static void
after_callback(void)
{
    indigo_time_t elapsed =
        INDIGO_TIME_DIFF_ms(callback_start_time, INDIGO_CURRENT_TIME);
    if (elapsed >= SOCKETMANAGER_CONFIG_TIMESLICE_MS * 2) {
        AIM_LOG_VERBOSE("Callback exceeded 2x timeslice (ran for %d ms, timeslice is %d ms)",
                        (int)elapsed, SOCKETMANAGER_CONFIG_TIMESLICE_MS);
    }
}

int
ind_soc_should_yield(void)
{
    indigo_time_t elapsed =
        INDIGO_TIME_DIFF_ms(callback_start_time, INDIGO_CURRENT_TIME);
    return elapsed >= SOCKETMANAGER_CONFIG_TIMESLICE_MS;
}

/*
 * Run callbacks for each ready socket.
 */
static void
process_sockets(ind_soc_priority_t priority)
{
    int i;
    for (i = 0; i < num_pollfds; i++) {
        struct pollfd *pfd = &pollfds[i];
        int read_ready, write_ready, error_seen;

        if (ind_soc_run_status__ == IND_SOC_RUN_STATUS_EXIT) {
            break;
        }

        if (soc_map[pfd->fd].priority != priority) {
            continue;
        }

        read_ready = (pfd->revents & POLLIN) != 0;
        write_ready = (pfd->revents & POLLOUT) != 0;
        error_seen = (pfd->revents & POLLERR) != 0;
        if (read_ready || write_ready || error_seen) {
            before_callback();
            soc_map[pfd->fd].callback(pfd->fd, soc_map[pfd->fd].cookie,
                    read_ready, write_ready, error_seen);
            after_callback();
        }
    }
}

/*
 * Run callbacks for each task.
 */
static void
process_tasks(ind_soc_priority_t priority)
{
    struct list_links *cur, *next;
    LIST_FOREACH_SAFE(&tasks, cur, next) {
        ind_soc_task_t *task = container_of(cur, links, ind_soc_task_t);
        if (task->priority < priority) {
            break;
        }
        before_callback();
        if (task->callback(task->cookie) == IND_SOC_TASK_FINISHED) {
            list_remove(&task->links);
            aim_free(task);
        }
        after_callback();
    }
}

/*
 * This function returns the priority level the event loop should process
 * on the current iteration. It assumes poll() has been called on the global
 * pollfds array.
 */
static int
find_highest_ready_priority(void)
{
    int idx;
    ind_soc_priority_t priority = IND_SOC_LOWEST_PRIORITY;
    list_links_t *cur;

    for (idx = 0; idx < num_pollfds; idx++) {
        struct pollfd *pfd = &pollfds[idx];

        if (pfd->revents == 0) {
            continue;
        }

        priority = aim_imax(priority, soc_map[pfd->fd].priority);
    }

    LIST_FOREACH(&ready_timers, cur) {
        timer_event_t *timer = container_of(cur, ready_links, timer_event_t);
        priority = aim_imax(priority, timer->priority);
    }

    if (!list_empty(&tasks)) {
        ind_soc_task_t *task = container_of(tasks.links.next, links, ind_soc_task_t);
        priority = aim_imax(priority, task->priority);
    }

    return priority;
}

/*
 * Run timer events, select and make callbacks for sockets marked ready
 *
 * If timeout < 0, block indefinitely; if timeout == 0, poll.
 */

int
ind_soc_select_and_run(int run_for_ms)
{
    int rv;
    indigo_time_t start, current;
    int elapsed;
    int next_timer_ms, timeout_ms;
    ind_soc_priority_t priority;

    ind_soc_run_status_set(IND_SOC_RUN_STATUS_OK);

    current = start = INDIGO_CURRENT_TIME;

    do {
        find_ready_timers(current);

        if (list_empty(&tasks)) {
            next_timer_ms = find_next_timer_expiration(current);
        } else {
            /* Do not sleep if a task is ready */
            next_timer_ms = 0;
        }

        timeout_ms = calculate_next_timeout(start, current,
                                            run_for_ms, next_timer_ms);

        AIM_LOG_TRACE("polling %d fds, timeout %d ms", num_pollfds, timeout_ms);
        rv = poll(pollfds, num_pollfds, timeout_ms);
        AIM_LOG_TRACE("poll returned %d", rv);

        if (rv < 0 && errno != EINTR) {
            AIM_LOG_ERROR("Error in poll: %s", strerror(errno));
            return INDIGO_ERROR_UNKNOWN;
        }

        priority = find_highest_ready_priority();
        AIM_LOG_TRACE("processing priority %d", priority);

        process_sockets(priority);
        process_timers(priority);
        process_tasks(priority);

        if (ind_soc_run_status__ == IND_SOC_RUN_STATUS_EXIT) {
            return INDIGO_ERROR_NONE;
        }

        current = INDIGO_CURRENT_TIME;
        elapsed = INDIGO_TIME_DIFF_ms(start, current);
    } while ((run_for_ms < 0) || ((run_for_ms > 0) && (elapsed < run_for_ms)));

    return INDIGO_ERROR_NONE;
}


/* utility functions for unit test only */
int
unit_test_soc_timer_event_count_get(void)
{
    int idx;
    int count = 0;

    FOREACH_TIMER_EVENT(idx) {
        AIM_LOG_VERBOSE("timer %d callback %p state %d", 
                        idx, timer_event[idx].callback, 
                        timer_event[idx].state);
        if (timer_event[idx].state != TIMER_STATE_FREE) {
            count++;
        }
    }

    return count;
}

int
unit_test_soc_socket_count_get(void)
{
    int idx;
    int count = 0;

    for (idx = 0; idx < SOCKETMANAGER_CONFIG_MAX_SOCKETS; idx++) {
        if (IS_ACTIVE_SOCKET_ID(idx)) {
            count++;
        }
    }

    return count;
}

