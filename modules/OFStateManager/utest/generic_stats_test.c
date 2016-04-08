/****************************************************************
 *
 *        Copyright 2016, Big Switch Networks, Inc.
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
#include <SocketManager/socketmanager.h>

extern void handle_message(of_object_t *obj);
extern int do_barrier(void);

static int count1 = 0;
static int count2 = 0;

static void
handler(indigo_cxn_id_t cxn_id,
        const of_bsn_generic_stats_request_t *req,
        void *priv)
{
    (*(int *)priv)++;
}

static void
send_generic_stats_request(const char *name)
{
    of_object_t *req = of_bsn_generic_stats_request_new(OF_VERSION_1_4);
    of_str64_t name_buf = "";
    strncpy(name_buf, name, sizeof(name_buf));
    of_bsn_generic_stats_request_name_set(req, name_buf);
    handle_message(req);
    do_barrier();
}

int
test_generic_stats(void)
{
    send_generic_stats_request("stats1");
    AIM_ASSERT(count1 == 0);
    AIM_ASSERT(count2 == 0);

    indigo_core_generic_stats_register("stats1", handler, &count1);
    send_generic_stats_request("stats1");
    send_generic_stats_request("stats2");
    AIM_ASSERT(count1 == 1);
    AIM_ASSERT(count2 == 0);

    indigo_core_generic_stats_register("stats2", handler, &count2);
    send_generic_stats_request("stats1");
    send_generic_stats_request("stats2");
    AIM_ASSERT(count1 == 2);
    AIM_ASSERT(count2 == 1);

    indigo_core_generic_stats_unregister("stats1");
    send_generic_stats_request("stats1");
    send_generic_stats_request("stats2");
    AIM_ASSERT(count1 == 2);
    AIM_ASSERT(count2 == 2);

    indigo_core_generic_stats_unregister("stats2");
    send_generic_stats_request("stats1");
    send_generic_stats_request("stats2");
    AIM_ASSERT(count1 == 2);
    AIM_ASSERT(count2 == 2);

    return TEST_PASS;
}
