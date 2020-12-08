/****************************************************************
 *
 *        Copyright 2015, Big Switch Networks, Inc.
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
#include <SocketManager/socketmanager.h>

#include "test_infra.h"

#define QUEUES_PER_PORT OFSTATEMANAGER_CONFIG_MAX_QUEUES/OFSTATEMANAGER_CONFIG_MAX_PORTS

struct port_counters {
    int stats;
    int desc_stats;
    int queue_desc_stats[QUEUES_PER_PORT];
    int queue_stats[QUEUES_PER_PORT];
};

extern void handle_message(of_object_t *obj);
extern int do_barrier(void);

struct port_counters port_counters[OFSTATEMANAGER_CONFIG_MAX_PORTS];

indigo_error_t
indigo_port_desc_stats_get_one(of_port_no_t port_no, of_port_desc_t *port_desc)
{
    of_object_t props;
    of_object_t prop;
    of_port_desc_properties_bind(port_desc, &props);
    of_port_desc_prop_ethernet_init(&prop, props.version, -1, 1);
    if (of_list_port_desc_prop_append_bind(&props, &prop) < 0) {
        AIM_DIE("unexpected error appending to port desc stats properties");
    }

    port_counters[port_no].desc_stats++;
    return INDIGO_ERROR_NONE;
}

indigo_error_t
indigo_port_stats_get_one(of_port_no_t port_no, of_port_stats_entry_t *port_stats)
{
    of_object_t props;
    of_object_t prop;
    of_port_stats_entry_properties_bind(port_stats, &props);
    of_port_stats_prop_ethernet_init(&prop, props.version, -1, 1);
    if (of_list_port_stats_prop_append_bind(&props, &prop) < 0) {
        AIM_DIE("unexpected error appending to port stats properties");
    }

    port_counters[port_no].stats++;
    return INDIGO_ERROR_NONE;
}

indigo_error_t
indigo_port_queue_stats_get_one(of_port_no_t port_no, uint32_t queue_id, of_queue_stats_entry_t *queue_stats)
{
    port_counters[port_no].queue_stats[queue_id]++;
    return INDIGO_ERROR_NONE;
}

indigo_error_t
indigo_port_queue_desc_get_one(of_port_no_t port_no, uint32_t queue_id, of_queue_desc_t *queue_desc)
{
    port_counters[port_no].queue_desc_stats[queue_id]++;
    return INDIGO_ERROR_NONE;
}

static int
test_port_desc_stats(void)
{
    struct ind_core_port *handle1, *handle2;
    indigo_core_port_register(1, &handle1);
    indigo_core_port_register(2, &handle2);

    memset(port_counters, 0, sizeof(port_counters));

    of_port_desc_stats_request_t *obj = of_port_desc_stats_request_new(OF_VERSION_1_4);
    handle_message(obj);
    do_barrier();

    AIM_TRUE_OR_DIE(port_counters[1].desc_stats == 1);
    AIM_TRUE_OR_DIE(port_counters[2].desc_stats == 1);

    indigo_core_port_unregister(handle1);
    indigo_core_port_unregister(handle2);

    return TEST_PASS;
}

static int
test_port_stats(void)
{
    struct ind_core_port *handle1, *handle2;
    indigo_core_port_register(1, &handle1);
    indigo_core_port_register(2, &handle2);

    /* Request for OFPP_ANY */
    memset(port_counters, 0, sizeof(port_counters));
    of_port_stats_request_t *obj = of_port_stats_request_new(OF_VERSION_1_4);
    of_port_stats_request_port_no_set(obj, OF_PORT_DEST_WILDCARD);
    handle_message(obj);
    do_barrier();

    AIM_TRUE_OR_DIE(port_counters[1].stats == 1);
    AIM_TRUE_OR_DIE(port_counters[2].stats == 1);

    /* Request for a single port */
    memset(port_counters, 0, sizeof(port_counters));
    obj = of_port_stats_request_new(OF_VERSION_1_4);
    of_port_stats_request_port_no_set(obj, 2);
    handle_message(obj);
    do_barrier();

    AIM_TRUE_OR_DIE(port_counters[1].stats == 0);
    AIM_TRUE_OR_DIE(port_counters[2].stats == 1);

    indigo_core_port_unregister(handle1);
    indigo_core_port_unregister(handle2);

    return TEST_PASS;
}

