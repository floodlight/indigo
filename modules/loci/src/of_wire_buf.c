/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */

/****************************************************************
 *
 * of_wire_buf.c
 *
 * Implementation of more complicated of_wire_buf operations
 *
 ****************************************************************/

#include <loci/loci.h>

#if 0
static of_match_v1_t *
wire_buf_v1_to_match(of_wire_buffer_t *wbuf, int offset)
{
    of_match_v1_t *match;
    match = of_match_v1_new(OF_VERSION_1_0);
    return match;
}

/*
 * First pass at wire buf to match conversions.  These involve a lot
 * of copying and could be made more efficient.
 */
int
of_wire_buffer_of_match_get(of_object_t *obj, int offset, of_match_t *match)
{
    switch (obj->version) {
    case OF_VERSION_1_0:
        break;
    case OF_VERSION_1_1:
        break;
    case OF_VERSION_1_2:
        break;
    default:
        return OF_ERROR_VERSION;
        break;
    }

    return OF_ERROR_NONE;
}

/**
 * Write a host match structure into the wire buffer
 * @param obj The object that owns the buffer to write to
 * @param offset The start location in the wire buffer
 * @param match Pointer to the host match object
 * @param cur_len The current length of the object in the buffer
 *
 * If the current length is different than the length of the new data
 * being written, then move the remains of the buffer.  This only applies
 * to version 1.2 (though it should apply to 1.1).
 */

int
of_wire_buffer_of_match_set(of_object_t *obj, int offset, 
                            of_match_t *match, int cur_len)
{
    // of_octets_t octets;

    switch (obj->version) {
    case OF_VERSION_1_0:
        break;
    case OF_VERSION_1_1:
        break;
    case OF_VERSION_1_2:
        // of_match_v3_serialize(match, &octets);
        break;
    default:
        return OF_ERROR_VERSION;
        break;
    }

    return OF_ERROR_NONE;
}
#endif

/**
 * Replace data in the data buffer, possibly with a new
 * length or appending to buffer.
 *
 * @param wbuf The wire buffer being updated.
 * @param offset The start point of the update
 * @param old_len The number of bytes being replaced
 * @param data Source of bytes to write into the buffer
 * @param new_len The number of bytes to write
 *
 * The buffer may grow for this operation.  Current byte count
 * is pre-grow for the replace.
 *
 * The current byte count for the buffer is updated.
 * 
 */

void
of_wire_buffer_replace_data(of_wire_buffer_t *wbuf, 
                            int offset, 
                            int old_len,
                            uint8_t *data,
                            int new_len)
{
    int bytes;
    uint8_t *src_ptr, *dst_ptr;
    int cur_bytes;

    ASSERT(wbuf != NULL);

    cur_bytes = wbuf->current_bytes;

    /* Doesn't make sense; mismatch in current buffer info */
    ASSERT(old_len + offset <= wbuf->current_bytes);

    wbuf->current_bytes += (new_len - old_len); // may decrease size

    if ((old_len + offset < cur_bytes) && (old_len != new_len)) {
        /* Need to move back of buffer */
        src_ptr = &wbuf->buf[offset + old_len];
        dst_ptr = &wbuf->buf[offset + new_len];
        bytes = cur_bytes - (offset + old_len);
        MEMMOVE(dst_ptr, src_ptr, bytes);
    }

    dst_ptr = &wbuf->buf[offset];
    MEMCPY(dst_ptr, data, new_len);

    ASSERT(wbuf->current_bytes == cur_bytes + (new_len - old_len));
}
