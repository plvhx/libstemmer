AM_CPPFLAGS = -I$(srcdir)/../../../include -DPKGDATADIR='"$(pkgdatadir)"'

noinst_LTLIBRARIES = libstemmervisitor.la

libstemmervisitor_la_SOURCES = \
	remove-derivational-suffix.cpp \
	remove-inflectional-particle.cpp \
	remove-inflectional-possessive-pronoun.cpp \
	remove-plain-prefix.cpp \
	unstem-short-word.cpp \
	prefix-disambiguator.cpp \
	visitor-provider.cpp