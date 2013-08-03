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
 * @brief First line of defense against OpenFlow messages
 *
 * See detailed documentation in the Indigo architecture headers.
 */

#include "ofstatemanager_log.h"

#include <OFStateManager/ofstatemanager_config.h>
#include <OFConnectionManager/ofconnectionmanager.h>
#include <indigo/indigo.h>
#include <indigo/of_state_manager.h>
#include <indigo/port_manager.h>
#include <indigo/forwarding.h>
#include <loci/loci.h>
#include <loci/loci_obj_dump.h>
#include "ofstatemanager_decs.h"
#include "ofstatemanager_int.h"
#include "handlers.h"
#include "ft.h"

typedef struct ptr_cxn_wrapper_s {
    void *req; /**< Generic request pointer, usually a LOXI object */
    void *reply; /**< Generic reply pointer, usually a LOXI object */
    indigo_cxn_id_t cxn_id; /**< The connection ID for the operation */
    ft_entry_t      *entry;
    int expected_count; /**< Number of callbacks expected */
    int received_count; /**< Number of callbacks received so far */
} ptr_cxn_wrapper_t;

/****************************************************************
 *
 * Utility functions
 *
 ****************************************************************/

/**
 * Wrapper for a callback pair of a generic pointer and a connection id
 * For some operations, multiple callbacks occur.  Bookkeeping variables
 * are included for these, but are not used by all operations.
 */

/**
 * Init function for cookie wrapper
 */

static ptr_cxn_wrapper_t *
setup_ptr_cxn(void *req,
              void *reply,
              indigo_cxn_id_t cxn_id,
              ft_entry_t *entry
              )
{
    ptr_cxn_wrapper_t *ptr_cxn;
    if ((ptr_cxn = INDIGO_MEM_ALLOC(sizeof(*ptr_cxn))) == NULL) {
        return NULL;
    }

    ptr_cxn->req = req;
    ptr_cxn->reply = reply;
    ptr_cxn->cxn_id = cxn_id;
    ptr_cxn->entry  = entry;
    ptr_cxn->expected_count = 1;
    ptr_cxn->received_count = 0;

    return ptr_cxn;
}

int
ind_core_xid_alloc(void)
{
    static uint32_t xid = 1000;

    return xid++;
}

/****************************************************************
 *
 * Message handling
 *
 ****************************************************************/

/**
 * Function for unhandled message
 */
indigo_error_t
ind_core_unhandled_message(of_object_t *obj, indigo_cxn_id_t cxn_id)
{
    uint32_t xid = 0;

    LOG_ERROR("Unhandled message %p from %d.  Object id %d",
              obj, cxn_id, obj->object_id);

    of_object_xid_get(obj, &xid);
    /* Generate error message */
    if (indigo_cxn_send_error_msg(obj->version, cxn_id, xid,
                                  OF_ERROR_TYPE_BAD_REQUEST,
                                  OF_REQUEST_FAILED_BAD_TYPE, NULL) < 0) {
        LOG_ERROR("Error sending error message for unhandled msg, cxn id %d",
                  cxn_id);
    }

    of_object_delete(obj);

    return INDIGO_ERROR_UNKNOWN;
}

/****************************************************************/

/**
 * Handle a hello message
 * @param cxn_id Connection handler for the owning connection
 * @param _obj Generic type object for the message to be coerced
 * @returns Error code
 */

indigo_error_t
ind_core_hello_handler(of_object_t *_obj, indigo_cxn_id_t cxn_id)
{
    LOG_TRACE("Received HELLO message from %d", cxn_id);

    of_object_delete(_obj);

    return INDIGO_ERROR_NONE;
}

/****************************************************************/

/**
 * Handle a packet_out message
 * @param cxn_id Connection handler for the owning connection
 * @param _obj Generic type object for the message to be coerced
 * @returns Error code
 *
 * Note:  Deletes packet out object, so data from obj should be copied
 */

indigo_error_t
ind_core_packet_out_handler(of_object_t *_obj, indigo_cxn_id_t cxn_id)
{
    of_packet_out_t *obj;

    obj = (of_packet_out_t *)_obj;
    LOG_TRACE("Handling of_packet_out message: %p.", obj);

    (void)indigo_fwd_packet_out(obj);

    of_packet_out_delete(obj);

    return INDIGO_ERROR_NONE;
}

/****************************************************************/

/**
 * Handle a port_mod message
 * @param cxn_id Connection handler for the owning connection
 * @param _obj Generic type object for the message to be coerced
 * @returns Error code
 */

indigo_error_t
ind_core_port_mod_handler(of_object_t *_obj, indigo_cxn_id_t cxn_id)
{
    ptr_cxn_wrapper_t *ptr_cxn;
    of_port_mod_t *obj;
    indigo_cookie_t cookie;

    if ((ptr_cxn = setup_ptr_cxn(_obj, NULL, cxn_id, 0)) == NULL) {
        LOG_ERROR("Could not alloc transfer data for port mod");
        of_object_delete(_obj);
        return INDIGO_ERROR_RESOURCE;
    }
    cookie = INDIGO_POINTER_TO_COOKIE(ptr_cxn);

    obj = (of_port_mod_t *)_obj;
    LOG_TRACE("Handling of_port_mod message: %p.", obj);

    indigo_port_modify(obj, cookie);

    return INDIGO_ERROR_NONE;
}


void
indigo_core_port_modify_callback(indigo_error_t result,
                                 indigo_cookie_t cookie)
{
    ptr_cxn_wrapper_t *ptr_cxn;
    of_port_mod_t *obj;

    if (!ind_core_init_done) {
        return;
    }

    LOG_TRACE("Port modify callback with result %d", result);
    ptr_cxn = INDIGO_COOKIE_TO_POINTER(cookie);
    obj = (of_port_mod_t *)ptr_cxn->req;

    if (result != INDIGO_ERROR_NONE) {
        of_version_t ver = obj->version;
        uint32_t xid = 0;

        LOG_ERROR("Received error %d from port modify callback", result);
        of_port_mod_xid_get(obj, &xid);
        if (ind_core_send_error_msg(ver, ptr_cxn->cxn_id, xid,
                OF_ERROR_TYPE_PORT_MOD_FAILED_BY_VERSION(ver),
                OF_PORT_MOD_FAILED_BAD_PORT, obj, NULL) < 0) {
            LOG_ERROR("Error sending port mod error message");
        }
    }

    of_port_mod_delete((of_port_mod_t *) ptr_cxn->req);
    INDIGO_MEM_FREE(ptr_cxn);
}

/****************************************************************/

/**
 * Handle a port_stats_request message
 * @param cxn_id Connection handler for the owning connection
 * @param _obj Generic type object for the message to be coerced
 * @returns Error code
 */

indigo_error_t
ind_core_port_stats_request_handler(of_object_t *_obj, indigo_cxn_id_t cxn_id)
{
    of_port_stats_request_t *obj;
    indigo_cookie_t cookie;
    ptr_cxn_wrapper_t *ptr_cxn;

    if ((ptr_cxn = setup_ptr_cxn(_obj, NULL, cxn_id, 0)) == NULL) {
        LOG_ERROR("Could not alloc transfer data for port stats req");
        of_object_delete(_obj);
        return INDIGO_ERROR_RESOURCE;
    }
    cookie = INDIGO_POINTER_TO_COOKIE(ptr_cxn);

    obj = (of_port_stats_request_t *)_obj;
    LOG_TRACE("Handling of_port_stats_request message: %p.", obj);

    indigo_port_stats_get(obj, cookie);

    return INDIGO_ERROR_NONE;
}


