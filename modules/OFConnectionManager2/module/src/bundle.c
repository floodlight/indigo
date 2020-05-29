/****************************************************************
 *
 *        Copyright 2014-2015,2017-2020, Arista Networks, Inc.
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
#include <indigo/error.h>

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
 *  - Validate messages on add
 */

#define SUBBUNDLE_UNSET (-1)

/* bundle task state stores all necessary info to process a bundle's msgs;
 * original bundle is freed immediately after task state is set up */
struct bundle_task_state {
    indigo_cxn_id_t cxn_id;
    of_object_t *reply;
    uint32_t id;                /* Bundle ID */
    uint32_t subbundle_count;   /* Number of subbundles */
    uint32_t cur_subbundle;     /* Currently processing this subbundle */
    uint32_t cur_offset;        /* Current position in current subbundle */
    bool cur_offset_is_pending; /* Current position is pending */
    subbundle_t *subbundles;    /* Array of pointers to subbundles */
};

static bundle_t *find_bundle(connection_t *cxn, uint32_t id);
static of_object_t *parse_message(uint8_t *data, of_object_storage_t *storage);
static void free_bundle(bundle_t *bundle);
static int compare_message(const void *_a, const void *_b);
static ind_soc_task_status_t bundle_task(void *cookie);

static indigo_cxn_bundle_comparator_t comparator;

/* by default, every bundle_add message goes into the same subbundle.
 * NOTE: an extra subbundle is allocated for barriers when a subbundle
 * designator is supplied */
static uint32_t num_subbundles_per_bundle = 1;
static indigo_cxn_subbundle_designator_t subbundle_designator;
static indigo_cxn_bundle_comparator_t *subbundle_comparators;

static indigo_cxn_subbundle_start_t *subbundle_starts;
static indigo_cxn_subbundle_finish_t *subbundle_finishes;

