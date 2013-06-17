/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */

/*
 * @fixme THIS FILE NEEDS CLEANUP.  It may just go away.
 * 
 * Low level internal header file.  Defines inheritance mechanism for
 * LOCI objects.  In general, the routines in this file should not be
 * called directly.  Rather the class-specific operations should be 
 * used from loci.h.
 *
 * TREAT THESE FUNCTIONS AS PRIVATE.  THEY ARE GENERALLY HELPER
 * FUNCTIONS FOR LOCI TYPE SPECIFIC IMPLEMENTATIONS
 */

#if !defined(_OF_OBJECT_H_)
#define _OF_OBJECT_H_

#include <loci/of_buffer.h>
#include <loci/of_match.h>
#include <loci/loci_base.h>
#include <loci/of_message.h>

#if defined(OF_OBJECT_TRACKING)
#include <BigList/biglist.h>
#endif

/**
 * This is the number of bytes reserved for metadata in each
 * of_object_t instance.
 */
#define OF_OBJECT_METADATA_BYTES 32

/****************************************************************
 * General list operations: first, next, append_setup, append_advance
 ****************************************************************/

/* General list first operation */
extern int of_list_first(of_object_t *parent, of_object_t *child);

/* General list next operation */
extern int of_list_next(of_object_t *parent, of_object_t *child);

/* General list append bind operation */
extern int of_list_append_bind(of_object_t *parent, of_object_t *child);

/* Append a copy of item to list */
extern int of_list_append(of_object_t *list, of_object_t *item);

extern of_object_t *of_object_new(int bytes);
extern of_object_t * of_object_dup_(of_object_t *src);

/**
 * Callback function prototype for deleting an object
 */
typedef void (*of_object_delete_callback_f)(of_object_t *obj);

#if defined(OF_OBJECT_TRACKING)
/**
 * When tracking is enabled, the location of each new or dup
 * call of an OF object is recorded and a list is kept of all
 * outstanding objects.
 *
 * This dovetails with using objects to track outstanding operations
 * for barrier processing.
 */

/**
 * Global tracking stats
 */
typedef struct loci_object_track_s {
    biglist_t *objects;
    int count_current;
    uint32_t count_max;
    uint32_t allocs;
    uint32_t deletes;
} loci_object_track_t;

extern loci_object_track_t loci_global_tracking;

/* Remap dup call to tracking */
extern of_object_t * of_object_dup_tracking(of_object_t *src,
                                            const char *file, int line);
#define of_object_dup(src) of_object_dup_tracking(src, __FILE__, __LINE__)
extern void of_object_track(of_object_t *obj, const char *file, int line);

extern void of_object_track_output(of_object_t *obj, loci_writer_f writer, void* cookie); 
extern void of_object_track_report(loci_writer_f writer, void* cookie); 

/**
 * The data stored in each object related to tracking and
 * The LOCI client may install a delete callback function to allow
 * the notification of an object's destruction.
 */

typedef struct of_object_track_info_s {
    of_object_delete_callback_f delete_cb;  /* To be implemented */
    void *delete_cookie;

    /* Track file and line where allocated */
    const char *file;
    int line;
    biglist_t *bl_entry; /* Pointer to self */
    uint32_t magic; /* validation value */
} of_object_track_info_t;

#define OF_OBJECT_TRACKING_MAGIC 0x11235813
#else

/* Use native dup call */
#define of_object_dup of_object_dup_

/**
 * When tracking is not enabled, we still support a delete callback
 */

typedef struct of_object_track_info_s {
    of_object_delete_callback_f delete_cb;  /* To be implemented */
    void *delete_cookie;
} of_object_track_info_t;

#endif

extern int of_object_xid_set(of_object_t *obj, uint32_t xid);
extern int of_object_xid_get(of_object_t *obj, uint32_t *xid);

/* Bind a buffer to an object, usually for parsing the buffer */
extern int of_object_buffer_bind(of_object_t *obj, uint8_t *buf, 
                                 int bytes, of_buffer_free_f buf_free);


/**
 * Steal a wire buffer from an object.
 * @param obj The object whose buffer is being removed
 * @param buffer[out] A handle for the pointer to the uint8_t * returned
 *
 * The wire buffer is taken from the object and its wirebuffer is set to
 * NULL.  The ref_count of the wire buffer is not changed.
 */
extern void of_object_wire_buffer_steal(of_object_t *obj, uint8_t **buffer);
extern int of_object_append_buffer(of_object_t *dst, of_object_t *src);

extern of_object_t *of_object_new_from_message(of_message_t msg, int len);

/* Delete an OpenFlow object without reference to its type */
extern void of_object_delete(of_object_t *obj);

int of_object_can_grow(of_object_t *obj, int new_len);

#endif /* _OF_OBJECT_H_ */
