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
 *
 *
 *****************************************************************************/
#include "biglist_int.h"
#include <stdio.h>

/*
 * This should be done with the TPrintf library but I don't want the
 * dependency for something so small.
 */
biglist_t*
biglist_dump(biglist_t* bl, void (*dump_element)(biglist_t* el))
{
    biglist_t* ble;
    printf("BigList @ %p = {\n", (void*)bl);
    for(ble = bl; ble; ble = ble->next) {
        printf("    biglist_t @%p= {\n", (void*)ble);
        printf("        data=%p, previous=%p, next=%p\n",
               (void*)ble->data, (void*)ble->previous, (void*)ble->next);
        if(dump_element) {
            dump_element(ble->data);
        }
        printf("    }\n");
    }
    printf("}\n");
    return bl;
}
