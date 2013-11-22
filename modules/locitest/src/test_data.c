/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */

/**
 *
 * AUTOMATICALLY GENERATED FILE.  Edits will be lost on regen.
 *
 * Data file tests for all versions.
 */

#include <locitest/test_common.h>


static void
hexdump(const uint8_t *data, int len)
{
    int i = 0, j;
    while (i < len) {
	printf("%02x: ", i);
	for (j = 0; j < 8 && i < len; j++, i++) {
	    printf("%02x ", data[i]);
	}
	printf("\n");
    }
}

static void
show_failure(const uint8_t *a, int a_len, const uint8_t *b, int b_len)
{
    printf("\n--- Expected: (len=%d)\n", a_len);
    hexdump(a, a_len);
    printf("\n--- Actual: (len=%d)\n", b_len);
    hexdump(b, b_len);
}

/* Generated from of10/action_bsn_set_tunnel_dst.data */
static int
test_of10_action_bsn_set_tunnel_dst(void) {
    uint8_t binary[] = {
        0xff, 0xff, 0x00, 0x10, 0x00, 0x5c, 0x16, 0xc7, 
        0x00, 0x00, 0x00, 0x02, 0x12, 0x34, 0x56, 0x78, 
        
    };

    of_object_t *obj;

    obj = of_action_bsn_set_tunnel_dst_new(OF_VERSION_1_0);
    of_action_bsn_set_tunnel_dst_dst_set(obj, 0x12345678);

    if (sizeof(binary) != WBUF_CURRENT_BYTES(OF_OBJECT_TO_WBUF(obj))
        || memcmp(binary, WBUF_BUF(OF_OBJECT_TO_WBUF(obj)), sizeof(binary))) {
	show_failure(binary, sizeof(binary),
		     WBUF_BUF(OF_OBJECT_TO_WBUF(obj)),
		     WBUF_CURRENT_BYTES(OF_OBJECT_TO_WBUF(obj)));
	of_object_delete(obj);
	return TEST_FAIL;
    }

    of_object_delete(obj);
    return TEST_PASS;
}

/* Generated from of10/desc_stats_reply.data */
static int
test_of10_desc_stats_reply(void) {
    uint8_t binary[] = {
        0x01, 0x11, 0x04, 0x2c, 0x00, 0x00, 0x00, 0x03, 
        0x00, 0x00, 0x00, 0x01, 0x54, 0x68, 0x65, 0x20, 
        0x49, 0x6e, 0x64, 0x69, 0x67, 0x6f, 0x2d, 0x32, 
        0x20, 0x43, 0x6f, 0x6d, 0x6d, 0x75, 0x6e, 0x69, 
        0x74, 0x79, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x55, 0x6e, 0x6b, 0x6e, 
        0x6f, 0x77, 0x6e, 0x20, 0x73, 0x65, 0x72, 0x76, 
        0x65, 0x72, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x49, 0x6e, 0x64, 0x69, 
        0x67, 0x6f, 0x2d, 0x32, 0x20, 0x4c, 0x52, 0x49, 
        0x20, 0x70, 0x72, 0x65, 0x2d, 0x72, 0x65, 0x6c, 
        0x65, 0x61, 0x73, 0x65, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x31, 0x31, 0x32, 0x33, 
        0x35, 0x38, 0x31, 0x33, 0x32, 0x31, 0x33, 0x34, 
        0x35, 0x35, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x49, 0x6e, 0x64, 0x69, 
        0x67, 0x6f, 0x2d, 0x32, 0x20, 0x4c, 0x52, 0x49, 
        0x20, 0x66, 0x6f, 0x72, 0x77, 0x61, 0x72, 0x64, 
        0x69, 0x6e, 0x67, 0x20, 0x6d, 0x6f, 0x64, 0x75, 
        0x6c, 0x65, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 
    };

    of_object_t *obj;

    obj = of_desc_stats_reply_new(OF_VERSION_1_0);
    of_desc_stats_reply_xid_set(obj, 3);
    of_desc_stats_reply_flags_set(obj, OF_STATS_REPLY_FLAG_REPLY_MORE);
    {
        of_desc_str_t mfr_desc = "The Indigo-2 Community";
        of_desc_stats_reply_mfr_desc_set(obj, mfr_desc);
    }
    {
        of_desc_str_t hw_desc = "Unknown server";
        of_desc_stats_reply_hw_desc_set(obj, hw_desc);
    }
    {
        of_desc_str_t sw_desc = "Indigo-2 LRI pre-release";
        of_desc_stats_reply_sw_desc_set(obj, sw_desc);
    }
    {
        of_desc_str_t dp_desc = "Indigo-2 LRI forwarding module";
        of_desc_stats_reply_dp_desc_set(obj, dp_desc);
    }
    {
        of_serial_num_t serial_num = "11235813213455";
        of_desc_stats_reply_serial_num_set(obj, serial_num);
    }

    if (sizeof(binary) != WBUF_CURRENT_BYTES(OF_OBJECT_TO_WBUF(obj))
        || memcmp(binary, WBUF_BUF(OF_OBJECT_TO_WBUF(obj)), sizeof(binary))) {
	show_failure(binary, sizeof(binary),
		     WBUF_BUF(OF_OBJECT_TO_WBUF(obj)),
		     WBUF_CURRENT_BYTES(OF_OBJECT_TO_WBUF(obj)));
	of_object_delete(obj);
	return TEST_FAIL;
    }

    of_object_delete(obj);
    return TEST_PASS;
}

/* Generated from of10/echo_request.data */
static int
test_of10_echo_request(void) {
    uint8_t binary[] = {
        0x01, 0x02, 0x00, 0x0b, 0x12, 0x34, 0x56, 0x78, 
        0x61, 0x62, 0x01, 
    };

    of_object_t *obj;

    obj = of_echo_request_new(OF_VERSION_1_0);
    of_echo_request_xid_set(obj, 0x12345678);
    {
        of_octets_t data = { .data=(uint8_t *)"ab\x01", .bytes=3 };
        of_echo_request_data_set(obj, &data);
    }

    if (sizeof(binary) != WBUF_CURRENT_BYTES(OF_OBJECT_TO_WBUF(obj))
        || memcmp(binary, WBUF_BUF(OF_OBJECT_TO_WBUF(obj)), sizeof(binary))) {
	show_failure(binary, sizeof(binary),
		     WBUF_BUF(OF_OBJECT_TO_WBUF(obj)),
		     WBUF_CURRENT_BYTES(OF_OBJECT_TO_WBUF(obj)));
	of_object_delete(obj);
	return TEST_FAIL;
    }

    of_object_delete(obj);
    return TEST_PASS;
}

