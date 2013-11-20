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
 *  /utest/main.c
 *
 *  Configuration Unit Testing
 *
 *****************************************************************************/


#include <Configuration/configuration_config.h>
#include <Configuration/configuration.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <indigo/assert.h>
#include <cjson/cJSON.h>

#include "configuration_log.h"

static const char *sample_json =
    "{\n"
    "    \"logging\": {\n"
    "	     \"dataplane\": \"errors\"\n"
    "    },\n"
    "    \"int\": 5,\n"
    "    \"double\": 3.14,\n"
    "    \"true\": true,\n"
    "    \"false\": false,\n"
    "    \"mac\": \"00:01:02:03:04:05\"\n"
    "}\n";

static void
test_lookup(void)
{
    cJSON *node;
    char *str;
    int intval;
    double doubleval;
    cJSON *root = cJSON_Parse(sample_json);
    of_mac_addr_t mac_check = {{0, 1, 2, 3, 4, 5}};
    of_mac_addr_t mac;

    INDIGO_ASSERT(ind_cfg_lookup(root, "", &node) == INDIGO_ERROR_NONE);
    INDIGO_ASSERT(node == root);

    INDIGO_ASSERT(ind_cfg_lookup(root, "nonexistent", &node) == INDIGO_ERROR_NOT_FOUND);

    INDIGO_ASSERT(ind_cfg_lookup(root, "logging", &node) == INDIGO_ERROR_NONE);
    INDIGO_ASSERT(!strcmp(node->string, "logging"));
    INDIGO_ASSERT(node->type == cJSON_Object);

    INDIGO_ASSERT(ind_cfg_lookup(root, "logging.dataplane", &node) == INDIGO_ERROR_NONE);
    INDIGO_ASSERT(!strcmp(node->string, "dataplane"));
    INDIGO_ASSERT(node->type == cJSON_String);
    INDIGO_ASSERT(!strcmp(node->valuestring, "errors"));

    INDIGO_ASSERT(ind_cfg_lookup(root, "logging", &node) == INDIGO_ERROR_NONE);
    INDIGO_ASSERT(ind_cfg_lookup(node, "dataplane", &node) == INDIGO_ERROR_NONE);
    INDIGO_ASSERT(!strcmp(node->string, "dataplane"));
    INDIGO_ASSERT(node->type == cJSON_String);
    INDIGO_ASSERT(!strcmp(node->valuestring, "errors"));

    INDIGO_ASSERT(ind_cfg_lookup(root, "logging.nonexistent", &node) == INDIGO_ERROR_NOT_FOUND);
    INDIGO_ASSERT(ind_cfg_lookup(root, "logging.nonexistent.nonexistent2", &node) == INDIGO_ERROR_NOT_FOUND);
    INDIGO_ASSERT(ind_cfg_lookup(root, "logging.dataplane.nonexistent", &node) == INDIGO_ERROR_PARAM);

    /* ind_cfg_lookup_string */

    INDIGO_ASSERT(ind_cfg_lookup_string(root, "logging.dataplane", &str) == INDIGO_ERROR_NONE);
    INDIGO_ASSERT(!strcmp(str, "errors"));

    INDIGO_ASSERT(ind_cfg_lookup_string(root, "logging", &str) == INDIGO_ERROR_PARAM);
    INDIGO_ASSERT(ind_cfg_lookup_string(root, "int", &str) == INDIGO_ERROR_PARAM);
    INDIGO_ASSERT(ind_cfg_lookup_string(root, "double", &str) == INDIGO_ERROR_PARAM);
    INDIGO_ASSERT(ind_cfg_lookup_string(root, "true", &str) == INDIGO_ERROR_PARAM);
    INDIGO_ASSERT(ind_cfg_lookup_string(root, "false", &str) == INDIGO_ERROR_PARAM);

    /* ind_cfg_lookup_int */

    INDIGO_ASSERT(ind_cfg_lookup_int(root, "int", &intval) == INDIGO_ERROR_NONE);
    INDIGO_ASSERT(intval == 5);

    INDIGO_ASSERT(ind_cfg_lookup_int(root, "double", &intval) == INDIGO_ERROR_PARAM);

    INDIGO_ASSERT(ind_cfg_lookup_int(root, "logging", &intval) == INDIGO_ERROR_PARAM);
    INDIGO_ASSERT(ind_cfg_lookup_int(root, "logging.dataplane", &intval) == INDIGO_ERROR_PARAM);
    INDIGO_ASSERT(ind_cfg_lookup_int(root, "true", &intval) == INDIGO_ERROR_PARAM);
    INDIGO_ASSERT(ind_cfg_lookup_int(root, "false", &intval) == INDIGO_ERROR_PARAM);

    /* ind_cfg_lookup_double */

    INDIGO_ASSERT(ind_cfg_lookup_double(root, "double", &doubleval) == INDIGO_ERROR_NONE);
    INDIGO_ASSERT(doubleval == 3.14);

    INDIGO_ASSERT(ind_cfg_lookup_double(root, "int", &doubleval) == INDIGO_ERROR_NONE);
    INDIGO_ASSERT(doubleval == 5.0);

    INDIGO_ASSERT(ind_cfg_lookup_double(root, "logging", &doubleval) == INDIGO_ERROR_PARAM);
    INDIGO_ASSERT(ind_cfg_lookup_double(root, "logging.dataplane", &doubleval) == INDIGO_ERROR_PARAM);
    INDIGO_ASSERT(ind_cfg_lookup_double(root, "true", &doubleval) == INDIGO_ERROR_PARAM);
    INDIGO_ASSERT(ind_cfg_lookup_double(root, "false", &doubleval) == INDIGO_ERROR_PARAM);

    /* ind_cfg_lookup_bool */

    INDIGO_ASSERT(ind_cfg_lookup_bool(root, "true", &intval) == INDIGO_ERROR_NONE);
    INDIGO_ASSERT(intval == 1);

    INDIGO_ASSERT(ind_cfg_lookup_bool(root, "false", &intval) == INDIGO_ERROR_NONE);
    INDIGO_ASSERT(intval == 0);

    INDIGO_ASSERT(ind_cfg_lookup_bool(root, "logging", &intval) == INDIGO_ERROR_PARAM);
    INDIGO_ASSERT(ind_cfg_lookup_bool(root, "logging.dataplane", &intval) == INDIGO_ERROR_PARAM);
    INDIGO_ASSERT(ind_cfg_lookup_bool(root, "int", &intval) == INDIGO_ERROR_PARAM);
    INDIGO_ASSERT(ind_cfg_lookup_bool(root, "double", &intval) == INDIGO_ERROR_PARAM);
    INDIGO_ASSERT(ind_cfg_parse_mac_addr(root, "mac", &mac) == INDIGO_ERROR_NONE);
    INDIGO_ASSERT(memcmp(&mac, &mac_check, 6) == 0);

    cJSON_Delete(root);
}