void
indigo_core_port_stats_get_callback(indigo_error_t result,
                                    of_port_stats_reply_t *reply,
                                    indigo_cookie_t cookie)
{
    ptr_cxn_wrapper_t *ptr_cxn;
    indigo_cxn_id_t cxn_id;
    int rv;
    of_port_stats_request_t *obj;
    uint32_t xid = 0;

    if (!ind_core_init_done) {
        return;
    }

    ptr_cxn = INDIGO_COOKIE_TO_POINTER(cookie);
    obj = (of_port_stats_request_t *)ptr_cxn->req;
    cxn_id = ptr_cxn->cxn_id;

    LOG_TRACE("Port stats callback for cxn %d", cxn_id);

    if (result == INDIGO_ERROR_NONE) {
        /* Set the XID to match the request */
        of_port_stats_request_xid_get(obj, &xid);
        of_port_stats_reply_xid_set(reply, xid);

        if ((rv = IND_CORE_MSG_SEND(cxn_id, reply)) < 0) {
            LOG_ERROR("Error %d sending port_stats_get reply to %d", rv, cxn_id);
        }
    } else {
        LOG_ERROR("Received error %d from port stats get callback", result);
        /* @todo sending type 0, code 0 error message */
        if (indigo_cxn_send_error_msg(obj->version, cxn_id, xid,
                                      0, 0, NULL) < 0) {
            LOG_ERROR("Error sending error message for port stats get msg, "
                      "cxn id %d", cxn_id);
        }
    }

    of_port_stats_request_delete(obj);
    INDIGO_MEM_FREE(ptr_cxn);
}

/****************************************************************/

/**
 * Handle a queue_get_config_request message
 * @param cxn_id Connection handler for the owning connection
 * @param _obj Generic type object for the message to be coerced
 * @returns Error code
 */

indigo_error_t
ind_core_queue_get_config_request_handler(of_object_t *_obj,
                                          indigo_cxn_id_t cxn_id)
{
    of_queue_get_config_request_t *obj = (of_queue_get_config_request_t *)_obj;
    indigo_cookie_t cookie;
    ptr_cxn_wrapper_t *ptr_cxn;

    if ((ptr_cxn = setup_ptr_cxn(_obj, NULL, cxn_id, 0)) == NULL) {
        LOG_ERROR("Could not alloc transfer data for queue config req");
        of_object_delete(_obj);
        return INDIGO_ERROR_RESOURCE;
    }
    cookie = INDIGO_POINTER_TO_COOKIE(ptr_cxn);

    LOG_TRACE("Handling of_queue_get_config_request message: %p.", obj);
    indigo_port_queue_config_get(obj, cookie);

    return INDIGO_ERROR_NONE;
}


void
indigo_core_queue_config_get_callback(indigo_error_t result,
                                      of_queue_get_config_reply_t *reply,
                                      indigo_cookie_t cookie)
{
    ptr_cxn_wrapper_t *ptr_cxn;
    indigo_cxn_id_t cxn_id;
    int rv;
    of_queue_get_config_request_t *request;
    uint32_t xid;

    if (!ind_core_init_done) {
        return;
    }

    ptr_cxn = INDIGO_COOKIE_TO_POINTER(cookie);
    request = (of_queue_get_config_request_t *)ptr_cxn->req;
    cxn_id = ptr_cxn->cxn_id;
    of_queue_get_config_request_xid_get(request, &xid);

    LOG_TRACE("Queue config callback");

    if (result == INDIGO_ERROR_NONE) {
        of_port_no_t port;

        of_queue_get_config_reply_xid_set(reply, xid);

        of_queue_get_config_request_port_get(request, &port);
        of_queue_get_config_reply_port_set(reply, port);

        if ((rv = IND_CORE_MSG_SEND(cxn_id, reply)) < 0) {
            LOG_ERROR("Error %d sending port_stats_get reply to %d", rv, cxn_id);
        }
    } else {
        LOG_ERROR("Received error %d from queue config get callback", result);
        /* @todo sending type 0, code 0 error message */
        if (indigo_cxn_send_error_msg(request->version, cxn_id, xid,
                                      0, 0, NULL) < 0) {
            LOG_ERROR("Error sending error message for queue config get msg, "
                      "cxn id %d", cxn_id);
        }
    }

    of_queue_get_config_request_delete(request);
    INDIGO_MEM_FREE(ptr_cxn);
}

/****************************************************************/

/**
 * Handle a queue_stats_request message
 * @param cxn_id Connection handler for the owning connection
 * @param _obj Generic type object for the message to be coerced
 * @returns Error code
 */

indigo_error_t
ind_core_queue_stats_request_handler(of_object_t *_obj, indigo_cxn_id_t cxn_id)
{
    of_queue_stats_request_t *obj;
    indigo_cookie_t cookie;
    ptr_cxn_wrapper_t *ptr_cxn;

    obj = (of_queue_stats_request_t *)_obj;
    LOG_TRACE("Handling of_queue_stats_request message: %p.", obj);

    if ((ptr_cxn = setup_ptr_cxn(_obj, NULL, cxn_id, 0)) == NULL) {
        LOG_ERROR("Could not alloc transfer data for queue stats req");
        of_object_delete(_obj);
        return INDIGO_ERROR_RESOURCE;
    }
    cookie = INDIGO_POINTER_TO_COOKIE(ptr_cxn);

    /* Handle object of type of_queue_stats_request_t */
    indigo_port_queue_stats_get(obj, cookie);

    return INDIGO_ERROR_NONE;
}

void
indigo_core_queue_stats_get_callback(indigo_error_t result,
                                     of_queue_stats_reply_t *reply,
                                     indigo_cookie_t cookie)
{
    ptr_cxn_wrapper_t *ptr_cxn;
    indigo_cxn_id_t cxn_id;
    int rv;
    of_queue_stats_request_t* obj;
    uint32_t xid;

    if (!ind_core_init_done) {
        return;
    }

    ptr_cxn = INDIGO_COOKIE_TO_POINTER(cookie);
    obj = ptr_cxn->req;
    cxn_id = ptr_cxn->cxn_id;
    of_queue_stats_request_xid_get(obj, &xid);

    LOG_TRACE("Queue stats callback");

    if (result == INDIGO_ERROR_NONE) {
        /* Set the XID to match the request */
        of_queue_stats_reply_xid_set(reply, xid);

        if ((rv = IND_CORE_MSG_SEND(cxn_id, reply)) < 0) {
            LOG_ERROR("Error %d sending queue_stats reply to %d", rv, cxn_id);
            of_queue_stats_reply_delete(reply);
        }
    } else {
        LOG_ERROR("Received error %d from queue stats get callback", result);
        /* @todo sending type 0, code 0 error message */
        if (indigo_cxn_send_error_msg(obj->version, cxn_id, xid,
                                      0, 0, NULL) < 0) {
            LOG_ERROR("Error sending error message for queue stats get msg, "
                      "cxn id %d", cxn_id);
        }
    }

    of_queue_stats_request_delete(ptr_cxn->req);
    INDIGO_MEM_FREE(ptr_cxn);
}


static void
req_enqueue(ft_entry_t *entry, ptr_cxn_wrapper_t *ptr_cxn)
{
   entry->queued_reqs = biglist_append(entry->queued_reqs, ptr_cxn);
}

/*
 * An operation on an entry has completed.  Check the queue for other
 * pending operations.  Note that the second check is to see if the
 * entry was deleted and process that deletion if so.
 */

static void
queued_req_service(ft_entry_t *entry)
{
    biglist_t         *ble;
    ptr_cxn_wrapper_t *ptr_cxn;

    if (entry->state > FT_FLOW_STATE_DELETE_MARKED) {
        /* entry delete already processed, pending result */
        return;
    }

    if (entry->state == FT_FLOW_STATE_DELETE_MARKED) { /* entry deleted */
        LOG_TRACE("Queued req: removing flow " INDIGO_FLOW_ID_PRINTF_FORMAT,
                  INDIGO_FLOW_ID_PRINTF_ARG(entry->id));

        entry->state = FT_FLOW_STATE_DELETING;
        indigo_fwd_flow_delete(entry->id, INDIGO_POINTER_TO_COOKIE(entry));
        return;
    }

    /* Mark entry as stable */
    entry->state = FT_FLOW_STATE_CREATED;
    if ((ble = entry->queued_reqs) == 0) { /* No ops pending */
        return;
    }

    /* Start next modify operation */
    ptr_cxn = BIGLIST_CAST(ptr_cxn_wrapper_t *, ble);
    entry->queued_reqs = biglist_remove(entry->queued_reqs, ptr_cxn);
    entry->state = FT_FLOW_STATE_MODIFYING;

    indigo_fwd_flow_modify(entry->id, ptr_cxn->req,
                           INDIGO_POINTER_TO_COOKIE(ptr_cxn));
}

/****************************************************************/

