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

static bundle_t *find_bundle(connection_t *cxn, uint32_t id);
static of_object_t *parse_message(uint8_t *data, of_object_storage_t *storage);

void
ind_cxn_bundle_init(connection_t *cxn)
{
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
            cxn->bundles[i].id = BUNDLE_ID_INVALID;
            biglist_free_all(cxn->bundles[i].head, free);
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
        bundle->head = NULL;
    } else if (ctrl_type == OFPBCT_CLOSE_REQUEST) {
        /* Ignored */
    } else if (ctrl_type == OFPBCT_COMMIT_REQUEST) {
        if (bundle == NULL) {
            err_code = OFPBFC_BAD_ID;
            goto error;
        }

        /* TODO long running task */

        while (bundle->head) {
            /* Pop first message from the list */
            void *data = bundle->head->data;
            bundle->head = biglist_remove_link_free(bundle->head, bundle->head);

            of_object_storage_t obj_storage;
            of_object_t *obj = parse_message(data, &obj_storage);

            ind_cxn_process_message(cxn, obj);

            free(data);
        }

        AIM_ASSERT(bundle->head == NULL);
        bundle->id = BUNDLE_ID_INVALID;
    } else if (ctrl_type == OFPBCT_DISCARD_REQUEST) {
        if (bundle == NULL) {
            err_code = OFPBFC_BAD_ID;
            goto error;
        }

        bundle->id = BUNDLE_ID_INVALID;
        biglist_free_all(bundle->head, free);
    } else {
        err_code = OFPBFC_BAD_TYPE;
        goto error;
    }

    /* Send reply */
    of_object_t *reply = of_object_dup(obj);
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

    bundle->head = biglist_append(bundle->head, aim_memdup(data.data, data.bytes));
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
