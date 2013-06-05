#!/usr/bin/python
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
# Builder Module Generation.
#
###############################################################################
import sys
import os
import re
import errno
import subprocess
import pprint

class ModuleFile(object):
    """Base Class for all generated files in a give module."""

    def __init__(self, config):

        #
        # The following keys are required in the config dict
        #
        # moduleName - The name of the module we're generating.
        # moduleDesc - The description of the new module.
        # modulesBaseDir - The base directory for the module repo.
        #
        # The following keys are optional in the config dict:
        #

        # moduleRelative Path - Path relative to the moduleBaseDir.
        self.moduleRelativePath = None

        # overwrite -- overwrite existing files
        self.overwrite = False


        self.__dict__.update(config)

        #
        # These keys are made available for generation classes
        # to be used in their format strings
        #
        self.MODULE_NAME = self.moduleName
        self.MODULE_DESC = self.moduleDesc
        self.MODULES_BASE_DIR = self.modulesBaseDir

        self.MODULE_BASE_DIR = self.MODULES_BASE_DIR
        if self.moduleRelativePath:
            self.MODULE_BASE_DIR += "/" + self.moduleRelativePath
            self.MODULE_RELATIVE_PATH = "%s" % (self.moduleRelativePath)
        else:
            self.MODULE_RELATIVE_PATH = "./"

        self.MODULE_BASE_DIR += "/" + self.MODULE_NAME


        self.MODULE_NAME_UPPER=self.MODULE_NAME.upper()
        self.MODULE_NAME_LOWER=self.MODULE_NAME.lower()
        self.MODULE_SRC_DIR="%s/module/src" % self.MODULE_BASE_DIR
        self.MODULE_INC_DIR="%s/module/inc/%s" % (self.MODULE_BASE_DIR, self.MODULE_NAME)
        self.MODULE_SRC_FBASE="%s/module/src/%s" % (self.MODULE_BASE_DIR, self.MODULE_NAME_LOWER)
        self.MODULE_INC_FBASE="%s/module/inc/%s/%s" % (self.MODULE_BASE_DIR, self.MODULE_NAME, self.MODULE_NAME_LOWER)

        # Default keys and values
        self.BRIEF=""
        self.header = ""
        self.footer = ""


        # Base class initializations
        self.binit()
        # File initializations
        self.finit()
        # Final initializations
        self.finalize()


    def binit(self):
        """Derived base class init."""
        pass

    def finit(self):
        """File class init."""
        pass

    def finalize(self):
        """Final initialization."""
        pass

    def write(self):

        #
        # Finalize the values of all variables.
        # There may be multiple dependencies, so we
        # Try a few times to resolve them.
        # Anything truly circular or missing will eventually fail.
        #
        for i in range(1, 10):
            for (k, v) in self.__dict__.iteritems():
                if type(v) is str:
                    try:
                        self.__dict__[k] = v % self.__dict__
                    except Exception as e:
                        if i == 9:
                            print "\nclass=%s\nk=%s, v=%s\n" % (self.__class__, k,v)
                            raise


        try:
            os.makedirs(os.path.dirname(self.fname))
        except OSError as e:
            if e.errno != errno.EEXIST:
                raise

        if os.path.exists(self.fname):
            if self.overwrite is False:
                # Don't overwrite an existing file
                print "Skipping existing file %s..." % self.fname
                return

        print "Writing %s..." % self.fname
        f = open(self.fname, "w");
        f.write(self.header)
        f.write(self.body)
        f.write(self.footer)
        f.close()


class ModuleCSourceFile(ModuleFile):
    """Base class for Module C Source files."""
    def binit(self):
        self.header = (
"""/**************************************************************************//**
 *
 *
 *
 *****************************************************************************/
#include <%(MODULE_NAME)s/%(MODULE_NAME_LOWER)s_config.h>
""")

        self.footer = (
"""
"""
)


class ModuleCPublicHeaderFile(ModuleFile):
    """Base class for Module Public C Header files."""
    def binit(self):
        self.header = (
"""/**************************************************************************//**
 *
 * @file
 * @brief %(BRIEF)s
 *
 * @addtogroup %(DOXYGROUP)s
 * @{
 *
 *****************************************************************************/
#ifndef %(IFDEF)s
#define %(IFDEF)s

""" )

        self.footer = (
"""
#endif /* %(IFDEF)s */
/* @} */
""")

    def finalize(self):
        basename = os.path.basename(self.fname % self.__dict__)
        self.IFDEF = "__%s__" % re.sub("[\.]", "_", basename).upper()




