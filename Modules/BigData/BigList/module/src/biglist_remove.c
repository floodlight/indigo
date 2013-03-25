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

biglist_t*
biglist_remove(biglist_t* bl, const void* data)
{
    biglist_t* ble;

    /* Find the data */
    for(ble = bl; ble && ble->data != data; ble = ble->next);

    if(ble != NULL) {
        bl = biglist_remove_link(bl, ble);
        BIGLIST_FREE(ble);
    }
    return bl;
}
