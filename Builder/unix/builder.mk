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
# builder.mk
#
# Common builder functions
#
###############################################################################
ifndef __BUILDER_MK__
__BUILDER_MK__ := 1

#
# Rebuld the top-level $(MODULE).mk
#
ifndef MODULEDIR
MODULEDIR=$(CURDIR)
endif
ifndef TARGET_DIR
TARGET_DIR=$(CURDIR)
endif

###############################################################################
#
# TOOLCHAINS
#
# Toolchain directory locations can be specified as a colon separated path
# of directories in TOOLCHAIN_PATHS.
#
###############################################################################
#
# Add local toolchain directory to TOOLCHAIN_PATHS
#
override TOOLCHAIN_PATHS += $(BUILDER)/toolchains
override TOOLCHAIN_PATHS := $(subst :, , $(TOOLCHAIN_PATHS))
TOOLCHAIN_DIRS := $(foreach dir,$(TOOLCHAIN_PATHS),$(wildcard $(dir)/*))

# Absolute paths for all available toolchains
TOOLCHAIN_DIRS := $(filter-out %.mk,$(TOOLCHAIN_DIRS))
# Names of all toolchains available
ALL_TOOLCHAINS := $(notdir $(TOOLCHAIN_DIRS))
# Set directory for each toolchain by name
$(foreach dir,$(TOOLCHAIN_DIRS),$(eval TOOLCHAIN_DIR_$(notdir $(dir)) := $(dir $(dir))))

ifndef TOOLCHAIN
TOOLCHAIN := gcc-local
endif

#
# Make sure the toolchain directory is available
#
ifndef TOOLCHAIN_DIR_$(TOOLCHAIN)
$(error "Cannot find toolchain directory for '$(TOOLCHAIN)'")
endif

TOOLCHAIN_DIR := $(TOOLCHAIN_DIR_$(TOOLCHAIN))$(TOOLCHAIN)

endif # __BUILDER_MK__
