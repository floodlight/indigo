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
 *  /module/inc/ofstatemanager.h
 *
 *  OFStateManager Public Interface
 *
 *****************************************************************************/


#ifndef __OFSTATEMANAGER_H__
#define __OFSTATEMANAGER_H__


#include "ofstatemanager_config.h"
#include <indigo/types.h>
#include <indigo/error.h>
#include <indigo/of_state_manager.h>

/**
 * @brief The default strings reported for desc stats
 */

#define IND_CORE_SW_DESC_DEFAULT "Indigo-2"
#define IND_CORE_HW_DESC_DEFAULT "Server"
#define IND_CORE_MFR_DESC_DEFAULT "The Indigo-2 Community"
#define IND_CORE_DP_DESC_DEFAULT "Virtual forwarding module"
#define IND_CORE_SERIAL_NUM_DEFAULT "11235813213455"

/**
 * Default number of entries to allocate in the flow table
 */
#define IND_CORE_FT_MAX_ENTRIES (16 * 1024)

typedef struct ind_core_config_s {
    int expire_flows;   /**< Boolean, should state mgr manage flow expires */
    int stats_check_ms; /**< How frequently to check stats for expire, etc */
    indigo_core_disconnected_mode_t disconnected_mode;
} ind_core_config_t;


/**
 * Initialize module
 * @param config Configuration
 */
indigo_error_t ind_core_init(ind_core_config_t *config);

/**
 * Clean up module
 */
indigo_error_t ind_core_finish(void);

/**
 * Enable/disable module
 * @param enable
 *
 * All modules must be initialized before calling this function.
 */
indigo_error_t ind_core_enable_set(int enable);

/**
 * Get enable status for module
 * @param (out) enable
 */
indigo_error_t ind_core_enable_get(int *enable);

/**
 * @brief Set/get descriptive stats values for the switch
 */

indigo_error_t ind_core_sw_desc_set(of_desc_str_t desc);
indigo_error_t ind_core_sw_desc_get(of_desc_str_t desc);
indigo_error_t ind_core_hw_desc_set(of_desc_str_t desc);
indigo_error_t ind_core_hw_desc_get(of_desc_str_t desc);
indigo_error_t ind_core_dp_desc_set(of_desc_str_t desc);
indigo_error_t ind_core_dp_desc_get(of_desc_str_t desc);
indigo_error_t ind_core_mfr_desc_set(of_desc_str_t desc);
indigo_error_t ind_core_mfr_desc_get(of_desc_str_t desc);
indigo_error_t ind_core_serial_num_set(of_serial_num_t serial_num);
indigo_error_t ind_core_serial_num_get(of_serial_num_t serial_num);

/**
 * Flow Table Iterator
 */
typedef int (ind_core_ft_iter_f)(indigo_flow_id_t id,
                                 of_flow_add_t* ofa, void* cookie);

/**
 * Iterate over all core flowtable entries.
 */
indigo_error_t ind_core_ft_iter(ind_core_ft_iter_f iter, void* cookie);

/**
 * Dump all entries in the flow table.
 * This is verbose.
 */
void ind_core_ft_dump(aim_pvs_t* pvs);

/**
 * Show all entries in the flow table.
 * Human readable.
 */
void ind_core_ft_show(aim_pvs_t* pvs);

/**
 * Show basic stats about a flow table
 */
void ind_core_ft_stats(aim_pvs_t* pvs);

#endif /* __OFSTATEMANAGER_H__ */
