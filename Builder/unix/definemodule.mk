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
# definemodule.mk
#
# Define a code Module.
#
###############################################################################
ifndef __DEFINEMODULE_MK__
__DEFINEMODULE_MK__=1

.DEFAULT_GOAL=show

#
# Include generic builder tools
#
include $(BUILDER)/builder.mk
include $(BUILDER)/modules.mk

#
# Update $(MODULE).mk if necessary
#
ifdef MODULE_MK_ALWAYS_UPDATE
MODULE_MK_UPDATE := $(shell $(BUILDER)/tools/modulemakes.py --name $(MODULE))
else
MODULE_MK_UPDATE := $(shell test -f $(MODULE).mk || $(BUILDER)/tools/modulemakes.py --name $(MODULE))
endif

#
# Include our modulemake definitions
#
-include $(MODULE).mk

#
# Display Module Targets
#
include $(BUILDER)/targets.mk

#
# Module definitions cannot build themselves.
# The only targets that are allows are:t
#
# modulemake
# autogen
# show
#
ALLOWED_GOALS:=modulemake autogen show dox doxv
DENY_GOALS:=$(filter-out $(ALLOWED_GOALS),$(MAKECMDGOALS))
ifneq ($(DENY_GOALS),)
$(error "$(DENY_GOALS)" cannot be built from here)
endif

endif # __DEFINEMODULE_MK__
