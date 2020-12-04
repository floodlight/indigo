/****************************************************************
 *
 *        Copyright 2013-2016,2018-2020, Arista Networks, Inc.
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

extern indigo_error_t indigo_core_receive_controller_message(
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
 * Miscellaneous stats
 ****************************************************************/

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
 * Async operation support:
 * add4()/modify4()/del4() are used for async operations.
 * In the event that PENDING or CONTINUE is returned by the add4/modify4/
 * del4 APIs, the pending count will be incremented and
 * the resume function indigo_core_gentable_resume() must be called by
 * the driver either to complete any remaining work if the asynchronous
 * operation is successfully completed by the lower-level driver, or to
 * clean up operational state if the asynchronous operation fails in
 * lower-level driver code.
 *
 * The difference between PENDING and CONTINUE is that
 * PENDING will pause subbundle processing while CONTINUE will continue
 * the next message until all messages in subbundle have been processed.
 *
 * Also, in order to provide sufficient context to the resume function,
 * the add4/modify4/del4 APIs take a void* context as their first parameter.
 * This void* value should be passed back to the resume function when the
 * lower-level driver code finally completes (either with success or failure).
 *
 * The state manager also needs the operation context, containing
 * connection id and oflow obj, to resume its remaining tasks.
 * The operation context is passed to the driver in a form of
 * struct indigo_core_op_context. (See add4()/modify4()/del4()).
 * Drivers call the resume function with the operation context and
 * the final status.
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
    indigo_error_t (*add)(
        void *table_priv, of_list_bsn_tlv_t *key, of_list_bsn_tlv_t *value,
        void **entry_priv);

    /**
     * @brief Modify an entry
     * @param table_priv Table private data
     * @param entry_priv Entry private data
     * @param key Entry key (identical to key from add)
     * @param value New entry value
     */
    indigo_error_t (*modify)(
        void *table_priv, void *entry_priv, of_list_bsn_tlv_t *key,
        of_list_bsn_tlv_t *value);

    /**
     * @brief Delete an entry
     * @param table_priv Table private data
     * @param entry_priv Entry private data
     * @param key Entry key (identical to key from add)
     */
    indigo_error_t (*del)(
        void *table_priv, void *entry_priv, of_list_bsn_tlv_t *key);

    /**
     * @brief Get stats for an entry
     * @param table_priv Table private data
     * @param entry_priv Entry private data
     * @param key Entry key (identical to key from add)
     * @param stats Stats list to be filled in
     */
    void (*get_stats)(
        void *table_priv, void *entry_priv, of_list_bsn_tlv_t *key,
        of_list_bsn_tlv_t *stats);

    /**
     * @brief Add an entry
     * @param cxn_id Controller connection ID
     * @param table_priv Table private data
     * @param key Entry key
     * @param value Entry value
     * @param [out] entry_priv Opaque private data for the entry, passed back
     *                         whenever another operation is made on the entry.
     */
    indigo_error_t (*add2)(
        indigo_cxn_id_t cxn_id,
        void *table_priv, of_list_bsn_tlv_t *key, of_list_bsn_tlv_t *value,
        void **entry_priv);

    /**
     * @brief Modify an entry
     * @param cxn_id Controller connection ID
     * @param table_priv Table private data
     * @param entry_priv Entry private data
     * @param key Entry key (identical to key from add)
     * @param value New entry value
     */
    indigo_error_t (*modify2)(
        indigo_cxn_id_t cxn_id,
        void *table_priv, void *entry_priv, of_list_bsn_tlv_t *key,
        of_list_bsn_tlv_t *value);

    /**
     * @brief Delete an entry
     * @param cxn_id Controller connection ID
     * @param table_priv Table private data
     * @param entry_priv Entry private data
     * @param key Entry key (identical to key from add)
     */
    indigo_error_t (*del2)(
        indigo_cxn_id_t cxn_id,
        void *table_priv, void *entry_priv, of_list_bsn_tlv_t *key);

    /**
     * @brief Add an entry
     * @param cxn_id Controller connection ID
     * @param table_priv Table private data
     * @param key Entry key
     * @param value Entry value
     * @param [out] entry_priv Opaque private data for the entry, passed back
     *                         whenever another operation is made on the entry.
     * @param err_txt In case of error, text to be copied to bsn_error msg
     * NOTE: When writing into err_txt, it is the implementer's responsibility
     * not to overflow err_txt
     */
    indigo_error_t (*add3)(
        indigo_cxn_id_t cxn_id,
        void *table_priv, of_list_bsn_tlv_t *key, of_list_bsn_tlv_t *value,
        void **entry_priv, of_desc_str_t err_txt);

    /**
     * @brief Modify an entry
     * @param cxn_id Controller connection ID
     * @param table_priv Table private data
     * @param entry_priv Entry private data
     * @param key Entry key (identical to key from add)
     * @param value New entry value
     * @param err_txt In case of error, text to be copied to bsn_error msg
     * NOTE: When writing into err_txt, it is the implementer's responsibility
     * not to overflow err_txt
     */
    indigo_error_t (*modify3)(
        indigo_cxn_id_t cxn_id,
        void *table_priv, void *entry_priv, of_list_bsn_tlv_t *key,
        of_list_bsn_tlv_t *value, of_desc_str_t err_txt);

    /**
     * @brief Delete an entry
     * @param cxn_id Controller connection ID
     * @param table_priv Table private data
     * @param entry_priv Entry private data
     * @param key Entry key (identical to key from add)
     * @param err_txt In case of error, text to be copied to bsn_error msg
     * NOTE: When writing into err_txt, it is the implementer's responsibility
     * not to overflow err_txt
     */
    indigo_error_t (*del3)(
        indigo_cxn_id_t cxn_id,
        void *table_priv, void *entry_priv, of_list_bsn_tlv_t *key,
        of_desc_str_t err_txt);

    /**
     * @brief Add an entry
     * @param cxn_id Controller connection ID
     * @param table_priv Table private data
     * @param key Entry key (identical to key from add)
     * @param value New entry value
     * @param [out] entry_priv Opaque private data for the entry, passed back
     *                         whenever another operation is made on the entry.
     *                         For async operation (return INDIGO_ERROR_PENDING)
     *                         this value assigned to entry_priv will be
     *                         ignored by state manager. Instead, the entry_priv
     *                         passed to the resume function will be stored if
     *                         the asynchronous operation is successfully
     *                         completed by the lower-level driver
     * @param err_txt In case of error, text to be copied to bsn_error msg
     * @param op_ctx Opaque context to be passed back to state manager when
     *               resume function is called after async operation completes
     * NOTE: When writing into err_txt, it is the implementer's responsibility
     * not to overflow err_txt
     */
    indigo_error_t (*add4)(
        indigo_cxn_id_t cxn_id,
        void *table_priv, of_list_bsn_tlv_t *key, of_list_bsn_tlv_t *value,
        void **entry_priv, of_desc_str_t err_txt,
        void *op_ctx);

    /**
     * @brief Modify an entry
     * @param cxn_id Controller connection ID
     * @param table_priv Table private data
     * @param entry_priv Entry private data
     * @param key Entry key (identical to key from add)
     * @param value New entry value
     * @param err_txt In case of error, text to be copied to bsn_error msg
     * @param op_ctx Opaque context to be passed back to state manager when
     *               resume function is called after async operation completes
     * NOTE: When writing into err_txt, it is the implementer's responsibility
     * not to overflow err_txt
     */
    indigo_error_t (*modify4)(
        indigo_cxn_id_t cxn_id,
        void *table_priv, void *entry_priv, of_list_bsn_tlv_t *key,
        of_list_bsn_tlv_t *value, of_desc_str_t err_txt,
        void *op_ctx);

    /**
     * @brief Delete an entry
     * @param cxn_id Controller connection ID
     * @param table_priv Table private data
     * @param entry_priv Entry private data
     * @param key Entry key (identical to key from add)
     * @param err_txt In case of error, text to be copied to bsn_error msg
     * @param op_ctx Opaque context to be passed back to state manager when
     *               resume function is called after async operation completes
     * NOTE: When writing into err_txt, it is the implementer's responsibility
     * not to overflow err_txt
     */
    indigo_error_t (*del4)(
        indigo_cxn_id_t cxn_id,
        void *table_priv, void *entry_priv, of_list_bsn_tlv_t *key,
        of_desc_str_t err_txt,
        void *op_ctx);

    /**
     * @brief Start a subbundle operation on this gentable
     * @param cxn_id Controller connection ID
     * @param table_priv Table private data
     */
    indigo_error_t (*start)(
        indigo_cxn_id_t cxn_id, void *table_priv);

    /**
     * @brief Finish a subbundle operation on this gentable
     * @param cxn_id Controller connection ID
     * @param table_priv Table private data
     */
    indigo_error_t (*finish)(
        indigo_cxn_id_t cxn_id, void *table_priv);
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

