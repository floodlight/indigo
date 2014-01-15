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

/**
 * @file
 * @brief Internal listener interfaces
 *
 * The registration functions are declared in ofstatemanager.h.
 */

#ifndef _OFSTATEMANAGER_LISTENER_H_
#define _OFSTATEMANAGER_LISTENER_H_

#include <indigo/indigo.h>

/* Notify functions for each class of listener */
indigo_core_listener_result_t ind_core_packet_in_notify(of_packet_in_t *packet_in);
indigo_core_listener_result_t ind_core_port_status_notify(of_port_status_t *port_status);
indigo_core_listener_result_t ind_core_message_notify(indigo_cxn_id_t cxn_id, of_object_t *message);

#endif /* _OFSTATEMANAGER_LISTENER_H_ */