/* Generated from of10/flow_add.data */
static int
test_of10_flow_add(void) {
    uint8_t binary[] = {
        0x01, 0x0e, 0x00, 0x70, 0x12, 0x34, 0x56, 0x78, 
        0x00, 0x30, 0x00, 0xe2, 0x00, 0x03, 0x01, 0x23, 
        0x45, 0x67, 0x89, 0xab, 0xcd, 0xef, 0x01, 0x23, 
        0x45, 0x67, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0xc0, 0xa8, 0x03, 0x7f, 
        0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 
        0x00, 0x00, 0x00, 0x08, 0xff, 0xfb, 0x00, 0x00, 
        0xff, 0xff, 0x00, 0x10, 0x00, 0x00, 0x23, 0x20, 
        0x00, 0x12, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0xff, 0xff, 0x00, 0x10, 0x00, 0x5c, 0x16, 0xc7, 
        0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 
        
    };

    of_object_t *obj;

    obj = of_flow_add_new(OF_VERSION_1_0);
    of_flow_add_xid_set(obj, 0x12345678);
    of_flow_add_idle_timeout_set(obj, 5);
    of_flow_add_flags_set(obj, 2);
    {
        of_match_t match = { OF_VERSION_1_0 };
        match.fields.in_port = 3;
        match.fields.eth_src = (of_mac_addr_t) { { 0x01, 0x23, 0x45, 0x67, 0x89, 0xab } };
        match.fields.eth_dst = (of_mac_addr_t) { { 0xcd, 0xef, 0x01, 0x23, 0x45, 0x67 } };
        match.fields.eth_type = 0x800;
        match.fields.ipv4_src = 0xc0a8037f;
        match.fields.ipv4_dst = 0xffffffff;
        OF_MATCH_MASK_IN_PORT_EXACT_SET(&match);
        OF_MATCH_MASK_ETH_SRC_EXACT_SET(&match);
        OF_MATCH_MASK_ETH_DST_EXACT_SET(&match);
        OF_MATCH_MASK_ETH_TYPE_EXACT_SET(&match);
        //OF_MATCH_MASK_VLAN_VID_EXACT_SET(&match);
        //OF_MATCH_MASK_VLAN_PCP_EXACT_SET(&match);
        OF_MATCH_MASK_ETH_TYPE_EXACT_SET(&match);
        //OF_MATCH_MASK_IP_DSCP_EXACT_SET(&match);
        //OF_MATCH_MASK_IP_PROTO_EXACT_SET(&match);
        OF_MATCH_MASK_IPV4_SRC_EXACT_SET(&match);
        OF_MATCH_MASK_IPV4_DST_EXACT_SET(&match);
        //OF_MATCH_MASK_TCP_SRC_EXACT_SET(&match);
        //OF_MATCH_MASK_TCP_DST_EXACT_SET(&match);
        of_flow_add_match_set(obj, &match);
    }
    {
        of_list_action_t actions;
        of_flow_add_actions_bind(obj, &actions);
        {
            of_action_t action;
            of_action_output_init(&action.output, OF_VERSION_1_0, -1, 1);
            of_list_action_append_bind(&actions, &action);
            of_action_output_port_set(&action.output, OF_PORT_DEST_FLOOD);
        }
        {
            of_action_t action;
            of_action_nicira_dec_ttl_init(&action.nicira_dec_ttl, OF_VERSION_1_0, -1, 1);
            of_list_action_append_bind(&actions, &action);
        }
        {
            of_action_t action;
            of_action_bsn_set_tunnel_dst_init(&action.bsn_set_tunnel_dst, OF_VERSION_1_0, -1, 1);
            of_list_action_append_bind(&actions, &action);
        }
    }

    if (sizeof(binary) != WBUF_CURRENT_BYTES(OF_OBJECT_TO_WBUF(obj))
        || memcmp(binary, WBUF_BUF(OF_OBJECT_TO_WBUF(obj)), sizeof(binary))) {
	show_failure(binary, sizeof(binary),
		     WBUF_BUF(OF_OBJECT_TO_WBUF(obj)),
		     WBUF_CURRENT_BYTES(OF_OBJECT_TO_WBUF(obj)));
	of_object_delete(obj);
	return TEST_FAIL;
    }

    of_object_delete(obj);
    return TEST_PASS;
}

/* Generated from of10/flow_stats_entry.data */
static int
test_of10_flow_stats_entry(void) {
    uint8_t binary[] = {
        0x00, 0x68, 0x03, 0x00, 0x00, 0x30, 0x00, 0xe2, 
        0x00, 0x03, 0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 
        0xcd, 0xef, 0x01, 0x23, 0x45, 0x67, 0x00, 0x00, 
        0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0xc0, 0xa8, 0x03, 0x7f, 0xff, 0xff, 0xff, 0xff, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 
        0x00, 0x00, 0x00, 0x02, 0x00, 0x64, 0x00, 0x05, 
        0x00, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0a, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xe8, 
        0x00, 0x00, 0x00, 0x08, 0x00, 0x01, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x08, 0x00, 0x02, 0x00, 0x00, 
        
    };

    of_object_t *obj;

    obj = of_flow_stats_entry_new(OF_VERSION_1_0);
    {
        of_object_t list;
        of_flow_stats_entry_actions_bind(obj, &list);
        {
            of_object_t *obj = of_action_output_new(OF_VERSION_1_0);
            of_action_output_max_len_set(obj, 0);
            of_action_output_port_set(obj, 1);
            of_list_append(&list, obj);
            of_object_delete(obj);
        }
        {
            of_object_t *obj = of_action_output_new(OF_VERSION_1_0);
            of_action_output_max_len_set(obj, 0);
            of_action_output_port_set(obj, 2);
            of_list_append(&list, obj);
            of_object_delete(obj);
        }
    }
    of_flow_stats_entry_byte_count_set(obj, 1000);
    of_flow_stats_entry_cookie_set(obj, 81985529216486895);
    of_flow_stats_entry_duration_nsec_set(obj, 2);
    of_flow_stats_entry_duration_sec_set(obj, 1);
    of_flow_stats_entry_hard_timeout_set(obj, 10);
    of_flow_stats_entry_idle_timeout_set(obj, 5);
    {
        of_match_t match = { OF_VERSION_1_0 };
        match.fields.in_port = 3;
        match.fields.eth_src = (of_mac_addr_t) { { 0x01, 0x23, 0x45, 0x67, 0x89, 0xab } };
        match.fields.eth_dst = (of_mac_addr_t) { { 0xcd, 0xef, 0x01, 0x23, 0x45, 0x67 } };
        match.fields.eth_type = 0x800;
        match.fields.ipv4_src = 0xc0a8037f;
        match.fields.ipv4_dst = 0xffffffff;
        OF_MATCH_MASK_IN_PORT_EXACT_SET(&match);
        OF_MATCH_MASK_ETH_SRC_EXACT_SET(&match);
        OF_MATCH_MASK_ETH_DST_EXACT_SET(&match);
        OF_MATCH_MASK_ETH_TYPE_EXACT_SET(&match);
        //OF_MATCH_MASK_VLAN_VID_EXACT_SET(&match);
        //OF_MATCH_MASK_VLAN_PCP_EXACT_SET(&match);
        OF_MATCH_MASK_ETH_TYPE_EXACT_SET(&match);
        //OF_MATCH_MASK_IP_DSCP_EXACT_SET(&match);
        //OF_MATCH_MASK_IP_PROTO_EXACT_SET(&match);
        OF_MATCH_MASK_IPV4_SRC_EXACT_SET(&match);
        OF_MATCH_MASK_IPV4_DST_EXACT_SET(&match);
        //OF_MATCH_MASK_TCP_SRC_EXACT_SET(&match);
        //OF_MATCH_MASK_TCP_DST_EXACT_SET(&match);
        of_flow_stats_entry_match_set(obj, &match);
    }
    of_flow_stats_entry_packet_count_set(obj, 10);
    of_flow_stats_entry_priority_set(obj, 100);
    of_flow_stats_entry_table_id_set(obj, 3);

    if (sizeof(binary) != WBUF_CURRENT_BYTES(OF_OBJECT_TO_WBUF(obj))
        || memcmp(binary, WBUF_BUF(OF_OBJECT_TO_WBUF(obj)), sizeof(binary))) {
	show_failure(binary, sizeof(binary),
		     WBUF_BUF(OF_OBJECT_TO_WBUF(obj)),
		     WBUF_CURRENT_BYTES(OF_OBJECT_TO_WBUF(obj)));
	of_object_delete(obj);
	return TEST_FAIL;
    }

    of_object_delete(obj);
    return TEST_PASS;
}

