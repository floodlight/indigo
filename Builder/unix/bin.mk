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
# bin.mk
#
# Rule definitions for building library targets.
################################################################################


BTARGET := $(BINARY)

$(BINARY_DIR)/$(BINARY): BINARY := $(BINARY)

include $(TOOLCHAIN_DIR)/bin.mk

$(BINARY): $(BINARY_DIR)/$(BINARY)

$($(BTARGET)_SUBDIR)/$(BINARY): $(BINARY_DIR)/$(BINARY)

BINARY_TARGETS := $(BINARY_TARGETS) $(BINARY)

$(BINARY)_VARS: BINARY := $(BINARY)

$(BINARY)_VARS:
	@echo ""
	@echo TARGET BINARY:
	@echo $(BINARY_DIR)/$(BINARY)


CLEAN_TARGETS := $(CLEAN_TARGETS) $(BINARY_DIR)/$(BINARY)
