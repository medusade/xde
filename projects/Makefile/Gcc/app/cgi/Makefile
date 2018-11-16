########################################################################
# Copyright (c) 1988-2018 $organization$
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
#   Date: 11/14/2018
#
# generic Gcc Makefile for xde Executable cgi
########################################################################


#
# target
#
cgi_EXETARGET = cgi

########################################################################

#
# user c++ flags
#
cgi_USRCXXFLAGS += \
${xde_USRCXXFLAGS} \

#
# user defines
#
cgi_USRDEFINES += \
${xde_USRDEFINES} \

#
# user includes
#
cgi_USRINCLUDES += \
${xde_USRINCLUDES} \

#
# user libdirs
#
cgi_USRLIBDIRS += \
${xde_USRLIBDIRS} \

########################################################################

#
# Executable .c sources
#
#cgi_EXE_C_SOURCES += \
#${XDE_SRC}/xde/base/Base.c \

#
# Executable .cc sources
#
#cgi_EXE_CC_SOURCES += \
#${XDE_SRC}/xde/base/Base.cc \

#
# Executable .cxx sources
#
cgi_EXE_CXX_SOURCES += \
${XDE_SRC}/capp/ccgi/cgi/ccgimain.cxx \
${XDE_SRC}/clib/ccgi/cgi.cxx \

#
# Executable .cpp sources
#
#cgi_EXE_CPP_SOURCES += \
#${XDE_SRC}/xde/base/Base.cpp \

#
# Executable .m sources
#
#cgi_EXE_M_SOURCES += \
#${XDE_SRC}/xde/base/Base.m \

#
# Executable .mm sources
#
#cgi_EXE_MM_SOURCES += \
#${XDE_SRC}/xde/base/Base.mm \


########################################################################

#
# Executable libraries
#
cgi_LIBS += \
${xde_LIBS}



