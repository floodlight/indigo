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
#include "aim_log.h"

void aim_die(const char* function,
             const char* file,
             int line,
             const char* fmt, ...)
{
    va_list va;
    va_list vb;

    va_start(va, fmt);
    va_copy(vb, va);

    aim_log_vcommon(AIM_LOG_STRUCT_POINTER,
                    AIM_LOG_FLAG_FATAL,
                    NULL, 0,
                    function, file, line,
                    fmt, va);

    aim_pvs_vprintf(&aim_pvs_stderr, fmt, vb);
    aim_pvs_printf(&aim_pvs_stderr, "\n");
    /* Fixme/Todo */
    abort();
}
