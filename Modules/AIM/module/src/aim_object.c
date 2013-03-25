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
#include <AIM/aim_object.h>
#include "aim_util.h"

aim_object_t*
aim_object_create(unsigned int size, const char* id, int subtype,
                  void* cookie, aim_object_dtor dtor)
{
    aim_object_t* object;

    if(size < sizeof(*object)) {
        size = sizeof(*object);
    }

    object = aim_zmalloc(size);
    if(object) {
        AIM_OBJECT_INIT(object, id, subtype, cookie, dtor);
    }
    return object;
}

void
aim_object_destroy(aim_object_t* obj)
{
    if(obj) {
        if(obj->destructor) {
            obj->destructor(obj);
        }
    }
}
