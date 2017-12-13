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
# generic Gcc Makefile for xde Executable cgicatch
########################################################################


#
# target
#
cgicatch_EXETARGET = xde-cgicatch

########################################################################

#
# user c++ flags
#
cgicatch_USRCXXFLAGS += \
${xde_USRCXXFLAGS} \

#
# user defines
#
cgicatch_USRDEFINES += \
${xde_USRDEFINES} \

#
# user includes
#
cgicatch_USRINCLUDES += \
${xde_USRINCLUDES} \

#
# user libdirs
#
cgicatch_USRLIBDIRS += \
${xde_USRLIBDIRS} \

########################################################################

#
# Executable .c sources
#
#cgicatch_EXE_C_SOURCES += \
#${XDE_SRC}/xde/base/Base.c \

#
# Executable .cc sources
#
#cgicatch_EXE_CC_SOURCES += \
#${XDE_SRC}/xde/base/Base.cc \

#
# Executable .cxx sources
#
cgicatch_EXE_CXX_SOURCES += \
${XDE_SRC}/capp/ccgi/cgicatch/ccgicatch.cxx \
${XDE_SRC}/clib/ccgi/cgi.cxx

#
# Executable .cpp sources
#
#cgicatch_EXE_CPP_SOURCES += \
#${XDE_SRC}/xde/base/Base.cpp \

#
# Executable .m sources
#
#cgicatch_EXE_M_SOURCES += \
#${XDE_SRC}/xde/base/Base.m \

#
# Executable .mm sources
#
#cgicatch_EXE_MM_SOURCES += \
#${XDE_SRC}/xde/base/Base.mm \


########################################################################

#
# Executable libraries
#
cgicatch_LIBS += \
${xde_LIBS}



