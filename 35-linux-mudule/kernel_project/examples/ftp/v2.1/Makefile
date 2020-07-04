CFLAGS = -O
SUBDIRS =  misc-progs misc-modules \
           scull sbull snull short pci
FTPDIR = ../ftp
all: subdirs

subdirs:
	for n in $(SUBDIRS); do $(MAKE) -C $$n || exit 1; done

clean:
	rm -f *.o *~
	for n in $(SUBDIRS); do $(MAKE) -C $$n clean; done

## These are for internal use, and won't work with the released sources.

checkthem:
	for n in $(SUBDIRS); do $(MAKE) -C $$n checkthem; done

check:
	for n in $(SUBDIRS); do $(MAKE) -C $$n check; done

objs:
	for n in $(SUBDIRS); do $(MAKE) -C $$n objs; done

testneed:
	for n in $(SUBDIRS); do $(MAKE) -C $$n testneed; done

ftp: clean
	-@mkdir $(FTPDIR)
	shar -V -x * | ../tools/sharfilter | (cd $(FTPDIR) && sh -)
