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
 *  /module/inc/AIM/aim_pvs_buffer.h
 *
 *
 * @file
 * @brief AIM Buffer PVS
 *
 * @addtogroup aim-pvs-buffer
 * @{
 *
 *****************************************************************************/
#ifndef __AIM_PVS_BUFFER_H__
#define __AIM_PVS_BUFFER_H__

#include <AIM/aim_pvs.h>

/**
 * @brief Create a PVS which collects and buffers output.
 * @note When finished, you should call aim_pvs_destroy().
 */
aim_pvs_t* aim_pvs_buffer_create(void);

/**
 * @brief the current size of the output.
 * @param pvs The PVS
 */
int aim_pvs_buffer_size(aim_pvs_t* pvs);

/**
 * @brief Get the entire output buffer.
 * @param pvs The pvs.
 * @returns A new buffer containing the entire output.
 * @note You must free the buffer when you're done.
 */
char* aim_pvs_buffer_get(aim_pvs_t* pvs);

/**
 * @brief Discard all output.
 * @param pvs The pvs.
 */
void aim_pvs_buffer_reset(aim_pvs_t* pvs);

/**
 * @brief Iterate over all buffers.
 * @param pvs The pvs.
 * @param [out] size The size of the returned data.
 * @returns The next buffer if available.
 * @returns NULL if no more data is available.
 * @note The returned pointer must not be freed.
 */
const char* aim_pvs_buffer_iterate(aim_pvs_t* pvs, int* size);


#endif /* __AIM_PVS_BUFFER_H__ */
/*@}*/
