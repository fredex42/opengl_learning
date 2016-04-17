#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([opengl learning], [1.0], [BUG-REPORT-ADDRESS])
AM_INIT_AUTOMAKE
AC_CONFIG_SRCDIR([src/])
AM_CONFIG_HEADER(config.h)
AC_CONFIG_FILES([Makefile])

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h])
AC_CHECK_HEADERS([GL/glew.h],[],[AC_MSG_ERROR([You need to install the development files for GLEW. On Debian-style distros this is libglew-dev])])
AC_CHECK_HEADERS([GLFW/glfw.h],[],[AC_MSG_ERROR([You need to install the development files for GLFW])]))
AC_CHECK_HEADERS([glm/glm.hpp],[],[AC_MSG_ERROR([You need to install the glm header files package])]))
AC_CHECK_HEADERS([glm/gtc/matrix_transform.hpp],[],[AC_MSG_ERROR([You need to install the glm header files package])]))
AC_CHECK_HEADERS([glm/gtx/transform.hpp],[],[AC_MSG_ERROR([You need to install the glm header files package])]))

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL

# Checks for library functions.

AC_OUTPUT
