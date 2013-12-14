/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */

/**
 *
 * AUTOMATICALLY GENERATED FILE.  Edits will be lost on regen.
 *
 * Source file for OpenFlow message validation.
 *
 */

#include "loci_log.h"
#include <loci/loci.h>
#include <loci/loci_validator.h>

#define VALIDATOR_LOG(...) LOCI_LOG_ERROR("Validator Error: " __VA_ARGS__)


static inline int of_list_table_stats_entry_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_list_queue_stats_entry_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_list_queue_prop_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_list_port_stats_entry_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_list_port_desc_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_list_packet_queue_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_list_flow_stats_entry_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_list_bsn_interface_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_list_action_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_table_stats_entry_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_queue_stats_entry_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_queue_prop_min_rate_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_queue_prop_header_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_port_stats_entry_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_port_desc_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_packet_queue_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_match_v1_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_header_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_flow_stats_entry_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_bsn_vport_q_in_q_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_bsn_vport_header_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_bsn_interface_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_action_strip_vlan_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_action_set_vlan_vid_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_action_set_vlan_pcp_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_action_set_tp_src_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_action_set_tp_dst_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_action_set_nw_tos_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_action_set_nw_src_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_action_set_nw_dst_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_action_set_dl_src_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_action_set_dl_dst_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_action_output_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_action_nicira_dec_ttl_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_action_nicira_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_action_header_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_action_experimenter_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_action_enqueue_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_action_bsn_set_tunnel_dst_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_action_bsn_mirror_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_action_bsn_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_table_stats_request_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_table_stats_reply_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_table_mod_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_stats_request_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_stats_reply_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_set_config_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_queue_stats_request_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_queue_stats_reply_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_queue_op_failed_error_msg_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_queue_get_config_request_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_queue_get_config_reply_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_port_status_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_port_stats_request_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_port_stats_reply_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_port_mod_failed_error_msg_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_port_mod_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_packet_out_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_packet_in_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_nicira_header_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_nicira_controller_role_request_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_nicira_controller_role_reply_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_hello_failed_error_msg_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_hello_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_get_config_request_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_get_config_reply_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_flow_stats_request_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_flow_stats_reply_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_flow_removed_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_flow_modify_strict_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_flow_modify_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_flow_mod_failed_error_msg_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_flow_mod_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_flow_delete_strict_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_flow_delete_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_flow_add_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_features_request_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_features_reply_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_experimenter_stats_request_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_experimenter_stats_reply_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_experimenter_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_error_msg_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_echo_request_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_echo_reply_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_desc_stats_request_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_desc_stats_reply_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_bsn_virtual_port_remove_request_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_bsn_virtual_port_remove_reply_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_bsn_virtual_port_create_request_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_bsn_virtual_port_create_reply_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_bsn_stats_request_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_bsn_stats_reply_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_bsn_shell_status_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_bsn_shell_output_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_bsn_shell_command_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_bsn_set_pktin_suppression_request_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_bsn_set_pktin_suppression_reply_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_bsn_set_mirroring_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_bsn_set_l2_table_request_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_bsn_set_l2_table_reply_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_bsn_set_ip_mask_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_bsn_pdu_tx_request_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_bsn_pdu_tx_reply_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_bsn_pdu_rx_timeout_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_bsn_pdu_rx_request_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_bsn_pdu_rx_reply_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_bsn_hybrid_get_request_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_bsn_hybrid_get_reply_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_bsn_header_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_bsn_get_mirroring_request_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_bsn_get_mirroring_reply_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_bsn_get_l2_table_request_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_bsn_get_l2_table_reply_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_bsn_get_ip_mask_request_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_bsn_get_ip_mask_reply_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_bsn_get_interfaces_request_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_bsn_get_interfaces_reply_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_bsn_bw_enable_set_request_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_bsn_bw_enable_set_reply_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_bsn_bw_enable_get_request_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_bsn_bw_enable_get_reply_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_bsn_bw_clear_data_request_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_bsn_bw_clear_data_reply_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_barrier_request_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_barrier_reply_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_bad_request_error_msg_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_bad_action_error_msg_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_aggregate_stats_request_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_aggregate_stats_reply_OF_VERSION_1_0_validate(uint8_t *buf, int len);
static inline int of_list_table_stats_entry_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_list_queue_stats_entry_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_list_queue_prop_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_list_port_stats_entry_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_list_port_desc_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_list_packet_queue_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_list_instruction_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_list_group_stats_entry_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_list_group_desc_stats_entry_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_list_flow_stats_entry_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_list_bucket_counter_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_list_bucket_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_list_bsn_interface_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_list_action_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_table_stats_entry_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_queue_stats_entry_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_queue_prop_min_rate_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_queue_prop_header_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_port_stats_entry_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_port_desc_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_packet_queue_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_match_v2_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_instruction_write_metadata_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_instruction_write_actions_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_instruction_header_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_instruction_goto_table_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_instruction_experimenter_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_instruction_clear_actions_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_instruction_apply_actions_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_header_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_group_stats_entry_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_group_desc_stats_entry_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_flow_stats_entry_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_bucket_counter_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_bucket_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_bsn_vport_q_in_q_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_bsn_vport_header_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_bsn_interface_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_action_set_vlan_vid_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_action_set_vlan_pcp_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_action_set_tp_src_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_action_set_tp_dst_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_action_set_queue_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_action_set_nw_ttl_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_action_set_nw_tos_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_action_set_nw_src_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_action_set_nw_ecn_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_action_set_nw_dst_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_action_set_mpls_ttl_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_action_set_mpls_tc_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_action_set_mpls_label_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_action_set_dl_src_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_action_set_dl_dst_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_action_push_vlan_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_action_push_mpls_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_action_pop_vlan_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_action_pop_mpls_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_action_output_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_action_nicira_dec_ttl_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_action_nicira_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_action_header_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_action_group_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_action_experimenter_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_action_dec_nw_ttl_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_action_dec_mpls_ttl_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_action_copy_ttl_out_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_action_copy_ttl_in_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_action_bsn_set_tunnel_dst_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_action_bsn_mirror_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_action_bsn_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_table_stats_request_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_table_stats_reply_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_table_mod_failed_error_msg_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_table_mod_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_switch_config_failed_error_msg_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_stats_request_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_stats_reply_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_set_config_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_queue_stats_request_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_queue_stats_reply_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_queue_op_failed_error_msg_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_queue_get_config_request_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_queue_get_config_reply_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_port_status_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_port_stats_request_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_port_stats_reply_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_port_mod_failed_error_msg_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_port_mod_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_packet_out_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_packet_in_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_nicira_header_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_hello_failed_error_msg_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_hello_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_group_stats_request_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_group_stats_reply_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_group_modify_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_group_mod_failed_error_msg_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_group_mod_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_group_desc_stats_request_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_group_desc_stats_reply_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_group_delete_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_group_add_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_get_config_request_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_get_config_reply_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_flow_stats_request_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_flow_stats_reply_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_flow_removed_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_flow_modify_strict_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_flow_modify_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_flow_mod_failed_error_msg_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_flow_mod_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_flow_delete_strict_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_flow_delete_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_flow_add_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_features_request_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_features_reply_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_experimenter_stats_request_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_experimenter_stats_reply_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_experimenter_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_error_msg_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_echo_request_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_echo_reply_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_desc_stats_request_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_desc_stats_reply_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_bsn_virtual_port_remove_request_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_bsn_virtual_port_remove_reply_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_bsn_virtual_port_create_request_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_bsn_virtual_port_create_reply_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_bsn_stats_request_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_bsn_stats_reply_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_bsn_set_pktin_suppression_request_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_bsn_set_pktin_suppression_reply_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_bsn_set_mirroring_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_bsn_pdu_tx_request_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_bsn_pdu_tx_reply_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_bsn_pdu_rx_timeout_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_bsn_pdu_rx_request_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_bsn_pdu_rx_reply_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_bsn_header_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_bsn_get_mirroring_request_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_bsn_get_mirroring_reply_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_bsn_get_interfaces_request_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_bsn_get_interfaces_reply_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_bsn_bw_enable_set_request_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_bsn_bw_enable_set_reply_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_bsn_bw_enable_get_request_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_bsn_bw_enable_get_reply_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_bsn_bw_clear_data_request_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_bsn_bw_clear_data_reply_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_barrier_request_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_barrier_reply_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_bad_request_error_msg_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_bad_match_error_msg_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_bad_instruction_error_msg_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_bad_action_error_msg_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_aggregate_stats_request_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_aggregate_stats_reply_OF_VERSION_1_1_validate(uint8_t *buf, int len);
static inline int of_list_table_stats_entry_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_list_queue_stats_entry_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_list_queue_prop_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_list_port_stats_entry_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_list_port_desc_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_list_packet_queue_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_list_oxm_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_list_instruction_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_list_group_stats_entry_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_list_group_desc_stats_entry_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_list_flow_stats_entry_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_list_bucket_counter_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_list_bucket_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_list_bsn_interface_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_list_action_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_table_stats_entry_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_queue_stats_entry_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_queue_prop_min_rate_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_queue_prop_max_rate_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_queue_prop_header_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_queue_prop_experimenter_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_port_stats_entry_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_port_desc_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_packet_queue_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_vlan_vid_masked_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_vlan_vid_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_vlan_pcp_masked_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_vlan_pcp_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_udp_src_masked_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_udp_src_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_udp_dst_masked_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_udp_dst_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_tcp_src_masked_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_tcp_src_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_tcp_dst_masked_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_tcp_dst_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_sctp_src_masked_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_sctp_src_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_sctp_dst_masked_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_sctp_dst_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_mpls_tc_masked_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_mpls_tc_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_mpls_label_masked_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_mpls_label_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_metadata_masked_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_metadata_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_ipv6_src_masked_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_ipv6_src_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_ipv6_nd_tll_masked_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_ipv6_nd_tll_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_ipv6_nd_target_masked_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_ipv6_nd_target_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_ipv6_nd_sll_masked_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_ipv6_nd_sll_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_ipv6_flabel_masked_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_ipv6_flabel_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_ipv6_dst_masked_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_ipv6_dst_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_ipv4_src_masked_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_ipv4_src_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_ipv4_dst_masked_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_ipv4_dst_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_ip_proto_masked_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_ip_proto_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_ip_ecn_masked_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_ip_ecn_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_ip_dscp_masked_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_ip_dscp_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_in_port_masked_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_in_port_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_in_phy_port_masked_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_in_phy_port_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_icmpv6_type_masked_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_icmpv6_type_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_icmpv6_code_masked_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_icmpv6_code_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_icmpv4_type_masked_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_icmpv4_type_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_icmpv4_code_masked_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_icmpv4_code_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_header_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_eth_type_masked_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_eth_type_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_eth_src_masked_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_eth_src_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_eth_dst_masked_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_eth_dst_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_bsn_vrf_masked_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_bsn_vrf_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_bsn_lag_id_masked_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_bsn_lag_id_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_bsn_l3_src_class_id_masked_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_bsn_l3_src_class_id_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_bsn_l3_interface_class_id_masked_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_bsn_l3_interface_class_id_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_bsn_l3_dst_class_id_masked_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_bsn_l3_dst_class_id_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_bsn_in_ports_128_masked_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_bsn_in_ports_128_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_bsn_global_vrf_allowed_masked_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_bsn_global_vrf_allowed_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_arp_tpa_masked_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_arp_tpa_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_arp_tha_masked_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_arp_tha_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_arp_spa_masked_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_arp_spa_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_arp_sha_masked_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_arp_sha_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_arp_op_masked_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_oxm_arp_op_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_match_v3_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_instruction_write_metadata_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_instruction_write_actions_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_instruction_header_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_instruction_goto_table_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_instruction_experimenter_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_instruction_clear_actions_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_instruction_apply_actions_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_header_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_group_stats_entry_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_group_desc_stats_entry_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_flow_stats_entry_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_bucket_counter_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_bucket_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_bsn_vport_q_in_q_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_bsn_vport_header_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_bsn_interface_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_action_set_queue_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_action_set_nw_ttl_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_action_set_mpls_ttl_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_action_set_field_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_action_push_vlan_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_action_push_mpls_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_action_pop_vlan_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_action_pop_mpls_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_action_output_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_action_nicira_dec_ttl_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_action_nicira_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_action_header_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_action_group_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_action_experimenter_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_action_dec_nw_ttl_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_action_dec_mpls_ttl_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_action_copy_ttl_out_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_action_copy_ttl_in_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_action_bsn_set_tunnel_dst_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_action_bsn_mirror_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_action_bsn_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_table_stats_request_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_table_stats_reply_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_table_mod_failed_error_msg_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_table_mod_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_switch_config_failed_error_msg_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_stats_request_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_stats_reply_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_set_config_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_role_request_failed_error_msg_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_role_request_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_role_reply_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_queue_stats_request_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_queue_stats_reply_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_queue_op_failed_error_msg_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_queue_get_config_request_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_queue_get_config_reply_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_port_status_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_port_stats_request_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_port_stats_reply_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_port_mod_failed_error_msg_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_port_mod_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_packet_out_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_packet_in_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_nicira_header_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_hello_failed_error_msg_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_hello_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_group_stats_request_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_group_stats_reply_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_group_modify_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_group_mod_failed_error_msg_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_group_mod_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_group_features_stats_request_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_group_features_stats_reply_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_group_desc_stats_request_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_group_desc_stats_reply_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_group_delete_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_group_add_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_get_config_request_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_get_config_reply_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_flow_stats_request_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_flow_stats_reply_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_flow_removed_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_flow_modify_strict_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_flow_modify_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_flow_mod_failed_error_msg_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_flow_mod_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_flow_delete_strict_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_flow_delete_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_flow_add_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_features_request_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_features_reply_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_experimenter_stats_request_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_experimenter_stats_reply_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_experimenter_error_msg_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_experimenter_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_error_msg_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_echo_request_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_echo_reply_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_desc_stats_request_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_desc_stats_reply_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_bsn_virtual_port_remove_request_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_bsn_virtual_port_remove_reply_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_bsn_virtual_port_create_request_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_bsn_virtual_port_create_reply_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_bsn_stats_request_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_bsn_stats_reply_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_bsn_set_pktin_suppression_request_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_bsn_set_pktin_suppression_reply_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_bsn_set_mirroring_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_bsn_pdu_tx_request_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_bsn_pdu_tx_reply_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_bsn_pdu_rx_timeout_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_bsn_pdu_rx_request_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_bsn_pdu_rx_reply_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_bsn_header_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_bsn_get_mirroring_request_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_bsn_get_mirroring_reply_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_bsn_get_interfaces_request_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_bsn_get_interfaces_reply_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_bsn_bw_enable_set_request_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_bsn_bw_enable_set_reply_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_bsn_bw_enable_get_request_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_bsn_bw_enable_get_reply_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_bsn_bw_clear_data_request_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_bsn_bw_clear_data_reply_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_barrier_request_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_barrier_reply_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_bad_request_error_msg_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_bad_match_error_msg_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_bad_instruction_error_msg_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_bad_action_error_msg_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_aggregate_stats_request_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_aggregate_stats_reply_OF_VERSION_1_2_validate(uint8_t *buf, int len);
static inline int of_list_uint8_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_list_uint64_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_list_uint32_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_list_table_stats_entry_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_list_table_features_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_list_table_feature_prop_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_list_queue_stats_entry_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_list_queue_prop_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_list_port_stats_entry_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_list_port_desc_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_list_packet_queue_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_list_oxm_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_list_meter_stats_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_list_meter_band_stats_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_list_meter_band_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_list_instruction_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_list_hello_elem_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_list_group_stats_entry_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_list_group_desc_stats_entry_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_list_flow_stats_entry_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_list_bucket_counter_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_list_bucket_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_list_bsn_vlan_counter_stats_entry_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_list_bsn_switch_pipeline_stats_entry_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_list_bsn_port_counter_stats_entry_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_list_bsn_lacp_stats_entry_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_list_bsn_interface_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_list_action_id_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_list_action_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_uint8_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_uint64_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_uint32_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_table_stats_entry_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_table_features_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_table_feature_prop_write_setfield_miss_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_table_feature_prop_write_setfield_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_table_feature_prop_write_actions_miss_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_table_feature_prop_write_actions_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_table_feature_prop_wildcards_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_table_feature_prop_next_tables_miss_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_table_feature_prop_next_tables_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_table_feature_prop_match_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_table_feature_prop_instructions_miss_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_table_feature_prop_instructions_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_table_feature_prop_header_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_table_feature_prop_experimenter_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_table_feature_prop_apply_setfield_miss_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_table_feature_prop_apply_setfield_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_table_feature_prop_apply_actions_miss_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_table_feature_prop_apply_actions_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_queue_stats_entry_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_queue_prop_min_rate_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_queue_prop_max_rate_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_queue_prop_header_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_queue_prop_experimenter_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_port_stats_entry_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_port_desc_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_packet_queue_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_vlan_vid_masked_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_vlan_vid_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_vlan_pcp_masked_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_vlan_pcp_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_udp_src_masked_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_udp_src_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_udp_dst_masked_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_udp_dst_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_tcp_src_masked_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_tcp_src_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_tcp_dst_masked_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_tcp_dst_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_sctp_src_masked_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_sctp_src_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_sctp_dst_masked_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_sctp_dst_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_mpls_tc_masked_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_mpls_tc_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_mpls_label_masked_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_mpls_label_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_metadata_masked_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_metadata_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_ipv6_src_masked_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_ipv6_src_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_ipv6_nd_tll_masked_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_ipv6_nd_tll_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_ipv6_nd_target_masked_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_ipv6_nd_target_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_ipv6_nd_sll_masked_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_ipv6_nd_sll_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_ipv6_flabel_masked_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_ipv6_flabel_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_ipv6_dst_masked_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_ipv6_dst_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_ipv4_src_masked_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_ipv4_src_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_ipv4_dst_masked_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_ipv4_dst_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_ip_proto_masked_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_ip_proto_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_ip_ecn_masked_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_ip_ecn_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_ip_dscp_masked_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_ip_dscp_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_in_port_masked_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_in_port_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_in_phy_port_masked_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_in_phy_port_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_icmpv6_type_masked_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_icmpv6_type_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_icmpv6_code_masked_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_icmpv6_code_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_icmpv4_type_masked_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_icmpv4_type_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_icmpv4_code_masked_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_icmpv4_code_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_header_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_eth_type_masked_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_eth_type_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_eth_src_masked_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_eth_src_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_eth_dst_masked_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_eth_dst_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_bsn_vrf_masked_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_bsn_vrf_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_bsn_lag_id_masked_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_bsn_lag_id_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_bsn_l3_src_class_id_masked_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_bsn_l3_src_class_id_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_bsn_l3_interface_class_id_masked_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_bsn_l3_interface_class_id_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_bsn_l3_dst_class_id_masked_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_bsn_l3_dst_class_id_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_bsn_in_ports_128_masked_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_bsn_in_ports_128_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_bsn_global_vrf_allowed_masked_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_bsn_global_vrf_allowed_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_arp_tpa_masked_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_arp_tpa_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_arp_tha_masked_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_arp_tha_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_arp_spa_masked_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_arp_spa_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_arp_sha_masked_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_arp_sha_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_arp_op_masked_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_oxm_arp_op_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_meter_stats_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_meter_features_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_meter_config_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_meter_band_stats_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_meter_band_header_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_meter_band_experimenter_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_meter_band_dscp_remark_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_meter_band_drop_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_match_v3_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_instruction_write_metadata_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_instruction_write_actions_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_instruction_meter_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_instruction_id_write_metadata_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_instruction_id_write_actions_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_instruction_id_meter_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_instruction_id_header_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_instruction_id_goto_table_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_instruction_id_experimenter_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_instruction_id_clear_actions_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_instruction_id_bsn_disable_src_mac_check_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_instruction_id_bsn_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_instruction_id_apply_actions_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_instruction_header_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_instruction_goto_table_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_instruction_experimenter_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_instruction_clear_actions_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_instruction_bsn_disable_src_mac_check_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_instruction_bsn_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_instruction_apply_actions_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_hello_elem_versionbitmap_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_hello_elem_header_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_header_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_group_stats_entry_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_group_desc_stats_entry_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_flow_stats_entry_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_experimenter_stats_header_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_bucket_counter_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_bucket_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_bsn_vport_q_in_q_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_bsn_vport_header_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_bsn_vlan_counter_stats_entry_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_bsn_switch_pipeline_stats_entry_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_bsn_port_counter_stats_entry_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_bsn_lacp_stats_entry_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_bsn_interface_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_action_set_queue_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_action_set_nw_ttl_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_action_set_mpls_ttl_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_action_set_field_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_action_push_vlan_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_action_push_pbb_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_action_push_mpls_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_action_pop_vlan_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_action_pop_pbb_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_action_pop_mpls_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_action_output_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_action_nicira_dec_ttl_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_action_nicira_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_action_id_set_queue_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_action_id_set_nw_ttl_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_action_id_set_mpls_ttl_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_action_id_set_field_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_action_id_push_vlan_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_action_id_push_pbb_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_action_id_push_mpls_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_action_id_pop_vlan_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_action_id_pop_pbb_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_action_id_pop_mpls_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_action_id_output_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_action_id_nicira_dec_ttl_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_action_id_nicira_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_action_id_header_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_action_id_group_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_action_id_experimenter_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_action_id_dec_nw_ttl_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_action_id_dec_mpls_ttl_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_action_id_copy_ttl_out_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_action_id_copy_ttl_in_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_action_id_bsn_set_tunnel_dst_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_action_id_bsn_mirror_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_action_id_bsn_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_action_header_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_action_group_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_action_experimenter_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_action_dec_nw_ttl_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_action_dec_mpls_ttl_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_action_copy_ttl_out_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_action_copy_ttl_in_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_action_bsn_set_tunnel_dst_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_action_bsn_mirror_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_action_bsn_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_table_stats_request_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_table_stats_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_table_mod_failed_error_msg_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_table_mod_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_table_features_stats_request_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_table_features_stats_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_table_features_failed_error_msg_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_switch_config_failed_error_msg_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_stats_request_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_stats_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_set_config_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_role_request_failed_error_msg_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_role_request_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_role_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_queue_stats_request_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_queue_stats_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_queue_op_failed_error_msg_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_queue_get_config_request_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_queue_get_config_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_port_status_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_port_stats_request_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_port_stats_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_port_mod_failed_error_msg_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_port_mod_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_port_desc_stats_request_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_port_desc_stats_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_packet_out_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_packet_in_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_nicira_header_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_meter_stats_request_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_meter_stats_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_meter_mod_failed_error_msg_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_meter_mod_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_meter_features_stats_request_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_meter_features_stats_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_meter_config_stats_request_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_meter_config_stats_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_hello_failed_error_msg_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_hello_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_group_stats_request_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_group_stats_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_group_modify_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_group_mod_failed_error_msg_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_group_mod_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_group_features_stats_request_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_group_features_stats_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_group_desc_stats_request_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_group_desc_stats_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_group_delete_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_group_add_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_get_config_request_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_get_config_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_flow_stats_request_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_flow_stats_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_flow_removed_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_flow_modify_strict_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_flow_modify_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_flow_mod_failed_error_msg_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_flow_mod_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_flow_delete_strict_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_flow_delete_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_flow_add_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_features_request_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_features_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_experimenter_stats_request_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_experimenter_stats_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_experimenter_error_msg_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_experimenter_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_error_msg_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_echo_request_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_echo_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_desc_stats_request_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_desc_stats_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_bsn_vlan_counter_stats_request_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_bsn_vlan_counter_stats_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_bsn_virtual_port_remove_request_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_bsn_virtual_port_remove_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_bsn_virtual_port_create_request_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_bsn_virtual_port_create_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_bsn_time_request_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_bsn_time_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_bsn_switch_pipeline_stats_request_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_bsn_switch_pipeline_stats_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_bsn_stats_request_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_bsn_stats_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_bsn_set_switch_pipeline_request_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_bsn_set_switch_pipeline_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_bsn_set_pktin_suppression_request_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_bsn_set_pktin_suppression_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_bsn_set_mirroring_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_bsn_set_lacp_request_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_bsn_set_lacp_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_bsn_port_counter_stats_request_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_bsn_port_counter_stats_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_bsn_pdu_tx_request_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_bsn_pdu_tx_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_bsn_pdu_rx_timeout_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_bsn_pdu_rx_request_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_bsn_pdu_rx_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_bsn_lacp_stats_request_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_bsn_lacp_stats_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_bsn_lacp_convergence_notif_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_bsn_header_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_bsn_get_switch_pipeline_request_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_bsn_get_switch_pipeline_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_bsn_get_mirroring_request_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_bsn_get_mirroring_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_bsn_get_interfaces_request_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_bsn_get_interfaces_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_bsn_flow_idle_enable_set_request_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_bsn_flow_idle_enable_set_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_bsn_flow_idle_enable_get_request_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_bsn_flow_idle_enable_get_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_bsn_flow_idle_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_bsn_bw_enable_set_request_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_bsn_bw_enable_set_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_bsn_bw_enable_get_request_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_bsn_bw_enable_get_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_bsn_bw_clear_data_request_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_bsn_bw_clear_data_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_barrier_request_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_barrier_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_bad_request_error_msg_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_bad_match_error_msg_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_bad_instruction_error_msg_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_bad_action_error_msg_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_async_set_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_async_get_request_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_async_get_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_aggregate_stats_request_OF_VERSION_1_3_validate(uint8_t *buf, int len);
static inline int of_aggregate_stats_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len);

static inline int
of_list_table_stats_entry_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if ((len / 64) * 64 != len) {
        return -1;
    }

    return 0;
}

static inline int
of_list_queue_stats_entry_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if ((len / 32) * 32 != len) {
        return -1;
    }

    return 0;
}

static inline int
of_list_queue_prop_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    while (len >= 8) {
        of_object_id_t e_id;
        uint16_t e_type, e_len;
        buf_u16_get(buf, &e_type);
        buf_u16_get(buf+2, &e_len);
        e_id = of_queue_prop_to_object_id(e_type, OF_VERSION_1_0);
        switch (e_id) {
        case OF_QUEUE_PROP_MIN_RATE:
            if (of_queue_prop_min_rate_OF_VERSION_1_0_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        default:
            return -1;
        }
        buf += e_len;
        len -= e_len;
    }
    if (len != 0) {
        return -1;
    }

    return 0;
}

static inline int
of_list_port_stats_entry_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if ((len / 104) * 104 != len) {
        return -1;
    }

    return 0;
}

static inline int
of_list_port_desc_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if ((len / 48) * 48 != len) {
        return -1;
    }

    return 0;
}

static inline int
of_list_packet_queue_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    /* XXX unknown element format */

    return 0;
}

static inline int
of_list_flow_stats_entry_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    /* TODO verify U16 len elements */

    return 0;
}

static inline int
of_list_bsn_interface_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if ((len / 32) * 32 != len) {
        return -1;
    }

    return 0;
}

