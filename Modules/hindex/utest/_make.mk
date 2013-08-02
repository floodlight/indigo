###############################################################################
#
#  /utest/_make.mk
#
#  hindex Unit Testing Definitions
#
###############################################################################
UMODULE := hindex
UMODULE_SUBDIR := $(dir $(lastword $(MAKEFILE_LIST)))
include $(BUILDER)/utest.mk

