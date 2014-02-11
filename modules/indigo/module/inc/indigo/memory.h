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
 * @brief Memory management abstraction
 *
 * These are the vectors that need to be defined.  They are implemented
 * as macros.  If INDIGO_MEM_STDLIB is defined, then the Linux versions
 * are assumed available from string.h and stdlib.h
 */

#ifndef _INDIGO_MEMORY_H_
#define _INDIGO_MEMORY_H_

/* Standard Linux Definitions */

#if defined(INDIGO_MEM_STDLIB)

/* @todo Document these */

#define INDIGO_MEM_MOVE(dest, src, bytes)   memmove(dest, src, bytes)
#define INDIGO_MEM_SET(dest, val, bytes)    memset(dest, val, bytes)
#define INDIGO_MEM_CLEAR(dest, bytes)       memset(dest, 0, bytes)
#define INDIGO_MEM_COPY(dest, src, bytes)   memcpy(dest, src, bytes)
#define INDIGO_MEM_COMPARE(a, b, bytes)     memcmp(a, b, bytes)

#endif /* INDIGO_MEM_STDLIB */

#endif /* _INDIGO_MEMORY_H_ */