/* Generated from of10/flow_stats_reply.data */
static int
test_of10_flow_stats_reply(void) {
    uint8_t binary[] = {
        0x01, 0x11, 0x00, 0xe4, 0x00, 0x00, 0x00, 0x06, 
        0x00, 0x01, 0x00, 0x00, 0x00, 0x68, 0x03, 0x00, 
        0x00, 0x3f, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02, 
        0x00, 0x64, 0x00, 0x05, 0x00, 0x0a, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x01, 0x23, 0x45, 0x67, 
        0x89, 0xab, 0xcd, 0xef, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x0a, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x03, 0xe8, 0x00, 0x00, 0x00, 0x08, 
        0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 
        0x00, 0x02, 0x00, 0x00, 0x00, 0x70, 0x04, 0x00, 
        0x00, 0x3f, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02, 
        0x00, 0x64, 0x00, 0x05, 0x00, 0x0a, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x01, 0x23, 0x45, 0x67, 
        0x89, 0xab, 0xcd, 0xef, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x0a, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x03, 0xe8, 0x00, 0x00, 0x00, 0x08, 
        0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 
        0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 
        0x00, 0x03, 0x00, 0x00, 
    };

    of_object_t *obj;

    obj = of_flow_stats_reply_new(OF_VERSION_1_0);
    of_flow_stats_reply_flags_set(obj, 0);
    of_flow_stats_reply_xid_set(obj, 6);
    {
        of_object_t *entries = of_list_flow_stats_entry_new(OF_VERSION_1_0);
        {
            of_object_t *elem = of_flow_stats_entry_new(OF_VERSION_1_0);
            of_flow_stats_entry_byte_count_set(elem, 1000);
            of_flow_stats_entry_cookie_set(elem, 81985529216486895);
            of_flow_stats_entry_duration_nsec_set(elem, 2);
            of_flow_stats_entry_duration_sec_set(elem, 1);
            of_flow_stats_entry_hard_timeout_set(elem, 10);
            of_flow_stats_entry_idle_timeout_set(elem, 5);
            of_flow_stats_entry_packet_count_set(elem, 10);
            of_flow_stats_entry_priority_set(elem, 100);
            of_flow_stats_entry_table_id_set(elem, 3);
            {
                of_match_t match = { OF_VERSION_1_0 };
                of_flow_stats_entry_match_set(elem, &match);
            }
            {
                of_object_t *actions = of_list_action_new(OF_VERSION_1_0);
                {
                    of_object_t *elem = of_action_output_new(OF_VERSION_1_0);
                    of_action_output_max_len_set(elem, 0);
                    of_action_output_port_set(elem, 1);
                    of_list_append(actions, elem);
                    of_object_delete(elem);
                }
                {
                    of_object_t *elem = of_action_output_new(OF_VERSION_1_0);
                    of_action_output_max_len_set(elem, 0);
                    of_action_output_port_set(elem, 2);
                    of_list_append(actions, elem);
                    of_object_delete(elem);
                }
                of_flow_stats_entry_actions_set(elem, actions);
                of_object_delete(actions);
            }
            of_list_append(entries, elem);
            of_object_delete(elem);
        }
        {
            of_object_t *elem = of_flow_stats_entry_new(OF_VERSION_1_0);
            of_flow_stats_entry_byte_count_set(elem, 1000);
            of_flow_stats_entry_cookie_set(elem, 81985529216486895);
            of_flow_stats_entry_duration_nsec_set(elem, 2);
            of_flow_stats_entry_duration_sec_set(elem, 1);
            of_flow_stats_entry_hard_timeout_set(elem, 10);
            of_flow_stats_entry_idle_timeout_set(elem, 5);
            of_flow_stats_entry_packet_count_set(elem, 10);
            of_flow_stats_entry_priority_set(elem, 100);
            of_flow_stats_entry_table_id_set(elem, 4);
            {
                of_match_t match = { OF_VERSION_1_0 };
                of_flow_stats_entry_match_set(elem, &match);
            }
            {
                of_object_t *actions = of_list_action_new(OF_VERSION_1_0);
                {
                    of_object_t *elem = of_action_output_new(OF_VERSION_1_0);
                    of_action_output_max_len_set(elem, 0);
                    of_action_output_port_set(elem, 1);
                    of_list_append(actions, elem);
                    of_object_delete(elem);
                }
                {
                    of_object_t *elem = of_action_output_new(OF_VERSION_1_0);
                    of_action_output_max_len_set(elem, 0);
                    of_action_output_port_set(elem, 2);
                    of_list_append(actions, elem);
                    of_object_delete(elem);
                }
                {
                    of_object_t *elem = of_action_output_new(OF_VERSION_1_0);
                    of_action_output_max_len_set(elem, 0);
                    of_action_output_port_set(elem, 3);
                    of_list_append(actions, elem);
                    of_object_delete(elem);
                }
                of_flow_stats_entry_actions_set(elem, actions);
                of_object_delete(actions);
            }
            of_list_append(entries, elem);
            of_object_delete(elem);
        }
        of_flow_stats_reply_entries_set(obj, entries);
        of_object_delete(entries);
    }

    if (sizeof(binary) != WBUF_CURRENT_BYTES(OF_OBJECT_TO_WBUF(obj))
        || memcmp(binary, WBUF_BUF(OF_OBJECT_TO_WBUF(obj)), sizeof(binary))) {
	show_failure(binary, sizeof(binary),
		     WBUF_BUF(OF_OBJECT_TO_WBUF(obj)),
		     WBUF_CURRENT_BYTES(OF_OBJECT_TO_WBUF(obj)));
	of_object_delete(obj);
	return TEST_FAIL;
    }

    of_object_delete(obj);
    return TEST_PASS;
}

