/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */

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

