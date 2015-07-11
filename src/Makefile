TARGETS	= $(OBJDIR)../include/Init.h $(OBJDIR)../include/Session.h $(OBJDIR)Init
OBJDIR	=
PREFIX	= /usr/local
DESTDIR	=
BINDIR	= $(PREFIX)/bin
SBINDIR	= $(PREFIX)/sbin
CC	= cc
CPPFLAGSF=
CPPFLAGS=
CFLAGSF	= -W `pkg-config --cflags libApp`
CFLAGS	= -Wall -g -O2 -pedantic -fPIC -fstack-protector
LDFLAGSF= `pkg-config --libs libApp` -Wl,--export-dynamic
LDFLAGS	= -Wl,-pie
RM	= rm -f
LN	= ln -f
MKDIR	= mkdir -m 0755 -p
INSTALL	= install


all: $(TARGETS)

$(OBJDIR)../include/Init.h: ../data/Init.interface
	../data/appbroker.sh -P "$(PREFIX)" -- "$(OBJDIR)../include/Init.h"

$(OBJDIR)../include/Session.h: ../data/Session.interface
	../data/appbroker.sh -P "$(PREFIX)" -- "$(OBJDIR)../include/Session.h"

Init_OBJS = $(OBJDIR)init.o $(OBJDIR)main.o $(OBJDIR)service.o $(OBJDIR)session.o
Init_CFLAGS = $(CPPFLAGSF) $(CPPFLAGS) $(CFLAGSF) $(CFLAGS)
Init_LDFLAGS = $(LDFLAGSF) $(LDFLAGS)

$(OBJDIR)Init: $(Init_OBJS)
	$(CC) -o $(OBJDIR)Init $(Init_OBJS) $(Init_LDFLAGS)

$(OBJDIR)init.o: init.c session.h init.h ../include/Init.h ../config.h
	$(CC) -DPREFIX=\"$(PREFIX)\" $(Init_CFLAGS) -o $(OBJDIR)init.o -c init.c

$(OBJDIR)main.o: main.c init.h session.h ../config.h
	$(CC) $(Init_CFLAGS) -o $(OBJDIR)main.o -c main.c

$(OBJDIR)service.o: service.c common.h service.h
	$(CC) $(Init_CFLAGS) -o $(OBJDIR)service.o -c service.c

$(OBJDIR)session.o: session.c
	$(CC) $(Init_CFLAGS) -o $(OBJDIR)session.o -c session.c

clean:
	$(RM) -- $(../include/Init.h_OBJS) $(../include/Session.h_OBJS) $(Init_OBJS)
	../data/appbroker.sh -c -P "$(PREFIX)" -- "../include/Init.h"
	../data/appbroker.sh -c -P "$(PREFIX)" -- "../include/Session.h"

distclean: clean
	$(RM) -- $(TARGETS)

install: $(TARGETS)
	$(MKDIR) $(DESTDIR)$(BINDIR)
	$(INSTALL) -m 0755 $(OBJDIR)Init $(DESTDIR)$(BINDIR)/Init

uninstall:
	$(RM) -- $(DESTDIR)$(BINDIR)/Init

.PHONY: all clean distclean install uninstall
