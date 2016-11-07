/****************************************************************
 *
 *        Copyright 2013-2016, Big Switch Networks, Inc.
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

#include <indigo/error.h>
#include "configuration_int.h"
#include "configuration_log.h"
#include <cjson/cJSON.h>
#include <cjson_util/cjson_util.h>
#include <cjson_util/cjson_util_file.h>
#include <BigList/biglist.h>
#include <SocketManager/socketmanager.h>

/* List of struct ind_cfg_ops pointers */
static biglist_t *cfg_registration_list;

/* Tracks current configuration file */
static cjson_util_file_t cfg_jfs;


/*
 * Invokes each registered configuration listener with the cJSON tree
 * parsed from the configuration file.
 */
static indigo_error_t
stage_and_commit(void)
{
    biglist_t *el;
    int failed = 0;

    AIM_LOG_INFO("Staging new configuration");

    BIGLIST_FOREACH(el, cfg_registration_list) {
        struct ind_cfg_ops *ops = el->data;
        if (IND_CFG_ENTRY_USES_DEFAULT(ops)) {
            if (ops->stage(cfg_jfs.root) < 0) {
                failed = 1;
            }
        }
    }

    if (failed == 0) {
        AIM_LOG_INFO("Committing new configuration");

        BIGLIST_FOREACH(el, cfg_registration_list) {
            struct ind_cfg_ops *ops = el->data;
            if (IND_CFG_ENTRY_USES_DEFAULT(ops)) {
                ops->commit();
            }
        }

        AIM_LOG_INFO("Finished reconfiguration");
        return INDIGO_ERROR_NONE;
    } else {
        AIM_LOG_WARN("Reconfiguration failed, new configuration not applied");
        return INDIGO_ERROR_UNKNOWN;
    }
}

/*
 * Set the configuration filename and load it.
 * Uses cjson_util to parse the config file contents into a cJSON tree,
 * and then stages and commits the parsed config.
 */
indigo_error_t
ind_cfg_filename_set(char *filename)
{
    int rv;

    if (filename == NULL) {
        cjson_util_file_close(&cfg_jfs);
        return INDIGO_ERROR_NONE;
    }
    
    rv = cjson_util_file_open(filename, &cfg_jfs, "{}");
    switch(rv) {
    case AIM_ERROR_NONE:
        AIM_LOG_INFO("Config: filename %s set", filename);
        return stage_and_commit();
    case AIM_ERROR_NOT_FOUND:
        AIM_LOG_ERROR("Config: filename %s not found", filename);
        return INDIGO_ERROR_NOT_FOUND;
    case AIM_ERROR_PARAM:
        AIM_LOG_ERROR("Config: failed to parse filename %s", filename);
        return INDIGO_ERROR_PARSE;
    case AIM_ERROR_INTERNAL:  /* fall-through */
    default:
        AIM_LOG_ERROR("Config: unknown error %d opening filename %s",
                      rv, filename);
        return INDIGO_ERROR_UNKNOWN;
    }
}

indigo_error_t
ind_cfg_filename_get(char *filename, int maxlen)
{
    if (filename == NULL) {
        return INDIGO_ERROR_PARAM;
    }
    if (cfg_jfs.filename == NULL) {
        return INDIGO_ERROR_INIT;
    }

    if (strlen(filename) >= maxlen) {
        AIM_LOG_ERROR("Config: cannot get filename, too long");
        return INDIGO_ERROR_PARAM;
    }

    strncpy(filename, cfg_jfs.filename, maxlen);

    return INDIGO_ERROR_NONE;
}

void
ind_cfg_register(const struct ind_cfg_ops *ops)
{
    if (!IND_CFG_ENTRY_USES_DEFAULT(ops)) {
        AIM_LOG_INFO("Registering cfg client for %s", ops->filename);
    }
    cfg_registration_list = biglist_append(cfg_registration_list, (void *)ops);
}

void 
ind_cfg_unregister(const struct ind_cfg_ops *ops)
{
    cfg_registration_list = biglist_remove(cfg_registration_list, (void *)ops);
}

/*
 * Iterate thru the registered users and process any entries which
 * use a non-default configuration file
 */
static void
update_nondefault_config(void)
{
    cJSON *root;
    biglist_t *el;
    int rv;

    BIGLIST_FOREACH(el, cfg_registration_list) {
        struct ind_cfg_ops *ops = el->data;
        if (!IND_CFG_ENTRY_USES_DEFAULT(ops)) {
            AIM_LOG_VERBOSE("Loading non-default cfg file %s", ops->filename);
            rv = cjson_util_parse_file(ops->filename, &root);
            if (rv) {
                AIM_LOG_ERROR("Could not load non-default cfg file %s",
                              ops->filename);
            } else {
                if (ops->stage(root) < 0) {
                    AIM_LOG_ERROR("Failed to stage non-default cfg file %s",
                                  ops->filename);
                } else {
                    ops->commit();
                }
                cJSON_Delete(root);
            }
        }
    }
}

/*
 * Load a configuration file.
 * Uses cjson_util to reload the config file contents into a cJSON tree,
 * and then stages and commits the parsed config.
 */
