# stepper/makefile
# Comment/uncomment the following line to enable/disable debugging
#DEBUG = y

# Change it here or specify it on the "make" commandline
INCLUDEDIR = /usr/include 

ifeq ($(DEBUG),y)
  DEBFLAGS = -O -g -DSTEP_DEBUG # "-O" is needed to expand inlines
else
  DEBFLAGS = -O2
endif

CFLAGS = -D__KERNEL__ -DMODULE -Wall $(DEBFLAGS)
CFLAGS += -I$(INCLUDEDIR)

# Extract version number from headers.
VER = $(shell awk -F\" '/REL/ {print $$2}' $(INCLUDE)/linux/version.h)

TARGET = stepper

OBJS = $(TARGET).o

all: $(OBJS)

clean:
	rm -f *.o *~ core
