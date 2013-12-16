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
 * @brief Forwarding interface structure definitions
 *
 * These are required for the functions defined by both the forwarding
 * module and the state manager module.
 */

#ifndef _INDIGO_FI_H_
#define _INDIGO_FI_H_

#include <indigo/error.h>
#include <indigo/types.h>
#include <indigo/time.h>
#include <loci/loci.h>


/**
 * @brief Flow removed reasons.
 *
 * See indigo_core_flow_removed.   In addition to the OF flow removed
 * reasons, we add overwrite, resource and unknown.
 */

typedef enum indigo_fi_flow_removed_e {
    INDIGO_FLOW_REMOVED_NONE         = -1,
    INDIGO_FLOW_REMOVED_IDLE_TIMEOUT = OF_FLOW_REMOVED_REASON_IDLE_TIMEOUT,
    INDIGO_FLOW_REMOVED_HARD_TIMEOUT = OF_FLOW_REMOVED_REASON_HARD_TIMEOUT,
    INDIGO_FLOW_REMOVED_DELETE       = OF_FLOW_REMOVED_REASON_DELETE,
    INDIGO_FLOW_REMOVED_GROUP_DELETE = OF_FLOW_REMOVED_REASON_GROUP_DELETE,
    INDIGO_FLOW_REMOVED_OVERWRITE    = 4,
    INDIGO_FLOW_REMOVED_RESOURCE     = 5,
    INDIGO_FLOW_REMOVED_UNKNOWN      = 6
} indigo_fi_flow_removed_t;

/**
 * @brief Flow statistics counters
 *
 * Not all implementations will support duration_ns.  It must be 0 if not used.
 * It is provided for implementations that do timing events such as flow
 * expirations in the forwarding module.
 */

typedef struct indigo_fi_flow_stats {
    indigo_flow_id_t flow_id; /**< The ID of the flow */
    uint64_t duration_ns;     /**< Time in ns flow exists or existed */
    uint64_t packets;         /**< Number of packets in flow  */
    uint64_t bytes;           /**< Number of bytes in flow  */
} indigo_fi_flow_stats_t;

/**
 * @brief VLAN statistics counters
 *
 * Should be set to -1 if not supported.
 */

typedef struct indigo_fi_vlan_stats {
    uint64_t rx_bytes;
    uint64_t rx_packets;
    uint64_t tx_bytes;
    uint64_t tx_packets;
} indigo_fi_vlan_stats_t;

/**
 * @brief Port statistics counters
 *
 * Should be set to -1 if not supported.
 */

typedef struct indigo_fi_port_stats {
    uint64_t rx_bytes;
    uint64_t rx_packets_unicast;
    uint64_t rx_packets_broadcast;
    uint64_t rx_packets_multicast;
    uint64_t rx_dropped;
    uint64_t rx_errors;
    uint64_t tx_bytes;
    uint64_t tx_packets_unicast;
    uint64_t tx_packets_broadcast;
    uint64_t tx_packets_multicast;
    uint64_t tx_dropped;
    uint64_t tx_errors;
} indigo_fi_port_stats_t;

#endif /* _INDIGO_FI_H_ */
