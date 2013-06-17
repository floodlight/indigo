/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */

#include <stdarg.h>

#include "loci_log.h"

#include <loci/loci.h>

static int
loci_null_logger(loci_log_level_t level,
                 const char *fname, const char *file, int line,
                 const char *format, ...)
{
    return 0;
}

loci_logger_f loci_logger = loci_null_logger;