/* Generated from of10/hello.data */
static int
test_of10_hello(void) {
    uint8_t binary[] = {
        0x01, 0x00, 0x00, 0x08, 0x12, 0x34, 0x56, 0x78, 
        
    };

    of_object_t *obj;

    obj = of_hello_new(OF_VERSION_1_0);
    of_hello_xid_set(obj, 305419896);

    if (sizeof(binary) != WBUF_CURRENT_BYTES(OF_OBJECT_TO_WBUF(obj))
        || memcmp(binary, WBUF_BUF(OF_OBJECT_TO_WBUF(obj)), sizeof(binary))) {
	show_failure(binary, sizeof(binary),
		     WBUF_BUF(OF_OBJECT_TO_WBUF(obj)),
		     WBUF_CURRENT_BYTES(OF_OBJECT_TO_WBUF(obj)));
	of_object_delete(obj);
	return TEST_FAIL;
    }

    of_object_delete(obj);
    return TEST_PASS;
}

/* Generated from of10/packet_in.data */
static int
test_of10_packet_in(void) {
    uint8_t binary[] = {
        0x01, 0x0a, 0x00, 0x15, 0x12, 0x34, 0x56, 0x78, 
        0xab, 0xcd, 0xef, 0x01, 0x00, 0x09, 0xff, 0xfe, 
        0x01, 0x00, 0x61, 0x62, 0x63, 
    };

    of_object_t *obj;

    obj = of_packet_in_new(OF_VERSION_1_0);
    of_packet_in_buffer_id_set(obj, 2882400001);
    {
        of_octets_t data = { .bytes=3, .data=(uint8_t *)"\x61\x62\x63" };
        of_packet_in_data_set(obj, &data);
    }
    of_packet_in_in_port_set(obj, 65534);
    of_packet_in_reason_set(obj, 1);
    of_packet_in_total_len_set(obj, 9);
    of_packet_in_xid_set(obj, 305419896);

    if (sizeof(binary) != WBUF_CURRENT_BYTES(OF_OBJECT_TO_WBUF(obj))
        || memcmp(binary, WBUF_BUF(OF_OBJECT_TO_WBUF(obj)), sizeof(binary))) {
	show_failure(binary, sizeof(binary),
		     WBUF_BUF(OF_OBJECT_TO_WBUF(obj)),
		     WBUF_CURRENT_BYTES(OF_OBJECT_TO_WBUF(obj)));
	of_object_delete(obj);
	return TEST_FAIL;
    }

    of_object_delete(obj);
    return TEST_PASS;
}

/* Generated from of10/packet_out.data */
static int
test_of10_packet_out(void) {
    uint8_t binary[] = {
        0x01, 0x0d, 0x00, 0x23, 0x12, 0x34, 0x56, 0x78, 
        0xab, 0xcd, 0xef, 0x01, 0xff, 0xfe, 0x00, 0x10, 
        0x00, 0x00, 0x00, 0x08, 0x00, 0x01, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x08, 0x00, 0x02, 0x00, 0x00, 
        0x61, 0x62, 0x63, 
    };

    of_object_t *obj;

    obj = of_packet_out_new(OF_VERSION_1_0);
    of_packet_out_buffer_id_set(obj, 2882400001);
    of_packet_out_in_port_set(obj, 65534);
    of_packet_out_xid_set(obj, 305419896);
    {
        of_object_t *list = of_list_action_new(OF_VERSION_1_0);
        {
            of_object_t *obj = of_action_output_new(OF_VERSION_1_0);
            of_action_output_max_len_set(obj, 0);
            of_action_output_port_set(obj, 1);
            of_list_append(list, obj);
            of_object_delete(obj);
        }
        {
            of_object_t *obj = of_action_output_new(OF_VERSION_1_0);
            of_action_output_max_len_set(obj, 0);
            of_action_output_port_set(obj, 2);
            of_list_append(list, obj);
            of_object_delete(obj);
        }
        of_packet_out_actions_set(obj, list);
        of_object_delete(list);
    }
    {
        of_octets_t data = { .bytes=3, .data=(uint8_t *)"\x61\x62\x63" };
        of_packet_out_data_set(obj, &data);
    }

    if (sizeof(binary) != WBUF_CURRENT_BYTES(OF_OBJECT_TO_WBUF(obj))
        || memcmp(binary, WBUF_BUF(OF_OBJECT_TO_WBUF(obj)), sizeof(binary))) {
	show_failure(binary, sizeof(binary),
		     WBUF_BUF(OF_OBJECT_TO_WBUF(obj)),
		     WBUF_CURRENT_BYTES(OF_OBJECT_TO_WBUF(obj)));
	of_object_delete(obj);
	return TEST_FAIL;
    }

    of_object_delete(obj);
    return TEST_PASS;
}

/* Generated from of10/port_desc.data */
static int
test_of10_port_desc(void) {
    uint8_t binary[] = {
        0xff, 0xfd, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 
        0x66, 0x6f, 0x6f, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x02, 0x00, 
        0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x20, 
        0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x08, 0x00, 
        
    };

    of_object_t *obj;

    obj = of_port_desc_new(OF_VERSION_1_0);
    of_port_desc_advertised_set(obj, 32);
    of_port_desc_config_set(obj, 16);
    of_port_desc_curr_set(obj, 1);
    {
        of_mac_addr_t hw_addr = { { 1, 2, 3, 4, 5, 6 } };
        of_port_desc_hw_addr_set(obj, hw_addr);
    }
    {
        of_port_name_t name = "foo";
        of_port_desc_name_set(obj, name);
    }
    of_port_desc_peer_set(obj, 2048);
    of_port_desc_port_no_set(obj, 65533);
    of_port_desc_state_set(obj, 512);
    of_port_desc_supported_set(obj, 512);

    if (sizeof(binary) != WBUF_CURRENT_BYTES(OF_OBJECT_TO_WBUF(obj))
        || memcmp(binary, WBUF_BUF(OF_OBJECT_TO_WBUF(obj)), sizeof(binary))) {
	show_failure(binary, sizeof(binary),
		     WBUF_BUF(OF_OBJECT_TO_WBUF(obj)),
		     WBUF_CURRENT_BYTES(OF_OBJECT_TO_WBUF(obj)));
	of_object_delete(obj);
	return TEST_FAIL;
    }

    of_object_delete(obj);
    return TEST_PASS;
}

