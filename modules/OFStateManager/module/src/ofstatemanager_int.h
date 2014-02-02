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
 *  /module/src/ofstatemanager_int.h
 *
 *  OFStateManager Internal Header
 *
 *****************************************************************************/


#ifndef __OFSTATEMANAGER_INT_H__
#define __OFSTATEMANAGER_INT_H__

/* C file must include appropriate log header */

#include <indigo/fi.h>
#include <indigo/of_connection_manager.h>
#include <SocketManager/socketmanager.h>
#include <OFStateManager/ofstatemanager_config.h>
#include <cjson/cJSON.h>

/* Short hand logging macros */
#define LOG_ERROR AIM_LOG_ERROR
#define LOG_WARN AIM_LOG_WARN
#define LOG_INFO AIM_LOG_INFO
#define LOG_VERBOSE AIM_LOG_VERBOSE
#define LOG_TRACE AIM_LOG_TRACE

/**
 * Try an operation and return the error code on failure.
 */
#define _TRY(op) do {                                                   \
        int _rv;                                                        \
        if ((_rv = (op)) < 0) {                                         \
            LOG_ERROR("ERROR %d at %s:%d\n", _rv, __FILE__, __LINE__);  \
            return _rv;                                                 \
        }                                                               \
    } while (0)

/**
 * As above, but do not return on error; just log it
 */
#define _TRY_NR(op) do {                                                \
        int _rv;                                                        \
        if ((_rv = (op)) < 0) {                                         \
            LOG_ERROR("ERROR %d at %s:%d\n", _rv, __FILE__, __LINE__);  \
        }                                                               \
    } while (0)

/**
 * Try an operation and return a specified error code on failure.
 */
#define _TRY_RV(op, specified_rv) do {                                  \
        int _rv;                                                        \
        if ((_rv = (op)) < 0) {                                         \
            LOG_ERROR("ERROR %d at %s:%d\n", _rv, __FILE__, __LINE__);  \
            return (specified_rv);                                      \
        }                                                               \
    } while (0)

/**
 * Local state manager configuration data
 * @li init_done Have values been initialized
 * @li flags See OpenFlow protocol, set_config message
 * @li miss_send_len See OpenFlow protocol, set_config message
 */

typedef struct ind_core_desc_stats_s {
    of_desc_str_t sw_desc;
    of_desc_str_t hw_desc;
    of_desc_str_t dp_desc;
    of_desc_str_t mfr_desc;
    of_serial_num_t serial_num;
} ind_core_desc_stats_t;

typedef struct ind_core_of_config_s {
    /* Values for config set by controller */
    uint16_t flags;
    uint16_t miss_send_len;
    int config_set_done; /**< Has a config set been processed */

    /* Values to be used by switch for desc stats reply */
    ind_core_desc_stats_t desc_stats;
} ind_core_of_config_t;

/**
 * Calculate second and nano-second durations for a flow
 */

static inline void
calc_duration(indigo_time_t current_time, indigo_time_t entry_time,
              uint32_t *secs, uint32_t *nsecs)
{
    uint32_t ms_time;

    ms_time = INDIGO_TIME_DIFF_ms(entry_time, current_time);
    *secs = ms_time / 1000;
    *nsecs = ((ms_time % 1000) * 1000000);
}

extern const struct ind_cfg_ops ind_core_cfg_ops;

void ind_core_test_gentable_init(void);
void ind_core_test_gentable_finish(void);

of_object_t *ind_core_dup_tracking(of_object_t *obj, indigo_cxn_id_t cxn_id);

#include <OFStateManager/ofstatemanager.h>

#endif /* __OFSTATEMANAGER_INT_H__ */
