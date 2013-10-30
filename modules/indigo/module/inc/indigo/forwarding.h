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
 * Unless otherwise noted, calls in this file are asynchronous.  This is
 * indicated by a void return type.
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
 * This is a synchronous call.
 *
 * Ownership of the features_reply LOXI object is maintained by the
 * caller (OF state manager).
 */

extern indigo_error_t indigo_fwd_forwarding_features_get(
    of_features_reply_t *features_reply);

/**
 * @brief Flow create
 * @param of_flow_add The original LOCI request
 * @param [out] table_id Table inserted into
 *
 * Create a flow for the forwarding engine.
 *
 * This is a synchronous call.
 *
 * Ownership of the flow_add LOXI object is maintained by the
 * caller (OF state manager).
 */

extern indigo_error_t indigo_fwd_flow_create(
    indigo_cookie_t flow_id,
    of_flow_add_t *flow_add,
    uint8_t *table_id);

/**
 * @brief Modify an existing flow.
 * @param flow_id Flow identifier
 * @param flow_modify The original LOCI message indicating the modification
 * @return Return code from operation
 *
 * @fixme Consider adding parameters to indicate modification that
 * should be done:  modify_effects, modify_cookie or clear_counters.
 *
 * Ownership of the flow_modify LOXI object is maintained by the
 * caller (OF state manager).
 */

extern indigo_error_t indigo_fwd_flow_modify(
    indigo_cookie_t flow_id,
    of_flow_modify_t *flow_modify);

/**
 * @brief Flow delete
 * @param flow_id Flow identifier
 * @param callback_cookie Passed to async response callback
 *
 * Delete a flow from the forwarding engine.  Final stats are returned to
 * the state manager via the response callback.
 */

extern void indigo_fwd_flow_delete(
    indigo_cookie_t flow_id,
    indigo_cookie_t callback_cookie);

/**
 * @brief Flow stats
 * @param flow_id The ID of the flow whose stats are to be retrieved
 * @param [out] flow_stats Statistics for flow
 *
 * This is a synchronous operation.
 *
 * Get the stats structure from an existing flow. The flow_stats object MUST
 * contain the flow ID.
 */

extern indigo_error_t indigo_fwd_flow_stats_get(
    indigo_cookie_t flow_id,
    indigo_fi_flow_stats_t *flow_stats);

/**
 * @brief Modify table properties
 * @param of_table_mod The LOXI request
 * @param callback_cookie Passed to async response callback
 *
 * Modify properties of given table.
 */

extern void indigo_fwd_table_mod(
      of_table_mod_t *of_table_mod,
      indigo_cookie_t callback_cookie);

/**
 * @brief Table stats
 * @param table_stats_request The LOXI request
 * @param [out] table_stats_reply The LOXI reply
 * @return Return code from operation
 *
 * This is a synchronous operation.
 *
 * Ownership of the table_stats_request LOXI object is maintained by the
 * caller (OF state manager).
 */

extern indigo_error_t indigo_fwd_table_stats_get(
    of_table_stats_request_t *table_stats_request,
    of_table_stats_reply_t **table_stats_reply);

/**
 * @brief Packet out operation
 * @param packet_out The LOXI packet out message
 *
 * This is a synchronous operation.
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
 * This is a synchronous function.
 *
 * Ownership of the experimenter LOXI object is maintained by the
 * caller (OF state manager).
 */

extern indigo_error_t indigo_fwd_experimenter(
    of_experimenter_t *experimenter,
    indigo_cxn_id_t cxn_id);


/**
 * Notify forwarding of changes in expiration processing behavior
 */
extern indigo_error_t indigo_fwd_expiration_enable_set(int is_enabled);
extern indigo_error_t indigo_fwd_expiration_enable_get(int *is_enabled);

/**
 * Group management
 *
 * These interfaces largely map to the OpenFlow group-mod message, but with a
 * few differences for easier Forwarding implementation:
 *
 *  - Delete of OFPG_ALL is turned into a series of deletes of single groups.
 *  - Modify with a changed type is turned into a delete and add.
 */

/**
 * @brief Add a group
 * @param id Group ID
 * @param group_type OpenFlow group type
 * @param buckets LOCI bucket list
 */
indigo_error_t indigo_fwd_group_add(uint32_t id, uint8_t group_type, of_list_bucket_t *buckets);

/**
 * @brief Modify an existing group
 * @param id Group ID
 * @param buckets LOCI bucket list
 */
indigo_error_t indigo_fwd_group_modify(uint32_t id, of_list_bucket_t *buckets);

/**
 * @brief Delete an existing group
 * @param id Group ID
 */
void indigo_fwd_group_delete(uint32_t id);

/**
 * @brief Retrieve stats for a group
 * @param id Group ID
 * @param entry LOCI of_group_stats_entry_t to be filled in with stats
 *
 * Forwarding should set the packet_count, byte_count, and bucket_stats fields.
 */
void indigo_fwd_group_stats_get(uint32_t id, of_group_stats_entry_t *entry);

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