static inline int
of_list_action_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    while (len >= 8) {
        of_object_id_t e_id;
        uint16_t e_type, e_len;
        buf_u16_get(buf, &e_type);
        buf_u16_get(buf+2, &e_len);
        e_id = of_action_to_object_id(e_type, OF_VERSION_1_0);
        switch (e_id) {
        case OF_ACTION_BSN_MIRROR:
            if (of_action_bsn_mirror_OF_VERSION_1_0_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_SET_NW_TOS:
            if (of_action_set_nw_tos_OF_VERSION_1_0_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_BSN_SET_TUNNEL_DST:
            if (of_action_bsn_set_tunnel_dst_OF_VERSION_1_0_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_SET_NW_DST:
            if (of_action_set_nw_dst_OF_VERSION_1_0_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_SET_NW_SRC:
            if (of_action_set_nw_src_OF_VERSION_1_0_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_SET_VLAN_VID:
            if (of_action_set_vlan_vid_OF_VERSION_1_0_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_NICIRA_DEC_TTL:
            if (of_action_nicira_dec_ttl_OF_VERSION_1_0_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_SET_TP_DST:
            if (of_action_set_tp_dst_OF_VERSION_1_0_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_SET_VLAN_PCP:
            if (of_action_set_vlan_pcp_OF_VERSION_1_0_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_ENQUEUE:
            if (of_action_enqueue_OF_VERSION_1_0_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_BSN:
            if (of_action_bsn_OF_VERSION_1_0_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_EXPERIMENTER:
            if (of_action_experimenter_OF_VERSION_1_0_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_NICIRA:
            if (of_action_nicira_OF_VERSION_1_0_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_STRIP_VLAN:
            if (of_action_strip_vlan_OF_VERSION_1_0_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_SET_DL_DST:
            if (of_action_set_dl_dst_OF_VERSION_1_0_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_SET_TP_SRC:
            if (of_action_set_tp_src_OF_VERSION_1_0_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_SET_DL_SRC:
            if (of_action_set_dl_src_OF_VERSION_1_0_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_OUTPUT:
            if (of_action_output_OF_VERSION_1_0_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        default:
            return -1;
        }
        buf += e_len;
        len -= e_len;
    }
    if (len != 0) {
        return -1;
    }

    return 0;
}

static inline int
of_table_stats_entry_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 64) {
        VALIDATOR_LOG("Class of_table_stats_entry.  Len %d too small, < %d", len, 64);
        return -1;
    }

    return 0;
}

static inline int
of_queue_stats_entry_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 32) {
        VALIDATOR_LOG("Class of_queue_stats_entry.  Len %d too small, < %d", len, 32);
        return -1;
    }

    return 0;
}

static inline int
of_queue_prop_min_rate_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_queue_prop_min_rate.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_queue_prop_header_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_queue_prop_header.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_port_stats_entry_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 104) {
        VALIDATOR_LOG("Class of_port_stats_entry.  Len %d too small, < %d", len, 104);
        return -1;
    }

    return 0;
}

static inline int
of_port_desc_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 48) {
        VALIDATOR_LOG("Class of_port_desc.  Len %d too small, < %d", len, 48);
        return -1;
    }

    return 0;
}

static inline int
of_packet_queue_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_packet_queue.  Len %d too small, < %d", len, 8);
        return -1;
    }


    {    int properties_len = len - 8;


        if (of_list_queue_prop_OF_VERSION_1_0_validate(buf + 8, properties_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_match_v1_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 40) {
        VALIDATOR_LOG("Class of_match_v1.  Len %d too small, < %d", len, 40);
        return -1;
    }

    return 0;
}

static inline int
of_header_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_header.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_flow_stats_entry_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 88) {
        VALIDATOR_LOG("Class of_flow_stats_entry.  Len %d too small, < %d", len, 88);
        return -1;
    }


    {    int actions_len = len - 88;


        if (of_list_action_OF_VERSION_1_0_validate(buf + 88, actions_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_bsn_vport_q_in_q_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 32) {
        VALIDATOR_LOG("Class of_bsn_vport_q_in_q.  Len %d too small, < %d", len, 32);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_vport_header_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 4) {
        VALIDATOR_LOG("Class of_bsn_vport_header.  Len %d too small, < %d", len, 4);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_interface_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 32) {
        VALIDATOR_LOG("Class of_bsn_interface.  Len %d too small, < %d", len, 32);
        return -1;
    }

    return 0;
}

static inline int
of_action_strip_vlan_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_action_strip_vlan.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_action_set_vlan_vid_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_action_set_vlan_vid.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_action_set_vlan_pcp_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_action_set_vlan_pcp.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_action_set_tp_src_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_action_set_tp_src.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_action_set_tp_dst_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_action_set_tp_dst.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_action_set_nw_tos_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_action_set_nw_tos.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_action_set_nw_src_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_action_set_nw_src.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_action_set_nw_dst_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_action_set_nw_dst.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_action_set_dl_src_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_action_set_dl_src.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_action_set_dl_dst_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_action_set_dl_dst.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_action_output_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_action_output.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_action_nicira_dec_ttl_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_action_nicira_dec_ttl.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_action_nicira_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_action_nicira.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_action_header_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_action_header.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_action_experimenter_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_action_experimenter.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_action_enqueue_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_action_enqueue.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_action_bsn_set_tunnel_dst_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_action_bsn_set_tunnel_dst.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_action_bsn_mirror_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 24) {
        VALIDATOR_LOG("Class of_action_bsn_mirror.  Len %d too small, < %d", len, 24);
        return -1;
    }

    return 0;
}

static inline int
of_action_bsn_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_action_bsn.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_table_stats_request_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_table_stats_request.  Len %d too small, < %d", len, 12);
        return -1;
    }

    return 0;
}

static inline int
of_table_stats_reply_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_table_stats_reply.  Len %d too small, < %d", len, 12);
        return -1;
    }


    {    int entries_len = len - 12;


        if (of_list_table_stats_entry_OF_VERSION_1_0_validate(buf + 12, entries_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_table_mod_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_table_mod.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_stats_request_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_stats_request.  Len %d too small, < %d", len, 12);
        return -1;
    }

    return 0;
}

static inline int
of_stats_reply_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_stats_reply.  Len %d too small, < %d", len, 12);
        return -1;
    }

    return 0;
}

static inline int
of_set_config_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_set_config.  Len %d too small, < %d", len, 12);
        return -1;
    }

    return 0;
}

static inline int
of_queue_stats_request_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 20) {
        VALIDATOR_LOG("Class of_queue_stats_request.  Len %d too small, < %d", len, 20);
        return -1;
    }

    return 0;
}

static inline int
of_queue_stats_reply_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_queue_stats_reply.  Len %d too small, < %d", len, 12);
        return -1;
    }


    {    int entries_len = len - 12;


        if (of_list_queue_stats_entry_OF_VERSION_1_0_validate(buf + 12, entries_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_queue_op_failed_error_msg_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_queue_op_failed_error_msg.  Len %d too small, < %d", len, 12);
        return -1;
    }

    return 0;
}

static inline int
of_queue_get_config_request_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_queue_get_config_request.  Len %d too small, < %d", len, 12);
        return -1;
    }

    return 0;
}

static inline int
of_queue_get_config_reply_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_queue_get_config_reply.  Len %d too small, < %d", len, 16);
        return -1;
    }


    {    int queues_len = len - 16;


        if (of_list_packet_queue_OF_VERSION_1_0_validate(buf + 16, queues_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_port_status_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 64) {
        VALIDATOR_LOG("Class of_port_status.  Len %d too small, < %d", len, 64);
        return -1;
    }

    return 0;
}

static inline int
of_port_stats_request_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 20) {
        VALIDATOR_LOG("Class of_port_stats_request.  Len %d too small, < %d", len, 20);
        return -1;
    }

    return 0;
}

static inline int
of_port_stats_reply_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_port_stats_reply.  Len %d too small, < %d", len, 12);
        return -1;
    }


    {    int entries_len = len - 12;


        if (of_list_port_stats_entry_OF_VERSION_1_0_validate(buf + 12, entries_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_port_mod_failed_error_msg_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_port_mod_failed_error_msg.  Len %d too small, < %d", len, 12);
        return -1;
    }

    return 0;
}

static inline int
of_port_mod_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 32) {
        VALIDATOR_LOG("Class of_port_mod.  Len %d too small, < %d", len, 32);
        return -1;
    }

    return 0;
}

static inline int
of_packet_out_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_packet_out.  Len %d too small, < %d", len, 16);
        return -1;
    }

    {
        uint16_t actions_len;
        buf_u16_get(buf + 16 - 2, &actions_len);
        if (actions_len + 16 > len) {
            VALIDATOR_LOG("Class of_packet_out, member actions.  "
                          "Len %d and offset %d too big for %d",
                          actions_len, 16, len);
            return -1;
        }

        if (of_list_action_OF_VERSION_1_0_validate(buf + 16, actions_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_packet_in_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 18) {
        VALIDATOR_LOG("Class of_packet_in.  Len %d too small, < %d", len, 18);
        return -1;
    }

    return 0;
}

static inline int
of_nicira_header_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_nicira_header.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_nicira_controller_role_request_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 20) {
        VALIDATOR_LOG("Class of_nicira_controller_role_request.  Len %d too small, < %d", len, 20);
        return -1;
    }

    return 0;
}

static inline int
of_nicira_controller_role_reply_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 20) {
        VALIDATOR_LOG("Class of_nicira_controller_role_reply.  Len %d too small, < %d", len, 20);
        return -1;
    }

    return 0;
}

static inline int
of_hello_failed_error_msg_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_hello_failed_error_msg.  Len %d too small, < %d", len, 12);
        return -1;
    }

    return 0;
}

static inline int
of_hello_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_hello.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_get_config_request_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_get_config_request.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_get_config_reply_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_get_config_reply.  Len %d too small, < %d", len, 12);
        return -1;
    }

    return 0;
}

static inline int
of_flow_stats_request_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 56) {
        VALIDATOR_LOG("Class of_flow_stats_request.  Len %d too small, < %d", len, 56);
        return -1;
    }

    return 0;
}

static inline int
of_flow_stats_reply_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_flow_stats_reply.  Len %d too small, < %d", len, 12);
        return -1;
    }


    {    int entries_len = len - 12;


        if (of_list_flow_stats_entry_OF_VERSION_1_0_validate(buf + 12, entries_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_flow_removed_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 88) {
        VALIDATOR_LOG("Class of_flow_removed.  Len %d too small, < %d", len, 88);
        return -1;
    }

    return 0;
}

static inline int
of_flow_modify_strict_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 72) {
        VALIDATOR_LOG("Class of_flow_modify_strict.  Len %d too small, < %d", len, 72);
        return -1;
    }


    {    int actions_len = len - 72;


        if (of_list_action_OF_VERSION_1_0_validate(buf + 72, actions_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_flow_modify_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 72) {
        VALIDATOR_LOG("Class of_flow_modify.  Len %d too small, < %d", len, 72);
        return -1;
    }


    {    int actions_len = len - 72;


        if (of_list_action_OF_VERSION_1_0_validate(buf + 72, actions_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_flow_mod_failed_error_msg_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_flow_mod_failed_error_msg.  Len %d too small, < %d", len, 12);
        return -1;
    }

    return 0;
}

static inline int
of_flow_mod_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 72) {
        VALIDATOR_LOG("Class of_flow_mod.  Len %d too small, < %d", len, 72);
        return -1;
    }


    {    int actions_len = len - 72;


        if (of_list_action_OF_VERSION_1_0_validate(buf + 72, actions_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_flow_delete_strict_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 72) {
        VALIDATOR_LOG("Class of_flow_delete_strict.  Len %d too small, < %d", len, 72);
        return -1;
    }


    {    int actions_len = len - 72;


        if (of_list_action_OF_VERSION_1_0_validate(buf + 72, actions_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_flow_delete_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 72) {
        VALIDATOR_LOG("Class of_flow_delete.  Len %d too small, < %d", len, 72);
        return -1;
    }


    {    int actions_len = len - 72;


        if (of_list_action_OF_VERSION_1_0_validate(buf + 72, actions_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_flow_add_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 72) {
        VALIDATOR_LOG("Class of_flow_add.  Len %d too small, < %d", len, 72);
        return -1;
    }


    {    int actions_len = len - 72;


        if (of_list_action_OF_VERSION_1_0_validate(buf + 72, actions_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_features_request_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_features_request.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_features_reply_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 32) {
        VALIDATOR_LOG("Class of_features_reply.  Len %d too small, < %d", len, 32);
        return -1;
    }


    {    int ports_len = len - 32;


        if (of_list_port_desc_OF_VERSION_1_0_validate(buf + 32, ports_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_experimenter_stats_request_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_experimenter_stats_request.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_experimenter_stats_reply_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_experimenter_stats_reply.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_experimenter_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_experimenter.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_error_msg_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 10) {
        VALIDATOR_LOG("Class of_error_msg.  Len %d too small, < %d", len, 10);
        return -1;
    }

    return 0;
}

static inline int
of_echo_request_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_echo_request.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_echo_reply_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_echo_reply.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_desc_stats_request_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_desc_stats_request.  Len %d too small, < %d", len, 12);
        return -1;
    }

    return 0;
}

static inline int
of_desc_stats_reply_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 1068) {
        VALIDATOR_LOG("Class of_desc_stats_reply.  Len %d too small, < %d", len, 1068);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_virtual_port_remove_request_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 20) {
        VALIDATOR_LOG("Class of_bsn_virtual_port_remove_request.  Len %d too small, < %d", len, 20);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_virtual_port_remove_reply_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 20) {
        VALIDATOR_LOG("Class of_bsn_virtual_port_remove_reply.  Len %d too small, < %d", len, 20);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_virtual_port_create_request_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 48) {
        VALIDATOR_LOG("Class of_bsn_virtual_port_create_request.  Len %d too small, < %d", len, 48);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_virtual_port_create_reply_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 24) {
        VALIDATOR_LOG("Class of_bsn_virtual_port_create_reply.  Len %d too small, < %d", len, 24);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_stats_request_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 24) {
        VALIDATOR_LOG("Class of_bsn_stats_request.  Len %d too small, < %d", len, 24);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_stats_reply_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 24) {
        VALIDATOR_LOG("Class of_bsn_stats_reply.  Len %d too small, < %d", len, 24);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_shell_status_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 20) {
        VALIDATOR_LOG("Class of_bsn_shell_status.  Len %d too small, < %d", len, 20);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_shell_output_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_bsn_shell_output.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_shell_command_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 20) {
        VALIDATOR_LOG("Class of_bsn_shell_command.  Len %d too small, < %d", len, 20);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_set_pktin_suppression_request_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 32) {
        VALIDATOR_LOG("Class of_bsn_set_pktin_suppression_request.  Len %d too small, < %d", len, 32);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_set_pktin_suppression_reply_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 20) {
        VALIDATOR_LOG("Class of_bsn_set_pktin_suppression_reply.  Len %d too small, < %d", len, 20);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_set_mirroring_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 20) {
        VALIDATOR_LOG("Class of_bsn_set_mirroring.  Len %d too small, < %d", len, 20);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_set_l2_table_request_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 24) {
        VALIDATOR_LOG("Class of_bsn_set_l2_table_request.  Len %d too small, < %d", len, 24);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_set_l2_table_reply_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 24) {
        VALIDATOR_LOG("Class of_bsn_set_l2_table_reply.  Len %d too small, < %d", len, 24);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_set_ip_mask_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 24) {
        VALIDATOR_LOG("Class of_bsn_set_ip_mask.  Len %d too small, < %d", len, 24);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_pdu_tx_request_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 26) {
        VALIDATOR_LOG("Class of_bsn_pdu_tx_request.  Len %d too small, < %d", len, 26);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_pdu_tx_reply_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 23) {
        VALIDATOR_LOG("Class of_bsn_pdu_tx_reply.  Len %d too small, < %d", len, 23);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_pdu_rx_timeout_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 19) {
        VALIDATOR_LOG("Class of_bsn_pdu_rx_timeout.  Len %d too small, < %d", len, 19);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_pdu_rx_request_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 26) {
        VALIDATOR_LOG("Class of_bsn_pdu_rx_request.  Len %d too small, < %d", len, 26);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_pdu_rx_reply_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 23) {
        VALIDATOR_LOG("Class of_bsn_pdu_rx_reply.  Len %d too small, < %d", len, 23);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_hybrid_get_request_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_bsn_hybrid_get_request.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_hybrid_get_reply_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 24) {
        VALIDATOR_LOG("Class of_bsn_hybrid_get_reply.  Len %d too small, < %d", len, 24);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_header_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_bsn_header.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_get_mirroring_request_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 20) {
        VALIDATOR_LOG("Class of_bsn_get_mirroring_request.  Len %d too small, < %d", len, 20);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_get_mirroring_reply_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 20) {
        VALIDATOR_LOG("Class of_bsn_get_mirroring_reply.  Len %d too small, < %d", len, 20);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_get_l2_table_request_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_bsn_get_l2_table_request.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_get_l2_table_reply_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 24) {
        VALIDATOR_LOG("Class of_bsn_get_l2_table_reply.  Len %d too small, < %d", len, 24);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_get_ip_mask_request_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 24) {
        VALIDATOR_LOG("Class of_bsn_get_ip_mask_request.  Len %d too small, < %d", len, 24);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_get_ip_mask_reply_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 24) {
        VALIDATOR_LOG("Class of_bsn_get_ip_mask_reply.  Len %d too small, < %d", len, 24);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_get_interfaces_request_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_bsn_get_interfaces_request.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_get_interfaces_reply_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_bsn_get_interfaces_reply.  Len %d too small, < %d", len, 16);
        return -1;
    }


    {    int interfaces_len = len - 16;


        if (of_list_bsn_interface_OF_VERSION_1_0_validate(buf + 16, interfaces_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_bsn_bw_enable_set_request_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 20) {
        VALIDATOR_LOG("Class of_bsn_bw_enable_set_request.  Len %d too small, < %d", len, 20);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_bw_enable_set_reply_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 24) {
        VALIDATOR_LOG("Class of_bsn_bw_enable_set_reply.  Len %d too small, < %d", len, 24);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_bw_enable_get_request_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_bsn_bw_enable_get_request.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_bw_enable_get_reply_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 20) {
        VALIDATOR_LOG("Class of_bsn_bw_enable_get_reply.  Len %d too small, < %d", len, 20);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_bw_clear_data_request_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_bsn_bw_clear_data_request.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_bw_clear_data_reply_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 20) {
        VALIDATOR_LOG("Class of_bsn_bw_clear_data_reply.  Len %d too small, < %d", len, 20);
        return -1;
    }

    return 0;
}

static inline int
of_barrier_request_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_barrier_request.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_barrier_reply_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_barrier_reply.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_bad_request_error_msg_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_bad_request_error_msg.  Len %d too small, < %d", len, 12);
        return -1;
    }

    return 0;
}

static inline int
of_bad_action_error_msg_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_bad_action_error_msg.  Len %d too small, < %d", len, 12);
        return -1;
    }

    return 0;
}

static inline int
of_aggregate_stats_request_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 56) {
        VALIDATOR_LOG("Class of_aggregate_stats_request.  Len %d too small, < %d", len, 56);
        return -1;
    }

    return 0;
}

static inline int
of_aggregate_stats_reply_OF_VERSION_1_0_validate(uint8_t *buf, int len)
{
    if (len < 36) {
        VALIDATOR_LOG("Class of_aggregate_stats_reply.  Len %d too small, < %d", len, 36);
        return -1;
    }

    return 0;
}

int
of_validate_message_OF_VERSION_1_0(of_message_t msg, int len)
{
    of_object_id_t object_id = of_message_to_object_id(msg, len);
    uint8_t *buf = OF_MESSAGE_TO_BUFFER(msg);
    switch (object_id) {
    case OF_TABLE_STATS_REQUEST:
        return of_table_stats_request_OF_VERSION_1_0_validate(buf, len);
    case OF_TABLE_STATS_REPLY:
        return of_table_stats_reply_OF_VERSION_1_0_validate(buf, len);
    case OF_TABLE_MOD:
        return of_table_mod_OF_VERSION_1_0_validate(buf, len);
    case OF_STATS_REQUEST:
        return of_stats_request_OF_VERSION_1_0_validate(buf, len);
    case OF_STATS_REPLY:
        return of_stats_reply_OF_VERSION_1_0_validate(buf, len);
    case OF_SET_CONFIG:
        return of_set_config_OF_VERSION_1_0_validate(buf, len);
    case OF_QUEUE_STATS_REQUEST:
        return of_queue_stats_request_OF_VERSION_1_0_validate(buf, len);
    case OF_QUEUE_STATS_REPLY:
        return of_queue_stats_reply_OF_VERSION_1_0_validate(buf, len);
    case OF_QUEUE_OP_FAILED_ERROR_MSG:
        return of_queue_op_failed_error_msg_OF_VERSION_1_0_validate(buf, len);
    case OF_QUEUE_GET_CONFIG_REQUEST:
        return of_queue_get_config_request_OF_VERSION_1_0_validate(buf, len);
    case OF_QUEUE_GET_CONFIG_REPLY:
        return of_queue_get_config_reply_OF_VERSION_1_0_validate(buf, len);
    case OF_PORT_STATUS:
        return of_port_status_OF_VERSION_1_0_validate(buf, len);
    case OF_PORT_STATS_REQUEST:
        return of_port_stats_request_OF_VERSION_1_0_validate(buf, len);
    case OF_PORT_STATS_REPLY:
        return of_port_stats_reply_OF_VERSION_1_0_validate(buf, len);
    case OF_PORT_MOD_FAILED_ERROR_MSG:
        return of_port_mod_failed_error_msg_OF_VERSION_1_0_validate(buf, len);
    case OF_PORT_MOD:
        return of_port_mod_OF_VERSION_1_0_validate(buf, len);
    case OF_PACKET_OUT:
        return of_packet_out_OF_VERSION_1_0_validate(buf, len);
    case OF_PACKET_IN:
        return of_packet_in_OF_VERSION_1_0_validate(buf, len);
    case OF_NICIRA_HEADER:
        return of_nicira_header_OF_VERSION_1_0_validate(buf, len);
    case OF_NICIRA_CONTROLLER_ROLE_REQUEST:
        return of_nicira_controller_role_request_OF_VERSION_1_0_validate(buf, len);
    case OF_NICIRA_CONTROLLER_ROLE_REPLY:
        return of_nicira_controller_role_reply_OF_VERSION_1_0_validate(buf, len);
    case OF_HELLO_FAILED_ERROR_MSG:
        return of_hello_failed_error_msg_OF_VERSION_1_0_validate(buf, len);
    case OF_HELLO:
        return of_hello_OF_VERSION_1_0_validate(buf, len);
    case OF_GET_CONFIG_REQUEST:
        return of_get_config_request_OF_VERSION_1_0_validate(buf, len);
    case OF_GET_CONFIG_REPLY:
        return of_get_config_reply_OF_VERSION_1_0_validate(buf, len);
    case OF_FLOW_STATS_REQUEST:
        return of_flow_stats_request_OF_VERSION_1_0_validate(buf, len);
    case OF_FLOW_STATS_REPLY:
        return of_flow_stats_reply_OF_VERSION_1_0_validate(buf, len);
    case OF_FLOW_REMOVED:
        return of_flow_removed_OF_VERSION_1_0_validate(buf, len);
    case OF_FLOW_MODIFY_STRICT:
        return of_flow_modify_strict_OF_VERSION_1_0_validate(buf, len);
    case OF_FLOW_MODIFY:
        return of_flow_modify_OF_VERSION_1_0_validate(buf, len);
    case OF_FLOW_MOD_FAILED_ERROR_MSG:
        return of_flow_mod_failed_error_msg_OF_VERSION_1_0_validate(buf, len);
    case OF_FLOW_MOD:
        return of_flow_mod_OF_VERSION_1_0_validate(buf, len);
    case OF_FLOW_DELETE_STRICT:
        return of_flow_delete_strict_OF_VERSION_1_0_validate(buf, len);
    case OF_FLOW_DELETE:
        return of_flow_delete_OF_VERSION_1_0_validate(buf, len);
    case OF_FLOW_ADD:
        return of_flow_add_OF_VERSION_1_0_validate(buf, len);
    case OF_FEATURES_REQUEST:
        return of_features_request_OF_VERSION_1_0_validate(buf, len);
    case OF_FEATURES_REPLY:
        return of_features_reply_OF_VERSION_1_0_validate(buf, len);
    case OF_EXPERIMENTER_STATS_REQUEST:
        return of_experimenter_stats_request_OF_VERSION_1_0_validate(buf, len);
    case OF_EXPERIMENTER_STATS_REPLY:
        return of_experimenter_stats_reply_OF_VERSION_1_0_validate(buf, len);
    case OF_EXPERIMENTER:
        return of_experimenter_OF_VERSION_1_0_validate(buf, len);
    case OF_ERROR_MSG:
        return of_error_msg_OF_VERSION_1_0_validate(buf, len);
    case OF_ECHO_REQUEST:
        return of_echo_request_OF_VERSION_1_0_validate(buf, len);
    case OF_ECHO_REPLY:
        return of_echo_reply_OF_VERSION_1_0_validate(buf, len);
    case OF_DESC_STATS_REQUEST:
        return of_desc_stats_request_OF_VERSION_1_0_validate(buf, len);
    case OF_DESC_STATS_REPLY:
        return of_desc_stats_reply_OF_VERSION_1_0_validate(buf, len);
    case OF_BSN_VIRTUAL_PORT_REMOVE_REQUEST:
        return of_bsn_virtual_port_remove_request_OF_VERSION_1_0_validate(buf, len);
    case OF_BSN_VIRTUAL_PORT_REMOVE_REPLY:
        return of_bsn_virtual_port_remove_reply_OF_VERSION_1_0_validate(buf, len);
    case OF_BSN_VIRTUAL_PORT_CREATE_REQUEST:
        return of_bsn_virtual_port_create_request_OF_VERSION_1_0_validate(buf, len);
    case OF_BSN_VIRTUAL_PORT_CREATE_REPLY:
        return of_bsn_virtual_port_create_reply_OF_VERSION_1_0_validate(buf, len);
    case OF_BSN_STATS_REQUEST:
        return of_bsn_stats_request_OF_VERSION_1_0_validate(buf, len);
    case OF_BSN_STATS_REPLY:
        return of_bsn_stats_reply_OF_VERSION_1_0_validate(buf, len);
    case OF_BSN_SHELL_STATUS:
        return of_bsn_shell_status_OF_VERSION_1_0_validate(buf, len);
    case OF_BSN_SHELL_OUTPUT:
        return of_bsn_shell_output_OF_VERSION_1_0_validate(buf, len);
    case OF_BSN_SHELL_COMMAND:
        return of_bsn_shell_command_OF_VERSION_1_0_validate(buf, len);
    case OF_BSN_SET_PKTIN_SUPPRESSION_REQUEST:
        return of_bsn_set_pktin_suppression_request_OF_VERSION_1_0_validate(buf, len);
    case OF_BSN_SET_PKTIN_SUPPRESSION_REPLY:
        return of_bsn_set_pktin_suppression_reply_OF_VERSION_1_0_validate(buf, len);
    case OF_BSN_SET_MIRRORING:
        return of_bsn_set_mirroring_OF_VERSION_1_0_validate(buf, len);
    case OF_BSN_SET_L2_TABLE_REQUEST:
        return of_bsn_set_l2_table_request_OF_VERSION_1_0_validate(buf, len);
    case OF_BSN_SET_L2_TABLE_REPLY:
        return of_bsn_set_l2_table_reply_OF_VERSION_1_0_validate(buf, len);
    case OF_BSN_SET_IP_MASK:
        return of_bsn_set_ip_mask_OF_VERSION_1_0_validate(buf, len);
    case OF_BSN_PDU_TX_REQUEST:
        return of_bsn_pdu_tx_request_OF_VERSION_1_0_validate(buf, len);
    case OF_BSN_PDU_TX_REPLY:
        return of_bsn_pdu_tx_reply_OF_VERSION_1_0_validate(buf, len);
    case OF_BSN_PDU_RX_TIMEOUT:
        return of_bsn_pdu_rx_timeout_OF_VERSION_1_0_validate(buf, len);
    case OF_BSN_PDU_RX_REQUEST:
        return of_bsn_pdu_rx_request_OF_VERSION_1_0_validate(buf, len);
    case OF_BSN_PDU_RX_REPLY:
        return of_bsn_pdu_rx_reply_OF_VERSION_1_0_validate(buf, len);
    case OF_BSN_HYBRID_GET_REQUEST:
        return of_bsn_hybrid_get_request_OF_VERSION_1_0_validate(buf, len);
    case OF_BSN_HYBRID_GET_REPLY:
        return of_bsn_hybrid_get_reply_OF_VERSION_1_0_validate(buf, len);
    case OF_BSN_HEADER:
        return of_bsn_header_OF_VERSION_1_0_validate(buf, len);
    case OF_BSN_GET_MIRRORING_REQUEST:
        return of_bsn_get_mirroring_request_OF_VERSION_1_0_validate(buf, len);
    case OF_BSN_GET_MIRRORING_REPLY:
        return of_bsn_get_mirroring_reply_OF_VERSION_1_0_validate(buf, len);
    case OF_BSN_GET_L2_TABLE_REQUEST:
        return of_bsn_get_l2_table_request_OF_VERSION_1_0_validate(buf, len);
    case OF_BSN_GET_L2_TABLE_REPLY:
        return of_bsn_get_l2_table_reply_OF_VERSION_1_0_validate(buf, len);
    case OF_BSN_GET_IP_MASK_REQUEST:
        return of_bsn_get_ip_mask_request_OF_VERSION_1_0_validate(buf, len);
    case OF_BSN_GET_IP_MASK_REPLY:
        return of_bsn_get_ip_mask_reply_OF_VERSION_1_0_validate(buf, len);
    case OF_BSN_GET_INTERFACES_REQUEST:
        return of_bsn_get_interfaces_request_OF_VERSION_1_0_validate(buf, len);
    case OF_BSN_GET_INTERFACES_REPLY:
        return of_bsn_get_interfaces_reply_OF_VERSION_1_0_validate(buf, len);
    case OF_BSN_BW_ENABLE_SET_REQUEST:
        return of_bsn_bw_enable_set_request_OF_VERSION_1_0_validate(buf, len);
    case OF_BSN_BW_ENABLE_SET_REPLY:
        return of_bsn_bw_enable_set_reply_OF_VERSION_1_0_validate(buf, len);
    case OF_BSN_BW_ENABLE_GET_REQUEST:
        return of_bsn_bw_enable_get_request_OF_VERSION_1_0_validate(buf, len);
    case OF_BSN_BW_ENABLE_GET_REPLY:
        return of_bsn_bw_enable_get_reply_OF_VERSION_1_0_validate(buf, len);
    case OF_BSN_BW_CLEAR_DATA_REQUEST:
        return of_bsn_bw_clear_data_request_OF_VERSION_1_0_validate(buf, len);
    case OF_BSN_BW_CLEAR_DATA_REPLY:
        return of_bsn_bw_clear_data_reply_OF_VERSION_1_0_validate(buf, len);
    case OF_BARRIER_REQUEST:
        return of_barrier_request_OF_VERSION_1_0_validate(buf, len);
    case OF_BARRIER_REPLY:
        return of_barrier_reply_OF_VERSION_1_0_validate(buf, len);
    case OF_BAD_REQUEST_ERROR_MSG:
        return of_bad_request_error_msg_OF_VERSION_1_0_validate(buf, len);
    case OF_BAD_ACTION_ERROR_MSG:
        return of_bad_action_error_msg_OF_VERSION_1_0_validate(buf, len);
    case OF_AGGREGATE_STATS_REQUEST:
        return of_aggregate_stats_request_OF_VERSION_1_0_validate(buf, len);
    case OF_AGGREGATE_STATS_REPLY:
        return of_aggregate_stats_reply_OF_VERSION_1_0_validate(buf, len);
    default:
        VALIDATOR_LOG("of_aggregate_stats_reply: could not map OF_AGGREGATE_STATS_REPLY");
        return -1;
    }
}

static inline int
of_list_table_stats_entry_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if ((len / 88) * 88 != len) {
        return -1;
    }

    return 0;
}

static inline int
of_list_queue_stats_entry_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if ((len / 32) * 32 != len) {
        return -1;
    }

    return 0;
}

static inline int
of_list_queue_prop_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    while (len >= 8) {
        of_object_id_t e_id;
        uint16_t e_type, e_len;
        buf_u16_get(buf, &e_type);
        buf_u16_get(buf+2, &e_len);
        e_id = of_queue_prop_to_object_id(e_type, OF_VERSION_1_1);
        switch (e_id) {
        case OF_QUEUE_PROP_MIN_RATE:
            if (of_queue_prop_min_rate_OF_VERSION_1_1_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        default:
            return -1;
        }
        buf += e_len;
        len -= e_len;
    }
    if (len != 0) {
        return -1;
    }

    return 0;
}

static inline int
of_list_port_stats_entry_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if ((len / 104) * 104 != len) {
        return -1;
    }

    return 0;
}

