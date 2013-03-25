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
#  Generic Unit Testing Module Makefile
#
###############################################################################
#
# Unit tests build with debug enabled.

DEBUG := 1

.DEFAULT_GOAL := tests

include $(BUILDER)/standardinit.mk

# The Module we are building
ifndef TEST_MODULE
$(error $$(TEST_MODULE) is not defined.)
endif

# At the very least we need the test module
DEPENDMODULES += $(TEST_MODULE)
DEPENDMODULES_XHEADER := $(DEPENDMODULES)

# Pull in the utest library for the TEST_MODULE
INCLUDE_$(TEST_MODULE)_UTEST := 1

# Pull in external module dependencies
include $(BUILDER)/dependmodules.mk

include $(BUILDER)/targets.mk

ifdef VALGRIND
HARNESS:=valgrind --leak-check=full --show-reachable=yes --suppressions=$(BIGCODE)/Tools/valgrind.suppressions
endif


# By Convention
ifdef $(TEST_MODULE)UtestBinary
# There is only one unit test - default unit testing
UTEST_BINARY := $(BINARY_DIR)/$($(TEST_MODULE)UtestBinary)
tests: $(UTEST_BINARY) $($(TEST_MODULE)_UNIT_TESTS)
	@echo ""
	@echo "** Starting Unit Test: $(UTEST_BINARY)"
	@$(SUDO) $(HARNESS) $(UTEST_BINARY)
	@echo "** Finished Unit Test: $(UTEST_BINARY)"
	@echo ""

endif

ifdef $(TEST_MODULE)UtestBinaries
# Multiple unit tests -- you have to specify your own targets
tests: $($(TEST_MODULE)UtestBinaries) $($(TEST_MODULE)_UNIT_TESTS)
endif



alltests:
	$(MAKE) alltc MAKETARGET=tests


#
# Convenience: remake autogen in the test module directory
#
autogen:
	$(MAKE) -C $($(TEST_MODULE)_BASEDIR) autogen






