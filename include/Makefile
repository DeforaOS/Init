TARGETS	= Init.h
PREFIX	= /usr/local
DESTDIR	=
RM	?= rm -f
LN	?= ln -f
MKDIR	?= mkdir -p
INSTALL	?= install


all: $(TARGETS)

Init.h: ../data/Init.interface
	../data/appbroker.sh -P "$(PREFIX)" -- "Init.h"

clean:
	$(RM) -- $(Init.h_OBJS)

distclean: clean
	$(RM) -- $(TARGETS)

install: $(TARGETS)

uninstall:

.PHONY: all clean distclean install uninstall
