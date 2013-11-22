/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */

/**
 *
 * AUTOMATICALLY GENERATED FILE.  Edits will be lost on regen.
 *
 * Source file for object showing.
 *
 */

#define DISABLE_WARN_UNUSED_RESULT
#include <loci/loci.h>
#include <loci/loci_show.h>
#include <loci/loci_obj_show.h>

static int
unknown_show(loci_writer_f writer, void* cookie, of_object_t *obj)
{
    return writer(cookie, "Unable to print object of type %d, version %d\n",
                         obj->object_id, obj->version);
}

int
of_aggregate_stats_reply_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_aggregate_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    uint64_t val64;

    of_aggregate_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_aggregate_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    of_aggregate_stats_reply_packet_count_get(obj, &val64);
    out += writer(cookie, "packet_count=");
    out += LOCI_SHOW_u64_packet_count(writer, cookie, val64);
    out += writer(cookie, " ");

    of_aggregate_stats_reply_byte_count_get(obj, &val64);
    out += writer(cookie, "byte_count=");
    out += LOCI_SHOW_u64_byte_count(writer, cookie, val64);
    out += writer(cookie, " ");

    of_aggregate_stats_reply_flow_count_get(obj, &val32);
    out += writer(cookie, "flow_count=");
    out += LOCI_SHOW_u32_flow_count(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_aggregate_stats_request_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_aggregate_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_match_t match;
    uint8_t val8;
    of_port_no_t port_no;

    of_aggregate_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_aggregate_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    of_aggregate_stats_request_match_get(obj, &match);
    out += writer(cookie, "match=");
    out += LOCI_SHOW_match_match(writer, cookie, match);
    out += writer(cookie, " ");

    of_aggregate_stats_request_table_id_get(obj, &val8);
    out += writer(cookie, "table_id=");
    out += LOCI_SHOW_u8_table_id(writer, cookie, val8);
    out += writer(cookie, " ");

    of_aggregate_stats_request_out_port_get(obj, &port_no);
    out += writer(cookie, "out_port=");
    out += LOCI_SHOW_port_no_out_port(writer, cookie, port_no);
    out += writer(cookie, " ");

    return out;
}

int
of_bad_action_error_msg_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_bad_action_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    of_bad_action_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bad_action_error_msg_code_get(obj, &val16);
    out += writer(cookie, "code=");
    out += LOCI_SHOW_u16_code(writer, cookie, val16);
    out += writer(cookie, " ");

    of_bad_action_error_msg_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_bad_request_error_msg_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_bad_request_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    of_bad_request_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bad_request_error_msg_code_get(obj, &val16);
    out += writer(cookie, "code=");
    out += LOCI_SHOW_u16_code(writer, cookie, val16);
    out += writer(cookie, " ");

    of_bad_request_error_msg_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_barrier_reply_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_barrier_reply_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_barrier_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_barrier_request_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_barrier_request_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_barrier_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_bw_clear_data_reply_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_bsn_bw_clear_data_reply_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_bsn_bw_clear_data_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_bw_clear_data_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_bw_clear_data_reply_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_bw_clear_data_reply_status_get(obj, &val32);
    out += writer(cookie, "status=");
    out += LOCI_SHOW_u32_status(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_bw_clear_data_request_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_bsn_bw_clear_data_request_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_bsn_bw_clear_data_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_bw_clear_data_request_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_bw_clear_data_request_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_bw_enable_get_reply_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_bsn_bw_enable_get_reply_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_bsn_bw_enable_get_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_bw_enable_get_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_bw_enable_get_reply_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_bw_enable_get_reply_enabled_get(obj, &val32);
    out += writer(cookie, "enabled=");
    out += LOCI_SHOW_u32_enabled(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_bw_enable_get_request_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_bsn_bw_enable_get_request_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_bsn_bw_enable_get_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_bw_enable_get_request_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_bw_enable_get_request_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_bw_enable_set_reply_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_bsn_bw_enable_set_reply_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_bsn_bw_enable_set_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_bw_enable_set_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_bw_enable_set_reply_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_bw_enable_set_reply_enable_get(obj, &val32);
    out += writer(cookie, "enable=");
    out += LOCI_SHOW_u32_enable(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_bw_enable_set_reply_status_get(obj, &val32);
    out += writer(cookie, "status=");
    out += LOCI_SHOW_u32_status(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_bw_enable_set_request_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_bsn_bw_enable_set_request_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_bsn_bw_enable_set_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_bw_enable_set_request_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_bw_enable_set_request_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_bw_enable_set_request_enable_get(obj, &val32);
    out += writer(cookie, "enable=");
    out += LOCI_SHOW_u32_enable(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_get_interfaces_reply_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_bsn_get_interfaces_reply_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_list_bsn_interface_t list;
    of_bsn_interface_t elt;
    int rv;

    of_bsn_get_interfaces_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_get_interfaces_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_get_interfaces_reply_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    out += writer(cookie, "of_bsn_interface_t={ ");
    of_bsn_get_interfaces_reply_interfaces_bind(obj, &list);
    OF_LIST_BSN_INTERFACE_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_bsn_get_interfaces_request_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_bsn_get_interfaces_request_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_bsn_get_interfaces_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_get_interfaces_request_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_get_interfaces_request_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_get_ip_mask_reply_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_bsn_get_ip_mask_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint8_t val8;

    of_bsn_get_ip_mask_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_get_ip_mask_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_get_ip_mask_reply_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_get_ip_mask_reply_index_get(obj, &val8);
    out += writer(cookie, "index=");
    out += LOCI_SHOW_u8_index(writer, cookie, val8);
    out += writer(cookie, " ");

    of_bsn_get_ip_mask_reply_mask_get(obj, &val32);
    out += writer(cookie, "mask=");
    out += LOCI_SHOW_u32_mask(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_get_ip_mask_request_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_bsn_get_ip_mask_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint8_t val8;

    of_bsn_get_ip_mask_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_get_ip_mask_request_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_get_ip_mask_request_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_get_ip_mask_request_index_get(obj, &val8);
    out += writer(cookie, "index=");
    out += LOCI_SHOW_u8_index(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_get_l2_table_reply_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_bsn_get_l2_table_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint8_t val8;
    uint16_t val16;

    of_bsn_get_l2_table_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_get_l2_table_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_get_l2_table_reply_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_get_l2_table_reply_l2_table_enable_get(obj, &val8);
    out += writer(cookie, "l2_table_enable=");
    out += LOCI_SHOW_u8_l2_table_enable(writer, cookie, val8);
    out += writer(cookie, " ");

    of_bsn_get_l2_table_reply_l2_table_priority_get(obj, &val16);
    out += writer(cookie, "l2_table_priority=");
    out += LOCI_SHOW_u16_l2_table_priority(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_get_l2_table_request_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_bsn_get_l2_table_request_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_bsn_get_l2_table_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_get_l2_table_request_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_get_l2_table_request_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_get_mirroring_reply_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_bsn_get_mirroring_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint8_t val8;

    of_bsn_get_mirroring_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_get_mirroring_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_get_mirroring_reply_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_get_mirroring_reply_report_mirror_ports_get(obj, &val8);
    out += writer(cookie, "report_mirror_ports=");
    out += LOCI_SHOW_u8_report_mirror_ports(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_get_mirroring_request_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_bsn_get_mirroring_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint8_t val8;

    of_bsn_get_mirroring_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_get_mirroring_request_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_get_mirroring_request_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_get_mirroring_request_report_mirror_ports_get(obj, &val8);
    out += writer(cookie, "report_mirror_ports=");
    out += LOCI_SHOW_u8_report_mirror_ports(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_header_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_bsn_header_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_bsn_header_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_header_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_header_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_hybrid_get_reply_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_bsn_hybrid_get_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint8_t val8;
    uint16_t val16;

    of_bsn_hybrid_get_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_hybrid_get_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_hybrid_get_reply_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_hybrid_get_reply_hybrid_enable_get(obj, &val8);
    out += writer(cookie, "hybrid_enable=");
    out += LOCI_SHOW_u8_hybrid_enable(writer, cookie, val8);
    out += writer(cookie, " ");

    of_bsn_hybrid_get_reply_hybrid_version_get(obj, &val16);
    out += writer(cookie, "hybrid_version=");
    out += LOCI_SHOW_u16_hybrid_version(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_hybrid_get_request_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_bsn_hybrid_get_request_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_bsn_hybrid_get_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_hybrid_get_request_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_hybrid_get_request_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_pdu_rx_reply_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_bsn_pdu_rx_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_port_no_t port_no;
    uint8_t val8;

    of_bsn_pdu_rx_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_pdu_rx_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_pdu_rx_reply_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_pdu_rx_reply_status_get(obj, &val32);
    out += writer(cookie, "status=");
    out += LOCI_SHOW_u32_status(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_pdu_rx_reply_port_no_get(obj, &port_no);
    out += writer(cookie, "port_no=");
    out += LOCI_SHOW_port_no_port_no(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_bsn_pdu_rx_reply_slot_num_get(obj, &val8);
    out += writer(cookie, "slot_num=");
    out += LOCI_SHOW_u8_slot_num(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_pdu_rx_request_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_bsn_pdu_rx_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_port_no_t port_no;
    uint8_t val8;
    of_octets_t octets;

    of_bsn_pdu_rx_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_pdu_rx_request_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_pdu_rx_request_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_pdu_rx_request_timeout_ms_get(obj, &val32);
    out += writer(cookie, "timeout_ms=");
    out += LOCI_SHOW_u32_timeout_ms(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_pdu_rx_request_port_no_get(obj, &port_no);
    out += writer(cookie, "port_no=");
    out += LOCI_SHOW_port_no_port_no(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_bsn_pdu_rx_request_slot_num_get(obj, &val8);
    out += writer(cookie, "slot_num=");
    out += LOCI_SHOW_u8_slot_num(writer, cookie, val8);
    out += writer(cookie, " ");

    of_bsn_pdu_rx_request_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_pdu_rx_timeout_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_bsn_pdu_rx_timeout_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_port_no_t port_no;
    uint8_t val8;

    of_bsn_pdu_rx_timeout_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_pdu_rx_timeout_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_pdu_rx_timeout_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_pdu_rx_timeout_port_no_get(obj, &port_no);
    out += writer(cookie, "port_no=");
    out += LOCI_SHOW_port_no_port_no(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_bsn_pdu_rx_timeout_slot_num_get(obj, &val8);
    out += writer(cookie, "slot_num=");
    out += LOCI_SHOW_u8_slot_num(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_pdu_tx_reply_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_bsn_pdu_tx_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_port_no_t port_no;
    uint8_t val8;

    of_bsn_pdu_tx_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_pdu_tx_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_pdu_tx_reply_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_pdu_tx_reply_status_get(obj, &val32);
    out += writer(cookie, "status=");
    out += LOCI_SHOW_u32_status(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_pdu_tx_reply_port_no_get(obj, &port_no);
    out += writer(cookie, "port_no=");
    out += LOCI_SHOW_port_no_port_no(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_bsn_pdu_tx_reply_slot_num_get(obj, &val8);
    out += writer(cookie, "slot_num=");
    out += LOCI_SHOW_u8_slot_num(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_pdu_tx_request_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_bsn_pdu_tx_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_port_no_t port_no;
    uint8_t val8;
    of_octets_t octets;

    of_bsn_pdu_tx_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_pdu_tx_request_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_pdu_tx_request_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_pdu_tx_request_tx_interval_ms_get(obj, &val32);
    out += writer(cookie, "tx_interval_ms=");
    out += LOCI_SHOW_u32_tx_interval_ms(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_pdu_tx_request_port_no_get(obj, &port_no);
    out += writer(cookie, "port_no=");
    out += LOCI_SHOW_port_no_port_no(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_bsn_pdu_tx_request_slot_num_get(obj, &val8);
    out += writer(cookie, "slot_num=");
    out += LOCI_SHOW_u8_slot_num(writer, cookie, val8);
    out += writer(cookie, " ");

    of_bsn_pdu_tx_request_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_set_ip_mask_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_bsn_set_ip_mask_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint8_t val8;

    of_bsn_set_ip_mask_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_set_ip_mask_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_set_ip_mask_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_set_ip_mask_index_get(obj, &val8);
    out += writer(cookie, "index=");
    out += LOCI_SHOW_u8_index(writer, cookie, val8);
    out += writer(cookie, " ");

    of_bsn_set_ip_mask_mask_get(obj, &val32);
    out += writer(cookie, "mask=");
    out += LOCI_SHOW_u32_mask(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_set_l2_table_reply_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_bsn_set_l2_table_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint8_t val8;
    uint16_t val16;

    of_bsn_set_l2_table_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_set_l2_table_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_set_l2_table_reply_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_set_l2_table_reply_l2_table_enable_get(obj, &val8);
    out += writer(cookie, "l2_table_enable=");
    out += LOCI_SHOW_u8_l2_table_enable(writer, cookie, val8);
    out += writer(cookie, " ");

    of_bsn_set_l2_table_reply_l2_table_priority_get(obj, &val16);
    out += writer(cookie, "l2_table_priority=");
    out += LOCI_SHOW_u16_l2_table_priority(writer, cookie, val16);
    out += writer(cookie, " ");

    of_bsn_set_l2_table_reply_status_get(obj, &val32);
    out += writer(cookie, "status=");
    out += LOCI_SHOW_u32_status(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_set_l2_table_request_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_bsn_set_l2_table_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint8_t val8;
    uint16_t val16;

    of_bsn_set_l2_table_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_set_l2_table_request_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_set_l2_table_request_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_set_l2_table_request_l2_table_enable_get(obj, &val8);
    out += writer(cookie, "l2_table_enable=");
    out += LOCI_SHOW_u8_l2_table_enable(writer, cookie, val8);
    out += writer(cookie, " ");

    of_bsn_set_l2_table_request_l2_table_priority_get(obj, &val16);
    out += writer(cookie, "l2_table_priority=");
    out += LOCI_SHOW_u16_l2_table_priority(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_set_mirroring_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_bsn_set_mirroring_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint8_t val8;

    of_bsn_set_mirroring_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_set_mirroring_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_set_mirroring_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_set_mirroring_report_mirror_ports_get(obj, &val8);
    out += writer(cookie, "report_mirror_ports=");
    out += LOCI_SHOW_u8_report_mirror_ports(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_set_pktin_suppression_reply_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_bsn_set_pktin_suppression_reply_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_bsn_set_pktin_suppression_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_set_pktin_suppression_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_set_pktin_suppression_reply_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_set_pktin_suppression_reply_status_get(obj, &val32);
    out += writer(cookie, "status=");
    out += LOCI_SHOW_u32_status(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_set_pktin_suppression_request_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_bsn_set_pktin_suppression_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint8_t val8;
    uint16_t val16;
    uint64_t val64;

    of_bsn_set_pktin_suppression_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_set_pktin_suppression_request_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_set_pktin_suppression_request_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_set_pktin_suppression_request_enabled_get(obj, &val8);
    out += writer(cookie, "enabled=");
    out += LOCI_SHOW_u8_enabled(writer, cookie, val8);
    out += writer(cookie, " ");

    of_bsn_set_pktin_suppression_request_idle_timeout_get(obj, &val16);
    out += writer(cookie, "idle_timeout=");
    out += LOCI_SHOW_u16_idle_timeout(writer, cookie, val16);
    out += writer(cookie, " ");

    of_bsn_set_pktin_suppression_request_hard_timeout_get(obj, &val16);
    out += writer(cookie, "hard_timeout=");
    out += LOCI_SHOW_u16_hard_timeout(writer, cookie, val16);
    out += writer(cookie, " ");

    of_bsn_set_pktin_suppression_request_priority_get(obj, &val16);
    out += writer(cookie, "priority=");
    out += LOCI_SHOW_u16_priority(writer, cookie, val16);
    out += writer(cookie, " ");

    of_bsn_set_pktin_suppression_request_cookie_get(obj, &val64);
    out += writer(cookie, "cookie=");
    out += LOCI_SHOW_u64_cookie(writer, cookie, val64);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_shell_command_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_bsn_shell_command_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_octets_t octets;

    of_bsn_shell_command_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_shell_command_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_shell_command_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_shell_command_service_get(obj, &val32);
    out += writer(cookie, "service=");
    out += LOCI_SHOW_u32_service(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_shell_command_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_shell_output_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_bsn_shell_output_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_octets_t octets;

    of_bsn_shell_output_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_shell_output_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_shell_output_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_shell_output_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_shell_status_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_bsn_shell_status_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_bsn_shell_status_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_shell_status_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_shell_status_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_shell_status_status_get(obj, &val32);
    out += writer(cookie, "status=");
    out += LOCI_SHOW_u32_status(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_stats_reply_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_bsn_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_bsn_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    of_bsn_stats_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_stats_reply_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_stats_request_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_bsn_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_bsn_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    of_bsn_stats_request_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_stats_request_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_virtual_port_create_reply_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_bsn_virtual_port_create_reply_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_bsn_virtual_port_create_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_virtual_port_create_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_virtual_port_create_reply_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_virtual_port_create_reply_status_get(obj, &val32);
    out += writer(cookie, "status=");
    out += LOCI_SHOW_u32_status(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_virtual_port_create_reply_vport_no_get(obj, &val32);
    out += writer(cookie, "vport_no=");
    out += LOCI_SHOW_u32_vport_no(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_virtual_port_create_request_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_bsn_virtual_port_create_request_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_bsn_vport_q_in_q_t vport;

    of_bsn_virtual_port_create_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_virtual_port_create_request_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_virtual_port_create_request_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_virtual_port_create_request_vport_bind(obj, &vport);
    out += of_bsn_vport_q_in_q_OF_VERSION_1_0_show(writer, cookie, &vport);

    return out;
}

int
of_bsn_virtual_port_remove_reply_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_bsn_virtual_port_remove_reply_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_bsn_virtual_port_remove_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_virtual_port_remove_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_virtual_port_remove_reply_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_virtual_port_remove_reply_status_get(obj, &val32);
    out += writer(cookie, "status=");
    out += LOCI_SHOW_u32_status(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_virtual_port_remove_request_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_bsn_virtual_port_remove_request_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_bsn_virtual_port_remove_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_virtual_port_remove_request_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_virtual_port_remove_request_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_virtual_port_remove_request_vport_no_get(obj, &val32);
    out += writer(cookie, "vport_no=");
    out += LOCI_SHOW_u32_vport_no(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_desc_stats_reply_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_desc_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_desc_str_t desc_str;
    of_serial_num_t ser_num;

    of_desc_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_desc_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    of_desc_stats_reply_mfr_desc_get(obj, &desc_str);
    out += writer(cookie, "mfr_desc=");
    out += LOCI_SHOW_desc_str_mfr_desc(writer, cookie, desc_str);
    out += writer(cookie, " ");

    of_desc_stats_reply_hw_desc_get(obj, &desc_str);
    out += writer(cookie, "hw_desc=");
    out += LOCI_SHOW_desc_str_hw_desc(writer, cookie, desc_str);
    out += writer(cookie, " ");

    of_desc_stats_reply_sw_desc_get(obj, &desc_str);
    out += writer(cookie, "sw_desc=");
    out += LOCI_SHOW_desc_str_sw_desc(writer, cookie, desc_str);
    out += writer(cookie, " ");

    of_desc_stats_reply_serial_num_get(obj, &ser_num);
    out += writer(cookie, "serial_num=");
    out += LOCI_SHOW_ser_num_serial_num(writer, cookie, ser_num);
    out += writer(cookie, " ");

    of_desc_stats_reply_dp_desc_get(obj, &desc_str);
    out += writer(cookie, "dp_desc=");
    out += LOCI_SHOW_desc_str_dp_desc(writer, cookie, desc_str);
    out += writer(cookie, " ");

    return out;
}

int
of_desc_stats_request_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_desc_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_desc_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_desc_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_echo_reply_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_echo_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_octets_t octets;

    of_echo_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_echo_reply_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_echo_request_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_echo_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_octets_t octets;

    of_echo_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_echo_request_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_error_msg_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_experimenter_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_experimenter_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_octets_t octets;

    of_experimenter_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_experimenter_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_experimenter_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_experimenter_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_experimenter_stats_reply_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_experimenter_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    of_experimenter_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_experimenter_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    of_experimenter_stats_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_experimenter_stats_reply_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_experimenter_stats_request_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_experimenter_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    of_experimenter_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_experimenter_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    of_experimenter_stats_request_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_experimenter_stats_request_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_features_reply_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_features_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint64_t val64;
    uint8_t val8;

    of_list_port_desc_t list;
    of_port_desc_t elt;
    int rv;

    of_features_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_features_reply_datapath_id_get(obj, &val64);
    out += writer(cookie, "datapath_id=");
    out += LOCI_SHOW_u64_datapath_id(writer, cookie, val64);
    out += writer(cookie, " ");

    of_features_reply_n_buffers_get(obj, &val32);
    out += writer(cookie, "n_buffers=");
    out += LOCI_SHOW_u32_n_buffers(writer, cookie, val32);
    out += writer(cookie, " ");

    of_features_reply_n_tables_get(obj, &val8);
    out += writer(cookie, "n_tables=");
    out += LOCI_SHOW_u8_n_tables(writer, cookie, val8);
    out += writer(cookie, " ");

    of_features_reply_capabilities_get(obj, &val32);
    out += writer(cookie, "capabilities=");
    out += LOCI_SHOW_u32_capabilities(writer, cookie, val32);
    out += writer(cookie, " ");

    of_features_reply_actions_get(obj, &val32);
    out += writer(cookie, "actions=");
    out += LOCI_SHOW_u32_actions(writer, cookie, val32);
    out += writer(cookie, " ");

    out += writer(cookie, "of_port_desc_t={ ");
    of_features_reply_ports_bind(obj, &list);
    OF_LIST_PORT_DESC_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_features_request_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_features_request_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_features_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_flow_add_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_flow_add_t *obj)
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

    of_flow_add_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_add_match_get(obj, &match);
    out += writer(cookie, "match=");
    out += LOCI_SHOW_match_match(writer, cookie, match);
    out += writer(cookie, " ");

    of_flow_add_cookie_get(obj, &val64);
    out += writer(cookie, "cookie=");
    out += LOCI_SHOW_u64_cookie(writer, cookie, val64);
    out += writer(cookie, " ");

    of_flow_add_idle_timeout_get(obj, &val16);
    out += writer(cookie, "idle_timeout=");
    out += LOCI_SHOW_u16_idle_timeout(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_add_hard_timeout_get(obj, &val16);
    out += writer(cookie, "hard_timeout=");
    out += LOCI_SHOW_u16_hard_timeout(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_add_priority_get(obj, &val16);
    out += writer(cookie, "priority=");
    out += LOCI_SHOW_u16_priority(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_add_buffer_id_get(obj, &val32);
    out += writer(cookie, "buffer_id=");
    out += LOCI_SHOW_u32_buffer_id(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_add_out_port_get(obj, &port_no);
    out += writer(cookie, "out_port=");
    out += LOCI_SHOW_port_no_out_port(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_flow_add_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    out += writer(cookie, "of_action_t={ ");
    of_flow_add_actions_bind(obj, &list);
    OF_LIST_ACTION_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_flow_delete_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_flow_delete_t *obj)
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

    of_flow_delete_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_delete_match_get(obj, &match);
    out += writer(cookie, "match=");
    out += LOCI_SHOW_match_match(writer, cookie, match);
    out += writer(cookie, " ");

    of_flow_delete_cookie_get(obj, &val64);
    out += writer(cookie, "cookie=");
    out += LOCI_SHOW_u64_cookie(writer, cookie, val64);
    out += writer(cookie, " ");

    of_flow_delete_idle_timeout_get(obj, &val16);
    out += writer(cookie, "idle_timeout=");
    out += LOCI_SHOW_u16_idle_timeout(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_delete_hard_timeout_get(obj, &val16);
    out += writer(cookie, "hard_timeout=");
    out += LOCI_SHOW_u16_hard_timeout(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_delete_priority_get(obj, &val16);
    out += writer(cookie, "priority=");
    out += LOCI_SHOW_u16_priority(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_delete_buffer_id_get(obj, &val32);
    out += writer(cookie, "buffer_id=");
    out += LOCI_SHOW_u32_buffer_id(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_delete_out_port_get(obj, &port_no);
    out += writer(cookie, "out_port=");
    out += LOCI_SHOW_port_no_out_port(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_flow_delete_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    out += writer(cookie, "of_action_t={ ");
    of_flow_delete_actions_bind(obj, &list);
    OF_LIST_ACTION_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_flow_delete_strict_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_flow_delete_strict_t *obj)
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

    of_flow_delete_strict_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_delete_strict_match_get(obj, &match);
    out += writer(cookie, "match=");
    out += LOCI_SHOW_match_match(writer, cookie, match);
    out += writer(cookie, " ");

    of_flow_delete_strict_cookie_get(obj, &val64);
    out += writer(cookie, "cookie=");
    out += LOCI_SHOW_u64_cookie(writer, cookie, val64);
    out += writer(cookie, " ");

    of_flow_delete_strict_idle_timeout_get(obj, &val16);
    out += writer(cookie, "idle_timeout=");
    out += LOCI_SHOW_u16_idle_timeout(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_delete_strict_hard_timeout_get(obj, &val16);
    out += writer(cookie, "hard_timeout=");
    out += LOCI_SHOW_u16_hard_timeout(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_delete_strict_priority_get(obj, &val16);
    out += writer(cookie, "priority=");
    out += LOCI_SHOW_u16_priority(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_delete_strict_buffer_id_get(obj, &val32);
    out += writer(cookie, "buffer_id=");
    out += LOCI_SHOW_u32_buffer_id(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_delete_strict_out_port_get(obj, &port_no);
    out += writer(cookie, "out_port=");
    out += LOCI_SHOW_port_no_out_port(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_flow_delete_strict_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    out += writer(cookie, "of_action_t={ ");
    of_flow_delete_strict_actions_bind(obj, &list);
    OF_LIST_ACTION_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_flow_mod_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_flow_mod_t *obj)
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

    of_flow_mod_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_mod_match_get(obj, &match);
    out += writer(cookie, "match=");
    out += LOCI_SHOW_match_match(writer, cookie, match);
    out += writer(cookie, " ");

    of_flow_mod_cookie_get(obj, &val64);
    out += writer(cookie, "cookie=");
    out += LOCI_SHOW_u64_cookie(writer, cookie, val64);
    out += writer(cookie, " ");

    of_flow_mod_idle_timeout_get(obj, &val16);
    out += writer(cookie, "idle_timeout=");
    out += LOCI_SHOW_u16_idle_timeout(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_mod_hard_timeout_get(obj, &val16);
    out += writer(cookie, "hard_timeout=");
    out += LOCI_SHOW_u16_hard_timeout(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_mod_priority_get(obj, &val16);
    out += writer(cookie, "priority=");
    out += LOCI_SHOW_u16_priority(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_mod_buffer_id_get(obj, &val32);
    out += writer(cookie, "buffer_id=");
    out += LOCI_SHOW_u32_buffer_id(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_mod_out_port_get(obj, &port_no);
    out += writer(cookie, "out_port=");
    out += LOCI_SHOW_port_no_out_port(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_flow_mod_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    out += writer(cookie, "of_action_t={ ");
    of_flow_mod_actions_bind(obj, &list);
    OF_LIST_ACTION_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_flow_mod_failed_error_msg_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_flow_mod_failed_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    of_flow_mod_failed_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_mod_failed_error_msg_code_get(obj, &val16);
    out += writer(cookie, "code=");
    out += LOCI_SHOW_u16_code(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_mod_failed_error_msg_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_flow_modify_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_flow_modify_t *obj)
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

    of_flow_modify_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_modify_match_get(obj, &match);
    out += writer(cookie, "match=");
    out += LOCI_SHOW_match_match(writer, cookie, match);
    out += writer(cookie, " ");

    of_flow_modify_cookie_get(obj, &val64);
    out += writer(cookie, "cookie=");
    out += LOCI_SHOW_u64_cookie(writer, cookie, val64);
    out += writer(cookie, " ");

    of_flow_modify_idle_timeout_get(obj, &val16);
    out += writer(cookie, "idle_timeout=");
    out += LOCI_SHOW_u16_idle_timeout(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_modify_hard_timeout_get(obj, &val16);
    out += writer(cookie, "hard_timeout=");
    out += LOCI_SHOW_u16_hard_timeout(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_modify_priority_get(obj, &val16);
    out += writer(cookie, "priority=");
    out += LOCI_SHOW_u16_priority(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_modify_buffer_id_get(obj, &val32);
    out += writer(cookie, "buffer_id=");
    out += LOCI_SHOW_u32_buffer_id(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_modify_out_port_get(obj, &port_no);
    out += writer(cookie, "out_port=");
    out += LOCI_SHOW_port_no_out_port(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_flow_modify_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    out += writer(cookie, "of_action_t={ ");
    of_flow_modify_actions_bind(obj, &list);
    OF_LIST_ACTION_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_flow_modify_strict_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_flow_modify_strict_t *obj)
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

    of_flow_modify_strict_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_modify_strict_match_get(obj, &match);
    out += writer(cookie, "match=");
    out += LOCI_SHOW_match_match(writer, cookie, match);
    out += writer(cookie, " ");

    of_flow_modify_strict_cookie_get(obj, &val64);
    out += writer(cookie, "cookie=");
    out += LOCI_SHOW_u64_cookie(writer, cookie, val64);
    out += writer(cookie, " ");

    of_flow_modify_strict_idle_timeout_get(obj, &val16);
    out += writer(cookie, "idle_timeout=");
    out += LOCI_SHOW_u16_idle_timeout(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_modify_strict_hard_timeout_get(obj, &val16);
    out += writer(cookie, "hard_timeout=");
    out += LOCI_SHOW_u16_hard_timeout(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_modify_strict_priority_get(obj, &val16);
    out += writer(cookie, "priority=");
    out += LOCI_SHOW_u16_priority(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_modify_strict_buffer_id_get(obj, &val32);
    out += writer(cookie, "buffer_id=");
    out += LOCI_SHOW_u32_buffer_id(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_modify_strict_out_port_get(obj, &port_no);
    out += writer(cookie, "out_port=");
    out += LOCI_SHOW_port_no_out_port(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_flow_modify_strict_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    out += writer(cookie, "of_action_t={ ");
    of_flow_modify_strict_actions_bind(obj, &list);
    OF_LIST_ACTION_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_flow_removed_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_flow_removed_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_match_t match;
    uint64_t val64;
    uint16_t val16;
    uint8_t val8;

    of_flow_removed_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_removed_match_get(obj, &match);
    out += writer(cookie, "match=");
    out += LOCI_SHOW_match_match(writer, cookie, match);
    out += writer(cookie, " ");

    of_flow_removed_cookie_get(obj, &val64);
    out += writer(cookie, "cookie=");
    out += LOCI_SHOW_u64_cookie(writer, cookie, val64);
    out += writer(cookie, " ");

    of_flow_removed_priority_get(obj, &val16);
    out += writer(cookie, "priority=");
    out += LOCI_SHOW_u16_priority(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_removed_reason_get(obj, &val8);
    out += writer(cookie, "reason=");
    out += LOCI_SHOW_u8_reason(writer, cookie, val8);
    out += writer(cookie, " ");

    of_flow_removed_duration_sec_get(obj, &val32);
    out += writer(cookie, "duration_sec=");
    out += LOCI_SHOW_u32_duration_sec(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_removed_duration_nsec_get(obj, &val32);
    out += writer(cookie, "duration_nsec=");
    out += LOCI_SHOW_u32_duration_nsec(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_removed_idle_timeout_get(obj, &val16);
    out += writer(cookie, "idle_timeout=");
    out += LOCI_SHOW_u16_idle_timeout(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_removed_packet_count_get(obj, &val64);
    out += writer(cookie, "packet_count=");
    out += LOCI_SHOW_u64_packet_count(writer, cookie, val64);
    out += writer(cookie, " ");

    of_flow_removed_byte_count_get(obj, &val64);
    out += writer(cookie, "byte_count=");
    out += LOCI_SHOW_u64_byte_count(writer, cookie, val64);
    out += writer(cookie, " ");

    return out;
}

int
of_flow_stats_reply_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_flow_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_list_flow_stats_entry_t list;
    of_flow_stats_entry_t elt;
    int rv;

    of_flow_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    out += writer(cookie, "of_flow_stats_entry_t={ ");
    of_flow_stats_reply_entries_bind(obj, &list);
    OF_LIST_FLOW_STATS_ENTRY_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_flow_stats_request_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_flow_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_match_t match;
    uint8_t val8;
    of_port_no_t port_no;

    of_flow_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_stats_request_match_get(obj, &match);
    out += writer(cookie, "match=");
    out += LOCI_SHOW_match_match(writer, cookie, match);
    out += writer(cookie, " ");

    of_flow_stats_request_table_id_get(obj, &val8);
    out += writer(cookie, "table_id=");
    out += LOCI_SHOW_u8_table_id(writer, cookie, val8);
    out += writer(cookie, " ");

    of_flow_stats_request_out_port_get(obj, &port_no);
    out += writer(cookie, "out_port=");
    out += LOCI_SHOW_port_no_out_port(writer, cookie, port_no);
    out += writer(cookie, " ");

    return out;
}

int
of_get_config_reply_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_get_config_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_get_config_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_get_config_reply_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    of_get_config_reply_miss_send_len_get(obj, &val16);
    out += writer(cookie, "miss_send_len=");
    out += LOCI_SHOW_u16_miss_send_len(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_get_config_request_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_get_config_request_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_get_config_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_hello_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_hello_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_hello_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_hello_failed_error_msg_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_hello_failed_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    of_hello_failed_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_hello_failed_error_msg_code_get(obj, &val16);
    out += writer(cookie, "code=");
    out += LOCI_SHOW_u16_code(writer, cookie, val16);
    out += writer(cookie, " ");

    of_hello_failed_error_msg_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_nicira_controller_role_reply_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_nicira_controller_role_reply_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_nicira_controller_role_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_nicira_controller_role_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_nicira_controller_role_reply_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_nicira_controller_role_reply_role_get(obj, &val32);
    out += writer(cookie, "role=");
    out += LOCI_SHOW_u32_role(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_nicira_controller_role_request_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_nicira_controller_role_request_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_nicira_controller_role_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_nicira_controller_role_request_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_nicira_controller_role_request_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_nicira_controller_role_request_role_get(obj, &val32);
    out += writer(cookie, "role=");
    out += LOCI_SHOW_u32_role(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_nicira_header_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_nicira_header_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_nicira_header_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_nicira_header_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_nicira_header_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_packet_in_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_packet_in_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_port_no_t port_no;
    uint8_t val8;
    of_octets_t octets;

    of_packet_in_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_packet_in_buffer_id_get(obj, &val32);
    out += writer(cookie, "buffer_id=");
    out += LOCI_SHOW_u32_buffer_id(writer, cookie, val32);
    out += writer(cookie, " ");

    of_packet_in_total_len_get(obj, &val16);
    out += writer(cookie, "total_len=");
    out += LOCI_SHOW_u16_total_len(writer, cookie, val16);
    out += writer(cookie, " ");

    of_packet_in_in_port_get(obj, &port_no);
    out += writer(cookie, "in_port=");
    out += LOCI_SHOW_port_no_in_port(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_packet_in_reason_get(obj, &val8);
    out += writer(cookie, "reason=");
    out += LOCI_SHOW_u8_reason(writer, cookie, val8);
    out += writer(cookie, " ");

    of_packet_in_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_packet_out_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_packet_out_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_port_no_t port_no;

    of_list_action_t list;
    of_action_t elt;
    int rv;
    of_octets_t octets;

    of_packet_out_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_packet_out_buffer_id_get(obj, &val32);
    out += writer(cookie, "buffer_id=");
    out += LOCI_SHOW_u32_buffer_id(writer, cookie, val32);
    out += writer(cookie, " ");

    of_packet_out_in_port_get(obj, &port_no);
    out += writer(cookie, "in_port=");
    out += LOCI_SHOW_port_no_in_port(writer, cookie, port_no);
    out += writer(cookie, " ");

    out += writer(cookie, "of_action_t={ ");
    of_packet_out_actions_bind(obj, &list);
    OF_LIST_ACTION_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    of_packet_out_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_port_mod_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_port_mod_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_port_no_t port_no;
    of_mac_addr_t mac_addr;

    of_port_mod_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_port_mod_port_no_get(obj, &port_no);
    out += writer(cookie, "port_no=");
    out += LOCI_SHOW_port_no_port_no(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_port_mod_hw_addr_get(obj, &mac_addr);
    out += writer(cookie, "hw_addr=");
    out += LOCI_SHOW_mac_hw_addr(writer, cookie, mac_addr);
    out += writer(cookie, " ");

    of_port_mod_config_get(obj, &val32);
    out += writer(cookie, "config=");
    out += LOCI_SHOW_u32_config(writer, cookie, val32);
    out += writer(cookie, " ");

    of_port_mod_mask_get(obj, &val32);
    out += writer(cookie, "mask=");
    out += LOCI_SHOW_u32_mask(writer, cookie, val32);
    out += writer(cookie, " ");

    of_port_mod_advertise_get(obj, &val32);
    out += writer(cookie, "advertise=");
    out += LOCI_SHOW_u32_advertise(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_port_mod_failed_error_msg_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_port_mod_failed_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    of_port_mod_failed_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_port_mod_failed_error_msg_code_get(obj, &val16);
    out += writer(cookie, "code=");
    out += LOCI_SHOW_u16_code(writer, cookie, val16);
    out += writer(cookie, " ");

    of_port_mod_failed_error_msg_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_port_stats_reply_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_port_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_list_port_stats_entry_t list;
    of_port_stats_entry_t elt;
    int rv;

    of_port_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_port_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    out += writer(cookie, "of_port_stats_entry_t={ ");
    of_port_stats_reply_entries_bind(obj, &list);
    OF_LIST_PORT_STATS_ENTRY_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_port_stats_request_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_port_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_port_no_t port_no;

    of_port_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_port_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    of_port_stats_request_port_no_get(obj, &port_no);
    out += writer(cookie, "port_no=");
    out += LOCI_SHOW_port_no_port_no(writer, cookie, port_no);
    out += writer(cookie, " ");

    return out;
}

int
of_port_status_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_port_status_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint8_t val8;

    of_port_desc_t port_desc;

    of_port_status_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_port_status_reason_get(obj, &val8);
    out += writer(cookie, "reason=");
    out += LOCI_SHOW_u8_reason(writer, cookie, val8);
    out += writer(cookie, " ");

    of_port_status_desc_bind(obj, &port_desc);
    out += of_port_desc_OF_VERSION_1_0_show(writer, cookie, &port_desc);

    return out;
}

int
of_queue_get_config_reply_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_queue_get_config_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_port_no_t port_no;

    of_list_packet_queue_t list;
    of_packet_queue_t elt;
    int rv;

    of_queue_get_config_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_queue_get_config_reply_port_get(obj, &port_no);
    out += writer(cookie, "port=");
    out += LOCI_SHOW_port_no_port(writer, cookie, port_no);
    out += writer(cookie, " ");

    out += writer(cookie, "of_packet_queue_t={ ");
    of_queue_get_config_reply_queues_bind(obj, &list);
    OF_LIST_PACKET_QUEUE_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_queue_get_config_request_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_queue_get_config_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_port_no_t port_no;

    of_queue_get_config_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_queue_get_config_request_port_get(obj, &port_no);
    out += writer(cookie, "port=");
    out += LOCI_SHOW_port_no_port(writer, cookie, port_no);
    out += writer(cookie, " ");

    return out;
}

int
of_queue_op_failed_error_msg_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_queue_op_failed_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    of_queue_op_failed_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_queue_op_failed_error_msg_code_get(obj, &val16);
    out += writer(cookie, "code=");
    out += LOCI_SHOW_u16_code(writer, cookie, val16);
    out += writer(cookie, " ");

    of_queue_op_failed_error_msg_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_queue_stats_reply_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_queue_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_list_queue_stats_entry_t list;
    of_queue_stats_entry_t elt;
    int rv;

    of_queue_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_queue_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    out += writer(cookie, "of_queue_stats_entry_t={ ");
    of_queue_stats_reply_entries_bind(obj, &list);
    OF_LIST_QUEUE_STATS_ENTRY_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_queue_stats_request_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_queue_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_port_no_t port_no;

    of_queue_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_queue_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    of_queue_stats_request_port_no_get(obj, &port_no);
    out += writer(cookie, "port_no=");
    out += LOCI_SHOW_port_no_port_no(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_queue_stats_request_queue_id_get(obj, &val32);
    out += writer(cookie, "queue_id=");
    out += LOCI_SHOW_u32_queue_id(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_set_config_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_set_config_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_set_config_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_set_config_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    of_set_config_miss_send_len_get(obj, &val16);
    out += writer(cookie, "miss_send_len=");
    out += LOCI_SHOW_u16_miss_send_len(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_stats_reply_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_stats_request_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_table_mod_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_table_mod_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint8_t val8;

    of_table_mod_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_table_mod_table_id_get(obj, &val8);
    out += writer(cookie, "table_id=");
    out += LOCI_SHOW_u8_table_id(writer, cookie, val8);
    out += writer(cookie, " ");

    of_table_mod_config_get(obj, &val32);
    out += writer(cookie, "config=");
    out += LOCI_SHOW_u32_config(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_table_stats_reply_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_table_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_list_table_stats_entry_t list;
    of_table_stats_entry_t elt;
    int rv;

    of_table_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_table_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    out += writer(cookie, "of_table_stats_entry_t={ ");
    of_table_stats_reply_entries_bind(obj, &list);
    OF_LIST_TABLE_STATS_ENTRY_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_table_stats_request_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_table_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_table_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_table_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_action_bsn_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_action_bsn_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_action_bsn_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_action_bsn_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_action_bsn_mirror_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_action_bsn_mirror_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint8_t val8;

    of_action_bsn_mirror_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_action_bsn_mirror_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_action_bsn_mirror_dest_port_get(obj, &val32);
    out += writer(cookie, "dest_port=");
    out += LOCI_SHOW_u32_dest_port(writer, cookie, val32);
    out += writer(cookie, " ");

    of_action_bsn_mirror_vlan_tag_get(obj, &val32);
    out += writer(cookie, "vlan_tag=");
    out += LOCI_SHOW_u32_vlan_tag(writer, cookie, val32);
    out += writer(cookie, " ");

    of_action_bsn_mirror_copy_stage_get(obj, &val8);
    out += writer(cookie, "copy_stage=");
    out += LOCI_SHOW_u8_copy_stage(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_action_bsn_set_tunnel_dst_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_action_bsn_set_tunnel_dst_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_action_bsn_set_tunnel_dst_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_action_bsn_set_tunnel_dst_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_action_bsn_set_tunnel_dst_dst_get(obj, &val32);
    out += writer(cookie, "dst=");
    out += LOCI_SHOW_u32_dst(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_action_enqueue_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_action_enqueue_t *obj)
{
    int out = 0;
    of_port_no_t port_no;
    uint32_t val32;

    of_action_enqueue_port_get(obj, &port_no);
    out += writer(cookie, "port=");
    out += LOCI_SHOW_port_no_port(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_action_enqueue_queue_id_get(obj, &val32);
    out += writer(cookie, "queue_id=");
    out += LOCI_SHOW_u32_queue_id(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_action_experimenter_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_action_experimenter_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_octets_t octets;

    of_action_experimenter_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_action_experimenter_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_action_header_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_action_header_t *obj)
{
    int out = 0;

    return out;
}

int
of_action_nicira_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_action_nicira_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_action_nicira_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_action_nicira_subtype_get(obj, &val16);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u16_subtype(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_action_nicira_dec_ttl_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_action_nicira_dec_ttl_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_action_nicira_dec_ttl_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_action_nicira_dec_ttl_subtype_get(obj, &val16);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u16_subtype(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_action_output_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_action_output_t *obj)
{
    int out = 0;
    of_port_no_t port_no;
    uint16_t val16;

    of_action_output_port_get(obj, &port_no);
    out += writer(cookie, "port=");
    out += LOCI_SHOW_port_no_port(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_action_output_max_len_get(obj, &val16);
    out += writer(cookie, "max_len=");
    out += LOCI_SHOW_u16_max_len(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_action_set_dl_dst_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_action_set_dl_dst_t *obj)
{
    int out = 0;
    of_mac_addr_t mac_addr;

    of_action_set_dl_dst_dl_addr_get(obj, &mac_addr);
    out += writer(cookie, "dl_addr=");
    out += LOCI_SHOW_mac_dl_addr(writer, cookie, mac_addr);
    out += writer(cookie, " ");

    return out;
}

int
of_action_set_dl_src_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_action_set_dl_src_t *obj)
{
    int out = 0;
    of_mac_addr_t mac_addr;

    of_action_set_dl_src_dl_addr_get(obj, &mac_addr);
    out += writer(cookie, "dl_addr=");
    out += LOCI_SHOW_mac_dl_addr(writer, cookie, mac_addr);
    out += writer(cookie, " ");

    return out;
}

int
of_action_set_nw_dst_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_action_set_nw_dst_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_action_set_nw_dst_nw_addr_get(obj, &val32);
    out += writer(cookie, "nw_addr=");
    out += LOCI_SHOW_u32_nw_addr(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_action_set_nw_src_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_action_set_nw_src_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_action_set_nw_src_nw_addr_get(obj, &val32);
    out += writer(cookie, "nw_addr=");
    out += LOCI_SHOW_u32_nw_addr(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_action_set_nw_tos_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_action_set_nw_tos_t *obj)
{
    int out = 0;
    uint8_t val8;

    of_action_set_nw_tos_nw_tos_get(obj, &val8);
    out += writer(cookie, "nw_tos=");
    out += LOCI_SHOW_u8_nw_tos(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_action_set_tp_dst_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_action_set_tp_dst_t *obj)
{
    int out = 0;
    uint16_t val16;

    of_action_set_tp_dst_tp_port_get(obj, &val16);
    out += writer(cookie, "tp_port=");
    out += LOCI_SHOW_u16_tp_port(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_action_set_tp_src_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_action_set_tp_src_t *obj)
{
    int out = 0;
    uint16_t val16;

    of_action_set_tp_src_tp_port_get(obj, &val16);
    out += writer(cookie, "tp_port=");
    out += LOCI_SHOW_u16_tp_port(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_action_set_vlan_pcp_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_action_set_vlan_pcp_t *obj)
{
    int out = 0;
    uint8_t val8;

    of_action_set_vlan_pcp_vlan_pcp_get(obj, &val8);
    out += writer(cookie, "vlan_pcp=");
    out += LOCI_SHOW_u8_vlan_pcp(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_action_set_vlan_vid_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_action_set_vlan_vid_t *obj)
{
    int out = 0;
    uint16_t val16;

    of_action_set_vlan_vid_vlan_vid_get(obj, &val16);
    out += writer(cookie, "vlan_vid=");
    out += LOCI_SHOW_u16_vlan_vid(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_action_strip_vlan_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_action_strip_vlan_t *obj)
{
    int out = 0;

    return out;
}

int
of_bsn_interface_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_bsn_interface_t *obj)
{
    int out = 0;
    of_mac_addr_t mac_addr;
    of_port_name_t port_name;
    of_ipv4_t ipv4;

    of_bsn_interface_hw_addr_get(obj, &mac_addr);
    out += writer(cookie, "hw_addr=");
    out += LOCI_SHOW_mac_hw_addr(writer, cookie, mac_addr);
    out += writer(cookie, " ");

    of_bsn_interface_name_get(obj, &port_name);
    out += writer(cookie, "name=");
    out += LOCI_SHOW_port_name_name(writer, cookie, port_name);
    out += writer(cookie, " ");

    of_bsn_interface_ipv4_addr_get(obj, &ipv4);
    out += writer(cookie, "ipv4_addr=");
    out += LOCI_SHOW_ipv4_ipv4_addr(writer, cookie, ipv4);
    out += writer(cookie, " ");

    of_bsn_interface_ipv4_netmask_get(obj, &ipv4);
    out += writer(cookie, "ipv4_netmask=");
    out += LOCI_SHOW_ipv4_ipv4_netmask(writer, cookie, ipv4);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_vport_header_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_bsn_vport_header_t *obj)
{
    int out = 0;

    return out;
}

int
of_bsn_vport_q_in_q_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_bsn_vport_q_in_q_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_port_name_t port_name;

    of_bsn_vport_q_in_q_port_no_get(obj, &val32);
    out += writer(cookie, "port_no=");
    out += LOCI_SHOW_u32_port_no(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_vport_q_in_q_ingress_tpid_get(obj, &val16);
    out += writer(cookie, "ingress_tpid=");
    out += LOCI_SHOW_u16_ingress_tpid(writer, cookie, val16);
    out += writer(cookie, " ");

    of_bsn_vport_q_in_q_ingress_vlan_id_get(obj, &val16);
    out += writer(cookie, "ingress_vlan_id=");
    out += LOCI_SHOW_u16_ingress_vlan_id(writer, cookie, val16);
    out += writer(cookie, " ");

    of_bsn_vport_q_in_q_egress_tpid_get(obj, &val16);
    out += writer(cookie, "egress_tpid=");
    out += LOCI_SHOW_u16_egress_tpid(writer, cookie, val16);
    out += writer(cookie, " ");

    of_bsn_vport_q_in_q_egress_vlan_id_get(obj, &val16);
    out += writer(cookie, "egress_vlan_id=");
    out += LOCI_SHOW_u16_egress_vlan_id(writer, cookie, val16);
    out += writer(cookie, " ");

    of_bsn_vport_q_in_q_if_name_get(obj, &port_name);
    out += writer(cookie, "if_name=");
    out += LOCI_SHOW_port_name_if_name(writer, cookie, port_name);
    out += writer(cookie, " ");

    return out;
}

int
of_flow_stats_entry_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_flow_stats_entry_t *obj)
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

    of_flow_stats_entry_table_id_get(obj, &val8);
    out += writer(cookie, "table_id=");
    out += LOCI_SHOW_u8_table_id(writer, cookie, val8);
    out += writer(cookie, " ");

    of_flow_stats_entry_match_get(obj, &match);
    out += writer(cookie, "match=");
    out += LOCI_SHOW_match_match(writer, cookie, match);
    out += writer(cookie, " ");

    of_flow_stats_entry_duration_sec_get(obj, &val32);
    out += writer(cookie, "duration_sec=");
    out += LOCI_SHOW_u32_duration_sec(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_stats_entry_duration_nsec_get(obj, &val32);
    out += writer(cookie, "duration_nsec=");
    out += LOCI_SHOW_u32_duration_nsec(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_stats_entry_priority_get(obj, &val16);
    out += writer(cookie, "priority=");
    out += LOCI_SHOW_u16_priority(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_stats_entry_idle_timeout_get(obj, &val16);
    out += writer(cookie, "idle_timeout=");
    out += LOCI_SHOW_u16_idle_timeout(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_stats_entry_hard_timeout_get(obj, &val16);
    out += writer(cookie, "hard_timeout=");
    out += LOCI_SHOW_u16_hard_timeout(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_stats_entry_cookie_get(obj, &val64);
    out += writer(cookie, "cookie=");
    out += LOCI_SHOW_u64_cookie(writer, cookie, val64);
    out += writer(cookie, " ");

    of_flow_stats_entry_packet_count_get(obj, &val64);
    out += writer(cookie, "packet_count=");
    out += LOCI_SHOW_u64_packet_count(writer, cookie, val64);
    out += writer(cookie, " ");

    of_flow_stats_entry_byte_count_get(obj, &val64);
    out += writer(cookie, "byte_count=");
    out += LOCI_SHOW_u64_byte_count(writer, cookie, val64);
    out += writer(cookie, " ");

    out += writer(cookie, "of_action_t={ ");
    of_flow_stats_entry_actions_bind(obj, &list);
    OF_LIST_ACTION_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_header_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_header_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_header_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_match_v1_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_match_v1_t *obj)
{
    int out = 0;
    of_wc_bmap_t wc_bmap;
    of_port_no_t port_no;
    of_mac_addr_t mac_addr;
    uint16_t val16;
    uint8_t val8;
    of_ipv4_t ipv4;

    of_match_v1_wildcards_get(obj, &wc_bmap);
    out += writer(cookie, "wildcards=");
    out += LOCI_SHOW_wc_bmap_wildcards(writer, cookie, wc_bmap);
    out += writer(cookie, " ");

    of_match_v1_in_port_get(obj, &port_no);
    out += writer(cookie, "in_port=");
    out += LOCI_SHOW_port_no_in_port(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_match_v1_eth_src_get(obj, &mac_addr);
    out += writer(cookie, "eth_src=");
    out += LOCI_SHOW_mac_eth_src(writer, cookie, mac_addr);
    out += writer(cookie, " ");

    of_match_v1_eth_dst_get(obj, &mac_addr);
    out += writer(cookie, "eth_dst=");
    out += LOCI_SHOW_mac_eth_dst(writer, cookie, mac_addr);
    out += writer(cookie, " ");

    of_match_v1_vlan_vid_get(obj, &val16);
    out += writer(cookie, "vlan_vid=");
    out += LOCI_SHOW_u16_vlan_vid(writer, cookie, val16);
    out += writer(cookie, " ");

    of_match_v1_vlan_pcp_get(obj, &val8);
    out += writer(cookie, "vlan_pcp=");
    out += LOCI_SHOW_u8_vlan_pcp(writer, cookie, val8);
    out += writer(cookie, " ");

    of_match_v1_eth_type_get(obj, &val16);
    out += writer(cookie, "eth_type=");
    out += LOCI_SHOW_u16_eth_type(writer, cookie, val16);
    out += writer(cookie, " ");

    of_match_v1_ip_dscp_get(obj, &val8);
    out += writer(cookie, "ip_dscp=");
    out += LOCI_SHOW_u8_ip_dscp(writer, cookie, val8);
    out += writer(cookie, " ");

    of_match_v1_ip_proto_get(obj, &val8);
    out += writer(cookie, "ip_proto=");
    out += LOCI_SHOW_u8_ip_proto(writer, cookie, val8);
    out += writer(cookie, " ");

    of_match_v1_ipv4_src_get(obj, &ipv4);
    out += writer(cookie, "ipv4_src=");
    out += LOCI_SHOW_ipv4_ipv4_src(writer, cookie, ipv4);
    out += writer(cookie, " ");

    of_match_v1_ipv4_dst_get(obj, &ipv4);
    out += writer(cookie, "ipv4_dst=");
    out += LOCI_SHOW_ipv4_ipv4_dst(writer, cookie, ipv4);
    out += writer(cookie, " ");

    of_match_v1_tcp_src_get(obj, &val16);
    out += writer(cookie, "tcp_src=");
    out += LOCI_SHOW_u16_tcp_src(writer, cookie, val16);
    out += writer(cookie, " ");

    of_match_v1_tcp_dst_get(obj, &val16);
    out += writer(cookie, "tcp_dst=");
    out += LOCI_SHOW_u16_tcp_dst(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_packet_queue_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_packet_queue_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_list_queue_prop_t list;
    of_queue_prop_t elt;
    int rv;

    of_packet_queue_queue_id_get(obj, &val32);
    out += writer(cookie, "queue_id=");
    out += LOCI_SHOW_u32_queue_id(writer, cookie, val32);
    out += writer(cookie, " ");

    out += writer(cookie, "of_queue_prop_t={ ");
    of_packet_queue_properties_bind(obj, &list);
    OF_LIST_QUEUE_PROP_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_port_desc_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_port_desc_t *obj)
{
    int out = 0;
    of_port_no_t port_no;
    of_mac_addr_t mac_addr;
    of_port_name_t port_name;
    uint32_t val32;

    of_port_desc_port_no_get(obj, &port_no);
    out += writer(cookie, "port_no=");
    out += LOCI_SHOW_port_no_port_no(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_port_desc_hw_addr_get(obj, &mac_addr);
    out += writer(cookie, "hw_addr=");
    out += LOCI_SHOW_mac_hw_addr(writer, cookie, mac_addr);
    out += writer(cookie, " ");

    of_port_desc_name_get(obj, &port_name);
    out += writer(cookie, "name=");
    out += LOCI_SHOW_port_name_name(writer, cookie, port_name);
    out += writer(cookie, " ");

    of_port_desc_config_get(obj, &val32);
    out += writer(cookie, "config=");
    out += LOCI_SHOW_u32_config(writer, cookie, val32);
    out += writer(cookie, " ");

    of_port_desc_state_get(obj, &val32);
    out += writer(cookie, "state=");
    out += LOCI_SHOW_u32_state(writer, cookie, val32);
    out += writer(cookie, " ");

    of_port_desc_curr_get(obj, &val32);
    out += writer(cookie, "curr=");
    out += LOCI_SHOW_u32_curr(writer, cookie, val32);
    out += writer(cookie, " ");

    of_port_desc_advertised_get(obj, &val32);
    out += writer(cookie, "advertised=");
    out += LOCI_SHOW_u32_advertised(writer, cookie, val32);
    out += writer(cookie, " ");

    of_port_desc_supported_get(obj, &val32);
    out += writer(cookie, "supported=");
    out += LOCI_SHOW_u32_supported(writer, cookie, val32);
    out += writer(cookie, " ");

    of_port_desc_peer_get(obj, &val32);
    out += writer(cookie, "peer=");
    out += LOCI_SHOW_u32_peer(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_port_stats_entry_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_port_stats_entry_t *obj)
{
    int out = 0;
    of_port_no_t port_no;
    uint64_t val64;

    of_port_stats_entry_port_no_get(obj, &port_no);
    out += writer(cookie, "port_no=");
    out += LOCI_SHOW_port_no_port_no(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_port_stats_entry_rx_packets_get(obj, &val64);
    out += writer(cookie, "rx_packets=");
    out += LOCI_SHOW_u64_rx_packets(writer, cookie, val64);
    out += writer(cookie, " ");

    of_port_stats_entry_tx_packets_get(obj, &val64);
    out += writer(cookie, "tx_packets=");
    out += LOCI_SHOW_u64_tx_packets(writer, cookie, val64);
    out += writer(cookie, " ");

    of_port_stats_entry_rx_bytes_get(obj, &val64);
    out += writer(cookie, "rx_bytes=");
    out += LOCI_SHOW_u64_rx_bytes(writer, cookie, val64);
    out += writer(cookie, " ");

    of_port_stats_entry_tx_bytes_get(obj, &val64);
    out += writer(cookie, "tx_bytes=");
    out += LOCI_SHOW_u64_tx_bytes(writer, cookie, val64);
    out += writer(cookie, " ");

    of_port_stats_entry_rx_dropped_get(obj, &val64);
    out += writer(cookie, "rx_dropped=");
    out += LOCI_SHOW_u64_rx_dropped(writer, cookie, val64);
    out += writer(cookie, " ");

    of_port_stats_entry_tx_dropped_get(obj, &val64);
    out += writer(cookie, "tx_dropped=");
    out += LOCI_SHOW_u64_tx_dropped(writer, cookie, val64);
    out += writer(cookie, " ");

    of_port_stats_entry_rx_errors_get(obj, &val64);
    out += writer(cookie, "rx_errors=");
    out += LOCI_SHOW_u64_rx_errors(writer, cookie, val64);
    out += writer(cookie, " ");

    of_port_stats_entry_tx_errors_get(obj, &val64);
    out += writer(cookie, "tx_errors=");
    out += LOCI_SHOW_u64_tx_errors(writer, cookie, val64);
    out += writer(cookie, " ");

    of_port_stats_entry_rx_frame_err_get(obj, &val64);
    out += writer(cookie, "rx_frame_err=");
    out += LOCI_SHOW_u64_rx_frame_err(writer, cookie, val64);
    out += writer(cookie, " ");

    of_port_stats_entry_rx_over_err_get(obj, &val64);
    out += writer(cookie, "rx_over_err=");
    out += LOCI_SHOW_u64_rx_over_err(writer, cookie, val64);
    out += writer(cookie, " ");

    of_port_stats_entry_rx_crc_err_get(obj, &val64);
    out += writer(cookie, "rx_crc_err=");
    out += LOCI_SHOW_u64_rx_crc_err(writer, cookie, val64);
    out += writer(cookie, " ");

    of_port_stats_entry_collisions_get(obj, &val64);
    out += writer(cookie, "collisions=");
    out += LOCI_SHOW_u64_collisions(writer, cookie, val64);
    out += writer(cookie, " ");

    return out;
}

int
of_queue_prop_header_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_queue_prop_header_t *obj)
{
    int out = 0;

    return out;
}

int
of_queue_prop_min_rate_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_queue_prop_min_rate_t *obj)
{
    int out = 0;
    uint16_t val16;

    of_queue_prop_min_rate_rate_get(obj, &val16);
    out += writer(cookie, "rate=");
    out += LOCI_SHOW_u16_rate(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_queue_stats_entry_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_queue_stats_entry_t *obj)
{
    int out = 0;
    of_port_no_t port_no;
    uint32_t val32;
    uint64_t val64;

    of_queue_stats_entry_port_no_get(obj, &port_no);
    out += writer(cookie, "port_no=");
    out += LOCI_SHOW_port_no_port_no(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_queue_stats_entry_queue_id_get(obj, &val32);
    out += writer(cookie, "queue_id=");
    out += LOCI_SHOW_u32_queue_id(writer, cookie, val32);
    out += writer(cookie, " ");

    of_queue_stats_entry_tx_bytes_get(obj, &val64);
    out += writer(cookie, "tx_bytes=");
    out += LOCI_SHOW_u64_tx_bytes(writer, cookie, val64);
    out += writer(cookie, " ");

    of_queue_stats_entry_tx_packets_get(obj, &val64);
    out += writer(cookie, "tx_packets=");
    out += LOCI_SHOW_u64_tx_packets(writer, cookie, val64);
    out += writer(cookie, " ");

    of_queue_stats_entry_tx_errors_get(obj, &val64);
    out += writer(cookie, "tx_errors=");
    out += LOCI_SHOW_u64_tx_errors(writer, cookie, val64);
    out += writer(cookie, " ");

    return out;
}

int
of_table_stats_entry_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_table_stats_entry_t *obj)
{
    int out = 0;
    uint8_t val8;
    of_table_name_t table_name;
    of_wc_bmap_t wc_bmap;
    uint32_t val32;
    uint64_t val64;

    of_table_stats_entry_table_id_get(obj, &val8);
    out += writer(cookie, "table_id=");
    out += LOCI_SHOW_u8_table_id(writer, cookie, val8);
    out += writer(cookie, " ");

    of_table_stats_entry_name_get(obj, &table_name);
    out += writer(cookie, "name=");
    out += LOCI_SHOW_tab_name_name(writer, cookie, table_name);
    out += writer(cookie, " ");

    of_table_stats_entry_wildcards_get(obj, &wc_bmap);
    out += writer(cookie, "wildcards=");
    out += LOCI_SHOW_wc_bmap_wildcards(writer, cookie, wc_bmap);
    out += writer(cookie, " ");

    of_table_stats_entry_max_entries_get(obj, &val32);
    out += writer(cookie, "max_entries=");
    out += LOCI_SHOW_u32_max_entries(writer, cookie, val32);
    out += writer(cookie, " ");

    of_table_stats_entry_active_count_get(obj, &val32);
    out += writer(cookie, "active_count=");
    out += LOCI_SHOW_u32_active_count(writer, cookie, val32);
    out += writer(cookie, " ");

    of_table_stats_entry_lookup_count_get(obj, &val64);
    out += writer(cookie, "lookup_count=");
    out += LOCI_SHOW_u64_lookup_count(writer, cookie, val64);
    out += writer(cookie, " ");

    of_table_stats_entry_matched_count_get(obj, &val64);
    out += writer(cookie, "matched_count=");
    out += LOCI_SHOW_u64_matched_count(writer, cookie, val64);
    out += writer(cookie, " ");

    return out;
}

int
of_list_action_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_list_action_t *obj)
{
    int out = 0;

    return out;
}

int
of_list_bsn_interface_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_list_bsn_interface_t *obj)
{
    int out = 0;

    return out;
}

int
of_list_flow_stats_entry_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_list_flow_stats_entry_t *obj)
{
    int out = 0;

    return out;
}

int
of_list_packet_queue_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_list_packet_queue_t *obj)
{
    int out = 0;

    return out;
}

int
of_list_port_desc_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_list_port_desc_t *obj)
{
    int out = 0;

    return out;
}

int
of_list_port_stats_entry_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_list_port_stats_entry_t *obj)
{
    int out = 0;

    return out;
}

int
of_list_queue_prop_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_list_queue_prop_t *obj)
{
    int out = 0;

    return out;
}

int
of_list_queue_stats_entry_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_list_queue_stats_entry_t *obj)
{
    int out = 0;

    return out;
}

int
of_list_table_stats_entry_OF_VERSION_1_0_show(loci_writer_f writer, void* cookie, of_list_table_stats_entry_t *obj)
{
    int out = 0;

    return out;
}

int
of_aggregate_stats_reply_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_aggregate_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    uint64_t val64;

    of_aggregate_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_aggregate_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    of_aggregate_stats_reply_packet_count_get(obj, &val64);
    out += writer(cookie, "packet_count=");
    out += LOCI_SHOW_u64_packet_count(writer, cookie, val64);
    out += writer(cookie, " ");

    of_aggregate_stats_reply_byte_count_get(obj, &val64);
    out += writer(cookie, "byte_count=");
    out += LOCI_SHOW_u64_byte_count(writer, cookie, val64);
    out += writer(cookie, " ");

    of_aggregate_stats_reply_flow_count_get(obj, &val32);
    out += writer(cookie, "flow_count=");
    out += LOCI_SHOW_u32_flow_count(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_aggregate_stats_request_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_aggregate_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    uint8_t val8;
    of_port_no_t port_no;
    uint64_t val64;
    of_match_t match;

    of_aggregate_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_aggregate_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    of_aggregate_stats_request_table_id_get(obj, &val8);
    out += writer(cookie, "table_id=");
    out += LOCI_SHOW_u8_table_id(writer, cookie, val8);
    out += writer(cookie, " ");

    of_aggregate_stats_request_out_port_get(obj, &port_no);
    out += writer(cookie, "out_port=");
    out += LOCI_SHOW_port_no_out_port(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_aggregate_stats_request_out_group_get(obj, &val32);
    out += writer(cookie, "out_group=");
    out += LOCI_SHOW_u32_out_group(writer, cookie, val32);
    out += writer(cookie, " ");

    of_aggregate_stats_request_cookie_get(obj, &val64);
    out += writer(cookie, "cookie=");
    out += LOCI_SHOW_u64_cookie(writer, cookie, val64);
    out += writer(cookie, " ");

    of_aggregate_stats_request_cookie_mask_get(obj, &val64);
    out += writer(cookie, "cookie_mask=");
    out += LOCI_SHOW_u64_cookie_mask(writer, cookie, val64);
    out += writer(cookie, " ");

    of_aggregate_stats_request_match_get(obj, &match);
    out += writer(cookie, "match=");
    out += LOCI_SHOW_match_match(writer, cookie, match);
    out += writer(cookie, " ");

    return out;
}

int
of_bad_action_error_msg_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_bad_action_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    of_bad_action_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bad_action_error_msg_code_get(obj, &val16);
    out += writer(cookie, "code=");
    out += LOCI_SHOW_u16_code(writer, cookie, val16);
    out += writer(cookie, " ");

    of_bad_action_error_msg_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_bad_instruction_error_msg_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_bad_instruction_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    of_bad_instruction_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bad_instruction_error_msg_code_get(obj, &val16);
    out += writer(cookie, "code=");
    out += LOCI_SHOW_u16_code(writer, cookie, val16);
    out += writer(cookie, " ");

    of_bad_instruction_error_msg_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_bad_match_error_msg_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_bad_match_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    of_bad_match_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bad_match_error_msg_code_get(obj, &val16);
    out += writer(cookie, "code=");
    out += LOCI_SHOW_u16_code(writer, cookie, val16);
    out += writer(cookie, " ");

    of_bad_match_error_msg_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_bad_request_error_msg_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_bad_request_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    of_bad_request_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bad_request_error_msg_code_get(obj, &val16);
    out += writer(cookie, "code=");
    out += LOCI_SHOW_u16_code(writer, cookie, val16);
    out += writer(cookie, " ");

    of_bad_request_error_msg_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_barrier_reply_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_barrier_reply_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_barrier_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_barrier_request_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_barrier_request_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_barrier_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_bw_clear_data_reply_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_bsn_bw_clear_data_reply_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_bsn_bw_clear_data_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_bw_clear_data_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_bw_clear_data_reply_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_bw_clear_data_reply_status_get(obj, &val32);
    out += writer(cookie, "status=");
    out += LOCI_SHOW_u32_status(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_bw_clear_data_request_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_bsn_bw_clear_data_request_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_bsn_bw_clear_data_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_bw_clear_data_request_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_bw_clear_data_request_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_bw_enable_get_reply_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_bsn_bw_enable_get_reply_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_bsn_bw_enable_get_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_bw_enable_get_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_bw_enable_get_reply_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_bw_enable_get_reply_enabled_get(obj, &val32);
    out += writer(cookie, "enabled=");
    out += LOCI_SHOW_u32_enabled(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_bw_enable_get_request_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_bsn_bw_enable_get_request_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_bsn_bw_enable_get_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_bw_enable_get_request_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_bw_enable_get_request_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_bw_enable_set_reply_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_bsn_bw_enable_set_reply_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_bsn_bw_enable_set_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_bw_enable_set_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_bw_enable_set_reply_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_bw_enable_set_reply_enable_get(obj, &val32);
    out += writer(cookie, "enable=");
    out += LOCI_SHOW_u32_enable(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_bw_enable_set_reply_status_get(obj, &val32);
    out += writer(cookie, "status=");
    out += LOCI_SHOW_u32_status(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_bw_enable_set_request_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_bsn_bw_enable_set_request_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_bsn_bw_enable_set_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_bw_enable_set_request_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_bw_enable_set_request_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_bw_enable_set_request_enable_get(obj, &val32);
    out += writer(cookie, "enable=");
    out += LOCI_SHOW_u32_enable(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_get_interfaces_reply_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_bsn_get_interfaces_reply_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_list_bsn_interface_t list;
    of_bsn_interface_t elt;
    int rv;

    of_bsn_get_interfaces_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_get_interfaces_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_get_interfaces_reply_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    out += writer(cookie, "of_bsn_interface_t={ ");
    of_bsn_get_interfaces_reply_interfaces_bind(obj, &list);
    OF_LIST_BSN_INTERFACE_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_bsn_get_interfaces_request_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_bsn_get_interfaces_request_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_bsn_get_interfaces_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_get_interfaces_request_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_get_interfaces_request_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_get_mirroring_reply_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_bsn_get_mirroring_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint8_t val8;

    of_bsn_get_mirroring_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_get_mirroring_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_get_mirroring_reply_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_get_mirroring_reply_report_mirror_ports_get(obj, &val8);
    out += writer(cookie, "report_mirror_ports=");
    out += LOCI_SHOW_u8_report_mirror_ports(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_get_mirroring_request_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_bsn_get_mirroring_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint8_t val8;

    of_bsn_get_mirroring_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_get_mirroring_request_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_get_mirroring_request_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_get_mirroring_request_report_mirror_ports_get(obj, &val8);
    out += writer(cookie, "report_mirror_ports=");
    out += LOCI_SHOW_u8_report_mirror_ports(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_header_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_bsn_header_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_bsn_header_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_header_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_header_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_pdu_rx_reply_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_bsn_pdu_rx_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_port_no_t port_no;
    uint8_t val8;

    of_bsn_pdu_rx_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_pdu_rx_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_pdu_rx_reply_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_pdu_rx_reply_status_get(obj, &val32);
    out += writer(cookie, "status=");
    out += LOCI_SHOW_u32_status(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_pdu_rx_reply_port_no_get(obj, &port_no);
    out += writer(cookie, "port_no=");
    out += LOCI_SHOW_port_no_port_no(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_bsn_pdu_rx_reply_slot_num_get(obj, &val8);
    out += writer(cookie, "slot_num=");
    out += LOCI_SHOW_u8_slot_num(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_pdu_rx_request_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_bsn_pdu_rx_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_port_no_t port_no;
    uint8_t val8;
    of_octets_t octets;

    of_bsn_pdu_rx_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_pdu_rx_request_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_pdu_rx_request_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_pdu_rx_request_timeout_ms_get(obj, &val32);
    out += writer(cookie, "timeout_ms=");
    out += LOCI_SHOW_u32_timeout_ms(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_pdu_rx_request_port_no_get(obj, &port_no);
    out += writer(cookie, "port_no=");
    out += LOCI_SHOW_port_no_port_no(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_bsn_pdu_rx_request_slot_num_get(obj, &val8);
    out += writer(cookie, "slot_num=");
    out += LOCI_SHOW_u8_slot_num(writer, cookie, val8);
    out += writer(cookie, " ");

    of_bsn_pdu_rx_request_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_pdu_rx_timeout_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_bsn_pdu_rx_timeout_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_port_no_t port_no;
    uint8_t val8;

    of_bsn_pdu_rx_timeout_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_pdu_rx_timeout_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_pdu_rx_timeout_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_pdu_rx_timeout_port_no_get(obj, &port_no);
    out += writer(cookie, "port_no=");
    out += LOCI_SHOW_port_no_port_no(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_bsn_pdu_rx_timeout_slot_num_get(obj, &val8);
    out += writer(cookie, "slot_num=");
    out += LOCI_SHOW_u8_slot_num(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_pdu_tx_reply_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_bsn_pdu_tx_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_port_no_t port_no;
    uint8_t val8;

    of_bsn_pdu_tx_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_pdu_tx_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_pdu_tx_reply_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_pdu_tx_reply_status_get(obj, &val32);
    out += writer(cookie, "status=");
    out += LOCI_SHOW_u32_status(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_pdu_tx_reply_port_no_get(obj, &port_no);
    out += writer(cookie, "port_no=");
    out += LOCI_SHOW_port_no_port_no(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_bsn_pdu_tx_reply_slot_num_get(obj, &val8);
    out += writer(cookie, "slot_num=");
    out += LOCI_SHOW_u8_slot_num(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_pdu_tx_request_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_bsn_pdu_tx_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_port_no_t port_no;
    uint8_t val8;
    of_octets_t octets;

    of_bsn_pdu_tx_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_pdu_tx_request_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_pdu_tx_request_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_pdu_tx_request_tx_interval_ms_get(obj, &val32);
    out += writer(cookie, "tx_interval_ms=");
    out += LOCI_SHOW_u32_tx_interval_ms(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_pdu_tx_request_port_no_get(obj, &port_no);
    out += writer(cookie, "port_no=");
    out += LOCI_SHOW_port_no_port_no(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_bsn_pdu_tx_request_slot_num_get(obj, &val8);
    out += writer(cookie, "slot_num=");
    out += LOCI_SHOW_u8_slot_num(writer, cookie, val8);
    out += writer(cookie, " ");

    of_bsn_pdu_tx_request_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_set_mirroring_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_bsn_set_mirroring_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint8_t val8;

    of_bsn_set_mirroring_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_set_mirroring_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_set_mirroring_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_set_mirroring_report_mirror_ports_get(obj, &val8);
    out += writer(cookie, "report_mirror_ports=");
    out += LOCI_SHOW_u8_report_mirror_ports(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_set_pktin_suppression_reply_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_bsn_set_pktin_suppression_reply_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_bsn_set_pktin_suppression_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_set_pktin_suppression_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_set_pktin_suppression_reply_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_set_pktin_suppression_reply_status_get(obj, &val32);
    out += writer(cookie, "status=");
    out += LOCI_SHOW_u32_status(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_set_pktin_suppression_request_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_bsn_set_pktin_suppression_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint8_t val8;
    uint16_t val16;
    uint64_t val64;

    of_bsn_set_pktin_suppression_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_set_pktin_suppression_request_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_set_pktin_suppression_request_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_set_pktin_suppression_request_enabled_get(obj, &val8);
    out += writer(cookie, "enabled=");
    out += LOCI_SHOW_u8_enabled(writer, cookie, val8);
    out += writer(cookie, " ");

    of_bsn_set_pktin_suppression_request_idle_timeout_get(obj, &val16);
    out += writer(cookie, "idle_timeout=");
    out += LOCI_SHOW_u16_idle_timeout(writer, cookie, val16);
    out += writer(cookie, " ");

    of_bsn_set_pktin_suppression_request_hard_timeout_get(obj, &val16);
    out += writer(cookie, "hard_timeout=");
    out += LOCI_SHOW_u16_hard_timeout(writer, cookie, val16);
    out += writer(cookie, " ");

    of_bsn_set_pktin_suppression_request_priority_get(obj, &val16);
    out += writer(cookie, "priority=");
    out += LOCI_SHOW_u16_priority(writer, cookie, val16);
    out += writer(cookie, " ");

    of_bsn_set_pktin_suppression_request_cookie_get(obj, &val64);
    out += writer(cookie, "cookie=");
    out += LOCI_SHOW_u64_cookie(writer, cookie, val64);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_stats_reply_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_bsn_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_bsn_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    of_bsn_stats_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_stats_reply_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_stats_request_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_bsn_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_bsn_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    of_bsn_stats_request_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_stats_request_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_virtual_port_create_reply_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_bsn_virtual_port_create_reply_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_bsn_virtual_port_create_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_virtual_port_create_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_virtual_port_create_reply_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_virtual_port_create_reply_status_get(obj, &val32);
    out += writer(cookie, "status=");
    out += LOCI_SHOW_u32_status(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_virtual_port_create_reply_vport_no_get(obj, &val32);
    out += writer(cookie, "vport_no=");
    out += LOCI_SHOW_u32_vport_no(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_virtual_port_create_request_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_bsn_virtual_port_create_request_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_bsn_vport_q_in_q_t vport;

    of_bsn_virtual_port_create_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_virtual_port_create_request_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_virtual_port_create_request_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_virtual_port_create_request_vport_bind(obj, &vport);
    out += of_bsn_vport_q_in_q_OF_VERSION_1_1_show(writer, cookie, &vport);

    return out;
}

int
of_bsn_virtual_port_remove_reply_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_bsn_virtual_port_remove_reply_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_bsn_virtual_port_remove_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_virtual_port_remove_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_virtual_port_remove_reply_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_virtual_port_remove_reply_status_get(obj, &val32);
    out += writer(cookie, "status=");
    out += LOCI_SHOW_u32_status(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_virtual_port_remove_request_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_bsn_virtual_port_remove_request_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_bsn_virtual_port_remove_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_virtual_port_remove_request_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_virtual_port_remove_request_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_virtual_port_remove_request_vport_no_get(obj, &val32);
    out += writer(cookie, "vport_no=");
    out += LOCI_SHOW_u32_vport_no(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_desc_stats_reply_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_desc_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_desc_str_t desc_str;
    of_serial_num_t ser_num;

    of_desc_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_desc_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    of_desc_stats_reply_mfr_desc_get(obj, &desc_str);
    out += writer(cookie, "mfr_desc=");
    out += LOCI_SHOW_desc_str_mfr_desc(writer, cookie, desc_str);
    out += writer(cookie, " ");

    of_desc_stats_reply_hw_desc_get(obj, &desc_str);
    out += writer(cookie, "hw_desc=");
    out += LOCI_SHOW_desc_str_hw_desc(writer, cookie, desc_str);
    out += writer(cookie, " ");

    of_desc_stats_reply_sw_desc_get(obj, &desc_str);
    out += writer(cookie, "sw_desc=");
    out += LOCI_SHOW_desc_str_sw_desc(writer, cookie, desc_str);
    out += writer(cookie, " ");

    of_desc_stats_reply_serial_num_get(obj, &ser_num);
    out += writer(cookie, "serial_num=");
    out += LOCI_SHOW_ser_num_serial_num(writer, cookie, ser_num);
    out += writer(cookie, " ");

    of_desc_stats_reply_dp_desc_get(obj, &desc_str);
    out += writer(cookie, "dp_desc=");
    out += LOCI_SHOW_desc_str_dp_desc(writer, cookie, desc_str);
    out += writer(cookie, " ");

    return out;
}

int
of_desc_stats_request_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_desc_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_desc_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_desc_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_echo_reply_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_echo_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_octets_t octets;

    of_echo_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_echo_reply_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_echo_request_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_echo_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_octets_t octets;

    of_echo_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_echo_request_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_error_msg_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_experimenter_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_experimenter_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_octets_t octets;

    of_experimenter_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_experimenter_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_experimenter_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_experimenter_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_experimenter_stats_reply_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_experimenter_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    of_experimenter_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_experimenter_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    of_experimenter_stats_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_experimenter_stats_reply_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_experimenter_stats_request_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_experimenter_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    of_experimenter_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_experimenter_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    of_experimenter_stats_request_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_experimenter_stats_request_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_features_reply_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_features_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint64_t val64;
    uint8_t val8;

    of_list_port_desc_t list;
    of_port_desc_t elt;
    int rv;

    of_features_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_features_reply_datapath_id_get(obj, &val64);
    out += writer(cookie, "datapath_id=");
    out += LOCI_SHOW_u64_datapath_id(writer, cookie, val64);
    out += writer(cookie, " ");

    of_features_reply_n_buffers_get(obj, &val32);
    out += writer(cookie, "n_buffers=");
    out += LOCI_SHOW_u32_n_buffers(writer, cookie, val32);
    out += writer(cookie, " ");

    of_features_reply_n_tables_get(obj, &val8);
    out += writer(cookie, "n_tables=");
    out += LOCI_SHOW_u8_n_tables(writer, cookie, val8);
    out += writer(cookie, " ");

    of_features_reply_capabilities_get(obj, &val32);
    out += writer(cookie, "capabilities=");
    out += LOCI_SHOW_u32_capabilities(writer, cookie, val32);
    out += writer(cookie, " ");

    of_features_reply_reserved_get(obj, &val32);
    out += writer(cookie, "reserved=");
    out += LOCI_SHOW_u32_reserved(writer, cookie, val32);
    out += writer(cookie, " ");

    out += writer(cookie, "of_port_desc_t={ ");
    of_features_reply_ports_bind(obj, &list);
    OF_LIST_PORT_DESC_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_features_request_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_features_request_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_features_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_flow_add_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_flow_add_t *obj)
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

    of_flow_add_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_add_cookie_get(obj, &val64);
    out += writer(cookie, "cookie=");
    out += LOCI_SHOW_u64_cookie(writer, cookie, val64);
    out += writer(cookie, " ");

    of_flow_add_cookie_mask_get(obj, &val64);
    out += writer(cookie, "cookie_mask=");
    out += LOCI_SHOW_u64_cookie_mask(writer, cookie, val64);
    out += writer(cookie, " ");

    of_flow_add_table_id_get(obj, &val8);
    out += writer(cookie, "table_id=");
    out += LOCI_SHOW_u8_table_id(writer, cookie, val8);
    out += writer(cookie, " ");

    of_flow_add_idle_timeout_get(obj, &val16);
    out += writer(cookie, "idle_timeout=");
    out += LOCI_SHOW_u16_idle_timeout(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_add_hard_timeout_get(obj, &val16);
    out += writer(cookie, "hard_timeout=");
    out += LOCI_SHOW_u16_hard_timeout(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_add_priority_get(obj, &val16);
    out += writer(cookie, "priority=");
    out += LOCI_SHOW_u16_priority(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_add_buffer_id_get(obj, &val32);
    out += writer(cookie, "buffer_id=");
    out += LOCI_SHOW_u32_buffer_id(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_add_out_port_get(obj, &port_no);
    out += writer(cookie, "out_port=");
    out += LOCI_SHOW_port_no_out_port(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_flow_add_out_group_get(obj, &val32);
    out += writer(cookie, "out_group=");
    out += LOCI_SHOW_u32_out_group(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_add_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_add_match_get(obj, &match);
    out += writer(cookie, "match=");
    out += LOCI_SHOW_match_match(writer, cookie, match);
    out += writer(cookie, " ");

    out += writer(cookie, "of_instruction_t={ ");
    of_flow_add_instructions_bind(obj, &list);
    OF_LIST_INSTRUCTION_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_flow_delete_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_flow_delete_t *obj)
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

    of_flow_delete_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_delete_cookie_get(obj, &val64);
    out += writer(cookie, "cookie=");
    out += LOCI_SHOW_u64_cookie(writer, cookie, val64);
    out += writer(cookie, " ");

    of_flow_delete_cookie_mask_get(obj, &val64);
    out += writer(cookie, "cookie_mask=");
    out += LOCI_SHOW_u64_cookie_mask(writer, cookie, val64);
    out += writer(cookie, " ");

    of_flow_delete_table_id_get(obj, &val8);
    out += writer(cookie, "table_id=");
    out += LOCI_SHOW_u8_table_id(writer, cookie, val8);
    out += writer(cookie, " ");

    of_flow_delete_idle_timeout_get(obj, &val16);
    out += writer(cookie, "idle_timeout=");
    out += LOCI_SHOW_u16_idle_timeout(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_delete_hard_timeout_get(obj, &val16);
    out += writer(cookie, "hard_timeout=");
    out += LOCI_SHOW_u16_hard_timeout(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_delete_priority_get(obj, &val16);
    out += writer(cookie, "priority=");
    out += LOCI_SHOW_u16_priority(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_delete_buffer_id_get(obj, &val32);
    out += writer(cookie, "buffer_id=");
    out += LOCI_SHOW_u32_buffer_id(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_delete_out_port_get(obj, &port_no);
    out += writer(cookie, "out_port=");
    out += LOCI_SHOW_port_no_out_port(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_flow_delete_out_group_get(obj, &val32);
    out += writer(cookie, "out_group=");
    out += LOCI_SHOW_u32_out_group(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_delete_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_delete_match_get(obj, &match);
    out += writer(cookie, "match=");
    out += LOCI_SHOW_match_match(writer, cookie, match);
    out += writer(cookie, " ");

    out += writer(cookie, "of_instruction_t={ ");
    of_flow_delete_instructions_bind(obj, &list);
    OF_LIST_INSTRUCTION_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_flow_delete_strict_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_flow_delete_strict_t *obj)
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

    of_flow_delete_strict_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_delete_strict_cookie_get(obj, &val64);
    out += writer(cookie, "cookie=");
    out += LOCI_SHOW_u64_cookie(writer, cookie, val64);
    out += writer(cookie, " ");

    of_flow_delete_strict_cookie_mask_get(obj, &val64);
    out += writer(cookie, "cookie_mask=");
    out += LOCI_SHOW_u64_cookie_mask(writer, cookie, val64);
    out += writer(cookie, " ");

    of_flow_delete_strict_table_id_get(obj, &val8);
    out += writer(cookie, "table_id=");
    out += LOCI_SHOW_u8_table_id(writer, cookie, val8);
    out += writer(cookie, " ");

    of_flow_delete_strict_idle_timeout_get(obj, &val16);
    out += writer(cookie, "idle_timeout=");
    out += LOCI_SHOW_u16_idle_timeout(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_delete_strict_hard_timeout_get(obj, &val16);
    out += writer(cookie, "hard_timeout=");
    out += LOCI_SHOW_u16_hard_timeout(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_delete_strict_priority_get(obj, &val16);
    out += writer(cookie, "priority=");
    out += LOCI_SHOW_u16_priority(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_delete_strict_buffer_id_get(obj, &val32);
    out += writer(cookie, "buffer_id=");
    out += LOCI_SHOW_u32_buffer_id(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_delete_strict_out_port_get(obj, &port_no);
    out += writer(cookie, "out_port=");
    out += LOCI_SHOW_port_no_out_port(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_flow_delete_strict_out_group_get(obj, &val32);
    out += writer(cookie, "out_group=");
    out += LOCI_SHOW_u32_out_group(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_delete_strict_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_delete_strict_match_get(obj, &match);
    out += writer(cookie, "match=");
    out += LOCI_SHOW_match_match(writer, cookie, match);
    out += writer(cookie, " ");

    out += writer(cookie, "of_instruction_t={ ");
    of_flow_delete_strict_instructions_bind(obj, &list);
    OF_LIST_INSTRUCTION_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_flow_mod_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_flow_mod_t *obj)
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

    of_flow_mod_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_mod_cookie_get(obj, &val64);
    out += writer(cookie, "cookie=");
    out += LOCI_SHOW_u64_cookie(writer, cookie, val64);
    out += writer(cookie, " ");

    of_flow_mod_cookie_mask_get(obj, &val64);
    out += writer(cookie, "cookie_mask=");
    out += LOCI_SHOW_u64_cookie_mask(writer, cookie, val64);
    out += writer(cookie, " ");

    of_flow_mod_table_id_get(obj, &val8);
    out += writer(cookie, "table_id=");
    out += LOCI_SHOW_u8_table_id(writer, cookie, val8);
    out += writer(cookie, " ");

    of_flow_mod_idle_timeout_get(obj, &val16);
    out += writer(cookie, "idle_timeout=");
    out += LOCI_SHOW_u16_idle_timeout(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_mod_hard_timeout_get(obj, &val16);
    out += writer(cookie, "hard_timeout=");
    out += LOCI_SHOW_u16_hard_timeout(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_mod_priority_get(obj, &val16);
    out += writer(cookie, "priority=");
    out += LOCI_SHOW_u16_priority(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_mod_buffer_id_get(obj, &val32);
    out += writer(cookie, "buffer_id=");
    out += LOCI_SHOW_u32_buffer_id(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_mod_out_port_get(obj, &port_no);
    out += writer(cookie, "out_port=");
    out += LOCI_SHOW_port_no_out_port(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_flow_mod_out_group_get(obj, &val32);
    out += writer(cookie, "out_group=");
    out += LOCI_SHOW_u32_out_group(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_mod_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_mod_match_get(obj, &match);
    out += writer(cookie, "match=");
    out += LOCI_SHOW_match_match(writer, cookie, match);
    out += writer(cookie, " ");

    out += writer(cookie, "of_instruction_t={ ");
    of_flow_mod_instructions_bind(obj, &list);
    OF_LIST_INSTRUCTION_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_flow_mod_failed_error_msg_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_flow_mod_failed_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    of_flow_mod_failed_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_mod_failed_error_msg_code_get(obj, &val16);
    out += writer(cookie, "code=");
    out += LOCI_SHOW_u16_code(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_mod_failed_error_msg_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_flow_modify_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_flow_modify_t *obj)
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

    of_flow_modify_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_modify_cookie_get(obj, &val64);
    out += writer(cookie, "cookie=");
    out += LOCI_SHOW_u64_cookie(writer, cookie, val64);
    out += writer(cookie, " ");

    of_flow_modify_cookie_mask_get(obj, &val64);
    out += writer(cookie, "cookie_mask=");
    out += LOCI_SHOW_u64_cookie_mask(writer, cookie, val64);
    out += writer(cookie, " ");

    of_flow_modify_table_id_get(obj, &val8);
    out += writer(cookie, "table_id=");
    out += LOCI_SHOW_u8_table_id(writer, cookie, val8);
    out += writer(cookie, " ");

    of_flow_modify_idle_timeout_get(obj, &val16);
    out += writer(cookie, "idle_timeout=");
    out += LOCI_SHOW_u16_idle_timeout(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_modify_hard_timeout_get(obj, &val16);
    out += writer(cookie, "hard_timeout=");
    out += LOCI_SHOW_u16_hard_timeout(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_modify_priority_get(obj, &val16);
    out += writer(cookie, "priority=");
    out += LOCI_SHOW_u16_priority(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_modify_buffer_id_get(obj, &val32);
    out += writer(cookie, "buffer_id=");
    out += LOCI_SHOW_u32_buffer_id(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_modify_out_port_get(obj, &port_no);
    out += writer(cookie, "out_port=");
    out += LOCI_SHOW_port_no_out_port(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_flow_modify_out_group_get(obj, &val32);
    out += writer(cookie, "out_group=");
    out += LOCI_SHOW_u32_out_group(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_modify_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_modify_match_get(obj, &match);
    out += writer(cookie, "match=");
    out += LOCI_SHOW_match_match(writer, cookie, match);
    out += writer(cookie, " ");

    out += writer(cookie, "of_instruction_t={ ");
    of_flow_modify_instructions_bind(obj, &list);
    OF_LIST_INSTRUCTION_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_flow_modify_strict_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_flow_modify_strict_t *obj)
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

    of_flow_modify_strict_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_modify_strict_cookie_get(obj, &val64);
    out += writer(cookie, "cookie=");
    out += LOCI_SHOW_u64_cookie(writer, cookie, val64);
    out += writer(cookie, " ");

    of_flow_modify_strict_cookie_mask_get(obj, &val64);
    out += writer(cookie, "cookie_mask=");
    out += LOCI_SHOW_u64_cookie_mask(writer, cookie, val64);
    out += writer(cookie, " ");

    of_flow_modify_strict_table_id_get(obj, &val8);
    out += writer(cookie, "table_id=");
    out += LOCI_SHOW_u8_table_id(writer, cookie, val8);
    out += writer(cookie, " ");

    of_flow_modify_strict_idle_timeout_get(obj, &val16);
    out += writer(cookie, "idle_timeout=");
    out += LOCI_SHOW_u16_idle_timeout(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_modify_strict_hard_timeout_get(obj, &val16);
    out += writer(cookie, "hard_timeout=");
    out += LOCI_SHOW_u16_hard_timeout(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_modify_strict_priority_get(obj, &val16);
    out += writer(cookie, "priority=");
    out += LOCI_SHOW_u16_priority(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_modify_strict_buffer_id_get(obj, &val32);
    out += writer(cookie, "buffer_id=");
    out += LOCI_SHOW_u32_buffer_id(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_modify_strict_out_port_get(obj, &port_no);
    out += writer(cookie, "out_port=");
    out += LOCI_SHOW_port_no_out_port(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_flow_modify_strict_out_group_get(obj, &val32);
    out += writer(cookie, "out_group=");
    out += LOCI_SHOW_u32_out_group(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_modify_strict_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_modify_strict_match_get(obj, &match);
    out += writer(cookie, "match=");
    out += LOCI_SHOW_match_match(writer, cookie, match);
    out += writer(cookie, " ");

    out += writer(cookie, "of_instruction_t={ ");
    of_flow_modify_strict_instructions_bind(obj, &list);
    OF_LIST_INSTRUCTION_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_flow_removed_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_flow_removed_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint64_t val64;
    uint16_t val16;
    uint8_t val8;
    of_match_t match;

    of_flow_removed_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_removed_cookie_get(obj, &val64);
    out += writer(cookie, "cookie=");
    out += LOCI_SHOW_u64_cookie(writer, cookie, val64);
    out += writer(cookie, " ");

    of_flow_removed_priority_get(obj, &val16);
    out += writer(cookie, "priority=");
    out += LOCI_SHOW_u16_priority(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_removed_reason_get(obj, &val8);
    out += writer(cookie, "reason=");
    out += LOCI_SHOW_u8_reason(writer, cookie, val8);
    out += writer(cookie, " ");

    of_flow_removed_table_id_get(obj, &val8);
    out += writer(cookie, "table_id=");
    out += LOCI_SHOW_u8_table_id(writer, cookie, val8);
    out += writer(cookie, " ");

    of_flow_removed_duration_sec_get(obj, &val32);
    out += writer(cookie, "duration_sec=");
    out += LOCI_SHOW_u32_duration_sec(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_removed_duration_nsec_get(obj, &val32);
    out += writer(cookie, "duration_nsec=");
    out += LOCI_SHOW_u32_duration_nsec(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_removed_idle_timeout_get(obj, &val16);
    out += writer(cookie, "idle_timeout=");
    out += LOCI_SHOW_u16_idle_timeout(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_removed_packet_count_get(obj, &val64);
    out += writer(cookie, "packet_count=");
    out += LOCI_SHOW_u64_packet_count(writer, cookie, val64);
    out += writer(cookie, " ");

    of_flow_removed_byte_count_get(obj, &val64);
    out += writer(cookie, "byte_count=");
    out += LOCI_SHOW_u64_byte_count(writer, cookie, val64);
    out += writer(cookie, " ");

    of_flow_removed_match_get(obj, &match);
    out += writer(cookie, "match=");
    out += LOCI_SHOW_match_match(writer, cookie, match);
    out += writer(cookie, " ");

    return out;
}

int
of_flow_stats_reply_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_flow_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_list_flow_stats_entry_t list;
    of_flow_stats_entry_t elt;
    int rv;

    of_flow_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    out += writer(cookie, "of_flow_stats_entry_t={ ");
    of_flow_stats_reply_entries_bind(obj, &list);
    OF_LIST_FLOW_STATS_ENTRY_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_flow_stats_request_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_flow_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    uint8_t val8;
    of_port_no_t port_no;
    uint64_t val64;
    of_match_t match;

    of_flow_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_stats_request_table_id_get(obj, &val8);
    out += writer(cookie, "table_id=");
    out += LOCI_SHOW_u8_table_id(writer, cookie, val8);
    out += writer(cookie, " ");

    of_flow_stats_request_out_port_get(obj, &port_no);
    out += writer(cookie, "out_port=");
    out += LOCI_SHOW_port_no_out_port(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_flow_stats_request_out_group_get(obj, &val32);
    out += writer(cookie, "out_group=");
    out += LOCI_SHOW_u32_out_group(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_stats_request_cookie_get(obj, &val64);
    out += writer(cookie, "cookie=");
    out += LOCI_SHOW_u64_cookie(writer, cookie, val64);
    out += writer(cookie, " ");

    of_flow_stats_request_cookie_mask_get(obj, &val64);
    out += writer(cookie, "cookie_mask=");
    out += LOCI_SHOW_u64_cookie_mask(writer, cookie, val64);
    out += writer(cookie, " ");

    of_flow_stats_request_match_get(obj, &match);
    out += writer(cookie, "match=");
    out += LOCI_SHOW_match_match(writer, cookie, match);
    out += writer(cookie, " ");

    return out;
}

int
of_get_config_reply_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_get_config_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_get_config_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_get_config_reply_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    of_get_config_reply_miss_send_len_get(obj, &val16);
    out += writer(cookie, "miss_send_len=");
    out += LOCI_SHOW_u16_miss_send_len(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_get_config_request_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_get_config_request_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_get_config_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_group_desc_stats_reply_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_group_desc_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_list_group_desc_stats_entry_t list;
    of_group_desc_stats_entry_t elt;
    int rv;

    of_group_desc_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_group_desc_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    out += writer(cookie, "of_group_desc_stats_entry_t={ ");
    of_group_desc_stats_reply_entries_bind(obj, &list);
    OF_LIST_GROUP_DESC_STATS_ENTRY_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_group_desc_stats_request_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_group_desc_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_group_desc_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_group_desc_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_group_mod_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_group_mod_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    uint8_t val8;

    of_list_bucket_t list;
    of_bucket_t elt;
    int rv;

    of_group_mod_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_group_mod_command_get(obj, &val16);
    out += writer(cookie, "command=");
    out += LOCI_SHOW_u16_command(writer, cookie, val16);
    out += writer(cookie, " ");

    of_group_mod_group_type_get(obj, &val8);
    out += writer(cookie, "group_type=");
    out += LOCI_SHOW_u8_group_type(writer, cookie, val8);
    out += writer(cookie, " ");

    of_group_mod_group_id_get(obj, &val32);
    out += writer(cookie, "group_id=");
    out += LOCI_SHOW_u32_group_id(writer, cookie, val32);
    out += writer(cookie, " ");

    out += writer(cookie, "of_bucket_t={ ");
    of_group_mod_buckets_bind(obj, &list);
    OF_LIST_BUCKET_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_group_mod_failed_error_msg_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_group_mod_failed_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    of_group_mod_failed_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_group_mod_failed_error_msg_code_get(obj, &val16);
    out += writer(cookie, "code=");
    out += LOCI_SHOW_u16_code(writer, cookie, val16);
    out += writer(cookie, " ");

    of_group_mod_failed_error_msg_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_group_stats_reply_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_group_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_list_group_stats_entry_t list;
    of_group_stats_entry_t elt;
    int rv;

    of_group_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_group_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    out += writer(cookie, "of_group_stats_entry_t={ ");
    of_group_stats_reply_entries_bind(obj, &list);
    OF_LIST_GROUP_STATS_ENTRY_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_group_stats_request_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_group_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_group_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_group_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    of_group_stats_request_group_id_get(obj, &val32);
    out += writer(cookie, "group_id=");
    out += LOCI_SHOW_u32_group_id(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_hello_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_hello_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_hello_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_hello_failed_error_msg_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_hello_failed_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    of_hello_failed_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_hello_failed_error_msg_code_get(obj, &val16);
    out += writer(cookie, "code=");
    out += LOCI_SHOW_u16_code(writer, cookie, val16);
    out += writer(cookie, " ");

    of_hello_failed_error_msg_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_nicira_header_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_nicira_header_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_nicira_header_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_nicira_header_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_nicira_header_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_packet_in_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_packet_in_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_port_no_t port_no;
    uint16_t val16;
    uint8_t val8;
    of_octets_t octets;

    of_packet_in_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_packet_in_buffer_id_get(obj, &val32);
    out += writer(cookie, "buffer_id=");
    out += LOCI_SHOW_u32_buffer_id(writer, cookie, val32);
    out += writer(cookie, " ");

    of_packet_in_in_port_get(obj, &port_no);
    out += writer(cookie, "in_port=");
    out += LOCI_SHOW_port_no_in_port(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_packet_in_in_phy_port_get(obj, &port_no);
    out += writer(cookie, "in_phy_port=");
    out += LOCI_SHOW_port_no_in_phy_port(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_packet_in_total_len_get(obj, &val16);
    out += writer(cookie, "total_len=");
    out += LOCI_SHOW_u16_total_len(writer, cookie, val16);
    out += writer(cookie, " ");

    of_packet_in_reason_get(obj, &val8);
    out += writer(cookie, "reason=");
    out += LOCI_SHOW_u8_reason(writer, cookie, val8);
    out += writer(cookie, " ");

    of_packet_in_table_id_get(obj, &val8);
    out += writer(cookie, "table_id=");
    out += LOCI_SHOW_u8_table_id(writer, cookie, val8);
    out += writer(cookie, " ");

    of_packet_in_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_packet_out_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_packet_out_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_port_no_t port_no;

    of_list_action_t list;
    of_action_t elt;
    int rv;
    of_octets_t octets;

    of_packet_out_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_packet_out_buffer_id_get(obj, &val32);
    out += writer(cookie, "buffer_id=");
    out += LOCI_SHOW_u32_buffer_id(writer, cookie, val32);
    out += writer(cookie, " ");

    of_packet_out_in_port_get(obj, &port_no);
    out += writer(cookie, "in_port=");
    out += LOCI_SHOW_port_no_in_port(writer, cookie, port_no);
    out += writer(cookie, " ");

    out += writer(cookie, "of_action_t={ ");
    of_packet_out_actions_bind(obj, &list);
    OF_LIST_ACTION_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    of_packet_out_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_port_mod_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_port_mod_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_port_no_t port_no;
    of_mac_addr_t mac_addr;

    of_port_mod_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_port_mod_port_no_get(obj, &port_no);
    out += writer(cookie, "port_no=");
    out += LOCI_SHOW_port_no_port_no(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_port_mod_hw_addr_get(obj, &mac_addr);
    out += writer(cookie, "hw_addr=");
    out += LOCI_SHOW_mac_hw_addr(writer, cookie, mac_addr);
    out += writer(cookie, " ");

    of_port_mod_config_get(obj, &val32);
    out += writer(cookie, "config=");
    out += LOCI_SHOW_u32_config(writer, cookie, val32);
    out += writer(cookie, " ");

    of_port_mod_mask_get(obj, &val32);
    out += writer(cookie, "mask=");
    out += LOCI_SHOW_u32_mask(writer, cookie, val32);
    out += writer(cookie, " ");

    of_port_mod_advertise_get(obj, &val32);
    out += writer(cookie, "advertise=");
    out += LOCI_SHOW_u32_advertise(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_port_mod_failed_error_msg_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_port_mod_failed_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    of_port_mod_failed_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_port_mod_failed_error_msg_code_get(obj, &val16);
    out += writer(cookie, "code=");
    out += LOCI_SHOW_u16_code(writer, cookie, val16);
    out += writer(cookie, " ");

    of_port_mod_failed_error_msg_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_port_stats_reply_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_port_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_list_port_stats_entry_t list;
    of_port_stats_entry_t elt;
    int rv;

    of_port_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_port_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    out += writer(cookie, "of_port_stats_entry_t={ ");
    of_port_stats_reply_entries_bind(obj, &list);
    OF_LIST_PORT_STATS_ENTRY_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_port_stats_request_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_port_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_port_no_t port_no;

    of_port_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_port_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    of_port_stats_request_port_no_get(obj, &port_no);
    out += writer(cookie, "port_no=");
    out += LOCI_SHOW_port_no_port_no(writer, cookie, port_no);
    out += writer(cookie, " ");

    return out;
}

int
of_port_status_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_port_status_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint8_t val8;

    of_port_desc_t port_desc;

    of_port_status_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_port_status_reason_get(obj, &val8);
    out += writer(cookie, "reason=");
    out += LOCI_SHOW_u8_reason(writer, cookie, val8);
    out += writer(cookie, " ");

    of_port_status_desc_bind(obj, &port_desc);
    out += of_port_desc_OF_VERSION_1_1_show(writer, cookie, &port_desc);

    return out;
}

int
of_queue_get_config_reply_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_queue_get_config_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_port_no_t port_no;

    of_list_packet_queue_t list;
    of_packet_queue_t elt;
    int rv;

    of_queue_get_config_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_queue_get_config_reply_port_get(obj, &port_no);
    out += writer(cookie, "port=");
    out += LOCI_SHOW_port_no_port(writer, cookie, port_no);
    out += writer(cookie, " ");

    out += writer(cookie, "of_packet_queue_t={ ");
    of_queue_get_config_reply_queues_bind(obj, &list);
    OF_LIST_PACKET_QUEUE_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_queue_get_config_request_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_queue_get_config_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_port_no_t port_no;

    of_queue_get_config_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_queue_get_config_request_port_get(obj, &port_no);
    out += writer(cookie, "port=");
    out += LOCI_SHOW_port_no_port(writer, cookie, port_no);
    out += writer(cookie, " ");

    return out;
}

int
of_queue_op_failed_error_msg_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_queue_op_failed_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    of_queue_op_failed_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_queue_op_failed_error_msg_code_get(obj, &val16);
    out += writer(cookie, "code=");
    out += LOCI_SHOW_u16_code(writer, cookie, val16);
    out += writer(cookie, " ");

    of_queue_op_failed_error_msg_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_queue_stats_reply_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_queue_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_list_queue_stats_entry_t list;
    of_queue_stats_entry_t elt;
    int rv;

    of_queue_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_queue_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    out += writer(cookie, "of_queue_stats_entry_t={ ");
    of_queue_stats_reply_entries_bind(obj, &list);
    OF_LIST_QUEUE_STATS_ENTRY_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_queue_stats_request_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_queue_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_port_no_t port_no;

    of_queue_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_queue_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    of_queue_stats_request_port_no_get(obj, &port_no);
    out += writer(cookie, "port_no=");
    out += LOCI_SHOW_port_no_port_no(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_queue_stats_request_queue_id_get(obj, &val32);
    out += writer(cookie, "queue_id=");
    out += LOCI_SHOW_u32_queue_id(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_set_config_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_set_config_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_set_config_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_set_config_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    of_set_config_miss_send_len_get(obj, &val16);
    out += writer(cookie, "miss_send_len=");
    out += LOCI_SHOW_u16_miss_send_len(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_stats_reply_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_stats_request_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_switch_config_failed_error_msg_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_switch_config_failed_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    of_switch_config_failed_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_switch_config_failed_error_msg_code_get(obj, &val16);
    out += writer(cookie, "code=");
    out += LOCI_SHOW_u16_code(writer, cookie, val16);
    out += writer(cookie, " ");

    of_switch_config_failed_error_msg_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_table_mod_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_table_mod_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint8_t val8;

    of_table_mod_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_table_mod_table_id_get(obj, &val8);
    out += writer(cookie, "table_id=");
    out += LOCI_SHOW_u8_table_id(writer, cookie, val8);
    out += writer(cookie, " ");

    of_table_mod_config_get(obj, &val32);
    out += writer(cookie, "config=");
    out += LOCI_SHOW_u32_config(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_table_mod_failed_error_msg_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_table_mod_failed_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    of_table_mod_failed_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_table_mod_failed_error_msg_code_get(obj, &val16);
    out += writer(cookie, "code=");
    out += LOCI_SHOW_u16_code(writer, cookie, val16);
    out += writer(cookie, " ");

    of_table_mod_failed_error_msg_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_table_stats_reply_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_table_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_list_table_stats_entry_t list;
    of_table_stats_entry_t elt;
    int rv;

    of_table_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_table_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    out += writer(cookie, "of_table_stats_entry_t={ ");
    of_table_stats_reply_entries_bind(obj, &list);
    OF_LIST_TABLE_STATS_ENTRY_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_table_stats_request_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_table_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_table_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_table_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_action_bsn_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_action_bsn_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_action_bsn_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_action_bsn_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_action_bsn_mirror_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_action_bsn_mirror_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint8_t val8;

    of_action_bsn_mirror_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_action_bsn_mirror_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_action_bsn_mirror_dest_port_get(obj, &val32);
    out += writer(cookie, "dest_port=");
    out += LOCI_SHOW_u32_dest_port(writer, cookie, val32);
    out += writer(cookie, " ");

    of_action_bsn_mirror_vlan_tag_get(obj, &val32);
    out += writer(cookie, "vlan_tag=");
    out += LOCI_SHOW_u32_vlan_tag(writer, cookie, val32);
    out += writer(cookie, " ");

    of_action_bsn_mirror_copy_stage_get(obj, &val8);
    out += writer(cookie, "copy_stage=");
    out += LOCI_SHOW_u8_copy_stage(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_action_bsn_set_tunnel_dst_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_action_bsn_set_tunnel_dst_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_action_bsn_set_tunnel_dst_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_action_bsn_set_tunnel_dst_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_action_bsn_set_tunnel_dst_dst_get(obj, &val32);
    out += writer(cookie, "dst=");
    out += LOCI_SHOW_u32_dst(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_action_copy_ttl_in_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_action_copy_ttl_in_t *obj)
{
    int out = 0;

    return out;
}

int
of_action_copy_ttl_out_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_action_copy_ttl_out_t *obj)
{
    int out = 0;

    return out;
}

int
of_action_dec_mpls_ttl_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_action_dec_mpls_ttl_t *obj)
{
    int out = 0;

    return out;
}

int
of_action_dec_nw_ttl_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_action_dec_nw_ttl_t *obj)
{
    int out = 0;

    return out;
}

int
of_action_experimenter_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_action_experimenter_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_octets_t octets;

    of_action_experimenter_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_action_experimenter_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_action_group_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_action_group_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_action_group_group_id_get(obj, &val32);
    out += writer(cookie, "group_id=");
    out += LOCI_SHOW_u32_group_id(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_action_header_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_action_header_t *obj)
{
    int out = 0;

    return out;
}

int
of_action_nicira_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_action_nicira_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_action_nicira_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_action_nicira_subtype_get(obj, &val16);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u16_subtype(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_action_nicira_dec_ttl_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_action_nicira_dec_ttl_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_action_nicira_dec_ttl_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_action_nicira_dec_ttl_subtype_get(obj, &val16);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u16_subtype(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_action_output_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_action_output_t *obj)
{
    int out = 0;
    of_port_no_t port_no;
    uint16_t val16;

    of_action_output_port_get(obj, &port_no);
    out += writer(cookie, "port=");
    out += LOCI_SHOW_port_no_port(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_action_output_max_len_get(obj, &val16);
    out += writer(cookie, "max_len=");
    out += LOCI_SHOW_u16_max_len(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_action_pop_mpls_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_action_pop_mpls_t *obj)
{
    int out = 0;
    uint16_t val16;

    of_action_pop_mpls_ethertype_get(obj, &val16);
    out += writer(cookie, "ethertype=");
    out += LOCI_SHOW_u16_ethertype(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_action_pop_vlan_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_action_pop_vlan_t *obj)
{
    int out = 0;

    return out;
}

int
of_action_push_mpls_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_action_push_mpls_t *obj)
{
    int out = 0;
    uint16_t val16;

    of_action_push_mpls_ethertype_get(obj, &val16);
    out += writer(cookie, "ethertype=");
    out += LOCI_SHOW_u16_ethertype(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_action_push_vlan_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_action_push_vlan_t *obj)
{
    int out = 0;
    uint16_t val16;

    of_action_push_vlan_ethertype_get(obj, &val16);
    out += writer(cookie, "ethertype=");
    out += LOCI_SHOW_u16_ethertype(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_action_set_dl_dst_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_action_set_dl_dst_t *obj)
{
    int out = 0;
    of_mac_addr_t mac_addr;

    of_action_set_dl_dst_dl_addr_get(obj, &mac_addr);
    out += writer(cookie, "dl_addr=");
    out += LOCI_SHOW_mac_dl_addr(writer, cookie, mac_addr);
    out += writer(cookie, " ");

    return out;
}

int
of_action_set_dl_src_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_action_set_dl_src_t *obj)
{
    int out = 0;
    of_mac_addr_t mac_addr;

    of_action_set_dl_src_dl_addr_get(obj, &mac_addr);
    out += writer(cookie, "dl_addr=");
    out += LOCI_SHOW_mac_dl_addr(writer, cookie, mac_addr);
    out += writer(cookie, " ");

    return out;
}

int
of_action_set_mpls_label_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_action_set_mpls_label_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_action_set_mpls_label_mpls_label_get(obj, &val32);
    out += writer(cookie, "mpls_label=");
    out += LOCI_SHOW_u32_mpls_label(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_action_set_mpls_tc_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_action_set_mpls_tc_t *obj)
{
    int out = 0;
    uint8_t val8;

    of_action_set_mpls_tc_mpls_tc_get(obj, &val8);
    out += writer(cookie, "mpls_tc=");
    out += LOCI_SHOW_u8_mpls_tc(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_action_set_mpls_ttl_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_action_set_mpls_ttl_t *obj)
{
    int out = 0;
    uint8_t val8;

    of_action_set_mpls_ttl_mpls_ttl_get(obj, &val8);
    out += writer(cookie, "mpls_ttl=");
    out += LOCI_SHOW_u8_mpls_ttl(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_action_set_nw_dst_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_action_set_nw_dst_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_action_set_nw_dst_nw_addr_get(obj, &val32);
    out += writer(cookie, "nw_addr=");
    out += LOCI_SHOW_u32_nw_addr(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_action_set_nw_ecn_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_action_set_nw_ecn_t *obj)
{
    int out = 0;
    uint8_t val8;

    of_action_set_nw_ecn_nw_ecn_get(obj, &val8);
    out += writer(cookie, "nw_ecn=");
    out += LOCI_SHOW_u8_nw_ecn(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_action_set_nw_src_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_action_set_nw_src_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_action_set_nw_src_nw_addr_get(obj, &val32);
    out += writer(cookie, "nw_addr=");
    out += LOCI_SHOW_u32_nw_addr(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_action_set_nw_tos_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_action_set_nw_tos_t *obj)
{
    int out = 0;
    uint8_t val8;

    of_action_set_nw_tos_nw_tos_get(obj, &val8);
    out += writer(cookie, "nw_tos=");
    out += LOCI_SHOW_u8_nw_tos(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_action_set_nw_ttl_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_action_set_nw_ttl_t *obj)
{
    int out = 0;
    uint8_t val8;

    of_action_set_nw_ttl_nw_ttl_get(obj, &val8);
    out += writer(cookie, "nw_ttl=");
    out += LOCI_SHOW_u8_nw_ttl(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_action_set_queue_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_action_set_queue_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_action_set_queue_queue_id_get(obj, &val32);
    out += writer(cookie, "queue_id=");
    out += LOCI_SHOW_u32_queue_id(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_action_set_tp_dst_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_action_set_tp_dst_t *obj)
{
    int out = 0;
    uint16_t val16;

    of_action_set_tp_dst_tp_port_get(obj, &val16);
    out += writer(cookie, "tp_port=");
    out += LOCI_SHOW_u16_tp_port(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_action_set_tp_src_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_action_set_tp_src_t *obj)
{
    int out = 0;
    uint16_t val16;

    of_action_set_tp_src_tp_port_get(obj, &val16);
    out += writer(cookie, "tp_port=");
    out += LOCI_SHOW_u16_tp_port(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_action_set_vlan_pcp_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_action_set_vlan_pcp_t *obj)
{
    int out = 0;
    uint8_t val8;

    of_action_set_vlan_pcp_vlan_pcp_get(obj, &val8);
    out += writer(cookie, "vlan_pcp=");
    out += LOCI_SHOW_u8_vlan_pcp(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_action_set_vlan_vid_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_action_set_vlan_vid_t *obj)
{
    int out = 0;
    uint16_t val16;

    of_action_set_vlan_vid_vlan_vid_get(obj, &val16);
    out += writer(cookie, "vlan_vid=");
    out += LOCI_SHOW_u16_vlan_vid(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_interface_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_bsn_interface_t *obj)
{
    int out = 0;
    of_mac_addr_t mac_addr;
    of_port_name_t port_name;
    of_ipv4_t ipv4;

    of_bsn_interface_hw_addr_get(obj, &mac_addr);
    out += writer(cookie, "hw_addr=");
    out += LOCI_SHOW_mac_hw_addr(writer, cookie, mac_addr);
    out += writer(cookie, " ");

    of_bsn_interface_name_get(obj, &port_name);
    out += writer(cookie, "name=");
    out += LOCI_SHOW_port_name_name(writer, cookie, port_name);
    out += writer(cookie, " ");

    of_bsn_interface_ipv4_addr_get(obj, &ipv4);
    out += writer(cookie, "ipv4_addr=");
    out += LOCI_SHOW_ipv4_ipv4_addr(writer, cookie, ipv4);
    out += writer(cookie, " ");

    of_bsn_interface_ipv4_netmask_get(obj, &ipv4);
    out += writer(cookie, "ipv4_netmask=");
    out += LOCI_SHOW_ipv4_ipv4_netmask(writer, cookie, ipv4);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_vport_header_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_bsn_vport_header_t *obj)
{
    int out = 0;

    return out;
}

int
of_bsn_vport_q_in_q_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_bsn_vport_q_in_q_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_port_name_t port_name;

    of_bsn_vport_q_in_q_port_no_get(obj, &val32);
    out += writer(cookie, "port_no=");
    out += LOCI_SHOW_u32_port_no(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_vport_q_in_q_ingress_tpid_get(obj, &val16);
    out += writer(cookie, "ingress_tpid=");
    out += LOCI_SHOW_u16_ingress_tpid(writer, cookie, val16);
    out += writer(cookie, " ");

    of_bsn_vport_q_in_q_ingress_vlan_id_get(obj, &val16);
    out += writer(cookie, "ingress_vlan_id=");
    out += LOCI_SHOW_u16_ingress_vlan_id(writer, cookie, val16);
    out += writer(cookie, " ");

    of_bsn_vport_q_in_q_egress_tpid_get(obj, &val16);
    out += writer(cookie, "egress_tpid=");
    out += LOCI_SHOW_u16_egress_tpid(writer, cookie, val16);
    out += writer(cookie, " ");

    of_bsn_vport_q_in_q_egress_vlan_id_get(obj, &val16);
    out += writer(cookie, "egress_vlan_id=");
    out += LOCI_SHOW_u16_egress_vlan_id(writer, cookie, val16);
    out += writer(cookie, " ");

    of_bsn_vport_q_in_q_if_name_get(obj, &port_name);
    out += writer(cookie, "if_name=");
    out += LOCI_SHOW_port_name_if_name(writer, cookie, port_name);
    out += writer(cookie, " ");

    return out;
}

int
of_bucket_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_bucket_t *obj)
{
    int out = 0;
    uint16_t val16;
    of_port_no_t port_no;
    uint32_t val32;

    of_list_action_t list;
    of_action_t elt;
    int rv;

    of_bucket_weight_get(obj, &val16);
    out += writer(cookie, "weight=");
    out += LOCI_SHOW_u16_weight(writer, cookie, val16);
    out += writer(cookie, " ");

    of_bucket_watch_port_get(obj, &port_no);
    out += writer(cookie, "watch_port=");
    out += LOCI_SHOW_port_no_watch_port(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_bucket_watch_group_get(obj, &val32);
    out += writer(cookie, "watch_group=");
    out += LOCI_SHOW_u32_watch_group(writer, cookie, val32);
    out += writer(cookie, " ");

    out += writer(cookie, "of_action_t={ ");
    of_bucket_actions_bind(obj, &list);
    OF_LIST_ACTION_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_bucket_counter_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_bucket_counter_t *obj)
{
    int out = 0;
    uint64_t val64;

    of_bucket_counter_packet_count_get(obj, &val64);
    out += writer(cookie, "packet_count=");
    out += LOCI_SHOW_u64_packet_count(writer, cookie, val64);
    out += writer(cookie, " ");

    of_bucket_counter_byte_count_get(obj, &val64);
    out += writer(cookie, "byte_count=");
    out += LOCI_SHOW_u64_byte_count(writer, cookie, val64);
    out += writer(cookie, " ");

    return out;
}

int
of_flow_stats_entry_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_flow_stats_entry_t *obj)
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

    of_flow_stats_entry_table_id_get(obj, &val8);
    out += writer(cookie, "table_id=");
    out += LOCI_SHOW_u8_table_id(writer, cookie, val8);
    out += writer(cookie, " ");

    of_flow_stats_entry_duration_sec_get(obj, &val32);
    out += writer(cookie, "duration_sec=");
    out += LOCI_SHOW_u32_duration_sec(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_stats_entry_duration_nsec_get(obj, &val32);
    out += writer(cookie, "duration_nsec=");
    out += LOCI_SHOW_u32_duration_nsec(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_stats_entry_priority_get(obj, &val16);
    out += writer(cookie, "priority=");
    out += LOCI_SHOW_u16_priority(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_stats_entry_idle_timeout_get(obj, &val16);
    out += writer(cookie, "idle_timeout=");
    out += LOCI_SHOW_u16_idle_timeout(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_stats_entry_hard_timeout_get(obj, &val16);
    out += writer(cookie, "hard_timeout=");
    out += LOCI_SHOW_u16_hard_timeout(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_stats_entry_cookie_get(obj, &val64);
    out += writer(cookie, "cookie=");
    out += LOCI_SHOW_u64_cookie(writer, cookie, val64);
    out += writer(cookie, " ");

    of_flow_stats_entry_packet_count_get(obj, &val64);
    out += writer(cookie, "packet_count=");
    out += LOCI_SHOW_u64_packet_count(writer, cookie, val64);
    out += writer(cookie, " ");

    of_flow_stats_entry_byte_count_get(obj, &val64);
    out += writer(cookie, "byte_count=");
    out += LOCI_SHOW_u64_byte_count(writer, cookie, val64);
    out += writer(cookie, " ");

    of_flow_stats_entry_match_get(obj, &match);
    out += writer(cookie, "match=");
    out += LOCI_SHOW_match_match(writer, cookie, match);
    out += writer(cookie, " ");

    out += writer(cookie, "of_instruction_t={ ");
    of_flow_stats_entry_instructions_bind(obj, &list);
    OF_LIST_INSTRUCTION_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_group_desc_stats_entry_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_group_desc_stats_entry_t *obj)
{
    int out = 0;
    uint8_t val8;
    uint32_t val32;

    of_list_bucket_t list;
    of_bucket_t elt;
    int rv;

    of_group_desc_stats_entry_group_type_get(obj, &val8);
    out += writer(cookie, "group_type=");
    out += LOCI_SHOW_u8_group_type(writer, cookie, val8);
    out += writer(cookie, " ");

    of_group_desc_stats_entry_group_id_get(obj, &val32);
    out += writer(cookie, "group_id=");
    out += LOCI_SHOW_u32_group_id(writer, cookie, val32);
    out += writer(cookie, " ");

    out += writer(cookie, "of_bucket_t={ ");
    of_group_desc_stats_entry_buckets_bind(obj, &list);
    OF_LIST_BUCKET_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_group_stats_entry_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_group_stats_entry_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint64_t val64;

    of_list_bucket_counter_t list;
    of_bucket_counter_t elt;
    int rv;

    of_group_stats_entry_group_id_get(obj, &val32);
    out += writer(cookie, "group_id=");
    out += LOCI_SHOW_u32_group_id(writer, cookie, val32);
    out += writer(cookie, " ");

    of_group_stats_entry_ref_count_get(obj, &val32);
    out += writer(cookie, "ref_count=");
    out += LOCI_SHOW_u32_ref_count(writer, cookie, val32);
    out += writer(cookie, " ");

    of_group_stats_entry_packet_count_get(obj, &val64);
    out += writer(cookie, "packet_count=");
    out += LOCI_SHOW_u64_packet_count(writer, cookie, val64);
    out += writer(cookie, " ");

    of_group_stats_entry_byte_count_get(obj, &val64);
    out += writer(cookie, "byte_count=");
    out += LOCI_SHOW_u64_byte_count(writer, cookie, val64);
    out += writer(cookie, " ");

    out += writer(cookie, "of_bucket_counter_t={ ");
    of_group_stats_entry_bucket_stats_bind(obj, &list);
    OF_LIST_BUCKET_COUNTER_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_header_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_header_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_header_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_instruction_apply_actions_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_instruction_apply_actions_t *obj)
{
    int out = 0;

    of_list_action_t list;
    of_action_t elt;
    int rv;

    out += writer(cookie, "of_action_t={ ");
    of_instruction_apply_actions_actions_bind(obj, &list);
    OF_LIST_ACTION_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_instruction_clear_actions_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_instruction_clear_actions_t *obj)
{
    int out = 0;

    return out;
}

int
of_instruction_experimenter_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_instruction_experimenter_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_octets_t octets;

    of_instruction_experimenter_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_instruction_experimenter_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_instruction_goto_table_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_instruction_goto_table_t *obj)
{
    int out = 0;
    uint8_t val8;

    of_instruction_goto_table_table_id_get(obj, &val8);
    out += writer(cookie, "table_id=");
    out += LOCI_SHOW_u8_table_id(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_instruction_header_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_instruction_header_t *obj)
{
    int out = 0;

    return out;
}

int
of_instruction_write_actions_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_instruction_write_actions_t *obj)
{
    int out = 0;

    of_list_action_t list;
    of_action_t elt;
    int rv;

    out += writer(cookie, "of_action_t={ ");
    of_instruction_write_actions_actions_bind(obj, &list);
    OF_LIST_ACTION_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_instruction_write_metadata_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_instruction_write_metadata_t *obj)
{
    int out = 0;
    uint64_t val64;

    of_instruction_write_metadata_metadata_get(obj, &val64);
    out += writer(cookie, "metadata=");
    out += LOCI_SHOW_u64_metadata(writer, cookie, val64);
    out += writer(cookie, " ");

    of_instruction_write_metadata_metadata_mask_get(obj, &val64);
    out += writer(cookie, "metadata_mask=");
    out += LOCI_SHOW_u64_metadata_mask(writer, cookie, val64);
    out += writer(cookie, " ");

    return out;
}

int
of_match_v2_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_match_v2_t *obj)
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

    of_match_v2_in_port_get(obj, &port_no);
    out += writer(cookie, "in_port=");
    out += LOCI_SHOW_port_no_in_port(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_match_v2_wildcards_get(obj, &wc_bmap);
    out += writer(cookie, "wildcards=");
    out += LOCI_SHOW_wc_bmap_wildcards(writer, cookie, wc_bmap);
    out += writer(cookie, " ");

    of_match_v2_eth_src_get(obj, &mac_addr);
    out += writer(cookie, "eth_src=");
    out += LOCI_SHOW_mac_eth_src(writer, cookie, mac_addr);
    out += writer(cookie, " ");

    of_match_v2_eth_src_mask_get(obj, &mac_addr);
    out += writer(cookie, "eth_src_mask=");
    out += LOCI_SHOW_mac_eth_src_mask(writer, cookie, mac_addr);
    out += writer(cookie, " ");

    of_match_v2_eth_dst_get(obj, &mac_addr);
    out += writer(cookie, "eth_dst=");
    out += LOCI_SHOW_mac_eth_dst(writer, cookie, mac_addr);
    out += writer(cookie, " ");

    of_match_v2_eth_dst_mask_get(obj, &mac_addr);
    out += writer(cookie, "eth_dst_mask=");
    out += LOCI_SHOW_mac_eth_dst_mask(writer, cookie, mac_addr);
    out += writer(cookie, " ");

    of_match_v2_vlan_vid_get(obj, &val16);
    out += writer(cookie, "vlan_vid=");
    out += LOCI_SHOW_u16_vlan_vid(writer, cookie, val16);
    out += writer(cookie, " ");

    of_match_v2_vlan_pcp_get(obj, &val8);
    out += writer(cookie, "vlan_pcp=");
    out += LOCI_SHOW_u8_vlan_pcp(writer, cookie, val8);
    out += writer(cookie, " ");

    of_match_v2_eth_type_get(obj, &val16);
    out += writer(cookie, "eth_type=");
    out += LOCI_SHOW_u16_eth_type(writer, cookie, val16);
    out += writer(cookie, " ");

    of_match_v2_ip_dscp_get(obj, &val8);
    out += writer(cookie, "ip_dscp=");
    out += LOCI_SHOW_u8_ip_dscp(writer, cookie, val8);
    out += writer(cookie, " ");

    of_match_v2_ip_proto_get(obj, &val8);
    out += writer(cookie, "ip_proto=");
    out += LOCI_SHOW_u8_ip_proto(writer, cookie, val8);
    out += writer(cookie, " ");

    of_match_v2_ipv4_src_get(obj, &ipv4);
    out += writer(cookie, "ipv4_src=");
    out += LOCI_SHOW_ipv4_ipv4_src(writer, cookie, ipv4);
    out += writer(cookie, " ");

    of_match_v2_ipv4_src_mask_get(obj, &ipv4);
    out += writer(cookie, "ipv4_src_mask=");
    out += LOCI_SHOW_ipv4_ipv4_src_mask(writer, cookie, ipv4);
    out += writer(cookie, " ");

    of_match_v2_ipv4_dst_get(obj, &ipv4);
    out += writer(cookie, "ipv4_dst=");
    out += LOCI_SHOW_ipv4_ipv4_dst(writer, cookie, ipv4);
    out += writer(cookie, " ");

    of_match_v2_ipv4_dst_mask_get(obj, &ipv4);
    out += writer(cookie, "ipv4_dst_mask=");
    out += LOCI_SHOW_ipv4_ipv4_dst_mask(writer, cookie, ipv4);
    out += writer(cookie, " ");

    of_match_v2_tcp_src_get(obj, &val16);
    out += writer(cookie, "tcp_src=");
    out += LOCI_SHOW_u16_tcp_src(writer, cookie, val16);
    out += writer(cookie, " ");

    of_match_v2_tcp_dst_get(obj, &val16);
    out += writer(cookie, "tcp_dst=");
    out += LOCI_SHOW_u16_tcp_dst(writer, cookie, val16);
    out += writer(cookie, " ");

    of_match_v2_mpls_label_get(obj, &val32);
    out += writer(cookie, "mpls_label=");
    out += LOCI_SHOW_u32_mpls_label(writer, cookie, val32);
    out += writer(cookie, " ");

    of_match_v2_mpls_tc_get(obj, &val8);
    out += writer(cookie, "mpls_tc=");
    out += LOCI_SHOW_u8_mpls_tc(writer, cookie, val8);
    out += writer(cookie, " ");

    of_match_v2_metadata_get(obj, &val64);
    out += writer(cookie, "metadata=");
    out += LOCI_SHOW_u64_metadata(writer, cookie, val64);
    out += writer(cookie, " ");

    of_match_v2_metadata_mask_get(obj, &val64);
    out += writer(cookie, "metadata_mask=");
    out += LOCI_SHOW_u64_metadata_mask(writer, cookie, val64);
    out += writer(cookie, " ");

    return out;
}

int
of_packet_queue_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_packet_queue_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_list_queue_prop_t list;
    of_queue_prop_t elt;
    int rv;

    of_packet_queue_queue_id_get(obj, &val32);
    out += writer(cookie, "queue_id=");
    out += LOCI_SHOW_u32_queue_id(writer, cookie, val32);
    out += writer(cookie, " ");

    out += writer(cookie, "of_queue_prop_t={ ");
    of_packet_queue_properties_bind(obj, &list);
    OF_LIST_QUEUE_PROP_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_port_desc_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_port_desc_t *obj)
{
    int out = 0;
    of_port_no_t port_no;
    of_mac_addr_t mac_addr;
    of_port_name_t port_name;
    uint32_t val32;

    of_port_desc_port_no_get(obj, &port_no);
    out += writer(cookie, "port_no=");
    out += LOCI_SHOW_port_no_port_no(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_port_desc_hw_addr_get(obj, &mac_addr);
    out += writer(cookie, "hw_addr=");
    out += LOCI_SHOW_mac_hw_addr(writer, cookie, mac_addr);
    out += writer(cookie, " ");

    of_port_desc_name_get(obj, &port_name);
    out += writer(cookie, "name=");
    out += LOCI_SHOW_port_name_name(writer, cookie, port_name);
    out += writer(cookie, " ");

    of_port_desc_config_get(obj, &val32);
    out += writer(cookie, "config=");
    out += LOCI_SHOW_u32_config(writer, cookie, val32);
    out += writer(cookie, " ");

    of_port_desc_state_get(obj, &val32);
    out += writer(cookie, "state=");
    out += LOCI_SHOW_u32_state(writer, cookie, val32);
    out += writer(cookie, " ");

    of_port_desc_curr_get(obj, &val32);
    out += writer(cookie, "curr=");
    out += LOCI_SHOW_u32_curr(writer, cookie, val32);
    out += writer(cookie, " ");

    of_port_desc_advertised_get(obj, &val32);
    out += writer(cookie, "advertised=");
    out += LOCI_SHOW_u32_advertised(writer, cookie, val32);
    out += writer(cookie, " ");

    of_port_desc_supported_get(obj, &val32);
    out += writer(cookie, "supported=");
    out += LOCI_SHOW_u32_supported(writer, cookie, val32);
    out += writer(cookie, " ");

    of_port_desc_peer_get(obj, &val32);
    out += writer(cookie, "peer=");
    out += LOCI_SHOW_u32_peer(writer, cookie, val32);
    out += writer(cookie, " ");

    of_port_desc_curr_speed_get(obj, &val32);
    out += writer(cookie, "curr_speed=");
    out += LOCI_SHOW_u32_curr_speed(writer, cookie, val32);
    out += writer(cookie, " ");

    of_port_desc_max_speed_get(obj, &val32);
    out += writer(cookie, "max_speed=");
    out += LOCI_SHOW_u32_max_speed(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_port_stats_entry_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_port_stats_entry_t *obj)
{
    int out = 0;
    of_port_no_t port_no;
    uint64_t val64;

    of_port_stats_entry_port_no_get(obj, &port_no);
    out += writer(cookie, "port_no=");
    out += LOCI_SHOW_port_no_port_no(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_port_stats_entry_rx_packets_get(obj, &val64);
    out += writer(cookie, "rx_packets=");
    out += LOCI_SHOW_u64_rx_packets(writer, cookie, val64);
    out += writer(cookie, " ");

    of_port_stats_entry_tx_packets_get(obj, &val64);
    out += writer(cookie, "tx_packets=");
    out += LOCI_SHOW_u64_tx_packets(writer, cookie, val64);
    out += writer(cookie, " ");

    of_port_stats_entry_rx_bytes_get(obj, &val64);
    out += writer(cookie, "rx_bytes=");
    out += LOCI_SHOW_u64_rx_bytes(writer, cookie, val64);
    out += writer(cookie, " ");

    of_port_stats_entry_tx_bytes_get(obj, &val64);
    out += writer(cookie, "tx_bytes=");
    out += LOCI_SHOW_u64_tx_bytes(writer, cookie, val64);
    out += writer(cookie, " ");

    of_port_stats_entry_rx_dropped_get(obj, &val64);
    out += writer(cookie, "rx_dropped=");
    out += LOCI_SHOW_u64_rx_dropped(writer, cookie, val64);
    out += writer(cookie, " ");

    of_port_stats_entry_tx_dropped_get(obj, &val64);
    out += writer(cookie, "tx_dropped=");
    out += LOCI_SHOW_u64_tx_dropped(writer, cookie, val64);
    out += writer(cookie, " ");

    of_port_stats_entry_rx_errors_get(obj, &val64);
    out += writer(cookie, "rx_errors=");
    out += LOCI_SHOW_u64_rx_errors(writer, cookie, val64);
    out += writer(cookie, " ");

    of_port_stats_entry_tx_errors_get(obj, &val64);
    out += writer(cookie, "tx_errors=");
    out += LOCI_SHOW_u64_tx_errors(writer, cookie, val64);
    out += writer(cookie, " ");

    of_port_stats_entry_rx_frame_err_get(obj, &val64);
    out += writer(cookie, "rx_frame_err=");
    out += LOCI_SHOW_u64_rx_frame_err(writer, cookie, val64);
    out += writer(cookie, " ");

    of_port_stats_entry_rx_over_err_get(obj, &val64);
    out += writer(cookie, "rx_over_err=");
    out += LOCI_SHOW_u64_rx_over_err(writer, cookie, val64);
    out += writer(cookie, " ");

    of_port_stats_entry_rx_crc_err_get(obj, &val64);
    out += writer(cookie, "rx_crc_err=");
    out += LOCI_SHOW_u64_rx_crc_err(writer, cookie, val64);
    out += writer(cookie, " ");

    of_port_stats_entry_collisions_get(obj, &val64);
    out += writer(cookie, "collisions=");
    out += LOCI_SHOW_u64_collisions(writer, cookie, val64);
    out += writer(cookie, " ");

    return out;
}

int
of_queue_prop_header_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_queue_prop_header_t *obj)
{
    int out = 0;

    return out;
}

int
of_queue_prop_min_rate_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_queue_prop_min_rate_t *obj)
{
    int out = 0;
    uint16_t val16;

    of_queue_prop_min_rate_rate_get(obj, &val16);
    out += writer(cookie, "rate=");
    out += LOCI_SHOW_u16_rate(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_queue_stats_entry_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_queue_stats_entry_t *obj)
{
    int out = 0;
    of_port_no_t port_no;
    uint32_t val32;
    uint64_t val64;

    of_queue_stats_entry_port_no_get(obj, &port_no);
    out += writer(cookie, "port_no=");
    out += LOCI_SHOW_port_no_port_no(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_queue_stats_entry_queue_id_get(obj, &val32);
    out += writer(cookie, "queue_id=");
    out += LOCI_SHOW_u32_queue_id(writer, cookie, val32);
    out += writer(cookie, " ");

    of_queue_stats_entry_tx_bytes_get(obj, &val64);
    out += writer(cookie, "tx_bytes=");
    out += LOCI_SHOW_u64_tx_bytes(writer, cookie, val64);
    out += writer(cookie, " ");

    of_queue_stats_entry_tx_packets_get(obj, &val64);
    out += writer(cookie, "tx_packets=");
    out += LOCI_SHOW_u64_tx_packets(writer, cookie, val64);
    out += writer(cookie, " ");

    of_queue_stats_entry_tx_errors_get(obj, &val64);
    out += writer(cookie, "tx_errors=");
    out += LOCI_SHOW_u64_tx_errors(writer, cookie, val64);
    out += writer(cookie, " ");

    return out;
}

int
of_table_stats_entry_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_table_stats_entry_t *obj)
{
    int out = 0;
    uint8_t val8;
    of_table_name_t table_name;
    of_wc_bmap_t wc_bmap;
    of_match_bmap_t match_bmap;
    uint32_t val32;
    uint64_t val64;

    of_table_stats_entry_table_id_get(obj, &val8);
    out += writer(cookie, "table_id=");
    out += LOCI_SHOW_u8_table_id(writer, cookie, val8);
    out += writer(cookie, " ");

    of_table_stats_entry_name_get(obj, &table_name);
    out += writer(cookie, "name=");
    out += LOCI_SHOW_tab_name_name(writer, cookie, table_name);
    out += writer(cookie, " ");

    of_table_stats_entry_wildcards_get(obj, &wc_bmap);
    out += writer(cookie, "wildcards=");
    out += LOCI_SHOW_wc_bmap_wildcards(writer, cookie, wc_bmap);
    out += writer(cookie, " ");

    of_table_stats_entry_match_get(obj, &match_bmap);
    out += writer(cookie, "match=");
    out += LOCI_SHOW_match_bmap_match(writer, cookie, match_bmap);
    out += writer(cookie, " ");

    of_table_stats_entry_instructions_get(obj, &val32);
    out += writer(cookie, "instructions=");
    out += LOCI_SHOW_u32_instructions(writer, cookie, val32);
    out += writer(cookie, " ");

    of_table_stats_entry_write_actions_get(obj, &val32);
    out += writer(cookie, "write_actions=");
    out += LOCI_SHOW_u32_write_actions(writer, cookie, val32);
    out += writer(cookie, " ");

    of_table_stats_entry_apply_actions_get(obj, &val32);
    out += writer(cookie, "apply_actions=");
    out += LOCI_SHOW_u32_apply_actions(writer, cookie, val32);
    out += writer(cookie, " ");

    of_table_stats_entry_config_get(obj, &val32);
    out += writer(cookie, "config=");
    out += LOCI_SHOW_u32_config(writer, cookie, val32);
    out += writer(cookie, " ");

    of_table_stats_entry_max_entries_get(obj, &val32);
    out += writer(cookie, "max_entries=");
    out += LOCI_SHOW_u32_max_entries(writer, cookie, val32);
    out += writer(cookie, " ");

    of_table_stats_entry_active_count_get(obj, &val32);
    out += writer(cookie, "active_count=");
    out += LOCI_SHOW_u32_active_count(writer, cookie, val32);
    out += writer(cookie, " ");

    of_table_stats_entry_lookup_count_get(obj, &val64);
    out += writer(cookie, "lookup_count=");
    out += LOCI_SHOW_u64_lookup_count(writer, cookie, val64);
    out += writer(cookie, " ");

    of_table_stats_entry_matched_count_get(obj, &val64);
    out += writer(cookie, "matched_count=");
    out += LOCI_SHOW_u64_matched_count(writer, cookie, val64);
    out += writer(cookie, " ");

    return out;
}

int
of_list_action_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_list_action_t *obj)
{
    int out = 0;

    return out;
}

int
of_list_bsn_interface_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_list_bsn_interface_t *obj)
{
    int out = 0;

    return out;
}

int
of_list_bucket_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_list_bucket_t *obj)
{
    int out = 0;

    return out;
}

int
of_list_bucket_counter_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_list_bucket_counter_t *obj)
{
    int out = 0;

    return out;
}

int
of_list_flow_stats_entry_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_list_flow_stats_entry_t *obj)
{
    int out = 0;

    return out;
}

int
of_list_group_desc_stats_entry_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_list_group_desc_stats_entry_t *obj)
{
    int out = 0;

    return out;
}

int
of_list_group_stats_entry_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_list_group_stats_entry_t *obj)
{
    int out = 0;

    return out;
}

int
of_list_instruction_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_list_instruction_t *obj)
{
    int out = 0;

    return out;
}

int
of_list_packet_queue_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_list_packet_queue_t *obj)
{
    int out = 0;

    return out;
}

int
of_list_port_desc_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_list_port_desc_t *obj)
{
    int out = 0;

    return out;
}

int
of_list_port_stats_entry_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_list_port_stats_entry_t *obj)
{
    int out = 0;

    return out;
}

int
of_list_queue_prop_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_list_queue_prop_t *obj)
{
    int out = 0;

    return out;
}

int
of_list_queue_stats_entry_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_list_queue_stats_entry_t *obj)
{
    int out = 0;

    return out;
}

int
of_list_table_stats_entry_OF_VERSION_1_1_show(loci_writer_f writer, void* cookie, of_list_table_stats_entry_t *obj)
{
    int out = 0;

    return out;
}

int
of_aggregate_stats_reply_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_aggregate_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    uint64_t val64;

    of_aggregate_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_aggregate_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    of_aggregate_stats_reply_packet_count_get(obj, &val64);
    out += writer(cookie, "packet_count=");
    out += LOCI_SHOW_u64_packet_count(writer, cookie, val64);
    out += writer(cookie, " ");

    of_aggregate_stats_reply_byte_count_get(obj, &val64);
    out += writer(cookie, "byte_count=");
    out += LOCI_SHOW_u64_byte_count(writer, cookie, val64);
    out += writer(cookie, " ");

    of_aggregate_stats_reply_flow_count_get(obj, &val32);
    out += writer(cookie, "flow_count=");
    out += LOCI_SHOW_u32_flow_count(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_aggregate_stats_request_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_aggregate_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    uint8_t val8;
    of_port_no_t port_no;
    uint64_t val64;
    of_match_t match;

    of_aggregate_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_aggregate_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    of_aggregate_stats_request_table_id_get(obj, &val8);
    out += writer(cookie, "table_id=");
    out += LOCI_SHOW_u8_table_id(writer, cookie, val8);
    out += writer(cookie, " ");

    of_aggregate_stats_request_out_port_get(obj, &port_no);
    out += writer(cookie, "out_port=");
    out += LOCI_SHOW_port_no_out_port(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_aggregate_stats_request_out_group_get(obj, &val32);
    out += writer(cookie, "out_group=");
    out += LOCI_SHOW_u32_out_group(writer, cookie, val32);
    out += writer(cookie, " ");

    of_aggregate_stats_request_cookie_get(obj, &val64);
    out += writer(cookie, "cookie=");
    out += LOCI_SHOW_u64_cookie(writer, cookie, val64);
    out += writer(cookie, " ");

    of_aggregate_stats_request_cookie_mask_get(obj, &val64);
    out += writer(cookie, "cookie_mask=");
    out += LOCI_SHOW_u64_cookie_mask(writer, cookie, val64);
    out += writer(cookie, " ");

    of_aggregate_stats_request_match_get(obj, &match);
    out += writer(cookie, "match=");
    out += LOCI_SHOW_match_match(writer, cookie, match);
    out += writer(cookie, " ");

    return out;
}

int
of_bad_action_error_msg_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_bad_action_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    of_bad_action_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bad_action_error_msg_code_get(obj, &val16);
    out += writer(cookie, "code=");
    out += LOCI_SHOW_u16_code(writer, cookie, val16);
    out += writer(cookie, " ");

    of_bad_action_error_msg_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_bad_instruction_error_msg_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_bad_instruction_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    of_bad_instruction_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bad_instruction_error_msg_code_get(obj, &val16);
    out += writer(cookie, "code=");
    out += LOCI_SHOW_u16_code(writer, cookie, val16);
    out += writer(cookie, " ");

    of_bad_instruction_error_msg_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_bad_match_error_msg_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_bad_match_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    of_bad_match_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bad_match_error_msg_code_get(obj, &val16);
    out += writer(cookie, "code=");
    out += LOCI_SHOW_u16_code(writer, cookie, val16);
    out += writer(cookie, " ");

    of_bad_match_error_msg_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_bad_request_error_msg_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_bad_request_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    of_bad_request_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bad_request_error_msg_code_get(obj, &val16);
    out += writer(cookie, "code=");
    out += LOCI_SHOW_u16_code(writer, cookie, val16);
    out += writer(cookie, " ");

    of_bad_request_error_msg_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_barrier_reply_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_barrier_reply_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_barrier_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_barrier_request_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_barrier_request_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_barrier_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_bw_clear_data_reply_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_bsn_bw_clear_data_reply_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_bsn_bw_clear_data_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_bw_clear_data_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_bw_clear_data_reply_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_bw_clear_data_reply_status_get(obj, &val32);
    out += writer(cookie, "status=");
    out += LOCI_SHOW_u32_status(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_bw_clear_data_request_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_bsn_bw_clear_data_request_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_bsn_bw_clear_data_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_bw_clear_data_request_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_bw_clear_data_request_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_bw_enable_get_reply_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_bsn_bw_enable_get_reply_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_bsn_bw_enable_get_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_bw_enable_get_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_bw_enable_get_reply_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_bw_enable_get_reply_enabled_get(obj, &val32);
    out += writer(cookie, "enabled=");
    out += LOCI_SHOW_u32_enabled(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_bw_enable_get_request_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_bsn_bw_enable_get_request_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_bsn_bw_enable_get_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_bw_enable_get_request_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_bw_enable_get_request_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_bw_enable_set_reply_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_bsn_bw_enable_set_reply_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_bsn_bw_enable_set_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_bw_enable_set_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_bw_enable_set_reply_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_bw_enable_set_reply_enable_get(obj, &val32);
    out += writer(cookie, "enable=");
    out += LOCI_SHOW_u32_enable(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_bw_enable_set_reply_status_get(obj, &val32);
    out += writer(cookie, "status=");
    out += LOCI_SHOW_u32_status(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_bw_enable_set_request_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_bsn_bw_enable_set_request_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_bsn_bw_enable_set_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_bw_enable_set_request_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_bw_enable_set_request_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_bw_enable_set_request_enable_get(obj, &val32);
    out += writer(cookie, "enable=");
    out += LOCI_SHOW_u32_enable(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_get_interfaces_reply_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_bsn_get_interfaces_reply_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_list_bsn_interface_t list;
    of_bsn_interface_t elt;
    int rv;

    of_bsn_get_interfaces_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_get_interfaces_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_get_interfaces_reply_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    out += writer(cookie, "of_bsn_interface_t={ ");
    of_bsn_get_interfaces_reply_interfaces_bind(obj, &list);
    OF_LIST_BSN_INTERFACE_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_bsn_get_interfaces_request_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_bsn_get_interfaces_request_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_bsn_get_interfaces_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_get_interfaces_request_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_get_interfaces_request_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_get_mirroring_reply_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_bsn_get_mirroring_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint8_t val8;

    of_bsn_get_mirroring_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_get_mirroring_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_get_mirroring_reply_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_get_mirroring_reply_report_mirror_ports_get(obj, &val8);
    out += writer(cookie, "report_mirror_ports=");
    out += LOCI_SHOW_u8_report_mirror_ports(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_get_mirroring_request_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_bsn_get_mirroring_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint8_t val8;

    of_bsn_get_mirroring_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_get_mirroring_request_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_get_mirroring_request_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_get_mirroring_request_report_mirror_ports_get(obj, &val8);
    out += writer(cookie, "report_mirror_ports=");
    out += LOCI_SHOW_u8_report_mirror_ports(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_header_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_bsn_header_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_bsn_header_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_header_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_header_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_pdu_rx_reply_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_bsn_pdu_rx_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_port_no_t port_no;
    uint8_t val8;

    of_bsn_pdu_rx_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_pdu_rx_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_pdu_rx_reply_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_pdu_rx_reply_status_get(obj, &val32);
    out += writer(cookie, "status=");
    out += LOCI_SHOW_u32_status(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_pdu_rx_reply_port_no_get(obj, &port_no);
    out += writer(cookie, "port_no=");
    out += LOCI_SHOW_port_no_port_no(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_bsn_pdu_rx_reply_slot_num_get(obj, &val8);
    out += writer(cookie, "slot_num=");
    out += LOCI_SHOW_u8_slot_num(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_pdu_rx_request_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_bsn_pdu_rx_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_port_no_t port_no;
    uint8_t val8;
    of_octets_t octets;

    of_bsn_pdu_rx_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_pdu_rx_request_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_pdu_rx_request_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_pdu_rx_request_timeout_ms_get(obj, &val32);
    out += writer(cookie, "timeout_ms=");
    out += LOCI_SHOW_u32_timeout_ms(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_pdu_rx_request_port_no_get(obj, &port_no);
    out += writer(cookie, "port_no=");
    out += LOCI_SHOW_port_no_port_no(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_bsn_pdu_rx_request_slot_num_get(obj, &val8);
    out += writer(cookie, "slot_num=");
    out += LOCI_SHOW_u8_slot_num(writer, cookie, val8);
    out += writer(cookie, " ");

    of_bsn_pdu_rx_request_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_pdu_rx_timeout_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_bsn_pdu_rx_timeout_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_port_no_t port_no;
    uint8_t val8;

    of_bsn_pdu_rx_timeout_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_pdu_rx_timeout_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_pdu_rx_timeout_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_pdu_rx_timeout_port_no_get(obj, &port_no);
    out += writer(cookie, "port_no=");
    out += LOCI_SHOW_port_no_port_no(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_bsn_pdu_rx_timeout_slot_num_get(obj, &val8);
    out += writer(cookie, "slot_num=");
    out += LOCI_SHOW_u8_slot_num(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_pdu_tx_reply_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_bsn_pdu_tx_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_port_no_t port_no;
    uint8_t val8;

    of_bsn_pdu_tx_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_pdu_tx_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_pdu_tx_reply_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_pdu_tx_reply_status_get(obj, &val32);
    out += writer(cookie, "status=");
    out += LOCI_SHOW_u32_status(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_pdu_tx_reply_port_no_get(obj, &port_no);
    out += writer(cookie, "port_no=");
    out += LOCI_SHOW_port_no_port_no(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_bsn_pdu_tx_reply_slot_num_get(obj, &val8);
    out += writer(cookie, "slot_num=");
    out += LOCI_SHOW_u8_slot_num(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_pdu_tx_request_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_bsn_pdu_tx_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_port_no_t port_no;
    uint8_t val8;
    of_octets_t octets;

    of_bsn_pdu_tx_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_pdu_tx_request_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_pdu_tx_request_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_pdu_tx_request_tx_interval_ms_get(obj, &val32);
    out += writer(cookie, "tx_interval_ms=");
    out += LOCI_SHOW_u32_tx_interval_ms(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_pdu_tx_request_port_no_get(obj, &port_no);
    out += writer(cookie, "port_no=");
    out += LOCI_SHOW_port_no_port_no(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_bsn_pdu_tx_request_slot_num_get(obj, &val8);
    out += writer(cookie, "slot_num=");
    out += LOCI_SHOW_u8_slot_num(writer, cookie, val8);
    out += writer(cookie, " ");

    of_bsn_pdu_tx_request_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_set_mirroring_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_bsn_set_mirroring_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint8_t val8;

    of_bsn_set_mirroring_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_set_mirroring_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_set_mirroring_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_set_mirroring_report_mirror_ports_get(obj, &val8);
    out += writer(cookie, "report_mirror_ports=");
    out += LOCI_SHOW_u8_report_mirror_ports(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_set_pktin_suppression_reply_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_bsn_set_pktin_suppression_reply_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_bsn_set_pktin_suppression_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_set_pktin_suppression_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_set_pktin_suppression_reply_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_set_pktin_suppression_reply_status_get(obj, &val32);
    out += writer(cookie, "status=");
    out += LOCI_SHOW_u32_status(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_set_pktin_suppression_request_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_bsn_set_pktin_suppression_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint8_t val8;
    uint16_t val16;
    uint64_t val64;

    of_bsn_set_pktin_suppression_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_set_pktin_suppression_request_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_set_pktin_suppression_request_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_set_pktin_suppression_request_enabled_get(obj, &val8);
    out += writer(cookie, "enabled=");
    out += LOCI_SHOW_u8_enabled(writer, cookie, val8);
    out += writer(cookie, " ");

    of_bsn_set_pktin_suppression_request_idle_timeout_get(obj, &val16);
    out += writer(cookie, "idle_timeout=");
    out += LOCI_SHOW_u16_idle_timeout(writer, cookie, val16);
    out += writer(cookie, " ");

    of_bsn_set_pktin_suppression_request_hard_timeout_get(obj, &val16);
    out += writer(cookie, "hard_timeout=");
    out += LOCI_SHOW_u16_hard_timeout(writer, cookie, val16);
    out += writer(cookie, " ");

    of_bsn_set_pktin_suppression_request_priority_get(obj, &val16);
    out += writer(cookie, "priority=");
    out += LOCI_SHOW_u16_priority(writer, cookie, val16);
    out += writer(cookie, " ");

    of_bsn_set_pktin_suppression_request_cookie_get(obj, &val64);
    out += writer(cookie, "cookie=");
    out += LOCI_SHOW_u64_cookie(writer, cookie, val64);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_stats_reply_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_bsn_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_bsn_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    of_bsn_stats_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_stats_reply_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_stats_request_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_bsn_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_bsn_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    of_bsn_stats_request_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_stats_request_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_virtual_port_create_reply_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_bsn_virtual_port_create_reply_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_bsn_virtual_port_create_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_virtual_port_create_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_virtual_port_create_reply_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_virtual_port_create_reply_status_get(obj, &val32);
    out += writer(cookie, "status=");
    out += LOCI_SHOW_u32_status(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_virtual_port_create_reply_vport_no_get(obj, &val32);
    out += writer(cookie, "vport_no=");
    out += LOCI_SHOW_u32_vport_no(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_virtual_port_create_request_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_bsn_virtual_port_create_request_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_bsn_vport_q_in_q_t vport;

    of_bsn_virtual_port_create_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_virtual_port_create_request_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_virtual_port_create_request_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_virtual_port_create_request_vport_bind(obj, &vport);
    out += of_bsn_vport_q_in_q_OF_VERSION_1_2_show(writer, cookie, &vport);

    return out;
}

int
of_bsn_virtual_port_remove_reply_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_bsn_virtual_port_remove_reply_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_bsn_virtual_port_remove_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_virtual_port_remove_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_virtual_port_remove_reply_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_virtual_port_remove_reply_status_get(obj, &val32);
    out += writer(cookie, "status=");
    out += LOCI_SHOW_u32_status(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_virtual_port_remove_request_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_bsn_virtual_port_remove_request_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_bsn_virtual_port_remove_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_virtual_port_remove_request_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_virtual_port_remove_request_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_virtual_port_remove_request_vport_no_get(obj, &val32);
    out += writer(cookie, "vport_no=");
    out += LOCI_SHOW_u32_vport_no(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_desc_stats_reply_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_desc_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_desc_str_t desc_str;
    of_serial_num_t ser_num;

    of_desc_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_desc_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    of_desc_stats_reply_mfr_desc_get(obj, &desc_str);
    out += writer(cookie, "mfr_desc=");
    out += LOCI_SHOW_desc_str_mfr_desc(writer, cookie, desc_str);
    out += writer(cookie, " ");

    of_desc_stats_reply_hw_desc_get(obj, &desc_str);
    out += writer(cookie, "hw_desc=");
    out += LOCI_SHOW_desc_str_hw_desc(writer, cookie, desc_str);
    out += writer(cookie, " ");

    of_desc_stats_reply_sw_desc_get(obj, &desc_str);
    out += writer(cookie, "sw_desc=");
    out += LOCI_SHOW_desc_str_sw_desc(writer, cookie, desc_str);
    out += writer(cookie, " ");

    of_desc_stats_reply_serial_num_get(obj, &ser_num);
    out += writer(cookie, "serial_num=");
    out += LOCI_SHOW_ser_num_serial_num(writer, cookie, ser_num);
    out += writer(cookie, " ");

    of_desc_stats_reply_dp_desc_get(obj, &desc_str);
    out += writer(cookie, "dp_desc=");
    out += LOCI_SHOW_desc_str_dp_desc(writer, cookie, desc_str);
    out += writer(cookie, " ");

    return out;
}

int
of_desc_stats_request_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_desc_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_desc_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_desc_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_echo_reply_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_echo_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_octets_t octets;

    of_echo_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_echo_reply_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_echo_request_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_echo_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_octets_t octets;

    of_echo_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_echo_request_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_error_msg_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_experimenter_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_experimenter_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_octets_t octets;

    of_experimenter_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_experimenter_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_experimenter_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_experimenter_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_experimenter_error_msg_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_experimenter_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    of_experimenter_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_experimenter_error_msg_subtype_get(obj, &val16);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u16_subtype(writer, cookie, val16);
    out += writer(cookie, " ");

    of_experimenter_error_msg_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_experimenter_error_msg_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_experimenter_stats_reply_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_experimenter_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    of_experimenter_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_experimenter_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    of_experimenter_stats_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_experimenter_stats_reply_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_experimenter_stats_reply_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_experimenter_stats_request_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_experimenter_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    of_experimenter_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_experimenter_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    of_experimenter_stats_request_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_experimenter_stats_request_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_experimenter_stats_request_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_features_reply_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_features_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint64_t val64;
    uint8_t val8;

    of_list_port_desc_t list;
    of_port_desc_t elt;
    int rv;

    of_features_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_features_reply_datapath_id_get(obj, &val64);
    out += writer(cookie, "datapath_id=");
    out += LOCI_SHOW_u64_datapath_id(writer, cookie, val64);
    out += writer(cookie, " ");

    of_features_reply_n_buffers_get(obj, &val32);
    out += writer(cookie, "n_buffers=");
    out += LOCI_SHOW_u32_n_buffers(writer, cookie, val32);
    out += writer(cookie, " ");

    of_features_reply_n_tables_get(obj, &val8);
    out += writer(cookie, "n_tables=");
    out += LOCI_SHOW_u8_n_tables(writer, cookie, val8);
    out += writer(cookie, " ");

    of_features_reply_capabilities_get(obj, &val32);
    out += writer(cookie, "capabilities=");
    out += LOCI_SHOW_u32_capabilities(writer, cookie, val32);
    out += writer(cookie, " ");

    of_features_reply_reserved_get(obj, &val32);
    out += writer(cookie, "reserved=");
    out += LOCI_SHOW_u32_reserved(writer, cookie, val32);
    out += writer(cookie, " ");

    out += writer(cookie, "of_port_desc_t={ ");
    of_features_reply_ports_bind(obj, &list);
    OF_LIST_PORT_DESC_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_features_request_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_features_request_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_features_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_flow_add_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_flow_add_t *obj)
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

    of_flow_add_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_add_cookie_get(obj, &val64);
    out += writer(cookie, "cookie=");
    out += LOCI_SHOW_u64_cookie(writer, cookie, val64);
    out += writer(cookie, " ");

    of_flow_add_cookie_mask_get(obj, &val64);
    out += writer(cookie, "cookie_mask=");
    out += LOCI_SHOW_u64_cookie_mask(writer, cookie, val64);
    out += writer(cookie, " ");

    of_flow_add_table_id_get(obj, &val8);
    out += writer(cookie, "table_id=");
    out += LOCI_SHOW_u8_table_id(writer, cookie, val8);
    out += writer(cookie, " ");

    of_flow_add_idle_timeout_get(obj, &val16);
    out += writer(cookie, "idle_timeout=");
    out += LOCI_SHOW_u16_idle_timeout(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_add_hard_timeout_get(obj, &val16);
    out += writer(cookie, "hard_timeout=");
    out += LOCI_SHOW_u16_hard_timeout(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_add_priority_get(obj, &val16);
    out += writer(cookie, "priority=");
    out += LOCI_SHOW_u16_priority(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_add_buffer_id_get(obj, &val32);
    out += writer(cookie, "buffer_id=");
    out += LOCI_SHOW_u32_buffer_id(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_add_out_port_get(obj, &port_no);
    out += writer(cookie, "out_port=");
    out += LOCI_SHOW_port_no_out_port(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_flow_add_out_group_get(obj, &val32);
    out += writer(cookie, "out_group=");
    out += LOCI_SHOW_u32_out_group(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_add_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_add_match_get(obj, &match);
    out += writer(cookie, "match=");
    out += LOCI_SHOW_match_match(writer, cookie, match);
    out += writer(cookie, " ");

    out += writer(cookie, "of_instruction_t={ ");
    of_flow_add_instructions_bind(obj, &list);
    OF_LIST_INSTRUCTION_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_flow_delete_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_flow_delete_t *obj)
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

    of_flow_delete_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_delete_cookie_get(obj, &val64);
    out += writer(cookie, "cookie=");
    out += LOCI_SHOW_u64_cookie(writer, cookie, val64);
    out += writer(cookie, " ");

    of_flow_delete_cookie_mask_get(obj, &val64);
    out += writer(cookie, "cookie_mask=");
    out += LOCI_SHOW_u64_cookie_mask(writer, cookie, val64);
    out += writer(cookie, " ");

    of_flow_delete_table_id_get(obj, &val8);
    out += writer(cookie, "table_id=");
    out += LOCI_SHOW_u8_table_id(writer, cookie, val8);
    out += writer(cookie, " ");

    of_flow_delete_idle_timeout_get(obj, &val16);
    out += writer(cookie, "idle_timeout=");
    out += LOCI_SHOW_u16_idle_timeout(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_delete_hard_timeout_get(obj, &val16);
    out += writer(cookie, "hard_timeout=");
    out += LOCI_SHOW_u16_hard_timeout(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_delete_priority_get(obj, &val16);
    out += writer(cookie, "priority=");
    out += LOCI_SHOW_u16_priority(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_delete_buffer_id_get(obj, &val32);
    out += writer(cookie, "buffer_id=");
    out += LOCI_SHOW_u32_buffer_id(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_delete_out_port_get(obj, &port_no);
    out += writer(cookie, "out_port=");
    out += LOCI_SHOW_port_no_out_port(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_flow_delete_out_group_get(obj, &val32);
    out += writer(cookie, "out_group=");
    out += LOCI_SHOW_u32_out_group(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_delete_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_delete_match_get(obj, &match);
    out += writer(cookie, "match=");
    out += LOCI_SHOW_match_match(writer, cookie, match);
    out += writer(cookie, " ");

    out += writer(cookie, "of_instruction_t={ ");
    of_flow_delete_instructions_bind(obj, &list);
    OF_LIST_INSTRUCTION_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_flow_delete_strict_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_flow_delete_strict_t *obj)
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

    of_flow_delete_strict_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_delete_strict_cookie_get(obj, &val64);
    out += writer(cookie, "cookie=");
    out += LOCI_SHOW_u64_cookie(writer, cookie, val64);
    out += writer(cookie, " ");

    of_flow_delete_strict_cookie_mask_get(obj, &val64);
    out += writer(cookie, "cookie_mask=");
    out += LOCI_SHOW_u64_cookie_mask(writer, cookie, val64);
    out += writer(cookie, " ");

    of_flow_delete_strict_table_id_get(obj, &val8);
    out += writer(cookie, "table_id=");
    out += LOCI_SHOW_u8_table_id(writer, cookie, val8);
    out += writer(cookie, " ");

    of_flow_delete_strict_idle_timeout_get(obj, &val16);
    out += writer(cookie, "idle_timeout=");
    out += LOCI_SHOW_u16_idle_timeout(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_delete_strict_hard_timeout_get(obj, &val16);
    out += writer(cookie, "hard_timeout=");
    out += LOCI_SHOW_u16_hard_timeout(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_delete_strict_priority_get(obj, &val16);
    out += writer(cookie, "priority=");
    out += LOCI_SHOW_u16_priority(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_delete_strict_buffer_id_get(obj, &val32);
    out += writer(cookie, "buffer_id=");
    out += LOCI_SHOW_u32_buffer_id(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_delete_strict_out_port_get(obj, &port_no);
    out += writer(cookie, "out_port=");
    out += LOCI_SHOW_port_no_out_port(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_flow_delete_strict_out_group_get(obj, &val32);
    out += writer(cookie, "out_group=");
    out += LOCI_SHOW_u32_out_group(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_delete_strict_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_delete_strict_match_get(obj, &match);
    out += writer(cookie, "match=");
    out += LOCI_SHOW_match_match(writer, cookie, match);
    out += writer(cookie, " ");

    out += writer(cookie, "of_instruction_t={ ");
    of_flow_delete_strict_instructions_bind(obj, &list);
    OF_LIST_INSTRUCTION_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_flow_mod_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_flow_mod_t *obj)
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

    of_flow_mod_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_mod_cookie_get(obj, &val64);
    out += writer(cookie, "cookie=");
    out += LOCI_SHOW_u64_cookie(writer, cookie, val64);
    out += writer(cookie, " ");

    of_flow_mod_cookie_mask_get(obj, &val64);
    out += writer(cookie, "cookie_mask=");
    out += LOCI_SHOW_u64_cookie_mask(writer, cookie, val64);
    out += writer(cookie, " ");

    of_flow_mod_table_id_get(obj, &val8);
    out += writer(cookie, "table_id=");
    out += LOCI_SHOW_u8_table_id(writer, cookie, val8);
    out += writer(cookie, " ");

    of_flow_mod_idle_timeout_get(obj, &val16);
    out += writer(cookie, "idle_timeout=");
    out += LOCI_SHOW_u16_idle_timeout(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_mod_hard_timeout_get(obj, &val16);
    out += writer(cookie, "hard_timeout=");
    out += LOCI_SHOW_u16_hard_timeout(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_mod_priority_get(obj, &val16);
    out += writer(cookie, "priority=");
    out += LOCI_SHOW_u16_priority(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_mod_buffer_id_get(obj, &val32);
    out += writer(cookie, "buffer_id=");
    out += LOCI_SHOW_u32_buffer_id(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_mod_out_port_get(obj, &port_no);
    out += writer(cookie, "out_port=");
    out += LOCI_SHOW_port_no_out_port(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_flow_mod_out_group_get(obj, &val32);
    out += writer(cookie, "out_group=");
    out += LOCI_SHOW_u32_out_group(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_mod_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_mod_match_get(obj, &match);
    out += writer(cookie, "match=");
    out += LOCI_SHOW_match_match(writer, cookie, match);
    out += writer(cookie, " ");

    out += writer(cookie, "of_instruction_t={ ");
    of_flow_mod_instructions_bind(obj, &list);
    OF_LIST_INSTRUCTION_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_flow_mod_failed_error_msg_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_flow_mod_failed_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    of_flow_mod_failed_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_mod_failed_error_msg_code_get(obj, &val16);
    out += writer(cookie, "code=");
    out += LOCI_SHOW_u16_code(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_mod_failed_error_msg_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_flow_modify_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_flow_modify_t *obj)
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

    of_flow_modify_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_modify_cookie_get(obj, &val64);
    out += writer(cookie, "cookie=");
    out += LOCI_SHOW_u64_cookie(writer, cookie, val64);
    out += writer(cookie, " ");

    of_flow_modify_cookie_mask_get(obj, &val64);
    out += writer(cookie, "cookie_mask=");
    out += LOCI_SHOW_u64_cookie_mask(writer, cookie, val64);
    out += writer(cookie, " ");

    of_flow_modify_table_id_get(obj, &val8);
    out += writer(cookie, "table_id=");
    out += LOCI_SHOW_u8_table_id(writer, cookie, val8);
    out += writer(cookie, " ");

    of_flow_modify_idle_timeout_get(obj, &val16);
    out += writer(cookie, "idle_timeout=");
    out += LOCI_SHOW_u16_idle_timeout(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_modify_hard_timeout_get(obj, &val16);
    out += writer(cookie, "hard_timeout=");
    out += LOCI_SHOW_u16_hard_timeout(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_modify_priority_get(obj, &val16);
    out += writer(cookie, "priority=");
    out += LOCI_SHOW_u16_priority(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_modify_buffer_id_get(obj, &val32);
    out += writer(cookie, "buffer_id=");
    out += LOCI_SHOW_u32_buffer_id(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_modify_out_port_get(obj, &port_no);
    out += writer(cookie, "out_port=");
    out += LOCI_SHOW_port_no_out_port(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_flow_modify_out_group_get(obj, &val32);
    out += writer(cookie, "out_group=");
    out += LOCI_SHOW_u32_out_group(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_modify_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_modify_match_get(obj, &match);
    out += writer(cookie, "match=");
    out += LOCI_SHOW_match_match(writer, cookie, match);
    out += writer(cookie, " ");

    out += writer(cookie, "of_instruction_t={ ");
    of_flow_modify_instructions_bind(obj, &list);
    OF_LIST_INSTRUCTION_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_flow_modify_strict_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_flow_modify_strict_t *obj)
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

    of_flow_modify_strict_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_modify_strict_cookie_get(obj, &val64);
    out += writer(cookie, "cookie=");
    out += LOCI_SHOW_u64_cookie(writer, cookie, val64);
    out += writer(cookie, " ");

    of_flow_modify_strict_cookie_mask_get(obj, &val64);
    out += writer(cookie, "cookie_mask=");
    out += LOCI_SHOW_u64_cookie_mask(writer, cookie, val64);
    out += writer(cookie, " ");

    of_flow_modify_strict_table_id_get(obj, &val8);
    out += writer(cookie, "table_id=");
    out += LOCI_SHOW_u8_table_id(writer, cookie, val8);
    out += writer(cookie, " ");

    of_flow_modify_strict_idle_timeout_get(obj, &val16);
    out += writer(cookie, "idle_timeout=");
    out += LOCI_SHOW_u16_idle_timeout(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_modify_strict_hard_timeout_get(obj, &val16);
    out += writer(cookie, "hard_timeout=");
    out += LOCI_SHOW_u16_hard_timeout(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_modify_strict_priority_get(obj, &val16);
    out += writer(cookie, "priority=");
    out += LOCI_SHOW_u16_priority(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_modify_strict_buffer_id_get(obj, &val32);
    out += writer(cookie, "buffer_id=");
    out += LOCI_SHOW_u32_buffer_id(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_modify_strict_out_port_get(obj, &port_no);
    out += writer(cookie, "out_port=");
    out += LOCI_SHOW_port_no_out_port(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_flow_modify_strict_out_group_get(obj, &val32);
    out += writer(cookie, "out_group=");
    out += LOCI_SHOW_u32_out_group(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_modify_strict_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_modify_strict_match_get(obj, &match);
    out += writer(cookie, "match=");
    out += LOCI_SHOW_match_match(writer, cookie, match);
    out += writer(cookie, " ");

    out += writer(cookie, "of_instruction_t={ ");
    of_flow_modify_strict_instructions_bind(obj, &list);
    OF_LIST_INSTRUCTION_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_flow_removed_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_flow_removed_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint64_t val64;
    uint16_t val16;
    uint8_t val8;
    of_match_t match;

    of_flow_removed_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_removed_cookie_get(obj, &val64);
    out += writer(cookie, "cookie=");
    out += LOCI_SHOW_u64_cookie(writer, cookie, val64);
    out += writer(cookie, " ");

    of_flow_removed_priority_get(obj, &val16);
    out += writer(cookie, "priority=");
    out += LOCI_SHOW_u16_priority(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_removed_reason_get(obj, &val8);
    out += writer(cookie, "reason=");
    out += LOCI_SHOW_u8_reason(writer, cookie, val8);
    out += writer(cookie, " ");

    of_flow_removed_table_id_get(obj, &val8);
    out += writer(cookie, "table_id=");
    out += LOCI_SHOW_u8_table_id(writer, cookie, val8);
    out += writer(cookie, " ");

    of_flow_removed_duration_sec_get(obj, &val32);
    out += writer(cookie, "duration_sec=");
    out += LOCI_SHOW_u32_duration_sec(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_removed_duration_nsec_get(obj, &val32);
    out += writer(cookie, "duration_nsec=");
    out += LOCI_SHOW_u32_duration_nsec(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_removed_idle_timeout_get(obj, &val16);
    out += writer(cookie, "idle_timeout=");
    out += LOCI_SHOW_u16_idle_timeout(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_removed_hard_timeout_get(obj, &val16);
    out += writer(cookie, "hard_timeout=");
    out += LOCI_SHOW_u16_hard_timeout(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_removed_packet_count_get(obj, &val64);
    out += writer(cookie, "packet_count=");
    out += LOCI_SHOW_u64_packet_count(writer, cookie, val64);
    out += writer(cookie, " ");

    of_flow_removed_byte_count_get(obj, &val64);
    out += writer(cookie, "byte_count=");
    out += LOCI_SHOW_u64_byte_count(writer, cookie, val64);
    out += writer(cookie, " ");

    of_flow_removed_match_get(obj, &match);
    out += writer(cookie, "match=");
    out += LOCI_SHOW_match_match(writer, cookie, match);
    out += writer(cookie, " ");

    return out;
}

int
of_flow_stats_reply_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_flow_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_list_flow_stats_entry_t list;
    of_flow_stats_entry_t elt;
    int rv;

    of_flow_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    out += writer(cookie, "of_flow_stats_entry_t={ ");
    of_flow_stats_reply_entries_bind(obj, &list);
    OF_LIST_FLOW_STATS_ENTRY_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_flow_stats_request_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_flow_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    uint8_t val8;
    of_port_no_t port_no;
    uint64_t val64;
    of_match_t match;

    of_flow_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_stats_request_table_id_get(obj, &val8);
    out += writer(cookie, "table_id=");
    out += LOCI_SHOW_u8_table_id(writer, cookie, val8);
    out += writer(cookie, " ");

    of_flow_stats_request_out_port_get(obj, &port_no);
    out += writer(cookie, "out_port=");
    out += LOCI_SHOW_port_no_out_port(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_flow_stats_request_out_group_get(obj, &val32);
    out += writer(cookie, "out_group=");
    out += LOCI_SHOW_u32_out_group(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_stats_request_cookie_get(obj, &val64);
    out += writer(cookie, "cookie=");
    out += LOCI_SHOW_u64_cookie(writer, cookie, val64);
    out += writer(cookie, " ");

    of_flow_stats_request_cookie_mask_get(obj, &val64);
    out += writer(cookie, "cookie_mask=");
    out += LOCI_SHOW_u64_cookie_mask(writer, cookie, val64);
    out += writer(cookie, " ");

    of_flow_stats_request_match_get(obj, &match);
    out += writer(cookie, "match=");
    out += LOCI_SHOW_match_match(writer, cookie, match);
    out += writer(cookie, " ");

    return out;
}

int
of_get_config_reply_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_get_config_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_get_config_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_get_config_reply_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    of_get_config_reply_miss_send_len_get(obj, &val16);
    out += writer(cookie, "miss_send_len=");
    out += LOCI_SHOW_u16_miss_send_len(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_get_config_request_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_get_config_request_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_get_config_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_group_desc_stats_reply_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_group_desc_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_list_group_desc_stats_entry_t list;
    of_group_desc_stats_entry_t elt;
    int rv;

    of_group_desc_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_group_desc_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    out += writer(cookie, "of_group_desc_stats_entry_t={ ");
    of_group_desc_stats_reply_entries_bind(obj, &list);
    OF_LIST_GROUP_DESC_STATS_ENTRY_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_group_desc_stats_request_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_group_desc_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_group_desc_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_group_desc_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_group_features_stats_reply_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_group_features_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_group_features_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_group_features_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    of_group_features_stats_reply_types_get(obj, &val32);
    out += writer(cookie, "types=");
    out += LOCI_SHOW_u32_types(writer, cookie, val32);
    out += writer(cookie, " ");

    of_group_features_stats_reply_capabilities_get(obj, &val32);
    out += writer(cookie, "capabilities=");
    out += LOCI_SHOW_u32_capabilities(writer, cookie, val32);
    out += writer(cookie, " ");

    of_group_features_stats_reply_max_groups_all_get(obj, &val32);
    out += writer(cookie, "max_groups_all=");
    out += LOCI_SHOW_u32_max_groups_all(writer, cookie, val32);
    out += writer(cookie, " ");

    of_group_features_stats_reply_max_groups_select_get(obj, &val32);
    out += writer(cookie, "max_groups_select=");
    out += LOCI_SHOW_u32_max_groups_select(writer, cookie, val32);
    out += writer(cookie, " ");

    of_group_features_stats_reply_max_groups_indirect_get(obj, &val32);
    out += writer(cookie, "max_groups_indirect=");
    out += LOCI_SHOW_u32_max_groups_indirect(writer, cookie, val32);
    out += writer(cookie, " ");

    of_group_features_stats_reply_max_groups_ff_get(obj, &val32);
    out += writer(cookie, "max_groups_ff=");
    out += LOCI_SHOW_u32_max_groups_ff(writer, cookie, val32);
    out += writer(cookie, " ");

    of_group_features_stats_reply_actions_all_get(obj, &val32);
    out += writer(cookie, "actions_all=");
    out += LOCI_SHOW_u32_actions_all(writer, cookie, val32);
    out += writer(cookie, " ");

    of_group_features_stats_reply_actions_select_get(obj, &val32);
    out += writer(cookie, "actions_select=");
    out += LOCI_SHOW_u32_actions_select(writer, cookie, val32);
    out += writer(cookie, " ");

    of_group_features_stats_reply_actions_indirect_get(obj, &val32);
    out += writer(cookie, "actions_indirect=");
    out += LOCI_SHOW_u32_actions_indirect(writer, cookie, val32);
    out += writer(cookie, " ");

    of_group_features_stats_reply_actions_ff_get(obj, &val32);
    out += writer(cookie, "actions_ff=");
    out += LOCI_SHOW_u32_actions_ff(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_group_features_stats_request_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_group_features_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_group_features_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_group_features_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_group_mod_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_group_mod_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    uint8_t val8;

    of_list_bucket_t list;
    of_bucket_t elt;
    int rv;

    of_group_mod_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_group_mod_command_get(obj, &val16);
    out += writer(cookie, "command=");
    out += LOCI_SHOW_u16_command(writer, cookie, val16);
    out += writer(cookie, " ");

    of_group_mod_group_type_get(obj, &val8);
    out += writer(cookie, "group_type=");
    out += LOCI_SHOW_u8_group_type(writer, cookie, val8);
    out += writer(cookie, " ");

    of_group_mod_group_id_get(obj, &val32);
    out += writer(cookie, "group_id=");
    out += LOCI_SHOW_u32_group_id(writer, cookie, val32);
    out += writer(cookie, " ");

    out += writer(cookie, "of_bucket_t={ ");
    of_group_mod_buckets_bind(obj, &list);
    OF_LIST_BUCKET_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_group_mod_failed_error_msg_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_group_mod_failed_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    of_group_mod_failed_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_group_mod_failed_error_msg_code_get(obj, &val16);
    out += writer(cookie, "code=");
    out += LOCI_SHOW_u16_code(writer, cookie, val16);
    out += writer(cookie, " ");

    of_group_mod_failed_error_msg_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_group_stats_reply_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_group_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_list_group_stats_entry_t list;
    of_group_stats_entry_t elt;
    int rv;

    of_group_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_group_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    out += writer(cookie, "of_group_stats_entry_t={ ");
    of_group_stats_reply_entries_bind(obj, &list);
    OF_LIST_GROUP_STATS_ENTRY_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_group_stats_request_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_group_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_group_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_group_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    of_group_stats_request_group_id_get(obj, &val32);
    out += writer(cookie, "group_id=");
    out += LOCI_SHOW_u32_group_id(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_hello_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_hello_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_hello_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_hello_failed_error_msg_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_hello_failed_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    of_hello_failed_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_hello_failed_error_msg_code_get(obj, &val16);
    out += writer(cookie, "code=");
    out += LOCI_SHOW_u16_code(writer, cookie, val16);
    out += writer(cookie, " ");

    of_hello_failed_error_msg_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_nicira_header_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_nicira_header_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_nicira_header_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_nicira_header_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_nicira_header_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_packet_in_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_packet_in_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    uint8_t val8;
    of_match_t match;
    of_octets_t octets;

    of_packet_in_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_packet_in_buffer_id_get(obj, &val32);
    out += writer(cookie, "buffer_id=");
    out += LOCI_SHOW_u32_buffer_id(writer, cookie, val32);
    out += writer(cookie, " ");

    of_packet_in_total_len_get(obj, &val16);
    out += writer(cookie, "total_len=");
    out += LOCI_SHOW_u16_total_len(writer, cookie, val16);
    out += writer(cookie, " ");

    of_packet_in_reason_get(obj, &val8);
    out += writer(cookie, "reason=");
    out += LOCI_SHOW_u8_reason(writer, cookie, val8);
    out += writer(cookie, " ");

    of_packet_in_table_id_get(obj, &val8);
    out += writer(cookie, "table_id=");
    out += LOCI_SHOW_u8_table_id(writer, cookie, val8);
    out += writer(cookie, " ");

    of_packet_in_match_get(obj, &match);
    out += writer(cookie, "match=");
    out += LOCI_SHOW_match_match(writer, cookie, match);
    out += writer(cookie, " ");

    of_packet_in_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_packet_out_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_packet_out_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_port_no_t port_no;

    of_list_action_t list;
    of_action_t elt;
    int rv;
    of_octets_t octets;

    of_packet_out_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_packet_out_buffer_id_get(obj, &val32);
    out += writer(cookie, "buffer_id=");
    out += LOCI_SHOW_u32_buffer_id(writer, cookie, val32);
    out += writer(cookie, " ");

    of_packet_out_in_port_get(obj, &port_no);
    out += writer(cookie, "in_port=");
    out += LOCI_SHOW_port_no_in_port(writer, cookie, port_no);
    out += writer(cookie, " ");

    out += writer(cookie, "of_action_t={ ");
    of_packet_out_actions_bind(obj, &list);
    OF_LIST_ACTION_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    of_packet_out_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_port_mod_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_port_mod_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_port_no_t port_no;
    of_mac_addr_t mac_addr;

    of_port_mod_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_port_mod_port_no_get(obj, &port_no);
    out += writer(cookie, "port_no=");
    out += LOCI_SHOW_port_no_port_no(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_port_mod_hw_addr_get(obj, &mac_addr);
    out += writer(cookie, "hw_addr=");
    out += LOCI_SHOW_mac_hw_addr(writer, cookie, mac_addr);
    out += writer(cookie, " ");

    of_port_mod_config_get(obj, &val32);
    out += writer(cookie, "config=");
    out += LOCI_SHOW_u32_config(writer, cookie, val32);
    out += writer(cookie, " ");

    of_port_mod_mask_get(obj, &val32);
    out += writer(cookie, "mask=");
    out += LOCI_SHOW_u32_mask(writer, cookie, val32);
    out += writer(cookie, " ");

    of_port_mod_advertise_get(obj, &val32);
    out += writer(cookie, "advertise=");
    out += LOCI_SHOW_u32_advertise(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_port_mod_failed_error_msg_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_port_mod_failed_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    of_port_mod_failed_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_port_mod_failed_error_msg_code_get(obj, &val16);
    out += writer(cookie, "code=");
    out += LOCI_SHOW_u16_code(writer, cookie, val16);
    out += writer(cookie, " ");

    of_port_mod_failed_error_msg_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_port_stats_reply_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_port_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_list_port_stats_entry_t list;
    of_port_stats_entry_t elt;
    int rv;

    of_port_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_port_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    out += writer(cookie, "of_port_stats_entry_t={ ");
    of_port_stats_reply_entries_bind(obj, &list);
    OF_LIST_PORT_STATS_ENTRY_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_port_stats_request_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_port_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_port_no_t port_no;

    of_port_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_port_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    of_port_stats_request_port_no_get(obj, &port_no);
    out += writer(cookie, "port_no=");
    out += LOCI_SHOW_port_no_port_no(writer, cookie, port_no);
    out += writer(cookie, " ");

    return out;
}

int
of_port_status_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_port_status_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint8_t val8;

    of_port_desc_t port_desc;

    of_port_status_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_port_status_reason_get(obj, &val8);
    out += writer(cookie, "reason=");
    out += LOCI_SHOW_u8_reason(writer, cookie, val8);
    out += writer(cookie, " ");

    of_port_status_desc_bind(obj, &port_desc);
    out += of_port_desc_OF_VERSION_1_2_show(writer, cookie, &port_desc);

    return out;
}

int
of_queue_get_config_reply_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_queue_get_config_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_port_no_t port_no;

    of_list_packet_queue_t list;
    of_packet_queue_t elt;
    int rv;

    of_queue_get_config_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_queue_get_config_reply_port_get(obj, &port_no);
    out += writer(cookie, "port=");
    out += LOCI_SHOW_port_no_port(writer, cookie, port_no);
    out += writer(cookie, " ");

    out += writer(cookie, "of_packet_queue_t={ ");
    of_queue_get_config_reply_queues_bind(obj, &list);
    OF_LIST_PACKET_QUEUE_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_queue_get_config_request_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_queue_get_config_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_port_no_t port_no;

    of_queue_get_config_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_queue_get_config_request_port_get(obj, &port_no);
    out += writer(cookie, "port=");
    out += LOCI_SHOW_port_no_port(writer, cookie, port_no);
    out += writer(cookie, " ");

    return out;
}

int
of_queue_op_failed_error_msg_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_queue_op_failed_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    of_queue_op_failed_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_queue_op_failed_error_msg_code_get(obj, &val16);
    out += writer(cookie, "code=");
    out += LOCI_SHOW_u16_code(writer, cookie, val16);
    out += writer(cookie, " ");

    of_queue_op_failed_error_msg_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_queue_stats_reply_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_queue_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_list_queue_stats_entry_t list;
    of_queue_stats_entry_t elt;
    int rv;

    of_queue_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_queue_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    out += writer(cookie, "of_queue_stats_entry_t={ ");
    of_queue_stats_reply_entries_bind(obj, &list);
    OF_LIST_QUEUE_STATS_ENTRY_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_queue_stats_request_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_queue_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_port_no_t port_no;

    of_queue_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_queue_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    of_queue_stats_request_port_no_get(obj, &port_no);
    out += writer(cookie, "port_no=");
    out += LOCI_SHOW_port_no_port_no(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_queue_stats_request_queue_id_get(obj, &val32);
    out += writer(cookie, "queue_id=");
    out += LOCI_SHOW_u32_queue_id(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_role_reply_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_role_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint64_t val64;

    of_role_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_role_reply_role_get(obj, &val32);
    out += writer(cookie, "role=");
    out += LOCI_SHOW_u32_role(writer, cookie, val32);
    out += writer(cookie, " ");

    of_role_reply_generation_id_get(obj, &val64);
    out += writer(cookie, "generation_id=");
    out += LOCI_SHOW_u64_generation_id(writer, cookie, val64);
    out += writer(cookie, " ");

    return out;
}

int
of_role_request_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_role_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint64_t val64;

    of_role_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_role_request_role_get(obj, &val32);
    out += writer(cookie, "role=");
    out += LOCI_SHOW_u32_role(writer, cookie, val32);
    out += writer(cookie, " ");

    of_role_request_generation_id_get(obj, &val64);
    out += writer(cookie, "generation_id=");
    out += LOCI_SHOW_u64_generation_id(writer, cookie, val64);
    out += writer(cookie, " ");

    return out;
}

int
of_role_request_failed_error_msg_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_role_request_failed_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    of_role_request_failed_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_role_request_failed_error_msg_code_get(obj, &val16);
    out += writer(cookie, "code=");
    out += LOCI_SHOW_u16_code(writer, cookie, val16);
    out += writer(cookie, " ");

    of_role_request_failed_error_msg_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_set_config_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_set_config_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_set_config_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_set_config_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    of_set_config_miss_send_len_get(obj, &val16);
    out += writer(cookie, "miss_send_len=");
    out += LOCI_SHOW_u16_miss_send_len(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_stats_reply_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_stats_request_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_switch_config_failed_error_msg_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_switch_config_failed_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    of_switch_config_failed_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_switch_config_failed_error_msg_code_get(obj, &val16);
    out += writer(cookie, "code=");
    out += LOCI_SHOW_u16_code(writer, cookie, val16);
    out += writer(cookie, " ");

    of_switch_config_failed_error_msg_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_table_mod_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_table_mod_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint8_t val8;

    of_table_mod_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_table_mod_table_id_get(obj, &val8);
    out += writer(cookie, "table_id=");
    out += LOCI_SHOW_u8_table_id(writer, cookie, val8);
    out += writer(cookie, " ");

    of_table_mod_config_get(obj, &val32);
    out += writer(cookie, "config=");
    out += LOCI_SHOW_u32_config(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_table_mod_failed_error_msg_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_table_mod_failed_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    of_table_mod_failed_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_table_mod_failed_error_msg_code_get(obj, &val16);
    out += writer(cookie, "code=");
    out += LOCI_SHOW_u16_code(writer, cookie, val16);
    out += writer(cookie, " ");

    of_table_mod_failed_error_msg_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_table_stats_reply_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_table_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_list_table_stats_entry_t list;
    of_table_stats_entry_t elt;
    int rv;

    of_table_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_table_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    out += writer(cookie, "of_table_stats_entry_t={ ");
    of_table_stats_reply_entries_bind(obj, &list);
    OF_LIST_TABLE_STATS_ENTRY_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_table_stats_request_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_table_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_table_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_table_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_action_bsn_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_action_bsn_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_action_bsn_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_action_bsn_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_action_bsn_mirror_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_action_bsn_mirror_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint8_t val8;

    of_action_bsn_mirror_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_action_bsn_mirror_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_action_bsn_mirror_dest_port_get(obj, &val32);
    out += writer(cookie, "dest_port=");
    out += LOCI_SHOW_u32_dest_port(writer, cookie, val32);
    out += writer(cookie, " ");

    of_action_bsn_mirror_vlan_tag_get(obj, &val32);
    out += writer(cookie, "vlan_tag=");
    out += LOCI_SHOW_u32_vlan_tag(writer, cookie, val32);
    out += writer(cookie, " ");

    of_action_bsn_mirror_copy_stage_get(obj, &val8);
    out += writer(cookie, "copy_stage=");
    out += LOCI_SHOW_u8_copy_stage(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_action_bsn_set_tunnel_dst_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_action_bsn_set_tunnel_dst_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_action_bsn_set_tunnel_dst_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_action_bsn_set_tunnel_dst_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_action_bsn_set_tunnel_dst_dst_get(obj, &val32);
    out += writer(cookie, "dst=");
    out += LOCI_SHOW_u32_dst(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_action_copy_ttl_in_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_action_copy_ttl_in_t *obj)
{
    int out = 0;

    return out;
}

int
of_action_copy_ttl_out_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_action_copy_ttl_out_t *obj)
{
    int out = 0;

    return out;
}

int
of_action_dec_mpls_ttl_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_action_dec_mpls_ttl_t *obj)
{
    int out = 0;

    return out;
}

int
of_action_dec_nw_ttl_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_action_dec_nw_ttl_t *obj)
{
    int out = 0;

    return out;
}

int
of_action_experimenter_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_action_experimenter_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_octets_t octets;

    of_action_experimenter_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_action_experimenter_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_action_group_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_action_group_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_action_group_group_id_get(obj, &val32);
    out += writer(cookie, "group_id=");
    out += LOCI_SHOW_u32_group_id(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_action_header_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_action_header_t *obj)
{
    int out = 0;

    return out;
}

int
of_action_nicira_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_action_nicira_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_action_nicira_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_action_nicira_subtype_get(obj, &val16);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u16_subtype(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_action_nicira_dec_ttl_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_action_nicira_dec_ttl_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_action_nicira_dec_ttl_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_action_nicira_dec_ttl_subtype_get(obj, &val16);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u16_subtype(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_action_output_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_action_output_t *obj)
{
    int out = 0;
    of_port_no_t port_no;
    uint16_t val16;

    of_action_output_port_get(obj, &port_no);
    out += writer(cookie, "port=");
    out += LOCI_SHOW_port_no_port(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_action_output_max_len_get(obj, &val16);
    out += writer(cookie, "max_len=");
    out += LOCI_SHOW_u16_max_len(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_action_pop_mpls_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_action_pop_mpls_t *obj)
{
    int out = 0;
    uint16_t val16;

    of_action_pop_mpls_ethertype_get(obj, &val16);
    out += writer(cookie, "ethertype=");
    out += LOCI_SHOW_u16_ethertype(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_action_pop_vlan_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_action_pop_vlan_t *obj)
{
    int out = 0;

    return out;
}

int
of_action_push_mpls_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_action_push_mpls_t *obj)
{
    int out = 0;
    uint16_t val16;

    of_action_push_mpls_ethertype_get(obj, &val16);
    out += writer(cookie, "ethertype=");
    out += LOCI_SHOW_u16_ethertype(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_action_push_vlan_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_action_push_vlan_t *obj)
{
    int out = 0;
    uint16_t val16;

    of_action_push_vlan_ethertype_get(obj, &val16);
    out += writer(cookie, "ethertype=");
    out += LOCI_SHOW_u16_ethertype(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_action_set_field_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_action_set_field_t *obj)
{
    int out = 0;
    of_octets_t octets;

    of_action_set_field_field_get(obj, &octets);
    out += writer(cookie, "field=");
    out += LOCI_SHOW_octets_field(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_action_set_mpls_ttl_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_action_set_mpls_ttl_t *obj)
{
    int out = 0;
    uint8_t val8;

    of_action_set_mpls_ttl_mpls_ttl_get(obj, &val8);
    out += writer(cookie, "mpls_ttl=");
    out += LOCI_SHOW_u8_mpls_ttl(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_action_set_nw_ttl_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_action_set_nw_ttl_t *obj)
{
    int out = 0;
    uint8_t val8;

    of_action_set_nw_ttl_nw_ttl_get(obj, &val8);
    out += writer(cookie, "nw_ttl=");
    out += LOCI_SHOW_u8_nw_ttl(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_action_set_queue_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_action_set_queue_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_action_set_queue_queue_id_get(obj, &val32);
    out += writer(cookie, "queue_id=");
    out += LOCI_SHOW_u32_queue_id(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_interface_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_bsn_interface_t *obj)
{
    int out = 0;
    of_mac_addr_t mac_addr;
    of_port_name_t port_name;
    of_ipv4_t ipv4;

    of_bsn_interface_hw_addr_get(obj, &mac_addr);
    out += writer(cookie, "hw_addr=");
    out += LOCI_SHOW_mac_hw_addr(writer, cookie, mac_addr);
    out += writer(cookie, " ");

    of_bsn_interface_name_get(obj, &port_name);
    out += writer(cookie, "name=");
    out += LOCI_SHOW_port_name_name(writer, cookie, port_name);
    out += writer(cookie, " ");

    of_bsn_interface_ipv4_addr_get(obj, &ipv4);
    out += writer(cookie, "ipv4_addr=");
    out += LOCI_SHOW_ipv4_ipv4_addr(writer, cookie, ipv4);
    out += writer(cookie, " ");

    of_bsn_interface_ipv4_netmask_get(obj, &ipv4);
    out += writer(cookie, "ipv4_netmask=");
    out += LOCI_SHOW_ipv4_ipv4_netmask(writer, cookie, ipv4);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_vport_header_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_bsn_vport_header_t *obj)
{
    int out = 0;

    return out;
}

int
of_bsn_vport_q_in_q_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_bsn_vport_q_in_q_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_port_name_t port_name;

    of_bsn_vport_q_in_q_port_no_get(obj, &val32);
    out += writer(cookie, "port_no=");
    out += LOCI_SHOW_u32_port_no(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_vport_q_in_q_ingress_tpid_get(obj, &val16);
    out += writer(cookie, "ingress_tpid=");
    out += LOCI_SHOW_u16_ingress_tpid(writer, cookie, val16);
    out += writer(cookie, " ");

    of_bsn_vport_q_in_q_ingress_vlan_id_get(obj, &val16);
    out += writer(cookie, "ingress_vlan_id=");
    out += LOCI_SHOW_u16_ingress_vlan_id(writer, cookie, val16);
    out += writer(cookie, " ");

    of_bsn_vport_q_in_q_egress_tpid_get(obj, &val16);
    out += writer(cookie, "egress_tpid=");
    out += LOCI_SHOW_u16_egress_tpid(writer, cookie, val16);
    out += writer(cookie, " ");

    of_bsn_vport_q_in_q_egress_vlan_id_get(obj, &val16);
    out += writer(cookie, "egress_vlan_id=");
    out += LOCI_SHOW_u16_egress_vlan_id(writer, cookie, val16);
    out += writer(cookie, " ");

    of_bsn_vport_q_in_q_if_name_get(obj, &port_name);
    out += writer(cookie, "if_name=");
    out += LOCI_SHOW_port_name_if_name(writer, cookie, port_name);
    out += writer(cookie, " ");

    return out;
}

int
of_bucket_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_bucket_t *obj)
{
    int out = 0;
    uint16_t val16;
    of_port_no_t port_no;
    uint32_t val32;

    of_list_action_t list;
    of_action_t elt;
    int rv;

    of_bucket_weight_get(obj, &val16);
    out += writer(cookie, "weight=");
    out += LOCI_SHOW_u16_weight(writer, cookie, val16);
    out += writer(cookie, " ");

    of_bucket_watch_port_get(obj, &port_no);
    out += writer(cookie, "watch_port=");
    out += LOCI_SHOW_port_no_watch_port(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_bucket_watch_group_get(obj, &val32);
    out += writer(cookie, "watch_group=");
    out += LOCI_SHOW_u32_watch_group(writer, cookie, val32);
    out += writer(cookie, " ");

    out += writer(cookie, "of_action_t={ ");
    of_bucket_actions_bind(obj, &list);
    OF_LIST_ACTION_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_bucket_counter_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_bucket_counter_t *obj)
{
    int out = 0;
    uint64_t val64;

    of_bucket_counter_packet_count_get(obj, &val64);
    out += writer(cookie, "packet_count=");
    out += LOCI_SHOW_u64_packet_count(writer, cookie, val64);
    out += writer(cookie, " ");

    of_bucket_counter_byte_count_get(obj, &val64);
    out += writer(cookie, "byte_count=");
    out += LOCI_SHOW_u64_byte_count(writer, cookie, val64);
    out += writer(cookie, " ");

    return out;
}

int
of_flow_stats_entry_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_flow_stats_entry_t *obj)
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

    of_flow_stats_entry_table_id_get(obj, &val8);
    out += writer(cookie, "table_id=");
    out += LOCI_SHOW_u8_table_id(writer, cookie, val8);
    out += writer(cookie, " ");

    of_flow_stats_entry_duration_sec_get(obj, &val32);
    out += writer(cookie, "duration_sec=");
    out += LOCI_SHOW_u32_duration_sec(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_stats_entry_duration_nsec_get(obj, &val32);
    out += writer(cookie, "duration_nsec=");
    out += LOCI_SHOW_u32_duration_nsec(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_stats_entry_priority_get(obj, &val16);
    out += writer(cookie, "priority=");
    out += LOCI_SHOW_u16_priority(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_stats_entry_idle_timeout_get(obj, &val16);
    out += writer(cookie, "idle_timeout=");
    out += LOCI_SHOW_u16_idle_timeout(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_stats_entry_hard_timeout_get(obj, &val16);
    out += writer(cookie, "hard_timeout=");
    out += LOCI_SHOW_u16_hard_timeout(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_stats_entry_cookie_get(obj, &val64);
    out += writer(cookie, "cookie=");
    out += LOCI_SHOW_u64_cookie(writer, cookie, val64);
    out += writer(cookie, " ");

    of_flow_stats_entry_packet_count_get(obj, &val64);
    out += writer(cookie, "packet_count=");
    out += LOCI_SHOW_u64_packet_count(writer, cookie, val64);
    out += writer(cookie, " ");

    of_flow_stats_entry_byte_count_get(obj, &val64);
    out += writer(cookie, "byte_count=");
    out += LOCI_SHOW_u64_byte_count(writer, cookie, val64);
    out += writer(cookie, " ");

    of_flow_stats_entry_match_get(obj, &match);
    out += writer(cookie, "match=");
    out += LOCI_SHOW_match_match(writer, cookie, match);
    out += writer(cookie, " ");

    out += writer(cookie, "of_instruction_t={ ");
    of_flow_stats_entry_instructions_bind(obj, &list);
    OF_LIST_INSTRUCTION_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_group_desc_stats_entry_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_group_desc_stats_entry_t *obj)
{
    int out = 0;
    uint8_t val8;
    uint32_t val32;

    of_list_bucket_t list;
    of_bucket_t elt;
    int rv;

    of_group_desc_stats_entry_group_type_get(obj, &val8);
    out += writer(cookie, "group_type=");
    out += LOCI_SHOW_u8_group_type(writer, cookie, val8);
    out += writer(cookie, " ");

    of_group_desc_stats_entry_group_id_get(obj, &val32);
    out += writer(cookie, "group_id=");
    out += LOCI_SHOW_u32_group_id(writer, cookie, val32);
    out += writer(cookie, " ");

    out += writer(cookie, "of_bucket_t={ ");
    of_group_desc_stats_entry_buckets_bind(obj, &list);
    OF_LIST_BUCKET_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_group_stats_entry_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_group_stats_entry_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint64_t val64;

    of_list_bucket_counter_t list;
    of_bucket_counter_t elt;
    int rv;

    of_group_stats_entry_group_id_get(obj, &val32);
    out += writer(cookie, "group_id=");
    out += LOCI_SHOW_u32_group_id(writer, cookie, val32);
    out += writer(cookie, " ");

    of_group_stats_entry_ref_count_get(obj, &val32);
    out += writer(cookie, "ref_count=");
    out += LOCI_SHOW_u32_ref_count(writer, cookie, val32);
    out += writer(cookie, " ");

    of_group_stats_entry_packet_count_get(obj, &val64);
    out += writer(cookie, "packet_count=");
    out += LOCI_SHOW_u64_packet_count(writer, cookie, val64);
    out += writer(cookie, " ");

    of_group_stats_entry_byte_count_get(obj, &val64);
    out += writer(cookie, "byte_count=");
    out += LOCI_SHOW_u64_byte_count(writer, cookie, val64);
    out += writer(cookie, " ");

    out += writer(cookie, "of_bucket_counter_t={ ");
    of_group_stats_entry_bucket_stats_bind(obj, &list);
    OF_LIST_BUCKET_COUNTER_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_header_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_header_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_header_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_instruction_apply_actions_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_instruction_apply_actions_t *obj)
{
    int out = 0;

    of_list_action_t list;
    of_action_t elt;
    int rv;

    out += writer(cookie, "of_action_t={ ");
    of_instruction_apply_actions_actions_bind(obj, &list);
    OF_LIST_ACTION_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_instruction_clear_actions_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_instruction_clear_actions_t *obj)
{
    int out = 0;

    return out;
}

int
of_instruction_experimenter_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_instruction_experimenter_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_octets_t octets;

    of_instruction_experimenter_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_instruction_experimenter_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_instruction_goto_table_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_instruction_goto_table_t *obj)
{
    int out = 0;
    uint8_t val8;

    of_instruction_goto_table_table_id_get(obj, &val8);
    out += writer(cookie, "table_id=");
    out += LOCI_SHOW_u8_table_id(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_instruction_header_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_instruction_header_t *obj)
{
    int out = 0;

    return out;
}

int
of_instruction_write_actions_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_instruction_write_actions_t *obj)
{
    int out = 0;

    of_list_action_t list;
    of_action_t elt;
    int rv;

    out += writer(cookie, "of_action_t={ ");
    of_instruction_write_actions_actions_bind(obj, &list);
    OF_LIST_ACTION_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_instruction_write_metadata_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_instruction_write_metadata_t *obj)
{
    int out = 0;
    uint64_t val64;

    of_instruction_write_metadata_metadata_get(obj, &val64);
    out += writer(cookie, "metadata=");
    out += LOCI_SHOW_u64_metadata(writer, cookie, val64);
    out += writer(cookie, " ");

    of_instruction_write_metadata_metadata_mask_get(obj, &val64);
    out += writer(cookie, "metadata_mask=");
    out += LOCI_SHOW_u64_metadata_mask(writer, cookie, val64);
    out += writer(cookie, " ");

    return out;
}

int
of_match_v3_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_match_v3_t *obj)
{
    int out = 0;

    of_list_oxm_t list;
    of_oxm_t elt;
    int rv;

    out += writer(cookie, "of_oxm_t={ ");
    of_match_v3_oxm_list_bind(obj, &list);
    OF_LIST_OXM_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_oxm_arp_op_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_arp_op_t *obj)
{
    int out = 0;
    uint16_t val16;

    of_oxm_arp_op_value_get(obj, &val16);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u16_value(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_arp_op_masked_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_arp_op_masked_t *obj)
{
    int out = 0;
    uint16_t val16;

    of_oxm_arp_op_masked_value_get(obj, &val16);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u16_value(writer, cookie, val16);
    out += writer(cookie, " ");

    of_oxm_arp_op_masked_value_mask_get(obj, &val16);
    out += writer(cookie, "value_mask=");
    out += LOCI_SHOW_u16_value_mask(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_arp_sha_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_arp_sha_t *obj)
{
    int out = 0;
    of_mac_addr_t mac_addr;

    of_oxm_arp_sha_value_get(obj, &mac_addr);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_mac_value(writer, cookie, mac_addr);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_arp_sha_masked_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_arp_sha_masked_t *obj)
{
    int out = 0;
    of_mac_addr_t mac_addr;

    of_oxm_arp_sha_masked_value_get(obj, &mac_addr);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_mac_value(writer, cookie, mac_addr);
    out += writer(cookie, " ");

    of_oxm_arp_sha_masked_value_mask_get(obj, &mac_addr);
    out += writer(cookie, "value_mask=");
    out += LOCI_SHOW_mac_value_mask(writer, cookie, mac_addr);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_arp_spa_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_arp_spa_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_oxm_arp_spa_value_get(obj, &val32);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u32_value(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_arp_spa_masked_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_arp_spa_masked_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_oxm_arp_spa_masked_value_get(obj, &val32);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u32_value(writer, cookie, val32);
    out += writer(cookie, " ");

    of_oxm_arp_spa_masked_value_mask_get(obj, &val32);
    out += writer(cookie, "value_mask=");
    out += LOCI_SHOW_u32_value_mask(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_arp_tha_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_arp_tha_t *obj)
{
    int out = 0;
    of_mac_addr_t mac_addr;

    of_oxm_arp_tha_value_get(obj, &mac_addr);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_mac_value(writer, cookie, mac_addr);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_arp_tha_masked_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_arp_tha_masked_t *obj)
{
    int out = 0;
    of_mac_addr_t mac_addr;

    of_oxm_arp_tha_masked_value_get(obj, &mac_addr);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_mac_value(writer, cookie, mac_addr);
    out += writer(cookie, " ");

    of_oxm_arp_tha_masked_value_mask_get(obj, &mac_addr);
    out += writer(cookie, "value_mask=");
    out += LOCI_SHOW_mac_value_mask(writer, cookie, mac_addr);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_arp_tpa_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_arp_tpa_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_oxm_arp_tpa_value_get(obj, &val32);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u32_value(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_arp_tpa_masked_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_arp_tpa_masked_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_oxm_arp_tpa_masked_value_get(obj, &val32);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u32_value(writer, cookie, val32);
    out += writer(cookie, " ");

    of_oxm_arp_tpa_masked_value_mask_get(obj, &val32);
    out += writer(cookie, "value_mask=");
    out += LOCI_SHOW_u32_value_mask(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_bsn_global_vrf_allowed_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_bsn_global_vrf_allowed_t *obj)
{
    int out = 0;
    uint8_t val8;

    of_oxm_bsn_global_vrf_allowed_value_get(obj, &val8);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u8_value(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_bsn_global_vrf_allowed_masked_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_bsn_global_vrf_allowed_masked_t *obj)
{
    int out = 0;
    uint8_t val8;

    of_oxm_bsn_global_vrf_allowed_masked_value_get(obj, &val8);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u8_value(writer, cookie, val8);
    out += writer(cookie, " ");

    of_oxm_bsn_global_vrf_allowed_masked_value_mask_get(obj, &val8);
    out += writer(cookie, "value_mask=");
    out += LOCI_SHOW_u8_value_mask(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_bsn_in_ports_128_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_bsn_in_ports_128_t *obj)
{
    int out = 0;
    of_bitmap_128_t bitmap_128;

    of_oxm_bsn_in_ports_128_value_get(obj, &bitmap_128);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_bitmap_128_value(writer, cookie, bitmap_128);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_bsn_in_ports_128_masked_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_bsn_in_ports_128_masked_t *obj)
{
    int out = 0;
    of_bitmap_128_t bitmap_128;

    of_oxm_bsn_in_ports_128_masked_value_get(obj, &bitmap_128);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_bitmap_128_value(writer, cookie, bitmap_128);
    out += writer(cookie, " ");

    of_oxm_bsn_in_ports_128_masked_value_mask_get(obj, &bitmap_128);
    out += writer(cookie, "value_mask=");
    out += LOCI_SHOW_bitmap_128_value_mask(writer, cookie, bitmap_128);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_bsn_l3_dst_class_id_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_bsn_l3_dst_class_id_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_oxm_bsn_l3_dst_class_id_value_get(obj, &val32);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u32_value(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_bsn_l3_dst_class_id_masked_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_bsn_l3_dst_class_id_masked_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_oxm_bsn_l3_dst_class_id_masked_value_get(obj, &val32);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u32_value(writer, cookie, val32);
    out += writer(cookie, " ");

    of_oxm_bsn_l3_dst_class_id_masked_value_mask_get(obj, &val32);
    out += writer(cookie, "value_mask=");
    out += LOCI_SHOW_u32_value_mask(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_bsn_l3_interface_class_id_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_bsn_l3_interface_class_id_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_oxm_bsn_l3_interface_class_id_value_get(obj, &val32);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u32_value(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_bsn_l3_interface_class_id_masked_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_bsn_l3_interface_class_id_masked_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_oxm_bsn_l3_interface_class_id_masked_value_get(obj, &val32);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u32_value(writer, cookie, val32);
    out += writer(cookie, " ");

    of_oxm_bsn_l3_interface_class_id_masked_value_mask_get(obj, &val32);
    out += writer(cookie, "value_mask=");
    out += LOCI_SHOW_u32_value_mask(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_bsn_l3_src_class_id_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_bsn_l3_src_class_id_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_oxm_bsn_l3_src_class_id_value_get(obj, &val32);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u32_value(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_bsn_l3_src_class_id_masked_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_bsn_l3_src_class_id_masked_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_oxm_bsn_l3_src_class_id_masked_value_get(obj, &val32);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u32_value(writer, cookie, val32);
    out += writer(cookie, " ");

    of_oxm_bsn_l3_src_class_id_masked_value_mask_get(obj, &val32);
    out += writer(cookie, "value_mask=");
    out += LOCI_SHOW_u32_value_mask(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_bsn_lag_id_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_bsn_lag_id_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_oxm_bsn_lag_id_value_get(obj, &val32);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u32_value(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_bsn_lag_id_masked_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_bsn_lag_id_masked_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_oxm_bsn_lag_id_masked_value_get(obj, &val32);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u32_value(writer, cookie, val32);
    out += writer(cookie, " ");

    of_oxm_bsn_lag_id_masked_value_mask_get(obj, &val32);
    out += writer(cookie, "value_mask=");
    out += LOCI_SHOW_u32_value_mask(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_bsn_vrf_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_bsn_vrf_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_oxm_bsn_vrf_value_get(obj, &val32);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u32_value(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_bsn_vrf_masked_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_bsn_vrf_masked_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_oxm_bsn_vrf_masked_value_get(obj, &val32);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u32_value(writer, cookie, val32);
    out += writer(cookie, " ");

    of_oxm_bsn_vrf_masked_value_mask_get(obj, &val32);
    out += writer(cookie, "value_mask=");
    out += LOCI_SHOW_u32_value_mask(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_eth_dst_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_eth_dst_t *obj)
{
    int out = 0;
    of_mac_addr_t mac_addr;

    of_oxm_eth_dst_value_get(obj, &mac_addr);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_mac_value(writer, cookie, mac_addr);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_eth_dst_masked_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_eth_dst_masked_t *obj)
{
    int out = 0;
    of_mac_addr_t mac_addr;

    of_oxm_eth_dst_masked_value_get(obj, &mac_addr);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_mac_value(writer, cookie, mac_addr);
    out += writer(cookie, " ");

    of_oxm_eth_dst_masked_value_mask_get(obj, &mac_addr);
    out += writer(cookie, "value_mask=");
    out += LOCI_SHOW_mac_value_mask(writer, cookie, mac_addr);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_eth_src_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_eth_src_t *obj)
{
    int out = 0;
    of_mac_addr_t mac_addr;

    of_oxm_eth_src_value_get(obj, &mac_addr);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_mac_value(writer, cookie, mac_addr);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_eth_src_masked_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_eth_src_masked_t *obj)
{
    int out = 0;
    of_mac_addr_t mac_addr;

    of_oxm_eth_src_masked_value_get(obj, &mac_addr);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_mac_value(writer, cookie, mac_addr);
    out += writer(cookie, " ");

    of_oxm_eth_src_masked_value_mask_get(obj, &mac_addr);
    out += writer(cookie, "value_mask=");
    out += LOCI_SHOW_mac_value_mask(writer, cookie, mac_addr);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_eth_type_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_eth_type_t *obj)
{
    int out = 0;
    uint16_t val16;

    of_oxm_eth_type_value_get(obj, &val16);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u16_value(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_eth_type_masked_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_eth_type_masked_t *obj)
{
    int out = 0;
    uint16_t val16;

    of_oxm_eth_type_masked_value_get(obj, &val16);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u16_value(writer, cookie, val16);
    out += writer(cookie, " ");

    of_oxm_eth_type_masked_value_mask_get(obj, &val16);
    out += writer(cookie, "value_mask=");
    out += LOCI_SHOW_u16_value_mask(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_header_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_header_t *obj)
{
    int out = 0;

    return out;
}

int
of_oxm_icmpv4_code_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_icmpv4_code_t *obj)
{
    int out = 0;
    uint8_t val8;

    of_oxm_icmpv4_code_value_get(obj, &val8);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u8_value(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_icmpv4_code_masked_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_icmpv4_code_masked_t *obj)
{
    int out = 0;
    uint8_t val8;

    of_oxm_icmpv4_code_masked_value_get(obj, &val8);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u8_value(writer, cookie, val8);
    out += writer(cookie, " ");

    of_oxm_icmpv4_code_masked_value_mask_get(obj, &val8);
    out += writer(cookie, "value_mask=");
    out += LOCI_SHOW_u8_value_mask(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_icmpv4_type_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_icmpv4_type_t *obj)
{
    int out = 0;
    uint8_t val8;

    of_oxm_icmpv4_type_value_get(obj, &val8);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u8_value(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_icmpv4_type_masked_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_icmpv4_type_masked_t *obj)
{
    int out = 0;
    uint8_t val8;

    of_oxm_icmpv4_type_masked_value_get(obj, &val8);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u8_value(writer, cookie, val8);
    out += writer(cookie, " ");

    of_oxm_icmpv4_type_masked_value_mask_get(obj, &val8);
    out += writer(cookie, "value_mask=");
    out += LOCI_SHOW_u8_value_mask(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_icmpv6_code_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_icmpv6_code_t *obj)
{
    int out = 0;
    uint8_t val8;

    of_oxm_icmpv6_code_value_get(obj, &val8);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u8_value(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_icmpv6_code_masked_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_icmpv6_code_masked_t *obj)
{
    int out = 0;
    uint8_t val8;

    of_oxm_icmpv6_code_masked_value_get(obj, &val8);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u8_value(writer, cookie, val8);
    out += writer(cookie, " ");

    of_oxm_icmpv6_code_masked_value_mask_get(obj, &val8);
    out += writer(cookie, "value_mask=");
    out += LOCI_SHOW_u8_value_mask(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_icmpv6_type_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_icmpv6_type_t *obj)
{
    int out = 0;
    uint8_t val8;

    of_oxm_icmpv6_type_value_get(obj, &val8);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u8_value(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_icmpv6_type_masked_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_icmpv6_type_masked_t *obj)
{
    int out = 0;
    uint8_t val8;

    of_oxm_icmpv6_type_masked_value_get(obj, &val8);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u8_value(writer, cookie, val8);
    out += writer(cookie, " ");

    of_oxm_icmpv6_type_masked_value_mask_get(obj, &val8);
    out += writer(cookie, "value_mask=");
    out += LOCI_SHOW_u8_value_mask(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_in_phy_port_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_in_phy_port_t *obj)
{
    int out = 0;
    of_port_no_t port_no;

    of_oxm_in_phy_port_value_get(obj, &port_no);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_port_no_value(writer, cookie, port_no);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_in_phy_port_masked_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_in_phy_port_masked_t *obj)
{
    int out = 0;
    of_port_no_t port_no;

    of_oxm_in_phy_port_masked_value_get(obj, &port_no);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_port_no_value(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_oxm_in_phy_port_masked_value_mask_get(obj, &port_no);
    out += writer(cookie, "value_mask=");
    out += LOCI_SHOW_port_no_value_mask(writer, cookie, port_no);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_in_port_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_in_port_t *obj)
{
    int out = 0;
    of_port_no_t port_no;

    of_oxm_in_port_value_get(obj, &port_no);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_port_no_value(writer, cookie, port_no);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_in_port_masked_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_in_port_masked_t *obj)
{
    int out = 0;
    of_port_no_t port_no;

    of_oxm_in_port_masked_value_get(obj, &port_no);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_port_no_value(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_oxm_in_port_masked_value_mask_get(obj, &port_no);
    out += writer(cookie, "value_mask=");
    out += LOCI_SHOW_port_no_value_mask(writer, cookie, port_no);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_ip_dscp_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_ip_dscp_t *obj)
{
    int out = 0;
    uint8_t val8;

    of_oxm_ip_dscp_value_get(obj, &val8);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u8_value(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_ip_dscp_masked_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_ip_dscp_masked_t *obj)
{
    int out = 0;
    uint8_t val8;

    of_oxm_ip_dscp_masked_value_get(obj, &val8);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u8_value(writer, cookie, val8);
    out += writer(cookie, " ");

    of_oxm_ip_dscp_masked_value_mask_get(obj, &val8);
    out += writer(cookie, "value_mask=");
    out += LOCI_SHOW_u8_value_mask(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_ip_ecn_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_ip_ecn_t *obj)
{
    int out = 0;
    uint8_t val8;

    of_oxm_ip_ecn_value_get(obj, &val8);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u8_value(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_ip_ecn_masked_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_ip_ecn_masked_t *obj)
{
    int out = 0;
    uint8_t val8;

    of_oxm_ip_ecn_masked_value_get(obj, &val8);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u8_value(writer, cookie, val8);
    out += writer(cookie, " ");

    of_oxm_ip_ecn_masked_value_mask_get(obj, &val8);
    out += writer(cookie, "value_mask=");
    out += LOCI_SHOW_u8_value_mask(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_ip_proto_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_ip_proto_t *obj)
{
    int out = 0;
    uint8_t val8;

    of_oxm_ip_proto_value_get(obj, &val8);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u8_value(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_ip_proto_masked_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_ip_proto_masked_t *obj)
{
    int out = 0;
    uint8_t val8;

    of_oxm_ip_proto_masked_value_get(obj, &val8);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u8_value(writer, cookie, val8);
    out += writer(cookie, " ");

    of_oxm_ip_proto_masked_value_mask_get(obj, &val8);
    out += writer(cookie, "value_mask=");
    out += LOCI_SHOW_u8_value_mask(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_ipv4_dst_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_ipv4_dst_t *obj)
{
    int out = 0;
    of_ipv4_t ipv4;

    of_oxm_ipv4_dst_value_get(obj, &ipv4);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_ipv4_value(writer, cookie, ipv4);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_ipv4_dst_masked_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_ipv4_dst_masked_t *obj)
{
    int out = 0;
    of_ipv4_t ipv4;

    of_oxm_ipv4_dst_masked_value_get(obj, &ipv4);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_ipv4_value(writer, cookie, ipv4);
    out += writer(cookie, " ");

    of_oxm_ipv4_dst_masked_value_mask_get(obj, &ipv4);
    out += writer(cookie, "value_mask=");
    out += LOCI_SHOW_ipv4_value_mask(writer, cookie, ipv4);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_ipv4_src_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_ipv4_src_t *obj)
{
    int out = 0;
    of_ipv4_t ipv4;

    of_oxm_ipv4_src_value_get(obj, &ipv4);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_ipv4_value(writer, cookie, ipv4);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_ipv4_src_masked_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_ipv4_src_masked_t *obj)
{
    int out = 0;
    of_ipv4_t ipv4;

    of_oxm_ipv4_src_masked_value_get(obj, &ipv4);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_ipv4_value(writer, cookie, ipv4);
    out += writer(cookie, " ");

    of_oxm_ipv4_src_masked_value_mask_get(obj, &ipv4);
    out += writer(cookie, "value_mask=");
    out += LOCI_SHOW_ipv4_value_mask(writer, cookie, ipv4);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_ipv6_dst_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_ipv6_dst_t *obj)
{
    int out = 0;
    of_ipv6_t ipv6;

    of_oxm_ipv6_dst_value_get(obj, &ipv6);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_ipv6_value(writer, cookie, ipv6);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_ipv6_dst_masked_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_ipv6_dst_masked_t *obj)
{
    int out = 0;
    of_ipv6_t ipv6;

    of_oxm_ipv6_dst_masked_value_get(obj, &ipv6);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_ipv6_value(writer, cookie, ipv6);
    out += writer(cookie, " ");

    of_oxm_ipv6_dst_masked_value_mask_get(obj, &ipv6);
    out += writer(cookie, "value_mask=");
    out += LOCI_SHOW_ipv6_value_mask(writer, cookie, ipv6);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_ipv6_flabel_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_ipv6_flabel_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_oxm_ipv6_flabel_value_get(obj, &val32);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u32_value(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_ipv6_flabel_masked_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_ipv6_flabel_masked_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_oxm_ipv6_flabel_masked_value_get(obj, &val32);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u32_value(writer, cookie, val32);
    out += writer(cookie, " ");

    of_oxm_ipv6_flabel_masked_value_mask_get(obj, &val32);
    out += writer(cookie, "value_mask=");
    out += LOCI_SHOW_u32_value_mask(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_ipv6_nd_sll_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_ipv6_nd_sll_t *obj)
{
    int out = 0;
    of_mac_addr_t mac_addr;

    of_oxm_ipv6_nd_sll_value_get(obj, &mac_addr);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_mac_value(writer, cookie, mac_addr);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_ipv6_nd_sll_masked_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_ipv6_nd_sll_masked_t *obj)
{
    int out = 0;
    of_mac_addr_t mac_addr;

    of_oxm_ipv6_nd_sll_masked_value_get(obj, &mac_addr);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_mac_value(writer, cookie, mac_addr);
    out += writer(cookie, " ");

    of_oxm_ipv6_nd_sll_masked_value_mask_get(obj, &mac_addr);
    out += writer(cookie, "value_mask=");
    out += LOCI_SHOW_mac_value_mask(writer, cookie, mac_addr);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_ipv6_nd_target_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_ipv6_nd_target_t *obj)
{
    int out = 0;
    of_ipv6_t ipv6;

    of_oxm_ipv6_nd_target_value_get(obj, &ipv6);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_ipv6_value(writer, cookie, ipv6);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_ipv6_nd_target_masked_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_ipv6_nd_target_masked_t *obj)
{
    int out = 0;
    of_ipv6_t ipv6;

    of_oxm_ipv6_nd_target_masked_value_get(obj, &ipv6);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_ipv6_value(writer, cookie, ipv6);
    out += writer(cookie, " ");

    of_oxm_ipv6_nd_target_masked_value_mask_get(obj, &ipv6);
    out += writer(cookie, "value_mask=");
    out += LOCI_SHOW_ipv6_value_mask(writer, cookie, ipv6);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_ipv6_nd_tll_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_ipv6_nd_tll_t *obj)
{
    int out = 0;
    of_mac_addr_t mac_addr;

    of_oxm_ipv6_nd_tll_value_get(obj, &mac_addr);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_mac_value(writer, cookie, mac_addr);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_ipv6_nd_tll_masked_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_ipv6_nd_tll_masked_t *obj)
{
    int out = 0;
    of_mac_addr_t mac_addr;

    of_oxm_ipv6_nd_tll_masked_value_get(obj, &mac_addr);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_mac_value(writer, cookie, mac_addr);
    out += writer(cookie, " ");

    of_oxm_ipv6_nd_tll_masked_value_mask_get(obj, &mac_addr);
    out += writer(cookie, "value_mask=");
    out += LOCI_SHOW_mac_value_mask(writer, cookie, mac_addr);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_ipv6_src_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_ipv6_src_t *obj)
{
    int out = 0;
    of_ipv6_t ipv6;

    of_oxm_ipv6_src_value_get(obj, &ipv6);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_ipv6_value(writer, cookie, ipv6);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_ipv6_src_masked_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_ipv6_src_masked_t *obj)
{
    int out = 0;
    of_ipv6_t ipv6;

    of_oxm_ipv6_src_masked_value_get(obj, &ipv6);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_ipv6_value(writer, cookie, ipv6);
    out += writer(cookie, " ");

    of_oxm_ipv6_src_masked_value_mask_get(obj, &ipv6);
    out += writer(cookie, "value_mask=");
    out += LOCI_SHOW_ipv6_value_mask(writer, cookie, ipv6);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_metadata_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_metadata_t *obj)
{
    int out = 0;
    uint64_t val64;

    of_oxm_metadata_value_get(obj, &val64);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u64_value(writer, cookie, val64);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_metadata_masked_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_metadata_masked_t *obj)
{
    int out = 0;
    uint64_t val64;

    of_oxm_metadata_masked_value_get(obj, &val64);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u64_value(writer, cookie, val64);
    out += writer(cookie, " ");

    of_oxm_metadata_masked_value_mask_get(obj, &val64);
    out += writer(cookie, "value_mask=");
    out += LOCI_SHOW_u64_value_mask(writer, cookie, val64);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_mpls_label_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_mpls_label_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_oxm_mpls_label_value_get(obj, &val32);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u32_value(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_mpls_label_masked_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_mpls_label_masked_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_oxm_mpls_label_masked_value_get(obj, &val32);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u32_value(writer, cookie, val32);
    out += writer(cookie, " ");

    of_oxm_mpls_label_masked_value_mask_get(obj, &val32);
    out += writer(cookie, "value_mask=");
    out += LOCI_SHOW_u32_value_mask(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_mpls_tc_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_mpls_tc_t *obj)
{
    int out = 0;
    uint8_t val8;

    of_oxm_mpls_tc_value_get(obj, &val8);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u8_value(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_mpls_tc_masked_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_mpls_tc_masked_t *obj)
{
    int out = 0;
    uint8_t val8;

    of_oxm_mpls_tc_masked_value_get(obj, &val8);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u8_value(writer, cookie, val8);
    out += writer(cookie, " ");

    of_oxm_mpls_tc_masked_value_mask_get(obj, &val8);
    out += writer(cookie, "value_mask=");
    out += LOCI_SHOW_u8_value_mask(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_sctp_dst_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_sctp_dst_t *obj)
{
    int out = 0;
    uint16_t val16;

    of_oxm_sctp_dst_value_get(obj, &val16);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u16_value(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_sctp_dst_masked_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_sctp_dst_masked_t *obj)
{
    int out = 0;
    uint16_t val16;

    of_oxm_sctp_dst_masked_value_get(obj, &val16);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u16_value(writer, cookie, val16);
    out += writer(cookie, " ");

    of_oxm_sctp_dst_masked_value_mask_get(obj, &val16);
    out += writer(cookie, "value_mask=");
    out += LOCI_SHOW_u16_value_mask(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_sctp_src_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_sctp_src_t *obj)
{
    int out = 0;
    uint16_t val16;

    of_oxm_sctp_src_value_get(obj, &val16);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u16_value(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_sctp_src_masked_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_sctp_src_masked_t *obj)
{
    int out = 0;
    uint16_t val16;

    of_oxm_sctp_src_masked_value_get(obj, &val16);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u16_value(writer, cookie, val16);
    out += writer(cookie, " ");

    of_oxm_sctp_src_masked_value_mask_get(obj, &val16);
    out += writer(cookie, "value_mask=");
    out += LOCI_SHOW_u16_value_mask(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_tcp_dst_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_tcp_dst_t *obj)
{
    int out = 0;
    uint16_t val16;

    of_oxm_tcp_dst_value_get(obj, &val16);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u16_value(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_tcp_dst_masked_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_tcp_dst_masked_t *obj)
{
    int out = 0;
    uint16_t val16;

    of_oxm_tcp_dst_masked_value_get(obj, &val16);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u16_value(writer, cookie, val16);
    out += writer(cookie, " ");

    of_oxm_tcp_dst_masked_value_mask_get(obj, &val16);
    out += writer(cookie, "value_mask=");
    out += LOCI_SHOW_u16_value_mask(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_tcp_src_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_tcp_src_t *obj)
{
    int out = 0;
    uint16_t val16;

    of_oxm_tcp_src_value_get(obj, &val16);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u16_value(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_tcp_src_masked_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_tcp_src_masked_t *obj)
{
    int out = 0;
    uint16_t val16;

    of_oxm_tcp_src_masked_value_get(obj, &val16);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u16_value(writer, cookie, val16);
    out += writer(cookie, " ");

    of_oxm_tcp_src_masked_value_mask_get(obj, &val16);
    out += writer(cookie, "value_mask=");
    out += LOCI_SHOW_u16_value_mask(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_udp_dst_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_udp_dst_t *obj)
{
    int out = 0;
    uint16_t val16;

    of_oxm_udp_dst_value_get(obj, &val16);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u16_value(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_udp_dst_masked_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_udp_dst_masked_t *obj)
{
    int out = 0;
    uint16_t val16;

    of_oxm_udp_dst_masked_value_get(obj, &val16);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u16_value(writer, cookie, val16);
    out += writer(cookie, " ");

    of_oxm_udp_dst_masked_value_mask_get(obj, &val16);
    out += writer(cookie, "value_mask=");
    out += LOCI_SHOW_u16_value_mask(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_udp_src_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_udp_src_t *obj)
{
    int out = 0;
    uint16_t val16;

    of_oxm_udp_src_value_get(obj, &val16);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u16_value(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_udp_src_masked_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_udp_src_masked_t *obj)
{
    int out = 0;
    uint16_t val16;

    of_oxm_udp_src_masked_value_get(obj, &val16);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u16_value(writer, cookie, val16);
    out += writer(cookie, " ");

    of_oxm_udp_src_masked_value_mask_get(obj, &val16);
    out += writer(cookie, "value_mask=");
    out += LOCI_SHOW_u16_value_mask(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_vlan_pcp_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_vlan_pcp_t *obj)
{
    int out = 0;
    uint8_t val8;

    of_oxm_vlan_pcp_value_get(obj, &val8);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u8_value(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_vlan_pcp_masked_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_vlan_pcp_masked_t *obj)
{
    int out = 0;
    uint8_t val8;

    of_oxm_vlan_pcp_masked_value_get(obj, &val8);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u8_value(writer, cookie, val8);
    out += writer(cookie, " ");

    of_oxm_vlan_pcp_masked_value_mask_get(obj, &val8);
    out += writer(cookie, "value_mask=");
    out += LOCI_SHOW_u8_value_mask(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_vlan_vid_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_vlan_vid_t *obj)
{
    int out = 0;
    uint16_t val16;

    of_oxm_vlan_vid_value_get(obj, &val16);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u16_value(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_vlan_vid_masked_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_oxm_vlan_vid_masked_t *obj)
{
    int out = 0;
    uint16_t val16;

    of_oxm_vlan_vid_masked_value_get(obj, &val16);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u16_value(writer, cookie, val16);
    out += writer(cookie, " ");

    of_oxm_vlan_vid_masked_value_mask_get(obj, &val16);
    out += writer(cookie, "value_mask=");
    out += LOCI_SHOW_u16_value_mask(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_packet_queue_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_packet_queue_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_port_no_t port_no;

    of_list_queue_prop_t list;
    of_queue_prop_t elt;
    int rv;

    of_packet_queue_queue_id_get(obj, &val32);
    out += writer(cookie, "queue_id=");
    out += LOCI_SHOW_u32_queue_id(writer, cookie, val32);
    out += writer(cookie, " ");

    of_packet_queue_port_get(obj, &port_no);
    out += writer(cookie, "port=");
    out += LOCI_SHOW_port_no_port(writer, cookie, port_no);
    out += writer(cookie, " ");

    out += writer(cookie, "of_queue_prop_t={ ");
    of_packet_queue_properties_bind(obj, &list);
    OF_LIST_QUEUE_PROP_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_port_desc_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_port_desc_t *obj)
{
    int out = 0;
    of_port_no_t port_no;
    of_mac_addr_t mac_addr;
    of_port_name_t port_name;
    uint32_t val32;

    of_port_desc_port_no_get(obj, &port_no);
    out += writer(cookie, "port_no=");
    out += LOCI_SHOW_port_no_port_no(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_port_desc_hw_addr_get(obj, &mac_addr);
    out += writer(cookie, "hw_addr=");
    out += LOCI_SHOW_mac_hw_addr(writer, cookie, mac_addr);
    out += writer(cookie, " ");

    of_port_desc_name_get(obj, &port_name);
    out += writer(cookie, "name=");
    out += LOCI_SHOW_port_name_name(writer, cookie, port_name);
    out += writer(cookie, " ");

    of_port_desc_config_get(obj, &val32);
    out += writer(cookie, "config=");
    out += LOCI_SHOW_u32_config(writer, cookie, val32);
    out += writer(cookie, " ");

    of_port_desc_state_get(obj, &val32);
    out += writer(cookie, "state=");
    out += LOCI_SHOW_u32_state(writer, cookie, val32);
    out += writer(cookie, " ");

    of_port_desc_curr_get(obj, &val32);
    out += writer(cookie, "curr=");
    out += LOCI_SHOW_u32_curr(writer, cookie, val32);
    out += writer(cookie, " ");

    of_port_desc_advertised_get(obj, &val32);
    out += writer(cookie, "advertised=");
    out += LOCI_SHOW_u32_advertised(writer, cookie, val32);
    out += writer(cookie, " ");

    of_port_desc_supported_get(obj, &val32);
    out += writer(cookie, "supported=");
    out += LOCI_SHOW_u32_supported(writer, cookie, val32);
    out += writer(cookie, " ");

    of_port_desc_peer_get(obj, &val32);
    out += writer(cookie, "peer=");
    out += LOCI_SHOW_u32_peer(writer, cookie, val32);
    out += writer(cookie, " ");

    of_port_desc_curr_speed_get(obj, &val32);
    out += writer(cookie, "curr_speed=");
    out += LOCI_SHOW_u32_curr_speed(writer, cookie, val32);
    out += writer(cookie, " ");

    of_port_desc_max_speed_get(obj, &val32);
    out += writer(cookie, "max_speed=");
    out += LOCI_SHOW_u32_max_speed(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_port_stats_entry_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_port_stats_entry_t *obj)
{
    int out = 0;
    of_port_no_t port_no;
    uint64_t val64;

    of_port_stats_entry_port_no_get(obj, &port_no);
    out += writer(cookie, "port_no=");
    out += LOCI_SHOW_port_no_port_no(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_port_stats_entry_rx_packets_get(obj, &val64);
    out += writer(cookie, "rx_packets=");
    out += LOCI_SHOW_u64_rx_packets(writer, cookie, val64);
    out += writer(cookie, " ");

    of_port_stats_entry_tx_packets_get(obj, &val64);
    out += writer(cookie, "tx_packets=");
    out += LOCI_SHOW_u64_tx_packets(writer, cookie, val64);
    out += writer(cookie, " ");

    of_port_stats_entry_rx_bytes_get(obj, &val64);
    out += writer(cookie, "rx_bytes=");
    out += LOCI_SHOW_u64_rx_bytes(writer, cookie, val64);
    out += writer(cookie, " ");

    of_port_stats_entry_tx_bytes_get(obj, &val64);
    out += writer(cookie, "tx_bytes=");
    out += LOCI_SHOW_u64_tx_bytes(writer, cookie, val64);
    out += writer(cookie, " ");

    of_port_stats_entry_rx_dropped_get(obj, &val64);
    out += writer(cookie, "rx_dropped=");
    out += LOCI_SHOW_u64_rx_dropped(writer, cookie, val64);
    out += writer(cookie, " ");

    of_port_stats_entry_tx_dropped_get(obj, &val64);
    out += writer(cookie, "tx_dropped=");
    out += LOCI_SHOW_u64_tx_dropped(writer, cookie, val64);
    out += writer(cookie, " ");

    of_port_stats_entry_rx_errors_get(obj, &val64);
    out += writer(cookie, "rx_errors=");
    out += LOCI_SHOW_u64_rx_errors(writer, cookie, val64);
    out += writer(cookie, " ");

    of_port_stats_entry_tx_errors_get(obj, &val64);
    out += writer(cookie, "tx_errors=");
    out += LOCI_SHOW_u64_tx_errors(writer, cookie, val64);
    out += writer(cookie, " ");

    of_port_stats_entry_rx_frame_err_get(obj, &val64);
    out += writer(cookie, "rx_frame_err=");
    out += LOCI_SHOW_u64_rx_frame_err(writer, cookie, val64);
    out += writer(cookie, " ");

    of_port_stats_entry_rx_over_err_get(obj, &val64);
    out += writer(cookie, "rx_over_err=");
    out += LOCI_SHOW_u64_rx_over_err(writer, cookie, val64);
    out += writer(cookie, " ");

    of_port_stats_entry_rx_crc_err_get(obj, &val64);
    out += writer(cookie, "rx_crc_err=");
    out += LOCI_SHOW_u64_rx_crc_err(writer, cookie, val64);
    out += writer(cookie, " ");

    of_port_stats_entry_collisions_get(obj, &val64);
    out += writer(cookie, "collisions=");
    out += LOCI_SHOW_u64_collisions(writer, cookie, val64);
    out += writer(cookie, " ");

    return out;
}

int
of_queue_prop_experimenter_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_queue_prop_experimenter_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_octets_t octets;

    of_queue_prop_experimenter_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_queue_prop_experimenter_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_queue_prop_header_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_queue_prop_header_t *obj)
{
    int out = 0;

    return out;
}

int
of_queue_prop_max_rate_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_queue_prop_max_rate_t *obj)
{
    int out = 0;
    uint16_t val16;

    of_queue_prop_max_rate_rate_get(obj, &val16);
    out += writer(cookie, "rate=");
    out += LOCI_SHOW_u16_rate(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_queue_prop_min_rate_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_queue_prop_min_rate_t *obj)
{
    int out = 0;
    uint16_t val16;

    of_queue_prop_min_rate_rate_get(obj, &val16);
    out += writer(cookie, "rate=");
    out += LOCI_SHOW_u16_rate(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_queue_stats_entry_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_queue_stats_entry_t *obj)
{
    int out = 0;
    of_port_no_t port_no;
    uint32_t val32;
    uint64_t val64;

    of_queue_stats_entry_port_no_get(obj, &port_no);
    out += writer(cookie, "port_no=");
    out += LOCI_SHOW_port_no_port_no(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_queue_stats_entry_queue_id_get(obj, &val32);
    out += writer(cookie, "queue_id=");
    out += LOCI_SHOW_u32_queue_id(writer, cookie, val32);
    out += writer(cookie, " ");

    of_queue_stats_entry_tx_bytes_get(obj, &val64);
    out += writer(cookie, "tx_bytes=");
    out += LOCI_SHOW_u64_tx_bytes(writer, cookie, val64);
    out += writer(cookie, " ");

    of_queue_stats_entry_tx_packets_get(obj, &val64);
    out += writer(cookie, "tx_packets=");
    out += LOCI_SHOW_u64_tx_packets(writer, cookie, val64);
    out += writer(cookie, " ");

    of_queue_stats_entry_tx_errors_get(obj, &val64);
    out += writer(cookie, "tx_errors=");
    out += LOCI_SHOW_u64_tx_errors(writer, cookie, val64);
    out += writer(cookie, " ");

    return out;
}

int
of_table_stats_entry_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_table_stats_entry_t *obj)
{
    int out = 0;
    uint8_t val8;
    of_table_name_t table_name;
    of_match_bmap_t match_bmap;
    of_wc_bmap_t wc_bmap;
    uint32_t val32;
    uint64_t val64;

    of_table_stats_entry_table_id_get(obj, &val8);
    out += writer(cookie, "table_id=");
    out += LOCI_SHOW_u8_table_id(writer, cookie, val8);
    out += writer(cookie, " ");

    of_table_stats_entry_name_get(obj, &table_name);
    out += writer(cookie, "name=");
    out += LOCI_SHOW_tab_name_name(writer, cookie, table_name);
    out += writer(cookie, " ");

    of_table_stats_entry_match_get(obj, &match_bmap);
    out += writer(cookie, "match=");
    out += LOCI_SHOW_match_bmap_match(writer, cookie, match_bmap);
    out += writer(cookie, " ");

    of_table_stats_entry_wildcards_get(obj, &wc_bmap);
    out += writer(cookie, "wildcards=");
    out += LOCI_SHOW_wc_bmap_wildcards(writer, cookie, wc_bmap);
    out += writer(cookie, " ");

    of_table_stats_entry_write_actions_get(obj, &val32);
    out += writer(cookie, "write_actions=");
    out += LOCI_SHOW_u32_write_actions(writer, cookie, val32);
    out += writer(cookie, " ");

    of_table_stats_entry_apply_actions_get(obj, &val32);
    out += writer(cookie, "apply_actions=");
    out += LOCI_SHOW_u32_apply_actions(writer, cookie, val32);
    out += writer(cookie, " ");

    of_table_stats_entry_write_setfields_get(obj, &val64);
    out += writer(cookie, "write_setfields=");
    out += LOCI_SHOW_u64_write_setfields(writer, cookie, val64);
    out += writer(cookie, " ");

    of_table_stats_entry_apply_setfields_get(obj, &val64);
    out += writer(cookie, "apply_setfields=");
    out += LOCI_SHOW_u64_apply_setfields(writer, cookie, val64);
    out += writer(cookie, " ");

    of_table_stats_entry_metadata_match_get(obj, &val64);
    out += writer(cookie, "metadata_match=");
    out += LOCI_SHOW_u64_metadata_match(writer, cookie, val64);
    out += writer(cookie, " ");

    of_table_stats_entry_metadata_write_get(obj, &val64);
    out += writer(cookie, "metadata_write=");
    out += LOCI_SHOW_u64_metadata_write(writer, cookie, val64);
    out += writer(cookie, " ");

    of_table_stats_entry_instructions_get(obj, &val32);
    out += writer(cookie, "instructions=");
    out += LOCI_SHOW_u32_instructions(writer, cookie, val32);
    out += writer(cookie, " ");

    of_table_stats_entry_config_get(obj, &val32);
    out += writer(cookie, "config=");
    out += LOCI_SHOW_u32_config(writer, cookie, val32);
    out += writer(cookie, " ");

    of_table_stats_entry_max_entries_get(obj, &val32);
    out += writer(cookie, "max_entries=");
    out += LOCI_SHOW_u32_max_entries(writer, cookie, val32);
    out += writer(cookie, " ");

    of_table_stats_entry_active_count_get(obj, &val32);
    out += writer(cookie, "active_count=");
    out += LOCI_SHOW_u32_active_count(writer, cookie, val32);
    out += writer(cookie, " ");

    of_table_stats_entry_lookup_count_get(obj, &val64);
    out += writer(cookie, "lookup_count=");
    out += LOCI_SHOW_u64_lookup_count(writer, cookie, val64);
    out += writer(cookie, " ");

    of_table_stats_entry_matched_count_get(obj, &val64);
    out += writer(cookie, "matched_count=");
    out += LOCI_SHOW_u64_matched_count(writer, cookie, val64);
    out += writer(cookie, " ");

    return out;
}

int
of_list_action_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_list_action_t *obj)
{
    int out = 0;

    return out;
}

int
of_list_bsn_interface_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_list_bsn_interface_t *obj)
{
    int out = 0;

    return out;
}

int
of_list_bucket_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_list_bucket_t *obj)
{
    int out = 0;

    return out;
}

int
of_list_bucket_counter_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_list_bucket_counter_t *obj)
{
    int out = 0;

    return out;
}

int
of_list_flow_stats_entry_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_list_flow_stats_entry_t *obj)
{
    int out = 0;

    return out;
}

int
of_list_group_desc_stats_entry_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_list_group_desc_stats_entry_t *obj)
{
    int out = 0;

    return out;
}

int
of_list_group_stats_entry_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_list_group_stats_entry_t *obj)
{
    int out = 0;

    return out;
}

int
of_list_instruction_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_list_instruction_t *obj)
{
    int out = 0;

    return out;
}

int
of_list_oxm_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_list_oxm_t *obj)
{
    int out = 0;

    return out;
}

int
of_list_packet_queue_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_list_packet_queue_t *obj)
{
    int out = 0;

    return out;
}

int
of_list_port_desc_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_list_port_desc_t *obj)
{
    int out = 0;

    return out;
}

int
of_list_port_stats_entry_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_list_port_stats_entry_t *obj)
{
    int out = 0;

    return out;
}

int
of_list_queue_prop_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_list_queue_prop_t *obj)
{
    int out = 0;

    return out;
}

int
of_list_queue_stats_entry_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_list_queue_stats_entry_t *obj)
{
    int out = 0;

    return out;
}

int
of_list_table_stats_entry_OF_VERSION_1_2_show(loci_writer_f writer, void* cookie, of_list_table_stats_entry_t *obj)
{
    int out = 0;

    return out;
}

int
of_aggregate_stats_reply_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_aggregate_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    uint64_t val64;

    of_aggregate_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_aggregate_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    of_aggregate_stats_reply_packet_count_get(obj, &val64);
    out += writer(cookie, "packet_count=");
    out += LOCI_SHOW_u64_packet_count(writer, cookie, val64);
    out += writer(cookie, " ");

    of_aggregate_stats_reply_byte_count_get(obj, &val64);
    out += writer(cookie, "byte_count=");
    out += LOCI_SHOW_u64_byte_count(writer, cookie, val64);
    out += writer(cookie, " ");

    of_aggregate_stats_reply_flow_count_get(obj, &val32);
    out += writer(cookie, "flow_count=");
    out += LOCI_SHOW_u32_flow_count(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_aggregate_stats_request_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_aggregate_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    uint8_t val8;
    of_port_no_t port_no;
    uint64_t val64;
    of_match_t match;

    of_aggregate_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_aggregate_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    of_aggregate_stats_request_table_id_get(obj, &val8);
    out += writer(cookie, "table_id=");
    out += LOCI_SHOW_u8_table_id(writer, cookie, val8);
    out += writer(cookie, " ");

    of_aggregate_stats_request_out_port_get(obj, &port_no);
    out += writer(cookie, "out_port=");
    out += LOCI_SHOW_port_no_out_port(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_aggregate_stats_request_out_group_get(obj, &val32);
    out += writer(cookie, "out_group=");
    out += LOCI_SHOW_u32_out_group(writer, cookie, val32);
    out += writer(cookie, " ");

    of_aggregate_stats_request_cookie_get(obj, &val64);
    out += writer(cookie, "cookie=");
    out += LOCI_SHOW_u64_cookie(writer, cookie, val64);
    out += writer(cookie, " ");

    of_aggregate_stats_request_cookie_mask_get(obj, &val64);
    out += writer(cookie, "cookie_mask=");
    out += LOCI_SHOW_u64_cookie_mask(writer, cookie, val64);
    out += writer(cookie, " ");

    of_aggregate_stats_request_match_get(obj, &match);
    out += writer(cookie, "match=");
    out += LOCI_SHOW_match_match(writer, cookie, match);
    out += writer(cookie, " ");

    return out;
}

int
of_async_get_reply_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_async_get_reply_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_async_get_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_async_get_reply_packet_in_mask_equal_master_get(obj, &val32);
    out += writer(cookie, "packet_in_mask_equal_master=");
    out += LOCI_SHOW_u32_packet_in_mask_equal_master(writer, cookie, val32);
    out += writer(cookie, " ");

    of_async_get_reply_packet_in_mask_slave_get(obj, &val32);
    out += writer(cookie, "packet_in_mask_slave=");
    out += LOCI_SHOW_u32_packet_in_mask_slave(writer, cookie, val32);
    out += writer(cookie, " ");

    of_async_get_reply_port_status_mask_equal_master_get(obj, &val32);
    out += writer(cookie, "port_status_mask_equal_master=");
    out += LOCI_SHOW_u32_port_status_mask_equal_master(writer, cookie, val32);
    out += writer(cookie, " ");

    of_async_get_reply_port_status_mask_slave_get(obj, &val32);
    out += writer(cookie, "port_status_mask_slave=");
    out += LOCI_SHOW_u32_port_status_mask_slave(writer, cookie, val32);
    out += writer(cookie, " ");

    of_async_get_reply_flow_removed_mask_equal_master_get(obj, &val32);
    out += writer(cookie, "flow_removed_mask_equal_master=");
    out += LOCI_SHOW_u32_flow_removed_mask_equal_master(writer, cookie, val32);
    out += writer(cookie, " ");

    of_async_get_reply_flow_removed_mask_slave_get(obj, &val32);
    out += writer(cookie, "flow_removed_mask_slave=");
    out += LOCI_SHOW_u32_flow_removed_mask_slave(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_async_get_request_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_async_get_request_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_async_get_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_async_get_request_packet_in_mask_equal_master_get(obj, &val32);
    out += writer(cookie, "packet_in_mask_equal_master=");
    out += LOCI_SHOW_u32_packet_in_mask_equal_master(writer, cookie, val32);
    out += writer(cookie, " ");

    of_async_get_request_packet_in_mask_slave_get(obj, &val32);
    out += writer(cookie, "packet_in_mask_slave=");
    out += LOCI_SHOW_u32_packet_in_mask_slave(writer, cookie, val32);
    out += writer(cookie, " ");

    of_async_get_request_port_status_mask_equal_master_get(obj, &val32);
    out += writer(cookie, "port_status_mask_equal_master=");
    out += LOCI_SHOW_u32_port_status_mask_equal_master(writer, cookie, val32);
    out += writer(cookie, " ");

    of_async_get_request_port_status_mask_slave_get(obj, &val32);
    out += writer(cookie, "port_status_mask_slave=");
    out += LOCI_SHOW_u32_port_status_mask_slave(writer, cookie, val32);
    out += writer(cookie, " ");

    of_async_get_request_flow_removed_mask_equal_master_get(obj, &val32);
    out += writer(cookie, "flow_removed_mask_equal_master=");
    out += LOCI_SHOW_u32_flow_removed_mask_equal_master(writer, cookie, val32);
    out += writer(cookie, " ");

    of_async_get_request_flow_removed_mask_slave_get(obj, &val32);
    out += writer(cookie, "flow_removed_mask_slave=");
    out += LOCI_SHOW_u32_flow_removed_mask_slave(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_async_set_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_async_set_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_async_set_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_async_set_packet_in_mask_equal_master_get(obj, &val32);
    out += writer(cookie, "packet_in_mask_equal_master=");
    out += LOCI_SHOW_u32_packet_in_mask_equal_master(writer, cookie, val32);
    out += writer(cookie, " ");

    of_async_set_packet_in_mask_slave_get(obj, &val32);
    out += writer(cookie, "packet_in_mask_slave=");
    out += LOCI_SHOW_u32_packet_in_mask_slave(writer, cookie, val32);
    out += writer(cookie, " ");

    of_async_set_port_status_mask_equal_master_get(obj, &val32);
    out += writer(cookie, "port_status_mask_equal_master=");
    out += LOCI_SHOW_u32_port_status_mask_equal_master(writer, cookie, val32);
    out += writer(cookie, " ");

    of_async_set_port_status_mask_slave_get(obj, &val32);
    out += writer(cookie, "port_status_mask_slave=");
    out += LOCI_SHOW_u32_port_status_mask_slave(writer, cookie, val32);
    out += writer(cookie, " ");

    of_async_set_flow_removed_mask_equal_master_get(obj, &val32);
    out += writer(cookie, "flow_removed_mask_equal_master=");
    out += LOCI_SHOW_u32_flow_removed_mask_equal_master(writer, cookie, val32);
    out += writer(cookie, " ");

    of_async_set_flow_removed_mask_slave_get(obj, &val32);
    out += writer(cookie, "flow_removed_mask_slave=");
    out += LOCI_SHOW_u32_flow_removed_mask_slave(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_bad_action_error_msg_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_bad_action_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    of_bad_action_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bad_action_error_msg_code_get(obj, &val16);
    out += writer(cookie, "code=");
    out += LOCI_SHOW_u16_code(writer, cookie, val16);
    out += writer(cookie, " ");

    of_bad_action_error_msg_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_bad_instruction_error_msg_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_bad_instruction_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    of_bad_instruction_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bad_instruction_error_msg_code_get(obj, &val16);
    out += writer(cookie, "code=");
    out += LOCI_SHOW_u16_code(writer, cookie, val16);
    out += writer(cookie, " ");

    of_bad_instruction_error_msg_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_bad_match_error_msg_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_bad_match_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    of_bad_match_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bad_match_error_msg_code_get(obj, &val16);
    out += writer(cookie, "code=");
    out += LOCI_SHOW_u16_code(writer, cookie, val16);
    out += writer(cookie, " ");

    of_bad_match_error_msg_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_bad_request_error_msg_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_bad_request_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    of_bad_request_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bad_request_error_msg_code_get(obj, &val16);
    out += writer(cookie, "code=");
    out += LOCI_SHOW_u16_code(writer, cookie, val16);
    out += writer(cookie, " ");

    of_bad_request_error_msg_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_barrier_reply_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_barrier_reply_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_barrier_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_barrier_request_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_barrier_request_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_barrier_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_bw_clear_data_reply_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_bsn_bw_clear_data_reply_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_bsn_bw_clear_data_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_bw_clear_data_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_bw_clear_data_reply_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_bw_clear_data_reply_status_get(obj, &val32);
    out += writer(cookie, "status=");
    out += LOCI_SHOW_u32_status(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_bw_clear_data_request_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_bsn_bw_clear_data_request_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_bsn_bw_clear_data_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_bw_clear_data_request_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_bw_clear_data_request_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_bw_enable_get_reply_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_bsn_bw_enable_get_reply_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_bsn_bw_enable_get_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_bw_enable_get_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_bw_enable_get_reply_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_bw_enable_get_reply_enabled_get(obj, &val32);
    out += writer(cookie, "enabled=");
    out += LOCI_SHOW_u32_enabled(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_bw_enable_get_request_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_bsn_bw_enable_get_request_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_bsn_bw_enable_get_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_bw_enable_get_request_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_bw_enable_get_request_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_bw_enable_set_reply_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_bsn_bw_enable_set_reply_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_bsn_bw_enable_set_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_bw_enable_set_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_bw_enable_set_reply_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_bw_enable_set_reply_enable_get(obj, &val32);
    out += writer(cookie, "enable=");
    out += LOCI_SHOW_u32_enable(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_bw_enable_set_reply_status_get(obj, &val32);
    out += writer(cookie, "status=");
    out += LOCI_SHOW_u32_status(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_bw_enable_set_request_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_bsn_bw_enable_set_request_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_bsn_bw_enable_set_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_bw_enable_set_request_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_bw_enable_set_request_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_bw_enable_set_request_enable_get(obj, &val32);
    out += writer(cookie, "enable=");
    out += LOCI_SHOW_u32_enable(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_flow_idle_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_bsn_flow_idle_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint64_t val64;
    uint16_t val16;
    uint8_t val8;
    of_match_t match;

    of_bsn_flow_idle_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_flow_idle_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_flow_idle_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_flow_idle_cookie_get(obj, &val64);
    out += writer(cookie, "cookie=");
    out += LOCI_SHOW_u64_cookie(writer, cookie, val64);
    out += writer(cookie, " ");

    of_bsn_flow_idle_priority_get(obj, &val16);
    out += writer(cookie, "priority=");
    out += LOCI_SHOW_u16_priority(writer, cookie, val16);
    out += writer(cookie, " ");

    of_bsn_flow_idle_table_id_get(obj, &val8);
    out += writer(cookie, "table_id=");
    out += LOCI_SHOW_u8_table_id(writer, cookie, val8);
    out += writer(cookie, " ");

    of_bsn_flow_idle_match_get(obj, &match);
    out += writer(cookie, "match=");
    out += LOCI_SHOW_match_match(writer, cookie, match);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_flow_idle_enable_get_reply_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_bsn_flow_idle_enable_get_reply_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_bsn_flow_idle_enable_get_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_flow_idle_enable_get_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_flow_idle_enable_get_reply_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_flow_idle_enable_get_reply_enabled_get(obj, &val32);
    out += writer(cookie, "enabled=");
    out += LOCI_SHOW_u32_enabled(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_flow_idle_enable_get_request_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_bsn_flow_idle_enable_get_request_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_bsn_flow_idle_enable_get_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_flow_idle_enable_get_request_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_flow_idle_enable_get_request_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_flow_idle_enable_set_reply_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_bsn_flow_idle_enable_set_reply_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_bsn_flow_idle_enable_set_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_flow_idle_enable_set_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_flow_idle_enable_set_reply_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_flow_idle_enable_set_reply_enable_get(obj, &val32);
    out += writer(cookie, "enable=");
    out += LOCI_SHOW_u32_enable(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_flow_idle_enable_set_reply_status_get(obj, &val32);
    out += writer(cookie, "status=");
    out += LOCI_SHOW_u32_status(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_flow_idle_enable_set_request_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_bsn_flow_idle_enable_set_request_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_bsn_flow_idle_enable_set_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_flow_idle_enable_set_request_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_flow_idle_enable_set_request_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_flow_idle_enable_set_request_enable_get(obj, &val32);
    out += writer(cookie, "enable=");
    out += LOCI_SHOW_u32_enable(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_get_interfaces_reply_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_bsn_get_interfaces_reply_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_list_bsn_interface_t list;
    of_bsn_interface_t elt;
    int rv;

    of_bsn_get_interfaces_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_get_interfaces_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_get_interfaces_reply_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    out += writer(cookie, "of_bsn_interface_t={ ");
    of_bsn_get_interfaces_reply_interfaces_bind(obj, &list);
    OF_LIST_BSN_INTERFACE_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_bsn_get_interfaces_request_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_bsn_get_interfaces_request_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_bsn_get_interfaces_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_get_interfaces_request_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_get_interfaces_request_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_get_mirroring_reply_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_bsn_get_mirroring_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint8_t val8;

    of_bsn_get_mirroring_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_get_mirroring_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_get_mirroring_reply_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_get_mirroring_reply_report_mirror_ports_get(obj, &val8);
    out += writer(cookie, "report_mirror_ports=");
    out += LOCI_SHOW_u8_report_mirror_ports(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_get_mirroring_request_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_bsn_get_mirroring_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint8_t val8;

    of_bsn_get_mirroring_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_get_mirroring_request_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_get_mirroring_request_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_get_mirroring_request_report_mirror_ports_get(obj, &val8);
    out += writer(cookie, "report_mirror_ports=");
    out += LOCI_SHOW_u8_report_mirror_ports(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_header_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_bsn_header_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_bsn_header_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_header_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_header_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_lacp_convergence_notif_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_bsn_lacp_convergence_notif_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint8_t val8;
    of_port_no_t port_no;
    uint16_t val16;
    of_mac_addr_t mac_addr;

    of_bsn_lacp_convergence_notif_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_lacp_convergence_notif_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_lacp_convergence_notif_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_lacp_convergence_notif_convergence_status_get(obj, &val8);
    out += writer(cookie, "convergence_status=");
    out += LOCI_SHOW_u8_convergence_status(writer, cookie, val8);
    out += writer(cookie, " ");

    of_bsn_lacp_convergence_notif_port_no_get(obj, &port_no);
    out += writer(cookie, "port_no=");
    out += LOCI_SHOW_port_no_port_no(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_bsn_lacp_convergence_notif_actor_sys_priority_get(obj, &val16);
    out += writer(cookie, "actor_sys_priority=");
    out += LOCI_SHOW_u16_actor_sys_priority(writer, cookie, val16);
    out += writer(cookie, " ");

    of_bsn_lacp_convergence_notif_actor_sys_mac_get(obj, &mac_addr);
    out += writer(cookie, "actor_sys_mac=");
    out += LOCI_SHOW_mac_actor_sys_mac(writer, cookie, mac_addr);
    out += writer(cookie, " ");

    of_bsn_lacp_convergence_notif_actor_port_priority_get(obj, &val16);
    out += writer(cookie, "actor_port_priority=");
    out += LOCI_SHOW_u16_actor_port_priority(writer, cookie, val16);
    out += writer(cookie, " ");

    of_bsn_lacp_convergence_notif_actor_port_num_get(obj, &val16);
    out += writer(cookie, "actor_port_num=");
    out += LOCI_SHOW_u16_actor_port_num(writer, cookie, val16);
    out += writer(cookie, " ");

    of_bsn_lacp_convergence_notif_actor_key_get(obj, &val16);
    out += writer(cookie, "actor_key=");
    out += LOCI_SHOW_u16_actor_key(writer, cookie, val16);
    out += writer(cookie, " ");

    of_bsn_lacp_convergence_notif_partner_sys_priority_get(obj, &val16);
    out += writer(cookie, "partner_sys_priority=");
    out += LOCI_SHOW_u16_partner_sys_priority(writer, cookie, val16);
    out += writer(cookie, " ");

    of_bsn_lacp_convergence_notif_partner_sys_mac_get(obj, &mac_addr);
    out += writer(cookie, "partner_sys_mac=");
    out += LOCI_SHOW_mac_partner_sys_mac(writer, cookie, mac_addr);
    out += writer(cookie, " ");

    of_bsn_lacp_convergence_notif_partner_port_priority_get(obj, &val16);
    out += writer(cookie, "partner_port_priority=");
    out += LOCI_SHOW_u16_partner_port_priority(writer, cookie, val16);
    out += writer(cookie, " ");

    of_bsn_lacp_convergence_notif_partner_port_num_get(obj, &val16);
    out += writer(cookie, "partner_port_num=");
    out += LOCI_SHOW_u16_partner_port_num(writer, cookie, val16);
    out += writer(cookie, " ");

    of_bsn_lacp_convergence_notif_partner_key_get(obj, &val16);
    out += writer(cookie, "partner_key=");
    out += LOCI_SHOW_u16_partner_key(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_lacp_stats_reply_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_bsn_lacp_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_list_bsn_lacp_stats_entry_t list;
    of_bsn_lacp_stats_entry_t elt;
    int rv;

    of_bsn_lacp_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_lacp_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    of_bsn_lacp_stats_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_lacp_stats_reply_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    out += writer(cookie, "of_bsn_lacp_stats_entry_t={ ");
    of_bsn_lacp_stats_reply_entries_bind(obj, &list);
    OF_LIST_BSN_LACP_STATS_ENTRY_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_bsn_lacp_stats_request_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_bsn_lacp_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_bsn_lacp_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_lacp_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    of_bsn_lacp_stats_request_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_lacp_stats_request_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_pdu_rx_reply_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_bsn_pdu_rx_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_port_no_t port_no;
    uint8_t val8;

    of_bsn_pdu_rx_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_pdu_rx_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_pdu_rx_reply_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_pdu_rx_reply_status_get(obj, &val32);
    out += writer(cookie, "status=");
    out += LOCI_SHOW_u32_status(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_pdu_rx_reply_port_no_get(obj, &port_no);
    out += writer(cookie, "port_no=");
    out += LOCI_SHOW_port_no_port_no(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_bsn_pdu_rx_reply_slot_num_get(obj, &val8);
    out += writer(cookie, "slot_num=");
    out += LOCI_SHOW_u8_slot_num(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_pdu_rx_request_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_bsn_pdu_rx_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_port_no_t port_no;
    uint8_t val8;
    of_octets_t octets;

    of_bsn_pdu_rx_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_pdu_rx_request_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_pdu_rx_request_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_pdu_rx_request_timeout_ms_get(obj, &val32);
    out += writer(cookie, "timeout_ms=");
    out += LOCI_SHOW_u32_timeout_ms(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_pdu_rx_request_port_no_get(obj, &port_no);
    out += writer(cookie, "port_no=");
    out += LOCI_SHOW_port_no_port_no(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_bsn_pdu_rx_request_slot_num_get(obj, &val8);
    out += writer(cookie, "slot_num=");
    out += LOCI_SHOW_u8_slot_num(writer, cookie, val8);
    out += writer(cookie, " ");

    of_bsn_pdu_rx_request_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_pdu_rx_timeout_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_bsn_pdu_rx_timeout_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_port_no_t port_no;
    uint8_t val8;

    of_bsn_pdu_rx_timeout_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_pdu_rx_timeout_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_pdu_rx_timeout_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_pdu_rx_timeout_port_no_get(obj, &port_no);
    out += writer(cookie, "port_no=");
    out += LOCI_SHOW_port_no_port_no(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_bsn_pdu_rx_timeout_slot_num_get(obj, &val8);
    out += writer(cookie, "slot_num=");
    out += LOCI_SHOW_u8_slot_num(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_pdu_tx_reply_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_bsn_pdu_tx_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_port_no_t port_no;
    uint8_t val8;

    of_bsn_pdu_tx_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_pdu_tx_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_pdu_tx_reply_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_pdu_tx_reply_status_get(obj, &val32);
    out += writer(cookie, "status=");
    out += LOCI_SHOW_u32_status(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_pdu_tx_reply_port_no_get(obj, &port_no);
    out += writer(cookie, "port_no=");
    out += LOCI_SHOW_port_no_port_no(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_bsn_pdu_tx_reply_slot_num_get(obj, &val8);
    out += writer(cookie, "slot_num=");
    out += LOCI_SHOW_u8_slot_num(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_pdu_tx_request_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_bsn_pdu_tx_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_port_no_t port_no;
    uint8_t val8;
    of_octets_t octets;

    of_bsn_pdu_tx_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_pdu_tx_request_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_pdu_tx_request_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_pdu_tx_request_tx_interval_ms_get(obj, &val32);
    out += writer(cookie, "tx_interval_ms=");
    out += LOCI_SHOW_u32_tx_interval_ms(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_pdu_tx_request_port_no_get(obj, &port_no);
    out += writer(cookie, "port_no=");
    out += LOCI_SHOW_port_no_port_no(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_bsn_pdu_tx_request_slot_num_get(obj, &val8);
    out += writer(cookie, "slot_num=");
    out += LOCI_SHOW_u8_slot_num(writer, cookie, val8);
    out += writer(cookie, " ");

    of_bsn_pdu_tx_request_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_set_lacp_reply_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_bsn_set_lacp_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_port_no_t port_no;

    of_bsn_set_lacp_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_set_lacp_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_set_lacp_reply_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_set_lacp_reply_status_get(obj, &val32);
    out += writer(cookie, "status=");
    out += LOCI_SHOW_u32_status(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_set_lacp_reply_port_no_get(obj, &port_no);
    out += writer(cookie, "port_no=");
    out += LOCI_SHOW_port_no_port_no(writer, cookie, port_no);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_set_lacp_request_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_bsn_set_lacp_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint8_t val8;
    of_port_no_t port_no;
    uint16_t val16;
    of_mac_addr_t mac_addr;

    of_bsn_set_lacp_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_set_lacp_request_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_set_lacp_request_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_set_lacp_request_enabled_get(obj, &val8);
    out += writer(cookie, "enabled=");
    out += LOCI_SHOW_u8_enabled(writer, cookie, val8);
    out += writer(cookie, " ");

    of_bsn_set_lacp_request_port_no_get(obj, &port_no);
    out += writer(cookie, "port_no=");
    out += LOCI_SHOW_port_no_port_no(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_bsn_set_lacp_request_actor_sys_priority_get(obj, &val16);
    out += writer(cookie, "actor_sys_priority=");
    out += LOCI_SHOW_u16_actor_sys_priority(writer, cookie, val16);
    out += writer(cookie, " ");

    of_bsn_set_lacp_request_actor_sys_mac_get(obj, &mac_addr);
    out += writer(cookie, "actor_sys_mac=");
    out += LOCI_SHOW_mac_actor_sys_mac(writer, cookie, mac_addr);
    out += writer(cookie, " ");

    of_bsn_set_lacp_request_actor_port_priority_get(obj, &val16);
    out += writer(cookie, "actor_port_priority=");
    out += LOCI_SHOW_u16_actor_port_priority(writer, cookie, val16);
    out += writer(cookie, " ");

    of_bsn_set_lacp_request_actor_port_num_get(obj, &val16);
    out += writer(cookie, "actor_port_num=");
    out += LOCI_SHOW_u16_actor_port_num(writer, cookie, val16);
    out += writer(cookie, " ");

    of_bsn_set_lacp_request_actor_key_get(obj, &val16);
    out += writer(cookie, "actor_key=");
    out += LOCI_SHOW_u16_actor_key(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_set_mirroring_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_bsn_set_mirroring_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint8_t val8;

    of_bsn_set_mirroring_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_set_mirroring_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_set_mirroring_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_set_mirroring_report_mirror_ports_get(obj, &val8);
    out += writer(cookie, "report_mirror_ports=");
    out += LOCI_SHOW_u8_report_mirror_ports(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_set_pktin_suppression_reply_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_bsn_set_pktin_suppression_reply_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_bsn_set_pktin_suppression_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_set_pktin_suppression_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_set_pktin_suppression_reply_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_set_pktin_suppression_reply_status_get(obj, &val32);
    out += writer(cookie, "status=");
    out += LOCI_SHOW_u32_status(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_set_pktin_suppression_request_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_bsn_set_pktin_suppression_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint8_t val8;
    uint16_t val16;
    uint64_t val64;

    of_bsn_set_pktin_suppression_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_set_pktin_suppression_request_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_set_pktin_suppression_request_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_set_pktin_suppression_request_enabled_get(obj, &val8);
    out += writer(cookie, "enabled=");
    out += LOCI_SHOW_u8_enabled(writer, cookie, val8);
    out += writer(cookie, " ");

    of_bsn_set_pktin_suppression_request_idle_timeout_get(obj, &val16);
    out += writer(cookie, "idle_timeout=");
    out += LOCI_SHOW_u16_idle_timeout(writer, cookie, val16);
    out += writer(cookie, " ");

    of_bsn_set_pktin_suppression_request_hard_timeout_get(obj, &val16);
    out += writer(cookie, "hard_timeout=");
    out += LOCI_SHOW_u16_hard_timeout(writer, cookie, val16);
    out += writer(cookie, " ");

    of_bsn_set_pktin_suppression_request_priority_get(obj, &val16);
    out += writer(cookie, "priority=");
    out += LOCI_SHOW_u16_priority(writer, cookie, val16);
    out += writer(cookie, " ");

    of_bsn_set_pktin_suppression_request_cookie_get(obj, &val64);
    out += writer(cookie, "cookie=");
    out += LOCI_SHOW_u64_cookie(writer, cookie, val64);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_stats_reply_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_bsn_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_bsn_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    of_bsn_stats_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_stats_reply_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_stats_request_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_bsn_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_bsn_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    of_bsn_stats_request_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_stats_request_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_time_reply_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_bsn_time_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint64_t val64;

    of_bsn_time_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_time_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_time_reply_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_time_reply_time_ms_get(obj, &val64);
    out += writer(cookie, "time_ms=");
    out += LOCI_SHOW_u64_time_ms(writer, cookie, val64);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_time_request_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_bsn_time_request_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_bsn_time_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_time_request_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_time_request_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_virtual_port_create_reply_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_bsn_virtual_port_create_reply_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_bsn_virtual_port_create_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_virtual_port_create_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_virtual_port_create_reply_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_virtual_port_create_reply_status_get(obj, &val32);
    out += writer(cookie, "status=");
    out += LOCI_SHOW_u32_status(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_virtual_port_create_reply_vport_no_get(obj, &val32);
    out += writer(cookie, "vport_no=");
    out += LOCI_SHOW_u32_vport_no(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_virtual_port_create_request_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_bsn_virtual_port_create_request_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_bsn_vport_q_in_q_t vport;

    of_bsn_virtual_port_create_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_virtual_port_create_request_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_virtual_port_create_request_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_virtual_port_create_request_vport_bind(obj, &vport);
    out += of_bsn_vport_q_in_q_OF_VERSION_1_3_show(writer, cookie, &vport);

    return out;
}

int
of_bsn_virtual_port_remove_reply_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_bsn_virtual_port_remove_reply_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_bsn_virtual_port_remove_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_virtual_port_remove_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_virtual_port_remove_reply_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_virtual_port_remove_reply_status_get(obj, &val32);
    out += writer(cookie, "status=");
    out += LOCI_SHOW_u32_status(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_virtual_port_remove_request_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_bsn_virtual_port_remove_request_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_bsn_virtual_port_remove_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_virtual_port_remove_request_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_virtual_port_remove_request_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_virtual_port_remove_request_vport_no_get(obj, &val32);
    out += writer(cookie, "vport_no=");
    out += LOCI_SHOW_u32_vport_no(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_desc_stats_reply_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_desc_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_desc_str_t desc_str;
    of_serial_num_t ser_num;

    of_desc_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_desc_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    of_desc_stats_reply_mfr_desc_get(obj, &desc_str);
    out += writer(cookie, "mfr_desc=");
    out += LOCI_SHOW_desc_str_mfr_desc(writer, cookie, desc_str);
    out += writer(cookie, " ");

    of_desc_stats_reply_hw_desc_get(obj, &desc_str);
    out += writer(cookie, "hw_desc=");
    out += LOCI_SHOW_desc_str_hw_desc(writer, cookie, desc_str);
    out += writer(cookie, " ");

    of_desc_stats_reply_sw_desc_get(obj, &desc_str);
    out += writer(cookie, "sw_desc=");
    out += LOCI_SHOW_desc_str_sw_desc(writer, cookie, desc_str);
    out += writer(cookie, " ");

    of_desc_stats_reply_serial_num_get(obj, &ser_num);
    out += writer(cookie, "serial_num=");
    out += LOCI_SHOW_ser_num_serial_num(writer, cookie, ser_num);
    out += writer(cookie, " ");

    of_desc_stats_reply_dp_desc_get(obj, &desc_str);
    out += writer(cookie, "dp_desc=");
    out += LOCI_SHOW_desc_str_dp_desc(writer, cookie, desc_str);
    out += writer(cookie, " ");

    return out;
}

int
of_desc_stats_request_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_desc_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_desc_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_desc_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_echo_reply_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_echo_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_octets_t octets;

    of_echo_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_echo_reply_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_echo_request_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_echo_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_octets_t octets;

    of_echo_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_echo_request_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_error_msg_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_experimenter_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_experimenter_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_octets_t octets;

    of_experimenter_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_experimenter_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_experimenter_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_experimenter_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_experimenter_error_msg_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_experimenter_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    of_experimenter_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_experimenter_error_msg_subtype_get(obj, &val16);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u16_subtype(writer, cookie, val16);
    out += writer(cookie, " ");

    of_experimenter_error_msg_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_experimenter_error_msg_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_experimenter_stats_reply_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_experimenter_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_experimenter_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_experimenter_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    of_experimenter_stats_reply_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_experimenter_stats_reply_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_experimenter_stats_request_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_experimenter_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_experimenter_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_experimenter_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    of_experimenter_stats_request_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_experimenter_stats_request_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_features_reply_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_features_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint64_t val64;
    uint8_t val8;

    of_features_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_features_reply_datapath_id_get(obj, &val64);
    out += writer(cookie, "datapath_id=");
    out += LOCI_SHOW_u64_datapath_id(writer, cookie, val64);
    out += writer(cookie, " ");

    of_features_reply_n_buffers_get(obj, &val32);
    out += writer(cookie, "n_buffers=");
    out += LOCI_SHOW_u32_n_buffers(writer, cookie, val32);
    out += writer(cookie, " ");

    of_features_reply_n_tables_get(obj, &val8);
    out += writer(cookie, "n_tables=");
    out += LOCI_SHOW_u8_n_tables(writer, cookie, val8);
    out += writer(cookie, " ");

    of_features_reply_auxiliary_id_get(obj, &val8);
    out += writer(cookie, "auxiliary_id=");
    out += LOCI_SHOW_u8_auxiliary_id(writer, cookie, val8);
    out += writer(cookie, " ");

    of_features_reply_capabilities_get(obj, &val32);
    out += writer(cookie, "capabilities=");
    out += LOCI_SHOW_u32_capabilities(writer, cookie, val32);
    out += writer(cookie, " ");

    of_features_reply_reserved_get(obj, &val32);
    out += writer(cookie, "reserved=");
    out += LOCI_SHOW_u32_reserved(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_features_request_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_features_request_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_features_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_flow_add_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_flow_add_t *obj)
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

    of_flow_add_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_add_cookie_get(obj, &val64);
    out += writer(cookie, "cookie=");
    out += LOCI_SHOW_u64_cookie(writer, cookie, val64);
    out += writer(cookie, " ");

    of_flow_add_cookie_mask_get(obj, &val64);
    out += writer(cookie, "cookie_mask=");
    out += LOCI_SHOW_u64_cookie_mask(writer, cookie, val64);
    out += writer(cookie, " ");

    of_flow_add_table_id_get(obj, &val8);
    out += writer(cookie, "table_id=");
    out += LOCI_SHOW_u8_table_id(writer, cookie, val8);
    out += writer(cookie, " ");

    of_flow_add_idle_timeout_get(obj, &val16);
    out += writer(cookie, "idle_timeout=");
    out += LOCI_SHOW_u16_idle_timeout(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_add_hard_timeout_get(obj, &val16);
    out += writer(cookie, "hard_timeout=");
    out += LOCI_SHOW_u16_hard_timeout(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_add_priority_get(obj, &val16);
    out += writer(cookie, "priority=");
    out += LOCI_SHOW_u16_priority(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_add_buffer_id_get(obj, &val32);
    out += writer(cookie, "buffer_id=");
    out += LOCI_SHOW_u32_buffer_id(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_add_out_port_get(obj, &port_no);
    out += writer(cookie, "out_port=");
    out += LOCI_SHOW_port_no_out_port(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_flow_add_out_group_get(obj, &val32);
    out += writer(cookie, "out_group=");
    out += LOCI_SHOW_u32_out_group(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_add_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_add_match_get(obj, &match);
    out += writer(cookie, "match=");
    out += LOCI_SHOW_match_match(writer, cookie, match);
    out += writer(cookie, " ");

    out += writer(cookie, "of_instruction_t={ ");
    of_flow_add_instructions_bind(obj, &list);
    OF_LIST_INSTRUCTION_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_flow_delete_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_flow_delete_t *obj)
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

    of_flow_delete_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_delete_cookie_get(obj, &val64);
    out += writer(cookie, "cookie=");
    out += LOCI_SHOW_u64_cookie(writer, cookie, val64);
    out += writer(cookie, " ");

    of_flow_delete_cookie_mask_get(obj, &val64);
    out += writer(cookie, "cookie_mask=");
    out += LOCI_SHOW_u64_cookie_mask(writer, cookie, val64);
    out += writer(cookie, " ");

    of_flow_delete_table_id_get(obj, &val8);
    out += writer(cookie, "table_id=");
    out += LOCI_SHOW_u8_table_id(writer, cookie, val8);
    out += writer(cookie, " ");

    of_flow_delete_idle_timeout_get(obj, &val16);
    out += writer(cookie, "idle_timeout=");
    out += LOCI_SHOW_u16_idle_timeout(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_delete_hard_timeout_get(obj, &val16);
    out += writer(cookie, "hard_timeout=");
    out += LOCI_SHOW_u16_hard_timeout(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_delete_priority_get(obj, &val16);
    out += writer(cookie, "priority=");
    out += LOCI_SHOW_u16_priority(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_delete_buffer_id_get(obj, &val32);
    out += writer(cookie, "buffer_id=");
    out += LOCI_SHOW_u32_buffer_id(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_delete_out_port_get(obj, &port_no);
    out += writer(cookie, "out_port=");
    out += LOCI_SHOW_port_no_out_port(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_flow_delete_out_group_get(obj, &val32);
    out += writer(cookie, "out_group=");
    out += LOCI_SHOW_u32_out_group(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_delete_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_delete_match_get(obj, &match);
    out += writer(cookie, "match=");
    out += LOCI_SHOW_match_match(writer, cookie, match);
    out += writer(cookie, " ");

    out += writer(cookie, "of_instruction_t={ ");
    of_flow_delete_instructions_bind(obj, &list);
    OF_LIST_INSTRUCTION_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_flow_delete_strict_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_flow_delete_strict_t *obj)
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

    of_flow_delete_strict_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_delete_strict_cookie_get(obj, &val64);
    out += writer(cookie, "cookie=");
    out += LOCI_SHOW_u64_cookie(writer, cookie, val64);
    out += writer(cookie, " ");

    of_flow_delete_strict_cookie_mask_get(obj, &val64);
    out += writer(cookie, "cookie_mask=");
    out += LOCI_SHOW_u64_cookie_mask(writer, cookie, val64);
    out += writer(cookie, " ");

    of_flow_delete_strict_table_id_get(obj, &val8);
    out += writer(cookie, "table_id=");
    out += LOCI_SHOW_u8_table_id(writer, cookie, val8);
    out += writer(cookie, " ");

    of_flow_delete_strict_idle_timeout_get(obj, &val16);
    out += writer(cookie, "idle_timeout=");
    out += LOCI_SHOW_u16_idle_timeout(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_delete_strict_hard_timeout_get(obj, &val16);
    out += writer(cookie, "hard_timeout=");
    out += LOCI_SHOW_u16_hard_timeout(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_delete_strict_priority_get(obj, &val16);
    out += writer(cookie, "priority=");
    out += LOCI_SHOW_u16_priority(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_delete_strict_buffer_id_get(obj, &val32);
    out += writer(cookie, "buffer_id=");
    out += LOCI_SHOW_u32_buffer_id(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_delete_strict_out_port_get(obj, &port_no);
    out += writer(cookie, "out_port=");
    out += LOCI_SHOW_port_no_out_port(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_flow_delete_strict_out_group_get(obj, &val32);
    out += writer(cookie, "out_group=");
    out += LOCI_SHOW_u32_out_group(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_delete_strict_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_delete_strict_match_get(obj, &match);
    out += writer(cookie, "match=");
    out += LOCI_SHOW_match_match(writer, cookie, match);
    out += writer(cookie, " ");

    out += writer(cookie, "of_instruction_t={ ");
    of_flow_delete_strict_instructions_bind(obj, &list);
    OF_LIST_INSTRUCTION_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_flow_mod_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_flow_mod_t *obj)
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

    of_flow_mod_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_mod_cookie_get(obj, &val64);
    out += writer(cookie, "cookie=");
    out += LOCI_SHOW_u64_cookie(writer, cookie, val64);
    out += writer(cookie, " ");

    of_flow_mod_cookie_mask_get(obj, &val64);
    out += writer(cookie, "cookie_mask=");
    out += LOCI_SHOW_u64_cookie_mask(writer, cookie, val64);
    out += writer(cookie, " ");

    of_flow_mod_table_id_get(obj, &val8);
    out += writer(cookie, "table_id=");
    out += LOCI_SHOW_u8_table_id(writer, cookie, val8);
    out += writer(cookie, " ");

    of_flow_mod_idle_timeout_get(obj, &val16);
    out += writer(cookie, "idle_timeout=");
    out += LOCI_SHOW_u16_idle_timeout(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_mod_hard_timeout_get(obj, &val16);
    out += writer(cookie, "hard_timeout=");
    out += LOCI_SHOW_u16_hard_timeout(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_mod_priority_get(obj, &val16);
    out += writer(cookie, "priority=");
    out += LOCI_SHOW_u16_priority(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_mod_buffer_id_get(obj, &val32);
    out += writer(cookie, "buffer_id=");
    out += LOCI_SHOW_u32_buffer_id(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_mod_out_port_get(obj, &port_no);
    out += writer(cookie, "out_port=");
    out += LOCI_SHOW_port_no_out_port(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_flow_mod_out_group_get(obj, &val32);
    out += writer(cookie, "out_group=");
    out += LOCI_SHOW_u32_out_group(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_mod_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_mod_match_get(obj, &match);
    out += writer(cookie, "match=");
    out += LOCI_SHOW_match_match(writer, cookie, match);
    out += writer(cookie, " ");

    out += writer(cookie, "of_instruction_t={ ");
    of_flow_mod_instructions_bind(obj, &list);
    OF_LIST_INSTRUCTION_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_flow_mod_failed_error_msg_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_flow_mod_failed_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    of_flow_mod_failed_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_mod_failed_error_msg_code_get(obj, &val16);
    out += writer(cookie, "code=");
    out += LOCI_SHOW_u16_code(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_mod_failed_error_msg_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_flow_modify_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_flow_modify_t *obj)
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

    of_flow_modify_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_modify_cookie_get(obj, &val64);
    out += writer(cookie, "cookie=");
    out += LOCI_SHOW_u64_cookie(writer, cookie, val64);
    out += writer(cookie, " ");

    of_flow_modify_cookie_mask_get(obj, &val64);
    out += writer(cookie, "cookie_mask=");
    out += LOCI_SHOW_u64_cookie_mask(writer, cookie, val64);
    out += writer(cookie, " ");

    of_flow_modify_table_id_get(obj, &val8);
    out += writer(cookie, "table_id=");
    out += LOCI_SHOW_u8_table_id(writer, cookie, val8);
    out += writer(cookie, " ");

    of_flow_modify_idle_timeout_get(obj, &val16);
    out += writer(cookie, "idle_timeout=");
    out += LOCI_SHOW_u16_idle_timeout(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_modify_hard_timeout_get(obj, &val16);
    out += writer(cookie, "hard_timeout=");
    out += LOCI_SHOW_u16_hard_timeout(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_modify_priority_get(obj, &val16);
    out += writer(cookie, "priority=");
    out += LOCI_SHOW_u16_priority(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_modify_buffer_id_get(obj, &val32);
    out += writer(cookie, "buffer_id=");
    out += LOCI_SHOW_u32_buffer_id(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_modify_out_port_get(obj, &port_no);
    out += writer(cookie, "out_port=");
    out += LOCI_SHOW_port_no_out_port(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_flow_modify_out_group_get(obj, &val32);
    out += writer(cookie, "out_group=");
    out += LOCI_SHOW_u32_out_group(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_modify_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_modify_match_get(obj, &match);
    out += writer(cookie, "match=");
    out += LOCI_SHOW_match_match(writer, cookie, match);
    out += writer(cookie, " ");

    out += writer(cookie, "of_instruction_t={ ");
    of_flow_modify_instructions_bind(obj, &list);
    OF_LIST_INSTRUCTION_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_flow_modify_strict_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_flow_modify_strict_t *obj)
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

    of_flow_modify_strict_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_modify_strict_cookie_get(obj, &val64);
    out += writer(cookie, "cookie=");
    out += LOCI_SHOW_u64_cookie(writer, cookie, val64);
    out += writer(cookie, " ");

    of_flow_modify_strict_cookie_mask_get(obj, &val64);
    out += writer(cookie, "cookie_mask=");
    out += LOCI_SHOW_u64_cookie_mask(writer, cookie, val64);
    out += writer(cookie, " ");

    of_flow_modify_strict_table_id_get(obj, &val8);
    out += writer(cookie, "table_id=");
    out += LOCI_SHOW_u8_table_id(writer, cookie, val8);
    out += writer(cookie, " ");

    of_flow_modify_strict_idle_timeout_get(obj, &val16);
    out += writer(cookie, "idle_timeout=");
    out += LOCI_SHOW_u16_idle_timeout(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_modify_strict_hard_timeout_get(obj, &val16);
    out += writer(cookie, "hard_timeout=");
    out += LOCI_SHOW_u16_hard_timeout(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_modify_strict_priority_get(obj, &val16);
    out += writer(cookie, "priority=");
    out += LOCI_SHOW_u16_priority(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_modify_strict_buffer_id_get(obj, &val32);
    out += writer(cookie, "buffer_id=");
    out += LOCI_SHOW_u32_buffer_id(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_modify_strict_out_port_get(obj, &port_no);
    out += writer(cookie, "out_port=");
    out += LOCI_SHOW_port_no_out_port(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_flow_modify_strict_out_group_get(obj, &val32);
    out += writer(cookie, "out_group=");
    out += LOCI_SHOW_u32_out_group(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_modify_strict_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_modify_strict_match_get(obj, &match);
    out += writer(cookie, "match=");
    out += LOCI_SHOW_match_match(writer, cookie, match);
    out += writer(cookie, " ");

    out += writer(cookie, "of_instruction_t={ ");
    of_flow_modify_strict_instructions_bind(obj, &list);
    OF_LIST_INSTRUCTION_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_flow_removed_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_flow_removed_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint64_t val64;
    uint16_t val16;
    uint8_t val8;
    of_match_t match;

    of_flow_removed_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_removed_cookie_get(obj, &val64);
    out += writer(cookie, "cookie=");
    out += LOCI_SHOW_u64_cookie(writer, cookie, val64);
    out += writer(cookie, " ");

    of_flow_removed_priority_get(obj, &val16);
    out += writer(cookie, "priority=");
    out += LOCI_SHOW_u16_priority(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_removed_reason_get(obj, &val8);
    out += writer(cookie, "reason=");
    out += LOCI_SHOW_u8_reason(writer, cookie, val8);
    out += writer(cookie, " ");

    of_flow_removed_table_id_get(obj, &val8);
    out += writer(cookie, "table_id=");
    out += LOCI_SHOW_u8_table_id(writer, cookie, val8);
    out += writer(cookie, " ");

    of_flow_removed_duration_sec_get(obj, &val32);
    out += writer(cookie, "duration_sec=");
    out += LOCI_SHOW_u32_duration_sec(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_removed_duration_nsec_get(obj, &val32);
    out += writer(cookie, "duration_nsec=");
    out += LOCI_SHOW_u32_duration_nsec(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_removed_idle_timeout_get(obj, &val16);
    out += writer(cookie, "idle_timeout=");
    out += LOCI_SHOW_u16_idle_timeout(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_removed_hard_timeout_get(obj, &val16);
    out += writer(cookie, "hard_timeout=");
    out += LOCI_SHOW_u16_hard_timeout(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_removed_packet_count_get(obj, &val64);
    out += writer(cookie, "packet_count=");
    out += LOCI_SHOW_u64_packet_count(writer, cookie, val64);
    out += writer(cookie, " ");

    of_flow_removed_byte_count_get(obj, &val64);
    out += writer(cookie, "byte_count=");
    out += LOCI_SHOW_u64_byte_count(writer, cookie, val64);
    out += writer(cookie, " ");

    of_flow_removed_match_get(obj, &match);
    out += writer(cookie, "match=");
    out += LOCI_SHOW_match_match(writer, cookie, match);
    out += writer(cookie, " ");

    return out;
}

int
of_flow_stats_reply_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_flow_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_list_flow_stats_entry_t list;
    of_flow_stats_entry_t elt;
    int rv;

    of_flow_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    out += writer(cookie, "of_flow_stats_entry_t={ ");
    of_flow_stats_reply_entries_bind(obj, &list);
    OF_LIST_FLOW_STATS_ENTRY_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_flow_stats_request_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_flow_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    uint8_t val8;
    of_port_no_t port_no;
    uint64_t val64;
    of_match_t match;

    of_flow_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_stats_request_table_id_get(obj, &val8);
    out += writer(cookie, "table_id=");
    out += LOCI_SHOW_u8_table_id(writer, cookie, val8);
    out += writer(cookie, " ");

    of_flow_stats_request_out_port_get(obj, &port_no);
    out += writer(cookie, "out_port=");
    out += LOCI_SHOW_port_no_out_port(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_flow_stats_request_out_group_get(obj, &val32);
    out += writer(cookie, "out_group=");
    out += LOCI_SHOW_u32_out_group(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_stats_request_cookie_get(obj, &val64);
    out += writer(cookie, "cookie=");
    out += LOCI_SHOW_u64_cookie(writer, cookie, val64);
    out += writer(cookie, " ");

    of_flow_stats_request_cookie_mask_get(obj, &val64);
    out += writer(cookie, "cookie_mask=");
    out += LOCI_SHOW_u64_cookie_mask(writer, cookie, val64);
    out += writer(cookie, " ");

    of_flow_stats_request_match_get(obj, &match);
    out += writer(cookie, "match=");
    out += LOCI_SHOW_match_match(writer, cookie, match);
    out += writer(cookie, " ");

    return out;
}

int
of_get_config_reply_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_get_config_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_get_config_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_get_config_reply_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    of_get_config_reply_miss_send_len_get(obj, &val16);
    out += writer(cookie, "miss_send_len=");
    out += LOCI_SHOW_u16_miss_send_len(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_get_config_request_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_get_config_request_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_get_config_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_group_desc_stats_reply_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_group_desc_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_list_group_desc_stats_entry_t list;
    of_group_desc_stats_entry_t elt;
    int rv;

    of_group_desc_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_group_desc_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    out += writer(cookie, "of_group_desc_stats_entry_t={ ");
    of_group_desc_stats_reply_entries_bind(obj, &list);
    OF_LIST_GROUP_DESC_STATS_ENTRY_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_group_desc_stats_request_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_group_desc_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_group_desc_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_group_desc_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_group_features_stats_reply_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_group_features_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_group_features_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_group_features_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    of_group_features_stats_reply_types_get(obj, &val32);
    out += writer(cookie, "types=");
    out += LOCI_SHOW_u32_types(writer, cookie, val32);
    out += writer(cookie, " ");

    of_group_features_stats_reply_capabilities_get(obj, &val32);
    out += writer(cookie, "capabilities=");
    out += LOCI_SHOW_u32_capabilities(writer, cookie, val32);
    out += writer(cookie, " ");

    of_group_features_stats_reply_max_groups_all_get(obj, &val32);
    out += writer(cookie, "max_groups_all=");
    out += LOCI_SHOW_u32_max_groups_all(writer, cookie, val32);
    out += writer(cookie, " ");

    of_group_features_stats_reply_max_groups_select_get(obj, &val32);
    out += writer(cookie, "max_groups_select=");
    out += LOCI_SHOW_u32_max_groups_select(writer, cookie, val32);
    out += writer(cookie, " ");

    of_group_features_stats_reply_max_groups_indirect_get(obj, &val32);
    out += writer(cookie, "max_groups_indirect=");
    out += LOCI_SHOW_u32_max_groups_indirect(writer, cookie, val32);
    out += writer(cookie, " ");

    of_group_features_stats_reply_max_groups_ff_get(obj, &val32);
    out += writer(cookie, "max_groups_ff=");
    out += LOCI_SHOW_u32_max_groups_ff(writer, cookie, val32);
    out += writer(cookie, " ");

    of_group_features_stats_reply_actions_all_get(obj, &val32);
    out += writer(cookie, "actions_all=");
    out += LOCI_SHOW_u32_actions_all(writer, cookie, val32);
    out += writer(cookie, " ");

    of_group_features_stats_reply_actions_select_get(obj, &val32);
    out += writer(cookie, "actions_select=");
    out += LOCI_SHOW_u32_actions_select(writer, cookie, val32);
    out += writer(cookie, " ");

    of_group_features_stats_reply_actions_indirect_get(obj, &val32);
    out += writer(cookie, "actions_indirect=");
    out += LOCI_SHOW_u32_actions_indirect(writer, cookie, val32);
    out += writer(cookie, " ");

    of_group_features_stats_reply_actions_ff_get(obj, &val32);
    out += writer(cookie, "actions_ff=");
    out += LOCI_SHOW_u32_actions_ff(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_group_features_stats_request_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_group_features_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_group_features_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_group_features_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_group_mod_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_group_mod_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    uint8_t val8;

    of_list_bucket_t list;
    of_bucket_t elt;
    int rv;

    of_group_mod_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_group_mod_command_get(obj, &val16);
    out += writer(cookie, "command=");
    out += LOCI_SHOW_u16_command(writer, cookie, val16);
    out += writer(cookie, " ");

    of_group_mod_group_type_get(obj, &val8);
    out += writer(cookie, "group_type=");
    out += LOCI_SHOW_u8_group_type(writer, cookie, val8);
    out += writer(cookie, " ");

    of_group_mod_group_id_get(obj, &val32);
    out += writer(cookie, "group_id=");
    out += LOCI_SHOW_u32_group_id(writer, cookie, val32);
    out += writer(cookie, " ");

    out += writer(cookie, "of_bucket_t={ ");
    of_group_mod_buckets_bind(obj, &list);
    OF_LIST_BUCKET_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_group_mod_failed_error_msg_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_group_mod_failed_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    of_group_mod_failed_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_group_mod_failed_error_msg_code_get(obj, &val16);
    out += writer(cookie, "code=");
    out += LOCI_SHOW_u16_code(writer, cookie, val16);
    out += writer(cookie, " ");

    of_group_mod_failed_error_msg_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_group_stats_reply_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_group_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_list_group_stats_entry_t list;
    of_group_stats_entry_t elt;
    int rv;

    of_group_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_group_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    out += writer(cookie, "of_group_stats_entry_t={ ");
    of_group_stats_reply_entries_bind(obj, &list);
    OF_LIST_GROUP_STATS_ENTRY_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_group_stats_request_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_group_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_group_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_group_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    of_group_stats_request_group_id_get(obj, &val32);
    out += writer(cookie, "group_id=");
    out += LOCI_SHOW_u32_group_id(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_hello_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_hello_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_list_hello_elem_t list;
    of_hello_elem_t elt;
    int rv;

    of_hello_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    out += writer(cookie, "of_hello_elem_t={ ");
    of_hello_elements_bind(obj, &list);
    OF_LIST_HELLO_ELEM_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_hello_failed_error_msg_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_hello_failed_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    of_hello_failed_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_hello_failed_error_msg_code_get(obj, &val16);
    out += writer(cookie, "code=");
    out += LOCI_SHOW_u16_code(writer, cookie, val16);
    out += writer(cookie, " ");

    of_hello_failed_error_msg_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_meter_config_stats_reply_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_meter_config_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_list_meter_band_t list;
    of_meter_band_t elt;
    int rv;

    of_meter_config_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_meter_config_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    out += writer(cookie, "of_meter_band_t={ ");
    of_meter_config_stats_reply_entries_bind(obj, &list);
    OF_LIST_METER_BAND_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_meter_config_stats_request_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_meter_config_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_meter_config_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_meter_config_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    of_meter_config_stats_request_meter_id_get(obj, &val32);
    out += writer(cookie, "meter_id=");
    out += LOCI_SHOW_u32_meter_id(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_meter_features_stats_reply_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_meter_features_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_meter_features_t features;

    of_meter_features_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_meter_features_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    of_meter_features_stats_reply_features_bind(obj, &features);
    out += of_meter_features_OF_VERSION_1_3_show(writer, cookie, &features);

    return out;
}

int
of_meter_features_stats_request_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_meter_features_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_meter_features_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_meter_features_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_meter_mod_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_meter_mod_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_list_meter_band_t list;
    of_meter_band_t elt;
    int rv;

    of_meter_mod_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_meter_mod_command_get(obj, &val16);
    out += writer(cookie, "command=");
    out += LOCI_SHOW_u16_command(writer, cookie, val16);
    out += writer(cookie, " ");

    of_meter_mod_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    of_meter_mod_meter_id_get(obj, &val32);
    out += writer(cookie, "meter_id=");
    out += LOCI_SHOW_u32_meter_id(writer, cookie, val32);
    out += writer(cookie, " ");

    out += writer(cookie, "of_meter_band_t={ ");
    of_meter_mod_meters_bind(obj, &list);
    OF_LIST_METER_BAND_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_meter_mod_failed_error_msg_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_meter_mod_failed_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    of_meter_mod_failed_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_meter_mod_failed_error_msg_code_get(obj, &val16);
    out += writer(cookie, "code=");
    out += LOCI_SHOW_u16_code(writer, cookie, val16);
    out += writer(cookie, " ");

    of_meter_mod_failed_error_msg_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_meter_stats_reply_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_meter_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_list_meter_stats_t list;
    of_meter_stats_t elt;
    int rv;

    of_meter_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_meter_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    out += writer(cookie, "of_meter_stats_t={ ");
    of_meter_stats_reply_entries_bind(obj, &list);
    OF_LIST_METER_STATS_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_meter_stats_request_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_meter_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_meter_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_meter_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    of_meter_stats_request_meter_id_get(obj, &val32);
    out += writer(cookie, "meter_id=");
    out += LOCI_SHOW_u32_meter_id(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_nicira_header_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_nicira_header_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_nicira_header_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_nicira_header_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_nicira_header_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_packet_in_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_packet_in_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    uint8_t val8;
    uint64_t val64;
    of_match_t match;
    of_octets_t octets;

    of_packet_in_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_packet_in_buffer_id_get(obj, &val32);
    out += writer(cookie, "buffer_id=");
    out += LOCI_SHOW_u32_buffer_id(writer, cookie, val32);
    out += writer(cookie, " ");

    of_packet_in_total_len_get(obj, &val16);
    out += writer(cookie, "total_len=");
    out += LOCI_SHOW_u16_total_len(writer, cookie, val16);
    out += writer(cookie, " ");

    of_packet_in_reason_get(obj, &val8);
    out += writer(cookie, "reason=");
    out += LOCI_SHOW_u8_reason(writer, cookie, val8);
    out += writer(cookie, " ");

    of_packet_in_table_id_get(obj, &val8);
    out += writer(cookie, "table_id=");
    out += LOCI_SHOW_u8_table_id(writer, cookie, val8);
    out += writer(cookie, " ");

    of_packet_in_cookie_get(obj, &val64);
    out += writer(cookie, "cookie=");
    out += LOCI_SHOW_u64_cookie(writer, cookie, val64);
    out += writer(cookie, " ");

    of_packet_in_match_get(obj, &match);
    out += writer(cookie, "match=");
    out += LOCI_SHOW_match_match(writer, cookie, match);
    out += writer(cookie, " ");

    of_packet_in_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_packet_out_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_packet_out_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_port_no_t port_no;

    of_list_action_t list;
    of_action_t elt;
    int rv;
    of_octets_t octets;

    of_packet_out_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_packet_out_buffer_id_get(obj, &val32);
    out += writer(cookie, "buffer_id=");
    out += LOCI_SHOW_u32_buffer_id(writer, cookie, val32);
    out += writer(cookie, " ");

    of_packet_out_in_port_get(obj, &port_no);
    out += writer(cookie, "in_port=");
    out += LOCI_SHOW_port_no_in_port(writer, cookie, port_no);
    out += writer(cookie, " ");

    out += writer(cookie, "of_action_t={ ");
    of_packet_out_actions_bind(obj, &list);
    OF_LIST_ACTION_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    of_packet_out_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_port_desc_stats_reply_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_port_desc_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_list_port_desc_t list;
    of_port_desc_t elt;
    int rv;

    of_port_desc_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_port_desc_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    out += writer(cookie, "of_port_desc_t={ ");
    of_port_desc_stats_reply_entries_bind(obj, &list);
    OF_LIST_PORT_DESC_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_port_desc_stats_request_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_port_desc_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_port_desc_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_port_desc_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_port_mod_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_port_mod_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_port_no_t port_no;
    of_mac_addr_t mac_addr;

    of_port_mod_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_port_mod_port_no_get(obj, &port_no);
    out += writer(cookie, "port_no=");
    out += LOCI_SHOW_port_no_port_no(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_port_mod_hw_addr_get(obj, &mac_addr);
    out += writer(cookie, "hw_addr=");
    out += LOCI_SHOW_mac_hw_addr(writer, cookie, mac_addr);
    out += writer(cookie, " ");

    of_port_mod_config_get(obj, &val32);
    out += writer(cookie, "config=");
    out += LOCI_SHOW_u32_config(writer, cookie, val32);
    out += writer(cookie, " ");

    of_port_mod_mask_get(obj, &val32);
    out += writer(cookie, "mask=");
    out += LOCI_SHOW_u32_mask(writer, cookie, val32);
    out += writer(cookie, " ");

    of_port_mod_advertise_get(obj, &val32);
    out += writer(cookie, "advertise=");
    out += LOCI_SHOW_u32_advertise(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_port_mod_failed_error_msg_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_port_mod_failed_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    of_port_mod_failed_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_port_mod_failed_error_msg_code_get(obj, &val16);
    out += writer(cookie, "code=");
    out += LOCI_SHOW_u16_code(writer, cookie, val16);
    out += writer(cookie, " ");

    of_port_mod_failed_error_msg_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_port_stats_reply_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_port_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_list_port_stats_entry_t list;
    of_port_stats_entry_t elt;
    int rv;

    of_port_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_port_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    out += writer(cookie, "of_port_stats_entry_t={ ");
    of_port_stats_reply_entries_bind(obj, &list);
    OF_LIST_PORT_STATS_ENTRY_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_port_stats_request_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_port_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_port_no_t port_no;

    of_port_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_port_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    of_port_stats_request_port_no_get(obj, &port_no);
    out += writer(cookie, "port_no=");
    out += LOCI_SHOW_port_no_port_no(writer, cookie, port_no);
    out += writer(cookie, " ");

    return out;
}

int
of_port_status_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_port_status_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint8_t val8;

    of_port_desc_t port_desc;

    of_port_status_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_port_status_reason_get(obj, &val8);
    out += writer(cookie, "reason=");
    out += LOCI_SHOW_u8_reason(writer, cookie, val8);
    out += writer(cookie, " ");

    of_port_status_desc_bind(obj, &port_desc);
    out += of_port_desc_OF_VERSION_1_3_show(writer, cookie, &port_desc);

    return out;
}

int
of_queue_get_config_reply_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_queue_get_config_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_port_no_t port_no;

    of_list_packet_queue_t list;
    of_packet_queue_t elt;
    int rv;

    of_queue_get_config_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_queue_get_config_reply_port_get(obj, &port_no);
    out += writer(cookie, "port=");
    out += LOCI_SHOW_port_no_port(writer, cookie, port_no);
    out += writer(cookie, " ");

    out += writer(cookie, "of_packet_queue_t={ ");
    of_queue_get_config_reply_queues_bind(obj, &list);
    OF_LIST_PACKET_QUEUE_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_queue_get_config_request_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_queue_get_config_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_port_no_t port_no;

    of_queue_get_config_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_queue_get_config_request_port_get(obj, &port_no);
    out += writer(cookie, "port=");
    out += LOCI_SHOW_port_no_port(writer, cookie, port_no);
    out += writer(cookie, " ");

    return out;
}

int
of_queue_op_failed_error_msg_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_queue_op_failed_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    of_queue_op_failed_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_queue_op_failed_error_msg_code_get(obj, &val16);
    out += writer(cookie, "code=");
    out += LOCI_SHOW_u16_code(writer, cookie, val16);
    out += writer(cookie, " ");

    of_queue_op_failed_error_msg_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_queue_stats_reply_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_queue_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_list_queue_stats_entry_t list;
    of_queue_stats_entry_t elt;
    int rv;

    of_queue_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_queue_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    out += writer(cookie, "of_queue_stats_entry_t={ ");
    of_queue_stats_reply_entries_bind(obj, &list);
    OF_LIST_QUEUE_STATS_ENTRY_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_queue_stats_request_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_queue_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_port_no_t port_no;

    of_queue_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_queue_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    of_queue_stats_request_port_no_get(obj, &port_no);
    out += writer(cookie, "port_no=");
    out += LOCI_SHOW_port_no_port_no(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_queue_stats_request_queue_id_get(obj, &val32);
    out += writer(cookie, "queue_id=");
    out += LOCI_SHOW_u32_queue_id(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_role_reply_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_role_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint64_t val64;

    of_role_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_role_reply_role_get(obj, &val32);
    out += writer(cookie, "role=");
    out += LOCI_SHOW_u32_role(writer, cookie, val32);
    out += writer(cookie, " ");

    of_role_reply_generation_id_get(obj, &val64);
    out += writer(cookie, "generation_id=");
    out += LOCI_SHOW_u64_generation_id(writer, cookie, val64);
    out += writer(cookie, " ");

    return out;
}

int
of_role_request_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_role_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint64_t val64;

    of_role_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_role_request_role_get(obj, &val32);
    out += writer(cookie, "role=");
    out += LOCI_SHOW_u32_role(writer, cookie, val32);
    out += writer(cookie, " ");

    of_role_request_generation_id_get(obj, &val64);
    out += writer(cookie, "generation_id=");
    out += LOCI_SHOW_u64_generation_id(writer, cookie, val64);
    out += writer(cookie, " ");

    return out;
}

int
of_role_request_failed_error_msg_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_role_request_failed_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    of_role_request_failed_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_role_request_failed_error_msg_code_get(obj, &val16);
    out += writer(cookie, "code=");
    out += LOCI_SHOW_u16_code(writer, cookie, val16);
    out += writer(cookie, " ");

    of_role_request_failed_error_msg_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_set_config_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_set_config_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_set_config_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_set_config_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    of_set_config_miss_send_len_get(obj, &val16);
    out += writer(cookie, "miss_send_len=");
    out += LOCI_SHOW_u16_miss_send_len(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_stats_reply_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_stats_request_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_switch_config_failed_error_msg_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_switch_config_failed_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    of_switch_config_failed_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_switch_config_failed_error_msg_code_get(obj, &val16);
    out += writer(cookie, "code=");
    out += LOCI_SHOW_u16_code(writer, cookie, val16);
    out += writer(cookie, " ");

    of_switch_config_failed_error_msg_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_table_features_failed_error_msg_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_table_features_failed_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    of_table_features_failed_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_table_features_failed_error_msg_code_get(obj, &val16);
    out += writer(cookie, "code=");
    out += LOCI_SHOW_u16_code(writer, cookie, val16);
    out += writer(cookie, " ");

    of_table_features_failed_error_msg_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_table_features_stats_reply_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_table_features_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_list_table_features_t list;
    of_table_features_t elt;
    int rv;

    of_table_features_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_table_features_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    out += writer(cookie, "of_table_features_t={ ");
    of_table_features_stats_reply_entries_bind(obj, &list);
    OF_LIST_TABLE_FEATURES_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_table_features_stats_request_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_table_features_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_list_table_features_t list;
    of_table_features_t elt;
    int rv;

    of_table_features_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_table_features_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    out += writer(cookie, "of_table_features_t={ ");
    of_table_features_stats_request_entries_bind(obj, &list);
    OF_LIST_TABLE_FEATURES_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_table_mod_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_table_mod_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint8_t val8;

    of_table_mod_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_table_mod_table_id_get(obj, &val8);
    out += writer(cookie, "table_id=");
    out += LOCI_SHOW_u8_table_id(writer, cookie, val8);
    out += writer(cookie, " ");

    of_table_mod_config_get(obj, &val32);
    out += writer(cookie, "config=");
    out += LOCI_SHOW_u32_config(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_table_mod_failed_error_msg_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_table_mod_failed_error_msg_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_octets_t octets;

    of_table_mod_failed_error_msg_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_table_mod_failed_error_msg_code_get(obj, &val16);
    out += writer(cookie, "code=");
    out += LOCI_SHOW_u16_code(writer, cookie, val16);
    out += writer(cookie, " ");

    of_table_mod_failed_error_msg_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_table_stats_reply_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_table_stats_reply_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_list_table_stats_entry_t list;
    of_table_stats_entry_t elt;
    int rv;

    of_table_stats_reply_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_table_stats_reply_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    out += writer(cookie, "of_table_stats_entry_t={ ");
    of_table_stats_reply_entries_bind(obj, &list);
    OF_LIST_TABLE_STATS_ENTRY_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_table_stats_request_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_table_stats_request_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_table_stats_request_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    of_table_stats_request_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_action_bsn_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_action_bsn_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_action_bsn_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_action_bsn_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_action_bsn_mirror_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_action_bsn_mirror_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint8_t val8;

    of_action_bsn_mirror_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_action_bsn_mirror_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_action_bsn_mirror_dest_port_get(obj, &val32);
    out += writer(cookie, "dest_port=");
    out += LOCI_SHOW_u32_dest_port(writer, cookie, val32);
    out += writer(cookie, " ");

    of_action_bsn_mirror_vlan_tag_get(obj, &val32);
    out += writer(cookie, "vlan_tag=");
    out += LOCI_SHOW_u32_vlan_tag(writer, cookie, val32);
    out += writer(cookie, " ");

    of_action_bsn_mirror_copy_stage_get(obj, &val8);
    out += writer(cookie, "copy_stage=");
    out += LOCI_SHOW_u8_copy_stage(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_action_bsn_set_tunnel_dst_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_action_bsn_set_tunnel_dst_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_action_bsn_set_tunnel_dst_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_action_bsn_set_tunnel_dst_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_action_bsn_set_tunnel_dst_dst_get(obj, &val32);
    out += writer(cookie, "dst=");
    out += LOCI_SHOW_u32_dst(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_action_copy_ttl_in_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_action_copy_ttl_in_t *obj)
{
    int out = 0;

    return out;
}

int
of_action_copy_ttl_out_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_action_copy_ttl_out_t *obj)
{
    int out = 0;

    return out;
}

int
of_action_dec_mpls_ttl_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_action_dec_mpls_ttl_t *obj)
{
    int out = 0;

    return out;
}

int
of_action_dec_nw_ttl_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_action_dec_nw_ttl_t *obj)
{
    int out = 0;

    return out;
}

int
of_action_experimenter_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_action_experimenter_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_octets_t octets;

    of_action_experimenter_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_action_experimenter_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_action_group_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_action_group_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_action_group_group_id_get(obj, &val32);
    out += writer(cookie, "group_id=");
    out += LOCI_SHOW_u32_group_id(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_action_header_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_action_header_t *obj)
{
    int out = 0;

    return out;
}

int
of_action_id_bsn_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_action_id_bsn_t *obj)
{
    int out = 0;

    return out;
}

int
of_action_id_bsn_mirror_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_action_id_bsn_mirror_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_action_id_bsn_mirror_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_action_id_bsn_mirror_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_action_id_bsn_set_tunnel_dst_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_action_id_bsn_set_tunnel_dst_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_action_id_bsn_set_tunnel_dst_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_action_id_bsn_set_tunnel_dst_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_action_id_copy_ttl_in_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_action_id_copy_ttl_in_t *obj)
{
    int out = 0;

    return out;
}

int
of_action_id_copy_ttl_out_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_action_id_copy_ttl_out_t *obj)
{
    int out = 0;

    return out;
}

int
of_action_id_dec_mpls_ttl_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_action_id_dec_mpls_ttl_t *obj)
{
    int out = 0;

    return out;
}

int
of_action_id_dec_nw_ttl_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_action_id_dec_nw_ttl_t *obj)
{
    int out = 0;

    return out;
}

int
of_action_id_experimenter_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_action_id_experimenter_t *obj)
{
    int out = 0;

    return out;
}

int
of_action_id_group_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_action_id_group_t *obj)
{
    int out = 0;

    return out;
}

int
of_action_id_header_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_action_id_header_t *obj)
{
    int out = 0;

    return out;
}

int
of_action_id_nicira_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_action_id_nicira_t *obj)
{
    int out = 0;

    return out;
}

int
of_action_id_nicira_dec_ttl_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_action_id_nicira_dec_ttl_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_action_id_nicira_dec_ttl_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_action_id_nicira_dec_ttl_subtype_get(obj, &val16);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u16_subtype(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_action_id_output_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_action_id_output_t *obj)
{
    int out = 0;

    return out;
}

int
of_action_id_pop_mpls_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_action_id_pop_mpls_t *obj)
{
    int out = 0;

    return out;
}

int
of_action_id_pop_pbb_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_action_id_pop_pbb_t *obj)
{
    int out = 0;

    return out;
}

int
of_action_id_pop_vlan_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_action_id_pop_vlan_t *obj)
{
    int out = 0;

    return out;
}

int
of_action_id_push_mpls_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_action_id_push_mpls_t *obj)
{
    int out = 0;

    return out;
}

int
of_action_id_push_pbb_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_action_id_push_pbb_t *obj)
{
    int out = 0;

    return out;
}

int
of_action_id_push_vlan_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_action_id_push_vlan_t *obj)
{
    int out = 0;

    return out;
}

int
of_action_id_set_field_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_action_id_set_field_t *obj)
{
    int out = 0;

    return out;
}

int
of_action_id_set_mpls_ttl_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_action_id_set_mpls_ttl_t *obj)
{
    int out = 0;

    return out;
}

int
of_action_id_set_nw_ttl_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_action_id_set_nw_ttl_t *obj)
{
    int out = 0;

    return out;
}

int
of_action_id_set_queue_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_action_id_set_queue_t *obj)
{
    int out = 0;

    return out;
}

int
of_action_nicira_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_action_nicira_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_action_nicira_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_action_nicira_subtype_get(obj, &val16);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u16_subtype(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_action_nicira_dec_ttl_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_action_nicira_dec_ttl_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;

    of_action_nicira_dec_ttl_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_action_nicira_dec_ttl_subtype_get(obj, &val16);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u16_subtype(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_action_output_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_action_output_t *obj)
{
    int out = 0;
    of_port_no_t port_no;
    uint16_t val16;

    of_action_output_port_get(obj, &port_no);
    out += writer(cookie, "port=");
    out += LOCI_SHOW_port_no_port(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_action_output_max_len_get(obj, &val16);
    out += writer(cookie, "max_len=");
    out += LOCI_SHOW_u16_max_len(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_action_pop_mpls_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_action_pop_mpls_t *obj)
{
    int out = 0;
    uint16_t val16;

    of_action_pop_mpls_ethertype_get(obj, &val16);
    out += writer(cookie, "ethertype=");
    out += LOCI_SHOW_u16_ethertype(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_action_pop_pbb_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_action_pop_pbb_t *obj)
{
    int out = 0;

    return out;
}

int
of_action_pop_vlan_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_action_pop_vlan_t *obj)
{
    int out = 0;

    return out;
}

int
of_action_push_mpls_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_action_push_mpls_t *obj)
{
    int out = 0;
    uint16_t val16;

    of_action_push_mpls_ethertype_get(obj, &val16);
    out += writer(cookie, "ethertype=");
    out += LOCI_SHOW_u16_ethertype(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_action_push_pbb_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_action_push_pbb_t *obj)
{
    int out = 0;
    uint16_t val16;

    of_action_push_pbb_ethertype_get(obj, &val16);
    out += writer(cookie, "ethertype=");
    out += LOCI_SHOW_u16_ethertype(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_action_push_vlan_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_action_push_vlan_t *obj)
{
    int out = 0;
    uint16_t val16;

    of_action_push_vlan_ethertype_get(obj, &val16);
    out += writer(cookie, "ethertype=");
    out += LOCI_SHOW_u16_ethertype(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_action_set_field_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_action_set_field_t *obj)
{
    int out = 0;
    of_octets_t octets;

    of_action_set_field_field_get(obj, &octets);
    out += writer(cookie, "field=");
    out += LOCI_SHOW_octets_field(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_action_set_mpls_ttl_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_action_set_mpls_ttl_t *obj)
{
    int out = 0;
    uint8_t val8;

    of_action_set_mpls_ttl_mpls_ttl_get(obj, &val8);
    out += writer(cookie, "mpls_ttl=");
    out += LOCI_SHOW_u8_mpls_ttl(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_action_set_nw_ttl_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_action_set_nw_ttl_t *obj)
{
    int out = 0;
    uint8_t val8;

    of_action_set_nw_ttl_nw_ttl_get(obj, &val8);
    out += writer(cookie, "nw_ttl=");
    out += LOCI_SHOW_u8_nw_ttl(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_action_set_queue_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_action_set_queue_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_action_set_queue_queue_id_get(obj, &val32);
    out += writer(cookie, "queue_id=");
    out += LOCI_SHOW_u32_queue_id(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_interface_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_bsn_interface_t *obj)
{
    int out = 0;
    of_mac_addr_t mac_addr;
    of_port_name_t port_name;
    of_ipv4_t ipv4;

    of_bsn_interface_hw_addr_get(obj, &mac_addr);
    out += writer(cookie, "hw_addr=");
    out += LOCI_SHOW_mac_hw_addr(writer, cookie, mac_addr);
    out += writer(cookie, " ");

    of_bsn_interface_name_get(obj, &port_name);
    out += writer(cookie, "name=");
    out += LOCI_SHOW_port_name_name(writer, cookie, port_name);
    out += writer(cookie, " ");

    of_bsn_interface_ipv4_addr_get(obj, &ipv4);
    out += writer(cookie, "ipv4_addr=");
    out += LOCI_SHOW_ipv4_ipv4_addr(writer, cookie, ipv4);
    out += writer(cookie, " ");

    of_bsn_interface_ipv4_netmask_get(obj, &ipv4);
    out += writer(cookie, "ipv4_netmask=");
    out += LOCI_SHOW_ipv4_ipv4_netmask(writer, cookie, ipv4);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_lacp_stats_entry_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_bsn_lacp_stats_entry_t *obj)
{
    int out = 0;
    of_port_no_t port_no;
    uint16_t val16;
    of_mac_addr_t mac_addr;
    uint8_t val8;

    of_bsn_lacp_stats_entry_port_no_get(obj, &port_no);
    out += writer(cookie, "port_no=");
    out += LOCI_SHOW_port_no_port_no(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_bsn_lacp_stats_entry_actor_sys_priority_get(obj, &val16);
    out += writer(cookie, "actor_sys_priority=");
    out += LOCI_SHOW_u16_actor_sys_priority(writer, cookie, val16);
    out += writer(cookie, " ");

    of_bsn_lacp_stats_entry_actor_sys_mac_get(obj, &mac_addr);
    out += writer(cookie, "actor_sys_mac=");
    out += LOCI_SHOW_mac_actor_sys_mac(writer, cookie, mac_addr);
    out += writer(cookie, " ");

    of_bsn_lacp_stats_entry_actor_port_priority_get(obj, &val16);
    out += writer(cookie, "actor_port_priority=");
    out += LOCI_SHOW_u16_actor_port_priority(writer, cookie, val16);
    out += writer(cookie, " ");

    of_bsn_lacp_stats_entry_actor_port_num_get(obj, &val16);
    out += writer(cookie, "actor_port_num=");
    out += LOCI_SHOW_u16_actor_port_num(writer, cookie, val16);
    out += writer(cookie, " ");

    of_bsn_lacp_stats_entry_actor_key_get(obj, &val16);
    out += writer(cookie, "actor_key=");
    out += LOCI_SHOW_u16_actor_key(writer, cookie, val16);
    out += writer(cookie, " ");

    of_bsn_lacp_stats_entry_convergence_status_get(obj, &val8);
    out += writer(cookie, "convergence_status=");
    out += LOCI_SHOW_u8_convergence_status(writer, cookie, val8);
    out += writer(cookie, " ");

    of_bsn_lacp_stats_entry_partner_sys_priority_get(obj, &val16);
    out += writer(cookie, "partner_sys_priority=");
    out += LOCI_SHOW_u16_partner_sys_priority(writer, cookie, val16);
    out += writer(cookie, " ");

    of_bsn_lacp_stats_entry_partner_sys_mac_get(obj, &mac_addr);
    out += writer(cookie, "partner_sys_mac=");
    out += LOCI_SHOW_mac_partner_sys_mac(writer, cookie, mac_addr);
    out += writer(cookie, " ");

    of_bsn_lacp_stats_entry_partner_port_priority_get(obj, &val16);
    out += writer(cookie, "partner_port_priority=");
    out += LOCI_SHOW_u16_partner_port_priority(writer, cookie, val16);
    out += writer(cookie, " ");

    of_bsn_lacp_stats_entry_partner_port_num_get(obj, &val16);
    out += writer(cookie, "partner_port_num=");
    out += LOCI_SHOW_u16_partner_port_num(writer, cookie, val16);
    out += writer(cookie, " ");

    of_bsn_lacp_stats_entry_partner_key_get(obj, &val16);
    out += writer(cookie, "partner_key=");
    out += LOCI_SHOW_u16_partner_key(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_bsn_vport_header_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_bsn_vport_header_t *obj)
{
    int out = 0;

    return out;
}

int
of_bsn_vport_q_in_q_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_bsn_vport_q_in_q_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint16_t val16;
    of_port_name_t port_name;

    of_bsn_vport_q_in_q_port_no_get(obj, &val32);
    out += writer(cookie, "port_no=");
    out += LOCI_SHOW_u32_port_no(writer, cookie, val32);
    out += writer(cookie, " ");

    of_bsn_vport_q_in_q_ingress_tpid_get(obj, &val16);
    out += writer(cookie, "ingress_tpid=");
    out += LOCI_SHOW_u16_ingress_tpid(writer, cookie, val16);
    out += writer(cookie, " ");

    of_bsn_vport_q_in_q_ingress_vlan_id_get(obj, &val16);
    out += writer(cookie, "ingress_vlan_id=");
    out += LOCI_SHOW_u16_ingress_vlan_id(writer, cookie, val16);
    out += writer(cookie, " ");

    of_bsn_vport_q_in_q_egress_tpid_get(obj, &val16);
    out += writer(cookie, "egress_tpid=");
    out += LOCI_SHOW_u16_egress_tpid(writer, cookie, val16);
    out += writer(cookie, " ");

    of_bsn_vport_q_in_q_egress_vlan_id_get(obj, &val16);
    out += writer(cookie, "egress_vlan_id=");
    out += LOCI_SHOW_u16_egress_vlan_id(writer, cookie, val16);
    out += writer(cookie, " ");

    of_bsn_vport_q_in_q_if_name_get(obj, &port_name);
    out += writer(cookie, "if_name=");
    out += LOCI_SHOW_port_name_if_name(writer, cookie, port_name);
    out += writer(cookie, " ");

    return out;
}

int
of_bucket_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_bucket_t *obj)
{
    int out = 0;
    uint16_t val16;
    of_port_no_t port_no;
    uint32_t val32;

    of_list_action_t list;
    of_action_t elt;
    int rv;

    of_bucket_weight_get(obj, &val16);
    out += writer(cookie, "weight=");
    out += LOCI_SHOW_u16_weight(writer, cookie, val16);
    out += writer(cookie, " ");

    of_bucket_watch_port_get(obj, &port_no);
    out += writer(cookie, "watch_port=");
    out += LOCI_SHOW_port_no_watch_port(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_bucket_watch_group_get(obj, &val32);
    out += writer(cookie, "watch_group=");
    out += LOCI_SHOW_u32_watch_group(writer, cookie, val32);
    out += writer(cookie, " ");

    out += writer(cookie, "of_action_t={ ");
    of_bucket_actions_bind(obj, &list);
    OF_LIST_ACTION_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_bucket_counter_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_bucket_counter_t *obj)
{
    int out = 0;
    uint64_t val64;

    of_bucket_counter_packet_count_get(obj, &val64);
    out += writer(cookie, "packet_count=");
    out += LOCI_SHOW_u64_packet_count(writer, cookie, val64);
    out += writer(cookie, " ");

    of_bucket_counter_byte_count_get(obj, &val64);
    out += writer(cookie, "byte_count=");
    out += LOCI_SHOW_u64_byte_count(writer, cookie, val64);
    out += writer(cookie, " ");

    return out;
}

int
of_experimenter_stats_header_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_experimenter_stats_header_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_experimenter_stats_header_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_experimenter_stats_header_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_flow_stats_entry_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_flow_stats_entry_t *obj)
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

    of_flow_stats_entry_table_id_get(obj, &val8);
    out += writer(cookie, "table_id=");
    out += LOCI_SHOW_u8_table_id(writer, cookie, val8);
    out += writer(cookie, " ");

    of_flow_stats_entry_duration_sec_get(obj, &val32);
    out += writer(cookie, "duration_sec=");
    out += LOCI_SHOW_u32_duration_sec(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_stats_entry_duration_nsec_get(obj, &val32);
    out += writer(cookie, "duration_nsec=");
    out += LOCI_SHOW_u32_duration_nsec(writer, cookie, val32);
    out += writer(cookie, " ");

    of_flow_stats_entry_priority_get(obj, &val16);
    out += writer(cookie, "priority=");
    out += LOCI_SHOW_u16_priority(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_stats_entry_idle_timeout_get(obj, &val16);
    out += writer(cookie, "idle_timeout=");
    out += LOCI_SHOW_u16_idle_timeout(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_stats_entry_hard_timeout_get(obj, &val16);
    out += writer(cookie, "hard_timeout=");
    out += LOCI_SHOW_u16_hard_timeout(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_stats_entry_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    of_flow_stats_entry_cookie_get(obj, &val64);
    out += writer(cookie, "cookie=");
    out += LOCI_SHOW_u64_cookie(writer, cookie, val64);
    out += writer(cookie, " ");

    of_flow_stats_entry_packet_count_get(obj, &val64);
    out += writer(cookie, "packet_count=");
    out += LOCI_SHOW_u64_packet_count(writer, cookie, val64);
    out += writer(cookie, " ");

    of_flow_stats_entry_byte_count_get(obj, &val64);
    out += writer(cookie, "byte_count=");
    out += LOCI_SHOW_u64_byte_count(writer, cookie, val64);
    out += writer(cookie, " ");

    of_flow_stats_entry_match_get(obj, &match);
    out += writer(cookie, "match=");
    out += LOCI_SHOW_match_match(writer, cookie, match);
    out += writer(cookie, " ");

    out += writer(cookie, "of_instruction_t={ ");
    of_flow_stats_entry_instructions_bind(obj, &list);
    OF_LIST_INSTRUCTION_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_group_desc_stats_entry_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_group_desc_stats_entry_t *obj)
{
    int out = 0;
    uint8_t val8;
    uint32_t val32;

    of_list_bucket_t list;
    of_bucket_t elt;
    int rv;

    of_group_desc_stats_entry_group_type_get(obj, &val8);
    out += writer(cookie, "group_type=");
    out += LOCI_SHOW_u8_group_type(writer, cookie, val8);
    out += writer(cookie, " ");

    of_group_desc_stats_entry_group_id_get(obj, &val32);
    out += writer(cookie, "group_id=");
    out += LOCI_SHOW_u32_group_id(writer, cookie, val32);
    out += writer(cookie, " ");

    out += writer(cookie, "of_bucket_t={ ");
    of_group_desc_stats_entry_buckets_bind(obj, &list);
    OF_LIST_BUCKET_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_group_stats_entry_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_group_stats_entry_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint64_t val64;

    of_list_bucket_counter_t list;
    of_bucket_counter_t elt;
    int rv;

    of_group_stats_entry_group_id_get(obj, &val32);
    out += writer(cookie, "group_id=");
    out += LOCI_SHOW_u32_group_id(writer, cookie, val32);
    out += writer(cookie, " ");

    of_group_stats_entry_ref_count_get(obj, &val32);
    out += writer(cookie, "ref_count=");
    out += LOCI_SHOW_u32_ref_count(writer, cookie, val32);
    out += writer(cookie, " ");

    of_group_stats_entry_packet_count_get(obj, &val64);
    out += writer(cookie, "packet_count=");
    out += LOCI_SHOW_u64_packet_count(writer, cookie, val64);
    out += writer(cookie, " ");

    of_group_stats_entry_byte_count_get(obj, &val64);
    out += writer(cookie, "byte_count=");
    out += LOCI_SHOW_u64_byte_count(writer, cookie, val64);
    out += writer(cookie, " ");

    of_group_stats_entry_duration_sec_get(obj, &val32);
    out += writer(cookie, "duration_sec=");
    out += LOCI_SHOW_u32_duration_sec(writer, cookie, val32);
    out += writer(cookie, " ");

    of_group_stats_entry_duration_nsec_get(obj, &val32);
    out += writer(cookie, "duration_nsec=");
    out += LOCI_SHOW_u32_duration_nsec(writer, cookie, val32);
    out += writer(cookie, " ");

    out += writer(cookie, "of_bucket_counter_t={ ");
    of_group_stats_entry_bucket_stats_bind(obj, &list);
    OF_LIST_BUCKET_COUNTER_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_header_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_header_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_header_xid_get(obj, &val32);
    out += writer(cookie, "xid=");
    out += LOCI_SHOW_u32_xid(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_hello_elem_header_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_hello_elem_header_t *obj)
{
    int out = 0;

    return out;
}

int
of_hello_elem_versionbitmap_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_hello_elem_versionbitmap_t *obj)
{
    int out = 0;

    of_list_uint32_t list;
    of_uint32_t elt;
    int rv;

    out += writer(cookie, "of_uint32_t={ ");
    of_hello_elem_versionbitmap_bitmaps_bind(obj, &list);
    OF_LIST_UINT32_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_instruction_apply_actions_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_instruction_apply_actions_t *obj)
{
    int out = 0;

    of_list_action_t list;
    of_action_t elt;
    int rv;

    out += writer(cookie, "of_action_t={ ");
    of_instruction_apply_actions_actions_bind(obj, &list);
    OF_LIST_ACTION_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_instruction_bsn_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_instruction_bsn_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_instruction_bsn_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_instruction_bsn_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_instruction_bsn_disable_src_mac_check_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_instruction_bsn_disable_src_mac_check_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_instruction_bsn_disable_src_mac_check_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_instruction_bsn_disable_src_mac_check_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_instruction_clear_actions_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_instruction_clear_actions_t *obj)
{
    int out = 0;

    return out;
}

int
of_instruction_experimenter_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_instruction_experimenter_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_octets_t octets;

    of_instruction_experimenter_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_instruction_experimenter_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_instruction_goto_table_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_instruction_goto_table_t *obj)
{
    int out = 0;
    uint8_t val8;

    of_instruction_goto_table_table_id_get(obj, &val8);
    out += writer(cookie, "table_id=");
    out += LOCI_SHOW_u8_table_id(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_instruction_header_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_instruction_header_t *obj)
{
    int out = 0;

    return out;
}

int
of_instruction_meter_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_instruction_meter_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_instruction_meter_meter_id_get(obj, &val32);
    out += writer(cookie, "meter_id=");
    out += LOCI_SHOW_u32_meter_id(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_instruction_write_actions_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_instruction_write_actions_t *obj)
{
    int out = 0;

    of_list_action_t list;
    of_action_t elt;
    int rv;

    out += writer(cookie, "of_action_t={ ");
    of_instruction_write_actions_actions_bind(obj, &list);
    OF_LIST_ACTION_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_instruction_write_metadata_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_instruction_write_metadata_t *obj)
{
    int out = 0;
    uint64_t val64;

    of_instruction_write_metadata_metadata_get(obj, &val64);
    out += writer(cookie, "metadata=");
    out += LOCI_SHOW_u64_metadata(writer, cookie, val64);
    out += writer(cookie, " ");

    of_instruction_write_metadata_metadata_mask_get(obj, &val64);
    out += writer(cookie, "metadata_mask=");
    out += LOCI_SHOW_u64_metadata_mask(writer, cookie, val64);
    out += writer(cookie, " ");

    return out;
}

int
of_match_v3_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_match_v3_t *obj)
{
    int out = 0;

    of_list_oxm_t list;
    of_oxm_t elt;
    int rv;

    out += writer(cookie, "of_oxm_t={ ");
    of_match_v3_oxm_list_bind(obj, &list);
    OF_LIST_OXM_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_meter_band_drop_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_meter_band_drop_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_meter_band_drop_rate_get(obj, &val32);
    out += writer(cookie, "rate=");
    out += LOCI_SHOW_u32_rate(writer, cookie, val32);
    out += writer(cookie, " ");

    of_meter_band_drop_burst_size_get(obj, &val32);
    out += writer(cookie, "burst_size=");
    out += LOCI_SHOW_u32_burst_size(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_meter_band_dscp_remark_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_meter_band_dscp_remark_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint8_t val8;

    of_meter_band_dscp_remark_rate_get(obj, &val32);
    out += writer(cookie, "rate=");
    out += LOCI_SHOW_u32_rate(writer, cookie, val32);
    out += writer(cookie, " ");

    of_meter_band_dscp_remark_burst_size_get(obj, &val32);
    out += writer(cookie, "burst_size=");
    out += LOCI_SHOW_u32_burst_size(writer, cookie, val32);
    out += writer(cookie, " ");

    of_meter_band_dscp_remark_prec_level_get(obj, &val8);
    out += writer(cookie, "prec_level=");
    out += LOCI_SHOW_u8_prec_level(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_meter_band_experimenter_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_meter_band_experimenter_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_meter_band_experimenter_rate_get(obj, &val32);
    out += writer(cookie, "rate=");
    out += LOCI_SHOW_u32_rate(writer, cookie, val32);
    out += writer(cookie, " ");

    of_meter_band_experimenter_burst_size_get(obj, &val32);
    out += writer(cookie, "burst_size=");
    out += LOCI_SHOW_u32_burst_size(writer, cookie, val32);
    out += writer(cookie, " ");

    of_meter_band_experimenter_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_meter_band_header_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_meter_band_header_t *obj)
{
    int out = 0;

    return out;
}

int
of_meter_band_stats_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_meter_band_stats_t *obj)
{
    int out = 0;
    uint64_t val64;

    of_meter_band_stats_packet_band_count_get(obj, &val64);
    out += writer(cookie, "packet_band_count=");
    out += LOCI_SHOW_u64_packet_band_count(writer, cookie, val64);
    out += writer(cookie, " ");

    of_meter_band_stats_byte_band_count_get(obj, &val64);
    out += writer(cookie, "byte_band_count=");
    out += LOCI_SHOW_u64_byte_band_count(writer, cookie, val64);
    out += writer(cookie, " ");

    return out;
}

int
of_meter_config_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_meter_config_t *obj)
{
    int out = 0;
    uint16_t val16;
    uint32_t val32;

    of_list_meter_band_t list;
    of_meter_band_t elt;
    int rv;

    of_meter_config_flags_get(obj, &val16);
    out += writer(cookie, "flags=");
    out += LOCI_SHOW_u16_flags(writer, cookie, val16);
    out += writer(cookie, " ");

    of_meter_config_meter_id_get(obj, &val32);
    out += writer(cookie, "meter_id=");
    out += LOCI_SHOW_u32_meter_id(writer, cookie, val32);
    out += writer(cookie, " ");

    out += writer(cookie, "of_meter_band_t={ ");
    of_meter_config_entries_bind(obj, &list);
    OF_LIST_METER_BAND_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_meter_features_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_meter_features_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint8_t val8;

    of_meter_features_max_meter_get(obj, &val32);
    out += writer(cookie, "max_meter=");
    out += LOCI_SHOW_u32_max_meter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_meter_features_band_types_get(obj, &val32);
    out += writer(cookie, "band_types=");
    out += LOCI_SHOW_u32_band_types(writer, cookie, val32);
    out += writer(cookie, " ");

    of_meter_features_capabilities_get(obj, &val32);
    out += writer(cookie, "capabilities=");
    out += LOCI_SHOW_u32_capabilities(writer, cookie, val32);
    out += writer(cookie, " ");

    of_meter_features_max_bands_get(obj, &val8);
    out += writer(cookie, "max_bands=");
    out += LOCI_SHOW_u8_max_bands(writer, cookie, val8);
    out += writer(cookie, " ");

    of_meter_features_max_color_get(obj, &val8);
    out += writer(cookie, "max_color=");
    out += LOCI_SHOW_u8_max_color(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_meter_stats_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_meter_stats_t *obj)
{
    int out = 0;
    uint32_t val32;
    uint64_t val64;

    of_list_meter_band_stats_t list;
    of_meter_band_stats_t elt;
    int rv;

    of_meter_stats_meter_id_get(obj, &val32);
    out += writer(cookie, "meter_id=");
    out += LOCI_SHOW_u32_meter_id(writer, cookie, val32);
    out += writer(cookie, " ");

    of_meter_stats_flow_count_get(obj, &val32);
    out += writer(cookie, "flow_count=");
    out += LOCI_SHOW_u32_flow_count(writer, cookie, val32);
    out += writer(cookie, " ");

    of_meter_stats_packet_in_count_get(obj, &val64);
    out += writer(cookie, "packet_in_count=");
    out += LOCI_SHOW_u64_packet_in_count(writer, cookie, val64);
    out += writer(cookie, " ");

    of_meter_stats_byte_in_count_get(obj, &val64);
    out += writer(cookie, "byte_in_count=");
    out += LOCI_SHOW_u64_byte_in_count(writer, cookie, val64);
    out += writer(cookie, " ");

    of_meter_stats_duration_sec_get(obj, &val32);
    out += writer(cookie, "duration_sec=");
    out += LOCI_SHOW_u32_duration_sec(writer, cookie, val32);
    out += writer(cookie, " ");

    of_meter_stats_duration_nsec_get(obj, &val32);
    out += writer(cookie, "duration_nsec=");
    out += LOCI_SHOW_u32_duration_nsec(writer, cookie, val32);
    out += writer(cookie, " ");

    out += writer(cookie, "of_meter_band_stats_t={ ");
    of_meter_stats_band_stats_bind(obj, &list);
    OF_LIST_METER_BAND_STATS_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_oxm_arp_op_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_arp_op_t *obj)
{
    int out = 0;
    uint16_t val16;

    of_oxm_arp_op_value_get(obj, &val16);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u16_value(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_arp_op_masked_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_arp_op_masked_t *obj)
{
    int out = 0;
    uint16_t val16;

    of_oxm_arp_op_masked_value_get(obj, &val16);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u16_value(writer, cookie, val16);
    out += writer(cookie, " ");

    of_oxm_arp_op_masked_value_mask_get(obj, &val16);
    out += writer(cookie, "value_mask=");
    out += LOCI_SHOW_u16_value_mask(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_arp_sha_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_arp_sha_t *obj)
{
    int out = 0;
    of_mac_addr_t mac_addr;

    of_oxm_arp_sha_value_get(obj, &mac_addr);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_mac_value(writer, cookie, mac_addr);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_arp_sha_masked_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_arp_sha_masked_t *obj)
{
    int out = 0;
    of_mac_addr_t mac_addr;

    of_oxm_arp_sha_masked_value_get(obj, &mac_addr);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_mac_value(writer, cookie, mac_addr);
    out += writer(cookie, " ");

    of_oxm_arp_sha_masked_value_mask_get(obj, &mac_addr);
    out += writer(cookie, "value_mask=");
    out += LOCI_SHOW_mac_value_mask(writer, cookie, mac_addr);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_arp_spa_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_arp_spa_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_oxm_arp_spa_value_get(obj, &val32);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u32_value(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_arp_spa_masked_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_arp_spa_masked_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_oxm_arp_spa_masked_value_get(obj, &val32);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u32_value(writer, cookie, val32);
    out += writer(cookie, " ");

    of_oxm_arp_spa_masked_value_mask_get(obj, &val32);
    out += writer(cookie, "value_mask=");
    out += LOCI_SHOW_u32_value_mask(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_arp_tha_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_arp_tha_t *obj)
{
    int out = 0;
    of_mac_addr_t mac_addr;

    of_oxm_arp_tha_value_get(obj, &mac_addr);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_mac_value(writer, cookie, mac_addr);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_arp_tha_masked_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_arp_tha_masked_t *obj)
{
    int out = 0;
    of_mac_addr_t mac_addr;

    of_oxm_arp_tha_masked_value_get(obj, &mac_addr);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_mac_value(writer, cookie, mac_addr);
    out += writer(cookie, " ");

    of_oxm_arp_tha_masked_value_mask_get(obj, &mac_addr);
    out += writer(cookie, "value_mask=");
    out += LOCI_SHOW_mac_value_mask(writer, cookie, mac_addr);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_arp_tpa_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_arp_tpa_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_oxm_arp_tpa_value_get(obj, &val32);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u32_value(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_arp_tpa_masked_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_arp_tpa_masked_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_oxm_arp_tpa_masked_value_get(obj, &val32);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u32_value(writer, cookie, val32);
    out += writer(cookie, " ");

    of_oxm_arp_tpa_masked_value_mask_get(obj, &val32);
    out += writer(cookie, "value_mask=");
    out += LOCI_SHOW_u32_value_mask(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_bsn_global_vrf_allowed_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_bsn_global_vrf_allowed_t *obj)
{
    int out = 0;
    uint8_t val8;

    of_oxm_bsn_global_vrf_allowed_value_get(obj, &val8);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u8_value(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_bsn_global_vrf_allowed_masked_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_bsn_global_vrf_allowed_masked_t *obj)
{
    int out = 0;
    uint8_t val8;

    of_oxm_bsn_global_vrf_allowed_masked_value_get(obj, &val8);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u8_value(writer, cookie, val8);
    out += writer(cookie, " ");

    of_oxm_bsn_global_vrf_allowed_masked_value_mask_get(obj, &val8);
    out += writer(cookie, "value_mask=");
    out += LOCI_SHOW_u8_value_mask(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_bsn_in_ports_128_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_bsn_in_ports_128_t *obj)
{
    int out = 0;
    of_bitmap_128_t bitmap_128;

    of_oxm_bsn_in_ports_128_value_get(obj, &bitmap_128);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_bitmap_128_value(writer, cookie, bitmap_128);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_bsn_in_ports_128_masked_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_bsn_in_ports_128_masked_t *obj)
{
    int out = 0;
    of_bitmap_128_t bitmap_128;

    of_oxm_bsn_in_ports_128_masked_value_get(obj, &bitmap_128);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_bitmap_128_value(writer, cookie, bitmap_128);
    out += writer(cookie, " ");

    of_oxm_bsn_in_ports_128_masked_value_mask_get(obj, &bitmap_128);
    out += writer(cookie, "value_mask=");
    out += LOCI_SHOW_bitmap_128_value_mask(writer, cookie, bitmap_128);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_bsn_l3_dst_class_id_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_bsn_l3_dst_class_id_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_oxm_bsn_l3_dst_class_id_value_get(obj, &val32);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u32_value(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_bsn_l3_dst_class_id_masked_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_bsn_l3_dst_class_id_masked_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_oxm_bsn_l3_dst_class_id_masked_value_get(obj, &val32);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u32_value(writer, cookie, val32);
    out += writer(cookie, " ");

    of_oxm_bsn_l3_dst_class_id_masked_value_mask_get(obj, &val32);
    out += writer(cookie, "value_mask=");
    out += LOCI_SHOW_u32_value_mask(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_bsn_l3_interface_class_id_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_bsn_l3_interface_class_id_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_oxm_bsn_l3_interface_class_id_value_get(obj, &val32);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u32_value(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_bsn_l3_interface_class_id_masked_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_bsn_l3_interface_class_id_masked_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_oxm_bsn_l3_interface_class_id_masked_value_get(obj, &val32);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u32_value(writer, cookie, val32);
    out += writer(cookie, " ");

    of_oxm_bsn_l3_interface_class_id_masked_value_mask_get(obj, &val32);
    out += writer(cookie, "value_mask=");
    out += LOCI_SHOW_u32_value_mask(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_bsn_l3_src_class_id_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_bsn_l3_src_class_id_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_oxm_bsn_l3_src_class_id_value_get(obj, &val32);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u32_value(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_bsn_l3_src_class_id_masked_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_bsn_l3_src_class_id_masked_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_oxm_bsn_l3_src_class_id_masked_value_get(obj, &val32);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u32_value(writer, cookie, val32);
    out += writer(cookie, " ");

    of_oxm_bsn_l3_src_class_id_masked_value_mask_get(obj, &val32);
    out += writer(cookie, "value_mask=");
    out += LOCI_SHOW_u32_value_mask(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_bsn_lag_id_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_bsn_lag_id_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_oxm_bsn_lag_id_value_get(obj, &val32);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u32_value(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_bsn_lag_id_masked_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_bsn_lag_id_masked_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_oxm_bsn_lag_id_masked_value_get(obj, &val32);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u32_value(writer, cookie, val32);
    out += writer(cookie, " ");

    of_oxm_bsn_lag_id_masked_value_mask_get(obj, &val32);
    out += writer(cookie, "value_mask=");
    out += LOCI_SHOW_u32_value_mask(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_bsn_vrf_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_bsn_vrf_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_oxm_bsn_vrf_value_get(obj, &val32);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u32_value(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_bsn_vrf_masked_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_bsn_vrf_masked_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_oxm_bsn_vrf_masked_value_get(obj, &val32);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u32_value(writer, cookie, val32);
    out += writer(cookie, " ");

    of_oxm_bsn_vrf_masked_value_mask_get(obj, &val32);
    out += writer(cookie, "value_mask=");
    out += LOCI_SHOW_u32_value_mask(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_eth_dst_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_eth_dst_t *obj)
{
    int out = 0;
    of_mac_addr_t mac_addr;

    of_oxm_eth_dst_value_get(obj, &mac_addr);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_mac_value(writer, cookie, mac_addr);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_eth_dst_masked_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_eth_dst_masked_t *obj)
{
    int out = 0;
    of_mac_addr_t mac_addr;

    of_oxm_eth_dst_masked_value_get(obj, &mac_addr);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_mac_value(writer, cookie, mac_addr);
    out += writer(cookie, " ");

    of_oxm_eth_dst_masked_value_mask_get(obj, &mac_addr);
    out += writer(cookie, "value_mask=");
    out += LOCI_SHOW_mac_value_mask(writer, cookie, mac_addr);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_eth_src_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_eth_src_t *obj)
{
    int out = 0;
    of_mac_addr_t mac_addr;

    of_oxm_eth_src_value_get(obj, &mac_addr);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_mac_value(writer, cookie, mac_addr);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_eth_src_masked_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_eth_src_masked_t *obj)
{
    int out = 0;
    of_mac_addr_t mac_addr;

    of_oxm_eth_src_masked_value_get(obj, &mac_addr);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_mac_value(writer, cookie, mac_addr);
    out += writer(cookie, " ");

    of_oxm_eth_src_masked_value_mask_get(obj, &mac_addr);
    out += writer(cookie, "value_mask=");
    out += LOCI_SHOW_mac_value_mask(writer, cookie, mac_addr);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_eth_type_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_eth_type_t *obj)
{
    int out = 0;
    uint16_t val16;

    of_oxm_eth_type_value_get(obj, &val16);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u16_value(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_eth_type_masked_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_eth_type_masked_t *obj)
{
    int out = 0;
    uint16_t val16;

    of_oxm_eth_type_masked_value_get(obj, &val16);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u16_value(writer, cookie, val16);
    out += writer(cookie, " ");

    of_oxm_eth_type_masked_value_mask_get(obj, &val16);
    out += writer(cookie, "value_mask=");
    out += LOCI_SHOW_u16_value_mask(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_header_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_header_t *obj)
{
    int out = 0;

    return out;
}

int
of_oxm_icmpv4_code_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_icmpv4_code_t *obj)
{
    int out = 0;
    uint8_t val8;

    of_oxm_icmpv4_code_value_get(obj, &val8);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u8_value(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_icmpv4_code_masked_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_icmpv4_code_masked_t *obj)
{
    int out = 0;
    uint8_t val8;

    of_oxm_icmpv4_code_masked_value_get(obj, &val8);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u8_value(writer, cookie, val8);
    out += writer(cookie, " ");

    of_oxm_icmpv4_code_masked_value_mask_get(obj, &val8);
    out += writer(cookie, "value_mask=");
    out += LOCI_SHOW_u8_value_mask(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_icmpv4_type_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_icmpv4_type_t *obj)
{
    int out = 0;
    uint8_t val8;

    of_oxm_icmpv4_type_value_get(obj, &val8);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u8_value(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_icmpv4_type_masked_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_icmpv4_type_masked_t *obj)
{
    int out = 0;
    uint8_t val8;

    of_oxm_icmpv4_type_masked_value_get(obj, &val8);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u8_value(writer, cookie, val8);
    out += writer(cookie, " ");

    of_oxm_icmpv4_type_masked_value_mask_get(obj, &val8);
    out += writer(cookie, "value_mask=");
    out += LOCI_SHOW_u8_value_mask(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_icmpv6_code_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_icmpv6_code_t *obj)
{
    int out = 0;
    uint8_t val8;

    of_oxm_icmpv6_code_value_get(obj, &val8);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u8_value(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_icmpv6_code_masked_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_icmpv6_code_masked_t *obj)
{
    int out = 0;
    uint8_t val8;

    of_oxm_icmpv6_code_masked_value_get(obj, &val8);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u8_value(writer, cookie, val8);
    out += writer(cookie, " ");

    of_oxm_icmpv6_code_masked_value_mask_get(obj, &val8);
    out += writer(cookie, "value_mask=");
    out += LOCI_SHOW_u8_value_mask(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_icmpv6_type_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_icmpv6_type_t *obj)
{
    int out = 0;
    uint8_t val8;

    of_oxm_icmpv6_type_value_get(obj, &val8);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u8_value(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_icmpv6_type_masked_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_icmpv6_type_masked_t *obj)
{
    int out = 0;
    uint8_t val8;

    of_oxm_icmpv6_type_masked_value_get(obj, &val8);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u8_value(writer, cookie, val8);
    out += writer(cookie, " ");

    of_oxm_icmpv6_type_masked_value_mask_get(obj, &val8);
    out += writer(cookie, "value_mask=");
    out += LOCI_SHOW_u8_value_mask(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_in_phy_port_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_in_phy_port_t *obj)
{
    int out = 0;
    of_port_no_t port_no;

    of_oxm_in_phy_port_value_get(obj, &port_no);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_port_no_value(writer, cookie, port_no);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_in_phy_port_masked_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_in_phy_port_masked_t *obj)
{
    int out = 0;
    of_port_no_t port_no;

    of_oxm_in_phy_port_masked_value_get(obj, &port_no);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_port_no_value(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_oxm_in_phy_port_masked_value_mask_get(obj, &port_no);
    out += writer(cookie, "value_mask=");
    out += LOCI_SHOW_port_no_value_mask(writer, cookie, port_no);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_in_port_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_in_port_t *obj)
{
    int out = 0;
    of_port_no_t port_no;

    of_oxm_in_port_value_get(obj, &port_no);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_port_no_value(writer, cookie, port_no);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_in_port_masked_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_in_port_masked_t *obj)
{
    int out = 0;
    of_port_no_t port_no;

    of_oxm_in_port_masked_value_get(obj, &port_no);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_port_no_value(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_oxm_in_port_masked_value_mask_get(obj, &port_no);
    out += writer(cookie, "value_mask=");
    out += LOCI_SHOW_port_no_value_mask(writer, cookie, port_no);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_ip_dscp_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_ip_dscp_t *obj)
{
    int out = 0;
    uint8_t val8;

    of_oxm_ip_dscp_value_get(obj, &val8);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u8_value(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_ip_dscp_masked_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_ip_dscp_masked_t *obj)
{
    int out = 0;
    uint8_t val8;

    of_oxm_ip_dscp_masked_value_get(obj, &val8);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u8_value(writer, cookie, val8);
    out += writer(cookie, " ");

    of_oxm_ip_dscp_masked_value_mask_get(obj, &val8);
    out += writer(cookie, "value_mask=");
    out += LOCI_SHOW_u8_value_mask(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_ip_ecn_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_ip_ecn_t *obj)
{
    int out = 0;
    uint8_t val8;

    of_oxm_ip_ecn_value_get(obj, &val8);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u8_value(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_ip_ecn_masked_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_ip_ecn_masked_t *obj)
{
    int out = 0;
    uint8_t val8;

    of_oxm_ip_ecn_masked_value_get(obj, &val8);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u8_value(writer, cookie, val8);
    out += writer(cookie, " ");

    of_oxm_ip_ecn_masked_value_mask_get(obj, &val8);
    out += writer(cookie, "value_mask=");
    out += LOCI_SHOW_u8_value_mask(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_ip_proto_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_ip_proto_t *obj)
{
    int out = 0;
    uint8_t val8;

    of_oxm_ip_proto_value_get(obj, &val8);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u8_value(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_ip_proto_masked_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_ip_proto_masked_t *obj)
{
    int out = 0;
    uint8_t val8;

    of_oxm_ip_proto_masked_value_get(obj, &val8);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u8_value(writer, cookie, val8);
    out += writer(cookie, " ");

    of_oxm_ip_proto_masked_value_mask_get(obj, &val8);
    out += writer(cookie, "value_mask=");
    out += LOCI_SHOW_u8_value_mask(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_ipv4_dst_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_ipv4_dst_t *obj)
{
    int out = 0;
    of_ipv4_t ipv4;

    of_oxm_ipv4_dst_value_get(obj, &ipv4);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_ipv4_value(writer, cookie, ipv4);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_ipv4_dst_masked_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_ipv4_dst_masked_t *obj)
{
    int out = 0;
    of_ipv4_t ipv4;

    of_oxm_ipv4_dst_masked_value_get(obj, &ipv4);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_ipv4_value(writer, cookie, ipv4);
    out += writer(cookie, " ");

    of_oxm_ipv4_dst_masked_value_mask_get(obj, &ipv4);
    out += writer(cookie, "value_mask=");
    out += LOCI_SHOW_ipv4_value_mask(writer, cookie, ipv4);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_ipv4_src_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_ipv4_src_t *obj)
{
    int out = 0;
    of_ipv4_t ipv4;

    of_oxm_ipv4_src_value_get(obj, &ipv4);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_ipv4_value(writer, cookie, ipv4);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_ipv4_src_masked_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_ipv4_src_masked_t *obj)
{
    int out = 0;
    of_ipv4_t ipv4;

    of_oxm_ipv4_src_masked_value_get(obj, &ipv4);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_ipv4_value(writer, cookie, ipv4);
    out += writer(cookie, " ");

    of_oxm_ipv4_src_masked_value_mask_get(obj, &ipv4);
    out += writer(cookie, "value_mask=");
    out += LOCI_SHOW_ipv4_value_mask(writer, cookie, ipv4);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_ipv6_dst_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_ipv6_dst_t *obj)
{
    int out = 0;
    of_ipv6_t ipv6;

    of_oxm_ipv6_dst_value_get(obj, &ipv6);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_ipv6_value(writer, cookie, ipv6);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_ipv6_dst_masked_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_ipv6_dst_masked_t *obj)
{
    int out = 0;
    of_ipv6_t ipv6;

    of_oxm_ipv6_dst_masked_value_get(obj, &ipv6);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_ipv6_value(writer, cookie, ipv6);
    out += writer(cookie, " ");

    of_oxm_ipv6_dst_masked_value_mask_get(obj, &ipv6);
    out += writer(cookie, "value_mask=");
    out += LOCI_SHOW_ipv6_value_mask(writer, cookie, ipv6);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_ipv6_flabel_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_ipv6_flabel_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_oxm_ipv6_flabel_value_get(obj, &val32);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u32_value(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_ipv6_flabel_masked_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_ipv6_flabel_masked_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_oxm_ipv6_flabel_masked_value_get(obj, &val32);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u32_value(writer, cookie, val32);
    out += writer(cookie, " ");

    of_oxm_ipv6_flabel_masked_value_mask_get(obj, &val32);
    out += writer(cookie, "value_mask=");
    out += LOCI_SHOW_u32_value_mask(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_ipv6_nd_sll_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_ipv6_nd_sll_t *obj)
{
    int out = 0;
    of_mac_addr_t mac_addr;

    of_oxm_ipv6_nd_sll_value_get(obj, &mac_addr);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_mac_value(writer, cookie, mac_addr);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_ipv6_nd_sll_masked_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_ipv6_nd_sll_masked_t *obj)
{
    int out = 0;
    of_mac_addr_t mac_addr;

    of_oxm_ipv6_nd_sll_masked_value_get(obj, &mac_addr);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_mac_value(writer, cookie, mac_addr);
    out += writer(cookie, " ");

    of_oxm_ipv6_nd_sll_masked_value_mask_get(obj, &mac_addr);
    out += writer(cookie, "value_mask=");
    out += LOCI_SHOW_mac_value_mask(writer, cookie, mac_addr);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_ipv6_nd_target_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_ipv6_nd_target_t *obj)
{
    int out = 0;
    of_ipv6_t ipv6;

    of_oxm_ipv6_nd_target_value_get(obj, &ipv6);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_ipv6_value(writer, cookie, ipv6);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_ipv6_nd_target_masked_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_ipv6_nd_target_masked_t *obj)
{
    int out = 0;
    of_ipv6_t ipv6;

    of_oxm_ipv6_nd_target_masked_value_get(obj, &ipv6);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_ipv6_value(writer, cookie, ipv6);
    out += writer(cookie, " ");

    of_oxm_ipv6_nd_target_masked_value_mask_get(obj, &ipv6);
    out += writer(cookie, "value_mask=");
    out += LOCI_SHOW_ipv6_value_mask(writer, cookie, ipv6);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_ipv6_nd_tll_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_ipv6_nd_tll_t *obj)
{
    int out = 0;
    of_mac_addr_t mac_addr;

    of_oxm_ipv6_nd_tll_value_get(obj, &mac_addr);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_mac_value(writer, cookie, mac_addr);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_ipv6_nd_tll_masked_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_ipv6_nd_tll_masked_t *obj)
{
    int out = 0;
    of_mac_addr_t mac_addr;

    of_oxm_ipv6_nd_tll_masked_value_get(obj, &mac_addr);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_mac_value(writer, cookie, mac_addr);
    out += writer(cookie, " ");

    of_oxm_ipv6_nd_tll_masked_value_mask_get(obj, &mac_addr);
    out += writer(cookie, "value_mask=");
    out += LOCI_SHOW_mac_value_mask(writer, cookie, mac_addr);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_ipv6_src_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_ipv6_src_t *obj)
{
    int out = 0;
    of_ipv6_t ipv6;

    of_oxm_ipv6_src_value_get(obj, &ipv6);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_ipv6_value(writer, cookie, ipv6);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_ipv6_src_masked_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_ipv6_src_masked_t *obj)
{
    int out = 0;
    of_ipv6_t ipv6;

    of_oxm_ipv6_src_masked_value_get(obj, &ipv6);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_ipv6_value(writer, cookie, ipv6);
    out += writer(cookie, " ");

    of_oxm_ipv6_src_masked_value_mask_get(obj, &ipv6);
    out += writer(cookie, "value_mask=");
    out += LOCI_SHOW_ipv6_value_mask(writer, cookie, ipv6);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_metadata_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_metadata_t *obj)
{
    int out = 0;
    uint64_t val64;

    of_oxm_metadata_value_get(obj, &val64);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u64_value(writer, cookie, val64);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_metadata_masked_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_metadata_masked_t *obj)
{
    int out = 0;
    uint64_t val64;

    of_oxm_metadata_masked_value_get(obj, &val64);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u64_value(writer, cookie, val64);
    out += writer(cookie, " ");

    of_oxm_metadata_masked_value_mask_get(obj, &val64);
    out += writer(cookie, "value_mask=");
    out += LOCI_SHOW_u64_value_mask(writer, cookie, val64);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_mpls_label_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_mpls_label_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_oxm_mpls_label_value_get(obj, &val32);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u32_value(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_mpls_label_masked_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_mpls_label_masked_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_oxm_mpls_label_masked_value_get(obj, &val32);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u32_value(writer, cookie, val32);
    out += writer(cookie, " ");

    of_oxm_mpls_label_masked_value_mask_get(obj, &val32);
    out += writer(cookie, "value_mask=");
    out += LOCI_SHOW_u32_value_mask(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_mpls_tc_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_mpls_tc_t *obj)
{
    int out = 0;
    uint8_t val8;

    of_oxm_mpls_tc_value_get(obj, &val8);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u8_value(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_mpls_tc_masked_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_mpls_tc_masked_t *obj)
{
    int out = 0;
    uint8_t val8;

    of_oxm_mpls_tc_masked_value_get(obj, &val8);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u8_value(writer, cookie, val8);
    out += writer(cookie, " ");

    of_oxm_mpls_tc_masked_value_mask_get(obj, &val8);
    out += writer(cookie, "value_mask=");
    out += LOCI_SHOW_u8_value_mask(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_sctp_dst_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_sctp_dst_t *obj)
{
    int out = 0;
    uint16_t val16;

    of_oxm_sctp_dst_value_get(obj, &val16);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u16_value(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_sctp_dst_masked_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_sctp_dst_masked_t *obj)
{
    int out = 0;
    uint16_t val16;

    of_oxm_sctp_dst_masked_value_get(obj, &val16);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u16_value(writer, cookie, val16);
    out += writer(cookie, " ");

    of_oxm_sctp_dst_masked_value_mask_get(obj, &val16);
    out += writer(cookie, "value_mask=");
    out += LOCI_SHOW_u16_value_mask(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_sctp_src_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_sctp_src_t *obj)
{
    int out = 0;
    uint16_t val16;

    of_oxm_sctp_src_value_get(obj, &val16);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u16_value(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_sctp_src_masked_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_sctp_src_masked_t *obj)
{
    int out = 0;
    uint16_t val16;

    of_oxm_sctp_src_masked_value_get(obj, &val16);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u16_value(writer, cookie, val16);
    out += writer(cookie, " ");

    of_oxm_sctp_src_masked_value_mask_get(obj, &val16);
    out += writer(cookie, "value_mask=");
    out += LOCI_SHOW_u16_value_mask(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_tcp_dst_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_tcp_dst_t *obj)
{
    int out = 0;
    uint16_t val16;

    of_oxm_tcp_dst_value_get(obj, &val16);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u16_value(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_tcp_dst_masked_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_tcp_dst_masked_t *obj)
{
    int out = 0;
    uint16_t val16;

    of_oxm_tcp_dst_masked_value_get(obj, &val16);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u16_value(writer, cookie, val16);
    out += writer(cookie, " ");

    of_oxm_tcp_dst_masked_value_mask_get(obj, &val16);
    out += writer(cookie, "value_mask=");
    out += LOCI_SHOW_u16_value_mask(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_tcp_src_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_tcp_src_t *obj)
{
    int out = 0;
    uint16_t val16;

    of_oxm_tcp_src_value_get(obj, &val16);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u16_value(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_tcp_src_masked_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_tcp_src_masked_t *obj)
{
    int out = 0;
    uint16_t val16;

    of_oxm_tcp_src_masked_value_get(obj, &val16);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u16_value(writer, cookie, val16);
    out += writer(cookie, " ");

    of_oxm_tcp_src_masked_value_mask_get(obj, &val16);
    out += writer(cookie, "value_mask=");
    out += LOCI_SHOW_u16_value_mask(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_udp_dst_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_udp_dst_t *obj)
{
    int out = 0;
    uint16_t val16;

    of_oxm_udp_dst_value_get(obj, &val16);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u16_value(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_udp_dst_masked_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_udp_dst_masked_t *obj)
{
    int out = 0;
    uint16_t val16;

    of_oxm_udp_dst_masked_value_get(obj, &val16);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u16_value(writer, cookie, val16);
    out += writer(cookie, " ");

    of_oxm_udp_dst_masked_value_mask_get(obj, &val16);
    out += writer(cookie, "value_mask=");
    out += LOCI_SHOW_u16_value_mask(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_udp_src_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_udp_src_t *obj)
{
    int out = 0;
    uint16_t val16;

    of_oxm_udp_src_value_get(obj, &val16);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u16_value(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_udp_src_masked_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_udp_src_masked_t *obj)
{
    int out = 0;
    uint16_t val16;

    of_oxm_udp_src_masked_value_get(obj, &val16);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u16_value(writer, cookie, val16);
    out += writer(cookie, " ");

    of_oxm_udp_src_masked_value_mask_get(obj, &val16);
    out += writer(cookie, "value_mask=");
    out += LOCI_SHOW_u16_value_mask(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_vlan_pcp_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_vlan_pcp_t *obj)
{
    int out = 0;
    uint8_t val8;

    of_oxm_vlan_pcp_value_get(obj, &val8);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u8_value(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_vlan_pcp_masked_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_vlan_pcp_masked_t *obj)
{
    int out = 0;
    uint8_t val8;

    of_oxm_vlan_pcp_masked_value_get(obj, &val8);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u8_value(writer, cookie, val8);
    out += writer(cookie, " ");

    of_oxm_vlan_pcp_masked_value_mask_get(obj, &val8);
    out += writer(cookie, "value_mask=");
    out += LOCI_SHOW_u8_value_mask(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_vlan_vid_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_vlan_vid_t *obj)
{
    int out = 0;
    uint16_t val16;

    of_oxm_vlan_vid_value_get(obj, &val16);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u16_value(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_oxm_vlan_vid_masked_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_oxm_vlan_vid_masked_t *obj)
{
    int out = 0;
    uint16_t val16;

    of_oxm_vlan_vid_masked_value_get(obj, &val16);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u16_value(writer, cookie, val16);
    out += writer(cookie, " ");

    of_oxm_vlan_vid_masked_value_mask_get(obj, &val16);
    out += writer(cookie, "value_mask=");
    out += LOCI_SHOW_u16_value_mask(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_packet_queue_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_packet_queue_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_port_no_t port_no;

    of_list_queue_prop_t list;
    of_queue_prop_t elt;
    int rv;

    of_packet_queue_queue_id_get(obj, &val32);
    out += writer(cookie, "queue_id=");
    out += LOCI_SHOW_u32_queue_id(writer, cookie, val32);
    out += writer(cookie, " ");

    of_packet_queue_port_get(obj, &port_no);
    out += writer(cookie, "port=");
    out += LOCI_SHOW_port_no_port(writer, cookie, port_no);
    out += writer(cookie, " ");

    out += writer(cookie, "of_queue_prop_t={ ");
    of_packet_queue_properties_bind(obj, &list);
    OF_LIST_QUEUE_PROP_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_port_desc_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_port_desc_t *obj)
{
    int out = 0;
    of_port_no_t port_no;
    of_mac_addr_t mac_addr;
    of_port_name_t port_name;
    uint32_t val32;

    of_port_desc_port_no_get(obj, &port_no);
    out += writer(cookie, "port_no=");
    out += LOCI_SHOW_port_no_port_no(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_port_desc_hw_addr_get(obj, &mac_addr);
    out += writer(cookie, "hw_addr=");
    out += LOCI_SHOW_mac_hw_addr(writer, cookie, mac_addr);
    out += writer(cookie, " ");

    of_port_desc_name_get(obj, &port_name);
    out += writer(cookie, "name=");
    out += LOCI_SHOW_port_name_name(writer, cookie, port_name);
    out += writer(cookie, " ");

    of_port_desc_config_get(obj, &val32);
    out += writer(cookie, "config=");
    out += LOCI_SHOW_u32_config(writer, cookie, val32);
    out += writer(cookie, " ");

    of_port_desc_state_get(obj, &val32);
    out += writer(cookie, "state=");
    out += LOCI_SHOW_u32_state(writer, cookie, val32);
    out += writer(cookie, " ");

    of_port_desc_curr_get(obj, &val32);
    out += writer(cookie, "curr=");
    out += LOCI_SHOW_u32_curr(writer, cookie, val32);
    out += writer(cookie, " ");

    of_port_desc_advertised_get(obj, &val32);
    out += writer(cookie, "advertised=");
    out += LOCI_SHOW_u32_advertised(writer, cookie, val32);
    out += writer(cookie, " ");

    of_port_desc_supported_get(obj, &val32);
    out += writer(cookie, "supported=");
    out += LOCI_SHOW_u32_supported(writer, cookie, val32);
    out += writer(cookie, " ");

    of_port_desc_peer_get(obj, &val32);
    out += writer(cookie, "peer=");
    out += LOCI_SHOW_u32_peer(writer, cookie, val32);
    out += writer(cookie, " ");

    of_port_desc_curr_speed_get(obj, &val32);
    out += writer(cookie, "curr_speed=");
    out += LOCI_SHOW_u32_curr_speed(writer, cookie, val32);
    out += writer(cookie, " ");

    of_port_desc_max_speed_get(obj, &val32);
    out += writer(cookie, "max_speed=");
    out += LOCI_SHOW_u32_max_speed(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_port_stats_entry_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_port_stats_entry_t *obj)
{
    int out = 0;
    of_port_no_t port_no;
    uint64_t val64;
    uint32_t val32;

    of_port_stats_entry_port_no_get(obj, &port_no);
    out += writer(cookie, "port_no=");
    out += LOCI_SHOW_port_no_port_no(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_port_stats_entry_rx_packets_get(obj, &val64);
    out += writer(cookie, "rx_packets=");
    out += LOCI_SHOW_u64_rx_packets(writer, cookie, val64);
    out += writer(cookie, " ");

    of_port_stats_entry_tx_packets_get(obj, &val64);
    out += writer(cookie, "tx_packets=");
    out += LOCI_SHOW_u64_tx_packets(writer, cookie, val64);
    out += writer(cookie, " ");

    of_port_stats_entry_rx_bytes_get(obj, &val64);
    out += writer(cookie, "rx_bytes=");
    out += LOCI_SHOW_u64_rx_bytes(writer, cookie, val64);
    out += writer(cookie, " ");

    of_port_stats_entry_tx_bytes_get(obj, &val64);
    out += writer(cookie, "tx_bytes=");
    out += LOCI_SHOW_u64_tx_bytes(writer, cookie, val64);
    out += writer(cookie, " ");

    of_port_stats_entry_rx_dropped_get(obj, &val64);
    out += writer(cookie, "rx_dropped=");
    out += LOCI_SHOW_u64_rx_dropped(writer, cookie, val64);
    out += writer(cookie, " ");

    of_port_stats_entry_tx_dropped_get(obj, &val64);
    out += writer(cookie, "tx_dropped=");
    out += LOCI_SHOW_u64_tx_dropped(writer, cookie, val64);
    out += writer(cookie, " ");

    of_port_stats_entry_rx_errors_get(obj, &val64);
    out += writer(cookie, "rx_errors=");
    out += LOCI_SHOW_u64_rx_errors(writer, cookie, val64);
    out += writer(cookie, " ");

    of_port_stats_entry_tx_errors_get(obj, &val64);
    out += writer(cookie, "tx_errors=");
    out += LOCI_SHOW_u64_tx_errors(writer, cookie, val64);
    out += writer(cookie, " ");

    of_port_stats_entry_rx_frame_err_get(obj, &val64);
    out += writer(cookie, "rx_frame_err=");
    out += LOCI_SHOW_u64_rx_frame_err(writer, cookie, val64);
    out += writer(cookie, " ");

    of_port_stats_entry_rx_over_err_get(obj, &val64);
    out += writer(cookie, "rx_over_err=");
    out += LOCI_SHOW_u64_rx_over_err(writer, cookie, val64);
    out += writer(cookie, " ");

    of_port_stats_entry_rx_crc_err_get(obj, &val64);
    out += writer(cookie, "rx_crc_err=");
    out += LOCI_SHOW_u64_rx_crc_err(writer, cookie, val64);
    out += writer(cookie, " ");

    of_port_stats_entry_collisions_get(obj, &val64);
    out += writer(cookie, "collisions=");
    out += LOCI_SHOW_u64_collisions(writer, cookie, val64);
    out += writer(cookie, " ");

    of_port_stats_entry_duration_sec_get(obj, &val32);
    out += writer(cookie, "duration_sec=");
    out += LOCI_SHOW_u32_duration_sec(writer, cookie, val32);
    out += writer(cookie, " ");

    of_port_stats_entry_duration_nsec_get(obj, &val32);
    out += writer(cookie, "duration_nsec=");
    out += LOCI_SHOW_u32_duration_nsec(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_queue_prop_experimenter_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_queue_prop_experimenter_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_octets_t octets;

    of_queue_prop_experimenter_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_queue_prop_experimenter_data_get(obj, &octets);
    out += writer(cookie, "data=");
    out += LOCI_SHOW_octets_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_queue_prop_header_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_queue_prop_header_t *obj)
{
    int out = 0;

    return out;
}

int
of_queue_prop_max_rate_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_queue_prop_max_rate_t *obj)
{
    int out = 0;
    uint16_t val16;

    of_queue_prop_max_rate_rate_get(obj, &val16);
    out += writer(cookie, "rate=");
    out += LOCI_SHOW_u16_rate(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_queue_prop_min_rate_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_queue_prop_min_rate_t *obj)
{
    int out = 0;
    uint16_t val16;

    of_queue_prop_min_rate_rate_get(obj, &val16);
    out += writer(cookie, "rate=");
    out += LOCI_SHOW_u16_rate(writer, cookie, val16);
    out += writer(cookie, " ");

    return out;
}

int
of_queue_stats_entry_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_queue_stats_entry_t *obj)
{
    int out = 0;
    of_port_no_t port_no;
    uint32_t val32;
    uint64_t val64;

    of_queue_stats_entry_port_no_get(obj, &port_no);
    out += writer(cookie, "port_no=");
    out += LOCI_SHOW_port_no_port_no(writer, cookie, port_no);
    out += writer(cookie, " ");

    of_queue_stats_entry_queue_id_get(obj, &val32);
    out += writer(cookie, "queue_id=");
    out += LOCI_SHOW_u32_queue_id(writer, cookie, val32);
    out += writer(cookie, " ");

    of_queue_stats_entry_tx_bytes_get(obj, &val64);
    out += writer(cookie, "tx_bytes=");
    out += LOCI_SHOW_u64_tx_bytes(writer, cookie, val64);
    out += writer(cookie, " ");

    of_queue_stats_entry_tx_packets_get(obj, &val64);
    out += writer(cookie, "tx_packets=");
    out += LOCI_SHOW_u64_tx_packets(writer, cookie, val64);
    out += writer(cookie, " ");

    of_queue_stats_entry_tx_errors_get(obj, &val64);
    out += writer(cookie, "tx_errors=");
    out += LOCI_SHOW_u64_tx_errors(writer, cookie, val64);
    out += writer(cookie, " ");

    of_queue_stats_entry_duration_sec_get(obj, &val32);
    out += writer(cookie, "duration_sec=");
    out += LOCI_SHOW_u32_duration_sec(writer, cookie, val32);
    out += writer(cookie, " ");

    of_queue_stats_entry_duration_nsec_get(obj, &val32);
    out += writer(cookie, "duration_nsec=");
    out += LOCI_SHOW_u32_duration_nsec(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_table_feature_prop_apply_actions_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_table_feature_prop_apply_actions_t *obj)
{
    int out = 0;

    of_list_action_id_t list;
    of_action_id_t elt;
    int rv;

    out += writer(cookie, "of_action_id_t={ ");
    of_table_feature_prop_apply_actions_action_ids_bind(obj, &list);
    OF_LIST_ACTION_ID_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_table_feature_prop_apply_actions_miss_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_table_feature_prop_apply_actions_miss_t *obj)
{
    int out = 0;

    of_list_action_id_t list;
    of_action_id_t elt;
    int rv;

    out += writer(cookie, "of_action_id_t={ ");
    of_table_feature_prop_apply_actions_miss_action_ids_bind(obj, &list);
    OF_LIST_ACTION_ID_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_table_feature_prop_apply_setfield_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_table_feature_prop_apply_setfield_t *obj)
{
    int out = 0;

    of_list_uint32_t list;
    of_uint32_t elt;
    int rv;

    out += writer(cookie, "of_uint32_t={ ");
    of_table_feature_prop_apply_setfield_oxm_ids_bind(obj, &list);
    OF_LIST_UINT32_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_table_feature_prop_apply_setfield_miss_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_table_feature_prop_apply_setfield_miss_t *obj)
{
    int out = 0;

    of_list_uint32_t list;
    of_uint32_t elt;
    int rv;

    out += writer(cookie, "of_uint32_t={ ");
    of_table_feature_prop_apply_setfield_miss_oxm_ids_bind(obj, &list);
    OF_LIST_UINT32_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_table_feature_prop_experimenter_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_table_feature_prop_experimenter_t *obj)
{
    int out = 0;
    uint32_t val32;
    of_octets_t octets;

    of_table_feature_prop_experimenter_experimenter_get(obj, &val32);
    out += writer(cookie, "experimenter=");
    out += LOCI_SHOW_u32_experimenter(writer, cookie, val32);
    out += writer(cookie, " ");

    of_table_feature_prop_experimenter_subtype_get(obj, &val32);
    out += writer(cookie, "subtype=");
    out += LOCI_SHOW_u32_subtype(writer, cookie, val32);
    out += writer(cookie, " ");

    of_table_feature_prop_experimenter_experimenter_data_get(obj, &octets);
    out += writer(cookie, "experimenter_data=");
    out += LOCI_SHOW_octets_experimenter_data(writer, cookie, octets);
    out += writer(cookie, " ");

    return out;
}

int
of_table_feature_prop_header_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_table_feature_prop_header_t *obj)
{
    int out = 0;

    return out;
}

int
of_table_feature_prop_instructions_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_table_feature_prop_instructions_t *obj)
{
    int out = 0;

    of_list_instruction_t list;
    of_instruction_t elt;
    int rv;

    out += writer(cookie, "of_instruction_t={ ");
    of_table_feature_prop_instructions_instruction_ids_bind(obj, &list);
    OF_LIST_INSTRUCTION_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_table_feature_prop_instructions_miss_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_table_feature_prop_instructions_miss_t *obj)
{
    int out = 0;

    of_list_instruction_t list;
    of_instruction_t elt;
    int rv;

    out += writer(cookie, "of_instruction_t={ ");
    of_table_feature_prop_instructions_miss_instruction_ids_bind(obj, &list);
    OF_LIST_INSTRUCTION_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_table_feature_prop_match_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_table_feature_prop_match_t *obj)
{
    int out = 0;

    of_list_uint32_t list;
    of_uint32_t elt;
    int rv;

    out += writer(cookie, "of_uint32_t={ ");
    of_table_feature_prop_match_oxm_ids_bind(obj, &list);
    OF_LIST_UINT32_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_table_feature_prop_next_tables_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_table_feature_prop_next_tables_t *obj)
{
    int out = 0;

    of_list_uint8_t list;
    of_uint8_t elt;
    int rv;

    out += writer(cookie, "of_uint8_t={ ");
    of_table_feature_prop_next_tables_next_table_ids_bind(obj, &list);
    OF_LIST_UINT8_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_table_feature_prop_next_tables_miss_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_table_feature_prop_next_tables_miss_t *obj)
{
    int out = 0;

    of_list_uint8_t list;
    of_uint8_t elt;
    int rv;

    out += writer(cookie, "of_uint8_t={ ");
    of_table_feature_prop_next_tables_miss_next_table_ids_bind(obj, &list);
    OF_LIST_UINT8_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_table_feature_prop_wildcards_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_table_feature_prop_wildcards_t *obj)
{
    int out = 0;

    of_list_uint32_t list;
    of_uint32_t elt;
    int rv;

    out += writer(cookie, "of_uint32_t={ ");
    of_table_feature_prop_wildcards_oxm_ids_bind(obj, &list);
    OF_LIST_UINT32_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_table_feature_prop_write_actions_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_table_feature_prop_write_actions_t *obj)
{
    int out = 0;

    of_list_action_id_t list;
    of_action_id_t elt;
    int rv;

    out += writer(cookie, "of_action_id_t={ ");
    of_table_feature_prop_write_actions_action_ids_bind(obj, &list);
    OF_LIST_ACTION_ID_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_table_feature_prop_write_actions_miss_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_table_feature_prop_write_actions_miss_t *obj)
{
    int out = 0;

    of_list_action_id_t list;
    of_action_id_t elt;
    int rv;

    out += writer(cookie, "of_action_id_t={ ");
    of_table_feature_prop_write_actions_miss_action_ids_bind(obj, &list);
    OF_LIST_ACTION_ID_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_table_feature_prop_write_setfield_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_table_feature_prop_write_setfield_t *obj)
{
    int out = 0;

    of_list_uint32_t list;
    of_uint32_t elt;
    int rv;

    out += writer(cookie, "of_uint32_t={ ");
    of_table_feature_prop_write_setfield_oxm_ids_bind(obj, &list);
    OF_LIST_UINT32_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_table_feature_prop_write_setfield_miss_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_table_feature_prop_write_setfield_miss_t *obj)
{
    int out = 0;

    of_list_uint32_t list;
    of_uint32_t elt;
    int rv;

    out += writer(cookie, "of_uint32_t={ ");
    of_table_feature_prop_write_setfield_miss_oxm_ids_bind(obj, &list);
    OF_LIST_UINT32_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_table_features_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_table_features_t *obj)
{
    int out = 0;
    uint8_t val8;
    of_table_name_t table_name;
    uint64_t val64;
    uint32_t val32;

    of_list_table_feature_prop_t list;
    of_table_feature_prop_t elt;
    int rv;

    of_table_features_table_id_get(obj, &val8);
    out += writer(cookie, "table_id=");
    out += LOCI_SHOW_u8_table_id(writer, cookie, val8);
    out += writer(cookie, " ");

    of_table_features_name_get(obj, &table_name);
    out += writer(cookie, "name=");
    out += LOCI_SHOW_tab_name_name(writer, cookie, table_name);
    out += writer(cookie, " ");

    of_table_features_metadata_match_get(obj, &val64);
    out += writer(cookie, "metadata_match=");
    out += LOCI_SHOW_u64_metadata_match(writer, cookie, val64);
    out += writer(cookie, " ");

    of_table_features_metadata_write_get(obj, &val64);
    out += writer(cookie, "metadata_write=");
    out += LOCI_SHOW_u64_metadata_write(writer, cookie, val64);
    out += writer(cookie, " ");

    of_table_features_config_get(obj, &val32);
    out += writer(cookie, "config=");
    out += LOCI_SHOW_u32_config(writer, cookie, val32);
    out += writer(cookie, " ");

    of_table_features_max_entries_get(obj, &val32);
    out += writer(cookie, "max_entries=");
    out += LOCI_SHOW_u32_max_entries(writer, cookie, val32);
    out += writer(cookie, " ");

    out += writer(cookie, "of_table_feature_prop_t={ ");
    of_table_features_properties_bind(obj, &list);
    OF_LIST_TABLE_FEATURE_PROP_ITER(&list, &elt, rv) {
        of_object_show(writer, cookie, (of_object_t *)&elt);
    }
    out += writer(cookie, "} ");

    return out;
}

int
of_table_stats_entry_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_table_stats_entry_t *obj)
{
    int out = 0;
    uint8_t val8;
    uint32_t val32;
    uint64_t val64;

    of_table_stats_entry_table_id_get(obj, &val8);
    out += writer(cookie, "table_id=");
    out += LOCI_SHOW_u8_table_id(writer, cookie, val8);
    out += writer(cookie, " ");

    of_table_stats_entry_active_count_get(obj, &val32);
    out += writer(cookie, "active_count=");
    out += LOCI_SHOW_u32_active_count(writer, cookie, val32);
    out += writer(cookie, " ");

    of_table_stats_entry_lookup_count_get(obj, &val64);
    out += writer(cookie, "lookup_count=");
    out += LOCI_SHOW_u64_lookup_count(writer, cookie, val64);
    out += writer(cookie, " ");

    of_table_stats_entry_matched_count_get(obj, &val64);
    out += writer(cookie, "matched_count=");
    out += LOCI_SHOW_u64_matched_count(writer, cookie, val64);
    out += writer(cookie, " ");

    return out;
}

int
of_uint32_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_uint32_t *obj)
{
    int out = 0;
    uint32_t val32;

    of_uint32_value_get(obj, &val32);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u32_value(writer, cookie, val32);
    out += writer(cookie, " ");

    return out;
}

int
of_uint8_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_uint8_t *obj)
{
    int out = 0;
    uint8_t val8;

    of_uint8_value_get(obj, &val8);
    out += writer(cookie, "value=");
    out += LOCI_SHOW_u8_value(writer, cookie, val8);
    out += writer(cookie, " ");

    return out;
}

int
of_list_action_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_list_action_t *obj)
{
    int out = 0;

    return out;
}

int
of_list_action_id_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_list_action_id_t *obj)
{
    int out = 0;

    return out;
}

int
of_list_bsn_interface_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_list_bsn_interface_t *obj)
{
    int out = 0;

    return out;
}

int
of_list_bsn_lacp_stats_entry_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_list_bsn_lacp_stats_entry_t *obj)
{
    int out = 0;

    return out;
}

int
of_list_bucket_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_list_bucket_t *obj)
{
    int out = 0;

    return out;
}

int
of_list_bucket_counter_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_list_bucket_counter_t *obj)
{
    int out = 0;

    return out;
}

int
of_list_flow_stats_entry_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_list_flow_stats_entry_t *obj)
{
    int out = 0;

    return out;
}

int
of_list_group_desc_stats_entry_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_list_group_desc_stats_entry_t *obj)
{
    int out = 0;

    return out;
}

int
of_list_group_stats_entry_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_list_group_stats_entry_t *obj)
{
    int out = 0;

    return out;
}

int
of_list_hello_elem_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_list_hello_elem_t *obj)
{
    int out = 0;

    return out;
}

int
of_list_instruction_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_list_instruction_t *obj)
{
    int out = 0;

    return out;
}

int
of_list_meter_band_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_list_meter_band_t *obj)
{
    int out = 0;

    return out;
}

int
of_list_meter_band_stats_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_list_meter_band_stats_t *obj)
{
    int out = 0;

    return out;
}

int
of_list_meter_stats_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_list_meter_stats_t *obj)
{
    int out = 0;

    return out;
}

int
of_list_oxm_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_list_oxm_t *obj)
{
    int out = 0;

    return out;
}

int
of_list_packet_queue_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_list_packet_queue_t *obj)
{
    int out = 0;

    return out;
}

int
of_list_port_desc_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_list_port_desc_t *obj)
{
    int out = 0;

    return out;
}

int
of_list_port_stats_entry_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_list_port_stats_entry_t *obj)
{
    int out = 0;

    return out;
}

int
of_list_queue_prop_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_list_queue_prop_t *obj)
{
    int out = 0;

    return out;
}

int
of_list_queue_stats_entry_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_list_queue_stats_entry_t *obj)
{
    int out = 0;

    return out;
}

int
of_list_table_feature_prop_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_list_table_feature_prop_t *obj)
{
    int out = 0;

    return out;
}

int
of_list_table_features_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_list_table_features_t *obj)
{
    int out = 0;

    return out;
}

int
of_list_table_stats_entry_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_list_table_stats_entry_t *obj)
{
    int out = 0;

    return out;
}

int
of_list_uint32_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_list_uint32_t *obj)
{
    int out = 0;

    return out;
}

int
of_list_uint8_OF_VERSION_1_3_show(loci_writer_f writer, void* cookie, of_list_uint8_t *obj)
{
    int out = 0;

    return out;
}

/**
 * Log a match entry
 */
int
loci_show_match(loci_writer_f writer, void* cookie, of_match_t *match)
{
    int out = 0;

    if (OF_MATCH_MASK_IPV6_FLABEL_ACTIVE_TEST(match)) {
        out += writer(cookie, "ipv6_flabel active=");
        out += LOCI_SHOW_u32_ipv6_flabel(writer, cookie, match->fields.ipv6_flabel);
        out += writer(cookie, "/");
        out += LOCI_SHOW_u32_ipv6_flabel(writer, cookie, match->masks.ipv6_flabel);
        out += writer(cookie, " ");
    }

    if (OF_MATCH_MASK_BSN_LAG_ID_ACTIVE_TEST(match)) {
        out += writer(cookie, "bsn_lag_id active=");
        out += LOCI_SHOW_u32_bsn_lag_id(writer, cookie, match->fields.bsn_lag_id);
        out += writer(cookie, "/");
        out += LOCI_SHOW_u32_bsn_lag_id(writer, cookie, match->masks.bsn_lag_id);
        out += writer(cookie, " ");
    }

    if (OF_MATCH_MASK_VLAN_PCP_ACTIVE_TEST(match)) {
        out += writer(cookie, "vlan_pcp active=");
        out += LOCI_SHOW_u8_vlan_pcp(writer, cookie, match->fields.vlan_pcp);
        out += writer(cookie, "/");
        out += LOCI_SHOW_u8_vlan_pcp(writer, cookie, match->masks.vlan_pcp);
        out += writer(cookie, " ");
    }

    if (OF_MATCH_MASK_IPV4_SRC_ACTIVE_TEST(match)) {
        out += writer(cookie, "ipv4_src active=");
        out += LOCI_SHOW_ipv4_ipv4_src(writer, cookie, match->fields.ipv4_src);
        out += writer(cookie, "/");
        out += LOCI_SHOW_ipv4_ipv4_src(writer, cookie, match->masks.ipv4_src);
        out += writer(cookie, " ");
    }

    if (OF_MATCH_MASK_IPV6_DST_ACTIVE_TEST(match)) {
        out += writer(cookie, "ipv6_dst active=");
        out += LOCI_SHOW_ipv6_ipv6_dst(writer, cookie, match->fields.ipv6_dst);
        out += writer(cookie, "/");
        out += LOCI_SHOW_ipv6_ipv6_dst(writer, cookie, match->masks.ipv6_dst);
        out += writer(cookie, " ");
    }

    if (OF_MATCH_MASK_ARP_TPA_ACTIVE_TEST(match)) {
        out += writer(cookie, "arp_tpa active=");
        out += LOCI_SHOW_u32_arp_tpa(writer, cookie, match->fields.arp_tpa);
        out += writer(cookie, "/");
        out += LOCI_SHOW_u32_arp_tpa(writer, cookie, match->masks.arp_tpa);
        out += writer(cookie, " ");
    }

    if (OF_MATCH_MASK_ICMPV6_TYPE_ACTIVE_TEST(match)) {
        out += writer(cookie, "icmpv6_type active=");
        out += LOCI_SHOW_u8_icmpv6_type(writer, cookie, match->fields.icmpv6_type);
        out += writer(cookie, "/");
        out += LOCI_SHOW_u8_icmpv6_type(writer, cookie, match->masks.icmpv6_type);
        out += writer(cookie, " ");
    }

    if (OF_MATCH_MASK_BSN_IN_PORTS_128_ACTIVE_TEST(match)) {
        out += writer(cookie, "bsn_in_ports_128 active=");
        out += LOCI_SHOW_bitmap_128_bsn_in_ports_128(writer, cookie, match->fields.bsn_in_ports_128);
        out += writer(cookie, "/");
        out += LOCI_SHOW_bitmap_128_bsn_in_ports_128(writer, cookie, match->masks.bsn_in_ports_128);
        out += writer(cookie, " ");
    }

    if (OF_MATCH_MASK_ARP_SHA_ACTIVE_TEST(match)) {
        out += writer(cookie, "arp_sha active=");
        out += LOCI_SHOW_mac_arp_sha(writer, cookie, match->fields.arp_sha);
        out += writer(cookie, "/");
        out += LOCI_SHOW_mac_arp_sha(writer, cookie, match->masks.arp_sha);
        out += writer(cookie, " ");
    }

    if (OF_MATCH_MASK_IPV6_SRC_ACTIVE_TEST(match)) {
        out += writer(cookie, "ipv6_src active=");
        out += LOCI_SHOW_ipv6_ipv6_src(writer, cookie, match->fields.ipv6_src);
        out += writer(cookie, "/");
        out += LOCI_SHOW_ipv6_ipv6_src(writer, cookie, match->masks.ipv6_src);
        out += writer(cookie, " ");
    }

    if (OF_MATCH_MASK_SCTP_SRC_ACTIVE_TEST(match)) {
        out += writer(cookie, "sctp_src active=");
        out += LOCI_SHOW_u16_sctp_src(writer, cookie, match->fields.sctp_src);
        out += writer(cookie, "/");
        out += LOCI_SHOW_u16_sctp_src(writer, cookie, match->masks.sctp_src);
        out += writer(cookie, " ");
    }

    if (OF_MATCH_MASK_ICMPV6_CODE_ACTIVE_TEST(match)) {
        out += writer(cookie, "icmpv6_code active=");
        out += LOCI_SHOW_u8_icmpv6_code(writer, cookie, match->fields.icmpv6_code);
        out += writer(cookie, "/");
        out += LOCI_SHOW_u8_icmpv6_code(writer, cookie, match->masks.icmpv6_code);
        out += writer(cookie, " ");
    }

    if (OF_MATCH_MASK_ETH_DST_ACTIVE_TEST(match)) {
        out += writer(cookie, "eth_dst active=");
        out += LOCI_SHOW_mac_eth_dst(writer, cookie, match->fields.eth_dst);
        out += writer(cookie, "/");
        out += LOCI_SHOW_mac_eth_dst(writer, cookie, match->masks.eth_dst);
        out += writer(cookie, " ");
    }

    if (OF_MATCH_MASK_IPV6_ND_SLL_ACTIVE_TEST(match)) {
        out += writer(cookie, "ipv6_nd_sll active=");
        out += LOCI_SHOW_mac_ipv6_nd_sll(writer, cookie, match->fields.ipv6_nd_sll);
        out += writer(cookie, "/");
        out += LOCI_SHOW_mac_ipv6_nd_sll(writer, cookie, match->masks.ipv6_nd_sll);
        out += writer(cookie, " ");
    }

    if (OF_MATCH_MASK_MPLS_TC_ACTIVE_TEST(match)) {
        out += writer(cookie, "mpls_tc active=");
        out += LOCI_SHOW_u8_mpls_tc(writer, cookie, match->fields.mpls_tc);
        out += writer(cookie, "/");
        out += LOCI_SHOW_u8_mpls_tc(writer, cookie, match->masks.mpls_tc);
        out += writer(cookie, " ");
    }

    if (OF_MATCH_MASK_ARP_OP_ACTIVE_TEST(match)) {
        out += writer(cookie, "arp_op active=");
        out += LOCI_SHOW_u16_arp_op(writer, cookie, match->fields.arp_op);
        out += writer(cookie, "/");
        out += LOCI_SHOW_u16_arp_op(writer, cookie, match->masks.arp_op);
        out += writer(cookie, " ");
    }

    if (OF_MATCH_MASK_ETH_TYPE_ACTIVE_TEST(match)) {
        out += writer(cookie, "eth_type active=");
        out += LOCI_SHOW_u16_eth_type(writer, cookie, match->fields.eth_type);
        out += writer(cookie, "/");
        out += LOCI_SHOW_u16_eth_type(writer, cookie, match->masks.eth_type);
        out += writer(cookie, " ");
    }

    if (OF_MATCH_MASK_IPV6_ND_TARGET_ACTIVE_TEST(match)) {
        out += writer(cookie, "ipv6_nd_target active=");
        out += LOCI_SHOW_ipv6_ipv6_nd_target(writer, cookie, match->fields.ipv6_nd_target);
        out += writer(cookie, "/");
        out += LOCI_SHOW_ipv6_ipv6_nd_target(writer, cookie, match->masks.ipv6_nd_target);
        out += writer(cookie, " ");
    }

    if (OF_MATCH_MASK_VLAN_VID_ACTIVE_TEST(match)) {
        out += writer(cookie, "vlan_vid active=");
        out += LOCI_SHOW_u16_vlan_vid(writer, cookie, match->fields.vlan_vid);
        out += writer(cookie, "/");
        out += LOCI_SHOW_u16_vlan_vid(writer, cookie, match->masks.vlan_vid);
        out += writer(cookie, " ");
    }

    if (OF_MATCH_MASK_ARP_THA_ACTIVE_TEST(match)) {
        out += writer(cookie, "arp_tha active=");
        out += LOCI_SHOW_mac_arp_tha(writer, cookie, match->fields.arp_tha);
        out += writer(cookie, "/");
        out += LOCI_SHOW_mac_arp_tha(writer, cookie, match->masks.arp_tha);
        out += writer(cookie, " ");
    }

    if (OF_MATCH_MASK_IN_PORT_ACTIVE_TEST(match)) {
        out += writer(cookie, "in_port active=");
        out += LOCI_SHOW_port_no_in_port(writer, cookie, match->fields.in_port);
        out += writer(cookie, "/");
        out += LOCI_SHOW_port_no_in_port(writer, cookie, match->masks.in_port);
        out += writer(cookie, " ");
    }

    if (OF_MATCH_MASK_METADATA_ACTIVE_TEST(match)) {
        out += writer(cookie, "metadata active=");
        out += LOCI_SHOW_u64_metadata(writer, cookie, match->fields.metadata);
        out += writer(cookie, "/");
        out += LOCI_SHOW_u64_metadata(writer, cookie, match->masks.metadata);
        out += writer(cookie, " ");
    }

    if (OF_MATCH_MASK_BSN_L3_SRC_CLASS_ID_ACTIVE_TEST(match)) {
        out += writer(cookie, "bsn_l3_src_class_id active=");
        out += LOCI_SHOW_u32_bsn_l3_src_class_id(writer, cookie, match->fields.bsn_l3_src_class_id);
        out += writer(cookie, "/");
        out += LOCI_SHOW_u32_bsn_l3_src_class_id(writer, cookie, match->masks.bsn_l3_src_class_id);
        out += writer(cookie, " ");
    }

    if (OF_MATCH_MASK_SCTP_DST_ACTIVE_TEST(match)) {
        out += writer(cookie, "sctp_dst active=");
        out += LOCI_SHOW_u16_sctp_dst(writer, cookie, match->fields.sctp_dst);
        out += writer(cookie, "/");
        out += LOCI_SHOW_u16_sctp_dst(writer, cookie, match->masks.sctp_dst);
        out += writer(cookie, " ");
    }

    if (OF_MATCH_MASK_ICMPV4_CODE_ACTIVE_TEST(match)) {
        out += writer(cookie, "icmpv4_code active=");
        out += LOCI_SHOW_u8_icmpv4_code(writer, cookie, match->fields.icmpv4_code);
        out += writer(cookie, "/");
        out += LOCI_SHOW_u8_icmpv4_code(writer, cookie, match->masks.icmpv4_code);
        out += writer(cookie, " ");
    }

    if (OF_MATCH_MASK_TCP_SRC_ACTIVE_TEST(match)) {
        out += writer(cookie, "tcp_src active=");
        out += LOCI_SHOW_u16_tcp_src(writer, cookie, match->fields.tcp_src);
        out += writer(cookie, "/");
        out += LOCI_SHOW_u16_tcp_src(writer, cookie, match->masks.tcp_src);
        out += writer(cookie, " ");
    }

    if (OF_MATCH_MASK_BSN_VRF_ACTIVE_TEST(match)) {
        out += writer(cookie, "bsn_vrf active=");
        out += LOCI_SHOW_u32_bsn_vrf(writer, cookie, match->fields.bsn_vrf);
        out += writer(cookie, "/");
        out += LOCI_SHOW_u32_bsn_vrf(writer, cookie, match->masks.bsn_vrf);
        out += writer(cookie, " ");
    }

    if (OF_MATCH_MASK_IP_ECN_ACTIVE_TEST(match)) {
        out += writer(cookie, "ip_ecn active=");
        out += LOCI_SHOW_u8_ip_ecn(writer, cookie, match->fields.ip_ecn);
        out += writer(cookie, "/");
        out += LOCI_SHOW_u8_ip_ecn(writer, cookie, match->masks.ip_ecn);
        out += writer(cookie, " ");
    }

    if (OF_MATCH_MASK_BSN_GLOBAL_VRF_ALLOWED_ACTIVE_TEST(match)) {
        out += writer(cookie, "bsn_global_vrf_allowed active=");
        out += LOCI_SHOW_u8_bsn_global_vrf_allowed(writer, cookie, match->fields.bsn_global_vrf_allowed);
        out += writer(cookie, "/");
        out += LOCI_SHOW_u8_bsn_global_vrf_allowed(writer, cookie, match->masks.bsn_global_vrf_allowed);
        out += writer(cookie, " ");
    }

    if (OF_MATCH_MASK_UDP_DST_ACTIVE_TEST(match)) {
        out += writer(cookie, "udp_dst active=");
        out += LOCI_SHOW_u16_udp_dst(writer, cookie, match->fields.udp_dst);
        out += writer(cookie, "/");
        out += LOCI_SHOW_u16_udp_dst(writer, cookie, match->masks.udp_dst);
        out += writer(cookie, " ");
    }

    if (OF_MATCH_MASK_ARP_SPA_ACTIVE_TEST(match)) {
        out += writer(cookie, "arp_spa active=");
        out += LOCI_SHOW_u32_arp_spa(writer, cookie, match->fields.arp_spa);
        out += writer(cookie, "/");
        out += LOCI_SHOW_u32_arp_spa(writer, cookie, match->masks.arp_spa);
        out += writer(cookie, " ");
    }

    if (OF_MATCH_MASK_IN_PHY_PORT_ACTIVE_TEST(match)) {
        out += writer(cookie, "in_phy_port active=");
        out += LOCI_SHOW_port_no_in_phy_port(writer, cookie, match->fields.in_phy_port);
        out += writer(cookie, "/");
        out += LOCI_SHOW_port_no_in_phy_port(writer, cookie, match->masks.in_phy_port);
        out += writer(cookie, " ");
    }

    if (OF_MATCH_MASK_IPV4_DST_ACTIVE_TEST(match)) {
        out += writer(cookie, "ipv4_dst active=");
        out += LOCI_SHOW_ipv4_ipv4_dst(writer, cookie, match->fields.ipv4_dst);
        out += writer(cookie, "/");
        out += LOCI_SHOW_ipv4_ipv4_dst(writer, cookie, match->masks.ipv4_dst);
        out += writer(cookie, " ");
    }

    if (OF_MATCH_MASK_ETH_SRC_ACTIVE_TEST(match)) {
        out += writer(cookie, "eth_src active=");
        out += LOCI_SHOW_mac_eth_src(writer, cookie, match->fields.eth_src);
        out += writer(cookie, "/");
        out += LOCI_SHOW_mac_eth_src(writer, cookie, match->masks.eth_src);
        out += writer(cookie, " ");
    }

    if (OF_MATCH_MASK_UDP_SRC_ACTIVE_TEST(match)) {
        out += writer(cookie, "udp_src active=");
        out += LOCI_SHOW_u16_udp_src(writer, cookie, match->fields.udp_src);
        out += writer(cookie, "/");
        out += LOCI_SHOW_u16_udp_src(writer, cookie, match->masks.udp_src);
        out += writer(cookie, " ");
    }

    if (OF_MATCH_MASK_BSN_L3_DST_CLASS_ID_ACTIVE_TEST(match)) {
        out += writer(cookie, "bsn_l3_dst_class_id active=");
        out += LOCI_SHOW_u32_bsn_l3_dst_class_id(writer, cookie, match->fields.bsn_l3_dst_class_id);
        out += writer(cookie, "/");
        out += LOCI_SHOW_u32_bsn_l3_dst_class_id(writer, cookie, match->masks.bsn_l3_dst_class_id);
        out += writer(cookie, " ");
    }

    if (OF_MATCH_MASK_IPV6_ND_TLL_ACTIVE_TEST(match)) {
        out += writer(cookie, "ipv6_nd_tll active=");
        out += LOCI_SHOW_mac_ipv6_nd_tll(writer, cookie, match->fields.ipv6_nd_tll);
        out += writer(cookie, "/");
        out += LOCI_SHOW_mac_ipv6_nd_tll(writer, cookie, match->masks.ipv6_nd_tll);
        out += writer(cookie, " ");
    }

    if (OF_MATCH_MASK_ICMPV4_TYPE_ACTIVE_TEST(match)) {
        out += writer(cookie, "icmpv4_type active=");
        out += LOCI_SHOW_u8_icmpv4_type(writer, cookie, match->fields.icmpv4_type);
        out += writer(cookie, "/");
        out += LOCI_SHOW_u8_icmpv4_type(writer, cookie, match->masks.icmpv4_type);
        out += writer(cookie, " ");
    }

    if (OF_MATCH_MASK_MPLS_LABEL_ACTIVE_TEST(match)) {
        out += writer(cookie, "mpls_label active=");
        out += LOCI_SHOW_u32_mpls_label(writer, cookie, match->fields.mpls_label);
        out += writer(cookie, "/");
        out += LOCI_SHOW_u32_mpls_label(writer, cookie, match->masks.mpls_label);
        out += writer(cookie, " ");
    }

    if (OF_MATCH_MASK_TCP_DST_ACTIVE_TEST(match)) {
        out += writer(cookie, "tcp_dst active=");
        out += LOCI_SHOW_u16_tcp_dst(writer, cookie, match->fields.tcp_dst);
        out += writer(cookie, "/");
        out += LOCI_SHOW_u16_tcp_dst(writer, cookie, match->masks.tcp_dst);
        out += writer(cookie, " ");
    }

    if (OF_MATCH_MASK_IP_PROTO_ACTIVE_TEST(match)) {
        out += writer(cookie, "ip_proto active=");
        out += LOCI_SHOW_u8_ip_proto(writer, cookie, match->fields.ip_proto);
        out += writer(cookie, "/");
        out += LOCI_SHOW_u8_ip_proto(writer, cookie, match->masks.ip_proto);
        out += writer(cookie, " ");
    }

    if (OF_MATCH_MASK_BSN_L3_INTERFACE_CLASS_ID_ACTIVE_TEST(match)) {
        out += writer(cookie, "bsn_l3_interface_class_id active=");
        out += LOCI_SHOW_u32_bsn_l3_interface_class_id(writer, cookie, match->fields.bsn_l3_interface_class_id);
        out += writer(cookie, "/");
        out += LOCI_SHOW_u32_bsn_l3_interface_class_id(writer, cookie, match->masks.bsn_l3_interface_class_id);
        out += writer(cookie, " ");
    }

    if (OF_MATCH_MASK_IP_DSCP_ACTIVE_TEST(match)) {
        out += writer(cookie, "ip_dscp active=");
        out += LOCI_SHOW_u8_ip_dscp(writer, cookie, match->fields.ip_dscp);
        out += writer(cookie, "/");
        out += LOCI_SHOW_u8_ip_dscp(writer, cookie, match->masks.ip_dscp);
        out += writer(cookie, " ");
    }

    return out;
}

static const loci_obj_show_f show_funs_v1[OF_OBJECT_COUNT] = {
    unknown_show, /* of_object, not a valid specific type */
    of_aggregate_stats_reply_OF_VERSION_1_0_show,
    of_aggregate_stats_request_OF_VERSION_1_0_show,
    unknown_show,
    unknown_show,
    unknown_show,
    of_bad_action_error_msg_OF_VERSION_1_0_show,
    unknown_show,
    unknown_show,
    of_bad_request_error_msg_OF_VERSION_1_0_show,
    of_barrier_reply_OF_VERSION_1_0_show,
    of_barrier_request_OF_VERSION_1_0_show,
    of_bsn_bw_clear_data_reply_OF_VERSION_1_0_show,
    of_bsn_bw_clear_data_request_OF_VERSION_1_0_show,
    of_bsn_bw_enable_get_reply_OF_VERSION_1_0_show,
    of_bsn_bw_enable_get_request_OF_VERSION_1_0_show,
    of_bsn_bw_enable_set_reply_OF_VERSION_1_0_show,
    of_bsn_bw_enable_set_request_OF_VERSION_1_0_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    of_bsn_get_interfaces_reply_OF_VERSION_1_0_show,
    of_bsn_get_interfaces_request_OF_VERSION_1_0_show,
    of_bsn_get_ip_mask_reply_OF_VERSION_1_0_show,
    of_bsn_get_ip_mask_request_OF_VERSION_1_0_show,
    of_bsn_get_l2_table_reply_OF_VERSION_1_0_show,
    of_bsn_get_l2_table_request_OF_VERSION_1_0_show,
    of_bsn_get_mirroring_reply_OF_VERSION_1_0_show,
    of_bsn_get_mirroring_request_OF_VERSION_1_0_show,
    of_bsn_header_OF_VERSION_1_0_show,
    of_bsn_hybrid_get_reply_OF_VERSION_1_0_show,
    of_bsn_hybrid_get_request_OF_VERSION_1_0_show,
    unknown_show,
    unknown_show,
    unknown_show,
    of_bsn_pdu_rx_reply_OF_VERSION_1_0_show,
    of_bsn_pdu_rx_request_OF_VERSION_1_0_show,
    of_bsn_pdu_rx_timeout_OF_VERSION_1_0_show,
    of_bsn_pdu_tx_reply_OF_VERSION_1_0_show,
    of_bsn_pdu_tx_request_OF_VERSION_1_0_show,
    of_bsn_set_ip_mask_OF_VERSION_1_0_show,
    of_bsn_set_l2_table_reply_OF_VERSION_1_0_show,
    of_bsn_set_l2_table_request_OF_VERSION_1_0_show,
    unknown_show,
    unknown_show,
    of_bsn_set_mirroring_OF_VERSION_1_0_show,
    of_bsn_set_pktin_suppression_reply_OF_VERSION_1_0_show,
    of_bsn_set_pktin_suppression_request_OF_VERSION_1_0_show,
    of_bsn_shell_command_OF_VERSION_1_0_show,
    of_bsn_shell_output_OF_VERSION_1_0_show,
    of_bsn_shell_status_OF_VERSION_1_0_show,
    of_bsn_stats_reply_OF_VERSION_1_0_show,
    of_bsn_stats_request_OF_VERSION_1_0_show,
    unknown_show,
    unknown_show,
    of_bsn_virtual_port_create_reply_OF_VERSION_1_0_show,
    of_bsn_virtual_port_create_request_OF_VERSION_1_0_show,
    of_bsn_virtual_port_remove_reply_OF_VERSION_1_0_show,
    of_bsn_virtual_port_remove_request_OF_VERSION_1_0_show,
    of_desc_stats_reply_OF_VERSION_1_0_show,
    of_desc_stats_request_OF_VERSION_1_0_show,
    of_echo_reply_OF_VERSION_1_0_show,
    of_echo_request_OF_VERSION_1_0_show,
    of_error_msg_OF_VERSION_1_0_show,
    of_experimenter_OF_VERSION_1_0_show,
    unknown_show,
    of_experimenter_stats_reply_OF_VERSION_1_0_show,
    of_experimenter_stats_request_OF_VERSION_1_0_show,
    of_features_reply_OF_VERSION_1_0_show,
    of_features_request_OF_VERSION_1_0_show,
    of_flow_add_OF_VERSION_1_0_show,
    of_flow_delete_OF_VERSION_1_0_show,
    of_flow_delete_strict_OF_VERSION_1_0_show,
    of_flow_mod_OF_VERSION_1_0_show,
    of_flow_mod_failed_error_msg_OF_VERSION_1_0_show,
    of_flow_modify_OF_VERSION_1_0_show,
    of_flow_modify_strict_OF_VERSION_1_0_show,
    of_flow_removed_OF_VERSION_1_0_show,
    of_flow_stats_reply_OF_VERSION_1_0_show,
    of_flow_stats_request_OF_VERSION_1_0_show,
    of_get_config_reply_OF_VERSION_1_0_show,
    of_get_config_request_OF_VERSION_1_0_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    of_hello_OF_VERSION_1_0_show,
    of_hello_failed_error_msg_OF_VERSION_1_0_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    of_nicira_controller_role_reply_OF_VERSION_1_0_show,
    of_nicira_controller_role_request_OF_VERSION_1_0_show,
    of_nicira_header_OF_VERSION_1_0_show,
    of_packet_in_OF_VERSION_1_0_show,
    of_packet_out_OF_VERSION_1_0_show,
    unknown_show,
    unknown_show,
    of_port_mod_OF_VERSION_1_0_show,
    of_port_mod_failed_error_msg_OF_VERSION_1_0_show,
    of_port_stats_reply_OF_VERSION_1_0_show,
    of_port_stats_request_OF_VERSION_1_0_show,
    of_port_status_OF_VERSION_1_0_show,
    of_queue_get_config_reply_OF_VERSION_1_0_show,
    of_queue_get_config_request_OF_VERSION_1_0_show,
    of_queue_op_failed_error_msg_OF_VERSION_1_0_show,
    of_queue_stats_reply_OF_VERSION_1_0_show,
    of_queue_stats_request_OF_VERSION_1_0_show,
    unknown_show,
    unknown_show,
    unknown_show,
    of_set_config_OF_VERSION_1_0_show,
    of_stats_reply_OF_VERSION_1_0_show,
    of_stats_request_OF_VERSION_1_0_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    of_table_mod_OF_VERSION_1_0_show,
    unknown_show,
    of_table_stats_reply_OF_VERSION_1_0_show,
    of_table_stats_request_OF_VERSION_1_0_show,
    unknown_show,
    of_action_bsn_OF_VERSION_1_0_show,
    of_action_bsn_mirror_OF_VERSION_1_0_show,
    of_action_bsn_set_tunnel_dst_OF_VERSION_1_0_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    of_action_enqueue_OF_VERSION_1_0_show,
    of_action_experimenter_OF_VERSION_1_0_show,
    unknown_show,
    of_action_header_OF_VERSION_1_0_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    of_action_nicira_OF_VERSION_1_0_show,
    of_action_nicira_dec_ttl_OF_VERSION_1_0_show,
    of_action_output_OF_VERSION_1_0_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    of_action_set_dl_dst_OF_VERSION_1_0_show,
    of_action_set_dl_src_OF_VERSION_1_0_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    of_action_set_nw_dst_OF_VERSION_1_0_show,
    unknown_show,
    of_action_set_nw_src_OF_VERSION_1_0_show,
    of_action_set_nw_tos_OF_VERSION_1_0_show,
    unknown_show,
    unknown_show,
    of_action_set_tp_dst_OF_VERSION_1_0_show,
    of_action_set_tp_src_OF_VERSION_1_0_show,
    of_action_set_vlan_pcp_OF_VERSION_1_0_show,
    of_action_set_vlan_vid_OF_VERSION_1_0_show,
    of_action_strip_vlan_OF_VERSION_1_0_show,
    of_bsn_interface_OF_VERSION_1_0_show,
    unknown_show,
    unknown_show,
    of_bsn_vport_header_OF_VERSION_1_0_show,
    of_bsn_vport_q_in_q_OF_VERSION_1_0_show,
    unknown_show,
    unknown_show,
    unknown_show,
    of_flow_stats_entry_OF_VERSION_1_0_show,
    unknown_show,
    unknown_show,
    of_header_OF_VERSION_1_0_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    of_match_v1_OF_VERSION_1_0_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    of_packet_queue_OF_VERSION_1_0_show,
    of_port_desc_OF_VERSION_1_0_show,
    of_port_stats_entry_OF_VERSION_1_0_show,
    unknown_show,
    unknown_show,
    of_queue_prop_header_OF_VERSION_1_0_show,
    unknown_show,
    of_queue_prop_min_rate_OF_VERSION_1_0_show,
    of_queue_stats_entry_OF_VERSION_1_0_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    of_table_stats_entry_OF_VERSION_1_0_show,
    unknown_show,
    unknown_show,
    of_list_action_OF_VERSION_1_0_show,
    unknown_show,
    of_list_bsn_interface_OF_VERSION_1_0_show,
    unknown_show,
    unknown_show,
    unknown_show,
    of_list_flow_stats_entry_OF_VERSION_1_0_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    of_list_packet_queue_OF_VERSION_1_0_show,
    of_list_port_desc_OF_VERSION_1_0_show,
    of_list_port_stats_entry_OF_VERSION_1_0_show,
    of_list_queue_prop_OF_VERSION_1_0_show,
    of_list_queue_stats_entry_OF_VERSION_1_0_show,
    unknown_show,
    unknown_show,
    of_list_table_stats_entry_OF_VERSION_1_0_show,
    unknown_show,
    unknown_show
};


static const loci_obj_show_f show_funs_v2[OF_OBJECT_COUNT] = {
    unknown_show, /* of_object, not a valid specific type */
    of_aggregate_stats_reply_OF_VERSION_1_1_show,
    of_aggregate_stats_request_OF_VERSION_1_1_show,
    unknown_show,
    unknown_show,
    unknown_show,
    of_bad_action_error_msg_OF_VERSION_1_1_show,
    of_bad_instruction_error_msg_OF_VERSION_1_1_show,
    of_bad_match_error_msg_OF_VERSION_1_1_show,
    of_bad_request_error_msg_OF_VERSION_1_1_show,
    of_barrier_reply_OF_VERSION_1_1_show,
    of_barrier_request_OF_VERSION_1_1_show,
    of_bsn_bw_clear_data_reply_OF_VERSION_1_1_show,
    of_bsn_bw_clear_data_request_OF_VERSION_1_1_show,
    of_bsn_bw_enable_get_reply_OF_VERSION_1_1_show,
    of_bsn_bw_enable_get_request_OF_VERSION_1_1_show,
    of_bsn_bw_enable_set_reply_OF_VERSION_1_1_show,
    of_bsn_bw_enable_set_request_OF_VERSION_1_1_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    of_bsn_get_interfaces_reply_OF_VERSION_1_1_show,
    of_bsn_get_interfaces_request_OF_VERSION_1_1_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    of_bsn_get_mirroring_reply_OF_VERSION_1_1_show,
    of_bsn_get_mirroring_request_OF_VERSION_1_1_show,
    of_bsn_header_OF_VERSION_1_1_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    of_bsn_pdu_rx_reply_OF_VERSION_1_1_show,
    of_bsn_pdu_rx_request_OF_VERSION_1_1_show,
    of_bsn_pdu_rx_timeout_OF_VERSION_1_1_show,
    of_bsn_pdu_tx_reply_OF_VERSION_1_1_show,
    of_bsn_pdu_tx_request_OF_VERSION_1_1_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    of_bsn_set_mirroring_OF_VERSION_1_1_show,
    of_bsn_set_pktin_suppression_reply_OF_VERSION_1_1_show,
    of_bsn_set_pktin_suppression_request_OF_VERSION_1_1_show,
    unknown_show,
    unknown_show,
    unknown_show,
    of_bsn_stats_reply_OF_VERSION_1_1_show,
    of_bsn_stats_request_OF_VERSION_1_1_show,
    unknown_show,
    unknown_show,
    of_bsn_virtual_port_create_reply_OF_VERSION_1_1_show,
    of_bsn_virtual_port_create_request_OF_VERSION_1_1_show,
    of_bsn_virtual_port_remove_reply_OF_VERSION_1_1_show,
    of_bsn_virtual_port_remove_request_OF_VERSION_1_1_show,
    of_desc_stats_reply_OF_VERSION_1_1_show,
    of_desc_stats_request_OF_VERSION_1_1_show,
    of_echo_reply_OF_VERSION_1_1_show,
    of_echo_request_OF_VERSION_1_1_show,
    of_error_msg_OF_VERSION_1_1_show,
    of_experimenter_OF_VERSION_1_1_show,
    unknown_show,
    of_experimenter_stats_reply_OF_VERSION_1_1_show,
    of_experimenter_stats_request_OF_VERSION_1_1_show,
    of_features_reply_OF_VERSION_1_1_show,
    of_features_request_OF_VERSION_1_1_show,
    of_flow_add_OF_VERSION_1_1_show,
    of_flow_delete_OF_VERSION_1_1_show,
    of_flow_delete_strict_OF_VERSION_1_1_show,
    of_flow_mod_OF_VERSION_1_1_show,
    of_flow_mod_failed_error_msg_OF_VERSION_1_1_show,
    of_flow_modify_OF_VERSION_1_1_show,
    of_flow_modify_strict_OF_VERSION_1_1_show,
    of_flow_removed_OF_VERSION_1_1_show,
    of_flow_stats_reply_OF_VERSION_1_1_show,
    of_flow_stats_request_OF_VERSION_1_1_show,
    of_get_config_reply_OF_VERSION_1_1_show,
    of_get_config_request_OF_VERSION_1_1_show,
    of_group_desc_stats_reply_OF_VERSION_1_1_show,
    of_group_desc_stats_request_OF_VERSION_1_1_show,
    unknown_show,
    unknown_show,
    of_group_mod_OF_VERSION_1_1_show,
    of_group_mod_failed_error_msg_OF_VERSION_1_1_show,
    of_group_stats_reply_OF_VERSION_1_1_show,
    of_group_stats_request_OF_VERSION_1_1_show,
    of_hello_OF_VERSION_1_1_show,
    of_hello_failed_error_msg_OF_VERSION_1_1_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    of_nicira_header_OF_VERSION_1_1_show,
    of_packet_in_OF_VERSION_1_1_show,
    of_packet_out_OF_VERSION_1_1_show,
    unknown_show,
    unknown_show,
    of_port_mod_OF_VERSION_1_1_show,
    of_port_mod_failed_error_msg_OF_VERSION_1_1_show,
    of_port_stats_reply_OF_VERSION_1_1_show,
    of_port_stats_request_OF_VERSION_1_1_show,
    of_port_status_OF_VERSION_1_1_show,
    of_queue_get_config_reply_OF_VERSION_1_1_show,
    of_queue_get_config_request_OF_VERSION_1_1_show,
    of_queue_op_failed_error_msg_OF_VERSION_1_1_show,
    of_queue_stats_reply_OF_VERSION_1_1_show,
    of_queue_stats_request_OF_VERSION_1_1_show,
    unknown_show,
    unknown_show,
    unknown_show,
    of_set_config_OF_VERSION_1_1_show,
    of_stats_reply_OF_VERSION_1_1_show,
    of_stats_request_OF_VERSION_1_1_show,
    of_switch_config_failed_error_msg_OF_VERSION_1_1_show,
    unknown_show,
    unknown_show,
    unknown_show,
    of_table_mod_OF_VERSION_1_1_show,
    of_table_mod_failed_error_msg_OF_VERSION_1_1_show,
    of_table_stats_reply_OF_VERSION_1_1_show,
    of_table_stats_request_OF_VERSION_1_1_show,
    unknown_show,
    of_action_bsn_OF_VERSION_1_1_show,
    of_action_bsn_mirror_OF_VERSION_1_1_show,
    of_action_bsn_set_tunnel_dst_OF_VERSION_1_1_show,
    of_action_copy_ttl_in_OF_VERSION_1_1_show,
    of_action_copy_ttl_out_OF_VERSION_1_1_show,
    of_action_dec_mpls_ttl_OF_VERSION_1_1_show,
    of_action_dec_nw_ttl_OF_VERSION_1_1_show,
    unknown_show,
    of_action_experimenter_OF_VERSION_1_1_show,
    of_action_group_OF_VERSION_1_1_show,
    of_action_header_OF_VERSION_1_1_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    of_action_nicira_OF_VERSION_1_1_show,
    of_action_nicira_dec_ttl_OF_VERSION_1_1_show,
    of_action_output_OF_VERSION_1_1_show,
    of_action_pop_mpls_OF_VERSION_1_1_show,
    unknown_show,
    of_action_pop_vlan_OF_VERSION_1_1_show,
    of_action_push_mpls_OF_VERSION_1_1_show,
    unknown_show,
    of_action_push_vlan_OF_VERSION_1_1_show,
    of_action_set_dl_dst_OF_VERSION_1_1_show,
    of_action_set_dl_src_OF_VERSION_1_1_show,
    unknown_show,
    of_action_set_mpls_label_OF_VERSION_1_1_show,
    of_action_set_mpls_tc_OF_VERSION_1_1_show,
    of_action_set_mpls_ttl_OF_VERSION_1_1_show,
    of_action_set_nw_dst_OF_VERSION_1_1_show,
    of_action_set_nw_ecn_OF_VERSION_1_1_show,
    of_action_set_nw_src_OF_VERSION_1_1_show,
    of_action_set_nw_tos_OF_VERSION_1_1_show,
    of_action_set_nw_ttl_OF_VERSION_1_1_show,
    of_action_set_queue_OF_VERSION_1_1_show,
    of_action_set_tp_dst_OF_VERSION_1_1_show,
    of_action_set_tp_src_OF_VERSION_1_1_show,
    of_action_set_vlan_pcp_OF_VERSION_1_1_show,
    of_action_set_vlan_vid_OF_VERSION_1_1_show,
    unknown_show,
    of_bsn_interface_OF_VERSION_1_1_show,
    unknown_show,
    unknown_show,
    of_bsn_vport_header_OF_VERSION_1_1_show,
    of_bsn_vport_q_in_q_OF_VERSION_1_1_show,
    of_bucket_OF_VERSION_1_1_show,
    of_bucket_counter_OF_VERSION_1_1_show,
    unknown_show,
    of_flow_stats_entry_OF_VERSION_1_1_show,
    of_group_desc_stats_entry_OF_VERSION_1_1_show,
    of_group_stats_entry_OF_VERSION_1_1_show,
    of_header_OF_VERSION_1_1_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    of_instruction_apply_actions_OF_VERSION_1_1_show,
    unknown_show,
    unknown_show,
    of_instruction_clear_actions_OF_VERSION_1_1_show,
    of_instruction_experimenter_OF_VERSION_1_1_show,
    of_instruction_goto_table_OF_VERSION_1_1_show,
    of_instruction_header_OF_VERSION_1_1_show,
    unknown_show,
    of_instruction_write_actions_OF_VERSION_1_1_show,
    of_instruction_write_metadata_OF_VERSION_1_1_show,
    unknown_show,
    of_match_v2_OF_VERSION_1_1_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    of_packet_queue_OF_VERSION_1_1_show,
    of_port_desc_OF_VERSION_1_1_show,
    of_port_stats_entry_OF_VERSION_1_1_show,
    unknown_show,
    unknown_show,
    of_queue_prop_header_OF_VERSION_1_1_show,
    unknown_show,
    of_queue_prop_min_rate_OF_VERSION_1_1_show,
    of_queue_stats_entry_OF_VERSION_1_1_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    of_table_stats_entry_OF_VERSION_1_1_show,
    unknown_show,
    unknown_show,
    of_list_action_OF_VERSION_1_1_show,
    unknown_show,
    of_list_bsn_interface_OF_VERSION_1_1_show,
    unknown_show,
    of_list_bucket_OF_VERSION_1_1_show,
    of_list_bucket_counter_OF_VERSION_1_1_show,
    of_list_flow_stats_entry_OF_VERSION_1_1_show,
    of_list_group_desc_stats_entry_OF_VERSION_1_1_show,
    of_list_group_stats_entry_OF_VERSION_1_1_show,
    unknown_show,
    of_list_instruction_OF_VERSION_1_1_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    of_list_packet_queue_OF_VERSION_1_1_show,
    of_list_port_desc_OF_VERSION_1_1_show,
    of_list_port_stats_entry_OF_VERSION_1_1_show,
    of_list_queue_prop_OF_VERSION_1_1_show,
    of_list_queue_stats_entry_OF_VERSION_1_1_show,
    unknown_show,
    unknown_show,
    of_list_table_stats_entry_OF_VERSION_1_1_show,
    unknown_show,
    unknown_show
};


static const loci_obj_show_f show_funs_v3[OF_OBJECT_COUNT] = {
    unknown_show, /* of_object, not a valid specific type */
    of_aggregate_stats_reply_OF_VERSION_1_2_show,
    of_aggregate_stats_request_OF_VERSION_1_2_show,
    unknown_show,
    unknown_show,
    unknown_show,
    of_bad_action_error_msg_OF_VERSION_1_2_show,
    of_bad_instruction_error_msg_OF_VERSION_1_2_show,
    of_bad_match_error_msg_OF_VERSION_1_2_show,
    of_bad_request_error_msg_OF_VERSION_1_2_show,
    of_barrier_reply_OF_VERSION_1_2_show,
    of_barrier_request_OF_VERSION_1_2_show,
    of_bsn_bw_clear_data_reply_OF_VERSION_1_2_show,
    of_bsn_bw_clear_data_request_OF_VERSION_1_2_show,
    of_bsn_bw_enable_get_reply_OF_VERSION_1_2_show,
    of_bsn_bw_enable_get_request_OF_VERSION_1_2_show,
    of_bsn_bw_enable_set_reply_OF_VERSION_1_2_show,
    of_bsn_bw_enable_set_request_OF_VERSION_1_2_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    of_bsn_get_interfaces_reply_OF_VERSION_1_2_show,
    of_bsn_get_interfaces_request_OF_VERSION_1_2_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    of_bsn_get_mirroring_reply_OF_VERSION_1_2_show,
    of_bsn_get_mirroring_request_OF_VERSION_1_2_show,
    of_bsn_header_OF_VERSION_1_2_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    of_bsn_pdu_rx_reply_OF_VERSION_1_2_show,
    of_bsn_pdu_rx_request_OF_VERSION_1_2_show,
    of_bsn_pdu_rx_timeout_OF_VERSION_1_2_show,
    of_bsn_pdu_tx_reply_OF_VERSION_1_2_show,
    of_bsn_pdu_tx_request_OF_VERSION_1_2_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    of_bsn_set_mirroring_OF_VERSION_1_2_show,
    of_bsn_set_pktin_suppression_reply_OF_VERSION_1_2_show,
    of_bsn_set_pktin_suppression_request_OF_VERSION_1_2_show,
    unknown_show,
    unknown_show,
    unknown_show,
    of_bsn_stats_reply_OF_VERSION_1_2_show,
    of_bsn_stats_request_OF_VERSION_1_2_show,
    unknown_show,
    unknown_show,
    of_bsn_virtual_port_create_reply_OF_VERSION_1_2_show,
    of_bsn_virtual_port_create_request_OF_VERSION_1_2_show,
    of_bsn_virtual_port_remove_reply_OF_VERSION_1_2_show,
    of_bsn_virtual_port_remove_request_OF_VERSION_1_2_show,
    of_desc_stats_reply_OF_VERSION_1_2_show,
    of_desc_stats_request_OF_VERSION_1_2_show,
    of_echo_reply_OF_VERSION_1_2_show,
    of_echo_request_OF_VERSION_1_2_show,
    of_error_msg_OF_VERSION_1_2_show,
    of_experimenter_OF_VERSION_1_2_show,
    of_experimenter_error_msg_OF_VERSION_1_2_show,
    of_experimenter_stats_reply_OF_VERSION_1_2_show,
    of_experimenter_stats_request_OF_VERSION_1_2_show,
    of_features_reply_OF_VERSION_1_2_show,
    of_features_request_OF_VERSION_1_2_show,
    of_flow_add_OF_VERSION_1_2_show,
    of_flow_delete_OF_VERSION_1_2_show,
    of_flow_delete_strict_OF_VERSION_1_2_show,
    of_flow_mod_OF_VERSION_1_2_show,
    of_flow_mod_failed_error_msg_OF_VERSION_1_2_show,
    of_flow_modify_OF_VERSION_1_2_show,
    of_flow_modify_strict_OF_VERSION_1_2_show,
    of_flow_removed_OF_VERSION_1_2_show,
    of_flow_stats_reply_OF_VERSION_1_2_show,
    of_flow_stats_request_OF_VERSION_1_2_show,
    of_get_config_reply_OF_VERSION_1_2_show,
    of_get_config_request_OF_VERSION_1_2_show,
    of_group_desc_stats_reply_OF_VERSION_1_2_show,
    of_group_desc_stats_request_OF_VERSION_1_2_show,
    of_group_features_stats_reply_OF_VERSION_1_2_show,
    of_group_features_stats_request_OF_VERSION_1_2_show,
    of_group_mod_OF_VERSION_1_2_show,
    of_group_mod_failed_error_msg_OF_VERSION_1_2_show,
    of_group_stats_reply_OF_VERSION_1_2_show,
    of_group_stats_request_OF_VERSION_1_2_show,
    of_hello_OF_VERSION_1_2_show,
    of_hello_failed_error_msg_OF_VERSION_1_2_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    of_nicira_header_OF_VERSION_1_2_show,
    of_packet_in_OF_VERSION_1_2_show,
    of_packet_out_OF_VERSION_1_2_show,
    unknown_show,
    unknown_show,
    of_port_mod_OF_VERSION_1_2_show,
    of_port_mod_failed_error_msg_OF_VERSION_1_2_show,
    of_port_stats_reply_OF_VERSION_1_2_show,
    of_port_stats_request_OF_VERSION_1_2_show,
    of_port_status_OF_VERSION_1_2_show,
    of_queue_get_config_reply_OF_VERSION_1_2_show,
    of_queue_get_config_request_OF_VERSION_1_2_show,
    of_queue_op_failed_error_msg_OF_VERSION_1_2_show,
    of_queue_stats_reply_OF_VERSION_1_2_show,
    of_queue_stats_request_OF_VERSION_1_2_show,
    of_role_reply_OF_VERSION_1_2_show,
    of_role_request_OF_VERSION_1_2_show,
    of_role_request_failed_error_msg_OF_VERSION_1_2_show,
    of_set_config_OF_VERSION_1_2_show,
    of_stats_reply_OF_VERSION_1_2_show,
    of_stats_request_OF_VERSION_1_2_show,
    of_switch_config_failed_error_msg_OF_VERSION_1_2_show,
    unknown_show,
    unknown_show,
    unknown_show,
    of_table_mod_OF_VERSION_1_2_show,
    of_table_mod_failed_error_msg_OF_VERSION_1_2_show,
    of_table_stats_reply_OF_VERSION_1_2_show,
    of_table_stats_request_OF_VERSION_1_2_show,
    unknown_show,
    of_action_bsn_OF_VERSION_1_2_show,
    of_action_bsn_mirror_OF_VERSION_1_2_show,
    of_action_bsn_set_tunnel_dst_OF_VERSION_1_2_show,
    of_action_copy_ttl_in_OF_VERSION_1_2_show,
    of_action_copy_ttl_out_OF_VERSION_1_2_show,
    of_action_dec_mpls_ttl_OF_VERSION_1_2_show,
    of_action_dec_nw_ttl_OF_VERSION_1_2_show,
    unknown_show,
    of_action_experimenter_OF_VERSION_1_2_show,
    of_action_group_OF_VERSION_1_2_show,
    of_action_header_OF_VERSION_1_2_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    of_action_nicira_OF_VERSION_1_2_show,
    of_action_nicira_dec_ttl_OF_VERSION_1_2_show,
    of_action_output_OF_VERSION_1_2_show,
    of_action_pop_mpls_OF_VERSION_1_2_show,
    unknown_show,
    of_action_pop_vlan_OF_VERSION_1_2_show,
    of_action_push_mpls_OF_VERSION_1_2_show,
    unknown_show,
    of_action_push_vlan_OF_VERSION_1_2_show,
    unknown_show,
    unknown_show,
    of_action_set_field_OF_VERSION_1_2_show,
    unknown_show,
    unknown_show,
    of_action_set_mpls_ttl_OF_VERSION_1_2_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    of_action_set_nw_ttl_OF_VERSION_1_2_show,
    of_action_set_queue_OF_VERSION_1_2_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    of_bsn_interface_OF_VERSION_1_2_show,
    unknown_show,
    unknown_show,
    of_bsn_vport_header_OF_VERSION_1_2_show,
    of_bsn_vport_q_in_q_OF_VERSION_1_2_show,
    of_bucket_OF_VERSION_1_2_show,
    of_bucket_counter_OF_VERSION_1_2_show,
    unknown_show,
    of_flow_stats_entry_OF_VERSION_1_2_show,
    of_group_desc_stats_entry_OF_VERSION_1_2_show,
    of_group_stats_entry_OF_VERSION_1_2_show,
    of_header_OF_VERSION_1_2_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    of_instruction_apply_actions_OF_VERSION_1_2_show,
    unknown_show,
    unknown_show,
    of_instruction_clear_actions_OF_VERSION_1_2_show,
    of_instruction_experimenter_OF_VERSION_1_2_show,
    of_instruction_goto_table_OF_VERSION_1_2_show,
    of_instruction_header_OF_VERSION_1_2_show,
    unknown_show,
    of_instruction_write_actions_OF_VERSION_1_2_show,
    of_instruction_write_metadata_OF_VERSION_1_2_show,
    unknown_show,
    unknown_show,
    of_match_v3_OF_VERSION_1_2_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    of_oxm_arp_op_OF_VERSION_1_2_show,
    of_oxm_arp_op_masked_OF_VERSION_1_2_show,
    of_oxm_arp_sha_OF_VERSION_1_2_show,
    of_oxm_arp_sha_masked_OF_VERSION_1_2_show,
    of_oxm_arp_spa_OF_VERSION_1_2_show,
    of_oxm_arp_spa_masked_OF_VERSION_1_2_show,
    of_oxm_arp_tha_OF_VERSION_1_2_show,
    of_oxm_arp_tha_masked_OF_VERSION_1_2_show,
    of_oxm_arp_tpa_OF_VERSION_1_2_show,
    of_oxm_arp_tpa_masked_OF_VERSION_1_2_show,
    of_oxm_bsn_global_vrf_allowed_OF_VERSION_1_2_show,
    of_oxm_bsn_global_vrf_allowed_masked_OF_VERSION_1_2_show,
    of_oxm_bsn_in_ports_128_OF_VERSION_1_2_show,
    of_oxm_bsn_in_ports_128_masked_OF_VERSION_1_2_show,
    of_oxm_bsn_l3_dst_class_id_OF_VERSION_1_2_show,
    of_oxm_bsn_l3_dst_class_id_masked_OF_VERSION_1_2_show,
    of_oxm_bsn_l3_interface_class_id_OF_VERSION_1_2_show,
    of_oxm_bsn_l3_interface_class_id_masked_OF_VERSION_1_2_show,
    of_oxm_bsn_l3_src_class_id_OF_VERSION_1_2_show,
    of_oxm_bsn_l3_src_class_id_masked_OF_VERSION_1_2_show,
    of_oxm_bsn_lag_id_OF_VERSION_1_2_show,
    of_oxm_bsn_lag_id_masked_OF_VERSION_1_2_show,
    of_oxm_bsn_vrf_OF_VERSION_1_2_show,
    of_oxm_bsn_vrf_masked_OF_VERSION_1_2_show,
    of_oxm_eth_dst_OF_VERSION_1_2_show,
    of_oxm_eth_dst_masked_OF_VERSION_1_2_show,
    of_oxm_eth_src_OF_VERSION_1_2_show,
    of_oxm_eth_src_masked_OF_VERSION_1_2_show,
    of_oxm_eth_type_OF_VERSION_1_2_show,
    of_oxm_eth_type_masked_OF_VERSION_1_2_show,
    of_oxm_header_OF_VERSION_1_2_show,
    of_oxm_icmpv4_code_OF_VERSION_1_2_show,
    of_oxm_icmpv4_code_masked_OF_VERSION_1_2_show,
    of_oxm_icmpv4_type_OF_VERSION_1_2_show,
    of_oxm_icmpv4_type_masked_OF_VERSION_1_2_show,
    of_oxm_icmpv6_code_OF_VERSION_1_2_show,
    of_oxm_icmpv6_code_masked_OF_VERSION_1_2_show,
    of_oxm_icmpv6_type_OF_VERSION_1_2_show,
    of_oxm_icmpv6_type_masked_OF_VERSION_1_2_show,
    of_oxm_in_phy_port_OF_VERSION_1_2_show,
    of_oxm_in_phy_port_masked_OF_VERSION_1_2_show,
    of_oxm_in_port_OF_VERSION_1_2_show,
    of_oxm_in_port_masked_OF_VERSION_1_2_show,
    of_oxm_ip_dscp_OF_VERSION_1_2_show,
    of_oxm_ip_dscp_masked_OF_VERSION_1_2_show,
    of_oxm_ip_ecn_OF_VERSION_1_2_show,
    of_oxm_ip_ecn_masked_OF_VERSION_1_2_show,
    of_oxm_ip_proto_OF_VERSION_1_2_show,
    of_oxm_ip_proto_masked_OF_VERSION_1_2_show,
    of_oxm_ipv4_dst_OF_VERSION_1_2_show,
    of_oxm_ipv4_dst_masked_OF_VERSION_1_2_show,
    of_oxm_ipv4_src_OF_VERSION_1_2_show,
    of_oxm_ipv4_src_masked_OF_VERSION_1_2_show,
    of_oxm_ipv6_dst_OF_VERSION_1_2_show,
    of_oxm_ipv6_dst_masked_OF_VERSION_1_2_show,
    of_oxm_ipv6_flabel_OF_VERSION_1_2_show,
    of_oxm_ipv6_flabel_masked_OF_VERSION_1_2_show,
    of_oxm_ipv6_nd_sll_OF_VERSION_1_2_show,
    of_oxm_ipv6_nd_sll_masked_OF_VERSION_1_2_show,
    of_oxm_ipv6_nd_target_OF_VERSION_1_2_show,
    of_oxm_ipv6_nd_target_masked_OF_VERSION_1_2_show,
    of_oxm_ipv6_nd_tll_OF_VERSION_1_2_show,
    of_oxm_ipv6_nd_tll_masked_OF_VERSION_1_2_show,
    of_oxm_ipv6_src_OF_VERSION_1_2_show,
    of_oxm_ipv6_src_masked_OF_VERSION_1_2_show,
    of_oxm_metadata_OF_VERSION_1_2_show,
    of_oxm_metadata_masked_OF_VERSION_1_2_show,
    of_oxm_mpls_label_OF_VERSION_1_2_show,
    of_oxm_mpls_label_masked_OF_VERSION_1_2_show,
    of_oxm_mpls_tc_OF_VERSION_1_2_show,
    of_oxm_mpls_tc_masked_OF_VERSION_1_2_show,
    of_oxm_sctp_dst_OF_VERSION_1_2_show,
    of_oxm_sctp_dst_masked_OF_VERSION_1_2_show,
    of_oxm_sctp_src_OF_VERSION_1_2_show,
    of_oxm_sctp_src_masked_OF_VERSION_1_2_show,
    of_oxm_tcp_dst_OF_VERSION_1_2_show,
    of_oxm_tcp_dst_masked_OF_VERSION_1_2_show,
    of_oxm_tcp_src_OF_VERSION_1_2_show,
    of_oxm_tcp_src_masked_OF_VERSION_1_2_show,
    of_oxm_udp_dst_OF_VERSION_1_2_show,
    of_oxm_udp_dst_masked_OF_VERSION_1_2_show,
    of_oxm_udp_src_OF_VERSION_1_2_show,
    of_oxm_udp_src_masked_OF_VERSION_1_2_show,
    of_oxm_vlan_pcp_OF_VERSION_1_2_show,
    of_oxm_vlan_pcp_masked_OF_VERSION_1_2_show,
    of_oxm_vlan_vid_OF_VERSION_1_2_show,
    of_oxm_vlan_vid_masked_OF_VERSION_1_2_show,
    of_packet_queue_OF_VERSION_1_2_show,
    of_port_desc_OF_VERSION_1_2_show,
    of_port_stats_entry_OF_VERSION_1_2_show,
    unknown_show,
    of_queue_prop_experimenter_OF_VERSION_1_2_show,
    of_queue_prop_header_OF_VERSION_1_2_show,
    of_queue_prop_max_rate_OF_VERSION_1_2_show,
    of_queue_prop_min_rate_OF_VERSION_1_2_show,
    of_queue_stats_entry_OF_VERSION_1_2_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    of_table_stats_entry_OF_VERSION_1_2_show,
    unknown_show,
    unknown_show,
    of_list_action_OF_VERSION_1_2_show,
    unknown_show,
    of_list_bsn_interface_OF_VERSION_1_2_show,
    unknown_show,
    of_list_bucket_OF_VERSION_1_2_show,
    of_list_bucket_counter_OF_VERSION_1_2_show,
    of_list_flow_stats_entry_OF_VERSION_1_2_show,
    of_list_group_desc_stats_entry_OF_VERSION_1_2_show,
    of_list_group_stats_entry_OF_VERSION_1_2_show,
    unknown_show,
    of_list_instruction_OF_VERSION_1_2_show,
    unknown_show,
    unknown_show,
    unknown_show,
    of_list_oxm_OF_VERSION_1_2_show,
    of_list_packet_queue_OF_VERSION_1_2_show,
    of_list_port_desc_OF_VERSION_1_2_show,
    of_list_port_stats_entry_OF_VERSION_1_2_show,
    of_list_queue_prop_OF_VERSION_1_2_show,
    of_list_queue_stats_entry_OF_VERSION_1_2_show,
    unknown_show,
    unknown_show,
    of_list_table_stats_entry_OF_VERSION_1_2_show,
    unknown_show,
    unknown_show
};


static const loci_obj_show_f show_funs_v4[OF_OBJECT_COUNT] = {
    unknown_show, /* of_object, not a valid specific type */
    of_aggregate_stats_reply_OF_VERSION_1_3_show,
    of_aggregate_stats_request_OF_VERSION_1_3_show,
    of_async_get_reply_OF_VERSION_1_3_show,
    of_async_get_request_OF_VERSION_1_3_show,
    of_async_set_OF_VERSION_1_3_show,
    of_bad_action_error_msg_OF_VERSION_1_3_show,
    of_bad_instruction_error_msg_OF_VERSION_1_3_show,
    of_bad_match_error_msg_OF_VERSION_1_3_show,
    of_bad_request_error_msg_OF_VERSION_1_3_show,
    of_barrier_reply_OF_VERSION_1_3_show,
    of_barrier_request_OF_VERSION_1_3_show,
    of_bsn_bw_clear_data_reply_OF_VERSION_1_3_show,
    of_bsn_bw_clear_data_request_OF_VERSION_1_3_show,
    of_bsn_bw_enable_get_reply_OF_VERSION_1_3_show,
    of_bsn_bw_enable_get_request_OF_VERSION_1_3_show,
    of_bsn_bw_enable_set_reply_OF_VERSION_1_3_show,
    of_bsn_bw_enable_set_request_OF_VERSION_1_3_show,
    of_bsn_flow_idle_OF_VERSION_1_3_show,
    of_bsn_flow_idle_enable_get_reply_OF_VERSION_1_3_show,
    of_bsn_flow_idle_enable_get_request_OF_VERSION_1_3_show,
    of_bsn_flow_idle_enable_set_reply_OF_VERSION_1_3_show,
    of_bsn_flow_idle_enable_set_request_OF_VERSION_1_3_show,
    of_bsn_get_interfaces_reply_OF_VERSION_1_3_show,
    of_bsn_get_interfaces_request_OF_VERSION_1_3_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    of_bsn_get_mirroring_reply_OF_VERSION_1_3_show,
    of_bsn_get_mirroring_request_OF_VERSION_1_3_show,
    of_bsn_header_OF_VERSION_1_3_show,
    unknown_show,
    unknown_show,
    of_bsn_lacp_convergence_notif_OF_VERSION_1_3_show,
    of_bsn_lacp_stats_reply_OF_VERSION_1_3_show,
    of_bsn_lacp_stats_request_OF_VERSION_1_3_show,
    of_bsn_pdu_rx_reply_OF_VERSION_1_3_show,
    of_bsn_pdu_rx_request_OF_VERSION_1_3_show,
    of_bsn_pdu_rx_timeout_OF_VERSION_1_3_show,
    of_bsn_pdu_tx_reply_OF_VERSION_1_3_show,
    of_bsn_pdu_tx_request_OF_VERSION_1_3_show,
    unknown_show,
    unknown_show,
    unknown_show,
    of_bsn_set_lacp_reply_OF_VERSION_1_3_show,
    of_bsn_set_lacp_request_OF_VERSION_1_3_show,
    of_bsn_set_mirroring_OF_VERSION_1_3_show,
    of_bsn_set_pktin_suppression_reply_OF_VERSION_1_3_show,
    of_bsn_set_pktin_suppression_request_OF_VERSION_1_3_show,
    unknown_show,
    unknown_show,
    unknown_show,
    of_bsn_stats_reply_OF_VERSION_1_3_show,
    of_bsn_stats_request_OF_VERSION_1_3_show,
    of_bsn_time_reply_OF_VERSION_1_3_show,
    of_bsn_time_request_OF_VERSION_1_3_show,
    of_bsn_virtual_port_create_reply_OF_VERSION_1_3_show,
    of_bsn_virtual_port_create_request_OF_VERSION_1_3_show,
    of_bsn_virtual_port_remove_reply_OF_VERSION_1_3_show,
    of_bsn_virtual_port_remove_request_OF_VERSION_1_3_show,
    of_desc_stats_reply_OF_VERSION_1_3_show,
    of_desc_stats_request_OF_VERSION_1_3_show,
    of_echo_reply_OF_VERSION_1_3_show,
    of_echo_request_OF_VERSION_1_3_show,
    of_error_msg_OF_VERSION_1_3_show,
    of_experimenter_OF_VERSION_1_3_show,
    of_experimenter_error_msg_OF_VERSION_1_3_show,
    of_experimenter_stats_reply_OF_VERSION_1_3_show,
    of_experimenter_stats_request_OF_VERSION_1_3_show,
    of_features_reply_OF_VERSION_1_3_show,
    of_features_request_OF_VERSION_1_3_show,
    of_flow_add_OF_VERSION_1_3_show,
    of_flow_delete_OF_VERSION_1_3_show,
    of_flow_delete_strict_OF_VERSION_1_3_show,
    of_flow_mod_OF_VERSION_1_3_show,
    of_flow_mod_failed_error_msg_OF_VERSION_1_3_show,
    of_flow_modify_OF_VERSION_1_3_show,
    of_flow_modify_strict_OF_VERSION_1_3_show,
    of_flow_removed_OF_VERSION_1_3_show,
    of_flow_stats_reply_OF_VERSION_1_3_show,
    of_flow_stats_request_OF_VERSION_1_3_show,
    of_get_config_reply_OF_VERSION_1_3_show,
    of_get_config_request_OF_VERSION_1_3_show,
    of_group_desc_stats_reply_OF_VERSION_1_3_show,
    of_group_desc_stats_request_OF_VERSION_1_3_show,
    of_group_features_stats_reply_OF_VERSION_1_3_show,
    of_group_features_stats_request_OF_VERSION_1_3_show,
    of_group_mod_OF_VERSION_1_3_show,
    of_group_mod_failed_error_msg_OF_VERSION_1_3_show,
    of_group_stats_reply_OF_VERSION_1_3_show,
    of_group_stats_request_OF_VERSION_1_3_show,
    of_hello_OF_VERSION_1_3_show,
    of_hello_failed_error_msg_OF_VERSION_1_3_show,
    of_meter_config_stats_reply_OF_VERSION_1_3_show,
    of_meter_config_stats_request_OF_VERSION_1_3_show,
    of_meter_features_stats_reply_OF_VERSION_1_3_show,
    of_meter_features_stats_request_OF_VERSION_1_3_show,
    of_meter_mod_OF_VERSION_1_3_show,
    of_meter_mod_failed_error_msg_OF_VERSION_1_3_show,
    of_meter_stats_reply_OF_VERSION_1_3_show,
    of_meter_stats_request_OF_VERSION_1_3_show,
    unknown_show,
    unknown_show,
    of_nicira_header_OF_VERSION_1_3_show,
    of_packet_in_OF_VERSION_1_3_show,
    of_packet_out_OF_VERSION_1_3_show,
    of_port_desc_stats_reply_OF_VERSION_1_3_show,
    of_port_desc_stats_request_OF_VERSION_1_3_show,
    of_port_mod_OF_VERSION_1_3_show,
    of_port_mod_failed_error_msg_OF_VERSION_1_3_show,
    of_port_stats_reply_OF_VERSION_1_3_show,
    of_port_stats_request_OF_VERSION_1_3_show,
    of_port_status_OF_VERSION_1_3_show,
    of_queue_get_config_reply_OF_VERSION_1_3_show,
    of_queue_get_config_request_OF_VERSION_1_3_show,
    of_queue_op_failed_error_msg_OF_VERSION_1_3_show,
    of_queue_stats_reply_OF_VERSION_1_3_show,
    of_queue_stats_request_OF_VERSION_1_3_show,
    of_role_reply_OF_VERSION_1_3_show,
    of_role_request_OF_VERSION_1_3_show,
    of_role_request_failed_error_msg_OF_VERSION_1_3_show,
    of_set_config_OF_VERSION_1_3_show,
    of_stats_reply_OF_VERSION_1_3_show,
    of_stats_request_OF_VERSION_1_3_show,
    of_switch_config_failed_error_msg_OF_VERSION_1_3_show,
    of_table_features_failed_error_msg_OF_VERSION_1_3_show,
    of_table_features_stats_reply_OF_VERSION_1_3_show,
    of_table_features_stats_request_OF_VERSION_1_3_show,
    of_table_mod_OF_VERSION_1_3_show,
    of_table_mod_failed_error_msg_OF_VERSION_1_3_show,
    of_table_stats_reply_OF_VERSION_1_3_show,
    of_table_stats_request_OF_VERSION_1_3_show,
    unknown_show,
    of_action_bsn_OF_VERSION_1_3_show,
    of_action_bsn_mirror_OF_VERSION_1_3_show,
    of_action_bsn_set_tunnel_dst_OF_VERSION_1_3_show,
    of_action_copy_ttl_in_OF_VERSION_1_3_show,
    of_action_copy_ttl_out_OF_VERSION_1_3_show,
    of_action_dec_mpls_ttl_OF_VERSION_1_3_show,
    of_action_dec_nw_ttl_OF_VERSION_1_3_show,
    unknown_show,
    of_action_experimenter_OF_VERSION_1_3_show,
    of_action_group_OF_VERSION_1_3_show,
    of_action_header_OF_VERSION_1_3_show,
    unknown_show,
    of_action_id_bsn_OF_VERSION_1_3_show,
    of_action_id_bsn_mirror_OF_VERSION_1_3_show,
    of_action_id_bsn_set_tunnel_dst_OF_VERSION_1_3_show,
    of_action_id_copy_ttl_in_OF_VERSION_1_3_show,
    of_action_id_copy_ttl_out_OF_VERSION_1_3_show,
    of_action_id_dec_mpls_ttl_OF_VERSION_1_3_show,
    of_action_id_dec_nw_ttl_OF_VERSION_1_3_show,
    of_action_id_experimenter_OF_VERSION_1_3_show,
    of_action_id_group_OF_VERSION_1_3_show,
    of_action_id_header_OF_VERSION_1_3_show,
    of_action_id_nicira_OF_VERSION_1_3_show,
    of_action_id_nicira_dec_ttl_OF_VERSION_1_3_show,
    of_action_id_output_OF_VERSION_1_3_show,
    of_action_id_pop_mpls_OF_VERSION_1_3_show,
    of_action_id_pop_pbb_OF_VERSION_1_3_show,
    of_action_id_pop_vlan_OF_VERSION_1_3_show,
    of_action_id_push_mpls_OF_VERSION_1_3_show,
    of_action_id_push_pbb_OF_VERSION_1_3_show,
    of_action_id_push_vlan_OF_VERSION_1_3_show,
    of_action_id_set_field_OF_VERSION_1_3_show,
    of_action_id_set_mpls_ttl_OF_VERSION_1_3_show,
    of_action_id_set_nw_ttl_OF_VERSION_1_3_show,
    of_action_id_set_queue_OF_VERSION_1_3_show,
    of_action_nicira_OF_VERSION_1_3_show,
    of_action_nicira_dec_ttl_OF_VERSION_1_3_show,
    of_action_output_OF_VERSION_1_3_show,
    of_action_pop_mpls_OF_VERSION_1_3_show,
    of_action_pop_pbb_OF_VERSION_1_3_show,
    of_action_pop_vlan_OF_VERSION_1_3_show,
    of_action_push_mpls_OF_VERSION_1_3_show,
    of_action_push_pbb_OF_VERSION_1_3_show,
    of_action_push_vlan_OF_VERSION_1_3_show,
    unknown_show,
    unknown_show,
    of_action_set_field_OF_VERSION_1_3_show,
    unknown_show,
    unknown_show,
    of_action_set_mpls_ttl_OF_VERSION_1_3_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    of_action_set_nw_ttl_OF_VERSION_1_3_show,
    of_action_set_queue_OF_VERSION_1_3_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    unknown_show,
    of_bsn_interface_OF_VERSION_1_3_show,
    of_bsn_lacp_stats_entry_OF_VERSION_1_3_show,
    unknown_show,
    of_bsn_vport_header_OF_VERSION_1_3_show,
    of_bsn_vport_q_in_q_OF_VERSION_1_3_show,
    of_bucket_OF_VERSION_1_3_show,
    of_bucket_counter_OF_VERSION_1_3_show,
    of_experimenter_stats_header_OF_VERSION_1_3_show,
    of_flow_stats_entry_OF_VERSION_1_3_show,
    of_group_desc_stats_entry_OF_VERSION_1_3_show,
    of_group_stats_entry_OF_VERSION_1_3_show,
    of_header_OF_VERSION_1_3_show,
    unknown_show,
    of_hello_elem_header_OF_VERSION_1_3_show,
    of_hello_elem_versionbitmap_OF_VERSION_1_3_show,
    unknown_show,
    of_instruction_apply_actions_OF_VERSION_1_3_show,
    of_instruction_bsn_OF_VERSION_1_3_show,
    of_instruction_bsn_disable_src_mac_check_OF_VERSION_1_3_show,
    of_instruction_clear_actions_OF_VERSION_1_3_show,
    of_instruction_experimenter_OF_VERSION_1_3_show,
    of_instruction_goto_table_OF_VERSION_1_3_show,
    of_instruction_header_OF_VERSION_1_3_show,
    of_instruction_meter_OF_VERSION_1_3_show,
    of_instruction_write_actions_OF_VERSION_1_3_show,
    of_instruction_write_metadata_OF_VERSION_1_3_show,
    unknown_show,
    unknown_show,
    of_match_v3_OF_VERSION_1_3_show,
    unknown_show,
    of_meter_band_drop_OF_VERSION_1_3_show,
    of_meter_band_dscp_remark_OF_VERSION_1_3_show,
    of_meter_band_experimenter_OF_VERSION_1_3_show,
    of_meter_band_header_OF_VERSION_1_3_show,
    of_meter_band_stats_OF_VERSION_1_3_show,
    of_meter_config_OF_VERSION_1_3_show,
    of_meter_features_OF_VERSION_1_3_show,
    of_meter_stats_OF_VERSION_1_3_show,
    unknown_show,
    of_oxm_arp_op_OF_VERSION_1_3_show,
    of_oxm_arp_op_masked_OF_VERSION_1_3_show,
    of_oxm_arp_sha_OF_VERSION_1_3_show,
    of_oxm_arp_sha_masked_OF_VERSION_1_3_show,
    of_oxm_arp_spa_OF_VERSION_1_3_show,
    of_oxm_arp_spa_masked_OF_VERSION_1_3_show,
    of_oxm_arp_tha_OF_VERSION_1_3_show,
    of_oxm_arp_tha_masked_OF_VERSION_1_3_show,
    of_oxm_arp_tpa_OF_VERSION_1_3_show,
    of_oxm_arp_tpa_masked_OF_VERSION_1_3_show,
    of_oxm_bsn_global_vrf_allowed_OF_VERSION_1_3_show,
    of_oxm_bsn_global_vrf_allowed_masked_OF_VERSION_1_3_show,
    of_oxm_bsn_in_ports_128_OF_VERSION_1_3_show,
    of_oxm_bsn_in_ports_128_masked_OF_VERSION_1_3_show,
    of_oxm_bsn_l3_dst_class_id_OF_VERSION_1_3_show,
    of_oxm_bsn_l3_dst_class_id_masked_OF_VERSION_1_3_show,
    of_oxm_bsn_l3_interface_class_id_OF_VERSION_1_3_show,
    of_oxm_bsn_l3_interface_class_id_masked_OF_VERSION_1_3_show,
    of_oxm_bsn_l3_src_class_id_OF_VERSION_1_3_show,
    of_oxm_bsn_l3_src_class_id_masked_OF_VERSION_1_3_show,
    of_oxm_bsn_lag_id_OF_VERSION_1_3_show,
    of_oxm_bsn_lag_id_masked_OF_VERSION_1_3_show,
    of_oxm_bsn_vrf_OF_VERSION_1_3_show,
    of_oxm_bsn_vrf_masked_OF_VERSION_1_3_show,
    of_oxm_eth_dst_OF_VERSION_1_3_show,
    of_oxm_eth_dst_masked_OF_VERSION_1_3_show,
    of_oxm_eth_src_OF_VERSION_1_3_show,
    of_oxm_eth_src_masked_OF_VERSION_1_3_show,
    of_oxm_eth_type_OF_VERSION_1_3_show,
    of_oxm_eth_type_masked_OF_VERSION_1_3_show,
    of_oxm_header_OF_VERSION_1_3_show,
    of_oxm_icmpv4_code_OF_VERSION_1_3_show,
    of_oxm_icmpv4_code_masked_OF_VERSION_1_3_show,
    of_oxm_icmpv4_type_OF_VERSION_1_3_show,
    of_oxm_icmpv4_type_masked_OF_VERSION_1_3_show,
    of_oxm_icmpv6_code_OF_VERSION_1_3_show,
    of_oxm_icmpv6_code_masked_OF_VERSION_1_3_show,
    of_oxm_icmpv6_type_OF_VERSION_1_3_show,
    of_oxm_icmpv6_type_masked_OF_VERSION_1_3_show,
    of_oxm_in_phy_port_OF_VERSION_1_3_show,
    of_oxm_in_phy_port_masked_OF_VERSION_1_3_show,
    of_oxm_in_port_OF_VERSION_1_3_show,
    of_oxm_in_port_masked_OF_VERSION_1_3_show,
    of_oxm_ip_dscp_OF_VERSION_1_3_show,
    of_oxm_ip_dscp_masked_OF_VERSION_1_3_show,
    of_oxm_ip_ecn_OF_VERSION_1_3_show,
    of_oxm_ip_ecn_masked_OF_VERSION_1_3_show,
    of_oxm_ip_proto_OF_VERSION_1_3_show,
    of_oxm_ip_proto_masked_OF_VERSION_1_3_show,
    of_oxm_ipv4_dst_OF_VERSION_1_3_show,
    of_oxm_ipv4_dst_masked_OF_VERSION_1_3_show,
    of_oxm_ipv4_src_OF_VERSION_1_3_show,
    of_oxm_ipv4_src_masked_OF_VERSION_1_3_show,
    of_oxm_ipv6_dst_OF_VERSION_1_3_show,
    of_oxm_ipv6_dst_masked_OF_VERSION_1_3_show,
    of_oxm_ipv6_flabel_OF_VERSION_1_3_show,
    of_oxm_ipv6_flabel_masked_OF_VERSION_1_3_show,
    of_oxm_ipv6_nd_sll_OF_VERSION_1_3_show,
    of_oxm_ipv6_nd_sll_masked_OF_VERSION_1_3_show,
    of_oxm_ipv6_nd_target_OF_VERSION_1_3_show,
    of_oxm_ipv6_nd_target_masked_OF_VERSION_1_3_show,
    of_oxm_ipv6_nd_tll_OF_VERSION_1_3_show,
    of_oxm_ipv6_nd_tll_masked_OF_VERSION_1_3_show,
    of_oxm_ipv6_src_OF_VERSION_1_3_show,
    of_oxm_ipv6_src_masked_OF_VERSION_1_3_show,
    of_oxm_metadata_OF_VERSION_1_3_show,
    of_oxm_metadata_masked_OF_VERSION_1_3_show,
    of_oxm_mpls_label_OF_VERSION_1_3_show,
    of_oxm_mpls_label_masked_OF_VERSION_1_3_show,
    of_oxm_mpls_tc_OF_VERSION_1_3_show,
    of_oxm_mpls_tc_masked_OF_VERSION_1_3_show,
    of_oxm_sctp_dst_OF_VERSION_1_3_show,
    of_oxm_sctp_dst_masked_OF_VERSION_1_3_show,
    of_oxm_sctp_src_OF_VERSION_1_3_show,
    of_oxm_sctp_src_masked_OF_VERSION_1_3_show,
    of_oxm_tcp_dst_OF_VERSION_1_3_show,
    of_oxm_tcp_dst_masked_OF_VERSION_1_3_show,
    of_oxm_tcp_src_OF_VERSION_1_3_show,
    of_oxm_tcp_src_masked_OF_VERSION_1_3_show,
    of_oxm_udp_dst_OF_VERSION_1_3_show,
    of_oxm_udp_dst_masked_OF_VERSION_1_3_show,
    of_oxm_udp_src_OF_VERSION_1_3_show,
    of_oxm_udp_src_masked_OF_VERSION_1_3_show,
    of_oxm_vlan_pcp_OF_VERSION_1_3_show,
    of_oxm_vlan_pcp_masked_OF_VERSION_1_3_show,
    of_oxm_vlan_vid_OF_VERSION_1_3_show,
    of_oxm_vlan_vid_masked_OF_VERSION_1_3_show,
    of_packet_queue_OF_VERSION_1_3_show,
    of_port_desc_OF_VERSION_1_3_show,
    of_port_stats_entry_OF_VERSION_1_3_show,
    unknown_show,
    of_queue_prop_experimenter_OF_VERSION_1_3_show,
    of_queue_prop_header_OF_VERSION_1_3_show,
    of_queue_prop_max_rate_OF_VERSION_1_3_show,
    of_queue_prop_min_rate_OF_VERSION_1_3_show,
    of_queue_stats_entry_OF_VERSION_1_3_show,
    unknown_show,
    of_table_feature_prop_apply_actions_OF_VERSION_1_3_show,
    of_table_feature_prop_apply_actions_miss_OF_VERSION_1_3_show,
    of_table_feature_prop_apply_setfield_OF_VERSION_1_3_show,
    of_table_feature_prop_apply_setfield_miss_OF_VERSION_1_3_show,
    of_table_feature_prop_experimenter_OF_VERSION_1_3_show,
    of_table_feature_prop_header_OF_VERSION_1_3_show,
    of_table_feature_prop_instructions_OF_VERSION_1_3_show,
    of_table_feature_prop_instructions_miss_OF_VERSION_1_3_show,
    of_table_feature_prop_match_OF_VERSION_1_3_show,
    of_table_feature_prop_next_tables_OF_VERSION_1_3_show,
    of_table_feature_prop_next_tables_miss_OF_VERSION_1_3_show,
    of_table_feature_prop_wildcards_OF_VERSION_1_3_show,
    of_table_feature_prop_write_actions_OF_VERSION_1_3_show,
    of_table_feature_prop_write_actions_miss_OF_VERSION_1_3_show,
    of_table_feature_prop_write_setfield_OF_VERSION_1_3_show,
    of_table_feature_prop_write_setfield_miss_OF_VERSION_1_3_show,
    of_table_features_OF_VERSION_1_3_show,
    of_table_stats_entry_OF_VERSION_1_3_show,
    of_uint32_OF_VERSION_1_3_show,
    of_uint8_OF_VERSION_1_3_show,
    of_list_action_OF_VERSION_1_3_show,
    of_list_action_id_OF_VERSION_1_3_show,
    of_list_bsn_interface_OF_VERSION_1_3_show,
    of_list_bsn_lacp_stats_entry_OF_VERSION_1_3_show,
    of_list_bucket_OF_VERSION_1_3_show,
    of_list_bucket_counter_OF_VERSION_1_3_show,
    of_list_flow_stats_entry_OF_VERSION_1_3_show,
    of_list_group_desc_stats_entry_OF_VERSION_1_3_show,
    of_list_group_stats_entry_OF_VERSION_1_3_show,
    of_list_hello_elem_OF_VERSION_1_3_show,
    of_list_instruction_OF_VERSION_1_3_show,
    of_list_meter_band_OF_VERSION_1_3_show,
    of_list_meter_band_stats_OF_VERSION_1_3_show,
    of_list_meter_stats_OF_VERSION_1_3_show,
    of_list_oxm_OF_VERSION_1_3_show,
    of_list_packet_queue_OF_VERSION_1_3_show,
    of_list_port_desc_OF_VERSION_1_3_show,
    of_list_port_stats_entry_OF_VERSION_1_3_show,
    of_list_queue_prop_OF_VERSION_1_3_show,
    of_list_queue_stats_entry_OF_VERSION_1_3_show,
    of_list_table_feature_prop_OF_VERSION_1_3_show,
    of_list_table_features_OF_VERSION_1_3_show,
    of_list_table_stats_entry_OF_VERSION_1_3_show,
    of_list_uint32_OF_VERSION_1_3_show,
    of_list_uint8_OF_VERSION_1_3_show
};


static const loci_obj_show_f *const show_funs[5] = {
    NULL,
    show_funs_v1,
    show_funs_v2,
    show_funs_v3,
    show_funs_v4
};

int
of_object_show(loci_writer_f writer, void* cookie, of_object_t *obj)
{
    if ((obj->object_id > 0) && (obj->object_id < OF_OBJECT_COUNT)) {
        if (((obj)->version > 0) && ((obj)->version <= OF_VERSION_1_2)) {
            /* @fixme VERSION */
            return show_funs[obj->version][obj->object_id](writer, cookie, (of_object_t *)obj);
        } else {
            return writer(cookie, "Bad version %d\n", obj->version);
        }
    }
    return writer(cookie, "Bad object id %d\n", obj->object_id);
}
