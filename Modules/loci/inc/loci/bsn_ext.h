/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */

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