static indigo_error_t
flow_mod_setup_query(of_flow_modify_t *obj, /* Works with add, mod, del */
                     of_meta_match_t *query,
                     int query_mode,
                     int force_wildcard_port)
{
    INDIGO_MEM_SET(query, 0, sizeof(*query));
    query->table_id = TABLE_ID_ANY;
    _TRY(of_flow_modify_match_get(obj, &(query->match)));
    query->mode = query_mode;
    if ((query_mode == OF_MATCH_STRICT) || (query_mode == OF_MATCH_OVERLAP)) {
        query->check_priority = 1;
        of_flow_add_priority_get(obj, &(query->priority));
    }
    if (force_wildcard_port) {
        query->out_port = OF_PORT_DEST_WILDCARD;
    } else {
        /* Could check object_id is delete or delete_strict */
        of_flow_add_out_port_get(obj, &(query->out_port));
    }

    return INDIGO_ERROR_NONE;
}

/**
 * @brief Check if overlap is found with the flow modify object
 *
 * Return 1 if overlap found, 0 if not found, <0 on error
 */

static int
overlap_found(of_flow_modify_t *obj)
{
    of_meta_match_t query;
    indigo_error_t rv;

    _TRY(flow_mod_setup_query(obj, &query, OF_MATCH_OVERLAP, 1));
    rv = ft_first_match(ind_core_ft, &query, NULL);

    if (rv == INDIGO_ERROR_NONE) {
        return 1;
    } else if (rv == INDIGO_ERROR_NOT_FOUND) {
        return 0;
    }

    return rv;
}

static indigo_flow_id_t
flow_id_next(void)
{
    static indigo_flow_id_t next_flow_id = 1;

    indigo_flow_id_t result = next_flow_id;

    if (++next_flow_id == 0)  next_flow_id = 1;

    return (result);
}

/**
 * Handle a flow_add message
 * @param cxn_id Connection handler for the owning connection
 * @param _obj Generic type object for the message to be coerced
 * @returns Error code
 */

indigo_error_t
ind_core_flow_add_handler(of_object_t *_obj, indigo_cxn_id_t cxn_id)
{
    indigo_error_t result = INDIGO_ERROR_NONE;
    of_flow_modify_t *obj; /* Coerce to modify object */
    indigo_cookie_t cookie;
    of_meta_match_t query;
    uint16_t flags;
    of_version_t ver;
    uint32_t xid = 0;
    ptr_cxn_wrapper_t *ptr_cxn = 0;
    ft_entry_t        *entry = 0;
    unsigned char     overlapf = 0;
    indigo_flow_id_t  flow_id;
    uint16_t idle_timeout, hard_timeout;

    obj = (of_flow_modify_t *)_obj;
    ver = obj->version;
    LOG_TRACE("Handling of_flow_add message: %p, ver %d.", obj, ver);

    of_flow_modify_flags_get(obj, &flags);

    (void)of_flow_modify_xid_get(obj, &xid);
    if (flags & OF_FLOW_MOD_FLAG_CHECK_OVERLAP_BY_VERSION(ver)) {
        if (overlap_found(obj)) {
            LOG_TRACE("Overlap found when adding flow");
            if (ind_core_send_error_msg(ver, cxn_id, xid,
                    OF_ERROR_TYPE_FLOW_MOD_FAILED_BY_VERSION(ver),
                    OF_FLOW_MOD_FAILED_OVERLAP_BY_VERSION(ver),
                    obj, NULL) < 0) {
                LOG_ERROR("Error sending overlap error message");
            }
            overlapf = 1;
            goto done;
        }
    }

    (void)of_flow_modify_idle_timeout_get(obj, &idle_timeout);
    (void)of_flow_modify_hard_timeout_get(obj, &hard_timeout);
    if ((flags & OF_FLOW_MOD_FLAG_EMERG_BY_VERSION(ver)) &&
        (idle_timeout != 0 || hard_timeout != 0)) {
        LOG_TRACE("Attempted to set timeout on an emergency flow");
        if (ind_core_send_error_msg(ver, cxn_id, xid,
                OF_ERROR_TYPE_FLOW_MOD_FAILED_BY_VERSION(ver),
                OF_FLOW_MOD_FAILED_BAD_EMERG_TIMEOUT_BY_VERSION(ver),
                obj, NULL) < 0) {
            LOG_ERROR("Error sending bad emergency timeout error message");
        }
        result = INDIGO_ERROR_PARAM;
        goto done;
    }

    /* Search table; if match found, replace entry */
    result = flow_mod_setup_query(obj, &query, OF_MATCH_STRICT, 1);
    if (result != INDIGO_ERROR_NONE) {
        LOG_ERROR("flow_mod_setup_query() failed");
        goto done;
    }

    /* Delete existing flow if any */
    if (ft_first_match(ind_core_ft, &query, &entry) == INDIGO_ERROR_NONE) {
        ind_core_flow_entry_delete(entry, INDIGO_FLOW_REMOVED_OVERWRITE);
    }

    /* No match found, add as normal */
    LOG_TRACE("Adding new flow");

    flow_id = flow_id_next();

    result = ft_add(ind_core_ft, flow_id, obj, &entry);
    if (result != INDIGO_ERROR_NONE) {
        LOG_ERROR("ft_add() failed");
        goto done;
    }

    if ((ptr_cxn = setup_ptr_cxn(_obj, NULL, cxn_id, entry)) == NULL) {
        LOG_ERROR("Could not alloc transfer data for flow create req");
        result = INDIGO_ERROR_RESOURCE;
        goto done;
    }
    cookie = INDIGO_POINTER_TO_COOKIE(ptr_cxn);
    indigo_fwd_flow_create(flow_id, (of_flow_add_t *)obj, cookie);

 done:
    if (result != INDIGO_ERROR_NONE || overlapf) {
        if (ptr_cxn)  INDIGO_MEM_FREE(ptr_cxn);
        if (entry)    ft_delete(ind_core_ft, entry);
        of_object_delete(_obj);
    }

    return INDIGO_ERROR_NONE;
}

/**
 * Translate the error status into the correct error code for the given
 * OpenFlow version, and send the error message to the controller.
 * @param indigo_err Error status
 * @param ver OpenFlow version
 * @param cxn_id Connection to send to
 * @param flow_mod Request that failed
 */

static void
flow_mod_err_msg_send(indigo_error_t indigo_err, of_version_t ver,
                      indigo_cxn_id_t cxn_id, of_flow_modify_t *flow_mod)
{
    unsigned char errmsgf = 0;
    unsigned code;
    uint32_t xid;

    of_flow_modify_xid_get(flow_mod, &xid);

    switch (indigo_err) {
    case INDIGO_ERROR_NONE:
        break;

    case INDIGO_ERROR_RESOURCE:
        code    = OF_FLOW_MOD_FAILED_ALL_TABLES_FULL_BY_VERSION(ver);
        /* @fixme this will return the wrong code for ver >1.0 */
        errmsgf = 1;
        break;

    case INDIGO_ERROR_NOT_SUPPORTED:
        code    = OF_FLOW_MOD_FAILED_UNSUPPORTED_BY_VERSION(ver);
        /* @fixme this will return the wrong code for ver >1.0 */
        errmsgf = 1;
        break;

    default:
        code    = OF_FLOW_MOD_FAILED_EPERM_BY_VERSION(ver);
        /* @fixme use OF_FLOW_MOD_FAILED_UNKNOWN for ver >1.0 */
        errmsgf = 1;
    }

    if (errmsgf) {
        int rv;

        rv = ind_core_send_error_msg(ver, cxn_id, xid,
            OF_ERROR_TYPE_FLOW_MOD_FAILED_BY_VERSION(ver),
            code, flow_mod, NULL);
        if (INDIGO_FAILURE(rv)) {
            LOG_ERROR("Error sending flow mod error message");
        }
    }
}

