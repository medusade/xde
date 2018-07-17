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
#   Date: 7/17/2018
#
# generic Gcc Makefile for xde Executable adalcgi
########################################################################


#
# target
#
adalcgi_EXETARGET = xde-adalcgi

########################################################################

#
# user c++ flags
#
adalcgi_USRCXXFLAGS += \
${xde_USRCXXFLAGS} \

#
# user defines
#
adalcgi_USRDEFINES += \
${xde_USRDEFINES} \

#
# user includes
#
adalcgi_USRINCLUDES += \
${xde_USRINCLUDES} \

#
# user libdirs
#
adalcgi_USRLIBDIRS += \
${xde_USRLIBDIRS} \

########################################################################

#
# Executable .c sources
#
#adalcgi_EXE_C_SOURCES += \
#${XDE_SRC}/xde/base/Base.c \

#
# Executable .cc sources
#
#adalcgi_EXE_CC_SOURCES += \
#${XDE_SRC}/xde/base/Base.cc \

#
# Executable .cxx sources
#
adalcgi_EXE_CXX_SOURCES += \
${XDE_SRC}/capp/ccgi/adalcgi/cadalex.cxx \
${XDE_SRC}/capp/ccgi/adalcgi/cadalexer.cxx \
${XDE_SRC}/capp/ccgi/adalcgi/cadacgi.cxx \
${XDE_SRC}/clib/ccgi/cgi.cxx \
${XDE_SRC}/clib/ccgi/ctemplatenamelist.cxx \
${XDE_SRC}/clib/ccgi/cdocumentnamelist.cxx \
${XDE_SRC}/clib/ccgi/ctemplatefilenameitems.cxx \
${XDE_SRC}/clib/ccgi/cdocumentfilenameitems.cxx \
${XDE_SRC}/clib/cyy/clexercgilex.cxx \
${XDE_SRC}/clib/cyy/clexersource.cxx \
${XDE_SRC}/clib/cyy/clexertoken.cxx \
${XDE_SRC}/clib/cyy/cyylexer.cxx \

#
# Executable .cpp sources
#
#adalcgi_EXE_CPP_SOURCES += \
#${XDE_SRC}/xde/base/Base.cpp \

#
# Executable .m sources
#
#adalcgi_EXE_M_SOURCES += \
#${XDE_SRC}/xde/base/Base.m \

#
# Executable .mm sources
#
#adalcgi_EXE_MM_SOURCES += \
#${XDE_SRC}/xde/base/Base.mm \


########################################################################

#
# Executable libraries
#
adalcgi_LIBS += \
${xde_LIBS}



