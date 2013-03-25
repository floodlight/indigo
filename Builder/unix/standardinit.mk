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
# standardinit.mk
#
# Define a standard/generic module init.
#
ifndef __STANDARDINIT_MK__
__STANDARDINIT_MK__=1

ifndef BUILDER
$(error $$BUILDER must be defined)
endif

#
# Include generic builder tools
#
include $(BUILDER)/builder.mk

MODULE_MAKE := $(shell test -f $(MODULE).mk || $(BUILDER)/tools/modulemakes.py --name $(MODULE))

include $(BUILDER)/init.mk

endif # __STANDARDINIT_MK__