void
indigo_core_flow_create_callback(indigo_error_t result,
                                 indigo_cookie_t flow_id,
                                 uint8_t table_id,
                                 indigo_cookie_t cookie)
{
    ptr_cxn_wrapper_t *ptr_cxn;
    indigo_cxn_id_t cxn_id;
    of_flow_add_t *flow_add;
    ft_entry_t    *entry;

    if (!ind_core_init_done) {
        return;
    }

    LOG_TRACE("Flow create callback: rv %d. Id "
              INDIGO_COOKIE_PRINTF_FORMAT, result, flow_id);

    ptr_cxn = INDIGO_COOKIE_TO_POINTER(cookie);
    flow_add = (of_flow_add_t *)ptr_cxn->req;
    cxn_id = ptr_cxn->cxn_id;
    entry  = ptr_cxn->entry;

    if (result == INDIGO_ERROR_NONE) {
        LOG_TRACE("Flow table now has %d entries",
                  FT_STATUS(ind_core_ft)->current_count);
        entry->table_id = table_id;
        queued_req_service(entry);
    } else { /* Error during insertion at forwarding layer */
       uint32_t xid;

       LOG_VERBOSE("Error from forwarding while inserting flow");
       ind_core_ft->status.forwarding_add_errors += 1;

       of_flow_add_xid_get(flow_add, &xid);
       flow_mod_err_msg_send(result, flow_add->version, cxn_id,
                             (of_flow_modify_t *)flow_add);

       /* Free entry in local flow table */
       ft_delete(ind_core_ft, entry);
    }

    INDIGO_MEM_FREE(ptr_cxn);

    /* Delete the original request */
    of_flow_add_delete(flow_add);
}

/****************************************************************/

/**
 * Handle a flow_modify message
 * @param cxn_id Connection handler for the owning connection
 * @param _obj Generic type object for the message to be coerced
 * @returns Error code
 *
 * For flow modifies, we do the simplest thing which is to duplicate
 * the flow mod message for each modified entry.  (If you don't do this
 * you need track both the number of callbacks made and the original
 * message so that it is not deleted until all callbacks are completed.)
 *
 * So the handler deletes the duplicated flow mod.
 */

indigo_error_t
ind_core_flow_modify_handler(of_object_t *_obj, indigo_cxn_id_t cxn_id)
{
    indigo_error_t result = INDIGO_ERROR_NONE;
    of_flow_modify_t *obj;
    biglist_t *list = 0, *ble;
    int count;
    int rv;
    of_meta_match_t query;
    of_flow_modify_t *dup = 0;
    ptr_cxn_wrapper_t *ptr_cxn = 0;
    ft_entry_t        *entry;

    obj = (of_flow_modify_t *)_obj;
    LOG_TRACE("Handling of_flow_modify message: %p.", obj);

    /* Form the query and call mark entries */
    rv = flow_mod_setup_query(obj, &query, OF_MATCH_NON_STRICT, 1);
    if (rv != INDIGO_ERROR_NONE) {
        of_object_delete(_obj);
        return rv;
    }
    list = ft_query(ind_core_ft, &query);
    if ((count = biglist_length(list)) == 0) {
        LOG_TRACE("No entries to modify, treat as add: %p", obj);
        biglist_free(list);
        /* OpenFlow 1.0.0, section 4.6, page 14.  Treat as an add */
        return ind_core_flow_add_handler(_obj, cxn_id);
    }

    LOG_TRACE("Found %d entries to be modified", count);

    for (ble = list; ble; ble = ble->next) {
        LOG_TRACE("Flow mod entry " INDIGO_COOKIE_PRINTF_FORMAT,
                  FT_LIST_TO_FLOW_ID(ble));

        entry = FT_LIST_TO_ENTRY(ble);

        /* Flow is being deleted => Ignore modify */
        if (FT_FLOW_STATE_IS_DELETED(entry->state)) {
            LOG_TRACE("Flow being deleted -- skipping modify");
            continue;
        }

        if ((dup = of_object_dup(_obj)) == NULL) {
            LOG_ERROR("Could not allocate duplicate flow mod obj");
            result = INDIGO_ERROR_RESOURCE;
            goto done;
        }

        if ((ptr_cxn = setup_ptr_cxn(dup, 0, cxn_id, entry)) == 0) {
            LOG_ERROR("setup_ptr_cxn() failed");
            result = INDIGO_ERROR_RESOURCE;
            goto done;
        }

        /* Indicate the dup object is outstanding for the cxn instance */
        if (ind_cxn_message_track_setup(cxn_id, dup) < 0) {
            LOG_ERROR("Could not set up flow-mod msg tracking for id %d\n",
                      cxn_id);
        }
        if (FT_FLOW_STATE_IS_STABLE(entry->state)) {
            /* Flow is stable => Issue modify to forwarding */
            entry->state = FT_FLOW_STATE_MODIFYING;

            indigo_fwd_flow_modify(entry->id, dup,
                                   INDIGO_POINTER_TO_COOKIE(ptr_cxn));
        } else {
            /* Outstanding req to forwarding for flow => Queue request */
            req_enqueue(entry, ptr_cxn);
        }

        ptr_cxn = 0;
        dup     = 0;
    }

 done:
    if (result != INDIGO_ERROR_NONE) {
        if (ptr_cxn)  INDIGO_MEM_FREE(ptr_cxn);
        if (dup)      of_object_delete(dup);
    }

    if (list)  biglist_free(list);

    of_object_delete(_obj);

    return (result);
}

/**
 * Handle a flow_modify_strict message
 * @param cxn_id Connection handler for the owning connection
 * @param _obj Generic type object for the message to be coerced
 * @returns Error code
 *
 * Checks that only one entry in local table matches.  See modify_handler
 * above for more info.
 */

indigo_error_t
ind_core_flow_modify_strict_handler(of_object_t *_obj, indigo_cxn_id_t cxn_id)
{
    indigo_error_t result = INDIGO_ERROR_NONE;
    of_flow_modify_strict_t *obj;
    int rv;
    of_meta_match_t query;
    ft_entry_t        *entry;
    ptr_cxn_wrapper_t *ptr_cxn = 0;

    obj = (of_flow_modify_strict_t *)_obj;
    LOG_TRACE("Handling of_flow_modify_strict message: %p.", obj);

    /* Form the query and call mark entries */
    rv = flow_mod_setup_query(obj, &query, OF_MATCH_STRICT, 1);
    if (rv != INDIGO_ERROR_NONE) {
        of_object_delete(_obj);
        return rv;
    }

    rv = ft_first_match(ind_core_ft, &query, &entry);
    if (rv == INDIGO_ERROR_NOT_FOUND) {
        LOG_TRACE("No entries to modify strict, treat as add: %p", obj);
        /* OpenFlow 1.0.0, section 4.6, page 14.  Treat as an add */
        return ind_core_flow_add_handler(_obj, cxn_id);
    }

    if (FT_FLOW_STATE_IS_DELETED(entry->state)) {
       LOG_TRACE("Flow being deleted -- skipping modify");
       goto done;
    }

    if ((ptr_cxn = setup_ptr_cxn(obj, 0, cxn_id, entry)) == 0) {
        LOG_ERROR("setup_ptr_cxn() failed");
        result = INDIGO_ERROR_RESOURCE;
        goto done;
    }

    if (FT_FLOW_STATE_IS_STABLE(entry->state)) {
       /* Flow is stable => Issue modify to forwarding */

        entry->state = FT_FLOW_STATE_MODIFYING;

       indigo_fwd_flow_modify(entry->id,
                              obj,
                              INDIGO_POINTER_TO_COOKIE(ptr_cxn)
          );
    } else {
       /* Outstanding req to forwarding for flow => Queue request */

       req_enqueue(entry, ptr_cxn);
    }

 done:
    if (result != INDIGO_ERROR_NONE) {
        if (ptr_cxn)  INDIGO_MEM_FREE(ptr_cxn);
        of_object_delete(_obj);
    }

    return (result);
}

void
indigo_core_flow_modify_callback(indigo_error_t result,
                                 indigo_fi_flow_stats_t *flow_stats,
                                 indigo_cookie_t cookie)
{
    ptr_cxn_wrapper_t *ptr_cxn;
    ft_entry_t *entry;
    of_flow_modify_t *flow_mod;
    indigo_cxn_id_t  cxn_id;

    if (!ind_core_init_done) {
        return;
    }

    ptr_cxn = INDIGO_COOKIE_TO_POINTER(cookie);
    flow_mod = ptr_cxn->req;
    cxn_id   = ptr_cxn->cxn_id;
    entry    = ptr_cxn->entry;

    if (result == INDIGO_ERROR_NONE) {
        LOG_TRACE("Flow mod callback id " INDIGO_COOKIE_PRINTF_FORMAT,
                  entry->id);
        ft_entry_modify_effects(ind_core_ft, entry, flow_mod);
    } else {
        LOG_TRACE("Flow mod callback error, %d", result);
        flow_mod_err_msg_send(result, flow_mod->version, cxn_id, flow_mod);
    }

    of_object_delete((of_object_t *)flow_mod);
    INDIGO_MEM_FREE(ptr_cxn);

    if (!FT_FLOW_STATE_IS_DELETED(entry->state)) {
        entry->state = FT_FLOW_STATE_CREATED;
    }

    queued_req_service(entry);
}