/* Generated from of10/port_mod.data */
static int
test_of10_port_mod(void) {
    uint8_t binary[] = {
        0x01, 0x0f, 0x00, 0x20, 0x00, 0x00, 0x00, 0x02, 
        0xff, 0xfd, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 
        0x90, 0xab, 0xcd, 0xef, 0xff, 0x11, 0xff, 0x11, 
        0xca, 0xfe, 0x67, 0x89, 0x00, 0x00, 0x00, 0x00, 
        
    };

    of_object_t *obj;

    obj = of_port_mod_new(OF_VERSION_1_0);
    of_port_mod_advertise_set(obj, 3405670281);
    of_port_mod_config_set(obj, 2427178479);
    {
        of_mac_addr_t hw_addr = { { 1, 2, 3, 4, 5, 6 } };
        of_port_mod_hw_addr_set(obj, hw_addr);
    }
    of_port_mod_mask_set(obj, 4279369489);
    of_port_mod_port_no_set(obj, 65533);
    of_port_mod_xid_set(obj, 2);

    if (sizeof(binary) != WBUF_CURRENT_BYTES(OF_OBJECT_TO_WBUF(obj))
        || memcmp(binary, WBUF_BUF(OF_OBJECT_TO_WBUF(obj)), sizeof(binary))) {
	show_failure(binary, sizeof(binary),
		     WBUF_BUF(OF_OBJECT_TO_WBUF(obj)),
		     WBUF_CURRENT_BYTES(OF_OBJECT_TO_WBUF(obj)));
	of_object_delete(obj);
	return TEST_FAIL;
    }

    of_object_delete(obj);
    return TEST_PASS;
}

/* Generated from of10/port_stats_reply.data */
static int
test_of10_port_stats_reply(void) {
    uint8_t binary[] = {
        0x01, 0x11, 0x00, 0xdc, 0x00, 0x00, 0x00, 0x05, 
        0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x05, 0xff, 0xfe, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x01, 
    };

    of_object_t *obj;

    obj = of_port_stats_reply_new(OF_VERSION_1_0);
    {
        of_object_t list;
        of_port_stats_reply_entries_bind(obj, &list);
        {
            of_object_t *obj = of_port_stats_entry_new(OF_VERSION_1_0);
            of_port_stats_entry_collisions_set(obj, 5);
            of_port_stats_entry_port_no_set(obj, 1);
            of_port_stats_entry_rx_bytes_set(obj, 0);
            of_port_stats_entry_rx_crc_err_set(obj, 0);
            of_port_stats_entry_rx_dropped_set(obj, 0);
            of_port_stats_entry_rx_errors_set(obj, 0);
            of_port_stats_entry_rx_frame_err_set(obj, 0);
            of_port_stats_entry_rx_over_err_set(obj, 0);
            of_port_stats_entry_rx_packets_set(obj, 56);
            of_port_stats_entry_tx_bytes_set(obj, 0);
            of_port_stats_entry_tx_dropped_set(obj, 0);
            of_port_stats_entry_tx_errors_set(obj, 0);
            of_port_stats_entry_tx_packets_set(obj, 0);
            of_list_append(&list, obj);
            of_object_delete(obj);
        }
        {
            of_object_t *obj = of_port_stats_entry_new(OF_VERSION_1_0);
            of_port_stats_entry_collisions_set(obj, 1);
            of_port_stats_entry_port_no_set(obj, 65534);
            of_port_stats_entry_rx_bytes_set(obj, 0);
            of_port_stats_entry_rx_crc_err_set(obj, 0);
            of_port_stats_entry_rx_dropped_set(obj, 0);
            of_port_stats_entry_rx_errors_set(obj, 0);
            of_port_stats_entry_rx_frame_err_set(obj, 0);
            of_port_stats_entry_rx_over_err_set(obj, 0);
            of_port_stats_entry_rx_packets_set(obj, 1);
            of_port_stats_entry_tx_bytes_set(obj, 0);
            of_port_stats_entry_tx_dropped_set(obj, 0);
            of_port_stats_entry_tx_errors_set(obj, 0);
            of_port_stats_entry_tx_packets_set(obj, 0);
            of_list_append(&list, obj);
            of_object_delete(obj);
        }
    }
    of_port_stats_reply_flags_set(obj, 0);
    of_port_stats_reply_xid_set(obj, 5);

    if (sizeof(binary) != WBUF_CURRENT_BYTES(OF_OBJECT_TO_WBUF(obj))
        || memcmp(binary, WBUF_BUF(OF_OBJECT_TO_WBUF(obj)), sizeof(binary))) {
	show_failure(binary, sizeof(binary),
		     WBUF_BUF(OF_OBJECT_TO_WBUF(obj)),
		     WBUF_CURRENT_BYTES(OF_OBJECT_TO_WBUF(obj)));
	of_object_delete(obj);
	return TEST_FAIL;
    }

    of_object_delete(obj);
    return TEST_PASS;
}

/* Generated from of10/port_status.data */
static int
test_of10_port_status(void) {
    uint8_t binary[] = {
        0x01, 0x0c, 0x00, 0x40, 0x00, 0x00, 0x00, 0x04, 
        0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0xff, 0xfd, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 
        0x66, 0x6f, 0x6f, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x02, 0x00, 
        0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x20, 
        0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x08, 0x00, 
        
    };

    of_object_t *obj;

    obj = of_port_status_new(OF_VERSION_1_0);
    {
        of_object_t *desc = of_port_desc_new(OF_VERSION_1_0);
        of_port_desc_advertised_set(desc, 32);
        of_port_desc_config_set(desc, 16);
        of_port_desc_curr_set(desc, 1);
        {
    	of_mac_addr_t hw_addr = { { 1, 2, 3, 4, 5, 6 } };
    	of_port_desc_hw_addr_set(desc, hw_addr);
        }
        {
    	of_port_name_t name = "foo";
    	of_port_desc_name_set(desc, name);
        }
        of_port_desc_peer_set(desc, 2048);
        of_port_desc_port_no_set(desc, 65533);
        of_port_desc_state_set(desc, 512);
        of_port_desc_supported_set(desc, 512);
        of_port_status_desc_set(obj, desc);
        of_object_delete(desc);
    }
    of_port_status_reason_set(obj, 1);
    of_port_status_xid_set(obj, 4);

    if (sizeof(binary) != WBUF_CURRENT_BYTES(OF_OBJECT_TO_WBUF(obj))
        || memcmp(binary, WBUF_BUF(OF_OBJECT_TO_WBUF(obj)), sizeof(binary))) {
	show_failure(binary, sizeof(binary),
		     WBUF_BUF(OF_OBJECT_TO_WBUF(obj)),
		     WBUF_CURRENT_BYTES(OF_OBJECT_TO_WBUF(obj)));
	of_object_delete(obj);
	return TEST_FAIL;
    }

    of_object_delete(obj);
    return TEST_PASS;
}

