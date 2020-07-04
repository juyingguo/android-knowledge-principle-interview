CFLAGS = -O
SUBDIRS =  misc-progs misc-modules \
           skull scull scullp scullv sbull spull snull\
	   short stepper pci
FTPDIR = ../ftp
all: subdirs

subdirs:
	for n in $(SUBDIRS); do $(MAKE) -C $$n || exit 1; done

clean:
	rm -f *.o *~
	for n in $(SUBDIRS); do $(MAKE) -C $$n clean; done

checkthem:
	for n in $(SUBDIRS); do $(MAKE) -C $$n checkthem; done

check:
	for n in $(SUBDIRS); do $(MAKE) -C $$n check; done

objs:
	for n in $(SUBDIRS); do $(MAKE) -C $$n objs; done

ftp: clean
	-@mkdir $(FTPDIR)
	shar -V -x * | ../tools/sharfilter | (cd $(FTPDIR) && sh -)

#	cd $(FTPDIR); for n in `find . -name '_*' -print`; do \
#	   echo "replacing $$n"; mv $$n `echo $$n | sed s/_//`; done
