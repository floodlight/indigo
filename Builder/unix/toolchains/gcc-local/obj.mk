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
# GCC-Local Object File Rules
#
################################################################################
ifdef OBJECT_DIR

THIS_DIR := $(dir $(lastword $(MAKEFILE_LIST)))

MAKE_DIR=$(OBJECT_DIR)/$($(TARGET)_SUBDIR)
include $(BUILDER)/makedir.mk

ifndef GCC
GCC := gcc
endif

ifdef DEBUG
DEBUG_FLAGS = -g
CINFO="[debug]"
else
CINFO="[release]"
endif

ifdef COVERAGE
COVERAGE_FLAGS := --coverage
endif

ifdef ANALYZE
ANALYZE_FLAGS := --analyze -c
endif

ifndef ALLOW_DECLARATION_AFTER_STATEMENT
GCC_WARNING_FLAGS += -Wdeclaration-after-statement
endif

#
# Default options based on GCC version.
#
GCC_WARNING_FLAGS := -Wall -Wno-missing-field-initializers

ifndef NO_USE_GCC_VERSION_TOOL
#
# Build version tool
#
ifndef GCC_VERSION_TOOL_NAME
ifeq ($(shell uname -s),Darwin)
GCC_VERSION_TOOL_NAME := $(shell mktemp -t X)
else
GCC_VERSION_TOOL_NAME := $(shell mktemp)
endif

GCC_VERSION_TOOL_BUILD := $(shell $(GCC) -o $(GCC_VERSION_TOOL_NAME) $(THIS_DIR)/gcc-version-tool.c)
ifeq ($(shell $(GCC_VERSION_TOOL_NAME) gt 4400),true)
#GCC_VERSION_SPECIFIC_WARNING_FLAGS += -Wunused-result
endif
endif
endif

GCC_WARNING_FLAGS += $(GCC_VERSION_SPECIFIC_WARNING_FLAGS)


#
# We enable -Werror for every build by default.
# Sadly, this cannot always be enforced, particularly when
# including external code.
#
# You must disable -Werror explicitly in your target if
# you find yourself in such a situation.
#
#
ifndef GCC_NO_WERROR
GCC_WARNING_FLAGS += -Werror
endif

ifdef PEDANTIC
GCC_PEDANTIC_FLAGS += -std=c99 -pedantic-errors -Wextra
endif

# Rule to build object files from c files for this target.
# Note that we also generate dependencies automatically with -MD
$(OBJECT_DIR)/$($(TARGET)_SUBDIR)/%.o: $($(TARGET)_SUBDIR)/%.c
	@echo "    Compiling$(CINFO): $(TARGET)::$(notdir $<)"
	$(VERBOSE)$(GCC) $(DEBUG_FLAGS) $(COVERAGE_FLAGS) $(ANALYZE_FLAGS) -I. $($(TARGET)_INCLUDES) $($(TARGET)_CFLAGS) $(GLOBAL_INCLUDES) $(GLOBAL_CFLAGS) $(GCC_PEDANTIC_FLAGS) $(GCC_FLAGS) $(GCC_WARNING_FLAGS) -MD -c $< -o $@

# Dependecies Files for these targets
$(TARGET)_DEPS := $($(TARGET)_OBJS:%.o=%.d)

$(OBJECT_DIR)/$($(TARGET)_SUBDIR)/%.o: TARGET:=$(TARGET)

endif

