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
# dependmodules.mk
#
# Include make information for a set of modules.
#
# REQUIRES:
#		$(MODULE_PATH)	- Location of modules
#	        $(DEPENDMODULES) - List of modules to include
#
###############################################################################
ifdef DEPENDMODULES

#
# You can specify a set of module directories and the manifest will be
# generated automatically.
#
# This allows you to combine multiple repositories and module locations.
#
ifdef MODULE_DIRS
MAKE_MODULE_DIRS_MANIFESTS := $(foreach dir,$(MODULE_DIRS),$(shell test -f $(dir)/Manifest.mk || cd $(dir) && $(BUILDER)/tools/manifesttool.py make))
MODULEMANIFEST += $(foreach dir,$(MODULE_DIRS),$(dir)/Manifest.mk)
endif

#
# Either specified manually, or through the MODULE_DIRS settings above
#
ifndef MODULEMANIFEST
$(error $$MODULEMANIFEST must be set)
endif

#
# List of all module manifest files
#
include $(MODULEMANIFEST)

#
# Make sure the $(MODULE).mk file exists for all modules on which we are depending:
#
DEPEND_MODULES_MK := $(foreach mod,$(DEPENDMODULES),$(shell test -f $($(mod)_BASEDIR)/$(mod).mk || $(BUILDER)/tools/modulemakes.py --name $(mod) --root=$($(mod)_BASEDIR)))

# Include all $(MODULE).mk in DEPENDMODULES
include $(foreach mod,$(DEPENDMODULES),$($(mod)_BASEDIR)/$(mod).mk)

#
# Add all $(MODULE)_INCLUDES to $GLOBAL_INCLUDES.
#
# $GLOBAL_INCLUDES is referenced by the toolchain directly
GLOBAL_INCLUDES += $(foreach mod,$(DEPENDMODULES), $($(mod)_INCLUDES))

#
# Provide uppercase versions of DEPENDMODULES for optional config processing
#
DEPENDMODULES_UPPER := $(foreach mod,$(DEPENDMODULES),$(shell echo $(mod) | tr [:lower:] [:upper:]))

#
# Generate all requested DEPENDMODULE types into the dependmodules.x header.
#
# The DEPENDMODULE_BUILD macro always contains all modules that were built:
DEPENDMODULE_ENTRIES += $(foreach mod,$(DEPENDMODULES),build:$(mod))
# Modules can specify the types of entries they export:
DEPENDMODULE_ENTRIES += $(foreach mod,$(DEPENDMODULES),$($(mod)_DEPENDMODULE_ENTRIES))
# Generate
DEPENDMODULE_HEADER := $(shell $(BUILDER)/tools/wod.py dependmodules.x $(BUILDER)/tools/dependmodules.py $(DEPENDMODULE_ENTRIES))

endif # DEPENDMODULES

