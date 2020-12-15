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

/* bundle task state stores all necessary info to process a bundle's msgs (objs);
 * original bundle is freed immediately after task state is set up
 * Async operation pending can happend within a subbundle.
 */
struct bundle_task_state {
    indigo_cxn_id_t cxn_id;
    of_object_t *reply;
    uint32_t id;                  /* Bundle ID */
    uint32_t subbundle_count;     /* Number of subbundles */
    uint32_t cur_subbundle;       /* Currently processing this subbundle */
    uint32_t cur_offset;          /* Current position in current subbundle */
    bool cur_subbundle_is_paused; /* Current subbundle is pending on its outstanding operation(s). 
                                   * If this flag is set, then the subbundle should wait for
                                   * all the outstanding operations before processing next
                                   * message in the current subbundle.
                                   * If this flag is NOT set, then the subbundle is ok to process
                                   * next message in the subbundle (ignore the outstanding count.)
                                   * This flag should be set before moving on next subbundle if
                                   * the current subbundle has any outstanding operation so that the
                                   * bundle task will be blocked until all outstanding operation(s)
                                   * have been cleared.
                                   */
    subbundle_t *subbundles;       /* Array of pointers to subbundles */
    bool is_aborted;               /* bundle task is aborted due to connection loss */
};

static bundle_t *find_bundle(connection_t *cxn, uint32_t id);
static of_object_t *message_to_obj(uint8_t *data);
static void free_bundle(bundle_t *bundle);
static int compare_obj(const void *_a, const void *_b);
static ind_soc_task_status_t bundle_task(void *cookie);

static indigo_cxn_bundle_comparator_t comparator;

/* by default, every bundle_add message goes into the same subbundle.
 * NOTE: an extra subbundle is allocated for barriers when a subbundle
 * designator is supplied */
static uint32_t num_subbundles_per_bundle = 1;
static indigo_cxn_subbundle_designator_t subbundle_designator;
static indigo_cxn_bundle_comparator_t *subbundle_comparators;

static indigo_cxn_subbundle_start_t *subbundle_starts2;
static indigo_cxn_subbundle_finish_t *subbundle_finishes2;
static indigo_cxn_subbundle_start3_t *subbundle_starts3;
static indigo_cxn_subbundle_finish3_t *subbundle_finishes3;

/* used by subbundle_compare_message to select subbundle comparator */
static uint32_t subbundle_comparator_idx;
/* forward declaration */
static int subbundle_compare_obj(const void *_a, const void *_b);

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
                qsort(subbundle->objs, subbundle->count,
                      sizeof(subbundle->objs[0]), compare_obj);
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
                    qsort(subbundle->objs, subbundle->count,
                          sizeof(subbundle->objs[0]),
                          subbundle_compare_obj);
                    AIM_LOG_VERBOSE("sorting complete");
                }
            }
        }

        struct bundle_task_state *state = aim_zmalloc(sizeof(*state));
        state->cxn_id = cxn->cxn_id;
        state->reply = of_object_dup(obj);
        state->cur_subbundle_is_paused = false;
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
        AIM_LOG_WARN("Inconsistent bundled message length in bundle %u", bundle->id);
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
    void *msg = aim_memdup(data.data, data.bytes);
    of_object_t *msg_obj = message_to_obj(msg);

    if (bundle->subbundle_count == 1) {
        idx = 0;
    } else {
        if (msg_obj->object_id == OF_BARRIER_REQUEST) {
            /* barriers are placed in the last subbundle */
            idx = bundle->subbundle_count - 1;
        } else {
            idx = subbundle_designator(msg_obj);
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
        subbundle->objs = aim_realloc(subbundle->objs, sizeof(*subbundle->objs) * new_allocated);
        subbundle->allocated = new_allocated;
    }

    subbundle->objs[subbundle->count++] = msg_obj; 
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
message_to_obj(uint8_t *data)
{
    int len = of_message_length_get(data);
    return of_object_new_from_message(data, len);
}


static void
free_subbundle(subbundle_t *subbundle)
{
    int i;
    for (i = 0; i < subbundle->count; i++) {
        of_object_delete(subbundle->objs[i]);
    }
    aim_free(subbundle->objs);
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

    subbundle_starts2 = starts;
    subbundle_finishes2 = finishes;

    return INDIGO_ERROR_NONE;
}

/* see description in public header file */
indigo_error_t
indigo_cxn_subbundle_set3(uint32_t num_subbundles,
                          indigo_cxn_subbundle_designator_t designator,
                          indigo_cxn_bundle_comparator_t comparators[],
                          indigo_cxn_subbundle_start3_t starts[],
                          indigo_cxn_subbundle_finish3_t finishes[])
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

    subbundle_starts3 = starts;
    subbundle_finishes3 = finishes;

    return INDIGO_ERROR_NONE;
}

