
AC_PREREQ (2.61)

AC_INIT(filter_backport, 1.0, tompkins@nscl.msu.edu, [], [])

AC_CONFIG_HEADER([config.h])
AC_CONFIG_MACRO_DIR([m4])

AC_PROG_CXX
AC_PROG_INSTALL
AC_PROG_LIBTOOL

AM_INIT_AUTOMAKE([foreign])
SOVERSION="1:0:0"

AX_GENGETOPT

#
#  Threading is hard coded to -pthread now.
#
THREADCXX_FLAGS="-pthread"
THREADC_FLAGS="-pthread"
THREADLD_FLAGS="-lpthread -lrt"

AC_SUBST(SOVERSION)
AC_SUBST(THREADCXX_FLAGS)
AC_SUBST(THREADC_FLAGS)
AC_SUBST(THREADLD_FLAGS)


# specify the output Makefiles for config.status
AC_CONFIG_FILES([Makefile
                 src/Makefile])

AC_OUTPUT