class ModuleCPrivateHeaderFile(ModuleFile):
    """Base class for Module Private C Header files."""
    def binit(self):
        self.HEADER_TITLE = ""
        self.HEADER_DESC = ""

        self.header = (
"""/**************************************************************************//**
 *
 * %(BRIEF)s
 *
 *****************************************************************************/
#ifndef %(IFDEF)s
#define %(IFDEF)s
""" )

        self.footer = (
"""
#endif /* %(IFDEF)s */
""")

    def finalize(self):
        basename = os.path.basename(self.fname % self.__dict__)
        self.IFDEF = "__%s__" % re.sub("[\.]", "_", basename).upper()




class ModuleHashFile(ModuleFile):
    """Base class for Module Make and hash-commented files."""
    def binit(self):
        self.BRIEF = ""
        self.header = (
"""###############################################################################
#
# %(BRIEF)s
#
###############################################################################
""")
        self.footer = ""



class ModuleMakefile(ModuleHashFile):
    """Base class for Module makefiles."""
    def binit(self):
        ModuleHashFile.binit(self)
        self.THIS_DIR="$(dir $(lastword $(MAKEFILE_LIST)))"




##############################################################################
#
#
# Generated file classes start here. These all represent generated files,
# and use the above base classes.
#
# All classes named GModule* will be automatically generated.
#
##############################################################################

class GModuleModuleMake(ModuleMakefile):
    def finit(self):
        self.fname = "%(MODULE_BASE_DIR)s/module/make.mk"
        self.body = (
"""THIS_DIR := %(THIS_DIR)s
%(MODULE_NAME)s_INCLUDES := -I $(THIS_DIR)inc
%(MODULE_NAME)s_INTERNAL_INCLUDES := -I $(THIS_DIR)src
%(MODULE_NAME)s_DEPENDMODULE_ENTRIES := init:%(MODULE_NAME_LOWER)s ucli:%(MODULE_NAME_LOWER)s

"""
)

###############################################################################

class GModuleMake(ModuleMakefile):
    def finit(self):
        self.fname = "%(MODULE_BASE_DIR)s/Makefile"
        self.body=(
"""MODULE := %(MODULE_NAME)s
AUTOMODULE := %(MODULE_NAME)s
ifndef BUILDER
$(error "$$BUILDER must be specified.")
endif
include $(BUILDER)/definemodule.mk
""")

###############################################################################
class GModuleSrcMake(ModuleMakefile):
    def finit(self):
        self.fname = "%(MODULE_SRC_DIR)s/make.mk"
        self.body = (
"""
LIBRARY := %(MODULE_NAME)s
$(LIBRARY)_SUBDIR := %(THIS_DIR)s
include $(BUILDER)/lib.mk
""")

###############################################################################

class GModuleUtestMain(ModuleCSourceFile):
    def finit(self):
        self.BRIEF="%(MODULE_NAME)s Unit Test."
        self.fname = "%(MODULE_BASE_DIR)s/utest/main.c"
        self.body=(
"""
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <AIM/aim.h>

int aim_main(int argc, char* argv[])
{
    printf("%(MODULE_NAME)s Utest Is Empty\\n");
    %(MODULE_NAME_LOWER)s_config_show(&aim_pvs_stdout);
    return 0;
}
""")

###############################################################################

class GModuleUtestMake(ModuleMakefile):
    def finit(self):
        self.BRIEF="%(MODULE_NAME)s Unit Test Makefile."
        self.fname = "%(MODULE_BASE_DIR)s/utest/_make.mk"
        self.body = (
"""UMODULE := %(MODULE_NAME)s
UMODULE_SUBDIR := %(THIS_DIR)s
include $(BUILDER)/utest.mk
""")

###############################################################################

class GModuleReadme(ModuleHashFile):
    def finit(self):
        self.BRIEF="%(MODULE_NAME)s README"
        self.fname = "%(MODULE_BASE_DIR)s/README"
        self.body= (
"""
""")

