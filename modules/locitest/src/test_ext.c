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

/* Copyright 2012, Big Switch Networks, Inc. */

/**
 * Test extensions
 */

#include <locitest/test_common.h>

/**
 * Simple tests for extension objects
 */

int
test_ext_objs(void)
{
    of_action_bsn_mirror_t *obj;

    obj = of_action_bsn_mirror_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_BSN_MIRROR);

    TEST_ASSERT(of_action_to_object_id(OF_EXPERIMENTER_TYPE, OF_VERSION_1_0) ==
                OF_ACTION_EXPERIMENTER);

    TEST_ASSERT(of_action_id_to_object_id(OF_EXPERIMENTER_TYPE, OF_VERSION_1_0) ==
                OF_ACTION_ID_EXPERIMENTER);

    TEST_ASSERT(of_instruction_to_object_id(OF_EXPERIMENTER_TYPE, OF_VERSION_1_0) ==
                OF_INSTRUCTION_EXPERIMENTER);

    TEST_ASSERT(of_queue_prop_to_object_id(OF_EXPERIMENTER_TYPE, OF_VERSION_1_0) ==
                OF_QUEUE_PROP_EXPERIMENTER);

    TEST_ASSERT(of_meter_band_to_object_id(OF_EXPERIMENTER_TYPE, OF_VERSION_1_0) ==
                OF_METER_BAND_EXPERIMENTER);

    TEST_ASSERT(of_table_feature_prop_to_object_id(OF_EXPERIMENTER_TYPE,
                                                   OF_VERSION_1_3) ==
                OF_TABLE_FEATURE_PROP_EXPERIMENTER);

    return TEST_PASS;
}