/* WARNING: uses global variable to select the right subbundle comparator */
static int
subbundle_compare_obj(const void *_a, const void *_b)
{
    AIM_ASSERT((subbundle_comparators != NULL) &&
               (subbundle_comparator_idx < num_subbundles_per_bundle));

    of_object_t *obj_a = *((of_object_t * const *)_a);

    of_object_t *obj_b = *((of_object_t * const *)_b);

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
compare_obj(const void *_a, const void *_b)
{
    AIM_ASSERT(comparator != NULL);

    of_object_t *obj_a = *((of_object_t * const *)_a);

    of_object_t *obj_b = *((of_object_t * const *)_b);

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
invoke_subbundle_start(indigo_cxn_id_t cxn_id, indigo_cxn_subbundle_info_t *subbundle_info)
{
    uint32_t subbundle_idx = subbundle_info->subbundle_idx;
    /* do not invoke for last subbundle (only contains barriers) */
    if (subbundle_starts3) {
        if ((subbundle_idx < num_subbundles_per_bundle-1) &&
            subbundle_starts3[subbundle_idx]) {
            if (subbundle_info->total_msg_count) {
                (*subbundle_starts3[subbundle_idx])(cxn_id, subbundle_info);
            }
        }
    } else if (subbundle_starts2) {
        if ((subbundle_idx < num_subbundles_per_bundle-1) &&
            subbundle_starts2[subbundle_idx]) {
            (*subbundle_starts2[subbundle_idx])(cxn_id, subbundle_idx);
        }
    }
}

static void
invoke_subbundle_finish(indigo_cxn_id_t cxn_id, indigo_cxn_subbundle_info_t *subbundle_info)
{
    uint32_t subbundle_idx = subbundle_info->subbundle_idx;
    /* do not invoke for last subbundle (only contains barriers) */
    if (subbundle_finishes3) {
        if ((subbundle_idx < num_subbundles_per_bundle-1) &&
            subbundle_finishes3[subbundle_idx]) {
            if (subbundle_info->total_msg_count) {
                (*subbundle_finishes3[subbundle_idx])(cxn_id, subbundle_info);
            }
        }
    } else if (subbundle_finishes2) {
        if ((subbundle_idx < num_subbundles_per_bundle-1) &&
            subbundle_finishes2[subbundle_idx]) {
            (*subbundle_finishes2[subbundle_idx])(cxn_id, subbundle_idx);
        }
    }
}

static ind_soc_task_status_t
bundle_task(void *cookie)
{
    struct bundle_task_state *state = cookie;

    connection_t *cxn = ind_cxn_id_to_connection(state->cxn_id);
    indigo_cxn_subbundle_info_t subbundle_info;

    /* Check whether the bundle task operation should be paused.
     * It will check the pending operations from previous connections.
     * Note: If the existing connection is gone, then just let the bundle task
     *       continue its work - clean up all the subbundles.
     */
    if (ind_cxn_bundle_task_should_yield(cxn)) {
        return IND_SOC_TASK_CONTINUE;
    }

    /* If bundle state allows next message, then don't care how many
     * pending operations. This case can be that the subbundle allows next msg to
     * be processed.
     * Otherwise, bundle state should wait until no pending operation.
     * Note: next subbundle cannot start until the previous subbundle has no pending.
     */
    if (state->cur_subbundle_is_paused == true) {
        if (ind_cxn_subbundle_should_yield(cxn)) {
            return IND_SOC_TASK_CONTINUE;
        }
        state->cur_subbundle_is_paused = false;
    }

    /* state->cur_msg_is_paused == false or cxn is NULL */
    
    /* corner case: invoke start for first subbundle */
    if (state->cur_subbundle == SUBBUNDLE_UNSET) {
        state->cur_subbundle = 0;
        state->is_aborted = false;
        subbundle_info.subbundle_idx = state->cur_subbundle;
        subbundle_info.total_msg_count = state->subbundles[state->cur_subbundle].count;
        subbundle_info.is_aborted = false;
        invoke_subbundle_start(state->cxn_id, &subbundle_info);
    }

    while (state->cur_subbundle < state->subbundle_count) {
        subbundle_t *subbundle = &state->subbundles[state->cur_subbundle];

        /* iterate through the current subbundle */
        while (state->cur_offset < subbundle->count) {
            /* cxn is gone or outstanding operations have been done */
            if (cxn) {
                AIM_LOG_TRACE("cur_subbundle=%u cur_offset=%u is_paused=%d",
                              state->cur_subbundle, state->cur_offset,
                              state->cur_subbundle_is_paused);

                /* The task is ok to process message at cur_offset.
                 * The cur_offset is in clear status. */
                of_object_t *obj = subbundle->objs[state->cur_offset];
                if (obj) {
                    indigo_error_t rv;
                    rv = ind_cxn_process_message(cxn, obj);
                    if (rv == INDIGO_ERROR_PENDING) {
                        /* The message is an async operation. Set pause flag. */
                        state->cur_subbundle_is_paused = true; 
                        AIM_LOG_TRACE("bundle_task cur_offset=%u pending\n",
                                      state->cur_offset);
                    }
                    /* If rv is OK, ERROR, or CONTINUE, then allow next message.
                     * The obj should have been duplicated in the OFStateManager
                     * or driver. It is safe to free the obj.
                     */
                }
            } else { /* if (cxn) */
                /* Connection went away:
                 * All the remaining subbundles should be flushed away.
                 * Free the cur_offset and remaining messages.
                 */
                state->cur_subbundle_is_paused = false;
                state->is_aborted = true;
            } /* if (cxn) */

            of_object_delete(subbundle->objs[state->cur_offset]); 
            subbundle->objs[state->cur_offset] = NULL;
            state->cur_offset++;

            if (ind_soc_should_yield() || state->cur_subbundle_is_paused) {
                return IND_SOC_TASK_CONTINUE;
            }
        }
        /* clean up subbundle */
        aim_free(subbundle->objs);
        subbundle->objs = NULL;
        /* invoke subbundle finish before moving onto next subbundle */
        subbundle_info.subbundle_idx = state->cur_subbundle;
        subbundle_info.total_msg_count = state->subbundles[state->cur_subbundle].count;
        subbundle_info.is_aborted = state->is_aborted;
        invoke_subbundle_finish(state->cxn_id, &subbundle_info);
        /* move to the next subbundle */
        state->cur_subbundle++;
        state->cur_offset = 0;
        if (state->cur_subbundle < state->subbundle_count) {
            /* invoke subbundle start for next subbundle */
            subbundle_info.subbundle_idx = state->cur_subbundle;
            subbundle_info.total_msg_count = state->subbundles[state->cur_subbundle].count;
            subbundle_info.is_aborted = state->is_aborted;
            invoke_subbundle_start(state->cxn_id, &subbundle_info);
        }
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
