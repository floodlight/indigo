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
 * @brief Weak symbols for optional Forwarding/PortManager interfaces
 */

#include "ofstatemanager_log.h"

#include <OFStateManager/ofstatemanager_config.h>
#include <indigo/indigo.h>
#include <indigo/forwarding.h>
#include <loci/loci.h>

#ifdef __GNUC__
#define WEAK __attribute__ ((weak))
#else
#warn "Weak symbols not supported for this compiler"
#endif

#ifdef WEAK

WEAK void
indigo_fwd_vlan_stats_get(
    uint16_t vlan_vid,
    indigo_fi_vlan_stats_t *vlan_stats)
{
    /* All counters default to -1 */
}

WEAK void
indigo_port_extended_stats_get(
    of_port_no_t port_no,
    indigo_fi_port_stats_t *port_stats)
{
    /* All counters default to -1 */
}

WEAK indigo_error_t
indigo_fwd_flow_create(
    indigo_cookie_t flow_id,
    of_flow_add_t *flow_add,
    uint8_t *table_id)
{
    return INDIGO_ERROR_BAD_TABLE_ID;
}

WEAK indigo_error_t
indigo_fwd_flow_modify(
    indigo_cookie_t flow_id,
    of_flow_modify_t *flow_modify)
{
    return INDIGO_ERROR_BAD_TABLE_ID;
}

WEAK indigo_error_t
indigo_fwd_flow_delete(
    indigo_cookie_t flow_id,
    indigo_fi_flow_stats_t *flow_stats)
{
    return INDIGO_ERROR_BAD_TABLE_ID;
}

WEAK indigo_error_t
indigo_fwd_flow_stats_get(
    indigo_cookie_t flow_id,
    indigo_fi_flow_stats_t *flow_stats)
{
    return INDIGO_ERROR_BAD_TABLE_ID;
}

WEAK indigo_error_t
indigo_fwd_flow_hit_status_get(
    indigo_cookie_t flow_id,
    bool *hit_status)
{
    return INDIGO_ERROR_BAD_TABLE_ID;
}

#endif
