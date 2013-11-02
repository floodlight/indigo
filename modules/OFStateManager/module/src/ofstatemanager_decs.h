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

/*
 * Internal declarations.  These are broken out to avoid
 * circular dependencies
 */

#ifndef OFSTATEMANAGER_DECS_H
#define OFSTATEMANAGER_DECS_H

#include "ofstatemanager_int.h"

#include "ft.h"

extern int ind_core_init_done;
extern int ind_core_module_enabled;

/* State manager configuration data, shared within module */
extern ind_core_of_config_t ind_core_of_config;

/* The flow table instance visible to all parts of the module */
extern ft_instance_t ind_core_ft;

/**
 * Generate an XID for a message from this switch (not a reply)
 */

extern int ind_core_xid_alloc(void);

extern void ind_core_flow_entry_delete(ft_entry_t *entry,
                                       indigo_fi_flow_removed_t reason,
                                       indigo_cxn_id_t cxn_id);

#endif /* OFSTATEMANAGER_DECS_H */
