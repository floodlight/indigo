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

/**************************************************************************//**
 *
 * @file
 * @brief Valgrind-specific features
 *
 * @addtogroup aim-valgrind
 * @{
 *
 *****************************************************************************/
#ifndef __AIM_VALGRIND_H__
#define __AIM_VALGRIND_H__

/**
 * @brief Return current running-under-valgrind status.
 * @returns 0 If not running under valgrind.
 * @returns 1 If running under valgrind.
 * @returns -1 If status is unknown (support not compiled in).
 */
int aim_valgrind_status(void);


#endif /* __AIM_VALGRIND_H */
/* @}*/

