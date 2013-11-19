/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */

/**
 *
 * AUTOMATICALLY GENERATED FILE.  Edits will be lost on regen.
 *
 * Unified simple class instantiation tests for all versions
 */

#include <locitest/test_common.h>

static int
test_of_aggregate_stats_reply_OF_VERSION_1_0(void)
{
    of_aggregate_stats_reply_t *obj;
    obj = of_aggregate_stats_reply_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 36);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_AGGREGATE_STATS_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 36);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_AGGREGATE_STATS_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_aggregate_stats_reply_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_aggregate_stats_reply_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_aggregate_stats_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_aggregate_stats_request_OF_VERSION_1_0(void)
{
    of_aggregate_stats_request_t *obj;
    obj = of_aggregate_stats_request_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 56);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_AGGREGATE_STATS_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 56);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_AGGREGATE_STATS_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_aggregate_stats_request_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_aggregate_stats_request_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_aggregate_stats_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bad_action_error_msg_OF_VERSION_1_0(void)
{
    of_bad_action_error_msg_t *obj;
    obj = of_bad_action_error_msg_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BAD_ACTION_ERROR_MSG);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BAD_ACTION_ERROR_MSG);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bad_action_error_msg_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bad_action_error_msg_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_bad_action_error_msg_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bad_request_error_msg_OF_VERSION_1_0(void)
{
    of_bad_request_error_msg_t *obj;
    obj = of_bad_request_error_msg_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BAD_REQUEST_ERROR_MSG);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BAD_REQUEST_ERROR_MSG);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bad_request_error_msg_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bad_request_error_msg_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_bad_request_error_msg_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_barrier_reply_OF_VERSION_1_0(void)
{
    of_barrier_reply_t *obj;
    obj = of_barrier_reply_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BARRIER_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BARRIER_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_barrier_reply_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_barrier_reply_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_barrier_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_barrier_request_OF_VERSION_1_0(void)
{
    of_barrier_request_t *obj;
    obj = of_barrier_request_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BARRIER_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BARRIER_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_barrier_request_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_barrier_request_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_barrier_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_bw_clear_data_reply_OF_VERSION_1_0(void)
{
    of_bsn_bw_clear_data_reply_t *obj;
    obj = of_bsn_bw_clear_data_reply_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_BW_CLEAR_DATA_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 20);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_BW_CLEAR_DATA_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_bw_clear_data_reply_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_bw_clear_data_reply_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_bsn_bw_clear_data_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_bw_clear_data_request_OF_VERSION_1_0(void)
{
    of_bsn_bw_clear_data_request_t *obj;
    obj = of_bsn_bw_clear_data_request_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_BW_CLEAR_DATA_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_BW_CLEAR_DATA_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_bw_clear_data_request_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_bw_clear_data_request_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_bsn_bw_clear_data_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_bw_enable_get_reply_OF_VERSION_1_0(void)
{
    of_bsn_bw_enable_get_reply_t *obj;
    obj = of_bsn_bw_enable_get_reply_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_BW_ENABLE_GET_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 20);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_BW_ENABLE_GET_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_bw_enable_get_reply_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_bw_enable_get_reply_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_bsn_bw_enable_get_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_bw_enable_get_request_OF_VERSION_1_0(void)
{
    of_bsn_bw_enable_get_request_t *obj;
    obj = of_bsn_bw_enable_get_request_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_BW_ENABLE_GET_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_BW_ENABLE_GET_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_bw_enable_get_request_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_bw_enable_get_request_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_bsn_bw_enable_get_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_bw_enable_set_reply_OF_VERSION_1_0(void)
{
    of_bsn_bw_enable_set_reply_t *obj;
    obj = of_bsn_bw_enable_set_reply_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_BW_ENABLE_SET_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 24);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_BW_ENABLE_SET_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_bw_enable_set_reply_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_bw_enable_set_reply_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_bsn_bw_enable_set_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_bw_enable_set_request_OF_VERSION_1_0(void)
{
    of_bsn_bw_enable_set_request_t *obj;
    obj = of_bsn_bw_enable_set_request_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_BW_ENABLE_SET_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 20);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_BW_ENABLE_SET_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_bw_enable_set_request_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_bw_enable_set_request_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_bsn_bw_enable_set_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_get_interfaces_reply_OF_VERSION_1_0(void)
{
    of_bsn_get_interfaces_reply_t *obj;
    obj = of_bsn_get_interfaces_reply_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GET_INTERFACES_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_GET_INTERFACES_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_get_interfaces_reply_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_get_interfaces_reply_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_bsn_get_interfaces_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_get_interfaces_request_OF_VERSION_1_0(void)
{
    of_bsn_get_interfaces_request_t *obj;
    obj = of_bsn_get_interfaces_request_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GET_INTERFACES_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_GET_INTERFACES_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_get_interfaces_request_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_get_interfaces_request_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_bsn_get_interfaces_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_get_ip_mask_reply_OF_VERSION_1_0(void)
{
    of_bsn_get_ip_mask_reply_t *obj;
    obj = of_bsn_get_ip_mask_reply_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GET_IP_MASK_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 24);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_GET_IP_MASK_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_get_ip_mask_reply_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_get_ip_mask_reply_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_bsn_get_ip_mask_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_get_ip_mask_request_OF_VERSION_1_0(void)
{
    of_bsn_get_ip_mask_request_t *obj;
    obj = of_bsn_get_ip_mask_request_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GET_IP_MASK_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 24);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_GET_IP_MASK_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_get_ip_mask_request_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_get_ip_mask_request_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_bsn_get_ip_mask_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_get_l2_table_reply_OF_VERSION_1_0(void)
{
    of_bsn_get_l2_table_reply_t *obj;
    obj = of_bsn_get_l2_table_reply_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GET_L2_TABLE_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 24);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_GET_L2_TABLE_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_get_l2_table_reply_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_get_l2_table_reply_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_bsn_get_l2_table_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_get_l2_table_request_OF_VERSION_1_0(void)
{
    of_bsn_get_l2_table_request_t *obj;
    obj = of_bsn_get_l2_table_request_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GET_L2_TABLE_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_GET_L2_TABLE_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_get_l2_table_request_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_get_l2_table_request_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_bsn_get_l2_table_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_get_mirroring_reply_OF_VERSION_1_0(void)
{
    of_bsn_get_mirroring_reply_t *obj;
    obj = of_bsn_get_mirroring_reply_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GET_MIRRORING_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 20);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_GET_MIRRORING_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_get_mirroring_reply_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_get_mirroring_reply_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_bsn_get_mirroring_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_get_mirroring_request_OF_VERSION_1_0(void)
{
    of_bsn_get_mirroring_request_t *obj;
    obj = of_bsn_get_mirroring_request_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GET_MIRRORING_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 20);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_GET_MIRRORING_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_get_mirroring_request_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_get_mirroring_request_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_bsn_get_mirroring_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_header_OF_VERSION_1_0(void)
{
    of_bsn_header_t *obj;
    obj = of_bsn_header_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_HEADER);

    of_bsn_header_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_hybrid_get_reply_OF_VERSION_1_0(void)
{
    of_bsn_hybrid_get_reply_t *obj;
    obj = of_bsn_hybrid_get_reply_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_HYBRID_GET_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 24);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_HYBRID_GET_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_hybrid_get_reply_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_hybrid_get_reply_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_bsn_hybrid_get_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_hybrid_get_request_OF_VERSION_1_0(void)
{
    of_bsn_hybrid_get_request_t *obj;
    obj = of_bsn_hybrid_get_request_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_HYBRID_GET_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_HYBRID_GET_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_hybrid_get_request_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_hybrid_get_request_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_bsn_hybrid_get_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_pdu_rx_reply_OF_VERSION_1_0(void)
{
    of_bsn_pdu_rx_reply_t *obj;
    obj = of_bsn_pdu_rx_reply_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 23);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_PDU_RX_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 23);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_PDU_RX_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_pdu_rx_reply_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_pdu_rx_reply_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_bsn_pdu_rx_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_pdu_rx_request_OF_VERSION_1_0(void)
{
    of_bsn_pdu_rx_request_t *obj;
    obj = of_bsn_pdu_rx_request_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 26);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_PDU_RX_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 26);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_PDU_RX_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_pdu_rx_request_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_pdu_rx_request_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_bsn_pdu_rx_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_pdu_rx_timeout_OF_VERSION_1_0(void)
{
    of_bsn_pdu_rx_timeout_t *obj;
    obj = of_bsn_pdu_rx_timeout_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 19);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_PDU_RX_TIMEOUT);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 19);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_PDU_RX_TIMEOUT);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_pdu_rx_timeout_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_pdu_rx_timeout_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_bsn_pdu_rx_timeout_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_pdu_tx_reply_OF_VERSION_1_0(void)
{
    of_bsn_pdu_tx_reply_t *obj;
    obj = of_bsn_pdu_tx_reply_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 23);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_PDU_TX_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 23);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_PDU_TX_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_pdu_tx_reply_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_pdu_tx_reply_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_bsn_pdu_tx_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_pdu_tx_request_OF_VERSION_1_0(void)
{
    of_bsn_pdu_tx_request_t *obj;
    obj = of_bsn_pdu_tx_request_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 26);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_PDU_TX_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 26);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_PDU_TX_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_pdu_tx_request_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_pdu_tx_request_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_bsn_pdu_tx_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_set_ip_mask_OF_VERSION_1_0(void)
{
    of_bsn_set_ip_mask_t *obj;
    obj = of_bsn_set_ip_mask_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_SET_IP_MASK);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 24);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_SET_IP_MASK);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_set_ip_mask_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_set_ip_mask_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_bsn_set_ip_mask_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_set_l2_table_reply_OF_VERSION_1_0(void)
{
    of_bsn_set_l2_table_reply_t *obj;
    obj = of_bsn_set_l2_table_reply_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_SET_L2_TABLE_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 24);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_SET_L2_TABLE_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_set_l2_table_reply_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_set_l2_table_reply_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_bsn_set_l2_table_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_set_l2_table_request_OF_VERSION_1_0(void)
{
    of_bsn_set_l2_table_request_t *obj;
    obj = of_bsn_set_l2_table_request_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_SET_L2_TABLE_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 24);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_SET_L2_TABLE_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_set_l2_table_request_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_set_l2_table_request_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_bsn_set_l2_table_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_set_mirroring_OF_VERSION_1_0(void)
{
    of_bsn_set_mirroring_t *obj;
    obj = of_bsn_set_mirroring_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_SET_MIRRORING);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 20);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_SET_MIRRORING);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_set_mirroring_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_set_mirroring_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_bsn_set_mirroring_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_set_pktin_suppression_reply_OF_VERSION_1_0(void)
{
    of_bsn_set_pktin_suppression_reply_t *obj;
    obj = of_bsn_set_pktin_suppression_reply_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_SET_PKTIN_SUPPRESSION_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 20);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_SET_PKTIN_SUPPRESSION_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_set_pktin_suppression_reply_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_set_pktin_suppression_reply_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_bsn_set_pktin_suppression_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_set_pktin_suppression_request_OF_VERSION_1_0(void)
{
    of_bsn_set_pktin_suppression_request_t *obj;
    obj = of_bsn_set_pktin_suppression_request_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 32);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_SET_PKTIN_SUPPRESSION_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 32);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_SET_PKTIN_SUPPRESSION_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_set_pktin_suppression_request_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_set_pktin_suppression_request_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_bsn_set_pktin_suppression_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_shell_command_OF_VERSION_1_0(void)
{
    of_bsn_shell_command_t *obj;
    obj = of_bsn_shell_command_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_SHELL_COMMAND);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 20);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_SHELL_COMMAND);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_shell_command_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_shell_command_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_bsn_shell_command_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_shell_output_OF_VERSION_1_0(void)
{
    of_bsn_shell_output_t *obj;
    obj = of_bsn_shell_output_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_SHELL_OUTPUT);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_SHELL_OUTPUT);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_shell_output_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_shell_output_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_bsn_shell_output_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_shell_status_OF_VERSION_1_0(void)
{
    of_bsn_shell_status_t *obj;
    obj = of_bsn_shell_status_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_SHELL_STATUS);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 20);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_SHELL_STATUS);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_shell_status_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_shell_status_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_bsn_shell_status_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_stats_reply_OF_VERSION_1_0(void)
{
    of_bsn_stats_reply_t *obj;
    obj = of_bsn_stats_reply_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_STATS_REPLY);

    of_bsn_stats_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_stats_request_OF_VERSION_1_0(void)
{
    of_bsn_stats_request_t *obj;
    obj = of_bsn_stats_request_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_STATS_REQUEST);

    of_bsn_stats_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_virtual_port_create_reply_OF_VERSION_1_0(void)
{
    of_bsn_virtual_port_create_reply_t *obj;
    obj = of_bsn_virtual_port_create_reply_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_VIRTUAL_PORT_CREATE_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 24);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_VIRTUAL_PORT_CREATE_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_virtual_port_create_reply_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_virtual_port_create_reply_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_bsn_virtual_port_create_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_virtual_port_create_request_OF_VERSION_1_0(void)
{
    of_bsn_virtual_port_create_request_t *obj;
    obj = of_bsn_virtual_port_create_request_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 48);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_VIRTUAL_PORT_CREATE_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 48);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_VIRTUAL_PORT_CREATE_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_virtual_port_create_request_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_virtual_port_create_request_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_bsn_virtual_port_create_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_virtual_port_remove_reply_OF_VERSION_1_0(void)
{
    of_bsn_virtual_port_remove_reply_t *obj;
    obj = of_bsn_virtual_port_remove_reply_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_VIRTUAL_PORT_REMOVE_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 20);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_VIRTUAL_PORT_REMOVE_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_virtual_port_remove_reply_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_virtual_port_remove_reply_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_bsn_virtual_port_remove_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_virtual_port_remove_request_OF_VERSION_1_0(void)
{
    of_bsn_virtual_port_remove_request_t *obj;
    obj = of_bsn_virtual_port_remove_request_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_VIRTUAL_PORT_REMOVE_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 20);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_VIRTUAL_PORT_REMOVE_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_virtual_port_remove_request_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_virtual_port_remove_request_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_bsn_virtual_port_remove_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_desc_stats_reply_OF_VERSION_1_0(void)
{
    of_desc_stats_reply_t *obj;
    obj = of_desc_stats_reply_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 1068);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_DESC_STATS_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 1068);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_DESC_STATS_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_desc_stats_reply_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_desc_stats_reply_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_desc_stats_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_desc_stats_request_OF_VERSION_1_0(void)
{
    of_desc_stats_request_t *obj;
    obj = of_desc_stats_request_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_DESC_STATS_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_DESC_STATS_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_desc_stats_request_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_desc_stats_request_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_desc_stats_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_echo_reply_OF_VERSION_1_0(void)
{
    of_echo_reply_t *obj;
    obj = of_echo_reply_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ECHO_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ECHO_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_echo_reply_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_echo_reply_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_echo_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_echo_request_OF_VERSION_1_0(void)
{
    of_echo_request_t *obj;
    obj = of_echo_request_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ECHO_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ECHO_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_echo_request_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_echo_request_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_echo_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_error_msg_OF_VERSION_1_0(void)
{
    of_error_msg_t *obj;
    obj = of_error_msg_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 10);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ERROR_MSG);

    of_error_msg_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_experimenter_OF_VERSION_1_0(void)
{
    of_experimenter_t *obj;
    obj = of_experimenter_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_EXPERIMENTER);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_EXPERIMENTER);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_experimenter_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_experimenter_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_experimenter_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_experimenter_stats_reply_OF_VERSION_1_0(void)
{
    of_experimenter_stats_reply_t *obj;
    obj = of_experimenter_stats_reply_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_EXPERIMENTER_STATS_REPLY);

    of_experimenter_stats_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_experimenter_stats_request_OF_VERSION_1_0(void)
{
    of_experimenter_stats_request_t *obj;
    obj = of_experimenter_stats_request_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_EXPERIMENTER_STATS_REQUEST);

    of_experimenter_stats_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_features_reply_OF_VERSION_1_0(void)
{
    of_features_reply_t *obj;
    obj = of_features_reply_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 32);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FEATURES_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 32);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_FEATURES_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_features_reply_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_features_reply_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_features_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_features_request_OF_VERSION_1_0(void)
{
    of_features_request_t *obj;
    obj = of_features_request_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FEATURES_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_FEATURES_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_features_request_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_features_request_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_features_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_flow_add_OF_VERSION_1_0(void)
{
    of_flow_add_t *obj;
    obj = of_flow_add_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 72);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_ADD);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 72);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_FLOW_ADD);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_flow_add_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_flow_add_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_flow_add_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_flow_delete_OF_VERSION_1_0(void)
{
    of_flow_delete_t *obj;
    obj = of_flow_delete_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 72);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_DELETE);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 72);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_FLOW_DELETE);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_flow_delete_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_flow_delete_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_flow_delete_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_flow_delete_strict_OF_VERSION_1_0(void)
{
    of_flow_delete_strict_t *obj;
    obj = of_flow_delete_strict_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 72);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_DELETE_STRICT);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 72);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_FLOW_DELETE_STRICT);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_flow_delete_strict_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_flow_delete_strict_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_flow_delete_strict_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_flow_mod_OF_VERSION_1_0(void)
{
    of_flow_mod_t *obj;
    obj = of_flow_mod_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 72);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_MOD);

    of_flow_mod_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_flow_mod_failed_error_msg_OF_VERSION_1_0(void)
{
    of_flow_mod_failed_error_msg_t *obj;
    obj = of_flow_mod_failed_error_msg_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_MOD_FAILED_ERROR_MSG);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_FLOW_MOD_FAILED_ERROR_MSG);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_flow_mod_failed_error_msg_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_flow_mod_failed_error_msg_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_flow_mod_failed_error_msg_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_flow_modify_OF_VERSION_1_0(void)
{
    of_flow_modify_t *obj;
    obj = of_flow_modify_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 72);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_MODIFY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 72);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_FLOW_MODIFY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_flow_modify_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_flow_modify_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_flow_modify_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_flow_modify_strict_OF_VERSION_1_0(void)
{
    of_flow_modify_strict_t *obj;
    obj = of_flow_modify_strict_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 72);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_MODIFY_STRICT);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 72);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_FLOW_MODIFY_STRICT);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_flow_modify_strict_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_flow_modify_strict_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_flow_modify_strict_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_flow_removed_OF_VERSION_1_0(void)
{
    of_flow_removed_t *obj;
    obj = of_flow_removed_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 88);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_REMOVED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 88);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_FLOW_REMOVED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_flow_removed_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_flow_removed_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_flow_removed_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_flow_stats_reply_OF_VERSION_1_0(void)
{
    of_flow_stats_reply_t *obj;
    obj = of_flow_stats_reply_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_STATS_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_FLOW_STATS_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_flow_stats_reply_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_flow_stats_reply_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_flow_stats_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_flow_stats_request_OF_VERSION_1_0(void)
{
    of_flow_stats_request_t *obj;
    obj = of_flow_stats_request_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 56);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_STATS_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 56);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_FLOW_STATS_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_flow_stats_request_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_flow_stats_request_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_flow_stats_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_get_config_reply_OF_VERSION_1_0(void)
{
    of_get_config_reply_t *obj;
    obj = of_get_config_reply_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_GET_CONFIG_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_GET_CONFIG_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_get_config_reply_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_get_config_reply_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_get_config_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_get_config_request_OF_VERSION_1_0(void)
{
    of_get_config_request_t *obj;
    obj = of_get_config_request_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_GET_CONFIG_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_GET_CONFIG_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_get_config_request_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_get_config_request_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_get_config_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_hello_OF_VERSION_1_0(void)
{
    of_hello_t *obj;
    obj = of_hello_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_HELLO);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_HELLO);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_hello_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_hello_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_hello_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_hello_failed_error_msg_OF_VERSION_1_0(void)
{
    of_hello_failed_error_msg_t *obj;
    obj = of_hello_failed_error_msg_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_HELLO_FAILED_ERROR_MSG);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_HELLO_FAILED_ERROR_MSG);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_hello_failed_error_msg_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_hello_failed_error_msg_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_hello_failed_error_msg_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_nicira_controller_role_reply_OF_VERSION_1_0(void)
{
    of_nicira_controller_role_reply_t *obj;
    obj = of_nicira_controller_role_reply_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_NICIRA_CONTROLLER_ROLE_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 20);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_NICIRA_CONTROLLER_ROLE_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_nicira_controller_role_reply_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_nicira_controller_role_reply_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_nicira_controller_role_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_nicira_controller_role_request_OF_VERSION_1_0(void)
{
    of_nicira_controller_role_request_t *obj;
    obj = of_nicira_controller_role_request_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_NICIRA_CONTROLLER_ROLE_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 20);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_NICIRA_CONTROLLER_ROLE_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_nicira_controller_role_request_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_nicira_controller_role_request_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_nicira_controller_role_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_nicira_header_OF_VERSION_1_0(void)
{
    of_nicira_header_t *obj;
    obj = of_nicira_header_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_NICIRA_HEADER);

    of_nicira_header_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_packet_in_OF_VERSION_1_0(void)
{
    of_packet_in_t *obj;
    obj = of_packet_in_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 18);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_PACKET_IN);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 18);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_PACKET_IN);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_packet_in_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_packet_in_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_packet_in_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_packet_out_OF_VERSION_1_0(void)
{
    of_packet_out_t *obj;
    obj = of_packet_out_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_PACKET_OUT);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_PACKET_OUT);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_packet_out_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_packet_out_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_packet_out_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_port_mod_OF_VERSION_1_0(void)
{
    of_port_mod_t *obj;
    obj = of_port_mod_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 32);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_PORT_MOD);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 32);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_PORT_MOD);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_port_mod_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_port_mod_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_port_mod_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_port_mod_failed_error_msg_OF_VERSION_1_0(void)
{
    of_port_mod_failed_error_msg_t *obj;
    obj = of_port_mod_failed_error_msg_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_PORT_MOD_FAILED_ERROR_MSG);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_PORT_MOD_FAILED_ERROR_MSG);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_port_mod_failed_error_msg_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_port_mod_failed_error_msg_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_port_mod_failed_error_msg_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_port_stats_reply_OF_VERSION_1_0(void)
{
    of_port_stats_reply_t *obj;
    obj = of_port_stats_reply_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_PORT_STATS_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_PORT_STATS_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_port_stats_reply_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_port_stats_reply_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_port_stats_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_port_stats_request_OF_VERSION_1_0(void)
{
    of_port_stats_request_t *obj;
    obj = of_port_stats_request_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_PORT_STATS_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 20);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_PORT_STATS_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_port_stats_request_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_port_stats_request_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_port_stats_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_port_status_OF_VERSION_1_0(void)
{
    of_port_status_t *obj;
    obj = of_port_status_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 64);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_PORT_STATUS);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 64);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_PORT_STATUS);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_port_status_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_port_status_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_port_status_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_queue_get_config_reply_OF_VERSION_1_0(void)
{
    of_queue_get_config_reply_t *obj;
    obj = of_queue_get_config_reply_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_QUEUE_GET_CONFIG_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_QUEUE_GET_CONFIG_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_queue_get_config_reply_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_queue_get_config_reply_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_queue_get_config_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_queue_get_config_request_OF_VERSION_1_0(void)
{
    of_queue_get_config_request_t *obj;
    obj = of_queue_get_config_request_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_QUEUE_GET_CONFIG_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_QUEUE_GET_CONFIG_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_queue_get_config_request_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_queue_get_config_request_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_queue_get_config_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_queue_op_failed_error_msg_OF_VERSION_1_0(void)
{
    of_queue_op_failed_error_msg_t *obj;
    obj = of_queue_op_failed_error_msg_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_QUEUE_OP_FAILED_ERROR_MSG);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_QUEUE_OP_FAILED_ERROR_MSG);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_queue_op_failed_error_msg_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_queue_op_failed_error_msg_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_queue_op_failed_error_msg_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_queue_stats_reply_OF_VERSION_1_0(void)
{
    of_queue_stats_reply_t *obj;
    obj = of_queue_stats_reply_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_QUEUE_STATS_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_QUEUE_STATS_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_queue_stats_reply_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_queue_stats_reply_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_queue_stats_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_queue_stats_request_OF_VERSION_1_0(void)
{
    of_queue_stats_request_t *obj;
    obj = of_queue_stats_request_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_QUEUE_STATS_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 20);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_QUEUE_STATS_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_queue_stats_request_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_queue_stats_request_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_queue_stats_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_set_config_OF_VERSION_1_0(void)
{
    of_set_config_t *obj;
    obj = of_set_config_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_SET_CONFIG);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_SET_CONFIG);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_set_config_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_set_config_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_set_config_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_stats_reply_OF_VERSION_1_0(void)
{
    of_stats_reply_t *obj;
    obj = of_stats_reply_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_STATS_REPLY);

    of_stats_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_stats_request_OF_VERSION_1_0(void)
{
    of_stats_request_t *obj;
    obj = of_stats_request_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_STATS_REQUEST);

    of_stats_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_table_mod_OF_VERSION_1_0(void)
{
    of_table_mod_t *obj;
    obj = of_table_mod_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_TABLE_MOD);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_TABLE_MOD);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_table_mod_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_table_mod_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_table_mod_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_table_stats_reply_OF_VERSION_1_0(void)
{
    of_table_stats_reply_t *obj;
    obj = of_table_stats_reply_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_TABLE_STATS_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_TABLE_STATS_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_table_stats_reply_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_table_stats_reply_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_table_stats_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_table_stats_request_OF_VERSION_1_0(void)
{
    of_table_stats_request_t *obj;
    obj = of_table_stats_request_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_TABLE_STATS_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_TABLE_STATS_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_table_stats_request_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_table_stats_request_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_table_stats_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_bsn_OF_VERSION_1_0(void)
{
    of_action_bsn_t *obj;
    obj = of_action_bsn_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_BSN);

    of_action_bsn_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_bsn_mirror_OF_VERSION_1_0(void)
{
    of_action_bsn_mirror_t *obj;
    obj = of_action_bsn_mirror_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_BSN_MIRROR);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 24);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_BSN_MIRROR);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_bsn_mirror_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_bsn_mirror_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_action_bsn_mirror_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_bsn_set_tunnel_dst_OF_VERSION_1_0(void)
{
    of_action_bsn_set_tunnel_dst_t *obj;
    obj = of_action_bsn_set_tunnel_dst_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_BSN_SET_TUNNEL_DST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_BSN_SET_TUNNEL_DST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_bsn_set_tunnel_dst_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_bsn_set_tunnel_dst_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_action_bsn_set_tunnel_dst_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_enqueue_OF_VERSION_1_0(void)
{
    of_action_enqueue_t *obj;
    obj = of_action_enqueue_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_ENQUEUE);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_ENQUEUE);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_enqueue_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_enqueue_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_action_enqueue_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_experimenter_OF_VERSION_1_0(void)
{
    of_action_experimenter_t *obj;
    obj = of_action_experimenter_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_EXPERIMENTER);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_EXPERIMENTER);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_experimenter_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_experimenter_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_action_experimenter_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_header_OF_VERSION_1_0(void)
{
    of_action_header_t *obj;
    obj = of_action_header_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_HEADER);

    of_action_header_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_nicira_OF_VERSION_1_0(void)
{
    of_action_nicira_t *obj;
    obj = of_action_nicira_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_NICIRA);

    of_action_nicira_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_nicira_dec_ttl_OF_VERSION_1_0(void)
{
    of_action_nicira_dec_ttl_t *obj;
    obj = of_action_nicira_dec_ttl_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_NICIRA_DEC_TTL);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_NICIRA_DEC_TTL);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_nicira_dec_ttl_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_nicira_dec_ttl_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_action_nicira_dec_ttl_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_output_OF_VERSION_1_0(void)
{
    of_action_output_t *obj;
    obj = of_action_output_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_OUTPUT);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_OUTPUT);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_output_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_output_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_action_output_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_set_dl_dst_OF_VERSION_1_0(void)
{
    of_action_set_dl_dst_t *obj;
    obj = of_action_set_dl_dst_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_SET_DL_DST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_SET_DL_DST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_set_dl_dst_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_set_dl_dst_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_action_set_dl_dst_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_set_dl_src_OF_VERSION_1_0(void)
{
    of_action_set_dl_src_t *obj;
    obj = of_action_set_dl_src_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_SET_DL_SRC);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_SET_DL_SRC);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_set_dl_src_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_set_dl_src_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_action_set_dl_src_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_set_nw_dst_OF_VERSION_1_0(void)
{
    of_action_set_nw_dst_t *obj;
    obj = of_action_set_nw_dst_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_SET_NW_DST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_SET_NW_DST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_set_nw_dst_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_set_nw_dst_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_action_set_nw_dst_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_set_nw_src_OF_VERSION_1_0(void)
{
    of_action_set_nw_src_t *obj;
    obj = of_action_set_nw_src_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_SET_NW_SRC);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_SET_NW_SRC);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_set_nw_src_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_set_nw_src_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_action_set_nw_src_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_set_nw_tos_OF_VERSION_1_0(void)
{
    of_action_set_nw_tos_t *obj;
    obj = of_action_set_nw_tos_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_SET_NW_TOS);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_SET_NW_TOS);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_set_nw_tos_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_set_nw_tos_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_action_set_nw_tos_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_set_tp_dst_OF_VERSION_1_0(void)
{
    of_action_set_tp_dst_t *obj;
    obj = of_action_set_tp_dst_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_SET_TP_DST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_SET_TP_DST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_set_tp_dst_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_set_tp_dst_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_action_set_tp_dst_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_set_tp_src_OF_VERSION_1_0(void)
{
    of_action_set_tp_src_t *obj;
    obj = of_action_set_tp_src_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_SET_TP_SRC);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_SET_TP_SRC);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_set_tp_src_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_set_tp_src_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_action_set_tp_src_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_set_vlan_pcp_OF_VERSION_1_0(void)
{
    of_action_set_vlan_pcp_t *obj;
    obj = of_action_set_vlan_pcp_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_SET_VLAN_PCP);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_SET_VLAN_PCP);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_set_vlan_pcp_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_set_vlan_pcp_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_action_set_vlan_pcp_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_set_vlan_vid_OF_VERSION_1_0(void)
{
    of_action_set_vlan_vid_t *obj;
    obj = of_action_set_vlan_vid_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_SET_VLAN_VID);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_SET_VLAN_VID);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_set_vlan_vid_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_set_vlan_vid_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_action_set_vlan_vid_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_strip_vlan_OF_VERSION_1_0(void)
{
    of_action_strip_vlan_t *obj;
    obj = of_action_strip_vlan_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_STRIP_VLAN);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_STRIP_VLAN);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_strip_vlan_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_strip_vlan_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_action_strip_vlan_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_interface_OF_VERSION_1_0(void)
{
    of_bsn_interface_t *obj;
    obj = of_bsn_interface_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 32);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_INTERFACE);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 32);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_INTERFACE);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_interface_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_interface_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_bsn_interface_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_vport_header_OF_VERSION_1_0(void)
{
    of_bsn_vport_header_t *obj;
    obj = of_bsn_vport_header_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 4);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_VPORT_HEADER);

    of_bsn_vport_header_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_vport_q_in_q_OF_VERSION_1_0(void)
{
    of_bsn_vport_q_in_q_t *obj;
    obj = of_bsn_vport_q_in_q_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 32);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_VPORT_Q_IN_Q);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 32);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_VPORT_Q_IN_Q);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_vport_q_in_q_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_vport_q_in_q_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_bsn_vport_q_in_q_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_flow_stats_entry_OF_VERSION_1_0(void)
{
    of_flow_stats_entry_t *obj;
    obj = of_flow_stats_entry_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 88);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_STATS_ENTRY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 88);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_FLOW_STATS_ENTRY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_flow_stats_entry_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_flow_stats_entry_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_flow_stats_entry_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_header_OF_VERSION_1_0(void)
{
    of_header_t *obj;
    obj = of_header_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_HEADER);

    of_header_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_match_v1_OF_VERSION_1_0(void)
{
    of_match_v1_t *obj;
    obj = of_match_v1_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 40);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_MATCH_V1);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 40);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_MATCH_V1);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_match_v1_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_match_v1_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_match_v1_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_packet_queue_OF_VERSION_1_0(void)
{
    of_packet_queue_t *obj;
    obj = of_packet_queue_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_PACKET_QUEUE);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_PACKET_QUEUE);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_packet_queue_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_packet_queue_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_packet_queue_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_port_desc_OF_VERSION_1_0(void)
{
    of_port_desc_t *obj;
    obj = of_port_desc_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 48);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_PORT_DESC);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 48);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_PORT_DESC);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_port_desc_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_port_desc_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_port_desc_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_port_stats_entry_OF_VERSION_1_0(void)
{
    of_port_stats_entry_t *obj;
    obj = of_port_stats_entry_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 104);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_PORT_STATS_ENTRY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 104);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_PORT_STATS_ENTRY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_port_stats_entry_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_port_stats_entry_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_port_stats_entry_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_queue_prop_header_OF_VERSION_1_0(void)
{
    of_queue_prop_header_t *obj;
    obj = of_queue_prop_header_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_QUEUE_PROP_HEADER);

    of_queue_prop_header_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_queue_prop_min_rate_OF_VERSION_1_0(void)
{
    of_queue_prop_min_rate_t *obj;
    obj = of_queue_prop_min_rate_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_QUEUE_PROP_MIN_RATE);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_QUEUE_PROP_MIN_RATE);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_queue_prop_min_rate_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_queue_prop_min_rate_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_queue_prop_min_rate_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_queue_stats_entry_OF_VERSION_1_0(void)
{
    of_queue_stats_entry_t *obj;
    obj = of_queue_stats_entry_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 32);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_QUEUE_STATS_ENTRY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 32);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_QUEUE_STATS_ENTRY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_queue_stats_entry_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_queue_stats_entry_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_queue_stats_entry_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_table_stats_entry_OF_VERSION_1_0(void)
{
    of_table_stats_entry_t *obj;
    obj = of_table_stats_entry_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 64);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_TABLE_STATS_ENTRY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 64);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_TABLE_STATS_ENTRY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_table_stats_entry_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_table_stats_entry_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_table_stats_entry_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_list_action_OF_VERSION_1_0(void)
{
    of_list_action_t *obj;
    obj = of_list_action_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 0);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_LIST_ACTION);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 0);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_LIST_ACTION);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_list_action_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_list_action_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_list_action_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_list_bsn_interface_OF_VERSION_1_0(void)
{
    of_list_bsn_interface_t *obj;
    obj = of_list_bsn_interface_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 0);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_LIST_BSN_INTERFACE);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 0);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_LIST_BSN_INTERFACE);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_list_bsn_interface_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_list_bsn_interface_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_list_bsn_interface_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_list_flow_stats_entry_OF_VERSION_1_0(void)
{
    of_list_flow_stats_entry_t *obj;
    obj = of_list_flow_stats_entry_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 0);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_LIST_FLOW_STATS_ENTRY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 0);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_LIST_FLOW_STATS_ENTRY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_list_flow_stats_entry_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_list_flow_stats_entry_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_list_flow_stats_entry_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_list_packet_queue_OF_VERSION_1_0(void)
{
    of_list_packet_queue_t *obj;
    obj = of_list_packet_queue_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 0);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_LIST_PACKET_QUEUE);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 0);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_LIST_PACKET_QUEUE);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_list_packet_queue_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_list_packet_queue_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_list_packet_queue_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_list_port_desc_OF_VERSION_1_0(void)
{
    of_list_port_desc_t *obj;
    obj = of_list_port_desc_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 0);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_LIST_PORT_DESC);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 0);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_LIST_PORT_DESC);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_list_port_desc_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_list_port_desc_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_list_port_desc_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_list_port_stats_entry_OF_VERSION_1_0(void)
{
    of_list_port_stats_entry_t *obj;
    obj = of_list_port_stats_entry_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 0);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_LIST_PORT_STATS_ENTRY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 0);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_LIST_PORT_STATS_ENTRY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_list_port_stats_entry_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_list_port_stats_entry_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_list_port_stats_entry_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_list_queue_prop_OF_VERSION_1_0(void)
{
    of_list_queue_prop_t *obj;
    obj = of_list_queue_prop_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 0);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_LIST_QUEUE_PROP);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 0);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_LIST_QUEUE_PROP);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_list_queue_prop_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_list_queue_prop_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_list_queue_prop_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_list_queue_stats_entry_OF_VERSION_1_0(void)
{
    of_list_queue_stats_entry_t *obj;
    obj = of_list_queue_stats_entry_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 0);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_LIST_QUEUE_STATS_ENTRY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 0);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_LIST_QUEUE_STATS_ENTRY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_list_queue_stats_entry_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_list_queue_stats_entry_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_list_queue_stats_entry_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_list_table_stats_entry_OF_VERSION_1_0(void)
{
    of_list_table_stats_entry_t *obj;
    obj = of_list_table_stats_entry_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 0);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_LIST_TABLE_STATS_ENTRY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 0);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_LIST_TABLE_STATS_ENTRY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_list_table_stats_entry_OF_VERSION_1_0_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_list_table_stats_entry_OF_VERSION_1_0_check(
        obj, 1) != 0);

    of_list_table_stats_entry_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_aggregate_stats_reply_OF_VERSION_1_1(void)
{
    of_aggregate_stats_reply_t *obj;
    obj = of_aggregate_stats_reply_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 40);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_AGGREGATE_STATS_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 40);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_AGGREGATE_STATS_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_aggregate_stats_reply_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_aggregate_stats_reply_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_aggregate_stats_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_aggregate_stats_request_OF_VERSION_1_1(void)
{
    of_aggregate_stats_request_t *obj;
    obj = of_aggregate_stats_request_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 136);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_AGGREGATE_STATS_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 136);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_AGGREGATE_STATS_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_aggregate_stats_request_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_aggregate_stats_request_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_aggregate_stats_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bad_action_error_msg_OF_VERSION_1_1(void)
{
    of_bad_action_error_msg_t *obj;
    obj = of_bad_action_error_msg_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BAD_ACTION_ERROR_MSG);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BAD_ACTION_ERROR_MSG);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bad_action_error_msg_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bad_action_error_msg_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_bad_action_error_msg_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bad_instruction_error_msg_OF_VERSION_1_1(void)
{
    of_bad_instruction_error_msg_t *obj;
    obj = of_bad_instruction_error_msg_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BAD_INSTRUCTION_ERROR_MSG);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BAD_INSTRUCTION_ERROR_MSG);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bad_instruction_error_msg_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bad_instruction_error_msg_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_bad_instruction_error_msg_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bad_match_error_msg_OF_VERSION_1_1(void)
{
    of_bad_match_error_msg_t *obj;
    obj = of_bad_match_error_msg_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BAD_MATCH_ERROR_MSG);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BAD_MATCH_ERROR_MSG);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bad_match_error_msg_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bad_match_error_msg_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_bad_match_error_msg_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bad_request_error_msg_OF_VERSION_1_1(void)
{
    of_bad_request_error_msg_t *obj;
    obj = of_bad_request_error_msg_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BAD_REQUEST_ERROR_MSG);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BAD_REQUEST_ERROR_MSG);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bad_request_error_msg_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bad_request_error_msg_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_bad_request_error_msg_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_barrier_reply_OF_VERSION_1_1(void)
{
    of_barrier_reply_t *obj;
    obj = of_barrier_reply_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BARRIER_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BARRIER_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_barrier_reply_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_barrier_reply_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_barrier_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_barrier_request_OF_VERSION_1_1(void)
{
    of_barrier_request_t *obj;
    obj = of_barrier_request_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BARRIER_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BARRIER_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_barrier_request_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_barrier_request_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_barrier_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_bw_clear_data_reply_OF_VERSION_1_1(void)
{
    of_bsn_bw_clear_data_reply_t *obj;
    obj = of_bsn_bw_clear_data_reply_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_BW_CLEAR_DATA_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 20);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_BW_CLEAR_DATA_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_bw_clear_data_reply_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_bw_clear_data_reply_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_bsn_bw_clear_data_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_bw_clear_data_request_OF_VERSION_1_1(void)
{
    of_bsn_bw_clear_data_request_t *obj;
    obj = of_bsn_bw_clear_data_request_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_BW_CLEAR_DATA_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_BW_CLEAR_DATA_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_bw_clear_data_request_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_bw_clear_data_request_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_bsn_bw_clear_data_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_bw_enable_get_reply_OF_VERSION_1_1(void)
{
    of_bsn_bw_enable_get_reply_t *obj;
    obj = of_bsn_bw_enable_get_reply_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_BW_ENABLE_GET_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 20);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_BW_ENABLE_GET_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_bw_enable_get_reply_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_bw_enable_get_reply_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_bsn_bw_enable_get_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_bw_enable_get_request_OF_VERSION_1_1(void)
{
    of_bsn_bw_enable_get_request_t *obj;
    obj = of_bsn_bw_enable_get_request_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_BW_ENABLE_GET_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_BW_ENABLE_GET_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_bw_enable_get_request_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_bw_enable_get_request_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_bsn_bw_enable_get_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_bw_enable_set_reply_OF_VERSION_1_1(void)
{
    of_bsn_bw_enable_set_reply_t *obj;
    obj = of_bsn_bw_enable_set_reply_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_BW_ENABLE_SET_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 24);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_BW_ENABLE_SET_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_bw_enable_set_reply_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_bw_enable_set_reply_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_bsn_bw_enable_set_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_bw_enable_set_request_OF_VERSION_1_1(void)
{
    of_bsn_bw_enable_set_request_t *obj;
    obj = of_bsn_bw_enable_set_request_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_BW_ENABLE_SET_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 20);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_BW_ENABLE_SET_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_bw_enable_set_request_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_bw_enable_set_request_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_bsn_bw_enable_set_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_get_interfaces_reply_OF_VERSION_1_1(void)
{
    of_bsn_get_interfaces_reply_t *obj;
    obj = of_bsn_get_interfaces_reply_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GET_INTERFACES_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_GET_INTERFACES_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_get_interfaces_reply_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_get_interfaces_reply_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_bsn_get_interfaces_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_get_interfaces_request_OF_VERSION_1_1(void)
{
    of_bsn_get_interfaces_request_t *obj;
    obj = of_bsn_get_interfaces_request_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GET_INTERFACES_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_GET_INTERFACES_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_get_interfaces_request_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_get_interfaces_request_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_bsn_get_interfaces_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_get_mirroring_reply_OF_VERSION_1_1(void)
{
    of_bsn_get_mirroring_reply_t *obj;
    obj = of_bsn_get_mirroring_reply_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GET_MIRRORING_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 20);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_GET_MIRRORING_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_get_mirroring_reply_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_get_mirroring_reply_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_bsn_get_mirroring_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_get_mirroring_request_OF_VERSION_1_1(void)
{
    of_bsn_get_mirroring_request_t *obj;
    obj = of_bsn_get_mirroring_request_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GET_MIRRORING_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 20);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_GET_MIRRORING_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_get_mirroring_request_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_get_mirroring_request_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_bsn_get_mirroring_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_header_OF_VERSION_1_1(void)
{
    of_bsn_header_t *obj;
    obj = of_bsn_header_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_HEADER);

    of_bsn_header_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_pdu_rx_reply_OF_VERSION_1_1(void)
{
    of_bsn_pdu_rx_reply_t *obj;
    obj = of_bsn_pdu_rx_reply_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 25);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_PDU_RX_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 25);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_PDU_RX_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_pdu_rx_reply_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_pdu_rx_reply_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_bsn_pdu_rx_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_pdu_rx_request_OF_VERSION_1_1(void)
{
    of_bsn_pdu_rx_request_t *obj;
    obj = of_bsn_pdu_rx_request_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 28);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_PDU_RX_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 28);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_PDU_RX_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_pdu_rx_request_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_pdu_rx_request_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_bsn_pdu_rx_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_pdu_rx_timeout_OF_VERSION_1_1(void)
{
    of_bsn_pdu_rx_timeout_t *obj;
    obj = of_bsn_pdu_rx_timeout_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 21);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_PDU_RX_TIMEOUT);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 21);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_PDU_RX_TIMEOUT);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_pdu_rx_timeout_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_pdu_rx_timeout_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_bsn_pdu_rx_timeout_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_pdu_tx_reply_OF_VERSION_1_1(void)
{
    of_bsn_pdu_tx_reply_t *obj;
    obj = of_bsn_pdu_tx_reply_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 25);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_PDU_TX_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 25);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_PDU_TX_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_pdu_tx_reply_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_pdu_tx_reply_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_bsn_pdu_tx_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_pdu_tx_request_OF_VERSION_1_1(void)
{
    of_bsn_pdu_tx_request_t *obj;
    obj = of_bsn_pdu_tx_request_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 28);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_PDU_TX_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 28);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_PDU_TX_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_pdu_tx_request_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_pdu_tx_request_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_bsn_pdu_tx_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_set_mirroring_OF_VERSION_1_1(void)
{
    of_bsn_set_mirroring_t *obj;
    obj = of_bsn_set_mirroring_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_SET_MIRRORING);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 20);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_SET_MIRRORING);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_set_mirroring_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_set_mirroring_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_bsn_set_mirroring_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_set_pktin_suppression_reply_OF_VERSION_1_1(void)
{
    of_bsn_set_pktin_suppression_reply_t *obj;
    obj = of_bsn_set_pktin_suppression_reply_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_SET_PKTIN_SUPPRESSION_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 20);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_SET_PKTIN_SUPPRESSION_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_set_pktin_suppression_reply_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_set_pktin_suppression_reply_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_bsn_set_pktin_suppression_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_set_pktin_suppression_request_OF_VERSION_1_1(void)
{
    of_bsn_set_pktin_suppression_request_t *obj;
    obj = of_bsn_set_pktin_suppression_request_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 32);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_SET_PKTIN_SUPPRESSION_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 32);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_SET_PKTIN_SUPPRESSION_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_set_pktin_suppression_request_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_set_pktin_suppression_request_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_bsn_set_pktin_suppression_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_stats_reply_OF_VERSION_1_1(void)
{
    of_bsn_stats_reply_t *obj;
    obj = of_bsn_stats_reply_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_STATS_REPLY);

    of_bsn_stats_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_stats_request_OF_VERSION_1_1(void)
{
    of_bsn_stats_request_t *obj;
    obj = of_bsn_stats_request_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_STATS_REQUEST);

    of_bsn_stats_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_virtual_port_create_reply_OF_VERSION_1_1(void)
{
    of_bsn_virtual_port_create_reply_t *obj;
    obj = of_bsn_virtual_port_create_reply_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_VIRTUAL_PORT_CREATE_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 24);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_VIRTUAL_PORT_CREATE_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_virtual_port_create_reply_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_virtual_port_create_reply_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_bsn_virtual_port_create_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_virtual_port_create_request_OF_VERSION_1_1(void)
{
    of_bsn_virtual_port_create_request_t *obj;
    obj = of_bsn_virtual_port_create_request_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 48);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_VIRTUAL_PORT_CREATE_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 48);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_VIRTUAL_PORT_CREATE_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_virtual_port_create_request_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_virtual_port_create_request_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_bsn_virtual_port_create_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_virtual_port_remove_reply_OF_VERSION_1_1(void)
{
    of_bsn_virtual_port_remove_reply_t *obj;
    obj = of_bsn_virtual_port_remove_reply_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_VIRTUAL_PORT_REMOVE_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 20);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_VIRTUAL_PORT_REMOVE_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_virtual_port_remove_reply_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_virtual_port_remove_reply_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_bsn_virtual_port_remove_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_virtual_port_remove_request_OF_VERSION_1_1(void)
{
    of_bsn_virtual_port_remove_request_t *obj;
    obj = of_bsn_virtual_port_remove_request_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_VIRTUAL_PORT_REMOVE_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 20);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_VIRTUAL_PORT_REMOVE_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_virtual_port_remove_request_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_virtual_port_remove_request_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_bsn_virtual_port_remove_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_desc_stats_reply_OF_VERSION_1_1(void)
{
    of_desc_stats_reply_t *obj;
    obj = of_desc_stats_reply_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 1072);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_DESC_STATS_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 1072);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_DESC_STATS_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_desc_stats_reply_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_desc_stats_reply_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_desc_stats_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_desc_stats_request_OF_VERSION_1_1(void)
{
    of_desc_stats_request_t *obj;
    obj = of_desc_stats_request_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_DESC_STATS_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_DESC_STATS_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_desc_stats_request_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_desc_stats_request_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_desc_stats_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_echo_reply_OF_VERSION_1_1(void)
{
    of_echo_reply_t *obj;
    obj = of_echo_reply_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ECHO_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ECHO_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_echo_reply_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_echo_reply_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_echo_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_echo_request_OF_VERSION_1_1(void)
{
    of_echo_request_t *obj;
    obj = of_echo_request_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ECHO_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ECHO_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_echo_request_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_echo_request_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_echo_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_error_msg_OF_VERSION_1_1(void)
{
    of_error_msg_t *obj;
    obj = of_error_msg_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 10);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ERROR_MSG);

    of_error_msg_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_experimenter_OF_VERSION_1_1(void)
{
    of_experimenter_t *obj;
    obj = of_experimenter_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_EXPERIMENTER);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_EXPERIMENTER);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_experimenter_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_experimenter_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_experimenter_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_experimenter_stats_reply_OF_VERSION_1_1(void)
{
    of_experimenter_stats_reply_t *obj;
    obj = of_experimenter_stats_reply_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_EXPERIMENTER_STATS_REPLY);

    of_experimenter_stats_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_experimenter_stats_request_OF_VERSION_1_1(void)
{
    of_experimenter_stats_request_t *obj;
    obj = of_experimenter_stats_request_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_EXPERIMENTER_STATS_REQUEST);

    of_experimenter_stats_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_features_reply_OF_VERSION_1_1(void)
{
    of_features_reply_t *obj;
    obj = of_features_reply_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 32);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FEATURES_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 32);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_FEATURES_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_features_reply_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_features_reply_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_features_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_features_request_OF_VERSION_1_1(void)
{
    of_features_request_t *obj;
    obj = of_features_request_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FEATURES_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_FEATURES_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_features_request_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_features_request_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_features_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_flow_add_OF_VERSION_1_1(void)
{
    of_flow_add_t *obj;
    obj = of_flow_add_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 136);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_ADD);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 136);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_FLOW_ADD);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_flow_add_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_flow_add_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_flow_add_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_flow_delete_OF_VERSION_1_1(void)
{
    of_flow_delete_t *obj;
    obj = of_flow_delete_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 136);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_DELETE);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 136);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_FLOW_DELETE);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_flow_delete_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_flow_delete_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_flow_delete_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_flow_delete_strict_OF_VERSION_1_1(void)
{
    of_flow_delete_strict_t *obj;
    obj = of_flow_delete_strict_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 136);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_DELETE_STRICT);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 136);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_FLOW_DELETE_STRICT);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_flow_delete_strict_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_flow_delete_strict_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_flow_delete_strict_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_flow_mod_OF_VERSION_1_1(void)
{
    of_flow_mod_t *obj;
    obj = of_flow_mod_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 136);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_MOD);

    of_flow_mod_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_flow_mod_failed_error_msg_OF_VERSION_1_1(void)
{
    of_flow_mod_failed_error_msg_t *obj;
    obj = of_flow_mod_failed_error_msg_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_MOD_FAILED_ERROR_MSG);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_FLOW_MOD_FAILED_ERROR_MSG);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_flow_mod_failed_error_msg_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_flow_mod_failed_error_msg_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_flow_mod_failed_error_msg_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_flow_modify_OF_VERSION_1_1(void)
{
    of_flow_modify_t *obj;
    obj = of_flow_modify_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 136);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_MODIFY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 136);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_FLOW_MODIFY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_flow_modify_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_flow_modify_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_flow_modify_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_flow_modify_strict_OF_VERSION_1_1(void)
{
    of_flow_modify_strict_t *obj;
    obj = of_flow_modify_strict_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 136);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_MODIFY_STRICT);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 136);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_FLOW_MODIFY_STRICT);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_flow_modify_strict_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_flow_modify_strict_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_flow_modify_strict_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_flow_removed_OF_VERSION_1_1(void)
{
    of_flow_removed_t *obj;
    obj = of_flow_removed_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 136);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_REMOVED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 136);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_FLOW_REMOVED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_flow_removed_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_flow_removed_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_flow_removed_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_flow_stats_reply_OF_VERSION_1_1(void)
{
    of_flow_stats_reply_t *obj;
    obj = of_flow_stats_reply_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_STATS_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_FLOW_STATS_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_flow_stats_reply_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_flow_stats_reply_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_flow_stats_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_flow_stats_request_OF_VERSION_1_1(void)
{
    of_flow_stats_request_t *obj;
    obj = of_flow_stats_request_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 136);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_STATS_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 136);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_FLOW_STATS_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_flow_stats_request_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_flow_stats_request_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_flow_stats_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_get_config_reply_OF_VERSION_1_1(void)
{
    of_get_config_reply_t *obj;
    obj = of_get_config_reply_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_GET_CONFIG_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_GET_CONFIG_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_get_config_reply_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_get_config_reply_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_get_config_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_get_config_request_OF_VERSION_1_1(void)
{
    of_get_config_request_t *obj;
    obj = of_get_config_request_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_GET_CONFIG_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_GET_CONFIG_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_get_config_request_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_get_config_request_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_get_config_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_group_desc_stats_reply_OF_VERSION_1_1(void)
{
    of_group_desc_stats_reply_t *obj;
    obj = of_group_desc_stats_reply_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_GROUP_DESC_STATS_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_GROUP_DESC_STATS_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_group_desc_stats_reply_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_group_desc_stats_reply_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_group_desc_stats_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_group_desc_stats_request_OF_VERSION_1_1(void)
{
    of_group_desc_stats_request_t *obj;
    obj = of_group_desc_stats_request_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_GROUP_DESC_STATS_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_GROUP_DESC_STATS_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_group_desc_stats_request_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_group_desc_stats_request_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_group_desc_stats_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_group_mod_OF_VERSION_1_1(void)
{
    of_group_mod_t *obj;
    obj = of_group_mod_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_GROUP_MOD);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_GROUP_MOD);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_group_mod_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_group_mod_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_group_mod_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_group_mod_failed_error_msg_OF_VERSION_1_1(void)
{
    of_group_mod_failed_error_msg_t *obj;
    obj = of_group_mod_failed_error_msg_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_GROUP_MOD_FAILED_ERROR_MSG);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_GROUP_MOD_FAILED_ERROR_MSG);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_group_mod_failed_error_msg_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_group_mod_failed_error_msg_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_group_mod_failed_error_msg_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_group_stats_reply_OF_VERSION_1_1(void)
{
    of_group_stats_reply_t *obj;
    obj = of_group_stats_reply_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_GROUP_STATS_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_GROUP_STATS_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_group_stats_reply_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_group_stats_reply_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_group_stats_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_group_stats_request_OF_VERSION_1_1(void)
{
    of_group_stats_request_t *obj;
    obj = of_group_stats_request_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_GROUP_STATS_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 24);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_GROUP_STATS_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_group_stats_request_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_group_stats_request_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_group_stats_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_hello_OF_VERSION_1_1(void)
{
    of_hello_t *obj;
    obj = of_hello_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_HELLO);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_HELLO);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_hello_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_hello_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_hello_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_hello_failed_error_msg_OF_VERSION_1_1(void)
{
    of_hello_failed_error_msg_t *obj;
    obj = of_hello_failed_error_msg_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_HELLO_FAILED_ERROR_MSG);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_HELLO_FAILED_ERROR_MSG);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_hello_failed_error_msg_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_hello_failed_error_msg_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_hello_failed_error_msg_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_nicira_header_OF_VERSION_1_1(void)
{
    of_nicira_header_t *obj;
    obj = of_nicira_header_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_NICIRA_HEADER);

    of_nicira_header_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_packet_in_OF_VERSION_1_1(void)
{
    of_packet_in_t *obj;
    obj = of_packet_in_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_PACKET_IN);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 24);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_PACKET_IN);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_packet_in_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_packet_in_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_packet_in_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_packet_out_OF_VERSION_1_1(void)
{
    of_packet_out_t *obj;
    obj = of_packet_out_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_PACKET_OUT);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 24);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_PACKET_OUT);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_packet_out_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_packet_out_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_packet_out_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_port_mod_OF_VERSION_1_1(void)
{
    of_port_mod_t *obj;
    obj = of_port_mod_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 40);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_PORT_MOD);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 40);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_PORT_MOD);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_port_mod_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_port_mod_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_port_mod_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_port_mod_failed_error_msg_OF_VERSION_1_1(void)
{
    of_port_mod_failed_error_msg_t *obj;
    obj = of_port_mod_failed_error_msg_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_PORT_MOD_FAILED_ERROR_MSG);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_PORT_MOD_FAILED_ERROR_MSG);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_port_mod_failed_error_msg_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_port_mod_failed_error_msg_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_port_mod_failed_error_msg_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_port_stats_reply_OF_VERSION_1_1(void)
{
    of_port_stats_reply_t *obj;
    obj = of_port_stats_reply_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_PORT_STATS_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_PORT_STATS_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_port_stats_reply_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_port_stats_reply_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_port_stats_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_port_stats_request_OF_VERSION_1_1(void)
{
    of_port_stats_request_t *obj;
    obj = of_port_stats_request_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_PORT_STATS_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 24);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_PORT_STATS_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_port_stats_request_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_port_stats_request_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_port_stats_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_port_status_OF_VERSION_1_1(void)
{
    of_port_status_t *obj;
    obj = of_port_status_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 80);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_PORT_STATUS);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 80);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_PORT_STATUS);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_port_status_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_port_status_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_port_status_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_queue_get_config_reply_OF_VERSION_1_1(void)
{
    of_queue_get_config_reply_t *obj;
    obj = of_queue_get_config_reply_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_QUEUE_GET_CONFIG_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_QUEUE_GET_CONFIG_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_queue_get_config_reply_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_queue_get_config_reply_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_queue_get_config_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_queue_get_config_request_OF_VERSION_1_1(void)
{
    of_queue_get_config_request_t *obj;
    obj = of_queue_get_config_request_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_QUEUE_GET_CONFIG_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_QUEUE_GET_CONFIG_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_queue_get_config_request_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_queue_get_config_request_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_queue_get_config_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_queue_op_failed_error_msg_OF_VERSION_1_1(void)
{
    of_queue_op_failed_error_msg_t *obj;
    obj = of_queue_op_failed_error_msg_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_QUEUE_OP_FAILED_ERROR_MSG);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_QUEUE_OP_FAILED_ERROR_MSG);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_queue_op_failed_error_msg_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_queue_op_failed_error_msg_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_queue_op_failed_error_msg_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_queue_stats_reply_OF_VERSION_1_1(void)
{
    of_queue_stats_reply_t *obj;
    obj = of_queue_stats_reply_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_QUEUE_STATS_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_QUEUE_STATS_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_queue_stats_reply_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_queue_stats_reply_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_queue_stats_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_queue_stats_request_OF_VERSION_1_1(void)
{
    of_queue_stats_request_t *obj;
    obj = of_queue_stats_request_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_QUEUE_STATS_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 24);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_QUEUE_STATS_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_queue_stats_request_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_queue_stats_request_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_queue_stats_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_set_config_OF_VERSION_1_1(void)
{
    of_set_config_t *obj;
    obj = of_set_config_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_SET_CONFIG);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_SET_CONFIG);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_set_config_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_set_config_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_set_config_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_stats_reply_OF_VERSION_1_1(void)
{
    of_stats_reply_t *obj;
    obj = of_stats_reply_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_STATS_REPLY);

    of_stats_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_stats_request_OF_VERSION_1_1(void)
{
    of_stats_request_t *obj;
    obj = of_stats_request_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_STATS_REQUEST);

    of_stats_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_switch_config_failed_error_msg_OF_VERSION_1_1(void)
{
    of_switch_config_failed_error_msg_t *obj;
    obj = of_switch_config_failed_error_msg_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_SWITCH_CONFIG_FAILED_ERROR_MSG);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_SWITCH_CONFIG_FAILED_ERROR_MSG);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_switch_config_failed_error_msg_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_switch_config_failed_error_msg_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_switch_config_failed_error_msg_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_table_mod_OF_VERSION_1_1(void)
{
    of_table_mod_t *obj;
    obj = of_table_mod_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_TABLE_MOD);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_TABLE_MOD);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_table_mod_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_table_mod_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_table_mod_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_table_mod_failed_error_msg_OF_VERSION_1_1(void)
{
    of_table_mod_failed_error_msg_t *obj;
    obj = of_table_mod_failed_error_msg_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_TABLE_MOD_FAILED_ERROR_MSG);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_TABLE_MOD_FAILED_ERROR_MSG);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_table_mod_failed_error_msg_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_table_mod_failed_error_msg_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_table_mod_failed_error_msg_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_table_stats_reply_OF_VERSION_1_1(void)
{
    of_table_stats_reply_t *obj;
    obj = of_table_stats_reply_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_TABLE_STATS_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_TABLE_STATS_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_table_stats_reply_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_table_stats_reply_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_table_stats_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_table_stats_request_OF_VERSION_1_1(void)
{
    of_table_stats_request_t *obj;
    obj = of_table_stats_request_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_TABLE_STATS_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_TABLE_STATS_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_table_stats_request_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_table_stats_request_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_table_stats_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_bsn_OF_VERSION_1_1(void)
{
    of_action_bsn_t *obj;
    obj = of_action_bsn_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_BSN);

    of_action_bsn_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_bsn_mirror_OF_VERSION_1_1(void)
{
    of_action_bsn_mirror_t *obj;
    obj = of_action_bsn_mirror_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_BSN_MIRROR);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 24);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_BSN_MIRROR);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_bsn_mirror_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_bsn_mirror_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_action_bsn_mirror_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_bsn_set_tunnel_dst_OF_VERSION_1_1(void)
{
    of_action_bsn_set_tunnel_dst_t *obj;
    obj = of_action_bsn_set_tunnel_dst_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_BSN_SET_TUNNEL_DST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_BSN_SET_TUNNEL_DST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_bsn_set_tunnel_dst_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_bsn_set_tunnel_dst_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_action_bsn_set_tunnel_dst_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_copy_ttl_in_OF_VERSION_1_1(void)
{
    of_action_copy_ttl_in_t *obj;
    obj = of_action_copy_ttl_in_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_COPY_TTL_IN);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_COPY_TTL_IN);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_copy_ttl_in_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_copy_ttl_in_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_action_copy_ttl_in_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_copy_ttl_out_OF_VERSION_1_1(void)
{
    of_action_copy_ttl_out_t *obj;
    obj = of_action_copy_ttl_out_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_COPY_TTL_OUT);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_COPY_TTL_OUT);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_copy_ttl_out_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_copy_ttl_out_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_action_copy_ttl_out_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_dec_mpls_ttl_OF_VERSION_1_1(void)
{
    of_action_dec_mpls_ttl_t *obj;
    obj = of_action_dec_mpls_ttl_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_DEC_MPLS_TTL);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_DEC_MPLS_TTL);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_dec_mpls_ttl_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_dec_mpls_ttl_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_action_dec_mpls_ttl_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_dec_nw_ttl_OF_VERSION_1_1(void)
{
    of_action_dec_nw_ttl_t *obj;
    obj = of_action_dec_nw_ttl_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_DEC_NW_TTL);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_DEC_NW_TTL);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_dec_nw_ttl_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_dec_nw_ttl_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_action_dec_nw_ttl_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_experimenter_OF_VERSION_1_1(void)
{
    of_action_experimenter_t *obj;
    obj = of_action_experimenter_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_EXPERIMENTER);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_EXPERIMENTER);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_experimenter_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_experimenter_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_action_experimenter_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_group_OF_VERSION_1_1(void)
{
    of_action_group_t *obj;
    obj = of_action_group_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_GROUP);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_GROUP);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_group_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_group_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_action_group_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_header_OF_VERSION_1_1(void)
{
    of_action_header_t *obj;
    obj = of_action_header_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_HEADER);

    of_action_header_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_nicira_OF_VERSION_1_1(void)
{
    of_action_nicira_t *obj;
    obj = of_action_nicira_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_NICIRA);

    of_action_nicira_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_nicira_dec_ttl_OF_VERSION_1_1(void)
{
    of_action_nicira_dec_ttl_t *obj;
    obj = of_action_nicira_dec_ttl_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_NICIRA_DEC_TTL);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_NICIRA_DEC_TTL);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_nicira_dec_ttl_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_nicira_dec_ttl_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_action_nicira_dec_ttl_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_output_OF_VERSION_1_1(void)
{
    of_action_output_t *obj;
    obj = of_action_output_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_OUTPUT);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_OUTPUT);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_output_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_output_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_action_output_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_pop_mpls_OF_VERSION_1_1(void)
{
    of_action_pop_mpls_t *obj;
    obj = of_action_pop_mpls_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_POP_MPLS);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_POP_MPLS);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_pop_mpls_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_pop_mpls_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_action_pop_mpls_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_pop_vlan_OF_VERSION_1_1(void)
{
    of_action_pop_vlan_t *obj;
    obj = of_action_pop_vlan_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_POP_VLAN);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_POP_VLAN);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_pop_vlan_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_pop_vlan_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_action_pop_vlan_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_push_mpls_OF_VERSION_1_1(void)
{
    of_action_push_mpls_t *obj;
    obj = of_action_push_mpls_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_PUSH_MPLS);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_PUSH_MPLS);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_push_mpls_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_push_mpls_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_action_push_mpls_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_push_vlan_OF_VERSION_1_1(void)
{
    of_action_push_vlan_t *obj;
    obj = of_action_push_vlan_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_PUSH_VLAN);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_PUSH_VLAN);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_push_vlan_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_push_vlan_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_action_push_vlan_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_set_dl_dst_OF_VERSION_1_1(void)
{
    of_action_set_dl_dst_t *obj;
    obj = of_action_set_dl_dst_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_SET_DL_DST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_SET_DL_DST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_set_dl_dst_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_set_dl_dst_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_action_set_dl_dst_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_set_dl_src_OF_VERSION_1_1(void)
{
    of_action_set_dl_src_t *obj;
    obj = of_action_set_dl_src_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_SET_DL_SRC);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_SET_DL_SRC);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_set_dl_src_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_set_dl_src_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_action_set_dl_src_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_set_mpls_label_OF_VERSION_1_1(void)
{
    of_action_set_mpls_label_t *obj;
    obj = of_action_set_mpls_label_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_SET_MPLS_LABEL);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_SET_MPLS_LABEL);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_set_mpls_label_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_set_mpls_label_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_action_set_mpls_label_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_set_mpls_tc_OF_VERSION_1_1(void)
{
    of_action_set_mpls_tc_t *obj;
    obj = of_action_set_mpls_tc_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_SET_MPLS_TC);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_SET_MPLS_TC);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_set_mpls_tc_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_set_mpls_tc_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_action_set_mpls_tc_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_set_mpls_ttl_OF_VERSION_1_1(void)
{
    of_action_set_mpls_ttl_t *obj;
    obj = of_action_set_mpls_ttl_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_SET_MPLS_TTL);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_SET_MPLS_TTL);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_set_mpls_ttl_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_set_mpls_ttl_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_action_set_mpls_ttl_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_set_nw_dst_OF_VERSION_1_1(void)
{
    of_action_set_nw_dst_t *obj;
    obj = of_action_set_nw_dst_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_SET_NW_DST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_SET_NW_DST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_set_nw_dst_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_set_nw_dst_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_action_set_nw_dst_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_set_nw_ecn_OF_VERSION_1_1(void)
{
    of_action_set_nw_ecn_t *obj;
    obj = of_action_set_nw_ecn_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_SET_NW_ECN);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_SET_NW_ECN);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_set_nw_ecn_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_set_nw_ecn_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_action_set_nw_ecn_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_set_nw_src_OF_VERSION_1_1(void)
{
    of_action_set_nw_src_t *obj;
    obj = of_action_set_nw_src_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_SET_NW_SRC);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_SET_NW_SRC);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_set_nw_src_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_set_nw_src_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_action_set_nw_src_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_set_nw_tos_OF_VERSION_1_1(void)
{
    of_action_set_nw_tos_t *obj;
    obj = of_action_set_nw_tos_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_SET_NW_TOS);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_SET_NW_TOS);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_set_nw_tos_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_set_nw_tos_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_action_set_nw_tos_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_set_nw_ttl_OF_VERSION_1_1(void)
{
    of_action_set_nw_ttl_t *obj;
    obj = of_action_set_nw_ttl_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_SET_NW_TTL);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_SET_NW_TTL);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_set_nw_ttl_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_set_nw_ttl_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_action_set_nw_ttl_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_set_queue_OF_VERSION_1_1(void)
{
    of_action_set_queue_t *obj;
    obj = of_action_set_queue_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_SET_QUEUE);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_SET_QUEUE);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_set_queue_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_set_queue_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_action_set_queue_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_set_tp_dst_OF_VERSION_1_1(void)
{
    of_action_set_tp_dst_t *obj;
    obj = of_action_set_tp_dst_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_SET_TP_DST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_SET_TP_DST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_set_tp_dst_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_set_tp_dst_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_action_set_tp_dst_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_set_tp_src_OF_VERSION_1_1(void)
{
    of_action_set_tp_src_t *obj;
    obj = of_action_set_tp_src_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_SET_TP_SRC);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_SET_TP_SRC);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_set_tp_src_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_set_tp_src_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_action_set_tp_src_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_set_vlan_pcp_OF_VERSION_1_1(void)
{
    of_action_set_vlan_pcp_t *obj;
    obj = of_action_set_vlan_pcp_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_SET_VLAN_PCP);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_SET_VLAN_PCP);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_set_vlan_pcp_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_set_vlan_pcp_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_action_set_vlan_pcp_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_set_vlan_vid_OF_VERSION_1_1(void)
{
    of_action_set_vlan_vid_t *obj;
    obj = of_action_set_vlan_vid_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_SET_VLAN_VID);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_SET_VLAN_VID);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_set_vlan_vid_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_set_vlan_vid_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_action_set_vlan_vid_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_interface_OF_VERSION_1_1(void)
{
    of_bsn_interface_t *obj;
    obj = of_bsn_interface_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 32);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_INTERFACE);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 32);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_INTERFACE);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_interface_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_interface_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_bsn_interface_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_vport_header_OF_VERSION_1_1(void)
{
    of_bsn_vport_header_t *obj;
    obj = of_bsn_vport_header_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 4);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_VPORT_HEADER);

    of_bsn_vport_header_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_vport_q_in_q_OF_VERSION_1_1(void)
{
    of_bsn_vport_q_in_q_t *obj;
    obj = of_bsn_vport_q_in_q_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 32);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_VPORT_Q_IN_Q);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 32);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_VPORT_Q_IN_Q);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_vport_q_in_q_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_vport_q_in_q_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_bsn_vport_q_in_q_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bucket_OF_VERSION_1_1(void)
{
    of_bucket_t *obj;
    obj = of_bucket_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BUCKET);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BUCKET);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bucket_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bucket_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_bucket_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bucket_counter_OF_VERSION_1_1(void)
{
    of_bucket_counter_t *obj;
    obj = of_bucket_counter_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BUCKET_COUNTER);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BUCKET_COUNTER);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bucket_counter_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bucket_counter_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_bucket_counter_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_flow_stats_entry_OF_VERSION_1_1(void)
{
    of_flow_stats_entry_t *obj;
    obj = of_flow_stats_entry_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 136);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_STATS_ENTRY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 136);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_FLOW_STATS_ENTRY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_flow_stats_entry_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_flow_stats_entry_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_flow_stats_entry_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_group_desc_stats_entry_OF_VERSION_1_1(void)
{
    of_group_desc_stats_entry_t *obj;
    obj = of_group_desc_stats_entry_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_GROUP_DESC_STATS_ENTRY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_GROUP_DESC_STATS_ENTRY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_group_desc_stats_entry_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_group_desc_stats_entry_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_group_desc_stats_entry_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_group_stats_entry_OF_VERSION_1_1(void)
{
    of_group_stats_entry_t *obj;
    obj = of_group_stats_entry_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 32);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_GROUP_STATS_ENTRY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 32);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_GROUP_STATS_ENTRY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_group_stats_entry_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_group_stats_entry_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_group_stats_entry_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_header_OF_VERSION_1_1(void)
{
    of_header_t *obj;
    obj = of_header_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_HEADER);

    of_header_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_instruction_apply_actions_OF_VERSION_1_1(void)
{
    of_instruction_apply_actions_t *obj;
    obj = of_instruction_apply_actions_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_INSTRUCTION_APPLY_ACTIONS);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_INSTRUCTION_APPLY_ACTIONS);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_instruction_apply_actions_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_instruction_apply_actions_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_instruction_apply_actions_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_instruction_clear_actions_OF_VERSION_1_1(void)
{
    of_instruction_clear_actions_t *obj;
    obj = of_instruction_clear_actions_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_INSTRUCTION_CLEAR_ACTIONS);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_INSTRUCTION_CLEAR_ACTIONS);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_instruction_clear_actions_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_instruction_clear_actions_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_instruction_clear_actions_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_instruction_experimenter_OF_VERSION_1_1(void)
{
    of_instruction_experimenter_t *obj;
    obj = of_instruction_experimenter_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_INSTRUCTION_EXPERIMENTER);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_INSTRUCTION_EXPERIMENTER);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_instruction_experimenter_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_instruction_experimenter_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_instruction_experimenter_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_instruction_goto_table_OF_VERSION_1_1(void)
{
    of_instruction_goto_table_t *obj;
    obj = of_instruction_goto_table_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_INSTRUCTION_GOTO_TABLE);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_INSTRUCTION_GOTO_TABLE);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_instruction_goto_table_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_instruction_goto_table_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_instruction_goto_table_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_instruction_header_OF_VERSION_1_1(void)
{
    of_instruction_header_t *obj;
    obj = of_instruction_header_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_INSTRUCTION_HEADER);

    of_instruction_header_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_instruction_write_actions_OF_VERSION_1_1(void)
{
    of_instruction_write_actions_t *obj;
    obj = of_instruction_write_actions_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_INSTRUCTION_WRITE_ACTIONS);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_INSTRUCTION_WRITE_ACTIONS);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_instruction_write_actions_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_instruction_write_actions_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_instruction_write_actions_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_instruction_write_metadata_OF_VERSION_1_1(void)
{
    of_instruction_write_metadata_t *obj;
    obj = of_instruction_write_metadata_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_INSTRUCTION_WRITE_METADATA);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 24);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_INSTRUCTION_WRITE_METADATA);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_instruction_write_metadata_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_instruction_write_metadata_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_instruction_write_metadata_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_match_v2_OF_VERSION_1_1(void)
{
    of_match_v2_t *obj;
    obj = of_match_v2_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 88);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_MATCH_V2);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 88);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_MATCH_V2);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_match_v2_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_match_v2_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_match_v2_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_packet_queue_OF_VERSION_1_1(void)
{
    of_packet_queue_t *obj;
    obj = of_packet_queue_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_PACKET_QUEUE);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_PACKET_QUEUE);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_packet_queue_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_packet_queue_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_packet_queue_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_port_desc_OF_VERSION_1_1(void)
{
    of_port_desc_t *obj;
    obj = of_port_desc_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 64);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_PORT_DESC);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 64);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_PORT_DESC);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_port_desc_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_port_desc_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_port_desc_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_port_stats_entry_OF_VERSION_1_1(void)
{
    of_port_stats_entry_t *obj;
    obj = of_port_stats_entry_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 104);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_PORT_STATS_ENTRY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 104);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_PORT_STATS_ENTRY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_port_stats_entry_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_port_stats_entry_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_port_stats_entry_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_queue_prop_header_OF_VERSION_1_1(void)
{
    of_queue_prop_header_t *obj;
    obj = of_queue_prop_header_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_QUEUE_PROP_HEADER);

    of_queue_prop_header_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_queue_prop_min_rate_OF_VERSION_1_1(void)
{
    of_queue_prop_min_rate_t *obj;
    obj = of_queue_prop_min_rate_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_QUEUE_PROP_MIN_RATE);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_QUEUE_PROP_MIN_RATE);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_queue_prop_min_rate_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_queue_prop_min_rate_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_queue_prop_min_rate_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_queue_stats_entry_OF_VERSION_1_1(void)
{
    of_queue_stats_entry_t *obj;
    obj = of_queue_stats_entry_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 32);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_QUEUE_STATS_ENTRY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 32);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_QUEUE_STATS_ENTRY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_queue_stats_entry_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_queue_stats_entry_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_queue_stats_entry_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_table_stats_entry_OF_VERSION_1_1(void)
{
    of_table_stats_entry_t *obj;
    obj = of_table_stats_entry_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 88);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_TABLE_STATS_ENTRY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 88);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_TABLE_STATS_ENTRY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_table_stats_entry_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_table_stats_entry_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_table_stats_entry_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_list_action_OF_VERSION_1_1(void)
{
    of_list_action_t *obj;
    obj = of_list_action_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 0);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_LIST_ACTION);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 0);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_LIST_ACTION);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_list_action_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_list_action_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_list_action_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_list_bsn_interface_OF_VERSION_1_1(void)
{
    of_list_bsn_interface_t *obj;
    obj = of_list_bsn_interface_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 0);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_LIST_BSN_INTERFACE);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 0);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_LIST_BSN_INTERFACE);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_list_bsn_interface_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_list_bsn_interface_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_list_bsn_interface_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_list_bucket_OF_VERSION_1_1(void)
{
    of_list_bucket_t *obj;
    obj = of_list_bucket_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 0);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_LIST_BUCKET);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 0);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_LIST_BUCKET);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_list_bucket_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_list_bucket_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_list_bucket_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_list_bucket_counter_OF_VERSION_1_1(void)
{
    of_list_bucket_counter_t *obj;
    obj = of_list_bucket_counter_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 0);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_LIST_BUCKET_COUNTER);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 0);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_LIST_BUCKET_COUNTER);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_list_bucket_counter_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_list_bucket_counter_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_list_bucket_counter_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_list_flow_stats_entry_OF_VERSION_1_1(void)
{
    of_list_flow_stats_entry_t *obj;
    obj = of_list_flow_stats_entry_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 0);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_LIST_FLOW_STATS_ENTRY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 0);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_LIST_FLOW_STATS_ENTRY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_list_flow_stats_entry_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_list_flow_stats_entry_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_list_flow_stats_entry_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_list_group_desc_stats_entry_OF_VERSION_1_1(void)
{
    of_list_group_desc_stats_entry_t *obj;
    obj = of_list_group_desc_stats_entry_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 0);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_LIST_GROUP_DESC_STATS_ENTRY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 0);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_LIST_GROUP_DESC_STATS_ENTRY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_list_group_desc_stats_entry_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_list_group_desc_stats_entry_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_list_group_desc_stats_entry_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_list_group_stats_entry_OF_VERSION_1_1(void)
{
    of_list_group_stats_entry_t *obj;
    obj = of_list_group_stats_entry_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 0);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_LIST_GROUP_STATS_ENTRY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 0);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_LIST_GROUP_STATS_ENTRY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_list_group_stats_entry_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_list_group_stats_entry_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_list_group_stats_entry_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_list_instruction_OF_VERSION_1_1(void)
{
    of_list_instruction_t *obj;
    obj = of_list_instruction_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 0);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_LIST_INSTRUCTION);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 0);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_LIST_INSTRUCTION);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_list_instruction_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_list_instruction_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_list_instruction_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_list_packet_queue_OF_VERSION_1_1(void)
{
    of_list_packet_queue_t *obj;
    obj = of_list_packet_queue_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 0);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_LIST_PACKET_QUEUE);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 0);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_LIST_PACKET_QUEUE);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_list_packet_queue_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_list_packet_queue_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_list_packet_queue_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_list_port_desc_OF_VERSION_1_1(void)
{
    of_list_port_desc_t *obj;
    obj = of_list_port_desc_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 0);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_LIST_PORT_DESC);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 0);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_LIST_PORT_DESC);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_list_port_desc_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_list_port_desc_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_list_port_desc_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_list_port_stats_entry_OF_VERSION_1_1(void)
{
    of_list_port_stats_entry_t *obj;
    obj = of_list_port_stats_entry_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 0);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_LIST_PORT_STATS_ENTRY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 0);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_LIST_PORT_STATS_ENTRY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_list_port_stats_entry_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_list_port_stats_entry_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_list_port_stats_entry_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_list_queue_prop_OF_VERSION_1_1(void)
{
    of_list_queue_prop_t *obj;
    obj = of_list_queue_prop_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 0);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_LIST_QUEUE_PROP);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 0);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_LIST_QUEUE_PROP);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_list_queue_prop_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_list_queue_prop_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_list_queue_prop_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_list_queue_stats_entry_OF_VERSION_1_1(void)
{
    of_list_queue_stats_entry_t *obj;
    obj = of_list_queue_stats_entry_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 0);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_LIST_QUEUE_STATS_ENTRY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 0);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_LIST_QUEUE_STATS_ENTRY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_list_queue_stats_entry_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_list_queue_stats_entry_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_list_queue_stats_entry_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_list_table_stats_entry_OF_VERSION_1_1(void)
{
    of_list_table_stats_entry_t *obj;
    obj = of_list_table_stats_entry_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 0);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_LIST_TABLE_STATS_ENTRY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 0);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_LIST_TABLE_STATS_ENTRY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_list_table_stats_entry_OF_VERSION_1_1_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_list_table_stats_entry_OF_VERSION_1_1_check(
        obj, 1) != 0);

    of_list_table_stats_entry_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_aggregate_stats_reply_OF_VERSION_1_2(void)
{
    of_aggregate_stats_reply_t *obj;
    obj = of_aggregate_stats_reply_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 40);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_AGGREGATE_STATS_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 40);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_AGGREGATE_STATS_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_aggregate_stats_reply_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_aggregate_stats_reply_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_aggregate_stats_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_aggregate_stats_request_OF_VERSION_1_2(void)
{
    of_aggregate_stats_request_t *obj;
    obj = of_aggregate_stats_request_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 56);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_AGGREGATE_STATS_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 56);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_AGGREGATE_STATS_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_aggregate_stats_request_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_aggregate_stats_request_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_aggregate_stats_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bad_action_error_msg_OF_VERSION_1_2(void)
{
    of_bad_action_error_msg_t *obj;
    obj = of_bad_action_error_msg_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BAD_ACTION_ERROR_MSG);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BAD_ACTION_ERROR_MSG);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bad_action_error_msg_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bad_action_error_msg_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_bad_action_error_msg_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bad_instruction_error_msg_OF_VERSION_1_2(void)
{
    of_bad_instruction_error_msg_t *obj;
    obj = of_bad_instruction_error_msg_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BAD_INSTRUCTION_ERROR_MSG);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BAD_INSTRUCTION_ERROR_MSG);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bad_instruction_error_msg_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bad_instruction_error_msg_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_bad_instruction_error_msg_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bad_match_error_msg_OF_VERSION_1_2(void)
{
    of_bad_match_error_msg_t *obj;
    obj = of_bad_match_error_msg_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BAD_MATCH_ERROR_MSG);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BAD_MATCH_ERROR_MSG);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bad_match_error_msg_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bad_match_error_msg_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_bad_match_error_msg_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bad_request_error_msg_OF_VERSION_1_2(void)
{
    of_bad_request_error_msg_t *obj;
    obj = of_bad_request_error_msg_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BAD_REQUEST_ERROR_MSG);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BAD_REQUEST_ERROR_MSG);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bad_request_error_msg_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bad_request_error_msg_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_bad_request_error_msg_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_barrier_reply_OF_VERSION_1_2(void)
{
    of_barrier_reply_t *obj;
    obj = of_barrier_reply_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BARRIER_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BARRIER_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_barrier_reply_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_barrier_reply_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_barrier_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_barrier_request_OF_VERSION_1_2(void)
{
    of_barrier_request_t *obj;
    obj = of_barrier_request_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BARRIER_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BARRIER_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_barrier_request_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_barrier_request_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_barrier_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_bw_clear_data_reply_OF_VERSION_1_2(void)
{
    of_bsn_bw_clear_data_reply_t *obj;
    obj = of_bsn_bw_clear_data_reply_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_BW_CLEAR_DATA_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 20);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_BW_CLEAR_DATA_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_bw_clear_data_reply_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_bw_clear_data_reply_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_bsn_bw_clear_data_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_bw_clear_data_request_OF_VERSION_1_2(void)
{
    of_bsn_bw_clear_data_request_t *obj;
    obj = of_bsn_bw_clear_data_request_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_BW_CLEAR_DATA_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_BW_CLEAR_DATA_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_bw_clear_data_request_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_bw_clear_data_request_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_bsn_bw_clear_data_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_bw_enable_get_reply_OF_VERSION_1_2(void)
{
    of_bsn_bw_enable_get_reply_t *obj;
    obj = of_bsn_bw_enable_get_reply_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_BW_ENABLE_GET_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 20);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_BW_ENABLE_GET_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_bw_enable_get_reply_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_bw_enable_get_reply_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_bsn_bw_enable_get_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_bw_enable_get_request_OF_VERSION_1_2(void)
{
    of_bsn_bw_enable_get_request_t *obj;
    obj = of_bsn_bw_enable_get_request_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_BW_ENABLE_GET_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_BW_ENABLE_GET_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_bw_enable_get_request_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_bw_enable_get_request_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_bsn_bw_enable_get_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_bw_enable_set_reply_OF_VERSION_1_2(void)
{
    of_bsn_bw_enable_set_reply_t *obj;
    obj = of_bsn_bw_enable_set_reply_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_BW_ENABLE_SET_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 24);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_BW_ENABLE_SET_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_bw_enable_set_reply_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_bw_enable_set_reply_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_bsn_bw_enable_set_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_bw_enable_set_request_OF_VERSION_1_2(void)
{
    of_bsn_bw_enable_set_request_t *obj;
    obj = of_bsn_bw_enable_set_request_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_BW_ENABLE_SET_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 20);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_BW_ENABLE_SET_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_bw_enable_set_request_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_bw_enable_set_request_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_bsn_bw_enable_set_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_get_interfaces_reply_OF_VERSION_1_2(void)
{
    of_bsn_get_interfaces_reply_t *obj;
    obj = of_bsn_get_interfaces_reply_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GET_INTERFACES_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_GET_INTERFACES_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_get_interfaces_reply_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_get_interfaces_reply_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_bsn_get_interfaces_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_get_interfaces_request_OF_VERSION_1_2(void)
{
    of_bsn_get_interfaces_request_t *obj;
    obj = of_bsn_get_interfaces_request_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GET_INTERFACES_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_GET_INTERFACES_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_get_interfaces_request_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_get_interfaces_request_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_bsn_get_interfaces_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_get_mirroring_reply_OF_VERSION_1_2(void)
{
    of_bsn_get_mirroring_reply_t *obj;
    obj = of_bsn_get_mirroring_reply_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GET_MIRRORING_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 20);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_GET_MIRRORING_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_get_mirroring_reply_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_get_mirroring_reply_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_bsn_get_mirroring_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_get_mirroring_request_OF_VERSION_1_2(void)
{
    of_bsn_get_mirroring_request_t *obj;
    obj = of_bsn_get_mirroring_request_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GET_MIRRORING_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 20);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_GET_MIRRORING_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_get_mirroring_request_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_get_mirroring_request_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_bsn_get_mirroring_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_header_OF_VERSION_1_2(void)
{
    of_bsn_header_t *obj;
    obj = of_bsn_header_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_HEADER);

    of_bsn_header_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_pdu_rx_reply_OF_VERSION_1_2(void)
{
    of_bsn_pdu_rx_reply_t *obj;
    obj = of_bsn_pdu_rx_reply_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 25);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_PDU_RX_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 25);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_PDU_RX_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_pdu_rx_reply_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_pdu_rx_reply_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_bsn_pdu_rx_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_pdu_rx_request_OF_VERSION_1_2(void)
{
    of_bsn_pdu_rx_request_t *obj;
    obj = of_bsn_pdu_rx_request_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 28);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_PDU_RX_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 28);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_PDU_RX_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_pdu_rx_request_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_pdu_rx_request_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_bsn_pdu_rx_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_pdu_rx_timeout_OF_VERSION_1_2(void)
{
    of_bsn_pdu_rx_timeout_t *obj;
    obj = of_bsn_pdu_rx_timeout_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 21);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_PDU_RX_TIMEOUT);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 21);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_PDU_RX_TIMEOUT);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_pdu_rx_timeout_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_pdu_rx_timeout_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_bsn_pdu_rx_timeout_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_pdu_tx_reply_OF_VERSION_1_2(void)
{
    of_bsn_pdu_tx_reply_t *obj;
    obj = of_bsn_pdu_tx_reply_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 25);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_PDU_TX_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 25);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_PDU_TX_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_pdu_tx_reply_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_pdu_tx_reply_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_bsn_pdu_tx_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_pdu_tx_request_OF_VERSION_1_2(void)
{
    of_bsn_pdu_tx_request_t *obj;
    obj = of_bsn_pdu_tx_request_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 28);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_PDU_TX_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 28);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_PDU_TX_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_pdu_tx_request_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_pdu_tx_request_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_bsn_pdu_tx_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_set_mirroring_OF_VERSION_1_2(void)
{
    of_bsn_set_mirroring_t *obj;
    obj = of_bsn_set_mirroring_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_SET_MIRRORING);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 20);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_SET_MIRRORING);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_set_mirroring_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_set_mirroring_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_bsn_set_mirroring_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_set_pktin_suppression_reply_OF_VERSION_1_2(void)
{
    of_bsn_set_pktin_suppression_reply_t *obj;
    obj = of_bsn_set_pktin_suppression_reply_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_SET_PKTIN_SUPPRESSION_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 20);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_SET_PKTIN_SUPPRESSION_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_set_pktin_suppression_reply_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_set_pktin_suppression_reply_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_bsn_set_pktin_suppression_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_set_pktin_suppression_request_OF_VERSION_1_2(void)
{
    of_bsn_set_pktin_suppression_request_t *obj;
    obj = of_bsn_set_pktin_suppression_request_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 32);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_SET_PKTIN_SUPPRESSION_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 32);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_SET_PKTIN_SUPPRESSION_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_set_pktin_suppression_request_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_set_pktin_suppression_request_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_bsn_set_pktin_suppression_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_stats_reply_OF_VERSION_1_2(void)
{
    of_bsn_stats_reply_t *obj;
    obj = of_bsn_stats_reply_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_STATS_REPLY);

    of_bsn_stats_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_stats_request_OF_VERSION_1_2(void)
{
    of_bsn_stats_request_t *obj;
    obj = of_bsn_stats_request_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_STATS_REQUEST);

    of_bsn_stats_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_virtual_port_create_reply_OF_VERSION_1_2(void)
{
    of_bsn_virtual_port_create_reply_t *obj;
    obj = of_bsn_virtual_port_create_reply_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_VIRTUAL_PORT_CREATE_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 24);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_VIRTUAL_PORT_CREATE_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_virtual_port_create_reply_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_virtual_port_create_reply_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_bsn_virtual_port_create_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_virtual_port_create_request_OF_VERSION_1_2(void)
{
    of_bsn_virtual_port_create_request_t *obj;
    obj = of_bsn_virtual_port_create_request_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 48);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_VIRTUAL_PORT_CREATE_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 48);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_VIRTUAL_PORT_CREATE_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_virtual_port_create_request_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_virtual_port_create_request_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_bsn_virtual_port_create_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_virtual_port_remove_reply_OF_VERSION_1_2(void)
{
    of_bsn_virtual_port_remove_reply_t *obj;
    obj = of_bsn_virtual_port_remove_reply_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_VIRTUAL_PORT_REMOVE_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 20);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_VIRTUAL_PORT_REMOVE_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_virtual_port_remove_reply_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_virtual_port_remove_reply_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_bsn_virtual_port_remove_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_virtual_port_remove_request_OF_VERSION_1_2(void)
{
    of_bsn_virtual_port_remove_request_t *obj;
    obj = of_bsn_virtual_port_remove_request_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_VIRTUAL_PORT_REMOVE_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 20);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_VIRTUAL_PORT_REMOVE_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_virtual_port_remove_request_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_virtual_port_remove_request_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_bsn_virtual_port_remove_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_desc_stats_reply_OF_VERSION_1_2(void)
{
    of_desc_stats_reply_t *obj;
    obj = of_desc_stats_reply_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 1072);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_DESC_STATS_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 1072);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_DESC_STATS_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_desc_stats_reply_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_desc_stats_reply_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_desc_stats_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_desc_stats_request_OF_VERSION_1_2(void)
{
    of_desc_stats_request_t *obj;
    obj = of_desc_stats_request_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_DESC_STATS_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_DESC_STATS_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_desc_stats_request_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_desc_stats_request_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_desc_stats_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_echo_reply_OF_VERSION_1_2(void)
{
    of_echo_reply_t *obj;
    obj = of_echo_reply_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ECHO_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ECHO_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_echo_reply_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_echo_reply_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_echo_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_echo_request_OF_VERSION_1_2(void)
{
    of_echo_request_t *obj;
    obj = of_echo_request_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ECHO_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ECHO_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_echo_request_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_echo_request_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_echo_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_error_msg_OF_VERSION_1_2(void)
{
    of_error_msg_t *obj;
    obj = of_error_msg_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 10);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ERROR_MSG);

    of_error_msg_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_experimenter_OF_VERSION_1_2(void)
{
    of_experimenter_t *obj;
    obj = of_experimenter_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_EXPERIMENTER);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_EXPERIMENTER);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_experimenter_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_experimenter_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_experimenter_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_experimenter_error_msg_OF_VERSION_1_2(void)
{
    of_experimenter_error_msg_t *obj;
    obj = of_experimenter_error_msg_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_EXPERIMENTER_ERROR_MSG);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_EXPERIMENTER_ERROR_MSG);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_experimenter_error_msg_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_experimenter_error_msg_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_experimenter_error_msg_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_experimenter_stats_reply_OF_VERSION_1_2(void)
{
    of_experimenter_stats_reply_t *obj;
    obj = of_experimenter_stats_reply_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_EXPERIMENTER_STATS_REPLY);

    of_experimenter_stats_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_experimenter_stats_request_OF_VERSION_1_2(void)
{
    of_experimenter_stats_request_t *obj;
    obj = of_experimenter_stats_request_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_EXPERIMENTER_STATS_REQUEST);

    of_experimenter_stats_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_features_reply_OF_VERSION_1_2(void)
{
    of_features_reply_t *obj;
    obj = of_features_reply_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 32);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FEATURES_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 32);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_FEATURES_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_features_reply_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_features_reply_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_features_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_features_request_OF_VERSION_1_2(void)
{
    of_features_request_t *obj;
    obj = of_features_request_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FEATURES_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_FEATURES_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_features_request_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_features_request_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_features_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_flow_add_OF_VERSION_1_2(void)
{
    of_flow_add_t *obj;
    obj = of_flow_add_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 56);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_ADD);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 56);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_FLOW_ADD);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_flow_add_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_flow_add_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_flow_add_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_flow_delete_OF_VERSION_1_2(void)
{
    of_flow_delete_t *obj;
    obj = of_flow_delete_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 56);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_DELETE);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 56);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_FLOW_DELETE);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_flow_delete_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_flow_delete_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_flow_delete_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_flow_delete_strict_OF_VERSION_1_2(void)
{
    of_flow_delete_strict_t *obj;
    obj = of_flow_delete_strict_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 56);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_DELETE_STRICT);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 56);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_FLOW_DELETE_STRICT);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_flow_delete_strict_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_flow_delete_strict_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_flow_delete_strict_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_flow_mod_OF_VERSION_1_2(void)
{
    of_flow_mod_t *obj;
    obj = of_flow_mod_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 56);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_MOD);

    of_flow_mod_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_flow_mod_failed_error_msg_OF_VERSION_1_2(void)
{
    of_flow_mod_failed_error_msg_t *obj;
    obj = of_flow_mod_failed_error_msg_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_MOD_FAILED_ERROR_MSG);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_FLOW_MOD_FAILED_ERROR_MSG);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_flow_mod_failed_error_msg_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_flow_mod_failed_error_msg_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_flow_mod_failed_error_msg_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_flow_modify_OF_VERSION_1_2(void)
{
    of_flow_modify_t *obj;
    obj = of_flow_modify_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 56);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_MODIFY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 56);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_FLOW_MODIFY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_flow_modify_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_flow_modify_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_flow_modify_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_flow_modify_strict_OF_VERSION_1_2(void)
{
    of_flow_modify_strict_t *obj;
    obj = of_flow_modify_strict_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 56);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_MODIFY_STRICT);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 56);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_FLOW_MODIFY_STRICT);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_flow_modify_strict_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_flow_modify_strict_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_flow_modify_strict_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_flow_removed_OF_VERSION_1_2(void)
{
    of_flow_removed_t *obj;
    obj = of_flow_removed_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 56);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_REMOVED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 56);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_FLOW_REMOVED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_flow_removed_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_flow_removed_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_flow_removed_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_flow_stats_reply_OF_VERSION_1_2(void)
{
    of_flow_stats_reply_t *obj;
    obj = of_flow_stats_reply_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_STATS_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_FLOW_STATS_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_flow_stats_reply_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_flow_stats_reply_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_flow_stats_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_flow_stats_request_OF_VERSION_1_2(void)
{
    of_flow_stats_request_t *obj;
    obj = of_flow_stats_request_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 56);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_STATS_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 56);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_FLOW_STATS_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_flow_stats_request_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_flow_stats_request_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_flow_stats_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_get_config_reply_OF_VERSION_1_2(void)
{
    of_get_config_reply_t *obj;
    obj = of_get_config_reply_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_GET_CONFIG_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_GET_CONFIG_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_get_config_reply_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_get_config_reply_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_get_config_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_get_config_request_OF_VERSION_1_2(void)
{
    of_get_config_request_t *obj;
    obj = of_get_config_request_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_GET_CONFIG_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_GET_CONFIG_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_get_config_request_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_get_config_request_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_get_config_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_group_desc_stats_reply_OF_VERSION_1_2(void)
{
    of_group_desc_stats_reply_t *obj;
    obj = of_group_desc_stats_reply_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_GROUP_DESC_STATS_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_GROUP_DESC_STATS_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_group_desc_stats_reply_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_group_desc_stats_reply_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_group_desc_stats_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_group_desc_stats_request_OF_VERSION_1_2(void)
{
    of_group_desc_stats_request_t *obj;
    obj = of_group_desc_stats_request_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_GROUP_DESC_STATS_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_GROUP_DESC_STATS_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_group_desc_stats_request_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_group_desc_stats_request_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_group_desc_stats_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_group_features_stats_reply_OF_VERSION_1_2(void)
{
    of_group_features_stats_reply_t *obj;
    obj = of_group_features_stats_reply_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 56);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_GROUP_FEATURES_STATS_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 56);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_GROUP_FEATURES_STATS_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_group_features_stats_reply_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_group_features_stats_reply_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_group_features_stats_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_group_features_stats_request_OF_VERSION_1_2(void)
{
    of_group_features_stats_request_t *obj;
    obj = of_group_features_stats_request_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_GROUP_FEATURES_STATS_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_GROUP_FEATURES_STATS_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_group_features_stats_request_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_group_features_stats_request_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_group_features_stats_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_group_mod_OF_VERSION_1_2(void)
{
    of_group_mod_t *obj;
    obj = of_group_mod_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_GROUP_MOD);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_GROUP_MOD);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_group_mod_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_group_mod_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_group_mod_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_group_mod_failed_error_msg_OF_VERSION_1_2(void)
{
    of_group_mod_failed_error_msg_t *obj;
    obj = of_group_mod_failed_error_msg_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_GROUP_MOD_FAILED_ERROR_MSG);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_GROUP_MOD_FAILED_ERROR_MSG);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_group_mod_failed_error_msg_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_group_mod_failed_error_msg_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_group_mod_failed_error_msg_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_group_stats_reply_OF_VERSION_1_2(void)
{
    of_group_stats_reply_t *obj;
    obj = of_group_stats_reply_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_GROUP_STATS_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_GROUP_STATS_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_group_stats_reply_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_group_stats_reply_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_group_stats_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_group_stats_request_OF_VERSION_1_2(void)
{
    of_group_stats_request_t *obj;
    obj = of_group_stats_request_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_GROUP_STATS_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 24);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_GROUP_STATS_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_group_stats_request_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_group_stats_request_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_group_stats_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_hello_OF_VERSION_1_2(void)
{
    of_hello_t *obj;
    obj = of_hello_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_HELLO);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_HELLO);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_hello_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_hello_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_hello_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_hello_failed_error_msg_OF_VERSION_1_2(void)
{
    of_hello_failed_error_msg_t *obj;
    obj = of_hello_failed_error_msg_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_HELLO_FAILED_ERROR_MSG);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_HELLO_FAILED_ERROR_MSG);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_hello_failed_error_msg_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_hello_failed_error_msg_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_hello_failed_error_msg_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_nicira_header_OF_VERSION_1_2(void)
{
    of_nicira_header_t *obj;
    obj = of_nicira_header_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_NICIRA_HEADER);

    of_nicira_header_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_packet_in_OF_VERSION_1_2(void)
{
    of_packet_in_t *obj;
    obj = of_packet_in_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 26);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_PACKET_IN);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 26);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_PACKET_IN);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_packet_in_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_packet_in_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_packet_in_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_packet_out_OF_VERSION_1_2(void)
{
    of_packet_out_t *obj;
    obj = of_packet_out_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_PACKET_OUT);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 24);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_PACKET_OUT);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_packet_out_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_packet_out_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_packet_out_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_port_mod_OF_VERSION_1_2(void)
{
    of_port_mod_t *obj;
    obj = of_port_mod_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 40);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_PORT_MOD);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 40);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_PORT_MOD);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_port_mod_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_port_mod_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_port_mod_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_port_mod_failed_error_msg_OF_VERSION_1_2(void)
{
    of_port_mod_failed_error_msg_t *obj;
    obj = of_port_mod_failed_error_msg_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_PORT_MOD_FAILED_ERROR_MSG);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_PORT_MOD_FAILED_ERROR_MSG);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_port_mod_failed_error_msg_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_port_mod_failed_error_msg_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_port_mod_failed_error_msg_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_port_stats_reply_OF_VERSION_1_2(void)
{
    of_port_stats_reply_t *obj;
    obj = of_port_stats_reply_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_PORT_STATS_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_PORT_STATS_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_port_stats_reply_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_port_stats_reply_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_port_stats_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_port_stats_request_OF_VERSION_1_2(void)
{
    of_port_stats_request_t *obj;
    obj = of_port_stats_request_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_PORT_STATS_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 24);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_PORT_STATS_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_port_stats_request_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_port_stats_request_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_port_stats_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_port_status_OF_VERSION_1_2(void)
{
    of_port_status_t *obj;
    obj = of_port_status_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 80);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_PORT_STATUS);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 80);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_PORT_STATUS);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_port_status_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_port_status_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_port_status_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_queue_get_config_reply_OF_VERSION_1_2(void)
{
    of_queue_get_config_reply_t *obj;
    obj = of_queue_get_config_reply_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_QUEUE_GET_CONFIG_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_QUEUE_GET_CONFIG_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_queue_get_config_reply_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_queue_get_config_reply_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_queue_get_config_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_queue_get_config_request_OF_VERSION_1_2(void)
{
    of_queue_get_config_request_t *obj;
    obj = of_queue_get_config_request_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_QUEUE_GET_CONFIG_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_QUEUE_GET_CONFIG_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_queue_get_config_request_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_queue_get_config_request_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_queue_get_config_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_queue_op_failed_error_msg_OF_VERSION_1_2(void)
{
    of_queue_op_failed_error_msg_t *obj;
    obj = of_queue_op_failed_error_msg_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_QUEUE_OP_FAILED_ERROR_MSG);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_QUEUE_OP_FAILED_ERROR_MSG);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_queue_op_failed_error_msg_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_queue_op_failed_error_msg_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_queue_op_failed_error_msg_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_queue_stats_reply_OF_VERSION_1_2(void)
{
    of_queue_stats_reply_t *obj;
    obj = of_queue_stats_reply_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_QUEUE_STATS_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_QUEUE_STATS_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_queue_stats_reply_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_queue_stats_reply_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_queue_stats_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_queue_stats_request_OF_VERSION_1_2(void)
{
    of_queue_stats_request_t *obj;
    obj = of_queue_stats_request_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_QUEUE_STATS_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 24);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_QUEUE_STATS_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_queue_stats_request_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_queue_stats_request_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_queue_stats_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_role_reply_OF_VERSION_1_2(void)
{
    of_role_reply_t *obj;
    obj = of_role_reply_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ROLE_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 24);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ROLE_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_role_reply_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_role_reply_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_role_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_role_request_OF_VERSION_1_2(void)
{
    of_role_request_t *obj;
    obj = of_role_request_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ROLE_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 24);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ROLE_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_role_request_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_role_request_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_role_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_role_request_failed_error_msg_OF_VERSION_1_2(void)
{
    of_role_request_failed_error_msg_t *obj;
    obj = of_role_request_failed_error_msg_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ROLE_REQUEST_FAILED_ERROR_MSG);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ROLE_REQUEST_FAILED_ERROR_MSG);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_role_request_failed_error_msg_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_role_request_failed_error_msg_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_role_request_failed_error_msg_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_set_config_OF_VERSION_1_2(void)
{
    of_set_config_t *obj;
    obj = of_set_config_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_SET_CONFIG);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_SET_CONFIG);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_set_config_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_set_config_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_set_config_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_stats_reply_OF_VERSION_1_2(void)
{
    of_stats_reply_t *obj;
    obj = of_stats_reply_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_STATS_REPLY);

    of_stats_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_stats_request_OF_VERSION_1_2(void)
{
    of_stats_request_t *obj;
    obj = of_stats_request_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_STATS_REQUEST);

    of_stats_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_switch_config_failed_error_msg_OF_VERSION_1_2(void)
{
    of_switch_config_failed_error_msg_t *obj;
    obj = of_switch_config_failed_error_msg_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_SWITCH_CONFIG_FAILED_ERROR_MSG);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_SWITCH_CONFIG_FAILED_ERROR_MSG);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_switch_config_failed_error_msg_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_switch_config_failed_error_msg_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_switch_config_failed_error_msg_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_table_mod_OF_VERSION_1_2(void)
{
    of_table_mod_t *obj;
    obj = of_table_mod_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_TABLE_MOD);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_TABLE_MOD);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_table_mod_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_table_mod_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_table_mod_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_table_mod_failed_error_msg_OF_VERSION_1_2(void)
{
    of_table_mod_failed_error_msg_t *obj;
    obj = of_table_mod_failed_error_msg_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_TABLE_MOD_FAILED_ERROR_MSG);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_TABLE_MOD_FAILED_ERROR_MSG);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_table_mod_failed_error_msg_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_table_mod_failed_error_msg_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_table_mod_failed_error_msg_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_table_stats_reply_OF_VERSION_1_2(void)
{
    of_table_stats_reply_t *obj;
    obj = of_table_stats_reply_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_TABLE_STATS_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_TABLE_STATS_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_table_stats_reply_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_table_stats_reply_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_table_stats_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_table_stats_request_OF_VERSION_1_2(void)
{
    of_table_stats_request_t *obj;
    obj = of_table_stats_request_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_TABLE_STATS_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_TABLE_STATS_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_table_stats_request_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_table_stats_request_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_table_stats_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_bsn_OF_VERSION_1_2(void)
{
    of_action_bsn_t *obj;
    obj = of_action_bsn_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_BSN);

    of_action_bsn_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_bsn_mirror_OF_VERSION_1_2(void)
{
    of_action_bsn_mirror_t *obj;
    obj = of_action_bsn_mirror_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_BSN_MIRROR);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 24);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_BSN_MIRROR);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_bsn_mirror_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_bsn_mirror_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_action_bsn_mirror_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_bsn_set_tunnel_dst_OF_VERSION_1_2(void)
{
    of_action_bsn_set_tunnel_dst_t *obj;
    obj = of_action_bsn_set_tunnel_dst_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_BSN_SET_TUNNEL_DST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_BSN_SET_TUNNEL_DST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_bsn_set_tunnel_dst_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_bsn_set_tunnel_dst_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_action_bsn_set_tunnel_dst_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_copy_ttl_in_OF_VERSION_1_2(void)
{
    of_action_copy_ttl_in_t *obj;
    obj = of_action_copy_ttl_in_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_COPY_TTL_IN);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_COPY_TTL_IN);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_copy_ttl_in_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_copy_ttl_in_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_action_copy_ttl_in_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_copy_ttl_out_OF_VERSION_1_2(void)
{
    of_action_copy_ttl_out_t *obj;
    obj = of_action_copy_ttl_out_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_COPY_TTL_OUT);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_COPY_TTL_OUT);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_copy_ttl_out_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_copy_ttl_out_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_action_copy_ttl_out_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_dec_mpls_ttl_OF_VERSION_1_2(void)
{
    of_action_dec_mpls_ttl_t *obj;
    obj = of_action_dec_mpls_ttl_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_DEC_MPLS_TTL);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_DEC_MPLS_TTL);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_dec_mpls_ttl_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_dec_mpls_ttl_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_action_dec_mpls_ttl_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_dec_nw_ttl_OF_VERSION_1_2(void)
{
    of_action_dec_nw_ttl_t *obj;
    obj = of_action_dec_nw_ttl_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_DEC_NW_TTL);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_DEC_NW_TTL);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_dec_nw_ttl_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_dec_nw_ttl_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_action_dec_nw_ttl_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_experimenter_OF_VERSION_1_2(void)
{
    of_action_experimenter_t *obj;
    obj = of_action_experimenter_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_EXPERIMENTER);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_EXPERIMENTER);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_experimenter_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_experimenter_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_action_experimenter_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_group_OF_VERSION_1_2(void)
{
    of_action_group_t *obj;
    obj = of_action_group_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_GROUP);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_GROUP);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_group_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_group_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_action_group_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_header_OF_VERSION_1_2(void)
{
    of_action_header_t *obj;
    obj = of_action_header_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_HEADER);

    of_action_header_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_nicira_OF_VERSION_1_2(void)
{
    of_action_nicira_t *obj;
    obj = of_action_nicira_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_NICIRA);

    of_action_nicira_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_nicira_dec_ttl_OF_VERSION_1_2(void)
{
    of_action_nicira_dec_ttl_t *obj;
    obj = of_action_nicira_dec_ttl_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_NICIRA_DEC_TTL);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_NICIRA_DEC_TTL);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_nicira_dec_ttl_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_nicira_dec_ttl_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_action_nicira_dec_ttl_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_output_OF_VERSION_1_2(void)
{
    of_action_output_t *obj;
    obj = of_action_output_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_OUTPUT);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_OUTPUT);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_output_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_output_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_action_output_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_pop_mpls_OF_VERSION_1_2(void)
{
    of_action_pop_mpls_t *obj;
    obj = of_action_pop_mpls_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_POP_MPLS);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_POP_MPLS);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_pop_mpls_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_pop_mpls_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_action_pop_mpls_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_pop_vlan_OF_VERSION_1_2(void)
{
    of_action_pop_vlan_t *obj;
    obj = of_action_pop_vlan_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_POP_VLAN);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_POP_VLAN);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_pop_vlan_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_pop_vlan_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_action_pop_vlan_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_push_mpls_OF_VERSION_1_2(void)
{
    of_action_push_mpls_t *obj;
    obj = of_action_push_mpls_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_PUSH_MPLS);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_PUSH_MPLS);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_push_mpls_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_push_mpls_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_action_push_mpls_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_push_vlan_OF_VERSION_1_2(void)
{
    of_action_push_vlan_t *obj;
    obj = of_action_push_vlan_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_PUSH_VLAN);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_PUSH_VLAN);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_push_vlan_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_push_vlan_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_action_push_vlan_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_set_field_OF_VERSION_1_2(void)
{
    of_action_set_field_t *obj;
    obj = of_action_set_field_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 4);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_SET_FIELD);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 4);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_SET_FIELD);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_set_field_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_set_field_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_action_set_field_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_set_mpls_ttl_OF_VERSION_1_2(void)
{
    of_action_set_mpls_ttl_t *obj;
    obj = of_action_set_mpls_ttl_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_SET_MPLS_TTL);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_SET_MPLS_TTL);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_set_mpls_ttl_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_set_mpls_ttl_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_action_set_mpls_ttl_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_set_nw_ttl_OF_VERSION_1_2(void)
{
    of_action_set_nw_ttl_t *obj;
    obj = of_action_set_nw_ttl_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_SET_NW_TTL);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_SET_NW_TTL);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_set_nw_ttl_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_set_nw_ttl_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_action_set_nw_ttl_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_set_queue_OF_VERSION_1_2(void)
{
    of_action_set_queue_t *obj;
    obj = of_action_set_queue_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_SET_QUEUE);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_SET_QUEUE);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_set_queue_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_set_queue_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_action_set_queue_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_interface_OF_VERSION_1_2(void)
{
    of_bsn_interface_t *obj;
    obj = of_bsn_interface_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 32);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_INTERFACE);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 32);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_INTERFACE);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_interface_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_interface_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_bsn_interface_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_vport_header_OF_VERSION_1_2(void)
{
    of_bsn_vport_header_t *obj;
    obj = of_bsn_vport_header_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 4);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_VPORT_HEADER);

    of_bsn_vport_header_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_vport_q_in_q_OF_VERSION_1_2(void)
{
    of_bsn_vport_q_in_q_t *obj;
    obj = of_bsn_vport_q_in_q_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 32);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_VPORT_Q_IN_Q);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 32);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_VPORT_Q_IN_Q);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_vport_q_in_q_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_vport_q_in_q_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_bsn_vport_q_in_q_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bucket_OF_VERSION_1_2(void)
{
    of_bucket_t *obj;
    obj = of_bucket_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BUCKET);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BUCKET);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bucket_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bucket_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_bucket_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bucket_counter_OF_VERSION_1_2(void)
{
    of_bucket_counter_t *obj;
    obj = of_bucket_counter_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BUCKET_COUNTER);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BUCKET_COUNTER);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bucket_counter_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bucket_counter_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_bucket_counter_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_flow_stats_entry_OF_VERSION_1_2(void)
{
    of_flow_stats_entry_t *obj;
    obj = of_flow_stats_entry_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 56);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_STATS_ENTRY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 56);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_FLOW_STATS_ENTRY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_flow_stats_entry_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_flow_stats_entry_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_flow_stats_entry_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_group_desc_stats_entry_OF_VERSION_1_2(void)
{
    of_group_desc_stats_entry_t *obj;
    obj = of_group_desc_stats_entry_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_GROUP_DESC_STATS_ENTRY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_GROUP_DESC_STATS_ENTRY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_group_desc_stats_entry_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_group_desc_stats_entry_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_group_desc_stats_entry_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_group_stats_entry_OF_VERSION_1_2(void)
{
    of_group_stats_entry_t *obj;
    obj = of_group_stats_entry_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 32);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_GROUP_STATS_ENTRY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 32);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_GROUP_STATS_ENTRY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_group_stats_entry_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_group_stats_entry_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_group_stats_entry_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_header_OF_VERSION_1_2(void)
{
    of_header_t *obj;
    obj = of_header_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_HEADER);

    of_header_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_instruction_apply_actions_OF_VERSION_1_2(void)
{
    of_instruction_apply_actions_t *obj;
    obj = of_instruction_apply_actions_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_INSTRUCTION_APPLY_ACTIONS);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_INSTRUCTION_APPLY_ACTIONS);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_instruction_apply_actions_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_instruction_apply_actions_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_instruction_apply_actions_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_instruction_clear_actions_OF_VERSION_1_2(void)
{
    of_instruction_clear_actions_t *obj;
    obj = of_instruction_clear_actions_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_INSTRUCTION_CLEAR_ACTIONS);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_INSTRUCTION_CLEAR_ACTIONS);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_instruction_clear_actions_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_instruction_clear_actions_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_instruction_clear_actions_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_instruction_experimenter_OF_VERSION_1_2(void)
{
    of_instruction_experimenter_t *obj;
    obj = of_instruction_experimenter_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_INSTRUCTION_EXPERIMENTER);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_INSTRUCTION_EXPERIMENTER);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_instruction_experimenter_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_instruction_experimenter_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_instruction_experimenter_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_instruction_goto_table_OF_VERSION_1_2(void)
{
    of_instruction_goto_table_t *obj;
    obj = of_instruction_goto_table_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_INSTRUCTION_GOTO_TABLE);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_INSTRUCTION_GOTO_TABLE);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_instruction_goto_table_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_instruction_goto_table_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_instruction_goto_table_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_instruction_header_OF_VERSION_1_2(void)
{
    of_instruction_header_t *obj;
    obj = of_instruction_header_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_INSTRUCTION_HEADER);

    of_instruction_header_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_instruction_write_actions_OF_VERSION_1_2(void)
{
    of_instruction_write_actions_t *obj;
    obj = of_instruction_write_actions_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_INSTRUCTION_WRITE_ACTIONS);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_INSTRUCTION_WRITE_ACTIONS);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_instruction_write_actions_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_instruction_write_actions_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_instruction_write_actions_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_instruction_write_metadata_OF_VERSION_1_2(void)
{
    of_instruction_write_metadata_t *obj;
    obj = of_instruction_write_metadata_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_INSTRUCTION_WRITE_METADATA);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 24);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_INSTRUCTION_WRITE_METADATA);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_instruction_write_metadata_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_instruction_write_metadata_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_instruction_write_metadata_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_match_v3_OF_VERSION_1_2(void)
{
    of_match_v3_t *obj;
    obj = of_match_v3_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 4);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_MATCH_V3);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 4);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_MATCH_V3);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_match_v3_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_match_v3_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_match_v3_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_arp_op_OF_VERSION_1_2(void)
{
    of_oxm_arp_op_t *obj;
    obj = of_oxm_arp_op_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 6);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_ARP_OP);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 6);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_ARP_OP);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_arp_op_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_arp_op_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_oxm_arp_op_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_arp_op_masked_OF_VERSION_1_2(void)
{
    of_oxm_arp_op_masked_t *obj;
    obj = of_oxm_arp_op_masked_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_ARP_OP_MASKED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_ARP_OP_MASKED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_arp_op_masked_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_arp_op_masked_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_oxm_arp_op_masked_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_arp_sha_OF_VERSION_1_2(void)
{
    of_oxm_arp_sha_t *obj;
    obj = of_oxm_arp_sha_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 10);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_ARP_SHA);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 10);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_ARP_SHA);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_arp_sha_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_arp_sha_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_oxm_arp_sha_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_arp_sha_masked_OF_VERSION_1_2(void)
{
    of_oxm_arp_sha_masked_t *obj;
    obj = of_oxm_arp_sha_masked_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_ARP_SHA_MASKED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_ARP_SHA_MASKED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_arp_sha_masked_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_arp_sha_masked_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_oxm_arp_sha_masked_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_arp_spa_OF_VERSION_1_2(void)
{
    of_oxm_arp_spa_t *obj;
    obj = of_oxm_arp_spa_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_ARP_SPA);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_ARP_SPA);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_arp_spa_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_arp_spa_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_oxm_arp_spa_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_arp_spa_masked_OF_VERSION_1_2(void)
{
    of_oxm_arp_spa_masked_t *obj;
    obj = of_oxm_arp_spa_masked_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_ARP_SPA_MASKED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_ARP_SPA_MASKED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_arp_spa_masked_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_arp_spa_masked_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_oxm_arp_spa_masked_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_arp_tha_OF_VERSION_1_2(void)
{
    of_oxm_arp_tha_t *obj;
    obj = of_oxm_arp_tha_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 10);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_ARP_THA);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 10);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_ARP_THA);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_arp_tha_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_arp_tha_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_oxm_arp_tha_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_arp_tha_masked_OF_VERSION_1_2(void)
{
    of_oxm_arp_tha_masked_t *obj;
    obj = of_oxm_arp_tha_masked_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_ARP_THA_MASKED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_ARP_THA_MASKED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_arp_tha_masked_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_arp_tha_masked_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_oxm_arp_tha_masked_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_arp_tpa_OF_VERSION_1_2(void)
{
    of_oxm_arp_tpa_t *obj;
    obj = of_oxm_arp_tpa_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_ARP_TPA);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_ARP_TPA);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_arp_tpa_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_arp_tpa_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_oxm_arp_tpa_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_arp_tpa_masked_OF_VERSION_1_2(void)
{
    of_oxm_arp_tpa_masked_t *obj;
    obj = of_oxm_arp_tpa_masked_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_ARP_TPA_MASKED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_ARP_TPA_MASKED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_arp_tpa_masked_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_arp_tpa_masked_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_oxm_arp_tpa_masked_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_bsn_global_vrf_allowed_OF_VERSION_1_2(void)
{
    of_oxm_bsn_global_vrf_allowed_t *obj;
    obj = of_oxm_bsn_global_vrf_allowed_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 5);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_BSN_GLOBAL_VRF_ALLOWED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 5);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_BSN_GLOBAL_VRF_ALLOWED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_bsn_global_vrf_allowed_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_bsn_global_vrf_allowed_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_oxm_bsn_global_vrf_allowed_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_bsn_global_vrf_allowed_masked_OF_VERSION_1_2(void)
{
    of_oxm_bsn_global_vrf_allowed_masked_t *obj;
    obj = of_oxm_bsn_global_vrf_allowed_masked_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 6);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_BSN_GLOBAL_VRF_ALLOWED_MASKED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 6);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_BSN_GLOBAL_VRF_ALLOWED_MASKED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_bsn_global_vrf_allowed_masked_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_bsn_global_vrf_allowed_masked_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_oxm_bsn_global_vrf_allowed_masked_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_bsn_in_ports_128_OF_VERSION_1_2(void)
{
    of_oxm_bsn_in_ports_128_t *obj;
    obj = of_oxm_bsn_in_ports_128_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_BSN_IN_PORTS_128);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 20);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_BSN_IN_PORTS_128);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_bsn_in_ports_128_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_bsn_in_ports_128_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_oxm_bsn_in_ports_128_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_bsn_in_ports_128_masked_OF_VERSION_1_2(void)
{
    of_oxm_bsn_in_ports_128_masked_t *obj;
    obj = of_oxm_bsn_in_ports_128_masked_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 36);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_BSN_IN_PORTS_128_MASKED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 36);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_BSN_IN_PORTS_128_MASKED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_bsn_in_ports_128_masked_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_bsn_in_ports_128_masked_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_oxm_bsn_in_ports_128_masked_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_bsn_l3_dst_class_id_OF_VERSION_1_2(void)
{
    of_oxm_bsn_l3_dst_class_id_t *obj;
    obj = of_oxm_bsn_l3_dst_class_id_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_BSN_L3_DST_CLASS_ID);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_BSN_L3_DST_CLASS_ID);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_bsn_l3_dst_class_id_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_bsn_l3_dst_class_id_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_oxm_bsn_l3_dst_class_id_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_bsn_l3_dst_class_id_masked_OF_VERSION_1_2(void)
{
    of_oxm_bsn_l3_dst_class_id_masked_t *obj;
    obj = of_oxm_bsn_l3_dst_class_id_masked_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_BSN_L3_DST_CLASS_ID_MASKED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_BSN_L3_DST_CLASS_ID_MASKED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_bsn_l3_dst_class_id_masked_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_bsn_l3_dst_class_id_masked_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_oxm_bsn_l3_dst_class_id_masked_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_bsn_l3_interface_class_id_OF_VERSION_1_2(void)
{
    of_oxm_bsn_l3_interface_class_id_t *obj;
    obj = of_oxm_bsn_l3_interface_class_id_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_BSN_L3_INTERFACE_CLASS_ID);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_BSN_L3_INTERFACE_CLASS_ID);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_bsn_l3_interface_class_id_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_bsn_l3_interface_class_id_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_oxm_bsn_l3_interface_class_id_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_bsn_l3_interface_class_id_masked_OF_VERSION_1_2(void)
{
    of_oxm_bsn_l3_interface_class_id_masked_t *obj;
    obj = of_oxm_bsn_l3_interface_class_id_masked_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_BSN_L3_INTERFACE_CLASS_ID_MASKED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_BSN_L3_INTERFACE_CLASS_ID_MASKED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_bsn_l3_interface_class_id_masked_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_bsn_l3_interface_class_id_masked_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_oxm_bsn_l3_interface_class_id_masked_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_bsn_l3_src_class_id_OF_VERSION_1_2(void)
{
    of_oxm_bsn_l3_src_class_id_t *obj;
    obj = of_oxm_bsn_l3_src_class_id_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_BSN_L3_SRC_CLASS_ID);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_BSN_L3_SRC_CLASS_ID);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_bsn_l3_src_class_id_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_bsn_l3_src_class_id_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_oxm_bsn_l3_src_class_id_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_bsn_l3_src_class_id_masked_OF_VERSION_1_2(void)
{
    of_oxm_bsn_l3_src_class_id_masked_t *obj;
    obj = of_oxm_bsn_l3_src_class_id_masked_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_BSN_L3_SRC_CLASS_ID_MASKED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_BSN_L3_SRC_CLASS_ID_MASKED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_bsn_l3_src_class_id_masked_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_bsn_l3_src_class_id_masked_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_oxm_bsn_l3_src_class_id_masked_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_bsn_lag_id_OF_VERSION_1_2(void)
{
    of_oxm_bsn_lag_id_t *obj;
    obj = of_oxm_bsn_lag_id_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_BSN_LAG_ID);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_BSN_LAG_ID);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_bsn_lag_id_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_bsn_lag_id_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_oxm_bsn_lag_id_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_bsn_lag_id_masked_OF_VERSION_1_2(void)
{
    of_oxm_bsn_lag_id_masked_t *obj;
    obj = of_oxm_bsn_lag_id_masked_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_BSN_LAG_ID_MASKED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_BSN_LAG_ID_MASKED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_bsn_lag_id_masked_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_bsn_lag_id_masked_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_oxm_bsn_lag_id_masked_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_bsn_vrf_OF_VERSION_1_2(void)
{
    of_oxm_bsn_vrf_t *obj;
    obj = of_oxm_bsn_vrf_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_BSN_VRF);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_BSN_VRF);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_bsn_vrf_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_bsn_vrf_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_oxm_bsn_vrf_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_bsn_vrf_masked_OF_VERSION_1_2(void)
{
    of_oxm_bsn_vrf_masked_t *obj;
    obj = of_oxm_bsn_vrf_masked_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_BSN_VRF_MASKED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_BSN_VRF_MASKED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_bsn_vrf_masked_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_bsn_vrf_masked_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_oxm_bsn_vrf_masked_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_eth_dst_OF_VERSION_1_2(void)
{
    of_oxm_eth_dst_t *obj;
    obj = of_oxm_eth_dst_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 10);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_ETH_DST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 10);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_ETH_DST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_eth_dst_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_eth_dst_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_oxm_eth_dst_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_eth_dst_masked_OF_VERSION_1_2(void)
{
    of_oxm_eth_dst_masked_t *obj;
    obj = of_oxm_eth_dst_masked_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_ETH_DST_MASKED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_ETH_DST_MASKED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_eth_dst_masked_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_eth_dst_masked_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_oxm_eth_dst_masked_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_eth_src_OF_VERSION_1_2(void)
{
    of_oxm_eth_src_t *obj;
    obj = of_oxm_eth_src_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 10);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_ETH_SRC);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 10);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_ETH_SRC);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_eth_src_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_eth_src_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_oxm_eth_src_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_eth_src_masked_OF_VERSION_1_2(void)
{
    of_oxm_eth_src_masked_t *obj;
    obj = of_oxm_eth_src_masked_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_ETH_SRC_MASKED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_ETH_SRC_MASKED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_eth_src_masked_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_eth_src_masked_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_oxm_eth_src_masked_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_eth_type_OF_VERSION_1_2(void)
{
    of_oxm_eth_type_t *obj;
    obj = of_oxm_eth_type_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 6);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_ETH_TYPE);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 6);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_ETH_TYPE);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_eth_type_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_eth_type_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_oxm_eth_type_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_eth_type_masked_OF_VERSION_1_2(void)
{
    of_oxm_eth_type_masked_t *obj;
    obj = of_oxm_eth_type_masked_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_ETH_TYPE_MASKED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_ETH_TYPE_MASKED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_eth_type_masked_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_eth_type_masked_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_oxm_eth_type_masked_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_header_OF_VERSION_1_2(void)
{
    of_oxm_header_t *obj;
    obj = of_oxm_header_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 4);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_HEADER);

    of_oxm_header_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_icmpv4_code_OF_VERSION_1_2(void)
{
    of_oxm_icmpv4_code_t *obj;
    obj = of_oxm_icmpv4_code_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 5);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_ICMPV4_CODE);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 5);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_ICMPV4_CODE);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_icmpv4_code_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_icmpv4_code_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_oxm_icmpv4_code_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_icmpv4_code_masked_OF_VERSION_1_2(void)
{
    of_oxm_icmpv4_code_masked_t *obj;
    obj = of_oxm_icmpv4_code_masked_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 6);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_ICMPV4_CODE_MASKED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 6);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_ICMPV4_CODE_MASKED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_icmpv4_code_masked_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_icmpv4_code_masked_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_oxm_icmpv4_code_masked_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_icmpv4_type_OF_VERSION_1_2(void)
{
    of_oxm_icmpv4_type_t *obj;
    obj = of_oxm_icmpv4_type_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 5);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_ICMPV4_TYPE);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 5);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_ICMPV4_TYPE);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_icmpv4_type_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_icmpv4_type_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_oxm_icmpv4_type_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_icmpv4_type_masked_OF_VERSION_1_2(void)
{
    of_oxm_icmpv4_type_masked_t *obj;
    obj = of_oxm_icmpv4_type_masked_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 6);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_ICMPV4_TYPE_MASKED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 6);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_ICMPV4_TYPE_MASKED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_icmpv4_type_masked_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_icmpv4_type_masked_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_oxm_icmpv4_type_masked_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_icmpv6_code_OF_VERSION_1_2(void)
{
    of_oxm_icmpv6_code_t *obj;
    obj = of_oxm_icmpv6_code_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 5);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_ICMPV6_CODE);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 5);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_ICMPV6_CODE);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_icmpv6_code_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_icmpv6_code_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_oxm_icmpv6_code_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_icmpv6_code_masked_OF_VERSION_1_2(void)
{
    of_oxm_icmpv6_code_masked_t *obj;
    obj = of_oxm_icmpv6_code_masked_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 6);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_ICMPV6_CODE_MASKED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 6);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_ICMPV6_CODE_MASKED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_icmpv6_code_masked_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_icmpv6_code_masked_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_oxm_icmpv6_code_masked_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_icmpv6_type_OF_VERSION_1_2(void)
{
    of_oxm_icmpv6_type_t *obj;
    obj = of_oxm_icmpv6_type_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 5);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_ICMPV6_TYPE);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 5);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_ICMPV6_TYPE);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_icmpv6_type_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_icmpv6_type_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_oxm_icmpv6_type_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_icmpv6_type_masked_OF_VERSION_1_2(void)
{
    of_oxm_icmpv6_type_masked_t *obj;
    obj = of_oxm_icmpv6_type_masked_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 6);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_ICMPV6_TYPE_MASKED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 6);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_ICMPV6_TYPE_MASKED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_icmpv6_type_masked_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_icmpv6_type_masked_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_oxm_icmpv6_type_masked_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_in_phy_port_OF_VERSION_1_2(void)
{
    of_oxm_in_phy_port_t *obj;
    obj = of_oxm_in_phy_port_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_IN_PHY_PORT);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_IN_PHY_PORT);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_in_phy_port_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_in_phy_port_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_oxm_in_phy_port_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_in_phy_port_masked_OF_VERSION_1_2(void)
{
    of_oxm_in_phy_port_masked_t *obj;
    obj = of_oxm_in_phy_port_masked_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_IN_PHY_PORT_MASKED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_IN_PHY_PORT_MASKED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_in_phy_port_masked_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_in_phy_port_masked_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_oxm_in_phy_port_masked_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_in_port_OF_VERSION_1_2(void)
{
    of_oxm_in_port_t *obj;
    obj = of_oxm_in_port_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_IN_PORT);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_IN_PORT);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_in_port_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_in_port_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_oxm_in_port_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_in_port_masked_OF_VERSION_1_2(void)
{
    of_oxm_in_port_masked_t *obj;
    obj = of_oxm_in_port_masked_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_IN_PORT_MASKED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_IN_PORT_MASKED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_in_port_masked_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_in_port_masked_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_oxm_in_port_masked_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_ip_dscp_OF_VERSION_1_2(void)
{
    of_oxm_ip_dscp_t *obj;
    obj = of_oxm_ip_dscp_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 5);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_IP_DSCP);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 5);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_IP_DSCP);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_ip_dscp_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_ip_dscp_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_oxm_ip_dscp_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_ip_dscp_masked_OF_VERSION_1_2(void)
{
    of_oxm_ip_dscp_masked_t *obj;
    obj = of_oxm_ip_dscp_masked_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 6);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_IP_DSCP_MASKED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 6);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_IP_DSCP_MASKED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_ip_dscp_masked_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_ip_dscp_masked_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_oxm_ip_dscp_masked_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_ip_ecn_OF_VERSION_1_2(void)
{
    of_oxm_ip_ecn_t *obj;
    obj = of_oxm_ip_ecn_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 5);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_IP_ECN);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 5);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_IP_ECN);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_ip_ecn_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_ip_ecn_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_oxm_ip_ecn_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_ip_ecn_masked_OF_VERSION_1_2(void)
{
    of_oxm_ip_ecn_masked_t *obj;
    obj = of_oxm_ip_ecn_masked_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 6);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_IP_ECN_MASKED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 6);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_IP_ECN_MASKED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_ip_ecn_masked_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_ip_ecn_masked_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_oxm_ip_ecn_masked_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_ip_proto_OF_VERSION_1_2(void)
{
    of_oxm_ip_proto_t *obj;
    obj = of_oxm_ip_proto_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 5);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_IP_PROTO);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 5);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_IP_PROTO);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_ip_proto_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_ip_proto_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_oxm_ip_proto_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_ip_proto_masked_OF_VERSION_1_2(void)
{
    of_oxm_ip_proto_masked_t *obj;
    obj = of_oxm_ip_proto_masked_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 6);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_IP_PROTO_MASKED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 6);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_IP_PROTO_MASKED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_ip_proto_masked_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_ip_proto_masked_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_oxm_ip_proto_masked_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_ipv4_dst_OF_VERSION_1_2(void)
{
    of_oxm_ipv4_dst_t *obj;
    obj = of_oxm_ipv4_dst_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_IPV4_DST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_IPV4_DST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_ipv4_dst_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_ipv4_dst_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_oxm_ipv4_dst_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_ipv4_dst_masked_OF_VERSION_1_2(void)
{
    of_oxm_ipv4_dst_masked_t *obj;
    obj = of_oxm_ipv4_dst_masked_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_IPV4_DST_MASKED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_IPV4_DST_MASKED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_ipv4_dst_masked_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_ipv4_dst_masked_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_oxm_ipv4_dst_masked_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_ipv4_src_OF_VERSION_1_2(void)
{
    of_oxm_ipv4_src_t *obj;
    obj = of_oxm_ipv4_src_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_IPV4_SRC);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_IPV4_SRC);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_ipv4_src_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_ipv4_src_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_oxm_ipv4_src_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_ipv4_src_masked_OF_VERSION_1_2(void)
{
    of_oxm_ipv4_src_masked_t *obj;
    obj = of_oxm_ipv4_src_masked_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_IPV4_SRC_MASKED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_IPV4_SRC_MASKED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_ipv4_src_masked_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_ipv4_src_masked_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_oxm_ipv4_src_masked_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_ipv6_dst_OF_VERSION_1_2(void)
{
    of_oxm_ipv6_dst_t *obj;
    obj = of_oxm_ipv6_dst_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_IPV6_DST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 20);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_IPV6_DST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_ipv6_dst_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_ipv6_dst_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_oxm_ipv6_dst_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_ipv6_dst_masked_OF_VERSION_1_2(void)
{
    of_oxm_ipv6_dst_masked_t *obj;
    obj = of_oxm_ipv6_dst_masked_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 36);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_IPV6_DST_MASKED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 36);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_IPV6_DST_MASKED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_ipv6_dst_masked_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_ipv6_dst_masked_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_oxm_ipv6_dst_masked_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_ipv6_flabel_OF_VERSION_1_2(void)
{
    of_oxm_ipv6_flabel_t *obj;
    obj = of_oxm_ipv6_flabel_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_IPV6_FLABEL);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_IPV6_FLABEL);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_ipv6_flabel_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_ipv6_flabel_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_oxm_ipv6_flabel_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_ipv6_flabel_masked_OF_VERSION_1_2(void)
{
    of_oxm_ipv6_flabel_masked_t *obj;
    obj = of_oxm_ipv6_flabel_masked_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_IPV6_FLABEL_MASKED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_IPV6_FLABEL_MASKED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_ipv6_flabel_masked_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_ipv6_flabel_masked_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_oxm_ipv6_flabel_masked_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_ipv6_nd_sll_OF_VERSION_1_2(void)
{
    of_oxm_ipv6_nd_sll_t *obj;
    obj = of_oxm_ipv6_nd_sll_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 10);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_IPV6_ND_SLL);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 10);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_IPV6_ND_SLL);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_ipv6_nd_sll_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_ipv6_nd_sll_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_oxm_ipv6_nd_sll_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_ipv6_nd_sll_masked_OF_VERSION_1_2(void)
{
    of_oxm_ipv6_nd_sll_masked_t *obj;
    obj = of_oxm_ipv6_nd_sll_masked_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_IPV6_ND_SLL_MASKED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_IPV6_ND_SLL_MASKED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_ipv6_nd_sll_masked_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_ipv6_nd_sll_masked_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_oxm_ipv6_nd_sll_masked_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_ipv6_nd_target_OF_VERSION_1_2(void)
{
    of_oxm_ipv6_nd_target_t *obj;
    obj = of_oxm_ipv6_nd_target_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_IPV6_ND_TARGET);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 20);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_IPV6_ND_TARGET);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_ipv6_nd_target_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_ipv6_nd_target_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_oxm_ipv6_nd_target_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_ipv6_nd_target_masked_OF_VERSION_1_2(void)
{
    of_oxm_ipv6_nd_target_masked_t *obj;
    obj = of_oxm_ipv6_nd_target_masked_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 36);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_IPV6_ND_TARGET_MASKED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 36);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_IPV6_ND_TARGET_MASKED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_ipv6_nd_target_masked_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_ipv6_nd_target_masked_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_oxm_ipv6_nd_target_masked_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_ipv6_nd_tll_OF_VERSION_1_2(void)
{
    of_oxm_ipv6_nd_tll_t *obj;
    obj = of_oxm_ipv6_nd_tll_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 10);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_IPV6_ND_TLL);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 10);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_IPV6_ND_TLL);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_ipv6_nd_tll_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_ipv6_nd_tll_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_oxm_ipv6_nd_tll_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_ipv6_nd_tll_masked_OF_VERSION_1_2(void)
{
    of_oxm_ipv6_nd_tll_masked_t *obj;
    obj = of_oxm_ipv6_nd_tll_masked_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_IPV6_ND_TLL_MASKED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_IPV6_ND_TLL_MASKED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_ipv6_nd_tll_masked_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_ipv6_nd_tll_masked_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_oxm_ipv6_nd_tll_masked_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_ipv6_src_OF_VERSION_1_2(void)
{
    of_oxm_ipv6_src_t *obj;
    obj = of_oxm_ipv6_src_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_IPV6_SRC);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 20);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_IPV6_SRC);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_ipv6_src_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_ipv6_src_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_oxm_ipv6_src_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_ipv6_src_masked_OF_VERSION_1_2(void)
{
    of_oxm_ipv6_src_masked_t *obj;
    obj = of_oxm_ipv6_src_masked_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 36);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_IPV6_SRC_MASKED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 36);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_IPV6_SRC_MASKED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_ipv6_src_masked_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_ipv6_src_masked_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_oxm_ipv6_src_masked_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_metadata_OF_VERSION_1_2(void)
{
    of_oxm_metadata_t *obj;
    obj = of_oxm_metadata_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_METADATA);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_METADATA);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_metadata_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_metadata_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_oxm_metadata_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_metadata_masked_OF_VERSION_1_2(void)
{
    of_oxm_metadata_masked_t *obj;
    obj = of_oxm_metadata_masked_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_METADATA_MASKED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 20);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_METADATA_MASKED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_metadata_masked_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_metadata_masked_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_oxm_metadata_masked_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_mpls_label_OF_VERSION_1_2(void)
{
    of_oxm_mpls_label_t *obj;
    obj = of_oxm_mpls_label_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_MPLS_LABEL);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_MPLS_LABEL);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_mpls_label_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_mpls_label_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_oxm_mpls_label_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_mpls_label_masked_OF_VERSION_1_2(void)
{
    of_oxm_mpls_label_masked_t *obj;
    obj = of_oxm_mpls_label_masked_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_MPLS_LABEL_MASKED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_MPLS_LABEL_MASKED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_mpls_label_masked_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_mpls_label_masked_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_oxm_mpls_label_masked_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_mpls_tc_OF_VERSION_1_2(void)
{
    of_oxm_mpls_tc_t *obj;
    obj = of_oxm_mpls_tc_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 5);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_MPLS_TC);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 5);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_MPLS_TC);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_mpls_tc_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_mpls_tc_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_oxm_mpls_tc_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_mpls_tc_masked_OF_VERSION_1_2(void)
{
    of_oxm_mpls_tc_masked_t *obj;
    obj = of_oxm_mpls_tc_masked_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 6);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_MPLS_TC_MASKED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 6);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_MPLS_TC_MASKED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_mpls_tc_masked_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_mpls_tc_masked_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_oxm_mpls_tc_masked_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_sctp_dst_OF_VERSION_1_2(void)
{
    of_oxm_sctp_dst_t *obj;
    obj = of_oxm_sctp_dst_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 6);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_SCTP_DST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 6);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_SCTP_DST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_sctp_dst_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_sctp_dst_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_oxm_sctp_dst_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_sctp_dst_masked_OF_VERSION_1_2(void)
{
    of_oxm_sctp_dst_masked_t *obj;
    obj = of_oxm_sctp_dst_masked_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_SCTP_DST_MASKED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_SCTP_DST_MASKED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_sctp_dst_masked_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_sctp_dst_masked_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_oxm_sctp_dst_masked_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_sctp_src_OF_VERSION_1_2(void)
{
    of_oxm_sctp_src_t *obj;
    obj = of_oxm_sctp_src_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 6);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_SCTP_SRC);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 6);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_SCTP_SRC);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_sctp_src_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_sctp_src_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_oxm_sctp_src_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_sctp_src_masked_OF_VERSION_1_2(void)
{
    of_oxm_sctp_src_masked_t *obj;
    obj = of_oxm_sctp_src_masked_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_SCTP_SRC_MASKED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_SCTP_SRC_MASKED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_sctp_src_masked_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_sctp_src_masked_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_oxm_sctp_src_masked_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_tcp_dst_OF_VERSION_1_2(void)
{
    of_oxm_tcp_dst_t *obj;
    obj = of_oxm_tcp_dst_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 6);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_TCP_DST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 6);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_TCP_DST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_tcp_dst_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_tcp_dst_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_oxm_tcp_dst_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_tcp_dst_masked_OF_VERSION_1_2(void)
{
    of_oxm_tcp_dst_masked_t *obj;
    obj = of_oxm_tcp_dst_masked_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_TCP_DST_MASKED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_TCP_DST_MASKED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_tcp_dst_masked_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_tcp_dst_masked_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_oxm_tcp_dst_masked_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_tcp_src_OF_VERSION_1_2(void)
{
    of_oxm_tcp_src_t *obj;
    obj = of_oxm_tcp_src_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 6);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_TCP_SRC);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 6);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_TCP_SRC);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_tcp_src_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_tcp_src_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_oxm_tcp_src_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_tcp_src_masked_OF_VERSION_1_2(void)
{
    of_oxm_tcp_src_masked_t *obj;
    obj = of_oxm_tcp_src_masked_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_TCP_SRC_MASKED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_TCP_SRC_MASKED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_tcp_src_masked_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_tcp_src_masked_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_oxm_tcp_src_masked_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_udp_dst_OF_VERSION_1_2(void)
{
    of_oxm_udp_dst_t *obj;
    obj = of_oxm_udp_dst_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 6);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_UDP_DST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 6);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_UDP_DST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_udp_dst_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_udp_dst_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_oxm_udp_dst_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_udp_dst_masked_OF_VERSION_1_2(void)
{
    of_oxm_udp_dst_masked_t *obj;
    obj = of_oxm_udp_dst_masked_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_UDP_DST_MASKED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_UDP_DST_MASKED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_udp_dst_masked_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_udp_dst_masked_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_oxm_udp_dst_masked_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_udp_src_OF_VERSION_1_2(void)
{
    of_oxm_udp_src_t *obj;
    obj = of_oxm_udp_src_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 6);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_UDP_SRC);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 6);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_UDP_SRC);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_udp_src_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_udp_src_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_oxm_udp_src_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_udp_src_masked_OF_VERSION_1_2(void)
{
    of_oxm_udp_src_masked_t *obj;
    obj = of_oxm_udp_src_masked_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_UDP_SRC_MASKED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_UDP_SRC_MASKED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_udp_src_masked_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_udp_src_masked_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_oxm_udp_src_masked_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_vlan_pcp_OF_VERSION_1_2(void)
{
    of_oxm_vlan_pcp_t *obj;
    obj = of_oxm_vlan_pcp_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 5);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_VLAN_PCP);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 5);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_VLAN_PCP);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_vlan_pcp_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_vlan_pcp_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_oxm_vlan_pcp_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_vlan_pcp_masked_OF_VERSION_1_2(void)
{
    of_oxm_vlan_pcp_masked_t *obj;
    obj = of_oxm_vlan_pcp_masked_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 6);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_VLAN_PCP_MASKED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 6);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_VLAN_PCP_MASKED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_vlan_pcp_masked_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_vlan_pcp_masked_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_oxm_vlan_pcp_masked_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_vlan_vid_OF_VERSION_1_2(void)
{
    of_oxm_vlan_vid_t *obj;
    obj = of_oxm_vlan_vid_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 6);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_VLAN_VID);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 6);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_VLAN_VID);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_vlan_vid_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_vlan_vid_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_oxm_vlan_vid_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_vlan_vid_masked_OF_VERSION_1_2(void)
{
    of_oxm_vlan_vid_masked_t *obj;
    obj = of_oxm_vlan_vid_masked_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_VLAN_VID_MASKED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_VLAN_VID_MASKED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_vlan_vid_masked_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_vlan_vid_masked_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_oxm_vlan_vid_masked_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_packet_queue_OF_VERSION_1_2(void)
{
    of_packet_queue_t *obj;
    obj = of_packet_queue_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_PACKET_QUEUE);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_PACKET_QUEUE);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_packet_queue_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_packet_queue_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_packet_queue_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_port_desc_OF_VERSION_1_2(void)
{
    of_port_desc_t *obj;
    obj = of_port_desc_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 64);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_PORT_DESC);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 64);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_PORT_DESC);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_port_desc_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_port_desc_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_port_desc_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_port_stats_entry_OF_VERSION_1_2(void)
{
    of_port_stats_entry_t *obj;
    obj = of_port_stats_entry_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 104);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_PORT_STATS_ENTRY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 104);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_PORT_STATS_ENTRY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_port_stats_entry_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_port_stats_entry_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_port_stats_entry_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_queue_prop_experimenter_OF_VERSION_1_2(void)
{
    of_queue_prop_experimenter_t *obj;
    obj = of_queue_prop_experimenter_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_QUEUE_PROP_EXPERIMENTER);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_QUEUE_PROP_EXPERIMENTER);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_queue_prop_experimenter_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_queue_prop_experimenter_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_queue_prop_experimenter_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_queue_prop_header_OF_VERSION_1_2(void)
{
    of_queue_prop_header_t *obj;
    obj = of_queue_prop_header_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_QUEUE_PROP_HEADER);

    of_queue_prop_header_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_queue_prop_max_rate_OF_VERSION_1_2(void)
{
    of_queue_prop_max_rate_t *obj;
    obj = of_queue_prop_max_rate_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_QUEUE_PROP_MAX_RATE);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_QUEUE_PROP_MAX_RATE);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_queue_prop_max_rate_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_queue_prop_max_rate_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_queue_prop_max_rate_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_queue_prop_min_rate_OF_VERSION_1_2(void)
{
    of_queue_prop_min_rate_t *obj;
    obj = of_queue_prop_min_rate_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_QUEUE_PROP_MIN_RATE);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_QUEUE_PROP_MIN_RATE);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_queue_prop_min_rate_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_queue_prop_min_rate_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_queue_prop_min_rate_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_queue_stats_entry_OF_VERSION_1_2(void)
{
    of_queue_stats_entry_t *obj;
    obj = of_queue_stats_entry_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 32);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_QUEUE_STATS_ENTRY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 32);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_QUEUE_STATS_ENTRY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_queue_stats_entry_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_queue_stats_entry_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_queue_stats_entry_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_table_stats_entry_OF_VERSION_1_2(void)
{
    of_table_stats_entry_t *obj;
    obj = of_table_stats_entry_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 128);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_TABLE_STATS_ENTRY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 128);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_TABLE_STATS_ENTRY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_table_stats_entry_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_table_stats_entry_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_table_stats_entry_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_list_action_OF_VERSION_1_2(void)
{
    of_list_action_t *obj;
    obj = of_list_action_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 0);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_LIST_ACTION);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 0);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_LIST_ACTION);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_list_action_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_list_action_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_list_action_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_list_bsn_interface_OF_VERSION_1_2(void)
{
    of_list_bsn_interface_t *obj;
    obj = of_list_bsn_interface_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 0);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_LIST_BSN_INTERFACE);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 0);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_LIST_BSN_INTERFACE);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_list_bsn_interface_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_list_bsn_interface_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_list_bsn_interface_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_list_bucket_OF_VERSION_1_2(void)
{
    of_list_bucket_t *obj;
    obj = of_list_bucket_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 0);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_LIST_BUCKET);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 0);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_LIST_BUCKET);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_list_bucket_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_list_bucket_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_list_bucket_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_list_bucket_counter_OF_VERSION_1_2(void)
{
    of_list_bucket_counter_t *obj;
    obj = of_list_bucket_counter_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 0);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_LIST_BUCKET_COUNTER);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 0);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_LIST_BUCKET_COUNTER);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_list_bucket_counter_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_list_bucket_counter_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_list_bucket_counter_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_list_flow_stats_entry_OF_VERSION_1_2(void)
{
    of_list_flow_stats_entry_t *obj;
    obj = of_list_flow_stats_entry_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 0);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_LIST_FLOW_STATS_ENTRY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 0);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_LIST_FLOW_STATS_ENTRY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_list_flow_stats_entry_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_list_flow_stats_entry_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_list_flow_stats_entry_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_list_group_desc_stats_entry_OF_VERSION_1_2(void)
{
    of_list_group_desc_stats_entry_t *obj;
    obj = of_list_group_desc_stats_entry_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 0);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_LIST_GROUP_DESC_STATS_ENTRY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 0);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_LIST_GROUP_DESC_STATS_ENTRY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_list_group_desc_stats_entry_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_list_group_desc_stats_entry_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_list_group_desc_stats_entry_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_list_group_stats_entry_OF_VERSION_1_2(void)
{
    of_list_group_stats_entry_t *obj;
    obj = of_list_group_stats_entry_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 0);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_LIST_GROUP_STATS_ENTRY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 0);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_LIST_GROUP_STATS_ENTRY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_list_group_stats_entry_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_list_group_stats_entry_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_list_group_stats_entry_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_list_instruction_OF_VERSION_1_2(void)
{
    of_list_instruction_t *obj;
    obj = of_list_instruction_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 0);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_LIST_INSTRUCTION);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 0);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_LIST_INSTRUCTION);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_list_instruction_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_list_instruction_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_list_instruction_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_list_oxm_OF_VERSION_1_2(void)
{
    of_list_oxm_t *obj;
    obj = of_list_oxm_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 0);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_LIST_OXM);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 0);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_LIST_OXM);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_list_oxm_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_list_oxm_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_list_oxm_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_list_packet_queue_OF_VERSION_1_2(void)
{
    of_list_packet_queue_t *obj;
    obj = of_list_packet_queue_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 0);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_LIST_PACKET_QUEUE);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 0);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_LIST_PACKET_QUEUE);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_list_packet_queue_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_list_packet_queue_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_list_packet_queue_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_list_port_desc_OF_VERSION_1_2(void)
{
    of_list_port_desc_t *obj;
    obj = of_list_port_desc_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 0);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_LIST_PORT_DESC);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 0);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_LIST_PORT_DESC);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_list_port_desc_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_list_port_desc_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_list_port_desc_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_list_port_stats_entry_OF_VERSION_1_2(void)
{
    of_list_port_stats_entry_t *obj;
    obj = of_list_port_stats_entry_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 0);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_LIST_PORT_STATS_ENTRY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 0);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_LIST_PORT_STATS_ENTRY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_list_port_stats_entry_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_list_port_stats_entry_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_list_port_stats_entry_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_list_queue_prop_OF_VERSION_1_2(void)
{
    of_list_queue_prop_t *obj;
    obj = of_list_queue_prop_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 0);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_LIST_QUEUE_PROP);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 0);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_LIST_QUEUE_PROP);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_list_queue_prop_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_list_queue_prop_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_list_queue_prop_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_list_queue_stats_entry_OF_VERSION_1_2(void)
{
    of_list_queue_stats_entry_t *obj;
    obj = of_list_queue_stats_entry_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 0);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_LIST_QUEUE_STATS_ENTRY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 0);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_LIST_QUEUE_STATS_ENTRY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_list_queue_stats_entry_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_list_queue_stats_entry_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_list_queue_stats_entry_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_list_table_stats_entry_OF_VERSION_1_2(void)
{
    of_list_table_stats_entry_t *obj;
    obj = of_list_table_stats_entry_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 0);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_LIST_TABLE_STATS_ENTRY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 0);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_LIST_TABLE_STATS_ENTRY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_list_table_stats_entry_OF_VERSION_1_2_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_list_table_stats_entry_OF_VERSION_1_2_check(
        obj, 1) != 0);

    of_list_table_stats_entry_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_aggregate_stats_reply_OF_VERSION_1_3(void)
{
    of_aggregate_stats_reply_t *obj;
    obj = of_aggregate_stats_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 40);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_AGGREGATE_STATS_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 40);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_AGGREGATE_STATS_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_aggregate_stats_reply_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_aggregate_stats_reply_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_aggregate_stats_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_aggregate_stats_request_OF_VERSION_1_3(void)
{
    of_aggregate_stats_request_t *obj;
    obj = of_aggregate_stats_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 56);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_AGGREGATE_STATS_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 56);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_AGGREGATE_STATS_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_aggregate_stats_request_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_aggregate_stats_request_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_aggregate_stats_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_async_get_reply_OF_VERSION_1_3(void)
{
    of_async_get_reply_t *obj;
    obj = of_async_get_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 32);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ASYNC_GET_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 32);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ASYNC_GET_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_async_get_reply_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_async_get_reply_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_async_get_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_async_get_request_OF_VERSION_1_3(void)
{
    of_async_get_request_t *obj;
    obj = of_async_get_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 32);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ASYNC_GET_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 32);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ASYNC_GET_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_async_get_request_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_async_get_request_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_async_get_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_async_set_OF_VERSION_1_3(void)
{
    of_async_set_t *obj;
    obj = of_async_set_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 32);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ASYNC_SET);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 32);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ASYNC_SET);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_async_set_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_async_set_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_async_set_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bad_action_error_msg_OF_VERSION_1_3(void)
{
    of_bad_action_error_msg_t *obj;
    obj = of_bad_action_error_msg_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BAD_ACTION_ERROR_MSG);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BAD_ACTION_ERROR_MSG);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bad_action_error_msg_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bad_action_error_msg_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_bad_action_error_msg_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bad_instruction_error_msg_OF_VERSION_1_3(void)
{
    of_bad_instruction_error_msg_t *obj;
    obj = of_bad_instruction_error_msg_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BAD_INSTRUCTION_ERROR_MSG);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BAD_INSTRUCTION_ERROR_MSG);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bad_instruction_error_msg_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bad_instruction_error_msg_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_bad_instruction_error_msg_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bad_match_error_msg_OF_VERSION_1_3(void)
{
    of_bad_match_error_msg_t *obj;
    obj = of_bad_match_error_msg_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BAD_MATCH_ERROR_MSG);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BAD_MATCH_ERROR_MSG);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bad_match_error_msg_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bad_match_error_msg_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_bad_match_error_msg_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bad_request_error_msg_OF_VERSION_1_3(void)
{
    of_bad_request_error_msg_t *obj;
    obj = of_bad_request_error_msg_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BAD_REQUEST_ERROR_MSG);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BAD_REQUEST_ERROR_MSG);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bad_request_error_msg_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bad_request_error_msg_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_bad_request_error_msg_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_barrier_reply_OF_VERSION_1_3(void)
{
    of_barrier_reply_t *obj;
    obj = of_barrier_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BARRIER_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BARRIER_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_barrier_reply_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_barrier_reply_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_barrier_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_barrier_request_OF_VERSION_1_3(void)
{
    of_barrier_request_t *obj;
    obj = of_barrier_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BARRIER_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BARRIER_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_barrier_request_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_barrier_request_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_barrier_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_bw_clear_data_reply_OF_VERSION_1_3(void)
{
    of_bsn_bw_clear_data_reply_t *obj;
    obj = of_bsn_bw_clear_data_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_BW_CLEAR_DATA_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 20);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_BW_CLEAR_DATA_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_bw_clear_data_reply_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_bw_clear_data_reply_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_bsn_bw_clear_data_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_bw_clear_data_request_OF_VERSION_1_3(void)
{
    of_bsn_bw_clear_data_request_t *obj;
    obj = of_bsn_bw_clear_data_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_BW_CLEAR_DATA_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_BW_CLEAR_DATA_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_bw_clear_data_request_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_bw_clear_data_request_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_bsn_bw_clear_data_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_bw_enable_get_reply_OF_VERSION_1_3(void)
{
    of_bsn_bw_enable_get_reply_t *obj;
    obj = of_bsn_bw_enable_get_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_BW_ENABLE_GET_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 20);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_BW_ENABLE_GET_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_bw_enable_get_reply_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_bw_enable_get_reply_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_bsn_bw_enable_get_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_bw_enable_get_request_OF_VERSION_1_3(void)
{
    of_bsn_bw_enable_get_request_t *obj;
    obj = of_bsn_bw_enable_get_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_BW_ENABLE_GET_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_BW_ENABLE_GET_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_bw_enable_get_request_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_bw_enable_get_request_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_bsn_bw_enable_get_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_bw_enable_set_reply_OF_VERSION_1_3(void)
{
    of_bsn_bw_enable_set_reply_t *obj;
    obj = of_bsn_bw_enable_set_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_BW_ENABLE_SET_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 24);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_BW_ENABLE_SET_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_bw_enable_set_reply_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_bw_enable_set_reply_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_bsn_bw_enable_set_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_bw_enable_set_request_OF_VERSION_1_3(void)
{
    of_bsn_bw_enable_set_request_t *obj;
    obj = of_bsn_bw_enable_set_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_BW_ENABLE_SET_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 20);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_BW_ENABLE_SET_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_bw_enable_set_request_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_bw_enable_set_request_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_bsn_bw_enable_set_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_flow_idle_OF_VERSION_1_3(void)
{
    of_bsn_flow_idle_t *obj;
    obj = of_bsn_flow_idle_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 40);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_FLOW_IDLE);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 40);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_FLOW_IDLE);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_flow_idle_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_flow_idle_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_bsn_flow_idle_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_flow_idle_enable_get_reply_OF_VERSION_1_3(void)
{
    of_bsn_flow_idle_enable_get_reply_t *obj;
    obj = of_bsn_flow_idle_enable_get_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_FLOW_IDLE_ENABLE_GET_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 20);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_FLOW_IDLE_ENABLE_GET_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_flow_idle_enable_get_reply_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_flow_idle_enable_get_reply_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_bsn_flow_idle_enable_get_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_flow_idle_enable_get_request_OF_VERSION_1_3(void)
{
    of_bsn_flow_idle_enable_get_request_t *obj;
    obj = of_bsn_flow_idle_enable_get_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_FLOW_IDLE_ENABLE_GET_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_FLOW_IDLE_ENABLE_GET_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_flow_idle_enable_get_request_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_flow_idle_enable_get_request_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_bsn_flow_idle_enable_get_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_flow_idle_enable_set_reply_OF_VERSION_1_3(void)
{
    of_bsn_flow_idle_enable_set_reply_t *obj;
    obj = of_bsn_flow_idle_enable_set_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_FLOW_IDLE_ENABLE_SET_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 24);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_FLOW_IDLE_ENABLE_SET_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_flow_idle_enable_set_reply_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_flow_idle_enable_set_reply_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_bsn_flow_idle_enable_set_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_flow_idle_enable_set_request_OF_VERSION_1_3(void)
{
    of_bsn_flow_idle_enable_set_request_t *obj;
    obj = of_bsn_flow_idle_enable_set_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_FLOW_IDLE_ENABLE_SET_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 20);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_FLOW_IDLE_ENABLE_SET_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_flow_idle_enable_set_request_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_flow_idle_enable_set_request_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_bsn_flow_idle_enable_set_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_get_interfaces_reply_OF_VERSION_1_3(void)
{
    of_bsn_get_interfaces_reply_t *obj;
    obj = of_bsn_get_interfaces_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GET_INTERFACES_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_GET_INTERFACES_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_get_interfaces_reply_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_get_interfaces_reply_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_bsn_get_interfaces_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_get_interfaces_request_OF_VERSION_1_3(void)
{
    of_bsn_get_interfaces_request_t *obj;
    obj = of_bsn_get_interfaces_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GET_INTERFACES_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_GET_INTERFACES_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_get_interfaces_request_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_get_interfaces_request_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_bsn_get_interfaces_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_get_mirroring_reply_OF_VERSION_1_3(void)
{
    of_bsn_get_mirroring_reply_t *obj;
    obj = of_bsn_get_mirroring_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GET_MIRRORING_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 20);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_GET_MIRRORING_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_get_mirroring_reply_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_get_mirroring_reply_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_bsn_get_mirroring_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_get_mirroring_request_OF_VERSION_1_3(void)
{
    of_bsn_get_mirroring_request_t *obj;
    obj = of_bsn_get_mirroring_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GET_MIRRORING_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 20);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_GET_MIRRORING_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_get_mirroring_request_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_get_mirroring_request_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_bsn_get_mirroring_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_header_OF_VERSION_1_3(void)
{
    of_bsn_header_t *obj;
    obj = of_bsn_header_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_HEADER);

    of_bsn_header_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_lacp_convergence_notif_OF_VERSION_1_3(void)
{
    of_bsn_lacp_convergence_notif_t *obj;
    obj = of_bsn_lacp_convergence_notif_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 52);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_LACP_CONVERGENCE_NOTIF);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 52);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_LACP_CONVERGENCE_NOTIF);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_lacp_convergence_notif_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_lacp_convergence_notif_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_bsn_lacp_convergence_notif_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_lacp_stats_reply_OF_VERSION_1_3(void)
{
    of_bsn_lacp_stats_reply_t *obj;
    obj = of_bsn_lacp_stats_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_LACP_STATS_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 24);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_LACP_STATS_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_lacp_stats_reply_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_lacp_stats_reply_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_bsn_lacp_stats_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_lacp_stats_request_OF_VERSION_1_3(void)
{
    of_bsn_lacp_stats_request_t *obj;
    obj = of_bsn_lacp_stats_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_LACP_STATS_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 24);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_LACP_STATS_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_lacp_stats_request_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_lacp_stats_request_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_bsn_lacp_stats_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_pdu_rx_reply_OF_VERSION_1_3(void)
{
    of_bsn_pdu_rx_reply_t *obj;
    obj = of_bsn_pdu_rx_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 25);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_PDU_RX_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 25);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_PDU_RX_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_pdu_rx_reply_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_pdu_rx_reply_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_bsn_pdu_rx_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_pdu_rx_request_OF_VERSION_1_3(void)
{
    of_bsn_pdu_rx_request_t *obj;
    obj = of_bsn_pdu_rx_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 28);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_PDU_RX_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 28);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_PDU_RX_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_pdu_rx_request_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_pdu_rx_request_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_bsn_pdu_rx_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_pdu_rx_timeout_OF_VERSION_1_3(void)
{
    of_bsn_pdu_rx_timeout_t *obj;
    obj = of_bsn_pdu_rx_timeout_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 21);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_PDU_RX_TIMEOUT);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 21);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_PDU_RX_TIMEOUT);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_pdu_rx_timeout_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_pdu_rx_timeout_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_bsn_pdu_rx_timeout_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_pdu_tx_reply_OF_VERSION_1_3(void)
{
    of_bsn_pdu_tx_reply_t *obj;
    obj = of_bsn_pdu_tx_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 25);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_PDU_TX_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 25);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_PDU_TX_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_pdu_tx_reply_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_pdu_tx_reply_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_bsn_pdu_tx_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_pdu_tx_request_OF_VERSION_1_3(void)
{
    of_bsn_pdu_tx_request_t *obj;
    obj = of_bsn_pdu_tx_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 28);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_PDU_TX_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 28);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_PDU_TX_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_pdu_tx_request_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_pdu_tx_request_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_bsn_pdu_tx_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_set_lacp_reply_OF_VERSION_1_3(void)
{
    of_bsn_set_lacp_reply_t *obj;
    obj = of_bsn_set_lacp_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_SET_LACP_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 24);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_SET_LACP_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_set_lacp_reply_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_set_lacp_reply_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_bsn_set_lacp_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_set_lacp_request_OF_VERSION_1_3(void)
{
    of_bsn_set_lacp_request_t *obj;
    obj = of_bsn_set_lacp_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 38);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_SET_LACP_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 38);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_SET_LACP_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_set_lacp_request_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_set_lacp_request_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_bsn_set_lacp_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_set_mirroring_OF_VERSION_1_3(void)
{
    of_bsn_set_mirroring_t *obj;
    obj = of_bsn_set_mirroring_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_SET_MIRRORING);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 20);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_SET_MIRRORING);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_set_mirroring_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_set_mirroring_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_bsn_set_mirroring_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_set_pktin_suppression_reply_OF_VERSION_1_3(void)
{
    of_bsn_set_pktin_suppression_reply_t *obj;
    obj = of_bsn_set_pktin_suppression_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_SET_PKTIN_SUPPRESSION_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 20);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_SET_PKTIN_SUPPRESSION_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_set_pktin_suppression_reply_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_set_pktin_suppression_reply_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_bsn_set_pktin_suppression_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_set_pktin_suppression_request_OF_VERSION_1_3(void)
{
    of_bsn_set_pktin_suppression_request_t *obj;
    obj = of_bsn_set_pktin_suppression_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 32);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_SET_PKTIN_SUPPRESSION_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 32);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_SET_PKTIN_SUPPRESSION_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_set_pktin_suppression_request_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_set_pktin_suppression_request_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_bsn_set_pktin_suppression_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_stats_reply_OF_VERSION_1_3(void)
{
    of_bsn_stats_reply_t *obj;
    obj = of_bsn_stats_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_STATS_REPLY);

    of_bsn_stats_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_stats_request_OF_VERSION_1_3(void)
{
    of_bsn_stats_request_t *obj;
    obj = of_bsn_stats_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_STATS_REQUEST);

    of_bsn_stats_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_time_reply_OF_VERSION_1_3(void)
{
    of_bsn_time_reply_t *obj;
    obj = of_bsn_time_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_TIME_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 24);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_TIME_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_time_reply_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_time_reply_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_bsn_time_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_time_request_OF_VERSION_1_3(void)
{
    of_bsn_time_request_t *obj;
    obj = of_bsn_time_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_TIME_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_TIME_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_time_request_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_time_request_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_bsn_time_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_virtual_port_create_reply_OF_VERSION_1_3(void)
{
    of_bsn_virtual_port_create_reply_t *obj;
    obj = of_bsn_virtual_port_create_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_VIRTUAL_PORT_CREATE_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 24);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_VIRTUAL_PORT_CREATE_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_virtual_port_create_reply_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_virtual_port_create_reply_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_bsn_virtual_port_create_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_virtual_port_create_request_OF_VERSION_1_3(void)
{
    of_bsn_virtual_port_create_request_t *obj;
    obj = of_bsn_virtual_port_create_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 48);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_VIRTUAL_PORT_CREATE_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 48);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_VIRTUAL_PORT_CREATE_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_virtual_port_create_request_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_virtual_port_create_request_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_bsn_virtual_port_create_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_virtual_port_remove_reply_OF_VERSION_1_3(void)
{
    of_bsn_virtual_port_remove_reply_t *obj;
    obj = of_bsn_virtual_port_remove_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_VIRTUAL_PORT_REMOVE_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 20);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_VIRTUAL_PORT_REMOVE_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_virtual_port_remove_reply_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_virtual_port_remove_reply_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_bsn_virtual_port_remove_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_virtual_port_remove_request_OF_VERSION_1_3(void)
{
    of_bsn_virtual_port_remove_request_t *obj;
    obj = of_bsn_virtual_port_remove_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_VIRTUAL_PORT_REMOVE_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 20);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_VIRTUAL_PORT_REMOVE_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_virtual_port_remove_request_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_virtual_port_remove_request_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_bsn_virtual_port_remove_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_desc_stats_reply_OF_VERSION_1_3(void)
{
    of_desc_stats_reply_t *obj;
    obj = of_desc_stats_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 1072);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_DESC_STATS_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 1072);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_DESC_STATS_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_desc_stats_reply_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_desc_stats_reply_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_desc_stats_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_desc_stats_request_OF_VERSION_1_3(void)
{
    of_desc_stats_request_t *obj;
    obj = of_desc_stats_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_DESC_STATS_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_DESC_STATS_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_desc_stats_request_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_desc_stats_request_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_desc_stats_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_echo_reply_OF_VERSION_1_3(void)
{
    of_echo_reply_t *obj;
    obj = of_echo_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ECHO_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ECHO_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_echo_reply_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_echo_reply_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_echo_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_echo_request_OF_VERSION_1_3(void)
{
    of_echo_request_t *obj;
    obj = of_echo_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ECHO_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ECHO_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_echo_request_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_echo_request_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_echo_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_error_msg_OF_VERSION_1_3(void)
{
    of_error_msg_t *obj;
    obj = of_error_msg_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 10);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ERROR_MSG);

    of_error_msg_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_experimenter_OF_VERSION_1_3(void)
{
    of_experimenter_t *obj;
    obj = of_experimenter_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_EXPERIMENTER);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_EXPERIMENTER);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_experimenter_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_experimenter_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_experimenter_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_experimenter_error_msg_OF_VERSION_1_3(void)
{
    of_experimenter_error_msg_t *obj;
    obj = of_experimenter_error_msg_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_EXPERIMENTER_ERROR_MSG);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_EXPERIMENTER_ERROR_MSG);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_experimenter_error_msg_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_experimenter_error_msg_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_experimenter_error_msg_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_experimenter_stats_reply_OF_VERSION_1_3(void)
{
    of_experimenter_stats_reply_t *obj;
    obj = of_experimenter_stats_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_EXPERIMENTER_STATS_REPLY);

    of_experimenter_stats_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_experimenter_stats_request_OF_VERSION_1_3(void)
{
    of_experimenter_stats_request_t *obj;
    obj = of_experimenter_stats_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_EXPERIMENTER_STATS_REQUEST);

    of_experimenter_stats_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_features_reply_OF_VERSION_1_3(void)
{
    of_features_reply_t *obj;
    obj = of_features_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 32);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FEATURES_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 32);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_FEATURES_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_features_reply_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_features_reply_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_features_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_features_request_OF_VERSION_1_3(void)
{
    of_features_request_t *obj;
    obj = of_features_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FEATURES_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_FEATURES_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_features_request_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_features_request_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_features_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_flow_add_OF_VERSION_1_3(void)
{
    of_flow_add_t *obj;
    obj = of_flow_add_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 56);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_ADD);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 56);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_FLOW_ADD);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_flow_add_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_flow_add_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_flow_add_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_flow_delete_OF_VERSION_1_3(void)
{
    of_flow_delete_t *obj;
    obj = of_flow_delete_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 56);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_DELETE);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 56);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_FLOW_DELETE);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_flow_delete_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_flow_delete_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_flow_delete_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_flow_delete_strict_OF_VERSION_1_3(void)
{
    of_flow_delete_strict_t *obj;
    obj = of_flow_delete_strict_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 56);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_DELETE_STRICT);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 56);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_FLOW_DELETE_STRICT);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_flow_delete_strict_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_flow_delete_strict_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_flow_delete_strict_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_flow_mod_OF_VERSION_1_3(void)
{
    of_flow_mod_t *obj;
    obj = of_flow_mod_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 56);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_MOD);

    of_flow_mod_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_flow_mod_failed_error_msg_OF_VERSION_1_3(void)
{
    of_flow_mod_failed_error_msg_t *obj;
    obj = of_flow_mod_failed_error_msg_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_MOD_FAILED_ERROR_MSG);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_FLOW_MOD_FAILED_ERROR_MSG);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_flow_mod_failed_error_msg_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_flow_mod_failed_error_msg_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_flow_mod_failed_error_msg_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_flow_modify_OF_VERSION_1_3(void)
{
    of_flow_modify_t *obj;
    obj = of_flow_modify_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 56);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_MODIFY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 56);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_FLOW_MODIFY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_flow_modify_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_flow_modify_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_flow_modify_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_flow_modify_strict_OF_VERSION_1_3(void)
{
    of_flow_modify_strict_t *obj;
    obj = of_flow_modify_strict_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 56);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_MODIFY_STRICT);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 56);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_FLOW_MODIFY_STRICT);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_flow_modify_strict_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_flow_modify_strict_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_flow_modify_strict_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_flow_removed_OF_VERSION_1_3(void)
{
    of_flow_removed_t *obj;
    obj = of_flow_removed_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 56);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_REMOVED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 56);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_FLOW_REMOVED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_flow_removed_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_flow_removed_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_flow_removed_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_flow_stats_reply_OF_VERSION_1_3(void)
{
    of_flow_stats_reply_t *obj;
    obj = of_flow_stats_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_STATS_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_FLOW_STATS_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_flow_stats_reply_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_flow_stats_reply_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_flow_stats_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_flow_stats_request_OF_VERSION_1_3(void)
{
    of_flow_stats_request_t *obj;
    obj = of_flow_stats_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 56);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_STATS_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 56);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_FLOW_STATS_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_flow_stats_request_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_flow_stats_request_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_flow_stats_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_get_config_reply_OF_VERSION_1_3(void)
{
    of_get_config_reply_t *obj;
    obj = of_get_config_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_GET_CONFIG_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_GET_CONFIG_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_get_config_reply_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_get_config_reply_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_get_config_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_get_config_request_OF_VERSION_1_3(void)
{
    of_get_config_request_t *obj;
    obj = of_get_config_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_GET_CONFIG_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_GET_CONFIG_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_get_config_request_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_get_config_request_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_get_config_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_group_desc_stats_reply_OF_VERSION_1_3(void)
{
    of_group_desc_stats_reply_t *obj;
    obj = of_group_desc_stats_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_GROUP_DESC_STATS_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_GROUP_DESC_STATS_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_group_desc_stats_reply_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_group_desc_stats_reply_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_group_desc_stats_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_group_desc_stats_request_OF_VERSION_1_3(void)
{
    of_group_desc_stats_request_t *obj;
    obj = of_group_desc_stats_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_GROUP_DESC_STATS_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_GROUP_DESC_STATS_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_group_desc_stats_request_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_group_desc_stats_request_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_group_desc_stats_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_group_features_stats_reply_OF_VERSION_1_3(void)
{
    of_group_features_stats_reply_t *obj;
    obj = of_group_features_stats_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 56);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_GROUP_FEATURES_STATS_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 56);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_GROUP_FEATURES_STATS_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_group_features_stats_reply_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_group_features_stats_reply_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_group_features_stats_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_group_features_stats_request_OF_VERSION_1_3(void)
{
    of_group_features_stats_request_t *obj;
    obj = of_group_features_stats_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_GROUP_FEATURES_STATS_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_GROUP_FEATURES_STATS_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_group_features_stats_request_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_group_features_stats_request_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_group_features_stats_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_group_mod_OF_VERSION_1_3(void)
{
    of_group_mod_t *obj;
    obj = of_group_mod_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_GROUP_MOD);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_GROUP_MOD);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_group_mod_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_group_mod_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_group_mod_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_group_mod_failed_error_msg_OF_VERSION_1_3(void)
{
    of_group_mod_failed_error_msg_t *obj;
    obj = of_group_mod_failed_error_msg_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_GROUP_MOD_FAILED_ERROR_MSG);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_GROUP_MOD_FAILED_ERROR_MSG);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_group_mod_failed_error_msg_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_group_mod_failed_error_msg_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_group_mod_failed_error_msg_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_group_stats_reply_OF_VERSION_1_3(void)
{
    of_group_stats_reply_t *obj;
    obj = of_group_stats_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_GROUP_STATS_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_GROUP_STATS_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_group_stats_reply_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_group_stats_reply_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_group_stats_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_group_stats_request_OF_VERSION_1_3(void)
{
    of_group_stats_request_t *obj;
    obj = of_group_stats_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_GROUP_STATS_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 24);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_GROUP_STATS_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_group_stats_request_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_group_stats_request_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_group_stats_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_hello_OF_VERSION_1_3(void)
{
    of_hello_t *obj;
    obj = of_hello_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_HELLO);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_HELLO);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_hello_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_hello_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_hello_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_hello_failed_error_msg_OF_VERSION_1_3(void)
{
    of_hello_failed_error_msg_t *obj;
    obj = of_hello_failed_error_msg_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_HELLO_FAILED_ERROR_MSG);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_HELLO_FAILED_ERROR_MSG);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_hello_failed_error_msg_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_hello_failed_error_msg_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_hello_failed_error_msg_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_meter_config_stats_reply_OF_VERSION_1_3(void)
{
    of_meter_config_stats_reply_t *obj;
    obj = of_meter_config_stats_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_METER_CONFIG_STATS_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_METER_CONFIG_STATS_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_meter_config_stats_reply_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_meter_config_stats_reply_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_meter_config_stats_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_meter_config_stats_request_OF_VERSION_1_3(void)
{
    of_meter_config_stats_request_t *obj;
    obj = of_meter_config_stats_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_METER_CONFIG_STATS_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 24);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_METER_CONFIG_STATS_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_meter_config_stats_request_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_meter_config_stats_request_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_meter_config_stats_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_meter_features_stats_reply_OF_VERSION_1_3(void)
{
    of_meter_features_stats_reply_t *obj;
    obj = of_meter_features_stats_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 32);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_METER_FEATURES_STATS_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 32);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_METER_FEATURES_STATS_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_meter_features_stats_reply_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_meter_features_stats_reply_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_meter_features_stats_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_meter_features_stats_request_OF_VERSION_1_3(void)
{
    of_meter_features_stats_request_t *obj;
    obj = of_meter_features_stats_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_METER_FEATURES_STATS_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_METER_FEATURES_STATS_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_meter_features_stats_request_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_meter_features_stats_request_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_meter_features_stats_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_meter_mod_OF_VERSION_1_3(void)
{
    of_meter_mod_t *obj;
    obj = of_meter_mod_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_METER_MOD);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_METER_MOD);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_meter_mod_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_meter_mod_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_meter_mod_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_meter_mod_failed_error_msg_OF_VERSION_1_3(void)
{
    of_meter_mod_failed_error_msg_t *obj;
    obj = of_meter_mod_failed_error_msg_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_METER_MOD_FAILED_ERROR_MSG);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_METER_MOD_FAILED_ERROR_MSG);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_meter_mod_failed_error_msg_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_meter_mod_failed_error_msg_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_meter_mod_failed_error_msg_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_meter_stats_reply_OF_VERSION_1_3(void)
{
    of_meter_stats_reply_t *obj;
    obj = of_meter_stats_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_METER_STATS_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_METER_STATS_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_meter_stats_reply_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_meter_stats_reply_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_meter_stats_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_meter_stats_request_OF_VERSION_1_3(void)
{
    of_meter_stats_request_t *obj;
    obj = of_meter_stats_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_METER_STATS_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 24);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_METER_STATS_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_meter_stats_request_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_meter_stats_request_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_meter_stats_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_nicira_header_OF_VERSION_1_3(void)
{
    of_nicira_header_t *obj;
    obj = of_nicira_header_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_NICIRA_HEADER);

    of_nicira_header_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_packet_in_OF_VERSION_1_3(void)
{
    of_packet_in_t *obj;
    obj = of_packet_in_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 34);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_PACKET_IN);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 34);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_PACKET_IN);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_packet_in_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_packet_in_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_packet_in_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_packet_out_OF_VERSION_1_3(void)
{
    of_packet_out_t *obj;
    obj = of_packet_out_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_PACKET_OUT);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 24);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_PACKET_OUT);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_packet_out_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_packet_out_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_packet_out_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_port_desc_stats_reply_OF_VERSION_1_3(void)
{
    of_port_desc_stats_reply_t *obj;
    obj = of_port_desc_stats_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_PORT_DESC_STATS_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_PORT_DESC_STATS_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_port_desc_stats_reply_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_port_desc_stats_reply_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_port_desc_stats_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_port_desc_stats_request_OF_VERSION_1_3(void)
{
    of_port_desc_stats_request_t *obj;
    obj = of_port_desc_stats_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_PORT_DESC_STATS_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_PORT_DESC_STATS_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_port_desc_stats_request_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_port_desc_stats_request_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_port_desc_stats_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_port_mod_OF_VERSION_1_3(void)
{
    of_port_mod_t *obj;
    obj = of_port_mod_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 40);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_PORT_MOD);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 40);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_PORT_MOD);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_port_mod_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_port_mod_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_port_mod_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_port_mod_failed_error_msg_OF_VERSION_1_3(void)
{
    of_port_mod_failed_error_msg_t *obj;
    obj = of_port_mod_failed_error_msg_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_PORT_MOD_FAILED_ERROR_MSG);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_PORT_MOD_FAILED_ERROR_MSG);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_port_mod_failed_error_msg_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_port_mod_failed_error_msg_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_port_mod_failed_error_msg_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_port_stats_reply_OF_VERSION_1_3(void)
{
    of_port_stats_reply_t *obj;
    obj = of_port_stats_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_PORT_STATS_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_PORT_STATS_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_port_stats_reply_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_port_stats_reply_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_port_stats_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_port_stats_request_OF_VERSION_1_3(void)
{
    of_port_stats_request_t *obj;
    obj = of_port_stats_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_PORT_STATS_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 24);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_PORT_STATS_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_port_stats_request_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_port_stats_request_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_port_stats_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_port_status_OF_VERSION_1_3(void)
{
    of_port_status_t *obj;
    obj = of_port_status_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 80);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_PORT_STATUS);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 80);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_PORT_STATUS);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_port_status_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_port_status_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_port_status_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_queue_get_config_reply_OF_VERSION_1_3(void)
{
    of_queue_get_config_reply_t *obj;
    obj = of_queue_get_config_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_QUEUE_GET_CONFIG_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_QUEUE_GET_CONFIG_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_queue_get_config_reply_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_queue_get_config_reply_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_queue_get_config_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_queue_get_config_request_OF_VERSION_1_3(void)
{
    of_queue_get_config_request_t *obj;
    obj = of_queue_get_config_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_QUEUE_GET_CONFIG_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_QUEUE_GET_CONFIG_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_queue_get_config_request_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_queue_get_config_request_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_queue_get_config_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_queue_op_failed_error_msg_OF_VERSION_1_3(void)
{
    of_queue_op_failed_error_msg_t *obj;
    obj = of_queue_op_failed_error_msg_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_QUEUE_OP_FAILED_ERROR_MSG);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_QUEUE_OP_FAILED_ERROR_MSG);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_queue_op_failed_error_msg_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_queue_op_failed_error_msg_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_queue_op_failed_error_msg_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_queue_stats_reply_OF_VERSION_1_3(void)
{
    of_queue_stats_reply_t *obj;
    obj = of_queue_stats_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_QUEUE_STATS_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_QUEUE_STATS_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_queue_stats_reply_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_queue_stats_reply_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_queue_stats_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_queue_stats_request_OF_VERSION_1_3(void)
{
    of_queue_stats_request_t *obj;
    obj = of_queue_stats_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_QUEUE_STATS_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 24);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_QUEUE_STATS_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_queue_stats_request_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_queue_stats_request_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_queue_stats_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_role_reply_OF_VERSION_1_3(void)
{
    of_role_reply_t *obj;
    obj = of_role_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ROLE_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 24);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ROLE_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_role_reply_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_role_reply_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_role_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_role_request_OF_VERSION_1_3(void)
{
    of_role_request_t *obj;
    obj = of_role_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ROLE_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 24);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ROLE_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_role_request_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_role_request_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_role_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_role_request_failed_error_msg_OF_VERSION_1_3(void)
{
    of_role_request_failed_error_msg_t *obj;
    obj = of_role_request_failed_error_msg_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ROLE_REQUEST_FAILED_ERROR_MSG);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ROLE_REQUEST_FAILED_ERROR_MSG);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_role_request_failed_error_msg_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_role_request_failed_error_msg_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_role_request_failed_error_msg_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_set_config_OF_VERSION_1_3(void)
{
    of_set_config_t *obj;
    obj = of_set_config_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_SET_CONFIG);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_SET_CONFIG);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_set_config_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_set_config_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_set_config_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_stats_reply_OF_VERSION_1_3(void)
{
    of_stats_reply_t *obj;
    obj = of_stats_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_STATS_REPLY);

    of_stats_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_stats_request_OF_VERSION_1_3(void)
{
    of_stats_request_t *obj;
    obj = of_stats_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_STATS_REQUEST);

    of_stats_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_switch_config_failed_error_msg_OF_VERSION_1_3(void)
{
    of_switch_config_failed_error_msg_t *obj;
    obj = of_switch_config_failed_error_msg_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_SWITCH_CONFIG_FAILED_ERROR_MSG);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_SWITCH_CONFIG_FAILED_ERROR_MSG);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_switch_config_failed_error_msg_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_switch_config_failed_error_msg_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_switch_config_failed_error_msg_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_table_features_failed_error_msg_OF_VERSION_1_3(void)
{
    of_table_features_failed_error_msg_t *obj;
    obj = of_table_features_failed_error_msg_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_TABLE_FEATURES_FAILED_ERROR_MSG);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_TABLE_FEATURES_FAILED_ERROR_MSG);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_table_features_failed_error_msg_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_table_features_failed_error_msg_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_table_features_failed_error_msg_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_table_features_stats_reply_OF_VERSION_1_3(void)
{
    of_table_features_stats_reply_t *obj;
    obj = of_table_features_stats_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_TABLE_FEATURES_STATS_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_TABLE_FEATURES_STATS_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_table_features_stats_reply_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_table_features_stats_reply_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_table_features_stats_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_table_features_stats_request_OF_VERSION_1_3(void)
{
    of_table_features_stats_request_t *obj;
    obj = of_table_features_stats_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_TABLE_FEATURES_STATS_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_TABLE_FEATURES_STATS_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_table_features_stats_request_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_table_features_stats_request_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_table_features_stats_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_table_mod_OF_VERSION_1_3(void)
{
    of_table_mod_t *obj;
    obj = of_table_mod_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_TABLE_MOD);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_TABLE_MOD);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_table_mod_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_table_mod_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_table_mod_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_table_mod_failed_error_msg_OF_VERSION_1_3(void)
{
    of_table_mod_failed_error_msg_t *obj;
    obj = of_table_mod_failed_error_msg_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_TABLE_MOD_FAILED_ERROR_MSG);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_TABLE_MOD_FAILED_ERROR_MSG);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_table_mod_failed_error_msg_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_table_mod_failed_error_msg_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_table_mod_failed_error_msg_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_table_stats_reply_OF_VERSION_1_3(void)
{
    of_table_stats_reply_t *obj;
    obj = of_table_stats_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_TABLE_STATS_REPLY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_TABLE_STATS_REPLY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_table_stats_reply_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_table_stats_reply_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_table_stats_reply_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_table_stats_request_OF_VERSION_1_3(void)
{
    of_table_stats_request_t *obj;
    obj = of_table_stats_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_TABLE_STATS_REQUEST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_TABLE_STATS_REQUEST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_table_stats_request_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_table_stats_request_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_table_stats_request_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_bsn_OF_VERSION_1_3(void)
{
    of_action_bsn_t *obj;
    obj = of_action_bsn_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_BSN);

    of_action_bsn_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_bsn_mirror_OF_VERSION_1_3(void)
{
    of_action_bsn_mirror_t *obj;
    obj = of_action_bsn_mirror_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_BSN_MIRROR);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 24);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_BSN_MIRROR);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_bsn_mirror_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_bsn_mirror_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_action_bsn_mirror_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_bsn_set_tunnel_dst_OF_VERSION_1_3(void)
{
    of_action_bsn_set_tunnel_dst_t *obj;
    obj = of_action_bsn_set_tunnel_dst_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_BSN_SET_TUNNEL_DST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_BSN_SET_TUNNEL_DST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_bsn_set_tunnel_dst_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_bsn_set_tunnel_dst_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_action_bsn_set_tunnel_dst_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_copy_ttl_in_OF_VERSION_1_3(void)
{
    of_action_copy_ttl_in_t *obj;
    obj = of_action_copy_ttl_in_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_COPY_TTL_IN);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_COPY_TTL_IN);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_copy_ttl_in_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_copy_ttl_in_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_action_copy_ttl_in_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_copy_ttl_out_OF_VERSION_1_3(void)
{
    of_action_copy_ttl_out_t *obj;
    obj = of_action_copy_ttl_out_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_COPY_TTL_OUT);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_COPY_TTL_OUT);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_copy_ttl_out_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_copy_ttl_out_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_action_copy_ttl_out_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_dec_mpls_ttl_OF_VERSION_1_3(void)
{
    of_action_dec_mpls_ttl_t *obj;
    obj = of_action_dec_mpls_ttl_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_DEC_MPLS_TTL);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_DEC_MPLS_TTL);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_dec_mpls_ttl_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_dec_mpls_ttl_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_action_dec_mpls_ttl_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_dec_nw_ttl_OF_VERSION_1_3(void)
{
    of_action_dec_nw_ttl_t *obj;
    obj = of_action_dec_nw_ttl_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_DEC_NW_TTL);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_DEC_NW_TTL);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_dec_nw_ttl_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_dec_nw_ttl_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_action_dec_nw_ttl_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_experimenter_OF_VERSION_1_3(void)
{
    of_action_experimenter_t *obj;
    obj = of_action_experimenter_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_EXPERIMENTER);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_EXPERIMENTER);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_experimenter_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_experimenter_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_action_experimenter_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_group_OF_VERSION_1_3(void)
{
    of_action_group_t *obj;
    obj = of_action_group_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_GROUP);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_GROUP);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_group_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_group_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_action_group_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_header_OF_VERSION_1_3(void)
{
    of_action_header_t *obj;
    obj = of_action_header_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_HEADER);

    of_action_header_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_id_bsn_OF_VERSION_1_3(void)
{
    of_action_id_bsn_t *obj;
    obj = of_action_id_bsn_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_ID_BSN);

    of_action_id_bsn_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_id_bsn_mirror_OF_VERSION_1_3(void)
{
    of_action_id_bsn_mirror_t *obj;
    obj = of_action_id_bsn_mirror_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_ID_BSN_MIRROR);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_ID_BSN_MIRROR);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_id_bsn_mirror_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_id_bsn_mirror_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_action_id_bsn_mirror_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_id_bsn_set_tunnel_dst_OF_VERSION_1_3(void)
{
    of_action_id_bsn_set_tunnel_dst_t *obj;
    obj = of_action_id_bsn_set_tunnel_dst_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_ID_BSN_SET_TUNNEL_DST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_ID_BSN_SET_TUNNEL_DST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_id_bsn_set_tunnel_dst_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_id_bsn_set_tunnel_dst_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_action_id_bsn_set_tunnel_dst_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_id_copy_ttl_in_OF_VERSION_1_3(void)
{
    of_action_id_copy_ttl_in_t *obj;
    obj = of_action_id_copy_ttl_in_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_ID_COPY_TTL_IN);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_ID_COPY_TTL_IN);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_id_copy_ttl_in_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_id_copy_ttl_in_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_action_id_copy_ttl_in_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_id_copy_ttl_out_OF_VERSION_1_3(void)
{
    of_action_id_copy_ttl_out_t *obj;
    obj = of_action_id_copy_ttl_out_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_ID_COPY_TTL_OUT);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_ID_COPY_TTL_OUT);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_id_copy_ttl_out_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_id_copy_ttl_out_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_action_id_copy_ttl_out_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_id_dec_mpls_ttl_OF_VERSION_1_3(void)
{
    of_action_id_dec_mpls_ttl_t *obj;
    obj = of_action_id_dec_mpls_ttl_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_ID_DEC_MPLS_TTL);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_ID_DEC_MPLS_TTL);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_id_dec_mpls_ttl_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_id_dec_mpls_ttl_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_action_id_dec_mpls_ttl_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_id_dec_nw_ttl_OF_VERSION_1_3(void)
{
    of_action_id_dec_nw_ttl_t *obj;
    obj = of_action_id_dec_nw_ttl_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_ID_DEC_NW_TTL);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_ID_DEC_NW_TTL);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_id_dec_nw_ttl_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_id_dec_nw_ttl_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_action_id_dec_nw_ttl_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_id_experimenter_OF_VERSION_1_3(void)
{
    of_action_id_experimenter_t *obj;
    obj = of_action_id_experimenter_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_ID_EXPERIMENTER);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_ID_EXPERIMENTER);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_id_experimenter_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_id_experimenter_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_action_id_experimenter_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_id_group_OF_VERSION_1_3(void)
{
    of_action_id_group_t *obj;
    obj = of_action_id_group_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_ID_GROUP);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_ID_GROUP);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_id_group_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_id_group_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_action_id_group_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_id_header_OF_VERSION_1_3(void)
{
    of_action_id_header_t *obj;
    obj = of_action_id_header_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_ID_HEADER);

    of_action_id_header_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_id_nicira_OF_VERSION_1_3(void)
{
    of_action_id_nicira_t *obj;
    obj = of_action_id_nicira_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_ID_NICIRA);

    of_action_id_nicira_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_id_nicira_dec_ttl_OF_VERSION_1_3(void)
{
    of_action_id_nicira_dec_ttl_t *obj;
    obj = of_action_id_nicira_dec_ttl_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 10);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_ID_NICIRA_DEC_TTL);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 10);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_ID_NICIRA_DEC_TTL);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_id_nicira_dec_ttl_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_id_nicira_dec_ttl_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_action_id_nicira_dec_ttl_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_id_output_OF_VERSION_1_3(void)
{
    of_action_id_output_t *obj;
    obj = of_action_id_output_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_ID_OUTPUT);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_ID_OUTPUT);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_id_output_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_id_output_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_action_id_output_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_id_pop_mpls_OF_VERSION_1_3(void)
{
    of_action_id_pop_mpls_t *obj;
    obj = of_action_id_pop_mpls_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_ID_POP_MPLS);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_ID_POP_MPLS);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_id_pop_mpls_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_id_pop_mpls_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_action_id_pop_mpls_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_id_pop_pbb_OF_VERSION_1_3(void)
{
    of_action_id_pop_pbb_t *obj;
    obj = of_action_id_pop_pbb_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_ID_POP_PBB);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_ID_POP_PBB);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_id_pop_pbb_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_id_pop_pbb_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_action_id_pop_pbb_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_id_pop_vlan_OF_VERSION_1_3(void)
{
    of_action_id_pop_vlan_t *obj;
    obj = of_action_id_pop_vlan_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_ID_POP_VLAN);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_ID_POP_VLAN);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_id_pop_vlan_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_id_pop_vlan_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_action_id_pop_vlan_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_id_push_mpls_OF_VERSION_1_3(void)
{
    of_action_id_push_mpls_t *obj;
    obj = of_action_id_push_mpls_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_ID_PUSH_MPLS);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_ID_PUSH_MPLS);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_id_push_mpls_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_id_push_mpls_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_action_id_push_mpls_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_id_push_pbb_OF_VERSION_1_3(void)
{
    of_action_id_push_pbb_t *obj;
    obj = of_action_id_push_pbb_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_ID_PUSH_PBB);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_ID_PUSH_PBB);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_id_push_pbb_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_id_push_pbb_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_action_id_push_pbb_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_id_push_vlan_OF_VERSION_1_3(void)
{
    of_action_id_push_vlan_t *obj;
    obj = of_action_id_push_vlan_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_ID_PUSH_VLAN);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_ID_PUSH_VLAN);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_id_push_vlan_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_id_push_vlan_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_action_id_push_vlan_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_id_set_field_OF_VERSION_1_3(void)
{
    of_action_id_set_field_t *obj;
    obj = of_action_id_set_field_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_ID_SET_FIELD);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_ID_SET_FIELD);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_id_set_field_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_id_set_field_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_action_id_set_field_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_id_set_mpls_ttl_OF_VERSION_1_3(void)
{
    of_action_id_set_mpls_ttl_t *obj;
    obj = of_action_id_set_mpls_ttl_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_ID_SET_MPLS_TTL);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_ID_SET_MPLS_TTL);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_id_set_mpls_ttl_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_id_set_mpls_ttl_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_action_id_set_mpls_ttl_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_id_set_nw_ttl_OF_VERSION_1_3(void)
{
    of_action_id_set_nw_ttl_t *obj;
    obj = of_action_id_set_nw_ttl_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_ID_SET_NW_TTL);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_ID_SET_NW_TTL);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_id_set_nw_ttl_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_id_set_nw_ttl_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_action_id_set_nw_ttl_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_id_set_queue_OF_VERSION_1_3(void)
{
    of_action_id_set_queue_t *obj;
    obj = of_action_id_set_queue_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_ID_SET_QUEUE);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_ID_SET_QUEUE);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_id_set_queue_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_id_set_queue_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_action_id_set_queue_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_nicira_OF_VERSION_1_3(void)
{
    of_action_nicira_t *obj;
    obj = of_action_nicira_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_NICIRA);

    of_action_nicira_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_nicira_dec_ttl_OF_VERSION_1_3(void)
{
    of_action_nicira_dec_ttl_t *obj;
    obj = of_action_nicira_dec_ttl_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_NICIRA_DEC_TTL);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_NICIRA_DEC_TTL);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_nicira_dec_ttl_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_nicira_dec_ttl_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_action_nicira_dec_ttl_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_output_OF_VERSION_1_3(void)
{
    of_action_output_t *obj;
    obj = of_action_output_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_OUTPUT);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_OUTPUT);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_output_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_output_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_action_output_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_pop_mpls_OF_VERSION_1_3(void)
{
    of_action_pop_mpls_t *obj;
    obj = of_action_pop_mpls_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_POP_MPLS);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_POP_MPLS);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_pop_mpls_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_pop_mpls_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_action_pop_mpls_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_pop_pbb_OF_VERSION_1_3(void)
{
    of_action_pop_pbb_t *obj;
    obj = of_action_pop_pbb_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_POP_PBB);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_POP_PBB);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_pop_pbb_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_pop_pbb_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_action_pop_pbb_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_pop_vlan_OF_VERSION_1_3(void)
{
    of_action_pop_vlan_t *obj;
    obj = of_action_pop_vlan_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_POP_VLAN);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_POP_VLAN);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_pop_vlan_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_pop_vlan_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_action_pop_vlan_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_push_mpls_OF_VERSION_1_3(void)
{
    of_action_push_mpls_t *obj;
    obj = of_action_push_mpls_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_PUSH_MPLS);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_PUSH_MPLS);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_push_mpls_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_push_mpls_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_action_push_mpls_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_push_pbb_OF_VERSION_1_3(void)
{
    of_action_push_pbb_t *obj;
    obj = of_action_push_pbb_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_PUSH_PBB);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_PUSH_PBB);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_push_pbb_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_push_pbb_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_action_push_pbb_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_push_vlan_OF_VERSION_1_3(void)
{
    of_action_push_vlan_t *obj;
    obj = of_action_push_vlan_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_PUSH_VLAN);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_PUSH_VLAN);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_push_vlan_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_push_vlan_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_action_push_vlan_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_set_field_OF_VERSION_1_3(void)
{
    of_action_set_field_t *obj;
    obj = of_action_set_field_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 4);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_SET_FIELD);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 4);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_SET_FIELD);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_set_field_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_set_field_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_action_set_field_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_set_mpls_ttl_OF_VERSION_1_3(void)
{
    of_action_set_mpls_ttl_t *obj;
    obj = of_action_set_mpls_ttl_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_SET_MPLS_TTL);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_SET_MPLS_TTL);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_set_mpls_ttl_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_set_mpls_ttl_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_action_set_mpls_ttl_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_set_nw_ttl_OF_VERSION_1_3(void)
{
    of_action_set_nw_ttl_t *obj;
    obj = of_action_set_nw_ttl_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_SET_NW_TTL);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_SET_NW_TTL);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_set_nw_ttl_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_set_nw_ttl_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_action_set_nw_ttl_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_action_set_queue_OF_VERSION_1_3(void)
{
    of_action_set_queue_t *obj;
    obj = of_action_set_queue_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_SET_QUEUE);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_ACTION_SET_QUEUE);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_action_set_queue_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_action_set_queue_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_action_set_queue_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_interface_OF_VERSION_1_3(void)
{
    of_bsn_interface_t *obj;
    obj = of_bsn_interface_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 32);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_INTERFACE);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 32);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_INTERFACE);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_interface_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_interface_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_bsn_interface_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_lacp_stats_entry_OF_VERSION_1_3(void)
{
    of_bsn_lacp_stats_entry_t *obj;
    obj = of_bsn_lacp_stats_entry_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 36);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_LACP_STATS_ENTRY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 36);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_LACP_STATS_ENTRY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_lacp_stats_entry_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_lacp_stats_entry_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_bsn_lacp_stats_entry_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_vport_header_OF_VERSION_1_3(void)
{
    of_bsn_vport_header_t *obj;
    obj = of_bsn_vport_header_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 4);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_VPORT_HEADER);

    of_bsn_vport_header_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bsn_vport_q_in_q_OF_VERSION_1_3(void)
{
    of_bsn_vport_q_in_q_t *obj;
    obj = of_bsn_vport_q_in_q_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 32);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_VPORT_Q_IN_Q);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 32);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BSN_VPORT_Q_IN_Q);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bsn_vport_q_in_q_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bsn_vport_q_in_q_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_bsn_vport_q_in_q_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bucket_OF_VERSION_1_3(void)
{
    of_bucket_t *obj;
    obj = of_bucket_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BUCKET);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BUCKET);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bucket_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bucket_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_bucket_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_bucket_counter_OF_VERSION_1_3(void)
{
    of_bucket_counter_t *obj;
    obj = of_bucket_counter_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BUCKET_COUNTER);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_BUCKET_COUNTER);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_bucket_counter_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_bucket_counter_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_bucket_counter_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_experimenter_stats_header_OF_VERSION_1_3(void)
{
    of_experimenter_stats_header_t *obj;
    obj = of_experimenter_stats_header_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_EXPERIMENTER_STATS_HEADER);

    of_experimenter_stats_header_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_flow_stats_entry_OF_VERSION_1_3(void)
{
    of_flow_stats_entry_t *obj;
    obj = of_flow_stats_entry_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 56);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_STATS_ENTRY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 56);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_FLOW_STATS_ENTRY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_flow_stats_entry_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_flow_stats_entry_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_flow_stats_entry_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_group_desc_stats_entry_OF_VERSION_1_3(void)
{
    of_group_desc_stats_entry_t *obj;
    obj = of_group_desc_stats_entry_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_GROUP_DESC_STATS_ENTRY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_GROUP_DESC_STATS_ENTRY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_group_desc_stats_entry_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_group_desc_stats_entry_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_group_desc_stats_entry_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_group_stats_entry_OF_VERSION_1_3(void)
{
    of_group_stats_entry_t *obj;
    obj = of_group_stats_entry_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 40);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_GROUP_STATS_ENTRY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 40);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_GROUP_STATS_ENTRY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_group_stats_entry_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_group_stats_entry_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_group_stats_entry_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_header_OF_VERSION_1_3(void)
{
    of_header_t *obj;
    obj = of_header_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_HEADER);

    of_header_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_hello_elem_header_OF_VERSION_1_3(void)
{
    of_hello_elem_header_t *obj;
    obj = of_hello_elem_header_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 4);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_HELLO_ELEM_HEADER);

    of_hello_elem_header_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_hello_elem_versionbitmap_OF_VERSION_1_3(void)
{
    of_hello_elem_versionbitmap_t *obj;
    obj = of_hello_elem_versionbitmap_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 4);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_HELLO_ELEM_VERSIONBITMAP);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 4);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_HELLO_ELEM_VERSIONBITMAP);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_hello_elem_versionbitmap_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_hello_elem_versionbitmap_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_hello_elem_versionbitmap_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_instruction_apply_actions_OF_VERSION_1_3(void)
{
    of_instruction_apply_actions_t *obj;
    obj = of_instruction_apply_actions_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_INSTRUCTION_APPLY_ACTIONS);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_INSTRUCTION_APPLY_ACTIONS);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_instruction_apply_actions_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_instruction_apply_actions_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_instruction_apply_actions_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_instruction_clear_actions_OF_VERSION_1_3(void)
{
    of_instruction_clear_actions_t *obj;
    obj = of_instruction_clear_actions_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_INSTRUCTION_CLEAR_ACTIONS);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_INSTRUCTION_CLEAR_ACTIONS);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_instruction_clear_actions_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_instruction_clear_actions_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_instruction_clear_actions_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_instruction_experimenter_OF_VERSION_1_3(void)
{
    of_instruction_experimenter_t *obj;
    obj = of_instruction_experimenter_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_INSTRUCTION_EXPERIMENTER);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_INSTRUCTION_EXPERIMENTER);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_instruction_experimenter_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_instruction_experimenter_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_instruction_experimenter_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_instruction_goto_table_OF_VERSION_1_3(void)
{
    of_instruction_goto_table_t *obj;
    obj = of_instruction_goto_table_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_INSTRUCTION_GOTO_TABLE);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_INSTRUCTION_GOTO_TABLE);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_instruction_goto_table_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_instruction_goto_table_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_instruction_goto_table_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_instruction_header_OF_VERSION_1_3(void)
{
    of_instruction_header_t *obj;
    obj = of_instruction_header_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 4);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_INSTRUCTION_HEADER);

    of_instruction_header_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_instruction_meter_OF_VERSION_1_3(void)
{
    of_instruction_meter_t *obj;
    obj = of_instruction_meter_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_INSTRUCTION_METER);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_INSTRUCTION_METER);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_instruction_meter_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_instruction_meter_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_instruction_meter_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_instruction_write_actions_OF_VERSION_1_3(void)
{
    of_instruction_write_actions_t *obj;
    obj = of_instruction_write_actions_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_INSTRUCTION_WRITE_ACTIONS);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_INSTRUCTION_WRITE_ACTIONS);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_instruction_write_actions_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_instruction_write_actions_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_instruction_write_actions_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_instruction_write_metadata_OF_VERSION_1_3(void)
{
    of_instruction_write_metadata_t *obj;
    obj = of_instruction_write_metadata_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_INSTRUCTION_WRITE_METADATA);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 24);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_INSTRUCTION_WRITE_METADATA);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_instruction_write_metadata_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_instruction_write_metadata_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_instruction_write_metadata_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_match_v3_OF_VERSION_1_3(void)
{
    of_match_v3_t *obj;
    obj = of_match_v3_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 4);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_MATCH_V3);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 4);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_MATCH_V3);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_match_v3_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_match_v3_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_match_v3_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_meter_band_drop_OF_VERSION_1_3(void)
{
    of_meter_band_drop_t *obj;
    obj = of_meter_band_drop_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_METER_BAND_DROP);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_METER_BAND_DROP);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_meter_band_drop_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_meter_band_drop_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_meter_band_drop_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_meter_band_dscp_remark_OF_VERSION_1_3(void)
{
    of_meter_band_dscp_remark_t *obj;
    obj = of_meter_band_dscp_remark_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_METER_BAND_DSCP_REMARK);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_METER_BAND_DSCP_REMARK);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_meter_band_dscp_remark_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_meter_band_dscp_remark_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_meter_band_dscp_remark_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_meter_band_experimenter_OF_VERSION_1_3(void)
{
    of_meter_band_experimenter_t *obj;
    obj = of_meter_band_experimenter_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_METER_BAND_EXPERIMENTER);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_METER_BAND_EXPERIMENTER);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_meter_band_experimenter_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_meter_band_experimenter_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_meter_band_experimenter_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_meter_band_header_OF_VERSION_1_3(void)
{
    of_meter_band_header_t *obj;
    obj = of_meter_band_header_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 4);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_METER_BAND_HEADER);

    of_meter_band_header_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_meter_band_stats_OF_VERSION_1_3(void)
{
    of_meter_band_stats_t *obj;
    obj = of_meter_band_stats_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_METER_BAND_STATS);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_METER_BAND_STATS);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_meter_band_stats_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_meter_band_stats_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_meter_band_stats_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_meter_config_OF_VERSION_1_3(void)
{
    of_meter_config_t *obj;
    obj = of_meter_config_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_METER_CONFIG);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_METER_CONFIG);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_meter_config_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_meter_config_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_meter_config_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_meter_features_OF_VERSION_1_3(void)
{
    of_meter_features_t *obj;
    obj = of_meter_features_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_METER_FEATURES);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_METER_FEATURES);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_meter_features_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_meter_features_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_meter_features_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_meter_stats_OF_VERSION_1_3(void)
{
    of_meter_stats_t *obj;
    obj = of_meter_stats_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 40);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_METER_STATS);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 40);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_METER_STATS);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_meter_stats_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_meter_stats_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_meter_stats_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_arp_op_OF_VERSION_1_3(void)
{
    of_oxm_arp_op_t *obj;
    obj = of_oxm_arp_op_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 6);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_ARP_OP);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 6);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_ARP_OP);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_arp_op_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_arp_op_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_oxm_arp_op_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_arp_op_masked_OF_VERSION_1_3(void)
{
    of_oxm_arp_op_masked_t *obj;
    obj = of_oxm_arp_op_masked_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_ARP_OP_MASKED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_ARP_OP_MASKED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_arp_op_masked_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_arp_op_masked_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_oxm_arp_op_masked_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_arp_sha_OF_VERSION_1_3(void)
{
    of_oxm_arp_sha_t *obj;
    obj = of_oxm_arp_sha_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 10);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_ARP_SHA);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 10);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_ARP_SHA);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_arp_sha_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_arp_sha_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_oxm_arp_sha_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_arp_sha_masked_OF_VERSION_1_3(void)
{
    of_oxm_arp_sha_masked_t *obj;
    obj = of_oxm_arp_sha_masked_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_ARP_SHA_MASKED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_ARP_SHA_MASKED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_arp_sha_masked_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_arp_sha_masked_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_oxm_arp_sha_masked_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_arp_spa_OF_VERSION_1_3(void)
{
    of_oxm_arp_spa_t *obj;
    obj = of_oxm_arp_spa_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_ARP_SPA);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_ARP_SPA);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_arp_spa_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_arp_spa_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_oxm_arp_spa_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_arp_spa_masked_OF_VERSION_1_3(void)
{
    of_oxm_arp_spa_masked_t *obj;
    obj = of_oxm_arp_spa_masked_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_ARP_SPA_MASKED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_ARP_SPA_MASKED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_arp_spa_masked_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_arp_spa_masked_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_oxm_arp_spa_masked_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_arp_tha_OF_VERSION_1_3(void)
{
    of_oxm_arp_tha_t *obj;
    obj = of_oxm_arp_tha_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 10);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_ARP_THA);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 10);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_ARP_THA);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_arp_tha_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_arp_tha_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_oxm_arp_tha_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_arp_tha_masked_OF_VERSION_1_3(void)
{
    of_oxm_arp_tha_masked_t *obj;
    obj = of_oxm_arp_tha_masked_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_ARP_THA_MASKED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_ARP_THA_MASKED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_arp_tha_masked_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_arp_tha_masked_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_oxm_arp_tha_masked_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_arp_tpa_OF_VERSION_1_3(void)
{
    of_oxm_arp_tpa_t *obj;
    obj = of_oxm_arp_tpa_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_ARP_TPA);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_ARP_TPA);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_arp_tpa_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_arp_tpa_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_oxm_arp_tpa_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_arp_tpa_masked_OF_VERSION_1_3(void)
{
    of_oxm_arp_tpa_masked_t *obj;
    obj = of_oxm_arp_tpa_masked_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_ARP_TPA_MASKED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_ARP_TPA_MASKED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_arp_tpa_masked_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_arp_tpa_masked_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_oxm_arp_tpa_masked_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_bsn_global_vrf_allowed_OF_VERSION_1_3(void)
{
    of_oxm_bsn_global_vrf_allowed_t *obj;
    obj = of_oxm_bsn_global_vrf_allowed_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 5);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_BSN_GLOBAL_VRF_ALLOWED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 5);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_BSN_GLOBAL_VRF_ALLOWED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_bsn_global_vrf_allowed_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_bsn_global_vrf_allowed_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_oxm_bsn_global_vrf_allowed_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_bsn_global_vrf_allowed_masked_OF_VERSION_1_3(void)
{
    of_oxm_bsn_global_vrf_allowed_masked_t *obj;
    obj = of_oxm_bsn_global_vrf_allowed_masked_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 6);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_BSN_GLOBAL_VRF_ALLOWED_MASKED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 6);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_BSN_GLOBAL_VRF_ALLOWED_MASKED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_bsn_global_vrf_allowed_masked_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_bsn_global_vrf_allowed_masked_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_oxm_bsn_global_vrf_allowed_masked_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_bsn_in_ports_128_OF_VERSION_1_3(void)
{
    of_oxm_bsn_in_ports_128_t *obj;
    obj = of_oxm_bsn_in_ports_128_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_BSN_IN_PORTS_128);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 20);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_BSN_IN_PORTS_128);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_bsn_in_ports_128_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_bsn_in_ports_128_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_oxm_bsn_in_ports_128_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_bsn_in_ports_128_masked_OF_VERSION_1_3(void)
{
    of_oxm_bsn_in_ports_128_masked_t *obj;
    obj = of_oxm_bsn_in_ports_128_masked_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 36);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_BSN_IN_PORTS_128_MASKED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 36);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_BSN_IN_PORTS_128_MASKED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_bsn_in_ports_128_masked_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_bsn_in_ports_128_masked_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_oxm_bsn_in_ports_128_masked_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_bsn_l3_dst_class_id_OF_VERSION_1_3(void)
{
    of_oxm_bsn_l3_dst_class_id_t *obj;
    obj = of_oxm_bsn_l3_dst_class_id_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_BSN_L3_DST_CLASS_ID);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_BSN_L3_DST_CLASS_ID);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_bsn_l3_dst_class_id_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_bsn_l3_dst_class_id_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_oxm_bsn_l3_dst_class_id_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_bsn_l3_dst_class_id_masked_OF_VERSION_1_3(void)
{
    of_oxm_bsn_l3_dst_class_id_masked_t *obj;
    obj = of_oxm_bsn_l3_dst_class_id_masked_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_BSN_L3_DST_CLASS_ID_MASKED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_BSN_L3_DST_CLASS_ID_MASKED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_bsn_l3_dst_class_id_masked_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_bsn_l3_dst_class_id_masked_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_oxm_bsn_l3_dst_class_id_masked_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_bsn_l3_interface_class_id_OF_VERSION_1_3(void)
{
    of_oxm_bsn_l3_interface_class_id_t *obj;
    obj = of_oxm_bsn_l3_interface_class_id_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_BSN_L3_INTERFACE_CLASS_ID);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_BSN_L3_INTERFACE_CLASS_ID);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_bsn_l3_interface_class_id_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_bsn_l3_interface_class_id_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_oxm_bsn_l3_interface_class_id_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_bsn_l3_interface_class_id_masked_OF_VERSION_1_3(void)
{
    of_oxm_bsn_l3_interface_class_id_masked_t *obj;
    obj = of_oxm_bsn_l3_interface_class_id_masked_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_BSN_L3_INTERFACE_CLASS_ID_MASKED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_BSN_L3_INTERFACE_CLASS_ID_MASKED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_bsn_l3_interface_class_id_masked_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_bsn_l3_interface_class_id_masked_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_oxm_bsn_l3_interface_class_id_masked_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_bsn_l3_src_class_id_OF_VERSION_1_3(void)
{
    of_oxm_bsn_l3_src_class_id_t *obj;
    obj = of_oxm_bsn_l3_src_class_id_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_BSN_L3_SRC_CLASS_ID);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_BSN_L3_SRC_CLASS_ID);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_bsn_l3_src_class_id_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_bsn_l3_src_class_id_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_oxm_bsn_l3_src_class_id_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_bsn_l3_src_class_id_masked_OF_VERSION_1_3(void)
{
    of_oxm_bsn_l3_src_class_id_masked_t *obj;
    obj = of_oxm_bsn_l3_src_class_id_masked_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_BSN_L3_SRC_CLASS_ID_MASKED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_BSN_L3_SRC_CLASS_ID_MASKED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_bsn_l3_src_class_id_masked_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_bsn_l3_src_class_id_masked_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_oxm_bsn_l3_src_class_id_masked_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_bsn_lag_id_OF_VERSION_1_3(void)
{
    of_oxm_bsn_lag_id_t *obj;
    obj = of_oxm_bsn_lag_id_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_BSN_LAG_ID);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_BSN_LAG_ID);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_bsn_lag_id_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_bsn_lag_id_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_oxm_bsn_lag_id_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_bsn_lag_id_masked_OF_VERSION_1_3(void)
{
    of_oxm_bsn_lag_id_masked_t *obj;
    obj = of_oxm_bsn_lag_id_masked_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_BSN_LAG_ID_MASKED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_BSN_LAG_ID_MASKED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_bsn_lag_id_masked_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_bsn_lag_id_masked_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_oxm_bsn_lag_id_masked_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_bsn_vrf_OF_VERSION_1_3(void)
{
    of_oxm_bsn_vrf_t *obj;
    obj = of_oxm_bsn_vrf_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_BSN_VRF);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_BSN_VRF);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_bsn_vrf_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_bsn_vrf_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_oxm_bsn_vrf_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_bsn_vrf_masked_OF_VERSION_1_3(void)
{
    of_oxm_bsn_vrf_masked_t *obj;
    obj = of_oxm_bsn_vrf_masked_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_BSN_VRF_MASKED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_BSN_VRF_MASKED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_bsn_vrf_masked_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_bsn_vrf_masked_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_oxm_bsn_vrf_masked_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_eth_dst_OF_VERSION_1_3(void)
{
    of_oxm_eth_dst_t *obj;
    obj = of_oxm_eth_dst_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 10);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_ETH_DST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 10);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_ETH_DST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_eth_dst_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_eth_dst_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_oxm_eth_dst_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_eth_dst_masked_OF_VERSION_1_3(void)
{
    of_oxm_eth_dst_masked_t *obj;
    obj = of_oxm_eth_dst_masked_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_ETH_DST_MASKED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_ETH_DST_MASKED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_eth_dst_masked_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_eth_dst_masked_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_oxm_eth_dst_masked_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_eth_src_OF_VERSION_1_3(void)
{
    of_oxm_eth_src_t *obj;
    obj = of_oxm_eth_src_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 10);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_ETH_SRC);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 10);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_ETH_SRC);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_eth_src_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_eth_src_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_oxm_eth_src_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_eth_src_masked_OF_VERSION_1_3(void)
{
    of_oxm_eth_src_masked_t *obj;
    obj = of_oxm_eth_src_masked_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_ETH_SRC_MASKED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_ETH_SRC_MASKED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_eth_src_masked_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_eth_src_masked_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_oxm_eth_src_masked_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_eth_type_OF_VERSION_1_3(void)
{
    of_oxm_eth_type_t *obj;
    obj = of_oxm_eth_type_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 6);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_ETH_TYPE);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 6);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_ETH_TYPE);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_eth_type_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_eth_type_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_oxm_eth_type_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_eth_type_masked_OF_VERSION_1_3(void)
{
    of_oxm_eth_type_masked_t *obj;
    obj = of_oxm_eth_type_masked_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_ETH_TYPE_MASKED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_ETH_TYPE_MASKED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_eth_type_masked_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_eth_type_masked_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_oxm_eth_type_masked_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_header_OF_VERSION_1_3(void)
{
    of_oxm_header_t *obj;
    obj = of_oxm_header_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 4);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_HEADER);

    of_oxm_header_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_icmpv4_code_OF_VERSION_1_3(void)
{
    of_oxm_icmpv4_code_t *obj;
    obj = of_oxm_icmpv4_code_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 5);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_ICMPV4_CODE);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 5);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_ICMPV4_CODE);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_icmpv4_code_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_icmpv4_code_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_oxm_icmpv4_code_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_icmpv4_code_masked_OF_VERSION_1_3(void)
{
    of_oxm_icmpv4_code_masked_t *obj;
    obj = of_oxm_icmpv4_code_masked_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 6);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_ICMPV4_CODE_MASKED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 6);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_ICMPV4_CODE_MASKED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_icmpv4_code_masked_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_icmpv4_code_masked_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_oxm_icmpv4_code_masked_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_icmpv4_type_OF_VERSION_1_3(void)
{
    of_oxm_icmpv4_type_t *obj;
    obj = of_oxm_icmpv4_type_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 5);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_ICMPV4_TYPE);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 5);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_ICMPV4_TYPE);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_icmpv4_type_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_icmpv4_type_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_oxm_icmpv4_type_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_icmpv4_type_masked_OF_VERSION_1_3(void)
{
    of_oxm_icmpv4_type_masked_t *obj;
    obj = of_oxm_icmpv4_type_masked_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 6);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_ICMPV4_TYPE_MASKED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 6);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_ICMPV4_TYPE_MASKED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_icmpv4_type_masked_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_icmpv4_type_masked_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_oxm_icmpv4_type_masked_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_icmpv6_code_OF_VERSION_1_3(void)
{
    of_oxm_icmpv6_code_t *obj;
    obj = of_oxm_icmpv6_code_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 5);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_ICMPV6_CODE);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 5);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_ICMPV6_CODE);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_icmpv6_code_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_icmpv6_code_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_oxm_icmpv6_code_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_icmpv6_code_masked_OF_VERSION_1_3(void)
{
    of_oxm_icmpv6_code_masked_t *obj;
    obj = of_oxm_icmpv6_code_masked_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 6);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_ICMPV6_CODE_MASKED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 6);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_ICMPV6_CODE_MASKED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_icmpv6_code_masked_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_icmpv6_code_masked_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_oxm_icmpv6_code_masked_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_icmpv6_type_OF_VERSION_1_3(void)
{
    of_oxm_icmpv6_type_t *obj;
    obj = of_oxm_icmpv6_type_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 5);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_ICMPV6_TYPE);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 5);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_ICMPV6_TYPE);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_icmpv6_type_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_icmpv6_type_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_oxm_icmpv6_type_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_icmpv6_type_masked_OF_VERSION_1_3(void)
{
    of_oxm_icmpv6_type_masked_t *obj;
    obj = of_oxm_icmpv6_type_masked_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 6);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_ICMPV6_TYPE_MASKED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 6);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_ICMPV6_TYPE_MASKED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_icmpv6_type_masked_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_icmpv6_type_masked_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_oxm_icmpv6_type_masked_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_in_phy_port_OF_VERSION_1_3(void)
{
    of_oxm_in_phy_port_t *obj;
    obj = of_oxm_in_phy_port_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_IN_PHY_PORT);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_IN_PHY_PORT);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_in_phy_port_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_in_phy_port_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_oxm_in_phy_port_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_in_phy_port_masked_OF_VERSION_1_3(void)
{
    of_oxm_in_phy_port_masked_t *obj;
    obj = of_oxm_in_phy_port_masked_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_IN_PHY_PORT_MASKED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_IN_PHY_PORT_MASKED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_in_phy_port_masked_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_in_phy_port_masked_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_oxm_in_phy_port_masked_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_in_port_OF_VERSION_1_3(void)
{
    of_oxm_in_port_t *obj;
    obj = of_oxm_in_port_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_IN_PORT);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_IN_PORT);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_in_port_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_in_port_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_oxm_in_port_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_in_port_masked_OF_VERSION_1_3(void)
{
    of_oxm_in_port_masked_t *obj;
    obj = of_oxm_in_port_masked_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_IN_PORT_MASKED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_IN_PORT_MASKED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_in_port_masked_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_in_port_masked_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_oxm_in_port_masked_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_ip_dscp_OF_VERSION_1_3(void)
{
    of_oxm_ip_dscp_t *obj;
    obj = of_oxm_ip_dscp_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 5);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_IP_DSCP);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 5);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_IP_DSCP);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_ip_dscp_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_ip_dscp_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_oxm_ip_dscp_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_ip_dscp_masked_OF_VERSION_1_3(void)
{
    of_oxm_ip_dscp_masked_t *obj;
    obj = of_oxm_ip_dscp_masked_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 6);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_IP_DSCP_MASKED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 6);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_IP_DSCP_MASKED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_ip_dscp_masked_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_ip_dscp_masked_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_oxm_ip_dscp_masked_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_ip_ecn_OF_VERSION_1_3(void)
{
    of_oxm_ip_ecn_t *obj;
    obj = of_oxm_ip_ecn_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 5);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_IP_ECN);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 5);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_IP_ECN);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_ip_ecn_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_ip_ecn_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_oxm_ip_ecn_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_ip_ecn_masked_OF_VERSION_1_3(void)
{
    of_oxm_ip_ecn_masked_t *obj;
    obj = of_oxm_ip_ecn_masked_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 6);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_IP_ECN_MASKED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 6);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_IP_ECN_MASKED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_ip_ecn_masked_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_ip_ecn_masked_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_oxm_ip_ecn_masked_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_ip_proto_OF_VERSION_1_3(void)
{
    of_oxm_ip_proto_t *obj;
    obj = of_oxm_ip_proto_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 5);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_IP_PROTO);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 5);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_IP_PROTO);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_ip_proto_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_ip_proto_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_oxm_ip_proto_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_ip_proto_masked_OF_VERSION_1_3(void)
{
    of_oxm_ip_proto_masked_t *obj;
    obj = of_oxm_ip_proto_masked_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 6);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_IP_PROTO_MASKED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 6);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_IP_PROTO_MASKED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_ip_proto_masked_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_ip_proto_masked_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_oxm_ip_proto_masked_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_ipv4_dst_OF_VERSION_1_3(void)
{
    of_oxm_ipv4_dst_t *obj;
    obj = of_oxm_ipv4_dst_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_IPV4_DST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_IPV4_DST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_ipv4_dst_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_ipv4_dst_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_oxm_ipv4_dst_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_ipv4_dst_masked_OF_VERSION_1_3(void)
{
    of_oxm_ipv4_dst_masked_t *obj;
    obj = of_oxm_ipv4_dst_masked_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_IPV4_DST_MASKED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_IPV4_DST_MASKED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_ipv4_dst_masked_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_ipv4_dst_masked_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_oxm_ipv4_dst_masked_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_ipv4_src_OF_VERSION_1_3(void)
{
    of_oxm_ipv4_src_t *obj;
    obj = of_oxm_ipv4_src_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_IPV4_SRC);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_IPV4_SRC);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_ipv4_src_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_ipv4_src_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_oxm_ipv4_src_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_ipv4_src_masked_OF_VERSION_1_3(void)
{
    of_oxm_ipv4_src_masked_t *obj;
    obj = of_oxm_ipv4_src_masked_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_IPV4_SRC_MASKED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_IPV4_SRC_MASKED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_ipv4_src_masked_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_ipv4_src_masked_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_oxm_ipv4_src_masked_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_ipv6_dst_OF_VERSION_1_3(void)
{
    of_oxm_ipv6_dst_t *obj;
    obj = of_oxm_ipv6_dst_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_IPV6_DST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 20);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_IPV6_DST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_ipv6_dst_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_ipv6_dst_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_oxm_ipv6_dst_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_ipv6_dst_masked_OF_VERSION_1_3(void)
{
    of_oxm_ipv6_dst_masked_t *obj;
    obj = of_oxm_ipv6_dst_masked_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 36);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_IPV6_DST_MASKED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 36);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_IPV6_DST_MASKED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_ipv6_dst_masked_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_ipv6_dst_masked_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_oxm_ipv6_dst_masked_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_ipv6_flabel_OF_VERSION_1_3(void)
{
    of_oxm_ipv6_flabel_t *obj;
    obj = of_oxm_ipv6_flabel_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_IPV6_FLABEL);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_IPV6_FLABEL);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_ipv6_flabel_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_ipv6_flabel_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_oxm_ipv6_flabel_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_ipv6_flabel_masked_OF_VERSION_1_3(void)
{
    of_oxm_ipv6_flabel_masked_t *obj;
    obj = of_oxm_ipv6_flabel_masked_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_IPV6_FLABEL_MASKED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_IPV6_FLABEL_MASKED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_ipv6_flabel_masked_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_ipv6_flabel_masked_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_oxm_ipv6_flabel_masked_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_ipv6_nd_sll_OF_VERSION_1_3(void)
{
    of_oxm_ipv6_nd_sll_t *obj;
    obj = of_oxm_ipv6_nd_sll_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 10);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_IPV6_ND_SLL);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 10);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_IPV6_ND_SLL);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_ipv6_nd_sll_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_ipv6_nd_sll_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_oxm_ipv6_nd_sll_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_ipv6_nd_sll_masked_OF_VERSION_1_3(void)
{
    of_oxm_ipv6_nd_sll_masked_t *obj;
    obj = of_oxm_ipv6_nd_sll_masked_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_IPV6_ND_SLL_MASKED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_IPV6_ND_SLL_MASKED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_ipv6_nd_sll_masked_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_ipv6_nd_sll_masked_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_oxm_ipv6_nd_sll_masked_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_ipv6_nd_target_OF_VERSION_1_3(void)
{
    of_oxm_ipv6_nd_target_t *obj;
    obj = of_oxm_ipv6_nd_target_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_IPV6_ND_TARGET);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 20);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_IPV6_ND_TARGET);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_ipv6_nd_target_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_ipv6_nd_target_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_oxm_ipv6_nd_target_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_ipv6_nd_target_masked_OF_VERSION_1_3(void)
{
    of_oxm_ipv6_nd_target_masked_t *obj;
    obj = of_oxm_ipv6_nd_target_masked_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 36);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_IPV6_ND_TARGET_MASKED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 36);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_IPV6_ND_TARGET_MASKED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_ipv6_nd_target_masked_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_ipv6_nd_target_masked_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_oxm_ipv6_nd_target_masked_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_ipv6_nd_tll_OF_VERSION_1_3(void)
{
    of_oxm_ipv6_nd_tll_t *obj;
    obj = of_oxm_ipv6_nd_tll_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 10);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_IPV6_ND_TLL);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 10);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_IPV6_ND_TLL);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_ipv6_nd_tll_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_ipv6_nd_tll_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_oxm_ipv6_nd_tll_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_ipv6_nd_tll_masked_OF_VERSION_1_3(void)
{
    of_oxm_ipv6_nd_tll_masked_t *obj;
    obj = of_oxm_ipv6_nd_tll_masked_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_IPV6_ND_TLL_MASKED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_IPV6_ND_TLL_MASKED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_ipv6_nd_tll_masked_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_ipv6_nd_tll_masked_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_oxm_ipv6_nd_tll_masked_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_ipv6_src_OF_VERSION_1_3(void)
{
    of_oxm_ipv6_src_t *obj;
    obj = of_oxm_ipv6_src_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_IPV6_SRC);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 20);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_IPV6_SRC);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_ipv6_src_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_ipv6_src_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_oxm_ipv6_src_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_ipv6_src_masked_OF_VERSION_1_3(void)
{
    of_oxm_ipv6_src_masked_t *obj;
    obj = of_oxm_ipv6_src_masked_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 36);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_IPV6_SRC_MASKED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 36);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_IPV6_SRC_MASKED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_ipv6_src_masked_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_ipv6_src_masked_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_oxm_ipv6_src_masked_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_metadata_OF_VERSION_1_3(void)
{
    of_oxm_metadata_t *obj;
    obj = of_oxm_metadata_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_METADATA);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_METADATA);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_metadata_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_metadata_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_oxm_metadata_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_metadata_masked_OF_VERSION_1_3(void)
{
    of_oxm_metadata_masked_t *obj;
    obj = of_oxm_metadata_masked_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_METADATA_MASKED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 20);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_METADATA_MASKED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_metadata_masked_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_metadata_masked_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_oxm_metadata_masked_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_mpls_label_OF_VERSION_1_3(void)
{
    of_oxm_mpls_label_t *obj;
    obj = of_oxm_mpls_label_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_MPLS_LABEL);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_MPLS_LABEL);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_mpls_label_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_mpls_label_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_oxm_mpls_label_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_mpls_label_masked_OF_VERSION_1_3(void)
{
    of_oxm_mpls_label_masked_t *obj;
    obj = of_oxm_mpls_label_masked_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_MPLS_LABEL_MASKED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_MPLS_LABEL_MASKED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_mpls_label_masked_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_mpls_label_masked_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_oxm_mpls_label_masked_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_mpls_tc_OF_VERSION_1_3(void)
{
    of_oxm_mpls_tc_t *obj;
    obj = of_oxm_mpls_tc_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 5);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_MPLS_TC);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 5);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_MPLS_TC);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_mpls_tc_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_mpls_tc_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_oxm_mpls_tc_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_mpls_tc_masked_OF_VERSION_1_3(void)
{
    of_oxm_mpls_tc_masked_t *obj;
    obj = of_oxm_mpls_tc_masked_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 6);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_MPLS_TC_MASKED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 6);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_MPLS_TC_MASKED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_mpls_tc_masked_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_mpls_tc_masked_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_oxm_mpls_tc_masked_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_sctp_dst_OF_VERSION_1_3(void)
{
    of_oxm_sctp_dst_t *obj;
    obj = of_oxm_sctp_dst_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 6);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_SCTP_DST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 6);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_SCTP_DST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_sctp_dst_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_sctp_dst_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_oxm_sctp_dst_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_sctp_dst_masked_OF_VERSION_1_3(void)
{
    of_oxm_sctp_dst_masked_t *obj;
    obj = of_oxm_sctp_dst_masked_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_SCTP_DST_MASKED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_SCTP_DST_MASKED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_sctp_dst_masked_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_sctp_dst_masked_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_oxm_sctp_dst_masked_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_sctp_src_OF_VERSION_1_3(void)
{
    of_oxm_sctp_src_t *obj;
    obj = of_oxm_sctp_src_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 6);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_SCTP_SRC);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 6);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_SCTP_SRC);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_sctp_src_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_sctp_src_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_oxm_sctp_src_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_sctp_src_masked_OF_VERSION_1_3(void)
{
    of_oxm_sctp_src_masked_t *obj;
    obj = of_oxm_sctp_src_masked_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_SCTP_SRC_MASKED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_SCTP_SRC_MASKED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_sctp_src_masked_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_sctp_src_masked_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_oxm_sctp_src_masked_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_tcp_dst_OF_VERSION_1_3(void)
{
    of_oxm_tcp_dst_t *obj;
    obj = of_oxm_tcp_dst_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 6);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_TCP_DST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 6);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_TCP_DST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_tcp_dst_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_tcp_dst_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_oxm_tcp_dst_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_tcp_dst_masked_OF_VERSION_1_3(void)
{
    of_oxm_tcp_dst_masked_t *obj;
    obj = of_oxm_tcp_dst_masked_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_TCP_DST_MASKED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_TCP_DST_MASKED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_tcp_dst_masked_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_tcp_dst_masked_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_oxm_tcp_dst_masked_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_tcp_src_OF_VERSION_1_3(void)
{
    of_oxm_tcp_src_t *obj;
    obj = of_oxm_tcp_src_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 6);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_TCP_SRC);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 6);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_TCP_SRC);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_tcp_src_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_tcp_src_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_oxm_tcp_src_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_tcp_src_masked_OF_VERSION_1_3(void)
{
    of_oxm_tcp_src_masked_t *obj;
    obj = of_oxm_tcp_src_masked_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_TCP_SRC_MASKED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_TCP_SRC_MASKED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_tcp_src_masked_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_tcp_src_masked_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_oxm_tcp_src_masked_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_udp_dst_OF_VERSION_1_3(void)
{
    of_oxm_udp_dst_t *obj;
    obj = of_oxm_udp_dst_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 6);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_UDP_DST);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 6);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_UDP_DST);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_udp_dst_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_udp_dst_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_oxm_udp_dst_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_udp_dst_masked_OF_VERSION_1_3(void)
{
    of_oxm_udp_dst_masked_t *obj;
    obj = of_oxm_udp_dst_masked_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_UDP_DST_MASKED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_UDP_DST_MASKED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_udp_dst_masked_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_udp_dst_masked_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_oxm_udp_dst_masked_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_udp_src_OF_VERSION_1_3(void)
{
    of_oxm_udp_src_t *obj;
    obj = of_oxm_udp_src_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 6);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_UDP_SRC);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 6);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_UDP_SRC);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_udp_src_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_udp_src_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_oxm_udp_src_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_udp_src_masked_OF_VERSION_1_3(void)
{
    of_oxm_udp_src_masked_t *obj;
    obj = of_oxm_udp_src_masked_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_UDP_SRC_MASKED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_UDP_SRC_MASKED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_udp_src_masked_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_udp_src_masked_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_oxm_udp_src_masked_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_vlan_pcp_OF_VERSION_1_3(void)
{
    of_oxm_vlan_pcp_t *obj;
    obj = of_oxm_vlan_pcp_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 5);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_VLAN_PCP);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 5);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_VLAN_PCP);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_vlan_pcp_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_vlan_pcp_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_oxm_vlan_pcp_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_vlan_pcp_masked_OF_VERSION_1_3(void)
{
    of_oxm_vlan_pcp_masked_t *obj;
    obj = of_oxm_vlan_pcp_masked_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 6);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_VLAN_PCP_MASKED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 6);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_VLAN_PCP_MASKED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_vlan_pcp_masked_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_vlan_pcp_masked_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_oxm_vlan_pcp_masked_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_vlan_vid_OF_VERSION_1_3(void)
{
    of_oxm_vlan_vid_t *obj;
    obj = of_oxm_vlan_vid_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 6);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_VLAN_VID);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 6);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_VLAN_VID);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_vlan_vid_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_vlan_vid_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_oxm_vlan_vid_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_oxm_vlan_vid_masked_OF_VERSION_1_3(void)
{
    of_oxm_vlan_vid_masked_t *obj;
    obj = of_oxm_vlan_vid_masked_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_OXM_VLAN_VID_MASKED);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 8);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_OXM_VLAN_VID_MASKED);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_oxm_vlan_vid_masked_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_oxm_vlan_vid_masked_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_oxm_vlan_vid_masked_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_packet_queue_OF_VERSION_1_3(void)
{
    of_packet_queue_t *obj;
    obj = of_packet_queue_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_PACKET_QUEUE);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_PACKET_QUEUE);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_packet_queue_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_packet_queue_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_packet_queue_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_port_desc_OF_VERSION_1_3(void)
{
    of_port_desc_t *obj;
    obj = of_port_desc_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 64);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_PORT_DESC);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 64);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_PORT_DESC);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_port_desc_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_port_desc_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_port_desc_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_port_stats_entry_OF_VERSION_1_3(void)
{
    of_port_stats_entry_t *obj;
    obj = of_port_stats_entry_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 112);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_PORT_STATS_ENTRY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 112);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_PORT_STATS_ENTRY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_port_stats_entry_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_port_stats_entry_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_port_stats_entry_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_queue_prop_experimenter_OF_VERSION_1_3(void)
{
    of_queue_prop_experimenter_t *obj;
    obj = of_queue_prop_experimenter_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_QUEUE_PROP_EXPERIMENTER);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_QUEUE_PROP_EXPERIMENTER);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_queue_prop_experimenter_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_queue_prop_experimenter_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_queue_prop_experimenter_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_queue_prop_header_OF_VERSION_1_3(void)
{
    of_queue_prop_header_t *obj;
    obj = of_queue_prop_header_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_QUEUE_PROP_HEADER);

    of_queue_prop_header_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_queue_prop_max_rate_OF_VERSION_1_3(void)
{
    of_queue_prop_max_rate_t *obj;
    obj = of_queue_prop_max_rate_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_QUEUE_PROP_MAX_RATE);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_QUEUE_PROP_MAX_RATE);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_queue_prop_max_rate_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_queue_prop_max_rate_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_queue_prop_max_rate_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_queue_prop_min_rate_OF_VERSION_1_3(void)
{
    of_queue_prop_min_rate_t *obj;
    obj = of_queue_prop_min_rate_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_QUEUE_PROP_MIN_RATE);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 16);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_QUEUE_PROP_MIN_RATE);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_queue_prop_min_rate_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_queue_prop_min_rate_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_queue_prop_min_rate_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_queue_stats_entry_OF_VERSION_1_3(void)
{
    of_queue_stats_entry_t *obj;
    obj = of_queue_stats_entry_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 40);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_QUEUE_STATS_ENTRY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 40);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_QUEUE_STATS_ENTRY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_queue_stats_entry_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_queue_stats_entry_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_queue_stats_entry_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_table_feature_prop_apply_actions_OF_VERSION_1_3(void)
{
    of_table_feature_prop_apply_actions_t *obj;
    obj = of_table_feature_prop_apply_actions_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 4);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_TABLE_FEATURE_PROP_APPLY_ACTIONS);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 4);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_TABLE_FEATURE_PROP_APPLY_ACTIONS);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_table_feature_prop_apply_actions_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_table_feature_prop_apply_actions_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_table_feature_prop_apply_actions_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_table_feature_prop_apply_actions_miss_OF_VERSION_1_3(void)
{
    of_table_feature_prop_apply_actions_miss_t *obj;
    obj = of_table_feature_prop_apply_actions_miss_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 4);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_TABLE_FEATURE_PROP_APPLY_ACTIONS_MISS);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 4);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_TABLE_FEATURE_PROP_APPLY_ACTIONS_MISS);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_table_feature_prop_apply_actions_miss_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_table_feature_prop_apply_actions_miss_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_table_feature_prop_apply_actions_miss_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_table_feature_prop_apply_setfield_OF_VERSION_1_3(void)
{
    of_table_feature_prop_apply_setfield_t *obj;
    obj = of_table_feature_prop_apply_setfield_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 4);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_TABLE_FEATURE_PROP_APPLY_SETFIELD);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 4);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_TABLE_FEATURE_PROP_APPLY_SETFIELD);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_table_feature_prop_apply_setfield_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_table_feature_prop_apply_setfield_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_table_feature_prop_apply_setfield_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_table_feature_prop_apply_setfield_miss_OF_VERSION_1_3(void)
{
    of_table_feature_prop_apply_setfield_miss_t *obj;
    obj = of_table_feature_prop_apply_setfield_miss_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 4);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_TABLE_FEATURE_PROP_APPLY_SETFIELD_MISS);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 4);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_TABLE_FEATURE_PROP_APPLY_SETFIELD_MISS);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_table_feature_prop_apply_setfield_miss_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_table_feature_prop_apply_setfield_miss_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_table_feature_prop_apply_setfield_miss_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_table_feature_prop_experimenter_OF_VERSION_1_3(void)
{
    of_table_feature_prop_experimenter_t *obj;
    obj = of_table_feature_prop_experimenter_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_TABLE_FEATURE_PROP_EXPERIMENTER);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 12);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_TABLE_FEATURE_PROP_EXPERIMENTER);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_table_feature_prop_experimenter_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_table_feature_prop_experimenter_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_table_feature_prop_experimenter_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_table_feature_prop_header_OF_VERSION_1_3(void)
{
    of_table_feature_prop_header_t *obj;
    obj = of_table_feature_prop_header_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 4);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_TABLE_FEATURE_PROP_HEADER);

    of_table_feature_prop_header_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_table_feature_prop_instructions_OF_VERSION_1_3(void)
{
    of_table_feature_prop_instructions_t *obj;
    obj = of_table_feature_prop_instructions_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 4);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_TABLE_FEATURE_PROP_INSTRUCTIONS);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 4);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_TABLE_FEATURE_PROP_INSTRUCTIONS);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_table_feature_prop_instructions_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_table_feature_prop_instructions_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_table_feature_prop_instructions_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_table_feature_prop_instructions_miss_OF_VERSION_1_3(void)
{
    of_table_feature_prop_instructions_miss_t *obj;
    obj = of_table_feature_prop_instructions_miss_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 4);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_TABLE_FEATURE_PROP_INSTRUCTIONS_MISS);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 4);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_TABLE_FEATURE_PROP_INSTRUCTIONS_MISS);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_table_feature_prop_instructions_miss_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_table_feature_prop_instructions_miss_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_table_feature_prop_instructions_miss_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_table_feature_prop_match_OF_VERSION_1_3(void)
{
    of_table_feature_prop_match_t *obj;
    obj = of_table_feature_prop_match_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 4);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_TABLE_FEATURE_PROP_MATCH);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 4);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_TABLE_FEATURE_PROP_MATCH);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_table_feature_prop_match_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_table_feature_prop_match_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_table_feature_prop_match_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_table_feature_prop_next_tables_OF_VERSION_1_3(void)
{
    of_table_feature_prop_next_tables_t *obj;
    obj = of_table_feature_prop_next_tables_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 4);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_TABLE_FEATURE_PROP_NEXT_TABLES);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 4);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_TABLE_FEATURE_PROP_NEXT_TABLES);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_table_feature_prop_next_tables_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_table_feature_prop_next_tables_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_table_feature_prop_next_tables_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_table_feature_prop_next_tables_miss_OF_VERSION_1_3(void)
{
    of_table_feature_prop_next_tables_miss_t *obj;
    obj = of_table_feature_prop_next_tables_miss_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 4);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_TABLE_FEATURE_PROP_NEXT_TABLES_MISS);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 4);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_TABLE_FEATURE_PROP_NEXT_TABLES_MISS);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_table_feature_prop_next_tables_miss_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_table_feature_prop_next_tables_miss_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_table_feature_prop_next_tables_miss_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_table_feature_prop_wildcards_OF_VERSION_1_3(void)
{
    of_table_feature_prop_wildcards_t *obj;
    obj = of_table_feature_prop_wildcards_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 4);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_TABLE_FEATURE_PROP_WILDCARDS);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 4);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_TABLE_FEATURE_PROP_WILDCARDS);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_table_feature_prop_wildcards_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_table_feature_prop_wildcards_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_table_feature_prop_wildcards_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_table_feature_prop_write_actions_OF_VERSION_1_3(void)
{
    of_table_feature_prop_write_actions_t *obj;
    obj = of_table_feature_prop_write_actions_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 4);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_TABLE_FEATURE_PROP_WRITE_ACTIONS);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 4);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_TABLE_FEATURE_PROP_WRITE_ACTIONS);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_table_feature_prop_write_actions_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_table_feature_prop_write_actions_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_table_feature_prop_write_actions_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_table_feature_prop_write_actions_miss_OF_VERSION_1_3(void)
{
    of_table_feature_prop_write_actions_miss_t *obj;
    obj = of_table_feature_prop_write_actions_miss_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 4);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_TABLE_FEATURE_PROP_WRITE_ACTIONS_MISS);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 4);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_TABLE_FEATURE_PROP_WRITE_ACTIONS_MISS);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_table_feature_prop_write_actions_miss_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_table_feature_prop_write_actions_miss_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_table_feature_prop_write_actions_miss_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_table_feature_prop_write_setfield_OF_VERSION_1_3(void)
{
    of_table_feature_prop_write_setfield_t *obj;
    obj = of_table_feature_prop_write_setfield_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 4);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_TABLE_FEATURE_PROP_WRITE_SETFIELD);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 4);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_TABLE_FEATURE_PROP_WRITE_SETFIELD);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_table_feature_prop_write_setfield_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_table_feature_prop_write_setfield_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_table_feature_prop_write_setfield_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_table_feature_prop_write_setfield_miss_OF_VERSION_1_3(void)
{
    of_table_feature_prop_write_setfield_miss_t *obj;
    obj = of_table_feature_prop_write_setfield_miss_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 4);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_TABLE_FEATURE_PROP_WRITE_SETFIELD_MISS);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 4);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_TABLE_FEATURE_PROP_WRITE_SETFIELD_MISS);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_table_feature_prop_write_setfield_miss_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_table_feature_prop_write_setfield_miss_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_table_feature_prop_write_setfield_miss_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_table_features_OF_VERSION_1_3(void)
{
    of_table_features_t *obj;
    obj = of_table_features_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 64);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_TABLE_FEATURES);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 64);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_TABLE_FEATURES);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_table_features_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_table_features_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_table_features_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_table_stats_entry_OF_VERSION_1_3(void)
{
    of_table_stats_entry_t *obj;
    obj = of_table_stats_entry_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_TABLE_STATS_ENTRY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 24);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_TABLE_STATS_ENTRY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_table_stats_entry_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_table_stats_entry_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_table_stats_entry_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_uint32_OF_VERSION_1_3(void)
{
    of_uint32_t *obj;
    obj = of_uint32_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 4);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_UINT32);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 4);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_UINT32);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_uint32_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_uint32_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_uint32_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_uint8_OF_VERSION_1_3(void)
{
    of_uint8_t *obj;
    obj = of_uint8_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 1);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_UINT8);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 1);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_UINT8);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_uint8_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_uint8_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_uint8_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_list_action_OF_VERSION_1_3(void)
{
    of_list_action_t *obj;
    obj = of_list_action_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 0);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_LIST_ACTION);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 0);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_LIST_ACTION);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_list_action_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_list_action_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_list_action_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_list_action_id_OF_VERSION_1_3(void)
{
    of_list_action_id_t *obj;
    obj = of_list_action_id_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 0);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_LIST_ACTION_ID);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 0);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_LIST_ACTION_ID);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_list_action_id_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_list_action_id_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_list_action_id_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_list_bsn_interface_OF_VERSION_1_3(void)
{
    of_list_bsn_interface_t *obj;
    obj = of_list_bsn_interface_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 0);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_LIST_BSN_INTERFACE);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 0);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_LIST_BSN_INTERFACE);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_list_bsn_interface_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_list_bsn_interface_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_list_bsn_interface_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_list_bsn_lacp_stats_entry_OF_VERSION_1_3(void)
{
    of_list_bsn_lacp_stats_entry_t *obj;
    obj = of_list_bsn_lacp_stats_entry_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 0);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_LIST_BSN_LACP_STATS_ENTRY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 0);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_LIST_BSN_LACP_STATS_ENTRY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_list_bsn_lacp_stats_entry_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_list_bsn_lacp_stats_entry_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_list_bsn_lacp_stats_entry_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_list_bucket_OF_VERSION_1_3(void)
{
    of_list_bucket_t *obj;
    obj = of_list_bucket_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 0);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_LIST_BUCKET);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 0);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_LIST_BUCKET);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_list_bucket_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_list_bucket_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_list_bucket_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_list_bucket_counter_OF_VERSION_1_3(void)
{
    of_list_bucket_counter_t *obj;
    obj = of_list_bucket_counter_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 0);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_LIST_BUCKET_COUNTER);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 0);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_LIST_BUCKET_COUNTER);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_list_bucket_counter_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_list_bucket_counter_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_list_bucket_counter_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_list_flow_stats_entry_OF_VERSION_1_3(void)
{
    of_list_flow_stats_entry_t *obj;
    obj = of_list_flow_stats_entry_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 0);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_LIST_FLOW_STATS_ENTRY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 0);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_LIST_FLOW_STATS_ENTRY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_list_flow_stats_entry_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_list_flow_stats_entry_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_list_flow_stats_entry_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_list_group_desc_stats_entry_OF_VERSION_1_3(void)
{
    of_list_group_desc_stats_entry_t *obj;
    obj = of_list_group_desc_stats_entry_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 0);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_LIST_GROUP_DESC_STATS_ENTRY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 0);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_LIST_GROUP_DESC_STATS_ENTRY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_list_group_desc_stats_entry_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_list_group_desc_stats_entry_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_list_group_desc_stats_entry_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_list_group_stats_entry_OF_VERSION_1_3(void)
{
    of_list_group_stats_entry_t *obj;
    obj = of_list_group_stats_entry_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 0);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_LIST_GROUP_STATS_ENTRY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 0);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_LIST_GROUP_STATS_ENTRY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_list_group_stats_entry_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_list_group_stats_entry_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_list_group_stats_entry_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_list_hello_elem_OF_VERSION_1_3(void)
{
    of_list_hello_elem_t *obj;
    obj = of_list_hello_elem_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 0);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_LIST_HELLO_ELEM);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 0);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_LIST_HELLO_ELEM);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_list_hello_elem_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_list_hello_elem_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_list_hello_elem_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_list_instruction_OF_VERSION_1_3(void)
{
    of_list_instruction_t *obj;
    obj = of_list_instruction_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 0);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_LIST_INSTRUCTION);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 0);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_LIST_INSTRUCTION);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_list_instruction_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_list_instruction_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_list_instruction_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_list_meter_band_OF_VERSION_1_3(void)
{
    of_list_meter_band_t *obj;
    obj = of_list_meter_band_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 0);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_LIST_METER_BAND);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 0);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_LIST_METER_BAND);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_list_meter_band_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_list_meter_band_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_list_meter_band_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_list_meter_band_stats_OF_VERSION_1_3(void)
{
    of_list_meter_band_stats_t *obj;
    obj = of_list_meter_band_stats_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 0);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_LIST_METER_BAND_STATS);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 0);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_LIST_METER_BAND_STATS);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_list_meter_band_stats_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_list_meter_band_stats_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_list_meter_band_stats_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_list_meter_stats_OF_VERSION_1_3(void)
{
    of_list_meter_stats_t *obj;
    obj = of_list_meter_stats_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 0);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_LIST_METER_STATS);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 0);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_LIST_METER_STATS);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_list_meter_stats_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_list_meter_stats_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_list_meter_stats_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_list_oxm_OF_VERSION_1_3(void)
{
    of_list_oxm_t *obj;
    obj = of_list_oxm_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 0);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_LIST_OXM);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 0);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_LIST_OXM);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_list_oxm_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_list_oxm_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_list_oxm_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_list_packet_queue_OF_VERSION_1_3(void)
{
    of_list_packet_queue_t *obj;
    obj = of_list_packet_queue_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 0);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_LIST_PACKET_QUEUE);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 0);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_LIST_PACKET_QUEUE);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_list_packet_queue_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_list_packet_queue_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_list_packet_queue_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_list_port_desc_OF_VERSION_1_3(void)
{
    of_list_port_desc_t *obj;
    obj = of_list_port_desc_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 0);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_LIST_PORT_DESC);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 0);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_LIST_PORT_DESC);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_list_port_desc_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_list_port_desc_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_list_port_desc_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_list_port_stats_entry_OF_VERSION_1_3(void)
{
    of_list_port_stats_entry_t *obj;
    obj = of_list_port_stats_entry_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 0);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_LIST_PORT_STATS_ENTRY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 0);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_LIST_PORT_STATS_ENTRY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_list_port_stats_entry_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_list_port_stats_entry_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_list_port_stats_entry_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_list_queue_prop_OF_VERSION_1_3(void)
{
    of_list_queue_prop_t *obj;
    obj = of_list_queue_prop_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 0);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_LIST_QUEUE_PROP);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 0);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_LIST_QUEUE_PROP);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_list_queue_prop_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_list_queue_prop_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_list_queue_prop_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_list_queue_stats_entry_OF_VERSION_1_3(void)
{
    of_list_queue_stats_entry_t *obj;
    obj = of_list_queue_stats_entry_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 0);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_LIST_QUEUE_STATS_ENTRY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 0);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_LIST_QUEUE_STATS_ENTRY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_list_queue_stats_entry_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_list_queue_stats_entry_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_list_queue_stats_entry_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_list_table_feature_prop_OF_VERSION_1_3(void)
{
    of_list_table_feature_prop_t *obj;
    obj = of_list_table_feature_prop_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 0);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_LIST_TABLE_FEATURE_PROP);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 0);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_LIST_TABLE_FEATURE_PROP);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_list_table_feature_prop_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_list_table_feature_prop_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_list_table_feature_prop_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_list_table_features_OF_VERSION_1_3(void)
{
    of_list_table_features_t *obj;
    obj = of_list_table_features_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 0);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_LIST_TABLE_FEATURES);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 0);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_LIST_TABLE_FEATURES);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_list_table_features_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_list_table_features_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_list_table_features_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_list_table_stats_entry_OF_VERSION_1_3(void)
{
    of_list_table_stats_entry_t *obj;
    obj = of_list_table_stats_entry_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 0);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_LIST_TABLE_STATS_ENTRY);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 0);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_LIST_TABLE_STATS_ENTRY);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_list_table_stats_entry_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_list_table_stats_entry_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_list_table_stats_entry_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_list_uint32_OF_VERSION_1_3(void)
{
    of_list_uint32_t *obj;
    obj = of_list_uint32_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 0);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_LIST_UINT32);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 0);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_LIST_UINT32);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_list_uint32_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_list_uint32_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_list_uint32_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

static int
test_of_list_uint8_OF_VERSION_1_3(void)
{
    of_list_uint8_t *obj;
    obj = of_list_uint8_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 0);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_LIST_UINT8);

    if (obj->wire_length_get != NULL) {
        int length;

        obj->wire_length_get((of_object_t *)obj, &length);
        TEST_ASSERT(length == 0);
    }
    if (obj->wire_type_get != NULL) {
        of_object_id_t obj_id;

        obj->wire_type_get((of_object_t *)obj, &obj_id);
        TEST_ASSERT(obj_id == OF_LIST_UINT8);
    }

    /* Set up incrementing values for members */
    TEST_ASSERT(of_list_uint8_OF_VERSION_1_3_populate(
        obj, 1) != 0);

    /* Check values just set */
    TEST_ASSERT(of_list_uint8_OF_VERSION_1_3_check(
        obj, 1) != 0);

    of_list_uint8_delete(obj);

    /* To do: Check memory */
    return TEST_PASS;
}

int
run_unified_accessor_tests(void)
{
    RUN_TEST(of_aggregate_stats_reply_OF_VERSION_1_0);
    RUN_TEST(of_aggregate_stats_request_OF_VERSION_1_0);
    RUN_TEST(of_bad_action_error_msg_OF_VERSION_1_0);
    RUN_TEST(of_bad_request_error_msg_OF_VERSION_1_0);
    RUN_TEST(of_barrier_reply_OF_VERSION_1_0);
    RUN_TEST(of_barrier_request_OF_VERSION_1_0);
    RUN_TEST(of_bsn_bw_clear_data_reply_OF_VERSION_1_0);
    RUN_TEST(of_bsn_bw_clear_data_request_OF_VERSION_1_0);
    RUN_TEST(of_bsn_bw_enable_get_reply_OF_VERSION_1_0);
    RUN_TEST(of_bsn_bw_enable_get_request_OF_VERSION_1_0);
    RUN_TEST(of_bsn_bw_enable_set_reply_OF_VERSION_1_0);
    RUN_TEST(of_bsn_bw_enable_set_request_OF_VERSION_1_0);
    RUN_TEST(of_bsn_get_interfaces_reply_OF_VERSION_1_0);
    RUN_TEST(of_bsn_get_interfaces_request_OF_VERSION_1_0);
    RUN_TEST(of_bsn_get_ip_mask_reply_OF_VERSION_1_0);
    RUN_TEST(of_bsn_get_ip_mask_request_OF_VERSION_1_0);
    RUN_TEST(of_bsn_get_l2_table_reply_OF_VERSION_1_0);
    RUN_TEST(of_bsn_get_l2_table_request_OF_VERSION_1_0);
    RUN_TEST(of_bsn_get_mirroring_reply_OF_VERSION_1_0);
    RUN_TEST(of_bsn_get_mirroring_request_OF_VERSION_1_0);
    RUN_TEST(of_bsn_header_OF_VERSION_1_0);
    RUN_TEST(of_bsn_hybrid_get_reply_OF_VERSION_1_0);
    RUN_TEST(of_bsn_hybrid_get_request_OF_VERSION_1_0);
    RUN_TEST(of_bsn_pdu_rx_reply_OF_VERSION_1_0);
    RUN_TEST(of_bsn_pdu_rx_request_OF_VERSION_1_0);
    RUN_TEST(of_bsn_pdu_rx_timeout_OF_VERSION_1_0);
    RUN_TEST(of_bsn_pdu_tx_reply_OF_VERSION_1_0);
    RUN_TEST(of_bsn_pdu_tx_request_OF_VERSION_1_0);
    RUN_TEST(of_bsn_set_ip_mask_OF_VERSION_1_0);
    RUN_TEST(of_bsn_set_l2_table_reply_OF_VERSION_1_0);
    RUN_TEST(of_bsn_set_l2_table_request_OF_VERSION_1_0);
    RUN_TEST(of_bsn_set_mirroring_OF_VERSION_1_0);
    RUN_TEST(of_bsn_set_pktin_suppression_reply_OF_VERSION_1_0);
    RUN_TEST(of_bsn_set_pktin_suppression_request_OF_VERSION_1_0);
    RUN_TEST(of_bsn_shell_command_OF_VERSION_1_0);
    RUN_TEST(of_bsn_shell_output_OF_VERSION_1_0);
    RUN_TEST(of_bsn_shell_status_OF_VERSION_1_0);
    RUN_TEST(of_bsn_stats_reply_OF_VERSION_1_0);
    RUN_TEST(of_bsn_stats_request_OF_VERSION_1_0);
    RUN_TEST(of_bsn_virtual_port_create_reply_OF_VERSION_1_0);
    RUN_TEST(of_bsn_virtual_port_create_request_OF_VERSION_1_0);
    RUN_TEST(of_bsn_virtual_port_remove_reply_OF_VERSION_1_0);
    RUN_TEST(of_bsn_virtual_port_remove_request_OF_VERSION_1_0);
    RUN_TEST(of_desc_stats_reply_OF_VERSION_1_0);
    RUN_TEST(of_desc_stats_request_OF_VERSION_1_0);
    RUN_TEST(of_echo_reply_OF_VERSION_1_0);
    RUN_TEST(of_echo_request_OF_VERSION_1_0);
    RUN_TEST(of_error_msg_OF_VERSION_1_0);
    RUN_TEST(of_experimenter_OF_VERSION_1_0);
    RUN_TEST(of_experimenter_stats_reply_OF_VERSION_1_0);
    RUN_TEST(of_experimenter_stats_request_OF_VERSION_1_0);
    RUN_TEST(of_features_reply_OF_VERSION_1_0);
    RUN_TEST(of_features_request_OF_VERSION_1_0);
    RUN_TEST(of_flow_add_OF_VERSION_1_0);
    RUN_TEST(of_flow_delete_OF_VERSION_1_0);
    RUN_TEST(of_flow_delete_strict_OF_VERSION_1_0);
    RUN_TEST(of_flow_mod_OF_VERSION_1_0);
    RUN_TEST(of_flow_mod_failed_error_msg_OF_VERSION_1_0);
    RUN_TEST(of_flow_modify_OF_VERSION_1_0);
    RUN_TEST(of_flow_modify_strict_OF_VERSION_1_0);
    RUN_TEST(of_flow_removed_OF_VERSION_1_0);
    RUN_TEST(of_flow_stats_reply_OF_VERSION_1_0);
    RUN_TEST(of_flow_stats_request_OF_VERSION_1_0);
    RUN_TEST(of_get_config_reply_OF_VERSION_1_0);
    RUN_TEST(of_get_config_request_OF_VERSION_1_0);
    RUN_TEST(of_hello_OF_VERSION_1_0);
    RUN_TEST(of_hello_failed_error_msg_OF_VERSION_1_0);
    RUN_TEST(of_nicira_controller_role_reply_OF_VERSION_1_0);
    RUN_TEST(of_nicira_controller_role_request_OF_VERSION_1_0);
    RUN_TEST(of_nicira_header_OF_VERSION_1_0);
    RUN_TEST(of_packet_in_OF_VERSION_1_0);
    RUN_TEST(of_packet_out_OF_VERSION_1_0);
    RUN_TEST(of_port_mod_OF_VERSION_1_0);
    RUN_TEST(of_port_mod_failed_error_msg_OF_VERSION_1_0);
    RUN_TEST(of_port_stats_reply_OF_VERSION_1_0);
    RUN_TEST(of_port_stats_request_OF_VERSION_1_0);
    RUN_TEST(of_port_status_OF_VERSION_1_0);
    RUN_TEST(of_queue_get_config_reply_OF_VERSION_1_0);
    RUN_TEST(of_queue_get_config_request_OF_VERSION_1_0);
    RUN_TEST(of_queue_op_failed_error_msg_OF_VERSION_1_0);
    RUN_TEST(of_queue_stats_reply_OF_VERSION_1_0);
    RUN_TEST(of_queue_stats_request_OF_VERSION_1_0);
    RUN_TEST(of_set_config_OF_VERSION_1_0);
    RUN_TEST(of_stats_reply_OF_VERSION_1_0);
    RUN_TEST(of_stats_request_OF_VERSION_1_0);
    RUN_TEST(of_table_mod_OF_VERSION_1_0);
    RUN_TEST(of_table_stats_reply_OF_VERSION_1_0);
    RUN_TEST(of_table_stats_request_OF_VERSION_1_0);
    RUN_TEST(of_action_bsn_OF_VERSION_1_0);
    RUN_TEST(of_action_bsn_mirror_OF_VERSION_1_0);
    RUN_TEST(of_action_bsn_set_tunnel_dst_OF_VERSION_1_0);
    RUN_TEST(of_action_enqueue_OF_VERSION_1_0);
    RUN_TEST(of_action_experimenter_OF_VERSION_1_0);
    RUN_TEST(of_action_header_OF_VERSION_1_0);
    RUN_TEST(of_action_nicira_OF_VERSION_1_0);
    RUN_TEST(of_action_nicira_dec_ttl_OF_VERSION_1_0);
    RUN_TEST(of_action_output_OF_VERSION_1_0);
    RUN_TEST(of_action_set_dl_dst_OF_VERSION_1_0);
    RUN_TEST(of_action_set_dl_src_OF_VERSION_1_0);
    RUN_TEST(of_action_set_nw_dst_OF_VERSION_1_0);
    RUN_TEST(of_action_set_nw_src_OF_VERSION_1_0);
    RUN_TEST(of_action_set_nw_tos_OF_VERSION_1_0);
    RUN_TEST(of_action_set_tp_dst_OF_VERSION_1_0);
    RUN_TEST(of_action_set_tp_src_OF_VERSION_1_0);
    RUN_TEST(of_action_set_vlan_pcp_OF_VERSION_1_0);
    RUN_TEST(of_action_set_vlan_vid_OF_VERSION_1_0);
    RUN_TEST(of_action_strip_vlan_OF_VERSION_1_0);
    RUN_TEST(of_bsn_interface_OF_VERSION_1_0);
    RUN_TEST(of_bsn_vport_header_OF_VERSION_1_0);
    RUN_TEST(of_bsn_vport_q_in_q_OF_VERSION_1_0);
    RUN_TEST(of_flow_stats_entry_OF_VERSION_1_0);
    RUN_TEST(of_header_OF_VERSION_1_0);
    RUN_TEST(of_match_v1_OF_VERSION_1_0);
    RUN_TEST(of_packet_queue_OF_VERSION_1_0);
    RUN_TEST(of_port_desc_OF_VERSION_1_0);
    RUN_TEST(of_port_stats_entry_OF_VERSION_1_0);
    RUN_TEST(of_queue_prop_header_OF_VERSION_1_0);
    RUN_TEST(of_queue_prop_min_rate_OF_VERSION_1_0);
    RUN_TEST(of_queue_stats_entry_OF_VERSION_1_0);
    RUN_TEST(of_table_stats_entry_OF_VERSION_1_0);
    RUN_TEST(of_list_action_OF_VERSION_1_0);
    RUN_TEST(of_list_bsn_interface_OF_VERSION_1_0);
    RUN_TEST(of_list_flow_stats_entry_OF_VERSION_1_0);
    RUN_TEST(of_list_packet_queue_OF_VERSION_1_0);
    RUN_TEST(of_list_port_desc_OF_VERSION_1_0);
    RUN_TEST(of_list_port_stats_entry_OF_VERSION_1_0);
    RUN_TEST(of_list_queue_prop_OF_VERSION_1_0);
    RUN_TEST(of_list_queue_stats_entry_OF_VERSION_1_0);
    RUN_TEST(of_list_table_stats_entry_OF_VERSION_1_0);
    RUN_TEST(of_aggregate_stats_reply_OF_VERSION_1_1);
    RUN_TEST(of_aggregate_stats_request_OF_VERSION_1_1);
    RUN_TEST(of_bad_action_error_msg_OF_VERSION_1_1);
    RUN_TEST(of_bad_instruction_error_msg_OF_VERSION_1_1);
    RUN_TEST(of_bad_match_error_msg_OF_VERSION_1_1);
    RUN_TEST(of_bad_request_error_msg_OF_VERSION_1_1);
    RUN_TEST(of_barrier_reply_OF_VERSION_1_1);
    RUN_TEST(of_barrier_request_OF_VERSION_1_1);
    RUN_TEST(of_bsn_bw_clear_data_reply_OF_VERSION_1_1);
    RUN_TEST(of_bsn_bw_clear_data_request_OF_VERSION_1_1);
    RUN_TEST(of_bsn_bw_enable_get_reply_OF_VERSION_1_1);
    RUN_TEST(of_bsn_bw_enable_get_request_OF_VERSION_1_1);
    RUN_TEST(of_bsn_bw_enable_set_reply_OF_VERSION_1_1);
    RUN_TEST(of_bsn_bw_enable_set_request_OF_VERSION_1_1);
    RUN_TEST(of_bsn_get_interfaces_reply_OF_VERSION_1_1);
    RUN_TEST(of_bsn_get_interfaces_request_OF_VERSION_1_1);
    RUN_TEST(of_bsn_get_mirroring_reply_OF_VERSION_1_1);
    RUN_TEST(of_bsn_get_mirroring_request_OF_VERSION_1_1);
    RUN_TEST(of_bsn_header_OF_VERSION_1_1);
    RUN_TEST(of_bsn_pdu_rx_reply_OF_VERSION_1_1);
    RUN_TEST(of_bsn_pdu_rx_request_OF_VERSION_1_1);
    RUN_TEST(of_bsn_pdu_rx_timeout_OF_VERSION_1_1);
    RUN_TEST(of_bsn_pdu_tx_reply_OF_VERSION_1_1);
    RUN_TEST(of_bsn_pdu_tx_request_OF_VERSION_1_1);
    RUN_TEST(of_bsn_set_mirroring_OF_VERSION_1_1);
    RUN_TEST(of_bsn_set_pktin_suppression_reply_OF_VERSION_1_1);
    RUN_TEST(of_bsn_set_pktin_suppression_request_OF_VERSION_1_1);
    RUN_TEST(of_bsn_stats_reply_OF_VERSION_1_1);
    RUN_TEST(of_bsn_stats_request_OF_VERSION_1_1);
    RUN_TEST(of_bsn_virtual_port_create_reply_OF_VERSION_1_1);
    RUN_TEST(of_bsn_virtual_port_create_request_OF_VERSION_1_1);
    RUN_TEST(of_bsn_virtual_port_remove_reply_OF_VERSION_1_1);
    RUN_TEST(of_bsn_virtual_port_remove_request_OF_VERSION_1_1);
    RUN_TEST(of_desc_stats_reply_OF_VERSION_1_1);
    RUN_TEST(of_desc_stats_request_OF_VERSION_1_1);
    RUN_TEST(of_echo_reply_OF_VERSION_1_1);
    RUN_TEST(of_echo_request_OF_VERSION_1_1);
    RUN_TEST(of_error_msg_OF_VERSION_1_1);
    RUN_TEST(of_experimenter_OF_VERSION_1_1);
    RUN_TEST(of_experimenter_stats_reply_OF_VERSION_1_1);
    RUN_TEST(of_experimenter_stats_request_OF_VERSION_1_1);
    RUN_TEST(of_features_reply_OF_VERSION_1_1);
    RUN_TEST(of_features_request_OF_VERSION_1_1);
    RUN_TEST(of_flow_add_OF_VERSION_1_1);
    RUN_TEST(of_flow_delete_OF_VERSION_1_1);
    RUN_TEST(of_flow_delete_strict_OF_VERSION_1_1);
    RUN_TEST(of_flow_mod_OF_VERSION_1_1);
    RUN_TEST(of_flow_mod_failed_error_msg_OF_VERSION_1_1);
    RUN_TEST(of_flow_modify_OF_VERSION_1_1);
    RUN_TEST(of_flow_modify_strict_OF_VERSION_1_1);
    RUN_TEST(of_flow_removed_OF_VERSION_1_1);
    RUN_TEST(of_flow_stats_reply_OF_VERSION_1_1);
    RUN_TEST(of_flow_stats_request_OF_VERSION_1_1);
    RUN_TEST(of_get_config_reply_OF_VERSION_1_1);
    RUN_TEST(of_get_config_request_OF_VERSION_1_1);
    RUN_TEST(of_group_desc_stats_reply_OF_VERSION_1_1);
    RUN_TEST(of_group_desc_stats_request_OF_VERSION_1_1);
    RUN_TEST(of_group_mod_OF_VERSION_1_1);
    RUN_TEST(of_group_mod_failed_error_msg_OF_VERSION_1_1);
    RUN_TEST(of_group_stats_reply_OF_VERSION_1_1);
    RUN_TEST(of_group_stats_request_OF_VERSION_1_1);
    RUN_TEST(of_hello_OF_VERSION_1_1);
    RUN_TEST(of_hello_failed_error_msg_OF_VERSION_1_1);
    RUN_TEST(of_nicira_header_OF_VERSION_1_1);
    RUN_TEST(of_packet_in_OF_VERSION_1_1);
    RUN_TEST(of_packet_out_OF_VERSION_1_1);
    RUN_TEST(of_port_mod_OF_VERSION_1_1);
    RUN_TEST(of_port_mod_failed_error_msg_OF_VERSION_1_1);
    RUN_TEST(of_port_stats_reply_OF_VERSION_1_1);
    RUN_TEST(of_port_stats_request_OF_VERSION_1_1);
    RUN_TEST(of_port_status_OF_VERSION_1_1);
    RUN_TEST(of_queue_get_config_reply_OF_VERSION_1_1);
    RUN_TEST(of_queue_get_config_request_OF_VERSION_1_1);
    RUN_TEST(of_queue_op_failed_error_msg_OF_VERSION_1_1);
    RUN_TEST(of_queue_stats_reply_OF_VERSION_1_1);
    RUN_TEST(of_queue_stats_request_OF_VERSION_1_1);
    RUN_TEST(of_set_config_OF_VERSION_1_1);
    RUN_TEST(of_stats_reply_OF_VERSION_1_1);
    RUN_TEST(of_stats_request_OF_VERSION_1_1);
    RUN_TEST(of_switch_config_failed_error_msg_OF_VERSION_1_1);
    RUN_TEST(of_table_mod_OF_VERSION_1_1);
    RUN_TEST(of_table_mod_failed_error_msg_OF_VERSION_1_1);
    RUN_TEST(of_table_stats_reply_OF_VERSION_1_1);
    RUN_TEST(of_table_stats_request_OF_VERSION_1_1);
    RUN_TEST(of_action_bsn_OF_VERSION_1_1);
    RUN_TEST(of_action_bsn_mirror_OF_VERSION_1_1);
    RUN_TEST(of_action_bsn_set_tunnel_dst_OF_VERSION_1_1);
    RUN_TEST(of_action_copy_ttl_in_OF_VERSION_1_1);
    RUN_TEST(of_action_copy_ttl_out_OF_VERSION_1_1);
    RUN_TEST(of_action_dec_mpls_ttl_OF_VERSION_1_1);
    RUN_TEST(of_action_dec_nw_ttl_OF_VERSION_1_1);
    RUN_TEST(of_action_experimenter_OF_VERSION_1_1);
    RUN_TEST(of_action_group_OF_VERSION_1_1);
    RUN_TEST(of_action_header_OF_VERSION_1_1);
    RUN_TEST(of_action_nicira_OF_VERSION_1_1);
    RUN_TEST(of_action_nicira_dec_ttl_OF_VERSION_1_1);
    RUN_TEST(of_action_output_OF_VERSION_1_1);
    RUN_TEST(of_action_pop_mpls_OF_VERSION_1_1);
    RUN_TEST(of_action_pop_vlan_OF_VERSION_1_1);
    RUN_TEST(of_action_push_mpls_OF_VERSION_1_1);
    RUN_TEST(of_action_push_vlan_OF_VERSION_1_1);
    RUN_TEST(of_action_set_dl_dst_OF_VERSION_1_1);
    RUN_TEST(of_action_set_dl_src_OF_VERSION_1_1);
    RUN_TEST(of_action_set_mpls_label_OF_VERSION_1_1);
    RUN_TEST(of_action_set_mpls_tc_OF_VERSION_1_1);
    RUN_TEST(of_action_set_mpls_ttl_OF_VERSION_1_1);
    RUN_TEST(of_action_set_nw_dst_OF_VERSION_1_1);
    RUN_TEST(of_action_set_nw_ecn_OF_VERSION_1_1);
    RUN_TEST(of_action_set_nw_src_OF_VERSION_1_1);
    RUN_TEST(of_action_set_nw_tos_OF_VERSION_1_1);
    RUN_TEST(of_action_set_nw_ttl_OF_VERSION_1_1);
    RUN_TEST(of_action_set_queue_OF_VERSION_1_1);
    RUN_TEST(of_action_set_tp_dst_OF_VERSION_1_1);
    RUN_TEST(of_action_set_tp_src_OF_VERSION_1_1);
    RUN_TEST(of_action_set_vlan_pcp_OF_VERSION_1_1);
    RUN_TEST(of_action_set_vlan_vid_OF_VERSION_1_1);
    RUN_TEST(of_bsn_interface_OF_VERSION_1_1);
    RUN_TEST(of_bsn_vport_header_OF_VERSION_1_1);
    RUN_TEST(of_bsn_vport_q_in_q_OF_VERSION_1_1);
    RUN_TEST(of_bucket_OF_VERSION_1_1);
    RUN_TEST(of_bucket_counter_OF_VERSION_1_1);
    RUN_TEST(of_flow_stats_entry_OF_VERSION_1_1);
    RUN_TEST(of_group_desc_stats_entry_OF_VERSION_1_1);
    RUN_TEST(of_group_stats_entry_OF_VERSION_1_1);
    RUN_TEST(of_header_OF_VERSION_1_1);
    RUN_TEST(of_instruction_apply_actions_OF_VERSION_1_1);
    RUN_TEST(of_instruction_clear_actions_OF_VERSION_1_1);
    RUN_TEST(of_instruction_experimenter_OF_VERSION_1_1);
    RUN_TEST(of_instruction_goto_table_OF_VERSION_1_1);
    RUN_TEST(of_instruction_header_OF_VERSION_1_1);
    RUN_TEST(of_instruction_write_actions_OF_VERSION_1_1);
    RUN_TEST(of_instruction_write_metadata_OF_VERSION_1_1);
    RUN_TEST(of_match_v2_OF_VERSION_1_1);
    RUN_TEST(of_packet_queue_OF_VERSION_1_1);
    RUN_TEST(of_port_desc_OF_VERSION_1_1);
    RUN_TEST(of_port_stats_entry_OF_VERSION_1_1);
    RUN_TEST(of_queue_prop_header_OF_VERSION_1_1);
    RUN_TEST(of_queue_prop_min_rate_OF_VERSION_1_1);
    RUN_TEST(of_queue_stats_entry_OF_VERSION_1_1);
    RUN_TEST(of_table_stats_entry_OF_VERSION_1_1);
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
    RUN_TEST(of_aggregate_stats_reply_OF_VERSION_1_2);
    RUN_TEST(of_aggregate_stats_request_OF_VERSION_1_2);
    RUN_TEST(of_bad_action_error_msg_OF_VERSION_1_2);
    RUN_TEST(of_bad_instruction_error_msg_OF_VERSION_1_2);
    RUN_TEST(of_bad_match_error_msg_OF_VERSION_1_2);
    RUN_TEST(of_bad_request_error_msg_OF_VERSION_1_2);
    RUN_TEST(of_barrier_reply_OF_VERSION_1_2);
    RUN_TEST(of_barrier_request_OF_VERSION_1_2);
    RUN_TEST(of_bsn_bw_clear_data_reply_OF_VERSION_1_2);
    RUN_TEST(of_bsn_bw_clear_data_request_OF_VERSION_1_2);
    RUN_TEST(of_bsn_bw_enable_get_reply_OF_VERSION_1_2);
    RUN_TEST(of_bsn_bw_enable_get_request_OF_VERSION_1_2);
    RUN_TEST(of_bsn_bw_enable_set_reply_OF_VERSION_1_2);
    RUN_TEST(of_bsn_bw_enable_set_request_OF_VERSION_1_2);
    RUN_TEST(of_bsn_get_interfaces_reply_OF_VERSION_1_2);
    RUN_TEST(of_bsn_get_interfaces_request_OF_VERSION_1_2);
    RUN_TEST(of_bsn_get_mirroring_reply_OF_VERSION_1_2);
    RUN_TEST(of_bsn_get_mirroring_request_OF_VERSION_1_2);
    RUN_TEST(of_bsn_header_OF_VERSION_1_2);
    RUN_TEST(of_bsn_pdu_rx_reply_OF_VERSION_1_2);
    RUN_TEST(of_bsn_pdu_rx_request_OF_VERSION_1_2);
    RUN_TEST(of_bsn_pdu_rx_timeout_OF_VERSION_1_2);
    RUN_TEST(of_bsn_pdu_tx_reply_OF_VERSION_1_2);
    RUN_TEST(of_bsn_pdu_tx_request_OF_VERSION_1_2);
    RUN_TEST(of_bsn_set_mirroring_OF_VERSION_1_2);
    RUN_TEST(of_bsn_set_pktin_suppression_reply_OF_VERSION_1_2);
    RUN_TEST(of_bsn_set_pktin_suppression_request_OF_VERSION_1_2);
    RUN_TEST(of_bsn_stats_reply_OF_VERSION_1_2);
    RUN_TEST(of_bsn_stats_request_OF_VERSION_1_2);
    RUN_TEST(of_bsn_virtual_port_create_reply_OF_VERSION_1_2);
    RUN_TEST(of_bsn_virtual_port_create_request_OF_VERSION_1_2);
    RUN_TEST(of_bsn_virtual_port_remove_reply_OF_VERSION_1_2);
    RUN_TEST(of_bsn_virtual_port_remove_request_OF_VERSION_1_2);
    RUN_TEST(of_desc_stats_reply_OF_VERSION_1_2);
    RUN_TEST(of_desc_stats_request_OF_VERSION_1_2);
    RUN_TEST(of_echo_reply_OF_VERSION_1_2);
    RUN_TEST(of_echo_request_OF_VERSION_1_2);
    RUN_TEST(of_error_msg_OF_VERSION_1_2);
    RUN_TEST(of_experimenter_OF_VERSION_1_2);
    RUN_TEST(of_experimenter_error_msg_OF_VERSION_1_2);
    RUN_TEST(of_experimenter_stats_reply_OF_VERSION_1_2);
    RUN_TEST(of_experimenter_stats_request_OF_VERSION_1_2);
    RUN_TEST(of_features_reply_OF_VERSION_1_2);
    RUN_TEST(of_features_request_OF_VERSION_1_2);
    RUN_TEST(of_flow_add_OF_VERSION_1_2);
    RUN_TEST(of_flow_delete_OF_VERSION_1_2);
    RUN_TEST(of_flow_delete_strict_OF_VERSION_1_2);
    RUN_TEST(of_flow_mod_OF_VERSION_1_2);
    RUN_TEST(of_flow_mod_failed_error_msg_OF_VERSION_1_2);
    RUN_TEST(of_flow_modify_OF_VERSION_1_2);
    RUN_TEST(of_flow_modify_strict_OF_VERSION_1_2);
    RUN_TEST(of_flow_removed_OF_VERSION_1_2);
    RUN_TEST(of_flow_stats_reply_OF_VERSION_1_2);
    RUN_TEST(of_flow_stats_request_OF_VERSION_1_2);
    RUN_TEST(of_get_config_reply_OF_VERSION_1_2);
    RUN_TEST(of_get_config_request_OF_VERSION_1_2);
    RUN_TEST(of_group_desc_stats_reply_OF_VERSION_1_2);
    RUN_TEST(of_group_desc_stats_request_OF_VERSION_1_2);
    RUN_TEST(of_group_features_stats_reply_OF_VERSION_1_2);
    RUN_TEST(of_group_features_stats_request_OF_VERSION_1_2);
    RUN_TEST(of_group_mod_OF_VERSION_1_2);
    RUN_TEST(of_group_mod_failed_error_msg_OF_VERSION_1_2);
    RUN_TEST(of_group_stats_reply_OF_VERSION_1_2);
    RUN_TEST(of_group_stats_request_OF_VERSION_1_2);
    RUN_TEST(of_hello_OF_VERSION_1_2);
    RUN_TEST(of_hello_failed_error_msg_OF_VERSION_1_2);
    RUN_TEST(of_nicira_header_OF_VERSION_1_2);
    RUN_TEST(of_packet_in_OF_VERSION_1_2);
    RUN_TEST(of_packet_out_OF_VERSION_1_2);
    RUN_TEST(of_port_mod_OF_VERSION_1_2);
    RUN_TEST(of_port_mod_failed_error_msg_OF_VERSION_1_2);
    RUN_TEST(of_port_stats_reply_OF_VERSION_1_2);
    RUN_TEST(of_port_stats_request_OF_VERSION_1_2);
    RUN_TEST(of_port_status_OF_VERSION_1_2);
    RUN_TEST(of_queue_get_config_reply_OF_VERSION_1_2);
    RUN_TEST(of_queue_get_config_request_OF_VERSION_1_2);
    RUN_TEST(of_queue_op_failed_error_msg_OF_VERSION_1_2);
    RUN_TEST(of_queue_stats_reply_OF_VERSION_1_2);
    RUN_TEST(of_queue_stats_request_OF_VERSION_1_2);
    RUN_TEST(of_role_reply_OF_VERSION_1_2);
    RUN_TEST(of_role_request_OF_VERSION_1_2);
    RUN_TEST(of_role_request_failed_error_msg_OF_VERSION_1_2);
    RUN_TEST(of_set_config_OF_VERSION_1_2);
    RUN_TEST(of_stats_reply_OF_VERSION_1_2);
    RUN_TEST(of_stats_request_OF_VERSION_1_2);
    RUN_TEST(of_switch_config_failed_error_msg_OF_VERSION_1_2);
    RUN_TEST(of_table_mod_OF_VERSION_1_2);
    RUN_TEST(of_table_mod_failed_error_msg_OF_VERSION_1_2);
    RUN_TEST(of_table_stats_reply_OF_VERSION_1_2);
    RUN_TEST(of_table_stats_request_OF_VERSION_1_2);
    RUN_TEST(of_action_bsn_OF_VERSION_1_2);
    RUN_TEST(of_action_bsn_mirror_OF_VERSION_1_2);
    RUN_TEST(of_action_bsn_set_tunnel_dst_OF_VERSION_1_2);
    RUN_TEST(of_action_copy_ttl_in_OF_VERSION_1_2);
    RUN_TEST(of_action_copy_ttl_out_OF_VERSION_1_2);
    RUN_TEST(of_action_dec_mpls_ttl_OF_VERSION_1_2);
    RUN_TEST(of_action_dec_nw_ttl_OF_VERSION_1_2);
    RUN_TEST(of_action_experimenter_OF_VERSION_1_2);
    RUN_TEST(of_action_group_OF_VERSION_1_2);
    RUN_TEST(of_action_header_OF_VERSION_1_2);
    RUN_TEST(of_action_nicira_OF_VERSION_1_2);
    RUN_TEST(of_action_nicira_dec_ttl_OF_VERSION_1_2);
    RUN_TEST(of_action_output_OF_VERSION_1_2);
    RUN_TEST(of_action_pop_mpls_OF_VERSION_1_2);
    RUN_TEST(of_action_pop_vlan_OF_VERSION_1_2);
    RUN_TEST(of_action_push_mpls_OF_VERSION_1_2);
    RUN_TEST(of_action_push_vlan_OF_VERSION_1_2);
    RUN_TEST(of_action_set_field_OF_VERSION_1_2);
    RUN_TEST(of_action_set_mpls_ttl_OF_VERSION_1_2);
    RUN_TEST(of_action_set_nw_ttl_OF_VERSION_1_2);
    RUN_TEST(of_action_set_queue_OF_VERSION_1_2);
    RUN_TEST(of_bsn_interface_OF_VERSION_1_2);
    RUN_TEST(of_bsn_vport_header_OF_VERSION_1_2);
    RUN_TEST(of_bsn_vport_q_in_q_OF_VERSION_1_2);
    RUN_TEST(of_bucket_OF_VERSION_1_2);
    RUN_TEST(of_bucket_counter_OF_VERSION_1_2);
    RUN_TEST(of_flow_stats_entry_OF_VERSION_1_2);
    RUN_TEST(of_group_desc_stats_entry_OF_VERSION_1_2);
    RUN_TEST(of_group_stats_entry_OF_VERSION_1_2);
    RUN_TEST(of_header_OF_VERSION_1_2);
    RUN_TEST(of_instruction_apply_actions_OF_VERSION_1_2);
    RUN_TEST(of_instruction_clear_actions_OF_VERSION_1_2);
    RUN_TEST(of_instruction_experimenter_OF_VERSION_1_2);
    RUN_TEST(of_instruction_goto_table_OF_VERSION_1_2);
    RUN_TEST(of_instruction_header_OF_VERSION_1_2);
    RUN_TEST(of_instruction_write_actions_OF_VERSION_1_2);
    RUN_TEST(of_instruction_write_metadata_OF_VERSION_1_2);
    RUN_TEST(of_match_v3_OF_VERSION_1_2);
    RUN_TEST(of_oxm_arp_op_OF_VERSION_1_2);
    RUN_TEST(of_oxm_arp_op_masked_OF_VERSION_1_2);
    RUN_TEST(of_oxm_arp_sha_OF_VERSION_1_2);
    RUN_TEST(of_oxm_arp_sha_masked_OF_VERSION_1_2);
    RUN_TEST(of_oxm_arp_spa_OF_VERSION_1_2);
    RUN_TEST(of_oxm_arp_spa_masked_OF_VERSION_1_2);
    RUN_TEST(of_oxm_arp_tha_OF_VERSION_1_2);
    RUN_TEST(of_oxm_arp_tha_masked_OF_VERSION_1_2);
    RUN_TEST(of_oxm_arp_tpa_OF_VERSION_1_2);
    RUN_TEST(of_oxm_arp_tpa_masked_OF_VERSION_1_2);
    RUN_TEST(of_oxm_bsn_global_vrf_allowed_OF_VERSION_1_2);
    RUN_TEST(of_oxm_bsn_global_vrf_allowed_masked_OF_VERSION_1_2);
    RUN_TEST(of_oxm_bsn_in_ports_128_OF_VERSION_1_2);
    RUN_TEST(of_oxm_bsn_in_ports_128_masked_OF_VERSION_1_2);
    RUN_TEST(of_oxm_bsn_l3_dst_class_id_OF_VERSION_1_2);
    RUN_TEST(of_oxm_bsn_l3_dst_class_id_masked_OF_VERSION_1_2);
    RUN_TEST(of_oxm_bsn_l3_interface_class_id_OF_VERSION_1_2);
    RUN_TEST(of_oxm_bsn_l3_interface_class_id_masked_OF_VERSION_1_2);
    RUN_TEST(of_oxm_bsn_l3_src_class_id_OF_VERSION_1_2);
    RUN_TEST(of_oxm_bsn_l3_src_class_id_masked_OF_VERSION_1_2);
    RUN_TEST(of_oxm_bsn_lag_id_OF_VERSION_1_2);
    RUN_TEST(of_oxm_bsn_lag_id_masked_OF_VERSION_1_2);
    RUN_TEST(of_oxm_bsn_vrf_OF_VERSION_1_2);
    RUN_TEST(of_oxm_bsn_vrf_masked_OF_VERSION_1_2);
    RUN_TEST(of_oxm_eth_dst_OF_VERSION_1_2);
    RUN_TEST(of_oxm_eth_dst_masked_OF_VERSION_1_2);
    RUN_TEST(of_oxm_eth_src_OF_VERSION_1_2);
    RUN_TEST(of_oxm_eth_src_masked_OF_VERSION_1_2);
    RUN_TEST(of_oxm_eth_type_OF_VERSION_1_2);
    RUN_TEST(of_oxm_eth_type_masked_OF_VERSION_1_2);
    RUN_TEST(of_oxm_header_OF_VERSION_1_2);
    RUN_TEST(of_oxm_icmpv4_code_OF_VERSION_1_2);
    RUN_TEST(of_oxm_icmpv4_code_masked_OF_VERSION_1_2);
    RUN_TEST(of_oxm_icmpv4_type_OF_VERSION_1_2);
    RUN_TEST(of_oxm_icmpv4_type_masked_OF_VERSION_1_2);
    RUN_TEST(of_oxm_icmpv6_code_OF_VERSION_1_2);
    RUN_TEST(of_oxm_icmpv6_code_masked_OF_VERSION_1_2);
    RUN_TEST(of_oxm_icmpv6_type_OF_VERSION_1_2);
    RUN_TEST(of_oxm_icmpv6_type_masked_OF_VERSION_1_2);
    RUN_TEST(of_oxm_in_phy_port_OF_VERSION_1_2);
    RUN_TEST(of_oxm_in_phy_port_masked_OF_VERSION_1_2);
    RUN_TEST(of_oxm_in_port_OF_VERSION_1_2);
    RUN_TEST(of_oxm_in_port_masked_OF_VERSION_1_2);
    RUN_TEST(of_oxm_ip_dscp_OF_VERSION_1_2);
    RUN_TEST(of_oxm_ip_dscp_masked_OF_VERSION_1_2);
    RUN_TEST(of_oxm_ip_ecn_OF_VERSION_1_2);
    RUN_TEST(of_oxm_ip_ecn_masked_OF_VERSION_1_2);
    RUN_TEST(of_oxm_ip_proto_OF_VERSION_1_2);
    RUN_TEST(of_oxm_ip_proto_masked_OF_VERSION_1_2);
    RUN_TEST(of_oxm_ipv4_dst_OF_VERSION_1_2);
    RUN_TEST(of_oxm_ipv4_dst_masked_OF_VERSION_1_2);
    RUN_TEST(of_oxm_ipv4_src_OF_VERSION_1_2);
    RUN_TEST(of_oxm_ipv4_src_masked_OF_VERSION_1_2);
    RUN_TEST(of_oxm_ipv6_dst_OF_VERSION_1_2);
    RUN_TEST(of_oxm_ipv6_dst_masked_OF_VERSION_1_2);
    RUN_TEST(of_oxm_ipv6_flabel_OF_VERSION_1_2);
    RUN_TEST(of_oxm_ipv6_flabel_masked_OF_VERSION_1_2);
    RUN_TEST(of_oxm_ipv6_nd_sll_OF_VERSION_1_2);
    RUN_TEST(of_oxm_ipv6_nd_sll_masked_OF_VERSION_1_2);
    RUN_TEST(of_oxm_ipv6_nd_target_OF_VERSION_1_2);
    RUN_TEST(of_oxm_ipv6_nd_target_masked_OF_VERSION_1_2);
    RUN_TEST(of_oxm_ipv6_nd_tll_OF_VERSION_1_2);
    RUN_TEST(of_oxm_ipv6_nd_tll_masked_OF_VERSION_1_2);
    RUN_TEST(of_oxm_ipv6_src_OF_VERSION_1_2);
    RUN_TEST(of_oxm_ipv6_src_masked_OF_VERSION_1_2);
    RUN_TEST(of_oxm_metadata_OF_VERSION_1_2);
    RUN_TEST(of_oxm_metadata_masked_OF_VERSION_1_2);
    RUN_TEST(of_oxm_mpls_label_OF_VERSION_1_2);
    RUN_TEST(of_oxm_mpls_label_masked_OF_VERSION_1_2);
    RUN_TEST(of_oxm_mpls_tc_OF_VERSION_1_2);
    RUN_TEST(of_oxm_mpls_tc_masked_OF_VERSION_1_2);
    RUN_TEST(of_oxm_sctp_dst_OF_VERSION_1_2);
    RUN_TEST(of_oxm_sctp_dst_masked_OF_VERSION_1_2);
    RUN_TEST(of_oxm_sctp_src_OF_VERSION_1_2);
    RUN_TEST(of_oxm_sctp_src_masked_OF_VERSION_1_2);
    RUN_TEST(of_oxm_tcp_dst_OF_VERSION_1_2);
    RUN_TEST(of_oxm_tcp_dst_masked_OF_VERSION_1_2);
    RUN_TEST(of_oxm_tcp_src_OF_VERSION_1_2);
    RUN_TEST(of_oxm_tcp_src_masked_OF_VERSION_1_2);
    RUN_TEST(of_oxm_udp_dst_OF_VERSION_1_2);
    RUN_TEST(of_oxm_udp_dst_masked_OF_VERSION_1_2);
    RUN_TEST(of_oxm_udp_src_OF_VERSION_1_2);
    RUN_TEST(of_oxm_udp_src_masked_OF_VERSION_1_2);
    RUN_TEST(of_oxm_vlan_pcp_OF_VERSION_1_2);
    RUN_TEST(of_oxm_vlan_pcp_masked_OF_VERSION_1_2);
    RUN_TEST(of_oxm_vlan_vid_OF_VERSION_1_2);
    RUN_TEST(of_oxm_vlan_vid_masked_OF_VERSION_1_2);
    RUN_TEST(of_packet_queue_OF_VERSION_1_2);
    RUN_TEST(of_port_desc_OF_VERSION_1_2);
    RUN_TEST(of_port_stats_entry_OF_VERSION_1_2);
    RUN_TEST(of_queue_prop_experimenter_OF_VERSION_1_2);
    RUN_TEST(of_queue_prop_header_OF_VERSION_1_2);
    RUN_TEST(of_queue_prop_max_rate_OF_VERSION_1_2);
    RUN_TEST(of_queue_prop_min_rate_OF_VERSION_1_2);
    RUN_TEST(of_queue_stats_entry_OF_VERSION_1_2);
    RUN_TEST(of_table_stats_entry_OF_VERSION_1_2);
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
    RUN_TEST(of_aggregate_stats_reply_OF_VERSION_1_3);
    RUN_TEST(of_aggregate_stats_request_OF_VERSION_1_3);
    RUN_TEST(of_async_get_reply_OF_VERSION_1_3);
    RUN_TEST(of_async_get_request_OF_VERSION_1_3);
    RUN_TEST(of_async_set_OF_VERSION_1_3);
    RUN_TEST(of_bad_action_error_msg_OF_VERSION_1_3);
    RUN_TEST(of_bad_instruction_error_msg_OF_VERSION_1_3);
    RUN_TEST(of_bad_match_error_msg_OF_VERSION_1_3);
    RUN_TEST(of_bad_request_error_msg_OF_VERSION_1_3);
    RUN_TEST(of_barrier_reply_OF_VERSION_1_3);
    RUN_TEST(of_barrier_request_OF_VERSION_1_3);
    RUN_TEST(of_bsn_bw_clear_data_reply_OF_VERSION_1_3);
    RUN_TEST(of_bsn_bw_clear_data_request_OF_VERSION_1_3);
    RUN_TEST(of_bsn_bw_enable_get_reply_OF_VERSION_1_3);
    RUN_TEST(of_bsn_bw_enable_get_request_OF_VERSION_1_3);
    RUN_TEST(of_bsn_bw_enable_set_reply_OF_VERSION_1_3);
    RUN_TEST(of_bsn_bw_enable_set_request_OF_VERSION_1_3);
    RUN_TEST(of_bsn_flow_idle_OF_VERSION_1_3);
    RUN_TEST(of_bsn_flow_idle_enable_get_reply_OF_VERSION_1_3);
    RUN_TEST(of_bsn_flow_idle_enable_get_request_OF_VERSION_1_3);
    RUN_TEST(of_bsn_flow_idle_enable_set_reply_OF_VERSION_1_3);
    RUN_TEST(of_bsn_flow_idle_enable_set_request_OF_VERSION_1_3);
    RUN_TEST(of_bsn_get_interfaces_reply_OF_VERSION_1_3);
    RUN_TEST(of_bsn_get_interfaces_request_OF_VERSION_1_3);
    RUN_TEST(of_bsn_get_mirroring_reply_OF_VERSION_1_3);
    RUN_TEST(of_bsn_get_mirroring_request_OF_VERSION_1_3);
    RUN_TEST(of_bsn_header_OF_VERSION_1_3);
    RUN_TEST(of_bsn_lacp_convergence_notif_OF_VERSION_1_3);
    RUN_TEST(of_bsn_lacp_stats_reply_OF_VERSION_1_3);
    RUN_TEST(of_bsn_lacp_stats_request_OF_VERSION_1_3);
    RUN_TEST(of_bsn_pdu_rx_reply_OF_VERSION_1_3);
    RUN_TEST(of_bsn_pdu_rx_request_OF_VERSION_1_3);
    RUN_TEST(of_bsn_pdu_rx_timeout_OF_VERSION_1_3);
    RUN_TEST(of_bsn_pdu_tx_reply_OF_VERSION_1_3);
    RUN_TEST(of_bsn_pdu_tx_request_OF_VERSION_1_3);
    RUN_TEST(of_bsn_set_lacp_reply_OF_VERSION_1_3);
    RUN_TEST(of_bsn_set_lacp_request_OF_VERSION_1_3);
    RUN_TEST(of_bsn_set_mirroring_OF_VERSION_1_3);
    RUN_TEST(of_bsn_set_pktin_suppression_reply_OF_VERSION_1_3);
    RUN_TEST(of_bsn_set_pktin_suppression_request_OF_VERSION_1_3);
    RUN_TEST(of_bsn_stats_reply_OF_VERSION_1_3);
    RUN_TEST(of_bsn_stats_request_OF_VERSION_1_3);
    RUN_TEST(of_bsn_time_reply_OF_VERSION_1_3);
    RUN_TEST(of_bsn_time_request_OF_VERSION_1_3);
    RUN_TEST(of_bsn_virtual_port_create_reply_OF_VERSION_1_3);
    RUN_TEST(of_bsn_virtual_port_create_request_OF_VERSION_1_3);
    RUN_TEST(of_bsn_virtual_port_remove_reply_OF_VERSION_1_3);
    RUN_TEST(of_bsn_virtual_port_remove_request_OF_VERSION_1_3);
    RUN_TEST(of_desc_stats_reply_OF_VERSION_1_3);
    RUN_TEST(of_desc_stats_request_OF_VERSION_1_3);
    RUN_TEST(of_echo_reply_OF_VERSION_1_3);
    RUN_TEST(of_echo_request_OF_VERSION_1_3);
    RUN_TEST(of_error_msg_OF_VERSION_1_3);
    RUN_TEST(of_experimenter_OF_VERSION_1_3);
    RUN_TEST(of_experimenter_error_msg_OF_VERSION_1_3);
    RUN_TEST(of_experimenter_stats_reply_OF_VERSION_1_3);
    RUN_TEST(of_experimenter_stats_request_OF_VERSION_1_3);
    RUN_TEST(of_features_reply_OF_VERSION_1_3);
    RUN_TEST(of_features_request_OF_VERSION_1_3);
    RUN_TEST(of_flow_add_OF_VERSION_1_3);
    RUN_TEST(of_flow_delete_OF_VERSION_1_3);
    RUN_TEST(of_flow_delete_strict_OF_VERSION_1_3);
    RUN_TEST(of_flow_mod_OF_VERSION_1_3);
    RUN_TEST(of_flow_mod_failed_error_msg_OF_VERSION_1_3);
    RUN_TEST(of_flow_modify_OF_VERSION_1_3);
    RUN_TEST(of_flow_modify_strict_OF_VERSION_1_3);
    RUN_TEST(of_flow_removed_OF_VERSION_1_3);
    RUN_TEST(of_flow_stats_reply_OF_VERSION_1_3);
    RUN_TEST(of_flow_stats_request_OF_VERSION_1_3);
    RUN_TEST(of_get_config_reply_OF_VERSION_1_3);
    RUN_TEST(of_get_config_request_OF_VERSION_1_3);
    RUN_TEST(of_group_desc_stats_reply_OF_VERSION_1_3);
    RUN_TEST(of_group_desc_stats_request_OF_VERSION_1_3);
    RUN_TEST(of_group_features_stats_reply_OF_VERSION_1_3);
    RUN_TEST(of_group_features_stats_request_OF_VERSION_1_3);
    RUN_TEST(of_group_mod_OF_VERSION_1_3);
    RUN_TEST(of_group_mod_failed_error_msg_OF_VERSION_1_3);
    RUN_TEST(of_group_stats_reply_OF_VERSION_1_3);
    RUN_TEST(of_group_stats_request_OF_VERSION_1_3);
    RUN_TEST(of_hello_OF_VERSION_1_3);
    RUN_TEST(of_hello_failed_error_msg_OF_VERSION_1_3);
    RUN_TEST(of_meter_config_stats_reply_OF_VERSION_1_3);
    RUN_TEST(of_meter_config_stats_request_OF_VERSION_1_3);
    RUN_TEST(of_meter_features_stats_reply_OF_VERSION_1_3);
    RUN_TEST(of_meter_features_stats_request_OF_VERSION_1_3);
    RUN_TEST(of_meter_mod_OF_VERSION_1_3);
    RUN_TEST(of_meter_mod_failed_error_msg_OF_VERSION_1_3);
    RUN_TEST(of_meter_stats_reply_OF_VERSION_1_3);
    RUN_TEST(of_meter_stats_request_OF_VERSION_1_3);
    RUN_TEST(of_nicira_header_OF_VERSION_1_3);
    RUN_TEST(of_packet_in_OF_VERSION_1_3);
    RUN_TEST(of_packet_out_OF_VERSION_1_3);
    RUN_TEST(of_port_desc_stats_reply_OF_VERSION_1_3);
    RUN_TEST(of_port_desc_stats_request_OF_VERSION_1_3);
    RUN_TEST(of_port_mod_OF_VERSION_1_3);
    RUN_TEST(of_port_mod_failed_error_msg_OF_VERSION_1_3);
    RUN_TEST(of_port_stats_reply_OF_VERSION_1_3);
    RUN_TEST(of_port_stats_request_OF_VERSION_1_3);
    RUN_TEST(of_port_status_OF_VERSION_1_3);
    RUN_TEST(of_queue_get_config_reply_OF_VERSION_1_3);
    RUN_TEST(of_queue_get_config_request_OF_VERSION_1_3);
    RUN_TEST(of_queue_op_failed_error_msg_OF_VERSION_1_3);
    RUN_TEST(of_queue_stats_reply_OF_VERSION_1_3);
    RUN_TEST(of_queue_stats_request_OF_VERSION_1_3);
    RUN_TEST(of_role_reply_OF_VERSION_1_3);
    RUN_TEST(of_role_request_OF_VERSION_1_3);
    RUN_TEST(of_role_request_failed_error_msg_OF_VERSION_1_3);
    RUN_TEST(of_set_config_OF_VERSION_1_3);
    RUN_TEST(of_stats_reply_OF_VERSION_1_3);
    RUN_TEST(of_stats_request_OF_VERSION_1_3);
    RUN_TEST(of_switch_config_failed_error_msg_OF_VERSION_1_3);
    RUN_TEST(of_table_features_failed_error_msg_OF_VERSION_1_3);
    RUN_TEST(of_table_features_stats_reply_OF_VERSION_1_3);
    RUN_TEST(of_table_features_stats_request_OF_VERSION_1_3);
    RUN_TEST(of_table_mod_OF_VERSION_1_3);
    RUN_TEST(of_table_mod_failed_error_msg_OF_VERSION_1_3);
    RUN_TEST(of_table_stats_reply_OF_VERSION_1_3);
    RUN_TEST(of_table_stats_request_OF_VERSION_1_3);
    RUN_TEST(of_action_bsn_OF_VERSION_1_3);
    RUN_TEST(of_action_bsn_mirror_OF_VERSION_1_3);
    RUN_TEST(of_action_bsn_set_tunnel_dst_OF_VERSION_1_3);
    RUN_TEST(of_action_copy_ttl_in_OF_VERSION_1_3);
    RUN_TEST(of_action_copy_ttl_out_OF_VERSION_1_3);
    RUN_TEST(of_action_dec_mpls_ttl_OF_VERSION_1_3);
    RUN_TEST(of_action_dec_nw_ttl_OF_VERSION_1_3);
    RUN_TEST(of_action_experimenter_OF_VERSION_1_3);
    RUN_TEST(of_action_group_OF_VERSION_1_3);
    RUN_TEST(of_action_header_OF_VERSION_1_3);
    RUN_TEST(of_action_id_bsn_OF_VERSION_1_3);
    RUN_TEST(of_action_id_bsn_mirror_OF_VERSION_1_3);
    RUN_TEST(of_action_id_bsn_set_tunnel_dst_OF_VERSION_1_3);
    RUN_TEST(of_action_id_copy_ttl_in_OF_VERSION_1_3);
    RUN_TEST(of_action_id_copy_ttl_out_OF_VERSION_1_3);
    RUN_TEST(of_action_id_dec_mpls_ttl_OF_VERSION_1_3);
    RUN_TEST(of_action_id_dec_nw_ttl_OF_VERSION_1_3);
    RUN_TEST(of_action_id_experimenter_OF_VERSION_1_3);
    RUN_TEST(of_action_id_group_OF_VERSION_1_3);
    RUN_TEST(of_action_id_header_OF_VERSION_1_3);
    RUN_TEST(of_action_id_nicira_OF_VERSION_1_3);
    RUN_TEST(of_action_id_nicira_dec_ttl_OF_VERSION_1_3);
    RUN_TEST(of_action_id_output_OF_VERSION_1_3);
    RUN_TEST(of_action_id_pop_mpls_OF_VERSION_1_3);
    RUN_TEST(of_action_id_pop_pbb_OF_VERSION_1_3);
    RUN_TEST(of_action_id_pop_vlan_OF_VERSION_1_3);
    RUN_TEST(of_action_id_push_mpls_OF_VERSION_1_3);
    RUN_TEST(of_action_id_push_pbb_OF_VERSION_1_3);
    RUN_TEST(of_action_id_push_vlan_OF_VERSION_1_3);
    RUN_TEST(of_action_id_set_field_OF_VERSION_1_3);
    RUN_TEST(of_action_id_set_mpls_ttl_OF_VERSION_1_3);
    RUN_TEST(of_action_id_set_nw_ttl_OF_VERSION_1_3);
    RUN_TEST(of_action_id_set_queue_OF_VERSION_1_3);
    RUN_TEST(of_action_nicira_OF_VERSION_1_3);
    RUN_TEST(of_action_nicira_dec_ttl_OF_VERSION_1_3);
    RUN_TEST(of_action_output_OF_VERSION_1_3);
    RUN_TEST(of_action_pop_mpls_OF_VERSION_1_3);
    RUN_TEST(of_action_pop_pbb_OF_VERSION_1_3);
    RUN_TEST(of_action_pop_vlan_OF_VERSION_1_3);
    RUN_TEST(of_action_push_mpls_OF_VERSION_1_3);
    RUN_TEST(of_action_push_pbb_OF_VERSION_1_3);
    RUN_TEST(of_action_push_vlan_OF_VERSION_1_3);
    RUN_TEST(of_action_set_field_OF_VERSION_1_3);
    RUN_TEST(of_action_set_mpls_ttl_OF_VERSION_1_3);
    RUN_TEST(of_action_set_nw_ttl_OF_VERSION_1_3);
    RUN_TEST(of_action_set_queue_OF_VERSION_1_3);
    RUN_TEST(of_bsn_interface_OF_VERSION_1_3);
    RUN_TEST(of_bsn_lacp_stats_entry_OF_VERSION_1_3);
    RUN_TEST(of_bsn_vport_header_OF_VERSION_1_3);
    RUN_TEST(of_bsn_vport_q_in_q_OF_VERSION_1_3);
    RUN_TEST(of_bucket_OF_VERSION_1_3);
    RUN_TEST(of_bucket_counter_OF_VERSION_1_3);
    RUN_TEST(of_experimenter_stats_header_OF_VERSION_1_3);
    RUN_TEST(of_flow_stats_entry_OF_VERSION_1_3);
    RUN_TEST(of_group_desc_stats_entry_OF_VERSION_1_3);
    RUN_TEST(of_group_stats_entry_OF_VERSION_1_3);
    RUN_TEST(of_header_OF_VERSION_1_3);
    RUN_TEST(of_hello_elem_header_OF_VERSION_1_3);
    RUN_TEST(of_hello_elem_versionbitmap_OF_VERSION_1_3);
    RUN_TEST(of_instruction_apply_actions_OF_VERSION_1_3);
    RUN_TEST(of_instruction_clear_actions_OF_VERSION_1_3);
    RUN_TEST(of_instruction_experimenter_OF_VERSION_1_3);
    RUN_TEST(of_instruction_goto_table_OF_VERSION_1_3);
    RUN_TEST(of_instruction_header_OF_VERSION_1_3);
    RUN_TEST(of_instruction_meter_OF_VERSION_1_3);
    RUN_TEST(of_instruction_write_actions_OF_VERSION_1_3);
    RUN_TEST(of_instruction_write_metadata_OF_VERSION_1_3);
    RUN_TEST(of_match_v3_OF_VERSION_1_3);
    RUN_TEST(of_meter_band_drop_OF_VERSION_1_3);
    RUN_TEST(of_meter_band_dscp_remark_OF_VERSION_1_3);
    RUN_TEST(of_meter_band_experimenter_OF_VERSION_1_3);
    RUN_TEST(of_meter_band_header_OF_VERSION_1_3);
    RUN_TEST(of_meter_band_stats_OF_VERSION_1_3);
    RUN_TEST(of_meter_config_OF_VERSION_1_3);
    RUN_TEST(of_meter_features_OF_VERSION_1_3);
    RUN_TEST(of_meter_stats_OF_VERSION_1_3);
    RUN_TEST(of_oxm_arp_op_OF_VERSION_1_3);
    RUN_TEST(of_oxm_arp_op_masked_OF_VERSION_1_3);
    RUN_TEST(of_oxm_arp_sha_OF_VERSION_1_3);
    RUN_TEST(of_oxm_arp_sha_masked_OF_VERSION_1_3);
    RUN_TEST(of_oxm_arp_spa_OF_VERSION_1_3);
    RUN_TEST(of_oxm_arp_spa_masked_OF_VERSION_1_3);
    RUN_TEST(of_oxm_arp_tha_OF_VERSION_1_3);
    RUN_TEST(of_oxm_arp_tha_masked_OF_VERSION_1_3);
    RUN_TEST(of_oxm_arp_tpa_OF_VERSION_1_3);
    RUN_TEST(of_oxm_arp_tpa_masked_OF_VERSION_1_3);
    RUN_TEST(of_oxm_bsn_global_vrf_allowed_OF_VERSION_1_3);
    RUN_TEST(of_oxm_bsn_global_vrf_allowed_masked_OF_VERSION_1_3);
    RUN_TEST(of_oxm_bsn_in_ports_128_OF_VERSION_1_3);
    RUN_TEST(of_oxm_bsn_in_ports_128_masked_OF_VERSION_1_3);
    RUN_TEST(of_oxm_bsn_l3_dst_class_id_OF_VERSION_1_3);
    RUN_TEST(of_oxm_bsn_l3_dst_class_id_masked_OF_VERSION_1_3);
    RUN_TEST(of_oxm_bsn_l3_interface_class_id_OF_VERSION_1_3);
    RUN_TEST(of_oxm_bsn_l3_interface_class_id_masked_OF_VERSION_1_3);
    RUN_TEST(of_oxm_bsn_l3_src_class_id_OF_VERSION_1_3);
    RUN_TEST(of_oxm_bsn_l3_src_class_id_masked_OF_VERSION_1_3);
    RUN_TEST(of_oxm_bsn_lag_id_OF_VERSION_1_3);
    RUN_TEST(of_oxm_bsn_lag_id_masked_OF_VERSION_1_3);
    RUN_TEST(of_oxm_bsn_vrf_OF_VERSION_1_3);
    RUN_TEST(of_oxm_bsn_vrf_masked_OF_VERSION_1_3);
    RUN_TEST(of_oxm_eth_dst_OF_VERSION_1_3);
    RUN_TEST(of_oxm_eth_dst_masked_OF_VERSION_1_3);
    RUN_TEST(of_oxm_eth_src_OF_VERSION_1_3);
    RUN_TEST(of_oxm_eth_src_masked_OF_VERSION_1_3);
    RUN_TEST(of_oxm_eth_type_OF_VERSION_1_3);
    RUN_TEST(of_oxm_eth_type_masked_OF_VERSION_1_3);
    RUN_TEST(of_oxm_header_OF_VERSION_1_3);
    RUN_TEST(of_oxm_icmpv4_code_OF_VERSION_1_3);
    RUN_TEST(of_oxm_icmpv4_code_masked_OF_VERSION_1_3);
    RUN_TEST(of_oxm_icmpv4_type_OF_VERSION_1_3);
    RUN_TEST(of_oxm_icmpv4_type_masked_OF_VERSION_1_3);
    RUN_TEST(of_oxm_icmpv6_code_OF_VERSION_1_3);
    RUN_TEST(of_oxm_icmpv6_code_masked_OF_VERSION_1_3);
    RUN_TEST(of_oxm_icmpv6_type_OF_VERSION_1_3);
    RUN_TEST(of_oxm_icmpv6_type_masked_OF_VERSION_1_3);
    RUN_TEST(of_oxm_in_phy_port_OF_VERSION_1_3);
    RUN_TEST(of_oxm_in_phy_port_masked_OF_VERSION_1_3);
    RUN_TEST(of_oxm_in_port_OF_VERSION_1_3);
    RUN_TEST(of_oxm_in_port_masked_OF_VERSION_1_3);
    RUN_TEST(of_oxm_ip_dscp_OF_VERSION_1_3);
    RUN_TEST(of_oxm_ip_dscp_masked_OF_VERSION_1_3);
    RUN_TEST(of_oxm_ip_ecn_OF_VERSION_1_3);
    RUN_TEST(of_oxm_ip_ecn_masked_OF_VERSION_1_3);
    RUN_TEST(of_oxm_ip_proto_OF_VERSION_1_3);
    RUN_TEST(of_oxm_ip_proto_masked_OF_VERSION_1_3);
    RUN_TEST(of_oxm_ipv4_dst_OF_VERSION_1_3);
    RUN_TEST(of_oxm_ipv4_dst_masked_OF_VERSION_1_3);
    RUN_TEST(of_oxm_ipv4_src_OF_VERSION_1_3);
    RUN_TEST(of_oxm_ipv4_src_masked_OF_VERSION_1_3);
    RUN_TEST(of_oxm_ipv6_dst_OF_VERSION_1_3);
    RUN_TEST(of_oxm_ipv6_dst_masked_OF_VERSION_1_3);
    RUN_TEST(of_oxm_ipv6_flabel_OF_VERSION_1_3);
    RUN_TEST(of_oxm_ipv6_flabel_masked_OF_VERSION_1_3);
    RUN_TEST(of_oxm_ipv6_nd_sll_OF_VERSION_1_3);
    RUN_TEST(of_oxm_ipv6_nd_sll_masked_OF_VERSION_1_3);
    RUN_TEST(of_oxm_ipv6_nd_target_OF_VERSION_1_3);
    RUN_TEST(of_oxm_ipv6_nd_target_masked_OF_VERSION_1_3);
    RUN_TEST(of_oxm_ipv6_nd_tll_OF_VERSION_1_3);
    RUN_TEST(of_oxm_ipv6_nd_tll_masked_OF_VERSION_1_3);
    RUN_TEST(of_oxm_ipv6_src_OF_VERSION_1_3);
    RUN_TEST(of_oxm_ipv6_src_masked_OF_VERSION_1_3);
    RUN_TEST(of_oxm_metadata_OF_VERSION_1_3);
    RUN_TEST(of_oxm_metadata_masked_OF_VERSION_1_3);
    RUN_TEST(of_oxm_mpls_label_OF_VERSION_1_3);
    RUN_TEST(of_oxm_mpls_label_masked_OF_VERSION_1_3);
    RUN_TEST(of_oxm_mpls_tc_OF_VERSION_1_3);
    RUN_TEST(of_oxm_mpls_tc_masked_OF_VERSION_1_3);
    RUN_TEST(of_oxm_sctp_dst_OF_VERSION_1_3);
    RUN_TEST(of_oxm_sctp_dst_masked_OF_VERSION_1_3);
    RUN_TEST(of_oxm_sctp_src_OF_VERSION_1_3);
    RUN_TEST(of_oxm_sctp_src_masked_OF_VERSION_1_3);
    RUN_TEST(of_oxm_tcp_dst_OF_VERSION_1_3);
    RUN_TEST(of_oxm_tcp_dst_masked_OF_VERSION_1_3);
    RUN_TEST(of_oxm_tcp_src_OF_VERSION_1_3);
    RUN_TEST(of_oxm_tcp_src_masked_OF_VERSION_1_3);
    RUN_TEST(of_oxm_udp_dst_OF_VERSION_1_3);
    RUN_TEST(of_oxm_udp_dst_masked_OF_VERSION_1_3);
    RUN_TEST(of_oxm_udp_src_OF_VERSION_1_3);
    RUN_TEST(of_oxm_udp_src_masked_OF_VERSION_1_3);
    RUN_TEST(of_oxm_vlan_pcp_OF_VERSION_1_3);
    RUN_TEST(of_oxm_vlan_pcp_masked_OF_VERSION_1_3);
    RUN_TEST(of_oxm_vlan_vid_OF_VERSION_1_3);
    RUN_TEST(of_oxm_vlan_vid_masked_OF_VERSION_1_3);
    RUN_TEST(of_packet_queue_OF_VERSION_1_3);
    RUN_TEST(of_port_desc_OF_VERSION_1_3);
    RUN_TEST(of_port_stats_entry_OF_VERSION_1_3);
    RUN_TEST(of_queue_prop_experimenter_OF_VERSION_1_3);
    RUN_TEST(of_queue_prop_header_OF_VERSION_1_3);
    RUN_TEST(of_queue_prop_max_rate_OF_VERSION_1_3);
    RUN_TEST(of_queue_prop_min_rate_OF_VERSION_1_3);
    RUN_TEST(of_queue_stats_entry_OF_VERSION_1_3);
    RUN_TEST(of_table_feature_prop_apply_actions_OF_VERSION_1_3);
    RUN_TEST(of_table_feature_prop_apply_actions_miss_OF_VERSION_1_3);
    RUN_TEST(of_table_feature_prop_apply_setfield_OF_VERSION_1_3);
    RUN_TEST(of_table_feature_prop_apply_setfield_miss_OF_VERSION_1_3);
    RUN_TEST(of_table_feature_prop_experimenter_OF_VERSION_1_3);
    RUN_TEST(of_table_feature_prop_header_OF_VERSION_1_3);
    RUN_TEST(of_table_feature_prop_instructions_OF_VERSION_1_3);
    RUN_TEST(of_table_feature_prop_instructions_miss_OF_VERSION_1_3);
    RUN_TEST(of_table_feature_prop_match_OF_VERSION_1_3);
    RUN_TEST(of_table_feature_prop_next_tables_OF_VERSION_1_3);
    RUN_TEST(of_table_feature_prop_next_tables_miss_OF_VERSION_1_3);
    RUN_TEST(of_table_feature_prop_wildcards_OF_VERSION_1_3);
    RUN_TEST(of_table_feature_prop_write_actions_OF_VERSION_1_3);
    RUN_TEST(of_table_feature_prop_write_actions_miss_OF_VERSION_1_3);
    RUN_TEST(of_table_feature_prop_write_setfield_OF_VERSION_1_3);
    RUN_TEST(of_table_feature_prop_write_setfield_miss_OF_VERSION_1_3);
    RUN_TEST(of_table_features_OF_VERSION_1_3);
    RUN_TEST(of_table_stats_entry_OF_VERSION_1_3);
    RUN_TEST(of_uint32_OF_VERSION_1_3);
    RUN_TEST(of_uint8_OF_VERSION_1_3);
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
