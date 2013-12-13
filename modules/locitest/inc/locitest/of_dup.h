/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */

/*
 * Duplication function header file
 *
 * AUTOMATICALLY GENERATED FILE.  Edits will be lost on regen.
 */

#if !defined(_OF_DUP_H_)
#define _OF_DUP_H_

#include <loci/loci.h>

extern of_aggregate_stats_reply_t *
    of_aggregate_stats_reply_dup(
        of_aggregate_stats_reply_t *src);

extern of_aggregate_stats_request_t *
    of_aggregate_stats_request_dup(
        of_aggregate_stats_request_t *src);

extern of_async_get_reply_t *
    of_async_get_reply_dup(
        of_async_get_reply_t *src);

extern of_async_get_request_t *
    of_async_get_request_dup(
        of_async_get_request_t *src);

extern of_async_set_t *
    of_async_set_dup(
        of_async_set_t *src);

extern of_bad_action_error_msg_t *
    of_bad_action_error_msg_dup(
        of_bad_action_error_msg_t *src);

extern of_bad_instruction_error_msg_t *
    of_bad_instruction_error_msg_dup(
        of_bad_instruction_error_msg_t *src);

extern of_bad_match_error_msg_t *
    of_bad_match_error_msg_dup(
        of_bad_match_error_msg_t *src);

extern of_bad_request_error_msg_t *
    of_bad_request_error_msg_dup(
        of_bad_request_error_msg_t *src);

extern of_barrier_reply_t *
    of_barrier_reply_dup(
        of_barrier_reply_t *src);

extern of_barrier_request_t *
    of_barrier_request_dup(
        of_barrier_request_t *src);

extern of_bsn_bw_clear_data_reply_t *
    of_bsn_bw_clear_data_reply_dup(
        of_bsn_bw_clear_data_reply_t *src);

extern of_bsn_bw_clear_data_request_t *
    of_bsn_bw_clear_data_request_dup(
        of_bsn_bw_clear_data_request_t *src);

extern of_bsn_bw_enable_get_reply_t *
    of_bsn_bw_enable_get_reply_dup(
        of_bsn_bw_enable_get_reply_t *src);

extern of_bsn_bw_enable_get_request_t *
    of_bsn_bw_enable_get_request_dup(
        of_bsn_bw_enable_get_request_t *src);

extern of_bsn_bw_enable_set_reply_t *
    of_bsn_bw_enable_set_reply_dup(
        of_bsn_bw_enable_set_reply_t *src);

extern of_bsn_bw_enable_set_request_t *
    of_bsn_bw_enable_set_request_dup(
        of_bsn_bw_enable_set_request_t *src);

extern of_bsn_flow_idle_t *
    of_bsn_flow_idle_dup(
        of_bsn_flow_idle_t *src);

extern of_bsn_flow_idle_enable_get_reply_t *
    of_bsn_flow_idle_enable_get_reply_dup(
        of_bsn_flow_idle_enable_get_reply_t *src);

extern of_bsn_flow_idle_enable_get_request_t *
    of_bsn_flow_idle_enable_get_request_dup(
        of_bsn_flow_idle_enable_get_request_t *src);

extern of_bsn_flow_idle_enable_set_reply_t *
    of_bsn_flow_idle_enable_set_reply_dup(
        of_bsn_flow_idle_enable_set_reply_t *src);

extern of_bsn_flow_idle_enable_set_request_t *
    of_bsn_flow_idle_enable_set_request_dup(
        of_bsn_flow_idle_enable_set_request_t *src);

extern of_bsn_get_interfaces_reply_t *
    of_bsn_get_interfaces_reply_dup(
        of_bsn_get_interfaces_reply_t *src);

extern of_bsn_get_interfaces_request_t *
    of_bsn_get_interfaces_request_dup(
        of_bsn_get_interfaces_request_t *src);

extern of_bsn_get_ip_mask_reply_t *
    of_bsn_get_ip_mask_reply_dup(
        of_bsn_get_ip_mask_reply_t *src);

extern of_bsn_get_ip_mask_request_t *
    of_bsn_get_ip_mask_request_dup(
        of_bsn_get_ip_mask_request_t *src);

extern of_bsn_get_l2_table_reply_t *
    of_bsn_get_l2_table_reply_dup(
        of_bsn_get_l2_table_reply_t *src);

extern of_bsn_get_l2_table_request_t *
    of_bsn_get_l2_table_request_dup(
        of_bsn_get_l2_table_request_t *src);

extern of_bsn_get_mirroring_reply_t *
    of_bsn_get_mirroring_reply_dup(
        of_bsn_get_mirroring_reply_t *src);

extern of_bsn_get_mirroring_request_t *
    of_bsn_get_mirroring_request_dup(
        of_bsn_get_mirroring_request_t *src);

extern of_bsn_get_switch_pipeline_reply_t *
    of_bsn_get_switch_pipeline_reply_dup(
        of_bsn_get_switch_pipeline_reply_t *src);

extern of_bsn_get_switch_pipeline_request_t *
    of_bsn_get_switch_pipeline_request_dup(
        of_bsn_get_switch_pipeline_request_t *src);

extern of_bsn_header_t *
    of_bsn_header_dup(
        of_bsn_header_t *src);

extern of_bsn_hybrid_get_reply_t *
    of_bsn_hybrid_get_reply_dup(
        of_bsn_hybrid_get_reply_t *src);

extern of_bsn_hybrid_get_request_t *
    of_bsn_hybrid_get_request_dup(
        of_bsn_hybrid_get_request_t *src);

extern of_bsn_lacp_convergence_notif_t *
    of_bsn_lacp_convergence_notif_dup(
        of_bsn_lacp_convergence_notif_t *src);

extern of_bsn_lacp_stats_reply_t *
    of_bsn_lacp_stats_reply_dup(
        of_bsn_lacp_stats_reply_t *src);

extern of_bsn_lacp_stats_request_t *
    of_bsn_lacp_stats_request_dup(
        of_bsn_lacp_stats_request_t *src);

extern of_bsn_pdu_rx_reply_t *
    of_bsn_pdu_rx_reply_dup(
        of_bsn_pdu_rx_reply_t *src);

extern of_bsn_pdu_rx_request_t *
    of_bsn_pdu_rx_request_dup(
        of_bsn_pdu_rx_request_t *src);

extern of_bsn_pdu_rx_timeout_t *
    of_bsn_pdu_rx_timeout_dup(
        of_bsn_pdu_rx_timeout_t *src);

extern of_bsn_pdu_tx_reply_t *
    of_bsn_pdu_tx_reply_dup(
        of_bsn_pdu_tx_reply_t *src);

extern of_bsn_pdu_tx_request_t *
    of_bsn_pdu_tx_request_dup(
        of_bsn_pdu_tx_request_t *src);

extern of_bsn_port_counter_stats_reply_t *
    of_bsn_port_counter_stats_reply_dup(
        of_bsn_port_counter_stats_reply_t *src);

extern of_bsn_port_counter_stats_request_t *
    of_bsn_port_counter_stats_request_dup(
        of_bsn_port_counter_stats_request_t *src);

extern of_bsn_set_ip_mask_t *
    of_bsn_set_ip_mask_dup(
        of_bsn_set_ip_mask_t *src);

extern of_bsn_set_l2_table_reply_t *
    of_bsn_set_l2_table_reply_dup(
        of_bsn_set_l2_table_reply_t *src);

extern of_bsn_set_l2_table_request_t *
    of_bsn_set_l2_table_request_dup(
        of_bsn_set_l2_table_request_t *src);

extern of_bsn_set_lacp_reply_t *
    of_bsn_set_lacp_reply_dup(
        of_bsn_set_lacp_reply_t *src);

extern of_bsn_set_lacp_request_t *
    of_bsn_set_lacp_request_dup(
        of_bsn_set_lacp_request_t *src);

extern of_bsn_set_mirroring_t *
    of_bsn_set_mirroring_dup(
        of_bsn_set_mirroring_t *src);

extern of_bsn_set_pktin_suppression_reply_t *
    of_bsn_set_pktin_suppression_reply_dup(
        of_bsn_set_pktin_suppression_reply_t *src);

extern of_bsn_set_pktin_suppression_request_t *
    of_bsn_set_pktin_suppression_request_dup(
        of_bsn_set_pktin_suppression_request_t *src);

extern of_bsn_set_switch_pipeline_reply_t *
    of_bsn_set_switch_pipeline_reply_dup(
        of_bsn_set_switch_pipeline_reply_t *src);

extern of_bsn_set_switch_pipeline_request_t *
    of_bsn_set_switch_pipeline_request_dup(
        of_bsn_set_switch_pipeline_request_t *src);

extern of_bsn_shell_command_t *
    of_bsn_shell_command_dup(
        of_bsn_shell_command_t *src);

extern of_bsn_shell_output_t *
    of_bsn_shell_output_dup(
        of_bsn_shell_output_t *src);

extern of_bsn_shell_status_t *
    of_bsn_shell_status_dup(
        of_bsn_shell_status_t *src);

extern of_bsn_stats_reply_t *
    of_bsn_stats_reply_dup(
        of_bsn_stats_reply_t *src);

extern of_bsn_stats_request_t *
    of_bsn_stats_request_dup(
        of_bsn_stats_request_t *src);

extern of_bsn_switch_pipeline_stats_reply_t *
    of_bsn_switch_pipeline_stats_reply_dup(
        of_bsn_switch_pipeline_stats_reply_t *src);

extern of_bsn_switch_pipeline_stats_request_t *
    of_bsn_switch_pipeline_stats_request_dup(
        of_bsn_switch_pipeline_stats_request_t *src);

extern of_bsn_time_reply_t *
    of_bsn_time_reply_dup(
        of_bsn_time_reply_t *src);

extern of_bsn_time_request_t *
    of_bsn_time_request_dup(
        of_bsn_time_request_t *src);

extern of_bsn_virtual_port_create_reply_t *
    of_bsn_virtual_port_create_reply_dup(
        of_bsn_virtual_port_create_reply_t *src);

extern of_bsn_virtual_port_create_request_t *
    of_bsn_virtual_port_create_request_dup(
        of_bsn_virtual_port_create_request_t *src);

extern of_bsn_virtual_port_remove_reply_t *
    of_bsn_virtual_port_remove_reply_dup(
        of_bsn_virtual_port_remove_reply_t *src);

extern of_bsn_virtual_port_remove_request_t *
    of_bsn_virtual_port_remove_request_dup(
        of_bsn_virtual_port_remove_request_t *src);

extern of_bsn_vlan_counter_stats_reply_t *
    of_bsn_vlan_counter_stats_reply_dup(
        of_bsn_vlan_counter_stats_reply_t *src);

extern of_bsn_vlan_counter_stats_request_t *
    of_bsn_vlan_counter_stats_request_dup(
        of_bsn_vlan_counter_stats_request_t *src);

extern of_desc_stats_reply_t *
    of_desc_stats_reply_dup(
        of_desc_stats_reply_t *src);

extern of_desc_stats_request_t *
    of_desc_stats_request_dup(
        of_desc_stats_request_t *src);

extern of_echo_reply_t *
    of_echo_reply_dup(
        of_echo_reply_t *src);

extern of_echo_request_t *
    of_echo_request_dup(
        of_echo_request_t *src);

extern of_error_msg_t *
    of_error_msg_dup(
        of_error_msg_t *src);

extern of_experimenter_t *
    of_experimenter_dup(
        of_experimenter_t *src);

extern of_experimenter_error_msg_t *
    of_experimenter_error_msg_dup(
        of_experimenter_error_msg_t *src);

extern of_experimenter_stats_reply_t *
    of_experimenter_stats_reply_dup(
        of_experimenter_stats_reply_t *src);

extern of_experimenter_stats_request_t *
    of_experimenter_stats_request_dup(
        of_experimenter_stats_request_t *src);

extern of_features_reply_t *
    of_features_reply_dup(
        of_features_reply_t *src);

extern of_features_request_t *
    of_features_request_dup(
        of_features_request_t *src);

extern of_flow_add_t *
    of_flow_add_dup(
        of_flow_add_t *src);

extern of_flow_delete_t *
    of_flow_delete_dup(
        of_flow_delete_t *src);

extern of_flow_delete_strict_t *
    of_flow_delete_strict_dup(
        of_flow_delete_strict_t *src);

extern of_flow_mod_t *
    of_flow_mod_dup(
        of_flow_mod_t *src);

extern of_flow_mod_failed_error_msg_t *
    of_flow_mod_failed_error_msg_dup(
        of_flow_mod_failed_error_msg_t *src);

extern of_flow_modify_t *
    of_flow_modify_dup(
        of_flow_modify_t *src);

extern of_flow_modify_strict_t *
    of_flow_modify_strict_dup(
        of_flow_modify_strict_t *src);

extern of_flow_removed_t *
    of_flow_removed_dup(
        of_flow_removed_t *src);

extern of_flow_stats_reply_t *
    of_flow_stats_reply_dup(
        of_flow_stats_reply_t *src);

extern of_flow_stats_request_t *
    of_flow_stats_request_dup(
        of_flow_stats_request_t *src);

extern of_get_config_reply_t *
    of_get_config_reply_dup(
        of_get_config_reply_t *src);

extern of_get_config_request_t *
    of_get_config_request_dup(
        of_get_config_request_t *src);

extern of_group_add_t *
    of_group_add_dup(
        of_group_add_t *src);

extern of_group_delete_t *
    of_group_delete_dup(
        of_group_delete_t *src);

extern of_group_desc_stats_reply_t *
    of_group_desc_stats_reply_dup(
        of_group_desc_stats_reply_t *src);

extern of_group_desc_stats_request_t *
    of_group_desc_stats_request_dup(
        of_group_desc_stats_request_t *src);

extern of_group_features_stats_reply_t *
    of_group_features_stats_reply_dup(
        of_group_features_stats_reply_t *src);

extern of_group_features_stats_request_t *
    of_group_features_stats_request_dup(
        of_group_features_stats_request_t *src);

extern of_group_mod_t *
    of_group_mod_dup(
        of_group_mod_t *src);

extern of_group_mod_failed_error_msg_t *
    of_group_mod_failed_error_msg_dup(
        of_group_mod_failed_error_msg_t *src);

extern of_group_modify_t *
    of_group_modify_dup(
        of_group_modify_t *src);

extern of_group_stats_reply_t *
    of_group_stats_reply_dup(
        of_group_stats_reply_t *src);

extern of_group_stats_request_t *
    of_group_stats_request_dup(
        of_group_stats_request_t *src);

extern of_hello_t *
    of_hello_dup(
        of_hello_t *src);

extern of_hello_failed_error_msg_t *
    of_hello_failed_error_msg_dup(
        of_hello_failed_error_msg_t *src);

extern of_meter_config_stats_reply_t *
    of_meter_config_stats_reply_dup(
        of_meter_config_stats_reply_t *src);

extern of_meter_config_stats_request_t *
    of_meter_config_stats_request_dup(
        of_meter_config_stats_request_t *src);

extern of_meter_features_stats_reply_t *
    of_meter_features_stats_reply_dup(
        of_meter_features_stats_reply_t *src);

extern of_meter_features_stats_request_t *
    of_meter_features_stats_request_dup(
        of_meter_features_stats_request_t *src);

extern of_meter_mod_t *
    of_meter_mod_dup(
        of_meter_mod_t *src);

extern of_meter_mod_failed_error_msg_t *
    of_meter_mod_failed_error_msg_dup(
        of_meter_mod_failed_error_msg_t *src);

extern of_meter_stats_reply_t *
    of_meter_stats_reply_dup(
        of_meter_stats_reply_t *src);

extern of_meter_stats_request_t *
    of_meter_stats_request_dup(
        of_meter_stats_request_t *src);

extern of_nicira_controller_role_reply_t *
    of_nicira_controller_role_reply_dup(
        of_nicira_controller_role_reply_t *src);

extern of_nicira_controller_role_request_t *
    of_nicira_controller_role_request_dup(
        of_nicira_controller_role_request_t *src);

extern of_nicira_header_t *
    of_nicira_header_dup(
        of_nicira_header_t *src);

extern of_packet_in_t *
    of_packet_in_dup(
        of_packet_in_t *src);

extern of_packet_out_t *
    of_packet_out_dup(
        of_packet_out_t *src);

extern of_port_desc_stats_reply_t *
    of_port_desc_stats_reply_dup(
        of_port_desc_stats_reply_t *src);

extern of_port_desc_stats_request_t *
    of_port_desc_stats_request_dup(
        of_port_desc_stats_request_t *src);

extern of_port_mod_t *
    of_port_mod_dup(
        of_port_mod_t *src);

extern of_port_mod_failed_error_msg_t *
    of_port_mod_failed_error_msg_dup(
        of_port_mod_failed_error_msg_t *src);

extern of_port_stats_reply_t *
    of_port_stats_reply_dup(
        of_port_stats_reply_t *src);

extern of_port_stats_request_t *
    of_port_stats_request_dup(
        of_port_stats_request_t *src);

extern of_port_status_t *
    of_port_status_dup(
        of_port_status_t *src);

extern of_queue_get_config_reply_t *
    of_queue_get_config_reply_dup(
        of_queue_get_config_reply_t *src);

extern of_queue_get_config_request_t *
    of_queue_get_config_request_dup(
        of_queue_get_config_request_t *src);

extern of_queue_op_failed_error_msg_t *
    of_queue_op_failed_error_msg_dup(
        of_queue_op_failed_error_msg_t *src);

extern of_queue_stats_reply_t *
    of_queue_stats_reply_dup(
        of_queue_stats_reply_t *src);

extern of_queue_stats_request_t *
    of_queue_stats_request_dup(
        of_queue_stats_request_t *src);

extern of_role_reply_t *
    of_role_reply_dup(
        of_role_reply_t *src);

extern of_role_request_t *
    of_role_request_dup(
        of_role_request_t *src);

extern of_role_request_failed_error_msg_t *
    of_role_request_failed_error_msg_dup(
        of_role_request_failed_error_msg_t *src);

extern of_set_config_t *
    of_set_config_dup(
        of_set_config_t *src);

extern of_stats_reply_t *
    of_stats_reply_dup(
        of_stats_reply_t *src);

extern of_stats_request_t *
    of_stats_request_dup(
        of_stats_request_t *src);

extern of_switch_config_failed_error_msg_t *
    of_switch_config_failed_error_msg_dup(
        of_switch_config_failed_error_msg_t *src);

extern of_table_features_failed_error_msg_t *
    of_table_features_failed_error_msg_dup(
        of_table_features_failed_error_msg_t *src);

extern of_table_features_stats_reply_t *
    of_table_features_stats_reply_dup(
        of_table_features_stats_reply_t *src);

extern of_table_features_stats_request_t *
    of_table_features_stats_request_dup(
        of_table_features_stats_request_t *src);

extern of_table_mod_t *
    of_table_mod_dup(
        of_table_mod_t *src);

extern of_table_mod_failed_error_msg_t *
    of_table_mod_failed_error_msg_dup(
        of_table_mod_failed_error_msg_t *src);

extern of_table_stats_reply_t *
    of_table_stats_reply_dup(
        of_table_stats_reply_t *src);

extern of_table_stats_request_t *
    of_table_stats_request_dup(
        of_table_stats_request_t *src);

extern of_action_t *
    of_action_dup(
        of_action_t *src);

extern of_action_bsn_t *
    of_action_bsn_dup(
        of_action_bsn_t *src);

extern of_action_bsn_mirror_t *
    of_action_bsn_mirror_dup(
        of_action_bsn_mirror_t *src);

extern of_action_bsn_set_tunnel_dst_t *
    of_action_bsn_set_tunnel_dst_dup(
        of_action_bsn_set_tunnel_dst_t *src);

extern of_action_copy_ttl_in_t *
    of_action_copy_ttl_in_dup(
        of_action_copy_ttl_in_t *src);

extern of_action_copy_ttl_out_t *
    of_action_copy_ttl_out_dup(
        of_action_copy_ttl_out_t *src);

extern of_action_dec_mpls_ttl_t *
    of_action_dec_mpls_ttl_dup(
        of_action_dec_mpls_ttl_t *src);

extern of_action_dec_nw_ttl_t *
    of_action_dec_nw_ttl_dup(
        of_action_dec_nw_ttl_t *src);

extern of_action_enqueue_t *
    of_action_enqueue_dup(
        of_action_enqueue_t *src);

extern of_action_experimenter_t *
    of_action_experimenter_dup(
        of_action_experimenter_t *src);

extern of_action_group_t *
    of_action_group_dup(
        of_action_group_t *src);

extern of_action_header_t *
    of_action_header_dup(
        of_action_header_t *src);

extern of_action_id_t *
    of_action_id_dup(
        of_action_id_t *src);

extern of_action_id_bsn_t *
    of_action_id_bsn_dup(
        of_action_id_bsn_t *src);

extern of_action_id_bsn_mirror_t *
    of_action_id_bsn_mirror_dup(
        of_action_id_bsn_mirror_t *src);

extern of_action_id_bsn_set_tunnel_dst_t *
    of_action_id_bsn_set_tunnel_dst_dup(
        of_action_id_bsn_set_tunnel_dst_t *src);

extern of_action_id_copy_ttl_in_t *
    of_action_id_copy_ttl_in_dup(
        of_action_id_copy_ttl_in_t *src);

extern of_action_id_copy_ttl_out_t *
    of_action_id_copy_ttl_out_dup(
        of_action_id_copy_ttl_out_t *src);

extern of_action_id_dec_mpls_ttl_t *
    of_action_id_dec_mpls_ttl_dup(
        of_action_id_dec_mpls_ttl_t *src);

extern of_action_id_dec_nw_ttl_t *
    of_action_id_dec_nw_ttl_dup(
        of_action_id_dec_nw_ttl_t *src);

extern of_action_id_experimenter_t *
    of_action_id_experimenter_dup(
        of_action_id_experimenter_t *src);

extern of_action_id_group_t *
    of_action_id_group_dup(
        of_action_id_group_t *src);

extern of_action_id_header_t *
    of_action_id_header_dup(
        of_action_id_header_t *src);

extern of_action_id_nicira_t *
    of_action_id_nicira_dup(
        of_action_id_nicira_t *src);

extern of_action_id_nicira_dec_ttl_t *
    of_action_id_nicira_dec_ttl_dup(
        of_action_id_nicira_dec_ttl_t *src);

extern of_action_id_output_t *
    of_action_id_output_dup(
        of_action_id_output_t *src);

extern of_action_id_pop_mpls_t *
    of_action_id_pop_mpls_dup(
        of_action_id_pop_mpls_t *src);

extern of_action_id_pop_pbb_t *
    of_action_id_pop_pbb_dup(
        of_action_id_pop_pbb_t *src);

extern of_action_id_pop_vlan_t *
    of_action_id_pop_vlan_dup(
        of_action_id_pop_vlan_t *src);

extern of_action_id_push_mpls_t *
    of_action_id_push_mpls_dup(
        of_action_id_push_mpls_t *src);

extern of_action_id_push_pbb_t *
    of_action_id_push_pbb_dup(
        of_action_id_push_pbb_t *src);

extern of_action_id_push_vlan_t *
    of_action_id_push_vlan_dup(
        of_action_id_push_vlan_t *src);

extern of_action_id_set_field_t *
    of_action_id_set_field_dup(
        of_action_id_set_field_t *src);

extern of_action_id_set_mpls_ttl_t *
    of_action_id_set_mpls_ttl_dup(
        of_action_id_set_mpls_ttl_t *src);

extern of_action_id_set_nw_ttl_t *
    of_action_id_set_nw_ttl_dup(
        of_action_id_set_nw_ttl_t *src);

extern of_action_id_set_queue_t *
    of_action_id_set_queue_dup(
        of_action_id_set_queue_t *src);

extern of_action_nicira_t *
    of_action_nicira_dup(
        of_action_nicira_t *src);

extern of_action_nicira_dec_ttl_t *
    of_action_nicira_dec_ttl_dup(
        of_action_nicira_dec_ttl_t *src);

extern of_action_output_t *
    of_action_output_dup(
        of_action_output_t *src);

extern of_action_pop_mpls_t *
    of_action_pop_mpls_dup(
        of_action_pop_mpls_t *src);

extern of_action_pop_pbb_t *
    of_action_pop_pbb_dup(
        of_action_pop_pbb_t *src);

extern of_action_pop_vlan_t *
    of_action_pop_vlan_dup(
        of_action_pop_vlan_t *src);

extern of_action_push_mpls_t *
    of_action_push_mpls_dup(
        of_action_push_mpls_t *src);

extern of_action_push_pbb_t *
    of_action_push_pbb_dup(
        of_action_push_pbb_t *src);

extern of_action_push_vlan_t *
    of_action_push_vlan_dup(
        of_action_push_vlan_t *src);

