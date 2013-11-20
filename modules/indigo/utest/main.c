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

/* FILE HEADER PLACEHOLDER */

/**
 * @file
 * @brief Very simple compilation test fro indigo include files
 */

#include <indigo/error.h>
#include <indigo/memory.h>
#include <indigo/types.h>
#include <indigo/time.h>
#include <indigo/assert.h>
#include <indigo/module.h>
#include <indigo/of_connection_manager.h>
#include <indigo/of_state_manager.h>
#include <indigo/forwarding.h>
#include <indigo/port_manager.h>

#define AIM_LOG_MODULE_NAME indigo
#include <AIM/aim_log.h>

/*
 * Indigo log struct.
 */
AIM_LOG_STRUCT_DEFINE(
                      0x1,  /* enabled */
                      0xFFFF,  /* Initial flags */
                      NULL, /* Custom log map */
                      0x0   /* Initial custom flags */
                      );

int
main(int argc, char* argv[])
{
    INDIGO_ASSERT(1==1);
    AIM_LOG_INFO("Okay.");
    return 0;
}
