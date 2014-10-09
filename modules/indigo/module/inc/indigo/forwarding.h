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
 * @brief Forwarding module function prototypes
 * @addtogroup indigo-Forwarding
 *
 * This defines the API for all functions provided by the forwarding
 * module. This includes configuration as well as fi (forwarding interface)
 * functions.
 *
 * @{
 */

#ifndef _INDIGO_FORWARDING_H_
#define _INDIGO_FORWARDING_H_

#include <indigo/error.h>
#include <indigo/types.h>
#include <loci/loci.h>
#include <indigo/fi.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief Features get
 * @param features The LOCI reply message to fill out with features
 * @returns Error code
 *
 * Fill out a features reply message for the forwarding information.
 *
 * Ownership of the features_reply LOXI object is maintained by the
 * caller (OF state manager).
 */

extern indigo_error_t indigo_fwd_forwarding_features_get(
    of_features_reply_t *features_reply);

/**
 * @brief VLAN stats
 * @param vlan_vid The ID of the VLAN whose stats are to be retrieved
 * @param [out] vlan_stats Statistics for the VLAN
 *
 * Only supported counters need to be set. The rest will default to -1.
 *
 * If the VLAN is invalid or no stats are available, don't set any of the
 * counters.
 */

void indigo_fwd_vlan_stats_get(
    uint16_t vlan_vid,
    indigo_fi_vlan_stats_t *vlan_stats);

/**
 * @brief Packet out operation
 * @param packet_out The LOXI packet out message
 *
 * Ownership of the packet_out LOXI object is maintained by the
 * caller (OF state manager).
 */

extern indigo_error_t indigo_fwd_packet_out(
    of_packet_out_t *packet_out);

/**
 * @brief Experimenter (vendor) extension
 * @param experimenter The message from the controller
 * @param cxn_id Connection ID on which the message arrived
 *
 * Ownership of the experimenter LOXI object is maintained by the
 * caller (OF state manager).
 */

extern indigo_error_t indigo_fwd_experimenter(
    of_experimenter_t *experimenter,
    indigo_cxn_id_t cxn_id);

/**
 * Switch pipeline management
 *
 * The switch pipeline defines the flow of packets through the functional
 * units of the switch, and the set of tables consulted by these units.
 *
 * The standard method of configuring the switch pipeline is the OF 1.3
 * table-features multipart message. However, this message is not sufficently
 * expressive to represent the flow of packets through a realistic switch.
 */

/**
 * @brief Get existing switch pipeline
 * @param pipeline Pipeline string describing switch operational mode
 */
void indigo_fwd_pipeline_get(of_desc_str_t pipeline);

/**
 * @brief Set switch pipeline
 * @param pipeline Pipeline string describing switch operational mode
 */
indigo_error_t indigo_fwd_pipeline_set(of_desc_str_t pipeline);

/**
 * @brief Get a list of supported switch pipelines
 * @param pipelines List of pipelines
 * @param num_pipelines Number of pipelines
 *
 * Forwarding should allocate memory using aim_malloc() for the pipeline
 * list and set num_pipelines to the number of elements.
 *
 * Caller should use aim_free() to free memory.
 */
void indigo_fwd_pipeline_stats_get(of_desc_str_t **pipelines, int *num_pipelines);

/****************************************************************
 * Function provided for port manager
 ****************************************************************/

/**
 * Accept a data plane packet for processing by forwarding manager
 *
 * @param ingress_port The OpenFlow port from which the packet was received
 * @param data Pointer to a monolithic buffer holding the packet data
 * @param length Length of the packet in bytes
 *
 * Provided by forwarding, required by port manager
 *
 * Ownership of the buffer is maintained by the caller (port manager).
 *
 * Most implementations will have a more direct connection between the port
 * manager and forwarding modules, and will not implement this interface.
 */

extern indigo_error_t indigo_fwd_packet_receive(
    of_port_no_t ingress_port,
    uint8_t *data,
    unsigned length);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* _INDIGO_FORWARDING_H_ */
/* @} */
