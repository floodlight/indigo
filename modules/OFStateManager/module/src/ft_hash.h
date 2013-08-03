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

/****************************************************************
 * Hash table flow implementation (default) declarations
 *
 ****************************************************************/

#ifndef FT_HASH_H
#define FT_HASH_H

#include "ft.h"

extern ft_instance_t ft_hash_create(ft_config_t *config);

extern void ft_hash_delete(ft_instance_t ft);

extern indigo_error_t ft_hash_flow_add(ft_instance_t ft,
                                       indigo_flow_id_t id,
                                       of_flow_add_t *flow_add,
                                       ft_entry_t **entry_p);

extern indigo_error_t ft_hash_flow_delete(ft_instance_t ft,
                                          ft_entry_t *entry);

extern indigo_error_t ft_hash_flow_delete_id(ft_instance_t ft,
                                             indigo_flow_id_t id);

#endif
