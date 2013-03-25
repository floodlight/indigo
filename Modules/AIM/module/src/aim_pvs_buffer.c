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
#include <AIM/aim_pvs_buffer.h>
#include <AIM/aim_utils.h>
#include <AIM/aim_string.h>
#include "aim_util.h"

AIM_OBJECT_ID_DEFINE(aim_buffer_pvs_obj, "aim_buffer_pvs");

typedef struct aim_pvs_buffer_entry_s {
    struct aim_pvs_buffer_entry_s* next;

    const char* data;
    int size;

} aim_pvs_buffer_entry_t;

typedef struct aim_buffer_pvs_s {
    aim_pvs_t pvs;
    aim_pvs_buffer_entry_t* list;
    aim_pvs_buffer_entry_t* last;
    aim_pvs_buffer_entry_t* next;
    int size;

} aim_pvs_buffer_t;


/**
 * Used as a sentinal for terminating iteration.
 */
static aim_pvs_buffer_entry_t entry_invalid__;

/**
 * Destructor for our objects.
 */
static void aim_pvs_buffer_destroy__(aim_object_t*);

/**
 * Output buffer function.
 */
static int
aim_pvs_buffer_vprintf__(aim_pvs_t* _pvs, const char* fmt, va_list vargs)
{
    aim_pvs_buffer_t* pvs = (aim_pvs_buffer_t*)_pvs;
    int count;
    char* p;
    va_list vacopy;

    va_copy(vacopy, vargs);
    count = aim_vsnprintf(NULL, 0, fmt, vacopy);
    va_end(vacopy);

    if(count > 0) {
        aim_pvs_buffer_entry_t* entry;
        count++;
        p = aim_zmalloc(count);
        aim_vsnprintf(p, count, fmt, vargs);
        entry = aim_zmalloc(sizeof(*entry));
        entry->data = p;
        entry->size = count;

        if(pvs->list == NULL) {
            pvs->list = entry;
            pvs->last = entry;
            pvs->next = entry;
        }
        else {
            pvs->last->next = entry;
            pvs->last = entry;
        }
        pvs->size+=count-1;
    }
    return count;
}


aim_pvs_t*
aim_pvs_buffer_create(void)
{
    aim_pvs_buffer_t* rv = aim_zmalloc(sizeof(*rv));

    AIM_OBJECT_INIT(rv, aim_buffer_pvs_obj, 0, NULL, aim_pvs_buffer_destroy__);
    rv->pvs.enabled = 1;
    rv->pvs.vprintf = aim_pvs_buffer_vprintf__;
    return (aim_pvs_t*)rv;
}

int
aim_pvs_buffer_size(aim_pvs_t* _pvs)
{
    aim_pvs_buffer_t* pvs = (aim_pvs_buffer_t*)(_pvs);

    if(AIM_OBJECT_IS_NOT(pvs, aim_buffer_pvs_obj)) {
        return -1;
    }

    return pvs->size;
}

char*
aim_pvs_buffer_get(aim_pvs_t* _pvs)
{
    aim_pvs_buffer_t* pvs = (aim_pvs_buffer_t*)(_pvs);
    char* rv;

    if(AIM_OBJECT_IS_NOT(pvs, aim_buffer_pvs_obj)) {
        return NULL;
    }

    if(pvs->size > 0) {
        char* dst;
        const char* src;
        int count;

        rv = aim_zmalloc(pvs->size+1);
        dst = rv;

        while( (src = aim_pvs_buffer_iterate(_pvs, &count)) ) {
            AIM_STRCPY(dst, src);
            dst += count-1;
        }
        return rv;
    }
    return NULL;
}

const char*
aim_pvs_buffer_iterate(aim_pvs_t* _pvs, int* size)
{
    aim_pvs_buffer_t* pvs = (aim_pvs_buffer_t*)(_pvs);
    const char* rv;

    if(AIM_OBJECT_IS_NOT(pvs, aim_buffer_pvs_obj)) {
        return NULL;
    }

    if(pvs->next == NULL || pvs->next == &entry_invalid__) {
        /* Done iterating. Reset. */
        pvs->next = pvs->list;
        return NULL;
    }

    if(size) {
        *size = pvs->next->size;
    }
    rv = pvs->next->data;
    if(pvs->next->next) {
        pvs->next = pvs->next->next;
    }
    else {
        pvs->next = &entry_invalid__;
    }
    return rv;
}


void
aim_pvs_buffer_reset(aim_pvs_t* _pvs)
{
    aim_pvs_buffer_t* pvs = (aim_pvs_buffer_t*)(_pvs);

    if(AIM_OBJECT_IS_NOT(pvs, aim_buffer_pvs_obj)) {
        return;
    }

    while(pvs->list) {
        aim_pvs_buffer_entry_t* next = pvs->list->next;
        AIM_FREE((void*)pvs->list->data);
        AIM_FREE(pvs->list);
        pvs->list = next;
    }
}

void
aim_pvs_buffer_destroy__(aim_object_t* obj)
{
    aim_pvs_buffer_reset((aim_pvs_t*)obj);
    AIM_FREE(obj);
}



















