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
# generic Gcc Makefile for xde Executable cxxlcgi
########################################################################


#
# target
#
cxxlcgi_EXETARGET = cxxlcgi

########################################################################

#
# user c++ flags
#
cxxlcgi_USRCXXFLAGS += \
${xde_USRCXXFLAGS} \

#
# user defines
#
cxxlcgi_USRDEFINES += \
${xde_USRDEFINES} \

#
# user includes
#
cxxlcgi_USRINCLUDES += \
${xde_USRINCLUDES} \

#
# user libdirs
#
cxxlcgi_USRLIBDIRS += \
${xde_USRLIBDIRS} \

########################################################################

#
# Executable .c sources
#
#cxxlcgi_EXE_C_SOURCES += \
#${XDE_SRC}/xde/base/Base.c \

#
# Executable .cc sources
#
#cxxlcgi_EXE_CC_SOURCES += \
#${XDE_SRC}/xde/base/Base.cc \

#
# Executable .cxx sources
#
cxxlcgi_EXE_CXX_SOURCES += \
${XDE_SRC}/capp/ccgi/cxxlcgi/ccxxlcgi.cxx \
${XDE_SRC}/capp/ccgi/cxxlcgi/ccxxlex.cxx \
${XDE_SRC}/capp/ccgi/cxxlcgi/ccxxlexer.cxx \
${XDE_SRC}/clib/ccgi/cgi.cxx \
${xde_t_functions_CXX_SOURCES} \

#
# Executable .cpp sources
#
#cxxlcgi_EXE_CPP_SOURCES += \
#${XDE_SRC}/xde/base/Base.cpp \

#
# Executable .m sources
#
#cxxlcgi_EXE_M_SOURCES += \
#${XDE_SRC}/xde/base/Base.m \

#
# Executable .mm sources
#
#cxxlcgi_EXE_MM_SOURCES += \
#${XDE_SRC}/xde/base/Base.mm \

#
# Executable .lcgi sources
#
cxxlcgi_EXE_LCGI_SOURCES += \
${XDE_SRC}/capp/ccgi/cxxlcgi/cxxlcgi.lcgi \
${XDE_SRC}/capp/ccgi/cxxlcgi/lcgi-top.lcgi \
${XDE_SRC}/capp/ccgi/cxxlcgi/lcgi-bottom.lcgi \

########################################################################

#
# Executable libraries
#
cxxlcgi_LIBS += \
${xde_LIBS}

########################################################################

RESINSTALL = install-res
install-res: ${EXETARGET} ${INSBIN}
	@(echo "Installing - cxxlcgi.lcgi lcgi-top.lcgi lcgi-bottom.lcgi"...;\
	  ((cp -r $(BINDIR)/cxxlcgi.lcgi $(INSBIN)) || (exit 1));\
	  ((cp -r $(BINDIR)/lcgi-top.lcgi $(INSBIN)) || (exit 1));\
	  ((cp -r $(BINDIR)/lcgi-bottom.lcgi $(INSBIN)) || (exit 1));\
	  echo ..."Installed - cxxlcgi.lcgi lcgi-top.lcgi lcgi-bottom.lcgi")