/* used by subbundle_compare_message to select subbundle comparator */
static uint32_t subbundle_comparator_idx;
/* forward declaration */
static int subbundle_compare_message(const void *_a, const void *_b);


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
        AIM_ASSERT(bundle->bytes == 0);
        AIM_ASSERT(bundle->subbundle_count == 0);
        AIM_ASSERT(bundle->subbundles == NULL);

        /* allocate subbundles */
        bundle->subbundle_count = num_subbundles_per_bundle;
        bundle->subbundles =
            aim_zmalloc(sizeof(subbundle_t)*bundle->subbundle_count);
        AIM_TRUE_OR_DIE(bundle->subbundles != NULL,
                        "no memory allocated for subbundles");
        AIM_LOG_VERBOSE("allocated %u subbundles", bundle->subbundle_count);
    } else if (ctrl_type == OFPBCT_CLOSE_REQUEST) {
        /* Ignored */
    } else if (ctrl_type == OFPBCT_COMMIT_REQUEST) {
        if (bundle == NULL) {
            err_code = OFPBFC_BAD_ID;
            goto error;
        }

        AIM_LOG_VERBOSE("bundle commit, %u messages", bundle->count);
        if (bundle->subbundle_count == 1) {
            if (comparator && !(bundle->flags & OFPBF_ORDERED)) {
                subbundle_t *subbundle = &bundle->subbundles[0];
                AIM_LOG_VERBOSE("qsort start");
                qsort(subbundle->msgs, subbundle->count,
                      sizeof(subbundle->msgs[0]), compare_message);
                AIM_LOG_VERBOSE("qsort complete");
            }
        } else {
            /* iterate over all subbundles, invoking supplied comparators;
             * skip the last subbundle, which contains barriers only */
            int i;
            for (i = 0; i < bundle->subbundle_count-1; i++) {
                if (subbundle_comparators && subbundle_comparators[i]) {
                    subbundle_t *subbundle = &bundle->subbundles[i];
                    subbundle_comparator_idx = i;
                    AIM_LOG_VERBOSE("sorting subbundle %d, %u messages",
                                    i, subbundle->count);
                    qsort(subbundle->msgs, subbundle->count,
                          sizeof(subbundle->msgs[0]),
                          subbundle_compare_message);
                    AIM_LOG_VERBOSE("sorting complete");
                }
            }
        }

        struct bundle_task_state *state = aim_zmalloc(sizeof(*state));
        state->cxn_id = cxn->cxn_id;
        state->reply = of_object_dup(obj);
        state->cur_offset_is_pending = false;
        of_bundle_ctrl_msg_bundle_ctrl_type_set(state->reply,
                                                OFPBCT_COMMIT_REPLY);
        state->id = bundle->id;
        state->subbundle_count = bundle->subbundle_count;
        state->cur_subbundle = SUBBUNDLE_UNSET;
        state->cur_offset = 0;
        state->subbundles = bundle->subbundles;

        if (ind_soc_task_register(bundle_task, state,
                                  IND_SOC_NORMAL_PRIORITY) < 0) {
            AIM_DIE("Failed to create long running task for bundle");
        }

        ind_cxn_pause(cxn);

        /* Transfer ownership of msgs to task */
        bundle->subbundles = NULL;
        bundle->subbundle_count = 0;

        free_bundle(bundle);

        /* Do not send reply yet */
        return;
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

    /* find the right subbundle */
    int idx;
    if (bundle->subbundle_count == 1) {
        idx = 0;
    } else {
        of_object_storage_t obj_storage;
        of_object_t *obj = parse_message(data.data, &obj_storage);
        if (obj->object_id == OF_BARRIER_REQUEST) {
            /* barriers are placed in the last subbundle */
            idx = bundle->subbundle_count - 1;
        } else {
            idx = subbundle_designator(obj);
            /* misdesignated messages are also placed in the last subbundle */
            if (idx > bundle->subbundle_count - 1) {
                idx = bundle->subbundle_count - 1;
            }
        }
    }
    subbundle_t *subbundle = &bundle->subbundles[idx];

    if (subbundle->count == subbundle->allocated) {
        /* Resize array */
        uint32_t new_allocated = (subbundle->allocated == 0 ? 1 : subbundle->allocated * 2);
        subbundle->msgs = aim_realloc(subbundle->msgs, sizeof(*subbundle->msgs) * new_allocated);
        subbundle->allocated = new_allocated;
    }

    subbundle->msgs[subbundle->count++] = aim_memdup(data.data, data.bytes);
    bundle->count++;
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
free_subbundle(subbundle_t *subbundle)
{
    int i;
    for (i = 0; i < subbundle->count; i++) {
        aim_free(subbundle->msgs[i]);
    }
    aim_free(subbundle->msgs);
}

static void
free_bundle(bundle_t *bundle)
{
    int i;
    for (i = 0; i < bundle->subbundle_count; i++) {
        free_subbundle(&bundle->subbundles[i]);
    }
    aim_free(bundle->subbundles);

    bundle->id = BUNDLE_ID_INVALID;
    bundle->subbundles = NULL;
    bundle->subbundle_count = 0;
    bundle->count = 0;
    bundle->bytes = 0;
    bundle->flags = 0;
}

/* see description in public header file */
indigo_error_t
indigo_cxn_subbundle_set(uint32_t num_subbundles,
                         indigo_cxn_subbundle_designator_t designator,
                         indigo_cxn_bundle_comparator_t comparators[])
{
    return indigo_cxn_subbundle_set2(num_subbundles,
                                     designator,
                                     comparators,
                                     NULL, NULL);
}

/* see description in public header file */
indigo_error_t
indigo_cxn_subbundle_set2(uint32_t num_subbundles,
                          indigo_cxn_subbundle_designator_t designator,
                          indigo_cxn_bundle_comparator_t comparators[],
                          indigo_cxn_subbundle_start_t starts[],
                          indigo_cxn_subbundle_finish_t finishes[])
{
    if (num_subbundles > OFCONNECTIONMANAGER_CONFIG_MAX_SUBBUNDLES+1) {
        AIM_LOG_ERROR("num_subbundles %u exceeds maximum %u",
                      num_subbundles,
                      OFCONNECTIONMANAGER_CONFIG_MAX_SUBBUNDLES+1);
        return INDIGO_ERROR_PARAM;
    }
    if ((num_subbundles > 0) && (designator == NULL)) {
        AIM_LOG_ERROR("num_subbundles > 0, but designator == NULL");
        return INDIGO_ERROR_PARAM;
    }
    /* one more subbundle for barriers */
    num_subbundles_per_bundle = num_subbundles + 1;

    subbundle_designator = designator;
    subbundle_comparators = comparators;

    subbundle_starts = starts;
    subbundle_finishes = finishes;

    return INDIGO_ERROR_NONE;
}

/* WARNING: uses global variable to select the right subbundle comparator */
static int
subbundle_compare_message(const void *_a, const void *_b)
{
    AIM_ASSERT((subbundle_comparators != NULL) &&
               (subbundle_comparator_idx < num_subbundles_per_bundle));

    of_object_storage_t obj_a_storage;
    of_object_t *obj_a = parse_message(*(uint8_t * const *)_a, &obj_a_storage);

    of_object_storage_t obj_b_storage;
    of_object_t *obj_b = parse_message(*(uint8_t * const *)_b, &obj_b_storage);

    if (obj_a == NULL || obj_b == NULL) {
        return 0;
    }

    return subbundle_comparators[subbundle_comparator_idx](obj_a, obj_b);
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

    if (obj_a->object_id == OF_BARRIER_REQUEST) {
        /* Barriers go to the end of the bundle */
        return 1;
    }

    return comparator(obj_a, obj_b);
}

static void
invoke_subbundle_start(indigo_cxn_id_t cxn_id, uint32_t subbundle_idx)
{
    /* do not invoke for last subbundle (only contains barriers) */
    if (subbundle_starts && (subbundle_idx < num_subbundles_per_bundle-1) &&
        subbundle_starts[subbundle_idx]) {
        (*subbundle_starts[subbundle_idx])(cxn_id, subbundle_idx);
    }
}

static void
invoke_subbundle_finish(indigo_cxn_id_t cxn_id, uint32_t subbundle_idx)
{
    /* do not invoke for last subbundle (only contains barriers) */
    if (subbundle_finishes && (subbundle_idx < num_subbundles_per_bundle-1) &&
        subbundle_finishes[subbundle_idx]) {
        (*subbundle_finishes[subbundle_idx])(cxn_id, subbundle_idx);
    }
}

static ind_soc_task_status_t
bundle_task(void *cookie)
{
    struct bundle_task_state *state = cookie;

    connection_t *cxn = ind_cxn_id_to_connection(state->cxn_id);

    if (ind_cxn_bundle_task_should_yield(cxn)) {
        /* wait for a async operation before process next subbundle
         * the async operation can be a single request or
         * a task spawn by bundle_task
         */
        return IND_SOC_TASK_CONTINUE;
    }

    /* corner case: invoke start for first subbundle */
    if (state->cur_subbundle == SUBBUNDLE_UNSET) {
        state->cur_subbundle = 0;
        invoke_subbundle_start(state->cxn_id, state->cur_subbundle);
    }

    while (state->cur_subbundle < state->subbundle_count) {
        subbundle_t *subbundle = &state->subbundles[state->cur_subbundle];
        /* iterate through the current subbundle */
        while (state->cur_offset < subbundle->count) {
            if (cxn) {

                AIM_LOG_TRACE("bundle_task cur_offset=%u is_pending %d\n",
                              state->cur_offset, state->cur_offset_is_pending);
                if (state->cur_offset_is_pending == false) {
                    /* The task is ok to process message at cur_offset.
                     * The cur_offset is in clear status. */
                    of_object_storage_t obj_storage;
                    of_object_t *obj =
                        parse_message(subbundle->msgs[state->cur_offset],
                                      &obj_storage);
                    if (obj) {
                        indigo_error_t rv;
                        rv = ind_cxn_process_message(cxn, obj);
                        if (rv == INDIGO_ERROR_PENDING) {
                            /* The message is an async operation
                             * Mark the messsage at cur_offset as pending.
                             * The pending status will be cleared in the next
                             * runnable cycle.
                             */
                            state->cur_offset_is_pending = true;
                            ind_cxn_block_async_op(cxn);
                            AIM_LOG_TRACE("bundle_task cur_offset=%u pending\n",
                                          state->cur_offset);
                            return IND_SOC_TASK_CONTINUE;
                        }
                    }
                } else {
                    /* This subbundle msg is done. Clear its pending status.
                     * Fall through to free it.
                     */
                    state->cur_offset_is_pending = false;
                    AIM_LOG_TRACE("bundle_task cur_offset=%u was pending, now done\n",
                                  state->cur_offset);
                }
            } else {
                /* Connection went away. Drop remaining messages.
                 * Clear the cur_offset_pending status anyway. */
                state->cur_offset_is_pending = false; 
            }

            aim_free(subbundle->msgs[state->cur_offset]);
            subbundle->msgs[state->cur_offset] = NULL;
            state->cur_offset++;

            if (ind_soc_should_yield()) {
                return IND_SOC_TASK_CONTINUE;
            }
        }
        /* clean up subbundle */
        aim_free(subbundle->msgs);
        subbundle->msgs = NULL;
        /* invoke subbundle finish before moving onto next subbundle */
        invoke_subbundle_finish(state->cxn_id, state->cur_subbundle);
        /* move to the next subbundle */
        state->cur_subbundle++;
        state->cur_offset = 0;
        /* invoke subbundle start for next subbundle */
        invoke_subbundle_start(state->cxn_id, state->cur_subbundle);
    }

    if (cxn) {
        indigo_cxn_send_controller_message(cxn->cxn_id, state->reply);
    } else {
        of_object_delete(state->reply);
    }

    aim_free(state->subbundles);
    aim_free(state);

    ind_cxn_resume(cxn);

    return IND_SOC_TASK_FINISHED;
}
