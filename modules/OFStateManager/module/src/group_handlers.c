/****************************************************************
 *
 *        Copyright 2013, Big Switch Networks, Inc.
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

/**
 * @file
 * @brief OpenFlow message handlers for group messages
 *
 * See detailed documentation in the Indigo architecture headers.
 */

#include "ofstatemanager_log.h"

#include <OFStateManager/ofstatemanager_config.h>
#include <OFConnectionManager/ofconnectionmanager.h>
#include <indigo/indigo.h>
#include <indigo/of_state_manager.h>
#include <indigo/forwarding.h>
#include <loci/loci.h>
#include "ofstatemanager_decs.h"
#include "ofstatemanager_int.h"
#include "handlers.h"
#include <BigHash/bighash.h>

typedef struct ind_core_group_table_s {
    of_table_name_t name;
    void *priv;
    const indigo_core_group_table_ops_t *ops;
} ind_core_group_table_t;

typedef struct ind_core_group_s {
    bighash_entry_t hash_entry;
    uint32_t id;
    uint32_t type;
    of_list_bucket_t *buckets;
    indigo_time_t creation_time;
    void *priv;
} ind_core_group_t;

#define TEMPLATE_NAME group_hashtable
#define TEMPLATE_OBJ_TYPE ind_core_group_t
#define TEMPLATE_KEY_FIELD id
#define TEMPLATE_ENTRY_FIELD hash_entry
#include <BigHash/bighash_template.h>

static ind_core_group_table_t *group_table_for_id(uint32_t group_id);

static bighash_table_t *ind_core_group_hashtable;
static ind_core_group_table_t *ind_core_group_tables[256];

static ind_core_group_t *
ind_core_group_lookup(uint32_t id)
{
    return group_hashtable_first(ind_core_group_hashtable, &id);
}

static void
ind_core_group_delete_one(ind_core_group_t *group, indigo_cxn_id_t cxn_id)
{
    ind_core_group_table_t *table = group_table_for_id(group->id);
    if (table) {
        table->ops->entry_delete(table->priv, cxn_id, group->priv);
    } else {
        indigo_fwd_group_delete(group->id);
    }
    of_object_delete(group->buckets);
    bighash_remove(ind_core_group_hashtable, &group->hash_entry);
    aim_free(group);
}

void
ind_core_group_add_handler(of_object_t *_obj, indigo_cxn_id_t cxn_id)
{
    of_group_add_t *obj = _obj;
    uint32_t xid;
    uint8_t type;
    uint32_t id;
    of_list_bucket_t buckets;
    ind_core_group_t *group = NULL;
    uint16_t err_type = OF_ERROR_TYPE_GROUP_MOD_FAILED;
    uint16_t err_code = OF_GROUP_MOD_FAILED_EPERM;
    indigo_error_t result;
    void *entry_priv = NULL;

    of_group_add_xid_get(obj, &xid);
    of_group_add_group_type_get(obj, &type);
    of_group_add_group_id_get(obj, &id);
    of_group_add_buckets_bind(obj, &buckets);

    if (id <= OF_GROUP_MAX) {
        group = ind_core_group_lookup(id);
    }

    if (group != NULL) {
        err_code = OF_GROUP_MOD_FAILED_GROUP_EXISTS;
        goto error;
    } else if (id > OF_GROUP_MAX) {
        err_code = OF_GROUP_MOD_FAILED_INVALID_GROUP;
        goto error;
    }

    ind_core_group_table_t *table = group_table_for_id(id);
    if (table) {
        result = table->ops->entry_create(table->priv, cxn_id, id, type, &buckets, &entry_priv);
    } else {
        result = indigo_fwd_group_add(id, type, &buckets);
    }

    if (result < 0) {
        err_code = OF_GROUP_MOD_FAILED_INVALID_GROUP;
        goto error;
    }

    group = aim_malloc(sizeof(*group));
    group->id = id;
    group->type = type;
    group->buckets = of_object_dup(&buckets);
    AIM_TRUE_OR_DIE(group->buckets != NULL);
    group->creation_time = INDIGO_CURRENT_TIME;
    group->priv = entry_priv;

    group_hashtable_insert(ind_core_group_hashtable, group);

    return;

error:
    indigo_cxn_send_error_reply(cxn_id, obj, err_type, err_code);
}