static int
test_queue_stats(void)
{
    struct ind_core_port *handle1, *handle2;
    indigo_core_port_register(1, &handle1);
    indigo_core_port_register(2, &handle2);

    struct ind_core_queue *queue1_3, *queue1_4, *queue2_3, *queue2_4;
    indigo_core_queue_register(1, 3, &queue1_3);
    indigo_core_queue_register(1, 4, &queue1_4);
    indigo_core_queue_register(2, 3, &queue2_3);
    indigo_core_queue_register(2, 4, &queue2_4);

    /* Request for OFPP_ANY, OF_QUEUE_ALL */
    memset(port_counters, 0, sizeof(port_counters));
    of_queue_stats_request_t *obj = of_queue_stats_request_new(OF_VERSION_1_4);
    of_queue_stats_request_port_no_set(obj, OF_PORT_DEST_WILDCARD);
    of_queue_stats_request_queue_id_set(obj, OF_QUEUE_ALL);
    handle_message(obj);
    do_barrier();

    AIM_TRUE_OR_DIE(port_counters[1].queue_stats[3] == 1);
    AIM_TRUE_OR_DIE(port_counters[1].queue_stats[4] == 1);
    AIM_TRUE_OR_DIE(port_counters[2].queue_stats[3] == 1);
    AIM_TRUE_OR_DIE(port_counters[2].queue_stats[4] == 1);

    /* Request for a single port, OF_QUEUE_ALL */
    memset(port_counters, 0, sizeof(port_counters));
    obj = of_queue_stats_request_new(OF_VERSION_1_4);
    of_queue_stats_request_port_no_set(obj, 2);
    of_queue_stats_request_queue_id_set(obj, OF_QUEUE_ALL);
    handle_message(obj);
    do_barrier();

    AIM_TRUE_OR_DIE(port_counters[1].queue_stats[3] == 0);
    AIM_TRUE_OR_DIE(port_counters[1].queue_stats[4] == 0);
    AIM_TRUE_OR_DIE(port_counters[2].queue_stats[3] == 1);
    AIM_TRUE_OR_DIE(port_counters[2].queue_stats[4] == 1);

    /* Request for OFPP_ANY, a single queue */
    memset(port_counters, 0, sizeof(port_counters));
    obj = of_queue_stats_request_new(OF_VERSION_1_4);
    of_queue_stats_request_port_no_set(obj, OF_PORT_DEST_WILDCARD);
    of_queue_stats_request_queue_id_set(obj, 4);
    handle_message(obj);
    do_barrier();

    AIM_TRUE_OR_DIE(port_counters[1].queue_stats[3] == 0);
    AIM_TRUE_OR_DIE(port_counters[1].queue_stats[4] == 1);
    AIM_TRUE_OR_DIE(port_counters[2].queue_stats[3] == 0);
    AIM_TRUE_OR_DIE(port_counters[2].queue_stats[4] == 1);

    /* Request for a single port and queue */
    memset(port_counters, 0, sizeof(port_counters));
    obj = of_queue_stats_request_new(OF_VERSION_1_4);
    of_queue_stats_request_port_no_set(obj, 2);
    of_queue_stats_request_queue_id_set(obj, 4);
    handle_message(obj);
    do_barrier();

    AIM_TRUE_OR_DIE(port_counters[1].queue_stats[3] == 0);
    AIM_TRUE_OR_DIE(port_counters[1].queue_stats[4] == 0);
    AIM_TRUE_OR_DIE(port_counters[2].queue_stats[3] == 0);
    AIM_TRUE_OR_DIE(port_counters[2].queue_stats[4] == 1);

    indigo_core_queue_unregister(queue1_3);
    indigo_core_queue_unregister(queue1_4);
    indigo_core_queue_unregister(queue2_3);
    indigo_core_queue_unregister(queue2_4);
    indigo_core_port_unregister(handle1);
    indigo_core_port_unregister(handle2);

    return TEST_PASS;
}

