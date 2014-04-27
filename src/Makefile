TARGETS	= ../include/Init.h ../include/Session.h Init
PREFIX	= /usr/local
DESTDIR	=
BINDIR	= $(PREFIX)/bin
SBINDIR	= $(PREFIX)/sbin
CC	= cc
CPPFLAGSF=
CPPFLAGS=
CFLAGSF	= -W `pkg-config --cflags libApp`
CFLAGS	= -Wall -g -O2 -pedantic
LDFLAGSF= `pkg-config --libs libApp` -Wl,--export-dynamic
LDFLAGS	= 
RM	= rm -f
LN	= ln -f
MKDIR	= mkdir -m 0755 -p
INSTALL	= install


all: $(TARGETS)

../include/Init.h: ../data/Init.interface
	../data/appbroker.sh -P "$(PREFIX)" -- "../include/Init.h"

../include/Session.h: ../data/Session.interface
	../data/appbroker.sh -P "$(PREFIX)" -- "../include/Session.h"

Init_OBJS = init.o main.o service.o session.o
Init_CFLAGS = $(CPPFLAGSF) $(CPPFLAGS) $(CFLAGSF) $(CFLAGS)
Init_LDFLAGS = $(LDFLAGSF) $(LDFLAGS)

Init: $(Init_OBJS)
	$(CC) -o Init $(Init_OBJS) $(Init_LDFLAGS)

init.o: init.c session.h init.h ../include/Init.h ../config.h
	$(CC) -DPREFIX=\"$(PREFIX)\" $(Init_CFLAGS) -c init.c

main.o: main.c init.h session.h ../config.h
	$(CC) $(Init_CFLAGS) -c main.c

service.o: service.c common.h service.h
	$(CC) $(Init_CFLAGS) -c service.c

session.o: session.c
	$(CC) $(Init_CFLAGS) -c session.c

clean:
	$(RM) -- $(../include/Init.h_OBJS) $(../include/Session.h_OBJS) $(Init_OBJS)

distclean: clean
	$(RM) -- $(TARGETS)

install: $(TARGETS)
	$(MKDIR) $(DESTDIR)$(BINDIR)
	$(INSTALL) -m 0755 Init $(DESTDIR)$(BINDIR)/Init

uninstall:
	$(RM) -- $(DESTDIR)$(BINDIR)/Init

.PHONY: all clean distclean install uninstall
