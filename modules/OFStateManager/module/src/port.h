/****************************************************************
 *
 *        Copyright 2015, Big Switch Networks, Inc.
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
 * Internal APIs implemented by port.c
 */

#ifndef OFSTATEMANAGER_PORT_H
#define OFSTATEMANAGER_PORT_H

#include <slot_allocator/slot_allocator.h>

struct ind_core_port {
    of_port_no_t port_no;
};

struct ind_core_queue {
    of_port_no_t port_no;
    uint32_t queue_id;
};

extern struct slot_allocator *ind_core_port_allocator;
extern struct ind_core_port ind_core_ports[OFSTATEMANAGER_CONFIG_MAX_PORTS]; 

extern struct slot_allocator *ind_core_queue_allocator;
extern struct ind_core_queue ind_core_queues[OFSTATEMANAGER_CONFIG_MAX_QUEUES]; 

/* Number of ports currently registered */
extern int ind_core_ports_registered;

void ind_core_port_init(void);
void ind_core_port_finish(void);

#endif
