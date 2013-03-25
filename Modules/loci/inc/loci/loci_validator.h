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

/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */


/**
 *
 * AUTOMATICALLY GENERATED FILE.  Edits will be lost on regen.
 *
 * Declarations of message validation functions. These functions check that an
 * OpenFlow message is well formed. Specifically, they check internal length
 * fields.
 */

#if !defined(_LOCI_VALIDATOR_H_)
#define _LOCI_VALIDATOR_H_

#include <loci/loci.h>

/*
 * Validate an OpenFlow message.
 * @return 0 if message is valid, -1 otherwise.
 */
extern int of_validate_message(of_message_t msg, int len);

#endif /* _LOCI_VALIDATOR_H_ */
