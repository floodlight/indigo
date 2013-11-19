/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */

/**
 *
 * AUTOMATICALLY GENERATED FILE.  Edits will be lost on regen.
 *
 * Message-scalar tests for all versions
 */

#include <locitest/test_common.h>

/**
 * Baseline list tests for version OF_VERSION_1_0
 */

static int
test_of_list_action_OF_VERSION_1_0(void)
{
    of_list_action_t *list;
    int value = 1;

    list = of_list_action_new(OF_VERSION_1_0);
    TEST_ASSERT(list != NULL);
    TEST_ASSERT(list->version == OF_VERSION_1_0);
    TEST_ASSERT(list->length == 0);
    TEST_ASSERT(list->parent == NULL);
    TEST_ASSERT(list->object_id == OF_LIST_ACTION);

    value = list_setup_of_list_action_OF_VERSION_1_0(list, value);
    TEST_ASSERT(value != 0);

    /* Now check values */
    value = 1;
    value = list_check_of_list_action_OF_VERSION_1_0(list, value);
    TEST_ASSERT(value != 0);

    of_list_action_delete(list);

    return TEST_PASS;
}

static int
test_of_list_bsn_interface_OF_VERSION_1_0(void)
{
    of_list_bsn_interface_t *list;
    int value = 1;

    list = of_list_bsn_interface_new(OF_VERSION_1_0);
    TEST_ASSERT(list != NULL);
    TEST_ASSERT(list->version == OF_VERSION_1_0);
    TEST_ASSERT(list->length == 0);
    TEST_ASSERT(list->parent == NULL);
    TEST_ASSERT(list->object_id == OF_LIST_BSN_INTERFACE);

    value = list_setup_of_list_bsn_interface_OF_VERSION_1_0(list, value);
    TEST_ASSERT(value != 0);

    /* Now check values */
    value = 1;
    value = list_check_of_list_bsn_interface_OF_VERSION_1_0(list, value);
    TEST_ASSERT(value != 0);

    of_list_bsn_interface_delete(list);

    return TEST_PASS;
}

static int
test_of_list_flow_stats_entry_OF_VERSION_1_0(void)
{
    of_list_flow_stats_entry_t *list;
    int value = 1;

    list = of_list_flow_stats_entry_new(OF_VERSION_1_0);
    TEST_ASSERT(list != NULL);
    TEST_ASSERT(list->version == OF_VERSION_1_0);
    TEST_ASSERT(list->length == 0);
    TEST_ASSERT(list->parent == NULL);
    TEST_ASSERT(list->object_id == OF_LIST_FLOW_STATS_ENTRY);

    value = list_setup_of_list_flow_stats_entry_OF_VERSION_1_0(list, value);
    TEST_ASSERT(value != 0);

    /* Now check values */
    value = 1;
    value = list_check_of_list_flow_stats_entry_OF_VERSION_1_0(list, value);
    TEST_ASSERT(value != 0);

    of_list_flow_stats_entry_delete(list);

    return TEST_PASS;
}

static int
test_of_list_packet_queue_OF_VERSION_1_0(void)
{
    of_list_packet_queue_t *list;
    int value = 1;

    list = of_list_packet_queue_new(OF_VERSION_1_0);
    TEST_ASSERT(list != NULL);
    TEST_ASSERT(list->version == OF_VERSION_1_0);
    TEST_ASSERT(list->length == 0);
    TEST_ASSERT(list->parent == NULL);
    TEST_ASSERT(list->object_id == OF_LIST_PACKET_QUEUE);

    value = list_setup_of_list_packet_queue_OF_VERSION_1_0(list, value);
    TEST_ASSERT(value != 0);

    /* Now check values */
    value = 1;
    value = list_check_of_list_packet_queue_OF_VERSION_1_0(list, value);
    TEST_ASSERT(value != 0);

    of_list_packet_queue_delete(list);

    return TEST_PASS;
}

static int
test_of_list_port_desc_OF_VERSION_1_0(void)
{
    of_list_port_desc_t *list;
    int value = 1;

    list = of_list_port_desc_new(OF_VERSION_1_0);
    TEST_ASSERT(list != NULL);
    TEST_ASSERT(list->version == OF_VERSION_1_0);
    TEST_ASSERT(list->length == 0);
    TEST_ASSERT(list->parent == NULL);
    TEST_ASSERT(list->object_id == OF_LIST_PORT_DESC);

    value = list_setup_of_list_port_desc_OF_VERSION_1_0(list, value);
    TEST_ASSERT(value != 0);

    /* Now check values */
    value = 1;
    value = list_check_of_list_port_desc_OF_VERSION_1_0(list, value);
    TEST_ASSERT(value != 0);

    of_list_port_desc_delete(list);

    return TEST_PASS;
}

static int
test_of_list_port_stats_entry_OF_VERSION_1_0(void)
{
    of_list_port_stats_entry_t *list;
    int value = 1;

    list = of_list_port_stats_entry_new(OF_VERSION_1_0);
    TEST_ASSERT(list != NULL);
    TEST_ASSERT(list->version == OF_VERSION_1_0);
    TEST_ASSERT(list->length == 0);
    TEST_ASSERT(list->parent == NULL);
    TEST_ASSERT(list->object_id == OF_LIST_PORT_STATS_ENTRY);

    value = list_setup_of_list_port_stats_entry_OF_VERSION_1_0(list, value);
    TEST_ASSERT(value != 0);

    /* Now check values */
    value = 1;
    value = list_check_of_list_port_stats_entry_OF_VERSION_1_0(list, value);
    TEST_ASSERT(value != 0);

    of_list_port_stats_entry_delete(list);

    return TEST_PASS;
}

static int
test_of_list_queue_prop_OF_VERSION_1_0(void)
{
    of_list_queue_prop_t *list;
    int value = 1;

    list = of_list_queue_prop_new(OF_VERSION_1_0);
    TEST_ASSERT(list != NULL);
    TEST_ASSERT(list->version == OF_VERSION_1_0);
    TEST_ASSERT(list->length == 0);
    TEST_ASSERT(list->parent == NULL);
    TEST_ASSERT(list->object_id == OF_LIST_QUEUE_PROP);

    value = list_setup_of_list_queue_prop_OF_VERSION_1_0(list, value);
    TEST_ASSERT(value != 0);

    /* Now check values */
    value = 1;
    value = list_check_of_list_queue_prop_OF_VERSION_1_0(list, value);
    TEST_ASSERT(value != 0);

    of_list_queue_prop_delete(list);

    return TEST_PASS;
}

static int
test_of_list_queue_stats_entry_OF_VERSION_1_0(void)
{
    of_list_queue_stats_entry_t *list;
    int value = 1;

    list = of_list_queue_stats_entry_new(OF_VERSION_1_0);
    TEST_ASSERT(list != NULL);
    TEST_ASSERT(list->version == OF_VERSION_1_0);
    TEST_ASSERT(list->length == 0);
    TEST_ASSERT(list->parent == NULL);
    TEST_ASSERT(list->object_id == OF_LIST_QUEUE_STATS_ENTRY);

    value = list_setup_of_list_queue_stats_entry_OF_VERSION_1_0(list, value);
    TEST_ASSERT(value != 0);

    /* Now check values */
    value = 1;
    value = list_check_of_list_queue_stats_entry_OF_VERSION_1_0(list, value);
    TEST_ASSERT(value != 0);

    of_list_queue_stats_entry_delete(list);

    return TEST_PASS;
}

