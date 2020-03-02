########################################################################
# Copyright (c) 1988-2020 $organization$
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
#   Date: 3/2/2020
#
# generic Gcc Makefile for xde Executable uuid
########################################################################


#
# target
#
uuid_EXETARGET = uuid

########################################################################

#
# user c++ flags
#
uuid_USRCXXFLAGS += \
${xde_USRCXXFLAGS} \

#
# user defines
#
uuid_USRDEFINES += \
${xde_USRDEFINES} \

#
# user includes
#
uuid_USRINCLUDES += \
${xde_USRINCLUDES} \
${medusade_USRINCLUDES} \

#
# user libdirs
#
uuid_USRLIBDIRS += \
${xde_USRLIBDIRS} \

########################################################################

#
# Executable .c sources
#
#uuid_EXE_C_SOURCES += \
#${XDE_SRC}/xde/base/Base.c \

#
# Executable .cc sources
#
#uuid_EXE_CC_SOURCES += \
#${XDE_SRC}/xde/base/Base.cc \

#
# Executable .cxx sources
#
uuid_EXE_CXX_SOURCES += \
${xde_crypto_CXX_SOURCES} \
${XDE_SRC}/clib/cos/argmain.cxx \
${XDE_SRC}/capp/cnetwork/uuid/cuuidmain.cxx \

#
# Executable .cpp sources
#
#uuid_EXE_CPP_SOURCES += \
#${XDE_SRC}/xde/base/Base.cpp \

#
# Executable .m sources
#
#uuid_EXE_M_SOURCES += \
#${XDE_SRC}/xde/base/Base.m \

#
# Executable .mm sources
#
#uuid_EXE_MM_SOURCES += \
#${XDE_SRC}/xde/base/Base.mm \


########################################################################

#
# Executable libraries
#
uuid_LIBS += \
${xde_LIBS}
