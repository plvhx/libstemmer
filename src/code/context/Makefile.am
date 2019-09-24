VLLIBS = \
	visitor/libstemmervisitor.la

AM_CPPFLAGS = -I$(srcdir)/../../include -DPKGDATADIR='"$(pkgdatadir)"'

SUBDIRS = visitor

noinst_LTLIBRARIES = libstemmercontext.la

libstemmercontext_la_SOURCES = \
	context.cpp \
	removal.cpp

libstemmercontext_la_LIBADD = $(VLLIBS)