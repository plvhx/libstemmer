LLLIBS  = context/libstemmercontext.la
LLLIBS += disambiguator/libdisambiguator.la

LIBSTEMCPP  = affix-pair.cpp
LIBSTEMCPP += dictionary.cpp
LIBSTEMCPP += hash.cpp
LIBSTEMCPP += disambiguator-rule-factory.cpp
LIBSTEMCPP += precedence-adjustor-specification.cpp
LIBSTEMCPP += stemmer.cpp
LIBSTEMCPP += string-util.cpp
LIBSTEMCPP += stopword-remover-factory.cpp
LIBSTEMCPP += stopword-remover.cpp

AM_CPPFLAGS = -I$(srcdir)/../include -DPKGDATADIR='"$(pkgdatadir)"'

SUBDIRS  = context
SUBDIRS += disambiguator 

lib_LTLIBRARIES = libstemmer.la

libstemmer_la_SOURCES = $(LIBSTEMCPP)
libstemmer_la_LIBADD = $(LLLIBS)
libstemmer_la_LDFLAGS = -version-info 0:0:0 -no-undefined