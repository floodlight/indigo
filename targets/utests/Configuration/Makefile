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
include ../../../init.mk

MODULE := Configuration_utest
TEST_MODULE := Configuration

DEPENDMODULES := AIM SocketManager indigo loci BigList cjson timer_wheel debug_counter histogram cjson_util

# These indicate Linux specific implementations to be used for
# various features
GLOBAL_CFLAGS += -DINDIGO_LINUX_LOGGING
GLOBAL_CFLAGS += -DINDIGO_LINUX_TIME
GLOBAL_CFLAGS += -DINDIGO_FAULT_ON_ASSERT
GLOBAL_CFLAGS += -DINDIGO_MEM_STDLIB
GLOBAL_CFLAGS += -g
GLOBAL_CFLAGS += -DCONFIGURATION_CONFIG_INCLUDE_UCLI=0
GLOBAL_CFLAGS += -DSOCKETMANAGER_CONFIG_INCLUDE_UCLI=0

DEPENDMODULE_HEADERS := IOF

GLOBAL_LINK_LIBS += -lpthread -lpcap -lm

include $(BUILDER)/build-unit-test.mk