static inline int
of_list_port_desc_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if ((len / 64) * 64 != len) {
        return -1;
    }

    return 0;
}

static inline int
of_list_packet_queue_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    /* XXX unknown element format */

    return 0;
}

static inline int
of_list_instruction_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    while (len >= 8) {
        of_object_id_t e_id;
        uint16_t e_type, e_len;
        buf_u16_get(buf, &e_type);
        buf_u16_get(buf+2, &e_len);
        e_id = of_instruction_to_object_id(e_type, OF_VERSION_1_1);
        switch (e_id) {
        case OF_INSTRUCTION_CLEAR_ACTIONS:
            if (of_instruction_clear_actions_OF_VERSION_1_1_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_INSTRUCTION_WRITE_ACTIONS:
            if (of_instruction_write_actions_OF_VERSION_1_1_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_INSTRUCTION_GOTO_TABLE:
            if (of_instruction_goto_table_OF_VERSION_1_1_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_INSTRUCTION_APPLY_ACTIONS:
            if (of_instruction_apply_actions_OF_VERSION_1_1_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_INSTRUCTION_EXPERIMENTER:
            if (of_instruction_experimenter_OF_VERSION_1_1_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_INSTRUCTION_WRITE_METADATA:
            if (of_instruction_write_metadata_OF_VERSION_1_1_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        default:
            return -1;
        }
        buf += e_len;
        len -= e_len;
    }
    if (len != 0) {
        return -1;
    }

    return 0;
}

static inline int
of_list_group_stats_entry_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    /* TODO verify U16 len elements */

    return 0;
}

static inline int
of_list_group_desc_stats_entry_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    /* TODO verify U16 len elements */

    return 0;
}

static inline int
of_list_flow_stats_entry_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    /* TODO verify U16 len elements */

    return 0;
}

static inline int
of_list_bucket_counter_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if ((len / 16) * 16 != len) {
        return -1;
    }

    return 0;
}

static inline int
of_list_bucket_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    /* TODO verify U16 len elements */

    return 0;
}

static inline int
of_list_bsn_interface_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if ((len / 32) * 32 != len) {
        return -1;
    }

    return 0;
}

