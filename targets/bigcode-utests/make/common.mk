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
# BigCode Unit Tests
#
# Common Make and build settings for all unit tests.
#
###############################################################################
ifndef MODULE
$(error Need to define $$MODULE)
endif

ifndef BIGCODE
BIGCODE:=$(abspath ../../..)
endif

#
# Default to Builder in BigCode
#
ifndef BUILDER
export BUILDER := $(BIGCODE)/Builder/unix
endif

#
# Default to local build directory
#
ifndef BUILD_DIR
export BUILD_DIR := ./build
endif

GLOBAL_CFLAGS += -DOF_WIRE_BUFFER_DEBUG
