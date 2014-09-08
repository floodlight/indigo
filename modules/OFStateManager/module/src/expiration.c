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
 * @brief Flow expiration
 */

#include <OFStateManager/ofstatemanager_config.h>
#include <indigo/indigo.h>
#include <SocketManager/socketmanager.h>

#include "ofstatemanager_log.h"
#include "ofstatemanager_decs.h"
#include "ft_entry.h"
#include "table.h"

static void send_idle_notification(ft_entry_t *entry);

static LIST_DEFINE(expiration_queue);

static indigo_time_t
calc_expiration_time(ft_entry_t *entry, int *reason)
{
    indigo_time_t idle_expiration_time = -1, hard_expiration_time = -1;
    INDIGO_ASSERT(entry->hard_timeout || entry->idle_timeout);

    if (entry->hard_timeout > 0) {
        hard_expiration_time = entry->insert_time + entry->hard_timeout*1000;
    }
    if (entry->idle_timeout > 0) {
        idle_expiration_time = entry->last_counter_change + entry->idle_timeout*1000;
    }

    if (hard_expiration_time <= idle_expiration_time) {
        *reason = OF_FLOW_REMOVED_REASON_HARD_TIMEOUT;
        return hard_expiration_time;
    } else {
        *reason = OF_FLOW_REMOVED_REASON_IDLE_TIMEOUT;
        return idle_expiration_time;
    }
}

void
ind_core_expiration_add(ft_entry_t *entry)
{
    int reason;
    indigo_time_t expiration_time = calc_expiration_time(entry, &reason);
    list_links_t *cur;

    /* Iterate over list in reverse order */
    for (cur = expiration_queue.links.prev;
         cur != &expiration_queue.links;
         cur = cur->prev) {
        ft_entry_t *other = FT_ENTRY_CONTAINER(cur, expiration);
        if (calc_expiration_time(other, &reason) <= expiration_time) {
            /* 'other' expires before us. Insert after it. */
            list_insert_after(cur, &entry->expiration_links);
            return;
        }
    }

    /* Lowest expiration time. Insert at front of list. */
    list_unshift(&expiration_queue, &entry->expiration_links);
}

void
ind_core_expiration_remove(ft_entry_t *entry)
{
    list_remove(&entry->expiration_links);
}

/*
 * Expiration processing for a single flow
 *
 * For idle timeouts, will check with the hardware to see if the flow has been
 * hit since the last time it was checked.
 *
 * Returns true if the flow actually expired.
 */
static bool
expire_flow(ft_entry_t *entry, int reason)
{
    if (reason == INDIGO_FLOW_REMOVED_HARD_TIMEOUT) {
        AIM_LOG_TRACE("Hard TO (%d): " INDIGO_FLOW_ID_PRINTF_FORMAT,
                      entry->hard_timeout,
                      INDIGO_FLOW_ID_PRINTF_ARG(entry->id));
        ind_core_flow_entry_delete(entry, reason, INDIGO_CXN_ID_UNSPECIFIED);
        return true;
    } else if (reason == OF_FLOW_REMOVED_REASON_IDLE_TIMEOUT) {
        int rv;
        bool hit;

        /* Get hit status for idle timeouts */
        ind_core_table_t *table = ind_core_table_get(entry->table_id);
        if (table != NULL) {
            rv = table->ops->entry_hit_status_get(table->priv, INDIGO_CXN_ID_UNSPECIFIED,
                                                  entry->priv, &hit);
        } else {
            rv = indigo_fwd_flow_hit_status_get(entry->id, &hit);
        }

        if (rv != INDIGO_ERROR_NONE) {
            AIM_LOG_ERROR("Failed to get hit status for flow "
                          INDIGO_FLOW_ID_PRINTF_FORMAT": %s",
                          entry->id, indigo_strerror(rv));
            return false;
        }

        if (hit || entry->flags & OF_FLOW_MOD_FLAG_BSN_SEND_IDLE) {
            /* Reinsert entry into the expiration list */
            entry->last_counter_change = INDIGO_CURRENT_TIME;
            ind_core_expiration_remove(entry);
            ind_core_expiration_add(entry);
        }

        if (!hit) {
            if (entry->flags & OF_FLOW_MOD_FLAG_BSN_SEND_IDLE) {
                send_idle_notification(entry);
            } else {
                AIM_LOG_TRACE("Idle TO (%d): " INDIGO_FLOW_ID_PRINTF_FORMAT,
                              entry->idle_timeout,
                              INDIGO_FLOW_ID_PRINTF_ARG(entry->id));
                ind_core_flow_entry_delete(entry, reason, INDIGO_CXN_ID_UNSPECIFIED);
            }

            return true;
        } else {
            return false;
        }
    } else {
        AIM_TRUE_OR_DIE(0);
    }
}

void
ind_core_expiration_timer(void *cookie)
{
    indigo_time_t now = INDIGO_CURRENT_TIME;
    int expired_flows = 0; /* Limit the number of messages sent to the controller each tick */

    while (expired_flows < 32 &&
            !ind_soc_should_yield() &&
            !list_empty(&expiration_queue)) {
        int reason;
        list_links_t *links = expiration_queue.links.next;
        ft_entry_t *entry = FT_ENTRY_CONTAINER(links, expiration);
        if (calc_expiration_time(entry, &reason) <= now) {
            if (expire_flow(entry, reason)) {
                expired_flows++;
            }
        } else {
            break;
        }
    }
}

/**
 * @brief Send a idle notification for the given entry
 * @param entry The local flow table entry
 */

static void
send_idle_notification(ft_entry_t *entry)
{
    of_bsn_flow_idle_t *msg;
    of_version_t ver;

    if (indigo_cxn_get_async_version(&ver) < 0) {
        /* No controllers connected */
        return;
    }

    if ((msg = of_bsn_flow_idle_new(ver)) == NULL) {
        AIM_LOG_ERROR("Failed to allocate flow_idle message");
        return;
    }

    of_bsn_flow_idle_cookie_set(msg, entry->cookie);
    of_bsn_flow_idle_priority_set(msg, entry->priority);
    of_bsn_flow_idle_table_id_set(msg, entry->table_id);

    of_match_t match;
    minimatch_expand(&entry->minimatch, &match);

    if (of_bsn_flow_idle_match_set(msg, &match)) {
        AIM_LOG_ERROR("Failed to set match in idle notification");
        of_object_delete(msg);
        return;
    }

    indigo_cxn_send_async_message(msg);
}
