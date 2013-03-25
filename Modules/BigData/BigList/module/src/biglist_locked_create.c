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
 *****************************************************************************/
#include "biglist_int.h"

biglist_locked_t*
biglist_locked_create(void)
{
    biglist_locked_t* bl = biglist_zmalloc(sizeof(*bl));
    if(bl) {
#if BIGLIST_CONFIG_INCLUDE_LOCKED == 1
        sem_init(&bl->lock, 0, 1);
#endif
    }
    return bl;
}


