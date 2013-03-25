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

/**************************************************************************//**
 *
 *
 *
 *
 *****************************************************************************/
#include <AIM/aim_config.h>
#include <AIM/aim_pvs_file.h>
#include "aim_util.h"

#if AIM_CONFIG_PVS_INCLUDE_TTY == 1
#include <unistd.h>
#endif

AIM_OBJECT_ID_DEFINE(aim_pvs_file_oid, "aim_pvs_file");

/**
 * Destructor for our objects.
 */
static void aim_pvs_file_destroy__(aim_object_t* object);


/**
 * Output to FILE*
 */
static int
aim_vprint_fp__(aim_pvs_t* pvs, const char* fmt, va_list vargs)
{
    int rv = 0;

    /**
     * Special checks for stdout/stderr
     */
    if(pvs->object.cookie == NULL) {
        if(pvs->object.subtype == 1) {
            pvs->object.cookie = stdout;
        }
        if(pvs->object.subtype == 2) {
            pvs->object.cookie = stderr;
        }
    }

    if(pvs->object.cookie) {
        FILE* fp = (FILE*) pvs->object.cookie;
        if(fp) {
            rv = vfprintf(fp, fmt, vargs);
            fflush(fp);
        }
    }
    return rv;
}

/**
 * Create a file PVS.
 */
aim_pvs_t*
aim_pvs_fopen(const char* path, const char* mode)
{
    FILE* fp = fopen(path, mode);
    aim_pvs_t* rv = NULL;

    if(fp) {
        rv = (aim_pvs_t*) aim_object_create(sizeof(*rv),
                                            aim_pvs_file_oid, -1,
                                            fp, aim_pvs_file_destroy__);
        rv->vprintf = aim_vprint_fp__;
        rv->enabled = 1;
    }
    return rv;
}

/**
 * Close and destroy a file PVS.
 */
static void
aim_pvs_file_destroy__(aim_object_t* object)
{
    if(object->cookie) {
        FILE* fp = (FILE*)object->cookie;
        fclose(fp);
    }
    AIM_FREE(object);
}


static int
isatty__(aim_pvs_t* pvs)
{
#if AIM_CONFIG_PVS_INCLUDE_TTY == 1
    if(pvs->object.subtype == 1) {
        return isatty(1);
    }
    if(pvs->object.subtype == 2) {
        return isatty(2);
    }
#endif
    return 0;
}

/**
 * Standard builtin types are based on the FILE pvs.
 */
aim_pvs_t aim_pvs_stdout = {
    AIM_STATIC_OBJECT_INIT(aim_pvs_file_oid, 1, NULL, NULL),
    aim_vprint_fp__,
    1,
    0,
    isatty__,
};

aim_pvs_t aim_pvs_stderr = {
    AIM_STATIC_OBJECT_INIT(aim_pvs_file_oid, 2, NULL, NULL),
    aim_vprint_fp__,
    1,
    0,
    isatty__,
};

aim_pvs_t aim_pvs_none = {
    AIM_STATIC_OBJECT_INIT(aim_pvs_file_oid, -1, NULL, NULL),
    aim_vprint_fp__,
    1,
    0
};