/****************************************************************/

/* Flowtable iterator for ind_core_flow_delete_handler */
static void
delete_iter_cb(void *cookie, ft_entry_t *entry)
{
    of_object_t *obj = cookie;
    if (entry != NULL) {
        ind_core_flow_entry_delete(entry, INDIGO_FLOW_REMOVED_DELETE);
    } else {
        LOG_TRACE("Finished flow delete task");
        of_object_delete(obj);
    }
}


/**
 * Handle a flow_delete message
 * @param cxn_id Connection handler for the owning connection
 * @param _obj Generic type object for the message to be coerced
 * @returns Error code
 */

indigo_error_t
ind_core_flow_delete_handler(of_object_t *_obj, indigo_cxn_id_t cxn_id)
{
    of_flow_delete_t *flow_del;
    of_meta_match_t query;
    indigo_error_t rv;

    flow_del = (of_flow_delete_t *)_obj;
    LOG_TRACE("Handling of_flow_delete message: %p.", flow_del);

    /* Form the query and call mark entries */
    rv = flow_mod_setup_query((of_flow_modify_t *)flow_del, &query,
                              OF_MATCH_NON_STRICT, 0);
    if (rv != INDIGO_ERROR_NONE) {
        of_object_delete(_obj);
        return rv;
    }

    rv = ft_spawn_iter_task(ind_core_ft, &query, delete_iter_cb, _obj,
                            IND_SOC_DEFAULT_PRIORITY);
    if (rv != INDIGO_ERROR_NONE) {
        of_object_delete(_obj);
        return rv;
    }

    /* Ownership of _obj is passed to the iterator for barrier tracking */
    return INDIGO_ERROR_NONE;
}

/**
 * Handle a flow_delete_strict message
 * @param cxn_id Connection handler for the owning connection
 * @param _obj Generic type object for the message to be coerced
 * @returns Error code
 */

indigo_error_t
ind_core_flow_delete_strict_handler(of_object_t *_obj, indigo_cxn_id_t cxn_id)
{
    of_flow_delete_strict_t *obj;
    int rv;
    of_meta_match_t query;
    ft_entry_t *entry;

    obj = (of_flow_delete_strict_t *)_obj;
    LOG_TRACE("Handling of_flow_delete_strict message: %p.", obj);

    /* Form the query and call mark entries */
    rv = flow_mod_setup_query((of_flow_modify_t *)obj, &query, OF_MATCH_STRICT, 0);
    if (rv != INDIGO_ERROR_NONE) {
        of_object_delete(_obj);
        return rv;
    }

    if (ft_first_match(ind_core_ft, &query, &entry) == INDIGO_ERROR_NONE) {
        ind_core_flow_entry_delete(entry, INDIGO_FLOW_REMOVED_DELETE);
    }

    of_object_delete(_obj);
    return INDIGO_ERROR_NONE;
}


/****************************************************************/

static indigo_error_t
get_config_reply_setup(of_get_config_reply_t *reply, of_get_config_request_t *req)
{
    uint32_t xid;

    of_get_config_reply_flags_set(reply, ind_core_of_config.flags);
    of_get_config_reply_miss_send_len_set(reply,
         ind_core_of_config.miss_send_len);

    of_get_config_request_xid_get(req, &xid);
    of_get_config_reply_xid_set(reply, xid);

    return INDIGO_ERROR_NONE;
}

/**
 * Handle a get_config_request message
 * @param cxn_id Connection handler for the owning connection
 * @param _obj Generic type object for the message to be coerced
 * @returns Error code
 */

indigo_error_t
ind_core_get_config_request_handler(of_object_t *_obj, indigo_cxn_id_t cxn_id)
{
    of_get_config_request_t *obj;
    of_get_config_reply_t *reply = NULL;
    int rv;

    obj = (of_get_config_request_t *)_obj;
    LOG_TRACE("Handling of_get_config_request message: %p.", obj);

    /* Allocate reply */
    reply = of_get_config_reply_new(obj->version);
    if (reply == NULL) {
        LOG_TRACE("Could not alloc get_config_reply.");
        of_object_delete(_obj);
        return INDIGO_ERROR_RESOURCE;
    }

    rv = get_config_reply_setup(reply, obj);
    if (rv != INDIGO_ERROR_NONE) {
        of_get_config_reply_delete(reply);
        of_object_delete(_obj);
        return rv;
    }

    rv = IND_CORE_MSG_SEND(cxn_id, reply);

    /* If error, free the reply pointer */
    if (rv != INDIGO_ERROR_NONE) {
        of_get_config_reply_delete(reply);
    }
    of_object_delete(_obj);

    return INDIGO_ERROR_NONE;
}

/****************************************************************/

struct ind_core_flow_stats_priv {
    indigo_cxn_id_t cxn_id;
    of_flow_stats_request_t *req;
    indigo_time_t current_time;
    of_flow_stats_reply_t *reply;
};

static void
ind_core_flow_stats_request_cb(struct ind_core_flow_stats_state *state,
                               indigo_fi_flow_stats_t *flow_stats)
{
    struct ind_core_flow_stats_priv *priv = (struct ind_core_flow_stats_priv *)(state + 1);
    ft_entry_t *entry;
    uint32_t secs, nsecs;

    /* Allocate a reply if we don't already have one. */
    if (priv->reply == NULL) {
        uint32_t xid;

        priv->reply = of_flow_stats_reply_new(priv->req->version);
        if (priv->reply == NULL) {
            LOG_ERROR("Failed to allocate of_flow_stats_reply.");
            if (flow_stats == NULL) {
                of_flow_stats_request_delete(priv->req);
            }
            return;
        }

        of_flow_stats_request_xid_get(priv->req, &xid);
        of_flow_stats_reply_xid_set(priv->reply, xid);
        of_flow_stats_reply_flags_set(priv->reply, 1);
    }

    if (flow_stats == NULL) {
        /* Send last reply */
        of_flow_stats_reply_flags_set(priv->reply, 0);
        IND_CORE_MSG_SEND(priv->cxn_id, priv->reply);

        /* Clean up state */
        of_flow_stats_request_delete(priv->req);
        return;
    }

    entry = ft_lookup(ind_core_ft, flow_stats->flow_id);
    if (entry == NULL) {
        LOG_ERROR("failed to lookup flow during flow_stats callback");
        return;
    }

    /* TODO use time from flow_stats? */
    calc_duration(priv->current_time, entry->insert_time, &secs, &nsecs);

    /* Set up the structures to append an entry to the list */
    {
        of_list_flow_stats_entry_t list;
        of_flow_stats_entry_t stats_entry;
        of_flow_stats_reply_entries_bind(priv->reply, &list);
        of_flow_stats_entry_init(&stats_entry, priv->reply->version, -1, 1);
        if (of_list_flow_stats_entry_append_bind(&list, &stats_entry)) {
            LOG_ERROR("failed to append to flow stats list during flow_stats callback");
            return;
        }

        /* Populate the entry */
        if (of_flow_stats_entry_setup_from_flow_add(&stats_entry,
                                                    entry->flow_add,
                                                    entry->effects.actions)) {
            LOG_ERROR("failed to setup flow stats entry during flow_stats callback");
            return;
        }
        of_flow_stats_entry_table_id_set(&stats_entry, entry->table_id);
        of_flow_stats_entry_duration_sec_set(&stats_entry, secs);
        of_flow_stats_entry_duration_nsec_set(&stats_entry, nsecs);
        of_flow_stats_entry_packet_count_set(&stats_entry, flow_stats->packets);
        of_flow_stats_entry_byte_count_set(&stats_entry, flow_stats->bytes);
    }

    if (priv->reply->length > (1 << 15)) { /* Last object would get too big */
        IND_CORE_MSG_SEND(priv->cxn_id, priv->reply);
        priv->reply = NULL;
    }
}

/**
 * Handle a flow_stats_request message
 * @param _obj Generic type object for the message to be coerced
 * @param cxn_id Connection handler for the owning connection
 * @returns Error code
 */

