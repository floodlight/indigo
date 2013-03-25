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

################################################################################
#
# GCC-Local32 Object File Rules
#
################################################################################
# Just change the compilation flags and call the local gcc toolchain
ifeq (,$(findstring -m32,$(GCC_FLAGS)))
GCC_FLAGS += -m32
endif

include $(BUILDER)/toolchains/gcc-local/obj.mk

