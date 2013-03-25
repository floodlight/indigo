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
# Generic Object File Rules
#
################################################################################

#
# Generate Source and Object Lists for this $(TARGET).
# TARGET is specified by the calling makefile.
#
ifndef $(TARGET)_SRCS
$(TARGET)_SRCS := $(wildcard $($(TARGET)_SUBDIR)/*.c)
endif

$(TARGET)_LSRCS := $(notdir $($(TARGET)_SRCS))
$(TARGET)_LOBJS := $(addsuffix .o, $(basename $($(TARGET)_LSRCS)))
$(TARGET)_OBJS := $(addprefix $(OBJECT_DIR)/$($(TARGET)_SUBDIR)/, $($(TARGET)_LOBJS)) $(EXTRA_$(TARGET)_OBJS)

ALL_TARGETS := $(ALL_TARGETS) $(TARGET)

#
# Rule to build object and dependency files.
# This is provided directly by the toolchain definition.
# Note that it must also export a $(TARGET)_DEPS value.
#
include $(TOOLCHAIN_DIR)/obj.mk

#
# Add a rule to build all objects into the object directory based on
# their relative path.
#
$($(TARGET)_SUBDIR)/%.o: $(OBJECT_DIR)/$($(TARGET)_SUBDIR)/%.o


#
# Rule to make TARGET objects by name
#
$(TARGET)_OBJS $(TARGET): $($(TARGET)_OBJS)


-include $($(TARGET)_DEPS)

CLEAN_TARGETS := $(CLEAN_TARGETS) $($(TARGET)_OBJS) $($(TARGET)_DEPS)

#
# Information Targets for these objects:
#
$(TARGET)_VARS: TARGET := $(TARGET)
$(TARGET)_VARS: DIRECTORY := $($(TARGET)_SUBDIR)
$(TARGET)_VARS:
	@echo "DIRECTORY"
	@echo $(DIRECTORY)
	@echo ""
	@echo $(TARGET)_SRCS:
	@echo $($(TARGET)_SRCS)
	@echo ""
	@echo $(TARGET)_LSRCS:
	@echo $($(TARGET)_LSRCS)
	@echo ""
	@echo $(TARGET)_LOBJS
	@echo $($(TARGET)_LOBJS)
	@echo ""
	@echo $(TARGET)_OBJS
	@echo $($(TARGET)_OBJS)
	@echo ""
	@echo $(TARGET)_DEPS
	@echo $($(TARGET)_DEPS)

