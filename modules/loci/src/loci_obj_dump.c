/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */

/**
 *
 * AUTOMATICALLY GENERATED FILE.  Edits will be lost on regen.
 *
 * Source file for object dumping.
 *
 */

#define DISABLE_WARN_UNUSED_RESULT
#include <loci/loci.h>
#include <loci/loci_dump.h>
#include <loci/loci_obj_dump.h>

static int
unknown_dump(loci_writer_f writer, void* cookie, of_object_t *obj)
{
    return writer(cookie, "Unable to print object of type %d, version %d\n",
                         obj->object_id, obj->version);
}

int
of_aggregate_stats_reply_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_aggregate_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    uint64_t val64;

    out += writer(cookie, "Object of type of_aggregate_stats_reply\n");

    of_aggregate_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_aggregate_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_aggregate_stats_reply_packet_count_get(obj, &val64);
    out += writer(cookie, "  packet_count (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_aggregate_stats_reply_byte_count_get(obj, &val64);
    out += writer(cookie, "  byte_count (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_aggregate_stats_reply_flow_count_get(obj, &val32);
    out += writer(cookie, "  flow_count (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_aggregate_stats_request_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_aggregate_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_match_t match;
    uint8_t val8;
    of_port_no_t port_no;

    out += writer(cookie, "Object of type of_aggregate_stats_request\n");

    of_aggregate_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_aggregate_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_aggregate_stats_request_match_get(obj, &match);
    out += writer(cookie, "  match (of_match_t):  ");
    out += LOCI_DUMP_match(writer, cookie, match);
    out += writer(cookie, "\n");

    of_aggregate_stats_request_table_id_get(obj, &val8);
    out += writer(cookie, "  table_id (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_aggregate_stats_request_out_port_get(obj, &port_no);
    out += writer(cookie, "  out_port (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    return out;
}

int
of_bad_action_error_msg_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_bad_action_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_bad_action_error_msg\n");

    of_bad_action_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bad_action_error_msg_code_get(obj, &val16);
    out += writer(cookie, "  code (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_bad_action_error_msg_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_bad_request_error_msg_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_bad_request_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_bad_request_error_msg\n");

    of_bad_request_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bad_request_error_msg_code_get(obj, &val16);
    out += writer(cookie, "  code (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_bad_request_error_msg_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_barrier_reply_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_barrier_reply_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_barrier_reply\n");

    of_barrier_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_barrier_request_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_barrier_request_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_barrier_request\n");

    of_barrier_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_bw_clear_data_reply_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_bsn_bw_clear_data_reply_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_bsn_bw_clear_data_reply\n");

    of_bsn_bw_clear_data_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_bw_clear_data_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_bw_clear_data_reply_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_bw_clear_data_reply_status_get(obj, &val32);
    out += writer(cookie, "  status (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_bw_clear_data_request_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_bsn_bw_clear_data_request_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_bsn_bw_clear_data_request\n");

    of_bsn_bw_clear_data_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_bw_clear_data_request_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_bw_clear_data_request_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_bw_enable_get_reply_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_bsn_bw_enable_get_reply_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_bsn_bw_enable_get_reply\n");

    of_bsn_bw_enable_get_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_bw_enable_get_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_bw_enable_get_reply_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_bw_enable_get_reply_enabled_get(obj, &val32);
    out += writer(cookie, "  enabled (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_bw_enable_get_request_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_bsn_bw_enable_get_request_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_bsn_bw_enable_get_request\n");

    of_bsn_bw_enable_get_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_bw_enable_get_request_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_bw_enable_get_request_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_bw_enable_set_reply_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_bsn_bw_enable_set_reply_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_bsn_bw_enable_set_reply\n");

    of_bsn_bw_enable_set_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_bw_enable_set_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_bw_enable_set_reply_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_bw_enable_set_reply_enable_get(obj, &val32);
    out += writer(cookie, "  enable (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_bw_enable_set_reply_status_get(obj, &val32);
    out += writer(cookie, "  status (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_bw_enable_set_request_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_bsn_bw_enable_set_request_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_bsn_bw_enable_set_request\n");

    of_bsn_bw_enable_set_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_bw_enable_set_request_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_bw_enable_set_request_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_bw_enable_set_request_enable_get(obj, &val32);
    out += writer(cookie, "  enable (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_get_interfaces_reply_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_bsn_get_interfaces_reply_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_list_bsn_interface_t list;
    of_bsn_interface_t elt;
    int rv;

    out += writer(cookie, "Object of type of_bsn_get_interfaces_reply\n");

    of_bsn_get_interfaces_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_get_interfaces_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_get_interfaces_reply_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_bsn_interface_t\n");
    of_bsn_get_interfaces_reply_interfaces_bind(obj, &list);
    OF_LIST_BSN_INTERFACE_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_bsn_get_interfaces_request_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_bsn_get_interfaces_request_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_bsn_get_interfaces_request\n");

    of_bsn_get_interfaces_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_get_interfaces_request_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_get_interfaces_request_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_get_ip_mask_reply_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_bsn_get_ip_mask_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint8_t val8;

    out += writer(cookie, "Object of type of_bsn_get_ip_mask_reply\n");

    of_bsn_get_ip_mask_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_get_ip_mask_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_get_ip_mask_reply_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_get_ip_mask_reply_index_get(obj, &val8);
    out += writer(cookie, "  index (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_bsn_get_ip_mask_reply_mask_get(obj, &val32);
    out += writer(cookie, "  mask (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_get_ip_mask_request_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_bsn_get_ip_mask_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint8_t val8;

    out += writer(cookie, "Object of type of_bsn_get_ip_mask_request\n");

    of_bsn_get_ip_mask_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_get_ip_mask_request_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_get_ip_mask_request_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_get_ip_mask_request_index_get(obj, &val8);
    out += writer(cookie, "  index (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_get_l2_table_reply_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_bsn_get_l2_table_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint8_t val8;
    uint16_t val16;

    out += writer(cookie, "Object of type of_bsn_get_l2_table_reply\n");

    of_bsn_get_l2_table_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_get_l2_table_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_get_l2_table_reply_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_get_l2_table_reply_l2_table_enable_get(obj, &val8);
    out += writer(cookie, "  l2_table_enable (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_bsn_get_l2_table_reply_l2_table_priority_get(obj, &val16);
    out += writer(cookie, "  l2_table_priority (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_get_l2_table_request_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_bsn_get_l2_table_request_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_bsn_get_l2_table_request\n");

    of_bsn_get_l2_table_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_get_l2_table_request_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_get_l2_table_request_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_get_mirroring_reply_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_bsn_get_mirroring_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint8_t val8;

    out += writer(cookie, "Object of type of_bsn_get_mirroring_reply\n");

    of_bsn_get_mirroring_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_get_mirroring_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_get_mirroring_reply_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_get_mirroring_reply_report_mirror_ports_get(obj, &val8);
    out += writer(cookie, "  report_mirror_ports (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_get_mirroring_request_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_bsn_get_mirroring_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint8_t val8;

    out += writer(cookie, "Object of type of_bsn_get_mirroring_request\n");

    of_bsn_get_mirroring_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_get_mirroring_request_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_get_mirroring_request_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_get_mirroring_request_report_mirror_ports_get(obj, &val8);
    out += writer(cookie, "  report_mirror_ports (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_header_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_bsn_header_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_bsn_header\n");

    of_bsn_header_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_header_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_header_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_hybrid_get_reply_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_bsn_hybrid_get_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint8_t val8;
    uint16_t val16;

    out += writer(cookie, "Object of type of_bsn_hybrid_get_reply\n");

    of_bsn_hybrid_get_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_hybrid_get_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_hybrid_get_reply_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_hybrid_get_reply_hybrid_enable_get(obj, &val8);
    out += writer(cookie, "  hybrid_enable (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_bsn_hybrid_get_reply_hybrid_version_get(obj, &val16);
    out += writer(cookie, "  hybrid_version (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_hybrid_get_request_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_bsn_hybrid_get_request_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_bsn_hybrid_get_request\n");

    of_bsn_hybrid_get_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_hybrid_get_request_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_hybrid_get_request_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_pdu_rx_reply_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_bsn_pdu_rx_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_port_no_t port_no;
    uint8_t val8;

    out += writer(cookie, "Object of type of_bsn_pdu_rx_reply\n");

    of_bsn_pdu_rx_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_pdu_rx_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_pdu_rx_reply_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_pdu_rx_reply_status_get(obj, &val32);
    out += writer(cookie, "  status (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_pdu_rx_reply_port_no_get(obj, &port_no);
    out += writer(cookie, "  port_no (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_bsn_pdu_rx_reply_slot_num_get(obj, &val8);
    out += writer(cookie, "  slot_num (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_pdu_rx_request_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_bsn_pdu_rx_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_port_no_t port_no;
    uint8_t val8;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_bsn_pdu_rx_request\n");

    of_bsn_pdu_rx_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_pdu_rx_request_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_pdu_rx_request_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_pdu_rx_request_timeout_ms_get(obj, &val32);
    out += writer(cookie, "  timeout_ms (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_pdu_rx_request_port_no_get(obj, &port_no);
    out += writer(cookie, "  port_no (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_bsn_pdu_rx_request_slot_num_get(obj, &val8);
    out += writer(cookie, "  slot_num (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_bsn_pdu_rx_request_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_pdu_rx_timeout_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_bsn_pdu_rx_timeout_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_port_no_t port_no;
    uint8_t val8;

    out += writer(cookie, "Object of type of_bsn_pdu_rx_timeout\n");

    of_bsn_pdu_rx_timeout_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_pdu_rx_timeout_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_pdu_rx_timeout_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_pdu_rx_timeout_port_no_get(obj, &port_no);
    out += writer(cookie, "  port_no (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_bsn_pdu_rx_timeout_slot_num_get(obj, &val8);
    out += writer(cookie, "  slot_num (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_pdu_tx_reply_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_bsn_pdu_tx_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_port_no_t port_no;
    uint8_t val8;

    out += writer(cookie, "Object of type of_bsn_pdu_tx_reply\n");

    of_bsn_pdu_tx_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_pdu_tx_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_pdu_tx_reply_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_pdu_tx_reply_status_get(obj, &val32);
    out += writer(cookie, "  status (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_pdu_tx_reply_port_no_get(obj, &port_no);
    out += writer(cookie, "  port_no (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_bsn_pdu_tx_reply_slot_num_get(obj, &val8);
    out += writer(cookie, "  slot_num (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_pdu_tx_request_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_bsn_pdu_tx_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_port_no_t port_no;
    uint8_t val8;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_bsn_pdu_tx_request\n");

    of_bsn_pdu_tx_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_pdu_tx_request_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_pdu_tx_request_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_pdu_tx_request_tx_interval_ms_get(obj, &val32);
    out += writer(cookie, "  tx_interval_ms (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_pdu_tx_request_port_no_get(obj, &port_no);
    out += writer(cookie, "  port_no (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_bsn_pdu_tx_request_slot_num_get(obj, &val8);
    out += writer(cookie, "  slot_num (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_bsn_pdu_tx_request_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_set_ip_mask_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_bsn_set_ip_mask_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint8_t val8;

    out += writer(cookie, "Object of type of_bsn_set_ip_mask\n");

    of_bsn_set_ip_mask_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_set_ip_mask_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_set_ip_mask_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_set_ip_mask_index_get(obj, &val8);
    out += writer(cookie, "  index (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_bsn_set_ip_mask_mask_get(obj, &val32);
    out += writer(cookie, "  mask (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_set_l2_table_reply_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_bsn_set_l2_table_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint8_t val8;
    uint16_t val16;

    out += writer(cookie, "Object of type of_bsn_set_l2_table_reply\n");

    of_bsn_set_l2_table_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_set_l2_table_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_set_l2_table_reply_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_set_l2_table_reply_l2_table_enable_get(obj, &val8);
    out += writer(cookie, "  l2_table_enable (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_bsn_set_l2_table_reply_l2_table_priority_get(obj, &val16);
    out += writer(cookie, "  l2_table_priority (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_bsn_set_l2_table_reply_status_get(obj, &val32);
    out += writer(cookie, "  status (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_set_l2_table_request_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_bsn_set_l2_table_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint8_t val8;
    uint16_t val16;

    out += writer(cookie, "Object of type of_bsn_set_l2_table_request\n");

    of_bsn_set_l2_table_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_set_l2_table_request_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_set_l2_table_request_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_set_l2_table_request_l2_table_enable_get(obj, &val8);
    out += writer(cookie, "  l2_table_enable (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_bsn_set_l2_table_request_l2_table_priority_get(obj, &val16);
    out += writer(cookie, "  l2_table_priority (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_set_mirroring_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_bsn_set_mirroring_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint8_t val8;

    out += writer(cookie, "Object of type of_bsn_set_mirroring\n");

    of_bsn_set_mirroring_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_set_mirroring_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_set_mirroring_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_set_mirroring_report_mirror_ports_get(obj, &val8);
    out += writer(cookie, "  report_mirror_ports (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_set_pktin_suppression_reply_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_bsn_set_pktin_suppression_reply_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_bsn_set_pktin_suppression_reply\n");

    of_bsn_set_pktin_suppression_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_set_pktin_suppression_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_set_pktin_suppression_reply_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_set_pktin_suppression_reply_status_get(obj, &val32);
    out += writer(cookie, "  status (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_set_pktin_suppression_request_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_bsn_set_pktin_suppression_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint8_t val8;
    uint16_t val16;
    uint64_t val64;

    out += writer(cookie, "Object of type of_bsn_set_pktin_suppression_request\n");

    of_bsn_set_pktin_suppression_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_set_pktin_suppression_request_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_set_pktin_suppression_request_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_set_pktin_suppression_request_enabled_get(obj, &val8);
    out += writer(cookie, "  enabled (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_bsn_set_pktin_suppression_request_idle_timeout_get(obj, &val16);
    out += writer(cookie, "  idle_timeout (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_bsn_set_pktin_suppression_request_hard_timeout_get(obj, &val16);
    out += writer(cookie, "  hard_timeout (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_bsn_set_pktin_suppression_request_priority_get(obj, &val16);
    out += writer(cookie, "  priority (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_bsn_set_pktin_suppression_request_cookie_get(obj, &val64);
    out += writer(cookie, "  cookie (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_shell_command_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_bsn_shell_command_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_bsn_shell_command\n");

    of_bsn_shell_command_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_shell_command_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_shell_command_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_shell_command_service_get(obj, &val32);
    out += writer(cookie, "  service (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_shell_command_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_shell_output_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_bsn_shell_output_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_bsn_shell_output\n");

    of_bsn_shell_output_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_shell_output_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_shell_output_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_shell_output_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_shell_status_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_bsn_shell_status_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_bsn_shell_status\n");

    of_bsn_shell_status_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_shell_status_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_shell_status_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_shell_status_status_get(obj, &val32);
    out += writer(cookie, "  status (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_stats_reply_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_bsn_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    out += writer(cookie, "Object of type of_bsn_stats_reply\n");

    of_bsn_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_bsn_stats_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_stats_reply_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_stats_request_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_bsn_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    out += writer(cookie, "Object of type of_bsn_stats_request\n");

    of_bsn_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_bsn_stats_request_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_stats_request_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_virtual_port_create_reply_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_bsn_virtual_port_create_reply_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_bsn_virtual_port_create_reply\n");

    of_bsn_virtual_port_create_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_virtual_port_create_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_virtual_port_create_reply_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_virtual_port_create_reply_status_get(obj, &val32);
    out += writer(cookie, "  status (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_virtual_port_create_reply_vport_no_get(obj, &val32);
    out += writer(cookie, "  vport_no (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_virtual_port_create_request_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_bsn_virtual_port_create_request_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_bsn_vport_q_in_q_t vport;

    out += writer(cookie, "Object of type of_bsn_virtual_port_create_request\n");

    of_bsn_virtual_port_create_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_virtual_port_create_request_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_virtual_port_create_request_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_virtual_port_create_request_vport_bind(obj, &vport);
    out += of_bsn_vport_q_in_q_OF_VERSION_1_0_dump(writer, cookie, &vport);

    return out;
}

int
of_bsn_virtual_port_remove_reply_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_bsn_virtual_port_remove_reply_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_bsn_virtual_port_remove_reply\n");

    of_bsn_virtual_port_remove_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_virtual_port_remove_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_virtual_port_remove_reply_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_virtual_port_remove_reply_status_get(obj, &val32);
    out += writer(cookie, "  status (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_virtual_port_remove_request_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_bsn_virtual_port_remove_request_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_bsn_virtual_port_remove_request\n");

    of_bsn_virtual_port_remove_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_virtual_port_remove_request_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_virtual_port_remove_request_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_virtual_port_remove_request_vport_no_get(obj, &val32);
    out += writer(cookie, "  vport_no (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_desc_stats_reply_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_desc_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_desc_str_t desc_str;
    of_serial_num_t ser_num;

    out += writer(cookie, "Object of type of_desc_stats_reply\n");

    of_desc_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_desc_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_desc_stats_reply_mfr_desc_get(obj, &desc_str);
    out += writer(cookie, "  mfr_desc (of_desc_str_t):  ");
    out += LOCI_DUMP_desc_str(writer, cookie, desc_str);
    out += writer(cookie, "\n");

    of_desc_stats_reply_hw_desc_get(obj, &desc_str);
    out += writer(cookie, "  hw_desc (of_desc_str_t):  ");
    out += LOCI_DUMP_desc_str(writer, cookie, desc_str);
    out += writer(cookie, "\n");

    of_desc_stats_reply_sw_desc_get(obj, &desc_str);
    out += writer(cookie, "  sw_desc (of_desc_str_t):  ");
    out += LOCI_DUMP_desc_str(writer, cookie, desc_str);
    out += writer(cookie, "\n");

    of_desc_stats_reply_serial_num_get(obj, &ser_num);
    out += writer(cookie, "  serial_num (of_serial_num_t):  ");
    out += LOCI_DUMP_ser_num(writer, cookie, ser_num);
    out += writer(cookie, "\n");

    of_desc_stats_reply_dp_desc_get(obj, &desc_str);
    out += writer(cookie, "  dp_desc (of_desc_str_t):  ");
    out += LOCI_DUMP_desc_str(writer, cookie, desc_str);
    out += writer(cookie, "\n");

    return out;
}

int
of_desc_stats_request_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_desc_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    out += writer(cookie, "Object of type of_desc_stats_request\n");

    of_desc_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_desc_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_echo_reply_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_echo_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_echo_reply\n");

    of_echo_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_echo_reply_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_echo_request_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_echo_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_echo_request\n");

    of_echo_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_echo_request_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_error_msg_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_error_msg\n");

    of_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_experimenter_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_experimenter_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_experimenter\n");

    of_experimenter_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_experimenter_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_experimenter_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_experimenter_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_experimenter_stats_reply_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_experimenter_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_experimenter_stats_reply\n");

    of_experimenter_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_experimenter_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_experimenter_stats_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_experimenter_stats_reply_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_experimenter_stats_request_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_experimenter_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_experimenter_stats_request\n");

    of_experimenter_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_experimenter_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_experimenter_stats_request_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_experimenter_stats_request_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_features_reply_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_features_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint64_t val64;
    uint8_t val8;

    of_list_port_desc_t list;
    of_port_desc_t elt;
    int rv;

    out += writer(cookie, "Object of type of_features_reply\n");

    of_features_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_features_reply_datapath_id_get(obj, &val64);
    out += writer(cookie, "  datapath_id (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_features_reply_n_buffers_get(obj, &val32);
    out += writer(cookie, "  n_buffers (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_features_reply_n_tables_get(obj, &val8);
    out += writer(cookie, "  n_tables (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_features_reply_capabilities_get(obj, &val32);
    out += writer(cookie, "  capabilities (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_features_reply_actions_get(obj, &val32);
    out += writer(cookie, "  actions (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_port_desc_t\n");
    of_features_reply_ports_bind(obj, &list);
    OF_LIST_PORT_DESC_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_features_request_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_features_request_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_features_request\n");

    of_features_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_flow_add_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_flow_add_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_match_t match;
    uint64_t val64;
    uint16_t val16;
    of_port_no_t port_no;

    of_list_action_t list;
    of_action_t elt;
    int rv;

    out += writer(cookie, "Object of type of_flow_add\n");

    of_flow_add_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_add_match_get(obj, &match);
    out += writer(cookie, "  match (of_match_t):  ");
    out += LOCI_DUMP_match(writer, cookie, match);
    out += writer(cookie, "\n");

    of_flow_add_cookie_get(obj, &val64);
    out += writer(cookie, "  cookie (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_flow_add_idle_timeout_get(obj, &val16);
    out += writer(cookie, "  idle_timeout (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_add_hard_timeout_get(obj, &val16);
    out += writer(cookie, "  hard_timeout (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_add_priority_get(obj, &val16);
    out += writer(cookie, "  priority (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_add_buffer_id_get(obj, &val32);
    out += writer(cookie, "  buffer_id (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_add_out_port_get(obj, &port_no);
    out += writer(cookie, "  out_port (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_flow_add_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_action_t\n");
    of_flow_add_actions_bind(obj, &list);
    OF_LIST_ACTION_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_flow_delete_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_flow_delete_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_match_t match;
    uint64_t val64;
    uint16_t val16;
    of_port_no_t port_no;

    of_list_action_t list;
    of_action_t elt;
    int rv;

    out += writer(cookie, "Object of type of_flow_delete\n");

    of_flow_delete_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_delete_match_get(obj, &match);
    out += writer(cookie, "  match (of_match_t):  ");
    out += LOCI_DUMP_match(writer, cookie, match);
    out += writer(cookie, "\n");

    of_flow_delete_cookie_get(obj, &val64);
    out += writer(cookie, "  cookie (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_flow_delete_idle_timeout_get(obj, &val16);
    out += writer(cookie, "  idle_timeout (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_delete_hard_timeout_get(obj, &val16);
    out += writer(cookie, "  hard_timeout (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_delete_priority_get(obj, &val16);
    out += writer(cookie, "  priority (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_delete_buffer_id_get(obj, &val32);
    out += writer(cookie, "  buffer_id (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_delete_out_port_get(obj, &port_no);
    out += writer(cookie, "  out_port (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_flow_delete_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_action_t\n");
    of_flow_delete_actions_bind(obj, &list);
    OF_LIST_ACTION_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_flow_delete_strict_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_flow_delete_strict_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_match_t match;
    uint64_t val64;
    uint16_t val16;
    of_port_no_t port_no;

    of_list_action_t list;
    of_action_t elt;
    int rv;

    out += writer(cookie, "Object of type of_flow_delete_strict\n");

    of_flow_delete_strict_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_delete_strict_match_get(obj, &match);
    out += writer(cookie, "  match (of_match_t):  ");
    out += LOCI_DUMP_match(writer, cookie, match);
    out += writer(cookie, "\n");

    of_flow_delete_strict_cookie_get(obj, &val64);
    out += writer(cookie, "  cookie (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_flow_delete_strict_idle_timeout_get(obj, &val16);
    out += writer(cookie, "  idle_timeout (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_delete_strict_hard_timeout_get(obj, &val16);
    out += writer(cookie, "  hard_timeout (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_delete_strict_priority_get(obj, &val16);
    out += writer(cookie, "  priority (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_delete_strict_buffer_id_get(obj, &val32);
    out += writer(cookie, "  buffer_id (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_delete_strict_out_port_get(obj, &port_no);
    out += writer(cookie, "  out_port (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_flow_delete_strict_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_action_t\n");
    of_flow_delete_strict_actions_bind(obj, &list);
    OF_LIST_ACTION_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_flow_mod_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_flow_mod_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_match_t match;
    uint64_t val64;
    uint16_t val16;
    of_port_no_t port_no;

    of_list_action_t list;
    of_action_t elt;
    int rv;

    out += writer(cookie, "Object of type of_flow_mod\n");

    of_flow_mod_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_mod_match_get(obj, &match);
    out += writer(cookie, "  match (of_match_t):  ");
    out += LOCI_DUMP_match(writer, cookie, match);
    out += writer(cookie, "\n");

    of_flow_mod_cookie_get(obj, &val64);
    out += writer(cookie, "  cookie (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_flow_mod_idle_timeout_get(obj, &val16);
    out += writer(cookie, "  idle_timeout (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_mod_hard_timeout_get(obj, &val16);
    out += writer(cookie, "  hard_timeout (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_mod_priority_get(obj, &val16);
    out += writer(cookie, "  priority (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_mod_buffer_id_get(obj, &val32);
    out += writer(cookie, "  buffer_id (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_mod_out_port_get(obj, &port_no);
    out += writer(cookie, "  out_port (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_flow_mod_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_action_t\n");
    of_flow_mod_actions_bind(obj, &list);
    OF_LIST_ACTION_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_flow_mod_failed_error_msg_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_flow_mod_failed_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_flow_mod_failed_error_msg\n");

    of_flow_mod_failed_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_mod_failed_error_msg_code_get(obj, &val16);
    out += writer(cookie, "  code (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_mod_failed_error_msg_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_flow_modify_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_flow_modify_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_match_t match;
    uint64_t val64;
    uint16_t val16;
    of_port_no_t port_no;

    of_list_action_t list;
    of_action_t elt;
    int rv;

    out += writer(cookie, "Object of type of_flow_modify\n");

    of_flow_modify_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_modify_match_get(obj, &match);
    out += writer(cookie, "  match (of_match_t):  ");
    out += LOCI_DUMP_match(writer, cookie, match);
    out += writer(cookie, "\n");

    of_flow_modify_cookie_get(obj, &val64);
    out += writer(cookie, "  cookie (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_flow_modify_idle_timeout_get(obj, &val16);
    out += writer(cookie, "  idle_timeout (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_modify_hard_timeout_get(obj, &val16);
    out += writer(cookie, "  hard_timeout (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_modify_priority_get(obj, &val16);
    out += writer(cookie, "  priority (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_modify_buffer_id_get(obj, &val32);
    out += writer(cookie, "  buffer_id (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_modify_out_port_get(obj, &port_no);
    out += writer(cookie, "  out_port (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_flow_modify_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_action_t\n");
    of_flow_modify_actions_bind(obj, &list);
    OF_LIST_ACTION_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_flow_modify_strict_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_flow_modify_strict_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_match_t match;
    uint64_t val64;
    uint16_t val16;
    of_port_no_t port_no;

    of_list_action_t list;
    of_action_t elt;
    int rv;

    out += writer(cookie, "Object of type of_flow_modify_strict\n");

    of_flow_modify_strict_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_modify_strict_match_get(obj, &match);
    out += writer(cookie, "  match (of_match_t):  ");
    out += LOCI_DUMP_match(writer, cookie, match);
    out += writer(cookie, "\n");

    of_flow_modify_strict_cookie_get(obj, &val64);
    out += writer(cookie, "  cookie (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_flow_modify_strict_idle_timeout_get(obj, &val16);
    out += writer(cookie, "  idle_timeout (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_modify_strict_hard_timeout_get(obj, &val16);
    out += writer(cookie, "  hard_timeout (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_modify_strict_priority_get(obj, &val16);
    out += writer(cookie, "  priority (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_modify_strict_buffer_id_get(obj, &val32);
    out += writer(cookie, "  buffer_id (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_modify_strict_out_port_get(obj, &port_no);
    out += writer(cookie, "  out_port (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_flow_modify_strict_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_action_t\n");
    of_flow_modify_strict_actions_bind(obj, &list);
    OF_LIST_ACTION_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_flow_removed_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_flow_removed_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_match_t match;
    uint64_t val64;
    uint16_t val16;
    uint8_t val8;

    out += writer(cookie, "Object of type of_flow_removed\n");

    of_flow_removed_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_removed_match_get(obj, &match);
    out += writer(cookie, "  match (of_match_t):  ");
    out += LOCI_DUMP_match(writer, cookie, match);
    out += writer(cookie, "\n");

    of_flow_removed_cookie_get(obj, &val64);
    out += writer(cookie, "  cookie (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_flow_removed_priority_get(obj, &val16);
    out += writer(cookie, "  priority (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_removed_reason_get(obj, &val8);
    out += writer(cookie, "  reason (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_flow_removed_duration_sec_get(obj, &val32);
    out += writer(cookie, "  duration_sec (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_removed_duration_nsec_get(obj, &val32);
    out += writer(cookie, "  duration_nsec (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_removed_idle_timeout_get(obj, &val16);
    out += writer(cookie, "  idle_timeout (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_removed_packet_count_get(obj, &val64);
    out += writer(cookie, "  packet_count (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_flow_removed_byte_count_get(obj, &val64);
    out += writer(cookie, "  byte_count (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    return out;
}

int
of_flow_stats_reply_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_flow_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_list_flow_stats_entry_t list;
    of_flow_stats_entry_t elt;
    int rv;

    out += writer(cookie, "Object of type of_flow_stats_reply\n");

    of_flow_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_flow_stats_entry_t\n");
    of_flow_stats_reply_entries_bind(obj, &list);
    OF_LIST_FLOW_STATS_ENTRY_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_flow_stats_request_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_flow_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_match_t match;
    uint8_t val8;
    of_port_no_t port_no;

    out += writer(cookie, "Object of type of_flow_stats_request\n");

    of_flow_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_stats_request_match_get(obj, &match);
    out += writer(cookie, "  match (of_match_t):  ");
    out += LOCI_DUMP_match(writer, cookie, match);
    out += writer(cookie, "\n");

    of_flow_stats_request_table_id_get(obj, &val8);
    out += writer(cookie, "  table_id (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_flow_stats_request_out_port_get(obj, &port_no);
    out += writer(cookie, "  out_port (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    return out;
}

int
of_get_config_reply_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_get_config_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    out += writer(cookie, "Object of type of_get_config_reply\n");

    of_get_config_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_get_config_reply_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_get_config_reply_miss_send_len_get(obj, &val16);
    out += writer(cookie, "  miss_send_len (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_get_config_request_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_get_config_request_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_get_config_request\n");

    of_get_config_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_hello_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_hello_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_hello\n");

    of_hello_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_hello_failed_error_msg_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_hello_failed_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_hello_failed_error_msg\n");

    of_hello_failed_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_hello_failed_error_msg_code_get(obj, &val16);
    out += writer(cookie, "  code (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_hello_failed_error_msg_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_nicira_controller_role_reply_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_nicira_controller_role_reply_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_nicira_controller_role_reply\n");

    of_nicira_controller_role_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_nicira_controller_role_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_nicira_controller_role_reply_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_nicira_controller_role_reply_role_get(obj, &val32);
    out += writer(cookie, "  role (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_nicira_controller_role_request_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_nicira_controller_role_request_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_nicira_controller_role_request\n");

    of_nicira_controller_role_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_nicira_controller_role_request_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_nicira_controller_role_request_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_nicira_controller_role_request_role_get(obj, &val32);
    out += writer(cookie, "  role (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_nicira_header_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_nicira_header_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_nicira_header\n");

    of_nicira_header_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_nicira_header_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_nicira_header_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_packet_in_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_packet_in_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_port_no_t port_no;
    uint8_t val8;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_packet_in\n");

    of_packet_in_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_packet_in_buffer_id_get(obj, &val32);
    out += writer(cookie, "  buffer_id (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_packet_in_total_len_get(obj, &val16);
    out += writer(cookie, "  total_len (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_packet_in_in_port_get(obj, &port_no);
    out += writer(cookie, "  in_port (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_packet_in_reason_get(obj, &val8);
    out += writer(cookie, "  reason (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_packet_in_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_packet_out_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_packet_out_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_port_no_t port_no;

    of_list_action_t list;
    of_action_t elt;
    int rv;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_packet_out\n");

    of_packet_out_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_packet_out_buffer_id_get(obj, &val32);
    out += writer(cookie, "  buffer_id (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_packet_out_in_port_get(obj, &port_no);
    out += writer(cookie, "  in_port (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_action_t\n");
    of_packet_out_actions_bind(obj, &list);
    OF_LIST_ACTION_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    of_packet_out_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_port_mod_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_port_mod_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_port_no_t port_no;
    of_mac_addr_t mac_addr;

    out += writer(cookie, "Object of type of_port_mod\n");

    of_port_mod_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_port_mod_port_no_get(obj, &port_no);
    out += writer(cookie, "  port_no (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_port_mod_hw_addr_get(obj, &mac_addr);
    out += writer(cookie, "  hw_addr (of_mac_addr_t):  ");
    out += LOCI_DUMP_mac(writer, cookie, mac_addr);
    out += writer(cookie, "\n");

    of_port_mod_config_get(obj, &val32);
    out += writer(cookie, "  config (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_port_mod_mask_get(obj, &val32);
    out += writer(cookie, "  mask (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_port_mod_advertise_get(obj, &val32);
    out += writer(cookie, "  advertise (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_port_mod_failed_error_msg_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_port_mod_failed_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_port_mod_failed_error_msg\n");

    of_port_mod_failed_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_port_mod_failed_error_msg_code_get(obj, &val16);
    out += writer(cookie, "  code (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_port_mod_failed_error_msg_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_port_stats_reply_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_port_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_list_port_stats_entry_t list;
    of_port_stats_entry_t elt;
    int rv;

    out += writer(cookie, "Object of type of_port_stats_reply\n");

    of_port_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_port_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_port_stats_entry_t\n");
    of_port_stats_reply_entries_bind(obj, &list);
    OF_LIST_PORT_STATS_ENTRY_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_port_stats_request_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_port_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_port_no_t port_no;

    out += writer(cookie, "Object of type of_port_stats_request\n");

    of_port_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_port_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_port_stats_request_port_no_get(obj, &port_no);
    out += writer(cookie, "  port_no (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    return out;
}

int
of_port_status_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_port_status_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint8_t val8;

    of_port_desc_t port_desc;

    out += writer(cookie, "Object of type of_port_status\n");

    of_port_status_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_port_status_reason_get(obj, &val8);
    out += writer(cookie, "  reason (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_port_status_desc_bind(obj, &port_desc);
    out += of_port_desc_OF_VERSION_1_0_dump(writer, cookie, &port_desc);

    return out;
}

int
of_queue_get_config_reply_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_queue_get_config_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_port_no_t port_no;

    of_list_packet_queue_t list;
    of_packet_queue_t elt;
    int rv;

    out += writer(cookie, "Object of type of_queue_get_config_reply\n");

    of_queue_get_config_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_queue_get_config_reply_port_get(obj, &port_no);
    out += writer(cookie, "  port (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_packet_queue_t\n");
    of_queue_get_config_reply_queues_bind(obj, &list);
    OF_LIST_PACKET_QUEUE_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_queue_get_config_request_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_queue_get_config_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_port_no_t port_no;

    out += writer(cookie, "Object of type of_queue_get_config_request\n");

    of_queue_get_config_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_queue_get_config_request_port_get(obj, &port_no);
    out += writer(cookie, "  port (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    return out;
}

int
of_queue_op_failed_error_msg_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_queue_op_failed_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_queue_op_failed_error_msg\n");

    of_queue_op_failed_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_queue_op_failed_error_msg_code_get(obj, &val16);
    out += writer(cookie, "  code (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_queue_op_failed_error_msg_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_queue_stats_reply_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_queue_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_list_queue_stats_entry_t list;
    of_queue_stats_entry_t elt;
    int rv;

    out += writer(cookie, "Object of type of_queue_stats_reply\n");

    of_queue_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_queue_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_queue_stats_entry_t\n");
    of_queue_stats_reply_entries_bind(obj, &list);
    OF_LIST_QUEUE_STATS_ENTRY_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_queue_stats_request_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_queue_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_port_no_t port_no;

    out += writer(cookie, "Object of type of_queue_stats_request\n");

    of_queue_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_queue_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_queue_stats_request_port_no_get(obj, &port_no);
    out += writer(cookie, "  port_no (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_queue_stats_request_queue_id_get(obj, &val32);
    out += writer(cookie, "  queue_id (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_set_config_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_set_config_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    out += writer(cookie, "Object of type of_set_config\n");

    of_set_config_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_set_config_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_set_config_miss_send_len_get(obj, &val16);
    out += writer(cookie, "  miss_send_len (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_stats_reply_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    out += writer(cookie, "Object of type of_stats_reply\n");

    of_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_stats_request_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    out += writer(cookie, "Object of type of_stats_request\n");

    of_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_table_mod_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_table_mod_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint8_t val8;

    out += writer(cookie, "Object of type of_table_mod\n");

    of_table_mod_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_table_mod_table_id_get(obj, &val8);
    out += writer(cookie, "  table_id (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_table_mod_config_get(obj, &val32);
    out += writer(cookie, "  config (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_table_stats_reply_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_table_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_list_table_stats_entry_t list;
    of_table_stats_entry_t elt;
    int rv;

    out += writer(cookie, "Object of type of_table_stats_reply\n");

    of_table_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_table_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_table_stats_entry_t\n");
    of_table_stats_reply_entries_bind(obj, &list);
    OF_LIST_TABLE_STATS_ENTRY_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_table_stats_request_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_table_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    out += writer(cookie, "Object of type of_table_stats_request\n");

    of_table_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_table_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_action_bsn_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_action_bsn_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_action_bsn\n");

    of_action_bsn_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_action_bsn_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_action_bsn_mirror_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_action_bsn_mirror_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint8_t val8;

    out += writer(cookie, "Object of type of_action_bsn_mirror\n");

    of_action_bsn_mirror_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_action_bsn_mirror_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_action_bsn_mirror_dest_port_get(obj, &val32);
    out += writer(cookie, "  dest_port (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_action_bsn_mirror_vlan_tag_get(obj, &val32);
    out += writer(cookie, "  vlan_tag (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_action_bsn_mirror_copy_stage_get(obj, &val8);
    out += writer(cookie, "  copy_stage (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_action_bsn_set_tunnel_dst_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_action_bsn_set_tunnel_dst_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_action_bsn_set_tunnel_dst\n");

    of_action_bsn_set_tunnel_dst_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_action_bsn_set_tunnel_dst_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_action_bsn_set_tunnel_dst_dst_get(obj, &val32);
    out += writer(cookie, "  dst (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_action_enqueue_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_action_enqueue_t *obj)
{
    int out = 0;
    of_port_no_t port_no;
    uint32_t val32;

    out += writer(cookie, "Object of type of_action_enqueue\n");

    of_action_enqueue_port_get(obj, &port_no);
    out += writer(cookie, "  port (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_action_enqueue_queue_id_get(obj, &val32);
    out += writer(cookie, "  queue_id (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_action_experimenter_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_action_experimenter_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_action_experimenter\n");

    of_action_experimenter_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_action_experimenter_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_action_header_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_action_header_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_action_header\n");

    return out;
}

int
of_action_nicira_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_action_nicira_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    out += writer(cookie, "Object of type of_action_nicira\n");

    of_action_nicira_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_action_nicira_subtype_get(obj, &val16);
    out += writer(cookie, "  subtype (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_action_nicira_dec_ttl_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_action_nicira_dec_ttl_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    out += writer(cookie, "Object of type of_action_nicira_dec_ttl\n");

    of_action_nicira_dec_ttl_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_action_nicira_dec_ttl_subtype_get(obj, &val16);
    out += writer(cookie, "  subtype (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_action_output_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_action_output_t *obj)
{
    int out = 0;
    of_port_no_t port_no;
    uint16_t val16;

    out += writer(cookie, "Object of type of_action_output\n");

    of_action_output_port_get(obj, &port_no);
    out += writer(cookie, "  port (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_action_output_max_len_get(obj, &val16);
    out += writer(cookie, "  max_len (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_action_set_dl_dst_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_action_set_dl_dst_t *obj)
{
    int out = 0;
    of_mac_addr_t mac_addr;

    out += writer(cookie, "Object of type of_action_set_dl_dst\n");

    of_action_set_dl_dst_dl_addr_get(obj, &mac_addr);
    out += writer(cookie, "  dl_addr (of_mac_addr_t):  ");
    out += LOCI_DUMP_mac(writer, cookie, mac_addr);
    out += writer(cookie, "\n");

    return out;
}

int
of_action_set_dl_src_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_action_set_dl_src_t *obj)
{
    int out = 0;
    of_mac_addr_t mac_addr;

    out += writer(cookie, "Object of type of_action_set_dl_src\n");

    of_action_set_dl_src_dl_addr_get(obj, &mac_addr);
    out += writer(cookie, "  dl_addr (of_mac_addr_t):  ");
    out += LOCI_DUMP_mac(writer, cookie, mac_addr);
    out += writer(cookie, "\n");

    return out;
}

int
of_action_set_nw_dst_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_action_set_nw_dst_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_action_set_nw_dst\n");

    of_action_set_nw_dst_nw_addr_get(obj, &val32);
    out += writer(cookie, "  nw_addr (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_action_set_nw_src_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_action_set_nw_src_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_action_set_nw_src\n");

    of_action_set_nw_src_nw_addr_get(obj, &val32);
    out += writer(cookie, "  nw_addr (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_action_set_nw_tos_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_action_set_nw_tos_t *obj)
{
    int out = 0;
    uint8_t val8;

    out += writer(cookie, "Object of type of_action_set_nw_tos\n");

    of_action_set_nw_tos_nw_tos_get(obj, &val8);
    out += writer(cookie, "  nw_tos (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_action_set_tp_dst_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_action_set_tp_dst_t *obj)
{
    int out = 0;
    uint16_t val16;

    out += writer(cookie, "Object of type of_action_set_tp_dst\n");

    of_action_set_tp_dst_tp_port_get(obj, &val16);
    out += writer(cookie, "  tp_port (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_action_set_tp_src_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_action_set_tp_src_t *obj)
{
    int out = 0;
    uint16_t val16;

    out += writer(cookie, "Object of type of_action_set_tp_src\n");

    of_action_set_tp_src_tp_port_get(obj, &val16);
    out += writer(cookie, "  tp_port (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_action_set_vlan_pcp_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_action_set_vlan_pcp_t *obj)
{
    int out = 0;
    uint8_t val8;

    out += writer(cookie, "Object of type of_action_set_vlan_pcp\n");

    of_action_set_vlan_pcp_vlan_pcp_get(obj, &val8);
    out += writer(cookie, "  vlan_pcp (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_action_set_vlan_vid_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_action_set_vlan_vid_t *obj)
{
    int out = 0;
    uint16_t val16;

    out += writer(cookie, "Object of type of_action_set_vlan_vid\n");

    of_action_set_vlan_vid_vlan_vid_get(obj, &val16);
    out += writer(cookie, "  vlan_vid (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_action_strip_vlan_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_action_strip_vlan_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_action_strip_vlan\n");

    return out;
}

int
of_bsn_interface_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_bsn_interface_t *obj)
{
    int out = 0;
    of_mac_addr_t mac_addr;
    of_port_name_t port_name;
    of_ipv4_t ipv4;

    out += writer(cookie, "Object of type of_bsn_interface\n");

    of_bsn_interface_hw_addr_get(obj, &mac_addr);
    out += writer(cookie, "  hw_addr (of_mac_addr_t):  ");
    out += LOCI_DUMP_mac(writer, cookie, mac_addr);
    out += writer(cookie, "\n");

    of_bsn_interface_name_get(obj, &port_name);
    out += writer(cookie, "  name (of_port_name_t):  ");
    out += LOCI_DUMP_port_name(writer, cookie, port_name);
    out += writer(cookie, "\n");

    of_bsn_interface_ipv4_addr_get(obj, &ipv4);
    out += writer(cookie, "  ipv4_addr (of_ipv4_t):  ");
    out += LOCI_DUMP_ipv4(writer, cookie, ipv4);
    out += writer(cookie, "\n");

    of_bsn_interface_ipv4_netmask_get(obj, &ipv4);
    out += writer(cookie, "  ipv4_netmask (of_ipv4_t):  ");
    out += LOCI_DUMP_ipv4(writer, cookie, ipv4);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_vport_header_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_bsn_vport_header_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_bsn_vport_header\n");

    return out;
}

int
of_bsn_vport_q_in_q_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_bsn_vport_q_in_q_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_port_name_t port_name;

    out += writer(cookie, "Object of type of_bsn_vport_q_in_q\n");

    of_bsn_vport_q_in_q_port_no_get(obj, &val32);
    out += writer(cookie, "  port_no (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_vport_q_in_q_ingress_tpid_get(obj, &val16);
    out += writer(cookie, "  ingress_tpid (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_bsn_vport_q_in_q_ingress_vlan_id_get(obj, &val16);
    out += writer(cookie, "  ingress_vlan_id (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_bsn_vport_q_in_q_egress_tpid_get(obj, &val16);
    out += writer(cookie, "  egress_tpid (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_bsn_vport_q_in_q_egress_vlan_id_get(obj, &val16);
    out += writer(cookie, "  egress_vlan_id (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_bsn_vport_q_in_q_if_name_get(obj, &port_name);
    out += writer(cookie, "  if_name (of_port_name_t):  ");
    out += LOCI_DUMP_port_name(writer, cookie, port_name);
    out += writer(cookie, "\n");

    return out;
}

int
of_flow_stats_entry_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_flow_stats_entry_t *obj)
{
    int out = 0;
    uint8_t val8;
    of_match_t match;
    uint32_t val32;
    uint16_t val16;
    uint64_t val64;

    of_list_action_t list;
    of_action_t elt;
    int rv;

    out += writer(cookie, "Object of type of_flow_stats_entry\n");

    of_flow_stats_entry_table_id_get(obj, &val8);
    out += writer(cookie, "  table_id (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_flow_stats_entry_match_get(obj, &match);
    out += writer(cookie, "  match (of_match_t):  ");
    out += LOCI_DUMP_match(writer, cookie, match);
    out += writer(cookie, "\n");

    of_flow_stats_entry_duration_sec_get(obj, &val32);
    out += writer(cookie, "  duration_sec (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_stats_entry_duration_nsec_get(obj, &val32);
    out += writer(cookie, "  duration_nsec (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_stats_entry_priority_get(obj, &val16);
    out += writer(cookie, "  priority (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_stats_entry_idle_timeout_get(obj, &val16);
    out += writer(cookie, "  idle_timeout (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_stats_entry_hard_timeout_get(obj, &val16);
    out += writer(cookie, "  hard_timeout (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_stats_entry_cookie_get(obj, &val64);
    out += writer(cookie, "  cookie (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_flow_stats_entry_packet_count_get(obj, &val64);
    out += writer(cookie, "  packet_count (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_flow_stats_entry_byte_count_get(obj, &val64);
    out += writer(cookie, "  byte_count (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_action_t\n");
    of_flow_stats_entry_actions_bind(obj, &list);
    OF_LIST_ACTION_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_header_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_header_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_header\n");

    of_header_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_match_v1_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_match_v1_t *obj)
{
    int out = 0;
    of_wc_bmap_t wc_bmap;
    of_port_no_t port_no;
    of_mac_addr_t mac_addr;
    uint16_t val16;
    uint8_t val8;
    of_ipv4_t ipv4;

    out += writer(cookie, "Object of type of_match_v1\n");

    of_match_v1_wildcards_get(obj, &wc_bmap);
    out += writer(cookie, "  wildcards (of_wc_bmap_t):  ");
    out += LOCI_DUMP_wc_bmap(writer, cookie, wc_bmap);
    out += writer(cookie, "\n");

    of_match_v1_in_port_get(obj, &port_no);
    out += writer(cookie, "  in_port (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_match_v1_eth_src_get(obj, &mac_addr);
    out += writer(cookie, "  eth_src (of_mac_addr_t):  ");
    out += LOCI_DUMP_mac(writer, cookie, mac_addr);
    out += writer(cookie, "\n");

    of_match_v1_eth_dst_get(obj, &mac_addr);
    out += writer(cookie, "  eth_dst (of_mac_addr_t):  ");
    out += LOCI_DUMP_mac(writer, cookie, mac_addr);
    out += writer(cookie, "\n");

    of_match_v1_vlan_vid_get(obj, &val16);
    out += writer(cookie, "  vlan_vid (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_match_v1_vlan_pcp_get(obj, &val8);
    out += writer(cookie, "  vlan_pcp (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_match_v1_eth_type_get(obj, &val16);
    out += writer(cookie, "  eth_type (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_match_v1_ip_dscp_get(obj, &val8);
    out += writer(cookie, "  ip_dscp (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_match_v1_ip_proto_get(obj, &val8);
    out += writer(cookie, "  ip_proto (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_match_v1_ipv4_src_get(obj, &ipv4);
    out += writer(cookie, "  ipv4_src (of_ipv4_t):  ");
    out += LOCI_DUMP_ipv4(writer, cookie, ipv4);
    out += writer(cookie, "\n");

    of_match_v1_ipv4_dst_get(obj, &ipv4);
    out += writer(cookie, "  ipv4_dst (of_ipv4_t):  ");
    out += LOCI_DUMP_ipv4(writer, cookie, ipv4);
    out += writer(cookie, "\n");

    of_match_v1_tcp_src_get(obj, &val16);
    out += writer(cookie, "  tcp_src (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_match_v1_tcp_dst_get(obj, &val16);
    out += writer(cookie, "  tcp_dst (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_packet_queue_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_packet_queue_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_list_queue_prop_t list;
    of_queue_prop_t elt;
    int rv;

    out += writer(cookie, "Object of type of_packet_queue\n");

    of_packet_queue_queue_id_get(obj, &val32);
    out += writer(cookie, "  queue_id (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_queue_prop_t\n");
    of_packet_queue_properties_bind(obj, &list);
    OF_LIST_QUEUE_PROP_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_port_desc_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_port_desc_t *obj)
{
    int out = 0;
    of_port_no_t port_no;
    of_mac_addr_t mac_addr;
    of_port_name_t port_name;
    uint32_t val32;

    out += writer(cookie, "Object of type of_port_desc\n");

    of_port_desc_port_no_get(obj, &port_no);
    out += writer(cookie, "  port_no (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_port_desc_hw_addr_get(obj, &mac_addr);
    out += writer(cookie, "  hw_addr (of_mac_addr_t):  ");
    out += LOCI_DUMP_mac(writer, cookie, mac_addr);
    out += writer(cookie, "\n");

    of_port_desc_name_get(obj, &port_name);
    out += writer(cookie, "  name (of_port_name_t):  ");
    out += LOCI_DUMP_port_name(writer, cookie, port_name);
    out += writer(cookie, "\n");

    of_port_desc_config_get(obj, &val32);
    out += writer(cookie, "  config (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_port_desc_state_get(obj, &val32);
    out += writer(cookie, "  state (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_port_desc_curr_get(obj, &val32);
    out += writer(cookie, "  curr (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_port_desc_advertised_get(obj, &val32);
    out += writer(cookie, "  advertised (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_port_desc_supported_get(obj, &val32);
    out += writer(cookie, "  supported (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_port_desc_peer_get(obj, &val32);
    out += writer(cookie, "  peer (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_port_stats_entry_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_port_stats_entry_t *obj)
{
    int out = 0;
    of_port_no_t port_no;
    uint64_t val64;

    out += writer(cookie, "Object of type of_port_stats_entry\n");

    of_port_stats_entry_port_no_get(obj, &port_no);
    out += writer(cookie, "  port_no (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_port_stats_entry_rx_packets_get(obj, &val64);
    out += writer(cookie, "  rx_packets (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_port_stats_entry_tx_packets_get(obj, &val64);
    out += writer(cookie, "  tx_packets (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_port_stats_entry_rx_bytes_get(obj, &val64);
    out += writer(cookie, "  rx_bytes (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_port_stats_entry_tx_bytes_get(obj, &val64);
    out += writer(cookie, "  tx_bytes (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_port_stats_entry_rx_dropped_get(obj, &val64);
    out += writer(cookie, "  rx_dropped (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_port_stats_entry_tx_dropped_get(obj, &val64);
    out += writer(cookie, "  tx_dropped (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_port_stats_entry_rx_errors_get(obj, &val64);
    out += writer(cookie, "  rx_errors (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_port_stats_entry_tx_errors_get(obj, &val64);
    out += writer(cookie, "  tx_errors (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_port_stats_entry_rx_frame_err_get(obj, &val64);
    out += writer(cookie, "  rx_frame_err (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_port_stats_entry_rx_over_err_get(obj, &val64);
    out += writer(cookie, "  rx_over_err (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_port_stats_entry_rx_crc_err_get(obj, &val64);
    out += writer(cookie, "  rx_crc_err (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_port_stats_entry_collisions_get(obj, &val64);
    out += writer(cookie, "  collisions (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    return out;
}

int
of_queue_prop_header_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_queue_prop_header_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_queue_prop_header\n");

    return out;
}

int
of_queue_prop_min_rate_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_queue_prop_min_rate_t *obj)
{
    int out = 0;
    uint16_t val16;

    out += writer(cookie, "Object of type of_queue_prop_min_rate\n");

    of_queue_prop_min_rate_rate_get(obj, &val16);
    out += writer(cookie, "  rate (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_queue_stats_entry_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_queue_stats_entry_t *obj)
{
    int out = 0;
    of_port_no_t port_no;
    uint32_t val32;
    uint64_t val64;

    out += writer(cookie, "Object of type of_queue_stats_entry\n");

    of_queue_stats_entry_port_no_get(obj, &port_no);
    out += writer(cookie, "  port_no (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_queue_stats_entry_queue_id_get(obj, &val32);
    out += writer(cookie, "  queue_id (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_queue_stats_entry_tx_bytes_get(obj, &val64);
    out += writer(cookie, "  tx_bytes (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_queue_stats_entry_tx_packets_get(obj, &val64);
    out += writer(cookie, "  tx_packets (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_queue_stats_entry_tx_errors_get(obj, &val64);
    out += writer(cookie, "  tx_errors (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    return out;
}

int
of_table_stats_entry_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_table_stats_entry_t *obj)
{
    int out = 0;
    uint8_t val8;
    of_table_name_t table_name;
    of_wc_bmap_t wc_bmap;
    uint32_t val32;
    uint64_t val64;

    out += writer(cookie, "Object of type of_table_stats_entry\n");

    of_table_stats_entry_table_id_get(obj, &val8);
    out += writer(cookie, "  table_id (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_table_stats_entry_name_get(obj, &table_name);
    out += writer(cookie, "  name (of_table_name_t):  ");
    out += LOCI_DUMP_tab_name(writer, cookie, table_name);
    out += writer(cookie, "\n");

    of_table_stats_entry_wildcards_get(obj, &wc_bmap);
    out += writer(cookie, "  wildcards (of_wc_bmap_t):  ");
    out += LOCI_DUMP_wc_bmap(writer, cookie, wc_bmap);
    out += writer(cookie, "\n");

    of_table_stats_entry_max_entries_get(obj, &val32);
    out += writer(cookie, "  max_entries (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_table_stats_entry_active_count_get(obj, &val32);
    out += writer(cookie, "  active_count (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_table_stats_entry_lookup_count_get(obj, &val64);
    out += writer(cookie, "  lookup_count (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_table_stats_entry_matched_count_get(obj, &val64);
    out += writer(cookie, "  matched_count (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    return out;
}

int
of_list_action_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_list_action_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_list_action\n");

    return out;
}

int
of_list_bsn_interface_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_list_bsn_interface_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_list_bsn_interface\n");

    return out;
}

int
of_list_flow_stats_entry_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_list_flow_stats_entry_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_list_flow_stats_entry\n");

    return out;
}

int
of_list_packet_queue_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_list_packet_queue_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_list_packet_queue\n");

    return out;
}

int
of_list_port_desc_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_list_port_desc_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_list_port_desc\n");

    return out;
}

int
of_list_port_stats_entry_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_list_port_stats_entry_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_list_port_stats_entry\n");

    return out;
}

int
of_list_queue_prop_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_list_queue_prop_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_list_queue_prop\n");

    return out;
}

int
of_list_queue_stats_entry_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_list_queue_stats_entry_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_list_queue_stats_entry\n");

    return out;
}

int
of_list_table_stats_entry_OF_VERSION_1_0_dump(loci_writer_f writer, void* cookie, of_list_table_stats_entry_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_list_table_stats_entry\n");

    return out;
}

int
of_aggregate_stats_reply_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_aggregate_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    uint64_t val64;

    out += writer(cookie, "Object of type of_aggregate_stats_reply\n");

    of_aggregate_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_aggregate_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_aggregate_stats_reply_packet_count_get(obj, &val64);
    out += writer(cookie, "  packet_count (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_aggregate_stats_reply_byte_count_get(obj, &val64);
    out += writer(cookie, "  byte_count (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_aggregate_stats_reply_flow_count_get(obj, &val32);
    out += writer(cookie, "  flow_count (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_aggregate_stats_request_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_aggregate_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    uint8_t val8;
    of_port_no_t port_no;
    uint64_t val64;
    of_match_t match;

    out += writer(cookie, "Object of type of_aggregate_stats_request\n");

    of_aggregate_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_aggregate_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_aggregate_stats_request_table_id_get(obj, &val8);
    out += writer(cookie, "  table_id (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_aggregate_stats_request_out_port_get(obj, &port_no);
    out += writer(cookie, "  out_port (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_aggregate_stats_request_out_group_get(obj, &val32);
    out += writer(cookie, "  out_group (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_aggregate_stats_request_cookie_get(obj, &val64);
    out += writer(cookie, "  cookie (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_aggregate_stats_request_cookie_mask_get(obj, &val64);
    out += writer(cookie, "  cookie_mask (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_aggregate_stats_request_match_get(obj, &match);
    out += writer(cookie, "  match (of_match_t):  ");
    out += LOCI_DUMP_match(writer, cookie, match);
    out += writer(cookie, "\n");

    return out;
}

int
of_bad_action_error_msg_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_bad_action_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_bad_action_error_msg\n");

    of_bad_action_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bad_action_error_msg_code_get(obj, &val16);
    out += writer(cookie, "  code (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_bad_action_error_msg_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_bad_instruction_error_msg_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_bad_instruction_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_bad_instruction_error_msg\n");

    of_bad_instruction_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bad_instruction_error_msg_code_get(obj, &val16);
    out += writer(cookie, "  code (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_bad_instruction_error_msg_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_bad_match_error_msg_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_bad_match_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_bad_match_error_msg\n");

    of_bad_match_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bad_match_error_msg_code_get(obj, &val16);
    out += writer(cookie, "  code (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_bad_match_error_msg_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_bad_request_error_msg_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_bad_request_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_bad_request_error_msg\n");

    of_bad_request_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bad_request_error_msg_code_get(obj, &val16);
    out += writer(cookie, "  code (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_bad_request_error_msg_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_barrier_reply_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_barrier_reply_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_barrier_reply\n");

    of_barrier_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_barrier_request_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_barrier_request_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_barrier_request\n");

    of_barrier_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_bw_clear_data_reply_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_bsn_bw_clear_data_reply_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_bsn_bw_clear_data_reply\n");

    of_bsn_bw_clear_data_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_bw_clear_data_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_bw_clear_data_reply_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_bw_clear_data_reply_status_get(obj, &val32);
    out += writer(cookie, "  status (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_bw_clear_data_request_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_bsn_bw_clear_data_request_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_bsn_bw_clear_data_request\n");

    of_bsn_bw_clear_data_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_bw_clear_data_request_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_bw_clear_data_request_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_bw_enable_get_reply_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_bsn_bw_enable_get_reply_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_bsn_bw_enable_get_reply\n");

    of_bsn_bw_enable_get_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_bw_enable_get_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_bw_enable_get_reply_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_bw_enable_get_reply_enabled_get(obj, &val32);
    out += writer(cookie, "  enabled (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_bw_enable_get_request_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_bsn_bw_enable_get_request_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_bsn_bw_enable_get_request\n");

    of_bsn_bw_enable_get_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_bw_enable_get_request_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_bw_enable_get_request_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_bw_enable_set_reply_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_bsn_bw_enable_set_reply_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_bsn_bw_enable_set_reply\n");

    of_bsn_bw_enable_set_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_bw_enable_set_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_bw_enable_set_reply_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_bw_enable_set_reply_enable_get(obj, &val32);
    out += writer(cookie, "  enable (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_bw_enable_set_reply_status_get(obj, &val32);
    out += writer(cookie, "  status (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_bw_enable_set_request_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_bsn_bw_enable_set_request_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_bsn_bw_enable_set_request\n");

    of_bsn_bw_enable_set_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_bw_enable_set_request_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_bw_enable_set_request_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_bw_enable_set_request_enable_get(obj, &val32);
    out += writer(cookie, "  enable (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_get_interfaces_reply_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_bsn_get_interfaces_reply_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_list_bsn_interface_t list;
    of_bsn_interface_t elt;
    int rv;

    out += writer(cookie, "Object of type of_bsn_get_interfaces_reply\n");

    of_bsn_get_interfaces_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_get_interfaces_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_get_interfaces_reply_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_bsn_interface_t\n");
    of_bsn_get_interfaces_reply_interfaces_bind(obj, &list);
    OF_LIST_BSN_INTERFACE_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_bsn_get_interfaces_request_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_bsn_get_interfaces_request_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_bsn_get_interfaces_request\n");

    of_bsn_get_interfaces_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_get_interfaces_request_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_get_interfaces_request_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_get_mirroring_reply_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_bsn_get_mirroring_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint8_t val8;

    out += writer(cookie, "Object of type of_bsn_get_mirroring_reply\n");

    of_bsn_get_mirroring_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_get_mirroring_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_get_mirroring_reply_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_get_mirroring_reply_report_mirror_ports_get(obj, &val8);
    out += writer(cookie, "  report_mirror_ports (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_get_mirroring_request_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_bsn_get_mirroring_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint8_t val8;

    out += writer(cookie, "Object of type of_bsn_get_mirroring_request\n");

    of_bsn_get_mirroring_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_get_mirroring_request_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_get_mirroring_request_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_get_mirroring_request_report_mirror_ports_get(obj, &val8);
    out += writer(cookie, "  report_mirror_ports (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_header_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_bsn_header_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_bsn_header\n");

    of_bsn_header_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_header_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_header_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_pdu_rx_reply_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_bsn_pdu_rx_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_port_no_t port_no;
    uint8_t val8;

    out += writer(cookie, "Object of type of_bsn_pdu_rx_reply\n");

    of_bsn_pdu_rx_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_pdu_rx_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_pdu_rx_reply_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_pdu_rx_reply_status_get(obj, &val32);
    out += writer(cookie, "  status (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_pdu_rx_reply_port_no_get(obj, &port_no);
    out += writer(cookie, "  port_no (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_bsn_pdu_rx_reply_slot_num_get(obj, &val8);
    out += writer(cookie, "  slot_num (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_pdu_rx_request_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_bsn_pdu_rx_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_port_no_t port_no;
    uint8_t val8;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_bsn_pdu_rx_request\n");

    of_bsn_pdu_rx_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_pdu_rx_request_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_pdu_rx_request_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_pdu_rx_request_timeout_ms_get(obj, &val32);
    out += writer(cookie, "  timeout_ms (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_pdu_rx_request_port_no_get(obj, &port_no);
    out += writer(cookie, "  port_no (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_bsn_pdu_rx_request_slot_num_get(obj, &val8);
    out += writer(cookie, "  slot_num (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_bsn_pdu_rx_request_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_pdu_rx_timeout_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_bsn_pdu_rx_timeout_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_port_no_t port_no;
    uint8_t val8;

    out += writer(cookie, "Object of type of_bsn_pdu_rx_timeout\n");

    of_bsn_pdu_rx_timeout_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_pdu_rx_timeout_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_pdu_rx_timeout_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_pdu_rx_timeout_port_no_get(obj, &port_no);
    out += writer(cookie, "  port_no (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_bsn_pdu_rx_timeout_slot_num_get(obj, &val8);
    out += writer(cookie, "  slot_num (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_pdu_tx_reply_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_bsn_pdu_tx_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_port_no_t port_no;
    uint8_t val8;

    out += writer(cookie, "Object of type of_bsn_pdu_tx_reply\n");

    of_bsn_pdu_tx_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_pdu_tx_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_pdu_tx_reply_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_pdu_tx_reply_status_get(obj, &val32);
    out += writer(cookie, "  status (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_pdu_tx_reply_port_no_get(obj, &port_no);
    out += writer(cookie, "  port_no (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_bsn_pdu_tx_reply_slot_num_get(obj, &val8);
    out += writer(cookie, "  slot_num (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_pdu_tx_request_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_bsn_pdu_tx_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_port_no_t port_no;
    uint8_t val8;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_bsn_pdu_tx_request\n");

    of_bsn_pdu_tx_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_pdu_tx_request_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_pdu_tx_request_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_pdu_tx_request_tx_interval_ms_get(obj, &val32);
    out += writer(cookie, "  tx_interval_ms (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_pdu_tx_request_port_no_get(obj, &port_no);
    out += writer(cookie, "  port_no (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_bsn_pdu_tx_request_slot_num_get(obj, &val8);
    out += writer(cookie, "  slot_num (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_bsn_pdu_tx_request_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_set_mirroring_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_bsn_set_mirroring_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint8_t val8;

    out += writer(cookie, "Object of type of_bsn_set_mirroring\n");

    of_bsn_set_mirroring_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_set_mirroring_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_set_mirroring_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_set_mirroring_report_mirror_ports_get(obj, &val8);
    out += writer(cookie, "  report_mirror_ports (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_set_pktin_suppression_reply_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_bsn_set_pktin_suppression_reply_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_bsn_set_pktin_suppression_reply\n");

    of_bsn_set_pktin_suppression_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_set_pktin_suppression_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_set_pktin_suppression_reply_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_set_pktin_suppression_reply_status_get(obj, &val32);
    out += writer(cookie, "  status (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_set_pktin_suppression_request_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_bsn_set_pktin_suppression_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint8_t val8;
    uint16_t val16;
    uint64_t val64;

    out += writer(cookie, "Object of type of_bsn_set_pktin_suppression_request\n");

    of_bsn_set_pktin_suppression_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_set_pktin_suppression_request_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_set_pktin_suppression_request_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_set_pktin_suppression_request_enabled_get(obj, &val8);
    out += writer(cookie, "  enabled (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_bsn_set_pktin_suppression_request_idle_timeout_get(obj, &val16);
    out += writer(cookie, "  idle_timeout (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_bsn_set_pktin_suppression_request_hard_timeout_get(obj, &val16);
    out += writer(cookie, "  hard_timeout (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_bsn_set_pktin_suppression_request_priority_get(obj, &val16);
    out += writer(cookie, "  priority (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_bsn_set_pktin_suppression_request_cookie_get(obj, &val64);
    out += writer(cookie, "  cookie (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_stats_reply_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_bsn_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    out += writer(cookie, "Object of type of_bsn_stats_reply\n");

    of_bsn_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_bsn_stats_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_stats_reply_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_stats_request_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_bsn_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    out += writer(cookie, "Object of type of_bsn_stats_request\n");

    of_bsn_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_bsn_stats_request_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_stats_request_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_virtual_port_create_reply_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_bsn_virtual_port_create_reply_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_bsn_virtual_port_create_reply\n");

    of_bsn_virtual_port_create_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_virtual_port_create_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_virtual_port_create_reply_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_virtual_port_create_reply_status_get(obj, &val32);
    out += writer(cookie, "  status (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_virtual_port_create_reply_vport_no_get(obj, &val32);
    out += writer(cookie, "  vport_no (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_virtual_port_create_request_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_bsn_virtual_port_create_request_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_bsn_vport_q_in_q_t vport;

    out += writer(cookie, "Object of type of_bsn_virtual_port_create_request\n");

    of_bsn_virtual_port_create_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_virtual_port_create_request_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_virtual_port_create_request_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_virtual_port_create_request_vport_bind(obj, &vport);
    out += of_bsn_vport_q_in_q_OF_VERSION_1_1_dump(writer, cookie, &vport);

    return out;
}

int
of_bsn_virtual_port_remove_reply_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_bsn_virtual_port_remove_reply_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_bsn_virtual_port_remove_reply\n");

    of_bsn_virtual_port_remove_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_virtual_port_remove_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_virtual_port_remove_reply_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_virtual_port_remove_reply_status_get(obj, &val32);
    out += writer(cookie, "  status (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_virtual_port_remove_request_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_bsn_virtual_port_remove_request_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_bsn_virtual_port_remove_request\n");

    of_bsn_virtual_port_remove_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_virtual_port_remove_request_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_virtual_port_remove_request_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_virtual_port_remove_request_vport_no_get(obj, &val32);
    out += writer(cookie, "  vport_no (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_desc_stats_reply_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_desc_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_desc_str_t desc_str;
    of_serial_num_t ser_num;

    out += writer(cookie, "Object of type of_desc_stats_reply\n");

    of_desc_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_desc_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_desc_stats_reply_mfr_desc_get(obj, &desc_str);
    out += writer(cookie, "  mfr_desc (of_desc_str_t):  ");
    out += LOCI_DUMP_desc_str(writer, cookie, desc_str);
    out += writer(cookie, "\n");

    of_desc_stats_reply_hw_desc_get(obj, &desc_str);
    out += writer(cookie, "  hw_desc (of_desc_str_t):  ");
    out += LOCI_DUMP_desc_str(writer, cookie, desc_str);
    out += writer(cookie, "\n");

    of_desc_stats_reply_sw_desc_get(obj, &desc_str);
    out += writer(cookie, "  sw_desc (of_desc_str_t):  ");
    out += LOCI_DUMP_desc_str(writer, cookie, desc_str);
    out += writer(cookie, "\n");

    of_desc_stats_reply_serial_num_get(obj, &ser_num);
    out += writer(cookie, "  serial_num (of_serial_num_t):  ");
    out += LOCI_DUMP_ser_num(writer, cookie, ser_num);
    out += writer(cookie, "\n");

    of_desc_stats_reply_dp_desc_get(obj, &desc_str);
    out += writer(cookie, "  dp_desc (of_desc_str_t):  ");
    out += LOCI_DUMP_desc_str(writer, cookie, desc_str);
    out += writer(cookie, "\n");

    return out;
}

int
of_desc_stats_request_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_desc_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    out += writer(cookie, "Object of type of_desc_stats_request\n");

    of_desc_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_desc_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_echo_reply_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_echo_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_echo_reply\n");

    of_echo_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_echo_reply_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_echo_request_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_echo_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_echo_request\n");

    of_echo_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_echo_request_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_error_msg_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_error_msg\n");

    of_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_experimenter_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_experimenter_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_experimenter\n");

    of_experimenter_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_experimenter_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_experimenter_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_experimenter_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_experimenter_stats_reply_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_experimenter_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_experimenter_stats_reply\n");

    of_experimenter_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_experimenter_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_experimenter_stats_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_experimenter_stats_reply_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_experimenter_stats_request_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_experimenter_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_experimenter_stats_request\n");

    of_experimenter_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_experimenter_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_experimenter_stats_request_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_experimenter_stats_request_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_features_reply_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_features_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint64_t val64;
    uint8_t val8;

    of_list_port_desc_t list;
    of_port_desc_t elt;
    int rv;

    out += writer(cookie, "Object of type of_features_reply\n");

    of_features_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_features_reply_datapath_id_get(obj, &val64);
    out += writer(cookie, "  datapath_id (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_features_reply_n_buffers_get(obj, &val32);
    out += writer(cookie, "  n_buffers (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_features_reply_n_tables_get(obj, &val8);
    out += writer(cookie, "  n_tables (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_features_reply_capabilities_get(obj, &val32);
    out += writer(cookie, "  capabilities (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_features_reply_reserved_get(obj, &val32);
    out += writer(cookie, "  reserved (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_port_desc_t\n");
    of_features_reply_ports_bind(obj, &list);
    OF_LIST_PORT_DESC_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_features_request_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_features_request_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_features_request\n");

    of_features_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_flow_add_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_flow_add_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint64_t val64;
    uint8_t val8;
    uint16_t val16;
    of_port_no_t port_no;
    of_match_t match;

    of_list_instruction_t list;
    of_instruction_t elt;
    int rv;

    out += writer(cookie, "Object of type of_flow_add\n");

    of_flow_add_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_add_cookie_get(obj, &val64);
    out += writer(cookie, "  cookie (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_flow_add_cookie_mask_get(obj, &val64);
    out += writer(cookie, "  cookie_mask (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_flow_add_table_id_get(obj, &val8);
    out += writer(cookie, "  table_id (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_flow_add_idle_timeout_get(obj, &val16);
    out += writer(cookie, "  idle_timeout (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_add_hard_timeout_get(obj, &val16);
    out += writer(cookie, "  hard_timeout (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_add_priority_get(obj, &val16);
    out += writer(cookie, "  priority (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_add_buffer_id_get(obj, &val32);
    out += writer(cookie, "  buffer_id (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_add_out_port_get(obj, &port_no);
    out += writer(cookie, "  out_port (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_flow_add_out_group_get(obj, &val32);
    out += writer(cookie, "  out_group (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_add_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_add_match_get(obj, &match);
    out += writer(cookie, "  match (of_match_t):  ");
    out += LOCI_DUMP_match(writer, cookie, match);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_instruction_t\n");
    of_flow_add_instructions_bind(obj, &list);
    OF_LIST_INSTRUCTION_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_flow_delete_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_flow_delete_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint64_t val64;
    uint8_t val8;
    uint16_t val16;
    of_port_no_t port_no;
    of_match_t match;

    of_list_instruction_t list;
    of_instruction_t elt;
    int rv;

    out += writer(cookie, "Object of type of_flow_delete\n");

    of_flow_delete_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_delete_cookie_get(obj, &val64);
    out += writer(cookie, "  cookie (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_flow_delete_cookie_mask_get(obj, &val64);
    out += writer(cookie, "  cookie_mask (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_flow_delete_table_id_get(obj, &val8);
    out += writer(cookie, "  table_id (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_flow_delete_idle_timeout_get(obj, &val16);
    out += writer(cookie, "  idle_timeout (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_delete_hard_timeout_get(obj, &val16);
    out += writer(cookie, "  hard_timeout (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_delete_priority_get(obj, &val16);
    out += writer(cookie, "  priority (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_delete_buffer_id_get(obj, &val32);
    out += writer(cookie, "  buffer_id (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_delete_out_port_get(obj, &port_no);
    out += writer(cookie, "  out_port (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_flow_delete_out_group_get(obj, &val32);
    out += writer(cookie, "  out_group (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_delete_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_delete_match_get(obj, &match);
    out += writer(cookie, "  match (of_match_t):  ");
    out += LOCI_DUMP_match(writer, cookie, match);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_instruction_t\n");
    of_flow_delete_instructions_bind(obj, &list);
    OF_LIST_INSTRUCTION_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_flow_delete_strict_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_flow_delete_strict_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint64_t val64;
    uint8_t val8;
    uint16_t val16;
    of_port_no_t port_no;
    of_match_t match;

    of_list_instruction_t list;
    of_instruction_t elt;
    int rv;

    out += writer(cookie, "Object of type of_flow_delete_strict\n");

    of_flow_delete_strict_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_delete_strict_cookie_get(obj, &val64);
    out += writer(cookie, "  cookie (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_flow_delete_strict_cookie_mask_get(obj, &val64);
    out += writer(cookie, "  cookie_mask (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_flow_delete_strict_table_id_get(obj, &val8);
    out += writer(cookie, "  table_id (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_flow_delete_strict_idle_timeout_get(obj, &val16);
    out += writer(cookie, "  idle_timeout (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_delete_strict_hard_timeout_get(obj, &val16);
    out += writer(cookie, "  hard_timeout (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_delete_strict_priority_get(obj, &val16);
    out += writer(cookie, "  priority (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_delete_strict_buffer_id_get(obj, &val32);
    out += writer(cookie, "  buffer_id (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_delete_strict_out_port_get(obj, &port_no);
    out += writer(cookie, "  out_port (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_flow_delete_strict_out_group_get(obj, &val32);
    out += writer(cookie, "  out_group (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_delete_strict_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_delete_strict_match_get(obj, &match);
    out += writer(cookie, "  match (of_match_t):  ");
    out += LOCI_DUMP_match(writer, cookie, match);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_instruction_t\n");
    of_flow_delete_strict_instructions_bind(obj, &list);
    OF_LIST_INSTRUCTION_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_flow_mod_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_flow_mod_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint64_t val64;
    uint8_t val8;
    uint16_t val16;
    of_port_no_t port_no;
    of_match_t match;

    of_list_instruction_t list;
    of_instruction_t elt;
    int rv;

    out += writer(cookie, "Object of type of_flow_mod\n");

    of_flow_mod_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_mod_cookie_get(obj, &val64);
    out += writer(cookie, "  cookie (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_flow_mod_cookie_mask_get(obj, &val64);
    out += writer(cookie, "  cookie_mask (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_flow_mod_table_id_get(obj, &val8);
    out += writer(cookie, "  table_id (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_flow_mod_idle_timeout_get(obj, &val16);
    out += writer(cookie, "  idle_timeout (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_mod_hard_timeout_get(obj, &val16);
    out += writer(cookie, "  hard_timeout (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_mod_priority_get(obj, &val16);
    out += writer(cookie, "  priority (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_mod_buffer_id_get(obj, &val32);
    out += writer(cookie, "  buffer_id (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_mod_out_port_get(obj, &port_no);
    out += writer(cookie, "  out_port (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_flow_mod_out_group_get(obj, &val32);
    out += writer(cookie, "  out_group (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_mod_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_mod_match_get(obj, &match);
    out += writer(cookie, "  match (of_match_t):  ");
    out += LOCI_DUMP_match(writer, cookie, match);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_instruction_t\n");
    of_flow_mod_instructions_bind(obj, &list);
    OF_LIST_INSTRUCTION_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_flow_mod_failed_error_msg_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_flow_mod_failed_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_flow_mod_failed_error_msg\n");

    of_flow_mod_failed_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_mod_failed_error_msg_code_get(obj, &val16);
    out += writer(cookie, "  code (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_mod_failed_error_msg_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_flow_modify_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_flow_modify_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint64_t val64;
    uint8_t val8;
    uint16_t val16;
    of_port_no_t port_no;
    of_match_t match;

    of_list_instruction_t list;
    of_instruction_t elt;
    int rv;

    out += writer(cookie, "Object of type of_flow_modify\n");

    of_flow_modify_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_modify_cookie_get(obj, &val64);
    out += writer(cookie, "  cookie (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_flow_modify_cookie_mask_get(obj, &val64);
    out += writer(cookie, "  cookie_mask (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_flow_modify_table_id_get(obj, &val8);
    out += writer(cookie, "  table_id (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_flow_modify_idle_timeout_get(obj, &val16);
    out += writer(cookie, "  idle_timeout (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_modify_hard_timeout_get(obj, &val16);
    out += writer(cookie, "  hard_timeout (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_modify_priority_get(obj, &val16);
    out += writer(cookie, "  priority (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_modify_buffer_id_get(obj, &val32);
    out += writer(cookie, "  buffer_id (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_modify_out_port_get(obj, &port_no);
    out += writer(cookie, "  out_port (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_flow_modify_out_group_get(obj, &val32);
    out += writer(cookie, "  out_group (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_modify_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_modify_match_get(obj, &match);
    out += writer(cookie, "  match (of_match_t):  ");
    out += LOCI_DUMP_match(writer, cookie, match);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_instruction_t\n");
    of_flow_modify_instructions_bind(obj, &list);
    OF_LIST_INSTRUCTION_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_flow_modify_strict_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_flow_modify_strict_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint64_t val64;
    uint8_t val8;
    uint16_t val16;
    of_port_no_t port_no;
    of_match_t match;

    of_list_instruction_t list;
    of_instruction_t elt;
    int rv;

    out += writer(cookie, "Object of type of_flow_modify_strict\n");

    of_flow_modify_strict_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_modify_strict_cookie_get(obj, &val64);
    out += writer(cookie, "  cookie (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_flow_modify_strict_cookie_mask_get(obj, &val64);
    out += writer(cookie, "  cookie_mask (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_flow_modify_strict_table_id_get(obj, &val8);
    out += writer(cookie, "  table_id (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_flow_modify_strict_idle_timeout_get(obj, &val16);
    out += writer(cookie, "  idle_timeout (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_modify_strict_hard_timeout_get(obj, &val16);
    out += writer(cookie, "  hard_timeout (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_modify_strict_priority_get(obj, &val16);
    out += writer(cookie, "  priority (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_modify_strict_buffer_id_get(obj, &val32);
    out += writer(cookie, "  buffer_id (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_modify_strict_out_port_get(obj, &port_no);
    out += writer(cookie, "  out_port (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_flow_modify_strict_out_group_get(obj, &val32);
    out += writer(cookie, "  out_group (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_modify_strict_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_modify_strict_match_get(obj, &match);
    out += writer(cookie, "  match (of_match_t):  ");
    out += LOCI_DUMP_match(writer, cookie, match);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_instruction_t\n");
    of_flow_modify_strict_instructions_bind(obj, &list);
    OF_LIST_INSTRUCTION_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_flow_removed_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_flow_removed_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint64_t val64;
    uint16_t val16;
    uint8_t val8;
    of_match_t match;

    out += writer(cookie, "Object of type of_flow_removed\n");

    of_flow_removed_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_removed_cookie_get(obj, &val64);
    out += writer(cookie, "  cookie (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_flow_removed_priority_get(obj, &val16);
    out += writer(cookie, "  priority (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_removed_reason_get(obj, &val8);
    out += writer(cookie, "  reason (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_flow_removed_table_id_get(obj, &val8);
    out += writer(cookie, "  table_id (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_flow_removed_duration_sec_get(obj, &val32);
    out += writer(cookie, "  duration_sec (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_removed_duration_nsec_get(obj, &val32);
    out += writer(cookie, "  duration_nsec (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_removed_idle_timeout_get(obj, &val16);
    out += writer(cookie, "  idle_timeout (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_removed_packet_count_get(obj, &val64);
    out += writer(cookie, "  packet_count (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_flow_removed_byte_count_get(obj, &val64);
    out += writer(cookie, "  byte_count (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_flow_removed_match_get(obj, &match);
    out += writer(cookie, "  match (of_match_t):  ");
    out += LOCI_DUMP_match(writer, cookie, match);
    out += writer(cookie, "\n");

    return out;
}

int
of_flow_stats_reply_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_flow_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_list_flow_stats_entry_t list;
    of_flow_stats_entry_t elt;
    int rv;

    out += writer(cookie, "Object of type of_flow_stats_reply\n");

    of_flow_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_flow_stats_entry_t\n");
    of_flow_stats_reply_entries_bind(obj, &list);
    OF_LIST_FLOW_STATS_ENTRY_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_flow_stats_request_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_flow_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    uint8_t val8;
    of_port_no_t port_no;
    uint64_t val64;
    of_match_t match;

    out += writer(cookie, "Object of type of_flow_stats_request\n");

    of_flow_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_stats_request_table_id_get(obj, &val8);
    out += writer(cookie, "  table_id (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_flow_stats_request_out_port_get(obj, &port_no);
    out += writer(cookie, "  out_port (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_flow_stats_request_out_group_get(obj, &val32);
    out += writer(cookie, "  out_group (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_stats_request_cookie_get(obj, &val64);
    out += writer(cookie, "  cookie (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_flow_stats_request_cookie_mask_get(obj, &val64);
    out += writer(cookie, "  cookie_mask (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_flow_stats_request_match_get(obj, &match);
    out += writer(cookie, "  match (of_match_t):  ");
    out += LOCI_DUMP_match(writer, cookie, match);
    out += writer(cookie, "\n");

    return out;
}

int
of_get_config_reply_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_get_config_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    out += writer(cookie, "Object of type of_get_config_reply\n");

    of_get_config_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_get_config_reply_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_get_config_reply_miss_send_len_get(obj, &val16);
    out += writer(cookie, "  miss_send_len (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_get_config_request_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_get_config_request_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_get_config_request\n");

    of_get_config_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_group_desc_stats_reply_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_group_desc_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_list_group_desc_stats_entry_t list;
    of_group_desc_stats_entry_t elt;
    int rv;

    out += writer(cookie, "Object of type of_group_desc_stats_reply\n");

    of_group_desc_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_group_desc_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_group_desc_stats_entry_t\n");
    of_group_desc_stats_reply_entries_bind(obj, &list);
    OF_LIST_GROUP_DESC_STATS_ENTRY_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_group_desc_stats_request_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_group_desc_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    out += writer(cookie, "Object of type of_group_desc_stats_request\n");

    of_group_desc_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_group_desc_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_group_mod_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_group_mod_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    uint8_t val8;

    of_list_bucket_t list;
    of_bucket_t elt;
    int rv;

    out += writer(cookie, "Object of type of_group_mod\n");

    of_group_mod_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_group_mod_command_get(obj, &val16);
    out += writer(cookie, "  command (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_group_mod_group_type_get(obj, &val8);
    out += writer(cookie, "  group_type (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_group_mod_group_id_get(obj, &val32);
    out += writer(cookie, "  group_id (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_bucket_t\n");
    of_group_mod_buckets_bind(obj, &list);
    OF_LIST_BUCKET_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_group_mod_failed_error_msg_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_group_mod_failed_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_group_mod_failed_error_msg\n");

    of_group_mod_failed_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_group_mod_failed_error_msg_code_get(obj, &val16);
    out += writer(cookie, "  code (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_group_mod_failed_error_msg_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_group_stats_reply_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_group_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_list_group_stats_entry_t list;
    of_group_stats_entry_t elt;
    int rv;

    out += writer(cookie, "Object of type of_group_stats_reply\n");

    of_group_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_group_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_group_stats_entry_t\n");
    of_group_stats_reply_entries_bind(obj, &list);
    OF_LIST_GROUP_STATS_ENTRY_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_group_stats_request_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_group_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    out += writer(cookie, "Object of type of_group_stats_request\n");

    of_group_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_group_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_group_stats_request_group_id_get(obj, &val32);
    out += writer(cookie, "  group_id (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_hello_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_hello_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_hello\n");

    of_hello_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_hello_failed_error_msg_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_hello_failed_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_hello_failed_error_msg\n");

    of_hello_failed_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_hello_failed_error_msg_code_get(obj, &val16);
    out += writer(cookie, "  code (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_hello_failed_error_msg_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_nicira_header_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_nicira_header_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_nicira_header\n");

    of_nicira_header_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_nicira_header_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_nicira_header_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_packet_in_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_packet_in_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_port_no_t port_no;
    uint16_t val16;
    uint8_t val8;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_packet_in\n");

    of_packet_in_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_packet_in_buffer_id_get(obj, &val32);
    out += writer(cookie, "  buffer_id (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_packet_in_in_port_get(obj, &port_no);
    out += writer(cookie, "  in_port (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_packet_in_in_phy_port_get(obj, &port_no);
    out += writer(cookie, "  in_phy_port (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_packet_in_total_len_get(obj, &val16);
    out += writer(cookie, "  total_len (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_packet_in_reason_get(obj, &val8);
    out += writer(cookie, "  reason (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_packet_in_table_id_get(obj, &val8);
    out += writer(cookie, "  table_id (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_packet_in_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_packet_out_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_packet_out_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_port_no_t port_no;

    of_list_action_t list;
    of_action_t elt;
    int rv;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_packet_out\n");

    of_packet_out_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_packet_out_buffer_id_get(obj, &val32);
    out += writer(cookie, "  buffer_id (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_packet_out_in_port_get(obj, &port_no);
    out += writer(cookie, "  in_port (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_action_t\n");
    of_packet_out_actions_bind(obj, &list);
    OF_LIST_ACTION_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    of_packet_out_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_port_mod_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_port_mod_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_port_no_t port_no;
    of_mac_addr_t mac_addr;

    out += writer(cookie, "Object of type of_port_mod\n");

    of_port_mod_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_port_mod_port_no_get(obj, &port_no);
    out += writer(cookie, "  port_no (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_port_mod_hw_addr_get(obj, &mac_addr);
    out += writer(cookie, "  hw_addr (of_mac_addr_t):  ");
    out += LOCI_DUMP_mac(writer, cookie, mac_addr);
    out += writer(cookie, "\n");

    of_port_mod_config_get(obj, &val32);
    out += writer(cookie, "  config (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_port_mod_mask_get(obj, &val32);
    out += writer(cookie, "  mask (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_port_mod_advertise_get(obj, &val32);
    out += writer(cookie, "  advertise (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_port_mod_failed_error_msg_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_port_mod_failed_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_port_mod_failed_error_msg\n");

    of_port_mod_failed_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_port_mod_failed_error_msg_code_get(obj, &val16);
    out += writer(cookie, "  code (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_port_mod_failed_error_msg_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_port_stats_reply_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_port_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_list_port_stats_entry_t list;
    of_port_stats_entry_t elt;
    int rv;

    out += writer(cookie, "Object of type of_port_stats_reply\n");

    of_port_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_port_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_port_stats_entry_t\n");
    of_port_stats_reply_entries_bind(obj, &list);
    OF_LIST_PORT_STATS_ENTRY_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_port_stats_request_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_port_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_port_no_t port_no;

    out += writer(cookie, "Object of type of_port_stats_request\n");

    of_port_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_port_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_port_stats_request_port_no_get(obj, &port_no);
    out += writer(cookie, "  port_no (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    return out;
}

int
of_port_status_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_port_status_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint8_t val8;

    of_port_desc_t port_desc;

    out += writer(cookie, "Object of type of_port_status\n");

    of_port_status_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_port_status_reason_get(obj, &val8);
    out += writer(cookie, "  reason (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_port_status_desc_bind(obj, &port_desc);
    out += of_port_desc_OF_VERSION_1_1_dump(writer, cookie, &port_desc);

    return out;
}

int
of_queue_get_config_reply_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_queue_get_config_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_port_no_t port_no;

    of_list_packet_queue_t list;
    of_packet_queue_t elt;
    int rv;

    out += writer(cookie, "Object of type of_queue_get_config_reply\n");

    of_queue_get_config_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_queue_get_config_reply_port_get(obj, &port_no);
    out += writer(cookie, "  port (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_packet_queue_t\n");
    of_queue_get_config_reply_queues_bind(obj, &list);
    OF_LIST_PACKET_QUEUE_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_queue_get_config_request_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_queue_get_config_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_port_no_t port_no;

    out += writer(cookie, "Object of type of_queue_get_config_request\n");

    of_queue_get_config_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_queue_get_config_request_port_get(obj, &port_no);
    out += writer(cookie, "  port (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    return out;
}

int
of_queue_op_failed_error_msg_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_queue_op_failed_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_queue_op_failed_error_msg\n");

    of_queue_op_failed_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_queue_op_failed_error_msg_code_get(obj, &val16);
    out += writer(cookie, "  code (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_queue_op_failed_error_msg_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_queue_stats_reply_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_queue_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_list_queue_stats_entry_t list;
    of_queue_stats_entry_t elt;
    int rv;

    out += writer(cookie, "Object of type of_queue_stats_reply\n");

    of_queue_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_queue_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_queue_stats_entry_t\n");
    of_queue_stats_reply_entries_bind(obj, &list);
    OF_LIST_QUEUE_STATS_ENTRY_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_queue_stats_request_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_queue_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_port_no_t port_no;

    out += writer(cookie, "Object of type of_queue_stats_request\n");

    of_queue_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_queue_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_queue_stats_request_port_no_get(obj, &port_no);
    out += writer(cookie, "  port_no (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_queue_stats_request_queue_id_get(obj, &val32);
    out += writer(cookie, "  queue_id (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_set_config_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_set_config_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    out += writer(cookie, "Object of type of_set_config\n");

    of_set_config_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_set_config_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_set_config_miss_send_len_get(obj, &val16);
    out += writer(cookie, "  miss_send_len (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_stats_reply_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    out += writer(cookie, "Object of type of_stats_reply\n");

    of_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_stats_request_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    out += writer(cookie, "Object of type of_stats_request\n");

    of_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_switch_config_failed_error_msg_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_switch_config_failed_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_switch_config_failed_error_msg\n");

    of_switch_config_failed_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_switch_config_failed_error_msg_code_get(obj, &val16);
    out += writer(cookie, "  code (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_switch_config_failed_error_msg_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_table_mod_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_table_mod_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint8_t val8;

    out += writer(cookie, "Object of type of_table_mod\n");

    of_table_mod_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_table_mod_table_id_get(obj, &val8);
    out += writer(cookie, "  table_id (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_table_mod_config_get(obj, &val32);
    out += writer(cookie, "  config (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_table_mod_failed_error_msg_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_table_mod_failed_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_table_mod_failed_error_msg\n");

    of_table_mod_failed_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_table_mod_failed_error_msg_code_get(obj, &val16);
    out += writer(cookie, "  code (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_table_mod_failed_error_msg_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_table_stats_reply_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_table_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_list_table_stats_entry_t list;
    of_table_stats_entry_t elt;
    int rv;

    out += writer(cookie, "Object of type of_table_stats_reply\n");

    of_table_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_table_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_table_stats_entry_t\n");
    of_table_stats_reply_entries_bind(obj, &list);
    OF_LIST_TABLE_STATS_ENTRY_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_table_stats_request_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_table_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    out += writer(cookie, "Object of type of_table_stats_request\n");

    of_table_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_table_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_action_bsn_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_action_bsn_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_action_bsn\n");

    of_action_bsn_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_action_bsn_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_action_bsn_mirror_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_action_bsn_mirror_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint8_t val8;

    out += writer(cookie, "Object of type of_action_bsn_mirror\n");

    of_action_bsn_mirror_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_action_bsn_mirror_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_action_bsn_mirror_dest_port_get(obj, &val32);
    out += writer(cookie, "  dest_port (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_action_bsn_mirror_vlan_tag_get(obj, &val32);
    out += writer(cookie, "  vlan_tag (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_action_bsn_mirror_copy_stage_get(obj, &val8);
    out += writer(cookie, "  copy_stage (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_action_bsn_set_tunnel_dst_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_action_bsn_set_tunnel_dst_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_action_bsn_set_tunnel_dst\n");

    of_action_bsn_set_tunnel_dst_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_action_bsn_set_tunnel_dst_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_action_bsn_set_tunnel_dst_dst_get(obj, &val32);
    out += writer(cookie, "  dst (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_action_copy_ttl_in_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_action_copy_ttl_in_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_action_copy_ttl_in\n");

    return out;
}

int
of_action_copy_ttl_out_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_action_copy_ttl_out_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_action_copy_ttl_out\n");

    return out;
}

int
of_action_dec_mpls_ttl_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_action_dec_mpls_ttl_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_action_dec_mpls_ttl\n");

    return out;
}

int
of_action_dec_nw_ttl_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_action_dec_nw_ttl_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_action_dec_nw_ttl\n");

    return out;
}

int
of_action_experimenter_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_action_experimenter_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_action_experimenter\n");

    of_action_experimenter_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_action_experimenter_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_action_group_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_action_group_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_action_group\n");

    of_action_group_group_id_get(obj, &val32);
    out += writer(cookie, "  group_id (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_action_header_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_action_header_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_action_header\n");

    return out;
}

int
of_action_nicira_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_action_nicira_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    out += writer(cookie, "Object of type of_action_nicira\n");

    of_action_nicira_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_action_nicira_subtype_get(obj, &val16);
    out += writer(cookie, "  subtype (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_action_nicira_dec_ttl_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_action_nicira_dec_ttl_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    out += writer(cookie, "Object of type of_action_nicira_dec_ttl\n");

    of_action_nicira_dec_ttl_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_action_nicira_dec_ttl_subtype_get(obj, &val16);
    out += writer(cookie, "  subtype (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_action_output_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_action_output_t *obj)
{
    int out = 0;
    of_port_no_t port_no;
    uint16_t val16;

    out += writer(cookie, "Object of type of_action_output\n");

    of_action_output_port_get(obj, &port_no);
    out += writer(cookie, "  port (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_action_output_max_len_get(obj, &val16);
    out += writer(cookie, "  max_len (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_action_pop_mpls_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_action_pop_mpls_t *obj)
{
    int out = 0;
    uint16_t val16;

    out += writer(cookie, "Object of type of_action_pop_mpls\n");

    of_action_pop_mpls_ethertype_get(obj, &val16);
    out += writer(cookie, "  ethertype (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_action_pop_vlan_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_action_pop_vlan_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_action_pop_vlan\n");

    return out;
}

int
of_action_push_mpls_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_action_push_mpls_t *obj)
{
    int out = 0;
    uint16_t val16;

    out += writer(cookie, "Object of type of_action_push_mpls\n");

    of_action_push_mpls_ethertype_get(obj, &val16);
    out += writer(cookie, "  ethertype (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_action_push_vlan_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_action_push_vlan_t *obj)
{
    int out = 0;
    uint16_t val16;

    out += writer(cookie, "Object of type of_action_push_vlan\n");

    of_action_push_vlan_ethertype_get(obj, &val16);
    out += writer(cookie, "  ethertype (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_action_set_dl_dst_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_action_set_dl_dst_t *obj)
{
    int out = 0;
    of_mac_addr_t mac_addr;

    out += writer(cookie, "Object of type of_action_set_dl_dst\n");

    of_action_set_dl_dst_dl_addr_get(obj, &mac_addr);
    out += writer(cookie, "  dl_addr (of_mac_addr_t):  ");
    out += LOCI_DUMP_mac(writer, cookie, mac_addr);
    out += writer(cookie, "\n");

    return out;
}

int
of_action_set_dl_src_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_action_set_dl_src_t *obj)
{
    int out = 0;
    of_mac_addr_t mac_addr;

    out += writer(cookie, "Object of type of_action_set_dl_src\n");

    of_action_set_dl_src_dl_addr_get(obj, &mac_addr);
    out += writer(cookie, "  dl_addr (of_mac_addr_t):  ");
    out += LOCI_DUMP_mac(writer, cookie, mac_addr);
    out += writer(cookie, "\n");

    return out;
}

int
of_action_set_mpls_label_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_action_set_mpls_label_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_action_set_mpls_label\n");

    of_action_set_mpls_label_mpls_label_get(obj, &val32);
    out += writer(cookie, "  mpls_label (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_action_set_mpls_tc_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_action_set_mpls_tc_t *obj)
{
    int out = 0;
    uint8_t val8;

    out += writer(cookie, "Object of type of_action_set_mpls_tc\n");

    of_action_set_mpls_tc_mpls_tc_get(obj, &val8);
    out += writer(cookie, "  mpls_tc (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_action_set_mpls_ttl_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_action_set_mpls_ttl_t *obj)
{
    int out = 0;
    uint8_t val8;

    out += writer(cookie, "Object of type of_action_set_mpls_ttl\n");

    of_action_set_mpls_ttl_mpls_ttl_get(obj, &val8);
    out += writer(cookie, "  mpls_ttl (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_action_set_nw_dst_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_action_set_nw_dst_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_action_set_nw_dst\n");

    of_action_set_nw_dst_nw_addr_get(obj, &val32);
    out += writer(cookie, "  nw_addr (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_action_set_nw_ecn_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_action_set_nw_ecn_t *obj)
{
    int out = 0;
    uint8_t val8;

    out += writer(cookie, "Object of type of_action_set_nw_ecn\n");

    of_action_set_nw_ecn_nw_ecn_get(obj, &val8);
    out += writer(cookie, "  nw_ecn (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_action_set_nw_src_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_action_set_nw_src_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_action_set_nw_src\n");

    of_action_set_nw_src_nw_addr_get(obj, &val32);
    out += writer(cookie, "  nw_addr (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_action_set_nw_tos_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_action_set_nw_tos_t *obj)
{
    int out = 0;
    uint8_t val8;

    out += writer(cookie, "Object of type of_action_set_nw_tos\n");

    of_action_set_nw_tos_nw_tos_get(obj, &val8);
    out += writer(cookie, "  nw_tos (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_action_set_nw_ttl_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_action_set_nw_ttl_t *obj)
{
    int out = 0;
    uint8_t val8;

    out += writer(cookie, "Object of type of_action_set_nw_ttl\n");

    of_action_set_nw_ttl_nw_ttl_get(obj, &val8);
    out += writer(cookie, "  nw_ttl (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_action_set_queue_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_action_set_queue_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_action_set_queue\n");

    of_action_set_queue_queue_id_get(obj, &val32);
    out += writer(cookie, "  queue_id (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_action_set_tp_dst_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_action_set_tp_dst_t *obj)
{
    int out = 0;
    uint16_t val16;

    out += writer(cookie, "Object of type of_action_set_tp_dst\n");

    of_action_set_tp_dst_tp_port_get(obj, &val16);
    out += writer(cookie, "  tp_port (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_action_set_tp_src_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_action_set_tp_src_t *obj)
{
    int out = 0;
    uint16_t val16;

    out += writer(cookie, "Object of type of_action_set_tp_src\n");

    of_action_set_tp_src_tp_port_get(obj, &val16);
    out += writer(cookie, "  tp_port (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_action_set_vlan_pcp_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_action_set_vlan_pcp_t *obj)
{
    int out = 0;
    uint8_t val8;

    out += writer(cookie, "Object of type of_action_set_vlan_pcp\n");

    of_action_set_vlan_pcp_vlan_pcp_get(obj, &val8);
    out += writer(cookie, "  vlan_pcp (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_action_set_vlan_vid_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_action_set_vlan_vid_t *obj)
{
    int out = 0;
    uint16_t val16;

    out += writer(cookie, "Object of type of_action_set_vlan_vid\n");

    of_action_set_vlan_vid_vlan_vid_get(obj, &val16);
    out += writer(cookie, "  vlan_vid (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_interface_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_bsn_interface_t *obj)
{
    int out = 0;
    of_mac_addr_t mac_addr;
    of_port_name_t port_name;
    of_ipv4_t ipv4;

    out += writer(cookie, "Object of type of_bsn_interface\n");

    of_bsn_interface_hw_addr_get(obj, &mac_addr);
    out += writer(cookie, "  hw_addr (of_mac_addr_t):  ");
    out += LOCI_DUMP_mac(writer, cookie, mac_addr);
    out += writer(cookie, "\n");

    of_bsn_interface_name_get(obj, &port_name);
    out += writer(cookie, "  name (of_port_name_t):  ");
    out += LOCI_DUMP_port_name(writer, cookie, port_name);
    out += writer(cookie, "\n");

    of_bsn_interface_ipv4_addr_get(obj, &ipv4);
    out += writer(cookie, "  ipv4_addr (of_ipv4_t):  ");
    out += LOCI_DUMP_ipv4(writer, cookie, ipv4);
    out += writer(cookie, "\n");

    of_bsn_interface_ipv4_netmask_get(obj, &ipv4);
    out += writer(cookie, "  ipv4_netmask (of_ipv4_t):  ");
    out += LOCI_DUMP_ipv4(writer, cookie, ipv4);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_vport_header_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_bsn_vport_header_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_bsn_vport_header\n");

    return out;
}

int
of_bsn_vport_q_in_q_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_bsn_vport_q_in_q_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_port_name_t port_name;

    out += writer(cookie, "Object of type of_bsn_vport_q_in_q\n");

    of_bsn_vport_q_in_q_port_no_get(obj, &val32);
    out += writer(cookie, "  port_no (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_vport_q_in_q_ingress_tpid_get(obj, &val16);
    out += writer(cookie, "  ingress_tpid (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_bsn_vport_q_in_q_ingress_vlan_id_get(obj, &val16);
    out += writer(cookie, "  ingress_vlan_id (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_bsn_vport_q_in_q_egress_tpid_get(obj, &val16);
    out += writer(cookie, "  egress_tpid (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_bsn_vport_q_in_q_egress_vlan_id_get(obj, &val16);
    out += writer(cookie, "  egress_vlan_id (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_bsn_vport_q_in_q_if_name_get(obj, &port_name);
    out += writer(cookie, "  if_name (of_port_name_t):  ");
    out += LOCI_DUMP_port_name(writer, cookie, port_name);
    out += writer(cookie, "\n");

    return out;
}

int
of_bucket_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_bucket_t *obj)
{
    int out = 0;
    uint16_t val16;
    of_port_no_t port_no;
    uint32_t val32;

    of_list_action_t list;
    of_action_t elt;
    int rv;

    out += writer(cookie, "Object of type of_bucket\n");

    of_bucket_weight_get(obj, &val16);
    out += writer(cookie, "  weight (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_bucket_watch_port_get(obj, &port_no);
    out += writer(cookie, "  watch_port (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_bucket_watch_group_get(obj, &val32);
    out += writer(cookie, "  watch_group (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_action_t\n");
    of_bucket_actions_bind(obj, &list);
    OF_LIST_ACTION_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_bucket_counter_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_bucket_counter_t *obj)
{
    int out = 0;
    uint64_t val64;

    out += writer(cookie, "Object of type of_bucket_counter\n");

    of_bucket_counter_packet_count_get(obj, &val64);
    out += writer(cookie, "  packet_count (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_bucket_counter_byte_count_get(obj, &val64);
    out += writer(cookie, "  byte_count (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    return out;
}

int
of_flow_stats_entry_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_flow_stats_entry_t *obj)
{
    int out = 0;
    uint8_t val8;
    uint32_t val32;
    uint16_t val16;
    uint64_t val64;
    of_match_t match;

    of_list_instruction_t list;
    of_instruction_t elt;
    int rv;

    out += writer(cookie, "Object of type of_flow_stats_entry\n");

    of_flow_stats_entry_table_id_get(obj, &val8);
    out += writer(cookie, "  table_id (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_flow_stats_entry_duration_sec_get(obj, &val32);
    out += writer(cookie, "  duration_sec (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_stats_entry_duration_nsec_get(obj, &val32);
    out += writer(cookie, "  duration_nsec (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_stats_entry_priority_get(obj, &val16);
    out += writer(cookie, "  priority (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_stats_entry_idle_timeout_get(obj, &val16);
    out += writer(cookie, "  idle_timeout (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_stats_entry_hard_timeout_get(obj, &val16);
    out += writer(cookie, "  hard_timeout (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_stats_entry_cookie_get(obj, &val64);
    out += writer(cookie, "  cookie (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_flow_stats_entry_packet_count_get(obj, &val64);
    out += writer(cookie, "  packet_count (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_flow_stats_entry_byte_count_get(obj, &val64);
    out += writer(cookie, "  byte_count (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_flow_stats_entry_match_get(obj, &match);
    out += writer(cookie, "  match (of_match_t):  ");
    out += LOCI_DUMP_match(writer, cookie, match);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_instruction_t\n");
    of_flow_stats_entry_instructions_bind(obj, &list);
    OF_LIST_INSTRUCTION_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_group_desc_stats_entry_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_group_desc_stats_entry_t *obj)
{
    int out = 0;
    uint8_t val8;
    uint32_t val32;

    of_list_bucket_t list;
    of_bucket_t elt;
    int rv;

    out += writer(cookie, "Object of type of_group_desc_stats_entry\n");

    of_group_desc_stats_entry_group_type_get(obj, &val8);
    out += writer(cookie, "  group_type (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_group_desc_stats_entry_group_id_get(obj, &val32);
    out += writer(cookie, "  group_id (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_bucket_t\n");
    of_group_desc_stats_entry_buckets_bind(obj, &list);
    OF_LIST_BUCKET_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_group_stats_entry_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_group_stats_entry_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint64_t val64;

    of_list_bucket_counter_t list;
    of_bucket_counter_t elt;
    int rv;

    out += writer(cookie, "Object of type of_group_stats_entry\n");

    of_group_stats_entry_group_id_get(obj, &val32);
    out += writer(cookie, "  group_id (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_group_stats_entry_ref_count_get(obj, &val32);
    out += writer(cookie, "  ref_count (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_group_stats_entry_packet_count_get(obj, &val64);
    out += writer(cookie, "  packet_count (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_group_stats_entry_byte_count_get(obj, &val64);
    out += writer(cookie, "  byte_count (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_bucket_counter_t\n");
    of_group_stats_entry_bucket_stats_bind(obj, &list);
    OF_LIST_BUCKET_COUNTER_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_header_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_header_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_header\n");

    of_header_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_instruction_apply_actions_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_instruction_apply_actions_t *obj)
{
    int out = 0;

    of_list_action_t list;
    of_action_t elt;
    int rv;

    out += writer(cookie, "Object of type of_instruction_apply_actions\n");

    out += writer(cookie, "List of of_action_t\n");
    of_instruction_apply_actions_actions_bind(obj, &list);
    OF_LIST_ACTION_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_instruction_clear_actions_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_instruction_clear_actions_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_instruction_clear_actions\n");

    return out;
}

int
of_instruction_experimenter_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_instruction_experimenter_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_instruction_experimenter\n");

    of_instruction_experimenter_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_instruction_experimenter_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_instruction_goto_table_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_instruction_goto_table_t *obj)
{
    int out = 0;
    uint8_t val8;

    out += writer(cookie, "Object of type of_instruction_goto_table\n");

    of_instruction_goto_table_table_id_get(obj, &val8);
    out += writer(cookie, "  table_id (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_instruction_header_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_instruction_header_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_instruction_header\n");

    return out;
}

int
of_instruction_write_actions_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_instruction_write_actions_t *obj)
{
    int out = 0;

    of_list_action_t list;
    of_action_t elt;
    int rv;

    out += writer(cookie, "Object of type of_instruction_write_actions\n");

    out += writer(cookie, "List of of_action_t\n");
    of_instruction_write_actions_actions_bind(obj, &list);
    OF_LIST_ACTION_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_instruction_write_metadata_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_instruction_write_metadata_t *obj)
{
    int out = 0;
    uint64_t val64;

    out += writer(cookie, "Object of type of_instruction_write_metadata\n");

    of_instruction_write_metadata_metadata_get(obj, &val64);
    out += writer(cookie, "  metadata (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_instruction_write_metadata_metadata_mask_get(obj, &val64);
    out += writer(cookie, "  metadata_mask (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    return out;
}

int
of_match_v2_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_match_v2_t *obj)
{
    int out = 0;
    of_port_no_t port_no;
    of_wc_bmap_t wc_bmap;
    of_mac_addr_t mac_addr;
    uint16_t val16;
    uint8_t val8;
    of_ipv4_t ipv4;
    uint32_t val32;
    uint64_t val64;

    out += writer(cookie, "Object of type of_match_v2\n");

    of_match_v2_in_port_get(obj, &port_no);
    out += writer(cookie, "  in_port (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_match_v2_wildcards_get(obj, &wc_bmap);
    out += writer(cookie, "  wildcards (of_wc_bmap_t):  ");
    out += LOCI_DUMP_wc_bmap(writer, cookie, wc_bmap);
    out += writer(cookie, "\n");

    of_match_v2_eth_src_get(obj, &mac_addr);
    out += writer(cookie, "  eth_src (of_mac_addr_t):  ");
    out += LOCI_DUMP_mac(writer, cookie, mac_addr);
    out += writer(cookie, "\n");

    of_match_v2_eth_src_mask_get(obj, &mac_addr);
    out += writer(cookie, "  eth_src_mask (of_mac_addr_t):  ");
    out += LOCI_DUMP_mac(writer, cookie, mac_addr);
    out += writer(cookie, "\n");

    of_match_v2_eth_dst_get(obj, &mac_addr);
    out += writer(cookie, "  eth_dst (of_mac_addr_t):  ");
    out += LOCI_DUMP_mac(writer, cookie, mac_addr);
    out += writer(cookie, "\n");

    of_match_v2_eth_dst_mask_get(obj, &mac_addr);
    out += writer(cookie, "  eth_dst_mask (of_mac_addr_t):  ");
    out += LOCI_DUMP_mac(writer, cookie, mac_addr);
    out += writer(cookie, "\n");

    of_match_v2_vlan_vid_get(obj, &val16);
    out += writer(cookie, "  vlan_vid (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_match_v2_vlan_pcp_get(obj, &val8);
    out += writer(cookie, "  vlan_pcp (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_match_v2_eth_type_get(obj, &val16);
    out += writer(cookie, "  eth_type (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_match_v2_ip_dscp_get(obj, &val8);
    out += writer(cookie, "  ip_dscp (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_match_v2_ip_proto_get(obj, &val8);
    out += writer(cookie, "  ip_proto (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_match_v2_ipv4_src_get(obj, &ipv4);
    out += writer(cookie, "  ipv4_src (of_ipv4_t):  ");
    out += LOCI_DUMP_ipv4(writer, cookie, ipv4);
    out += writer(cookie, "\n");

    of_match_v2_ipv4_src_mask_get(obj, &ipv4);
    out += writer(cookie, "  ipv4_src_mask (of_ipv4_t):  ");
    out += LOCI_DUMP_ipv4(writer, cookie, ipv4);
    out += writer(cookie, "\n");

    of_match_v2_ipv4_dst_get(obj, &ipv4);
    out += writer(cookie, "  ipv4_dst (of_ipv4_t):  ");
    out += LOCI_DUMP_ipv4(writer, cookie, ipv4);
    out += writer(cookie, "\n");

    of_match_v2_ipv4_dst_mask_get(obj, &ipv4);
    out += writer(cookie, "  ipv4_dst_mask (of_ipv4_t):  ");
    out += LOCI_DUMP_ipv4(writer, cookie, ipv4);
    out += writer(cookie, "\n");

    of_match_v2_tcp_src_get(obj, &val16);
    out += writer(cookie, "  tcp_src (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_match_v2_tcp_dst_get(obj, &val16);
    out += writer(cookie, "  tcp_dst (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_match_v2_mpls_label_get(obj, &val32);
    out += writer(cookie, "  mpls_label (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_match_v2_mpls_tc_get(obj, &val8);
    out += writer(cookie, "  mpls_tc (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_match_v2_metadata_get(obj, &val64);
    out += writer(cookie, "  metadata (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_match_v2_metadata_mask_get(obj, &val64);
    out += writer(cookie, "  metadata_mask (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    return out;
}

int
of_packet_queue_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_packet_queue_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_list_queue_prop_t list;
    of_queue_prop_t elt;
    int rv;

    out += writer(cookie, "Object of type of_packet_queue\n");

    of_packet_queue_queue_id_get(obj, &val32);
    out += writer(cookie, "  queue_id (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_queue_prop_t\n");
    of_packet_queue_properties_bind(obj, &list);
    OF_LIST_QUEUE_PROP_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_port_desc_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_port_desc_t *obj)
{
    int out = 0;
    of_port_no_t port_no;
    of_mac_addr_t mac_addr;
    of_port_name_t port_name;
    uint32_t val32;

    out += writer(cookie, "Object of type of_port_desc\n");

    of_port_desc_port_no_get(obj, &port_no);
    out += writer(cookie, "  port_no (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_port_desc_hw_addr_get(obj, &mac_addr);
    out += writer(cookie, "  hw_addr (of_mac_addr_t):  ");
    out += LOCI_DUMP_mac(writer, cookie, mac_addr);
    out += writer(cookie, "\n");

    of_port_desc_name_get(obj, &port_name);
    out += writer(cookie, "  name (of_port_name_t):  ");
    out += LOCI_DUMP_port_name(writer, cookie, port_name);
    out += writer(cookie, "\n");

    of_port_desc_config_get(obj, &val32);
    out += writer(cookie, "  config (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_port_desc_state_get(obj, &val32);
    out += writer(cookie, "  state (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_port_desc_curr_get(obj, &val32);
    out += writer(cookie, "  curr (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_port_desc_advertised_get(obj, &val32);
    out += writer(cookie, "  advertised (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_port_desc_supported_get(obj, &val32);
    out += writer(cookie, "  supported (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_port_desc_peer_get(obj, &val32);
    out += writer(cookie, "  peer (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_port_desc_curr_speed_get(obj, &val32);
    out += writer(cookie, "  curr_speed (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_port_desc_max_speed_get(obj, &val32);
    out += writer(cookie, "  max_speed (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_port_stats_entry_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_port_stats_entry_t *obj)
{
    int out = 0;
    of_port_no_t port_no;
    uint64_t val64;

    out += writer(cookie, "Object of type of_port_stats_entry\n");

    of_port_stats_entry_port_no_get(obj, &port_no);
    out += writer(cookie, "  port_no (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_port_stats_entry_rx_packets_get(obj, &val64);
    out += writer(cookie, "  rx_packets (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_port_stats_entry_tx_packets_get(obj, &val64);
    out += writer(cookie, "  tx_packets (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_port_stats_entry_rx_bytes_get(obj, &val64);
    out += writer(cookie, "  rx_bytes (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_port_stats_entry_tx_bytes_get(obj, &val64);
    out += writer(cookie, "  tx_bytes (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_port_stats_entry_rx_dropped_get(obj, &val64);
    out += writer(cookie, "  rx_dropped (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_port_stats_entry_tx_dropped_get(obj, &val64);
    out += writer(cookie, "  tx_dropped (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_port_stats_entry_rx_errors_get(obj, &val64);
    out += writer(cookie, "  rx_errors (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_port_stats_entry_tx_errors_get(obj, &val64);
    out += writer(cookie, "  tx_errors (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_port_stats_entry_rx_frame_err_get(obj, &val64);
    out += writer(cookie, "  rx_frame_err (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_port_stats_entry_rx_over_err_get(obj, &val64);
    out += writer(cookie, "  rx_over_err (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_port_stats_entry_rx_crc_err_get(obj, &val64);
    out += writer(cookie, "  rx_crc_err (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_port_stats_entry_collisions_get(obj, &val64);
    out += writer(cookie, "  collisions (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    return out;
}

int
of_queue_prop_header_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_queue_prop_header_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_queue_prop_header\n");

    return out;
}

int
of_queue_prop_min_rate_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_queue_prop_min_rate_t *obj)
{
    int out = 0;
    uint16_t val16;

    out += writer(cookie, "Object of type of_queue_prop_min_rate\n");

    of_queue_prop_min_rate_rate_get(obj, &val16);
    out += writer(cookie, "  rate (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_queue_stats_entry_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_queue_stats_entry_t *obj)
{
    int out = 0;
    of_port_no_t port_no;
    uint32_t val32;
    uint64_t val64;

    out += writer(cookie, "Object of type of_queue_stats_entry\n");

    of_queue_stats_entry_port_no_get(obj, &port_no);
    out += writer(cookie, "  port_no (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_queue_stats_entry_queue_id_get(obj, &val32);
    out += writer(cookie, "  queue_id (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_queue_stats_entry_tx_bytes_get(obj, &val64);
    out += writer(cookie, "  tx_bytes (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_queue_stats_entry_tx_packets_get(obj, &val64);
    out += writer(cookie, "  tx_packets (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_queue_stats_entry_tx_errors_get(obj, &val64);
    out += writer(cookie, "  tx_errors (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    return out;
}

int
of_table_stats_entry_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_table_stats_entry_t *obj)
{
    int out = 0;
    uint8_t val8;
    of_table_name_t table_name;
    of_wc_bmap_t wc_bmap;
    of_match_bmap_t match_bmap;
    uint32_t val32;
    uint64_t val64;

    out += writer(cookie, "Object of type of_table_stats_entry\n");

    of_table_stats_entry_table_id_get(obj, &val8);
    out += writer(cookie, "  table_id (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_table_stats_entry_name_get(obj, &table_name);
    out += writer(cookie, "  name (of_table_name_t):  ");
    out += LOCI_DUMP_tab_name(writer, cookie, table_name);
    out += writer(cookie, "\n");

    of_table_stats_entry_wildcards_get(obj, &wc_bmap);
    out += writer(cookie, "  wildcards (of_wc_bmap_t):  ");
    out += LOCI_DUMP_wc_bmap(writer, cookie, wc_bmap);
    out += writer(cookie, "\n");

    of_table_stats_entry_match_get(obj, &match_bmap);
    out += writer(cookie, "  match (of_match_bmap_t):  ");
    out += LOCI_DUMP_match_bmap(writer, cookie, match_bmap);
    out += writer(cookie, "\n");

    of_table_stats_entry_instructions_get(obj, &val32);
    out += writer(cookie, "  instructions (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_table_stats_entry_write_actions_get(obj, &val32);
    out += writer(cookie, "  write_actions (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_table_stats_entry_apply_actions_get(obj, &val32);
    out += writer(cookie, "  apply_actions (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_table_stats_entry_config_get(obj, &val32);
    out += writer(cookie, "  config (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_table_stats_entry_max_entries_get(obj, &val32);
    out += writer(cookie, "  max_entries (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_table_stats_entry_active_count_get(obj, &val32);
    out += writer(cookie, "  active_count (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_table_stats_entry_lookup_count_get(obj, &val64);
    out += writer(cookie, "  lookup_count (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_table_stats_entry_matched_count_get(obj, &val64);
    out += writer(cookie, "  matched_count (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    return out;
}

int
of_list_action_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_list_action_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_list_action\n");

    return out;
}

int
of_list_bsn_interface_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_list_bsn_interface_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_list_bsn_interface\n");

    return out;
}

int
of_list_bucket_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_list_bucket_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_list_bucket\n");

    return out;
}

int
of_list_bucket_counter_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_list_bucket_counter_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_list_bucket_counter\n");

    return out;
}

int
of_list_flow_stats_entry_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_list_flow_stats_entry_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_list_flow_stats_entry\n");

    return out;
}

int
of_list_group_desc_stats_entry_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_list_group_desc_stats_entry_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_list_group_desc_stats_entry\n");

    return out;
}

int
of_list_group_stats_entry_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_list_group_stats_entry_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_list_group_stats_entry\n");

    return out;
}

int
of_list_instruction_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_list_instruction_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_list_instruction\n");

    return out;
}

int
of_list_packet_queue_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_list_packet_queue_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_list_packet_queue\n");

    return out;
}

int
of_list_port_desc_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_list_port_desc_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_list_port_desc\n");

    return out;
}

int
of_list_port_stats_entry_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_list_port_stats_entry_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_list_port_stats_entry\n");

    return out;
}

int
of_list_queue_prop_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_list_queue_prop_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_list_queue_prop\n");

    return out;
}

int
of_list_queue_stats_entry_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_list_queue_stats_entry_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_list_queue_stats_entry\n");

    return out;
}

int
of_list_table_stats_entry_OF_VERSION_1_1_dump(loci_writer_f writer, void* cookie, of_list_table_stats_entry_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_list_table_stats_entry\n");

    return out;
}

int
of_aggregate_stats_reply_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_aggregate_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    uint64_t val64;

    out += writer(cookie, "Object of type of_aggregate_stats_reply\n");

    of_aggregate_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_aggregate_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_aggregate_stats_reply_packet_count_get(obj, &val64);
    out += writer(cookie, "  packet_count (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_aggregate_stats_reply_byte_count_get(obj, &val64);
    out += writer(cookie, "  byte_count (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_aggregate_stats_reply_flow_count_get(obj, &val32);
    out += writer(cookie, "  flow_count (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_aggregate_stats_request_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_aggregate_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    uint8_t val8;
    of_port_no_t port_no;
    uint64_t val64;
    of_match_t match;

    out += writer(cookie, "Object of type of_aggregate_stats_request\n");

    of_aggregate_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_aggregate_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_aggregate_stats_request_table_id_get(obj, &val8);
    out += writer(cookie, "  table_id (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_aggregate_stats_request_out_port_get(obj, &port_no);
    out += writer(cookie, "  out_port (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_aggregate_stats_request_out_group_get(obj, &val32);
    out += writer(cookie, "  out_group (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_aggregate_stats_request_cookie_get(obj, &val64);
    out += writer(cookie, "  cookie (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_aggregate_stats_request_cookie_mask_get(obj, &val64);
    out += writer(cookie, "  cookie_mask (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_aggregate_stats_request_match_get(obj, &match);
    out += writer(cookie, "  match (of_match_t):  ");
    out += LOCI_DUMP_match(writer, cookie, match);
    out += writer(cookie, "\n");

    return out;
}

int
of_bad_action_error_msg_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_bad_action_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_bad_action_error_msg\n");

    of_bad_action_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bad_action_error_msg_code_get(obj, &val16);
    out += writer(cookie, "  code (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_bad_action_error_msg_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_bad_instruction_error_msg_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_bad_instruction_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_bad_instruction_error_msg\n");

    of_bad_instruction_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bad_instruction_error_msg_code_get(obj, &val16);
    out += writer(cookie, "  code (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_bad_instruction_error_msg_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_bad_match_error_msg_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_bad_match_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_bad_match_error_msg\n");

    of_bad_match_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bad_match_error_msg_code_get(obj, &val16);
    out += writer(cookie, "  code (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_bad_match_error_msg_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_bad_request_error_msg_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_bad_request_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_bad_request_error_msg\n");

    of_bad_request_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bad_request_error_msg_code_get(obj, &val16);
    out += writer(cookie, "  code (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_bad_request_error_msg_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_barrier_reply_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_barrier_reply_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_barrier_reply\n");

    of_barrier_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_barrier_request_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_barrier_request_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_barrier_request\n");

    of_barrier_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_bw_clear_data_reply_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_bsn_bw_clear_data_reply_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_bsn_bw_clear_data_reply\n");

    of_bsn_bw_clear_data_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_bw_clear_data_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_bw_clear_data_reply_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_bw_clear_data_reply_status_get(obj, &val32);
    out += writer(cookie, "  status (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_bw_clear_data_request_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_bsn_bw_clear_data_request_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_bsn_bw_clear_data_request\n");

    of_bsn_bw_clear_data_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_bw_clear_data_request_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_bw_clear_data_request_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_bw_enable_get_reply_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_bsn_bw_enable_get_reply_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_bsn_bw_enable_get_reply\n");

    of_bsn_bw_enable_get_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_bw_enable_get_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_bw_enable_get_reply_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_bw_enable_get_reply_enabled_get(obj, &val32);
    out += writer(cookie, "  enabled (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_bw_enable_get_request_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_bsn_bw_enable_get_request_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_bsn_bw_enable_get_request\n");

    of_bsn_bw_enable_get_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_bw_enable_get_request_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_bw_enable_get_request_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_bw_enable_set_reply_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_bsn_bw_enable_set_reply_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_bsn_bw_enable_set_reply\n");

    of_bsn_bw_enable_set_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_bw_enable_set_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_bw_enable_set_reply_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_bw_enable_set_reply_enable_get(obj, &val32);
    out += writer(cookie, "  enable (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_bw_enable_set_reply_status_get(obj, &val32);
    out += writer(cookie, "  status (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_bw_enable_set_request_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_bsn_bw_enable_set_request_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_bsn_bw_enable_set_request\n");

    of_bsn_bw_enable_set_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_bw_enable_set_request_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_bw_enable_set_request_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_bw_enable_set_request_enable_get(obj, &val32);
    out += writer(cookie, "  enable (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_get_interfaces_reply_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_bsn_get_interfaces_reply_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_list_bsn_interface_t list;
    of_bsn_interface_t elt;
    int rv;

    out += writer(cookie, "Object of type of_bsn_get_interfaces_reply\n");

    of_bsn_get_interfaces_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_get_interfaces_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_get_interfaces_reply_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_bsn_interface_t\n");
    of_bsn_get_interfaces_reply_interfaces_bind(obj, &list);
    OF_LIST_BSN_INTERFACE_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_bsn_get_interfaces_request_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_bsn_get_interfaces_request_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_bsn_get_interfaces_request\n");

    of_bsn_get_interfaces_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_get_interfaces_request_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_get_interfaces_request_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_get_mirroring_reply_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_bsn_get_mirroring_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint8_t val8;

    out += writer(cookie, "Object of type of_bsn_get_mirroring_reply\n");

    of_bsn_get_mirroring_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_get_mirroring_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_get_mirroring_reply_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_get_mirroring_reply_report_mirror_ports_get(obj, &val8);
    out += writer(cookie, "  report_mirror_ports (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_get_mirroring_request_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_bsn_get_mirroring_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint8_t val8;

    out += writer(cookie, "Object of type of_bsn_get_mirroring_request\n");

    of_bsn_get_mirroring_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_get_mirroring_request_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_get_mirroring_request_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_get_mirroring_request_report_mirror_ports_get(obj, &val8);
    out += writer(cookie, "  report_mirror_ports (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_header_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_bsn_header_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_bsn_header\n");

    of_bsn_header_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_header_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_header_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_pdu_rx_reply_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_bsn_pdu_rx_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_port_no_t port_no;
    uint8_t val8;

    out += writer(cookie, "Object of type of_bsn_pdu_rx_reply\n");

    of_bsn_pdu_rx_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_pdu_rx_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_pdu_rx_reply_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_pdu_rx_reply_status_get(obj, &val32);
    out += writer(cookie, "  status (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_pdu_rx_reply_port_no_get(obj, &port_no);
    out += writer(cookie, "  port_no (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_bsn_pdu_rx_reply_slot_num_get(obj, &val8);
    out += writer(cookie, "  slot_num (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_pdu_rx_request_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_bsn_pdu_rx_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_port_no_t port_no;
    uint8_t val8;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_bsn_pdu_rx_request\n");

    of_bsn_pdu_rx_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_pdu_rx_request_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_pdu_rx_request_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_pdu_rx_request_timeout_ms_get(obj, &val32);
    out += writer(cookie, "  timeout_ms (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_pdu_rx_request_port_no_get(obj, &port_no);
    out += writer(cookie, "  port_no (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_bsn_pdu_rx_request_slot_num_get(obj, &val8);
    out += writer(cookie, "  slot_num (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_bsn_pdu_rx_request_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_pdu_rx_timeout_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_bsn_pdu_rx_timeout_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_port_no_t port_no;
    uint8_t val8;

    out += writer(cookie, "Object of type of_bsn_pdu_rx_timeout\n");

    of_bsn_pdu_rx_timeout_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_pdu_rx_timeout_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_pdu_rx_timeout_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_pdu_rx_timeout_port_no_get(obj, &port_no);
    out += writer(cookie, "  port_no (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_bsn_pdu_rx_timeout_slot_num_get(obj, &val8);
    out += writer(cookie, "  slot_num (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_pdu_tx_reply_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_bsn_pdu_tx_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_port_no_t port_no;
    uint8_t val8;

    out += writer(cookie, "Object of type of_bsn_pdu_tx_reply\n");

    of_bsn_pdu_tx_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_pdu_tx_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_pdu_tx_reply_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_pdu_tx_reply_status_get(obj, &val32);
    out += writer(cookie, "  status (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_pdu_tx_reply_port_no_get(obj, &port_no);
    out += writer(cookie, "  port_no (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_bsn_pdu_tx_reply_slot_num_get(obj, &val8);
    out += writer(cookie, "  slot_num (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_pdu_tx_request_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_bsn_pdu_tx_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_port_no_t port_no;
    uint8_t val8;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_bsn_pdu_tx_request\n");

    of_bsn_pdu_tx_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_pdu_tx_request_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_pdu_tx_request_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_pdu_tx_request_tx_interval_ms_get(obj, &val32);
    out += writer(cookie, "  tx_interval_ms (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_pdu_tx_request_port_no_get(obj, &port_no);
    out += writer(cookie, "  port_no (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_bsn_pdu_tx_request_slot_num_get(obj, &val8);
    out += writer(cookie, "  slot_num (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_bsn_pdu_tx_request_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_set_mirroring_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_bsn_set_mirroring_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint8_t val8;

    out += writer(cookie, "Object of type of_bsn_set_mirroring\n");

    of_bsn_set_mirroring_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_set_mirroring_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_set_mirroring_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_set_mirroring_report_mirror_ports_get(obj, &val8);
    out += writer(cookie, "  report_mirror_ports (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_set_pktin_suppression_reply_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_bsn_set_pktin_suppression_reply_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_bsn_set_pktin_suppression_reply\n");

    of_bsn_set_pktin_suppression_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_set_pktin_suppression_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_set_pktin_suppression_reply_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_set_pktin_suppression_reply_status_get(obj, &val32);
    out += writer(cookie, "  status (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_set_pktin_suppression_request_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_bsn_set_pktin_suppression_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint8_t val8;
    uint16_t val16;
    uint64_t val64;

    out += writer(cookie, "Object of type of_bsn_set_pktin_suppression_request\n");

    of_bsn_set_pktin_suppression_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_set_pktin_suppression_request_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_set_pktin_suppression_request_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_set_pktin_suppression_request_enabled_get(obj, &val8);
    out += writer(cookie, "  enabled (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_bsn_set_pktin_suppression_request_idle_timeout_get(obj, &val16);
    out += writer(cookie, "  idle_timeout (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_bsn_set_pktin_suppression_request_hard_timeout_get(obj, &val16);
    out += writer(cookie, "  hard_timeout (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_bsn_set_pktin_suppression_request_priority_get(obj, &val16);
    out += writer(cookie, "  priority (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_bsn_set_pktin_suppression_request_cookie_get(obj, &val64);
    out += writer(cookie, "  cookie (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_stats_reply_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_bsn_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    out += writer(cookie, "Object of type of_bsn_stats_reply\n");

    of_bsn_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_bsn_stats_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_stats_reply_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_stats_request_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_bsn_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    out += writer(cookie, "Object of type of_bsn_stats_request\n");

    of_bsn_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_bsn_stats_request_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_stats_request_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_virtual_port_create_reply_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_bsn_virtual_port_create_reply_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_bsn_virtual_port_create_reply\n");

    of_bsn_virtual_port_create_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_virtual_port_create_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_virtual_port_create_reply_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_virtual_port_create_reply_status_get(obj, &val32);
    out += writer(cookie, "  status (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_virtual_port_create_reply_vport_no_get(obj, &val32);
    out += writer(cookie, "  vport_no (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_virtual_port_create_request_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_bsn_virtual_port_create_request_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_bsn_vport_q_in_q_t vport;

    out += writer(cookie, "Object of type of_bsn_virtual_port_create_request\n");

    of_bsn_virtual_port_create_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_virtual_port_create_request_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_virtual_port_create_request_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_virtual_port_create_request_vport_bind(obj, &vport);
    out += of_bsn_vport_q_in_q_OF_VERSION_1_2_dump(writer, cookie, &vport);

    return out;
}

int
of_bsn_virtual_port_remove_reply_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_bsn_virtual_port_remove_reply_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_bsn_virtual_port_remove_reply\n");

    of_bsn_virtual_port_remove_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_virtual_port_remove_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_virtual_port_remove_reply_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_virtual_port_remove_reply_status_get(obj, &val32);
    out += writer(cookie, "  status (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_virtual_port_remove_request_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_bsn_virtual_port_remove_request_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_bsn_virtual_port_remove_request\n");

    of_bsn_virtual_port_remove_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_virtual_port_remove_request_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_virtual_port_remove_request_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_virtual_port_remove_request_vport_no_get(obj, &val32);
    out += writer(cookie, "  vport_no (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_desc_stats_reply_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_desc_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_desc_str_t desc_str;
    of_serial_num_t ser_num;

    out += writer(cookie, "Object of type of_desc_stats_reply\n");

    of_desc_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_desc_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_desc_stats_reply_mfr_desc_get(obj, &desc_str);
    out += writer(cookie, "  mfr_desc (of_desc_str_t):  ");
    out += LOCI_DUMP_desc_str(writer, cookie, desc_str);
    out += writer(cookie, "\n");

    of_desc_stats_reply_hw_desc_get(obj, &desc_str);
    out += writer(cookie, "  hw_desc (of_desc_str_t):  ");
    out += LOCI_DUMP_desc_str(writer, cookie, desc_str);
    out += writer(cookie, "\n");

    of_desc_stats_reply_sw_desc_get(obj, &desc_str);
    out += writer(cookie, "  sw_desc (of_desc_str_t):  ");
    out += LOCI_DUMP_desc_str(writer, cookie, desc_str);
    out += writer(cookie, "\n");

    of_desc_stats_reply_serial_num_get(obj, &ser_num);
    out += writer(cookie, "  serial_num (of_serial_num_t):  ");
    out += LOCI_DUMP_ser_num(writer, cookie, ser_num);
    out += writer(cookie, "\n");

    of_desc_stats_reply_dp_desc_get(obj, &desc_str);
    out += writer(cookie, "  dp_desc (of_desc_str_t):  ");
    out += LOCI_DUMP_desc_str(writer, cookie, desc_str);
    out += writer(cookie, "\n");

    return out;
}

int
of_desc_stats_request_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_desc_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    out += writer(cookie, "Object of type of_desc_stats_request\n");

    of_desc_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_desc_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_echo_reply_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_echo_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_echo_reply\n");

    of_echo_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_echo_reply_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_echo_request_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_echo_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_echo_request\n");

    of_echo_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_echo_request_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_error_msg_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_error_msg\n");

    of_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_experimenter_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_experimenter_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_experimenter\n");

    of_experimenter_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_experimenter_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_experimenter_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_experimenter_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_experimenter_error_msg_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_experimenter_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_experimenter_error_msg\n");

    of_experimenter_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_experimenter_error_msg_subtype_get(obj, &val16);
    out += writer(cookie, "  subtype (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_experimenter_error_msg_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_experimenter_error_msg_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_experimenter_stats_reply_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_experimenter_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_experimenter_stats_reply\n");

    of_experimenter_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_experimenter_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_experimenter_stats_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_experimenter_stats_reply_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_experimenter_stats_reply_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_experimenter_stats_request_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_experimenter_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_experimenter_stats_request\n");

    of_experimenter_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_experimenter_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_experimenter_stats_request_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_experimenter_stats_request_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_experimenter_stats_request_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_features_reply_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_features_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint64_t val64;
    uint8_t val8;

    of_list_port_desc_t list;
    of_port_desc_t elt;
    int rv;

    out += writer(cookie, "Object of type of_features_reply\n");

    of_features_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_features_reply_datapath_id_get(obj, &val64);
    out += writer(cookie, "  datapath_id (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_features_reply_n_buffers_get(obj, &val32);
    out += writer(cookie, "  n_buffers (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_features_reply_n_tables_get(obj, &val8);
    out += writer(cookie, "  n_tables (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_features_reply_capabilities_get(obj, &val32);
    out += writer(cookie, "  capabilities (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_features_reply_reserved_get(obj, &val32);
    out += writer(cookie, "  reserved (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_port_desc_t\n");
    of_features_reply_ports_bind(obj, &list);
    OF_LIST_PORT_DESC_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_features_request_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_features_request_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_features_request\n");

    of_features_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_flow_add_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_flow_add_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint64_t val64;
    uint8_t val8;
    uint16_t val16;
    of_port_no_t port_no;
    of_match_t match;

    of_list_instruction_t list;
    of_instruction_t elt;
    int rv;

    out += writer(cookie, "Object of type of_flow_add\n");

    of_flow_add_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_add_cookie_get(obj, &val64);
    out += writer(cookie, "  cookie (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_flow_add_cookie_mask_get(obj, &val64);
    out += writer(cookie, "  cookie_mask (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_flow_add_table_id_get(obj, &val8);
    out += writer(cookie, "  table_id (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_flow_add_idle_timeout_get(obj, &val16);
    out += writer(cookie, "  idle_timeout (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_add_hard_timeout_get(obj, &val16);
    out += writer(cookie, "  hard_timeout (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_add_priority_get(obj, &val16);
    out += writer(cookie, "  priority (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_add_buffer_id_get(obj, &val32);
    out += writer(cookie, "  buffer_id (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_add_out_port_get(obj, &port_no);
    out += writer(cookie, "  out_port (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_flow_add_out_group_get(obj, &val32);
    out += writer(cookie, "  out_group (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_add_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_add_match_get(obj, &match);
    out += writer(cookie, "  match (of_match_t):  ");
    out += LOCI_DUMP_match(writer, cookie, match);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_instruction_t\n");
    of_flow_add_instructions_bind(obj, &list);
    OF_LIST_INSTRUCTION_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_flow_delete_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_flow_delete_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint64_t val64;
    uint8_t val8;
    uint16_t val16;
    of_port_no_t port_no;
    of_match_t match;

    of_list_instruction_t list;
    of_instruction_t elt;
    int rv;

    out += writer(cookie, "Object of type of_flow_delete\n");

    of_flow_delete_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_delete_cookie_get(obj, &val64);
    out += writer(cookie, "  cookie (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_flow_delete_cookie_mask_get(obj, &val64);
    out += writer(cookie, "  cookie_mask (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_flow_delete_table_id_get(obj, &val8);
    out += writer(cookie, "  table_id (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_flow_delete_idle_timeout_get(obj, &val16);
    out += writer(cookie, "  idle_timeout (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_delete_hard_timeout_get(obj, &val16);
    out += writer(cookie, "  hard_timeout (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_delete_priority_get(obj, &val16);
    out += writer(cookie, "  priority (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_delete_buffer_id_get(obj, &val32);
    out += writer(cookie, "  buffer_id (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_delete_out_port_get(obj, &port_no);
    out += writer(cookie, "  out_port (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_flow_delete_out_group_get(obj, &val32);
    out += writer(cookie, "  out_group (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_delete_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_delete_match_get(obj, &match);
    out += writer(cookie, "  match (of_match_t):  ");
    out += LOCI_DUMP_match(writer, cookie, match);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_instruction_t\n");
    of_flow_delete_instructions_bind(obj, &list);
    OF_LIST_INSTRUCTION_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_flow_delete_strict_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_flow_delete_strict_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint64_t val64;
    uint8_t val8;
    uint16_t val16;
    of_port_no_t port_no;
    of_match_t match;

    of_list_instruction_t list;
    of_instruction_t elt;
    int rv;

    out += writer(cookie, "Object of type of_flow_delete_strict\n");

    of_flow_delete_strict_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_delete_strict_cookie_get(obj, &val64);
    out += writer(cookie, "  cookie (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_flow_delete_strict_cookie_mask_get(obj, &val64);
    out += writer(cookie, "  cookie_mask (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_flow_delete_strict_table_id_get(obj, &val8);
    out += writer(cookie, "  table_id (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_flow_delete_strict_idle_timeout_get(obj, &val16);
    out += writer(cookie, "  idle_timeout (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_delete_strict_hard_timeout_get(obj, &val16);
    out += writer(cookie, "  hard_timeout (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_delete_strict_priority_get(obj, &val16);
    out += writer(cookie, "  priority (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_delete_strict_buffer_id_get(obj, &val32);
    out += writer(cookie, "  buffer_id (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_delete_strict_out_port_get(obj, &port_no);
    out += writer(cookie, "  out_port (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_flow_delete_strict_out_group_get(obj, &val32);
    out += writer(cookie, "  out_group (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_delete_strict_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_delete_strict_match_get(obj, &match);
    out += writer(cookie, "  match (of_match_t):  ");
    out += LOCI_DUMP_match(writer, cookie, match);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_instruction_t\n");
    of_flow_delete_strict_instructions_bind(obj, &list);
    OF_LIST_INSTRUCTION_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_flow_mod_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_flow_mod_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint64_t val64;
    uint8_t val8;
    uint16_t val16;
    of_port_no_t port_no;
    of_match_t match;

    of_list_instruction_t list;
    of_instruction_t elt;
    int rv;

    out += writer(cookie, "Object of type of_flow_mod\n");

    of_flow_mod_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_mod_cookie_get(obj, &val64);
    out += writer(cookie, "  cookie (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_flow_mod_cookie_mask_get(obj, &val64);
    out += writer(cookie, "  cookie_mask (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_flow_mod_table_id_get(obj, &val8);
    out += writer(cookie, "  table_id (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_flow_mod_idle_timeout_get(obj, &val16);
    out += writer(cookie, "  idle_timeout (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_mod_hard_timeout_get(obj, &val16);
    out += writer(cookie, "  hard_timeout (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_mod_priority_get(obj, &val16);
    out += writer(cookie, "  priority (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_mod_buffer_id_get(obj, &val32);
    out += writer(cookie, "  buffer_id (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_mod_out_port_get(obj, &port_no);
    out += writer(cookie, "  out_port (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_flow_mod_out_group_get(obj, &val32);
    out += writer(cookie, "  out_group (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_mod_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_mod_match_get(obj, &match);
    out += writer(cookie, "  match (of_match_t):  ");
    out += LOCI_DUMP_match(writer, cookie, match);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_instruction_t\n");
    of_flow_mod_instructions_bind(obj, &list);
    OF_LIST_INSTRUCTION_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_flow_mod_failed_error_msg_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_flow_mod_failed_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_flow_mod_failed_error_msg\n");

    of_flow_mod_failed_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_mod_failed_error_msg_code_get(obj, &val16);
    out += writer(cookie, "  code (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_mod_failed_error_msg_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_flow_modify_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_flow_modify_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint64_t val64;
    uint8_t val8;
    uint16_t val16;
    of_port_no_t port_no;
    of_match_t match;

    of_list_instruction_t list;
    of_instruction_t elt;
    int rv;

    out += writer(cookie, "Object of type of_flow_modify\n");

    of_flow_modify_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_modify_cookie_get(obj, &val64);
    out += writer(cookie, "  cookie (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_flow_modify_cookie_mask_get(obj, &val64);
    out += writer(cookie, "  cookie_mask (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_flow_modify_table_id_get(obj, &val8);
    out += writer(cookie, "  table_id (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_flow_modify_idle_timeout_get(obj, &val16);
    out += writer(cookie, "  idle_timeout (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_modify_hard_timeout_get(obj, &val16);
    out += writer(cookie, "  hard_timeout (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_modify_priority_get(obj, &val16);
    out += writer(cookie, "  priority (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_modify_buffer_id_get(obj, &val32);
    out += writer(cookie, "  buffer_id (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_modify_out_port_get(obj, &port_no);
    out += writer(cookie, "  out_port (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_flow_modify_out_group_get(obj, &val32);
    out += writer(cookie, "  out_group (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_modify_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_modify_match_get(obj, &match);
    out += writer(cookie, "  match (of_match_t):  ");
    out += LOCI_DUMP_match(writer, cookie, match);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_instruction_t\n");
    of_flow_modify_instructions_bind(obj, &list);
    OF_LIST_INSTRUCTION_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_flow_modify_strict_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_flow_modify_strict_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint64_t val64;
    uint8_t val8;
    uint16_t val16;
    of_port_no_t port_no;
    of_match_t match;

    of_list_instruction_t list;
    of_instruction_t elt;
    int rv;

    out += writer(cookie, "Object of type of_flow_modify_strict\n");

    of_flow_modify_strict_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_modify_strict_cookie_get(obj, &val64);
    out += writer(cookie, "  cookie (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_flow_modify_strict_cookie_mask_get(obj, &val64);
    out += writer(cookie, "  cookie_mask (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_flow_modify_strict_table_id_get(obj, &val8);
    out += writer(cookie, "  table_id (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_flow_modify_strict_idle_timeout_get(obj, &val16);
    out += writer(cookie, "  idle_timeout (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_modify_strict_hard_timeout_get(obj, &val16);
    out += writer(cookie, "  hard_timeout (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_modify_strict_priority_get(obj, &val16);
    out += writer(cookie, "  priority (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_modify_strict_buffer_id_get(obj, &val32);
    out += writer(cookie, "  buffer_id (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_modify_strict_out_port_get(obj, &port_no);
    out += writer(cookie, "  out_port (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_flow_modify_strict_out_group_get(obj, &val32);
    out += writer(cookie, "  out_group (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_modify_strict_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_modify_strict_match_get(obj, &match);
    out += writer(cookie, "  match (of_match_t):  ");
    out += LOCI_DUMP_match(writer, cookie, match);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_instruction_t\n");
    of_flow_modify_strict_instructions_bind(obj, &list);
    OF_LIST_INSTRUCTION_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_flow_removed_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_flow_removed_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint64_t val64;
    uint16_t val16;
    uint8_t val8;
    of_match_t match;

    out += writer(cookie, "Object of type of_flow_removed\n");

    of_flow_removed_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_removed_cookie_get(obj, &val64);
    out += writer(cookie, "  cookie (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_flow_removed_priority_get(obj, &val16);
    out += writer(cookie, "  priority (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_removed_reason_get(obj, &val8);
    out += writer(cookie, "  reason (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_flow_removed_table_id_get(obj, &val8);
    out += writer(cookie, "  table_id (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_flow_removed_duration_sec_get(obj, &val32);
    out += writer(cookie, "  duration_sec (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_removed_duration_nsec_get(obj, &val32);
    out += writer(cookie, "  duration_nsec (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_removed_idle_timeout_get(obj, &val16);
    out += writer(cookie, "  idle_timeout (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_removed_hard_timeout_get(obj, &val16);
    out += writer(cookie, "  hard_timeout (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_removed_packet_count_get(obj, &val64);
    out += writer(cookie, "  packet_count (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_flow_removed_byte_count_get(obj, &val64);
    out += writer(cookie, "  byte_count (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_flow_removed_match_get(obj, &match);
    out += writer(cookie, "  match (of_match_t):  ");
    out += LOCI_DUMP_match(writer, cookie, match);
    out += writer(cookie, "\n");

    return out;
}

int
of_flow_stats_reply_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_flow_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_list_flow_stats_entry_t list;
    of_flow_stats_entry_t elt;
    int rv;

    out += writer(cookie, "Object of type of_flow_stats_reply\n");

    of_flow_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_flow_stats_entry_t\n");
    of_flow_stats_reply_entries_bind(obj, &list);
    OF_LIST_FLOW_STATS_ENTRY_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_flow_stats_request_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_flow_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    uint8_t val8;
    of_port_no_t port_no;
    uint64_t val64;
    of_match_t match;

    out += writer(cookie, "Object of type of_flow_stats_request\n");

    of_flow_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_stats_request_table_id_get(obj, &val8);
    out += writer(cookie, "  table_id (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_flow_stats_request_out_port_get(obj, &port_no);
    out += writer(cookie, "  out_port (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_flow_stats_request_out_group_get(obj, &val32);
    out += writer(cookie, "  out_group (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_stats_request_cookie_get(obj, &val64);
    out += writer(cookie, "  cookie (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_flow_stats_request_cookie_mask_get(obj, &val64);
    out += writer(cookie, "  cookie_mask (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_flow_stats_request_match_get(obj, &match);
    out += writer(cookie, "  match (of_match_t):  ");
    out += LOCI_DUMP_match(writer, cookie, match);
    out += writer(cookie, "\n");

    return out;
}

int
of_get_config_reply_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_get_config_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    out += writer(cookie, "Object of type of_get_config_reply\n");

    of_get_config_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_get_config_reply_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_get_config_reply_miss_send_len_get(obj, &val16);
    out += writer(cookie, "  miss_send_len (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_get_config_request_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_get_config_request_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_get_config_request\n");

    of_get_config_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_group_desc_stats_reply_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_group_desc_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_list_group_desc_stats_entry_t list;
    of_group_desc_stats_entry_t elt;
    int rv;

    out += writer(cookie, "Object of type of_group_desc_stats_reply\n");

    of_group_desc_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_group_desc_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_group_desc_stats_entry_t\n");
    of_group_desc_stats_reply_entries_bind(obj, &list);
    OF_LIST_GROUP_DESC_STATS_ENTRY_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_group_desc_stats_request_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_group_desc_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    out += writer(cookie, "Object of type of_group_desc_stats_request\n");

    of_group_desc_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_group_desc_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_group_features_stats_reply_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_group_features_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    out += writer(cookie, "Object of type of_group_features_stats_reply\n");

    of_group_features_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_group_features_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_group_features_stats_reply_types_get(obj, &val32);
    out += writer(cookie, "  types (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_group_features_stats_reply_capabilities_get(obj, &val32);
    out += writer(cookie, "  capabilities (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_group_features_stats_reply_max_groups_all_get(obj, &val32);
    out += writer(cookie, "  max_groups_all (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_group_features_stats_reply_max_groups_select_get(obj, &val32);
    out += writer(cookie, "  max_groups_select (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_group_features_stats_reply_max_groups_indirect_get(obj, &val32);
    out += writer(cookie, "  max_groups_indirect (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_group_features_stats_reply_max_groups_ff_get(obj, &val32);
    out += writer(cookie, "  max_groups_ff (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_group_features_stats_reply_actions_all_get(obj, &val32);
    out += writer(cookie, "  actions_all (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_group_features_stats_reply_actions_select_get(obj, &val32);
    out += writer(cookie, "  actions_select (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_group_features_stats_reply_actions_indirect_get(obj, &val32);
    out += writer(cookie, "  actions_indirect (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_group_features_stats_reply_actions_ff_get(obj, &val32);
    out += writer(cookie, "  actions_ff (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_group_features_stats_request_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_group_features_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    out += writer(cookie, "Object of type of_group_features_stats_request\n");

    of_group_features_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_group_features_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_group_mod_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_group_mod_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    uint8_t val8;

    of_list_bucket_t list;
    of_bucket_t elt;
    int rv;

    out += writer(cookie, "Object of type of_group_mod\n");

    of_group_mod_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_group_mod_command_get(obj, &val16);
    out += writer(cookie, "  command (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_group_mod_group_type_get(obj, &val8);
    out += writer(cookie, "  group_type (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_group_mod_group_id_get(obj, &val32);
    out += writer(cookie, "  group_id (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_bucket_t\n");
    of_group_mod_buckets_bind(obj, &list);
    OF_LIST_BUCKET_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_group_mod_failed_error_msg_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_group_mod_failed_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_group_mod_failed_error_msg\n");

    of_group_mod_failed_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_group_mod_failed_error_msg_code_get(obj, &val16);
    out += writer(cookie, "  code (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_group_mod_failed_error_msg_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_group_stats_reply_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_group_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_list_group_stats_entry_t list;
    of_group_stats_entry_t elt;
    int rv;

    out += writer(cookie, "Object of type of_group_stats_reply\n");

    of_group_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_group_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_group_stats_entry_t\n");
    of_group_stats_reply_entries_bind(obj, &list);
    OF_LIST_GROUP_STATS_ENTRY_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_group_stats_request_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_group_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    out += writer(cookie, "Object of type of_group_stats_request\n");

    of_group_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_group_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_group_stats_request_group_id_get(obj, &val32);
    out += writer(cookie, "  group_id (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_hello_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_hello_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_hello\n");

    of_hello_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_hello_failed_error_msg_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_hello_failed_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_hello_failed_error_msg\n");

    of_hello_failed_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_hello_failed_error_msg_code_get(obj, &val16);
    out += writer(cookie, "  code (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_hello_failed_error_msg_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_nicira_header_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_nicira_header_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_nicira_header\n");

    of_nicira_header_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_nicira_header_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_nicira_header_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_packet_in_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_packet_in_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    uint8_t val8;
    of_match_t match;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_packet_in\n");

    of_packet_in_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_packet_in_buffer_id_get(obj, &val32);
    out += writer(cookie, "  buffer_id (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_packet_in_total_len_get(obj, &val16);
    out += writer(cookie, "  total_len (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_packet_in_reason_get(obj, &val8);
    out += writer(cookie, "  reason (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_packet_in_table_id_get(obj, &val8);
    out += writer(cookie, "  table_id (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_packet_in_match_get(obj, &match);
    out += writer(cookie, "  match (of_match_t):  ");
    out += LOCI_DUMP_match(writer, cookie, match);
    out += writer(cookie, "\n");

    of_packet_in_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_packet_out_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_packet_out_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_port_no_t port_no;

    of_list_action_t list;
    of_action_t elt;
    int rv;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_packet_out\n");

    of_packet_out_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_packet_out_buffer_id_get(obj, &val32);
    out += writer(cookie, "  buffer_id (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_packet_out_in_port_get(obj, &port_no);
    out += writer(cookie, "  in_port (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_action_t\n");
    of_packet_out_actions_bind(obj, &list);
    OF_LIST_ACTION_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    of_packet_out_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_port_mod_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_port_mod_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_port_no_t port_no;
    of_mac_addr_t mac_addr;

    out += writer(cookie, "Object of type of_port_mod\n");

    of_port_mod_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_port_mod_port_no_get(obj, &port_no);
    out += writer(cookie, "  port_no (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_port_mod_hw_addr_get(obj, &mac_addr);
    out += writer(cookie, "  hw_addr (of_mac_addr_t):  ");
    out += LOCI_DUMP_mac(writer, cookie, mac_addr);
    out += writer(cookie, "\n");

    of_port_mod_config_get(obj, &val32);
    out += writer(cookie, "  config (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_port_mod_mask_get(obj, &val32);
    out += writer(cookie, "  mask (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_port_mod_advertise_get(obj, &val32);
    out += writer(cookie, "  advertise (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_port_mod_failed_error_msg_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_port_mod_failed_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_port_mod_failed_error_msg\n");

    of_port_mod_failed_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_port_mod_failed_error_msg_code_get(obj, &val16);
    out += writer(cookie, "  code (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_port_mod_failed_error_msg_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_port_stats_reply_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_port_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_list_port_stats_entry_t list;
    of_port_stats_entry_t elt;
    int rv;

    out += writer(cookie, "Object of type of_port_stats_reply\n");

    of_port_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_port_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_port_stats_entry_t\n");
    of_port_stats_reply_entries_bind(obj, &list);
    OF_LIST_PORT_STATS_ENTRY_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_port_stats_request_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_port_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_port_no_t port_no;

    out += writer(cookie, "Object of type of_port_stats_request\n");

    of_port_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_port_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_port_stats_request_port_no_get(obj, &port_no);
    out += writer(cookie, "  port_no (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    return out;
}

int
of_port_status_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_port_status_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint8_t val8;

    of_port_desc_t port_desc;

    out += writer(cookie, "Object of type of_port_status\n");

    of_port_status_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_port_status_reason_get(obj, &val8);
    out += writer(cookie, "  reason (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_port_status_desc_bind(obj, &port_desc);
    out += of_port_desc_OF_VERSION_1_2_dump(writer, cookie, &port_desc);

    return out;
}

int
of_queue_get_config_reply_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_queue_get_config_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_port_no_t port_no;

    of_list_packet_queue_t list;
    of_packet_queue_t elt;
    int rv;

    out += writer(cookie, "Object of type of_queue_get_config_reply\n");

    of_queue_get_config_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_queue_get_config_reply_port_get(obj, &port_no);
    out += writer(cookie, "  port (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_packet_queue_t\n");
    of_queue_get_config_reply_queues_bind(obj, &list);
    OF_LIST_PACKET_QUEUE_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_queue_get_config_request_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_queue_get_config_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_port_no_t port_no;

    out += writer(cookie, "Object of type of_queue_get_config_request\n");

    of_queue_get_config_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_queue_get_config_request_port_get(obj, &port_no);
    out += writer(cookie, "  port (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    return out;
}

int
of_queue_op_failed_error_msg_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_queue_op_failed_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_queue_op_failed_error_msg\n");

    of_queue_op_failed_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_queue_op_failed_error_msg_code_get(obj, &val16);
    out += writer(cookie, "  code (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_queue_op_failed_error_msg_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_queue_stats_reply_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_queue_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_list_queue_stats_entry_t list;
    of_queue_stats_entry_t elt;
    int rv;

    out += writer(cookie, "Object of type of_queue_stats_reply\n");

    of_queue_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_queue_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_queue_stats_entry_t\n");
    of_queue_stats_reply_entries_bind(obj, &list);
    OF_LIST_QUEUE_STATS_ENTRY_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_queue_stats_request_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_queue_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_port_no_t port_no;

    out += writer(cookie, "Object of type of_queue_stats_request\n");

    of_queue_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_queue_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_queue_stats_request_port_no_get(obj, &port_no);
    out += writer(cookie, "  port_no (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_queue_stats_request_queue_id_get(obj, &val32);
    out += writer(cookie, "  queue_id (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_role_reply_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_role_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint64_t val64;

    out += writer(cookie, "Object of type of_role_reply\n");

    of_role_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_role_reply_role_get(obj, &val32);
    out += writer(cookie, "  role (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_role_reply_generation_id_get(obj, &val64);
    out += writer(cookie, "  generation_id (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    return out;
}

int
of_role_request_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_role_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint64_t val64;

    out += writer(cookie, "Object of type of_role_request\n");

    of_role_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_role_request_role_get(obj, &val32);
    out += writer(cookie, "  role (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_role_request_generation_id_get(obj, &val64);
    out += writer(cookie, "  generation_id (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    return out;
}

int
of_role_request_failed_error_msg_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_role_request_failed_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_role_request_failed_error_msg\n");

    of_role_request_failed_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_role_request_failed_error_msg_code_get(obj, &val16);
    out += writer(cookie, "  code (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_role_request_failed_error_msg_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_set_config_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_set_config_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    out += writer(cookie, "Object of type of_set_config\n");

    of_set_config_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_set_config_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_set_config_miss_send_len_get(obj, &val16);
    out += writer(cookie, "  miss_send_len (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_stats_reply_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    out += writer(cookie, "Object of type of_stats_reply\n");

    of_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_stats_request_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    out += writer(cookie, "Object of type of_stats_request\n");

    of_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_switch_config_failed_error_msg_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_switch_config_failed_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_switch_config_failed_error_msg\n");

    of_switch_config_failed_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_switch_config_failed_error_msg_code_get(obj, &val16);
    out += writer(cookie, "  code (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_switch_config_failed_error_msg_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_table_mod_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_table_mod_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint8_t val8;

    out += writer(cookie, "Object of type of_table_mod\n");

    of_table_mod_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_table_mod_table_id_get(obj, &val8);
    out += writer(cookie, "  table_id (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_table_mod_config_get(obj, &val32);
    out += writer(cookie, "  config (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_table_mod_failed_error_msg_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_table_mod_failed_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_table_mod_failed_error_msg\n");

    of_table_mod_failed_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_table_mod_failed_error_msg_code_get(obj, &val16);
    out += writer(cookie, "  code (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_table_mod_failed_error_msg_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_table_stats_reply_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_table_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_list_table_stats_entry_t list;
    of_table_stats_entry_t elt;
    int rv;

    out += writer(cookie, "Object of type of_table_stats_reply\n");

    of_table_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_table_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_table_stats_entry_t\n");
    of_table_stats_reply_entries_bind(obj, &list);
    OF_LIST_TABLE_STATS_ENTRY_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_table_stats_request_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_table_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    out += writer(cookie, "Object of type of_table_stats_request\n");

    of_table_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_table_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_action_bsn_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_action_bsn_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_action_bsn\n");

    of_action_bsn_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_action_bsn_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_action_bsn_mirror_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_action_bsn_mirror_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint8_t val8;

    out += writer(cookie, "Object of type of_action_bsn_mirror\n");

    of_action_bsn_mirror_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_action_bsn_mirror_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_action_bsn_mirror_dest_port_get(obj, &val32);
    out += writer(cookie, "  dest_port (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_action_bsn_mirror_vlan_tag_get(obj, &val32);
    out += writer(cookie, "  vlan_tag (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_action_bsn_mirror_copy_stage_get(obj, &val8);
    out += writer(cookie, "  copy_stage (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_action_bsn_set_tunnel_dst_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_action_bsn_set_tunnel_dst_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_action_bsn_set_tunnel_dst\n");

    of_action_bsn_set_tunnel_dst_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_action_bsn_set_tunnel_dst_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_action_bsn_set_tunnel_dst_dst_get(obj, &val32);
    out += writer(cookie, "  dst (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_action_copy_ttl_in_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_action_copy_ttl_in_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_action_copy_ttl_in\n");

    return out;
}

int
of_action_copy_ttl_out_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_action_copy_ttl_out_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_action_copy_ttl_out\n");

    return out;
}

int
of_action_dec_mpls_ttl_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_action_dec_mpls_ttl_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_action_dec_mpls_ttl\n");

    return out;
}

int
of_action_dec_nw_ttl_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_action_dec_nw_ttl_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_action_dec_nw_ttl\n");

    return out;
}

int
of_action_experimenter_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_action_experimenter_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_action_experimenter\n");

    of_action_experimenter_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_action_experimenter_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_action_group_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_action_group_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_action_group\n");

    of_action_group_group_id_get(obj, &val32);
    out += writer(cookie, "  group_id (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_action_header_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_action_header_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_action_header\n");

    return out;
}

int
of_action_nicira_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_action_nicira_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    out += writer(cookie, "Object of type of_action_nicira\n");

    of_action_nicira_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_action_nicira_subtype_get(obj, &val16);
    out += writer(cookie, "  subtype (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_action_nicira_dec_ttl_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_action_nicira_dec_ttl_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    out += writer(cookie, "Object of type of_action_nicira_dec_ttl\n");

    of_action_nicira_dec_ttl_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_action_nicira_dec_ttl_subtype_get(obj, &val16);
    out += writer(cookie, "  subtype (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_action_output_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_action_output_t *obj)
{
    int out = 0;
    of_port_no_t port_no;
    uint16_t val16;

    out += writer(cookie, "Object of type of_action_output\n");

    of_action_output_port_get(obj, &port_no);
    out += writer(cookie, "  port (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_action_output_max_len_get(obj, &val16);
    out += writer(cookie, "  max_len (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_action_pop_mpls_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_action_pop_mpls_t *obj)
{
    int out = 0;
    uint16_t val16;

    out += writer(cookie, "Object of type of_action_pop_mpls\n");

    of_action_pop_mpls_ethertype_get(obj, &val16);
    out += writer(cookie, "  ethertype (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_action_pop_vlan_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_action_pop_vlan_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_action_pop_vlan\n");

    return out;
}

int
of_action_push_mpls_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_action_push_mpls_t *obj)
{
    int out = 0;
    uint16_t val16;

    out += writer(cookie, "Object of type of_action_push_mpls\n");

    of_action_push_mpls_ethertype_get(obj, &val16);
    out += writer(cookie, "  ethertype (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_action_push_vlan_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_action_push_vlan_t *obj)
{
    int out = 0;
    uint16_t val16;

    out += writer(cookie, "Object of type of_action_push_vlan\n");

    of_action_push_vlan_ethertype_get(obj, &val16);
    out += writer(cookie, "  ethertype (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_action_set_field_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_action_set_field_t *obj)
{
    int out = 0;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_action_set_field\n");

    of_action_set_field_field_get(obj, &octets);
    out += writer(cookie, "  field (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_action_set_mpls_ttl_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_action_set_mpls_ttl_t *obj)
{
    int out = 0;
    uint8_t val8;

    out += writer(cookie, "Object of type of_action_set_mpls_ttl\n");

    of_action_set_mpls_ttl_mpls_ttl_get(obj, &val8);
    out += writer(cookie, "  mpls_ttl (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_action_set_nw_ttl_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_action_set_nw_ttl_t *obj)
{
    int out = 0;
    uint8_t val8;

    out += writer(cookie, "Object of type of_action_set_nw_ttl\n");

    of_action_set_nw_ttl_nw_ttl_get(obj, &val8);
    out += writer(cookie, "  nw_ttl (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_action_set_queue_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_action_set_queue_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_action_set_queue\n");

    of_action_set_queue_queue_id_get(obj, &val32);
    out += writer(cookie, "  queue_id (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_interface_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_bsn_interface_t *obj)
{
    int out = 0;
    of_mac_addr_t mac_addr;
    of_port_name_t port_name;
    of_ipv4_t ipv4;

    out += writer(cookie, "Object of type of_bsn_interface\n");

    of_bsn_interface_hw_addr_get(obj, &mac_addr);
    out += writer(cookie, "  hw_addr (of_mac_addr_t):  ");
    out += LOCI_DUMP_mac(writer, cookie, mac_addr);
    out += writer(cookie, "\n");

    of_bsn_interface_name_get(obj, &port_name);
    out += writer(cookie, "  name (of_port_name_t):  ");
    out += LOCI_DUMP_port_name(writer, cookie, port_name);
    out += writer(cookie, "\n");

    of_bsn_interface_ipv4_addr_get(obj, &ipv4);
    out += writer(cookie, "  ipv4_addr (of_ipv4_t):  ");
    out += LOCI_DUMP_ipv4(writer, cookie, ipv4);
    out += writer(cookie, "\n");

    of_bsn_interface_ipv4_netmask_get(obj, &ipv4);
    out += writer(cookie, "  ipv4_netmask (of_ipv4_t):  ");
    out += LOCI_DUMP_ipv4(writer, cookie, ipv4);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_vport_header_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_bsn_vport_header_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_bsn_vport_header\n");

    return out;
}

int
of_bsn_vport_q_in_q_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_bsn_vport_q_in_q_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_port_name_t port_name;

    out += writer(cookie, "Object of type of_bsn_vport_q_in_q\n");

    of_bsn_vport_q_in_q_port_no_get(obj, &val32);
    out += writer(cookie, "  port_no (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_vport_q_in_q_ingress_tpid_get(obj, &val16);
    out += writer(cookie, "  ingress_tpid (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_bsn_vport_q_in_q_ingress_vlan_id_get(obj, &val16);
    out += writer(cookie, "  ingress_vlan_id (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_bsn_vport_q_in_q_egress_tpid_get(obj, &val16);
    out += writer(cookie, "  egress_tpid (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_bsn_vport_q_in_q_egress_vlan_id_get(obj, &val16);
    out += writer(cookie, "  egress_vlan_id (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_bsn_vport_q_in_q_if_name_get(obj, &port_name);
    out += writer(cookie, "  if_name (of_port_name_t):  ");
    out += LOCI_DUMP_port_name(writer, cookie, port_name);
    out += writer(cookie, "\n");

    return out;
}

int
of_bucket_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_bucket_t *obj)
{
    int out = 0;
    uint16_t val16;
    of_port_no_t port_no;
    uint32_t val32;

    of_list_action_t list;
    of_action_t elt;
    int rv;

    out += writer(cookie, "Object of type of_bucket\n");

    of_bucket_weight_get(obj, &val16);
    out += writer(cookie, "  weight (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_bucket_watch_port_get(obj, &port_no);
    out += writer(cookie, "  watch_port (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_bucket_watch_group_get(obj, &val32);
    out += writer(cookie, "  watch_group (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_action_t\n");
    of_bucket_actions_bind(obj, &list);
    OF_LIST_ACTION_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_bucket_counter_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_bucket_counter_t *obj)
{
    int out = 0;
    uint64_t val64;

    out += writer(cookie, "Object of type of_bucket_counter\n");

    of_bucket_counter_packet_count_get(obj, &val64);
    out += writer(cookie, "  packet_count (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_bucket_counter_byte_count_get(obj, &val64);
    out += writer(cookie, "  byte_count (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    return out;
}

int
of_flow_stats_entry_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_flow_stats_entry_t *obj)
{
    int out = 0;
    uint8_t val8;
    uint32_t val32;
    uint16_t val16;
    uint64_t val64;
    of_match_t match;

    of_list_instruction_t list;
    of_instruction_t elt;
    int rv;

    out += writer(cookie, "Object of type of_flow_stats_entry\n");

    of_flow_stats_entry_table_id_get(obj, &val8);
    out += writer(cookie, "  table_id (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_flow_stats_entry_duration_sec_get(obj, &val32);
    out += writer(cookie, "  duration_sec (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_stats_entry_duration_nsec_get(obj, &val32);
    out += writer(cookie, "  duration_nsec (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_stats_entry_priority_get(obj, &val16);
    out += writer(cookie, "  priority (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_stats_entry_idle_timeout_get(obj, &val16);
    out += writer(cookie, "  idle_timeout (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_stats_entry_hard_timeout_get(obj, &val16);
    out += writer(cookie, "  hard_timeout (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_stats_entry_cookie_get(obj, &val64);
    out += writer(cookie, "  cookie (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_flow_stats_entry_packet_count_get(obj, &val64);
    out += writer(cookie, "  packet_count (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_flow_stats_entry_byte_count_get(obj, &val64);
    out += writer(cookie, "  byte_count (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_flow_stats_entry_match_get(obj, &match);
    out += writer(cookie, "  match (of_match_t):  ");
    out += LOCI_DUMP_match(writer, cookie, match);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_instruction_t\n");
    of_flow_stats_entry_instructions_bind(obj, &list);
    OF_LIST_INSTRUCTION_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_group_desc_stats_entry_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_group_desc_stats_entry_t *obj)
{
    int out = 0;
    uint8_t val8;
    uint32_t val32;

    of_list_bucket_t list;
    of_bucket_t elt;
    int rv;

    out += writer(cookie, "Object of type of_group_desc_stats_entry\n");

    of_group_desc_stats_entry_group_type_get(obj, &val8);
    out += writer(cookie, "  group_type (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_group_desc_stats_entry_group_id_get(obj, &val32);
    out += writer(cookie, "  group_id (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_bucket_t\n");
    of_group_desc_stats_entry_buckets_bind(obj, &list);
    OF_LIST_BUCKET_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_group_stats_entry_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_group_stats_entry_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint64_t val64;

    of_list_bucket_counter_t list;
    of_bucket_counter_t elt;
    int rv;

    out += writer(cookie, "Object of type of_group_stats_entry\n");

    of_group_stats_entry_group_id_get(obj, &val32);
    out += writer(cookie, "  group_id (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_group_stats_entry_ref_count_get(obj, &val32);
    out += writer(cookie, "  ref_count (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_group_stats_entry_packet_count_get(obj, &val64);
    out += writer(cookie, "  packet_count (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_group_stats_entry_byte_count_get(obj, &val64);
    out += writer(cookie, "  byte_count (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_bucket_counter_t\n");
    of_group_stats_entry_bucket_stats_bind(obj, &list);
    OF_LIST_BUCKET_COUNTER_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_header_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_header_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_header\n");

    of_header_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_instruction_apply_actions_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_instruction_apply_actions_t *obj)
{
    int out = 0;

    of_list_action_t list;
    of_action_t elt;
    int rv;

    out += writer(cookie, "Object of type of_instruction_apply_actions\n");

    out += writer(cookie, "List of of_action_t\n");
    of_instruction_apply_actions_actions_bind(obj, &list);
    OF_LIST_ACTION_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_instruction_clear_actions_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_instruction_clear_actions_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_instruction_clear_actions\n");

    return out;
}

int
of_instruction_experimenter_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_instruction_experimenter_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_instruction_experimenter\n");

    of_instruction_experimenter_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_instruction_experimenter_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_instruction_goto_table_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_instruction_goto_table_t *obj)
{
    int out = 0;
    uint8_t val8;

    out += writer(cookie, "Object of type of_instruction_goto_table\n");

    of_instruction_goto_table_table_id_get(obj, &val8);
    out += writer(cookie, "  table_id (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_instruction_header_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_instruction_header_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_instruction_header\n");

    return out;
}

int
of_instruction_write_actions_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_instruction_write_actions_t *obj)
{
    int out = 0;

    of_list_action_t list;
    of_action_t elt;
    int rv;

    out += writer(cookie, "Object of type of_instruction_write_actions\n");

    out += writer(cookie, "List of of_action_t\n");
    of_instruction_write_actions_actions_bind(obj, &list);
    OF_LIST_ACTION_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_instruction_write_metadata_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_instruction_write_metadata_t *obj)
{
    int out = 0;
    uint64_t val64;

    out += writer(cookie, "Object of type of_instruction_write_metadata\n");

    of_instruction_write_metadata_metadata_get(obj, &val64);
    out += writer(cookie, "  metadata (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_instruction_write_metadata_metadata_mask_get(obj, &val64);
    out += writer(cookie, "  metadata_mask (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    return out;
}

int
of_match_v3_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_match_v3_t *obj)
{
    int out = 0;

    of_list_oxm_t list;
    of_oxm_t elt;
    int rv;

    out += writer(cookie, "Object of type of_match_v3\n");

    out += writer(cookie, "List of of_oxm_t\n");
    of_match_v3_oxm_list_bind(obj, &list);
    OF_LIST_OXM_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_oxm_arp_op_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_arp_op_t *obj)
{
    int out = 0;
    uint16_t val16;

    out += writer(cookie, "Object of type of_oxm_arp_op\n");

    of_oxm_arp_op_value_get(obj, &val16);
    out += writer(cookie, "  value (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_arp_op_masked_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_arp_op_masked_t *obj)
{
    int out = 0;
    uint16_t val16;

    out += writer(cookie, "Object of type of_oxm_arp_op_masked\n");

    of_oxm_arp_op_masked_value_get(obj, &val16);
    out += writer(cookie, "  value (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_oxm_arp_op_masked_value_mask_get(obj, &val16);
    out += writer(cookie, "  value_mask (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_arp_sha_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_arp_sha_t *obj)
{
    int out = 0;
    of_mac_addr_t mac_addr;

    out += writer(cookie, "Object of type of_oxm_arp_sha\n");

    of_oxm_arp_sha_value_get(obj, &mac_addr);
    out += writer(cookie, "  value (of_mac_addr_t):  ");
    out += LOCI_DUMP_mac(writer, cookie, mac_addr);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_arp_sha_masked_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_arp_sha_masked_t *obj)
{
    int out = 0;
    of_mac_addr_t mac_addr;

    out += writer(cookie, "Object of type of_oxm_arp_sha_masked\n");

    of_oxm_arp_sha_masked_value_get(obj, &mac_addr);
    out += writer(cookie, "  value (of_mac_addr_t):  ");
    out += LOCI_DUMP_mac(writer, cookie, mac_addr);
    out += writer(cookie, "\n");

    of_oxm_arp_sha_masked_value_mask_get(obj, &mac_addr);
    out += writer(cookie, "  value_mask (of_mac_addr_t):  ");
    out += LOCI_DUMP_mac(writer, cookie, mac_addr);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_arp_spa_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_arp_spa_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_oxm_arp_spa\n");

    of_oxm_arp_spa_value_get(obj, &val32);
    out += writer(cookie, "  value (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_arp_spa_masked_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_arp_spa_masked_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_oxm_arp_spa_masked\n");

    of_oxm_arp_spa_masked_value_get(obj, &val32);
    out += writer(cookie, "  value (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_oxm_arp_spa_masked_value_mask_get(obj, &val32);
    out += writer(cookie, "  value_mask (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_arp_tha_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_arp_tha_t *obj)
{
    int out = 0;
    of_mac_addr_t mac_addr;

    out += writer(cookie, "Object of type of_oxm_arp_tha\n");

    of_oxm_arp_tha_value_get(obj, &mac_addr);
    out += writer(cookie, "  value (of_mac_addr_t):  ");
    out += LOCI_DUMP_mac(writer, cookie, mac_addr);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_arp_tha_masked_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_arp_tha_masked_t *obj)
{
    int out = 0;
    of_mac_addr_t mac_addr;

    out += writer(cookie, "Object of type of_oxm_arp_tha_masked\n");

    of_oxm_arp_tha_masked_value_get(obj, &mac_addr);
    out += writer(cookie, "  value (of_mac_addr_t):  ");
    out += LOCI_DUMP_mac(writer, cookie, mac_addr);
    out += writer(cookie, "\n");

    of_oxm_arp_tha_masked_value_mask_get(obj, &mac_addr);
    out += writer(cookie, "  value_mask (of_mac_addr_t):  ");
    out += LOCI_DUMP_mac(writer, cookie, mac_addr);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_arp_tpa_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_arp_tpa_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_oxm_arp_tpa\n");

    of_oxm_arp_tpa_value_get(obj, &val32);
    out += writer(cookie, "  value (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_arp_tpa_masked_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_arp_tpa_masked_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_oxm_arp_tpa_masked\n");

    of_oxm_arp_tpa_masked_value_get(obj, &val32);
    out += writer(cookie, "  value (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_oxm_arp_tpa_masked_value_mask_get(obj, &val32);
    out += writer(cookie, "  value_mask (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_bsn_global_vrf_allowed_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_bsn_global_vrf_allowed_t *obj)
{
    int out = 0;
    uint8_t val8;

    out += writer(cookie, "Object of type of_oxm_bsn_global_vrf_allowed\n");

    of_oxm_bsn_global_vrf_allowed_value_get(obj, &val8);
    out += writer(cookie, "  value (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_bsn_global_vrf_allowed_masked_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_bsn_global_vrf_allowed_masked_t *obj)
{
    int out = 0;
    uint8_t val8;

    out += writer(cookie, "Object of type of_oxm_bsn_global_vrf_allowed_masked\n");

    of_oxm_bsn_global_vrf_allowed_masked_value_get(obj, &val8);
    out += writer(cookie, "  value (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_oxm_bsn_global_vrf_allowed_masked_value_mask_get(obj, &val8);
    out += writer(cookie, "  value_mask (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_bsn_in_ports_128_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_bsn_in_ports_128_t *obj)
{
    int out = 0;
    of_bitmap_128_t bitmap_128;

    out += writer(cookie, "Object of type of_oxm_bsn_in_ports_128\n");

    of_oxm_bsn_in_ports_128_value_get(obj, &bitmap_128);
    out += writer(cookie, "  value (of_bitmap_128_t):  ");
    out += LOCI_DUMP_bitmap_128(writer, cookie, bitmap_128);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_bsn_in_ports_128_masked_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_bsn_in_ports_128_masked_t *obj)
{
    int out = 0;
    of_bitmap_128_t bitmap_128;

    out += writer(cookie, "Object of type of_oxm_bsn_in_ports_128_masked\n");

    of_oxm_bsn_in_ports_128_masked_value_get(obj, &bitmap_128);
    out += writer(cookie, "  value (of_bitmap_128_t):  ");
    out += LOCI_DUMP_bitmap_128(writer, cookie, bitmap_128);
    out += writer(cookie, "\n");

    of_oxm_bsn_in_ports_128_masked_value_mask_get(obj, &bitmap_128);
    out += writer(cookie, "  value_mask (of_bitmap_128_t):  ");
    out += LOCI_DUMP_bitmap_128(writer, cookie, bitmap_128);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_bsn_l3_dst_class_id_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_bsn_l3_dst_class_id_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_oxm_bsn_l3_dst_class_id\n");

    of_oxm_bsn_l3_dst_class_id_value_get(obj, &val32);
    out += writer(cookie, "  value (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_bsn_l3_dst_class_id_masked_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_bsn_l3_dst_class_id_masked_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_oxm_bsn_l3_dst_class_id_masked\n");

    of_oxm_bsn_l3_dst_class_id_masked_value_get(obj, &val32);
    out += writer(cookie, "  value (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_oxm_bsn_l3_dst_class_id_masked_value_mask_get(obj, &val32);
    out += writer(cookie, "  value_mask (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_bsn_l3_interface_class_id_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_bsn_l3_interface_class_id_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_oxm_bsn_l3_interface_class_id\n");

    of_oxm_bsn_l3_interface_class_id_value_get(obj, &val32);
    out += writer(cookie, "  value (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_bsn_l3_interface_class_id_masked_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_bsn_l3_interface_class_id_masked_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_oxm_bsn_l3_interface_class_id_masked\n");

    of_oxm_bsn_l3_interface_class_id_masked_value_get(obj, &val32);
    out += writer(cookie, "  value (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_oxm_bsn_l3_interface_class_id_masked_value_mask_get(obj, &val32);
    out += writer(cookie, "  value_mask (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_bsn_l3_src_class_id_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_bsn_l3_src_class_id_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_oxm_bsn_l3_src_class_id\n");

    of_oxm_bsn_l3_src_class_id_value_get(obj, &val32);
    out += writer(cookie, "  value (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_bsn_l3_src_class_id_masked_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_bsn_l3_src_class_id_masked_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_oxm_bsn_l3_src_class_id_masked\n");

    of_oxm_bsn_l3_src_class_id_masked_value_get(obj, &val32);
    out += writer(cookie, "  value (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_oxm_bsn_l3_src_class_id_masked_value_mask_get(obj, &val32);
    out += writer(cookie, "  value_mask (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_bsn_lag_id_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_bsn_lag_id_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_oxm_bsn_lag_id\n");

    of_oxm_bsn_lag_id_value_get(obj, &val32);
    out += writer(cookie, "  value (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_bsn_lag_id_masked_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_bsn_lag_id_masked_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_oxm_bsn_lag_id_masked\n");

    of_oxm_bsn_lag_id_masked_value_get(obj, &val32);
    out += writer(cookie, "  value (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_oxm_bsn_lag_id_masked_value_mask_get(obj, &val32);
    out += writer(cookie, "  value_mask (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_bsn_vrf_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_bsn_vrf_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_oxm_bsn_vrf\n");

    of_oxm_bsn_vrf_value_get(obj, &val32);
    out += writer(cookie, "  value (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_bsn_vrf_masked_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_bsn_vrf_masked_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_oxm_bsn_vrf_masked\n");

    of_oxm_bsn_vrf_masked_value_get(obj, &val32);
    out += writer(cookie, "  value (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_oxm_bsn_vrf_masked_value_mask_get(obj, &val32);
    out += writer(cookie, "  value_mask (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_eth_dst_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_eth_dst_t *obj)
{
    int out = 0;
    of_mac_addr_t mac_addr;

    out += writer(cookie, "Object of type of_oxm_eth_dst\n");

    of_oxm_eth_dst_value_get(obj, &mac_addr);
    out += writer(cookie, "  value (of_mac_addr_t):  ");
    out += LOCI_DUMP_mac(writer, cookie, mac_addr);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_eth_dst_masked_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_eth_dst_masked_t *obj)
{
    int out = 0;
    of_mac_addr_t mac_addr;

    out += writer(cookie, "Object of type of_oxm_eth_dst_masked\n");

    of_oxm_eth_dst_masked_value_get(obj, &mac_addr);
    out += writer(cookie, "  value (of_mac_addr_t):  ");
    out += LOCI_DUMP_mac(writer, cookie, mac_addr);
    out += writer(cookie, "\n");

    of_oxm_eth_dst_masked_value_mask_get(obj, &mac_addr);
    out += writer(cookie, "  value_mask (of_mac_addr_t):  ");
    out += LOCI_DUMP_mac(writer, cookie, mac_addr);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_eth_src_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_eth_src_t *obj)
{
    int out = 0;
    of_mac_addr_t mac_addr;

    out += writer(cookie, "Object of type of_oxm_eth_src\n");

    of_oxm_eth_src_value_get(obj, &mac_addr);
    out += writer(cookie, "  value (of_mac_addr_t):  ");
    out += LOCI_DUMP_mac(writer, cookie, mac_addr);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_eth_src_masked_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_eth_src_masked_t *obj)
{
    int out = 0;
    of_mac_addr_t mac_addr;

    out += writer(cookie, "Object of type of_oxm_eth_src_masked\n");

    of_oxm_eth_src_masked_value_get(obj, &mac_addr);
    out += writer(cookie, "  value (of_mac_addr_t):  ");
    out += LOCI_DUMP_mac(writer, cookie, mac_addr);
    out += writer(cookie, "\n");

    of_oxm_eth_src_masked_value_mask_get(obj, &mac_addr);
    out += writer(cookie, "  value_mask (of_mac_addr_t):  ");
    out += LOCI_DUMP_mac(writer, cookie, mac_addr);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_eth_type_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_eth_type_t *obj)
{
    int out = 0;
    uint16_t val16;

    out += writer(cookie, "Object of type of_oxm_eth_type\n");

    of_oxm_eth_type_value_get(obj, &val16);
    out += writer(cookie, "  value (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_eth_type_masked_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_eth_type_masked_t *obj)
{
    int out = 0;
    uint16_t val16;

    out += writer(cookie, "Object of type of_oxm_eth_type_masked\n");

    of_oxm_eth_type_masked_value_get(obj, &val16);
    out += writer(cookie, "  value (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_oxm_eth_type_masked_value_mask_get(obj, &val16);
    out += writer(cookie, "  value_mask (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_header_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_header_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_oxm_header\n");

    return out;
}

int
of_oxm_icmpv4_code_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_icmpv4_code_t *obj)
{
    int out = 0;
    uint8_t val8;

    out += writer(cookie, "Object of type of_oxm_icmpv4_code\n");

    of_oxm_icmpv4_code_value_get(obj, &val8);
    out += writer(cookie, "  value (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_icmpv4_code_masked_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_icmpv4_code_masked_t *obj)
{
    int out = 0;
    uint8_t val8;

    out += writer(cookie, "Object of type of_oxm_icmpv4_code_masked\n");

    of_oxm_icmpv4_code_masked_value_get(obj, &val8);
    out += writer(cookie, "  value (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_oxm_icmpv4_code_masked_value_mask_get(obj, &val8);
    out += writer(cookie, "  value_mask (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_icmpv4_type_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_icmpv4_type_t *obj)
{
    int out = 0;
    uint8_t val8;

    out += writer(cookie, "Object of type of_oxm_icmpv4_type\n");

    of_oxm_icmpv4_type_value_get(obj, &val8);
    out += writer(cookie, "  value (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_icmpv4_type_masked_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_icmpv4_type_masked_t *obj)
{
    int out = 0;
    uint8_t val8;

    out += writer(cookie, "Object of type of_oxm_icmpv4_type_masked\n");

    of_oxm_icmpv4_type_masked_value_get(obj, &val8);
    out += writer(cookie, "  value (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_oxm_icmpv4_type_masked_value_mask_get(obj, &val8);
    out += writer(cookie, "  value_mask (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_icmpv6_code_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_icmpv6_code_t *obj)
{
    int out = 0;
    uint8_t val8;

    out += writer(cookie, "Object of type of_oxm_icmpv6_code\n");

    of_oxm_icmpv6_code_value_get(obj, &val8);
    out += writer(cookie, "  value (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_icmpv6_code_masked_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_icmpv6_code_masked_t *obj)
{
    int out = 0;
    uint8_t val8;

    out += writer(cookie, "Object of type of_oxm_icmpv6_code_masked\n");

    of_oxm_icmpv6_code_masked_value_get(obj, &val8);
    out += writer(cookie, "  value (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_oxm_icmpv6_code_masked_value_mask_get(obj, &val8);
    out += writer(cookie, "  value_mask (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_icmpv6_type_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_icmpv6_type_t *obj)
{
    int out = 0;
    uint8_t val8;

    out += writer(cookie, "Object of type of_oxm_icmpv6_type\n");

    of_oxm_icmpv6_type_value_get(obj, &val8);
    out += writer(cookie, "  value (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_icmpv6_type_masked_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_icmpv6_type_masked_t *obj)
{
    int out = 0;
    uint8_t val8;

    out += writer(cookie, "Object of type of_oxm_icmpv6_type_masked\n");

    of_oxm_icmpv6_type_masked_value_get(obj, &val8);
    out += writer(cookie, "  value (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_oxm_icmpv6_type_masked_value_mask_get(obj, &val8);
    out += writer(cookie, "  value_mask (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_in_phy_port_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_in_phy_port_t *obj)
{
    int out = 0;
    of_port_no_t port_no;

    out += writer(cookie, "Object of type of_oxm_in_phy_port\n");

    of_oxm_in_phy_port_value_get(obj, &port_no);
    out += writer(cookie, "  value (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_in_phy_port_masked_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_in_phy_port_masked_t *obj)
{
    int out = 0;
    of_port_no_t port_no;

    out += writer(cookie, "Object of type of_oxm_in_phy_port_masked\n");

    of_oxm_in_phy_port_masked_value_get(obj, &port_no);
    out += writer(cookie, "  value (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_oxm_in_phy_port_masked_value_mask_get(obj, &port_no);
    out += writer(cookie, "  value_mask (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_in_port_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_in_port_t *obj)
{
    int out = 0;
    of_port_no_t port_no;

    out += writer(cookie, "Object of type of_oxm_in_port\n");

    of_oxm_in_port_value_get(obj, &port_no);
    out += writer(cookie, "  value (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_in_port_masked_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_in_port_masked_t *obj)
{
    int out = 0;
    of_port_no_t port_no;

    out += writer(cookie, "Object of type of_oxm_in_port_masked\n");

    of_oxm_in_port_masked_value_get(obj, &port_no);
    out += writer(cookie, "  value (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_oxm_in_port_masked_value_mask_get(obj, &port_no);
    out += writer(cookie, "  value_mask (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_ip_dscp_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_ip_dscp_t *obj)
{
    int out = 0;
    uint8_t val8;

    out += writer(cookie, "Object of type of_oxm_ip_dscp\n");

    of_oxm_ip_dscp_value_get(obj, &val8);
    out += writer(cookie, "  value (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_ip_dscp_masked_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_ip_dscp_masked_t *obj)
{
    int out = 0;
    uint8_t val8;

    out += writer(cookie, "Object of type of_oxm_ip_dscp_masked\n");

    of_oxm_ip_dscp_masked_value_get(obj, &val8);
    out += writer(cookie, "  value (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_oxm_ip_dscp_masked_value_mask_get(obj, &val8);
    out += writer(cookie, "  value_mask (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_ip_ecn_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_ip_ecn_t *obj)
{
    int out = 0;
    uint8_t val8;

    out += writer(cookie, "Object of type of_oxm_ip_ecn\n");

    of_oxm_ip_ecn_value_get(obj, &val8);
    out += writer(cookie, "  value (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_ip_ecn_masked_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_ip_ecn_masked_t *obj)
{
    int out = 0;
    uint8_t val8;

    out += writer(cookie, "Object of type of_oxm_ip_ecn_masked\n");

    of_oxm_ip_ecn_masked_value_get(obj, &val8);
    out += writer(cookie, "  value (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_oxm_ip_ecn_masked_value_mask_get(obj, &val8);
    out += writer(cookie, "  value_mask (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_ip_proto_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_ip_proto_t *obj)
{
    int out = 0;
    uint8_t val8;

    out += writer(cookie, "Object of type of_oxm_ip_proto\n");

    of_oxm_ip_proto_value_get(obj, &val8);
    out += writer(cookie, "  value (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_ip_proto_masked_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_ip_proto_masked_t *obj)
{
    int out = 0;
    uint8_t val8;

    out += writer(cookie, "Object of type of_oxm_ip_proto_masked\n");

    of_oxm_ip_proto_masked_value_get(obj, &val8);
    out += writer(cookie, "  value (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_oxm_ip_proto_masked_value_mask_get(obj, &val8);
    out += writer(cookie, "  value_mask (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_ipv4_dst_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_ipv4_dst_t *obj)
{
    int out = 0;
    of_ipv4_t ipv4;

    out += writer(cookie, "Object of type of_oxm_ipv4_dst\n");

    of_oxm_ipv4_dst_value_get(obj, &ipv4);
    out += writer(cookie, "  value (of_ipv4_t):  ");
    out += LOCI_DUMP_ipv4(writer, cookie, ipv4);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_ipv4_dst_masked_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_ipv4_dst_masked_t *obj)
{
    int out = 0;
    of_ipv4_t ipv4;

    out += writer(cookie, "Object of type of_oxm_ipv4_dst_masked\n");

    of_oxm_ipv4_dst_masked_value_get(obj, &ipv4);
    out += writer(cookie, "  value (of_ipv4_t):  ");
    out += LOCI_DUMP_ipv4(writer, cookie, ipv4);
    out += writer(cookie, "\n");

    of_oxm_ipv4_dst_masked_value_mask_get(obj, &ipv4);
    out += writer(cookie, "  value_mask (of_ipv4_t):  ");
    out += LOCI_DUMP_ipv4(writer, cookie, ipv4);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_ipv4_src_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_ipv4_src_t *obj)
{
    int out = 0;
    of_ipv4_t ipv4;

    out += writer(cookie, "Object of type of_oxm_ipv4_src\n");

    of_oxm_ipv4_src_value_get(obj, &ipv4);
    out += writer(cookie, "  value (of_ipv4_t):  ");
    out += LOCI_DUMP_ipv4(writer, cookie, ipv4);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_ipv4_src_masked_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_ipv4_src_masked_t *obj)
{
    int out = 0;
    of_ipv4_t ipv4;

    out += writer(cookie, "Object of type of_oxm_ipv4_src_masked\n");

    of_oxm_ipv4_src_masked_value_get(obj, &ipv4);
    out += writer(cookie, "  value (of_ipv4_t):  ");
    out += LOCI_DUMP_ipv4(writer, cookie, ipv4);
    out += writer(cookie, "\n");

    of_oxm_ipv4_src_masked_value_mask_get(obj, &ipv4);
    out += writer(cookie, "  value_mask (of_ipv4_t):  ");
    out += LOCI_DUMP_ipv4(writer, cookie, ipv4);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_ipv6_dst_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_ipv6_dst_t *obj)
{
    int out = 0;
    of_ipv6_t ipv6;

    out += writer(cookie, "Object of type of_oxm_ipv6_dst\n");

    of_oxm_ipv6_dst_value_get(obj, &ipv6);
    out += writer(cookie, "  value (of_ipv6_t):  ");
    out += LOCI_DUMP_ipv6(writer, cookie, ipv6);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_ipv6_dst_masked_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_ipv6_dst_masked_t *obj)
{
    int out = 0;
    of_ipv6_t ipv6;

    out += writer(cookie, "Object of type of_oxm_ipv6_dst_masked\n");

    of_oxm_ipv6_dst_masked_value_get(obj, &ipv6);
    out += writer(cookie, "  value (of_ipv6_t):  ");
    out += LOCI_DUMP_ipv6(writer, cookie, ipv6);
    out += writer(cookie, "\n");

    of_oxm_ipv6_dst_masked_value_mask_get(obj, &ipv6);
    out += writer(cookie, "  value_mask (of_ipv6_t):  ");
    out += LOCI_DUMP_ipv6(writer, cookie, ipv6);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_ipv6_flabel_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_ipv6_flabel_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_oxm_ipv6_flabel\n");

    of_oxm_ipv6_flabel_value_get(obj, &val32);
    out += writer(cookie, "  value (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_ipv6_flabel_masked_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_ipv6_flabel_masked_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_oxm_ipv6_flabel_masked\n");

    of_oxm_ipv6_flabel_masked_value_get(obj, &val32);
    out += writer(cookie, "  value (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_oxm_ipv6_flabel_masked_value_mask_get(obj, &val32);
    out += writer(cookie, "  value_mask (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_ipv6_nd_sll_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_ipv6_nd_sll_t *obj)
{
    int out = 0;
    of_mac_addr_t mac_addr;

    out += writer(cookie, "Object of type of_oxm_ipv6_nd_sll\n");

    of_oxm_ipv6_nd_sll_value_get(obj, &mac_addr);
    out += writer(cookie, "  value (of_mac_addr_t):  ");
    out += LOCI_DUMP_mac(writer, cookie, mac_addr);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_ipv6_nd_sll_masked_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_ipv6_nd_sll_masked_t *obj)
{
    int out = 0;
    of_mac_addr_t mac_addr;

    out += writer(cookie, "Object of type of_oxm_ipv6_nd_sll_masked\n");

    of_oxm_ipv6_nd_sll_masked_value_get(obj, &mac_addr);
    out += writer(cookie, "  value (of_mac_addr_t):  ");
    out += LOCI_DUMP_mac(writer, cookie, mac_addr);
    out += writer(cookie, "\n");

    of_oxm_ipv6_nd_sll_masked_value_mask_get(obj, &mac_addr);
    out += writer(cookie, "  value_mask (of_mac_addr_t):  ");
    out += LOCI_DUMP_mac(writer, cookie, mac_addr);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_ipv6_nd_target_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_ipv6_nd_target_t *obj)
{
    int out = 0;
    of_ipv6_t ipv6;

    out += writer(cookie, "Object of type of_oxm_ipv6_nd_target\n");

    of_oxm_ipv6_nd_target_value_get(obj, &ipv6);
    out += writer(cookie, "  value (of_ipv6_t):  ");
    out += LOCI_DUMP_ipv6(writer, cookie, ipv6);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_ipv6_nd_target_masked_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_ipv6_nd_target_masked_t *obj)
{
    int out = 0;
    of_ipv6_t ipv6;

    out += writer(cookie, "Object of type of_oxm_ipv6_nd_target_masked\n");

    of_oxm_ipv6_nd_target_masked_value_get(obj, &ipv6);
    out += writer(cookie, "  value (of_ipv6_t):  ");
    out += LOCI_DUMP_ipv6(writer, cookie, ipv6);
    out += writer(cookie, "\n");

    of_oxm_ipv6_nd_target_masked_value_mask_get(obj, &ipv6);
    out += writer(cookie, "  value_mask (of_ipv6_t):  ");
    out += LOCI_DUMP_ipv6(writer, cookie, ipv6);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_ipv6_nd_tll_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_ipv6_nd_tll_t *obj)
{
    int out = 0;
    of_mac_addr_t mac_addr;

    out += writer(cookie, "Object of type of_oxm_ipv6_nd_tll\n");

    of_oxm_ipv6_nd_tll_value_get(obj, &mac_addr);
    out += writer(cookie, "  value (of_mac_addr_t):  ");
    out += LOCI_DUMP_mac(writer, cookie, mac_addr);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_ipv6_nd_tll_masked_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_ipv6_nd_tll_masked_t *obj)
{
    int out = 0;
    of_mac_addr_t mac_addr;

    out += writer(cookie, "Object of type of_oxm_ipv6_nd_tll_masked\n");

    of_oxm_ipv6_nd_tll_masked_value_get(obj, &mac_addr);
    out += writer(cookie, "  value (of_mac_addr_t):  ");
    out += LOCI_DUMP_mac(writer, cookie, mac_addr);
    out += writer(cookie, "\n");

    of_oxm_ipv6_nd_tll_masked_value_mask_get(obj, &mac_addr);
    out += writer(cookie, "  value_mask (of_mac_addr_t):  ");
    out += LOCI_DUMP_mac(writer, cookie, mac_addr);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_ipv6_src_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_ipv6_src_t *obj)
{
    int out = 0;
    of_ipv6_t ipv6;

    out += writer(cookie, "Object of type of_oxm_ipv6_src\n");

    of_oxm_ipv6_src_value_get(obj, &ipv6);
    out += writer(cookie, "  value (of_ipv6_t):  ");
    out += LOCI_DUMP_ipv6(writer, cookie, ipv6);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_ipv6_src_masked_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_ipv6_src_masked_t *obj)
{
    int out = 0;
    of_ipv6_t ipv6;

    out += writer(cookie, "Object of type of_oxm_ipv6_src_masked\n");

    of_oxm_ipv6_src_masked_value_get(obj, &ipv6);
    out += writer(cookie, "  value (of_ipv6_t):  ");
    out += LOCI_DUMP_ipv6(writer, cookie, ipv6);
    out += writer(cookie, "\n");

    of_oxm_ipv6_src_masked_value_mask_get(obj, &ipv6);
    out += writer(cookie, "  value_mask (of_ipv6_t):  ");
    out += LOCI_DUMP_ipv6(writer, cookie, ipv6);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_metadata_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_metadata_t *obj)
{
    int out = 0;
    uint64_t val64;

    out += writer(cookie, "Object of type of_oxm_metadata\n");

    of_oxm_metadata_value_get(obj, &val64);
    out += writer(cookie, "  value (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_metadata_masked_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_metadata_masked_t *obj)
{
    int out = 0;
    uint64_t val64;

    out += writer(cookie, "Object of type of_oxm_metadata_masked\n");

    of_oxm_metadata_masked_value_get(obj, &val64);
    out += writer(cookie, "  value (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_oxm_metadata_masked_value_mask_get(obj, &val64);
    out += writer(cookie, "  value_mask (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_mpls_label_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_mpls_label_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_oxm_mpls_label\n");

    of_oxm_mpls_label_value_get(obj, &val32);
    out += writer(cookie, "  value (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_mpls_label_masked_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_mpls_label_masked_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_oxm_mpls_label_masked\n");

    of_oxm_mpls_label_masked_value_get(obj, &val32);
    out += writer(cookie, "  value (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_oxm_mpls_label_masked_value_mask_get(obj, &val32);
    out += writer(cookie, "  value_mask (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_mpls_tc_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_mpls_tc_t *obj)
{
    int out = 0;
    uint8_t val8;

    out += writer(cookie, "Object of type of_oxm_mpls_tc\n");

    of_oxm_mpls_tc_value_get(obj, &val8);
    out += writer(cookie, "  value (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_mpls_tc_masked_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_mpls_tc_masked_t *obj)
{
    int out = 0;
    uint8_t val8;

    out += writer(cookie, "Object of type of_oxm_mpls_tc_masked\n");

    of_oxm_mpls_tc_masked_value_get(obj, &val8);
    out += writer(cookie, "  value (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_oxm_mpls_tc_masked_value_mask_get(obj, &val8);
    out += writer(cookie, "  value_mask (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_sctp_dst_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_sctp_dst_t *obj)
{
    int out = 0;
    uint16_t val16;

    out += writer(cookie, "Object of type of_oxm_sctp_dst\n");

    of_oxm_sctp_dst_value_get(obj, &val16);
    out += writer(cookie, "  value (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_sctp_dst_masked_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_sctp_dst_masked_t *obj)
{
    int out = 0;
    uint16_t val16;

    out += writer(cookie, "Object of type of_oxm_sctp_dst_masked\n");

    of_oxm_sctp_dst_masked_value_get(obj, &val16);
    out += writer(cookie, "  value (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_oxm_sctp_dst_masked_value_mask_get(obj, &val16);
    out += writer(cookie, "  value_mask (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_sctp_src_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_sctp_src_t *obj)
{
    int out = 0;
    uint16_t val16;

    out += writer(cookie, "Object of type of_oxm_sctp_src\n");

    of_oxm_sctp_src_value_get(obj, &val16);
    out += writer(cookie, "  value (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_sctp_src_masked_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_sctp_src_masked_t *obj)
{
    int out = 0;
    uint16_t val16;

    out += writer(cookie, "Object of type of_oxm_sctp_src_masked\n");

    of_oxm_sctp_src_masked_value_get(obj, &val16);
    out += writer(cookie, "  value (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_oxm_sctp_src_masked_value_mask_get(obj, &val16);
    out += writer(cookie, "  value_mask (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_tcp_dst_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_tcp_dst_t *obj)
{
    int out = 0;
    uint16_t val16;

    out += writer(cookie, "Object of type of_oxm_tcp_dst\n");

    of_oxm_tcp_dst_value_get(obj, &val16);
    out += writer(cookie, "  value (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_tcp_dst_masked_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_tcp_dst_masked_t *obj)
{
    int out = 0;
    uint16_t val16;

    out += writer(cookie, "Object of type of_oxm_tcp_dst_masked\n");

    of_oxm_tcp_dst_masked_value_get(obj, &val16);
    out += writer(cookie, "  value (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_oxm_tcp_dst_masked_value_mask_get(obj, &val16);
    out += writer(cookie, "  value_mask (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_tcp_src_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_tcp_src_t *obj)
{
    int out = 0;
    uint16_t val16;

    out += writer(cookie, "Object of type of_oxm_tcp_src\n");

    of_oxm_tcp_src_value_get(obj, &val16);
    out += writer(cookie, "  value (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_tcp_src_masked_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_tcp_src_masked_t *obj)
{
    int out = 0;
    uint16_t val16;

    out += writer(cookie, "Object of type of_oxm_tcp_src_masked\n");

    of_oxm_tcp_src_masked_value_get(obj, &val16);
    out += writer(cookie, "  value (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_oxm_tcp_src_masked_value_mask_get(obj, &val16);
    out += writer(cookie, "  value_mask (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_udp_dst_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_udp_dst_t *obj)
{
    int out = 0;
    uint16_t val16;

    out += writer(cookie, "Object of type of_oxm_udp_dst\n");

    of_oxm_udp_dst_value_get(obj, &val16);
    out += writer(cookie, "  value (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_udp_dst_masked_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_udp_dst_masked_t *obj)
{
    int out = 0;
    uint16_t val16;

    out += writer(cookie, "Object of type of_oxm_udp_dst_masked\n");

    of_oxm_udp_dst_masked_value_get(obj, &val16);
    out += writer(cookie, "  value (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_oxm_udp_dst_masked_value_mask_get(obj, &val16);
    out += writer(cookie, "  value_mask (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_udp_src_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_udp_src_t *obj)
{
    int out = 0;
    uint16_t val16;

    out += writer(cookie, "Object of type of_oxm_udp_src\n");

    of_oxm_udp_src_value_get(obj, &val16);
    out += writer(cookie, "  value (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_udp_src_masked_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_udp_src_masked_t *obj)
{
    int out = 0;
    uint16_t val16;

    out += writer(cookie, "Object of type of_oxm_udp_src_masked\n");

    of_oxm_udp_src_masked_value_get(obj, &val16);
    out += writer(cookie, "  value (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_oxm_udp_src_masked_value_mask_get(obj, &val16);
    out += writer(cookie, "  value_mask (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_vlan_pcp_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_vlan_pcp_t *obj)
{
    int out = 0;
    uint8_t val8;

    out += writer(cookie, "Object of type of_oxm_vlan_pcp\n");

    of_oxm_vlan_pcp_value_get(obj, &val8);
    out += writer(cookie, "  value (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_vlan_pcp_masked_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_vlan_pcp_masked_t *obj)
{
    int out = 0;
    uint8_t val8;

    out += writer(cookie, "Object of type of_oxm_vlan_pcp_masked\n");

    of_oxm_vlan_pcp_masked_value_get(obj, &val8);
    out += writer(cookie, "  value (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_oxm_vlan_pcp_masked_value_mask_get(obj, &val8);
    out += writer(cookie, "  value_mask (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_vlan_vid_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_vlan_vid_t *obj)
{
    int out = 0;
    uint16_t val16;

    out += writer(cookie, "Object of type of_oxm_vlan_vid\n");

    of_oxm_vlan_vid_value_get(obj, &val16);
    out += writer(cookie, "  value (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_vlan_vid_masked_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_oxm_vlan_vid_masked_t *obj)
{
    int out = 0;
    uint16_t val16;

    out += writer(cookie, "Object of type of_oxm_vlan_vid_masked\n");

    of_oxm_vlan_vid_masked_value_get(obj, &val16);
    out += writer(cookie, "  value (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_oxm_vlan_vid_masked_value_mask_get(obj, &val16);
    out += writer(cookie, "  value_mask (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_packet_queue_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_packet_queue_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_port_no_t port_no;

    of_list_queue_prop_t list;
    of_queue_prop_t elt;
    int rv;

    out += writer(cookie, "Object of type of_packet_queue\n");

    of_packet_queue_queue_id_get(obj, &val32);
    out += writer(cookie, "  queue_id (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_packet_queue_port_get(obj, &port_no);
    out += writer(cookie, "  port (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_queue_prop_t\n");
    of_packet_queue_properties_bind(obj, &list);
    OF_LIST_QUEUE_PROP_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_port_desc_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_port_desc_t *obj)
{
    int out = 0;
    of_port_no_t port_no;
    of_mac_addr_t mac_addr;
    of_port_name_t port_name;
    uint32_t val32;

    out += writer(cookie, "Object of type of_port_desc\n");

    of_port_desc_port_no_get(obj, &port_no);
    out += writer(cookie, "  port_no (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_port_desc_hw_addr_get(obj, &mac_addr);
    out += writer(cookie, "  hw_addr (of_mac_addr_t):  ");
    out += LOCI_DUMP_mac(writer, cookie, mac_addr);
    out += writer(cookie, "\n");

    of_port_desc_name_get(obj, &port_name);
    out += writer(cookie, "  name (of_port_name_t):  ");
    out += LOCI_DUMP_port_name(writer, cookie, port_name);
    out += writer(cookie, "\n");

    of_port_desc_config_get(obj, &val32);
    out += writer(cookie, "  config (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_port_desc_state_get(obj, &val32);
    out += writer(cookie, "  state (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_port_desc_curr_get(obj, &val32);
    out += writer(cookie, "  curr (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_port_desc_advertised_get(obj, &val32);
    out += writer(cookie, "  advertised (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_port_desc_supported_get(obj, &val32);
    out += writer(cookie, "  supported (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_port_desc_peer_get(obj, &val32);
    out += writer(cookie, "  peer (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_port_desc_curr_speed_get(obj, &val32);
    out += writer(cookie, "  curr_speed (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_port_desc_max_speed_get(obj, &val32);
    out += writer(cookie, "  max_speed (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_port_stats_entry_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_port_stats_entry_t *obj)
{
    int out = 0;
    of_port_no_t port_no;
    uint64_t val64;

    out += writer(cookie, "Object of type of_port_stats_entry\n");

    of_port_stats_entry_port_no_get(obj, &port_no);
    out += writer(cookie, "  port_no (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_port_stats_entry_rx_packets_get(obj, &val64);
    out += writer(cookie, "  rx_packets (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_port_stats_entry_tx_packets_get(obj, &val64);
    out += writer(cookie, "  tx_packets (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_port_stats_entry_rx_bytes_get(obj, &val64);
    out += writer(cookie, "  rx_bytes (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_port_stats_entry_tx_bytes_get(obj, &val64);
    out += writer(cookie, "  tx_bytes (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_port_stats_entry_rx_dropped_get(obj, &val64);
    out += writer(cookie, "  rx_dropped (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_port_stats_entry_tx_dropped_get(obj, &val64);
    out += writer(cookie, "  tx_dropped (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_port_stats_entry_rx_errors_get(obj, &val64);
    out += writer(cookie, "  rx_errors (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_port_stats_entry_tx_errors_get(obj, &val64);
    out += writer(cookie, "  tx_errors (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_port_stats_entry_rx_frame_err_get(obj, &val64);
    out += writer(cookie, "  rx_frame_err (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_port_stats_entry_rx_over_err_get(obj, &val64);
    out += writer(cookie, "  rx_over_err (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_port_stats_entry_rx_crc_err_get(obj, &val64);
    out += writer(cookie, "  rx_crc_err (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_port_stats_entry_collisions_get(obj, &val64);
    out += writer(cookie, "  collisions (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    return out;
}

int
of_queue_prop_experimenter_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_queue_prop_experimenter_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_queue_prop_experimenter\n");

    of_queue_prop_experimenter_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_queue_prop_experimenter_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_queue_prop_header_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_queue_prop_header_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_queue_prop_header\n");

    return out;
}

int
of_queue_prop_max_rate_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_queue_prop_max_rate_t *obj)
{
    int out = 0;
    uint16_t val16;

    out += writer(cookie, "Object of type of_queue_prop_max_rate\n");

    of_queue_prop_max_rate_rate_get(obj, &val16);
    out += writer(cookie, "  rate (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_queue_prop_min_rate_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_queue_prop_min_rate_t *obj)
{
    int out = 0;
    uint16_t val16;

    out += writer(cookie, "Object of type of_queue_prop_min_rate\n");

    of_queue_prop_min_rate_rate_get(obj, &val16);
    out += writer(cookie, "  rate (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_queue_stats_entry_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_queue_stats_entry_t *obj)
{
    int out = 0;
    of_port_no_t port_no;
    uint32_t val32;
    uint64_t val64;

    out += writer(cookie, "Object of type of_queue_stats_entry\n");

    of_queue_stats_entry_port_no_get(obj, &port_no);
    out += writer(cookie, "  port_no (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_queue_stats_entry_queue_id_get(obj, &val32);
    out += writer(cookie, "  queue_id (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_queue_stats_entry_tx_bytes_get(obj, &val64);
    out += writer(cookie, "  tx_bytes (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_queue_stats_entry_tx_packets_get(obj, &val64);
    out += writer(cookie, "  tx_packets (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_queue_stats_entry_tx_errors_get(obj, &val64);
    out += writer(cookie, "  tx_errors (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    return out;
}

int
of_table_stats_entry_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_table_stats_entry_t *obj)
{
    int out = 0;
    uint8_t val8;
    of_table_name_t table_name;
    of_match_bmap_t match_bmap;
    of_wc_bmap_t wc_bmap;
    uint32_t val32;
    uint64_t val64;

    out += writer(cookie, "Object of type of_table_stats_entry\n");

    of_table_stats_entry_table_id_get(obj, &val8);
    out += writer(cookie, "  table_id (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_table_stats_entry_name_get(obj, &table_name);
    out += writer(cookie, "  name (of_table_name_t):  ");
    out += LOCI_DUMP_tab_name(writer, cookie, table_name);
    out += writer(cookie, "\n");

    of_table_stats_entry_match_get(obj, &match_bmap);
    out += writer(cookie, "  match (of_match_bmap_t):  ");
    out += LOCI_DUMP_match_bmap(writer, cookie, match_bmap);
    out += writer(cookie, "\n");

    of_table_stats_entry_wildcards_get(obj, &wc_bmap);
    out += writer(cookie, "  wildcards (of_wc_bmap_t):  ");
    out += LOCI_DUMP_wc_bmap(writer, cookie, wc_bmap);
    out += writer(cookie, "\n");

    of_table_stats_entry_write_actions_get(obj, &val32);
    out += writer(cookie, "  write_actions (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_table_stats_entry_apply_actions_get(obj, &val32);
    out += writer(cookie, "  apply_actions (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_table_stats_entry_write_setfields_get(obj, &val64);
    out += writer(cookie, "  write_setfields (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_table_stats_entry_apply_setfields_get(obj, &val64);
    out += writer(cookie, "  apply_setfields (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_table_stats_entry_metadata_match_get(obj, &val64);
    out += writer(cookie, "  metadata_match (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_table_stats_entry_metadata_write_get(obj, &val64);
    out += writer(cookie, "  metadata_write (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_table_stats_entry_instructions_get(obj, &val32);
    out += writer(cookie, "  instructions (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_table_stats_entry_config_get(obj, &val32);
    out += writer(cookie, "  config (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_table_stats_entry_max_entries_get(obj, &val32);
    out += writer(cookie, "  max_entries (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_table_stats_entry_active_count_get(obj, &val32);
    out += writer(cookie, "  active_count (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_table_stats_entry_lookup_count_get(obj, &val64);
    out += writer(cookie, "  lookup_count (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_table_stats_entry_matched_count_get(obj, &val64);
    out += writer(cookie, "  matched_count (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    return out;
}

int
of_list_action_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_list_action_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_list_action\n");

    return out;
}

int
of_list_bsn_interface_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_list_bsn_interface_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_list_bsn_interface\n");

    return out;
}

int
of_list_bucket_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_list_bucket_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_list_bucket\n");

    return out;
}

int
of_list_bucket_counter_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_list_bucket_counter_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_list_bucket_counter\n");

    return out;
}

int
of_list_flow_stats_entry_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_list_flow_stats_entry_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_list_flow_stats_entry\n");

    return out;
}

int
of_list_group_desc_stats_entry_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_list_group_desc_stats_entry_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_list_group_desc_stats_entry\n");

    return out;
}

int
of_list_group_stats_entry_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_list_group_stats_entry_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_list_group_stats_entry\n");

    return out;
}

int
of_list_instruction_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_list_instruction_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_list_instruction\n");

    return out;
}

int
of_list_oxm_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_list_oxm_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_list_oxm\n");

    return out;
}

int
of_list_packet_queue_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_list_packet_queue_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_list_packet_queue\n");

    return out;
}

int
of_list_port_desc_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_list_port_desc_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_list_port_desc\n");

    return out;
}

int
of_list_port_stats_entry_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_list_port_stats_entry_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_list_port_stats_entry\n");

    return out;
}

int
of_list_queue_prop_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_list_queue_prop_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_list_queue_prop\n");

    return out;
}

int
of_list_queue_stats_entry_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_list_queue_stats_entry_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_list_queue_stats_entry\n");

    return out;
}

int
of_list_table_stats_entry_OF_VERSION_1_2_dump(loci_writer_f writer, void* cookie, of_list_table_stats_entry_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_list_table_stats_entry\n");

    return out;
}

int
of_aggregate_stats_reply_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_aggregate_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    uint64_t val64;

    out += writer(cookie, "Object of type of_aggregate_stats_reply\n");

    of_aggregate_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_aggregate_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_aggregate_stats_reply_packet_count_get(obj, &val64);
    out += writer(cookie, "  packet_count (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_aggregate_stats_reply_byte_count_get(obj, &val64);
    out += writer(cookie, "  byte_count (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_aggregate_stats_reply_flow_count_get(obj, &val32);
    out += writer(cookie, "  flow_count (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_aggregate_stats_request_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_aggregate_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    uint8_t val8;
    of_port_no_t port_no;
    uint64_t val64;
    of_match_t match;

    out += writer(cookie, "Object of type of_aggregate_stats_request\n");

    of_aggregate_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_aggregate_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_aggregate_stats_request_table_id_get(obj, &val8);
    out += writer(cookie, "  table_id (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_aggregate_stats_request_out_port_get(obj, &port_no);
    out += writer(cookie, "  out_port (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_aggregate_stats_request_out_group_get(obj, &val32);
    out += writer(cookie, "  out_group (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_aggregate_stats_request_cookie_get(obj, &val64);
    out += writer(cookie, "  cookie (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_aggregate_stats_request_cookie_mask_get(obj, &val64);
    out += writer(cookie, "  cookie_mask (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_aggregate_stats_request_match_get(obj, &match);
    out += writer(cookie, "  match (of_match_t):  ");
    out += LOCI_DUMP_match(writer, cookie, match);
    out += writer(cookie, "\n");

    return out;
}

int
of_async_get_reply_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_async_get_reply_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_async_get_reply\n");

    of_async_get_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_async_get_reply_packet_in_mask_equal_master_get(obj, &val32);
    out += writer(cookie, "  packet_in_mask_equal_master (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_async_get_reply_packet_in_mask_slave_get(obj, &val32);
    out += writer(cookie, "  packet_in_mask_slave (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_async_get_reply_port_status_mask_equal_master_get(obj, &val32);
    out += writer(cookie, "  port_status_mask_equal_master (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_async_get_reply_port_status_mask_slave_get(obj, &val32);
    out += writer(cookie, "  port_status_mask_slave (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_async_get_reply_flow_removed_mask_equal_master_get(obj, &val32);
    out += writer(cookie, "  flow_removed_mask_equal_master (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_async_get_reply_flow_removed_mask_slave_get(obj, &val32);
    out += writer(cookie, "  flow_removed_mask_slave (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_async_get_request_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_async_get_request_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_async_get_request\n");

    of_async_get_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_async_get_request_packet_in_mask_equal_master_get(obj, &val32);
    out += writer(cookie, "  packet_in_mask_equal_master (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_async_get_request_packet_in_mask_slave_get(obj, &val32);
    out += writer(cookie, "  packet_in_mask_slave (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_async_get_request_port_status_mask_equal_master_get(obj, &val32);
    out += writer(cookie, "  port_status_mask_equal_master (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_async_get_request_port_status_mask_slave_get(obj, &val32);
    out += writer(cookie, "  port_status_mask_slave (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_async_get_request_flow_removed_mask_equal_master_get(obj, &val32);
    out += writer(cookie, "  flow_removed_mask_equal_master (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_async_get_request_flow_removed_mask_slave_get(obj, &val32);
    out += writer(cookie, "  flow_removed_mask_slave (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_async_set_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_async_set_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_async_set\n");

    of_async_set_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_async_set_packet_in_mask_equal_master_get(obj, &val32);
    out += writer(cookie, "  packet_in_mask_equal_master (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_async_set_packet_in_mask_slave_get(obj, &val32);
    out += writer(cookie, "  packet_in_mask_slave (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_async_set_port_status_mask_equal_master_get(obj, &val32);
    out += writer(cookie, "  port_status_mask_equal_master (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_async_set_port_status_mask_slave_get(obj, &val32);
    out += writer(cookie, "  port_status_mask_slave (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_async_set_flow_removed_mask_equal_master_get(obj, &val32);
    out += writer(cookie, "  flow_removed_mask_equal_master (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_async_set_flow_removed_mask_slave_get(obj, &val32);
    out += writer(cookie, "  flow_removed_mask_slave (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_bad_action_error_msg_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_bad_action_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_bad_action_error_msg\n");

    of_bad_action_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bad_action_error_msg_code_get(obj, &val16);
    out += writer(cookie, "  code (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_bad_action_error_msg_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_bad_instruction_error_msg_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_bad_instruction_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_bad_instruction_error_msg\n");

    of_bad_instruction_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bad_instruction_error_msg_code_get(obj, &val16);
    out += writer(cookie, "  code (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_bad_instruction_error_msg_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_bad_match_error_msg_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_bad_match_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_bad_match_error_msg\n");

    of_bad_match_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bad_match_error_msg_code_get(obj, &val16);
    out += writer(cookie, "  code (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_bad_match_error_msg_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_bad_request_error_msg_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_bad_request_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_bad_request_error_msg\n");

    of_bad_request_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bad_request_error_msg_code_get(obj, &val16);
    out += writer(cookie, "  code (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_bad_request_error_msg_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_barrier_reply_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_barrier_reply_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_barrier_reply\n");

    of_barrier_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_barrier_request_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_barrier_request_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_barrier_request\n");

    of_barrier_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_bw_clear_data_reply_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_bsn_bw_clear_data_reply_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_bsn_bw_clear_data_reply\n");

    of_bsn_bw_clear_data_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_bw_clear_data_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_bw_clear_data_reply_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_bw_clear_data_reply_status_get(obj, &val32);
    out += writer(cookie, "  status (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_bw_clear_data_request_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_bsn_bw_clear_data_request_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_bsn_bw_clear_data_request\n");

    of_bsn_bw_clear_data_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_bw_clear_data_request_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_bw_clear_data_request_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_bw_enable_get_reply_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_bsn_bw_enable_get_reply_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_bsn_bw_enable_get_reply\n");

    of_bsn_bw_enable_get_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_bw_enable_get_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_bw_enable_get_reply_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_bw_enable_get_reply_enabled_get(obj, &val32);
    out += writer(cookie, "  enabled (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_bw_enable_get_request_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_bsn_bw_enable_get_request_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_bsn_bw_enable_get_request\n");

    of_bsn_bw_enable_get_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_bw_enable_get_request_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_bw_enable_get_request_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_bw_enable_set_reply_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_bsn_bw_enable_set_reply_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_bsn_bw_enable_set_reply\n");

    of_bsn_bw_enable_set_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_bw_enable_set_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_bw_enable_set_reply_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_bw_enable_set_reply_enable_get(obj, &val32);
    out += writer(cookie, "  enable (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_bw_enable_set_reply_status_get(obj, &val32);
    out += writer(cookie, "  status (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_bw_enable_set_request_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_bsn_bw_enable_set_request_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_bsn_bw_enable_set_request\n");

    of_bsn_bw_enable_set_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_bw_enable_set_request_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_bw_enable_set_request_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_bw_enable_set_request_enable_get(obj, &val32);
    out += writer(cookie, "  enable (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_flow_idle_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_bsn_flow_idle_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint64_t val64;
    uint16_t val16;
    uint8_t val8;
    of_match_t match;

    out += writer(cookie, "Object of type of_bsn_flow_idle\n");

    of_bsn_flow_idle_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_flow_idle_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_flow_idle_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_flow_idle_cookie_get(obj, &val64);
    out += writer(cookie, "  cookie (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_bsn_flow_idle_priority_get(obj, &val16);
    out += writer(cookie, "  priority (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_bsn_flow_idle_table_id_get(obj, &val8);
    out += writer(cookie, "  table_id (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_bsn_flow_idle_match_get(obj, &match);
    out += writer(cookie, "  match (of_match_t):  ");
    out += LOCI_DUMP_match(writer, cookie, match);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_flow_idle_enable_get_reply_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_bsn_flow_idle_enable_get_reply_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_bsn_flow_idle_enable_get_reply\n");

    of_bsn_flow_idle_enable_get_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_flow_idle_enable_get_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_flow_idle_enable_get_reply_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_flow_idle_enable_get_reply_enabled_get(obj, &val32);
    out += writer(cookie, "  enabled (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_flow_idle_enable_get_request_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_bsn_flow_idle_enable_get_request_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_bsn_flow_idle_enable_get_request\n");

    of_bsn_flow_idle_enable_get_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_flow_idle_enable_get_request_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_flow_idle_enable_get_request_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_flow_idle_enable_set_reply_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_bsn_flow_idle_enable_set_reply_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_bsn_flow_idle_enable_set_reply\n");

    of_bsn_flow_idle_enable_set_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_flow_idle_enable_set_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_flow_idle_enable_set_reply_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_flow_idle_enable_set_reply_enable_get(obj, &val32);
    out += writer(cookie, "  enable (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_flow_idle_enable_set_reply_status_get(obj, &val32);
    out += writer(cookie, "  status (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_flow_idle_enable_set_request_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_bsn_flow_idle_enable_set_request_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_bsn_flow_idle_enable_set_request\n");

    of_bsn_flow_idle_enable_set_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_flow_idle_enable_set_request_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_flow_idle_enable_set_request_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_flow_idle_enable_set_request_enable_get(obj, &val32);
    out += writer(cookie, "  enable (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_get_interfaces_reply_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_bsn_get_interfaces_reply_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_list_bsn_interface_t list;
    of_bsn_interface_t elt;
    int rv;

    out += writer(cookie, "Object of type of_bsn_get_interfaces_reply\n");

    of_bsn_get_interfaces_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_get_interfaces_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_get_interfaces_reply_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_bsn_interface_t\n");
    of_bsn_get_interfaces_reply_interfaces_bind(obj, &list);
    OF_LIST_BSN_INTERFACE_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_bsn_get_interfaces_request_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_bsn_get_interfaces_request_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_bsn_get_interfaces_request\n");

    of_bsn_get_interfaces_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_get_interfaces_request_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_get_interfaces_request_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_get_mirroring_reply_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_bsn_get_mirroring_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint8_t val8;

    out += writer(cookie, "Object of type of_bsn_get_mirroring_reply\n");

    of_bsn_get_mirroring_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_get_mirroring_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_get_mirroring_reply_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_get_mirroring_reply_report_mirror_ports_get(obj, &val8);
    out += writer(cookie, "  report_mirror_ports (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_get_mirroring_request_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_bsn_get_mirroring_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint8_t val8;

    out += writer(cookie, "Object of type of_bsn_get_mirroring_request\n");

    of_bsn_get_mirroring_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_get_mirroring_request_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_get_mirroring_request_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_get_mirroring_request_report_mirror_ports_get(obj, &val8);
    out += writer(cookie, "  report_mirror_ports (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_header_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_bsn_header_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_bsn_header\n");

    of_bsn_header_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_header_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_header_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_lacp_convergence_notif_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_bsn_lacp_convergence_notif_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint8_t val8;
    of_port_no_t port_no;
    uint16_t val16;
    of_mac_addr_t mac_addr;

    out += writer(cookie, "Object of type of_bsn_lacp_convergence_notif\n");

    of_bsn_lacp_convergence_notif_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_lacp_convergence_notif_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_lacp_convergence_notif_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_lacp_convergence_notif_convergence_status_get(obj, &val8);
    out += writer(cookie, "  convergence_status (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_bsn_lacp_convergence_notif_port_no_get(obj, &port_no);
    out += writer(cookie, "  port_no (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_bsn_lacp_convergence_notif_actor_sys_priority_get(obj, &val16);
    out += writer(cookie, "  actor_sys_priority (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_bsn_lacp_convergence_notif_actor_sys_mac_get(obj, &mac_addr);
    out += writer(cookie, "  actor_sys_mac (of_mac_addr_t):  ");
    out += LOCI_DUMP_mac(writer, cookie, mac_addr);
    out += writer(cookie, "\n");

    of_bsn_lacp_convergence_notif_actor_port_priority_get(obj, &val16);
    out += writer(cookie, "  actor_port_priority (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_bsn_lacp_convergence_notif_actor_port_num_get(obj, &val16);
    out += writer(cookie, "  actor_port_num (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_bsn_lacp_convergence_notif_actor_key_get(obj, &val16);
    out += writer(cookie, "  actor_key (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_bsn_lacp_convergence_notif_partner_sys_priority_get(obj, &val16);
    out += writer(cookie, "  partner_sys_priority (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_bsn_lacp_convergence_notif_partner_sys_mac_get(obj, &mac_addr);
    out += writer(cookie, "  partner_sys_mac (of_mac_addr_t):  ");
    out += LOCI_DUMP_mac(writer, cookie, mac_addr);
    out += writer(cookie, "\n");

    of_bsn_lacp_convergence_notif_partner_port_priority_get(obj, &val16);
    out += writer(cookie, "  partner_port_priority (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_bsn_lacp_convergence_notif_partner_port_num_get(obj, &val16);
    out += writer(cookie, "  partner_port_num (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_bsn_lacp_convergence_notif_partner_key_get(obj, &val16);
    out += writer(cookie, "  partner_key (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_lacp_stats_reply_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_bsn_lacp_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_list_bsn_lacp_stats_entry_t list;
    of_bsn_lacp_stats_entry_t elt;
    int rv;

    out += writer(cookie, "Object of type of_bsn_lacp_stats_reply\n");

    of_bsn_lacp_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_lacp_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_bsn_lacp_stats_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_lacp_stats_reply_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_bsn_lacp_stats_entry_t\n");
    of_bsn_lacp_stats_reply_entries_bind(obj, &list);
    OF_LIST_BSN_LACP_STATS_ENTRY_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_bsn_lacp_stats_request_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_bsn_lacp_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    out += writer(cookie, "Object of type of_bsn_lacp_stats_request\n");

    of_bsn_lacp_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_lacp_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_bsn_lacp_stats_request_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_lacp_stats_request_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_pdu_rx_reply_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_bsn_pdu_rx_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_port_no_t port_no;
    uint8_t val8;

    out += writer(cookie, "Object of type of_bsn_pdu_rx_reply\n");

    of_bsn_pdu_rx_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_pdu_rx_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_pdu_rx_reply_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_pdu_rx_reply_status_get(obj, &val32);
    out += writer(cookie, "  status (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_pdu_rx_reply_port_no_get(obj, &port_no);
    out += writer(cookie, "  port_no (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_bsn_pdu_rx_reply_slot_num_get(obj, &val8);
    out += writer(cookie, "  slot_num (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_pdu_rx_request_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_bsn_pdu_rx_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_port_no_t port_no;
    uint8_t val8;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_bsn_pdu_rx_request\n");

    of_bsn_pdu_rx_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_pdu_rx_request_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_pdu_rx_request_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_pdu_rx_request_timeout_ms_get(obj, &val32);
    out += writer(cookie, "  timeout_ms (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_pdu_rx_request_port_no_get(obj, &port_no);
    out += writer(cookie, "  port_no (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_bsn_pdu_rx_request_slot_num_get(obj, &val8);
    out += writer(cookie, "  slot_num (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_bsn_pdu_rx_request_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_pdu_rx_timeout_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_bsn_pdu_rx_timeout_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_port_no_t port_no;
    uint8_t val8;

    out += writer(cookie, "Object of type of_bsn_pdu_rx_timeout\n");

    of_bsn_pdu_rx_timeout_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_pdu_rx_timeout_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_pdu_rx_timeout_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_pdu_rx_timeout_port_no_get(obj, &port_no);
    out += writer(cookie, "  port_no (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_bsn_pdu_rx_timeout_slot_num_get(obj, &val8);
    out += writer(cookie, "  slot_num (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_pdu_tx_reply_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_bsn_pdu_tx_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_port_no_t port_no;
    uint8_t val8;

    out += writer(cookie, "Object of type of_bsn_pdu_tx_reply\n");

    of_bsn_pdu_tx_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_pdu_tx_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_pdu_tx_reply_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_pdu_tx_reply_status_get(obj, &val32);
    out += writer(cookie, "  status (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_pdu_tx_reply_port_no_get(obj, &port_no);
    out += writer(cookie, "  port_no (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_bsn_pdu_tx_reply_slot_num_get(obj, &val8);
    out += writer(cookie, "  slot_num (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_pdu_tx_request_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_bsn_pdu_tx_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_port_no_t port_no;
    uint8_t val8;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_bsn_pdu_tx_request\n");

    of_bsn_pdu_tx_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_pdu_tx_request_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_pdu_tx_request_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_pdu_tx_request_tx_interval_ms_get(obj, &val32);
    out += writer(cookie, "  tx_interval_ms (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_pdu_tx_request_port_no_get(obj, &port_no);
    out += writer(cookie, "  port_no (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_bsn_pdu_tx_request_slot_num_get(obj, &val8);
    out += writer(cookie, "  slot_num (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_bsn_pdu_tx_request_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_set_lacp_reply_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_bsn_set_lacp_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_port_no_t port_no;

    out += writer(cookie, "Object of type of_bsn_set_lacp_reply\n");

    of_bsn_set_lacp_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_set_lacp_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_set_lacp_reply_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_set_lacp_reply_status_get(obj, &val32);
    out += writer(cookie, "  status (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_set_lacp_reply_port_no_get(obj, &port_no);
    out += writer(cookie, "  port_no (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_set_lacp_request_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_bsn_set_lacp_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint8_t val8;
    of_port_no_t port_no;
    uint16_t val16;
    of_mac_addr_t mac_addr;

    out += writer(cookie, "Object of type of_bsn_set_lacp_request\n");

    of_bsn_set_lacp_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_set_lacp_request_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_set_lacp_request_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_set_lacp_request_enabled_get(obj, &val8);
    out += writer(cookie, "  enabled (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_bsn_set_lacp_request_port_no_get(obj, &port_no);
    out += writer(cookie, "  port_no (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_bsn_set_lacp_request_actor_sys_priority_get(obj, &val16);
    out += writer(cookie, "  actor_sys_priority (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_bsn_set_lacp_request_actor_sys_mac_get(obj, &mac_addr);
    out += writer(cookie, "  actor_sys_mac (of_mac_addr_t):  ");
    out += LOCI_DUMP_mac(writer, cookie, mac_addr);
    out += writer(cookie, "\n");

    of_bsn_set_lacp_request_actor_port_priority_get(obj, &val16);
    out += writer(cookie, "  actor_port_priority (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_bsn_set_lacp_request_actor_port_num_get(obj, &val16);
    out += writer(cookie, "  actor_port_num (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_bsn_set_lacp_request_actor_key_get(obj, &val16);
    out += writer(cookie, "  actor_key (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_set_mirroring_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_bsn_set_mirroring_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint8_t val8;

    out += writer(cookie, "Object of type of_bsn_set_mirroring\n");

    of_bsn_set_mirroring_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_set_mirroring_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_set_mirroring_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_set_mirroring_report_mirror_ports_get(obj, &val8);
    out += writer(cookie, "  report_mirror_ports (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_set_pktin_suppression_reply_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_bsn_set_pktin_suppression_reply_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_bsn_set_pktin_suppression_reply\n");

    of_bsn_set_pktin_suppression_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_set_pktin_suppression_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_set_pktin_suppression_reply_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_set_pktin_suppression_reply_status_get(obj, &val32);
    out += writer(cookie, "  status (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_set_pktin_suppression_request_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_bsn_set_pktin_suppression_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint8_t val8;
    uint16_t val16;
    uint64_t val64;

    out += writer(cookie, "Object of type of_bsn_set_pktin_suppression_request\n");

    of_bsn_set_pktin_suppression_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_set_pktin_suppression_request_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_set_pktin_suppression_request_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_set_pktin_suppression_request_enabled_get(obj, &val8);
    out += writer(cookie, "  enabled (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_bsn_set_pktin_suppression_request_idle_timeout_get(obj, &val16);
    out += writer(cookie, "  idle_timeout (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_bsn_set_pktin_suppression_request_hard_timeout_get(obj, &val16);
    out += writer(cookie, "  hard_timeout (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_bsn_set_pktin_suppression_request_priority_get(obj, &val16);
    out += writer(cookie, "  priority (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_bsn_set_pktin_suppression_request_cookie_get(obj, &val64);
    out += writer(cookie, "  cookie (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_stats_reply_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_bsn_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    out += writer(cookie, "Object of type of_bsn_stats_reply\n");

    of_bsn_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_bsn_stats_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_stats_reply_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_stats_request_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_bsn_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    out += writer(cookie, "Object of type of_bsn_stats_request\n");

    of_bsn_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_bsn_stats_request_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_stats_request_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_time_reply_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_bsn_time_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint64_t val64;

    out += writer(cookie, "Object of type of_bsn_time_reply\n");

    of_bsn_time_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_time_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_time_reply_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_time_reply_time_ms_get(obj, &val64);
    out += writer(cookie, "  time_ms (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_time_request_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_bsn_time_request_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_bsn_time_request\n");

    of_bsn_time_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_time_request_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_time_request_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_virtual_port_create_reply_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_bsn_virtual_port_create_reply_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_bsn_virtual_port_create_reply\n");

    of_bsn_virtual_port_create_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_virtual_port_create_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_virtual_port_create_reply_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_virtual_port_create_reply_status_get(obj, &val32);
    out += writer(cookie, "  status (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_virtual_port_create_reply_vport_no_get(obj, &val32);
    out += writer(cookie, "  vport_no (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_virtual_port_create_request_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_bsn_virtual_port_create_request_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_bsn_vport_q_in_q_t vport;

    out += writer(cookie, "Object of type of_bsn_virtual_port_create_request\n");

    of_bsn_virtual_port_create_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_virtual_port_create_request_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_virtual_port_create_request_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_virtual_port_create_request_vport_bind(obj, &vport);
    out += of_bsn_vport_q_in_q_OF_VERSION_1_3_dump(writer, cookie, &vport);

    return out;
}

int
of_bsn_virtual_port_remove_reply_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_bsn_virtual_port_remove_reply_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_bsn_virtual_port_remove_reply\n");

    of_bsn_virtual_port_remove_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_virtual_port_remove_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_virtual_port_remove_reply_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_virtual_port_remove_reply_status_get(obj, &val32);
    out += writer(cookie, "  status (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_virtual_port_remove_request_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_bsn_virtual_port_remove_request_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_bsn_virtual_port_remove_request\n");

    of_bsn_virtual_port_remove_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_virtual_port_remove_request_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_virtual_port_remove_request_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_virtual_port_remove_request_vport_no_get(obj, &val32);
    out += writer(cookie, "  vport_no (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_desc_stats_reply_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_desc_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_desc_str_t desc_str;
    of_serial_num_t ser_num;

    out += writer(cookie, "Object of type of_desc_stats_reply\n");

    of_desc_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_desc_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_desc_stats_reply_mfr_desc_get(obj, &desc_str);
    out += writer(cookie, "  mfr_desc (of_desc_str_t):  ");
    out += LOCI_DUMP_desc_str(writer, cookie, desc_str);
    out += writer(cookie, "\n");

    of_desc_stats_reply_hw_desc_get(obj, &desc_str);
    out += writer(cookie, "  hw_desc (of_desc_str_t):  ");
    out += LOCI_DUMP_desc_str(writer, cookie, desc_str);
    out += writer(cookie, "\n");

    of_desc_stats_reply_sw_desc_get(obj, &desc_str);
    out += writer(cookie, "  sw_desc (of_desc_str_t):  ");
    out += LOCI_DUMP_desc_str(writer, cookie, desc_str);
    out += writer(cookie, "\n");

    of_desc_stats_reply_serial_num_get(obj, &ser_num);
    out += writer(cookie, "  serial_num (of_serial_num_t):  ");
    out += LOCI_DUMP_ser_num(writer, cookie, ser_num);
    out += writer(cookie, "\n");

    of_desc_stats_reply_dp_desc_get(obj, &desc_str);
    out += writer(cookie, "  dp_desc (of_desc_str_t):  ");
    out += LOCI_DUMP_desc_str(writer, cookie, desc_str);
    out += writer(cookie, "\n");

    return out;
}

int
of_desc_stats_request_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_desc_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    out += writer(cookie, "Object of type of_desc_stats_request\n");

    of_desc_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_desc_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_echo_reply_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_echo_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_echo_reply\n");

    of_echo_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_echo_reply_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_echo_request_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_echo_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_echo_request\n");

    of_echo_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_echo_request_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_error_msg_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_error_msg\n");

    of_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_experimenter_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_experimenter_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_experimenter\n");

    of_experimenter_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_experimenter_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_experimenter_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_experimenter_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_experimenter_error_msg_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_experimenter_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_experimenter_error_msg\n");

    of_experimenter_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_experimenter_error_msg_subtype_get(obj, &val16);
    out += writer(cookie, "  subtype (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_experimenter_error_msg_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_experimenter_error_msg_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_experimenter_stats_reply_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_experimenter_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    out += writer(cookie, "Object of type of_experimenter_stats_reply\n");

    of_experimenter_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_experimenter_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_experimenter_stats_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_experimenter_stats_reply_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_experimenter_stats_request_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_experimenter_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    out += writer(cookie, "Object of type of_experimenter_stats_request\n");

    of_experimenter_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_experimenter_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_experimenter_stats_request_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_experimenter_stats_request_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_features_reply_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_features_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint64_t val64;
    uint8_t val8;

    out += writer(cookie, "Object of type of_features_reply\n");

    of_features_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_features_reply_datapath_id_get(obj, &val64);
    out += writer(cookie, "  datapath_id (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_features_reply_n_buffers_get(obj, &val32);
    out += writer(cookie, "  n_buffers (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_features_reply_n_tables_get(obj, &val8);
    out += writer(cookie, "  n_tables (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_features_reply_auxiliary_id_get(obj, &val8);
    out += writer(cookie, "  auxiliary_id (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_features_reply_capabilities_get(obj, &val32);
    out += writer(cookie, "  capabilities (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_features_reply_reserved_get(obj, &val32);
    out += writer(cookie, "  reserved (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_features_request_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_features_request_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_features_request\n");

    of_features_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_flow_add_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_flow_add_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint64_t val64;
    uint8_t val8;
    uint16_t val16;
    of_port_no_t port_no;
    of_match_t match;

    of_list_instruction_t list;
    of_instruction_t elt;
    int rv;

    out += writer(cookie, "Object of type of_flow_add\n");

    of_flow_add_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_add_cookie_get(obj, &val64);
    out += writer(cookie, "  cookie (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_flow_add_cookie_mask_get(obj, &val64);
    out += writer(cookie, "  cookie_mask (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_flow_add_table_id_get(obj, &val8);
    out += writer(cookie, "  table_id (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_flow_add_idle_timeout_get(obj, &val16);
    out += writer(cookie, "  idle_timeout (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_add_hard_timeout_get(obj, &val16);
    out += writer(cookie, "  hard_timeout (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_add_priority_get(obj, &val16);
    out += writer(cookie, "  priority (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_add_buffer_id_get(obj, &val32);
    out += writer(cookie, "  buffer_id (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_add_out_port_get(obj, &port_no);
    out += writer(cookie, "  out_port (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_flow_add_out_group_get(obj, &val32);
    out += writer(cookie, "  out_group (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_add_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_add_match_get(obj, &match);
    out += writer(cookie, "  match (of_match_t):  ");
    out += LOCI_DUMP_match(writer, cookie, match);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_instruction_t\n");
    of_flow_add_instructions_bind(obj, &list);
    OF_LIST_INSTRUCTION_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_flow_delete_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_flow_delete_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint64_t val64;
    uint8_t val8;
    uint16_t val16;
    of_port_no_t port_no;
    of_match_t match;

    of_list_instruction_t list;
    of_instruction_t elt;
    int rv;

    out += writer(cookie, "Object of type of_flow_delete\n");

    of_flow_delete_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_delete_cookie_get(obj, &val64);
    out += writer(cookie, "  cookie (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_flow_delete_cookie_mask_get(obj, &val64);
    out += writer(cookie, "  cookie_mask (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_flow_delete_table_id_get(obj, &val8);
    out += writer(cookie, "  table_id (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_flow_delete_idle_timeout_get(obj, &val16);
    out += writer(cookie, "  idle_timeout (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_delete_hard_timeout_get(obj, &val16);
    out += writer(cookie, "  hard_timeout (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_delete_priority_get(obj, &val16);
    out += writer(cookie, "  priority (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_delete_buffer_id_get(obj, &val32);
    out += writer(cookie, "  buffer_id (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_delete_out_port_get(obj, &port_no);
    out += writer(cookie, "  out_port (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_flow_delete_out_group_get(obj, &val32);
    out += writer(cookie, "  out_group (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_delete_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_delete_match_get(obj, &match);
    out += writer(cookie, "  match (of_match_t):  ");
    out += LOCI_DUMP_match(writer, cookie, match);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_instruction_t\n");
    of_flow_delete_instructions_bind(obj, &list);
    OF_LIST_INSTRUCTION_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_flow_delete_strict_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_flow_delete_strict_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint64_t val64;
    uint8_t val8;
    uint16_t val16;
    of_port_no_t port_no;
    of_match_t match;

    of_list_instruction_t list;
    of_instruction_t elt;
    int rv;

    out += writer(cookie, "Object of type of_flow_delete_strict\n");

    of_flow_delete_strict_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_delete_strict_cookie_get(obj, &val64);
    out += writer(cookie, "  cookie (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_flow_delete_strict_cookie_mask_get(obj, &val64);
    out += writer(cookie, "  cookie_mask (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_flow_delete_strict_table_id_get(obj, &val8);
    out += writer(cookie, "  table_id (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_flow_delete_strict_idle_timeout_get(obj, &val16);
    out += writer(cookie, "  idle_timeout (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_delete_strict_hard_timeout_get(obj, &val16);
    out += writer(cookie, "  hard_timeout (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_delete_strict_priority_get(obj, &val16);
    out += writer(cookie, "  priority (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_delete_strict_buffer_id_get(obj, &val32);
    out += writer(cookie, "  buffer_id (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_delete_strict_out_port_get(obj, &port_no);
    out += writer(cookie, "  out_port (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_flow_delete_strict_out_group_get(obj, &val32);
    out += writer(cookie, "  out_group (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_delete_strict_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_delete_strict_match_get(obj, &match);
    out += writer(cookie, "  match (of_match_t):  ");
    out += LOCI_DUMP_match(writer, cookie, match);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_instruction_t\n");
    of_flow_delete_strict_instructions_bind(obj, &list);
    OF_LIST_INSTRUCTION_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_flow_mod_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_flow_mod_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint64_t val64;
    uint8_t val8;
    uint16_t val16;
    of_port_no_t port_no;
    of_match_t match;

    of_list_instruction_t list;
    of_instruction_t elt;
    int rv;

    out += writer(cookie, "Object of type of_flow_mod\n");

    of_flow_mod_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_mod_cookie_get(obj, &val64);
    out += writer(cookie, "  cookie (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_flow_mod_cookie_mask_get(obj, &val64);
    out += writer(cookie, "  cookie_mask (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_flow_mod_table_id_get(obj, &val8);
    out += writer(cookie, "  table_id (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_flow_mod_idle_timeout_get(obj, &val16);
    out += writer(cookie, "  idle_timeout (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_mod_hard_timeout_get(obj, &val16);
    out += writer(cookie, "  hard_timeout (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_mod_priority_get(obj, &val16);
    out += writer(cookie, "  priority (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_mod_buffer_id_get(obj, &val32);
    out += writer(cookie, "  buffer_id (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_mod_out_port_get(obj, &port_no);
    out += writer(cookie, "  out_port (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_flow_mod_out_group_get(obj, &val32);
    out += writer(cookie, "  out_group (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_mod_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_mod_match_get(obj, &match);
    out += writer(cookie, "  match (of_match_t):  ");
    out += LOCI_DUMP_match(writer, cookie, match);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_instruction_t\n");
    of_flow_mod_instructions_bind(obj, &list);
    OF_LIST_INSTRUCTION_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_flow_mod_failed_error_msg_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_flow_mod_failed_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_flow_mod_failed_error_msg\n");

    of_flow_mod_failed_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_mod_failed_error_msg_code_get(obj, &val16);
    out += writer(cookie, "  code (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_mod_failed_error_msg_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_flow_modify_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_flow_modify_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint64_t val64;
    uint8_t val8;
    uint16_t val16;
    of_port_no_t port_no;
    of_match_t match;

    of_list_instruction_t list;
    of_instruction_t elt;
    int rv;

    out += writer(cookie, "Object of type of_flow_modify\n");

    of_flow_modify_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_modify_cookie_get(obj, &val64);
    out += writer(cookie, "  cookie (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_flow_modify_cookie_mask_get(obj, &val64);
    out += writer(cookie, "  cookie_mask (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_flow_modify_table_id_get(obj, &val8);
    out += writer(cookie, "  table_id (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_flow_modify_idle_timeout_get(obj, &val16);
    out += writer(cookie, "  idle_timeout (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_modify_hard_timeout_get(obj, &val16);
    out += writer(cookie, "  hard_timeout (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_modify_priority_get(obj, &val16);
    out += writer(cookie, "  priority (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_modify_buffer_id_get(obj, &val32);
    out += writer(cookie, "  buffer_id (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_modify_out_port_get(obj, &port_no);
    out += writer(cookie, "  out_port (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_flow_modify_out_group_get(obj, &val32);
    out += writer(cookie, "  out_group (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_modify_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_modify_match_get(obj, &match);
    out += writer(cookie, "  match (of_match_t):  ");
    out += LOCI_DUMP_match(writer, cookie, match);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_instruction_t\n");
    of_flow_modify_instructions_bind(obj, &list);
    OF_LIST_INSTRUCTION_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_flow_modify_strict_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_flow_modify_strict_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint64_t val64;
    uint8_t val8;
    uint16_t val16;
    of_port_no_t port_no;
    of_match_t match;

    of_list_instruction_t list;
    of_instruction_t elt;
    int rv;

    out += writer(cookie, "Object of type of_flow_modify_strict\n");

    of_flow_modify_strict_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_modify_strict_cookie_get(obj, &val64);
    out += writer(cookie, "  cookie (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_flow_modify_strict_cookie_mask_get(obj, &val64);
    out += writer(cookie, "  cookie_mask (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_flow_modify_strict_table_id_get(obj, &val8);
    out += writer(cookie, "  table_id (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_flow_modify_strict_idle_timeout_get(obj, &val16);
    out += writer(cookie, "  idle_timeout (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_modify_strict_hard_timeout_get(obj, &val16);
    out += writer(cookie, "  hard_timeout (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_modify_strict_priority_get(obj, &val16);
    out += writer(cookie, "  priority (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_modify_strict_buffer_id_get(obj, &val32);
    out += writer(cookie, "  buffer_id (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_modify_strict_out_port_get(obj, &port_no);
    out += writer(cookie, "  out_port (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_flow_modify_strict_out_group_get(obj, &val32);
    out += writer(cookie, "  out_group (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_modify_strict_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_modify_strict_match_get(obj, &match);
    out += writer(cookie, "  match (of_match_t):  ");
    out += LOCI_DUMP_match(writer, cookie, match);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_instruction_t\n");
    of_flow_modify_strict_instructions_bind(obj, &list);
    OF_LIST_INSTRUCTION_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_flow_removed_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_flow_removed_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint64_t val64;
    uint16_t val16;
    uint8_t val8;
    of_match_t match;

    out += writer(cookie, "Object of type of_flow_removed\n");

    of_flow_removed_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_removed_cookie_get(obj, &val64);
    out += writer(cookie, "  cookie (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_flow_removed_priority_get(obj, &val16);
    out += writer(cookie, "  priority (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_removed_reason_get(obj, &val8);
    out += writer(cookie, "  reason (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_flow_removed_table_id_get(obj, &val8);
    out += writer(cookie, "  table_id (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_flow_removed_duration_sec_get(obj, &val32);
    out += writer(cookie, "  duration_sec (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_removed_duration_nsec_get(obj, &val32);
    out += writer(cookie, "  duration_nsec (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_removed_idle_timeout_get(obj, &val16);
    out += writer(cookie, "  idle_timeout (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_removed_hard_timeout_get(obj, &val16);
    out += writer(cookie, "  hard_timeout (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_removed_packet_count_get(obj, &val64);
    out += writer(cookie, "  packet_count (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_flow_removed_byte_count_get(obj, &val64);
    out += writer(cookie, "  byte_count (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_flow_removed_match_get(obj, &match);
    out += writer(cookie, "  match (of_match_t):  ");
    out += LOCI_DUMP_match(writer, cookie, match);
    out += writer(cookie, "\n");

    return out;
}

int
of_flow_stats_reply_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_flow_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_list_flow_stats_entry_t list;
    of_flow_stats_entry_t elt;
    int rv;

    out += writer(cookie, "Object of type of_flow_stats_reply\n");

    of_flow_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_flow_stats_entry_t\n");
    of_flow_stats_reply_entries_bind(obj, &list);
    OF_LIST_FLOW_STATS_ENTRY_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_flow_stats_request_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_flow_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    uint8_t val8;
    of_port_no_t port_no;
    uint64_t val64;
    of_match_t match;

    out += writer(cookie, "Object of type of_flow_stats_request\n");

    of_flow_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_stats_request_table_id_get(obj, &val8);
    out += writer(cookie, "  table_id (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_flow_stats_request_out_port_get(obj, &port_no);
    out += writer(cookie, "  out_port (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_flow_stats_request_out_group_get(obj, &val32);
    out += writer(cookie, "  out_group (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_stats_request_cookie_get(obj, &val64);
    out += writer(cookie, "  cookie (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_flow_stats_request_cookie_mask_get(obj, &val64);
    out += writer(cookie, "  cookie_mask (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_flow_stats_request_match_get(obj, &match);
    out += writer(cookie, "  match (of_match_t):  ");
    out += LOCI_DUMP_match(writer, cookie, match);
    out += writer(cookie, "\n");

    return out;
}

int
of_get_config_reply_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_get_config_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    out += writer(cookie, "Object of type of_get_config_reply\n");

    of_get_config_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_get_config_reply_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_get_config_reply_miss_send_len_get(obj, &val16);
    out += writer(cookie, "  miss_send_len (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_get_config_request_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_get_config_request_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_get_config_request\n");

    of_get_config_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_group_desc_stats_reply_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_group_desc_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_list_group_desc_stats_entry_t list;
    of_group_desc_stats_entry_t elt;
    int rv;

    out += writer(cookie, "Object of type of_group_desc_stats_reply\n");

    of_group_desc_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_group_desc_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_group_desc_stats_entry_t\n");
    of_group_desc_stats_reply_entries_bind(obj, &list);
    OF_LIST_GROUP_DESC_STATS_ENTRY_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_group_desc_stats_request_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_group_desc_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    out += writer(cookie, "Object of type of_group_desc_stats_request\n");

    of_group_desc_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_group_desc_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_group_features_stats_reply_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_group_features_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    out += writer(cookie, "Object of type of_group_features_stats_reply\n");

    of_group_features_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_group_features_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_group_features_stats_reply_types_get(obj, &val32);
    out += writer(cookie, "  types (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_group_features_stats_reply_capabilities_get(obj, &val32);
    out += writer(cookie, "  capabilities (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_group_features_stats_reply_max_groups_all_get(obj, &val32);
    out += writer(cookie, "  max_groups_all (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_group_features_stats_reply_max_groups_select_get(obj, &val32);
    out += writer(cookie, "  max_groups_select (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_group_features_stats_reply_max_groups_indirect_get(obj, &val32);
    out += writer(cookie, "  max_groups_indirect (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_group_features_stats_reply_max_groups_ff_get(obj, &val32);
    out += writer(cookie, "  max_groups_ff (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_group_features_stats_reply_actions_all_get(obj, &val32);
    out += writer(cookie, "  actions_all (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_group_features_stats_reply_actions_select_get(obj, &val32);
    out += writer(cookie, "  actions_select (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_group_features_stats_reply_actions_indirect_get(obj, &val32);
    out += writer(cookie, "  actions_indirect (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_group_features_stats_reply_actions_ff_get(obj, &val32);
    out += writer(cookie, "  actions_ff (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_group_features_stats_request_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_group_features_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    out += writer(cookie, "Object of type of_group_features_stats_request\n");

    of_group_features_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_group_features_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_group_mod_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_group_mod_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    uint8_t val8;

    of_list_bucket_t list;
    of_bucket_t elt;
    int rv;

    out += writer(cookie, "Object of type of_group_mod\n");

    of_group_mod_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_group_mod_command_get(obj, &val16);
    out += writer(cookie, "  command (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_group_mod_group_type_get(obj, &val8);
    out += writer(cookie, "  group_type (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_group_mod_group_id_get(obj, &val32);
    out += writer(cookie, "  group_id (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_bucket_t\n");
    of_group_mod_buckets_bind(obj, &list);
    OF_LIST_BUCKET_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_group_mod_failed_error_msg_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_group_mod_failed_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_group_mod_failed_error_msg\n");

    of_group_mod_failed_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_group_mod_failed_error_msg_code_get(obj, &val16);
    out += writer(cookie, "  code (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_group_mod_failed_error_msg_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_group_stats_reply_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_group_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_list_group_stats_entry_t list;
    of_group_stats_entry_t elt;
    int rv;

    out += writer(cookie, "Object of type of_group_stats_reply\n");

    of_group_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_group_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_group_stats_entry_t\n");
    of_group_stats_reply_entries_bind(obj, &list);
    OF_LIST_GROUP_STATS_ENTRY_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_group_stats_request_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_group_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    out += writer(cookie, "Object of type of_group_stats_request\n");

    of_group_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_group_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_group_stats_request_group_id_get(obj, &val32);
    out += writer(cookie, "  group_id (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_hello_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_hello_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_list_hello_elem_t list;
    of_hello_elem_t elt;
    int rv;

    out += writer(cookie, "Object of type of_hello\n");

    of_hello_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_hello_elem_t\n");
    of_hello_elements_bind(obj, &list);
    OF_LIST_HELLO_ELEM_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_hello_failed_error_msg_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_hello_failed_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_hello_failed_error_msg\n");

    of_hello_failed_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_hello_failed_error_msg_code_get(obj, &val16);
    out += writer(cookie, "  code (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_hello_failed_error_msg_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_meter_config_stats_reply_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_meter_config_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_list_meter_band_t list;
    of_meter_band_t elt;
    int rv;

    out += writer(cookie, "Object of type of_meter_config_stats_reply\n");

    of_meter_config_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_meter_config_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_meter_band_t\n");
    of_meter_config_stats_reply_entries_bind(obj, &list);
    OF_LIST_METER_BAND_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_meter_config_stats_request_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_meter_config_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    out += writer(cookie, "Object of type of_meter_config_stats_request\n");

    of_meter_config_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_meter_config_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_meter_config_stats_request_meter_id_get(obj, &val32);
    out += writer(cookie, "  meter_id (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_meter_features_stats_reply_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_meter_features_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_meter_features_t features;

    out += writer(cookie, "Object of type of_meter_features_stats_reply\n");

    of_meter_features_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_meter_features_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_meter_features_stats_reply_features_bind(obj, &features);
    out += of_meter_features_OF_VERSION_1_3_dump(writer, cookie, &features);

    return out;
}

int
of_meter_features_stats_request_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_meter_features_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    out += writer(cookie, "Object of type of_meter_features_stats_request\n");

    of_meter_features_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_meter_features_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_meter_mod_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_meter_mod_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_list_meter_band_t list;
    of_meter_band_t elt;
    int rv;

    out += writer(cookie, "Object of type of_meter_mod\n");

    of_meter_mod_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_meter_mod_command_get(obj, &val16);
    out += writer(cookie, "  command (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_meter_mod_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_meter_mod_meter_id_get(obj, &val32);
    out += writer(cookie, "  meter_id (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_meter_band_t\n");
    of_meter_mod_meters_bind(obj, &list);
    OF_LIST_METER_BAND_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_meter_mod_failed_error_msg_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_meter_mod_failed_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_meter_mod_failed_error_msg\n");

    of_meter_mod_failed_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_meter_mod_failed_error_msg_code_get(obj, &val16);
    out += writer(cookie, "  code (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_meter_mod_failed_error_msg_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_meter_stats_reply_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_meter_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_list_meter_stats_t list;
    of_meter_stats_t elt;
    int rv;

    out += writer(cookie, "Object of type of_meter_stats_reply\n");

    of_meter_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_meter_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_meter_stats_t\n");
    of_meter_stats_reply_entries_bind(obj, &list);
    OF_LIST_METER_STATS_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_meter_stats_request_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_meter_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    out += writer(cookie, "Object of type of_meter_stats_request\n");

    of_meter_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_meter_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_meter_stats_request_meter_id_get(obj, &val32);
    out += writer(cookie, "  meter_id (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_nicira_header_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_nicira_header_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_nicira_header\n");

    of_nicira_header_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_nicira_header_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_nicira_header_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_packet_in_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_packet_in_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    uint8_t val8;
    uint64_t val64;
    of_match_t match;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_packet_in\n");

    of_packet_in_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_packet_in_buffer_id_get(obj, &val32);
    out += writer(cookie, "  buffer_id (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_packet_in_total_len_get(obj, &val16);
    out += writer(cookie, "  total_len (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_packet_in_reason_get(obj, &val8);
    out += writer(cookie, "  reason (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_packet_in_table_id_get(obj, &val8);
    out += writer(cookie, "  table_id (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_packet_in_cookie_get(obj, &val64);
    out += writer(cookie, "  cookie (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_packet_in_match_get(obj, &match);
    out += writer(cookie, "  match (of_match_t):  ");
    out += LOCI_DUMP_match(writer, cookie, match);
    out += writer(cookie, "\n");

    of_packet_in_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_packet_out_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_packet_out_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_port_no_t port_no;

    of_list_action_t list;
    of_action_t elt;
    int rv;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_packet_out\n");

    of_packet_out_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_packet_out_buffer_id_get(obj, &val32);
    out += writer(cookie, "  buffer_id (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_packet_out_in_port_get(obj, &port_no);
    out += writer(cookie, "  in_port (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_action_t\n");
    of_packet_out_actions_bind(obj, &list);
    OF_LIST_ACTION_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    of_packet_out_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_port_desc_stats_reply_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_port_desc_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_list_port_desc_t list;
    of_port_desc_t elt;
    int rv;

    out += writer(cookie, "Object of type of_port_desc_stats_reply\n");

    of_port_desc_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_port_desc_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_port_desc_t\n");
    of_port_desc_stats_reply_entries_bind(obj, &list);
    OF_LIST_PORT_DESC_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_port_desc_stats_request_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_port_desc_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    out += writer(cookie, "Object of type of_port_desc_stats_request\n");

    of_port_desc_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_port_desc_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_port_mod_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_port_mod_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_port_no_t port_no;
    of_mac_addr_t mac_addr;

    out += writer(cookie, "Object of type of_port_mod\n");

    of_port_mod_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_port_mod_port_no_get(obj, &port_no);
    out += writer(cookie, "  port_no (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_port_mod_hw_addr_get(obj, &mac_addr);
    out += writer(cookie, "  hw_addr (of_mac_addr_t):  ");
    out += LOCI_DUMP_mac(writer, cookie, mac_addr);
    out += writer(cookie, "\n");

    of_port_mod_config_get(obj, &val32);
    out += writer(cookie, "  config (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_port_mod_mask_get(obj, &val32);
    out += writer(cookie, "  mask (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_port_mod_advertise_get(obj, &val32);
    out += writer(cookie, "  advertise (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_port_mod_failed_error_msg_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_port_mod_failed_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_port_mod_failed_error_msg\n");

    of_port_mod_failed_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_port_mod_failed_error_msg_code_get(obj, &val16);
    out += writer(cookie, "  code (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_port_mod_failed_error_msg_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_port_stats_reply_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_port_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_list_port_stats_entry_t list;
    of_port_stats_entry_t elt;
    int rv;

    out += writer(cookie, "Object of type of_port_stats_reply\n");

    of_port_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_port_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_port_stats_entry_t\n");
    of_port_stats_reply_entries_bind(obj, &list);
    OF_LIST_PORT_STATS_ENTRY_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_port_stats_request_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_port_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_port_no_t port_no;

    out += writer(cookie, "Object of type of_port_stats_request\n");

    of_port_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_port_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_port_stats_request_port_no_get(obj, &port_no);
    out += writer(cookie, "  port_no (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    return out;
}

int
of_port_status_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_port_status_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint8_t val8;

    of_port_desc_t port_desc;

    out += writer(cookie, "Object of type of_port_status\n");

    of_port_status_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_port_status_reason_get(obj, &val8);
    out += writer(cookie, "  reason (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_port_status_desc_bind(obj, &port_desc);
    out += of_port_desc_OF_VERSION_1_3_dump(writer, cookie, &port_desc);

    return out;
}

int
of_queue_get_config_reply_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_queue_get_config_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_port_no_t port_no;

    of_list_packet_queue_t list;
    of_packet_queue_t elt;
    int rv;

    out += writer(cookie, "Object of type of_queue_get_config_reply\n");

    of_queue_get_config_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_queue_get_config_reply_port_get(obj, &port_no);
    out += writer(cookie, "  port (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_packet_queue_t\n");
    of_queue_get_config_reply_queues_bind(obj, &list);
    OF_LIST_PACKET_QUEUE_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_queue_get_config_request_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_queue_get_config_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_port_no_t port_no;

    out += writer(cookie, "Object of type of_queue_get_config_request\n");

    of_queue_get_config_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_queue_get_config_request_port_get(obj, &port_no);
    out += writer(cookie, "  port (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    return out;
}

int
of_queue_op_failed_error_msg_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_queue_op_failed_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_queue_op_failed_error_msg\n");

    of_queue_op_failed_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_queue_op_failed_error_msg_code_get(obj, &val16);
    out += writer(cookie, "  code (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_queue_op_failed_error_msg_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_queue_stats_reply_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_queue_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_list_queue_stats_entry_t list;
    of_queue_stats_entry_t elt;
    int rv;

    out += writer(cookie, "Object of type of_queue_stats_reply\n");

    of_queue_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_queue_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_queue_stats_entry_t\n");
    of_queue_stats_reply_entries_bind(obj, &list);
    OF_LIST_QUEUE_STATS_ENTRY_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_queue_stats_request_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_queue_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_port_no_t port_no;

    out += writer(cookie, "Object of type of_queue_stats_request\n");

    of_queue_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_queue_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_queue_stats_request_port_no_get(obj, &port_no);
    out += writer(cookie, "  port_no (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_queue_stats_request_queue_id_get(obj, &val32);
    out += writer(cookie, "  queue_id (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_role_reply_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_role_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint64_t val64;

    out += writer(cookie, "Object of type of_role_reply\n");

    of_role_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_role_reply_role_get(obj, &val32);
    out += writer(cookie, "  role (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_role_reply_generation_id_get(obj, &val64);
    out += writer(cookie, "  generation_id (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    return out;
}

int
of_role_request_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_role_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint64_t val64;

    out += writer(cookie, "Object of type of_role_request\n");

    of_role_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_role_request_role_get(obj, &val32);
    out += writer(cookie, "  role (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_role_request_generation_id_get(obj, &val64);
    out += writer(cookie, "  generation_id (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    return out;
}

int
of_role_request_failed_error_msg_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_role_request_failed_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_role_request_failed_error_msg\n");

    of_role_request_failed_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_role_request_failed_error_msg_code_get(obj, &val16);
    out += writer(cookie, "  code (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_role_request_failed_error_msg_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_set_config_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_set_config_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    out += writer(cookie, "Object of type of_set_config\n");

    of_set_config_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_set_config_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_set_config_miss_send_len_get(obj, &val16);
    out += writer(cookie, "  miss_send_len (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_stats_reply_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    out += writer(cookie, "Object of type of_stats_reply\n");

    of_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_stats_request_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    out += writer(cookie, "Object of type of_stats_request\n");

    of_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_switch_config_failed_error_msg_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_switch_config_failed_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_switch_config_failed_error_msg\n");

    of_switch_config_failed_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_switch_config_failed_error_msg_code_get(obj, &val16);
    out += writer(cookie, "  code (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_switch_config_failed_error_msg_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_table_features_failed_error_msg_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_table_features_failed_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_table_features_failed_error_msg\n");

    of_table_features_failed_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_table_features_failed_error_msg_code_get(obj, &val16);
    out += writer(cookie, "  code (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_table_features_failed_error_msg_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_table_features_stats_reply_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_table_features_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_list_table_features_t list;
    of_table_features_t elt;
    int rv;

    out += writer(cookie, "Object of type of_table_features_stats_reply\n");

    of_table_features_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_table_features_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_table_features_t\n");
    of_table_features_stats_reply_entries_bind(obj, &list);
    OF_LIST_TABLE_FEATURES_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_table_features_stats_request_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_table_features_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_list_table_features_t list;
    of_table_features_t elt;
    int rv;

    out += writer(cookie, "Object of type of_table_features_stats_request\n");

    of_table_features_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_table_features_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_table_features_t\n");
    of_table_features_stats_request_entries_bind(obj, &list);
    OF_LIST_TABLE_FEATURES_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_table_mod_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_table_mod_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint8_t val8;

    out += writer(cookie, "Object of type of_table_mod\n");

    of_table_mod_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_table_mod_table_id_get(obj, &val8);
    out += writer(cookie, "  table_id (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_table_mod_config_get(obj, &val32);
    out += writer(cookie, "  config (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_table_mod_failed_error_msg_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_table_mod_failed_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_table_mod_failed_error_msg\n");

    of_table_mod_failed_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_table_mod_failed_error_msg_code_get(obj, &val16);
    out += writer(cookie, "  code (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_table_mod_failed_error_msg_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_table_stats_reply_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_table_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_list_table_stats_entry_t list;
    of_table_stats_entry_t elt;
    int rv;

    out += writer(cookie, "Object of type of_table_stats_reply\n");

    of_table_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_table_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_table_stats_entry_t\n");
    of_table_stats_reply_entries_bind(obj, &list);
    OF_LIST_TABLE_STATS_ENTRY_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_table_stats_request_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_table_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    out += writer(cookie, "Object of type of_table_stats_request\n");

    of_table_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_table_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_action_bsn_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_action_bsn_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_action_bsn\n");

    of_action_bsn_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_action_bsn_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_action_bsn_mirror_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_action_bsn_mirror_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint8_t val8;

    out += writer(cookie, "Object of type of_action_bsn_mirror\n");

    of_action_bsn_mirror_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_action_bsn_mirror_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_action_bsn_mirror_dest_port_get(obj, &val32);
    out += writer(cookie, "  dest_port (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_action_bsn_mirror_vlan_tag_get(obj, &val32);
    out += writer(cookie, "  vlan_tag (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_action_bsn_mirror_copy_stage_get(obj, &val8);
    out += writer(cookie, "  copy_stage (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_action_bsn_set_tunnel_dst_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_action_bsn_set_tunnel_dst_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_action_bsn_set_tunnel_dst\n");

    of_action_bsn_set_tunnel_dst_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_action_bsn_set_tunnel_dst_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_action_bsn_set_tunnel_dst_dst_get(obj, &val32);
    out += writer(cookie, "  dst (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_action_copy_ttl_in_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_action_copy_ttl_in_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_action_copy_ttl_in\n");

    return out;
}

int
of_action_copy_ttl_out_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_action_copy_ttl_out_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_action_copy_ttl_out\n");

    return out;
}

int
of_action_dec_mpls_ttl_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_action_dec_mpls_ttl_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_action_dec_mpls_ttl\n");

    return out;
}

int
of_action_dec_nw_ttl_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_action_dec_nw_ttl_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_action_dec_nw_ttl\n");

    return out;
}

int
of_action_experimenter_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_action_experimenter_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_action_experimenter\n");

    of_action_experimenter_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_action_experimenter_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_action_group_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_action_group_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_action_group\n");

    of_action_group_group_id_get(obj, &val32);
    out += writer(cookie, "  group_id (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_action_header_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_action_header_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_action_header\n");

    return out;
}

int
of_action_id_bsn_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_action_id_bsn_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_action_id_bsn\n");

    return out;
}

int
of_action_id_bsn_mirror_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_action_id_bsn_mirror_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_action_id_bsn_mirror\n");

    of_action_id_bsn_mirror_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_action_id_bsn_mirror_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_action_id_bsn_set_tunnel_dst_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_action_id_bsn_set_tunnel_dst_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_action_id_bsn_set_tunnel_dst\n");

    of_action_id_bsn_set_tunnel_dst_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_action_id_bsn_set_tunnel_dst_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_action_id_copy_ttl_in_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_action_id_copy_ttl_in_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_action_id_copy_ttl_in\n");

    return out;
}

int
of_action_id_copy_ttl_out_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_action_id_copy_ttl_out_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_action_id_copy_ttl_out\n");

    return out;
}

int
of_action_id_dec_mpls_ttl_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_action_id_dec_mpls_ttl_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_action_id_dec_mpls_ttl\n");

    return out;
}

int
of_action_id_dec_nw_ttl_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_action_id_dec_nw_ttl_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_action_id_dec_nw_ttl\n");

    return out;
}

int
of_action_id_experimenter_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_action_id_experimenter_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_action_id_experimenter\n");

    return out;
}

int
of_action_id_group_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_action_id_group_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_action_id_group\n");

    return out;
}

int
of_action_id_header_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_action_id_header_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_action_id_header\n");

    return out;
}

int
of_action_id_nicira_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_action_id_nicira_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_action_id_nicira\n");

    return out;
}

int
of_action_id_nicira_dec_ttl_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_action_id_nicira_dec_ttl_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    out += writer(cookie, "Object of type of_action_id_nicira_dec_ttl\n");

    of_action_id_nicira_dec_ttl_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_action_id_nicira_dec_ttl_subtype_get(obj, &val16);
    out += writer(cookie, "  subtype (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_action_id_output_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_action_id_output_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_action_id_output\n");

    return out;
}

int
of_action_id_pop_mpls_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_action_id_pop_mpls_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_action_id_pop_mpls\n");

    return out;
}

int
of_action_id_pop_pbb_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_action_id_pop_pbb_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_action_id_pop_pbb\n");

    return out;
}

int
of_action_id_pop_vlan_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_action_id_pop_vlan_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_action_id_pop_vlan\n");

    return out;
}

int
of_action_id_push_mpls_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_action_id_push_mpls_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_action_id_push_mpls\n");

    return out;
}

int
of_action_id_push_pbb_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_action_id_push_pbb_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_action_id_push_pbb\n");

    return out;
}

int
of_action_id_push_vlan_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_action_id_push_vlan_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_action_id_push_vlan\n");

    return out;
}

int
of_action_id_set_field_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_action_id_set_field_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_action_id_set_field\n");

    return out;
}

int
of_action_id_set_mpls_ttl_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_action_id_set_mpls_ttl_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_action_id_set_mpls_ttl\n");

    return out;
}

int
of_action_id_set_nw_ttl_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_action_id_set_nw_ttl_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_action_id_set_nw_ttl\n");

    return out;
}

int
of_action_id_set_queue_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_action_id_set_queue_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_action_id_set_queue\n");

    return out;
}

int
of_action_nicira_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_action_nicira_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    out += writer(cookie, "Object of type of_action_nicira\n");

    of_action_nicira_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_action_nicira_subtype_get(obj, &val16);
    out += writer(cookie, "  subtype (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_action_nicira_dec_ttl_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_action_nicira_dec_ttl_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    out += writer(cookie, "Object of type of_action_nicira_dec_ttl\n");

    of_action_nicira_dec_ttl_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_action_nicira_dec_ttl_subtype_get(obj, &val16);
    out += writer(cookie, "  subtype (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_action_output_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_action_output_t *obj)
{
    int out = 0;
    of_port_no_t port_no;
    uint16_t val16;

    out += writer(cookie, "Object of type of_action_output\n");

    of_action_output_port_get(obj, &port_no);
    out += writer(cookie, "  port (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_action_output_max_len_get(obj, &val16);
    out += writer(cookie, "  max_len (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_action_pop_mpls_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_action_pop_mpls_t *obj)
{
    int out = 0;
    uint16_t val16;

    out += writer(cookie, "Object of type of_action_pop_mpls\n");

    of_action_pop_mpls_ethertype_get(obj, &val16);
    out += writer(cookie, "  ethertype (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_action_pop_pbb_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_action_pop_pbb_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_action_pop_pbb\n");

    return out;
}

int
of_action_pop_vlan_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_action_pop_vlan_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_action_pop_vlan\n");

    return out;
}

int
of_action_push_mpls_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_action_push_mpls_t *obj)
{
    int out = 0;
    uint16_t val16;

    out += writer(cookie, "Object of type of_action_push_mpls\n");

    of_action_push_mpls_ethertype_get(obj, &val16);
    out += writer(cookie, "  ethertype (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_action_push_pbb_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_action_push_pbb_t *obj)
{
    int out = 0;
    uint16_t val16;

    out += writer(cookie, "Object of type of_action_push_pbb\n");

    of_action_push_pbb_ethertype_get(obj, &val16);
    out += writer(cookie, "  ethertype (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_action_push_vlan_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_action_push_vlan_t *obj)
{
    int out = 0;
    uint16_t val16;

    out += writer(cookie, "Object of type of_action_push_vlan\n");

    of_action_push_vlan_ethertype_get(obj, &val16);
    out += writer(cookie, "  ethertype (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_action_set_field_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_action_set_field_t *obj)
{
    int out = 0;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_action_set_field\n");

    of_action_set_field_field_get(obj, &octets);
    out += writer(cookie, "  field (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_action_set_mpls_ttl_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_action_set_mpls_ttl_t *obj)
{
    int out = 0;
    uint8_t val8;

    out += writer(cookie, "Object of type of_action_set_mpls_ttl\n");

    of_action_set_mpls_ttl_mpls_ttl_get(obj, &val8);
    out += writer(cookie, "  mpls_ttl (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_action_set_nw_ttl_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_action_set_nw_ttl_t *obj)
{
    int out = 0;
    uint8_t val8;

    out += writer(cookie, "Object of type of_action_set_nw_ttl\n");

    of_action_set_nw_ttl_nw_ttl_get(obj, &val8);
    out += writer(cookie, "  nw_ttl (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_action_set_queue_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_action_set_queue_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_action_set_queue\n");

    of_action_set_queue_queue_id_get(obj, &val32);
    out += writer(cookie, "  queue_id (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_interface_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_bsn_interface_t *obj)
{
    int out = 0;
    of_mac_addr_t mac_addr;
    of_port_name_t port_name;
    of_ipv4_t ipv4;

    out += writer(cookie, "Object of type of_bsn_interface\n");

    of_bsn_interface_hw_addr_get(obj, &mac_addr);
    out += writer(cookie, "  hw_addr (of_mac_addr_t):  ");
    out += LOCI_DUMP_mac(writer, cookie, mac_addr);
    out += writer(cookie, "\n");

    of_bsn_interface_name_get(obj, &port_name);
    out += writer(cookie, "  name (of_port_name_t):  ");
    out += LOCI_DUMP_port_name(writer, cookie, port_name);
    out += writer(cookie, "\n");

    of_bsn_interface_ipv4_addr_get(obj, &ipv4);
    out += writer(cookie, "  ipv4_addr (of_ipv4_t):  ");
    out += LOCI_DUMP_ipv4(writer, cookie, ipv4);
    out += writer(cookie, "\n");

    of_bsn_interface_ipv4_netmask_get(obj, &ipv4);
    out += writer(cookie, "  ipv4_netmask (of_ipv4_t):  ");
    out += LOCI_DUMP_ipv4(writer, cookie, ipv4);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_lacp_stats_entry_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_bsn_lacp_stats_entry_t *obj)
{
    int out = 0;
    of_port_no_t port_no;
    uint16_t val16;
    of_mac_addr_t mac_addr;
    uint8_t val8;

    out += writer(cookie, "Object of type of_bsn_lacp_stats_entry\n");

    of_bsn_lacp_stats_entry_port_no_get(obj, &port_no);
    out += writer(cookie, "  port_no (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_bsn_lacp_stats_entry_actor_sys_priority_get(obj, &val16);
    out += writer(cookie, "  actor_sys_priority (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_bsn_lacp_stats_entry_actor_sys_mac_get(obj, &mac_addr);
    out += writer(cookie, "  actor_sys_mac (of_mac_addr_t):  ");
    out += LOCI_DUMP_mac(writer, cookie, mac_addr);
    out += writer(cookie, "\n");

    of_bsn_lacp_stats_entry_actor_port_priority_get(obj, &val16);
    out += writer(cookie, "  actor_port_priority (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_bsn_lacp_stats_entry_actor_port_num_get(obj, &val16);
    out += writer(cookie, "  actor_port_num (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_bsn_lacp_stats_entry_actor_key_get(obj, &val16);
    out += writer(cookie, "  actor_key (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_bsn_lacp_stats_entry_convergence_status_get(obj, &val8);
    out += writer(cookie, "  convergence_status (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_bsn_lacp_stats_entry_partner_sys_priority_get(obj, &val16);
    out += writer(cookie, "  partner_sys_priority (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_bsn_lacp_stats_entry_partner_sys_mac_get(obj, &mac_addr);
    out += writer(cookie, "  partner_sys_mac (of_mac_addr_t):  ");
    out += LOCI_DUMP_mac(writer, cookie, mac_addr);
    out += writer(cookie, "\n");

    of_bsn_lacp_stats_entry_partner_port_priority_get(obj, &val16);
    out += writer(cookie, "  partner_port_priority (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_bsn_lacp_stats_entry_partner_port_num_get(obj, &val16);
    out += writer(cookie, "  partner_port_num (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_bsn_lacp_stats_entry_partner_key_get(obj, &val16);
    out += writer(cookie, "  partner_key (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_bsn_vport_header_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_bsn_vport_header_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_bsn_vport_header\n");

    return out;
}

int
of_bsn_vport_q_in_q_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_bsn_vport_q_in_q_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_port_name_t port_name;

    out += writer(cookie, "Object of type of_bsn_vport_q_in_q\n");

    of_bsn_vport_q_in_q_port_no_get(obj, &val32);
    out += writer(cookie, "  port_no (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_bsn_vport_q_in_q_ingress_tpid_get(obj, &val16);
    out += writer(cookie, "  ingress_tpid (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_bsn_vport_q_in_q_ingress_vlan_id_get(obj, &val16);
    out += writer(cookie, "  ingress_vlan_id (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_bsn_vport_q_in_q_egress_tpid_get(obj, &val16);
    out += writer(cookie, "  egress_tpid (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_bsn_vport_q_in_q_egress_vlan_id_get(obj, &val16);
    out += writer(cookie, "  egress_vlan_id (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_bsn_vport_q_in_q_if_name_get(obj, &port_name);
    out += writer(cookie, "  if_name (of_port_name_t):  ");
    out += LOCI_DUMP_port_name(writer, cookie, port_name);
    out += writer(cookie, "\n");

    return out;
}

int
of_bucket_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_bucket_t *obj)
{
    int out = 0;
    uint16_t val16;
    of_port_no_t port_no;
    uint32_t val32;

    of_list_action_t list;
    of_action_t elt;
    int rv;

    out += writer(cookie, "Object of type of_bucket\n");

    of_bucket_weight_get(obj, &val16);
    out += writer(cookie, "  weight (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_bucket_watch_port_get(obj, &port_no);
    out += writer(cookie, "  watch_port (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_bucket_watch_group_get(obj, &val32);
    out += writer(cookie, "  watch_group (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_action_t\n");
    of_bucket_actions_bind(obj, &list);
    OF_LIST_ACTION_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_bucket_counter_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_bucket_counter_t *obj)
{
    int out = 0;
    uint64_t val64;

    out += writer(cookie, "Object of type of_bucket_counter\n");

    of_bucket_counter_packet_count_get(obj, &val64);
    out += writer(cookie, "  packet_count (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_bucket_counter_byte_count_get(obj, &val64);
    out += writer(cookie, "  byte_count (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    return out;
}

int
of_experimenter_stats_header_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_experimenter_stats_header_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_experimenter_stats_header\n");

    of_experimenter_stats_header_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_experimenter_stats_header_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_flow_stats_entry_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_flow_stats_entry_t *obj)
{
    int out = 0;
    uint8_t val8;
    uint32_t val32;
    uint16_t val16;
    uint64_t val64;
    of_match_t match;

    of_list_instruction_t list;
    of_instruction_t elt;
    int rv;

    out += writer(cookie, "Object of type of_flow_stats_entry\n");

    of_flow_stats_entry_table_id_get(obj, &val8);
    out += writer(cookie, "  table_id (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_flow_stats_entry_duration_sec_get(obj, &val32);
    out += writer(cookie, "  duration_sec (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_stats_entry_duration_nsec_get(obj, &val32);
    out += writer(cookie, "  duration_nsec (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_flow_stats_entry_priority_get(obj, &val16);
    out += writer(cookie, "  priority (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_stats_entry_idle_timeout_get(obj, &val16);
    out += writer(cookie, "  idle_timeout (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_stats_entry_hard_timeout_get(obj, &val16);
    out += writer(cookie, "  hard_timeout (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_stats_entry_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_flow_stats_entry_cookie_get(obj, &val64);
    out += writer(cookie, "  cookie (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_flow_stats_entry_packet_count_get(obj, &val64);
    out += writer(cookie, "  packet_count (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_flow_stats_entry_byte_count_get(obj, &val64);
    out += writer(cookie, "  byte_count (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_flow_stats_entry_match_get(obj, &match);
    out += writer(cookie, "  match (of_match_t):  ");
    out += LOCI_DUMP_match(writer, cookie, match);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_instruction_t\n");
    of_flow_stats_entry_instructions_bind(obj, &list);
    OF_LIST_INSTRUCTION_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_group_desc_stats_entry_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_group_desc_stats_entry_t *obj)
{
    int out = 0;
    uint8_t val8;
    uint32_t val32;

    of_list_bucket_t list;
    of_bucket_t elt;
    int rv;

    out += writer(cookie, "Object of type of_group_desc_stats_entry\n");

    of_group_desc_stats_entry_group_type_get(obj, &val8);
    out += writer(cookie, "  group_type (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_group_desc_stats_entry_group_id_get(obj, &val32);
    out += writer(cookie, "  group_id (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_bucket_t\n");
    of_group_desc_stats_entry_buckets_bind(obj, &list);
    OF_LIST_BUCKET_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_group_stats_entry_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_group_stats_entry_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint64_t val64;

    of_list_bucket_counter_t list;
    of_bucket_counter_t elt;
    int rv;

    out += writer(cookie, "Object of type of_group_stats_entry\n");

    of_group_stats_entry_group_id_get(obj, &val32);
    out += writer(cookie, "  group_id (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_group_stats_entry_ref_count_get(obj, &val32);
    out += writer(cookie, "  ref_count (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_group_stats_entry_packet_count_get(obj, &val64);
    out += writer(cookie, "  packet_count (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_group_stats_entry_byte_count_get(obj, &val64);
    out += writer(cookie, "  byte_count (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_group_stats_entry_duration_sec_get(obj, &val32);
    out += writer(cookie, "  duration_sec (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_group_stats_entry_duration_nsec_get(obj, &val32);
    out += writer(cookie, "  duration_nsec (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_bucket_counter_t\n");
    of_group_stats_entry_bucket_stats_bind(obj, &list);
    OF_LIST_BUCKET_COUNTER_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_header_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_header_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_header\n");

    of_header_xid_get(obj, &val32);
    out += writer(cookie, "  xid (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_hello_elem_header_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_hello_elem_header_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_hello_elem_header\n");

    return out;
}

int
of_hello_elem_versionbitmap_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_hello_elem_versionbitmap_t *obj)
{
    int out = 0;

    of_list_uint32_t list;
    of_uint32_t elt;
    int rv;

    out += writer(cookie, "Object of type of_hello_elem_versionbitmap\n");

    out += writer(cookie, "List of of_uint32_t\n");
    of_hello_elem_versionbitmap_bitmaps_bind(obj, &list);
    OF_LIST_UINT32_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_instruction_apply_actions_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_instruction_apply_actions_t *obj)
{
    int out = 0;

    of_list_action_t list;
    of_action_t elt;
    int rv;

    out += writer(cookie, "Object of type of_instruction_apply_actions\n");

    out += writer(cookie, "List of of_action_t\n");
    of_instruction_apply_actions_actions_bind(obj, &list);
    OF_LIST_ACTION_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_instruction_clear_actions_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_instruction_clear_actions_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_instruction_clear_actions\n");

    return out;
}

int
of_instruction_experimenter_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_instruction_experimenter_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_instruction_experimenter\n");

    of_instruction_experimenter_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_instruction_experimenter_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_instruction_goto_table_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_instruction_goto_table_t *obj)
{
    int out = 0;
    uint8_t val8;

    out += writer(cookie, "Object of type of_instruction_goto_table\n");

    of_instruction_goto_table_table_id_get(obj, &val8);
    out += writer(cookie, "  table_id (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_instruction_header_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_instruction_header_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_instruction_header\n");

    return out;
}

int
of_instruction_meter_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_instruction_meter_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_instruction_meter\n");

    of_instruction_meter_meter_id_get(obj, &val32);
    out += writer(cookie, "  meter_id (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_instruction_write_actions_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_instruction_write_actions_t *obj)
{
    int out = 0;

    of_list_action_t list;
    of_action_t elt;
    int rv;

    out += writer(cookie, "Object of type of_instruction_write_actions\n");

    out += writer(cookie, "List of of_action_t\n");
    of_instruction_write_actions_actions_bind(obj, &list);
    OF_LIST_ACTION_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_instruction_write_metadata_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_instruction_write_metadata_t *obj)
{
    int out = 0;
    uint64_t val64;

    out += writer(cookie, "Object of type of_instruction_write_metadata\n");

    of_instruction_write_metadata_metadata_get(obj, &val64);
    out += writer(cookie, "  metadata (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_instruction_write_metadata_metadata_mask_get(obj, &val64);
    out += writer(cookie, "  metadata_mask (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    return out;
}

int
of_match_v3_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_match_v3_t *obj)
{
    int out = 0;

    of_list_oxm_t list;
    of_oxm_t elt;
    int rv;

    out += writer(cookie, "Object of type of_match_v3\n");

    out += writer(cookie, "List of of_oxm_t\n");
    of_match_v3_oxm_list_bind(obj, &list);
    OF_LIST_OXM_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_meter_band_drop_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_meter_band_drop_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_meter_band_drop\n");

    of_meter_band_drop_rate_get(obj, &val32);
    out += writer(cookie, "  rate (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_meter_band_drop_burst_size_get(obj, &val32);
    out += writer(cookie, "  burst_size (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_meter_band_dscp_remark_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_meter_band_dscp_remark_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint8_t val8;

    out += writer(cookie, "Object of type of_meter_band_dscp_remark\n");

    of_meter_band_dscp_remark_rate_get(obj, &val32);
    out += writer(cookie, "  rate (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_meter_band_dscp_remark_burst_size_get(obj, &val32);
    out += writer(cookie, "  burst_size (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_meter_band_dscp_remark_prec_level_get(obj, &val8);
    out += writer(cookie, "  prec_level (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_meter_band_experimenter_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_meter_band_experimenter_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_meter_band_experimenter\n");

    of_meter_band_experimenter_rate_get(obj, &val32);
    out += writer(cookie, "  rate (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_meter_band_experimenter_burst_size_get(obj, &val32);
    out += writer(cookie, "  burst_size (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_meter_band_experimenter_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_meter_band_header_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_meter_band_header_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_meter_band_header\n");

    return out;
}

int
of_meter_band_stats_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_meter_band_stats_t *obj)
{
    int out = 0;
    uint64_t val64;

    out += writer(cookie, "Object of type of_meter_band_stats\n");

    of_meter_band_stats_packet_band_count_get(obj, &val64);
    out += writer(cookie, "  packet_band_count (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_meter_band_stats_byte_band_count_get(obj, &val64);
    out += writer(cookie, "  byte_band_count (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    return out;
}

int
of_meter_config_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_meter_config_t *obj)
{
    int out = 0;
    uint16_t val16;
    uint32_t val32;

    of_list_meter_band_t list;
    of_meter_band_t elt;
    int rv;

    out += writer(cookie, "Object of type of_meter_config\n");

    of_meter_config_flags_get(obj, &val16);
    out += writer(cookie, "  flags (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_meter_config_meter_id_get(obj, &val32);
    out += writer(cookie, "  meter_id (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_meter_band_t\n");
    of_meter_config_entries_bind(obj, &list);
    OF_LIST_METER_BAND_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_meter_features_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_meter_features_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint8_t val8;

    out += writer(cookie, "Object of type of_meter_features\n");

    of_meter_features_max_meter_get(obj, &val32);
    out += writer(cookie, "  max_meter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_meter_features_band_types_get(obj, &val32);
    out += writer(cookie, "  band_types (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_meter_features_capabilities_get(obj, &val32);
    out += writer(cookie, "  capabilities (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_meter_features_max_bands_get(obj, &val8);
    out += writer(cookie, "  max_bands (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_meter_features_max_color_get(obj, &val8);
    out += writer(cookie, "  max_color (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_meter_stats_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_meter_stats_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint64_t val64;

    of_list_meter_band_stats_t list;
    of_meter_band_stats_t elt;
    int rv;

    out += writer(cookie, "Object of type of_meter_stats\n");

    of_meter_stats_meter_id_get(obj, &val32);
    out += writer(cookie, "  meter_id (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_meter_stats_flow_count_get(obj, &val32);
    out += writer(cookie, "  flow_count (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_meter_stats_packet_in_count_get(obj, &val64);
    out += writer(cookie, "  packet_in_count (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_meter_stats_byte_in_count_get(obj, &val64);
    out += writer(cookie, "  byte_in_count (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_meter_stats_duration_sec_get(obj, &val32);
    out += writer(cookie, "  duration_sec (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_meter_stats_duration_nsec_get(obj, &val32);
    out += writer(cookie, "  duration_nsec (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_meter_band_stats_t\n");
    of_meter_stats_band_stats_bind(obj, &list);
    OF_LIST_METER_BAND_STATS_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_oxm_arp_op_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_arp_op_t *obj)
{
    int out = 0;
    uint16_t val16;

    out += writer(cookie, "Object of type of_oxm_arp_op\n");

    of_oxm_arp_op_value_get(obj, &val16);
    out += writer(cookie, "  value (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_arp_op_masked_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_arp_op_masked_t *obj)
{
    int out = 0;
    uint16_t val16;

    out += writer(cookie, "Object of type of_oxm_arp_op_masked\n");

    of_oxm_arp_op_masked_value_get(obj, &val16);
    out += writer(cookie, "  value (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_oxm_arp_op_masked_value_mask_get(obj, &val16);
    out += writer(cookie, "  value_mask (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_arp_sha_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_arp_sha_t *obj)
{
    int out = 0;
    of_mac_addr_t mac_addr;

    out += writer(cookie, "Object of type of_oxm_arp_sha\n");

    of_oxm_arp_sha_value_get(obj, &mac_addr);
    out += writer(cookie, "  value (of_mac_addr_t):  ");
    out += LOCI_DUMP_mac(writer, cookie, mac_addr);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_arp_sha_masked_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_arp_sha_masked_t *obj)
{
    int out = 0;
    of_mac_addr_t mac_addr;

    out += writer(cookie, "Object of type of_oxm_arp_sha_masked\n");

    of_oxm_arp_sha_masked_value_get(obj, &mac_addr);
    out += writer(cookie, "  value (of_mac_addr_t):  ");
    out += LOCI_DUMP_mac(writer, cookie, mac_addr);
    out += writer(cookie, "\n");

    of_oxm_arp_sha_masked_value_mask_get(obj, &mac_addr);
    out += writer(cookie, "  value_mask (of_mac_addr_t):  ");
    out += LOCI_DUMP_mac(writer, cookie, mac_addr);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_arp_spa_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_arp_spa_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_oxm_arp_spa\n");

    of_oxm_arp_spa_value_get(obj, &val32);
    out += writer(cookie, "  value (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_arp_spa_masked_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_arp_spa_masked_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_oxm_arp_spa_masked\n");

    of_oxm_arp_spa_masked_value_get(obj, &val32);
    out += writer(cookie, "  value (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_oxm_arp_spa_masked_value_mask_get(obj, &val32);
    out += writer(cookie, "  value_mask (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_arp_tha_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_arp_tha_t *obj)
{
    int out = 0;
    of_mac_addr_t mac_addr;

    out += writer(cookie, "Object of type of_oxm_arp_tha\n");

    of_oxm_arp_tha_value_get(obj, &mac_addr);
    out += writer(cookie, "  value (of_mac_addr_t):  ");
    out += LOCI_DUMP_mac(writer, cookie, mac_addr);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_arp_tha_masked_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_arp_tha_masked_t *obj)
{
    int out = 0;
    of_mac_addr_t mac_addr;

    out += writer(cookie, "Object of type of_oxm_arp_tha_masked\n");

    of_oxm_arp_tha_masked_value_get(obj, &mac_addr);
    out += writer(cookie, "  value (of_mac_addr_t):  ");
    out += LOCI_DUMP_mac(writer, cookie, mac_addr);
    out += writer(cookie, "\n");

    of_oxm_arp_tha_masked_value_mask_get(obj, &mac_addr);
    out += writer(cookie, "  value_mask (of_mac_addr_t):  ");
    out += LOCI_DUMP_mac(writer, cookie, mac_addr);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_arp_tpa_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_arp_tpa_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_oxm_arp_tpa\n");

    of_oxm_arp_tpa_value_get(obj, &val32);
    out += writer(cookie, "  value (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_arp_tpa_masked_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_arp_tpa_masked_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_oxm_arp_tpa_masked\n");

    of_oxm_arp_tpa_masked_value_get(obj, &val32);
    out += writer(cookie, "  value (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_oxm_arp_tpa_masked_value_mask_get(obj, &val32);
    out += writer(cookie, "  value_mask (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_bsn_global_vrf_allowed_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_bsn_global_vrf_allowed_t *obj)
{
    int out = 0;
    uint8_t val8;

    out += writer(cookie, "Object of type of_oxm_bsn_global_vrf_allowed\n");

    of_oxm_bsn_global_vrf_allowed_value_get(obj, &val8);
    out += writer(cookie, "  value (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_bsn_global_vrf_allowed_masked_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_bsn_global_vrf_allowed_masked_t *obj)
{
    int out = 0;
    uint8_t val8;

    out += writer(cookie, "Object of type of_oxm_bsn_global_vrf_allowed_masked\n");

    of_oxm_bsn_global_vrf_allowed_masked_value_get(obj, &val8);
    out += writer(cookie, "  value (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_oxm_bsn_global_vrf_allowed_masked_value_mask_get(obj, &val8);
    out += writer(cookie, "  value_mask (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_bsn_in_ports_128_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_bsn_in_ports_128_t *obj)
{
    int out = 0;
    of_bitmap_128_t bitmap_128;

    out += writer(cookie, "Object of type of_oxm_bsn_in_ports_128\n");

    of_oxm_bsn_in_ports_128_value_get(obj, &bitmap_128);
    out += writer(cookie, "  value (of_bitmap_128_t):  ");
    out += LOCI_DUMP_bitmap_128(writer, cookie, bitmap_128);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_bsn_in_ports_128_masked_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_bsn_in_ports_128_masked_t *obj)
{
    int out = 0;
    of_bitmap_128_t bitmap_128;

    out += writer(cookie, "Object of type of_oxm_bsn_in_ports_128_masked\n");

    of_oxm_bsn_in_ports_128_masked_value_get(obj, &bitmap_128);
    out += writer(cookie, "  value (of_bitmap_128_t):  ");
    out += LOCI_DUMP_bitmap_128(writer, cookie, bitmap_128);
    out += writer(cookie, "\n");

    of_oxm_bsn_in_ports_128_masked_value_mask_get(obj, &bitmap_128);
    out += writer(cookie, "  value_mask (of_bitmap_128_t):  ");
    out += LOCI_DUMP_bitmap_128(writer, cookie, bitmap_128);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_bsn_l3_dst_class_id_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_bsn_l3_dst_class_id_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_oxm_bsn_l3_dst_class_id\n");

    of_oxm_bsn_l3_dst_class_id_value_get(obj, &val32);
    out += writer(cookie, "  value (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_bsn_l3_dst_class_id_masked_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_bsn_l3_dst_class_id_masked_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_oxm_bsn_l3_dst_class_id_masked\n");

    of_oxm_bsn_l3_dst_class_id_masked_value_get(obj, &val32);
    out += writer(cookie, "  value (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_oxm_bsn_l3_dst_class_id_masked_value_mask_get(obj, &val32);
    out += writer(cookie, "  value_mask (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_bsn_l3_interface_class_id_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_bsn_l3_interface_class_id_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_oxm_bsn_l3_interface_class_id\n");

    of_oxm_bsn_l3_interface_class_id_value_get(obj, &val32);
    out += writer(cookie, "  value (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_bsn_l3_interface_class_id_masked_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_bsn_l3_interface_class_id_masked_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_oxm_bsn_l3_interface_class_id_masked\n");

    of_oxm_bsn_l3_interface_class_id_masked_value_get(obj, &val32);
    out += writer(cookie, "  value (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_oxm_bsn_l3_interface_class_id_masked_value_mask_get(obj, &val32);
    out += writer(cookie, "  value_mask (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_bsn_l3_src_class_id_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_bsn_l3_src_class_id_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_oxm_bsn_l3_src_class_id\n");

    of_oxm_bsn_l3_src_class_id_value_get(obj, &val32);
    out += writer(cookie, "  value (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_bsn_l3_src_class_id_masked_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_bsn_l3_src_class_id_masked_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_oxm_bsn_l3_src_class_id_masked\n");

    of_oxm_bsn_l3_src_class_id_masked_value_get(obj, &val32);
    out += writer(cookie, "  value (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_oxm_bsn_l3_src_class_id_masked_value_mask_get(obj, &val32);
    out += writer(cookie, "  value_mask (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_bsn_lag_id_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_bsn_lag_id_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_oxm_bsn_lag_id\n");

    of_oxm_bsn_lag_id_value_get(obj, &val32);
    out += writer(cookie, "  value (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_bsn_lag_id_masked_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_bsn_lag_id_masked_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_oxm_bsn_lag_id_masked\n");

    of_oxm_bsn_lag_id_masked_value_get(obj, &val32);
    out += writer(cookie, "  value (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_oxm_bsn_lag_id_masked_value_mask_get(obj, &val32);
    out += writer(cookie, "  value_mask (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_bsn_vrf_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_bsn_vrf_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_oxm_bsn_vrf\n");

    of_oxm_bsn_vrf_value_get(obj, &val32);
    out += writer(cookie, "  value (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_bsn_vrf_masked_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_bsn_vrf_masked_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_oxm_bsn_vrf_masked\n");

    of_oxm_bsn_vrf_masked_value_get(obj, &val32);
    out += writer(cookie, "  value (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_oxm_bsn_vrf_masked_value_mask_get(obj, &val32);
    out += writer(cookie, "  value_mask (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_eth_dst_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_eth_dst_t *obj)
{
    int out = 0;
    of_mac_addr_t mac_addr;

    out += writer(cookie, "Object of type of_oxm_eth_dst\n");

    of_oxm_eth_dst_value_get(obj, &mac_addr);
    out += writer(cookie, "  value (of_mac_addr_t):  ");
    out += LOCI_DUMP_mac(writer, cookie, mac_addr);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_eth_dst_masked_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_eth_dst_masked_t *obj)
{
    int out = 0;
    of_mac_addr_t mac_addr;

    out += writer(cookie, "Object of type of_oxm_eth_dst_masked\n");

    of_oxm_eth_dst_masked_value_get(obj, &mac_addr);
    out += writer(cookie, "  value (of_mac_addr_t):  ");
    out += LOCI_DUMP_mac(writer, cookie, mac_addr);
    out += writer(cookie, "\n");

    of_oxm_eth_dst_masked_value_mask_get(obj, &mac_addr);
    out += writer(cookie, "  value_mask (of_mac_addr_t):  ");
    out += LOCI_DUMP_mac(writer, cookie, mac_addr);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_eth_src_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_eth_src_t *obj)
{
    int out = 0;
    of_mac_addr_t mac_addr;

    out += writer(cookie, "Object of type of_oxm_eth_src\n");

    of_oxm_eth_src_value_get(obj, &mac_addr);
    out += writer(cookie, "  value (of_mac_addr_t):  ");
    out += LOCI_DUMP_mac(writer, cookie, mac_addr);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_eth_src_masked_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_eth_src_masked_t *obj)
{
    int out = 0;
    of_mac_addr_t mac_addr;

    out += writer(cookie, "Object of type of_oxm_eth_src_masked\n");

    of_oxm_eth_src_masked_value_get(obj, &mac_addr);
    out += writer(cookie, "  value (of_mac_addr_t):  ");
    out += LOCI_DUMP_mac(writer, cookie, mac_addr);
    out += writer(cookie, "\n");

    of_oxm_eth_src_masked_value_mask_get(obj, &mac_addr);
    out += writer(cookie, "  value_mask (of_mac_addr_t):  ");
    out += LOCI_DUMP_mac(writer, cookie, mac_addr);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_eth_type_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_eth_type_t *obj)
{
    int out = 0;
    uint16_t val16;

    out += writer(cookie, "Object of type of_oxm_eth_type\n");

    of_oxm_eth_type_value_get(obj, &val16);
    out += writer(cookie, "  value (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_eth_type_masked_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_eth_type_masked_t *obj)
{
    int out = 0;
    uint16_t val16;

    out += writer(cookie, "Object of type of_oxm_eth_type_masked\n");

    of_oxm_eth_type_masked_value_get(obj, &val16);
    out += writer(cookie, "  value (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_oxm_eth_type_masked_value_mask_get(obj, &val16);
    out += writer(cookie, "  value_mask (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_header_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_header_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_oxm_header\n");

    return out;
}

int
of_oxm_icmpv4_code_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_icmpv4_code_t *obj)
{
    int out = 0;
    uint8_t val8;

    out += writer(cookie, "Object of type of_oxm_icmpv4_code\n");

    of_oxm_icmpv4_code_value_get(obj, &val8);
    out += writer(cookie, "  value (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_icmpv4_code_masked_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_icmpv4_code_masked_t *obj)
{
    int out = 0;
    uint8_t val8;

    out += writer(cookie, "Object of type of_oxm_icmpv4_code_masked\n");

    of_oxm_icmpv4_code_masked_value_get(obj, &val8);
    out += writer(cookie, "  value (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_oxm_icmpv4_code_masked_value_mask_get(obj, &val8);
    out += writer(cookie, "  value_mask (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_icmpv4_type_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_icmpv4_type_t *obj)
{
    int out = 0;
    uint8_t val8;

    out += writer(cookie, "Object of type of_oxm_icmpv4_type\n");

    of_oxm_icmpv4_type_value_get(obj, &val8);
    out += writer(cookie, "  value (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_icmpv4_type_masked_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_icmpv4_type_masked_t *obj)
{
    int out = 0;
    uint8_t val8;

    out += writer(cookie, "Object of type of_oxm_icmpv4_type_masked\n");

    of_oxm_icmpv4_type_masked_value_get(obj, &val8);
    out += writer(cookie, "  value (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_oxm_icmpv4_type_masked_value_mask_get(obj, &val8);
    out += writer(cookie, "  value_mask (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_icmpv6_code_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_icmpv6_code_t *obj)
{
    int out = 0;
    uint8_t val8;

    out += writer(cookie, "Object of type of_oxm_icmpv6_code\n");

    of_oxm_icmpv6_code_value_get(obj, &val8);
    out += writer(cookie, "  value (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_icmpv6_code_masked_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_icmpv6_code_masked_t *obj)
{
    int out = 0;
    uint8_t val8;

    out += writer(cookie, "Object of type of_oxm_icmpv6_code_masked\n");

    of_oxm_icmpv6_code_masked_value_get(obj, &val8);
    out += writer(cookie, "  value (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_oxm_icmpv6_code_masked_value_mask_get(obj, &val8);
    out += writer(cookie, "  value_mask (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_icmpv6_type_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_icmpv6_type_t *obj)
{
    int out = 0;
    uint8_t val8;

    out += writer(cookie, "Object of type of_oxm_icmpv6_type\n");

    of_oxm_icmpv6_type_value_get(obj, &val8);
    out += writer(cookie, "  value (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_icmpv6_type_masked_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_icmpv6_type_masked_t *obj)
{
    int out = 0;
    uint8_t val8;

    out += writer(cookie, "Object of type of_oxm_icmpv6_type_masked\n");

    of_oxm_icmpv6_type_masked_value_get(obj, &val8);
    out += writer(cookie, "  value (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_oxm_icmpv6_type_masked_value_mask_get(obj, &val8);
    out += writer(cookie, "  value_mask (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_in_phy_port_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_in_phy_port_t *obj)
{
    int out = 0;
    of_port_no_t port_no;

    out += writer(cookie, "Object of type of_oxm_in_phy_port\n");

    of_oxm_in_phy_port_value_get(obj, &port_no);
    out += writer(cookie, "  value (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_in_phy_port_masked_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_in_phy_port_masked_t *obj)
{
    int out = 0;
    of_port_no_t port_no;

    out += writer(cookie, "Object of type of_oxm_in_phy_port_masked\n");

    of_oxm_in_phy_port_masked_value_get(obj, &port_no);
    out += writer(cookie, "  value (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_oxm_in_phy_port_masked_value_mask_get(obj, &port_no);
    out += writer(cookie, "  value_mask (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_in_port_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_in_port_t *obj)
{
    int out = 0;
    of_port_no_t port_no;

    out += writer(cookie, "Object of type of_oxm_in_port\n");

    of_oxm_in_port_value_get(obj, &port_no);
    out += writer(cookie, "  value (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_in_port_masked_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_in_port_masked_t *obj)
{
    int out = 0;
    of_port_no_t port_no;

    out += writer(cookie, "Object of type of_oxm_in_port_masked\n");

    of_oxm_in_port_masked_value_get(obj, &port_no);
    out += writer(cookie, "  value (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_oxm_in_port_masked_value_mask_get(obj, &port_no);
    out += writer(cookie, "  value_mask (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_ip_dscp_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_ip_dscp_t *obj)
{
    int out = 0;
    uint8_t val8;

    out += writer(cookie, "Object of type of_oxm_ip_dscp\n");

    of_oxm_ip_dscp_value_get(obj, &val8);
    out += writer(cookie, "  value (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_ip_dscp_masked_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_ip_dscp_masked_t *obj)
{
    int out = 0;
    uint8_t val8;

    out += writer(cookie, "Object of type of_oxm_ip_dscp_masked\n");

    of_oxm_ip_dscp_masked_value_get(obj, &val8);
    out += writer(cookie, "  value (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_oxm_ip_dscp_masked_value_mask_get(obj, &val8);
    out += writer(cookie, "  value_mask (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_ip_ecn_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_ip_ecn_t *obj)
{
    int out = 0;
    uint8_t val8;

    out += writer(cookie, "Object of type of_oxm_ip_ecn\n");

    of_oxm_ip_ecn_value_get(obj, &val8);
    out += writer(cookie, "  value (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_ip_ecn_masked_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_ip_ecn_masked_t *obj)
{
    int out = 0;
    uint8_t val8;

    out += writer(cookie, "Object of type of_oxm_ip_ecn_masked\n");

    of_oxm_ip_ecn_masked_value_get(obj, &val8);
    out += writer(cookie, "  value (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_oxm_ip_ecn_masked_value_mask_get(obj, &val8);
    out += writer(cookie, "  value_mask (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_ip_proto_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_ip_proto_t *obj)
{
    int out = 0;
    uint8_t val8;

    out += writer(cookie, "Object of type of_oxm_ip_proto\n");

    of_oxm_ip_proto_value_get(obj, &val8);
    out += writer(cookie, "  value (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_ip_proto_masked_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_ip_proto_masked_t *obj)
{
    int out = 0;
    uint8_t val8;

    out += writer(cookie, "Object of type of_oxm_ip_proto_masked\n");

    of_oxm_ip_proto_masked_value_get(obj, &val8);
    out += writer(cookie, "  value (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_oxm_ip_proto_masked_value_mask_get(obj, &val8);
    out += writer(cookie, "  value_mask (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_ipv4_dst_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_ipv4_dst_t *obj)
{
    int out = 0;
    of_ipv4_t ipv4;

    out += writer(cookie, "Object of type of_oxm_ipv4_dst\n");

    of_oxm_ipv4_dst_value_get(obj, &ipv4);
    out += writer(cookie, "  value (of_ipv4_t):  ");
    out += LOCI_DUMP_ipv4(writer, cookie, ipv4);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_ipv4_dst_masked_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_ipv4_dst_masked_t *obj)
{
    int out = 0;
    of_ipv4_t ipv4;

    out += writer(cookie, "Object of type of_oxm_ipv4_dst_masked\n");

    of_oxm_ipv4_dst_masked_value_get(obj, &ipv4);
    out += writer(cookie, "  value (of_ipv4_t):  ");
    out += LOCI_DUMP_ipv4(writer, cookie, ipv4);
    out += writer(cookie, "\n");

    of_oxm_ipv4_dst_masked_value_mask_get(obj, &ipv4);
    out += writer(cookie, "  value_mask (of_ipv4_t):  ");
    out += LOCI_DUMP_ipv4(writer, cookie, ipv4);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_ipv4_src_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_ipv4_src_t *obj)
{
    int out = 0;
    of_ipv4_t ipv4;

    out += writer(cookie, "Object of type of_oxm_ipv4_src\n");

    of_oxm_ipv4_src_value_get(obj, &ipv4);
    out += writer(cookie, "  value (of_ipv4_t):  ");
    out += LOCI_DUMP_ipv4(writer, cookie, ipv4);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_ipv4_src_masked_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_ipv4_src_masked_t *obj)
{
    int out = 0;
    of_ipv4_t ipv4;

    out += writer(cookie, "Object of type of_oxm_ipv4_src_masked\n");

    of_oxm_ipv4_src_masked_value_get(obj, &ipv4);
    out += writer(cookie, "  value (of_ipv4_t):  ");
    out += LOCI_DUMP_ipv4(writer, cookie, ipv4);
    out += writer(cookie, "\n");

    of_oxm_ipv4_src_masked_value_mask_get(obj, &ipv4);
    out += writer(cookie, "  value_mask (of_ipv4_t):  ");
    out += LOCI_DUMP_ipv4(writer, cookie, ipv4);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_ipv6_dst_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_ipv6_dst_t *obj)
{
    int out = 0;
    of_ipv6_t ipv6;

    out += writer(cookie, "Object of type of_oxm_ipv6_dst\n");

    of_oxm_ipv6_dst_value_get(obj, &ipv6);
    out += writer(cookie, "  value (of_ipv6_t):  ");
    out += LOCI_DUMP_ipv6(writer, cookie, ipv6);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_ipv6_dst_masked_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_ipv6_dst_masked_t *obj)
{
    int out = 0;
    of_ipv6_t ipv6;

    out += writer(cookie, "Object of type of_oxm_ipv6_dst_masked\n");

    of_oxm_ipv6_dst_masked_value_get(obj, &ipv6);
    out += writer(cookie, "  value (of_ipv6_t):  ");
    out += LOCI_DUMP_ipv6(writer, cookie, ipv6);
    out += writer(cookie, "\n");

    of_oxm_ipv6_dst_masked_value_mask_get(obj, &ipv6);
    out += writer(cookie, "  value_mask (of_ipv6_t):  ");
    out += LOCI_DUMP_ipv6(writer, cookie, ipv6);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_ipv6_flabel_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_ipv6_flabel_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_oxm_ipv6_flabel\n");

    of_oxm_ipv6_flabel_value_get(obj, &val32);
    out += writer(cookie, "  value (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_ipv6_flabel_masked_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_ipv6_flabel_masked_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_oxm_ipv6_flabel_masked\n");

    of_oxm_ipv6_flabel_masked_value_get(obj, &val32);
    out += writer(cookie, "  value (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_oxm_ipv6_flabel_masked_value_mask_get(obj, &val32);
    out += writer(cookie, "  value_mask (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_ipv6_nd_sll_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_ipv6_nd_sll_t *obj)
{
    int out = 0;
    of_mac_addr_t mac_addr;

    out += writer(cookie, "Object of type of_oxm_ipv6_nd_sll\n");

    of_oxm_ipv6_nd_sll_value_get(obj, &mac_addr);
    out += writer(cookie, "  value (of_mac_addr_t):  ");
    out += LOCI_DUMP_mac(writer, cookie, mac_addr);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_ipv6_nd_sll_masked_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_ipv6_nd_sll_masked_t *obj)
{
    int out = 0;
    of_mac_addr_t mac_addr;

    out += writer(cookie, "Object of type of_oxm_ipv6_nd_sll_masked\n");

    of_oxm_ipv6_nd_sll_masked_value_get(obj, &mac_addr);
    out += writer(cookie, "  value (of_mac_addr_t):  ");
    out += LOCI_DUMP_mac(writer, cookie, mac_addr);
    out += writer(cookie, "\n");

    of_oxm_ipv6_nd_sll_masked_value_mask_get(obj, &mac_addr);
    out += writer(cookie, "  value_mask (of_mac_addr_t):  ");
    out += LOCI_DUMP_mac(writer, cookie, mac_addr);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_ipv6_nd_target_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_ipv6_nd_target_t *obj)
{
    int out = 0;
    of_ipv6_t ipv6;

    out += writer(cookie, "Object of type of_oxm_ipv6_nd_target\n");

    of_oxm_ipv6_nd_target_value_get(obj, &ipv6);
    out += writer(cookie, "  value (of_ipv6_t):  ");
    out += LOCI_DUMP_ipv6(writer, cookie, ipv6);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_ipv6_nd_target_masked_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_ipv6_nd_target_masked_t *obj)
{
    int out = 0;
    of_ipv6_t ipv6;

    out += writer(cookie, "Object of type of_oxm_ipv6_nd_target_masked\n");

    of_oxm_ipv6_nd_target_masked_value_get(obj, &ipv6);
    out += writer(cookie, "  value (of_ipv6_t):  ");
    out += LOCI_DUMP_ipv6(writer, cookie, ipv6);
    out += writer(cookie, "\n");

    of_oxm_ipv6_nd_target_masked_value_mask_get(obj, &ipv6);
    out += writer(cookie, "  value_mask (of_ipv6_t):  ");
    out += LOCI_DUMP_ipv6(writer, cookie, ipv6);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_ipv6_nd_tll_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_ipv6_nd_tll_t *obj)
{
    int out = 0;
    of_mac_addr_t mac_addr;

    out += writer(cookie, "Object of type of_oxm_ipv6_nd_tll\n");

    of_oxm_ipv6_nd_tll_value_get(obj, &mac_addr);
    out += writer(cookie, "  value (of_mac_addr_t):  ");
    out += LOCI_DUMP_mac(writer, cookie, mac_addr);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_ipv6_nd_tll_masked_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_ipv6_nd_tll_masked_t *obj)
{
    int out = 0;
    of_mac_addr_t mac_addr;

    out += writer(cookie, "Object of type of_oxm_ipv6_nd_tll_masked\n");

    of_oxm_ipv6_nd_tll_masked_value_get(obj, &mac_addr);
    out += writer(cookie, "  value (of_mac_addr_t):  ");
    out += LOCI_DUMP_mac(writer, cookie, mac_addr);
    out += writer(cookie, "\n");

    of_oxm_ipv6_nd_tll_masked_value_mask_get(obj, &mac_addr);
    out += writer(cookie, "  value_mask (of_mac_addr_t):  ");
    out += LOCI_DUMP_mac(writer, cookie, mac_addr);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_ipv6_src_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_ipv6_src_t *obj)
{
    int out = 0;
    of_ipv6_t ipv6;

    out += writer(cookie, "Object of type of_oxm_ipv6_src\n");

    of_oxm_ipv6_src_value_get(obj, &ipv6);
    out += writer(cookie, "  value (of_ipv6_t):  ");
    out += LOCI_DUMP_ipv6(writer, cookie, ipv6);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_ipv6_src_masked_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_ipv6_src_masked_t *obj)
{
    int out = 0;
    of_ipv6_t ipv6;

    out += writer(cookie, "Object of type of_oxm_ipv6_src_masked\n");

    of_oxm_ipv6_src_masked_value_get(obj, &ipv6);
    out += writer(cookie, "  value (of_ipv6_t):  ");
    out += LOCI_DUMP_ipv6(writer, cookie, ipv6);
    out += writer(cookie, "\n");

    of_oxm_ipv6_src_masked_value_mask_get(obj, &ipv6);
    out += writer(cookie, "  value_mask (of_ipv6_t):  ");
    out += LOCI_DUMP_ipv6(writer, cookie, ipv6);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_metadata_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_metadata_t *obj)
{
    int out = 0;
    uint64_t val64;

    out += writer(cookie, "Object of type of_oxm_metadata\n");

    of_oxm_metadata_value_get(obj, &val64);
    out += writer(cookie, "  value (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_metadata_masked_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_metadata_masked_t *obj)
{
    int out = 0;
    uint64_t val64;

    out += writer(cookie, "Object of type of_oxm_metadata_masked\n");

    of_oxm_metadata_masked_value_get(obj, &val64);
    out += writer(cookie, "  value (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_oxm_metadata_masked_value_mask_get(obj, &val64);
    out += writer(cookie, "  value_mask (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_mpls_label_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_mpls_label_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_oxm_mpls_label\n");

    of_oxm_mpls_label_value_get(obj, &val32);
    out += writer(cookie, "  value (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_mpls_label_masked_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_mpls_label_masked_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_oxm_mpls_label_masked\n");

    of_oxm_mpls_label_masked_value_get(obj, &val32);
    out += writer(cookie, "  value (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_oxm_mpls_label_masked_value_mask_get(obj, &val32);
    out += writer(cookie, "  value_mask (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_mpls_tc_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_mpls_tc_t *obj)
{
    int out = 0;
    uint8_t val8;

    out += writer(cookie, "Object of type of_oxm_mpls_tc\n");

    of_oxm_mpls_tc_value_get(obj, &val8);
    out += writer(cookie, "  value (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_mpls_tc_masked_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_mpls_tc_masked_t *obj)
{
    int out = 0;
    uint8_t val8;

    out += writer(cookie, "Object of type of_oxm_mpls_tc_masked\n");

    of_oxm_mpls_tc_masked_value_get(obj, &val8);
    out += writer(cookie, "  value (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_oxm_mpls_tc_masked_value_mask_get(obj, &val8);
    out += writer(cookie, "  value_mask (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_sctp_dst_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_sctp_dst_t *obj)
{
    int out = 0;
    uint16_t val16;

    out += writer(cookie, "Object of type of_oxm_sctp_dst\n");

    of_oxm_sctp_dst_value_get(obj, &val16);
    out += writer(cookie, "  value (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_sctp_dst_masked_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_sctp_dst_masked_t *obj)
{
    int out = 0;
    uint16_t val16;

    out += writer(cookie, "Object of type of_oxm_sctp_dst_masked\n");

    of_oxm_sctp_dst_masked_value_get(obj, &val16);
    out += writer(cookie, "  value (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_oxm_sctp_dst_masked_value_mask_get(obj, &val16);
    out += writer(cookie, "  value_mask (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_sctp_src_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_sctp_src_t *obj)
{
    int out = 0;
    uint16_t val16;

    out += writer(cookie, "Object of type of_oxm_sctp_src\n");

    of_oxm_sctp_src_value_get(obj, &val16);
    out += writer(cookie, "  value (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_sctp_src_masked_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_sctp_src_masked_t *obj)
{
    int out = 0;
    uint16_t val16;

    out += writer(cookie, "Object of type of_oxm_sctp_src_masked\n");

    of_oxm_sctp_src_masked_value_get(obj, &val16);
    out += writer(cookie, "  value (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_oxm_sctp_src_masked_value_mask_get(obj, &val16);
    out += writer(cookie, "  value_mask (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_tcp_dst_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_tcp_dst_t *obj)
{
    int out = 0;
    uint16_t val16;

    out += writer(cookie, "Object of type of_oxm_tcp_dst\n");

    of_oxm_tcp_dst_value_get(obj, &val16);
    out += writer(cookie, "  value (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_tcp_dst_masked_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_tcp_dst_masked_t *obj)
{
    int out = 0;
    uint16_t val16;

    out += writer(cookie, "Object of type of_oxm_tcp_dst_masked\n");

    of_oxm_tcp_dst_masked_value_get(obj, &val16);
    out += writer(cookie, "  value (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_oxm_tcp_dst_masked_value_mask_get(obj, &val16);
    out += writer(cookie, "  value_mask (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_tcp_src_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_tcp_src_t *obj)
{
    int out = 0;
    uint16_t val16;

    out += writer(cookie, "Object of type of_oxm_tcp_src\n");

    of_oxm_tcp_src_value_get(obj, &val16);
    out += writer(cookie, "  value (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_tcp_src_masked_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_tcp_src_masked_t *obj)
{
    int out = 0;
    uint16_t val16;

    out += writer(cookie, "Object of type of_oxm_tcp_src_masked\n");

    of_oxm_tcp_src_masked_value_get(obj, &val16);
    out += writer(cookie, "  value (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_oxm_tcp_src_masked_value_mask_get(obj, &val16);
    out += writer(cookie, "  value_mask (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_udp_dst_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_udp_dst_t *obj)
{
    int out = 0;
    uint16_t val16;

    out += writer(cookie, "Object of type of_oxm_udp_dst\n");

    of_oxm_udp_dst_value_get(obj, &val16);
    out += writer(cookie, "  value (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_udp_dst_masked_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_udp_dst_masked_t *obj)
{
    int out = 0;
    uint16_t val16;

    out += writer(cookie, "Object of type of_oxm_udp_dst_masked\n");

    of_oxm_udp_dst_masked_value_get(obj, &val16);
    out += writer(cookie, "  value (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_oxm_udp_dst_masked_value_mask_get(obj, &val16);
    out += writer(cookie, "  value_mask (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_udp_src_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_udp_src_t *obj)
{
    int out = 0;
    uint16_t val16;

    out += writer(cookie, "Object of type of_oxm_udp_src\n");

    of_oxm_udp_src_value_get(obj, &val16);
    out += writer(cookie, "  value (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_udp_src_masked_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_udp_src_masked_t *obj)
{
    int out = 0;
    uint16_t val16;

    out += writer(cookie, "Object of type of_oxm_udp_src_masked\n");

    of_oxm_udp_src_masked_value_get(obj, &val16);
    out += writer(cookie, "  value (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_oxm_udp_src_masked_value_mask_get(obj, &val16);
    out += writer(cookie, "  value_mask (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_vlan_pcp_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_vlan_pcp_t *obj)
{
    int out = 0;
    uint8_t val8;

    out += writer(cookie, "Object of type of_oxm_vlan_pcp\n");

    of_oxm_vlan_pcp_value_get(obj, &val8);
    out += writer(cookie, "  value (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_vlan_pcp_masked_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_vlan_pcp_masked_t *obj)
{
    int out = 0;
    uint8_t val8;

    out += writer(cookie, "Object of type of_oxm_vlan_pcp_masked\n");

    of_oxm_vlan_pcp_masked_value_get(obj, &val8);
    out += writer(cookie, "  value (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_oxm_vlan_pcp_masked_value_mask_get(obj, &val8);
    out += writer(cookie, "  value_mask (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_vlan_vid_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_vlan_vid_t *obj)
{
    int out = 0;
    uint16_t val16;

    out += writer(cookie, "Object of type of_oxm_vlan_vid\n");

    of_oxm_vlan_vid_value_get(obj, &val16);
    out += writer(cookie, "  value (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_oxm_vlan_vid_masked_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_oxm_vlan_vid_masked_t *obj)
{
    int out = 0;
    uint16_t val16;

    out += writer(cookie, "Object of type of_oxm_vlan_vid_masked\n");

    of_oxm_vlan_vid_masked_value_get(obj, &val16);
    out += writer(cookie, "  value (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    of_oxm_vlan_vid_masked_value_mask_get(obj, &val16);
    out += writer(cookie, "  value_mask (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_packet_queue_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_packet_queue_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_port_no_t port_no;

    of_list_queue_prop_t list;
    of_queue_prop_t elt;
    int rv;

    out += writer(cookie, "Object of type of_packet_queue\n");

    of_packet_queue_queue_id_get(obj, &val32);
    out += writer(cookie, "  queue_id (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_packet_queue_port_get(obj, &port_no);
    out += writer(cookie, "  port (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_queue_prop_t\n");
    of_packet_queue_properties_bind(obj, &list);
    OF_LIST_QUEUE_PROP_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_port_desc_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_port_desc_t *obj)
{
    int out = 0;
    of_port_no_t port_no;
    of_mac_addr_t mac_addr;
    of_port_name_t port_name;
    uint32_t val32;

    out += writer(cookie, "Object of type of_port_desc\n");

    of_port_desc_port_no_get(obj, &port_no);
    out += writer(cookie, "  port_no (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_port_desc_hw_addr_get(obj, &mac_addr);
    out += writer(cookie, "  hw_addr (of_mac_addr_t):  ");
    out += LOCI_DUMP_mac(writer, cookie, mac_addr);
    out += writer(cookie, "\n");

    of_port_desc_name_get(obj, &port_name);
    out += writer(cookie, "  name (of_port_name_t):  ");
    out += LOCI_DUMP_port_name(writer, cookie, port_name);
    out += writer(cookie, "\n");

    of_port_desc_config_get(obj, &val32);
    out += writer(cookie, "  config (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_port_desc_state_get(obj, &val32);
    out += writer(cookie, "  state (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_port_desc_curr_get(obj, &val32);
    out += writer(cookie, "  curr (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_port_desc_advertised_get(obj, &val32);
    out += writer(cookie, "  advertised (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_port_desc_supported_get(obj, &val32);
    out += writer(cookie, "  supported (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_port_desc_peer_get(obj, &val32);
    out += writer(cookie, "  peer (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_port_desc_curr_speed_get(obj, &val32);
    out += writer(cookie, "  curr_speed (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_port_desc_max_speed_get(obj, &val32);
    out += writer(cookie, "  max_speed (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_port_stats_entry_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_port_stats_entry_t *obj)
{
    int out = 0;
    of_port_no_t port_no;
    uint64_t val64;
    uint32_t val32;

    out += writer(cookie, "Object of type of_port_stats_entry\n");

    of_port_stats_entry_port_no_get(obj, &port_no);
    out += writer(cookie, "  port_no (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_port_stats_entry_rx_packets_get(obj, &val64);
    out += writer(cookie, "  rx_packets (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_port_stats_entry_tx_packets_get(obj, &val64);
    out += writer(cookie, "  tx_packets (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_port_stats_entry_rx_bytes_get(obj, &val64);
    out += writer(cookie, "  rx_bytes (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_port_stats_entry_tx_bytes_get(obj, &val64);
    out += writer(cookie, "  tx_bytes (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_port_stats_entry_rx_dropped_get(obj, &val64);
    out += writer(cookie, "  rx_dropped (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_port_stats_entry_tx_dropped_get(obj, &val64);
    out += writer(cookie, "  tx_dropped (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_port_stats_entry_rx_errors_get(obj, &val64);
    out += writer(cookie, "  rx_errors (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_port_stats_entry_tx_errors_get(obj, &val64);
    out += writer(cookie, "  tx_errors (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_port_stats_entry_rx_frame_err_get(obj, &val64);
    out += writer(cookie, "  rx_frame_err (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_port_stats_entry_rx_over_err_get(obj, &val64);
    out += writer(cookie, "  rx_over_err (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_port_stats_entry_rx_crc_err_get(obj, &val64);
    out += writer(cookie, "  rx_crc_err (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_port_stats_entry_collisions_get(obj, &val64);
    out += writer(cookie, "  collisions (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_port_stats_entry_duration_sec_get(obj, &val32);
    out += writer(cookie, "  duration_sec (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_port_stats_entry_duration_nsec_get(obj, &val32);
    out += writer(cookie, "  duration_nsec (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_queue_prop_experimenter_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_queue_prop_experimenter_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_queue_prop_experimenter\n");

    of_queue_prop_experimenter_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_queue_prop_experimenter_data_get(obj, &octets);
    out += writer(cookie, "  data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_queue_prop_header_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_queue_prop_header_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_queue_prop_header\n");

    return out;
}

int
of_queue_prop_max_rate_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_queue_prop_max_rate_t *obj)
{
    int out = 0;
    uint16_t val16;

    out += writer(cookie, "Object of type of_queue_prop_max_rate\n");

    of_queue_prop_max_rate_rate_get(obj, &val16);
    out += writer(cookie, "  rate (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_queue_prop_min_rate_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_queue_prop_min_rate_t *obj)
{
    int out = 0;
    uint16_t val16;

    out += writer(cookie, "Object of type of_queue_prop_min_rate\n");

    of_queue_prop_min_rate_rate_get(obj, &val16);
    out += writer(cookie, "  rate (uint16_t):  ");
    out += LOCI_DUMP_u16(writer, cookie, val16);
    out += writer(cookie, "\n");

    return out;
}

int
of_queue_stats_entry_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_queue_stats_entry_t *obj)
{
    int out = 0;
    of_port_no_t port_no;
    uint32_t val32;
    uint64_t val64;

    out += writer(cookie, "Object of type of_queue_stats_entry\n");

    of_queue_stats_entry_port_no_get(obj, &port_no);
    out += writer(cookie, "  port_no (of_port_no_t):  ");
    out += LOCI_DUMP_port_no(writer, cookie, port_no);
    out += writer(cookie, "\n");

    of_queue_stats_entry_queue_id_get(obj, &val32);
    out += writer(cookie, "  queue_id (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_queue_stats_entry_tx_bytes_get(obj, &val64);
    out += writer(cookie, "  tx_bytes (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_queue_stats_entry_tx_packets_get(obj, &val64);
    out += writer(cookie, "  tx_packets (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_queue_stats_entry_tx_errors_get(obj, &val64);
    out += writer(cookie, "  tx_errors (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_queue_stats_entry_duration_sec_get(obj, &val32);
    out += writer(cookie, "  duration_sec (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_queue_stats_entry_duration_nsec_get(obj, &val32);
    out += writer(cookie, "  duration_nsec (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_table_feature_prop_apply_actions_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_table_feature_prop_apply_actions_t *obj)
{
    int out = 0;

    of_list_action_id_t list;
    of_action_id_t elt;
    int rv;

    out += writer(cookie, "Object of type of_table_feature_prop_apply_actions\n");

    out += writer(cookie, "List of of_action_id_t\n");
    of_table_feature_prop_apply_actions_action_ids_bind(obj, &list);
    OF_LIST_ACTION_ID_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_table_feature_prop_apply_actions_miss_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_table_feature_prop_apply_actions_miss_t *obj)
{
    int out = 0;

    of_list_action_id_t list;
    of_action_id_t elt;
    int rv;

    out += writer(cookie, "Object of type of_table_feature_prop_apply_actions_miss\n");

    out += writer(cookie, "List of of_action_id_t\n");
    of_table_feature_prop_apply_actions_miss_action_ids_bind(obj, &list);
    OF_LIST_ACTION_ID_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_table_feature_prop_apply_setfield_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_table_feature_prop_apply_setfield_t *obj)
{
    int out = 0;

    of_list_uint32_t list;
    of_uint32_t elt;
    int rv;

    out += writer(cookie, "Object of type of_table_feature_prop_apply_setfield\n");

    out += writer(cookie, "List of of_uint32_t\n");
    of_table_feature_prop_apply_setfield_oxm_ids_bind(obj, &list);
    OF_LIST_UINT32_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_table_feature_prop_apply_setfield_miss_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_table_feature_prop_apply_setfield_miss_t *obj)
{
    int out = 0;

    of_list_uint32_t list;
    of_uint32_t elt;
    int rv;

    out += writer(cookie, "Object of type of_table_feature_prop_apply_setfield_miss\n");

    out += writer(cookie, "List of of_uint32_t\n");
    of_table_feature_prop_apply_setfield_miss_oxm_ids_bind(obj, &list);
    OF_LIST_UINT32_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_table_feature_prop_experimenter_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_table_feature_prop_experimenter_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_octets_t octets;

    out += writer(cookie, "Object of type of_table_feature_prop_experimenter\n");

    of_table_feature_prop_experimenter_experimenter_get(obj, &val32);
    out += writer(cookie, "  experimenter (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_table_feature_prop_experimenter_subtype_get(obj, &val32);
    out += writer(cookie, "  subtype (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_table_feature_prop_experimenter_experimenter_data_get(obj, &octets);
    out += writer(cookie, "  experimenter_data (of_octets_t):  ");
    out += LOCI_DUMP_octets(writer, cookie, octets);
    out += writer(cookie, "\n");

    return out;
}

int
of_table_feature_prop_header_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_table_feature_prop_header_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_table_feature_prop_header\n");

    return out;
}

int
of_table_feature_prop_instructions_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_table_feature_prop_instructions_t *obj)
{
    int out = 0;

    of_list_instruction_t list;
    of_instruction_t elt;
    int rv;

    out += writer(cookie, "Object of type of_table_feature_prop_instructions\n");

    out += writer(cookie, "List of of_instruction_t\n");
    of_table_feature_prop_instructions_instruction_ids_bind(obj, &list);
    OF_LIST_INSTRUCTION_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_table_feature_prop_instructions_miss_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_table_feature_prop_instructions_miss_t *obj)
{
    int out = 0;

    of_list_instruction_t list;
    of_instruction_t elt;
    int rv;

    out += writer(cookie, "Object of type of_table_feature_prop_instructions_miss\n");

    out += writer(cookie, "List of of_instruction_t\n");
    of_table_feature_prop_instructions_miss_instruction_ids_bind(obj, &list);
    OF_LIST_INSTRUCTION_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_table_feature_prop_match_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_table_feature_prop_match_t *obj)
{
    int out = 0;

    of_list_uint32_t list;
    of_uint32_t elt;
    int rv;

    out += writer(cookie, "Object of type of_table_feature_prop_match\n");

    out += writer(cookie, "List of of_uint32_t\n");
    of_table_feature_prop_match_oxm_ids_bind(obj, &list);
    OF_LIST_UINT32_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_table_feature_prop_next_tables_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_table_feature_prop_next_tables_t *obj)
{
    int out = 0;

    of_list_uint8_t list;
    of_uint8_t elt;
    int rv;

    out += writer(cookie, "Object of type of_table_feature_prop_next_tables\n");

    out += writer(cookie, "List of of_uint8_t\n");
    of_table_feature_prop_next_tables_next_table_ids_bind(obj, &list);
    OF_LIST_UINT8_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_table_feature_prop_next_tables_miss_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_table_feature_prop_next_tables_miss_t *obj)
{
    int out = 0;

    of_list_uint8_t list;
    of_uint8_t elt;
    int rv;

    out += writer(cookie, "Object of type of_table_feature_prop_next_tables_miss\n");

    out += writer(cookie, "List of of_uint8_t\n");
    of_table_feature_prop_next_tables_miss_next_table_ids_bind(obj, &list);
    OF_LIST_UINT8_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_table_feature_prop_wildcards_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_table_feature_prop_wildcards_t *obj)
{
    int out = 0;

    of_list_uint32_t list;
    of_uint32_t elt;
    int rv;

    out += writer(cookie, "Object of type of_table_feature_prop_wildcards\n");

    out += writer(cookie, "List of of_uint32_t\n");
    of_table_feature_prop_wildcards_oxm_ids_bind(obj, &list);
    OF_LIST_UINT32_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_table_feature_prop_write_actions_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_table_feature_prop_write_actions_t *obj)
{
    int out = 0;

    of_list_action_id_t list;
    of_action_id_t elt;
    int rv;

    out += writer(cookie, "Object of type of_table_feature_prop_write_actions\n");

    out += writer(cookie, "List of of_action_id_t\n");
    of_table_feature_prop_write_actions_action_ids_bind(obj, &list);
    OF_LIST_ACTION_ID_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_table_feature_prop_write_actions_miss_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_table_feature_prop_write_actions_miss_t *obj)
{
    int out = 0;

    of_list_action_id_t list;
    of_action_id_t elt;
    int rv;

    out += writer(cookie, "Object of type of_table_feature_prop_write_actions_miss\n");

    out += writer(cookie, "List of of_action_id_t\n");
    of_table_feature_prop_write_actions_miss_action_ids_bind(obj, &list);
    OF_LIST_ACTION_ID_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_table_feature_prop_write_setfield_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_table_feature_prop_write_setfield_t *obj)
{
    int out = 0;

    of_list_uint32_t list;
    of_uint32_t elt;
    int rv;

    out += writer(cookie, "Object of type of_table_feature_prop_write_setfield\n");

    out += writer(cookie, "List of of_uint32_t\n");
    of_table_feature_prop_write_setfield_oxm_ids_bind(obj, &list);
    OF_LIST_UINT32_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_table_feature_prop_write_setfield_miss_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_table_feature_prop_write_setfield_miss_t *obj)
{
    int out = 0;

    of_list_uint32_t list;
    of_uint32_t elt;
    int rv;

    out += writer(cookie, "Object of type of_table_feature_prop_write_setfield_miss\n");

    out += writer(cookie, "List of of_uint32_t\n");
    of_table_feature_prop_write_setfield_miss_oxm_ids_bind(obj, &list);
    OF_LIST_UINT32_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_table_features_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_table_features_t *obj)
{
    int out = 0;
    uint8_t val8;
    of_table_name_t table_name;
    uint64_t val64;
    uint32_t val32;

    of_list_table_feature_prop_t list;
    of_table_feature_prop_t elt;
    int rv;

    out += writer(cookie, "Object of type of_table_features\n");

    of_table_features_table_id_get(obj, &val8);
    out += writer(cookie, "  table_id (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_table_features_name_get(obj, &table_name);
    out += writer(cookie, "  name (of_table_name_t):  ");
    out += LOCI_DUMP_tab_name(writer, cookie, table_name);
    out += writer(cookie, "\n");

    of_table_features_metadata_match_get(obj, &val64);
    out += writer(cookie, "  metadata_match (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_table_features_metadata_write_get(obj, &val64);
    out += writer(cookie, "  metadata_write (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_table_features_config_get(obj, &val32);
    out += writer(cookie, "  config (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_table_features_max_entries_get(obj, &val32);
    out += writer(cookie, "  max_entries (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    out += writer(cookie, "List of of_table_feature_prop_t\n");
    of_table_features_properties_bind(obj, &list);
    OF_LIST_TABLE_FEATURE_PROP_ITER(&list, &elt, rv) {
        of_object_dump(writer, cookie, (of_object_t *)&elt);
    }

    return out;
}

int
of_table_stats_entry_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_table_stats_entry_t *obj)
{
    int out = 0;
    uint8_t val8;
    uint32_t val32;
    uint64_t val64;

    out += writer(cookie, "Object of type of_table_stats_entry\n");

    of_table_stats_entry_table_id_get(obj, &val8);
    out += writer(cookie, "  table_id (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    of_table_stats_entry_active_count_get(obj, &val32);
    out += writer(cookie, "  active_count (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    of_table_stats_entry_lookup_count_get(obj, &val64);
    out += writer(cookie, "  lookup_count (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    of_table_stats_entry_matched_count_get(obj, &val64);
    out += writer(cookie, "  matched_count (uint64_t):  ");
    out += LOCI_DUMP_u64(writer, cookie, val64);
    out += writer(cookie, "\n");

    return out;
}

int
of_uint32_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_uint32_t *obj)
{
    int out = 0;
    uint32_t val32;

    out += writer(cookie, "Object of type of_uint32\n");

    of_uint32_value_get(obj, &val32);
    out += writer(cookie, "  value (uint32_t):  ");
    out += LOCI_DUMP_u32(writer, cookie, val32);
    out += writer(cookie, "\n");

    return out;
}

int
of_uint8_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_uint8_t *obj)
{
    int out = 0;
    uint8_t val8;

    out += writer(cookie, "Object of type of_uint8\n");

    of_uint8_value_get(obj, &val8);
    out += writer(cookie, "  value (uint8_t):  ");
    out += LOCI_DUMP_u8(writer, cookie, val8);
    out += writer(cookie, "\n");

    return out;
}

int
of_list_action_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_list_action_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_list_action\n");

    return out;
}

int
of_list_action_id_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_list_action_id_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_list_action_id\n");

    return out;
}

int
of_list_bsn_interface_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_list_bsn_interface_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_list_bsn_interface\n");

    return out;
}

int
of_list_bsn_lacp_stats_entry_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_list_bsn_lacp_stats_entry_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_list_bsn_lacp_stats_entry\n");

    return out;
}

int
of_list_bucket_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_list_bucket_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_list_bucket\n");

    return out;
}

int
of_list_bucket_counter_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_list_bucket_counter_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_list_bucket_counter\n");

    return out;
}

int
of_list_flow_stats_entry_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_list_flow_stats_entry_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_list_flow_stats_entry\n");

    return out;
}

int
of_list_group_desc_stats_entry_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_list_group_desc_stats_entry_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_list_group_desc_stats_entry\n");

    return out;
}

int
of_list_group_stats_entry_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_list_group_stats_entry_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_list_group_stats_entry\n");

    return out;
}

int
of_list_hello_elem_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_list_hello_elem_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_list_hello_elem\n");

    return out;
}

int
of_list_instruction_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_list_instruction_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_list_instruction\n");

    return out;
}

int
of_list_meter_band_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_list_meter_band_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_list_meter_band\n");

    return out;
}

int
of_list_meter_band_stats_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_list_meter_band_stats_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_list_meter_band_stats\n");

    return out;
}

int
of_list_meter_stats_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_list_meter_stats_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_list_meter_stats\n");

    return out;
}

int
of_list_oxm_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_list_oxm_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_list_oxm\n");

    return out;
}

int
of_list_packet_queue_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_list_packet_queue_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_list_packet_queue\n");

    return out;
}

int
of_list_port_desc_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_list_port_desc_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_list_port_desc\n");

    return out;
}

int
of_list_port_stats_entry_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_list_port_stats_entry_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_list_port_stats_entry\n");

    return out;
}

int
of_list_queue_prop_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_list_queue_prop_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_list_queue_prop\n");

    return out;
}

int
of_list_queue_stats_entry_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_list_queue_stats_entry_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_list_queue_stats_entry\n");

    return out;
}

int
of_list_table_feature_prop_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_list_table_feature_prop_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_list_table_feature_prop\n");

    return out;
}

int
of_list_table_features_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_list_table_features_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_list_table_features\n");

    return out;
}

int
of_list_table_stats_entry_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_list_table_stats_entry_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_list_table_stats_entry\n");

    return out;
}

int
of_list_uint32_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_list_uint32_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_list_uint32\n");

    return out;
}

int
of_list_uint8_OF_VERSION_1_3_dump(loci_writer_f writer, void* cookie, of_list_uint8_t *obj)
{
    int out = 0;

    out += writer(cookie, "Object of type of_list_uint8\n");

    return out;
}

/**
 * Log a match entry
 */
int
loci_dump_match(loci_writer_f writer, void* cookie, of_match_t *match)
{
    int out = 0;

    out += writer(cookie, "Match obj, version %d.\n", match->version);

    if (OF_MATCH_MASK_IPV6_FLABEL_ACTIVE_TEST(match)) {
        out += writer(cookie, "  ipv6_flabel (uint32_t) active: Value ");
        out += LOCI_DUMP_u32(writer, cookie, match->fields.ipv6_flabel);
        out += writer(cookie, "\n    Mask ");
        out += LOCI_DUMP_u32(writer, cookie, match->masks.ipv6_flabel);
        out += writer(cookie, "\n");
    }

    if (OF_MATCH_MASK_BSN_LAG_ID_ACTIVE_TEST(match)) {
        out += writer(cookie, "  bsn_lag_id (uint32_t) active: Value ");
        out += LOCI_DUMP_u32(writer, cookie, match->fields.bsn_lag_id);
        out += writer(cookie, "\n    Mask ");
        out += LOCI_DUMP_u32(writer, cookie, match->masks.bsn_lag_id);
        out += writer(cookie, "\n");
    }

    if (OF_MATCH_MASK_VLAN_PCP_ACTIVE_TEST(match)) {
        out += writer(cookie, "  vlan_pcp (uint8_t) active: Value ");
        out += LOCI_DUMP_u8(writer, cookie, match->fields.vlan_pcp);
        out += writer(cookie, "\n    Mask ");
        out += LOCI_DUMP_u8(writer, cookie, match->masks.vlan_pcp);
        out += writer(cookie, "\n");
    }

    if (OF_MATCH_MASK_IPV4_SRC_ACTIVE_TEST(match)) {
        out += writer(cookie, "  ipv4_src (of_ipv4_t) active: Value ");
        out += LOCI_DUMP_ipv4(writer, cookie, match->fields.ipv4_src);
        out += writer(cookie, "\n    Mask ");
        out += LOCI_DUMP_ipv4(writer, cookie, match->masks.ipv4_src);
        out += writer(cookie, "\n");
    }

    if (OF_MATCH_MASK_IPV6_DST_ACTIVE_TEST(match)) {
        out += writer(cookie, "  ipv6_dst (of_ipv6_t) active: Value ");
        out += LOCI_DUMP_ipv6(writer, cookie, match->fields.ipv6_dst);
        out += writer(cookie, "\n    Mask ");
        out += LOCI_DUMP_ipv6(writer, cookie, match->masks.ipv6_dst);
        out += writer(cookie, "\n");
    }

    if (OF_MATCH_MASK_ARP_TPA_ACTIVE_TEST(match)) {
        out += writer(cookie, "  arp_tpa (uint32_t) active: Value ");
        out += LOCI_DUMP_u32(writer, cookie, match->fields.arp_tpa);
        out += writer(cookie, "\n    Mask ");
        out += LOCI_DUMP_u32(writer, cookie, match->masks.arp_tpa);
        out += writer(cookie, "\n");
    }

    if (OF_MATCH_MASK_ICMPV6_TYPE_ACTIVE_TEST(match)) {
        out += writer(cookie, "  icmpv6_type (uint8_t) active: Value ");
        out += LOCI_DUMP_u8(writer, cookie, match->fields.icmpv6_type);
        out += writer(cookie, "\n    Mask ");
        out += LOCI_DUMP_u8(writer, cookie, match->masks.icmpv6_type);
        out += writer(cookie, "\n");
    }

    if (OF_MATCH_MASK_BSN_IN_PORTS_128_ACTIVE_TEST(match)) {
        out += writer(cookie, "  bsn_in_ports_128 (of_bitmap_128_t) active: Value ");
        out += LOCI_DUMP_bitmap_128(writer, cookie, match->fields.bsn_in_ports_128);
        out += writer(cookie, "\n    Mask ");
        out += LOCI_DUMP_bitmap_128(writer, cookie, match->masks.bsn_in_ports_128);
        out += writer(cookie, "\n");
    }

    if (OF_MATCH_MASK_ARP_SHA_ACTIVE_TEST(match)) {
        out += writer(cookie, "  arp_sha (of_mac_addr_t) active: Value ");
        out += LOCI_DUMP_mac(writer, cookie, match->fields.arp_sha);
        out += writer(cookie, "\n    Mask ");
        out += LOCI_DUMP_mac(writer, cookie, match->masks.arp_sha);
        out += writer(cookie, "\n");
    }

    if (OF_MATCH_MASK_IPV6_SRC_ACTIVE_TEST(match)) {
        out += writer(cookie, "  ipv6_src (of_ipv6_t) active: Value ");
        out += LOCI_DUMP_ipv6(writer, cookie, match->fields.ipv6_src);
        out += writer(cookie, "\n    Mask ");
        out += LOCI_DUMP_ipv6(writer, cookie, match->masks.ipv6_src);
        out += writer(cookie, "\n");
    }

    if (OF_MATCH_MASK_SCTP_SRC_ACTIVE_TEST(match)) {
        out += writer(cookie, "  sctp_src (uint16_t) active: Value ");
        out += LOCI_DUMP_u16(writer, cookie, match->fields.sctp_src);
        out += writer(cookie, "\n    Mask ");
        out += LOCI_DUMP_u16(writer, cookie, match->masks.sctp_src);
        out += writer(cookie, "\n");
    }

    if (OF_MATCH_MASK_ICMPV6_CODE_ACTIVE_TEST(match)) {
        out += writer(cookie, "  icmpv6_code (uint8_t) active: Value ");
        out += LOCI_DUMP_u8(writer, cookie, match->fields.icmpv6_code);
        out += writer(cookie, "\n    Mask ");
        out += LOCI_DUMP_u8(writer, cookie, match->masks.icmpv6_code);
        out += writer(cookie, "\n");
    }

    if (OF_MATCH_MASK_ETH_DST_ACTIVE_TEST(match)) {
        out += writer(cookie, "  eth_dst (of_mac_addr_t) active: Value ");
        out += LOCI_DUMP_mac(writer, cookie, match->fields.eth_dst);
        out += writer(cookie, "\n    Mask ");
        out += LOCI_DUMP_mac(writer, cookie, match->masks.eth_dst);
        out += writer(cookie, "\n");
    }

    if (OF_MATCH_MASK_IPV6_ND_SLL_ACTIVE_TEST(match)) {
        out += writer(cookie, "  ipv6_nd_sll (of_mac_addr_t) active: Value ");
        out += LOCI_DUMP_mac(writer, cookie, match->fields.ipv6_nd_sll);
        out += writer(cookie, "\n    Mask ");
        out += LOCI_DUMP_mac(writer, cookie, match->masks.ipv6_nd_sll);
        out += writer(cookie, "\n");
    }

    if (OF_MATCH_MASK_MPLS_TC_ACTIVE_TEST(match)) {
        out += writer(cookie, "  mpls_tc (uint8_t) active: Value ");
        out += LOCI_DUMP_u8(writer, cookie, match->fields.mpls_tc);
        out += writer(cookie, "\n    Mask ");
        out += LOCI_DUMP_u8(writer, cookie, match->masks.mpls_tc);
        out += writer(cookie, "\n");
    }

    if (OF_MATCH_MASK_ARP_OP_ACTIVE_TEST(match)) {
        out += writer(cookie, "  arp_op (uint16_t) active: Value ");
        out += LOCI_DUMP_u16(writer, cookie, match->fields.arp_op);
        out += writer(cookie, "\n    Mask ");
        out += LOCI_DUMP_u16(writer, cookie, match->masks.arp_op);
        out += writer(cookie, "\n");
    }

    if (OF_MATCH_MASK_ETH_TYPE_ACTIVE_TEST(match)) {
        out += writer(cookie, "  eth_type (uint16_t) active: Value ");
        out += LOCI_DUMP_u16(writer, cookie, match->fields.eth_type);
        out += writer(cookie, "\n    Mask ");
        out += LOCI_DUMP_u16(writer, cookie, match->masks.eth_type);
        out += writer(cookie, "\n");
    }

    if (OF_MATCH_MASK_IPV6_ND_TARGET_ACTIVE_TEST(match)) {
        out += writer(cookie, "  ipv6_nd_target (of_ipv6_t) active: Value ");
        out += LOCI_DUMP_ipv6(writer, cookie, match->fields.ipv6_nd_target);
        out += writer(cookie, "\n    Mask ");
        out += LOCI_DUMP_ipv6(writer, cookie, match->masks.ipv6_nd_target);
        out += writer(cookie, "\n");
    }

    if (OF_MATCH_MASK_VLAN_VID_ACTIVE_TEST(match)) {
        out += writer(cookie, "  vlan_vid (uint16_t) active: Value ");
        out += LOCI_DUMP_u16(writer, cookie, match->fields.vlan_vid);
        out += writer(cookie, "\n    Mask ");
        out += LOCI_DUMP_u16(writer, cookie, match->masks.vlan_vid);
        out += writer(cookie, "\n");
    }

    if (OF_MATCH_MASK_ARP_THA_ACTIVE_TEST(match)) {
        out += writer(cookie, "  arp_tha (of_mac_addr_t) active: Value ");
        out += LOCI_DUMP_mac(writer, cookie, match->fields.arp_tha);
        out += writer(cookie, "\n    Mask ");
        out += LOCI_DUMP_mac(writer, cookie, match->masks.arp_tha);
        out += writer(cookie, "\n");
    }

    if (OF_MATCH_MASK_IN_PORT_ACTIVE_TEST(match)) {
        out += writer(cookie, "  in_port (of_port_no_t) active: Value ");
        out += LOCI_DUMP_port_no(writer, cookie, match->fields.in_port);
        out += writer(cookie, "\n    Mask ");
        out += LOCI_DUMP_port_no(writer, cookie, match->masks.in_port);
        out += writer(cookie, "\n");
    }

    if (OF_MATCH_MASK_METADATA_ACTIVE_TEST(match)) {
        out += writer(cookie, "  metadata (uint64_t) active: Value ");
        out += LOCI_DUMP_u64(writer, cookie, match->fields.metadata);
        out += writer(cookie, "\n    Mask ");
        out += LOCI_DUMP_u64(writer, cookie, match->masks.metadata);
        out += writer(cookie, "\n");
    }

    if (OF_MATCH_MASK_BSN_L3_SRC_CLASS_ID_ACTIVE_TEST(match)) {
        out += writer(cookie, "  bsn_l3_src_class_id (uint32_t) active: Value ");
        out += LOCI_DUMP_u32(writer, cookie, match->fields.bsn_l3_src_class_id);
        out += writer(cookie, "\n    Mask ");
        out += LOCI_DUMP_u32(writer, cookie, match->masks.bsn_l3_src_class_id);
        out += writer(cookie, "\n");
    }

    if (OF_MATCH_MASK_SCTP_DST_ACTIVE_TEST(match)) {
        out += writer(cookie, "  sctp_dst (uint16_t) active: Value ");
        out += LOCI_DUMP_u16(writer, cookie, match->fields.sctp_dst);
        out += writer(cookie, "\n    Mask ");
        out += LOCI_DUMP_u16(writer, cookie, match->masks.sctp_dst);
        out += writer(cookie, "\n");
    }

    if (OF_MATCH_MASK_ICMPV4_CODE_ACTIVE_TEST(match)) {
        out += writer(cookie, "  icmpv4_code (uint8_t) active: Value ");
        out += LOCI_DUMP_u8(writer, cookie, match->fields.icmpv4_code);
        out += writer(cookie, "\n    Mask ");
        out += LOCI_DUMP_u8(writer, cookie, match->masks.icmpv4_code);
        out += writer(cookie, "\n");
    }

    if (OF_MATCH_MASK_TCP_SRC_ACTIVE_TEST(match)) {
        out += writer(cookie, "  tcp_src (uint16_t) active: Value ");
        out += LOCI_DUMP_u16(writer, cookie, match->fields.tcp_src);
        out += writer(cookie, "\n    Mask ");
        out += LOCI_DUMP_u16(writer, cookie, match->masks.tcp_src);
        out += writer(cookie, "\n");
    }

    if (OF_MATCH_MASK_BSN_VRF_ACTIVE_TEST(match)) {
        out += writer(cookie, "  bsn_vrf (uint32_t) active: Value ");
        out += LOCI_DUMP_u32(writer, cookie, match->fields.bsn_vrf);
        out += writer(cookie, "\n    Mask ");
        out += LOCI_DUMP_u32(writer, cookie, match->masks.bsn_vrf);
        out += writer(cookie, "\n");
    }

    if (OF_MATCH_MASK_IP_ECN_ACTIVE_TEST(match)) {
        out += writer(cookie, "  ip_ecn (uint8_t) active: Value ");
        out += LOCI_DUMP_u8(writer, cookie, match->fields.ip_ecn);
        out += writer(cookie, "\n    Mask ");
        out += LOCI_DUMP_u8(writer, cookie, match->masks.ip_ecn);
        out += writer(cookie, "\n");
    }

    if (OF_MATCH_MASK_BSN_GLOBAL_VRF_ALLOWED_ACTIVE_TEST(match)) {
        out += writer(cookie, "  bsn_global_vrf_allowed (uint8_t) active: Value ");
        out += LOCI_DUMP_u8(writer, cookie, match->fields.bsn_global_vrf_allowed);
        out += writer(cookie, "\n    Mask ");
        out += LOCI_DUMP_u8(writer, cookie, match->masks.bsn_global_vrf_allowed);
        out += writer(cookie, "\n");
    }

    if (OF_MATCH_MASK_UDP_DST_ACTIVE_TEST(match)) {
        out += writer(cookie, "  udp_dst (uint16_t) active: Value ");
        out += LOCI_DUMP_u16(writer, cookie, match->fields.udp_dst);
        out += writer(cookie, "\n    Mask ");
        out += LOCI_DUMP_u16(writer, cookie, match->masks.udp_dst);
        out += writer(cookie, "\n");
    }

    if (OF_MATCH_MASK_ARP_SPA_ACTIVE_TEST(match)) {
        out += writer(cookie, "  arp_spa (uint32_t) active: Value ");
        out += LOCI_DUMP_u32(writer, cookie, match->fields.arp_spa);
        out += writer(cookie, "\n    Mask ");
        out += LOCI_DUMP_u32(writer, cookie, match->masks.arp_spa);
        out += writer(cookie, "\n");
    }

    if (OF_MATCH_MASK_IN_PHY_PORT_ACTIVE_TEST(match)) {
        out += writer(cookie, "  in_phy_port (of_port_no_t) active: Value ");
        out += LOCI_DUMP_port_no(writer, cookie, match->fields.in_phy_port);
        out += writer(cookie, "\n    Mask ");
        out += LOCI_DUMP_port_no(writer, cookie, match->masks.in_phy_port);
        out += writer(cookie, "\n");
    }

    if (OF_MATCH_MASK_IPV4_DST_ACTIVE_TEST(match)) {
        out += writer(cookie, "  ipv4_dst (of_ipv4_t) active: Value ");
        out += LOCI_DUMP_ipv4(writer, cookie, match->fields.ipv4_dst);
        out += writer(cookie, "\n    Mask ");
        out += LOCI_DUMP_ipv4(writer, cookie, match->masks.ipv4_dst);
        out += writer(cookie, "\n");
    }

    if (OF_MATCH_MASK_ETH_SRC_ACTIVE_TEST(match)) {
        out += writer(cookie, "  eth_src (of_mac_addr_t) active: Value ");
        out += LOCI_DUMP_mac(writer, cookie, match->fields.eth_src);
        out += writer(cookie, "\n    Mask ");
        out += LOCI_DUMP_mac(writer, cookie, match->masks.eth_src);
        out += writer(cookie, "\n");
    }

    if (OF_MATCH_MASK_UDP_SRC_ACTIVE_TEST(match)) {
        out += writer(cookie, "  udp_src (uint16_t) active: Value ");
        out += LOCI_DUMP_u16(writer, cookie, match->fields.udp_src);
        out += writer(cookie, "\n    Mask ");
        out += LOCI_DUMP_u16(writer, cookie, match->masks.udp_src);
        out += writer(cookie, "\n");
    }

    if (OF_MATCH_MASK_BSN_L3_DST_CLASS_ID_ACTIVE_TEST(match)) {
        out += writer(cookie, "  bsn_l3_dst_class_id (uint32_t) active: Value ");
        out += LOCI_DUMP_u32(writer, cookie, match->fields.bsn_l3_dst_class_id);
        out += writer(cookie, "\n    Mask ");
        out += LOCI_DUMP_u32(writer, cookie, match->masks.bsn_l3_dst_class_id);
        out += writer(cookie, "\n");
    }

    if (OF_MATCH_MASK_IPV6_ND_TLL_ACTIVE_TEST(match)) {
        out += writer(cookie, "  ipv6_nd_tll (of_mac_addr_t) active: Value ");
        out += LOCI_DUMP_mac(writer, cookie, match->fields.ipv6_nd_tll);
        out += writer(cookie, "\n    Mask ");
        out += LOCI_DUMP_mac(writer, cookie, match->masks.ipv6_nd_tll);
        out += writer(cookie, "\n");
    }

    if (OF_MATCH_MASK_ICMPV4_TYPE_ACTIVE_TEST(match)) {
        out += writer(cookie, "  icmpv4_type (uint8_t) active: Value ");
        out += LOCI_DUMP_u8(writer, cookie, match->fields.icmpv4_type);
        out += writer(cookie, "\n    Mask ");
        out += LOCI_DUMP_u8(writer, cookie, match->masks.icmpv4_type);
        out += writer(cookie, "\n");
    }

    if (OF_MATCH_MASK_MPLS_LABEL_ACTIVE_TEST(match)) {
        out += writer(cookie, "  mpls_label (uint32_t) active: Value ");
        out += LOCI_DUMP_u32(writer, cookie, match->fields.mpls_label);
        out += writer(cookie, "\n    Mask ");
        out += LOCI_DUMP_u32(writer, cookie, match->masks.mpls_label);
        out += writer(cookie, "\n");
    }

    if (OF_MATCH_MASK_TCP_DST_ACTIVE_TEST(match)) {
        out += writer(cookie, "  tcp_dst (uint16_t) active: Value ");
        out += LOCI_DUMP_u16(writer, cookie, match->fields.tcp_dst);
        out += writer(cookie, "\n    Mask ");
        out += LOCI_DUMP_u16(writer, cookie, match->masks.tcp_dst);
        out += writer(cookie, "\n");
    }

    if (OF_MATCH_MASK_IP_PROTO_ACTIVE_TEST(match)) {
        out += writer(cookie, "  ip_proto (uint8_t) active: Value ");
        out += LOCI_DUMP_u8(writer, cookie, match->fields.ip_proto);
        out += writer(cookie, "\n    Mask ");
        out += LOCI_DUMP_u8(writer, cookie, match->masks.ip_proto);
        out += writer(cookie, "\n");
    }

    if (OF_MATCH_MASK_BSN_L3_INTERFACE_CLASS_ID_ACTIVE_TEST(match)) {
        out += writer(cookie, "  bsn_l3_interface_class_id (uint32_t) active: Value ");
        out += LOCI_DUMP_u32(writer, cookie, match->fields.bsn_l3_interface_class_id);
        out += writer(cookie, "\n    Mask ");
        out += LOCI_DUMP_u32(writer, cookie, match->masks.bsn_l3_interface_class_id);
        out += writer(cookie, "\n");
    }

    if (OF_MATCH_MASK_IP_DSCP_ACTIVE_TEST(match)) {
        out += writer(cookie, "  ip_dscp (uint8_t) active: Value ");
        out += LOCI_DUMP_u8(writer, cookie, match->fields.ip_dscp);
        out += writer(cookie, "\n    Mask ");
        out += LOCI_DUMP_u8(writer, cookie, match->masks.ip_dscp);
        out += writer(cookie, "\n");
    }

    return out;
}

static const loci_obj_dump_f dump_funs_v1[OF_OBJECT_COUNT] = {
    unknown_dump, /* of_object, not a valid specific type */
    of_aggregate_stats_reply_OF_VERSION_1_0_dump,
    of_aggregate_stats_request_OF_VERSION_1_0_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    of_bad_action_error_msg_OF_VERSION_1_0_dump,
    unknown_dump,
    unknown_dump,
    of_bad_request_error_msg_OF_VERSION_1_0_dump,
    of_barrier_reply_OF_VERSION_1_0_dump,
    of_barrier_request_OF_VERSION_1_0_dump,
    of_bsn_bw_clear_data_reply_OF_VERSION_1_0_dump,
    of_bsn_bw_clear_data_request_OF_VERSION_1_0_dump,
    of_bsn_bw_enable_get_reply_OF_VERSION_1_0_dump,
    of_bsn_bw_enable_get_request_OF_VERSION_1_0_dump,
    of_bsn_bw_enable_set_reply_OF_VERSION_1_0_dump,
    of_bsn_bw_enable_set_request_OF_VERSION_1_0_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    of_bsn_get_interfaces_reply_OF_VERSION_1_0_dump,
    of_bsn_get_interfaces_request_OF_VERSION_1_0_dump,
    of_bsn_get_ip_mask_reply_OF_VERSION_1_0_dump,
    of_bsn_get_ip_mask_request_OF_VERSION_1_0_dump,
    of_bsn_get_l2_table_reply_OF_VERSION_1_0_dump,
    of_bsn_get_l2_table_request_OF_VERSION_1_0_dump,
    of_bsn_get_mirroring_reply_OF_VERSION_1_0_dump,
    of_bsn_get_mirroring_request_OF_VERSION_1_0_dump,
    of_bsn_header_OF_VERSION_1_0_dump,
    of_bsn_hybrid_get_reply_OF_VERSION_1_0_dump,
    of_bsn_hybrid_get_request_OF_VERSION_1_0_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    of_bsn_pdu_rx_reply_OF_VERSION_1_0_dump,
    of_bsn_pdu_rx_request_OF_VERSION_1_0_dump,
    of_bsn_pdu_rx_timeout_OF_VERSION_1_0_dump,
    of_bsn_pdu_tx_reply_OF_VERSION_1_0_dump,
    of_bsn_pdu_tx_request_OF_VERSION_1_0_dump,
    of_bsn_set_ip_mask_OF_VERSION_1_0_dump,
    of_bsn_set_l2_table_reply_OF_VERSION_1_0_dump,
    of_bsn_set_l2_table_request_OF_VERSION_1_0_dump,
    unknown_dump,
    unknown_dump,
    of_bsn_set_mirroring_OF_VERSION_1_0_dump,
    of_bsn_set_pktin_suppression_reply_OF_VERSION_1_0_dump,
    of_bsn_set_pktin_suppression_request_OF_VERSION_1_0_dump,
    of_bsn_shell_command_OF_VERSION_1_0_dump,
    of_bsn_shell_output_OF_VERSION_1_0_dump,
    of_bsn_shell_status_OF_VERSION_1_0_dump,
    of_bsn_stats_reply_OF_VERSION_1_0_dump,
    of_bsn_stats_request_OF_VERSION_1_0_dump,
    unknown_dump,
    unknown_dump,
    of_bsn_virtual_port_create_reply_OF_VERSION_1_0_dump,
    of_bsn_virtual_port_create_request_OF_VERSION_1_0_dump,
    of_bsn_virtual_port_remove_reply_OF_VERSION_1_0_dump,
    of_bsn_virtual_port_remove_request_OF_VERSION_1_0_dump,
    of_desc_stats_reply_OF_VERSION_1_0_dump,
    of_desc_stats_request_OF_VERSION_1_0_dump,
    of_echo_reply_OF_VERSION_1_0_dump,
    of_echo_request_OF_VERSION_1_0_dump,
    of_error_msg_OF_VERSION_1_0_dump,
    of_experimenter_OF_VERSION_1_0_dump,
    unknown_dump,
    of_experimenter_stats_reply_OF_VERSION_1_0_dump,
    of_experimenter_stats_request_OF_VERSION_1_0_dump,
    of_features_reply_OF_VERSION_1_0_dump,
    of_features_request_OF_VERSION_1_0_dump,
    of_flow_add_OF_VERSION_1_0_dump,
    of_flow_delete_OF_VERSION_1_0_dump,
    of_flow_delete_strict_OF_VERSION_1_0_dump,
    of_flow_mod_OF_VERSION_1_0_dump,
    of_flow_mod_failed_error_msg_OF_VERSION_1_0_dump,
    of_flow_modify_OF_VERSION_1_0_dump,
    of_flow_modify_strict_OF_VERSION_1_0_dump,
    of_flow_removed_OF_VERSION_1_0_dump,
    of_flow_stats_reply_OF_VERSION_1_0_dump,
    of_flow_stats_request_OF_VERSION_1_0_dump,
    of_get_config_reply_OF_VERSION_1_0_dump,
    of_get_config_request_OF_VERSION_1_0_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    of_hello_OF_VERSION_1_0_dump,
    of_hello_failed_error_msg_OF_VERSION_1_0_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    of_nicira_controller_role_reply_OF_VERSION_1_0_dump,
    of_nicira_controller_role_request_OF_VERSION_1_0_dump,
    of_nicira_header_OF_VERSION_1_0_dump,
    of_packet_in_OF_VERSION_1_0_dump,
    of_packet_out_OF_VERSION_1_0_dump,
    unknown_dump,
    unknown_dump,
    of_port_mod_OF_VERSION_1_0_dump,
    of_port_mod_failed_error_msg_OF_VERSION_1_0_dump,
    of_port_stats_reply_OF_VERSION_1_0_dump,
    of_port_stats_request_OF_VERSION_1_0_dump,
    of_port_status_OF_VERSION_1_0_dump,
    of_queue_get_config_reply_OF_VERSION_1_0_dump,
    of_queue_get_config_request_OF_VERSION_1_0_dump,
    of_queue_op_failed_error_msg_OF_VERSION_1_0_dump,
    of_queue_stats_reply_OF_VERSION_1_0_dump,
    of_queue_stats_request_OF_VERSION_1_0_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    of_set_config_OF_VERSION_1_0_dump,
    of_stats_reply_OF_VERSION_1_0_dump,
    of_stats_request_OF_VERSION_1_0_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    of_table_mod_OF_VERSION_1_0_dump,
    unknown_dump,
    of_table_stats_reply_OF_VERSION_1_0_dump,
    of_table_stats_request_OF_VERSION_1_0_dump,
    unknown_dump,
    of_action_bsn_OF_VERSION_1_0_dump,
    of_action_bsn_mirror_OF_VERSION_1_0_dump,
    of_action_bsn_set_tunnel_dst_OF_VERSION_1_0_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    of_action_enqueue_OF_VERSION_1_0_dump,
    of_action_experimenter_OF_VERSION_1_0_dump,
    unknown_dump,
    of_action_header_OF_VERSION_1_0_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    of_action_nicira_OF_VERSION_1_0_dump,
    of_action_nicira_dec_ttl_OF_VERSION_1_0_dump,
    of_action_output_OF_VERSION_1_0_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    of_action_set_dl_dst_OF_VERSION_1_0_dump,
    of_action_set_dl_src_OF_VERSION_1_0_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    of_action_set_nw_dst_OF_VERSION_1_0_dump,
    unknown_dump,
    of_action_set_nw_src_OF_VERSION_1_0_dump,
    of_action_set_nw_tos_OF_VERSION_1_0_dump,
    unknown_dump,
    unknown_dump,
    of_action_set_tp_dst_OF_VERSION_1_0_dump,
    of_action_set_tp_src_OF_VERSION_1_0_dump,
    of_action_set_vlan_pcp_OF_VERSION_1_0_dump,
    of_action_set_vlan_vid_OF_VERSION_1_0_dump,
    of_action_strip_vlan_OF_VERSION_1_0_dump,
    of_bsn_interface_OF_VERSION_1_0_dump,
    unknown_dump,
    unknown_dump,
    of_bsn_vport_header_OF_VERSION_1_0_dump,
    of_bsn_vport_q_in_q_OF_VERSION_1_0_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    of_flow_stats_entry_OF_VERSION_1_0_dump,
    unknown_dump,
    unknown_dump,
    of_header_OF_VERSION_1_0_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    of_match_v1_OF_VERSION_1_0_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    of_packet_queue_OF_VERSION_1_0_dump,
    of_port_desc_OF_VERSION_1_0_dump,
    of_port_stats_entry_OF_VERSION_1_0_dump,
    unknown_dump,
    unknown_dump,
    of_queue_prop_header_OF_VERSION_1_0_dump,
    unknown_dump,
    of_queue_prop_min_rate_OF_VERSION_1_0_dump,
    of_queue_stats_entry_OF_VERSION_1_0_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    of_table_stats_entry_OF_VERSION_1_0_dump,
    unknown_dump,
    unknown_dump,
    of_list_action_OF_VERSION_1_0_dump,
    unknown_dump,
    of_list_bsn_interface_OF_VERSION_1_0_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    of_list_flow_stats_entry_OF_VERSION_1_0_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    of_list_packet_queue_OF_VERSION_1_0_dump,
    of_list_port_desc_OF_VERSION_1_0_dump,
    of_list_port_stats_entry_OF_VERSION_1_0_dump,
    of_list_queue_prop_OF_VERSION_1_0_dump,
    of_list_queue_stats_entry_OF_VERSION_1_0_dump,
    unknown_dump,
    unknown_dump,
    of_list_table_stats_entry_OF_VERSION_1_0_dump,
    unknown_dump,
    unknown_dump
};


static const loci_obj_dump_f dump_funs_v2[OF_OBJECT_COUNT] = {
    unknown_dump, /* of_object, not a valid specific type */
    of_aggregate_stats_reply_OF_VERSION_1_1_dump,
    of_aggregate_stats_request_OF_VERSION_1_1_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    of_bad_action_error_msg_OF_VERSION_1_1_dump,
    of_bad_instruction_error_msg_OF_VERSION_1_1_dump,
    of_bad_match_error_msg_OF_VERSION_1_1_dump,
    of_bad_request_error_msg_OF_VERSION_1_1_dump,
    of_barrier_reply_OF_VERSION_1_1_dump,
    of_barrier_request_OF_VERSION_1_1_dump,
    of_bsn_bw_clear_data_reply_OF_VERSION_1_1_dump,
    of_bsn_bw_clear_data_request_OF_VERSION_1_1_dump,
    of_bsn_bw_enable_get_reply_OF_VERSION_1_1_dump,
    of_bsn_bw_enable_get_request_OF_VERSION_1_1_dump,
    of_bsn_bw_enable_set_reply_OF_VERSION_1_1_dump,
    of_bsn_bw_enable_set_request_OF_VERSION_1_1_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    of_bsn_get_interfaces_reply_OF_VERSION_1_1_dump,
    of_bsn_get_interfaces_request_OF_VERSION_1_1_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    of_bsn_get_mirroring_reply_OF_VERSION_1_1_dump,
    of_bsn_get_mirroring_request_OF_VERSION_1_1_dump,
    of_bsn_header_OF_VERSION_1_1_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    of_bsn_pdu_rx_reply_OF_VERSION_1_1_dump,
    of_bsn_pdu_rx_request_OF_VERSION_1_1_dump,
    of_bsn_pdu_rx_timeout_OF_VERSION_1_1_dump,
    of_bsn_pdu_tx_reply_OF_VERSION_1_1_dump,
    of_bsn_pdu_tx_request_OF_VERSION_1_1_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    of_bsn_set_mirroring_OF_VERSION_1_1_dump,
    of_bsn_set_pktin_suppression_reply_OF_VERSION_1_1_dump,
    of_bsn_set_pktin_suppression_request_OF_VERSION_1_1_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    of_bsn_stats_reply_OF_VERSION_1_1_dump,
    of_bsn_stats_request_OF_VERSION_1_1_dump,
    unknown_dump,
    unknown_dump,
    of_bsn_virtual_port_create_reply_OF_VERSION_1_1_dump,
    of_bsn_virtual_port_create_request_OF_VERSION_1_1_dump,
    of_bsn_virtual_port_remove_reply_OF_VERSION_1_1_dump,
    of_bsn_virtual_port_remove_request_OF_VERSION_1_1_dump,
    of_desc_stats_reply_OF_VERSION_1_1_dump,
    of_desc_stats_request_OF_VERSION_1_1_dump,
    of_echo_reply_OF_VERSION_1_1_dump,
    of_echo_request_OF_VERSION_1_1_dump,
    of_error_msg_OF_VERSION_1_1_dump,
    of_experimenter_OF_VERSION_1_1_dump,
    unknown_dump,
    of_experimenter_stats_reply_OF_VERSION_1_1_dump,
    of_experimenter_stats_request_OF_VERSION_1_1_dump,
    of_features_reply_OF_VERSION_1_1_dump,
    of_features_request_OF_VERSION_1_1_dump,
    of_flow_add_OF_VERSION_1_1_dump,
    of_flow_delete_OF_VERSION_1_1_dump,
    of_flow_delete_strict_OF_VERSION_1_1_dump,
    of_flow_mod_OF_VERSION_1_1_dump,
    of_flow_mod_failed_error_msg_OF_VERSION_1_1_dump,
    of_flow_modify_OF_VERSION_1_1_dump,
    of_flow_modify_strict_OF_VERSION_1_1_dump,
    of_flow_removed_OF_VERSION_1_1_dump,
    of_flow_stats_reply_OF_VERSION_1_1_dump,
    of_flow_stats_request_OF_VERSION_1_1_dump,
    of_get_config_reply_OF_VERSION_1_1_dump,
    of_get_config_request_OF_VERSION_1_1_dump,
    of_group_desc_stats_reply_OF_VERSION_1_1_dump,
    of_group_desc_stats_request_OF_VERSION_1_1_dump,
    unknown_dump,
    unknown_dump,
    of_group_mod_OF_VERSION_1_1_dump,
    of_group_mod_failed_error_msg_OF_VERSION_1_1_dump,
    of_group_stats_reply_OF_VERSION_1_1_dump,
    of_group_stats_request_OF_VERSION_1_1_dump,
    of_hello_OF_VERSION_1_1_dump,
    of_hello_failed_error_msg_OF_VERSION_1_1_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    of_nicira_header_OF_VERSION_1_1_dump,
    of_packet_in_OF_VERSION_1_1_dump,
    of_packet_out_OF_VERSION_1_1_dump,
    unknown_dump,
    unknown_dump,
    of_port_mod_OF_VERSION_1_1_dump,
    of_port_mod_failed_error_msg_OF_VERSION_1_1_dump,
    of_port_stats_reply_OF_VERSION_1_1_dump,
    of_port_stats_request_OF_VERSION_1_1_dump,
    of_port_status_OF_VERSION_1_1_dump,
    of_queue_get_config_reply_OF_VERSION_1_1_dump,
    of_queue_get_config_request_OF_VERSION_1_1_dump,
    of_queue_op_failed_error_msg_OF_VERSION_1_1_dump,
    of_queue_stats_reply_OF_VERSION_1_1_dump,
    of_queue_stats_request_OF_VERSION_1_1_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    of_set_config_OF_VERSION_1_1_dump,
    of_stats_reply_OF_VERSION_1_1_dump,
    of_stats_request_OF_VERSION_1_1_dump,
    of_switch_config_failed_error_msg_OF_VERSION_1_1_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    of_table_mod_OF_VERSION_1_1_dump,
    of_table_mod_failed_error_msg_OF_VERSION_1_1_dump,
    of_table_stats_reply_OF_VERSION_1_1_dump,
    of_table_stats_request_OF_VERSION_1_1_dump,
    unknown_dump,
    of_action_bsn_OF_VERSION_1_1_dump,
    of_action_bsn_mirror_OF_VERSION_1_1_dump,
    of_action_bsn_set_tunnel_dst_OF_VERSION_1_1_dump,
    of_action_copy_ttl_in_OF_VERSION_1_1_dump,
    of_action_copy_ttl_out_OF_VERSION_1_1_dump,
    of_action_dec_mpls_ttl_OF_VERSION_1_1_dump,
    of_action_dec_nw_ttl_OF_VERSION_1_1_dump,
    unknown_dump,
    of_action_experimenter_OF_VERSION_1_1_dump,
    of_action_group_OF_VERSION_1_1_dump,
    of_action_header_OF_VERSION_1_1_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    of_action_nicira_OF_VERSION_1_1_dump,
    of_action_nicira_dec_ttl_OF_VERSION_1_1_dump,
    of_action_output_OF_VERSION_1_1_dump,
    of_action_pop_mpls_OF_VERSION_1_1_dump,
    unknown_dump,
    of_action_pop_vlan_OF_VERSION_1_1_dump,
    of_action_push_mpls_OF_VERSION_1_1_dump,
    unknown_dump,
    of_action_push_vlan_OF_VERSION_1_1_dump,
    of_action_set_dl_dst_OF_VERSION_1_1_dump,
    of_action_set_dl_src_OF_VERSION_1_1_dump,
    unknown_dump,
    of_action_set_mpls_label_OF_VERSION_1_1_dump,
    of_action_set_mpls_tc_OF_VERSION_1_1_dump,
    of_action_set_mpls_ttl_OF_VERSION_1_1_dump,
    of_action_set_nw_dst_OF_VERSION_1_1_dump,
    of_action_set_nw_ecn_OF_VERSION_1_1_dump,
    of_action_set_nw_src_OF_VERSION_1_1_dump,
    of_action_set_nw_tos_OF_VERSION_1_1_dump,
    of_action_set_nw_ttl_OF_VERSION_1_1_dump,
    of_action_set_queue_OF_VERSION_1_1_dump,
    of_action_set_tp_dst_OF_VERSION_1_1_dump,
    of_action_set_tp_src_OF_VERSION_1_1_dump,
    of_action_set_vlan_pcp_OF_VERSION_1_1_dump,
    of_action_set_vlan_vid_OF_VERSION_1_1_dump,
    unknown_dump,
    of_bsn_interface_OF_VERSION_1_1_dump,
    unknown_dump,
    unknown_dump,
    of_bsn_vport_header_OF_VERSION_1_1_dump,
    of_bsn_vport_q_in_q_OF_VERSION_1_1_dump,
    of_bucket_OF_VERSION_1_1_dump,
    of_bucket_counter_OF_VERSION_1_1_dump,
    unknown_dump,
    of_flow_stats_entry_OF_VERSION_1_1_dump,
    of_group_desc_stats_entry_OF_VERSION_1_1_dump,
    of_group_stats_entry_OF_VERSION_1_1_dump,
    of_header_OF_VERSION_1_1_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    of_instruction_apply_actions_OF_VERSION_1_1_dump,
    of_instruction_clear_actions_OF_VERSION_1_1_dump,
    of_instruction_experimenter_OF_VERSION_1_1_dump,
    of_instruction_goto_table_OF_VERSION_1_1_dump,
    of_instruction_header_OF_VERSION_1_1_dump,
    unknown_dump,
    of_instruction_write_actions_OF_VERSION_1_1_dump,
    of_instruction_write_metadata_OF_VERSION_1_1_dump,
    unknown_dump,
    of_match_v2_OF_VERSION_1_1_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    of_packet_queue_OF_VERSION_1_1_dump,
    of_port_desc_OF_VERSION_1_1_dump,
    of_port_stats_entry_OF_VERSION_1_1_dump,
    unknown_dump,
    unknown_dump,
    of_queue_prop_header_OF_VERSION_1_1_dump,
    unknown_dump,
    of_queue_prop_min_rate_OF_VERSION_1_1_dump,
    of_queue_stats_entry_OF_VERSION_1_1_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    of_table_stats_entry_OF_VERSION_1_1_dump,
    unknown_dump,
    unknown_dump,
    of_list_action_OF_VERSION_1_1_dump,
    unknown_dump,
    of_list_bsn_interface_OF_VERSION_1_1_dump,
    unknown_dump,
    of_list_bucket_OF_VERSION_1_1_dump,
    of_list_bucket_counter_OF_VERSION_1_1_dump,
    of_list_flow_stats_entry_OF_VERSION_1_1_dump,
    of_list_group_desc_stats_entry_OF_VERSION_1_1_dump,
    of_list_group_stats_entry_OF_VERSION_1_1_dump,
    unknown_dump,
    of_list_instruction_OF_VERSION_1_1_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    of_list_packet_queue_OF_VERSION_1_1_dump,
    of_list_port_desc_OF_VERSION_1_1_dump,
    of_list_port_stats_entry_OF_VERSION_1_1_dump,
    of_list_queue_prop_OF_VERSION_1_1_dump,
    of_list_queue_stats_entry_OF_VERSION_1_1_dump,
    unknown_dump,
    unknown_dump,
    of_list_table_stats_entry_OF_VERSION_1_1_dump,
    unknown_dump,
    unknown_dump
};


static const loci_obj_dump_f dump_funs_v3[OF_OBJECT_COUNT] = {
    unknown_dump, /* of_object, not a valid specific type */
    of_aggregate_stats_reply_OF_VERSION_1_2_dump,
    of_aggregate_stats_request_OF_VERSION_1_2_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    of_bad_action_error_msg_OF_VERSION_1_2_dump,
    of_bad_instruction_error_msg_OF_VERSION_1_2_dump,
    of_bad_match_error_msg_OF_VERSION_1_2_dump,
    of_bad_request_error_msg_OF_VERSION_1_2_dump,
    of_barrier_reply_OF_VERSION_1_2_dump,
    of_barrier_request_OF_VERSION_1_2_dump,
    of_bsn_bw_clear_data_reply_OF_VERSION_1_2_dump,
    of_bsn_bw_clear_data_request_OF_VERSION_1_2_dump,
    of_bsn_bw_enable_get_reply_OF_VERSION_1_2_dump,
    of_bsn_bw_enable_get_request_OF_VERSION_1_2_dump,
    of_bsn_bw_enable_set_reply_OF_VERSION_1_2_dump,
    of_bsn_bw_enable_set_request_OF_VERSION_1_2_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    of_bsn_get_interfaces_reply_OF_VERSION_1_2_dump,
    of_bsn_get_interfaces_request_OF_VERSION_1_2_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    of_bsn_get_mirroring_reply_OF_VERSION_1_2_dump,
    of_bsn_get_mirroring_request_OF_VERSION_1_2_dump,
    of_bsn_header_OF_VERSION_1_2_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    of_bsn_pdu_rx_reply_OF_VERSION_1_2_dump,
    of_bsn_pdu_rx_request_OF_VERSION_1_2_dump,
    of_bsn_pdu_rx_timeout_OF_VERSION_1_2_dump,
    of_bsn_pdu_tx_reply_OF_VERSION_1_2_dump,
    of_bsn_pdu_tx_request_OF_VERSION_1_2_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    of_bsn_set_mirroring_OF_VERSION_1_2_dump,
    of_bsn_set_pktin_suppression_reply_OF_VERSION_1_2_dump,
    of_bsn_set_pktin_suppression_request_OF_VERSION_1_2_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    of_bsn_stats_reply_OF_VERSION_1_2_dump,
    of_bsn_stats_request_OF_VERSION_1_2_dump,
    unknown_dump,
    unknown_dump,
    of_bsn_virtual_port_create_reply_OF_VERSION_1_2_dump,
    of_bsn_virtual_port_create_request_OF_VERSION_1_2_dump,
    of_bsn_virtual_port_remove_reply_OF_VERSION_1_2_dump,
    of_bsn_virtual_port_remove_request_OF_VERSION_1_2_dump,
    of_desc_stats_reply_OF_VERSION_1_2_dump,
    of_desc_stats_request_OF_VERSION_1_2_dump,
    of_echo_reply_OF_VERSION_1_2_dump,
    of_echo_request_OF_VERSION_1_2_dump,
    of_error_msg_OF_VERSION_1_2_dump,
    of_experimenter_OF_VERSION_1_2_dump,
    of_experimenter_error_msg_OF_VERSION_1_2_dump,
    of_experimenter_stats_reply_OF_VERSION_1_2_dump,
    of_experimenter_stats_request_OF_VERSION_1_2_dump,
    of_features_reply_OF_VERSION_1_2_dump,
    of_features_request_OF_VERSION_1_2_dump,
    of_flow_add_OF_VERSION_1_2_dump,
    of_flow_delete_OF_VERSION_1_2_dump,
    of_flow_delete_strict_OF_VERSION_1_2_dump,
    of_flow_mod_OF_VERSION_1_2_dump,
    of_flow_mod_failed_error_msg_OF_VERSION_1_2_dump,
    of_flow_modify_OF_VERSION_1_2_dump,
    of_flow_modify_strict_OF_VERSION_1_2_dump,
    of_flow_removed_OF_VERSION_1_2_dump,
    of_flow_stats_reply_OF_VERSION_1_2_dump,
    of_flow_stats_request_OF_VERSION_1_2_dump,
    of_get_config_reply_OF_VERSION_1_2_dump,
    of_get_config_request_OF_VERSION_1_2_dump,
    of_group_desc_stats_reply_OF_VERSION_1_2_dump,
    of_group_desc_stats_request_OF_VERSION_1_2_dump,
    of_group_features_stats_reply_OF_VERSION_1_2_dump,
    of_group_features_stats_request_OF_VERSION_1_2_dump,
    of_group_mod_OF_VERSION_1_2_dump,
    of_group_mod_failed_error_msg_OF_VERSION_1_2_dump,
    of_group_stats_reply_OF_VERSION_1_2_dump,
    of_group_stats_request_OF_VERSION_1_2_dump,
    of_hello_OF_VERSION_1_2_dump,
    of_hello_failed_error_msg_OF_VERSION_1_2_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    of_nicira_header_OF_VERSION_1_2_dump,
    of_packet_in_OF_VERSION_1_2_dump,
    of_packet_out_OF_VERSION_1_2_dump,
    unknown_dump,
    unknown_dump,
    of_port_mod_OF_VERSION_1_2_dump,
    of_port_mod_failed_error_msg_OF_VERSION_1_2_dump,
    of_port_stats_reply_OF_VERSION_1_2_dump,
    of_port_stats_request_OF_VERSION_1_2_dump,
    of_port_status_OF_VERSION_1_2_dump,
    of_queue_get_config_reply_OF_VERSION_1_2_dump,
    of_queue_get_config_request_OF_VERSION_1_2_dump,
    of_queue_op_failed_error_msg_OF_VERSION_1_2_dump,
    of_queue_stats_reply_OF_VERSION_1_2_dump,
    of_queue_stats_request_OF_VERSION_1_2_dump,
    of_role_reply_OF_VERSION_1_2_dump,
    of_role_request_OF_VERSION_1_2_dump,
    of_role_request_failed_error_msg_OF_VERSION_1_2_dump,
    of_set_config_OF_VERSION_1_2_dump,
    of_stats_reply_OF_VERSION_1_2_dump,
    of_stats_request_OF_VERSION_1_2_dump,
    of_switch_config_failed_error_msg_OF_VERSION_1_2_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    of_table_mod_OF_VERSION_1_2_dump,
    of_table_mod_failed_error_msg_OF_VERSION_1_2_dump,
    of_table_stats_reply_OF_VERSION_1_2_dump,
    of_table_stats_request_OF_VERSION_1_2_dump,
    unknown_dump,
    of_action_bsn_OF_VERSION_1_2_dump,
    of_action_bsn_mirror_OF_VERSION_1_2_dump,
    of_action_bsn_set_tunnel_dst_OF_VERSION_1_2_dump,
    of_action_copy_ttl_in_OF_VERSION_1_2_dump,
    of_action_copy_ttl_out_OF_VERSION_1_2_dump,
    of_action_dec_mpls_ttl_OF_VERSION_1_2_dump,
    of_action_dec_nw_ttl_OF_VERSION_1_2_dump,
    unknown_dump,
    of_action_experimenter_OF_VERSION_1_2_dump,
    of_action_group_OF_VERSION_1_2_dump,
    of_action_header_OF_VERSION_1_2_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    of_action_nicira_OF_VERSION_1_2_dump,
    of_action_nicira_dec_ttl_OF_VERSION_1_2_dump,
    of_action_output_OF_VERSION_1_2_dump,
    of_action_pop_mpls_OF_VERSION_1_2_dump,
    unknown_dump,
    of_action_pop_vlan_OF_VERSION_1_2_dump,
    of_action_push_mpls_OF_VERSION_1_2_dump,
    unknown_dump,
    of_action_push_vlan_OF_VERSION_1_2_dump,
    unknown_dump,
    unknown_dump,
    of_action_set_field_OF_VERSION_1_2_dump,
    unknown_dump,
    unknown_dump,
    of_action_set_mpls_ttl_OF_VERSION_1_2_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    of_action_set_nw_ttl_OF_VERSION_1_2_dump,
    of_action_set_queue_OF_VERSION_1_2_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    of_bsn_interface_OF_VERSION_1_2_dump,
    unknown_dump,
    unknown_dump,
    of_bsn_vport_header_OF_VERSION_1_2_dump,
    of_bsn_vport_q_in_q_OF_VERSION_1_2_dump,
    of_bucket_OF_VERSION_1_2_dump,
    of_bucket_counter_OF_VERSION_1_2_dump,
    unknown_dump,
    of_flow_stats_entry_OF_VERSION_1_2_dump,
    of_group_desc_stats_entry_OF_VERSION_1_2_dump,
    of_group_stats_entry_OF_VERSION_1_2_dump,
    of_header_OF_VERSION_1_2_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    of_instruction_apply_actions_OF_VERSION_1_2_dump,
    of_instruction_clear_actions_OF_VERSION_1_2_dump,
    of_instruction_experimenter_OF_VERSION_1_2_dump,
    of_instruction_goto_table_OF_VERSION_1_2_dump,
    of_instruction_header_OF_VERSION_1_2_dump,
    unknown_dump,
    of_instruction_write_actions_OF_VERSION_1_2_dump,
    of_instruction_write_metadata_OF_VERSION_1_2_dump,
    unknown_dump,
    unknown_dump,
    of_match_v3_OF_VERSION_1_2_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    of_oxm_arp_op_OF_VERSION_1_2_dump,
    of_oxm_arp_op_masked_OF_VERSION_1_2_dump,
    of_oxm_arp_sha_OF_VERSION_1_2_dump,
    of_oxm_arp_sha_masked_OF_VERSION_1_2_dump,
    of_oxm_arp_spa_OF_VERSION_1_2_dump,
    of_oxm_arp_spa_masked_OF_VERSION_1_2_dump,
    of_oxm_arp_tha_OF_VERSION_1_2_dump,
    of_oxm_arp_tha_masked_OF_VERSION_1_2_dump,
    of_oxm_arp_tpa_OF_VERSION_1_2_dump,
    of_oxm_arp_tpa_masked_OF_VERSION_1_2_dump,
    of_oxm_bsn_global_vrf_allowed_OF_VERSION_1_2_dump,
    of_oxm_bsn_global_vrf_allowed_masked_OF_VERSION_1_2_dump,
    of_oxm_bsn_in_ports_128_OF_VERSION_1_2_dump,
    of_oxm_bsn_in_ports_128_masked_OF_VERSION_1_2_dump,
    of_oxm_bsn_l3_dst_class_id_OF_VERSION_1_2_dump,
    of_oxm_bsn_l3_dst_class_id_masked_OF_VERSION_1_2_dump,
    of_oxm_bsn_l3_interface_class_id_OF_VERSION_1_2_dump,
    of_oxm_bsn_l3_interface_class_id_masked_OF_VERSION_1_2_dump,
    of_oxm_bsn_l3_src_class_id_OF_VERSION_1_2_dump,
    of_oxm_bsn_l3_src_class_id_masked_OF_VERSION_1_2_dump,
    of_oxm_bsn_lag_id_OF_VERSION_1_2_dump,
    of_oxm_bsn_lag_id_masked_OF_VERSION_1_2_dump,
    of_oxm_bsn_vrf_OF_VERSION_1_2_dump,
    of_oxm_bsn_vrf_masked_OF_VERSION_1_2_dump,
    of_oxm_eth_dst_OF_VERSION_1_2_dump,
    of_oxm_eth_dst_masked_OF_VERSION_1_2_dump,
    of_oxm_eth_src_OF_VERSION_1_2_dump,
    of_oxm_eth_src_masked_OF_VERSION_1_2_dump,
    of_oxm_eth_type_OF_VERSION_1_2_dump,
    of_oxm_eth_type_masked_OF_VERSION_1_2_dump,
    of_oxm_header_OF_VERSION_1_2_dump,
    of_oxm_icmpv4_code_OF_VERSION_1_2_dump,
    of_oxm_icmpv4_code_masked_OF_VERSION_1_2_dump,
    of_oxm_icmpv4_type_OF_VERSION_1_2_dump,
    of_oxm_icmpv4_type_masked_OF_VERSION_1_2_dump,
    of_oxm_icmpv6_code_OF_VERSION_1_2_dump,
    of_oxm_icmpv6_code_masked_OF_VERSION_1_2_dump,
    of_oxm_icmpv6_type_OF_VERSION_1_2_dump,
    of_oxm_icmpv6_type_masked_OF_VERSION_1_2_dump,
    of_oxm_in_phy_port_OF_VERSION_1_2_dump,
    of_oxm_in_phy_port_masked_OF_VERSION_1_2_dump,
    of_oxm_in_port_OF_VERSION_1_2_dump,
    of_oxm_in_port_masked_OF_VERSION_1_2_dump,
    of_oxm_ip_dscp_OF_VERSION_1_2_dump,
    of_oxm_ip_dscp_masked_OF_VERSION_1_2_dump,
    of_oxm_ip_ecn_OF_VERSION_1_2_dump,
    of_oxm_ip_ecn_masked_OF_VERSION_1_2_dump,
    of_oxm_ip_proto_OF_VERSION_1_2_dump,
    of_oxm_ip_proto_masked_OF_VERSION_1_2_dump,
    of_oxm_ipv4_dst_OF_VERSION_1_2_dump,
    of_oxm_ipv4_dst_masked_OF_VERSION_1_2_dump,
    of_oxm_ipv4_src_OF_VERSION_1_2_dump,
    of_oxm_ipv4_src_masked_OF_VERSION_1_2_dump,
    of_oxm_ipv6_dst_OF_VERSION_1_2_dump,
    of_oxm_ipv6_dst_masked_OF_VERSION_1_2_dump,
    of_oxm_ipv6_flabel_OF_VERSION_1_2_dump,
    of_oxm_ipv6_flabel_masked_OF_VERSION_1_2_dump,
    of_oxm_ipv6_nd_sll_OF_VERSION_1_2_dump,
    of_oxm_ipv6_nd_sll_masked_OF_VERSION_1_2_dump,
    of_oxm_ipv6_nd_target_OF_VERSION_1_2_dump,
    of_oxm_ipv6_nd_target_masked_OF_VERSION_1_2_dump,
    of_oxm_ipv6_nd_tll_OF_VERSION_1_2_dump,
    of_oxm_ipv6_nd_tll_masked_OF_VERSION_1_2_dump,
    of_oxm_ipv6_src_OF_VERSION_1_2_dump,
    of_oxm_ipv6_src_masked_OF_VERSION_1_2_dump,
    of_oxm_metadata_OF_VERSION_1_2_dump,
    of_oxm_metadata_masked_OF_VERSION_1_2_dump,
    of_oxm_mpls_label_OF_VERSION_1_2_dump,
    of_oxm_mpls_label_masked_OF_VERSION_1_2_dump,
    of_oxm_mpls_tc_OF_VERSION_1_2_dump,
    of_oxm_mpls_tc_masked_OF_VERSION_1_2_dump,
    of_oxm_sctp_dst_OF_VERSION_1_2_dump,
    of_oxm_sctp_dst_masked_OF_VERSION_1_2_dump,
    of_oxm_sctp_src_OF_VERSION_1_2_dump,
    of_oxm_sctp_src_masked_OF_VERSION_1_2_dump,
    of_oxm_tcp_dst_OF_VERSION_1_2_dump,
    of_oxm_tcp_dst_masked_OF_VERSION_1_2_dump,
    of_oxm_tcp_src_OF_VERSION_1_2_dump,
    of_oxm_tcp_src_masked_OF_VERSION_1_2_dump,
    of_oxm_udp_dst_OF_VERSION_1_2_dump,
    of_oxm_udp_dst_masked_OF_VERSION_1_2_dump,
    of_oxm_udp_src_OF_VERSION_1_2_dump,
    of_oxm_udp_src_masked_OF_VERSION_1_2_dump,
    of_oxm_vlan_pcp_OF_VERSION_1_2_dump,
    of_oxm_vlan_pcp_masked_OF_VERSION_1_2_dump,
    of_oxm_vlan_vid_OF_VERSION_1_2_dump,
    of_oxm_vlan_vid_masked_OF_VERSION_1_2_dump,
    of_packet_queue_OF_VERSION_1_2_dump,
    of_port_desc_OF_VERSION_1_2_dump,
    of_port_stats_entry_OF_VERSION_1_2_dump,
    unknown_dump,
    of_queue_prop_experimenter_OF_VERSION_1_2_dump,
    of_queue_prop_header_OF_VERSION_1_2_dump,
    of_queue_prop_max_rate_OF_VERSION_1_2_dump,
    of_queue_prop_min_rate_OF_VERSION_1_2_dump,
    of_queue_stats_entry_OF_VERSION_1_2_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    of_table_stats_entry_OF_VERSION_1_2_dump,
    unknown_dump,
    unknown_dump,
    of_list_action_OF_VERSION_1_2_dump,
    unknown_dump,
    of_list_bsn_interface_OF_VERSION_1_2_dump,
    unknown_dump,
    of_list_bucket_OF_VERSION_1_2_dump,
    of_list_bucket_counter_OF_VERSION_1_2_dump,
    of_list_flow_stats_entry_OF_VERSION_1_2_dump,
    of_list_group_desc_stats_entry_OF_VERSION_1_2_dump,
    of_list_group_stats_entry_OF_VERSION_1_2_dump,
    unknown_dump,
    of_list_instruction_OF_VERSION_1_2_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    of_list_oxm_OF_VERSION_1_2_dump,
    of_list_packet_queue_OF_VERSION_1_2_dump,
    of_list_port_desc_OF_VERSION_1_2_dump,
    of_list_port_stats_entry_OF_VERSION_1_2_dump,
    of_list_queue_prop_OF_VERSION_1_2_dump,
    of_list_queue_stats_entry_OF_VERSION_1_2_dump,
    unknown_dump,
    unknown_dump,
    of_list_table_stats_entry_OF_VERSION_1_2_dump,
    unknown_dump,
    unknown_dump
};


static const loci_obj_dump_f dump_funs_v4[OF_OBJECT_COUNT] = {
    unknown_dump, /* of_object, not a valid specific type */
    of_aggregate_stats_reply_OF_VERSION_1_3_dump,
    of_aggregate_stats_request_OF_VERSION_1_3_dump,
    of_async_get_reply_OF_VERSION_1_3_dump,
    of_async_get_request_OF_VERSION_1_3_dump,
    of_async_set_OF_VERSION_1_3_dump,
    of_bad_action_error_msg_OF_VERSION_1_3_dump,
    of_bad_instruction_error_msg_OF_VERSION_1_3_dump,
    of_bad_match_error_msg_OF_VERSION_1_3_dump,
    of_bad_request_error_msg_OF_VERSION_1_3_dump,
    of_barrier_reply_OF_VERSION_1_3_dump,
    of_barrier_request_OF_VERSION_1_3_dump,
    of_bsn_bw_clear_data_reply_OF_VERSION_1_3_dump,
    of_bsn_bw_clear_data_request_OF_VERSION_1_3_dump,
    of_bsn_bw_enable_get_reply_OF_VERSION_1_3_dump,
    of_bsn_bw_enable_get_request_OF_VERSION_1_3_dump,
    of_bsn_bw_enable_set_reply_OF_VERSION_1_3_dump,
    of_bsn_bw_enable_set_request_OF_VERSION_1_3_dump,
    of_bsn_flow_idle_OF_VERSION_1_3_dump,
    of_bsn_flow_idle_enable_get_reply_OF_VERSION_1_3_dump,
    of_bsn_flow_idle_enable_get_request_OF_VERSION_1_3_dump,
    of_bsn_flow_idle_enable_set_reply_OF_VERSION_1_3_dump,
    of_bsn_flow_idle_enable_set_request_OF_VERSION_1_3_dump,
    of_bsn_get_interfaces_reply_OF_VERSION_1_3_dump,
    of_bsn_get_interfaces_request_OF_VERSION_1_3_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    of_bsn_get_mirroring_reply_OF_VERSION_1_3_dump,
    of_bsn_get_mirroring_request_OF_VERSION_1_3_dump,
    of_bsn_header_OF_VERSION_1_3_dump,
    unknown_dump,
    unknown_dump,
    of_bsn_lacp_convergence_notif_OF_VERSION_1_3_dump,
    of_bsn_lacp_stats_reply_OF_VERSION_1_3_dump,
    of_bsn_lacp_stats_request_OF_VERSION_1_3_dump,
    of_bsn_pdu_rx_reply_OF_VERSION_1_3_dump,
    of_bsn_pdu_rx_request_OF_VERSION_1_3_dump,
    of_bsn_pdu_rx_timeout_OF_VERSION_1_3_dump,
    of_bsn_pdu_tx_reply_OF_VERSION_1_3_dump,
    of_bsn_pdu_tx_request_OF_VERSION_1_3_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    of_bsn_set_lacp_reply_OF_VERSION_1_3_dump,
    of_bsn_set_lacp_request_OF_VERSION_1_3_dump,
    of_bsn_set_mirroring_OF_VERSION_1_3_dump,
    of_bsn_set_pktin_suppression_reply_OF_VERSION_1_3_dump,
    of_bsn_set_pktin_suppression_request_OF_VERSION_1_3_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    of_bsn_stats_reply_OF_VERSION_1_3_dump,
    of_bsn_stats_request_OF_VERSION_1_3_dump,
    of_bsn_time_reply_OF_VERSION_1_3_dump,
    of_bsn_time_request_OF_VERSION_1_3_dump,
    of_bsn_virtual_port_create_reply_OF_VERSION_1_3_dump,
    of_bsn_virtual_port_create_request_OF_VERSION_1_3_dump,
    of_bsn_virtual_port_remove_reply_OF_VERSION_1_3_dump,
    of_bsn_virtual_port_remove_request_OF_VERSION_1_3_dump,
    of_desc_stats_reply_OF_VERSION_1_3_dump,
    of_desc_stats_request_OF_VERSION_1_3_dump,
    of_echo_reply_OF_VERSION_1_3_dump,
    of_echo_request_OF_VERSION_1_3_dump,
    of_error_msg_OF_VERSION_1_3_dump,
    of_experimenter_OF_VERSION_1_3_dump,
    of_experimenter_error_msg_OF_VERSION_1_3_dump,
    of_experimenter_stats_reply_OF_VERSION_1_3_dump,
    of_experimenter_stats_request_OF_VERSION_1_3_dump,
    of_features_reply_OF_VERSION_1_3_dump,
    of_features_request_OF_VERSION_1_3_dump,
    of_flow_add_OF_VERSION_1_3_dump,
    of_flow_delete_OF_VERSION_1_3_dump,
    of_flow_delete_strict_OF_VERSION_1_3_dump,
    of_flow_mod_OF_VERSION_1_3_dump,
    of_flow_mod_failed_error_msg_OF_VERSION_1_3_dump,
    of_flow_modify_OF_VERSION_1_3_dump,
    of_flow_modify_strict_OF_VERSION_1_3_dump,
    of_flow_removed_OF_VERSION_1_3_dump,
    of_flow_stats_reply_OF_VERSION_1_3_dump,
    of_flow_stats_request_OF_VERSION_1_3_dump,
    of_get_config_reply_OF_VERSION_1_3_dump,
    of_get_config_request_OF_VERSION_1_3_dump,
    of_group_desc_stats_reply_OF_VERSION_1_3_dump,
    of_group_desc_stats_request_OF_VERSION_1_3_dump,
    of_group_features_stats_reply_OF_VERSION_1_3_dump,
    of_group_features_stats_request_OF_VERSION_1_3_dump,
    of_group_mod_OF_VERSION_1_3_dump,
    of_group_mod_failed_error_msg_OF_VERSION_1_3_dump,
    of_group_stats_reply_OF_VERSION_1_3_dump,
    of_group_stats_request_OF_VERSION_1_3_dump,
    of_hello_OF_VERSION_1_3_dump,
    of_hello_failed_error_msg_OF_VERSION_1_3_dump,
    of_meter_config_stats_reply_OF_VERSION_1_3_dump,
    of_meter_config_stats_request_OF_VERSION_1_3_dump,
    of_meter_features_stats_reply_OF_VERSION_1_3_dump,
    of_meter_features_stats_request_OF_VERSION_1_3_dump,
    of_meter_mod_OF_VERSION_1_3_dump,
    of_meter_mod_failed_error_msg_OF_VERSION_1_3_dump,
    of_meter_stats_reply_OF_VERSION_1_3_dump,
    of_meter_stats_request_OF_VERSION_1_3_dump,
    unknown_dump,
    unknown_dump,
    of_nicira_header_OF_VERSION_1_3_dump,
    of_packet_in_OF_VERSION_1_3_dump,
    of_packet_out_OF_VERSION_1_3_dump,
    of_port_desc_stats_reply_OF_VERSION_1_3_dump,
    of_port_desc_stats_request_OF_VERSION_1_3_dump,
    of_port_mod_OF_VERSION_1_3_dump,
    of_port_mod_failed_error_msg_OF_VERSION_1_3_dump,
    of_port_stats_reply_OF_VERSION_1_3_dump,
    of_port_stats_request_OF_VERSION_1_3_dump,
    of_port_status_OF_VERSION_1_3_dump,
    of_queue_get_config_reply_OF_VERSION_1_3_dump,
    of_queue_get_config_request_OF_VERSION_1_3_dump,
    of_queue_op_failed_error_msg_OF_VERSION_1_3_dump,
    of_queue_stats_reply_OF_VERSION_1_3_dump,
    of_queue_stats_request_OF_VERSION_1_3_dump,
    of_role_reply_OF_VERSION_1_3_dump,
    of_role_request_OF_VERSION_1_3_dump,
    of_role_request_failed_error_msg_OF_VERSION_1_3_dump,
    of_set_config_OF_VERSION_1_3_dump,
    of_stats_reply_OF_VERSION_1_3_dump,
    of_stats_request_OF_VERSION_1_3_dump,
    of_switch_config_failed_error_msg_OF_VERSION_1_3_dump,
    of_table_features_failed_error_msg_OF_VERSION_1_3_dump,
    of_table_features_stats_reply_OF_VERSION_1_3_dump,
    of_table_features_stats_request_OF_VERSION_1_3_dump,
    of_table_mod_OF_VERSION_1_3_dump,
    of_table_mod_failed_error_msg_OF_VERSION_1_3_dump,
    of_table_stats_reply_OF_VERSION_1_3_dump,
    of_table_stats_request_OF_VERSION_1_3_dump,
    unknown_dump,
    of_action_bsn_OF_VERSION_1_3_dump,
    of_action_bsn_mirror_OF_VERSION_1_3_dump,
    of_action_bsn_set_tunnel_dst_OF_VERSION_1_3_dump,
    of_action_copy_ttl_in_OF_VERSION_1_3_dump,
    of_action_copy_ttl_out_OF_VERSION_1_3_dump,
    of_action_dec_mpls_ttl_OF_VERSION_1_3_dump,
    of_action_dec_nw_ttl_OF_VERSION_1_3_dump,
    unknown_dump,
    of_action_experimenter_OF_VERSION_1_3_dump,
    of_action_group_OF_VERSION_1_3_dump,
    of_action_header_OF_VERSION_1_3_dump,
    unknown_dump,
    of_action_id_bsn_OF_VERSION_1_3_dump,
    of_action_id_bsn_mirror_OF_VERSION_1_3_dump,
    of_action_id_bsn_set_tunnel_dst_OF_VERSION_1_3_dump,
    of_action_id_copy_ttl_in_OF_VERSION_1_3_dump,
    of_action_id_copy_ttl_out_OF_VERSION_1_3_dump,
    of_action_id_dec_mpls_ttl_OF_VERSION_1_3_dump,
    of_action_id_dec_nw_ttl_OF_VERSION_1_3_dump,
    of_action_id_experimenter_OF_VERSION_1_3_dump,
    of_action_id_group_OF_VERSION_1_3_dump,
    of_action_id_header_OF_VERSION_1_3_dump,
    of_action_id_nicira_OF_VERSION_1_3_dump,
    of_action_id_nicira_dec_ttl_OF_VERSION_1_3_dump,
    of_action_id_output_OF_VERSION_1_3_dump,
    of_action_id_pop_mpls_OF_VERSION_1_3_dump,
    of_action_id_pop_pbb_OF_VERSION_1_3_dump,
    of_action_id_pop_vlan_OF_VERSION_1_3_dump,
    of_action_id_push_mpls_OF_VERSION_1_3_dump,
    of_action_id_push_pbb_OF_VERSION_1_3_dump,
    of_action_id_push_vlan_OF_VERSION_1_3_dump,
    of_action_id_set_field_OF_VERSION_1_3_dump,
    of_action_id_set_mpls_ttl_OF_VERSION_1_3_dump,
    of_action_id_set_nw_ttl_OF_VERSION_1_3_dump,
    of_action_id_set_queue_OF_VERSION_1_3_dump,
    of_action_nicira_OF_VERSION_1_3_dump,
    of_action_nicira_dec_ttl_OF_VERSION_1_3_dump,
    of_action_output_OF_VERSION_1_3_dump,
    of_action_pop_mpls_OF_VERSION_1_3_dump,
    of_action_pop_pbb_OF_VERSION_1_3_dump,
    of_action_pop_vlan_OF_VERSION_1_3_dump,
    of_action_push_mpls_OF_VERSION_1_3_dump,
    of_action_push_pbb_OF_VERSION_1_3_dump,
    of_action_push_vlan_OF_VERSION_1_3_dump,
    unknown_dump,
    unknown_dump,
    of_action_set_field_OF_VERSION_1_3_dump,
    unknown_dump,
    unknown_dump,
    of_action_set_mpls_ttl_OF_VERSION_1_3_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    of_action_set_nw_ttl_OF_VERSION_1_3_dump,
    of_action_set_queue_OF_VERSION_1_3_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    unknown_dump,
    of_bsn_interface_OF_VERSION_1_3_dump,
    of_bsn_lacp_stats_entry_OF_VERSION_1_3_dump,
    unknown_dump,
    of_bsn_vport_header_OF_VERSION_1_3_dump,
    of_bsn_vport_q_in_q_OF_VERSION_1_3_dump,
    of_bucket_OF_VERSION_1_3_dump,
    of_bucket_counter_OF_VERSION_1_3_dump,
    of_experimenter_stats_header_OF_VERSION_1_3_dump,
    of_flow_stats_entry_OF_VERSION_1_3_dump,
    of_group_desc_stats_entry_OF_VERSION_1_3_dump,
    of_group_stats_entry_OF_VERSION_1_3_dump,
    of_header_OF_VERSION_1_3_dump,
    unknown_dump,
    of_hello_elem_header_OF_VERSION_1_3_dump,
    of_hello_elem_versionbitmap_OF_VERSION_1_3_dump,
    unknown_dump,
    of_instruction_apply_actions_OF_VERSION_1_3_dump,
    of_instruction_clear_actions_OF_VERSION_1_3_dump,
    of_instruction_experimenter_OF_VERSION_1_3_dump,
    of_instruction_goto_table_OF_VERSION_1_3_dump,
    of_instruction_header_OF_VERSION_1_3_dump,
    of_instruction_meter_OF_VERSION_1_3_dump,
    of_instruction_write_actions_OF_VERSION_1_3_dump,
    of_instruction_write_metadata_OF_VERSION_1_3_dump,
    unknown_dump,
    unknown_dump,
    of_match_v3_OF_VERSION_1_3_dump,
    unknown_dump,
    of_meter_band_drop_OF_VERSION_1_3_dump,
    of_meter_band_dscp_remark_OF_VERSION_1_3_dump,
    of_meter_band_experimenter_OF_VERSION_1_3_dump,
    of_meter_band_header_OF_VERSION_1_3_dump,
    of_meter_band_stats_OF_VERSION_1_3_dump,
    of_meter_config_OF_VERSION_1_3_dump,
    of_meter_features_OF_VERSION_1_3_dump,
    of_meter_stats_OF_VERSION_1_3_dump,
    unknown_dump,
    of_oxm_arp_op_OF_VERSION_1_3_dump,
    of_oxm_arp_op_masked_OF_VERSION_1_3_dump,
    of_oxm_arp_sha_OF_VERSION_1_3_dump,
    of_oxm_arp_sha_masked_OF_VERSION_1_3_dump,
    of_oxm_arp_spa_OF_VERSION_1_3_dump,
    of_oxm_arp_spa_masked_OF_VERSION_1_3_dump,
    of_oxm_arp_tha_OF_VERSION_1_3_dump,
    of_oxm_arp_tha_masked_OF_VERSION_1_3_dump,
    of_oxm_arp_tpa_OF_VERSION_1_3_dump,
    of_oxm_arp_tpa_masked_OF_VERSION_1_3_dump,
    of_oxm_bsn_global_vrf_allowed_OF_VERSION_1_3_dump,
    of_oxm_bsn_global_vrf_allowed_masked_OF_VERSION_1_3_dump,
    of_oxm_bsn_in_ports_128_OF_VERSION_1_3_dump,
    of_oxm_bsn_in_ports_128_masked_OF_VERSION_1_3_dump,
    of_oxm_bsn_l3_dst_class_id_OF_VERSION_1_3_dump,
    of_oxm_bsn_l3_dst_class_id_masked_OF_VERSION_1_3_dump,
    of_oxm_bsn_l3_interface_class_id_OF_VERSION_1_3_dump,
    of_oxm_bsn_l3_interface_class_id_masked_OF_VERSION_1_3_dump,
    of_oxm_bsn_l3_src_class_id_OF_VERSION_1_3_dump,
    of_oxm_bsn_l3_src_class_id_masked_OF_VERSION_1_3_dump,
    of_oxm_bsn_lag_id_OF_VERSION_1_3_dump,
    of_oxm_bsn_lag_id_masked_OF_VERSION_1_3_dump,
    of_oxm_bsn_vrf_OF_VERSION_1_3_dump,
    of_oxm_bsn_vrf_masked_OF_VERSION_1_3_dump,
    of_oxm_eth_dst_OF_VERSION_1_3_dump,
    of_oxm_eth_dst_masked_OF_VERSION_1_3_dump,
    of_oxm_eth_src_OF_VERSION_1_3_dump,
    of_oxm_eth_src_masked_OF_VERSION_1_3_dump,
    of_oxm_eth_type_OF_VERSION_1_3_dump,
    of_oxm_eth_type_masked_OF_VERSION_1_3_dump,
    of_oxm_header_OF_VERSION_1_3_dump,
    of_oxm_icmpv4_code_OF_VERSION_1_3_dump,
    of_oxm_icmpv4_code_masked_OF_VERSION_1_3_dump,
    of_oxm_icmpv4_type_OF_VERSION_1_3_dump,
    of_oxm_icmpv4_type_masked_OF_VERSION_1_3_dump,
    of_oxm_icmpv6_code_OF_VERSION_1_3_dump,
    of_oxm_icmpv6_code_masked_OF_VERSION_1_3_dump,
    of_oxm_icmpv6_type_OF_VERSION_1_3_dump,
    of_oxm_icmpv6_type_masked_OF_VERSION_1_3_dump,
    of_oxm_in_phy_port_OF_VERSION_1_3_dump,
    of_oxm_in_phy_port_masked_OF_VERSION_1_3_dump,
    of_oxm_in_port_OF_VERSION_1_3_dump,
    of_oxm_in_port_masked_OF_VERSION_1_3_dump,
    of_oxm_ip_dscp_OF_VERSION_1_3_dump,
    of_oxm_ip_dscp_masked_OF_VERSION_1_3_dump,
    of_oxm_ip_ecn_OF_VERSION_1_3_dump,
    of_oxm_ip_ecn_masked_OF_VERSION_1_3_dump,
    of_oxm_ip_proto_OF_VERSION_1_3_dump,
    of_oxm_ip_proto_masked_OF_VERSION_1_3_dump,
    of_oxm_ipv4_dst_OF_VERSION_1_3_dump,
    of_oxm_ipv4_dst_masked_OF_VERSION_1_3_dump,
    of_oxm_ipv4_src_OF_VERSION_1_3_dump,
    of_oxm_ipv4_src_masked_OF_VERSION_1_3_dump,
    of_oxm_ipv6_dst_OF_VERSION_1_3_dump,
    of_oxm_ipv6_dst_masked_OF_VERSION_1_3_dump,
    of_oxm_ipv6_flabel_OF_VERSION_1_3_dump,
    of_oxm_ipv6_flabel_masked_OF_VERSION_1_3_dump,
    of_oxm_ipv6_nd_sll_OF_VERSION_1_3_dump,
    of_oxm_ipv6_nd_sll_masked_OF_VERSION_1_3_dump,
    of_oxm_ipv6_nd_target_OF_VERSION_1_3_dump,
    of_oxm_ipv6_nd_target_masked_OF_VERSION_1_3_dump,
    of_oxm_ipv6_nd_tll_OF_VERSION_1_3_dump,
    of_oxm_ipv6_nd_tll_masked_OF_VERSION_1_3_dump,
    of_oxm_ipv6_src_OF_VERSION_1_3_dump,
    of_oxm_ipv6_src_masked_OF_VERSION_1_3_dump,
    of_oxm_metadata_OF_VERSION_1_3_dump,
    of_oxm_metadata_masked_OF_VERSION_1_3_dump,
    of_oxm_mpls_label_OF_VERSION_1_3_dump,
    of_oxm_mpls_label_masked_OF_VERSION_1_3_dump,
    of_oxm_mpls_tc_OF_VERSION_1_3_dump,
    of_oxm_mpls_tc_masked_OF_VERSION_1_3_dump,
    of_oxm_sctp_dst_OF_VERSION_1_3_dump,
    of_oxm_sctp_dst_masked_OF_VERSION_1_3_dump,
    of_oxm_sctp_src_OF_VERSION_1_3_dump,
    of_oxm_sctp_src_masked_OF_VERSION_1_3_dump,
    of_oxm_tcp_dst_OF_VERSION_1_3_dump,
    of_oxm_tcp_dst_masked_OF_VERSION_1_3_dump,
    of_oxm_tcp_src_OF_VERSION_1_3_dump,
    of_oxm_tcp_src_masked_OF_VERSION_1_3_dump,
    of_oxm_udp_dst_OF_VERSION_1_3_dump,
    of_oxm_udp_dst_masked_OF_VERSION_1_3_dump,
    of_oxm_udp_src_OF_VERSION_1_3_dump,
    of_oxm_udp_src_masked_OF_VERSION_1_3_dump,
    of_oxm_vlan_pcp_OF_VERSION_1_3_dump,
    of_oxm_vlan_pcp_masked_OF_VERSION_1_3_dump,
    of_oxm_vlan_vid_OF_VERSION_1_3_dump,
    of_oxm_vlan_vid_masked_OF_VERSION_1_3_dump,
    of_packet_queue_OF_VERSION_1_3_dump,
    of_port_desc_OF_VERSION_1_3_dump,
    of_port_stats_entry_OF_VERSION_1_3_dump,
    unknown_dump,
    of_queue_prop_experimenter_OF_VERSION_1_3_dump,
    of_queue_prop_header_OF_VERSION_1_3_dump,
    of_queue_prop_max_rate_OF_VERSION_1_3_dump,
    of_queue_prop_min_rate_OF_VERSION_1_3_dump,
    of_queue_stats_entry_OF_VERSION_1_3_dump,
    unknown_dump,
    of_table_feature_prop_apply_actions_OF_VERSION_1_3_dump,
    of_table_feature_prop_apply_actions_miss_OF_VERSION_1_3_dump,
    of_table_feature_prop_apply_setfield_OF_VERSION_1_3_dump,
    of_table_feature_prop_apply_setfield_miss_OF_VERSION_1_3_dump,
    of_table_feature_prop_experimenter_OF_VERSION_1_3_dump,
    of_table_feature_prop_header_OF_VERSION_1_3_dump,
    of_table_feature_prop_instructions_OF_VERSION_1_3_dump,
    of_table_feature_prop_instructions_miss_OF_VERSION_1_3_dump,
    of_table_feature_prop_match_OF_VERSION_1_3_dump,
    of_table_feature_prop_next_tables_OF_VERSION_1_3_dump,
    of_table_feature_prop_next_tables_miss_OF_VERSION_1_3_dump,
    of_table_feature_prop_wildcards_OF_VERSION_1_3_dump,
    of_table_feature_prop_write_actions_OF_VERSION_1_3_dump,
    of_table_feature_prop_write_actions_miss_OF_VERSION_1_3_dump,
    of_table_feature_prop_write_setfield_OF_VERSION_1_3_dump,
    of_table_feature_prop_write_setfield_miss_OF_VERSION_1_3_dump,
    of_table_features_OF_VERSION_1_3_dump,
    of_table_stats_entry_OF_VERSION_1_3_dump,
    of_uint32_OF_VERSION_1_3_dump,
    of_uint8_OF_VERSION_1_3_dump,
    of_list_action_OF_VERSION_1_3_dump,
    of_list_action_id_OF_VERSION_1_3_dump,
    of_list_bsn_interface_OF_VERSION_1_3_dump,
    of_list_bsn_lacp_stats_entry_OF_VERSION_1_3_dump,
    of_list_bucket_OF_VERSION_1_3_dump,
    of_list_bucket_counter_OF_VERSION_1_3_dump,
    of_list_flow_stats_entry_OF_VERSION_1_3_dump,
    of_list_group_desc_stats_entry_OF_VERSION_1_3_dump,
    of_list_group_stats_entry_OF_VERSION_1_3_dump,
    of_list_hello_elem_OF_VERSION_1_3_dump,
    of_list_instruction_OF_VERSION_1_3_dump,
    of_list_meter_band_OF_VERSION_1_3_dump,
    of_list_meter_band_stats_OF_VERSION_1_3_dump,
    of_list_meter_stats_OF_VERSION_1_3_dump,
    of_list_oxm_OF_VERSION_1_3_dump,
    of_list_packet_queue_OF_VERSION_1_3_dump,
    of_list_port_desc_OF_VERSION_1_3_dump,
    of_list_port_stats_entry_OF_VERSION_1_3_dump,
    of_list_queue_prop_OF_VERSION_1_3_dump,
    of_list_queue_stats_entry_OF_VERSION_1_3_dump,
    of_list_table_feature_prop_OF_VERSION_1_3_dump,
    of_list_table_features_OF_VERSION_1_3_dump,
    of_list_table_stats_entry_OF_VERSION_1_3_dump,
    of_list_uint32_OF_VERSION_1_3_dump,
    of_list_uint8_OF_VERSION_1_3_dump
};


static const loci_obj_dump_f *const dump_funs[5] = {
    NULL,
    dump_funs_v1,
    dump_funs_v2,
    dump_funs_v3,
    dump_funs_v4
};

int
of_object_dump(loci_writer_f writer, void* cookie, of_object_t *obj)
{
    if ((obj->object_id > 0) && (obj->object_id < OF_OBJECT_COUNT)) {
        if (((obj)->version > 0) && ((obj)->version <= OF_VERSION_1_3)) {
            /* @fixme VERSION */
            return dump_funs[obj->version][obj->object_id](writer, cookie, (of_object_t *)obj);
        } else {
            return writer(cookie, "Bad version %d\n", obj->version);
        }
    }
    return writer(cookie, "Bad object id %d\n", obj->object_id);
}