###############################################################################

class GModuleAutoMake(ModuleMakefile):
    def finit(self):
        self.BRIEF="%(MODULE_NAME)s Autogeneration"
        self.fname = "%(MODULE_BASE_DIR)s/module/auto/make.mk"
        self.body=(
"""%(MODULE_NAME)s_AUTO_DEFS := module/auto/%(MODULE_NAME)s.yml
%(MODULE_NAME)s_AUTO_DIRS := module/inc/%(MODULE_NAME)s module/src
include $(BUILDER)/auto.mk

""")

###############################################################################

class GModuleAutoYml(ModuleHashFile):

    #
    # These are the default configuration defines for each
    # new module. They can be added to by clients before
    # generation.
    #
    CDEFS="""- %(MODULE_NAME_UPPER)s_CONFIG_INCLUDE_LOGGING:
    doc: \"Include or exclude logging.\"
    default: 1
- %(MODULE_NAME_UPPER)s_CONFIG_LOG_OPTIONS_DEFAULT:
    doc: "Default enabled log options."
    default: AIM_LOG_OPTIONS_DEFAULT
- %(MODULE_NAME_UPPER)s_CONFIG_LOG_BITS_DEFAULT:
    doc: "Default enabled log bits."
    default: AIM_LOG_BITS_DEFAULT
- %(MODULE_NAME_UPPER)s_CONFIG_LOG_CUSTOM_BITS_DEFAULT:
    doc: "Default enabled custom log bits."
    default: 0
- %(MODULE_NAME_UPPER)s_CONFIG_PORTING_STDLIB:
    doc: \"Default all porting macros to use the C standard libraries.\"
    default: 1
- %(MODULE_NAME_UPPER)s_CONFIG_PORTING_INCLUDE_STDLIB_HEADERS:
    doc: \"Include standard library headers for stdlib porting macros.\"
    default: %(MODULE_NAME_UPPER)s_CONFIG_PORTING_STDLIB
"""

    def finit(self):
        self.CDEF_ENTRIES = self.CDEFS
        self.BRIEF="%(MODULE_NAME)s Autogeneration Definitions."
        self.fname = "%(MODULE_BASE_DIR)s/module/auto/%(MODULE_NAME)s.yml"
        self.body=(
"""
cdefs: &cdefs
%(CDEF_ENTRIES)s

definitions:
  cdefs:
    %(MODULE_NAME_UPPER)s_CONFIG_HEADER:
      defs: *cdefs
      basename: %(MODULE_NAME_LOWER)s_config

  portingmacro:
    %(MODULE_NAME_UPPER)s:
      macros:
        - malloc
        - free
        - memset
        - memcpy
        - strncpy
        - vsnprintf
        - snprintf
        - strlen
""")

###############################################################################

class GModuleConfigHeader(ModuleCPublicHeaderFile):
    def finit(self):
        self.BRIEF="%(MODULE_NAME)s Configuration Header"
        self.DOXYGROUP="%(MODULE_NAME_LOWER)s-config" % self.__dict__
        self.fname = "%(MODULE_INC_FBASE)s_config.h"
        self.body = (
"""#ifdef GLOBAL_INCLUDE_CUSTOM_CONFIG
#include <global_custom_config.h>
#endif
#ifdef %(MODULE_NAME_UPPER)s_INCLUDE_CUSTOM_CONFIG
#include <%(MODULE_NAME_LOWER)s_custom_config.h>
#endif

/* <auto.start.cdefs(%(MODULE_NAME_UPPER)s_CONFIG_HEADER).header> */
/* <auto.end.cdefs(%(MODULE_NAME_UPPER)s_CONFIG_HEADER).header> */

#include \"%(MODULE_NAME_LOWER)s_porting.h\"
""")

###############################################################################

class GModuleConfigSource(ModuleCSourceFile):
    def finit(self):
        self.fname = "%(MODULE_SRC_FBASE)s_config.c"
        self.body = (
"""
/* <auto.start.cdefs(%(MODULE_NAME_UPPER)s_CONFIG_HEADER).source> */
/* <auto.end.cdefs(%(MODULE_NAME_UPPER)s_CONFIG_HEADER).source> */
"""
)

###############################################################################

