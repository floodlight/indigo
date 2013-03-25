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
#include "biglist_int.h"
#include <stdlib.h>

void**
biglist_to_data_array(biglist_t* bl, int* size)
{
    if(bl == NULL) {
        if(size) {
            *size = 0;
        }
        return NULL;
    }
    else {
        biglist_t* ble;
        void** data = biglist_zmalloc(sizeof(void*)*biglist_length(bl));
        int i = 0;
        for(ble = bl; ble; ble = ble->next) {
            data[i++] = ble->data;
        }
        if(size) {
            *size = i;
        }
        return data;
    }
}