/*
 * @brief resume indigo add4()/modify4()/del4() when the driver gets the final status 
 * @param op_ctx operation context 
 * @param entry_priv driver's private data for this entry
 * @param err_txt error string from driver
 * @param rv the final status of the driver async add/modify/del
 *
 * The state manager will use the value of rv to either complete the async
 * operation in case of success or clean up in case of failure
 * This function is intended for asynchronous operations, and should not be called for
 * synchronous operations
 * For synchronous operations, the state manager will call this function internally.
 */

void
indigo_core_gentable_entry_resume(
    void *op_ctx,
    void *entry_priv,
    of_desc_str_t err_txt,
    indigo_error_t rv);

/*
 * @brief Lookup a gentable entry by key
 * @param gentable
 * @param key
 *
 * Returns the private data for the entry, or NULL if not found.
 *
 * The key can be either a single TLV or a list of TLVs.
 */

void *
indigo_core_gentable_lookup(indigo_core_gentable_t *gentable, of_object_t *key);

/*
 * @brief Acquire a reference to a gentable entry
 * @param gentable
 * @param key
 *
 * Returns the private data for the entry, or NULL if not found.
 *
 * The key can be either a single TLV or a list of TLVs.
 *
 * Delete operations on the gentable entry will be rejected until all
 * references to it are released.
 */

