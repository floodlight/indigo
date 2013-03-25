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
 *
 * @file
 * @brief AIM Syslog PVS
 *
 * @addtogroup aim-pvs-syslog
 * @{
 *
 *****************************************************************************/
#ifndef __AIM_PVS_SYSLOG_H__
#define __AIM_PVS_SYSLOG_H__

#include <AIM/aim_config.h>

#if AIM_CONFIG_INCLUDE_PVS_SYSLOG == 1

#include <AIM/aim_pvs.h>
#include <syslog.h>

/**
 * @brief Open the syslog PVS.
 * @param ident ident -- see openlog()
 * @param option option -- see openlog()
 * @param facility facility -- see openlog()
 *
 * @note Only one syslog PVS can be created at a time.
 */
aim_pvs_t* aim_pvs_syslog_open(const char* ident, int option, int facility);


/**
 * @brief Get the current syslog pvs.
 * @brief If it hasn't been created yet, the defaults will be used.
 */
aim_pvs_t* aim_pvs_syslog_get(void);


#endif /* AIM_CONFIG_INCLUDE_PVS_SYSLOG */
#endif /* __AIM_PVS_SYSLOG_H__ */
/*@}*/



