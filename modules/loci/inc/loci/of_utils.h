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

/* Copyright 2013, Big Switch Networks, Inc. */

/****************************************************************
 * File: of_utils.h
 *
 * Header file for some utilities provided based on LOCI code generation
 *
 ****************************************************************/

#ifndef OF_UTILS_H
#define OF_UTILS_H

#include <loci/loci.h>

extern int of_action_list_has_out_port(of_list_action_t *actions,
                                       of_port_no_t outport);

#endif
