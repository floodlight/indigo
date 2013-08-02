###############################################################################
#
#  /module/make.mk
#
#  hindex public includes are defined here
#
###############################################################################
THISDIR := $(dir $(lastword $(MAKEFILE_LIST)))
hindex_INCLUDES := -I $(THISDIR)inc
hindex_INTERNAL_INCLUDES := -I $(THISDIR)src

