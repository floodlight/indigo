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
 * Some utilities provided based on LOCI code generation
 *
 ****************************************************************/

#include <loci/of_utils.h>


/**
 * Check if the given port is used as an output for any entry on the list
 * @param actions The list of actions being checked
 * @param outport The port being sought
 * @returns Boolean, true if entry has an output action to outport
 *
 * @fixme VERSION Currently only OF 1.0 supported
 * @fixme Check for error return in accessor
 *
 * If outport is "wildcard", the test should be ignored, so return true
 */

int
of_action_list_has_out_port(of_list_action_t *actions, of_port_no_t outport)
{
    of_action_t elt;
    of_action_output_t *output;
    int loop_rv;
    of_port_no_t port_no;
    int rv = 0;

    if (outport == OF_PORT_DEST_WILDCARD) { /* Same as OFPP_ANY */
        return 1;
    }

    output = &elt.output;
    OF_LIST_ACTION_ITER(actions, &elt, loop_rv) {
        if (output->object_id == OF_ACTION_OUTPUT) {
            of_action_output_port_get(output, &port_no);
            if (port_no == outport) {
                rv = 1;
                break;
            }
        }
    }

    return rv;
}