void *
indigo_core_gentable_acquire(indigo_core_gentable_t *gentable, of_object_t *key);

/*
 * @brief Release a reference to a gentable entry
 * @param gentable
 * @param key
 *
 * The key can be either a single TLV or a list of TLVs.
 */

void
indigo_core_gentable_release(indigo_core_gentable_t *gentable, of_object_t *key);

/*
 * @brief Get the table ID of a gentable
 * @param gentable
 *
 * Returns the table ID assigned to the given gentable.
 */

uint16_t
indigo_core_gentable_id(indigo_core_gentable_t *gentable);

/**
 * @brief Get the table ID of a gentable from its name.
 * @param name Gentable name; should be same as that passed when registering.
 *
 * Returns the table ID assigned to the gentable with the specified name.
 * If the gentable is not found, returns GENTABLE_ID_INVALID.
 */
#define GENTABLE_ID_INVALID ((uint16_t) (-1))

uint16_t
indigo_core_gentable_id_lookup(const char *name);

/**
 * @brief Invoke the start function from indigo_core_gentable_ops_t
 * @param gentable_id table ID, uint16_t
 * @param cxn_id Controller connection ID
 *
 * Provided as a convenience routine.  Intended to be called from
 * subbundle start functions, registered with indigo_cxn_subbundle_set2().
 */

indigo_error_t
indigo_core_gentable_start(uint16_t gentable_id,
                           indigo_cxn_id_t cxn_id);

/**
 * @brief Invoke the finish function from indigo_core_gentable_ops_t
 * @param gentable_id table ID, uint16_t
 * @param cxn_id Controller connection ID
 *
 * Provided as a convenience routine.  Intended to be called from
 * subbundle finish functions, registered with indigo_cxn_subbundle_set2().
 */

