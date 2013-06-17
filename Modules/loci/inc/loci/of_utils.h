/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */

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
