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

ifndef ROOT
ROOT := $(dir $(lastword $(MAKEFILE_LIST)))/../..
endif

ifndef INDIGO
INDIGO := $(ROOT)
endif

ifndef BUILDER
BUILDER := $(INDIGO)/Builder/unix
endif

ifndef BUILD_DIR
export BUILD_DIR := ./build
endif

ALLOW_DECLARATION_AFTER_STATEMENT = 1

MODULE := hindex_benchmark
include $(BUILDER)/standardinit.mk

MODULE_DIRS := $(INDIGO)/Modules $(ROOT)/Modules

LIBRARY := hindex_benchmark_main
$(LIBRARY)_SUBDIR := $(dir $(lastword $(MAKEFILE_LIST)))
include $(BUILDER)/lib.mk

MODULEMANIFEST := $(INDIGO)/Modules/Manifest.mk

DEPENDMODULES := hindex AIM
include $(BUILDER)/dependmodules.mk

BINARY := hindex-benchmark

$(BINARY)_LIBRARIES := $(LIBRARY_TARGETS)
include $(BUILDER)/bin.mk

include $(BUILDER)/targets.mk

GLOBAL_CFLAGS += -g
GLOBAL_CFLAGS += -O3
GLOBAL_LINK_LIBS += -lrt

ifdef USE_CALLGRIND
GLOBAL_CFLAGS += -DUSE_CALLGRIND
endif
