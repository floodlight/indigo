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
 *  /module/src/ofconnectionmanager_log.c
 *
 *  OFConnectionManager Log
 *
 *****************************************************************************/
#include <OFConnectionManager/ofconnectionmanager_config.h>
#include <OFConnectionManager/ofconnectionmanager.h>
#include "ofconnectionmanager_int.h"
#include "ofconnectionmanager_log.h"

/*
 * OFConnectionManager log struct.
 */
AIM_LOG_STRUCT_DEFINE(
                      OFCONNECTIONMANAGER_CONFIG_LOG_OPTIONS_DEFAULT,
                      OFCONNECTIONMANAGER_CONFIG_LOG_BITS_DEFAULT,
                      NULL, /* Custom log map */
                      OFCONNECTIONMANAGER_CONFIG_LOG_CUSTOM_BITS_DEFAULT
                      );
