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
 * @brief Listener infrastructure
 */

#include <OFStateManager/ofstatemanager_config.h>
#include <OFStateManager/ofstatemanager.h>
#include <indigo/indigo.h>
#include <BigList/biglist.h>

#include "ofstatemanager_log.h"
#include "listener.h"

static biglist_t *packet_in_listeners;
static biglist_t *port_status_listeners;
static biglist_t *message_listeners;

/* Packet in */

indigo_error_t
indigo_core_packet_in_listener_register(indigo_core_packet_in_listener_f fn)
{
    if (biglist_find(packet_in_listeners, fn)) {
        return INDIGO_ERROR_EXISTS;
    }

    packet_in_listeners = biglist_append(packet_in_listeners, fn);

    return INDIGO_ERROR_NONE;
}

void
indigo_core_packet_in_listener_unregister(indigo_core_packet_in_listener_f fn)
{
    packet_in_listeners = biglist_remove(packet_in_listeners, fn);
}

indigo_core_listener_result_t
ind_core_packet_in_notify(of_packet_in_t *packet_in)
{
    indigo_core_listener_result_t result = INDIGO_CORE_LISTENER_RESULT_PASS;
    biglist_t *cur;
    indigo_core_packet_in_listener_f fn;

    BIGLIST_FOREACH_DATA(cur, packet_in_listeners, indigo_core_packet_in_listener_f, fn) {
        result |= fn(packet_in);
    }

    return result;
}

/* Port status */

indigo_error_t
indigo_core_port_status_listener_register(indigo_core_port_status_listener_f fn)
{
    if (biglist_find(port_status_listeners, fn)) {
        return INDIGO_ERROR_EXISTS;
    }

    port_status_listeners = biglist_append(port_status_listeners, fn);

    return INDIGO_ERROR_NONE;
}

void
indigo_core_port_status_listener_unregister(indigo_core_port_status_listener_f fn)
{
    port_status_listeners = biglist_remove(port_status_listeners, fn);
}

indigo_core_listener_result_t
ind_core_port_status_notify(of_port_status_t *port_status)
{
    indigo_core_listener_result_t result = INDIGO_CORE_LISTENER_RESULT_PASS;
    biglist_t *cur;
    indigo_core_port_status_listener_f fn;

    BIGLIST_FOREACH_DATA(cur, port_status_listeners, indigo_core_port_status_listener_f, fn) {
        result |= fn(port_status);
    }

    return result;
}

/* Message from controller */

indigo_error_t
indigo_core_message_listener_register(indigo_core_message_listener_f fn)
{
    if (biglist_find(message_listeners, fn)) {
        return INDIGO_ERROR_EXISTS;
    }

    message_listeners = biglist_append(message_listeners, fn);

    return INDIGO_ERROR_NONE;
}

void
indigo_core_message_listener_unregister(indigo_core_message_listener_f fn)
{
    message_listeners = biglist_remove(message_listeners, fn);
}

indigo_core_listener_result_t
ind_core_message_notify(indigo_cxn_id_t cxn_id, of_object_t *message)
{
    indigo_core_listener_result_t result = INDIGO_CORE_LISTENER_RESULT_PASS;
    biglist_t *cur;
    indigo_core_message_listener_f fn;

    BIGLIST_FOREACH_DATA(cur, message_listeners, indigo_core_message_listener_f, fn) {
        result |= fn(cxn_id, message);
    }

    return result;
}