void
ind_core_group_modify_handler(of_object_t *_obj, indigo_cxn_id_t cxn_id)
{
    of_group_mod_t *obj = _obj;
    uint32_t xid;
    uint8_t type;
    uint32_t id;
    of_list_bucket_t buckets;
    ind_core_group_t *group = NULL;
    uint16_t err_type = OF_ERROR_TYPE_GROUP_MOD_FAILED;
    uint16_t err_code = OF_GROUP_MOD_FAILED_EPERM;
    indigo_error_t result;

    of_group_modify_xid_get(obj, &xid);
    of_group_modify_group_type_get(obj, &type);
    of_group_modify_group_id_get(obj, &id);
    of_group_modify_buckets_bind(obj, &buckets);

    if (id <= OF_GROUP_MAX) {
        group = ind_core_group_lookup(id);
    }

    if (group == NULL) {
        err_code = OF_GROUP_MOD_FAILED_UNKNOWN_GROUP;
        goto error;
    }

    ind_core_group_table_t *table = group_table_for_id(id);
    if (group->type == type) {
        if (table) {
            result = table->ops->entry_modify(table->priv, cxn_id, group->priv, &buckets);
        } else {
            result = indigo_fwd_group_modify(id, &buckets);
        }
    } else {
        if (table) {
            (void) table->ops->entry_delete(table->priv, cxn_id, group->priv);
            result = table->ops->entry_create(table->priv, cxn_id, id, type, &buckets, &group->priv);
        } else {
            indigo_fwd_group_delete(id);
            result = indigo_fwd_group_add(id, type, &buckets);
        }
    }

    if (result < 0) {
        err_code = OF_GROUP_MOD_FAILED_INVALID_GROUP;
        goto error;
    }

    group->type = type;
    of_object_delete(group->buckets);
    group->buckets = of_object_dup(&buckets);
    AIM_TRUE_OR_DIE(group->buckets != NULL);

    return;

error:
    indigo_cxn_send_error_reply(cxn_id, obj, err_type, err_code);
}

void
ind_core_group_delete_handler(of_object_t *_obj, indigo_cxn_id_t cxn_id)
{
    of_group_delete_t *obj = _obj;
    uint32_t xid;
    uint32_t id;
    ind_core_group_t *group = NULL;
    uint16_t err_type = OF_ERROR_TYPE_GROUP_MOD_FAILED;
    uint16_t err_code = OF_GROUP_MOD_FAILED_EPERM;

    of_group_delete_xid_get(obj, &xid);
    of_group_delete_group_id_get(obj, &id);

    if (id <= OF_GROUP_MAX) {
        group = ind_core_group_lookup(id);
    }

    if (id == OF_GROUP_ALL) {
        bighash_iter_t iter;
        for (group = bighash_iter_start(ind_core_group_hashtable, &iter);
                group; group = bighash_iter_next(&iter)) {
            ind_core_group_delete_one(group, cxn_id);
        }
    } else if (group != NULL) {
        ind_core_group_delete_one(group, cxn_id);
    } else if (id > OF_GROUP_MAX) {
        err_code = OF_GROUP_MOD_FAILED_INVALID_GROUP;
        goto error;
    }

    return;

error:
    indigo_cxn_send_error_reply(cxn_id, obj, err_type, err_code);
}

static void
ind_core_group_stats_entry_populate(of_group_stats_entry_t *entry,
                                    ind_core_group_t *group,
                                    indigo_time_t current_time)
{
    uint32_t duration_sec, duration_nsec;

    of_group_stats_entry_group_id_set(entry, group->id);

    calc_duration(current_time, group->creation_time, &duration_sec, &duration_nsec);
    of_group_stats_entry_duration_sec_set(entry, duration_sec);
    of_group_stats_entry_duration_nsec_set(entry, duration_nsec);

    ind_core_group_table_t *table = group_table_for_id(group->id);
    if (table) {
        table->ops->entry_stats_get(table->priv, group->priv, entry);
    } else {
        indigo_fwd_group_stats_get(group->id, entry);
    }
}

