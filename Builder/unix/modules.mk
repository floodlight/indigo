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
# Generate the modules.inc file for the current directory.
#
# The modules.inc file includes all subdirectory makefiles for
# top-level inclusion.
#
###############################################################################


ifndef TARGET_FILE
#
# The default filename is 'modules.inc'.
#
# The building application can request a different filename when asking a module
# to produce it's modules.inc for external inclusion and building
#

ifdef MODULE
TARGET_FILE=$(MODULE).mk
else
TARGET_FILE=modules.inc
endif

endif


ifndef TARGET_DIR
#
# The default location for the modules.inc file is the current directory.
# Customizeable by the builder of the module.
#
TARGET_DIR=$(CURDIR)
endif

ifndef MODULE_DIR
#
# The default module directory is the current directory
#
MODULE_DIR=$(CURDIR)
endif