static void
test_json_parse_failure(void)
{
    FILE *file;
    char filename[] = "tmpXXXXXX";

    file = fdopen(mkstemp(filename), "w");
    fprintf(file, "{\n\tblah\n}");
    fclose(file);
    ind_cfg_filename_set(filename);

    INDIGO_ASSERT(ind_cfg_load() == INDIGO_ERROR_PARSE);

    unlink(filename);
}

/* Test config ops 1 */

static indigo_error_t stage1_retval;
static int stage1_count;

static indigo_error_t
stage1(cJSON *cjson)
{
    INDIGO_ASSERT(stage1_count == 0);
    stage1_count++;
    return stage1_retval;
}

static int commit1_count;

static void
commit1(void)
{
    INDIGO_ASSERT(stage1_count == 1);
    commit1_count++;
}

static const struct ind_cfg_ops ops1 = {
    .stage = stage1,
    .commit = commit1,
};

/* Test config ops 2 */

static indigo_error_t stage2_retval;
static int stage2_count;

static indigo_error_t
stage2(cJSON *cjson)
{
    INDIGO_ASSERT(stage2_count == 0);
    stage2_count++;
    return stage2_retval;
}

static int commit2_count;

static void
commit2(void)
{
    INDIGO_ASSERT(stage2_count == 1);
    commit2_count++;
}

static const struct ind_cfg_ops ops2 = {
    .stage = stage2,
    .commit = commit2,
};