static int
test_queue_desc_stats(void)
{
    struct ind_core_port *handle1, *handle2;
    indigo_core_port_register(1, &handle1);
    indigo_core_port_register(2, &handle2);

    struct ind_core_queue *queue1_3, *queue1_4, *queue2_3, *queue2_4;
    indigo_core_queue_register(1, 3, &queue1_3);
    indigo_core_queue_register(1, 4, &queue1_4);
    indigo_core_queue_register(2, 3, &queue2_3);
    indigo_core_queue_register(2, 4, &queue2_4);

    /* Request for OFPP_ANY, OF_QUEUE_ALL */
    memset(port_counters, 0, sizeof(port_counters));
    of_queue_desc_stats_request_t *obj = of_queue_desc_stats_request_new(OF_VERSION_1_4);
    of_queue_desc_stats_request_port_no_set(obj, OF_PORT_DEST_WILDCARD);
    of_queue_desc_stats_request_queue_id_set(obj, OF_QUEUE_ALL);
    handle_message(obj);
    do_barrier();

    AIM_TRUE_OR_DIE(port_counters[1].queue_desc_stats[3] == 1);
    AIM_TRUE_OR_DIE(port_counters[1].queue_desc_stats[4] == 1);
    AIM_TRUE_OR_DIE(port_counters[2].queue_desc_stats[3] == 1);
    AIM_TRUE_OR_DIE(port_counters[2].queue_desc_stats[4] == 1);

    /* Request for a single port, OF_QUEUE_ALL */
    memset(port_counters, 0, sizeof(port_counters));
    obj = of_queue_desc_stats_request_new(OF_VERSION_1_4);
    of_queue_desc_stats_request_port_no_set(obj, 2);
    of_queue_desc_stats_request_queue_id_set(obj, OF_QUEUE_ALL);
    handle_message(obj);
    do_barrier();

    AIM_TRUE_OR_DIE(port_counters[1].queue_desc_stats[3] == 0);
    AIM_TRUE_OR_DIE(port_counters[1].queue_desc_stats[4] == 0);
    AIM_TRUE_OR_DIE(port_counters[2].queue_desc_stats[3] == 1);
    AIM_TRUE_OR_DIE(port_counters[2].queue_desc_stats[4] == 1);

    /* Request for OFPP_ANY, a single queue */
    memset(port_counters, 0, sizeof(port_counters));
    obj = of_queue_desc_stats_request_new(OF_VERSION_1_4);
    of_queue_desc_stats_request_port_no_set(obj, OF_PORT_DEST_WILDCARD);
    of_queue_desc_stats_request_queue_id_set(obj, 4);
    handle_message(obj);
    do_barrier();

    AIM_TRUE_OR_DIE(port_counters[1].queue_desc_stats[3] == 0);
    AIM_TRUE_OR_DIE(port_counters[1].queue_desc_stats[4] == 1);
    AIM_TRUE_OR_DIE(port_counters[2].queue_desc_stats[3] == 0);
    AIM_TRUE_OR_DIE(port_counters[2].queue_desc_stats[4] == 1);

    /* Request for a single port and queue */
    memset(port_counters, 0, sizeof(port_counters));
    obj = of_queue_desc_stats_request_new(OF_VERSION_1_4);
    of_queue_desc_stats_request_port_no_set(obj, 2);
    of_queue_desc_stats_request_queue_id_set(obj, 4);
    handle_message(obj);
    do_barrier();

    AIM_TRUE_OR_DIE(port_counters[1].queue_desc_stats[3] == 0);
    AIM_TRUE_OR_DIE(port_counters[1].queue_desc_stats[4] == 0);
    AIM_TRUE_OR_DIE(port_counters[2].queue_desc_stats[3] == 0);
    AIM_TRUE_OR_DIE(port_counters[2].queue_desc_stats[4] == 1);

    indigo_core_queue_unregister(queue1_3);
    indigo_core_queue_unregister(queue1_4);
    indigo_core_queue_unregister(queue2_3);
    indigo_core_queue_unregister(queue2_4);
    indigo_core_port_unregister(handle1);
    indigo_core_port_unregister(handle2);

    return TEST_PASS;
}

static int
test_queue_desc_stats_multipart(void)
{
    int i, j;
    struct ind_core_port *port_handles[OFSTATEMANAGER_CONFIG_MAX_PORTS];
    struct ind_core_queue *queue_handles[OFSTATEMANAGER_CONFIG_MAX_PORTS];
    const int qid = 3;

    for (i = 0; i < OFSTATEMANAGER_CONFIG_MAX_PORTS; i++) {
        indigo_core_port_register(i, &port_handles[i]);
        indigo_core_queue_register(i, qid, &queue_handles[i]);
    }

    memset(port_counters, 0, sizeof(port_counters));
    of_queue_desc_stats_request_t *obj = of_queue_desc_stats_request_new(OF_VERSION_1_4);
    of_queue_desc_stats_request_port_no_set(obj, OF_PORT_DEST_WILDCARD);
    of_queue_desc_stats_request_queue_id_set(obj, OF_QUEUE_ALL);
    handle_message(obj);
    do_barrier();

    for (i = 0; i < OFSTATEMANAGER_CONFIG_MAX_PORTS; i++) {
        for (j = 0; j < QUEUES_PER_PORT; j++) {
            AIM_TRUE_OR_DIE(port_counters[i].queue_desc_stats[j] ==
                            (j == qid)? 1: 0);
        }
    }

    for (i = 0; i < OFSTATEMANAGER_CONFIG_MAX_PORTS; i++) {
        indigo_core_queue_unregister(queue_handles[i]);
        indigo_core_port_unregister(port_handles[i]);
    }

    return TEST_PASS;
}