static int
test_of_list_table_stats_entry_OF_VERSION_1_0(void)
{
    of_list_table_stats_entry_t *list;
    int value = 1;

    list = of_list_table_stats_entry_new(OF_VERSION_1_0);
    TEST_ASSERT(list != NULL);
    TEST_ASSERT(list->version == OF_VERSION_1_0);
    TEST_ASSERT(list->length == 0);
    TEST_ASSERT(list->parent == NULL);
    TEST_ASSERT(list->object_id == OF_LIST_TABLE_STATS_ENTRY);

    value = list_setup_of_list_table_stats_entry_OF_VERSION_1_0(list, value);
    TEST_ASSERT(value != 0);

    /* Now check values */
    value = 1;
    value = list_check_of_list_table_stats_entry_OF_VERSION_1_0(list, value);
    TEST_ASSERT(value != 0);

    of_list_table_stats_entry_delete(list);

    return TEST_PASS;
}

/**
 * Baseline list tests for version OF_VERSION_1_1
 */

static int
test_of_list_action_OF_VERSION_1_1(void)
{
    of_list_action_t *list;
    int value = 1;

    list = of_list_action_new(OF_VERSION_1_1);
    TEST_ASSERT(list != NULL);
    TEST_ASSERT(list->version == OF_VERSION_1_1);
    TEST_ASSERT(list->length == 0);
    TEST_ASSERT(list->parent == NULL);
    TEST_ASSERT(list->object_id == OF_LIST_ACTION);

    value = list_setup_of_list_action_OF_VERSION_1_1(list, value);
    TEST_ASSERT(value != 0);

    /* Now check values */
    value = 1;
    value = list_check_of_list_action_OF_VERSION_1_1(list, value);
    TEST_ASSERT(value != 0);

    of_list_action_delete(list);

    return TEST_PASS;
}

static int
test_of_list_bsn_interface_OF_VERSION_1_1(void)
{
    of_list_bsn_interface_t *list;
    int value = 1;

    list = of_list_bsn_interface_new(OF_VERSION_1_1);
    TEST_ASSERT(list != NULL);
    TEST_ASSERT(list->version == OF_VERSION_1_1);
    TEST_ASSERT(list->length == 0);
    TEST_ASSERT(list->parent == NULL);
    TEST_ASSERT(list->object_id == OF_LIST_BSN_INTERFACE);

    value = list_setup_of_list_bsn_interface_OF_VERSION_1_1(list, value);
    TEST_ASSERT(value != 0);

    /* Now check values */
    value = 1;
    value = list_check_of_list_bsn_interface_OF_VERSION_1_1(list, value);
    TEST_ASSERT(value != 0);

    of_list_bsn_interface_delete(list);

    return TEST_PASS;
}

static int
test_of_list_bucket_OF_VERSION_1_1(void)
{
    of_list_bucket_t *list;
    int value = 1;

    list = of_list_bucket_new(OF_VERSION_1_1);
    TEST_ASSERT(list != NULL);
    TEST_ASSERT(list->version == OF_VERSION_1_1);
    TEST_ASSERT(list->length == 0);
    TEST_ASSERT(list->parent == NULL);
    TEST_ASSERT(list->object_id == OF_LIST_BUCKET);

    value = list_setup_of_list_bucket_OF_VERSION_1_1(list, value);
    TEST_ASSERT(value != 0);

    /* Now check values */
    value = 1;
    value = list_check_of_list_bucket_OF_VERSION_1_1(list, value);
    TEST_ASSERT(value != 0);

    of_list_bucket_delete(list);

    return TEST_PASS;
}

static int
test_of_list_bucket_counter_OF_VERSION_1_1(void)
{
    of_list_bucket_counter_t *list;
    int value = 1;

    list = of_list_bucket_counter_new(OF_VERSION_1_1);
    TEST_ASSERT(list != NULL);
    TEST_ASSERT(list->version == OF_VERSION_1_1);
    TEST_ASSERT(list->length == 0);
    TEST_ASSERT(list->parent == NULL);
    TEST_ASSERT(list->object_id == OF_LIST_BUCKET_COUNTER);

    value = list_setup_of_list_bucket_counter_OF_VERSION_1_1(list, value);
    TEST_ASSERT(value != 0);

    /* Now check values */
    value = 1;
    value = list_check_of_list_bucket_counter_OF_VERSION_1_1(list, value);
    TEST_ASSERT(value != 0);

    of_list_bucket_counter_delete(list);

    return TEST_PASS;
}

static int
test_of_list_flow_stats_entry_OF_VERSION_1_1(void)
{
    of_list_flow_stats_entry_t *list;
    int value = 1;

    list = of_list_flow_stats_entry_new(OF_VERSION_1_1);
    TEST_ASSERT(list != NULL);
    TEST_ASSERT(list->version == OF_VERSION_1_1);
    TEST_ASSERT(list->length == 0);
    TEST_ASSERT(list->parent == NULL);
    TEST_ASSERT(list->object_id == OF_LIST_FLOW_STATS_ENTRY);

    value = list_setup_of_list_flow_stats_entry_OF_VERSION_1_1(list, value);
    TEST_ASSERT(value != 0);

    /* Now check values */
    value = 1;
    value = list_check_of_list_flow_stats_entry_OF_VERSION_1_1(list, value);
    TEST_ASSERT(value != 0);

    of_list_flow_stats_entry_delete(list);

    return TEST_PASS;
}

static int
test_of_list_group_desc_stats_entry_OF_VERSION_1_1(void)
{
    of_list_group_desc_stats_entry_t *list;
    int value = 1;

    list = of_list_group_desc_stats_entry_new(OF_VERSION_1_1);
    TEST_ASSERT(list != NULL);
    TEST_ASSERT(list->version == OF_VERSION_1_1);
    TEST_ASSERT(list->length == 0);
    TEST_ASSERT(list->parent == NULL);
    TEST_ASSERT(list->object_id == OF_LIST_GROUP_DESC_STATS_ENTRY);

    value = list_setup_of_list_group_desc_stats_entry_OF_VERSION_1_1(list, value);
    TEST_ASSERT(value != 0);

    /* Now check values */
    value = 1;
    value = list_check_of_list_group_desc_stats_entry_OF_VERSION_1_1(list, value);
    TEST_ASSERT(value != 0);

    of_list_group_desc_stats_entry_delete(list);

    return TEST_PASS;
}

static int
test_of_list_group_stats_entry_OF_VERSION_1_1(void)
{
    of_list_group_stats_entry_t *list;
    int value = 1;

    list = of_list_group_stats_entry_new(OF_VERSION_1_1);
    TEST_ASSERT(list != NULL);
    TEST_ASSERT(list->version == OF_VERSION_1_1);
    TEST_ASSERT(list->length == 0);
    TEST_ASSERT(list->parent == NULL);
    TEST_ASSERT(list->object_id == OF_LIST_GROUP_STATS_ENTRY);

    value = list_setup_of_list_group_stats_entry_OF_VERSION_1_1(list, value);
    TEST_ASSERT(value != 0);

    /* Now check values */
    value = 1;
    value = list_check_of_list_group_stats_entry_OF_VERSION_1_1(list, value);
    TEST_ASSERT(value != 0);

    of_list_group_stats_entry_delete(list);

    return TEST_PASS;
}

static int
test_of_list_instruction_OF_VERSION_1_1(void)
{
    of_list_instruction_t *list;
    int value = 1;

    list = of_list_instruction_new(OF_VERSION_1_1);
    TEST_ASSERT(list != NULL);
    TEST_ASSERT(list->version == OF_VERSION_1_1);
    TEST_ASSERT(list->length == 0);
    TEST_ASSERT(list->parent == NULL);
    TEST_ASSERT(list->object_id == OF_LIST_INSTRUCTION);

    value = list_setup_of_list_instruction_OF_VERSION_1_1(list, value);
    TEST_ASSERT(value != 0);

    /* Now check values */
    value = 1;
    value = list_check_of_list_instruction_OF_VERSION_1_1(list, value);
    TEST_ASSERT(value != 0);

    of_list_instruction_delete(list);

    return TEST_PASS;
}