static inline int
of_list_action_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    while (len >= 8) {
        of_object_id_t e_id;
        uint16_t e_type, e_len;
        buf_u16_get(buf, &e_type);
        buf_u16_get(buf+2, &e_len);
        e_id = of_action_to_object_id(e_type, OF_VERSION_1_1);
        switch (e_id) {
        case OF_ACTION_COPY_TTL_OUT:
            if (of_action_copy_ttl_out_OF_VERSION_1_1_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_SET_MPLS_TC:
            if (of_action_set_mpls_tc_OF_VERSION_1_1_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_BSN_MIRROR:
            if (of_action_bsn_mirror_OF_VERSION_1_1_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_SET_NW_TOS:
            if (of_action_set_nw_tos_OF_VERSION_1_1_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_DEC_MPLS_TTL:
            if (of_action_dec_mpls_ttl_OF_VERSION_1_1_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_BSN_SET_TUNNEL_DST:
            if (of_action_bsn_set_tunnel_dst_OF_VERSION_1_1_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_SET_NW_DST:
            if (of_action_set_nw_dst_OF_VERSION_1_1_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_SET_MPLS_LABEL:
            if (of_action_set_mpls_label_OF_VERSION_1_1_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_GROUP:
            if (of_action_group_OF_VERSION_1_1_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_SET_NW_SRC:
            if (of_action_set_nw_src_OF_VERSION_1_1_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_SET_VLAN_VID:
            if (of_action_set_vlan_vid_OF_VERSION_1_1_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_SET_MPLS_TTL:
            if (of_action_set_mpls_ttl_OF_VERSION_1_1_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_POP_VLAN:
            if (of_action_pop_vlan_OF_VERSION_1_1_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_NICIRA_DEC_TTL:
            if (of_action_nicira_dec_ttl_OF_VERSION_1_1_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_SET_TP_DST:
            if (of_action_set_tp_dst_OF_VERSION_1_1_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_POP_MPLS:
            if (of_action_pop_mpls_OF_VERSION_1_1_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_PUSH_VLAN:
            if (of_action_push_vlan_OF_VERSION_1_1_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_SET_VLAN_PCP:
            if (of_action_set_vlan_pcp_OF_VERSION_1_1_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_BSN:
            if (of_action_bsn_OF_VERSION_1_1_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_EXPERIMENTER:
            if (of_action_experimenter_OF_VERSION_1_1_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_SET_NW_TTL:
            if (of_action_set_nw_ttl_OF_VERSION_1_1_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_COPY_TTL_IN:
            if (of_action_copy_ttl_in_OF_VERSION_1_1_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_NICIRA:
            if (of_action_nicira_OF_VERSION_1_1_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_SET_NW_ECN:
            if (of_action_set_nw_ecn_OF_VERSION_1_1_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_SET_DL_DST:
            if (of_action_set_dl_dst_OF_VERSION_1_1_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_PUSH_MPLS:
            if (of_action_push_mpls_OF_VERSION_1_1_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_SET_TP_SRC:
            if (of_action_set_tp_src_OF_VERSION_1_1_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_DEC_NW_TTL:
            if (of_action_dec_nw_ttl_OF_VERSION_1_1_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_SET_DL_SRC:
            if (of_action_set_dl_src_OF_VERSION_1_1_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_SET_QUEUE:
            if (of_action_set_queue_OF_VERSION_1_1_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_OUTPUT:
            if (of_action_output_OF_VERSION_1_1_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        default:
            return -1;
        }
        buf += e_len;
        len -= e_len;
    }
    if (len != 0) {
        return -1;
    }

    return 0;
}

static inline int
of_table_stats_entry_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 88) {
        VALIDATOR_LOG("Class of_table_stats_entry.  Len %d too small, < %d", len, 88);
        return -1;
    }

    return 0;
}

static inline int
of_queue_stats_entry_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 32) {
        VALIDATOR_LOG("Class of_queue_stats_entry.  Len %d too small, < %d", len, 32);
        return -1;
    }

    return 0;
}

static inline int
of_queue_prop_min_rate_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_queue_prop_min_rate.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_queue_prop_header_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_queue_prop_header.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_port_stats_entry_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 104) {
        VALIDATOR_LOG("Class of_port_stats_entry.  Len %d too small, < %d", len, 104);
        return -1;
    }

    return 0;
}

static inline int
of_port_desc_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 64) {
        VALIDATOR_LOG("Class of_port_desc.  Len %d too small, < %d", len, 64);
        return -1;
    }

    return 0;
}

static inline int
of_packet_queue_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_packet_queue.  Len %d too small, < %d", len, 8);
        return -1;
    }


    {    int properties_len = len - 8;


        if (of_list_queue_prop_OF_VERSION_1_1_validate(buf + 8, properties_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_match_v2_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 88) {
        VALIDATOR_LOG("Class of_match_v2.  Len %d too small, < %d", len, 88);
        return -1;
    }

    return 0;
}

static inline int
of_instruction_write_metadata_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 24) {
        VALIDATOR_LOG("Class of_instruction_write_metadata.  Len %d too small, < %d", len, 24);
        return -1;
    }

    return 0;
}

static inline int
of_instruction_write_actions_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_instruction_write_actions.  Len %d too small, < %d", len, 8);
        return -1;
    }


    {    int actions_len = len - 8;


        if (of_list_action_OF_VERSION_1_1_validate(buf + 8, actions_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_instruction_header_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_instruction_header.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_instruction_goto_table_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_instruction_goto_table.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_instruction_experimenter_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_instruction_experimenter.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_instruction_clear_actions_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_instruction_clear_actions.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_instruction_apply_actions_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_instruction_apply_actions.  Len %d too small, < %d", len, 8);
        return -1;
    }


    {    int actions_len = len - 8;


        if (of_list_action_OF_VERSION_1_1_validate(buf + 8, actions_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_header_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_header.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_group_stats_entry_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 32) {
        VALIDATOR_LOG("Class of_group_stats_entry.  Len %d too small, < %d", len, 32);
        return -1;
    }


    {    int bucket_stats_len = len - 32;


        if (of_list_bucket_counter_OF_VERSION_1_1_validate(buf + 32, bucket_stats_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_group_desc_stats_entry_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_group_desc_stats_entry.  Len %d too small, < %d", len, 8);
        return -1;
    }


    {    int buckets_len = len - 8;


        if (of_list_bucket_OF_VERSION_1_1_validate(buf + 8, buckets_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_flow_stats_entry_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 136) {
        VALIDATOR_LOG("Class of_flow_stats_entry.  Len %d too small, < %d", len, 136);
        return -1;
    }


    {    int instructions_len = len - 136;


        if (of_list_instruction_OF_VERSION_1_1_validate(buf + 136, instructions_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_bucket_counter_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_bucket_counter.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_bucket_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_bucket.  Len %d too small, < %d", len, 16);
        return -1;
    }


    {    int actions_len = len - 16;


        if (of_list_action_OF_VERSION_1_1_validate(buf + 16, actions_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_bsn_vport_q_in_q_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 32) {
        VALIDATOR_LOG("Class of_bsn_vport_q_in_q.  Len %d too small, < %d", len, 32);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_vport_header_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 4) {
        VALIDATOR_LOG("Class of_bsn_vport_header.  Len %d too small, < %d", len, 4);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_interface_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 32) {
        VALIDATOR_LOG("Class of_bsn_interface.  Len %d too small, < %d", len, 32);
        return -1;
    }

    return 0;
}

static inline int
of_action_set_vlan_vid_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_action_set_vlan_vid.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_action_set_vlan_pcp_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_action_set_vlan_pcp.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_action_set_tp_src_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_action_set_tp_src.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_action_set_tp_dst_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_action_set_tp_dst.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_action_set_queue_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_action_set_queue.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_action_set_nw_ttl_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_action_set_nw_ttl.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_action_set_nw_tos_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_action_set_nw_tos.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_action_set_nw_src_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_action_set_nw_src.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_action_set_nw_ecn_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_action_set_nw_ecn.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_action_set_nw_dst_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_action_set_nw_dst.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_action_set_mpls_ttl_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_action_set_mpls_ttl.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_action_set_mpls_tc_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_action_set_mpls_tc.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_action_set_mpls_label_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_action_set_mpls_label.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_action_set_dl_src_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_action_set_dl_src.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_action_set_dl_dst_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_action_set_dl_dst.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_action_push_vlan_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_action_push_vlan.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_action_push_mpls_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_action_push_mpls.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_action_pop_vlan_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_action_pop_vlan.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_action_pop_mpls_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_action_pop_mpls.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_action_output_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_action_output.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_action_nicira_dec_ttl_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_action_nicira_dec_ttl.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_action_nicira_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_action_nicira.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_action_header_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_action_header.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_action_group_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_action_group.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_action_experimenter_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_action_experimenter.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_action_dec_nw_ttl_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_action_dec_nw_ttl.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_action_dec_mpls_ttl_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_action_dec_mpls_ttl.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_action_copy_ttl_out_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_action_copy_ttl_out.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_action_copy_ttl_in_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_action_copy_ttl_in.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_action_bsn_set_tunnel_dst_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_action_bsn_set_tunnel_dst.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_action_bsn_mirror_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 24) {
        VALIDATOR_LOG("Class of_action_bsn_mirror.  Len %d too small, < %d", len, 24);
        return -1;
    }

    return 0;
}

static inline int
of_action_bsn_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_action_bsn.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_table_stats_request_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_table_stats_request.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_table_stats_reply_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_table_stats_reply.  Len %d too small, < %d", len, 16);
        return -1;
    }


    {    int entries_len = len - 16;


        if (of_list_table_stats_entry_OF_VERSION_1_1_validate(buf + 16, entries_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_table_mod_failed_error_msg_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_table_mod_failed_error_msg.  Len %d too small, < %d", len, 12);
        return -1;
    }

    return 0;
}

static inline int
of_table_mod_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_table_mod.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_switch_config_failed_error_msg_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_switch_config_failed_error_msg.  Len %d too small, < %d", len, 12);
        return -1;
    }

    return 0;
}

static inline int
of_stats_request_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_stats_request.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_stats_reply_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_stats_reply.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_set_config_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_set_config.  Len %d too small, < %d", len, 12);
        return -1;
    }

    return 0;
}

static inline int
of_queue_stats_request_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 24) {
        VALIDATOR_LOG("Class of_queue_stats_request.  Len %d too small, < %d", len, 24);
        return -1;
    }

    return 0;
}

static inline int
of_queue_stats_reply_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_queue_stats_reply.  Len %d too small, < %d", len, 16);
        return -1;
    }


    {    int entries_len = len - 16;


        if (of_list_queue_stats_entry_OF_VERSION_1_1_validate(buf + 16, entries_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_queue_op_failed_error_msg_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_queue_op_failed_error_msg.  Len %d too small, < %d", len, 12);
        return -1;
    }

    return 0;
}

static inline int
of_queue_get_config_request_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_queue_get_config_request.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_queue_get_config_reply_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_queue_get_config_reply.  Len %d too small, < %d", len, 16);
        return -1;
    }


    {    int queues_len = len - 16;


        if (of_list_packet_queue_OF_VERSION_1_1_validate(buf + 16, queues_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_port_status_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 80) {
        VALIDATOR_LOG("Class of_port_status.  Len %d too small, < %d", len, 80);
        return -1;
    }

    return 0;
}

static inline int
of_port_stats_request_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 24) {
        VALIDATOR_LOG("Class of_port_stats_request.  Len %d too small, < %d", len, 24);
        return -1;
    }

    return 0;
}

static inline int
of_port_stats_reply_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_port_stats_reply.  Len %d too small, < %d", len, 16);
        return -1;
    }


    {    int entries_len = len - 16;


        if (of_list_port_stats_entry_OF_VERSION_1_1_validate(buf + 16, entries_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_port_mod_failed_error_msg_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_port_mod_failed_error_msg.  Len %d too small, < %d", len, 12);
        return -1;
    }

    return 0;
}

static inline int
of_port_mod_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 40) {
        VALIDATOR_LOG("Class of_port_mod.  Len %d too small, < %d", len, 40);
        return -1;
    }

    return 0;
}

static inline int
of_packet_out_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 24) {
        VALIDATOR_LOG("Class of_packet_out.  Len %d too small, < %d", len, 24);
        return -1;
    }

    {
        uint16_t actions_len;
        buf_u16_get(buf + 24 - 2, &actions_len);
        if (actions_len + 24 > len) {
            VALIDATOR_LOG("Class of_packet_out, member actions.  "
                          "Len %d and offset %d too big for %d",
                          actions_len, 24, len);
            return -1;
        }

        if (of_list_action_OF_VERSION_1_1_validate(buf + 24, actions_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_packet_in_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 24) {
        VALIDATOR_LOG("Class of_packet_in.  Len %d too small, < %d", len, 24);
        return -1;
    }

    return 0;
}

static inline int
of_nicira_header_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_nicira_header.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_hello_failed_error_msg_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_hello_failed_error_msg.  Len %d too small, < %d", len, 12);
        return -1;
    }

    return 0;
}

static inline int
of_hello_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_hello.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_group_stats_request_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 24) {
        VALIDATOR_LOG("Class of_group_stats_request.  Len %d too small, < %d", len, 24);
        return -1;
    }

    return 0;
}

static inline int
of_group_stats_reply_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_group_stats_reply.  Len %d too small, < %d", len, 16);
        return -1;
    }


    {    int entries_len = len - 16;


        if (of_list_group_stats_entry_OF_VERSION_1_1_validate(buf + 16, entries_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_group_modify_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_group_modify.  Len %d too small, < %d", len, 16);
        return -1;
    }


    {    int buckets_len = len - 16;


        if (of_list_bucket_OF_VERSION_1_1_validate(buf + 16, buckets_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_group_mod_failed_error_msg_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_group_mod_failed_error_msg.  Len %d too small, < %d", len, 12);
        return -1;
    }

    return 0;
}

static inline int
of_group_mod_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_group_mod.  Len %d too small, < %d", len, 16);
        return -1;
    }


    {    int buckets_len = len - 16;


        if (of_list_bucket_OF_VERSION_1_1_validate(buf + 16, buckets_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_group_desc_stats_request_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_group_desc_stats_request.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_group_desc_stats_reply_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_group_desc_stats_reply.  Len %d too small, < %d", len, 16);
        return -1;
    }


    {    int entries_len = len - 16;


        if (of_list_group_desc_stats_entry_OF_VERSION_1_1_validate(buf + 16, entries_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_group_delete_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_group_delete.  Len %d too small, < %d", len, 16);
        return -1;
    }


    {    int buckets_len = len - 16;


        if (of_list_bucket_OF_VERSION_1_1_validate(buf + 16, buckets_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_group_add_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_group_add.  Len %d too small, < %d", len, 16);
        return -1;
    }


    {    int buckets_len = len - 16;


        if (of_list_bucket_OF_VERSION_1_1_validate(buf + 16, buckets_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_get_config_request_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_get_config_request.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_get_config_reply_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_get_config_reply.  Len %d too small, < %d", len, 12);
        return -1;
    }

    return 0;
}

static inline int
of_flow_stats_request_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 136) {
        VALIDATOR_LOG("Class of_flow_stats_request.  Len %d too small, < %d", len, 136);
        return -1;
    }

    return 0;
}

static inline int
of_flow_stats_reply_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_flow_stats_reply.  Len %d too small, < %d", len, 16);
        return -1;
    }


    {    int entries_len = len - 16;


        if (of_list_flow_stats_entry_OF_VERSION_1_1_validate(buf + 16, entries_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_flow_removed_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 136) {
        VALIDATOR_LOG("Class of_flow_removed.  Len %d too small, < %d", len, 136);
        return -1;
    }

    return 0;
}

static inline int
of_flow_modify_strict_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 136) {
        VALIDATOR_LOG("Class of_flow_modify_strict.  Len %d too small, < %d", len, 136);
        return -1;
    }


    {    int instructions_len = len - 136;


        if (of_list_instruction_OF_VERSION_1_1_validate(buf + 136, instructions_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_flow_modify_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 136) {
        VALIDATOR_LOG("Class of_flow_modify.  Len %d too small, < %d", len, 136);
        return -1;
    }


    {    int instructions_len = len - 136;


        if (of_list_instruction_OF_VERSION_1_1_validate(buf + 136, instructions_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_flow_mod_failed_error_msg_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_flow_mod_failed_error_msg.  Len %d too small, < %d", len, 12);
        return -1;
    }

    return 0;
}

static inline int
of_flow_mod_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 136) {
        VALIDATOR_LOG("Class of_flow_mod.  Len %d too small, < %d", len, 136);
        return -1;
    }


    {    int instructions_len = len - 136;


        if (of_list_instruction_OF_VERSION_1_1_validate(buf + 136, instructions_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_flow_delete_strict_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 136) {
        VALIDATOR_LOG("Class of_flow_delete_strict.  Len %d too small, < %d", len, 136);
        return -1;
    }


    {    int instructions_len = len - 136;


        if (of_list_instruction_OF_VERSION_1_1_validate(buf + 136, instructions_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_flow_delete_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 136) {
        VALIDATOR_LOG("Class of_flow_delete.  Len %d too small, < %d", len, 136);
        return -1;
    }


    {    int instructions_len = len - 136;


        if (of_list_instruction_OF_VERSION_1_1_validate(buf + 136, instructions_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_flow_add_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 136) {
        VALIDATOR_LOG("Class of_flow_add.  Len %d too small, < %d", len, 136);
        return -1;
    }


    {    int instructions_len = len - 136;


        if (of_list_instruction_OF_VERSION_1_1_validate(buf + 136, instructions_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_features_request_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_features_request.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_features_reply_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 32) {
        VALIDATOR_LOG("Class of_features_reply.  Len %d too small, < %d", len, 32);
        return -1;
    }


    {    int ports_len = len - 32;


        if (of_list_port_desc_OF_VERSION_1_1_validate(buf + 32, ports_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_experimenter_stats_request_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 24) {
        VALIDATOR_LOG("Class of_experimenter_stats_request.  Len %d too small, < %d", len, 24);
        return -1;
    }

    return 0;
}

static inline int
of_experimenter_stats_reply_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 24) {
        VALIDATOR_LOG("Class of_experimenter_stats_reply.  Len %d too small, < %d", len, 24);
        return -1;
    }

    return 0;
}

static inline int
of_experimenter_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_experimenter.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_error_msg_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 10) {
        VALIDATOR_LOG("Class of_error_msg.  Len %d too small, < %d", len, 10);
        return -1;
    }

    return 0;
}

static inline int
of_echo_request_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_echo_request.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_echo_reply_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_echo_reply.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_desc_stats_request_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_desc_stats_request.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_desc_stats_reply_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 1072) {
        VALIDATOR_LOG("Class of_desc_stats_reply.  Len %d too small, < %d", len, 1072);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_virtual_port_remove_request_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 20) {
        VALIDATOR_LOG("Class of_bsn_virtual_port_remove_request.  Len %d too small, < %d", len, 20);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_virtual_port_remove_reply_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 20) {
        VALIDATOR_LOG("Class of_bsn_virtual_port_remove_reply.  Len %d too small, < %d", len, 20);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_virtual_port_create_request_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 48) {
        VALIDATOR_LOG("Class of_bsn_virtual_port_create_request.  Len %d too small, < %d", len, 48);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_virtual_port_create_reply_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 24) {
        VALIDATOR_LOG("Class of_bsn_virtual_port_create_reply.  Len %d too small, < %d", len, 24);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_stats_request_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 24) {
        VALIDATOR_LOG("Class of_bsn_stats_request.  Len %d too small, < %d", len, 24);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_stats_reply_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 24) {
        VALIDATOR_LOG("Class of_bsn_stats_reply.  Len %d too small, < %d", len, 24);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_set_pktin_suppression_request_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 32) {
        VALIDATOR_LOG("Class of_bsn_set_pktin_suppression_request.  Len %d too small, < %d", len, 32);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_set_pktin_suppression_reply_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 20) {
        VALIDATOR_LOG("Class of_bsn_set_pktin_suppression_reply.  Len %d too small, < %d", len, 20);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_set_mirroring_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 20) {
        VALIDATOR_LOG("Class of_bsn_set_mirroring.  Len %d too small, < %d", len, 20);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_pdu_tx_request_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 28) {
        VALIDATOR_LOG("Class of_bsn_pdu_tx_request.  Len %d too small, < %d", len, 28);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_pdu_tx_reply_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 25) {
        VALIDATOR_LOG("Class of_bsn_pdu_tx_reply.  Len %d too small, < %d", len, 25);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_pdu_rx_timeout_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 21) {
        VALIDATOR_LOG("Class of_bsn_pdu_rx_timeout.  Len %d too small, < %d", len, 21);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_pdu_rx_request_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 28) {
        VALIDATOR_LOG("Class of_bsn_pdu_rx_request.  Len %d too small, < %d", len, 28);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_pdu_rx_reply_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 25) {
        VALIDATOR_LOG("Class of_bsn_pdu_rx_reply.  Len %d too small, < %d", len, 25);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_header_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_bsn_header.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_get_mirroring_request_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 20) {
        VALIDATOR_LOG("Class of_bsn_get_mirroring_request.  Len %d too small, < %d", len, 20);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_get_mirroring_reply_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 20) {
        VALIDATOR_LOG("Class of_bsn_get_mirroring_reply.  Len %d too small, < %d", len, 20);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_get_interfaces_request_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_bsn_get_interfaces_request.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_get_interfaces_reply_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_bsn_get_interfaces_reply.  Len %d too small, < %d", len, 16);
        return -1;
    }


    {    int interfaces_len = len - 16;


        if (of_list_bsn_interface_OF_VERSION_1_1_validate(buf + 16, interfaces_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_bsn_bw_enable_set_request_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 20) {
        VALIDATOR_LOG("Class of_bsn_bw_enable_set_request.  Len %d too small, < %d", len, 20);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_bw_enable_set_reply_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 24) {
        VALIDATOR_LOG("Class of_bsn_bw_enable_set_reply.  Len %d too small, < %d", len, 24);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_bw_enable_get_request_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_bsn_bw_enable_get_request.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_bw_enable_get_reply_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 20) {
        VALIDATOR_LOG("Class of_bsn_bw_enable_get_reply.  Len %d too small, < %d", len, 20);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_bw_clear_data_request_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_bsn_bw_clear_data_request.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_bw_clear_data_reply_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 20) {
        VALIDATOR_LOG("Class of_bsn_bw_clear_data_reply.  Len %d too small, < %d", len, 20);
        return -1;
    }

    return 0;
}

static inline int
of_barrier_request_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_barrier_request.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_barrier_reply_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_barrier_reply.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_bad_request_error_msg_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_bad_request_error_msg.  Len %d too small, < %d", len, 12);
        return -1;
    }

    return 0;
}

static inline int
of_bad_match_error_msg_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_bad_match_error_msg.  Len %d too small, < %d", len, 12);
        return -1;
    }

    return 0;
}

static inline int
of_bad_instruction_error_msg_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_bad_instruction_error_msg.  Len %d too small, < %d", len, 12);
        return -1;
    }

    return 0;
}

static inline int
of_bad_action_error_msg_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_bad_action_error_msg.  Len %d too small, < %d", len, 12);
        return -1;
    }

    return 0;
}

static inline int
of_aggregate_stats_request_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 136) {
        VALIDATOR_LOG("Class of_aggregate_stats_request.  Len %d too small, < %d", len, 136);
        return -1;
    }

    return 0;
}

static inline int
of_aggregate_stats_reply_OF_VERSION_1_1_validate(uint8_t *buf, int len)
{
    if (len < 40) {
        VALIDATOR_LOG("Class of_aggregate_stats_reply.  Len %d too small, < %d", len, 40);
        return -1;
    }

    return 0;
}

int
of_validate_message_OF_VERSION_1_1(of_message_t msg, int len)
{
    of_object_id_t object_id = of_message_to_object_id(msg, len);
    uint8_t *buf = OF_MESSAGE_TO_BUFFER(msg);
    switch (object_id) {
    case OF_TABLE_STATS_REQUEST:
        return of_table_stats_request_OF_VERSION_1_1_validate(buf, len);
    case OF_TABLE_STATS_REPLY:
        return of_table_stats_reply_OF_VERSION_1_1_validate(buf, len);
    case OF_TABLE_MOD_FAILED_ERROR_MSG:
        return of_table_mod_failed_error_msg_OF_VERSION_1_1_validate(buf, len);
    case OF_TABLE_MOD:
        return of_table_mod_OF_VERSION_1_1_validate(buf, len);
    case OF_SWITCH_CONFIG_FAILED_ERROR_MSG:
        return of_switch_config_failed_error_msg_OF_VERSION_1_1_validate(buf, len);
    case OF_STATS_REQUEST:
        return of_stats_request_OF_VERSION_1_1_validate(buf, len);
    case OF_STATS_REPLY:
        return of_stats_reply_OF_VERSION_1_1_validate(buf, len);
    case OF_SET_CONFIG:
        return of_set_config_OF_VERSION_1_1_validate(buf, len);
    case OF_QUEUE_STATS_REQUEST:
        return of_queue_stats_request_OF_VERSION_1_1_validate(buf, len);
    case OF_QUEUE_STATS_REPLY:
        return of_queue_stats_reply_OF_VERSION_1_1_validate(buf, len);
    case OF_QUEUE_OP_FAILED_ERROR_MSG:
        return of_queue_op_failed_error_msg_OF_VERSION_1_1_validate(buf, len);
    case OF_QUEUE_GET_CONFIG_REQUEST:
        return of_queue_get_config_request_OF_VERSION_1_1_validate(buf, len);
    case OF_QUEUE_GET_CONFIG_REPLY:
        return of_queue_get_config_reply_OF_VERSION_1_1_validate(buf, len);
    case OF_PORT_STATUS:
        return of_port_status_OF_VERSION_1_1_validate(buf, len);
    case OF_PORT_STATS_REQUEST:
        return of_port_stats_request_OF_VERSION_1_1_validate(buf, len);
    case OF_PORT_STATS_REPLY:
        return of_port_stats_reply_OF_VERSION_1_1_validate(buf, len);
    case OF_PORT_MOD_FAILED_ERROR_MSG:
        return of_port_mod_failed_error_msg_OF_VERSION_1_1_validate(buf, len);
    case OF_PORT_MOD:
        return of_port_mod_OF_VERSION_1_1_validate(buf, len);
    case OF_PACKET_OUT:
        return of_packet_out_OF_VERSION_1_1_validate(buf, len);
    case OF_PACKET_IN:
        return of_packet_in_OF_VERSION_1_1_validate(buf, len);
    case OF_NICIRA_HEADER:
        return of_nicira_header_OF_VERSION_1_1_validate(buf, len);
    case OF_HELLO_FAILED_ERROR_MSG:
        return of_hello_failed_error_msg_OF_VERSION_1_1_validate(buf, len);
    case OF_HELLO:
        return of_hello_OF_VERSION_1_1_validate(buf, len);
    case OF_GROUP_STATS_REQUEST:
        return of_group_stats_request_OF_VERSION_1_1_validate(buf, len);
    case OF_GROUP_STATS_REPLY:
        return of_group_stats_reply_OF_VERSION_1_1_validate(buf, len);
    case OF_GROUP_MODIFY:
        return of_group_modify_OF_VERSION_1_1_validate(buf, len);
    case OF_GROUP_MOD_FAILED_ERROR_MSG:
        return of_group_mod_failed_error_msg_OF_VERSION_1_1_validate(buf, len);
    case OF_GROUP_MOD:
        return of_group_mod_OF_VERSION_1_1_validate(buf, len);
    case OF_GROUP_DESC_STATS_REQUEST:
        return of_group_desc_stats_request_OF_VERSION_1_1_validate(buf, len);
    case OF_GROUP_DESC_STATS_REPLY:
        return of_group_desc_stats_reply_OF_VERSION_1_1_validate(buf, len);
    case OF_GROUP_DELETE:
        return of_group_delete_OF_VERSION_1_1_validate(buf, len);
    case OF_GROUP_ADD:
        return of_group_add_OF_VERSION_1_1_validate(buf, len);
    case OF_GET_CONFIG_REQUEST:
        return of_get_config_request_OF_VERSION_1_1_validate(buf, len);
    case OF_GET_CONFIG_REPLY:
        return of_get_config_reply_OF_VERSION_1_1_validate(buf, len);
    case OF_FLOW_STATS_REQUEST:
        return of_flow_stats_request_OF_VERSION_1_1_validate(buf, len);
    case OF_FLOW_STATS_REPLY:
        return of_flow_stats_reply_OF_VERSION_1_1_validate(buf, len);
    case OF_FLOW_REMOVED:
        return of_flow_removed_OF_VERSION_1_1_validate(buf, len);
    case OF_FLOW_MODIFY_STRICT:
        return of_flow_modify_strict_OF_VERSION_1_1_validate(buf, len);
    case OF_FLOW_MODIFY:
        return of_flow_modify_OF_VERSION_1_1_validate(buf, len);
    case OF_FLOW_MOD_FAILED_ERROR_MSG:
        return of_flow_mod_failed_error_msg_OF_VERSION_1_1_validate(buf, len);
    case OF_FLOW_MOD:
        return of_flow_mod_OF_VERSION_1_1_validate(buf, len);
    case OF_FLOW_DELETE_STRICT:
        return of_flow_delete_strict_OF_VERSION_1_1_validate(buf, len);
    case OF_FLOW_DELETE:
        return of_flow_delete_OF_VERSION_1_1_validate(buf, len);
    case OF_FLOW_ADD:
        return of_flow_add_OF_VERSION_1_1_validate(buf, len);
    case OF_FEATURES_REQUEST:
        return of_features_request_OF_VERSION_1_1_validate(buf, len);
    case OF_FEATURES_REPLY:
        return of_features_reply_OF_VERSION_1_1_validate(buf, len);
    case OF_EXPERIMENTER_STATS_REQUEST:
        return of_experimenter_stats_request_OF_VERSION_1_1_validate(buf, len);
    case OF_EXPERIMENTER_STATS_REPLY:
        return of_experimenter_stats_reply_OF_VERSION_1_1_validate(buf, len);
    case OF_EXPERIMENTER:
        return of_experimenter_OF_VERSION_1_1_validate(buf, len);
    case OF_ERROR_MSG:
        return of_error_msg_OF_VERSION_1_1_validate(buf, len);
    case OF_ECHO_REQUEST:
        return of_echo_request_OF_VERSION_1_1_validate(buf, len);
    case OF_ECHO_REPLY:
        return of_echo_reply_OF_VERSION_1_1_validate(buf, len);
    case OF_DESC_STATS_REQUEST:
        return of_desc_stats_request_OF_VERSION_1_1_validate(buf, len);
    case OF_DESC_STATS_REPLY:
        return of_desc_stats_reply_OF_VERSION_1_1_validate(buf, len);
    case OF_BSN_VIRTUAL_PORT_REMOVE_REQUEST:
        return of_bsn_virtual_port_remove_request_OF_VERSION_1_1_validate(buf, len);
    case OF_BSN_VIRTUAL_PORT_REMOVE_REPLY:
        return of_bsn_virtual_port_remove_reply_OF_VERSION_1_1_validate(buf, len);
    case OF_BSN_VIRTUAL_PORT_CREATE_REQUEST:
        return of_bsn_virtual_port_create_request_OF_VERSION_1_1_validate(buf, len);
    case OF_BSN_VIRTUAL_PORT_CREATE_REPLY:
        return of_bsn_virtual_port_create_reply_OF_VERSION_1_1_validate(buf, len);
    case OF_BSN_STATS_REQUEST:
        return of_bsn_stats_request_OF_VERSION_1_1_validate(buf, len);
    case OF_BSN_STATS_REPLY:
        return of_bsn_stats_reply_OF_VERSION_1_1_validate(buf, len);
    case OF_BSN_SET_PKTIN_SUPPRESSION_REQUEST:
        return of_bsn_set_pktin_suppression_request_OF_VERSION_1_1_validate(buf, len);
    case OF_BSN_SET_PKTIN_SUPPRESSION_REPLY:
        return of_bsn_set_pktin_suppression_reply_OF_VERSION_1_1_validate(buf, len);
    case OF_BSN_SET_MIRRORING:
        return of_bsn_set_mirroring_OF_VERSION_1_1_validate(buf, len);
    case OF_BSN_PDU_TX_REQUEST:
        return of_bsn_pdu_tx_request_OF_VERSION_1_1_validate(buf, len);
    case OF_BSN_PDU_TX_REPLY:
        return of_bsn_pdu_tx_reply_OF_VERSION_1_1_validate(buf, len);
    case OF_BSN_PDU_RX_TIMEOUT:
        return of_bsn_pdu_rx_timeout_OF_VERSION_1_1_validate(buf, len);
    case OF_BSN_PDU_RX_REQUEST:
        return of_bsn_pdu_rx_request_OF_VERSION_1_1_validate(buf, len);
    case OF_BSN_PDU_RX_REPLY:
        return of_bsn_pdu_rx_reply_OF_VERSION_1_1_validate(buf, len);
    case OF_BSN_HEADER:
        return of_bsn_header_OF_VERSION_1_1_validate(buf, len);
    case OF_BSN_GET_MIRRORING_REQUEST:
        return of_bsn_get_mirroring_request_OF_VERSION_1_1_validate(buf, len);
    case OF_BSN_GET_MIRRORING_REPLY:
        return of_bsn_get_mirroring_reply_OF_VERSION_1_1_validate(buf, len);
    case OF_BSN_GET_INTERFACES_REQUEST:
        return of_bsn_get_interfaces_request_OF_VERSION_1_1_validate(buf, len);
    case OF_BSN_GET_INTERFACES_REPLY:
        return of_bsn_get_interfaces_reply_OF_VERSION_1_1_validate(buf, len);
    case OF_BSN_BW_ENABLE_SET_REQUEST:
        return of_bsn_bw_enable_set_request_OF_VERSION_1_1_validate(buf, len);
    case OF_BSN_BW_ENABLE_SET_REPLY:
        return of_bsn_bw_enable_set_reply_OF_VERSION_1_1_validate(buf, len);
    case OF_BSN_BW_ENABLE_GET_REQUEST:
        return of_bsn_bw_enable_get_request_OF_VERSION_1_1_validate(buf, len);
    case OF_BSN_BW_ENABLE_GET_REPLY:
        return of_bsn_bw_enable_get_reply_OF_VERSION_1_1_validate(buf, len);
    case OF_BSN_BW_CLEAR_DATA_REQUEST:
        return of_bsn_bw_clear_data_request_OF_VERSION_1_1_validate(buf, len);
    case OF_BSN_BW_CLEAR_DATA_REPLY:
        return of_bsn_bw_clear_data_reply_OF_VERSION_1_1_validate(buf, len);
    case OF_BARRIER_REQUEST:
        return of_barrier_request_OF_VERSION_1_1_validate(buf, len);
    case OF_BARRIER_REPLY:
        return of_barrier_reply_OF_VERSION_1_1_validate(buf, len);
    case OF_BAD_REQUEST_ERROR_MSG:
        return of_bad_request_error_msg_OF_VERSION_1_1_validate(buf, len);
    case OF_BAD_MATCH_ERROR_MSG:
        return of_bad_match_error_msg_OF_VERSION_1_1_validate(buf, len);
    case OF_BAD_INSTRUCTION_ERROR_MSG:
        return of_bad_instruction_error_msg_OF_VERSION_1_1_validate(buf, len);
    case OF_BAD_ACTION_ERROR_MSG:
        return of_bad_action_error_msg_OF_VERSION_1_1_validate(buf, len);
    case OF_AGGREGATE_STATS_REQUEST:
        return of_aggregate_stats_request_OF_VERSION_1_1_validate(buf, len);
    case OF_AGGREGATE_STATS_REPLY:
        return of_aggregate_stats_reply_OF_VERSION_1_1_validate(buf, len);
    default:
        VALIDATOR_LOG("of_aggregate_stats_reply: could not map OF_AGGREGATE_STATS_REPLY");
        return -1;
    }
}

static inline int
of_list_table_stats_entry_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if ((len / 128) * 128 != len) {
        return -1;
    }

    return 0;
}

static inline int
of_list_queue_stats_entry_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if ((len / 32) * 32 != len) {
        return -1;
    }

    return 0;
}

static inline int
of_list_queue_prop_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    while (len >= 8) {
        of_object_id_t e_id;
        uint16_t e_type, e_len;
        buf_u16_get(buf, &e_type);
        buf_u16_get(buf+2, &e_len);
        e_id = of_queue_prop_to_object_id(e_type, OF_VERSION_1_2);
        switch (e_id) {
        case OF_QUEUE_PROP_MIN_RATE:
            if (of_queue_prop_min_rate_OF_VERSION_1_2_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_QUEUE_PROP_MAX_RATE:
            if (of_queue_prop_max_rate_OF_VERSION_1_2_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_QUEUE_PROP_EXPERIMENTER:
            if (of_queue_prop_experimenter_OF_VERSION_1_2_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        default:
            return -1;
        }
        buf += e_len;
        len -= e_len;
    }
    if (len != 0) {
        return -1;
    }

    return 0;
}

static inline int
of_list_port_stats_entry_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if ((len / 104) * 104 != len) {
        return -1;
    }

    return 0;
}

static inline int
of_list_port_desc_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if ((len / 64) * 64 != len) {
        return -1;
    }

    return 0;
}

static inline int
of_list_packet_queue_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    /* XXX unknown element format */

    return 0;
}

static inline int
of_list_oxm_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    /* TODO verify OXM elements */

    return 0;
}

static inline int
of_list_instruction_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    while (len >= 8) {
        of_object_id_t e_id;
        uint16_t e_type, e_len;
        buf_u16_get(buf, &e_type);
        buf_u16_get(buf+2, &e_len);
        e_id = of_instruction_to_object_id(e_type, OF_VERSION_1_2);
        switch (e_id) {
        case OF_INSTRUCTION_CLEAR_ACTIONS:
            if (of_instruction_clear_actions_OF_VERSION_1_2_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_INSTRUCTION_WRITE_ACTIONS:
            if (of_instruction_write_actions_OF_VERSION_1_2_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_INSTRUCTION_GOTO_TABLE:
            if (of_instruction_goto_table_OF_VERSION_1_2_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_INSTRUCTION_APPLY_ACTIONS:
            if (of_instruction_apply_actions_OF_VERSION_1_2_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_INSTRUCTION_EXPERIMENTER:
            if (of_instruction_experimenter_OF_VERSION_1_2_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_INSTRUCTION_WRITE_METADATA:
            if (of_instruction_write_metadata_OF_VERSION_1_2_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        default:
            return -1;
        }
        buf += e_len;
        len -= e_len;
    }
    if (len != 0) {
        return -1;
    }

    return 0;
}

static inline int
of_list_group_stats_entry_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    /* TODO verify U16 len elements */

    return 0;
}

static inline int
of_list_group_desc_stats_entry_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    /* TODO verify U16 len elements */

    return 0;
}

static inline int
of_list_flow_stats_entry_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    /* TODO verify U16 len elements */

    return 0;
}

static inline int
of_list_bucket_counter_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if ((len / 16) * 16 != len) {
        return -1;
    }

    return 0;
}

static inline int
of_list_bucket_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    /* TODO verify U16 len elements */

    return 0;
}

static inline int
of_list_bsn_interface_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if ((len / 32) * 32 != len) {
        return -1;
    }

    return 0;
}

static inline int
of_list_action_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    while (len >= 8) {
        of_object_id_t e_id;
        uint16_t e_type, e_len;
        buf_u16_get(buf, &e_type);
        buf_u16_get(buf+2, &e_len);
        e_id = of_action_to_object_id(e_type, OF_VERSION_1_2);
        switch (e_id) {
        case OF_ACTION_COPY_TTL_OUT:
            if (of_action_copy_ttl_out_OF_VERSION_1_2_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_BSN_MIRROR:
            if (of_action_bsn_mirror_OF_VERSION_1_2_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_SET_FIELD:
            if (of_action_set_field_OF_VERSION_1_2_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_DEC_MPLS_TTL:
            if (of_action_dec_mpls_ttl_OF_VERSION_1_2_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_BSN_SET_TUNNEL_DST:
            if (of_action_bsn_set_tunnel_dst_OF_VERSION_1_2_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_GROUP:
            if (of_action_group_OF_VERSION_1_2_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_SET_MPLS_TTL:
            if (of_action_set_mpls_ttl_OF_VERSION_1_2_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_POP_VLAN:
            if (of_action_pop_vlan_OF_VERSION_1_2_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_NICIRA_DEC_TTL:
            if (of_action_nicira_dec_ttl_OF_VERSION_1_2_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_POP_MPLS:
            if (of_action_pop_mpls_OF_VERSION_1_2_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_PUSH_VLAN:
            if (of_action_push_vlan_OF_VERSION_1_2_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_BSN:
            if (of_action_bsn_OF_VERSION_1_2_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_EXPERIMENTER:
            if (of_action_experimenter_OF_VERSION_1_2_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_SET_NW_TTL:
            if (of_action_set_nw_ttl_OF_VERSION_1_2_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_COPY_TTL_IN:
            if (of_action_copy_ttl_in_OF_VERSION_1_2_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_NICIRA:
            if (of_action_nicira_OF_VERSION_1_2_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_PUSH_MPLS:
            if (of_action_push_mpls_OF_VERSION_1_2_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_DEC_NW_TTL:
            if (of_action_dec_nw_ttl_OF_VERSION_1_2_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_SET_QUEUE:
            if (of_action_set_queue_OF_VERSION_1_2_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_OUTPUT:
            if (of_action_output_OF_VERSION_1_2_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        default:
            return -1;
        }
        buf += e_len;
        len -= e_len;
    }
    if (len != 0) {
        return -1;
    }

    return 0;
}

static inline int
of_table_stats_entry_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 128) {
        VALIDATOR_LOG("Class of_table_stats_entry.  Len %d too small, < %d", len, 128);
        return -1;
    }

    return 0;
}

static inline int
of_queue_stats_entry_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 32) {
        VALIDATOR_LOG("Class of_queue_stats_entry.  Len %d too small, < %d", len, 32);
        return -1;
    }

    return 0;
}

static inline int
of_queue_prop_min_rate_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_queue_prop_min_rate.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_queue_prop_max_rate_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_queue_prop_max_rate.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_queue_prop_header_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_queue_prop_header.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_queue_prop_experimenter_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_queue_prop_experimenter.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_port_stats_entry_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 104) {
        VALIDATOR_LOG("Class of_port_stats_entry.  Len %d too small, < %d", len, 104);
        return -1;
    }

    return 0;
}

static inline int
of_port_desc_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 64) {
        VALIDATOR_LOG("Class of_port_desc.  Len %d too small, < %d", len, 64);
        return -1;
    }

    return 0;
}

static inline int
of_packet_queue_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_packet_queue.  Len %d too small, < %d", len, 16);
        return -1;
    }


    {    int properties_len = len - 16;


        if (of_list_queue_prop_OF_VERSION_1_2_validate(buf + 16, properties_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_oxm_vlan_vid_masked_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_oxm_vlan_vid_masked.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_vlan_vid_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 6) {
        VALIDATOR_LOG("Class of_oxm_vlan_vid.  Len %d too small, < %d", len, 6);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_vlan_pcp_masked_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 6) {
        VALIDATOR_LOG("Class of_oxm_vlan_pcp_masked.  Len %d too small, < %d", len, 6);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_vlan_pcp_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 5) {
        VALIDATOR_LOG("Class of_oxm_vlan_pcp.  Len %d too small, < %d", len, 5);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_udp_src_masked_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_oxm_udp_src_masked.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_udp_src_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 6) {
        VALIDATOR_LOG("Class of_oxm_udp_src.  Len %d too small, < %d", len, 6);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_udp_dst_masked_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_oxm_udp_dst_masked.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_udp_dst_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 6) {
        VALIDATOR_LOG("Class of_oxm_udp_dst.  Len %d too small, < %d", len, 6);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_tcp_src_masked_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_oxm_tcp_src_masked.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_tcp_src_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 6) {
        VALIDATOR_LOG("Class of_oxm_tcp_src.  Len %d too small, < %d", len, 6);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_tcp_dst_masked_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_oxm_tcp_dst_masked.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_tcp_dst_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 6) {
        VALIDATOR_LOG("Class of_oxm_tcp_dst.  Len %d too small, < %d", len, 6);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_sctp_src_masked_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_oxm_sctp_src_masked.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_sctp_src_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 6) {
        VALIDATOR_LOG("Class of_oxm_sctp_src.  Len %d too small, < %d", len, 6);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_sctp_dst_masked_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_oxm_sctp_dst_masked.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_sctp_dst_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 6) {
        VALIDATOR_LOG("Class of_oxm_sctp_dst.  Len %d too small, < %d", len, 6);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_mpls_tc_masked_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 6) {
        VALIDATOR_LOG("Class of_oxm_mpls_tc_masked.  Len %d too small, < %d", len, 6);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_mpls_tc_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 5) {
        VALIDATOR_LOG("Class of_oxm_mpls_tc.  Len %d too small, < %d", len, 5);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_mpls_label_masked_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_oxm_mpls_label_masked.  Len %d too small, < %d", len, 12);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_mpls_label_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_oxm_mpls_label.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_metadata_masked_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 20) {
        VALIDATOR_LOG("Class of_oxm_metadata_masked.  Len %d too small, < %d", len, 20);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_metadata_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_oxm_metadata.  Len %d too small, < %d", len, 12);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_ipv6_src_masked_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 36) {
        VALIDATOR_LOG("Class of_oxm_ipv6_src_masked.  Len %d too small, < %d", len, 36);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_ipv6_src_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 20) {
        VALIDATOR_LOG("Class of_oxm_ipv6_src.  Len %d too small, < %d", len, 20);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_ipv6_nd_tll_masked_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_oxm_ipv6_nd_tll_masked.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_ipv6_nd_tll_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 10) {
        VALIDATOR_LOG("Class of_oxm_ipv6_nd_tll.  Len %d too small, < %d", len, 10);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_ipv6_nd_target_masked_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 36) {
        VALIDATOR_LOG("Class of_oxm_ipv6_nd_target_masked.  Len %d too small, < %d", len, 36);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_ipv6_nd_target_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 20) {
        VALIDATOR_LOG("Class of_oxm_ipv6_nd_target.  Len %d too small, < %d", len, 20);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_ipv6_nd_sll_masked_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_oxm_ipv6_nd_sll_masked.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_ipv6_nd_sll_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 10) {
        VALIDATOR_LOG("Class of_oxm_ipv6_nd_sll.  Len %d too small, < %d", len, 10);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_ipv6_flabel_masked_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_oxm_ipv6_flabel_masked.  Len %d too small, < %d", len, 12);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_ipv6_flabel_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_oxm_ipv6_flabel.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_ipv6_dst_masked_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 36) {
        VALIDATOR_LOG("Class of_oxm_ipv6_dst_masked.  Len %d too small, < %d", len, 36);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_ipv6_dst_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 20) {
        VALIDATOR_LOG("Class of_oxm_ipv6_dst.  Len %d too small, < %d", len, 20);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_ipv4_src_masked_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_oxm_ipv4_src_masked.  Len %d too small, < %d", len, 12);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_ipv4_src_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_oxm_ipv4_src.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_ipv4_dst_masked_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_oxm_ipv4_dst_masked.  Len %d too small, < %d", len, 12);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_ipv4_dst_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_oxm_ipv4_dst.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_ip_proto_masked_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 6) {
        VALIDATOR_LOG("Class of_oxm_ip_proto_masked.  Len %d too small, < %d", len, 6);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_ip_proto_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 5) {
        VALIDATOR_LOG("Class of_oxm_ip_proto.  Len %d too small, < %d", len, 5);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_ip_ecn_masked_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 6) {
        VALIDATOR_LOG("Class of_oxm_ip_ecn_masked.  Len %d too small, < %d", len, 6);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_ip_ecn_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 5) {
        VALIDATOR_LOG("Class of_oxm_ip_ecn.  Len %d too small, < %d", len, 5);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_ip_dscp_masked_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 6) {
        VALIDATOR_LOG("Class of_oxm_ip_dscp_masked.  Len %d too small, < %d", len, 6);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_ip_dscp_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 5) {
        VALIDATOR_LOG("Class of_oxm_ip_dscp.  Len %d too small, < %d", len, 5);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_in_port_masked_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_oxm_in_port_masked.  Len %d too small, < %d", len, 12);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_in_port_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_oxm_in_port.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_in_phy_port_masked_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_oxm_in_phy_port_masked.  Len %d too small, < %d", len, 12);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_in_phy_port_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_oxm_in_phy_port.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_icmpv6_type_masked_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 6) {
        VALIDATOR_LOG("Class of_oxm_icmpv6_type_masked.  Len %d too small, < %d", len, 6);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_icmpv6_type_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 5) {
        VALIDATOR_LOG("Class of_oxm_icmpv6_type.  Len %d too small, < %d", len, 5);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_icmpv6_code_masked_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 6) {
        VALIDATOR_LOG("Class of_oxm_icmpv6_code_masked.  Len %d too small, < %d", len, 6);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_icmpv6_code_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 5) {
        VALIDATOR_LOG("Class of_oxm_icmpv6_code.  Len %d too small, < %d", len, 5);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_icmpv4_type_masked_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 6) {
        VALIDATOR_LOG("Class of_oxm_icmpv4_type_masked.  Len %d too small, < %d", len, 6);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_icmpv4_type_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 5) {
        VALIDATOR_LOG("Class of_oxm_icmpv4_type.  Len %d too small, < %d", len, 5);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_icmpv4_code_masked_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 6) {
        VALIDATOR_LOG("Class of_oxm_icmpv4_code_masked.  Len %d too small, < %d", len, 6);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_icmpv4_code_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 5) {
        VALIDATOR_LOG("Class of_oxm_icmpv4_code.  Len %d too small, < %d", len, 5);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_header_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 4) {
        VALIDATOR_LOG("Class of_oxm_header.  Len %d too small, < %d", len, 4);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_eth_type_masked_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_oxm_eth_type_masked.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_eth_type_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 6) {
        VALIDATOR_LOG("Class of_oxm_eth_type.  Len %d too small, < %d", len, 6);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_eth_src_masked_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_oxm_eth_src_masked.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_eth_src_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 10) {
        VALIDATOR_LOG("Class of_oxm_eth_src.  Len %d too small, < %d", len, 10);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_eth_dst_masked_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_oxm_eth_dst_masked.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_eth_dst_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 10) {
        VALIDATOR_LOG("Class of_oxm_eth_dst.  Len %d too small, < %d", len, 10);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_bsn_vrf_masked_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_oxm_bsn_vrf_masked.  Len %d too small, < %d", len, 12);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_bsn_vrf_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_oxm_bsn_vrf.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_bsn_lag_id_masked_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_oxm_bsn_lag_id_masked.  Len %d too small, < %d", len, 12);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_bsn_lag_id_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_oxm_bsn_lag_id.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_bsn_l3_src_class_id_masked_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_oxm_bsn_l3_src_class_id_masked.  Len %d too small, < %d", len, 12);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_bsn_l3_src_class_id_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_oxm_bsn_l3_src_class_id.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_bsn_l3_interface_class_id_masked_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_oxm_bsn_l3_interface_class_id_masked.  Len %d too small, < %d", len, 12);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_bsn_l3_interface_class_id_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_oxm_bsn_l3_interface_class_id.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_bsn_l3_dst_class_id_masked_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_oxm_bsn_l3_dst_class_id_masked.  Len %d too small, < %d", len, 12);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_bsn_l3_dst_class_id_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_oxm_bsn_l3_dst_class_id.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_bsn_in_ports_128_masked_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 36) {
        VALIDATOR_LOG("Class of_oxm_bsn_in_ports_128_masked.  Len %d too small, < %d", len, 36);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_bsn_in_ports_128_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 20) {
        VALIDATOR_LOG("Class of_oxm_bsn_in_ports_128.  Len %d too small, < %d", len, 20);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_bsn_global_vrf_allowed_masked_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 6) {
        VALIDATOR_LOG("Class of_oxm_bsn_global_vrf_allowed_masked.  Len %d too small, < %d", len, 6);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_bsn_global_vrf_allowed_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 5) {
        VALIDATOR_LOG("Class of_oxm_bsn_global_vrf_allowed.  Len %d too small, < %d", len, 5);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_arp_tpa_masked_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_oxm_arp_tpa_masked.  Len %d too small, < %d", len, 12);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_arp_tpa_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_oxm_arp_tpa.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_arp_tha_masked_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_oxm_arp_tha_masked.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_arp_tha_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 10) {
        VALIDATOR_LOG("Class of_oxm_arp_tha.  Len %d too small, < %d", len, 10);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_arp_spa_masked_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_oxm_arp_spa_masked.  Len %d too small, < %d", len, 12);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_arp_spa_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_oxm_arp_spa.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_arp_sha_masked_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_oxm_arp_sha_masked.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_arp_sha_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 10) {
        VALIDATOR_LOG("Class of_oxm_arp_sha.  Len %d too small, < %d", len, 10);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_arp_op_masked_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_oxm_arp_op_masked.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_arp_op_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 6) {
        VALIDATOR_LOG("Class of_oxm_arp_op.  Len %d too small, < %d", len, 6);
        return -1;
    }

    return 0;
}

static inline int
of_match_v3_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 4) {
        VALIDATOR_LOG("Class of_match_v3.  Len %d too small, < %d", len, 4);
        return -1;
    }


    {    int oxm_list_len = len - 4;


        if (of_list_oxm_OF_VERSION_1_2_validate(buf + 4, oxm_list_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_instruction_write_metadata_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 24) {
        VALIDATOR_LOG("Class of_instruction_write_metadata.  Len %d too small, < %d", len, 24);
        return -1;
    }

    return 0;
}

static inline int
of_instruction_write_actions_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_instruction_write_actions.  Len %d too small, < %d", len, 8);
        return -1;
    }


    {    int actions_len = len - 8;


        if (of_list_action_OF_VERSION_1_2_validate(buf + 8, actions_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_instruction_header_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_instruction_header.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_instruction_goto_table_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_instruction_goto_table.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_instruction_experimenter_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_instruction_experimenter.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_instruction_clear_actions_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_instruction_clear_actions.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_instruction_apply_actions_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_instruction_apply_actions.  Len %d too small, < %d", len, 8);
        return -1;
    }


    {    int actions_len = len - 8;


        if (of_list_action_OF_VERSION_1_2_validate(buf + 8, actions_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_header_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_header.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_group_stats_entry_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 32) {
        VALIDATOR_LOG("Class of_group_stats_entry.  Len %d too small, < %d", len, 32);
        return -1;
    }


    {    int bucket_stats_len = len - 32;


        if (of_list_bucket_counter_OF_VERSION_1_2_validate(buf + 32, bucket_stats_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_group_desc_stats_entry_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_group_desc_stats_entry.  Len %d too small, < %d", len, 8);
        return -1;
    }


    {    int buckets_len = len - 8;


        if (of_list_bucket_OF_VERSION_1_2_validate(buf + 8, buckets_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_flow_stats_entry_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 56) {
        VALIDATOR_LOG("Class of_flow_stats_entry.  Len %d too small, < %d", len, 56);
        return -1;
    }


    {    int instructions_len = len - -1;


        if (of_list_instruction_OF_VERSION_1_2_validate(buf + -1, instructions_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_bucket_counter_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_bucket_counter.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_bucket_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_bucket.  Len %d too small, < %d", len, 16);
        return -1;
    }


    {    int actions_len = len - 16;


        if (of_list_action_OF_VERSION_1_2_validate(buf + 16, actions_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_bsn_vport_q_in_q_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 32) {
        VALIDATOR_LOG("Class of_bsn_vport_q_in_q.  Len %d too small, < %d", len, 32);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_vport_header_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 4) {
        VALIDATOR_LOG("Class of_bsn_vport_header.  Len %d too small, < %d", len, 4);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_interface_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 32) {
        VALIDATOR_LOG("Class of_bsn_interface.  Len %d too small, < %d", len, 32);
        return -1;
    }

    return 0;
}

static inline int
of_action_set_queue_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_action_set_queue.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_action_set_nw_ttl_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_action_set_nw_ttl.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_action_set_mpls_ttl_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_action_set_mpls_ttl.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_action_set_field_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 4) {
        VALIDATOR_LOG("Class of_action_set_field.  Len %d too small, < %d", len, 4);
        return -1;
    }

    return 0;
}

static inline int
of_action_push_vlan_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_action_push_vlan.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_action_push_mpls_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_action_push_mpls.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_action_pop_vlan_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_action_pop_vlan.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_action_pop_mpls_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_action_pop_mpls.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_action_output_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_action_output.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_action_nicira_dec_ttl_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_action_nicira_dec_ttl.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_action_nicira_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_action_nicira.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_action_header_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_action_header.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_action_group_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_action_group.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_action_experimenter_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_action_experimenter.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_action_dec_nw_ttl_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_action_dec_nw_ttl.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_action_dec_mpls_ttl_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_action_dec_mpls_ttl.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_action_copy_ttl_out_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_action_copy_ttl_out.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_action_copy_ttl_in_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_action_copy_ttl_in.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_action_bsn_set_tunnel_dst_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_action_bsn_set_tunnel_dst.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_action_bsn_mirror_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 24) {
        VALIDATOR_LOG("Class of_action_bsn_mirror.  Len %d too small, < %d", len, 24);
        return -1;
    }

    return 0;
}

static inline int
of_action_bsn_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_action_bsn.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_table_stats_request_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_table_stats_request.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_table_stats_reply_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_table_stats_reply.  Len %d too small, < %d", len, 16);
        return -1;
    }


    {    int entries_len = len - 16;


        if (of_list_table_stats_entry_OF_VERSION_1_2_validate(buf + 16, entries_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_table_mod_failed_error_msg_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_table_mod_failed_error_msg.  Len %d too small, < %d", len, 12);
        return -1;
    }

    return 0;
}

static inline int
of_table_mod_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_table_mod.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_switch_config_failed_error_msg_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_switch_config_failed_error_msg.  Len %d too small, < %d", len, 12);
        return -1;
    }

    return 0;
}

static inline int
of_stats_request_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_stats_request.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_stats_reply_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_stats_reply.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_set_config_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_set_config.  Len %d too small, < %d", len, 12);
        return -1;
    }

    return 0;
}

static inline int
of_role_request_failed_error_msg_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_role_request_failed_error_msg.  Len %d too small, < %d", len, 12);
        return -1;
    }

    return 0;
}

static inline int
of_role_request_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 24) {
        VALIDATOR_LOG("Class of_role_request.  Len %d too small, < %d", len, 24);
        return -1;
    }

    return 0;
}

static inline int
of_role_reply_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 24) {
        VALIDATOR_LOG("Class of_role_reply.  Len %d too small, < %d", len, 24);
        return -1;
    }

    return 0;
}

static inline int
of_queue_stats_request_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 24) {
        VALIDATOR_LOG("Class of_queue_stats_request.  Len %d too small, < %d", len, 24);
        return -1;
    }

    return 0;
}

static inline int
of_queue_stats_reply_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_queue_stats_reply.  Len %d too small, < %d", len, 16);
        return -1;
    }


    {    int entries_len = len - 16;


        if (of_list_queue_stats_entry_OF_VERSION_1_2_validate(buf + 16, entries_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_queue_op_failed_error_msg_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_queue_op_failed_error_msg.  Len %d too small, < %d", len, 12);
        return -1;
    }

    return 0;
}

static inline int
of_queue_get_config_request_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_queue_get_config_request.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_queue_get_config_reply_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_queue_get_config_reply.  Len %d too small, < %d", len, 16);
        return -1;
    }


    {    int queues_len = len - 16;


        if (of_list_packet_queue_OF_VERSION_1_2_validate(buf + 16, queues_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_port_status_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 80) {
        VALIDATOR_LOG("Class of_port_status.  Len %d too small, < %d", len, 80);
        return -1;
    }

    return 0;
}

static inline int
of_port_stats_request_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 24) {
        VALIDATOR_LOG("Class of_port_stats_request.  Len %d too small, < %d", len, 24);
        return -1;
    }

    return 0;
}

static inline int
of_port_stats_reply_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_port_stats_reply.  Len %d too small, < %d", len, 16);
        return -1;
    }


    {    int entries_len = len - 16;


        if (of_list_port_stats_entry_OF_VERSION_1_2_validate(buf + 16, entries_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_port_mod_failed_error_msg_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_port_mod_failed_error_msg.  Len %d too small, < %d", len, 12);
        return -1;
    }

    return 0;
}

static inline int
of_port_mod_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 40) {
        VALIDATOR_LOG("Class of_port_mod.  Len %d too small, < %d", len, 40);
        return -1;
    }

    return 0;
}

static inline int
of_packet_out_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 24) {
        VALIDATOR_LOG("Class of_packet_out.  Len %d too small, < %d", len, 24);
        return -1;
    }

    {
        uint16_t actions_len;
        buf_u16_get(buf + 24 - 2, &actions_len);
        if (actions_len + 24 > len) {
            VALIDATOR_LOG("Class of_packet_out, member actions.  "
                          "Len %d and offset %d too big for %d",
                          actions_len, 24, len);
            return -1;
        }

        if (of_list_action_OF_VERSION_1_2_validate(buf + 24, actions_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_packet_in_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 24) {
        VALIDATOR_LOG("Class of_packet_in.  Len %d too small, < %d", len, 24);
        return -1;
    }

    return 0;
}

static inline int
of_nicira_header_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_nicira_header.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_hello_failed_error_msg_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_hello_failed_error_msg.  Len %d too small, < %d", len, 12);
        return -1;
    }

    return 0;
}

static inline int
of_hello_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_hello.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_group_stats_request_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 24) {
        VALIDATOR_LOG("Class of_group_stats_request.  Len %d too small, < %d", len, 24);
        return -1;
    }

    return 0;
}

static inline int
of_group_stats_reply_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_group_stats_reply.  Len %d too small, < %d", len, 16);
        return -1;
    }


    {    int entries_len = len - 16;


        if (of_list_group_stats_entry_OF_VERSION_1_2_validate(buf + 16, entries_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_group_modify_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_group_modify.  Len %d too small, < %d", len, 16);
        return -1;
    }


    {    int buckets_len = len - 16;


        if (of_list_bucket_OF_VERSION_1_2_validate(buf + 16, buckets_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_group_mod_failed_error_msg_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_group_mod_failed_error_msg.  Len %d too small, < %d", len, 12);
        return -1;
    }

    return 0;
}

static inline int
of_group_mod_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_group_mod.  Len %d too small, < %d", len, 16);
        return -1;
    }


    {    int buckets_len = len - 16;


        if (of_list_bucket_OF_VERSION_1_2_validate(buf + 16, buckets_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_group_features_stats_request_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_group_features_stats_request.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_group_features_stats_reply_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 56) {
        VALIDATOR_LOG("Class of_group_features_stats_reply.  Len %d too small, < %d", len, 56);
        return -1;
    }

    return 0;
}

static inline int
of_group_desc_stats_request_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_group_desc_stats_request.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_group_desc_stats_reply_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_group_desc_stats_reply.  Len %d too small, < %d", len, 16);
        return -1;
    }


    {    int entries_len = len - 16;


        if (of_list_group_desc_stats_entry_OF_VERSION_1_2_validate(buf + 16, entries_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_group_delete_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_group_delete.  Len %d too small, < %d", len, 16);
        return -1;
    }


    {    int buckets_len = len - 16;


        if (of_list_bucket_OF_VERSION_1_2_validate(buf + 16, buckets_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_group_add_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_group_add.  Len %d too small, < %d", len, 16);
        return -1;
    }


    {    int buckets_len = len - 16;


        if (of_list_bucket_OF_VERSION_1_2_validate(buf + 16, buckets_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_get_config_request_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_get_config_request.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_get_config_reply_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_get_config_reply.  Len %d too small, < %d", len, 12);
        return -1;
    }

    return 0;
}

static inline int
of_flow_stats_request_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 56) {
        VALIDATOR_LOG("Class of_flow_stats_request.  Len %d too small, < %d", len, 56);
        return -1;
    }

    return 0;
}

static inline int
of_flow_stats_reply_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_flow_stats_reply.  Len %d too small, < %d", len, 16);
        return -1;
    }


    {    int entries_len = len - 16;


        if (of_list_flow_stats_entry_OF_VERSION_1_2_validate(buf + 16, entries_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_flow_removed_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 56) {
        VALIDATOR_LOG("Class of_flow_removed.  Len %d too small, < %d", len, 56);
        return -1;
    }

    return 0;
}

static inline int
of_flow_modify_strict_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 56) {
        VALIDATOR_LOG("Class of_flow_modify_strict.  Len %d too small, < %d", len, 56);
        return -1;
    }

    {
        uint16_t instructions_len, instructions_offset;
        uint16_t match_len;
        buf_u16_get(buf + 48 + 2, &match_len);
        instructions_offset = 48 + OF_MATCH_BYTES(match_len);
        instructions_len = len - instructions_offset;

        if (of_list_instruction_OF_VERSION_1_2_validate(buf + instructions_offset, instructions_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_flow_modify_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 56) {
        VALIDATOR_LOG("Class of_flow_modify.  Len %d too small, < %d", len, 56);
        return -1;
    }

    {
        uint16_t instructions_len, instructions_offset;
        uint16_t match_len;
        buf_u16_get(buf + 48 + 2, &match_len);
        instructions_offset = 48 + OF_MATCH_BYTES(match_len);
        instructions_len = len - instructions_offset;

        if (of_list_instruction_OF_VERSION_1_2_validate(buf + instructions_offset, instructions_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_flow_mod_failed_error_msg_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_flow_mod_failed_error_msg.  Len %d too small, < %d", len, 12);
        return -1;
    }

    return 0;
}

static inline int
of_flow_mod_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 56) {
        VALIDATOR_LOG("Class of_flow_mod.  Len %d too small, < %d", len, 56);
        return -1;
    }

    {
        uint16_t instructions_len, instructions_offset;
        uint16_t match_len;
        buf_u16_get(buf + 48 + 2, &match_len);
        instructions_offset = 48 + OF_MATCH_BYTES(match_len);
        instructions_len = len - instructions_offset;

        if (of_list_instruction_OF_VERSION_1_2_validate(buf + instructions_offset, instructions_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_flow_delete_strict_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 56) {
        VALIDATOR_LOG("Class of_flow_delete_strict.  Len %d too small, < %d", len, 56);
        return -1;
    }

    {
        uint16_t instructions_len, instructions_offset;
        uint16_t match_len;
        buf_u16_get(buf + 48 + 2, &match_len);
        instructions_offset = 48 + OF_MATCH_BYTES(match_len);
        instructions_len = len - instructions_offset;

        if (of_list_instruction_OF_VERSION_1_2_validate(buf + instructions_offset, instructions_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_flow_delete_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 56) {
        VALIDATOR_LOG("Class of_flow_delete.  Len %d too small, < %d", len, 56);
        return -1;
    }

    {
        uint16_t instructions_len, instructions_offset;
        uint16_t match_len;
        buf_u16_get(buf + 48 + 2, &match_len);
        instructions_offset = 48 + OF_MATCH_BYTES(match_len);
        instructions_len = len - instructions_offset;

        if (of_list_instruction_OF_VERSION_1_2_validate(buf + instructions_offset, instructions_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_flow_add_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 56) {
        VALIDATOR_LOG("Class of_flow_add.  Len %d too small, < %d", len, 56);
        return -1;
    }

    {
        uint16_t instructions_len, instructions_offset;
        uint16_t match_len;
        buf_u16_get(buf + 48 + 2, &match_len);
        instructions_offset = 48 + OF_MATCH_BYTES(match_len);
        instructions_len = len - instructions_offset;

        if (of_list_instruction_OF_VERSION_1_2_validate(buf + instructions_offset, instructions_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_features_request_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_features_request.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_features_reply_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 32) {
        VALIDATOR_LOG("Class of_features_reply.  Len %d too small, < %d", len, 32);
        return -1;
    }


    {    int ports_len = len - 32;


        if (of_list_port_desc_OF_VERSION_1_2_validate(buf + 32, ports_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_experimenter_stats_request_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 24) {
        VALIDATOR_LOG("Class of_experimenter_stats_request.  Len %d too small, < %d", len, 24);
        return -1;
    }

    return 0;
}

static inline int
of_experimenter_stats_reply_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 24) {
        VALIDATOR_LOG("Class of_experimenter_stats_reply.  Len %d too small, < %d", len, 24);
        return -1;
    }

    return 0;
}

static inline int
of_experimenter_error_msg_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_experimenter_error_msg.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_experimenter_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_experimenter.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_error_msg_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 10) {
        VALIDATOR_LOG("Class of_error_msg.  Len %d too small, < %d", len, 10);
        return -1;
    }

    return 0;
}

static inline int
of_echo_request_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_echo_request.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_echo_reply_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_echo_reply.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_desc_stats_request_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_desc_stats_request.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_desc_stats_reply_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 1072) {
        VALIDATOR_LOG("Class of_desc_stats_reply.  Len %d too small, < %d", len, 1072);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_virtual_port_remove_request_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 20) {
        VALIDATOR_LOG("Class of_bsn_virtual_port_remove_request.  Len %d too small, < %d", len, 20);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_virtual_port_remove_reply_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 20) {
        VALIDATOR_LOG("Class of_bsn_virtual_port_remove_reply.  Len %d too small, < %d", len, 20);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_virtual_port_create_request_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 48) {
        VALIDATOR_LOG("Class of_bsn_virtual_port_create_request.  Len %d too small, < %d", len, 48);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_virtual_port_create_reply_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 24) {
        VALIDATOR_LOG("Class of_bsn_virtual_port_create_reply.  Len %d too small, < %d", len, 24);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_stats_request_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 24) {
        VALIDATOR_LOG("Class of_bsn_stats_request.  Len %d too small, < %d", len, 24);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_stats_reply_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 24) {
        VALIDATOR_LOG("Class of_bsn_stats_reply.  Len %d too small, < %d", len, 24);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_set_pktin_suppression_request_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 32) {
        VALIDATOR_LOG("Class of_bsn_set_pktin_suppression_request.  Len %d too small, < %d", len, 32);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_set_pktin_suppression_reply_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 20) {
        VALIDATOR_LOG("Class of_bsn_set_pktin_suppression_reply.  Len %d too small, < %d", len, 20);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_set_mirroring_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 20) {
        VALIDATOR_LOG("Class of_bsn_set_mirroring.  Len %d too small, < %d", len, 20);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_pdu_tx_request_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 28) {
        VALIDATOR_LOG("Class of_bsn_pdu_tx_request.  Len %d too small, < %d", len, 28);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_pdu_tx_reply_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 25) {
        VALIDATOR_LOG("Class of_bsn_pdu_tx_reply.  Len %d too small, < %d", len, 25);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_pdu_rx_timeout_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 21) {
        VALIDATOR_LOG("Class of_bsn_pdu_rx_timeout.  Len %d too small, < %d", len, 21);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_pdu_rx_request_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 28) {
        VALIDATOR_LOG("Class of_bsn_pdu_rx_request.  Len %d too small, < %d", len, 28);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_pdu_rx_reply_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 25) {
        VALIDATOR_LOG("Class of_bsn_pdu_rx_reply.  Len %d too small, < %d", len, 25);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_header_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_bsn_header.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_get_mirroring_request_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 20) {
        VALIDATOR_LOG("Class of_bsn_get_mirroring_request.  Len %d too small, < %d", len, 20);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_get_mirroring_reply_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 20) {
        VALIDATOR_LOG("Class of_bsn_get_mirroring_reply.  Len %d too small, < %d", len, 20);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_get_interfaces_request_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_bsn_get_interfaces_request.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_get_interfaces_reply_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_bsn_get_interfaces_reply.  Len %d too small, < %d", len, 16);
        return -1;
    }


    {    int interfaces_len = len - 16;


        if (of_list_bsn_interface_OF_VERSION_1_2_validate(buf + 16, interfaces_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_bsn_bw_enable_set_request_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 20) {
        VALIDATOR_LOG("Class of_bsn_bw_enable_set_request.  Len %d too small, < %d", len, 20);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_bw_enable_set_reply_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 24) {
        VALIDATOR_LOG("Class of_bsn_bw_enable_set_reply.  Len %d too small, < %d", len, 24);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_bw_enable_get_request_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_bsn_bw_enable_get_request.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_bw_enable_get_reply_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 20) {
        VALIDATOR_LOG("Class of_bsn_bw_enable_get_reply.  Len %d too small, < %d", len, 20);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_bw_clear_data_request_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_bsn_bw_clear_data_request.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_bw_clear_data_reply_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 20) {
        VALIDATOR_LOG("Class of_bsn_bw_clear_data_reply.  Len %d too small, < %d", len, 20);
        return -1;
    }

    return 0;
}

static inline int
of_barrier_request_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_barrier_request.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_barrier_reply_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_barrier_reply.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_bad_request_error_msg_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_bad_request_error_msg.  Len %d too small, < %d", len, 12);
        return -1;
    }

    return 0;
}

static inline int
of_bad_match_error_msg_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_bad_match_error_msg.  Len %d too small, < %d", len, 12);
        return -1;
    }

    return 0;
}

static inline int
of_bad_instruction_error_msg_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_bad_instruction_error_msg.  Len %d too small, < %d", len, 12);
        return -1;
    }

    return 0;
}

static inline int
of_bad_action_error_msg_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_bad_action_error_msg.  Len %d too small, < %d", len, 12);
        return -1;
    }

    return 0;
}

static inline int
of_aggregate_stats_request_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 56) {
        VALIDATOR_LOG("Class of_aggregate_stats_request.  Len %d too small, < %d", len, 56);
        return -1;
    }

    return 0;
}

static inline int
of_aggregate_stats_reply_OF_VERSION_1_2_validate(uint8_t *buf, int len)
{
    if (len < 40) {
        VALIDATOR_LOG("Class of_aggregate_stats_reply.  Len %d too small, < %d", len, 40);
        return -1;
    }

    return 0;
}

int
of_validate_message_OF_VERSION_1_2(of_message_t msg, int len)
{
    of_object_id_t object_id = of_message_to_object_id(msg, len);
    uint8_t *buf = OF_MESSAGE_TO_BUFFER(msg);
    switch (object_id) {
    case OF_TABLE_STATS_REQUEST:
        return of_table_stats_request_OF_VERSION_1_2_validate(buf, len);
    case OF_TABLE_STATS_REPLY:
        return of_table_stats_reply_OF_VERSION_1_2_validate(buf, len);
    case OF_TABLE_MOD_FAILED_ERROR_MSG:
        return of_table_mod_failed_error_msg_OF_VERSION_1_2_validate(buf, len);
    case OF_TABLE_MOD:
        return of_table_mod_OF_VERSION_1_2_validate(buf, len);
    case OF_SWITCH_CONFIG_FAILED_ERROR_MSG:
        return of_switch_config_failed_error_msg_OF_VERSION_1_2_validate(buf, len);
    case OF_STATS_REQUEST:
        return of_stats_request_OF_VERSION_1_2_validate(buf, len);
    case OF_STATS_REPLY:
        return of_stats_reply_OF_VERSION_1_2_validate(buf, len);
    case OF_SET_CONFIG:
        return of_set_config_OF_VERSION_1_2_validate(buf, len);
    case OF_ROLE_REQUEST_FAILED_ERROR_MSG:
        return of_role_request_failed_error_msg_OF_VERSION_1_2_validate(buf, len);
    case OF_ROLE_REQUEST:
        return of_role_request_OF_VERSION_1_2_validate(buf, len);
    case OF_ROLE_REPLY:
        return of_role_reply_OF_VERSION_1_2_validate(buf, len);
    case OF_QUEUE_STATS_REQUEST:
        return of_queue_stats_request_OF_VERSION_1_2_validate(buf, len);
    case OF_QUEUE_STATS_REPLY:
        return of_queue_stats_reply_OF_VERSION_1_2_validate(buf, len);
    case OF_QUEUE_OP_FAILED_ERROR_MSG:
        return of_queue_op_failed_error_msg_OF_VERSION_1_2_validate(buf, len);
    case OF_QUEUE_GET_CONFIG_REQUEST:
        return of_queue_get_config_request_OF_VERSION_1_2_validate(buf, len);
    case OF_QUEUE_GET_CONFIG_REPLY:
        return of_queue_get_config_reply_OF_VERSION_1_2_validate(buf, len);
    case OF_PORT_STATUS:
        return of_port_status_OF_VERSION_1_2_validate(buf, len);
    case OF_PORT_STATS_REQUEST:
        return of_port_stats_request_OF_VERSION_1_2_validate(buf, len);
    case OF_PORT_STATS_REPLY:
        return of_port_stats_reply_OF_VERSION_1_2_validate(buf, len);
    case OF_PORT_MOD_FAILED_ERROR_MSG:
        return of_port_mod_failed_error_msg_OF_VERSION_1_2_validate(buf, len);
    case OF_PORT_MOD:
        return of_port_mod_OF_VERSION_1_2_validate(buf, len);
    case OF_PACKET_OUT:
        return of_packet_out_OF_VERSION_1_2_validate(buf, len);
    case OF_PACKET_IN:
        return of_packet_in_OF_VERSION_1_2_validate(buf, len);
    case OF_NICIRA_HEADER:
        return of_nicira_header_OF_VERSION_1_2_validate(buf, len);
    case OF_HELLO_FAILED_ERROR_MSG:
        return of_hello_failed_error_msg_OF_VERSION_1_2_validate(buf, len);
    case OF_HELLO:
        return of_hello_OF_VERSION_1_2_validate(buf, len);
    case OF_GROUP_STATS_REQUEST:
        return of_group_stats_request_OF_VERSION_1_2_validate(buf, len);
    case OF_GROUP_STATS_REPLY:
        return of_group_stats_reply_OF_VERSION_1_2_validate(buf, len);
    case OF_GROUP_MODIFY:
        return of_group_modify_OF_VERSION_1_2_validate(buf, len);
    case OF_GROUP_MOD_FAILED_ERROR_MSG:
        return of_group_mod_failed_error_msg_OF_VERSION_1_2_validate(buf, len);
    case OF_GROUP_MOD:
        return of_group_mod_OF_VERSION_1_2_validate(buf, len);
    case OF_GROUP_FEATURES_STATS_REQUEST:
        return of_group_features_stats_request_OF_VERSION_1_2_validate(buf, len);
    case OF_GROUP_FEATURES_STATS_REPLY:
        return of_group_features_stats_reply_OF_VERSION_1_2_validate(buf, len);
    case OF_GROUP_DESC_STATS_REQUEST:
        return of_group_desc_stats_request_OF_VERSION_1_2_validate(buf, len);
    case OF_GROUP_DESC_STATS_REPLY:
        return of_group_desc_stats_reply_OF_VERSION_1_2_validate(buf, len);
    case OF_GROUP_DELETE:
        return of_group_delete_OF_VERSION_1_2_validate(buf, len);
    case OF_GROUP_ADD:
        return of_group_add_OF_VERSION_1_2_validate(buf, len);
    case OF_GET_CONFIG_REQUEST:
        return of_get_config_request_OF_VERSION_1_2_validate(buf, len);
    case OF_GET_CONFIG_REPLY:
        return of_get_config_reply_OF_VERSION_1_2_validate(buf, len);
    case OF_FLOW_STATS_REQUEST:
        return of_flow_stats_request_OF_VERSION_1_2_validate(buf, len);
    case OF_FLOW_STATS_REPLY:
        return of_flow_stats_reply_OF_VERSION_1_2_validate(buf, len);
    case OF_FLOW_REMOVED:
        return of_flow_removed_OF_VERSION_1_2_validate(buf, len);
    case OF_FLOW_MODIFY_STRICT:
        return of_flow_modify_strict_OF_VERSION_1_2_validate(buf, len);
    case OF_FLOW_MODIFY:
        return of_flow_modify_OF_VERSION_1_2_validate(buf, len);
    case OF_FLOW_MOD_FAILED_ERROR_MSG:
        return of_flow_mod_failed_error_msg_OF_VERSION_1_2_validate(buf, len);
    case OF_FLOW_MOD:
        return of_flow_mod_OF_VERSION_1_2_validate(buf, len);
    case OF_FLOW_DELETE_STRICT:
        return of_flow_delete_strict_OF_VERSION_1_2_validate(buf, len);
    case OF_FLOW_DELETE:
        return of_flow_delete_OF_VERSION_1_2_validate(buf, len);
    case OF_FLOW_ADD:
        return of_flow_add_OF_VERSION_1_2_validate(buf, len);
    case OF_FEATURES_REQUEST:
        return of_features_request_OF_VERSION_1_2_validate(buf, len);
    case OF_FEATURES_REPLY:
        return of_features_reply_OF_VERSION_1_2_validate(buf, len);
    case OF_EXPERIMENTER_STATS_REQUEST:
        return of_experimenter_stats_request_OF_VERSION_1_2_validate(buf, len);
    case OF_EXPERIMENTER_STATS_REPLY:
        return of_experimenter_stats_reply_OF_VERSION_1_2_validate(buf, len);
    case OF_EXPERIMENTER_ERROR_MSG:
        return of_experimenter_error_msg_OF_VERSION_1_2_validate(buf, len);
    case OF_EXPERIMENTER:
        return of_experimenter_OF_VERSION_1_2_validate(buf, len);
    case OF_ERROR_MSG:
        return of_error_msg_OF_VERSION_1_2_validate(buf, len);
    case OF_ECHO_REQUEST:
        return of_echo_request_OF_VERSION_1_2_validate(buf, len);
    case OF_ECHO_REPLY:
        return of_echo_reply_OF_VERSION_1_2_validate(buf, len);
    case OF_DESC_STATS_REQUEST:
        return of_desc_stats_request_OF_VERSION_1_2_validate(buf, len);
    case OF_DESC_STATS_REPLY:
        return of_desc_stats_reply_OF_VERSION_1_2_validate(buf, len);
    case OF_BSN_VIRTUAL_PORT_REMOVE_REQUEST:
        return of_bsn_virtual_port_remove_request_OF_VERSION_1_2_validate(buf, len);
    case OF_BSN_VIRTUAL_PORT_REMOVE_REPLY:
        return of_bsn_virtual_port_remove_reply_OF_VERSION_1_2_validate(buf, len);
    case OF_BSN_VIRTUAL_PORT_CREATE_REQUEST:
        return of_bsn_virtual_port_create_request_OF_VERSION_1_2_validate(buf, len);
    case OF_BSN_VIRTUAL_PORT_CREATE_REPLY:
        return of_bsn_virtual_port_create_reply_OF_VERSION_1_2_validate(buf, len);
    case OF_BSN_STATS_REQUEST:
        return of_bsn_stats_request_OF_VERSION_1_2_validate(buf, len);
    case OF_BSN_STATS_REPLY:
        return of_bsn_stats_reply_OF_VERSION_1_2_validate(buf, len);
    case OF_BSN_SET_PKTIN_SUPPRESSION_REQUEST:
        return of_bsn_set_pktin_suppression_request_OF_VERSION_1_2_validate(buf, len);
    case OF_BSN_SET_PKTIN_SUPPRESSION_REPLY:
        return of_bsn_set_pktin_suppression_reply_OF_VERSION_1_2_validate(buf, len);
    case OF_BSN_SET_MIRRORING:
        return of_bsn_set_mirroring_OF_VERSION_1_2_validate(buf, len);
    case OF_BSN_PDU_TX_REQUEST:
        return of_bsn_pdu_tx_request_OF_VERSION_1_2_validate(buf, len);
    case OF_BSN_PDU_TX_REPLY:
        return of_bsn_pdu_tx_reply_OF_VERSION_1_2_validate(buf, len);
    case OF_BSN_PDU_RX_TIMEOUT:
        return of_bsn_pdu_rx_timeout_OF_VERSION_1_2_validate(buf, len);
    case OF_BSN_PDU_RX_REQUEST:
        return of_bsn_pdu_rx_request_OF_VERSION_1_2_validate(buf, len);
    case OF_BSN_PDU_RX_REPLY:
        return of_bsn_pdu_rx_reply_OF_VERSION_1_2_validate(buf, len);
    case OF_BSN_HEADER:
        return of_bsn_header_OF_VERSION_1_2_validate(buf, len);
    case OF_BSN_GET_MIRRORING_REQUEST:
        return of_bsn_get_mirroring_request_OF_VERSION_1_2_validate(buf, len);
    case OF_BSN_GET_MIRRORING_REPLY:
        return of_bsn_get_mirroring_reply_OF_VERSION_1_2_validate(buf, len);
    case OF_BSN_GET_INTERFACES_REQUEST:
        return of_bsn_get_interfaces_request_OF_VERSION_1_2_validate(buf, len);
    case OF_BSN_GET_INTERFACES_REPLY:
        return of_bsn_get_interfaces_reply_OF_VERSION_1_2_validate(buf, len);
    case OF_BSN_BW_ENABLE_SET_REQUEST:
        return of_bsn_bw_enable_set_request_OF_VERSION_1_2_validate(buf, len);
    case OF_BSN_BW_ENABLE_SET_REPLY:
        return of_bsn_bw_enable_set_reply_OF_VERSION_1_2_validate(buf, len);
    case OF_BSN_BW_ENABLE_GET_REQUEST:
        return of_bsn_bw_enable_get_request_OF_VERSION_1_2_validate(buf, len);
    case OF_BSN_BW_ENABLE_GET_REPLY:
        return of_bsn_bw_enable_get_reply_OF_VERSION_1_2_validate(buf, len);
    case OF_BSN_BW_CLEAR_DATA_REQUEST:
        return of_bsn_bw_clear_data_request_OF_VERSION_1_2_validate(buf, len);
    case OF_BSN_BW_CLEAR_DATA_REPLY:
        return of_bsn_bw_clear_data_reply_OF_VERSION_1_2_validate(buf, len);
    case OF_BARRIER_REQUEST:
        return of_barrier_request_OF_VERSION_1_2_validate(buf, len);
    case OF_BARRIER_REPLY:
        return of_barrier_reply_OF_VERSION_1_2_validate(buf, len);
    case OF_BAD_REQUEST_ERROR_MSG:
        return of_bad_request_error_msg_OF_VERSION_1_2_validate(buf, len);
    case OF_BAD_MATCH_ERROR_MSG:
        return of_bad_match_error_msg_OF_VERSION_1_2_validate(buf, len);
    case OF_BAD_INSTRUCTION_ERROR_MSG:
        return of_bad_instruction_error_msg_OF_VERSION_1_2_validate(buf, len);
    case OF_BAD_ACTION_ERROR_MSG:
        return of_bad_action_error_msg_OF_VERSION_1_2_validate(buf, len);
    case OF_AGGREGATE_STATS_REQUEST:
        return of_aggregate_stats_request_OF_VERSION_1_2_validate(buf, len);
    case OF_AGGREGATE_STATS_REPLY:
        return of_aggregate_stats_reply_OF_VERSION_1_2_validate(buf, len);
    default:
        VALIDATOR_LOG("of_aggregate_stats_reply: could not map OF_AGGREGATE_STATS_REPLY");
        return -1;
    }
}

static inline int
of_list_uint8_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if ((len / 1) * 1 != len) {
        return -1;
    }

    return 0;
}

static inline int
of_list_uint64_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if ((len / 8) * 8 != len) {
        return -1;
    }

    return 0;
}

static inline int
of_list_uint32_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if ((len / 4) * 4 != len) {
        return -1;
    }

    return 0;
}

static inline int
of_list_table_stats_entry_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if ((len / 24) * 24 != len) {
        return -1;
    }

    return 0;
}

