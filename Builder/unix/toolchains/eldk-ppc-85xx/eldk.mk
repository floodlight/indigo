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
# Common settings for the ELDK.
#
###############################################################################
ifndef __ELDK_MK__
__ELDK_MK__ := 1

#
# Default location for the entire toolchain
#
ifndef ELDK_ROOT
ELDK_ROOT := /opt/tools/ELDK_4.2
endif

GCC := ppc_85xx-gcc

export CROSS_COMPILE=ppc_85xx-
export PATH := $(ELDK_ROOT)/usr/bin:$(ELDK)/bin:$(PATH)
export ARCH := ppc

GCC_TOOLCHAIN_CHECK := $(wildcard $(ELDK_ROOT)/usr/bin/$(GCC))

ifneq ($(GCC_TOOLCHAIN_CHECK),$(ELDK_ROOT)/usr/bin/$(GCC))
$(error "ELDK Toolchain misconfigured: The ppc_85xx-gcc binary was not found. Search path is currently $(ELDK_ROOT).")
endif


endif