extern of_action_set_dl_dst_t *
    of_action_set_dl_dst_dup(
        of_action_set_dl_dst_t *src);

extern of_action_set_dl_src_t *
    of_action_set_dl_src_dup(
        of_action_set_dl_src_t *src);

extern of_action_set_field_t *
    of_action_set_field_dup(
        of_action_set_field_t *src);

extern of_action_set_mpls_label_t *
    of_action_set_mpls_label_dup(
        of_action_set_mpls_label_t *src);

extern of_action_set_mpls_tc_t *
    of_action_set_mpls_tc_dup(
        of_action_set_mpls_tc_t *src);

extern of_action_set_mpls_ttl_t *
    of_action_set_mpls_ttl_dup(
        of_action_set_mpls_ttl_t *src);

extern of_action_set_nw_dst_t *
    of_action_set_nw_dst_dup(
        of_action_set_nw_dst_t *src);

extern of_action_set_nw_ecn_t *
    of_action_set_nw_ecn_dup(
        of_action_set_nw_ecn_t *src);

extern of_action_set_nw_src_t *
    of_action_set_nw_src_dup(
        of_action_set_nw_src_t *src);

extern of_action_set_nw_tos_t *
    of_action_set_nw_tos_dup(
        of_action_set_nw_tos_t *src);

extern of_action_set_nw_ttl_t *
    of_action_set_nw_ttl_dup(
        of_action_set_nw_ttl_t *src);

extern of_action_set_queue_t *
    of_action_set_queue_dup(
        of_action_set_queue_t *src);

extern of_action_set_tp_dst_t *
    of_action_set_tp_dst_dup(
        of_action_set_tp_dst_t *src);

extern of_action_set_tp_src_t *
    of_action_set_tp_src_dup(
        of_action_set_tp_src_t *src);

extern of_action_set_vlan_pcp_t *
    of_action_set_vlan_pcp_dup(
        of_action_set_vlan_pcp_t *src);

extern of_action_set_vlan_vid_t *
    of_action_set_vlan_vid_dup(
        of_action_set_vlan_vid_t *src);

extern of_action_strip_vlan_t *
    of_action_strip_vlan_dup(
        of_action_strip_vlan_t *src);

extern of_bsn_interface_t *
    of_bsn_interface_dup(
        of_bsn_interface_t *src);

extern of_bsn_lacp_stats_entry_t *
    of_bsn_lacp_stats_entry_dup(
        of_bsn_lacp_stats_entry_t *src);

extern of_bsn_port_counter_stats_entry_t *
    of_bsn_port_counter_stats_entry_dup(
        of_bsn_port_counter_stats_entry_t *src);

extern of_bsn_switch_pipeline_stats_entry_t *
    of_bsn_switch_pipeline_stats_entry_dup(
        of_bsn_switch_pipeline_stats_entry_t *src);

extern of_bsn_vlan_counter_stats_entry_t *
    of_bsn_vlan_counter_stats_entry_dup(
        of_bsn_vlan_counter_stats_entry_t *src);

extern of_bsn_vport_t *
    of_bsn_vport_dup(
        of_bsn_vport_t *src);

extern of_bsn_vport_header_t *
    of_bsn_vport_header_dup(
        of_bsn_vport_header_t *src);

extern of_bsn_vport_q_in_q_t *
    of_bsn_vport_q_in_q_dup(
        of_bsn_vport_q_in_q_t *src);

extern of_bucket_t *
    of_bucket_dup(
        of_bucket_t *src);

extern of_bucket_counter_t *
    of_bucket_counter_dup(
        of_bucket_counter_t *src);

extern of_experimenter_stats_header_t *
    of_experimenter_stats_header_dup(
        of_experimenter_stats_header_t *src);

extern of_flow_stats_entry_t *
    of_flow_stats_entry_dup(
        of_flow_stats_entry_t *src);

extern of_group_desc_stats_entry_t *
    of_group_desc_stats_entry_dup(
        of_group_desc_stats_entry_t *src);

extern of_group_stats_entry_t *
    of_group_stats_entry_dup(
        of_group_stats_entry_t *src);

extern of_header_t *
    of_header_dup(
        of_header_t *src);

extern of_hello_elem_t *
    of_hello_elem_dup(
        of_hello_elem_t *src);

extern of_hello_elem_header_t *
    of_hello_elem_header_dup(
        of_hello_elem_header_t *src);

extern of_hello_elem_versionbitmap_t *
    of_hello_elem_versionbitmap_dup(
        of_hello_elem_versionbitmap_t *src);

extern of_instruction_t *
    of_instruction_dup(
        of_instruction_t *src);

extern of_instruction_apply_actions_t *
    of_instruction_apply_actions_dup(
        of_instruction_apply_actions_t *src);

extern of_instruction_bsn_t *
    of_instruction_bsn_dup(
        of_instruction_bsn_t *src);

extern of_instruction_bsn_disable_src_mac_check_t *
    of_instruction_bsn_disable_src_mac_check_dup(
        of_instruction_bsn_disable_src_mac_check_t *src);

extern of_instruction_clear_actions_t *
    of_instruction_clear_actions_dup(
        of_instruction_clear_actions_t *src);

extern of_instruction_experimenter_t *
    of_instruction_experimenter_dup(
        of_instruction_experimenter_t *src);

extern of_instruction_goto_table_t *
    of_instruction_goto_table_dup(
        of_instruction_goto_table_t *src);

extern of_instruction_header_t *
    of_instruction_header_dup(
        of_instruction_header_t *src);

extern of_instruction_id_t *
    of_instruction_id_dup(
        of_instruction_id_t *src);

extern of_instruction_id_apply_actions_t *
    of_instruction_id_apply_actions_dup(
        of_instruction_id_apply_actions_t *src);

extern of_instruction_id_bsn_t *
    of_instruction_id_bsn_dup(
        of_instruction_id_bsn_t *src);

extern of_instruction_id_bsn_disable_src_mac_check_t *
    of_instruction_id_bsn_disable_src_mac_check_dup(
        of_instruction_id_bsn_disable_src_mac_check_t *src);

extern of_instruction_id_clear_actions_t *
    of_instruction_id_clear_actions_dup(
        of_instruction_id_clear_actions_t *src);

extern of_instruction_id_experimenter_t *
    of_instruction_id_experimenter_dup(
        of_instruction_id_experimenter_t *src);

extern of_instruction_id_goto_table_t *
    of_instruction_id_goto_table_dup(
        of_instruction_id_goto_table_t *src);

extern of_instruction_id_header_t *
    of_instruction_id_header_dup(
        of_instruction_id_header_t *src);

extern of_instruction_id_meter_t *
    of_instruction_id_meter_dup(
        of_instruction_id_meter_t *src);

extern of_instruction_id_write_actions_t *
    of_instruction_id_write_actions_dup(
        of_instruction_id_write_actions_t *src);

extern of_instruction_id_write_metadata_t *
    of_instruction_id_write_metadata_dup(
        of_instruction_id_write_metadata_t *src);

extern of_instruction_meter_t *
    of_instruction_meter_dup(
        of_instruction_meter_t *src);

extern of_instruction_write_actions_t *
    of_instruction_write_actions_dup(
        of_instruction_write_actions_t *src);

extern of_instruction_write_metadata_t *
    of_instruction_write_metadata_dup(
        of_instruction_write_metadata_t *src);

extern of_match_v1_t *
    of_match_v1_dup(
        of_match_v1_t *src);

extern of_match_v2_t *
    of_match_v2_dup(
        of_match_v2_t *src);

extern of_match_v3_t *
    of_match_v3_dup(
        of_match_v3_t *src);

extern of_meter_band_t *
    of_meter_band_dup(
        of_meter_band_t *src);

extern of_meter_band_drop_t *
    of_meter_band_drop_dup(
        of_meter_band_drop_t *src);

extern of_meter_band_dscp_remark_t *
    of_meter_band_dscp_remark_dup(
        of_meter_band_dscp_remark_t *src);

extern of_meter_band_experimenter_t *
    of_meter_band_experimenter_dup(
        of_meter_band_experimenter_t *src);

extern of_meter_band_header_t *
    of_meter_band_header_dup(
        of_meter_band_header_t *src);

extern of_meter_band_stats_t *
    of_meter_band_stats_dup(
        of_meter_band_stats_t *src);

extern of_meter_config_t *
    of_meter_config_dup(
        of_meter_config_t *src);

extern of_meter_features_t *
    of_meter_features_dup(
        of_meter_features_t *src);

extern of_meter_stats_t *
    of_meter_stats_dup(
        of_meter_stats_t *src);

extern of_oxm_t *
    of_oxm_dup(
        of_oxm_t *src);

extern of_oxm_arp_op_t *
    of_oxm_arp_op_dup(
        of_oxm_arp_op_t *src);

extern of_oxm_arp_op_masked_t *
    of_oxm_arp_op_masked_dup(
        of_oxm_arp_op_masked_t *src);

extern of_oxm_arp_sha_t *
    of_oxm_arp_sha_dup(
        of_oxm_arp_sha_t *src);

extern of_oxm_arp_sha_masked_t *
    of_oxm_arp_sha_masked_dup(
        of_oxm_arp_sha_masked_t *src);

extern of_oxm_arp_spa_t *
    of_oxm_arp_spa_dup(
        of_oxm_arp_spa_t *src);

extern of_oxm_arp_spa_masked_t *
    of_oxm_arp_spa_masked_dup(
        of_oxm_arp_spa_masked_t *src);

extern of_oxm_arp_tha_t *
    of_oxm_arp_tha_dup(
        of_oxm_arp_tha_t *src);

extern of_oxm_arp_tha_masked_t *
    of_oxm_arp_tha_masked_dup(
        of_oxm_arp_tha_masked_t *src);

extern of_oxm_arp_tpa_t *
    of_oxm_arp_tpa_dup(
        of_oxm_arp_tpa_t *src);

extern of_oxm_arp_tpa_masked_t *
    of_oxm_arp_tpa_masked_dup(
        of_oxm_arp_tpa_masked_t *src);

extern of_oxm_bsn_global_vrf_allowed_t *
    of_oxm_bsn_global_vrf_allowed_dup(
        of_oxm_bsn_global_vrf_allowed_t *src);

extern of_oxm_bsn_global_vrf_allowed_masked_t *
    of_oxm_bsn_global_vrf_allowed_masked_dup(
        of_oxm_bsn_global_vrf_allowed_masked_t *src);

extern of_oxm_bsn_in_ports_128_t *
    of_oxm_bsn_in_ports_128_dup(
        of_oxm_bsn_in_ports_128_t *src);

extern of_oxm_bsn_in_ports_128_masked_t *
    of_oxm_bsn_in_ports_128_masked_dup(
        of_oxm_bsn_in_ports_128_masked_t *src);

extern of_oxm_bsn_l3_dst_class_id_t *
    of_oxm_bsn_l3_dst_class_id_dup(
        of_oxm_bsn_l3_dst_class_id_t *src);

extern of_oxm_bsn_l3_dst_class_id_masked_t *
    of_oxm_bsn_l3_dst_class_id_masked_dup(
        of_oxm_bsn_l3_dst_class_id_masked_t *src);

extern of_oxm_bsn_l3_interface_class_id_t *
    of_oxm_bsn_l3_interface_class_id_dup(
        of_oxm_bsn_l3_interface_class_id_t *src);

extern of_oxm_bsn_l3_interface_class_id_masked_t *
    of_oxm_bsn_l3_interface_class_id_masked_dup(
        of_oxm_bsn_l3_interface_class_id_masked_t *src);

extern of_oxm_bsn_l3_src_class_id_t *
    of_oxm_bsn_l3_src_class_id_dup(
        of_oxm_bsn_l3_src_class_id_t *src);

extern of_oxm_bsn_l3_src_class_id_masked_t *
    of_oxm_bsn_l3_src_class_id_masked_dup(
        of_oxm_bsn_l3_src_class_id_masked_t *src);

extern of_oxm_bsn_lag_id_t *
    of_oxm_bsn_lag_id_dup(
        of_oxm_bsn_lag_id_t *src);

extern of_oxm_bsn_lag_id_masked_t *
    of_oxm_bsn_lag_id_masked_dup(
        of_oxm_bsn_lag_id_masked_t *src);

extern of_oxm_bsn_vrf_t *
    of_oxm_bsn_vrf_dup(
        of_oxm_bsn_vrf_t *src);

extern of_oxm_bsn_vrf_masked_t *
    of_oxm_bsn_vrf_masked_dup(
        of_oxm_bsn_vrf_masked_t *src);

extern of_oxm_eth_dst_t *
    of_oxm_eth_dst_dup(
        of_oxm_eth_dst_t *src);

extern of_oxm_eth_dst_masked_t *
    of_oxm_eth_dst_masked_dup(
        of_oxm_eth_dst_masked_t *src);

extern of_oxm_eth_src_t *
    of_oxm_eth_src_dup(
        of_oxm_eth_src_t *src);

extern of_oxm_eth_src_masked_t *
    of_oxm_eth_src_masked_dup(
        of_oxm_eth_src_masked_t *src);

extern of_oxm_eth_type_t *
    of_oxm_eth_type_dup(
        of_oxm_eth_type_t *src);

extern of_oxm_eth_type_masked_t *
    of_oxm_eth_type_masked_dup(
        of_oxm_eth_type_masked_t *src);

extern of_oxm_header_t *
    of_oxm_header_dup(
        of_oxm_header_t *src);

extern of_oxm_icmpv4_code_t *
    of_oxm_icmpv4_code_dup(
        of_oxm_icmpv4_code_t *src);

extern of_oxm_icmpv4_code_masked_t *
    of_oxm_icmpv4_code_masked_dup(
        of_oxm_icmpv4_code_masked_t *src);

extern of_oxm_icmpv4_type_t *
    of_oxm_icmpv4_type_dup(
        of_oxm_icmpv4_type_t *src);

extern of_oxm_icmpv4_type_masked_t *
    of_oxm_icmpv4_type_masked_dup(
        of_oxm_icmpv4_type_masked_t *src);

extern of_oxm_icmpv6_code_t *
    of_oxm_icmpv6_code_dup(
        of_oxm_icmpv6_code_t *src);

extern of_oxm_icmpv6_code_masked_t *
    of_oxm_icmpv6_code_masked_dup(
        of_oxm_icmpv6_code_masked_t *src);

extern of_oxm_icmpv6_type_t *
    of_oxm_icmpv6_type_dup(
        of_oxm_icmpv6_type_t *src);

extern of_oxm_icmpv6_type_masked_t *
    of_oxm_icmpv6_type_masked_dup(
        of_oxm_icmpv6_type_masked_t *src);

extern of_oxm_in_phy_port_t *
    of_oxm_in_phy_port_dup(
        of_oxm_in_phy_port_t *src);

extern of_oxm_in_phy_port_masked_t *
    of_oxm_in_phy_port_masked_dup(
        of_oxm_in_phy_port_masked_t *src);

extern of_oxm_in_port_t *
    of_oxm_in_port_dup(
        of_oxm_in_port_t *src);

extern of_oxm_in_port_masked_t *
    of_oxm_in_port_masked_dup(
        of_oxm_in_port_masked_t *src);

extern of_oxm_ip_dscp_t *
    of_oxm_ip_dscp_dup(
        of_oxm_ip_dscp_t *src);

extern of_oxm_ip_dscp_masked_t *
    of_oxm_ip_dscp_masked_dup(
        of_oxm_ip_dscp_masked_t *src);

extern of_oxm_ip_ecn_t *
    of_oxm_ip_ecn_dup(
        of_oxm_ip_ecn_t *src);

extern of_oxm_ip_ecn_masked_t *
    of_oxm_ip_ecn_masked_dup(
        of_oxm_ip_ecn_masked_t *src);

extern of_oxm_ip_proto_t *
    of_oxm_ip_proto_dup(
        of_oxm_ip_proto_t *src);

extern of_oxm_ip_proto_masked_t *
    of_oxm_ip_proto_masked_dup(
        of_oxm_ip_proto_masked_t *src);

extern of_oxm_ipv4_dst_t *
    of_oxm_ipv4_dst_dup(
        of_oxm_ipv4_dst_t *src);

extern of_oxm_ipv4_dst_masked_t *
    of_oxm_ipv4_dst_masked_dup(
        of_oxm_ipv4_dst_masked_t *src);

extern of_oxm_ipv4_src_t *
    of_oxm_ipv4_src_dup(
        of_oxm_ipv4_src_t *src);

extern of_oxm_ipv4_src_masked_t *
    of_oxm_ipv4_src_masked_dup(
        of_oxm_ipv4_src_masked_t *src);

extern of_oxm_ipv6_dst_t *
    of_oxm_ipv6_dst_dup(
        of_oxm_ipv6_dst_t *src);

extern of_oxm_ipv6_dst_masked_t *
    of_oxm_ipv6_dst_masked_dup(
        of_oxm_ipv6_dst_masked_t *src);

extern of_oxm_ipv6_flabel_t *
    of_oxm_ipv6_flabel_dup(
        of_oxm_ipv6_flabel_t *src);

extern of_oxm_ipv6_flabel_masked_t *
    of_oxm_ipv6_flabel_masked_dup(
        of_oxm_ipv6_flabel_masked_t *src);

extern of_oxm_ipv6_nd_sll_t *
    of_oxm_ipv6_nd_sll_dup(
        of_oxm_ipv6_nd_sll_t *src);

extern of_oxm_ipv6_nd_sll_masked_t *
    of_oxm_ipv6_nd_sll_masked_dup(
        of_oxm_ipv6_nd_sll_masked_t *src);

extern of_oxm_ipv6_nd_target_t *
    of_oxm_ipv6_nd_target_dup(
        of_oxm_ipv6_nd_target_t *src);

extern of_oxm_ipv6_nd_target_masked_t *
    of_oxm_ipv6_nd_target_masked_dup(
        of_oxm_ipv6_nd_target_masked_t *src);

extern of_oxm_ipv6_nd_tll_t *
    of_oxm_ipv6_nd_tll_dup(
        of_oxm_ipv6_nd_tll_t *src);

extern of_oxm_ipv6_nd_tll_masked_t *
    of_oxm_ipv6_nd_tll_masked_dup(
        of_oxm_ipv6_nd_tll_masked_t *src);

extern of_oxm_ipv6_src_t *
    of_oxm_ipv6_src_dup(
        of_oxm_ipv6_src_t *src);

extern of_oxm_ipv6_src_masked_t *
    of_oxm_ipv6_src_masked_dup(
        of_oxm_ipv6_src_masked_t *src);

extern of_oxm_metadata_t *
    of_oxm_metadata_dup(
        of_oxm_metadata_t *src);

extern of_oxm_metadata_masked_t *
    of_oxm_metadata_masked_dup(
        of_oxm_metadata_masked_t *src);

extern of_oxm_mpls_label_t *
    of_oxm_mpls_label_dup(
        of_oxm_mpls_label_t *src);

extern of_oxm_mpls_label_masked_t *
    of_oxm_mpls_label_masked_dup(
        of_oxm_mpls_label_masked_t *src);

extern of_oxm_mpls_tc_t *
    of_oxm_mpls_tc_dup(
        of_oxm_mpls_tc_t *src);

extern of_oxm_mpls_tc_masked_t *
    of_oxm_mpls_tc_masked_dup(
        of_oxm_mpls_tc_masked_t *src);

extern of_oxm_sctp_dst_t *
    of_oxm_sctp_dst_dup(
        of_oxm_sctp_dst_t *src);

extern of_oxm_sctp_dst_masked_t *
    of_oxm_sctp_dst_masked_dup(
        of_oxm_sctp_dst_masked_t *src);

extern of_oxm_sctp_src_t *
    of_oxm_sctp_src_dup(
        of_oxm_sctp_src_t *src);

extern of_oxm_sctp_src_masked_t *
    of_oxm_sctp_src_masked_dup(
        of_oxm_sctp_src_masked_t *src);

extern of_oxm_tcp_dst_t *
    of_oxm_tcp_dst_dup(
        of_oxm_tcp_dst_t *src);

extern of_oxm_tcp_dst_masked_t *
    of_oxm_tcp_dst_masked_dup(
        of_oxm_tcp_dst_masked_t *src);

extern of_oxm_tcp_src_t *
    of_oxm_tcp_src_dup(
        of_oxm_tcp_src_t *src);

extern of_oxm_tcp_src_masked_t *
    of_oxm_tcp_src_masked_dup(
        of_oxm_tcp_src_masked_t *src);

extern of_oxm_udp_dst_t *
    of_oxm_udp_dst_dup(
        of_oxm_udp_dst_t *src);

extern of_oxm_udp_dst_masked_t *
    of_oxm_udp_dst_masked_dup(
        of_oxm_udp_dst_masked_t *src);

extern of_oxm_udp_src_t *
    of_oxm_udp_src_dup(
        of_oxm_udp_src_t *src);

extern of_oxm_udp_src_masked_t *
    of_oxm_udp_src_masked_dup(
        of_oxm_udp_src_masked_t *src);

extern of_oxm_vlan_pcp_t *
    of_oxm_vlan_pcp_dup(
        of_oxm_vlan_pcp_t *src);

extern of_oxm_vlan_pcp_masked_t *
    of_oxm_vlan_pcp_masked_dup(
        of_oxm_vlan_pcp_masked_t *src);

extern of_oxm_vlan_vid_t *
    of_oxm_vlan_vid_dup(
        of_oxm_vlan_vid_t *src);

extern of_oxm_vlan_vid_masked_t *
    of_oxm_vlan_vid_masked_dup(
        of_oxm_vlan_vid_masked_t *src);

extern of_packet_queue_t *
    of_packet_queue_dup(
        of_packet_queue_t *src);

extern of_port_desc_t *
    of_port_desc_dup(
        of_port_desc_t *src);

extern of_port_stats_entry_t *
    of_port_stats_entry_dup(
        of_port_stats_entry_t *src);

extern of_queue_prop_t *
    of_queue_prop_dup(
        of_queue_prop_t *src);

extern of_queue_prop_experimenter_t *
    of_queue_prop_experimenter_dup(
        of_queue_prop_experimenter_t *src);

extern of_queue_prop_header_t *
    of_queue_prop_header_dup(
        of_queue_prop_header_t *src);

extern of_queue_prop_max_rate_t *
    of_queue_prop_max_rate_dup(
        of_queue_prop_max_rate_t *src);

extern of_queue_prop_min_rate_t *
    of_queue_prop_min_rate_dup(
        of_queue_prop_min_rate_t *src);

extern of_queue_stats_entry_t *
    of_queue_stats_entry_dup(
        of_queue_stats_entry_t *src);

extern of_table_feature_prop_t *
    of_table_feature_prop_dup(
        of_table_feature_prop_t *src);

extern of_table_feature_prop_apply_actions_t *
    of_table_feature_prop_apply_actions_dup(
        of_table_feature_prop_apply_actions_t *src);

extern of_table_feature_prop_apply_actions_miss_t *
    of_table_feature_prop_apply_actions_miss_dup(
        of_table_feature_prop_apply_actions_miss_t *src);

extern of_table_feature_prop_apply_setfield_t *
    of_table_feature_prop_apply_setfield_dup(
        of_table_feature_prop_apply_setfield_t *src);

extern of_table_feature_prop_apply_setfield_miss_t *
    of_table_feature_prop_apply_setfield_miss_dup(
        of_table_feature_prop_apply_setfield_miss_t *src);

extern of_table_feature_prop_experimenter_t *
    of_table_feature_prop_experimenter_dup(
        of_table_feature_prop_experimenter_t *src);

extern of_table_feature_prop_header_t *
    of_table_feature_prop_header_dup(
        of_table_feature_prop_header_t *src);

extern of_table_feature_prop_instructions_t *
    of_table_feature_prop_instructions_dup(
        of_table_feature_prop_instructions_t *src);

extern of_table_feature_prop_instructions_miss_t *
    of_table_feature_prop_instructions_miss_dup(
        of_table_feature_prop_instructions_miss_t *src);

extern of_table_feature_prop_match_t *
    of_table_feature_prop_match_dup(
        of_table_feature_prop_match_t *src);

extern of_table_feature_prop_next_tables_t *
    of_table_feature_prop_next_tables_dup(
        of_table_feature_prop_next_tables_t *src);

extern of_table_feature_prop_next_tables_miss_t *
    of_table_feature_prop_next_tables_miss_dup(
        of_table_feature_prop_next_tables_miss_t *src);

extern of_table_feature_prop_wildcards_t *
    of_table_feature_prop_wildcards_dup(
        of_table_feature_prop_wildcards_t *src);

extern of_table_feature_prop_write_actions_t *
    of_table_feature_prop_write_actions_dup(
        of_table_feature_prop_write_actions_t *src);

