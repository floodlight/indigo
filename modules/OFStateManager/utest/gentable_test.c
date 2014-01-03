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

/******************************************************************************
 *
 *  /utest/main.c
 *
 *  OFStateManager Unit Testing
 *
 *****************************************************************************/
#define AIM_LOG_MODULE_NAME ofstatemanager_utest
#include <AIM/aim_log.h>

#include <OFStateManager/ofstatemanager.h>
#include <OFStateManager/ofstatemanager_config.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <loci/loci.h>
#include <locitest/unittest.h>
#include <locitest/test_common.h>

#define NUM_TABLES 16

extern indigo_core_gentable_ops_t test_ops;

static of_bsn_gentable_entry_add_t *
make_add(uint16_t table_id, uint32_t port, of_mac_addr_t mac)
{
    of_object_t *obj = of_bsn_gentable_entry_add_new(OF_VERSION_1_3);
    of_bsn_gentable_entry_add_xid_set(obj, 0x12345678);
    of_bsn_gentable_entry_add_table_id_set(obj, table_id);
    {
        of_checksum_128_t checksum = { 0xFEDCBA9876543210L, 0xFFEECCBBAA998877L };
        of_bsn_gentable_entry_add_checksum_set(obj, checksum);
    }
    {
        of_object_t list;
        of_bsn_gentable_entry_add_key_bind(obj, &list);
        {
            of_object_t *tlv = of_bsn_tlv_port_new(OF_VERSION_1_3);
            of_bsn_tlv_port_value_set(tlv, port);
            of_list_append(&list, tlv);
            of_object_delete(tlv);
        }
    }
    {
        of_object_t list;
        of_bsn_gentable_entry_add_value_bind(obj, &list);
        {
            of_object_t *tlv = of_bsn_tlv_mac_new(OF_VERSION_1_3);
            of_bsn_tlv_mac_value_set(tlv, mac);
            of_list_append(&list, tlv);
            of_object_delete(tlv);
        }
    }
    return obj;
}

int
test_gentable(void)
{
    int i;
    indigo_core_gentable_t *gentables[NUM_TABLES];

    for (i = 0; i < NUM_TABLES; i++) {
        of_table_name_t name;
        snprintf(name, sizeof(name), "gentable %d", i);
        indigo_core_gentable_register(name, &test_ops, INDIGO_COOKIE_TO_POINTER(i), 10, 8, &gentables[i]);
    }

    {
        of_bsn_gentable_entry_add_t *obj = make_add(0, 1, (of_mac_addr_t) { { 1, 2, 3, 4, 5, 6 } });
        indigo_core_receive_controller_message(0, obj);
    }

    for (i = 0; i < NUM_TABLES; i++) {
        indigo_core_gentable_unregister(gentables[i]);
    }

    return TEST_PASS;
}

static indigo_error_t
test_gentable_add(void *table_priv, of_list_bsn_tlv_t *key, of_list_bsn_tlv_t *value, void **entry_priv)
{
    *entry_priv = NULL;
    return INDIGO_ERROR_NONE;
}

static indigo_error_t
test_gentable_modify(void *table_priv, void *entry_priv, of_list_bsn_tlv_t *key, of_list_bsn_tlv_t *value)
{
    return INDIGO_ERROR_NONE;
}

static indigo_error_t
test_gentable_delete(void *table_priv, void *entry_priv, of_list_bsn_tlv_t *key)
{
    return INDIGO_ERROR_NONE;
}

static void
test_gentable_get_stats(void *table_priv, void *entry_priv, of_list_bsn_tlv_t *key, of_list_bsn_tlv_t *stats)
{
}

indigo_core_gentable_ops_t test_ops = {
    test_gentable_add,
    test_gentable_modify,
    test_gentable_delete,
    test_gentable_get_stats,
};
