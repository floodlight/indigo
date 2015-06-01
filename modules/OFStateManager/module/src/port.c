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
 * Port/queue registration APIs
 *
 * These APIs allow OFStateManager to iterate over available ports and queues.
 */

#include <indigo/of_state_manager.h>
#include <slot_allocator/slot_allocator.h>
#include "ofstatemanager_decs.h"
#include "ofstatemanager_log.h"
#include "port.h"

struct slot_allocator *ind_core_port_allocator;
struct ind_core_port ind_core_ports[OFSTATEMANAGER_CONFIG_MAX_PORTS]; 

struct slot_allocator *ind_core_queue_allocator;
struct ind_core_queue ind_core_queues[OFSTATEMANAGER_CONFIG_MAX_QUEUES]; 

int ind_core_ports_registered;

void
indigo_core_port_register(of_port_no_t port_no, struct ind_core_port **handle)
{
    uint32_t slot = slot_allocator_alloc(ind_core_port_allocator);
    if (slot == SLOT_INVALID) {
        AIM_DIE("Attempted to register more than %d ports", OFSTATEMANAGER_CONFIG_MAX_PORTS);
    }

    AIM_ASSERT(slot < OFSTATEMANAGER_CONFIG_MAX_PORTS);
    *handle = &ind_core_ports[slot];
    ind_core_ports[slot].port_no = port_no;
    ind_core_ports_registered++;
}

void
indigo_core_port_unregister(struct ind_core_port *handle)
{
    AIM_ASSERT(ind_core_ports_registered > 0);
    ind_core_ports_registered--;
    uint32_t slot = handle - ind_core_ports;
    AIM_ASSERT(slot < OFSTATEMANAGER_CONFIG_MAX_PORTS);
    slot_allocator_free(ind_core_port_allocator, slot);
}

void
indigo_core_queue_register(of_port_no_t port_no, uint32_t queue_id, struct ind_core_queue **handle)
{
    uint32_t slot = slot_allocator_alloc(ind_core_queue_allocator);
    if (slot == SLOT_INVALID) {
        AIM_DIE("Attempted to register more than %d queues", OFSTATEMANAGER_CONFIG_MAX_QUEUES);
    }

    AIM_ASSERT(slot < OFSTATEMANAGER_CONFIG_MAX_QUEUES);
    *handle = &ind_core_queues[slot];
    ind_core_queues[slot].port_no = port_no;
    ind_core_queues[slot].queue_id = queue_id;
}

void
indigo_core_queue_unregister(struct ind_core_queue *handle)
{
    uint32_t slot = handle - ind_core_queues;
    AIM_ASSERT(slot < OFSTATEMANAGER_CONFIG_MAX_QUEUES);
    slot_allocator_free(ind_core_queue_allocator, slot);
}

void
ind_core_port_init(void)
{
    ind_core_port_allocator = slot_allocator_create(OFSTATEMANAGER_CONFIG_MAX_PORTS);
    ind_core_queue_allocator = slot_allocator_create(OFSTATEMANAGER_CONFIG_MAX_QUEUES);
}
