# Comment/uncomment the following line to enable/disable debugging
#DEBUG = y

# Change it here or specify it on the "make" commandline
INCLUDEDIR = /usr/include

ifeq ($(DEBUG),y)
  DEBFLAGS = -O -g -DSHORT_DEBUG
else
  DEBFLAGS = -O2
endif

CFLAGS = -D__KERNEL__ -DMODULE -Wall $(DEBFLAGS)

CFLAGS += -I$(INCLUDEDIR)

OBJS = short.o

all: $(OBJS)

skull.o: skull_init.o skull_clean.o
	$(LD) -r $^ -o $@

install:
	mkdir -p /lib/modules/$(VER)/misc /lib/modules/misc
	install -c short.o /lib/modules/$(VER)/misc
	install -c short.o /lib/modules/misc

clean:
	rm -f *.o *~ core