static inline int
of_list_table_features_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    /* TODO verify U16 len elements */

    return 0;
}

static inline int
of_list_table_feature_prop_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    while (len >= 4) {
        of_object_id_t e_id;
        uint16_t e_type, e_len;
        buf_u16_get(buf, &e_type);
        buf_u16_get(buf+2, &e_len);
        e_id = of_table_feature_prop_to_object_id(e_type, OF_VERSION_1_3);
        switch (e_id) {
        case OF_TABLE_FEATURE_PROP_NEXT_TABLES_MISS:
            if (of_table_feature_prop_next_tables_miss_OF_VERSION_1_3_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_TABLE_FEATURE_PROP_WILDCARDS:
            if (of_table_feature_prop_wildcards_OF_VERSION_1_3_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_TABLE_FEATURE_PROP_WRITE_ACTIONS:
            if (of_table_feature_prop_write_actions_OF_VERSION_1_3_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_TABLE_FEATURE_PROP_WRITE_ACTIONS_MISS:
            if (of_table_feature_prop_write_actions_miss_OF_VERSION_1_3_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_TABLE_FEATURE_PROP_NEXT_TABLES:
            if (of_table_feature_prop_next_tables_OF_VERSION_1_3_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_TABLE_FEATURE_PROP_APPLY_ACTIONS_MISS:
            if (of_table_feature_prop_apply_actions_miss_OF_VERSION_1_3_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_TABLE_FEATURE_PROP_APPLY_ACTIONS:
            if (of_table_feature_prop_apply_actions_OF_VERSION_1_3_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_TABLE_FEATURE_PROP_APPLY_SETFIELD_MISS:
            if (of_table_feature_prop_apply_setfield_miss_OF_VERSION_1_3_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_TABLE_FEATURE_PROP_EXPERIMENTER:
            if (of_table_feature_prop_experimenter_OF_VERSION_1_3_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_TABLE_FEATURE_PROP_WRITE_SETFIELD_MISS:
            if (of_table_feature_prop_write_setfield_miss_OF_VERSION_1_3_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_TABLE_FEATURE_PROP_WRITE_SETFIELD:
            if (of_table_feature_prop_write_setfield_OF_VERSION_1_3_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_TABLE_FEATURE_PROP_INSTRUCTIONS_MISS:
            if (of_table_feature_prop_instructions_miss_OF_VERSION_1_3_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_TABLE_FEATURE_PROP_APPLY_SETFIELD:
            if (of_table_feature_prop_apply_setfield_OF_VERSION_1_3_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_TABLE_FEATURE_PROP_MATCH:
            if (of_table_feature_prop_match_OF_VERSION_1_3_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_TABLE_FEATURE_PROP_INSTRUCTIONS:
            if (of_table_feature_prop_instructions_OF_VERSION_1_3_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        default:
            return -1;
        }
        buf += e_len;
        len -= e_len;
    }
    if (len != 0) {
        return -1;
    }

    return 0;
}

static inline int
of_list_queue_stats_entry_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if ((len / 40) * 40 != len) {
        return -1;
    }

    return 0;
}

static inline int
of_list_queue_prop_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    while (len >= 8) {
        of_object_id_t e_id;
        uint16_t e_type, e_len;
        buf_u16_get(buf, &e_type);
        buf_u16_get(buf+2, &e_len);
        e_id = of_queue_prop_to_object_id(e_type, OF_VERSION_1_3);
        switch (e_id) {
        case OF_QUEUE_PROP_MIN_RATE:
            if (of_queue_prop_min_rate_OF_VERSION_1_3_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_QUEUE_PROP_MAX_RATE:
            if (of_queue_prop_max_rate_OF_VERSION_1_3_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_QUEUE_PROP_EXPERIMENTER:
            if (of_queue_prop_experimenter_OF_VERSION_1_3_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        default:
            return -1;
        }
        buf += e_len;
        len -= e_len;
    }
    if (len != 0) {
        return -1;
    }

    return 0;
}

static inline int
of_list_port_stats_entry_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if ((len / 112) * 112 != len) {
        return -1;
    }

    return 0;
}

static inline int
of_list_port_desc_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if ((len / 64) * 64 != len) {
        return -1;
    }

    return 0;
}

static inline int
of_list_packet_queue_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    /* XXX unknown element format */

    return 0;
}

static inline int
of_list_oxm_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    /* TODO verify OXM elements */

    return 0;
}

static inline int
of_list_meter_stats_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    /* XXX unknown element format */

    return 0;
}

static inline int
of_list_meter_band_stats_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if ((len / 16) * 16 != len) {
        return -1;
    }

    return 0;
}

static inline int
of_list_meter_band_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    while (len >= 4) {
        of_object_id_t e_id;
        uint16_t e_type, e_len;
        buf_u16_get(buf, &e_type);
        buf_u16_get(buf+2, &e_len);
        e_id = of_meter_band_to_object_id(e_type, OF_VERSION_1_3);
        switch (e_id) {
        case OF_METER_BAND_DSCP_REMARK:
            if (of_meter_band_dscp_remark_OF_VERSION_1_3_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_METER_BAND_DROP:
            if (of_meter_band_drop_OF_VERSION_1_3_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_METER_BAND_EXPERIMENTER:
            if (of_meter_band_experimenter_OF_VERSION_1_3_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        default:
            return -1;
        }
        buf += e_len;
        len -= e_len;
    }
    if (len != 0) {
        return -1;
    }

    return 0;
}

static inline int
of_list_instruction_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    while (len >= 4) {
        of_object_id_t e_id;
        uint16_t e_type, e_len;
        buf_u16_get(buf, &e_type);
        buf_u16_get(buf+2, &e_len);
        e_id = of_instruction_to_object_id(e_type, OF_VERSION_1_3);
        switch (e_id) {
        case OF_INSTRUCTION_CLEAR_ACTIONS:
            if (of_instruction_clear_actions_OF_VERSION_1_3_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_INSTRUCTION_WRITE_ACTIONS:
            if (of_instruction_write_actions_OF_VERSION_1_3_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_INSTRUCTION_GOTO_TABLE:
            if (of_instruction_goto_table_OF_VERSION_1_3_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_INSTRUCTION_METER:
            if (of_instruction_meter_OF_VERSION_1_3_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_INSTRUCTION_APPLY_ACTIONS:
            if (of_instruction_apply_actions_OF_VERSION_1_3_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_INSTRUCTION_BSN:
            if (of_instruction_bsn_OF_VERSION_1_3_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_INSTRUCTION_EXPERIMENTER:
            if (of_instruction_experimenter_OF_VERSION_1_3_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_INSTRUCTION_WRITE_METADATA:
            if (of_instruction_write_metadata_OF_VERSION_1_3_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_INSTRUCTION_BSN_DISABLE_SRC_MAC_CHECK:
            if (of_instruction_bsn_disable_src_mac_check_OF_VERSION_1_3_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        default:
            return -1;
        }
        buf += e_len;
        len -= e_len;
    }
    if (len != 0) {
        return -1;
    }

    return 0;
}

static inline int
of_list_hello_elem_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    while (len >= 4) {
        of_object_id_t e_id;
        uint16_t e_type, e_len;
        buf_u16_get(buf, &e_type);
        buf_u16_get(buf+2, &e_len);
        e_id = of_hello_elem_to_object_id(e_type, OF_VERSION_1_3);
        switch (e_id) {
        case OF_HELLO_ELEM_VERSIONBITMAP:
            if (of_hello_elem_versionbitmap_OF_VERSION_1_3_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        default:
            return -1;
        }
        buf += e_len;
        len -= e_len;
    }
    if (len != 0) {
        return -1;
    }

    return 0;
}

static inline int
of_list_group_stats_entry_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    /* TODO verify U16 len elements */

    return 0;
}

static inline int
of_list_group_desc_stats_entry_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    /* TODO verify U16 len elements */

    return 0;
}

static inline int
of_list_flow_stats_entry_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    /* TODO verify U16 len elements */

    return 0;
}

static inline int
of_list_bucket_counter_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if ((len / 16) * 16 != len) {
        return -1;
    }

    return 0;
}

static inline int
of_list_bucket_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    /* TODO verify U16 len elements */

    return 0;
}

static inline int
of_list_bsn_vlan_counter_stats_entry_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    /* TODO verify U16 len elements */

    return 0;
}

static inline int
of_list_bsn_switch_pipeline_stats_entry_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if ((len / 256) * 256 != len) {
        return -1;
    }

    return 0;
}

static inline int
of_list_bsn_port_counter_stats_entry_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    /* TODO verify U16 len elements */

    return 0;
}

static inline int
of_list_bsn_lacp_stats_entry_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if ((len / 36) * 36 != len) {
        return -1;
    }

    return 0;
}

static inline int
of_list_bsn_interface_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if ((len / 32) * 32 != len) {
        return -1;
    }

    return 0;
}

static inline int
of_list_action_id_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    while (len >= 8) {
        of_object_id_t e_id;
        uint16_t e_type, e_len;
        buf_u16_get(buf, &e_type);
        buf_u16_get(buf+2, &e_len);
        e_id = of_action_id_to_object_id(e_type, OF_VERSION_1_3);
        switch (e_id) {
        case OF_ACTION_ID_BSN_MIRROR:
            if (of_action_id_bsn_mirror_OF_VERSION_1_3_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_ID_DEC_MPLS_TTL:
            if (of_action_id_dec_mpls_ttl_OF_VERSION_1_3_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_ID_BSN_SET_TUNNEL_DST:
            if (of_action_id_bsn_set_tunnel_dst_OF_VERSION_1_3_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_ID_COPY_TTL_IN:
            if (of_action_id_copy_ttl_in_OF_VERSION_1_3_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_ID_GROUP:
            if (of_action_id_group_OF_VERSION_1_3_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_ID_COPY_TTL_OUT:
            if (of_action_id_copy_ttl_out_OF_VERSION_1_3_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_ID_SET_FIELD:
            if (of_action_id_set_field_OF_VERSION_1_3_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_ID_SET_MPLS_TTL:
            if (of_action_id_set_mpls_ttl_OF_VERSION_1_3_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_ID_POP_VLAN:
            if (of_action_id_pop_vlan_OF_VERSION_1_3_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_ID_PUSH_PBB:
            if (of_action_id_push_pbb_OF_VERSION_1_3_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_ID_NICIRA_DEC_TTL:
            if (of_action_id_nicira_dec_ttl_OF_VERSION_1_3_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_ID_POP_MPLS:
            if (of_action_id_pop_mpls_OF_VERSION_1_3_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_ID_PUSH_VLAN:
            if (of_action_id_push_vlan_OF_VERSION_1_3_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_ID_BSN:
            if (of_action_id_bsn_OF_VERSION_1_3_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_ID_EXPERIMENTER:
            if (of_action_id_experimenter_OF_VERSION_1_3_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_ID_SET_NW_TTL:
            if (of_action_id_set_nw_ttl_OF_VERSION_1_3_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_ID_POP_PBB:
            if (of_action_id_pop_pbb_OF_VERSION_1_3_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_ID_NICIRA:
            if (of_action_id_nicira_OF_VERSION_1_3_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_ID_SET_QUEUE:
            if (of_action_id_set_queue_OF_VERSION_1_3_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_ID_PUSH_MPLS:
            if (of_action_id_push_mpls_OF_VERSION_1_3_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_ID_DEC_NW_TTL:
            if (of_action_id_dec_nw_ttl_OF_VERSION_1_3_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_ID_OUTPUT:
            if (of_action_id_output_OF_VERSION_1_3_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        default:
            return -1;
        }
        buf += e_len;
        len -= e_len;
    }
    if (len != 0) {
        return -1;
    }

    return 0;
}

static inline int
of_list_action_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    while (len >= 8) {
        of_object_id_t e_id;
        uint16_t e_type, e_len;
        buf_u16_get(buf, &e_type);
        buf_u16_get(buf+2, &e_len);
        e_id = of_action_to_object_id(e_type, OF_VERSION_1_3);
        switch (e_id) {
        case OF_ACTION_COPY_TTL_OUT:
            if (of_action_copy_ttl_out_OF_VERSION_1_3_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_BSN_MIRROR:
            if (of_action_bsn_mirror_OF_VERSION_1_3_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_SET_FIELD:
            if (of_action_set_field_OF_VERSION_1_3_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_DEC_MPLS_TTL:
            if (of_action_dec_mpls_ttl_OF_VERSION_1_3_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_BSN_SET_TUNNEL_DST:
            if (of_action_bsn_set_tunnel_dst_OF_VERSION_1_3_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_POP_PBB:
            if (of_action_pop_pbb_OF_VERSION_1_3_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_GROUP:
            if (of_action_group_OF_VERSION_1_3_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_SET_MPLS_TTL:
            if (of_action_set_mpls_ttl_OF_VERSION_1_3_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_POP_VLAN:
            if (of_action_pop_vlan_OF_VERSION_1_3_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_PUSH_PBB:
            if (of_action_push_pbb_OF_VERSION_1_3_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_NICIRA_DEC_TTL:
            if (of_action_nicira_dec_ttl_OF_VERSION_1_3_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_POP_MPLS:
            if (of_action_pop_mpls_OF_VERSION_1_3_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_PUSH_VLAN:
            if (of_action_push_vlan_OF_VERSION_1_3_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_BSN:
            if (of_action_bsn_OF_VERSION_1_3_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_EXPERIMENTER:
            if (of_action_experimenter_OF_VERSION_1_3_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_SET_NW_TTL:
            if (of_action_set_nw_ttl_OF_VERSION_1_3_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_COPY_TTL_IN:
            if (of_action_copy_ttl_in_OF_VERSION_1_3_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_NICIRA:
            if (of_action_nicira_OF_VERSION_1_3_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_PUSH_MPLS:
            if (of_action_push_mpls_OF_VERSION_1_3_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_DEC_NW_TTL:
            if (of_action_dec_nw_ttl_OF_VERSION_1_3_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_SET_QUEUE:
            if (of_action_set_queue_OF_VERSION_1_3_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        case OF_ACTION_OUTPUT:
            if (of_action_output_OF_VERSION_1_3_validate(buf, e_len) < 0) {
                return -1;
            }
            break;
        default:
            return -1;
        }
        buf += e_len;
        len -= e_len;
    }
    if (len != 0) {
        return -1;
    }

    return 0;
}

static inline int
of_uint8_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 1) {
        VALIDATOR_LOG("Class of_uint8.  Len %d too small, < %d", len, 1);
        return -1;
    }

    return 0;
}

static inline int
of_uint64_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_uint64.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_uint32_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 4) {
        VALIDATOR_LOG("Class of_uint32.  Len %d too small, < %d", len, 4);
        return -1;
    }

    return 0;
}

static inline int
of_table_stats_entry_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 24) {
        VALIDATOR_LOG("Class of_table_stats_entry.  Len %d too small, < %d", len, 24);
        return -1;
    }

    return 0;
}

static inline int
of_table_features_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 64) {
        VALIDATOR_LOG("Class of_table_features.  Len %d too small, < %d", len, 64);
        return -1;
    }


    {    int properties_len = len - 64;


        if (of_list_table_feature_prop_OF_VERSION_1_3_validate(buf + 64, properties_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_table_feature_prop_write_setfield_miss_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 4) {
        VALIDATOR_LOG("Class of_table_feature_prop_write_setfield_miss.  Len %d too small, < %d", len, 4);
        return -1;
    }


    {    int oxm_ids_len = len - 4;


        if (of_list_uint32_OF_VERSION_1_3_validate(buf + 4, oxm_ids_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_table_feature_prop_write_setfield_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 4) {
        VALIDATOR_LOG("Class of_table_feature_prop_write_setfield.  Len %d too small, < %d", len, 4);
        return -1;
    }


    {    int oxm_ids_len = len - 4;


        if (of_list_uint32_OF_VERSION_1_3_validate(buf + 4, oxm_ids_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_table_feature_prop_write_actions_miss_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 4) {
        VALIDATOR_LOG("Class of_table_feature_prop_write_actions_miss.  Len %d too small, < %d", len, 4);
        return -1;
    }


    {    int action_ids_len = len - 4;


        if (of_list_action_id_OF_VERSION_1_3_validate(buf + 4, action_ids_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_table_feature_prop_write_actions_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 4) {
        VALIDATOR_LOG("Class of_table_feature_prop_write_actions.  Len %d too small, < %d", len, 4);
        return -1;
    }


    {    int action_ids_len = len - 4;


        if (of_list_action_id_OF_VERSION_1_3_validate(buf + 4, action_ids_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_table_feature_prop_wildcards_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 4) {
        VALIDATOR_LOG("Class of_table_feature_prop_wildcards.  Len %d too small, < %d", len, 4);
        return -1;
    }


    {    int oxm_ids_len = len - 4;


        if (of_list_uint32_OF_VERSION_1_3_validate(buf + 4, oxm_ids_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_table_feature_prop_next_tables_miss_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 4) {
        VALIDATOR_LOG("Class of_table_feature_prop_next_tables_miss.  Len %d too small, < %d", len, 4);
        return -1;
    }


    {    int next_table_ids_len = len - 4;


        if (of_list_uint8_OF_VERSION_1_3_validate(buf + 4, next_table_ids_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_table_feature_prop_next_tables_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 4) {
        VALIDATOR_LOG("Class of_table_feature_prop_next_tables.  Len %d too small, < %d", len, 4);
        return -1;
    }


    {    int next_table_ids_len = len - 4;


        if (of_list_uint8_OF_VERSION_1_3_validate(buf + 4, next_table_ids_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_table_feature_prop_match_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 4) {
        VALIDATOR_LOG("Class of_table_feature_prop_match.  Len %d too small, < %d", len, 4);
        return -1;
    }


    {    int oxm_ids_len = len - 4;


        if (of_list_uint32_OF_VERSION_1_3_validate(buf + 4, oxm_ids_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_table_feature_prop_instructions_miss_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 4) {
        VALIDATOR_LOG("Class of_table_feature_prop_instructions_miss.  Len %d too small, < %d", len, 4);
        return -1;
    }


    {    int instruction_ids_len = len - 4;


        if (of_list_instruction_OF_VERSION_1_3_validate(buf + 4, instruction_ids_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_table_feature_prop_instructions_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 4) {
        VALIDATOR_LOG("Class of_table_feature_prop_instructions.  Len %d too small, < %d", len, 4);
        return -1;
    }


    {    int instruction_ids_len = len - 4;


        if (of_list_instruction_OF_VERSION_1_3_validate(buf + 4, instruction_ids_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_table_feature_prop_header_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 4) {
        VALIDATOR_LOG("Class of_table_feature_prop_header.  Len %d too small, < %d", len, 4);
        return -1;
    }

    return 0;
}

static inline int
of_table_feature_prop_experimenter_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_table_feature_prop_experimenter.  Len %d too small, < %d", len, 12);
        return -1;
    }

    return 0;
}

static inline int
of_table_feature_prop_apply_setfield_miss_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 4) {
        VALIDATOR_LOG("Class of_table_feature_prop_apply_setfield_miss.  Len %d too small, < %d", len, 4);
        return -1;
    }


    {    int oxm_ids_len = len - 4;


        if (of_list_uint32_OF_VERSION_1_3_validate(buf + 4, oxm_ids_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_table_feature_prop_apply_setfield_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 4) {
        VALIDATOR_LOG("Class of_table_feature_prop_apply_setfield.  Len %d too small, < %d", len, 4);
        return -1;
    }


    {    int oxm_ids_len = len - 4;


        if (of_list_uint32_OF_VERSION_1_3_validate(buf + 4, oxm_ids_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_table_feature_prop_apply_actions_miss_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 4) {
        VALIDATOR_LOG("Class of_table_feature_prop_apply_actions_miss.  Len %d too small, < %d", len, 4);
        return -1;
    }


    {    int action_ids_len = len - 4;


        if (of_list_action_id_OF_VERSION_1_3_validate(buf + 4, action_ids_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_table_feature_prop_apply_actions_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 4) {
        VALIDATOR_LOG("Class of_table_feature_prop_apply_actions.  Len %d too small, < %d", len, 4);
        return -1;
    }


    {    int action_ids_len = len - 4;


        if (of_list_action_id_OF_VERSION_1_3_validate(buf + 4, action_ids_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_queue_stats_entry_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 40) {
        VALIDATOR_LOG("Class of_queue_stats_entry.  Len %d too small, < %d", len, 40);
        return -1;
    }

    return 0;
}

static inline int
of_queue_prop_min_rate_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_queue_prop_min_rate.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_queue_prop_max_rate_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_queue_prop_max_rate.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_queue_prop_header_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_queue_prop_header.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_queue_prop_experimenter_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_queue_prop_experimenter.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_port_stats_entry_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 112) {
        VALIDATOR_LOG("Class of_port_stats_entry.  Len %d too small, < %d", len, 112);
        return -1;
    }

    return 0;
}

static inline int
of_port_desc_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 64) {
        VALIDATOR_LOG("Class of_port_desc.  Len %d too small, < %d", len, 64);
        return -1;
    }

    return 0;
}

static inline int
of_packet_queue_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_packet_queue.  Len %d too small, < %d", len, 16);
        return -1;
    }


    {    int properties_len = len - 16;


        if (of_list_queue_prop_OF_VERSION_1_3_validate(buf + 16, properties_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_oxm_vlan_vid_masked_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_oxm_vlan_vid_masked.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_vlan_vid_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 6) {
        VALIDATOR_LOG("Class of_oxm_vlan_vid.  Len %d too small, < %d", len, 6);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_vlan_pcp_masked_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 6) {
        VALIDATOR_LOG("Class of_oxm_vlan_pcp_masked.  Len %d too small, < %d", len, 6);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_vlan_pcp_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 5) {
        VALIDATOR_LOG("Class of_oxm_vlan_pcp.  Len %d too small, < %d", len, 5);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_udp_src_masked_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_oxm_udp_src_masked.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_udp_src_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 6) {
        VALIDATOR_LOG("Class of_oxm_udp_src.  Len %d too small, < %d", len, 6);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_udp_dst_masked_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_oxm_udp_dst_masked.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_udp_dst_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 6) {
        VALIDATOR_LOG("Class of_oxm_udp_dst.  Len %d too small, < %d", len, 6);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_tcp_src_masked_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_oxm_tcp_src_masked.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_tcp_src_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 6) {
        VALIDATOR_LOG("Class of_oxm_tcp_src.  Len %d too small, < %d", len, 6);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_tcp_dst_masked_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_oxm_tcp_dst_masked.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_tcp_dst_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 6) {
        VALIDATOR_LOG("Class of_oxm_tcp_dst.  Len %d too small, < %d", len, 6);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_sctp_src_masked_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_oxm_sctp_src_masked.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_sctp_src_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 6) {
        VALIDATOR_LOG("Class of_oxm_sctp_src.  Len %d too small, < %d", len, 6);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_sctp_dst_masked_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_oxm_sctp_dst_masked.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_sctp_dst_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 6) {
        VALIDATOR_LOG("Class of_oxm_sctp_dst.  Len %d too small, < %d", len, 6);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_mpls_tc_masked_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 6) {
        VALIDATOR_LOG("Class of_oxm_mpls_tc_masked.  Len %d too small, < %d", len, 6);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_mpls_tc_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 5) {
        VALIDATOR_LOG("Class of_oxm_mpls_tc.  Len %d too small, < %d", len, 5);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_mpls_label_masked_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_oxm_mpls_label_masked.  Len %d too small, < %d", len, 12);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_mpls_label_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_oxm_mpls_label.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_metadata_masked_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 20) {
        VALIDATOR_LOG("Class of_oxm_metadata_masked.  Len %d too small, < %d", len, 20);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_metadata_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_oxm_metadata.  Len %d too small, < %d", len, 12);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_ipv6_src_masked_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 36) {
        VALIDATOR_LOG("Class of_oxm_ipv6_src_masked.  Len %d too small, < %d", len, 36);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_ipv6_src_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 20) {
        VALIDATOR_LOG("Class of_oxm_ipv6_src.  Len %d too small, < %d", len, 20);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_ipv6_nd_tll_masked_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_oxm_ipv6_nd_tll_masked.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_ipv6_nd_tll_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 10) {
        VALIDATOR_LOG("Class of_oxm_ipv6_nd_tll.  Len %d too small, < %d", len, 10);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_ipv6_nd_target_masked_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 36) {
        VALIDATOR_LOG("Class of_oxm_ipv6_nd_target_masked.  Len %d too small, < %d", len, 36);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_ipv6_nd_target_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 20) {
        VALIDATOR_LOG("Class of_oxm_ipv6_nd_target.  Len %d too small, < %d", len, 20);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_ipv6_nd_sll_masked_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_oxm_ipv6_nd_sll_masked.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_ipv6_nd_sll_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 10) {
        VALIDATOR_LOG("Class of_oxm_ipv6_nd_sll.  Len %d too small, < %d", len, 10);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_ipv6_flabel_masked_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_oxm_ipv6_flabel_masked.  Len %d too small, < %d", len, 12);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_ipv6_flabel_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_oxm_ipv6_flabel.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_ipv6_dst_masked_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 36) {
        VALIDATOR_LOG("Class of_oxm_ipv6_dst_masked.  Len %d too small, < %d", len, 36);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_ipv6_dst_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 20) {
        VALIDATOR_LOG("Class of_oxm_ipv6_dst.  Len %d too small, < %d", len, 20);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_ipv4_src_masked_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_oxm_ipv4_src_masked.  Len %d too small, < %d", len, 12);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_ipv4_src_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_oxm_ipv4_src.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_ipv4_dst_masked_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_oxm_ipv4_dst_masked.  Len %d too small, < %d", len, 12);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_ipv4_dst_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_oxm_ipv4_dst.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_ip_proto_masked_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 6) {
        VALIDATOR_LOG("Class of_oxm_ip_proto_masked.  Len %d too small, < %d", len, 6);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_ip_proto_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 5) {
        VALIDATOR_LOG("Class of_oxm_ip_proto.  Len %d too small, < %d", len, 5);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_ip_ecn_masked_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 6) {
        VALIDATOR_LOG("Class of_oxm_ip_ecn_masked.  Len %d too small, < %d", len, 6);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_ip_ecn_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 5) {
        VALIDATOR_LOG("Class of_oxm_ip_ecn.  Len %d too small, < %d", len, 5);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_ip_dscp_masked_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 6) {
        VALIDATOR_LOG("Class of_oxm_ip_dscp_masked.  Len %d too small, < %d", len, 6);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_ip_dscp_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 5) {
        VALIDATOR_LOG("Class of_oxm_ip_dscp.  Len %d too small, < %d", len, 5);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_in_port_masked_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_oxm_in_port_masked.  Len %d too small, < %d", len, 12);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_in_port_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_oxm_in_port.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_in_phy_port_masked_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_oxm_in_phy_port_masked.  Len %d too small, < %d", len, 12);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_in_phy_port_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_oxm_in_phy_port.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_icmpv6_type_masked_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 6) {
        VALIDATOR_LOG("Class of_oxm_icmpv6_type_masked.  Len %d too small, < %d", len, 6);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_icmpv6_type_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 5) {
        VALIDATOR_LOG("Class of_oxm_icmpv6_type.  Len %d too small, < %d", len, 5);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_icmpv6_code_masked_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 6) {
        VALIDATOR_LOG("Class of_oxm_icmpv6_code_masked.  Len %d too small, < %d", len, 6);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_icmpv6_code_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 5) {
        VALIDATOR_LOG("Class of_oxm_icmpv6_code.  Len %d too small, < %d", len, 5);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_icmpv4_type_masked_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 6) {
        VALIDATOR_LOG("Class of_oxm_icmpv4_type_masked.  Len %d too small, < %d", len, 6);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_icmpv4_type_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 5) {
        VALIDATOR_LOG("Class of_oxm_icmpv4_type.  Len %d too small, < %d", len, 5);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_icmpv4_code_masked_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 6) {
        VALIDATOR_LOG("Class of_oxm_icmpv4_code_masked.  Len %d too small, < %d", len, 6);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_icmpv4_code_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 5) {
        VALIDATOR_LOG("Class of_oxm_icmpv4_code.  Len %d too small, < %d", len, 5);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_header_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 4) {
        VALIDATOR_LOG("Class of_oxm_header.  Len %d too small, < %d", len, 4);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_eth_type_masked_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_oxm_eth_type_masked.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_eth_type_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 6) {
        VALIDATOR_LOG("Class of_oxm_eth_type.  Len %d too small, < %d", len, 6);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_eth_src_masked_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_oxm_eth_src_masked.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_eth_src_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 10) {
        VALIDATOR_LOG("Class of_oxm_eth_src.  Len %d too small, < %d", len, 10);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_eth_dst_masked_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_oxm_eth_dst_masked.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_eth_dst_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 10) {
        VALIDATOR_LOG("Class of_oxm_eth_dst.  Len %d too small, < %d", len, 10);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_bsn_vrf_masked_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_oxm_bsn_vrf_masked.  Len %d too small, < %d", len, 12);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_bsn_vrf_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_oxm_bsn_vrf.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_bsn_lag_id_masked_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_oxm_bsn_lag_id_masked.  Len %d too small, < %d", len, 12);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_bsn_lag_id_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_oxm_bsn_lag_id.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_bsn_l3_src_class_id_masked_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_oxm_bsn_l3_src_class_id_masked.  Len %d too small, < %d", len, 12);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_bsn_l3_src_class_id_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_oxm_bsn_l3_src_class_id.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_bsn_l3_interface_class_id_masked_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_oxm_bsn_l3_interface_class_id_masked.  Len %d too small, < %d", len, 12);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_bsn_l3_interface_class_id_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_oxm_bsn_l3_interface_class_id.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_bsn_l3_dst_class_id_masked_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_oxm_bsn_l3_dst_class_id_masked.  Len %d too small, < %d", len, 12);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_bsn_l3_dst_class_id_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_oxm_bsn_l3_dst_class_id.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_bsn_in_ports_128_masked_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 36) {
        VALIDATOR_LOG("Class of_oxm_bsn_in_ports_128_masked.  Len %d too small, < %d", len, 36);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_bsn_in_ports_128_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 20) {
        VALIDATOR_LOG("Class of_oxm_bsn_in_ports_128.  Len %d too small, < %d", len, 20);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_bsn_global_vrf_allowed_masked_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 6) {
        VALIDATOR_LOG("Class of_oxm_bsn_global_vrf_allowed_masked.  Len %d too small, < %d", len, 6);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_bsn_global_vrf_allowed_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 5) {
        VALIDATOR_LOG("Class of_oxm_bsn_global_vrf_allowed.  Len %d too small, < %d", len, 5);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_arp_tpa_masked_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_oxm_arp_tpa_masked.  Len %d too small, < %d", len, 12);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_arp_tpa_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_oxm_arp_tpa.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_arp_tha_masked_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_oxm_arp_tha_masked.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_arp_tha_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 10) {
        VALIDATOR_LOG("Class of_oxm_arp_tha.  Len %d too small, < %d", len, 10);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_arp_spa_masked_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_oxm_arp_spa_masked.  Len %d too small, < %d", len, 12);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_arp_spa_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_oxm_arp_spa.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_arp_sha_masked_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_oxm_arp_sha_masked.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_arp_sha_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 10) {
        VALIDATOR_LOG("Class of_oxm_arp_sha.  Len %d too small, < %d", len, 10);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_arp_op_masked_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_oxm_arp_op_masked.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_oxm_arp_op_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 6) {
        VALIDATOR_LOG("Class of_oxm_arp_op.  Len %d too small, < %d", len, 6);
        return -1;
    }

    return 0;
}

static inline int
of_meter_stats_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 40) {
        VALIDATOR_LOG("Class of_meter_stats.  Len %d too small, < %d", len, 40);
        return -1;
    }


    {    int band_stats_len = len - 40;


        if (of_list_meter_band_stats_OF_VERSION_1_3_validate(buf + 40, band_stats_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_meter_features_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_meter_features.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_meter_config_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_meter_config.  Len %d too small, < %d", len, 8);
        return -1;
    }


    {    int entries_len = len - 8;


        if (of_list_meter_band_OF_VERSION_1_3_validate(buf + 8, entries_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_meter_band_stats_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_meter_band_stats.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_meter_band_header_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 4) {
        VALIDATOR_LOG("Class of_meter_band_header.  Len %d too small, < %d", len, 4);
        return -1;
    }

    return 0;
}

static inline int
of_meter_band_experimenter_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_meter_band_experimenter.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_meter_band_dscp_remark_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_meter_band_dscp_remark.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_meter_band_drop_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_meter_band_drop.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_match_v3_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 4) {
        VALIDATOR_LOG("Class of_match_v3.  Len %d too small, < %d", len, 4);
        return -1;
    }


    {    int oxm_list_len = len - 4;


        if (of_list_oxm_OF_VERSION_1_3_validate(buf + 4, oxm_list_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_instruction_write_metadata_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 24) {
        VALIDATOR_LOG("Class of_instruction_write_metadata.  Len %d too small, < %d", len, 24);
        return -1;
    }

    return 0;
}

static inline int
of_instruction_write_actions_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_instruction_write_actions.  Len %d too small, < %d", len, 8);
        return -1;
    }


    {    int actions_len = len - 8;


        if (of_list_action_OF_VERSION_1_3_validate(buf + 8, actions_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_instruction_meter_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_instruction_meter.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_instruction_id_write_metadata_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_instruction_id_write_metadata.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_instruction_id_write_actions_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_instruction_id_write_actions.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_instruction_id_meter_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 4) {
        VALIDATOR_LOG("Class of_instruction_id_meter.  Len %d too small, < %d", len, 4);
        return -1;
    }

    return 0;
}

static inline int
of_instruction_id_header_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 4) {
        VALIDATOR_LOG("Class of_instruction_id_header.  Len %d too small, < %d", len, 4);
        return -1;
    }

    return 0;
}

static inline int
of_instruction_id_goto_table_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 7) {
        VALIDATOR_LOG("Class of_instruction_id_goto_table.  Len %d too small, < %d", len, 7);
        return -1;
    }

    return 0;
}

static inline int
of_instruction_id_experimenter_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_instruction_id_experimenter.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_instruction_id_clear_actions_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_instruction_id_clear_actions.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_instruction_id_bsn_disable_src_mac_check_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_instruction_id_bsn_disable_src_mac_check.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_instruction_id_bsn_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_instruction_id_bsn.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_instruction_id_apply_actions_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_instruction_id_apply_actions.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_instruction_header_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 4) {
        VALIDATOR_LOG("Class of_instruction_header.  Len %d too small, < %d", len, 4);
        return -1;
    }

    return 0;
}

static inline int
of_instruction_goto_table_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_instruction_goto_table.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_instruction_experimenter_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_instruction_experimenter.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_instruction_clear_actions_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_instruction_clear_actions.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_instruction_bsn_disable_src_mac_check_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_instruction_bsn_disable_src_mac_check.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_instruction_bsn_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_instruction_bsn.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_instruction_apply_actions_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_instruction_apply_actions.  Len %d too small, < %d", len, 8);
        return -1;
    }


    {    int actions_len = len - 8;


        if (of_list_action_OF_VERSION_1_3_validate(buf + 8, actions_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_hello_elem_versionbitmap_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 4) {
        VALIDATOR_LOG("Class of_hello_elem_versionbitmap.  Len %d too small, < %d", len, 4);
        return -1;
    }


    {    int bitmaps_len = len - 4;


        if (of_list_uint32_OF_VERSION_1_3_validate(buf + 4, bitmaps_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_hello_elem_header_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 4) {
        VALIDATOR_LOG("Class of_hello_elem_header.  Len %d too small, < %d", len, 4);
        return -1;
    }

    return 0;
}

static inline int
of_header_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_header.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_group_stats_entry_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 40) {
        VALIDATOR_LOG("Class of_group_stats_entry.  Len %d too small, < %d", len, 40);
        return -1;
    }


    {    int bucket_stats_len = len - 40;


        if (of_list_bucket_counter_OF_VERSION_1_3_validate(buf + 40, bucket_stats_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_group_desc_stats_entry_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_group_desc_stats_entry.  Len %d too small, < %d", len, 8);
        return -1;
    }


    {    int buckets_len = len - 8;


        if (of_list_bucket_OF_VERSION_1_3_validate(buf + 8, buckets_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_flow_stats_entry_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 56) {
        VALIDATOR_LOG("Class of_flow_stats_entry.  Len %d too small, < %d", len, 56);
        return -1;
    }


    {    int instructions_len = len - -1;


        if (of_list_instruction_OF_VERSION_1_3_validate(buf + -1, instructions_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_experimenter_stats_header_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_experimenter_stats_header.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_bucket_counter_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_bucket_counter.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_bucket_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_bucket.  Len %d too small, < %d", len, 16);
        return -1;
    }


    {    int actions_len = len - 16;


        if (of_list_action_OF_VERSION_1_3_validate(buf + 16, actions_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_bsn_vport_q_in_q_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 32) {
        VALIDATOR_LOG("Class of_bsn_vport_q_in_q.  Len %d too small, < %d", len, 32);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_vport_header_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 4) {
        VALIDATOR_LOG("Class of_bsn_vport_header.  Len %d too small, < %d", len, 4);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_vlan_counter_stats_entry_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_bsn_vlan_counter_stats_entry.  Len %d too small, < %d", len, 8);
        return -1;
    }


    {    int values_len = len - 8;


        if (of_list_uint64_OF_VERSION_1_3_validate(buf + 8, values_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_bsn_switch_pipeline_stats_entry_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 256) {
        VALIDATOR_LOG("Class of_bsn_switch_pipeline_stats_entry.  Len %d too small, < %d", len, 256);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_port_counter_stats_entry_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_bsn_port_counter_stats_entry.  Len %d too small, < %d", len, 8);
        return -1;
    }


    {    int values_len = len - 8;


        if (of_list_uint64_OF_VERSION_1_3_validate(buf + 8, values_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_bsn_lacp_stats_entry_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 36) {
        VALIDATOR_LOG("Class of_bsn_lacp_stats_entry.  Len %d too small, < %d", len, 36);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_interface_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 32) {
        VALIDATOR_LOG("Class of_bsn_interface.  Len %d too small, < %d", len, 32);
        return -1;
    }

    return 0;
}

static inline int
of_action_set_queue_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_action_set_queue.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_action_set_nw_ttl_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_action_set_nw_ttl.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_action_set_mpls_ttl_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_action_set_mpls_ttl.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_action_set_field_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 4) {
        VALIDATOR_LOG("Class of_action_set_field.  Len %d too small, < %d", len, 4);
        return -1;
    }

    return 0;
}

static inline int
of_action_push_vlan_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_action_push_vlan.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_action_push_pbb_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_action_push_pbb.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_action_push_mpls_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_action_push_mpls.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_action_pop_vlan_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_action_pop_vlan.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_action_pop_pbb_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_action_pop_pbb.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_action_pop_mpls_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_action_pop_mpls.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_action_output_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_action_output.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_action_nicira_dec_ttl_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_action_nicira_dec_ttl.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_action_nicira_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_action_nicira.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_action_id_set_queue_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 4) {
        VALIDATOR_LOG("Class of_action_id_set_queue.  Len %d too small, < %d", len, 4);
        return -1;
    }

    return 0;
}

static inline int
of_action_id_set_nw_ttl_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 7) {
        VALIDATOR_LOG("Class of_action_id_set_nw_ttl.  Len %d too small, < %d", len, 7);
        return -1;
    }

    return 0;
}

static inline int
of_action_id_set_mpls_ttl_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 7) {
        VALIDATOR_LOG("Class of_action_id_set_mpls_ttl.  Len %d too small, < %d", len, 7);
        return -1;
    }

    return 0;
}

static inline int
of_action_id_set_field_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 4) {
        VALIDATOR_LOG("Class of_action_id_set_field.  Len %d too small, < %d", len, 4);
        return -1;
    }

    return 0;
}

static inline int
of_action_id_push_vlan_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 6) {
        VALIDATOR_LOG("Class of_action_id_push_vlan.  Len %d too small, < %d", len, 6);
        return -1;
    }

    return 0;
}

static inline int
of_action_id_push_pbb_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 6) {
        VALIDATOR_LOG("Class of_action_id_push_pbb.  Len %d too small, < %d", len, 6);
        return -1;
    }

    return 0;
}

static inline int
of_action_id_push_mpls_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 6) {
        VALIDATOR_LOG("Class of_action_id_push_mpls.  Len %d too small, < %d", len, 6);
        return -1;
    }

    return 0;
}

static inline int
of_action_id_pop_vlan_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_action_id_pop_vlan.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_action_id_pop_pbb_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_action_id_pop_pbb.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_action_id_pop_mpls_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 6) {
        VALIDATOR_LOG("Class of_action_id_pop_mpls.  Len %d too small, < %d", len, 6);
        return -1;
    }

    return 0;
}

static inline int
of_action_id_output_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 10) {
        VALIDATOR_LOG("Class of_action_id_output.  Len %d too small, < %d", len, 10);
        return -1;
    }

    return 0;
}

static inline int
of_action_id_nicira_dec_ttl_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_action_id_nicira_dec_ttl.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_action_id_nicira_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_action_id_nicira.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_action_id_header_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_action_id_header.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_action_id_group_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 4) {
        VALIDATOR_LOG("Class of_action_id_group.  Len %d too small, < %d", len, 4);
        return -1;
    }

    return 0;
}

static inline int
of_action_id_experimenter_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_action_id_experimenter.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_action_id_dec_nw_ttl_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_action_id_dec_nw_ttl.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_action_id_dec_mpls_ttl_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_action_id_dec_mpls_ttl.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_action_id_copy_ttl_out_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_action_id_copy_ttl_out.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_action_id_copy_ttl_in_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_action_id_copy_ttl_in.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_action_id_bsn_set_tunnel_dst_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_action_id_bsn_set_tunnel_dst.  Len %d too small, < %d", len, 12);
        return -1;
    }

    return 0;
}

static inline int
of_action_id_bsn_mirror_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 15) {
        VALIDATOR_LOG("Class of_action_id_bsn_mirror.  Len %d too small, < %d", len, 15);
        return -1;
    }

    return 0;
}

static inline int
of_action_id_bsn_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_action_id_bsn.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_action_header_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_action_header.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_action_group_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_action_group.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_action_experimenter_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_action_experimenter.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_action_dec_nw_ttl_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_action_dec_nw_ttl.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_action_dec_mpls_ttl_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_action_dec_mpls_ttl.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_action_copy_ttl_out_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_action_copy_ttl_out.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_action_copy_ttl_in_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_action_copy_ttl_in.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_action_bsn_set_tunnel_dst_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_action_bsn_set_tunnel_dst.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_action_bsn_mirror_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 24) {
        VALIDATOR_LOG("Class of_action_bsn_mirror.  Len %d too small, < %d", len, 24);
        return -1;
    }

    return 0;
}

static inline int
of_action_bsn_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_action_bsn.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_table_stats_request_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_table_stats_request.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_table_stats_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_table_stats_reply.  Len %d too small, < %d", len, 16);
        return -1;
    }


    {    int entries_len = len - 16;


        if (of_list_table_stats_entry_OF_VERSION_1_3_validate(buf + 16, entries_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_table_mod_failed_error_msg_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_table_mod_failed_error_msg.  Len %d too small, < %d", len, 12);
        return -1;
    }

    return 0;
}

static inline int
of_table_mod_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_table_mod.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_table_features_stats_request_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_table_features_stats_request.  Len %d too small, < %d", len, 16);
        return -1;
    }


    {    int entries_len = len - 16;


        if (of_list_table_features_OF_VERSION_1_3_validate(buf + 16, entries_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_table_features_stats_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_table_features_stats_reply.  Len %d too small, < %d", len, 16);
        return -1;
    }


    {    int entries_len = len - 16;


        if (of_list_table_features_OF_VERSION_1_3_validate(buf + 16, entries_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_table_features_failed_error_msg_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_table_features_failed_error_msg.  Len %d too small, < %d", len, 12);
        return -1;
    }

    return 0;
}

static inline int
of_switch_config_failed_error_msg_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_switch_config_failed_error_msg.  Len %d too small, < %d", len, 12);
        return -1;
    }

    return 0;
}

static inline int
of_stats_request_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_stats_request.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_stats_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_stats_reply.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_set_config_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_set_config.  Len %d too small, < %d", len, 12);
        return -1;
    }

    return 0;
}

static inline int
of_role_request_failed_error_msg_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_role_request_failed_error_msg.  Len %d too small, < %d", len, 12);
        return -1;
    }

    return 0;
}

static inline int
of_role_request_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 24) {
        VALIDATOR_LOG("Class of_role_request.  Len %d too small, < %d", len, 24);
        return -1;
    }

    return 0;
}

static inline int
of_role_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 24) {
        VALIDATOR_LOG("Class of_role_reply.  Len %d too small, < %d", len, 24);
        return -1;
    }

    return 0;
}

static inline int
of_queue_stats_request_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 24) {
        VALIDATOR_LOG("Class of_queue_stats_request.  Len %d too small, < %d", len, 24);
        return -1;
    }

    return 0;
}

static inline int
of_queue_stats_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_queue_stats_reply.  Len %d too small, < %d", len, 16);
        return -1;
    }


    {    int entries_len = len - 16;


        if (of_list_queue_stats_entry_OF_VERSION_1_3_validate(buf + 16, entries_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_queue_op_failed_error_msg_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_queue_op_failed_error_msg.  Len %d too small, < %d", len, 12);
        return -1;
    }

    return 0;
}

static inline int
of_queue_get_config_request_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_queue_get_config_request.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_queue_get_config_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_queue_get_config_reply.  Len %d too small, < %d", len, 16);
        return -1;
    }


    {    int queues_len = len - 16;


        if (of_list_packet_queue_OF_VERSION_1_3_validate(buf + 16, queues_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_port_status_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 80) {
        VALIDATOR_LOG("Class of_port_status.  Len %d too small, < %d", len, 80);
        return -1;
    }

    return 0;
}

static inline int
of_port_stats_request_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 24) {
        VALIDATOR_LOG("Class of_port_stats_request.  Len %d too small, < %d", len, 24);
        return -1;
    }

    return 0;
}

static inline int
of_port_stats_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_port_stats_reply.  Len %d too small, < %d", len, 16);
        return -1;
    }


    {    int entries_len = len - 16;


        if (of_list_port_stats_entry_OF_VERSION_1_3_validate(buf + 16, entries_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_port_mod_failed_error_msg_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_port_mod_failed_error_msg.  Len %d too small, < %d", len, 12);
        return -1;
    }

    return 0;
}

static inline int
of_port_mod_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 40) {
        VALIDATOR_LOG("Class of_port_mod.  Len %d too small, < %d", len, 40);
        return -1;
    }

    return 0;
}

static inline int
of_port_desc_stats_request_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_port_desc_stats_request.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_port_desc_stats_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_port_desc_stats_reply.  Len %d too small, < %d", len, 16);
        return -1;
    }


    {    int entries_len = len - 16;


        if (of_list_port_desc_OF_VERSION_1_3_validate(buf + 16, entries_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_packet_out_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 24) {
        VALIDATOR_LOG("Class of_packet_out.  Len %d too small, < %d", len, 24);
        return -1;
    }

    {
        uint16_t actions_len;
        buf_u16_get(buf + 24 - 2, &actions_len);
        if (actions_len + 24 > len) {
            VALIDATOR_LOG("Class of_packet_out, member actions.  "
                          "Len %d and offset %d too big for %d",
                          actions_len, 24, len);
            return -1;
        }

        if (of_list_action_OF_VERSION_1_3_validate(buf + 24, actions_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_packet_in_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 32) {
        VALIDATOR_LOG("Class of_packet_in.  Len %d too small, < %d", len, 32);
        return -1;
    }

    return 0;
}

static inline int
of_nicira_header_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_nicira_header.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_meter_stats_request_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 24) {
        VALIDATOR_LOG("Class of_meter_stats_request.  Len %d too small, < %d", len, 24);
        return -1;
    }

    return 0;
}

static inline int
of_meter_stats_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_meter_stats_reply.  Len %d too small, < %d", len, 16);
        return -1;
    }


    {    int entries_len = len - 16;


        if (of_list_meter_stats_OF_VERSION_1_3_validate(buf + 16, entries_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_meter_mod_failed_error_msg_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_meter_mod_failed_error_msg.  Len %d too small, < %d", len, 12);
        return -1;
    }

    return 0;
}

static inline int
of_meter_mod_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_meter_mod.  Len %d too small, < %d", len, 16);
        return -1;
    }


    {    int meters_len = len - 16;


        if (of_list_meter_band_OF_VERSION_1_3_validate(buf + 16, meters_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_meter_features_stats_request_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_meter_features_stats_request.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_meter_features_stats_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 32) {
        VALIDATOR_LOG("Class of_meter_features_stats_reply.  Len %d too small, < %d", len, 32);
        return -1;
    }

    return 0;
}

static inline int
of_meter_config_stats_request_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 24) {
        VALIDATOR_LOG("Class of_meter_config_stats_request.  Len %d too small, < %d", len, 24);
        return -1;
    }

    return 0;
}

static inline int
of_meter_config_stats_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_meter_config_stats_reply.  Len %d too small, < %d", len, 16);
        return -1;
    }


    {    int entries_len = len - 16;


        if (of_list_meter_band_OF_VERSION_1_3_validate(buf + 16, entries_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_hello_failed_error_msg_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_hello_failed_error_msg.  Len %d too small, < %d", len, 12);
        return -1;
    }

    return 0;
}

static inline int
of_hello_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_hello.  Len %d too small, < %d", len, 8);
        return -1;
    }


    {    int elements_len = len - 8;


        if (of_list_hello_elem_OF_VERSION_1_3_validate(buf + 8, elements_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_group_stats_request_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 24) {
        VALIDATOR_LOG("Class of_group_stats_request.  Len %d too small, < %d", len, 24);
        return -1;
    }

    return 0;
}

static inline int
of_group_stats_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_group_stats_reply.  Len %d too small, < %d", len, 16);
        return -1;
    }


    {    int entries_len = len - 16;


        if (of_list_group_stats_entry_OF_VERSION_1_3_validate(buf + 16, entries_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_group_modify_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_group_modify.  Len %d too small, < %d", len, 16);
        return -1;
    }


    {    int buckets_len = len - 16;


        if (of_list_bucket_OF_VERSION_1_3_validate(buf + 16, buckets_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_group_mod_failed_error_msg_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_group_mod_failed_error_msg.  Len %d too small, < %d", len, 12);
        return -1;
    }

    return 0;
}

static inline int
of_group_mod_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_group_mod.  Len %d too small, < %d", len, 16);
        return -1;
    }


    {    int buckets_len = len - 16;


        if (of_list_bucket_OF_VERSION_1_3_validate(buf + 16, buckets_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_group_features_stats_request_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_group_features_stats_request.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_group_features_stats_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 56) {
        VALIDATOR_LOG("Class of_group_features_stats_reply.  Len %d too small, < %d", len, 56);
        return -1;
    }

    return 0;
}

static inline int
of_group_desc_stats_request_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_group_desc_stats_request.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_group_desc_stats_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_group_desc_stats_reply.  Len %d too small, < %d", len, 16);
        return -1;
    }


    {    int entries_len = len - 16;


        if (of_list_group_desc_stats_entry_OF_VERSION_1_3_validate(buf + 16, entries_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_group_delete_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_group_delete.  Len %d too small, < %d", len, 16);
        return -1;
    }


    {    int buckets_len = len - 16;


        if (of_list_bucket_OF_VERSION_1_3_validate(buf + 16, buckets_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_group_add_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_group_add.  Len %d too small, < %d", len, 16);
        return -1;
    }


    {    int buckets_len = len - 16;


        if (of_list_bucket_OF_VERSION_1_3_validate(buf + 16, buckets_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_get_config_request_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_get_config_request.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_get_config_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_get_config_reply.  Len %d too small, < %d", len, 12);
        return -1;
    }

    return 0;
}

static inline int
of_flow_stats_request_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 56) {
        VALIDATOR_LOG("Class of_flow_stats_request.  Len %d too small, < %d", len, 56);
        return -1;
    }

    return 0;
}

static inline int
of_flow_stats_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_flow_stats_reply.  Len %d too small, < %d", len, 16);
        return -1;
    }


    {    int entries_len = len - 16;


        if (of_list_flow_stats_entry_OF_VERSION_1_3_validate(buf + 16, entries_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_flow_removed_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 56) {
        VALIDATOR_LOG("Class of_flow_removed.  Len %d too small, < %d", len, 56);
        return -1;
    }

    return 0;
}

static inline int
of_flow_modify_strict_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 56) {
        VALIDATOR_LOG("Class of_flow_modify_strict.  Len %d too small, < %d", len, 56);
        return -1;
    }

    {
        uint16_t instructions_len, instructions_offset;
        uint16_t match_len;
        buf_u16_get(buf + 48 + 2, &match_len);
        instructions_offset = 48 + OF_MATCH_BYTES(match_len);
        instructions_len = len - instructions_offset;

        if (of_list_instruction_OF_VERSION_1_3_validate(buf + instructions_offset, instructions_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_flow_modify_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 56) {
        VALIDATOR_LOG("Class of_flow_modify.  Len %d too small, < %d", len, 56);
        return -1;
    }

    {
        uint16_t instructions_len, instructions_offset;
        uint16_t match_len;
        buf_u16_get(buf + 48 + 2, &match_len);
        instructions_offset = 48 + OF_MATCH_BYTES(match_len);
        instructions_len = len - instructions_offset;

        if (of_list_instruction_OF_VERSION_1_3_validate(buf + instructions_offset, instructions_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_flow_mod_failed_error_msg_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_flow_mod_failed_error_msg.  Len %d too small, < %d", len, 12);
        return -1;
    }

    return 0;
}

static inline int
of_flow_mod_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 56) {
        VALIDATOR_LOG("Class of_flow_mod.  Len %d too small, < %d", len, 56);
        return -1;
    }

    {
        uint16_t instructions_len, instructions_offset;
        uint16_t match_len;
        buf_u16_get(buf + 48 + 2, &match_len);
        instructions_offset = 48 + OF_MATCH_BYTES(match_len);
        instructions_len = len - instructions_offset;

        if (of_list_instruction_OF_VERSION_1_3_validate(buf + instructions_offset, instructions_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_flow_delete_strict_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 56) {
        VALIDATOR_LOG("Class of_flow_delete_strict.  Len %d too small, < %d", len, 56);
        return -1;
    }

    {
        uint16_t instructions_len, instructions_offset;
        uint16_t match_len;
        buf_u16_get(buf + 48 + 2, &match_len);
        instructions_offset = 48 + OF_MATCH_BYTES(match_len);
        instructions_len = len - instructions_offset;

        if (of_list_instruction_OF_VERSION_1_3_validate(buf + instructions_offset, instructions_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_flow_delete_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 56) {
        VALIDATOR_LOG("Class of_flow_delete.  Len %d too small, < %d", len, 56);
        return -1;
    }

    {
        uint16_t instructions_len, instructions_offset;
        uint16_t match_len;
        buf_u16_get(buf + 48 + 2, &match_len);
        instructions_offset = 48 + OF_MATCH_BYTES(match_len);
        instructions_len = len - instructions_offset;

        if (of_list_instruction_OF_VERSION_1_3_validate(buf + instructions_offset, instructions_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_flow_add_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 56) {
        VALIDATOR_LOG("Class of_flow_add.  Len %d too small, < %d", len, 56);
        return -1;
    }

    {
        uint16_t instructions_len, instructions_offset;
        uint16_t match_len;
        buf_u16_get(buf + 48 + 2, &match_len);
        instructions_offset = 48 + OF_MATCH_BYTES(match_len);
        instructions_len = len - instructions_offset;

        if (of_list_instruction_OF_VERSION_1_3_validate(buf + instructions_offset, instructions_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_features_request_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_features_request.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_features_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 32) {
        VALIDATOR_LOG("Class of_features_reply.  Len %d too small, < %d", len, 32);
        return -1;
    }

    return 0;
}

static inline int
of_experimenter_stats_request_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 24) {
        VALIDATOR_LOG("Class of_experimenter_stats_request.  Len %d too small, < %d", len, 24);
        return -1;
    }

    return 0;
}

static inline int
of_experimenter_stats_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 24) {
        VALIDATOR_LOG("Class of_experimenter_stats_reply.  Len %d too small, < %d", len, 24);
        return -1;
    }

    return 0;
}

static inline int
of_experimenter_error_msg_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_experimenter_error_msg.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_experimenter_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_experimenter.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_error_msg_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 10) {
        VALIDATOR_LOG("Class of_error_msg.  Len %d too small, < %d", len, 10);
        return -1;
    }

    return 0;
}

static inline int
of_echo_request_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_echo_request.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_echo_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_echo_reply.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_desc_stats_request_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_desc_stats_request.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_desc_stats_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 1072) {
        VALIDATOR_LOG("Class of_desc_stats_reply.  Len %d too small, < %d", len, 1072);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_vlan_counter_stats_request_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 26) {
        VALIDATOR_LOG("Class of_bsn_vlan_counter_stats_request.  Len %d too small, < %d", len, 26);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_vlan_counter_stats_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 24) {
        VALIDATOR_LOG("Class of_bsn_vlan_counter_stats_reply.  Len %d too small, < %d", len, 24);
        return -1;
    }


    {    int entries_len = len - 24;


        if (of_list_bsn_vlan_counter_stats_entry_OF_VERSION_1_3_validate(buf + 24, entries_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_bsn_virtual_port_remove_request_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 20) {
        VALIDATOR_LOG("Class of_bsn_virtual_port_remove_request.  Len %d too small, < %d", len, 20);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_virtual_port_remove_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 20) {
        VALIDATOR_LOG("Class of_bsn_virtual_port_remove_reply.  Len %d too small, < %d", len, 20);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_virtual_port_create_request_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 48) {
        VALIDATOR_LOG("Class of_bsn_virtual_port_create_request.  Len %d too small, < %d", len, 48);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_virtual_port_create_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 24) {
        VALIDATOR_LOG("Class of_bsn_virtual_port_create_reply.  Len %d too small, < %d", len, 24);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_time_request_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_bsn_time_request.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_time_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 24) {
        VALIDATOR_LOG("Class of_bsn_time_reply.  Len %d too small, < %d", len, 24);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_switch_pipeline_stats_request_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 24) {
        VALIDATOR_LOG("Class of_bsn_switch_pipeline_stats_request.  Len %d too small, < %d", len, 24);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_switch_pipeline_stats_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 24) {
        VALIDATOR_LOG("Class of_bsn_switch_pipeline_stats_reply.  Len %d too small, < %d", len, 24);
        return -1;
    }


    {    int entries_len = len - 24;


        if (of_list_bsn_switch_pipeline_stats_entry_OF_VERSION_1_3_validate(buf + 24, entries_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_bsn_stats_request_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 24) {
        VALIDATOR_LOG("Class of_bsn_stats_request.  Len %d too small, < %d", len, 24);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_stats_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 24) {
        VALIDATOR_LOG("Class of_bsn_stats_reply.  Len %d too small, < %d", len, 24);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_set_switch_pipeline_request_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 272) {
        VALIDATOR_LOG("Class of_bsn_set_switch_pipeline_request.  Len %d too small, < %d", len, 272);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_set_switch_pipeline_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 20) {
        VALIDATOR_LOG("Class of_bsn_set_switch_pipeline_reply.  Len %d too small, < %d", len, 20);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_set_pktin_suppression_request_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 32) {
        VALIDATOR_LOG("Class of_bsn_set_pktin_suppression_request.  Len %d too small, < %d", len, 32);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_set_pktin_suppression_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 20) {
        VALIDATOR_LOG("Class of_bsn_set_pktin_suppression_reply.  Len %d too small, < %d", len, 20);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_set_mirroring_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 20) {
        VALIDATOR_LOG("Class of_bsn_set_mirroring.  Len %d too small, < %d", len, 20);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_set_lacp_request_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 38) {
        VALIDATOR_LOG("Class of_bsn_set_lacp_request.  Len %d too small, < %d", len, 38);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_set_lacp_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 24) {
        VALIDATOR_LOG("Class of_bsn_set_lacp_reply.  Len %d too small, < %d", len, 24);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_port_counter_stats_request_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 28) {
        VALIDATOR_LOG("Class of_bsn_port_counter_stats_request.  Len %d too small, < %d", len, 28);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_port_counter_stats_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 24) {
        VALIDATOR_LOG("Class of_bsn_port_counter_stats_reply.  Len %d too small, < %d", len, 24);
        return -1;
    }


    {    int entries_len = len - 24;


        if (of_list_bsn_port_counter_stats_entry_OF_VERSION_1_3_validate(buf + 24, entries_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_bsn_pdu_tx_request_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 28) {
        VALIDATOR_LOG("Class of_bsn_pdu_tx_request.  Len %d too small, < %d", len, 28);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_pdu_tx_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 25) {
        VALIDATOR_LOG("Class of_bsn_pdu_tx_reply.  Len %d too small, < %d", len, 25);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_pdu_rx_timeout_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 21) {
        VALIDATOR_LOG("Class of_bsn_pdu_rx_timeout.  Len %d too small, < %d", len, 21);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_pdu_rx_request_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 28) {
        VALIDATOR_LOG("Class of_bsn_pdu_rx_request.  Len %d too small, < %d", len, 28);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_pdu_rx_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 25) {
        VALIDATOR_LOG("Class of_bsn_pdu_rx_reply.  Len %d too small, < %d", len, 25);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_lacp_stats_request_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 24) {
        VALIDATOR_LOG("Class of_bsn_lacp_stats_request.  Len %d too small, < %d", len, 24);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_lacp_stats_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 24) {
        VALIDATOR_LOG("Class of_bsn_lacp_stats_reply.  Len %d too small, < %d", len, 24);
        return -1;
    }


    {    int entries_len = len - 24;


        if (of_list_bsn_lacp_stats_entry_OF_VERSION_1_3_validate(buf + 24, entries_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_bsn_lacp_convergence_notif_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 52) {
        VALIDATOR_LOG("Class of_bsn_lacp_convergence_notif.  Len %d too small, < %d", len, 52);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_header_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_bsn_header.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_get_switch_pipeline_request_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_bsn_get_switch_pipeline_request.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_get_switch_pipeline_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 272) {
        VALIDATOR_LOG("Class of_bsn_get_switch_pipeline_reply.  Len %d too small, < %d", len, 272);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_get_mirroring_request_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 20) {
        VALIDATOR_LOG("Class of_bsn_get_mirroring_request.  Len %d too small, < %d", len, 20);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_get_mirroring_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 20) {
        VALIDATOR_LOG("Class of_bsn_get_mirroring_reply.  Len %d too small, < %d", len, 20);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_get_interfaces_request_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_bsn_get_interfaces_request.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_get_interfaces_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_bsn_get_interfaces_reply.  Len %d too small, < %d", len, 16);
        return -1;
    }


    {    int interfaces_len = len - 16;


        if (of_list_bsn_interface_OF_VERSION_1_3_validate(buf + 16, interfaces_len) < 0) {
            return -1;
        }
    }

    return 0;
}

static inline int
of_bsn_flow_idle_enable_set_request_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 20) {
        VALIDATOR_LOG("Class of_bsn_flow_idle_enable_set_request.  Len %d too small, < %d", len, 20);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_flow_idle_enable_set_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 24) {
        VALIDATOR_LOG("Class of_bsn_flow_idle_enable_set_reply.  Len %d too small, < %d", len, 24);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_flow_idle_enable_get_request_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_bsn_flow_idle_enable_get_request.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_flow_idle_enable_get_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 20) {
        VALIDATOR_LOG("Class of_bsn_flow_idle_enable_get_reply.  Len %d too small, < %d", len, 20);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_flow_idle_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 40) {
        VALIDATOR_LOG("Class of_bsn_flow_idle.  Len %d too small, < %d", len, 40);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_bw_enable_set_request_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 20) {
        VALIDATOR_LOG("Class of_bsn_bw_enable_set_request.  Len %d too small, < %d", len, 20);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_bw_enable_set_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 24) {
        VALIDATOR_LOG("Class of_bsn_bw_enable_set_reply.  Len %d too small, < %d", len, 24);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_bw_enable_get_request_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_bsn_bw_enable_get_request.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_bw_enable_get_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 20) {
        VALIDATOR_LOG("Class of_bsn_bw_enable_get_reply.  Len %d too small, < %d", len, 20);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_bw_clear_data_request_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 16) {
        VALIDATOR_LOG("Class of_bsn_bw_clear_data_request.  Len %d too small, < %d", len, 16);
        return -1;
    }

    return 0;
}

static inline int
of_bsn_bw_clear_data_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 20) {
        VALIDATOR_LOG("Class of_bsn_bw_clear_data_reply.  Len %d too small, < %d", len, 20);
        return -1;
    }

    return 0;
}

static inline int
of_barrier_request_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_barrier_request.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_barrier_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 8) {
        VALIDATOR_LOG("Class of_barrier_reply.  Len %d too small, < %d", len, 8);
        return -1;
    }

    return 0;
}

static inline int
of_bad_request_error_msg_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_bad_request_error_msg.  Len %d too small, < %d", len, 12);
        return -1;
    }

    return 0;
}

static inline int
of_bad_match_error_msg_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_bad_match_error_msg.  Len %d too small, < %d", len, 12);
        return -1;
    }

    return 0;
}

static inline int
of_bad_instruction_error_msg_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_bad_instruction_error_msg.  Len %d too small, < %d", len, 12);
        return -1;
    }

    return 0;
}

static inline int
of_bad_action_error_msg_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 12) {
        VALIDATOR_LOG("Class of_bad_action_error_msg.  Len %d too small, < %d", len, 12);
        return -1;
    }

    return 0;
}

static inline int
of_async_set_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 32) {
        VALIDATOR_LOG("Class of_async_set.  Len %d too small, < %d", len, 32);
        return -1;
    }

    return 0;
}

static inline int
of_async_get_request_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 32) {
        VALIDATOR_LOG("Class of_async_get_request.  Len %d too small, < %d", len, 32);
        return -1;
    }

    return 0;
}

static inline int
of_async_get_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 32) {
        VALIDATOR_LOG("Class of_async_get_reply.  Len %d too small, < %d", len, 32);
        return -1;
    }

    return 0;
}

static inline int
of_aggregate_stats_request_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 56) {
        VALIDATOR_LOG("Class of_aggregate_stats_request.  Len %d too small, < %d", len, 56);
        return -1;
    }

    return 0;
}

static inline int
of_aggregate_stats_reply_OF_VERSION_1_3_validate(uint8_t *buf, int len)
{
    if (len < 40) {
        VALIDATOR_LOG("Class of_aggregate_stats_reply.  Len %d too small, < %d", len, 40);
        return -1;
    }

    return 0;
}

int
of_validate_message_OF_VERSION_1_3(of_message_t msg, int len)
{
    of_object_id_t object_id = of_message_to_object_id(msg, len);
    uint8_t *buf = OF_MESSAGE_TO_BUFFER(msg);
    switch (object_id) {
    case OF_TABLE_STATS_REQUEST:
        return of_table_stats_request_OF_VERSION_1_3_validate(buf, len);
    case OF_TABLE_STATS_REPLY:
        return of_table_stats_reply_OF_VERSION_1_3_validate(buf, len);
    case OF_TABLE_MOD_FAILED_ERROR_MSG:
        return of_table_mod_failed_error_msg_OF_VERSION_1_3_validate(buf, len);
    case OF_TABLE_MOD:
        return of_table_mod_OF_VERSION_1_3_validate(buf, len);
    case OF_TABLE_FEATURES_STATS_REQUEST:
        return of_table_features_stats_request_OF_VERSION_1_3_validate(buf, len);
    case OF_TABLE_FEATURES_STATS_REPLY:
        return of_table_features_stats_reply_OF_VERSION_1_3_validate(buf, len);
    case OF_TABLE_FEATURES_FAILED_ERROR_MSG:
        return of_table_features_failed_error_msg_OF_VERSION_1_3_validate(buf, len);
    case OF_SWITCH_CONFIG_FAILED_ERROR_MSG:
        return of_switch_config_failed_error_msg_OF_VERSION_1_3_validate(buf, len);
    case OF_STATS_REQUEST:
        return of_stats_request_OF_VERSION_1_3_validate(buf, len);
    case OF_STATS_REPLY:
        return of_stats_reply_OF_VERSION_1_3_validate(buf, len);
    case OF_SET_CONFIG:
        return of_set_config_OF_VERSION_1_3_validate(buf, len);
    case OF_ROLE_REQUEST_FAILED_ERROR_MSG:
        return of_role_request_failed_error_msg_OF_VERSION_1_3_validate(buf, len);
    case OF_ROLE_REQUEST:
        return of_role_request_OF_VERSION_1_3_validate(buf, len);
    case OF_ROLE_REPLY:
        return of_role_reply_OF_VERSION_1_3_validate(buf, len);
    case OF_QUEUE_STATS_REQUEST:
        return of_queue_stats_request_OF_VERSION_1_3_validate(buf, len);
    case OF_QUEUE_STATS_REPLY:
        return of_queue_stats_reply_OF_VERSION_1_3_validate(buf, len);
    case OF_QUEUE_OP_FAILED_ERROR_MSG:
        return of_queue_op_failed_error_msg_OF_VERSION_1_3_validate(buf, len);
    case OF_QUEUE_GET_CONFIG_REQUEST:
        return of_queue_get_config_request_OF_VERSION_1_3_validate(buf, len);
    case OF_QUEUE_GET_CONFIG_REPLY:
        return of_queue_get_config_reply_OF_VERSION_1_3_validate(buf, len);
    case OF_PORT_STATUS:
        return of_port_status_OF_VERSION_1_3_validate(buf, len);
    case OF_PORT_STATS_REQUEST:
        return of_port_stats_request_OF_VERSION_1_3_validate(buf, len);
    case OF_PORT_STATS_REPLY:
        return of_port_stats_reply_OF_VERSION_1_3_validate(buf, len);
    case OF_PORT_MOD_FAILED_ERROR_MSG:
        return of_port_mod_failed_error_msg_OF_VERSION_1_3_validate(buf, len);
    case OF_PORT_MOD:
        return of_port_mod_OF_VERSION_1_3_validate(buf, len);
    case OF_PORT_DESC_STATS_REQUEST:
        return of_port_desc_stats_request_OF_VERSION_1_3_validate(buf, len);
    case OF_PORT_DESC_STATS_REPLY:
        return of_port_desc_stats_reply_OF_VERSION_1_3_validate(buf, len);
    case OF_PACKET_OUT:
        return of_packet_out_OF_VERSION_1_3_validate(buf, len);
    case OF_PACKET_IN:
        return of_packet_in_OF_VERSION_1_3_validate(buf, len);
    case OF_NICIRA_HEADER:
        return of_nicira_header_OF_VERSION_1_3_validate(buf, len);
    case OF_METER_STATS_REQUEST:
        return of_meter_stats_request_OF_VERSION_1_3_validate(buf, len);
    case OF_METER_STATS_REPLY:
        return of_meter_stats_reply_OF_VERSION_1_3_validate(buf, len);
    case OF_METER_MOD_FAILED_ERROR_MSG:
        return of_meter_mod_failed_error_msg_OF_VERSION_1_3_validate(buf, len);
    case OF_METER_MOD:
        return of_meter_mod_OF_VERSION_1_3_validate(buf, len);
    case OF_METER_FEATURES_STATS_REQUEST:
        return of_meter_features_stats_request_OF_VERSION_1_3_validate(buf, len);
    case OF_METER_FEATURES_STATS_REPLY:
        return of_meter_features_stats_reply_OF_VERSION_1_3_validate(buf, len);
    case OF_METER_CONFIG_STATS_REQUEST:
        return of_meter_config_stats_request_OF_VERSION_1_3_validate(buf, len);
    case OF_METER_CONFIG_STATS_REPLY:
        return of_meter_config_stats_reply_OF_VERSION_1_3_validate(buf, len);
    case OF_HELLO_FAILED_ERROR_MSG:
        return of_hello_failed_error_msg_OF_VERSION_1_3_validate(buf, len);
    case OF_HELLO:
        return of_hello_OF_VERSION_1_3_validate(buf, len);
    case OF_GROUP_STATS_REQUEST:
        return of_group_stats_request_OF_VERSION_1_3_validate(buf, len);
    case OF_GROUP_STATS_REPLY:
        return of_group_stats_reply_OF_VERSION_1_3_validate(buf, len);
    case OF_GROUP_MODIFY:
        return of_group_modify_OF_VERSION_1_3_validate(buf, len);
    case OF_GROUP_MOD_FAILED_ERROR_MSG:
        return of_group_mod_failed_error_msg_OF_VERSION_1_3_validate(buf, len);
    case OF_GROUP_MOD:
        return of_group_mod_OF_VERSION_1_3_validate(buf, len);
    case OF_GROUP_FEATURES_STATS_REQUEST:
        return of_group_features_stats_request_OF_VERSION_1_3_validate(buf, len);
    case OF_GROUP_FEATURES_STATS_REPLY:
        return of_group_features_stats_reply_OF_VERSION_1_3_validate(buf, len);
    case OF_GROUP_DESC_STATS_REQUEST:
        return of_group_desc_stats_request_OF_VERSION_1_3_validate(buf, len);
    case OF_GROUP_DESC_STATS_REPLY:
        return of_group_desc_stats_reply_OF_VERSION_1_3_validate(buf, len);
    case OF_GROUP_DELETE:
        return of_group_delete_OF_VERSION_1_3_validate(buf, len);
    case OF_GROUP_ADD:
        return of_group_add_OF_VERSION_1_3_validate(buf, len);
    case OF_GET_CONFIG_REQUEST:
        return of_get_config_request_OF_VERSION_1_3_validate(buf, len);
    case OF_GET_CONFIG_REPLY:
        return of_get_config_reply_OF_VERSION_1_3_validate(buf, len);
    case OF_FLOW_STATS_REQUEST:
        return of_flow_stats_request_OF_VERSION_1_3_validate(buf, len);
    case OF_FLOW_STATS_REPLY:
        return of_flow_stats_reply_OF_VERSION_1_3_validate(buf, len);
    case OF_FLOW_REMOVED:
        return of_flow_removed_OF_VERSION_1_3_validate(buf, len);
    case OF_FLOW_MODIFY_STRICT:
        return of_flow_modify_strict_OF_VERSION_1_3_validate(buf, len);
    case OF_FLOW_MODIFY:
        return of_flow_modify_OF_VERSION_1_3_validate(buf, len);
    case OF_FLOW_MOD_FAILED_ERROR_MSG:
        return of_flow_mod_failed_error_msg_OF_VERSION_1_3_validate(buf, len);
    case OF_FLOW_MOD:
        return of_flow_mod_OF_VERSION_1_3_validate(buf, len);
    case OF_FLOW_DELETE_STRICT:
        return of_flow_delete_strict_OF_VERSION_1_3_validate(buf, len);
    case OF_FLOW_DELETE:
        return of_flow_delete_OF_VERSION_1_3_validate(buf, len);
    case OF_FLOW_ADD:
        return of_flow_add_OF_VERSION_1_3_validate(buf, len);
    case OF_FEATURES_REQUEST:
        return of_features_request_OF_VERSION_1_3_validate(buf, len);
    case OF_FEATURES_REPLY:
        return of_features_reply_OF_VERSION_1_3_validate(buf, len);
    case OF_EXPERIMENTER_STATS_REQUEST:
        return of_experimenter_stats_request_OF_VERSION_1_3_validate(buf, len);
    case OF_EXPERIMENTER_STATS_REPLY:
        return of_experimenter_stats_reply_OF_VERSION_1_3_validate(buf, len);
    case OF_EXPERIMENTER_ERROR_MSG:
        return of_experimenter_error_msg_OF_VERSION_1_3_validate(buf, len);
    case OF_EXPERIMENTER:
        return of_experimenter_OF_VERSION_1_3_validate(buf, len);
    case OF_ERROR_MSG:
        return of_error_msg_OF_VERSION_1_3_validate(buf, len);
    case OF_ECHO_REQUEST:
        return of_echo_request_OF_VERSION_1_3_validate(buf, len);
    case OF_ECHO_REPLY:
        return of_echo_reply_OF_VERSION_1_3_validate(buf, len);
    case OF_DESC_STATS_REQUEST:
        return of_desc_stats_request_OF_VERSION_1_3_validate(buf, len);
    case OF_DESC_STATS_REPLY:
        return of_desc_stats_reply_OF_VERSION_1_3_validate(buf, len);
    case OF_BSN_VLAN_COUNTER_STATS_REQUEST:
        return of_bsn_vlan_counter_stats_request_OF_VERSION_1_3_validate(buf, len);
    case OF_BSN_VLAN_COUNTER_STATS_REPLY:
        return of_bsn_vlan_counter_stats_reply_OF_VERSION_1_3_validate(buf, len);
    case OF_BSN_VIRTUAL_PORT_REMOVE_REQUEST:
        return of_bsn_virtual_port_remove_request_OF_VERSION_1_3_validate(buf, len);
    case OF_BSN_VIRTUAL_PORT_REMOVE_REPLY:
        return of_bsn_virtual_port_remove_reply_OF_VERSION_1_3_validate(buf, len);
    case OF_BSN_VIRTUAL_PORT_CREATE_REQUEST:
        return of_bsn_virtual_port_create_request_OF_VERSION_1_3_validate(buf, len);
    case OF_BSN_VIRTUAL_PORT_CREATE_REPLY:
        return of_bsn_virtual_port_create_reply_OF_VERSION_1_3_validate(buf, len);
    case OF_BSN_TIME_REQUEST:
        return of_bsn_time_request_OF_VERSION_1_3_validate(buf, len);
    case OF_BSN_TIME_REPLY:
        return of_bsn_time_reply_OF_VERSION_1_3_validate(buf, len);
    case OF_BSN_SWITCH_PIPELINE_STATS_REQUEST:
        return of_bsn_switch_pipeline_stats_request_OF_VERSION_1_3_validate(buf, len);
    case OF_BSN_SWITCH_PIPELINE_STATS_REPLY:
        return of_bsn_switch_pipeline_stats_reply_OF_VERSION_1_3_validate(buf, len);
    case OF_BSN_STATS_REQUEST:
        return of_bsn_stats_request_OF_VERSION_1_3_validate(buf, len);
    case OF_BSN_STATS_REPLY:
        return of_bsn_stats_reply_OF_VERSION_1_3_validate(buf, len);
    case OF_BSN_SET_SWITCH_PIPELINE_REQUEST:
        return of_bsn_set_switch_pipeline_request_OF_VERSION_1_3_validate(buf, len);
    case OF_BSN_SET_SWITCH_PIPELINE_REPLY:
        return of_bsn_set_switch_pipeline_reply_OF_VERSION_1_3_validate(buf, len);
    case OF_BSN_SET_PKTIN_SUPPRESSION_REQUEST:
        return of_bsn_set_pktin_suppression_request_OF_VERSION_1_3_validate(buf, len);
    case OF_BSN_SET_PKTIN_SUPPRESSION_REPLY:
        return of_bsn_set_pktin_suppression_reply_OF_VERSION_1_3_validate(buf, len);
    case OF_BSN_SET_MIRRORING:
        return of_bsn_set_mirroring_OF_VERSION_1_3_validate(buf, len);
    case OF_BSN_SET_LACP_REQUEST:
        return of_bsn_set_lacp_request_OF_VERSION_1_3_validate(buf, len);
    case OF_BSN_SET_LACP_REPLY:
        return of_bsn_set_lacp_reply_OF_VERSION_1_3_validate(buf, len);
    case OF_BSN_PORT_COUNTER_STATS_REQUEST:
        return of_bsn_port_counter_stats_request_OF_VERSION_1_3_validate(buf, len);
    case OF_BSN_PORT_COUNTER_STATS_REPLY:
        return of_bsn_port_counter_stats_reply_OF_VERSION_1_3_validate(buf, len);
    case OF_BSN_PDU_TX_REQUEST:
        return of_bsn_pdu_tx_request_OF_VERSION_1_3_validate(buf, len);
    case OF_BSN_PDU_TX_REPLY:
        return of_bsn_pdu_tx_reply_OF_VERSION_1_3_validate(buf, len);
    case OF_BSN_PDU_RX_TIMEOUT:
        return of_bsn_pdu_rx_timeout_OF_VERSION_1_3_validate(buf, len);
    case OF_BSN_PDU_RX_REQUEST:
        return of_bsn_pdu_rx_request_OF_VERSION_1_3_validate(buf, len);
    case OF_BSN_PDU_RX_REPLY:
        return of_bsn_pdu_rx_reply_OF_VERSION_1_3_validate(buf, len);
    case OF_BSN_LACP_STATS_REQUEST:
        return of_bsn_lacp_stats_request_OF_VERSION_1_3_validate(buf, len);
    case OF_BSN_LACP_STATS_REPLY:
        return of_bsn_lacp_stats_reply_OF_VERSION_1_3_validate(buf, len);
    case OF_BSN_LACP_CONVERGENCE_NOTIF:
        return of_bsn_lacp_convergence_notif_OF_VERSION_1_3_validate(buf, len);
    case OF_BSN_HEADER:
        return of_bsn_header_OF_VERSION_1_3_validate(buf, len);
    case OF_BSN_GET_SWITCH_PIPELINE_REQUEST:
        return of_bsn_get_switch_pipeline_request_OF_VERSION_1_3_validate(buf, len);
    case OF_BSN_GET_SWITCH_PIPELINE_REPLY:
        return of_bsn_get_switch_pipeline_reply_OF_VERSION_1_3_validate(buf, len);
    case OF_BSN_GET_MIRRORING_REQUEST:
        return of_bsn_get_mirroring_request_OF_VERSION_1_3_validate(buf, len);
    case OF_BSN_GET_MIRRORING_REPLY:
        return of_bsn_get_mirroring_reply_OF_VERSION_1_3_validate(buf, len);
    case OF_BSN_GET_INTERFACES_REQUEST:
        return of_bsn_get_interfaces_request_OF_VERSION_1_3_validate(buf, len);
    case OF_BSN_GET_INTERFACES_REPLY:
        return of_bsn_get_interfaces_reply_OF_VERSION_1_3_validate(buf, len);
    case OF_BSN_FLOW_IDLE_ENABLE_SET_REQUEST:
        return of_bsn_flow_idle_enable_set_request_OF_VERSION_1_3_validate(buf, len);
    case OF_BSN_FLOW_IDLE_ENABLE_SET_REPLY:
        return of_bsn_flow_idle_enable_set_reply_OF_VERSION_1_3_validate(buf, len);
    case OF_BSN_FLOW_IDLE_ENABLE_GET_REQUEST:
        return of_bsn_flow_idle_enable_get_request_OF_VERSION_1_3_validate(buf, len);
    case OF_BSN_FLOW_IDLE_ENABLE_GET_REPLY:
        return of_bsn_flow_idle_enable_get_reply_OF_VERSION_1_3_validate(buf, len);
    case OF_BSN_FLOW_IDLE:
        return of_bsn_flow_idle_OF_VERSION_1_3_validate(buf, len);
    case OF_BSN_BW_ENABLE_SET_REQUEST:
        return of_bsn_bw_enable_set_request_OF_VERSION_1_3_validate(buf, len);
    case OF_BSN_BW_ENABLE_SET_REPLY:
        return of_bsn_bw_enable_set_reply_OF_VERSION_1_3_validate(buf, len);
    case OF_BSN_BW_ENABLE_GET_REQUEST:
        return of_bsn_bw_enable_get_request_OF_VERSION_1_3_validate(buf, len);
    case OF_BSN_BW_ENABLE_GET_REPLY:
        return of_bsn_bw_enable_get_reply_OF_VERSION_1_3_validate(buf, len);
    case OF_BSN_BW_CLEAR_DATA_REQUEST:
        return of_bsn_bw_clear_data_request_OF_VERSION_1_3_validate(buf, len);
    case OF_BSN_BW_CLEAR_DATA_REPLY:
        return of_bsn_bw_clear_data_reply_OF_VERSION_1_3_validate(buf, len);
    case OF_BARRIER_REQUEST:
        return of_barrier_request_OF_VERSION_1_3_validate(buf, len);
    case OF_BARRIER_REPLY:
        return of_barrier_reply_OF_VERSION_1_3_validate(buf, len);
    case OF_BAD_REQUEST_ERROR_MSG:
        return of_bad_request_error_msg_OF_VERSION_1_3_validate(buf, len);
    case OF_BAD_MATCH_ERROR_MSG:
        return of_bad_match_error_msg_OF_VERSION_1_3_validate(buf, len);
    case OF_BAD_INSTRUCTION_ERROR_MSG:
        return of_bad_instruction_error_msg_OF_VERSION_1_3_validate(buf, len);
    case OF_BAD_ACTION_ERROR_MSG:
        return of_bad_action_error_msg_OF_VERSION_1_3_validate(buf, len);
    case OF_ASYNC_SET:
        return of_async_set_OF_VERSION_1_3_validate(buf, len);
    case OF_ASYNC_GET_REQUEST:
        return of_async_get_request_OF_VERSION_1_3_validate(buf, len);
    case OF_ASYNC_GET_REPLY:
        return of_async_get_reply_OF_VERSION_1_3_validate(buf, len);
    case OF_AGGREGATE_STATS_REQUEST:
        return of_aggregate_stats_request_OF_VERSION_1_3_validate(buf, len);
    case OF_AGGREGATE_STATS_REPLY:
        return of_aggregate_stats_reply_OF_VERSION_1_3_validate(buf, len);
    default:
        VALIDATOR_LOG("of_aggregate_stats_reply: could not map OF_AGGREGATE_STATS_REPLY");
        return -1;
    }
}

int
of_validate_message(of_message_t msg, int len)
{
    of_version_t version;
    if (len < OF_MESSAGE_MIN_LENGTH ||
        len != of_message_length_get(msg)) {
        VALIDATOR_LOG("message length %d != %d", len,
                      of_message_length_get(msg));
        return -1;
    }

    version = of_message_version_get(msg);
    switch (version) {
    case OF_VERSION_1_0:
        return of_validate_message_OF_VERSION_1_0(msg, len);
    case OF_VERSION_1_1:
        return of_validate_message_OF_VERSION_1_1(msg, len);
    case OF_VERSION_1_2:
        return of_validate_message_OF_VERSION_1_2(msg, len);
    case OF_VERSION_1_3:
        return of_validate_message_OF_VERSION_1_3(msg, len);
    default:
        VALIDATOR_LOG("Bad version %d", OF_VERSION_1_3);
        return -1;
    }
}