extern of_table_feature_prop_write_actions_miss_t *
    of_table_feature_prop_write_actions_miss_dup(
        of_table_feature_prop_write_actions_miss_t *src);

extern of_table_feature_prop_write_setfield_t *
    of_table_feature_prop_write_setfield_dup(
        of_table_feature_prop_write_setfield_t *src);

extern of_table_feature_prop_write_setfield_miss_t *
    of_table_feature_prop_write_setfield_miss_dup(
        of_table_feature_prop_write_setfield_miss_t *src);

extern of_table_features_t *
    of_table_features_dup(
        of_table_features_t *src);

extern of_table_stats_entry_t *
    of_table_stats_entry_dup(
        of_table_stats_entry_t *src);

extern of_uint32_t *
    of_uint32_dup(
        of_uint32_t *src);

extern of_uint64_t *
    of_uint64_dup(
        of_uint64_t *src);

extern of_uint8_t *
    of_uint8_dup(
        of_uint8_t *src);

extern of_list_action_t *
    of_list_action_dup(
        of_list_action_t *src);

extern of_list_action_id_t *
    of_list_action_id_dup(
        of_list_action_id_t *src);

extern of_list_bsn_interface_t *
    of_list_bsn_interface_dup(
        of_list_bsn_interface_t *src);

extern of_list_bsn_lacp_stats_entry_t *
    of_list_bsn_lacp_stats_entry_dup(
        of_list_bsn_lacp_stats_entry_t *src);

extern of_list_bsn_port_counter_stats_entry_t *
    of_list_bsn_port_counter_stats_entry_dup(
        of_list_bsn_port_counter_stats_entry_t *src);

extern of_list_bsn_switch_pipeline_stats_entry_t *
    of_list_bsn_switch_pipeline_stats_entry_dup(
        of_list_bsn_switch_pipeline_stats_entry_t *src);

extern of_list_bsn_vlan_counter_stats_entry_t *
    of_list_bsn_vlan_counter_stats_entry_dup(
        of_list_bsn_vlan_counter_stats_entry_t *src);

extern of_list_bucket_t *
    of_list_bucket_dup(
        of_list_bucket_t *src);

extern of_list_bucket_counter_t *
    of_list_bucket_counter_dup(
        of_list_bucket_counter_t *src);

extern of_list_flow_stats_entry_t *
    of_list_flow_stats_entry_dup(
        of_list_flow_stats_entry_t *src);

extern of_list_group_desc_stats_entry_t *
    of_list_group_desc_stats_entry_dup(
        of_list_group_desc_stats_entry_t *src);

extern of_list_group_stats_entry_t *
    of_list_group_stats_entry_dup(
        of_list_group_stats_entry_t *src);

extern of_list_hello_elem_t *
    of_list_hello_elem_dup(
        of_list_hello_elem_t *src);

extern of_list_instruction_t *
    of_list_instruction_dup(
        of_list_instruction_t *src);

extern of_list_meter_band_t *
    of_list_meter_band_dup(
        of_list_meter_band_t *src);

extern of_list_meter_band_stats_t *
    of_list_meter_band_stats_dup(
        of_list_meter_band_stats_t *src);

extern of_list_meter_stats_t *
    of_list_meter_stats_dup(
        of_list_meter_stats_t *src);

extern of_list_oxm_t *
    of_list_oxm_dup(
        of_list_oxm_t *src);

extern of_list_packet_queue_t *
    of_list_packet_queue_dup(
        of_list_packet_queue_t *src);

extern of_list_port_desc_t *
    of_list_port_desc_dup(
        of_list_port_desc_t *src);

extern of_list_port_stats_entry_t *
    of_list_port_stats_entry_dup(
        of_list_port_stats_entry_t *src);

extern of_list_queue_prop_t *
    of_list_queue_prop_dup(
        of_list_queue_prop_t *src);

extern of_list_queue_stats_entry_t *
    of_list_queue_stats_entry_dup(
        of_list_queue_stats_entry_t *src);

extern of_list_table_feature_prop_t *
    of_list_table_feature_prop_dup(
        of_list_table_feature_prop_t *src);

extern of_list_table_features_t *
    of_list_table_features_dup(
        of_list_table_features_t *src);

extern of_list_table_stats_entry_t *
    of_list_table_stats_entry_dup(
        of_list_table_stats_entry_t *src);

extern of_list_uint32_t *
    of_list_uint32_dup(
        of_list_uint32_t *src);

extern of_list_uint64_t *
    of_list_uint64_dup(
        of_list_uint64_t *src);

extern of_list_uint8_t *
    of_list_uint8_dup(
        of_list_uint8_t *src);

extern of_aggregate_stats_reply_t *
    of_aggregate_stats_reply_OF_VERSION_1_0_dup(
        of_aggregate_stats_reply_t *src);

extern of_aggregate_stats_request_t *
    of_aggregate_stats_request_OF_VERSION_1_0_dup(
        of_aggregate_stats_request_t *src);

extern of_bad_action_error_msg_t *
    of_bad_action_error_msg_OF_VERSION_1_0_dup(
        of_bad_action_error_msg_t *src);

extern of_bad_request_error_msg_t *
    of_bad_request_error_msg_OF_VERSION_1_0_dup(
        of_bad_request_error_msg_t *src);

extern of_barrier_reply_t *
    of_barrier_reply_OF_VERSION_1_0_dup(
        of_barrier_reply_t *src);

extern of_barrier_request_t *
    of_barrier_request_OF_VERSION_1_0_dup(
        of_barrier_request_t *src);

extern of_bsn_bw_clear_data_reply_t *
    of_bsn_bw_clear_data_reply_OF_VERSION_1_0_dup(
        of_bsn_bw_clear_data_reply_t *src);

extern of_bsn_bw_clear_data_request_t *
    of_bsn_bw_clear_data_request_OF_VERSION_1_0_dup(
        of_bsn_bw_clear_data_request_t *src);

extern of_bsn_bw_enable_get_reply_t *
    of_bsn_bw_enable_get_reply_OF_VERSION_1_0_dup(
        of_bsn_bw_enable_get_reply_t *src);

extern of_bsn_bw_enable_get_request_t *
    of_bsn_bw_enable_get_request_OF_VERSION_1_0_dup(
        of_bsn_bw_enable_get_request_t *src);

extern of_bsn_bw_enable_set_reply_t *
    of_bsn_bw_enable_set_reply_OF_VERSION_1_0_dup(
        of_bsn_bw_enable_set_reply_t *src);

extern of_bsn_bw_enable_set_request_t *
    of_bsn_bw_enable_set_request_OF_VERSION_1_0_dup(
        of_bsn_bw_enable_set_request_t *src);

extern of_bsn_get_interfaces_reply_t *
    of_bsn_get_interfaces_reply_OF_VERSION_1_0_dup(
        of_bsn_get_interfaces_reply_t *src);

extern of_bsn_get_interfaces_request_t *
    of_bsn_get_interfaces_request_OF_VERSION_1_0_dup(
        of_bsn_get_interfaces_request_t *src);

extern of_bsn_get_ip_mask_reply_t *
    of_bsn_get_ip_mask_reply_OF_VERSION_1_0_dup(
        of_bsn_get_ip_mask_reply_t *src);

extern of_bsn_get_ip_mask_request_t *
    of_bsn_get_ip_mask_request_OF_VERSION_1_0_dup(
        of_bsn_get_ip_mask_request_t *src);

extern of_bsn_get_l2_table_reply_t *
    of_bsn_get_l2_table_reply_OF_VERSION_1_0_dup(
        of_bsn_get_l2_table_reply_t *src);

extern of_bsn_get_l2_table_request_t *
    of_bsn_get_l2_table_request_OF_VERSION_1_0_dup(
        of_bsn_get_l2_table_request_t *src);

extern of_bsn_get_mirroring_reply_t *
    of_bsn_get_mirroring_reply_OF_VERSION_1_0_dup(
        of_bsn_get_mirroring_reply_t *src);

extern of_bsn_get_mirroring_request_t *
    of_bsn_get_mirroring_request_OF_VERSION_1_0_dup(
        of_bsn_get_mirroring_request_t *src);

extern of_bsn_header_t *
    of_bsn_header_OF_VERSION_1_0_dup(
        of_bsn_header_t *src);

extern of_bsn_hybrid_get_reply_t *
    of_bsn_hybrid_get_reply_OF_VERSION_1_0_dup(
        of_bsn_hybrid_get_reply_t *src);

extern of_bsn_hybrid_get_request_t *
    of_bsn_hybrid_get_request_OF_VERSION_1_0_dup(
        of_bsn_hybrid_get_request_t *src);

extern of_bsn_pdu_rx_reply_t *
    of_bsn_pdu_rx_reply_OF_VERSION_1_0_dup(
        of_bsn_pdu_rx_reply_t *src);

extern of_bsn_pdu_rx_request_t *
    of_bsn_pdu_rx_request_OF_VERSION_1_0_dup(
        of_bsn_pdu_rx_request_t *src);

extern of_bsn_pdu_rx_timeout_t *
    of_bsn_pdu_rx_timeout_OF_VERSION_1_0_dup(
        of_bsn_pdu_rx_timeout_t *src);

extern of_bsn_pdu_tx_reply_t *
    of_bsn_pdu_tx_reply_OF_VERSION_1_0_dup(
        of_bsn_pdu_tx_reply_t *src);

extern of_bsn_pdu_tx_request_t *
    of_bsn_pdu_tx_request_OF_VERSION_1_0_dup(
        of_bsn_pdu_tx_request_t *src);

extern of_bsn_set_ip_mask_t *
    of_bsn_set_ip_mask_OF_VERSION_1_0_dup(
        of_bsn_set_ip_mask_t *src);

extern of_bsn_set_l2_table_reply_t *
    of_bsn_set_l2_table_reply_OF_VERSION_1_0_dup(
        of_bsn_set_l2_table_reply_t *src);

extern of_bsn_set_l2_table_request_t *
    of_bsn_set_l2_table_request_OF_VERSION_1_0_dup(
        of_bsn_set_l2_table_request_t *src);

extern of_bsn_set_mirroring_t *
    of_bsn_set_mirroring_OF_VERSION_1_0_dup(
        of_bsn_set_mirroring_t *src);

extern of_bsn_set_pktin_suppression_reply_t *
    of_bsn_set_pktin_suppression_reply_OF_VERSION_1_0_dup(
        of_bsn_set_pktin_suppression_reply_t *src);

extern of_bsn_set_pktin_suppression_request_t *
    of_bsn_set_pktin_suppression_request_OF_VERSION_1_0_dup(
        of_bsn_set_pktin_suppression_request_t *src);

extern of_bsn_shell_command_t *
    of_bsn_shell_command_OF_VERSION_1_0_dup(
        of_bsn_shell_command_t *src);

extern of_bsn_shell_output_t *
    of_bsn_shell_output_OF_VERSION_1_0_dup(
        of_bsn_shell_output_t *src);

extern of_bsn_shell_status_t *
    of_bsn_shell_status_OF_VERSION_1_0_dup(
        of_bsn_shell_status_t *src);

extern of_bsn_stats_reply_t *
    of_bsn_stats_reply_OF_VERSION_1_0_dup(
        of_bsn_stats_reply_t *src);

extern of_bsn_stats_request_t *
    of_bsn_stats_request_OF_VERSION_1_0_dup(
        of_bsn_stats_request_t *src);

extern of_bsn_virtual_port_create_reply_t *
    of_bsn_virtual_port_create_reply_OF_VERSION_1_0_dup(
        of_bsn_virtual_port_create_reply_t *src);

extern of_bsn_virtual_port_create_request_t *
    of_bsn_virtual_port_create_request_OF_VERSION_1_0_dup(
        of_bsn_virtual_port_create_request_t *src);

extern of_bsn_virtual_port_remove_reply_t *
    of_bsn_virtual_port_remove_reply_OF_VERSION_1_0_dup(
        of_bsn_virtual_port_remove_reply_t *src);

extern of_bsn_virtual_port_remove_request_t *
    of_bsn_virtual_port_remove_request_OF_VERSION_1_0_dup(
        of_bsn_virtual_port_remove_request_t *src);

extern of_desc_stats_reply_t *
    of_desc_stats_reply_OF_VERSION_1_0_dup(
        of_desc_stats_reply_t *src);

extern of_desc_stats_request_t *
    of_desc_stats_request_OF_VERSION_1_0_dup(
        of_desc_stats_request_t *src);

extern of_echo_reply_t *
    of_echo_reply_OF_VERSION_1_0_dup(
        of_echo_reply_t *src);

extern of_echo_request_t *
    of_echo_request_OF_VERSION_1_0_dup(
        of_echo_request_t *src);

extern of_error_msg_t *
    of_error_msg_OF_VERSION_1_0_dup(
        of_error_msg_t *src);

extern of_experimenter_t *
    of_experimenter_OF_VERSION_1_0_dup(
        of_experimenter_t *src);

extern of_experimenter_stats_reply_t *
    of_experimenter_stats_reply_OF_VERSION_1_0_dup(
        of_experimenter_stats_reply_t *src);

extern of_experimenter_stats_request_t *
    of_experimenter_stats_request_OF_VERSION_1_0_dup(
        of_experimenter_stats_request_t *src);

extern of_features_reply_t *
    of_features_reply_OF_VERSION_1_0_dup(
        of_features_reply_t *src);

extern of_features_request_t *
    of_features_request_OF_VERSION_1_0_dup(
        of_features_request_t *src);

extern of_flow_add_t *
    of_flow_add_OF_VERSION_1_0_dup(
        of_flow_add_t *src);

extern of_flow_delete_t *
    of_flow_delete_OF_VERSION_1_0_dup(
        of_flow_delete_t *src);

extern of_flow_delete_strict_t *
    of_flow_delete_strict_OF_VERSION_1_0_dup(
        of_flow_delete_strict_t *src);

extern of_flow_mod_t *
    of_flow_mod_OF_VERSION_1_0_dup(
        of_flow_mod_t *src);

extern of_flow_mod_failed_error_msg_t *
    of_flow_mod_failed_error_msg_OF_VERSION_1_0_dup(
        of_flow_mod_failed_error_msg_t *src);

extern of_flow_modify_t *
    of_flow_modify_OF_VERSION_1_0_dup(
        of_flow_modify_t *src);

extern of_flow_modify_strict_t *
    of_flow_modify_strict_OF_VERSION_1_0_dup(
        of_flow_modify_strict_t *src);

extern of_flow_removed_t *
    of_flow_removed_OF_VERSION_1_0_dup(
        of_flow_removed_t *src);

extern of_flow_stats_reply_t *
    of_flow_stats_reply_OF_VERSION_1_0_dup(
        of_flow_stats_reply_t *src);

extern of_flow_stats_request_t *
    of_flow_stats_request_OF_VERSION_1_0_dup(
        of_flow_stats_request_t *src);

extern of_get_config_reply_t *
    of_get_config_reply_OF_VERSION_1_0_dup(
        of_get_config_reply_t *src);

extern of_get_config_request_t *
    of_get_config_request_OF_VERSION_1_0_dup(
        of_get_config_request_t *src);

extern of_hello_t *
    of_hello_OF_VERSION_1_0_dup(
        of_hello_t *src);

extern of_hello_failed_error_msg_t *
    of_hello_failed_error_msg_OF_VERSION_1_0_dup(
        of_hello_failed_error_msg_t *src);

extern of_nicira_controller_role_reply_t *
    of_nicira_controller_role_reply_OF_VERSION_1_0_dup(
        of_nicira_controller_role_reply_t *src);

extern of_nicira_controller_role_request_t *
    of_nicira_controller_role_request_OF_VERSION_1_0_dup(
        of_nicira_controller_role_request_t *src);

extern of_nicira_header_t *
    of_nicira_header_OF_VERSION_1_0_dup(
        of_nicira_header_t *src);

extern of_packet_in_t *
    of_packet_in_OF_VERSION_1_0_dup(
        of_packet_in_t *src);

extern of_packet_out_t *
    of_packet_out_OF_VERSION_1_0_dup(
        of_packet_out_t *src);

extern of_port_mod_t *
    of_port_mod_OF_VERSION_1_0_dup(
        of_port_mod_t *src);

extern of_port_mod_failed_error_msg_t *
    of_port_mod_failed_error_msg_OF_VERSION_1_0_dup(
        of_port_mod_failed_error_msg_t *src);

extern of_port_stats_reply_t *
    of_port_stats_reply_OF_VERSION_1_0_dup(
        of_port_stats_reply_t *src);

extern of_port_stats_request_t *
    of_port_stats_request_OF_VERSION_1_0_dup(
        of_port_stats_request_t *src);

extern of_port_status_t *
    of_port_status_OF_VERSION_1_0_dup(
        of_port_status_t *src);

extern of_queue_get_config_reply_t *
    of_queue_get_config_reply_OF_VERSION_1_0_dup(
        of_queue_get_config_reply_t *src);

extern of_queue_get_config_request_t *
    of_queue_get_config_request_OF_VERSION_1_0_dup(
        of_queue_get_config_request_t *src);

extern of_queue_op_failed_error_msg_t *
    of_queue_op_failed_error_msg_OF_VERSION_1_0_dup(
        of_queue_op_failed_error_msg_t *src);

extern of_queue_stats_reply_t *
    of_queue_stats_reply_OF_VERSION_1_0_dup(
        of_queue_stats_reply_t *src);

extern of_queue_stats_request_t *
    of_queue_stats_request_OF_VERSION_1_0_dup(
        of_queue_stats_request_t *src);

extern of_set_config_t *
    of_set_config_OF_VERSION_1_0_dup(
        of_set_config_t *src);

extern of_stats_reply_t *
    of_stats_reply_OF_VERSION_1_0_dup(
        of_stats_reply_t *src);

extern of_stats_request_t *
    of_stats_request_OF_VERSION_1_0_dup(
        of_stats_request_t *src);

extern of_table_mod_t *
    of_table_mod_OF_VERSION_1_0_dup(
        of_table_mod_t *src);

extern of_table_stats_reply_t *
    of_table_stats_reply_OF_VERSION_1_0_dup(
        of_table_stats_reply_t *src);

extern of_table_stats_request_t *
    of_table_stats_request_OF_VERSION_1_0_dup(
        of_table_stats_request_t *src);

extern of_action_t *
    of_action_OF_VERSION_1_0_dup(
        of_action_t *src);

extern of_action_bsn_t *
    of_action_bsn_OF_VERSION_1_0_dup(
        of_action_bsn_t *src);

extern of_action_bsn_mirror_t *
    of_action_bsn_mirror_OF_VERSION_1_0_dup(
        of_action_bsn_mirror_t *src);

extern of_action_bsn_set_tunnel_dst_t *
    of_action_bsn_set_tunnel_dst_OF_VERSION_1_0_dup(
        of_action_bsn_set_tunnel_dst_t *src);

extern of_action_enqueue_t *
    of_action_enqueue_OF_VERSION_1_0_dup(
        of_action_enqueue_t *src);

extern of_action_experimenter_t *
    of_action_experimenter_OF_VERSION_1_0_dup(
        of_action_experimenter_t *src);

extern of_action_header_t *
    of_action_header_OF_VERSION_1_0_dup(
        of_action_header_t *src);

extern of_action_nicira_t *
    of_action_nicira_OF_VERSION_1_0_dup(
        of_action_nicira_t *src);

extern of_action_nicira_dec_ttl_t *
    of_action_nicira_dec_ttl_OF_VERSION_1_0_dup(
        of_action_nicira_dec_ttl_t *src);

extern of_action_output_t *
    of_action_output_OF_VERSION_1_0_dup(
        of_action_output_t *src);

extern of_action_set_dl_dst_t *
    of_action_set_dl_dst_OF_VERSION_1_0_dup(
        of_action_set_dl_dst_t *src);

extern of_action_set_dl_src_t *
    of_action_set_dl_src_OF_VERSION_1_0_dup(
        of_action_set_dl_src_t *src);

extern of_action_set_nw_dst_t *
    of_action_set_nw_dst_OF_VERSION_1_0_dup(
        of_action_set_nw_dst_t *src);

extern of_action_set_nw_src_t *
    of_action_set_nw_src_OF_VERSION_1_0_dup(
        of_action_set_nw_src_t *src);

extern of_action_set_nw_tos_t *
    of_action_set_nw_tos_OF_VERSION_1_0_dup(
        of_action_set_nw_tos_t *src);

extern of_action_set_tp_dst_t *
    of_action_set_tp_dst_OF_VERSION_1_0_dup(
        of_action_set_tp_dst_t *src);

extern of_action_set_tp_src_t *
    of_action_set_tp_src_OF_VERSION_1_0_dup(
        of_action_set_tp_src_t *src);

extern of_action_set_vlan_pcp_t *
    of_action_set_vlan_pcp_OF_VERSION_1_0_dup(
        of_action_set_vlan_pcp_t *src);

extern of_action_set_vlan_vid_t *
    of_action_set_vlan_vid_OF_VERSION_1_0_dup(
        of_action_set_vlan_vid_t *src);

extern of_action_strip_vlan_t *
    of_action_strip_vlan_OF_VERSION_1_0_dup(
        of_action_strip_vlan_t *src);

extern of_bsn_interface_t *
    of_bsn_interface_OF_VERSION_1_0_dup(
        of_bsn_interface_t *src);

extern of_bsn_vport_t *
    of_bsn_vport_OF_VERSION_1_0_dup(
        of_bsn_vport_t *src);

extern of_bsn_vport_header_t *
    of_bsn_vport_header_OF_VERSION_1_0_dup(
        of_bsn_vport_header_t *src);

extern of_bsn_vport_q_in_q_t *
    of_bsn_vport_q_in_q_OF_VERSION_1_0_dup(
        of_bsn_vport_q_in_q_t *src);

extern of_flow_stats_entry_t *
    of_flow_stats_entry_OF_VERSION_1_0_dup(
        of_flow_stats_entry_t *src);

extern of_header_t *
    of_header_OF_VERSION_1_0_dup(
        of_header_t *src);

extern of_match_v1_t *
    of_match_v1_OF_VERSION_1_0_dup(
        of_match_v1_t *src);

extern of_packet_queue_t *
    of_packet_queue_OF_VERSION_1_0_dup(
        of_packet_queue_t *src);

extern of_port_desc_t *
    of_port_desc_OF_VERSION_1_0_dup(
        of_port_desc_t *src);

extern of_port_stats_entry_t *
    of_port_stats_entry_OF_VERSION_1_0_dup(
        of_port_stats_entry_t *src);

extern of_queue_prop_t *
    of_queue_prop_OF_VERSION_1_0_dup(
        of_queue_prop_t *src);

extern of_queue_prop_header_t *
    of_queue_prop_header_OF_VERSION_1_0_dup(
        of_queue_prop_header_t *src);

extern of_queue_prop_min_rate_t *
    of_queue_prop_min_rate_OF_VERSION_1_0_dup(
        of_queue_prop_min_rate_t *src);

extern of_queue_stats_entry_t *
    of_queue_stats_entry_OF_VERSION_1_0_dup(
        of_queue_stats_entry_t *src);

extern of_table_stats_entry_t *
    of_table_stats_entry_OF_VERSION_1_0_dup(
        of_table_stats_entry_t *src);

extern of_list_action_t *
    of_list_action_OF_VERSION_1_0_dup(
        of_list_action_t *src);

extern of_list_bsn_interface_t *
    of_list_bsn_interface_OF_VERSION_1_0_dup(
        of_list_bsn_interface_t *src);

extern of_list_flow_stats_entry_t *
    of_list_flow_stats_entry_OF_VERSION_1_0_dup(
        of_list_flow_stats_entry_t *src);

extern of_list_packet_queue_t *
    of_list_packet_queue_OF_VERSION_1_0_dup(
        of_list_packet_queue_t *src);

extern of_list_port_desc_t *
    of_list_port_desc_OF_VERSION_1_0_dup(
        of_list_port_desc_t *src);

extern of_list_port_stats_entry_t *
    of_list_port_stats_entry_OF_VERSION_1_0_dup(
        of_list_port_stats_entry_t *src);

extern of_list_queue_prop_t *
    of_list_queue_prop_OF_VERSION_1_0_dup(
        of_list_queue_prop_t *src);

extern of_list_queue_stats_entry_t *
    of_list_queue_stats_entry_OF_VERSION_1_0_dup(
        of_list_queue_stats_entry_t *src);

extern of_list_table_stats_entry_t *
    of_list_table_stats_entry_OF_VERSION_1_0_dup(
        of_list_table_stats_entry_t *src);

extern of_aggregate_stats_reply_t *
    of_aggregate_stats_reply_OF_VERSION_1_1_dup(
        of_aggregate_stats_reply_t *src);

extern of_aggregate_stats_request_t *
    of_aggregate_stats_request_OF_VERSION_1_1_dup(
        of_aggregate_stats_request_t *src);