/* Generated from of10/queue_get_config_reply.data */
static int
test_of10_queue_get_config_reply(void) {
    uint8_t binary[] = {
        0x01, 0x15, 0x00, 0x50, 0x12, 0x34, 0x56, 0x78, 
        0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x01, 0x00, 0x18, 0x00, 0x00, 
        0x00, 0x01, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x02, 0x00, 0x28, 0x00, 0x00, 
        0x00, 0x01, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x01, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        
    };

    of_object_t *obj;

    obj = of_queue_get_config_reply_new(OF_VERSION_1_0);
    of_queue_get_config_reply_port_set(obj, 65534);
    {
        of_object_t list;
        of_queue_get_config_reply_queues_bind(obj, &list);
        {
            of_object_t *obj = of_packet_queue_new(OF_VERSION_1_0);
            {
                of_object_t list;
                of_packet_queue_properties_bind(obj, &list);
                {
                    of_object_t *obj = of_queue_prop_min_rate_new(OF_VERSION_1_0);
                    of_queue_prop_min_rate_rate_set(obj, 5);
                    of_list_append(&list, obj);
                    of_object_delete(obj);
                }
            }
            of_packet_queue_queue_id_set(obj, 1);
            of_list_append(&list, obj);
            of_object_delete(obj);
        }
        {
            of_object_t *obj = of_packet_queue_new(OF_VERSION_1_0);
            {
                of_object_t list;
                of_packet_queue_properties_bind(obj, &list);
                {
                    of_object_t *obj = of_queue_prop_min_rate_new(OF_VERSION_1_0);
                    of_queue_prop_min_rate_rate_set(obj, 6);
                    of_list_append(&list, obj);
                    of_object_delete(obj);
                }
                {
                    of_object_t *obj = of_queue_prop_min_rate_new(OF_VERSION_1_0);
                    of_queue_prop_min_rate_rate_set(obj, 7);
                    of_list_append(&list, obj);
                    of_object_delete(obj);
                }
            }
            of_packet_queue_queue_id_set(obj, 2);
            of_list_append(&list, obj);
            of_object_delete(obj);
        }
    }
    of_queue_get_config_reply_xid_set(obj, 305419896);

    if (sizeof(binary) != WBUF_CURRENT_BYTES(OF_OBJECT_TO_WBUF(obj))
        || memcmp(binary, WBUF_BUF(OF_OBJECT_TO_WBUF(obj)), sizeof(binary))) {
	show_failure(binary, sizeof(binary),
		     WBUF_BUF(OF_OBJECT_TO_WBUF(obj)),
		     WBUF_CURRENT_BYTES(OF_OBJECT_TO_WBUF(obj)));
	of_object_delete(obj);
	return TEST_FAIL;
    }

    of_object_delete(obj);
    return TEST_PASS;
}

/* Generated from of10/table_stats_entry.data */
static int
test_of10_table_stats_entry(void) {
    uint8_t binary[] = {
        0x03, 0x00, 0x00, 0x00, 0x66, 0x6f, 0x6f, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 
        0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x02, 
        0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0x81, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
        
    };

    of_object_t *obj;

    obj = of_table_stats_entry_new(OF_VERSION_1_0);
    of_table_stats_entry_active_count_set(obj, 2);
    of_table_stats_entry_lookup_count_set(obj, 1099511627775ULL);
    of_table_stats_entry_matched_count_set(obj, 9300233470495232273ULL);
    of_table_stats_entry_max_entries_set(obj, 5);
    {
        of_table_name_t name = "foo";
        of_table_stats_entry_name_set(obj, name);
    }
    of_table_stats_entry_table_id_set(obj, 3);
    of_table_stats_entry_wildcards_set(obj, 4194303);

    if (sizeof(binary) != WBUF_CURRENT_BYTES(OF_OBJECT_TO_WBUF(obj))
        || memcmp(binary, WBUF_BUF(OF_OBJECT_TO_WBUF(obj)), sizeof(binary))) {
	show_failure(binary, sizeof(binary),
		     WBUF_BUF(OF_OBJECT_TO_WBUF(obj)),
		     WBUF_CURRENT_BYTES(OF_OBJECT_TO_WBUF(obj)));
	of_object_delete(obj);
	return TEST_FAIL;
    }

    of_object_delete(obj);
    return TEST_PASS;
}

/* Generated from of13/bad_match_error_msg.data */
static int
test_of13_bad_match_error_msg(void) {
    uint8_t binary[] = {
        0x04, 0x01, 0x00, 0x0f, 0x12, 0x34, 0x56, 0x78, 
        0x00, 0x04, 0x00, 0x08, 0x61, 0x62, 0x63, 
    };

    of_object_t *obj;

    obj = of_bad_match_error_msg_new(OF_VERSION_1_3);
    of_bad_match_error_msg_xid_set(obj, 0x12345678);
    of_bad_match_error_msg_code_set(obj, OF_MATCH_FAILED_BAD_MASK_BY_VERSION(OF_VERSION_1_3));
    of_octets_t data = { .bytes=3, .data=(uint8_t *)"\x61\x62\x63" };
    of_bad_match_error_msg_data_set(obj, &data);

    if (sizeof(binary) != WBUF_CURRENT_BYTES(OF_OBJECT_TO_WBUF(obj))
        || memcmp(binary, WBUF_BUF(OF_OBJECT_TO_WBUF(obj)), sizeof(binary))) {
	show_failure(binary, sizeof(binary),
		     WBUF_BUF(OF_OBJECT_TO_WBUF(obj)),
		     WBUF_CURRENT_BYTES(OF_OBJECT_TO_WBUF(obj)));
	of_object_delete(obj);
	return TEST_FAIL;
    }

    of_object_delete(obj);
    return TEST_PASS;
}

/* Generated from of13/bad_request_error_msg.data */
static int
test_of13_bad_request_error_msg(void) {
    uint8_t binary[] = {
        0x04, 0x01, 0x00, 0x0f, 0x12, 0x34, 0x56, 0x78, 
        0x00, 0x01, 0x00, 0x08, 0x61, 0x62, 0x63, 
    };

    of_object_t *obj;

    obj = of_bad_request_error_msg_new(OF_VERSION_1_3);
    of_bad_request_error_msg_xid_set(obj, 0x12345678);
    of_bad_request_error_msg_code_set(obj, OF_REQUEST_FAILED_BUFFER_UNKNOWN_BY_VERSION(OF_VERSION_1_3));
    of_octets_t data = { .bytes=3, .data=(uint8_t *)"\x61\x62\x63" };
    of_bad_request_error_msg_data_set(obj, &data);

    if (sizeof(binary) != WBUF_CURRENT_BYTES(OF_OBJECT_TO_WBUF(obj))
        || memcmp(binary, WBUF_BUF(OF_OBJECT_TO_WBUF(obj)), sizeof(binary))) {
	show_failure(binary, sizeof(binary),
		     WBUF_BUF(OF_OBJECT_TO_WBUF(obj)),
		     WBUF_CURRENT_BYTES(OF_OBJECT_TO_WBUF(obj)));
	of_object_delete(obj);
	return TEST_FAIL;
    }

    of_object_delete(obj);
    return TEST_PASS;
}

