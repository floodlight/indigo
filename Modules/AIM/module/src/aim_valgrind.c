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
#include <AIM/aim_valgrind.h>

#if AIM_CONFIG_INCLUDE_VALGRIND == 1
#include <valgrind/valgrind.h>
#endif


int
aim_valgrind_status(void)
{
    int rv = -1;
#if AIM_CONFIG_INCLUDE_VALGRIND == 1
    rv = RUNNING_ON_VALGRIND;
#endif
    return rv;
}