extern of_bad_action_error_msg_t *
    of_bad_action_error_msg_OF_VERSION_1_1_dup(
        of_bad_action_error_msg_t *src);

extern of_bad_instruction_error_msg_t *
    of_bad_instruction_error_msg_OF_VERSION_1_1_dup(
        of_bad_instruction_error_msg_t *src);

extern of_bad_match_error_msg_t *
    of_bad_match_error_msg_OF_VERSION_1_1_dup(
        of_bad_match_error_msg_t *src);

extern of_bad_request_error_msg_t *
    of_bad_request_error_msg_OF_VERSION_1_1_dup(
        of_bad_request_error_msg_t *src);

extern of_barrier_reply_t *
    of_barrier_reply_OF_VERSION_1_1_dup(
        of_barrier_reply_t *src);

extern of_barrier_request_t *
    of_barrier_request_OF_VERSION_1_1_dup(
        of_barrier_request_t *src);

extern of_bsn_bw_clear_data_reply_t *
    of_bsn_bw_clear_data_reply_OF_VERSION_1_1_dup(
        of_bsn_bw_clear_data_reply_t *src);

extern of_bsn_bw_clear_data_request_t *
    of_bsn_bw_clear_data_request_OF_VERSION_1_1_dup(
        of_bsn_bw_clear_data_request_t *src);

extern of_bsn_bw_enable_get_reply_t *
    of_bsn_bw_enable_get_reply_OF_VERSION_1_1_dup(
        of_bsn_bw_enable_get_reply_t *src);

extern of_bsn_bw_enable_get_request_t *
    of_bsn_bw_enable_get_request_OF_VERSION_1_1_dup(
        of_bsn_bw_enable_get_request_t *src);

extern of_bsn_bw_enable_set_reply_t *
    of_bsn_bw_enable_set_reply_OF_VERSION_1_1_dup(
        of_bsn_bw_enable_set_reply_t *src);

extern of_bsn_bw_enable_set_request_t *
    of_bsn_bw_enable_set_request_OF_VERSION_1_1_dup(
        of_bsn_bw_enable_set_request_t *src);

extern of_bsn_get_interfaces_reply_t *
    of_bsn_get_interfaces_reply_OF_VERSION_1_1_dup(
        of_bsn_get_interfaces_reply_t *src);

extern of_bsn_get_interfaces_request_t *
    of_bsn_get_interfaces_request_OF_VERSION_1_1_dup(
        of_bsn_get_interfaces_request_t *src);

extern of_bsn_get_mirroring_reply_t *
    of_bsn_get_mirroring_reply_OF_VERSION_1_1_dup(
        of_bsn_get_mirroring_reply_t *src);

extern of_bsn_get_mirroring_request_t *
    of_bsn_get_mirroring_request_OF_VERSION_1_1_dup(
        of_bsn_get_mirroring_request_t *src);

extern of_bsn_header_t *
    of_bsn_header_OF_VERSION_1_1_dup(
        of_bsn_header_t *src);

extern of_bsn_pdu_rx_reply_t *
    of_bsn_pdu_rx_reply_OF_VERSION_1_1_dup(
        of_bsn_pdu_rx_reply_t *src);

extern of_bsn_pdu_rx_request_t *
    of_bsn_pdu_rx_request_OF_VERSION_1_1_dup(
        of_bsn_pdu_rx_request_t *src);

extern of_bsn_pdu_rx_timeout_t *
    of_bsn_pdu_rx_timeout_OF_VERSION_1_1_dup(
        of_bsn_pdu_rx_timeout_t *src);

extern of_bsn_pdu_tx_reply_t *
    of_bsn_pdu_tx_reply_OF_VERSION_1_1_dup(
        of_bsn_pdu_tx_reply_t *src);

extern of_bsn_pdu_tx_request_t *
    of_bsn_pdu_tx_request_OF_VERSION_1_1_dup(
        of_bsn_pdu_tx_request_t *src);

extern of_bsn_set_mirroring_t *
    of_bsn_set_mirroring_OF_VERSION_1_1_dup(
        of_bsn_set_mirroring_t *src);

extern of_bsn_set_pktin_suppression_reply_t *
    of_bsn_set_pktin_suppression_reply_OF_VERSION_1_1_dup(
        of_bsn_set_pktin_suppression_reply_t *src);

extern of_bsn_set_pktin_suppression_request_t *
    of_bsn_set_pktin_suppression_request_OF_VERSION_1_1_dup(
        of_bsn_set_pktin_suppression_request_t *src);

extern of_bsn_stats_reply_t *
    of_bsn_stats_reply_OF_VERSION_1_1_dup(
        of_bsn_stats_reply_t *src);

extern of_bsn_stats_request_t *
    of_bsn_stats_request_OF_VERSION_1_1_dup(
        of_bsn_stats_request_t *src);

extern of_bsn_virtual_port_create_reply_t *
    of_bsn_virtual_port_create_reply_OF_VERSION_1_1_dup(
        of_bsn_virtual_port_create_reply_t *src);

extern of_bsn_virtual_port_create_request_t *
    of_bsn_virtual_port_create_request_OF_VERSION_1_1_dup(
        of_bsn_virtual_port_create_request_t *src);

extern of_bsn_virtual_port_remove_reply_t *
    of_bsn_virtual_port_remove_reply_OF_VERSION_1_1_dup(
        of_bsn_virtual_port_remove_reply_t *src);

extern of_bsn_virtual_port_remove_request_t *
    of_bsn_virtual_port_remove_request_OF_VERSION_1_1_dup(
        of_bsn_virtual_port_remove_request_t *src);

extern of_desc_stats_reply_t *
    of_desc_stats_reply_OF_VERSION_1_1_dup(
        of_desc_stats_reply_t *src);

extern of_desc_stats_request_t *
    of_desc_stats_request_OF_VERSION_1_1_dup(
        of_desc_stats_request_t *src);

extern of_echo_reply_t *
    of_echo_reply_OF_VERSION_1_1_dup(
        of_echo_reply_t *src);

extern of_echo_request_t *
    of_echo_request_OF_VERSION_1_1_dup(
        of_echo_request_t *src);

extern of_error_msg_t *
    of_error_msg_OF_VERSION_1_1_dup(
        of_error_msg_t *src);

extern of_experimenter_t *
    of_experimenter_OF_VERSION_1_1_dup(
        of_experimenter_t *src);

extern of_experimenter_stats_reply_t *
    of_experimenter_stats_reply_OF_VERSION_1_1_dup(
        of_experimenter_stats_reply_t *src);

extern of_experimenter_stats_request_t *
    of_experimenter_stats_request_OF_VERSION_1_1_dup(
        of_experimenter_stats_request_t *src);

extern of_features_reply_t *
    of_features_reply_OF_VERSION_1_1_dup(
        of_features_reply_t *src);

extern of_features_request_t *
    of_features_request_OF_VERSION_1_1_dup(
        of_features_request_t *src);

extern of_flow_add_t *
    of_flow_add_OF_VERSION_1_1_dup(
        of_flow_add_t *src);

extern of_flow_delete_t *
    of_flow_delete_OF_VERSION_1_1_dup(
        of_flow_delete_t *src);

extern of_flow_delete_strict_t *
    of_flow_delete_strict_OF_VERSION_1_1_dup(
        of_flow_delete_strict_t *src);

extern of_flow_mod_t *
    of_flow_mod_OF_VERSION_1_1_dup(
        of_flow_mod_t *src);

extern of_flow_mod_failed_error_msg_t *
    of_flow_mod_failed_error_msg_OF_VERSION_1_1_dup(
        of_flow_mod_failed_error_msg_t *src);

extern of_flow_modify_t *
    of_flow_modify_OF_VERSION_1_1_dup(
        of_flow_modify_t *src);

extern of_flow_modify_strict_t *
    of_flow_modify_strict_OF_VERSION_1_1_dup(
        of_flow_modify_strict_t *src);

extern of_flow_removed_t *
    of_flow_removed_OF_VERSION_1_1_dup(
        of_flow_removed_t *src);

extern of_flow_stats_reply_t *
    of_flow_stats_reply_OF_VERSION_1_1_dup(
        of_flow_stats_reply_t *src);

extern of_flow_stats_request_t *
    of_flow_stats_request_OF_VERSION_1_1_dup(
        of_flow_stats_request_t *src);

extern of_get_config_reply_t *
    of_get_config_reply_OF_VERSION_1_1_dup(
        of_get_config_reply_t *src);

extern of_get_config_request_t *
    of_get_config_request_OF_VERSION_1_1_dup(
        of_get_config_request_t *src);

extern of_group_add_t *
    of_group_add_OF_VERSION_1_1_dup(
        of_group_add_t *src);

extern of_group_delete_t *
    of_group_delete_OF_VERSION_1_1_dup(
        of_group_delete_t *src);

extern of_group_desc_stats_reply_t *
    of_group_desc_stats_reply_OF_VERSION_1_1_dup(
        of_group_desc_stats_reply_t *src);

extern of_group_desc_stats_request_t *
    of_group_desc_stats_request_OF_VERSION_1_1_dup(
        of_group_desc_stats_request_t *src);

extern of_group_mod_t *
    of_group_mod_OF_VERSION_1_1_dup(
        of_group_mod_t *src);

extern of_group_mod_failed_error_msg_t *
    of_group_mod_failed_error_msg_OF_VERSION_1_1_dup(
        of_group_mod_failed_error_msg_t *src);

extern of_group_modify_t *
    of_group_modify_OF_VERSION_1_1_dup(
        of_group_modify_t *src);

extern of_group_stats_reply_t *
    of_group_stats_reply_OF_VERSION_1_1_dup(
        of_group_stats_reply_t *src);

extern of_group_stats_request_t *
    of_group_stats_request_OF_VERSION_1_1_dup(
        of_group_stats_request_t *src);

extern of_hello_t *
    of_hello_OF_VERSION_1_1_dup(
        of_hello_t *src);

extern of_hello_failed_error_msg_t *
    of_hello_failed_error_msg_OF_VERSION_1_1_dup(
        of_hello_failed_error_msg_t *src);

extern of_nicira_header_t *
    of_nicira_header_OF_VERSION_1_1_dup(
        of_nicira_header_t *src);

extern of_packet_in_t *
    of_packet_in_OF_VERSION_1_1_dup(
        of_packet_in_t *src);

extern of_packet_out_t *
    of_packet_out_OF_VERSION_1_1_dup(
        of_packet_out_t *src);

extern of_port_mod_t *
    of_port_mod_OF_VERSION_1_1_dup(
        of_port_mod_t *src);

extern of_port_mod_failed_error_msg_t *
    of_port_mod_failed_error_msg_OF_VERSION_1_1_dup(
        of_port_mod_failed_error_msg_t *src);

extern of_port_stats_reply_t *
    of_port_stats_reply_OF_VERSION_1_1_dup(
        of_port_stats_reply_t *src);

extern of_port_stats_request_t *
    of_port_stats_request_OF_VERSION_1_1_dup(
        of_port_stats_request_t *src);

extern of_port_status_t *
    of_port_status_OF_VERSION_1_1_dup(
        of_port_status_t *src);

extern of_queue_get_config_reply_t *
    of_queue_get_config_reply_OF_VERSION_1_1_dup(
        of_queue_get_config_reply_t *src);

extern of_queue_get_config_request_t *
    of_queue_get_config_request_OF_VERSION_1_1_dup(
        of_queue_get_config_request_t *src);

extern of_queue_op_failed_error_msg_t *
    of_queue_op_failed_error_msg_OF_VERSION_1_1_dup(
        of_queue_op_failed_error_msg_t *src);

extern of_queue_stats_reply_t *
    of_queue_stats_reply_OF_VERSION_1_1_dup(
        of_queue_stats_reply_t *src);

extern of_queue_stats_request_t *
    of_queue_stats_request_OF_VERSION_1_1_dup(
        of_queue_stats_request_t *src);

extern of_set_config_t *
    of_set_config_OF_VERSION_1_1_dup(
        of_set_config_t *src);

extern of_stats_reply_t *
    of_stats_reply_OF_VERSION_1_1_dup(
        of_stats_reply_t *src);

extern of_stats_request_t *
    of_stats_request_OF_VERSION_1_1_dup(
        of_stats_request_t *src);

extern of_switch_config_failed_error_msg_t *
    of_switch_config_failed_error_msg_OF_VERSION_1_1_dup(
        of_switch_config_failed_error_msg_t *src);

extern of_table_mod_t *
    of_table_mod_OF_VERSION_1_1_dup(
        of_table_mod_t *src);

extern of_table_mod_failed_error_msg_t *
    of_table_mod_failed_error_msg_OF_VERSION_1_1_dup(
        of_table_mod_failed_error_msg_t *src);

extern of_table_stats_reply_t *
    of_table_stats_reply_OF_VERSION_1_1_dup(
        of_table_stats_reply_t *src);

extern of_table_stats_request_t *
    of_table_stats_request_OF_VERSION_1_1_dup(
        of_table_stats_request_t *src);

extern of_action_t *
    of_action_OF_VERSION_1_1_dup(
        of_action_t *src);

extern of_action_bsn_t *
    of_action_bsn_OF_VERSION_1_1_dup(
        of_action_bsn_t *src);

extern of_action_bsn_mirror_t *
    of_action_bsn_mirror_OF_VERSION_1_1_dup(
        of_action_bsn_mirror_t *src);

extern of_action_bsn_set_tunnel_dst_t *
    of_action_bsn_set_tunnel_dst_OF_VERSION_1_1_dup(
        of_action_bsn_set_tunnel_dst_t *src);

extern of_action_copy_ttl_in_t *
    of_action_copy_ttl_in_OF_VERSION_1_1_dup(
        of_action_copy_ttl_in_t *src);

extern of_action_copy_ttl_out_t *
    of_action_copy_ttl_out_OF_VERSION_1_1_dup(
        of_action_copy_ttl_out_t *src);

extern of_action_dec_mpls_ttl_t *
    of_action_dec_mpls_ttl_OF_VERSION_1_1_dup(
        of_action_dec_mpls_ttl_t *src);

extern of_action_dec_nw_ttl_t *
    of_action_dec_nw_ttl_OF_VERSION_1_1_dup(
        of_action_dec_nw_ttl_t *src);

extern of_action_experimenter_t *
    of_action_experimenter_OF_VERSION_1_1_dup(
        of_action_experimenter_t *src);

extern of_action_group_t *
    of_action_group_OF_VERSION_1_1_dup(
        of_action_group_t *src);

extern of_action_header_t *
    of_action_header_OF_VERSION_1_1_dup(
        of_action_header_t *src);

extern of_action_nicira_t *
    of_action_nicira_OF_VERSION_1_1_dup(
        of_action_nicira_t *src);

extern of_action_nicira_dec_ttl_t *
    of_action_nicira_dec_ttl_OF_VERSION_1_1_dup(
        of_action_nicira_dec_ttl_t *src);

extern of_action_output_t *
    of_action_output_OF_VERSION_1_1_dup(
        of_action_output_t *src);

extern of_action_pop_mpls_t *
    of_action_pop_mpls_OF_VERSION_1_1_dup(
        of_action_pop_mpls_t *src);

extern of_action_pop_vlan_t *
    of_action_pop_vlan_OF_VERSION_1_1_dup(
        of_action_pop_vlan_t *src);

extern of_action_push_mpls_t *
    of_action_push_mpls_OF_VERSION_1_1_dup(
        of_action_push_mpls_t *src);

extern of_action_push_vlan_t *
    of_action_push_vlan_OF_VERSION_1_1_dup(
        of_action_push_vlan_t *src);

extern of_action_set_dl_dst_t *
    of_action_set_dl_dst_OF_VERSION_1_1_dup(
        of_action_set_dl_dst_t *src);

extern of_action_set_dl_src_t *
    of_action_set_dl_src_OF_VERSION_1_1_dup(
        of_action_set_dl_src_t *src);

extern of_action_set_mpls_label_t *
    of_action_set_mpls_label_OF_VERSION_1_1_dup(
        of_action_set_mpls_label_t *src);

extern of_action_set_mpls_tc_t *
    of_action_set_mpls_tc_OF_VERSION_1_1_dup(
        of_action_set_mpls_tc_t *src);

extern of_action_set_mpls_ttl_t *
    of_action_set_mpls_ttl_OF_VERSION_1_1_dup(
        of_action_set_mpls_ttl_t *src);

extern of_action_set_nw_dst_t *
    of_action_set_nw_dst_OF_VERSION_1_1_dup(
        of_action_set_nw_dst_t *src);

extern of_action_set_nw_ecn_t *
    of_action_set_nw_ecn_OF_VERSION_1_1_dup(
        of_action_set_nw_ecn_t *src);

extern of_action_set_nw_src_t *
    of_action_set_nw_src_OF_VERSION_1_1_dup(
        of_action_set_nw_src_t *src);

extern of_action_set_nw_tos_t *
    of_action_set_nw_tos_OF_VERSION_1_1_dup(
        of_action_set_nw_tos_t *src);

extern of_action_set_nw_ttl_t *
    of_action_set_nw_ttl_OF_VERSION_1_1_dup(
        of_action_set_nw_ttl_t *src);

extern of_action_set_queue_t *
    of_action_set_queue_OF_VERSION_1_1_dup(
        of_action_set_queue_t *src);

extern of_action_set_tp_dst_t *
    of_action_set_tp_dst_OF_VERSION_1_1_dup(
        of_action_set_tp_dst_t *src);

extern of_action_set_tp_src_t *
    of_action_set_tp_src_OF_VERSION_1_1_dup(
        of_action_set_tp_src_t *src);

extern of_action_set_vlan_pcp_t *
    of_action_set_vlan_pcp_OF_VERSION_1_1_dup(
        of_action_set_vlan_pcp_t *src);

extern of_action_set_vlan_vid_t *
    of_action_set_vlan_vid_OF_VERSION_1_1_dup(
        of_action_set_vlan_vid_t *src);

extern of_bsn_interface_t *
    of_bsn_interface_OF_VERSION_1_1_dup(
        of_bsn_interface_t *src);

extern of_bsn_vport_t *
    of_bsn_vport_OF_VERSION_1_1_dup(
        of_bsn_vport_t *src);

extern of_bsn_vport_header_t *
    of_bsn_vport_header_OF_VERSION_1_1_dup(
        of_bsn_vport_header_t *src);

extern of_bsn_vport_q_in_q_t *
    of_bsn_vport_q_in_q_OF_VERSION_1_1_dup(
        of_bsn_vport_q_in_q_t *src);

extern of_bucket_t *
    of_bucket_OF_VERSION_1_1_dup(
        of_bucket_t *src);

extern of_bucket_counter_t *
    of_bucket_counter_OF_VERSION_1_1_dup(
        of_bucket_counter_t *src);

extern of_flow_stats_entry_t *
    of_flow_stats_entry_OF_VERSION_1_1_dup(
        of_flow_stats_entry_t *src);

extern of_group_desc_stats_entry_t *
    of_group_desc_stats_entry_OF_VERSION_1_1_dup(
        of_group_desc_stats_entry_t *src);

extern of_group_stats_entry_t *
    of_group_stats_entry_OF_VERSION_1_1_dup(
        of_group_stats_entry_t *src);

extern of_header_t *
    of_header_OF_VERSION_1_1_dup(
        of_header_t *src);

extern of_instruction_t *
    of_instruction_OF_VERSION_1_1_dup(
        of_instruction_t *src);

extern of_instruction_apply_actions_t *
    of_instruction_apply_actions_OF_VERSION_1_1_dup(
        of_instruction_apply_actions_t *src);

extern of_instruction_clear_actions_t *
    of_instruction_clear_actions_OF_VERSION_1_1_dup(
        of_instruction_clear_actions_t *src);

extern of_instruction_experimenter_t *
    of_instruction_experimenter_OF_VERSION_1_1_dup(
        of_instruction_experimenter_t *src);

extern of_instruction_goto_table_t *
    of_instruction_goto_table_OF_VERSION_1_1_dup(
        of_instruction_goto_table_t *src);

extern of_instruction_header_t *
    of_instruction_header_OF_VERSION_1_1_dup(
        of_instruction_header_t *src);

extern of_instruction_write_actions_t *
    of_instruction_write_actions_OF_VERSION_1_1_dup(
        of_instruction_write_actions_t *src);

extern of_instruction_write_metadata_t *
    of_instruction_write_metadata_OF_VERSION_1_1_dup(
        of_instruction_write_metadata_t *src);

extern of_match_v2_t *
    of_match_v2_OF_VERSION_1_1_dup(
        of_match_v2_t *src);

extern of_packet_queue_t *
    of_packet_queue_OF_VERSION_1_1_dup(
        of_packet_queue_t *src);

extern of_port_desc_t *
    of_port_desc_OF_VERSION_1_1_dup(
        of_port_desc_t *src);

extern of_port_stats_entry_t *
    of_port_stats_entry_OF_VERSION_1_1_dup(
        of_port_stats_entry_t *src);

extern of_queue_prop_t *
    of_queue_prop_OF_VERSION_1_1_dup(
        of_queue_prop_t *src);

extern of_queue_prop_header_t *
    of_queue_prop_header_OF_VERSION_1_1_dup(
        of_queue_prop_header_t *src);

extern of_queue_prop_min_rate_t *
    of_queue_prop_min_rate_OF_VERSION_1_1_dup(
        of_queue_prop_min_rate_t *src);

extern of_queue_stats_entry_t *
    of_queue_stats_entry_OF_VERSION_1_1_dup(
        of_queue_stats_entry_t *src);

extern of_table_stats_entry_t *
    of_table_stats_entry_OF_VERSION_1_1_dup(
        of_table_stats_entry_t *src);

extern of_list_action_t *
    of_list_action_OF_VERSION_1_1_dup(
        of_list_action_t *src);

extern of_list_bsn_interface_t *
    of_list_bsn_interface_OF_VERSION_1_1_dup(
        of_list_bsn_interface_t *src);

extern of_list_bucket_t *
    of_list_bucket_OF_VERSION_1_1_dup(
        of_list_bucket_t *src);

extern of_list_bucket_counter_t *
    of_list_bucket_counter_OF_VERSION_1_1_dup(
        of_list_bucket_counter_t *src);

extern of_list_flow_stats_entry_t *
    of_list_flow_stats_entry_OF_VERSION_1_1_dup(
        of_list_flow_stats_entry_t *src);

extern of_list_group_desc_stats_entry_t *
    of_list_group_desc_stats_entry_OF_VERSION_1_1_dup(
        of_list_group_desc_stats_entry_t *src);

extern of_list_group_stats_entry_t *
    of_list_group_stats_entry_OF_VERSION_1_1_dup(
        of_list_group_stats_entry_t *src);

extern of_list_instruction_t *
    of_list_instruction_OF_VERSION_1_1_dup(
        of_list_instruction_t *src);

extern of_list_packet_queue_t *
    of_list_packet_queue_OF_VERSION_1_1_dup(
        of_list_packet_queue_t *src);

extern of_list_port_desc_t *
    of_list_port_desc_OF_VERSION_1_1_dup(
        of_list_port_desc_t *src);

extern of_list_port_stats_entry_t *
    of_list_port_stats_entry_OF_VERSION_1_1_dup(
        of_list_port_stats_entry_t *src);

extern of_list_queue_prop_t *
    of_list_queue_prop_OF_VERSION_1_1_dup(
        of_list_queue_prop_t *src);

extern of_list_queue_stats_entry_t *
    of_list_queue_stats_entry_OF_VERSION_1_1_dup(
        of_list_queue_stats_entry_t *src);

extern of_list_table_stats_entry_t *
    of_list_table_stats_entry_OF_VERSION_1_1_dup(
        of_list_table_stats_entry_t *src);

extern of_aggregate_stats_reply_t *
    of_aggregate_stats_reply_OF_VERSION_1_2_dup(
        of_aggregate_stats_reply_t *src);

extern of_aggregate_stats_request_t *
    of_aggregate_stats_request_OF_VERSION_1_2_dup(
        of_aggregate_stats_request_t *src);

extern of_bad_action_error_msg_t *
    of_bad_action_error_msg_OF_VERSION_1_2_dup(
        of_bad_action_error_msg_t *src);

extern of_bad_instruction_error_msg_t *
    of_bad_instruction_error_msg_OF_VERSION_1_2_dup(
        of_bad_instruction_error_msg_t *src);

extern of_bad_match_error_msg_t *
    of_bad_match_error_msg_OF_VERSION_1_2_dup(
        of_bad_match_error_msg_t *src);

extern of_bad_request_error_msg_t *
    of_bad_request_error_msg_OF_VERSION_1_2_dup(
        of_bad_request_error_msg_t *src);

