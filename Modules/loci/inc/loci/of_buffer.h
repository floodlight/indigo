/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */

/****************************************************************
 *
 * Low level buffer manipulation functions
 * Requires low level type defs
 *
 ****************************************************************/

#ifndef _OF_BUFFER_H_
#define _OF_BUFFER_H_

#include <loci/loci_base.h>
#include <stdio.h>

/* Function type used for a "free" operation of a low level buffer */
typedef void (*of_buffer_free_f)(void *buf);


/****************************************************************
 *
 * Low level buffers accessors handling endian and alignment
 *
 ****************************************************************/

static inline void
buf_ipv6_get(uint8_t *buf, of_ipv6_t *val) {
    MEMCPY(val, buf, sizeof(*val));
    IPV6_NTOH(val, val); /* probably a no-op */
}

static inline void
buf_mac_get(uint8_t *buf, of_mac_addr_t *val) {
    MEMCPY(val, buf, sizeof(*val));
}

static inline void
buf_u64_get(uint8_t *buf, uint64_t *val) {
    MEMCPY(val, buf, sizeof(*val));
    *val = U64_NTOH(*val);
}

static inline void
buf_u32_get(uint8_t *buf, uint32_t *val) {
    MEMCPY(val, buf, sizeof(*val));
    *val = U32_NTOH(*val);
}

static inline void
buf_u16_get(uint8_t *buf, uint16_t *val) {
    MEMCPY(val, buf, sizeof(uint16_t));
    *val = U16_NTOH(*val);
}

static inline void
buf_u8_get(uint8_t *buf, uint8_t *val) {
    *val = *buf;
}

static inline void
buf_octets_get(uint8_t *buf, uint8_t *dst, int bytes) {
    MEMCPY(dst, buf, bytes);
}

static inline void
buf_ipv6_set(uint8_t *buf, of_ipv6_t *val) {
    /* FIXME:  If this is not a NO-OP, need to change the code */
#if 1
    MEMCPY(buf, val, sizeof(*val));
#else
    of_ipv6_t w_val;
    MEMCPY(&w_val, val sizeof(w_val));
    IPV6_HTON(w_val, w_val);
    MEMCPY(buf, &w_val, sizeof(w_val));
#endif
}

static inline void
buf_mac_addr_set(uint8_t *buf, of_mac_addr_t *val) {
    MEMCPY(buf, val, sizeof(of_mac_addr_t));
}

static inline void
buf_u64_set(uint8_t *buf, uint64_t val) {
    val = U64_HTON(val);
    MEMCPY(buf, &val, sizeof(uint64_t));
}

static inline void
buf_u32_set(uint8_t *buf, uint32_t val) {
    val = U32_HTON(val);
    MEMCPY(buf, &val, sizeof(uint32_t));
}

static inline void
buf_u16_set(uint8_t *buf, uint16_t val) {
    val = U16_NTOH(val);
    MEMCPY(buf, &val, sizeof(uint16_t));
}

static inline void
buf_u8_set(uint8_t *buf, uint8_t val) {
    *buf = val;
}

static inline void
buf_octets_set(uint8_t *buf, uint8_t *src, int bytes) {
    MEMCPY(buf, src, bytes);
}


#endif /* _OF_BUFFER_H_ */
