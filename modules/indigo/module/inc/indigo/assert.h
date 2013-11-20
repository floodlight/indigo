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
 * @brief Debug assertion
 *
 * The macro INDIGO_ASSERT(cond) may be defined by the target.
 * If it is not defined before the inclusion of this
 * file, it will default to a no-op.
 *
 * If INDIGO_FAULT_ON_ASSERT is defined,
 * force a segmentation fault if an assert fails.  This is useful if
 * using a debugger.
 *
 * This requires local modules AIM logging to be included before referenced
 */

#ifndef _INDIGO_ASSERT_H_
#define _INDIGO_ASSERT_H_

#if defined(INDIGO_FAULT_ON_ASSERT)

#define INDIGO_ASSERT(cond) do if (!(cond)) {                           \
            AIM_LOG_ERROR("%s.%d: Assert %s failed\n",                  \
                          __FILE__, __LINE__, #cond);                   \
            *((volatile int *)0) = 1;                                   \
        } while (0)

#elif !defined(INDIGO_ASSERT)

/* No op if not defined otherwise */
#define INDIGO_ASSERT(cond)

#endif

#endif /* _INDIGO_ASSERT_H_ */