extern of_barrier_reply_t *
    of_barrier_reply_OF_VERSION_1_2_dup(
        of_barrier_reply_t *src);

extern of_barrier_request_t *
    of_barrier_request_OF_VERSION_1_2_dup(
        of_barrier_request_t *src);

extern of_bsn_bw_clear_data_reply_t *
    of_bsn_bw_clear_data_reply_OF_VERSION_1_2_dup(
        of_bsn_bw_clear_data_reply_t *src);

extern of_bsn_bw_clear_data_request_t *
    of_bsn_bw_clear_data_request_OF_VERSION_1_2_dup(
        of_bsn_bw_clear_data_request_t *src);

extern of_bsn_bw_enable_get_reply_t *
    of_bsn_bw_enable_get_reply_OF_VERSION_1_2_dup(
        of_bsn_bw_enable_get_reply_t *src);

extern of_bsn_bw_enable_get_request_t *
    of_bsn_bw_enable_get_request_OF_VERSION_1_2_dup(
        of_bsn_bw_enable_get_request_t *src);

extern of_bsn_bw_enable_set_reply_t *
    of_bsn_bw_enable_set_reply_OF_VERSION_1_2_dup(
        of_bsn_bw_enable_set_reply_t *src);

extern of_bsn_bw_enable_set_request_t *
    of_bsn_bw_enable_set_request_OF_VERSION_1_2_dup(
        of_bsn_bw_enable_set_request_t *src);

extern of_bsn_get_interfaces_reply_t *
    of_bsn_get_interfaces_reply_OF_VERSION_1_2_dup(
        of_bsn_get_interfaces_reply_t *src);

extern of_bsn_get_interfaces_request_t *
    of_bsn_get_interfaces_request_OF_VERSION_1_2_dup(
        of_bsn_get_interfaces_request_t *src);

extern of_bsn_get_mirroring_reply_t *
    of_bsn_get_mirroring_reply_OF_VERSION_1_2_dup(
        of_bsn_get_mirroring_reply_t *src);

extern of_bsn_get_mirroring_request_t *
    of_bsn_get_mirroring_request_OF_VERSION_1_2_dup(
        of_bsn_get_mirroring_request_t *src);

extern of_bsn_header_t *
    of_bsn_header_OF_VERSION_1_2_dup(
        of_bsn_header_t *src);

extern of_bsn_pdu_rx_reply_t *
    of_bsn_pdu_rx_reply_OF_VERSION_1_2_dup(
        of_bsn_pdu_rx_reply_t *src);

extern of_bsn_pdu_rx_request_t *
    of_bsn_pdu_rx_request_OF_VERSION_1_2_dup(
        of_bsn_pdu_rx_request_t *src);

extern of_bsn_pdu_rx_timeout_t *
    of_bsn_pdu_rx_timeout_OF_VERSION_1_2_dup(
        of_bsn_pdu_rx_timeout_t *src);

extern of_bsn_pdu_tx_reply_t *
    of_bsn_pdu_tx_reply_OF_VERSION_1_2_dup(
        of_bsn_pdu_tx_reply_t *src);

extern of_bsn_pdu_tx_request_t *
    of_bsn_pdu_tx_request_OF_VERSION_1_2_dup(
        of_bsn_pdu_tx_request_t *src);

extern of_bsn_set_mirroring_t *
    of_bsn_set_mirroring_OF_VERSION_1_2_dup(
        of_bsn_set_mirroring_t *src);

extern of_bsn_set_pktin_suppression_reply_t *
    of_bsn_set_pktin_suppression_reply_OF_VERSION_1_2_dup(
        of_bsn_set_pktin_suppression_reply_t *src);

extern of_bsn_set_pktin_suppression_request_t *
    of_bsn_set_pktin_suppression_request_OF_VERSION_1_2_dup(
        of_bsn_set_pktin_suppression_request_t *src);

extern of_bsn_stats_reply_t *
    of_bsn_stats_reply_OF_VERSION_1_2_dup(
        of_bsn_stats_reply_t *src);

extern of_bsn_stats_request_t *
    of_bsn_stats_request_OF_VERSION_1_2_dup(
        of_bsn_stats_request_t *src);

extern of_bsn_virtual_port_create_reply_t *
    of_bsn_virtual_port_create_reply_OF_VERSION_1_2_dup(
        of_bsn_virtual_port_create_reply_t *src);

extern of_bsn_virtual_port_create_request_t *
    of_bsn_virtual_port_create_request_OF_VERSION_1_2_dup(
        of_bsn_virtual_port_create_request_t *src);

extern of_bsn_virtual_port_remove_reply_t *
    of_bsn_virtual_port_remove_reply_OF_VERSION_1_2_dup(
        of_bsn_virtual_port_remove_reply_t *src);

extern of_bsn_virtual_port_remove_request_t *
    of_bsn_virtual_port_remove_request_OF_VERSION_1_2_dup(
        of_bsn_virtual_port_remove_request_t *src);

extern of_desc_stats_reply_t *
    of_desc_stats_reply_OF_VERSION_1_2_dup(
        of_desc_stats_reply_t *src);

extern of_desc_stats_request_t *
    of_desc_stats_request_OF_VERSION_1_2_dup(
        of_desc_stats_request_t *src);

extern of_echo_reply_t *
    of_echo_reply_OF_VERSION_1_2_dup(
        of_echo_reply_t *src);

extern of_echo_request_t *
    of_echo_request_OF_VERSION_1_2_dup(
        of_echo_request_t *src);

extern of_error_msg_t *
    of_error_msg_OF_VERSION_1_2_dup(
        of_error_msg_t *src);

extern of_experimenter_t *
    of_experimenter_OF_VERSION_1_2_dup(
        of_experimenter_t *src);

extern of_experimenter_error_msg_t *
    of_experimenter_error_msg_OF_VERSION_1_2_dup(
        of_experimenter_error_msg_t *src);

extern of_experimenter_stats_reply_t *
    of_experimenter_stats_reply_OF_VERSION_1_2_dup(
        of_experimenter_stats_reply_t *src);

extern of_experimenter_stats_request_t *
    of_experimenter_stats_request_OF_VERSION_1_2_dup(
        of_experimenter_stats_request_t *src);

extern of_features_reply_t *
    of_features_reply_OF_VERSION_1_2_dup(
        of_features_reply_t *src);

extern of_features_request_t *
    of_features_request_OF_VERSION_1_2_dup(
        of_features_request_t *src);

extern of_flow_add_t *
    of_flow_add_OF_VERSION_1_2_dup(
        of_flow_add_t *src);

extern of_flow_delete_t *
    of_flow_delete_OF_VERSION_1_2_dup(
        of_flow_delete_t *src);

extern of_flow_delete_strict_t *
    of_flow_delete_strict_OF_VERSION_1_2_dup(
        of_flow_delete_strict_t *src);

extern of_flow_mod_t *
    of_flow_mod_OF_VERSION_1_2_dup(
        of_flow_mod_t *src);

extern of_flow_mod_failed_error_msg_t *
    of_flow_mod_failed_error_msg_OF_VERSION_1_2_dup(
        of_flow_mod_failed_error_msg_t *src);

extern of_flow_modify_t *
    of_flow_modify_OF_VERSION_1_2_dup(
        of_flow_modify_t *src);

extern of_flow_modify_strict_t *
    of_flow_modify_strict_OF_VERSION_1_2_dup(
        of_flow_modify_strict_t *src);

extern of_flow_removed_t *
    of_flow_removed_OF_VERSION_1_2_dup(
        of_flow_removed_t *src);

extern of_flow_stats_reply_t *
    of_flow_stats_reply_OF_VERSION_1_2_dup(
        of_flow_stats_reply_t *src);

extern of_flow_stats_request_t *
    of_flow_stats_request_OF_VERSION_1_2_dup(
        of_flow_stats_request_t *src);

extern of_get_config_reply_t *
    of_get_config_reply_OF_VERSION_1_2_dup(
        of_get_config_reply_t *src);

extern of_get_config_request_t *
    of_get_config_request_OF_VERSION_1_2_dup(
        of_get_config_request_t *src);

extern of_group_add_t *
    of_group_add_OF_VERSION_1_2_dup(
        of_group_add_t *src);

extern of_group_delete_t *
    of_group_delete_OF_VERSION_1_2_dup(
        of_group_delete_t *src);

extern of_group_desc_stats_reply_t *
    of_group_desc_stats_reply_OF_VERSION_1_2_dup(
        of_group_desc_stats_reply_t *src);

extern of_group_desc_stats_request_t *
    of_group_desc_stats_request_OF_VERSION_1_2_dup(
        of_group_desc_stats_request_t *src);

extern of_group_features_stats_reply_t *
    of_group_features_stats_reply_OF_VERSION_1_2_dup(
        of_group_features_stats_reply_t *src);

extern of_group_features_stats_request_t *
    of_group_features_stats_request_OF_VERSION_1_2_dup(
        of_group_features_stats_request_t *src);

extern of_group_mod_t *
    of_group_mod_OF_VERSION_1_2_dup(
        of_group_mod_t *src);

extern of_group_mod_failed_error_msg_t *
    of_group_mod_failed_error_msg_OF_VERSION_1_2_dup(
        of_group_mod_failed_error_msg_t *src);

extern of_group_modify_t *
    of_group_modify_OF_VERSION_1_2_dup(
        of_group_modify_t *src);

extern of_group_stats_reply_t *
    of_group_stats_reply_OF_VERSION_1_2_dup(
        of_group_stats_reply_t *src);

extern of_group_stats_request_t *
    of_group_stats_request_OF_VERSION_1_2_dup(
        of_group_stats_request_t *src);

extern of_hello_t *
    of_hello_OF_VERSION_1_2_dup(
        of_hello_t *src);

extern of_hello_failed_error_msg_t *
    of_hello_failed_error_msg_OF_VERSION_1_2_dup(
        of_hello_failed_error_msg_t *src);

extern of_nicira_header_t *
    of_nicira_header_OF_VERSION_1_2_dup(
        of_nicira_header_t *src);

extern of_packet_in_t *
    of_packet_in_OF_VERSION_1_2_dup(
        of_packet_in_t *src);

extern of_packet_out_t *
    of_packet_out_OF_VERSION_1_2_dup(
        of_packet_out_t *src);

extern of_port_mod_t *
    of_port_mod_OF_VERSION_1_2_dup(
        of_port_mod_t *src);

extern of_port_mod_failed_error_msg_t *
    of_port_mod_failed_error_msg_OF_VERSION_1_2_dup(
        of_port_mod_failed_error_msg_t *src);

extern of_port_stats_reply_t *
    of_port_stats_reply_OF_VERSION_1_2_dup(
        of_port_stats_reply_t *src);

extern of_port_stats_request_t *
    of_port_stats_request_OF_VERSION_1_2_dup(
        of_port_stats_request_t *src);

extern of_port_status_t *
    of_port_status_OF_VERSION_1_2_dup(
        of_port_status_t *src);

extern of_queue_get_config_reply_t *
    of_queue_get_config_reply_OF_VERSION_1_2_dup(
        of_queue_get_config_reply_t *src);

extern of_queue_get_config_request_t *
    of_queue_get_config_request_OF_VERSION_1_2_dup(
        of_queue_get_config_request_t *src);

extern of_queue_op_failed_error_msg_t *
    of_queue_op_failed_error_msg_OF_VERSION_1_2_dup(
        of_queue_op_failed_error_msg_t *src);

extern of_queue_stats_reply_t *
    of_queue_stats_reply_OF_VERSION_1_2_dup(
        of_queue_stats_reply_t *src);

extern of_queue_stats_request_t *
    of_queue_stats_request_OF_VERSION_1_2_dup(
        of_queue_stats_request_t *src);

extern of_role_reply_t *
    of_role_reply_OF_VERSION_1_2_dup(
        of_role_reply_t *src);

extern of_role_request_t *
    of_role_request_OF_VERSION_1_2_dup(
        of_role_request_t *src);

extern of_role_request_failed_error_msg_t *
    of_role_request_failed_error_msg_OF_VERSION_1_2_dup(
        of_role_request_failed_error_msg_t *src);

extern of_set_config_t *
    of_set_config_OF_VERSION_1_2_dup(
        of_set_config_t *src);

extern of_stats_reply_t *
    of_stats_reply_OF_VERSION_1_2_dup(
        of_stats_reply_t *src);

extern of_stats_request_t *
    of_stats_request_OF_VERSION_1_2_dup(
        of_stats_request_t *src);

extern of_switch_config_failed_error_msg_t *
    of_switch_config_failed_error_msg_OF_VERSION_1_2_dup(
        of_switch_config_failed_error_msg_t *src);

extern of_table_mod_t *
    of_table_mod_OF_VERSION_1_2_dup(
        of_table_mod_t *src);

extern of_table_mod_failed_error_msg_t *
    of_table_mod_failed_error_msg_OF_VERSION_1_2_dup(
        of_table_mod_failed_error_msg_t *src);

extern of_table_stats_reply_t *
    of_table_stats_reply_OF_VERSION_1_2_dup(
        of_table_stats_reply_t *src);

extern of_table_stats_request_t *
    of_table_stats_request_OF_VERSION_1_2_dup(
        of_table_stats_request_t *src);

extern of_action_t *
    of_action_OF_VERSION_1_2_dup(
        of_action_t *src);

extern of_action_bsn_t *
    of_action_bsn_OF_VERSION_1_2_dup(
        of_action_bsn_t *src);

extern of_action_bsn_mirror_t *
    of_action_bsn_mirror_OF_VERSION_1_2_dup(
        of_action_bsn_mirror_t *src);

extern of_action_bsn_set_tunnel_dst_t *
    of_action_bsn_set_tunnel_dst_OF_VERSION_1_2_dup(
        of_action_bsn_set_tunnel_dst_t *src);

extern of_action_copy_ttl_in_t *
    of_action_copy_ttl_in_OF_VERSION_1_2_dup(
        of_action_copy_ttl_in_t *src);

extern of_action_copy_ttl_out_t *
    of_action_copy_ttl_out_OF_VERSION_1_2_dup(
        of_action_copy_ttl_out_t *src);

extern of_action_dec_mpls_ttl_t *
    of_action_dec_mpls_ttl_OF_VERSION_1_2_dup(
        of_action_dec_mpls_ttl_t *src);

extern of_action_dec_nw_ttl_t *
    of_action_dec_nw_ttl_OF_VERSION_1_2_dup(
        of_action_dec_nw_ttl_t *src);

extern of_action_experimenter_t *
    of_action_experimenter_OF_VERSION_1_2_dup(
        of_action_experimenter_t *src);

extern of_action_group_t *
    of_action_group_OF_VERSION_1_2_dup(
        of_action_group_t *src);

extern of_action_header_t *
    of_action_header_OF_VERSION_1_2_dup(
        of_action_header_t *src);

extern of_action_nicira_t *
    of_action_nicira_OF_VERSION_1_2_dup(
        of_action_nicira_t *src);

extern of_action_nicira_dec_ttl_t *
    of_action_nicira_dec_ttl_OF_VERSION_1_2_dup(
        of_action_nicira_dec_ttl_t *src);

extern of_action_output_t *
    of_action_output_OF_VERSION_1_2_dup(
        of_action_output_t *src);

extern of_action_pop_mpls_t *
    of_action_pop_mpls_OF_VERSION_1_2_dup(
        of_action_pop_mpls_t *src);

extern of_action_pop_vlan_t *
    of_action_pop_vlan_OF_VERSION_1_2_dup(
        of_action_pop_vlan_t *src);

extern of_action_push_mpls_t *
    of_action_push_mpls_OF_VERSION_1_2_dup(
        of_action_push_mpls_t *src);

extern of_action_push_vlan_t *
    of_action_push_vlan_OF_VERSION_1_2_dup(
        of_action_push_vlan_t *src);

extern of_action_set_field_t *
    of_action_set_field_OF_VERSION_1_2_dup(
        of_action_set_field_t *src);

extern of_action_set_mpls_ttl_t *
    of_action_set_mpls_ttl_OF_VERSION_1_2_dup(
        of_action_set_mpls_ttl_t *src);

extern of_action_set_nw_ttl_t *
    of_action_set_nw_ttl_OF_VERSION_1_2_dup(
        of_action_set_nw_ttl_t *src);

extern of_action_set_queue_t *
    of_action_set_queue_OF_VERSION_1_2_dup(
        of_action_set_queue_t *src);

extern of_bsn_interface_t *
    of_bsn_interface_OF_VERSION_1_2_dup(
        of_bsn_interface_t *src);

extern of_bsn_vport_t *
    of_bsn_vport_OF_VERSION_1_2_dup(
        of_bsn_vport_t *src);

extern of_bsn_vport_header_t *
    of_bsn_vport_header_OF_VERSION_1_2_dup(
        of_bsn_vport_header_t *src);

extern of_bsn_vport_q_in_q_t *
    of_bsn_vport_q_in_q_OF_VERSION_1_2_dup(
        of_bsn_vport_q_in_q_t *src);

extern of_bucket_t *
    of_bucket_OF_VERSION_1_2_dup(
        of_bucket_t *src);

extern of_bucket_counter_t *
    of_bucket_counter_OF_VERSION_1_2_dup(
        of_bucket_counter_t *src);

extern of_flow_stats_entry_t *
    of_flow_stats_entry_OF_VERSION_1_2_dup(
        of_flow_stats_entry_t *src);

extern of_group_desc_stats_entry_t *
    of_group_desc_stats_entry_OF_VERSION_1_2_dup(
        of_group_desc_stats_entry_t *src);

extern of_group_stats_entry_t *
    of_group_stats_entry_OF_VERSION_1_2_dup(
        of_group_stats_entry_t *src);

extern of_header_t *
    of_header_OF_VERSION_1_2_dup(
        of_header_t *src);

extern of_instruction_t *
    of_instruction_OF_VERSION_1_2_dup(
        of_instruction_t *src);

extern of_instruction_apply_actions_t *
    of_instruction_apply_actions_OF_VERSION_1_2_dup(
        of_instruction_apply_actions_t *src);

extern of_instruction_clear_actions_t *
    of_instruction_clear_actions_OF_VERSION_1_2_dup(
        of_instruction_clear_actions_t *src);

extern of_instruction_experimenter_t *
    of_instruction_experimenter_OF_VERSION_1_2_dup(
        of_instruction_experimenter_t *src);

extern of_instruction_goto_table_t *
    of_instruction_goto_table_OF_VERSION_1_2_dup(
        of_instruction_goto_table_t *src);

extern of_instruction_header_t *
    of_instruction_header_OF_VERSION_1_2_dup(
        of_instruction_header_t *src);

extern of_instruction_write_actions_t *
    of_instruction_write_actions_OF_VERSION_1_2_dup(
        of_instruction_write_actions_t *src);

extern of_instruction_write_metadata_t *
    of_instruction_write_metadata_OF_VERSION_1_2_dup(
        of_instruction_write_metadata_t *src);

extern of_match_v3_t *
    of_match_v3_OF_VERSION_1_2_dup(
        of_match_v3_t *src);

extern of_oxm_t *
    of_oxm_OF_VERSION_1_2_dup(
        of_oxm_t *src);

extern of_oxm_arp_op_t *
    of_oxm_arp_op_OF_VERSION_1_2_dup(
        of_oxm_arp_op_t *src);

extern of_oxm_arp_op_masked_t *
    of_oxm_arp_op_masked_OF_VERSION_1_2_dup(
        of_oxm_arp_op_masked_t *src);

extern of_oxm_arp_sha_t *
    of_oxm_arp_sha_OF_VERSION_1_2_dup(
        of_oxm_arp_sha_t *src);

extern of_oxm_arp_sha_masked_t *
    of_oxm_arp_sha_masked_OF_VERSION_1_2_dup(
        of_oxm_arp_sha_masked_t *src);

extern of_oxm_arp_spa_t *
    of_oxm_arp_spa_OF_VERSION_1_2_dup(
        of_oxm_arp_spa_t *src);

extern of_oxm_arp_spa_masked_t *
    of_oxm_arp_spa_masked_OF_VERSION_1_2_dup(
        of_oxm_arp_spa_masked_t *src);

extern of_oxm_arp_tha_t *
    of_oxm_arp_tha_OF_VERSION_1_2_dup(
        of_oxm_arp_tha_t *src);

extern of_oxm_arp_tha_masked_t *
    of_oxm_arp_tha_masked_OF_VERSION_1_2_dup(
        of_oxm_arp_tha_masked_t *src);

extern of_oxm_arp_tpa_t *
    of_oxm_arp_tpa_OF_VERSION_1_2_dup(
        of_oxm_arp_tpa_t *src);

extern of_oxm_arp_tpa_masked_t *
    of_oxm_arp_tpa_masked_OF_VERSION_1_2_dup(
        of_oxm_arp_tpa_masked_t *src);

extern of_oxm_bsn_global_vrf_allowed_t *
    of_oxm_bsn_global_vrf_allowed_OF_VERSION_1_2_dup(
        of_oxm_bsn_global_vrf_allowed_t *src);

extern of_oxm_bsn_global_vrf_allowed_masked_t *
    of_oxm_bsn_global_vrf_allowed_masked_OF_VERSION_1_2_dup(
        of_oxm_bsn_global_vrf_allowed_masked_t *src);

extern of_oxm_bsn_in_ports_128_t *
    of_oxm_bsn_in_ports_128_OF_VERSION_1_2_dup(
        of_oxm_bsn_in_ports_128_t *src);

extern of_oxm_bsn_in_ports_128_masked_t *
    of_oxm_bsn_in_ports_128_masked_OF_VERSION_1_2_dup(
        of_oxm_bsn_in_ports_128_masked_t *src);

extern of_oxm_bsn_l3_dst_class_id_t *
    of_oxm_bsn_l3_dst_class_id_OF_VERSION_1_2_dup(
        of_oxm_bsn_l3_dst_class_id_t *src);

extern of_oxm_bsn_l3_dst_class_id_masked_t *
    of_oxm_bsn_l3_dst_class_id_masked_OF_VERSION_1_2_dup(
        of_oxm_bsn_l3_dst_class_id_masked_t *src);

extern of_oxm_bsn_l3_interface_class_id_t *
    of_oxm_bsn_l3_interface_class_id_OF_VERSION_1_2_dup(
        of_oxm_bsn_l3_interface_class_id_t *src);

extern of_oxm_bsn_l3_interface_class_id_masked_t *
    of_oxm_bsn_l3_interface_class_id_masked_OF_VERSION_1_2_dup(
        of_oxm_bsn_l3_interface_class_id_masked_t *src);

extern of_oxm_bsn_l3_src_class_id_t *
    of_oxm_bsn_l3_src_class_id_OF_VERSION_1_2_dup(
        of_oxm_bsn_l3_src_class_id_t *src);

extern of_oxm_bsn_l3_src_class_id_masked_t *
    of_oxm_bsn_l3_src_class_id_masked_OF_VERSION_1_2_dup(
        of_oxm_bsn_l3_src_class_id_masked_t *src);

extern of_oxm_bsn_lag_id_t *
    of_oxm_bsn_lag_id_OF_VERSION_1_2_dup(
        of_oxm_bsn_lag_id_t *src);

extern of_oxm_bsn_lag_id_masked_t *
    of_oxm_bsn_lag_id_masked_OF_VERSION_1_2_dup(
        of_oxm_bsn_lag_id_masked_t *src);

extern of_oxm_bsn_vrf_t *
    of_oxm_bsn_vrf_OF_VERSION_1_2_dup(
        of_oxm_bsn_vrf_t *src);

extern of_oxm_bsn_vrf_masked_t *
    of_oxm_bsn_vrf_masked_OF_VERSION_1_2_dup(
        of_oxm_bsn_vrf_masked_t *src);

extern of_oxm_eth_dst_t *
    of_oxm_eth_dst_OF_VERSION_1_2_dup(
        of_oxm_eth_dst_t *src);

extern of_oxm_eth_dst_masked_t *
    of_oxm_eth_dst_masked_OF_VERSION_1_2_dup(
        of_oxm_eth_dst_masked_t *src);

extern of_oxm_eth_src_t *
    of_oxm_eth_src_OF_VERSION_1_2_dup(
        of_oxm_eth_src_t *src);

extern of_oxm_eth_src_masked_t *
    of_oxm_eth_src_masked_OF_VERSION_1_2_dup(
        of_oxm_eth_src_masked_t *src);

extern of_oxm_eth_type_t *
    of_oxm_eth_type_OF_VERSION_1_2_dup(
        of_oxm_eth_type_t *src);

extern of_oxm_eth_type_masked_t *
    of_oxm_eth_type_masked_OF_VERSION_1_2_dup(
        of_oxm_eth_type_masked_t *src);

extern of_oxm_header_t *
    of_oxm_header_OF_VERSION_1_2_dup(
        of_oxm_header_t *src);

