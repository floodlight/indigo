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
 * @brief Implementation of the built-in test gentable
 *
 * This table is provided so that test suites can exercise the gentable
 * functionality without worrying about hardware limitations.
 *
 * Key:
 *  - vlan_vid
 *  - ipv4
 *
 * Value:
 *  - mac
 *  - idle_notification
 *
 * Stats:
 *  - rx_packets
 *  - tx_packets
 *
 * Validation:
 *  - 0 <= vlan_vid < 4095
 *  - mac is unicast
 *
 * Deletion will fail the first time if idle_notification is set.
 */

#include "ofstatemanager_log.h"

#include <OFStateManager/ofstatemanager_config.h>
#include <indigo/indigo.h>
#include <loci/loci.h>
#include "ofstatemanager_decs.h"
#include "ofstatemanager_int.h"
#include "handlers.h"
#include <murmur/murmur.h>

struct ind_core_gentable_test_table;

static struct ind_core_gentable_test_table *ind_core_test_gentable_table;
static indigo_core_gentable_t *ind_core_test_gentable;

struct ind_core_gentable_test_key {
    uint16_t vlan_vid;
    of_ipv4_t ipv4;
};

struct ind_core_gentable_test_value {
    of_mac_addr_t mac;
    bool idle_notification;
};

struct ind_core_gentable_test_table {
    uint32_t num_entries;
};

struct ind_core_gentable_test_entry {
    struct ind_core_gentable_test_key key;
    struct ind_core_gentable_test_value value;
    uint64_t rx_packets;
    uint64_t tx_packets;
    bool fail_deletion;
};

static indigo_error_t
parse_key(of_list_bsn_tlv_t *key, struct ind_core_gentable_test_key *out)
{
    of_bsn_tlv_t tlv;
    int loop_rv = 0;
    int count_vlan_vid = 0;
    int count_ipv4 = 0;

    OF_LIST_BSN_TLV_ITER(key, &tlv, loop_rv) {
        if (tlv.header.object_id == OF_BSN_TLV_VLAN_VID) {
            count_vlan_vid++;
            of_bsn_tlv_vlan_vid_value_get(&tlv.port, &out->vlan_vid);
        } else if (tlv.header.object_id == OF_BSN_TLV_IPV4) {
            count_ipv4++;
            of_bsn_tlv_ipv4_value_get(&tlv.port, &out->ipv4);
        } else {
            return INDIGO_ERROR_NOT_SUPPORTED;
        }
    }

    if (count_vlan_vid != 1 || count_ipv4 != 1) {
        return INDIGO_ERROR_PARAM;
    } else if (out->vlan_vid >= 4095) {
        return INDIGO_ERROR_PARAM;
    } else {
        return INDIGO_ERROR_NONE;
    }
}

static indigo_error_t
parse_value(of_list_bsn_tlv_t *value, struct ind_core_gentable_test_value *out)
{
    of_bsn_tlv_t tlv;
    int loop_rv = 0;
    int count_mac = 0;
    int count_idle_notification = 0;

    out->idle_notification = false;

    OF_LIST_BSN_TLV_ITER(value, &tlv, loop_rv) {
        if (tlv.header.object_id == OF_BSN_TLV_MAC) {
            count_mac++;
            of_bsn_tlv_mac_value_get(&tlv.port, &out->mac);
        } else if (tlv.header.object_id == OF_BSN_TLV_IDLE_NOTIFICATION) {
            count_idle_notification++;
            out->idle_notification = true;
        } else {
            return INDIGO_ERROR_NOT_SUPPORTED;
        }
    }

    if (count_mac != 1 || count_idle_notification > 1) {
        return INDIGO_ERROR_PARAM;
    } else if (out->mac.addr[0] & 1) {
        /* non-unicast MAC */
        return INDIGO_ERROR_PARAM;
    } else {
        return INDIGO_ERROR_NONE;
    }
}

static indigo_error_t
ind_core_test_gentable_add(void *table_priv, of_list_bsn_tlv_t *key, of_list_bsn_tlv_t *value, void **entry_priv)
{
    indigo_error_t rv;
    struct ind_core_gentable_test_table *table = table_priv;
    struct ind_core_gentable_test_entry *entry = aim_zmalloc(sizeof(*entry));

    rv = parse_key(key, &entry->key);
    if (rv < 0) {
        aim_free(entry);
        return rv;
    }

    rv = parse_value(value, &entry->value);
    if (rv < 0) {
        aim_free(entry);
        return rv;
    }

    /* HACK to test deletion error path */
    entry->fail_deletion = entry->value.idle_notification;

    /* TODO validate num entries */

    table->num_entries++;

    *entry_priv = entry;
    return INDIGO_ERROR_NONE;
}

static indigo_error_t
ind_core_test_gentable_modify(void *table_priv, void *entry_priv, of_list_bsn_tlv_t *key, of_list_bsn_tlv_t *value)
{
    indigo_error_t rv;
    //struct ind_core_gentable_test_table *table = table_priv;
    struct ind_core_gentable_test_entry *entry = entry_priv;

    rv = parse_value(value, &entry->value);
    if (rv < 0) {
        return rv;
    }

    return INDIGO_ERROR_NONE;
}

static indigo_error_t
ind_core_test_gentable_delete(void *table_priv, void *entry_priv, of_list_bsn_tlv_t *key)
{
    struct ind_core_gentable_test_table *table = table_priv;
    struct ind_core_gentable_test_entry *entry = entry_priv;

    if (entry->fail_deletion) {
        entry->fail_deletion = false;
        return INDIGO_ERROR_PARAM;
    }

    aim_free(entry);

    table->num_entries--;

    return INDIGO_ERROR_NONE;
}

static void
ind_core_test_gentable_get_stats(void *table_priv, void *entry_priv, of_list_bsn_tlv_t *key, of_list_bsn_tlv_t *stats)
{
    //struct ind_core_gentable_test_table *table = table_priv;
    struct ind_core_gentable_test_entry *entry = entry_priv;

    {
        of_object_t *tlv = of_bsn_tlv_rx_packets_new(OF_VERSION_1_3);
        of_bsn_tlv_rx_packets_value_set(tlv, 100 * entry->key.vlan_vid);
        of_list_append(stats, tlv);
        of_object_delete(tlv);
    }

    {
        of_object_t *tlv = of_bsn_tlv_tx_packets_new(OF_VERSION_1_3);
        of_bsn_tlv_tx_packets_value_set(tlv, 101 * entry->key.vlan_vid);
        of_list_append(stats, tlv);
        of_object_delete(tlv);
    }
}

static indigo_core_gentable_ops_t ind_core_test_gentable_ops = {
    ind_core_test_gentable_add,
    ind_core_test_gentable_modify,
    ind_core_test_gentable_delete,
    ind_core_test_gentable_get_stats,
};

void
ind_core_test_gentable_init(void)
{
    ind_core_test_gentable_table =
        aim_zmalloc(sizeof(*ind_core_test_gentable_table));

    of_table_name_t name = "test";
    indigo_core_gentable_register(name, &ind_core_test_gentable_ops,
                                  ind_core_test_gentable_table, 1000, 64,
                                  &ind_core_test_gentable);
}

void
ind_core_test_gentable_finish(void)
{
    indigo_core_gentable_unregister(ind_core_test_gentable);
    aim_free(ind_core_test_gentable_table);

    ind_core_test_gentable = NULL;
    ind_core_test_gentable_table = NULL;
}