/* Generated from of13/bsn_flow_idle.data */
static int
test_of13_bsn_flow_idle(void) {
    uint8_t binary[] = {
        0x04, 0x04, 0x00, 0x38, 0x12, 0x34, 0x56, 0x78, 
        0x00, 0x5c, 0x16, 0xc7, 0x00, 0x00, 0x00, 0x28, 
        0xfe, 0xdc, 0xba, 0x98, 0x76, 0x54, 0x32, 0x10, 
        0x42, 0x68, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x01, 0x00, 0x16, 0x80, 0x00, 0x01, 0x08, 
        0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x05, 
        0x80, 0x00, 0x2a, 0x02, 0x00, 0x01, 0x00, 0x00, 
        
    };

    of_object_t *obj;

    obj = of_bsn_flow_idle_new(OF_VERSION_1_3);
    of_bsn_flow_idle_xid_set(obj, 0x12345678);
    of_bsn_flow_idle_cookie_set(obj, 0xFEDCBA9876543210);
    of_bsn_flow_idle_priority_set(obj, 17000);
    of_bsn_flow_idle_table_id_set(obj, 20);
    {
        of_match_t match = { OF_VERSION_1_3 };
        match.fields.in_port = 4;
        match.masks.in_port = 5;
        match.fields.arp_op = 1;
        OF_MATCH_MASK_ARP_OP_EXACT_SET(&match);
        of_bsn_flow_idle_match_set(obj, &match);
    }

    if (sizeof(binary) != WBUF_CURRENT_BYTES(OF_OBJECT_TO_WBUF(obj))
        || memcmp(binary, WBUF_BUF(OF_OBJECT_TO_WBUF(obj)), sizeof(binary))) {
	show_failure(binary, sizeof(binary),
		     WBUF_BUF(OF_OBJECT_TO_WBUF(obj)),
		     WBUF_CURRENT_BYTES(OF_OBJECT_TO_WBUF(obj)));
	of_object_delete(obj);
	return TEST_FAIL;
    }

    of_object_delete(obj);
    return TEST_PASS;
}

/* Generated from of13/bsn_lacp_stats_reply.data */
static int
test_of13_bsn_lacp_stats_reply(void) {
    uint8_t binary[] = {
        0x04, 0x13, 0x00, 0x3c, 0x12, 0x34, 0x56, 0x78, 
        0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x5c, 0x16, 0xc7, 0x00, 0x00, 0x00, 0x01, 
        0x00, 0x00, 0xf1, 0x11, 0xf2, 0x22, 0x01, 0x02, 
        0x03, 0x04, 0x05, 0x06, 0xf3, 0x33, 0xf4, 0x44, 
        0xf5, 0x55, 0x02, 0x00, 0xf6, 0x66, 0x0a, 0x0b, 
        0x0c, 0x0d, 0x0e, 0x0f, 0xf7, 0x77, 0xf8, 0x88, 
        0xf9, 0x99, 0x00, 0x00, 
    };

    of_object_t *obj;

    obj = of_bsn_lacp_stats_reply_new(OF_VERSION_1_3);
    of_bsn_lacp_stats_reply_xid_set(obj, 0x12345678);
    {
        of_object_t *entries = of_list_bsn_lacp_stats_entry_new(OF_VERSION_1_3);
        {
            of_object_t *elem = of_bsn_lacp_stats_entry_new(OF_VERSION_1_3);
            of_bsn_lacp_stats_entry_port_no_set(elem, 0xf111);
            of_bsn_lacp_stats_entry_actor_sys_priority_set(elem, 0xf222);
            {
                of_mac_addr_t mac = { { 1, 2, 3, 4, 5, 6 } };
                of_bsn_lacp_stats_entry_actor_sys_mac_set(elem, mac);
            }
            of_bsn_lacp_stats_entry_actor_port_priority_set(elem, 0xf333);
            of_bsn_lacp_stats_entry_actor_port_num_set(elem, 0xf444);
            of_bsn_lacp_stats_entry_actor_key_set(elem, 0xf555);
            of_bsn_lacp_stats_entry_partner_sys_priority_set(elem, 0xf666);
            of_bsn_lacp_stats_entry_convergence_status_set(elem, LACP_OUT_OF_SYNC);
            {
                of_mac_addr_t mac = { { 0xa, 0xb, 0xc, 0xd, 0xe, 0xf } };
                of_bsn_lacp_stats_entry_partner_sys_mac_set(elem, mac);
            }
            of_bsn_lacp_stats_entry_partner_port_priority_set(elem, 0xf777);
            of_bsn_lacp_stats_entry_partner_port_num_set(elem, 0xf888);
            of_bsn_lacp_stats_entry_partner_key_set(elem, 0xf999);
            of_list_append(entries, elem);
            of_object_delete(elem);
        }
        of_bsn_lacp_stats_reply_entries_set(obj, entries);
        of_object_delete(entries);
    }

    if (sizeof(binary) != WBUF_CURRENT_BYTES(OF_OBJECT_TO_WBUF(obj))
        || memcmp(binary, WBUF_BUF(OF_OBJECT_TO_WBUF(obj)), sizeof(binary))) {
	show_failure(binary, sizeof(binary),
		     WBUF_BUF(OF_OBJECT_TO_WBUF(obj)),
		     WBUF_CURRENT_BYTES(OF_OBJECT_TO_WBUF(obj)));
	of_object_delete(obj);
	return TEST_FAIL;
    }

    of_object_delete(obj);
    return TEST_PASS;
}

/* Generated from of13/bsn_lacp_stats_request.data */
static int
test_of13_bsn_lacp_stats_request(void) {
    uint8_t binary[] = {
        0x04, 0x12, 0x00, 0x18, 0x12, 0x34, 0x56, 0x78, 
        0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x5c, 0x16, 0xc7, 0x00, 0x00, 0x00, 0x01, 
        
    };

    of_object_t *obj;

    obj = of_bsn_lacp_stats_request_new(OF_VERSION_1_3);
    of_bsn_lacp_stats_request_xid_set(obj, 0x12345678);

    if (sizeof(binary) != WBUF_CURRENT_BYTES(OF_OBJECT_TO_WBUF(obj))
        || memcmp(binary, WBUF_BUF(OF_OBJECT_TO_WBUF(obj)), sizeof(binary))) {
	show_failure(binary, sizeof(binary),
		     WBUF_BUF(OF_OBJECT_TO_WBUF(obj)),
		     WBUF_CURRENT_BYTES(OF_OBJECT_TO_WBUF(obj)));
	of_object_delete(obj);
	return TEST_FAIL;
    }

    of_object_delete(obj);
    return TEST_PASS;
}

