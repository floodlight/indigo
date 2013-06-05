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
 * @file
 * @brief AIM Datatype String Parsing
 *
 * @addtogroup aim-sparse
 * @{
 *
 *****************************************************************************/
#include <AIM/aim_config.h>
#include <AIM/aim_sparse.h>
#include <AIM/aim_datatypes.h>
#include <AIM/aim_error.h>
#include <AIM/aim_printf.h>

/**
 * @brief Parse the given datatype.
 */

int
aim_sparse(char** args, aim_pvs_t* epvs, const char* fmt, ...)
{
    int rv;
    aim_va_list_t vargs;
    va_start(vargs.val, fmt);
    rv = aim_avsparse(args, epvs, fmt, &vargs);
    va_end(vargs.val);
    return rv;
}

int
aim_vsparse(char** args, aim_pvs_t* epvs, const char* fmt, va_list vargs)
{
    int rv;
    aim_va_list_t avargs;
    va_copy(avargs.val, vargs);
    rv = aim_avsparse(args, epvs, fmt, &avargs);
    va_end(avargs.val);
    return rv;
}

int
aim_avsparse(char** args, aim_pvs_t* epvs,
             const char* fmt, aim_va_list_t* vargs)
{
    int rv;
    int i;
    const char* type;

    for(i = 0, type = fmt; *type; type++, i++) {
        char typeName[32];

        AIM_MEMSET(typeName, 0, sizeof(typeName));

        if(*type == '{') {
            /* Read type name */
            const char* src;
            char* dst;
            AIM_MEMSET(typeName, 0, sizeof(typeName));
            for(src = ++type, dst=typeName; *src && *src != '}';
                src++, dst++) {
                *dst = *src;
            }
            if(*src != '}') {
                /* Error in format string */
                return AIM_ERROR_PARAM;
            }
            else {
                /* next character is the next format specifier */
                type = src;
            }

            rv = aim_avsparse_type(args[i], epvs, 0, typeName, vargs);
            if(rv < 0) {
                return rv;
            }
        }
        else {
            rv = aim_avsparse_type(args[i], epvs, *type, NULL, vargs);
            if(rv < 0) {
                return rv;
            }
        }
    }

    return AIM_ERROR_NONE;
}

int
aim_avsparse_type(const char* arg, aim_pvs_t* epvs,
                  char c, char* type, aim_va_list_t* vargs)
{
    int rv;
    aim_datatype_t* dt;
    aim_datatype_context_t dtc;

    if(arg == NULL) {
        return AIM_ERROR_PARAM;
    }

    if(type && type[0] == '%') {
        /* Immediate string specified. The argument must be that string. */
        if(type[1] == 0) {
            /* No string */
            return AIM_ERROR_PARAM;
        }
        if(!AIM_STRCMP(type+1, arg)) {
            return AIM_ERROR_NONE;
        }
        aim_printf(epvs, "expected '%s', not '%s'\n", type+1, arg);
        return AIM_ERROR_PARAM;
    }

    dt = aim_datatype_find(c, type);
    if(dt == NULL) {
        /* Unrecognized type */
        aim_printf(epvs, "<bug: no handler for type '%c:%s'>\n", (c) ? c : '.', (type) ? type : "[NULL]");
        return AIM_ERROR_NOT_FOUND;
    }

    dtc.dt = dt;
    dtc.epvs = epvs;
    rv = dt->from_str(&dtc, arg, vargs);

    if( (rv < 0) && dt->desc) {
        aim_printf(epvs, "'%s' is not a valid %s\n", arg, dt->desc);
    }
    return rv;
}




