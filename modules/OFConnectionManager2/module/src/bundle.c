/****************************************************************
 *
 *        Copyright 2014, Big Switch Networks, Inc.
 *
 * Licensed under the Eclipse Public License, Version 1.0 (the
 * "License"); you may not use this file except in compliance
 * with the License. You may obtain a copy of the License at
 *
 *        http://www.eclipse.org/legal/epl-v10.html
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
 * either express or implied. See the License for the specific
 * language governing permissions and limitations under the
 * License.
 *
 ****************************************************************/

#include "ofconnectionmanager_log.h"

#include <string.h>
#include <errno.h>
#include <unistd.h>

#include "cxn_instance.h"
#include "ofconnectionmanager_int.h"

#include <SocketManager/socketmanager.h>
#include <OFConnectionManager/ofconnectionmanager.h>

#include <indigo/memory.h>
#include <indigo/assert.h>

/*
 * Message bundles
 *
 * This feature allows the controller to queue up messages to be processed by the
 * switch. This is useful for two reasons: first, the switch won't be left in an
 * intermediate state if the controller disconnects while pushing flows; and
 * second, the controller can send commit messages to every switch at close to the
 * same instant, minimizing the amount of time the network is in an inconsistent
 * state.
 *
 * This doesn't yet implement the full semantics of OF 1.4 bundles. In particular,
 * a commit is not rolled back if executing a message fails.
 *
 * Still left to do:
 *  - Commit in a long-running task
 *  - Validate messages on add
 */

static bundle_t *find_bundle(connection_t *cxn, uint32_t id);
static of_object_t *parse_message(uint8_t *data, of_object_storage_t *storage);
static void free_bundle(bundle_t *bundle);
static int compare_message(const void *_a, const void *_b);

static indigo_cxn_bundle_comparator_t comparator;

void
ind_cxn_bundle_init(connection_t *cxn)
{
    memset(&cxn->bundles, 0, sizeof(cxn->bundles));

    int i;
    for (i = 0; i < MAX_BUNDLES; i++) {
        cxn->bundles[i].id = BUNDLE_ID_INVALID;
    }
}

void
ind_cxn_bundle_cleanup(connection_t *cxn)
{
    int i;
    for (i = 0; i < MAX_BUNDLES; i++) {
        if (cxn->bundles[i].id != BUNDLE_ID_INVALID) {
            free_bundle(&cxn->bundles[i]);
        }
    }
}

void
ind_cxn_bundle_ctrl_handle(connection_t *cxn, of_object_t *obj)
{
    uint32_t bundle_id;
    uint16_t ctrl_type;
    uint16_t flags;
    uint16_t err_code = OFPBFC_UNKNOWN;

    of_bundle_ctrl_msg_bundle_id_get(obj, &bundle_id);
    of_bundle_ctrl_msg_bundle_ctrl_type_get(obj, &ctrl_type);
    of_bundle_ctrl_msg_flags_get(obj, &flags);

    bundle_t *bundle = find_bundle(cxn, bundle_id);

    if (ctrl_type == OFPBCT_OPEN_REQUEST) {
        if (bundle != NULL) {
            err_code = OFPBFC_BUNDLE_EXIST;
            goto error;
        }

        bundle = find_bundle(cxn, BUNDLE_ID_INVALID);
        if (bundle == NULL) {
            err_code = OFPBFC_OUT_OF_BUNDLES;
            goto error;
        }

        bundle->id = bundle_id;
        bundle->flags = flags;
        AIM_ASSERT(bundle->count == 0);
        AIM_ASSERT(bundle->allocated == 0);
        AIM_ASSERT(bundle->bytes == 0);
        AIM_ASSERT(bundle->msgs == NULL);
    } else if (ctrl_type == OFPBCT_CLOSE_REQUEST) {
        /* Ignored */
    } else if (ctrl_type == OFPBCT_COMMIT_REQUEST) {
        if (bundle == NULL) {
            err_code = OFPBFC_BAD_ID;
            goto error;
        }

        if (comparator && !(bundle->flags & OFPBF_ORDERED)) {
            qsort(bundle->msgs, bundle->count, sizeof(bundle->msgs[0]), compare_message);
        }

        /* TODO long running task */

        int i;
        for (i = 0; i < bundle->count; i++) {
            of_object_storage_t obj_storage;
            of_object_t *obj = parse_message(bundle->msgs[i], &obj_storage);

            ind_cxn_process_message(cxn, obj);

            free(bundle->msgs[i]);
            bundle->msgs[i] = NULL;
        }

        free_bundle(bundle);
    } else if (ctrl_type == OFPBCT_DISCARD_REQUEST) {
        if (bundle == NULL) {
            err_code = OFPBFC_BAD_ID;
            goto error;
        }

        free_bundle(bundle);
    } else {
        err_code = OFPBFC_BAD_TYPE;
        goto error;
    }

    /* Send reply */
    of_object_t *reply = of_object_dup(obj);
    /* Derive the reply subtype from the request */
    of_bundle_ctrl_msg_bundle_ctrl_type_set(reply, ctrl_type+1);
    indigo_cxn_send_controller_message(cxn->cxn_id, reply);
    return;

error:
    indigo_cxn_send_error_reply(
        cxn->cxn_id, obj,
        OF_ERROR_TYPE_BUNDLE_FAILED,
        err_code);
}

