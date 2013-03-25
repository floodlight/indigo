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
biglist_remove_link(biglist_t* bl, biglist_t* blink)
{
    if (blink != NULL) {
        /* Found the element - splice it out */
        if (blink->previous) {
            blink->previous->next = blink->next;
        }
        if (blink->next) {
            blink->next->previous = blink->previous;
        }
        if (bl == blink) {
            /* Removing the start of the list */
            bl = blink->next;
        }
        /* The element is now an orphan */
        blink->next = NULL;
        blink->previous = NULL;
    }
    return bl;
}

