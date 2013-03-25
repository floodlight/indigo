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
# utest.mk
#
# Standard definitions for a Module's utest directory.
#
# This makefile will define a library for the local unit test sources,
# and a binary to build and run the unit tests.
#
#
# Set $(UMODULE) to the module name before calling.
# Set $(UMODULE_SUBDIR) to the subdir before calling
#
# If you unit test is more complicated than this, you will need a different
# make template.
#
###############################################################################
ifndef UMODULE
$(error Please specify $$UMODULE. By convention this should equal the module name for which this is the unit test)
endif

ifndef UMODULE_SUBDIR
$(error Please assign the local directory to $$UMODULE_SUBDIR before including utest.mk)
endif

# Quick Fix
ifdef INCLUDE_$(UMODULE)_UTEST

#
# Define a library for the local files
#
LIBRARY := $(UMODULE)Utest
$(LIBRARY)_SUBDIR := $(UMODULE_SUBDIR)
$(LIBRARY)_INCLUDES := $($(UMODULE)_INCLUDES) $($(UMODULE)_INTERNAL_INCLUDES)
include $(BUILDER)/lib.mk

#
# Define a binary for the utest
#
BINARY := utest_$(UMODULE)
# Link against all existing libraries in the module
$(BINARY)_LIBRARIES := $(LIBRARY_TARGETS) $(LIBRARY_TARGETS)
ifndef BUILDER_EXCLUDE_SETCAP
$(BINARY)_POST_BUILD = sudo setcap cap_net_raw=eip "$(BINARY_DIR)/$(BINARY)" || true
endif
include $(BUILDER)/bin.mk

#
# Make it easy for someone to reference this binary by name:
#
$(UMODULE)UtestBinary := $(BINARY)

endif # INCLUDE_$(UMODULE)_UTEST