void
ind_cxn_bundle_add_handle(connection_t *cxn, of_object_t *obj)
{
    uint32_t bundle_id;
    uint16_t flags;
    of_octets_t data;

    of_bundle_add_msg_bundle_id_get(obj, &bundle_id);
    of_bundle_add_msg_flags_get(obj, &flags);
    of_bundle_add_msg_data_get(obj, &data);

    bundle_t *bundle = find_bundle(cxn, bundle_id);
    if (bundle == NULL) {
        indigo_cxn_send_error_reply(
            cxn->cxn_id, obj,
            OF_ERROR_TYPE_BUNDLE_FAILED,
            OFPBFC_BAD_ID);
        return;
    }

    /* Validate length */
    if (data.bytes < OF_MESSAGE_HEADER_LENGTH || data.bytes != of_message_length_get(data.data)) {
        indigo_cxn_send_error_reply(
            cxn->cxn_id, obj,
            OF_ERROR_TYPE_BUNDLE_FAILED,
            OFPBFC_MSG_BAD_LEN);
        AIM_LOG_WARN("Inconsistent bundled message length", bundle->id);
        return;
    }

    /* Limit number of messages in the bundle */
    if (bundle->count >= OFCONNECTIONMANAGER_CONFIG_MAX_BUNDLE_MSGS) {
        indigo_cxn_send_error_reply(
            cxn->cxn_id, obj,
            OF_ERROR_TYPE_BUNDLE_FAILED,
            OFPBFC_MSG_TOO_MANY);
        AIM_LOG_WARN("Exceeded maximum number (%u) of messages in bundle %u", OFCONNECTIONMANAGER_CONFIG_MAX_BUNDLE_MSGS, bundle->id);
        return;
    }

    /* Limit amount of memory used by the bundle */
    if ((bundle->bytes + data.bytes) > OFCONNECTIONMANAGER_CONFIG_MAX_BUNDLE_BYTES) {
        indigo_cxn_send_error_reply(
            cxn->cxn_id, obj,
            OF_ERROR_TYPE_BUNDLE_FAILED,
            OFPBFC_MSG_TOO_MANY);
        AIM_LOG_WARN("Exceeded maximum size (%u bytes) of messages in bundle %u", OFCONNECTIONMANAGER_CONFIG_MAX_BUNDLE_BYTES, bundle->id);
        return;
    }

    if (bundle->count == bundle->allocated) {
        /* Resize array */
        uint32_t new_allocated = (bundle->allocated == 0 ? 1 : bundle->allocated * 2);
        bundle->msgs = aim_realloc(bundle->msgs, sizeof(*bundle->msgs) * new_allocated);
        bundle->allocated = new_allocated;
    }

    bundle->msgs[bundle->count++] = aim_memdup(data.data, data.bytes);
    bundle->bytes += data.bytes;
}

static bundle_t *
find_bundle(connection_t *cxn, uint32_t id)
{
    int i;
    for (i = 0; i < MAX_BUNDLES; i++) {
        if (cxn->bundles[i].id == id) {
            return &cxn->bundles[i];
        }
    }

    return NULL;
}

static of_object_t *
parse_message(uint8_t *data, of_object_storage_t *storage)
{
    int len = of_message_length_get(data);
    return of_object_new_from_message_preallocated(storage, data, len);
}

static void
free_bundle(bundle_t *bundle)
{
    int i;
    for (i = 0; i < bundle->count; i++) {
        free(bundle->msgs[i]);
    }

    free(bundle->msgs);

    bundle->id = BUNDLE_ID_INVALID;
    bundle->msgs = NULL;
    bundle->count = 0;
    bundle->allocated = 0;
    bundle->bytes = 0;
    bundle->flags = 0;

}

void
indigo_cxn_bundle_comparator_set(indigo_cxn_bundle_comparator_t fn)
{
    comparator = fn;
}

static int
compare_message(const void *_a, const void *_b)
{
    AIM_ASSERT(comparator != NULL);

    of_object_storage_t obj_a_storage;
    of_object_t *obj_a = parse_message(*(uint8_t * const *)_a, &obj_a_storage);

    of_object_storage_t obj_b_storage;
    of_object_t *obj_b = parse_message(*(uint8_t * const *)_b, &obj_b_storage);

    if (obj_a == NULL || obj_b == NULL) {
        return 0;
    }

    return comparator(obj_a, obj_b);
}
