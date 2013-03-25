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
biglist_from_array(biglist_t** bl, int size)
{
    int i;
    if(size == 0) {
        return NULL;
    }
    if(size == 1) {
        bl[0]->previous = NULL;
        bl[0]->next = NULL;
        return bl[0];
    }
    for(i = 0; i < size; i++) {
        bl[i]->previous = (i == 0) ? NULL : bl[i-1];
        bl[i]->next = (i==(size-1)) ? NULL : bl[i+1];
    }
    return bl[0];
}
