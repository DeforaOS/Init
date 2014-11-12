OBJDIR	=
PREFIX	= /usr/local
DESTDIR	=
MKDIR	= mkdir -m 0755 -p
INSTALL	= install
RM	= rm -f


all:

clean:

distclean: clean

install:
	$(MKDIR) $(DESTDIR)$(PREFIX)/etc/AppInterface
	$(INSTALL) -m 0644 Init.interface $(DESTDIR)$(PREFIX)/etc/AppInterface/Init.interface
	$(MKDIR) $(DESTDIR)$(PREFIX)/etc/AppInterface
	$(INSTALL) -m 0644 Session.interface $(DESTDIR)$(PREFIX)/etc/AppInterface/Session.interface

uninstall:
	$(RM) -- $(DESTDIR)$(PREFIX)/etc/AppInterface/Init.interface
	$(RM) -- $(DESTDIR)$(PREFIX)/etc/AppInterface/Session.interface

.PHONY: all clean distclean install uninstall
