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
 *  /module/inc/AIM/aim_pvs_file.h
 *
 *
 * @file
 * @brief AIM File PVS
 *
 * @addtogroup aim-pvs-file
 * @{
 *
 *****************************************************************************/
#ifndef __AIM_PVS_FILE_H__
#define __AIM_PVS_FILE_H__

#include <AIM/aim_pvs.h>

/**
 * @brief Open a PVS FILE stream.
 * @param path The filename to open.
 * @param mode The open mode.
 *
 * @note the file will be closed when you call aim_pvs_destroy()
 */
aim_pvs_t* aim_pvs_fopen(const char* path, const char* mode);


#endif /* __AIM_PVS_FILE_H__ */
/*@}*/



