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

/**
 * @file
 * @brief Indigo time abstraction
 *
 * The following need to be implemented by the platform.
 *
 * indigo_time_t:  Typedef of struct for time
 * INDIGO_CURRENT_TIME: Return current time of type indigo_time_t
 * INDIGO_TIME_DIFF_ms(earlier, later): Difference in milliseconds in times
 */

#ifndef _INDIGO_TIME_H_
#define _INDIGO_TIME_H_


#if defined(INDIGO_LINUX_TIME)

#include <time.h>
#include <sys/time.h>
#include <inttypes.h>
#include <string.h>
#include <stdio.h>

/**
 * The Indigo time type
 *
 * This needs to be defined by the target.  A default definition is given
 * if INDIGO_LINUX_TIME is defined.
 *
 * If INDIGO_LINUX_TIME is defined, the time type is a uint64_t representing
 * milliseconds since epoch (Jan 1, 1970).
 */
typedef uint64_t indigo_time_t;

/**
 * Get the current timestamp
 * @returns An indigo_time_t value representing the current time
 */
#define INDIGO_CURRENT_TIME indigo_current_time()

/**
 * Time difference in milliseconds
 *
 * @param earlier The earlier, start time
 * @param later The later, end time
 * @returns An integer representing the number of ms from earlier to later
 *
 * Can represent up to about 555 hours.
 */
#define INDIGO_TIME_DIFF_ms(earlier, later) ((int) ((later) - (earlier)))

/****************************************************************
 * Linux implementation mechanisms for the above abstractions
 *
 * Includes time to string functions
 ****************************************************************/

/* Function that actually gets the current time */
#ifdef INDIGO_LINUX_TIME_MONOTONIC
/* This is the correct behavior for current usage */
static inline indigo_time_t
indigo_current_time(void) {
    struct timespec tp;
    clock_gettime(CLOCK_MONOTONIC, &tp);
    return (uint64_t)(tp.tv_sec) * 1000 + (uint64_t)(tp.tv_nsec / (1000*1000));
}
#else
/* This was the previous behavior -- still supported until verified on other platforms */
static inline indigo_time_t
indigo_current_time(void) {
    struct timeval timeval;
    gettimeofday(&timeval, NULL);
    return (uint64_t)(timeval.tv_sec) * 1000 + (uint64_t)(timeval.tv_usec) / 1000;
}
#endif

/* Printing time to a string */
#define INDIGO_TIME_FORMAT "%b %d %T"
#define INDIGO_TIME_BYTES 32

/**
 * Convert a time value to a string
 *
 * @param itime An Indigo time value
 * @param buf The buffer in which put the result
 * @param len The length of buf
 * @returns Pointer to buf
 *
 * This should be considered an internal function.  The error checking
 * is hard coded to the format used.
 */

static inline char *
indigo_time_str(indigo_time_t itime, char *buf, int len) {
    time_t timeval;
    struct tm *loctime;
    int slen;

    if (len < 24) {
        return ((char *)"time buf too short");
    }
    timeval = (time_t)itime / 1000;

    loctime = localtime(&timeval);
    strftime(buf, len, INDIGO_TIME_FORMAT, loctime);
    slen = strlen(buf);

    sprintf(&buf[slen], ".%03d", (int)(itime % 1000));

    return buf;
}

/**
 * Convert Indigo time value to a string
 *
 * @param itime Time to convert
 * @param buf Buffer in which to write time string
 * @param len Length of buffer available
 */
#define INDIGO_TIME_TO_STRING(itime, buf, len) \
    indigo_time_str((itime), (buf), (len))

#endif /* INDIGO_LINUX_TIME */


#if defined(INDIGO_STUB_TIME)
typedef uint64_t indigo_time_t;
#define INDIGO_CURRENT_TIME (0)
#define INDIGO_TIME_DIFF_ms(_a,_b) (0)
#endif

#endif /* _INDIGO_TIME_H_ */
