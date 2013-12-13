/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */

/****************************************************************
 *
 * Functions for each concrete class that set the type fields
 *
 ****************************************************************/

#include <loci/loci.h>
#include <loci/of_message.h>
#include <endian.h>

#ifdef __GNUC__
#define UNREACHABLE() __builtin_unreachable()
#else
#define UNREACHABLE()
#endif

/*
 * In a separate function to give the compiler the choice of whether to inline.
 */
static unsigned char *
loci_object_to_buffer(of_object_t *obj)
{
    return OF_OBJECT_BUFFER_INDEX(obj, 0);
}


void
of_action_bsn_mirror_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(65535); /* type */
        *(uint32_t *)(buf + 4) = htobe32(6035143); /* experimenter */
        *(uint32_t *)(buf + 8) = htobe32(1); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_bsn_set_tunnel_dst_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(65535); /* type */
        *(uint32_t *)(buf + 4) = htobe32(6035143); /* experimenter */
        *(uint32_t *)(buf + 8) = htobe32(2); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_enqueue_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint16_t *)(buf + 0) = htobe16(11); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_nicira_dec_ttl_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(65535); /* type */
        *(uint32_t *)(buf + 4) = htobe32(8992); /* experimenter */
        *(uint16_t *)(buf + 8) = htobe16(18); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_output_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_set_dl_dst_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint16_t *)(buf + 0) = htobe16(5); /* type */
        break;
    case OF_VERSION_1_1:
        *(uint16_t *)(buf + 0) = htobe16(4); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_set_dl_src_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint16_t *)(buf + 0) = htobe16(4); /* type */
        break;
    case OF_VERSION_1_1:
        *(uint16_t *)(buf + 0) = htobe16(3); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_set_nw_dst_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint16_t *)(buf + 0) = htobe16(7); /* type */
        break;
    case OF_VERSION_1_1:
        *(uint16_t *)(buf + 0) = htobe16(6); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_set_nw_src_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint16_t *)(buf + 0) = htobe16(6); /* type */
        break;
    case OF_VERSION_1_1:
        *(uint16_t *)(buf + 0) = htobe16(5); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_set_nw_tos_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint16_t *)(buf + 0) = htobe16(8); /* type */
        break;
    case OF_VERSION_1_1:
        *(uint16_t *)(buf + 0) = htobe16(7); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_set_tp_dst_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
        *(uint16_t *)(buf + 0) = htobe16(10); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_set_tp_src_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
        *(uint16_t *)(buf + 0) = htobe16(9); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_set_vlan_pcp_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
        *(uint16_t *)(buf + 0) = htobe16(2); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_set_vlan_vid_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
        *(uint16_t *)(buf + 0) = htobe16(1); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_strip_vlan_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint16_t *)(buf + 0) = htobe16(3); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_aggregate_stats_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 17; /* type */
        *(uint16_t *)(buf + 8) = htobe16(2); /* stats_type */
        break;
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 19; /* type */
        *(uint16_t *)(buf + 8) = htobe16(2); /* stats_type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_aggregate_stats_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 16; /* type */
        *(uint16_t *)(buf + 8) = htobe16(2); /* stats_type */
        break;
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 18; /* type */
        *(uint16_t *)(buf + 8) = htobe16(2); /* stats_type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bad_action_error_msg_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 1; /* type */
        *(uint16_t *)(buf + 8) = htobe16(2); /* err_type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bad_request_error_msg_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 1; /* type */
        *(uint16_t *)(buf + 8) = htobe16(1); /* err_type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_barrier_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 19; /* type */
        break;
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 21; /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_barrier_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 18; /* type */
        break;
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 20; /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_bw_clear_data_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(6035143); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(22); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_bw_clear_data_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(6035143); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(21); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_bw_enable_get_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(6035143); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(20); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_bw_enable_get_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(6035143); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(19); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_bw_enable_set_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(6035143); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(23); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_bw_enable_set_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(6035143); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(18); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_get_interfaces_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(6035143); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(10); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_get_interfaces_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(6035143); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(9); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_get_ip_mask_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(6035143); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(2); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_get_ip_mask_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(6035143); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(1); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_get_l2_table_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(6035143); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(14); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_get_l2_table_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(6035143); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(13); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_get_mirroring_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(6035143); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(5); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_get_mirroring_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(6035143); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(4); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_hybrid_get_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(6035143); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(28); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_hybrid_get_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(6035143); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(27); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_pdu_rx_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(6035143); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(34); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_pdu_rx_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(6035143); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(33); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_pdu_rx_timeout_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(6035143); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(35); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_pdu_tx_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(6035143); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(32); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_pdu_tx_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(6035143); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(31); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_set_ip_mask_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(6035143); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(0); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_set_l2_table_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(6035143); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(24); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_set_l2_table_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(6035143); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(12); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_set_mirroring_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(6035143); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(3); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_set_pktin_suppression_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(6035143); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(25); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_set_pktin_suppression_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(6035143); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(11); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_shell_command_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(6035143); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(6); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_shell_output_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(6035143); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(7); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_shell_status_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(6035143); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(8); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_virtual_port_create_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(6035143); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(16); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_vport_q_in_q_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_virtual_port_create_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(6035143); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(15); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_virtual_port_remove_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(6035143); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(26); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_virtual_port_remove_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(6035143); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(17); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_desc_stats_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 17; /* type */
        *(uint16_t *)(buf + 8) = htobe16(0); /* stats_type */
        break;
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 19; /* type */
        *(uint16_t *)(buf + 8) = htobe16(0); /* stats_type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_desc_stats_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 16; /* type */
        *(uint16_t *)(buf + 8) = htobe16(0); /* stats_type */
        break;
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 18; /* type */
        *(uint16_t *)(buf + 8) = htobe16(0); /* stats_type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_echo_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 3; /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_echo_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 2; /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_features_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 6; /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_features_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 5; /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_flow_add_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 14; /* type */
        *(uint16_t *)(buf + 56) = htobe16(0); /* _command */
        break;
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 14; /* type */
        *(uint8_t *)(buf + 25) = 0; /* _command */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_flow_delete_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 14; /* type */
        *(uint16_t *)(buf + 56) = htobe16(3); /* _command */
        break;
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 14; /* type */
        *(uint8_t *)(buf + 25) = 3; /* _command */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_flow_delete_strict_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 14; /* type */
        *(uint16_t *)(buf + 56) = htobe16(4); /* _command */
        break;
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 14; /* type */
        *(uint8_t *)(buf + 25) = 4; /* _command */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_flow_mod_failed_error_msg_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 1; /* type */
        *(uint16_t *)(buf + 8) = htobe16(3); /* err_type */
        break;
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 1; /* type */
        *(uint16_t *)(buf + 8) = htobe16(5); /* err_type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_flow_modify_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 14; /* type */
        *(uint16_t *)(buf + 56) = htobe16(1); /* _command */
        break;
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 14; /* type */
        *(uint8_t *)(buf + 25) = 1; /* _command */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_flow_modify_strict_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 14; /* type */
        *(uint16_t *)(buf + 56) = htobe16(2); /* _command */
        break;
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 14; /* type */
        *(uint8_t *)(buf + 25) = 2; /* _command */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_flow_removed_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 11; /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_flow_stats_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 17; /* type */
        *(uint16_t *)(buf + 8) = htobe16(1); /* stats_type */
        break;
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 19; /* type */
        *(uint16_t *)(buf + 8) = htobe16(1); /* stats_type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_flow_stats_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 16; /* type */
        *(uint16_t *)(buf + 8) = htobe16(1); /* stats_type */
        break;
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 18; /* type */
        *(uint16_t *)(buf + 8) = htobe16(1); /* stats_type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_get_config_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 8; /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_get_config_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 7; /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_hello_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0; /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_hello_failed_error_msg_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 1; /* type */
        *(uint16_t *)(buf + 8) = htobe16(0); /* err_type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_nicira_controller_role_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(8992); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(11); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_nicira_controller_role_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(8992); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(10); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_packet_in_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 10; /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_packet_out_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 13; /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_port_mod_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 15; /* type */
        break;
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 16; /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_port_mod_failed_error_msg_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 1; /* type */
        *(uint16_t *)(buf + 8) = htobe16(4); /* err_type */
        break;
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 1; /* type */
        *(uint16_t *)(buf + 8) = htobe16(7); /* err_type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_port_stats_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 17; /* type */
        *(uint16_t *)(buf + 8) = htobe16(4); /* stats_type */
        break;
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 19; /* type */
        *(uint16_t *)(buf + 8) = htobe16(4); /* stats_type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_port_stats_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 16; /* type */
        *(uint16_t *)(buf + 8) = htobe16(4); /* stats_type */
        break;
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 18; /* type */
        *(uint16_t *)(buf + 8) = htobe16(4); /* stats_type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_port_status_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 12; /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_queue_get_config_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 21; /* type */
        break;
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 23; /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_queue_get_config_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 20; /* type */
        break;
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 22; /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_queue_op_failed_error_msg_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 1; /* type */
        *(uint16_t *)(buf + 8) = htobe16(5); /* err_type */
        break;
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 1; /* type */
        *(uint16_t *)(buf + 8) = htobe16(9); /* err_type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_queue_prop_min_rate_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(1); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_queue_stats_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 17; /* type */
        *(uint16_t *)(buf + 8) = htobe16(5); /* stats_type */
        break;
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 19; /* type */
        *(uint16_t *)(buf + 8) = htobe16(5); /* stats_type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_queue_stats_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 16; /* type */
        *(uint16_t *)(buf + 8) = htobe16(5); /* stats_type */
        break;
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 18; /* type */
        *(uint16_t *)(buf + 8) = htobe16(5); /* stats_type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_set_config_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 9; /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_table_mod_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 22; /* type */
        break;
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 17; /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_table_stats_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 17; /* type */
        *(uint16_t *)(buf + 8) = htobe16(3); /* stats_type */
        break;
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 19; /* type */
        *(uint16_t *)(buf + 8) = htobe16(3); /* stats_type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_table_stats_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 16; /* type */
        *(uint16_t *)(buf + 8) = htobe16(3); /* stats_type */
        break;
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 18; /* type */
        *(uint16_t *)(buf + 8) = htobe16(3); /* stats_type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_copy_ttl_in_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(12); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_copy_ttl_out_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(11); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_dec_mpls_ttl_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(16); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_dec_nw_ttl_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(24); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_group_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(22); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_pop_mpls_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(20); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_pop_vlan_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(18); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_push_mpls_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(19); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_push_vlan_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(17); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_set_mpls_label_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_1:
        *(uint16_t *)(buf + 0) = htobe16(13); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_set_mpls_tc_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_1:
        *(uint16_t *)(buf + 0) = htobe16(14); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_set_mpls_ttl_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(15); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_set_nw_ecn_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_1:
        *(uint16_t *)(buf + 0) = htobe16(8); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_set_nw_ttl_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(23); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_set_queue_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(21); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bad_instruction_error_msg_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 1; /* type */
        *(uint16_t *)(buf + 8) = htobe16(3); /* err_type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bad_match_error_msg_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 1; /* type */
        *(uint16_t *)(buf + 8) = htobe16(4); /* err_type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_group_add_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 15; /* type */
        *(uint16_t *)(buf + 8) = htobe16(0); /* command */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_group_delete_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 15; /* type */
        *(uint16_t *)(buf + 8) = htobe16(2); /* command */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_group_desc_stats_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 19; /* type */
        *(uint16_t *)(buf + 8) = htobe16(7); /* stats_type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_group_desc_stats_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 18; /* type */
        *(uint16_t *)(buf + 8) = htobe16(7); /* stats_type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_group_mod_failed_error_msg_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 1; /* type */
        *(uint16_t *)(buf + 8) = htobe16(6); /* err_type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_group_modify_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 15; /* type */
        *(uint16_t *)(buf + 8) = htobe16(1); /* command */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_group_stats_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 19; /* type */
        *(uint16_t *)(buf + 8) = htobe16(6); /* stats_type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_group_stats_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 18; /* type */
        *(uint16_t *)(buf + 8) = htobe16(6); /* stats_type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_instruction_apply_actions_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(4); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_instruction_clear_actions_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(5); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_instruction_goto_table_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(1); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_instruction_write_actions_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(3); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_instruction_write_metadata_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(2); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_match_v2_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_1:
        *(uint16_t *)(buf + 0) = htobe16(0); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_switch_config_failed_error_msg_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 1; /* type */
        *(uint16_t *)(buf + 8) = htobe16(10); /* err_type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_table_mod_failed_error_msg_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 1; /* type */
        *(uint16_t *)(buf + 8) = htobe16(8); /* err_type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_set_field_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(25); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_experimenter_error_msg_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 1; /* type */
        *(uint16_t *)(buf + 8) = htobe16(65535); /* err_type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_group_features_stats_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 19; /* type */
        *(uint16_t *)(buf + 8) = htobe16(8); /* stats_type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_group_features_stats_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 18; /* type */
        *(uint16_t *)(buf + 8) = htobe16(8); /* stats_type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_match_v3_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(1); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_arp_op_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(2147494402); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_arp_op_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(2147494660); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_arp_sha_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(2147495942); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_arp_sha_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(2147496204); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_arp_spa_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(2147494916); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_arp_spa_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(2147495176); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_arp_tha_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(2147496454); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_arp_tha_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(2147496716); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_arp_tpa_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(2147495428); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_arp_tpa_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(2147495688); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_bsn_global_vrf_allowed_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(198145); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_bsn_global_vrf_allowed_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(198402); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_bsn_in_ports_128_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(196624); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_bsn_in_ports_128_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(196896); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_bsn_l3_dst_class_id_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(199684); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_bsn_l3_dst_class_id_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(199944); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_bsn_l3_interface_class_id_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(198660); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_bsn_l3_interface_class_id_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(198920); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_bsn_l3_src_class_id_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(199172); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_bsn_l3_src_class_id_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(199432); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_bsn_lag_id_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(197124); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_bsn_lag_id_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(197384); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_bsn_vrf_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(197636); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_bsn_vrf_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(197896); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_eth_dst_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(2147485190); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_eth_dst_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(2147485452); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_eth_src_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(2147485702); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_eth_src_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(2147485964); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_eth_type_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(2147486210); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_eth_type_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(2147486468); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_icmpv4_code_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(2147493889); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_icmpv4_code_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(2147494146); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_icmpv4_type_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(2147493377); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_icmpv4_type_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(2147493634); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_icmpv6_code_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(2147499009); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_icmpv6_code_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(2147499266); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_icmpv6_type_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(2147498497); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_icmpv6_type_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(2147498754); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_in_phy_port_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(2147484164); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_in_phy_port_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(2147484424); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_in_port_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(2147483652); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_in_port_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(2147483912); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_ip_dscp_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(2147487745); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_ip_dscp_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(2147488002); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_ip_ecn_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(2147488257); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_ip_ecn_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(2147488514); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_ip_proto_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(2147488769); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_ip_proto_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(2147489026); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_ipv4_dst_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(2147489796); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_ipv4_dst_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(2147490056); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_ipv4_src_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(2147489284); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_ipv4_src_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(2147489544); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_ipv6_dst_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(2147497488); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_ipv6_dst_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(2147497760); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_ipv6_flabel_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(2147497988); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_ipv6_flabel_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(2147498248); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_ipv6_nd_sll_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(2147500038); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_ipv6_nd_sll_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(2147500300); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_ipv6_nd_target_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(2147499536); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_ipv6_nd_target_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(2147499808); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_ipv6_nd_tll_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(2147500550); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_ipv6_nd_tll_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(2147500812); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_ipv6_src_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(2147496976); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_ipv6_src_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(2147497248); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_metadata_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(2147484680); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_metadata_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(2147484944); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_mpls_label_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(2147501060); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_mpls_label_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(2147501320); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_mpls_tc_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(2147501569); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_mpls_tc_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(2147501826); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_sctp_dst_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(2147492866); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_sctp_dst_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(2147493124); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_sctp_src_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(2147492354); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_sctp_src_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(2147492612); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_tcp_dst_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(2147490818); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_tcp_dst_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(2147491076); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_tcp_src_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(2147490306); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_tcp_src_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(2147490564); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_udp_dst_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(2147491842); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_udp_dst_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(2147492100); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_udp_src_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(2147491330); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_udp_src_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(2147491588); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_vlan_pcp_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(2147487233); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_vlan_pcp_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(2147487490); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_vlan_vid_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(2147486722); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_vlan_vid_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(2147486980); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_queue_prop_max_rate_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(2); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_role_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 25; /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_role_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 24; /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_role_request_failed_error_msg_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 1; /* type */
        *(uint16_t *)(buf + 8) = htobe16(11); /* err_type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_id_bsn_mirror_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(65535); /* type */
        *(uint32_t *)(buf + 4) = htobe32(6035143); /* experimenter */
        *(uint32_t *)(buf + 8) = htobe32(1); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_id_bsn_set_tunnel_dst_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(65535); /* type */
        *(uint32_t *)(buf + 4) = htobe32(6035143); /* experimenter */
        *(uint32_t *)(buf + 8) = htobe32(2); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_id_copy_ttl_in_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(12); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_id_copy_ttl_out_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(11); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_id_dec_mpls_ttl_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(16); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_id_dec_nw_ttl_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(24); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_id_group_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(22); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_id_nicira_dec_ttl_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(65535); /* type */
        *(uint32_t *)(buf + 4) = htobe32(8992); /* experimenter */
        *(uint16_t *)(buf + 8) = htobe16(18); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_id_output_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_id_pop_mpls_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(20); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_pop_pbb_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(27); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_id_pop_pbb_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(27); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_id_pop_vlan_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(18); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_id_push_mpls_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(19); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_push_pbb_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(26); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_id_push_pbb_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(26); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_id_push_vlan_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(17); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_id_set_field_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(25); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_id_set_mpls_ttl_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(15); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_id_set_nw_ttl_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(23); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_id_set_queue_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(21); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_async_get_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 27; /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_async_get_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 26; /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_async_set_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 28; /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_flow_idle_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(6035143); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(40); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_flow_idle_enable_get_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(6035143); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(39); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_flow_idle_enable_get_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(6035143); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(38); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_flow_idle_enable_set_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(6035143); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(37); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_flow_idle_enable_set_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(6035143); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(36); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_get_switch_pipeline_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(6035143); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(52); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_get_switch_pipeline_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(6035143); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(51); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_lacp_convergence_notif_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(6035143); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(43); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_lacp_stats_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 19; /* type */
        *(uint16_t *)(buf + 8) = htobe16(65535); /* stats_type */
        *(uint32_t *)(buf + 16) = htobe32(6035143); /* experimenter */
        *(uint32_t *)(buf + 20) = htobe32(1); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_lacp_stats_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 18; /* type */
        *(uint16_t *)(buf + 8) = htobe16(65535); /* stats_type */
        *(uint32_t *)(buf + 16) = htobe32(6035143); /* experimenter */
        *(uint32_t *)(buf + 20) = htobe32(1); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_port_counter_stats_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 19; /* type */
        *(uint16_t *)(buf + 8) = htobe16(65535); /* stats_type */
        *(uint32_t *)(buf + 16) = htobe32(6035143); /* experimenter */
        *(uint32_t *)(buf + 20) = htobe32(8); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_port_counter_stats_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 18; /* type */
        *(uint16_t *)(buf + 8) = htobe16(65535); /* stats_type */
        *(uint32_t *)(buf + 16) = htobe32(6035143); /* experimenter */
        *(uint32_t *)(buf + 20) = htobe32(8); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_set_lacp_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(6035143); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(42); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_set_lacp_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(6035143); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(41); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_set_switch_pipeline_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(6035143); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(54); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_set_switch_pipeline_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(6035143); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(53); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_switch_pipeline_stats_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 19; /* type */
        *(uint16_t *)(buf + 8) = htobe16(65535); /* stats_type */
        *(uint32_t *)(buf + 16) = htobe32(6035143); /* experimenter */
        *(uint32_t *)(buf + 20) = htobe32(6); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_switch_pipeline_stats_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 18; /* type */
        *(uint16_t *)(buf + 8) = htobe16(65535); /* stats_type */
        *(uint32_t *)(buf + 16) = htobe32(6035143); /* experimenter */
        *(uint32_t *)(buf + 20) = htobe32(6); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_time_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(6035143); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(45); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_time_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(6035143); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(44); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_vlan_counter_stats_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 19; /* type */
        *(uint16_t *)(buf + 8) = htobe16(65535); /* stats_type */
        *(uint32_t *)(buf + 16) = htobe32(6035143); /* experimenter */
        *(uint32_t *)(buf + 20) = htobe32(9); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_vlan_counter_stats_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 18; /* type */
        *(uint16_t *)(buf + 8) = htobe16(65535); /* stats_type */
        *(uint32_t *)(buf + 16) = htobe32(6035143); /* experimenter */
        *(uint32_t *)(buf + 20) = htobe32(9); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_hello_elem_versionbitmap_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(1); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_instruction_id_apply_actions_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(4); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_instruction_bsn_disable_src_mac_check_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(65535); /* type */
        *(uint32_t *)(buf + 4) = htobe32(6035143); /* experimenter */
        *(uint32_t *)(buf + 8) = htobe32(0); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_instruction_id_bsn_disable_src_mac_check_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(65535); /* type */
        *(uint32_t *)(buf + 4) = htobe32(6035143); /* experimenter */
        *(uint32_t *)(buf + 8) = htobe32(0); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_instruction_id_clear_actions_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(5); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_instruction_id_goto_table_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(1); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_instruction_meter_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(6); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_instruction_id_meter_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(6); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_instruction_id_write_actions_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(3); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_instruction_id_write_metadata_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(2); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_meter_band_drop_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(1); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_meter_band_dscp_remark_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(2); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_meter_band_experimenter_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(65535); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_meter_config_stats_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 19; /* type */
        *(uint16_t *)(buf + 8) = htobe16(10); /* stats_type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_meter_config_stats_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 18; /* type */
        *(uint16_t *)(buf + 8) = htobe16(10); /* stats_type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_meter_features_stats_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 19; /* type */
        *(uint16_t *)(buf + 8) = htobe16(11); /* stats_type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_meter_features_stats_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 18; /* type */
        *(uint16_t *)(buf + 8) = htobe16(11); /* stats_type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_meter_mod_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 29; /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_meter_mod_failed_error_msg_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 1; /* type */
        *(uint16_t *)(buf + 8) = htobe16(12); /* err_type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_meter_stats_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 19; /* type */
        *(uint16_t *)(buf + 8) = htobe16(9); /* stats_type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_meter_stats_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 18; /* type */
        *(uint16_t *)(buf + 8) = htobe16(9); /* stats_type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_port_desc_stats_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 19; /* type */
        *(uint16_t *)(buf + 8) = htobe16(13); /* stats_type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_port_desc_stats_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 18; /* type */
        *(uint16_t *)(buf + 8) = htobe16(13); /* stats_type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_table_feature_prop_apply_actions_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(6); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_table_feature_prop_apply_actions_miss_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(7); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_table_feature_prop_apply_setfield_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(14); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_table_feature_prop_apply_setfield_miss_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(15); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_table_feature_prop_experimenter_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(65535); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_table_feature_prop_instructions_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_table_feature_prop_instructions_miss_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(1); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_table_feature_prop_match_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(8); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_table_feature_prop_next_tables_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(2); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_table_feature_prop_next_tables_miss_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(3); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_table_feature_prop_wildcards_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(10); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_table_feature_prop_write_actions_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(4); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_table_feature_prop_write_actions_miss_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(5); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_table_feature_prop_write_setfield_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(12); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_table_feature_prop_write_setfield_miss_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(13); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_table_features_failed_error_msg_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 1; /* type */
        *(uint16_t *)(buf + 8) = htobe16(13); /* err_type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_table_features_stats_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 19; /* type */
        *(uint16_t *)(buf + 8) = htobe16(12); /* stats_type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_table_features_stats_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 18; /* type */
        *(uint16_t *)(buf + 8) = htobe16(12); /* stats_type */
        break;
    default:
        UNREACHABLE();
    }
}
