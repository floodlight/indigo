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
 *
 * @addtogroup OFStateManager
 * @{
 *
 * This file defines the implementation-specific interfaces exposed by
 * OFStateManager. Most functions provided by this module are defined
 * in the Indigo @ref indigo-OFStateManager headers.
 */


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

typedef struct ind_core_config_s {
    int expire_flows;   /**< Boolean, should state mgr manage flow expires */
    int stats_check_ms; /**< How frequently to check stats for expire, etc */
    indigo_core_disconnected_mode_t disconnected_mode;
    int max_flowtable_entries; /**< Maximum number of entries in the flowtable */
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

/**
 * Listener interfaces
 *
 * These functions allow modules not defined in the Indigo architecture to
 * react to dataplane events and controller messages. This is useful for
 * implementing add-on switch functionality like LACP and LLDP offloads.
 */

/**
 * If any listener returns DROP, the event will not be handled by
 * OFStateManager. All listeners will still see the event.
 */
typedef enum ind_core_listener_result {
    IND_CORE_LISTENER_RESULT_PASS = 0,
    IND_CORE_LISTENER_RESULT_DROP = 1,
} ind_core_listener_result_t;

/**
 * Packet-in listener registration
 */
typedef ind_core_listener_result_t (*ind_core_packet_in_listener_f)(of_packet_in_t *packet_in);
indigo_error_t ind_core_packet_in_listener_register(ind_core_packet_in_listener_f fn);
void ind_core_packet_in_listener_unregister(ind_core_packet_in_listener_f fn);

/**
 * Port status listener registration
 */
typedef ind_core_listener_result_t (*ind_core_port_status_listener_f)(of_port_status_t *port_status);
indigo_error_t ind_core_port_status_listener_register(ind_core_port_status_listener_f fn);
void ind_core_port_status_listener_unregister(ind_core_port_status_listener_f fn);

/**
 * Message listener registration
 */
typedef ind_core_listener_result_t (*ind_core_message_listener_f)(indigo_cxn_id_t cxn_id, of_object_t *msg);
indigo_error_t ind_core_message_listener_register(ind_core_message_listener_f fn);
void ind_core_message_listener_unregister(ind_core_message_listener_f fn);

#endif /* __OFSTATEMANAGER_H__ */
/** @} */
