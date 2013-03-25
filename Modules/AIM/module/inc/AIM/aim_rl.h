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
 * @brief AIM Rate Limiters
 *
 *
 * @addtogroup aim-rl
 * @{
 *
 *****************************************************************************/
#ifndef __AIM_RL_H__
#define __AIM_RL_H__

#include <AIM/aim_config.h>
#include <AIM/aim_valist.h>
#include <AIM/aim_pvs.h>
#include <AIM/aim_utils.h>

/*
 * This rate limiter implementation is provided
 * to support rate-limited logging.
 */


/**
 * Optional function returning monotonic time.
 */
typedef uint64_t (*aim_ratelimiter_monotonic_f)(void);

/**
 * Ratelimiter object.
 */
typedef struct aim_ratelimiter_s {
    /** Averate time units per event (inverse of the rate) */
    uint32_t interval;
    /** Depth of bucket. */
    uint32_t burst;
    /** Time in the future the bucket will become empty. */
    uint64_t empty_time;
    /** monotonic timer (optional) */
    aim_ratelimiter_monotonic_f monotonic;

} aim_ratelimiter_t;


/**
 * @brief Initialize an AIM ratelimiter.
 * @param rl Pointer to the AIM ratelimiter structure.
 * @param interval The interval.
 * @param burst The burst size
 * @param monotonic Optional timer function.
 * @note If you don't specify the timer, you must always pass the current
 * time to the ratelimiter functions.
 */
void aim_ratelimiter_init(aim_ratelimiter_t* rl, uint32_t interval,
                          uint32_t burst, aim_ratelimiter_monotonic_f monotonic);

/**
 * @brief Rate limit check.
 * @param rl Pointer to the AIM ratelimiter structure.
 * @param current_time The current time.
 * @returns -1 if the limit has been reached.
 * @returns 0  if the limit has not been reached.
 * @note You can specify 0 as the current_time if you
 * configured the optional monotonic function.
 */
int aim_ratelimiter_limit(aim_ratelimiter_t* rl, uint64_t current_time);

/**
 * @brief Returns the next time an event will be allowed.
 * @param rl Poniter to the AIM ratelimiter structure.
 * @returns The next allowable event time using this limiter.
 */
uint64_t aim_ratelimiter_next_allowed_time(aim_ratelimiter_t* rl);


#endif /* __AIM_RL_H__ */

/* @}*/
