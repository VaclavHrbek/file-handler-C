AUTOMAKE_OPTIONS = subdir-objects

lib_LTLIBRARIES = libfile.la
libfile_la_SOURCES = \
		$(top_builddir)/src/file.c 
#$(top_builddir)/include/file.h
libfile_la_CFLAGS = -g -Werror -Wall 
libfile_la_CPPFLAGS = -Iinclude/
include_HEADERS = $(top_builddir)/include/file.h

