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
 * aim_xprintf.h
 *
 *
 *****************************************************************************/
#include <AIM/aim_config.h>
#include <AIM/aim_datatypes.h>
#include <AIM/aim_pvs.h>
#include <AIM/aim_string.h>
#include <AIM/aim_pvs_buffer.h>
#include <inttypes.h>
#include <stddef.h>

/**
 * These are all of the format specifiers recognized by C99.
 */
static char* specifiers__ = "diuoxXfFeEgGaAcspn%";


/**
 * When we call underlying functions that take a va_list
 * (some of which we have no control over), we can't assume
 * the va_list is passed by reference, or that it is even
 * usable after the call.
 *
 * As a result, we make a copy of the list, and send the copy
 * to the underlying function. We then have to figure out how
 * big the argument was so we can pull it off and continue.
 *
 * This function parses the format specifier to determine the
 * correct type and size of the variable and removes it from
 * the list.
 */
static int
pull_format_argument__(const char* fmt, aim_va_list_t* vargs)
{

    /**
     * The width and/or precision is passed as an argument
     * if specified as an asterisk in the format string.
     *
     * We need to start by pulling off as many integers as there are
     * asterisks.
     */
    const char* p;
    for(p = fmt; *p; p++) {
        if(*p == '*') {
            (void) va_arg(vargs->val, int);
        }
    }

    /** backup to the format specifier */
    p--;

    switch(*p)
        {
        case 'd':
        case 'i':
        case 'u':
        case 'o':
        case 'x':
        case 'X':
        case 'c':
            {
                /**
                 * These are all integer types.
                 * Determine optional length specifications.
                 */
                switch(p[-1])
                    {
                    case 'z':
                        {
                            (void) va_arg(vargs->val, size_t);
                            break;
                        }
                    case 'j':
                        {
                            (void) va_arg(vargs->val, intmax_t);
                            break;
                        }
                    case 't':
                        {
                            (void) va_arg(vargs->val, ptrdiff_t);
                            break;
                    }
                    case 'l':
                        {
                            /* just 'l', or 'll'? */
                            if(p[-2] == 'l') {
                                (void) va_arg(vargs->val, long long);
                            }
                            else {
                                (void) va_arg(vargs->val, long);
                            }
                            break;
                        }
                    case 'h':
                        {
                            /* h and hh are both promoted  integers,
                               so we don't bother determining which one it is */
                            (void) va_arg(vargs->val, int);
                            break;
                        }
                    default:
                        {
                            /* No length specification - integer */
                            (void) va_arg(vargs->val, int);
                            break;
                        }
                    }
                break;
            }
        case 'f':
        case 'F':
        case 'e':
        case 'E':
        case 'g':
        case 'G':
        case 'a':
        case 'A':
            {
                /**
                 * These are all double types.
                 */
                switch(p[-2])
                    {
                    case 'L':
                        {
                            (void) va_arg(vargs->val, long double);
                            break;
                        }
                    default:
                        {
                            (void) va_arg(vargs->val, double);
                            break;
                        }
                    }
                break;
            }
        case 'p':
        case 'n':
        case 's':
            {
                /**
                 * These are all pointer types. Note - 'n' is broken...
                 */
                (void) va_arg(vargs->val, void*);
                break;
            }
        default:
            {
                return -1;
            }
        }

    return 0;
}

int
aim_vprintf(aim_pvs_t* pvs, const char* fmt, va_list _vargs)
{
    char* fmt_ = aim_strdup(fmt);
    int   len = AIM_STRLEN(fmt);
    const char* src;
    char* dst;
    int count = 0;
    aim_va_list_t vargs;

    dst = fmt_;
    va_copy(vargs.val, _vargs);

#define NEXT_TOKEN()                            \
    do {                                        \
        AIM_MEMSET(fmt_, 0, len);               \
        dst = fmt_;                             \
    } while(0)


    NEXT_TOKEN();
    for(src = fmt, dst = fmt_; *src;) {
        *dst++ = *src;

        if(*src == '%') {
            src++;

            if(*src == '{') {
                char type[32];
                char* t = type;
                AIM_MEMSET(type, 0, sizeof(type));

                /* We will be printing a string */
                *dst++ = 's';
                src++;
                while(*src && *src !='}') {
                    *t++ = *src++;
                }
                if(*src == 0) {
                    /* Malformed */
                    count += aim_pvs_printf(pvs, fmt_, "%BADFORMAT");
                    AIM_FREE(fmt_);
                    return count;
                }
                else {
                    aim_datatype_t* dt = aim_datatype_find(0, type);
                    if(dt == NULL) {
                        /* bad or missing type */
                        count += aim_pvs_printf(pvs, "{error:unknown type %s}", type);
                        /*
                         * Its hard to continue from here. We don't know
                         * the number and type of arguments that were passed
                         * for this datatype, so we can't remove them to
                         * allow the rest of the format specifiers to receive
                         * their arguments properly, which will likely
                         * result in a fault. Probably better to just give up.
                         */
                        return count;
                    }
                    else {
                        const char* rv = NULL;
                        aim_datatype_context_t dtc;
                        dtc.dt = dt;
                        dtc.epvs = pvs;
                        dt->to_str(&dtc, &vargs, &rv);
                        count += aim_pvs_printf(pvs, fmt_, rv);
                        AIM_FREE((char*)rv);
                    }
                }
            }
            else {
                va_list vac;

                /* regular specifier */
                while(!AIM_STRCHR(specifiers__, *src)) {
                    *dst++ = *src++;
                }
                *dst++ = *src;
                *dst=0;

                va_copy(vac, vargs.val);
                count += aim_pvs_vprintf(pvs, fmt_, vac);
                va_end(vac);
                pull_format_argument__(fmt_, &vargs);
            }
            NEXT_TOKEN();
        }
        src++;
    }
    if(dst != fmt_) {
        count += aim_pvs_vprintf(pvs, fmt_, vargs.val);
    }
    AIM_FREE(fmt_);
    return count;
}

int
aim_printf(aim_pvs_t* pvs, const char* fmt, ...)
{
    int rv;
    va_list vargs;
    va_start(vargs, fmt);
    rv = aim_vprintf(pvs, fmt, vargs);
    va_end(vargs);
    return rv;
}
#if 0
int
aim_vsnprintf(char* dst, int size, const char* fmt, va_list vargs)
{
    int rv;
    char* data;
    aim_pvs_t* dstpvs = aim_pvs_buffer_create();
    aim_vprintf(dstpvs, fmt, vargs);
    rv = aim_pvs_buffer_size(dstpvs);
    data = aim_pvs_buffer_get(dstpvs);
    AIM_MEMCPY(dst, data, size);
    AIM_FREE(data);
    return rv;
}

int
aim_snprintf(char* dst, int size, const char* fmt, ...)
{
    int rv;
    va_list vargs;
    va_start(vargs, fmt);
    rv = aim_vsnprintf(dst, size, fmt, vargs);
    va_end(vargs);
    return rv;
}
#endif