static int
test_of_list_packet_queue_OF_VERSION_1_1(void)
{
    of_list_packet_queue_t *list;
    int value = 1;

    list = of_list_packet_queue_new(OF_VERSION_1_1);
    TEST_ASSERT(list != NULL);
    TEST_ASSERT(list->version == OF_VERSION_1_1);
    TEST_ASSERT(list->length == 0);
    TEST_ASSERT(list->parent == NULL);
    TEST_ASSERT(list->object_id == OF_LIST_PACKET_QUEUE);

    value = list_setup_of_list_packet_queue_OF_VERSION_1_1(list, value);
    TEST_ASSERT(value != 0);

    /* Now check values */
    value = 1;
    value = list_check_of_list_packet_queue_OF_VERSION_1_1(list, value);
    TEST_ASSERT(value != 0);

    of_list_packet_queue_delete(list);

    return TEST_PASS;
}

static int
test_of_list_port_desc_OF_VERSION_1_1(void)
{
    of_list_port_desc_t *list;
    int value = 1;

    list = of_list_port_desc_new(OF_VERSION_1_1);
    TEST_ASSERT(list != NULL);
    TEST_ASSERT(list->version == OF_VERSION_1_1);
    TEST_ASSERT(list->length == 0);
    TEST_ASSERT(list->parent == NULL);
    TEST_ASSERT(list->object_id == OF_LIST_PORT_DESC);

    value = list_setup_of_list_port_desc_OF_VERSION_1_1(list, value);
    TEST_ASSERT(value != 0);

    /* Now check values */
    value = 1;
    value = list_check_of_list_port_desc_OF_VERSION_1_1(list, value);
    TEST_ASSERT(value != 0);

    of_list_port_desc_delete(list);

    return TEST_PASS;
}

static int
test_of_list_port_stats_entry_OF_VERSION_1_1(void)
{
    of_list_port_stats_entry_t *list;
    int value = 1;

    list = of_list_port_stats_entry_new(OF_VERSION_1_1);
    TEST_ASSERT(list != NULL);
    TEST_ASSERT(list->version == OF_VERSION_1_1);
    TEST_ASSERT(list->length == 0);
    TEST_ASSERT(list->parent == NULL);
    TEST_ASSERT(list->object_id == OF_LIST_PORT_STATS_ENTRY);

    value = list_setup_of_list_port_stats_entry_OF_VERSION_1_1(list, value);
    TEST_ASSERT(value != 0);

    /* Now check values */
    value = 1;
    value = list_check_of_list_port_stats_entry_OF_VERSION_1_1(list, value);
    TEST_ASSERT(value != 0);

    of_list_port_stats_entry_delete(list);

    return TEST_PASS;
}

static int
test_of_list_queue_prop_OF_VERSION_1_1(void)
{
    of_list_queue_prop_t *list;
    int value = 1;

    list = of_list_queue_prop_new(OF_VERSION_1_1);
    TEST_ASSERT(list != NULL);
    TEST_ASSERT(list->version == OF_VERSION_1_1);
    TEST_ASSERT(list->length == 0);
    TEST_ASSERT(list->parent == NULL);
    TEST_ASSERT(list->object_id == OF_LIST_QUEUE_PROP);

    value = list_setup_of_list_queue_prop_OF_VERSION_1_1(list, value);
    TEST_ASSERT(value != 0);

    /* Now check values */
    value = 1;
    value = list_check_of_list_queue_prop_OF_VERSION_1_1(list, value);
    TEST_ASSERT(value != 0);

    of_list_queue_prop_delete(list);

    return TEST_PASS;
}

static int
test_of_list_queue_stats_entry_OF_VERSION_1_1(void)
{
    of_list_queue_stats_entry_t *list;
    int value = 1;

    list = of_list_queue_stats_entry_new(OF_VERSION_1_1);
    TEST_ASSERT(list != NULL);
    TEST_ASSERT(list->version == OF_VERSION_1_1);
    TEST_ASSERT(list->length == 0);
    TEST_ASSERT(list->parent == NULL);
    TEST_ASSERT(list->object_id == OF_LIST_QUEUE_STATS_ENTRY);

    value = list_setup_of_list_queue_stats_entry_OF_VERSION_1_1(list, value);
    TEST_ASSERT(value != 0);

    /* Now check values */
    value = 1;
    value = list_check_of_list_queue_stats_entry_OF_VERSION_1_1(list, value);
    TEST_ASSERT(value != 0);

    of_list_queue_stats_entry_delete(list);

    return TEST_PASS;
}

static int
test_of_list_table_stats_entry_OF_VERSION_1_1(void)
{
    of_list_table_stats_entry_t *list;
    int value = 1;

    list = of_list_table_stats_entry_new(OF_VERSION_1_1);
    TEST_ASSERT(list != NULL);
    TEST_ASSERT(list->version == OF_VERSION_1_1);
    TEST_ASSERT(list->length == 0);
    TEST_ASSERT(list->parent == NULL);
    TEST_ASSERT(list->object_id == OF_LIST_TABLE_STATS_ENTRY);

    value = list_setup_of_list_table_stats_entry_OF_VERSION_1_1(list, value);
    TEST_ASSERT(value != 0);

    /* Now check values */
    value = 1;
    value = list_check_of_list_table_stats_entry_OF_VERSION_1_1(list, value);
    TEST_ASSERT(value != 0);

    of_list_table_stats_entry_delete(list);

    return TEST_PASS;
}

/**
 * Baseline list tests for version OF_VERSION_1_2
 */

static int
test_of_list_action_OF_VERSION_1_2(void)
{
    of_list_action_t *list;
    int value = 1;

    list = of_list_action_new(OF_VERSION_1_2);
    TEST_ASSERT(list != NULL);
    TEST_ASSERT(list->version == OF_VERSION_1_2);
    TEST_ASSERT(list->length == 0);
    TEST_ASSERT(list->parent == NULL);
    TEST_ASSERT(list->object_id == OF_LIST_ACTION);

    value = list_setup_of_list_action_OF_VERSION_1_2(list, value);
    TEST_ASSERT(value != 0);

    /* Now check values */
    value = 1;
    value = list_check_of_list_action_OF_VERSION_1_2(list, value);
    TEST_ASSERT(value != 0);

    of_list_action_delete(list);

    return TEST_PASS;
}

static int
test_of_list_bsn_interface_OF_VERSION_1_2(void)
{
    of_list_bsn_interface_t *list;
    int value = 1;

    list = of_list_bsn_interface_new(OF_VERSION_1_2);
    TEST_ASSERT(list != NULL);
    TEST_ASSERT(list->version == OF_VERSION_1_2);
    TEST_ASSERT(list->length == 0);
    TEST_ASSERT(list->parent == NULL);
    TEST_ASSERT(list->object_id == OF_LIST_BSN_INTERFACE);

    value = list_setup_of_list_bsn_interface_OF_VERSION_1_2(list, value);
    TEST_ASSERT(value != 0);

    /* Now check values */
    value = 1;
    value = list_check_of_list_bsn_interface_OF_VERSION_1_2(list, value);
    TEST_ASSERT(value != 0);

    of_list_bsn_interface_delete(list);

    return TEST_PASS;
}

static int
test_of_list_bucket_OF_VERSION_1_2(void)
{
    of_list_bucket_t *list;
    int value = 1;

    list = of_list_bucket_new(OF_VERSION_1_2);
    TEST_ASSERT(list != NULL);
    TEST_ASSERT(list->version == OF_VERSION_1_2);
    TEST_ASSERT(list->length == 0);
    TEST_ASSERT(list->parent == NULL);
    TEST_ASSERT(list->object_id == OF_LIST_BUCKET);

    value = list_setup_of_list_bucket_OF_VERSION_1_2(list, value);
    TEST_ASSERT(value != 0);

    /* Now check values */
    value = 1;
    value = list_check_of_list_bucket_OF_VERSION_1_2(list, value);
    TEST_ASSERT(value != 0);

    of_list_bucket_delete(list);

    return TEST_PASS;
}