extern of_oxm_icmpv4_code_t *
    of_oxm_icmpv4_code_OF_VERSION_1_2_dup(
        of_oxm_icmpv4_code_t *src);

extern of_oxm_icmpv4_code_masked_t *
    of_oxm_icmpv4_code_masked_OF_VERSION_1_2_dup(
        of_oxm_icmpv4_code_masked_t *src);

extern of_oxm_icmpv4_type_t *
    of_oxm_icmpv4_type_OF_VERSION_1_2_dup(
        of_oxm_icmpv4_type_t *src);

extern of_oxm_icmpv4_type_masked_t *
    of_oxm_icmpv4_type_masked_OF_VERSION_1_2_dup(
        of_oxm_icmpv4_type_masked_t *src);

extern of_oxm_icmpv6_code_t *
    of_oxm_icmpv6_code_OF_VERSION_1_2_dup(
        of_oxm_icmpv6_code_t *src);

extern of_oxm_icmpv6_code_masked_t *
    of_oxm_icmpv6_code_masked_OF_VERSION_1_2_dup(
        of_oxm_icmpv6_code_masked_t *src);

extern of_oxm_icmpv6_type_t *
    of_oxm_icmpv6_type_OF_VERSION_1_2_dup(
        of_oxm_icmpv6_type_t *src);

extern of_oxm_icmpv6_type_masked_t *
    of_oxm_icmpv6_type_masked_OF_VERSION_1_2_dup(
        of_oxm_icmpv6_type_masked_t *src);

extern of_oxm_in_phy_port_t *
    of_oxm_in_phy_port_OF_VERSION_1_2_dup(
        of_oxm_in_phy_port_t *src);

extern of_oxm_in_phy_port_masked_t *
    of_oxm_in_phy_port_masked_OF_VERSION_1_2_dup(
        of_oxm_in_phy_port_masked_t *src);

extern of_oxm_in_port_t *
    of_oxm_in_port_OF_VERSION_1_2_dup(
        of_oxm_in_port_t *src);

extern of_oxm_in_port_masked_t *
    of_oxm_in_port_masked_OF_VERSION_1_2_dup(
        of_oxm_in_port_masked_t *src);

extern of_oxm_ip_dscp_t *
    of_oxm_ip_dscp_OF_VERSION_1_2_dup(
        of_oxm_ip_dscp_t *src);

extern of_oxm_ip_dscp_masked_t *
    of_oxm_ip_dscp_masked_OF_VERSION_1_2_dup(
        of_oxm_ip_dscp_masked_t *src);

extern of_oxm_ip_ecn_t *
    of_oxm_ip_ecn_OF_VERSION_1_2_dup(
        of_oxm_ip_ecn_t *src);

extern of_oxm_ip_ecn_masked_t *
    of_oxm_ip_ecn_masked_OF_VERSION_1_2_dup(
        of_oxm_ip_ecn_masked_t *src);

extern of_oxm_ip_proto_t *
    of_oxm_ip_proto_OF_VERSION_1_2_dup(
        of_oxm_ip_proto_t *src);

extern of_oxm_ip_proto_masked_t *
    of_oxm_ip_proto_masked_OF_VERSION_1_2_dup(
        of_oxm_ip_proto_masked_t *src);

extern of_oxm_ipv4_dst_t *
    of_oxm_ipv4_dst_OF_VERSION_1_2_dup(
        of_oxm_ipv4_dst_t *src);

extern of_oxm_ipv4_dst_masked_t *
    of_oxm_ipv4_dst_masked_OF_VERSION_1_2_dup(
        of_oxm_ipv4_dst_masked_t *src);

extern of_oxm_ipv4_src_t *
    of_oxm_ipv4_src_OF_VERSION_1_2_dup(
        of_oxm_ipv4_src_t *src);

extern of_oxm_ipv4_src_masked_t *
    of_oxm_ipv4_src_masked_OF_VERSION_1_2_dup(
        of_oxm_ipv4_src_masked_t *src);

extern of_oxm_ipv6_dst_t *
    of_oxm_ipv6_dst_OF_VERSION_1_2_dup(
        of_oxm_ipv6_dst_t *src);

extern of_oxm_ipv6_dst_masked_t *
    of_oxm_ipv6_dst_masked_OF_VERSION_1_2_dup(
        of_oxm_ipv6_dst_masked_t *src);

extern of_oxm_ipv6_flabel_t *
    of_oxm_ipv6_flabel_OF_VERSION_1_2_dup(
        of_oxm_ipv6_flabel_t *src);

extern of_oxm_ipv6_flabel_masked_t *
    of_oxm_ipv6_flabel_masked_OF_VERSION_1_2_dup(
        of_oxm_ipv6_flabel_masked_t *src);

extern of_oxm_ipv6_nd_sll_t *
    of_oxm_ipv6_nd_sll_OF_VERSION_1_2_dup(
        of_oxm_ipv6_nd_sll_t *src);

extern of_oxm_ipv6_nd_sll_masked_t *
    of_oxm_ipv6_nd_sll_masked_OF_VERSION_1_2_dup(
        of_oxm_ipv6_nd_sll_masked_t *src);

extern of_oxm_ipv6_nd_target_t *
    of_oxm_ipv6_nd_target_OF_VERSION_1_2_dup(
        of_oxm_ipv6_nd_target_t *src);

extern of_oxm_ipv6_nd_target_masked_t *
    of_oxm_ipv6_nd_target_masked_OF_VERSION_1_2_dup(
        of_oxm_ipv6_nd_target_masked_t *src);

extern of_oxm_ipv6_nd_tll_t *
    of_oxm_ipv6_nd_tll_OF_VERSION_1_2_dup(
        of_oxm_ipv6_nd_tll_t *src);

extern of_oxm_ipv6_nd_tll_masked_t *
    of_oxm_ipv6_nd_tll_masked_OF_VERSION_1_2_dup(
        of_oxm_ipv6_nd_tll_masked_t *src);

extern of_oxm_ipv6_src_t *
    of_oxm_ipv6_src_OF_VERSION_1_2_dup(
        of_oxm_ipv6_src_t *src);

extern of_oxm_ipv6_src_masked_t *
    of_oxm_ipv6_src_masked_OF_VERSION_1_2_dup(
        of_oxm_ipv6_src_masked_t *src);

extern of_oxm_metadata_t *
    of_oxm_metadata_OF_VERSION_1_2_dup(
        of_oxm_metadata_t *src);

extern of_oxm_metadata_masked_t *
    of_oxm_metadata_masked_OF_VERSION_1_2_dup(
        of_oxm_metadata_masked_t *src);

extern of_oxm_mpls_label_t *
    of_oxm_mpls_label_OF_VERSION_1_2_dup(
        of_oxm_mpls_label_t *src);

extern of_oxm_mpls_label_masked_t *
    of_oxm_mpls_label_masked_OF_VERSION_1_2_dup(
        of_oxm_mpls_label_masked_t *src);

extern of_oxm_mpls_tc_t *
    of_oxm_mpls_tc_OF_VERSION_1_2_dup(
        of_oxm_mpls_tc_t *src);

extern of_oxm_mpls_tc_masked_t *
    of_oxm_mpls_tc_masked_OF_VERSION_1_2_dup(
        of_oxm_mpls_tc_masked_t *src);

extern of_oxm_sctp_dst_t *
    of_oxm_sctp_dst_OF_VERSION_1_2_dup(
        of_oxm_sctp_dst_t *src);

extern of_oxm_sctp_dst_masked_t *
    of_oxm_sctp_dst_masked_OF_VERSION_1_2_dup(
        of_oxm_sctp_dst_masked_t *src);

extern of_oxm_sctp_src_t *
    of_oxm_sctp_src_OF_VERSION_1_2_dup(
        of_oxm_sctp_src_t *src);

extern of_oxm_sctp_src_masked_t *
    of_oxm_sctp_src_masked_OF_VERSION_1_2_dup(
        of_oxm_sctp_src_masked_t *src);

extern of_oxm_tcp_dst_t *
    of_oxm_tcp_dst_OF_VERSION_1_2_dup(
        of_oxm_tcp_dst_t *src);

extern of_oxm_tcp_dst_masked_t *
    of_oxm_tcp_dst_masked_OF_VERSION_1_2_dup(
        of_oxm_tcp_dst_masked_t *src);

extern of_oxm_tcp_src_t *
    of_oxm_tcp_src_OF_VERSION_1_2_dup(
        of_oxm_tcp_src_t *src);

extern of_oxm_tcp_src_masked_t *
    of_oxm_tcp_src_masked_OF_VERSION_1_2_dup(
        of_oxm_tcp_src_masked_t *src);

extern of_oxm_udp_dst_t *
    of_oxm_udp_dst_OF_VERSION_1_2_dup(
        of_oxm_udp_dst_t *src);

extern of_oxm_udp_dst_masked_t *
    of_oxm_udp_dst_masked_OF_VERSION_1_2_dup(
        of_oxm_udp_dst_masked_t *src);

extern of_oxm_udp_src_t *
    of_oxm_udp_src_OF_VERSION_1_2_dup(
        of_oxm_udp_src_t *src);

extern of_oxm_udp_src_masked_t *
    of_oxm_udp_src_masked_OF_VERSION_1_2_dup(
        of_oxm_udp_src_masked_t *src);

extern of_oxm_vlan_pcp_t *
    of_oxm_vlan_pcp_OF_VERSION_1_2_dup(
        of_oxm_vlan_pcp_t *src);

extern of_oxm_vlan_pcp_masked_t *
    of_oxm_vlan_pcp_masked_OF_VERSION_1_2_dup(
        of_oxm_vlan_pcp_masked_t *src);

extern of_oxm_vlan_vid_t *
    of_oxm_vlan_vid_OF_VERSION_1_2_dup(
        of_oxm_vlan_vid_t *src);

extern of_oxm_vlan_vid_masked_t *
    of_oxm_vlan_vid_masked_OF_VERSION_1_2_dup(
        of_oxm_vlan_vid_masked_t *src);

extern of_packet_queue_t *
    of_packet_queue_OF_VERSION_1_2_dup(
        of_packet_queue_t *src);

extern of_port_desc_t *
    of_port_desc_OF_VERSION_1_2_dup(
        of_port_desc_t *src);

extern of_port_stats_entry_t *
    of_port_stats_entry_OF_VERSION_1_2_dup(
        of_port_stats_entry_t *src);

extern of_queue_prop_t *
    of_queue_prop_OF_VERSION_1_2_dup(
        of_queue_prop_t *src);

extern of_queue_prop_experimenter_t *
    of_queue_prop_experimenter_OF_VERSION_1_2_dup(
        of_queue_prop_experimenter_t *src);

extern of_queue_prop_header_t *
    of_queue_prop_header_OF_VERSION_1_2_dup(
        of_queue_prop_header_t *src);

extern of_queue_prop_max_rate_t *
    of_queue_prop_max_rate_OF_VERSION_1_2_dup(
        of_queue_prop_max_rate_t *src);

extern of_queue_prop_min_rate_t *
    of_queue_prop_min_rate_OF_VERSION_1_2_dup(
        of_queue_prop_min_rate_t *src);

extern of_queue_stats_entry_t *
    of_queue_stats_entry_OF_VERSION_1_2_dup(
        of_queue_stats_entry_t *src);

extern of_table_stats_entry_t *
    of_table_stats_entry_OF_VERSION_1_2_dup(
        of_table_stats_entry_t *src);

extern of_list_action_t *
    of_list_action_OF_VERSION_1_2_dup(
        of_list_action_t *src);

extern of_list_bsn_interface_t *
    of_list_bsn_interface_OF_VERSION_1_2_dup(
        of_list_bsn_interface_t *src);

extern of_list_bucket_t *
    of_list_bucket_OF_VERSION_1_2_dup(
        of_list_bucket_t *src);

extern of_list_bucket_counter_t *
    of_list_bucket_counter_OF_VERSION_1_2_dup(
        of_list_bucket_counter_t *src);

extern of_list_flow_stats_entry_t *
    of_list_flow_stats_entry_OF_VERSION_1_2_dup(
        of_list_flow_stats_entry_t *src);

extern of_list_group_desc_stats_entry_t *
    of_list_group_desc_stats_entry_OF_VERSION_1_2_dup(
        of_list_group_desc_stats_entry_t *src);

extern of_list_group_stats_entry_t *
    of_list_group_stats_entry_OF_VERSION_1_2_dup(
        of_list_group_stats_entry_t *src);

extern of_list_instruction_t *
    of_list_instruction_OF_VERSION_1_2_dup(
        of_list_instruction_t *src);

extern of_list_oxm_t *
    of_list_oxm_OF_VERSION_1_2_dup(
        of_list_oxm_t *src);

extern of_list_packet_queue_t *
    of_list_packet_queue_OF_VERSION_1_2_dup(
        of_list_packet_queue_t *src);

extern of_list_port_desc_t *
    of_list_port_desc_OF_VERSION_1_2_dup(
        of_list_port_desc_t *src);

extern of_list_port_stats_entry_t *
    of_list_port_stats_entry_OF_VERSION_1_2_dup(
        of_list_port_stats_entry_t *src);

extern of_list_queue_prop_t *
    of_list_queue_prop_OF_VERSION_1_2_dup(
        of_list_queue_prop_t *src);

extern of_list_queue_stats_entry_t *
    of_list_queue_stats_entry_OF_VERSION_1_2_dup(
        of_list_queue_stats_entry_t *src);

extern of_list_table_stats_entry_t *
    of_list_table_stats_entry_OF_VERSION_1_2_dup(
        of_list_table_stats_entry_t *src);

extern of_aggregate_stats_reply_t *
    of_aggregate_stats_reply_OF_VERSION_1_3_dup(
        of_aggregate_stats_reply_t *src);

extern of_aggregate_stats_request_t *
    of_aggregate_stats_request_OF_VERSION_1_3_dup(
        of_aggregate_stats_request_t *src);

extern of_async_get_reply_t *
    of_async_get_reply_OF_VERSION_1_3_dup(
        of_async_get_reply_t *src);

extern of_async_get_request_t *
    of_async_get_request_OF_VERSION_1_3_dup(
        of_async_get_request_t *src);

extern of_async_set_t *
    of_async_set_OF_VERSION_1_3_dup(
        of_async_set_t *src);

extern of_bad_action_error_msg_t *
    of_bad_action_error_msg_OF_VERSION_1_3_dup(
        of_bad_action_error_msg_t *src);

extern of_bad_instruction_error_msg_t *
    of_bad_instruction_error_msg_OF_VERSION_1_3_dup(
        of_bad_instruction_error_msg_t *src);

extern of_bad_match_error_msg_t *
    of_bad_match_error_msg_OF_VERSION_1_3_dup(
        of_bad_match_error_msg_t *src);

extern of_bad_request_error_msg_t *
    of_bad_request_error_msg_OF_VERSION_1_3_dup(
        of_bad_request_error_msg_t *src);

extern of_barrier_reply_t *
    of_barrier_reply_OF_VERSION_1_3_dup(
        of_barrier_reply_t *src);

extern of_barrier_request_t *
    of_barrier_request_OF_VERSION_1_3_dup(
        of_barrier_request_t *src);

extern of_bsn_bw_clear_data_reply_t *
    of_bsn_bw_clear_data_reply_OF_VERSION_1_3_dup(
        of_bsn_bw_clear_data_reply_t *src);

extern of_bsn_bw_clear_data_request_t *
    of_bsn_bw_clear_data_request_OF_VERSION_1_3_dup(
        of_bsn_bw_clear_data_request_t *src);

extern of_bsn_bw_enable_get_reply_t *
    of_bsn_bw_enable_get_reply_OF_VERSION_1_3_dup(
        of_bsn_bw_enable_get_reply_t *src);

extern of_bsn_bw_enable_get_request_t *
    of_bsn_bw_enable_get_request_OF_VERSION_1_3_dup(
        of_bsn_bw_enable_get_request_t *src);

extern of_bsn_bw_enable_set_reply_t *
    of_bsn_bw_enable_set_reply_OF_VERSION_1_3_dup(
        of_bsn_bw_enable_set_reply_t *src);

extern of_bsn_bw_enable_set_request_t *
    of_bsn_bw_enable_set_request_OF_VERSION_1_3_dup(
        of_bsn_bw_enable_set_request_t *src);

extern of_bsn_flow_idle_t *
    of_bsn_flow_idle_OF_VERSION_1_3_dup(
        of_bsn_flow_idle_t *src);

extern of_bsn_flow_idle_enable_get_reply_t *
    of_bsn_flow_idle_enable_get_reply_OF_VERSION_1_3_dup(
        of_bsn_flow_idle_enable_get_reply_t *src);

extern of_bsn_flow_idle_enable_get_request_t *
    of_bsn_flow_idle_enable_get_request_OF_VERSION_1_3_dup(
        of_bsn_flow_idle_enable_get_request_t *src);

extern of_bsn_flow_idle_enable_set_reply_t *
    of_bsn_flow_idle_enable_set_reply_OF_VERSION_1_3_dup(
        of_bsn_flow_idle_enable_set_reply_t *src);

extern of_bsn_flow_idle_enable_set_request_t *
    of_bsn_flow_idle_enable_set_request_OF_VERSION_1_3_dup(
        of_bsn_flow_idle_enable_set_request_t *src);

extern of_bsn_get_interfaces_reply_t *
    of_bsn_get_interfaces_reply_OF_VERSION_1_3_dup(
        of_bsn_get_interfaces_reply_t *src);

extern of_bsn_get_interfaces_request_t *
    of_bsn_get_interfaces_request_OF_VERSION_1_3_dup(
        of_bsn_get_interfaces_request_t *src);

extern of_bsn_get_mirroring_reply_t *
    of_bsn_get_mirroring_reply_OF_VERSION_1_3_dup(
        of_bsn_get_mirroring_reply_t *src);

extern of_bsn_get_mirroring_request_t *
    of_bsn_get_mirroring_request_OF_VERSION_1_3_dup(
        of_bsn_get_mirroring_request_t *src);

extern of_bsn_get_switch_pipeline_reply_t *
    of_bsn_get_switch_pipeline_reply_OF_VERSION_1_3_dup(
        of_bsn_get_switch_pipeline_reply_t *src);

extern of_bsn_get_switch_pipeline_request_t *
    of_bsn_get_switch_pipeline_request_OF_VERSION_1_3_dup(
        of_bsn_get_switch_pipeline_request_t *src);

extern of_bsn_header_t *
    of_bsn_header_OF_VERSION_1_3_dup(
        of_bsn_header_t *src);

extern of_bsn_lacp_convergence_notif_t *
    of_bsn_lacp_convergence_notif_OF_VERSION_1_3_dup(
        of_bsn_lacp_convergence_notif_t *src);

extern of_bsn_lacp_stats_reply_t *
    of_bsn_lacp_stats_reply_OF_VERSION_1_3_dup(
        of_bsn_lacp_stats_reply_t *src);

extern of_bsn_lacp_stats_request_t *
    of_bsn_lacp_stats_request_OF_VERSION_1_3_dup(
        of_bsn_lacp_stats_request_t *src);

extern of_bsn_pdu_rx_reply_t *
    of_bsn_pdu_rx_reply_OF_VERSION_1_3_dup(
        of_bsn_pdu_rx_reply_t *src);

extern of_bsn_pdu_rx_request_t *
    of_bsn_pdu_rx_request_OF_VERSION_1_3_dup(
        of_bsn_pdu_rx_request_t *src);

extern of_bsn_pdu_rx_timeout_t *
    of_bsn_pdu_rx_timeout_OF_VERSION_1_3_dup(
        of_bsn_pdu_rx_timeout_t *src);

extern of_bsn_pdu_tx_reply_t *
    of_bsn_pdu_tx_reply_OF_VERSION_1_3_dup(
        of_bsn_pdu_tx_reply_t *src);

extern of_bsn_pdu_tx_request_t *
    of_bsn_pdu_tx_request_OF_VERSION_1_3_dup(
        of_bsn_pdu_tx_request_t *src);

extern of_bsn_port_counter_stats_reply_t *
    of_bsn_port_counter_stats_reply_OF_VERSION_1_3_dup(
        of_bsn_port_counter_stats_reply_t *src);

extern of_bsn_port_counter_stats_request_t *
    of_bsn_port_counter_stats_request_OF_VERSION_1_3_dup(
        of_bsn_port_counter_stats_request_t *src);

extern of_bsn_set_lacp_reply_t *
    of_bsn_set_lacp_reply_OF_VERSION_1_3_dup(
        of_bsn_set_lacp_reply_t *src);

extern of_bsn_set_lacp_request_t *
    of_bsn_set_lacp_request_OF_VERSION_1_3_dup(
        of_bsn_set_lacp_request_t *src);

extern of_bsn_set_mirroring_t *
    of_bsn_set_mirroring_OF_VERSION_1_3_dup(
        of_bsn_set_mirroring_t *src);

extern of_bsn_set_pktin_suppression_reply_t *
    of_bsn_set_pktin_suppression_reply_OF_VERSION_1_3_dup(
        of_bsn_set_pktin_suppression_reply_t *src);

extern of_bsn_set_pktin_suppression_request_t *
    of_bsn_set_pktin_suppression_request_OF_VERSION_1_3_dup(
        of_bsn_set_pktin_suppression_request_t *src);

extern of_bsn_set_switch_pipeline_reply_t *
    of_bsn_set_switch_pipeline_reply_OF_VERSION_1_3_dup(
        of_bsn_set_switch_pipeline_reply_t *src);

extern of_bsn_set_switch_pipeline_request_t *
    of_bsn_set_switch_pipeline_request_OF_VERSION_1_3_dup(
        of_bsn_set_switch_pipeline_request_t *src);

extern of_bsn_stats_reply_t *
    of_bsn_stats_reply_OF_VERSION_1_3_dup(
        of_bsn_stats_reply_t *src);

extern of_bsn_stats_request_t *
    of_bsn_stats_request_OF_VERSION_1_3_dup(
        of_bsn_stats_request_t *src);

extern of_bsn_switch_pipeline_stats_reply_t *
    of_bsn_switch_pipeline_stats_reply_OF_VERSION_1_3_dup(
        of_bsn_switch_pipeline_stats_reply_t *src);

extern of_bsn_switch_pipeline_stats_request_t *
    of_bsn_switch_pipeline_stats_request_OF_VERSION_1_3_dup(
        of_bsn_switch_pipeline_stats_request_t *src);

extern of_bsn_time_reply_t *
    of_bsn_time_reply_OF_VERSION_1_3_dup(
        of_bsn_time_reply_t *src);

extern of_bsn_time_request_t *
    of_bsn_time_request_OF_VERSION_1_3_dup(
        of_bsn_time_request_t *src);

extern of_bsn_virtual_port_create_reply_t *
    of_bsn_virtual_port_create_reply_OF_VERSION_1_3_dup(
        of_bsn_virtual_port_create_reply_t *src);

extern of_bsn_virtual_port_create_request_t *
    of_bsn_virtual_port_create_request_OF_VERSION_1_3_dup(
        of_bsn_virtual_port_create_request_t *src);

extern of_bsn_virtual_port_remove_reply_t *
    of_bsn_virtual_port_remove_reply_OF_VERSION_1_3_dup(
        of_bsn_virtual_port_remove_reply_t *src);

extern of_bsn_virtual_port_remove_request_t *
    of_bsn_virtual_port_remove_request_OF_VERSION_1_3_dup(
        of_bsn_virtual_port_remove_request_t *src);

extern of_bsn_vlan_counter_stats_reply_t *
    of_bsn_vlan_counter_stats_reply_OF_VERSION_1_3_dup(
        of_bsn_vlan_counter_stats_reply_t *src);

extern of_bsn_vlan_counter_stats_request_t *
    of_bsn_vlan_counter_stats_request_OF_VERSION_1_3_dup(
        of_bsn_vlan_counter_stats_request_t *src);

extern of_desc_stats_reply_t *
    of_desc_stats_reply_OF_VERSION_1_3_dup(
        of_desc_stats_reply_t *src);

extern of_desc_stats_request_t *
    of_desc_stats_request_OF_VERSION_1_3_dup(
        of_desc_stats_request_t *src);

extern of_echo_reply_t *
    of_echo_reply_OF_VERSION_1_3_dup(
        of_echo_reply_t *src);

extern of_echo_request_t *
    of_echo_request_OF_VERSION_1_3_dup(
        of_echo_request_t *src);

extern of_error_msg_t *
    of_error_msg_OF_VERSION_1_3_dup(
        of_error_msg_t *src);

extern of_experimenter_t *
    of_experimenter_OF_VERSION_1_3_dup(
        of_experimenter_t *src);

extern of_experimenter_error_msg_t *
    of_experimenter_error_msg_OF_VERSION_1_3_dup(
        of_experimenter_error_msg_t *src);

