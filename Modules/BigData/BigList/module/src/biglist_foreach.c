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

int
biglist_foreach(biglist_t* bl, biglist_iter_f iter, void* cookie)
{
    int rv = 0;
    while(bl) {
        rv = iter(bl->data, cookie);
        if(rv < 0) {
            /* abort processing */
            break;
        }
        bl = bl->next;
    }
    /*
     * If we processed all elements, we will return 0.
     * If we processed a subset, we will return the
     * result of the aborting iteration.
     */
    return (rv < 0) ? rv : 0;
}

