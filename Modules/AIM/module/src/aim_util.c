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
 *  /module/src/aim_util.c
 *
 *  AIM Utilities
 *
 *****************************************************************************/
#include <AIM/aim_config.h>
#include <AIM/aim.h>
#include "aim_int.h"

void*
aim_zmalloc(int size)
{
    void* p = AIM_MALLOC(size);
    if(p) {
        AIM_MEMSET(p, 0, size);
    }
    return p;
}

void*
aim_memdup(void* src, int size)
{
    return aim_memndup(src, size, size);
}

void*
aim_memndup(void* src, int src_size, int alloc_size)
{
	void* rv;
	if(alloc_size < src_size) {
		alloc_size = src_size;
	}
    rv = AIM_MALLOC(alloc_size);
    AIM_MEMCPY(rv, src, src_size);
    return rv;
}