extern of_experimenter_stats_reply_t *
    of_experimenter_stats_reply_OF_VERSION_1_3_dup(
        of_experimenter_stats_reply_t *src);

extern of_experimenter_stats_request_t *
    of_experimenter_stats_request_OF_VERSION_1_3_dup(
        of_experimenter_stats_request_t *src);

extern of_features_reply_t *
    of_features_reply_OF_VERSION_1_3_dup(
        of_features_reply_t *src);

extern of_features_request_t *
    of_features_request_OF_VERSION_1_3_dup(
        of_features_request_t *src);

extern of_flow_add_t *
    of_flow_add_OF_VERSION_1_3_dup(
        of_flow_add_t *src);

extern of_flow_delete_t *
    of_flow_delete_OF_VERSION_1_3_dup(
        of_flow_delete_t *src);

extern of_flow_delete_strict_t *
    of_flow_delete_strict_OF_VERSION_1_3_dup(
        of_flow_delete_strict_t *src);

extern of_flow_mod_t *
    of_flow_mod_OF_VERSION_1_3_dup(
        of_flow_mod_t *src);

extern of_flow_mod_failed_error_msg_t *
    of_flow_mod_failed_error_msg_OF_VERSION_1_3_dup(
        of_flow_mod_failed_error_msg_t *src);

extern of_flow_modify_t *
    of_flow_modify_OF_VERSION_1_3_dup(
        of_flow_modify_t *src);

extern of_flow_modify_strict_t *
    of_flow_modify_strict_OF_VERSION_1_3_dup(
        of_flow_modify_strict_t *src);

extern of_flow_removed_t *
    of_flow_removed_OF_VERSION_1_3_dup(
        of_flow_removed_t *src);

extern of_flow_stats_reply_t *
    of_flow_stats_reply_OF_VERSION_1_3_dup(
        of_flow_stats_reply_t *src);

extern of_flow_stats_request_t *
    of_flow_stats_request_OF_VERSION_1_3_dup(
        of_flow_stats_request_t *src);

extern of_get_config_reply_t *
    of_get_config_reply_OF_VERSION_1_3_dup(
        of_get_config_reply_t *src);

extern of_get_config_request_t *
    of_get_config_request_OF_VERSION_1_3_dup(
        of_get_config_request_t *src);

extern of_group_add_t *
    of_group_add_OF_VERSION_1_3_dup(
        of_group_add_t *src);

extern of_group_delete_t *
    of_group_delete_OF_VERSION_1_3_dup(
        of_group_delete_t *src);

extern of_group_desc_stats_reply_t *
    of_group_desc_stats_reply_OF_VERSION_1_3_dup(
        of_group_desc_stats_reply_t *src);

extern of_group_desc_stats_request_t *
    of_group_desc_stats_request_OF_VERSION_1_3_dup(
        of_group_desc_stats_request_t *src);

extern of_group_features_stats_reply_t *
    of_group_features_stats_reply_OF_VERSION_1_3_dup(
        of_group_features_stats_reply_t *src);

extern of_group_features_stats_request_t *
    of_group_features_stats_request_OF_VERSION_1_3_dup(
        of_group_features_stats_request_t *src);

extern of_group_mod_t *
    of_group_mod_OF_VERSION_1_3_dup(
        of_group_mod_t *src);

extern of_group_mod_failed_error_msg_t *
    of_group_mod_failed_error_msg_OF_VERSION_1_3_dup(
        of_group_mod_failed_error_msg_t *src);

extern of_group_modify_t *
    of_group_modify_OF_VERSION_1_3_dup(
        of_group_modify_t *src);

extern of_group_stats_reply_t *
    of_group_stats_reply_OF_VERSION_1_3_dup(
        of_group_stats_reply_t *src);

extern of_group_stats_request_t *
    of_group_stats_request_OF_VERSION_1_3_dup(
        of_group_stats_request_t *src);

extern of_hello_t *
    of_hello_OF_VERSION_1_3_dup(
        of_hello_t *src);

extern of_hello_failed_error_msg_t *
    of_hello_failed_error_msg_OF_VERSION_1_3_dup(
        of_hello_failed_error_msg_t *src);

extern of_meter_config_stats_reply_t *
    of_meter_config_stats_reply_OF_VERSION_1_3_dup(
        of_meter_config_stats_reply_t *src);

extern of_meter_config_stats_request_t *
    of_meter_config_stats_request_OF_VERSION_1_3_dup(
        of_meter_config_stats_request_t *src);

extern of_meter_features_stats_reply_t *
    of_meter_features_stats_reply_OF_VERSION_1_3_dup(
        of_meter_features_stats_reply_t *src);

extern of_meter_features_stats_request_t *
    of_meter_features_stats_request_OF_VERSION_1_3_dup(
        of_meter_features_stats_request_t *src);

extern of_meter_mod_t *
    of_meter_mod_OF_VERSION_1_3_dup(
        of_meter_mod_t *src);

extern of_meter_mod_failed_error_msg_t *
    of_meter_mod_failed_error_msg_OF_VERSION_1_3_dup(
        of_meter_mod_failed_error_msg_t *src);

extern of_meter_stats_reply_t *
    of_meter_stats_reply_OF_VERSION_1_3_dup(
        of_meter_stats_reply_t *src);

extern of_meter_stats_request_t *
    of_meter_stats_request_OF_VERSION_1_3_dup(
        of_meter_stats_request_t *src);

extern of_nicira_header_t *
    of_nicira_header_OF_VERSION_1_3_dup(
        of_nicira_header_t *src);

extern of_packet_in_t *
    of_packet_in_OF_VERSION_1_3_dup(
        of_packet_in_t *src);

extern of_packet_out_t *
    of_packet_out_OF_VERSION_1_3_dup(
        of_packet_out_t *src);

extern of_port_desc_stats_reply_t *
    of_port_desc_stats_reply_OF_VERSION_1_3_dup(
        of_port_desc_stats_reply_t *src);

extern of_port_desc_stats_request_t *
    of_port_desc_stats_request_OF_VERSION_1_3_dup(
        of_port_desc_stats_request_t *src);

extern of_port_mod_t *
    of_port_mod_OF_VERSION_1_3_dup(
        of_port_mod_t *src);

extern of_port_mod_failed_error_msg_t *
    of_port_mod_failed_error_msg_OF_VERSION_1_3_dup(
        of_port_mod_failed_error_msg_t *src);

extern of_port_stats_reply_t *
    of_port_stats_reply_OF_VERSION_1_3_dup(
        of_port_stats_reply_t *src);

extern of_port_stats_request_t *
    of_port_stats_request_OF_VERSION_1_3_dup(
        of_port_stats_request_t *src);

extern of_port_status_t *
    of_port_status_OF_VERSION_1_3_dup(
        of_port_status_t *src);

extern of_queue_get_config_reply_t *
    of_queue_get_config_reply_OF_VERSION_1_3_dup(
        of_queue_get_config_reply_t *src);

extern of_queue_get_config_request_t *
    of_queue_get_config_request_OF_VERSION_1_3_dup(
        of_queue_get_config_request_t *src);

extern of_queue_op_failed_error_msg_t *
    of_queue_op_failed_error_msg_OF_VERSION_1_3_dup(
        of_queue_op_failed_error_msg_t *src);

extern of_queue_stats_reply_t *
    of_queue_stats_reply_OF_VERSION_1_3_dup(
        of_queue_stats_reply_t *src);

extern of_queue_stats_request_t *
    of_queue_stats_request_OF_VERSION_1_3_dup(
        of_queue_stats_request_t *src);

extern of_role_reply_t *
    of_role_reply_OF_VERSION_1_3_dup(
        of_role_reply_t *src);

extern of_role_request_t *
    of_role_request_OF_VERSION_1_3_dup(
        of_role_request_t *src);

extern of_role_request_failed_error_msg_t *
    of_role_request_failed_error_msg_OF_VERSION_1_3_dup(
        of_role_request_failed_error_msg_t *src);

extern of_set_config_t *
    of_set_config_OF_VERSION_1_3_dup(
        of_set_config_t *src);

extern of_stats_reply_t *
    of_stats_reply_OF_VERSION_1_3_dup(
        of_stats_reply_t *src);

extern of_stats_request_t *
    of_stats_request_OF_VERSION_1_3_dup(
        of_stats_request_t *src);

extern of_switch_config_failed_error_msg_t *
    of_switch_config_failed_error_msg_OF_VERSION_1_3_dup(
        of_switch_config_failed_error_msg_t *src);

extern of_table_features_failed_error_msg_t *
    of_table_features_failed_error_msg_OF_VERSION_1_3_dup(
        of_table_features_failed_error_msg_t *src);

extern of_table_features_stats_reply_t *
    of_table_features_stats_reply_OF_VERSION_1_3_dup(
        of_table_features_stats_reply_t *src);

extern of_table_features_stats_request_t *
    of_table_features_stats_request_OF_VERSION_1_3_dup(
        of_table_features_stats_request_t *src);

extern of_table_mod_t *
    of_table_mod_OF_VERSION_1_3_dup(
        of_table_mod_t *src);

extern of_table_mod_failed_error_msg_t *
    of_table_mod_failed_error_msg_OF_VERSION_1_3_dup(
        of_table_mod_failed_error_msg_t *src);

extern of_table_stats_reply_t *
    of_table_stats_reply_OF_VERSION_1_3_dup(
        of_table_stats_reply_t *src);

extern of_table_stats_request_t *
    of_table_stats_request_OF_VERSION_1_3_dup(
        of_table_stats_request_t *src);

extern of_action_t *
    of_action_OF_VERSION_1_3_dup(
        of_action_t *src);

extern of_action_bsn_t *
    of_action_bsn_OF_VERSION_1_3_dup(
        of_action_bsn_t *src);

extern of_action_bsn_mirror_t *
    of_action_bsn_mirror_OF_VERSION_1_3_dup(
        of_action_bsn_mirror_t *src);

extern of_action_bsn_set_tunnel_dst_t *
    of_action_bsn_set_tunnel_dst_OF_VERSION_1_3_dup(
        of_action_bsn_set_tunnel_dst_t *src);

extern of_action_copy_ttl_in_t *
    of_action_copy_ttl_in_OF_VERSION_1_3_dup(
        of_action_copy_ttl_in_t *src);

extern of_action_copy_ttl_out_t *
    of_action_copy_ttl_out_OF_VERSION_1_3_dup(
        of_action_copy_ttl_out_t *src);

extern of_action_dec_mpls_ttl_t *
    of_action_dec_mpls_ttl_OF_VERSION_1_3_dup(
        of_action_dec_mpls_ttl_t *src);

extern of_action_dec_nw_ttl_t *
    of_action_dec_nw_ttl_OF_VERSION_1_3_dup(
        of_action_dec_nw_ttl_t *src);

extern of_action_experimenter_t *
    of_action_experimenter_OF_VERSION_1_3_dup(
        of_action_experimenter_t *src);

extern of_action_group_t *
    of_action_group_OF_VERSION_1_3_dup(
        of_action_group_t *src);

extern of_action_header_t *
    of_action_header_OF_VERSION_1_3_dup(
        of_action_header_t *src);

extern of_action_id_t *
    of_action_id_OF_VERSION_1_3_dup(
        of_action_id_t *src);

extern of_action_id_bsn_t *
    of_action_id_bsn_OF_VERSION_1_3_dup(
        of_action_id_bsn_t *src);

extern of_action_id_bsn_mirror_t *
    of_action_id_bsn_mirror_OF_VERSION_1_3_dup(
        of_action_id_bsn_mirror_t *src);

extern of_action_id_bsn_set_tunnel_dst_t *
    of_action_id_bsn_set_tunnel_dst_OF_VERSION_1_3_dup(
        of_action_id_bsn_set_tunnel_dst_t *src);

extern of_action_id_copy_ttl_in_t *
    of_action_id_copy_ttl_in_OF_VERSION_1_3_dup(
        of_action_id_copy_ttl_in_t *src);

extern of_action_id_copy_ttl_out_t *
    of_action_id_copy_ttl_out_OF_VERSION_1_3_dup(
        of_action_id_copy_ttl_out_t *src);

extern of_action_id_dec_mpls_ttl_t *
    of_action_id_dec_mpls_ttl_OF_VERSION_1_3_dup(
        of_action_id_dec_mpls_ttl_t *src);

extern of_action_id_dec_nw_ttl_t *
    of_action_id_dec_nw_ttl_OF_VERSION_1_3_dup(
        of_action_id_dec_nw_ttl_t *src);

extern of_action_id_experimenter_t *
    of_action_id_experimenter_OF_VERSION_1_3_dup(
        of_action_id_experimenter_t *src);

extern of_action_id_group_t *
    of_action_id_group_OF_VERSION_1_3_dup(
        of_action_id_group_t *src);

extern of_action_id_header_t *
    of_action_id_header_OF_VERSION_1_3_dup(
        of_action_id_header_t *src);

extern of_action_id_nicira_t *
    of_action_id_nicira_OF_VERSION_1_3_dup(
        of_action_id_nicira_t *src);

extern of_action_id_nicira_dec_ttl_t *
    of_action_id_nicira_dec_ttl_OF_VERSION_1_3_dup(
        of_action_id_nicira_dec_ttl_t *src);

extern of_action_id_output_t *
    of_action_id_output_OF_VERSION_1_3_dup(
        of_action_id_output_t *src);

extern of_action_id_pop_mpls_t *
    of_action_id_pop_mpls_OF_VERSION_1_3_dup(
        of_action_id_pop_mpls_t *src);

extern of_action_id_pop_pbb_t *
    of_action_id_pop_pbb_OF_VERSION_1_3_dup(
        of_action_id_pop_pbb_t *src);

extern of_action_id_pop_vlan_t *
    of_action_id_pop_vlan_OF_VERSION_1_3_dup(
        of_action_id_pop_vlan_t *src);

extern of_action_id_push_mpls_t *
    of_action_id_push_mpls_OF_VERSION_1_3_dup(
        of_action_id_push_mpls_t *src);

extern of_action_id_push_pbb_t *
    of_action_id_push_pbb_OF_VERSION_1_3_dup(
        of_action_id_push_pbb_t *src);

extern of_action_id_push_vlan_t *
    of_action_id_push_vlan_OF_VERSION_1_3_dup(
        of_action_id_push_vlan_t *src);

extern of_action_id_set_field_t *
    of_action_id_set_field_OF_VERSION_1_3_dup(
        of_action_id_set_field_t *src);

extern of_action_id_set_mpls_ttl_t *
    of_action_id_set_mpls_ttl_OF_VERSION_1_3_dup(
        of_action_id_set_mpls_ttl_t *src);

extern of_action_id_set_nw_ttl_t *
    of_action_id_set_nw_ttl_OF_VERSION_1_3_dup(
        of_action_id_set_nw_ttl_t *src);

extern of_action_id_set_queue_t *
    of_action_id_set_queue_OF_VERSION_1_3_dup(
        of_action_id_set_queue_t *src);

extern of_action_nicira_t *
    of_action_nicira_OF_VERSION_1_3_dup(
        of_action_nicira_t *src);

extern of_action_nicira_dec_ttl_t *
    of_action_nicira_dec_ttl_OF_VERSION_1_3_dup(
        of_action_nicira_dec_ttl_t *src);

extern of_action_output_t *
    of_action_output_OF_VERSION_1_3_dup(
        of_action_output_t *src);

extern of_action_pop_mpls_t *
    of_action_pop_mpls_OF_VERSION_1_3_dup(
        of_action_pop_mpls_t *src);

extern of_action_pop_pbb_t *
    of_action_pop_pbb_OF_VERSION_1_3_dup(
        of_action_pop_pbb_t *src);

extern of_action_pop_vlan_t *
    of_action_pop_vlan_OF_VERSION_1_3_dup(
        of_action_pop_vlan_t *src);

extern of_action_push_mpls_t *
    of_action_push_mpls_OF_VERSION_1_3_dup(
        of_action_push_mpls_t *src);

extern of_action_push_pbb_t *
    of_action_push_pbb_OF_VERSION_1_3_dup(
        of_action_push_pbb_t *src);

extern of_action_push_vlan_t *
    of_action_push_vlan_OF_VERSION_1_3_dup(
        of_action_push_vlan_t *src);

extern of_action_set_field_t *
    of_action_set_field_OF_VERSION_1_3_dup(
        of_action_set_field_t *src);

extern of_action_set_mpls_ttl_t *
    of_action_set_mpls_ttl_OF_VERSION_1_3_dup(
        of_action_set_mpls_ttl_t *src);

extern of_action_set_nw_ttl_t *
    of_action_set_nw_ttl_OF_VERSION_1_3_dup(
        of_action_set_nw_ttl_t *src);

extern of_action_set_queue_t *
    of_action_set_queue_OF_VERSION_1_3_dup(
        of_action_set_queue_t *src);

extern of_bsn_interface_t *
    of_bsn_interface_OF_VERSION_1_3_dup(
        of_bsn_interface_t *src);

extern of_bsn_lacp_stats_entry_t *
    of_bsn_lacp_stats_entry_OF_VERSION_1_3_dup(
        of_bsn_lacp_stats_entry_t *src);

extern of_bsn_port_counter_stats_entry_t *
    of_bsn_port_counter_stats_entry_OF_VERSION_1_3_dup(
        of_bsn_port_counter_stats_entry_t *src);

extern of_bsn_switch_pipeline_stats_entry_t *
    of_bsn_switch_pipeline_stats_entry_OF_VERSION_1_3_dup(
        of_bsn_switch_pipeline_stats_entry_t *src);

extern of_bsn_vlan_counter_stats_entry_t *
    of_bsn_vlan_counter_stats_entry_OF_VERSION_1_3_dup(
        of_bsn_vlan_counter_stats_entry_t *src);

extern of_bsn_vport_t *
    of_bsn_vport_OF_VERSION_1_3_dup(
        of_bsn_vport_t *src);

extern of_bsn_vport_header_t *
    of_bsn_vport_header_OF_VERSION_1_3_dup(
        of_bsn_vport_header_t *src);

extern of_bsn_vport_q_in_q_t *
    of_bsn_vport_q_in_q_OF_VERSION_1_3_dup(
        of_bsn_vport_q_in_q_t *src);

extern of_bucket_t *
    of_bucket_OF_VERSION_1_3_dup(
        of_bucket_t *src);

extern of_bucket_counter_t *
    of_bucket_counter_OF_VERSION_1_3_dup(
        of_bucket_counter_t *src);

extern of_experimenter_stats_header_t *
    of_experimenter_stats_header_OF_VERSION_1_3_dup(
        of_experimenter_stats_header_t *src);

extern of_flow_stats_entry_t *
    of_flow_stats_entry_OF_VERSION_1_3_dup(
        of_flow_stats_entry_t *src);

extern of_group_desc_stats_entry_t *
    of_group_desc_stats_entry_OF_VERSION_1_3_dup(
        of_group_desc_stats_entry_t *src);

extern of_group_stats_entry_t *
    of_group_stats_entry_OF_VERSION_1_3_dup(
        of_group_stats_entry_t *src);

extern of_header_t *
    of_header_OF_VERSION_1_3_dup(
        of_header_t *src);

extern of_hello_elem_t *
    of_hello_elem_OF_VERSION_1_3_dup(
        of_hello_elem_t *src);

extern of_hello_elem_header_t *
    of_hello_elem_header_OF_VERSION_1_3_dup(
        of_hello_elem_header_t *src);

extern of_hello_elem_versionbitmap_t *
    of_hello_elem_versionbitmap_OF_VERSION_1_3_dup(
        of_hello_elem_versionbitmap_t *src);

extern of_instruction_t *
    of_instruction_OF_VERSION_1_3_dup(
        of_instruction_t *src);

extern of_instruction_apply_actions_t *
    of_instruction_apply_actions_OF_VERSION_1_3_dup(
        of_instruction_apply_actions_t *src);

extern of_instruction_bsn_t *
    of_instruction_bsn_OF_VERSION_1_3_dup(
        of_instruction_bsn_t *src);

extern of_instruction_bsn_disable_src_mac_check_t *
    of_instruction_bsn_disable_src_mac_check_OF_VERSION_1_3_dup(
        of_instruction_bsn_disable_src_mac_check_t *src);

extern of_instruction_clear_actions_t *
    of_instruction_clear_actions_OF_VERSION_1_3_dup(
        of_instruction_clear_actions_t *src);

extern of_instruction_experimenter_t *
    of_instruction_experimenter_OF_VERSION_1_3_dup(
        of_instruction_experimenter_t *src);

extern of_instruction_goto_table_t *
    of_instruction_goto_table_OF_VERSION_1_3_dup(
        of_instruction_goto_table_t *src);

extern of_instruction_header_t *
    of_instruction_header_OF_VERSION_1_3_dup(
        of_instruction_header_t *src);

extern of_instruction_id_t *
    of_instruction_id_OF_VERSION_1_3_dup(
        of_instruction_id_t *src);

extern of_instruction_id_apply_actions_t *
    of_instruction_id_apply_actions_OF_VERSION_1_3_dup(
        of_instruction_id_apply_actions_t *src);

extern of_instruction_id_bsn_t *
    of_instruction_id_bsn_OF_VERSION_1_3_dup(
        of_instruction_id_bsn_t *src);

extern of_instruction_id_bsn_disable_src_mac_check_t *
    of_instruction_id_bsn_disable_src_mac_check_OF_VERSION_1_3_dup(
        of_instruction_id_bsn_disable_src_mac_check_t *src);

extern of_instruction_id_clear_actions_t *
    of_instruction_id_clear_actions_OF_VERSION_1_3_dup(
        of_instruction_id_clear_actions_t *src);

extern of_instruction_id_experimenter_t *
    of_instruction_id_experimenter_OF_VERSION_1_3_dup(
        of_instruction_id_experimenter_t *src);

extern of_instruction_id_goto_table_t *
    of_instruction_id_goto_table_OF_VERSION_1_3_dup(
        of_instruction_id_goto_table_t *src);

extern of_instruction_id_header_t *
    of_instruction_id_header_OF_VERSION_1_3_dup(
        of_instruction_id_header_t *src);

extern of_instruction_id_meter_t *
    of_instruction_id_meter_OF_VERSION_1_3_dup(
        of_instruction_id_meter_t *src);

extern of_instruction_id_write_actions_t *
    of_instruction_id_write_actions_OF_VERSION_1_3_dup(
        of_instruction_id_write_actions_t *src);

extern of_instruction_id_write_metadata_t *
    of_instruction_id_write_metadata_OF_VERSION_1_3_dup(
        of_instruction_id_write_metadata_t *src);

extern of_instruction_meter_t *
    of_instruction_meter_OF_VERSION_1_3_dup(
        of_instruction_meter_t *src);

extern of_instruction_write_actions_t *
    of_instruction_write_actions_OF_VERSION_1_3_dup(
        of_instruction_write_actions_t *src);

extern of_instruction_write_metadata_t *
    of_instruction_write_metadata_OF_VERSION_1_3_dup(
        of_instruction_write_metadata_t *src);

extern of_match_v3_t *
    of_match_v3_OF_VERSION_1_3_dup(
        of_match_v3_t *src);

extern of_meter_band_t *
    of_meter_band_OF_VERSION_1_3_dup(
        of_meter_band_t *src);

extern of_meter_band_drop_t *
    of_meter_band_drop_OF_VERSION_1_3_dup(
        of_meter_band_drop_t *src);

extern of_meter_band_dscp_remark_t *
    of_meter_band_dscp_remark_OF_VERSION_1_3_dup(
        of_meter_band_dscp_remark_t *src);

extern of_meter_band_experimenter_t *
    of_meter_band_experimenter_OF_VERSION_1_3_dup(
        of_meter_band_experimenter_t *src);

extern of_meter_band_header_t *
    of_meter_band_header_OF_VERSION_1_3_dup(
        of_meter_band_header_t *src);

extern of_meter_band_stats_t *
    of_meter_band_stats_OF_VERSION_1_3_dup(
        of_meter_band_stats_t *src);

extern of_meter_config_t *
    of_meter_config_OF_VERSION_1_3_dup(
        of_meter_config_t *src);

extern of_meter_features_t *
    of_meter_features_OF_VERSION_1_3_dup(
        of_meter_features_t *src);

extern of_meter_stats_t *
    of_meter_stats_OF_VERSION_1_3_dup(
        of_meter_stats_t *src);

extern of_oxm_t *
    of_oxm_OF_VERSION_1_3_dup(
        of_oxm_t *src);

extern of_oxm_arp_op_t *
    of_oxm_arp_op_OF_VERSION_1_3_dup(
        of_oxm_arp_op_t *src);

extern of_oxm_arp_op_masked_t *
    of_oxm_arp_op_masked_OF_VERSION_1_3_dup(
        of_oxm_arp_op_masked_t *src);

