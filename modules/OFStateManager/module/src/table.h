/****************************************************************
 *
 *        Copyright 2014, Big Switch Networks, Inc.
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

#ifndef _OFSTATEMANAGER_TABLE_H_
#define _OFSTATEMANAGER_TABLE_H_

#include <stdint.h>
#include <loci/loci.h>
#include <indigo/error.h>
#include <indigo/fi.h>
#include <indigo/of_state_manager.h>

typedef struct ind_core_table_s {
    char *name;
    void *priv;
    const indigo_core_table_ops_t *ops;
} ind_core_table_t;

ind_core_table_t *ind_core_table_get(uint8_t table_id);

#endif

