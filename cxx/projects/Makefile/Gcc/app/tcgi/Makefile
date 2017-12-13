########################################################################
# Copyright (c) 1988-2017 $organization$
#
# This software is provided by the author and contributors ``as is''
# and any express or implied warranties, including, but not limited to,
# the implied warranties of merchantability and fitness for a particular
# purpose are disclaimed. In no event shall the author or contributors
# be liable for any direct, indirect, incidental, special, exemplary,
# or consequential damages (including, but not limited to, procurement
# of substitute goods or services; loss of use, data, or profits; or
# business interruption) however caused and on any theory of liability,
# whether in contract, strict liability, or tort (including negligence
# or otherwise) arising in any way out of the use of this software,
# even if advised of the possibility of such damage.
#
#   File: Makefile
#
# Author: $author$
#   Date: 12/13/2017
#
# generic Gcc Makefile for xde Executable tcgi
########################################################################


#
# target
#
tcgi_EXETARGET = xde-tcgi

########################################################################

#
# user c++ flags
#
tcgi_USRCXXFLAGS += \
${xde_USRCXXFLAGS} \

#
# user defines
#
tcgi_USRDEFINES += \
${xde_USRDEFINES} \

#
# user includes
#
tcgi_USRINCLUDES += \
${xde_USRINCLUDES} \

#
# user libdirs
#
tcgi_USRLIBDIRS += \
${xde_USRLIBDIRS} \

########################################################################

#
# Executable .c sources
#
#tcgi_EXE_C_SOURCES += \
#${XDE_SRC}/xde/base/Base.c \

#
# Executable .cc sources
#
#tcgi_EXE_CC_SOURCES += \
#${XDE_SRC}/xde/base/Base.cc \

#
# Executable .cxx sources
#
tcgi_EXE_CXX_SOURCES += \
${XDE_SRC}/clib/ccgi/cgi.cxx \
${XDE_SRC}/clib/ct/ctcgi.cxx \
${XDE_SRC}/clib/ct/ctfunctions.cxx \
${XDE_SRC}/clib/ct/ctfilefunctions.cxx \
${XDE_SRC}/clib/ct/ctdatefunctions.cxx \
${XDE_SRC}/clib/ct/ctconditionalfunctions.cxx \
${XDE_SRC}/clib/ct/ctstringfunctions.cxx

#
# Executable .cpp sources
#
#tcgi_EXE_CPP_SOURCES += \
#${XDE_SRC}/xde/base/Base.cpp \

#
# Executable .m sources
#
#tcgi_EXE_M_SOURCES += \
#${XDE_SRC}/xde/base/Base.m \

#
# Executable .mm sources
#
#tcgi_EXE_MM_SOURCES += \
#${XDE_SRC}/xde/base/Base.mm \


########################################################################

#
# Executable libraries
#
tcgi_LIBS += \
${xde_LIBS}