static int
test_of_list_bucket_counter_OF_VERSION_1_2(void)
{
    of_list_bucket_counter_t *list;
    int value = 1;

    list = of_list_bucket_counter_new(OF_VERSION_1_2);
    TEST_ASSERT(list != NULL);
    TEST_ASSERT(list->version == OF_VERSION_1_2);
    TEST_ASSERT(list->length == 0);
    TEST_ASSERT(list->parent == NULL);
    TEST_ASSERT(list->object_id == OF_LIST_BUCKET_COUNTER);

    value = list_setup_of_list_bucket_counter_OF_VERSION_1_2(list, value);
    TEST_ASSERT(value != 0);

    /* Now check values */
    value = 1;
    value = list_check_of_list_bucket_counter_OF_VERSION_1_2(list, value);
    TEST_ASSERT(value != 0);

    of_list_bucket_counter_delete(list);

    return TEST_PASS;
}

static int
test_of_list_flow_stats_entry_OF_VERSION_1_2(void)
{
    of_list_flow_stats_entry_t *list;
    int value = 1;

    list = of_list_flow_stats_entry_new(OF_VERSION_1_2);
    TEST_ASSERT(list != NULL);
    TEST_ASSERT(list->version == OF_VERSION_1_2);
    TEST_ASSERT(list->length == 0);
    TEST_ASSERT(list->parent == NULL);
    TEST_ASSERT(list->object_id == OF_LIST_FLOW_STATS_ENTRY);

    value = list_setup_of_list_flow_stats_entry_OF_VERSION_1_2(list, value);
    TEST_ASSERT(value != 0);

    /* Now check values */
    value = 1;
    value = list_check_of_list_flow_stats_entry_OF_VERSION_1_2(list, value);
    TEST_ASSERT(value != 0);

    of_list_flow_stats_entry_delete(list);

    return TEST_PASS;
}

static int
test_of_list_group_desc_stats_entry_OF_VERSION_1_2(void)
{
    of_list_group_desc_stats_entry_t *list;
    int value = 1;

    list = of_list_group_desc_stats_entry_new(OF_VERSION_1_2);
    TEST_ASSERT(list != NULL);
    TEST_ASSERT(list->version == OF_VERSION_1_2);
    TEST_ASSERT(list->length == 0);
    TEST_ASSERT(list->parent == NULL);
    TEST_ASSERT(list->object_id == OF_LIST_GROUP_DESC_STATS_ENTRY);

    value = list_setup_of_list_group_desc_stats_entry_OF_VERSION_1_2(list, value);
    TEST_ASSERT(value != 0);

    /* Now check values */
    value = 1;
    value = list_check_of_list_group_desc_stats_entry_OF_VERSION_1_2(list, value);
    TEST_ASSERT(value != 0);

    of_list_group_desc_stats_entry_delete(list);

    return TEST_PASS;
}

static int
test_of_list_group_stats_entry_OF_VERSION_1_2(void)
{
    of_list_group_stats_entry_t *list;
    int value = 1;

    list = of_list_group_stats_entry_new(OF_VERSION_1_2);
    TEST_ASSERT(list != NULL);
    TEST_ASSERT(list->version == OF_VERSION_1_2);
    TEST_ASSERT(list->length == 0);
    TEST_ASSERT(list->parent == NULL);
    TEST_ASSERT(list->object_id == OF_LIST_GROUP_STATS_ENTRY);

    value = list_setup_of_list_group_stats_entry_OF_VERSION_1_2(list, value);
    TEST_ASSERT(value != 0);

    /* Now check values */
    value = 1;
    value = list_check_of_list_group_stats_entry_OF_VERSION_1_2(list, value);
    TEST_ASSERT(value != 0);

    of_list_group_stats_entry_delete(list);

    return TEST_PASS;
}

static int
test_of_list_instruction_OF_VERSION_1_2(void)
{
    of_list_instruction_t *list;
    int value = 1;

    list = of_list_instruction_new(OF_VERSION_1_2);
    TEST_ASSERT(list != NULL);
    TEST_ASSERT(list->version == OF_VERSION_1_2);
    TEST_ASSERT(list->length == 0);
    TEST_ASSERT(list->parent == NULL);
    TEST_ASSERT(list->object_id == OF_LIST_INSTRUCTION);

    value = list_setup_of_list_instruction_OF_VERSION_1_2(list, value);
    TEST_ASSERT(value != 0);

    /* Now check values */
    value = 1;
    value = list_check_of_list_instruction_OF_VERSION_1_2(list, value);
    TEST_ASSERT(value != 0);

    of_list_instruction_delete(list);

    return TEST_PASS;
}

static int
test_of_list_oxm_OF_VERSION_1_2(void)
{
    of_list_oxm_t *list;
    int value = 1;

    list = of_list_oxm_new(OF_VERSION_1_2);
    TEST_ASSERT(list != NULL);
    TEST_ASSERT(list->version == OF_VERSION_1_2);
    TEST_ASSERT(list->length == 0);
    TEST_ASSERT(list->parent == NULL);
    TEST_ASSERT(list->object_id == OF_LIST_OXM);

    value = list_setup_of_list_oxm_OF_VERSION_1_2(list, value);
    TEST_ASSERT(value != 0);

    /* Now check values */
    value = 1;
    value = list_check_of_list_oxm_OF_VERSION_1_2(list, value);
    TEST_ASSERT(value != 0);

    of_list_oxm_delete(list);

    return TEST_PASS;
}

static int
test_of_list_packet_queue_OF_VERSION_1_2(void)
{
    of_list_packet_queue_t *list;
    int value = 1;

    list = of_list_packet_queue_new(OF_VERSION_1_2);
    TEST_ASSERT(list != NULL);
    TEST_ASSERT(list->version == OF_VERSION_1_2);
    TEST_ASSERT(list->length == 0);
    TEST_ASSERT(list->parent == NULL);
    TEST_ASSERT(list->object_id == OF_LIST_PACKET_QUEUE);

    value = list_setup_of_list_packet_queue_OF_VERSION_1_2(list, value);
    TEST_ASSERT(value != 0);

    /* Now check values */
    value = 1;
    value = list_check_of_list_packet_queue_OF_VERSION_1_2(list, value);
    TEST_ASSERT(value != 0);

    of_list_packet_queue_delete(list);

    return TEST_PASS;
}

static int
test_of_list_port_desc_OF_VERSION_1_2(void)
{
    of_list_port_desc_t *list;
    int value = 1;

    list = of_list_port_desc_new(OF_VERSION_1_2);
    TEST_ASSERT(list != NULL);
    TEST_ASSERT(list->version == OF_VERSION_1_2);
    TEST_ASSERT(list->length == 0);
    TEST_ASSERT(list->parent == NULL);
    TEST_ASSERT(list->object_id == OF_LIST_PORT_DESC);

    value = list_setup_of_list_port_desc_OF_VERSION_1_2(list, value);
    TEST_ASSERT(value != 0);

    /* Now check values */
    value = 1;
    value = list_check_of_list_port_desc_OF_VERSION_1_2(list, value);
    TEST_ASSERT(value != 0);

    of_list_port_desc_delete(list);

    return TEST_PASS;
}