/* Generated from of13/instruction_bsn_disable_src_mac_check.data */
static int
test_of13_instruction_bsn_disable_src_mac_check(void) {
    uint8_t binary[] = {
        0xff, 0xff, 0x00, 0x10, 0x00, 0x5c, 0x16, 0xc7, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        
    };

    of_object_t *obj;

    obj = of_instruction_bsn_disable_src_mac_check_new(OF_VERSION_1_3);

    if (sizeof(binary) != WBUF_CURRENT_BYTES(OF_OBJECT_TO_WBUF(obj))
        || memcmp(binary, WBUF_BUF(OF_OBJECT_TO_WBUF(obj)), sizeof(binary))) {
	show_failure(binary, sizeof(binary),
		     WBUF_BUF(OF_OBJECT_TO_WBUF(obj)),
		     WBUF_CURRENT_BYTES(OF_OBJECT_TO_WBUF(obj)));
	of_object_delete(obj);
	return TEST_FAIL;
    }

    of_object_delete(obj);
    return TEST_PASS;
}

/* Generated from of13/oxm_bsn_global_vrf_allowed.data */
static int
test_of13_oxm_bsn_global_vrf_allowed(void) {
    uint8_t binary[] = {
        0x00, 0x03, 0x06, 0x01, 0x01, 
    };

    of_object_t *obj;

    obj = of_oxm_bsn_global_vrf_allowed_new(OF_VERSION_1_3);
    of_oxm_bsn_global_vrf_allowed_value_set(obj, 1);

    if (sizeof(binary) != WBUF_CURRENT_BYTES(OF_OBJECT_TO_WBUF(obj))
        || memcmp(binary, WBUF_BUF(OF_OBJECT_TO_WBUF(obj)), sizeof(binary))) {
	show_failure(binary, sizeof(binary),
		     WBUF_BUF(OF_OBJECT_TO_WBUF(obj)),
		     WBUF_CURRENT_BYTES(OF_OBJECT_TO_WBUF(obj)));
	of_object_delete(obj);
	return TEST_FAIL;
    }

    of_object_delete(obj);
    return TEST_PASS;
}

/* Generated from of13/oxm_bsn_in_ports_masked_128.data */
static int
test_of13_oxm_bsn_in_ports_masked_128(void) {
    uint8_t binary[] = {
        0x00, 0x03, 0x01, 0x20, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xfe, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xfd, 0xff, 0xfe, 
    };

    of_object_t *obj;

    obj = of_oxm_bsn_in_ports_128_masked_new(OF_VERSION_1_3);
    {
        of_bitmap_128_t bmap = { 0, 0 };
        of_oxm_bsn_in_ports_128_masked_value_set(obj, bmap);
    }
    {
        of_bitmap_128_t bmap = { 0xfffffffeffffffff , 0xfffffffffffdfffe };
        of_oxm_bsn_in_ports_128_masked_value_mask_set(obj, bmap);
    }

    if (sizeof(binary) != WBUF_CURRENT_BYTES(OF_OBJECT_TO_WBUF(obj))
        || memcmp(binary, WBUF_BUF(OF_OBJECT_TO_WBUF(obj)), sizeof(binary))) {
	show_failure(binary, sizeof(binary),
		     WBUF_BUF(OF_OBJECT_TO_WBUF(obj)),
		     WBUF_CURRENT_BYTES(OF_OBJECT_TO_WBUF(obj)));
	of_object_delete(obj);
	return TEST_FAIL;
    }

    of_object_delete(obj);
    return TEST_PASS;
}

/* Generated from of13/oxm_bsn_l3_src_class_id.data */
static int
test_of13_oxm_bsn_l3_src_class_id(void) {
    uint8_t binary[] = {
        0x00, 0x03, 0x0a, 0x04, 0x12, 0x34, 0x56, 0x78, 
        
    };

    of_object_t *obj;

    obj = of_oxm_bsn_l3_src_class_id_new(OF_VERSION_1_3);
    of_oxm_bsn_l3_src_class_id_value_set(obj, 0x12345678);

    if (sizeof(binary) != WBUF_CURRENT_BYTES(OF_OBJECT_TO_WBUF(obj))
        || memcmp(binary, WBUF_BUF(OF_OBJECT_TO_WBUF(obj)), sizeof(binary))) {
	show_failure(binary, sizeof(binary),
		     WBUF_BUF(OF_OBJECT_TO_WBUF(obj)),
		     WBUF_CURRENT_BYTES(OF_OBJECT_TO_WBUF(obj)));
	of_object_delete(obj);
	return TEST_FAIL;
    }

    of_object_delete(obj);
    return TEST_PASS;
}

/* Generated from of13/oxm_bsn_lag_id.data */
static int
test_of13_oxm_bsn_lag_id(void) {
    uint8_t binary[] = {
        0x00, 0x03, 0x02, 0x04, 0x12, 0x34, 0x56, 0x78, 
        
    };

    of_object_t *obj;

    obj = of_oxm_bsn_lag_id_new(OF_VERSION_1_3);
    of_oxm_bsn_lag_id_value_set(obj, 0x12345678);

    if (sizeof(binary) != WBUF_CURRENT_BYTES(OF_OBJECT_TO_WBUF(obj))
        || memcmp(binary, WBUF_BUF(OF_OBJECT_TO_WBUF(obj)), sizeof(binary))) {
	show_failure(binary, sizeof(binary),
		     WBUF_BUF(OF_OBJECT_TO_WBUF(obj)),
		     WBUF_CURRENT_BYTES(OF_OBJECT_TO_WBUF(obj)));
	of_object_delete(obj);
	return TEST_FAIL;
    }

    of_object_delete(obj);
    return TEST_PASS;
}


int
test_datafiles(void)
{
    RUN_TEST(of10_action_bsn_set_tunnel_dst);
    RUN_TEST(of10_desc_stats_reply);
    RUN_TEST(of10_echo_request);
    RUN_TEST(of10_flow_add);
    RUN_TEST(of10_flow_stats_entry);
    RUN_TEST(of10_flow_stats_reply);
    RUN_TEST(of10_hello);
    RUN_TEST(of10_packet_in);
    RUN_TEST(of10_packet_out);
    RUN_TEST(of10_port_desc);
    RUN_TEST(of10_port_mod);
    RUN_TEST(of10_port_stats_reply);
    RUN_TEST(of10_port_status);
    RUN_TEST(of10_queue_get_config_reply);
    RUN_TEST(of10_table_stats_entry);
    RUN_TEST(of13_bad_match_error_msg);
    RUN_TEST(of13_bad_request_error_msg);
    RUN_TEST(of13_bsn_flow_idle);
    RUN_TEST(of13_bsn_lacp_stats_reply);
    RUN_TEST(of13_bsn_lacp_stats_request);
    RUN_TEST(of13_instruction_bsn_disable_src_mac_check);
    RUN_TEST(of13_oxm_bsn_global_vrf_allowed);
    RUN_TEST(of13_oxm_bsn_in_ports_masked_128);
    RUN_TEST(of13_oxm_bsn_l3_src_class_id);
    RUN_TEST(of13_oxm_bsn_lag_id);
    return TEST_PASS;
}
