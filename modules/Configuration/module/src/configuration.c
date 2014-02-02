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

#include <indigo/error.h>
#include "configuration_int.h"
#include "configuration_log.h"
#include <cjson/cJSON.h>
#include <BigList/biglist.h>

/* List of struct ind_cfg_ops pointers */
static biglist_t *cfg_registration_list;

/* Filename that current_cfg was read from. */
static char *current_filename;


indigo_error_t
ind_cfg_filename_set(char *filename)
{
    char *tmp_name;
    if ((tmp_name = strdup(filename)) == NULL) {
        AIM_LOG_ERROR("Config:  Failed to set filename str to %s", filename);
        return INDIGO_ERROR_RESOURCE;
    }

    if (current_filename != NULL) {
        free(current_filename);
    }
    current_filename = tmp_name;

    AIM_LOG_INFO("Config:  Set filename to %s", current_filename);

    return INDIGO_ERROR_NONE;
}

indigo_error_t
ind_cfg_filename_get(char *filename, int maxlen)
{
    if (filename == NULL) {
        return INDIGO_ERROR_PARAM;
    }
    if (current_filename == NULL) {
        return INDIGO_ERROR_INIT;
    }

    if (strlen(filename) >= maxlen) {
        AIM_LOG_ERROR("Config:  cannot get filename, too long");
        return INDIGO_ERROR_PARAM;
    }

    strncpy(filename, current_filename, maxlen);

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

/*
 * Given the start of a string containing newlines and another pointer
 * inside that string, return the line and column number of that position.
 *
 * Line and column numbering starts at 1. Tab width is assumed to be 8.
 */
static void
find_line_number(const char *start, const char *pos, int *line, int *col)
{
    const char *cur = start;
    const int tabwidth = 8;
    *line = 1;
    *col = 1;

    while (cur < pos) {
        if (*cur == '\n') {
            (*line)++;
            *col = 1;
        } else if (*cur == '\t') {
            (*col) += tabwidth - ((*col - 1) % tabwidth);
        } else {
            (*col)++;
        }
        cur++;
    }
}

/*
 * Parse the given config file into a cJSON tree.
 *
 * If the config file is invalid, logs the errors and returns NULL.
 */
static cJSON *
parse_json_file(const char *filename)
{
    FILE *f;
    long len;
    char *data;
    cJSON *root;

    f = fopen(filename, "r");
    if (f == NULL) {
        AIM_LOG_ERROR("failed to open %s", filename);
        return NULL;
    }

    fseek(f, 0, SEEK_END);
    len = ftell(f);
    fseek(f, 0, SEEK_SET);
    data = aim_malloc(len + 1);
    if (fread(data, 1, len, f) == 0) {
        free(data);
        fclose(f);
        AIM_LOG_ERROR("failed to read %s", filename);
        return NULL;
    }
    data[len] = 0;
    fclose(f);

    root = cJSON_Parse(data);
    if (!root) {
        int line, col;
        char *next_newline;
        const char *errptr = cJSON_GetErrorPtr();
        find_line_number(data, errptr, &line, &col);

        /* Terminate the snippet before the next newline */
        next_newline = strchr(errptr, '\n');
        if (next_newline != NULL) {
            *next_newline = '\0';
        }

        AIM_LOG_ERROR("Error at line %d col %d: [%.8s]\n", line, col, errptr);

        free(data);
        return NULL;
    }

    free(data);

    return root;
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

    BIGLIST_FOREACH(el, cfg_registration_list) {
        struct ind_cfg_ops *ops = el->data;
        if (!IND_CFG_ENTRY_USES_DEFAULT(ops)) {
            AIM_LOG_VERBOSE("Loading non-default cfg file %s", ops->filename);
            root = parse_json_file(ops->filename);
            if (root == NULL) {
                /* parse_json_file() logged a detailed message. */
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
 *
 * The file is parsed into a cJSON tree and passed to each registered
 * listener.
 *
 * Use current_filename as the source.
 */
indigo_error_t
ind_cfg_load(void)
{
    cJSON *root;
    biglist_t *el;
    int failed = 0;

    /* Update any entries that use a non-default config file */
    update_nondefault_config();

    if (current_filename == NULL) {
        AIM_LOG_WARN("received SIGHUP but not using a config file");
        return INDIGO_ERROR_NONE;
    }

    root = parse_json_file(current_filename);
    if (root == NULL) {
        /* parse_json_file() logged a detailed message. */
        AIM_LOG_ERROR("Configuration unchanged; could not load %s.",
                      current_filename);
        return INDIGO_ERROR_PARSE;
    }

    AIM_LOG_INFO("Staging new configuration");

    BIGLIST_FOREACH(el, cfg_registration_list) {
        struct ind_cfg_ops *ops = el->data;
        if (IND_CFG_ENTRY_USES_DEFAULT(ops)) {
            if (ops->stage(root) < 0) {
                failed = 1;
            }
        }
    }

    cJSON_Delete(root);

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

indigo_error_t
ind_cfg_lookup(cJSON *root, const char *path_, cJSON **result)
{
    /* strtok_r mutates its input, need to copy */
    char *path = strdup(path_);
    char *saveptr = NULL;
    char *token;
    cJSON *node = root;
    indigo_error_t err = INDIGO_ERROR_NONE;

    while (INDIGO_SUCCESS(err) &&
           (token = strtok_r(node == root ? path : NULL, ".", &saveptr)) != NULL) {
        if (node->type != cJSON_Object) {
            err = INDIGO_ERROR_PARAM;
        } else if ((node = cJSON_GetObjectItem(node, token)) == NULL) {
            err = INDIGO_ERROR_NOT_FOUND;
        }
    }

    free(path);
    *result = err == INDIGO_ERROR_NONE ? node : NULL;
    return err;
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
