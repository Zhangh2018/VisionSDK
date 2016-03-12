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
#    2015-02-24
#
#  LANGUAGE
#    make
#
##############################################################################

GDT = $(SDK_ROOT)/tools/gdt/build-deskwin32/gdt.exe

KMEM = kmem

# Some tools used in this build script
OC = objcopy
NM = nm
SRSECS =    .text .data .rodata

%.c: ../src/%.gdt
	@echo "-------------------------------------"
	@echo "Creating $@" 
	$(GDT) $(GDT_OPTS) $< -o  $@
	@echo "-------------------------------------"
	
##############################################################################
# include file with symbols
$(KMEM)_sym.h: %_sym.h: %.elf
	@echo "generating: $@"
	@$(NM) -n $< | gawk -v name=$* > $@ \
	'BEGIN{gsub("/","_",name);\
	printf("#ifndef %s_SYM_H\n#define %s_SYM_H\n",name,name);}\
	{ if($$2=="T" || $$2=="D") \
	{gsub("[.]","_",$$3); printf("#define %s 0x%s\n",$$3,$$1);}}\
	END{printf("#endif\n");}'

# srecord file
$(KMEM).srec: $(KMEM).elf
	@echo "generating: $@"
	$(NBQ)$(OC) -O srec \
	  $(addprefix -j ,$(SRSECS)) $< $@
	  
# memory dump of srecord file
$(KMEM).c: $(KMEM).srec
	@echo "generating: $@"
	@echo "$<"
	@echo "/* KMEM Kernel Firmware Srecord */" > $@
	@echo "">> $@
	@echo "char kmem_srec[] = {\\" >> $@
	@echo "\"\\">> $@
	@gawk '{ gsub("\r", ""); print $$0"\\"}' $< >> $@
	@echo "\"\\">> $@
	@echo "};" >> $@

$(KMEM).elf: $(IPUS_APP) $(IPUV_APP)
	@echo "-------------------------------------"
	@echo "Creating $@" 
	ld -T $(SDK_ROOT)/build/nbuild/isp_tools/M0_data.ld --accept-unknown-input-arch \
	$(IPUS_APP) $(IPUV_APP) -o $@
	
	
all:: 	$(KMEM).elf $(KMEM).srec $(KMEM).c $(KMEM)_sym.h

clean::
	rm -f  $(ARM_LIB_SRCS) $(KMEM).elf $(KMEM).srec $(KMEM).c $(KMEM)_sym.h
	

