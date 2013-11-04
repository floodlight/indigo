/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */
/*
 * Duplication functions for all OF objects
 *
 * AUTOMATICALLY GENERATED FILE.  Edits will be lost on regen.
 *
 * These are test functions for exercising accessors.  You can call
 * of_object_dup for an efficient duplication.
 */

#define DISABLE_WARN_UNUSED_RESULT
#include "loci_log.h"
#include <locitest/of_dup.h>


/* Special try macro for duplicating */
#define _TRY_FREE(op, obj, rv) do { \
        int _rv;                                                             \
        if ((_rv = (op)) < 0) {                                              \
            LOCI_LOG_ERROR("ERROR %d at %s:%d\n", _rv, __FILE__, __LINE__);    \
            of_object_delete((of_object_t *)(obj));                          \
            return (rv);                                                     \
        }                                                                    \
    } while (0)

/**
 * Duplicate an object of type of_aggregate_stats_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_aggregate_stats_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_aggregate_stats_reply_t *
of_aggregate_stats_reply_OF_VERSION_1_0_dup(
    of_aggregate_stats_reply_t *src)
{
    of_aggregate_stats_reply_t *dst;
    uint32_t val32;
    uint16_t val16;
    uint64_t val64;

    if ((dst = of_aggregate_stats_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_aggregate_stats_reply_xid_get(src, &val32);
    of_aggregate_stats_reply_xid_set(dst, val32);

    of_aggregate_stats_reply_flags_get(src, &val16);
    of_aggregate_stats_reply_flags_set(dst, val16);

    of_aggregate_stats_reply_packet_count_get(src, &val64);
    of_aggregate_stats_reply_packet_count_set(dst, val64);

    of_aggregate_stats_reply_byte_count_get(src, &val64);
    of_aggregate_stats_reply_byte_count_set(dst, val64);

    of_aggregate_stats_reply_flow_count_get(src, &val32);
    of_aggregate_stats_reply_flow_count_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_aggregate_stats_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_aggregate_stats_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_aggregate_stats_request_t *
of_aggregate_stats_request_OF_VERSION_1_0_dup(
    of_aggregate_stats_request_t *src)
{
    of_aggregate_stats_request_t *dst;
    uint32_t val32;
    uint16_t val16;
    of_match_t match;
    uint8_t val8;
    of_port_no_t port_no;

    if ((dst = of_aggregate_stats_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_aggregate_stats_request_xid_get(src, &val32);
    of_aggregate_stats_request_xid_set(dst, val32);

    of_aggregate_stats_request_flags_get(src, &val16);
    of_aggregate_stats_request_flags_set(dst, val16);

    of_aggregate_stats_request_match_get(src, &match);
    of_aggregate_stats_request_match_set(dst, &match);

    of_aggregate_stats_request_table_id_get(src, &val8);
    of_aggregate_stats_request_table_id_set(dst, val8);

    of_aggregate_stats_request_out_port_get(src, &port_no);
    of_aggregate_stats_request_out_port_set(dst, port_no);

    return dst;
}

/**
 * Duplicate an object of type of_bad_action_error_msg
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bad_action_error_msg.
 *
 * The caller is responsible for deleting the returned value
 */
of_bad_action_error_msg_t *
of_bad_action_error_msg_OF_VERSION_1_0_dup(
    of_bad_action_error_msg_t *src)
{
    of_bad_action_error_msg_t *dst;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    if ((dst = of_bad_action_error_msg_new(src->version)) == NULL) {
        return NULL;
    }

    of_bad_action_error_msg_xid_get(src, &val32);
    of_bad_action_error_msg_xid_set(dst, val32);

    of_bad_action_error_msg_code_get(src, &val16);
    of_bad_action_error_msg_code_set(dst, val16);

    of_bad_action_error_msg_data_get(src, &octets);
    of_bad_action_error_msg_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_bad_request_error_msg
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bad_request_error_msg.
 *
 * The caller is responsible for deleting the returned value
 */
of_bad_request_error_msg_t *
of_bad_request_error_msg_OF_VERSION_1_0_dup(
    of_bad_request_error_msg_t *src)
{
    of_bad_request_error_msg_t *dst;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    if ((dst = of_bad_request_error_msg_new(src->version)) == NULL) {
        return NULL;
    }

    of_bad_request_error_msg_xid_get(src, &val32);
    of_bad_request_error_msg_xid_set(dst, val32);

    of_bad_request_error_msg_code_get(src, &val16);
    of_bad_request_error_msg_code_set(dst, val16);

    of_bad_request_error_msg_data_get(src, &octets);
    of_bad_request_error_msg_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_barrier_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_barrier_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_barrier_reply_t *
of_barrier_reply_OF_VERSION_1_0_dup(
    of_barrier_reply_t *src)
{
    of_barrier_reply_t *dst;
    uint32_t val32;

    if ((dst = of_barrier_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_barrier_reply_xid_get(src, &val32);
    of_barrier_reply_xid_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_barrier_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_barrier_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_barrier_request_t *
of_barrier_request_OF_VERSION_1_0_dup(
    of_barrier_request_t *src)
{
    of_barrier_request_t *dst;
    uint32_t val32;

    if ((dst = of_barrier_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_barrier_request_xid_get(src, &val32);
    of_barrier_request_xid_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_bw_clear_data_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_bw_clear_data_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_bw_clear_data_reply_t *
of_bsn_bw_clear_data_reply_OF_VERSION_1_0_dup(
    of_bsn_bw_clear_data_reply_t *src)
{
    of_bsn_bw_clear_data_reply_t *dst;
    uint32_t val32;

    if ((dst = of_bsn_bw_clear_data_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_bw_clear_data_reply_xid_get(src, &val32);
    of_bsn_bw_clear_data_reply_xid_set(dst, val32);

    of_bsn_bw_clear_data_reply_experimenter_get(src, &val32);
    of_bsn_bw_clear_data_reply_experimenter_set(dst, val32);

    of_bsn_bw_clear_data_reply_subtype_get(src, &val32);
    of_bsn_bw_clear_data_reply_subtype_set(dst, val32);

    of_bsn_bw_clear_data_reply_status_get(src, &val32);
    of_bsn_bw_clear_data_reply_status_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_bw_clear_data_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_bw_clear_data_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_bw_clear_data_request_t *
of_bsn_bw_clear_data_request_OF_VERSION_1_0_dup(
    of_bsn_bw_clear_data_request_t *src)
{
    of_bsn_bw_clear_data_request_t *dst;
    uint32_t val32;

    if ((dst = of_bsn_bw_clear_data_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_bw_clear_data_request_xid_get(src, &val32);
    of_bsn_bw_clear_data_request_xid_set(dst, val32);

    of_bsn_bw_clear_data_request_experimenter_get(src, &val32);
    of_bsn_bw_clear_data_request_experimenter_set(dst, val32);

    of_bsn_bw_clear_data_request_subtype_get(src, &val32);
    of_bsn_bw_clear_data_request_subtype_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_bw_enable_get_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_bw_enable_get_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_bw_enable_get_reply_t *
of_bsn_bw_enable_get_reply_OF_VERSION_1_0_dup(
    of_bsn_bw_enable_get_reply_t *src)
{
    of_bsn_bw_enable_get_reply_t *dst;
    uint32_t val32;

    if ((dst = of_bsn_bw_enable_get_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_bw_enable_get_reply_xid_get(src, &val32);
    of_bsn_bw_enable_get_reply_xid_set(dst, val32);

    of_bsn_bw_enable_get_reply_experimenter_get(src, &val32);
    of_bsn_bw_enable_get_reply_experimenter_set(dst, val32);

    of_bsn_bw_enable_get_reply_subtype_get(src, &val32);
    of_bsn_bw_enable_get_reply_subtype_set(dst, val32);

    of_bsn_bw_enable_get_reply_enabled_get(src, &val32);
    of_bsn_bw_enable_get_reply_enabled_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_bw_enable_get_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_bw_enable_get_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_bw_enable_get_request_t *
of_bsn_bw_enable_get_request_OF_VERSION_1_0_dup(
    of_bsn_bw_enable_get_request_t *src)
{
    of_bsn_bw_enable_get_request_t *dst;
    uint32_t val32;

    if ((dst = of_bsn_bw_enable_get_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_bw_enable_get_request_xid_get(src, &val32);
    of_bsn_bw_enable_get_request_xid_set(dst, val32);

    of_bsn_bw_enable_get_request_experimenter_get(src, &val32);
    of_bsn_bw_enable_get_request_experimenter_set(dst, val32);

    of_bsn_bw_enable_get_request_subtype_get(src, &val32);
    of_bsn_bw_enable_get_request_subtype_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_bw_enable_set_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_bw_enable_set_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_bw_enable_set_reply_t *
of_bsn_bw_enable_set_reply_OF_VERSION_1_0_dup(
    of_bsn_bw_enable_set_reply_t *src)
{
    of_bsn_bw_enable_set_reply_t *dst;
    uint32_t val32;

    if ((dst = of_bsn_bw_enable_set_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_bw_enable_set_reply_xid_get(src, &val32);
    of_bsn_bw_enable_set_reply_xid_set(dst, val32);

    of_bsn_bw_enable_set_reply_experimenter_get(src, &val32);
    of_bsn_bw_enable_set_reply_experimenter_set(dst, val32);

    of_bsn_bw_enable_set_reply_subtype_get(src, &val32);
    of_bsn_bw_enable_set_reply_subtype_set(dst, val32);

    of_bsn_bw_enable_set_reply_enable_get(src, &val32);
    of_bsn_bw_enable_set_reply_enable_set(dst, val32);

    of_bsn_bw_enable_set_reply_status_get(src, &val32);
    of_bsn_bw_enable_set_reply_status_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_bw_enable_set_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_bw_enable_set_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_bw_enable_set_request_t *
of_bsn_bw_enable_set_request_OF_VERSION_1_0_dup(
    of_bsn_bw_enable_set_request_t *src)
{
    of_bsn_bw_enable_set_request_t *dst;
    uint32_t val32;

    if ((dst = of_bsn_bw_enable_set_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_bw_enable_set_request_xid_get(src, &val32);
    of_bsn_bw_enable_set_request_xid_set(dst, val32);

    of_bsn_bw_enable_set_request_experimenter_get(src, &val32);
    of_bsn_bw_enable_set_request_experimenter_set(dst, val32);

    of_bsn_bw_enable_set_request_subtype_get(src, &val32);
    of_bsn_bw_enable_set_request_subtype_set(dst, val32);

    of_bsn_bw_enable_set_request_enable_get(src, &val32);
    of_bsn_bw_enable_set_request_enable_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_get_interfaces_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_get_interfaces_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_get_interfaces_reply_t *
of_bsn_get_interfaces_reply_OF_VERSION_1_0_dup(
    of_bsn_get_interfaces_reply_t *src)
{
    of_bsn_get_interfaces_reply_t *dst;
    uint32_t val32;

    of_list_bsn_interface_t src_list;
    of_list_bsn_interface_t *dst_list;

    if ((dst = of_bsn_get_interfaces_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_get_interfaces_reply_xid_get(src, &val32);
    of_bsn_get_interfaces_reply_xid_set(dst, val32);

    of_bsn_get_interfaces_reply_experimenter_get(src, &val32);
    of_bsn_get_interfaces_reply_experimenter_set(dst, val32);

    of_bsn_get_interfaces_reply_subtype_get(src, &val32);
    of_bsn_get_interfaces_reply_subtype_set(dst, val32);

    of_bsn_get_interfaces_reply_interfaces_bind(
        src, &src_list);
    dst_list = of_list_bsn_interface_OF_VERSION_1_0_dup(&src_list);
    if (dst_list == NULL) {
        of_bsn_get_interfaces_reply_delete(dst);
        return NULL;
    }
    of_bsn_get_interfaces_reply_interfaces_set(dst, dst_list);
    of_list_bsn_interface_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_get_interfaces_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_get_interfaces_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_get_interfaces_request_t *
of_bsn_get_interfaces_request_OF_VERSION_1_0_dup(
    of_bsn_get_interfaces_request_t *src)
{
    of_bsn_get_interfaces_request_t *dst;
    uint32_t val32;

    if ((dst = of_bsn_get_interfaces_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_get_interfaces_request_xid_get(src, &val32);
    of_bsn_get_interfaces_request_xid_set(dst, val32);

    of_bsn_get_interfaces_request_experimenter_get(src, &val32);
    of_bsn_get_interfaces_request_experimenter_set(dst, val32);

    of_bsn_get_interfaces_request_subtype_get(src, &val32);
    of_bsn_get_interfaces_request_subtype_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_get_ip_mask_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_get_ip_mask_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_get_ip_mask_reply_t *
of_bsn_get_ip_mask_reply_OF_VERSION_1_0_dup(
    of_bsn_get_ip_mask_reply_t *src)
{
    of_bsn_get_ip_mask_reply_t *dst;
    uint32_t val32;
    uint8_t val8;

    if ((dst = of_bsn_get_ip_mask_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_get_ip_mask_reply_xid_get(src, &val32);
    of_bsn_get_ip_mask_reply_xid_set(dst, val32);

    of_bsn_get_ip_mask_reply_experimenter_get(src, &val32);
    of_bsn_get_ip_mask_reply_experimenter_set(dst, val32);

    of_bsn_get_ip_mask_reply_subtype_get(src, &val32);
    of_bsn_get_ip_mask_reply_subtype_set(dst, val32);

    of_bsn_get_ip_mask_reply_index_get(src, &val8);
    of_bsn_get_ip_mask_reply_index_set(dst, val8);

    of_bsn_get_ip_mask_reply_mask_get(src, &val32);
    of_bsn_get_ip_mask_reply_mask_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_get_ip_mask_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_get_ip_mask_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_get_ip_mask_request_t *
of_bsn_get_ip_mask_request_OF_VERSION_1_0_dup(
    of_bsn_get_ip_mask_request_t *src)
{
    of_bsn_get_ip_mask_request_t *dst;
    uint32_t val32;
    uint8_t val8;

    if ((dst = of_bsn_get_ip_mask_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_get_ip_mask_request_xid_get(src, &val32);
    of_bsn_get_ip_mask_request_xid_set(dst, val32);

    of_bsn_get_ip_mask_request_experimenter_get(src, &val32);
    of_bsn_get_ip_mask_request_experimenter_set(dst, val32);

    of_bsn_get_ip_mask_request_subtype_get(src, &val32);
    of_bsn_get_ip_mask_request_subtype_set(dst, val32);

    of_bsn_get_ip_mask_request_index_get(src, &val8);
    of_bsn_get_ip_mask_request_index_set(dst, val8);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_get_l2_table_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_get_l2_table_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_get_l2_table_reply_t *
of_bsn_get_l2_table_reply_OF_VERSION_1_0_dup(
    of_bsn_get_l2_table_reply_t *src)
{
    of_bsn_get_l2_table_reply_t *dst;
    uint32_t val32;
    uint8_t val8;
    uint16_t val16;

    if ((dst = of_bsn_get_l2_table_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_get_l2_table_reply_xid_get(src, &val32);
    of_bsn_get_l2_table_reply_xid_set(dst, val32);

    of_bsn_get_l2_table_reply_experimenter_get(src, &val32);
    of_bsn_get_l2_table_reply_experimenter_set(dst, val32);

    of_bsn_get_l2_table_reply_subtype_get(src, &val32);
    of_bsn_get_l2_table_reply_subtype_set(dst, val32);

    of_bsn_get_l2_table_reply_l2_table_enable_get(src, &val8);
    of_bsn_get_l2_table_reply_l2_table_enable_set(dst, val8);

    of_bsn_get_l2_table_reply_l2_table_priority_get(src, &val16);
    of_bsn_get_l2_table_reply_l2_table_priority_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_get_l2_table_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_get_l2_table_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_get_l2_table_request_t *
of_bsn_get_l2_table_request_OF_VERSION_1_0_dup(
    of_bsn_get_l2_table_request_t *src)
{
    of_bsn_get_l2_table_request_t *dst;
    uint32_t val32;

    if ((dst = of_bsn_get_l2_table_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_get_l2_table_request_xid_get(src, &val32);
    of_bsn_get_l2_table_request_xid_set(dst, val32);

    of_bsn_get_l2_table_request_experimenter_get(src, &val32);
    of_bsn_get_l2_table_request_experimenter_set(dst, val32);

    of_bsn_get_l2_table_request_subtype_get(src, &val32);
    of_bsn_get_l2_table_request_subtype_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_get_mirroring_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_get_mirroring_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_get_mirroring_reply_t *
of_bsn_get_mirroring_reply_OF_VERSION_1_0_dup(
    of_bsn_get_mirroring_reply_t *src)
{
    of_bsn_get_mirroring_reply_t *dst;
    uint32_t val32;
    uint8_t val8;

    if ((dst = of_bsn_get_mirroring_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_get_mirroring_reply_xid_get(src, &val32);
    of_bsn_get_mirroring_reply_xid_set(dst, val32);

    of_bsn_get_mirroring_reply_experimenter_get(src, &val32);
    of_bsn_get_mirroring_reply_experimenter_set(dst, val32);

    of_bsn_get_mirroring_reply_subtype_get(src, &val32);
    of_bsn_get_mirroring_reply_subtype_set(dst, val32);

    of_bsn_get_mirroring_reply_report_mirror_ports_get(src, &val8);
    of_bsn_get_mirroring_reply_report_mirror_ports_set(dst, val8);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_get_mirroring_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_get_mirroring_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_get_mirroring_request_t *
of_bsn_get_mirroring_request_OF_VERSION_1_0_dup(
    of_bsn_get_mirroring_request_t *src)
{
    of_bsn_get_mirroring_request_t *dst;
    uint32_t val32;
    uint8_t val8;

    if ((dst = of_bsn_get_mirroring_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_get_mirroring_request_xid_get(src, &val32);
    of_bsn_get_mirroring_request_xid_set(dst, val32);

    of_bsn_get_mirroring_request_experimenter_get(src, &val32);
    of_bsn_get_mirroring_request_experimenter_set(dst, val32);

    of_bsn_get_mirroring_request_subtype_get(src, &val32);
    of_bsn_get_mirroring_request_subtype_set(dst, val32);

    of_bsn_get_mirroring_request_report_mirror_ports_get(src, &val8);
    of_bsn_get_mirroring_request_report_mirror_ports_set(dst, val8);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_header
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_header.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_header_t *
of_bsn_header_OF_VERSION_1_0_dup(
    of_bsn_header_t *src)
{
    of_bsn_header_t *dst;
    uint32_t val32;

    if ((dst = of_bsn_header_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_header_xid_get(src, &val32);
    of_bsn_header_xid_set(dst, val32);

    of_bsn_header_experimenter_get(src, &val32);
    of_bsn_header_experimenter_set(dst, val32);

    of_bsn_header_subtype_get(src, &val32);
    of_bsn_header_subtype_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_hybrid_get_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_hybrid_get_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_hybrid_get_reply_t *
of_bsn_hybrid_get_reply_OF_VERSION_1_0_dup(
    of_bsn_hybrid_get_reply_t *src)
{
    of_bsn_hybrid_get_reply_t *dst;
    uint32_t val32;
    uint8_t val8;
    uint16_t val16;

    if ((dst = of_bsn_hybrid_get_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_hybrid_get_reply_xid_get(src, &val32);
    of_bsn_hybrid_get_reply_xid_set(dst, val32);

    of_bsn_hybrid_get_reply_experimenter_get(src, &val32);
    of_bsn_hybrid_get_reply_experimenter_set(dst, val32);

    of_bsn_hybrid_get_reply_subtype_get(src, &val32);
    of_bsn_hybrid_get_reply_subtype_set(dst, val32);

    of_bsn_hybrid_get_reply_hybrid_enable_get(src, &val8);
    of_bsn_hybrid_get_reply_hybrid_enable_set(dst, val8);

    of_bsn_hybrid_get_reply_hybrid_version_get(src, &val16);
    of_bsn_hybrid_get_reply_hybrid_version_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_hybrid_get_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_hybrid_get_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_hybrid_get_request_t *
of_bsn_hybrid_get_request_OF_VERSION_1_0_dup(
    of_bsn_hybrid_get_request_t *src)
{
    of_bsn_hybrid_get_request_t *dst;
    uint32_t val32;

    if ((dst = of_bsn_hybrid_get_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_hybrid_get_request_xid_get(src, &val32);
    of_bsn_hybrid_get_request_xid_set(dst, val32);

    of_bsn_hybrid_get_request_experimenter_get(src, &val32);
    of_bsn_hybrid_get_request_experimenter_set(dst, val32);

    of_bsn_hybrid_get_request_subtype_get(src, &val32);
    of_bsn_hybrid_get_request_subtype_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_pdu_rx_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_pdu_rx_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_pdu_rx_reply_t *
of_bsn_pdu_rx_reply_OF_VERSION_1_0_dup(
    of_bsn_pdu_rx_reply_t *src)
{
    of_bsn_pdu_rx_reply_t *dst;
    uint32_t val32;

    if ((dst = of_bsn_pdu_rx_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_pdu_rx_reply_xid_get(src, &val32);
    of_bsn_pdu_rx_reply_xid_set(dst, val32);

    of_bsn_pdu_rx_reply_experimenter_get(src, &val32);
    of_bsn_pdu_rx_reply_experimenter_set(dst, val32);

    of_bsn_pdu_rx_reply_subtype_get(src, &val32);
    of_bsn_pdu_rx_reply_subtype_set(dst, val32);

    of_bsn_pdu_rx_reply_status_get(src, &val32);
    of_bsn_pdu_rx_reply_status_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_pdu_rx_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_pdu_rx_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_pdu_rx_request_t *
of_bsn_pdu_rx_request_OF_VERSION_1_0_dup(
    of_bsn_pdu_rx_request_t *src)
{
    of_bsn_pdu_rx_request_t *dst;
    uint32_t val32;
    of_port_no_t port_no;
    uint8_t val8;
    of_octets_t octets;

    if ((dst = of_bsn_pdu_rx_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_pdu_rx_request_xid_get(src, &val32);
    of_bsn_pdu_rx_request_xid_set(dst, val32);

    of_bsn_pdu_rx_request_experimenter_get(src, &val32);
    of_bsn_pdu_rx_request_experimenter_set(dst, val32);

    of_bsn_pdu_rx_request_subtype_get(src, &val32);
    of_bsn_pdu_rx_request_subtype_set(dst, val32);

    of_bsn_pdu_rx_request_timeout_ms_get(src, &val32);
    of_bsn_pdu_rx_request_timeout_ms_set(dst, val32);

    of_bsn_pdu_rx_request_port_no_get(src, &port_no);
    of_bsn_pdu_rx_request_port_no_set(dst, port_no);

    of_bsn_pdu_rx_request_slot_num_get(src, &val8);
    of_bsn_pdu_rx_request_slot_num_set(dst, val8);

    of_bsn_pdu_rx_request_data_get(src, &octets);
    of_bsn_pdu_rx_request_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_pdu_rx_timeout
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_pdu_rx_timeout.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_pdu_rx_timeout_t *
of_bsn_pdu_rx_timeout_OF_VERSION_1_0_dup(
    of_bsn_pdu_rx_timeout_t *src)
{
    of_bsn_pdu_rx_timeout_t *dst;
    uint32_t val32;
    of_port_no_t port_no;
    uint8_t val8;

    if ((dst = of_bsn_pdu_rx_timeout_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_pdu_rx_timeout_xid_get(src, &val32);
    of_bsn_pdu_rx_timeout_xid_set(dst, val32);

    of_bsn_pdu_rx_timeout_experimenter_get(src, &val32);
    of_bsn_pdu_rx_timeout_experimenter_set(dst, val32);

    of_bsn_pdu_rx_timeout_subtype_get(src, &val32);
    of_bsn_pdu_rx_timeout_subtype_set(dst, val32);

    of_bsn_pdu_rx_timeout_port_no_get(src, &port_no);
    of_bsn_pdu_rx_timeout_port_no_set(dst, port_no);

    of_bsn_pdu_rx_timeout_slot_num_get(src, &val8);
    of_bsn_pdu_rx_timeout_slot_num_set(dst, val8);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_pdu_tx_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_pdu_tx_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_pdu_tx_reply_t *
of_bsn_pdu_tx_reply_OF_VERSION_1_0_dup(
    of_bsn_pdu_tx_reply_t *src)
{
    of_bsn_pdu_tx_reply_t *dst;
    uint32_t val32;

    if ((dst = of_bsn_pdu_tx_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_pdu_tx_reply_xid_get(src, &val32);
    of_bsn_pdu_tx_reply_xid_set(dst, val32);

    of_bsn_pdu_tx_reply_experimenter_get(src, &val32);
    of_bsn_pdu_tx_reply_experimenter_set(dst, val32);

    of_bsn_pdu_tx_reply_subtype_get(src, &val32);
    of_bsn_pdu_tx_reply_subtype_set(dst, val32);

    of_bsn_pdu_tx_reply_status_get(src, &val32);
    of_bsn_pdu_tx_reply_status_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_pdu_tx_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_pdu_tx_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_pdu_tx_request_t *
of_bsn_pdu_tx_request_OF_VERSION_1_0_dup(
    of_bsn_pdu_tx_request_t *src)
{
    of_bsn_pdu_tx_request_t *dst;
    uint32_t val32;
    of_port_no_t port_no;
    uint8_t val8;
    of_octets_t octets;

    if ((dst = of_bsn_pdu_tx_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_pdu_tx_request_xid_get(src, &val32);
    of_bsn_pdu_tx_request_xid_set(dst, val32);

    of_bsn_pdu_tx_request_experimenter_get(src, &val32);
    of_bsn_pdu_tx_request_experimenter_set(dst, val32);

    of_bsn_pdu_tx_request_subtype_get(src, &val32);
    of_bsn_pdu_tx_request_subtype_set(dst, val32);

    of_bsn_pdu_tx_request_tx_interval_ms_get(src, &val32);
    of_bsn_pdu_tx_request_tx_interval_ms_set(dst, val32);

    of_bsn_pdu_tx_request_port_no_get(src, &port_no);
    of_bsn_pdu_tx_request_port_no_set(dst, port_no);

    of_bsn_pdu_tx_request_slot_num_get(src, &val8);
    of_bsn_pdu_tx_request_slot_num_set(dst, val8);

    of_bsn_pdu_tx_request_data_get(src, &octets);
    of_bsn_pdu_tx_request_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_set_ip_mask
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_set_ip_mask.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_set_ip_mask_t *
of_bsn_set_ip_mask_OF_VERSION_1_0_dup(
    of_bsn_set_ip_mask_t *src)
{
    of_bsn_set_ip_mask_t *dst;
    uint32_t val32;
    uint8_t val8;

    if ((dst = of_bsn_set_ip_mask_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_set_ip_mask_xid_get(src, &val32);
    of_bsn_set_ip_mask_xid_set(dst, val32);

    of_bsn_set_ip_mask_experimenter_get(src, &val32);
    of_bsn_set_ip_mask_experimenter_set(dst, val32);

    of_bsn_set_ip_mask_subtype_get(src, &val32);
    of_bsn_set_ip_mask_subtype_set(dst, val32);

    of_bsn_set_ip_mask_index_get(src, &val8);
    of_bsn_set_ip_mask_index_set(dst, val8);

    of_bsn_set_ip_mask_mask_get(src, &val32);
    of_bsn_set_ip_mask_mask_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_set_l2_table_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_set_l2_table_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_set_l2_table_reply_t *
of_bsn_set_l2_table_reply_OF_VERSION_1_0_dup(
    of_bsn_set_l2_table_reply_t *src)
{
    of_bsn_set_l2_table_reply_t *dst;
    uint32_t val32;
    uint8_t val8;
    uint16_t val16;

    if ((dst = of_bsn_set_l2_table_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_set_l2_table_reply_xid_get(src, &val32);
    of_bsn_set_l2_table_reply_xid_set(dst, val32);

    of_bsn_set_l2_table_reply_experimenter_get(src, &val32);
    of_bsn_set_l2_table_reply_experimenter_set(dst, val32);

    of_bsn_set_l2_table_reply_subtype_get(src, &val32);
    of_bsn_set_l2_table_reply_subtype_set(dst, val32);

    of_bsn_set_l2_table_reply_l2_table_enable_get(src, &val8);
    of_bsn_set_l2_table_reply_l2_table_enable_set(dst, val8);

    of_bsn_set_l2_table_reply_l2_table_priority_get(src, &val16);
    of_bsn_set_l2_table_reply_l2_table_priority_set(dst, val16);

    of_bsn_set_l2_table_reply_status_get(src, &val32);
    of_bsn_set_l2_table_reply_status_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_set_l2_table_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_set_l2_table_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_set_l2_table_request_t *
of_bsn_set_l2_table_request_OF_VERSION_1_0_dup(
    of_bsn_set_l2_table_request_t *src)
{
    of_bsn_set_l2_table_request_t *dst;
    uint32_t val32;
    uint8_t val8;
    uint16_t val16;

    if ((dst = of_bsn_set_l2_table_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_set_l2_table_request_xid_get(src, &val32);
    of_bsn_set_l2_table_request_xid_set(dst, val32);

    of_bsn_set_l2_table_request_experimenter_get(src, &val32);
    of_bsn_set_l2_table_request_experimenter_set(dst, val32);

    of_bsn_set_l2_table_request_subtype_get(src, &val32);
    of_bsn_set_l2_table_request_subtype_set(dst, val32);

    of_bsn_set_l2_table_request_l2_table_enable_get(src, &val8);
    of_bsn_set_l2_table_request_l2_table_enable_set(dst, val8);

    of_bsn_set_l2_table_request_l2_table_priority_get(src, &val16);
    of_bsn_set_l2_table_request_l2_table_priority_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_set_mirroring
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_set_mirroring.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_set_mirroring_t *
of_bsn_set_mirroring_OF_VERSION_1_0_dup(
    of_bsn_set_mirroring_t *src)
{
    of_bsn_set_mirroring_t *dst;
    uint32_t val32;
    uint8_t val8;

    if ((dst = of_bsn_set_mirroring_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_set_mirroring_xid_get(src, &val32);
    of_bsn_set_mirroring_xid_set(dst, val32);

    of_bsn_set_mirroring_experimenter_get(src, &val32);
    of_bsn_set_mirroring_experimenter_set(dst, val32);

    of_bsn_set_mirroring_subtype_get(src, &val32);
    of_bsn_set_mirroring_subtype_set(dst, val32);

    of_bsn_set_mirroring_report_mirror_ports_get(src, &val8);
    of_bsn_set_mirroring_report_mirror_ports_set(dst, val8);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_set_pktin_suppression_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_set_pktin_suppression_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_set_pktin_suppression_reply_t *
of_bsn_set_pktin_suppression_reply_OF_VERSION_1_0_dup(
    of_bsn_set_pktin_suppression_reply_t *src)
{
    of_bsn_set_pktin_suppression_reply_t *dst;
    uint32_t val32;

    if ((dst = of_bsn_set_pktin_suppression_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_set_pktin_suppression_reply_xid_get(src, &val32);
    of_bsn_set_pktin_suppression_reply_xid_set(dst, val32);

    of_bsn_set_pktin_suppression_reply_experimenter_get(src, &val32);
    of_bsn_set_pktin_suppression_reply_experimenter_set(dst, val32);

    of_bsn_set_pktin_suppression_reply_subtype_get(src, &val32);
    of_bsn_set_pktin_suppression_reply_subtype_set(dst, val32);

    of_bsn_set_pktin_suppression_reply_status_get(src, &val32);
    of_bsn_set_pktin_suppression_reply_status_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_set_pktin_suppression_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_set_pktin_suppression_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_set_pktin_suppression_request_t *
of_bsn_set_pktin_suppression_request_OF_VERSION_1_0_dup(
    of_bsn_set_pktin_suppression_request_t *src)
{
    of_bsn_set_pktin_suppression_request_t *dst;
    uint32_t val32;
    uint8_t val8;
    uint16_t val16;
    uint64_t val64;

    if ((dst = of_bsn_set_pktin_suppression_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_set_pktin_suppression_request_xid_get(src, &val32);
    of_bsn_set_pktin_suppression_request_xid_set(dst, val32);

    of_bsn_set_pktin_suppression_request_experimenter_get(src, &val32);
    of_bsn_set_pktin_suppression_request_experimenter_set(dst, val32);

    of_bsn_set_pktin_suppression_request_subtype_get(src, &val32);
    of_bsn_set_pktin_suppression_request_subtype_set(dst, val32);

    of_bsn_set_pktin_suppression_request_enabled_get(src, &val8);
    of_bsn_set_pktin_suppression_request_enabled_set(dst, val8);

    of_bsn_set_pktin_suppression_request_idle_timeout_get(src, &val16);
    of_bsn_set_pktin_suppression_request_idle_timeout_set(dst, val16);

    of_bsn_set_pktin_suppression_request_hard_timeout_get(src, &val16);
    of_bsn_set_pktin_suppression_request_hard_timeout_set(dst, val16);

    of_bsn_set_pktin_suppression_request_priority_get(src, &val16);
    of_bsn_set_pktin_suppression_request_priority_set(dst, val16);

    of_bsn_set_pktin_suppression_request_cookie_get(src, &val64);
    of_bsn_set_pktin_suppression_request_cookie_set(dst, val64);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_shell_command
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_shell_command.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_shell_command_t *
of_bsn_shell_command_OF_VERSION_1_0_dup(
    of_bsn_shell_command_t *src)
{
    of_bsn_shell_command_t *dst;
    uint32_t val32;
    of_octets_t octets;

    if ((dst = of_bsn_shell_command_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_shell_command_xid_get(src, &val32);
    of_bsn_shell_command_xid_set(dst, val32);

    of_bsn_shell_command_experimenter_get(src, &val32);
    of_bsn_shell_command_experimenter_set(dst, val32);

    of_bsn_shell_command_subtype_get(src, &val32);
    of_bsn_shell_command_subtype_set(dst, val32);

    of_bsn_shell_command_service_get(src, &val32);
    of_bsn_shell_command_service_set(dst, val32);

    of_bsn_shell_command_data_get(src, &octets);
    of_bsn_shell_command_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_shell_output
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_shell_output.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_shell_output_t *
of_bsn_shell_output_OF_VERSION_1_0_dup(
    of_bsn_shell_output_t *src)
{
    of_bsn_shell_output_t *dst;
    uint32_t val32;
    of_octets_t octets;

    if ((dst = of_bsn_shell_output_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_shell_output_xid_get(src, &val32);
    of_bsn_shell_output_xid_set(dst, val32);

    of_bsn_shell_output_experimenter_get(src, &val32);
    of_bsn_shell_output_experimenter_set(dst, val32);

    of_bsn_shell_output_subtype_get(src, &val32);
    of_bsn_shell_output_subtype_set(dst, val32);

    of_bsn_shell_output_data_get(src, &octets);
    of_bsn_shell_output_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_shell_status
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_shell_status.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_shell_status_t *
of_bsn_shell_status_OF_VERSION_1_0_dup(
    of_bsn_shell_status_t *src)
{
    of_bsn_shell_status_t *dst;
    uint32_t val32;

    if ((dst = of_bsn_shell_status_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_shell_status_xid_get(src, &val32);
    of_bsn_shell_status_xid_set(dst, val32);

    of_bsn_shell_status_experimenter_get(src, &val32);
    of_bsn_shell_status_experimenter_set(dst, val32);

    of_bsn_shell_status_subtype_get(src, &val32);
    of_bsn_shell_status_subtype_set(dst, val32);

    of_bsn_shell_status_status_get(src, &val32);
    of_bsn_shell_status_status_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_virtual_port_create_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_virtual_port_create_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_virtual_port_create_reply_t *
of_bsn_virtual_port_create_reply_OF_VERSION_1_0_dup(
    of_bsn_virtual_port_create_reply_t *src)
{
    of_bsn_virtual_port_create_reply_t *dst;
    uint32_t val32;

    if ((dst = of_bsn_virtual_port_create_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_virtual_port_create_reply_xid_get(src, &val32);
    of_bsn_virtual_port_create_reply_xid_set(dst, val32);

    of_bsn_virtual_port_create_reply_experimenter_get(src, &val32);
    of_bsn_virtual_port_create_reply_experimenter_set(dst, val32);

    of_bsn_virtual_port_create_reply_subtype_get(src, &val32);
    of_bsn_virtual_port_create_reply_subtype_set(dst, val32);

    of_bsn_virtual_port_create_reply_status_get(src, &val32);
    of_bsn_virtual_port_create_reply_status_set(dst, val32);

    of_bsn_virtual_port_create_reply_vport_no_get(src, &val32);
    of_bsn_virtual_port_create_reply_vport_no_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_virtual_port_create_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_virtual_port_create_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_virtual_port_create_request_t *
of_bsn_virtual_port_create_request_OF_VERSION_1_0_dup(
    of_bsn_virtual_port_create_request_t *src)
{
    of_bsn_virtual_port_create_request_t *dst;
    uint32_t val32;

    of_bsn_vport_q_in_q_t src_vport;
    of_bsn_vport_q_in_q_t *dst_vport;

    if ((dst = of_bsn_virtual_port_create_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_virtual_port_create_request_xid_get(src, &val32);
    of_bsn_virtual_port_create_request_xid_set(dst, val32);

    of_bsn_virtual_port_create_request_experimenter_get(src, &val32);
    of_bsn_virtual_port_create_request_experimenter_set(dst, val32);

    of_bsn_virtual_port_create_request_subtype_get(src, &val32);
    of_bsn_virtual_port_create_request_subtype_set(dst, val32);

    of_bsn_virtual_port_create_request_vport_bind(
        src, &src_vport);
    dst_vport = of_bsn_vport_q_in_q_OF_VERSION_1_0_dup(&src_vport);
    if (dst_vport == NULL) {
        of_bsn_virtual_port_create_request_delete(dst);
        return NULL;
    }
    of_bsn_virtual_port_create_request_vport_set(dst, dst_vport);
    of_bsn_vport_q_in_q_delete(dst_vport);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_virtual_port_remove_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_virtual_port_remove_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_virtual_port_remove_reply_t *
of_bsn_virtual_port_remove_reply_OF_VERSION_1_0_dup(
    of_bsn_virtual_port_remove_reply_t *src)
{
    of_bsn_virtual_port_remove_reply_t *dst;
    uint32_t val32;

    if ((dst = of_bsn_virtual_port_remove_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_virtual_port_remove_reply_xid_get(src, &val32);
    of_bsn_virtual_port_remove_reply_xid_set(dst, val32);

    of_bsn_virtual_port_remove_reply_experimenter_get(src, &val32);
    of_bsn_virtual_port_remove_reply_experimenter_set(dst, val32);

    of_bsn_virtual_port_remove_reply_subtype_get(src, &val32);
    of_bsn_virtual_port_remove_reply_subtype_set(dst, val32);

    of_bsn_virtual_port_remove_reply_status_get(src, &val32);
    of_bsn_virtual_port_remove_reply_status_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_virtual_port_remove_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_virtual_port_remove_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_virtual_port_remove_request_t *
of_bsn_virtual_port_remove_request_OF_VERSION_1_0_dup(
    of_bsn_virtual_port_remove_request_t *src)
{
    of_bsn_virtual_port_remove_request_t *dst;
    uint32_t val32;

    if ((dst = of_bsn_virtual_port_remove_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_virtual_port_remove_request_xid_get(src, &val32);
    of_bsn_virtual_port_remove_request_xid_set(dst, val32);

    of_bsn_virtual_port_remove_request_experimenter_get(src, &val32);
    of_bsn_virtual_port_remove_request_experimenter_set(dst, val32);

    of_bsn_virtual_port_remove_request_subtype_get(src, &val32);
    of_bsn_virtual_port_remove_request_subtype_set(dst, val32);

    of_bsn_virtual_port_remove_request_vport_no_get(src, &val32);
    of_bsn_virtual_port_remove_request_vport_no_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_desc_stats_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_desc_stats_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_desc_stats_reply_t *
of_desc_stats_reply_OF_VERSION_1_0_dup(
    of_desc_stats_reply_t *src)
{
    of_desc_stats_reply_t *dst;
    uint32_t val32;
    uint16_t val16;
    of_desc_str_t desc_str;
    of_serial_num_t ser_num;

    if ((dst = of_desc_stats_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_desc_stats_reply_xid_get(src, &val32);
    of_desc_stats_reply_xid_set(dst, val32);

    of_desc_stats_reply_flags_get(src, &val16);
    of_desc_stats_reply_flags_set(dst, val16);

    of_desc_stats_reply_mfr_desc_get(src, &desc_str);
    of_desc_stats_reply_mfr_desc_set(dst, desc_str);

    of_desc_stats_reply_hw_desc_get(src, &desc_str);
    of_desc_stats_reply_hw_desc_set(dst, desc_str);

    of_desc_stats_reply_sw_desc_get(src, &desc_str);
    of_desc_stats_reply_sw_desc_set(dst, desc_str);

    of_desc_stats_reply_serial_num_get(src, &ser_num);
    of_desc_stats_reply_serial_num_set(dst, ser_num);

    of_desc_stats_reply_dp_desc_get(src, &desc_str);
    of_desc_stats_reply_dp_desc_set(dst, desc_str);

    return dst;
}

/**
 * Duplicate an object of type of_desc_stats_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_desc_stats_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_desc_stats_request_t *
of_desc_stats_request_OF_VERSION_1_0_dup(
    of_desc_stats_request_t *src)
{
    of_desc_stats_request_t *dst;
    uint32_t val32;
    uint16_t val16;

    if ((dst = of_desc_stats_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_desc_stats_request_xid_get(src, &val32);
    of_desc_stats_request_xid_set(dst, val32);

    of_desc_stats_request_flags_get(src, &val16);
    of_desc_stats_request_flags_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_echo_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_echo_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_echo_reply_t *
of_echo_reply_OF_VERSION_1_0_dup(
    of_echo_reply_t *src)
{
    of_echo_reply_t *dst;
    uint32_t val32;
    of_octets_t octets;

    if ((dst = of_echo_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_echo_reply_xid_get(src, &val32);
    of_echo_reply_xid_set(dst, val32);

    of_echo_reply_data_get(src, &octets);
    of_echo_reply_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_echo_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_echo_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_echo_request_t *
of_echo_request_OF_VERSION_1_0_dup(
    of_echo_request_t *src)
{
    of_echo_request_t *dst;
    uint32_t val32;
    of_octets_t octets;

    if ((dst = of_echo_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_echo_request_xid_get(src, &val32);
    of_echo_request_xid_set(dst, val32);

    of_echo_request_data_get(src, &octets);
    of_echo_request_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_error_msg
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_error_msg.
 *
 * The caller is responsible for deleting the returned value
 */
of_error_msg_t *
of_error_msg_OF_VERSION_1_0_dup(
    of_error_msg_t *src)
{
    of_error_msg_t *dst;
    uint32_t val32;

    if ((dst = of_error_msg_new(src->version)) == NULL) {
        return NULL;
    }

    of_error_msg_xid_get(src, &val32);
    of_error_msg_xid_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_experimenter
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_experimenter.
 *
 * The caller is responsible for deleting the returned value
 */
of_experimenter_t *
of_experimenter_OF_VERSION_1_0_dup(
    of_experimenter_t *src)
{
    of_experimenter_t *dst;
    uint32_t val32;
    of_octets_t octets;

    if ((dst = of_experimenter_new(src->version)) == NULL) {
        return NULL;
    }

    of_experimenter_xid_get(src, &val32);
    of_experimenter_xid_set(dst, val32);

    of_experimenter_experimenter_get(src, &val32);
    of_experimenter_experimenter_set(dst, val32);

    of_experimenter_subtype_get(src, &val32);
    of_experimenter_subtype_set(dst, val32);

    of_experimenter_data_get(src, &octets);
    of_experimenter_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_experimenter_stats_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_experimenter_stats_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_experimenter_stats_reply_t *
of_experimenter_stats_reply_OF_VERSION_1_0_dup(
    of_experimenter_stats_reply_t *src)
{
    of_experimenter_stats_reply_t *dst;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    if ((dst = of_experimenter_stats_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_experimenter_stats_reply_xid_get(src, &val32);
    of_experimenter_stats_reply_xid_set(dst, val32);

    of_experimenter_stats_reply_flags_get(src, &val16);
    of_experimenter_stats_reply_flags_set(dst, val16);

    of_experimenter_stats_reply_experimenter_get(src, &val32);
    of_experimenter_stats_reply_experimenter_set(dst, val32);

    of_experimenter_stats_reply_data_get(src, &octets);
    of_experimenter_stats_reply_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_experimenter_stats_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_experimenter_stats_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_experimenter_stats_request_t *
of_experimenter_stats_request_OF_VERSION_1_0_dup(
    of_experimenter_stats_request_t *src)
{
    of_experimenter_stats_request_t *dst;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    if ((dst = of_experimenter_stats_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_experimenter_stats_request_xid_get(src, &val32);
    of_experimenter_stats_request_xid_set(dst, val32);

    of_experimenter_stats_request_flags_get(src, &val16);
    of_experimenter_stats_request_flags_set(dst, val16);

    of_experimenter_stats_request_experimenter_get(src, &val32);
    of_experimenter_stats_request_experimenter_set(dst, val32);

    of_experimenter_stats_request_data_get(src, &octets);
    of_experimenter_stats_request_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_features_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_features_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_features_reply_t *
of_features_reply_OF_VERSION_1_0_dup(
    of_features_reply_t *src)
{
    of_features_reply_t *dst;
    uint32_t val32;
    uint64_t val64;
    uint8_t val8;

    of_list_port_desc_t src_list;
    of_list_port_desc_t *dst_list;

    if ((dst = of_features_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_features_reply_xid_get(src, &val32);
    of_features_reply_xid_set(dst, val32);

    of_features_reply_datapath_id_get(src, &val64);
    of_features_reply_datapath_id_set(dst, val64);

    of_features_reply_n_buffers_get(src, &val32);
    of_features_reply_n_buffers_set(dst, val32);

    of_features_reply_n_tables_get(src, &val8);
    of_features_reply_n_tables_set(dst, val8);

    of_features_reply_capabilities_get(src, &val32);
    of_features_reply_capabilities_set(dst, val32);

    of_features_reply_actions_get(src, &val32);
    of_features_reply_actions_set(dst, val32);

    of_features_reply_ports_bind(
        src, &src_list);
    dst_list = of_list_port_desc_OF_VERSION_1_0_dup(&src_list);
    if (dst_list == NULL) {
        of_features_reply_delete(dst);
        return NULL;
    }
    of_features_reply_ports_set(dst, dst_list);
    of_list_port_desc_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_features_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_features_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_features_request_t *
of_features_request_OF_VERSION_1_0_dup(
    of_features_request_t *src)
{
    of_features_request_t *dst;
    uint32_t val32;

    if ((dst = of_features_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_features_request_xid_get(src, &val32);
    of_features_request_xid_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_flow_add
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_flow_add.
 *
 * The caller is responsible for deleting the returned value
 */
of_flow_add_t *
of_flow_add_OF_VERSION_1_0_dup(
    of_flow_add_t *src)
{
    of_flow_add_t *dst;
    uint32_t val32;
    of_match_t match;
    uint64_t val64;
    uint16_t val16;
    of_port_no_t port_no;

    of_list_action_t src_list;
    of_list_action_t *dst_list;

    if ((dst = of_flow_add_new(src->version)) == NULL) {
        return NULL;
    }

    of_flow_add_xid_get(src, &val32);
    of_flow_add_xid_set(dst, val32);

    of_flow_add_match_get(src, &match);
    of_flow_add_match_set(dst, &match);

    of_flow_add_cookie_get(src, &val64);
    of_flow_add_cookie_set(dst, val64);

    of_flow_add_idle_timeout_get(src, &val16);
    of_flow_add_idle_timeout_set(dst, val16);

    of_flow_add_hard_timeout_get(src, &val16);
    of_flow_add_hard_timeout_set(dst, val16);

    of_flow_add_priority_get(src, &val16);
    of_flow_add_priority_set(dst, val16);

    of_flow_add_buffer_id_get(src, &val32);
    of_flow_add_buffer_id_set(dst, val32);

    of_flow_add_out_port_get(src, &port_no);
    of_flow_add_out_port_set(dst, port_no);

    of_flow_add_flags_get(src, &val16);
    of_flow_add_flags_set(dst, val16);

    of_flow_add_actions_bind(
        src, &src_list);
    dst_list = of_list_action_OF_VERSION_1_0_dup(&src_list);
    if (dst_list == NULL) {
        of_flow_add_delete(dst);
        return NULL;
    }
    of_flow_add_actions_set(dst, dst_list);
    of_list_action_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_flow_delete
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_flow_delete.
 *
 * The caller is responsible for deleting the returned value
 */
of_flow_delete_t *
of_flow_delete_OF_VERSION_1_0_dup(
    of_flow_delete_t *src)
{
    of_flow_delete_t *dst;
    uint32_t val32;
    of_match_t match;
    uint64_t val64;
    uint16_t val16;
    of_port_no_t port_no;

    of_list_action_t src_list;
    of_list_action_t *dst_list;

    if ((dst = of_flow_delete_new(src->version)) == NULL) {
        return NULL;
    }

    of_flow_delete_xid_get(src, &val32);
    of_flow_delete_xid_set(dst, val32);

    of_flow_delete_match_get(src, &match);
    of_flow_delete_match_set(dst, &match);

    of_flow_delete_cookie_get(src, &val64);
    of_flow_delete_cookie_set(dst, val64);

    of_flow_delete_idle_timeout_get(src, &val16);
    of_flow_delete_idle_timeout_set(dst, val16);

    of_flow_delete_hard_timeout_get(src, &val16);
    of_flow_delete_hard_timeout_set(dst, val16);

    of_flow_delete_priority_get(src, &val16);
    of_flow_delete_priority_set(dst, val16);

    of_flow_delete_buffer_id_get(src, &val32);
    of_flow_delete_buffer_id_set(dst, val32);

    of_flow_delete_out_port_get(src, &port_no);
    of_flow_delete_out_port_set(dst, port_no);

    of_flow_delete_flags_get(src, &val16);
    of_flow_delete_flags_set(dst, val16);

    of_flow_delete_actions_bind(
        src, &src_list);
    dst_list = of_list_action_OF_VERSION_1_0_dup(&src_list);
    if (dst_list == NULL) {
        of_flow_delete_delete(dst);
        return NULL;
    }
    of_flow_delete_actions_set(dst, dst_list);
    of_list_action_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_flow_delete_strict
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_flow_delete_strict.
 *
 * The caller is responsible for deleting the returned value
 */
of_flow_delete_strict_t *
of_flow_delete_strict_OF_VERSION_1_0_dup(
    of_flow_delete_strict_t *src)
{
    of_flow_delete_strict_t *dst;
    uint32_t val32;
    of_match_t match;
    uint64_t val64;
    uint16_t val16;
    of_port_no_t port_no;

    of_list_action_t src_list;
    of_list_action_t *dst_list;

    if ((dst = of_flow_delete_strict_new(src->version)) == NULL) {
        return NULL;
    }

    of_flow_delete_strict_xid_get(src, &val32);
    of_flow_delete_strict_xid_set(dst, val32);

    of_flow_delete_strict_match_get(src, &match);
    of_flow_delete_strict_match_set(dst, &match);

    of_flow_delete_strict_cookie_get(src, &val64);
    of_flow_delete_strict_cookie_set(dst, val64);

    of_flow_delete_strict_idle_timeout_get(src, &val16);
    of_flow_delete_strict_idle_timeout_set(dst, val16);

    of_flow_delete_strict_hard_timeout_get(src, &val16);
    of_flow_delete_strict_hard_timeout_set(dst, val16);

    of_flow_delete_strict_priority_get(src, &val16);
    of_flow_delete_strict_priority_set(dst, val16);

    of_flow_delete_strict_buffer_id_get(src, &val32);
    of_flow_delete_strict_buffer_id_set(dst, val32);

    of_flow_delete_strict_out_port_get(src, &port_no);
    of_flow_delete_strict_out_port_set(dst, port_no);

    of_flow_delete_strict_flags_get(src, &val16);
    of_flow_delete_strict_flags_set(dst, val16);

    of_flow_delete_strict_actions_bind(
        src, &src_list);
    dst_list = of_list_action_OF_VERSION_1_0_dup(&src_list);
    if (dst_list == NULL) {
        of_flow_delete_strict_delete(dst);
        return NULL;
    }
    of_flow_delete_strict_actions_set(dst, dst_list);
    of_list_action_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_flow_mod
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_flow_mod.
 *
 * The caller is responsible for deleting the returned value
 */
of_flow_mod_t *
of_flow_mod_OF_VERSION_1_0_dup(
    of_flow_mod_t *src)
{
    of_flow_mod_t *dst;
    uint32_t val32;
    of_match_t match;
    uint64_t val64;
    uint16_t val16;
    of_port_no_t port_no;

    of_list_action_t src_list;
    of_list_action_t *dst_list;

    if ((dst = of_flow_mod_new(src->version)) == NULL) {
        return NULL;
    }

    of_flow_mod_xid_get(src, &val32);
    of_flow_mod_xid_set(dst, val32);

    of_flow_mod_match_get(src, &match);
    of_flow_mod_match_set(dst, &match);

    of_flow_mod_cookie_get(src, &val64);
    of_flow_mod_cookie_set(dst, val64);

    of_flow_mod_idle_timeout_get(src, &val16);
    of_flow_mod_idle_timeout_set(dst, val16);

    of_flow_mod_hard_timeout_get(src, &val16);
    of_flow_mod_hard_timeout_set(dst, val16);

    of_flow_mod_priority_get(src, &val16);
    of_flow_mod_priority_set(dst, val16);

    of_flow_mod_buffer_id_get(src, &val32);
    of_flow_mod_buffer_id_set(dst, val32);

    of_flow_mod_out_port_get(src, &port_no);
    of_flow_mod_out_port_set(dst, port_no);

    of_flow_mod_flags_get(src, &val16);
    of_flow_mod_flags_set(dst, val16);

    of_flow_mod_actions_bind(
        src, &src_list);
    dst_list = of_list_action_OF_VERSION_1_0_dup(&src_list);
    if (dst_list == NULL) {
        of_flow_mod_delete(dst);
        return NULL;
    }
    of_flow_mod_actions_set(dst, dst_list);
    of_list_action_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_flow_mod_failed_error_msg
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_flow_mod_failed_error_msg.
 *
 * The caller is responsible for deleting the returned value
 */
of_flow_mod_failed_error_msg_t *
of_flow_mod_failed_error_msg_OF_VERSION_1_0_dup(
    of_flow_mod_failed_error_msg_t *src)
{
    of_flow_mod_failed_error_msg_t *dst;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    if ((dst = of_flow_mod_failed_error_msg_new(src->version)) == NULL) {
        return NULL;
    }

    of_flow_mod_failed_error_msg_xid_get(src, &val32);
    of_flow_mod_failed_error_msg_xid_set(dst, val32);

    of_flow_mod_failed_error_msg_code_get(src, &val16);
    of_flow_mod_failed_error_msg_code_set(dst, val16);

    of_flow_mod_failed_error_msg_data_get(src, &octets);
    of_flow_mod_failed_error_msg_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_flow_modify
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_flow_modify.
 *
 * The caller is responsible for deleting the returned value
 */
of_flow_modify_t *
of_flow_modify_OF_VERSION_1_0_dup(
    of_flow_modify_t *src)
{
    of_flow_modify_t *dst;
    uint32_t val32;
    of_match_t match;
    uint64_t val64;
    uint16_t val16;
    of_port_no_t port_no;

    of_list_action_t src_list;
    of_list_action_t *dst_list;

    if ((dst = of_flow_modify_new(src->version)) == NULL) {
        return NULL;
    }

    of_flow_modify_xid_get(src, &val32);
    of_flow_modify_xid_set(dst, val32);

    of_flow_modify_match_get(src, &match);
    of_flow_modify_match_set(dst, &match);

    of_flow_modify_cookie_get(src, &val64);
    of_flow_modify_cookie_set(dst, val64);

    of_flow_modify_idle_timeout_get(src, &val16);
    of_flow_modify_idle_timeout_set(dst, val16);

    of_flow_modify_hard_timeout_get(src, &val16);
    of_flow_modify_hard_timeout_set(dst, val16);

    of_flow_modify_priority_get(src, &val16);
    of_flow_modify_priority_set(dst, val16);

    of_flow_modify_buffer_id_get(src, &val32);
    of_flow_modify_buffer_id_set(dst, val32);

    of_flow_modify_out_port_get(src, &port_no);
    of_flow_modify_out_port_set(dst, port_no);

    of_flow_modify_flags_get(src, &val16);
    of_flow_modify_flags_set(dst, val16);

    of_flow_modify_actions_bind(
        src, &src_list);
    dst_list = of_list_action_OF_VERSION_1_0_dup(&src_list);
    if (dst_list == NULL) {
        of_flow_modify_delete(dst);
        return NULL;
    }
    of_flow_modify_actions_set(dst, dst_list);
    of_list_action_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_flow_modify_strict
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_flow_modify_strict.
 *
 * The caller is responsible for deleting the returned value
 */
of_flow_modify_strict_t *
of_flow_modify_strict_OF_VERSION_1_0_dup(
    of_flow_modify_strict_t *src)
{
    of_flow_modify_strict_t *dst;
    uint32_t val32;
    of_match_t match;
    uint64_t val64;
    uint16_t val16;
    of_port_no_t port_no;

    of_list_action_t src_list;
    of_list_action_t *dst_list;

    if ((dst = of_flow_modify_strict_new(src->version)) == NULL) {
        return NULL;
    }

    of_flow_modify_strict_xid_get(src, &val32);
    of_flow_modify_strict_xid_set(dst, val32);

    of_flow_modify_strict_match_get(src, &match);
    of_flow_modify_strict_match_set(dst, &match);

    of_flow_modify_strict_cookie_get(src, &val64);
    of_flow_modify_strict_cookie_set(dst, val64);

    of_flow_modify_strict_idle_timeout_get(src, &val16);
    of_flow_modify_strict_idle_timeout_set(dst, val16);

    of_flow_modify_strict_hard_timeout_get(src, &val16);
    of_flow_modify_strict_hard_timeout_set(dst, val16);

    of_flow_modify_strict_priority_get(src, &val16);
    of_flow_modify_strict_priority_set(dst, val16);

    of_flow_modify_strict_buffer_id_get(src, &val32);
    of_flow_modify_strict_buffer_id_set(dst, val32);

    of_flow_modify_strict_out_port_get(src, &port_no);
    of_flow_modify_strict_out_port_set(dst, port_no);

    of_flow_modify_strict_flags_get(src, &val16);
    of_flow_modify_strict_flags_set(dst, val16);

    of_flow_modify_strict_actions_bind(
        src, &src_list);
    dst_list = of_list_action_OF_VERSION_1_0_dup(&src_list);
    if (dst_list == NULL) {
        of_flow_modify_strict_delete(dst);
        return NULL;
    }
    of_flow_modify_strict_actions_set(dst, dst_list);
    of_list_action_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_flow_removed
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_flow_removed.
 *
 * The caller is responsible for deleting the returned value
 */
of_flow_removed_t *
of_flow_removed_OF_VERSION_1_0_dup(
    of_flow_removed_t *src)
{
    of_flow_removed_t *dst;
    uint32_t val32;
    of_match_t match;
    uint64_t val64;
    uint16_t val16;
    uint8_t val8;

    if ((dst = of_flow_removed_new(src->version)) == NULL) {
        return NULL;
    }

    of_flow_removed_xid_get(src, &val32);
    of_flow_removed_xid_set(dst, val32);

    of_flow_removed_match_get(src, &match);
    of_flow_removed_match_set(dst, &match);

    of_flow_removed_cookie_get(src, &val64);
    of_flow_removed_cookie_set(dst, val64);

    of_flow_removed_priority_get(src, &val16);
    of_flow_removed_priority_set(dst, val16);

    of_flow_removed_reason_get(src, &val8);
    of_flow_removed_reason_set(dst, val8);

    of_flow_removed_duration_sec_get(src, &val32);
    of_flow_removed_duration_sec_set(dst, val32);

    of_flow_removed_duration_nsec_get(src, &val32);
    of_flow_removed_duration_nsec_set(dst, val32);

    of_flow_removed_idle_timeout_get(src, &val16);
    of_flow_removed_idle_timeout_set(dst, val16);

    of_flow_removed_packet_count_get(src, &val64);
    of_flow_removed_packet_count_set(dst, val64);

    of_flow_removed_byte_count_get(src, &val64);
    of_flow_removed_byte_count_set(dst, val64);

    return dst;
}

/**
 * Duplicate an object of type of_flow_stats_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_flow_stats_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_flow_stats_reply_t *
of_flow_stats_reply_OF_VERSION_1_0_dup(
    of_flow_stats_reply_t *src)
{
    of_flow_stats_reply_t *dst;
    uint32_t val32;
    uint16_t val16;

    of_list_flow_stats_entry_t src_list;
    of_list_flow_stats_entry_t *dst_list;

    if ((dst = of_flow_stats_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_flow_stats_reply_xid_get(src, &val32);
    of_flow_stats_reply_xid_set(dst, val32);

    of_flow_stats_reply_flags_get(src, &val16);
    of_flow_stats_reply_flags_set(dst, val16);

    of_flow_stats_reply_entries_bind(
        src, &src_list);
    dst_list = of_list_flow_stats_entry_OF_VERSION_1_0_dup(&src_list);
    if (dst_list == NULL) {
        of_flow_stats_reply_delete(dst);
        return NULL;
    }
    of_flow_stats_reply_entries_set(dst, dst_list);
    of_list_flow_stats_entry_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_flow_stats_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_flow_stats_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_flow_stats_request_t *
of_flow_stats_request_OF_VERSION_1_0_dup(
    of_flow_stats_request_t *src)
{
    of_flow_stats_request_t *dst;
    uint32_t val32;
    uint16_t val16;
    of_match_t match;
    uint8_t val8;
    of_port_no_t port_no;

    if ((dst = of_flow_stats_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_flow_stats_request_xid_get(src, &val32);
    of_flow_stats_request_xid_set(dst, val32);

    of_flow_stats_request_flags_get(src, &val16);
    of_flow_stats_request_flags_set(dst, val16);

    of_flow_stats_request_match_get(src, &match);
    of_flow_stats_request_match_set(dst, &match);

    of_flow_stats_request_table_id_get(src, &val8);
    of_flow_stats_request_table_id_set(dst, val8);

    of_flow_stats_request_out_port_get(src, &port_no);
    of_flow_stats_request_out_port_set(dst, port_no);

    return dst;
}

/**
 * Duplicate an object of type of_get_config_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_get_config_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_get_config_reply_t *
of_get_config_reply_OF_VERSION_1_0_dup(
    of_get_config_reply_t *src)
{
    of_get_config_reply_t *dst;
    uint32_t val32;
    uint16_t val16;

    if ((dst = of_get_config_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_get_config_reply_xid_get(src, &val32);
    of_get_config_reply_xid_set(dst, val32);

    of_get_config_reply_flags_get(src, &val16);
    of_get_config_reply_flags_set(dst, val16);

    of_get_config_reply_miss_send_len_get(src, &val16);
    of_get_config_reply_miss_send_len_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_get_config_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_get_config_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_get_config_request_t *
of_get_config_request_OF_VERSION_1_0_dup(
    of_get_config_request_t *src)
{
    of_get_config_request_t *dst;
    uint32_t val32;

    if ((dst = of_get_config_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_get_config_request_xid_get(src, &val32);
    of_get_config_request_xid_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_hello
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_hello.
 *
 * The caller is responsible for deleting the returned value
 */
of_hello_t *
of_hello_OF_VERSION_1_0_dup(
    of_hello_t *src)
{
    of_hello_t *dst;
    uint32_t val32;

    if ((dst = of_hello_new(src->version)) == NULL) {
        return NULL;
    }

    of_hello_xid_get(src, &val32);
    of_hello_xid_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_hello_failed_error_msg
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_hello_failed_error_msg.
 *
 * The caller is responsible for deleting the returned value
 */
of_hello_failed_error_msg_t *
of_hello_failed_error_msg_OF_VERSION_1_0_dup(
    of_hello_failed_error_msg_t *src)
{
    of_hello_failed_error_msg_t *dst;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    if ((dst = of_hello_failed_error_msg_new(src->version)) == NULL) {
        return NULL;
    }

    of_hello_failed_error_msg_xid_get(src, &val32);
    of_hello_failed_error_msg_xid_set(dst, val32);

    of_hello_failed_error_msg_code_get(src, &val16);
    of_hello_failed_error_msg_code_set(dst, val16);

    of_hello_failed_error_msg_data_get(src, &octets);
    of_hello_failed_error_msg_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_nicira_controller_role_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_nicira_controller_role_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_nicira_controller_role_reply_t *
of_nicira_controller_role_reply_OF_VERSION_1_0_dup(
    of_nicira_controller_role_reply_t *src)
{
    of_nicira_controller_role_reply_t *dst;
    uint32_t val32;

    if ((dst = of_nicira_controller_role_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_nicira_controller_role_reply_xid_get(src, &val32);
    of_nicira_controller_role_reply_xid_set(dst, val32);

    of_nicira_controller_role_reply_experimenter_get(src, &val32);
    of_nicira_controller_role_reply_experimenter_set(dst, val32);

    of_nicira_controller_role_reply_subtype_get(src, &val32);
    of_nicira_controller_role_reply_subtype_set(dst, val32);

    of_nicira_controller_role_reply_role_get(src, &val32);
    of_nicira_controller_role_reply_role_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_nicira_controller_role_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_nicira_controller_role_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_nicira_controller_role_request_t *
of_nicira_controller_role_request_OF_VERSION_1_0_dup(
    of_nicira_controller_role_request_t *src)
{
    of_nicira_controller_role_request_t *dst;
    uint32_t val32;

    if ((dst = of_nicira_controller_role_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_nicira_controller_role_request_xid_get(src, &val32);
    of_nicira_controller_role_request_xid_set(dst, val32);

    of_nicira_controller_role_request_experimenter_get(src, &val32);
    of_nicira_controller_role_request_experimenter_set(dst, val32);

    of_nicira_controller_role_request_subtype_get(src, &val32);
    of_nicira_controller_role_request_subtype_set(dst, val32);

    of_nicira_controller_role_request_role_get(src, &val32);
    of_nicira_controller_role_request_role_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_nicira_header
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_nicira_header.
 *
 * The caller is responsible for deleting the returned value
 */
of_nicira_header_t *
of_nicira_header_OF_VERSION_1_0_dup(
    of_nicira_header_t *src)
{
    of_nicira_header_t *dst;
    uint32_t val32;

    if ((dst = of_nicira_header_new(src->version)) == NULL) {
        return NULL;
    }

    of_nicira_header_xid_get(src, &val32);
    of_nicira_header_xid_set(dst, val32);

    of_nicira_header_experimenter_get(src, &val32);
    of_nicira_header_experimenter_set(dst, val32);

    of_nicira_header_subtype_get(src, &val32);
    of_nicira_header_subtype_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_packet_in
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_packet_in.
 *
 * The caller is responsible for deleting the returned value
 */
of_packet_in_t *
of_packet_in_OF_VERSION_1_0_dup(
    of_packet_in_t *src)
{
    of_packet_in_t *dst;
    uint32_t val32;
    uint16_t val16;
    of_port_no_t port_no;
    uint8_t val8;
    of_octets_t octets;

    if ((dst = of_packet_in_new(src->version)) == NULL) {
        return NULL;
    }

    of_packet_in_xid_get(src, &val32);
    of_packet_in_xid_set(dst, val32);

    of_packet_in_buffer_id_get(src, &val32);
    of_packet_in_buffer_id_set(dst, val32);

    of_packet_in_total_len_get(src, &val16);
    of_packet_in_total_len_set(dst, val16);

    of_packet_in_in_port_get(src, &port_no);
    of_packet_in_in_port_set(dst, port_no);

    of_packet_in_reason_get(src, &val8);
    of_packet_in_reason_set(dst, val8);

    of_packet_in_data_get(src, &octets);
    of_packet_in_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_packet_out
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_packet_out.
 *
 * The caller is responsible for deleting the returned value
 */
of_packet_out_t *
of_packet_out_OF_VERSION_1_0_dup(
    of_packet_out_t *src)
{
    of_packet_out_t *dst;
    uint32_t val32;
    of_port_no_t port_no;

    of_list_action_t src_list;
    of_list_action_t *dst_list;
    of_octets_t octets;

    if ((dst = of_packet_out_new(src->version)) == NULL) {
        return NULL;
    }

    of_packet_out_xid_get(src, &val32);
    of_packet_out_xid_set(dst, val32);

    of_packet_out_buffer_id_get(src, &val32);
    of_packet_out_buffer_id_set(dst, val32);

    of_packet_out_in_port_get(src, &port_no);
    of_packet_out_in_port_set(dst, port_no);

    of_packet_out_actions_bind(
        src, &src_list);
    dst_list = of_list_action_OF_VERSION_1_0_dup(&src_list);
    if (dst_list == NULL) {
        of_packet_out_delete(dst);
        return NULL;
    }
    of_packet_out_actions_set(dst, dst_list);
    of_list_action_delete(dst_list);

    of_packet_out_data_get(src, &octets);
    of_packet_out_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_port_mod
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_port_mod.
 *
 * The caller is responsible for deleting the returned value
 */
of_port_mod_t *
of_port_mod_OF_VERSION_1_0_dup(
    of_port_mod_t *src)
{
    of_port_mod_t *dst;
    uint32_t val32;
    of_port_no_t port_no;
    of_mac_addr_t mac_addr;

    if ((dst = of_port_mod_new(src->version)) == NULL) {
        return NULL;
    }

    of_port_mod_xid_get(src, &val32);
    of_port_mod_xid_set(dst, val32);

    of_port_mod_port_no_get(src, &port_no);
    of_port_mod_port_no_set(dst, port_no);

    of_port_mod_hw_addr_get(src, &mac_addr);
    of_port_mod_hw_addr_set(dst, mac_addr);

    of_port_mod_config_get(src, &val32);
    of_port_mod_config_set(dst, val32);

    of_port_mod_mask_get(src, &val32);
    of_port_mod_mask_set(dst, val32);

    of_port_mod_advertise_get(src, &val32);
    of_port_mod_advertise_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_port_mod_failed_error_msg
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_port_mod_failed_error_msg.
 *
 * The caller is responsible for deleting the returned value
 */
of_port_mod_failed_error_msg_t *
of_port_mod_failed_error_msg_OF_VERSION_1_0_dup(
    of_port_mod_failed_error_msg_t *src)
{
    of_port_mod_failed_error_msg_t *dst;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    if ((dst = of_port_mod_failed_error_msg_new(src->version)) == NULL) {
        return NULL;
    }

    of_port_mod_failed_error_msg_xid_get(src, &val32);
    of_port_mod_failed_error_msg_xid_set(dst, val32);

    of_port_mod_failed_error_msg_code_get(src, &val16);
    of_port_mod_failed_error_msg_code_set(dst, val16);

    of_port_mod_failed_error_msg_data_get(src, &octets);
    of_port_mod_failed_error_msg_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_port_stats_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_port_stats_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_port_stats_reply_t *
of_port_stats_reply_OF_VERSION_1_0_dup(
    of_port_stats_reply_t *src)
{
    of_port_stats_reply_t *dst;
    uint32_t val32;
    uint16_t val16;

    of_list_port_stats_entry_t src_list;
    of_list_port_stats_entry_t *dst_list;

    if ((dst = of_port_stats_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_port_stats_reply_xid_get(src, &val32);
    of_port_stats_reply_xid_set(dst, val32);

    of_port_stats_reply_flags_get(src, &val16);
    of_port_stats_reply_flags_set(dst, val16);

    of_port_stats_reply_entries_bind(
        src, &src_list);
    dst_list = of_list_port_stats_entry_OF_VERSION_1_0_dup(&src_list);
    if (dst_list == NULL) {
        of_port_stats_reply_delete(dst);
        return NULL;
    }
    of_port_stats_reply_entries_set(dst, dst_list);
    of_list_port_stats_entry_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_port_stats_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_port_stats_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_port_stats_request_t *
of_port_stats_request_OF_VERSION_1_0_dup(
    of_port_stats_request_t *src)
{
    of_port_stats_request_t *dst;
    uint32_t val32;
    uint16_t val16;
    of_port_no_t port_no;

    if ((dst = of_port_stats_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_port_stats_request_xid_get(src, &val32);
    of_port_stats_request_xid_set(dst, val32);

    of_port_stats_request_flags_get(src, &val16);
    of_port_stats_request_flags_set(dst, val16);

    of_port_stats_request_port_no_get(src, &port_no);
    of_port_stats_request_port_no_set(dst, port_no);

    return dst;
}

/**
 * Duplicate an object of type of_port_status
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_port_status.
 *
 * The caller is responsible for deleting the returned value
 */
of_port_status_t *
of_port_status_OF_VERSION_1_0_dup(
    of_port_status_t *src)
{
    of_port_status_t *dst;
    uint32_t val32;
    uint8_t val8;

    of_port_desc_t src_port_desc;
    of_port_desc_t *dst_port_desc;

    if ((dst = of_port_status_new(src->version)) == NULL) {
        return NULL;
    }

    of_port_status_xid_get(src, &val32);
    of_port_status_xid_set(dst, val32);

    of_port_status_reason_get(src, &val8);
    of_port_status_reason_set(dst, val8);

    of_port_status_desc_bind(
        src, &src_port_desc);
    dst_port_desc = of_port_desc_OF_VERSION_1_0_dup(&src_port_desc);
    if (dst_port_desc == NULL) {
        of_port_status_delete(dst);
        return NULL;
    }
    of_port_status_desc_set(dst, dst_port_desc);
    of_port_desc_delete(dst_port_desc);

    return dst;
}

/**
 * Duplicate an object of type of_queue_get_config_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_queue_get_config_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_queue_get_config_reply_t *
of_queue_get_config_reply_OF_VERSION_1_0_dup(
    of_queue_get_config_reply_t *src)
{
    of_queue_get_config_reply_t *dst;
    uint32_t val32;
    of_port_no_t port_no;

    of_list_packet_queue_t src_list;
    of_list_packet_queue_t *dst_list;

    if ((dst = of_queue_get_config_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_queue_get_config_reply_xid_get(src, &val32);
    of_queue_get_config_reply_xid_set(dst, val32);

    of_queue_get_config_reply_port_get(src, &port_no);
    of_queue_get_config_reply_port_set(dst, port_no);

    of_queue_get_config_reply_queues_bind(
        src, &src_list);
    dst_list = of_list_packet_queue_OF_VERSION_1_0_dup(&src_list);
    if (dst_list == NULL) {
        of_queue_get_config_reply_delete(dst);
        return NULL;
    }
    of_queue_get_config_reply_queues_set(dst, dst_list);
    of_list_packet_queue_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_queue_get_config_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_queue_get_config_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_queue_get_config_request_t *
of_queue_get_config_request_OF_VERSION_1_0_dup(
    of_queue_get_config_request_t *src)
{
    of_queue_get_config_request_t *dst;
    uint32_t val32;
    of_port_no_t port_no;

    if ((dst = of_queue_get_config_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_queue_get_config_request_xid_get(src, &val32);
    of_queue_get_config_request_xid_set(dst, val32);

    of_queue_get_config_request_port_get(src, &port_no);
    of_queue_get_config_request_port_set(dst, port_no);

    return dst;
}

/**
 * Duplicate an object of type of_queue_op_failed_error_msg
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_queue_op_failed_error_msg.
 *
 * The caller is responsible for deleting the returned value
 */
of_queue_op_failed_error_msg_t *
of_queue_op_failed_error_msg_OF_VERSION_1_0_dup(
    of_queue_op_failed_error_msg_t *src)
{
    of_queue_op_failed_error_msg_t *dst;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    if ((dst = of_queue_op_failed_error_msg_new(src->version)) == NULL) {
        return NULL;
    }

    of_queue_op_failed_error_msg_xid_get(src, &val32);
    of_queue_op_failed_error_msg_xid_set(dst, val32);

    of_queue_op_failed_error_msg_code_get(src, &val16);
    of_queue_op_failed_error_msg_code_set(dst, val16);

    of_queue_op_failed_error_msg_data_get(src, &octets);
    of_queue_op_failed_error_msg_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_queue_stats_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_queue_stats_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_queue_stats_reply_t *
of_queue_stats_reply_OF_VERSION_1_0_dup(
    of_queue_stats_reply_t *src)
{
    of_queue_stats_reply_t *dst;
    uint32_t val32;
    uint16_t val16;

    of_list_queue_stats_entry_t src_list;
    of_list_queue_stats_entry_t *dst_list;

    if ((dst = of_queue_stats_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_queue_stats_reply_xid_get(src, &val32);
    of_queue_stats_reply_xid_set(dst, val32);

    of_queue_stats_reply_flags_get(src, &val16);
    of_queue_stats_reply_flags_set(dst, val16);

    of_queue_stats_reply_entries_bind(
        src, &src_list);
    dst_list = of_list_queue_stats_entry_OF_VERSION_1_0_dup(&src_list);
    if (dst_list == NULL) {
        of_queue_stats_reply_delete(dst);
        return NULL;
    }
    of_queue_stats_reply_entries_set(dst, dst_list);
    of_list_queue_stats_entry_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_queue_stats_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_queue_stats_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_queue_stats_request_t *
of_queue_stats_request_OF_VERSION_1_0_dup(
    of_queue_stats_request_t *src)
{
    of_queue_stats_request_t *dst;
    uint32_t val32;
    uint16_t val16;
    of_port_no_t port_no;

    if ((dst = of_queue_stats_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_queue_stats_request_xid_get(src, &val32);
    of_queue_stats_request_xid_set(dst, val32);

    of_queue_stats_request_flags_get(src, &val16);
    of_queue_stats_request_flags_set(dst, val16);

    of_queue_stats_request_port_no_get(src, &port_no);
    of_queue_stats_request_port_no_set(dst, port_no);

    of_queue_stats_request_queue_id_get(src, &val32);
    of_queue_stats_request_queue_id_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_set_config
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_set_config.
 *
 * The caller is responsible for deleting the returned value
 */
of_set_config_t *
of_set_config_OF_VERSION_1_0_dup(
    of_set_config_t *src)
{
    of_set_config_t *dst;
    uint32_t val32;
    uint16_t val16;

    if ((dst = of_set_config_new(src->version)) == NULL) {
        return NULL;
    }

    of_set_config_xid_get(src, &val32);
    of_set_config_xid_set(dst, val32);

    of_set_config_flags_get(src, &val16);
    of_set_config_flags_set(dst, val16);

    of_set_config_miss_send_len_get(src, &val16);
    of_set_config_miss_send_len_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_stats_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_stats_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_stats_reply_t *
of_stats_reply_OF_VERSION_1_0_dup(
    of_stats_reply_t *src)
{
    of_stats_reply_t *dst;
    uint32_t val32;
    uint16_t val16;

    if ((dst = of_stats_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_stats_reply_xid_get(src, &val32);
    of_stats_reply_xid_set(dst, val32);

    of_stats_reply_flags_get(src, &val16);
    of_stats_reply_flags_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_stats_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_stats_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_stats_request_t *
of_stats_request_OF_VERSION_1_0_dup(
    of_stats_request_t *src)
{
    of_stats_request_t *dst;
    uint32_t val32;
    uint16_t val16;

    if ((dst = of_stats_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_stats_request_xid_get(src, &val32);
    of_stats_request_xid_set(dst, val32);

    of_stats_request_flags_get(src, &val16);
    of_stats_request_flags_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_table_mod
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_table_mod.
 *
 * The caller is responsible for deleting the returned value
 */
of_table_mod_t *
of_table_mod_OF_VERSION_1_0_dup(
    of_table_mod_t *src)
{
    of_table_mod_t *dst;
    uint32_t val32;
    uint8_t val8;

    if ((dst = of_table_mod_new(src->version)) == NULL) {
        return NULL;
    }

    of_table_mod_xid_get(src, &val32);
    of_table_mod_xid_set(dst, val32);

    of_table_mod_table_id_get(src, &val8);
    of_table_mod_table_id_set(dst, val8);

    of_table_mod_config_get(src, &val32);
    of_table_mod_config_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_table_stats_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_table_stats_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_table_stats_reply_t *
of_table_stats_reply_OF_VERSION_1_0_dup(
    of_table_stats_reply_t *src)
{
    of_table_stats_reply_t *dst;
    uint32_t val32;
    uint16_t val16;

    of_list_table_stats_entry_t src_list;
    of_list_table_stats_entry_t *dst_list;

    if ((dst = of_table_stats_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_table_stats_reply_xid_get(src, &val32);
    of_table_stats_reply_xid_set(dst, val32);

    of_table_stats_reply_flags_get(src, &val16);
    of_table_stats_reply_flags_set(dst, val16);

    of_table_stats_reply_entries_bind(
        src, &src_list);
    dst_list = of_list_table_stats_entry_OF_VERSION_1_0_dup(&src_list);
    if (dst_list == NULL) {
        of_table_stats_reply_delete(dst);
        return NULL;
    }
    of_table_stats_reply_entries_set(dst, dst_list);
    of_list_table_stats_entry_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_table_stats_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_table_stats_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_table_stats_request_t *
of_table_stats_request_OF_VERSION_1_0_dup(
    of_table_stats_request_t *src)
{
    of_table_stats_request_t *dst;
    uint32_t val32;
    uint16_t val16;

    if ((dst = of_table_stats_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_table_stats_request_xid_get(src, &val32);
    of_table_stats_request_xid_set(dst, val32);

    of_table_stats_request_flags_get(src, &val16);
    of_table_stats_request_flags_set(dst, val16);

    return dst;
}

/**
 * Duplicate a super class object of type of_action
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_t *
of_action_OF_VERSION_1_0_dup(
    of_action_t *src)
{

    if (src->header.object_id == OF_ACTION_NICIRA) {
        return (of_action_t *)of_action_nicira_OF_VERSION_1_0_dup(
            &src->nicira);
    }

    if (src->header.object_id == OF_ACTION_STRIP_VLAN) {
        return (of_action_t *)of_action_strip_vlan_OF_VERSION_1_0_dup(
            &src->strip_vlan);
    }

    if (src->header.object_id == OF_ACTION_SET_TP_DST) {
        return (of_action_t *)of_action_set_tp_dst_OF_VERSION_1_0_dup(
            &src->set_tp_dst);
    }

    if (src->header.object_id == OF_ACTION_BSN_MIRROR) {
        return (of_action_t *)of_action_bsn_mirror_OF_VERSION_1_0_dup(
            &src->bsn_mirror);
    }

    if (src->header.object_id == OF_ACTION_SET_DL_DST) {
        return (of_action_t *)of_action_set_dl_dst_OF_VERSION_1_0_dup(
            &src->set_dl_dst);
    }

    if (src->header.object_id == OF_ACTION_SET_NW_SRC) {
        return (of_action_t *)of_action_set_nw_src_OF_VERSION_1_0_dup(
            &src->set_nw_src);
    }

    if (src->header.object_id == OF_ACTION_SET_VLAN_PCP) {
        return (of_action_t *)of_action_set_vlan_pcp_OF_VERSION_1_0_dup(
            &src->set_vlan_pcp);
    }

    if (src->header.object_id == OF_ACTION_SET_TP_SRC) {
        return (of_action_t *)of_action_set_tp_src_OF_VERSION_1_0_dup(
            &src->set_tp_src);
    }

    if (src->header.object_id == OF_ACTION_ENQUEUE) {
        return (of_action_t *)of_action_enqueue_OF_VERSION_1_0_dup(
            &src->enqueue);
    }

    if (src->header.object_id == OF_ACTION_BSN) {
        return (of_action_t *)of_action_bsn_OF_VERSION_1_0_dup(
            &src->bsn);
    }

    if (src->header.object_id == OF_ACTION_SET_NW_TOS) {
        return (of_action_t *)of_action_set_nw_tos_OF_VERSION_1_0_dup(
            &src->set_nw_tos);
    }

    if (src->header.object_id == OF_ACTION_EXPERIMENTER) {
        return (of_action_t *)of_action_experimenter_OF_VERSION_1_0_dup(
            &src->experimenter);
    }

    if (src->header.object_id == OF_ACTION_SET_DL_SRC) {
        return (of_action_t *)of_action_set_dl_src_OF_VERSION_1_0_dup(
            &src->set_dl_src);
    }

    if (src->header.object_id == OF_ACTION_BSN_SET_TUNNEL_DST) {
        return (of_action_t *)of_action_bsn_set_tunnel_dst_OF_VERSION_1_0_dup(
            &src->bsn_set_tunnel_dst);
    }

    if (src->header.object_id == OF_ACTION_SET_NW_DST) {
        return (of_action_t *)of_action_set_nw_dst_OF_VERSION_1_0_dup(
            &src->set_nw_dst);
    }

    if (src->header.object_id == OF_ACTION_OUTPUT) {
        return (of_action_t *)of_action_output_OF_VERSION_1_0_dup(
            &src->output);
    }

    if (src->header.object_id == OF_ACTION_NICIRA_DEC_TTL) {
        return (of_action_t *)of_action_nicira_dec_ttl_OF_VERSION_1_0_dup(
            &src->nicira_dec_ttl);
    }

    if (src->header.object_id == OF_ACTION_SET_VLAN_VID) {
        return (of_action_t *)of_action_set_vlan_vid_OF_VERSION_1_0_dup(
            &src->set_vlan_vid);
    }

    return NULL;
}

/**
 * Duplicate an object of type of_action_bsn
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_bsn.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_bsn_t *
of_action_bsn_OF_VERSION_1_0_dup(
    of_action_bsn_t *src)
{
    of_action_bsn_t *dst;
    uint32_t val32;

    if ((dst = of_action_bsn_new(src->version)) == NULL) {
        return NULL;
    }

    of_action_bsn_experimenter_get(src, &val32);
    of_action_bsn_experimenter_set(dst, val32);

    of_action_bsn_subtype_get(src, &val32);
    of_action_bsn_subtype_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_action_bsn_mirror
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_bsn_mirror.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_bsn_mirror_t *
of_action_bsn_mirror_OF_VERSION_1_0_dup(
    of_action_bsn_mirror_t *src)
{
    of_action_bsn_mirror_t *dst;
    uint32_t val32;
    uint8_t val8;

    if ((dst = of_action_bsn_mirror_new(src->version)) == NULL) {
        return NULL;
    }

    of_action_bsn_mirror_experimenter_get(src, &val32);
    of_action_bsn_mirror_experimenter_set(dst, val32);

    of_action_bsn_mirror_subtype_get(src, &val32);
    of_action_bsn_mirror_subtype_set(dst, val32);

    of_action_bsn_mirror_dest_port_get(src, &val32);
    of_action_bsn_mirror_dest_port_set(dst, val32);

    of_action_bsn_mirror_vlan_tag_get(src, &val32);
    of_action_bsn_mirror_vlan_tag_set(dst, val32);

    of_action_bsn_mirror_copy_stage_get(src, &val8);
    of_action_bsn_mirror_copy_stage_set(dst, val8);

    return dst;
}

/**
 * Duplicate an object of type of_action_bsn_set_tunnel_dst
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_bsn_set_tunnel_dst.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_bsn_set_tunnel_dst_t *
of_action_bsn_set_tunnel_dst_OF_VERSION_1_0_dup(
    of_action_bsn_set_tunnel_dst_t *src)
{
    of_action_bsn_set_tunnel_dst_t *dst;
    uint32_t val32;

    if ((dst = of_action_bsn_set_tunnel_dst_new(src->version)) == NULL) {
        return NULL;
    }

    of_action_bsn_set_tunnel_dst_experimenter_get(src, &val32);
    of_action_bsn_set_tunnel_dst_experimenter_set(dst, val32);

    of_action_bsn_set_tunnel_dst_subtype_get(src, &val32);
    of_action_bsn_set_tunnel_dst_subtype_set(dst, val32);

    of_action_bsn_set_tunnel_dst_dst_get(src, &val32);
    of_action_bsn_set_tunnel_dst_dst_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_action_enqueue
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_enqueue.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_enqueue_t *
of_action_enqueue_OF_VERSION_1_0_dup(
    of_action_enqueue_t *src)
{
    of_action_enqueue_t *dst;
    of_port_no_t port_no;
    uint32_t val32;

    if ((dst = of_action_enqueue_new(src->version)) == NULL) {
        return NULL;
    }

    of_action_enqueue_port_get(src, &port_no);
    of_action_enqueue_port_set(dst, port_no);

    of_action_enqueue_queue_id_get(src, &val32);
    of_action_enqueue_queue_id_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_action_experimenter
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_experimenter.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_experimenter_t *
of_action_experimenter_OF_VERSION_1_0_dup(
    of_action_experimenter_t *src)
{
    of_action_experimenter_t *dst;
    uint32_t val32;
    of_octets_t octets;

    if ((dst = of_action_experimenter_new(src->version)) == NULL) {
        return NULL;
    }

    of_action_experimenter_experimenter_get(src, &val32);
    of_action_experimenter_experimenter_set(dst, val32);

    of_action_experimenter_data_get(src, &octets);
    of_action_experimenter_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_action_header
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_header.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_header_t *
of_action_header_OF_VERSION_1_0_dup(
    of_action_header_t *src)
{
    of_action_header_t *dst;

    if ((dst = of_action_header_new(src->version)) == NULL) {
        return NULL;
    }

    return dst;
}

/**
 * Duplicate an object of type of_action_nicira
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_nicira.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_nicira_t *
of_action_nicira_OF_VERSION_1_0_dup(
    of_action_nicira_t *src)
{
    of_action_nicira_t *dst;
    uint32_t val32;
    uint16_t val16;

    if ((dst = of_action_nicira_new(src->version)) == NULL) {
        return NULL;
    }

    of_action_nicira_experimenter_get(src, &val32);
    of_action_nicira_experimenter_set(dst, val32);

    of_action_nicira_subtype_get(src, &val16);
    of_action_nicira_subtype_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_action_nicira_dec_ttl
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_nicira_dec_ttl.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_nicira_dec_ttl_t *
of_action_nicira_dec_ttl_OF_VERSION_1_0_dup(
    of_action_nicira_dec_ttl_t *src)
{
    of_action_nicira_dec_ttl_t *dst;
    uint32_t val32;
    uint16_t val16;

    if ((dst = of_action_nicira_dec_ttl_new(src->version)) == NULL) {
        return NULL;
    }

    of_action_nicira_dec_ttl_experimenter_get(src, &val32);
    of_action_nicira_dec_ttl_experimenter_set(dst, val32);

    of_action_nicira_dec_ttl_subtype_get(src, &val16);
    of_action_nicira_dec_ttl_subtype_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_action_output
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_output.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_output_t *
of_action_output_OF_VERSION_1_0_dup(
    of_action_output_t *src)
{
    of_action_output_t *dst;
    of_port_no_t port_no;
    uint16_t val16;

    if ((dst = of_action_output_new(src->version)) == NULL) {
        return NULL;
    }

    of_action_output_port_get(src, &port_no);
    of_action_output_port_set(dst, port_no);

    of_action_output_max_len_get(src, &val16);
    of_action_output_max_len_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_action_set_dl_dst
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_set_dl_dst.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_set_dl_dst_t *
of_action_set_dl_dst_OF_VERSION_1_0_dup(
    of_action_set_dl_dst_t *src)
{
    of_action_set_dl_dst_t *dst;
    of_mac_addr_t mac_addr;

    if ((dst = of_action_set_dl_dst_new(src->version)) == NULL) {
        return NULL;
    }

    of_action_set_dl_dst_dl_addr_get(src, &mac_addr);
    of_action_set_dl_dst_dl_addr_set(dst, mac_addr);

    return dst;
}

/**
 * Duplicate an object of type of_action_set_dl_src
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_set_dl_src.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_set_dl_src_t *
of_action_set_dl_src_OF_VERSION_1_0_dup(
    of_action_set_dl_src_t *src)
{
    of_action_set_dl_src_t *dst;
    of_mac_addr_t mac_addr;

    if ((dst = of_action_set_dl_src_new(src->version)) == NULL) {
        return NULL;
    }

    of_action_set_dl_src_dl_addr_get(src, &mac_addr);
    of_action_set_dl_src_dl_addr_set(dst, mac_addr);

    return dst;
}

/**
 * Duplicate an object of type of_action_set_nw_dst
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_set_nw_dst.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_set_nw_dst_t *
of_action_set_nw_dst_OF_VERSION_1_0_dup(
    of_action_set_nw_dst_t *src)
{
    of_action_set_nw_dst_t *dst;
    uint32_t val32;

    if ((dst = of_action_set_nw_dst_new(src->version)) == NULL) {
        return NULL;
    }

    of_action_set_nw_dst_nw_addr_get(src, &val32);
    of_action_set_nw_dst_nw_addr_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_action_set_nw_src
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_set_nw_src.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_set_nw_src_t *
of_action_set_nw_src_OF_VERSION_1_0_dup(
    of_action_set_nw_src_t *src)
{
    of_action_set_nw_src_t *dst;
    uint32_t val32;

    if ((dst = of_action_set_nw_src_new(src->version)) == NULL) {
        return NULL;
    }

    of_action_set_nw_src_nw_addr_get(src, &val32);
    of_action_set_nw_src_nw_addr_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_action_set_nw_tos
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_set_nw_tos.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_set_nw_tos_t *
of_action_set_nw_tos_OF_VERSION_1_0_dup(
    of_action_set_nw_tos_t *src)
{
    of_action_set_nw_tos_t *dst;
    uint8_t val8;

    if ((dst = of_action_set_nw_tos_new(src->version)) == NULL) {
        return NULL;
    }

    of_action_set_nw_tos_nw_tos_get(src, &val8);
    of_action_set_nw_tos_nw_tos_set(dst, val8);

    return dst;
}

/**
 * Duplicate an object of type of_action_set_tp_dst
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_set_tp_dst.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_set_tp_dst_t *
of_action_set_tp_dst_OF_VERSION_1_0_dup(
    of_action_set_tp_dst_t *src)
{
    of_action_set_tp_dst_t *dst;
    uint16_t val16;

    if ((dst = of_action_set_tp_dst_new(src->version)) == NULL) {
        return NULL;
    }

    of_action_set_tp_dst_tp_port_get(src, &val16);
    of_action_set_tp_dst_tp_port_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_action_set_tp_src
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_set_tp_src.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_set_tp_src_t *
of_action_set_tp_src_OF_VERSION_1_0_dup(
    of_action_set_tp_src_t *src)
{
    of_action_set_tp_src_t *dst;
    uint16_t val16;

    if ((dst = of_action_set_tp_src_new(src->version)) == NULL) {
        return NULL;
    }

    of_action_set_tp_src_tp_port_get(src, &val16);
    of_action_set_tp_src_tp_port_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_action_set_vlan_pcp
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_set_vlan_pcp.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_set_vlan_pcp_t *
of_action_set_vlan_pcp_OF_VERSION_1_0_dup(
    of_action_set_vlan_pcp_t *src)
{
    of_action_set_vlan_pcp_t *dst;
    uint8_t val8;

    if ((dst = of_action_set_vlan_pcp_new(src->version)) == NULL) {
        return NULL;
    }

    of_action_set_vlan_pcp_vlan_pcp_get(src, &val8);
    of_action_set_vlan_pcp_vlan_pcp_set(dst, val8);

    return dst;
}

/**
 * Duplicate an object of type of_action_set_vlan_vid
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_set_vlan_vid.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_set_vlan_vid_t *
of_action_set_vlan_vid_OF_VERSION_1_0_dup(
    of_action_set_vlan_vid_t *src)
{
    of_action_set_vlan_vid_t *dst;
    uint16_t val16;

    if ((dst = of_action_set_vlan_vid_new(src->version)) == NULL) {
        return NULL;
    }

    of_action_set_vlan_vid_vlan_vid_get(src, &val16);
    of_action_set_vlan_vid_vlan_vid_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_action_strip_vlan
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_strip_vlan.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_strip_vlan_t *
of_action_strip_vlan_OF_VERSION_1_0_dup(
    of_action_strip_vlan_t *src)
{
    of_action_strip_vlan_t *dst;

    if ((dst = of_action_strip_vlan_new(src->version)) == NULL) {
        return NULL;
    }

    return dst;
}

/**
 * Duplicate an object of type of_bsn_interface
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_interface.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_interface_t *
of_bsn_interface_OF_VERSION_1_0_dup(
    of_bsn_interface_t *src)
{
    of_bsn_interface_t *dst;
    of_mac_addr_t mac_addr;
    of_port_name_t port_name;
    of_ipv4_t ipv4;

    if ((dst = of_bsn_interface_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_interface_hw_addr_get(src, &mac_addr);
    of_bsn_interface_hw_addr_set(dst, mac_addr);

    of_bsn_interface_name_get(src, &port_name);
    of_bsn_interface_name_set(dst, port_name);

    of_bsn_interface_ipv4_addr_get(src, &ipv4);
    of_bsn_interface_ipv4_addr_set(dst, ipv4);

    of_bsn_interface_ipv4_netmask_get(src, &ipv4);
    of_bsn_interface_ipv4_netmask_set(dst, ipv4);

    return dst;
}

/**
 * Duplicate a super class object of type of_bsn_vport
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_vport.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_vport_t *
of_bsn_vport_OF_VERSION_1_0_dup(
    of_bsn_vport_t *src)
{

    if (src->header.object_id == OF_BSN_VPORT_Q_IN_Q) {
        return (of_bsn_vport_t *)of_bsn_vport_q_in_q_OF_VERSION_1_0_dup(
            &src->q_in_q);
    }

    return NULL;
}

/**
 * Duplicate an object of type of_bsn_vport_header
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_vport_header.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_vport_header_t *
of_bsn_vport_header_OF_VERSION_1_0_dup(
    of_bsn_vport_header_t *src)
{
    of_bsn_vport_header_t *dst;

    if ((dst = of_bsn_vport_header_new(src->version)) == NULL) {
        return NULL;
    }

    return dst;
}

/**
 * Duplicate an object of type of_bsn_vport_q_in_q
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_vport_q_in_q.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_vport_q_in_q_t *
of_bsn_vport_q_in_q_OF_VERSION_1_0_dup(
    of_bsn_vport_q_in_q_t *src)
{
    of_bsn_vport_q_in_q_t *dst;
    uint32_t val32;
    uint16_t val16;
    of_port_name_t port_name;

    if ((dst = of_bsn_vport_q_in_q_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_vport_q_in_q_port_no_get(src, &val32);
    of_bsn_vport_q_in_q_port_no_set(dst, val32);

    of_bsn_vport_q_in_q_ingress_tpid_get(src, &val16);
    of_bsn_vport_q_in_q_ingress_tpid_set(dst, val16);

    of_bsn_vport_q_in_q_ingress_vlan_id_get(src, &val16);
    of_bsn_vport_q_in_q_ingress_vlan_id_set(dst, val16);

    of_bsn_vport_q_in_q_egress_tpid_get(src, &val16);
    of_bsn_vport_q_in_q_egress_tpid_set(dst, val16);

    of_bsn_vport_q_in_q_egress_vlan_id_get(src, &val16);
    of_bsn_vport_q_in_q_egress_vlan_id_set(dst, val16);

    of_bsn_vport_q_in_q_if_name_get(src, &port_name);
    of_bsn_vport_q_in_q_if_name_set(dst, port_name);

    return dst;
}

/**
 * Duplicate an object of type of_flow_stats_entry
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_flow_stats_entry.
 *
 * The caller is responsible for deleting the returned value
 */
of_flow_stats_entry_t *
of_flow_stats_entry_OF_VERSION_1_0_dup(
    of_flow_stats_entry_t *src)
{
    of_flow_stats_entry_t *dst;
    uint8_t val8;
    of_match_t match;
    uint32_t val32;
    uint16_t val16;
    uint64_t val64;

    of_list_action_t src_list;
    of_list_action_t *dst_list;

    if ((dst = of_flow_stats_entry_new(src->version)) == NULL) {
        return NULL;
    }

    of_flow_stats_entry_table_id_get(src, &val8);
    of_flow_stats_entry_table_id_set(dst, val8);

    of_flow_stats_entry_match_get(src, &match);
    of_flow_stats_entry_match_set(dst, &match);

    of_flow_stats_entry_duration_sec_get(src, &val32);
    of_flow_stats_entry_duration_sec_set(dst, val32);

    of_flow_stats_entry_duration_nsec_get(src, &val32);
    of_flow_stats_entry_duration_nsec_set(dst, val32);

    of_flow_stats_entry_priority_get(src, &val16);
    of_flow_stats_entry_priority_set(dst, val16);

    of_flow_stats_entry_idle_timeout_get(src, &val16);
    of_flow_stats_entry_idle_timeout_set(dst, val16);

    of_flow_stats_entry_hard_timeout_get(src, &val16);
    of_flow_stats_entry_hard_timeout_set(dst, val16);

    of_flow_stats_entry_cookie_get(src, &val64);
    of_flow_stats_entry_cookie_set(dst, val64);

    of_flow_stats_entry_packet_count_get(src, &val64);
    of_flow_stats_entry_packet_count_set(dst, val64);

    of_flow_stats_entry_byte_count_get(src, &val64);
    of_flow_stats_entry_byte_count_set(dst, val64);

    of_flow_stats_entry_actions_bind(
        src, &src_list);
    dst_list = of_list_action_OF_VERSION_1_0_dup(&src_list);
    if (dst_list == NULL) {
        of_flow_stats_entry_delete(dst);
        return NULL;
    }
    of_flow_stats_entry_actions_set(dst, dst_list);
    of_list_action_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_header
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_header.
 *
 * The caller is responsible for deleting the returned value
 */
of_header_t *
of_header_OF_VERSION_1_0_dup(
    of_header_t *src)
{
    of_header_t *dst;
    uint32_t val32;

    if ((dst = of_header_new(src->version)) == NULL) {
        return NULL;
    }

    of_header_xid_get(src, &val32);
    of_header_xid_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_match_v1
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_match_v1.
 *
 * The caller is responsible for deleting the returned value
 */
of_match_v1_t *
of_match_v1_OF_VERSION_1_0_dup(
    of_match_v1_t *src)
{
    of_match_v1_t *dst;
    of_wc_bmap_t wc_bmap;
    of_port_no_t port_no;
    of_mac_addr_t mac_addr;
    uint16_t val16;
    uint8_t val8;
    of_ipv4_t ipv4;

    if ((dst = of_match_v1_new(src->version)) == NULL) {
        return NULL;
    }

    of_match_v1_wildcards_get(src, &wc_bmap);
    of_match_v1_wildcards_set(dst, wc_bmap);

    of_match_v1_in_port_get(src, &port_no);
    of_match_v1_in_port_set(dst, port_no);

    of_match_v1_eth_src_get(src, &mac_addr);
    of_match_v1_eth_src_set(dst, mac_addr);

    of_match_v1_eth_dst_get(src, &mac_addr);
    of_match_v1_eth_dst_set(dst, mac_addr);

    of_match_v1_vlan_vid_get(src, &val16);
    of_match_v1_vlan_vid_set(dst, val16);

    of_match_v1_vlan_pcp_get(src, &val8);
    of_match_v1_vlan_pcp_set(dst, val8);

    of_match_v1_eth_type_get(src, &val16);
    of_match_v1_eth_type_set(dst, val16);

    of_match_v1_ip_dscp_get(src, &val8);
    of_match_v1_ip_dscp_set(dst, val8);

    of_match_v1_ip_proto_get(src, &val8);
    of_match_v1_ip_proto_set(dst, val8);

    of_match_v1_ipv4_src_get(src, &ipv4);
    of_match_v1_ipv4_src_set(dst, ipv4);

    of_match_v1_ipv4_dst_get(src, &ipv4);
    of_match_v1_ipv4_dst_set(dst, ipv4);

    of_match_v1_tcp_src_get(src, &val16);
    of_match_v1_tcp_src_set(dst, val16);

    of_match_v1_tcp_dst_get(src, &val16);
    of_match_v1_tcp_dst_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_packet_queue
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_packet_queue.
 *
 * The caller is responsible for deleting the returned value
 */
of_packet_queue_t *
of_packet_queue_OF_VERSION_1_0_dup(
    of_packet_queue_t *src)
{
    of_packet_queue_t *dst;
    uint32_t val32;

    of_list_queue_prop_t src_list;
    of_list_queue_prop_t *dst_list;

    if ((dst = of_packet_queue_new(src->version)) == NULL) {
        return NULL;
    }

    of_packet_queue_queue_id_get(src, &val32);
    of_packet_queue_queue_id_set(dst, val32);

    of_packet_queue_properties_bind(
        src, &src_list);
    dst_list = of_list_queue_prop_OF_VERSION_1_0_dup(&src_list);
    if (dst_list == NULL) {
        of_packet_queue_delete(dst);
        return NULL;
    }
    of_packet_queue_properties_set(dst, dst_list);
    of_list_queue_prop_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_port_desc
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_port_desc.
 *
 * The caller is responsible for deleting the returned value
 */
of_port_desc_t *
of_port_desc_OF_VERSION_1_0_dup(
    of_port_desc_t *src)
{
    of_port_desc_t *dst;
    of_port_no_t port_no;
    of_mac_addr_t mac_addr;
    of_port_name_t port_name;
    uint32_t val32;

    if ((dst = of_port_desc_new(src->version)) == NULL) {
        return NULL;
    }

    of_port_desc_port_no_get(src, &port_no);
    of_port_desc_port_no_set(dst, port_no);

    of_port_desc_hw_addr_get(src, &mac_addr);
    of_port_desc_hw_addr_set(dst, mac_addr);

    of_port_desc_name_get(src, &port_name);
    of_port_desc_name_set(dst, port_name);

    of_port_desc_config_get(src, &val32);
    of_port_desc_config_set(dst, val32);

    of_port_desc_state_get(src, &val32);
    of_port_desc_state_set(dst, val32);

    of_port_desc_curr_get(src, &val32);
    of_port_desc_curr_set(dst, val32);

    of_port_desc_advertised_get(src, &val32);
    of_port_desc_advertised_set(dst, val32);

    of_port_desc_supported_get(src, &val32);
    of_port_desc_supported_set(dst, val32);

    of_port_desc_peer_get(src, &val32);
    of_port_desc_peer_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_port_stats_entry
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_port_stats_entry.
 *
 * The caller is responsible for deleting the returned value
 */
of_port_stats_entry_t *
of_port_stats_entry_OF_VERSION_1_0_dup(
    of_port_stats_entry_t *src)
{
    of_port_stats_entry_t *dst;
    of_port_no_t port_no;
    uint64_t val64;

    if ((dst = of_port_stats_entry_new(src->version)) == NULL) {
        return NULL;
    }

    of_port_stats_entry_port_no_get(src, &port_no);
    of_port_stats_entry_port_no_set(dst, port_no);

    of_port_stats_entry_rx_packets_get(src, &val64);
    of_port_stats_entry_rx_packets_set(dst, val64);

    of_port_stats_entry_tx_packets_get(src, &val64);
    of_port_stats_entry_tx_packets_set(dst, val64);

    of_port_stats_entry_rx_bytes_get(src, &val64);
    of_port_stats_entry_rx_bytes_set(dst, val64);

    of_port_stats_entry_tx_bytes_get(src, &val64);
    of_port_stats_entry_tx_bytes_set(dst, val64);

    of_port_stats_entry_rx_dropped_get(src, &val64);
    of_port_stats_entry_rx_dropped_set(dst, val64);

    of_port_stats_entry_tx_dropped_get(src, &val64);
    of_port_stats_entry_tx_dropped_set(dst, val64);

    of_port_stats_entry_rx_errors_get(src, &val64);
    of_port_stats_entry_rx_errors_set(dst, val64);

    of_port_stats_entry_tx_errors_get(src, &val64);
    of_port_stats_entry_tx_errors_set(dst, val64);

    of_port_stats_entry_rx_frame_err_get(src, &val64);
    of_port_stats_entry_rx_frame_err_set(dst, val64);

    of_port_stats_entry_rx_over_err_get(src, &val64);
    of_port_stats_entry_rx_over_err_set(dst, val64);

    of_port_stats_entry_rx_crc_err_get(src, &val64);
    of_port_stats_entry_rx_crc_err_set(dst, val64);

    of_port_stats_entry_collisions_get(src, &val64);
    of_port_stats_entry_collisions_set(dst, val64);

    return dst;
}

/**
 * Duplicate a super class object of type of_queue_prop
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_queue_prop.
 *
 * The caller is responsible for deleting the returned value
 */
of_queue_prop_t *
of_queue_prop_OF_VERSION_1_0_dup(
    of_queue_prop_t *src)
{

    if (src->header.object_id == OF_QUEUE_PROP_MIN_RATE) {
        return (of_queue_prop_t *)of_queue_prop_min_rate_OF_VERSION_1_0_dup(
            &src->min_rate);
    }

    return NULL;
}

/**
 * Duplicate an object of type of_queue_prop_header
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_queue_prop_header.
 *
 * The caller is responsible for deleting the returned value
 */
of_queue_prop_header_t *
of_queue_prop_header_OF_VERSION_1_0_dup(
    of_queue_prop_header_t *src)
{
    of_queue_prop_header_t *dst;

    if ((dst = of_queue_prop_header_new(src->version)) == NULL) {
        return NULL;
    }

    return dst;
}

/**
 * Duplicate an object of type of_queue_prop_min_rate
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_queue_prop_min_rate.
 *
 * The caller is responsible for deleting the returned value
 */
of_queue_prop_min_rate_t *
of_queue_prop_min_rate_OF_VERSION_1_0_dup(
    of_queue_prop_min_rate_t *src)
{
    of_queue_prop_min_rate_t *dst;
    uint16_t val16;

    if ((dst = of_queue_prop_min_rate_new(src->version)) == NULL) {
        return NULL;
    }

    of_queue_prop_min_rate_rate_get(src, &val16);
    of_queue_prop_min_rate_rate_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_queue_stats_entry
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_queue_stats_entry.
 *
 * The caller is responsible for deleting the returned value
 */
of_queue_stats_entry_t *
of_queue_stats_entry_OF_VERSION_1_0_dup(
    of_queue_stats_entry_t *src)
{
    of_queue_stats_entry_t *dst;
    of_port_no_t port_no;
    uint32_t val32;
    uint64_t val64;

    if ((dst = of_queue_stats_entry_new(src->version)) == NULL) {
        return NULL;
    }

    of_queue_stats_entry_port_no_get(src, &port_no);
    of_queue_stats_entry_port_no_set(dst, port_no);

    of_queue_stats_entry_queue_id_get(src, &val32);
    of_queue_stats_entry_queue_id_set(dst, val32);

    of_queue_stats_entry_tx_bytes_get(src, &val64);
    of_queue_stats_entry_tx_bytes_set(dst, val64);

    of_queue_stats_entry_tx_packets_get(src, &val64);
    of_queue_stats_entry_tx_packets_set(dst, val64);

    of_queue_stats_entry_tx_errors_get(src, &val64);
    of_queue_stats_entry_tx_errors_set(dst, val64);

    return dst;
}

/**
 * Duplicate an object of type of_table_stats_entry
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_table_stats_entry.
 *
 * The caller is responsible for deleting the returned value
 */
of_table_stats_entry_t *
of_table_stats_entry_OF_VERSION_1_0_dup(
    of_table_stats_entry_t *src)
{
    of_table_stats_entry_t *dst;
    uint8_t val8;
    of_table_name_t table_name;
    of_wc_bmap_t wc_bmap;
    uint32_t val32;
    uint64_t val64;

    if ((dst = of_table_stats_entry_new(src->version)) == NULL) {
        return NULL;
    }

    of_table_stats_entry_table_id_get(src, &val8);
    of_table_stats_entry_table_id_set(dst, val8);

    of_table_stats_entry_name_get(src, &table_name);
    of_table_stats_entry_name_set(dst, table_name);

    of_table_stats_entry_wildcards_get(src, &wc_bmap);
    of_table_stats_entry_wildcards_set(dst, wc_bmap);

    of_table_stats_entry_max_entries_get(src, &val32);
    of_table_stats_entry_max_entries_set(dst, val32);

    of_table_stats_entry_active_count_get(src, &val32);
    of_table_stats_entry_active_count_set(dst, val32);

    of_table_stats_entry_lookup_count_get(src, &val64);
    of_table_stats_entry_lookup_count_set(dst, val64);

    of_table_stats_entry_matched_count_get(src, &val64);
    of_table_stats_entry_matched_count_set(dst, val64);

    return dst;
}

/**
 * Duplicate a list of type of_list_action
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_list_action.
 *
 * The caller is responsible for deleting the returned value
 */
of_list_action_t *
of_list_action_OF_VERSION_1_0_dup(
    of_list_action_t *src)
{
    of_action_t src_elt;
    of_action_t *dst_elt;
    int rv;
    of_list_action_t *dst;

    if ((dst = of_list_action_new(src->version)) == NULL) {
        return NULL;
    }

    OF_LIST_ACTION_ITER(src, &src_elt, rv) {
        if ((dst_elt = of_action_OF_VERSION_1_0_dup(&src_elt)) == NULL) {
            of_object_delete((of_object_t *)dst);
            return NULL;
        }
        _TRY_FREE(of_list_action_append(dst, dst_elt),
            dst, NULL);
        of_object_delete((of_object_t *)dst_elt);
    }

    return dst;
}

/**
 * Duplicate a list of type of_list_bsn_interface
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_list_bsn_interface.
 *
 * The caller is responsible for deleting the returned value
 */
of_list_bsn_interface_t *
of_list_bsn_interface_OF_VERSION_1_0_dup(
    of_list_bsn_interface_t *src)
{
    of_bsn_interface_t src_elt;
    of_bsn_interface_t *dst_elt;
    int rv;
    of_list_bsn_interface_t *dst;

    if ((dst = of_list_bsn_interface_new(src->version)) == NULL) {
        return NULL;
    }

    OF_LIST_BSN_INTERFACE_ITER(src, &src_elt, rv) {
        if ((dst_elt = of_bsn_interface_OF_VERSION_1_0_dup(&src_elt)) == NULL) {
            of_object_delete((of_object_t *)dst);
            return NULL;
        }
        _TRY_FREE(of_list_bsn_interface_append(dst, dst_elt),
            dst, NULL);
        of_object_delete((of_object_t *)dst_elt);
    }

    return dst;
}

/**
 * Duplicate a list of type of_list_flow_stats_entry
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_list_flow_stats_entry.
 *
 * The caller is responsible for deleting the returned value
 */
of_list_flow_stats_entry_t *
of_list_flow_stats_entry_OF_VERSION_1_0_dup(
    of_list_flow_stats_entry_t *src)
{
    of_flow_stats_entry_t src_elt;
    of_flow_stats_entry_t *dst_elt;
    int rv;
    of_list_flow_stats_entry_t *dst;

    if ((dst = of_list_flow_stats_entry_new(src->version)) == NULL) {
        return NULL;
    }

    OF_LIST_FLOW_STATS_ENTRY_ITER(src, &src_elt, rv) {
        if ((dst_elt = of_flow_stats_entry_OF_VERSION_1_0_dup(&src_elt)) == NULL) {
            of_object_delete((of_object_t *)dst);
            return NULL;
        }
        _TRY_FREE(of_list_flow_stats_entry_append(dst, dst_elt),
            dst, NULL);
        of_object_delete((of_object_t *)dst_elt);
    }

    return dst;
}

/**
 * Duplicate a list of type of_list_packet_queue
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_list_packet_queue.
 *
 * The caller is responsible for deleting the returned value
 */
of_list_packet_queue_t *
of_list_packet_queue_OF_VERSION_1_0_dup(
    of_list_packet_queue_t *src)
{
    of_packet_queue_t src_elt;
    of_packet_queue_t *dst_elt;
    int rv;
    of_list_packet_queue_t *dst;

    if ((dst = of_list_packet_queue_new(src->version)) == NULL) {
        return NULL;
    }

    OF_LIST_PACKET_QUEUE_ITER(src, &src_elt, rv) {
        if ((dst_elt = of_packet_queue_OF_VERSION_1_0_dup(&src_elt)) == NULL) {
            of_object_delete((of_object_t *)dst);
            return NULL;
        }
        _TRY_FREE(of_list_packet_queue_append(dst, dst_elt),
            dst, NULL);
        of_object_delete((of_object_t *)dst_elt);
    }

    return dst;
}

/**
 * Duplicate a list of type of_list_port_desc
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_list_port_desc.
 *
 * The caller is responsible for deleting the returned value
 */
of_list_port_desc_t *
of_list_port_desc_OF_VERSION_1_0_dup(
    of_list_port_desc_t *src)
{
    of_port_desc_t src_elt;
    of_port_desc_t *dst_elt;
    int rv;
    of_list_port_desc_t *dst;

    if ((dst = of_list_port_desc_new(src->version)) == NULL) {
        return NULL;
    }

    OF_LIST_PORT_DESC_ITER(src, &src_elt, rv) {
        if ((dst_elt = of_port_desc_OF_VERSION_1_0_dup(&src_elt)) == NULL) {
            of_object_delete((of_object_t *)dst);
            return NULL;
        }
        _TRY_FREE(of_list_port_desc_append(dst, dst_elt),
            dst, NULL);
        of_object_delete((of_object_t *)dst_elt);
    }

    return dst;
}

/**
 * Duplicate a list of type of_list_port_stats_entry
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_list_port_stats_entry.
 *
 * The caller is responsible for deleting the returned value
 */
of_list_port_stats_entry_t *
of_list_port_stats_entry_OF_VERSION_1_0_dup(
    of_list_port_stats_entry_t *src)
{
    of_port_stats_entry_t src_elt;
    of_port_stats_entry_t *dst_elt;
    int rv;
    of_list_port_stats_entry_t *dst;

    if ((dst = of_list_port_stats_entry_new(src->version)) == NULL) {
        return NULL;
    }

    OF_LIST_PORT_STATS_ENTRY_ITER(src, &src_elt, rv) {
        if ((dst_elt = of_port_stats_entry_OF_VERSION_1_0_dup(&src_elt)) == NULL) {
            of_object_delete((of_object_t *)dst);
            return NULL;
        }
        _TRY_FREE(of_list_port_stats_entry_append(dst, dst_elt),
            dst, NULL);
        of_object_delete((of_object_t *)dst_elt);
    }

    return dst;
}

/**
 * Duplicate a list of type of_list_queue_prop
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_list_queue_prop.
 *
 * The caller is responsible for deleting the returned value
 */
of_list_queue_prop_t *
of_list_queue_prop_OF_VERSION_1_0_dup(
    of_list_queue_prop_t *src)
{
    of_queue_prop_t src_elt;
    of_queue_prop_t *dst_elt;
    int rv;
    of_list_queue_prop_t *dst;

    if ((dst = of_list_queue_prop_new(src->version)) == NULL) {
        return NULL;
    }

    OF_LIST_QUEUE_PROP_ITER(src, &src_elt, rv) {
        if ((dst_elt = of_queue_prop_OF_VERSION_1_0_dup(&src_elt)) == NULL) {
            of_object_delete((of_object_t *)dst);
            return NULL;
        }
        _TRY_FREE(of_list_queue_prop_append(dst, dst_elt),
            dst, NULL);
        of_object_delete((of_object_t *)dst_elt);
    }

    return dst;
}

/**
 * Duplicate a list of type of_list_queue_stats_entry
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_list_queue_stats_entry.
 *
 * The caller is responsible for deleting the returned value
 */
of_list_queue_stats_entry_t *
of_list_queue_stats_entry_OF_VERSION_1_0_dup(
    of_list_queue_stats_entry_t *src)
{
    of_queue_stats_entry_t src_elt;
    of_queue_stats_entry_t *dst_elt;
    int rv;
    of_list_queue_stats_entry_t *dst;

    if ((dst = of_list_queue_stats_entry_new(src->version)) == NULL) {
        return NULL;
    }

    OF_LIST_QUEUE_STATS_ENTRY_ITER(src, &src_elt, rv) {
        if ((dst_elt = of_queue_stats_entry_OF_VERSION_1_0_dup(&src_elt)) == NULL) {
            of_object_delete((of_object_t *)dst);
            return NULL;
        }
        _TRY_FREE(of_list_queue_stats_entry_append(dst, dst_elt),
            dst, NULL);
        of_object_delete((of_object_t *)dst_elt);
    }

    return dst;
}

/**
 * Duplicate a list of type of_list_table_stats_entry
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_list_table_stats_entry.
 *
 * The caller is responsible for deleting the returned value
 */
of_list_table_stats_entry_t *
of_list_table_stats_entry_OF_VERSION_1_0_dup(
    of_list_table_stats_entry_t *src)
{
    of_table_stats_entry_t src_elt;
    of_table_stats_entry_t *dst_elt;
    int rv;
    of_list_table_stats_entry_t *dst;

    if ((dst = of_list_table_stats_entry_new(src->version)) == NULL) {
        return NULL;
    }

    OF_LIST_TABLE_STATS_ENTRY_ITER(src, &src_elt, rv) {
        if ((dst_elt = of_table_stats_entry_OF_VERSION_1_0_dup(&src_elt)) == NULL) {
            of_object_delete((of_object_t *)dst);
            return NULL;
        }
        _TRY_FREE(of_list_table_stats_entry_append(dst, dst_elt),
            dst, NULL);
        of_object_delete((of_object_t *)dst_elt);
    }

    return dst;
}

/**
 * Duplicate an object of type of_aggregate_stats_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_aggregate_stats_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_aggregate_stats_reply_t *
of_aggregate_stats_reply_OF_VERSION_1_1_dup(
    of_aggregate_stats_reply_t *src)
{
    of_aggregate_stats_reply_t *dst;
    uint32_t val32;
    uint16_t val16;
    uint64_t val64;

    if ((dst = of_aggregate_stats_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_aggregate_stats_reply_xid_get(src, &val32);
    of_aggregate_stats_reply_xid_set(dst, val32);

    of_aggregate_stats_reply_flags_get(src, &val16);
    of_aggregate_stats_reply_flags_set(dst, val16);

    of_aggregate_stats_reply_packet_count_get(src, &val64);
    of_aggregate_stats_reply_packet_count_set(dst, val64);

    of_aggregate_stats_reply_byte_count_get(src, &val64);
    of_aggregate_stats_reply_byte_count_set(dst, val64);

    of_aggregate_stats_reply_flow_count_get(src, &val32);
    of_aggregate_stats_reply_flow_count_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_aggregate_stats_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_aggregate_stats_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_aggregate_stats_request_t *
of_aggregate_stats_request_OF_VERSION_1_1_dup(
    of_aggregate_stats_request_t *src)
{
    of_aggregate_stats_request_t *dst;
    uint32_t val32;
    uint16_t val16;
    uint8_t val8;
    of_port_no_t port_no;
    uint64_t val64;
    of_match_t match;

    if ((dst = of_aggregate_stats_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_aggregate_stats_request_xid_get(src, &val32);
    of_aggregate_stats_request_xid_set(dst, val32);

    of_aggregate_stats_request_flags_get(src, &val16);
    of_aggregate_stats_request_flags_set(dst, val16);

    of_aggregate_stats_request_table_id_get(src, &val8);
    of_aggregate_stats_request_table_id_set(dst, val8);

    of_aggregate_stats_request_out_port_get(src, &port_no);
    of_aggregate_stats_request_out_port_set(dst, port_no);

    of_aggregate_stats_request_out_group_get(src, &val32);
    of_aggregate_stats_request_out_group_set(dst, val32);

    of_aggregate_stats_request_cookie_get(src, &val64);
    of_aggregate_stats_request_cookie_set(dst, val64);

    of_aggregate_stats_request_cookie_mask_get(src, &val64);
    of_aggregate_stats_request_cookie_mask_set(dst, val64);

    of_aggregate_stats_request_match_get(src, &match);
    of_aggregate_stats_request_match_set(dst, &match);

    return dst;
}

/**
 * Duplicate an object of type of_bad_action_error_msg
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bad_action_error_msg.
 *
 * The caller is responsible for deleting the returned value
 */
of_bad_action_error_msg_t *
of_bad_action_error_msg_OF_VERSION_1_1_dup(
    of_bad_action_error_msg_t *src)
{
    of_bad_action_error_msg_t *dst;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    if ((dst = of_bad_action_error_msg_new(src->version)) == NULL) {
        return NULL;
    }

    of_bad_action_error_msg_xid_get(src, &val32);
    of_bad_action_error_msg_xid_set(dst, val32);

    of_bad_action_error_msg_code_get(src, &val16);
    of_bad_action_error_msg_code_set(dst, val16);

    of_bad_action_error_msg_data_get(src, &octets);
    of_bad_action_error_msg_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_bad_instruction_error_msg
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bad_instruction_error_msg.
 *
 * The caller is responsible for deleting the returned value
 */
of_bad_instruction_error_msg_t *
of_bad_instruction_error_msg_OF_VERSION_1_1_dup(
    of_bad_instruction_error_msg_t *src)
{
    of_bad_instruction_error_msg_t *dst;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    if ((dst = of_bad_instruction_error_msg_new(src->version)) == NULL) {
        return NULL;
    }

    of_bad_instruction_error_msg_xid_get(src, &val32);
    of_bad_instruction_error_msg_xid_set(dst, val32);

    of_bad_instruction_error_msg_code_get(src, &val16);
    of_bad_instruction_error_msg_code_set(dst, val16);

    of_bad_instruction_error_msg_data_get(src, &octets);
    of_bad_instruction_error_msg_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_bad_match_error_msg
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bad_match_error_msg.
 *
 * The caller is responsible for deleting the returned value
 */
of_bad_match_error_msg_t *
of_bad_match_error_msg_OF_VERSION_1_1_dup(
    of_bad_match_error_msg_t *src)
{
    of_bad_match_error_msg_t *dst;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    if ((dst = of_bad_match_error_msg_new(src->version)) == NULL) {
        return NULL;
    }

    of_bad_match_error_msg_xid_get(src, &val32);
    of_bad_match_error_msg_xid_set(dst, val32);

    of_bad_match_error_msg_code_get(src, &val16);
    of_bad_match_error_msg_code_set(dst, val16);

    of_bad_match_error_msg_data_get(src, &octets);
    of_bad_match_error_msg_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_bad_request_error_msg
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bad_request_error_msg.
 *
 * The caller is responsible for deleting the returned value
 */
of_bad_request_error_msg_t *
of_bad_request_error_msg_OF_VERSION_1_1_dup(
    of_bad_request_error_msg_t *src)
{
    of_bad_request_error_msg_t *dst;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    if ((dst = of_bad_request_error_msg_new(src->version)) == NULL) {
        return NULL;
    }

    of_bad_request_error_msg_xid_get(src, &val32);
    of_bad_request_error_msg_xid_set(dst, val32);

    of_bad_request_error_msg_code_get(src, &val16);
    of_bad_request_error_msg_code_set(dst, val16);

    of_bad_request_error_msg_data_get(src, &octets);
    of_bad_request_error_msg_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_barrier_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_barrier_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_barrier_reply_t *
of_barrier_reply_OF_VERSION_1_1_dup(
    of_barrier_reply_t *src)
{
    of_barrier_reply_t *dst;
    uint32_t val32;

    if ((dst = of_barrier_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_barrier_reply_xid_get(src, &val32);
    of_barrier_reply_xid_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_barrier_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_barrier_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_barrier_request_t *
of_barrier_request_OF_VERSION_1_1_dup(
    of_barrier_request_t *src)
{
    of_barrier_request_t *dst;
    uint32_t val32;

    if ((dst = of_barrier_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_barrier_request_xid_get(src, &val32);
    of_barrier_request_xid_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_bw_clear_data_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_bw_clear_data_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_bw_clear_data_reply_t *
of_bsn_bw_clear_data_reply_OF_VERSION_1_1_dup(
    of_bsn_bw_clear_data_reply_t *src)
{
    of_bsn_bw_clear_data_reply_t *dst;
    uint32_t val32;

    if ((dst = of_bsn_bw_clear_data_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_bw_clear_data_reply_xid_get(src, &val32);
    of_bsn_bw_clear_data_reply_xid_set(dst, val32);

    of_bsn_bw_clear_data_reply_experimenter_get(src, &val32);
    of_bsn_bw_clear_data_reply_experimenter_set(dst, val32);

    of_bsn_bw_clear_data_reply_subtype_get(src, &val32);
    of_bsn_bw_clear_data_reply_subtype_set(dst, val32);

    of_bsn_bw_clear_data_reply_status_get(src, &val32);
    of_bsn_bw_clear_data_reply_status_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_bw_clear_data_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_bw_clear_data_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_bw_clear_data_request_t *
of_bsn_bw_clear_data_request_OF_VERSION_1_1_dup(
    of_bsn_bw_clear_data_request_t *src)
{
    of_bsn_bw_clear_data_request_t *dst;
    uint32_t val32;

    if ((dst = of_bsn_bw_clear_data_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_bw_clear_data_request_xid_get(src, &val32);
    of_bsn_bw_clear_data_request_xid_set(dst, val32);

    of_bsn_bw_clear_data_request_experimenter_get(src, &val32);
    of_bsn_bw_clear_data_request_experimenter_set(dst, val32);

    of_bsn_bw_clear_data_request_subtype_get(src, &val32);
    of_bsn_bw_clear_data_request_subtype_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_bw_enable_get_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_bw_enable_get_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_bw_enable_get_reply_t *
of_bsn_bw_enable_get_reply_OF_VERSION_1_1_dup(
    of_bsn_bw_enable_get_reply_t *src)
{
    of_bsn_bw_enable_get_reply_t *dst;
    uint32_t val32;

    if ((dst = of_bsn_bw_enable_get_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_bw_enable_get_reply_xid_get(src, &val32);
    of_bsn_bw_enable_get_reply_xid_set(dst, val32);

    of_bsn_bw_enable_get_reply_experimenter_get(src, &val32);
    of_bsn_bw_enable_get_reply_experimenter_set(dst, val32);

    of_bsn_bw_enable_get_reply_subtype_get(src, &val32);
    of_bsn_bw_enable_get_reply_subtype_set(dst, val32);

    of_bsn_bw_enable_get_reply_enabled_get(src, &val32);
    of_bsn_bw_enable_get_reply_enabled_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_bw_enable_get_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_bw_enable_get_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_bw_enable_get_request_t *
of_bsn_bw_enable_get_request_OF_VERSION_1_1_dup(
    of_bsn_bw_enable_get_request_t *src)
{
    of_bsn_bw_enable_get_request_t *dst;
    uint32_t val32;

    if ((dst = of_bsn_bw_enable_get_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_bw_enable_get_request_xid_get(src, &val32);
    of_bsn_bw_enable_get_request_xid_set(dst, val32);

    of_bsn_bw_enable_get_request_experimenter_get(src, &val32);
    of_bsn_bw_enable_get_request_experimenter_set(dst, val32);

    of_bsn_bw_enable_get_request_subtype_get(src, &val32);
    of_bsn_bw_enable_get_request_subtype_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_bw_enable_set_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_bw_enable_set_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_bw_enable_set_reply_t *
of_bsn_bw_enable_set_reply_OF_VERSION_1_1_dup(
    of_bsn_bw_enable_set_reply_t *src)
{
    of_bsn_bw_enable_set_reply_t *dst;
    uint32_t val32;

    if ((dst = of_bsn_bw_enable_set_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_bw_enable_set_reply_xid_get(src, &val32);
    of_bsn_bw_enable_set_reply_xid_set(dst, val32);

    of_bsn_bw_enable_set_reply_experimenter_get(src, &val32);
    of_bsn_bw_enable_set_reply_experimenter_set(dst, val32);

    of_bsn_bw_enable_set_reply_subtype_get(src, &val32);
    of_bsn_bw_enable_set_reply_subtype_set(dst, val32);

    of_bsn_bw_enable_set_reply_enable_get(src, &val32);
    of_bsn_bw_enable_set_reply_enable_set(dst, val32);

    of_bsn_bw_enable_set_reply_status_get(src, &val32);
    of_bsn_bw_enable_set_reply_status_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_bw_enable_set_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_bw_enable_set_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_bw_enable_set_request_t *
of_bsn_bw_enable_set_request_OF_VERSION_1_1_dup(
    of_bsn_bw_enable_set_request_t *src)
{
    of_bsn_bw_enable_set_request_t *dst;
    uint32_t val32;

    if ((dst = of_bsn_bw_enable_set_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_bw_enable_set_request_xid_get(src, &val32);
    of_bsn_bw_enable_set_request_xid_set(dst, val32);

    of_bsn_bw_enable_set_request_experimenter_get(src, &val32);
    of_bsn_bw_enable_set_request_experimenter_set(dst, val32);

    of_bsn_bw_enable_set_request_subtype_get(src, &val32);
    of_bsn_bw_enable_set_request_subtype_set(dst, val32);

    of_bsn_bw_enable_set_request_enable_get(src, &val32);
    of_bsn_bw_enable_set_request_enable_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_get_interfaces_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_get_interfaces_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_get_interfaces_reply_t *
of_bsn_get_interfaces_reply_OF_VERSION_1_1_dup(
    of_bsn_get_interfaces_reply_t *src)
{
    of_bsn_get_interfaces_reply_t *dst;
    uint32_t val32;

    of_list_bsn_interface_t src_list;
    of_list_bsn_interface_t *dst_list;

    if ((dst = of_bsn_get_interfaces_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_get_interfaces_reply_xid_get(src, &val32);
    of_bsn_get_interfaces_reply_xid_set(dst, val32);

    of_bsn_get_interfaces_reply_experimenter_get(src, &val32);
    of_bsn_get_interfaces_reply_experimenter_set(dst, val32);

    of_bsn_get_interfaces_reply_subtype_get(src, &val32);
    of_bsn_get_interfaces_reply_subtype_set(dst, val32);

    of_bsn_get_interfaces_reply_interfaces_bind(
        src, &src_list);
    dst_list = of_list_bsn_interface_OF_VERSION_1_1_dup(&src_list);
    if (dst_list == NULL) {
        of_bsn_get_interfaces_reply_delete(dst);
        return NULL;
    }
    of_bsn_get_interfaces_reply_interfaces_set(dst, dst_list);
    of_list_bsn_interface_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_get_interfaces_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_get_interfaces_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_get_interfaces_request_t *
of_bsn_get_interfaces_request_OF_VERSION_1_1_dup(
    of_bsn_get_interfaces_request_t *src)
{
    of_bsn_get_interfaces_request_t *dst;
    uint32_t val32;

    if ((dst = of_bsn_get_interfaces_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_get_interfaces_request_xid_get(src, &val32);
    of_bsn_get_interfaces_request_xid_set(dst, val32);

    of_bsn_get_interfaces_request_experimenter_get(src, &val32);
    of_bsn_get_interfaces_request_experimenter_set(dst, val32);

    of_bsn_get_interfaces_request_subtype_get(src, &val32);
    of_bsn_get_interfaces_request_subtype_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_get_mirroring_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_get_mirroring_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_get_mirroring_reply_t *
of_bsn_get_mirroring_reply_OF_VERSION_1_1_dup(
    of_bsn_get_mirroring_reply_t *src)
{
    of_bsn_get_mirroring_reply_t *dst;
    uint32_t val32;
    uint8_t val8;

    if ((dst = of_bsn_get_mirroring_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_get_mirroring_reply_xid_get(src, &val32);
    of_bsn_get_mirroring_reply_xid_set(dst, val32);

    of_bsn_get_mirroring_reply_experimenter_get(src, &val32);
    of_bsn_get_mirroring_reply_experimenter_set(dst, val32);

    of_bsn_get_mirroring_reply_subtype_get(src, &val32);
    of_bsn_get_mirroring_reply_subtype_set(dst, val32);

    of_bsn_get_mirroring_reply_report_mirror_ports_get(src, &val8);
    of_bsn_get_mirroring_reply_report_mirror_ports_set(dst, val8);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_get_mirroring_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_get_mirroring_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_get_mirroring_request_t *
of_bsn_get_mirroring_request_OF_VERSION_1_1_dup(
    of_bsn_get_mirroring_request_t *src)
{
    of_bsn_get_mirroring_request_t *dst;
    uint32_t val32;
    uint8_t val8;

    if ((dst = of_bsn_get_mirroring_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_get_mirroring_request_xid_get(src, &val32);
    of_bsn_get_mirroring_request_xid_set(dst, val32);

    of_bsn_get_mirroring_request_experimenter_get(src, &val32);
    of_bsn_get_mirroring_request_experimenter_set(dst, val32);

    of_bsn_get_mirroring_request_subtype_get(src, &val32);
    of_bsn_get_mirroring_request_subtype_set(dst, val32);

    of_bsn_get_mirroring_request_report_mirror_ports_get(src, &val8);
    of_bsn_get_mirroring_request_report_mirror_ports_set(dst, val8);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_header
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_header.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_header_t *
of_bsn_header_OF_VERSION_1_1_dup(
    of_bsn_header_t *src)
{
    of_bsn_header_t *dst;
    uint32_t val32;

    if ((dst = of_bsn_header_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_header_xid_get(src, &val32);
    of_bsn_header_xid_set(dst, val32);

    of_bsn_header_experimenter_get(src, &val32);
    of_bsn_header_experimenter_set(dst, val32);

    of_bsn_header_subtype_get(src, &val32);
    of_bsn_header_subtype_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_pdu_rx_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_pdu_rx_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_pdu_rx_reply_t *
of_bsn_pdu_rx_reply_OF_VERSION_1_1_dup(
    of_bsn_pdu_rx_reply_t *src)
{
    of_bsn_pdu_rx_reply_t *dst;
    uint32_t val32;

    if ((dst = of_bsn_pdu_rx_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_pdu_rx_reply_xid_get(src, &val32);
    of_bsn_pdu_rx_reply_xid_set(dst, val32);

    of_bsn_pdu_rx_reply_experimenter_get(src, &val32);
    of_bsn_pdu_rx_reply_experimenter_set(dst, val32);

    of_bsn_pdu_rx_reply_subtype_get(src, &val32);
    of_bsn_pdu_rx_reply_subtype_set(dst, val32);

    of_bsn_pdu_rx_reply_status_get(src, &val32);
    of_bsn_pdu_rx_reply_status_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_pdu_rx_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_pdu_rx_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_pdu_rx_request_t *
of_bsn_pdu_rx_request_OF_VERSION_1_1_dup(
    of_bsn_pdu_rx_request_t *src)
{
    of_bsn_pdu_rx_request_t *dst;
    uint32_t val32;
    of_port_no_t port_no;
    uint8_t val8;
    of_octets_t octets;

    if ((dst = of_bsn_pdu_rx_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_pdu_rx_request_xid_get(src, &val32);
    of_bsn_pdu_rx_request_xid_set(dst, val32);

    of_bsn_pdu_rx_request_experimenter_get(src, &val32);
    of_bsn_pdu_rx_request_experimenter_set(dst, val32);

    of_bsn_pdu_rx_request_subtype_get(src, &val32);
    of_bsn_pdu_rx_request_subtype_set(dst, val32);

    of_bsn_pdu_rx_request_timeout_ms_get(src, &val32);
    of_bsn_pdu_rx_request_timeout_ms_set(dst, val32);

    of_bsn_pdu_rx_request_port_no_get(src, &port_no);
    of_bsn_pdu_rx_request_port_no_set(dst, port_no);

    of_bsn_pdu_rx_request_slot_num_get(src, &val8);
    of_bsn_pdu_rx_request_slot_num_set(dst, val8);

    of_bsn_pdu_rx_request_data_get(src, &octets);
    of_bsn_pdu_rx_request_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_pdu_rx_timeout
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_pdu_rx_timeout.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_pdu_rx_timeout_t *
of_bsn_pdu_rx_timeout_OF_VERSION_1_1_dup(
    of_bsn_pdu_rx_timeout_t *src)
{
    of_bsn_pdu_rx_timeout_t *dst;
    uint32_t val32;
    of_port_no_t port_no;
    uint8_t val8;

    if ((dst = of_bsn_pdu_rx_timeout_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_pdu_rx_timeout_xid_get(src, &val32);
    of_bsn_pdu_rx_timeout_xid_set(dst, val32);

    of_bsn_pdu_rx_timeout_experimenter_get(src, &val32);
    of_bsn_pdu_rx_timeout_experimenter_set(dst, val32);

    of_bsn_pdu_rx_timeout_subtype_get(src, &val32);
    of_bsn_pdu_rx_timeout_subtype_set(dst, val32);

    of_bsn_pdu_rx_timeout_port_no_get(src, &port_no);
    of_bsn_pdu_rx_timeout_port_no_set(dst, port_no);

    of_bsn_pdu_rx_timeout_slot_num_get(src, &val8);
    of_bsn_pdu_rx_timeout_slot_num_set(dst, val8);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_pdu_tx_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_pdu_tx_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_pdu_tx_reply_t *
of_bsn_pdu_tx_reply_OF_VERSION_1_1_dup(
    of_bsn_pdu_tx_reply_t *src)
{
    of_bsn_pdu_tx_reply_t *dst;
    uint32_t val32;

    if ((dst = of_bsn_pdu_tx_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_pdu_tx_reply_xid_get(src, &val32);
    of_bsn_pdu_tx_reply_xid_set(dst, val32);

    of_bsn_pdu_tx_reply_experimenter_get(src, &val32);
    of_bsn_pdu_tx_reply_experimenter_set(dst, val32);

    of_bsn_pdu_tx_reply_subtype_get(src, &val32);
    of_bsn_pdu_tx_reply_subtype_set(dst, val32);

    of_bsn_pdu_tx_reply_status_get(src, &val32);
    of_bsn_pdu_tx_reply_status_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_pdu_tx_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_pdu_tx_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_pdu_tx_request_t *
of_bsn_pdu_tx_request_OF_VERSION_1_1_dup(
    of_bsn_pdu_tx_request_t *src)
{
    of_bsn_pdu_tx_request_t *dst;
    uint32_t val32;
    of_port_no_t port_no;
    uint8_t val8;
    of_octets_t octets;

    if ((dst = of_bsn_pdu_tx_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_pdu_tx_request_xid_get(src, &val32);
    of_bsn_pdu_tx_request_xid_set(dst, val32);

    of_bsn_pdu_tx_request_experimenter_get(src, &val32);
    of_bsn_pdu_tx_request_experimenter_set(dst, val32);

    of_bsn_pdu_tx_request_subtype_get(src, &val32);
    of_bsn_pdu_tx_request_subtype_set(dst, val32);

    of_bsn_pdu_tx_request_tx_interval_ms_get(src, &val32);
    of_bsn_pdu_tx_request_tx_interval_ms_set(dst, val32);

    of_bsn_pdu_tx_request_port_no_get(src, &port_no);
    of_bsn_pdu_tx_request_port_no_set(dst, port_no);

    of_bsn_pdu_tx_request_slot_num_get(src, &val8);
    of_bsn_pdu_tx_request_slot_num_set(dst, val8);

    of_bsn_pdu_tx_request_data_get(src, &octets);
    of_bsn_pdu_tx_request_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_set_mirroring
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_set_mirroring.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_set_mirroring_t *
of_bsn_set_mirroring_OF_VERSION_1_1_dup(
    of_bsn_set_mirroring_t *src)
{
    of_bsn_set_mirroring_t *dst;
    uint32_t val32;
    uint8_t val8;

    if ((dst = of_bsn_set_mirroring_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_set_mirroring_xid_get(src, &val32);
    of_bsn_set_mirroring_xid_set(dst, val32);

    of_bsn_set_mirroring_experimenter_get(src, &val32);
    of_bsn_set_mirroring_experimenter_set(dst, val32);

    of_bsn_set_mirroring_subtype_get(src, &val32);
    of_bsn_set_mirroring_subtype_set(dst, val32);

    of_bsn_set_mirroring_report_mirror_ports_get(src, &val8);
    of_bsn_set_mirroring_report_mirror_ports_set(dst, val8);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_set_pktin_suppression_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_set_pktin_suppression_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_set_pktin_suppression_reply_t *
of_bsn_set_pktin_suppression_reply_OF_VERSION_1_1_dup(
    of_bsn_set_pktin_suppression_reply_t *src)
{
    of_bsn_set_pktin_suppression_reply_t *dst;
    uint32_t val32;

    if ((dst = of_bsn_set_pktin_suppression_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_set_pktin_suppression_reply_xid_get(src, &val32);
    of_bsn_set_pktin_suppression_reply_xid_set(dst, val32);

    of_bsn_set_pktin_suppression_reply_experimenter_get(src, &val32);
    of_bsn_set_pktin_suppression_reply_experimenter_set(dst, val32);

    of_bsn_set_pktin_suppression_reply_subtype_get(src, &val32);
    of_bsn_set_pktin_suppression_reply_subtype_set(dst, val32);

    of_bsn_set_pktin_suppression_reply_status_get(src, &val32);
    of_bsn_set_pktin_suppression_reply_status_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_set_pktin_suppression_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_set_pktin_suppression_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_set_pktin_suppression_request_t *
of_bsn_set_pktin_suppression_request_OF_VERSION_1_1_dup(
    of_bsn_set_pktin_suppression_request_t *src)
{
    of_bsn_set_pktin_suppression_request_t *dst;
    uint32_t val32;
    uint8_t val8;
    uint16_t val16;
    uint64_t val64;

    if ((dst = of_bsn_set_pktin_suppression_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_set_pktin_suppression_request_xid_get(src, &val32);
    of_bsn_set_pktin_suppression_request_xid_set(dst, val32);

    of_bsn_set_pktin_suppression_request_experimenter_get(src, &val32);
    of_bsn_set_pktin_suppression_request_experimenter_set(dst, val32);

    of_bsn_set_pktin_suppression_request_subtype_get(src, &val32);
    of_bsn_set_pktin_suppression_request_subtype_set(dst, val32);

    of_bsn_set_pktin_suppression_request_enabled_get(src, &val8);
    of_bsn_set_pktin_suppression_request_enabled_set(dst, val8);

    of_bsn_set_pktin_suppression_request_idle_timeout_get(src, &val16);
    of_bsn_set_pktin_suppression_request_idle_timeout_set(dst, val16);

    of_bsn_set_pktin_suppression_request_hard_timeout_get(src, &val16);
    of_bsn_set_pktin_suppression_request_hard_timeout_set(dst, val16);

    of_bsn_set_pktin_suppression_request_priority_get(src, &val16);
    of_bsn_set_pktin_suppression_request_priority_set(dst, val16);

    of_bsn_set_pktin_suppression_request_cookie_get(src, &val64);
    of_bsn_set_pktin_suppression_request_cookie_set(dst, val64);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_virtual_port_create_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_virtual_port_create_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_virtual_port_create_reply_t *
of_bsn_virtual_port_create_reply_OF_VERSION_1_1_dup(
    of_bsn_virtual_port_create_reply_t *src)
{
    of_bsn_virtual_port_create_reply_t *dst;
    uint32_t val32;

    if ((dst = of_bsn_virtual_port_create_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_virtual_port_create_reply_xid_get(src, &val32);
    of_bsn_virtual_port_create_reply_xid_set(dst, val32);

    of_bsn_virtual_port_create_reply_experimenter_get(src, &val32);
    of_bsn_virtual_port_create_reply_experimenter_set(dst, val32);

    of_bsn_virtual_port_create_reply_subtype_get(src, &val32);
    of_bsn_virtual_port_create_reply_subtype_set(dst, val32);

    of_bsn_virtual_port_create_reply_status_get(src, &val32);
    of_bsn_virtual_port_create_reply_status_set(dst, val32);

    of_bsn_virtual_port_create_reply_vport_no_get(src, &val32);
    of_bsn_virtual_port_create_reply_vport_no_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_virtual_port_create_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_virtual_port_create_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_virtual_port_create_request_t *
of_bsn_virtual_port_create_request_OF_VERSION_1_1_dup(
    of_bsn_virtual_port_create_request_t *src)
{
    of_bsn_virtual_port_create_request_t *dst;
    uint32_t val32;

    of_bsn_vport_q_in_q_t src_vport;
    of_bsn_vport_q_in_q_t *dst_vport;

    if ((dst = of_bsn_virtual_port_create_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_virtual_port_create_request_xid_get(src, &val32);
    of_bsn_virtual_port_create_request_xid_set(dst, val32);

    of_bsn_virtual_port_create_request_experimenter_get(src, &val32);
    of_bsn_virtual_port_create_request_experimenter_set(dst, val32);

    of_bsn_virtual_port_create_request_subtype_get(src, &val32);
    of_bsn_virtual_port_create_request_subtype_set(dst, val32);

    of_bsn_virtual_port_create_request_vport_bind(
        src, &src_vport);
    dst_vport = of_bsn_vport_q_in_q_OF_VERSION_1_1_dup(&src_vport);
    if (dst_vport == NULL) {
        of_bsn_virtual_port_create_request_delete(dst);
        return NULL;
    }
    of_bsn_virtual_port_create_request_vport_set(dst, dst_vport);
    of_bsn_vport_q_in_q_delete(dst_vport);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_virtual_port_remove_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_virtual_port_remove_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_virtual_port_remove_reply_t *
of_bsn_virtual_port_remove_reply_OF_VERSION_1_1_dup(
    of_bsn_virtual_port_remove_reply_t *src)
{
    of_bsn_virtual_port_remove_reply_t *dst;
    uint32_t val32;

    if ((dst = of_bsn_virtual_port_remove_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_virtual_port_remove_reply_xid_get(src, &val32);
    of_bsn_virtual_port_remove_reply_xid_set(dst, val32);

    of_bsn_virtual_port_remove_reply_experimenter_get(src, &val32);
    of_bsn_virtual_port_remove_reply_experimenter_set(dst, val32);

    of_bsn_virtual_port_remove_reply_subtype_get(src, &val32);
    of_bsn_virtual_port_remove_reply_subtype_set(dst, val32);

    of_bsn_virtual_port_remove_reply_status_get(src, &val32);
    of_bsn_virtual_port_remove_reply_status_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_virtual_port_remove_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_virtual_port_remove_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_virtual_port_remove_request_t *
of_bsn_virtual_port_remove_request_OF_VERSION_1_1_dup(
    of_bsn_virtual_port_remove_request_t *src)
{
    of_bsn_virtual_port_remove_request_t *dst;
    uint32_t val32;

    if ((dst = of_bsn_virtual_port_remove_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_virtual_port_remove_request_xid_get(src, &val32);
    of_bsn_virtual_port_remove_request_xid_set(dst, val32);

    of_bsn_virtual_port_remove_request_experimenter_get(src, &val32);
    of_bsn_virtual_port_remove_request_experimenter_set(dst, val32);

    of_bsn_virtual_port_remove_request_subtype_get(src, &val32);
    of_bsn_virtual_port_remove_request_subtype_set(dst, val32);

    of_bsn_virtual_port_remove_request_vport_no_get(src, &val32);
    of_bsn_virtual_port_remove_request_vport_no_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_desc_stats_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_desc_stats_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_desc_stats_reply_t *
of_desc_stats_reply_OF_VERSION_1_1_dup(
    of_desc_stats_reply_t *src)
{
    of_desc_stats_reply_t *dst;
    uint32_t val32;
    uint16_t val16;
    of_desc_str_t desc_str;
    of_serial_num_t ser_num;

    if ((dst = of_desc_stats_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_desc_stats_reply_xid_get(src, &val32);
    of_desc_stats_reply_xid_set(dst, val32);

    of_desc_stats_reply_flags_get(src, &val16);
    of_desc_stats_reply_flags_set(dst, val16);

    of_desc_stats_reply_mfr_desc_get(src, &desc_str);
    of_desc_stats_reply_mfr_desc_set(dst, desc_str);

    of_desc_stats_reply_hw_desc_get(src, &desc_str);
    of_desc_stats_reply_hw_desc_set(dst, desc_str);

    of_desc_stats_reply_sw_desc_get(src, &desc_str);
    of_desc_stats_reply_sw_desc_set(dst, desc_str);

    of_desc_stats_reply_serial_num_get(src, &ser_num);
    of_desc_stats_reply_serial_num_set(dst, ser_num);

    of_desc_stats_reply_dp_desc_get(src, &desc_str);
    of_desc_stats_reply_dp_desc_set(dst, desc_str);

    return dst;
}

/**
 * Duplicate an object of type of_desc_stats_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_desc_stats_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_desc_stats_request_t *
of_desc_stats_request_OF_VERSION_1_1_dup(
    of_desc_stats_request_t *src)
{
    of_desc_stats_request_t *dst;
    uint32_t val32;
    uint16_t val16;

    if ((dst = of_desc_stats_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_desc_stats_request_xid_get(src, &val32);
    of_desc_stats_request_xid_set(dst, val32);

    of_desc_stats_request_flags_get(src, &val16);
    of_desc_stats_request_flags_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_echo_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_echo_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_echo_reply_t *
of_echo_reply_OF_VERSION_1_1_dup(
    of_echo_reply_t *src)
{
    of_echo_reply_t *dst;
    uint32_t val32;
    of_octets_t octets;

    if ((dst = of_echo_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_echo_reply_xid_get(src, &val32);
    of_echo_reply_xid_set(dst, val32);

    of_echo_reply_data_get(src, &octets);
    of_echo_reply_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_echo_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_echo_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_echo_request_t *
of_echo_request_OF_VERSION_1_1_dup(
    of_echo_request_t *src)
{
    of_echo_request_t *dst;
    uint32_t val32;
    of_octets_t octets;

    if ((dst = of_echo_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_echo_request_xid_get(src, &val32);
    of_echo_request_xid_set(dst, val32);

    of_echo_request_data_get(src, &octets);
    of_echo_request_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_error_msg
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_error_msg.
 *
 * The caller is responsible for deleting the returned value
 */
of_error_msg_t *
of_error_msg_OF_VERSION_1_1_dup(
    of_error_msg_t *src)
{
    of_error_msg_t *dst;
    uint32_t val32;

    if ((dst = of_error_msg_new(src->version)) == NULL) {
        return NULL;
    }

    of_error_msg_xid_get(src, &val32);
    of_error_msg_xid_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_experimenter
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_experimenter.
 *
 * The caller is responsible for deleting the returned value
 */
of_experimenter_t *
of_experimenter_OF_VERSION_1_1_dup(
    of_experimenter_t *src)
{
    of_experimenter_t *dst;
    uint32_t val32;
    of_octets_t octets;

    if ((dst = of_experimenter_new(src->version)) == NULL) {
        return NULL;
    }

    of_experimenter_xid_get(src, &val32);
    of_experimenter_xid_set(dst, val32);

    of_experimenter_experimenter_get(src, &val32);
    of_experimenter_experimenter_set(dst, val32);

    of_experimenter_subtype_get(src, &val32);
    of_experimenter_subtype_set(dst, val32);

    of_experimenter_data_get(src, &octets);
    of_experimenter_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_experimenter_stats_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_experimenter_stats_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_experimenter_stats_reply_t *
of_experimenter_stats_reply_OF_VERSION_1_1_dup(
    of_experimenter_stats_reply_t *src)
{
    of_experimenter_stats_reply_t *dst;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    if ((dst = of_experimenter_stats_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_experimenter_stats_reply_xid_get(src, &val32);
    of_experimenter_stats_reply_xid_set(dst, val32);

    of_experimenter_stats_reply_flags_get(src, &val16);
    of_experimenter_stats_reply_flags_set(dst, val16);

    of_experimenter_stats_reply_experimenter_get(src, &val32);
    of_experimenter_stats_reply_experimenter_set(dst, val32);

    of_experimenter_stats_reply_data_get(src, &octets);
    of_experimenter_stats_reply_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_experimenter_stats_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_experimenter_stats_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_experimenter_stats_request_t *
of_experimenter_stats_request_OF_VERSION_1_1_dup(
    of_experimenter_stats_request_t *src)
{
    of_experimenter_stats_request_t *dst;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    if ((dst = of_experimenter_stats_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_experimenter_stats_request_xid_get(src, &val32);
    of_experimenter_stats_request_xid_set(dst, val32);

    of_experimenter_stats_request_flags_get(src, &val16);
    of_experimenter_stats_request_flags_set(dst, val16);

    of_experimenter_stats_request_experimenter_get(src, &val32);
    of_experimenter_stats_request_experimenter_set(dst, val32);

    of_experimenter_stats_request_data_get(src, &octets);
    of_experimenter_stats_request_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_features_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_features_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_features_reply_t *
of_features_reply_OF_VERSION_1_1_dup(
    of_features_reply_t *src)
{
    of_features_reply_t *dst;
    uint32_t val32;
    uint64_t val64;
    uint8_t val8;

    of_list_port_desc_t src_list;
    of_list_port_desc_t *dst_list;

    if ((dst = of_features_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_features_reply_xid_get(src, &val32);
    of_features_reply_xid_set(dst, val32);

    of_features_reply_datapath_id_get(src, &val64);
    of_features_reply_datapath_id_set(dst, val64);

    of_features_reply_n_buffers_get(src, &val32);
    of_features_reply_n_buffers_set(dst, val32);

    of_features_reply_n_tables_get(src, &val8);
    of_features_reply_n_tables_set(dst, val8);

    of_features_reply_capabilities_get(src, &val32);
    of_features_reply_capabilities_set(dst, val32);

    of_features_reply_reserved_get(src, &val32);
    of_features_reply_reserved_set(dst, val32);

    of_features_reply_ports_bind(
        src, &src_list);
    dst_list = of_list_port_desc_OF_VERSION_1_1_dup(&src_list);
    if (dst_list == NULL) {
        of_features_reply_delete(dst);
        return NULL;
    }
    of_features_reply_ports_set(dst, dst_list);
    of_list_port_desc_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_features_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_features_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_features_request_t *
of_features_request_OF_VERSION_1_1_dup(
    of_features_request_t *src)
{
    of_features_request_t *dst;
    uint32_t val32;

    if ((dst = of_features_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_features_request_xid_get(src, &val32);
    of_features_request_xid_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_flow_add
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_flow_add.
 *
 * The caller is responsible for deleting the returned value
 */
of_flow_add_t *
of_flow_add_OF_VERSION_1_1_dup(
    of_flow_add_t *src)
{
    of_flow_add_t *dst;
    uint32_t val32;
    uint64_t val64;
    uint8_t val8;
    uint16_t val16;
    of_port_no_t port_no;
    of_match_t match;

    of_list_instruction_t src_list;
    of_list_instruction_t *dst_list;

    if ((dst = of_flow_add_new(src->version)) == NULL) {
        return NULL;
    }

    of_flow_add_xid_get(src, &val32);
    of_flow_add_xid_set(dst, val32);

    of_flow_add_cookie_get(src, &val64);
    of_flow_add_cookie_set(dst, val64);

    of_flow_add_cookie_mask_get(src, &val64);
    of_flow_add_cookie_mask_set(dst, val64);

    of_flow_add_table_id_get(src, &val8);
    of_flow_add_table_id_set(dst, val8);

    of_flow_add_idle_timeout_get(src, &val16);
    of_flow_add_idle_timeout_set(dst, val16);

    of_flow_add_hard_timeout_get(src, &val16);
    of_flow_add_hard_timeout_set(dst, val16);

    of_flow_add_priority_get(src, &val16);
    of_flow_add_priority_set(dst, val16);

    of_flow_add_buffer_id_get(src, &val32);
    of_flow_add_buffer_id_set(dst, val32);

    of_flow_add_out_port_get(src, &port_no);
    of_flow_add_out_port_set(dst, port_no);

    of_flow_add_out_group_get(src, &val32);
    of_flow_add_out_group_set(dst, val32);

    of_flow_add_flags_get(src, &val16);
    of_flow_add_flags_set(dst, val16);

    of_flow_add_match_get(src, &match);
    of_flow_add_match_set(dst, &match);

    of_flow_add_instructions_bind(
        src, &src_list);
    dst_list = of_list_instruction_OF_VERSION_1_1_dup(&src_list);
    if (dst_list == NULL) {
        of_flow_add_delete(dst);
        return NULL;
    }
    of_flow_add_instructions_set(dst, dst_list);
    of_list_instruction_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_flow_delete
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_flow_delete.
 *
 * The caller is responsible for deleting the returned value
 */
of_flow_delete_t *
of_flow_delete_OF_VERSION_1_1_dup(
    of_flow_delete_t *src)
{
    of_flow_delete_t *dst;
    uint32_t val32;
    uint64_t val64;
    uint8_t val8;
    uint16_t val16;
    of_port_no_t port_no;
    of_match_t match;

    of_list_instruction_t src_list;
    of_list_instruction_t *dst_list;

    if ((dst = of_flow_delete_new(src->version)) == NULL) {
        return NULL;
    }

    of_flow_delete_xid_get(src, &val32);
    of_flow_delete_xid_set(dst, val32);

    of_flow_delete_cookie_get(src, &val64);
    of_flow_delete_cookie_set(dst, val64);

    of_flow_delete_cookie_mask_get(src, &val64);
    of_flow_delete_cookie_mask_set(dst, val64);

    of_flow_delete_table_id_get(src, &val8);
    of_flow_delete_table_id_set(dst, val8);

    of_flow_delete_idle_timeout_get(src, &val16);
    of_flow_delete_idle_timeout_set(dst, val16);

    of_flow_delete_hard_timeout_get(src, &val16);
    of_flow_delete_hard_timeout_set(dst, val16);

    of_flow_delete_priority_get(src, &val16);
    of_flow_delete_priority_set(dst, val16);

    of_flow_delete_buffer_id_get(src, &val32);
    of_flow_delete_buffer_id_set(dst, val32);

    of_flow_delete_out_port_get(src, &port_no);
    of_flow_delete_out_port_set(dst, port_no);

    of_flow_delete_out_group_get(src, &val32);
    of_flow_delete_out_group_set(dst, val32);

    of_flow_delete_flags_get(src, &val16);
    of_flow_delete_flags_set(dst, val16);

    of_flow_delete_match_get(src, &match);
    of_flow_delete_match_set(dst, &match);

    of_flow_delete_instructions_bind(
        src, &src_list);
    dst_list = of_list_instruction_OF_VERSION_1_1_dup(&src_list);
    if (dst_list == NULL) {
        of_flow_delete_delete(dst);
        return NULL;
    }
    of_flow_delete_instructions_set(dst, dst_list);
    of_list_instruction_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_flow_delete_strict
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_flow_delete_strict.
 *
 * The caller is responsible for deleting the returned value
 */
of_flow_delete_strict_t *
of_flow_delete_strict_OF_VERSION_1_1_dup(
    of_flow_delete_strict_t *src)
{
    of_flow_delete_strict_t *dst;
    uint32_t val32;
    uint64_t val64;
    uint8_t val8;
    uint16_t val16;
    of_port_no_t port_no;
    of_match_t match;

    of_list_instruction_t src_list;
    of_list_instruction_t *dst_list;

    if ((dst = of_flow_delete_strict_new(src->version)) == NULL) {
        return NULL;
    }

    of_flow_delete_strict_xid_get(src, &val32);
    of_flow_delete_strict_xid_set(dst, val32);

    of_flow_delete_strict_cookie_get(src, &val64);
    of_flow_delete_strict_cookie_set(dst, val64);

    of_flow_delete_strict_cookie_mask_get(src, &val64);
    of_flow_delete_strict_cookie_mask_set(dst, val64);

    of_flow_delete_strict_table_id_get(src, &val8);
    of_flow_delete_strict_table_id_set(dst, val8);

    of_flow_delete_strict_idle_timeout_get(src, &val16);
    of_flow_delete_strict_idle_timeout_set(dst, val16);

    of_flow_delete_strict_hard_timeout_get(src, &val16);
    of_flow_delete_strict_hard_timeout_set(dst, val16);

    of_flow_delete_strict_priority_get(src, &val16);
    of_flow_delete_strict_priority_set(dst, val16);

    of_flow_delete_strict_buffer_id_get(src, &val32);
    of_flow_delete_strict_buffer_id_set(dst, val32);

    of_flow_delete_strict_out_port_get(src, &port_no);
    of_flow_delete_strict_out_port_set(dst, port_no);

    of_flow_delete_strict_out_group_get(src, &val32);
    of_flow_delete_strict_out_group_set(dst, val32);

    of_flow_delete_strict_flags_get(src, &val16);
    of_flow_delete_strict_flags_set(dst, val16);

    of_flow_delete_strict_match_get(src, &match);
    of_flow_delete_strict_match_set(dst, &match);

    of_flow_delete_strict_instructions_bind(
        src, &src_list);
    dst_list = of_list_instruction_OF_VERSION_1_1_dup(&src_list);
    if (dst_list == NULL) {
        of_flow_delete_strict_delete(dst);
        return NULL;
    }
    of_flow_delete_strict_instructions_set(dst, dst_list);
    of_list_instruction_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_flow_mod
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_flow_mod.
 *
 * The caller is responsible for deleting the returned value
 */
of_flow_mod_t *
of_flow_mod_OF_VERSION_1_1_dup(
    of_flow_mod_t *src)
{
    of_flow_mod_t *dst;
    uint32_t val32;
    uint64_t val64;
    uint8_t val8;
    uint16_t val16;
    of_port_no_t port_no;
    of_match_t match;

    of_list_instruction_t src_list;
    of_list_instruction_t *dst_list;

    if ((dst = of_flow_mod_new(src->version)) == NULL) {
        return NULL;
    }

    of_flow_mod_xid_get(src, &val32);
    of_flow_mod_xid_set(dst, val32);

    of_flow_mod_cookie_get(src, &val64);
    of_flow_mod_cookie_set(dst, val64);

    of_flow_mod_cookie_mask_get(src, &val64);
    of_flow_mod_cookie_mask_set(dst, val64);

    of_flow_mod_table_id_get(src, &val8);
    of_flow_mod_table_id_set(dst, val8);

    of_flow_mod_idle_timeout_get(src, &val16);
    of_flow_mod_idle_timeout_set(dst, val16);

    of_flow_mod_hard_timeout_get(src, &val16);
    of_flow_mod_hard_timeout_set(dst, val16);

    of_flow_mod_priority_get(src, &val16);
    of_flow_mod_priority_set(dst, val16);

    of_flow_mod_buffer_id_get(src, &val32);
    of_flow_mod_buffer_id_set(dst, val32);

    of_flow_mod_out_port_get(src, &port_no);
    of_flow_mod_out_port_set(dst, port_no);

    of_flow_mod_out_group_get(src, &val32);
    of_flow_mod_out_group_set(dst, val32);

    of_flow_mod_flags_get(src, &val16);
    of_flow_mod_flags_set(dst, val16);

    of_flow_mod_match_get(src, &match);
    of_flow_mod_match_set(dst, &match);

    of_flow_mod_instructions_bind(
        src, &src_list);
    dst_list = of_list_instruction_OF_VERSION_1_1_dup(&src_list);
    if (dst_list == NULL) {
        of_flow_mod_delete(dst);
        return NULL;
    }
    of_flow_mod_instructions_set(dst, dst_list);
    of_list_instruction_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_flow_mod_failed_error_msg
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_flow_mod_failed_error_msg.
 *
 * The caller is responsible for deleting the returned value
 */
of_flow_mod_failed_error_msg_t *
of_flow_mod_failed_error_msg_OF_VERSION_1_1_dup(
    of_flow_mod_failed_error_msg_t *src)
{
    of_flow_mod_failed_error_msg_t *dst;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    if ((dst = of_flow_mod_failed_error_msg_new(src->version)) == NULL) {
        return NULL;
    }

    of_flow_mod_failed_error_msg_xid_get(src, &val32);
    of_flow_mod_failed_error_msg_xid_set(dst, val32);

    of_flow_mod_failed_error_msg_code_get(src, &val16);
    of_flow_mod_failed_error_msg_code_set(dst, val16);

    of_flow_mod_failed_error_msg_data_get(src, &octets);
    of_flow_mod_failed_error_msg_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_flow_modify
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_flow_modify.
 *
 * The caller is responsible for deleting the returned value
 */
of_flow_modify_t *
of_flow_modify_OF_VERSION_1_1_dup(
    of_flow_modify_t *src)
{
    of_flow_modify_t *dst;
    uint32_t val32;
    uint64_t val64;
    uint8_t val8;
    uint16_t val16;
    of_port_no_t port_no;
    of_match_t match;

    of_list_instruction_t src_list;
    of_list_instruction_t *dst_list;

    if ((dst = of_flow_modify_new(src->version)) == NULL) {
        return NULL;
    }

    of_flow_modify_xid_get(src, &val32);
    of_flow_modify_xid_set(dst, val32);

    of_flow_modify_cookie_get(src, &val64);
    of_flow_modify_cookie_set(dst, val64);

    of_flow_modify_cookie_mask_get(src, &val64);
    of_flow_modify_cookie_mask_set(dst, val64);

    of_flow_modify_table_id_get(src, &val8);
    of_flow_modify_table_id_set(dst, val8);

    of_flow_modify_idle_timeout_get(src, &val16);
    of_flow_modify_idle_timeout_set(dst, val16);

    of_flow_modify_hard_timeout_get(src, &val16);
    of_flow_modify_hard_timeout_set(dst, val16);

    of_flow_modify_priority_get(src, &val16);
    of_flow_modify_priority_set(dst, val16);

    of_flow_modify_buffer_id_get(src, &val32);
    of_flow_modify_buffer_id_set(dst, val32);

    of_flow_modify_out_port_get(src, &port_no);
    of_flow_modify_out_port_set(dst, port_no);

    of_flow_modify_out_group_get(src, &val32);
    of_flow_modify_out_group_set(dst, val32);

    of_flow_modify_flags_get(src, &val16);
    of_flow_modify_flags_set(dst, val16);

    of_flow_modify_match_get(src, &match);
    of_flow_modify_match_set(dst, &match);

    of_flow_modify_instructions_bind(
        src, &src_list);
    dst_list = of_list_instruction_OF_VERSION_1_1_dup(&src_list);
    if (dst_list == NULL) {
        of_flow_modify_delete(dst);
        return NULL;
    }
    of_flow_modify_instructions_set(dst, dst_list);
    of_list_instruction_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_flow_modify_strict
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_flow_modify_strict.
 *
 * The caller is responsible for deleting the returned value
 */
of_flow_modify_strict_t *
of_flow_modify_strict_OF_VERSION_1_1_dup(
    of_flow_modify_strict_t *src)
{
    of_flow_modify_strict_t *dst;
    uint32_t val32;
    uint64_t val64;
    uint8_t val8;
    uint16_t val16;
    of_port_no_t port_no;
    of_match_t match;

    of_list_instruction_t src_list;
    of_list_instruction_t *dst_list;

    if ((dst = of_flow_modify_strict_new(src->version)) == NULL) {
        return NULL;
    }

    of_flow_modify_strict_xid_get(src, &val32);
    of_flow_modify_strict_xid_set(dst, val32);

    of_flow_modify_strict_cookie_get(src, &val64);
    of_flow_modify_strict_cookie_set(dst, val64);

    of_flow_modify_strict_cookie_mask_get(src, &val64);
    of_flow_modify_strict_cookie_mask_set(dst, val64);

    of_flow_modify_strict_table_id_get(src, &val8);
    of_flow_modify_strict_table_id_set(dst, val8);

    of_flow_modify_strict_idle_timeout_get(src, &val16);
    of_flow_modify_strict_idle_timeout_set(dst, val16);

    of_flow_modify_strict_hard_timeout_get(src, &val16);
    of_flow_modify_strict_hard_timeout_set(dst, val16);

    of_flow_modify_strict_priority_get(src, &val16);
    of_flow_modify_strict_priority_set(dst, val16);

    of_flow_modify_strict_buffer_id_get(src, &val32);
    of_flow_modify_strict_buffer_id_set(dst, val32);

    of_flow_modify_strict_out_port_get(src, &port_no);
    of_flow_modify_strict_out_port_set(dst, port_no);

    of_flow_modify_strict_out_group_get(src, &val32);
    of_flow_modify_strict_out_group_set(dst, val32);

    of_flow_modify_strict_flags_get(src, &val16);
    of_flow_modify_strict_flags_set(dst, val16);

    of_flow_modify_strict_match_get(src, &match);
    of_flow_modify_strict_match_set(dst, &match);

    of_flow_modify_strict_instructions_bind(
        src, &src_list);
    dst_list = of_list_instruction_OF_VERSION_1_1_dup(&src_list);
    if (dst_list == NULL) {
        of_flow_modify_strict_delete(dst);
        return NULL;
    }
    of_flow_modify_strict_instructions_set(dst, dst_list);
    of_list_instruction_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_flow_removed
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_flow_removed.
 *
 * The caller is responsible for deleting the returned value
 */
of_flow_removed_t *
of_flow_removed_OF_VERSION_1_1_dup(
    of_flow_removed_t *src)
{
    of_flow_removed_t *dst;
    uint32_t val32;
    uint64_t val64;
    uint16_t val16;
    uint8_t val8;
    of_match_t match;

    if ((dst = of_flow_removed_new(src->version)) == NULL) {
        return NULL;
    }

    of_flow_removed_xid_get(src, &val32);
    of_flow_removed_xid_set(dst, val32);

    of_flow_removed_cookie_get(src, &val64);
    of_flow_removed_cookie_set(dst, val64);

    of_flow_removed_priority_get(src, &val16);
    of_flow_removed_priority_set(dst, val16);

    of_flow_removed_reason_get(src, &val8);
    of_flow_removed_reason_set(dst, val8);

    of_flow_removed_table_id_get(src, &val8);
    of_flow_removed_table_id_set(dst, val8);

    of_flow_removed_duration_sec_get(src, &val32);
    of_flow_removed_duration_sec_set(dst, val32);

    of_flow_removed_duration_nsec_get(src, &val32);
    of_flow_removed_duration_nsec_set(dst, val32);

    of_flow_removed_idle_timeout_get(src, &val16);
    of_flow_removed_idle_timeout_set(dst, val16);

    of_flow_removed_packet_count_get(src, &val64);
    of_flow_removed_packet_count_set(dst, val64);

    of_flow_removed_byte_count_get(src, &val64);
    of_flow_removed_byte_count_set(dst, val64);

    of_flow_removed_match_get(src, &match);
    of_flow_removed_match_set(dst, &match);

    return dst;
}

/**
 * Duplicate an object of type of_flow_stats_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_flow_stats_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_flow_stats_reply_t *
of_flow_stats_reply_OF_VERSION_1_1_dup(
    of_flow_stats_reply_t *src)
{
    of_flow_stats_reply_t *dst;
    uint32_t val32;
    uint16_t val16;

    of_list_flow_stats_entry_t src_list;
    of_list_flow_stats_entry_t *dst_list;

    if ((dst = of_flow_stats_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_flow_stats_reply_xid_get(src, &val32);
    of_flow_stats_reply_xid_set(dst, val32);

    of_flow_stats_reply_flags_get(src, &val16);
    of_flow_stats_reply_flags_set(dst, val16);

    of_flow_stats_reply_entries_bind(
        src, &src_list);
    dst_list = of_list_flow_stats_entry_OF_VERSION_1_1_dup(&src_list);
    if (dst_list == NULL) {
        of_flow_stats_reply_delete(dst);
        return NULL;
    }
    of_flow_stats_reply_entries_set(dst, dst_list);
    of_list_flow_stats_entry_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_flow_stats_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_flow_stats_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_flow_stats_request_t *
of_flow_stats_request_OF_VERSION_1_1_dup(
    of_flow_stats_request_t *src)
{
    of_flow_stats_request_t *dst;
    uint32_t val32;
    uint16_t val16;
    uint8_t val8;
    of_port_no_t port_no;
    uint64_t val64;
    of_match_t match;

    if ((dst = of_flow_stats_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_flow_stats_request_xid_get(src, &val32);
    of_flow_stats_request_xid_set(dst, val32);

    of_flow_stats_request_flags_get(src, &val16);
    of_flow_stats_request_flags_set(dst, val16);

    of_flow_stats_request_table_id_get(src, &val8);
    of_flow_stats_request_table_id_set(dst, val8);

    of_flow_stats_request_out_port_get(src, &port_no);
    of_flow_stats_request_out_port_set(dst, port_no);

    of_flow_stats_request_out_group_get(src, &val32);
    of_flow_stats_request_out_group_set(dst, val32);

    of_flow_stats_request_cookie_get(src, &val64);
    of_flow_stats_request_cookie_set(dst, val64);

    of_flow_stats_request_cookie_mask_get(src, &val64);
    of_flow_stats_request_cookie_mask_set(dst, val64);

    of_flow_stats_request_match_get(src, &match);
    of_flow_stats_request_match_set(dst, &match);

    return dst;
}

/**
 * Duplicate an object of type of_get_config_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_get_config_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_get_config_reply_t *
of_get_config_reply_OF_VERSION_1_1_dup(
    of_get_config_reply_t *src)
{
    of_get_config_reply_t *dst;
    uint32_t val32;
    uint16_t val16;

    if ((dst = of_get_config_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_get_config_reply_xid_get(src, &val32);
    of_get_config_reply_xid_set(dst, val32);

    of_get_config_reply_flags_get(src, &val16);
    of_get_config_reply_flags_set(dst, val16);

    of_get_config_reply_miss_send_len_get(src, &val16);
    of_get_config_reply_miss_send_len_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_get_config_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_get_config_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_get_config_request_t *
of_get_config_request_OF_VERSION_1_1_dup(
    of_get_config_request_t *src)
{
    of_get_config_request_t *dst;
    uint32_t val32;

    if ((dst = of_get_config_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_get_config_request_xid_get(src, &val32);
    of_get_config_request_xid_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_group_desc_stats_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_group_desc_stats_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_group_desc_stats_reply_t *
of_group_desc_stats_reply_OF_VERSION_1_1_dup(
    of_group_desc_stats_reply_t *src)
{
    of_group_desc_stats_reply_t *dst;
    uint32_t val32;
    uint16_t val16;

    of_list_group_desc_stats_entry_t src_list;
    of_list_group_desc_stats_entry_t *dst_list;

    if ((dst = of_group_desc_stats_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_group_desc_stats_reply_xid_get(src, &val32);
    of_group_desc_stats_reply_xid_set(dst, val32);

    of_group_desc_stats_reply_flags_get(src, &val16);
    of_group_desc_stats_reply_flags_set(dst, val16);

    of_group_desc_stats_reply_entries_bind(
        src, &src_list);
    dst_list = of_list_group_desc_stats_entry_OF_VERSION_1_1_dup(&src_list);
    if (dst_list == NULL) {
        of_group_desc_stats_reply_delete(dst);
        return NULL;
    }
    of_group_desc_stats_reply_entries_set(dst, dst_list);
    of_list_group_desc_stats_entry_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_group_desc_stats_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_group_desc_stats_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_group_desc_stats_request_t *
of_group_desc_stats_request_OF_VERSION_1_1_dup(
    of_group_desc_stats_request_t *src)
{
    of_group_desc_stats_request_t *dst;
    uint32_t val32;
    uint16_t val16;

    if ((dst = of_group_desc_stats_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_group_desc_stats_request_xid_get(src, &val32);
    of_group_desc_stats_request_xid_set(dst, val32);

    of_group_desc_stats_request_flags_get(src, &val16);
    of_group_desc_stats_request_flags_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_group_mod
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_group_mod.
 *
 * The caller is responsible for deleting the returned value
 */
of_group_mod_t *
of_group_mod_OF_VERSION_1_1_dup(
    of_group_mod_t *src)
{
    of_group_mod_t *dst;
    uint32_t val32;
    uint16_t val16;
    uint8_t val8;

    of_list_bucket_t src_list;
    of_list_bucket_t *dst_list;

    if ((dst = of_group_mod_new(src->version)) == NULL) {
        return NULL;
    }

    of_group_mod_xid_get(src, &val32);
    of_group_mod_xid_set(dst, val32);

    of_group_mod_command_get(src, &val16);
    of_group_mod_command_set(dst, val16);

    of_group_mod_group_type_get(src, &val8);
    of_group_mod_group_type_set(dst, val8);

    of_group_mod_group_id_get(src, &val32);
    of_group_mod_group_id_set(dst, val32);

    of_group_mod_buckets_bind(
        src, &src_list);
    dst_list = of_list_bucket_OF_VERSION_1_1_dup(&src_list);
    if (dst_list == NULL) {
        of_group_mod_delete(dst);
        return NULL;
    }
    of_group_mod_buckets_set(dst, dst_list);
    of_list_bucket_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_group_mod_failed_error_msg
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_group_mod_failed_error_msg.
 *
 * The caller is responsible for deleting the returned value
 */
of_group_mod_failed_error_msg_t *
of_group_mod_failed_error_msg_OF_VERSION_1_1_dup(
    of_group_mod_failed_error_msg_t *src)
{
    of_group_mod_failed_error_msg_t *dst;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    if ((dst = of_group_mod_failed_error_msg_new(src->version)) == NULL) {
        return NULL;
    }

    of_group_mod_failed_error_msg_xid_get(src, &val32);
    of_group_mod_failed_error_msg_xid_set(dst, val32);

    of_group_mod_failed_error_msg_code_get(src, &val16);
    of_group_mod_failed_error_msg_code_set(dst, val16);

    of_group_mod_failed_error_msg_data_get(src, &octets);
    of_group_mod_failed_error_msg_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_group_stats_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_group_stats_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_group_stats_reply_t *
of_group_stats_reply_OF_VERSION_1_1_dup(
    of_group_stats_reply_t *src)
{
    of_group_stats_reply_t *dst;
    uint32_t val32;
    uint16_t val16;

    of_list_group_stats_entry_t src_list;
    of_list_group_stats_entry_t *dst_list;

    if ((dst = of_group_stats_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_group_stats_reply_xid_get(src, &val32);
    of_group_stats_reply_xid_set(dst, val32);

    of_group_stats_reply_flags_get(src, &val16);
    of_group_stats_reply_flags_set(dst, val16);

    of_group_stats_reply_entries_bind(
        src, &src_list);
    dst_list = of_list_group_stats_entry_OF_VERSION_1_1_dup(&src_list);
    if (dst_list == NULL) {
        of_group_stats_reply_delete(dst);
        return NULL;
    }
    of_group_stats_reply_entries_set(dst, dst_list);
    of_list_group_stats_entry_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_group_stats_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_group_stats_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_group_stats_request_t *
of_group_stats_request_OF_VERSION_1_1_dup(
    of_group_stats_request_t *src)
{
    of_group_stats_request_t *dst;
    uint32_t val32;
    uint16_t val16;

    if ((dst = of_group_stats_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_group_stats_request_xid_get(src, &val32);
    of_group_stats_request_xid_set(dst, val32);

    of_group_stats_request_flags_get(src, &val16);
    of_group_stats_request_flags_set(dst, val16);

    of_group_stats_request_group_id_get(src, &val32);
    of_group_stats_request_group_id_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_hello
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_hello.
 *
 * The caller is responsible for deleting the returned value
 */
of_hello_t *
of_hello_OF_VERSION_1_1_dup(
    of_hello_t *src)
{
    of_hello_t *dst;
    uint32_t val32;

    if ((dst = of_hello_new(src->version)) == NULL) {
        return NULL;
    }

    of_hello_xid_get(src, &val32);
    of_hello_xid_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_hello_failed_error_msg
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_hello_failed_error_msg.
 *
 * The caller is responsible for deleting the returned value
 */
of_hello_failed_error_msg_t *
of_hello_failed_error_msg_OF_VERSION_1_1_dup(
    of_hello_failed_error_msg_t *src)
{
    of_hello_failed_error_msg_t *dst;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    if ((dst = of_hello_failed_error_msg_new(src->version)) == NULL) {
        return NULL;
    }

    of_hello_failed_error_msg_xid_get(src, &val32);
    of_hello_failed_error_msg_xid_set(dst, val32);

    of_hello_failed_error_msg_code_get(src, &val16);
    of_hello_failed_error_msg_code_set(dst, val16);

    of_hello_failed_error_msg_data_get(src, &octets);
    of_hello_failed_error_msg_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_nicira_header
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_nicira_header.
 *
 * The caller is responsible for deleting the returned value
 */
of_nicira_header_t *
of_nicira_header_OF_VERSION_1_1_dup(
    of_nicira_header_t *src)
{
    of_nicira_header_t *dst;
    uint32_t val32;

    if ((dst = of_nicira_header_new(src->version)) == NULL) {
        return NULL;
    }

    of_nicira_header_xid_get(src, &val32);
    of_nicira_header_xid_set(dst, val32);

    of_nicira_header_experimenter_get(src, &val32);
    of_nicira_header_experimenter_set(dst, val32);

    of_nicira_header_subtype_get(src, &val32);
    of_nicira_header_subtype_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_packet_in
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_packet_in.
 *
 * The caller is responsible for deleting the returned value
 */
of_packet_in_t *
of_packet_in_OF_VERSION_1_1_dup(
    of_packet_in_t *src)
{
    of_packet_in_t *dst;
    uint32_t val32;
    of_port_no_t port_no;
    uint16_t val16;
    uint8_t val8;
    of_octets_t octets;

    if ((dst = of_packet_in_new(src->version)) == NULL) {
        return NULL;
    }

    of_packet_in_xid_get(src, &val32);
    of_packet_in_xid_set(dst, val32);

    of_packet_in_buffer_id_get(src, &val32);
    of_packet_in_buffer_id_set(dst, val32);

    of_packet_in_in_port_get(src, &port_no);
    of_packet_in_in_port_set(dst, port_no);

    of_packet_in_in_phy_port_get(src, &port_no);
    of_packet_in_in_phy_port_set(dst, port_no);

    of_packet_in_total_len_get(src, &val16);
    of_packet_in_total_len_set(dst, val16);

    of_packet_in_reason_get(src, &val8);
    of_packet_in_reason_set(dst, val8);

    of_packet_in_table_id_get(src, &val8);
    of_packet_in_table_id_set(dst, val8);

    of_packet_in_data_get(src, &octets);
    of_packet_in_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_packet_out
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_packet_out.
 *
 * The caller is responsible for deleting the returned value
 */
of_packet_out_t *
of_packet_out_OF_VERSION_1_1_dup(
    of_packet_out_t *src)
{
    of_packet_out_t *dst;
    uint32_t val32;
    of_port_no_t port_no;

    of_list_action_t src_list;
    of_list_action_t *dst_list;
    of_octets_t octets;

    if ((dst = of_packet_out_new(src->version)) == NULL) {
        return NULL;
    }

    of_packet_out_xid_get(src, &val32);
    of_packet_out_xid_set(dst, val32);

    of_packet_out_buffer_id_get(src, &val32);
    of_packet_out_buffer_id_set(dst, val32);

    of_packet_out_in_port_get(src, &port_no);
    of_packet_out_in_port_set(dst, port_no);

    of_packet_out_actions_bind(
        src, &src_list);
    dst_list = of_list_action_OF_VERSION_1_1_dup(&src_list);
    if (dst_list == NULL) {
        of_packet_out_delete(dst);
        return NULL;
    }
    of_packet_out_actions_set(dst, dst_list);
    of_list_action_delete(dst_list);

    of_packet_out_data_get(src, &octets);
    of_packet_out_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_port_mod
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_port_mod.
 *
 * The caller is responsible for deleting the returned value
 */
of_port_mod_t *
of_port_mod_OF_VERSION_1_1_dup(
    of_port_mod_t *src)
{
    of_port_mod_t *dst;
    uint32_t val32;
    of_port_no_t port_no;
    of_mac_addr_t mac_addr;

    if ((dst = of_port_mod_new(src->version)) == NULL) {
        return NULL;
    }

    of_port_mod_xid_get(src, &val32);
    of_port_mod_xid_set(dst, val32);

    of_port_mod_port_no_get(src, &port_no);
    of_port_mod_port_no_set(dst, port_no);

    of_port_mod_hw_addr_get(src, &mac_addr);
    of_port_mod_hw_addr_set(dst, mac_addr);

    of_port_mod_config_get(src, &val32);
    of_port_mod_config_set(dst, val32);

    of_port_mod_mask_get(src, &val32);
    of_port_mod_mask_set(dst, val32);

    of_port_mod_advertise_get(src, &val32);
    of_port_mod_advertise_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_port_mod_failed_error_msg
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_port_mod_failed_error_msg.
 *
 * The caller is responsible for deleting the returned value
 */
of_port_mod_failed_error_msg_t *
of_port_mod_failed_error_msg_OF_VERSION_1_1_dup(
    of_port_mod_failed_error_msg_t *src)
{
    of_port_mod_failed_error_msg_t *dst;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    if ((dst = of_port_mod_failed_error_msg_new(src->version)) == NULL) {
        return NULL;
    }

    of_port_mod_failed_error_msg_xid_get(src, &val32);
    of_port_mod_failed_error_msg_xid_set(dst, val32);

    of_port_mod_failed_error_msg_code_get(src, &val16);
    of_port_mod_failed_error_msg_code_set(dst, val16);

    of_port_mod_failed_error_msg_data_get(src, &octets);
    of_port_mod_failed_error_msg_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_port_stats_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_port_stats_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_port_stats_reply_t *
of_port_stats_reply_OF_VERSION_1_1_dup(
    of_port_stats_reply_t *src)
{
    of_port_stats_reply_t *dst;
    uint32_t val32;
    uint16_t val16;

    of_list_port_stats_entry_t src_list;
    of_list_port_stats_entry_t *dst_list;

    if ((dst = of_port_stats_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_port_stats_reply_xid_get(src, &val32);
    of_port_stats_reply_xid_set(dst, val32);

    of_port_stats_reply_flags_get(src, &val16);
    of_port_stats_reply_flags_set(dst, val16);

    of_port_stats_reply_entries_bind(
        src, &src_list);
    dst_list = of_list_port_stats_entry_OF_VERSION_1_1_dup(&src_list);
    if (dst_list == NULL) {
        of_port_stats_reply_delete(dst);
        return NULL;
    }
    of_port_stats_reply_entries_set(dst, dst_list);
    of_list_port_stats_entry_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_port_stats_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_port_stats_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_port_stats_request_t *
of_port_stats_request_OF_VERSION_1_1_dup(
    of_port_stats_request_t *src)
{
    of_port_stats_request_t *dst;
    uint32_t val32;
    uint16_t val16;
    of_port_no_t port_no;

    if ((dst = of_port_stats_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_port_stats_request_xid_get(src, &val32);
    of_port_stats_request_xid_set(dst, val32);

    of_port_stats_request_flags_get(src, &val16);
    of_port_stats_request_flags_set(dst, val16);

    of_port_stats_request_port_no_get(src, &port_no);
    of_port_stats_request_port_no_set(dst, port_no);

    return dst;
}

/**
 * Duplicate an object of type of_port_status
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_port_status.
 *
 * The caller is responsible for deleting the returned value
 */
of_port_status_t *
of_port_status_OF_VERSION_1_1_dup(
    of_port_status_t *src)
{
    of_port_status_t *dst;
    uint32_t val32;
    uint8_t val8;

    of_port_desc_t src_port_desc;
    of_port_desc_t *dst_port_desc;

    if ((dst = of_port_status_new(src->version)) == NULL) {
        return NULL;
    }

    of_port_status_xid_get(src, &val32);
    of_port_status_xid_set(dst, val32);

    of_port_status_reason_get(src, &val8);
    of_port_status_reason_set(dst, val8);

    of_port_status_desc_bind(
        src, &src_port_desc);
    dst_port_desc = of_port_desc_OF_VERSION_1_1_dup(&src_port_desc);
    if (dst_port_desc == NULL) {
        of_port_status_delete(dst);
        return NULL;
    }
    of_port_status_desc_set(dst, dst_port_desc);
    of_port_desc_delete(dst_port_desc);

    return dst;
}

/**
 * Duplicate an object of type of_queue_get_config_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_queue_get_config_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_queue_get_config_reply_t *
of_queue_get_config_reply_OF_VERSION_1_1_dup(
    of_queue_get_config_reply_t *src)
{
    of_queue_get_config_reply_t *dst;
    uint32_t val32;
    of_port_no_t port_no;

    of_list_packet_queue_t src_list;
    of_list_packet_queue_t *dst_list;

    if ((dst = of_queue_get_config_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_queue_get_config_reply_xid_get(src, &val32);
    of_queue_get_config_reply_xid_set(dst, val32);

    of_queue_get_config_reply_port_get(src, &port_no);
    of_queue_get_config_reply_port_set(dst, port_no);

    of_queue_get_config_reply_queues_bind(
        src, &src_list);
    dst_list = of_list_packet_queue_OF_VERSION_1_1_dup(&src_list);
    if (dst_list == NULL) {
        of_queue_get_config_reply_delete(dst);
        return NULL;
    }
    of_queue_get_config_reply_queues_set(dst, dst_list);
    of_list_packet_queue_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_queue_get_config_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_queue_get_config_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_queue_get_config_request_t *
of_queue_get_config_request_OF_VERSION_1_1_dup(
    of_queue_get_config_request_t *src)
{
    of_queue_get_config_request_t *dst;
    uint32_t val32;
    of_port_no_t port_no;

    if ((dst = of_queue_get_config_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_queue_get_config_request_xid_get(src, &val32);
    of_queue_get_config_request_xid_set(dst, val32);

    of_queue_get_config_request_port_get(src, &port_no);
    of_queue_get_config_request_port_set(dst, port_no);

    return dst;
}

/**
 * Duplicate an object of type of_queue_op_failed_error_msg
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_queue_op_failed_error_msg.
 *
 * The caller is responsible for deleting the returned value
 */
of_queue_op_failed_error_msg_t *
of_queue_op_failed_error_msg_OF_VERSION_1_1_dup(
    of_queue_op_failed_error_msg_t *src)
{
    of_queue_op_failed_error_msg_t *dst;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    if ((dst = of_queue_op_failed_error_msg_new(src->version)) == NULL) {
        return NULL;
    }

    of_queue_op_failed_error_msg_xid_get(src, &val32);
    of_queue_op_failed_error_msg_xid_set(dst, val32);

    of_queue_op_failed_error_msg_code_get(src, &val16);
    of_queue_op_failed_error_msg_code_set(dst, val16);

    of_queue_op_failed_error_msg_data_get(src, &octets);
    of_queue_op_failed_error_msg_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_queue_stats_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_queue_stats_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_queue_stats_reply_t *
of_queue_stats_reply_OF_VERSION_1_1_dup(
    of_queue_stats_reply_t *src)
{
    of_queue_stats_reply_t *dst;
    uint32_t val32;
    uint16_t val16;

    of_list_queue_stats_entry_t src_list;
    of_list_queue_stats_entry_t *dst_list;

    if ((dst = of_queue_stats_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_queue_stats_reply_xid_get(src, &val32);
    of_queue_stats_reply_xid_set(dst, val32);

    of_queue_stats_reply_flags_get(src, &val16);
    of_queue_stats_reply_flags_set(dst, val16);

    of_queue_stats_reply_entries_bind(
        src, &src_list);
    dst_list = of_list_queue_stats_entry_OF_VERSION_1_1_dup(&src_list);
    if (dst_list == NULL) {
        of_queue_stats_reply_delete(dst);
        return NULL;
    }
    of_queue_stats_reply_entries_set(dst, dst_list);
    of_list_queue_stats_entry_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_queue_stats_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_queue_stats_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_queue_stats_request_t *
of_queue_stats_request_OF_VERSION_1_1_dup(
    of_queue_stats_request_t *src)
{
    of_queue_stats_request_t *dst;
    uint32_t val32;
    uint16_t val16;
    of_port_no_t port_no;

    if ((dst = of_queue_stats_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_queue_stats_request_xid_get(src, &val32);
    of_queue_stats_request_xid_set(dst, val32);

    of_queue_stats_request_flags_get(src, &val16);
    of_queue_stats_request_flags_set(dst, val16);

    of_queue_stats_request_port_no_get(src, &port_no);
    of_queue_stats_request_port_no_set(dst, port_no);

    of_queue_stats_request_queue_id_get(src, &val32);
    of_queue_stats_request_queue_id_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_set_config
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_set_config.
 *
 * The caller is responsible for deleting the returned value
 */
of_set_config_t *
of_set_config_OF_VERSION_1_1_dup(
    of_set_config_t *src)
{
    of_set_config_t *dst;
    uint32_t val32;
    uint16_t val16;

    if ((dst = of_set_config_new(src->version)) == NULL) {
        return NULL;
    }

    of_set_config_xid_get(src, &val32);
    of_set_config_xid_set(dst, val32);

    of_set_config_flags_get(src, &val16);
    of_set_config_flags_set(dst, val16);

    of_set_config_miss_send_len_get(src, &val16);
    of_set_config_miss_send_len_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_stats_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_stats_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_stats_reply_t *
of_stats_reply_OF_VERSION_1_1_dup(
    of_stats_reply_t *src)
{
    of_stats_reply_t *dst;
    uint32_t val32;
    uint16_t val16;

    if ((dst = of_stats_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_stats_reply_xid_get(src, &val32);
    of_stats_reply_xid_set(dst, val32);

    of_stats_reply_flags_get(src, &val16);
    of_stats_reply_flags_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_stats_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_stats_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_stats_request_t *
of_stats_request_OF_VERSION_1_1_dup(
    of_stats_request_t *src)
{
    of_stats_request_t *dst;
    uint32_t val32;
    uint16_t val16;

    if ((dst = of_stats_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_stats_request_xid_get(src, &val32);
    of_stats_request_xid_set(dst, val32);

    of_stats_request_flags_get(src, &val16);
    of_stats_request_flags_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_switch_config_failed_error_msg
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_switch_config_failed_error_msg.
 *
 * The caller is responsible for deleting the returned value
 */
of_switch_config_failed_error_msg_t *
of_switch_config_failed_error_msg_OF_VERSION_1_1_dup(
    of_switch_config_failed_error_msg_t *src)
{
    of_switch_config_failed_error_msg_t *dst;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    if ((dst = of_switch_config_failed_error_msg_new(src->version)) == NULL) {
        return NULL;
    }

    of_switch_config_failed_error_msg_xid_get(src, &val32);
    of_switch_config_failed_error_msg_xid_set(dst, val32);

    of_switch_config_failed_error_msg_code_get(src, &val16);
    of_switch_config_failed_error_msg_code_set(dst, val16);

    of_switch_config_failed_error_msg_data_get(src, &octets);
    of_switch_config_failed_error_msg_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_table_mod
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_table_mod.
 *
 * The caller is responsible for deleting the returned value
 */
of_table_mod_t *
of_table_mod_OF_VERSION_1_1_dup(
    of_table_mod_t *src)
{
    of_table_mod_t *dst;
    uint32_t val32;
    uint8_t val8;

    if ((dst = of_table_mod_new(src->version)) == NULL) {
        return NULL;
    }

    of_table_mod_xid_get(src, &val32);
    of_table_mod_xid_set(dst, val32);

    of_table_mod_table_id_get(src, &val8);
    of_table_mod_table_id_set(dst, val8);

    of_table_mod_config_get(src, &val32);
    of_table_mod_config_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_table_mod_failed_error_msg
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_table_mod_failed_error_msg.
 *
 * The caller is responsible for deleting the returned value
 */
of_table_mod_failed_error_msg_t *
of_table_mod_failed_error_msg_OF_VERSION_1_1_dup(
    of_table_mod_failed_error_msg_t *src)
{
    of_table_mod_failed_error_msg_t *dst;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    if ((dst = of_table_mod_failed_error_msg_new(src->version)) == NULL) {
        return NULL;
    }

    of_table_mod_failed_error_msg_xid_get(src, &val32);
    of_table_mod_failed_error_msg_xid_set(dst, val32);

    of_table_mod_failed_error_msg_code_get(src, &val16);
    of_table_mod_failed_error_msg_code_set(dst, val16);

    of_table_mod_failed_error_msg_data_get(src, &octets);
    of_table_mod_failed_error_msg_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_table_stats_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_table_stats_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_table_stats_reply_t *
of_table_stats_reply_OF_VERSION_1_1_dup(
    of_table_stats_reply_t *src)
{
    of_table_stats_reply_t *dst;
    uint32_t val32;
    uint16_t val16;

    of_list_table_stats_entry_t src_list;
    of_list_table_stats_entry_t *dst_list;

    if ((dst = of_table_stats_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_table_stats_reply_xid_get(src, &val32);
    of_table_stats_reply_xid_set(dst, val32);

    of_table_stats_reply_flags_get(src, &val16);
    of_table_stats_reply_flags_set(dst, val16);

    of_table_stats_reply_entries_bind(
        src, &src_list);
    dst_list = of_list_table_stats_entry_OF_VERSION_1_1_dup(&src_list);
    if (dst_list == NULL) {
        of_table_stats_reply_delete(dst);
        return NULL;
    }
    of_table_stats_reply_entries_set(dst, dst_list);
    of_list_table_stats_entry_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_table_stats_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_table_stats_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_table_stats_request_t *
of_table_stats_request_OF_VERSION_1_1_dup(
    of_table_stats_request_t *src)
{
    of_table_stats_request_t *dst;
    uint32_t val32;
    uint16_t val16;

    if ((dst = of_table_stats_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_table_stats_request_xid_get(src, &val32);
    of_table_stats_request_xid_set(dst, val32);

    of_table_stats_request_flags_get(src, &val16);
    of_table_stats_request_flags_set(dst, val16);

    return dst;
}

/**
 * Duplicate a super class object of type of_action
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_t *
of_action_OF_VERSION_1_1_dup(
    of_action_t *src)
{

    if (src->header.object_id == OF_ACTION_SET_NW_SRC) {
        return (of_action_t *)of_action_set_nw_src_OF_VERSION_1_1_dup(
            &src->set_nw_src);
    }

    if (src->header.object_id == OF_ACTION_SET_MPLS_TC) {
        return (of_action_t *)of_action_set_mpls_tc_OF_VERSION_1_1_dup(
            &src->set_mpls_tc);
    }

    if (src->header.object_id == OF_ACTION_BSN_MIRROR) {
        return (of_action_t *)of_action_bsn_mirror_OF_VERSION_1_1_dup(
            &src->bsn_mirror);
    }

    if (src->header.object_id == OF_ACTION_SET_NW_TOS) {
        return (of_action_t *)of_action_set_nw_tos_OF_VERSION_1_1_dup(
            &src->set_nw_tos);
    }

    if (src->header.object_id == OF_ACTION_DEC_MPLS_TTL) {
        return (of_action_t *)of_action_dec_mpls_ttl_OF_VERSION_1_1_dup(
            &src->dec_mpls_ttl);
    }

    if (src->header.object_id == OF_ACTION_BSN_SET_TUNNEL_DST) {
        return (of_action_t *)of_action_bsn_set_tunnel_dst_OF_VERSION_1_1_dup(
            &src->bsn_set_tunnel_dst);
    }

    if (src->header.object_id == OF_ACTION_SET_NW_DST) {
        return (of_action_t *)of_action_set_nw_dst_OF_VERSION_1_1_dup(
            &src->set_nw_dst);
    }

    if (src->header.object_id == OF_ACTION_SET_MPLS_LABEL) {
        return (of_action_t *)of_action_set_mpls_label_OF_VERSION_1_1_dup(
            &src->set_mpls_label);
    }

    if (src->header.object_id == OF_ACTION_GROUP) {
        return (of_action_t *)of_action_group_OF_VERSION_1_1_dup(
            &src->group);
    }

    if (src->header.object_id == OF_ACTION_COPY_TTL_OUT) {
        return (of_action_t *)of_action_copy_ttl_out_OF_VERSION_1_1_dup(
            &src->copy_ttl_out);
    }

    if (src->header.object_id == OF_ACTION_SET_VLAN_VID) {
        return (of_action_t *)of_action_set_vlan_vid_OF_VERSION_1_1_dup(
            &src->set_vlan_vid);
    }

    if (src->header.object_id == OF_ACTION_SET_MPLS_TTL) {
        return (of_action_t *)of_action_set_mpls_ttl_OF_VERSION_1_1_dup(
            &src->set_mpls_ttl);
    }

    if (src->header.object_id == OF_ACTION_POP_VLAN) {
        return (of_action_t *)of_action_pop_vlan_OF_VERSION_1_1_dup(
            &src->pop_vlan);
    }

    if (src->header.object_id == OF_ACTION_NICIRA_DEC_TTL) {
        return (of_action_t *)of_action_nicira_dec_ttl_OF_VERSION_1_1_dup(
            &src->nicira_dec_ttl);
    }

    if (src->header.object_id == OF_ACTION_SET_TP_DST) {
        return (of_action_t *)of_action_set_tp_dst_OF_VERSION_1_1_dup(
            &src->set_tp_dst);
    }

    if (src->header.object_id == OF_ACTION_POP_MPLS) {
        return (of_action_t *)of_action_pop_mpls_OF_VERSION_1_1_dup(
            &src->pop_mpls);
    }

    if (src->header.object_id == OF_ACTION_PUSH_VLAN) {
        return (of_action_t *)of_action_push_vlan_OF_VERSION_1_1_dup(
            &src->push_vlan);
    }

    if (src->header.object_id == OF_ACTION_SET_VLAN_PCP) {
        return (of_action_t *)of_action_set_vlan_pcp_OF_VERSION_1_1_dup(
            &src->set_vlan_pcp);
    }

    if (src->header.object_id == OF_ACTION_BSN) {
        return (of_action_t *)of_action_bsn_OF_VERSION_1_1_dup(
            &src->bsn);
    }

    if (src->header.object_id == OF_ACTION_EXPERIMENTER) {
        return (of_action_t *)of_action_experimenter_OF_VERSION_1_1_dup(
            &src->experimenter);
    }

    if (src->header.object_id == OF_ACTION_SET_NW_TTL) {
        return (of_action_t *)of_action_set_nw_ttl_OF_VERSION_1_1_dup(
            &src->set_nw_ttl);
    }

    if (src->header.object_id == OF_ACTION_COPY_TTL_IN) {
        return (of_action_t *)of_action_copy_ttl_in_OF_VERSION_1_1_dup(
            &src->copy_ttl_in);
    }

    if (src->header.object_id == OF_ACTION_NICIRA) {
        return (of_action_t *)of_action_nicira_OF_VERSION_1_1_dup(
            &src->nicira);
    }

    if (src->header.object_id == OF_ACTION_SET_NW_ECN) {
        return (of_action_t *)of_action_set_nw_ecn_OF_VERSION_1_1_dup(
            &src->set_nw_ecn);
    }

    if (src->header.object_id == OF_ACTION_SET_DL_DST) {
        return (of_action_t *)of_action_set_dl_dst_OF_VERSION_1_1_dup(
            &src->set_dl_dst);
    }

    if (src->header.object_id == OF_ACTION_PUSH_MPLS) {
        return (of_action_t *)of_action_push_mpls_OF_VERSION_1_1_dup(
            &src->push_mpls);
    }

    if (src->header.object_id == OF_ACTION_SET_TP_SRC) {
        return (of_action_t *)of_action_set_tp_src_OF_VERSION_1_1_dup(
            &src->set_tp_src);
    }

    if (src->header.object_id == OF_ACTION_DEC_NW_TTL) {
        return (of_action_t *)of_action_dec_nw_ttl_OF_VERSION_1_1_dup(
            &src->dec_nw_ttl);
    }

    if (src->header.object_id == OF_ACTION_SET_DL_SRC) {
        return (of_action_t *)of_action_set_dl_src_OF_VERSION_1_1_dup(
            &src->set_dl_src);
    }

    if (src->header.object_id == OF_ACTION_SET_QUEUE) {
        return (of_action_t *)of_action_set_queue_OF_VERSION_1_1_dup(
            &src->set_queue);
    }

    if (src->header.object_id == OF_ACTION_OUTPUT) {
        return (of_action_t *)of_action_output_OF_VERSION_1_1_dup(
            &src->output);
    }

    return NULL;
}

/**
 * Duplicate an object of type of_action_bsn
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_bsn.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_bsn_t *
of_action_bsn_OF_VERSION_1_1_dup(
    of_action_bsn_t *src)
{
    of_action_bsn_t *dst;
    uint32_t val32;

    if ((dst = of_action_bsn_new(src->version)) == NULL) {
        return NULL;
    }

    of_action_bsn_experimenter_get(src, &val32);
    of_action_bsn_experimenter_set(dst, val32);

    of_action_bsn_subtype_get(src, &val32);
    of_action_bsn_subtype_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_action_bsn_mirror
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_bsn_mirror.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_bsn_mirror_t *
of_action_bsn_mirror_OF_VERSION_1_1_dup(
    of_action_bsn_mirror_t *src)
{
    of_action_bsn_mirror_t *dst;
    uint32_t val32;
    uint8_t val8;

    if ((dst = of_action_bsn_mirror_new(src->version)) == NULL) {
        return NULL;
    }

    of_action_bsn_mirror_experimenter_get(src, &val32);
    of_action_bsn_mirror_experimenter_set(dst, val32);

    of_action_bsn_mirror_subtype_get(src, &val32);
    of_action_bsn_mirror_subtype_set(dst, val32);

    of_action_bsn_mirror_dest_port_get(src, &val32);
    of_action_bsn_mirror_dest_port_set(dst, val32);

    of_action_bsn_mirror_vlan_tag_get(src, &val32);
    of_action_bsn_mirror_vlan_tag_set(dst, val32);

    of_action_bsn_mirror_copy_stage_get(src, &val8);
    of_action_bsn_mirror_copy_stage_set(dst, val8);

    return dst;
}

/**
 * Duplicate an object of type of_action_bsn_set_tunnel_dst
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_bsn_set_tunnel_dst.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_bsn_set_tunnel_dst_t *
of_action_bsn_set_tunnel_dst_OF_VERSION_1_1_dup(
    of_action_bsn_set_tunnel_dst_t *src)
{
    of_action_bsn_set_tunnel_dst_t *dst;
    uint32_t val32;

    if ((dst = of_action_bsn_set_tunnel_dst_new(src->version)) == NULL) {
        return NULL;
    }

    of_action_bsn_set_tunnel_dst_experimenter_get(src, &val32);
    of_action_bsn_set_tunnel_dst_experimenter_set(dst, val32);

    of_action_bsn_set_tunnel_dst_subtype_get(src, &val32);
    of_action_bsn_set_tunnel_dst_subtype_set(dst, val32);

    of_action_bsn_set_tunnel_dst_dst_get(src, &val32);
    of_action_bsn_set_tunnel_dst_dst_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_action_copy_ttl_in
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_copy_ttl_in.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_copy_ttl_in_t *
of_action_copy_ttl_in_OF_VERSION_1_1_dup(
    of_action_copy_ttl_in_t *src)
{
    of_action_copy_ttl_in_t *dst;

    if ((dst = of_action_copy_ttl_in_new(src->version)) == NULL) {
        return NULL;
    }

    return dst;
}

/**
 * Duplicate an object of type of_action_copy_ttl_out
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_copy_ttl_out.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_copy_ttl_out_t *
of_action_copy_ttl_out_OF_VERSION_1_1_dup(
    of_action_copy_ttl_out_t *src)
{
    of_action_copy_ttl_out_t *dst;

    if ((dst = of_action_copy_ttl_out_new(src->version)) == NULL) {
        return NULL;
    }

    return dst;
}

/**
 * Duplicate an object of type of_action_dec_mpls_ttl
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_dec_mpls_ttl.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_dec_mpls_ttl_t *
of_action_dec_mpls_ttl_OF_VERSION_1_1_dup(
    of_action_dec_mpls_ttl_t *src)
{
    of_action_dec_mpls_ttl_t *dst;

    if ((dst = of_action_dec_mpls_ttl_new(src->version)) == NULL) {
        return NULL;
    }

    return dst;
}

/**
 * Duplicate an object of type of_action_dec_nw_ttl
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_dec_nw_ttl.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_dec_nw_ttl_t *
of_action_dec_nw_ttl_OF_VERSION_1_1_dup(
    of_action_dec_nw_ttl_t *src)
{
    of_action_dec_nw_ttl_t *dst;

    if ((dst = of_action_dec_nw_ttl_new(src->version)) == NULL) {
        return NULL;
    }

    return dst;
}

/**
 * Duplicate an object of type of_action_experimenter
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_experimenter.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_experimenter_t *
of_action_experimenter_OF_VERSION_1_1_dup(
    of_action_experimenter_t *src)
{
    of_action_experimenter_t *dst;
    uint32_t val32;
    of_octets_t octets;

    if ((dst = of_action_experimenter_new(src->version)) == NULL) {
        return NULL;
    }

    of_action_experimenter_experimenter_get(src, &val32);
    of_action_experimenter_experimenter_set(dst, val32);

    of_action_experimenter_data_get(src, &octets);
    of_action_experimenter_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_action_group
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_group.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_group_t *
of_action_group_OF_VERSION_1_1_dup(
    of_action_group_t *src)
{
    of_action_group_t *dst;
    uint32_t val32;

    if ((dst = of_action_group_new(src->version)) == NULL) {
        return NULL;
    }

    of_action_group_group_id_get(src, &val32);
    of_action_group_group_id_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_action_header
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_header.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_header_t *
of_action_header_OF_VERSION_1_1_dup(
    of_action_header_t *src)
{
    of_action_header_t *dst;

    if ((dst = of_action_header_new(src->version)) == NULL) {
        return NULL;
    }

    return dst;
}

/**
 * Duplicate an object of type of_action_nicira
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_nicira.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_nicira_t *
of_action_nicira_OF_VERSION_1_1_dup(
    of_action_nicira_t *src)
{
    of_action_nicira_t *dst;
    uint32_t val32;
    uint16_t val16;

    if ((dst = of_action_nicira_new(src->version)) == NULL) {
        return NULL;
    }

    of_action_nicira_experimenter_get(src, &val32);
    of_action_nicira_experimenter_set(dst, val32);

    of_action_nicira_subtype_get(src, &val16);
    of_action_nicira_subtype_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_action_nicira_dec_ttl
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_nicira_dec_ttl.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_nicira_dec_ttl_t *
of_action_nicira_dec_ttl_OF_VERSION_1_1_dup(
    of_action_nicira_dec_ttl_t *src)
{
    of_action_nicira_dec_ttl_t *dst;
    uint32_t val32;
    uint16_t val16;

    if ((dst = of_action_nicira_dec_ttl_new(src->version)) == NULL) {
        return NULL;
    }

    of_action_nicira_dec_ttl_experimenter_get(src, &val32);
    of_action_nicira_dec_ttl_experimenter_set(dst, val32);

    of_action_nicira_dec_ttl_subtype_get(src, &val16);
    of_action_nicira_dec_ttl_subtype_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_action_output
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_output.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_output_t *
of_action_output_OF_VERSION_1_1_dup(
    of_action_output_t *src)
{
    of_action_output_t *dst;
    of_port_no_t port_no;
    uint16_t val16;

    if ((dst = of_action_output_new(src->version)) == NULL) {
        return NULL;
    }

    of_action_output_port_get(src, &port_no);
    of_action_output_port_set(dst, port_no);

    of_action_output_max_len_get(src, &val16);
    of_action_output_max_len_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_action_pop_mpls
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_pop_mpls.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_pop_mpls_t *
of_action_pop_mpls_OF_VERSION_1_1_dup(
    of_action_pop_mpls_t *src)
{
    of_action_pop_mpls_t *dst;
    uint16_t val16;

    if ((dst = of_action_pop_mpls_new(src->version)) == NULL) {
        return NULL;
    }

    of_action_pop_mpls_ethertype_get(src, &val16);
    of_action_pop_mpls_ethertype_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_action_pop_vlan
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_pop_vlan.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_pop_vlan_t *
of_action_pop_vlan_OF_VERSION_1_1_dup(
    of_action_pop_vlan_t *src)
{
    of_action_pop_vlan_t *dst;

    if ((dst = of_action_pop_vlan_new(src->version)) == NULL) {
        return NULL;
    }

    return dst;
}

/**
 * Duplicate an object of type of_action_push_mpls
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_push_mpls.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_push_mpls_t *
of_action_push_mpls_OF_VERSION_1_1_dup(
    of_action_push_mpls_t *src)
{
    of_action_push_mpls_t *dst;
    uint16_t val16;

    if ((dst = of_action_push_mpls_new(src->version)) == NULL) {
        return NULL;
    }

    of_action_push_mpls_ethertype_get(src, &val16);
    of_action_push_mpls_ethertype_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_action_push_vlan
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_push_vlan.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_push_vlan_t *
of_action_push_vlan_OF_VERSION_1_1_dup(
    of_action_push_vlan_t *src)
{
    of_action_push_vlan_t *dst;
    uint16_t val16;

    if ((dst = of_action_push_vlan_new(src->version)) == NULL) {
        return NULL;
    }

    of_action_push_vlan_ethertype_get(src, &val16);
    of_action_push_vlan_ethertype_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_action_set_dl_dst
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_set_dl_dst.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_set_dl_dst_t *
of_action_set_dl_dst_OF_VERSION_1_1_dup(
    of_action_set_dl_dst_t *src)
{
    of_action_set_dl_dst_t *dst;
    of_mac_addr_t mac_addr;

    if ((dst = of_action_set_dl_dst_new(src->version)) == NULL) {
        return NULL;
    }

    of_action_set_dl_dst_dl_addr_get(src, &mac_addr);
    of_action_set_dl_dst_dl_addr_set(dst, mac_addr);

    return dst;
}

/**
 * Duplicate an object of type of_action_set_dl_src
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_set_dl_src.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_set_dl_src_t *
of_action_set_dl_src_OF_VERSION_1_1_dup(
    of_action_set_dl_src_t *src)
{
    of_action_set_dl_src_t *dst;
    of_mac_addr_t mac_addr;

    if ((dst = of_action_set_dl_src_new(src->version)) == NULL) {
        return NULL;
    }

    of_action_set_dl_src_dl_addr_get(src, &mac_addr);
    of_action_set_dl_src_dl_addr_set(dst, mac_addr);

    return dst;
}

/**
 * Duplicate an object of type of_action_set_mpls_label
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_set_mpls_label.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_set_mpls_label_t *
of_action_set_mpls_label_OF_VERSION_1_1_dup(
    of_action_set_mpls_label_t *src)
{
    of_action_set_mpls_label_t *dst;
    uint32_t val32;

    if ((dst = of_action_set_mpls_label_new(src->version)) == NULL) {
        return NULL;
    }

    of_action_set_mpls_label_mpls_label_get(src, &val32);
    of_action_set_mpls_label_mpls_label_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_action_set_mpls_tc
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_set_mpls_tc.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_set_mpls_tc_t *
of_action_set_mpls_tc_OF_VERSION_1_1_dup(
    of_action_set_mpls_tc_t *src)
{
    of_action_set_mpls_tc_t *dst;
    uint8_t val8;

    if ((dst = of_action_set_mpls_tc_new(src->version)) == NULL) {
        return NULL;
    }

    of_action_set_mpls_tc_mpls_tc_get(src, &val8);
    of_action_set_mpls_tc_mpls_tc_set(dst, val8);

    return dst;
}

/**
 * Duplicate an object of type of_action_set_mpls_ttl
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_set_mpls_ttl.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_set_mpls_ttl_t *
of_action_set_mpls_ttl_OF_VERSION_1_1_dup(
    of_action_set_mpls_ttl_t *src)
{
    of_action_set_mpls_ttl_t *dst;
    uint8_t val8;

    if ((dst = of_action_set_mpls_ttl_new(src->version)) == NULL) {
        return NULL;
    }

    of_action_set_mpls_ttl_mpls_ttl_get(src, &val8);
    of_action_set_mpls_ttl_mpls_ttl_set(dst, val8);

    return dst;
}

/**
 * Duplicate an object of type of_action_set_nw_dst
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_set_nw_dst.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_set_nw_dst_t *
of_action_set_nw_dst_OF_VERSION_1_1_dup(
    of_action_set_nw_dst_t *src)
{
    of_action_set_nw_dst_t *dst;
    uint32_t val32;

    if ((dst = of_action_set_nw_dst_new(src->version)) == NULL) {
        return NULL;
    }

    of_action_set_nw_dst_nw_addr_get(src, &val32);
    of_action_set_nw_dst_nw_addr_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_action_set_nw_ecn
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_set_nw_ecn.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_set_nw_ecn_t *
of_action_set_nw_ecn_OF_VERSION_1_1_dup(
    of_action_set_nw_ecn_t *src)
{
    of_action_set_nw_ecn_t *dst;
    uint8_t val8;

    if ((dst = of_action_set_nw_ecn_new(src->version)) == NULL) {
        return NULL;
    }

    of_action_set_nw_ecn_nw_ecn_get(src, &val8);
    of_action_set_nw_ecn_nw_ecn_set(dst, val8);

    return dst;
}

/**
 * Duplicate an object of type of_action_set_nw_src
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_set_nw_src.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_set_nw_src_t *
of_action_set_nw_src_OF_VERSION_1_1_dup(
    of_action_set_nw_src_t *src)
{
    of_action_set_nw_src_t *dst;
    uint32_t val32;

    if ((dst = of_action_set_nw_src_new(src->version)) == NULL) {
        return NULL;
    }

    of_action_set_nw_src_nw_addr_get(src, &val32);
    of_action_set_nw_src_nw_addr_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_action_set_nw_tos
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_set_nw_tos.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_set_nw_tos_t *
of_action_set_nw_tos_OF_VERSION_1_1_dup(
    of_action_set_nw_tos_t *src)
{
    of_action_set_nw_tos_t *dst;
    uint8_t val8;

    if ((dst = of_action_set_nw_tos_new(src->version)) == NULL) {
        return NULL;
    }

    of_action_set_nw_tos_nw_tos_get(src, &val8);
    of_action_set_nw_tos_nw_tos_set(dst, val8);

    return dst;
}

/**
 * Duplicate an object of type of_action_set_nw_ttl
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_set_nw_ttl.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_set_nw_ttl_t *
of_action_set_nw_ttl_OF_VERSION_1_1_dup(
    of_action_set_nw_ttl_t *src)
{
    of_action_set_nw_ttl_t *dst;
    uint8_t val8;

    if ((dst = of_action_set_nw_ttl_new(src->version)) == NULL) {
        return NULL;
    }

    of_action_set_nw_ttl_nw_ttl_get(src, &val8);
    of_action_set_nw_ttl_nw_ttl_set(dst, val8);

    return dst;
}

/**
 * Duplicate an object of type of_action_set_queue
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_set_queue.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_set_queue_t *
of_action_set_queue_OF_VERSION_1_1_dup(
    of_action_set_queue_t *src)
{
    of_action_set_queue_t *dst;
    uint32_t val32;

    if ((dst = of_action_set_queue_new(src->version)) == NULL) {
        return NULL;
    }

    of_action_set_queue_queue_id_get(src, &val32);
    of_action_set_queue_queue_id_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_action_set_tp_dst
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_set_tp_dst.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_set_tp_dst_t *
of_action_set_tp_dst_OF_VERSION_1_1_dup(
    of_action_set_tp_dst_t *src)
{
    of_action_set_tp_dst_t *dst;
    uint16_t val16;

    if ((dst = of_action_set_tp_dst_new(src->version)) == NULL) {
        return NULL;
    }

    of_action_set_tp_dst_tp_port_get(src, &val16);
    of_action_set_tp_dst_tp_port_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_action_set_tp_src
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_set_tp_src.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_set_tp_src_t *
of_action_set_tp_src_OF_VERSION_1_1_dup(
    of_action_set_tp_src_t *src)
{
    of_action_set_tp_src_t *dst;
    uint16_t val16;

    if ((dst = of_action_set_tp_src_new(src->version)) == NULL) {
        return NULL;
    }

    of_action_set_tp_src_tp_port_get(src, &val16);
    of_action_set_tp_src_tp_port_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_action_set_vlan_pcp
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_set_vlan_pcp.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_set_vlan_pcp_t *
of_action_set_vlan_pcp_OF_VERSION_1_1_dup(
    of_action_set_vlan_pcp_t *src)
{
    of_action_set_vlan_pcp_t *dst;
    uint8_t val8;

    if ((dst = of_action_set_vlan_pcp_new(src->version)) == NULL) {
        return NULL;
    }

    of_action_set_vlan_pcp_vlan_pcp_get(src, &val8);
    of_action_set_vlan_pcp_vlan_pcp_set(dst, val8);

    return dst;
}

/**
 * Duplicate an object of type of_action_set_vlan_vid
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_set_vlan_vid.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_set_vlan_vid_t *
of_action_set_vlan_vid_OF_VERSION_1_1_dup(
    of_action_set_vlan_vid_t *src)
{
    of_action_set_vlan_vid_t *dst;
    uint16_t val16;

    if ((dst = of_action_set_vlan_vid_new(src->version)) == NULL) {
        return NULL;
    }

    of_action_set_vlan_vid_vlan_vid_get(src, &val16);
    of_action_set_vlan_vid_vlan_vid_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_interface
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_interface.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_interface_t *
of_bsn_interface_OF_VERSION_1_1_dup(
    of_bsn_interface_t *src)
{
    of_bsn_interface_t *dst;
    of_mac_addr_t mac_addr;
    of_port_name_t port_name;
    of_ipv4_t ipv4;

    if ((dst = of_bsn_interface_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_interface_hw_addr_get(src, &mac_addr);
    of_bsn_interface_hw_addr_set(dst, mac_addr);

    of_bsn_interface_name_get(src, &port_name);
    of_bsn_interface_name_set(dst, port_name);

    of_bsn_interface_ipv4_addr_get(src, &ipv4);
    of_bsn_interface_ipv4_addr_set(dst, ipv4);

    of_bsn_interface_ipv4_netmask_get(src, &ipv4);
    of_bsn_interface_ipv4_netmask_set(dst, ipv4);

    return dst;
}

/**
 * Duplicate a super class object of type of_bsn_vport
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_vport.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_vport_t *
of_bsn_vport_OF_VERSION_1_1_dup(
    of_bsn_vport_t *src)
{

    if (src->header.object_id == OF_BSN_VPORT_Q_IN_Q) {
        return (of_bsn_vport_t *)of_bsn_vport_q_in_q_OF_VERSION_1_1_dup(
            &src->q_in_q);
    }

    return NULL;
}

/**
 * Duplicate an object of type of_bsn_vport_header
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_vport_header.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_vport_header_t *
of_bsn_vport_header_OF_VERSION_1_1_dup(
    of_bsn_vport_header_t *src)
{
    of_bsn_vport_header_t *dst;

    if ((dst = of_bsn_vport_header_new(src->version)) == NULL) {
        return NULL;
    }

    return dst;
}

/**
 * Duplicate an object of type of_bsn_vport_q_in_q
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_vport_q_in_q.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_vport_q_in_q_t *
of_bsn_vport_q_in_q_OF_VERSION_1_1_dup(
    of_bsn_vport_q_in_q_t *src)
{
    of_bsn_vport_q_in_q_t *dst;
    uint32_t val32;
    uint16_t val16;
    of_port_name_t port_name;

    if ((dst = of_bsn_vport_q_in_q_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_vport_q_in_q_port_no_get(src, &val32);
    of_bsn_vport_q_in_q_port_no_set(dst, val32);

    of_bsn_vport_q_in_q_ingress_tpid_get(src, &val16);
    of_bsn_vport_q_in_q_ingress_tpid_set(dst, val16);

    of_bsn_vport_q_in_q_ingress_vlan_id_get(src, &val16);
    of_bsn_vport_q_in_q_ingress_vlan_id_set(dst, val16);

    of_bsn_vport_q_in_q_egress_tpid_get(src, &val16);
    of_bsn_vport_q_in_q_egress_tpid_set(dst, val16);

    of_bsn_vport_q_in_q_egress_vlan_id_get(src, &val16);
    of_bsn_vport_q_in_q_egress_vlan_id_set(dst, val16);

    of_bsn_vport_q_in_q_if_name_get(src, &port_name);
    of_bsn_vport_q_in_q_if_name_set(dst, port_name);

    return dst;
}

/**
 * Duplicate an object of type of_bucket
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bucket.
 *
 * The caller is responsible for deleting the returned value
 */
of_bucket_t *
of_bucket_OF_VERSION_1_1_dup(
    of_bucket_t *src)
{
    of_bucket_t *dst;
    uint16_t val16;
    of_port_no_t port_no;
    uint32_t val32;

    of_list_action_t src_list;
    of_list_action_t *dst_list;

    if ((dst = of_bucket_new(src->version)) == NULL) {
        return NULL;
    }

    of_bucket_weight_get(src, &val16);
    of_bucket_weight_set(dst, val16);

    of_bucket_watch_port_get(src, &port_no);
    of_bucket_watch_port_set(dst, port_no);

    of_bucket_watch_group_get(src, &val32);
    of_bucket_watch_group_set(dst, val32);

    of_bucket_actions_bind(
        src, &src_list);
    dst_list = of_list_action_OF_VERSION_1_1_dup(&src_list);
    if (dst_list == NULL) {
        of_bucket_delete(dst);
        return NULL;
    }
    of_bucket_actions_set(dst, dst_list);
    of_list_action_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_bucket_counter
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bucket_counter.
 *
 * The caller is responsible for deleting the returned value
 */
of_bucket_counter_t *
of_bucket_counter_OF_VERSION_1_1_dup(
    of_bucket_counter_t *src)
{
    of_bucket_counter_t *dst;
    uint64_t val64;

    if ((dst = of_bucket_counter_new(src->version)) == NULL) {
        return NULL;
    }

    of_bucket_counter_packet_count_get(src, &val64);
    of_bucket_counter_packet_count_set(dst, val64);

    of_bucket_counter_byte_count_get(src, &val64);
    of_bucket_counter_byte_count_set(dst, val64);

    return dst;
}

/**
 * Duplicate an object of type of_flow_stats_entry
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_flow_stats_entry.
 *
 * The caller is responsible for deleting the returned value
 */
of_flow_stats_entry_t *
of_flow_stats_entry_OF_VERSION_1_1_dup(
    of_flow_stats_entry_t *src)
{
    of_flow_stats_entry_t *dst;
    uint8_t val8;
    uint32_t val32;
    uint16_t val16;
    uint64_t val64;
    of_match_t match;

    of_list_instruction_t src_list;
    of_list_instruction_t *dst_list;

    if ((dst = of_flow_stats_entry_new(src->version)) == NULL) {
        return NULL;
    }

    of_flow_stats_entry_table_id_get(src, &val8);
    of_flow_stats_entry_table_id_set(dst, val8);

    of_flow_stats_entry_duration_sec_get(src, &val32);
    of_flow_stats_entry_duration_sec_set(dst, val32);

    of_flow_stats_entry_duration_nsec_get(src, &val32);
    of_flow_stats_entry_duration_nsec_set(dst, val32);

    of_flow_stats_entry_priority_get(src, &val16);
    of_flow_stats_entry_priority_set(dst, val16);

    of_flow_stats_entry_idle_timeout_get(src, &val16);
    of_flow_stats_entry_idle_timeout_set(dst, val16);

    of_flow_stats_entry_hard_timeout_get(src, &val16);
    of_flow_stats_entry_hard_timeout_set(dst, val16);

    of_flow_stats_entry_cookie_get(src, &val64);
    of_flow_stats_entry_cookie_set(dst, val64);

    of_flow_stats_entry_packet_count_get(src, &val64);
    of_flow_stats_entry_packet_count_set(dst, val64);

    of_flow_stats_entry_byte_count_get(src, &val64);
    of_flow_stats_entry_byte_count_set(dst, val64);

    of_flow_stats_entry_match_get(src, &match);
    of_flow_stats_entry_match_set(dst, &match);

    of_flow_stats_entry_instructions_bind(
        src, &src_list);
    dst_list = of_list_instruction_OF_VERSION_1_1_dup(&src_list);
    if (dst_list == NULL) {
        of_flow_stats_entry_delete(dst);
        return NULL;
    }
    of_flow_stats_entry_instructions_set(dst, dst_list);
    of_list_instruction_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_group_desc_stats_entry
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_group_desc_stats_entry.
 *
 * The caller is responsible for deleting the returned value
 */
of_group_desc_stats_entry_t *
of_group_desc_stats_entry_OF_VERSION_1_1_dup(
    of_group_desc_stats_entry_t *src)
{
    of_group_desc_stats_entry_t *dst;
    uint8_t val8;
    uint32_t val32;

    of_list_bucket_t src_list;
    of_list_bucket_t *dst_list;

    if ((dst = of_group_desc_stats_entry_new(src->version)) == NULL) {
        return NULL;
    }

    of_group_desc_stats_entry_group_type_get(src, &val8);
    of_group_desc_stats_entry_group_type_set(dst, val8);

    of_group_desc_stats_entry_group_id_get(src, &val32);
    of_group_desc_stats_entry_group_id_set(dst, val32);

    of_group_desc_stats_entry_buckets_bind(
        src, &src_list);
    dst_list = of_list_bucket_OF_VERSION_1_1_dup(&src_list);
    if (dst_list == NULL) {
        of_group_desc_stats_entry_delete(dst);
        return NULL;
    }
    of_group_desc_stats_entry_buckets_set(dst, dst_list);
    of_list_bucket_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_group_stats_entry
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_group_stats_entry.
 *
 * The caller is responsible for deleting the returned value
 */
of_group_stats_entry_t *
of_group_stats_entry_OF_VERSION_1_1_dup(
    of_group_stats_entry_t *src)
{
    of_group_stats_entry_t *dst;
    uint32_t val32;
    uint64_t val64;

    of_list_bucket_counter_t src_list;
    of_list_bucket_counter_t *dst_list;

    if ((dst = of_group_stats_entry_new(src->version)) == NULL) {
        return NULL;
    }

    of_group_stats_entry_group_id_get(src, &val32);
    of_group_stats_entry_group_id_set(dst, val32);

    of_group_stats_entry_ref_count_get(src, &val32);
    of_group_stats_entry_ref_count_set(dst, val32);

    of_group_stats_entry_packet_count_get(src, &val64);
    of_group_stats_entry_packet_count_set(dst, val64);

    of_group_stats_entry_byte_count_get(src, &val64);
    of_group_stats_entry_byte_count_set(dst, val64);

    of_group_stats_entry_bucket_stats_bind(
        src, &src_list);
    dst_list = of_list_bucket_counter_OF_VERSION_1_1_dup(&src_list);
    if (dst_list == NULL) {
        of_group_stats_entry_delete(dst);
        return NULL;
    }
    of_group_stats_entry_bucket_stats_set(dst, dst_list);
    of_list_bucket_counter_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_header
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_header.
 *
 * The caller is responsible for deleting the returned value
 */
of_header_t *
of_header_OF_VERSION_1_1_dup(
    of_header_t *src)
{
    of_header_t *dst;
    uint32_t val32;

    if ((dst = of_header_new(src->version)) == NULL) {
        return NULL;
    }

    of_header_xid_get(src, &val32);
    of_header_xid_set(dst, val32);

    return dst;
}

/**
 * Duplicate a super class object of type of_instruction
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_instruction.
 *
 * The caller is responsible for deleting the returned value
 */
of_instruction_t *
of_instruction_OF_VERSION_1_1_dup(
    of_instruction_t *src)
{

    if (src->header.object_id == OF_INSTRUCTION_CLEAR_ACTIONS) {
        return (of_instruction_t *)of_instruction_clear_actions_OF_VERSION_1_1_dup(
            &src->clear_actions);
    }

    if (src->header.object_id == OF_INSTRUCTION_WRITE_ACTIONS) {
        return (of_instruction_t *)of_instruction_write_actions_OF_VERSION_1_1_dup(
            &src->write_actions);
    }

    if (src->header.object_id == OF_INSTRUCTION_GOTO_TABLE) {
        return (of_instruction_t *)of_instruction_goto_table_OF_VERSION_1_1_dup(
            &src->goto_table);
    }

    if (src->header.object_id == OF_INSTRUCTION_APPLY_ACTIONS) {
        return (of_instruction_t *)of_instruction_apply_actions_OF_VERSION_1_1_dup(
            &src->apply_actions);
    }

    if (src->header.object_id == OF_INSTRUCTION_EXPERIMENTER) {
        return (of_instruction_t *)of_instruction_experimenter_OF_VERSION_1_1_dup(
            &src->experimenter);
    }

    if (src->header.object_id == OF_INSTRUCTION_WRITE_METADATA) {
        return (of_instruction_t *)of_instruction_write_metadata_OF_VERSION_1_1_dup(
            &src->write_metadata);
    }

    return NULL;
}

/**
 * Duplicate an object of type of_instruction_apply_actions
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_instruction_apply_actions.
 *
 * The caller is responsible for deleting the returned value
 */
of_instruction_apply_actions_t *
of_instruction_apply_actions_OF_VERSION_1_1_dup(
    of_instruction_apply_actions_t *src)
{
    of_instruction_apply_actions_t *dst;

    of_list_action_t src_list;
    of_list_action_t *dst_list;

    if ((dst = of_instruction_apply_actions_new(src->version)) == NULL) {
        return NULL;
    }

    of_instruction_apply_actions_actions_bind(
        src, &src_list);
    dst_list = of_list_action_OF_VERSION_1_1_dup(&src_list);
    if (dst_list == NULL) {
        of_instruction_apply_actions_delete(dst);
        return NULL;
    }
    of_instruction_apply_actions_actions_set(dst, dst_list);
    of_list_action_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_instruction_clear_actions
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_instruction_clear_actions.
 *
 * The caller is responsible for deleting the returned value
 */
of_instruction_clear_actions_t *
of_instruction_clear_actions_OF_VERSION_1_1_dup(
    of_instruction_clear_actions_t *src)
{
    of_instruction_clear_actions_t *dst;

    if ((dst = of_instruction_clear_actions_new(src->version)) == NULL) {
        return NULL;
    }

    return dst;
}

/**
 * Duplicate an object of type of_instruction_experimenter
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_instruction_experimenter.
 *
 * The caller is responsible for deleting the returned value
 */
of_instruction_experimenter_t *
of_instruction_experimenter_OF_VERSION_1_1_dup(
    of_instruction_experimenter_t *src)
{
    of_instruction_experimenter_t *dst;
    uint32_t val32;
    of_octets_t octets;

    if ((dst = of_instruction_experimenter_new(src->version)) == NULL) {
        return NULL;
    }

    of_instruction_experimenter_experimenter_get(src, &val32);
    of_instruction_experimenter_experimenter_set(dst, val32);

    of_instruction_experimenter_data_get(src, &octets);
    of_instruction_experimenter_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_instruction_goto_table
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_instruction_goto_table.
 *
 * The caller is responsible for deleting the returned value
 */
of_instruction_goto_table_t *
of_instruction_goto_table_OF_VERSION_1_1_dup(
    of_instruction_goto_table_t *src)
{
    of_instruction_goto_table_t *dst;
    uint8_t val8;

    if ((dst = of_instruction_goto_table_new(src->version)) == NULL) {
        return NULL;
    }

    of_instruction_goto_table_table_id_get(src, &val8);
    of_instruction_goto_table_table_id_set(dst, val8);

    return dst;
}

/**
 * Duplicate an object of type of_instruction_header
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_instruction_header.
 *
 * The caller is responsible for deleting the returned value
 */
of_instruction_header_t *
of_instruction_header_OF_VERSION_1_1_dup(
    of_instruction_header_t *src)
{
    of_instruction_header_t *dst;

    if ((dst = of_instruction_header_new(src->version)) == NULL) {
        return NULL;
    }

    return dst;
}

/**
 * Duplicate an object of type of_instruction_write_actions
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_instruction_write_actions.
 *
 * The caller is responsible for deleting the returned value
 */
of_instruction_write_actions_t *
of_instruction_write_actions_OF_VERSION_1_1_dup(
    of_instruction_write_actions_t *src)
{
    of_instruction_write_actions_t *dst;

    of_list_action_t src_list;
    of_list_action_t *dst_list;

    if ((dst = of_instruction_write_actions_new(src->version)) == NULL) {
        return NULL;
    }

    of_instruction_write_actions_actions_bind(
        src, &src_list);
    dst_list = of_list_action_OF_VERSION_1_1_dup(&src_list);
    if (dst_list == NULL) {
        of_instruction_write_actions_delete(dst);
        return NULL;
    }
    of_instruction_write_actions_actions_set(dst, dst_list);
    of_list_action_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_instruction_write_metadata
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_instruction_write_metadata.
 *
 * The caller is responsible for deleting the returned value
 */
of_instruction_write_metadata_t *
of_instruction_write_metadata_OF_VERSION_1_1_dup(
    of_instruction_write_metadata_t *src)
{
    of_instruction_write_metadata_t *dst;
    uint64_t val64;

    if ((dst = of_instruction_write_metadata_new(src->version)) == NULL) {
        return NULL;
    }

    of_instruction_write_metadata_metadata_get(src, &val64);
    of_instruction_write_metadata_metadata_set(dst, val64);

    of_instruction_write_metadata_metadata_mask_get(src, &val64);
    of_instruction_write_metadata_metadata_mask_set(dst, val64);

    return dst;
}

/**
 * Duplicate an object of type of_match_v2
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_match_v2.
 *
 * The caller is responsible for deleting the returned value
 */
of_match_v2_t *
of_match_v2_OF_VERSION_1_1_dup(
    of_match_v2_t *src)
{
    of_match_v2_t *dst;
    of_port_no_t port_no;
    of_wc_bmap_t wc_bmap;
    of_mac_addr_t mac_addr;
    uint16_t val16;
    uint8_t val8;
    of_ipv4_t ipv4;
    uint32_t val32;
    uint64_t val64;

    if ((dst = of_match_v2_new(src->version)) == NULL) {
        return NULL;
    }

    of_match_v2_in_port_get(src, &port_no);
    of_match_v2_in_port_set(dst, port_no);

    of_match_v2_wildcards_get(src, &wc_bmap);
    of_match_v2_wildcards_set(dst, wc_bmap);

    of_match_v2_eth_src_get(src, &mac_addr);
    of_match_v2_eth_src_set(dst, mac_addr);

    of_match_v2_eth_src_mask_get(src, &mac_addr);
    of_match_v2_eth_src_mask_set(dst, mac_addr);

    of_match_v2_eth_dst_get(src, &mac_addr);
    of_match_v2_eth_dst_set(dst, mac_addr);

    of_match_v2_eth_dst_mask_get(src, &mac_addr);
    of_match_v2_eth_dst_mask_set(dst, mac_addr);

    of_match_v2_vlan_vid_get(src, &val16);
    of_match_v2_vlan_vid_set(dst, val16);

    of_match_v2_vlan_pcp_get(src, &val8);
    of_match_v2_vlan_pcp_set(dst, val8);

    of_match_v2_eth_type_get(src, &val16);
    of_match_v2_eth_type_set(dst, val16);

    of_match_v2_ip_dscp_get(src, &val8);
    of_match_v2_ip_dscp_set(dst, val8);

    of_match_v2_ip_proto_get(src, &val8);
    of_match_v2_ip_proto_set(dst, val8);

    of_match_v2_ipv4_src_get(src, &ipv4);
    of_match_v2_ipv4_src_set(dst, ipv4);

    of_match_v2_ipv4_src_mask_get(src, &ipv4);
    of_match_v2_ipv4_src_mask_set(dst, ipv4);

    of_match_v2_ipv4_dst_get(src, &ipv4);
    of_match_v2_ipv4_dst_set(dst, ipv4);

    of_match_v2_ipv4_dst_mask_get(src, &ipv4);
    of_match_v2_ipv4_dst_mask_set(dst, ipv4);

    of_match_v2_tcp_src_get(src, &val16);
    of_match_v2_tcp_src_set(dst, val16);

    of_match_v2_tcp_dst_get(src, &val16);
    of_match_v2_tcp_dst_set(dst, val16);

    of_match_v2_mpls_label_get(src, &val32);
    of_match_v2_mpls_label_set(dst, val32);

    of_match_v2_mpls_tc_get(src, &val8);
    of_match_v2_mpls_tc_set(dst, val8);

    of_match_v2_metadata_get(src, &val64);
    of_match_v2_metadata_set(dst, val64);

    of_match_v2_metadata_mask_get(src, &val64);
    of_match_v2_metadata_mask_set(dst, val64);

    return dst;
}

/**
 * Duplicate an object of type of_packet_queue
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_packet_queue.
 *
 * The caller is responsible for deleting the returned value
 */
of_packet_queue_t *
of_packet_queue_OF_VERSION_1_1_dup(
    of_packet_queue_t *src)
{
    of_packet_queue_t *dst;
    uint32_t val32;

    of_list_queue_prop_t src_list;
    of_list_queue_prop_t *dst_list;

    if ((dst = of_packet_queue_new(src->version)) == NULL) {
        return NULL;
    }

    of_packet_queue_queue_id_get(src, &val32);
    of_packet_queue_queue_id_set(dst, val32);

    of_packet_queue_properties_bind(
        src, &src_list);
    dst_list = of_list_queue_prop_OF_VERSION_1_1_dup(&src_list);
    if (dst_list == NULL) {
        of_packet_queue_delete(dst);
        return NULL;
    }
    of_packet_queue_properties_set(dst, dst_list);
    of_list_queue_prop_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_port_desc
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_port_desc.
 *
 * The caller is responsible for deleting the returned value
 */
of_port_desc_t *
of_port_desc_OF_VERSION_1_1_dup(
    of_port_desc_t *src)
{
    of_port_desc_t *dst;
    of_port_no_t port_no;
    of_mac_addr_t mac_addr;
    of_port_name_t port_name;
    uint32_t val32;

    if ((dst = of_port_desc_new(src->version)) == NULL) {
        return NULL;
    }

    of_port_desc_port_no_get(src, &port_no);
    of_port_desc_port_no_set(dst, port_no);

    of_port_desc_hw_addr_get(src, &mac_addr);
    of_port_desc_hw_addr_set(dst, mac_addr);

    of_port_desc_name_get(src, &port_name);
    of_port_desc_name_set(dst, port_name);

    of_port_desc_config_get(src, &val32);
    of_port_desc_config_set(dst, val32);

    of_port_desc_state_get(src, &val32);
    of_port_desc_state_set(dst, val32);

    of_port_desc_curr_get(src, &val32);
    of_port_desc_curr_set(dst, val32);

    of_port_desc_advertised_get(src, &val32);
    of_port_desc_advertised_set(dst, val32);

    of_port_desc_supported_get(src, &val32);
    of_port_desc_supported_set(dst, val32);

    of_port_desc_peer_get(src, &val32);
    of_port_desc_peer_set(dst, val32);

    of_port_desc_curr_speed_get(src, &val32);
    of_port_desc_curr_speed_set(dst, val32);

    of_port_desc_max_speed_get(src, &val32);
    of_port_desc_max_speed_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_port_stats_entry
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_port_stats_entry.
 *
 * The caller is responsible for deleting the returned value
 */
of_port_stats_entry_t *
of_port_stats_entry_OF_VERSION_1_1_dup(
    of_port_stats_entry_t *src)
{
    of_port_stats_entry_t *dst;
    of_port_no_t port_no;
    uint64_t val64;

    if ((dst = of_port_stats_entry_new(src->version)) == NULL) {
        return NULL;
    }

    of_port_stats_entry_port_no_get(src, &port_no);
    of_port_stats_entry_port_no_set(dst, port_no);

    of_port_stats_entry_rx_packets_get(src, &val64);
    of_port_stats_entry_rx_packets_set(dst, val64);

    of_port_stats_entry_tx_packets_get(src, &val64);
    of_port_stats_entry_tx_packets_set(dst, val64);

    of_port_stats_entry_rx_bytes_get(src, &val64);
    of_port_stats_entry_rx_bytes_set(dst, val64);

    of_port_stats_entry_tx_bytes_get(src, &val64);
    of_port_stats_entry_tx_bytes_set(dst, val64);

    of_port_stats_entry_rx_dropped_get(src, &val64);
    of_port_stats_entry_rx_dropped_set(dst, val64);

    of_port_stats_entry_tx_dropped_get(src, &val64);
    of_port_stats_entry_tx_dropped_set(dst, val64);

    of_port_stats_entry_rx_errors_get(src, &val64);
    of_port_stats_entry_rx_errors_set(dst, val64);

    of_port_stats_entry_tx_errors_get(src, &val64);
    of_port_stats_entry_tx_errors_set(dst, val64);

    of_port_stats_entry_rx_frame_err_get(src, &val64);
    of_port_stats_entry_rx_frame_err_set(dst, val64);

    of_port_stats_entry_rx_over_err_get(src, &val64);
    of_port_stats_entry_rx_over_err_set(dst, val64);

    of_port_stats_entry_rx_crc_err_get(src, &val64);
    of_port_stats_entry_rx_crc_err_set(dst, val64);

    of_port_stats_entry_collisions_get(src, &val64);
    of_port_stats_entry_collisions_set(dst, val64);

    return dst;
}

/**
 * Duplicate a super class object of type of_queue_prop
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_queue_prop.
 *
 * The caller is responsible for deleting the returned value
 */
of_queue_prop_t *
of_queue_prop_OF_VERSION_1_1_dup(
    of_queue_prop_t *src)
{

    if (src->header.object_id == OF_QUEUE_PROP_MIN_RATE) {
        return (of_queue_prop_t *)of_queue_prop_min_rate_OF_VERSION_1_1_dup(
            &src->min_rate);
    }

    return NULL;
}

/**
 * Duplicate an object of type of_queue_prop_header
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_queue_prop_header.
 *
 * The caller is responsible for deleting the returned value
 */
of_queue_prop_header_t *
of_queue_prop_header_OF_VERSION_1_1_dup(
    of_queue_prop_header_t *src)
{
    of_queue_prop_header_t *dst;

    if ((dst = of_queue_prop_header_new(src->version)) == NULL) {
        return NULL;
    }

    return dst;
}

/**
 * Duplicate an object of type of_queue_prop_min_rate
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_queue_prop_min_rate.
 *
 * The caller is responsible for deleting the returned value
 */
of_queue_prop_min_rate_t *
of_queue_prop_min_rate_OF_VERSION_1_1_dup(
    of_queue_prop_min_rate_t *src)
{
    of_queue_prop_min_rate_t *dst;
    uint16_t val16;

    if ((dst = of_queue_prop_min_rate_new(src->version)) == NULL) {
        return NULL;
    }

    of_queue_prop_min_rate_rate_get(src, &val16);
    of_queue_prop_min_rate_rate_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_queue_stats_entry
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_queue_stats_entry.
 *
 * The caller is responsible for deleting the returned value
 */
of_queue_stats_entry_t *
of_queue_stats_entry_OF_VERSION_1_1_dup(
    of_queue_stats_entry_t *src)
{
    of_queue_stats_entry_t *dst;
    of_port_no_t port_no;
    uint32_t val32;
    uint64_t val64;

    if ((dst = of_queue_stats_entry_new(src->version)) == NULL) {
        return NULL;
    }

    of_queue_stats_entry_port_no_get(src, &port_no);
    of_queue_stats_entry_port_no_set(dst, port_no);

    of_queue_stats_entry_queue_id_get(src, &val32);
    of_queue_stats_entry_queue_id_set(dst, val32);

    of_queue_stats_entry_tx_bytes_get(src, &val64);
    of_queue_stats_entry_tx_bytes_set(dst, val64);

    of_queue_stats_entry_tx_packets_get(src, &val64);
    of_queue_stats_entry_tx_packets_set(dst, val64);

    of_queue_stats_entry_tx_errors_get(src, &val64);
    of_queue_stats_entry_tx_errors_set(dst, val64);

    return dst;
}

/**
 * Duplicate an object of type of_table_stats_entry
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_table_stats_entry.
 *
 * The caller is responsible for deleting the returned value
 */
of_table_stats_entry_t *
of_table_stats_entry_OF_VERSION_1_1_dup(
    of_table_stats_entry_t *src)
{
    of_table_stats_entry_t *dst;
    uint8_t val8;
    of_table_name_t table_name;
    of_wc_bmap_t wc_bmap;
    of_match_bmap_t match_bmap;
    uint32_t val32;
    uint64_t val64;

    if ((dst = of_table_stats_entry_new(src->version)) == NULL) {
        return NULL;
    }

    of_table_stats_entry_table_id_get(src, &val8);
    of_table_stats_entry_table_id_set(dst, val8);

    of_table_stats_entry_name_get(src, &table_name);
    of_table_stats_entry_name_set(dst, table_name);

    of_table_stats_entry_wildcards_get(src, &wc_bmap);
    of_table_stats_entry_wildcards_set(dst, wc_bmap);

    of_table_stats_entry_match_get(src, &match_bmap);
    of_table_stats_entry_match_set(dst, match_bmap);

    of_table_stats_entry_instructions_get(src, &val32);
    of_table_stats_entry_instructions_set(dst, val32);

    of_table_stats_entry_write_actions_get(src, &val32);
    of_table_stats_entry_write_actions_set(dst, val32);

    of_table_stats_entry_apply_actions_get(src, &val32);
    of_table_stats_entry_apply_actions_set(dst, val32);

    of_table_stats_entry_config_get(src, &val32);
    of_table_stats_entry_config_set(dst, val32);

    of_table_stats_entry_max_entries_get(src, &val32);
    of_table_stats_entry_max_entries_set(dst, val32);

    of_table_stats_entry_active_count_get(src, &val32);
    of_table_stats_entry_active_count_set(dst, val32);

    of_table_stats_entry_lookup_count_get(src, &val64);
    of_table_stats_entry_lookup_count_set(dst, val64);

    of_table_stats_entry_matched_count_get(src, &val64);
    of_table_stats_entry_matched_count_set(dst, val64);

    return dst;
}

/**
 * Duplicate a list of type of_list_action
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_list_action.
 *
 * The caller is responsible for deleting the returned value
 */
of_list_action_t *
of_list_action_OF_VERSION_1_1_dup(
    of_list_action_t *src)
{
    of_action_t src_elt;
    of_action_t *dst_elt;
    int rv;
    of_list_action_t *dst;

    if ((dst = of_list_action_new(src->version)) == NULL) {
        return NULL;
    }

    OF_LIST_ACTION_ITER(src, &src_elt, rv) {
        if ((dst_elt = of_action_OF_VERSION_1_1_dup(&src_elt)) == NULL) {
            of_object_delete((of_object_t *)dst);
            return NULL;
        }
        _TRY_FREE(of_list_action_append(dst, dst_elt),
            dst, NULL);
        of_object_delete((of_object_t *)dst_elt);
    }

    return dst;
}

/**
 * Duplicate a list of type of_list_bsn_interface
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_list_bsn_interface.
 *
 * The caller is responsible for deleting the returned value
 */
of_list_bsn_interface_t *
of_list_bsn_interface_OF_VERSION_1_1_dup(
    of_list_bsn_interface_t *src)
{
    of_bsn_interface_t src_elt;
    of_bsn_interface_t *dst_elt;
    int rv;
    of_list_bsn_interface_t *dst;

    if ((dst = of_list_bsn_interface_new(src->version)) == NULL) {
        return NULL;
    }

    OF_LIST_BSN_INTERFACE_ITER(src, &src_elt, rv) {
        if ((dst_elt = of_bsn_interface_OF_VERSION_1_1_dup(&src_elt)) == NULL) {
            of_object_delete((of_object_t *)dst);
            return NULL;
        }
        _TRY_FREE(of_list_bsn_interface_append(dst, dst_elt),
            dst, NULL);
        of_object_delete((of_object_t *)dst_elt);
    }

    return dst;
}

/**
 * Duplicate a list of type of_list_bucket
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_list_bucket.
 *
 * The caller is responsible for deleting the returned value
 */
of_list_bucket_t *
of_list_bucket_OF_VERSION_1_1_dup(
    of_list_bucket_t *src)
{
    of_bucket_t src_elt;
    of_bucket_t *dst_elt;
    int rv;
    of_list_bucket_t *dst;

    if ((dst = of_list_bucket_new(src->version)) == NULL) {
        return NULL;
    }

    OF_LIST_BUCKET_ITER(src, &src_elt, rv) {
        if ((dst_elt = of_bucket_OF_VERSION_1_1_dup(&src_elt)) == NULL) {
            of_object_delete((of_object_t *)dst);
            return NULL;
        }
        _TRY_FREE(of_list_bucket_append(dst, dst_elt),
            dst, NULL);
        of_object_delete((of_object_t *)dst_elt);
    }

    return dst;
}

/**
 * Duplicate a list of type of_list_bucket_counter
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_list_bucket_counter.
 *
 * The caller is responsible for deleting the returned value
 */
of_list_bucket_counter_t *
of_list_bucket_counter_OF_VERSION_1_1_dup(
    of_list_bucket_counter_t *src)
{
    of_bucket_counter_t src_elt;
    of_bucket_counter_t *dst_elt;
    int rv;
    of_list_bucket_counter_t *dst;

    if ((dst = of_list_bucket_counter_new(src->version)) == NULL) {
        return NULL;
    }

    OF_LIST_BUCKET_COUNTER_ITER(src, &src_elt, rv) {
        if ((dst_elt = of_bucket_counter_OF_VERSION_1_1_dup(&src_elt)) == NULL) {
            of_object_delete((of_object_t *)dst);
            return NULL;
        }
        _TRY_FREE(of_list_bucket_counter_append(dst, dst_elt),
            dst, NULL);
        of_object_delete((of_object_t *)dst_elt);
    }

    return dst;
}

/**
 * Duplicate a list of type of_list_flow_stats_entry
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_list_flow_stats_entry.
 *
 * The caller is responsible for deleting the returned value
 */
of_list_flow_stats_entry_t *
of_list_flow_stats_entry_OF_VERSION_1_1_dup(
    of_list_flow_stats_entry_t *src)
{
    of_flow_stats_entry_t src_elt;
    of_flow_stats_entry_t *dst_elt;
    int rv;
    of_list_flow_stats_entry_t *dst;

    if ((dst = of_list_flow_stats_entry_new(src->version)) == NULL) {
        return NULL;
    }

    OF_LIST_FLOW_STATS_ENTRY_ITER(src, &src_elt, rv) {
        if ((dst_elt = of_flow_stats_entry_OF_VERSION_1_1_dup(&src_elt)) == NULL) {
            of_object_delete((of_object_t *)dst);
            return NULL;
        }
        _TRY_FREE(of_list_flow_stats_entry_append(dst, dst_elt),
            dst, NULL);
        of_object_delete((of_object_t *)dst_elt);
    }

    return dst;
}

/**
 * Duplicate a list of type of_list_group_desc_stats_entry
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_list_group_desc_stats_entry.
 *
 * The caller is responsible for deleting the returned value
 */
of_list_group_desc_stats_entry_t *
of_list_group_desc_stats_entry_OF_VERSION_1_1_dup(
    of_list_group_desc_stats_entry_t *src)
{
    of_group_desc_stats_entry_t src_elt;
    of_group_desc_stats_entry_t *dst_elt;
    int rv;
    of_list_group_desc_stats_entry_t *dst;

    if ((dst = of_list_group_desc_stats_entry_new(src->version)) == NULL) {
        return NULL;
    }

    OF_LIST_GROUP_DESC_STATS_ENTRY_ITER(src, &src_elt, rv) {
        if ((dst_elt = of_group_desc_stats_entry_OF_VERSION_1_1_dup(&src_elt)) == NULL) {
            of_object_delete((of_object_t *)dst);
            return NULL;
        }
        _TRY_FREE(of_list_group_desc_stats_entry_append(dst, dst_elt),
            dst, NULL);
        of_object_delete((of_object_t *)dst_elt);
    }

    return dst;
}

/**
 * Duplicate a list of type of_list_group_stats_entry
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_list_group_stats_entry.
 *
 * The caller is responsible for deleting the returned value
 */
of_list_group_stats_entry_t *
of_list_group_stats_entry_OF_VERSION_1_1_dup(
    of_list_group_stats_entry_t *src)
{
    of_group_stats_entry_t src_elt;
    of_group_stats_entry_t *dst_elt;
    int rv;
    of_list_group_stats_entry_t *dst;

    if ((dst = of_list_group_stats_entry_new(src->version)) == NULL) {
        return NULL;
    }

    OF_LIST_GROUP_STATS_ENTRY_ITER(src, &src_elt, rv) {
        if ((dst_elt = of_group_stats_entry_OF_VERSION_1_1_dup(&src_elt)) == NULL) {
            of_object_delete((of_object_t *)dst);
            return NULL;
        }
        _TRY_FREE(of_list_group_stats_entry_append(dst, dst_elt),
            dst, NULL);
        of_object_delete((of_object_t *)dst_elt);
    }

    return dst;
}

/**
 * Duplicate a list of type of_list_instruction
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_list_instruction.
 *
 * The caller is responsible for deleting the returned value
 */
of_list_instruction_t *
of_list_instruction_OF_VERSION_1_1_dup(
    of_list_instruction_t *src)
{
    of_instruction_t src_elt;
    of_instruction_t *dst_elt;
    int rv;
    of_list_instruction_t *dst;

    if ((dst = of_list_instruction_new(src->version)) == NULL) {
        return NULL;
    }

    OF_LIST_INSTRUCTION_ITER(src, &src_elt, rv) {
        if ((dst_elt = of_instruction_OF_VERSION_1_1_dup(&src_elt)) == NULL) {
            of_object_delete((of_object_t *)dst);
            return NULL;
        }
        _TRY_FREE(of_list_instruction_append(dst, dst_elt),
            dst, NULL);
        of_object_delete((of_object_t *)dst_elt);
    }

    return dst;
}

/**
 * Duplicate a list of type of_list_packet_queue
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_list_packet_queue.
 *
 * The caller is responsible for deleting the returned value
 */
of_list_packet_queue_t *
of_list_packet_queue_OF_VERSION_1_1_dup(
    of_list_packet_queue_t *src)
{
    of_packet_queue_t src_elt;
    of_packet_queue_t *dst_elt;
    int rv;
    of_list_packet_queue_t *dst;

    if ((dst = of_list_packet_queue_new(src->version)) == NULL) {
        return NULL;
    }

    OF_LIST_PACKET_QUEUE_ITER(src, &src_elt, rv) {
        if ((dst_elt = of_packet_queue_OF_VERSION_1_1_dup(&src_elt)) == NULL) {
            of_object_delete((of_object_t *)dst);
            return NULL;
        }
        _TRY_FREE(of_list_packet_queue_append(dst, dst_elt),
            dst, NULL);
        of_object_delete((of_object_t *)dst_elt);
    }

    return dst;
}

/**
 * Duplicate a list of type of_list_port_desc
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_list_port_desc.
 *
 * The caller is responsible for deleting the returned value
 */
of_list_port_desc_t *
of_list_port_desc_OF_VERSION_1_1_dup(
    of_list_port_desc_t *src)
{
    of_port_desc_t src_elt;
    of_port_desc_t *dst_elt;
    int rv;
    of_list_port_desc_t *dst;

    if ((dst = of_list_port_desc_new(src->version)) == NULL) {
        return NULL;
    }

    OF_LIST_PORT_DESC_ITER(src, &src_elt, rv) {
        if ((dst_elt = of_port_desc_OF_VERSION_1_1_dup(&src_elt)) == NULL) {
            of_object_delete((of_object_t *)dst);
            return NULL;
        }
        _TRY_FREE(of_list_port_desc_append(dst, dst_elt),
            dst, NULL);
        of_object_delete((of_object_t *)dst_elt);
    }

    return dst;
}

/**
 * Duplicate a list of type of_list_port_stats_entry
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_list_port_stats_entry.
 *
 * The caller is responsible for deleting the returned value
 */
of_list_port_stats_entry_t *
of_list_port_stats_entry_OF_VERSION_1_1_dup(
    of_list_port_stats_entry_t *src)
{
    of_port_stats_entry_t src_elt;
    of_port_stats_entry_t *dst_elt;
    int rv;
    of_list_port_stats_entry_t *dst;

    if ((dst = of_list_port_stats_entry_new(src->version)) == NULL) {
        return NULL;
    }

    OF_LIST_PORT_STATS_ENTRY_ITER(src, &src_elt, rv) {
        if ((dst_elt = of_port_stats_entry_OF_VERSION_1_1_dup(&src_elt)) == NULL) {
            of_object_delete((of_object_t *)dst);
            return NULL;
        }
        _TRY_FREE(of_list_port_stats_entry_append(dst, dst_elt),
            dst, NULL);
        of_object_delete((of_object_t *)dst_elt);
    }

    return dst;
}

/**
 * Duplicate a list of type of_list_queue_prop
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_list_queue_prop.
 *
 * The caller is responsible for deleting the returned value
 */
of_list_queue_prop_t *
of_list_queue_prop_OF_VERSION_1_1_dup(
    of_list_queue_prop_t *src)
{
    of_queue_prop_t src_elt;
    of_queue_prop_t *dst_elt;
    int rv;
    of_list_queue_prop_t *dst;

    if ((dst = of_list_queue_prop_new(src->version)) == NULL) {
        return NULL;
    }

    OF_LIST_QUEUE_PROP_ITER(src, &src_elt, rv) {
        if ((dst_elt = of_queue_prop_OF_VERSION_1_1_dup(&src_elt)) == NULL) {
            of_object_delete((of_object_t *)dst);
            return NULL;
        }
        _TRY_FREE(of_list_queue_prop_append(dst, dst_elt),
            dst, NULL);
        of_object_delete((of_object_t *)dst_elt);
    }

    return dst;
}

/**
 * Duplicate a list of type of_list_queue_stats_entry
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_list_queue_stats_entry.
 *
 * The caller is responsible for deleting the returned value
 */
of_list_queue_stats_entry_t *
of_list_queue_stats_entry_OF_VERSION_1_1_dup(
    of_list_queue_stats_entry_t *src)
{
    of_queue_stats_entry_t src_elt;
    of_queue_stats_entry_t *dst_elt;
    int rv;
    of_list_queue_stats_entry_t *dst;

    if ((dst = of_list_queue_stats_entry_new(src->version)) == NULL) {
        return NULL;
    }

    OF_LIST_QUEUE_STATS_ENTRY_ITER(src, &src_elt, rv) {
        if ((dst_elt = of_queue_stats_entry_OF_VERSION_1_1_dup(&src_elt)) == NULL) {
            of_object_delete((of_object_t *)dst);
            return NULL;
        }
        _TRY_FREE(of_list_queue_stats_entry_append(dst, dst_elt),
            dst, NULL);
        of_object_delete((of_object_t *)dst_elt);
    }

    return dst;
}

/**
 * Duplicate a list of type of_list_table_stats_entry
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_list_table_stats_entry.
 *
 * The caller is responsible for deleting the returned value
 */
of_list_table_stats_entry_t *
of_list_table_stats_entry_OF_VERSION_1_1_dup(
    of_list_table_stats_entry_t *src)
{
    of_table_stats_entry_t src_elt;
    of_table_stats_entry_t *dst_elt;
    int rv;
    of_list_table_stats_entry_t *dst;

    if ((dst = of_list_table_stats_entry_new(src->version)) == NULL) {
        return NULL;
    }

    OF_LIST_TABLE_STATS_ENTRY_ITER(src, &src_elt, rv) {
        if ((dst_elt = of_table_stats_entry_OF_VERSION_1_1_dup(&src_elt)) == NULL) {
            of_object_delete((of_object_t *)dst);
            return NULL;
        }
        _TRY_FREE(of_list_table_stats_entry_append(dst, dst_elt),
            dst, NULL);
        of_object_delete((of_object_t *)dst_elt);
    }

    return dst;
}

/**
 * Duplicate an object of type of_aggregate_stats_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_aggregate_stats_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_aggregate_stats_reply_t *
of_aggregate_stats_reply_OF_VERSION_1_2_dup(
    of_aggregate_stats_reply_t *src)
{
    of_aggregate_stats_reply_t *dst;
    uint32_t val32;
    uint16_t val16;
    uint64_t val64;

    if ((dst = of_aggregate_stats_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_aggregate_stats_reply_xid_get(src, &val32);
    of_aggregate_stats_reply_xid_set(dst, val32);

    of_aggregate_stats_reply_flags_get(src, &val16);
    of_aggregate_stats_reply_flags_set(dst, val16);

    of_aggregate_stats_reply_packet_count_get(src, &val64);
    of_aggregate_stats_reply_packet_count_set(dst, val64);

    of_aggregate_stats_reply_byte_count_get(src, &val64);
    of_aggregate_stats_reply_byte_count_set(dst, val64);

    of_aggregate_stats_reply_flow_count_get(src, &val32);
    of_aggregate_stats_reply_flow_count_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_aggregate_stats_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_aggregate_stats_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_aggregate_stats_request_t *
of_aggregate_stats_request_OF_VERSION_1_2_dup(
    of_aggregate_stats_request_t *src)
{
    of_aggregate_stats_request_t *dst;
    uint32_t val32;
    uint16_t val16;
    uint8_t val8;
    of_port_no_t port_no;
    uint64_t val64;
    of_match_t match;

    if ((dst = of_aggregate_stats_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_aggregate_stats_request_xid_get(src, &val32);
    of_aggregate_stats_request_xid_set(dst, val32);

    of_aggregate_stats_request_flags_get(src, &val16);
    of_aggregate_stats_request_flags_set(dst, val16);

    of_aggregate_stats_request_table_id_get(src, &val8);
    of_aggregate_stats_request_table_id_set(dst, val8);

    of_aggregate_stats_request_out_port_get(src, &port_no);
    of_aggregate_stats_request_out_port_set(dst, port_no);

    of_aggregate_stats_request_out_group_get(src, &val32);
    of_aggregate_stats_request_out_group_set(dst, val32);

    of_aggregate_stats_request_cookie_get(src, &val64);
    of_aggregate_stats_request_cookie_set(dst, val64);

    of_aggregate_stats_request_cookie_mask_get(src, &val64);
    of_aggregate_stats_request_cookie_mask_set(dst, val64);

    of_aggregate_stats_request_match_get(src, &match);
    of_aggregate_stats_request_match_set(dst, &match);

    return dst;
}

/**
 * Duplicate an object of type of_bad_action_error_msg
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bad_action_error_msg.
 *
 * The caller is responsible for deleting the returned value
 */
of_bad_action_error_msg_t *
of_bad_action_error_msg_OF_VERSION_1_2_dup(
    of_bad_action_error_msg_t *src)
{
    of_bad_action_error_msg_t *dst;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    if ((dst = of_bad_action_error_msg_new(src->version)) == NULL) {
        return NULL;
    }

    of_bad_action_error_msg_xid_get(src, &val32);
    of_bad_action_error_msg_xid_set(dst, val32);

    of_bad_action_error_msg_code_get(src, &val16);
    of_bad_action_error_msg_code_set(dst, val16);

    of_bad_action_error_msg_data_get(src, &octets);
    of_bad_action_error_msg_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_bad_instruction_error_msg
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bad_instruction_error_msg.
 *
 * The caller is responsible for deleting the returned value
 */
of_bad_instruction_error_msg_t *
of_bad_instruction_error_msg_OF_VERSION_1_2_dup(
    of_bad_instruction_error_msg_t *src)
{
    of_bad_instruction_error_msg_t *dst;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    if ((dst = of_bad_instruction_error_msg_new(src->version)) == NULL) {
        return NULL;
    }

    of_bad_instruction_error_msg_xid_get(src, &val32);
    of_bad_instruction_error_msg_xid_set(dst, val32);

    of_bad_instruction_error_msg_code_get(src, &val16);
    of_bad_instruction_error_msg_code_set(dst, val16);

    of_bad_instruction_error_msg_data_get(src, &octets);
    of_bad_instruction_error_msg_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_bad_match_error_msg
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bad_match_error_msg.
 *
 * The caller is responsible for deleting the returned value
 */
of_bad_match_error_msg_t *
of_bad_match_error_msg_OF_VERSION_1_2_dup(
    of_bad_match_error_msg_t *src)
{
    of_bad_match_error_msg_t *dst;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    if ((dst = of_bad_match_error_msg_new(src->version)) == NULL) {
        return NULL;
    }

    of_bad_match_error_msg_xid_get(src, &val32);
    of_bad_match_error_msg_xid_set(dst, val32);

    of_bad_match_error_msg_code_get(src, &val16);
    of_bad_match_error_msg_code_set(dst, val16);

    of_bad_match_error_msg_data_get(src, &octets);
    of_bad_match_error_msg_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_bad_request_error_msg
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bad_request_error_msg.
 *
 * The caller is responsible for deleting the returned value
 */
of_bad_request_error_msg_t *
of_bad_request_error_msg_OF_VERSION_1_2_dup(
    of_bad_request_error_msg_t *src)
{
    of_bad_request_error_msg_t *dst;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    if ((dst = of_bad_request_error_msg_new(src->version)) == NULL) {
        return NULL;
    }

    of_bad_request_error_msg_xid_get(src, &val32);
    of_bad_request_error_msg_xid_set(dst, val32);

    of_bad_request_error_msg_code_get(src, &val16);
    of_bad_request_error_msg_code_set(dst, val16);

    of_bad_request_error_msg_data_get(src, &octets);
    of_bad_request_error_msg_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_barrier_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_barrier_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_barrier_reply_t *
of_barrier_reply_OF_VERSION_1_2_dup(
    of_barrier_reply_t *src)
{
    of_barrier_reply_t *dst;
    uint32_t val32;

    if ((dst = of_barrier_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_barrier_reply_xid_get(src, &val32);
    of_barrier_reply_xid_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_barrier_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_barrier_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_barrier_request_t *
of_barrier_request_OF_VERSION_1_2_dup(
    of_barrier_request_t *src)
{
    of_barrier_request_t *dst;
    uint32_t val32;

    if ((dst = of_barrier_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_barrier_request_xid_get(src, &val32);
    of_barrier_request_xid_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_bw_clear_data_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_bw_clear_data_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_bw_clear_data_reply_t *
of_bsn_bw_clear_data_reply_OF_VERSION_1_2_dup(
    of_bsn_bw_clear_data_reply_t *src)
{
    of_bsn_bw_clear_data_reply_t *dst;
    uint32_t val32;

    if ((dst = of_bsn_bw_clear_data_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_bw_clear_data_reply_xid_get(src, &val32);
    of_bsn_bw_clear_data_reply_xid_set(dst, val32);

    of_bsn_bw_clear_data_reply_experimenter_get(src, &val32);
    of_bsn_bw_clear_data_reply_experimenter_set(dst, val32);

    of_bsn_bw_clear_data_reply_subtype_get(src, &val32);
    of_bsn_bw_clear_data_reply_subtype_set(dst, val32);

    of_bsn_bw_clear_data_reply_status_get(src, &val32);
    of_bsn_bw_clear_data_reply_status_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_bw_clear_data_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_bw_clear_data_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_bw_clear_data_request_t *
of_bsn_bw_clear_data_request_OF_VERSION_1_2_dup(
    of_bsn_bw_clear_data_request_t *src)
{
    of_bsn_bw_clear_data_request_t *dst;
    uint32_t val32;

    if ((dst = of_bsn_bw_clear_data_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_bw_clear_data_request_xid_get(src, &val32);
    of_bsn_bw_clear_data_request_xid_set(dst, val32);

    of_bsn_bw_clear_data_request_experimenter_get(src, &val32);
    of_bsn_bw_clear_data_request_experimenter_set(dst, val32);

    of_bsn_bw_clear_data_request_subtype_get(src, &val32);
    of_bsn_bw_clear_data_request_subtype_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_bw_enable_get_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_bw_enable_get_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_bw_enable_get_reply_t *
of_bsn_bw_enable_get_reply_OF_VERSION_1_2_dup(
    of_bsn_bw_enable_get_reply_t *src)
{
    of_bsn_bw_enable_get_reply_t *dst;
    uint32_t val32;

    if ((dst = of_bsn_bw_enable_get_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_bw_enable_get_reply_xid_get(src, &val32);
    of_bsn_bw_enable_get_reply_xid_set(dst, val32);

    of_bsn_bw_enable_get_reply_experimenter_get(src, &val32);
    of_bsn_bw_enable_get_reply_experimenter_set(dst, val32);

    of_bsn_bw_enable_get_reply_subtype_get(src, &val32);
    of_bsn_bw_enable_get_reply_subtype_set(dst, val32);

    of_bsn_bw_enable_get_reply_enabled_get(src, &val32);
    of_bsn_bw_enable_get_reply_enabled_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_bw_enable_get_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_bw_enable_get_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_bw_enable_get_request_t *
of_bsn_bw_enable_get_request_OF_VERSION_1_2_dup(
    of_bsn_bw_enable_get_request_t *src)
{
    of_bsn_bw_enable_get_request_t *dst;
    uint32_t val32;

    if ((dst = of_bsn_bw_enable_get_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_bw_enable_get_request_xid_get(src, &val32);
    of_bsn_bw_enable_get_request_xid_set(dst, val32);

    of_bsn_bw_enable_get_request_experimenter_get(src, &val32);
    of_bsn_bw_enable_get_request_experimenter_set(dst, val32);

    of_bsn_bw_enable_get_request_subtype_get(src, &val32);
    of_bsn_bw_enable_get_request_subtype_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_bw_enable_set_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_bw_enable_set_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_bw_enable_set_reply_t *
of_bsn_bw_enable_set_reply_OF_VERSION_1_2_dup(
    of_bsn_bw_enable_set_reply_t *src)
{
    of_bsn_bw_enable_set_reply_t *dst;
    uint32_t val32;

    if ((dst = of_bsn_bw_enable_set_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_bw_enable_set_reply_xid_get(src, &val32);
    of_bsn_bw_enable_set_reply_xid_set(dst, val32);

    of_bsn_bw_enable_set_reply_experimenter_get(src, &val32);
    of_bsn_bw_enable_set_reply_experimenter_set(dst, val32);

    of_bsn_bw_enable_set_reply_subtype_get(src, &val32);
    of_bsn_bw_enable_set_reply_subtype_set(dst, val32);

    of_bsn_bw_enable_set_reply_enable_get(src, &val32);
    of_bsn_bw_enable_set_reply_enable_set(dst, val32);

    of_bsn_bw_enable_set_reply_status_get(src, &val32);
    of_bsn_bw_enable_set_reply_status_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_bw_enable_set_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_bw_enable_set_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_bw_enable_set_request_t *
of_bsn_bw_enable_set_request_OF_VERSION_1_2_dup(
    of_bsn_bw_enable_set_request_t *src)
{
    of_bsn_bw_enable_set_request_t *dst;
    uint32_t val32;

    if ((dst = of_bsn_bw_enable_set_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_bw_enable_set_request_xid_get(src, &val32);
    of_bsn_bw_enable_set_request_xid_set(dst, val32);

    of_bsn_bw_enable_set_request_experimenter_get(src, &val32);
    of_bsn_bw_enable_set_request_experimenter_set(dst, val32);

    of_bsn_bw_enable_set_request_subtype_get(src, &val32);
    of_bsn_bw_enable_set_request_subtype_set(dst, val32);

    of_bsn_bw_enable_set_request_enable_get(src, &val32);
    of_bsn_bw_enable_set_request_enable_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_get_interfaces_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_get_interfaces_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_get_interfaces_reply_t *
of_bsn_get_interfaces_reply_OF_VERSION_1_2_dup(
    of_bsn_get_interfaces_reply_t *src)
{
    of_bsn_get_interfaces_reply_t *dst;
    uint32_t val32;

    of_list_bsn_interface_t src_list;
    of_list_bsn_interface_t *dst_list;

    if ((dst = of_bsn_get_interfaces_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_get_interfaces_reply_xid_get(src, &val32);
    of_bsn_get_interfaces_reply_xid_set(dst, val32);

    of_bsn_get_interfaces_reply_experimenter_get(src, &val32);
    of_bsn_get_interfaces_reply_experimenter_set(dst, val32);

    of_bsn_get_interfaces_reply_subtype_get(src, &val32);
    of_bsn_get_interfaces_reply_subtype_set(dst, val32);

    of_bsn_get_interfaces_reply_interfaces_bind(
        src, &src_list);
    dst_list = of_list_bsn_interface_OF_VERSION_1_2_dup(&src_list);
    if (dst_list == NULL) {
        of_bsn_get_interfaces_reply_delete(dst);
        return NULL;
    }
    of_bsn_get_interfaces_reply_interfaces_set(dst, dst_list);
    of_list_bsn_interface_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_get_interfaces_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_get_interfaces_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_get_interfaces_request_t *
of_bsn_get_interfaces_request_OF_VERSION_1_2_dup(
    of_bsn_get_interfaces_request_t *src)
{
    of_bsn_get_interfaces_request_t *dst;
    uint32_t val32;

    if ((dst = of_bsn_get_interfaces_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_get_interfaces_request_xid_get(src, &val32);
    of_bsn_get_interfaces_request_xid_set(dst, val32);

    of_bsn_get_interfaces_request_experimenter_get(src, &val32);
    of_bsn_get_interfaces_request_experimenter_set(dst, val32);

    of_bsn_get_interfaces_request_subtype_get(src, &val32);
    of_bsn_get_interfaces_request_subtype_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_get_mirroring_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_get_mirroring_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_get_mirroring_reply_t *
of_bsn_get_mirroring_reply_OF_VERSION_1_2_dup(
    of_bsn_get_mirroring_reply_t *src)
{
    of_bsn_get_mirroring_reply_t *dst;
    uint32_t val32;
    uint8_t val8;

    if ((dst = of_bsn_get_mirroring_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_get_mirroring_reply_xid_get(src, &val32);
    of_bsn_get_mirroring_reply_xid_set(dst, val32);

    of_bsn_get_mirroring_reply_experimenter_get(src, &val32);
    of_bsn_get_mirroring_reply_experimenter_set(dst, val32);

    of_bsn_get_mirroring_reply_subtype_get(src, &val32);
    of_bsn_get_mirroring_reply_subtype_set(dst, val32);

    of_bsn_get_mirroring_reply_report_mirror_ports_get(src, &val8);
    of_bsn_get_mirroring_reply_report_mirror_ports_set(dst, val8);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_get_mirroring_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_get_mirroring_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_get_mirroring_request_t *
of_bsn_get_mirroring_request_OF_VERSION_1_2_dup(
    of_bsn_get_mirroring_request_t *src)
{
    of_bsn_get_mirroring_request_t *dst;
    uint32_t val32;
    uint8_t val8;

    if ((dst = of_bsn_get_mirroring_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_get_mirroring_request_xid_get(src, &val32);
    of_bsn_get_mirroring_request_xid_set(dst, val32);

    of_bsn_get_mirroring_request_experimenter_get(src, &val32);
    of_bsn_get_mirroring_request_experimenter_set(dst, val32);

    of_bsn_get_mirroring_request_subtype_get(src, &val32);
    of_bsn_get_mirroring_request_subtype_set(dst, val32);

    of_bsn_get_mirroring_request_report_mirror_ports_get(src, &val8);
    of_bsn_get_mirroring_request_report_mirror_ports_set(dst, val8);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_header
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_header.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_header_t *
of_bsn_header_OF_VERSION_1_2_dup(
    of_bsn_header_t *src)
{
    of_bsn_header_t *dst;
    uint32_t val32;

    if ((dst = of_bsn_header_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_header_xid_get(src, &val32);
    of_bsn_header_xid_set(dst, val32);

    of_bsn_header_experimenter_get(src, &val32);
    of_bsn_header_experimenter_set(dst, val32);

    of_bsn_header_subtype_get(src, &val32);
    of_bsn_header_subtype_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_pdu_rx_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_pdu_rx_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_pdu_rx_reply_t *
of_bsn_pdu_rx_reply_OF_VERSION_1_2_dup(
    of_bsn_pdu_rx_reply_t *src)
{
    of_bsn_pdu_rx_reply_t *dst;
    uint32_t val32;

    if ((dst = of_bsn_pdu_rx_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_pdu_rx_reply_xid_get(src, &val32);
    of_bsn_pdu_rx_reply_xid_set(dst, val32);

    of_bsn_pdu_rx_reply_experimenter_get(src, &val32);
    of_bsn_pdu_rx_reply_experimenter_set(dst, val32);

    of_bsn_pdu_rx_reply_subtype_get(src, &val32);
    of_bsn_pdu_rx_reply_subtype_set(dst, val32);

    of_bsn_pdu_rx_reply_status_get(src, &val32);
    of_bsn_pdu_rx_reply_status_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_pdu_rx_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_pdu_rx_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_pdu_rx_request_t *
of_bsn_pdu_rx_request_OF_VERSION_1_2_dup(
    of_bsn_pdu_rx_request_t *src)
{
    of_bsn_pdu_rx_request_t *dst;
    uint32_t val32;
    of_port_no_t port_no;
    uint8_t val8;
    of_octets_t octets;

    if ((dst = of_bsn_pdu_rx_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_pdu_rx_request_xid_get(src, &val32);
    of_bsn_pdu_rx_request_xid_set(dst, val32);

    of_bsn_pdu_rx_request_experimenter_get(src, &val32);
    of_bsn_pdu_rx_request_experimenter_set(dst, val32);

    of_bsn_pdu_rx_request_subtype_get(src, &val32);
    of_bsn_pdu_rx_request_subtype_set(dst, val32);

    of_bsn_pdu_rx_request_timeout_ms_get(src, &val32);
    of_bsn_pdu_rx_request_timeout_ms_set(dst, val32);

    of_bsn_pdu_rx_request_port_no_get(src, &port_no);
    of_bsn_pdu_rx_request_port_no_set(dst, port_no);

    of_bsn_pdu_rx_request_slot_num_get(src, &val8);
    of_bsn_pdu_rx_request_slot_num_set(dst, val8);

    of_bsn_pdu_rx_request_data_get(src, &octets);
    of_bsn_pdu_rx_request_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_pdu_rx_timeout
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_pdu_rx_timeout.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_pdu_rx_timeout_t *
of_bsn_pdu_rx_timeout_OF_VERSION_1_2_dup(
    of_bsn_pdu_rx_timeout_t *src)
{
    of_bsn_pdu_rx_timeout_t *dst;
    uint32_t val32;
    of_port_no_t port_no;
    uint8_t val8;

    if ((dst = of_bsn_pdu_rx_timeout_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_pdu_rx_timeout_xid_get(src, &val32);
    of_bsn_pdu_rx_timeout_xid_set(dst, val32);

    of_bsn_pdu_rx_timeout_experimenter_get(src, &val32);
    of_bsn_pdu_rx_timeout_experimenter_set(dst, val32);

    of_bsn_pdu_rx_timeout_subtype_get(src, &val32);
    of_bsn_pdu_rx_timeout_subtype_set(dst, val32);

    of_bsn_pdu_rx_timeout_port_no_get(src, &port_no);
    of_bsn_pdu_rx_timeout_port_no_set(dst, port_no);

    of_bsn_pdu_rx_timeout_slot_num_get(src, &val8);
    of_bsn_pdu_rx_timeout_slot_num_set(dst, val8);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_pdu_tx_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_pdu_tx_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_pdu_tx_reply_t *
of_bsn_pdu_tx_reply_OF_VERSION_1_2_dup(
    of_bsn_pdu_tx_reply_t *src)
{
    of_bsn_pdu_tx_reply_t *dst;
    uint32_t val32;

    if ((dst = of_bsn_pdu_tx_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_pdu_tx_reply_xid_get(src, &val32);
    of_bsn_pdu_tx_reply_xid_set(dst, val32);

    of_bsn_pdu_tx_reply_experimenter_get(src, &val32);
    of_bsn_pdu_tx_reply_experimenter_set(dst, val32);

    of_bsn_pdu_tx_reply_subtype_get(src, &val32);
    of_bsn_pdu_tx_reply_subtype_set(dst, val32);

    of_bsn_pdu_tx_reply_status_get(src, &val32);
    of_bsn_pdu_tx_reply_status_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_pdu_tx_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_pdu_tx_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_pdu_tx_request_t *
of_bsn_pdu_tx_request_OF_VERSION_1_2_dup(
    of_bsn_pdu_tx_request_t *src)
{
    of_bsn_pdu_tx_request_t *dst;
    uint32_t val32;
    of_port_no_t port_no;
    uint8_t val8;
    of_octets_t octets;

    if ((dst = of_bsn_pdu_tx_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_pdu_tx_request_xid_get(src, &val32);
    of_bsn_pdu_tx_request_xid_set(dst, val32);

    of_bsn_pdu_tx_request_experimenter_get(src, &val32);
    of_bsn_pdu_tx_request_experimenter_set(dst, val32);

    of_bsn_pdu_tx_request_subtype_get(src, &val32);
    of_bsn_pdu_tx_request_subtype_set(dst, val32);

    of_bsn_pdu_tx_request_tx_interval_ms_get(src, &val32);
    of_bsn_pdu_tx_request_tx_interval_ms_set(dst, val32);

    of_bsn_pdu_tx_request_port_no_get(src, &port_no);
    of_bsn_pdu_tx_request_port_no_set(dst, port_no);

    of_bsn_pdu_tx_request_slot_num_get(src, &val8);
    of_bsn_pdu_tx_request_slot_num_set(dst, val8);

    of_bsn_pdu_tx_request_data_get(src, &octets);
    of_bsn_pdu_tx_request_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_set_mirroring
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_set_mirroring.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_set_mirroring_t *
of_bsn_set_mirroring_OF_VERSION_1_2_dup(
    of_bsn_set_mirroring_t *src)
{
    of_bsn_set_mirroring_t *dst;
    uint32_t val32;
    uint8_t val8;

    if ((dst = of_bsn_set_mirroring_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_set_mirroring_xid_get(src, &val32);
    of_bsn_set_mirroring_xid_set(dst, val32);

    of_bsn_set_mirroring_experimenter_get(src, &val32);
    of_bsn_set_mirroring_experimenter_set(dst, val32);

    of_bsn_set_mirroring_subtype_get(src, &val32);
    of_bsn_set_mirroring_subtype_set(dst, val32);

    of_bsn_set_mirroring_report_mirror_ports_get(src, &val8);
    of_bsn_set_mirroring_report_mirror_ports_set(dst, val8);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_set_pktin_suppression_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_set_pktin_suppression_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_set_pktin_suppression_reply_t *
of_bsn_set_pktin_suppression_reply_OF_VERSION_1_2_dup(
    of_bsn_set_pktin_suppression_reply_t *src)
{
    of_bsn_set_pktin_suppression_reply_t *dst;
    uint32_t val32;

    if ((dst = of_bsn_set_pktin_suppression_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_set_pktin_suppression_reply_xid_get(src, &val32);
    of_bsn_set_pktin_suppression_reply_xid_set(dst, val32);

    of_bsn_set_pktin_suppression_reply_experimenter_get(src, &val32);
    of_bsn_set_pktin_suppression_reply_experimenter_set(dst, val32);

    of_bsn_set_pktin_suppression_reply_subtype_get(src, &val32);
    of_bsn_set_pktin_suppression_reply_subtype_set(dst, val32);

    of_bsn_set_pktin_suppression_reply_status_get(src, &val32);
    of_bsn_set_pktin_suppression_reply_status_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_set_pktin_suppression_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_set_pktin_suppression_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_set_pktin_suppression_request_t *
of_bsn_set_pktin_suppression_request_OF_VERSION_1_2_dup(
    of_bsn_set_pktin_suppression_request_t *src)
{
    of_bsn_set_pktin_suppression_request_t *dst;
    uint32_t val32;
    uint8_t val8;
    uint16_t val16;
    uint64_t val64;

    if ((dst = of_bsn_set_pktin_suppression_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_set_pktin_suppression_request_xid_get(src, &val32);
    of_bsn_set_pktin_suppression_request_xid_set(dst, val32);

    of_bsn_set_pktin_suppression_request_experimenter_get(src, &val32);
    of_bsn_set_pktin_suppression_request_experimenter_set(dst, val32);

    of_bsn_set_pktin_suppression_request_subtype_get(src, &val32);
    of_bsn_set_pktin_suppression_request_subtype_set(dst, val32);

    of_bsn_set_pktin_suppression_request_enabled_get(src, &val8);
    of_bsn_set_pktin_suppression_request_enabled_set(dst, val8);

    of_bsn_set_pktin_suppression_request_idle_timeout_get(src, &val16);
    of_bsn_set_pktin_suppression_request_idle_timeout_set(dst, val16);

    of_bsn_set_pktin_suppression_request_hard_timeout_get(src, &val16);
    of_bsn_set_pktin_suppression_request_hard_timeout_set(dst, val16);

    of_bsn_set_pktin_suppression_request_priority_get(src, &val16);
    of_bsn_set_pktin_suppression_request_priority_set(dst, val16);

    of_bsn_set_pktin_suppression_request_cookie_get(src, &val64);
    of_bsn_set_pktin_suppression_request_cookie_set(dst, val64);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_virtual_port_create_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_virtual_port_create_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_virtual_port_create_reply_t *
of_bsn_virtual_port_create_reply_OF_VERSION_1_2_dup(
    of_bsn_virtual_port_create_reply_t *src)
{
    of_bsn_virtual_port_create_reply_t *dst;
    uint32_t val32;

    if ((dst = of_bsn_virtual_port_create_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_virtual_port_create_reply_xid_get(src, &val32);
    of_bsn_virtual_port_create_reply_xid_set(dst, val32);

    of_bsn_virtual_port_create_reply_experimenter_get(src, &val32);
    of_bsn_virtual_port_create_reply_experimenter_set(dst, val32);

    of_bsn_virtual_port_create_reply_subtype_get(src, &val32);
    of_bsn_virtual_port_create_reply_subtype_set(dst, val32);

    of_bsn_virtual_port_create_reply_status_get(src, &val32);
    of_bsn_virtual_port_create_reply_status_set(dst, val32);

    of_bsn_virtual_port_create_reply_vport_no_get(src, &val32);
    of_bsn_virtual_port_create_reply_vport_no_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_virtual_port_create_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_virtual_port_create_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_virtual_port_create_request_t *
of_bsn_virtual_port_create_request_OF_VERSION_1_2_dup(
    of_bsn_virtual_port_create_request_t *src)
{
    of_bsn_virtual_port_create_request_t *dst;
    uint32_t val32;

    of_bsn_vport_q_in_q_t src_vport;
    of_bsn_vport_q_in_q_t *dst_vport;

    if ((dst = of_bsn_virtual_port_create_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_virtual_port_create_request_xid_get(src, &val32);
    of_bsn_virtual_port_create_request_xid_set(dst, val32);

    of_bsn_virtual_port_create_request_experimenter_get(src, &val32);
    of_bsn_virtual_port_create_request_experimenter_set(dst, val32);

    of_bsn_virtual_port_create_request_subtype_get(src, &val32);
    of_bsn_virtual_port_create_request_subtype_set(dst, val32);

    of_bsn_virtual_port_create_request_vport_bind(
        src, &src_vport);
    dst_vport = of_bsn_vport_q_in_q_OF_VERSION_1_2_dup(&src_vport);
    if (dst_vport == NULL) {
        of_bsn_virtual_port_create_request_delete(dst);
        return NULL;
    }
    of_bsn_virtual_port_create_request_vport_set(dst, dst_vport);
    of_bsn_vport_q_in_q_delete(dst_vport);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_virtual_port_remove_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_virtual_port_remove_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_virtual_port_remove_reply_t *
of_bsn_virtual_port_remove_reply_OF_VERSION_1_2_dup(
    of_bsn_virtual_port_remove_reply_t *src)
{
    of_bsn_virtual_port_remove_reply_t *dst;
    uint32_t val32;

    if ((dst = of_bsn_virtual_port_remove_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_virtual_port_remove_reply_xid_get(src, &val32);
    of_bsn_virtual_port_remove_reply_xid_set(dst, val32);

    of_bsn_virtual_port_remove_reply_experimenter_get(src, &val32);
    of_bsn_virtual_port_remove_reply_experimenter_set(dst, val32);

    of_bsn_virtual_port_remove_reply_subtype_get(src, &val32);
    of_bsn_virtual_port_remove_reply_subtype_set(dst, val32);

    of_bsn_virtual_port_remove_reply_status_get(src, &val32);
    of_bsn_virtual_port_remove_reply_status_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_virtual_port_remove_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_virtual_port_remove_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_virtual_port_remove_request_t *
of_bsn_virtual_port_remove_request_OF_VERSION_1_2_dup(
    of_bsn_virtual_port_remove_request_t *src)
{
    of_bsn_virtual_port_remove_request_t *dst;
    uint32_t val32;

    if ((dst = of_bsn_virtual_port_remove_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_virtual_port_remove_request_xid_get(src, &val32);
    of_bsn_virtual_port_remove_request_xid_set(dst, val32);

    of_bsn_virtual_port_remove_request_experimenter_get(src, &val32);
    of_bsn_virtual_port_remove_request_experimenter_set(dst, val32);

    of_bsn_virtual_port_remove_request_subtype_get(src, &val32);
    of_bsn_virtual_port_remove_request_subtype_set(dst, val32);

    of_bsn_virtual_port_remove_request_vport_no_get(src, &val32);
    of_bsn_virtual_port_remove_request_vport_no_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_desc_stats_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_desc_stats_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_desc_stats_reply_t *
of_desc_stats_reply_OF_VERSION_1_2_dup(
    of_desc_stats_reply_t *src)
{
    of_desc_stats_reply_t *dst;
    uint32_t val32;
    uint16_t val16;
    of_desc_str_t desc_str;
    of_serial_num_t ser_num;

    if ((dst = of_desc_stats_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_desc_stats_reply_xid_get(src, &val32);
    of_desc_stats_reply_xid_set(dst, val32);

    of_desc_stats_reply_flags_get(src, &val16);
    of_desc_stats_reply_flags_set(dst, val16);

    of_desc_stats_reply_mfr_desc_get(src, &desc_str);
    of_desc_stats_reply_mfr_desc_set(dst, desc_str);

    of_desc_stats_reply_hw_desc_get(src, &desc_str);
    of_desc_stats_reply_hw_desc_set(dst, desc_str);

    of_desc_stats_reply_sw_desc_get(src, &desc_str);
    of_desc_stats_reply_sw_desc_set(dst, desc_str);

    of_desc_stats_reply_serial_num_get(src, &ser_num);
    of_desc_stats_reply_serial_num_set(dst, ser_num);

    of_desc_stats_reply_dp_desc_get(src, &desc_str);
    of_desc_stats_reply_dp_desc_set(dst, desc_str);

    return dst;
}

/**
 * Duplicate an object of type of_desc_stats_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_desc_stats_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_desc_stats_request_t *
of_desc_stats_request_OF_VERSION_1_2_dup(
    of_desc_stats_request_t *src)
{
    of_desc_stats_request_t *dst;
    uint32_t val32;
    uint16_t val16;

    if ((dst = of_desc_stats_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_desc_stats_request_xid_get(src, &val32);
    of_desc_stats_request_xid_set(dst, val32);

    of_desc_stats_request_flags_get(src, &val16);
    of_desc_stats_request_flags_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_echo_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_echo_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_echo_reply_t *
of_echo_reply_OF_VERSION_1_2_dup(
    of_echo_reply_t *src)
{
    of_echo_reply_t *dst;
    uint32_t val32;
    of_octets_t octets;

    if ((dst = of_echo_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_echo_reply_xid_get(src, &val32);
    of_echo_reply_xid_set(dst, val32);

    of_echo_reply_data_get(src, &octets);
    of_echo_reply_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_echo_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_echo_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_echo_request_t *
of_echo_request_OF_VERSION_1_2_dup(
    of_echo_request_t *src)
{
    of_echo_request_t *dst;
    uint32_t val32;
    of_octets_t octets;

    if ((dst = of_echo_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_echo_request_xid_get(src, &val32);
    of_echo_request_xid_set(dst, val32);

    of_echo_request_data_get(src, &octets);
    of_echo_request_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_error_msg
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_error_msg.
 *
 * The caller is responsible for deleting the returned value
 */
of_error_msg_t *
of_error_msg_OF_VERSION_1_2_dup(
    of_error_msg_t *src)
{
    of_error_msg_t *dst;
    uint32_t val32;

    if ((dst = of_error_msg_new(src->version)) == NULL) {
        return NULL;
    }

    of_error_msg_xid_get(src, &val32);
    of_error_msg_xid_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_experimenter
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_experimenter.
 *
 * The caller is responsible for deleting the returned value
 */
of_experimenter_t *
of_experimenter_OF_VERSION_1_2_dup(
    of_experimenter_t *src)
{
    of_experimenter_t *dst;
    uint32_t val32;
    of_octets_t octets;

    if ((dst = of_experimenter_new(src->version)) == NULL) {
        return NULL;
    }

    of_experimenter_xid_get(src, &val32);
    of_experimenter_xid_set(dst, val32);

    of_experimenter_experimenter_get(src, &val32);
    of_experimenter_experimenter_set(dst, val32);

    of_experimenter_subtype_get(src, &val32);
    of_experimenter_subtype_set(dst, val32);

    of_experimenter_data_get(src, &octets);
    of_experimenter_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_experimenter_error_msg
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_experimenter_error_msg.
 *
 * The caller is responsible for deleting the returned value
 */
of_experimenter_error_msg_t *
of_experimenter_error_msg_OF_VERSION_1_2_dup(
    of_experimenter_error_msg_t *src)
{
    of_experimenter_error_msg_t *dst;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    if ((dst = of_experimenter_error_msg_new(src->version)) == NULL) {
        return NULL;
    }

    of_experimenter_error_msg_xid_get(src, &val32);
    of_experimenter_error_msg_xid_set(dst, val32);

    of_experimenter_error_msg_subtype_get(src, &val16);
    of_experimenter_error_msg_subtype_set(dst, val16);

    of_experimenter_error_msg_experimenter_get(src, &val32);
    of_experimenter_error_msg_experimenter_set(dst, val32);

    of_experimenter_error_msg_data_get(src, &octets);
    of_experimenter_error_msg_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_experimenter_stats_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_experimenter_stats_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_experimenter_stats_reply_t *
of_experimenter_stats_reply_OF_VERSION_1_2_dup(
    of_experimenter_stats_reply_t *src)
{
    of_experimenter_stats_reply_t *dst;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    if ((dst = of_experimenter_stats_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_experimenter_stats_reply_xid_get(src, &val32);
    of_experimenter_stats_reply_xid_set(dst, val32);

    of_experimenter_stats_reply_flags_get(src, &val16);
    of_experimenter_stats_reply_flags_set(dst, val16);

    of_experimenter_stats_reply_experimenter_get(src, &val32);
    of_experimenter_stats_reply_experimenter_set(dst, val32);

    of_experimenter_stats_reply_subtype_get(src, &val32);
    of_experimenter_stats_reply_subtype_set(dst, val32);

    of_experimenter_stats_reply_data_get(src, &octets);
    of_experimenter_stats_reply_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_experimenter_stats_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_experimenter_stats_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_experimenter_stats_request_t *
of_experimenter_stats_request_OF_VERSION_1_2_dup(
    of_experimenter_stats_request_t *src)
{
    of_experimenter_stats_request_t *dst;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    if ((dst = of_experimenter_stats_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_experimenter_stats_request_xid_get(src, &val32);
    of_experimenter_stats_request_xid_set(dst, val32);

    of_experimenter_stats_request_flags_get(src, &val16);
    of_experimenter_stats_request_flags_set(dst, val16);

    of_experimenter_stats_request_experimenter_get(src, &val32);
    of_experimenter_stats_request_experimenter_set(dst, val32);

    of_experimenter_stats_request_subtype_get(src, &val32);
    of_experimenter_stats_request_subtype_set(dst, val32);

    of_experimenter_stats_request_data_get(src, &octets);
    of_experimenter_stats_request_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_features_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_features_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_features_reply_t *
of_features_reply_OF_VERSION_1_2_dup(
    of_features_reply_t *src)
{
    of_features_reply_t *dst;
    uint32_t val32;
    uint64_t val64;
    uint8_t val8;

    of_list_port_desc_t src_list;
    of_list_port_desc_t *dst_list;

    if ((dst = of_features_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_features_reply_xid_get(src, &val32);
    of_features_reply_xid_set(dst, val32);

    of_features_reply_datapath_id_get(src, &val64);
    of_features_reply_datapath_id_set(dst, val64);

    of_features_reply_n_buffers_get(src, &val32);
    of_features_reply_n_buffers_set(dst, val32);

    of_features_reply_n_tables_get(src, &val8);
    of_features_reply_n_tables_set(dst, val8);

    of_features_reply_capabilities_get(src, &val32);
    of_features_reply_capabilities_set(dst, val32);

    of_features_reply_reserved_get(src, &val32);
    of_features_reply_reserved_set(dst, val32);

    of_features_reply_ports_bind(
        src, &src_list);
    dst_list = of_list_port_desc_OF_VERSION_1_2_dup(&src_list);
    if (dst_list == NULL) {
        of_features_reply_delete(dst);
        return NULL;
    }
    of_features_reply_ports_set(dst, dst_list);
    of_list_port_desc_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_features_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_features_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_features_request_t *
of_features_request_OF_VERSION_1_2_dup(
    of_features_request_t *src)
{
    of_features_request_t *dst;
    uint32_t val32;

    if ((dst = of_features_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_features_request_xid_get(src, &val32);
    of_features_request_xid_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_flow_add
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_flow_add.
 *
 * The caller is responsible for deleting the returned value
 */
of_flow_add_t *
of_flow_add_OF_VERSION_1_2_dup(
    of_flow_add_t *src)
{
    of_flow_add_t *dst;
    uint32_t val32;
    uint64_t val64;
    uint8_t val8;
    uint16_t val16;
    of_port_no_t port_no;
    of_match_t match;

    of_list_instruction_t src_list;
    of_list_instruction_t *dst_list;

    if ((dst = of_flow_add_new(src->version)) == NULL) {
        return NULL;
    }

    of_flow_add_xid_get(src, &val32);
    of_flow_add_xid_set(dst, val32);

    of_flow_add_cookie_get(src, &val64);
    of_flow_add_cookie_set(dst, val64);

    of_flow_add_cookie_mask_get(src, &val64);
    of_flow_add_cookie_mask_set(dst, val64);

    of_flow_add_table_id_get(src, &val8);
    of_flow_add_table_id_set(dst, val8);

    of_flow_add_idle_timeout_get(src, &val16);
    of_flow_add_idle_timeout_set(dst, val16);

    of_flow_add_hard_timeout_get(src, &val16);
    of_flow_add_hard_timeout_set(dst, val16);

    of_flow_add_priority_get(src, &val16);
    of_flow_add_priority_set(dst, val16);

    of_flow_add_buffer_id_get(src, &val32);
    of_flow_add_buffer_id_set(dst, val32);

    of_flow_add_out_port_get(src, &port_no);
    of_flow_add_out_port_set(dst, port_no);

    of_flow_add_out_group_get(src, &val32);
    of_flow_add_out_group_set(dst, val32);

    of_flow_add_flags_get(src, &val16);
    of_flow_add_flags_set(dst, val16);

    of_flow_add_match_get(src, &match);
    of_flow_add_match_set(dst, &match);

    of_flow_add_instructions_bind(
        src, &src_list);
    dst_list = of_list_instruction_OF_VERSION_1_2_dup(&src_list);
    if (dst_list == NULL) {
        of_flow_add_delete(dst);
        return NULL;
    }
    of_flow_add_instructions_set(dst, dst_list);
    of_list_instruction_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_flow_delete
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_flow_delete.
 *
 * The caller is responsible for deleting the returned value
 */
of_flow_delete_t *
of_flow_delete_OF_VERSION_1_2_dup(
    of_flow_delete_t *src)
{
    of_flow_delete_t *dst;
    uint32_t val32;
    uint64_t val64;
    uint8_t val8;
    uint16_t val16;
    of_port_no_t port_no;
    of_match_t match;

    of_list_instruction_t src_list;
    of_list_instruction_t *dst_list;

    if ((dst = of_flow_delete_new(src->version)) == NULL) {
        return NULL;
    }

    of_flow_delete_xid_get(src, &val32);
    of_flow_delete_xid_set(dst, val32);

    of_flow_delete_cookie_get(src, &val64);
    of_flow_delete_cookie_set(dst, val64);

    of_flow_delete_cookie_mask_get(src, &val64);
    of_flow_delete_cookie_mask_set(dst, val64);

    of_flow_delete_table_id_get(src, &val8);
    of_flow_delete_table_id_set(dst, val8);

    of_flow_delete_idle_timeout_get(src, &val16);
    of_flow_delete_idle_timeout_set(dst, val16);

    of_flow_delete_hard_timeout_get(src, &val16);
    of_flow_delete_hard_timeout_set(dst, val16);

    of_flow_delete_priority_get(src, &val16);
    of_flow_delete_priority_set(dst, val16);

    of_flow_delete_buffer_id_get(src, &val32);
    of_flow_delete_buffer_id_set(dst, val32);

    of_flow_delete_out_port_get(src, &port_no);
    of_flow_delete_out_port_set(dst, port_no);

    of_flow_delete_out_group_get(src, &val32);
    of_flow_delete_out_group_set(dst, val32);

    of_flow_delete_flags_get(src, &val16);
    of_flow_delete_flags_set(dst, val16);

    of_flow_delete_match_get(src, &match);
    of_flow_delete_match_set(dst, &match);

    of_flow_delete_instructions_bind(
        src, &src_list);
    dst_list = of_list_instruction_OF_VERSION_1_2_dup(&src_list);
    if (dst_list == NULL) {
        of_flow_delete_delete(dst);
        return NULL;
    }
    of_flow_delete_instructions_set(dst, dst_list);
    of_list_instruction_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_flow_delete_strict
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_flow_delete_strict.
 *
 * The caller is responsible for deleting the returned value
 */
of_flow_delete_strict_t *
of_flow_delete_strict_OF_VERSION_1_2_dup(
    of_flow_delete_strict_t *src)
{
    of_flow_delete_strict_t *dst;
    uint32_t val32;
    uint64_t val64;
    uint8_t val8;
    uint16_t val16;
    of_port_no_t port_no;
    of_match_t match;

    of_list_instruction_t src_list;
    of_list_instruction_t *dst_list;

    if ((dst = of_flow_delete_strict_new(src->version)) == NULL) {
        return NULL;
    }

    of_flow_delete_strict_xid_get(src, &val32);
    of_flow_delete_strict_xid_set(dst, val32);

    of_flow_delete_strict_cookie_get(src, &val64);
    of_flow_delete_strict_cookie_set(dst, val64);

    of_flow_delete_strict_cookie_mask_get(src, &val64);
    of_flow_delete_strict_cookie_mask_set(dst, val64);

    of_flow_delete_strict_table_id_get(src, &val8);
    of_flow_delete_strict_table_id_set(dst, val8);

    of_flow_delete_strict_idle_timeout_get(src, &val16);
    of_flow_delete_strict_idle_timeout_set(dst, val16);

    of_flow_delete_strict_hard_timeout_get(src, &val16);
    of_flow_delete_strict_hard_timeout_set(dst, val16);

    of_flow_delete_strict_priority_get(src, &val16);
    of_flow_delete_strict_priority_set(dst, val16);

    of_flow_delete_strict_buffer_id_get(src, &val32);
    of_flow_delete_strict_buffer_id_set(dst, val32);

    of_flow_delete_strict_out_port_get(src, &port_no);
    of_flow_delete_strict_out_port_set(dst, port_no);

    of_flow_delete_strict_out_group_get(src, &val32);
    of_flow_delete_strict_out_group_set(dst, val32);

    of_flow_delete_strict_flags_get(src, &val16);
    of_flow_delete_strict_flags_set(dst, val16);

    of_flow_delete_strict_match_get(src, &match);
    of_flow_delete_strict_match_set(dst, &match);

    of_flow_delete_strict_instructions_bind(
        src, &src_list);
    dst_list = of_list_instruction_OF_VERSION_1_2_dup(&src_list);
    if (dst_list == NULL) {
        of_flow_delete_strict_delete(dst);
        return NULL;
    }
    of_flow_delete_strict_instructions_set(dst, dst_list);
    of_list_instruction_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_flow_mod
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_flow_mod.
 *
 * The caller is responsible for deleting the returned value
 */
of_flow_mod_t *
of_flow_mod_OF_VERSION_1_2_dup(
    of_flow_mod_t *src)
{
    of_flow_mod_t *dst;
    uint32_t val32;
    uint64_t val64;
    uint8_t val8;
    uint16_t val16;
    of_port_no_t port_no;
    of_match_t match;

    of_list_instruction_t src_list;
    of_list_instruction_t *dst_list;

    if ((dst = of_flow_mod_new(src->version)) == NULL) {
        return NULL;
    }

    of_flow_mod_xid_get(src, &val32);
    of_flow_mod_xid_set(dst, val32);

    of_flow_mod_cookie_get(src, &val64);
    of_flow_mod_cookie_set(dst, val64);

    of_flow_mod_cookie_mask_get(src, &val64);
    of_flow_mod_cookie_mask_set(dst, val64);

    of_flow_mod_table_id_get(src, &val8);
    of_flow_mod_table_id_set(dst, val8);

    of_flow_mod_idle_timeout_get(src, &val16);
    of_flow_mod_idle_timeout_set(dst, val16);

    of_flow_mod_hard_timeout_get(src, &val16);
    of_flow_mod_hard_timeout_set(dst, val16);

    of_flow_mod_priority_get(src, &val16);
    of_flow_mod_priority_set(dst, val16);

    of_flow_mod_buffer_id_get(src, &val32);
    of_flow_mod_buffer_id_set(dst, val32);

    of_flow_mod_out_port_get(src, &port_no);
    of_flow_mod_out_port_set(dst, port_no);

    of_flow_mod_out_group_get(src, &val32);
    of_flow_mod_out_group_set(dst, val32);

    of_flow_mod_flags_get(src, &val16);
    of_flow_mod_flags_set(dst, val16);

    of_flow_mod_match_get(src, &match);
    of_flow_mod_match_set(dst, &match);

    of_flow_mod_instructions_bind(
        src, &src_list);
    dst_list = of_list_instruction_OF_VERSION_1_2_dup(&src_list);
    if (dst_list == NULL) {
        of_flow_mod_delete(dst);
        return NULL;
    }
    of_flow_mod_instructions_set(dst, dst_list);
    of_list_instruction_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_flow_mod_failed_error_msg
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_flow_mod_failed_error_msg.
 *
 * The caller is responsible for deleting the returned value
 */
of_flow_mod_failed_error_msg_t *
of_flow_mod_failed_error_msg_OF_VERSION_1_2_dup(
    of_flow_mod_failed_error_msg_t *src)
{
    of_flow_mod_failed_error_msg_t *dst;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    if ((dst = of_flow_mod_failed_error_msg_new(src->version)) == NULL) {
        return NULL;
    }

    of_flow_mod_failed_error_msg_xid_get(src, &val32);
    of_flow_mod_failed_error_msg_xid_set(dst, val32);

    of_flow_mod_failed_error_msg_code_get(src, &val16);
    of_flow_mod_failed_error_msg_code_set(dst, val16);

    of_flow_mod_failed_error_msg_data_get(src, &octets);
    of_flow_mod_failed_error_msg_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_flow_modify
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_flow_modify.
 *
 * The caller is responsible for deleting the returned value
 */
of_flow_modify_t *
of_flow_modify_OF_VERSION_1_2_dup(
    of_flow_modify_t *src)
{
    of_flow_modify_t *dst;
    uint32_t val32;
    uint64_t val64;
    uint8_t val8;
    uint16_t val16;
    of_port_no_t port_no;
    of_match_t match;

    of_list_instruction_t src_list;
    of_list_instruction_t *dst_list;

    if ((dst = of_flow_modify_new(src->version)) == NULL) {
        return NULL;
    }

    of_flow_modify_xid_get(src, &val32);
    of_flow_modify_xid_set(dst, val32);

    of_flow_modify_cookie_get(src, &val64);
    of_flow_modify_cookie_set(dst, val64);

    of_flow_modify_cookie_mask_get(src, &val64);
    of_flow_modify_cookie_mask_set(dst, val64);

    of_flow_modify_table_id_get(src, &val8);
    of_flow_modify_table_id_set(dst, val8);

    of_flow_modify_idle_timeout_get(src, &val16);
    of_flow_modify_idle_timeout_set(dst, val16);

    of_flow_modify_hard_timeout_get(src, &val16);
    of_flow_modify_hard_timeout_set(dst, val16);

    of_flow_modify_priority_get(src, &val16);
    of_flow_modify_priority_set(dst, val16);

    of_flow_modify_buffer_id_get(src, &val32);
    of_flow_modify_buffer_id_set(dst, val32);

    of_flow_modify_out_port_get(src, &port_no);
    of_flow_modify_out_port_set(dst, port_no);

    of_flow_modify_out_group_get(src, &val32);
    of_flow_modify_out_group_set(dst, val32);

    of_flow_modify_flags_get(src, &val16);
    of_flow_modify_flags_set(dst, val16);

    of_flow_modify_match_get(src, &match);
    of_flow_modify_match_set(dst, &match);

    of_flow_modify_instructions_bind(
        src, &src_list);
    dst_list = of_list_instruction_OF_VERSION_1_2_dup(&src_list);
    if (dst_list == NULL) {
        of_flow_modify_delete(dst);
        return NULL;
    }
    of_flow_modify_instructions_set(dst, dst_list);
    of_list_instruction_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_flow_modify_strict
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_flow_modify_strict.
 *
 * The caller is responsible for deleting the returned value
 */
of_flow_modify_strict_t *
of_flow_modify_strict_OF_VERSION_1_2_dup(
    of_flow_modify_strict_t *src)
{
    of_flow_modify_strict_t *dst;
    uint32_t val32;
    uint64_t val64;
    uint8_t val8;
    uint16_t val16;
    of_port_no_t port_no;
    of_match_t match;

    of_list_instruction_t src_list;
    of_list_instruction_t *dst_list;

    if ((dst = of_flow_modify_strict_new(src->version)) == NULL) {
        return NULL;
    }

    of_flow_modify_strict_xid_get(src, &val32);
    of_flow_modify_strict_xid_set(dst, val32);

    of_flow_modify_strict_cookie_get(src, &val64);
    of_flow_modify_strict_cookie_set(dst, val64);

    of_flow_modify_strict_cookie_mask_get(src, &val64);
    of_flow_modify_strict_cookie_mask_set(dst, val64);

    of_flow_modify_strict_table_id_get(src, &val8);
    of_flow_modify_strict_table_id_set(dst, val8);

    of_flow_modify_strict_idle_timeout_get(src, &val16);
    of_flow_modify_strict_idle_timeout_set(dst, val16);

    of_flow_modify_strict_hard_timeout_get(src, &val16);
    of_flow_modify_strict_hard_timeout_set(dst, val16);

    of_flow_modify_strict_priority_get(src, &val16);
    of_flow_modify_strict_priority_set(dst, val16);

    of_flow_modify_strict_buffer_id_get(src, &val32);
    of_flow_modify_strict_buffer_id_set(dst, val32);

    of_flow_modify_strict_out_port_get(src, &port_no);
    of_flow_modify_strict_out_port_set(dst, port_no);

    of_flow_modify_strict_out_group_get(src, &val32);
    of_flow_modify_strict_out_group_set(dst, val32);

    of_flow_modify_strict_flags_get(src, &val16);
    of_flow_modify_strict_flags_set(dst, val16);

    of_flow_modify_strict_match_get(src, &match);
    of_flow_modify_strict_match_set(dst, &match);

    of_flow_modify_strict_instructions_bind(
        src, &src_list);
    dst_list = of_list_instruction_OF_VERSION_1_2_dup(&src_list);
    if (dst_list == NULL) {
        of_flow_modify_strict_delete(dst);
        return NULL;
    }
    of_flow_modify_strict_instructions_set(dst, dst_list);
    of_list_instruction_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_flow_removed
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_flow_removed.
 *
 * The caller is responsible for deleting the returned value
 */
of_flow_removed_t *
of_flow_removed_OF_VERSION_1_2_dup(
    of_flow_removed_t *src)
{
    of_flow_removed_t *dst;
    uint32_t val32;
    uint64_t val64;
    uint16_t val16;
    uint8_t val8;
    of_match_t match;

    if ((dst = of_flow_removed_new(src->version)) == NULL) {
        return NULL;
    }

    of_flow_removed_xid_get(src, &val32);
    of_flow_removed_xid_set(dst, val32);

    of_flow_removed_cookie_get(src, &val64);
    of_flow_removed_cookie_set(dst, val64);

    of_flow_removed_priority_get(src, &val16);
    of_flow_removed_priority_set(dst, val16);

    of_flow_removed_reason_get(src, &val8);
    of_flow_removed_reason_set(dst, val8);

    of_flow_removed_table_id_get(src, &val8);
    of_flow_removed_table_id_set(dst, val8);

    of_flow_removed_duration_sec_get(src, &val32);
    of_flow_removed_duration_sec_set(dst, val32);

    of_flow_removed_duration_nsec_get(src, &val32);
    of_flow_removed_duration_nsec_set(dst, val32);

    of_flow_removed_idle_timeout_get(src, &val16);
    of_flow_removed_idle_timeout_set(dst, val16);

    of_flow_removed_hard_timeout_get(src, &val16);
    of_flow_removed_hard_timeout_set(dst, val16);

    of_flow_removed_packet_count_get(src, &val64);
    of_flow_removed_packet_count_set(dst, val64);

    of_flow_removed_byte_count_get(src, &val64);
    of_flow_removed_byte_count_set(dst, val64);

    of_flow_removed_match_get(src, &match);
    of_flow_removed_match_set(dst, &match);

    return dst;
}

/**
 * Duplicate an object of type of_flow_stats_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_flow_stats_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_flow_stats_reply_t *
of_flow_stats_reply_OF_VERSION_1_2_dup(
    of_flow_stats_reply_t *src)
{
    of_flow_stats_reply_t *dst;
    uint32_t val32;
    uint16_t val16;

    of_list_flow_stats_entry_t src_list;
    of_list_flow_stats_entry_t *dst_list;

    if ((dst = of_flow_stats_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_flow_stats_reply_xid_get(src, &val32);
    of_flow_stats_reply_xid_set(dst, val32);

    of_flow_stats_reply_flags_get(src, &val16);
    of_flow_stats_reply_flags_set(dst, val16);

    of_flow_stats_reply_entries_bind(
        src, &src_list);
    dst_list = of_list_flow_stats_entry_OF_VERSION_1_2_dup(&src_list);
    if (dst_list == NULL) {
        of_flow_stats_reply_delete(dst);
        return NULL;
    }
    of_flow_stats_reply_entries_set(dst, dst_list);
    of_list_flow_stats_entry_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_flow_stats_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_flow_stats_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_flow_stats_request_t *
of_flow_stats_request_OF_VERSION_1_2_dup(
    of_flow_stats_request_t *src)
{
    of_flow_stats_request_t *dst;
    uint32_t val32;
    uint16_t val16;
    uint8_t val8;
    of_port_no_t port_no;
    uint64_t val64;
    of_match_t match;

    if ((dst = of_flow_stats_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_flow_stats_request_xid_get(src, &val32);
    of_flow_stats_request_xid_set(dst, val32);

    of_flow_stats_request_flags_get(src, &val16);
    of_flow_stats_request_flags_set(dst, val16);

    of_flow_stats_request_table_id_get(src, &val8);
    of_flow_stats_request_table_id_set(dst, val8);

    of_flow_stats_request_out_port_get(src, &port_no);
    of_flow_stats_request_out_port_set(dst, port_no);

    of_flow_stats_request_out_group_get(src, &val32);
    of_flow_stats_request_out_group_set(dst, val32);

    of_flow_stats_request_cookie_get(src, &val64);
    of_flow_stats_request_cookie_set(dst, val64);

    of_flow_stats_request_cookie_mask_get(src, &val64);
    of_flow_stats_request_cookie_mask_set(dst, val64);

    of_flow_stats_request_match_get(src, &match);
    of_flow_stats_request_match_set(dst, &match);

    return dst;
}

/**
 * Duplicate an object of type of_get_config_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_get_config_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_get_config_reply_t *
of_get_config_reply_OF_VERSION_1_2_dup(
    of_get_config_reply_t *src)
{
    of_get_config_reply_t *dst;
    uint32_t val32;
    uint16_t val16;

    if ((dst = of_get_config_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_get_config_reply_xid_get(src, &val32);
    of_get_config_reply_xid_set(dst, val32);

    of_get_config_reply_flags_get(src, &val16);
    of_get_config_reply_flags_set(dst, val16);

    of_get_config_reply_miss_send_len_get(src, &val16);
    of_get_config_reply_miss_send_len_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_get_config_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_get_config_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_get_config_request_t *
of_get_config_request_OF_VERSION_1_2_dup(
    of_get_config_request_t *src)
{
    of_get_config_request_t *dst;
    uint32_t val32;

    if ((dst = of_get_config_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_get_config_request_xid_get(src, &val32);
    of_get_config_request_xid_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_group_desc_stats_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_group_desc_stats_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_group_desc_stats_reply_t *
of_group_desc_stats_reply_OF_VERSION_1_2_dup(
    of_group_desc_stats_reply_t *src)
{
    of_group_desc_stats_reply_t *dst;
    uint32_t val32;
    uint16_t val16;

    of_list_group_desc_stats_entry_t src_list;
    of_list_group_desc_stats_entry_t *dst_list;

    if ((dst = of_group_desc_stats_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_group_desc_stats_reply_xid_get(src, &val32);
    of_group_desc_stats_reply_xid_set(dst, val32);

    of_group_desc_stats_reply_flags_get(src, &val16);
    of_group_desc_stats_reply_flags_set(dst, val16);

    of_group_desc_stats_reply_entries_bind(
        src, &src_list);
    dst_list = of_list_group_desc_stats_entry_OF_VERSION_1_2_dup(&src_list);
    if (dst_list == NULL) {
        of_group_desc_stats_reply_delete(dst);
        return NULL;
    }
    of_group_desc_stats_reply_entries_set(dst, dst_list);
    of_list_group_desc_stats_entry_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_group_desc_stats_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_group_desc_stats_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_group_desc_stats_request_t *
of_group_desc_stats_request_OF_VERSION_1_2_dup(
    of_group_desc_stats_request_t *src)
{
    of_group_desc_stats_request_t *dst;
    uint32_t val32;
    uint16_t val16;

    if ((dst = of_group_desc_stats_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_group_desc_stats_request_xid_get(src, &val32);
    of_group_desc_stats_request_xid_set(dst, val32);

    of_group_desc_stats_request_flags_get(src, &val16);
    of_group_desc_stats_request_flags_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_group_features_stats_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_group_features_stats_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_group_features_stats_reply_t *
of_group_features_stats_reply_OF_VERSION_1_2_dup(
    of_group_features_stats_reply_t *src)
{
    of_group_features_stats_reply_t *dst;
    uint32_t val32;
    uint16_t val16;

    if ((dst = of_group_features_stats_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_group_features_stats_reply_xid_get(src, &val32);
    of_group_features_stats_reply_xid_set(dst, val32);

    of_group_features_stats_reply_flags_get(src, &val16);
    of_group_features_stats_reply_flags_set(dst, val16);

    of_group_features_stats_reply_types_get(src, &val32);
    of_group_features_stats_reply_types_set(dst, val32);

    of_group_features_stats_reply_capabilities_get(src, &val32);
    of_group_features_stats_reply_capabilities_set(dst, val32);

    of_group_features_stats_reply_max_groups_all_get(src, &val32);
    of_group_features_stats_reply_max_groups_all_set(dst, val32);

    of_group_features_stats_reply_max_groups_select_get(src, &val32);
    of_group_features_stats_reply_max_groups_select_set(dst, val32);

    of_group_features_stats_reply_max_groups_indirect_get(src, &val32);
    of_group_features_stats_reply_max_groups_indirect_set(dst, val32);

    of_group_features_stats_reply_max_groups_ff_get(src, &val32);
    of_group_features_stats_reply_max_groups_ff_set(dst, val32);

    of_group_features_stats_reply_actions_all_get(src, &val32);
    of_group_features_stats_reply_actions_all_set(dst, val32);

    of_group_features_stats_reply_actions_select_get(src, &val32);
    of_group_features_stats_reply_actions_select_set(dst, val32);

    of_group_features_stats_reply_actions_indirect_get(src, &val32);
    of_group_features_stats_reply_actions_indirect_set(dst, val32);

    of_group_features_stats_reply_actions_ff_get(src, &val32);
    of_group_features_stats_reply_actions_ff_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_group_features_stats_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_group_features_stats_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_group_features_stats_request_t *
of_group_features_stats_request_OF_VERSION_1_2_dup(
    of_group_features_stats_request_t *src)
{
    of_group_features_stats_request_t *dst;
    uint32_t val32;
    uint16_t val16;

    if ((dst = of_group_features_stats_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_group_features_stats_request_xid_get(src, &val32);
    of_group_features_stats_request_xid_set(dst, val32);

    of_group_features_stats_request_flags_get(src, &val16);
    of_group_features_stats_request_flags_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_group_mod
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_group_mod.
 *
 * The caller is responsible for deleting the returned value
 */
of_group_mod_t *
of_group_mod_OF_VERSION_1_2_dup(
    of_group_mod_t *src)
{
    of_group_mod_t *dst;
    uint32_t val32;
    uint16_t val16;
    uint8_t val8;

    of_list_bucket_t src_list;
    of_list_bucket_t *dst_list;

    if ((dst = of_group_mod_new(src->version)) == NULL) {
        return NULL;
    }

    of_group_mod_xid_get(src, &val32);
    of_group_mod_xid_set(dst, val32);

    of_group_mod_command_get(src, &val16);
    of_group_mod_command_set(dst, val16);

    of_group_mod_group_type_get(src, &val8);
    of_group_mod_group_type_set(dst, val8);

    of_group_mod_group_id_get(src, &val32);
    of_group_mod_group_id_set(dst, val32);

    of_group_mod_buckets_bind(
        src, &src_list);
    dst_list = of_list_bucket_OF_VERSION_1_2_dup(&src_list);
    if (dst_list == NULL) {
        of_group_mod_delete(dst);
        return NULL;
    }
    of_group_mod_buckets_set(dst, dst_list);
    of_list_bucket_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_group_mod_failed_error_msg
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_group_mod_failed_error_msg.
 *
 * The caller is responsible for deleting the returned value
 */
of_group_mod_failed_error_msg_t *
of_group_mod_failed_error_msg_OF_VERSION_1_2_dup(
    of_group_mod_failed_error_msg_t *src)
{
    of_group_mod_failed_error_msg_t *dst;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    if ((dst = of_group_mod_failed_error_msg_new(src->version)) == NULL) {
        return NULL;
    }

    of_group_mod_failed_error_msg_xid_get(src, &val32);
    of_group_mod_failed_error_msg_xid_set(dst, val32);

    of_group_mod_failed_error_msg_code_get(src, &val16);
    of_group_mod_failed_error_msg_code_set(dst, val16);

    of_group_mod_failed_error_msg_data_get(src, &octets);
    of_group_mod_failed_error_msg_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_group_stats_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_group_stats_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_group_stats_reply_t *
of_group_stats_reply_OF_VERSION_1_2_dup(
    of_group_stats_reply_t *src)
{
    of_group_stats_reply_t *dst;
    uint32_t val32;
    uint16_t val16;

    of_list_group_stats_entry_t src_list;
    of_list_group_stats_entry_t *dst_list;

    if ((dst = of_group_stats_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_group_stats_reply_xid_get(src, &val32);
    of_group_stats_reply_xid_set(dst, val32);

    of_group_stats_reply_flags_get(src, &val16);
    of_group_stats_reply_flags_set(dst, val16);

    of_group_stats_reply_entries_bind(
        src, &src_list);
    dst_list = of_list_group_stats_entry_OF_VERSION_1_2_dup(&src_list);
    if (dst_list == NULL) {
        of_group_stats_reply_delete(dst);
        return NULL;
    }
    of_group_stats_reply_entries_set(dst, dst_list);
    of_list_group_stats_entry_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_group_stats_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_group_stats_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_group_stats_request_t *
of_group_stats_request_OF_VERSION_1_2_dup(
    of_group_stats_request_t *src)
{
    of_group_stats_request_t *dst;
    uint32_t val32;
    uint16_t val16;

    if ((dst = of_group_stats_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_group_stats_request_xid_get(src, &val32);
    of_group_stats_request_xid_set(dst, val32);

    of_group_stats_request_flags_get(src, &val16);
    of_group_stats_request_flags_set(dst, val16);

    of_group_stats_request_group_id_get(src, &val32);
    of_group_stats_request_group_id_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_hello
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_hello.
 *
 * The caller is responsible for deleting the returned value
 */
of_hello_t *
of_hello_OF_VERSION_1_2_dup(
    of_hello_t *src)
{
    of_hello_t *dst;
    uint32_t val32;

    if ((dst = of_hello_new(src->version)) == NULL) {
        return NULL;
    }

    of_hello_xid_get(src, &val32);
    of_hello_xid_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_hello_failed_error_msg
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_hello_failed_error_msg.
 *
 * The caller is responsible for deleting the returned value
 */
of_hello_failed_error_msg_t *
of_hello_failed_error_msg_OF_VERSION_1_2_dup(
    of_hello_failed_error_msg_t *src)
{
    of_hello_failed_error_msg_t *dst;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    if ((dst = of_hello_failed_error_msg_new(src->version)) == NULL) {
        return NULL;
    }

    of_hello_failed_error_msg_xid_get(src, &val32);
    of_hello_failed_error_msg_xid_set(dst, val32);

    of_hello_failed_error_msg_code_get(src, &val16);
    of_hello_failed_error_msg_code_set(dst, val16);

    of_hello_failed_error_msg_data_get(src, &octets);
    of_hello_failed_error_msg_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_nicira_header
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_nicira_header.
 *
 * The caller is responsible for deleting the returned value
 */
of_nicira_header_t *
of_nicira_header_OF_VERSION_1_2_dup(
    of_nicira_header_t *src)
{
    of_nicira_header_t *dst;
    uint32_t val32;

    if ((dst = of_nicira_header_new(src->version)) == NULL) {
        return NULL;
    }

    of_nicira_header_xid_get(src, &val32);
    of_nicira_header_xid_set(dst, val32);

    of_nicira_header_experimenter_get(src, &val32);
    of_nicira_header_experimenter_set(dst, val32);

    of_nicira_header_subtype_get(src, &val32);
    of_nicira_header_subtype_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_packet_in
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_packet_in.
 *
 * The caller is responsible for deleting the returned value
 */
of_packet_in_t *
of_packet_in_OF_VERSION_1_2_dup(
    of_packet_in_t *src)
{
    of_packet_in_t *dst;
    uint32_t val32;
    uint16_t val16;
    uint8_t val8;
    of_match_t match;
    of_octets_t octets;

    if ((dst = of_packet_in_new(src->version)) == NULL) {
        return NULL;
    }

    of_packet_in_xid_get(src, &val32);
    of_packet_in_xid_set(dst, val32);

    of_packet_in_buffer_id_get(src, &val32);
    of_packet_in_buffer_id_set(dst, val32);

    of_packet_in_total_len_get(src, &val16);
    of_packet_in_total_len_set(dst, val16);

    of_packet_in_reason_get(src, &val8);
    of_packet_in_reason_set(dst, val8);

    of_packet_in_table_id_get(src, &val8);
    of_packet_in_table_id_set(dst, val8);

    of_packet_in_match_get(src, &match);
    of_packet_in_match_set(dst, &match);

    of_packet_in_data_get(src, &octets);
    of_packet_in_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_packet_out
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_packet_out.
 *
 * The caller is responsible for deleting the returned value
 */
of_packet_out_t *
of_packet_out_OF_VERSION_1_2_dup(
    of_packet_out_t *src)
{
    of_packet_out_t *dst;
    uint32_t val32;
    of_port_no_t port_no;

    of_list_action_t src_list;
    of_list_action_t *dst_list;
    of_octets_t octets;

    if ((dst = of_packet_out_new(src->version)) == NULL) {
        return NULL;
    }

    of_packet_out_xid_get(src, &val32);
    of_packet_out_xid_set(dst, val32);

    of_packet_out_buffer_id_get(src, &val32);
    of_packet_out_buffer_id_set(dst, val32);

    of_packet_out_in_port_get(src, &port_no);
    of_packet_out_in_port_set(dst, port_no);

    of_packet_out_actions_bind(
        src, &src_list);
    dst_list = of_list_action_OF_VERSION_1_2_dup(&src_list);
    if (dst_list == NULL) {
        of_packet_out_delete(dst);
        return NULL;
    }
    of_packet_out_actions_set(dst, dst_list);
    of_list_action_delete(dst_list);

    of_packet_out_data_get(src, &octets);
    of_packet_out_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_port_mod
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_port_mod.
 *
 * The caller is responsible for deleting the returned value
 */
of_port_mod_t *
of_port_mod_OF_VERSION_1_2_dup(
    of_port_mod_t *src)
{
    of_port_mod_t *dst;
    uint32_t val32;
    of_port_no_t port_no;
    of_mac_addr_t mac_addr;

    if ((dst = of_port_mod_new(src->version)) == NULL) {
        return NULL;
    }

    of_port_mod_xid_get(src, &val32);
    of_port_mod_xid_set(dst, val32);

    of_port_mod_port_no_get(src, &port_no);
    of_port_mod_port_no_set(dst, port_no);

    of_port_mod_hw_addr_get(src, &mac_addr);
    of_port_mod_hw_addr_set(dst, mac_addr);

    of_port_mod_config_get(src, &val32);
    of_port_mod_config_set(dst, val32);

    of_port_mod_mask_get(src, &val32);
    of_port_mod_mask_set(dst, val32);

    of_port_mod_advertise_get(src, &val32);
    of_port_mod_advertise_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_port_mod_failed_error_msg
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_port_mod_failed_error_msg.
 *
 * The caller is responsible for deleting the returned value
 */
of_port_mod_failed_error_msg_t *
of_port_mod_failed_error_msg_OF_VERSION_1_2_dup(
    of_port_mod_failed_error_msg_t *src)
{
    of_port_mod_failed_error_msg_t *dst;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    if ((dst = of_port_mod_failed_error_msg_new(src->version)) == NULL) {
        return NULL;
    }

    of_port_mod_failed_error_msg_xid_get(src, &val32);
    of_port_mod_failed_error_msg_xid_set(dst, val32);

    of_port_mod_failed_error_msg_code_get(src, &val16);
    of_port_mod_failed_error_msg_code_set(dst, val16);

    of_port_mod_failed_error_msg_data_get(src, &octets);
    of_port_mod_failed_error_msg_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_port_stats_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_port_stats_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_port_stats_reply_t *
of_port_stats_reply_OF_VERSION_1_2_dup(
    of_port_stats_reply_t *src)
{
    of_port_stats_reply_t *dst;
    uint32_t val32;
    uint16_t val16;

    of_list_port_stats_entry_t src_list;
    of_list_port_stats_entry_t *dst_list;

    if ((dst = of_port_stats_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_port_stats_reply_xid_get(src, &val32);
    of_port_stats_reply_xid_set(dst, val32);

    of_port_stats_reply_flags_get(src, &val16);
    of_port_stats_reply_flags_set(dst, val16);

    of_port_stats_reply_entries_bind(
        src, &src_list);
    dst_list = of_list_port_stats_entry_OF_VERSION_1_2_dup(&src_list);
    if (dst_list == NULL) {
        of_port_stats_reply_delete(dst);
        return NULL;
    }
    of_port_stats_reply_entries_set(dst, dst_list);
    of_list_port_stats_entry_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_port_stats_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_port_stats_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_port_stats_request_t *
of_port_stats_request_OF_VERSION_1_2_dup(
    of_port_stats_request_t *src)
{
    of_port_stats_request_t *dst;
    uint32_t val32;
    uint16_t val16;
    of_port_no_t port_no;

    if ((dst = of_port_stats_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_port_stats_request_xid_get(src, &val32);
    of_port_stats_request_xid_set(dst, val32);

    of_port_stats_request_flags_get(src, &val16);
    of_port_stats_request_flags_set(dst, val16);

    of_port_stats_request_port_no_get(src, &port_no);
    of_port_stats_request_port_no_set(dst, port_no);

    return dst;
}

/**
 * Duplicate an object of type of_port_status
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_port_status.
 *
 * The caller is responsible for deleting the returned value
 */
of_port_status_t *
of_port_status_OF_VERSION_1_2_dup(
    of_port_status_t *src)
{
    of_port_status_t *dst;
    uint32_t val32;
    uint8_t val8;

    of_port_desc_t src_port_desc;
    of_port_desc_t *dst_port_desc;

    if ((dst = of_port_status_new(src->version)) == NULL) {
        return NULL;
    }

    of_port_status_xid_get(src, &val32);
    of_port_status_xid_set(dst, val32);

    of_port_status_reason_get(src, &val8);
    of_port_status_reason_set(dst, val8);

    of_port_status_desc_bind(
        src, &src_port_desc);
    dst_port_desc = of_port_desc_OF_VERSION_1_2_dup(&src_port_desc);
    if (dst_port_desc == NULL) {
        of_port_status_delete(dst);
        return NULL;
    }
    of_port_status_desc_set(dst, dst_port_desc);
    of_port_desc_delete(dst_port_desc);

    return dst;
}

/**
 * Duplicate an object of type of_queue_get_config_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_queue_get_config_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_queue_get_config_reply_t *
of_queue_get_config_reply_OF_VERSION_1_2_dup(
    of_queue_get_config_reply_t *src)
{
    of_queue_get_config_reply_t *dst;
    uint32_t val32;
    of_port_no_t port_no;

    of_list_packet_queue_t src_list;
    of_list_packet_queue_t *dst_list;

    if ((dst = of_queue_get_config_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_queue_get_config_reply_xid_get(src, &val32);
    of_queue_get_config_reply_xid_set(dst, val32);

    of_queue_get_config_reply_port_get(src, &port_no);
    of_queue_get_config_reply_port_set(dst, port_no);

    of_queue_get_config_reply_queues_bind(
        src, &src_list);
    dst_list = of_list_packet_queue_OF_VERSION_1_2_dup(&src_list);
    if (dst_list == NULL) {
        of_queue_get_config_reply_delete(dst);
        return NULL;
    }
    of_queue_get_config_reply_queues_set(dst, dst_list);
    of_list_packet_queue_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_queue_get_config_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_queue_get_config_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_queue_get_config_request_t *
of_queue_get_config_request_OF_VERSION_1_2_dup(
    of_queue_get_config_request_t *src)
{
    of_queue_get_config_request_t *dst;
    uint32_t val32;
    of_port_no_t port_no;

    if ((dst = of_queue_get_config_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_queue_get_config_request_xid_get(src, &val32);
    of_queue_get_config_request_xid_set(dst, val32);

    of_queue_get_config_request_port_get(src, &port_no);
    of_queue_get_config_request_port_set(dst, port_no);

    return dst;
}

/**
 * Duplicate an object of type of_queue_op_failed_error_msg
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_queue_op_failed_error_msg.
 *
 * The caller is responsible for deleting the returned value
 */
of_queue_op_failed_error_msg_t *
of_queue_op_failed_error_msg_OF_VERSION_1_2_dup(
    of_queue_op_failed_error_msg_t *src)
{
    of_queue_op_failed_error_msg_t *dst;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    if ((dst = of_queue_op_failed_error_msg_new(src->version)) == NULL) {
        return NULL;
    }

    of_queue_op_failed_error_msg_xid_get(src, &val32);
    of_queue_op_failed_error_msg_xid_set(dst, val32);

    of_queue_op_failed_error_msg_code_get(src, &val16);
    of_queue_op_failed_error_msg_code_set(dst, val16);

    of_queue_op_failed_error_msg_data_get(src, &octets);
    of_queue_op_failed_error_msg_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_queue_stats_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_queue_stats_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_queue_stats_reply_t *
of_queue_stats_reply_OF_VERSION_1_2_dup(
    of_queue_stats_reply_t *src)
{
    of_queue_stats_reply_t *dst;
    uint32_t val32;
    uint16_t val16;

    of_list_queue_stats_entry_t src_list;
    of_list_queue_stats_entry_t *dst_list;

    if ((dst = of_queue_stats_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_queue_stats_reply_xid_get(src, &val32);
    of_queue_stats_reply_xid_set(dst, val32);

    of_queue_stats_reply_flags_get(src, &val16);
    of_queue_stats_reply_flags_set(dst, val16);

    of_queue_stats_reply_entries_bind(
        src, &src_list);
    dst_list = of_list_queue_stats_entry_OF_VERSION_1_2_dup(&src_list);
    if (dst_list == NULL) {
        of_queue_stats_reply_delete(dst);
        return NULL;
    }
    of_queue_stats_reply_entries_set(dst, dst_list);
    of_list_queue_stats_entry_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_queue_stats_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_queue_stats_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_queue_stats_request_t *
of_queue_stats_request_OF_VERSION_1_2_dup(
    of_queue_stats_request_t *src)
{
    of_queue_stats_request_t *dst;
    uint32_t val32;
    uint16_t val16;
    of_port_no_t port_no;

    if ((dst = of_queue_stats_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_queue_stats_request_xid_get(src, &val32);
    of_queue_stats_request_xid_set(dst, val32);

    of_queue_stats_request_flags_get(src, &val16);
    of_queue_stats_request_flags_set(dst, val16);

    of_queue_stats_request_port_no_get(src, &port_no);
    of_queue_stats_request_port_no_set(dst, port_no);

    of_queue_stats_request_queue_id_get(src, &val32);
    of_queue_stats_request_queue_id_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_role_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_role_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_role_reply_t *
of_role_reply_OF_VERSION_1_2_dup(
    of_role_reply_t *src)
{
    of_role_reply_t *dst;
    uint32_t val32;
    uint64_t val64;

    if ((dst = of_role_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_role_reply_xid_get(src, &val32);
    of_role_reply_xid_set(dst, val32);

    of_role_reply_role_get(src, &val32);
    of_role_reply_role_set(dst, val32);

    of_role_reply_generation_id_get(src, &val64);
    of_role_reply_generation_id_set(dst, val64);

    return dst;
}

/**
 * Duplicate an object of type of_role_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_role_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_role_request_t *
of_role_request_OF_VERSION_1_2_dup(
    of_role_request_t *src)
{
    of_role_request_t *dst;
    uint32_t val32;
    uint64_t val64;

    if ((dst = of_role_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_role_request_xid_get(src, &val32);
    of_role_request_xid_set(dst, val32);

    of_role_request_role_get(src, &val32);
    of_role_request_role_set(dst, val32);

    of_role_request_generation_id_get(src, &val64);
    of_role_request_generation_id_set(dst, val64);

    return dst;
}

/**
 * Duplicate an object of type of_role_request_failed_error_msg
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_role_request_failed_error_msg.
 *
 * The caller is responsible for deleting the returned value
 */
of_role_request_failed_error_msg_t *
of_role_request_failed_error_msg_OF_VERSION_1_2_dup(
    of_role_request_failed_error_msg_t *src)
{
    of_role_request_failed_error_msg_t *dst;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    if ((dst = of_role_request_failed_error_msg_new(src->version)) == NULL) {
        return NULL;
    }

    of_role_request_failed_error_msg_xid_get(src, &val32);
    of_role_request_failed_error_msg_xid_set(dst, val32);

    of_role_request_failed_error_msg_code_get(src, &val16);
    of_role_request_failed_error_msg_code_set(dst, val16);

    of_role_request_failed_error_msg_data_get(src, &octets);
    of_role_request_failed_error_msg_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_set_config
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_set_config.
 *
 * The caller is responsible for deleting the returned value
 */
of_set_config_t *
of_set_config_OF_VERSION_1_2_dup(
    of_set_config_t *src)
{
    of_set_config_t *dst;
    uint32_t val32;
    uint16_t val16;

    if ((dst = of_set_config_new(src->version)) == NULL) {
        return NULL;
    }

    of_set_config_xid_get(src, &val32);
    of_set_config_xid_set(dst, val32);

    of_set_config_flags_get(src, &val16);
    of_set_config_flags_set(dst, val16);

    of_set_config_miss_send_len_get(src, &val16);
    of_set_config_miss_send_len_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_stats_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_stats_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_stats_reply_t *
of_stats_reply_OF_VERSION_1_2_dup(
    of_stats_reply_t *src)
{
    of_stats_reply_t *dst;
    uint32_t val32;
    uint16_t val16;

    if ((dst = of_stats_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_stats_reply_xid_get(src, &val32);
    of_stats_reply_xid_set(dst, val32);

    of_stats_reply_flags_get(src, &val16);
    of_stats_reply_flags_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_stats_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_stats_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_stats_request_t *
of_stats_request_OF_VERSION_1_2_dup(
    of_stats_request_t *src)
{
    of_stats_request_t *dst;
    uint32_t val32;
    uint16_t val16;

    if ((dst = of_stats_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_stats_request_xid_get(src, &val32);
    of_stats_request_xid_set(dst, val32);

    of_stats_request_flags_get(src, &val16);
    of_stats_request_flags_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_switch_config_failed_error_msg
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_switch_config_failed_error_msg.
 *
 * The caller is responsible for deleting the returned value
 */
of_switch_config_failed_error_msg_t *
of_switch_config_failed_error_msg_OF_VERSION_1_2_dup(
    of_switch_config_failed_error_msg_t *src)
{
    of_switch_config_failed_error_msg_t *dst;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    if ((dst = of_switch_config_failed_error_msg_new(src->version)) == NULL) {
        return NULL;
    }

    of_switch_config_failed_error_msg_xid_get(src, &val32);
    of_switch_config_failed_error_msg_xid_set(dst, val32);

    of_switch_config_failed_error_msg_code_get(src, &val16);
    of_switch_config_failed_error_msg_code_set(dst, val16);

    of_switch_config_failed_error_msg_data_get(src, &octets);
    of_switch_config_failed_error_msg_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_table_mod
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_table_mod.
 *
 * The caller is responsible for deleting the returned value
 */
of_table_mod_t *
of_table_mod_OF_VERSION_1_2_dup(
    of_table_mod_t *src)
{
    of_table_mod_t *dst;
    uint32_t val32;
    uint8_t val8;

    if ((dst = of_table_mod_new(src->version)) == NULL) {
        return NULL;
    }

    of_table_mod_xid_get(src, &val32);
    of_table_mod_xid_set(dst, val32);

    of_table_mod_table_id_get(src, &val8);
    of_table_mod_table_id_set(dst, val8);

    of_table_mod_config_get(src, &val32);
    of_table_mod_config_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_table_mod_failed_error_msg
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_table_mod_failed_error_msg.
 *
 * The caller is responsible for deleting the returned value
 */
of_table_mod_failed_error_msg_t *
of_table_mod_failed_error_msg_OF_VERSION_1_2_dup(
    of_table_mod_failed_error_msg_t *src)
{
    of_table_mod_failed_error_msg_t *dst;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    if ((dst = of_table_mod_failed_error_msg_new(src->version)) == NULL) {
        return NULL;
    }

    of_table_mod_failed_error_msg_xid_get(src, &val32);
    of_table_mod_failed_error_msg_xid_set(dst, val32);

    of_table_mod_failed_error_msg_code_get(src, &val16);
    of_table_mod_failed_error_msg_code_set(dst, val16);

    of_table_mod_failed_error_msg_data_get(src, &octets);
    of_table_mod_failed_error_msg_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_table_stats_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_table_stats_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_table_stats_reply_t *
of_table_stats_reply_OF_VERSION_1_2_dup(
    of_table_stats_reply_t *src)
{
    of_table_stats_reply_t *dst;
    uint32_t val32;
    uint16_t val16;

    of_list_table_stats_entry_t src_list;
    of_list_table_stats_entry_t *dst_list;

    if ((dst = of_table_stats_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_table_stats_reply_xid_get(src, &val32);
    of_table_stats_reply_xid_set(dst, val32);

    of_table_stats_reply_flags_get(src, &val16);
    of_table_stats_reply_flags_set(dst, val16);

    of_table_stats_reply_entries_bind(
        src, &src_list);
    dst_list = of_list_table_stats_entry_OF_VERSION_1_2_dup(&src_list);
    if (dst_list == NULL) {
        of_table_stats_reply_delete(dst);
        return NULL;
    }
    of_table_stats_reply_entries_set(dst, dst_list);
    of_list_table_stats_entry_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_table_stats_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_table_stats_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_table_stats_request_t *
of_table_stats_request_OF_VERSION_1_2_dup(
    of_table_stats_request_t *src)
{
    of_table_stats_request_t *dst;
    uint32_t val32;
    uint16_t val16;

    if ((dst = of_table_stats_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_table_stats_request_xid_get(src, &val32);
    of_table_stats_request_xid_set(dst, val32);

    of_table_stats_request_flags_get(src, &val16);
    of_table_stats_request_flags_set(dst, val16);

    return dst;
}

/**
 * Duplicate a super class object of type of_action
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_t *
of_action_OF_VERSION_1_2_dup(
    of_action_t *src)
{

    if (src->header.object_id == OF_ACTION_NICIRA) {
        return (of_action_t *)of_action_nicira_OF_VERSION_1_2_dup(
            &src->nicira);
    }

    if (src->header.object_id == OF_ACTION_GROUP) {
        return (of_action_t *)of_action_group_OF_VERSION_1_2_dup(
            &src->group);
    }

    if (src->header.object_id == OF_ACTION_BSN_MIRROR) {
        return (of_action_t *)of_action_bsn_mirror_OF_VERSION_1_2_dup(
            &src->bsn_mirror);
    }

    if (src->header.object_id == OF_ACTION_POP_MPLS) {
        return (of_action_t *)of_action_pop_mpls_OF_VERSION_1_2_dup(
            &src->pop_mpls);
    }

    if (src->header.object_id == OF_ACTION_PUSH_VLAN) {
        return (of_action_t *)of_action_push_vlan_OF_VERSION_1_2_dup(
            &src->push_vlan);
    }

    if (src->header.object_id == OF_ACTION_PUSH_MPLS) {
        return (of_action_t *)of_action_push_mpls_OF_VERSION_1_2_dup(
            &src->push_mpls);
    }

    if (src->header.object_id == OF_ACTION_COPY_TTL_OUT) {
        return (of_action_t *)of_action_copy_ttl_out_OF_VERSION_1_2_dup(
            &src->copy_ttl_out);
    }

    if (src->header.object_id == OF_ACTION_SET_FIELD) {
        return (of_action_t *)of_action_set_field_OF_VERSION_1_2_dup(
            &src->set_field);
    }

    if (src->header.object_id == OF_ACTION_SET_MPLS_TTL) {
        return (of_action_t *)of_action_set_mpls_ttl_OF_VERSION_1_2_dup(
            &src->set_mpls_ttl);
    }

    if (src->header.object_id == OF_ACTION_POP_VLAN) {
        return (of_action_t *)of_action_pop_vlan_OF_VERSION_1_2_dup(
            &src->pop_vlan);
    }

    if (src->header.object_id == OF_ACTION_SET_NW_TTL) {
        return (of_action_t *)of_action_set_nw_ttl_OF_VERSION_1_2_dup(
            &src->set_nw_ttl);
    }

    if (src->header.object_id == OF_ACTION_DEC_NW_TTL) {
        return (of_action_t *)of_action_dec_nw_ttl_OF_VERSION_1_2_dup(
            &src->dec_nw_ttl);
    }

    if (src->header.object_id == OF_ACTION_BSN) {
        return (of_action_t *)of_action_bsn_OF_VERSION_1_2_dup(
            &src->bsn);
    }

    if (src->header.object_id == OF_ACTION_EXPERIMENTER) {
        return (of_action_t *)of_action_experimenter_OF_VERSION_1_2_dup(
            &src->experimenter);
    }

    if (src->header.object_id == OF_ACTION_DEC_MPLS_TTL) {
        return (of_action_t *)of_action_dec_mpls_ttl_OF_VERSION_1_2_dup(
            &src->dec_mpls_ttl);
    }

    if (src->header.object_id == OF_ACTION_BSN_SET_TUNNEL_DST) {
        return (of_action_t *)of_action_bsn_set_tunnel_dst_OF_VERSION_1_2_dup(
            &src->bsn_set_tunnel_dst);
    }

    if (src->header.object_id == OF_ACTION_OUTPUT) {
        return (of_action_t *)of_action_output_OF_VERSION_1_2_dup(
            &src->output);
    }

    if (src->header.object_id == OF_ACTION_NICIRA_DEC_TTL) {
        return (of_action_t *)of_action_nicira_dec_ttl_OF_VERSION_1_2_dup(
            &src->nicira_dec_ttl);
    }

    if (src->header.object_id == OF_ACTION_COPY_TTL_IN) {
        return (of_action_t *)of_action_copy_ttl_in_OF_VERSION_1_2_dup(
            &src->copy_ttl_in);
    }

    if (src->header.object_id == OF_ACTION_SET_QUEUE) {
        return (of_action_t *)of_action_set_queue_OF_VERSION_1_2_dup(
            &src->set_queue);
    }

    return NULL;
}

/**
 * Duplicate an object of type of_action_bsn
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_bsn.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_bsn_t *
of_action_bsn_OF_VERSION_1_2_dup(
    of_action_bsn_t *src)
{
    of_action_bsn_t *dst;
    uint32_t val32;

    if ((dst = of_action_bsn_new(src->version)) == NULL) {
        return NULL;
    }

    of_action_bsn_experimenter_get(src, &val32);
    of_action_bsn_experimenter_set(dst, val32);

    of_action_bsn_subtype_get(src, &val32);
    of_action_bsn_subtype_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_action_bsn_mirror
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_bsn_mirror.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_bsn_mirror_t *
of_action_bsn_mirror_OF_VERSION_1_2_dup(
    of_action_bsn_mirror_t *src)
{
    of_action_bsn_mirror_t *dst;
    uint32_t val32;
    uint8_t val8;

    if ((dst = of_action_bsn_mirror_new(src->version)) == NULL) {
        return NULL;
    }

    of_action_bsn_mirror_experimenter_get(src, &val32);
    of_action_bsn_mirror_experimenter_set(dst, val32);

    of_action_bsn_mirror_subtype_get(src, &val32);
    of_action_bsn_mirror_subtype_set(dst, val32);

    of_action_bsn_mirror_dest_port_get(src, &val32);
    of_action_bsn_mirror_dest_port_set(dst, val32);

    of_action_bsn_mirror_vlan_tag_get(src, &val32);
    of_action_bsn_mirror_vlan_tag_set(dst, val32);

    of_action_bsn_mirror_copy_stage_get(src, &val8);
    of_action_bsn_mirror_copy_stage_set(dst, val8);

    return dst;
}

/**
 * Duplicate an object of type of_action_bsn_set_tunnel_dst
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_bsn_set_tunnel_dst.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_bsn_set_tunnel_dst_t *
of_action_bsn_set_tunnel_dst_OF_VERSION_1_2_dup(
    of_action_bsn_set_tunnel_dst_t *src)
{
    of_action_bsn_set_tunnel_dst_t *dst;
    uint32_t val32;

    if ((dst = of_action_bsn_set_tunnel_dst_new(src->version)) == NULL) {
        return NULL;
    }

    of_action_bsn_set_tunnel_dst_experimenter_get(src, &val32);
    of_action_bsn_set_tunnel_dst_experimenter_set(dst, val32);

    of_action_bsn_set_tunnel_dst_subtype_get(src, &val32);
    of_action_bsn_set_tunnel_dst_subtype_set(dst, val32);

    of_action_bsn_set_tunnel_dst_dst_get(src, &val32);
    of_action_bsn_set_tunnel_dst_dst_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_action_copy_ttl_in
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_copy_ttl_in.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_copy_ttl_in_t *
of_action_copy_ttl_in_OF_VERSION_1_2_dup(
    of_action_copy_ttl_in_t *src)
{
    of_action_copy_ttl_in_t *dst;

    if ((dst = of_action_copy_ttl_in_new(src->version)) == NULL) {
        return NULL;
    }

    return dst;
}

/**
 * Duplicate an object of type of_action_copy_ttl_out
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_copy_ttl_out.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_copy_ttl_out_t *
of_action_copy_ttl_out_OF_VERSION_1_2_dup(
    of_action_copy_ttl_out_t *src)
{
    of_action_copy_ttl_out_t *dst;

    if ((dst = of_action_copy_ttl_out_new(src->version)) == NULL) {
        return NULL;
    }

    return dst;
}

/**
 * Duplicate an object of type of_action_dec_mpls_ttl
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_dec_mpls_ttl.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_dec_mpls_ttl_t *
of_action_dec_mpls_ttl_OF_VERSION_1_2_dup(
    of_action_dec_mpls_ttl_t *src)
{
    of_action_dec_mpls_ttl_t *dst;

    if ((dst = of_action_dec_mpls_ttl_new(src->version)) == NULL) {
        return NULL;
    }

    return dst;
}

/**
 * Duplicate an object of type of_action_dec_nw_ttl
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_dec_nw_ttl.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_dec_nw_ttl_t *
of_action_dec_nw_ttl_OF_VERSION_1_2_dup(
    of_action_dec_nw_ttl_t *src)
{
    of_action_dec_nw_ttl_t *dst;

    if ((dst = of_action_dec_nw_ttl_new(src->version)) == NULL) {
        return NULL;
    }

    return dst;
}

/**
 * Duplicate an object of type of_action_experimenter
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_experimenter.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_experimenter_t *
of_action_experimenter_OF_VERSION_1_2_dup(
    of_action_experimenter_t *src)
{
    of_action_experimenter_t *dst;
    uint32_t val32;
    of_octets_t octets;

    if ((dst = of_action_experimenter_new(src->version)) == NULL) {
        return NULL;
    }

    of_action_experimenter_experimenter_get(src, &val32);
    of_action_experimenter_experimenter_set(dst, val32);

    of_action_experimenter_data_get(src, &octets);
    of_action_experimenter_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_action_group
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_group.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_group_t *
of_action_group_OF_VERSION_1_2_dup(
    of_action_group_t *src)
{
    of_action_group_t *dst;
    uint32_t val32;

    if ((dst = of_action_group_new(src->version)) == NULL) {
        return NULL;
    }

    of_action_group_group_id_get(src, &val32);
    of_action_group_group_id_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_action_header
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_header.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_header_t *
of_action_header_OF_VERSION_1_2_dup(
    of_action_header_t *src)
{
    of_action_header_t *dst;

    if ((dst = of_action_header_new(src->version)) == NULL) {
        return NULL;
    }

    return dst;
}

/**
 * Duplicate an object of type of_action_nicira
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_nicira.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_nicira_t *
of_action_nicira_OF_VERSION_1_2_dup(
    of_action_nicira_t *src)
{
    of_action_nicira_t *dst;
    uint32_t val32;
    uint16_t val16;

    if ((dst = of_action_nicira_new(src->version)) == NULL) {
        return NULL;
    }

    of_action_nicira_experimenter_get(src, &val32);
    of_action_nicira_experimenter_set(dst, val32);

    of_action_nicira_subtype_get(src, &val16);
    of_action_nicira_subtype_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_action_nicira_dec_ttl
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_nicira_dec_ttl.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_nicira_dec_ttl_t *
of_action_nicira_dec_ttl_OF_VERSION_1_2_dup(
    of_action_nicira_dec_ttl_t *src)
{
    of_action_nicira_dec_ttl_t *dst;
    uint32_t val32;
    uint16_t val16;

    if ((dst = of_action_nicira_dec_ttl_new(src->version)) == NULL) {
        return NULL;
    }

    of_action_nicira_dec_ttl_experimenter_get(src, &val32);
    of_action_nicira_dec_ttl_experimenter_set(dst, val32);

    of_action_nicira_dec_ttl_subtype_get(src, &val16);
    of_action_nicira_dec_ttl_subtype_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_action_output
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_output.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_output_t *
of_action_output_OF_VERSION_1_2_dup(
    of_action_output_t *src)
{
    of_action_output_t *dst;
    of_port_no_t port_no;
    uint16_t val16;

    if ((dst = of_action_output_new(src->version)) == NULL) {
        return NULL;
    }

    of_action_output_port_get(src, &port_no);
    of_action_output_port_set(dst, port_no);

    of_action_output_max_len_get(src, &val16);
    of_action_output_max_len_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_action_pop_mpls
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_pop_mpls.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_pop_mpls_t *
of_action_pop_mpls_OF_VERSION_1_2_dup(
    of_action_pop_mpls_t *src)
{
    of_action_pop_mpls_t *dst;
    uint16_t val16;

    if ((dst = of_action_pop_mpls_new(src->version)) == NULL) {
        return NULL;
    }

    of_action_pop_mpls_ethertype_get(src, &val16);
    of_action_pop_mpls_ethertype_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_action_pop_vlan
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_pop_vlan.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_pop_vlan_t *
of_action_pop_vlan_OF_VERSION_1_2_dup(
    of_action_pop_vlan_t *src)
{
    of_action_pop_vlan_t *dst;

    if ((dst = of_action_pop_vlan_new(src->version)) == NULL) {
        return NULL;
    }

    return dst;
}

/**
 * Duplicate an object of type of_action_push_mpls
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_push_mpls.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_push_mpls_t *
of_action_push_mpls_OF_VERSION_1_2_dup(
    of_action_push_mpls_t *src)
{
    of_action_push_mpls_t *dst;
    uint16_t val16;

    if ((dst = of_action_push_mpls_new(src->version)) == NULL) {
        return NULL;
    }

    of_action_push_mpls_ethertype_get(src, &val16);
    of_action_push_mpls_ethertype_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_action_push_vlan
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_push_vlan.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_push_vlan_t *
of_action_push_vlan_OF_VERSION_1_2_dup(
    of_action_push_vlan_t *src)
{
    of_action_push_vlan_t *dst;
    uint16_t val16;

    if ((dst = of_action_push_vlan_new(src->version)) == NULL) {
        return NULL;
    }

    of_action_push_vlan_ethertype_get(src, &val16);
    of_action_push_vlan_ethertype_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_action_set_field
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_set_field.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_set_field_t *
of_action_set_field_OF_VERSION_1_2_dup(
    of_action_set_field_t *src)
{
    of_action_set_field_t *dst;
    of_octets_t octets;

    if ((dst = of_action_set_field_new(src->version)) == NULL) {
        return NULL;
    }

    of_action_set_field_field_get(src, &octets);
    of_action_set_field_field_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_action_set_mpls_ttl
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_set_mpls_ttl.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_set_mpls_ttl_t *
of_action_set_mpls_ttl_OF_VERSION_1_2_dup(
    of_action_set_mpls_ttl_t *src)
{
    of_action_set_mpls_ttl_t *dst;
    uint8_t val8;

    if ((dst = of_action_set_mpls_ttl_new(src->version)) == NULL) {
        return NULL;
    }

    of_action_set_mpls_ttl_mpls_ttl_get(src, &val8);
    of_action_set_mpls_ttl_mpls_ttl_set(dst, val8);

    return dst;
}

/**
 * Duplicate an object of type of_action_set_nw_ttl
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_set_nw_ttl.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_set_nw_ttl_t *
of_action_set_nw_ttl_OF_VERSION_1_2_dup(
    of_action_set_nw_ttl_t *src)
{
    of_action_set_nw_ttl_t *dst;
    uint8_t val8;

    if ((dst = of_action_set_nw_ttl_new(src->version)) == NULL) {
        return NULL;
    }

    of_action_set_nw_ttl_nw_ttl_get(src, &val8);
    of_action_set_nw_ttl_nw_ttl_set(dst, val8);

    return dst;
}

/**
 * Duplicate an object of type of_action_set_queue
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_set_queue.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_set_queue_t *
of_action_set_queue_OF_VERSION_1_2_dup(
    of_action_set_queue_t *src)
{
    of_action_set_queue_t *dst;
    uint32_t val32;

    if ((dst = of_action_set_queue_new(src->version)) == NULL) {
        return NULL;
    }

    of_action_set_queue_queue_id_get(src, &val32);
    of_action_set_queue_queue_id_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_interface
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_interface.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_interface_t *
of_bsn_interface_OF_VERSION_1_2_dup(
    of_bsn_interface_t *src)
{
    of_bsn_interface_t *dst;
    of_mac_addr_t mac_addr;
    of_port_name_t port_name;
    of_ipv4_t ipv4;

    if ((dst = of_bsn_interface_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_interface_hw_addr_get(src, &mac_addr);
    of_bsn_interface_hw_addr_set(dst, mac_addr);

    of_bsn_interface_name_get(src, &port_name);
    of_bsn_interface_name_set(dst, port_name);

    of_bsn_interface_ipv4_addr_get(src, &ipv4);
    of_bsn_interface_ipv4_addr_set(dst, ipv4);

    of_bsn_interface_ipv4_netmask_get(src, &ipv4);
    of_bsn_interface_ipv4_netmask_set(dst, ipv4);

    return dst;
}

/**
 * Duplicate a super class object of type of_bsn_vport
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_vport.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_vport_t *
of_bsn_vport_OF_VERSION_1_2_dup(
    of_bsn_vport_t *src)
{

    if (src->header.object_id == OF_BSN_VPORT_Q_IN_Q) {
        return (of_bsn_vport_t *)of_bsn_vport_q_in_q_OF_VERSION_1_2_dup(
            &src->q_in_q);
    }

    return NULL;
}

/**
 * Duplicate an object of type of_bsn_vport_header
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_vport_header.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_vport_header_t *
of_bsn_vport_header_OF_VERSION_1_2_dup(
    of_bsn_vport_header_t *src)
{
    of_bsn_vport_header_t *dst;

    if ((dst = of_bsn_vport_header_new(src->version)) == NULL) {
        return NULL;
    }

    return dst;
}

/**
 * Duplicate an object of type of_bsn_vport_q_in_q
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_vport_q_in_q.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_vport_q_in_q_t *
of_bsn_vport_q_in_q_OF_VERSION_1_2_dup(
    of_bsn_vport_q_in_q_t *src)
{
    of_bsn_vport_q_in_q_t *dst;
    uint32_t val32;
    uint16_t val16;
    of_port_name_t port_name;

    if ((dst = of_bsn_vport_q_in_q_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_vport_q_in_q_port_no_get(src, &val32);
    of_bsn_vport_q_in_q_port_no_set(dst, val32);

    of_bsn_vport_q_in_q_ingress_tpid_get(src, &val16);
    of_bsn_vport_q_in_q_ingress_tpid_set(dst, val16);

    of_bsn_vport_q_in_q_ingress_vlan_id_get(src, &val16);
    of_bsn_vport_q_in_q_ingress_vlan_id_set(dst, val16);

    of_bsn_vport_q_in_q_egress_tpid_get(src, &val16);
    of_bsn_vport_q_in_q_egress_tpid_set(dst, val16);

    of_bsn_vport_q_in_q_egress_vlan_id_get(src, &val16);
    of_bsn_vport_q_in_q_egress_vlan_id_set(dst, val16);

    of_bsn_vport_q_in_q_if_name_get(src, &port_name);
    of_bsn_vport_q_in_q_if_name_set(dst, port_name);

    return dst;
}

/**
 * Duplicate an object of type of_bucket
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bucket.
 *
 * The caller is responsible for deleting the returned value
 */
of_bucket_t *
of_bucket_OF_VERSION_1_2_dup(
    of_bucket_t *src)
{
    of_bucket_t *dst;
    uint16_t val16;
    of_port_no_t port_no;
    uint32_t val32;

    of_list_action_t src_list;
    of_list_action_t *dst_list;

    if ((dst = of_bucket_new(src->version)) == NULL) {
        return NULL;
    }

    of_bucket_weight_get(src, &val16);
    of_bucket_weight_set(dst, val16);

    of_bucket_watch_port_get(src, &port_no);
    of_bucket_watch_port_set(dst, port_no);

    of_bucket_watch_group_get(src, &val32);
    of_bucket_watch_group_set(dst, val32);

    of_bucket_actions_bind(
        src, &src_list);
    dst_list = of_list_action_OF_VERSION_1_2_dup(&src_list);
    if (dst_list == NULL) {
        of_bucket_delete(dst);
        return NULL;
    }
    of_bucket_actions_set(dst, dst_list);
    of_list_action_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_bucket_counter
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bucket_counter.
 *
 * The caller is responsible for deleting the returned value
 */
of_bucket_counter_t *
of_bucket_counter_OF_VERSION_1_2_dup(
    of_bucket_counter_t *src)
{
    of_bucket_counter_t *dst;
    uint64_t val64;

    if ((dst = of_bucket_counter_new(src->version)) == NULL) {
        return NULL;
    }

    of_bucket_counter_packet_count_get(src, &val64);
    of_bucket_counter_packet_count_set(dst, val64);

    of_bucket_counter_byte_count_get(src, &val64);
    of_bucket_counter_byte_count_set(dst, val64);

    return dst;
}

/**
 * Duplicate an object of type of_flow_stats_entry
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_flow_stats_entry.
 *
 * The caller is responsible for deleting the returned value
 */
of_flow_stats_entry_t *
of_flow_stats_entry_OF_VERSION_1_2_dup(
    of_flow_stats_entry_t *src)
{
    of_flow_stats_entry_t *dst;
    uint8_t val8;
    uint32_t val32;
    uint16_t val16;
    uint64_t val64;
    of_match_t match;

    of_list_instruction_t src_list;
    of_list_instruction_t *dst_list;

    if ((dst = of_flow_stats_entry_new(src->version)) == NULL) {
        return NULL;
    }

    of_flow_stats_entry_table_id_get(src, &val8);
    of_flow_stats_entry_table_id_set(dst, val8);

    of_flow_stats_entry_duration_sec_get(src, &val32);
    of_flow_stats_entry_duration_sec_set(dst, val32);

    of_flow_stats_entry_duration_nsec_get(src, &val32);
    of_flow_stats_entry_duration_nsec_set(dst, val32);

    of_flow_stats_entry_priority_get(src, &val16);
    of_flow_stats_entry_priority_set(dst, val16);

    of_flow_stats_entry_idle_timeout_get(src, &val16);
    of_flow_stats_entry_idle_timeout_set(dst, val16);

    of_flow_stats_entry_hard_timeout_get(src, &val16);
    of_flow_stats_entry_hard_timeout_set(dst, val16);

    of_flow_stats_entry_cookie_get(src, &val64);
    of_flow_stats_entry_cookie_set(dst, val64);

    of_flow_stats_entry_packet_count_get(src, &val64);
    of_flow_stats_entry_packet_count_set(dst, val64);

    of_flow_stats_entry_byte_count_get(src, &val64);
    of_flow_stats_entry_byte_count_set(dst, val64);

    of_flow_stats_entry_match_get(src, &match);
    of_flow_stats_entry_match_set(dst, &match);

    of_flow_stats_entry_instructions_bind(
        src, &src_list);
    dst_list = of_list_instruction_OF_VERSION_1_2_dup(&src_list);
    if (dst_list == NULL) {
        of_flow_stats_entry_delete(dst);
        return NULL;
    }
    of_flow_stats_entry_instructions_set(dst, dst_list);
    of_list_instruction_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_group_desc_stats_entry
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_group_desc_stats_entry.
 *
 * The caller is responsible for deleting the returned value
 */
of_group_desc_stats_entry_t *
of_group_desc_stats_entry_OF_VERSION_1_2_dup(
    of_group_desc_stats_entry_t *src)
{
    of_group_desc_stats_entry_t *dst;
    uint8_t val8;
    uint32_t val32;

    of_list_bucket_t src_list;
    of_list_bucket_t *dst_list;

    if ((dst = of_group_desc_stats_entry_new(src->version)) == NULL) {
        return NULL;
    }

    of_group_desc_stats_entry_group_type_get(src, &val8);
    of_group_desc_stats_entry_group_type_set(dst, val8);

    of_group_desc_stats_entry_group_id_get(src, &val32);
    of_group_desc_stats_entry_group_id_set(dst, val32);

    of_group_desc_stats_entry_buckets_bind(
        src, &src_list);
    dst_list = of_list_bucket_OF_VERSION_1_2_dup(&src_list);
    if (dst_list == NULL) {
        of_group_desc_stats_entry_delete(dst);
        return NULL;
    }
    of_group_desc_stats_entry_buckets_set(dst, dst_list);
    of_list_bucket_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_group_stats_entry
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_group_stats_entry.
 *
 * The caller is responsible for deleting the returned value
 */
of_group_stats_entry_t *
of_group_stats_entry_OF_VERSION_1_2_dup(
    of_group_stats_entry_t *src)
{
    of_group_stats_entry_t *dst;
    uint32_t val32;
    uint64_t val64;

    of_list_bucket_counter_t src_list;
    of_list_bucket_counter_t *dst_list;

    if ((dst = of_group_stats_entry_new(src->version)) == NULL) {
        return NULL;
    }

    of_group_stats_entry_group_id_get(src, &val32);
    of_group_stats_entry_group_id_set(dst, val32);

    of_group_stats_entry_ref_count_get(src, &val32);
    of_group_stats_entry_ref_count_set(dst, val32);

    of_group_stats_entry_packet_count_get(src, &val64);
    of_group_stats_entry_packet_count_set(dst, val64);

    of_group_stats_entry_byte_count_get(src, &val64);
    of_group_stats_entry_byte_count_set(dst, val64);

    of_group_stats_entry_bucket_stats_bind(
        src, &src_list);
    dst_list = of_list_bucket_counter_OF_VERSION_1_2_dup(&src_list);
    if (dst_list == NULL) {
        of_group_stats_entry_delete(dst);
        return NULL;
    }
    of_group_stats_entry_bucket_stats_set(dst, dst_list);
    of_list_bucket_counter_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_header
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_header.
 *
 * The caller is responsible for deleting the returned value
 */
of_header_t *
of_header_OF_VERSION_1_2_dup(
    of_header_t *src)
{
    of_header_t *dst;
    uint32_t val32;

    if ((dst = of_header_new(src->version)) == NULL) {
        return NULL;
    }

    of_header_xid_get(src, &val32);
    of_header_xid_set(dst, val32);

    return dst;
}

/**
 * Duplicate a super class object of type of_instruction
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_instruction.
 *
 * The caller is responsible for deleting the returned value
 */
of_instruction_t *
of_instruction_OF_VERSION_1_2_dup(
    of_instruction_t *src)
{

    if (src->header.object_id == OF_INSTRUCTION_CLEAR_ACTIONS) {
        return (of_instruction_t *)of_instruction_clear_actions_OF_VERSION_1_2_dup(
            &src->clear_actions);
    }

    if (src->header.object_id == OF_INSTRUCTION_WRITE_ACTIONS) {
        return (of_instruction_t *)of_instruction_write_actions_OF_VERSION_1_2_dup(
            &src->write_actions);
    }

    if (src->header.object_id == OF_INSTRUCTION_GOTO_TABLE) {
        return (of_instruction_t *)of_instruction_goto_table_OF_VERSION_1_2_dup(
            &src->goto_table);
    }

    if (src->header.object_id == OF_INSTRUCTION_APPLY_ACTIONS) {
        return (of_instruction_t *)of_instruction_apply_actions_OF_VERSION_1_2_dup(
            &src->apply_actions);
    }

    if (src->header.object_id == OF_INSTRUCTION_EXPERIMENTER) {
        return (of_instruction_t *)of_instruction_experimenter_OF_VERSION_1_2_dup(
            &src->experimenter);
    }

    if (src->header.object_id == OF_INSTRUCTION_WRITE_METADATA) {
        return (of_instruction_t *)of_instruction_write_metadata_OF_VERSION_1_2_dup(
            &src->write_metadata);
    }

    return NULL;
}

/**
 * Duplicate an object of type of_instruction_apply_actions
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_instruction_apply_actions.
 *
 * The caller is responsible for deleting the returned value
 */
of_instruction_apply_actions_t *
of_instruction_apply_actions_OF_VERSION_1_2_dup(
    of_instruction_apply_actions_t *src)
{
    of_instruction_apply_actions_t *dst;

    of_list_action_t src_list;
    of_list_action_t *dst_list;

    if ((dst = of_instruction_apply_actions_new(src->version)) == NULL) {
        return NULL;
    }

    of_instruction_apply_actions_actions_bind(
        src, &src_list);
    dst_list = of_list_action_OF_VERSION_1_2_dup(&src_list);
    if (dst_list == NULL) {
        of_instruction_apply_actions_delete(dst);
        return NULL;
    }
    of_instruction_apply_actions_actions_set(dst, dst_list);
    of_list_action_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_instruction_clear_actions
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_instruction_clear_actions.
 *
 * The caller is responsible for deleting the returned value
 */
of_instruction_clear_actions_t *
of_instruction_clear_actions_OF_VERSION_1_2_dup(
    of_instruction_clear_actions_t *src)
{
    of_instruction_clear_actions_t *dst;

    if ((dst = of_instruction_clear_actions_new(src->version)) == NULL) {
        return NULL;
    }

    return dst;
}

/**
 * Duplicate an object of type of_instruction_experimenter
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_instruction_experimenter.
 *
 * The caller is responsible for deleting the returned value
 */
of_instruction_experimenter_t *
of_instruction_experimenter_OF_VERSION_1_2_dup(
    of_instruction_experimenter_t *src)
{
    of_instruction_experimenter_t *dst;
    uint32_t val32;
    of_octets_t octets;

    if ((dst = of_instruction_experimenter_new(src->version)) == NULL) {
        return NULL;
    }

    of_instruction_experimenter_experimenter_get(src, &val32);
    of_instruction_experimenter_experimenter_set(dst, val32);

    of_instruction_experimenter_data_get(src, &octets);
    of_instruction_experimenter_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_instruction_goto_table
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_instruction_goto_table.
 *
 * The caller is responsible for deleting the returned value
 */
of_instruction_goto_table_t *
of_instruction_goto_table_OF_VERSION_1_2_dup(
    of_instruction_goto_table_t *src)
{
    of_instruction_goto_table_t *dst;
    uint8_t val8;

    if ((dst = of_instruction_goto_table_new(src->version)) == NULL) {
        return NULL;
    }

    of_instruction_goto_table_table_id_get(src, &val8);
    of_instruction_goto_table_table_id_set(dst, val8);

    return dst;
}

/**
 * Duplicate an object of type of_instruction_header
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_instruction_header.
 *
 * The caller is responsible for deleting the returned value
 */
of_instruction_header_t *
of_instruction_header_OF_VERSION_1_2_dup(
    of_instruction_header_t *src)
{
    of_instruction_header_t *dst;

    if ((dst = of_instruction_header_new(src->version)) == NULL) {
        return NULL;
    }

    return dst;
}

/**
 * Duplicate an object of type of_instruction_write_actions
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_instruction_write_actions.
 *
 * The caller is responsible for deleting the returned value
 */
of_instruction_write_actions_t *
of_instruction_write_actions_OF_VERSION_1_2_dup(
    of_instruction_write_actions_t *src)
{
    of_instruction_write_actions_t *dst;

    of_list_action_t src_list;
    of_list_action_t *dst_list;

    if ((dst = of_instruction_write_actions_new(src->version)) == NULL) {
        return NULL;
    }

    of_instruction_write_actions_actions_bind(
        src, &src_list);
    dst_list = of_list_action_OF_VERSION_1_2_dup(&src_list);
    if (dst_list == NULL) {
        of_instruction_write_actions_delete(dst);
        return NULL;
    }
    of_instruction_write_actions_actions_set(dst, dst_list);
    of_list_action_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_instruction_write_metadata
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_instruction_write_metadata.
 *
 * The caller is responsible for deleting the returned value
 */
of_instruction_write_metadata_t *
of_instruction_write_metadata_OF_VERSION_1_2_dup(
    of_instruction_write_metadata_t *src)
{
    of_instruction_write_metadata_t *dst;
    uint64_t val64;

    if ((dst = of_instruction_write_metadata_new(src->version)) == NULL) {
        return NULL;
    }

    of_instruction_write_metadata_metadata_get(src, &val64);
    of_instruction_write_metadata_metadata_set(dst, val64);

    of_instruction_write_metadata_metadata_mask_get(src, &val64);
    of_instruction_write_metadata_metadata_mask_set(dst, val64);

    return dst;
}

/**
 * Duplicate an object of type of_match_v3
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_match_v3.
 *
 * The caller is responsible for deleting the returned value
 */
of_match_v3_t *
of_match_v3_OF_VERSION_1_2_dup(
    of_match_v3_t *src)
{
    of_match_v3_t *dst;

    of_list_oxm_t src_list;
    of_list_oxm_t *dst_list;

    if ((dst = of_match_v3_new(src->version)) == NULL) {
        return NULL;
    }

    of_match_v3_oxm_list_bind(
        src, &src_list);
    dst_list = of_list_oxm_OF_VERSION_1_2_dup(&src_list);
    if (dst_list == NULL) {
        of_match_v3_delete(dst);
        return NULL;
    }
    of_match_v3_oxm_list_set(dst, dst_list);
    of_list_oxm_delete(dst_list);

    return dst;
}

/**
 * Duplicate a super class object of type of_oxm
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_t *
of_oxm_OF_VERSION_1_2_dup(
    of_oxm_t *src)
{

    if (src->header.object_id == OF_OXM_MPLS_TC_MASKED) {
        return (of_oxm_t *)of_oxm_mpls_tc_masked_OF_VERSION_1_2_dup(
            &src->mpls_tc_masked);
    }

    if (src->header.object_id == OF_OXM_ARP_SHA) {
        return (of_oxm_t *)of_oxm_arp_sha_OF_VERSION_1_2_dup(
            &src->arp_sha);
    }

    if (src->header.object_id == OF_OXM_ETH_SRC_MASKED) {
        return (of_oxm_t *)of_oxm_eth_src_masked_OF_VERSION_1_2_dup(
            &src->eth_src_masked);
    }

    if (src->header.object_id == OF_OXM_ETH_DST) {
        return (of_oxm_t *)of_oxm_eth_dst_OF_VERSION_1_2_dup(
            &src->eth_dst);
    }

    if (src->header.object_id == OF_OXM_VLAN_PCP_MASKED) {
        return (of_oxm_t *)of_oxm_vlan_pcp_masked_OF_VERSION_1_2_dup(
            &src->vlan_pcp_masked);
    }

    if (src->header.object_id == OF_OXM_ARP_OP) {
        return (of_oxm_t *)of_oxm_arp_op_OF_VERSION_1_2_dup(
            &src->arp_op);
    }

    if (src->header.object_id == OF_OXM_ETH_TYPE) {
        return (of_oxm_t *)of_oxm_eth_type_OF_VERSION_1_2_dup(
            &src->eth_type);
    }

    if (src->header.object_id == OF_OXM_BSN_IN_PORTS_128_MASKED) {
        return (of_oxm_t *)of_oxm_bsn_in_ports_128_masked_OF_VERSION_1_2_dup(
            &src->bsn_in_ports_128_masked);
    }

    if (src->header.object_id == OF_OXM_ARP_SPA) {
        return (of_oxm_t *)of_oxm_arp_spa_OF_VERSION_1_2_dup(
            &src->arp_spa);
    }

    if (src->header.object_id == OF_OXM_ICMPV4_TYPE_MASKED) {
        return (of_oxm_t *)of_oxm_icmpv4_type_masked_OF_VERSION_1_2_dup(
            &src->icmpv4_type_masked);
    }

    if (src->header.object_id == OF_OXM_ARP_SHA_MASKED) {
        return (of_oxm_t *)of_oxm_arp_sha_masked_OF_VERSION_1_2_dup(
            &src->arp_sha_masked);
    }

    if (src->header.object_id == OF_OXM_UDP_DST) {
        return (of_oxm_t *)of_oxm_udp_dst_OF_VERSION_1_2_dup(
            &src->udp_dst);
    }

    if (src->header.object_id == OF_OXM_BSN_VRF_MASKED) {
        return (of_oxm_t *)of_oxm_bsn_vrf_masked_OF_VERSION_1_2_dup(
            &src->bsn_vrf_masked);
    }

    if (src->header.object_id == OF_OXM_IPV6_ND_TARGET) {
        return (of_oxm_t *)of_oxm_ipv6_nd_target_OF_VERSION_1_2_dup(
            &src->ipv6_nd_target);
    }

    if (src->header.object_id == OF_OXM_ETH_TYPE_MASKED) {
        return (of_oxm_t *)of_oxm_eth_type_masked_OF_VERSION_1_2_dup(
            &src->eth_type_masked);
    }

    if (src->header.object_id == OF_OXM_BSN_GLOBAL_VRF_ALLOWED_MASKED) {
        return (of_oxm_t *)of_oxm_bsn_global_vrf_allowed_masked_OF_VERSION_1_2_dup(
            &src->bsn_global_vrf_allowed_masked);
    }

    if (src->header.object_id == OF_OXM_ICMPV4_TYPE) {
        return (of_oxm_t *)of_oxm_icmpv4_type_OF_VERSION_1_2_dup(
            &src->icmpv4_type);
    }

    if (src->header.object_id == OF_OXM_UDP_DST_MASKED) {
        return (of_oxm_t *)of_oxm_udp_dst_masked_OF_VERSION_1_2_dup(
            &src->udp_dst_masked);
    }

    if (src->header.object_id == OF_OXM_TCP_DST) {
        return (of_oxm_t *)of_oxm_tcp_dst_OF_VERSION_1_2_dup(
            &src->tcp_dst);
    }

    if (src->header.object_id == OF_OXM_IP_PROTO) {
        return (of_oxm_t *)of_oxm_ip_proto_OF_VERSION_1_2_dup(
            &src->ip_proto);
    }

    if (src->header.object_id == OF_OXM_IP_DSCP) {
        return (of_oxm_t *)of_oxm_ip_dscp_OF_VERSION_1_2_dup(
            &src->ip_dscp);
    }

    if (src->header.object_id == OF_OXM_ARP_SPA_MASKED) {
        return (of_oxm_t *)of_oxm_arp_spa_masked_OF_VERSION_1_2_dup(
            &src->arp_spa_masked);
    }

    if (src->header.object_id == OF_OXM_IPV6_FLABEL) {
        return (of_oxm_t *)of_oxm_ipv6_flabel_OF_VERSION_1_2_dup(
            &src->ipv6_flabel);
    }

    if (src->header.object_id == OF_OXM_IPV6_ND_TLL_MASKED) {
        return (of_oxm_t *)of_oxm_ipv6_nd_tll_masked_OF_VERSION_1_2_dup(
            &src->ipv6_nd_tll_masked);
    }

    if (src->header.object_id == OF_OXM_ARP_TPA) {
        return (of_oxm_t *)of_oxm_arp_tpa_OF_VERSION_1_2_dup(
            &src->arp_tpa);
    }

    if (src->header.object_id == OF_OXM_SCTP_SRC) {
        return (of_oxm_t *)of_oxm_sctp_src_OF_VERSION_1_2_dup(
            &src->sctp_src);
    }

    if (src->header.object_id == OF_OXM_IPV6_SRC) {
        return (of_oxm_t *)of_oxm_ipv6_src_OF_VERSION_1_2_dup(
            &src->ipv6_src);
    }

    if (src->header.object_id == OF_OXM_METADATA_MASKED) {
        return (of_oxm_t *)of_oxm_metadata_masked_OF_VERSION_1_2_dup(
            &src->metadata_masked);
    }

    if (src->header.object_id == OF_OXM_IPV6_ND_SLL) {
        return (of_oxm_t *)of_oxm_ipv6_nd_sll_OF_VERSION_1_2_dup(
            &src->ipv6_nd_sll);
    }

    if (src->header.object_id == OF_OXM_VLAN_VID) {
        return (of_oxm_t *)of_oxm_vlan_vid_OF_VERSION_1_2_dup(
            &src->vlan_vid);
    }

    if (src->header.object_id == OF_OXM_ARP_THA) {
        return (of_oxm_t *)of_oxm_arp_tha_OF_VERSION_1_2_dup(
            &src->arp_tha);
    }

    if (src->header.object_id == OF_OXM_METADATA) {
        return (of_oxm_t *)of_oxm_metadata_OF_VERSION_1_2_dup(
            &src->metadata);
    }

    if (src->header.object_id == OF_OXM_SCTP_DST) {
        return (of_oxm_t *)of_oxm_sctp_dst_OF_VERSION_1_2_dup(
            &src->sctp_dst);
    }

    if (src->header.object_id == OF_OXM_BSN_L3_SRC_CLASS_ID) {
        return (of_oxm_t *)of_oxm_bsn_l3_src_class_id_OF_VERSION_1_2_dup(
            &src->bsn_l3_src_class_id);
    }

    if (src->header.object_id == OF_OXM_ETH_DST_MASKED) {
        return (of_oxm_t *)of_oxm_eth_dst_masked_OF_VERSION_1_2_dup(
            &src->eth_dst_masked);
    }

    if (src->header.object_id == OF_OXM_IN_PORT_MASKED) {
        return (of_oxm_t *)of_oxm_in_port_masked_OF_VERSION_1_2_dup(
            &src->in_port_masked);
    }

    if (src->header.object_id == OF_OXM_IP_ECN) {
        return (of_oxm_t *)of_oxm_ip_ecn_OF_VERSION_1_2_dup(
            &src->ip_ecn);
    }

    if (src->header.object_id == OF_OXM_ICMPV4_CODE_MASKED) {
        return (of_oxm_t *)of_oxm_icmpv4_code_masked_OF_VERSION_1_2_dup(
            &src->icmpv4_code_masked);
    }

    if (src->header.object_id == OF_OXM_TCP_DST_MASKED) {
        return (of_oxm_t *)of_oxm_tcp_dst_masked_OF_VERSION_1_2_dup(
            &src->tcp_dst_masked);
    }

    if (src->header.object_id == OF_OXM_TCP_SRC_MASKED) {
        return (of_oxm_t *)of_oxm_tcp_src_masked_OF_VERSION_1_2_dup(
            &src->tcp_src_masked);
    }

    if (src->header.object_id == OF_OXM_IPV4_DST) {
        return (of_oxm_t *)of_oxm_ipv4_dst_OF_VERSION_1_2_dup(
            &src->ipv4_dst);
    }

    if (src->header.object_id == OF_OXM_IPV4_DST_MASKED) {
        return (of_oxm_t *)of_oxm_ipv4_dst_masked_OF_VERSION_1_2_dup(
            &src->ipv4_dst_masked);
    }

    if (src->header.object_id == OF_OXM_IPV6_ND_TLL) {
        return (of_oxm_t *)of_oxm_ipv6_nd_tll_OF_VERSION_1_2_dup(
            &src->ipv6_nd_tll);
    }

    if (src->header.object_id == OF_OXM_IP_PROTO_MASKED) {
        return (of_oxm_t *)of_oxm_ip_proto_masked_OF_VERSION_1_2_dup(
            &src->ip_proto_masked);
    }

    if (src->header.object_id == OF_OXM_IN_PHY_PORT_MASKED) {
        return (of_oxm_t *)of_oxm_in_phy_port_masked_OF_VERSION_1_2_dup(
            &src->in_phy_port_masked);
    }

    if (src->header.object_id == OF_OXM_BSN_LAG_ID) {
        return (of_oxm_t *)of_oxm_bsn_lag_id_OF_VERSION_1_2_dup(
            &src->bsn_lag_id);
    }

    if (src->header.object_id == OF_OXM_IPV6_DST_MASKED) {
        return (of_oxm_t *)of_oxm_ipv6_dst_masked_OF_VERSION_1_2_dup(
            &src->ipv6_dst_masked);
    }

    if (src->header.object_id == OF_OXM_VLAN_PCP) {
        return (of_oxm_t *)of_oxm_vlan_pcp_OF_VERSION_1_2_dup(
            &src->vlan_pcp);
    }

    if (src->header.object_id == OF_OXM_IPV4_SRC) {
        return (of_oxm_t *)of_oxm_ipv4_src_OF_VERSION_1_2_dup(
            &src->ipv4_src);
    }

    if (src->header.object_id == OF_OXM_IPV6_DST) {
        return (of_oxm_t *)of_oxm_ipv6_dst_OF_VERSION_1_2_dup(
            &src->ipv6_dst);
    }

    if (src->header.object_id == OF_OXM_IPV4_SRC_MASKED) {
        return (of_oxm_t *)of_oxm_ipv4_src_masked_OF_VERSION_1_2_dup(
            &src->ipv4_src_masked);
    }

    if (src->header.object_id == OF_OXM_ARP_OP_MASKED) {
        return (of_oxm_t *)of_oxm_arp_op_masked_OF_VERSION_1_2_dup(
            &src->arp_op_masked);
    }

    if (src->header.object_id == OF_OXM_ETH_SRC) {
        return (of_oxm_t *)of_oxm_eth_src_OF_VERSION_1_2_dup(
            &src->eth_src);
    }

    if (src->header.object_id == OF_OXM_ICMPV6_CODE) {
        return (of_oxm_t *)of_oxm_icmpv6_code_OF_VERSION_1_2_dup(
            &src->icmpv6_code);
    }

    if (src->header.object_id == OF_OXM_ICMPV6_CODE_MASKED) {
        return (of_oxm_t *)of_oxm_icmpv6_code_masked_OF_VERSION_1_2_dup(
            &src->icmpv6_code_masked);
    }

    if (src->header.object_id == OF_OXM_UDP_SRC_MASKED) {
        return (of_oxm_t *)of_oxm_udp_src_masked_OF_VERSION_1_2_dup(
            &src->udp_src_masked);
    }

    if (src->header.object_id == OF_OXM_IP_ECN_MASKED) {
        return (of_oxm_t *)of_oxm_ip_ecn_masked_OF_VERSION_1_2_dup(
            &src->ip_ecn_masked);
    }

    if (src->header.object_id == OF_OXM_UDP_SRC) {
        return (of_oxm_t *)of_oxm_udp_src_OF_VERSION_1_2_dup(
            &src->udp_src);
    }

    if (src->header.object_id == OF_OXM_VLAN_VID_MASKED) {
        return (of_oxm_t *)of_oxm_vlan_vid_masked_OF_VERSION_1_2_dup(
            &src->vlan_vid_masked);
    }

    if (src->header.object_id == OF_OXM_ARP_THA_MASKED) {
        return (of_oxm_t *)of_oxm_arp_tha_masked_OF_VERSION_1_2_dup(
            &src->arp_tha_masked);
    }

    if (src->header.object_id == OF_OXM_SCTP_SRC_MASKED) {
        return (of_oxm_t *)of_oxm_sctp_src_masked_OF_VERSION_1_2_dup(
            &src->sctp_src_masked);
    }

    if (src->header.object_id == OF_OXM_IN_PORT) {
        return (of_oxm_t *)of_oxm_in_port_OF_VERSION_1_2_dup(
            &src->in_port);
    }

    if (src->header.object_id == OF_OXM_BSN_L3_INTERFACE_CLASS_ID) {
        return (of_oxm_t *)of_oxm_bsn_l3_interface_class_id_OF_VERSION_1_2_dup(
            &src->bsn_l3_interface_class_id);
    }

    if (src->header.object_id == OF_OXM_IPV6_ND_SLL_MASKED) {
        return (of_oxm_t *)of_oxm_ipv6_nd_sll_masked_OF_VERSION_1_2_dup(
            &src->ipv6_nd_sll_masked);
    }

    if (src->header.object_id == OF_OXM_TCP_SRC) {
        return (of_oxm_t *)of_oxm_tcp_src_OF_VERSION_1_2_dup(
            &src->tcp_src);
    }

    if (src->header.object_id == OF_OXM_IPV6_ND_TARGET_MASKED) {
        return (of_oxm_t *)of_oxm_ipv6_nd_target_masked_OF_VERSION_1_2_dup(
            &src->ipv6_nd_target_masked);
    }

    if (src->header.object_id == OF_OXM_ICMPV6_TYPE_MASKED) {
        return (of_oxm_t *)of_oxm_icmpv6_type_masked_OF_VERSION_1_2_dup(
            &src->icmpv6_type_masked);
    }

    if (src->header.object_id == OF_OXM_MPLS_LABEL) {
        return (of_oxm_t *)of_oxm_mpls_label_OF_VERSION_1_2_dup(
            &src->mpls_label);
    }

    if (src->header.object_id == OF_OXM_BSN_IN_PORTS_128) {
        return (of_oxm_t *)of_oxm_bsn_in_ports_128_OF_VERSION_1_2_dup(
            &src->bsn_in_ports_128);
    }

    if (src->header.object_id == OF_OXM_BSN_L3_SRC_CLASS_ID_MASKED) {
        return (of_oxm_t *)of_oxm_bsn_l3_src_class_id_masked_OF_VERSION_1_2_dup(
            &src->bsn_l3_src_class_id_masked);
    }

    if (src->header.object_id == OF_OXM_IPV6_FLABEL_MASKED) {
        return (of_oxm_t *)of_oxm_ipv6_flabel_masked_OF_VERSION_1_2_dup(
            &src->ipv6_flabel_masked);
    }

    if (src->header.object_id == OF_OXM_BSN_LAG_ID_MASKED) {
        return (of_oxm_t *)of_oxm_bsn_lag_id_masked_OF_VERSION_1_2_dup(
            &src->bsn_lag_id_masked);
    }

    if (src->header.object_id == OF_OXM_IP_DSCP_MASKED) {
        return (of_oxm_t *)of_oxm_ip_dscp_masked_OF_VERSION_1_2_dup(
            &src->ip_dscp_masked);
    }

    if (src->header.object_id == OF_OXM_ICMPV6_TYPE) {
        return (of_oxm_t *)of_oxm_icmpv6_type_OF_VERSION_1_2_dup(
            &src->icmpv6_type);
    }

    if (src->header.object_id == OF_OXM_BSN_L3_INTERFACE_CLASS_ID_MASKED) {
        return (of_oxm_t *)of_oxm_bsn_l3_interface_class_id_masked_OF_VERSION_1_2_dup(
            &src->bsn_l3_interface_class_id_masked);
    }

    if (src->header.object_id == OF_OXM_MPLS_TC) {
        return (of_oxm_t *)of_oxm_mpls_tc_OF_VERSION_1_2_dup(
            &src->mpls_tc);
    }

    if (src->header.object_id == OF_OXM_BSN_L3_DST_CLASS_ID_MASKED) {
        return (of_oxm_t *)of_oxm_bsn_l3_dst_class_id_masked_OF_VERSION_1_2_dup(
            &src->bsn_l3_dst_class_id_masked);
    }

    if (src->header.object_id == OF_OXM_ARP_TPA_MASKED) {
        return (of_oxm_t *)of_oxm_arp_tpa_masked_OF_VERSION_1_2_dup(
            &src->arp_tpa_masked);
    }

    if (src->header.object_id == OF_OXM_SCTP_DST_MASKED) {
        return (of_oxm_t *)of_oxm_sctp_dst_masked_OF_VERSION_1_2_dup(
            &src->sctp_dst_masked);
    }

    if (src->header.object_id == OF_OXM_ICMPV4_CODE) {
        return (of_oxm_t *)of_oxm_icmpv4_code_OF_VERSION_1_2_dup(
            &src->icmpv4_code);
    }

    if (src->header.object_id == OF_OXM_BSN_VRF) {
        return (of_oxm_t *)of_oxm_bsn_vrf_OF_VERSION_1_2_dup(
            &src->bsn_vrf);
    }

    if (src->header.object_id == OF_OXM_IPV6_SRC_MASKED) {
        return (of_oxm_t *)of_oxm_ipv6_src_masked_OF_VERSION_1_2_dup(
            &src->ipv6_src_masked);
    }

    if (src->header.object_id == OF_OXM_BSN_GLOBAL_VRF_ALLOWED) {
        return (of_oxm_t *)of_oxm_bsn_global_vrf_allowed_OF_VERSION_1_2_dup(
            &src->bsn_global_vrf_allowed);
    }

    if (src->header.object_id == OF_OXM_IN_PHY_PORT) {
        return (of_oxm_t *)of_oxm_in_phy_port_OF_VERSION_1_2_dup(
            &src->in_phy_port);
    }

    if (src->header.object_id == OF_OXM_MPLS_LABEL_MASKED) {
        return (of_oxm_t *)of_oxm_mpls_label_masked_OF_VERSION_1_2_dup(
            &src->mpls_label_masked);
    }

    if (src->header.object_id == OF_OXM_BSN_L3_DST_CLASS_ID) {
        return (of_oxm_t *)of_oxm_bsn_l3_dst_class_id_OF_VERSION_1_2_dup(
            &src->bsn_l3_dst_class_id);
    }

    return NULL;
}

/**
 * Duplicate an object of type of_oxm_arp_op
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_arp_op.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_arp_op_t *
of_oxm_arp_op_OF_VERSION_1_2_dup(
    of_oxm_arp_op_t *src)
{
    of_oxm_arp_op_t *dst;
    uint16_t val16;

    if ((dst = of_oxm_arp_op_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_arp_op_value_get(src, &val16);
    of_oxm_arp_op_value_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_arp_op_masked
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_arp_op_masked.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_arp_op_masked_t *
of_oxm_arp_op_masked_OF_VERSION_1_2_dup(
    of_oxm_arp_op_masked_t *src)
{
    of_oxm_arp_op_masked_t *dst;
    uint16_t val16;

    if ((dst = of_oxm_arp_op_masked_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_arp_op_masked_value_get(src, &val16);
    of_oxm_arp_op_masked_value_set(dst, val16);

    of_oxm_arp_op_masked_value_mask_get(src, &val16);
    of_oxm_arp_op_masked_value_mask_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_arp_sha
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_arp_sha.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_arp_sha_t *
of_oxm_arp_sha_OF_VERSION_1_2_dup(
    of_oxm_arp_sha_t *src)
{
    of_oxm_arp_sha_t *dst;
    of_mac_addr_t mac_addr;

    if ((dst = of_oxm_arp_sha_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_arp_sha_value_get(src, &mac_addr);
    of_oxm_arp_sha_value_set(dst, mac_addr);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_arp_sha_masked
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_arp_sha_masked.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_arp_sha_masked_t *
of_oxm_arp_sha_masked_OF_VERSION_1_2_dup(
    of_oxm_arp_sha_masked_t *src)
{
    of_oxm_arp_sha_masked_t *dst;
    of_mac_addr_t mac_addr;

    if ((dst = of_oxm_arp_sha_masked_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_arp_sha_masked_value_get(src, &mac_addr);
    of_oxm_arp_sha_masked_value_set(dst, mac_addr);

    of_oxm_arp_sha_masked_value_mask_get(src, &mac_addr);
    of_oxm_arp_sha_masked_value_mask_set(dst, mac_addr);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_arp_spa
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_arp_spa.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_arp_spa_t *
of_oxm_arp_spa_OF_VERSION_1_2_dup(
    of_oxm_arp_spa_t *src)
{
    of_oxm_arp_spa_t *dst;
    uint32_t val32;

    if ((dst = of_oxm_arp_spa_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_arp_spa_value_get(src, &val32);
    of_oxm_arp_spa_value_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_arp_spa_masked
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_arp_spa_masked.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_arp_spa_masked_t *
of_oxm_arp_spa_masked_OF_VERSION_1_2_dup(
    of_oxm_arp_spa_masked_t *src)
{
    of_oxm_arp_spa_masked_t *dst;
    uint32_t val32;

    if ((dst = of_oxm_arp_spa_masked_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_arp_spa_masked_value_get(src, &val32);
    of_oxm_arp_spa_masked_value_set(dst, val32);

    of_oxm_arp_spa_masked_value_mask_get(src, &val32);
    of_oxm_arp_spa_masked_value_mask_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_arp_tha
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_arp_tha.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_arp_tha_t *
of_oxm_arp_tha_OF_VERSION_1_2_dup(
    of_oxm_arp_tha_t *src)
{
    of_oxm_arp_tha_t *dst;
    of_mac_addr_t mac_addr;

    if ((dst = of_oxm_arp_tha_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_arp_tha_value_get(src, &mac_addr);
    of_oxm_arp_tha_value_set(dst, mac_addr);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_arp_tha_masked
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_arp_tha_masked.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_arp_tha_masked_t *
of_oxm_arp_tha_masked_OF_VERSION_1_2_dup(
    of_oxm_arp_tha_masked_t *src)
{
    of_oxm_arp_tha_masked_t *dst;
    of_mac_addr_t mac_addr;

    if ((dst = of_oxm_arp_tha_masked_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_arp_tha_masked_value_get(src, &mac_addr);
    of_oxm_arp_tha_masked_value_set(dst, mac_addr);

    of_oxm_arp_tha_masked_value_mask_get(src, &mac_addr);
    of_oxm_arp_tha_masked_value_mask_set(dst, mac_addr);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_arp_tpa
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_arp_tpa.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_arp_tpa_t *
of_oxm_arp_tpa_OF_VERSION_1_2_dup(
    of_oxm_arp_tpa_t *src)
{
    of_oxm_arp_tpa_t *dst;
    uint32_t val32;

    if ((dst = of_oxm_arp_tpa_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_arp_tpa_value_get(src, &val32);
    of_oxm_arp_tpa_value_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_arp_tpa_masked
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_arp_tpa_masked.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_arp_tpa_masked_t *
of_oxm_arp_tpa_masked_OF_VERSION_1_2_dup(
    of_oxm_arp_tpa_masked_t *src)
{
    of_oxm_arp_tpa_masked_t *dst;
    uint32_t val32;

    if ((dst = of_oxm_arp_tpa_masked_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_arp_tpa_masked_value_get(src, &val32);
    of_oxm_arp_tpa_masked_value_set(dst, val32);

    of_oxm_arp_tpa_masked_value_mask_get(src, &val32);
    of_oxm_arp_tpa_masked_value_mask_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_bsn_global_vrf_allowed
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_bsn_global_vrf_allowed.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_bsn_global_vrf_allowed_t *
of_oxm_bsn_global_vrf_allowed_OF_VERSION_1_2_dup(
    of_oxm_bsn_global_vrf_allowed_t *src)
{
    of_oxm_bsn_global_vrf_allowed_t *dst;
    uint8_t val8;

    if ((dst = of_oxm_bsn_global_vrf_allowed_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_bsn_global_vrf_allowed_value_get(src, &val8);
    of_oxm_bsn_global_vrf_allowed_value_set(dst, val8);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_bsn_global_vrf_allowed_masked
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_bsn_global_vrf_allowed_masked.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_bsn_global_vrf_allowed_masked_t *
of_oxm_bsn_global_vrf_allowed_masked_OF_VERSION_1_2_dup(
    of_oxm_bsn_global_vrf_allowed_masked_t *src)
{
    of_oxm_bsn_global_vrf_allowed_masked_t *dst;
    uint8_t val8;

    if ((dst = of_oxm_bsn_global_vrf_allowed_masked_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_bsn_global_vrf_allowed_masked_value_get(src, &val8);
    of_oxm_bsn_global_vrf_allowed_masked_value_set(dst, val8);

    of_oxm_bsn_global_vrf_allowed_masked_value_mask_get(src, &val8);
    of_oxm_bsn_global_vrf_allowed_masked_value_mask_set(dst, val8);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_bsn_in_ports_128
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_bsn_in_ports_128.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_bsn_in_ports_128_t *
of_oxm_bsn_in_ports_128_OF_VERSION_1_2_dup(
    of_oxm_bsn_in_ports_128_t *src)
{
    of_oxm_bsn_in_ports_128_t *dst;
    of_bitmap_128_t bitmap_128;

    if ((dst = of_oxm_bsn_in_ports_128_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_bsn_in_ports_128_value_get(src, &bitmap_128);
    of_oxm_bsn_in_ports_128_value_set(dst, bitmap_128);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_bsn_in_ports_128_masked
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_bsn_in_ports_128_masked.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_bsn_in_ports_128_masked_t *
of_oxm_bsn_in_ports_128_masked_OF_VERSION_1_2_dup(
    of_oxm_bsn_in_ports_128_masked_t *src)
{
    of_oxm_bsn_in_ports_128_masked_t *dst;
    of_bitmap_128_t bitmap_128;

    if ((dst = of_oxm_bsn_in_ports_128_masked_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_bsn_in_ports_128_masked_value_get(src, &bitmap_128);
    of_oxm_bsn_in_ports_128_masked_value_set(dst, bitmap_128);

    of_oxm_bsn_in_ports_128_masked_value_mask_get(src, &bitmap_128);
    of_oxm_bsn_in_ports_128_masked_value_mask_set(dst, bitmap_128);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_bsn_l3_dst_class_id
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_bsn_l3_dst_class_id.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_bsn_l3_dst_class_id_t *
of_oxm_bsn_l3_dst_class_id_OF_VERSION_1_2_dup(
    of_oxm_bsn_l3_dst_class_id_t *src)
{
    of_oxm_bsn_l3_dst_class_id_t *dst;
    uint32_t val32;

    if ((dst = of_oxm_bsn_l3_dst_class_id_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_bsn_l3_dst_class_id_value_get(src, &val32);
    of_oxm_bsn_l3_dst_class_id_value_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_bsn_l3_dst_class_id_masked
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_bsn_l3_dst_class_id_masked.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_bsn_l3_dst_class_id_masked_t *
of_oxm_bsn_l3_dst_class_id_masked_OF_VERSION_1_2_dup(
    of_oxm_bsn_l3_dst_class_id_masked_t *src)
{
    of_oxm_bsn_l3_dst_class_id_masked_t *dst;
    uint32_t val32;

    if ((dst = of_oxm_bsn_l3_dst_class_id_masked_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_bsn_l3_dst_class_id_masked_value_get(src, &val32);
    of_oxm_bsn_l3_dst_class_id_masked_value_set(dst, val32);

    of_oxm_bsn_l3_dst_class_id_masked_value_mask_get(src, &val32);
    of_oxm_bsn_l3_dst_class_id_masked_value_mask_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_bsn_l3_interface_class_id
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_bsn_l3_interface_class_id.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_bsn_l3_interface_class_id_t *
of_oxm_bsn_l3_interface_class_id_OF_VERSION_1_2_dup(
    of_oxm_bsn_l3_interface_class_id_t *src)
{
    of_oxm_bsn_l3_interface_class_id_t *dst;
    uint32_t val32;

    if ((dst = of_oxm_bsn_l3_interface_class_id_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_bsn_l3_interface_class_id_value_get(src, &val32);
    of_oxm_bsn_l3_interface_class_id_value_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_bsn_l3_interface_class_id_masked
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_bsn_l3_interface_class_id_masked.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_bsn_l3_interface_class_id_masked_t *
of_oxm_bsn_l3_interface_class_id_masked_OF_VERSION_1_2_dup(
    of_oxm_bsn_l3_interface_class_id_masked_t *src)
{
    of_oxm_bsn_l3_interface_class_id_masked_t *dst;
    uint32_t val32;

    if ((dst = of_oxm_bsn_l3_interface_class_id_masked_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_bsn_l3_interface_class_id_masked_value_get(src, &val32);
    of_oxm_bsn_l3_interface_class_id_masked_value_set(dst, val32);

    of_oxm_bsn_l3_interface_class_id_masked_value_mask_get(src, &val32);
    of_oxm_bsn_l3_interface_class_id_masked_value_mask_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_bsn_l3_src_class_id
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_bsn_l3_src_class_id.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_bsn_l3_src_class_id_t *
of_oxm_bsn_l3_src_class_id_OF_VERSION_1_2_dup(
    of_oxm_bsn_l3_src_class_id_t *src)
{
    of_oxm_bsn_l3_src_class_id_t *dst;
    uint32_t val32;

    if ((dst = of_oxm_bsn_l3_src_class_id_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_bsn_l3_src_class_id_value_get(src, &val32);
    of_oxm_bsn_l3_src_class_id_value_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_bsn_l3_src_class_id_masked
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_bsn_l3_src_class_id_masked.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_bsn_l3_src_class_id_masked_t *
of_oxm_bsn_l3_src_class_id_masked_OF_VERSION_1_2_dup(
    of_oxm_bsn_l3_src_class_id_masked_t *src)
{
    of_oxm_bsn_l3_src_class_id_masked_t *dst;
    uint32_t val32;

    if ((dst = of_oxm_bsn_l3_src_class_id_masked_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_bsn_l3_src_class_id_masked_value_get(src, &val32);
    of_oxm_bsn_l3_src_class_id_masked_value_set(dst, val32);

    of_oxm_bsn_l3_src_class_id_masked_value_mask_get(src, &val32);
    of_oxm_bsn_l3_src_class_id_masked_value_mask_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_bsn_lag_id
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_bsn_lag_id.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_bsn_lag_id_t *
of_oxm_bsn_lag_id_OF_VERSION_1_2_dup(
    of_oxm_bsn_lag_id_t *src)
{
    of_oxm_bsn_lag_id_t *dst;
    uint32_t val32;

    if ((dst = of_oxm_bsn_lag_id_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_bsn_lag_id_value_get(src, &val32);
    of_oxm_bsn_lag_id_value_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_bsn_lag_id_masked
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_bsn_lag_id_masked.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_bsn_lag_id_masked_t *
of_oxm_bsn_lag_id_masked_OF_VERSION_1_2_dup(
    of_oxm_bsn_lag_id_masked_t *src)
{
    of_oxm_bsn_lag_id_masked_t *dst;
    uint32_t val32;

    if ((dst = of_oxm_bsn_lag_id_masked_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_bsn_lag_id_masked_value_get(src, &val32);
    of_oxm_bsn_lag_id_masked_value_set(dst, val32);

    of_oxm_bsn_lag_id_masked_value_mask_get(src, &val32);
    of_oxm_bsn_lag_id_masked_value_mask_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_bsn_vrf
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_bsn_vrf.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_bsn_vrf_t *
of_oxm_bsn_vrf_OF_VERSION_1_2_dup(
    of_oxm_bsn_vrf_t *src)
{
    of_oxm_bsn_vrf_t *dst;
    uint32_t val32;

    if ((dst = of_oxm_bsn_vrf_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_bsn_vrf_value_get(src, &val32);
    of_oxm_bsn_vrf_value_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_bsn_vrf_masked
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_bsn_vrf_masked.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_bsn_vrf_masked_t *
of_oxm_bsn_vrf_masked_OF_VERSION_1_2_dup(
    of_oxm_bsn_vrf_masked_t *src)
{
    of_oxm_bsn_vrf_masked_t *dst;
    uint32_t val32;

    if ((dst = of_oxm_bsn_vrf_masked_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_bsn_vrf_masked_value_get(src, &val32);
    of_oxm_bsn_vrf_masked_value_set(dst, val32);

    of_oxm_bsn_vrf_masked_value_mask_get(src, &val32);
    of_oxm_bsn_vrf_masked_value_mask_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_eth_dst
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_eth_dst.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_eth_dst_t *
of_oxm_eth_dst_OF_VERSION_1_2_dup(
    of_oxm_eth_dst_t *src)
{
    of_oxm_eth_dst_t *dst;
    of_mac_addr_t mac_addr;

    if ((dst = of_oxm_eth_dst_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_eth_dst_value_get(src, &mac_addr);
    of_oxm_eth_dst_value_set(dst, mac_addr);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_eth_dst_masked
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_eth_dst_masked.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_eth_dst_masked_t *
of_oxm_eth_dst_masked_OF_VERSION_1_2_dup(
    of_oxm_eth_dst_masked_t *src)
{
    of_oxm_eth_dst_masked_t *dst;
    of_mac_addr_t mac_addr;

    if ((dst = of_oxm_eth_dst_masked_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_eth_dst_masked_value_get(src, &mac_addr);
    of_oxm_eth_dst_masked_value_set(dst, mac_addr);

    of_oxm_eth_dst_masked_value_mask_get(src, &mac_addr);
    of_oxm_eth_dst_masked_value_mask_set(dst, mac_addr);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_eth_src
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_eth_src.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_eth_src_t *
of_oxm_eth_src_OF_VERSION_1_2_dup(
    of_oxm_eth_src_t *src)
{
    of_oxm_eth_src_t *dst;
    of_mac_addr_t mac_addr;

    if ((dst = of_oxm_eth_src_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_eth_src_value_get(src, &mac_addr);
    of_oxm_eth_src_value_set(dst, mac_addr);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_eth_src_masked
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_eth_src_masked.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_eth_src_masked_t *
of_oxm_eth_src_masked_OF_VERSION_1_2_dup(
    of_oxm_eth_src_masked_t *src)
{
    of_oxm_eth_src_masked_t *dst;
    of_mac_addr_t mac_addr;

    if ((dst = of_oxm_eth_src_masked_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_eth_src_masked_value_get(src, &mac_addr);
    of_oxm_eth_src_masked_value_set(dst, mac_addr);

    of_oxm_eth_src_masked_value_mask_get(src, &mac_addr);
    of_oxm_eth_src_masked_value_mask_set(dst, mac_addr);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_eth_type
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_eth_type.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_eth_type_t *
of_oxm_eth_type_OF_VERSION_1_2_dup(
    of_oxm_eth_type_t *src)
{
    of_oxm_eth_type_t *dst;
    uint16_t val16;

    if ((dst = of_oxm_eth_type_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_eth_type_value_get(src, &val16);
    of_oxm_eth_type_value_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_eth_type_masked
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_eth_type_masked.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_eth_type_masked_t *
of_oxm_eth_type_masked_OF_VERSION_1_2_dup(
    of_oxm_eth_type_masked_t *src)
{
    of_oxm_eth_type_masked_t *dst;
    uint16_t val16;

    if ((dst = of_oxm_eth_type_masked_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_eth_type_masked_value_get(src, &val16);
    of_oxm_eth_type_masked_value_set(dst, val16);

    of_oxm_eth_type_masked_value_mask_get(src, &val16);
    of_oxm_eth_type_masked_value_mask_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_header
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_header.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_header_t *
of_oxm_header_OF_VERSION_1_2_dup(
    of_oxm_header_t *src)
{
    of_oxm_header_t *dst;

    if ((dst = of_oxm_header_new(src->version)) == NULL) {
        return NULL;
    }

    return dst;
}

/**
 * Duplicate an object of type of_oxm_icmpv4_code
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_icmpv4_code.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_icmpv4_code_t *
of_oxm_icmpv4_code_OF_VERSION_1_2_dup(
    of_oxm_icmpv4_code_t *src)
{
    of_oxm_icmpv4_code_t *dst;
    uint8_t val8;

    if ((dst = of_oxm_icmpv4_code_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_icmpv4_code_value_get(src, &val8);
    of_oxm_icmpv4_code_value_set(dst, val8);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_icmpv4_code_masked
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_icmpv4_code_masked.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_icmpv4_code_masked_t *
of_oxm_icmpv4_code_masked_OF_VERSION_1_2_dup(
    of_oxm_icmpv4_code_masked_t *src)
{
    of_oxm_icmpv4_code_masked_t *dst;
    uint8_t val8;

    if ((dst = of_oxm_icmpv4_code_masked_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_icmpv4_code_masked_value_get(src, &val8);
    of_oxm_icmpv4_code_masked_value_set(dst, val8);

    of_oxm_icmpv4_code_masked_value_mask_get(src, &val8);
    of_oxm_icmpv4_code_masked_value_mask_set(dst, val8);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_icmpv4_type
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_icmpv4_type.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_icmpv4_type_t *
of_oxm_icmpv4_type_OF_VERSION_1_2_dup(
    of_oxm_icmpv4_type_t *src)
{
    of_oxm_icmpv4_type_t *dst;
    uint8_t val8;

    if ((dst = of_oxm_icmpv4_type_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_icmpv4_type_value_get(src, &val8);
    of_oxm_icmpv4_type_value_set(dst, val8);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_icmpv4_type_masked
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_icmpv4_type_masked.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_icmpv4_type_masked_t *
of_oxm_icmpv4_type_masked_OF_VERSION_1_2_dup(
    of_oxm_icmpv4_type_masked_t *src)
{
    of_oxm_icmpv4_type_masked_t *dst;
    uint8_t val8;

    if ((dst = of_oxm_icmpv4_type_masked_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_icmpv4_type_masked_value_get(src, &val8);
    of_oxm_icmpv4_type_masked_value_set(dst, val8);

    of_oxm_icmpv4_type_masked_value_mask_get(src, &val8);
    of_oxm_icmpv4_type_masked_value_mask_set(dst, val8);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_icmpv6_code
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_icmpv6_code.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_icmpv6_code_t *
of_oxm_icmpv6_code_OF_VERSION_1_2_dup(
    of_oxm_icmpv6_code_t *src)
{
    of_oxm_icmpv6_code_t *dst;
    uint8_t val8;

    if ((dst = of_oxm_icmpv6_code_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_icmpv6_code_value_get(src, &val8);
    of_oxm_icmpv6_code_value_set(dst, val8);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_icmpv6_code_masked
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_icmpv6_code_masked.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_icmpv6_code_masked_t *
of_oxm_icmpv6_code_masked_OF_VERSION_1_2_dup(
    of_oxm_icmpv6_code_masked_t *src)
{
    of_oxm_icmpv6_code_masked_t *dst;
    uint8_t val8;

    if ((dst = of_oxm_icmpv6_code_masked_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_icmpv6_code_masked_value_get(src, &val8);
    of_oxm_icmpv6_code_masked_value_set(dst, val8);

    of_oxm_icmpv6_code_masked_value_mask_get(src, &val8);
    of_oxm_icmpv6_code_masked_value_mask_set(dst, val8);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_icmpv6_type
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_icmpv6_type.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_icmpv6_type_t *
of_oxm_icmpv6_type_OF_VERSION_1_2_dup(
    of_oxm_icmpv6_type_t *src)
{
    of_oxm_icmpv6_type_t *dst;
    uint8_t val8;

    if ((dst = of_oxm_icmpv6_type_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_icmpv6_type_value_get(src, &val8);
    of_oxm_icmpv6_type_value_set(dst, val8);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_icmpv6_type_masked
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_icmpv6_type_masked.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_icmpv6_type_masked_t *
of_oxm_icmpv6_type_masked_OF_VERSION_1_2_dup(
    of_oxm_icmpv6_type_masked_t *src)
{
    of_oxm_icmpv6_type_masked_t *dst;
    uint8_t val8;

    if ((dst = of_oxm_icmpv6_type_masked_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_icmpv6_type_masked_value_get(src, &val8);
    of_oxm_icmpv6_type_masked_value_set(dst, val8);

    of_oxm_icmpv6_type_masked_value_mask_get(src, &val8);
    of_oxm_icmpv6_type_masked_value_mask_set(dst, val8);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_in_phy_port
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_in_phy_port.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_in_phy_port_t *
of_oxm_in_phy_port_OF_VERSION_1_2_dup(
    of_oxm_in_phy_port_t *src)
{
    of_oxm_in_phy_port_t *dst;
    of_port_no_t port_no;

    if ((dst = of_oxm_in_phy_port_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_in_phy_port_value_get(src, &port_no);
    of_oxm_in_phy_port_value_set(dst, port_no);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_in_phy_port_masked
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_in_phy_port_masked.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_in_phy_port_masked_t *
of_oxm_in_phy_port_masked_OF_VERSION_1_2_dup(
    of_oxm_in_phy_port_masked_t *src)
{
    of_oxm_in_phy_port_masked_t *dst;
    of_port_no_t port_no;

    if ((dst = of_oxm_in_phy_port_masked_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_in_phy_port_masked_value_get(src, &port_no);
    of_oxm_in_phy_port_masked_value_set(dst, port_no);

    of_oxm_in_phy_port_masked_value_mask_get(src, &port_no);
    of_oxm_in_phy_port_masked_value_mask_set(dst, port_no);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_in_port
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_in_port.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_in_port_t *
of_oxm_in_port_OF_VERSION_1_2_dup(
    of_oxm_in_port_t *src)
{
    of_oxm_in_port_t *dst;
    of_port_no_t port_no;

    if ((dst = of_oxm_in_port_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_in_port_value_get(src, &port_no);
    of_oxm_in_port_value_set(dst, port_no);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_in_port_masked
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_in_port_masked.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_in_port_masked_t *
of_oxm_in_port_masked_OF_VERSION_1_2_dup(
    of_oxm_in_port_masked_t *src)
{
    of_oxm_in_port_masked_t *dst;
    of_port_no_t port_no;

    if ((dst = of_oxm_in_port_masked_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_in_port_masked_value_get(src, &port_no);
    of_oxm_in_port_masked_value_set(dst, port_no);

    of_oxm_in_port_masked_value_mask_get(src, &port_no);
    of_oxm_in_port_masked_value_mask_set(dst, port_no);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_ip_dscp
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_ip_dscp.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_ip_dscp_t *
of_oxm_ip_dscp_OF_VERSION_1_2_dup(
    of_oxm_ip_dscp_t *src)
{
    of_oxm_ip_dscp_t *dst;
    uint8_t val8;

    if ((dst = of_oxm_ip_dscp_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_ip_dscp_value_get(src, &val8);
    of_oxm_ip_dscp_value_set(dst, val8);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_ip_dscp_masked
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_ip_dscp_masked.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_ip_dscp_masked_t *
of_oxm_ip_dscp_masked_OF_VERSION_1_2_dup(
    of_oxm_ip_dscp_masked_t *src)
{
    of_oxm_ip_dscp_masked_t *dst;
    uint8_t val8;

    if ((dst = of_oxm_ip_dscp_masked_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_ip_dscp_masked_value_get(src, &val8);
    of_oxm_ip_dscp_masked_value_set(dst, val8);

    of_oxm_ip_dscp_masked_value_mask_get(src, &val8);
    of_oxm_ip_dscp_masked_value_mask_set(dst, val8);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_ip_ecn
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_ip_ecn.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_ip_ecn_t *
of_oxm_ip_ecn_OF_VERSION_1_2_dup(
    of_oxm_ip_ecn_t *src)
{
    of_oxm_ip_ecn_t *dst;
    uint8_t val8;

    if ((dst = of_oxm_ip_ecn_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_ip_ecn_value_get(src, &val8);
    of_oxm_ip_ecn_value_set(dst, val8);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_ip_ecn_masked
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_ip_ecn_masked.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_ip_ecn_masked_t *
of_oxm_ip_ecn_masked_OF_VERSION_1_2_dup(
    of_oxm_ip_ecn_masked_t *src)
{
    of_oxm_ip_ecn_masked_t *dst;
    uint8_t val8;

    if ((dst = of_oxm_ip_ecn_masked_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_ip_ecn_masked_value_get(src, &val8);
    of_oxm_ip_ecn_masked_value_set(dst, val8);

    of_oxm_ip_ecn_masked_value_mask_get(src, &val8);
    of_oxm_ip_ecn_masked_value_mask_set(dst, val8);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_ip_proto
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_ip_proto.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_ip_proto_t *
of_oxm_ip_proto_OF_VERSION_1_2_dup(
    of_oxm_ip_proto_t *src)
{
    of_oxm_ip_proto_t *dst;
    uint8_t val8;

    if ((dst = of_oxm_ip_proto_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_ip_proto_value_get(src, &val8);
    of_oxm_ip_proto_value_set(dst, val8);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_ip_proto_masked
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_ip_proto_masked.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_ip_proto_masked_t *
of_oxm_ip_proto_masked_OF_VERSION_1_2_dup(
    of_oxm_ip_proto_masked_t *src)
{
    of_oxm_ip_proto_masked_t *dst;
    uint8_t val8;

    if ((dst = of_oxm_ip_proto_masked_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_ip_proto_masked_value_get(src, &val8);
    of_oxm_ip_proto_masked_value_set(dst, val8);

    of_oxm_ip_proto_masked_value_mask_get(src, &val8);
    of_oxm_ip_proto_masked_value_mask_set(dst, val8);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_ipv4_dst
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_ipv4_dst.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_ipv4_dst_t *
of_oxm_ipv4_dst_OF_VERSION_1_2_dup(
    of_oxm_ipv4_dst_t *src)
{
    of_oxm_ipv4_dst_t *dst;
    of_ipv4_t ipv4;

    if ((dst = of_oxm_ipv4_dst_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_ipv4_dst_value_get(src, &ipv4);
    of_oxm_ipv4_dst_value_set(dst, ipv4);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_ipv4_dst_masked
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_ipv4_dst_masked.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_ipv4_dst_masked_t *
of_oxm_ipv4_dst_masked_OF_VERSION_1_2_dup(
    of_oxm_ipv4_dst_masked_t *src)
{
    of_oxm_ipv4_dst_masked_t *dst;
    of_ipv4_t ipv4;

    if ((dst = of_oxm_ipv4_dst_masked_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_ipv4_dst_masked_value_get(src, &ipv4);
    of_oxm_ipv4_dst_masked_value_set(dst, ipv4);

    of_oxm_ipv4_dst_masked_value_mask_get(src, &ipv4);
    of_oxm_ipv4_dst_masked_value_mask_set(dst, ipv4);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_ipv4_src
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_ipv4_src.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_ipv4_src_t *
of_oxm_ipv4_src_OF_VERSION_1_2_dup(
    of_oxm_ipv4_src_t *src)
{
    of_oxm_ipv4_src_t *dst;
    of_ipv4_t ipv4;

    if ((dst = of_oxm_ipv4_src_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_ipv4_src_value_get(src, &ipv4);
    of_oxm_ipv4_src_value_set(dst, ipv4);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_ipv4_src_masked
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_ipv4_src_masked.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_ipv4_src_masked_t *
of_oxm_ipv4_src_masked_OF_VERSION_1_2_dup(
    of_oxm_ipv4_src_masked_t *src)
{
    of_oxm_ipv4_src_masked_t *dst;
    of_ipv4_t ipv4;

    if ((dst = of_oxm_ipv4_src_masked_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_ipv4_src_masked_value_get(src, &ipv4);
    of_oxm_ipv4_src_masked_value_set(dst, ipv4);

    of_oxm_ipv4_src_masked_value_mask_get(src, &ipv4);
    of_oxm_ipv4_src_masked_value_mask_set(dst, ipv4);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_ipv6_dst
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_ipv6_dst.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_ipv6_dst_t *
of_oxm_ipv6_dst_OF_VERSION_1_2_dup(
    of_oxm_ipv6_dst_t *src)
{
    of_oxm_ipv6_dst_t *dst;
    of_ipv6_t ipv6;

    if ((dst = of_oxm_ipv6_dst_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_ipv6_dst_value_get(src, &ipv6);
    of_oxm_ipv6_dst_value_set(dst, ipv6);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_ipv6_dst_masked
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_ipv6_dst_masked.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_ipv6_dst_masked_t *
of_oxm_ipv6_dst_masked_OF_VERSION_1_2_dup(
    of_oxm_ipv6_dst_masked_t *src)
{
    of_oxm_ipv6_dst_masked_t *dst;
    of_ipv6_t ipv6;

    if ((dst = of_oxm_ipv6_dst_masked_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_ipv6_dst_masked_value_get(src, &ipv6);
    of_oxm_ipv6_dst_masked_value_set(dst, ipv6);

    of_oxm_ipv6_dst_masked_value_mask_get(src, &ipv6);
    of_oxm_ipv6_dst_masked_value_mask_set(dst, ipv6);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_ipv6_flabel
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_ipv6_flabel.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_ipv6_flabel_t *
of_oxm_ipv6_flabel_OF_VERSION_1_2_dup(
    of_oxm_ipv6_flabel_t *src)
{
    of_oxm_ipv6_flabel_t *dst;
    uint32_t val32;

    if ((dst = of_oxm_ipv6_flabel_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_ipv6_flabel_value_get(src, &val32);
    of_oxm_ipv6_flabel_value_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_ipv6_flabel_masked
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_ipv6_flabel_masked.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_ipv6_flabel_masked_t *
of_oxm_ipv6_flabel_masked_OF_VERSION_1_2_dup(
    of_oxm_ipv6_flabel_masked_t *src)
{
    of_oxm_ipv6_flabel_masked_t *dst;
    uint32_t val32;

    if ((dst = of_oxm_ipv6_flabel_masked_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_ipv6_flabel_masked_value_get(src, &val32);
    of_oxm_ipv6_flabel_masked_value_set(dst, val32);

    of_oxm_ipv6_flabel_masked_value_mask_get(src, &val32);
    of_oxm_ipv6_flabel_masked_value_mask_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_ipv6_nd_sll
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_ipv6_nd_sll.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_ipv6_nd_sll_t *
of_oxm_ipv6_nd_sll_OF_VERSION_1_2_dup(
    of_oxm_ipv6_nd_sll_t *src)
{
    of_oxm_ipv6_nd_sll_t *dst;
    of_mac_addr_t mac_addr;

    if ((dst = of_oxm_ipv6_nd_sll_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_ipv6_nd_sll_value_get(src, &mac_addr);
    of_oxm_ipv6_nd_sll_value_set(dst, mac_addr);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_ipv6_nd_sll_masked
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_ipv6_nd_sll_masked.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_ipv6_nd_sll_masked_t *
of_oxm_ipv6_nd_sll_masked_OF_VERSION_1_2_dup(
    of_oxm_ipv6_nd_sll_masked_t *src)
{
    of_oxm_ipv6_nd_sll_masked_t *dst;
    of_mac_addr_t mac_addr;

    if ((dst = of_oxm_ipv6_nd_sll_masked_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_ipv6_nd_sll_masked_value_get(src, &mac_addr);
    of_oxm_ipv6_nd_sll_masked_value_set(dst, mac_addr);

    of_oxm_ipv6_nd_sll_masked_value_mask_get(src, &mac_addr);
    of_oxm_ipv6_nd_sll_masked_value_mask_set(dst, mac_addr);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_ipv6_nd_target
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_ipv6_nd_target.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_ipv6_nd_target_t *
of_oxm_ipv6_nd_target_OF_VERSION_1_2_dup(
    of_oxm_ipv6_nd_target_t *src)
{
    of_oxm_ipv6_nd_target_t *dst;
    of_ipv6_t ipv6;

    if ((dst = of_oxm_ipv6_nd_target_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_ipv6_nd_target_value_get(src, &ipv6);
    of_oxm_ipv6_nd_target_value_set(dst, ipv6);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_ipv6_nd_target_masked
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_ipv6_nd_target_masked.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_ipv6_nd_target_masked_t *
of_oxm_ipv6_nd_target_masked_OF_VERSION_1_2_dup(
    of_oxm_ipv6_nd_target_masked_t *src)
{
    of_oxm_ipv6_nd_target_masked_t *dst;
    of_ipv6_t ipv6;

    if ((dst = of_oxm_ipv6_nd_target_masked_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_ipv6_nd_target_masked_value_get(src, &ipv6);
    of_oxm_ipv6_nd_target_masked_value_set(dst, ipv6);

    of_oxm_ipv6_nd_target_masked_value_mask_get(src, &ipv6);
    of_oxm_ipv6_nd_target_masked_value_mask_set(dst, ipv6);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_ipv6_nd_tll
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_ipv6_nd_tll.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_ipv6_nd_tll_t *
of_oxm_ipv6_nd_tll_OF_VERSION_1_2_dup(
    of_oxm_ipv6_nd_tll_t *src)
{
    of_oxm_ipv6_nd_tll_t *dst;
    of_mac_addr_t mac_addr;

    if ((dst = of_oxm_ipv6_nd_tll_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_ipv6_nd_tll_value_get(src, &mac_addr);
    of_oxm_ipv6_nd_tll_value_set(dst, mac_addr);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_ipv6_nd_tll_masked
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_ipv6_nd_tll_masked.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_ipv6_nd_tll_masked_t *
of_oxm_ipv6_nd_tll_masked_OF_VERSION_1_2_dup(
    of_oxm_ipv6_nd_tll_masked_t *src)
{
    of_oxm_ipv6_nd_tll_masked_t *dst;
    of_mac_addr_t mac_addr;

    if ((dst = of_oxm_ipv6_nd_tll_masked_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_ipv6_nd_tll_masked_value_get(src, &mac_addr);
    of_oxm_ipv6_nd_tll_masked_value_set(dst, mac_addr);

    of_oxm_ipv6_nd_tll_masked_value_mask_get(src, &mac_addr);
    of_oxm_ipv6_nd_tll_masked_value_mask_set(dst, mac_addr);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_ipv6_src
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_ipv6_src.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_ipv6_src_t *
of_oxm_ipv6_src_OF_VERSION_1_2_dup(
    of_oxm_ipv6_src_t *src)
{
    of_oxm_ipv6_src_t *dst;
    of_ipv6_t ipv6;

    if ((dst = of_oxm_ipv6_src_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_ipv6_src_value_get(src, &ipv6);
    of_oxm_ipv6_src_value_set(dst, ipv6);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_ipv6_src_masked
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_ipv6_src_masked.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_ipv6_src_masked_t *
of_oxm_ipv6_src_masked_OF_VERSION_1_2_dup(
    of_oxm_ipv6_src_masked_t *src)
{
    of_oxm_ipv6_src_masked_t *dst;
    of_ipv6_t ipv6;

    if ((dst = of_oxm_ipv6_src_masked_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_ipv6_src_masked_value_get(src, &ipv6);
    of_oxm_ipv6_src_masked_value_set(dst, ipv6);

    of_oxm_ipv6_src_masked_value_mask_get(src, &ipv6);
    of_oxm_ipv6_src_masked_value_mask_set(dst, ipv6);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_metadata
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_metadata.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_metadata_t *
of_oxm_metadata_OF_VERSION_1_2_dup(
    of_oxm_metadata_t *src)
{
    of_oxm_metadata_t *dst;
    uint64_t val64;

    if ((dst = of_oxm_metadata_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_metadata_value_get(src, &val64);
    of_oxm_metadata_value_set(dst, val64);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_metadata_masked
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_metadata_masked.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_metadata_masked_t *
of_oxm_metadata_masked_OF_VERSION_1_2_dup(
    of_oxm_metadata_masked_t *src)
{
    of_oxm_metadata_masked_t *dst;
    uint64_t val64;

    if ((dst = of_oxm_metadata_masked_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_metadata_masked_value_get(src, &val64);
    of_oxm_metadata_masked_value_set(dst, val64);

    of_oxm_metadata_masked_value_mask_get(src, &val64);
    of_oxm_metadata_masked_value_mask_set(dst, val64);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_mpls_label
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_mpls_label.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_mpls_label_t *
of_oxm_mpls_label_OF_VERSION_1_2_dup(
    of_oxm_mpls_label_t *src)
{
    of_oxm_mpls_label_t *dst;
    uint32_t val32;

    if ((dst = of_oxm_mpls_label_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_mpls_label_value_get(src, &val32);
    of_oxm_mpls_label_value_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_mpls_label_masked
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_mpls_label_masked.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_mpls_label_masked_t *
of_oxm_mpls_label_masked_OF_VERSION_1_2_dup(
    of_oxm_mpls_label_masked_t *src)
{
    of_oxm_mpls_label_masked_t *dst;
    uint32_t val32;

    if ((dst = of_oxm_mpls_label_masked_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_mpls_label_masked_value_get(src, &val32);
    of_oxm_mpls_label_masked_value_set(dst, val32);

    of_oxm_mpls_label_masked_value_mask_get(src, &val32);
    of_oxm_mpls_label_masked_value_mask_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_mpls_tc
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_mpls_tc.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_mpls_tc_t *
of_oxm_mpls_tc_OF_VERSION_1_2_dup(
    of_oxm_mpls_tc_t *src)
{
    of_oxm_mpls_tc_t *dst;
    uint8_t val8;

    if ((dst = of_oxm_mpls_tc_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_mpls_tc_value_get(src, &val8);
    of_oxm_mpls_tc_value_set(dst, val8);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_mpls_tc_masked
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_mpls_tc_masked.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_mpls_tc_masked_t *
of_oxm_mpls_tc_masked_OF_VERSION_1_2_dup(
    of_oxm_mpls_tc_masked_t *src)
{
    of_oxm_mpls_tc_masked_t *dst;
    uint8_t val8;

    if ((dst = of_oxm_mpls_tc_masked_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_mpls_tc_masked_value_get(src, &val8);
    of_oxm_mpls_tc_masked_value_set(dst, val8);

    of_oxm_mpls_tc_masked_value_mask_get(src, &val8);
    of_oxm_mpls_tc_masked_value_mask_set(dst, val8);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_sctp_dst
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_sctp_dst.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_sctp_dst_t *
of_oxm_sctp_dst_OF_VERSION_1_2_dup(
    of_oxm_sctp_dst_t *src)
{
    of_oxm_sctp_dst_t *dst;
    uint16_t val16;

    if ((dst = of_oxm_sctp_dst_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_sctp_dst_value_get(src, &val16);
    of_oxm_sctp_dst_value_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_sctp_dst_masked
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_sctp_dst_masked.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_sctp_dst_masked_t *
of_oxm_sctp_dst_masked_OF_VERSION_1_2_dup(
    of_oxm_sctp_dst_masked_t *src)
{
    of_oxm_sctp_dst_masked_t *dst;
    uint16_t val16;

    if ((dst = of_oxm_sctp_dst_masked_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_sctp_dst_masked_value_get(src, &val16);
    of_oxm_sctp_dst_masked_value_set(dst, val16);

    of_oxm_sctp_dst_masked_value_mask_get(src, &val16);
    of_oxm_sctp_dst_masked_value_mask_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_sctp_src
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_sctp_src.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_sctp_src_t *
of_oxm_sctp_src_OF_VERSION_1_2_dup(
    of_oxm_sctp_src_t *src)
{
    of_oxm_sctp_src_t *dst;
    uint16_t val16;

    if ((dst = of_oxm_sctp_src_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_sctp_src_value_get(src, &val16);
    of_oxm_sctp_src_value_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_sctp_src_masked
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_sctp_src_masked.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_sctp_src_masked_t *
of_oxm_sctp_src_masked_OF_VERSION_1_2_dup(
    of_oxm_sctp_src_masked_t *src)
{
    of_oxm_sctp_src_masked_t *dst;
    uint16_t val16;

    if ((dst = of_oxm_sctp_src_masked_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_sctp_src_masked_value_get(src, &val16);
    of_oxm_sctp_src_masked_value_set(dst, val16);

    of_oxm_sctp_src_masked_value_mask_get(src, &val16);
    of_oxm_sctp_src_masked_value_mask_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_tcp_dst
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_tcp_dst.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_tcp_dst_t *
of_oxm_tcp_dst_OF_VERSION_1_2_dup(
    of_oxm_tcp_dst_t *src)
{
    of_oxm_tcp_dst_t *dst;
    uint16_t val16;

    if ((dst = of_oxm_tcp_dst_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_tcp_dst_value_get(src, &val16);
    of_oxm_tcp_dst_value_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_tcp_dst_masked
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_tcp_dst_masked.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_tcp_dst_masked_t *
of_oxm_tcp_dst_masked_OF_VERSION_1_2_dup(
    of_oxm_tcp_dst_masked_t *src)
{
    of_oxm_tcp_dst_masked_t *dst;
    uint16_t val16;

    if ((dst = of_oxm_tcp_dst_masked_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_tcp_dst_masked_value_get(src, &val16);
    of_oxm_tcp_dst_masked_value_set(dst, val16);

    of_oxm_tcp_dst_masked_value_mask_get(src, &val16);
    of_oxm_tcp_dst_masked_value_mask_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_tcp_src
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_tcp_src.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_tcp_src_t *
of_oxm_tcp_src_OF_VERSION_1_2_dup(
    of_oxm_tcp_src_t *src)
{
    of_oxm_tcp_src_t *dst;
    uint16_t val16;

    if ((dst = of_oxm_tcp_src_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_tcp_src_value_get(src, &val16);
    of_oxm_tcp_src_value_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_tcp_src_masked
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_tcp_src_masked.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_tcp_src_masked_t *
of_oxm_tcp_src_masked_OF_VERSION_1_2_dup(
    of_oxm_tcp_src_masked_t *src)
{
    of_oxm_tcp_src_masked_t *dst;
    uint16_t val16;

    if ((dst = of_oxm_tcp_src_masked_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_tcp_src_masked_value_get(src, &val16);
    of_oxm_tcp_src_masked_value_set(dst, val16);

    of_oxm_tcp_src_masked_value_mask_get(src, &val16);
    of_oxm_tcp_src_masked_value_mask_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_udp_dst
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_udp_dst.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_udp_dst_t *
of_oxm_udp_dst_OF_VERSION_1_2_dup(
    of_oxm_udp_dst_t *src)
{
    of_oxm_udp_dst_t *dst;
    uint16_t val16;

    if ((dst = of_oxm_udp_dst_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_udp_dst_value_get(src, &val16);
    of_oxm_udp_dst_value_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_udp_dst_masked
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_udp_dst_masked.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_udp_dst_masked_t *
of_oxm_udp_dst_masked_OF_VERSION_1_2_dup(
    of_oxm_udp_dst_masked_t *src)
{
    of_oxm_udp_dst_masked_t *dst;
    uint16_t val16;

    if ((dst = of_oxm_udp_dst_masked_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_udp_dst_masked_value_get(src, &val16);
    of_oxm_udp_dst_masked_value_set(dst, val16);

    of_oxm_udp_dst_masked_value_mask_get(src, &val16);
    of_oxm_udp_dst_masked_value_mask_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_udp_src
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_udp_src.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_udp_src_t *
of_oxm_udp_src_OF_VERSION_1_2_dup(
    of_oxm_udp_src_t *src)
{
    of_oxm_udp_src_t *dst;
    uint16_t val16;

    if ((dst = of_oxm_udp_src_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_udp_src_value_get(src, &val16);
    of_oxm_udp_src_value_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_udp_src_masked
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_udp_src_masked.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_udp_src_masked_t *
of_oxm_udp_src_masked_OF_VERSION_1_2_dup(
    of_oxm_udp_src_masked_t *src)
{
    of_oxm_udp_src_masked_t *dst;
    uint16_t val16;

    if ((dst = of_oxm_udp_src_masked_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_udp_src_masked_value_get(src, &val16);
    of_oxm_udp_src_masked_value_set(dst, val16);

    of_oxm_udp_src_masked_value_mask_get(src, &val16);
    of_oxm_udp_src_masked_value_mask_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_vlan_pcp
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_vlan_pcp.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_vlan_pcp_t *
of_oxm_vlan_pcp_OF_VERSION_1_2_dup(
    of_oxm_vlan_pcp_t *src)
{
    of_oxm_vlan_pcp_t *dst;
    uint8_t val8;

    if ((dst = of_oxm_vlan_pcp_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_vlan_pcp_value_get(src, &val8);
    of_oxm_vlan_pcp_value_set(dst, val8);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_vlan_pcp_masked
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_vlan_pcp_masked.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_vlan_pcp_masked_t *
of_oxm_vlan_pcp_masked_OF_VERSION_1_2_dup(
    of_oxm_vlan_pcp_masked_t *src)
{
    of_oxm_vlan_pcp_masked_t *dst;
    uint8_t val8;

    if ((dst = of_oxm_vlan_pcp_masked_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_vlan_pcp_masked_value_get(src, &val8);
    of_oxm_vlan_pcp_masked_value_set(dst, val8);

    of_oxm_vlan_pcp_masked_value_mask_get(src, &val8);
    of_oxm_vlan_pcp_masked_value_mask_set(dst, val8);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_vlan_vid
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_vlan_vid.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_vlan_vid_t *
of_oxm_vlan_vid_OF_VERSION_1_2_dup(
    of_oxm_vlan_vid_t *src)
{
    of_oxm_vlan_vid_t *dst;
    uint16_t val16;

    if ((dst = of_oxm_vlan_vid_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_vlan_vid_value_get(src, &val16);
    of_oxm_vlan_vid_value_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_vlan_vid_masked
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_vlan_vid_masked.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_vlan_vid_masked_t *
of_oxm_vlan_vid_masked_OF_VERSION_1_2_dup(
    of_oxm_vlan_vid_masked_t *src)
{
    of_oxm_vlan_vid_masked_t *dst;
    uint16_t val16;

    if ((dst = of_oxm_vlan_vid_masked_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_vlan_vid_masked_value_get(src, &val16);
    of_oxm_vlan_vid_masked_value_set(dst, val16);

    of_oxm_vlan_vid_masked_value_mask_get(src, &val16);
    of_oxm_vlan_vid_masked_value_mask_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_packet_queue
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_packet_queue.
 *
 * The caller is responsible for deleting the returned value
 */
of_packet_queue_t *
of_packet_queue_OF_VERSION_1_2_dup(
    of_packet_queue_t *src)
{
    of_packet_queue_t *dst;
    uint32_t val32;
    of_port_no_t port_no;

    of_list_queue_prop_t src_list;
    of_list_queue_prop_t *dst_list;

    if ((dst = of_packet_queue_new(src->version)) == NULL) {
        return NULL;
    }

    of_packet_queue_queue_id_get(src, &val32);
    of_packet_queue_queue_id_set(dst, val32);

    of_packet_queue_port_get(src, &port_no);
    of_packet_queue_port_set(dst, port_no);

    of_packet_queue_properties_bind(
        src, &src_list);
    dst_list = of_list_queue_prop_OF_VERSION_1_2_dup(&src_list);
    if (dst_list == NULL) {
        of_packet_queue_delete(dst);
        return NULL;
    }
    of_packet_queue_properties_set(dst, dst_list);
    of_list_queue_prop_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_port_desc
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_port_desc.
 *
 * The caller is responsible for deleting the returned value
 */
of_port_desc_t *
of_port_desc_OF_VERSION_1_2_dup(
    of_port_desc_t *src)
{
    of_port_desc_t *dst;
    of_port_no_t port_no;
    of_mac_addr_t mac_addr;
    of_port_name_t port_name;
    uint32_t val32;

    if ((dst = of_port_desc_new(src->version)) == NULL) {
        return NULL;
    }

    of_port_desc_port_no_get(src, &port_no);
    of_port_desc_port_no_set(dst, port_no);

    of_port_desc_hw_addr_get(src, &mac_addr);
    of_port_desc_hw_addr_set(dst, mac_addr);

    of_port_desc_name_get(src, &port_name);
    of_port_desc_name_set(dst, port_name);

    of_port_desc_config_get(src, &val32);
    of_port_desc_config_set(dst, val32);

    of_port_desc_state_get(src, &val32);
    of_port_desc_state_set(dst, val32);

    of_port_desc_curr_get(src, &val32);
    of_port_desc_curr_set(dst, val32);

    of_port_desc_advertised_get(src, &val32);
    of_port_desc_advertised_set(dst, val32);

    of_port_desc_supported_get(src, &val32);
    of_port_desc_supported_set(dst, val32);

    of_port_desc_peer_get(src, &val32);
    of_port_desc_peer_set(dst, val32);

    of_port_desc_curr_speed_get(src, &val32);
    of_port_desc_curr_speed_set(dst, val32);

    of_port_desc_max_speed_get(src, &val32);
    of_port_desc_max_speed_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_port_stats_entry
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_port_stats_entry.
 *
 * The caller is responsible for deleting the returned value
 */
of_port_stats_entry_t *
of_port_stats_entry_OF_VERSION_1_2_dup(
    of_port_stats_entry_t *src)
{
    of_port_stats_entry_t *dst;
    of_port_no_t port_no;
    uint64_t val64;

    if ((dst = of_port_stats_entry_new(src->version)) == NULL) {
        return NULL;
    }

    of_port_stats_entry_port_no_get(src, &port_no);
    of_port_stats_entry_port_no_set(dst, port_no);

    of_port_stats_entry_rx_packets_get(src, &val64);
    of_port_stats_entry_rx_packets_set(dst, val64);

    of_port_stats_entry_tx_packets_get(src, &val64);
    of_port_stats_entry_tx_packets_set(dst, val64);

    of_port_stats_entry_rx_bytes_get(src, &val64);
    of_port_stats_entry_rx_bytes_set(dst, val64);

    of_port_stats_entry_tx_bytes_get(src, &val64);
    of_port_stats_entry_tx_bytes_set(dst, val64);

    of_port_stats_entry_rx_dropped_get(src, &val64);
    of_port_stats_entry_rx_dropped_set(dst, val64);

    of_port_stats_entry_tx_dropped_get(src, &val64);
    of_port_stats_entry_tx_dropped_set(dst, val64);

    of_port_stats_entry_rx_errors_get(src, &val64);
    of_port_stats_entry_rx_errors_set(dst, val64);

    of_port_stats_entry_tx_errors_get(src, &val64);
    of_port_stats_entry_tx_errors_set(dst, val64);

    of_port_stats_entry_rx_frame_err_get(src, &val64);
    of_port_stats_entry_rx_frame_err_set(dst, val64);

    of_port_stats_entry_rx_over_err_get(src, &val64);
    of_port_stats_entry_rx_over_err_set(dst, val64);

    of_port_stats_entry_rx_crc_err_get(src, &val64);
    of_port_stats_entry_rx_crc_err_set(dst, val64);

    of_port_stats_entry_collisions_get(src, &val64);
    of_port_stats_entry_collisions_set(dst, val64);

    return dst;
}

/**
 * Duplicate a super class object of type of_queue_prop
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_queue_prop.
 *
 * The caller is responsible for deleting the returned value
 */
of_queue_prop_t *
of_queue_prop_OF_VERSION_1_2_dup(
    of_queue_prop_t *src)
{

    if (src->header.object_id == OF_QUEUE_PROP_MIN_RATE) {
        return (of_queue_prop_t *)of_queue_prop_min_rate_OF_VERSION_1_2_dup(
            &src->min_rate);
    }

    if (src->header.object_id == OF_QUEUE_PROP_MAX_RATE) {
        return (of_queue_prop_t *)of_queue_prop_max_rate_OF_VERSION_1_2_dup(
            &src->max_rate);
    }

    if (src->header.object_id == OF_QUEUE_PROP_EXPERIMENTER) {
        return (of_queue_prop_t *)of_queue_prop_experimenter_OF_VERSION_1_2_dup(
            &src->experimenter);
    }

    return NULL;
}

/**
 * Duplicate an object of type of_queue_prop_experimenter
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_queue_prop_experimenter.
 *
 * The caller is responsible for deleting the returned value
 */
of_queue_prop_experimenter_t *
of_queue_prop_experimenter_OF_VERSION_1_2_dup(
    of_queue_prop_experimenter_t *src)
{
    of_queue_prop_experimenter_t *dst;
    uint32_t val32;
    of_octets_t octets;

    if ((dst = of_queue_prop_experimenter_new(src->version)) == NULL) {
        return NULL;
    }

    of_queue_prop_experimenter_experimenter_get(src, &val32);
    of_queue_prop_experimenter_experimenter_set(dst, val32);

    of_queue_prop_experimenter_data_get(src, &octets);
    of_queue_prop_experimenter_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_queue_prop_header
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_queue_prop_header.
 *
 * The caller is responsible for deleting the returned value
 */
of_queue_prop_header_t *
of_queue_prop_header_OF_VERSION_1_2_dup(
    of_queue_prop_header_t *src)
{
    of_queue_prop_header_t *dst;

    if ((dst = of_queue_prop_header_new(src->version)) == NULL) {
        return NULL;
    }

    return dst;
}

/**
 * Duplicate an object of type of_queue_prop_max_rate
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_queue_prop_max_rate.
 *
 * The caller is responsible for deleting the returned value
 */
of_queue_prop_max_rate_t *
of_queue_prop_max_rate_OF_VERSION_1_2_dup(
    of_queue_prop_max_rate_t *src)
{
    of_queue_prop_max_rate_t *dst;
    uint16_t val16;

    if ((dst = of_queue_prop_max_rate_new(src->version)) == NULL) {
        return NULL;
    }

    of_queue_prop_max_rate_rate_get(src, &val16);
    of_queue_prop_max_rate_rate_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_queue_prop_min_rate
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_queue_prop_min_rate.
 *
 * The caller is responsible for deleting the returned value
 */
of_queue_prop_min_rate_t *
of_queue_prop_min_rate_OF_VERSION_1_2_dup(
    of_queue_prop_min_rate_t *src)
{
    of_queue_prop_min_rate_t *dst;
    uint16_t val16;

    if ((dst = of_queue_prop_min_rate_new(src->version)) == NULL) {
        return NULL;
    }

    of_queue_prop_min_rate_rate_get(src, &val16);
    of_queue_prop_min_rate_rate_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_queue_stats_entry
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_queue_stats_entry.
 *
 * The caller is responsible for deleting the returned value
 */
of_queue_stats_entry_t *
of_queue_stats_entry_OF_VERSION_1_2_dup(
    of_queue_stats_entry_t *src)
{
    of_queue_stats_entry_t *dst;
    of_port_no_t port_no;
    uint32_t val32;
    uint64_t val64;

    if ((dst = of_queue_stats_entry_new(src->version)) == NULL) {
        return NULL;
    }

    of_queue_stats_entry_port_no_get(src, &port_no);
    of_queue_stats_entry_port_no_set(dst, port_no);

    of_queue_stats_entry_queue_id_get(src, &val32);
    of_queue_stats_entry_queue_id_set(dst, val32);

    of_queue_stats_entry_tx_bytes_get(src, &val64);
    of_queue_stats_entry_tx_bytes_set(dst, val64);

    of_queue_stats_entry_tx_packets_get(src, &val64);
    of_queue_stats_entry_tx_packets_set(dst, val64);

    of_queue_stats_entry_tx_errors_get(src, &val64);
    of_queue_stats_entry_tx_errors_set(dst, val64);

    return dst;
}

/**
 * Duplicate an object of type of_table_stats_entry
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_table_stats_entry.
 *
 * The caller is responsible for deleting the returned value
 */
of_table_stats_entry_t *
of_table_stats_entry_OF_VERSION_1_2_dup(
    of_table_stats_entry_t *src)
{
    of_table_stats_entry_t *dst;
    uint8_t val8;
    of_table_name_t table_name;
    of_match_bmap_t match_bmap;
    of_wc_bmap_t wc_bmap;
    uint32_t val32;
    uint64_t val64;

    if ((dst = of_table_stats_entry_new(src->version)) == NULL) {
        return NULL;
    }

    of_table_stats_entry_table_id_get(src, &val8);
    of_table_stats_entry_table_id_set(dst, val8);

    of_table_stats_entry_name_get(src, &table_name);
    of_table_stats_entry_name_set(dst, table_name);

    of_table_stats_entry_match_get(src, &match_bmap);
    of_table_stats_entry_match_set(dst, match_bmap);

    of_table_stats_entry_wildcards_get(src, &wc_bmap);
    of_table_stats_entry_wildcards_set(dst, wc_bmap);

    of_table_stats_entry_write_actions_get(src, &val32);
    of_table_stats_entry_write_actions_set(dst, val32);

    of_table_stats_entry_apply_actions_get(src, &val32);
    of_table_stats_entry_apply_actions_set(dst, val32);

    of_table_stats_entry_write_setfields_get(src, &val64);
    of_table_stats_entry_write_setfields_set(dst, val64);

    of_table_stats_entry_apply_setfields_get(src, &val64);
    of_table_stats_entry_apply_setfields_set(dst, val64);

    of_table_stats_entry_metadata_match_get(src, &val64);
    of_table_stats_entry_metadata_match_set(dst, val64);

    of_table_stats_entry_metadata_write_get(src, &val64);
    of_table_stats_entry_metadata_write_set(dst, val64);

    of_table_stats_entry_instructions_get(src, &val32);
    of_table_stats_entry_instructions_set(dst, val32);

    of_table_stats_entry_config_get(src, &val32);
    of_table_stats_entry_config_set(dst, val32);

    of_table_stats_entry_max_entries_get(src, &val32);
    of_table_stats_entry_max_entries_set(dst, val32);

    of_table_stats_entry_active_count_get(src, &val32);
    of_table_stats_entry_active_count_set(dst, val32);

    of_table_stats_entry_lookup_count_get(src, &val64);
    of_table_stats_entry_lookup_count_set(dst, val64);

    of_table_stats_entry_matched_count_get(src, &val64);
    of_table_stats_entry_matched_count_set(dst, val64);

    return dst;
}

/**
 * Duplicate a list of type of_list_action
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_list_action.
 *
 * The caller is responsible for deleting the returned value
 */
of_list_action_t *
of_list_action_OF_VERSION_1_2_dup(
    of_list_action_t *src)
{
    of_action_t src_elt;
    of_action_t *dst_elt;
    int rv;
    of_list_action_t *dst;

    if ((dst = of_list_action_new(src->version)) == NULL) {
        return NULL;
    }

    OF_LIST_ACTION_ITER(src, &src_elt, rv) {
        if ((dst_elt = of_action_OF_VERSION_1_2_dup(&src_elt)) == NULL) {
            of_object_delete((of_object_t *)dst);
            return NULL;
        }
        _TRY_FREE(of_list_action_append(dst, dst_elt),
            dst, NULL);
        of_object_delete((of_object_t *)dst_elt);
    }

    return dst;
}

/**
 * Duplicate a list of type of_list_bsn_interface
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_list_bsn_interface.
 *
 * The caller is responsible for deleting the returned value
 */
of_list_bsn_interface_t *
of_list_bsn_interface_OF_VERSION_1_2_dup(
    of_list_bsn_interface_t *src)
{
    of_bsn_interface_t src_elt;
    of_bsn_interface_t *dst_elt;
    int rv;
    of_list_bsn_interface_t *dst;

    if ((dst = of_list_bsn_interface_new(src->version)) == NULL) {
        return NULL;
    }

    OF_LIST_BSN_INTERFACE_ITER(src, &src_elt, rv) {
        if ((dst_elt = of_bsn_interface_OF_VERSION_1_2_dup(&src_elt)) == NULL) {
            of_object_delete((of_object_t *)dst);
            return NULL;
        }
        _TRY_FREE(of_list_bsn_interface_append(dst, dst_elt),
            dst, NULL);
        of_object_delete((of_object_t *)dst_elt);
    }

    return dst;
}

/**
 * Duplicate a list of type of_list_bucket
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_list_bucket.
 *
 * The caller is responsible for deleting the returned value
 */
of_list_bucket_t *
of_list_bucket_OF_VERSION_1_2_dup(
    of_list_bucket_t *src)
{
    of_bucket_t src_elt;
    of_bucket_t *dst_elt;
    int rv;
    of_list_bucket_t *dst;

    if ((dst = of_list_bucket_new(src->version)) == NULL) {
        return NULL;
    }

    OF_LIST_BUCKET_ITER(src, &src_elt, rv) {
        if ((dst_elt = of_bucket_OF_VERSION_1_2_dup(&src_elt)) == NULL) {
            of_object_delete((of_object_t *)dst);
            return NULL;
        }
        _TRY_FREE(of_list_bucket_append(dst, dst_elt),
            dst, NULL);
        of_object_delete((of_object_t *)dst_elt);
    }

    return dst;
}

/**
 * Duplicate a list of type of_list_bucket_counter
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_list_bucket_counter.
 *
 * The caller is responsible for deleting the returned value
 */
of_list_bucket_counter_t *
of_list_bucket_counter_OF_VERSION_1_2_dup(
    of_list_bucket_counter_t *src)
{
    of_bucket_counter_t src_elt;
    of_bucket_counter_t *dst_elt;
    int rv;
    of_list_bucket_counter_t *dst;

    if ((dst = of_list_bucket_counter_new(src->version)) == NULL) {
        return NULL;
    }

    OF_LIST_BUCKET_COUNTER_ITER(src, &src_elt, rv) {
        if ((dst_elt = of_bucket_counter_OF_VERSION_1_2_dup(&src_elt)) == NULL) {
            of_object_delete((of_object_t *)dst);
            return NULL;
        }
        _TRY_FREE(of_list_bucket_counter_append(dst, dst_elt),
            dst, NULL);
        of_object_delete((of_object_t *)dst_elt);
    }

    return dst;
}

/**
 * Duplicate a list of type of_list_flow_stats_entry
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_list_flow_stats_entry.
 *
 * The caller is responsible for deleting the returned value
 */
of_list_flow_stats_entry_t *
of_list_flow_stats_entry_OF_VERSION_1_2_dup(
    of_list_flow_stats_entry_t *src)
{
    of_flow_stats_entry_t src_elt;
    of_flow_stats_entry_t *dst_elt;
    int rv;
    of_list_flow_stats_entry_t *dst;

    if ((dst = of_list_flow_stats_entry_new(src->version)) == NULL) {
        return NULL;
    }

    OF_LIST_FLOW_STATS_ENTRY_ITER(src, &src_elt, rv) {
        if ((dst_elt = of_flow_stats_entry_OF_VERSION_1_2_dup(&src_elt)) == NULL) {
            of_object_delete((of_object_t *)dst);
            return NULL;
        }
        _TRY_FREE(of_list_flow_stats_entry_append(dst, dst_elt),
            dst, NULL);
        of_object_delete((of_object_t *)dst_elt);
    }

    return dst;
}

/**
 * Duplicate a list of type of_list_group_desc_stats_entry
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_list_group_desc_stats_entry.
 *
 * The caller is responsible for deleting the returned value
 */
of_list_group_desc_stats_entry_t *
of_list_group_desc_stats_entry_OF_VERSION_1_2_dup(
    of_list_group_desc_stats_entry_t *src)
{
    of_group_desc_stats_entry_t src_elt;
    of_group_desc_stats_entry_t *dst_elt;
    int rv;
    of_list_group_desc_stats_entry_t *dst;

    if ((dst = of_list_group_desc_stats_entry_new(src->version)) == NULL) {
        return NULL;
    }

    OF_LIST_GROUP_DESC_STATS_ENTRY_ITER(src, &src_elt, rv) {
        if ((dst_elt = of_group_desc_stats_entry_OF_VERSION_1_2_dup(&src_elt)) == NULL) {
            of_object_delete((of_object_t *)dst);
            return NULL;
        }
        _TRY_FREE(of_list_group_desc_stats_entry_append(dst, dst_elt),
            dst, NULL);
        of_object_delete((of_object_t *)dst_elt);
    }

    return dst;
}

/**
 * Duplicate a list of type of_list_group_stats_entry
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_list_group_stats_entry.
 *
 * The caller is responsible for deleting the returned value
 */
of_list_group_stats_entry_t *
of_list_group_stats_entry_OF_VERSION_1_2_dup(
    of_list_group_stats_entry_t *src)
{
    of_group_stats_entry_t src_elt;
    of_group_stats_entry_t *dst_elt;
    int rv;
    of_list_group_stats_entry_t *dst;

    if ((dst = of_list_group_stats_entry_new(src->version)) == NULL) {
        return NULL;
    }

    OF_LIST_GROUP_STATS_ENTRY_ITER(src, &src_elt, rv) {
        if ((dst_elt = of_group_stats_entry_OF_VERSION_1_2_dup(&src_elt)) == NULL) {
            of_object_delete((of_object_t *)dst);
            return NULL;
        }
        _TRY_FREE(of_list_group_stats_entry_append(dst, dst_elt),
            dst, NULL);
        of_object_delete((of_object_t *)dst_elt);
    }

    return dst;
}

/**
 * Duplicate a list of type of_list_instruction
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_list_instruction.
 *
 * The caller is responsible for deleting the returned value
 */
of_list_instruction_t *
of_list_instruction_OF_VERSION_1_2_dup(
    of_list_instruction_t *src)
{
    of_instruction_t src_elt;
    of_instruction_t *dst_elt;
    int rv;
    of_list_instruction_t *dst;

    if ((dst = of_list_instruction_new(src->version)) == NULL) {
        return NULL;
    }

    OF_LIST_INSTRUCTION_ITER(src, &src_elt, rv) {
        if ((dst_elt = of_instruction_OF_VERSION_1_2_dup(&src_elt)) == NULL) {
            of_object_delete((of_object_t *)dst);
            return NULL;
        }
        _TRY_FREE(of_list_instruction_append(dst, dst_elt),
            dst, NULL);
        of_object_delete((of_object_t *)dst_elt);
    }

    return dst;
}

/**
 * Duplicate a list of type of_list_oxm
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_list_oxm.
 *
 * The caller is responsible for deleting the returned value
 */
of_list_oxm_t *
of_list_oxm_OF_VERSION_1_2_dup(
    of_list_oxm_t *src)
{
    of_oxm_t src_elt;
    of_oxm_t *dst_elt;
    int rv;
    of_list_oxm_t *dst;

    if ((dst = of_list_oxm_new(src->version)) == NULL) {
        return NULL;
    }

    OF_LIST_OXM_ITER(src, &src_elt, rv) {
        if ((dst_elt = of_oxm_OF_VERSION_1_2_dup(&src_elt)) == NULL) {
            of_object_delete((of_object_t *)dst);
            return NULL;
        }
        _TRY_FREE(of_list_oxm_append(dst, dst_elt),
            dst, NULL);
        of_object_delete((of_object_t *)dst_elt);
    }

    return dst;
}

/**
 * Duplicate a list of type of_list_packet_queue
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_list_packet_queue.
 *
 * The caller is responsible for deleting the returned value
 */
of_list_packet_queue_t *
of_list_packet_queue_OF_VERSION_1_2_dup(
    of_list_packet_queue_t *src)
{
    of_packet_queue_t src_elt;
    of_packet_queue_t *dst_elt;
    int rv;
    of_list_packet_queue_t *dst;

    if ((dst = of_list_packet_queue_new(src->version)) == NULL) {
        return NULL;
    }

    OF_LIST_PACKET_QUEUE_ITER(src, &src_elt, rv) {
        if ((dst_elt = of_packet_queue_OF_VERSION_1_2_dup(&src_elt)) == NULL) {
            of_object_delete((of_object_t *)dst);
            return NULL;
        }
        _TRY_FREE(of_list_packet_queue_append(dst, dst_elt),
            dst, NULL);
        of_object_delete((of_object_t *)dst_elt);
    }

    return dst;
}

/**
 * Duplicate a list of type of_list_port_desc
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_list_port_desc.
 *
 * The caller is responsible for deleting the returned value
 */
of_list_port_desc_t *
of_list_port_desc_OF_VERSION_1_2_dup(
    of_list_port_desc_t *src)
{
    of_port_desc_t src_elt;
    of_port_desc_t *dst_elt;
    int rv;
    of_list_port_desc_t *dst;

    if ((dst = of_list_port_desc_new(src->version)) == NULL) {
        return NULL;
    }

    OF_LIST_PORT_DESC_ITER(src, &src_elt, rv) {
        if ((dst_elt = of_port_desc_OF_VERSION_1_2_dup(&src_elt)) == NULL) {
            of_object_delete((of_object_t *)dst);
            return NULL;
        }
        _TRY_FREE(of_list_port_desc_append(dst, dst_elt),
            dst, NULL);
        of_object_delete((of_object_t *)dst_elt);
    }

    return dst;
}

/**
 * Duplicate a list of type of_list_port_stats_entry
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_list_port_stats_entry.
 *
 * The caller is responsible for deleting the returned value
 */
of_list_port_stats_entry_t *
of_list_port_stats_entry_OF_VERSION_1_2_dup(
    of_list_port_stats_entry_t *src)
{
    of_port_stats_entry_t src_elt;
    of_port_stats_entry_t *dst_elt;
    int rv;
    of_list_port_stats_entry_t *dst;

    if ((dst = of_list_port_stats_entry_new(src->version)) == NULL) {
        return NULL;
    }

    OF_LIST_PORT_STATS_ENTRY_ITER(src, &src_elt, rv) {
        if ((dst_elt = of_port_stats_entry_OF_VERSION_1_2_dup(&src_elt)) == NULL) {
            of_object_delete((of_object_t *)dst);
            return NULL;
        }
        _TRY_FREE(of_list_port_stats_entry_append(dst, dst_elt),
            dst, NULL);
        of_object_delete((of_object_t *)dst_elt);
    }

    return dst;
}

/**
 * Duplicate a list of type of_list_queue_prop
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_list_queue_prop.
 *
 * The caller is responsible for deleting the returned value
 */
of_list_queue_prop_t *
of_list_queue_prop_OF_VERSION_1_2_dup(
    of_list_queue_prop_t *src)
{
    of_queue_prop_t src_elt;
    of_queue_prop_t *dst_elt;
    int rv;
    of_list_queue_prop_t *dst;

    if ((dst = of_list_queue_prop_new(src->version)) == NULL) {
        return NULL;
    }

    OF_LIST_QUEUE_PROP_ITER(src, &src_elt, rv) {
        if ((dst_elt = of_queue_prop_OF_VERSION_1_2_dup(&src_elt)) == NULL) {
            of_object_delete((of_object_t *)dst);
            return NULL;
        }
        _TRY_FREE(of_list_queue_prop_append(dst, dst_elt),
            dst, NULL);
        of_object_delete((of_object_t *)dst_elt);
    }

    return dst;
}

/**
 * Duplicate a list of type of_list_queue_stats_entry
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_list_queue_stats_entry.
 *
 * The caller is responsible for deleting the returned value
 */
of_list_queue_stats_entry_t *
of_list_queue_stats_entry_OF_VERSION_1_2_dup(
    of_list_queue_stats_entry_t *src)
{
    of_queue_stats_entry_t src_elt;
    of_queue_stats_entry_t *dst_elt;
    int rv;
    of_list_queue_stats_entry_t *dst;

    if ((dst = of_list_queue_stats_entry_new(src->version)) == NULL) {
        return NULL;
    }

    OF_LIST_QUEUE_STATS_ENTRY_ITER(src, &src_elt, rv) {
        if ((dst_elt = of_queue_stats_entry_OF_VERSION_1_2_dup(&src_elt)) == NULL) {
            of_object_delete((of_object_t *)dst);
            return NULL;
        }
        _TRY_FREE(of_list_queue_stats_entry_append(dst, dst_elt),
            dst, NULL);
        of_object_delete((of_object_t *)dst_elt);
    }

    return dst;
}

/**
 * Duplicate a list of type of_list_table_stats_entry
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_list_table_stats_entry.
 *
 * The caller is responsible for deleting the returned value
 */
of_list_table_stats_entry_t *
of_list_table_stats_entry_OF_VERSION_1_2_dup(
    of_list_table_stats_entry_t *src)
{
    of_table_stats_entry_t src_elt;
    of_table_stats_entry_t *dst_elt;
    int rv;
    of_list_table_stats_entry_t *dst;

    if ((dst = of_list_table_stats_entry_new(src->version)) == NULL) {
        return NULL;
    }

    OF_LIST_TABLE_STATS_ENTRY_ITER(src, &src_elt, rv) {
        if ((dst_elt = of_table_stats_entry_OF_VERSION_1_2_dup(&src_elt)) == NULL) {
            of_object_delete((of_object_t *)dst);
            return NULL;
        }
        _TRY_FREE(of_list_table_stats_entry_append(dst, dst_elt),
            dst, NULL);
        of_object_delete((of_object_t *)dst_elt);
    }

    return dst;
}

/**
 * Duplicate an object of type of_aggregate_stats_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_aggregate_stats_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_aggregate_stats_reply_t *
of_aggregate_stats_reply_OF_VERSION_1_3_dup(
    of_aggregate_stats_reply_t *src)
{
    of_aggregate_stats_reply_t *dst;
    uint32_t val32;
    uint16_t val16;
    uint64_t val64;

    if ((dst = of_aggregate_stats_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_aggregate_stats_reply_xid_get(src, &val32);
    of_aggregate_stats_reply_xid_set(dst, val32);

    of_aggregate_stats_reply_flags_get(src, &val16);
    of_aggregate_stats_reply_flags_set(dst, val16);

    of_aggregate_stats_reply_packet_count_get(src, &val64);
    of_aggregate_stats_reply_packet_count_set(dst, val64);

    of_aggregate_stats_reply_byte_count_get(src, &val64);
    of_aggregate_stats_reply_byte_count_set(dst, val64);

    of_aggregate_stats_reply_flow_count_get(src, &val32);
    of_aggregate_stats_reply_flow_count_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_aggregate_stats_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_aggregate_stats_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_aggregate_stats_request_t *
of_aggregate_stats_request_OF_VERSION_1_3_dup(
    of_aggregate_stats_request_t *src)
{
    of_aggregate_stats_request_t *dst;
    uint32_t val32;
    uint16_t val16;
    uint8_t val8;
    of_port_no_t port_no;
    uint64_t val64;
    of_match_t match;

    if ((dst = of_aggregate_stats_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_aggregate_stats_request_xid_get(src, &val32);
    of_aggregate_stats_request_xid_set(dst, val32);

    of_aggregate_stats_request_flags_get(src, &val16);
    of_aggregate_stats_request_flags_set(dst, val16);

    of_aggregate_stats_request_table_id_get(src, &val8);
    of_aggregate_stats_request_table_id_set(dst, val8);

    of_aggregate_stats_request_out_port_get(src, &port_no);
    of_aggregate_stats_request_out_port_set(dst, port_no);

    of_aggregate_stats_request_out_group_get(src, &val32);
    of_aggregate_stats_request_out_group_set(dst, val32);

    of_aggregate_stats_request_cookie_get(src, &val64);
    of_aggregate_stats_request_cookie_set(dst, val64);

    of_aggregate_stats_request_cookie_mask_get(src, &val64);
    of_aggregate_stats_request_cookie_mask_set(dst, val64);

    of_aggregate_stats_request_match_get(src, &match);
    of_aggregate_stats_request_match_set(dst, &match);

    return dst;
}

/**
 * Duplicate an object of type of_async_get_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_async_get_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_async_get_reply_t *
of_async_get_reply_OF_VERSION_1_3_dup(
    of_async_get_reply_t *src)
{
    of_async_get_reply_t *dst;
    uint32_t val32;

    if ((dst = of_async_get_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_async_get_reply_xid_get(src, &val32);
    of_async_get_reply_xid_set(dst, val32);

    of_async_get_reply_packet_in_mask_equal_master_get(src, &val32);
    of_async_get_reply_packet_in_mask_equal_master_set(dst, val32);

    of_async_get_reply_packet_in_mask_slave_get(src, &val32);
    of_async_get_reply_packet_in_mask_slave_set(dst, val32);

    of_async_get_reply_port_status_mask_equal_master_get(src, &val32);
    of_async_get_reply_port_status_mask_equal_master_set(dst, val32);

    of_async_get_reply_port_status_mask_slave_get(src, &val32);
    of_async_get_reply_port_status_mask_slave_set(dst, val32);

    of_async_get_reply_flow_removed_mask_equal_master_get(src, &val32);
    of_async_get_reply_flow_removed_mask_equal_master_set(dst, val32);

    of_async_get_reply_flow_removed_mask_slave_get(src, &val32);
    of_async_get_reply_flow_removed_mask_slave_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_async_get_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_async_get_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_async_get_request_t *
of_async_get_request_OF_VERSION_1_3_dup(
    of_async_get_request_t *src)
{
    of_async_get_request_t *dst;
    uint32_t val32;

    if ((dst = of_async_get_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_async_get_request_xid_get(src, &val32);
    of_async_get_request_xid_set(dst, val32);

    of_async_get_request_packet_in_mask_equal_master_get(src, &val32);
    of_async_get_request_packet_in_mask_equal_master_set(dst, val32);

    of_async_get_request_packet_in_mask_slave_get(src, &val32);
    of_async_get_request_packet_in_mask_slave_set(dst, val32);

    of_async_get_request_port_status_mask_equal_master_get(src, &val32);
    of_async_get_request_port_status_mask_equal_master_set(dst, val32);

    of_async_get_request_port_status_mask_slave_get(src, &val32);
    of_async_get_request_port_status_mask_slave_set(dst, val32);

    of_async_get_request_flow_removed_mask_equal_master_get(src, &val32);
    of_async_get_request_flow_removed_mask_equal_master_set(dst, val32);

    of_async_get_request_flow_removed_mask_slave_get(src, &val32);
    of_async_get_request_flow_removed_mask_slave_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_async_set
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_async_set.
 *
 * The caller is responsible for deleting the returned value
 */
of_async_set_t *
of_async_set_OF_VERSION_1_3_dup(
    of_async_set_t *src)
{
    of_async_set_t *dst;
    uint32_t val32;

    if ((dst = of_async_set_new(src->version)) == NULL) {
        return NULL;
    }

    of_async_set_xid_get(src, &val32);
    of_async_set_xid_set(dst, val32);

    of_async_set_packet_in_mask_equal_master_get(src, &val32);
    of_async_set_packet_in_mask_equal_master_set(dst, val32);

    of_async_set_packet_in_mask_slave_get(src, &val32);
    of_async_set_packet_in_mask_slave_set(dst, val32);

    of_async_set_port_status_mask_equal_master_get(src, &val32);
    of_async_set_port_status_mask_equal_master_set(dst, val32);

    of_async_set_port_status_mask_slave_get(src, &val32);
    of_async_set_port_status_mask_slave_set(dst, val32);

    of_async_set_flow_removed_mask_equal_master_get(src, &val32);
    of_async_set_flow_removed_mask_equal_master_set(dst, val32);

    of_async_set_flow_removed_mask_slave_get(src, &val32);
    of_async_set_flow_removed_mask_slave_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_bad_action_error_msg
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bad_action_error_msg.
 *
 * The caller is responsible for deleting the returned value
 */
of_bad_action_error_msg_t *
of_bad_action_error_msg_OF_VERSION_1_3_dup(
    of_bad_action_error_msg_t *src)
{
    of_bad_action_error_msg_t *dst;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    if ((dst = of_bad_action_error_msg_new(src->version)) == NULL) {
        return NULL;
    }

    of_bad_action_error_msg_xid_get(src, &val32);
    of_bad_action_error_msg_xid_set(dst, val32);

    of_bad_action_error_msg_code_get(src, &val16);
    of_bad_action_error_msg_code_set(dst, val16);

    of_bad_action_error_msg_data_get(src, &octets);
    of_bad_action_error_msg_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_bad_instruction_error_msg
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bad_instruction_error_msg.
 *
 * The caller is responsible for deleting the returned value
 */
of_bad_instruction_error_msg_t *
of_bad_instruction_error_msg_OF_VERSION_1_3_dup(
    of_bad_instruction_error_msg_t *src)
{
    of_bad_instruction_error_msg_t *dst;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    if ((dst = of_bad_instruction_error_msg_new(src->version)) == NULL) {
        return NULL;
    }

    of_bad_instruction_error_msg_xid_get(src, &val32);
    of_bad_instruction_error_msg_xid_set(dst, val32);

    of_bad_instruction_error_msg_code_get(src, &val16);
    of_bad_instruction_error_msg_code_set(dst, val16);

    of_bad_instruction_error_msg_data_get(src, &octets);
    of_bad_instruction_error_msg_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_bad_match_error_msg
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bad_match_error_msg.
 *
 * The caller is responsible for deleting the returned value
 */
of_bad_match_error_msg_t *
of_bad_match_error_msg_OF_VERSION_1_3_dup(
    of_bad_match_error_msg_t *src)
{
    of_bad_match_error_msg_t *dst;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    if ((dst = of_bad_match_error_msg_new(src->version)) == NULL) {
        return NULL;
    }

    of_bad_match_error_msg_xid_get(src, &val32);
    of_bad_match_error_msg_xid_set(dst, val32);

    of_bad_match_error_msg_code_get(src, &val16);
    of_bad_match_error_msg_code_set(dst, val16);

    of_bad_match_error_msg_data_get(src, &octets);
    of_bad_match_error_msg_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_bad_request_error_msg
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bad_request_error_msg.
 *
 * The caller is responsible for deleting the returned value
 */
of_bad_request_error_msg_t *
of_bad_request_error_msg_OF_VERSION_1_3_dup(
    of_bad_request_error_msg_t *src)
{
    of_bad_request_error_msg_t *dst;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    if ((dst = of_bad_request_error_msg_new(src->version)) == NULL) {
        return NULL;
    }

    of_bad_request_error_msg_xid_get(src, &val32);
    of_bad_request_error_msg_xid_set(dst, val32);

    of_bad_request_error_msg_code_get(src, &val16);
    of_bad_request_error_msg_code_set(dst, val16);

    of_bad_request_error_msg_data_get(src, &octets);
    of_bad_request_error_msg_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_barrier_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_barrier_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_barrier_reply_t *
of_barrier_reply_OF_VERSION_1_3_dup(
    of_barrier_reply_t *src)
{
    of_barrier_reply_t *dst;
    uint32_t val32;

    if ((dst = of_barrier_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_barrier_reply_xid_get(src, &val32);
    of_barrier_reply_xid_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_barrier_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_barrier_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_barrier_request_t *
of_barrier_request_OF_VERSION_1_3_dup(
    of_barrier_request_t *src)
{
    of_barrier_request_t *dst;
    uint32_t val32;

    if ((dst = of_barrier_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_barrier_request_xid_get(src, &val32);
    of_barrier_request_xid_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_bw_clear_data_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_bw_clear_data_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_bw_clear_data_reply_t *
of_bsn_bw_clear_data_reply_OF_VERSION_1_3_dup(
    of_bsn_bw_clear_data_reply_t *src)
{
    of_bsn_bw_clear_data_reply_t *dst;
    uint32_t val32;

    if ((dst = of_bsn_bw_clear_data_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_bw_clear_data_reply_xid_get(src, &val32);
    of_bsn_bw_clear_data_reply_xid_set(dst, val32);

    of_bsn_bw_clear_data_reply_experimenter_get(src, &val32);
    of_bsn_bw_clear_data_reply_experimenter_set(dst, val32);

    of_bsn_bw_clear_data_reply_subtype_get(src, &val32);
    of_bsn_bw_clear_data_reply_subtype_set(dst, val32);

    of_bsn_bw_clear_data_reply_status_get(src, &val32);
    of_bsn_bw_clear_data_reply_status_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_bw_clear_data_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_bw_clear_data_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_bw_clear_data_request_t *
of_bsn_bw_clear_data_request_OF_VERSION_1_3_dup(
    of_bsn_bw_clear_data_request_t *src)
{
    of_bsn_bw_clear_data_request_t *dst;
    uint32_t val32;

    if ((dst = of_bsn_bw_clear_data_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_bw_clear_data_request_xid_get(src, &val32);
    of_bsn_bw_clear_data_request_xid_set(dst, val32);

    of_bsn_bw_clear_data_request_experimenter_get(src, &val32);
    of_bsn_bw_clear_data_request_experimenter_set(dst, val32);

    of_bsn_bw_clear_data_request_subtype_get(src, &val32);
    of_bsn_bw_clear_data_request_subtype_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_bw_enable_get_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_bw_enable_get_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_bw_enable_get_reply_t *
of_bsn_bw_enable_get_reply_OF_VERSION_1_3_dup(
    of_bsn_bw_enable_get_reply_t *src)
{
    of_bsn_bw_enable_get_reply_t *dst;
    uint32_t val32;

    if ((dst = of_bsn_bw_enable_get_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_bw_enable_get_reply_xid_get(src, &val32);
    of_bsn_bw_enable_get_reply_xid_set(dst, val32);

    of_bsn_bw_enable_get_reply_experimenter_get(src, &val32);
    of_bsn_bw_enable_get_reply_experimenter_set(dst, val32);

    of_bsn_bw_enable_get_reply_subtype_get(src, &val32);
    of_bsn_bw_enable_get_reply_subtype_set(dst, val32);

    of_bsn_bw_enable_get_reply_enabled_get(src, &val32);
    of_bsn_bw_enable_get_reply_enabled_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_bw_enable_get_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_bw_enable_get_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_bw_enable_get_request_t *
of_bsn_bw_enable_get_request_OF_VERSION_1_3_dup(
    of_bsn_bw_enable_get_request_t *src)
{
    of_bsn_bw_enable_get_request_t *dst;
    uint32_t val32;

    if ((dst = of_bsn_bw_enable_get_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_bw_enable_get_request_xid_get(src, &val32);
    of_bsn_bw_enable_get_request_xid_set(dst, val32);

    of_bsn_bw_enable_get_request_experimenter_get(src, &val32);
    of_bsn_bw_enable_get_request_experimenter_set(dst, val32);

    of_bsn_bw_enable_get_request_subtype_get(src, &val32);
    of_bsn_bw_enable_get_request_subtype_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_bw_enable_set_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_bw_enable_set_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_bw_enable_set_reply_t *
of_bsn_bw_enable_set_reply_OF_VERSION_1_3_dup(
    of_bsn_bw_enable_set_reply_t *src)
{
    of_bsn_bw_enable_set_reply_t *dst;
    uint32_t val32;

    if ((dst = of_bsn_bw_enable_set_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_bw_enable_set_reply_xid_get(src, &val32);
    of_bsn_bw_enable_set_reply_xid_set(dst, val32);

    of_bsn_bw_enable_set_reply_experimenter_get(src, &val32);
    of_bsn_bw_enable_set_reply_experimenter_set(dst, val32);

    of_bsn_bw_enable_set_reply_subtype_get(src, &val32);
    of_bsn_bw_enable_set_reply_subtype_set(dst, val32);

    of_bsn_bw_enable_set_reply_enable_get(src, &val32);
    of_bsn_bw_enable_set_reply_enable_set(dst, val32);

    of_bsn_bw_enable_set_reply_status_get(src, &val32);
    of_bsn_bw_enable_set_reply_status_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_bw_enable_set_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_bw_enable_set_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_bw_enable_set_request_t *
of_bsn_bw_enable_set_request_OF_VERSION_1_3_dup(
    of_bsn_bw_enable_set_request_t *src)
{
    of_bsn_bw_enable_set_request_t *dst;
    uint32_t val32;

    if ((dst = of_bsn_bw_enable_set_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_bw_enable_set_request_xid_get(src, &val32);
    of_bsn_bw_enable_set_request_xid_set(dst, val32);

    of_bsn_bw_enable_set_request_experimenter_get(src, &val32);
    of_bsn_bw_enable_set_request_experimenter_set(dst, val32);

    of_bsn_bw_enable_set_request_subtype_get(src, &val32);
    of_bsn_bw_enable_set_request_subtype_set(dst, val32);

    of_bsn_bw_enable_set_request_enable_get(src, &val32);
    of_bsn_bw_enable_set_request_enable_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_flow_idle
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_flow_idle.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_flow_idle_t *
of_bsn_flow_idle_OF_VERSION_1_3_dup(
    of_bsn_flow_idle_t *src)
{
    of_bsn_flow_idle_t *dst;
    uint32_t val32;
    uint64_t val64;
    uint16_t val16;
    uint8_t val8;
    of_match_t match;

    if ((dst = of_bsn_flow_idle_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_flow_idle_xid_get(src, &val32);
    of_bsn_flow_idle_xid_set(dst, val32);

    of_bsn_flow_idle_experimenter_get(src, &val32);
    of_bsn_flow_idle_experimenter_set(dst, val32);

    of_bsn_flow_idle_subtype_get(src, &val32);
    of_bsn_flow_idle_subtype_set(dst, val32);

    of_bsn_flow_idle_cookie_get(src, &val64);
    of_bsn_flow_idle_cookie_set(dst, val64);

    of_bsn_flow_idle_priority_get(src, &val16);
    of_bsn_flow_idle_priority_set(dst, val16);

    of_bsn_flow_idle_table_id_get(src, &val8);
    of_bsn_flow_idle_table_id_set(dst, val8);

    of_bsn_flow_idle_match_get(src, &match);
    of_bsn_flow_idle_match_set(dst, &match);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_flow_idle_enable_get_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_flow_idle_enable_get_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_flow_idle_enable_get_reply_t *
of_bsn_flow_idle_enable_get_reply_OF_VERSION_1_3_dup(
    of_bsn_flow_idle_enable_get_reply_t *src)
{
    of_bsn_flow_idle_enable_get_reply_t *dst;
    uint32_t val32;

    if ((dst = of_bsn_flow_idle_enable_get_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_flow_idle_enable_get_reply_xid_get(src, &val32);
    of_bsn_flow_idle_enable_get_reply_xid_set(dst, val32);

    of_bsn_flow_idle_enable_get_reply_experimenter_get(src, &val32);
    of_bsn_flow_idle_enable_get_reply_experimenter_set(dst, val32);

    of_bsn_flow_idle_enable_get_reply_subtype_get(src, &val32);
    of_bsn_flow_idle_enable_get_reply_subtype_set(dst, val32);

    of_bsn_flow_idle_enable_get_reply_enabled_get(src, &val32);
    of_bsn_flow_idle_enable_get_reply_enabled_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_flow_idle_enable_get_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_flow_idle_enable_get_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_flow_idle_enable_get_request_t *
of_bsn_flow_idle_enable_get_request_OF_VERSION_1_3_dup(
    of_bsn_flow_idle_enable_get_request_t *src)
{
    of_bsn_flow_idle_enable_get_request_t *dst;
    uint32_t val32;

    if ((dst = of_bsn_flow_idle_enable_get_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_flow_idle_enable_get_request_xid_get(src, &val32);
    of_bsn_flow_idle_enable_get_request_xid_set(dst, val32);

    of_bsn_flow_idle_enable_get_request_experimenter_get(src, &val32);
    of_bsn_flow_idle_enable_get_request_experimenter_set(dst, val32);

    of_bsn_flow_idle_enable_get_request_subtype_get(src, &val32);
    of_bsn_flow_idle_enable_get_request_subtype_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_flow_idle_enable_set_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_flow_idle_enable_set_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_flow_idle_enable_set_reply_t *
of_bsn_flow_idle_enable_set_reply_OF_VERSION_1_3_dup(
    of_bsn_flow_idle_enable_set_reply_t *src)
{
    of_bsn_flow_idle_enable_set_reply_t *dst;
    uint32_t val32;

    if ((dst = of_bsn_flow_idle_enable_set_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_flow_idle_enable_set_reply_xid_get(src, &val32);
    of_bsn_flow_idle_enable_set_reply_xid_set(dst, val32);

    of_bsn_flow_idle_enable_set_reply_experimenter_get(src, &val32);
    of_bsn_flow_idle_enable_set_reply_experimenter_set(dst, val32);

    of_bsn_flow_idle_enable_set_reply_subtype_get(src, &val32);
    of_bsn_flow_idle_enable_set_reply_subtype_set(dst, val32);

    of_bsn_flow_idle_enable_set_reply_enable_get(src, &val32);
    of_bsn_flow_idle_enable_set_reply_enable_set(dst, val32);

    of_bsn_flow_idle_enable_set_reply_status_get(src, &val32);
    of_bsn_flow_idle_enable_set_reply_status_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_flow_idle_enable_set_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_flow_idle_enable_set_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_flow_idle_enable_set_request_t *
of_bsn_flow_idle_enable_set_request_OF_VERSION_1_3_dup(
    of_bsn_flow_idle_enable_set_request_t *src)
{
    of_bsn_flow_idle_enable_set_request_t *dst;
    uint32_t val32;

    if ((dst = of_bsn_flow_idle_enable_set_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_flow_idle_enable_set_request_xid_get(src, &val32);
    of_bsn_flow_idle_enable_set_request_xid_set(dst, val32);

    of_bsn_flow_idle_enable_set_request_experimenter_get(src, &val32);
    of_bsn_flow_idle_enable_set_request_experimenter_set(dst, val32);

    of_bsn_flow_idle_enable_set_request_subtype_get(src, &val32);
    of_bsn_flow_idle_enable_set_request_subtype_set(dst, val32);

    of_bsn_flow_idle_enable_set_request_enable_get(src, &val32);
    of_bsn_flow_idle_enable_set_request_enable_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_get_interfaces_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_get_interfaces_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_get_interfaces_reply_t *
of_bsn_get_interfaces_reply_OF_VERSION_1_3_dup(
    of_bsn_get_interfaces_reply_t *src)
{
    of_bsn_get_interfaces_reply_t *dst;
    uint32_t val32;

    of_list_bsn_interface_t src_list;
    of_list_bsn_interface_t *dst_list;

    if ((dst = of_bsn_get_interfaces_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_get_interfaces_reply_xid_get(src, &val32);
    of_bsn_get_interfaces_reply_xid_set(dst, val32);

    of_bsn_get_interfaces_reply_experimenter_get(src, &val32);
    of_bsn_get_interfaces_reply_experimenter_set(dst, val32);

    of_bsn_get_interfaces_reply_subtype_get(src, &val32);
    of_bsn_get_interfaces_reply_subtype_set(dst, val32);

    of_bsn_get_interfaces_reply_interfaces_bind(
        src, &src_list);
    dst_list = of_list_bsn_interface_OF_VERSION_1_3_dup(&src_list);
    if (dst_list == NULL) {
        of_bsn_get_interfaces_reply_delete(dst);
        return NULL;
    }
    of_bsn_get_interfaces_reply_interfaces_set(dst, dst_list);
    of_list_bsn_interface_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_get_interfaces_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_get_interfaces_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_get_interfaces_request_t *
of_bsn_get_interfaces_request_OF_VERSION_1_3_dup(
    of_bsn_get_interfaces_request_t *src)
{
    of_bsn_get_interfaces_request_t *dst;
    uint32_t val32;

    if ((dst = of_bsn_get_interfaces_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_get_interfaces_request_xid_get(src, &val32);
    of_bsn_get_interfaces_request_xid_set(dst, val32);

    of_bsn_get_interfaces_request_experimenter_get(src, &val32);
    of_bsn_get_interfaces_request_experimenter_set(dst, val32);

    of_bsn_get_interfaces_request_subtype_get(src, &val32);
    of_bsn_get_interfaces_request_subtype_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_get_mirroring_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_get_mirroring_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_get_mirroring_reply_t *
of_bsn_get_mirroring_reply_OF_VERSION_1_3_dup(
    of_bsn_get_mirroring_reply_t *src)
{
    of_bsn_get_mirroring_reply_t *dst;
    uint32_t val32;
    uint8_t val8;

    if ((dst = of_bsn_get_mirroring_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_get_mirroring_reply_xid_get(src, &val32);
    of_bsn_get_mirroring_reply_xid_set(dst, val32);

    of_bsn_get_mirroring_reply_experimenter_get(src, &val32);
    of_bsn_get_mirroring_reply_experimenter_set(dst, val32);

    of_bsn_get_mirroring_reply_subtype_get(src, &val32);
    of_bsn_get_mirroring_reply_subtype_set(dst, val32);

    of_bsn_get_mirroring_reply_report_mirror_ports_get(src, &val8);
    of_bsn_get_mirroring_reply_report_mirror_ports_set(dst, val8);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_get_mirroring_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_get_mirroring_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_get_mirroring_request_t *
of_bsn_get_mirroring_request_OF_VERSION_1_3_dup(
    of_bsn_get_mirroring_request_t *src)
{
    of_bsn_get_mirroring_request_t *dst;
    uint32_t val32;
    uint8_t val8;

    if ((dst = of_bsn_get_mirroring_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_get_mirroring_request_xid_get(src, &val32);
    of_bsn_get_mirroring_request_xid_set(dst, val32);

    of_bsn_get_mirroring_request_experimenter_get(src, &val32);
    of_bsn_get_mirroring_request_experimenter_set(dst, val32);

    of_bsn_get_mirroring_request_subtype_get(src, &val32);
    of_bsn_get_mirroring_request_subtype_set(dst, val32);

    of_bsn_get_mirroring_request_report_mirror_ports_get(src, &val8);
    of_bsn_get_mirroring_request_report_mirror_ports_set(dst, val8);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_header
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_header.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_header_t *
of_bsn_header_OF_VERSION_1_3_dup(
    of_bsn_header_t *src)
{
    of_bsn_header_t *dst;
    uint32_t val32;

    if ((dst = of_bsn_header_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_header_xid_get(src, &val32);
    of_bsn_header_xid_set(dst, val32);

    of_bsn_header_experimenter_get(src, &val32);
    of_bsn_header_experimenter_set(dst, val32);

    of_bsn_header_subtype_get(src, &val32);
    of_bsn_header_subtype_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_pdu_rx_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_pdu_rx_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_pdu_rx_reply_t *
of_bsn_pdu_rx_reply_OF_VERSION_1_3_dup(
    of_bsn_pdu_rx_reply_t *src)
{
    of_bsn_pdu_rx_reply_t *dst;
    uint32_t val32;

    if ((dst = of_bsn_pdu_rx_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_pdu_rx_reply_xid_get(src, &val32);
    of_bsn_pdu_rx_reply_xid_set(dst, val32);

    of_bsn_pdu_rx_reply_experimenter_get(src, &val32);
    of_bsn_pdu_rx_reply_experimenter_set(dst, val32);

    of_bsn_pdu_rx_reply_subtype_get(src, &val32);
    of_bsn_pdu_rx_reply_subtype_set(dst, val32);

    of_bsn_pdu_rx_reply_status_get(src, &val32);
    of_bsn_pdu_rx_reply_status_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_pdu_rx_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_pdu_rx_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_pdu_rx_request_t *
of_bsn_pdu_rx_request_OF_VERSION_1_3_dup(
    of_bsn_pdu_rx_request_t *src)
{
    of_bsn_pdu_rx_request_t *dst;
    uint32_t val32;
    of_port_no_t port_no;
    uint8_t val8;
    of_octets_t octets;

    if ((dst = of_bsn_pdu_rx_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_pdu_rx_request_xid_get(src, &val32);
    of_bsn_pdu_rx_request_xid_set(dst, val32);

    of_bsn_pdu_rx_request_experimenter_get(src, &val32);
    of_bsn_pdu_rx_request_experimenter_set(dst, val32);

    of_bsn_pdu_rx_request_subtype_get(src, &val32);
    of_bsn_pdu_rx_request_subtype_set(dst, val32);

    of_bsn_pdu_rx_request_timeout_ms_get(src, &val32);
    of_bsn_pdu_rx_request_timeout_ms_set(dst, val32);

    of_bsn_pdu_rx_request_port_no_get(src, &port_no);
    of_bsn_pdu_rx_request_port_no_set(dst, port_no);

    of_bsn_pdu_rx_request_slot_num_get(src, &val8);
    of_bsn_pdu_rx_request_slot_num_set(dst, val8);

    of_bsn_pdu_rx_request_data_get(src, &octets);
    of_bsn_pdu_rx_request_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_pdu_rx_timeout
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_pdu_rx_timeout.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_pdu_rx_timeout_t *
of_bsn_pdu_rx_timeout_OF_VERSION_1_3_dup(
    of_bsn_pdu_rx_timeout_t *src)
{
    of_bsn_pdu_rx_timeout_t *dst;
    uint32_t val32;
    of_port_no_t port_no;
    uint8_t val8;

    if ((dst = of_bsn_pdu_rx_timeout_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_pdu_rx_timeout_xid_get(src, &val32);
    of_bsn_pdu_rx_timeout_xid_set(dst, val32);

    of_bsn_pdu_rx_timeout_experimenter_get(src, &val32);
    of_bsn_pdu_rx_timeout_experimenter_set(dst, val32);

    of_bsn_pdu_rx_timeout_subtype_get(src, &val32);
    of_bsn_pdu_rx_timeout_subtype_set(dst, val32);

    of_bsn_pdu_rx_timeout_port_no_get(src, &port_no);
    of_bsn_pdu_rx_timeout_port_no_set(dst, port_no);

    of_bsn_pdu_rx_timeout_slot_num_get(src, &val8);
    of_bsn_pdu_rx_timeout_slot_num_set(dst, val8);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_pdu_tx_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_pdu_tx_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_pdu_tx_reply_t *
of_bsn_pdu_tx_reply_OF_VERSION_1_3_dup(
    of_bsn_pdu_tx_reply_t *src)
{
    of_bsn_pdu_tx_reply_t *dst;
    uint32_t val32;

    if ((dst = of_bsn_pdu_tx_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_pdu_tx_reply_xid_get(src, &val32);
    of_bsn_pdu_tx_reply_xid_set(dst, val32);

    of_bsn_pdu_tx_reply_experimenter_get(src, &val32);
    of_bsn_pdu_tx_reply_experimenter_set(dst, val32);

    of_bsn_pdu_tx_reply_subtype_get(src, &val32);
    of_bsn_pdu_tx_reply_subtype_set(dst, val32);

    of_bsn_pdu_tx_reply_status_get(src, &val32);
    of_bsn_pdu_tx_reply_status_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_pdu_tx_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_pdu_tx_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_pdu_tx_request_t *
of_bsn_pdu_tx_request_OF_VERSION_1_3_dup(
    of_bsn_pdu_tx_request_t *src)
{
    of_bsn_pdu_tx_request_t *dst;
    uint32_t val32;
    of_port_no_t port_no;
    uint8_t val8;
    of_octets_t octets;

    if ((dst = of_bsn_pdu_tx_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_pdu_tx_request_xid_get(src, &val32);
    of_bsn_pdu_tx_request_xid_set(dst, val32);

    of_bsn_pdu_tx_request_experimenter_get(src, &val32);
    of_bsn_pdu_tx_request_experimenter_set(dst, val32);

    of_bsn_pdu_tx_request_subtype_get(src, &val32);
    of_bsn_pdu_tx_request_subtype_set(dst, val32);

    of_bsn_pdu_tx_request_tx_interval_ms_get(src, &val32);
    of_bsn_pdu_tx_request_tx_interval_ms_set(dst, val32);

    of_bsn_pdu_tx_request_port_no_get(src, &port_no);
    of_bsn_pdu_tx_request_port_no_set(dst, port_no);

    of_bsn_pdu_tx_request_slot_num_get(src, &val8);
    of_bsn_pdu_tx_request_slot_num_set(dst, val8);

    of_bsn_pdu_tx_request_data_get(src, &octets);
    of_bsn_pdu_tx_request_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_set_mirroring
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_set_mirroring.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_set_mirroring_t *
of_bsn_set_mirroring_OF_VERSION_1_3_dup(
    of_bsn_set_mirroring_t *src)
{
    of_bsn_set_mirroring_t *dst;
    uint32_t val32;
    uint8_t val8;

    if ((dst = of_bsn_set_mirroring_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_set_mirroring_xid_get(src, &val32);
    of_bsn_set_mirroring_xid_set(dst, val32);

    of_bsn_set_mirroring_experimenter_get(src, &val32);
    of_bsn_set_mirroring_experimenter_set(dst, val32);

    of_bsn_set_mirroring_subtype_get(src, &val32);
    of_bsn_set_mirroring_subtype_set(dst, val32);

    of_bsn_set_mirroring_report_mirror_ports_get(src, &val8);
    of_bsn_set_mirroring_report_mirror_ports_set(dst, val8);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_set_pktin_suppression_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_set_pktin_suppression_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_set_pktin_suppression_reply_t *
of_bsn_set_pktin_suppression_reply_OF_VERSION_1_3_dup(
    of_bsn_set_pktin_suppression_reply_t *src)
{
    of_bsn_set_pktin_suppression_reply_t *dst;
    uint32_t val32;

    if ((dst = of_bsn_set_pktin_suppression_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_set_pktin_suppression_reply_xid_get(src, &val32);
    of_bsn_set_pktin_suppression_reply_xid_set(dst, val32);

    of_bsn_set_pktin_suppression_reply_experimenter_get(src, &val32);
    of_bsn_set_pktin_suppression_reply_experimenter_set(dst, val32);

    of_bsn_set_pktin_suppression_reply_subtype_get(src, &val32);
    of_bsn_set_pktin_suppression_reply_subtype_set(dst, val32);

    of_bsn_set_pktin_suppression_reply_status_get(src, &val32);
    of_bsn_set_pktin_suppression_reply_status_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_set_pktin_suppression_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_set_pktin_suppression_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_set_pktin_suppression_request_t *
of_bsn_set_pktin_suppression_request_OF_VERSION_1_3_dup(
    of_bsn_set_pktin_suppression_request_t *src)
{
    of_bsn_set_pktin_suppression_request_t *dst;
    uint32_t val32;
    uint8_t val8;
    uint16_t val16;
    uint64_t val64;

    if ((dst = of_bsn_set_pktin_suppression_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_set_pktin_suppression_request_xid_get(src, &val32);
    of_bsn_set_pktin_suppression_request_xid_set(dst, val32);

    of_bsn_set_pktin_suppression_request_experimenter_get(src, &val32);
    of_bsn_set_pktin_suppression_request_experimenter_set(dst, val32);

    of_bsn_set_pktin_suppression_request_subtype_get(src, &val32);
    of_bsn_set_pktin_suppression_request_subtype_set(dst, val32);

    of_bsn_set_pktin_suppression_request_enabled_get(src, &val8);
    of_bsn_set_pktin_suppression_request_enabled_set(dst, val8);

    of_bsn_set_pktin_suppression_request_idle_timeout_get(src, &val16);
    of_bsn_set_pktin_suppression_request_idle_timeout_set(dst, val16);

    of_bsn_set_pktin_suppression_request_hard_timeout_get(src, &val16);
    of_bsn_set_pktin_suppression_request_hard_timeout_set(dst, val16);

    of_bsn_set_pktin_suppression_request_priority_get(src, &val16);
    of_bsn_set_pktin_suppression_request_priority_set(dst, val16);

    of_bsn_set_pktin_suppression_request_cookie_get(src, &val64);
    of_bsn_set_pktin_suppression_request_cookie_set(dst, val64);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_virtual_port_create_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_virtual_port_create_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_virtual_port_create_reply_t *
of_bsn_virtual_port_create_reply_OF_VERSION_1_3_dup(
    of_bsn_virtual_port_create_reply_t *src)
{
    of_bsn_virtual_port_create_reply_t *dst;
    uint32_t val32;

    if ((dst = of_bsn_virtual_port_create_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_virtual_port_create_reply_xid_get(src, &val32);
    of_bsn_virtual_port_create_reply_xid_set(dst, val32);

    of_bsn_virtual_port_create_reply_experimenter_get(src, &val32);
    of_bsn_virtual_port_create_reply_experimenter_set(dst, val32);

    of_bsn_virtual_port_create_reply_subtype_get(src, &val32);
    of_bsn_virtual_port_create_reply_subtype_set(dst, val32);

    of_bsn_virtual_port_create_reply_status_get(src, &val32);
    of_bsn_virtual_port_create_reply_status_set(dst, val32);

    of_bsn_virtual_port_create_reply_vport_no_get(src, &val32);
    of_bsn_virtual_port_create_reply_vport_no_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_virtual_port_create_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_virtual_port_create_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_virtual_port_create_request_t *
of_bsn_virtual_port_create_request_OF_VERSION_1_3_dup(
    of_bsn_virtual_port_create_request_t *src)
{
    of_bsn_virtual_port_create_request_t *dst;
    uint32_t val32;

    of_bsn_vport_q_in_q_t src_vport;
    of_bsn_vport_q_in_q_t *dst_vport;

    if ((dst = of_bsn_virtual_port_create_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_virtual_port_create_request_xid_get(src, &val32);
    of_bsn_virtual_port_create_request_xid_set(dst, val32);

    of_bsn_virtual_port_create_request_experimenter_get(src, &val32);
    of_bsn_virtual_port_create_request_experimenter_set(dst, val32);

    of_bsn_virtual_port_create_request_subtype_get(src, &val32);
    of_bsn_virtual_port_create_request_subtype_set(dst, val32);

    of_bsn_virtual_port_create_request_vport_bind(
        src, &src_vport);
    dst_vport = of_bsn_vport_q_in_q_OF_VERSION_1_3_dup(&src_vport);
    if (dst_vport == NULL) {
        of_bsn_virtual_port_create_request_delete(dst);
        return NULL;
    }
    of_bsn_virtual_port_create_request_vport_set(dst, dst_vport);
    of_bsn_vport_q_in_q_delete(dst_vport);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_virtual_port_remove_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_virtual_port_remove_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_virtual_port_remove_reply_t *
of_bsn_virtual_port_remove_reply_OF_VERSION_1_3_dup(
    of_bsn_virtual_port_remove_reply_t *src)
{
    of_bsn_virtual_port_remove_reply_t *dst;
    uint32_t val32;

    if ((dst = of_bsn_virtual_port_remove_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_virtual_port_remove_reply_xid_get(src, &val32);
    of_bsn_virtual_port_remove_reply_xid_set(dst, val32);

    of_bsn_virtual_port_remove_reply_experimenter_get(src, &val32);
    of_bsn_virtual_port_remove_reply_experimenter_set(dst, val32);

    of_bsn_virtual_port_remove_reply_subtype_get(src, &val32);
    of_bsn_virtual_port_remove_reply_subtype_set(dst, val32);

    of_bsn_virtual_port_remove_reply_status_get(src, &val32);
    of_bsn_virtual_port_remove_reply_status_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_virtual_port_remove_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_virtual_port_remove_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_virtual_port_remove_request_t *
of_bsn_virtual_port_remove_request_OF_VERSION_1_3_dup(
    of_bsn_virtual_port_remove_request_t *src)
{
    of_bsn_virtual_port_remove_request_t *dst;
    uint32_t val32;

    if ((dst = of_bsn_virtual_port_remove_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_virtual_port_remove_request_xid_get(src, &val32);
    of_bsn_virtual_port_remove_request_xid_set(dst, val32);

    of_bsn_virtual_port_remove_request_experimenter_get(src, &val32);
    of_bsn_virtual_port_remove_request_experimenter_set(dst, val32);

    of_bsn_virtual_port_remove_request_subtype_get(src, &val32);
    of_bsn_virtual_port_remove_request_subtype_set(dst, val32);

    of_bsn_virtual_port_remove_request_vport_no_get(src, &val32);
    of_bsn_virtual_port_remove_request_vport_no_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_desc_stats_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_desc_stats_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_desc_stats_reply_t *
of_desc_stats_reply_OF_VERSION_1_3_dup(
    of_desc_stats_reply_t *src)
{
    of_desc_stats_reply_t *dst;
    uint32_t val32;
    uint16_t val16;
    of_desc_str_t desc_str;
    of_serial_num_t ser_num;

    if ((dst = of_desc_stats_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_desc_stats_reply_xid_get(src, &val32);
    of_desc_stats_reply_xid_set(dst, val32);

    of_desc_stats_reply_flags_get(src, &val16);
    of_desc_stats_reply_flags_set(dst, val16);

    of_desc_stats_reply_mfr_desc_get(src, &desc_str);
    of_desc_stats_reply_mfr_desc_set(dst, desc_str);

    of_desc_stats_reply_hw_desc_get(src, &desc_str);
    of_desc_stats_reply_hw_desc_set(dst, desc_str);

    of_desc_stats_reply_sw_desc_get(src, &desc_str);
    of_desc_stats_reply_sw_desc_set(dst, desc_str);

    of_desc_stats_reply_serial_num_get(src, &ser_num);
    of_desc_stats_reply_serial_num_set(dst, ser_num);

    of_desc_stats_reply_dp_desc_get(src, &desc_str);
    of_desc_stats_reply_dp_desc_set(dst, desc_str);

    return dst;
}

/**
 * Duplicate an object of type of_desc_stats_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_desc_stats_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_desc_stats_request_t *
of_desc_stats_request_OF_VERSION_1_3_dup(
    of_desc_stats_request_t *src)
{
    of_desc_stats_request_t *dst;
    uint32_t val32;
    uint16_t val16;

    if ((dst = of_desc_stats_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_desc_stats_request_xid_get(src, &val32);
    of_desc_stats_request_xid_set(dst, val32);

    of_desc_stats_request_flags_get(src, &val16);
    of_desc_stats_request_flags_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_echo_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_echo_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_echo_reply_t *
of_echo_reply_OF_VERSION_1_3_dup(
    of_echo_reply_t *src)
{
    of_echo_reply_t *dst;
    uint32_t val32;
    of_octets_t octets;

    if ((dst = of_echo_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_echo_reply_xid_get(src, &val32);
    of_echo_reply_xid_set(dst, val32);

    of_echo_reply_data_get(src, &octets);
    of_echo_reply_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_echo_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_echo_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_echo_request_t *
of_echo_request_OF_VERSION_1_3_dup(
    of_echo_request_t *src)
{
    of_echo_request_t *dst;
    uint32_t val32;
    of_octets_t octets;

    if ((dst = of_echo_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_echo_request_xid_get(src, &val32);
    of_echo_request_xid_set(dst, val32);

    of_echo_request_data_get(src, &octets);
    of_echo_request_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_error_msg
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_error_msg.
 *
 * The caller is responsible for deleting the returned value
 */
of_error_msg_t *
of_error_msg_OF_VERSION_1_3_dup(
    of_error_msg_t *src)
{
    of_error_msg_t *dst;
    uint32_t val32;

    if ((dst = of_error_msg_new(src->version)) == NULL) {
        return NULL;
    }

    of_error_msg_xid_get(src, &val32);
    of_error_msg_xid_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_experimenter
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_experimenter.
 *
 * The caller is responsible for deleting the returned value
 */
of_experimenter_t *
of_experimenter_OF_VERSION_1_3_dup(
    of_experimenter_t *src)
{
    of_experimenter_t *dst;
    uint32_t val32;
    of_octets_t octets;

    if ((dst = of_experimenter_new(src->version)) == NULL) {
        return NULL;
    }

    of_experimenter_xid_get(src, &val32);
    of_experimenter_xid_set(dst, val32);

    of_experimenter_experimenter_get(src, &val32);
    of_experimenter_experimenter_set(dst, val32);

    of_experimenter_subtype_get(src, &val32);
    of_experimenter_subtype_set(dst, val32);

    of_experimenter_data_get(src, &octets);
    of_experimenter_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_experimenter_error_msg
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_experimenter_error_msg.
 *
 * The caller is responsible for deleting the returned value
 */
of_experimenter_error_msg_t *
of_experimenter_error_msg_OF_VERSION_1_3_dup(
    of_experimenter_error_msg_t *src)
{
    of_experimenter_error_msg_t *dst;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    if ((dst = of_experimenter_error_msg_new(src->version)) == NULL) {
        return NULL;
    }

    of_experimenter_error_msg_xid_get(src, &val32);
    of_experimenter_error_msg_xid_set(dst, val32);

    of_experimenter_error_msg_subtype_get(src, &val16);
    of_experimenter_error_msg_subtype_set(dst, val16);

    of_experimenter_error_msg_experimenter_get(src, &val32);
    of_experimenter_error_msg_experimenter_set(dst, val32);

    of_experimenter_error_msg_data_get(src, &octets);
    of_experimenter_error_msg_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_features_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_features_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_features_reply_t *
of_features_reply_OF_VERSION_1_3_dup(
    of_features_reply_t *src)
{
    of_features_reply_t *dst;
    uint32_t val32;
    uint64_t val64;
    uint8_t val8;

    if ((dst = of_features_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_features_reply_xid_get(src, &val32);
    of_features_reply_xid_set(dst, val32);

    of_features_reply_datapath_id_get(src, &val64);
    of_features_reply_datapath_id_set(dst, val64);

    of_features_reply_n_buffers_get(src, &val32);
    of_features_reply_n_buffers_set(dst, val32);

    of_features_reply_n_tables_get(src, &val8);
    of_features_reply_n_tables_set(dst, val8);

    of_features_reply_auxiliary_id_get(src, &val8);
    of_features_reply_auxiliary_id_set(dst, val8);

    of_features_reply_capabilities_get(src, &val32);
    of_features_reply_capabilities_set(dst, val32);

    of_features_reply_reserved_get(src, &val32);
    of_features_reply_reserved_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_features_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_features_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_features_request_t *
of_features_request_OF_VERSION_1_3_dup(
    of_features_request_t *src)
{
    of_features_request_t *dst;
    uint32_t val32;

    if ((dst = of_features_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_features_request_xid_get(src, &val32);
    of_features_request_xid_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_flow_add
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_flow_add.
 *
 * The caller is responsible for deleting the returned value
 */
of_flow_add_t *
of_flow_add_OF_VERSION_1_3_dup(
    of_flow_add_t *src)
{
    of_flow_add_t *dst;
    uint32_t val32;
    uint64_t val64;
    uint8_t val8;
    uint16_t val16;
    of_port_no_t port_no;
    of_match_t match;

    of_list_instruction_t src_list;
    of_list_instruction_t *dst_list;

    if ((dst = of_flow_add_new(src->version)) == NULL) {
        return NULL;
    }

    of_flow_add_xid_get(src, &val32);
    of_flow_add_xid_set(dst, val32);

    of_flow_add_cookie_get(src, &val64);
    of_flow_add_cookie_set(dst, val64);

    of_flow_add_cookie_mask_get(src, &val64);
    of_flow_add_cookie_mask_set(dst, val64);

    of_flow_add_table_id_get(src, &val8);
    of_flow_add_table_id_set(dst, val8);

    of_flow_add_idle_timeout_get(src, &val16);
    of_flow_add_idle_timeout_set(dst, val16);

    of_flow_add_hard_timeout_get(src, &val16);
    of_flow_add_hard_timeout_set(dst, val16);

    of_flow_add_priority_get(src, &val16);
    of_flow_add_priority_set(dst, val16);

    of_flow_add_buffer_id_get(src, &val32);
    of_flow_add_buffer_id_set(dst, val32);

    of_flow_add_out_port_get(src, &port_no);
    of_flow_add_out_port_set(dst, port_no);

    of_flow_add_out_group_get(src, &val32);
    of_flow_add_out_group_set(dst, val32);

    of_flow_add_flags_get(src, &val16);
    of_flow_add_flags_set(dst, val16);

    of_flow_add_match_get(src, &match);
    of_flow_add_match_set(dst, &match);

    of_flow_add_instructions_bind(
        src, &src_list);
    dst_list = of_list_instruction_OF_VERSION_1_3_dup(&src_list);
    if (dst_list == NULL) {
        of_flow_add_delete(dst);
        return NULL;
    }
    of_flow_add_instructions_set(dst, dst_list);
    of_list_instruction_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_flow_delete
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_flow_delete.
 *
 * The caller is responsible for deleting the returned value
 */
of_flow_delete_t *
of_flow_delete_OF_VERSION_1_3_dup(
    of_flow_delete_t *src)
{
    of_flow_delete_t *dst;
    uint32_t val32;
    uint64_t val64;
    uint8_t val8;
    uint16_t val16;
    of_port_no_t port_no;
    of_match_t match;

    of_list_instruction_t src_list;
    of_list_instruction_t *dst_list;

    if ((dst = of_flow_delete_new(src->version)) == NULL) {
        return NULL;
    }

    of_flow_delete_xid_get(src, &val32);
    of_flow_delete_xid_set(dst, val32);

    of_flow_delete_cookie_get(src, &val64);
    of_flow_delete_cookie_set(dst, val64);

    of_flow_delete_cookie_mask_get(src, &val64);
    of_flow_delete_cookie_mask_set(dst, val64);

    of_flow_delete_table_id_get(src, &val8);
    of_flow_delete_table_id_set(dst, val8);

    of_flow_delete_idle_timeout_get(src, &val16);
    of_flow_delete_idle_timeout_set(dst, val16);

    of_flow_delete_hard_timeout_get(src, &val16);
    of_flow_delete_hard_timeout_set(dst, val16);

    of_flow_delete_priority_get(src, &val16);
    of_flow_delete_priority_set(dst, val16);

    of_flow_delete_buffer_id_get(src, &val32);
    of_flow_delete_buffer_id_set(dst, val32);

    of_flow_delete_out_port_get(src, &port_no);
    of_flow_delete_out_port_set(dst, port_no);

    of_flow_delete_out_group_get(src, &val32);
    of_flow_delete_out_group_set(dst, val32);

    of_flow_delete_flags_get(src, &val16);
    of_flow_delete_flags_set(dst, val16);

    of_flow_delete_match_get(src, &match);
    of_flow_delete_match_set(dst, &match);

    of_flow_delete_instructions_bind(
        src, &src_list);
    dst_list = of_list_instruction_OF_VERSION_1_3_dup(&src_list);
    if (dst_list == NULL) {
        of_flow_delete_delete(dst);
        return NULL;
    }
    of_flow_delete_instructions_set(dst, dst_list);
    of_list_instruction_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_flow_delete_strict
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_flow_delete_strict.
 *
 * The caller is responsible for deleting the returned value
 */
of_flow_delete_strict_t *
of_flow_delete_strict_OF_VERSION_1_3_dup(
    of_flow_delete_strict_t *src)
{
    of_flow_delete_strict_t *dst;
    uint32_t val32;
    uint64_t val64;
    uint8_t val8;
    uint16_t val16;
    of_port_no_t port_no;
    of_match_t match;

    of_list_instruction_t src_list;
    of_list_instruction_t *dst_list;

    if ((dst = of_flow_delete_strict_new(src->version)) == NULL) {
        return NULL;
    }

    of_flow_delete_strict_xid_get(src, &val32);
    of_flow_delete_strict_xid_set(dst, val32);

    of_flow_delete_strict_cookie_get(src, &val64);
    of_flow_delete_strict_cookie_set(dst, val64);

    of_flow_delete_strict_cookie_mask_get(src, &val64);
    of_flow_delete_strict_cookie_mask_set(dst, val64);

    of_flow_delete_strict_table_id_get(src, &val8);
    of_flow_delete_strict_table_id_set(dst, val8);

    of_flow_delete_strict_idle_timeout_get(src, &val16);
    of_flow_delete_strict_idle_timeout_set(dst, val16);

    of_flow_delete_strict_hard_timeout_get(src, &val16);
    of_flow_delete_strict_hard_timeout_set(dst, val16);

    of_flow_delete_strict_priority_get(src, &val16);
    of_flow_delete_strict_priority_set(dst, val16);

    of_flow_delete_strict_buffer_id_get(src, &val32);
    of_flow_delete_strict_buffer_id_set(dst, val32);

    of_flow_delete_strict_out_port_get(src, &port_no);
    of_flow_delete_strict_out_port_set(dst, port_no);

    of_flow_delete_strict_out_group_get(src, &val32);
    of_flow_delete_strict_out_group_set(dst, val32);

    of_flow_delete_strict_flags_get(src, &val16);
    of_flow_delete_strict_flags_set(dst, val16);

    of_flow_delete_strict_match_get(src, &match);
    of_flow_delete_strict_match_set(dst, &match);

    of_flow_delete_strict_instructions_bind(
        src, &src_list);
    dst_list = of_list_instruction_OF_VERSION_1_3_dup(&src_list);
    if (dst_list == NULL) {
        of_flow_delete_strict_delete(dst);
        return NULL;
    }
    of_flow_delete_strict_instructions_set(dst, dst_list);
    of_list_instruction_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_flow_mod
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_flow_mod.
 *
 * The caller is responsible for deleting the returned value
 */
of_flow_mod_t *
of_flow_mod_OF_VERSION_1_3_dup(
    of_flow_mod_t *src)
{
    of_flow_mod_t *dst;
    uint32_t val32;
    uint64_t val64;
    uint8_t val8;
    uint16_t val16;
    of_port_no_t port_no;
    of_match_t match;

    of_list_instruction_t src_list;
    of_list_instruction_t *dst_list;

    if ((dst = of_flow_mod_new(src->version)) == NULL) {
        return NULL;
    }

    of_flow_mod_xid_get(src, &val32);
    of_flow_mod_xid_set(dst, val32);

    of_flow_mod_cookie_get(src, &val64);
    of_flow_mod_cookie_set(dst, val64);

    of_flow_mod_cookie_mask_get(src, &val64);
    of_flow_mod_cookie_mask_set(dst, val64);

    of_flow_mod_table_id_get(src, &val8);
    of_flow_mod_table_id_set(dst, val8);

    of_flow_mod_idle_timeout_get(src, &val16);
    of_flow_mod_idle_timeout_set(dst, val16);

    of_flow_mod_hard_timeout_get(src, &val16);
    of_flow_mod_hard_timeout_set(dst, val16);

    of_flow_mod_priority_get(src, &val16);
    of_flow_mod_priority_set(dst, val16);

    of_flow_mod_buffer_id_get(src, &val32);
    of_flow_mod_buffer_id_set(dst, val32);

    of_flow_mod_out_port_get(src, &port_no);
    of_flow_mod_out_port_set(dst, port_no);

    of_flow_mod_out_group_get(src, &val32);
    of_flow_mod_out_group_set(dst, val32);

    of_flow_mod_flags_get(src, &val16);
    of_flow_mod_flags_set(dst, val16);

    of_flow_mod_match_get(src, &match);
    of_flow_mod_match_set(dst, &match);

    of_flow_mod_instructions_bind(
        src, &src_list);
    dst_list = of_list_instruction_OF_VERSION_1_3_dup(&src_list);
    if (dst_list == NULL) {
        of_flow_mod_delete(dst);
        return NULL;
    }
    of_flow_mod_instructions_set(dst, dst_list);
    of_list_instruction_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_flow_mod_failed_error_msg
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_flow_mod_failed_error_msg.
 *
 * The caller is responsible for deleting the returned value
 */
of_flow_mod_failed_error_msg_t *
of_flow_mod_failed_error_msg_OF_VERSION_1_3_dup(
    of_flow_mod_failed_error_msg_t *src)
{
    of_flow_mod_failed_error_msg_t *dst;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    if ((dst = of_flow_mod_failed_error_msg_new(src->version)) == NULL) {
        return NULL;
    }

    of_flow_mod_failed_error_msg_xid_get(src, &val32);
    of_flow_mod_failed_error_msg_xid_set(dst, val32);

    of_flow_mod_failed_error_msg_code_get(src, &val16);
    of_flow_mod_failed_error_msg_code_set(dst, val16);

    of_flow_mod_failed_error_msg_data_get(src, &octets);
    of_flow_mod_failed_error_msg_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_flow_modify
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_flow_modify.
 *
 * The caller is responsible for deleting the returned value
 */
of_flow_modify_t *
of_flow_modify_OF_VERSION_1_3_dup(
    of_flow_modify_t *src)
{
    of_flow_modify_t *dst;
    uint32_t val32;
    uint64_t val64;
    uint8_t val8;
    uint16_t val16;
    of_port_no_t port_no;
    of_match_t match;

    of_list_instruction_t src_list;
    of_list_instruction_t *dst_list;

    if ((dst = of_flow_modify_new(src->version)) == NULL) {
        return NULL;
    }

    of_flow_modify_xid_get(src, &val32);
    of_flow_modify_xid_set(dst, val32);

    of_flow_modify_cookie_get(src, &val64);
    of_flow_modify_cookie_set(dst, val64);

    of_flow_modify_cookie_mask_get(src, &val64);
    of_flow_modify_cookie_mask_set(dst, val64);

    of_flow_modify_table_id_get(src, &val8);
    of_flow_modify_table_id_set(dst, val8);

    of_flow_modify_idle_timeout_get(src, &val16);
    of_flow_modify_idle_timeout_set(dst, val16);

    of_flow_modify_hard_timeout_get(src, &val16);
    of_flow_modify_hard_timeout_set(dst, val16);

    of_flow_modify_priority_get(src, &val16);
    of_flow_modify_priority_set(dst, val16);

    of_flow_modify_buffer_id_get(src, &val32);
    of_flow_modify_buffer_id_set(dst, val32);

    of_flow_modify_out_port_get(src, &port_no);
    of_flow_modify_out_port_set(dst, port_no);

    of_flow_modify_out_group_get(src, &val32);
    of_flow_modify_out_group_set(dst, val32);

    of_flow_modify_flags_get(src, &val16);
    of_flow_modify_flags_set(dst, val16);

    of_flow_modify_match_get(src, &match);
    of_flow_modify_match_set(dst, &match);

    of_flow_modify_instructions_bind(
        src, &src_list);
    dst_list = of_list_instruction_OF_VERSION_1_3_dup(&src_list);
    if (dst_list == NULL) {
        of_flow_modify_delete(dst);
        return NULL;
    }
    of_flow_modify_instructions_set(dst, dst_list);
    of_list_instruction_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_flow_modify_strict
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_flow_modify_strict.
 *
 * The caller is responsible for deleting the returned value
 */
of_flow_modify_strict_t *
of_flow_modify_strict_OF_VERSION_1_3_dup(
    of_flow_modify_strict_t *src)
{
    of_flow_modify_strict_t *dst;
    uint32_t val32;
    uint64_t val64;
    uint8_t val8;
    uint16_t val16;
    of_port_no_t port_no;
    of_match_t match;

    of_list_instruction_t src_list;
    of_list_instruction_t *dst_list;

    if ((dst = of_flow_modify_strict_new(src->version)) == NULL) {
        return NULL;
    }

    of_flow_modify_strict_xid_get(src, &val32);
    of_flow_modify_strict_xid_set(dst, val32);

    of_flow_modify_strict_cookie_get(src, &val64);
    of_flow_modify_strict_cookie_set(dst, val64);

    of_flow_modify_strict_cookie_mask_get(src, &val64);
    of_flow_modify_strict_cookie_mask_set(dst, val64);

    of_flow_modify_strict_table_id_get(src, &val8);
    of_flow_modify_strict_table_id_set(dst, val8);

    of_flow_modify_strict_idle_timeout_get(src, &val16);
    of_flow_modify_strict_idle_timeout_set(dst, val16);

    of_flow_modify_strict_hard_timeout_get(src, &val16);
    of_flow_modify_strict_hard_timeout_set(dst, val16);

    of_flow_modify_strict_priority_get(src, &val16);
    of_flow_modify_strict_priority_set(dst, val16);

    of_flow_modify_strict_buffer_id_get(src, &val32);
    of_flow_modify_strict_buffer_id_set(dst, val32);

    of_flow_modify_strict_out_port_get(src, &port_no);
    of_flow_modify_strict_out_port_set(dst, port_no);

    of_flow_modify_strict_out_group_get(src, &val32);
    of_flow_modify_strict_out_group_set(dst, val32);

    of_flow_modify_strict_flags_get(src, &val16);
    of_flow_modify_strict_flags_set(dst, val16);

    of_flow_modify_strict_match_get(src, &match);
    of_flow_modify_strict_match_set(dst, &match);

    of_flow_modify_strict_instructions_bind(
        src, &src_list);
    dst_list = of_list_instruction_OF_VERSION_1_3_dup(&src_list);
    if (dst_list == NULL) {
        of_flow_modify_strict_delete(dst);
        return NULL;
    }
    of_flow_modify_strict_instructions_set(dst, dst_list);
    of_list_instruction_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_flow_removed
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_flow_removed.
 *
 * The caller is responsible for deleting the returned value
 */
of_flow_removed_t *
of_flow_removed_OF_VERSION_1_3_dup(
    of_flow_removed_t *src)
{
    of_flow_removed_t *dst;
    uint32_t val32;
    uint64_t val64;
    uint16_t val16;
    uint8_t val8;
    of_match_t match;

    if ((dst = of_flow_removed_new(src->version)) == NULL) {
        return NULL;
    }

    of_flow_removed_xid_get(src, &val32);
    of_flow_removed_xid_set(dst, val32);

    of_flow_removed_cookie_get(src, &val64);
    of_flow_removed_cookie_set(dst, val64);

    of_flow_removed_priority_get(src, &val16);
    of_flow_removed_priority_set(dst, val16);

    of_flow_removed_reason_get(src, &val8);
    of_flow_removed_reason_set(dst, val8);

    of_flow_removed_table_id_get(src, &val8);
    of_flow_removed_table_id_set(dst, val8);

    of_flow_removed_duration_sec_get(src, &val32);
    of_flow_removed_duration_sec_set(dst, val32);

    of_flow_removed_duration_nsec_get(src, &val32);
    of_flow_removed_duration_nsec_set(dst, val32);

    of_flow_removed_idle_timeout_get(src, &val16);
    of_flow_removed_idle_timeout_set(dst, val16);

    of_flow_removed_hard_timeout_get(src, &val16);
    of_flow_removed_hard_timeout_set(dst, val16);

    of_flow_removed_packet_count_get(src, &val64);
    of_flow_removed_packet_count_set(dst, val64);

    of_flow_removed_byte_count_get(src, &val64);
    of_flow_removed_byte_count_set(dst, val64);

    of_flow_removed_match_get(src, &match);
    of_flow_removed_match_set(dst, &match);

    return dst;
}

/**
 * Duplicate an object of type of_flow_stats_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_flow_stats_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_flow_stats_reply_t *
of_flow_stats_reply_OF_VERSION_1_3_dup(
    of_flow_stats_reply_t *src)
{
    of_flow_stats_reply_t *dst;
    uint32_t val32;
    uint16_t val16;

    of_list_flow_stats_entry_t src_list;
    of_list_flow_stats_entry_t *dst_list;

    if ((dst = of_flow_stats_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_flow_stats_reply_xid_get(src, &val32);
    of_flow_stats_reply_xid_set(dst, val32);

    of_flow_stats_reply_flags_get(src, &val16);
    of_flow_stats_reply_flags_set(dst, val16);

    of_flow_stats_reply_entries_bind(
        src, &src_list);
    dst_list = of_list_flow_stats_entry_OF_VERSION_1_3_dup(&src_list);
    if (dst_list == NULL) {
        of_flow_stats_reply_delete(dst);
        return NULL;
    }
    of_flow_stats_reply_entries_set(dst, dst_list);
    of_list_flow_stats_entry_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_flow_stats_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_flow_stats_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_flow_stats_request_t *
of_flow_stats_request_OF_VERSION_1_3_dup(
    of_flow_stats_request_t *src)
{
    of_flow_stats_request_t *dst;
    uint32_t val32;
    uint16_t val16;
    uint8_t val8;
    of_port_no_t port_no;
    uint64_t val64;
    of_match_t match;

    if ((dst = of_flow_stats_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_flow_stats_request_xid_get(src, &val32);
    of_flow_stats_request_xid_set(dst, val32);

    of_flow_stats_request_flags_get(src, &val16);
    of_flow_stats_request_flags_set(dst, val16);

    of_flow_stats_request_table_id_get(src, &val8);
    of_flow_stats_request_table_id_set(dst, val8);

    of_flow_stats_request_out_port_get(src, &port_no);
    of_flow_stats_request_out_port_set(dst, port_no);

    of_flow_stats_request_out_group_get(src, &val32);
    of_flow_stats_request_out_group_set(dst, val32);

    of_flow_stats_request_cookie_get(src, &val64);
    of_flow_stats_request_cookie_set(dst, val64);

    of_flow_stats_request_cookie_mask_get(src, &val64);
    of_flow_stats_request_cookie_mask_set(dst, val64);

    of_flow_stats_request_match_get(src, &match);
    of_flow_stats_request_match_set(dst, &match);

    return dst;
}

/**
 * Duplicate an object of type of_get_config_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_get_config_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_get_config_reply_t *
of_get_config_reply_OF_VERSION_1_3_dup(
    of_get_config_reply_t *src)
{
    of_get_config_reply_t *dst;
    uint32_t val32;
    uint16_t val16;

    if ((dst = of_get_config_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_get_config_reply_xid_get(src, &val32);
    of_get_config_reply_xid_set(dst, val32);

    of_get_config_reply_flags_get(src, &val16);
    of_get_config_reply_flags_set(dst, val16);

    of_get_config_reply_miss_send_len_get(src, &val16);
    of_get_config_reply_miss_send_len_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_get_config_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_get_config_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_get_config_request_t *
of_get_config_request_OF_VERSION_1_3_dup(
    of_get_config_request_t *src)
{
    of_get_config_request_t *dst;
    uint32_t val32;

    if ((dst = of_get_config_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_get_config_request_xid_get(src, &val32);
    of_get_config_request_xid_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_group_desc_stats_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_group_desc_stats_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_group_desc_stats_reply_t *
of_group_desc_stats_reply_OF_VERSION_1_3_dup(
    of_group_desc_stats_reply_t *src)
{
    of_group_desc_stats_reply_t *dst;
    uint32_t val32;
    uint16_t val16;

    of_list_group_desc_stats_entry_t src_list;
    of_list_group_desc_stats_entry_t *dst_list;

    if ((dst = of_group_desc_stats_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_group_desc_stats_reply_xid_get(src, &val32);
    of_group_desc_stats_reply_xid_set(dst, val32);

    of_group_desc_stats_reply_flags_get(src, &val16);
    of_group_desc_stats_reply_flags_set(dst, val16);

    of_group_desc_stats_reply_entries_bind(
        src, &src_list);
    dst_list = of_list_group_desc_stats_entry_OF_VERSION_1_3_dup(&src_list);
    if (dst_list == NULL) {
        of_group_desc_stats_reply_delete(dst);
        return NULL;
    }
    of_group_desc_stats_reply_entries_set(dst, dst_list);
    of_list_group_desc_stats_entry_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_group_desc_stats_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_group_desc_stats_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_group_desc_stats_request_t *
of_group_desc_stats_request_OF_VERSION_1_3_dup(
    of_group_desc_stats_request_t *src)
{
    of_group_desc_stats_request_t *dst;
    uint32_t val32;
    uint16_t val16;

    if ((dst = of_group_desc_stats_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_group_desc_stats_request_xid_get(src, &val32);
    of_group_desc_stats_request_xid_set(dst, val32);

    of_group_desc_stats_request_flags_get(src, &val16);
    of_group_desc_stats_request_flags_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_group_features_stats_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_group_features_stats_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_group_features_stats_reply_t *
of_group_features_stats_reply_OF_VERSION_1_3_dup(
    of_group_features_stats_reply_t *src)
{
    of_group_features_stats_reply_t *dst;
    uint32_t val32;
    uint16_t val16;

    if ((dst = of_group_features_stats_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_group_features_stats_reply_xid_get(src, &val32);
    of_group_features_stats_reply_xid_set(dst, val32);

    of_group_features_stats_reply_flags_get(src, &val16);
    of_group_features_stats_reply_flags_set(dst, val16);

    of_group_features_stats_reply_types_get(src, &val32);
    of_group_features_stats_reply_types_set(dst, val32);

    of_group_features_stats_reply_capabilities_get(src, &val32);
    of_group_features_stats_reply_capabilities_set(dst, val32);

    of_group_features_stats_reply_max_groups_all_get(src, &val32);
    of_group_features_stats_reply_max_groups_all_set(dst, val32);

    of_group_features_stats_reply_max_groups_select_get(src, &val32);
    of_group_features_stats_reply_max_groups_select_set(dst, val32);

    of_group_features_stats_reply_max_groups_indirect_get(src, &val32);
    of_group_features_stats_reply_max_groups_indirect_set(dst, val32);

    of_group_features_stats_reply_max_groups_ff_get(src, &val32);
    of_group_features_stats_reply_max_groups_ff_set(dst, val32);

    of_group_features_stats_reply_actions_all_get(src, &val32);
    of_group_features_stats_reply_actions_all_set(dst, val32);

    of_group_features_stats_reply_actions_select_get(src, &val32);
    of_group_features_stats_reply_actions_select_set(dst, val32);

    of_group_features_stats_reply_actions_indirect_get(src, &val32);
    of_group_features_stats_reply_actions_indirect_set(dst, val32);

    of_group_features_stats_reply_actions_ff_get(src, &val32);
    of_group_features_stats_reply_actions_ff_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_group_features_stats_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_group_features_stats_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_group_features_stats_request_t *
of_group_features_stats_request_OF_VERSION_1_3_dup(
    of_group_features_stats_request_t *src)
{
    of_group_features_stats_request_t *dst;
    uint32_t val32;
    uint16_t val16;

    if ((dst = of_group_features_stats_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_group_features_stats_request_xid_get(src, &val32);
    of_group_features_stats_request_xid_set(dst, val32);

    of_group_features_stats_request_flags_get(src, &val16);
    of_group_features_stats_request_flags_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_group_mod
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_group_mod.
 *
 * The caller is responsible for deleting the returned value
 */
of_group_mod_t *
of_group_mod_OF_VERSION_1_3_dup(
    of_group_mod_t *src)
{
    of_group_mod_t *dst;
    uint32_t val32;
    uint16_t val16;
    uint8_t val8;

    of_list_bucket_t src_list;
    of_list_bucket_t *dst_list;

    if ((dst = of_group_mod_new(src->version)) == NULL) {
        return NULL;
    }

    of_group_mod_xid_get(src, &val32);
    of_group_mod_xid_set(dst, val32);

    of_group_mod_command_get(src, &val16);
    of_group_mod_command_set(dst, val16);

    of_group_mod_group_type_get(src, &val8);
    of_group_mod_group_type_set(dst, val8);

    of_group_mod_group_id_get(src, &val32);
    of_group_mod_group_id_set(dst, val32);

    of_group_mod_buckets_bind(
        src, &src_list);
    dst_list = of_list_bucket_OF_VERSION_1_3_dup(&src_list);
    if (dst_list == NULL) {
        of_group_mod_delete(dst);
        return NULL;
    }
    of_group_mod_buckets_set(dst, dst_list);
    of_list_bucket_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_group_mod_failed_error_msg
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_group_mod_failed_error_msg.
 *
 * The caller is responsible for deleting the returned value
 */
of_group_mod_failed_error_msg_t *
of_group_mod_failed_error_msg_OF_VERSION_1_3_dup(
    of_group_mod_failed_error_msg_t *src)
{
    of_group_mod_failed_error_msg_t *dst;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    if ((dst = of_group_mod_failed_error_msg_new(src->version)) == NULL) {
        return NULL;
    }

    of_group_mod_failed_error_msg_xid_get(src, &val32);
    of_group_mod_failed_error_msg_xid_set(dst, val32);

    of_group_mod_failed_error_msg_code_get(src, &val16);
    of_group_mod_failed_error_msg_code_set(dst, val16);

    of_group_mod_failed_error_msg_data_get(src, &octets);
    of_group_mod_failed_error_msg_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_group_stats_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_group_stats_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_group_stats_reply_t *
of_group_stats_reply_OF_VERSION_1_3_dup(
    of_group_stats_reply_t *src)
{
    of_group_stats_reply_t *dst;
    uint32_t val32;
    uint16_t val16;

    of_list_group_stats_entry_t src_list;
    of_list_group_stats_entry_t *dst_list;

    if ((dst = of_group_stats_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_group_stats_reply_xid_get(src, &val32);
    of_group_stats_reply_xid_set(dst, val32);

    of_group_stats_reply_flags_get(src, &val16);
    of_group_stats_reply_flags_set(dst, val16);

    of_group_stats_reply_entries_bind(
        src, &src_list);
    dst_list = of_list_group_stats_entry_OF_VERSION_1_3_dup(&src_list);
    if (dst_list == NULL) {
        of_group_stats_reply_delete(dst);
        return NULL;
    }
    of_group_stats_reply_entries_set(dst, dst_list);
    of_list_group_stats_entry_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_group_stats_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_group_stats_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_group_stats_request_t *
of_group_stats_request_OF_VERSION_1_3_dup(
    of_group_stats_request_t *src)
{
    of_group_stats_request_t *dst;
    uint32_t val32;
    uint16_t val16;

    if ((dst = of_group_stats_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_group_stats_request_xid_get(src, &val32);
    of_group_stats_request_xid_set(dst, val32);

    of_group_stats_request_flags_get(src, &val16);
    of_group_stats_request_flags_set(dst, val16);

    of_group_stats_request_group_id_get(src, &val32);
    of_group_stats_request_group_id_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_hello
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_hello.
 *
 * The caller is responsible for deleting the returned value
 */
of_hello_t *
of_hello_OF_VERSION_1_3_dup(
    of_hello_t *src)
{
    of_hello_t *dst;
    uint32_t val32;

    of_list_hello_elem_t src_list;
    of_list_hello_elem_t *dst_list;

    if ((dst = of_hello_new(src->version)) == NULL) {
        return NULL;
    }

    of_hello_xid_get(src, &val32);
    of_hello_xid_set(dst, val32);

    of_hello_elements_bind(
        src, &src_list);
    dst_list = of_list_hello_elem_OF_VERSION_1_3_dup(&src_list);
    if (dst_list == NULL) {
        of_hello_delete(dst);
        return NULL;
    }
    of_hello_elements_set(dst, dst_list);
    of_list_hello_elem_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_hello_failed_error_msg
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_hello_failed_error_msg.
 *
 * The caller is responsible for deleting the returned value
 */
of_hello_failed_error_msg_t *
of_hello_failed_error_msg_OF_VERSION_1_3_dup(
    of_hello_failed_error_msg_t *src)
{
    of_hello_failed_error_msg_t *dst;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    if ((dst = of_hello_failed_error_msg_new(src->version)) == NULL) {
        return NULL;
    }

    of_hello_failed_error_msg_xid_get(src, &val32);
    of_hello_failed_error_msg_xid_set(dst, val32);

    of_hello_failed_error_msg_code_get(src, &val16);
    of_hello_failed_error_msg_code_set(dst, val16);

    of_hello_failed_error_msg_data_get(src, &octets);
    of_hello_failed_error_msg_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_meter_config_stats_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_meter_config_stats_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_meter_config_stats_reply_t *
of_meter_config_stats_reply_OF_VERSION_1_3_dup(
    of_meter_config_stats_reply_t *src)
{
    of_meter_config_stats_reply_t *dst;
    uint32_t val32;
    uint16_t val16;

    of_list_meter_band_t src_list;
    of_list_meter_band_t *dst_list;

    if ((dst = of_meter_config_stats_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_meter_config_stats_reply_xid_get(src, &val32);
    of_meter_config_stats_reply_xid_set(dst, val32);

    of_meter_config_stats_reply_flags_get(src, &val16);
    of_meter_config_stats_reply_flags_set(dst, val16);

    of_meter_config_stats_reply_entries_bind(
        src, &src_list);
    dst_list = of_list_meter_band_OF_VERSION_1_3_dup(&src_list);
    if (dst_list == NULL) {
        of_meter_config_stats_reply_delete(dst);
        return NULL;
    }
    of_meter_config_stats_reply_entries_set(dst, dst_list);
    of_list_meter_band_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_meter_config_stats_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_meter_config_stats_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_meter_config_stats_request_t *
of_meter_config_stats_request_OF_VERSION_1_3_dup(
    of_meter_config_stats_request_t *src)
{
    of_meter_config_stats_request_t *dst;
    uint32_t val32;
    uint16_t val16;

    if ((dst = of_meter_config_stats_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_meter_config_stats_request_xid_get(src, &val32);
    of_meter_config_stats_request_xid_set(dst, val32);

    of_meter_config_stats_request_flags_get(src, &val16);
    of_meter_config_stats_request_flags_set(dst, val16);

    of_meter_config_stats_request_meter_id_get(src, &val32);
    of_meter_config_stats_request_meter_id_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_meter_features_stats_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_meter_features_stats_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_meter_features_stats_reply_t *
of_meter_features_stats_reply_OF_VERSION_1_3_dup(
    of_meter_features_stats_reply_t *src)
{
    of_meter_features_stats_reply_t *dst;
    uint32_t val32;
    uint16_t val16;

    of_meter_features_t src_features;
    of_meter_features_t *dst_features;

    if ((dst = of_meter_features_stats_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_meter_features_stats_reply_xid_get(src, &val32);
    of_meter_features_stats_reply_xid_set(dst, val32);

    of_meter_features_stats_reply_flags_get(src, &val16);
    of_meter_features_stats_reply_flags_set(dst, val16);

    of_meter_features_stats_reply_features_bind(
        src, &src_features);
    dst_features = of_meter_features_OF_VERSION_1_3_dup(&src_features);
    if (dst_features == NULL) {
        of_meter_features_stats_reply_delete(dst);
        return NULL;
    }
    of_meter_features_stats_reply_features_set(dst, dst_features);
    of_meter_features_delete(dst_features);

    return dst;
}

/**
 * Duplicate an object of type of_meter_features_stats_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_meter_features_stats_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_meter_features_stats_request_t *
of_meter_features_stats_request_OF_VERSION_1_3_dup(
    of_meter_features_stats_request_t *src)
{
    of_meter_features_stats_request_t *dst;
    uint32_t val32;
    uint16_t val16;

    if ((dst = of_meter_features_stats_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_meter_features_stats_request_xid_get(src, &val32);
    of_meter_features_stats_request_xid_set(dst, val32);

    of_meter_features_stats_request_flags_get(src, &val16);
    of_meter_features_stats_request_flags_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_meter_mod
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_meter_mod.
 *
 * The caller is responsible for deleting the returned value
 */
of_meter_mod_t *
of_meter_mod_OF_VERSION_1_3_dup(
    of_meter_mod_t *src)
{
    of_meter_mod_t *dst;
    uint32_t val32;
    uint16_t val16;

    of_list_meter_band_t src_list;
    of_list_meter_band_t *dst_list;

    if ((dst = of_meter_mod_new(src->version)) == NULL) {
        return NULL;
    }

    of_meter_mod_xid_get(src, &val32);
    of_meter_mod_xid_set(dst, val32);

    of_meter_mod_command_get(src, &val16);
    of_meter_mod_command_set(dst, val16);

    of_meter_mod_flags_get(src, &val16);
    of_meter_mod_flags_set(dst, val16);

    of_meter_mod_meter_id_get(src, &val32);
    of_meter_mod_meter_id_set(dst, val32);

    of_meter_mod_meters_bind(
        src, &src_list);
    dst_list = of_list_meter_band_OF_VERSION_1_3_dup(&src_list);
    if (dst_list == NULL) {
        of_meter_mod_delete(dst);
        return NULL;
    }
    of_meter_mod_meters_set(dst, dst_list);
    of_list_meter_band_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_meter_mod_failed_error_msg
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_meter_mod_failed_error_msg.
 *
 * The caller is responsible for deleting the returned value
 */
of_meter_mod_failed_error_msg_t *
of_meter_mod_failed_error_msg_OF_VERSION_1_3_dup(
    of_meter_mod_failed_error_msg_t *src)
{
    of_meter_mod_failed_error_msg_t *dst;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    if ((dst = of_meter_mod_failed_error_msg_new(src->version)) == NULL) {
        return NULL;
    }

    of_meter_mod_failed_error_msg_xid_get(src, &val32);
    of_meter_mod_failed_error_msg_xid_set(dst, val32);

    of_meter_mod_failed_error_msg_code_get(src, &val16);
    of_meter_mod_failed_error_msg_code_set(dst, val16);

    of_meter_mod_failed_error_msg_data_get(src, &octets);
    of_meter_mod_failed_error_msg_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_meter_stats_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_meter_stats_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_meter_stats_reply_t *
of_meter_stats_reply_OF_VERSION_1_3_dup(
    of_meter_stats_reply_t *src)
{
    of_meter_stats_reply_t *dst;
    uint32_t val32;
    uint16_t val16;

    of_list_meter_stats_t src_list;
    of_list_meter_stats_t *dst_list;

    if ((dst = of_meter_stats_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_meter_stats_reply_xid_get(src, &val32);
    of_meter_stats_reply_xid_set(dst, val32);

    of_meter_stats_reply_flags_get(src, &val16);
    of_meter_stats_reply_flags_set(dst, val16);

    of_meter_stats_reply_entries_bind(
        src, &src_list);
    dst_list = of_list_meter_stats_OF_VERSION_1_3_dup(&src_list);
    if (dst_list == NULL) {
        of_meter_stats_reply_delete(dst);
        return NULL;
    }
    of_meter_stats_reply_entries_set(dst, dst_list);
    of_list_meter_stats_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_meter_stats_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_meter_stats_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_meter_stats_request_t *
of_meter_stats_request_OF_VERSION_1_3_dup(
    of_meter_stats_request_t *src)
{
    of_meter_stats_request_t *dst;
    uint32_t val32;
    uint16_t val16;

    if ((dst = of_meter_stats_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_meter_stats_request_xid_get(src, &val32);
    of_meter_stats_request_xid_set(dst, val32);

    of_meter_stats_request_flags_get(src, &val16);
    of_meter_stats_request_flags_set(dst, val16);

    of_meter_stats_request_meter_id_get(src, &val32);
    of_meter_stats_request_meter_id_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_nicira_header
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_nicira_header.
 *
 * The caller is responsible for deleting the returned value
 */
of_nicira_header_t *
of_nicira_header_OF_VERSION_1_3_dup(
    of_nicira_header_t *src)
{
    of_nicira_header_t *dst;
    uint32_t val32;

    if ((dst = of_nicira_header_new(src->version)) == NULL) {
        return NULL;
    }

    of_nicira_header_xid_get(src, &val32);
    of_nicira_header_xid_set(dst, val32);

    of_nicira_header_experimenter_get(src, &val32);
    of_nicira_header_experimenter_set(dst, val32);

    of_nicira_header_subtype_get(src, &val32);
    of_nicira_header_subtype_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_packet_in
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_packet_in.
 *
 * The caller is responsible for deleting the returned value
 */
of_packet_in_t *
of_packet_in_OF_VERSION_1_3_dup(
    of_packet_in_t *src)
{
    of_packet_in_t *dst;
    uint32_t val32;
    uint16_t val16;
    uint8_t val8;
    uint64_t val64;
    of_match_t match;
    of_octets_t octets;

    if ((dst = of_packet_in_new(src->version)) == NULL) {
        return NULL;
    }

    of_packet_in_xid_get(src, &val32);
    of_packet_in_xid_set(dst, val32);

    of_packet_in_buffer_id_get(src, &val32);
    of_packet_in_buffer_id_set(dst, val32);

    of_packet_in_total_len_get(src, &val16);
    of_packet_in_total_len_set(dst, val16);

    of_packet_in_reason_get(src, &val8);
    of_packet_in_reason_set(dst, val8);

    of_packet_in_table_id_get(src, &val8);
    of_packet_in_table_id_set(dst, val8);

    of_packet_in_cookie_get(src, &val64);
    of_packet_in_cookie_set(dst, val64);

    of_packet_in_match_get(src, &match);
    of_packet_in_match_set(dst, &match);

    of_packet_in_data_get(src, &octets);
    of_packet_in_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_packet_out
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_packet_out.
 *
 * The caller is responsible for deleting the returned value
 */
of_packet_out_t *
of_packet_out_OF_VERSION_1_3_dup(
    of_packet_out_t *src)
{
    of_packet_out_t *dst;
    uint32_t val32;
    of_port_no_t port_no;

    of_list_action_t src_list;
    of_list_action_t *dst_list;
    of_octets_t octets;

    if ((dst = of_packet_out_new(src->version)) == NULL) {
        return NULL;
    }

    of_packet_out_xid_get(src, &val32);
    of_packet_out_xid_set(dst, val32);

    of_packet_out_buffer_id_get(src, &val32);
    of_packet_out_buffer_id_set(dst, val32);

    of_packet_out_in_port_get(src, &port_no);
    of_packet_out_in_port_set(dst, port_no);

    of_packet_out_actions_bind(
        src, &src_list);
    dst_list = of_list_action_OF_VERSION_1_3_dup(&src_list);
    if (dst_list == NULL) {
        of_packet_out_delete(dst);
        return NULL;
    }
    of_packet_out_actions_set(dst, dst_list);
    of_list_action_delete(dst_list);

    of_packet_out_data_get(src, &octets);
    of_packet_out_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_port_desc_stats_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_port_desc_stats_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_port_desc_stats_reply_t *
of_port_desc_stats_reply_OF_VERSION_1_3_dup(
    of_port_desc_stats_reply_t *src)
{
    of_port_desc_stats_reply_t *dst;
    uint32_t val32;
    uint16_t val16;

    of_list_port_desc_t src_list;
    of_list_port_desc_t *dst_list;

    if ((dst = of_port_desc_stats_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_port_desc_stats_reply_xid_get(src, &val32);
    of_port_desc_stats_reply_xid_set(dst, val32);

    of_port_desc_stats_reply_flags_get(src, &val16);
    of_port_desc_stats_reply_flags_set(dst, val16);

    of_port_desc_stats_reply_entries_bind(
        src, &src_list);
    dst_list = of_list_port_desc_OF_VERSION_1_3_dup(&src_list);
    if (dst_list == NULL) {
        of_port_desc_stats_reply_delete(dst);
        return NULL;
    }
    of_port_desc_stats_reply_entries_set(dst, dst_list);
    of_list_port_desc_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_port_desc_stats_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_port_desc_stats_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_port_desc_stats_request_t *
of_port_desc_stats_request_OF_VERSION_1_3_dup(
    of_port_desc_stats_request_t *src)
{
    of_port_desc_stats_request_t *dst;
    uint32_t val32;
    uint16_t val16;

    if ((dst = of_port_desc_stats_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_port_desc_stats_request_xid_get(src, &val32);
    of_port_desc_stats_request_xid_set(dst, val32);

    of_port_desc_stats_request_flags_get(src, &val16);
    of_port_desc_stats_request_flags_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_port_mod
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_port_mod.
 *
 * The caller is responsible for deleting the returned value
 */
of_port_mod_t *
of_port_mod_OF_VERSION_1_3_dup(
    of_port_mod_t *src)
{
    of_port_mod_t *dst;
    uint32_t val32;
    of_port_no_t port_no;
    of_mac_addr_t mac_addr;

    if ((dst = of_port_mod_new(src->version)) == NULL) {
        return NULL;
    }

    of_port_mod_xid_get(src, &val32);
    of_port_mod_xid_set(dst, val32);

    of_port_mod_port_no_get(src, &port_no);
    of_port_mod_port_no_set(dst, port_no);

    of_port_mod_hw_addr_get(src, &mac_addr);
    of_port_mod_hw_addr_set(dst, mac_addr);

    of_port_mod_config_get(src, &val32);
    of_port_mod_config_set(dst, val32);

    of_port_mod_mask_get(src, &val32);
    of_port_mod_mask_set(dst, val32);

    of_port_mod_advertise_get(src, &val32);
    of_port_mod_advertise_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_port_mod_failed_error_msg
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_port_mod_failed_error_msg.
 *
 * The caller is responsible for deleting the returned value
 */
of_port_mod_failed_error_msg_t *
of_port_mod_failed_error_msg_OF_VERSION_1_3_dup(
    of_port_mod_failed_error_msg_t *src)
{
    of_port_mod_failed_error_msg_t *dst;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    if ((dst = of_port_mod_failed_error_msg_new(src->version)) == NULL) {
        return NULL;
    }

    of_port_mod_failed_error_msg_xid_get(src, &val32);
    of_port_mod_failed_error_msg_xid_set(dst, val32);

    of_port_mod_failed_error_msg_code_get(src, &val16);
    of_port_mod_failed_error_msg_code_set(dst, val16);

    of_port_mod_failed_error_msg_data_get(src, &octets);
    of_port_mod_failed_error_msg_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_port_stats_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_port_stats_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_port_stats_reply_t *
of_port_stats_reply_OF_VERSION_1_3_dup(
    of_port_stats_reply_t *src)
{
    of_port_stats_reply_t *dst;
    uint32_t val32;
    uint16_t val16;

    of_list_port_stats_entry_t src_list;
    of_list_port_stats_entry_t *dst_list;

    if ((dst = of_port_stats_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_port_stats_reply_xid_get(src, &val32);
    of_port_stats_reply_xid_set(dst, val32);

    of_port_stats_reply_flags_get(src, &val16);
    of_port_stats_reply_flags_set(dst, val16);

    of_port_stats_reply_entries_bind(
        src, &src_list);
    dst_list = of_list_port_stats_entry_OF_VERSION_1_3_dup(&src_list);
    if (dst_list == NULL) {
        of_port_stats_reply_delete(dst);
        return NULL;
    }
    of_port_stats_reply_entries_set(dst, dst_list);
    of_list_port_stats_entry_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_port_stats_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_port_stats_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_port_stats_request_t *
of_port_stats_request_OF_VERSION_1_3_dup(
    of_port_stats_request_t *src)
{
    of_port_stats_request_t *dst;
    uint32_t val32;
    uint16_t val16;
    of_port_no_t port_no;

    if ((dst = of_port_stats_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_port_stats_request_xid_get(src, &val32);
    of_port_stats_request_xid_set(dst, val32);

    of_port_stats_request_flags_get(src, &val16);
    of_port_stats_request_flags_set(dst, val16);

    of_port_stats_request_port_no_get(src, &port_no);
    of_port_stats_request_port_no_set(dst, port_no);

    return dst;
}

/**
 * Duplicate an object of type of_port_status
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_port_status.
 *
 * The caller is responsible for deleting the returned value
 */
of_port_status_t *
of_port_status_OF_VERSION_1_3_dup(
    of_port_status_t *src)
{
    of_port_status_t *dst;
    uint32_t val32;
    uint8_t val8;

    of_port_desc_t src_port_desc;
    of_port_desc_t *dst_port_desc;

    if ((dst = of_port_status_new(src->version)) == NULL) {
        return NULL;
    }

    of_port_status_xid_get(src, &val32);
    of_port_status_xid_set(dst, val32);

    of_port_status_reason_get(src, &val8);
    of_port_status_reason_set(dst, val8);

    of_port_status_desc_bind(
        src, &src_port_desc);
    dst_port_desc = of_port_desc_OF_VERSION_1_3_dup(&src_port_desc);
    if (dst_port_desc == NULL) {
        of_port_status_delete(dst);
        return NULL;
    }
    of_port_status_desc_set(dst, dst_port_desc);
    of_port_desc_delete(dst_port_desc);

    return dst;
}

/**
 * Duplicate an object of type of_queue_get_config_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_queue_get_config_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_queue_get_config_reply_t *
of_queue_get_config_reply_OF_VERSION_1_3_dup(
    of_queue_get_config_reply_t *src)
{
    of_queue_get_config_reply_t *dst;
    uint32_t val32;
    of_port_no_t port_no;

    of_list_packet_queue_t src_list;
    of_list_packet_queue_t *dst_list;

    if ((dst = of_queue_get_config_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_queue_get_config_reply_xid_get(src, &val32);
    of_queue_get_config_reply_xid_set(dst, val32);

    of_queue_get_config_reply_port_get(src, &port_no);
    of_queue_get_config_reply_port_set(dst, port_no);

    of_queue_get_config_reply_queues_bind(
        src, &src_list);
    dst_list = of_list_packet_queue_OF_VERSION_1_3_dup(&src_list);
    if (dst_list == NULL) {
        of_queue_get_config_reply_delete(dst);
        return NULL;
    }
    of_queue_get_config_reply_queues_set(dst, dst_list);
    of_list_packet_queue_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_queue_get_config_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_queue_get_config_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_queue_get_config_request_t *
of_queue_get_config_request_OF_VERSION_1_3_dup(
    of_queue_get_config_request_t *src)
{
    of_queue_get_config_request_t *dst;
    uint32_t val32;
    of_port_no_t port_no;

    if ((dst = of_queue_get_config_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_queue_get_config_request_xid_get(src, &val32);
    of_queue_get_config_request_xid_set(dst, val32);

    of_queue_get_config_request_port_get(src, &port_no);
    of_queue_get_config_request_port_set(dst, port_no);

    return dst;
}

/**
 * Duplicate an object of type of_queue_op_failed_error_msg
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_queue_op_failed_error_msg.
 *
 * The caller is responsible for deleting the returned value
 */
of_queue_op_failed_error_msg_t *
of_queue_op_failed_error_msg_OF_VERSION_1_3_dup(
    of_queue_op_failed_error_msg_t *src)
{
    of_queue_op_failed_error_msg_t *dst;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    if ((dst = of_queue_op_failed_error_msg_new(src->version)) == NULL) {
        return NULL;
    }

    of_queue_op_failed_error_msg_xid_get(src, &val32);
    of_queue_op_failed_error_msg_xid_set(dst, val32);

    of_queue_op_failed_error_msg_code_get(src, &val16);
    of_queue_op_failed_error_msg_code_set(dst, val16);

    of_queue_op_failed_error_msg_data_get(src, &octets);
    of_queue_op_failed_error_msg_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_queue_stats_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_queue_stats_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_queue_stats_reply_t *
of_queue_stats_reply_OF_VERSION_1_3_dup(
    of_queue_stats_reply_t *src)
{
    of_queue_stats_reply_t *dst;
    uint32_t val32;
    uint16_t val16;

    of_list_queue_stats_entry_t src_list;
    of_list_queue_stats_entry_t *dst_list;

    if ((dst = of_queue_stats_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_queue_stats_reply_xid_get(src, &val32);
    of_queue_stats_reply_xid_set(dst, val32);

    of_queue_stats_reply_flags_get(src, &val16);
    of_queue_stats_reply_flags_set(dst, val16);

    of_queue_stats_reply_entries_bind(
        src, &src_list);
    dst_list = of_list_queue_stats_entry_OF_VERSION_1_3_dup(&src_list);
    if (dst_list == NULL) {
        of_queue_stats_reply_delete(dst);
        return NULL;
    }
    of_queue_stats_reply_entries_set(dst, dst_list);
    of_list_queue_stats_entry_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_queue_stats_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_queue_stats_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_queue_stats_request_t *
of_queue_stats_request_OF_VERSION_1_3_dup(
    of_queue_stats_request_t *src)
{
    of_queue_stats_request_t *dst;
    uint32_t val32;
    uint16_t val16;
    of_port_no_t port_no;

    if ((dst = of_queue_stats_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_queue_stats_request_xid_get(src, &val32);
    of_queue_stats_request_xid_set(dst, val32);

    of_queue_stats_request_flags_get(src, &val16);
    of_queue_stats_request_flags_set(dst, val16);

    of_queue_stats_request_port_no_get(src, &port_no);
    of_queue_stats_request_port_no_set(dst, port_no);

    of_queue_stats_request_queue_id_get(src, &val32);
    of_queue_stats_request_queue_id_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_role_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_role_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_role_reply_t *
of_role_reply_OF_VERSION_1_3_dup(
    of_role_reply_t *src)
{
    of_role_reply_t *dst;
    uint32_t val32;
    uint64_t val64;

    if ((dst = of_role_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_role_reply_xid_get(src, &val32);
    of_role_reply_xid_set(dst, val32);

    of_role_reply_role_get(src, &val32);
    of_role_reply_role_set(dst, val32);

    of_role_reply_generation_id_get(src, &val64);
    of_role_reply_generation_id_set(dst, val64);

    return dst;
}

/**
 * Duplicate an object of type of_role_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_role_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_role_request_t *
of_role_request_OF_VERSION_1_3_dup(
    of_role_request_t *src)
{
    of_role_request_t *dst;
    uint32_t val32;
    uint64_t val64;

    if ((dst = of_role_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_role_request_xid_get(src, &val32);
    of_role_request_xid_set(dst, val32);

    of_role_request_role_get(src, &val32);
    of_role_request_role_set(dst, val32);

    of_role_request_generation_id_get(src, &val64);
    of_role_request_generation_id_set(dst, val64);

    return dst;
}

/**
 * Duplicate an object of type of_role_request_failed_error_msg
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_role_request_failed_error_msg.
 *
 * The caller is responsible for deleting the returned value
 */
of_role_request_failed_error_msg_t *
of_role_request_failed_error_msg_OF_VERSION_1_3_dup(
    of_role_request_failed_error_msg_t *src)
{
    of_role_request_failed_error_msg_t *dst;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    if ((dst = of_role_request_failed_error_msg_new(src->version)) == NULL) {
        return NULL;
    }

    of_role_request_failed_error_msg_xid_get(src, &val32);
    of_role_request_failed_error_msg_xid_set(dst, val32);

    of_role_request_failed_error_msg_code_get(src, &val16);
    of_role_request_failed_error_msg_code_set(dst, val16);

    of_role_request_failed_error_msg_data_get(src, &octets);
    of_role_request_failed_error_msg_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_set_config
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_set_config.
 *
 * The caller is responsible for deleting the returned value
 */
of_set_config_t *
of_set_config_OF_VERSION_1_3_dup(
    of_set_config_t *src)
{
    of_set_config_t *dst;
    uint32_t val32;
    uint16_t val16;

    if ((dst = of_set_config_new(src->version)) == NULL) {
        return NULL;
    }

    of_set_config_xid_get(src, &val32);
    of_set_config_xid_set(dst, val32);

    of_set_config_flags_get(src, &val16);
    of_set_config_flags_set(dst, val16);

    of_set_config_miss_send_len_get(src, &val16);
    of_set_config_miss_send_len_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_stats_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_stats_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_stats_reply_t *
of_stats_reply_OF_VERSION_1_3_dup(
    of_stats_reply_t *src)
{
    of_stats_reply_t *dst;
    uint32_t val32;
    uint16_t val16;

    if ((dst = of_stats_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_stats_reply_xid_get(src, &val32);
    of_stats_reply_xid_set(dst, val32);

    of_stats_reply_flags_get(src, &val16);
    of_stats_reply_flags_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_stats_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_stats_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_stats_request_t *
of_stats_request_OF_VERSION_1_3_dup(
    of_stats_request_t *src)
{
    of_stats_request_t *dst;
    uint32_t val32;
    uint16_t val16;

    if ((dst = of_stats_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_stats_request_xid_get(src, &val32);
    of_stats_request_xid_set(dst, val32);

    of_stats_request_flags_get(src, &val16);
    of_stats_request_flags_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_switch_config_failed_error_msg
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_switch_config_failed_error_msg.
 *
 * The caller is responsible for deleting the returned value
 */
of_switch_config_failed_error_msg_t *
of_switch_config_failed_error_msg_OF_VERSION_1_3_dup(
    of_switch_config_failed_error_msg_t *src)
{
    of_switch_config_failed_error_msg_t *dst;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    if ((dst = of_switch_config_failed_error_msg_new(src->version)) == NULL) {
        return NULL;
    }

    of_switch_config_failed_error_msg_xid_get(src, &val32);
    of_switch_config_failed_error_msg_xid_set(dst, val32);

    of_switch_config_failed_error_msg_code_get(src, &val16);
    of_switch_config_failed_error_msg_code_set(dst, val16);

    of_switch_config_failed_error_msg_data_get(src, &octets);
    of_switch_config_failed_error_msg_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_table_features_failed_error_msg
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_table_features_failed_error_msg.
 *
 * The caller is responsible for deleting the returned value
 */
of_table_features_failed_error_msg_t *
of_table_features_failed_error_msg_OF_VERSION_1_3_dup(
    of_table_features_failed_error_msg_t *src)
{
    of_table_features_failed_error_msg_t *dst;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    if ((dst = of_table_features_failed_error_msg_new(src->version)) == NULL) {
        return NULL;
    }

    of_table_features_failed_error_msg_xid_get(src, &val32);
    of_table_features_failed_error_msg_xid_set(dst, val32);

    of_table_features_failed_error_msg_code_get(src, &val16);
    of_table_features_failed_error_msg_code_set(dst, val16);

    of_table_features_failed_error_msg_data_get(src, &octets);
    of_table_features_failed_error_msg_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_table_features_stats_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_table_features_stats_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_table_features_stats_reply_t *
of_table_features_stats_reply_OF_VERSION_1_3_dup(
    of_table_features_stats_reply_t *src)
{
    of_table_features_stats_reply_t *dst;
    uint32_t val32;
    uint16_t val16;

    of_list_table_features_t src_list;
    of_list_table_features_t *dst_list;

    if ((dst = of_table_features_stats_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_table_features_stats_reply_xid_get(src, &val32);
    of_table_features_stats_reply_xid_set(dst, val32);

    of_table_features_stats_reply_flags_get(src, &val16);
    of_table_features_stats_reply_flags_set(dst, val16);

    of_table_features_stats_reply_entries_bind(
        src, &src_list);
    dst_list = of_list_table_features_OF_VERSION_1_3_dup(&src_list);
    if (dst_list == NULL) {
        of_table_features_stats_reply_delete(dst);
        return NULL;
    }
    of_table_features_stats_reply_entries_set(dst, dst_list);
    of_list_table_features_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_table_features_stats_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_table_features_stats_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_table_features_stats_request_t *
of_table_features_stats_request_OF_VERSION_1_3_dup(
    of_table_features_stats_request_t *src)
{
    of_table_features_stats_request_t *dst;
    uint32_t val32;
    uint16_t val16;

    of_list_table_features_t src_list;
    of_list_table_features_t *dst_list;

    if ((dst = of_table_features_stats_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_table_features_stats_request_xid_get(src, &val32);
    of_table_features_stats_request_xid_set(dst, val32);

    of_table_features_stats_request_flags_get(src, &val16);
    of_table_features_stats_request_flags_set(dst, val16);

    of_table_features_stats_request_entries_bind(
        src, &src_list);
    dst_list = of_list_table_features_OF_VERSION_1_3_dup(&src_list);
    if (dst_list == NULL) {
        of_table_features_stats_request_delete(dst);
        return NULL;
    }
    of_table_features_stats_request_entries_set(dst, dst_list);
    of_list_table_features_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_table_mod
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_table_mod.
 *
 * The caller is responsible for deleting the returned value
 */
of_table_mod_t *
of_table_mod_OF_VERSION_1_3_dup(
    of_table_mod_t *src)
{
    of_table_mod_t *dst;
    uint32_t val32;
    uint8_t val8;

    if ((dst = of_table_mod_new(src->version)) == NULL) {
        return NULL;
    }

    of_table_mod_xid_get(src, &val32);
    of_table_mod_xid_set(dst, val32);

    of_table_mod_table_id_get(src, &val8);
    of_table_mod_table_id_set(dst, val8);

    of_table_mod_config_get(src, &val32);
    of_table_mod_config_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_table_mod_failed_error_msg
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_table_mod_failed_error_msg.
 *
 * The caller is responsible for deleting the returned value
 */
of_table_mod_failed_error_msg_t *
of_table_mod_failed_error_msg_OF_VERSION_1_3_dup(
    of_table_mod_failed_error_msg_t *src)
{
    of_table_mod_failed_error_msg_t *dst;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    if ((dst = of_table_mod_failed_error_msg_new(src->version)) == NULL) {
        return NULL;
    }

    of_table_mod_failed_error_msg_xid_get(src, &val32);
    of_table_mod_failed_error_msg_xid_set(dst, val32);

    of_table_mod_failed_error_msg_code_get(src, &val16);
    of_table_mod_failed_error_msg_code_set(dst, val16);

    of_table_mod_failed_error_msg_data_get(src, &octets);
    of_table_mod_failed_error_msg_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_table_stats_reply
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_table_stats_reply.
 *
 * The caller is responsible for deleting the returned value
 */
of_table_stats_reply_t *
of_table_stats_reply_OF_VERSION_1_3_dup(
    of_table_stats_reply_t *src)
{
    of_table_stats_reply_t *dst;
    uint32_t val32;
    uint16_t val16;

    of_list_table_stats_entry_t src_list;
    of_list_table_stats_entry_t *dst_list;

    if ((dst = of_table_stats_reply_new(src->version)) == NULL) {
        return NULL;
    }

    of_table_stats_reply_xid_get(src, &val32);
    of_table_stats_reply_xid_set(dst, val32);

    of_table_stats_reply_flags_get(src, &val16);
    of_table_stats_reply_flags_set(dst, val16);

    of_table_stats_reply_entries_bind(
        src, &src_list);
    dst_list = of_list_table_stats_entry_OF_VERSION_1_3_dup(&src_list);
    if (dst_list == NULL) {
        of_table_stats_reply_delete(dst);
        return NULL;
    }
    of_table_stats_reply_entries_set(dst, dst_list);
    of_list_table_stats_entry_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_table_stats_request
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_table_stats_request.
 *
 * The caller is responsible for deleting the returned value
 */
of_table_stats_request_t *
of_table_stats_request_OF_VERSION_1_3_dup(
    of_table_stats_request_t *src)
{
    of_table_stats_request_t *dst;
    uint32_t val32;
    uint16_t val16;

    if ((dst = of_table_stats_request_new(src->version)) == NULL) {
        return NULL;
    }

    of_table_stats_request_xid_get(src, &val32);
    of_table_stats_request_xid_set(dst, val32);

    of_table_stats_request_flags_get(src, &val16);
    of_table_stats_request_flags_set(dst, val16);

    return dst;
}

/**
 * Duplicate a super class object of type of_action
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_t *
of_action_OF_VERSION_1_3_dup(
    of_action_t *src)
{

    if (src->header.object_id == OF_ACTION_BSN_MIRROR) {
        return (of_action_t *)of_action_bsn_mirror_OF_VERSION_1_3_dup(
            &src->bsn_mirror);
    }

    if (src->header.object_id == OF_ACTION_DEC_MPLS_TTL) {
        return (of_action_t *)of_action_dec_mpls_ttl_OF_VERSION_1_3_dup(
            &src->dec_mpls_ttl);
    }

    if (src->header.object_id == OF_ACTION_BSN_SET_TUNNEL_DST) {
        return (of_action_t *)of_action_bsn_set_tunnel_dst_OF_VERSION_1_3_dup(
            &src->bsn_set_tunnel_dst);
    }

    if (src->header.object_id == OF_ACTION_COPY_TTL_IN) {
        return (of_action_t *)of_action_copy_ttl_in_OF_VERSION_1_3_dup(
            &src->copy_ttl_in);
    }

    if (src->header.object_id == OF_ACTION_GROUP) {
        return (of_action_t *)of_action_group_OF_VERSION_1_3_dup(
            &src->group);
    }

    if (src->header.object_id == OF_ACTION_COPY_TTL_OUT) {
        return (of_action_t *)of_action_copy_ttl_out_OF_VERSION_1_3_dup(
            &src->copy_ttl_out);
    }

    if (src->header.object_id == OF_ACTION_SET_FIELD) {
        return (of_action_t *)of_action_set_field_OF_VERSION_1_3_dup(
            &src->set_field);
    }

    if (src->header.object_id == OF_ACTION_SET_MPLS_TTL) {
        return (of_action_t *)of_action_set_mpls_ttl_OF_VERSION_1_3_dup(
            &src->set_mpls_ttl);
    }

    if (src->header.object_id == OF_ACTION_POP_VLAN) {
        return (of_action_t *)of_action_pop_vlan_OF_VERSION_1_3_dup(
            &src->pop_vlan);
    }

    if (src->header.object_id == OF_ACTION_PUSH_PBB) {
        return (of_action_t *)of_action_push_pbb_OF_VERSION_1_3_dup(
            &src->push_pbb);
    }

    if (src->header.object_id == OF_ACTION_NICIRA_DEC_TTL) {
        return (of_action_t *)of_action_nicira_dec_ttl_OF_VERSION_1_3_dup(
            &src->nicira_dec_ttl);
    }

    if (src->header.object_id == OF_ACTION_POP_MPLS) {
        return (of_action_t *)of_action_pop_mpls_OF_VERSION_1_3_dup(
            &src->pop_mpls);
    }

    if (src->header.object_id == OF_ACTION_PUSH_VLAN) {
        return (of_action_t *)of_action_push_vlan_OF_VERSION_1_3_dup(
            &src->push_vlan);
    }

    if (src->header.object_id == OF_ACTION_BSN) {
        return (of_action_t *)of_action_bsn_OF_VERSION_1_3_dup(
            &src->bsn);
    }

    if (src->header.object_id == OF_ACTION_EXPERIMENTER) {
        return (of_action_t *)of_action_experimenter_OF_VERSION_1_3_dup(
            &src->experimenter);
    }

    if (src->header.object_id == OF_ACTION_SET_NW_TTL) {
        return (of_action_t *)of_action_set_nw_ttl_OF_VERSION_1_3_dup(
            &src->set_nw_ttl);
    }

    if (src->header.object_id == OF_ACTION_POP_PBB) {
        return (of_action_t *)of_action_pop_pbb_OF_VERSION_1_3_dup(
            &src->pop_pbb);
    }

    if (src->header.object_id == OF_ACTION_NICIRA) {
        return (of_action_t *)of_action_nicira_OF_VERSION_1_3_dup(
            &src->nicira);
    }

    if (src->header.object_id == OF_ACTION_SET_QUEUE) {
        return (of_action_t *)of_action_set_queue_OF_VERSION_1_3_dup(
            &src->set_queue);
    }

    if (src->header.object_id == OF_ACTION_PUSH_MPLS) {
        return (of_action_t *)of_action_push_mpls_OF_VERSION_1_3_dup(
            &src->push_mpls);
    }

    if (src->header.object_id == OF_ACTION_DEC_NW_TTL) {
        return (of_action_t *)of_action_dec_nw_ttl_OF_VERSION_1_3_dup(
            &src->dec_nw_ttl);
    }

    if (src->header.object_id == OF_ACTION_OUTPUT) {
        return (of_action_t *)of_action_output_OF_VERSION_1_3_dup(
            &src->output);
    }

    return NULL;
}

/**
 * Duplicate an object of type of_action_bsn
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_bsn.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_bsn_t *
of_action_bsn_OF_VERSION_1_3_dup(
    of_action_bsn_t *src)
{
    of_action_bsn_t *dst;
    uint32_t val32;

    if ((dst = of_action_bsn_new(src->version)) == NULL) {
        return NULL;
    }

    of_action_bsn_experimenter_get(src, &val32);
    of_action_bsn_experimenter_set(dst, val32);

    of_action_bsn_subtype_get(src, &val32);
    of_action_bsn_subtype_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_action_bsn_mirror
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_bsn_mirror.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_bsn_mirror_t *
of_action_bsn_mirror_OF_VERSION_1_3_dup(
    of_action_bsn_mirror_t *src)
{
    of_action_bsn_mirror_t *dst;
    uint32_t val32;
    uint8_t val8;

    if ((dst = of_action_bsn_mirror_new(src->version)) == NULL) {
        return NULL;
    }

    of_action_bsn_mirror_experimenter_get(src, &val32);
    of_action_bsn_mirror_experimenter_set(dst, val32);

    of_action_bsn_mirror_subtype_get(src, &val32);
    of_action_bsn_mirror_subtype_set(dst, val32);

    of_action_bsn_mirror_dest_port_get(src, &val32);
    of_action_bsn_mirror_dest_port_set(dst, val32);

    of_action_bsn_mirror_vlan_tag_get(src, &val32);
    of_action_bsn_mirror_vlan_tag_set(dst, val32);

    of_action_bsn_mirror_copy_stage_get(src, &val8);
    of_action_bsn_mirror_copy_stage_set(dst, val8);

    return dst;
}

/**
 * Duplicate an object of type of_action_bsn_set_tunnel_dst
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_bsn_set_tunnel_dst.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_bsn_set_tunnel_dst_t *
of_action_bsn_set_tunnel_dst_OF_VERSION_1_3_dup(
    of_action_bsn_set_tunnel_dst_t *src)
{
    of_action_bsn_set_tunnel_dst_t *dst;
    uint32_t val32;

    if ((dst = of_action_bsn_set_tunnel_dst_new(src->version)) == NULL) {
        return NULL;
    }

    of_action_bsn_set_tunnel_dst_experimenter_get(src, &val32);
    of_action_bsn_set_tunnel_dst_experimenter_set(dst, val32);

    of_action_bsn_set_tunnel_dst_subtype_get(src, &val32);
    of_action_bsn_set_tunnel_dst_subtype_set(dst, val32);

    of_action_bsn_set_tunnel_dst_dst_get(src, &val32);
    of_action_bsn_set_tunnel_dst_dst_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_action_copy_ttl_in
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_copy_ttl_in.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_copy_ttl_in_t *
of_action_copy_ttl_in_OF_VERSION_1_3_dup(
    of_action_copy_ttl_in_t *src)
{
    of_action_copy_ttl_in_t *dst;

    if ((dst = of_action_copy_ttl_in_new(src->version)) == NULL) {
        return NULL;
    }

    return dst;
}

/**
 * Duplicate an object of type of_action_copy_ttl_out
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_copy_ttl_out.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_copy_ttl_out_t *
of_action_copy_ttl_out_OF_VERSION_1_3_dup(
    of_action_copy_ttl_out_t *src)
{
    of_action_copy_ttl_out_t *dst;

    if ((dst = of_action_copy_ttl_out_new(src->version)) == NULL) {
        return NULL;
    }

    return dst;
}

/**
 * Duplicate an object of type of_action_dec_mpls_ttl
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_dec_mpls_ttl.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_dec_mpls_ttl_t *
of_action_dec_mpls_ttl_OF_VERSION_1_3_dup(
    of_action_dec_mpls_ttl_t *src)
{
    of_action_dec_mpls_ttl_t *dst;

    if ((dst = of_action_dec_mpls_ttl_new(src->version)) == NULL) {
        return NULL;
    }

    return dst;
}

/**
 * Duplicate an object of type of_action_dec_nw_ttl
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_dec_nw_ttl.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_dec_nw_ttl_t *
of_action_dec_nw_ttl_OF_VERSION_1_3_dup(
    of_action_dec_nw_ttl_t *src)
{
    of_action_dec_nw_ttl_t *dst;

    if ((dst = of_action_dec_nw_ttl_new(src->version)) == NULL) {
        return NULL;
    }

    return dst;
}

/**
 * Duplicate an object of type of_action_experimenter
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_experimenter.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_experimenter_t *
of_action_experimenter_OF_VERSION_1_3_dup(
    of_action_experimenter_t *src)
{
    of_action_experimenter_t *dst;
    uint32_t val32;
    of_octets_t octets;

    if ((dst = of_action_experimenter_new(src->version)) == NULL) {
        return NULL;
    }

    of_action_experimenter_experimenter_get(src, &val32);
    of_action_experimenter_experimenter_set(dst, val32);

    of_action_experimenter_data_get(src, &octets);
    of_action_experimenter_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_action_group
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_group.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_group_t *
of_action_group_OF_VERSION_1_3_dup(
    of_action_group_t *src)
{
    of_action_group_t *dst;
    uint32_t val32;

    if ((dst = of_action_group_new(src->version)) == NULL) {
        return NULL;
    }

    of_action_group_group_id_get(src, &val32);
    of_action_group_group_id_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_action_header
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_header.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_header_t *
of_action_header_OF_VERSION_1_3_dup(
    of_action_header_t *src)
{
    of_action_header_t *dst;

    if ((dst = of_action_header_new(src->version)) == NULL) {
        return NULL;
    }

    return dst;
}

/**
 * Duplicate a super class object of type of_action_id
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_id.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_id_t *
of_action_id_OF_VERSION_1_3_dup(
    of_action_id_t *src)
{

    if (src->header.object_id == OF_ACTION_ID_BSN_MIRROR) {
        return (of_action_id_t *)of_action_id_bsn_mirror_OF_VERSION_1_3_dup(
            &src->bsn_mirror);
    }

    if (src->header.object_id == OF_ACTION_ID_DEC_MPLS_TTL) {
        return (of_action_id_t *)of_action_id_dec_mpls_ttl_OF_VERSION_1_3_dup(
            &src->dec_mpls_ttl);
    }

    if (src->header.object_id == OF_ACTION_ID_BSN_SET_TUNNEL_DST) {
        return (of_action_id_t *)of_action_id_bsn_set_tunnel_dst_OF_VERSION_1_3_dup(
            &src->bsn_set_tunnel_dst);
    }

    if (src->header.object_id == OF_ACTION_ID_COPY_TTL_IN) {
        return (of_action_id_t *)of_action_id_copy_ttl_in_OF_VERSION_1_3_dup(
            &src->copy_ttl_in);
    }

    if (src->header.object_id == OF_ACTION_ID_GROUP) {
        return (of_action_id_t *)of_action_id_group_OF_VERSION_1_3_dup(
            &src->group);
    }

    if (src->header.object_id == OF_ACTION_ID_COPY_TTL_OUT) {
        return (of_action_id_t *)of_action_id_copy_ttl_out_OF_VERSION_1_3_dup(
            &src->copy_ttl_out);
    }

    if (src->header.object_id == OF_ACTION_ID_SET_FIELD) {
        return (of_action_id_t *)of_action_id_set_field_OF_VERSION_1_3_dup(
            &src->set_field);
    }

    if (src->header.object_id == OF_ACTION_ID_SET_MPLS_TTL) {
        return (of_action_id_t *)of_action_id_set_mpls_ttl_OF_VERSION_1_3_dup(
            &src->set_mpls_ttl);
    }

    if (src->header.object_id == OF_ACTION_ID_POP_VLAN) {
        return (of_action_id_t *)of_action_id_pop_vlan_OF_VERSION_1_3_dup(
            &src->pop_vlan);
    }

    if (src->header.object_id == OF_ACTION_ID_PUSH_PBB) {
        return (of_action_id_t *)of_action_id_push_pbb_OF_VERSION_1_3_dup(
            &src->push_pbb);
    }

    if (src->header.object_id == OF_ACTION_ID_NICIRA_DEC_TTL) {
        return (of_action_id_t *)of_action_id_nicira_dec_ttl_OF_VERSION_1_3_dup(
            &src->nicira_dec_ttl);
    }

    if (src->header.object_id == OF_ACTION_ID_POP_MPLS) {
        return (of_action_id_t *)of_action_id_pop_mpls_OF_VERSION_1_3_dup(
            &src->pop_mpls);
    }

    if (src->header.object_id == OF_ACTION_ID_PUSH_VLAN) {
        return (of_action_id_t *)of_action_id_push_vlan_OF_VERSION_1_3_dup(
            &src->push_vlan);
    }

    if (src->header.object_id == OF_ACTION_ID_BSN) {
        return (of_action_id_t *)of_action_id_bsn_OF_VERSION_1_3_dup(
            &src->bsn);
    }

    if (src->header.object_id == OF_ACTION_ID_EXPERIMENTER) {
        return (of_action_id_t *)of_action_id_experimenter_OF_VERSION_1_3_dup(
            &src->experimenter);
    }

    if (src->header.object_id == OF_ACTION_ID_SET_NW_TTL) {
        return (of_action_id_t *)of_action_id_set_nw_ttl_OF_VERSION_1_3_dup(
            &src->set_nw_ttl);
    }

    if (src->header.object_id == OF_ACTION_ID_POP_PBB) {
        return (of_action_id_t *)of_action_id_pop_pbb_OF_VERSION_1_3_dup(
            &src->pop_pbb);
    }

    if (src->header.object_id == OF_ACTION_ID_NICIRA) {
        return (of_action_id_t *)of_action_id_nicira_OF_VERSION_1_3_dup(
            &src->nicira);
    }

    if (src->header.object_id == OF_ACTION_ID_SET_QUEUE) {
        return (of_action_id_t *)of_action_id_set_queue_OF_VERSION_1_3_dup(
            &src->set_queue);
    }

    if (src->header.object_id == OF_ACTION_ID_PUSH_MPLS) {
        return (of_action_id_t *)of_action_id_push_mpls_OF_VERSION_1_3_dup(
            &src->push_mpls);
    }

    if (src->header.object_id == OF_ACTION_ID_DEC_NW_TTL) {
        return (of_action_id_t *)of_action_id_dec_nw_ttl_OF_VERSION_1_3_dup(
            &src->dec_nw_ttl);
    }

    if (src->header.object_id == OF_ACTION_ID_OUTPUT) {
        return (of_action_id_t *)of_action_id_output_OF_VERSION_1_3_dup(
            &src->output);
    }

    return NULL;
}

/**
 * Duplicate an object of type of_action_id_bsn
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_id_bsn.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_id_bsn_t *
of_action_id_bsn_OF_VERSION_1_3_dup(
    of_action_id_bsn_t *src)
{
    of_action_id_bsn_t *dst;

    if ((dst = of_action_id_bsn_new(src->version)) == NULL) {
        return NULL;
    }

    return dst;
}

/**
 * Duplicate an object of type of_action_id_bsn_mirror
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_id_bsn_mirror.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_id_bsn_mirror_t *
of_action_id_bsn_mirror_OF_VERSION_1_3_dup(
    of_action_id_bsn_mirror_t *src)
{
    of_action_id_bsn_mirror_t *dst;
    uint32_t val32;

    if ((dst = of_action_id_bsn_mirror_new(src->version)) == NULL) {
        return NULL;
    }

    of_action_id_bsn_mirror_experimenter_get(src, &val32);
    of_action_id_bsn_mirror_experimenter_set(dst, val32);

    of_action_id_bsn_mirror_subtype_get(src, &val32);
    of_action_id_bsn_mirror_subtype_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_action_id_bsn_set_tunnel_dst
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_id_bsn_set_tunnel_dst.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_id_bsn_set_tunnel_dst_t *
of_action_id_bsn_set_tunnel_dst_OF_VERSION_1_3_dup(
    of_action_id_bsn_set_tunnel_dst_t *src)
{
    of_action_id_bsn_set_tunnel_dst_t *dst;
    uint32_t val32;

    if ((dst = of_action_id_bsn_set_tunnel_dst_new(src->version)) == NULL) {
        return NULL;
    }

    of_action_id_bsn_set_tunnel_dst_experimenter_get(src, &val32);
    of_action_id_bsn_set_tunnel_dst_experimenter_set(dst, val32);

    of_action_id_bsn_set_tunnel_dst_subtype_get(src, &val32);
    of_action_id_bsn_set_tunnel_dst_subtype_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_action_id_copy_ttl_in
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_id_copy_ttl_in.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_id_copy_ttl_in_t *
of_action_id_copy_ttl_in_OF_VERSION_1_3_dup(
    of_action_id_copy_ttl_in_t *src)
{
    of_action_id_copy_ttl_in_t *dst;

    if ((dst = of_action_id_copy_ttl_in_new(src->version)) == NULL) {
        return NULL;
    }

    return dst;
}

/**
 * Duplicate an object of type of_action_id_copy_ttl_out
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_id_copy_ttl_out.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_id_copy_ttl_out_t *
of_action_id_copy_ttl_out_OF_VERSION_1_3_dup(
    of_action_id_copy_ttl_out_t *src)
{
    of_action_id_copy_ttl_out_t *dst;

    if ((dst = of_action_id_copy_ttl_out_new(src->version)) == NULL) {
        return NULL;
    }

    return dst;
}

/**
 * Duplicate an object of type of_action_id_dec_mpls_ttl
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_id_dec_mpls_ttl.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_id_dec_mpls_ttl_t *
of_action_id_dec_mpls_ttl_OF_VERSION_1_3_dup(
    of_action_id_dec_mpls_ttl_t *src)
{
    of_action_id_dec_mpls_ttl_t *dst;

    if ((dst = of_action_id_dec_mpls_ttl_new(src->version)) == NULL) {
        return NULL;
    }

    return dst;
}

/**
 * Duplicate an object of type of_action_id_dec_nw_ttl
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_id_dec_nw_ttl.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_id_dec_nw_ttl_t *
of_action_id_dec_nw_ttl_OF_VERSION_1_3_dup(
    of_action_id_dec_nw_ttl_t *src)
{
    of_action_id_dec_nw_ttl_t *dst;

    if ((dst = of_action_id_dec_nw_ttl_new(src->version)) == NULL) {
        return NULL;
    }

    return dst;
}

/**
 * Duplicate an object of type of_action_id_experimenter
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_id_experimenter.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_id_experimenter_t *
of_action_id_experimenter_OF_VERSION_1_3_dup(
    of_action_id_experimenter_t *src)
{
    of_action_id_experimenter_t *dst;

    if ((dst = of_action_id_experimenter_new(src->version)) == NULL) {
        return NULL;
    }

    return dst;
}

/**
 * Duplicate an object of type of_action_id_group
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_id_group.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_id_group_t *
of_action_id_group_OF_VERSION_1_3_dup(
    of_action_id_group_t *src)
{
    of_action_id_group_t *dst;

    if ((dst = of_action_id_group_new(src->version)) == NULL) {
        return NULL;
    }

    return dst;
}

/**
 * Duplicate an object of type of_action_id_header
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_id_header.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_id_header_t *
of_action_id_header_OF_VERSION_1_3_dup(
    of_action_id_header_t *src)
{
    of_action_id_header_t *dst;

    if ((dst = of_action_id_header_new(src->version)) == NULL) {
        return NULL;
    }

    return dst;
}

/**
 * Duplicate an object of type of_action_id_nicira
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_id_nicira.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_id_nicira_t *
of_action_id_nicira_OF_VERSION_1_3_dup(
    of_action_id_nicira_t *src)
{
    of_action_id_nicira_t *dst;

    if ((dst = of_action_id_nicira_new(src->version)) == NULL) {
        return NULL;
    }

    return dst;
}

/**
 * Duplicate an object of type of_action_id_nicira_dec_ttl
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_id_nicira_dec_ttl.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_id_nicira_dec_ttl_t *
of_action_id_nicira_dec_ttl_OF_VERSION_1_3_dup(
    of_action_id_nicira_dec_ttl_t *src)
{
    of_action_id_nicira_dec_ttl_t *dst;
    uint32_t val32;
    uint16_t val16;

    if ((dst = of_action_id_nicira_dec_ttl_new(src->version)) == NULL) {
        return NULL;
    }

    of_action_id_nicira_dec_ttl_experimenter_get(src, &val32);
    of_action_id_nicira_dec_ttl_experimenter_set(dst, val32);

    of_action_id_nicira_dec_ttl_subtype_get(src, &val16);
    of_action_id_nicira_dec_ttl_subtype_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_action_id_output
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_id_output.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_id_output_t *
of_action_id_output_OF_VERSION_1_3_dup(
    of_action_id_output_t *src)
{
    of_action_id_output_t *dst;

    if ((dst = of_action_id_output_new(src->version)) == NULL) {
        return NULL;
    }

    return dst;
}

/**
 * Duplicate an object of type of_action_id_pop_mpls
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_id_pop_mpls.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_id_pop_mpls_t *
of_action_id_pop_mpls_OF_VERSION_1_3_dup(
    of_action_id_pop_mpls_t *src)
{
    of_action_id_pop_mpls_t *dst;

    if ((dst = of_action_id_pop_mpls_new(src->version)) == NULL) {
        return NULL;
    }

    return dst;
}

/**
 * Duplicate an object of type of_action_id_pop_pbb
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_id_pop_pbb.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_id_pop_pbb_t *
of_action_id_pop_pbb_OF_VERSION_1_3_dup(
    of_action_id_pop_pbb_t *src)
{
    of_action_id_pop_pbb_t *dst;

    if ((dst = of_action_id_pop_pbb_new(src->version)) == NULL) {
        return NULL;
    }

    return dst;
}

/**
 * Duplicate an object of type of_action_id_pop_vlan
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_id_pop_vlan.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_id_pop_vlan_t *
of_action_id_pop_vlan_OF_VERSION_1_3_dup(
    of_action_id_pop_vlan_t *src)
{
    of_action_id_pop_vlan_t *dst;

    if ((dst = of_action_id_pop_vlan_new(src->version)) == NULL) {
        return NULL;
    }

    return dst;
}

/**
 * Duplicate an object of type of_action_id_push_mpls
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_id_push_mpls.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_id_push_mpls_t *
of_action_id_push_mpls_OF_VERSION_1_3_dup(
    of_action_id_push_mpls_t *src)
{
    of_action_id_push_mpls_t *dst;

    if ((dst = of_action_id_push_mpls_new(src->version)) == NULL) {
        return NULL;
    }

    return dst;
}

/**
 * Duplicate an object of type of_action_id_push_pbb
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_id_push_pbb.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_id_push_pbb_t *
of_action_id_push_pbb_OF_VERSION_1_3_dup(
    of_action_id_push_pbb_t *src)
{
    of_action_id_push_pbb_t *dst;

    if ((dst = of_action_id_push_pbb_new(src->version)) == NULL) {
        return NULL;
    }

    return dst;
}

/**
 * Duplicate an object of type of_action_id_push_vlan
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_id_push_vlan.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_id_push_vlan_t *
of_action_id_push_vlan_OF_VERSION_1_3_dup(
    of_action_id_push_vlan_t *src)
{
    of_action_id_push_vlan_t *dst;

    if ((dst = of_action_id_push_vlan_new(src->version)) == NULL) {
        return NULL;
    }

    return dst;
}

/**
 * Duplicate an object of type of_action_id_set_field
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_id_set_field.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_id_set_field_t *
of_action_id_set_field_OF_VERSION_1_3_dup(
    of_action_id_set_field_t *src)
{
    of_action_id_set_field_t *dst;

    if ((dst = of_action_id_set_field_new(src->version)) == NULL) {
        return NULL;
    }

    return dst;
}

/**
 * Duplicate an object of type of_action_id_set_mpls_ttl
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_id_set_mpls_ttl.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_id_set_mpls_ttl_t *
of_action_id_set_mpls_ttl_OF_VERSION_1_3_dup(
    of_action_id_set_mpls_ttl_t *src)
{
    of_action_id_set_mpls_ttl_t *dst;

    if ((dst = of_action_id_set_mpls_ttl_new(src->version)) == NULL) {
        return NULL;
    }

    return dst;
}

/**
 * Duplicate an object of type of_action_id_set_nw_ttl
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_id_set_nw_ttl.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_id_set_nw_ttl_t *
of_action_id_set_nw_ttl_OF_VERSION_1_3_dup(
    of_action_id_set_nw_ttl_t *src)
{
    of_action_id_set_nw_ttl_t *dst;

    if ((dst = of_action_id_set_nw_ttl_new(src->version)) == NULL) {
        return NULL;
    }

    return dst;
}

/**
 * Duplicate an object of type of_action_id_set_queue
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_id_set_queue.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_id_set_queue_t *
of_action_id_set_queue_OF_VERSION_1_3_dup(
    of_action_id_set_queue_t *src)
{
    of_action_id_set_queue_t *dst;

    if ((dst = of_action_id_set_queue_new(src->version)) == NULL) {
        return NULL;
    }

    return dst;
}

/**
 * Duplicate an object of type of_action_nicira
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_nicira.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_nicira_t *
of_action_nicira_OF_VERSION_1_3_dup(
    of_action_nicira_t *src)
{
    of_action_nicira_t *dst;
    uint32_t val32;
    uint16_t val16;

    if ((dst = of_action_nicira_new(src->version)) == NULL) {
        return NULL;
    }

    of_action_nicira_experimenter_get(src, &val32);
    of_action_nicira_experimenter_set(dst, val32);

    of_action_nicira_subtype_get(src, &val16);
    of_action_nicira_subtype_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_action_nicira_dec_ttl
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_nicira_dec_ttl.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_nicira_dec_ttl_t *
of_action_nicira_dec_ttl_OF_VERSION_1_3_dup(
    of_action_nicira_dec_ttl_t *src)
{
    of_action_nicira_dec_ttl_t *dst;
    uint32_t val32;
    uint16_t val16;

    if ((dst = of_action_nicira_dec_ttl_new(src->version)) == NULL) {
        return NULL;
    }

    of_action_nicira_dec_ttl_experimenter_get(src, &val32);
    of_action_nicira_dec_ttl_experimenter_set(dst, val32);

    of_action_nicira_dec_ttl_subtype_get(src, &val16);
    of_action_nicira_dec_ttl_subtype_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_action_output
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_output.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_output_t *
of_action_output_OF_VERSION_1_3_dup(
    of_action_output_t *src)
{
    of_action_output_t *dst;
    of_port_no_t port_no;
    uint16_t val16;

    if ((dst = of_action_output_new(src->version)) == NULL) {
        return NULL;
    }

    of_action_output_port_get(src, &port_no);
    of_action_output_port_set(dst, port_no);

    of_action_output_max_len_get(src, &val16);
    of_action_output_max_len_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_action_pop_mpls
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_pop_mpls.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_pop_mpls_t *
of_action_pop_mpls_OF_VERSION_1_3_dup(
    of_action_pop_mpls_t *src)
{
    of_action_pop_mpls_t *dst;
    uint16_t val16;

    if ((dst = of_action_pop_mpls_new(src->version)) == NULL) {
        return NULL;
    }

    of_action_pop_mpls_ethertype_get(src, &val16);
    of_action_pop_mpls_ethertype_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_action_pop_pbb
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_pop_pbb.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_pop_pbb_t *
of_action_pop_pbb_OF_VERSION_1_3_dup(
    of_action_pop_pbb_t *src)
{
    of_action_pop_pbb_t *dst;

    if ((dst = of_action_pop_pbb_new(src->version)) == NULL) {
        return NULL;
    }

    return dst;
}

/**
 * Duplicate an object of type of_action_pop_vlan
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_pop_vlan.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_pop_vlan_t *
of_action_pop_vlan_OF_VERSION_1_3_dup(
    of_action_pop_vlan_t *src)
{
    of_action_pop_vlan_t *dst;

    if ((dst = of_action_pop_vlan_new(src->version)) == NULL) {
        return NULL;
    }

    return dst;
}

/**
 * Duplicate an object of type of_action_push_mpls
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_push_mpls.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_push_mpls_t *
of_action_push_mpls_OF_VERSION_1_3_dup(
    of_action_push_mpls_t *src)
{
    of_action_push_mpls_t *dst;
    uint16_t val16;

    if ((dst = of_action_push_mpls_new(src->version)) == NULL) {
        return NULL;
    }

    of_action_push_mpls_ethertype_get(src, &val16);
    of_action_push_mpls_ethertype_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_action_push_pbb
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_push_pbb.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_push_pbb_t *
of_action_push_pbb_OF_VERSION_1_3_dup(
    of_action_push_pbb_t *src)
{
    of_action_push_pbb_t *dst;
    uint16_t val16;

    if ((dst = of_action_push_pbb_new(src->version)) == NULL) {
        return NULL;
    }

    of_action_push_pbb_ethertype_get(src, &val16);
    of_action_push_pbb_ethertype_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_action_push_vlan
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_push_vlan.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_push_vlan_t *
of_action_push_vlan_OF_VERSION_1_3_dup(
    of_action_push_vlan_t *src)
{
    of_action_push_vlan_t *dst;
    uint16_t val16;

    if ((dst = of_action_push_vlan_new(src->version)) == NULL) {
        return NULL;
    }

    of_action_push_vlan_ethertype_get(src, &val16);
    of_action_push_vlan_ethertype_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_action_set_field
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_set_field.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_set_field_t *
of_action_set_field_OF_VERSION_1_3_dup(
    of_action_set_field_t *src)
{
    of_action_set_field_t *dst;
    of_octets_t octets;

    if ((dst = of_action_set_field_new(src->version)) == NULL) {
        return NULL;
    }

    of_action_set_field_field_get(src, &octets);
    of_action_set_field_field_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_action_set_mpls_ttl
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_set_mpls_ttl.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_set_mpls_ttl_t *
of_action_set_mpls_ttl_OF_VERSION_1_3_dup(
    of_action_set_mpls_ttl_t *src)
{
    of_action_set_mpls_ttl_t *dst;
    uint8_t val8;

    if ((dst = of_action_set_mpls_ttl_new(src->version)) == NULL) {
        return NULL;
    }

    of_action_set_mpls_ttl_mpls_ttl_get(src, &val8);
    of_action_set_mpls_ttl_mpls_ttl_set(dst, val8);

    return dst;
}

/**
 * Duplicate an object of type of_action_set_nw_ttl
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_set_nw_ttl.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_set_nw_ttl_t *
of_action_set_nw_ttl_OF_VERSION_1_3_dup(
    of_action_set_nw_ttl_t *src)
{
    of_action_set_nw_ttl_t *dst;
    uint8_t val8;

    if ((dst = of_action_set_nw_ttl_new(src->version)) == NULL) {
        return NULL;
    }

    of_action_set_nw_ttl_nw_ttl_get(src, &val8);
    of_action_set_nw_ttl_nw_ttl_set(dst, val8);

    return dst;
}

/**
 * Duplicate an object of type of_action_set_queue
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_action_set_queue.
 *
 * The caller is responsible for deleting the returned value
 */
of_action_set_queue_t *
of_action_set_queue_OF_VERSION_1_3_dup(
    of_action_set_queue_t *src)
{
    of_action_set_queue_t *dst;
    uint32_t val32;

    if ((dst = of_action_set_queue_new(src->version)) == NULL) {
        return NULL;
    }

    of_action_set_queue_queue_id_get(src, &val32);
    of_action_set_queue_queue_id_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_bsn_interface
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_interface.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_interface_t *
of_bsn_interface_OF_VERSION_1_3_dup(
    of_bsn_interface_t *src)
{
    of_bsn_interface_t *dst;
    of_mac_addr_t mac_addr;
    of_port_name_t port_name;
    of_ipv4_t ipv4;

    if ((dst = of_bsn_interface_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_interface_hw_addr_get(src, &mac_addr);
    of_bsn_interface_hw_addr_set(dst, mac_addr);

    of_bsn_interface_name_get(src, &port_name);
    of_bsn_interface_name_set(dst, port_name);

    of_bsn_interface_ipv4_addr_get(src, &ipv4);
    of_bsn_interface_ipv4_addr_set(dst, ipv4);

    of_bsn_interface_ipv4_netmask_get(src, &ipv4);
    of_bsn_interface_ipv4_netmask_set(dst, ipv4);

    return dst;
}

/**
 * Duplicate a super class object of type of_bsn_vport
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_vport.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_vport_t *
of_bsn_vport_OF_VERSION_1_3_dup(
    of_bsn_vport_t *src)
{

    if (src->header.object_id == OF_BSN_VPORT_Q_IN_Q) {
        return (of_bsn_vport_t *)of_bsn_vport_q_in_q_OF_VERSION_1_3_dup(
            &src->q_in_q);
    }

    return NULL;
}

/**
 * Duplicate an object of type of_bsn_vport_header
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_vport_header.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_vport_header_t *
of_bsn_vport_header_OF_VERSION_1_3_dup(
    of_bsn_vport_header_t *src)
{
    of_bsn_vport_header_t *dst;

    if ((dst = of_bsn_vport_header_new(src->version)) == NULL) {
        return NULL;
    }

    return dst;
}

/**
 * Duplicate an object of type of_bsn_vport_q_in_q
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bsn_vport_q_in_q.
 *
 * The caller is responsible for deleting the returned value
 */
of_bsn_vport_q_in_q_t *
of_bsn_vport_q_in_q_OF_VERSION_1_3_dup(
    of_bsn_vport_q_in_q_t *src)
{
    of_bsn_vport_q_in_q_t *dst;
    uint32_t val32;
    uint16_t val16;
    of_port_name_t port_name;

    if ((dst = of_bsn_vport_q_in_q_new(src->version)) == NULL) {
        return NULL;
    }

    of_bsn_vport_q_in_q_port_no_get(src, &val32);
    of_bsn_vport_q_in_q_port_no_set(dst, val32);

    of_bsn_vport_q_in_q_ingress_tpid_get(src, &val16);
    of_bsn_vport_q_in_q_ingress_tpid_set(dst, val16);

    of_bsn_vport_q_in_q_ingress_vlan_id_get(src, &val16);
    of_bsn_vport_q_in_q_ingress_vlan_id_set(dst, val16);

    of_bsn_vport_q_in_q_egress_tpid_get(src, &val16);
    of_bsn_vport_q_in_q_egress_tpid_set(dst, val16);

    of_bsn_vport_q_in_q_egress_vlan_id_get(src, &val16);
    of_bsn_vport_q_in_q_egress_vlan_id_set(dst, val16);

    of_bsn_vport_q_in_q_if_name_get(src, &port_name);
    of_bsn_vport_q_in_q_if_name_set(dst, port_name);

    return dst;
}

/**
 * Duplicate an object of type of_bucket
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bucket.
 *
 * The caller is responsible for deleting the returned value
 */
of_bucket_t *
of_bucket_OF_VERSION_1_3_dup(
    of_bucket_t *src)
{
    of_bucket_t *dst;
    uint16_t val16;
    of_port_no_t port_no;
    uint32_t val32;

    of_list_action_t src_list;
    of_list_action_t *dst_list;

    if ((dst = of_bucket_new(src->version)) == NULL) {
        return NULL;
    }

    of_bucket_weight_get(src, &val16);
    of_bucket_weight_set(dst, val16);

    of_bucket_watch_port_get(src, &port_no);
    of_bucket_watch_port_set(dst, port_no);

    of_bucket_watch_group_get(src, &val32);
    of_bucket_watch_group_set(dst, val32);

    of_bucket_actions_bind(
        src, &src_list);
    dst_list = of_list_action_OF_VERSION_1_3_dup(&src_list);
    if (dst_list == NULL) {
        of_bucket_delete(dst);
        return NULL;
    }
    of_bucket_actions_set(dst, dst_list);
    of_list_action_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_bucket_counter
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_bucket_counter.
 *
 * The caller is responsible for deleting the returned value
 */
of_bucket_counter_t *
of_bucket_counter_OF_VERSION_1_3_dup(
    of_bucket_counter_t *src)
{
    of_bucket_counter_t *dst;
    uint64_t val64;

    if ((dst = of_bucket_counter_new(src->version)) == NULL) {
        return NULL;
    }

    of_bucket_counter_packet_count_get(src, &val64);
    of_bucket_counter_packet_count_set(dst, val64);

    of_bucket_counter_byte_count_get(src, &val64);
    of_bucket_counter_byte_count_set(dst, val64);

    return dst;
}

/**
 * Duplicate an object of type of_experimenter_stats_header
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_experimenter_stats_header.
 *
 * The caller is responsible for deleting the returned value
 */
of_experimenter_stats_header_t *
of_experimenter_stats_header_OF_VERSION_1_3_dup(
    of_experimenter_stats_header_t *src)
{
    of_experimenter_stats_header_t *dst;
    uint32_t val32;

    if ((dst = of_experimenter_stats_header_new(src->version)) == NULL) {
        return NULL;
    }

    of_experimenter_stats_header_experimenter_get(src, &val32);
    of_experimenter_stats_header_experimenter_set(dst, val32);

    of_experimenter_stats_header_subtype_get(src, &val32);
    of_experimenter_stats_header_subtype_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_flow_stats_entry
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_flow_stats_entry.
 *
 * The caller is responsible for deleting the returned value
 */
of_flow_stats_entry_t *
of_flow_stats_entry_OF_VERSION_1_3_dup(
    of_flow_stats_entry_t *src)
{
    of_flow_stats_entry_t *dst;
    uint8_t val8;
    uint32_t val32;
    uint16_t val16;
    uint64_t val64;
    of_match_t match;

    of_list_instruction_t src_list;
    of_list_instruction_t *dst_list;

    if ((dst = of_flow_stats_entry_new(src->version)) == NULL) {
        return NULL;
    }

    of_flow_stats_entry_table_id_get(src, &val8);
    of_flow_stats_entry_table_id_set(dst, val8);

    of_flow_stats_entry_duration_sec_get(src, &val32);
    of_flow_stats_entry_duration_sec_set(dst, val32);

    of_flow_stats_entry_duration_nsec_get(src, &val32);
    of_flow_stats_entry_duration_nsec_set(dst, val32);

    of_flow_stats_entry_priority_get(src, &val16);
    of_flow_stats_entry_priority_set(dst, val16);

    of_flow_stats_entry_idle_timeout_get(src, &val16);
    of_flow_stats_entry_idle_timeout_set(dst, val16);

    of_flow_stats_entry_hard_timeout_get(src, &val16);
    of_flow_stats_entry_hard_timeout_set(dst, val16);

    of_flow_stats_entry_flags_get(src, &val16);
    of_flow_stats_entry_flags_set(dst, val16);

    of_flow_stats_entry_cookie_get(src, &val64);
    of_flow_stats_entry_cookie_set(dst, val64);

    of_flow_stats_entry_packet_count_get(src, &val64);
    of_flow_stats_entry_packet_count_set(dst, val64);

    of_flow_stats_entry_byte_count_get(src, &val64);
    of_flow_stats_entry_byte_count_set(dst, val64);

    of_flow_stats_entry_match_get(src, &match);
    of_flow_stats_entry_match_set(dst, &match);

    of_flow_stats_entry_instructions_bind(
        src, &src_list);
    dst_list = of_list_instruction_OF_VERSION_1_3_dup(&src_list);
    if (dst_list == NULL) {
        of_flow_stats_entry_delete(dst);
        return NULL;
    }
    of_flow_stats_entry_instructions_set(dst, dst_list);
    of_list_instruction_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_group_desc_stats_entry
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_group_desc_stats_entry.
 *
 * The caller is responsible for deleting the returned value
 */
of_group_desc_stats_entry_t *
of_group_desc_stats_entry_OF_VERSION_1_3_dup(
    of_group_desc_stats_entry_t *src)
{
    of_group_desc_stats_entry_t *dst;
    uint8_t val8;
    uint32_t val32;

    of_list_bucket_t src_list;
    of_list_bucket_t *dst_list;

    if ((dst = of_group_desc_stats_entry_new(src->version)) == NULL) {
        return NULL;
    }

    of_group_desc_stats_entry_group_type_get(src, &val8);
    of_group_desc_stats_entry_group_type_set(dst, val8);

    of_group_desc_stats_entry_group_id_get(src, &val32);
    of_group_desc_stats_entry_group_id_set(dst, val32);

    of_group_desc_stats_entry_buckets_bind(
        src, &src_list);
    dst_list = of_list_bucket_OF_VERSION_1_3_dup(&src_list);
    if (dst_list == NULL) {
        of_group_desc_stats_entry_delete(dst);
        return NULL;
    }
    of_group_desc_stats_entry_buckets_set(dst, dst_list);
    of_list_bucket_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_group_stats_entry
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_group_stats_entry.
 *
 * The caller is responsible for deleting the returned value
 */
of_group_stats_entry_t *
of_group_stats_entry_OF_VERSION_1_3_dup(
    of_group_stats_entry_t *src)
{
    of_group_stats_entry_t *dst;
    uint32_t val32;
    uint64_t val64;

    of_list_bucket_counter_t src_list;
    of_list_bucket_counter_t *dst_list;

    if ((dst = of_group_stats_entry_new(src->version)) == NULL) {
        return NULL;
    }

    of_group_stats_entry_group_id_get(src, &val32);
    of_group_stats_entry_group_id_set(dst, val32);

    of_group_stats_entry_ref_count_get(src, &val32);
    of_group_stats_entry_ref_count_set(dst, val32);

    of_group_stats_entry_packet_count_get(src, &val64);
    of_group_stats_entry_packet_count_set(dst, val64);

    of_group_stats_entry_byte_count_get(src, &val64);
    of_group_stats_entry_byte_count_set(dst, val64);

    of_group_stats_entry_duration_sec_get(src, &val32);
    of_group_stats_entry_duration_sec_set(dst, val32);

    of_group_stats_entry_duration_nsec_get(src, &val32);
    of_group_stats_entry_duration_nsec_set(dst, val32);

    of_group_stats_entry_bucket_stats_bind(
        src, &src_list);
    dst_list = of_list_bucket_counter_OF_VERSION_1_3_dup(&src_list);
    if (dst_list == NULL) {
        of_group_stats_entry_delete(dst);
        return NULL;
    }
    of_group_stats_entry_bucket_stats_set(dst, dst_list);
    of_list_bucket_counter_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_header
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_header.
 *
 * The caller is responsible for deleting the returned value
 */
of_header_t *
of_header_OF_VERSION_1_3_dup(
    of_header_t *src)
{
    of_header_t *dst;
    uint32_t val32;

    if ((dst = of_header_new(src->version)) == NULL) {
        return NULL;
    }

    of_header_xid_get(src, &val32);
    of_header_xid_set(dst, val32);

    return dst;
}

/**
 * Duplicate a super class object of type of_hello_elem
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_hello_elem.
 *
 * The caller is responsible for deleting the returned value
 */
of_hello_elem_t *
of_hello_elem_OF_VERSION_1_3_dup(
    of_hello_elem_t *src)
{

    if (src->header.object_id == OF_HELLO_ELEM_VERSIONBITMAP) {
        return (of_hello_elem_t *)of_hello_elem_versionbitmap_OF_VERSION_1_3_dup(
            &src->versionbitmap);
    }

    return NULL;
}

/**
 * Duplicate an object of type of_hello_elem_header
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_hello_elem_header.
 *
 * The caller is responsible for deleting the returned value
 */
of_hello_elem_header_t *
of_hello_elem_header_OF_VERSION_1_3_dup(
    of_hello_elem_header_t *src)
{
    of_hello_elem_header_t *dst;

    if ((dst = of_hello_elem_header_new(src->version)) == NULL) {
        return NULL;
    }

    return dst;
}

/**
 * Duplicate an object of type of_hello_elem_versionbitmap
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_hello_elem_versionbitmap.
 *
 * The caller is responsible for deleting the returned value
 */
of_hello_elem_versionbitmap_t *
of_hello_elem_versionbitmap_OF_VERSION_1_3_dup(
    of_hello_elem_versionbitmap_t *src)
{
    of_hello_elem_versionbitmap_t *dst;

    of_list_uint32_t src_list;
    of_list_uint32_t *dst_list;

    if ((dst = of_hello_elem_versionbitmap_new(src->version)) == NULL) {
        return NULL;
    }

    of_hello_elem_versionbitmap_bitmaps_bind(
        src, &src_list);
    dst_list = of_list_uint32_OF_VERSION_1_3_dup(&src_list);
    if (dst_list == NULL) {
        of_hello_elem_versionbitmap_delete(dst);
        return NULL;
    }
    of_hello_elem_versionbitmap_bitmaps_set(dst, dst_list);
    of_list_uint32_delete(dst_list);

    return dst;
}

/**
 * Duplicate a super class object of type of_instruction
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_instruction.
 *
 * The caller is responsible for deleting the returned value
 */
of_instruction_t *
of_instruction_OF_VERSION_1_3_dup(
    of_instruction_t *src)
{

    if (src->header.object_id == OF_INSTRUCTION_CLEAR_ACTIONS) {
        return (of_instruction_t *)of_instruction_clear_actions_OF_VERSION_1_3_dup(
            &src->clear_actions);
    }

    if (src->header.object_id == OF_INSTRUCTION_WRITE_ACTIONS) {
        return (of_instruction_t *)of_instruction_write_actions_OF_VERSION_1_3_dup(
            &src->write_actions);
    }

    if (src->header.object_id == OF_INSTRUCTION_GOTO_TABLE) {
        return (of_instruction_t *)of_instruction_goto_table_OF_VERSION_1_3_dup(
            &src->goto_table);
    }

    if (src->header.object_id == OF_INSTRUCTION_METER) {
        return (of_instruction_t *)of_instruction_meter_OF_VERSION_1_3_dup(
            &src->meter);
    }

    if (src->header.object_id == OF_INSTRUCTION_APPLY_ACTIONS) {
        return (of_instruction_t *)of_instruction_apply_actions_OF_VERSION_1_3_dup(
            &src->apply_actions);
    }

    if (src->header.object_id == OF_INSTRUCTION_EXPERIMENTER) {
        return (of_instruction_t *)of_instruction_experimenter_OF_VERSION_1_3_dup(
            &src->experimenter);
    }

    if (src->header.object_id == OF_INSTRUCTION_WRITE_METADATA) {
        return (of_instruction_t *)of_instruction_write_metadata_OF_VERSION_1_3_dup(
            &src->write_metadata);
    }

    return NULL;
}

/**
 * Duplicate an object of type of_instruction_apply_actions
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_instruction_apply_actions.
 *
 * The caller is responsible for deleting the returned value
 */
of_instruction_apply_actions_t *
of_instruction_apply_actions_OF_VERSION_1_3_dup(
    of_instruction_apply_actions_t *src)
{
    of_instruction_apply_actions_t *dst;

    of_list_action_t src_list;
    of_list_action_t *dst_list;

    if ((dst = of_instruction_apply_actions_new(src->version)) == NULL) {
        return NULL;
    }

    of_instruction_apply_actions_actions_bind(
        src, &src_list);
    dst_list = of_list_action_OF_VERSION_1_3_dup(&src_list);
    if (dst_list == NULL) {
        of_instruction_apply_actions_delete(dst);
        return NULL;
    }
    of_instruction_apply_actions_actions_set(dst, dst_list);
    of_list_action_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_instruction_clear_actions
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_instruction_clear_actions.
 *
 * The caller is responsible for deleting the returned value
 */
of_instruction_clear_actions_t *
of_instruction_clear_actions_OF_VERSION_1_3_dup(
    of_instruction_clear_actions_t *src)
{
    of_instruction_clear_actions_t *dst;

    if ((dst = of_instruction_clear_actions_new(src->version)) == NULL) {
        return NULL;
    }

    return dst;
}

/**
 * Duplicate an object of type of_instruction_experimenter
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_instruction_experimenter.
 *
 * The caller is responsible for deleting the returned value
 */
of_instruction_experimenter_t *
of_instruction_experimenter_OF_VERSION_1_3_dup(
    of_instruction_experimenter_t *src)
{
    of_instruction_experimenter_t *dst;
    uint32_t val32;
    of_octets_t octets;

    if ((dst = of_instruction_experimenter_new(src->version)) == NULL) {
        return NULL;
    }

    of_instruction_experimenter_experimenter_get(src, &val32);
    of_instruction_experimenter_experimenter_set(dst, val32);

    of_instruction_experimenter_data_get(src, &octets);
    of_instruction_experimenter_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_instruction_goto_table
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_instruction_goto_table.
 *
 * The caller is responsible for deleting the returned value
 */
of_instruction_goto_table_t *
of_instruction_goto_table_OF_VERSION_1_3_dup(
    of_instruction_goto_table_t *src)
{
    of_instruction_goto_table_t *dst;
    uint8_t val8;

    if ((dst = of_instruction_goto_table_new(src->version)) == NULL) {
        return NULL;
    }

    of_instruction_goto_table_table_id_get(src, &val8);
    of_instruction_goto_table_table_id_set(dst, val8);

    return dst;
}

/**
 * Duplicate an object of type of_instruction_header
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_instruction_header.
 *
 * The caller is responsible for deleting the returned value
 */
of_instruction_header_t *
of_instruction_header_OF_VERSION_1_3_dup(
    of_instruction_header_t *src)
{
    of_instruction_header_t *dst;

    if ((dst = of_instruction_header_new(src->version)) == NULL) {
        return NULL;
    }

    return dst;
}

/**
 * Duplicate an object of type of_instruction_meter
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_instruction_meter.
 *
 * The caller is responsible for deleting the returned value
 */
of_instruction_meter_t *
of_instruction_meter_OF_VERSION_1_3_dup(
    of_instruction_meter_t *src)
{
    of_instruction_meter_t *dst;
    uint32_t val32;

    if ((dst = of_instruction_meter_new(src->version)) == NULL) {
        return NULL;
    }

    of_instruction_meter_meter_id_get(src, &val32);
    of_instruction_meter_meter_id_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_instruction_write_actions
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_instruction_write_actions.
 *
 * The caller is responsible for deleting the returned value
 */
of_instruction_write_actions_t *
of_instruction_write_actions_OF_VERSION_1_3_dup(
    of_instruction_write_actions_t *src)
{
    of_instruction_write_actions_t *dst;

    of_list_action_t src_list;
    of_list_action_t *dst_list;

    if ((dst = of_instruction_write_actions_new(src->version)) == NULL) {
        return NULL;
    }

    of_instruction_write_actions_actions_bind(
        src, &src_list);
    dst_list = of_list_action_OF_VERSION_1_3_dup(&src_list);
    if (dst_list == NULL) {
        of_instruction_write_actions_delete(dst);
        return NULL;
    }
    of_instruction_write_actions_actions_set(dst, dst_list);
    of_list_action_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_instruction_write_metadata
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_instruction_write_metadata.
 *
 * The caller is responsible for deleting the returned value
 */
of_instruction_write_metadata_t *
of_instruction_write_metadata_OF_VERSION_1_3_dup(
    of_instruction_write_metadata_t *src)
{
    of_instruction_write_metadata_t *dst;
    uint64_t val64;

    if ((dst = of_instruction_write_metadata_new(src->version)) == NULL) {
        return NULL;
    }

    of_instruction_write_metadata_metadata_get(src, &val64);
    of_instruction_write_metadata_metadata_set(dst, val64);

    of_instruction_write_metadata_metadata_mask_get(src, &val64);
    of_instruction_write_metadata_metadata_mask_set(dst, val64);

    return dst;
}

/**
 * Duplicate an object of type of_match_v3
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_match_v3.
 *
 * The caller is responsible for deleting the returned value
 */
of_match_v3_t *
of_match_v3_OF_VERSION_1_3_dup(
    of_match_v3_t *src)
{
    of_match_v3_t *dst;

    of_list_oxm_t src_list;
    of_list_oxm_t *dst_list;

    if ((dst = of_match_v3_new(src->version)) == NULL) {
        return NULL;
    }

    of_match_v3_oxm_list_bind(
        src, &src_list);
    dst_list = of_list_oxm_OF_VERSION_1_3_dup(&src_list);
    if (dst_list == NULL) {
        of_match_v3_delete(dst);
        return NULL;
    }
    of_match_v3_oxm_list_set(dst, dst_list);
    of_list_oxm_delete(dst_list);

    return dst;
}

/**
 * Duplicate a super class object of type of_meter_band
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_meter_band.
 *
 * The caller is responsible for deleting the returned value
 */
of_meter_band_t *
of_meter_band_OF_VERSION_1_3_dup(
    of_meter_band_t *src)
{

    if (src->header.object_id == OF_METER_BAND_DSCP_REMARK) {
        return (of_meter_band_t *)of_meter_band_dscp_remark_OF_VERSION_1_3_dup(
            &src->dscp_remark);
    }

    if (src->header.object_id == OF_METER_BAND_DROP) {
        return (of_meter_band_t *)of_meter_band_drop_OF_VERSION_1_3_dup(
            &src->drop);
    }

    if (src->header.object_id == OF_METER_BAND_EXPERIMENTER) {
        return (of_meter_band_t *)of_meter_band_experimenter_OF_VERSION_1_3_dup(
            &src->experimenter);
    }

    return NULL;
}

/**
 * Duplicate an object of type of_meter_band_drop
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_meter_band_drop.
 *
 * The caller is responsible for deleting the returned value
 */
of_meter_band_drop_t *
of_meter_band_drop_OF_VERSION_1_3_dup(
    of_meter_band_drop_t *src)
{
    of_meter_band_drop_t *dst;
    uint32_t val32;

    if ((dst = of_meter_band_drop_new(src->version)) == NULL) {
        return NULL;
    }

    of_meter_band_drop_rate_get(src, &val32);
    of_meter_band_drop_rate_set(dst, val32);

    of_meter_band_drop_burst_size_get(src, &val32);
    of_meter_band_drop_burst_size_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_meter_band_dscp_remark
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_meter_band_dscp_remark.
 *
 * The caller is responsible for deleting the returned value
 */
of_meter_band_dscp_remark_t *
of_meter_band_dscp_remark_OF_VERSION_1_3_dup(
    of_meter_band_dscp_remark_t *src)
{
    of_meter_band_dscp_remark_t *dst;
    uint32_t val32;
    uint8_t val8;

    if ((dst = of_meter_band_dscp_remark_new(src->version)) == NULL) {
        return NULL;
    }

    of_meter_band_dscp_remark_rate_get(src, &val32);
    of_meter_band_dscp_remark_rate_set(dst, val32);

    of_meter_band_dscp_remark_burst_size_get(src, &val32);
    of_meter_band_dscp_remark_burst_size_set(dst, val32);

    of_meter_band_dscp_remark_prec_level_get(src, &val8);
    of_meter_band_dscp_remark_prec_level_set(dst, val8);

    return dst;
}

/**
 * Duplicate an object of type of_meter_band_experimenter
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_meter_band_experimenter.
 *
 * The caller is responsible for deleting the returned value
 */
of_meter_band_experimenter_t *
of_meter_band_experimenter_OF_VERSION_1_3_dup(
    of_meter_band_experimenter_t *src)
{
    of_meter_band_experimenter_t *dst;
    uint32_t val32;

    if ((dst = of_meter_band_experimenter_new(src->version)) == NULL) {
        return NULL;
    }

    of_meter_band_experimenter_rate_get(src, &val32);
    of_meter_band_experimenter_rate_set(dst, val32);

    of_meter_band_experimenter_burst_size_get(src, &val32);
    of_meter_band_experimenter_burst_size_set(dst, val32);

    of_meter_band_experimenter_experimenter_get(src, &val32);
    of_meter_band_experimenter_experimenter_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_meter_band_header
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_meter_band_header.
 *
 * The caller is responsible for deleting the returned value
 */
of_meter_band_header_t *
of_meter_band_header_OF_VERSION_1_3_dup(
    of_meter_band_header_t *src)
{
    of_meter_band_header_t *dst;

    if ((dst = of_meter_band_header_new(src->version)) == NULL) {
        return NULL;
    }

    return dst;
}

/**
 * Duplicate an object of type of_meter_band_stats
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_meter_band_stats.
 *
 * The caller is responsible for deleting the returned value
 */
of_meter_band_stats_t *
of_meter_band_stats_OF_VERSION_1_3_dup(
    of_meter_band_stats_t *src)
{
    of_meter_band_stats_t *dst;
    uint64_t val64;

    if ((dst = of_meter_band_stats_new(src->version)) == NULL) {
        return NULL;
    }

    of_meter_band_stats_packet_band_count_get(src, &val64);
    of_meter_band_stats_packet_band_count_set(dst, val64);

    of_meter_band_stats_byte_band_count_get(src, &val64);
    of_meter_band_stats_byte_band_count_set(dst, val64);

    return dst;
}

/**
 * Duplicate an object of type of_meter_config
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_meter_config.
 *
 * The caller is responsible for deleting the returned value
 */
of_meter_config_t *
of_meter_config_OF_VERSION_1_3_dup(
    of_meter_config_t *src)
{
    of_meter_config_t *dst;
    uint16_t val16;
    uint32_t val32;

    of_list_meter_band_t src_list;
    of_list_meter_band_t *dst_list;

    if ((dst = of_meter_config_new(src->version)) == NULL) {
        return NULL;
    }

    of_meter_config_flags_get(src, &val16);
    of_meter_config_flags_set(dst, val16);

    of_meter_config_meter_id_get(src, &val32);
    of_meter_config_meter_id_set(dst, val32);

    of_meter_config_entries_bind(
        src, &src_list);
    dst_list = of_list_meter_band_OF_VERSION_1_3_dup(&src_list);
    if (dst_list == NULL) {
        of_meter_config_delete(dst);
        return NULL;
    }
    of_meter_config_entries_set(dst, dst_list);
    of_list_meter_band_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_meter_features
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_meter_features.
 *
 * The caller is responsible for deleting the returned value
 */
of_meter_features_t *
of_meter_features_OF_VERSION_1_3_dup(
    of_meter_features_t *src)
{
    of_meter_features_t *dst;
    uint32_t val32;
    uint8_t val8;

    if ((dst = of_meter_features_new(src->version)) == NULL) {
        return NULL;
    }

    of_meter_features_max_meter_get(src, &val32);
    of_meter_features_max_meter_set(dst, val32);

    of_meter_features_band_types_get(src, &val32);
    of_meter_features_band_types_set(dst, val32);

    of_meter_features_capabilities_get(src, &val32);
    of_meter_features_capabilities_set(dst, val32);

    of_meter_features_max_bands_get(src, &val8);
    of_meter_features_max_bands_set(dst, val8);

    of_meter_features_max_color_get(src, &val8);
    of_meter_features_max_color_set(dst, val8);

    return dst;
}

/**
 * Duplicate an object of type of_meter_stats
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_meter_stats.
 *
 * The caller is responsible for deleting the returned value
 */
of_meter_stats_t *
of_meter_stats_OF_VERSION_1_3_dup(
    of_meter_stats_t *src)
{
    of_meter_stats_t *dst;
    uint32_t val32;
    uint64_t val64;

    of_list_meter_band_stats_t src_list;
    of_list_meter_band_stats_t *dst_list;

    if ((dst = of_meter_stats_new(src->version)) == NULL) {
        return NULL;
    }

    of_meter_stats_meter_id_get(src, &val32);
    of_meter_stats_meter_id_set(dst, val32);

    of_meter_stats_flow_count_get(src, &val32);
    of_meter_stats_flow_count_set(dst, val32);

    of_meter_stats_packet_in_count_get(src, &val64);
    of_meter_stats_packet_in_count_set(dst, val64);

    of_meter_stats_byte_in_count_get(src, &val64);
    of_meter_stats_byte_in_count_set(dst, val64);

    of_meter_stats_duration_sec_get(src, &val32);
    of_meter_stats_duration_sec_set(dst, val32);

    of_meter_stats_duration_nsec_get(src, &val32);
    of_meter_stats_duration_nsec_set(dst, val32);

    of_meter_stats_band_stats_bind(
        src, &src_list);
    dst_list = of_list_meter_band_stats_OF_VERSION_1_3_dup(&src_list);
    if (dst_list == NULL) {
        of_meter_stats_delete(dst);
        return NULL;
    }
    of_meter_stats_band_stats_set(dst, dst_list);
    of_list_meter_band_stats_delete(dst_list);

    return dst;
}

/**
 * Duplicate a super class object of type of_oxm
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_t *
of_oxm_OF_VERSION_1_3_dup(
    of_oxm_t *src)
{

    if (src->header.object_id == OF_OXM_MPLS_TC_MASKED) {
        return (of_oxm_t *)of_oxm_mpls_tc_masked_OF_VERSION_1_3_dup(
            &src->mpls_tc_masked);
    }

    if (src->header.object_id == OF_OXM_ARP_SHA) {
        return (of_oxm_t *)of_oxm_arp_sha_OF_VERSION_1_3_dup(
            &src->arp_sha);
    }

    if (src->header.object_id == OF_OXM_ETH_SRC_MASKED) {
        return (of_oxm_t *)of_oxm_eth_src_masked_OF_VERSION_1_3_dup(
            &src->eth_src_masked);
    }

    if (src->header.object_id == OF_OXM_ETH_DST) {
        return (of_oxm_t *)of_oxm_eth_dst_OF_VERSION_1_3_dup(
            &src->eth_dst);
    }

    if (src->header.object_id == OF_OXM_VLAN_PCP_MASKED) {
        return (of_oxm_t *)of_oxm_vlan_pcp_masked_OF_VERSION_1_3_dup(
            &src->vlan_pcp_masked);
    }

    if (src->header.object_id == OF_OXM_ARP_OP) {
        return (of_oxm_t *)of_oxm_arp_op_OF_VERSION_1_3_dup(
            &src->arp_op);
    }

    if (src->header.object_id == OF_OXM_ETH_TYPE) {
        return (of_oxm_t *)of_oxm_eth_type_OF_VERSION_1_3_dup(
            &src->eth_type);
    }

    if (src->header.object_id == OF_OXM_BSN_IN_PORTS_128_MASKED) {
        return (of_oxm_t *)of_oxm_bsn_in_ports_128_masked_OF_VERSION_1_3_dup(
            &src->bsn_in_ports_128_masked);
    }

    if (src->header.object_id == OF_OXM_ARP_SPA) {
        return (of_oxm_t *)of_oxm_arp_spa_OF_VERSION_1_3_dup(
            &src->arp_spa);
    }

    if (src->header.object_id == OF_OXM_ICMPV4_TYPE_MASKED) {
        return (of_oxm_t *)of_oxm_icmpv4_type_masked_OF_VERSION_1_3_dup(
            &src->icmpv4_type_masked);
    }

    if (src->header.object_id == OF_OXM_ARP_SHA_MASKED) {
        return (of_oxm_t *)of_oxm_arp_sha_masked_OF_VERSION_1_3_dup(
            &src->arp_sha_masked);
    }

    if (src->header.object_id == OF_OXM_UDP_DST) {
        return (of_oxm_t *)of_oxm_udp_dst_OF_VERSION_1_3_dup(
            &src->udp_dst);
    }

    if (src->header.object_id == OF_OXM_BSN_VRF_MASKED) {
        return (of_oxm_t *)of_oxm_bsn_vrf_masked_OF_VERSION_1_3_dup(
            &src->bsn_vrf_masked);
    }

    if (src->header.object_id == OF_OXM_IPV6_ND_TARGET) {
        return (of_oxm_t *)of_oxm_ipv6_nd_target_OF_VERSION_1_3_dup(
            &src->ipv6_nd_target);
    }

    if (src->header.object_id == OF_OXM_ETH_TYPE_MASKED) {
        return (of_oxm_t *)of_oxm_eth_type_masked_OF_VERSION_1_3_dup(
            &src->eth_type_masked);
    }

    if (src->header.object_id == OF_OXM_BSN_GLOBAL_VRF_ALLOWED_MASKED) {
        return (of_oxm_t *)of_oxm_bsn_global_vrf_allowed_masked_OF_VERSION_1_3_dup(
            &src->bsn_global_vrf_allowed_masked);
    }

    if (src->header.object_id == OF_OXM_ICMPV4_TYPE) {
        return (of_oxm_t *)of_oxm_icmpv4_type_OF_VERSION_1_3_dup(
            &src->icmpv4_type);
    }

    if (src->header.object_id == OF_OXM_UDP_DST_MASKED) {
        return (of_oxm_t *)of_oxm_udp_dst_masked_OF_VERSION_1_3_dup(
            &src->udp_dst_masked);
    }

    if (src->header.object_id == OF_OXM_TCP_DST) {
        return (of_oxm_t *)of_oxm_tcp_dst_OF_VERSION_1_3_dup(
            &src->tcp_dst);
    }

    if (src->header.object_id == OF_OXM_IP_PROTO) {
        return (of_oxm_t *)of_oxm_ip_proto_OF_VERSION_1_3_dup(
            &src->ip_proto);
    }

    if (src->header.object_id == OF_OXM_IP_DSCP) {
        return (of_oxm_t *)of_oxm_ip_dscp_OF_VERSION_1_3_dup(
            &src->ip_dscp);
    }

    if (src->header.object_id == OF_OXM_ARP_SPA_MASKED) {
        return (of_oxm_t *)of_oxm_arp_spa_masked_OF_VERSION_1_3_dup(
            &src->arp_spa_masked);
    }

    if (src->header.object_id == OF_OXM_IPV6_FLABEL) {
        return (of_oxm_t *)of_oxm_ipv6_flabel_OF_VERSION_1_3_dup(
            &src->ipv6_flabel);
    }

    if (src->header.object_id == OF_OXM_IPV6_ND_TLL_MASKED) {
        return (of_oxm_t *)of_oxm_ipv6_nd_tll_masked_OF_VERSION_1_3_dup(
            &src->ipv6_nd_tll_masked);
    }

    if (src->header.object_id == OF_OXM_ARP_TPA) {
        return (of_oxm_t *)of_oxm_arp_tpa_OF_VERSION_1_3_dup(
            &src->arp_tpa);
    }

    if (src->header.object_id == OF_OXM_SCTP_SRC) {
        return (of_oxm_t *)of_oxm_sctp_src_OF_VERSION_1_3_dup(
            &src->sctp_src);
    }

    if (src->header.object_id == OF_OXM_IPV6_SRC) {
        return (of_oxm_t *)of_oxm_ipv6_src_OF_VERSION_1_3_dup(
            &src->ipv6_src);
    }

    if (src->header.object_id == OF_OXM_METADATA_MASKED) {
        return (of_oxm_t *)of_oxm_metadata_masked_OF_VERSION_1_3_dup(
            &src->metadata_masked);
    }

    if (src->header.object_id == OF_OXM_IPV6_ND_SLL) {
        return (of_oxm_t *)of_oxm_ipv6_nd_sll_OF_VERSION_1_3_dup(
            &src->ipv6_nd_sll);
    }

    if (src->header.object_id == OF_OXM_VLAN_VID) {
        return (of_oxm_t *)of_oxm_vlan_vid_OF_VERSION_1_3_dup(
            &src->vlan_vid);
    }

    if (src->header.object_id == OF_OXM_ARP_THA) {
        return (of_oxm_t *)of_oxm_arp_tha_OF_VERSION_1_3_dup(
            &src->arp_tha);
    }

    if (src->header.object_id == OF_OXM_METADATA) {
        return (of_oxm_t *)of_oxm_metadata_OF_VERSION_1_3_dup(
            &src->metadata);
    }

    if (src->header.object_id == OF_OXM_SCTP_DST) {
        return (of_oxm_t *)of_oxm_sctp_dst_OF_VERSION_1_3_dup(
            &src->sctp_dst);
    }

    if (src->header.object_id == OF_OXM_BSN_L3_SRC_CLASS_ID) {
        return (of_oxm_t *)of_oxm_bsn_l3_src_class_id_OF_VERSION_1_3_dup(
            &src->bsn_l3_src_class_id);
    }

    if (src->header.object_id == OF_OXM_ETH_DST_MASKED) {
        return (of_oxm_t *)of_oxm_eth_dst_masked_OF_VERSION_1_3_dup(
            &src->eth_dst_masked);
    }

    if (src->header.object_id == OF_OXM_IN_PORT_MASKED) {
        return (of_oxm_t *)of_oxm_in_port_masked_OF_VERSION_1_3_dup(
            &src->in_port_masked);
    }

    if (src->header.object_id == OF_OXM_IP_ECN) {
        return (of_oxm_t *)of_oxm_ip_ecn_OF_VERSION_1_3_dup(
            &src->ip_ecn);
    }

    if (src->header.object_id == OF_OXM_ICMPV4_CODE_MASKED) {
        return (of_oxm_t *)of_oxm_icmpv4_code_masked_OF_VERSION_1_3_dup(
            &src->icmpv4_code_masked);
    }

    if (src->header.object_id == OF_OXM_TCP_DST_MASKED) {
        return (of_oxm_t *)of_oxm_tcp_dst_masked_OF_VERSION_1_3_dup(
            &src->tcp_dst_masked);
    }

    if (src->header.object_id == OF_OXM_TCP_SRC_MASKED) {
        return (of_oxm_t *)of_oxm_tcp_src_masked_OF_VERSION_1_3_dup(
            &src->tcp_src_masked);
    }

    if (src->header.object_id == OF_OXM_IPV4_DST) {
        return (of_oxm_t *)of_oxm_ipv4_dst_OF_VERSION_1_3_dup(
            &src->ipv4_dst);
    }

    if (src->header.object_id == OF_OXM_IPV4_DST_MASKED) {
        return (of_oxm_t *)of_oxm_ipv4_dst_masked_OF_VERSION_1_3_dup(
            &src->ipv4_dst_masked);
    }

    if (src->header.object_id == OF_OXM_IPV6_ND_TLL) {
        return (of_oxm_t *)of_oxm_ipv6_nd_tll_OF_VERSION_1_3_dup(
            &src->ipv6_nd_tll);
    }

    if (src->header.object_id == OF_OXM_IP_PROTO_MASKED) {
        return (of_oxm_t *)of_oxm_ip_proto_masked_OF_VERSION_1_3_dup(
            &src->ip_proto_masked);
    }

    if (src->header.object_id == OF_OXM_IN_PHY_PORT_MASKED) {
        return (of_oxm_t *)of_oxm_in_phy_port_masked_OF_VERSION_1_3_dup(
            &src->in_phy_port_masked);
    }

    if (src->header.object_id == OF_OXM_BSN_LAG_ID) {
        return (of_oxm_t *)of_oxm_bsn_lag_id_OF_VERSION_1_3_dup(
            &src->bsn_lag_id);
    }

    if (src->header.object_id == OF_OXM_IPV6_DST_MASKED) {
        return (of_oxm_t *)of_oxm_ipv6_dst_masked_OF_VERSION_1_3_dup(
            &src->ipv6_dst_masked);
    }

    if (src->header.object_id == OF_OXM_VLAN_PCP) {
        return (of_oxm_t *)of_oxm_vlan_pcp_OF_VERSION_1_3_dup(
            &src->vlan_pcp);
    }

    if (src->header.object_id == OF_OXM_IPV4_SRC) {
        return (of_oxm_t *)of_oxm_ipv4_src_OF_VERSION_1_3_dup(
            &src->ipv4_src);
    }

    if (src->header.object_id == OF_OXM_IPV6_DST) {
        return (of_oxm_t *)of_oxm_ipv6_dst_OF_VERSION_1_3_dup(
            &src->ipv6_dst);
    }

    if (src->header.object_id == OF_OXM_IPV4_SRC_MASKED) {
        return (of_oxm_t *)of_oxm_ipv4_src_masked_OF_VERSION_1_3_dup(
            &src->ipv4_src_masked);
    }

    if (src->header.object_id == OF_OXM_ARP_OP_MASKED) {
        return (of_oxm_t *)of_oxm_arp_op_masked_OF_VERSION_1_3_dup(
            &src->arp_op_masked);
    }

    if (src->header.object_id == OF_OXM_ETH_SRC) {
        return (of_oxm_t *)of_oxm_eth_src_OF_VERSION_1_3_dup(
            &src->eth_src);
    }

    if (src->header.object_id == OF_OXM_ICMPV6_CODE) {
        return (of_oxm_t *)of_oxm_icmpv6_code_OF_VERSION_1_3_dup(
            &src->icmpv6_code);
    }

    if (src->header.object_id == OF_OXM_ICMPV6_CODE_MASKED) {
        return (of_oxm_t *)of_oxm_icmpv6_code_masked_OF_VERSION_1_3_dup(
            &src->icmpv6_code_masked);
    }

    if (src->header.object_id == OF_OXM_UDP_SRC_MASKED) {
        return (of_oxm_t *)of_oxm_udp_src_masked_OF_VERSION_1_3_dup(
            &src->udp_src_masked);
    }

    if (src->header.object_id == OF_OXM_IP_ECN_MASKED) {
        return (of_oxm_t *)of_oxm_ip_ecn_masked_OF_VERSION_1_3_dup(
            &src->ip_ecn_masked);
    }

    if (src->header.object_id == OF_OXM_UDP_SRC) {
        return (of_oxm_t *)of_oxm_udp_src_OF_VERSION_1_3_dup(
            &src->udp_src);
    }

    if (src->header.object_id == OF_OXM_VLAN_VID_MASKED) {
        return (of_oxm_t *)of_oxm_vlan_vid_masked_OF_VERSION_1_3_dup(
            &src->vlan_vid_masked);
    }

    if (src->header.object_id == OF_OXM_ARP_THA_MASKED) {
        return (of_oxm_t *)of_oxm_arp_tha_masked_OF_VERSION_1_3_dup(
            &src->arp_tha_masked);
    }

    if (src->header.object_id == OF_OXM_SCTP_SRC_MASKED) {
        return (of_oxm_t *)of_oxm_sctp_src_masked_OF_VERSION_1_3_dup(
            &src->sctp_src_masked);
    }

    if (src->header.object_id == OF_OXM_IN_PORT) {
        return (of_oxm_t *)of_oxm_in_port_OF_VERSION_1_3_dup(
            &src->in_port);
    }

    if (src->header.object_id == OF_OXM_BSN_L3_INTERFACE_CLASS_ID) {
        return (of_oxm_t *)of_oxm_bsn_l3_interface_class_id_OF_VERSION_1_3_dup(
            &src->bsn_l3_interface_class_id);
    }

    if (src->header.object_id == OF_OXM_IPV6_ND_SLL_MASKED) {
        return (of_oxm_t *)of_oxm_ipv6_nd_sll_masked_OF_VERSION_1_3_dup(
            &src->ipv6_nd_sll_masked);
    }

    if (src->header.object_id == OF_OXM_TCP_SRC) {
        return (of_oxm_t *)of_oxm_tcp_src_OF_VERSION_1_3_dup(
            &src->tcp_src);
    }

    if (src->header.object_id == OF_OXM_IPV6_ND_TARGET_MASKED) {
        return (of_oxm_t *)of_oxm_ipv6_nd_target_masked_OF_VERSION_1_3_dup(
            &src->ipv6_nd_target_masked);
    }

    if (src->header.object_id == OF_OXM_ICMPV6_TYPE_MASKED) {
        return (of_oxm_t *)of_oxm_icmpv6_type_masked_OF_VERSION_1_3_dup(
            &src->icmpv6_type_masked);
    }

    if (src->header.object_id == OF_OXM_MPLS_LABEL) {
        return (of_oxm_t *)of_oxm_mpls_label_OF_VERSION_1_3_dup(
            &src->mpls_label);
    }

    if (src->header.object_id == OF_OXM_BSN_IN_PORTS_128) {
        return (of_oxm_t *)of_oxm_bsn_in_ports_128_OF_VERSION_1_3_dup(
            &src->bsn_in_ports_128);
    }

    if (src->header.object_id == OF_OXM_BSN_L3_SRC_CLASS_ID_MASKED) {
        return (of_oxm_t *)of_oxm_bsn_l3_src_class_id_masked_OF_VERSION_1_3_dup(
            &src->bsn_l3_src_class_id_masked);
    }

    if (src->header.object_id == OF_OXM_IPV6_FLABEL_MASKED) {
        return (of_oxm_t *)of_oxm_ipv6_flabel_masked_OF_VERSION_1_3_dup(
            &src->ipv6_flabel_masked);
    }

    if (src->header.object_id == OF_OXM_BSN_LAG_ID_MASKED) {
        return (of_oxm_t *)of_oxm_bsn_lag_id_masked_OF_VERSION_1_3_dup(
            &src->bsn_lag_id_masked);
    }

    if (src->header.object_id == OF_OXM_IP_DSCP_MASKED) {
        return (of_oxm_t *)of_oxm_ip_dscp_masked_OF_VERSION_1_3_dup(
            &src->ip_dscp_masked);
    }

    if (src->header.object_id == OF_OXM_ICMPV6_TYPE) {
        return (of_oxm_t *)of_oxm_icmpv6_type_OF_VERSION_1_3_dup(
            &src->icmpv6_type);
    }

    if (src->header.object_id == OF_OXM_BSN_L3_INTERFACE_CLASS_ID_MASKED) {
        return (of_oxm_t *)of_oxm_bsn_l3_interface_class_id_masked_OF_VERSION_1_3_dup(
            &src->bsn_l3_interface_class_id_masked);
    }

    if (src->header.object_id == OF_OXM_MPLS_TC) {
        return (of_oxm_t *)of_oxm_mpls_tc_OF_VERSION_1_3_dup(
            &src->mpls_tc);
    }

    if (src->header.object_id == OF_OXM_BSN_L3_DST_CLASS_ID_MASKED) {
        return (of_oxm_t *)of_oxm_bsn_l3_dst_class_id_masked_OF_VERSION_1_3_dup(
            &src->bsn_l3_dst_class_id_masked);
    }

    if (src->header.object_id == OF_OXM_ARP_TPA_MASKED) {
        return (of_oxm_t *)of_oxm_arp_tpa_masked_OF_VERSION_1_3_dup(
            &src->arp_tpa_masked);
    }

    if (src->header.object_id == OF_OXM_SCTP_DST_MASKED) {
        return (of_oxm_t *)of_oxm_sctp_dst_masked_OF_VERSION_1_3_dup(
            &src->sctp_dst_masked);
    }

    if (src->header.object_id == OF_OXM_ICMPV4_CODE) {
        return (of_oxm_t *)of_oxm_icmpv4_code_OF_VERSION_1_3_dup(
            &src->icmpv4_code);
    }

    if (src->header.object_id == OF_OXM_BSN_VRF) {
        return (of_oxm_t *)of_oxm_bsn_vrf_OF_VERSION_1_3_dup(
            &src->bsn_vrf);
    }

    if (src->header.object_id == OF_OXM_IPV6_SRC_MASKED) {
        return (of_oxm_t *)of_oxm_ipv6_src_masked_OF_VERSION_1_3_dup(
            &src->ipv6_src_masked);
    }

    if (src->header.object_id == OF_OXM_BSN_GLOBAL_VRF_ALLOWED) {
        return (of_oxm_t *)of_oxm_bsn_global_vrf_allowed_OF_VERSION_1_3_dup(
            &src->bsn_global_vrf_allowed);
    }

    if (src->header.object_id == OF_OXM_IN_PHY_PORT) {
        return (of_oxm_t *)of_oxm_in_phy_port_OF_VERSION_1_3_dup(
            &src->in_phy_port);
    }

    if (src->header.object_id == OF_OXM_MPLS_LABEL_MASKED) {
        return (of_oxm_t *)of_oxm_mpls_label_masked_OF_VERSION_1_3_dup(
            &src->mpls_label_masked);
    }

    if (src->header.object_id == OF_OXM_BSN_L3_DST_CLASS_ID) {
        return (of_oxm_t *)of_oxm_bsn_l3_dst_class_id_OF_VERSION_1_3_dup(
            &src->bsn_l3_dst_class_id);
    }

    return NULL;
}

/**
 * Duplicate an object of type of_oxm_arp_op
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_arp_op.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_arp_op_t *
of_oxm_arp_op_OF_VERSION_1_3_dup(
    of_oxm_arp_op_t *src)
{
    of_oxm_arp_op_t *dst;
    uint16_t val16;

    if ((dst = of_oxm_arp_op_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_arp_op_value_get(src, &val16);
    of_oxm_arp_op_value_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_arp_op_masked
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_arp_op_masked.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_arp_op_masked_t *
of_oxm_arp_op_masked_OF_VERSION_1_3_dup(
    of_oxm_arp_op_masked_t *src)
{
    of_oxm_arp_op_masked_t *dst;
    uint16_t val16;

    if ((dst = of_oxm_arp_op_masked_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_arp_op_masked_value_get(src, &val16);
    of_oxm_arp_op_masked_value_set(dst, val16);

    of_oxm_arp_op_masked_value_mask_get(src, &val16);
    of_oxm_arp_op_masked_value_mask_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_arp_sha
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_arp_sha.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_arp_sha_t *
of_oxm_arp_sha_OF_VERSION_1_3_dup(
    of_oxm_arp_sha_t *src)
{
    of_oxm_arp_sha_t *dst;
    of_mac_addr_t mac_addr;

    if ((dst = of_oxm_arp_sha_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_arp_sha_value_get(src, &mac_addr);
    of_oxm_arp_sha_value_set(dst, mac_addr);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_arp_sha_masked
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_arp_sha_masked.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_arp_sha_masked_t *
of_oxm_arp_sha_masked_OF_VERSION_1_3_dup(
    of_oxm_arp_sha_masked_t *src)
{
    of_oxm_arp_sha_masked_t *dst;
    of_mac_addr_t mac_addr;

    if ((dst = of_oxm_arp_sha_masked_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_arp_sha_masked_value_get(src, &mac_addr);
    of_oxm_arp_sha_masked_value_set(dst, mac_addr);

    of_oxm_arp_sha_masked_value_mask_get(src, &mac_addr);
    of_oxm_arp_sha_masked_value_mask_set(dst, mac_addr);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_arp_spa
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_arp_spa.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_arp_spa_t *
of_oxm_arp_spa_OF_VERSION_1_3_dup(
    of_oxm_arp_spa_t *src)
{
    of_oxm_arp_spa_t *dst;
    uint32_t val32;

    if ((dst = of_oxm_arp_spa_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_arp_spa_value_get(src, &val32);
    of_oxm_arp_spa_value_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_arp_spa_masked
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_arp_spa_masked.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_arp_spa_masked_t *
of_oxm_arp_spa_masked_OF_VERSION_1_3_dup(
    of_oxm_arp_spa_masked_t *src)
{
    of_oxm_arp_spa_masked_t *dst;
    uint32_t val32;

    if ((dst = of_oxm_arp_spa_masked_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_arp_spa_masked_value_get(src, &val32);
    of_oxm_arp_spa_masked_value_set(dst, val32);

    of_oxm_arp_spa_masked_value_mask_get(src, &val32);
    of_oxm_arp_spa_masked_value_mask_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_arp_tha
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_arp_tha.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_arp_tha_t *
of_oxm_arp_tha_OF_VERSION_1_3_dup(
    of_oxm_arp_tha_t *src)
{
    of_oxm_arp_tha_t *dst;
    of_mac_addr_t mac_addr;

    if ((dst = of_oxm_arp_tha_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_arp_tha_value_get(src, &mac_addr);
    of_oxm_arp_tha_value_set(dst, mac_addr);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_arp_tha_masked
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_arp_tha_masked.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_arp_tha_masked_t *
of_oxm_arp_tha_masked_OF_VERSION_1_3_dup(
    of_oxm_arp_tha_masked_t *src)
{
    of_oxm_arp_tha_masked_t *dst;
    of_mac_addr_t mac_addr;

    if ((dst = of_oxm_arp_tha_masked_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_arp_tha_masked_value_get(src, &mac_addr);
    of_oxm_arp_tha_masked_value_set(dst, mac_addr);

    of_oxm_arp_tha_masked_value_mask_get(src, &mac_addr);
    of_oxm_arp_tha_masked_value_mask_set(dst, mac_addr);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_arp_tpa
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_arp_tpa.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_arp_tpa_t *
of_oxm_arp_tpa_OF_VERSION_1_3_dup(
    of_oxm_arp_tpa_t *src)
{
    of_oxm_arp_tpa_t *dst;
    uint32_t val32;

    if ((dst = of_oxm_arp_tpa_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_arp_tpa_value_get(src, &val32);
    of_oxm_arp_tpa_value_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_arp_tpa_masked
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_arp_tpa_masked.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_arp_tpa_masked_t *
of_oxm_arp_tpa_masked_OF_VERSION_1_3_dup(
    of_oxm_arp_tpa_masked_t *src)
{
    of_oxm_arp_tpa_masked_t *dst;
    uint32_t val32;

    if ((dst = of_oxm_arp_tpa_masked_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_arp_tpa_masked_value_get(src, &val32);
    of_oxm_arp_tpa_masked_value_set(dst, val32);

    of_oxm_arp_tpa_masked_value_mask_get(src, &val32);
    of_oxm_arp_tpa_masked_value_mask_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_bsn_global_vrf_allowed
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_bsn_global_vrf_allowed.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_bsn_global_vrf_allowed_t *
of_oxm_bsn_global_vrf_allowed_OF_VERSION_1_3_dup(
    of_oxm_bsn_global_vrf_allowed_t *src)
{
    of_oxm_bsn_global_vrf_allowed_t *dst;
    uint8_t val8;

    if ((dst = of_oxm_bsn_global_vrf_allowed_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_bsn_global_vrf_allowed_value_get(src, &val8);
    of_oxm_bsn_global_vrf_allowed_value_set(dst, val8);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_bsn_global_vrf_allowed_masked
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_bsn_global_vrf_allowed_masked.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_bsn_global_vrf_allowed_masked_t *
of_oxm_bsn_global_vrf_allowed_masked_OF_VERSION_1_3_dup(
    of_oxm_bsn_global_vrf_allowed_masked_t *src)
{
    of_oxm_bsn_global_vrf_allowed_masked_t *dst;
    uint8_t val8;

    if ((dst = of_oxm_bsn_global_vrf_allowed_masked_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_bsn_global_vrf_allowed_masked_value_get(src, &val8);
    of_oxm_bsn_global_vrf_allowed_masked_value_set(dst, val8);

    of_oxm_bsn_global_vrf_allowed_masked_value_mask_get(src, &val8);
    of_oxm_bsn_global_vrf_allowed_masked_value_mask_set(dst, val8);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_bsn_in_ports_128
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_bsn_in_ports_128.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_bsn_in_ports_128_t *
of_oxm_bsn_in_ports_128_OF_VERSION_1_3_dup(
    of_oxm_bsn_in_ports_128_t *src)
{
    of_oxm_bsn_in_ports_128_t *dst;
    of_bitmap_128_t bitmap_128;

    if ((dst = of_oxm_bsn_in_ports_128_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_bsn_in_ports_128_value_get(src, &bitmap_128);
    of_oxm_bsn_in_ports_128_value_set(dst, bitmap_128);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_bsn_in_ports_128_masked
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_bsn_in_ports_128_masked.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_bsn_in_ports_128_masked_t *
of_oxm_bsn_in_ports_128_masked_OF_VERSION_1_3_dup(
    of_oxm_bsn_in_ports_128_masked_t *src)
{
    of_oxm_bsn_in_ports_128_masked_t *dst;
    of_bitmap_128_t bitmap_128;

    if ((dst = of_oxm_bsn_in_ports_128_masked_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_bsn_in_ports_128_masked_value_get(src, &bitmap_128);
    of_oxm_bsn_in_ports_128_masked_value_set(dst, bitmap_128);

    of_oxm_bsn_in_ports_128_masked_value_mask_get(src, &bitmap_128);
    of_oxm_bsn_in_ports_128_masked_value_mask_set(dst, bitmap_128);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_bsn_l3_dst_class_id
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_bsn_l3_dst_class_id.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_bsn_l3_dst_class_id_t *
of_oxm_bsn_l3_dst_class_id_OF_VERSION_1_3_dup(
    of_oxm_bsn_l3_dst_class_id_t *src)
{
    of_oxm_bsn_l3_dst_class_id_t *dst;
    uint32_t val32;

    if ((dst = of_oxm_bsn_l3_dst_class_id_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_bsn_l3_dst_class_id_value_get(src, &val32);
    of_oxm_bsn_l3_dst_class_id_value_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_bsn_l3_dst_class_id_masked
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_bsn_l3_dst_class_id_masked.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_bsn_l3_dst_class_id_masked_t *
of_oxm_bsn_l3_dst_class_id_masked_OF_VERSION_1_3_dup(
    of_oxm_bsn_l3_dst_class_id_masked_t *src)
{
    of_oxm_bsn_l3_dst_class_id_masked_t *dst;
    uint32_t val32;

    if ((dst = of_oxm_bsn_l3_dst_class_id_masked_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_bsn_l3_dst_class_id_masked_value_get(src, &val32);
    of_oxm_bsn_l3_dst_class_id_masked_value_set(dst, val32);

    of_oxm_bsn_l3_dst_class_id_masked_value_mask_get(src, &val32);
    of_oxm_bsn_l3_dst_class_id_masked_value_mask_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_bsn_l3_interface_class_id
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_bsn_l3_interface_class_id.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_bsn_l3_interface_class_id_t *
of_oxm_bsn_l3_interface_class_id_OF_VERSION_1_3_dup(
    of_oxm_bsn_l3_interface_class_id_t *src)
{
    of_oxm_bsn_l3_interface_class_id_t *dst;
    uint32_t val32;

    if ((dst = of_oxm_bsn_l3_interface_class_id_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_bsn_l3_interface_class_id_value_get(src, &val32);
    of_oxm_bsn_l3_interface_class_id_value_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_bsn_l3_interface_class_id_masked
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_bsn_l3_interface_class_id_masked.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_bsn_l3_interface_class_id_masked_t *
of_oxm_bsn_l3_interface_class_id_masked_OF_VERSION_1_3_dup(
    of_oxm_bsn_l3_interface_class_id_masked_t *src)
{
    of_oxm_bsn_l3_interface_class_id_masked_t *dst;
    uint32_t val32;

    if ((dst = of_oxm_bsn_l3_interface_class_id_masked_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_bsn_l3_interface_class_id_masked_value_get(src, &val32);
    of_oxm_bsn_l3_interface_class_id_masked_value_set(dst, val32);

    of_oxm_bsn_l3_interface_class_id_masked_value_mask_get(src, &val32);
    of_oxm_bsn_l3_interface_class_id_masked_value_mask_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_bsn_l3_src_class_id
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_bsn_l3_src_class_id.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_bsn_l3_src_class_id_t *
of_oxm_bsn_l3_src_class_id_OF_VERSION_1_3_dup(
    of_oxm_bsn_l3_src_class_id_t *src)
{
    of_oxm_bsn_l3_src_class_id_t *dst;
    uint32_t val32;

    if ((dst = of_oxm_bsn_l3_src_class_id_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_bsn_l3_src_class_id_value_get(src, &val32);
    of_oxm_bsn_l3_src_class_id_value_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_bsn_l3_src_class_id_masked
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_bsn_l3_src_class_id_masked.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_bsn_l3_src_class_id_masked_t *
of_oxm_bsn_l3_src_class_id_masked_OF_VERSION_1_3_dup(
    of_oxm_bsn_l3_src_class_id_masked_t *src)
{
    of_oxm_bsn_l3_src_class_id_masked_t *dst;
    uint32_t val32;

    if ((dst = of_oxm_bsn_l3_src_class_id_masked_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_bsn_l3_src_class_id_masked_value_get(src, &val32);
    of_oxm_bsn_l3_src_class_id_masked_value_set(dst, val32);

    of_oxm_bsn_l3_src_class_id_masked_value_mask_get(src, &val32);
    of_oxm_bsn_l3_src_class_id_masked_value_mask_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_bsn_lag_id
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_bsn_lag_id.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_bsn_lag_id_t *
of_oxm_bsn_lag_id_OF_VERSION_1_3_dup(
    of_oxm_bsn_lag_id_t *src)
{
    of_oxm_bsn_lag_id_t *dst;
    uint32_t val32;

    if ((dst = of_oxm_bsn_lag_id_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_bsn_lag_id_value_get(src, &val32);
    of_oxm_bsn_lag_id_value_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_bsn_lag_id_masked
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_bsn_lag_id_masked.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_bsn_lag_id_masked_t *
of_oxm_bsn_lag_id_masked_OF_VERSION_1_3_dup(
    of_oxm_bsn_lag_id_masked_t *src)
{
    of_oxm_bsn_lag_id_masked_t *dst;
    uint32_t val32;

    if ((dst = of_oxm_bsn_lag_id_masked_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_bsn_lag_id_masked_value_get(src, &val32);
    of_oxm_bsn_lag_id_masked_value_set(dst, val32);

    of_oxm_bsn_lag_id_masked_value_mask_get(src, &val32);
    of_oxm_bsn_lag_id_masked_value_mask_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_bsn_vrf
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_bsn_vrf.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_bsn_vrf_t *
of_oxm_bsn_vrf_OF_VERSION_1_3_dup(
    of_oxm_bsn_vrf_t *src)
{
    of_oxm_bsn_vrf_t *dst;
    uint32_t val32;

    if ((dst = of_oxm_bsn_vrf_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_bsn_vrf_value_get(src, &val32);
    of_oxm_bsn_vrf_value_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_bsn_vrf_masked
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_bsn_vrf_masked.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_bsn_vrf_masked_t *
of_oxm_bsn_vrf_masked_OF_VERSION_1_3_dup(
    of_oxm_bsn_vrf_masked_t *src)
{
    of_oxm_bsn_vrf_masked_t *dst;
    uint32_t val32;

    if ((dst = of_oxm_bsn_vrf_masked_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_bsn_vrf_masked_value_get(src, &val32);
    of_oxm_bsn_vrf_masked_value_set(dst, val32);

    of_oxm_bsn_vrf_masked_value_mask_get(src, &val32);
    of_oxm_bsn_vrf_masked_value_mask_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_eth_dst
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_eth_dst.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_eth_dst_t *
of_oxm_eth_dst_OF_VERSION_1_3_dup(
    of_oxm_eth_dst_t *src)
{
    of_oxm_eth_dst_t *dst;
    of_mac_addr_t mac_addr;

    if ((dst = of_oxm_eth_dst_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_eth_dst_value_get(src, &mac_addr);
    of_oxm_eth_dst_value_set(dst, mac_addr);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_eth_dst_masked
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_eth_dst_masked.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_eth_dst_masked_t *
of_oxm_eth_dst_masked_OF_VERSION_1_3_dup(
    of_oxm_eth_dst_masked_t *src)
{
    of_oxm_eth_dst_masked_t *dst;
    of_mac_addr_t mac_addr;

    if ((dst = of_oxm_eth_dst_masked_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_eth_dst_masked_value_get(src, &mac_addr);
    of_oxm_eth_dst_masked_value_set(dst, mac_addr);

    of_oxm_eth_dst_masked_value_mask_get(src, &mac_addr);
    of_oxm_eth_dst_masked_value_mask_set(dst, mac_addr);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_eth_src
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_eth_src.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_eth_src_t *
of_oxm_eth_src_OF_VERSION_1_3_dup(
    of_oxm_eth_src_t *src)
{
    of_oxm_eth_src_t *dst;
    of_mac_addr_t mac_addr;

    if ((dst = of_oxm_eth_src_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_eth_src_value_get(src, &mac_addr);
    of_oxm_eth_src_value_set(dst, mac_addr);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_eth_src_masked
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_eth_src_masked.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_eth_src_masked_t *
of_oxm_eth_src_masked_OF_VERSION_1_3_dup(
    of_oxm_eth_src_masked_t *src)
{
    of_oxm_eth_src_masked_t *dst;
    of_mac_addr_t mac_addr;

    if ((dst = of_oxm_eth_src_masked_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_eth_src_masked_value_get(src, &mac_addr);
    of_oxm_eth_src_masked_value_set(dst, mac_addr);

    of_oxm_eth_src_masked_value_mask_get(src, &mac_addr);
    of_oxm_eth_src_masked_value_mask_set(dst, mac_addr);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_eth_type
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_eth_type.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_eth_type_t *
of_oxm_eth_type_OF_VERSION_1_3_dup(
    of_oxm_eth_type_t *src)
{
    of_oxm_eth_type_t *dst;
    uint16_t val16;

    if ((dst = of_oxm_eth_type_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_eth_type_value_get(src, &val16);
    of_oxm_eth_type_value_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_eth_type_masked
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_eth_type_masked.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_eth_type_masked_t *
of_oxm_eth_type_masked_OF_VERSION_1_3_dup(
    of_oxm_eth_type_masked_t *src)
{
    of_oxm_eth_type_masked_t *dst;
    uint16_t val16;

    if ((dst = of_oxm_eth_type_masked_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_eth_type_masked_value_get(src, &val16);
    of_oxm_eth_type_masked_value_set(dst, val16);

    of_oxm_eth_type_masked_value_mask_get(src, &val16);
    of_oxm_eth_type_masked_value_mask_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_header
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_header.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_header_t *
of_oxm_header_OF_VERSION_1_3_dup(
    of_oxm_header_t *src)
{
    of_oxm_header_t *dst;

    if ((dst = of_oxm_header_new(src->version)) == NULL) {
        return NULL;
    }

    return dst;
}

/**
 * Duplicate an object of type of_oxm_icmpv4_code
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_icmpv4_code.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_icmpv4_code_t *
of_oxm_icmpv4_code_OF_VERSION_1_3_dup(
    of_oxm_icmpv4_code_t *src)
{
    of_oxm_icmpv4_code_t *dst;
    uint8_t val8;

    if ((dst = of_oxm_icmpv4_code_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_icmpv4_code_value_get(src, &val8);
    of_oxm_icmpv4_code_value_set(dst, val8);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_icmpv4_code_masked
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_icmpv4_code_masked.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_icmpv4_code_masked_t *
of_oxm_icmpv4_code_masked_OF_VERSION_1_3_dup(
    of_oxm_icmpv4_code_masked_t *src)
{
    of_oxm_icmpv4_code_masked_t *dst;
    uint8_t val8;

    if ((dst = of_oxm_icmpv4_code_masked_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_icmpv4_code_masked_value_get(src, &val8);
    of_oxm_icmpv4_code_masked_value_set(dst, val8);

    of_oxm_icmpv4_code_masked_value_mask_get(src, &val8);
    of_oxm_icmpv4_code_masked_value_mask_set(dst, val8);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_icmpv4_type
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_icmpv4_type.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_icmpv4_type_t *
of_oxm_icmpv4_type_OF_VERSION_1_3_dup(
    of_oxm_icmpv4_type_t *src)
{
    of_oxm_icmpv4_type_t *dst;
    uint8_t val8;

    if ((dst = of_oxm_icmpv4_type_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_icmpv4_type_value_get(src, &val8);
    of_oxm_icmpv4_type_value_set(dst, val8);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_icmpv4_type_masked
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_icmpv4_type_masked.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_icmpv4_type_masked_t *
of_oxm_icmpv4_type_masked_OF_VERSION_1_3_dup(
    of_oxm_icmpv4_type_masked_t *src)
{
    of_oxm_icmpv4_type_masked_t *dst;
    uint8_t val8;

    if ((dst = of_oxm_icmpv4_type_masked_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_icmpv4_type_masked_value_get(src, &val8);
    of_oxm_icmpv4_type_masked_value_set(dst, val8);

    of_oxm_icmpv4_type_masked_value_mask_get(src, &val8);
    of_oxm_icmpv4_type_masked_value_mask_set(dst, val8);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_icmpv6_code
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_icmpv6_code.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_icmpv6_code_t *
of_oxm_icmpv6_code_OF_VERSION_1_3_dup(
    of_oxm_icmpv6_code_t *src)
{
    of_oxm_icmpv6_code_t *dst;
    uint8_t val8;

    if ((dst = of_oxm_icmpv6_code_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_icmpv6_code_value_get(src, &val8);
    of_oxm_icmpv6_code_value_set(dst, val8);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_icmpv6_code_masked
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_icmpv6_code_masked.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_icmpv6_code_masked_t *
of_oxm_icmpv6_code_masked_OF_VERSION_1_3_dup(
    of_oxm_icmpv6_code_masked_t *src)
{
    of_oxm_icmpv6_code_masked_t *dst;
    uint8_t val8;

    if ((dst = of_oxm_icmpv6_code_masked_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_icmpv6_code_masked_value_get(src, &val8);
    of_oxm_icmpv6_code_masked_value_set(dst, val8);

    of_oxm_icmpv6_code_masked_value_mask_get(src, &val8);
    of_oxm_icmpv6_code_masked_value_mask_set(dst, val8);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_icmpv6_type
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_icmpv6_type.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_icmpv6_type_t *
of_oxm_icmpv6_type_OF_VERSION_1_3_dup(
    of_oxm_icmpv6_type_t *src)
{
    of_oxm_icmpv6_type_t *dst;
    uint8_t val8;

    if ((dst = of_oxm_icmpv6_type_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_icmpv6_type_value_get(src, &val8);
    of_oxm_icmpv6_type_value_set(dst, val8);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_icmpv6_type_masked
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_icmpv6_type_masked.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_icmpv6_type_masked_t *
of_oxm_icmpv6_type_masked_OF_VERSION_1_3_dup(
    of_oxm_icmpv6_type_masked_t *src)
{
    of_oxm_icmpv6_type_masked_t *dst;
    uint8_t val8;

    if ((dst = of_oxm_icmpv6_type_masked_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_icmpv6_type_masked_value_get(src, &val8);
    of_oxm_icmpv6_type_masked_value_set(dst, val8);

    of_oxm_icmpv6_type_masked_value_mask_get(src, &val8);
    of_oxm_icmpv6_type_masked_value_mask_set(dst, val8);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_in_phy_port
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_in_phy_port.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_in_phy_port_t *
of_oxm_in_phy_port_OF_VERSION_1_3_dup(
    of_oxm_in_phy_port_t *src)
{
    of_oxm_in_phy_port_t *dst;
    of_port_no_t port_no;

    if ((dst = of_oxm_in_phy_port_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_in_phy_port_value_get(src, &port_no);
    of_oxm_in_phy_port_value_set(dst, port_no);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_in_phy_port_masked
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_in_phy_port_masked.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_in_phy_port_masked_t *
of_oxm_in_phy_port_masked_OF_VERSION_1_3_dup(
    of_oxm_in_phy_port_masked_t *src)
{
    of_oxm_in_phy_port_masked_t *dst;
    of_port_no_t port_no;

    if ((dst = of_oxm_in_phy_port_masked_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_in_phy_port_masked_value_get(src, &port_no);
    of_oxm_in_phy_port_masked_value_set(dst, port_no);

    of_oxm_in_phy_port_masked_value_mask_get(src, &port_no);
    of_oxm_in_phy_port_masked_value_mask_set(dst, port_no);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_in_port
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_in_port.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_in_port_t *
of_oxm_in_port_OF_VERSION_1_3_dup(
    of_oxm_in_port_t *src)
{
    of_oxm_in_port_t *dst;
    of_port_no_t port_no;

    if ((dst = of_oxm_in_port_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_in_port_value_get(src, &port_no);
    of_oxm_in_port_value_set(dst, port_no);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_in_port_masked
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_in_port_masked.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_in_port_masked_t *
of_oxm_in_port_masked_OF_VERSION_1_3_dup(
    of_oxm_in_port_masked_t *src)
{
    of_oxm_in_port_masked_t *dst;
    of_port_no_t port_no;

    if ((dst = of_oxm_in_port_masked_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_in_port_masked_value_get(src, &port_no);
    of_oxm_in_port_masked_value_set(dst, port_no);

    of_oxm_in_port_masked_value_mask_get(src, &port_no);
    of_oxm_in_port_masked_value_mask_set(dst, port_no);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_ip_dscp
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_ip_dscp.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_ip_dscp_t *
of_oxm_ip_dscp_OF_VERSION_1_3_dup(
    of_oxm_ip_dscp_t *src)
{
    of_oxm_ip_dscp_t *dst;
    uint8_t val8;

    if ((dst = of_oxm_ip_dscp_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_ip_dscp_value_get(src, &val8);
    of_oxm_ip_dscp_value_set(dst, val8);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_ip_dscp_masked
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_ip_dscp_masked.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_ip_dscp_masked_t *
of_oxm_ip_dscp_masked_OF_VERSION_1_3_dup(
    of_oxm_ip_dscp_masked_t *src)
{
    of_oxm_ip_dscp_masked_t *dst;
    uint8_t val8;

    if ((dst = of_oxm_ip_dscp_masked_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_ip_dscp_masked_value_get(src, &val8);
    of_oxm_ip_dscp_masked_value_set(dst, val8);

    of_oxm_ip_dscp_masked_value_mask_get(src, &val8);
    of_oxm_ip_dscp_masked_value_mask_set(dst, val8);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_ip_ecn
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_ip_ecn.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_ip_ecn_t *
of_oxm_ip_ecn_OF_VERSION_1_3_dup(
    of_oxm_ip_ecn_t *src)
{
    of_oxm_ip_ecn_t *dst;
    uint8_t val8;

    if ((dst = of_oxm_ip_ecn_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_ip_ecn_value_get(src, &val8);
    of_oxm_ip_ecn_value_set(dst, val8);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_ip_ecn_masked
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_ip_ecn_masked.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_ip_ecn_masked_t *
of_oxm_ip_ecn_masked_OF_VERSION_1_3_dup(
    of_oxm_ip_ecn_masked_t *src)
{
    of_oxm_ip_ecn_masked_t *dst;
    uint8_t val8;

    if ((dst = of_oxm_ip_ecn_masked_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_ip_ecn_masked_value_get(src, &val8);
    of_oxm_ip_ecn_masked_value_set(dst, val8);

    of_oxm_ip_ecn_masked_value_mask_get(src, &val8);
    of_oxm_ip_ecn_masked_value_mask_set(dst, val8);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_ip_proto
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_ip_proto.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_ip_proto_t *
of_oxm_ip_proto_OF_VERSION_1_3_dup(
    of_oxm_ip_proto_t *src)
{
    of_oxm_ip_proto_t *dst;
    uint8_t val8;

    if ((dst = of_oxm_ip_proto_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_ip_proto_value_get(src, &val8);
    of_oxm_ip_proto_value_set(dst, val8);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_ip_proto_masked
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_ip_proto_masked.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_ip_proto_masked_t *
of_oxm_ip_proto_masked_OF_VERSION_1_3_dup(
    of_oxm_ip_proto_masked_t *src)
{
    of_oxm_ip_proto_masked_t *dst;
    uint8_t val8;

    if ((dst = of_oxm_ip_proto_masked_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_ip_proto_masked_value_get(src, &val8);
    of_oxm_ip_proto_masked_value_set(dst, val8);

    of_oxm_ip_proto_masked_value_mask_get(src, &val8);
    of_oxm_ip_proto_masked_value_mask_set(dst, val8);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_ipv4_dst
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_ipv4_dst.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_ipv4_dst_t *
of_oxm_ipv4_dst_OF_VERSION_1_3_dup(
    of_oxm_ipv4_dst_t *src)
{
    of_oxm_ipv4_dst_t *dst;
    of_ipv4_t ipv4;

    if ((dst = of_oxm_ipv4_dst_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_ipv4_dst_value_get(src, &ipv4);
    of_oxm_ipv4_dst_value_set(dst, ipv4);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_ipv4_dst_masked
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_ipv4_dst_masked.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_ipv4_dst_masked_t *
of_oxm_ipv4_dst_masked_OF_VERSION_1_3_dup(
    of_oxm_ipv4_dst_masked_t *src)
{
    of_oxm_ipv4_dst_masked_t *dst;
    of_ipv4_t ipv4;

    if ((dst = of_oxm_ipv4_dst_masked_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_ipv4_dst_masked_value_get(src, &ipv4);
    of_oxm_ipv4_dst_masked_value_set(dst, ipv4);

    of_oxm_ipv4_dst_masked_value_mask_get(src, &ipv4);
    of_oxm_ipv4_dst_masked_value_mask_set(dst, ipv4);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_ipv4_src
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_ipv4_src.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_ipv4_src_t *
of_oxm_ipv4_src_OF_VERSION_1_3_dup(
    of_oxm_ipv4_src_t *src)
{
    of_oxm_ipv4_src_t *dst;
    of_ipv4_t ipv4;

    if ((dst = of_oxm_ipv4_src_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_ipv4_src_value_get(src, &ipv4);
    of_oxm_ipv4_src_value_set(dst, ipv4);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_ipv4_src_masked
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_ipv4_src_masked.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_ipv4_src_masked_t *
of_oxm_ipv4_src_masked_OF_VERSION_1_3_dup(
    of_oxm_ipv4_src_masked_t *src)
{
    of_oxm_ipv4_src_masked_t *dst;
    of_ipv4_t ipv4;

    if ((dst = of_oxm_ipv4_src_masked_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_ipv4_src_masked_value_get(src, &ipv4);
    of_oxm_ipv4_src_masked_value_set(dst, ipv4);

    of_oxm_ipv4_src_masked_value_mask_get(src, &ipv4);
    of_oxm_ipv4_src_masked_value_mask_set(dst, ipv4);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_ipv6_dst
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_ipv6_dst.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_ipv6_dst_t *
of_oxm_ipv6_dst_OF_VERSION_1_3_dup(
    of_oxm_ipv6_dst_t *src)
{
    of_oxm_ipv6_dst_t *dst;
    of_ipv6_t ipv6;

    if ((dst = of_oxm_ipv6_dst_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_ipv6_dst_value_get(src, &ipv6);
    of_oxm_ipv6_dst_value_set(dst, ipv6);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_ipv6_dst_masked
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_ipv6_dst_masked.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_ipv6_dst_masked_t *
of_oxm_ipv6_dst_masked_OF_VERSION_1_3_dup(
    of_oxm_ipv6_dst_masked_t *src)
{
    of_oxm_ipv6_dst_masked_t *dst;
    of_ipv6_t ipv6;

    if ((dst = of_oxm_ipv6_dst_masked_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_ipv6_dst_masked_value_get(src, &ipv6);
    of_oxm_ipv6_dst_masked_value_set(dst, ipv6);

    of_oxm_ipv6_dst_masked_value_mask_get(src, &ipv6);
    of_oxm_ipv6_dst_masked_value_mask_set(dst, ipv6);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_ipv6_flabel
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_ipv6_flabel.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_ipv6_flabel_t *
of_oxm_ipv6_flabel_OF_VERSION_1_3_dup(
    of_oxm_ipv6_flabel_t *src)
{
    of_oxm_ipv6_flabel_t *dst;
    uint32_t val32;

    if ((dst = of_oxm_ipv6_flabel_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_ipv6_flabel_value_get(src, &val32);
    of_oxm_ipv6_flabel_value_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_ipv6_flabel_masked
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_ipv6_flabel_masked.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_ipv6_flabel_masked_t *
of_oxm_ipv6_flabel_masked_OF_VERSION_1_3_dup(
    of_oxm_ipv6_flabel_masked_t *src)
{
    of_oxm_ipv6_flabel_masked_t *dst;
    uint32_t val32;

    if ((dst = of_oxm_ipv6_flabel_masked_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_ipv6_flabel_masked_value_get(src, &val32);
    of_oxm_ipv6_flabel_masked_value_set(dst, val32);

    of_oxm_ipv6_flabel_masked_value_mask_get(src, &val32);
    of_oxm_ipv6_flabel_masked_value_mask_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_ipv6_nd_sll
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_ipv6_nd_sll.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_ipv6_nd_sll_t *
of_oxm_ipv6_nd_sll_OF_VERSION_1_3_dup(
    of_oxm_ipv6_nd_sll_t *src)
{
    of_oxm_ipv6_nd_sll_t *dst;
    of_mac_addr_t mac_addr;

    if ((dst = of_oxm_ipv6_nd_sll_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_ipv6_nd_sll_value_get(src, &mac_addr);
    of_oxm_ipv6_nd_sll_value_set(dst, mac_addr);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_ipv6_nd_sll_masked
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_ipv6_nd_sll_masked.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_ipv6_nd_sll_masked_t *
of_oxm_ipv6_nd_sll_masked_OF_VERSION_1_3_dup(
    of_oxm_ipv6_nd_sll_masked_t *src)
{
    of_oxm_ipv6_nd_sll_masked_t *dst;
    of_mac_addr_t mac_addr;

    if ((dst = of_oxm_ipv6_nd_sll_masked_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_ipv6_nd_sll_masked_value_get(src, &mac_addr);
    of_oxm_ipv6_nd_sll_masked_value_set(dst, mac_addr);

    of_oxm_ipv6_nd_sll_masked_value_mask_get(src, &mac_addr);
    of_oxm_ipv6_nd_sll_masked_value_mask_set(dst, mac_addr);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_ipv6_nd_target
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_ipv6_nd_target.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_ipv6_nd_target_t *
of_oxm_ipv6_nd_target_OF_VERSION_1_3_dup(
    of_oxm_ipv6_nd_target_t *src)
{
    of_oxm_ipv6_nd_target_t *dst;
    of_ipv6_t ipv6;

    if ((dst = of_oxm_ipv6_nd_target_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_ipv6_nd_target_value_get(src, &ipv6);
    of_oxm_ipv6_nd_target_value_set(dst, ipv6);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_ipv6_nd_target_masked
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_ipv6_nd_target_masked.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_ipv6_nd_target_masked_t *
of_oxm_ipv6_nd_target_masked_OF_VERSION_1_3_dup(
    of_oxm_ipv6_nd_target_masked_t *src)
{
    of_oxm_ipv6_nd_target_masked_t *dst;
    of_ipv6_t ipv6;

    if ((dst = of_oxm_ipv6_nd_target_masked_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_ipv6_nd_target_masked_value_get(src, &ipv6);
    of_oxm_ipv6_nd_target_masked_value_set(dst, ipv6);

    of_oxm_ipv6_nd_target_masked_value_mask_get(src, &ipv6);
    of_oxm_ipv6_nd_target_masked_value_mask_set(dst, ipv6);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_ipv6_nd_tll
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_ipv6_nd_tll.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_ipv6_nd_tll_t *
of_oxm_ipv6_nd_tll_OF_VERSION_1_3_dup(
    of_oxm_ipv6_nd_tll_t *src)
{
    of_oxm_ipv6_nd_tll_t *dst;
    of_mac_addr_t mac_addr;

    if ((dst = of_oxm_ipv6_nd_tll_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_ipv6_nd_tll_value_get(src, &mac_addr);
    of_oxm_ipv6_nd_tll_value_set(dst, mac_addr);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_ipv6_nd_tll_masked
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_ipv6_nd_tll_masked.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_ipv6_nd_tll_masked_t *
of_oxm_ipv6_nd_tll_masked_OF_VERSION_1_3_dup(
    of_oxm_ipv6_nd_tll_masked_t *src)
{
    of_oxm_ipv6_nd_tll_masked_t *dst;
    of_mac_addr_t mac_addr;

    if ((dst = of_oxm_ipv6_nd_tll_masked_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_ipv6_nd_tll_masked_value_get(src, &mac_addr);
    of_oxm_ipv6_nd_tll_masked_value_set(dst, mac_addr);

    of_oxm_ipv6_nd_tll_masked_value_mask_get(src, &mac_addr);
    of_oxm_ipv6_nd_tll_masked_value_mask_set(dst, mac_addr);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_ipv6_src
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_ipv6_src.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_ipv6_src_t *
of_oxm_ipv6_src_OF_VERSION_1_3_dup(
    of_oxm_ipv6_src_t *src)
{
    of_oxm_ipv6_src_t *dst;
    of_ipv6_t ipv6;

    if ((dst = of_oxm_ipv6_src_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_ipv6_src_value_get(src, &ipv6);
    of_oxm_ipv6_src_value_set(dst, ipv6);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_ipv6_src_masked
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_ipv6_src_masked.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_ipv6_src_masked_t *
of_oxm_ipv6_src_masked_OF_VERSION_1_3_dup(
    of_oxm_ipv6_src_masked_t *src)
{
    of_oxm_ipv6_src_masked_t *dst;
    of_ipv6_t ipv6;

    if ((dst = of_oxm_ipv6_src_masked_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_ipv6_src_masked_value_get(src, &ipv6);
    of_oxm_ipv6_src_masked_value_set(dst, ipv6);

    of_oxm_ipv6_src_masked_value_mask_get(src, &ipv6);
    of_oxm_ipv6_src_masked_value_mask_set(dst, ipv6);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_metadata
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_metadata.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_metadata_t *
of_oxm_metadata_OF_VERSION_1_3_dup(
    of_oxm_metadata_t *src)
{
    of_oxm_metadata_t *dst;
    uint64_t val64;

    if ((dst = of_oxm_metadata_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_metadata_value_get(src, &val64);
    of_oxm_metadata_value_set(dst, val64);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_metadata_masked
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_metadata_masked.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_metadata_masked_t *
of_oxm_metadata_masked_OF_VERSION_1_3_dup(
    of_oxm_metadata_masked_t *src)
{
    of_oxm_metadata_masked_t *dst;
    uint64_t val64;

    if ((dst = of_oxm_metadata_masked_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_metadata_masked_value_get(src, &val64);
    of_oxm_metadata_masked_value_set(dst, val64);

    of_oxm_metadata_masked_value_mask_get(src, &val64);
    of_oxm_metadata_masked_value_mask_set(dst, val64);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_mpls_label
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_mpls_label.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_mpls_label_t *
of_oxm_mpls_label_OF_VERSION_1_3_dup(
    of_oxm_mpls_label_t *src)
{
    of_oxm_mpls_label_t *dst;
    uint32_t val32;

    if ((dst = of_oxm_mpls_label_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_mpls_label_value_get(src, &val32);
    of_oxm_mpls_label_value_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_mpls_label_masked
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_mpls_label_masked.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_mpls_label_masked_t *
of_oxm_mpls_label_masked_OF_VERSION_1_3_dup(
    of_oxm_mpls_label_masked_t *src)
{
    of_oxm_mpls_label_masked_t *dst;
    uint32_t val32;

    if ((dst = of_oxm_mpls_label_masked_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_mpls_label_masked_value_get(src, &val32);
    of_oxm_mpls_label_masked_value_set(dst, val32);

    of_oxm_mpls_label_masked_value_mask_get(src, &val32);
    of_oxm_mpls_label_masked_value_mask_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_mpls_tc
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_mpls_tc.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_mpls_tc_t *
of_oxm_mpls_tc_OF_VERSION_1_3_dup(
    of_oxm_mpls_tc_t *src)
{
    of_oxm_mpls_tc_t *dst;
    uint8_t val8;

    if ((dst = of_oxm_mpls_tc_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_mpls_tc_value_get(src, &val8);
    of_oxm_mpls_tc_value_set(dst, val8);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_mpls_tc_masked
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_mpls_tc_masked.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_mpls_tc_masked_t *
of_oxm_mpls_tc_masked_OF_VERSION_1_3_dup(
    of_oxm_mpls_tc_masked_t *src)
{
    of_oxm_mpls_tc_masked_t *dst;
    uint8_t val8;

    if ((dst = of_oxm_mpls_tc_masked_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_mpls_tc_masked_value_get(src, &val8);
    of_oxm_mpls_tc_masked_value_set(dst, val8);

    of_oxm_mpls_tc_masked_value_mask_get(src, &val8);
    of_oxm_mpls_tc_masked_value_mask_set(dst, val8);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_sctp_dst
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_sctp_dst.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_sctp_dst_t *
of_oxm_sctp_dst_OF_VERSION_1_3_dup(
    of_oxm_sctp_dst_t *src)
{
    of_oxm_sctp_dst_t *dst;
    uint16_t val16;

    if ((dst = of_oxm_sctp_dst_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_sctp_dst_value_get(src, &val16);
    of_oxm_sctp_dst_value_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_sctp_dst_masked
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_sctp_dst_masked.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_sctp_dst_masked_t *
of_oxm_sctp_dst_masked_OF_VERSION_1_3_dup(
    of_oxm_sctp_dst_masked_t *src)
{
    of_oxm_sctp_dst_masked_t *dst;
    uint16_t val16;

    if ((dst = of_oxm_sctp_dst_masked_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_sctp_dst_masked_value_get(src, &val16);
    of_oxm_sctp_dst_masked_value_set(dst, val16);

    of_oxm_sctp_dst_masked_value_mask_get(src, &val16);
    of_oxm_sctp_dst_masked_value_mask_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_sctp_src
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_sctp_src.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_sctp_src_t *
of_oxm_sctp_src_OF_VERSION_1_3_dup(
    of_oxm_sctp_src_t *src)
{
    of_oxm_sctp_src_t *dst;
    uint16_t val16;

    if ((dst = of_oxm_sctp_src_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_sctp_src_value_get(src, &val16);
    of_oxm_sctp_src_value_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_sctp_src_masked
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_sctp_src_masked.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_sctp_src_masked_t *
of_oxm_sctp_src_masked_OF_VERSION_1_3_dup(
    of_oxm_sctp_src_masked_t *src)
{
    of_oxm_sctp_src_masked_t *dst;
    uint16_t val16;

    if ((dst = of_oxm_sctp_src_masked_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_sctp_src_masked_value_get(src, &val16);
    of_oxm_sctp_src_masked_value_set(dst, val16);

    of_oxm_sctp_src_masked_value_mask_get(src, &val16);
    of_oxm_sctp_src_masked_value_mask_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_tcp_dst
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_tcp_dst.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_tcp_dst_t *
of_oxm_tcp_dst_OF_VERSION_1_3_dup(
    of_oxm_tcp_dst_t *src)
{
    of_oxm_tcp_dst_t *dst;
    uint16_t val16;

    if ((dst = of_oxm_tcp_dst_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_tcp_dst_value_get(src, &val16);
    of_oxm_tcp_dst_value_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_tcp_dst_masked
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_tcp_dst_masked.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_tcp_dst_masked_t *
of_oxm_tcp_dst_masked_OF_VERSION_1_3_dup(
    of_oxm_tcp_dst_masked_t *src)
{
    of_oxm_tcp_dst_masked_t *dst;
    uint16_t val16;

    if ((dst = of_oxm_tcp_dst_masked_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_tcp_dst_masked_value_get(src, &val16);
    of_oxm_tcp_dst_masked_value_set(dst, val16);

    of_oxm_tcp_dst_masked_value_mask_get(src, &val16);
    of_oxm_tcp_dst_masked_value_mask_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_tcp_src
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_tcp_src.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_tcp_src_t *
of_oxm_tcp_src_OF_VERSION_1_3_dup(
    of_oxm_tcp_src_t *src)
{
    of_oxm_tcp_src_t *dst;
    uint16_t val16;

    if ((dst = of_oxm_tcp_src_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_tcp_src_value_get(src, &val16);
    of_oxm_tcp_src_value_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_tcp_src_masked
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_tcp_src_masked.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_tcp_src_masked_t *
of_oxm_tcp_src_masked_OF_VERSION_1_3_dup(
    of_oxm_tcp_src_masked_t *src)
{
    of_oxm_tcp_src_masked_t *dst;
    uint16_t val16;

    if ((dst = of_oxm_tcp_src_masked_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_tcp_src_masked_value_get(src, &val16);
    of_oxm_tcp_src_masked_value_set(dst, val16);

    of_oxm_tcp_src_masked_value_mask_get(src, &val16);
    of_oxm_tcp_src_masked_value_mask_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_udp_dst
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_udp_dst.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_udp_dst_t *
of_oxm_udp_dst_OF_VERSION_1_3_dup(
    of_oxm_udp_dst_t *src)
{
    of_oxm_udp_dst_t *dst;
    uint16_t val16;

    if ((dst = of_oxm_udp_dst_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_udp_dst_value_get(src, &val16);
    of_oxm_udp_dst_value_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_udp_dst_masked
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_udp_dst_masked.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_udp_dst_masked_t *
of_oxm_udp_dst_masked_OF_VERSION_1_3_dup(
    of_oxm_udp_dst_masked_t *src)
{
    of_oxm_udp_dst_masked_t *dst;
    uint16_t val16;

    if ((dst = of_oxm_udp_dst_masked_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_udp_dst_masked_value_get(src, &val16);
    of_oxm_udp_dst_masked_value_set(dst, val16);

    of_oxm_udp_dst_masked_value_mask_get(src, &val16);
    of_oxm_udp_dst_masked_value_mask_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_udp_src
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_udp_src.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_udp_src_t *
of_oxm_udp_src_OF_VERSION_1_3_dup(
    of_oxm_udp_src_t *src)
{
    of_oxm_udp_src_t *dst;
    uint16_t val16;

    if ((dst = of_oxm_udp_src_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_udp_src_value_get(src, &val16);
    of_oxm_udp_src_value_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_udp_src_masked
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_udp_src_masked.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_udp_src_masked_t *
of_oxm_udp_src_masked_OF_VERSION_1_3_dup(
    of_oxm_udp_src_masked_t *src)
{
    of_oxm_udp_src_masked_t *dst;
    uint16_t val16;

    if ((dst = of_oxm_udp_src_masked_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_udp_src_masked_value_get(src, &val16);
    of_oxm_udp_src_masked_value_set(dst, val16);

    of_oxm_udp_src_masked_value_mask_get(src, &val16);
    of_oxm_udp_src_masked_value_mask_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_vlan_pcp
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_vlan_pcp.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_vlan_pcp_t *
of_oxm_vlan_pcp_OF_VERSION_1_3_dup(
    of_oxm_vlan_pcp_t *src)
{
    of_oxm_vlan_pcp_t *dst;
    uint8_t val8;

    if ((dst = of_oxm_vlan_pcp_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_vlan_pcp_value_get(src, &val8);
    of_oxm_vlan_pcp_value_set(dst, val8);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_vlan_pcp_masked
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_vlan_pcp_masked.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_vlan_pcp_masked_t *
of_oxm_vlan_pcp_masked_OF_VERSION_1_3_dup(
    of_oxm_vlan_pcp_masked_t *src)
{
    of_oxm_vlan_pcp_masked_t *dst;
    uint8_t val8;

    if ((dst = of_oxm_vlan_pcp_masked_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_vlan_pcp_masked_value_get(src, &val8);
    of_oxm_vlan_pcp_masked_value_set(dst, val8);

    of_oxm_vlan_pcp_masked_value_mask_get(src, &val8);
    of_oxm_vlan_pcp_masked_value_mask_set(dst, val8);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_vlan_vid
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_vlan_vid.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_vlan_vid_t *
of_oxm_vlan_vid_OF_VERSION_1_3_dup(
    of_oxm_vlan_vid_t *src)
{
    of_oxm_vlan_vid_t *dst;
    uint16_t val16;

    if ((dst = of_oxm_vlan_vid_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_vlan_vid_value_get(src, &val16);
    of_oxm_vlan_vid_value_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_oxm_vlan_vid_masked
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_oxm_vlan_vid_masked.
 *
 * The caller is responsible for deleting the returned value
 */
of_oxm_vlan_vid_masked_t *
of_oxm_vlan_vid_masked_OF_VERSION_1_3_dup(
    of_oxm_vlan_vid_masked_t *src)
{
    of_oxm_vlan_vid_masked_t *dst;
    uint16_t val16;

    if ((dst = of_oxm_vlan_vid_masked_new(src->version)) == NULL) {
        return NULL;
    }

    of_oxm_vlan_vid_masked_value_get(src, &val16);
    of_oxm_vlan_vid_masked_value_set(dst, val16);

    of_oxm_vlan_vid_masked_value_mask_get(src, &val16);
    of_oxm_vlan_vid_masked_value_mask_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_packet_queue
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_packet_queue.
 *
 * The caller is responsible for deleting the returned value
 */
of_packet_queue_t *
of_packet_queue_OF_VERSION_1_3_dup(
    of_packet_queue_t *src)
{
    of_packet_queue_t *dst;
    uint32_t val32;
    of_port_no_t port_no;

    of_list_queue_prop_t src_list;
    of_list_queue_prop_t *dst_list;

    if ((dst = of_packet_queue_new(src->version)) == NULL) {
        return NULL;
    }

    of_packet_queue_queue_id_get(src, &val32);
    of_packet_queue_queue_id_set(dst, val32);

    of_packet_queue_port_get(src, &port_no);
    of_packet_queue_port_set(dst, port_no);

    of_packet_queue_properties_bind(
        src, &src_list);
    dst_list = of_list_queue_prop_OF_VERSION_1_3_dup(&src_list);
    if (dst_list == NULL) {
        of_packet_queue_delete(dst);
        return NULL;
    }
    of_packet_queue_properties_set(dst, dst_list);
    of_list_queue_prop_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_port_desc
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_port_desc.
 *
 * The caller is responsible for deleting the returned value
 */
of_port_desc_t *
of_port_desc_OF_VERSION_1_3_dup(
    of_port_desc_t *src)
{
    of_port_desc_t *dst;
    of_port_no_t port_no;
    of_mac_addr_t mac_addr;
    of_port_name_t port_name;
    uint32_t val32;

    if ((dst = of_port_desc_new(src->version)) == NULL) {
        return NULL;
    }

    of_port_desc_port_no_get(src, &port_no);
    of_port_desc_port_no_set(dst, port_no);

    of_port_desc_hw_addr_get(src, &mac_addr);
    of_port_desc_hw_addr_set(dst, mac_addr);

    of_port_desc_name_get(src, &port_name);
    of_port_desc_name_set(dst, port_name);

    of_port_desc_config_get(src, &val32);
    of_port_desc_config_set(dst, val32);

    of_port_desc_state_get(src, &val32);
    of_port_desc_state_set(dst, val32);

    of_port_desc_curr_get(src, &val32);
    of_port_desc_curr_set(dst, val32);

    of_port_desc_advertised_get(src, &val32);
    of_port_desc_advertised_set(dst, val32);

    of_port_desc_supported_get(src, &val32);
    of_port_desc_supported_set(dst, val32);

    of_port_desc_peer_get(src, &val32);
    of_port_desc_peer_set(dst, val32);

    of_port_desc_curr_speed_get(src, &val32);
    of_port_desc_curr_speed_set(dst, val32);

    of_port_desc_max_speed_get(src, &val32);
    of_port_desc_max_speed_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_port_stats_entry
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_port_stats_entry.
 *
 * The caller is responsible for deleting the returned value
 */
of_port_stats_entry_t *
of_port_stats_entry_OF_VERSION_1_3_dup(
    of_port_stats_entry_t *src)
{
    of_port_stats_entry_t *dst;
    of_port_no_t port_no;
    uint64_t val64;
    uint32_t val32;

    if ((dst = of_port_stats_entry_new(src->version)) == NULL) {
        return NULL;
    }

    of_port_stats_entry_port_no_get(src, &port_no);
    of_port_stats_entry_port_no_set(dst, port_no);

    of_port_stats_entry_rx_packets_get(src, &val64);
    of_port_stats_entry_rx_packets_set(dst, val64);

    of_port_stats_entry_tx_packets_get(src, &val64);
    of_port_stats_entry_tx_packets_set(dst, val64);

    of_port_stats_entry_rx_bytes_get(src, &val64);
    of_port_stats_entry_rx_bytes_set(dst, val64);

    of_port_stats_entry_tx_bytes_get(src, &val64);
    of_port_stats_entry_tx_bytes_set(dst, val64);

    of_port_stats_entry_rx_dropped_get(src, &val64);
    of_port_stats_entry_rx_dropped_set(dst, val64);

    of_port_stats_entry_tx_dropped_get(src, &val64);
    of_port_stats_entry_tx_dropped_set(dst, val64);

    of_port_stats_entry_rx_errors_get(src, &val64);
    of_port_stats_entry_rx_errors_set(dst, val64);

    of_port_stats_entry_tx_errors_get(src, &val64);
    of_port_stats_entry_tx_errors_set(dst, val64);

    of_port_stats_entry_rx_frame_err_get(src, &val64);
    of_port_stats_entry_rx_frame_err_set(dst, val64);

    of_port_stats_entry_rx_over_err_get(src, &val64);
    of_port_stats_entry_rx_over_err_set(dst, val64);

    of_port_stats_entry_rx_crc_err_get(src, &val64);
    of_port_stats_entry_rx_crc_err_set(dst, val64);

    of_port_stats_entry_collisions_get(src, &val64);
    of_port_stats_entry_collisions_set(dst, val64);

    of_port_stats_entry_duration_sec_get(src, &val32);
    of_port_stats_entry_duration_sec_set(dst, val32);

    of_port_stats_entry_duration_nsec_get(src, &val32);
    of_port_stats_entry_duration_nsec_set(dst, val32);

    return dst;
}

/**
 * Duplicate a super class object of type of_queue_prop
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_queue_prop.
 *
 * The caller is responsible for deleting the returned value
 */
of_queue_prop_t *
of_queue_prop_OF_VERSION_1_3_dup(
    of_queue_prop_t *src)
{

    if (src->header.object_id == OF_QUEUE_PROP_MIN_RATE) {
        return (of_queue_prop_t *)of_queue_prop_min_rate_OF_VERSION_1_3_dup(
            &src->min_rate);
    }

    if (src->header.object_id == OF_QUEUE_PROP_MAX_RATE) {
        return (of_queue_prop_t *)of_queue_prop_max_rate_OF_VERSION_1_3_dup(
            &src->max_rate);
    }

    if (src->header.object_id == OF_QUEUE_PROP_EXPERIMENTER) {
        return (of_queue_prop_t *)of_queue_prop_experimenter_OF_VERSION_1_3_dup(
            &src->experimenter);
    }

    return NULL;
}

/**
 * Duplicate an object of type of_queue_prop_experimenter
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_queue_prop_experimenter.
 *
 * The caller is responsible for deleting the returned value
 */
of_queue_prop_experimenter_t *
of_queue_prop_experimenter_OF_VERSION_1_3_dup(
    of_queue_prop_experimenter_t *src)
{
    of_queue_prop_experimenter_t *dst;
    uint32_t val32;
    of_octets_t octets;

    if ((dst = of_queue_prop_experimenter_new(src->version)) == NULL) {
        return NULL;
    }

    of_queue_prop_experimenter_experimenter_get(src, &val32);
    of_queue_prop_experimenter_experimenter_set(dst, val32);

    of_queue_prop_experimenter_data_get(src, &octets);
    of_queue_prop_experimenter_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_queue_prop_header
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_queue_prop_header.
 *
 * The caller is responsible for deleting the returned value
 */
of_queue_prop_header_t *
of_queue_prop_header_OF_VERSION_1_3_dup(
    of_queue_prop_header_t *src)
{
    of_queue_prop_header_t *dst;

    if ((dst = of_queue_prop_header_new(src->version)) == NULL) {
        return NULL;
    }

    return dst;
}

/**
 * Duplicate an object of type of_queue_prop_max_rate
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_queue_prop_max_rate.
 *
 * The caller is responsible for deleting the returned value
 */
of_queue_prop_max_rate_t *
of_queue_prop_max_rate_OF_VERSION_1_3_dup(
    of_queue_prop_max_rate_t *src)
{
    of_queue_prop_max_rate_t *dst;
    uint16_t val16;

    if ((dst = of_queue_prop_max_rate_new(src->version)) == NULL) {
        return NULL;
    }

    of_queue_prop_max_rate_rate_get(src, &val16);
    of_queue_prop_max_rate_rate_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_queue_prop_min_rate
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_queue_prop_min_rate.
 *
 * The caller is responsible for deleting the returned value
 */
of_queue_prop_min_rate_t *
of_queue_prop_min_rate_OF_VERSION_1_3_dup(
    of_queue_prop_min_rate_t *src)
{
    of_queue_prop_min_rate_t *dst;
    uint16_t val16;

    if ((dst = of_queue_prop_min_rate_new(src->version)) == NULL) {
        return NULL;
    }

    of_queue_prop_min_rate_rate_get(src, &val16);
    of_queue_prop_min_rate_rate_set(dst, val16);

    return dst;
}

/**
 * Duplicate an object of type of_queue_stats_entry
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_queue_stats_entry.
 *
 * The caller is responsible for deleting the returned value
 */
of_queue_stats_entry_t *
of_queue_stats_entry_OF_VERSION_1_3_dup(
    of_queue_stats_entry_t *src)
{
    of_queue_stats_entry_t *dst;
    of_port_no_t port_no;
    uint32_t val32;
    uint64_t val64;

    if ((dst = of_queue_stats_entry_new(src->version)) == NULL) {
        return NULL;
    }

    of_queue_stats_entry_port_no_get(src, &port_no);
    of_queue_stats_entry_port_no_set(dst, port_no);

    of_queue_stats_entry_queue_id_get(src, &val32);
    of_queue_stats_entry_queue_id_set(dst, val32);

    of_queue_stats_entry_tx_bytes_get(src, &val64);
    of_queue_stats_entry_tx_bytes_set(dst, val64);

    of_queue_stats_entry_tx_packets_get(src, &val64);
    of_queue_stats_entry_tx_packets_set(dst, val64);

    of_queue_stats_entry_tx_errors_get(src, &val64);
    of_queue_stats_entry_tx_errors_set(dst, val64);

    of_queue_stats_entry_duration_sec_get(src, &val32);
    of_queue_stats_entry_duration_sec_set(dst, val32);

    of_queue_stats_entry_duration_nsec_get(src, &val32);
    of_queue_stats_entry_duration_nsec_set(dst, val32);

    return dst;
}

/**
 * Duplicate a super class object of type of_table_feature_prop
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_table_feature_prop.
 *
 * The caller is responsible for deleting the returned value
 */
of_table_feature_prop_t *
of_table_feature_prop_OF_VERSION_1_3_dup(
    of_table_feature_prop_t *src)
{

    if (src->header.object_id == OF_TABLE_FEATURE_PROP_NEXT_TABLES_MISS) {
        return (of_table_feature_prop_t *)of_table_feature_prop_next_tables_miss_OF_VERSION_1_3_dup(
            &src->next_tables_miss);
    }

    if (src->header.object_id == OF_TABLE_FEATURE_PROP_WILDCARDS) {
        return (of_table_feature_prop_t *)of_table_feature_prop_wildcards_OF_VERSION_1_3_dup(
            &src->wildcards);
    }

    if (src->header.object_id == OF_TABLE_FEATURE_PROP_WRITE_ACTIONS) {
        return (of_table_feature_prop_t *)of_table_feature_prop_write_actions_OF_VERSION_1_3_dup(
            &src->write_actions);
    }

    if (src->header.object_id == OF_TABLE_FEATURE_PROP_WRITE_ACTIONS_MISS) {
        return (of_table_feature_prop_t *)of_table_feature_prop_write_actions_miss_OF_VERSION_1_3_dup(
            &src->write_actions_miss);
    }

    if (src->header.object_id == OF_TABLE_FEATURE_PROP_NEXT_TABLES) {
        return (of_table_feature_prop_t *)of_table_feature_prop_next_tables_OF_VERSION_1_3_dup(
            &src->next_tables);
    }

    if (src->header.object_id == OF_TABLE_FEATURE_PROP_APPLY_ACTIONS_MISS) {
        return (of_table_feature_prop_t *)of_table_feature_prop_apply_actions_miss_OF_VERSION_1_3_dup(
            &src->apply_actions_miss);
    }

    if (src->header.object_id == OF_TABLE_FEATURE_PROP_APPLY_ACTIONS) {
        return (of_table_feature_prop_t *)of_table_feature_prop_apply_actions_OF_VERSION_1_3_dup(
            &src->apply_actions);
    }

    if (src->header.object_id == OF_TABLE_FEATURE_PROP_APPLY_SETFIELD_MISS) {
        return (of_table_feature_prop_t *)of_table_feature_prop_apply_setfield_miss_OF_VERSION_1_3_dup(
            &src->apply_setfield_miss);
    }

    if (src->header.object_id == OF_TABLE_FEATURE_PROP_EXPERIMENTER) {
        return (of_table_feature_prop_t *)of_table_feature_prop_experimenter_OF_VERSION_1_3_dup(
            &src->experimenter);
    }

    if (src->header.object_id == OF_TABLE_FEATURE_PROP_WRITE_SETFIELD_MISS) {
        return (of_table_feature_prop_t *)of_table_feature_prop_write_setfield_miss_OF_VERSION_1_3_dup(
            &src->write_setfield_miss);
    }

    if (src->header.object_id == OF_TABLE_FEATURE_PROP_WRITE_SETFIELD) {
        return (of_table_feature_prop_t *)of_table_feature_prop_write_setfield_OF_VERSION_1_3_dup(
            &src->write_setfield);
    }

    if (src->header.object_id == OF_TABLE_FEATURE_PROP_INSTRUCTIONS_MISS) {
        return (of_table_feature_prop_t *)of_table_feature_prop_instructions_miss_OF_VERSION_1_3_dup(
            &src->instructions_miss);
    }

    if (src->header.object_id == OF_TABLE_FEATURE_PROP_APPLY_SETFIELD) {
        return (of_table_feature_prop_t *)of_table_feature_prop_apply_setfield_OF_VERSION_1_3_dup(
            &src->apply_setfield);
    }

    if (src->header.object_id == OF_TABLE_FEATURE_PROP_MATCH) {
        return (of_table_feature_prop_t *)of_table_feature_prop_match_OF_VERSION_1_3_dup(
            &src->match);
    }

    if (src->header.object_id == OF_TABLE_FEATURE_PROP_INSTRUCTIONS) {
        return (of_table_feature_prop_t *)of_table_feature_prop_instructions_OF_VERSION_1_3_dup(
            &src->instructions);
    }

    return NULL;
}

/**
 * Duplicate an object of type of_table_feature_prop_apply_actions
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_table_feature_prop_apply_actions.
 *
 * The caller is responsible for deleting the returned value
 */
of_table_feature_prop_apply_actions_t *
of_table_feature_prop_apply_actions_OF_VERSION_1_3_dup(
    of_table_feature_prop_apply_actions_t *src)
{
    of_table_feature_prop_apply_actions_t *dst;

    of_list_action_id_t src_list;
    of_list_action_id_t *dst_list;

    if ((dst = of_table_feature_prop_apply_actions_new(src->version)) == NULL) {
        return NULL;
    }

    of_table_feature_prop_apply_actions_action_ids_bind(
        src, &src_list);
    dst_list = of_list_action_id_OF_VERSION_1_3_dup(&src_list);
    if (dst_list == NULL) {
        of_table_feature_prop_apply_actions_delete(dst);
        return NULL;
    }
    of_table_feature_prop_apply_actions_action_ids_set(dst, dst_list);
    of_list_action_id_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_table_feature_prop_apply_actions_miss
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_table_feature_prop_apply_actions_miss.
 *
 * The caller is responsible for deleting the returned value
 */
of_table_feature_prop_apply_actions_miss_t *
of_table_feature_prop_apply_actions_miss_OF_VERSION_1_3_dup(
    of_table_feature_prop_apply_actions_miss_t *src)
{
    of_table_feature_prop_apply_actions_miss_t *dst;

    of_list_action_id_t src_list;
    of_list_action_id_t *dst_list;

    if ((dst = of_table_feature_prop_apply_actions_miss_new(src->version)) == NULL) {
        return NULL;
    }

    of_table_feature_prop_apply_actions_miss_action_ids_bind(
        src, &src_list);
    dst_list = of_list_action_id_OF_VERSION_1_3_dup(&src_list);
    if (dst_list == NULL) {
        of_table_feature_prop_apply_actions_miss_delete(dst);
        return NULL;
    }
    of_table_feature_prop_apply_actions_miss_action_ids_set(dst, dst_list);
    of_list_action_id_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_table_feature_prop_apply_setfield
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_table_feature_prop_apply_setfield.
 *
 * The caller is responsible for deleting the returned value
 */
of_table_feature_prop_apply_setfield_t *
of_table_feature_prop_apply_setfield_OF_VERSION_1_3_dup(
    of_table_feature_prop_apply_setfield_t *src)
{
    of_table_feature_prop_apply_setfield_t *dst;

    of_list_uint32_t src_list;
    of_list_uint32_t *dst_list;

    if ((dst = of_table_feature_prop_apply_setfield_new(src->version)) == NULL) {
        return NULL;
    }

    of_table_feature_prop_apply_setfield_oxm_ids_bind(
        src, &src_list);
    dst_list = of_list_uint32_OF_VERSION_1_3_dup(&src_list);
    if (dst_list == NULL) {
        of_table_feature_prop_apply_setfield_delete(dst);
        return NULL;
    }
    of_table_feature_prop_apply_setfield_oxm_ids_set(dst, dst_list);
    of_list_uint32_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_table_feature_prop_apply_setfield_miss
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_table_feature_prop_apply_setfield_miss.
 *
 * The caller is responsible for deleting the returned value
 */
of_table_feature_prop_apply_setfield_miss_t *
of_table_feature_prop_apply_setfield_miss_OF_VERSION_1_3_dup(
    of_table_feature_prop_apply_setfield_miss_t *src)
{
    of_table_feature_prop_apply_setfield_miss_t *dst;

    of_list_uint32_t src_list;
    of_list_uint32_t *dst_list;

    if ((dst = of_table_feature_prop_apply_setfield_miss_new(src->version)) == NULL) {
        return NULL;
    }

    of_table_feature_prop_apply_setfield_miss_oxm_ids_bind(
        src, &src_list);
    dst_list = of_list_uint32_OF_VERSION_1_3_dup(&src_list);
    if (dst_list == NULL) {
        of_table_feature_prop_apply_setfield_miss_delete(dst);
        return NULL;
    }
    of_table_feature_prop_apply_setfield_miss_oxm_ids_set(dst, dst_list);
    of_list_uint32_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_table_feature_prop_experimenter
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_table_feature_prop_experimenter.
 *
 * The caller is responsible for deleting the returned value
 */
of_table_feature_prop_experimenter_t *
of_table_feature_prop_experimenter_OF_VERSION_1_3_dup(
    of_table_feature_prop_experimenter_t *src)
{
    of_table_feature_prop_experimenter_t *dst;
    uint32_t val32;
    of_octets_t octets;

    if ((dst = of_table_feature_prop_experimenter_new(src->version)) == NULL) {
        return NULL;
    }

    of_table_feature_prop_experimenter_experimenter_get(src, &val32);
    of_table_feature_prop_experimenter_experimenter_set(dst, val32);

    of_table_feature_prop_experimenter_subtype_get(src, &val32);
    of_table_feature_prop_experimenter_subtype_set(dst, val32);

    of_table_feature_prop_experimenter_experimenter_data_get(src, &octets);
    of_table_feature_prop_experimenter_experimenter_data_set(dst, &octets);

    return dst;
}

/**
 * Duplicate an object of type of_table_feature_prop_header
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_table_feature_prop_header.
 *
 * The caller is responsible for deleting the returned value
 */
of_table_feature_prop_header_t *
of_table_feature_prop_header_OF_VERSION_1_3_dup(
    of_table_feature_prop_header_t *src)
{
    of_table_feature_prop_header_t *dst;

    if ((dst = of_table_feature_prop_header_new(src->version)) == NULL) {
        return NULL;
    }

    return dst;
}

/**
 * Duplicate an object of type of_table_feature_prop_instructions
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_table_feature_prop_instructions.
 *
 * The caller is responsible for deleting the returned value
 */
of_table_feature_prop_instructions_t *
of_table_feature_prop_instructions_OF_VERSION_1_3_dup(
    of_table_feature_prop_instructions_t *src)
{
    of_table_feature_prop_instructions_t *dst;

    of_list_instruction_t src_list;
    of_list_instruction_t *dst_list;

    if ((dst = of_table_feature_prop_instructions_new(src->version)) == NULL) {
        return NULL;
    }

    of_table_feature_prop_instructions_instruction_ids_bind(
        src, &src_list);
    dst_list = of_list_instruction_OF_VERSION_1_3_dup(&src_list);
    if (dst_list == NULL) {
        of_table_feature_prop_instructions_delete(dst);
        return NULL;
    }
    of_table_feature_prop_instructions_instruction_ids_set(dst, dst_list);
    of_list_instruction_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_table_feature_prop_instructions_miss
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_table_feature_prop_instructions_miss.
 *
 * The caller is responsible for deleting the returned value
 */
of_table_feature_prop_instructions_miss_t *
of_table_feature_prop_instructions_miss_OF_VERSION_1_3_dup(
    of_table_feature_prop_instructions_miss_t *src)
{
    of_table_feature_prop_instructions_miss_t *dst;

    of_list_instruction_t src_list;
    of_list_instruction_t *dst_list;

    if ((dst = of_table_feature_prop_instructions_miss_new(src->version)) == NULL) {
        return NULL;
    }

    of_table_feature_prop_instructions_miss_instruction_ids_bind(
        src, &src_list);
    dst_list = of_list_instruction_OF_VERSION_1_3_dup(&src_list);
    if (dst_list == NULL) {
        of_table_feature_prop_instructions_miss_delete(dst);
        return NULL;
    }
    of_table_feature_prop_instructions_miss_instruction_ids_set(dst, dst_list);
    of_list_instruction_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_table_feature_prop_match
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_table_feature_prop_match.
 *
 * The caller is responsible for deleting the returned value
 */
of_table_feature_prop_match_t *
of_table_feature_prop_match_OF_VERSION_1_3_dup(
    of_table_feature_prop_match_t *src)
{
    of_table_feature_prop_match_t *dst;

    of_list_uint32_t src_list;
    of_list_uint32_t *dst_list;

    if ((dst = of_table_feature_prop_match_new(src->version)) == NULL) {
        return NULL;
    }

    of_table_feature_prop_match_oxm_ids_bind(
        src, &src_list);
    dst_list = of_list_uint32_OF_VERSION_1_3_dup(&src_list);
    if (dst_list == NULL) {
        of_table_feature_prop_match_delete(dst);
        return NULL;
    }
    of_table_feature_prop_match_oxm_ids_set(dst, dst_list);
    of_list_uint32_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_table_feature_prop_next_tables
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_table_feature_prop_next_tables.
 *
 * The caller is responsible for deleting the returned value
 */
of_table_feature_prop_next_tables_t *
of_table_feature_prop_next_tables_OF_VERSION_1_3_dup(
    of_table_feature_prop_next_tables_t *src)
{
    of_table_feature_prop_next_tables_t *dst;

    of_list_uint8_t src_list;
    of_list_uint8_t *dst_list;

    if ((dst = of_table_feature_prop_next_tables_new(src->version)) == NULL) {
        return NULL;
    }

    of_table_feature_prop_next_tables_next_table_ids_bind(
        src, &src_list);
    dst_list = of_list_uint8_OF_VERSION_1_3_dup(&src_list);
    if (dst_list == NULL) {
        of_table_feature_prop_next_tables_delete(dst);
        return NULL;
    }
    of_table_feature_prop_next_tables_next_table_ids_set(dst, dst_list);
    of_list_uint8_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_table_feature_prop_next_tables_miss
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_table_feature_prop_next_tables_miss.
 *
 * The caller is responsible for deleting the returned value
 */
of_table_feature_prop_next_tables_miss_t *
of_table_feature_prop_next_tables_miss_OF_VERSION_1_3_dup(
    of_table_feature_prop_next_tables_miss_t *src)
{
    of_table_feature_prop_next_tables_miss_t *dst;

    of_list_uint8_t src_list;
    of_list_uint8_t *dst_list;

    if ((dst = of_table_feature_prop_next_tables_miss_new(src->version)) == NULL) {
        return NULL;
    }

    of_table_feature_prop_next_tables_miss_next_table_ids_bind(
        src, &src_list);
    dst_list = of_list_uint8_OF_VERSION_1_3_dup(&src_list);
    if (dst_list == NULL) {
        of_table_feature_prop_next_tables_miss_delete(dst);
        return NULL;
    }
    of_table_feature_prop_next_tables_miss_next_table_ids_set(dst, dst_list);
    of_list_uint8_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_table_feature_prop_wildcards
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_table_feature_prop_wildcards.
 *
 * The caller is responsible for deleting the returned value
 */
of_table_feature_prop_wildcards_t *
of_table_feature_prop_wildcards_OF_VERSION_1_3_dup(
    of_table_feature_prop_wildcards_t *src)
{
    of_table_feature_prop_wildcards_t *dst;

    of_list_uint32_t src_list;
    of_list_uint32_t *dst_list;

    if ((dst = of_table_feature_prop_wildcards_new(src->version)) == NULL) {
        return NULL;
    }

    of_table_feature_prop_wildcards_oxm_ids_bind(
        src, &src_list);
    dst_list = of_list_uint32_OF_VERSION_1_3_dup(&src_list);
    if (dst_list == NULL) {
        of_table_feature_prop_wildcards_delete(dst);
        return NULL;
    }
    of_table_feature_prop_wildcards_oxm_ids_set(dst, dst_list);
    of_list_uint32_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_table_feature_prop_write_actions
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_table_feature_prop_write_actions.
 *
 * The caller is responsible for deleting the returned value
 */
of_table_feature_prop_write_actions_t *
of_table_feature_prop_write_actions_OF_VERSION_1_3_dup(
    of_table_feature_prop_write_actions_t *src)
{
    of_table_feature_prop_write_actions_t *dst;

    of_list_action_id_t src_list;
    of_list_action_id_t *dst_list;

    if ((dst = of_table_feature_prop_write_actions_new(src->version)) == NULL) {
        return NULL;
    }

    of_table_feature_prop_write_actions_action_ids_bind(
        src, &src_list);
    dst_list = of_list_action_id_OF_VERSION_1_3_dup(&src_list);
    if (dst_list == NULL) {
        of_table_feature_prop_write_actions_delete(dst);
        return NULL;
    }
    of_table_feature_prop_write_actions_action_ids_set(dst, dst_list);
    of_list_action_id_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_table_feature_prop_write_actions_miss
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_table_feature_prop_write_actions_miss.
 *
 * The caller is responsible for deleting the returned value
 */
of_table_feature_prop_write_actions_miss_t *
of_table_feature_prop_write_actions_miss_OF_VERSION_1_3_dup(
    of_table_feature_prop_write_actions_miss_t *src)
{
    of_table_feature_prop_write_actions_miss_t *dst;

    of_list_action_id_t src_list;
    of_list_action_id_t *dst_list;

    if ((dst = of_table_feature_prop_write_actions_miss_new(src->version)) == NULL) {
        return NULL;
    }

    of_table_feature_prop_write_actions_miss_action_ids_bind(
        src, &src_list);
    dst_list = of_list_action_id_OF_VERSION_1_3_dup(&src_list);
    if (dst_list == NULL) {
        of_table_feature_prop_write_actions_miss_delete(dst);
        return NULL;
    }
    of_table_feature_prop_write_actions_miss_action_ids_set(dst, dst_list);
    of_list_action_id_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_table_feature_prop_write_setfield
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_table_feature_prop_write_setfield.
 *
 * The caller is responsible for deleting the returned value
 */
of_table_feature_prop_write_setfield_t *
of_table_feature_prop_write_setfield_OF_VERSION_1_3_dup(
    of_table_feature_prop_write_setfield_t *src)
{
    of_table_feature_prop_write_setfield_t *dst;

    of_list_uint32_t src_list;
    of_list_uint32_t *dst_list;

    if ((dst = of_table_feature_prop_write_setfield_new(src->version)) == NULL) {
        return NULL;
    }

    of_table_feature_prop_write_setfield_oxm_ids_bind(
        src, &src_list);
    dst_list = of_list_uint32_OF_VERSION_1_3_dup(&src_list);
    if (dst_list == NULL) {
        of_table_feature_prop_write_setfield_delete(dst);
        return NULL;
    }
    of_table_feature_prop_write_setfield_oxm_ids_set(dst, dst_list);
    of_list_uint32_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_table_feature_prop_write_setfield_miss
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_table_feature_prop_write_setfield_miss.
 *
 * The caller is responsible for deleting the returned value
 */
of_table_feature_prop_write_setfield_miss_t *
of_table_feature_prop_write_setfield_miss_OF_VERSION_1_3_dup(
    of_table_feature_prop_write_setfield_miss_t *src)
{
    of_table_feature_prop_write_setfield_miss_t *dst;

    of_list_uint32_t src_list;
    of_list_uint32_t *dst_list;

    if ((dst = of_table_feature_prop_write_setfield_miss_new(src->version)) == NULL) {
        return NULL;
    }

    of_table_feature_prop_write_setfield_miss_oxm_ids_bind(
        src, &src_list);
    dst_list = of_list_uint32_OF_VERSION_1_3_dup(&src_list);
    if (dst_list == NULL) {
        of_table_feature_prop_write_setfield_miss_delete(dst);
        return NULL;
    }
    of_table_feature_prop_write_setfield_miss_oxm_ids_set(dst, dst_list);
    of_list_uint32_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_table_features
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_table_features.
 *
 * The caller is responsible for deleting the returned value
 */
of_table_features_t *
of_table_features_OF_VERSION_1_3_dup(
    of_table_features_t *src)
{
    of_table_features_t *dst;
    uint8_t val8;
    of_table_name_t table_name;
    uint64_t val64;
    uint32_t val32;

    of_list_table_feature_prop_t src_list;
    of_list_table_feature_prop_t *dst_list;

    if ((dst = of_table_features_new(src->version)) == NULL) {
        return NULL;
    }

    of_table_features_table_id_get(src, &val8);
    of_table_features_table_id_set(dst, val8);

    of_table_features_name_get(src, &table_name);
    of_table_features_name_set(dst, table_name);

    of_table_features_metadata_match_get(src, &val64);
    of_table_features_metadata_match_set(dst, val64);

    of_table_features_metadata_write_get(src, &val64);
    of_table_features_metadata_write_set(dst, val64);

    of_table_features_config_get(src, &val32);
    of_table_features_config_set(dst, val32);

    of_table_features_max_entries_get(src, &val32);
    of_table_features_max_entries_set(dst, val32);

    of_table_features_properties_bind(
        src, &src_list);
    dst_list = of_list_table_feature_prop_OF_VERSION_1_3_dup(&src_list);
    if (dst_list == NULL) {
        of_table_features_delete(dst);
        return NULL;
    }
    of_table_features_properties_set(dst, dst_list);
    of_list_table_feature_prop_delete(dst_list);

    return dst;
}

/**
 * Duplicate an object of type of_table_stats_entry
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_table_stats_entry.
 *
 * The caller is responsible for deleting the returned value
 */
of_table_stats_entry_t *
of_table_stats_entry_OF_VERSION_1_3_dup(
    of_table_stats_entry_t *src)
{
    of_table_stats_entry_t *dst;
    uint8_t val8;
    uint32_t val32;
    uint64_t val64;

    if ((dst = of_table_stats_entry_new(src->version)) == NULL) {
        return NULL;
    }

    of_table_stats_entry_table_id_get(src, &val8);
    of_table_stats_entry_table_id_set(dst, val8);

    of_table_stats_entry_active_count_get(src, &val32);
    of_table_stats_entry_active_count_set(dst, val32);

    of_table_stats_entry_lookup_count_get(src, &val64);
    of_table_stats_entry_lookup_count_set(dst, val64);

    of_table_stats_entry_matched_count_get(src, &val64);
    of_table_stats_entry_matched_count_set(dst, val64);

    return dst;
}

/**
 * Duplicate an object of type of_uint32
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_uint32.
 *
 * The caller is responsible for deleting the returned value
 */
of_uint32_t *
of_uint32_OF_VERSION_1_3_dup(
    of_uint32_t *src)
{
    of_uint32_t *dst;
    uint32_t val32;

    if ((dst = of_uint32_new(src->version)) == NULL) {
        return NULL;
    }

    of_uint32_value_get(src, &val32);
    of_uint32_value_set(dst, val32);

    return dst;
}

/**
 * Duplicate an object of type of_uint8
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_uint8.
 *
 * The caller is responsible for deleting the returned value
 */
of_uint8_t *
of_uint8_OF_VERSION_1_3_dup(
    of_uint8_t *src)
{
    of_uint8_t *dst;
    uint8_t val8;

    if ((dst = of_uint8_new(src->version)) == NULL) {
        return NULL;
    }

    of_uint8_value_get(src, &val8);
    of_uint8_value_set(dst, val8);

    return dst;
}

/**
 * Duplicate a list of type of_list_action
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_list_action.
 *
 * The caller is responsible for deleting the returned value
 */
of_list_action_t *
of_list_action_OF_VERSION_1_3_dup(
    of_list_action_t *src)
{
    of_action_t src_elt;
    of_action_t *dst_elt;
    int rv;
    of_list_action_t *dst;

    if ((dst = of_list_action_new(src->version)) == NULL) {
        return NULL;
    }

    OF_LIST_ACTION_ITER(src, &src_elt, rv) {
        if ((dst_elt = of_action_OF_VERSION_1_3_dup(&src_elt)) == NULL) {
            of_object_delete((of_object_t *)dst);
            return NULL;
        }
        _TRY_FREE(of_list_action_append(dst, dst_elt),
            dst, NULL);
        of_object_delete((of_object_t *)dst_elt);
    }

    return dst;
}

/**
 * Duplicate a list of type of_list_action_id
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_list_action_id.
 *
 * The caller is responsible for deleting the returned value
 */
of_list_action_id_t *
of_list_action_id_OF_VERSION_1_3_dup(
    of_list_action_id_t *src)
{
    of_action_id_t src_elt;
    of_action_id_t *dst_elt;
    int rv;
    of_list_action_id_t *dst;

    if ((dst = of_list_action_id_new(src->version)) == NULL) {
        return NULL;
    }

    OF_LIST_ACTION_ID_ITER(src, &src_elt, rv) {
        if ((dst_elt = of_action_id_OF_VERSION_1_3_dup(&src_elt)) == NULL) {
            of_object_delete((of_object_t *)dst);
            return NULL;
        }
        _TRY_FREE(of_list_action_id_append(dst, dst_elt),
            dst, NULL);
        of_object_delete((of_object_t *)dst_elt);
    }

    return dst;
}

/**
 * Duplicate a list of type of_list_bsn_interface
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_list_bsn_interface.
 *
 * The caller is responsible for deleting the returned value
 */
of_list_bsn_interface_t *
of_list_bsn_interface_OF_VERSION_1_3_dup(
    of_list_bsn_interface_t *src)
{
    of_bsn_interface_t src_elt;
    of_bsn_interface_t *dst_elt;
    int rv;
    of_list_bsn_interface_t *dst;

    if ((dst = of_list_bsn_interface_new(src->version)) == NULL) {
        return NULL;
    }

    OF_LIST_BSN_INTERFACE_ITER(src, &src_elt, rv) {
        if ((dst_elt = of_bsn_interface_OF_VERSION_1_3_dup(&src_elt)) == NULL) {
            of_object_delete((of_object_t *)dst);
            return NULL;
        }
        _TRY_FREE(of_list_bsn_interface_append(dst, dst_elt),
            dst, NULL);
        of_object_delete((of_object_t *)dst_elt);
    }

    return dst;
}

/**
 * Duplicate a list of type of_list_bucket
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_list_bucket.
 *
 * The caller is responsible for deleting the returned value
 */
of_list_bucket_t *
of_list_bucket_OF_VERSION_1_3_dup(
    of_list_bucket_t *src)
{
    of_bucket_t src_elt;
    of_bucket_t *dst_elt;
    int rv;
    of_list_bucket_t *dst;

    if ((dst = of_list_bucket_new(src->version)) == NULL) {
        return NULL;
    }

    OF_LIST_BUCKET_ITER(src, &src_elt, rv) {
        if ((dst_elt = of_bucket_OF_VERSION_1_3_dup(&src_elt)) == NULL) {
            of_object_delete((of_object_t *)dst);
            return NULL;
        }
        _TRY_FREE(of_list_bucket_append(dst, dst_elt),
            dst, NULL);
        of_object_delete((of_object_t *)dst_elt);
    }

    return dst;
}

/**
 * Duplicate a list of type of_list_bucket_counter
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_list_bucket_counter.
 *
 * The caller is responsible for deleting the returned value
 */
of_list_bucket_counter_t *
of_list_bucket_counter_OF_VERSION_1_3_dup(
    of_list_bucket_counter_t *src)
{
    of_bucket_counter_t src_elt;
    of_bucket_counter_t *dst_elt;
    int rv;
    of_list_bucket_counter_t *dst;

    if ((dst = of_list_bucket_counter_new(src->version)) == NULL) {
        return NULL;
    }

    OF_LIST_BUCKET_COUNTER_ITER(src, &src_elt, rv) {
        if ((dst_elt = of_bucket_counter_OF_VERSION_1_3_dup(&src_elt)) == NULL) {
            of_object_delete((of_object_t *)dst);
            return NULL;
        }
        _TRY_FREE(of_list_bucket_counter_append(dst, dst_elt),
            dst, NULL);
        of_object_delete((of_object_t *)dst_elt);
    }

    return dst;
}

/**
 * Duplicate a list of type of_list_flow_stats_entry
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_list_flow_stats_entry.
 *
 * The caller is responsible for deleting the returned value
 */
of_list_flow_stats_entry_t *
of_list_flow_stats_entry_OF_VERSION_1_3_dup(
    of_list_flow_stats_entry_t *src)
{
    of_flow_stats_entry_t src_elt;
    of_flow_stats_entry_t *dst_elt;
    int rv;
    of_list_flow_stats_entry_t *dst;

    if ((dst = of_list_flow_stats_entry_new(src->version)) == NULL) {
        return NULL;
    }

    OF_LIST_FLOW_STATS_ENTRY_ITER(src, &src_elt, rv) {
        if ((dst_elt = of_flow_stats_entry_OF_VERSION_1_3_dup(&src_elt)) == NULL) {
            of_object_delete((of_object_t *)dst);
            return NULL;
        }
        _TRY_FREE(of_list_flow_stats_entry_append(dst, dst_elt),
            dst, NULL);
        of_object_delete((of_object_t *)dst_elt);
    }

    return dst;
}

/**
 * Duplicate a list of type of_list_group_desc_stats_entry
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_list_group_desc_stats_entry.
 *
 * The caller is responsible for deleting the returned value
 */
of_list_group_desc_stats_entry_t *
of_list_group_desc_stats_entry_OF_VERSION_1_3_dup(
    of_list_group_desc_stats_entry_t *src)
{
    of_group_desc_stats_entry_t src_elt;
    of_group_desc_stats_entry_t *dst_elt;
    int rv;
    of_list_group_desc_stats_entry_t *dst;

    if ((dst = of_list_group_desc_stats_entry_new(src->version)) == NULL) {
        return NULL;
    }

    OF_LIST_GROUP_DESC_STATS_ENTRY_ITER(src, &src_elt, rv) {
        if ((dst_elt = of_group_desc_stats_entry_OF_VERSION_1_3_dup(&src_elt)) == NULL) {
            of_object_delete((of_object_t *)dst);
            return NULL;
        }
        _TRY_FREE(of_list_group_desc_stats_entry_append(dst, dst_elt),
            dst, NULL);
        of_object_delete((of_object_t *)dst_elt);
    }

    return dst;
}

/**
 * Duplicate a list of type of_list_group_stats_entry
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_list_group_stats_entry.
 *
 * The caller is responsible for deleting the returned value
 */
of_list_group_stats_entry_t *
of_list_group_stats_entry_OF_VERSION_1_3_dup(
    of_list_group_stats_entry_t *src)
{
    of_group_stats_entry_t src_elt;
    of_group_stats_entry_t *dst_elt;
    int rv;
    of_list_group_stats_entry_t *dst;

    if ((dst = of_list_group_stats_entry_new(src->version)) == NULL) {
        return NULL;
    }

    OF_LIST_GROUP_STATS_ENTRY_ITER(src, &src_elt, rv) {
        if ((dst_elt = of_group_stats_entry_OF_VERSION_1_3_dup(&src_elt)) == NULL) {
            of_object_delete((of_object_t *)dst);
            return NULL;
        }
        _TRY_FREE(of_list_group_stats_entry_append(dst, dst_elt),
            dst, NULL);
        of_object_delete((of_object_t *)dst_elt);
    }

    return dst;
}

/**
 * Duplicate a list of type of_list_hello_elem
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_list_hello_elem.
 *
 * The caller is responsible for deleting the returned value
 */
of_list_hello_elem_t *
of_list_hello_elem_OF_VERSION_1_3_dup(
    of_list_hello_elem_t *src)
{
    of_hello_elem_t src_elt;
    of_hello_elem_t *dst_elt;
    int rv;
    of_list_hello_elem_t *dst;

    if ((dst = of_list_hello_elem_new(src->version)) == NULL) {
        return NULL;
    }

    OF_LIST_HELLO_ELEM_ITER(src, &src_elt, rv) {
        if ((dst_elt = of_hello_elem_OF_VERSION_1_3_dup(&src_elt)) == NULL) {
            of_object_delete((of_object_t *)dst);
            return NULL;
        }
        _TRY_FREE(of_list_hello_elem_append(dst, dst_elt),
            dst, NULL);
        of_object_delete((of_object_t *)dst_elt);
    }

    return dst;
}

/**
 * Duplicate a list of type of_list_instruction
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_list_instruction.
 *
 * The caller is responsible for deleting the returned value
 */
of_list_instruction_t *
of_list_instruction_OF_VERSION_1_3_dup(
    of_list_instruction_t *src)
{
    of_instruction_t src_elt;
    of_instruction_t *dst_elt;
    int rv;
    of_list_instruction_t *dst;

    if ((dst = of_list_instruction_new(src->version)) == NULL) {
        return NULL;
    }

    OF_LIST_INSTRUCTION_ITER(src, &src_elt, rv) {
        if ((dst_elt = of_instruction_OF_VERSION_1_3_dup(&src_elt)) == NULL) {
            of_object_delete((of_object_t *)dst);
            return NULL;
        }
        _TRY_FREE(of_list_instruction_append(dst, dst_elt),
            dst, NULL);
        of_object_delete((of_object_t *)dst_elt);
    }

    return dst;
}

/**
 * Duplicate a list of type of_list_meter_band
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_list_meter_band.
 *
 * The caller is responsible for deleting the returned value
 */
of_list_meter_band_t *
of_list_meter_band_OF_VERSION_1_3_dup(
    of_list_meter_band_t *src)
{
    of_meter_band_t src_elt;
    of_meter_band_t *dst_elt;
    int rv;
    of_list_meter_band_t *dst;

    if ((dst = of_list_meter_band_new(src->version)) == NULL) {
        return NULL;
    }

    OF_LIST_METER_BAND_ITER(src, &src_elt, rv) {
        if ((dst_elt = of_meter_band_OF_VERSION_1_3_dup(&src_elt)) == NULL) {
            of_object_delete((of_object_t *)dst);
            return NULL;
        }
        _TRY_FREE(of_list_meter_band_append(dst, dst_elt),
            dst, NULL);
        of_object_delete((of_object_t *)dst_elt);
    }

    return dst;
}

/**
 * Duplicate a list of type of_list_meter_band_stats
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_list_meter_band_stats.
 *
 * The caller is responsible for deleting the returned value
 */
of_list_meter_band_stats_t *
of_list_meter_band_stats_OF_VERSION_1_3_dup(
    of_list_meter_band_stats_t *src)
{
    of_meter_band_stats_t src_elt;
    of_meter_band_stats_t *dst_elt;
    int rv;
    of_list_meter_band_stats_t *dst;

    if ((dst = of_list_meter_band_stats_new(src->version)) == NULL) {
        return NULL;
    }

    OF_LIST_METER_BAND_STATS_ITER(src, &src_elt, rv) {
        if ((dst_elt = of_meter_band_stats_OF_VERSION_1_3_dup(&src_elt)) == NULL) {
            of_object_delete((of_object_t *)dst);
            return NULL;
        }
        _TRY_FREE(of_list_meter_band_stats_append(dst, dst_elt),
            dst, NULL);
        of_object_delete((of_object_t *)dst_elt);
    }

    return dst;
}

/**
 * Duplicate a list of type of_list_meter_stats
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_list_meter_stats.
 *
 * The caller is responsible for deleting the returned value
 */
of_list_meter_stats_t *
of_list_meter_stats_OF_VERSION_1_3_dup(
    of_list_meter_stats_t *src)
{
    of_meter_stats_t src_elt;
    of_meter_stats_t *dst_elt;
    int rv;
    of_list_meter_stats_t *dst;

    if ((dst = of_list_meter_stats_new(src->version)) == NULL) {
        return NULL;
    }

    OF_LIST_METER_STATS_ITER(src, &src_elt, rv) {
        if ((dst_elt = of_meter_stats_OF_VERSION_1_3_dup(&src_elt)) == NULL) {
            of_object_delete((of_object_t *)dst);
            return NULL;
        }
        _TRY_FREE(of_list_meter_stats_append(dst, dst_elt),
            dst, NULL);
        of_object_delete((of_object_t *)dst_elt);
    }

    return dst;
}

/**
 * Duplicate a list of type of_list_oxm
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_list_oxm.
 *
 * The caller is responsible for deleting the returned value
 */
of_list_oxm_t *
of_list_oxm_OF_VERSION_1_3_dup(
    of_list_oxm_t *src)
{
    of_oxm_t src_elt;
    of_oxm_t *dst_elt;
    int rv;
    of_list_oxm_t *dst;

    if ((dst = of_list_oxm_new(src->version)) == NULL) {
        return NULL;
    }

    OF_LIST_OXM_ITER(src, &src_elt, rv) {
        if ((dst_elt = of_oxm_OF_VERSION_1_3_dup(&src_elt)) == NULL) {
            of_object_delete((of_object_t *)dst);
            return NULL;
        }
        _TRY_FREE(of_list_oxm_append(dst, dst_elt),
            dst, NULL);
        of_object_delete((of_object_t *)dst_elt);
    }

    return dst;
}

/**
 * Duplicate a list of type of_list_packet_queue
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_list_packet_queue.
 *
 * The caller is responsible for deleting the returned value
 */
of_list_packet_queue_t *
of_list_packet_queue_OF_VERSION_1_3_dup(
    of_list_packet_queue_t *src)
{
    of_packet_queue_t src_elt;
    of_packet_queue_t *dst_elt;
    int rv;
    of_list_packet_queue_t *dst;

    if ((dst = of_list_packet_queue_new(src->version)) == NULL) {
        return NULL;
    }

    OF_LIST_PACKET_QUEUE_ITER(src, &src_elt, rv) {
        if ((dst_elt = of_packet_queue_OF_VERSION_1_3_dup(&src_elt)) == NULL) {
            of_object_delete((of_object_t *)dst);
            return NULL;
        }
        _TRY_FREE(of_list_packet_queue_append(dst, dst_elt),
            dst, NULL);
        of_object_delete((of_object_t *)dst_elt);
    }

    return dst;
}

/**
 * Duplicate a list of type of_list_port_desc
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_list_port_desc.
 *
 * The caller is responsible for deleting the returned value
 */
of_list_port_desc_t *
of_list_port_desc_OF_VERSION_1_3_dup(
    of_list_port_desc_t *src)
{
    of_port_desc_t src_elt;
    of_port_desc_t *dst_elt;
    int rv;
    of_list_port_desc_t *dst;

    if ((dst = of_list_port_desc_new(src->version)) == NULL) {
        return NULL;
    }

    OF_LIST_PORT_DESC_ITER(src, &src_elt, rv) {
        if ((dst_elt = of_port_desc_OF_VERSION_1_3_dup(&src_elt)) == NULL) {
            of_object_delete((of_object_t *)dst);
            return NULL;
        }
        _TRY_FREE(of_list_port_desc_append(dst, dst_elt),
            dst, NULL);
        of_object_delete((of_object_t *)dst_elt);
    }

    return dst;
}

/**
 * Duplicate a list of type of_list_port_stats_entry
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_list_port_stats_entry.
 *
 * The caller is responsible for deleting the returned value
 */
of_list_port_stats_entry_t *
of_list_port_stats_entry_OF_VERSION_1_3_dup(
    of_list_port_stats_entry_t *src)
{
    of_port_stats_entry_t src_elt;
    of_port_stats_entry_t *dst_elt;
    int rv;
    of_list_port_stats_entry_t *dst;

    if ((dst = of_list_port_stats_entry_new(src->version)) == NULL) {
        return NULL;
    }

    OF_LIST_PORT_STATS_ENTRY_ITER(src, &src_elt, rv) {
        if ((dst_elt = of_port_stats_entry_OF_VERSION_1_3_dup(&src_elt)) == NULL) {
            of_object_delete((of_object_t *)dst);
            return NULL;
        }
        _TRY_FREE(of_list_port_stats_entry_append(dst, dst_elt),
            dst, NULL);
        of_object_delete((of_object_t *)dst_elt);
    }

    return dst;
}

/**
 * Duplicate a list of type of_list_queue_prop
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_list_queue_prop.
 *
 * The caller is responsible for deleting the returned value
 */
of_list_queue_prop_t *
of_list_queue_prop_OF_VERSION_1_3_dup(
    of_list_queue_prop_t *src)
{
    of_queue_prop_t src_elt;
    of_queue_prop_t *dst_elt;
    int rv;
    of_list_queue_prop_t *dst;

    if ((dst = of_list_queue_prop_new(src->version)) == NULL) {
        return NULL;
    }

    OF_LIST_QUEUE_PROP_ITER(src, &src_elt, rv) {
        if ((dst_elt = of_queue_prop_OF_VERSION_1_3_dup(&src_elt)) == NULL) {
            of_object_delete((of_object_t *)dst);
            return NULL;
        }
        _TRY_FREE(of_list_queue_prop_append(dst, dst_elt),
            dst, NULL);
        of_object_delete((of_object_t *)dst_elt);
    }

    return dst;
}

/**
 * Duplicate a list of type of_list_queue_stats_entry
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_list_queue_stats_entry.
 *
 * The caller is responsible for deleting the returned value
 */
of_list_queue_stats_entry_t *
of_list_queue_stats_entry_OF_VERSION_1_3_dup(
    of_list_queue_stats_entry_t *src)
{
    of_queue_stats_entry_t src_elt;
    of_queue_stats_entry_t *dst_elt;
    int rv;
    of_list_queue_stats_entry_t *dst;

    if ((dst = of_list_queue_stats_entry_new(src->version)) == NULL) {
        return NULL;
    }

    OF_LIST_QUEUE_STATS_ENTRY_ITER(src, &src_elt, rv) {
        if ((dst_elt = of_queue_stats_entry_OF_VERSION_1_3_dup(&src_elt)) == NULL) {
            of_object_delete((of_object_t *)dst);
            return NULL;
        }
        _TRY_FREE(of_list_queue_stats_entry_append(dst, dst_elt),
            dst, NULL);
        of_object_delete((of_object_t *)dst_elt);
    }

    return dst;
}

/**
 * Duplicate a list of type of_list_table_feature_prop
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_list_table_feature_prop.
 *
 * The caller is responsible for deleting the returned value
 */
of_list_table_feature_prop_t *
of_list_table_feature_prop_OF_VERSION_1_3_dup(
    of_list_table_feature_prop_t *src)
{
    of_table_feature_prop_t src_elt;
    of_table_feature_prop_t *dst_elt;
    int rv;
    of_list_table_feature_prop_t *dst;

    if ((dst = of_list_table_feature_prop_new(src->version)) == NULL) {
        return NULL;
    }

    OF_LIST_TABLE_FEATURE_PROP_ITER(src, &src_elt, rv) {
        if ((dst_elt = of_table_feature_prop_OF_VERSION_1_3_dup(&src_elt)) == NULL) {
            of_object_delete((of_object_t *)dst);
            return NULL;
        }
        _TRY_FREE(of_list_table_feature_prop_append(dst, dst_elt),
            dst, NULL);
        of_object_delete((of_object_t *)dst_elt);
    }

    return dst;
}

/**
 * Duplicate a list of type of_list_table_features
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_list_table_features.
 *
 * The caller is responsible for deleting the returned value
 */
of_list_table_features_t *
of_list_table_features_OF_VERSION_1_3_dup(
    of_list_table_features_t *src)
{
    of_table_features_t src_elt;
    of_table_features_t *dst_elt;
    int rv;
    of_list_table_features_t *dst;

    if ((dst = of_list_table_features_new(src->version)) == NULL) {
        return NULL;
    }

    OF_LIST_TABLE_FEATURES_ITER(src, &src_elt, rv) {
        if ((dst_elt = of_table_features_OF_VERSION_1_3_dup(&src_elt)) == NULL) {
            of_object_delete((of_object_t *)dst);
            return NULL;
        }
        _TRY_FREE(of_list_table_features_append(dst, dst_elt),
            dst, NULL);
        of_object_delete((of_object_t *)dst_elt);
    }

    return dst;
}

/**
 * Duplicate a list of type of_list_table_stats_entry
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_list_table_stats_entry.
 *
 * The caller is responsible for deleting the returned value
 */
of_list_table_stats_entry_t *
of_list_table_stats_entry_OF_VERSION_1_3_dup(
    of_list_table_stats_entry_t *src)
{
    of_table_stats_entry_t src_elt;
    of_table_stats_entry_t *dst_elt;
    int rv;
    of_list_table_stats_entry_t *dst;

    if ((dst = of_list_table_stats_entry_new(src->version)) == NULL) {
        return NULL;
    }

    OF_LIST_TABLE_STATS_ENTRY_ITER(src, &src_elt, rv) {
        if ((dst_elt = of_table_stats_entry_OF_VERSION_1_3_dup(&src_elt)) == NULL) {
            of_object_delete((of_object_t *)dst);
            return NULL;
        }
        _TRY_FREE(of_list_table_stats_entry_append(dst, dst_elt),
            dst, NULL);
        of_object_delete((of_object_t *)dst_elt);
    }

    return dst;
}

/**
 * Duplicate a list of type of_list_uint32
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_list_uint32.
 *
 * The caller is responsible for deleting the returned value
 */
of_list_uint32_t *
of_list_uint32_OF_VERSION_1_3_dup(
    of_list_uint32_t *src)
{
    of_uint32_t src_elt;
    of_uint32_t *dst_elt;
    int rv;
    of_list_uint32_t *dst;

    if ((dst = of_list_uint32_new(src->version)) == NULL) {
        return NULL;
    }

    OF_LIST_UINT32_ITER(src, &src_elt, rv) {
        if ((dst_elt = of_uint32_OF_VERSION_1_3_dup(&src_elt)) == NULL) {
            of_object_delete((of_object_t *)dst);
            return NULL;
        }
        _TRY_FREE(of_list_uint32_append(dst, dst_elt),
            dst, NULL);
        of_object_delete((of_object_t *)dst_elt);
    }

    return dst;
}

/**
 * Duplicate a list of type of_list_uint8
 * using accessor functions
 * @param src Pointer to object to be duplicated
 * @returns A new object of type of_list_uint8.
 *
 * The caller is responsible for deleting the returned value
 */
of_list_uint8_t *
of_list_uint8_OF_VERSION_1_3_dup(
    of_list_uint8_t *src)
{
    of_uint8_t src_elt;
    of_uint8_t *dst_elt;
    int rv;
    of_list_uint8_t *dst;

    if ((dst = of_list_uint8_new(src->version)) == NULL) {
        return NULL;
    }

    OF_LIST_UINT8_ITER(src, &src_elt, rv) {
        if ((dst_elt = of_uint8_OF_VERSION_1_3_dup(&src_elt)) == NULL) {
            of_object_delete((of_object_t *)dst);
            return NULL;
        }
        _TRY_FREE(of_list_uint8_append(dst, dst_elt),
            dst, NULL);
        of_object_delete((of_object_t *)dst_elt);
    }

    return dst;
}

of_aggregate_stats_reply_t *
of_aggregate_stats_reply_dup(
    of_aggregate_stats_reply_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_aggregate_stats_reply_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_aggregate_stats_reply_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_aggregate_stats_reply_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_aggregate_stats_reply_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_aggregate_stats_request_t *
of_aggregate_stats_request_dup(
    of_aggregate_stats_request_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_aggregate_stats_request_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_aggregate_stats_request_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_aggregate_stats_request_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_aggregate_stats_request_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_async_get_reply_t *
of_async_get_reply_dup(
    of_async_get_reply_t *src)
{

    if (src->version == OF_VERSION_1_3) {
        return of_async_get_reply_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_async_get_request_t *
of_async_get_request_dup(
    of_async_get_request_t *src)
{

    if (src->version == OF_VERSION_1_3) {
        return of_async_get_request_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_async_set_t *
of_async_set_dup(
    of_async_set_t *src)
{

    if (src->version == OF_VERSION_1_3) {
        return of_async_set_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_bad_action_error_msg_t *
of_bad_action_error_msg_dup(
    of_bad_action_error_msg_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_bad_action_error_msg_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_bad_action_error_msg_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_bad_action_error_msg_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_bad_action_error_msg_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_bad_instruction_error_msg_t *
of_bad_instruction_error_msg_dup(
    of_bad_instruction_error_msg_t *src)
{

    if (src->version == OF_VERSION_1_1) {
        return of_bad_instruction_error_msg_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_bad_instruction_error_msg_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_bad_instruction_error_msg_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_bad_match_error_msg_t *
of_bad_match_error_msg_dup(
    of_bad_match_error_msg_t *src)
{

    if (src->version == OF_VERSION_1_1) {
        return of_bad_match_error_msg_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_bad_match_error_msg_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_bad_match_error_msg_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_bad_request_error_msg_t *
of_bad_request_error_msg_dup(
    of_bad_request_error_msg_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_bad_request_error_msg_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_bad_request_error_msg_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_bad_request_error_msg_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_bad_request_error_msg_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_barrier_reply_t *
of_barrier_reply_dup(
    of_barrier_reply_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_barrier_reply_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_barrier_reply_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_barrier_reply_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_barrier_reply_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_barrier_request_t *
of_barrier_request_dup(
    of_barrier_request_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_barrier_request_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_barrier_request_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_barrier_request_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_barrier_request_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_bsn_bw_clear_data_reply_t *
of_bsn_bw_clear_data_reply_dup(
    of_bsn_bw_clear_data_reply_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_bsn_bw_clear_data_reply_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_bsn_bw_clear_data_reply_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_bsn_bw_clear_data_reply_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_bsn_bw_clear_data_reply_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_bsn_bw_clear_data_request_t *
of_bsn_bw_clear_data_request_dup(
    of_bsn_bw_clear_data_request_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_bsn_bw_clear_data_request_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_bsn_bw_clear_data_request_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_bsn_bw_clear_data_request_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_bsn_bw_clear_data_request_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_bsn_bw_enable_get_reply_t *
of_bsn_bw_enable_get_reply_dup(
    of_bsn_bw_enable_get_reply_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_bsn_bw_enable_get_reply_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_bsn_bw_enable_get_reply_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_bsn_bw_enable_get_reply_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_bsn_bw_enable_get_reply_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_bsn_bw_enable_get_request_t *
of_bsn_bw_enable_get_request_dup(
    of_bsn_bw_enable_get_request_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_bsn_bw_enable_get_request_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_bsn_bw_enable_get_request_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_bsn_bw_enable_get_request_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_bsn_bw_enable_get_request_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_bsn_bw_enable_set_reply_t *
of_bsn_bw_enable_set_reply_dup(
    of_bsn_bw_enable_set_reply_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_bsn_bw_enable_set_reply_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_bsn_bw_enable_set_reply_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_bsn_bw_enable_set_reply_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_bsn_bw_enable_set_reply_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_bsn_bw_enable_set_request_t *
of_bsn_bw_enable_set_request_dup(
    of_bsn_bw_enable_set_request_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_bsn_bw_enable_set_request_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_bsn_bw_enable_set_request_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_bsn_bw_enable_set_request_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_bsn_bw_enable_set_request_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_bsn_flow_idle_t *
of_bsn_flow_idle_dup(
    of_bsn_flow_idle_t *src)
{

    if (src->version == OF_VERSION_1_3) {
        return of_bsn_flow_idle_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_bsn_flow_idle_enable_get_reply_t *
of_bsn_flow_idle_enable_get_reply_dup(
    of_bsn_flow_idle_enable_get_reply_t *src)
{

    if (src->version == OF_VERSION_1_3) {
        return of_bsn_flow_idle_enable_get_reply_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_bsn_flow_idle_enable_get_request_t *
of_bsn_flow_idle_enable_get_request_dup(
    of_bsn_flow_idle_enable_get_request_t *src)
{

    if (src->version == OF_VERSION_1_3) {
        return of_bsn_flow_idle_enable_get_request_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_bsn_flow_idle_enable_set_reply_t *
of_bsn_flow_idle_enable_set_reply_dup(
    of_bsn_flow_idle_enable_set_reply_t *src)
{

    if (src->version == OF_VERSION_1_3) {
        return of_bsn_flow_idle_enable_set_reply_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_bsn_flow_idle_enable_set_request_t *
of_bsn_flow_idle_enable_set_request_dup(
    of_bsn_flow_idle_enable_set_request_t *src)
{

    if (src->version == OF_VERSION_1_3) {
        return of_bsn_flow_idle_enable_set_request_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_bsn_get_interfaces_reply_t *
of_bsn_get_interfaces_reply_dup(
    of_bsn_get_interfaces_reply_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_bsn_get_interfaces_reply_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_bsn_get_interfaces_reply_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_bsn_get_interfaces_reply_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_bsn_get_interfaces_reply_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_bsn_get_interfaces_request_t *
of_bsn_get_interfaces_request_dup(
    of_bsn_get_interfaces_request_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_bsn_get_interfaces_request_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_bsn_get_interfaces_request_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_bsn_get_interfaces_request_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_bsn_get_interfaces_request_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_bsn_get_ip_mask_reply_t *
of_bsn_get_ip_mask_reply_dup(
    of_bsn_get_ip_mask_reply_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_bsn_get_ip_mask_reply_OF_VERSION_1_0_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_bsn_get_ip_mask_request_t *
of_bsn_get_ip_mask_request_dup(
    of_bsn_get_ip_mask_request_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_bsn_get_ip_mask_request_OF_VERSION_1_0_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_bsn_get_l2_table_reply_t *
of_bsn_get_l2_table_reply_dup(
    of_bsn_get_l2_table_reply_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_bsn_get_l2_table_reply_OF_VERSION_1_0_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_bsn_get_l2_table_request_t *
of_bsn_get_l2_table_request_dup(
    of_bsn_get_l2_table_request_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_bsn_get_l2_table_request_OF_VERSION_1_0_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_bsn_get_mirroring_reply_t *
of_bsn_get_mirroring_reply_dup(
    of_bsn_get_mirroring_reply_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_bsn_get_mirroring_reply_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_bsn_get_mirroring_reply_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_bsn_get_mirroring_reply_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_bsn_get_mirroring_reply_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_bsn_get_mirroring_request_t *
of_bsn_get_mirroring_request_dup(
    of_bsn_get_mirroring_request_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_bsn_get_mirroring_request_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_bsn_get_mirroring_request_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_bsn_get_mirroring_request_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_bsn_get_mirroring_request_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_bsn_header_t *
of_bsn_header_dup(
    of_bsn_header_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_bsn_header_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_bsn_header_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_bsn_header_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_bsn_header_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_bsn_hybrid_get_reply_t *
of_bsn_hybrid_get_reply_dup(
    of_bsn_hybrid_get_reply_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_bsn_hybrid_get_reply_OF_VERSION_1_0_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_bsn_hybrid_get_request_t *
of_bsn_hybrid_get_request_dup(
    of_bsn_hybrid_get_request_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_bsn_hybrid_get_request_OF_VERSION_1_0_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_bsn_pdu_rx_reply_t *
of_bsn_pdu_rx_reply_dup(
    of_bsn_pdu_rx_reply_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_bsn_pdu_rx_reply_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_bsn_pdu_rx_reply_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_bsn_pdu_rx_reply_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_bsn_pdu_rx_reply_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_bsn_pdu_rx_request_t *
of_bsn_pdu_rx_request_dup(
    of_bsn_pdu_rx_request_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_bsn_pdu_rx_request_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_bsn_pdu_rx_request_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_bsn_pdu_rx_request_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_bsn_pdu_rx_request_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_bsn_pdu_rx_timeout_t *
of_bsn_pdu_rx_timeout_dup(
    of_bsn_pdu_rx_timeout_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_bsn_pdu_rx_timeout_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_bsn_pdu_rx_timeout_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_bsn_pdu_rx_timeout_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_bsn_pdu_rx_timeout_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_bsn_pdu_tx_reply_t *
of_bsn_pdu_tx_reply_dup(
    of_bsn_pdu_tx_reply_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_bsn_pdu_tx_reply_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_bsn_pdu_tx_reply_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_bsn_pdu_tx_reply_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_bsn_pdu_tx_reply_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_bsn_pdu_tx_request_t *
of_bsn_pdu_tx_request_dup(
    of_bsn_pdu_tx_request_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_bsn_pdu_tx_request_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_bsn_pdu_tx_request_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_bsn_pdu_tx_request_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_bsn_pdu_tx_request_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_bsn_set_ip_mask_t *
of_bsn_set_ip_mask_dup(
    of_bsn_set_ip_mask_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_bsn_set_ip_mask_OF_VERSION_1_0_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_bsn_set_l2_table_reply_t *
of_bsn_set_l2_table_reply_dup(
    of_bsn_set_l2_table_reply_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_bsn_set_l2_table_reply_OF_VERSION_1_0_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_bsn_set_l2_table_request_t *
of_bsn_set_l2_table_request_dup(
    of_bsn_set_l2_table_request_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_bsn_set_l2_table_request_OF_VERSION_1_0_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_bsn_set_mirroring_t *
of_bsn_set_mirroring_dup(
    of_bsn_set_mirroring_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_bsn_set_mirroring_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_bsn_set_mirroring_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_bsn_set_mirroring_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_bsn_set_mirroring_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_bsn_set_pktin_suppression_reply_t *
of_bsn_set_pktin_suppression_reply_dup(
    of_bsn_set_pktin_suppression_reply_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_bsn_set_pktin_suppression_reply_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_bsn_set_pktin_suppression_reply_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_bsn_set_pktin_suppression_reply_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_bsn_set_pktin_suppression_reply_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_bsn_set_pktin_suppression_request_t *
of_bsn_set_pktin_suppression_request_dup(
    of_bsn_set_pktin_suppression_request_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_bsn_set_pktin_suppression_request_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_bsn_set_pktin_suppression_request_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_bsn_set_pktin_suppression_request_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_bsn_set_pktin_suppression_request_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_bsn_shell_command_t *
of_bsn_shell_command_dup(
    of_bsn_shell_command_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_bsn_shell_command_OF_VERSION_1_0_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_bsn_shell_output_t *
of_bsn_shell_output_dup(
    of_bsn_shell_output_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_bsn_shell_output_OF_VERSION_1_0_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_bsn_shell_status_t *
of_bsn_shell_status_dup(
    of_bsn_shell_status_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_bsn_shell_status_OF_VERSION_1_0_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_bsn_virtual_port_create_reply_t *
of_bsn_virtual_port_create_reply_dup(
    of_bsn_virtual_port_create_reply_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_bsn_virtual_port_create_reply_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_bsn_virtual_port_create_reply_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_bsn_virtual_port_create_reply_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_bsn_virtual_port_create_reply_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_bsn_virtual_port_create_request_t *
of_bsn_virtual_port_create_request_dup(
    of_bsn_virtual_port_create_request_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_bsn_virtual_port_create_request_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_bsn_virtual_port_create_request_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_bsn_virtual_port_create_request_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_bsn_virtual_port_create_request_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_bsn_virtual_port_remove_reply_t *
of_bsn_virtual_port_remove_reply_dup(
    of_bsn_virtual_port_remove_reply_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_bsn_virtual_port_remove_reply_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_bsn_virtual_port_remove_reply_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_bsn_virtual_port_remove_reply_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_bsn_virtual_port_remove_reply_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_bsn_virtual_port_remove_request_t *
of_bsn_virtual_port_remove_request_dup(
    of_bsn_virtual_port_remove_request_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_bsn_virtual_port_remove_request_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_bsn_virtual_port_remove_request_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_bsn_virtual_port_remove_request_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_bsn_virtual_port_remove_request_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_desc_stats_reply_t *
of_desc_stats_reply_dup(
    of_desc_stats_reply_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_desc_stats_reply_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_desc_stats_reply_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_desc_stats_reply_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_desc_stats_reply_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_desc_stats_request_t *
of_desc_stats_request_dup(
    of_desc_stats_request_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_desc_stats_request_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_desc_stats_request_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_desc_stats_request_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_desc_stats_request_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_echo_reply_t *
of_echo_reply_dup(
    of_echo_reply_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_echo_reply_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_echo_reply_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_echo_reply_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_echo_reply_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_echo_request_t *
of_echo_request_dup(
    of_echo_request_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_echo_request_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_echo_request_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_echo_request_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_echo_request_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_error_msg_t *
of_error_msg_dup(
    of_error_msg_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_error_msg_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_error_msg_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_error_msg_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_error_msg_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_experimenter_t *
of_experimenter_dup(
    of_experimenter_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_experimenter_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_experimenter_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_experimenter_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_experimenter_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_experimenter_error_msg_t *
of_experimenter_error_msg_dup(
    of_experimenter_error_msg_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_experimenter_error_msg_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_experimenter_error_msg_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_experimenter_stats_reply_t *
of_experimenter_stats_reply_dup(
    of_experimenter_stats_reply_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_experimenter_stats_reply_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_experimenter_stats_reply_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_experimenter_stats_reply_OF_VERSION_1_2_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_experimenter_stats_request_t *
of_experimenter_stats_request_dup(
    of_experimenter_stats_request_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_experimenter_stats_request_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_experimenter_stats_request_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_experimenter_stats_request_OF_VERSION_1_2_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_features_reply_t *
of_features_reply_dup(
    of_features_reply_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_features_reply_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_features_reply_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_features_reply_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_features_reply_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_features_request_t *
of_features_request_dup(
    of_features_request_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_features_request_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_features_request_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_features_request_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_features_request_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_flow_add_t *
of_flow_add_dup(
    of_flow_add_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_flow_add_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_flow_add_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_flow_add_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_flow_add_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_flow_delete_t *
of_flow_delete_dup(
    of_flow_delete_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_flow_delete_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_flow_delete_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_flow_delete_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_flow_delete_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_flow_delete_strict_t *
of_flow_delete_strict_dup(
    of_flow_delete_strict_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_flow_delete_strict_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_flow_delete_strict_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_flow_delete_strict_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_flow_delete_strict_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_flow_mod_t *
of_flow_mod_dup(
    of_flow_mod_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_flow_mod_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_flow_mod_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_flow_mod_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_flow_mod_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_flow_mod_failed_error_msg_t *
of_flow_mod_failed_error_msg_dup(
    of_flow_mod_failed_error_msg_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_flow_mod_failed_error_msg_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_flow_mod_failed_error_msg_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_flow_mod_failed_error_msg_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_flow_mod_failed_error_msg_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_flow_modify_t *
of_flow_modify_dup(
    of_flow_modify_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_flow_modify_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_flow_modify_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_flow_modify_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_flow_modify_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_flow_modify_strict_t *
of_flow_modify_strict_dup(
    of_flow_modify_strict_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_flow_modify_strict_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_flow_modify_strict_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_flow_modify_strict_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_flow_modify_strict_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_flow_removed_t *
of_flow_removed_dup(
    of_flow_removed_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_flow_removed_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_flow_removed_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_flow_removed_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_flow_removed_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_flow_stats_reply_t *
of_flow_stats_reply_dup(
    of_flow_stats_reply_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_flow_stats_reply_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_flow_stats_reply_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_flow_stats_reply_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_flow_stats_reply_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_flow_stats_request_t *
of_flow_stats_request_dup(
    of_flow_stats_request_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_flow_stats_request_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_flow_stats_request_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_flow_stats_request_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_flow_stats_request_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_get_config_reply_t *
of_get_config_reply_dup(
    of_get_config_reply_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_get_config_reply_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_get_config_reply_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_get_config_reply_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_get_config_reply_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_get_config_request_t *
of_get_config_request_dup(
    of_get_config_request_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_get_config_request_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_get_config_request_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_get_config_request_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_get_config_request_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_group_desc_stats_reply_t *
of_group_desc_stats_reply_dup(
    of_group_desc_stats_reply_t *src)
{

    if (src->version == OF_VERSION_1_1) {
        return of_group_desc_stats_reply_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_group_desc_stats_reply_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_group_desc_stats_reply_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_group_desc_stats_request_t *
of_group_desc_stats_request_dup(
    of_group_desc_stats_request_t *src)
{

    if (src->version == OF_VERSION_1_1) {
        return of_group_desc_stats_request_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_group_desc_stats_request_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_group_desc_stats_request_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_group_features_stats_reply_t *
of_group_features_stats_reply_dup(
    of_group_features_stats_reply_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_group_features_stats_reply_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_group_features_stats_reply_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_group_features_stats_request_t *
of_group_features_stats_request_dup(
    of_group_features_stats_request_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_group_features_stats_request_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_group_features_stats_request_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_group_mod_t *
of_group_mod_dup(
    of_group_mod_t *src)
{

    if (src->version == OF_VERSION_1_1) {
        return of_group_mod_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_group_mod_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_group_mod_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_group_mod_failed_error_msg_t *
of_group_mod_failed_error_msg_dup(
    of_group_mod_failed_error_msg_t *src)
{

    if (src->version == OF_VERSION_1_1) {
        return of_group_mod_failed_error_msg_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_group_mod_failed_error_msg_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_group_mod_failed_error_msg_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_group_stats_reply_t *
of_group_stats_reply_dup(
    of_group_stats_reply_t *src)
{

    if (src->version == OF_VERSION_1_1) {
        return of_group_stats_reply_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_group_stats_reply_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_group_stats_reply_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_group_stats_request_t *
of_group_stats_request_dup(
    of_group_stats_request_t *src)
{

    if (src->version == OF_VERSION_1_1) {
        return of_group_stats_request_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_group_stats_request_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_group_stats_request_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_hello_t *
of_hello_dup(
    of_hello_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_hello_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_hello_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_hello_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_hello_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_hello_failed_error_msg_t *
of_hello_failed_error_msg_dup(
    of_hello_failed_error_msg_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_hello_failed_error_msg_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_hello_failed_error_msg_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_hello_failed_error_msg_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_hello_failed_error_msg_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_meter_config_stats_reply_t *
of_meter_config_stats_reply_dup(
    of_meter_config_stats_reply_t *src)
{

    if (src->version == OF_VERSION_1_3) {
        return of_meter_config_stats_reply_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_meter_config_stats_request_t *
of_meter_config_stats_request_dup(
    of_meter_config_stats_request_t *src)
{

    if (src->version == OF_VERSION_1_3) {
        return of_meter_config_stats_request_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_meter_features_stats_reply_t *
of_meter_features_stats_reply_dup(
    of_meter_features_stats_reply_t *src)
{

    if (src->version == OF_VERSION_1_3) {
        return of_meter_features_stats_reply_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_meter_features_stats_request_t *
of_meter_features_stats_request_dup(
    of_meter_features_stats_request_t *src)
{

    if (src->version == OF_VERSION_1_3) {
        return of_meter_features_stats_request_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_meter_mod_t *
of_meter_mod_dup(
    of_meter_mod_t *src)
{

    if (src->version == OF_VERSION_1_3) {
        return of_meter_mod_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_meter_mod_failed_error_msg_t *
of_meter_mod_failed_error_msg_dup(
    of_meter_mod_failed_error_msg_t *src)
{

    if (src->version == OF_VERSION_1_3) {
        return of_meter_mod_failed_error_msg_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_meter_stats_reply_t *
of_meter_stats_reply_dup(
    of_meter_stats_reply_t *src)
{

    if (src->version == OF_VERSION_1_3) {
        return of_meter_stats_reply_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_meter_stats_request_t *
of_meter_stats_request_dup(
    of_meter_stats_request_t *src)
{

    if (src->version == OF_VERSION_1_3) {
        return of_meter_stats_request_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_nicira_controller_role_reply_t *
of_nicira_controller_role_reply_dup(
    of_nicira_controller_role_reply_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_nicira_controller_role_reply_OF_VERSION_1_0_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_nicira_controller_role_request_t *
of_nicira_controller_role_request_dup(
    of_nicira_controller_role_request_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_nicira_controller_role_request_OF_VERSION_1_0_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_nicira_header_t *
of_nicira_header_dup(
    of_nicira_header_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_nicira_header_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_nicira_header_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_nicira_header_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_nicira_header_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_packet_in_t *
of_packet_in_dup(
    of_packet_in_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_packet_in_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_packet_in_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_packet_in_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_packet_in_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_packet_out_t *
of_packet_out_dup(
    of_packet_out_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_packet_out_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_packet_out_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_packet_out_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_packet_out_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_port_desc_stats_reply_t *
of_port_desc_stats_reply_dup(
    of_port_desc_stats_reply_t *src)
{

    if (src->version == OF_VERSION_1_3) {
        return of_port_desc_stats_reply_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_port_desc_stats_request_t *
of_port_desc_stats_request_dup(
    of_port_desc_stats_request_t *src)
{

    if (src->version == OF_VERSION_1_3) {
        return of_port_desc_stats_request_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_port_mod_t *
of_port_mod_dup(
    of_port_mod_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_port_mod_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_port_mod_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_port_mod_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_port_mod_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_port_mod_failed_error_msg_t *
of_port_mod_failed_error_msg_dup(
    of_port_mod_failed_error_msg_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_port_mod_failed_error_msg_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_port_mod_failed_error_msg_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_port_mod_failed_error_msg_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_port_mod_failed_error_msg_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_port_stats_reply_t *
of_port_stats_reply_dup(
    of_port_stats_reply_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_port_stats_reply_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_port_stats_reply_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_port_stats_reply_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_port_stats_reply_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_port_stats_request_t *
of_port_stats_request_dup(
    of_port_stats_request_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_port_stats_request_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_port_stats_request_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_port_stats_request_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_port_stats_request_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_port_status_t *
of_port_status_dup(
    of_port_status_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_port_status_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_port_status_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_port_status_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_port_status_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_queue_get_config_reply_t *
of_queue_get_config_reply_dup(
    of_queue_get_config_reply_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_queue_get_config_reply_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_queue_get_config_reply_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_queue_get_config_reply_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_queue_get_config_reply_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_queue_get_config_request_t *
of_queue_get_config_request_dup(
    of_queue_get_config_request_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_queue_get_config_request_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_queue_get_config_request_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_queue_get_config_request_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_queue_get_config_request_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_queue_op_failed_error_msg_t *
of_queue_op_failed_error_msg_dup(
    of_queue_op_failed_error_msg_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_queue_op_failed_error_msg_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_queue_op_failed_error_msg_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_queue_op_failed_error_msg_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_queue_op_failed_error_msg_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_queue_stats_reply_t *
of_queue_stats_reply_dup(
    of_queue_stats_reply_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_queue_stats_reply_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_queue_stats_reply_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_queue_stats_reply_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_queue_stats_reply_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_queue_stats_request_t *
of_queue_stats_request_dup(
    of_queue_stats_request_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_queue_stats_request_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_queue_stats_request_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_queue_stats_request_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_queue_stats_request_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_role_reply_t *
of_role_reply_dup(
    of_role_reply_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_role_reply_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_role_reply_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_role_request_t *
of_role_request_dup(
    of_role_request_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_role_request_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_role_request_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_role_request_failed_error_msg_t *
of_role_request_failed_error_msg_dup(
    of_role_request_failed_error_msg_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_role_request_failed_error_msg_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_role_request_failed_error_msg_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_set_config_t *
of_set_config_dup(
    of_set_config_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_set_config_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_set_config_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_set_config_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_set_config_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_stats_reply_t *
of_stats_reply_dup(
    of_stats_reply_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_stats_reply_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_stats_reply_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_stats_reply_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_stats_reply_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_stats_request_t *
of_stats_request_dup(
    of_stats_request_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_stats_request_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_stats_request_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_stats_request_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_stats_request_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_switch_config_failed_error_msg_t *
of_switch_config_failed_error_msg_dup(
    of_switch_config_failed_error_msg_t *src)
{

    if (src->version == OF_VERSION_1_1) {
        return of_switch_config_failed_error_msg_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_switch_config_failed_error_msg_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_switch_config_failed_error_msg_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_table_features_failed_error_msg_t *
of_table_features_failed_error_msg_dup(
    of_table_features_failed_error_msg_t *src)
{

    if (src->version == OF_VERSION_1_3) {
        return of_table_features_failed_error_msg_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_table_features_stats_reply_t *
of_table_features_stats_reply_dup(
    of_table_features_stats_reply_t *src)
{

    if (src->version == OF_VERSION_1_3) {
        return of_table_features_stats_reply_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_table_features_stats_request_t *
of_table_features_stats_request_dup(
    of_table_features_stats_request_t *src)
{

    if (src->version == OF_VERSION_1_3) {
        return of_table_features_stats_request_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_table_mod_t *
of_table_mod_dup(
    of_table_mod_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_table_mod_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_table_mod_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_table_mod_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_table_mod_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_table_mod_failed_error_msg_t *
of_table_mod_failed_error_msg_dup(
    of_table_mod_failed_error_msg_t *src)
{

    if (src->version == OF_VERSION_1_1) {
        return of_table_mod_failed_error_msg_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_table_mod_failed_error_msg_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_table_mod_failed_error_msg_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_table_stats_reply_t *
of_table_stats_reply_dup(
    of_table_stats_reply_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_table_stats_reply_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_table_stats_reply_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_table_stats_reply_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_table_stats_reply_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_table_stats_request_t *
of_table_stats_request_dup(
    of_table_stats_request_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_table_stats_request_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_table_stats_request_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_table_stats_request_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_table_stats_request_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_action_t *
of_action_dup(
    of_action_t *src)
{

    if (src->header.version == OF_VERSION_1_0) {
        return of_action_OF_VERSION_1_0_dup(src);
    }

    if (src->header.version == OF_VERSION_1_1) {
        return of_action_OF_VERSION_1_1_dup(src);
    }

    if (src->header.version == OF_VERSION_1_2) {
        return of_action_OF_VERSION_1_2_dup(src);
    }

    if (src->header.version == OF_VERSION_1_3) {
        return of_action_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_action_bsn_t *
of_action_bsn_dup(
    of_action_bsn_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_action_bsn_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_action_bsn_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_action_bsn_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_action_bsn_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_action_bsn_mirror_t *
of_action_bsn_mirror_dup(
    of_action_bsn_mirror_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_action_bsn_mirror_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_action_bsn_mirror_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_action_bsn_mirror_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_action_bsn_mirror_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_action_bsn_set_tunnel_dst_t *
of_action_bsn_set_tunnel_dst_dup(
    of_action_bsn_set_tunnel_dst_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_action_bsn_set_tunnel_dst_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_action_bsn_set_tunnel_dst_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_action_bsn_set_tunnel_dst_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_action_bsn_set_tunnel_dst_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_action_copy_ttl_in_t *
of_action_copy_ttl_in_dup(
    of_action_copy_ttl_in_t *src)
{

    if (src->version == OF_VERSION_1_1) {
        return of_action_copy_ttl_in_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_action_copy_ttl_in_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_action_copy_ttl_in_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_action_copy_ttl_out_t *
of_action_copy_ttl_out_dup(
    of_action_copy_ttl_out_t *src)
{

    if (src->version == OF_VERSION_1_1) {
        return of_action_copy_ttl_out_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_action_copy_ttl_out_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_action_copy_ttl_out_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_action_dec_mpls_ttl_t *
of_action_dec_mpls_ttl_dup(
    of_action_dec_mpls_ttl_t *src)
{

    if (src->version == OF_VERSION_1_1) {
        return of_action_dec_mpls_ttl_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_action_dec_mpls_ttl_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_action_dec_mpls_ttl_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_action_dec_nw_ttl_t *
of_action_dec_nw_ttl_dup(
    of_action_dec_nw_ttl_t *src)
{

    if (src->version == OF_VERSION_1_1) {
        return of_action_dec_nw_ttl_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_action_dec_nw_ttl_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_action_dec_nw_ttl_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_action_enqueue_t *
of_action_enqueue_dup(
    of_action_enqueue_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_action_enqueue_OF_VERSION_1_0_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_action_experimenter_t *
of_action_experimenter_dup(
    of_action_experimenter_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_action_experimenter_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_action_experimenter_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_action_experimenter_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_action_experimenter_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_action_group_t *
of_action_group_dup(
    of_action_group_t *src)
{

    if (src->version == OF_VERSION_1_1) {
        return of_action_group_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_action_group_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_action_group_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_action_header_t *
of_action_header_dup(
    of_action_header_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_action_header_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_action_header_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_action_header_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_action_header_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_action_id_t *
of_action_id_dup(
    of_action_id_t *src)
{

    if (src->header.version == OF_VERSION_1_3) {
        return of_action_id_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_action_id_bsn_t *
of_action_id_bsn_dup(
    of_action_id_bsn_t *src)
{

    if (src->version == OF_VERSION_1_3) {
        return of_action_id_bsn_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_action_id_bsn_mirror_t *
of_action_id_bsn_mirror_dup(
    of_action_id_bsn_mirror_t *src)
{

    if (src->version == OF_VERSION_1_3) {
        return of_action_id_bsn_mirror_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_action_id_bsn_set_tunnel_dst_t *
of_action_id_bsn_set_tunnel_dst_dup(
    of_action_id_bsn_set_tunnel_dst_t *src)
{

    if (src->version == OF_VERSION_1_3) {
        return of_action_id_bsn_set_tunnel_dst_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_action_id_copy_ttl_in_t *
of_action_id_copy_ttl_in_dup(
    of_action_id_copy_ttl_in_t *src)
{

    if (src->version == OF_VERSION_1_3) {
        return of_action_id_copy_ttl_in_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_action_id_copy_ttl_out_t *
of_action_id_copy_ttl_out_dup(
    of_action_id_copy_ttl_out_t *src)
{

    if (src->version == OF_VERSION_1_3) {
        return of_action_id_copy_ttl_out_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_action_id_dec_mpls_ttl_t *
of_action_id_dec_mpls_ttl_dup(
    of_action_id_dec_mpls_ttl_t *src)
{

    if (src->version == OF_VERSION_1_3) {
        return of_action_id_dec_mpls_ttl_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_action_id_dec_nw_ttl_t *
of_action_id_dec_nw_ttl_dup(
    of_action_id_dec_nw_ttl_t *src)
{

    if (src->version == OF_VERSION_1_3) {
        return of_action_id_dec_nw_ttl_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_action_id_experimenter_t *
of_action_id_experimenter_dup(
    of_action_id_experimenter_t *src)
{

    if (src->version == OF_VERSION_1_3) {
        return of_action_id_experimenter_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_action_id_group_t *
of_action_id_group_dup(
    of_action_id_group_t *src)
{

    if (src->version == OF_VERSION_1_3) {
        return of_action_id_group_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_action_id_header_t *
of_action_id_header_dup(
    of_action_id_header_t *src)
{

    if (src->version == OF_VERSION_1_3) {
        return of_action_id_header_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_action_id_nicira_t *
of_action_id_nicira_dup(
    of_action_id_nicira_t *src)
{

    if (src->version == OF_VERSION_1_3) {
        return of_action_id_nicira_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_action_id_nicira_dec_ttl_t *
of_action_id_nicira_dec_ttl_dup(
    of_action_id_nicira_dec_ttl_t *src)
{

    if (src->version == OF_VERSION_1_3) {
        return of_action_id_nicira_dec_ttl_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_action_id_output_t *
of_action_id_output_dup(
    of_action_id_output_t *src)
{

    if (src->version == OF_VERSION_1_3) {
        return of_action_id_output_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_action_id_pop_mpls_t *
of_action_id_pop_mpls_dup(
    of_action_id_pop_mpls_t *src)
{

    if (src->version == OF_VERSION_1_3) {
        return of_action_id_pop_mpls_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_action_id_pop_pbb_t *
of_action_id_pop_pbb_dup(
    of_action_id_pop_pbb_t *src)
{

    if (src->version == OF_VERSION_1_3) {
        return of_action_id_pop_pbb_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_action_id_pop_vlan_t *
of_action_id_pop_vlan_dup(
    of_action_id_pop_vlan_t *src)
{

    if (src->version == OF_VERSION_1_3) {
        return of_action_id_pop_vlan_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_action_id_push_mpls_t *
of_action_id_push_mpls_dup(
    of_action_id_push_mpls_t *src)
{

    if (src->version == OF_VERSION_1_3) {
        return of_action_id_push_mpls_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_action_id_push_pbb_t *
of_action_id_push_pbb_dup(
    of_action_id_push_pbb_t *src)
{

    if (src->version == OF_VERSION_1_3) {
        return of_action_id_push_pbb_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_action_id_push_vlan_t *
of_action_id_push_vlan_dup(
    of_action_id_push_vlan_t *src)
{

    if (src->version == OF_VERSION_1_3) {
        return of_action_id_push_vlan_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_action_id_set_field_t *
of_action_id_set_field_dup(
    of_action_id_set_field_t *src)
{

    if (src->version == OF_VERSION_1_3) {
        return of_action_id_set_field_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_action_id_set_mpls_ttl_t *
of_action_id_set_mpls_ttl_dup(
    of_action_id_set_mpls_ttl_t *src)
{

    if (src->version == OF_VERSION_1_3) {
        return of_action_id_set_mpls_ttl_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_action_id_set_nw_ttl_t *
of_action_id_set_nw_ttl_dup(
    of_action_id_set_nw_ttl_t *src)
{

    if (src->version == OF_VERSION_1_3) {
        return of_action_id_set_nw_ttl_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_action_id_set_queue_t *
of_action_id_set_queue_dup(
    of_action_id_set_queue_t *src)
{

    if (src->version == OF_VERSION_1_3) {
        return of_action_id_set_queue_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_action_nicira_t *
of_action_nicira_dup(
    of_action_nicira_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_action_nicira_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_action_nicira_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_action_nicira_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_action_nicira_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_action_nicira_dec_ttl_t *
of_action_nicira_dec_ttl_dup(
    of_action_nicira_dec_ttl_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_action_nicira_dec_ttl_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_action_nicira_dec_ttl_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_action_nicira_dec_ttl_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_action_nicira_dec_ttl_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_action_output_t *
of_action_output_dup(
    of_action_output_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_action_output_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_action_output_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_action_output_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_action_output_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_action_pop_mpls_t *
of_action_pop_mpls_dup(
    of_action_pop_mpls_t *src)
{

    if (src->version == OF_VERSION_1_1) {
        return of_action_pop_mpls_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_action_pop_mpls_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_action_pop_mpls_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_action_pop_pbb_t *
of_action_pop_pbb_dup(
    of_action_pop_pbb_t *src)
{

    if (src->version == OF_VERSION_1_3) {
        return of_action_pop_pbb_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_action_pop_vlan_t *
of_action_pop_vlan_dup(
    of_action_pop_vlan_t *src)
{

    if (src->version == OF_VERSION_1_1) {
        return of_action_pop_vlan_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_action_pop_vlan_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_action_pop_vlan_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_action_push_mpls_t *
of_action_push_mpls_dup(
    of_action_push_mpls_t *src)
{

    if (src->version == OF_VERSION_1_1) {
        return of_action_push_mpls_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_action_push_mpls_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_action_push_mpls_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_action_push_pbb_t *
of_action_push_pbb_dup(
    of_action_push_pbb_t *src)
{

    if (src->version == OF_VERSION_1_3) {
        return of_action_push_pbb_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_action_push_vlan_t *
of_action_push_vlan_dup(
    of_action_push_vlan_t *src)
{

    if (src->version == OF_VERSION_1_1) {
        return of_action_push_vlan_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_action_push_vlan_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_action_push_vlan_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_action_set_dl_dst_t *
of_action_set_dl_dst_dup(
    of_action_set_dl_dst_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_action_set_dl_dst_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_action_set_dl_dst_OF_VERSION_1_1_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_action_set_dl_src_t *
of_action_set_dl_src_dup(
    of_action_set_dl_src_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_action_set_dl_src_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_action_set_dl_src_OF_VERSION_1_1_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_action_set_field_t *
of_action_set_field_dup(
    of_action_set_field_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_action_set_field_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_action_set_field_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_action_set_mpls_label_t *
of_action_set_mpls_label_dup(
    of_action_set_mpls_label_t *src)
{

    if (src->version == OF_VERSION_1_1) {
        return of_action_set_mpls_label_OF_VERSION_1_1_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_action_set_mpls_tc_t *
of_action_set_mpls_tc_dup(
    of_action_set_mpls_tc_t *src)
{

    if (src->version == OF_VERSION_1_1) {
        return of_action_set_mpls_tc_OF_VERSION_1_1_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_action_set_mpls_ttl_t *
of_action_set_mpls_ttl_dup(
    of_action_set_mpls_ttl_t *src)
{

    if (src->version == OF_VERSION_1_1) {
        return of_action_set_mpls_ttl_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_action_set_mpls_ttl_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_action_set_mpls_ttl_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_action_set_nw_dst_t *
of_action_set_nw_dst_dup(
    of_action_set_nw_dst_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_action_set_nw_dst_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_action_set_nw_dst_OF_VERSION_1_1_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_action_set_nw_ecn_t *
of_action_set_nw_ecn_dup(
    of_action_set_nw_ecn_t *src)
{

    if (src->version == OF_VERSION_1_1) {
        return of_action_set_nw_ecn_OF_VERSION_1_1_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_action_set_nw_src_t *
of_action_set_nw_src_dup(
    of_action_set_nw_src_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_action_set_nw_src_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_action_set_nw_src_OF_VERSION_1_1_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_action_set_nw_tos_t *
of_action_set_nw_tos_dup(
    of_action_set_nw_tos_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_action_set_nw_tos_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_action_set_nw_tos_OF_VERSION_1_1_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_action_set_nw_ttl_t *
of_action_set_nw_ttl_dup(
    of_action_set_nw_ttl_t *src)
{

    if (src->version == OF_VERSION_1_1) {
        return of_action_set_nw_ttl_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_action_set_nw_ttl_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_action_set_nw_ttl_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_action_set_queue_t *
of_action_set_queue_dup(
    of_action_set_queue_t *src)
{

    if (src->version == OF_VERSION_1_1) {
        return of_action_set_queue_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_action_set_queue_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_action_set_queue_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_action_set_tp_dst_t *
of_action_set_tp_dst_dup(
    of_action_set_tp_dst_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_action_set_tp_dst_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_action_set_tp_dst_OF_VERSION_1_1_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_action_set_tp_src_t *
of_action_set_tp_src_dup(
    of_action_set_tp_src_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_action_set_tp_src_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_action_set_tp_src_OF_VERSION_1_1_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_action_set_vlan_pcp_t *
of_action_set_vlan_pcp_dup(
    of_action_set_vlan_pcp_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_action_set_vlan_pcp_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_action_set_vlan_pcp_OF_VERSION_1_1_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_action_set_vlan_vid_t *
of_action_set_vlan_vid_dup(
    of_action_set_vlan_vid_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_action_set_vlan_vid_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_action_set_vlan_vid_OF_VERSION_1_1_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_action_strip_vlan_t *
of_action_strip_vlan_dup(
    of_action_strip_vlan_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_action_strip_vlan_OF_VERSION_1_0_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_bsn_interface_t *
of_bsn_interface_dup(
    of_bsn_interface_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_bsn_interface_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_bsn_interface_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_bsn_interface_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_bsn_interface_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_bsn_vport_t *
of_bsn_vport_dup(
    of_bsn_vport_t *src)
{

    if (src->header.version == OF_VERSION_1_0) {
        return of_bsn_vport_OF_VERSION_1_0_dup(src);
    }

    if (src->header.version == OF_VERSION_1_1) {
        return of_bsn_vport_OF_VERSION_1_1_dup(src);
    }

    if (src->header.version == OF_VERSION_1_2) {
        return of_bsn_vport_OF_VERSION_1_2_dup(src);
    }

    if (src->header.version == OF_VERSION_1_3) {
        return of_bsn_vport_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_bsn_vport_header_t *
of_bsn_vport_header_dup(
    of_bsn_vport_header_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_bsn_vport_header_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_bsn_vport_header_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_bsn_vport_header_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_bsn_vport_header_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_bsn_vport_q_in_q_t *
of_bsn_vport_q_in_q_dup(
    of_bsn_vport_q_in_q_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_bsn_vport_q_in_q_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_bsn_vport_q_in_q_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_bsn_vport_q_in_q_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_bsn_vport_q_in_q_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_bucket_t *
of_bucket_dup(
    of_bucket_t *src)
{

    if (src->version == OF_VERSION_1_1) {
        return of_bucket_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_bucket_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_bucket_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_bucket_counter_t *
of_bucket_counter_dup(
    of_bucket_counter_t *src)
{

    if (src->version == OF_VERSION_1_1) {
        return of_bucket_counter_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_bucket_counter_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_bucket_counter_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_experimenter_stats_header_t *
of_experimenter_stats_header_dup(
    of_experimenter_stats_header_t *src)
{

    if (src->version == OF_VERSION_1_3) {
        return of_experimenter_stats_header_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_flow_stats_entry_t *
of_flow_stats_entry_dup(
    of_flow_stats_entry_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_flow_stats_entry_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_flow_stats_entry_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_flow_stats_entry_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_flow_stats_entry_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_group_desc_stats_entry_t *
of_group_desc_stats_entry_dup(
    of_group_desc_stats_entry_t *src)
{

    if (src->version == OF_VERSION_1_1) {
        return of_group_desc_stats_entry_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_group_desc_stats_entry_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_group_desc_stats_entry_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_group_stats_entry_t *
of_group_stats_entry_dup(
    of_group_stats_entry_t *src)
{

    if (src->version == OF_VERSION_1_1) {
        return of_group_stats_entry_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_group_stats_entry_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_group_stats_entry_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_header_t *
of_header_dup(
    of_header_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_header_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_header_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_header_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_header_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_hello_elem_t *
of_hello_elem_dup(
    of_hello_elem_t *src)
{

    if (src->header.version == OF_VERSION_1_3) {
        return of_hello_elem_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_hello_elem_header_t *
of_hello_elem_header_dup(
    of_hello_elem_header_t *src)
{

    if (src->version == OF_VERSION_1_3) {
        return of_hello_elem_header_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_hello_elem_versionbitmap_t *
of_hello_elem_versionbitmap_dup(
    of_hello_elem_versionbitmap_t *src)
{

    if (src->version == OF_VERSION_1_3) {
        return of_hello_elem_versionbitmap_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_instruction_t *
of_instruction_dup(
    of_instruction_t *src)
{

    if (src->header.version == OF_VERSION_1_1) {
        return of_instruction_OF_VERSION_1_1_dup(src);
    }

    if (src->header.version == OF_VERSION_1_2) {
        return of_instruction_OF_VERSION_1_2_dup(src);
    }

    if (src->header.version == OF_VERSION_1_3) {
        return of_instruction_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_instruction_apply_actions_t *
of_instruction_apply_actions_dup(
    of_instruction_apply_actions_t *src)
{

    if (src->version == OF_VERSION_1_1) {
        return of_instruction_apply_actions_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_instruction_apply_actions_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_instruction_apply_actions_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_instruction_clear_actions_t *
of_instruction_clear_actions_dup(
    of_instruction_clear_actions_t *src)
{

    if (src->version == OF_VERSION_1_1) {
        return of_instruction_clear_actions_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_instruction_clear_actions_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_instruction_clear_actions_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_instruction_experimenter_t *
of_instruction_experimenter_dup(
    of_instruction_experimenter_t *src)
{

    if (src->version == OF_VERSION_1_1) {
        return of_instruction_experimenter_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_instruction_experimenter_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_instruction_experimenter_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_instruction_goto_table_t *
of_instruction_goto_table_dup(
    of_instruction_goto_table_t *src)
{

    if (src->version == OF_VERSION_1_1) {
        return of_instruction_goto_table_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_instruction_goto_table_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_instruction_goto_table_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_instruction_header_t *
of_instruction_header_dup(
    of_instruction_header_t *src)
{

    if (src->version == OF_VERSION_1_1) {
        return of_instruction_header_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_instruction_header_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_instruction_header_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_instruction_meter_t *
of_instruction_meter_dup(
    of_instruction_meter_t *src)
{

    if (src->version == OF_VERSION_1_3) {
        return of_instruction_meter_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_instruction_write_actions_t *
of_instruction_write_actions_dup(
    of_instruction_write_actions_t *src)
{

    if (src->version == OF_VERSION_1_1) {
        return of_instruction_write_actions_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_instruction_write_actions_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_instruction_write_actions_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_instruction_write_metadata_t *
of_instruction_write_metadata_dup(
    of_instruction_write_metadata_t *src)
{

    if (src->version == OF_VERSION_1_1) {
        return of_instruction_write_metadata_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_instruction_write_metadata_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_instruction_write_metadata_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_match_v1_t *
of_match_v1_dup(
    of_match_v1_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_match_v1_OF_VERSION_1_0_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_match_v2_t *
of_match_v2_dup(
    of_match_v2_t *src)
{

    if (src->version == OF_VERSION_1_1) {
        return of_match_v2_OF_VERSION_1_1_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_match_v3_t *
of_match_v3_dup(
    of_match_v3_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_match_v3_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_match_v3_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_meter_band_t *
of_meter_band_dup(
    of_meter_band_t *src)
{

    if (src->header.version == OF_VERSION_1_3) {
        return of_meter_band_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_meter_band_drop_t *
of_meter_band_drop_dup(
    of_meter_band_drop_t *src)
{

    if (src->version == OF_VERSION_1_3) {
        return of_meter_band_drop_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_meter_band_dscp_remark_t *
of_meter_band_dscp_remark_dup(
    of_meter_band_dscp_remark_t *src)
{

    if (src->version == OF_VERSION_1_3) {
        return of_meter_band_dscp_remark_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_meter_band_experimenter_t *
of_meter_band_experimenter_dup(
    of_meter_band_experimenter_t *src)
{

    if (src->version == OF_VERSION_1_3) {
        return of_meter_band_experimenter_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_meter_band_header_t *
of_meter_band_header_dup(
    of_meter_band_header_t *src)
{

    if (src->version == OF_VERSION_1_3) {
        return of_meter_band_header_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_meter_band_stats_t *
of_meter_band_stats_dup(
    of_meter_band_stats_t *src)
{

    if (src->version == OF_VERSION_1_3) {
        return of_meter_band_stats_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_meter_config_t *
of_meter_config_dup(
    of_meter_config_t *src)
{

    if (src->version == OF_VERSION_1_3) {
        return of_meter_config_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_meter_features_t *
of_meter_features_dup(
    of_meter_features_t *src)
{

    if (src->version == OF_VERSION_1_3) {
        return of_meter_features_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_meter_stats_t *
of_meter_stats_dup(
    of_meter_stats_t *src)
{

    if (src->version == OF_VERSION_1_3) {
        return of_meter_stats_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_t *
of_oxm_dup(
    of_oxm_t *src)
{

    if (src->header.version == OF_VERSION_1_2) {
        return of_oxm_OF_VERSION_1_2_dup(src);
    }

    if (src->header.version == OF_VERSION_1_3) {
        return of_oxm_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_arp_op_t *
of_oxm_arp_op_dup(
    of_oxm_arp_op_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_arp_op_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_arp_op_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_arp_op_masked_t *
of_oxm_arp_op_masked_dup(
    of_oxm_arp_op_masked_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_arp_op_masked_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_arp_op_masked_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_arp_sha_t *
of_oxm_arp_sha_dup(
    of_oxm_arp_sha_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_arp_sha_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_arp_sha_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_arp_sha_masked_t *
of_oxm_arp_sha_masked_dup(
    of_oxm_arp_sha_masked_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_arp_sha_masked_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_arp_sha_masked_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_arp_spa_t *
of_oxm_arp_spa_dup(
    of_oxm_arp_spa_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_arp_spa_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_arp_spa_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_arp_spa_masked_t *
of_oxm_arp_spa_masked_dup(
    of_oxm_arp_spa_masked_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_arp_spa_masked_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_arp_spa_masked_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_arp_tha_t *
of_oxm_arp_tha_dup(
    of_oxm_arp_tha_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_arp_tha_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_arp_tha_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_arp_tha_masked_t *
of_oxm_arp_tha_masked_dup(
    of_oxm_arp_tha_masked_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_arp_tha_masked_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_arp_tha_masked_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_arp_tpa_t *
of_oxm_arp_tpa_dup(
    of_oxm_arp_tpa_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_arp_tpa_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_arp_tpa_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_arp_tpa_masked_t *
of_oxm_arp_tpa_masked_dup(
    of_oxm_arp_tpa_masked_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_arp_tpa_masked_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_arp_tpa_masked_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_bsn_global_vrf_allowed_t *
of_oxm_bsn_global_vrf_allowed_dup(
    of_oxm_bsn_global_vrf_allowed_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_bsn_global_vrf_allowed_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_bsn_global_vrf_allowed_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_bsn_global_vrf_allowed_masked_t *
of_oxm_bsn_global_vrf_allowed_masked_dup(
    of_oxm_bsn_global_vrf_allowed_masked_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_bsn_global_vrf_allowed_masked_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_bsn_global_vrf_allowed_masked_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_bsn_in_ports_128_t *
of_oxm_bsn_in_ports_128_dup(
    of_oxm_bsn_in_ports_128_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_bsn_in_ports_128_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_bsn_in_ports_128_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_bsn_in_ports_128_masked_t *
of_oxm_bsn_in_ports_128_masked_dup(
    of_oxm_bsn_in_ports_128_masked_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_bsn_in_ports_128_masked_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_bsn_in_ports_128_masked_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_bsn_l3_dst_class_id_t *
of_oxm_bsn_l3_dst_class_id_dup(
    of_oxm_bsn_l3_dst_class_id_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_bsn_l3_dst_class_id_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_bsn_l3_dst_class_id_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_bsn_l3_dst_class_id_masked_t *
of_oxm_bsn_l3_dst_class_id_masked_dup(
    of_oxm_bsn_l3_dst_class_id_masked_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_bsn_l3_dst_class_id_masked_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_bsn_l3_dst_class_id_masked_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_bsn_l3_interface_class_id_t *
of_oxm_bsn_l3_interface_class_id_dup(
    of_oxm_bsn_l3_interface_class_id_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_bsn_l3_interface_class_id_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_bsn_l3_interface_class_id_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_bsn_l3_interface_class_id_masked_t *
of_oxm_bsn_l3_interface_class_id_masked_dup(
    of_oxm_bsn_l3_interface_class_id_masked_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_bsn_l3_interface_class_id_masked_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_bsn_l3_interface_class_id_masked_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_bsn_l3_src_class_id_t *
of_oxm_bsn_l3_src_class_id_dup(
    of_oxm_bsn_l3_src_class_id_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_bsn_l3_src_class_id_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_bsn_l3_src_class_id_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_bsn_l3_src_class_id_masked_t *
of_oxm_bsn_l3_src_class_id_masked_dup(
    of_oxm_bsn_l3_src_class_id_masked_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_bsn_l3_src_class_id_masked_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_bsn_l3_src_class_id_masked_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_bsn_lag_id_t *
of_oxm_bsn_lag_id_dup(
    of_oxm_bsn_lag_id_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_bsn_lag_id_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_bsn_lag_id_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_bsn_lag_id_masked_t *
of_oxm_bsn_lag_id_masked_dup(
    of_oxm_bsn_lag_id_masked_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_bsn_lag_id_masked_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_bsn_lag_id_masked_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_bsn_vrf_t *
of_oxm_bsn_vrf_dup(
    of_oxm_bsn_vrf_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_bsn_vrf_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_bsn_vrf_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_bsn_vrf_masked_t *
of_oxm_bsn_vrf_masked_dup(
    of_oxm_bsn_vrf_masked_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_bsn_vrf_masked_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_bsn_vrf_masked_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_eth_dst_t *
of_oxm_eth_dst_dup(
    of_oxm_eth_dst_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_eth_dst_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_eth_dst_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_eth_dst_masked_t *
of_oxm_eth_dst_masked_dup(
    of_oxm_eth_dst_masked_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_eth_dst_masked_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_eth_dst_masked_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_eth_src_t *
of_oxm_eth_src_dup(
    of_oxm_eth_src_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_eth_src_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_eth_src_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_eth_src_masked_t *
of_oxm_eth_src_masked_dup(
    of_oxm_eth_src_masked_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_eth_src_masked_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_eth_src_masked_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_eth_type_t *
of_oxm_eth_type_dup(
    of_oxm_eth_type_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_eth_type_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_eth_type_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_eth_type_masked_t *
of_oxm_eth_type_masked_dup(
    of_oxm_eth_type_masked_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_eth_type_masked_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_eth_type_masked_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_header_t *
of_oxm_header_dup(
    of_oxm_header_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_header_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_header_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_icmpv4_code_t *
of_oxm_icmpv4_code_dup(
    of_oxm_icmpv4_code_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_icmpv4_code_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_icmpv4_code_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_icmpv4_code_masked_t *
of_oxm_icmpv4_code_masked_dup(
    of_oxm_icmpv4_code_masked_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_icmpv4_code_masked_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_icmpv4_code_masked_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_icmpv4_type_t *
of_oxm_icmpv4_type_dup(
    of_oxm_icmpv4_type_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_icmpv4_type_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_icmpv4_type_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_icmpv4_type_masked_t *
of_oxm_icmpv4_type_masked_dup(
    of_oxm_icmpv4_type_masked_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_icmpv4_type_masked_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_icmpv4_type_masked_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_icmpv6_code_t *
of_oxm_icmpv6_code_dup(
    of_oxm_icmpv6_code_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_icmpv6_code_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_icmpv6_code_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_icmpv6_code_masked_t *
of_oxm_icmpv6_code_masked_dup(
    of_oxm_icmpv6_code_masked_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_icmpv6_code_masked_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_icmpv6_code_masked_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_icmpv6_type_t *
of_oxm_icmpv6_type_dup(
    of_oxm_icmpv6_type_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_icmpv6_type_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_icmpv6_type_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_icmpv6_type_masked_t *
of_oxm_icmpv6_type_masked_dup(
    of_oxm_icmpv6_type_masked_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_icmpv6_type_masked_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_icmpv6_type_masked_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_in_phy_port_t *
of_oxm_in_phy_port_dup(
    of_oxm_in_phy_port_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_in_phy_port_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_in_phy_port_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_in_phy_port_masked_t *
of_oxm_in_phy_port_masked_dup(
    of_oxm_in_phy_port_masked_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_in_phy_port_masked_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_in_phy_port_masked_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_in_port_t *
of_oxm_in_port_dup(
    of_oxm_in_port_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_in_port_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_in_port_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_in_port_masked_t *
of_oxm_in_port_masked_dup(
    of_oxm_in_port_masked_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_in_port_masked_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_in_port_masked_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_ip_dscp_t *
of_oxm_ip_dscp_dup(
    of_oxm_ip_dscp_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_ip_dscp_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_ip_dscp_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_ip_dscp_masked_t *
of_oxm_ip_dscp_masked_dup(
    of_oxm_ip_dscp_masked_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_ip_dscp_masked_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_ip_dscp_masked_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_ip_ecn_t *
of_oxm_ip_ecn_dup(
    of_oxm_ip_ecn_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_ip_ecn_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_ip_ecn_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_ip_ecn_masked_t *
of_oxm_ip_ecn_masked_dup(
    of_oxm_ip_ecn_masked_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_ip_ecn_masked_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_ip_ecn_masked_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_ip_proto_t *
of_oxm_ip_proto_dup(
    of_oxm_ip_proto_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_ip_proto_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_ip_proto_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_ip_proto_masked_t *
of_oxm_ip_proto_masked_dup(
    of_oxm_ip_proto_masked_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_ip_proto_masked_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_ip_proto_masked_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_ipv4_dst_t *
of_oxm_ipv4_dst_dup(
    of_oxm_ipv4_dst_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_ipv4_dst_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_ipv4_dst_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_ipv4_dst_masked_t *
of_oxm_ipv4_dst_masked_dup(
    of_oxm_ipv4_dst_masked_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_ipv4_dst_masked_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_ipv4_dst_masked_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_ipv4_src_t *
of_oxm_ipv4_src_dup(
    of_oxm_ipv4_src_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_ipv4_src_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_ipv4_src_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_ipv4_src_masked_t *
of_oxm_ipv4_src_masked_dup(
    of_oxm_ipv4_src_masked_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_ipv4_src_masked_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_ipv4_src_masked_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_ipv6_dst_t *
of_oxm_ipv6_dst_dup(
    of_oxm_ipv6_dst_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_ipv6_dst_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_ipv6_dst_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_ipv6_dst_masked_t *
of_oxm_ipv6_dst_masked_dup(
    of_oxm_ipv6_dst_masked_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_ipv6_dst_masked_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_ipv6_dst_masked_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_ipv6_flabel_t *
of_oxm_ipv6_flabel_dup(
    of_oxm_ipv6_flabel_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_ipv6_flabel_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_ipv6_flabel_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_ipv6_flabel_masked_t *
of_oxm_ipv6_flabel_masked_dup(
    of_oxm_ipv6_flabel_masked_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_ipv6_flabel_masked_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_ipv6_flabel_masked_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_ipv6_nd_sll_t *
of_oxm_ipv6_nd_sll_dup(
    of_oxm_ipv6_nd_sll_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_ipv6_nd_sll_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_ipv6_nd_sll_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_ipv6_nd_sll_masked_t *
of_oxm_ipv6_nd_sll_masked_dup(
    of_oxm_ipv6_nd_sll_masked_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_ipv6_nd_sll_masked_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_ipv6_nd_sll_masked_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_ipv6_nd_target_t *
of_oxm_ipv6_nd_target_dup(
    of_oxm_ipv6_nd_target_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_ipv6_nd_target_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_ipv6_nd_target_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_ipv6_nd_target_masked_t *
of_oxm_ipv6_nd_target_masked_dup(
    of_oxm_ipv6_nd_target_masked_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_ipv6_nd_target_masked_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_ipv6_nd_target_masked_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_ipv6_nd_tll_t *
of_oxm_ipv6_nd_tll_dup(
    of_oxm_ipv6_nd_tll_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_ipv6_nd_tll_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_ipv6_nd_tll_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_ipv6_nd_tll_masked_t *
of_oxm_ipv6_nd_tll_masked_dup(
    of_oxm_ipv6_nd_tll_masked_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_ipv6_nd_tll_masked_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_ipv6_nd_tll_masked_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_ipv6_src_t *
of_oxm_ipv6_src_dup(
    of_oxm_ipv6_src_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_ipv6_src_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_ipv6_src_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_ipv6_src_masked_t *
of_oxm_ipv6_src_masked_dup(
    of_oxm_ipv6_src_masked_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_ipv6_src_masked_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_ipv6_src_masked_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_metadata_t *
of_oxm_metadata_dup(
    of_oxm_metadata_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_metadata_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_metadata_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_metadata_masked_t *
of_oxm_metadata_masked_dup(
    of_oxm_metadata_masked_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_metadata_masked_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_metadata_masked_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_mpls_label_t *
of_oxm_mpls_label_dup(
    of_oxm_mpls_label_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_mpls_label_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_mpls_label_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_mpls_label_masked_t *
of_oxm_mpls_label_masked_dup(
    of_oxm_mpls_label_masked_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_mpls_label_masked_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_mpls_label_masked_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_mpls_tc_t *
of_oxm_mpls_tc_dup(
    of_oxm_mpls_tc_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_mpls_tc_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_mpls_tc_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_mpls_tc_masked_t *
of_oxm_mpls_tc_masked_dup(
    of_oxm_mpls_tc_masked_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_mpls_tc_masked_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_mpls_tc_masked_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_sctp_dst_t *
of_oxm_sctp_dst_dup(
    of_oxm_sctp_dst_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_sctp_dst_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_sctp_dst_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_sctp_dst_masked_t *
of_oxm_sctp_dst_masked_dup(
    of_oxm_sctp_dst_masked_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_sctp_dst_masked_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_sctp_dst_masked_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_sctp_src_t *
of_oxm_sctp_src_dup(
    of_oxm_sctp_src_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_sctp_src_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_sctp_src_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_sctp_src_masked_t *
of_oxm_sctp_src_masked_dup(
    of_oxm_sctp_src_masked_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_sctp_src_masked_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_sctp_src_masked_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_tcp_dst_t *
of_oxm_tcp_dst_dup(
    of_oxm_tcp_dst_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_tcp_dst_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_tcp_dst_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_tcp_dst_masked_t *
of_oxm_tcp_dst_masked_dup(
    of_oxm_tcp_dst_masked_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_tcp_dst_masked_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_tcp_dst_masked_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_tcp_src_t *
of_oxm_tcp_src_dup(
    of_oxm_tcp_src_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_tcp_src_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_tcp_src_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_tcp_src_masked_t *
of_oxm_tcp_src_masked_dup(
    of_oxm_tcp_src_masked_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_tcp_src_masked_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_tcp_src_masked_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_udp_dst_t *
of_oxm_udp_dst_dup(
    of_oxm_udp_dst_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_udp_dst_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_udp_dst_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_udp_dst_masked_t *
of_oxm_udp_dst_masked_dup(
    of_oxm_udp_dst_masked_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_udp_dst_masked_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_udp_dst_masked_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_udp_src_t *
of_oxm_udp_src_dup(
    of_oxm_udp_src_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_udp_src_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_udp_src_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_udp_src_masked_t *
of_oxm_udp_src_masked_dup(
    of_oxm_udp_src_masked_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_udp_src_masked_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_udp_src_masked_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_vlan_pcp_t *
of_oxm_vlan_pcp_dup(
    of_oxm_vlan_pcp_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_vlan_pcp_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_vlan_pcp_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_vlan_pcp_masked_t *
of_oxm_vlan_pcp_masked_dup(
    of_oxm_vlan_pcp_masked_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_vlan_pcp_masked_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_vlan_pcp_masked_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_vlan_vid_t *
of_oxm_vlan_vid_dup(
    of_oxm_vlan_vid_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_vlan_vid_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_vlan_vid_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_oxm_vlan_vid_masked_t *
of_oxm_vlan_vid_masked_dup(
    of_oxm_vlan_vid_masked_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_oxm_vlan_vid_masked_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_oxm_vlan_vid_masked_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_packet_queue_t *
of_packet_queue_dup(
    of_packet_queue_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_packet_queue_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_packet_queue_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_packet_queue_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_packet_queue_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_port_desc_t *
of_port_desc_dup(
    of_port_desc_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_port_desc_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_port_desc_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_port_desc_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_port_desc_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_port_stats_entry_t *
of_port_stats_entry_dup(
    of_port_stats_entry_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_port_stats_entry_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_port_stats_entry_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_port_stats_entry_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_port_stats_entry_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_queue_prop_t *
of_queue_prop_dup(
    of_queue_prop_t *src)
{

    if (src->header.version == OF_VERSION_1_0) {
        return of_queue_prop_OF_VERSION_1_0_dup(src);
    }

    if (src->header.version == OF_VERSION_1_1) {
        return of_queue_prop_OF_VERSION_1_1_dup(src);
    }

    if (src->header.version == OF_VERSION_1_2) {
        return of_queue_prop_OF_VERSION_1_2_dup(src);
    }

    if (src->header.version == OF_VERSION_1_3) {
        return of_queue_prop_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_queue_prop_experimenter_t *
of_queue_prop_experimenter_dup(
    of_queue_prop_experimenter_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_queue_prop_experimenter_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_queue_prop_experimenter_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_queue_prop_header_t *
of_queue_prop_header_dup(
    of_queue_prop_header_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_queue_prop_header_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_queue_prop_header_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_queue_prop_header_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_queue_prop_header_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_queue_prop_max_rate_t *
of_queue_prop_max_rate_dup(
    of_queue_prop_max_rate_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_queue_prop_max_rate_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_queue_prop_max_rate_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_queue_prop_min_rate_t *
of_queue_prop_min_rate_dup(
    of_queue_prop_min_rate_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_queue_prop_min_rate_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_queue_prop_min_rate_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_queue_prop_min_rate_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_queue_prop_min_rate_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_queue_stats_entry_t *
of_queue_stats_entry_dup(
    of_queue_stats_entry_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_queue_stats_entry_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_queue_stats_entry_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_queue_stats_entry_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_queue_stats_entry_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_table_feature_prop_t *
of_table_feature_prop_dup(
    of_table_feature_prop_t *src)
{

    if (src->header.version == OF_VERSION_1_3) {
        return of_table_feature_prop_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_table_feature_prop_apply_actions_t *
of_table_feature_prop_apply_actions_dup(
    of_table_feature_prop_apply_actions_t *src)
{

    if (src->version == OF_VERSION_1_3) {
        return of_table_feature_prop_apply_actions_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_table_feature_prop_apply_actions_miss_t *
of_table_feature_prop_apply_actions_miss_dup(
    of_table_feature_prop_apply_actions_miss_t *src)
{

    if (src->version == OF_VERSION_1_3) {
        return of_table_feature_prop_apply_actions_miss_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_table_feature_prop_apply_setfield_t *
of_table_feature_prop_apply_setfield_dup(
    of_table_feature_prop_apply_setfield_t *src)
{

    if (src->version == OF_VERSION_1_3) {
        return of_table_feature_prop_apply_setfield_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_table_feature_prop_apply_setfield_miss_t *
of_table_feature_prop_apply_setfield_miss_dup(
    of_table_feature_prop_apply_setfield_miss_t *src)
{

    if (src->version == OF_VERSION_1_3) {
        return of_table_feature_prop_apply_setfield_miss_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_table_feature_prop_experimenter_t *
of_table_feature_prop_experimenter_dup(
    of_table_feature_prop_experimenter_t *src)
{

    if (src->version == OF_VERSION_1_3) {
        return of_table_feature_prop_experimenter_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_table_feature_prop_header_t *
of_table_feature_prop_header_dup(
    of_table_feature_prop_header_t *src)
{

    if (src->version == OF_VERSION_1_3) {
        return of_table_feature_prop_header_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_table_feature_prop_instructions_t *
of_table_feature_prop_instructions_dup(
    of_table_feature_prop_instructions_t *src)
{

    if (src->version == OF_VERSION_1_3) {
        return of_table_feature_prop_instructions_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_table_feature_prop_instructions_miss_t *
of_table_feature_prop_instructions_miss_dup(
    of_table_feature_prop_instructions_miss_t *src)
{

    if (src->version == OF_VERSION_1_3) {
        return of_table_feature_prop_instructions_miss_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_table_feature_prop_match_t *
of_table_feature_prop_match_dup(
    of_table_feature_prop_match_t *src)
{

    if (src->version == OF_VERSION_1_3) {
        return of_table_feature_prop_match_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_table_feature_prop_next_tables_t *
of_table_feature_prop_next_tables_dup(
    of_table_feature_prop_next_tables_t *src)
{

    if (src->version == OF_VERSION_1_3) {
        return of_table_feature_prop_next_tables_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_table_feature_prop_next_tables_miss_t *
of_table_feature_prop_next_tables_miss_dup(
    of_table_feature_prop_next_tables_miss_t *src)
{

    if (src->version == OF_VERSION_1_3) {
        return of_table_feature_prop_next_tables_miss_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_table_feature_prop_wildcards_t *
of_table_feature_prop_wildcards_dup(
    of_table_feature_prop_wildcards_t *src)
{

    if (src->version == OF_VERSION_1_3) {
        return of_table_feature_prop_wildcards_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_table_feature_prop_write_actions_t *
of_table_feature_prop_write_actions_dup(
    of_table_feature_prop_write_actions_t *src)
{

    if (src->version == OF_VERSION_1_3) {
        return of_table_feature_prop_write_actions_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_table_feature_prop_write_actions_miss_t *
of_table_feature_prop_write_actions_miss_dup(
    of_table_feature_prop_write_actions_miss_t *src)
{

    if (src->version == OF_VERSION_1_3) {
        return of_table_feature_prop_write_actions_miss_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_table_feature_prop_write_setfield_t *
of_table_feature_prop_write_setfield_dup(
    of_table_feature_prop_write_setfield_t *src)
{

    if (src->version == OF_VERSION_1_3) {
        return of_table_feature_prop_write_setfield_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_table_feature_prop_write_setfield_miss_t *
of_table_feature_prop_write_setfield_miss_dup(
    of_table_feature_prop_write_setfield_miss_t *src)
{

    if (src->version == OF_VERSION_1_3) {
        return of_table_feature_prop_write_setfield_miss_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_table_features_t *
of_table_features_dup(
    of_table_features_t *src)
{

    if (src->version == OF_VERSION_1_3) {
        return of_table_features_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_table_stats_entry_t *
of_table_stats_entry_dup(
    of_table_stats_entry_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_table_stats_entry_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_table_stats_entry_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_table_stats_entry_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_table_stats_entry_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_uint32_t *
of_uint32_dup(
    of_uint32_t *src)
{

    if (src->version == OF_VERSION_1_3) {
        return of_uint32_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_uint8_t *
of_uint8_dup(
    of_uint8_t *src)
{

    if (src->version == OF_VERSION_1_3) {
        return of_uint8_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_list_action_t *
of_list_action_dup(
    of_list_action_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_list_action_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_list_action_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_list_action_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_list_action_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_list_action_id_t *
of_list_action_id_dup(
    of_list_action_id_t *src)
{

    if (src->version == OF_VERSION_1_3) {
        return of_list_action_id_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_list_bsn_interface_t *
of_list_bsn_interface_dup(
    of_list_bsn_interface_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_list_bsn_interface_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_list_bsn_interface_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_list_bsn_interface_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_list_bsn_interface_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_list_bucket_t *
of_list_bucket_dup(
    of_list_bucket_t *src)
{

    if (src->version == OF_VERSION_1_1) {
        return of_list_bucket_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_list_bucket_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_list_bucket_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_list_bucket_counter_t *
of_list_bucket_counter_dup(
    of_list_bucket_counter_t *src)
{

    if (src->version == OF_VERSION_1_1) {
        return of_list_bucket_counter_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_list_bucket_counter_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_list_bucket_counter_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_list_flow_stats_entry_t *
of_list_flow_stats_entry_dup(
    of_list_flow_stats_entry_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_list_flow_stats_entry_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_list_flow_stats_entry_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_list_flow_stats_entry_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_list_flow_stats_entry_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_list_group_desc_stats_entry_t *
of_list_group_desc_stats_entry_dup(
    of_list_group_desc_stats_entry_t *src)
{

    if (src->version == OF_VERSION_1_1) {
        return of_list_group_desc_stats_entry_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_list_group_desc_stats_entry_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_list_group_desc_stats_entry_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_list_group_stats_entry_t *
of_list_group_stats_entry_dup(
    of_list_group_stats_entry_t *src)
{

    if (src->version == OF_VERSION_1_1) {
        return of_list_group_stats_entry_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_list_group_stats_entry_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_list_group_stats_entry_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_list_hello_elem_t *
of_list_hello_elem_dup(
    of_list_hello_elem_t *src)
{

    if (src->version == OF_VERSION_1_3) {
        return of_list_hello_elem_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_list_instruction_t *
of_list_instruction_dup(
    of_list_instruction_t *src)
{

    if (src->version == OF_VERSION_1_1) {
        return of_list_instruction_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_list_instruction_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_list_instruction_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_list_meter_band_t *
of_list_meter_band_dup(
    of_list_meter_band_t *src)
{

    if (src->version == OF_VERSION_1_3) {
        return of_list_meter_band_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_list_meter_band_stats_t *
of_list_meter_band_stats_dup(
    of_list_meter_band_stats_t *src)
{

    if (src->version == OF_VERSION_1_3) {
        return of_list_meter_band_stats_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_list_meter_stats_t *
of_list_meter_stats_dup(
    of_list_meter_stats_t *src)
{

    if (src->version == OF_VERSION_1_3) {
        return of_list_meter_stats_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_list_oxm_t *
of_list_oxm_dup(
    of_list_oxm_t *src)
{

    if (src->version == OF_VERSION_1_2) {
        return of_list_oxm_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_list_oxm_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_list_packet_queue_t *
of_list_packet_queue_dup(
    of_list_packet_queue_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_list_packet_queue_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_list_packet_queue_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_list_packet_queue_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_list_packet_queue_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_list_port_desc_t *
of_list_port_desc_dup(
    of_list_port_desc_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_list_port_desc_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_list_port_desc_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_list_port_desc_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_list_port_desc_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_list_port_stats_entry_t *
of_list_port_stats_entry_dup(
    of_list_port_stats_entry_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_list_port_stats_entry_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_list_port_stats_entry_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_list_port_stats_entry_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_list_port_stats_entry_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_list_queue_prop_t *
of_list_queue_prop_dup(
    of_list_queue_prop_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_list_queue_prop_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_list_queue_prop_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_list_queue_prop_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_list_queue_prop_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_list_queue_stats_entry_t *
of_list_queue_stats_entry_dup(
    of_list_queue_stats_entry_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_list_queue_stats_entry_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_list_queue_stats_entry_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_list_queue_stats_entry_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_list_queue_stats_entry_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_list_table_feature_prop_t *
of_list_table_feature_prop_dup(
    of_list_table_feature_prop_t *src)
{

    if (src->version == OF_VERSION_1_3) {
        return of_list_table_feature_prop_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_list_table_features_t *
of_list_table_features_dup(
    of_list_table_features_t *src)
{

    if (src->version == OF_VERSION_1_3) {
        return of_list_table_features_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_list_table_stats_entry_t *
of_list_table_stats_entry_dup(
    of_list_table_stats_entry_t *src)
{

    if (src->version == OF_VERSION_1_0) {
        return of_list_table_stats_entry_OF_VERSION_1_0_dup(src);
    }

    if (src->version == OF_VERSION_1_1) {
        return of_list_table_stats_entry_OF_VERSION_1_1_dup(src);
    }

    if (src->version == OF_VERSION_1_2) {
        return of_list_table_stats_entry_OF_VERSION_1_2_dup(src);
    }

    if (src->version == OF_VERSION_1_3) {
        return of_list_table_stats_entry_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_list_uint32_t *
of_list_uint32_dup(
    of_list_uint32_t *src)
{

    if (src->version == OF_VERSION_1_3) {
        return of_list_uint32_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}

of_list_uint8_t *
of_list_uint8_dup(
    of_list_uint8_t *src)
{

    if (src->version == OF_VERSION_1_3) {
        return of_list_uint8_OF_VERSION_1_3_dup(src);
    }

    /* Class not supported in given version */
    return NULL;
}
