
# This Makefile has been simplified as much as possible, by putting all
# generic material, independent of this specific directory, into
# ../Rules.make. Read that file for details

TOPDIR  := $(shell cd ..; pwd)
include $(TOPDIR)/Rules.make

CFLAGS += -O2 -I..

# To please automatic compilation, no TARGET is there, only OBJS
OBJS = pcidata.o pciregions.o
SRC = $(OBJS:.o=.c)
EXE = pcidump

all: .depend $(EXE) $(OBJS)

clean:
	rm -f *.o *~ $(EXE) .depend

depend .depend dep:
	$(CC) $(CFLAGS) -M *.c > $@


ifeq (.depend,$(wildcard .depend))
include .depend
endif


