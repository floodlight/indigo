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
#include <AIM/aim_map.h>

int
aim_map_si_s(int* rv, const char* s, aim_map_si_t* maps, unsigned int count)
{
    unsigned int idx;
    aim_map_si_t* p;

    if(s == NULL) {
        return 0;
    }

    for(p = maps, idx = 0; (count && (idx < count)) || p->s; idx++, p++) {
        if(!AIM_STRCMP(p->s, s)) {
            if(rv) {
                *rv = p->i;
            }
            return 1;
        }
    }

    return 0;
}

int
aim_map_si_i(const char** rv, int i, aim_map_si_t* maps, unsigned int count)
{
    unsigned int idx;
    aim_map_si_t* p;
    for(p = maps, idx = 0; (count && (idx < count)) || p->s; idx++, p++) {
        if(i == p->i) {
            if(rv) {
                *rv = p->s;
            }
            return 1;
        }
    }
    return 0;
}


