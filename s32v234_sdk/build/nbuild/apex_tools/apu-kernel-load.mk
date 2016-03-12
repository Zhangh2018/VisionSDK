##############################################################################
#
#  Freescale Semiconductor, Inc.
#  (c) Copyright 2011, Freescale Semiconductor, Inc.
#  ALL RIGHTS RESERVED.
#
##############################################################################
#
#  CONTENT
#
#
#  AUTHOR
#    Stefan Schwarz
#
#  DATE
#    2013-08-05
#
#  LANGUAGE
#    make
#
##############################################################################

APU_LOAD_HEADERS =	$(addsuffix _APU_LOAD.h,$(APU_APP))

%_APU_LOAD.h : %.elf
	read_elf -pPMh=32 -mDMb=8 -mVMb=256 $< -eGb -t $(tcl_script) -Tload_name=$(subst .elf,,$<) > $@

all:: $(APU_LOAD_HEADERS)


	