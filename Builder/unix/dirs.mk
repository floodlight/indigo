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

################################################################################
#
# dirs.mk
#
# Provides output directory processing for each module
#
################################################################################
ifndef __DIRS_MK__
__DIRS_MK__=1

#
# $(MODULE) is assumed to have been specified by the including makefile
#
ifndef MODULE
$(error "MODULE name has not been specified")
endif


################################################################################
#
# BUILD_DIR
#
# This is the top-level build directory.
#
# If specified, it will be used as the default
# for directories which are not specified (below)
#
# This is optional, but without it you must specify
# the directories which follow explicitly.
#
################################################################################
ifndef BUILD_DIR_BASE
BUILD_DIR_BASE := ./build
endif

ifndef BUILD_DIR
# Check for module-specified BUILD_DIR
ifdef $(MODULE)_BUILD_DIR
BUILD_DIR=$($(MODULE)_BUILD_DIR)
endif
endif


ifndef BUILD_DIR
BUILD_DIR := $(BUILD_DIR_BASE)
endif


#
# FIXME
#
SUPERCLEAN_BUILD_DIR := $(BUILD_DIR)

#
# Various environment options for build paths
#
ifdef BUILDER_BUILD_DIR_ADD_PREFIX
BUILD_DIR:=$(BUILD_DIR)/$(BUILDER_BUILD_DIR_ADD_PREFIX)
endif

ifdef BUILDER_BUILD_DIR_INCLUDES_CHROOT
ifdef SCHROOT_CHROOT_NAME
BUILD_DIR:=$(BUILD_DIR)/$(SCHROOT_CHROOT_NAME)
endif
endif


ifdef BUILDER_BUILD_DIR_INCLUDES_HOSTNAME
BUILD_DIR:=$(BUILD_DIR)/$(shell hostname)
endif

ifdef BUILDER_BUILD_DIR_INCLUDES_ARCH
BUILD_DIR:=$(BUILD_DIR)/$(shell arch)
endif

ifdef BUILDER_BUILD_DIR_ADD_SUFFIX
BUILD_DIR:=$(BUILD_DIR)/$(BUILDER_BUILD_DIR_ADD_SUFFIX)
endif

# Substitute problem characters that may have been introduced
# through a prefix or suffix
BUILD_DIR := $(subst :,.,$(BUILD_DIR))

ifdef TOOLCHAIN
BUILD_DIR:=$(BUILD_DIR)/$(TOOLCHAIN)
endif


################################################################################
#
# OBJECT_DIR
#
# This is the top-level object directory.
#
# All object files from the module's build will
# be placed in this directory.
#
# This defaults to $(BUILD_DIR)/obj
################################################################################
ifndef OBJECT_DIR
# Check for module-specified OBJECT_DIR
ifdef $(MODULE)_OBJECT_DIR
OBJECT_DIR = $($(MODULE)_OBJECT_DIR)
else
# OBJECT_DIR not specified. Use BUILD_DIR.
ifdef BUILD_DIR
OBJECT_DIR = $(BUILD_DIR)/obj
else
$(error "neither OBJECT_DIR, $(MODULE)_OBJECT_DIR, nor BUILD_DIR specified")
endif
endif
endif


################################################################################
#
# LIBRARY_DIR
#
# This is the top-level library directory.
#
# All library files from the module's build will
# be placed in this directory.
#
# This defaults to $(BUILD_DIR)/lib
################################################################################
ifndef LIBRARY_DIR
# Check for module-specified LIBRARY_DIR
ifdef $(MODULE)_LIBRARY_DIR
LIBRARY_DIR = $($(MODULE)_LIBRARY_DIR)
else
# LIBRARY_DIR not specified. Use BUILD_DIR.
ifdef BUILD_DIR
LIBRARY_DIR = $(BUILD_DIR)/lib
else
$(error "neither LIBRARY_DIR, $(MODULE)_LIBRARY_DIR, nor BUILD_DIR specified")
endif
endif
endif


################################################################################
#
# BINARY_DIR
#
# This is the top-level binary directory.
#
# All binary files from the module's build will
# be placed in this directory.
#
# This defaults to $(BUILD_DIR)/bin
################################################################################
ifndef BINARY_DIR
# Check for module-specified BINARY_DIR
ifdef $(MODULE)_BINARY_DIR
BINARY_DIR = $($(MODULE)_BINARY_DIR)
else
# BINARY_DIR not specified. Use BUILD_DIR.
ifdef BUILD_DIR
BINARY_DIR = $(BUILD_DIR)/bin
else
$(error "neither BINARY_DIR, $(MODULE)_BINARY_DIR, nor BUILD_DIR specified")
endif
endif
endif


#
# Targets to build these directories
#
MAKE_DIR=$(OBJECT_DIR)
include $(BUILDER)/makedir.mk
MAKE_DIR=$(LIBRARY_DIR)
include $(BUILDER)/makedir.mk
MAKE_DIR=$(BINARY_DIR)
include $(BUILDER)/makedir.mk

################################################################################
#
# Information Targets for the build directories
#
################################################################################

show_dirs:
	@echo Directories
	@echo "    BUILD_DIR = $(BUILD_DIR)"
	@echo "    $(MODULE)_BUILD_DIR = $($(MODULE)_BUILD_DIR)"
	@echo "    OBJECT_DIR = $(OBJECT_DIR)"
	@echo "    $(MODULE)_OBJECT_DIR = $($(MODULE)_OBJECT_DIR)"
	@echo "    LIBRARY_DIR = $(LIBRARY_DIR)"
	@echo "    $(MODULE)_LIBRARY_DIR = $($(MODULE)_LIBRARY_DIR)"
	@echo "    BINARY_DIR = $(BINARY_DIR)"
	@echo "    $(MODULE)_BINARY_DIR = $($(MODULE)_BINARY_DIR)"
	@echo ""

endif # __DIRS_MK__
