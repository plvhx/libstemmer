#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([libstemmer], [0.1], [paulus.gandung@digitalsekuriti.id])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_SRCDIR([src/code/affix-pair.cpp])
AC_CONFIG_HEADERS([src/include/stemmer/config.h])

m4_ifdef([AM_PROG_AR], [AM_PROG_AR])

LT_INIT

CXXFLAGS="$CXXFLAGS -O2 -std=c++14 -fPIC -lpcrecpp -lgtest -pthread"

# Checks for programs.
AC_PROG_CXX

# Checks for libraries.
AC_PROG_LIBTOOL

# Checks for header files.
AC_CHECK_HEADERS([stddef.h])

AM_INIT_AUTOMAKE([-Wall])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T

# Checks for library functions.

AC_CONFIG_FILES([libstemmer.pc
				 Makefile
                 src/Makefile
                 src/code/Makefile
                 src/code/context/Makefile
                 src/code/context/visitor/Makefile
                 src/code/disambiguator/Makefile
                 src/include/Makefile
                 test/Makefile
                 parameterized-test/Makefile])

AC_OUTPUT
