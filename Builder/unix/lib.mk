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
# lib.mk
#
# Rule definitions for building library targets.
################################################################################

# Include the rules to define and build this library's object files

TARGET := $(LIBRARY)
include $(BUILDER)/obj.mk
################################################################################
#
# Rules for building this library
#
################################################################################

# Assign Target-Specific value of Library for use when the target is executed:
$(LIBRARY_DIR)/$(LIBRARY).a: LIBRARY := $(LIBRARY)

# Include the toolchain build rule for libraries
include $(TOOLCHAIN_DIR)/lib.mk

# Rule to build the target by name:
$(LIBRARY).a: $(LIBRARY_DIR)/$(LIBRARY).a

# Rule to build the target by relative path:
$($(TARGET)_SUBDIR)/$(LIBRARY).a: $(LIBRARY_DIR)/$(LIBRARY).a


# Add this to the global list of library targets:
ifndef $(LIBRARY)_STANDALONE
LIBRARY_TARGETS := $(LIBRARY_TARGETS) $(LIBRARY).a
endif

CLEAN_TARGETS := $(CLEAN_TARGETS) $(LIBRARY_DIR)/$(LIBRARY).a

#
# Information Target for this Library
#
$(LIBRARY).a_VARS: LIBRARY := $(LIBRARY)
$(LIBRARY).a_VARS: $(LIBRARY)_VARS	# Get the object information
	@echo ""
	@echo TARGET LIBRARY:
	@echo $(LIBRARY_DIR)/$(LIBRARY).a


