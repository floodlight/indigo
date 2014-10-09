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
indigo_fwd_group_add(uint32_t id, uint8_t group_type, of_list_bucket_t *buckets)
{
    return INDIGO_ERROR_NOT_SUPPORTED;
}

WEAK indigo_error_t
indigo_fwd_group_modify(uint32_t id, of_list_bucket_t *buckets)
{
    return INDIGO_ERROR_NOT_SUPPORTED;
}

WEAK void
indigo_fwd_group_delete(uint32_t id)
{
}

WEAK void
indigo_fwd_group_stats_get(uint32_t id, of_group_stats_entry_t *entry)
{
}

#endif