static int
test_port_desc_stats_multipart(void)
{
    int i;
    struct ind_core_port *port_handles[OFSTATEMANAGER_CONFIG_MAX_PORTS];

    for (i = 0; i < OFSTATEMANAGER_CONFIG_MAX_PORTS; i++) {
        indigo_core_port_register(i, &port_handles[i]);
    }

    memset(port_counters, 0, sizeof(port_counters));
    of_port_desc_stats_request_t *obj = of_port_desc_stats_request_new(OF_VERSION_1_4);
    handle_message(obj);
    do_barrier();

    for (i = 0; i < OFSTATEMANAGER_CONFIG_MAX_PORTS; i++) {
        AIM_TRUE_OR_DIE(port_counters[i].desc_stats == 1);
    }

    for (i = 0; i < OFSTATEMANAGER_CONFIG_MAX_PORTS; i++) {
        indigo_core_port_unregister(port_handles[i]);
    }

    return TEST_PASS;
}

static int
test_port_stats_multipart(void)
{
    int i;
    struct ind_core_port *port_handles[OFSTATEMANAGER_CONFIG_MAX_PORTS];

    for (i = 0; i < OFSTATEMANAGER_CONFIG_MAX_PORTS; i++) {
        indigo_core_port_register(i, &port_handles[i]);
    }

    memset(port_counters, 0, sizeof(port_counters));
    of_port_stats_request_t *obj = of_port_stats_request_new(OF_VERSION_1_4);
    of_port_stats_request_port_no_set(obj, OF_PORT_DEST_WILDCARD);
    handle_message(obj);
    do_barrier();

    for (i = 0; i < OFSTATEMANAGER_CONFIG_MAX_PORTS; i++) {
        AIM_TRUE_OR_DIE(port_counters[i].stats == 1);
    }

    for (i = 0; i < OFSTATEMANAGER_CONFIG_MAX_PORTS; i++) {
        indigo_core_port_unregister(port_handles[i]);
    }

    return TEST_PASS;
}

static int
test_queue_stats_multipart(void)
{
    int i, j;
    struct ind_core_port *port_handles[OFSTATEMANAGER_CONFIG_MAX_PORTS];
    struct ind_core_queue *queue_handles[OFSTATEMANAGER_CONFIG_MAX_PORTS][QUEUES_PER_PORT];

    for (i = 0; i < OFSTATEMANAGER_CONFIG_MAX_PORTS; i++) {
        indigo_core_port_register(i, &port_handles[i]);
        for (j = 0; j < QUEUES_PER_PORT; j++) {
            indigo_core_queue_register(i, j, &queue_handles[i][j]);
        }
    }

    memset(port_counters, 0, sizeof(port_counters));
    of_queue_stats_request_t *obj = of_queue_stats_request_new(OF_VERSION_1_4);
    of_queue_stats_request_port_no_set(obj, OF_PORT_DEST_WILDCARD);
    of_queue_stats_request_queue_id_set(obj, OF_QUEUE_ALL);
    handle_message(obj);
    do_barrier();

    for (i = 0; i < OFSTATEMANAGER_CONFIG_MAX_PORTS; i++) {
        for (j = 0; j < QUEUES_PER_PORT; j++) {
            AIM_TRUE_OR_DIE(port_counters[i].queue_stats[j] == 1);
        }
    }

    for (i = 0; i < OFSTATEMANAGER_CONFIG_MAX_PORTS; i++) {
        for (j = 0; j < QUEUES_PER_PORT; j++) {
            indigo_core_queue_unregister(queue_handles[i][j]);
        }
        indigo_core_port_unregister(port_handles[i]);
    }

    return TEST_PASS;
}

int
test_port_registration(void)
{
    RUN_TEST(port_desc_stats);
    RUN_TEST(port_stats);
    RUN_TEST(queue_stats);
    RUN_TEST(queue_desc_stats);
    RUN_TEST(queue_desc_stats_multipart);
    RUN_TEST(port_desc_stats_multipart);
    RUN_TEST(port_stats_multipart);
    RUN_TEST(queue_stats_multipart);
    return TEST_PASS;
}
