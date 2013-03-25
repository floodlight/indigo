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
 *  /module/src/aim_stringc
 *
 *  AIM String Routines
 *
 *****************************************************************************/
#include <AIM/aim_config.h>
#include <AIM/aim.h>
#include "aim_int.h"
#include "aim_util.h"

char*
aim_strdup(const char* src)
{
    int size = AIM_STRLEN(src)+1;
    char* ns = aim_zmalloc(size);
    AIM_STRCPY(ns, src);
    return ns;
}

char*
aim_strtok_r(char *str, const char *delim, char **saveptr)
{
    char* rv;

    if (str == NULL) {
        str = *saveptr;
    }

    while(*str && AIM_STRCHR(delim, *str)) {
        str++;
    }

    if(*str == 0) {
        return NULL;
    }

    rv = str;
    while(*str && !AIM_STRCHR(delim, *str)) {
        str++;
    }

    if(*str) {
        *str++ = 0;
    }

    *saveptr = str;
    return rv;
}

int
aim_snprintf(char* str, int size, const char* fmt, ...)
{
    int rv;
    va_list vargs;
    va_start(vargs, fmt);
    rv = aim_vsnprintf(str, size, fmt, vargs);
    va_end(vargs);
    return rv;
}

#if _MSC_VER
int
aim_vsnprintf(char* str, int size, const char* fmt, va_list vargs)
{
    int count = -1;

    if (size != 0)
        count = _vsnprintf_s(str, size, _TRUNCATE, fmt, vargs);
    if (count == -1)
        count = _vscprintf(fmt, vargs);

    return count;
}
#else
int
aim_vsnprintf(char* str, int size, const char* fmt, va_list vargs)
{
    return AIM_VSNPRINTF(str, size, fmt, vargs);
}
#endif


char*
aim_fstrdup(const char* fmt, ...)
{
    char* rv;
    va_list vargs;
    va_start(vargs, fmt);
    rv = aim_vfstrdup(fmt, vargs);
    va_end(vargs);
    return rv;
}

char*
aim_vfstrdup(const char* fmt, va_list vargs)
{
    char b[128];
    AIM_VSNPRINTF(b, sizeof(b)-1, fmt, vargs);
    return aim_strdup(b);
}

int
aim_strlcpy(char* dst, const char* src, int size)
{
    AIM_STRNCPY(dst, src, size);
    if (size > 0)
        dst[size-1] = 0;
    return AIM_STRLEN(src);
}

static int
hex_val__(char c)
{
    if(c >= '0' && c <= '9') return c - '0';
    if(c >= 'A' && c <= 'F') return c - 'A' + 10;
    if(c >= 'a' && c <= 'f') return c - 'a' + 10;
    return -1;
}

uint8_t*
aim_bytes_from_string(const char* string, int* size)
{
    unsigned char* bytes;
    unsigned char byte;
    int i;
    int nibble_count;
    int string_len;

    if(string == NULL || size == NULL || string[0] == 0) {
        return NULL;
    }

    if(!AIM_STRCMP(string, "NULL")) {
        *size = 0;
        return NULL;
    }

    string_len = AIM_STRLEN(string);

    bytes = aim_zmalloc((string_len+1) / 2);

    byte = 0;
    nibble_count = 0;

    for(i = 0; i < string_len; i++) {
        int hv = hex_val__(string[i]);
        if(hv >= 0) {
            byte |= hv;
            if( (nibble_count % 2) == 0) {
                byte <<= 4;
            }
            else {
                bytes[nibble_count/2] = byte;
                byte = 0;
            }
            nibble_count++;
        }
    }
    if(nibble_count & 1) {
        /* Last nibble will be padded as zero */
        bytes[nibble_count++/2] = byte;
    }

    *size = nibble_count / 2;
    return bytes;
}

char*
aim_bytes_to_string(uint8_t* data, int size, int columns)
{
    int i;
    if(columns == 0) {
        char* rv;
        char* s;
        /* All on one line */
        rv = AIM_MALLOC(10 + /* size */
                        1 + /* : */
                        size*2 + /* bytes */
                        1 /* NULL */);
        s = rv;
        s += AIM_SNPRINTF(s, 16, "(%d):", size);
        for(i = 0; i < size; i++) {
            s += AIM_SNPRINTF(s, 4, "%.2x", data[i]);
        }
        return rv;
    }
    else {
        /**
         * We will need at least 3*size for all bytes.
         * Each column requires 10 extra characters, including newline.
         *
         */
        int c;
        int i;
        int len = (size*3) + ( (size/columns+1)*10) + 1;
        char* s = aim_zmalloc(len+1);
        char* sp = s;

        for(i = 0; i < size; i++) {
            if(i % columns == 0) {
                if(i != 0) {
                    c = AIM_SNPRINTF(sp, len, "\n");
                    sp += c, len -= c;
                }
                if(size > columns) {
                    c = AIM_SNPRINTF(sp, len, "  %.4x: ", i);
                    sp += c, len -= c;
                }
            }
            c = AIM_SNPRINTF(sp, len, "%.2x ", data[i]);
            sp += c, len -= c;
        }
        if((size > columns) && (size % columns != 0)) {
            c = AIM_SNPRINTF(sp, len, "\n");
            sp += c, len -= c;
        }
        return s;
    }
}

char*
aim_strjoin(const char* string, const char** strings, int count)
{
    int i;
    int len = 0;
    int jlen = AIM_STRLEN(string);
    char* rv;

    if(count <= 0) {
        return NULL;
    }

    /* Calculate required buffer size. */
    for(i = 0; i < count-1; i++) {
        len += AIM_STRLEN(strings[i]);
        len += jlen;
    }
    len += AIM_STRLEN(strings[i]) + 1;

    rv = aim_zmalloc(len);

    for(i = 0; i < count-1; i++) {
        AIM_STRCAT(rv, strings[i]);
        AIM_STRCAT(rv, string);
    }
    AIM_STRCAT(rv, strings[i]);

    return rv;
}