class GModuleModuleSource(ModuleCSourceFile):
    def finit(self):
        self.fname= "%(MODULE_SRC_FBASE)s_module.c"
        self.body = (
"""
#include "%(MODULE_NAME_LOWER)s_log.h"

static int
datatypes_init__(void)
{
#define %(MODULE_NAME_UPPER)s_ENUMERATION_ENTRY(_enum_name, _desc) \
    AIM_DATATYPE_MAP_REGISTER(_enum_name, _enum_name##_map, _desc, \
                              AIM_LOG_INTERNAL);
#include <%(MODULE_NAME)s/%(MODULE_NAME_LOWER)s.x>
    return 0;
}

void __%(MODULE_NAME_LOWER)s_module_init__(void)
{
    AIM_LOG_STRUCT_REGISTER();
    datatypes_init__();
}
""")

###############################################################################

class GModuleLogHeader(ModuleCPrivateHeaderFile):
    def finit(self):
        self.fname = "%(MODULE_SRC_FBASE)s_log.h"
        self.body = (
"""
#define AIM_LOG_MODULE_NAME %(MODULE_NAME_LOWER)s
#include <AIM/aim_log.h>
""")

###############################################################################

class GModuleLogSource(ModuleCSourceFile):
    def finit(self):
        self.fname = "%(MODULE_SRC_FBASE)s_log.c"
        self.body = (
"""
#include "%(MODULE_NAME_LOWER)s_log.h"
/*
 * %(MODULE_NAME)s log struct.
 */
AIM_LOG_STRUCT_DEFINE(
                      %(MODULE_NAME_UPPER)s_CONFIG_LOG_OPTIONS_DEFAULT,
                      %(MODULE_NAME_UPPER)s_CONFIG_LOG_BITS_DEFAULT,
                      NULL, /* Custom log map */
                      %(MODULE_NAME_UPPER)s_CONFIG_LOG_CUSTOM_BITS_DEFAULT
                     );
""")

###############################################################################

class GModuleEnumSource(ModuleCSourceFile):
    def finit(self):
        self.fname = "%(MODULE_SRC_FBASE)s_enums.c"
        self.body = (
"""
/* <--auto.start.enum(ALL).source> */
/* <auto.end.enum(ALL).source> */
""")


###############################################################################

class GModuleXHeader(ModuleCSourceFile):
    def finit(self):
        self.fname = "%(MODULE_INC_FBASE)s.x"
        self.BRIEF="%(MODULE_NAME)s X Macros."
        self.body=(
"""
/* <--auto.start.xmacro(ALL).define> */
/* <auto.end.xmacro(ALL).define> */

/* <--auto.start.xenum(ALL).define> */
/* <auto.end.xenum(ALL).define> */

""")

###############################################################################

class GModuleInternalHeader(ModuleCPrivateHeaderFile):
    def finit(self):
        self.fname = "%(MODULE_SRC_FBASE)s_int.h"
        self.BRIEF="%(MODULE_NAME)s Internal Header"
        self.body=(
"""
#include <%(MODULE_NAME)s/%(MODULE_NAME_LOWER)s_config.h>

""")

###############################################################################

class GModulePortingHeader(ModuleCPublicHeaderFile):
    def finit(self):
        self.fname = "%(MODULE_INC_FBASE)s_porting.h"
        self.BRIEF="%(MODULE_NAME)s Porting Macros."
        self.DOXYGROUP="%(MODULE_NAME_LOWER)s-porting" % self.__dict__
        self.body=(
"""
/* <auto.start.portingmacro(ALL).define> */
/* <auto.end.portingmacro(ALL).define> */

""")

###############################################################################

class GModuleDoxyHeader(ModuleCPrivateHeaderFile):
    def finit(self):
        self.fname = "%(MODULE_INC_FBASE)s_dox.h"
        self.BRIEF="%(MODULE_NAME)s Doxygen Header"
        self.body=(
"""
/**
 * @defgroup %(MODULE_NAME)s %(MODULE_NAME)s - %(MODULE_NAME)s Description
 *

The documentation overview for this module should go here.

 *
 * @{
 *
 * @defgroup %(MODULE_NAME_LOWER)s-%(MODULE_NAME_LOWER)s Public Interface
 * @defgroup %(MODULE_NAME_LOWER)s-config Compile Time Configuration
 * @defgroup %(MODULE_NAME_LOWER)s-porting Porting Macros
 *
 * @}
 *
 */
""")

