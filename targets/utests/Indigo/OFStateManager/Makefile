################################################################
#
#        Copyright 2013, Big Switch Networks, Inc. 
# 
# Licensed under the Eclipse Public License, Version 1.0 (the
# "License"); you may not use this file except in compliance
# with the License. You may obtain a copy of the License at
# 
#        http://www.eclipse.org/legal/epl-v10.html
# 
# Unless required by applicable law or agreed to in writing,
# software distributed under the License is distributed on an
# "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
# either express or implied. See the License for the specific
# language governing permissions and limitations under the
# License.
#
################################################################

###############################################################################
#
#  /utest/Makefile
#
#  BigData Unit Testing Makefile
#
###############################################################################

ifndef BIGCODE
BIGCODE:=$(dir $(lastword $(MAKEFILE_LIST)))/../../../..
endif

MODULE := OFStateManager_utest
TEST_MODULE := OFStateManager
NOMODULEMAKE=1

LOCI_SOURCE_DIR := ${BIGCODE}/Modules/loci/src

# These indicate Linux specific implementations to be used for
# various features
GLOBAL_CFLAGS += -DINDIGO_LINUX_LOGGING
GLOBAL_CFLAGS += -DINDIGO_LINUX_TIME
GLOBAL_CFLAGS += -DINDIGO_FAULT_ON_ASSERT
GLOBAL_CFLAGS += -DINDIGO_MEM_STDLIB
GLOBAL_CFLAGS += -DOF_OBJECT_TRACKING
GLOBAL_CFLAGS += -Wall
GLOBAL_CFLAGS += -I${LOCI_SOURCE_DIR}
GLOBAL_CFLAGS += -DAIM_CONFIG_INCLUDE_MODULES_INIT=1
GLOBAL_CFLAGS += -DAIM_CONFIG_INCLUDE_MAIN=1

GLOBAL_CFLAGS += -I${BIGCODE}/Modules/Indigo/OFConnectionManager/module/inc
GLOBAL_CFLAGS += -DOFSTATEMANAGER_CONFIG_INCLUDE_UCLI=0
GLOBAL_CFLAGS += -DSOCKETMANAGER_CONFIG_INCLUDE_UCLI=0

DEPENDMODULES += AIM BigList SocketManager loci locitest indigo murmur cjson Configuration

GLOBAL_LINK_LIBS += -lm


include ../../make/utestmodule.mk
