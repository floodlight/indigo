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
# targets.mk
#
###############################################################################
ifndef __TARGETS_MK__
__TARGETS_MK__=1

include $(BUILDER)/builder.mk

show_toolchains:
	@echo Available Toolchains:
	@echo "    " $(ALL_TOOLCHAINS)
	@echo ""

show_targets:
	@echo Available Targets:
	@echo "    " $(ALL_TARGETS)
	@echo ""

show_libs:
	@echo Available Libraries:
	@echo "    " $(LIBRARY_TARGETS)
	@echo ""

show_bins:
	@echo Available Binaries:
	@echo "    " $(BINARY_TARGETS)
	@echo ""

show_shared:
	@echo Available Shared Libraries:
	@echo "    " $(SHAREDLIB_TARGETS)
	@echo ""

show_scripts:
	@echo Available Scripts:
	@echo "    " $(SCRIPT_TARGETS)
	@echo ""

SHOW_TARGETS := show_targets show_libs show_bins show_shared show_scripts show_toolchains
ifdef __DIRS_MK__
SHOW_TARGETS += show_dirs
endif

show: $(SHOW_TARGETS)

.PHONY: libraries

libraries: $(LIBRARY_TARGETS)
binaries: $(BINARY_TARGETS)
sharedlibs: $(SHAREDLIB_TARGETS)
scripts: $(SCRIPT_TARGETS)

libs: libraries
bins: binaries

clean:
	@echo Cleaning Files
	@rm -rf $(CLEAN_TARGETS)
	@echo Cleaning Directories
	@rm -rf $(CLEAN_DIRECTORIES)

superclean:
	@echo Removing BUILD directory
	@rm -rf $(SUPERCLEAN_BUILD_DIR)

alltargets: libraries binaries sharedlibs scripts

#
# This special target will build the given target against all toolchains
#
alltoolchains:
	@$(foreach tc,$(ALL_TOOLCHAINS),$(MAKE) -C . $(MAKETARGET) TOOLCHAIN=$(tc);  )

alltc: alltoolchains

dox:
	doxygen $(MODULE).doxy > /dev/null
doxv:
	doxygen $(MODULE).doxy

endif # __TARGETS_MK__