indigo_error_t
ind_core_flow_stats_request_handler(of_object_t *_obj, indigo_cxn_id_t cxn_id)
{
    of_flow_stats_request_t *obj;
    of_meta_match_t query;
    struct ind_core_flow_stats_state *state;
    struct ind_core_flow_stats_priv *priv;
    ft_entry_t *entry;
    list_links_t *cur, *next;

    obj = (of_flow_stats_request_t *)_obj;
    LOG_TRACE("Handling of_flow_stats_request message: %p.", obj);

    /* Set up the query structure */
    INDIGO_MEM_SET(&query, 0, sizeof(query));
    if (of_flow_stats_request_match_get(obj, &(query.match)) < 0) {
        return INDIGO_ERROR_UNKNOWN;
    }
    of_flow_stats_request_out_port_get(obj, &(query.out_port));
    of_flow_stats_request_table_id_get(obj, &(query.table_id));

    /* Non strict; do not check priority, cookie or overlap */
    query.mode = OF_MATCH_NON_STRICT;

    state = INDIGO_MEM_ALLOC(sizeof(*state) + sizeof(*priv));
    if (state == NULL) {
       LOG_ERROR("Failed to allocate flow stats state object.");
       of_object_delete(_obj);
       return INDIGO_ERROR_RESOURCE;
    }

    state->finished_calls = 0;
    state->expected_count = 0;
    state->received_count = 0;
    state->callback = ind_core_flow_stats_request_cb;

    priv = (struct ind_core_flow_stats_priv *)(state + 1);
    priv->req = obj; /* ownership transferred */
    priv->cxn_id = cxn_id;
    priv->current_time = INDIGO_CURRENT_TIME;
    priv->reply = NULL;

    /*
     * Iterate over flow table; query stats for each entry.
     *
     * indigo_core_flow_stats_get_callback will generate the replies.
     */
    FT_ITER(ind_core_ft, entry, cur, next) {
       if (!FT_FLOW_STATE_IS_DELETED(entry->state) &&
               ft_entry_meta_match(&query, entry)) {
           state->expected_count++;
           indigo_fwd_flow_stats_get(entry->id,
                                     INDIGO_POINTER_TO_COOKIE(state));
        }
    }

    indigo_core_flow_stats_get_callback(INDIGO_ERROR_NONE, NULL,
                                        INDIGO_POINTER_TO_COOKIE(state));

    return INDIGO_ERROR_NONE;
}

/****************************************************************/

/**
 * Handle a echo_reply message
 * @param cxn_id Connection handler for the owning connection
 * @param _obj Generic type object for the message to be coerced
 * @returns Error code
 */

indigo_error_t
ind_core_echo_reply_handler(of_object_t *_obj, indigo_cxn_id_t cxn_id)
{
    of_echo_reply_t *obj;

    obj = (of_echo_reply_t *)_obj;
    LOG_TRACE("Handling of_echo_reply message: %p.", obj);

    /* Handle object of type of_echo_reply_t */

    return INDIGO_ERROR_NONE;
}

/****************************************************************/

struct ind_core_aggregate_stats_priv {
    uint64_t packets;
    uint64_t bytes;
    uint32_t flows;
    indigo_cxn_id_t cxn_id;
    of_aggregate_stats_request_t *req;
};

static void
ind_core_aggregate_stats_request_cb(struct ind_core_flow_stats_state *state,
                                    indigo_fi_flow_stats_t *flow_stats)
{
    struct ind_core_aggregate_stats_priv *priv = (struct ind_core_aggregate_stats_priv *)(state + 1);

    if (flow_stats != NULL) {
        priv->bytes += flow_stats->bytes;
        priv->packets += flow_stats->packets;
        priv->flows += 1;
    } else {
        uint32_t xid;
        of_aggregate_stats_reply_t* reply;
        of_aggregate_stats_request_xid_get(priv->req, &xid);
        reply = of_aggregate_stats_reply_new(priv->req->version);
        if (reply != NULL) {
            of_aggregate_stats_reply_xid_set(reply, xid);
            of_aggregate_stats_reply_byte_count_set(reply, priv->bytes);
            of_aggregate_stats_reply_packet_count_set(reply, priv->packets);
            of_aggregate_stats_reply_flow_count_set(reply, priv->flows);
            IND_CORE_MSG_SEND(priv->cxn_id, reply);
        } else {
            LOG_ERROR("Failed to allocate aggregate stats reply.");
        }
        of_aggregate_stats_request_delete(priv->req);
    }
}

/**
 * Handle a aggregate_stats_request message
 * @param cxn_id Connection handler for the owning connection
 * @param _obj Generic type object for the message to be coerced
 * @returns Error code
 */

indigo_error_t
ind_core_aggregate_stats_request_handler(of_object_t *_obj,
                                         indigo_cxn_id_t cxn_id)
{
    of_aggregate_stats_request_t *obj;
    of_meta_match_t query;
    struct ind_core_flow_stats_state *state;
    struct ind_core_aggregate_stats_priv *priv;
    ft_entry_t *entry;
    list_links_t *cur, *next;

    obj = (of_aggregate_stats_request_t *)_obj;
    LOG_TRACE("Handling of_aggregate_stats_request message: %p.", obj);

    /* Set up the query structure */
    INDIGO_MEM_SET(&query, 0, sizeof(query));
    if (of_aggregate_stats_request_match_get(obj, &(query.match)) < 0) {
        return INDIGO_ERROR_UNKNOWN;
    }
    of_aggregate_stats_request_out_port_get(obj, &(query.out_port));
    of_aggregate_stats_request_table_id_get(obj, &(query.table_id));

    /* Non strict; do not check priority, cookie or overlap */
    query.mode = OF_MATCH_NON_STRICT;

    state = INDIGO_MEM_ALLOC(sizeof(*state) + sizeof(*priv));
    if (state == NULL) {
       LOG_ERROR("Failed to allocate flow stats state object.");
       of_object_delete(_obj);
       return INDIGO_ERROR_RESOURCE;
    }

    state->finished_calls = 0;
    state->expected_count = 0;
    state->received_count = 0;
    state->callback = ind_core_aggregate_stats_request_cb;

    priv = (struct ind_core_aggregate_stats_priv *)(state + 1);
    priv->cxn_id = cxn_id;
    priv->req = obj; /* ownership transferred */
    priv->packets = 0;
    priv->bytes = 0;
    priv->flows = 0;

    /*
     * Iterate over flow table; query stats for each entry.
     *
     * indigo_core_flow_stats_get_callback will generate the reply.
     */
    FT_ITER(ind_core_ft, entry, cur, next) {
       if (!FT_FLOW_STATE_IS_DELETED(entry->state) &&
              ft_entry_meta_match(&query, entry)) {
           state->expected_count++;
           indigo_fwd_flow_stats_get(entry->id,
                                     INDIGO_POINTER_TO_COOKIE(state));
        }
    }

    indigo_core_flow_stats_get_callback(INDIGO_ERROR_NONE, NULL,
                                        INDIGO_POINTER_TO_COOKIE(state));

    return INDIGO_ERROR_NONE;
}

/****************************************************************/

/**
 * Handle a desc_stats_request message
 * @param cxn_id Connection handler for the owning connection
 * @param _obj Generic type object for the message to be coerced
 * @returns Error code
 */

indigo_error_t
ind_core_desc_stats_request_handler(of_object_t *_obj, indigo_cxn_id_t cxn_id)
{
    of_desc_stats_request_t *obj;
    of_desc_stats_reply_t *reply;
    uint32_t xid;
    int rv;
    ind_core_desc_stats_t *data;

    obj = (of_desc_stats_request_t *)_obj;
    LOG_TRACE("Handling of_desc_stats_request message: %p.", obj);

    /* Duplicate the module's desc stats reply and send to controller */
    if ((reply = of_desc_stats_reply_new(obj->version)) == NULL) {
        LOG_ERROR("Failed to create desc stats reply message");
        of_object_delete(_obj);
        return INDIGO_ERROR_NONE; /* @fixme Error handling in this case? */
    }

    of_desc_stats_request_xid_get(obj, &xid);
    of_desc_stats_reply_xid_set(reply, xid);

    data = &ind_core_of_config.desc_stats;
    of_desc_stats_reply_sw_desc_set(reply, data->sw_desc);
    of_desc_stats_reply_hw_desc_set(reply, data->hw_desc);
    of_desc_stats_reply_dp_desc_set(reply, data->dp_desc);
    of_desc_stats_reply_mfr_desc_set(reply, data->mfr_desc);
    of_desc_stats_reply_serial_num_set(reply, data->serial_num);
    of_desc_stats_reply_flags_set(reply, 0);

    if ((rv = IND_CORE_MSG_SEND(cxn_id, reply)) < 0) {
        LOG_ERROR("Error sending desc stats response to %d", cxn_id);
        of_object_delete(_obj);
        return rv;
    }

    of_object_delete(_obj);
    return INDIGO_ERROR_NONE;
}

