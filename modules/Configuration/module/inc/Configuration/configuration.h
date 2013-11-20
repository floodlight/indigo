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

/******************************************************************************
 *
 *  /module/inc/configuration.h
 *
 *  Configuration Public Interface
 *
 *****************************************************************************/


#ifndef __CONFIGURATION_H__
#define __CONFIGURATION_H__

#include "configuration_config.h"

#include <indigo/error.h>
#include <loci/loci.h>
#include <cjson/cJSON.h>

/**
 * Config operations
 *
 * Should be passed to ind_cfg_register during init.
 */
struct ind_cfg_ops {
    /**
     * Stage a new configuration
     *
     * Does any necessary parsing, validation, preallocation, etc.
     * If this function fails the reconfiguration is aborted.
     *
     * The module is assumed to use private global memory to store the
     * staged configuration so it can be used later during commit.
     *
     * In case of failures in other stage functions this may be called
     * multiple times with no commit() calls in between. This function
     * should clean up after previous calls if necessary.
     */
    indigo_error_t (*stage)(cJSON *cfg);

    /**
     * Commit a new configuration
     *
     * Applies the most recent configuration handled by the stage function.
     *
     * This function cannot fail. If part of the configuration can not be
     * applied for unavoidable reasons then details of the failure should be
     * logged.
     */
    void (*commit)(void);

    /**
     * Specifies the filename to be read for configuration data
     *
     * This is an optional parameter.  If this is NULL or the empty
     * string it is ignored and the above callbacks will be made with
     * the data in the default configuration file (if specified by a call
     * to ind_cfg_filename_set).
     *
     * If filename is a non-empty string, the configuration module will
     * treat this as a file name and attempt to open the named file using
     * it as a paraemeter to fopen.
     *
     * If the file is opened successfully, the contents are read in and
     * parsed as JSON input.  If this is successful, the stage and commit
     * calls are made for this module.  Otherwise, no callbacks are made
     * for this entry.
     */
    const char *filename;
};

/* If entry's filename is NULL or empty string, use default config */
#define IND_CFG_ENTRY_USES_DEFAULT(entry) \
    (((entry)->filename == NULL) || (*(entry)->filename == 0))

/**
 * Register stage/commit operations
 */
extern void ind_cfg_register(const struct ind_cfg_ops *ops);

/**
 * Load a new configuration from a file
 *
 * The file to use is configured with ind_cfg_filename_set().
 *
 * This function calls all registered stage callbacks, then, if all
 * stage callbacks succeeded, calls all commit callbacks.
 */
extern indigo_error_t ind_cfg_load(void);

extern indigo_error_t ind_cfg_install_sighup_handler(void);

extern indigo_error_t ind_cfg_filename_set(char *filename);
extern indigo_error_t ind_cfg_filename_get(char *filename, int maxlen);

/*
 * Convenience functions for looking up a particular value in the config
 *
 * The path is delimited by periods.
 */
extern indigo_error_t ind_cfg_lookup(cJSON *root, const char *path, cJSON **result);
extern indigo_error_t ind_cfg_lookup_string(cJSON *root, const char *path, char **result);
extern indigo_error_t ind_cfg_lookup_int(cJSON *root, const char *path, int *result);
extern indigo_error_t ind_cfg_lookup_double(cJSON *root, const char *path, double *result);
extern indigo_error_t ind_cfg_lookup_bool(cJSON *root, const char *path, int *result);

extern indigo_error_t ind_cfg_parse_mac_addr(cJSON *root, const char *path,
                                             of_mac_addr_t *mac_addr);

/*
 * Convenience function for parsing a log level
 *
 * If the given path leads to an invalid loglevel an error is returned. If the
 * path does not exist, the default is stored in *result and success is
 * returned. Otherwise, *result is populated using aim_log_syslog_level_map.
 */
extern indigo_error_t ind_cfg_parse_loglevel(cJSON *root, const char *path,
                                             uint32_t dflt, uint32_t *result);

#endif /* __CONFIGURATION_H__ */