indigo_error_t
indigo_core_gentable_finish(uint16_t gentable_id,
                            indigo_cxn_id_t cxn_id);

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
 * The Forwarding implementation uses these interfaces to tell
 * OFStateManager which flowtables exist. When OFStateManager
 * needs to create a flow, get stats, etc, it uses the function
 * pointers passed to indigo_core_table_register to call into
 * Forwarding.
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
     * @param cxn_id Connection requesting this operation
     * @param obj Flow-add message
     * @param flow_id Flow ID (only for use with indigo_core_flow_removed)
     * @param [out] entry_priv Private data for this flow
     */
    indigo_error_t (*entry_create)(
        void *table_priv, indigo_cxn_id_t cxn_id, of_flow_add_t *obj,
        indigo_cookie_t flow_id, void **entry_priv);

    /**
     * Modify an entry in the table
     * @param table_priv Private data passed to indigo_core_table_register
     * @param cxn_id Connection requesting this operation
     * @param entry_priv Private data returned by the entry_create operation
     * @param obj Flow-modify message
     */
    indigo_error_t (*entry_modify)(
        void *table_priv, indigo_cxn_id_t cxn_id, void *entry_priv,
        of_flow_modify_strict_t *obj);

    /**
     * Delete an entry from the table
     * @param table_priv Private data passed to indigo_core_table_register
     * @param cxn_id Connection requesting this operation
     * @param entry_priv Private data returned by the entry_create operation
     * @param [out] flow_stats Final stats
     *
     * No further operations will be called with entry_priv, so the
     * implementation should deallocate it.
     */
    indigo_error_t (*entry_delete)(
        void *table_priv, indigo_cxn_id_t cxn_id, void *entry_priv,
        indigo_fi_flow_stats_t *flow_stats);

    /**
     * Retrieve stats for an entry
     * @param table_priv Private data passed to indigo_core_table_register
     * @param cxn_id Connection requesting this operation
     * @param entry_priv Private data returned by the entry_create operation
     * @param [out] flow_stats Current stats
     */
    indigo_error_t (*entry_stats_get)(
        void *table_priv, indigo_cxn_id_t cxn_id, void *entry_priv,
        indigo_fi_flow_stats_t *flow_stats);

    /**
     * Retrieve and reset hit status for an entry
     * @param table_priv Private data passed to indigo_core_table_register
     * @param cxn_id Connection requesting this operation
     * @param entry_priv Private data returned by the entry_create operation
     * @param [out] hit_status True if entry hit since last time API was called
     */
    indigo_error_t (*entry_hit_status_get)(
        void *table_priv, indigo_cxn_id_t cxn_id, void *entry_priv,
        bool *hit_status);

    /**
     * Retrieve table stats
     * @param table_priv Private data passed to indigo_core_table_register
     * @param cxn_id Connection requesting this operation
     * @param [out] table_stats Current stats
     */
    indigo_error_t (*table_stats_get)(
        void *table_priv, indigo_cxn_id_t cxn_id,
        indigo_fi_table_stats_t *table_stats);
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


/****************************************************************
 *
 * Group table registration
 *
 * Instead of implementing indigo_fwd_group_*, the Forwarding module can
 * use this interface to register individual tables. The advantage
 * is that the Forwarding module doesn't need to do the dispatch
 * to the table implementation itself. In the future, indigo_group_*
 * will be removed.
 *
 * These interfaces largely map to the OpenFlow group-mod message, but with a
 * few differences for easier Forwarding implementation:
 *
 *  - Delete of OFPG_ALL is turned into a series of deletes of single groups.
 *  - Modify with a changed type is turned into a delete and add.
 *
 * If Forwarding uses this interface exclusively then it does not
 * need to maintain a hashtable keyed on group ID.
 *
 * Because OpenFlow does not include multiple group tables, we use the upper 8
 * bits of the group ID as the table ID.
 *
 * This is intended to be used in conjunction with the Indigo
 * forwarding pipeline interface. When indigo_fwd_pipeline_set is
 * called all tables must first be unregistered, then the tables
 * of the new pipeline must be registered.
 *
 ****************************************************************/

/**
 * Group table operations
 */