/****************************************************************/

/**
 * Handle a table_stats_request message
 * @param cxn_id Connection handler for the owning connection
 * @param _obj Generic type object for the message to be coerced
 * @returns Error code
 */

indigo_error_t
ind_core_table_stats_request_handler(of_object_t *_obj, indigo_cxn_id_t cxn_id)
{
    of_table_stats_request_t *obj;
    indigo_cookie_t cookie;
    ptr_cxn_wrapper_t *ptr_cxn;

    LOG_TRACE("Handling of_table_stats_request message: %p.", _obj);

    if ((ptr_cxn = setup_ptr_cxn(_obj, NULL, cxn_id, 0)) == NULL) {
        LOG_ERROR("Could not alloc transfer data for port stats req");
        of_object_delete(_obj);
        return INDIGO_ERROR_RESOURCE;
    }
    cookie = INDIGO_POINTER_TO_COOKIE(ptr_cxn);
    obj = (of_table_stats_request_t *)_obj;

    indigo_fwd_table_stats_get(obj, cookie);

    return INDIGO_ERROR_NONE;
}

void
indigo_core_table_stats_get_callback(indigo_error_t result,
                                     of_table_stats_reply_t *reply,
                                     indigo_cookie_t cookie)
{
    ptr_cxn_wrapper_t *ptr_cxn;
    indigo_cxn_id_t cxn_id;
    int rv = OF_ERROR_UNKNOWN;
    if (!ind_core_init_done) {
        return;
    }

    ptr_cxn = INDIGO_COOKIE_TO_POINTER(cookie);
    cxn_id = ptr_cxn->cxn_id;

    LOG_TRACE("Table stats callback");

    if (result != INDIGO_ERROR_NONE) {
       LOG_ERROR("Table stats returned error");
       goto done;
    }

    rv = IND_CORE_MSG_SEND(cxn_id, reply);
    if (rv < 0) {
        LOG_ERROR("Error %d sending table_stats reply to %d", rv, cxn_id);
    }

 done:
    if (rv < 0)  of_table_stats_reply_delete(reply);

    of_table_stats_request_delete(ptr_cxn->req);
    INDIGO_MEM_FREE(ptr_cxn);
}

/****************************************************************/

/**
 * Handle a port_desc_stats_request message
 * @param cxn_id Connection handler for the owning connection
 * @param _obj Generic type object for the message to be coerced
 * @returns Error code
 */

indigo_error_t
ind_core_port_desc_stats_request_handler(of_object_t *_obj, indigo_cxn_id_t cxn_id)
{
    uint32_t xid;
    of_port_desc_stats_request_t *obj;
    of_port_desc_stats_reply_t *reply;
    int rv;

    obj = (of_port_desc_stats_request_t *)_obj;
    LOG_TRACE("Handling of_port_desc_stats_request message: %p.", obj);

    /* Generate a port_desc_stats reply and send to controller */
    if ((reply = of_port_desc_stats_reply_new(obj->version)) == NULL) {
        LOG_ERROR("Failed to create port_desc_stats reply message");
        of_object_delete(_obj);
        return INDIGO_ERROR_NONE; /* @fixme Error handling in this case? */
    }

    of_port_desc_stats_request_xid_get(obj, &xid);
    of_port_desc_stats_reply_xid_set(reply, xid);
    indigo_port_desc_stats_get(reply);

    of_port_desc_stats_request_delete(obj);

    if ((rv = IND_CORE_MSG_SEND(cxn_id, reply)) < 0) {
        LOG_ERROR("Error sending port_desc_stats response to %d", cxn_id);
        return rv;
    }

    return INDIGO_ERROR_NONE;
}

/****************************************************************/

/**
 * Handle a features_request message
 * @param cxn_id Connection handler for the owning connection
 * @param _obj Generic type object for the message to be coerced
 * @returns Error code
 */

indigo_error_t
ind_core_features_request_handler(of_object_t *_obj, indigo_cxn_id_t cxn_id)
{
    of_features_request_t *obj;
    of_features_reply_t *reply;
    uint32_t xid;
    int rv;
    of_dpid_t dpid;

    obj = (of_features_request_t *)_obj;
    LOG_TRACE("Handling of_features_request message: %p.", obj);

    /* Generate a features reply and send to controller */
    if ((reply = of_features_reply_new(obj->version)) == NULL) {
        LOG_ERROR("Failed to create features reply message");
        of_object_delete(_obj);
        return INDIGO_ERROR_NONE; /* @fixme Error handling in this case? */
    }

    of_features_request_xid_get(obj, &xid);
    of_features_reply_xid_set(reply, xid);
    _TRY_NR(indigo_core_dpid_get(&dpid));
    of_features_reply_datapath_id_set(reply, dpid);
    of_features_reply_n_buffers_set(reply, 0);
    _TRY_NR(indigo_fwd_forwarding_features_get(reply));
    _TRY_NR(indigo_port_features_get(reply));

    of_features_request_delete(obj);

    if ((rv = IND_CORE_MSG_SEND(cxn_id, reply)) < 0) {
        LOG_ERROR("Error sending features response to %d", cxn_id);
        return rv;
    }

    return INDIGO_ERROR_NONE;
}

/**
 * Handle a table_mod message
 * @param cxn_id Connection handler for the owning connection
 * @param _obj Generic type object for the message to be coerced
 * @returns Error code
 */

indigo_error_t
ind_core_table_mod_handler(of_object_t *_obj, indigo_cxn_id_t cxn_id)
{
    of_table_mod_t *obj;

    obj = (of_table_mod_t *)_obj;
    LOG_TRACE("Handling of_table_mod message: %p.", obj);

    /* Handle object of type of_table_mod_t */

    of_object_delete(_obj);

    return INDIGO_ERROR_NONE;
}

/**
 * Handle a set_config message
 * @param cxn_id Connection handler for the owning connection
 * @param _obj Generic type object for the message to be coerced
 * @returns Error code
 */

indigo_error_t
ind_core_set_config_handler(of_object_t *_obj, indigo_cxn_id_t cxn_id)
{
    of_set_config_t *obj;

    obj = (of_set_config_t *)_obj;
    LOG_TRACE("Handling of_set_config message: %p.", obj);

    /* Handle object of type of_set_config_t */
    ind_core_of_config.config_set_done = 1;
    of_set_config_flags_get(obj, &ind_core_of_config.flags);
    LOG_VERBOSE("Config flags set to 0x%x", ind_core_of_config.flags);
    of_set_config_miss_send_len_get(obj, &ind_core_of_config.miss_send_len);
    LOG_VERBOSE("Miss send len set to %d", ind_core_of_config.miss_send_len);

    of_object_delete(_obj);

    return INDIGO_ERROR_NONE;
}

/**
 * Handle an experimenter message
 * @param cxn_id Connection handler for the owning connection
 * @param _obj Generic type object for the message to be coerced
 * @returns Error code
 *
 * The state manager has no specific support for experimenter messages.
 * However, the port or forwarding modules may have that support
 * independent of the state manager.  For this reason, the state
 * manager calls both the port manager and forwarding modules with
 * the request.
 *
 * Currently there is no support for asynchronous experimenter message
 * handling at this layer (so barriers currently will not track experimenter
 * messages correctly).  However, the port and forwarding modules
 * each get their own copy of the message.
 *
 * The port and forwarding modules must respond as follows:
 *    INDIGO_ERROR_NONE:  Supported request, no error.
 *    INDIGO_ERROR_NOT_SUPPORTED:  Module does not support the request
 *    INDIGO_ERROR_xxx: Supported request, but error occurred.
 *
 * If both modules respond with NOT_SUPPORTED, then an unknown message
 * type error is generated and sent back to the controller connection.
 *
 * If either module responds with NONE, the operation is considered
 * successful.
 *
 * Otherwise, if either module responds with an error other than
 * supported, behavior is TBD.
 *
 */