###############################################################################

class GModuleDoxyFile(ModuleFile):
    def finit(self):
        self.fname = "%(MODULE_BASE_DIR)s/%(MODULE_NAME)s.doxy" % self.__dict__
        body = subprocess.check_output(["/usr/bin/doxygen", "-g", "-"])
        body = body.replace("%", " percent");
        body = body.replace("PROJECT_NAME           = \"My Project\"",
                          "PROJECT_NAME           = \"%(MODULE_NAME)s\"")
        body = body.replace("PROJECT_BRIEF          =",
                          "PROJECT_BRIEF          = \"%(MODULE_DESC)s\"")
        body = body.replace("OUTPUT_DIRECTORY       =",
                          "OUTPUT_DIRECTORY       = doc")
        body = body.replace("OPTIMIZE_OUTPUT_FOR_C  = NO",
                          "OPTIMIZE_OUTPUT_FOR_C  = YES")
        body = body.replace("RECURSIVE              = NO",
                          "RECURSIVE              = YES")
        body = body.replace("INPUT                  =",
                            "INPUT                  = module/inc")
        self.body = body


###############################################################################


###############################################################################
#
# This class is optional and not generated by default.
# It produces the Makefile necessary to build the module's
# unit test.
#
# This can be instantiated with the correct paths for your
# module repository in your repositories integration script.
#
class ModuleUnitTestTargetMake(ModuleMakefile):

    def finit(self):
        self.fname = "%(MODULE_UNIT_TEST_DIR)s/Makefile"
        self.body=(
"""
ifndef BUILDER
$(error $$(BUILDER) is not defined.)
endif

MODULE := %(MODULE_NAME)s_utest
TEST_MODULE := %(MODULE_NAME)s
DEPENDMODULES := AIM
MODULE_DIRS := %(MODULE_DIRS)s
GLOBAL_CFLAGS += -DAIM_CONFIG_INCLUDE_MODULES_INIT=1
GLOBAL_CFLAGS += -DAIM_CONFIG_INCLUDE_MAIN=1
include $(BUILDER)/build-unit-test.mk
""")

###############################################################################
#
# End File Classes
#
###############################################################################



###############################################################################
#
# Generator Class
#
# This class collects all file object classes and
# generates them for a given module.
#
###############################################################################
class ModuleGenerator(object):
    def __init__(self, opts, globals_=None):
        self.classes = []
        self.opts = opts
        if globals_ is None:
            globals_ = globals().copy()
        for name, obj in globals_.iteritems():
            if name.startswith("GModule"):
                self.classes.append(globals_[name])

    def write(self):
        for csl in self.classes:
            x = csl(self.opts)
            # ugly hackery, fixme
            self.MODULE_BASE_DIR=x.MODULE_BASE_DIR
            x.write()

    #
    # This can be set on a per-client repository basis.
    # If not set, then it will be requested as an argument.
    #
    modulesBaseDir = None

    @staticmethod
    def main(globals_=None):
        import argparse
        ap=argparse.ArgumentParser(description="Create a new Module.")

        ap.add_argument('moduleName', help='New module name')
        ap.add_argument('moduleDesc', help='Module description')


        if ModuleGenerator.modulesBaseDir is None:
            ap.add_argument('modulesBaseDir',  help='Module base directory.')
        else:
            ap.add_argument('--modulesBaseDir', help='Module base directory.',
                            default=ModuleGenerator.modulesBaseDir)

        ap.add_argument('--moduleRelativePath', help='Path for new module, relative to module base.',
                        default=None)

        ap.add_argument('--overwrite', help='Overwrite target files.', action='store_true')

        opts = ap.parse_args()

        # The command-line argument names are equal to the required key
        # names assumed by the ModuleGenerator class, so we pass the
        # option dict directly:
        mg = ModuleGenerator(vars(opts), globals_)
        mg.write()

        # Run the first autogen on the new module
        os.system("make -C %s autogen" % mg.MODULE_BASE_DIR)


###############################################################################

if __name__ == "__main__":
    ModuleGenerator.main()




