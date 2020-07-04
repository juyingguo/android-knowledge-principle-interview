# Comment/uncomment the following line to enable/disable debugging
#DEBUG = y

# Change it here or specify it on the "make" commandline
INCLUDEDIR = /usr/include

ifeq ($(DEBUG),y)
  DEBFLAGS = -O -g -DJIT_DEBUG -DJIQ_DEBUG -DALL_DEBUG
else
  DEBFLAGS = -O2
endif

CFLAGS = -D__KERNEL__ -DMODULE -Wall $(DEBFLAGS)


CFLAGS += -I$(INCLUDEDIR)

# first the portable ones, then those that need newer kernel versions
# this way everything compilable is built under 1.2 before getting errors
OBJS = faulty.o sleepy.o silly.o slave.o slaveD.o slaveH.o import.o \
	master.o export.o hello.o \
	jit.o jiq.o allocator.o 


all: $(OBJS)

clean:
	rm -f *.o *~

# Don't use -Wall here: the cose is silly by design
hello.o: hello.c
	$(CC) -D__KERNEL__ -c $^ -o $@

# set MODVERSIONS if the kernel uses it
VERSUSED = $(shell grep 'define CONFIG_MODVERSIONS' \
                   $(INCLUDEDIR)/linux/autoconf.h | wc -l | sed 's/ //g')
ifeq ($(VERSUSED),1)
  MODVERSIONS = y
endif

# and then use it
ifdef MODVERSIONS
export.o import.o: export.ver
endif

export.ver: export.c
	$(CC) -I$(INCLUDEDIR) -E -D__GENKSYMS__ $^ | genksyms > $@