static int
test_of_list_port_stats_entry_OF_VERSION_1_2(void)
{
    of_list_port_stats_entry_t *list;
    int value = 1;

    list = of_list_port_stats_entry_new(OF_VERSION_1_2);
    TEST_ASSERT(list != NULL);
    TEST_ASSERT(list->version == OF_VERSION_1_2);
    TEST_ASSERT(list->length == 0);
    TEST_ASSERT(list->parent == NULL);
    TEST_ASSERT(list->object_id == OF_LIST_PORT_STATS_ENTRY);

    value = list_setup_of_list_port_stats_entry_OF_VERSION_1_2(list, value);
    TEST_ASSERT(value != 0);

    /* Now check values */
    value = 1;
    value = list_check_of_list_port_stats_entry_OF_VERSION_1_2(list, value);
    TEST_ASSERT(value != 0);

    of_list_port_stats_entry_delete(list);

    return TEST_PASS;
}

static int
test_of_list_queue_prop_OF_VERSION_1_2(void)
{
    of_list_queue_prop_t *list;
    int value = 1;

    list = of_list_queue_prop_new(OF_VERSION_1_2);
    TEST_ASSERT(list != NULL);
    TEST_ASSERT(list->version == OF_VERSION_1_2);
    TEST_ASSERT(list->length == 0);
    TEST_ASSERT(list->parent == NULL);
    TEST_ASSERT(list->object_id == OF_LIST_QUEUE_PROP);

    value = list_setup_of_list_queue_prop_OF_VERSION_1_2(list, value);
    TEST_ASSERT(value != 0);

    /* Now check values */
    value = 1;
    value = list_check_of_list_queue_prop_OF_VERSION_1_2(list, value);
    TEST_ASSERT(value != 0);

    of_list_queue_prop_delete(list);

    return TEST_PASS;
}

static int
test_of_list_queue_stats_entry_OF_VERSION_1_2(void)
{
    of_list_queue_stats_entry_t *list;
    int value = 1;

    list = of_list_queue_stats_entry_new(OF_VERSION_1_2);
    TEST_ASSERT(list != NULL);
    TEST_ASSERT(list->version == OF_VERSION_1_2);
    TEST_ASSERT(list->length == 0);
    TEST_ASSERT(list->parent == NULL);
    TEST_ASSERT(list->object_id == OF_LIST_QUEUE_STATS_ENTRY);

    value = list_setup_of_list_queue_stats_entry_OF_VERSION_1_2(list, value);
    TEST_ASSERT(value != 0);

    /* Now check values */
    value = 1;
    value = list_check_of_list_queue_stats_entry_OF_VERSION_1_2(list, value);
    TEST_ASSERT(value != 0);

    of_list_queue_stats_entry_delete(list);

    return TEST_PASS;
}

static int
test_of_list_table_stats_entry_OF_VERSION_1_2(void)
{
    of_list_table_stats_entry_t *list;
    int value = 1;

    list = of_list_table_stats_entry_new(OF_VERSION_1_2);
    TEST_ASSERT(list != NULL);
    TEST_ASSERT(list->version == OF_VERSION_1_2);
    TEST_ASSERT(list->length == 0);
    TEST_ASSERT(list->parent == NULL);
    TEST_ASSERT(list->object_id == OF_LIST_TABLE_STATS_ENTRY);

    value = list_setup_of_list_table_stats_entry_OF_VERSION_1_2(list, value);
    TEST_ASSERT(value != 0);

    /* Now check values */
    value = 1;
    value = list_check_of_list_table_stats_entry_OF_VERSION_1_2(list, value);
    TEST_ASSERT(value != 0);

    of_list_table_stats_entry_delete(list);

    return TEST_PASS;
}

/**
 * Baseline list tests for version OF_VERSION_1_3
 */

static int
test_of_list_action_OF_VERSION_1_3(void)
{
    of_list_action_t *list;
    int value = 1;

    list = of_list_action_new(OF_VERSION_1_3);
    TEST_ASSERT(list != NULL);
    TEST_ASSERT(list->version == OF_VERSION_1_3);
    TEST_ASSERT(list->length == 0);
    TEST_ASSERT(list->parent == NULL);
    TEST_ASSERT(list->object_id == OF_LIST_ACTION);

    value = list_setup_of_list_action_OF_VERSION_1_3(list, value);
    TEST_ASSERT(value != 0);

    /* Now check values */
    value = 1;
    value = list_check_of_list_action_OF_VERSION_1_3(list, value);
    TEST_ASSERT(value != 0);

    of_list_action_delete(list);

    return TEST_PASS;
}

static int
test_of_list_action_id_OF_VERSION_1_3(void)
{
    of_list_action_id_t *list;
    int value = 1;

    list = of_list_action_id_new(OF_VERSION_1_3);
    TEST_ASSERT(list != NULL);
    TEST_ASSERT(list->version == OF_VERSION_1_3);
    TEST_ASSERT(list->length == 0);
    TEST_ASSERT(list->parent == NULL);
    TEST_ASSERT(list->object_id == OF_LIST_ACTION_ID);

    value = list_setup_of_list_action_id_OF_VERSION_1_3(list, value);
    TEST_ASSERT(value != 0);

    /* Now check values */
    value = 1;
    value = list_check_of_list_action_id_OF_VERSION_1_3(list, value);
    TEST_ASSERT(value != 0);

    of_list_action_id_delete(list);

    return TEST_PASS;
}

static int
test_of_list_bsn_interface_OF_VERSION_1_3(void)
{
    of_list_bsn_interface_t *list;
    int value = 1;

    list = of_list_bsn_interface_new(OF_VERSION_1_3);
    TEST_ASSERT(list != NULL);
    TEST_ASSERT(list->version == OF_VERSION_1_3);
    TEST_ASSERT(list->length == 0);
    TEST_ASSERT(list->parent == NULL);
    TEST_ASSERT(list->object_id == OF_LIST_BSN_INTERFACE);

    value = list_setup_of_list_bsn_interface_OF_VERSION_1_3(list, value);
    TEST_ASSERT(value != 0);

    /* Now check values */
    value = 1;
    value = list_check_of_list_bsn_interface_OF_VERSION_1_3(list, value);
    TEST_ASSERT(value != 0);

    of_list_bsn_interface_delete(list);

    return TEST_PASS;
}

static int
test_of_list_bsn_lacp_stats_entry_OF_VERSION_1_3(void)
{
    of_list_bsn_lacp_stats_entry_t *list;
    int value = 1;

    list = of_list_bsn_lacp_stats_entry_new(OF_VERSION_1_3);
    TEST_ASSERT(list != NULL);
    TEST_ASSERT(list->version == OF_VERSION_1_3);
    TEST_ASSERT(list->length == 0);
    TEST_ASSERT(list->parent == NULL);
    TEST_ASSERT(list->object_id == OF_LIST_BSN_LACP_STATS_ENTRY);

    value = list_setup_of_list_bsn_lacp_stats_entry_OF_VERSION_1_3(list, value);
    TEST_ASSERT(value != 0);

    /* Now check values */
    value = 1;
    value = list_check_of_list_bsn_lacp_stats_entry_OF_VERSION_1_3(list, value);
    TEST_ASSERT(value != 0);

    of_list_bsn_lacp_stats_entry_delete(list);

    return TEST_PASS;
}

static int
test_of_list_bucket_OF_VERSION_1_3(void)
{
    of_list_bucket_t *list;
    int value = 1;

    list = of_list_bucket_new(OF_VERSION_1_3);
    TEST_ASSERT(list != NULL);
    TEST_ASSERT(list->version == OF_VERSION_1_3);
    TEST_ASSERT(list->length == 0);
    TEST_ASSERT(list->parent == NULL);
    TEST_ASSERT(list->object_id == OF_LIST_BUCKET);

    value = list_setup_of_list_bucket_OF_VERSION_1_3(list, value);
    TEST_ASSERT(value != 0);

    /* Now check values */
    value = 1;
    value = list_check_of_list_bucket_OF_VERSION_1_3(list, value);
    TEST_ASSERT(value != 0);

    of_list_bucket_delete(list);

    return TEST_PASS;
}

