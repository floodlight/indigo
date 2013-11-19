/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */

/**
 * Test message validator
 *
 * Run the message validator on corrupt messages to ensure it catches them.
 */

#include "loci_log.h"

#include <locitest/test_common.h>
#include <loci/loci_validator.h>

static int
test_validate_fixed_length(void)
{
    of_table_stats_request_t *obj = of_table_stats_request_new(OF_VERSION_1_0);
    of_message_t msg = OF_OBJECT_TO_MESSAGE(obj);

    TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);

    of_message_length_set(msg, of_message_length_get(msg) - 1);
    TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == -1);

    of_table_stats_request_delete(obj);
    return TEST_PASS;
}

static int
test_validate_fixed_length_list(void)
{
    of_table_stats_reply_t *obj = of_table_stats_reply_new(OF_VERSION_1_0);
    of_list_table_stats_entry_t list;
    of_table_stats_entry_t element;
    of_message_t msg; 
    of_table_stats_reply_entries_bind(obj, &list);
    of_table_stats_entry_init(&element, OF_VERSION_1_0, -1, 1);
    of_list_table_stats_entry_append_bind(&list, &element);
    of_list_table_stats_entry_append_bind(&list, &element);
    msg = OF_OBJECT_TO_MESSAGE(obj);

    TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);

    of_message_length_set(msg, of_message_length_get(msg) - 1);
    TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == -1);

    of_table_stats_reply_delete(obj);
    return TEST_PASS;
}

static int
test_validate_tlv16_list(void)
{
    of_flow_modify_t *obj = of_flow_modify_new(OF_VERSION_1_0);
    of_list_action_t list;
    of_action_set_tp_dst_t element1;
    of_action_output_t element2;
    of_message_t msg; 
    of_flow_modify_actions_bind(obj, &list);
    of_action_set_tp_dst_init(&element1, OF_VERSION_1_0, -1, 1);
    of_list_action_append_bind(&list, (of_action_t *)&element1);
    of_action_output_init(&element2, OF_VERSION_1_0, -1, 1);
    of_list_action_append_bind(&list, (of_action_t *)&element2);
    msg = OF_OBJECT_TO_MESSAGE(obj);

    TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);

    of_message_length_set(msg, of_message_length_get(msg) - 1);
    TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == -1);

    of_message_length_set(msg, of_message_length_get(msg) + 2);
    TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == -1);

    of_flow_modify_delete(obj);
    return TEST_PASS;
}

/*
 * Create an instance of every message and run it through the validator.
 */