typedef struct indigo_core_group_table_ops_s {
    /**
     * Add an entry to the table
     * @param table_priv Private data passed to indigo_core_group_table_register
     * @param cxn_id Connection requesting this operation
     * @param id Group ID
     * @param group_type OpenFlow group type
     * @param buckets LOCI bucket list
     * @param [out] entry_priv Private data for this group
     */
    indigo_error_t (*entry_create)(
        void *table_priv, indigo_cxn_id_t cxn_id,
        uint32_t group_id, uint8_t group_type, of_list_bucket_t *buckets,
        void **entry_priv);

    /**
     * Modify an entry in the table
     * @param table_priv Private data passed to indigo_core_group_table_register
     * @param cxn_id Connection requesting this operation
     * @param entry_priv Private data returned by the entry_create operation
     * @param buckets LOCI bucket list
     */
    indigo_error_t (*entry_modify)(
        void *table_priv, indigo_cxn_id_t cxn_id, void *entry_priv,
        of_list_bucket_t *buckets);

    /**
     * Delete an entry from the table
     * @param table_priv Private data passed to indigo_core_group_table_register
     * @param cxn_id Connection requesting this operation
     * @param entry_priv Private data returned by the entry_create operation
     *
     * No further operations will be called with entry_priv, so the
     * implementation should deallocate it.
     */
    indigo_error_t (*entry_delete)(
        void *table_priv, indigo_cxn_id_t cxn_id, void *entry_priv);

    /**
     * Retrieve stats for an entry
     * @param table_priv Private data passed to indigo_core_group_table_register
     * @param entry_priv Private data returned by the entry_create operation
     * @param stats LOCI of_group_stats_entry_t to be filled in with stats
     */
    indigo_error_t (*entry_stats_get)(
        void *table_priv, void *entry_priv,
        of_group_stats_entry_t *stats);
} indigo_core_group_table_ops_t;

/**
 * Register a group table
 *
 * The table ID and name must be unique. The ops must be valid at least until
 * the table is unregistered. 'table_priv' will be passed to every operation on
 * the table.
 *
 * Existing groups with the same table ID will be deleted.
 */
void indigo_core_group_table_register(
    uint8_t table_id,
    const char *name,
    const indigo_core_group_table_ops_t *ops,
    void *table_priv);

/**
 * Unregister a group table
 *
 * Existing entries will be deleted.
 */
void indigo_core_group_table_unregister(uint8_t table_id);

/**
 * Acquire a reference to a group
 *
 * Returns the priv pointer returned by the entry_create operation.
 *
 * All references acquired by this function must be released before
 * OFStateManager will allow the group to be destroyed.
 *
 * This is used when a flow or another group references a group. The
 * referenced group will not be allowed to be deleted until all
 * flows/groups referencing it are deleted (or modified to not reference
 * the group). This prevents dangling references in the forwarding hardware
 * or software.
 */
void *indigo_core_group_acquire(uint32_t group_id);

/**
 * Release a reference to a group
 */
void indigo_core_group_release(uint32_t group_id);

/**
 * Lookup a group
 *
 * Returns the priv pointer returned by the entry_create operation.
 *
 * Does not increment the group's reference count, so the returned pointer
 * must not be used after returning to the event loop.
 */
void *indigo_core_group_lookup(uint32_t group_id);


/****************************************************************
 * Port/Queue registration
 ****************************************************************/

/* Opaque handle for a port */
struct ind_core_port;

/* Opaque handle for a queue */
struct ind_core_queue;

/**
 * Register a port
 */
void
indigo_core_port_register(of_port_no_t port_no, struct ind_core_port **handle);

/**
 * Unregister a port
 */
void
indigo_core_port_unregister(struct ind_core_port *handle);

/**
 * Register a queue
 */
void
indigo_core_queue_register(of_port_no_t port_no, uint32_t queue_id, struct ind_core_queue **handle);

/**
 * Unregister a queue
 */
void
indigo_core_queue_unregister(struct ind_core_queue *handle);

/****************************************************************
 * Generic stats
 ****************************************************************/

/**
 * Handle a generic stats request
 * @param cxn_id Connection ID
 * @param req Request message
 * @param priv Private data passed to indigo_core_generic_stats_register
 *
 * This function should send one or more generic stats reply messages,
 * setting the OFPSF_REQ_MORE flag on all but the last. It can spawn
 * a long running task if necessary.
 */
typedef void (*indigo_core_generic_stats_f)(
    indigo_cxn_id_t cxn_id,
    of_bsn_generic_stats_request_t *req,
    void *priv);

/**
 * @brief Register a generic stats request
 * @param name Name of the stats request
 * @param handler Function pointer called when stats request is received
 * @param priv Private data passed to handler
 */
void
indigo_core_generic_stats_register(
    const char *name,
    indigo_core_generic_stats_f handler,
    void *priv);

/**
 * @brief Unregister a generic stats request
 * @param name Name of the stats request
 */
void
indigo_core_generic_stats_unregister(const char *name);

#endif /* _INDIGO_OF_STATE_MANAGER_H_ */
/** @} */
