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
#  /module/make.mk
#
#  locitest public includes are defined here
#
###############################################################################
LOCITEST := $(SUBMODULE_LOXIGEN_ARTIFACTS)/locitest
LOCI := $(SUBMODULE_LOXIGEN_ARTIFACTS)/loci

locitest_INCLUDES := -I $(LOCITEST)/inc -I $(LOCI)/src
locitest_INTERNAL_INCLUDES := -I $(LOCITEST)/src

LIBRARY := locitest
locitest_SUBDIR := $(LOCITEST)/src
include $(BUILDER)/lib.mk
