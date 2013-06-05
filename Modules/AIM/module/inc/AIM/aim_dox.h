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
 * @defgroup AIM AIM - Architecture and Implementation Module
 *

This module provides fundamental primitive structures for other
modules.

In general, each functional module tries to be both platform independent and
provide a clean, self-contained and flexible interface with as few assumptions
about deployment in a particular environment as possible.

The AIM module provides portability infrastructure, common good-practice
definitions, and fundamental primitives useful through the code to address
common issues such as debug and output virtualization and configuration,
logging.

The AIM module cannot depend on any other module or any external package.



 *
 * @{
 *
 * @defgroup aim-object AIM Object Management.
 * @defgroup aim-config Compile-Time Configuration
 * @defgroup aim-porting Porting Macros
 * @defgroup aim-printf Printf with Custom Datatypes
 * @defgroup aim-sparse Custom Datatype Parsing
 * @defgroup aim-pvs Virtualized Print Vectors
 * @{
 *  @defgroup aim-pvs-file File PVS
 *  @defgroup aim-pvs-buffer Buffered String PVS
 *  @defgroup aim-pvs-syslog Syslog PVS
 * @}
 * @defgroup aim-datatypes Custom Datatype Handling
 * @defgroup aim-valist Variable Argument Processing
 * @defgroup aim-string String Primitives
 * @defgroup aim-utils Generic Macros and Utilities
 * @defgroup aim-log Logging Support
 * @defgroup aim-rl Rate Limiters
 * @defgroup aim-list Inclusive Linked List Support
 * @defgroup aim-bitmap Bitmap Management
 * @defgroup aim-valgrind Valgrind Runtime Support
 * @defgroup aim-daemon Daemon and Supervisor Support
 *
 *
 * @}
 *
 */
