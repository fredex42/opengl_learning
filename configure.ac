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
#AS_IF([test "x$(uname -s)" == "xDarwin"],[LDFLAGS="-framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo ${LDFLAGS}"])
AC_CANONICAL_HOST
# Check for which host we are on and setup a few things
# specifically based on the host
case $host_os in
  darwin* )
        # Do something specific for mac
        LDFLAGS="-framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo ${LDFLAGS}"
        ;;
  linux* )
        # Do something specific for linux
        ;;
   *BSD*)
        # Do something specific for BSD
        ;;
    *)
        #Default Case
        ;;
esac
# Checks for header files.
AC_CHECK_HEADER([stdlib.h])
AC_LANG_PUSH([C++])
AC_CHECK_HEADER([GL/glew.h],[],[AC_MSG_ERROR([You need to install the development files for GLEW. On Debian-style distros this is libglew-dev])])
#AC_CHECK_HEADER([GL/glfw.h],[AC_DEFINE([HAVE_GLFW_H],[1],[Debian-syle GLFW header]) found_glfw_header=yes; break;])
AC_CHECK_HEADER([GLFW/glfw3.h],[AC_DEFINE([HAVE_GLFW3_H],[1],[Mac-stype GLFW header]) found_glfw_header=yes; break;])
AS_IF([test "x$found_glfw_header" != "xyes"],[AC_MSG_ERROR([You need to install the development files for GLFW. On Debian-style distros this is libglfw-dev])])

AC_CHECK_HEADER([glm/glm.hpp],[],[AC_MSG_ERROR([You need to install the glm header files package. On Debian-style distros this is libglm-dev])])
AC_CHECK_HEADER([glm/gtc/matrix_transform.hpp],[],[AC_MSG_ERROR([You need to install the glm header files package])])
AC_CHECK_HEADER([glm/gtx/transform.hpp],[],[AC_MSG_ERROR([You need to install the glm header files package])])

AC_LANG_POP([C++])
# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL

# Checks for library functions.
AC_SEARCH_LIBS([glewInit],[glew GLEW],[],[AC_MSG_ERROR([You need to install the development files for GLEW])])
AC_SEARCH_LIBS([glfwInit],[glfw3],[],[AC_MSG_ERROR([You need to install the development files for GLFW])],[-lX11 -ldl])
AC_SEARCH_LIBS([glClear],[GL],[],[AC_MSG_ERROR([You need to install the development files for OpenGL])])

AC_OUTPUT
