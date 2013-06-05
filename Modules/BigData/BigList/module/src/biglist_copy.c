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

#include "biglist_int.h"

biglist_t*
biglist_copy(biglist_t* src)
{
    biglist_t* ble;
    biglist_t* rv = NULL;
    for(ble = biglist_last(src); ble; ble = ble->previous) {
        rv = biglist_prepend(rv, ble->data);
    }
    return rv;
}
