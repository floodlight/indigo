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

/**
 * BSN OpenFlow extension definition header file
 */

#ifndef _LOCI_BSN_EXT_H_
#define _LOCI_BSN_EXT_H_

/* Mirroring for destination, bit in port_config */
#define OF_PORT_CONFIG_BSN_MIRROR_DEST (1 << 31) /* Mirror destination only */

/* Point at which mirroring is to occur */
#define OF_BSN_MIRROR_STAGE_INGRESS 0
#define OF_BSN_MIRROR_STAGE_EGRESS 1

#endif /* _LOCI_BSN_EXT_H_ */
