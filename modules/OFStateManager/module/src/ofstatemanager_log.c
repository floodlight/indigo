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

/******************************************************************************
 *
 *  /module/src/ofstatemanager_log.c
 *
 *  OFStateManager Log
 *
 *****************************************************************************/
#include <OFStateManager/ofstatemanager_config.h>
#include <OFStateManager/ofstatemanager.h>
#include "ofstatemanager_int.h"
#include "ofstatemanager_log.h"

/*
 * OFStateManager log struct.
 */
AIM_LOG_STRUCT_DEFINE(
                      OFSTATEMANAGER_CONFIG_LOG_OPTIONS_DEFAULT,
                      OFSTATEMANAGER_CONFIG_LOG_BITS_DEFAULT,
                      NULL, /* Custom log map */
                      OFSTATEMANAGER_CONFIG_LOG_CUSTOM_BITS_DEFAULT
                      );