extern of_oxm_arp_sha_t *
    of_oxm_arp_sha_OF_VERSION_1_3_dup(
        of_oxm_arp_sha_t *src);

extern of_oxm_arp_sha_masked_t *
    of_oxm_arp_sha_masked_OF_VERSION_1_3_dup(
        of_oxm_arp_sha_masked_t *src);

extern of_oxm_arp_spa_t *
    of_oxm_arp_spa_OF_VERSION_1_3_dup(
        of_oxm_arp_spa_t *src);

extern of_oxm_arp_spa_masked_t *
    of_oxm_arp_spa_masked_OF_VERSION_1_3_dup(
        of_oxm_arp_spa_masked_t *src);

extern of_oxm_arp_tha_t *
    of_oxm_arp_tha_OF_VERSION_1_3_dup(
        of_oxm_arp_tha_t *src);

extern of_oxm_arp_tha_masked_t *
    of_oxm_arp_tha_masked_OF_VERSION_1_3_dup(
        of_oxm_arp_tha_masked_t *src);

extern of_oxm_arp_tpa_t *
    of_oxm_arp_tpa_OF_VERSION_1_3_dup(
        of_oxm_arp_tpa_t *src);

extern of_oxm_arp_tpa_masked_t *
    of_oxm_arp_tpa_masked_OF_VERSION_1_3_dup(
        of_oxm_arp_tpa_masked_t *src);

extern of_oxm_bsn_global_vrf_allowed_t *
    of_oxm_bsn_global_vrf_allowed_OF_VERSION_1_3_dup(
        of_oxm_bsn_global_vrf_allowed_t *src);

extern of_oxm_bsn_global_vrf_allowed_masked_t *
    of_oxm_bsn_global_vrf_allowed_masked_OF_VERSION_1_3_dup(
        of_oxm_bsn_global_vrf_allowed_masked_t *src);

extern of_oxm_bsn_in_ports_128_t *
    of_oxm_bsn_in_ports_128_OF_VERSION_1_3_dup(
        of_oxm_bsn_in_ports_128_t *src);

extern of_oxm_bsn_in_ports_128_masked_t *
    of_oxm_bsn_in_ports_128_masked_OF_VERSION_1_3_dup(
        of_oxm_bsn_in_ports_128_masked_t *src);

extern of_oxm_bsn_l3_dst_class_id_t *
    of_oxm_bsn_l3_dst_class_id_OF_VERSION_1_3_dup(
        of_oxm_bsn_l3_dst_class_id_t *src);

extern of_oxm_bsn_l3_dst_class_id_masked_t *
    of_oxm_bsn_l3_dst_class_id_masked_OF_VERSION_1_3_dup(
        of_oxm_bsn_l3_dst_class_id_masked_t *src);

extern of_oxm_bsn_l3_interface_class_id_t *
    of_oxm_bsn_l3_interface_class_id_OF_VERSION_1_3_dup(
        of_oxm_bsn_l3_interface_class_id_t *src);

extern of_oxm_bsn_l3_interface_class_id_masked_t *
    of_oxm_bsn_l3_interface_class_id_masked_OF_VERSION_1_3_dup(
        of_oxm_bsn_l3_interface_class_id_masked_t *src);

extern of_oxm_bsn_l3_src_class_id_t *
    of_oxm_bsn_l3_src_class_id_OF_VERSION_1_3_dup(
        of_oxm_bsn_l3_src_class_id_t *src);

extern of_oxm_bsn_l3_src_class_id_masked_t *
    of_oxm_bsn_l3_src_class_id_masked_OF_VERSION_1_3_dup(
        of_oxm_bsn_l3_src_class_id_masked_t *src);

extern of_oxm_bsn_lag_id_t *
    of_oxm_bsn_lag_id_OF_VERSION_1_3_dup(
        of_oxm_bsn_lag_id_t *src);

extern of_oxm_bsn_lag_id_masked_t *
    of_oxm_bsn_lag_id_masked_OF_VERSION_1_3_dup(
        of_oxm_bsn_lag_id_masked_t *src);

extern of_oxm_bsn_vrf_t *
    of_oxm_bsn_vrf_OF_VERSION_1_3_dup(
        of_oxm_bsn_vrf_t *src);

extern of_oxm_bsn_vrf_masked_t *
    of_oxm_bsn_vrf_masked_OF_VERSION_1_3_dup(
        of_oxm_bsn_vrf_masked_t *src);

extern of_oxm_eth_dst_t *
    of_oxm_eth_dst_OF_VERSION_1_3_dup(
        of_oxm_eth_dst_t *src);

extern of_oxm_eth_dst_masked_t *
    of_oxm_eth_dst_masked_OF_VERSION_1_3_dup(
        of_oxm_eth_dst_masked_t *src);

extern of_oxm_eth_src_t *
    of_oxm_eth_src_OF_VERSION_1_3_dup(
        of_oxm_eth_src_t *src);

extern of_oxm_eth_src_masked_t *
    of_oxm_eth_src_masked_OF_VERSION_1_3_dup(
        of_oxm_eth_src_masked_t *src);

extern of_oxm_eth_type_t *
    of_oxm_eth_type_OF_VERSION_1_3_dup(
        of_oxm_eth_type_t *src);

extern of_oxm_eth_type_masked_t *
    of_oxm_eth_type_masked_OF_VERSION_1_3_dup(
        of_oxm_eth_type_masked_t *src);

extern of_oxm_header_t *
    of_oxm_header_OF_VERSION_1_3_dup(
        of_oxm_header_t *src);

extern of_oxm_icmpv4_code_t *
    of_oxm_icmpv4_code_OF_VERSION_1_3_dup(
        of_oxm_icmpv4_code_t *src);

extern of_oxm_icmpv4_code_masked_t *
    of_oxm_icmpv4_code_masked_OF_VERSION_1_3_dup(
        of_oxm_icmpv4_code_masked_t *src);

extern of_oxm_icmpv4_type_t *
    of_oxm_icmpv4_type_OF_VERSION_1_3_dup(
        of_oxm_icmpv4_type_t *src);

extern of_oxm_icmpv4_type_masked_t *
    of_oxm_icmpv4_type_masked_OF_VERSION_1_3_dup(
        of_oxm_icmpv4_type_masked_t *src);

extern of_oxm_icmpv6_code_t *
    of_oxm_icmpv6_code_OF_VERSION_1_3_dup(
        of_oxm_icmpv6_code_t *src);

extern of_oxm_icmpv6_code_masked_t *
    of_oxm_icmpv6_code_masked_OF_VERSION_1_3_dup(
        of_oxm_icmpv6_code_masked_t *src);

extern of_oxm_icmpv6_type_t *
    of_oxm_icmpv6_type_OF_VERSION_1_3_dup(
        of_oxm_icmpv6_type_t *src);

extern of_oxm_icmpv6_type_masked_t *
    of_oxm_icmpv6_type_masked_OF_VERSION_1_3_dup(
        of_oxm_icmpv6_type_masked_t *src);

extern of_oxm_in_phy_port_t *
    of_oxm_in_phy_port_OF_VERSION_1_3_dup(
        of_oxm_in_phy_port_t *src);

extern of_oxm_in_phy_port_masked_t *
    of_oxm_in_phy_port_masked_OF_VERSION_1_3_dup(
        of_oxm_in_phy_port_masked_t *src);

extern of_oxm_in_port_t *
    of_oxm_in_port_OF_VERSION_1_3_dup(
        of_oxm_in_port_t *src);

extern of_oxm_in_port_masked_t *
    of_oxm_in_port_masked_OF_VERSION_1_3_dup(
        of_oxm_in_port_masked_t *src);

extern of_oxm_ip_dscp_t *
    of_oxm_ip_dscp_OF_VERSION_1_3_dup(
        of_oxm_ip_dscp_t *src);

extern of_oxm_ip_dscp_masked_t *
    of_oxm_ip_dscp_masked_OF_VERSION_1_3_dup(
        of_oxm_ip_dscp_masked_t *src);

extern of_oxm_ip_ecn_t *
    of_oxm_ip_ecn_OF_VERSION_1_3_dup(
        of_oxm_ip_ecn_t *src);

extern of_oxm_ip_ecn_masked_t *
    of_oxm_ip_ecn_masked_OF_VERSION_1_3_dup(
        of_oxm_ip_ecn_masked_t *src);

extern of_oxm_ip_proto_t *
    of_oxm_ip_proto_OF_VERSION_1_3_dup(
        of_oxm_ip_proto_t *src);

extern of_oxm_ip_proto_masked_t *
    of_oxm_ip_proto_masked_OF_VERSION_1_3_dup(
        of_oxm_ip_proto_masked_t *src);

extern of_oxm_ipv4_dst_t *
    of_oxm_ipv4_dst_OF_VERSION_1_3_dup(
        of_oxm_ipv4_dst_t *src);

extern of_oxm_ipv4_dst_masked_t *
    of_oxm_ipv4_dst_masked_OF_VERSION_1_3_dup(
        of_oxm_ipv4_dst_masked_t *src);

extern of_oxm_ipv4_src_t *
    of_oxm_ipv4_src_OF_VERSION_1_3_dup(
        of_oxm_ipv4_src_t *src);

extern of_oxm_ipv4_src_masked_t *
    of_oxm_ipv4_src_masked_OF_VERSION_1_3_dup(
        of_oxm_ipv4_src_masked_t *src);

extern of_oxm_ipv6_dst_t *
    of_oxm_ipv6_dst_OF_VERSION_1_3_dup(
        of_oxm_ipv6_dst_t *src);

extern of_oxm_ipv6_dst_masked_t *
    of_oxm_ipv6_dst_masked_OF_VERSION_1_3_dup(
        of_oxm_ipv6_dst_masked_t *src);

extern of_oxm_ipv6_flabel_t *
    of_oxm_ipv6_flabel_OF_VERSION_1_3_dup(
        of_oxm_ipv6_flabel_t *src);

extern of_oxm_ipv6_flabel_masked_t *
    of_oxm_ipv6_flabel_masked_OF_VERSION_1_3_dup(
        of_oxm_ipv6_flabel_masked_t *src);

extern of_oxm_ipv6_nd_sll_t *
    of_oxm_ipv6_nd_sll_OF_VERSION_1_3_dup(
        of_oxm_ipv6_nd_sll_t *src);

extern of_oxm_ipv6_nd_sll_masked_t *
    of_oxm_ipv6_nd_sll_masked_OF_VERSION_1_3_dup(
        of_oxm_ipv6_nd_sll_masked_t *src);

extern of_oxm_ipv6_nd_target_t *
    of_oxm_ipv6_nd_target_OF_VERSION_1_3_dup(
        of_oxm_ipv6_nd_target_t *src);

extern of_oxm_ipv6_nd_target_masked_t *
    of_oxm_ipv6_nd_target_masked_OF_VERSION_1_3_dup(
        of_oxm_ipv6_nd_target_masked_t *src);

extern of_oxm_ipv6_nd_tll_t *
    of_oxm_ipv6_nd_tll_OF_VERSION_1_3_dup(
        of_oxm_ipv6_nd_tll_t *src);

extern of_oxm_ipv6_nd_tll_masked_t *
    of_oxm_ipv6_nd_tll_masked_OF_VERSION_1_3_dup(
        of_oxm_ipv6_nd_tll_masked_t *src);

extern of_oxm_ipv6_src_t *
    of_oxm_ipv6_src_OF_VERSION_1_3_dup(
        of_oxm_ipv6_src_t *src);

extern of_oxm_ipv6_src_masked_t *
    of_oxm_ipv6_src_masked_OF_VERSION_1_3_dup(
        of_oxm_ipv6_src_masked_t *src);

extern of_oxm_metadata_t *
    of_oxm_metadata_OF_VERSION_1_3_dup(
        of_oxm_metadata_t *src);

extern of_oxm_metadata_masked_t *
    of_oxm_metadata_masked_OF_VERSION_1_3_dup(
        of_oxm_metadata_masked_t *src);

extern of_oxm_mpls_label_t *
    of_oxm_mpls_label_OF_VERSION_1_3_dup(
        of_oxm_mpls_label_t *src);

extern of_oxm_mpls_label_masked_t *
    of_oxm_mpls_label_masked_OF_VERSION_1_3_dup(
        of_oxm_mpls_label_masked_t *src);

extern of_oxm_mpls_tc_t *
    of_oxm_mpls_tc_OF_VERSION_1_3_dup(
        of_oxm_mpls_tc_t *src);

extern of_oxm_mpls_tc_masked_t *
    of_oxm_mpls_tc_masked_OF_VERSION_1_3_dup(
        of_oxm_mpls_tc_masked_t *src);

extern of_oxm_sctp_dst_t *
    of_oxm_sctp_dst_OF_VERSION_1_3_dup(
        of_oxm_sctp_dst_t *src);

extern of_oxm_sctp_dst_masked_t *
    of_oxm_sctp_dst_masked_OF_VERSION_1_3_dup(
        of_oxm_sctp_dst_masked_t *src);

extern of_oxm_sctp_src_t *
    of_oxm_sctp_src_OF_VERSION_1_3_dup(
        of_oxm_sctp_src_t *src);

extern of_oxm_sctp_src_masked_t *
    of_oxm_sctp_src_masked_OF_VERSION_1_3_dup(
        of_oxm_sctp_src_masked_t *src);

extern of_oxm_tcp_dst_t *
    of_oxm_tcp_dst_OF_VERSION_1_3_dup(
        of_oxm_tcp_dst_t *src);

extern of_oxm_tcp_dst_masked_t *
    of_oxm_tcp_dst_masked_OF_VERSION_1_3_dup(
        of_oxm_tcp_dst_masked_t *src);

extern of_oxm_tcp_src_t *
    of_oxm_tcp_src_OF_VERSION_1_3_dup(
        of_oxm_tcp_src_t *src);

extern of_oxm_tcp_src_masked_t *
    of_oxm_tcp_src_masked_OF_VERSION_1_3_dup(
        of_oxm_tcp_src_masked_t *src);

extern of_oxm_udp_dst_t *
    of_oxm_udp_dst_OF_VERSION_1_3_dup(
        of_oxm_udp_dst_t *src);

extern of_oxm_udp_dst_masked_t *
    of_oxm_udp_dst_masked_OF_VERSION_1_3_dup(
        of_oxm_udp_dst_masked_t *src);

extern of_oxm_udp_src_t *
    of_oxm_udp_src_OF_VERSION_1_3_dup(
        of_oxm_udp_src_t *src);

extern of_oxm_udp_src_masked_t *
    of_oxm_udp_src_masked_OF_VERSION_1_3_dup(
        of_oxm_udp_src_masked_t *src);

extern of_oxm_vlan_pcp_t *
    of_oxm_vlan_pcp_OF_VERSION_1_3_dup(
        of_oxm_vlan_pcp_t *src);

extern of_oxm_vlan_pcp_masked_t *
    of_oxm_vlan_pcp_masked_OF_VERSION_1_3_dup(
        of_oxm_vlan_pcp_masked_t *src);

extern of_oxm_vlan_vid_t *
    of_oxm_vlan_vid_OF_VERSION_1_3_dup(
        of_oxm_vlan_vid_t *src);

extern of_oxm_vlan_vid_masked_t *
    of_oxm_vlan_vid_masked_OF_VERSION_1_3_dup(
        of_oxm_vlan_vid_masked_t *src);

extern of_packet_queue_t *
    of_packet_queue_OF_VERSION_1_3_dup(
        of_packet_queue_t *src);

extern of_port_desc_t *
    of_port_desc_OF_VERSION_1_3_dup(
        of_port_desc_t *src);

extern of_port_stats_entry_t *
    of_port_stats_entry_OF_VERSION_1_3_dup(
        of_port_stats_entry_t *src);

extern of_queue_prop_t *
    of_queue_prop_OF_VERSION_1_3_dup(
        of_queue_prop_t *src);

extern of_queue_prop_experimenter_t *
    of_queue_prop_experimenter_OF_VERSION_1_3_dup(
        of_queue_prop_experimenter_t *src);

extern of_queue_prop_header_t *
    of_queue_prop_header_OF_VERSION_1_3_dup(
        of_queue_prop_header_t *src);

extern of_queue_prop_max_rate_t *
    of_queue_prop_max_rate_OF_VERSION_1_3_dup(
        of_queue_prop_max_rate_t *src);

extern of_queue_prop_min_rate_t *
    of_queue_prop_min_rate_OF_VERSION_1_3_dup(
        of_queue_prop_min_rate_t *src);

extern of_queue_stats_entry_t *
    of_queue_stats_entry_OF_VERSION_1_3_dup(
        of_queue_stats_entry_t *src);

extern of_table_feature_prop_t *
    of_table_feature_prop_OF_VERSION_1_3_dup(
        of_table_feature_prop_t *src);

extern of_table_feature_prop_apply_actions_t *
    of_table_feature_prop_apply_actions_OF_VERSION_1_3_dup(
        of_table_feature_prop_apply_actions_t *src);

extern of_table_feature_prop_apply_actions_miss_t *
    of_table_feature_prop_apply_actions_miss_OF_VERSION_1_3_dup(
        of_table_feature_prop_apply_actions_miss_t *src);

extern of_table_feature_prop_apply_setfield_t *
    of_table_feature_prop_apply_setfield_OF_VERSION_1_3_dup(
        of_table_feature_prop_apply_setfield_t *src);

extern of_table_feature_prop_apply_setfield_miss_t *
    of_table_feature_prop_apply_setfield_miss_OF_VERSION_1_3_dup(
        of_table_feature_prop_apply_setfield_miss_t *src);

extern of_table_feature_prop_experimenter_t *
    of_table_feature_prop_experimenter_OF_VERSION_1_3_dup(
        of_table_feature_prop_experimenter_t *src);

extern of_table_feature_prop_header_t *
    of_table_feature_prop_header_OF_VERSION_1_3_dup(
        of_table_feature_prop_header_t *src);

extern of_table_feature_prop_instructions_t *
    of_table_feature_prop_instructions_OF_VERSION_1_3_dup(
        of_table_feature_prop_instructions_t *src);

extern of_table_feature_prop_instructions_miss_t *
    of_table_feature_prop_instructions_miss_OF_VERSION_1_3_dup(
        of_table_feature_prop_instructions_miss_t *src);

extern of_table_feature_prop_match_t *
    of_table_feature_prop_match_OF_VERSION_1_3_dup(
        of_table_feature_prop_match_t *src);

extern of_table_feature_prop_next_tables_t *
    of_table_feature_prop_next_tables_OF_VERSION_1_3_dup(
        of_table_feature_prop_next_tables_t *src);

extern of_table_feature_prop_next_tables_miss_t *
    of_table_feature_prop_next_tables_miss_OF_VERSION_1_3_dup(
        of_table_feature_prop_next_tables_miss_t *src);

extern of_table_feature_prop_wildcards_t *
    of_table_feature_prop_wildcards_OF_VERSION_1_3_dup(
        of_table_feature_prop_wildcards_t *src);

extern of_table_feature_prop_write_actions_t *
    of_table_feature_prop_write_actions_OF_VERSION_1_3_dup(
        of_table_feature_prop_write_actions_t *src);

extern of_table_feature_prop_write_actions_miss_t *
    of_table_feature_prop_write_actions_miss_OF_VERSION_1_3_dup(
        of_table_feature_prop_write_actions_miss_t *src);

extern of_table_feature_prop_write_setfield_t *
    of_table_feature_prop_write_setfield_OF_VERSION_1_3_dup(
        of_table_feature_prop_write_setfield_t *src);

extern of_table_feature_prop_write_setfield_miss_t *
    of_table_feature_prop_write_setfield_miss_OF_VERSION_1_3_dup(
        of_table_feature_prop_write_setfield_miss_t *src);

extern of_table_features_t *
    of_table_features_OF_VERSION_1_3_dup(
        of_table_features_t *src);

extern of_table_stats_entry_t *
    of_table_stats_entry_OF_VERSION_1_3_dup(
        of_table_stats_entry_t *src);

extern of_uint32_t *
    of_uint32_OF_VERSION_1_3_dup(
        of_uint32_t *src);

extern of_uint64_t *
    of_uint64_OF_VERSION_1_3_dup(
        of_uint64_t *src);

extern of_uint8_t *
    of_uint8_OF_VERSION_1_3_dup(
        of_uint8_t *src);

extern of_list_action_t *
    of_list_action_OF_VERSION_1_3_dup(
        of_list_action_t *src);

extern of_list_action_id_t *
    of_list_action_id_OF_VERSION_1_3_dup(
        of_list_action_id_t *src);

extern of_list_bsn_interface_t *
    of_list_bsn_interface_OF_VERSION_1_3_dup(
        of_list_bsn_interface_t *src);

extern of_list_bsn_lacp_stats_entry_t *
    of_list_bsn_lacp_stats_entry_OF_VERSION_1_3_dup(
        of_list_bsn_lacp_stats_entry_t *src);

extern of_list_bsn_port_counter_stats_entry_t *
    of_list_bsn_port_counter_stats_entry_OF_VERSION_1_3_dup(
        of_list_bsn_port_counter_stats_entry_t *src);

extern of_list_bsn_switch_pipeline_stats_entry_t *
    of_list_bsn_switch_pipeline_stats_entry_OF_VERSION_1_3_dup(
        of_list_bsn_switch_pipeline_stats_entry_t *src);

extern of_list_bsn_vlan_counter_stats_entry_t *
    of_list_bsn_vlan_counter_stats_entry_OF_VERSION_1_3_dup(
        of_list_bsn_vlan_counter_stats_entry_t *src);

extern of_list_bucket_t *
    of_list_bucket_OF_VERSION_1_3_dup(
        of_list_bucket_t *src);

extern of_list_bucket_counter_t *
    of_list_bucket_counter_OF_VERSION_1_3_dup(
        of_list_bucket_counter_t *src);

extern of_list_flow_stats_entry_t *
    of_list_flow_stats_entry_OF_VERSION_1_3_dup(
        of_list_flow_stats_entry_t *src);

extern of_list_group_desc_stats_entry_t *
    of_list_group_desc_stats_entry_OF_VERSION_1_3_dup(
        of_list_group_desc_stats_entry_t *src);

extern of_list_group_stats_entry_t *
    of_list_group_stats_entry_OF_VERSION_1_3_dup(
        of_list_group_stats_entry_t *src);

extern of_list_hello_elem_t *
    of_list_hello_elem_OF_VERSION_1_3_dup(
        of_list_hello_elem_t *src);

extern of_list_instruction_t *
    of_list_instruction_OF_VERSION_1_3_dup(
        of_list_instruction_t *src);

extern of_list_meter_band_t *
    of_list_meter_band_OF_VERSION_1_3_dup(
        of_list_meter_band_t *src);

extern of_list_meter_band_stats_t *
    of_list_meter_band_stats_OF_VERSION_1_3_dup(
        of_list_meter_band_stats_t *src);

extern of_list_meter_stats_t *
    of_list_meter_stats_OF_VERSION_1_3_dup(
        of_list_meter_stats_t *src);

extern of_list_oxm_t *
    of_list_oxm_OF_VERSION_1_3_dup(
        of_list_oxm_t *src);

extern of_list_packet_queue_t *
    of_list_packet_queue_OF_VERSION_1_3_dup(
        of_list_packet_queue_t *src);

extern of_list_port_desc_t *
    of_list_port_desc_OF_VERSION_1_3_dup(
        of_list_port_desc_t *src);

extern of_list_port_stats_entry_t *
    of_list_port_stats_entry_OF_VERSION_1_3_dup(
        of_list_port_stats_entry_t *src);

extern of_list_queue_prop_t *
    of_list_queue_prop_OF_VERSION_1_3_dup(
        of_list_queue_prop_t *src);

extern of_list_queue_stats_entry_t *
    of_list_queue_stats_entry_OF_VERSION_1_3_dup(
        of_list_queue_stats_entry_t *src);

extern of_list_table_feature_prop_t *
    of_list_table_feature_prop_OF_VERSION_1_3_dup(
        of_list_table_feature_prop_t *src);

extern of_list_table_features_t *
    of_list_table_features_OF_VERSION_1_3_dup(
        of_list_table_features_t *src);

extern of_list_table_stats_entry_t *
    of_list_table_stats_entry_OF_VERSION_1_3_dup(
        of_list_table_stats_entry_t *src);

extern of_list_uint32_t *
    of_list_uint32_OF_VERSION_1_3_dup(
        of_list_uint32_t *src);

extern of_list_uint64_t *
    of_list_uint64_OF_VERSION_1_3_dup(
        of_list_uint64_t *src);

extern of_list_uint8_t *
    of_list_uint8_OF_VERSION_1_3_dup(
        of_list_uint8_t *src);

#endif /* _OF_DUP_H_ */