/* TODO segment long replies */
void
ind_core_group_stats_request_handler(of_object_t *_obj,
                                     indigo_cxn_id_t cxn_id)
{
    of_group_stats_request_t *obj = _obj;
    of_group_stats_reply_t *reply;
    of_list_group_stats_entry_t entries;
    of_group_stats_entry_t *entry;
    uint32_t xid;
    uint32_t id;
    indigo_time_t current_time = INDIGO_CURRENT_TIME;

    of_group_stats_request_group_id_get(obj, &id);

    reply = of_group_stats_reply_new(obj->version);
    AIM_TRUE_OR_DIE(reply != NULL);

    of_group_stats_request_xid_get(obj, &xid);
    of_group_stats_reply_xid_set(reply, xid);
    of_group_stats_reply_entries_bind(reply, &entries);

    entry = of_group_stats_entry_new(entries.version);
    AIM_TRUE_OR_DIE(entry != NULL);

    if (id == OF_GROUP_ALL) {
        bighash_iter_t iter;
        ind_core_group_t *group;
        for (group = bighash_iter_start(ind_core_group_hashtable, &iter);
                group; group = bighash_iter_next(&iter)) {
            ind_core_group_stats_entry_populate(entry, group, current_time);

            if (of_list_append(&entries, entry) < 0) {
                break;
            }

            /* HACK unable to truncate existing object */
            of_object_delete(entry);
            entry = of_group_stats_entry_new(entries.version);
            AIM_TRUE_OR_DIE(entry != NULL);
        }
    } else if (id <= OF_GROUP_MAX) {
        ind_core_group_t *group = ind_core_group_lookup(id);
        if (group != NULL) {
            ind_core_group_stats_entry_populate(entry, group, current_time);

            if (of_list_append(&entries, entry) < 0) {
                AIM_DIE("unexpected failure appending single group stats entry");
            }
        }
    }

    of_object_delete(entry);

    indigo_cxn_send_controller_message(cxn_id, reply);
}

/* TODO segment long replies */
void
ind_core_group_desc_stats_request_handler(of_object_t *_obj,
                                          indigo_cxn_id_t cxn_id)
{
    of_group_desc_stats_request_t *obj = _obj;
    of_group_desc_stats_reply_t *reply;
    of_list_group_desc_stats_entry_t entries;
    of_group_desc_stats_entry_t *entry;
    uint32_t xid;
    ind_core_group_t *group;
    bighash_iter_t iter;

    reply = of_group_desc_stats_reply_new(obj->version);
    AIM_TRUE_OR_DIE(reply != NULL);

    of_group_desc_stats_request_xid_get(obj, &xid);
    of_group_desc_stats_reply_xid_set(reply, xid);
    of_group_desc_stats_reply_entries_bind(reply, &entries);

    entry = of_group_desc_stats_entry_new(entries.version);
    AIM_TRUE_OR_DIE(entry != NULL);

    for (group = bighash_iter_start(ind_core_group_hashtable, &iter);
            group; group = bighash_iter_next(&iter)) {
        of_group_desc_stats_entry_group_type_set(entry, group->type);
        of_group_desc_stats_entry_group_id_set(entry, group->id);
        if (of_group_desc_stats_entry_buckets_set(entry, group->buckets) < 0) {
            AIM_DIE("unexpected failure setting group desc stats entry buckets");
        }

        if (of_list_append(&entries, entry) < 0) {
            break;
        }
    }

    of_object_delete(entry);

    indigo_cxn_send_controller_message(cxn_id, reply);
}

void
ind_core_group_features_stats_request_handler(of_object_t *_obj,
                                              indigo_cxn_id_t cxn_id)
{
    of_group_features_stats_request_t *obj = _obj;
    ind_core_unhandled_message(obj, cxn_id);
}

void
ind_core_group_init(void)
{
    ind_core_group_hashtable = bighash_table_create(BIGHASH_AUTOGROW);
    AIM_TRUE_OR_DIE(ind_core_group_hashtable != NULL);
}

/*
 * Group table management
 */

static ind_core_group_table_t *
group_table_for_id(uint32_t group_id)
{
    return ind_core_group_tables[group_id >> 24];
}

void indigo_core_group_table_register(
    uint8_t table_id, const char *name,
    const indigo_core_group_table_ops_t *ops, void *priv)
{
    AIM_TRUE_OR_DIE(strlen(name) <= OF_MAX_TABLE_NAME_LEN);

    ind_core_group_table_t *table = aim_zmalloc(sizeof(*table));
    strncpy(table->name, name, sizeof(table->name));
    table->ops = ops;
    table->priv = priv;

    AIM_TRUE_OR_DIE(ind_core_group_tables[table_id] == NULL);
    ind_core_group_tables[table_id] = table;

    LOG_INFO("Registered group table \"%s\" with table id %d", name, table_id);
}

void indigo_core_group_table_unregister(uint8_t table_id)
{
    ind_core_group_table_t *table = ind_core_group_tables[table_id];
    AIM_TRUE_OR_DIE(table != NULL);

    /* Delete groups remaining in this table */
    bighash_iter_t iter;
    ind_core_group_t *group;
    for (group = bighash_iter_start(ind_core_group_hashtable, &iter);
            group; group = bighash_iter_next(&iter)) {
        if (group_table_for_id(group->id) == table) {
            ind_core_group_delete_one(group, INDIGO_CXN_ID_UNSPECIFIED);
        }
    }

    aim_free(table);
    ind_core_group_tables[table_id] = NULL;
}
