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
#include <AIM/aim_pvs.h>
#include <AIM/aim_printf.h>
#include "aim_util.h"
#include <stdio.h>

int
aim_pvs_avprintf(aim_pvs_t* pvs, const char* fmt, aim_va_list_t* vargs)
{
    if(pvs == NULL) {
        return 0;
    }
    pvs->counter++;
    if(pvs->enabled == 0) {
        return 0;
    }
    return pvs->vprintf(pvs, fmt, vargs->val);
}

int
aim_pvs_vprintf(aim_pvs_t* pvs, const char* fmt, va_list vargs)
{
    if(pvs == NULL) {
        return 0;
    }
    pvs->counter++;
    if(pvs->enabled == 0) {
        return 0;
    }
    return pvs->vprintf(pvs, fmt, vargs);
}

int
aim_pvs_printf(aim_pvs_t* pvs, const char* fmt, ...)
{
    int rv;
    va_list vargs;
    va_start(vargs, fmt);
    rv = aim_pvs_vprintf(pvs, fmt, vargs);
    va_end(vargs);
    return rv;
}

int
aim_pvs_enable(aim_pvs_t* pvs, int enable)
{
    if(pvs == NULL) {
        return -1;
    }
    else {
        pvs->enabled = enable;
        return 0;
    }
}

void
aim_pvs_destroy(aim_pvs_t* pvs)
{
    if(pvs) {
        aim_object_destroy((aim_object_t*)pvs);
    }
}

int
aim_pvs_isatty(aim_pvs_t* pvs)
{
    if(!pvs || !pvs->isatty) {
        return -1;
    }
    else {
        return pvs->isatty(pvs);
    }
}

