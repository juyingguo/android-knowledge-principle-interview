# Comment/uncomment the following line to enable/disable debugging
#DEBUG = y

# Change it here or specify it on the "make" commandline
INCLUDEDIR = /usr/include

ifeq ($(DEBUG),y)
  DEBFLAGS = -O -g -DSCULLP_DEBUG # "-O" is needed to expand inlines
else
  DEBFLAGS = -O2
endif

CFLAGS = -D__KERNEL__ -DMODULE -Wall $(DEBFLAGS)
CFLAGS += -I$(INCLUDEDIR)

# Extract version number from headers.
VER = $(shell awk -F\" '/REL/ {print $$2}' $(INCLUDEDIR)/linux/version.h)

TARGET = scullp
OBJS = main.o mmap.o

all: .depend $(TARGET).o

$(TARGET).o: $(OBJS)
	$(LD) -r $^ -o $@

install:
	mkdir -p /lib/modules/$(VER)/misc /lib/modules/misc
	install -c $(TARGET).o /lib/modules/$(VER)/misc
	install -c $(TARGET).o /lib/modules/misc


clean:
	rm -f *.o *~ core .depend

depend .depend dep:
	$(CC) $(CFLAGS) -M *.c > $@


ifeq (.depend,$(wildcard .depend))
include .depend
endif