static int
test_of_list_bucket_counter_OF_VERSION_1_3(void)
{
    of_list_bucket_counter_t *list;
    int value = 1;

    list = of_list_bucket_counter_new(OF_VERSION_1_3);
    TEST_ASSERT(list != NULL);
    TEST_ASSERT(list->version == OF_VERSION_1_3);
    TEST_ASSERT(list->length == 0);
    TEST_ASSERT(list->parent == NULL);
    TEST_ASSERT(list->object_id == OF_LIST_BUCKET_COUNTER);

    value = list_setup_of_list_bucket_counter_OF_VERSION_1_3(list, value);
    TEST_ASSERT(value != 0);

    /* Now check values */
    value = 1;
    value = list_check_of_list_bucket_counter_OF_VERSION_1_3(list, value);
    TEST_ASSERT(value != 0);

    of_list_bucket_counter_delete(list);

    return TEST_PASS;
}

static int
test_of_list_flow_stats_entry_OF_VERSION_1_3(void)
{
    of_list_flow_stats_entry_t *list;
    int value = 1;

    list = of_list_flow_stats_entry_new(OF_VERSION_1_3);
    TEST_ASSERT(list != NULL);
    TEST_ASSERT(list->version == OF_VERSION_1_3);
    TEST_ASSERT(list->length == 0);
    TEST_ASSERT(list->parent == NULL);
    TEST_ASSERT(list->object_id == OF_LIST_FLOW_STATS_ENTRY);

    value = list_setup_of_list_flow_stats_entry_OF_VERSION_1_3(list, value);
    TEST_ASSERT(value != 0);

    /* Now check values */
    value = 1;
    value = list_check_of_list_flow_stats_entry_OF_VERSION_1_3(list, value);
    TEST_ASSERT(value != 0);

    of_list_flow_stats_entry_delete(list);

    return TEST_PASS;
}

static int
test_of_list_group_desc_stats_entry_OF_VERSION_1_3(void)
{
    of_list_group_desc_stats_entry_t *list;
    int value = 1;

    list = of_list_group_desc_stats_entry_new(OF_VERSION_1_3);
    TEST_ASSERT(list != NULL);
    TEST_ASSERT(list->version == OF_VERSION_1_3);
    TEST_ASSERT(list->length == 0);
    TEST_ASSERT(list->parent == NULL);
    TEST_ASSERT(list->object_id == OF_LIST_GROUP_DESC_STATS_ENTRY);

    value = list_setup_of_list_group_desc_stats_entry_OF_VERSION_1_3(list, value);
    TEST_ASSERT(value != 0);

    /* Now check values */
    value = 1;
    value = list_check_of_list_group_desc_stats_entry_OF_VERSION_1_3(list, value);
    TEST_ASSERT(value != 0);

    of_list_group_desc_stats_entry_delete(list);

    return TEST_PASS;
}

static int
test_of_list_group_stats_entry_OF_VERSION_1_3(void)
{
    of_list_group_stats_entry_t *list;
    int value = 1;

    list = of_list_group_stats_entry_new(OF_VERSION_1_3);
    TEST_ASSERT(list != NULL);
    TEST_ASSERT(list->version == OF_VERSION_1_3);
    TEST_ASSERT(list->length == 0);
    TEST_ASSERT(list->parent == NULL);
    TEST_ASSERT(list->object_id == OF_LIST_GROUP_STATS_ENTRY);

    value = list_setup_of_list_group_stats_entry_OF_VERSION_1_3(list, value);
    TEST_ASSERT(value != 0);

    /* Now check values */
    value = 1;
    value = list_check_of_list_group_stats_entry_OF_VERSION_1_3(list, value);
    TEST_ASSERT(value != 0);

    of_list_group_stats_entry_delete(list);

    return TEST_PASS;
}

static int
test_of_list_hello_elem_OF_VERSION_1_3(void)
{
    of_list_hello_elem_t *list;
    int value = 1;

    list = of_list_hello_elem_new(OF_VERSION_1_3);
    TEST_ASSERT(list != NULL);
    TEST_ASSERT(list->version == OF_VERSION_1_3);
    TEST_ASSERT(list->length == 0);
    TEST_ASSERT(list->parent == NULL);
    TEST_ASSERT(list->object_id == OF_LIST_HELLO_ELEM);

    value = list_setup_of_list_hello_elem_OF_VERSION_1_3(list, value);
    TEST_ASSERT(value != 0);

    /* Now check values */
    value = 1;
    value = list_check_of_list_hello_elem_OF_VERSION_1_3(list, value);
    TEST_ASSERT(value != 0);

    of_list_hello_elem_delete(list);

    return TEST_PASS;
}

static int
test_of_list_instruction_OF_VERSION_1_3(void)
{
    of_list_instruction_t *list;
    int value = 1;

    list = of_list_instruction_new(OF_VERSION_1_3);
    TEST_ASSERT(list != NULL);
    TEST_ASSERT(list->version == OF_VERSION_1_3);
    TEST_ASSERT(list->length == 0);
    TEST_ASSERT(list->parent == NULL);
    TEST_ASSERT(list->object_id == OF_LIST_INSTRUCTION);

    value = list_setup_of_list_instruction_OF_VERSION_1_3(list, value);
    TEST_ASSERT(value != 0);

    /* Now check values */
    value = 1;
    value = list_check_of_list_instruction_OF_VERSION_1_3(list, value);
    TEST_ASSERT(value != 0);

    of_list_instruction_delete(list);

    return TEST_PASS;
}

static int
test_of_list_meter_band_OF_VERSION_1_3(void)
{
    of_list_meter_band_t *list;
    int value = 1;

    list = of_list_meter_band_new(OF_VERSION_1_3);
    TEST_ASSERT(list != NULL);
    TEST_ASSERT(list->version == OF_VERSION_1_3);
    TEST_ASSERT(list->length == 0);
    TEST_ASSERT(list->parent == NULL);
    TEST_ASSERT(list->object_id == OF_LIST_METER_BAND);

    value = list_setup_of_list_meter_band_OF_VERSION_1_3(list, value);
    TEST_ASSERT(value != 0);

    /* Now check values */
    value = 1;
    value = list_check_of_list_meter_band_OF_VERSION_1_3(list, value);
    TEST_ASSERT(value != 0);

    of_list_meter_band_delete(list);

    return TEST_PASS;
}

static int
test_of_list_meter_band_stats_OF_VERSION_1_3(void)
{
    of_list_meter_band_stats_t *list;
    int value = 1;

    list = of_list_meter_band_stats_new(OF_VERSION_1_3);
    TEST_ASSERT(list != NULL);
    TEST_ASSERT(list->version == OF_VERSION_1_3);
    TEST_ASSERT(list->length == 0);
    TEST_ASSERT(list->parent == NULL);
    TEST_ASSERT(list->object_id == OF_LIST_METER_BAND_STATS);

    value = list_setup_of_list_meter_band_stats_OF_VERSION_1_3(list, value);
    TEST_ASSERT(value != 0);

    /* Now check values */
    value = 1;
    value = list_check_of_list_meter_band_stats_OF_VERSION_1_3(list, value);
    TEST_ASSERT(value != 0);

    of_list_meter_band_stats_delete(list);

    return TEST_PASS;
}

