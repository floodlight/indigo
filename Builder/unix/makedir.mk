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
# Support makefile for creating directories
#
###############################################################################
#
# The client makefile shoudl set MAKE_DIR=<directory to create>
# then include this makefile
#

ifdef MAKE_DIR
$(MAKE_DIR)_CREATE := $(shell test -d $(MAKE_DIR) || mkdir -p $(MAKE_DIR))
CLEAN_DIRECTORIES := $(CLEAN_DIRECTORIES) $(abspath $(MAKE_DIR))
endif
