#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([file-lib], [0.1], [vencahrbek@email.cz])
AC_CONFIG_SRCDIR([include/file.h], [src/file.c], [tests/check_file.c])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIR([m4])
AM_PROG_AR

# Checks for programs.
AC_PROG_CC
AC_PROG_LIBTOOL

# Checks for libraries.
PKG_CHECK_MODULES([CHECK], [check >= 0.15.0])

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T

# Checks for library functions.
AC_FUNC_MALLOC

AM_INIT_AUTOMAKE([-Wall -Werror foreign])
AC_CONFIG_FILES([Makefile
				src/Makefile
				tests/Makefile
				])

AC_OUTPUT
