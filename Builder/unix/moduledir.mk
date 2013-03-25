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
# Common Module Repository Targets.
#
###############################################################################

#
# You can add to this target in our module repo makefile
# to display more information.
#
moduledir_show_targets::
	@echo ""
	@echo "Available targets:"
	@echo "    manifest                    Make Manifest.mk"
	@echo "    shmanifest                  Make Manifest.sh"
	@echo "    doxmanifest                 Make Manifest.doxy"
	@echo "    allmanifest                 Make all manifest files."
	@echo "    dox                         Run doxygen"
	@echo "    doxv                        Run doxygen (with log)"
	@echo "    regen-modulemakes           Regenerate all MODULE.mk files."
	@echo "    clean-modulemakes           Delete all MODULE.mk files."
	@echo "    allmodules TARGET=<target>  Build TARGET in all module directories."
	@echo "                                Requires existing Manifest.mk"


#
# Build the Manifest.mk for a module repository.
#
manifest:
	$(BUILDER)/tools/manifesttool.py make

#
# Build the Manifest.sh environment variable file.
#
shmanifest:
	$(BUILDER)/tools/manifesttool.py env

#
# Build the doxygen input manifest
#
doxmanifest:
	$(BUILDER)/tools/manifesttool.py dox

allmanifest:
	$(BUILDER)/tools/manifesttool.py all

#
# Generate documentation.
#
dox:
	@doxygen Modules.doxy > /dev/null

doxv:
	@doxygen Modules.doxy

#
# This defines a rule to build an arbitrary target in a module's basedir
#
define module-dir-make
$(1)-dir-make:
	$(MAKE) -C $($(1)_BASEDIR) $(TARGET)
endef

# This instantiates the rule for every known module
$(foreach mod, $(ALL_MODULES),$(eval $(call module-dir-make,$(mod))))

# This will build the target in every module
allmodules: $(foreach mod,$(ALL_MODULES),$(mod)-dir-make)

# This will regenerate all $(MODULE).mk files
regen-modulemakes:
	$(MAKE) allmodules MODULE_MK_ALWAYS_UPDATE=1

# This will destroy all $(MODULE).mk files
clean-modulemakes:
	rm -f $(foreach mod,$(ALL_MODULES),$($(mod)_BASEDIR)/$(mod).mk)






