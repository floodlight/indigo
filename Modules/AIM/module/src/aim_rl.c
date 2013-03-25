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
 *****************************************************************************/
#include <AIM/aim_config.h>
#include <AIM/aim_rl.h>
#include "aim_int.h"
#include "aim_util.h"

void
aim_ratelimiter_init(aim_ratelimiter_t* rl, uint32_t interval,
                     uint32_t burst, aim_ratelimiter_monotonic_f monotonic)
{
    if(rl) {
        AIM_MEMSET(rl, 0, sizeof(*rl));
        rl->interval = interval;
        rl->burst = burst;
        rl->empty_time = 0;
        rl->monotonic = monotonic;
    }
}

int
aim_ratelimiter_limit(aim_ratelimiter_t* rl, uint64_t current_time)
{
    if(rl) {
        if(current_time == 0 && rl->monotonic) {
            current_time = rl->monotonic();
        }
        if (current_time < aim_ratelimiter_next_allowed_time(rl)) {
            return -1;
        }
        if (rl->empty_time < current_time) {
            rl->empty_time = current_time;
        }
        rl->empty_time += rl->interval;

        return 0;
    }
    return -1;
}

uint64_t
aim_ratelimiter_next_allowed_time(aim_ratelimiter_t* rl)
{
    if(rl) {
        uint64_t burst_time = rl->burst * rl->interval;
        /* Avoid integer underflow */
        if (rl->empty_time < burst_time) {
            return 0;
        } else {
            return rl->empty_time - burst_time;
        }
    }
    return 0;
}