static int
test_validate_all(void)
{
    {
        of_table_stats_request_t *obj = of_table_stats_request_new(OF_VERSION_1_0);
        of_message_t msg;
        of_table_stats_request_OF_VERSION_1_0_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_table_stats_request_delete(obj);
    }

    {
        of_table_stats_reply_t *obj = of_table_stats_reply_new(OF_VERSION_1_0);
        of_message_t msg;
        of_table_stats_reply_OF_VERSION_1_0_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_table_stats_reply_delete(obj);
    }

    {
        of_table_mod_t *obj = of_table_mod_new(OF_VERSION_1_0);
        of_message_t msg;
        of_table_mod_OF_VERSION_1_0_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_table_mod_delete(obj);
    }

    {
        of_set_config_t *obj = of_set_config_new(OF_VERSION_1_0);
        of_message_t msg;
        of_set_config_OF_VERSION_1_0_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_set_config_delete(obj);
    }

    {
        of_queue_stats_request_t *obj = of_queue_stats_request_new(OF_VERSION_1_0);
        of_message_t msg;
        of_queue_stats_request_OF_VERSION_1_0_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_queue_stats_request_delete(obj);
    }

    {
        of_queue_stats_reply_t *obj = of_queue_stats_reply_new(OF_VERSION_1_0);
        of_message_t msg;
        of_queue_stats_reply_OF_VERSION_1_0_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_queue_stats_reply_delete(obj);
    }

    {
        of_queue_op_failed_error_msg_t *obj = of_queue_op_failed_error_msg_new(OF_VERSION_1_0);
        of_message_t msg;
        of_queue_op_failed_error_msg_OF_VERSION_1_0_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_queue_op_failed_error_msg_delete(obj);
    }

    {
        of_queue_get_config_request_t *obj = of_queue_get_config_request_new(OF_VERSION_1_0);
        of_message_t msg;
        of_queue_get_config_request_OF_VERSION_1_0_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_queue_get_config_request_delete(obj);
    }

    {
        of_queue_get_config_reply_t *obj = of_queue_get_config_reply_new(OF_VERSION_1_0);
        of_message_t msg;
        of_queue_get_config_reply_OF_VERSION_1_0_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_queue_get_config_reply_delete(obj);
    }

    {
        of_port_status_t *obj = of_port_status_new(OF_VERSION_1_0);
        of_message_t msg;
        of_port_status_OF_VERSION_1_0_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_port_status_delete(obj);
    }

    {
        of_port_stats_request_t *obj = of_port_stats_request_new(OF_VERSION_1_0);
        of_message_t msg;
        of_port_stats_request_OF_VERSION_1_0_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_port_stats_request_delete(obj);
    }

    {
        of_port_stats_reply_t *obj = of_port_stats_reply_new(OF_VERSION_1_0);
        of_message_t msg;
        of_port_stats_reply_OF_VERSION_1_0_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_port_stats_reply_delete(obj);
    }

    {
        of_port_mod_failed_error_msg_t *obj = of_port_mod_failed_error_msg_new(OF_VERSION_1_0);
        of_message_t msg;
        of_port_mod_failed_error_msg_OF_VERSION_1_0_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_port_mod_failed_error_msg_delete(obj);
    }

    {
        of_port_mod_t *obj = of_port_mod_new(OF_VERSION_1_0);
        of_message_t msg;
        of_port_mod_OF_VERSION_1_0_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_port_mod_delete(obj);
    }

    {
        of_packet_out_t *obj = of_packet_out_new(OF_VERSION_1_0);
        of_message_t msg;
        of_packet_out_OF_VERSION_1_0_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_packet_out_delete(obj);
    }

    {
        of_packet_in_t *obj = of_packet_in_new(OF_VERSION_1_0);
        of_message_t msg;
        of_packet_in_OF_VERSION_1_0_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_packet_in_delete(obj);
    }

    {
        of_nicira_controller_role_request_t *obj = of_nicira_controller_role_request_new(OF_VERSION_1_0);
        of_message_t msg;
        of_nicira_controller_role_request_OF_VERSION_1_0_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_nicira_controller_role_request_delete(obj);
    }

    {
        of_nicira_controller_role_reply_t *obj = of_nicira_controller_role_reply_new(OF_VERSION_1_0);
        of_message_t msg;
        of_nicira_controller_role_reply_OF_VERSION_1_0_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_nicira_controller_role_reply_delete(obj);
    }

    {
        of_hello_failed_error_msg_t *obj = of_hello_failed_error_msg_new(OF_VERSION_1_0);
        of_message_t msg;
        of_hello_failed_error_msg_OF_VERSION_1_0_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_hello_failed_error_msg_delete(obj);
    }

    {
        of_hello_t *obj = of_hello_new(OF_VERSION_1_0);
        of_message_t msg;
        of_hello_OF_VERSION_1_0_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_hello_delete(obj);
    }

    {
        of_get_config_request_t *obj = of_get_config_request_new(OF_VERSION_1_0);
        of_message_t msg;
        of_get_config_request_OF_VERSION_1_0_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_get_config_request_delete(obj);
    }

    {
        of_get_config_reply_t *obj = of_get_config_reply_new(OF_VERSION_1_0);
        of_message_t msg;
        of_get_config_reply_OF_VERSION_1_0_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_get_config_reply_delete(obj);
    }

    {
        of_flow_stats_request_t *obj = of_flow_stats_request_new(OF_VERSION_1_0);
        of_message_t msg;
        of_flow_stats_request_OF_VERSION_1_0_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_flow_stats_request_delete(obj);
    }

    {
        of_flow_stats_reply_t *obj = of_flow_stats_reply_new(OF_VERSION_1_0);
        of_message_t msg;
        of_flow_stats_reply_OF_VERSION_1_0_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_flow_stats_reply_delete(obj);
    }

    {
        of_flow_removed_t *obj = of_flow_removed_new(OF_VERSION_1_0);
        of_message_t msg;
        of_flow_removed_OF_VERSION_1_0_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_flow_removed_delete(obj);
    }

    {
        of_flow_modify_strict_t *obj = of_flow_modify_strict_new(OF_VERSION_1_0);
        of_message_t msg;
        of_flow_modify_strict_OF_VERSION_1_0_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_flow_modify_strict_delete(obj);
    }

    {
        of_flow_modify_t *obj = of_flow_modify_new(OF_VERSION_1_0);
        of_message_t msg;
        of_flow_modify_OF_VERSION_1_0_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_flow_modify_delete(obj);
    }

    {
        of_flow_mod_failed_error_msg_t *obj = of_flow_mod_failed_error_msg_new(OF_VERSION_1_0);
        of_message_t msg;
        of_flow_mod_failed_error_msg_OF_VERSION_1_0_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_flow_mod_failed_error_msg_delete(obj);
    }

    {
        of_flow_delete_strict_t *obj = of_flow_delete_strict_new(OF_VERSION_1_0);
        of_message_t msg;
        of_flow_delete_strict_OF_VERSION_1_0_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_flow_delete_strict_delete(obj);
    }

    {
        of_flow_delete_t *obj = of_flow_delete_new(OF_VERSION_1_0);
        of_message_t msg;
        of_flow_delete_OF_VERSION_1_0_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_flow_delete_delete(obj);
    }

    {
        of_flow_add_t *obj = of_flow_add_new(OF_VERSION_1_0);
        of_message_t msg;
        of_flow_add_OF_VERSION_1_0_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_flow_add_delete(obj);
    }

    {
        of_features_request_t *obj = of_features_request_new(OF_VERSION_1_0);
        of_message_t msg;
        of_features_request_OF_VERSION_1_0_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_features_request_delete(obj);
    }

    {
        of_features_reply_t *obj = of_features_reply_new(OF_VERSION_1_0);
        of_message_t msg;
        of_features_reply_OF_VERSION_1_0_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_features_reply_delete(obj);
    }

    {
        of_experimenter_t *obj = of_experimenter_new(OF_VERSION_1_0);
        of_message_t msg;
        of_experimenter_OF_VERSION_1_0_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_experimenter_delete(obj);
    }

    {
        of_echo_request_t *obj = of_echo_request_new(OF_VERSION_1_0);
        of_message_t msg;
        of_echo_request_OF_VERSION_1_0_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_echo_request_delete(obj);
    }

    {
        of_echo_reply_t *obj = of_echo_reply_new(OF_VERSION_1_0);
        of_message_t msg;
        of_echo_reply_OF_VERSION_1_0_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_echo_reply_delete(obj);
    }

    {
        of_desc_stats_request_t *obj = of_desc_stats_request_new(OF_VERSION_1_0);
        of_message_t msg;
        of_desc_stats_request_OF_VERSION_1_0_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_desc_stats_request_delete(obj);
    }

    {
        of_desc_stats_reply_t *obj = of_desc_stats_reply_new(OF_VERSION_1_0);
        of_message_t msg;
        of_desc_stats_reply_OF_VERSION_1_0_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_desc_stats_reply_delete(obj);
    }

    {
        of_bsn_virtual_port_remove_request_t *obj = of_bsn_virtual_port_remove_request_new(OF_VERSION_1_0);
        of_message_t msg;
        of_bsn_virtual_port_remove_request_OF_VERSION_1_0_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_virtual_port_remove_request_delete(obj);
    }

    {
        of_bsn_virtual_port_remove_reply_t *obj = of_bsn_virtual_port_remove_reply_new(OF_VERSION_1_0);
        of_message_t msg;
        of_bsn_virtual_port_remove_reply_OF_VERSION_1_0_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_virtual_port_remove_reply_delete(obj);
    }

    {
        of_bsn_virtual_port_create_request_t *obj = of_bsn_virtual_port_create_request_new(OF_VERSION_1_0);
        of_message_t msg;
        of_bsn_virtual_port_create_request_OF_VERSION_1_0_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_virtual_port_create_request_delete(obj);
    }

    {
        of_bsn_virtual_port_create_reply_t *obj = of_bsn_virtual_port_create_reply_new(OF_VERSION_1_0);
        of_message_t msg;
        of_bsn_virtual_port_create_reply_OF_VERSION_1_0_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_virtual_port_create_reply_delete(obj);
    }

    {
        of_bsn_shell_status_t *obj = of_bsn_shell_status_new(OF_VERSION_1_0);
        of_message_t msg;
        of_bsn_shell_status_OF_VERSION_1_0_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_shell_status_delete(obj);
    }

    {
        of_bsn_shell_output_t *obj = of_bsn_shell_output_new(OF_VERSION_1_0);
        of_message_t msg;
        of_bsn_shell_output_OF_VERSION_1_0_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_shell_output_delete(obj);
    }

    {
        of_bsn_shell_command_t *obj = of_bsn_shell_command_new(OF_VERSION_1_0);
        of_message_t msg;
        of_bsn_shell_command_OF_VERSION_1_0_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_shell_command_delete(obj);
    }

    {
        of_bsn_set_pktin_suppression_request_t *obj = of_bsn_set_pktin_suppression_request_new(OF_VERSION_1_0);
        of_message_t msg;
        of_bsn_set_pktin_suppression_request_OF_VERSION_1_0_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_set_pktin_suppression_request_delete(obj);
    }

    {
        of_bsn_set_pktin_suppression_reply_t *obj = of_bsn_set_pktin_suppression_reply_new(OF_VERSION_1_0);
        of_message_t msg;
        of_bsn_set_pktin_suppression_reply_OF_VERSION_1_0_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_set_pktin_suppression_reply_delete(obj);
    }

    {
        of_bsn_set_mirroring_t *obj = of_bsn_set_mirroring_new(OF_VERSION_1_0);
        of_message_t msg;
        of_bsn_set_mirroring_OF_VERSION_1_0_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_set_mirroring_delete(obj);
    }

    {
        of_bsn_set_l2_table_request_t *obj = of_bsn_set_l2_table_request_new(OF_VERSION_1_0);
        of_message_t msg;
        of_bsn_set_l2_table_request_OF_VERSION_1_0_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_set_l2_table_request_delete(obj);
    }

    {
        of_bsn_set_l2_table_reply_t *obj = of_bsn_set_l2_table_reply_new(OF_VERSION_1_0);
        of_message_t msg;
        of_bsn_set_l2_table_reply_OF_VERSION_1_0_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_set_l2_table_reply_delete(obj);
    }

    {
        of_bsn_set_ip_mask_t *obj = of_bsn_set_ip_mask_new(OF_VERSION_1_0);
        of_message_t msg;
        of_bsn_set_ip_mask_OF_VERSION_1_0_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_set_ip_mask_delete(obj);
    }

    {
        of_bsn_pdu_tx_request_t *obj = of_bsn_pdu_tx_request_new(OF_VERSION_1_0);
        of_message_t msg;
        of_bsn_pdu_tx_request_OF_VERSION_1_0_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_pdu_tx_request_delete(obj);
    }

    {
        of_bsn_pdu_tx_reply_t *obj = of_bsn_pdu_tx_reply_new(OF_VERSION_1_0);
        of_message_t msg;
        of_bsn_pdu_tx_reply_OF_VERSION_1_0_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_pdu_tx_reply_delete(obj);
    }

    {
        of_bsn_pdu_rx_timeout_t *obj = of_bsn_pdu_rx_timeout_new(OF_VERSION_1_0);
        of_message_t msg;
        of_bsn_pdu_rx_timeout_OF_VERSION_1_0_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_pdu_rx_timeout_delete(obj);
    }

    {
        of_bsn_pdu_rx_request_t *obj = of_bsn_pdu_rx_request_new(OF_VERSION_1_0);
        of_message_t msg;
        of_bsn_pdu_rx_request_OF_VERSION_1_0_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_pdu_rx_request_delete(obj);
    }

    {
        of_bsn_pdu_rx_reply_t *obj = of_bsn_pdu_rx_reply_new(OF_VERSION_1_0);
        of_message_t msg;
        of_bsn_pdu_rx_reply_OF_VERSION_1_0_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_pdu_rx_reply_delete(obj);
    }

    {
        of_bsn_hybrid_get_request_t *obj = of_bsn_hybrid_get_request_new(OF_VERSION_1_0);
        of_message_t msg;
        of_bsn_hybrid_get_request_OF_VERSION_1_0_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_hybrid_get_request_delete(obj);
    }

    {
        of_bsn_hybrid_get_reply_t *obj = of_bsn_hybrid_get_reply_new(OF_VERSION_1_0);
        of_message_t msg;
        of_bsn_hybrid_get_reply_OF_VERSION_1_0_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_hybrid_get_reply_delete(obj);
    }

    {
        of_bsn_get_mirroring_request_t *obj = of_bsn_get_mirroring_request_new(OF_VERSION_1_0);
        of_message_t msg;
        of_bsn_get_mirroring_request_OF_VERSION_1_0_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_get_mirroring_request_delete(obj);
    }

    {
        of_bsn_get_mirroring_reply_t *obj = of_bsn_get_mirroring_reply_new(OF_VERSION_1_0);
        of_message_t msg;
        of_bsn_get_mirroring_reply_OF_VERSION_1_0_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_get_mirroring_reply_delete(obj);
    }

    {
        of_bsn_get_l2_table_request_t *obj = of_bsn_get_l2_table_request_new(OF_VERSION_1_0);
        of_message_t msg;
        of_bsn_get_l2_table_request_OF_VERSION_1_0_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_get_l2_table_request_delete(obj);
    }

    {
        of_bsn_get_l2_table_reply_t *obj = of_bsn_get_l2_table_reply_new(OF_VERSION_1_0);
        of_message_t msg;
        of_bsn_get_l2_table_reply_OF_VERSION_1_0_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_get_l2_table_reply_delete(obj);
    }

    {
        of_bsn_get_ip_mask_request_t *obj = of_bsn_get_ip_mask_request_new(OF_VERSION_1_0);
        of_message_t msg;
        of_bsn_get_ip_mask_request_OF_VERSION_1_0_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_get_ip_mask_request_delete(obj);
    }

    {
        of_bsn_get_ip_mask_reply_t *obj = of_bsn_get_ip_mask_reply_new(OF_VERSION_1_0);
        of_message_t msg;
        of_bsn_get_ip_mask_reply_OF_VERSION_1_0_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_get_ip_mask_reply_delete(obj);
    }

    {
        of_bsn_get_interfaces_request_t *obj = of_bsn_get_interfaces_request_new(OF_VERSION_1_0);
        of_message_t msg;
        of_bsn_get_interfaces_request_OF_VERSION_1_0_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_get_interfaces_request_delete(obj);
    }

    {
        of_bsn_get_interfaces_reply_t *obj = of_bsn_get_interfaces_reply_new(OF_VERSION_1_0);
        of_message_t msg;
        of_bsn_get_interfaces_reply_OF_VERSION_1_0_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_get_interfaces_reply_delete(obj);
    }

    {
        of_bsn_bw_enable_set_request_t *obj = of_bsn_bw_enable_set_request_new(OF_VERSION_1_0);
        of_message_t msg;
        of_bsn_bw_enable_set_request_OF_VERSION_1_0_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_bw_enable_set_request_delete(obj);
    }

    {
        of_bsn_bw_enable_set_reply_t *obj = of_bsn_bw_enable_set_reply_new(OF_VERSION_1_0);
        of_message_t msg;
        of_bsn_bw_enable_set_reply_OF_VERSION_1_0_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_bw_enable_set_reply_delete(obj);
    }

    {
        of_bsn_bw_enable_get_request_t *obj = of_bsn_bw_enable_get_request_new(OF_VERSION_1_0);
        of_message_t msg;
        of_bsn_bw_enable_get_request_OF_VERSION_1_0_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_bw_enable_get_request_delete(obj);
    }

    {
        of_bsn_bw_enable_get_reply_t *obj = of_bsn_bw_enable_get_reply_new(OF_VERSION_1_0);
        of_message_t msg;
        of_bsn_bw_enable_get_reply_OF_VERSION_1_0_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_bw_enable_get_reply_delete(obj);
    }

    {
        of_bsn_bw_clear_data_request_t *obj = of_bsn_bw_clear_data_request_new(OF_VERSION_1_0);
        of_message_t msg;
        of_bsn_bw_clear_data_request_OF_VERSION_1_0_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_bw_clear_data_request_delete(obj);
    }

    {
        of_bsn_bw_clear_data_reply_t *obj = of_bsn_bw_clear_data_reply_new(OF_VERSION_1_0);
        of_message_t msg;
        of_bsn_bw_clear_data_reply_OF_VERSION_1_0_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_bw_clear_data_reply_delete(obj);
    }

    {
        of_barrier_request_t *obj = of_barrier_request_new(OF_VERSION_1_0);
        of_message_t msg;
        of_barrier_request_OF_VERSION_1_0_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_barrier_request_delete(obj);
    }

    {
        of_barrier_reply_t *obj = of_barrier_reply_new(OF_VERSION_1_0);
        of_message_t msg;
        of_barrier_reply_OF_VERSION_1_0_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_barrier_reply_delete(obj);
    }

    {
        of_bad_request_error_msg_t *obj = of_bad_request_error_msg_new(OF_VERSION_1_0);
        of_message_t msg;
        of_bad_request_error_msg_OF_VERSION_1_0_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bad_request_error_msg_delete(obj);
    }

    {
        of_bad_action_error_msg_t *obj = of_bad_action_error_msg_new(OF_VERSION_1_0);
        of_message_t msg;
        of_bad_action_error_msg_OF_VERSION_1_0_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bad_action_error_msg_delete(obj);
    }

    {
        of_aggregate_stats_request_t *obj = of_aggregate_stats_request_new(OF_VERSION_1_0);
        of_message_t msg;
        of_aggregate_stats_request_OF_VERSION_1_0_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_aggregate_stats_request_delete(obj);
    }

    {
        of_aggregate_stats_reply_t *obj = of_aggregate_stats_reply_new(OF_VERSION_1_0);
        of_message_t msg;
        of_aggregate_stats_reply_OF_VERSION_1_0_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_aggregate_stats_reply_delete(obj);
    }

    {
        of_table_stats_request_t *obj = of_table_stats_request_new(OF_VERSION_1_1);
        of_message_t msg;
        of_table_stats_request_OF_VERSION_1_1_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_table_stats_request_delete(obj);
    }

    {
        of_table_stats_reply_t *obj = of_table_stats_reply_new(OF_VERSION_1_1);
        of_message_t msg;
        of_table_stats_reply_OF_VERSION_1_1_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_table_stats_reply_delete(obj);
    }

    {
        of_table_mod_failed_error_msg_t *obj = of_table_mod_failed_error_msg_new(OF_VERSION_1_1);
        of_message_t msg;
        of_table_mod_failed_error_msg_OF_VERSION_1_1_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_table_mod_failed_error_msg_delete(obj);
    }

    {
        of_table_mod_t *obj = of_table_mod_new(OF_VERSION_1_1);
        of_message_t msg;
        of_table_mod_OF_VERSION_1_1_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_table_mod_delete(obj);
    }

    {
        of_switch_config_failed_error_msg_t *obj = of_switch_config_failed_error_msg_new(OF_VERSION_1_1);
        of_message_t msg;
        of_switch_config_failed_error_msg_OF_VERSION_1_1_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_switch_config_failed_error_msg_delete(obj);
    }

    {
        of_set_config_t *obj = of_set_config_new(OF_VERSION_1_1);
        of_message_t msg;
        of_set_config_OF_VERSION_1_1_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_set_config_delete(obj);
    }

    {
        of_queue_stats_request_t *obj = of_queue_stats_request_new(OF_VERSION_1_1);
        of_message_t msg;
        of_queue_stats_request_OF_VERSION_1_1_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_queue_stats_request_delete(obj);
    }

    {
        of_queue_stats_reply_t *obj = of_queue_stats_reply_new(OF_VERSION_1_1);
        of_message_t msg;
        of_queue_stats_reply_OF_VERSION_1_1_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_queue_stats_reply_delete(obj);
    }

    {
        of_queue_op_failed_error_msg_t *obj = of_queue_op_failed_error_msg_new(OF_VERSION_1_1);
        of_message_t msg;
        of_queue_op_failed_error_msg_OF_VERSION_1_1_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_queue_op_failed_error_msg_delete(obj);
    }

    {
        of_queue_get_config_request_t *obj = of_queue_get_config_request_new(OF_VERSION_1_1);
        of_message_t msg;
        of_queue_get_config_request_OF_VERSION_1_1_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_queue_get_config_request_delete(obj);
    }

    {
        of_queue_get_config_reply_t *obj = of_queue_get_config_reply_new(OF_VERSION_1_1);
        of_message_t msg;
        of_queue_get_config_reply_OF_VERSION_1_1_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_queue_get_config_reply_delete(obj);
    }

    {
        of_port_status_t *obj = of_port_status_new(OF_VERSION_1_1);
        of_message_t msg;
        of_port_status_OF_VERSION_1_1_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_port_status_delete(obj);
    }

    {
        of_port_stats_request_t *obj = of_port_stats_request_new(OF_VERSION_1_1);
        of_message_t msg;
        of_port_stats_request_OF_VERSION_1_1_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_port_stats_request_delete(obj);
    }

    {
        of_port_stats_reply_t *obj = of_port_stats_reply_new(OF_VERSION_1_1);
        of_message_t msg;
        of_port_stats_reply_OF_VERSION_1_1_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_port_stats_reply_delete(obj);
    }

    {
        of_port_mod_failed_error_msg_t *obj = of_port_mod_failed_error_msg_new(OF_VERSION_1_1);
        of_message_t msg;
        of_port_mod_failed_error_msg_OF_VERSION_1_1_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_port_mod_failed_error_msg_delete(obj);
    }

    {
        of_port_mod_t *obj = of_port_mod_new(OF_VERSION_1_1);
        of_message_t msg;
        of_port_mod_OF_VERSION_1_1_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_port_mod_delete(obj);
    }

    {
        of_packet_out_t *obj = of_packet_out_new(OF_VERSION_1_1);
        of_message_t msg;
        of_packet_out_OF_VERSION_1_1_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_packet_out_delete(obj);
    }

    {
        of_packet_in_t *obj = of_packet_in_new(OF_VERSION_1_1);
        of_message_t msg;
        of_packet_in_OF_VERSION_1_1_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_packet_in_delete(obj);
    }

    {
        of_hello_failed_error_msg_t *obj = of_hello_failed_error_msg_new(OF_VERSION_1_1);
        of_message_t msg;
        of_hello_failed_error_msg_OF_VERSION_1_1_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_hello_failed_error_msg_delete(obj);
    }

    {
        of_hello_t *obj = of_hello_new(OF_VERSION_1_1);
        of_message_t msg;
        of_hello_OF_VERSION_1_1_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_hello_delete(obj);
    }

    {
        of_group_stats_request_t *obj = of_group_stats_request_new(OF_VERSION_1_1);
        of_message_t msg;
        of_group_stats_request_OF_VERSION_1_1_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_group_stats_request_delete(obj);
    }

    {
        of_group_stats_reply_t *obj = of_group_stats_reply_new(OF_VERSION_1_1);
        of_message_t msg;
        of_group_stats_reply_OF_VERSION_1_1_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_group_stats_reply_delete(obj);
    }

    {
        of_group_mod_failed_error_msg_t *obj = of_group_mod_failed_error_msg_new(OF_VERSION_1_1);
        of_message_t msg;
        of_group_mod_failed_error_msg_OF_VERSION_1_1_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_group_mod_failed_error_msg_delete(obj);
    }

    {
        of_group_mod_t *obj = of_group_mod_new(OF_VERSION_1_1);
        of_message_t msg;
        of_group_mod_OF_VERSION_1_1_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_group_mod_delete(obj);
    }

    {
        of_group_desc_stats_request_t *obj = of_group_desc_stats_request_new(OF_VERSION_1_1);
        of_message_t msg;
        of_group_desc_stats_request_OF_VERSION_1_1_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_group_desc_stats_request_delete(obj);
    }

    {
        of_group_desc_stats_reply_t *obj = of_group_desc_stats_reply_new(OF_VERSION_1_1);
        of_message_t msg;
        of_group_desc_stats_reply_OF_VERSION_1_1_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_group_desc_stats_reply_delete(obj);
    }

    {
        of_get_config_request_t *obj = of_get_config_request_new(OF_VERSION_1_1);
        of_message_t msg;
        of_get_config_request_OF_VERSION_1_1_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_get_config_request_delete(obj);
    }

    {
        of_get_config_reply_t *obj = of_get_config_reply_new(OF_VERSION_1_1);
        of_message_t msg;
        of_get_config_reply_OF_VERSION_1_1_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_get_config_reply_delete(obj);
    }

    {
        of_flow_stats_request_t *obj = of_flow_stats_request_new(OF_VERSION_1_1);
        of_message_t msg;
        of_flow_stats_request_OF_VERSION_1_1_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_flow_stats_request_delete(obj);
    }

    {
        of_flow_stats_reply_t *obj = of_flow_stats_reply_new(OF_VERSION_1_1);
        of_message_t msg;
        of_flow_stats_reply_OF_VERSION_1_1_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_flow_stats_reply_delete(obj);
    }

    {
        of_flow_removed_t *obj = of_flow_removed_new(OF_VERSION_1_1);
        of_message_t msg;
        of_flow_removed_OF_VERSION_1_1_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_flow_removed_delete(obj);
    }

    {
        of_flow_modify_strict_t *obj = of_flow_modify_strict_new(OF_VERSION_1_1);
        of_message_t msg;
        of_flow_modify_strict_OF_VERSION_1_1_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_flow_modify_strict_delete(obj);
    }

    {
        of_flow_modify_t *obj = of_flow_modify_new(OF_VERSION_1_1);
        of_message_t msg;
        of_flow_modify_OF_VERSION_1_1_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_flow_modify_delete(obj);
    }

    {
        of_flow_mod_failed_error_msg_t *obj = of_flow_mod_failed_error_msg_new(OF_VERSION_1_1);
        of_message_t msg;
        of_flow_mod_failed_error_msg_OF_VERSION_1_1_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_flow_mod_failed_error_msg_delete(obj);
    }

    {
        of_flow_delete_strict_t *obj = of_flow_delete_strict_new(OF_VERSION_1_1);
        of_message_t msg;
        of_flow_delete_strict_OF_VERSION_1_1_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_flow_delete_strict_delete(obj);
    }

    {
        of_flow_delete_t *obj = of_flow_delete_new(OF_VERSION_1_1);
        of_message_t msg;
        of_flow_delete_OF_VERSION_1_1_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_flow_delete_delete(obj);
    }

    {
        of_flow_add_t *obj = of_flow_add_new(OF_VERSION_1_1);
        of_message_t msg;
        of_flow_add_OF_VERSION_1_1_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_flow_add_delete(obj);
    }

    {
        of_features_request_t *obj = of_features_request_new(OF_VERSION_1_1);
        of_message_t msg;
        of_features_request_OF_VERSION_1_1_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_features_request_delete(obj);
    }

    {
        of_features_reply_t *obj = of_features_reply_new(OF_VERSION_1_1);
        of_message_t msg;
        of_features_reply_OF_VERSION_1_1_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_features_reply_delete(obj);
    }

    {
        of_experimenter_t *obj = of_experimenter_new(OF_VERSION_1_1);
        of_message_t msg;
        of_experimenter_OF_VERSION_1_1_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_experimenter_delete(obj);
    }

    {
        of_echo_request_t *obj = of_echo_request_new(OF_VERSION_1_1);
        of_message_t msg;
        of_echo_request_OF_VERSION_1_1_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_echo_request_delete(obj);
    }

    {
        of_echo_reply_t *obj = of_echo_reply_new(OF_VERSION_1_1);
        of_message_t msg;
        of_echo_reply_OF_VERSION_1_1_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_echo_reply_delete(obj);
    }

    {
        of_desc_stats_request_t *obj = of_desc_stats_request_new(OF_VERSION_1_1);
        of_message_t msg;
        of_desc_stats_request_OF_VERSION_1_1_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_desc_stats_request_delete(obj);
    }

    {
        of_desc_stats_reply_t *obj = of_desc_stats_reply_new(OF_VERSION_1_1);
        of_message_t msg;
        of_desc_stats_reply_OF_VERSION_1_1_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_desc_stats_reply_delete(obj);
    }

    {
        of_bsn_virtual_port_remove_request_t *obj = of_bsn_virtual_port_remove_request_new(OF_VERSION_1_1);
        of_message_t msg;
        of_bsn_virtual_port_remove_request_OF_VERSION_1_1_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_virtual_port_remove_request_delete(obj);
    }

    {
        of_bsn_virtual_port_remove_reply_t *obj = of_bsn_virtual_port_remove_reply_new(OF_VERSION_1_1);
        of_message_t msg;
        of_bsn_virtual_port_remove_reply_OF_VERSION_1_1_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_virtual_port_remove_reply_delete(obj);
    }

    {
        of_bsn_virtual_port_create_request_t *obj = of_bsn_virtual_port_create_request_new(OF_VERSION_1_1);
        of_message_t msg;
        of_bsn_virtual_port_create_request_OF_VERSION_1_1_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_virtual_port_create_request_delete(obj);
    }

    {
        of_bsn_virtual_port_create_reply_t *obj = of_bsn_virtual_port_create_reply_new(OF_VERSION_1_1);
        of_message_t msg;
        of_bsn_virtual_port_create_reply_OF_VERSION_1_1_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_virtual_port_create_reply_delete(obj);
    }

    {
        of_bsn_set_pktin_suppression_request_t *obj = of_bsn_set_pktin_suppression_request_new(OF_VERSION_1_1);
        of_message_t msg;
        of_bsn_set_pktin_suppression_request_OF_VERSION_1_1_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_set_pktin_suppression_request_delete(obj);
    }

    {
        of_bsn_set_pktin_suppression_reply_t *obj = of_bsn_set_pktin_suppression_reply_new(OF_VERSION_1_1);
        of_message_t msg;
        of_bsn_set_pktin_suppression_reply_OF_VERSION_1_1_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_set_pktin_suppression_reply_delete(obj);
    }

    {
        of_bsn_set_mirroring_t *obj = of_bsn_set_mirroring_new(OF_VERSION_1_1);
        of_message_t msg;
        of_bsn_set_mirroring_OF_VERSION_1_1_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_set_mirroring_delete(obj);
    }

    {
        of_bsn_pdu_tx_request_t *obj = of_bsn_pdu_tx_request_new(OF_VERSION_1_1);
        of_message_t msg;
        of_bsn_pdu_tx_request_OF_VERSION_1_1_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_pdu_tx_request_delete(obj);
    }

    {
        of_bsn_pdu_tx_reply_t *obj = of_bsn_pdu_tx_reply_new(OF_VERSION_1_1);
        of_message_t msg;
        of_bsn_pdu_tx_reply_OF_VERSION_1_1_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_pdu_tx_reply_delete(obj);
    }

    {
        of_bsn_pdu_rx_timeout_t *obj = of_bsn_pdu_rx_timeout_new(OF_VERSION_1_1);
        of_message_t msg;
        of_bsn_pdu_rx_timeout_OF_VERSION_1_1_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_pdu_rx_timeout_delete(obj);
    }

    {
        of_bsn_pdu_rx_request_t *obj = of_bsn_pdu_rx_request_new(OF_VERSION_1_1);
        of_message_t msg;
        of_bsn_pdu_rx_request_OF_VERSION_1_1_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_pdu_rx_request_delete(obj);
    }

    {
        of_bsn_pdu_rx_reply_t *obj = of_bsn_pdu_rx_reply_new(OF_VERSION_1_1);
        of_message_t msg;
        of_bsn_pdu_rx_reply_OF_VERSION_1_1_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_pdu_rx_reply_delete(obj);
    }

    {
        of_bsn_get_mirroring_request_t *obj = of_bsn_get_mirroring_request_new(OF_VERSION_1_1);
        of_message_t msg;
        of_bsn_get_mirroring_request_OF_VERSION_1_1_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_get_mirroring_request_delete(obj);
    }

    {
        of_bsn_get_mirroring_reply_t *obj = of_bsn_get_mirroring_reply_new(OF_VERSION_1_1);
        of_message_t msg;
        of_bsn_get_mirroring_reply_OF_VERSION_1_1_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_get_mirroring_reply_delete(obj);
    }

    {
        of_bsn_get_interfaces_request_t *obj = of_bsn_get_interfaces_request_new(OF_VERSION_1_1);
        of_message_t msg;
        of_bsn_get_interfaces_request_OF_VERSION_1_1_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_get_interfaces_request_delete(obj);
    }

    {
        of_bsn_get_interfaces_reply_t *obj = of_bsn_get_interfaces_reply_new(OF_VERSION_1_1);
        of_message_t msg;
        of_bsn_get_interfaces_reply_OF_VERSION_1_1_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_get_interfaces_reply_delete(obj);
    }

    {
        of_bsn_bw_enable_set_request_t *obj = of_bsn_bw_enable_set_request_new(OF_VERSION_1_1);
        of_message_t msg;
        of_bsn_bw_enable_set_request_OF_VERSION_1_1_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_bw_enable_set_request_delete(obj);
    }

    {
        of_bsn_bw_enable_set_reply_t *obj = of_bsn_bw_enable_set_reply_new(OF_VERSION_1_1);
        of_message_t msg;
        of_bsn_bw_enable_set_reply_OF_VERSION_1_1_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_bw_enable_set_reply_delete(obj);
    }

    {
        of_bsn_bw_enable_get_request_t *obj = of_bsn_bw_enable_get_request_new(OF_VERSION_1_1);
        of_message_t msg;
        of_bsn_bw_enable_get_request_OF_VERSION_1_1_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_bw_enable_get_request_delete(obj);
    }

    {
        of_bsn_bw_enable_get_reply_t *obj = of_bsn_bw_enable_get_reply_new(OF_VERSION_1_1);
        of_message_t msg;
        of_bsn_bw_enable_get_reply_OF_VERSION_1_1_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_bw_enable_get_reply_delete(obj);
    }

    {
        of_bsn_bw_clear_data_request_t *obj = of_bsn_bw_clear_data_request_new(OF_VERSION_1_1);
        of_message_t msg;
        of_bsn_bw_clear_data_request_OF_VERSION_1_1_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_bw_clear_data_request_delete(obj);
    }

    {
        of_bsn_bw_clear_data_reply_t *obj = of_bsn_bw_clear_data_reply_new(OF_VERSION_1_1);
        of_message_t msg;
        of_bsn_bw_clear_data_reply_OF_VERSION_1_1_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_bw_clear_data_reply_delete(obj);
    }

    {
        of_barrier_request_t *obj = of_barrier_request_new(OF_VERSION_1_1);
        of_message_t msg;
        of_barrier_request_OF_VERSION_1_1_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_barrier_request_delete(obj);
    }

    {
        of_barrier_reply_t *obj = of_barrier_reply_new(OF_VERSION_1_1);
        of_message_t msg;
        of_barrier_reply_OF_VERSION_1_1_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_barrier_reply_delete(obj);
    }

    {
        of_bad_request_error_msg_t *obj = of_bad_request_error_msg_new(OF_VERSION_1_1);
        of_message_t msg;
        of_bad_request_error_msg_OF_VERSION_1_1_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bad_request_error_msg_delete(obj);
    }

    {
        of_bad_match_error_msg_t *obj = of_bad_match_error_msg_new(OF_VERSION_1_1);
        of_message_t msg;
        of_bad_match_error_msg_OF_VERSION_1_1_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bad_match_error_msg_delete(obj);
    }

    {
        of_bad_instruction_error_msg_t *obj = of_bad_instruction_error_msg_new(OF_VERSION_1_1);
        of_message_t msg;
        of_bad_instruction_error_msg_OF_VERSION_1_1_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bad_instruction_error_msg_delete(obj);
    }

    {
        of_bad_action_error_msg_t *obj = of_bad_action_error_msg_new(OF_VERSION_1_1);
        of_message_t msg;
        of_bad_action_error_msg_OF_VERSION_1_1_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bad_action_error_msg_delete(obj);
    }

    {
        of_aggregate_stats_request_t *obj = of_aggregate_stats_request_new(OF_VERSION_1_1);
        of_message_t msg;
        of_aggregate_stats_request_OF_VERSION_1_1_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_aggregate_stats_request_delete(obj);
    }

    {
        of_aggregate_stats_reply_t *obj = of_aggregate_stats_reply_new(OF_VERSION_1_1);
        of_message_t msg;
        of_aggregate_stats_reply_OF_VERSION_1_1_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_aggregate_stats_reply_delete(obj);
    }

    {
        of_table_stats_request_t *obj = of_table_stats_request_new(OF_VERSION_1_2);
        of_message_t msg;
        of_table_stats_request_OF_VERSION_1_2_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_table_stats_request_delete(obj);
    }

    {
        of_table_stats_reply_t *obj = of_table_stats_reply_new(OF_VERSION_1_2);
        of_message_t msg;
        of_table_stats_reply_OF_VERSION_1_2_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_table_stats_reply_delete(obj);
    }

    {
        of_table_mod_failed_error_msg_t *obj = of_table_mod_failed_error_msg_new(OF_VERSION_1_2);
        of_message_t msg;
        of_table_mod_failed_error_msg_OF_VERSION_1_2_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_table_mod_failed_error_msg_delete(obj);
    }

    {
        of_table_mod_t *obj = of_table_mod_new(OF_VERSION_1_2);
        of_message_t msg;
        of_table_mod_OF_VERSION_1_2_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_table_mod_delete(obj);
    }

    {
        of_switch_config_failed_error_msg_t *obj = of_switch_config_failed_error_msg_new(OF_VERSION_1_2);
        of_message_t msg;
        of_switch_config_failed_error_msg_OF_VERSION_1_2_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_switch_config_failed_error_msg_delete(obj);
    }

    {
        of_set_config_t *obj = of_set_config_new(OF_VERSION_1_2);
        of_message_t msg;
        of_set_config_OF_VERSION_1_2_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_set_config_delete(obj);
    }

    {
        of_role_request_failed_error_msg_t *obj = of_role_request_failed_error_msg_new(OF_VERSION_1_2);
        of_message_t msg;
        of_role_request_failed_error_msg_OF_VERSION_1_2_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_role_request_failed_error_msg_delete(obj);
    }

    {
        of_role_request_t *obj = of_role_request_new(OF_VERSION_1_2);
        of_message_t msg;
        of_role_request_OF_VERSION_1_2_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_role_request_delete(obj);
    }

    {
        of_role_reply_t *obj = of_role_reply_new(OF_VERSION_1_2);
        of_message_t msg;
        of_role_reply_OF_VERSION_1_2_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_role_reply_delete(obj);
    }

    {
        of_queue_stats_request_t *obj = of_queue_stats_request_new(OF_VERSION_1_2);
        of_message_t msg;
        of_queue_stats_request_OF_VERSION_1_2_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_queue_stats_request_delete(obj);
    }

    {
        of_queue_stats_reply_t *obj = of_queue_stats_reply_new(OF_VERSION_1_2);
        of_message_t msg;
        of_queue_stats_reply_OF_VERSION_1_2_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_queue_stats_reply_delete(obj);
    }

    {
        of_queue_op_failed_error_msg_t *obj = of_queue_op_failed_error_msg_new(OF_VERSION_1_2);
        of_message_t msg;
        of_queue_op_failed_error_msg_OF_VERSION_1_2_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_queue_op_failed_error_msg_delete(obj);
    }

    {
        of_queue_get_config_request_t *obj = of_queue_get_config_request_new(OF_VERSION_1_2);
        of_message_t msg;
        of_queue_get_config_request_OF_VERSION_1_2_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_queue_get_config_request_delete(obj);
    }

    {
        of_queue_get_config_reply_t *obj = of_queue_get_config_reply_new(OF_VERSION_1_2);
        of_message_t msg;
        of_queue_get_config_reply_OF_VERSION_1_2_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_queue_get_config_reply_delete(obj);
    }

    {
        of_port_status_t *obj = of_port_status_new(OF_VERSION_1_2);
        of_message_t msg;
        of_port_status_OF_VERSION_1_2_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_port_status_delete(obj);
    }

    {
        of_port_stats_request_t *obj = of_port_stats_request_new(OF_VERSION_1_2);
        of_message_t msg;
        of_port_stats_request_OF_VERSION_1_2_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_port_stats_request_delete(obj);
    }

    {
        of_port_stats_reply_t *obj = of_port_stats_reply_new(OF_VERSION_1_2);
        of_message_t msg;
        of_port_stats_reply_OF_VERSION_1_2_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_port_stats_reply_delete(obj);
    }

    {
        of_port_mod_failed_error_msg_t *obj = of_port_mod_failed_error_msg_new(OF_VERSION_1_2);
        of_message_t msg;
        of_port_mod_failed_error_msg_OF_VERSION_1_2_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_port_mod_failed_error_msg_delete(obj);
    }

    {
        of_port_mod_t *obj = of_port_mod_new(OF_VERSION_1_2);
        of_message_t msg;
        of_port_mod_OF_VERSION_1_2_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_port_mod_delete(obj);
    }

    {
        of_packet_out_t *obj = of_packet_out_new(OF_VERSION_1_2);
        of_message_t msg;
        of_packet_out_OF_VERSION_1_2_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_packet_out_delete(obj);
    }

    {
        of_packet_in_t *obj = of_packet_in_new(OF_VERSION_1_2);
        of_message_t msg;
        of_packet_in_OF_VERSION_1_2_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_packet_in_delete(obj);
    }

    {
        of_hello_failed_error_msg_t *obj = of_hello_failed_error_msg_new(OF_VERSION_1_2);
        of_message_t msg;
        of_hello_failed_error_msg_OF_VERSION_1_2_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_hello_failed_error_msg_delete(obj);
    }

    {
        of_hello_t *obj = of_hello_new(OF_VERSION_1_2);
        of_message_t msg;
        of_hello_OF_VERSION_1_2_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_hello_delete(obj);
    }

    {
        of_group_stats_request_t *obj = of_group_stats_request_new(OF_VERSION_1_2);
        of_message_t msg;
        of_group_stats_request_OF_VERSION_1_2_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_group_stats_request_delete(obj);
    }

    {
        of_group_stats_reply_t *obj = of_group_stats_reply_new(OF_VERSION_1_2);
        of_message_t msg;
        of_group_stats_reply_OF_VERSION_1_2_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_group_stats_reply_delete(obj);
    }

    {
        of_group_mod_failed_error_msg_t *obj = of_group_mod_failed_error_msg_new(OF_VERSION_1_2);
        of_message_t msg;
        of_group_mod_failed_error_msg_OF_VERSION_1_2_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_group_mod_failed_error_msg_delete(obj);
    }

    {
        of_group_mod_t *obj = of_group_mod_new(OF_VERSION_1_2);
        of_message_t msg;
        of_group_mod_OF_VERSION_1_2_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_group_mod_delete(obj);
    }

    {
        of_group_features_stats_request_t *obj = of_group_features_stats_request_new(OF_VERSION_1_2);
        of_message_t msg;
        of_group_features_stats_request_OF_VERSION_1_2_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_group_features_stats_request_delete(obj);
    }

    {
        of_group_features_stats_reply_t *obj = of_group_features_stats_reply_new(OF_VERSION_1_2);
        of_message_t msg;
        of_group_features_stats_reply_OF_VERSION_1_2_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_group_features_stats_reply_delete(obj);
    }

    {
        of_group_desc_stats_request_t *obj = of_group_desc_stats_request_new(OF_VERSION_1_2);
        of_message_t msg;
        of_group_desc_stats_request_OF_VERSION_1_2_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_group_desc_stats_request_delete(obj);
    }

    {
        of_group_desc_stats_reply_t *obj = of_group_desc_stats_reply_new(OF_VERSION_1_2);
        of_message_t msg;
        of_group_desc_stats_reply_OF_VERSION_1_2_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_group_desc_stats_reply_delete(obj);
    }

    {
        of_get_config_request_t *obj = of_get_config_request_new(OF_VERSION_1_2);
        of_message_t msg;
        of_get_config_request_OF_VERSION_1_2_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_get_config_request_delete(obj);
    }

    {
        of_get_config_reply_t *obj = of_get_config_reply_new(OF_VERSION_1_2);
        of_message_t msg;
        of_get_config_reply_OF_VERSION_1_2_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_get_config_reply_delete(obj);
    }

    {
        of_flow_stats_request_t *obj = of_flow_stats_request_new(OF_VERSION_1_2);
        of_message_t msg;
        of_flow_stats_request_OF_VERSION_1_2_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_flow_stats_request_delete(obj);
    }

    {
        of_flow_stats_reply_t *obj = of_flow_stats_reply_new(OF_VERSION_1_2);
        of_message_t msg;
        of_flow_stats_reply_OF_VERSION_1_2_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_flow_stats_reply_delete(obj);
    }

    {
        of_flow_removed_t *obj = of_flow_removed_new(OF_VERSION_1_2);
        of_message_t msg;
        of_flow_removed_OF_VERSION_1_2_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_flow_removed_delete(obj);
    }

    {
        of_flow_modify_strict_t *obj = of_flow_modify_strict_new(OF_VERSION_1_2);
        of_message_t msg;
        of_flow_modify_strict_OF_VERSION_1_2_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_flow_modify_strict_delete(obj);
    }

    {
        of_flow_modify_t *obj = of_flow_modify_new(OF_VERSION_1_2);
        of_message_t msg;
        of_flow_modify_OF_VERSION_1_2_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_flow_modify_delete(obj);
    }

    {
        of_flow_mod_failed_error_msg_t *obj = of_flow_mod_failed_error_msg_new(OF_VERSION_1_2);
        of_message_t msg;
        of_flow_mod_failed_error_msg_OF_VERSION_1_2_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_flow_mod_failed_error_msg_delete(obj);
    }

    {
        of_flow_delete_strict_t *obj = of_flow_delete_strict_new(OF_VERSION_1_2);
        of_message_t msg;
        of_flow_delete_strict_OF_VERSION_1_2_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_flow_delete_strict_delete(obj);
    }

    {
        of_flow_delete_t *obj = of_flow_delete_new(OF_VERSION_1_2);
        of_message_t msg;
        of_flow_delete_OF_VERSION_1_2_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_flow_delete_delete(obj);
    }

    {
        of_flow_add_t *obj = of_flow_add_new(OF_VERSION_1_2);
        of_message_t msg;
        of_flow_add_OF_VERSION_1_2_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_flow_add_delete(obj);
    }

    {
        of_features_request_t *obj = of_features_request_new(OF_VERSION_1_2);
        of_message_t msg;
        of_features_request_OF_VERSION_1_2_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_features_request_delete(obj);
    }

    {
        of_features_reply_t *obj = of_features_reply_new(OF_VERSION_1_2);
        of_message_t msg;
        of_features_reply_OF_VERSION_1_2_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_features_reply_delete(obj);
    }

    {
        of_experimenter_error_msg_t *obj = of_experimenter_error_msg_new(OF_VERSION_1_2);
        of_message_t msg;
        of_experimenter_error_msg_OF_VERSION_1_2_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_experimenter_error_msg_delete(obj);
    }

    {
        of_experimenter_t *obj = of_experimenter_new(OF_VERSION_1_2);
        of_message_t msg;
        of_experimenter_OF_VERSION_1_2_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_experimenter_delete(obj);
    }

    {
        of_echo_request_t *obj = of_echo_request_new(OF_VERSION_1_2);
        of_message_t msg;
        of_echo_request_OF_VERSION_1_2_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_echo_request_delete(obj);
    }

    {
        of_echo_reply_t *obj = of_echo_reply_new(OF_VERSION_1_2);
        of_message_t msg;
        of_echo_reply_OF_VERSION_1_2_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_echo_reply_delete(obj);
    }

    {
        of_desc_stats_request_t *obj = of_desc_stats_request_new(OF_VERSION_1_2);
        of_message_t msg;
        of_desc_stats_request_OF_VERSION_1_2_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_desc_stats_request_delete(obj);
    }

    {
        of_desc_stats_reply_t *obj = of_desc_stats_reply_new(OF_VERSION_1_2);
        of_message_t msg;
        of_desc_stats_reply_OF_VERSION_1_2_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_desc_stats_reply_delete(obj);
    }

    {
        of_bsn_virtual_port_remove_request_t *obj = of_bsn_virtual_port_remove_request_new(OF_VERSION_1_2);
        of_message_t msg;
        of_bsn_virtual_port_remove_request_OF_VERSION_1_2_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_virtual_port_remove_request_delete(obj);
    }

    {
        of_bsn_virtual_port_remove_reply_t *obj = of_bsn_virtual_port_remove_reply_new(OF_VERSION_1_2);
        of_message_t msg;
        of_bsn_virtual_port_remove_reply_OF_VERSION_1_2_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_virtual_port_remove_reply_delete(obj);
    }

    {
        of_bsn_virtual_port_create_request_t *obj = of_bsn_virtual_port_create_request_new(OF_VERSION_1_2);
        of_message_t msg;
        of_bsn_virtual_port_create_request_OF_VERSION_1_2_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_virtual_port_create_request_delete(obj);
    }

    {
        of_bsn_virtual_port_create_reply_t *obj = of_bsn_virtual_port_create_reply_new(OF_VERSION_1_2);
        of_message_t msg;
        of_bsn_virtual_port_create_reply_OF_VERSION_1_2_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_virtual_port_create_reply_delete(obj);
    }

    {
        of_bsn_set_pktin_suppression_request_t *obj = of_bsn_set_pktin_suppression_request_new(OF_VERSION_1_2);
        of_message_t msg;
        of_bsn_set_pktin_suppression_request_OF_VERSION_1_2_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_set_pktin_suppression_request_delete(obj);
    }

    {
        of_bsn_set_pktin_suppression_reply_t *obj = of_bsn_set_pktin_suppression_reply_new(OF_VERSION_1_2);
        of_message_t msg;
        of_bsn_set_pktin_suppression_reply_OF_VERSION_1_2_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_set_pktin_suppression_reply_delete(obj);
    }

    {
        of_bsn_set_mirroring_t *obj = of_bsn_set_mirroring_new(OF_VERSION_1_2);
        of_message_t msg;
        of_bsn_set_mirroring_OF_VERSION_1_2_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_set_mirroring_delete(obj);
    }

    {
        of_bsn_pdu_tx_request_t *obj = of_bsn_pdu_tx_request_new(OF_VERSION_1_2);
        of_message_t msg;
        of_bsn_pdu_tx_request_OF_VERSION_1_2_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_pdu_tx_request_delete(obj);
    }

    {
        of_bsn_pdu_tx_reply_t *obj = of_bsn_pdu_tx_reply_new(OF_VERSION_1_2);
        of_message_t msg;
        of_bsn_pdu_tx_reply_OF_VERSION_1_2_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_pdu_tx_reply_delete(obj);
    }

    {
        of_bsn_pdu_rx_timeout_t *obj = of_bsn_pdu_rx_timeout_new(OF_VERSION_1_2);
        of_message_t msg;
        of_bsn_pdu_rx_timeout_OF_VERSION_1_2_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_pdu_rx_timeout_delete(obj);
    }

    {
        of_bsn_pdu_rx_request_t *obj = of_bsn_pdu_rx_request_new(OF_VERSION_1_2);
        of_message_t msg;
        of_bsn_pdu_rx_request_OF_VERSION_1_2_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_pdu_rx_request_delete(obj);
    }

    {
        of_bsn_pdu_rx_reply_t *obj = of_bsn_pdu_rx_reply_new(OF_VERSION_1_2);
        of_message_t msg;
        of_bsn_pdu_rx_reply_OF_VERSION_1_2_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_pdu_rx_reply_delete(obj);
    }

    {
        of_bsn_get_mirroring_request_t *obj = of_bsn_get_mirroring_request_new(OF_VERSION_1_2);
        of_message_t msg;
        of_bsn_get_mirroring_request_OF_VERSION_1_2_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_get_mirroring_request_delete(obj);
    }

    {
        of_bsn_get_mirroring_reply_t *obj = of_bsn_get_mirroring_reply_new(OF_VERSION_1_2);
        of_message_t msg;
        of_bsn_get_mirroring_reply_OF_VERSION_1_2_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_get_mirroring_reply_delete(obj);
    }

    {
        of_bsn_get_interfaces_request_t *obj = of_bsn_get_interfaces_request_new(OF_VERSION_1_2);
        of_message_t msg;
        of_bsn_get_interfaces_request_OF_VERSION_1_2_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_get_interfaces_request_delete(obj);
    }

    {
        of_bsn_get_interfaces_reply_t *obj = of_bsn_get_interfaces_reply_new(OF_VERSION_1_2);
        of_message_t msg;
        of_bsn_get_interfaces_reply_OF_VERSION_1_2_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_get_interfaces_reply_delete(obj);
    }

    {
        of_bsn_bw_enable_set_request_t *obj = of_bsn_bw_enable_set_request_new(OF_VERSION_1_2);
        of_message_t msg;
        of_bsn_bw_enable_set_request_OF_VERSION_1_2_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_bw_enable_set_request_delete(obj);
    }

    {
        of_bsn_bw_enable_set_reply_t *obj = of_bsn_bw_enable_set_reply_new(OF_VERSION_1_2);
        of_message_t msg;
        of_bsn_bw_enable_set_reply_OF_VERSION_1_2_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_bw_enable_set_reply_delete(obj);
    }

    {
        of_bsn_bw_enable_get_request_t *obj = of_bsn_bw_enable_get_request_new(OF_VERSION_1_2);
        of_message_t msg;
        of_bsn_bw_enable_get_request_OF_VERSION_1_2_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_bw_enable_get_request_delete(obj);
    }

    {
        of_bsn_bw_enable_get_reply_t *obj = of_bsn_bw_enable_get_reply_new(OF_VERSION_1_2);
        of_message_t msg;
        of_bsn_bw_enable_get_reply_OF_VERSION_1_2_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_bw_enable_get_reply_delete(obj);
    }

    {
        of_bsn_bw_clear_data_request_t *obj = of_bsn_bw_clear_data_request_new(OF_VERSION_1_2);
        of_message_t msg;
        of_bsn_bw_clear_data_request_OF_VERSION_1_2_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_bw_clear_data_request_delete(obj);
    }

    {
        of_bsn_bw_clear_data_reply_t *obj = of_bsn_bw_clear_data_reply_new(OF_VERSION_1_2);
        of_message_t msg;
        of_bsn_bw_clear_data_reply_OF_VERSION_1_2_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_bw_clear_data_reply_delete(obj);
    }

    {
        of_barrier_request_t *obj = of_barrier_request_new(OF_VERSION_1_2);
        of_message_t msg;
        of_barrier_request_OF_VERSION_1_2_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_barrier_request_delete(obj);
    }

    {
        of_barrier_reply_t *obj = of_barrier_reply_new(OF_VERSION_1_2);
        of_message_t msg;
        of_barrier_reply_OF_VERSION_1_2_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_barrier_reply_delete(obj);
    }

    {
        of_bad_request_error_msg_t *obj = of_bad_request_error_msg_new(OF_VERSION_1_2);
        of_message_t msg;
        of_bad_request_error_msg_OF_VERSION_1_2_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bad_request_error_msg_delete(obj);
    }

    {
        of_bad_match_error_msg_t *obj = of_bad_match_error_msg_new(OF_VERSION_1_2);
        of_message_t msg;
        of_bad_match_error_msg_OF_VERSION_1_2_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bad_match_error_msg_delete(obj);
    }

    {
        of_bad_instruction_error_msg_t *obj = of_bad_instruction_error_msg_new(OF_VERSION_1_2);
        of_message_t msg;
        of_bad_instruction_error_msg_OF_VERSION_1_2_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bad_instruction_error_msg_delete(obj);
    }

    {
        of_bad_action_error_msg_t *obj = of_bad_action_error_msg_new(OF_VERSION_1_2);
        of_message_t msg;
        of_bad_action_error_msg_OF_VERSION_1_2_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bad_action_error_msg_delete(obj);
    }

    {
        of_aggregate_stats_request_t *obj = of_aggregate_stats_request_new(OF_VERSION_1_2);
        of_message_t msg;
        of_aggregate_stats_request_OF_VERSION_1_2_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_aggregate_stats_request_delete(obj);
    }

    {
        of_aggregate_stats_reply_t *obj = of_aggregate_stats_reply_new(OF_VERSION_1_2);
        of_message_t msg;
        of_aggregate_stats_reply_OF_VERSION_1_2_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_aggregate_stats_reply_delete(obj);
    }

    {
        of_table_stats_request_t *obj = of_table_stats_request_new(OF_VERSION_1_3);
        of_message_t msg;
        of_table_stats_request_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_table_stats_request_delete(obj);
    }

    {
        of_table_stats_reply_t *obj = of_table_stats_reply_new(OF_VERSION_1_3);
        of_message_t msg;
        of_table_stats_reply_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_table_stats_reply_delete(obj);
    }

    {
        of_table_mod_failed_error_msg_t *obj = of_table_mod_failed_error_msg_new(OF_VERSION_1_3);
        of_message_t msg;
        of_table_mod_failed_error_msg_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_table_mod_failed_error_msg_delete(obj);
    }

    {
        of_table_mod_t *obj = of_table_mod_new(OF_VERSION_1_3);
        of_message_t msg;
        of_table_mod_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_table_mod_delete(obj);
    }

    {
        of_table_features_stats_request_t *obj = of_table_features_stats_request_new(OF_VERSION_1_3);
        of_message_t msg;
        of_table_features_stats_request_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_table_features_stats_request_delete(obj);
    }

    {
        of_table_features_stats_reply_t *obj = of_table_features_stats_reply_new(OF_VERSION_1_3);
        of_message_t msg;
        of_table_features_stats_reply_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_table_features_stats_reply_delete(obj);
    }

    {
        of_table_features_failed_error_msg_t *obj = of_table_features_failed_error_msg_new(OF_VERSION_1_3);
        of_message_t msg;
        of_table_features_failed_error_msg_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_table_features_failed_error_msg_delete(obj);
    }

    {
        of_switch_config_failed_error_msg_t *obj = of_switch_config_failed_error_msg_new(OF_VERSION_1_3);
        of_message_t msg;
        of_switch_config_failed_error_msg_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_switch_config_failed_error_msg_delete(obj);
    }

    {
        of_set_config_t *obj = of_set_config_new(OF_VERSION_1_3);
        of_message_t msg;
        of_set_config_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_set_config_delete(obj);
    }

    {
        of_role_request_failed_error_msg_t *obj = of_role_request_failed_error_msg_new(OF_VERSION_1_3);
        of_message_t msg;
        of_role_request_failed_error_msg_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_role_request_failed_error_msg_delete(obj);
    }

    {
        of_role_request_t *obj = of_role_request_new(OF_VERSION_1_3);
        of_message_t msg;
        of_role_request_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_role_request_delete(obj);
    }

    {
        of_role_reply_t *obj = of_role_reply_new(OF_VERSION_1_3);
        of_message_t msg;
        of_role_reply_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_role_reply_delete(obj);
    }

    {
        of_queue_stats_request_t *obj = of_queue_stats_request_new(OF_VERSION_1_3);
        of_message_t msg;
        of_queue_stats_request_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_queue_stats_request_delete(obj);
    }

    {
        of_queue_stats_reply_t *obj = of_queue_stats_reply_new(OF_VERSION_1_3);
        of_message_t msg;
        of_queue_stats_reply_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_queue_stats_reply_delete(obj);
    }

    {
        of_queue_op_failed_error_msg_t *obj = of_queue_op_failed_error_msg_new(OF_VERSION_1_3);
        of_message_t msg;
        of_queue_op_failed_error_msg_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_queue_op_failed_error_msg_delete(obj);
    }

    {
        of_queue_get_config_request_t *obj = of_queue_get_config_request_new(OF_VERSION_1_3);
        of_message_t msg;
        of_queue_get_config_request_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_queue_get_config_request_delete(obj);
    }

    {
        of_queue_get_config_reply_t *obj = of_queue_get_config_reply_new(OF_VERSION_1_3);
        of_message_t msg;
        of_queue_get_config_reply_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_queue_get_config_reply_delete(obj);
    }

    {
        of_port_status_t *obj = of_port_status_new(OF_VERSION_1_3);
        of_message_t msg;
        of_port_status_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_port_status_delete(obj);
    }

    {
        of_port_stats_request_t *obj = of_port_stats_request_new(OF_VERSION_1_3);
        of_message_t msg;
        of_port_stats_request_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_port_stats_request_delete(obj);
    }

    {
        of_port_stats_reply_t *obj = of_port_stats_reply_new(OF_VERSION_1_3);
        of_message_t msg;
        of_port_stats_reply_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_port_stats_reply_delete(obj);
    }

    {
        of_port_mod_failed_error_msg_t *obj = of_port_mod_failed_error_msg_new(OF_VERSION_1_3);
        of_message_t msg;
        of_port_mod_failed_error_msg_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_port_mod_failed_error_msg_delete(obj);
    }

    {
        of_port_mod_t *obj = of_port_mod_new(OF_VERSION_1_3);
        of_message_t msg;
        of_port_mod_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_port_mod_delete(obj);
    }

    {
        of_port_desc_stats_request_t *obj = of_port_desc_stats_request_new(OF_VERSION_1_3);
        of_message_t msg;
        of_port_desc_stats_request_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_port_desc_stats_request_delete(obj);
    }

    {
        of_port_desc_stats_reply_t *obj = of_port_desc_stats_reply_new(OF_VERSION_1_3);
        of_message_t msg;
        of_port_desc_stats_reply_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_port_desc_stats_reply_delete(obj);
    }

    {
        of_packet_out_t *obj = of_packet_out_new(OF_VERSION_1_3);
        of_message_t msg;
        of_packet_out_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_packet_out_delete(obj);
    }

    {
        of_packet_in_t *obj = of_packet_in_new(OF_VERSION_1_3);
        of_message_t msg;
        of_packet_in_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_packet_in_delete(obj);
    }

    {
        of_meter_stats_request_t *obj = of_meter_stats_request_new(OF_VERSION_1_3);
        of_message_t msg;
        of_meter_stats_request_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_meter_stats_request_delete(obj);
    }

    {
        of_meter_stats_reply_t *obj = of_meter_stats_reply_new(OF_VERSION_1_3);
        of_message_t msg;
        of_meter_stats_reply_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_meter_stats_reply_delete(obj);
    }

    {
        of_meter_mod_failed_error_msg_t *obj = of_meter_mod_failed_error_msg_new(OF_VERSION_1_3);
        of_message_t msg;
        of_meter_mod_failed_error_msg_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_meter_mod_failed_error_msg_delete(obj);
    }

    {
        of_meter_mod_t *obj = of_meter_mod_new(OF_VERSION_1_3);
        of_message_t msg;
        of_meter_mod_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_meter_mod_delete(obj);
    }

    {
        of_meter_features_stats_request_t *obj = of_meter_features_stats_request_new(OF_VERSION_1_3);
        of_message_t msg;
        of_meter_features_stats_request_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_meter_features_stats_request_delete(obj);
    }

    {
        of_meter_features_stats_reply_t *obj = of_meter_features_stats_reply_new(OF_VERSION_1_3);
        of_message_t msg;
        of_meter_features_stats_reply_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_meter_features_stats_reply_delete(obj);
    }

    {
        of_meter_config_stats_request_t *obj = of_meter_config_stats_request_new(OF_VERSION_1_3);
        of_message_t msg;
        of_meter_config_stats_request_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_meter_config_stats_request_delete(obj);
    }

    {
        of_meter_config_stats_reply_t *obj = of_meter_config_stats_reply_new(OF_VERSION_1_3);
        of_message_t msg;
        of_meter_config_stats_reply_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_meter_config_stats_reply_delete(obj);
    }

    {
        of_hello_failed_error_msg_t *obj = of_hello_failed_error_msg_new(OF_VERSION_1_3);
        of_message_t msg;
        of_hello_failed_error_msg_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_hello_failed_error_msg_delete(obj);
    }

    {
        of_hello_t *obj = of_hello_new(OF_VERSION_1_3);
        of_message_t msg;
        of_hello_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_hello_delete(obj);
    }

    {
        of_group_stats_request_t *obj = of_group_stats_request_new(OF_VERSION_1_3);
        of_message_t msg;
        of_group_stats_request_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_group_stats_request_delete(obj);
    }

    {
        of_group_stats_reply_t *obj = of_group_stats_reply_new(OF_VERSION_1_3);
        of_message_t msg;
        of_group_stats_reply_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_group_stats_reply_delete(obj);
    }

    {
        of_group_mod_failed_error_msg_t *obj = of_group_mod_failed_error_msg_new(OF_VERSION_1_3);
        of_message_t msg;
        of_group_mod_failed_error_msg_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_group_mod_failed_error_msg_delete(obj);
    }

    {
        of_group_mod_t *obj = of_group_mod_new(OF_VERSION_1_3);
        of_message_t msg;
        of_group_mod_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_group_mod_delete(obj);
    }

    {
        of_group_features_stats_request_t *obj = of_group_features_stats_request_new(OF_VERSION_1_3);
        of_message_t msg;
        of_group_features_stats_request_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_group_features_stats_request_delete(obj);
    }

    {
        of_group_features_stats_reply_t *obj = of_group_features_stats_reply_new(OF_VERSION_1_3);
        of_message_t msg;
        of_group_features_stats_reply_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_group_features_stats_reply_delete(obj);
    }

    {
        of_group_desc_stats_request_t *obj = of_group_desc_stats_request_new(OF_VERSION_1_3);
        of_message_t msg;
        of_group_desc_stats_request_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_group_desc_stats_request_delete(obj);
    }

    {
        of_group_desc_stats_reply_t *obj = of_group_desc_stats_reply_new(OF_VERSION_1_3);
        of_message_t msg;
        of_group_desc_stats_reply_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_group_desc_stats_reply_delete(obj);
    }

    {
        of_get_config_request_t *obj = of_get_config_request_new(OF_VERSION_1_3);
        of_message_t msg;
        of_get_config_request_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_get_config_request_delete(obj);
    }

    {
        of_get_config_reply_t *obj = of_get_config_reply_new(OF_VERSION_1_3);
        of_message_t msg;
        of_get_config_reply_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_get_config_reply_delete(obj);
    }

    {
        of_flow_stats_request_t *obj = of_flow_stats_request_new(OF_VERSION_1_3);
        of_message_t msg;
        of_flow_stats_request_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_flow_stats_request_delete(obj);
    }

    {
        of_flow_stats_reply_t *obj = of_flow_stats_reply_new(OF_VERSION_1_3);
        of_message_t msg;
        of_flow_stats_reply_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_flow_stats_reply_delete(obj);
    }

    {
        of_flow_removed_t *obj = of_flow_removed_new(OF_VERSION_1_3);
        of_message_t msg;
        of_flow_removed_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_flow_removed_delete(obj);
    }

    {
        of_flow_modify_strict_t *obj = of_flow_modify_strict_new(OF_VERSION_1_3);
        of_message_t msg;
        of_flow_modify_strict_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_flow_modify_strict_delete(obj);
    }

    {
        of_flow_modify_t *obj = of_flow_modify_new(OF_VERSION_1_3);
        of_message_t msg;
        of_flow_modify_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_flow_modify_delete(obj);
    }

    {
        of_flow_mod_failed_error_msg_t *obj = of_flow_mod_failed_error_msg_new(OF_VERSION_1_3);
        of_message_t msg;
        of_flow_mod_failed_error_msg_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_flow_mod_failed_error_msg_delete(obj);
    }

    {
        of_flow_delete_strict_t *obj = of_flow_delete_strict_new(OF_VERSION_1_3);
        of_message_t msg;
        of_flow_delete_strict_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_flow_delete_strict_delete(obj);
    }

    {
        of_flow_delete_t *obj = of_flow_delete_new(OF_VERSION_1_3);
        of_message_t msg;
        of_flow_delete_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_flow_delete_delete(obj);
    }

    {
        of_flow_add_t *obj = of_flow_add_new(OF_VERSION_1_3);
        of_message_t msg;
        of_flow_add_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_flow_add_delete(obj);
    }

    {
        of_features_request_t *obj = of_features_request_new(OF_VERSION_1_3);
        of_message_t msg;
        of_features_request_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_features_request_delete(obj);
    }

    {
        of_features_reply_t *obj = of_features_reply_new(OF_VERSION_1_3);
        of_message_t msg;
        of_features_reply_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_features_reply_delete(obj);
    }

    {
        of_experimenter_error_msg_t *obj = of_experimenter_error_msg_new(OF_VERSION_1_3);
        of_message_t msg;
        of_experimenter_error_msg_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_experimenter_error_msg_delete(obj);
    }

    {
        of_experimenter_t *obj = of_experimenter_new(OF_VERSION_1_3);
        of_message_t msg;
        of_experimenter_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_experimenter_delete(obj);
    }

    {
        of_echo_request_t *obj = of_echo_request_new(OF_VERSION_1_3);
        of_message_t msg;
        of_echo_request_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_echo_request_delete(obj);
    }

    {
        of_echo_reply_t *obj = of_echo_reply_new(OF_VERSION_1_3);
        of_message_t msg;
        of_echo_reply_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_echo_reply_delete(obj);
    }

    {
        of_desc_stats_request_t *obj = of_desc_stats_request_new(OF_VERSION_1_3);
        of_message_t msg;
        of_desc_stats_request_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_desc_stats_request_delete(obj);
    }

    {
        of_desc_stats_reply_t *obj = of_desc_stats_reply_new(OF_VERSION_1_3);
        of_message_t msg;
        of_desc_stats_reply_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_desc_stats_reply_delete(obj);
    }

    {
        of_bsn_virtual_port_remove_request_t *obj = of_bsn_virtual_port_remove_request_new(OF_VERSION_1_3);
        of_message_t msg;
        of_bsn_virtual_port_remove_request_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_virtual_port_remove_request_delete(obj);
    }

    {
        of_bsn_virtual_port_remove_reply_t *obj = of_bsn_virtual_port_remove_reply_new(OF_VERSION_1_3);
        of_message_t msg;
        of_bsn_virtual_port_remove_reply_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_virtual_port_remove_reply_delete(obj);
    }

    {
        of_bsn_virtual_port_create_request_t *obj = of_bsn_virtual_port_create_request_new(OF_VERSION_1_3);
        of_message_t msg;
        of_bsn_virtual_port_create_request_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_virtual_port_create_request_delete(obj);
    }

    {
        of_bsn_virtual_port_create_reply_t *obj = of_bsn_virtual_port_create_reply_new(OF_VERSION_1_3);
        of_message_t msg;
        of_bsn_virtual_port_create_reply_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_virtual_port_create_reply_delete(obj);
    }

    {
        of_bsn_time_request_t *obj = of_bsn_time_request_new(OF_VERSION_1_3);
        of_message_t msg;
        of_bsn_time_request_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_time_request_delete(obj);
    }

    {
        of_bsn_time_reply_t *obj = of_bsn_time_reply_new(OF_VERSION_1_3);
        of_message_t msg;
        of_bsn_time_reply_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_time_reply_delete(obj);
    }

    {
        of_bsn_set_pktin_suppression_request_t *obj = of_bsn_set_pktin_suppression_request_new(OF_VERSION_1_3);
        of_message_t msg;
        of_bsn_set_pktin_suppression_request_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_set_pktin_suppression_request_delete(obj);
    }

    {
        of_bsn_set_pktin_suppression_reply_t *obj = of_bsn_set_pktin_suppression_reply_new(OF_VERSION_1_3);
        of_message_t msg;
        of_bsn_set_pktin_suppression_reply_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_set_pktin_suppression_reply_delete(obj);
    }

    {
        of_bsn_set_mirroring_t *obj = of_bsn_set_mirroring_new(OF_VERSION_1_3);
        of_message_t msg;
        of_bsn_set_mirroring_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_set_mirroring_delete(obj);
    }

    {
        of_bsn_set_lacp_request_t *obj = of_bsn_set_lacp_request_new(OF_VERSION_1_3);
        of_message_t msg;
        of_bsn_set_lacp_request_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_set_lacp_request_delete(obj);
    }

    {
        of_bsn_set_lacp_reply_t *obj = of_bsn_set_lacp_reply_new(OF_VERSION_1_3);
        of_message_t msg;
        of_bsn_set_lacp_reply_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_set_lacp_reply_delete(obj);
    }

    {
        of_bsn_pdu_tx_request_t *obj = of_bsn_pdu_tx_request_new(OF_VERSION_1_3);
        of_message_t msg;
        of_bsn_pdu_tx_request_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_pdu_tx_request_delete(obj);
    }

    {
        of_bsn_pdu_tx_reply_t *obj = of_bsn_pdu_tx_reply_new(OF_VERSION_1_3);
        of_message_t msg;
        of_bsn_pdu_tx_reply_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_pdu_tx_reply_delete(obj);
    }

    {
        of_bsn_pdu_rx_timeout_t *obj = of_bsn_pdu_rx_timeout_new(OF_VERSION_1_3);
        of_message_t msg;
        of_bsn_pdu_rx_timeout_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_pdu_rx_timeout_delete(obj);
    }

    {
        of_bsn_pdu_rx_request_t *obj = of_bsn_pdu_rx_request_new(OF_VERSION_1_3);
        of_message_t msg;
        of_bsn_pdu_rx_request_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_pdu_rx_request_delete(obj);
    }

    {
        of_bsn_pdu_rx_reply_t *obj = of_bsn_pdu_rx_reply_new(OF_VERSION_1_3);
        of_message_t msg;
        of_bsn_pdu_rx_reply_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_pdu_rx_reply_delete(obj);
    }

    {
        of_bsn_lacp_stats_request_t *obj = of_bsn_lacp_stats_request_new(OF_VERSION_1_3);
        of_message_t msg;
        of_bsn_lacp_stats_request_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_lacp_stats_request_delete(obj);
    }

    {
        of_bsn_lacp_stats_reply_t *obj = of_bsn_lacp_stats_reply_new(OF_VERSION_1_3);
        of_message_t msg;
        of_bsn_lacp_stats_reply_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_lacp_stats_reply_delete(obj);
    }

    {
        of_bsn_lacp_convergence_notif_t *obj = of_bsn_lacp_convergence_notif_new(OF_VERSION_1_3);
        of_message_t msg;
        of_bsn_lacp_convergence_notif_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_lacp_convergence_notif_delete(obj);
    }

    {
        of_bsn_get_mirroring_request_t *obj = of_bsn_get_mirroring_request_new(OF_VERSION_1_3);
        of_message_t msg;
        of_bsn_get_mirroring_request_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_get_mirroring_request_delete(obj);
    }

    {
        of_bsn_get_mirroring_reply_t *obj = of_bsn_get_mirroring_reply_new(OF_VERSION_1_3);
        of_message_t msg;
        of_bsn_get_mirroring_reply_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_get_mirroring_reply_delete(obj);
    }

    {
        of_bsn_get_interfaces_request_t *obj = of_bsn_get_interfaces_request_new(OF_VERSION_1_3);
        of_message_t msg;
        of_bsn_get_interfaces_request_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_get_interfaces_request_delete(obj);
    }

    {
        of_bsn_get_interfaces_reply_t *obj = of_bsn_get_interfaces_reply_new(OF_VERSION_1_3);
        of_message_t msg;
        of_bsn_get_interfaces_reply_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_get_interfaces_reply_delete(obj);
    }

    {
        of_bsn_flow_idle_enable_set_request_t *obj = of_bsn_flow_idle_enable_set_request_new(OF_VERSION_1_3);
        of_message_t msg;
        of_bsn_flow_idle_enable_set_request_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_flow_idle_enable_set_request_delete(obj);
    }

    {
        of_bsn_flow_idle_enable_set_reply_t *obj = of_bsn_flow_idle_enable_set_reply_new(OF_VERSION_1_3);
        of_message_t msg;
        of_bsn_flow_idle_enable_set_reply_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_flow_idle_enable_set_reply_delete(obj);
    }

    {
        of_bsn_flow_idle_enable_get_request_t *obj = of_bsn_flow_idle_enable_get_request_new(OF_VERSION_1_3);
        of_message_t msg;
        of_bsn_flow_idle_enable_get_request_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_flow_idle_enable_get_request_delete(obj);
    }

    {
        of_bsn_flow_idle_enable_get_reply_t *obj = of_bsn_flow_idle_enable_get_reply_new(OF_VERSION_1_3);
        of_message_t msg;
        of_bsn_flow_idle_enable_get_reply_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_flow_idle_enable_get_reply_delete(obj);
    }

    {
        of_bsn_flow_idle_t *obj = of_bsn_flow_idle_new(OF_VERSION_1_3);
        of_message_t msg;
        of_bsn_flow_idle_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_flow_idle_delete(obj);
    }

    {
        of_bsn_bw_enable_set_request_t *obj = of_bsn_bw_enable_set_request_new(OF_VERSION_1_3);
        of_message_t msg;
        of_bsn_bw_enable_set_request_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_bw_enable_set_request_delete(obj);
    }

    {
        of_bsn_bw_enable_set_reply_t *obj = of_bsn_bw_enable_set_reply_new(OF_VERSION_1_3);
        of_message_t msg;
        of_bsn_bw_enable_set_reply_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_bw_enable_set_reply_delete(obj);
    }

    {
        of_bsn_bw_enable_get_request_t *obj = of_bsn_bw_enable_get_request_new(OF_VERSION_1_3);
        of_message_t msg;
        of_bsn_bw_enable_get_request_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_bw_enable_get_request_delete(obj);
    }

    {
        of_bsn_bw_enable_get_reply_t *obj = of_bsn_bw_enable_get_reply_new(OF_VERSION_1_3);
        of_message_t msg;
        of_bsn_bw_enable_get_reply_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_bw_enable_get_reply_delete(obj);
    }

    {
        of_bsn_bw_clear_data_request_t *obj = of_bsn_bw_clear_data_request_new(OF_VERSION_1_3);
        of_message_t msg;
        of_bsn_bw_clear_data_request_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_bw_clear_data_request_delete(obj);
    }

    {
        of_bsn_bw_clear_data_reply_t *obj = of_bsn_bw_clear_data_reply_new(OF_VERSION_1_3);
        of_message_t msg;
        of_bsn_bw_clear_data_reply_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bsn_bw_clear_data_reply_delete(obj);
    }

    {
        of_barrier_request_t *obj = of_barrier_request_new(OF_VERSION_1_3);
        of_message_t msg;
        of_barrier_request_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_barrier_request_delete(obj);
    }

    {
        of_barrier_reply_t *obj = of_barrier_reply_new(OF_VERSION_1_3);
        of_message_t msg;
        of_barrier_reply_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_barrier_reply_delete(obj);
    }

    {
        of_bad_request_error_msg_t *obj = of_bad_request_error_msg_new(OF_VERSION_1_3);
        of_message_t msg;
        of_bad_request_error_msg_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bad_request_error_msg_delete(obj);
    }

    {
        of_bad_match_error_msg_t *obj = of_bad_match_error_msg_new(OF_VERSION_1_3);
        of_message_t msg;
        of_bad_match_error_msg_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bad_match_error_msg_delete(obj);
    }

    {
        of_bad_instruction_error_msg_t *obj = of_bad_instruction_error_msg_new(OF_VERSION_1_3);
        of_message_t msg;
        of_bad_instruction_error_msg_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bad_instruction_error_msg_delete(obj);
    }

    {
        of_bad_action_error_msg_t *obj = of_bad_action_error_msg_new(OF_VERSION_1_3);
        of_message_t msg;
        of_bad_action_error_msg_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_bad_action_error_msg_delete(obj);
    }

    {
        of_async_set_t *obj = of_async_set_new(OF_VERSION_1_3);
        of_message_t msg;
        of_async_set_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_async_set_delete(obj);
    }

    {
        of_async_get_request_t *obj = of_async_get_request_new(OF_VERSION_1_3);
        of_message_t msg;
        of_async_get_request_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_async_get_request_delete(obj);
    }

    {
        of_async_get_reply_t *obj = of_async_get_reply_new(OF_VERSION_1_3);
        of_message_t msg;
        of_async_get_reply_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_async_get_reply_delete(obj);
    }

    {
        of_aggregate_stats_request_t *obj = of_aggregate_stats_request_new(OF_VERSION_1_3);
        of_message_t msg;
        of_aggregate_stats_request_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_aggregate_stats_request_delete(obj);
    }

    {
        of_aggregate_stats_reply_t *obj = of_aggregate_stats_reply_new(OF_VERSION_1_3);
        of_message_t msg;
        of_aggregate_stats_reply_OF_VERSION_1_3_populate(obj, 1);
        msg = OF_OBJECT_TO_MESSAGE(obj);
        TEST_ASSERT(of_validate_message(msg, of_message_length_get(msg)) == 0);
        of_aggregate_stats_reply_delete(obj);
    }


    return TEST_PASS;
}

int
run_validator_tests(void)
{
    RUN_TEST(validate_fixed_length);
    RUN_TEST(validate_fixed_length_list);
    RUN_TEST(validate_tlv16_list);
    RUN_TEST(validate_all);

    return TEST_PASS;
}
