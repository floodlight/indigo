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
