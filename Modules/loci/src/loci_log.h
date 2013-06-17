/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */

#if !defined(_LOCI_LOG_H_)
#define _LOCI_LOG_H_

#include <loci/loci_base.h>
#include <loci/of_match.h>
#include <stdio.h>

/* g++ requires this to pick up PRI, etc.
 * See  http://gcc.gnu.org/ml/gcc-help/2006-10/msg00223.html
 */
#if !defined(__STDC_FORMAT_MACROS)
#define __STDC_FORMAT_MACROS
#endif
#include <inttypes.h>

/**
 * Per level log macros.  printf semantics
 */

#define LOCI_LOG_COMMON(level, ...) loci_logger(level, __func__, __FILE__, __LINE__, __VA_ARGS__)
#define LOCI_LOG_TRACE(...) LOCI_LOG_COMMON(LOCI_LOG_LEVEL_TRACE, __VA_ARGS__)
#define LOCI_LOG_VERBOSE(...) LOCI_LOG_COMMON(LOCI_LOG_LEVEL_VERBOSE, __VA_ARGS__)
#define LOCI_LOG_INFO(...) LOCI_LOG_COMMON(LOCI_LOG_LEVEL_INFO, __VA_ARGS__)
#define LOCI_LOG_WARN(...) LOCI_LOG_COMMON(LOCI_LOG_LEVEL_WARN, __VA_ARGS__)
#define LOCI_LOG_ERROR(...) LOCI_LOG_COMMON(LOCI_LOG_LEVEL_ERROR, __VA_ARGS__)
#define LOCI_LOG_MSG(...) LOCI_LOG_COMMON(LOCI_LOG_LEVEL_MSG, __VA_ARGS__)

#endif /* _LOCI_LOG_H_ */