static int
test_of_list_meter_stats_OF_VERSION_1_3(void)
{
    of_list_meter_stats_t *list;
    int value = 1;

    list = of_list_meter_stats_new(OF_VERSION_1_3);
    TEST_ASSERT(list != NULL);
    TEST_ASSERT(list->version == OF_VERSION_1_3);
    TEST_ASSERT(list->length == 0);
    TEST_ASSERT(list->parent == NULL);
    TEST_ASSERT(list->object_id == OF_LIST_METER_STATS);

    value = list_setup_of_list_meter_stats_OF_VERSION_1_3(list, value);
    TEST_ASSERT(value != 0);

    /* Now check values */
    value = 1;
    value = list_check_of_list_meter_stats_OF_VERSION_1_3(list, value);
    TEST_ASSERT(value != 0);

    of_list_meter_stats_delete(list);

    return TEST_PASS;
}

static int
test_of_list_oxm_OF_VERSION_1_3(void)
{
    of_list_oxm_t *list;
    int value = 1;

    list = of_list_oxm_new(OF_VERSION_1_3);
    TEST_ASSERT(list != NULL);
    TEST_ASSERT(list->version == OF_VERSION_1_3);
    TEST_ASSERT(list->length == 0);
    TEST_ASSERT(list->parent == NULL);
    TEST_ASSERT(list->object_id == OF_LIST_OXM);

    value = list_setup_of_list_oxm_OF_VERSION_1_3(list, value);
    TEST_ASSERT(value != 0);

    /* Now check values */
    value = 1;
    value = list_check_of_list_oxm_OF_VERSION_1_3(list, value);
    TEST_ASSERT(value != 0);

    of_list_oxm_delete(list);

    return TEST_PASS;
}

static int
test_of_list_packet_queue_OF_VERSION_1_3(void)
{
    of_list_packet_queue_t *list;
    int value = 1;

    list = of_list_packet_queue_new(OF_VERSION_1_3);
    TEST_ASSERT(list != NULL);
    TEST_ASSERT(list->version == OF_VERSION_1_3);
    TEST_ASSERT(list->length == 0);
    TEST_ASSERT(list->parent == NULL);
    TEST_ASSERT(list->object_id == OF_LIST_PACKET_QUEUE);

    value = list_setup_of_list_packet_queue_OF_VERSION_1_3(list, value);
    TEST_ASSERT(value != 0);

    /* Now check values */
    value = 1;
    value = list_check_of_list_packet_queue_OF_VERSION_1_3(list, value);
    TEST_ASSERT(value != 0);

    of_list_packet_queue_delete(list);

    return TEST_PASS;
}

static int
test_of_list_port_desc_OF_VERSION_1_3(void)
{
    of_list_port_desc_t *list;
    int value = 1;

    list = of_list_port_desc_new(OF_VERSION_1_3);
    TEST_ASSERT(list != NULL);
    TEST_ASSERT(list->version == OF_VERSION_1_3);
    TEST_ASSERT(list->length == 0);
    TEST_ASSERT(list->parent == NULL);
    TEST_ASSERT(list->object_id == OF_LIST_PORT_DESC);

    value = list_setup_of_list_port_desc_OF_VERSION_1_3(list, value);
    TEST_ASSERT(value != 0);

    /* Now check values */
    value = 1;
    value = list_check_of_list_port_desc_OF_VERSION_1_3(list, value);
    TEST_ASSERT(value != 0);

    of_list_port_desc_delete(list);

    return TEST_PASS;
}

static int
test_of_list_port_stats_entry_OF_VERSION_1_3(void)
{
    of_list_port_stats_entry_t *list;
    int value = 1;

    list = of_list_port_stats_entry_new(OF_VERSION_1_3);
    TEST_ASSERT(list != NULL);
    TEST_ASSERT(list->version == OF_VERSION_1_3);
    TEST_ASSERT(list->length == 0);
    TEST_ASSERT(list->parent == NULL);
    TEST_ASSERT(list->object_id == OF_LIST_PORT_STATS_ENTRY);

    value = list_setup_of_list_port_stats_entry_OF_VERSION_1_3(list, value);
    TEST_ASSERT(value != 0);

    /* Now check values */
    value = 1;
    value = list_check_of_list_port_stats_entry_OF_VERSION_1_3(list, value);
    TEST_ASSERT(value != 0);

    of_list_port_stats_entry_delete(list);

    return TEST_PASS;
}

static int
test_of_list_queue_prop_OF_VERSION_1_3(void)
{
    of_list_queue_prop_t *list;
    int value = 1;

    list = of_list_queue_prop_new(OF_VERSION_1_3);
    TEST_ASSERT(list != NULL);
    TEST_ASSERT(list->version == OF_VERSION_1_3);
    TEST_ASSERT(list->length == 0);
    TEST_ASSERT(list->parent == NULL);
    TEST_ASSERT(list->object_id == OF_LIST_QUEUE_PROP);

    value = list_setup_of_list_queue_prop_OF_VERSION_1_3(list, value);
    TEST_ASSERT(value != 0);

    /* Now check values */
    value = 1;
    value = list_check_of_list_queue_prop_OF_VERSION_1_3(list, value);
    TEST_ASSERT(value != 0);

    of_list_queue_prop_delete(list);

    return TEST_PASS;
}

static int
test_of_list_queue_stats_entry_OF_VERSION_1_3(void)
{
    of_list_queue_stats_entry_t *list;
    int value = 1;

    list = of_list_queue_stats_entry_new(OF_VERSION_1_3);
    TEST_ASSERT(list != NULL);
    TEST_ASSERT(list->version == OF_VERSION_1_3);
    TEST_ASSERT(list->length == 0);
    TEST_ASSERT(list->parent == NULL);
    TEST_ASSERT(list->object_id == OF_LIST_QUEUE_STATS_ENTRY);

    value = list_setup_of_list_queue_stats_entry_OF_VERSION_1_3(list, value);
    TEST_ASSERT(value != 0);

    /* Now check values */
    value = 1;
    value = list_check_of_list_queue_stats_entry_OF_VERSION_1_3(list, value);
    TEST_ASSERT(value != 0);

    of_list_queue_stats_entry_delete(list);

    return TEST_PASS;
}

static int
test_of_list_table_feature_prop_OF_VERSION_1_3(void)
{
    of_list_table_feature_prop_t *list;
    int value = 1;

    list = of_list_table_feature_prop_new(OF_VERSION_1_3);
    TEST_ASSERT(list != NULL);
    TEST_ASSERT(list->version == OF_VERSION_1_3);
    TEST_ASSERT(list->length == 0);
    TEST_ASSERT(list->parent == NULL);
    TEST_ASSERT(list->object_id == OF_LIST_TABLE_FEATURE_PROP);

    value = list_setup_of_list_table_feature_prop_OF_VERSION_1_3(list, value);
    TEST_ASSERT(value != 0);

    /* Now check values */
    value = 1;
    value = list_check_of_list_table_feature_prop_OF_VERSION_1_3(list, value);
    TEST_ASSERT(value != 0);

    of_list_table_feature_prop_delete(list);

    return TEST_PASS;
}

static int
test_of_list_table_features_OF_VERSION_1_3(void)
{
    of_list_table_features_t *list;
    int value = 1;

    list = of_list_table_features_new(OF_VERSION_1_3);
    TEST_ASSERT(list != NULL);
    TEST_ASSERT(list->version == OF_VERSION_1_3);
    TEST_ASSERT(list->length == 0);
    TEST_ASSERT(list->parent == NULL);
    TEST_ASSERT(list->object_id == OF_LIST_TABLE_FEATURES);

    value = list_setup_of_list_table_features_OF_VERSION_1_3(list, value);
    TEST_ASSERT(value != 0);

    /* Now check values */
    value = 1;
    value = list_check_of_list_table_features_OF_VERSION_1_3(list, value);
    TEST_ASSERT(value != 0);

    of_list_table_features_delete(list);

    return TEST_PASS;
}

