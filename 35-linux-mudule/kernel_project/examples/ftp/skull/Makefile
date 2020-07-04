# Change it here or specify it on the "make" commandline
INCLUDEDIR = /usr/include

CFLAGS = -D__KERNEL__ -DMODULE -O -Wall -I$(INCLUDEDIR)

# Extract version number from headers.
VER = $(shell awk -F\" '/REL/ {print $$2}' $(INCLUDEDIR)/linux/version.h)

OBJS = skull.o

all: $(OBJS)

skull.o: skull_init.o skull_clean.o
	$(LD) -r $^ -o $@

install:
	install -d /lib/modules/$(VER)/misc /lib/modules/misc
	install -c skull.o /lib/modules/$(VER)/misc
	install -c skull.o /lib/modules/misc

clean:
	rm -f *.o *~ core
