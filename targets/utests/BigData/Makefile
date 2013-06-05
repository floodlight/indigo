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
# Make all
#
###############################################################################
DIRECTORIES := $(notdir $(wildcard $(CURDIR)/*))
FILTER := make Makefile
DIRECTORIES := $(filter-out $(FILTER),$(DIRECTORIES))

.PHONY: all

all:
	echo $(DIRECTORIES)
	$(foreach d,$(DIRECTORIES),$(MAKE) -C $(d) $(MAKETARGET) || exit 1;)

clean:
	echo $(DIRECTORIES)
	$(foreach d,$(DIRECTORIES),$(MAKE) -C $(d) clean;)

superclean:
	echo $(DIRECTORIES)
	$(foreach d,$(DIRECTORIES),$(MAKE) -C $(d) superclean;)
