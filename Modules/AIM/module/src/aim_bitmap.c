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
 *
 *****************************************************************************/
#include <AIM/aim_config.h>
#include <AIM/aim_bitmap.h>
#include <AIM/aim.h>
#include "aim_int.h"

aim_bitmap_t*
aim_bitmap_alloc(aim_bitmap_t* rv, int bitcount)
{
    if(rv == NULL) {
        rv = aim_zmalloc(sizeof(*rv));
        rv->hdr.allocated = 1;
    }
    else {
        AIM_MEMSET(rv, 0, sizeof(*rv));
    }

    rv->hdr.wordcount = AIM_BITMAP_WORD_COUNT(bitcount);
    rv->hdr.words = aim_zmalloc(rv->hdr.wordcount*sizeof(aim_bitmap_word_t));
    rv->hdr.maxbit = bitcount-1;
    return rv;
}

void
aim_bitmap_free(aim_bitmap_t* bmap)
{
    if(bmap) {
        AIM_FREE(bmap->hdr.words);
        if(bmap->hdr.allocated) {
            AIM_FREE(bmap);
        }
    }
}

