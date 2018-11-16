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
#   Date: 11/16/2018
#
# generic Gcc Makefile for medusaxde Executable xslcgi
########################################################################


#
# target
#
xslcgi_EXETARGET = xslcgi

########################################################################

#
# user c++ flags
#
xslcgi_USRCXXFLAGS += \
${medusaxde_USRCXXFLAGS} \

#
# user defines
#
xslcgi_USRDEFINES += \
${medusaxde_USRDEFINES} \

#
# user includes
#
xslcgi_USRINCLUDES += \
${medusaxde_USRINCLUDES} \

#
# user libdirs
#
xslcgi_USRLIBDIRS += \
${medusaxde_USRLIBDIRS} \

########################################################################

#
# Executable .c sources
#
#xslcgi_EXE_C_SOURCES += \
#${MEDUSAXDE_SRC}/medusaxde/base/Base.c \

#
# Executable .cc sources
#
#xslcgi_EXE_CC_SOURCES += \
#${MEDUSAXDE_SRC}/medusaxde/base/Base.cc \

#
# Executable .cxx sources
#
xslcgi_EXE_CXX_SOURCES += \
${XDE_SRC}/capp/ccgi/xslcgi/cxslcgi.cxx \
${XDE_SRC}/clib/ccgi/cgi.cxx \
${xde_t_functions_CXX_SOURCES} \

#
# Executable .cpp sources
#
xslcgi_EXE_CPP_SOURCES += \

#
# Executable .m sources
#
#xslcgi_EXE_M_SOURCES += \
#${MEDUSAXDE_SRC}/medusaxde/base/Base.m \

#
# Executable .mm sources
#
#xslcgi_EXE_MM_SOURCES += \
#${MEDUSAXDE_SRC}/medusaxde/base/Base.mm \


########################################################################

#
# Executable libraries
#
xslcgi_LIBS += \
${medusaxde_LIBS}