indigo_error_t
ind_core_experimenter_handler(of_object_t *_obj, indigo_cxn_id_t cxn_id)
{
    of_experimenter_t *fwd_obj;
    of_experimenter_t *port_obj;
    indigo_error_t fwd_rv;
    indigo_error_t port_rv;
    indigo_error_t rv = INDIGO_ERROR_NONE;
    uint32_t xid = 0;
    of_version_t version;

    fwd_obj = (of_experimenter_t *)_obj;
    port_obj = of_object_dup(_obj);

    if (port_obj == NULL) {
        LOG_ERROR("Could not allocate port experimenter object");
        of_object_delete(_obj);
        return INDIGO_ERROR_RESOURCE;
    }

    /* Record data before calling datapath funs which own objs */
    version = fwd_obj->version;
    of_object_xid_get(_obj, &xid);

    LOG_TRACE("Handling of_experimenter message: %p.", fwd_obj);

    /* Handle object of type of_experimenter_t */
    if ((fwd_rv = indigo_fwd_experimenter(fwd_obj, cxn_id)) < 0) {
        LOG_TRACE("Error %d from fwd_experimenter", fwd_rv);
    }
    if ((port_rv = indigo_port_experimenter(port_obj, cxn_id)) < 0) {
        LOG_TRACE("Error %d from port_experimenter", port_rv);
    }

    if ((fwd_rv == INDIGO_ERROR_NOT_SUPPORTED) &&
        (port_rv == INDIGO_ERROR_NOT_SUPPORTED)) {
        indigo_cxn_send_error_msg(version, cxn_id, xid,
                                  OF_ERROR_TYPE_BAD_REQUEST,
                                  OF_REQUEST_FAILED_BAD_VENDOR, NULL);
    } else if ((fwd_rv != INDIGO_ERROR_NONE) &&
               (port_rv != INDIGO_ERROR_NONE)) {
        /* Not handled and some error */
        if (port_rv != INDIGO_ERROR_NONE) {
            rv = port_rv;
        }
        if (fwd_rv != INDIGO_ERROR_NONE) {
            rv = fwd_rv;
        }
    }

    if (rv < 0) {
        LOG_VERBOSE("Error handling experimenter message in port or fwding");
    }

    of_experimenter_delete(fwd_obj);
    of_experimenter_delete(port_obj);

    return rv;
}


/**
 * Handle a experimenter_stats_request message
 * @param cxn_id Connection handler for the owning connection
 * @param _obj Generic type object for the message to be coerced
 * @returns Error code
 *
 * Currently not handled; returns error message to controller
 */

indigo_error_t
ind_core_experimenter_stats_request_handler(of_object_t *_obj,
                                            indigo_cxn_id_t cxn_id)
{
    of_experimenter_stats_request_t *obj;

    obj = (of_experimenter_stats_request_t *)_obj;
    LOG_TRACE("Handling of_experimenter_stats_request message: %p.", obj);

    /* Handle object of type of_experimenter_stats_request_t */

    ind_core_unhandled_message(_obj, cxn_id);

    return INDIGO_ERROR_NONE;
}

/**
 * Handle a group_desc_stats_request message
 * @param cxn_id Connection handler for the owning connection
 * @param _obj Generic type object for the message to be coerced
 * @returns Error code
 */

indigo_error_t
ind_core_group_desc_stats_request_handler(of_object_t *_obj,
                                          indigo_cxn_id_t cxn_id)
{
    of_group_desc_stats_request_t *obj;

    obj = (of_group_desc_stats_request_t *)_obj;
    LOG_TRACE("Handling of_group_desc_stats_request message: %p.", obj);

    /* Handle object of type of_group_desc_stats_request_t */
    ind_core_unhandled_message(_obj, cxn_id);

    return INDIGO_ERROR_NONE;
}

/**
 * Handle a group_features_stats_request message
 * @param cxn_id Connection handler for the owning connection
 * @param _obj Generic type object for the message to be coerced
 * @returns Error code
 */

indigo_error_t
ind_core_group_features_stats_request_handler(of_object_t *_obj,
                                              indigo_cxn_id_t cxn_id)
{
    of_group_features_stats_request_t *obj;

    obj = (of_group_features_stats_request_t *)_obj;
    LOG_TRACE("Handling of_group_features_stats_request message: %p.", obj);

    /* Handle object of type of_group_features_stats_request_t */
    ind_core_unhandled_message(_obj, cxn_id);

    return INDIGO_ERROR_NONE;
}

/****************************************************************
 *
 * Extension message handling
 *
 ****************************************************************/

/**
 * Handle a BSN set IP mask
 * @param cxn_id Connection handler for the owning connection
 * @param _obj Generic type object for the message to be coerced
 * @returns Error code
 */

indigo_error_t
ind_core_bsn_set_ip_mask_handler(of_object_t *_obj, indigo_cxn_id_t cxn_id)
{
    of_bsn_set_ip_mask_t *obj;
    uint8_t index;
    uint32_t mask;
    uint32_t xid;

    obj = (of_bsn_set_ip_mask_t *)_obj;
    of_bsn_set_ip_mask_xid_get(obj, &xid);

    LOG_TRACE("Received BSN set IP mask message from %d", cxn_id);

    of_bsn_set_ip_mask_index_get(obj, &index);
    of_bsn_set_ip_mask_mask_get(obj, &mask);
    of_bsn_set_ip_mask_delete(obj);

    if (of_ip_mask_map_set((int)index, mask) < 0) {
        LOG_ERROR("Bad index for set ip_mask: %d", index);
        /* @todo sending type 0, code 0 error message */
        if (indigo_cxn_send_error_msg(obj->version, cxn_id, xid,
                                      0, 0, NULL) < 0) {
            LOG_ERROR("Error sending error message for set ip mask msg, "
                      "cxn id %d", cxn_id);
        }
        return INDIGO_ERROR_NONE;
    }
    LOG_TRACE("ip_mask: Set index %d to 0x%x", index, mask);

    return INDIGO_ERROR_NONE;
}

/**
 * Handle a BSN get IP mask request
 * @param cxn_id Connection handler for the owning connection
 * @param _obj Generic type object for the message to be coerced
 * @returns Error code
 */

indigo_error_t
ind_core_bsn_get_ip_mask_request_handler(of_object_t *_obj,
                                         indigo_cxn_id_t cxn_id)
{
    of_bsn_get_ip_mask_request_t *obj;
    of_bsn_get_ip_mask_reply_t *reply;
    uint32_t val32;
    uint8_t index;
    int rv;
    uint32_t xid;

    obj = (of_bsn_get_ip_mask_request_t *)_obj;

    LOG_TRACE("Received BSN get IP mask request message from %d", cxn_id);

    /* Duplicate the module's desc stats reply and send to controller */
    if ((reply = of_bsn_get_ip_mask_reply_new(obj->version)) == NULL) {
        LOG_ERROR("Failed to create ip mask reply message");
        of_bsn_get_ip_mask_request_delete(obj);
        return INDIGO_ERROR_NONE; /* @fixme Error handling in this case? */
    }

    of_bsn_get_ip_mask_request_xid_get(obj, &xid);
    of_bsn_get_ip_mask_reply_xid_set(reply, xid);

    of_bsn_get_ip_mask_request_index_get(obj, &index);
    of_bsn_get_ip_mask_reply_index_set(reply, index);

    of_bsn_get_ip_mask_request_delete(obj);

    if (of_ip_mask_map_get((int)index, &val32) < 0) {
        LOG_ERROR("Bad index for get ip_mask: %d", index);
        /* @todo sending type 0, code 0 error message */
        if (indigo_cxn_send_error_msg(obj->version, cxn_id, xid,
                                      0, 0, NULL) < 0) {
            LOG_ERROR("Error sending error message for get ip mask msg, "
                      "cxn id %d", cxn_id);
        }
        return INDIGO_ERROR_NONE;
    }
    of_bsn_get_ip_mask_reply_mask_set(reply, val32);

    if ((rv = IND_CORE_MSG_SEND(cxn_id, reply)) < 0) {
        LOG_ERROR("Error sending features response to %d", cxn_id);
        return rv;
    }
    return INDIGO_ERROR_NONE;
}