static int
test_of_list_table_stats_entry_OF_VERSION_1_3(void)
{
    of_list_table_stats_entry_t *list;
    int value = 1;

    list = of_list_table_stats_entry_new(OF_VERSION_1_3);
    TEST_ASSERT(list != NULL);
    TEST_ASSERT(list->version == OF_VERSION_1_3);
    TEST_ASSERT(list->length == 0);
    TEST_ASSERT(list->parent == NULL);
    TEST_ASSERT(list->object_id == OF_LIST_TABLE_STATS_ENTRY);

    value = list_setup_of_list_table_stats_entry_OF_VERSION_1_3(list, value);
    TEST_ASSERT(value != 0);

    /* Now check values */
    value = 1;
    value = list_check_of_list_table_stats_entry_OF_VERSION_1_3(list, value);
    TEST_ASSERT(value != 0);

    of_list_table_stats_entry_delete(list);

    return TEST_PASS;
}

static int
test_of_list_uint32_OF_VERSION_1_3(void)
{
    of_list_uint32_t *list;
    int value = 1;

    list = of_list_uint32_new(OF_VERSION_1_3);
    TEST_ASSERT(list != NULL);
    TEST_ASSERT(list->version == OF_VERSION_1_3);
    TEST_ASSERT(list->length == 0);
    TEST_ASSERT(list->parent == NULL);
    TEST_ASSERT(list->object_id == OF_LIST_UINT32);

    value = list_setup_of_list_uint32_OF_VERSION_1_3(list, value);
    TEST_ASSERT(value != 0);

    /* Now check values */
    value = 1;
    value = list_check_of_list_uint32_OF_VERSION_1_3(list, value);
    TEST_ASSERT(value != 0);

    of_list_uint32_delete(list);

    return TEST_PASS;
}

static int
test_of_list_uint8_OF_VERSION_1_3(void)
{
    of_list_uint8_t *list;
    int value = 1;

    list = of_list_uint8_new(OF_VERSION_1_3);
    TEST_ASSERT(list != NULL);
    TEST_ASSERT(list->version == OF_VERSION_1_3);
    TEST_ASSERT(list->length == 0);
    TEST_ASSERT(list->parent == NULL);
    TEST_ASSERT(list->object_id == OF_LIST_UINT8);

    value = list_setup_of_list_uint8_OF_VERSION_1_3(list, value);
    TEST_ASSERT(value != 0);

    /* Now check values */
    value = 1;
    value = list_check_of_list_uint8_OF_VERSION_1_3(list, value);
    TEST_ASSERT(value != 0);

    of_list_uint8_delete(list);

    return TEST_PASS;
}

int
run_list_tests(void)
{
    RUN_TEST(of_list_action_OF_VERSION_1_0);
    RUN_TEST(of_list_bsn_interface_OF_VERSION_1_0);
    RUN_TEST(of_list_flow_stats_entry_OF_VERSION_1_0);
    RUN_TEST(of_list_packet_queue_OF_VERSION_1_0);
    RUN_TEST(of_list_port_desc_OF_VERSION_1_0);
    RUN_TEST(of_list_port_stats_entry_OF_VERSION_1_0);
    RUN_TEST(of_list_queue_prop_OF_VERSION_1_0);
    RUN_TEST(of_list_queue_stats_entry_OF_VERSION_1_0);
    RUN_TEST(of_list_table_stats_entry_OF_VERSION_1_0);
    RUN_TEST(of_list_action_OF_VERSION_1_1);
    RUN_TEST(of_list_bsn_interface_OF_VERSION_1_1);
    RUN_TEST(of_list_bucket_OF_VERSION_1_1);
    RUN_TEST(of_list_bucket_counter_OF_VERSION_1_1);
    RUN_TEST(of_list_flow_stats_entry_OF_VERSION_1_1);
    RUN_TEST(of_list_group_desc_stats_entry_OF_VERSION_1_1);
    RUN_TEST(of_list_group_stats_entry_OF_VERSION_1_1);
    RUN_TEST(of_list_instruction_OF_VERSION_1_1);
    RUN_TEST(of_list_packet_queue_OF_VERSION_1_1);
    RUN_TEST(of_list_port_desc_OF_VERSION_1_1);
    RUN_TEST(of_list_port_stats_entry_OF_VERSION_1_1);
    RUN_TEST(of_list_queue_prop_OF_VERSION_1_1);
    RUN_TEST(of_list_queue_stats_entry_OF_VERSION_1_1);
    RUN_TEST(of_list_table_stats_entry_OF_VERSION_1_1);
    RUN_TEST(of_list_action_OF_VERSION_1_2);
    RUN_TEST(of_list_bsn_interface_OF_VERSION_1_2);
    RUN_TEST(of_list_bucket_OF_VERSION_1_2);
    RUN_TEST(of_list_bucket_counter_OF_VERSION_1_2);
    RUN_TEST(of_list_flow_stats_entry_OF_VERSION_1_2);
    RUN_TEST(of_list_group_desc_stats_entry_OF_VERSION_1_2);
    RUN_TEST(of_list_group_stats_entry_OF_VERSION_1_2);
    RUN_TEST(of_list_instruction_OF_VERSION_1_2);
    RUN_TEST(of_list_oxm_OF_VERSION_1_2);
    RUN_TEST(of_list_packet_queue_OF_VERSION_1_2);
    RUN_TEST(of_list_port_desc_OF_VERSION_1_2);
    RUN_TEST(of_list_port_stats_entry_OF_VERSION_1_2);
    RUN_TEST(of_list_queue_prop_OF_VERSION_1_2);
    RUN_TEST(of_list_queue_stats_entry_OF_VERSION_1_2);
    RUN_TEST(of_list_table_stats_entry_OF_VERSION_1_2);
    RUN_TEST(of_list_action_OF_VERSION_1_3);
    RUN_TEST(of_list_action_id_OF_VERSION_1_3);
    RUN_TEST(of_list_bsn_interface_OF_VERSION_1_3);
    RUN_TEST(of_list_bsn_lacp_stats_entry_OF_VERSION_1_3);
    RUN_TEST(of_list_bucket_OF_VERSION_1_3);
    RUN_TEST(of_list_bucket_counter_OF_VERSION_1_3);
    RUN_TEST(of_list_flow_stats_entry_OF_VERSION_1_3);
    RUN_TEST(of_list_group_desc_stats_entry_OF_VERSION_1_3);
    RUN_TEST(of_list_group_stats_entry_OF_VERSION_1_3);
    RUN_TEST(of_list_hello_elem_OF_VERSION_1_3);
    RUN_TEST(of_list_instruction_OF_VERSION_1_3);
    RUN_TEST(of_list_meter_band_OF_VERSION_1_3);
    RUN_TEST(of_list_meter_band_stats_OF_VERSION_1_3);
    RUN_TEST(of_list_meter_stats_OF_VERSION_1_3);
    RUN_TEST(of_list_oxm_OF_VERSION_1_3);
    RUN_TEST(of_list_packet_queue_OF_VERSION_1_3);
    RUN_TEST(of_list_port_desc_OF_VERSION_1_3);
    RUN_TEST(of_list_port_stats_entry_OF_VERSION_1_3);
    RUN_TEST(of_list_queue_prop_OF_VERSION_1_3);
    RUN_TEST(of_list_queue_stats_entry_OF_VERSION_1_3);
    RUN_TEST(of_list_table_feature_prop_OF_VERSION_1_3);
    RUN_TEST(of_list_table_features_OF_VERSION_1_3);
    RUN_TEST(of_list_table_stats_entry_OF_VERSION_1_3);
    RUN_TEST(of_list_uint32_OF_VERSION_1_3);
    RUN_TEST(of_list_uint8_OF_VERSION_1_3);

    return TEST_PASS;
}
