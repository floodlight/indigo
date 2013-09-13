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
# script.mk
#
# Rule definitions for building script targets.
# A 'script' here is just a file built by concatenating together
# its dependencies.
################################################################################


STARGET := $(SCRIPT)

$(BINARY_DIR)/$(SCRIPT): SCRIPT := $(SCRIPT)

$(SCRIPT): $(BINARY_DIR)/$(SCRIPT)

$($(STARGET)_SUBDIR)/$(SCRIPT): $(BINARY_DIR)/$(SCRIPT)

SCRIPT_TARGETS := $(SCRIPT_TARGETS) $(SCRIPT)

$(SCRIPT)_VARS: SCRIPT := $(SCRIPT)

$(SCRIPT)_VARS:
	@echo ""
	@echo TARGET SCRIPT:
	@echo $(BINARY_DIR)/$(SCRIPT)

# no toolchain-specific rule:
$(BINARY_DIR)/$(SCRIPT): $($(SCRIPT)_PARTS)
	@echo "    Generating Script: $(MODULE)::$(notdir $@)"
	@/bin/cp /dev/null $@
	$(VERBOSE)/bin/cat $($(SCRIPT)_PARTS) >> $@
	@/bin/chmod +x $@
