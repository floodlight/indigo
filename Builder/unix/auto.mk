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
# auto.mk
#
# Autogeneration rules
#
###############################################################################
THIS_SUBDIR := $(dir $(lastword $(MAKEFILE_LIST)))

#
# The calling Makefile specifies the following:
#
# $(AUTOMODULE)_AUTO_DEFS : file list
# $(AUTOMODULE)_AUTO_DIRS : directory list
#
# The SourceGenerator tool will be run over all of these files
#
#
ifdef AUTOMODULE

#
# The $(AUTOMODULE) is different from $(MODULE) so the autogen targets can be excluded from
# external builds.
#
# $(AUTOMODULE) should only be set the $(MODULE) in the module's top-level makefile, not
# it's $(MODULE).mk
#

$(AUTOMODULE)_AUTO_FILELIST := $(foreach dir,$($(AUTOMODULE)_AUTO_DIRS),$(wildcard $(dir)/*))

ifndef SOURCEGEN_DIR
SOURCEGEN_DIR=$(THIS_SUBDIR)../../Modules/SourceGen
endif

SOURCEGENTOOL := $(SOURCEGEN_DIR)/sg.py
EVALTOOL := $(SOURCEGEN_DIR)/cobjectgen.py

$(AUTOMODULE)_autogen:
	@$(SOURCEGENTOOL) -d $($(AUTOMODULE)_AUTO_DEFS) -i $($(AUTOMODULE)_AUTO_FILELIST)
	$($(AUTOMODULE)_AUTO_POST)

$(AUTOMODULE)_autoeval:
	@$(EVALTOOL) -i $($(AUTOMODULE)_AUTO_DEFS) -e "$(expr)"

autogen: $(AUTOMODULE)_autogen
autoeval: $(AUTOMODULE)_autoeval

endif

