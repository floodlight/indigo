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
 * @brief OpenFlow state manager module function prototypes
 * @addtogroup indigo-OFStateManager
 *
 * This defines the API for all functions provided by the OpenFlow
 * state manager.  This includes fi_ and configuration interface
 * functions.
 *
 * @{
 */

#ifndef _INDIGO_OF_STATE_MANAGER_H_
#define _INDIGO_OF_STATE_MANAGER_H_

#include <indigo/of_connection_manager.h>
#include <indigo/forwarding.h>
#include <loci/loci.h>
#include <indigo/fi.h>

/****************************************************************
 * Remote disconnect modes (formerly fail open, closed, etc).
 ****************************************************************/

/**
 * Representations of fail (disconnected) modes.  Determines what the
 * switch should do on the loss of all remote connections.
 *
 * STICKY:      Keep flowtable, stop processing expires
 * CLOSED:      Keep flowtable, but continue expires
 * DISABLED:    Clear flowtable
 * LOCKDOWN:    Clear flowtable, disable ports
 * LOCAL:       Enable local controller
 */

typedef enum indigo_core_disconnected_e {
    INDIGO_CORE_DISCONNECTED_MODE_STICKY     = 0,
    INDIGO_CORE_DISCONNECTED_MODE_CLOSED     = 1,
    INDIGO_CORE_DISCONNECTED_MODE_DISABLED   = 2,
    INDIGO_CORE_DISCONNECTED_MODE_LOCKDOWN   = 3,
    INDIGO_CORE_DISCONNECTED_MODE_LOCAL      = 4,
    IND_CORE_DISCONNECTED_MODE_COUNT         = 5   /* Last entry */
} indigo_core_disconnected_mode_t;

/****************************************************************
 * Forwarding Interface functions provided by the state manager
 ****************************************************************/

/**
 * Handle a packet in from the forwarding module
 * @param packet_in Pointer to the packet in object
 *
 * The state manager takes responsibility for the object
 */

extern indigo_error_t indigo_core_packet_in(of_packet_in_t *packet_in);


/****************************************************************
 * Controller message handling by the state manager
 ****************************************************************/

/**
 * Handle an OpenFlow message from a controller connection
 *
 * @param cxn The handle of the connection on which the message was received
 * @param obj The LOCI object representing the message
 *
 * Provided by state manager, required by connection manager
 *
 * Ownership of the message is not transferred.
 */

extern void indigo_core_receive_controller_message(
    indigo_cxn_id_t cxn,
    of_object_t *obj);


/****************************************************************
 * Configuration Interface functions provided by the state manager
 ****************************************************************/

/**
 * Set the datapath ID for the switch instance
 * @param dpid The datapath ID
 * @param returns indigo_error_t
 */

extern indigo_error_t indigo_core_dpid_set(of_dpid_t dpid);

/**
 * Get the datapath ID for the switch instance
 * @param dpid Pointer to where to store the DPID
 * @param returns indigo_error_t
 */

extern indigo_error_t indigo_core_dpid_get(of_dpid_t *dpid);

/****************************************************************
 * Asynchronous port event notification call
 ****************************************************************/

/**
 * @brief Notify state manager of port status change
 * @param port_status A LOXI message describing the change
 * in the port status
 *
 * The receiver becomes the owner of the port_status object.
 */
extern void indigo_core_port_status_update(of_port_status_t *port_status);


/****************************************************************
 * Asynchronous forwarding flow removed event notification call
 *
 ****************************************************************/

/**
 * @brief Notify state manager that a flow has been removed
 * @param reason The reason the flow was removed.  See fi.h.
 * @param stats A stats structure identifying the flow and related info
 *
 * This call is made from forwarding to the state manager to indicate
 * that a flow has been removed for some reason.
 *
 * Not all implementations may support this.  It is provided for
 * those which may do all flow expiration processing in the
 * forwarding module, and for those which may evict flows due
 * to resource or other constraints.
 *
 * It is not recommended that this call be made if a flow was removed because
 * of a call from the state manager to indigo_fwd_flow_delete.
 */

extern void indigo_core_flow_removed(
    indigo_fi_flow_removed_t reason,
    indigo_fi_flow_stats_t *stats);

/****************************************************************
 * Asynchronous connection manager notification, disconnection mode
 ****************************************************************/

/**
 * Set/get the disconnected mode
 */
extern indigo_error_t
indigo_core_disconnected_mode_set(indigo_core_disconnected_mode_t mode);

extern indigo_error_t
indigo_core_disconnected_mode_get(indigo_core_disconnected_mode_t *mode);

/**
 * @brief Notify state manager that the remote connection count has changed
 * @param new_count The new connection count
 *
 * This call is made from the connection manager to the state manager
 * to indicate that the number of connections to controllers has
 * changed.  This is intended to provide the state to core in order to
 * invoke the necessary changes to implement the configured disconnect mode.
 */

extern void indigo_core_connection_count_notify(
    int new_count);


/**
 * @brief Returns state manager statistics.
 * @param total_flows Current number of flows.
 * @param flow_mods Number of flow mod messages.
 * @param packet_ins Number of packet in messages.
 * @param packet_outs Number of packet out messages.
 *
 * Returns the number of current flows, flow mods, packet ins, and packet outs.
 * The last three quantities are cumulative as of the last time this function
 * was called.
 */

extern void
indigo_core_stats_get(uint32_t *total_flows,
                      uint32_t *flow_mods,
                      uint32_t *packet_ins,
                      uint32_t *packet_outs);

/****************************************************************
 * Gentable
 *
 * The gentable OpenFlow extension is documented fully in LOXI.
 *
 * The 'add' operation may optionally return a pointer-size value of private
 * data. This value will be passed to later operations on that entry. The
 * intended use is to store a pointer to the table implementation's allocated
 * memory for that entry, avoiding the neeed to parse the key and do a
 * hashtable lookup for each operation.
 *
 * The 'modify' operation does not exist in the wire protocol. It will be
 * called when a gentable_entry_add message is received for a key that
 * already exists in the table.
 *
 ****************************************************************/

/**
 * @brief Opaque handle to a gentable
 */
typedef struct indigo_core_gentable indigo_core_gentable_t;

/**
 * @brief Operations on a gentable
 */
typedef struct indigo_core_gentable_ops {
    /**
     * @brief Add an entry
     * @param table_priv Table private data
     * @param key Entry key
     * @param value Entry value
     * @param [out] entry_priv Opaque private data for the entry, passed back
     *                         whenever another operation is made on the entry.
     */
    indigo_error_t (*add)(void *table_priv, of_list_bsn_tlv_t *key, of_list_bsn_tlv_t *value, void **entry_priv);

    /**
     * @brief Modify an entry
     * @param table_priv Table private data
     * @param entry_priv Entry private data
     * @param key Entry key (identical to key from add)
     * @param value New entry value
     */
    indigo_error_t (*modify)(void *table_priv, void *entry_priv, of_list_bsn_tlv_t *key, of_list_bsn_tlv_t *value);

    /**
     * @brief Delete an entry
     * @param table_priv Table private data
     * @param entry_priv Entry private data
     * @param key Entry key (identical to key from add)
     */
    indigo_error_t (*del)(void *table_priv, void *entry_priv, of_list_bsn_tlv_t *key);

    /**
     * @brief Get stats for an entry
     * @param table_priv Table private data
     * @param entry_priv Entry private data
     * @param key Entry key (identical to key from add)
     * @param stats Stats list to be filled in
     */
    void (*get_stats)(void *table_priv, void *entry_priv, of_list_bsn_tlv_t *key, of_list_bsn_tlv_t *stats);
} indigo_core_gentable_ops_t;

/*
 * @brief Register a gentable
 * @param name Table name. The controller determines the table semantics based
 *             solely on this name.
 * @param ops Table operations. This memory should have static lifetime.
 * @param table_priv Opaque private data for this table, passed back
 *                   whenever an operation is made on the table.
 * @param max_size Maximum number of entries in the table. Not enforced by the
 *                 Indigo framework, only used for advertising to the controller.
 * @param buckets_size Initial size of the buckets array. May be resized by the
 *                     controller.
 * @param [out] gentable Handle to be passed to indigo_core_gentable_unregister.
 */

void
indigo_core_gentable_register(
    const char *name,
    const indigo_core_gentable_ops_t *ops,
    void *table_priv,
    uint32_t max_size,
    uint32_t buckets_size,
    indigo_core_gentable_t **gentable);

/*
 * @brief Unregister a gentable
 * @param gentable
 */

void
indigo_core_gentable_unregister(indigo_core_gentable_t *gentable);


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
typedef enum indigo_core_listener_result {
    INDIGO_CORE_LISTENER_RESULT_PASS = 0,
    INDIGO_CORE_LISTENER_RESULT_DROP = 1,
} indigo_core_listener_result_t;

/**
 * Packet-in listener registration
 */
typedef indigo_core_listener_result_t (*indigo_core_packet_in_listener_f)(of_packet_in_t *packet_in);
indigo_error_t indigo_core_packet_in_listener_register(indigo_core_packet_in_listener_f fn);
void indigo_core_packet_in_listener_unregister(indigo_core_packet_in_listener_f fn);

/**
 * Port status listener registration
 */
typedef indigo_core_listener_result_t (*indigo_core_port_status_listener_f)(of_port_status_t *port_status);
indigo_error_t indigo_core_port_status_listener_register(indigo_core_port_status_listener_f fn);
void indigo_core_port_status_listener_unregister(indigo_core_port_status_listener_f fn);

/**
 * Message listener registration
 */
typedef indigo_core_listener_result_t (*indigo_core_message_listener_f)(indigo_cxn_id_t cxn_id, of_object_t *msg);
indigo_error_t indigo_core_message_listener_register(indigo_core_message_listener_f fn);
void indigo_core_message_listener_unregister(indigo_core_message_listener_f fn);


/****************************************************************
 *
 * Flowtable registration
 *
 * Instead of implementing indigo_flow_*, the Forwarding module can
 * use this interface to register individual tables. The advantage
 * is that the Forwarding module doesn't need to do the dispatch
 * to the table implementation itself. In the future, indigo_flow_*
 * will be removed. At that point indigo_fwd_table_stats_get and
 * the (currently unimplemented) table features stats will be
 * replaced with additional per-table methods.
 *
 * If Forwarding uses this interface exclusively then it does not
 * need to maintain a hashtable keyed on flow ID. The only API that
 * still uses the flow ID is indigo_core_flow_removed.
 *
 * This is intended to be used in conjunction with the Indigo
 * forwarding pipeline interface. When indigo_fwd_pipeline_set is
 * called all tables must first be unregistered, then the tables
 * of the new pipeline must be registered. In case the new pipeline
 * is the same as the old one this will have the intended effect
 * of clearing all flows.
 *
 ****************************************************************/

/**
 * Table operations
 */

typedef struct indigo_core_table_ops_s {
    /**
     * Add an entry to the table
     * @param table_priv Private data passed to indigo_core_table_register
     * @param obj Flow-add message
     * @param flow_id Flow ID (only for use with indigo_core_flow_removed)
     * @param [out] entry_priv Private data for this flow
     */
    indigo_error_t (*entry_create)(void *table_priv, of_flow_add_t *obj, indigo_cookie_t flow_id, void **entry_priv);

    /**
     * Modify an entry in the table
     * @param table_priv Private data passed to indigo_core_table_register
     * @param entry_priv Private data returned by the entry_create operation
     * @param obj Flow-modify message
     */
    indigo_error_t (*entry_modify)(void *table_priv, void *entry_priv, of_flow_modify_strict_t *obj);

    /**
     * Delete an entry from the table
     * @param table_priv Private data passed to indigo_core_table_register
     * @param entry_priv Private data returned by the entry_create operation
     * @param [out] flow_stats Final stats
     *
     * No further operations will be called with entry_priv, so the
     * implementation should deallocate it.
     */
    indigo_error_t (*entry_delete)(void *table_priv, void *entry_priv, indigo_fi_flow_stats_t *flow_stats);

    /**
     * Retrieve stats for an entry
     * @param table_priv Private data passed to indigo_core_table_register
     * @param entry_priv Private data returned by the entry_create operation
     * @param [out] flow_stats Current stats
     */
    indigo_error_t (*entry_stats_get)(void *table_priv, void *entry_priv, indigo_fi_flow_stats_t *flow_stats);

    /**
     * Retrieve and reset hit status for an entry
     * @param table_priv Private data passed to indigo_core_table_register
     * @param entry_priv Private data returned by the entry_create operation
     * @param [out] hit_status True if entry hit since last time API was called
     */
    indigo_error_t (*entry_hit_status_get)(void *table_priv, void *entry_priv, bool *hit_status);
} indigo_core_table_ops_t;

/**
 * Register a flowtable
 *
 * The table ID and name must be unique. The ops must be valid at least until
 * the table is unregistered. 'table_priv' will be passed to every operation on
 * the table.
 *
 * Existing flows with the same table ID will be deleted.
 */
void indigo_core_table_register(uint8_t table_id, const char *name, const indigo_core_table_ops_t *ops, void *table_priv);

/**
 * Unregister a flowtable
 *
 * Existing entries will be deleted.
 */
void indigo_core_table_unregister(uint8_t table_id);

#endif /* _INDIGO_OF_STATE_MANAGER_H_ */
/** @} */
