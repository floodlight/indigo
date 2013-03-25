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
 *  /module/src/biglist_util.c
 *
 *  BigList Utilities
 *
 *****************************************************************************/
#include <BigList/biglist_config.h>
#include <BigList/biglist.h>
#include "biglist_int.h"

/* <auto.start.util(ALL).define> */
void*
biglist_zmalloc(int size)
{
    void* p;
    p = BIGLIST_MALLOC(size);
    if(p) {
        BIGLIST_MEMSET(p, 0, size);
    }
    return p;
}
int
biglist_strlcpy(char* dst, const char* src, int size)
{
    BIGLIST_STRNCPY(dst, src, size);
    if (size > 0)
        dst[size-1] = 0;
    return strlen(src);
}
/* <auto.end.util(ALL).define> */