indigo_error_t
ind_cfg_load(void)
{
    int rv;

    /* Update any entries that use a non-default config file */
    update_nondefault_config();

    if (cfg_jfs.filename == NULL) {
        AIM_LOG_WARN("received SIGHUP but not using a config file");
        return INDIGO_ERROR_NONE;
    }

    rv = cjson_util_file_reload(&cfg_jfs, 0);
    if (rv == 0) {
        AIM_LOG_VERBOSE("Configuration %s unchanged", cfg_jfs.filename);
        return INDIGO_ERROR_NONE;
    } else if (rv < 0) {
        AIM_LOG_ERROR("Configuration reload of %s, rv %d",
                      cfg_jfs.filename, rv);
        return INDIGO_ERROR_PARSE;
    }

    return stage_and_commit();
}

/* wrapper function */
static void
cfg_callback(void *cookie)
{
    ind_cfg_load();
}

/* install periodic event to call cfg_callback */
indigo_error_t
ind_cfg_install_reload_handler(void)
{
    const int period_ms = 250;

    return ind_soc_timer_event_register_with_priority(cfg_callback, NULL,
                                                      period_ms,
                                                      IND_SOC_HIGH_PRIORITY);
}


indigo_error_t
ind_cfg_lookup(cJSON *root, const char *path, cJSON **result)
{
    int rv;
    rv = cjson_util_lookup(root, result, path);
    if (rv == AIM_ERROR_PARAM) {
        *result = NULL;
        return INDIGO_ERROR_PARAM;
    } else if (rv == AIM_ERROR_NOT_FOUND) {
        *result = NULL;
        return INDIGO_ERROR_NOT_FOUND;
    } else {
        return INDIGO_ERROR_NONE;
    }
}

indigo_error_t
ind_cfg_lookup_string(cJSON *root, const char *path, char **result)
{
    cJSON *node;
    indigo_error_t err;

    err = ind_cfg_lookup(root, path, &node);
    if (err < 0) {
        return err;
    }

    if (node->type != cJSON_String) {
        return INDIGO_ERROR_PARAM;
    }

    *result = node->valuestring;

    return INDIGO_ERROR_NONE;
}

indigo_error_t
ind_cfg_lookup_int(cJSON *root, const char *path, int *result)
{
    cJSON *node;
    indigo_error_t err;

    err = ind_cfg_lookup(root, path, &node);
    if (err < 0) {
        return err;
    }

    if (node->type != cJSON_Number) {
        return INDIGO_ERROR_PARAM;
    }

    if (node->valueint != node->valuedouble) {
        return INDIGO_ERROR_PARAM;
    }

    *result = node->valueint;

    return INDIGO_ERROR_NONE;
}

indigo_error_t
ind_cfg_lookup_double(cJSON *root, const char *path, double *result)
{
    cJSON *node;
    indigo_error_t err;

    err = ind_cfg_lookup(root, path, &node);
    if (err < 0) {
        return err;
    }

    if (node->type != cJSON_Number) {
        return INDIGO_ERROR_PARAM;
    }

    *result = node->valuedouble;

    return INDIGO_ERROR_NONE;
}

indigo_error_t
ind_cfg_lookup_bool(cJSON *root, const char *path, int *result)
{
    cJSON *node;
    indigo_error_t err;

    err = ind_cfg_lookup(root, path, &node);
    if (err < 0) {
        return err;
    }

    if (node->type == cJSON_True) {
        *result = 1;
    } else if (node->type == cJSON_False) {
        *result = 0;
    } else {
        return INDIGO_ERROR_PARAM;
    }

    return INDIGO_ERROR_NONE;
}

indigo_error_t
ind_cfg_parse_loglevel(cJSON *root, const char *path,
                       uint32_t dflt, uint32_t *result)
{
    char *str;
    indigo_error_t err;

    err = ind_cfg_lookup_string(root, path, &str);
    if (err == INDIGO_ERROR_NONE) {
        if (aim_log_syslog_level_map(str, result) != 0) {
            AIM_LOG_WARN("Could not parse log level '%s' at %s", str, path);
            err = INDIGO_ERROR_PARAM;
        }
    } else if (err == INDIGO_ERROR_NOT_FOUND) {
        *result = dflt;
        err = INDIGO_ERROR_NONE;
    } else {
        AIM_LOG_WARN("Invalid log level key %s", path);
    }

    return err;
}

static int
str2mac(const char *str, of_mac_addr_t *mac)
{
    unsigned int imac[6];
    int p;
    int i;

    p = sscanf(str,"%2x:%2x:%2x:%2x:%2x:%2x",
               &imac[0], &imac[1], &imac[2], &imac[3], &imac[4], &imac[5]);
    if (p == 6) {
        for (i = 0; i < 6; i++) {
            mac->addr[i] = imac[i];
        }

        return 0;
    }

    return -1;
}

/**
 * Parse a mac addr entry from the configuration
 */

indigo_error_t
ind_cfg_parse_mac_addr(cJSON *root, const char *path,
                       of_mac_addr_t *mac_addr)
{
    cJSON *node;
    indigo_error_t err;

    if (root == NULL) {
        return INDIGO_ERROR_PARAM;
    }

    err = ind_cfg_lookup(root, path, &node);
    if (err < 0) {
        return err;
    }

    if (node->type != cJSON_String) {
        AIM_LOG_ERROR("Config: mac_addr must be a string");
        return INDIGO_ERROR_PARAM;
    }

    if (str2mac(node->valuestring, mac_addr)) {
        AIM_LOG_ERROR("Config: mac_addr must be a colon sep MAC str");
        return INDIGO_ERROR_PARAM;
    }

    return INDIGO_ERROR_NONE;
}