static void
test_reconfiguration(int reg)  /* If reg is false, assume registered */
{
    FILE *file;
    char filename[] = "tmpXXXXXX";

    file = fdopen(mkstemp(filename), "w");
    fwrite(sample_json, strlen(sample_json), 1, file);
    fclose(file);
    ind_cfg_filename_set(filename);

    if (reg) {
        /* Nothing registered */
        INDIGO_ASSERT(ind_cfg_load() == INDIGO_ERROR_NONE);
        ind_cfg_register(&ops1);
    }

    /* Success */
    stage1_retval = INDIGO_ERROR_NONE;
    stage1_count = commit1_count = 0;
    stage2_count = 0;
    stage2_retval = 0;
    INDIGO_ASSERT(ind_cfg_load() == INDIGO_ERROR_NONE);
    INDIGO_ASSERT(stage1_count == 1);
    INDIGO_ASSERT(commit1_count == 1);

    /* Failure */
    stage1_retval = INDIGO_ERROR_PARAM;
    stage1_count = commit1_count = 0;
    stage2_count = 0;
    stage2_retval = 0;
    INDIGO_ASSERT(ind_cfg_load() < 0);
    INDIGO_ASSERT(stage1_count == 1);
    INDIGO_ASSERT(commit1_count == 0);

    if (reg) {
        ind_cfg_register(&ops2);
    }

    /* Success */
    stage1_retval = INDIGO_ERROR_NONE;
    stage2_retval = INDIGO_ERROR_NONE;
    stage1_count = commit1_count = 0;
    stage2_count = commit2_count = 0;
    INDIGO_ASSERT(ind_cfg_load() == INDIGO_ERROR_NONE);
    INDIGO_ASSERT(stage1_count == 1);
    INDIGO_ASSERT(stage2_count == 1);
    INDIGO_ASSERT(commit1_count == 1);
    INDIGO_ASSERT(commit2_count == 1);

    /* Fail stage1 */
    stage1_retval = INDIGO_ERROR_PARAM;
    stage2_retval = INDIGO_ERROR_NONE;
    stage1_count = commit1_count = 0;
    stage2_count = commit2_count = 0;
    INDIGO_ASSERT(ind_cfg_load() < 0);
    INDIGO_ASSERT(stage1_count == 1);
    INDIGO_ASSERT(stage2_count == 1);
    INDIGO_ASSERT(commit1_count == 0);
    INDIGO_ASSERT(commit2_count == 0);

    /* Fail stage2 */
    stage1_retval = INDIGO_ERROR_NONE;
    stage2_retval = INDIGO_ERROR_PARAM;
    stage1_count = commit1_count = 0;
    stage2_count = commit2_count = 0;
    INDIGO_ASSERT(ind_cfg_load() < 0);
    INDIGO_ASSERT(stage1_count == 1);
    INDIGO_ASSERT(stage2_count == 1);
    INDIGO_ASSERT(commit1_count == 0);
    INDIGO_ASSERT(commit2_count == 0);

    /* Fail both stages */
    stage1_retval = INDIGO_ERROR_PARAM;
    stage2_retval = INDIGO_ERROR_PARAM;
    stage1_count = commit1_count = 0;
    stage2_count = commit2_count = 0;
    INDIGO_ASSERT(ind_cfg_load() < 0);
    INDIGO_ASSERT(stage1_count == 1);
    INDIGO_ASSERT(stage2_count == 1);
    INDIGO_ASSERT(commit1_count == 0);
    INDIGO_ASSERT(commit2_count == 0);

    unlink(filename);
}

/* Non default testing; use 17 for int val */

static const char *sample_json_non_dflt =
    "{\n"
    "    \"logging\": {\n"
    "	     \"dataplane\": \"verbose\"\n"
    "    },\n"
    "    \"int\": 17,\n"
    "    \"double\": 3.1415,\n"
    "    \"true\": true,\n"
    "    \"false\": false\n"
    "}\n";

static int stage_non_dflt_count;
static int commit_non_dflt_count;
static indigo_error_t stage_non_dflt_retval = INDIGO_ERROR_NONE;

static indigo_error_t
stage_non_dflt(cJSON *cjson)
{
    int intval;

    stage_non_dflt_count++;

    /* If int is present, verify that is 17 */
    if (ind_cfg_lookup_int(cjson, "int", &intval) == INDIGO_ERROR_NONE) {
        INDIGO_ASSERT(intval == 17);
    }
    return stage_non_dflt_retval;
}

static void
commit_non_dflt(void)
{
    INDIGO_ASSERT(stage_non_dflt_count > 0);
    commit_non_dflt_count++;
}

static struct ind_cfg_ops ops_non_dflt = {
    .stage = stage_non_dflt,
    .commit = commit_non_dflt,
};
static void
test_non_dflt_reconfiguration(void)
{
    FILE *file;
    char filename_non_dflt[] = "non_dflt_XXXXXX";

    file = fdopen(mkstemp(filename_non_dflt), "w");
    fwrite(sample_json_non_dflt, strlen(sample_json_non_dflt), 1, file);
    fclose(file);

    ops_non_dflt.filename = filename_non_dflt;
    ind_cfg_register(&ops_non_dflt);
    test_reconfiguration(0);
    INDIGO_ASSERT(stage_non_dflt_count);
    INDIGO_ASSERT(commit_non_dflt_count);

    unlink(filename_non_dflt);
}

int main(int argc, char* argv[])
{
    char filename[256];

    INDIGO_ASSERT(ind_cfg_filename_get(filename, sizeof(filename)) == INDIGO_ERROR_INIT);

    test_lookup();
    test_json_parse_failure();
    test_reconfiguration(1);
    test_non_dflt_reconfiguration();

    return 0;
}
