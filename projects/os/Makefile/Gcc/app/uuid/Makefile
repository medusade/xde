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
# Os Gcc Makefile for xde Executable uuid
########################################################################
PKG = ../../../../../..

BMK = build/Makefile/Gcc
MAK = projects/Makefile/Gcc
PRJ = projects/${OS}/Makefile/Gcc
SRC = src

include $(PKG)/$(BMK)/Makedefines
include $(PKG)/$(MAK)/Makedefines
include $(PKG)/$(MAK)/Makefile
include $(PKG)/$(BMK)/Makefile
include $(PKG)/$(MAK)/app/uuid/Makefile

#
# target
#
EXETARGET = ${uuid_EXETARGET}

########################################################################

#
# user defines
#
USRDEFINES += \
${uuid_USRDEFINES}

#
# user includes
#
USRINCLUDES += \
${uuid_USRINCLUDES}

#
# user libdirs
#
USRLIBDIRS += \
${uuid_USRLIBDIRS}

#
# user c++ flags
#
USRCXXFLAGS += \
${uuid_USRCXXFLAGS}

#
# user c flags
#
USRCFLAGS += \
${uuid_USRCFLAGS}

#
# user ld flags
#
USRLDFLAGS += \
${uuid_USRLDFLAGS}

########################################################################

#
# Executable C sources
#
EXE_C_SOURCES += \
${uuid_EXE_C_SOURCES}

#
# Executable C++ .cc sources
#
EXE_CC_SOURCES += \
${uuid_EXE_CC_SOURCES}

#
# Executable C++ .cxx sources
#
EXE_CXX_SOURCES += \
${uuid_EXE_CXX_SOURCES}

#
# Executable C++ .cpp sources
#
EXE_CPP_SOURCES += \
${uuid_EXE_CPP_SOURCES}

#
# Executable Objective C .m sources
#
EXE_M_SOURCES += \
${uuid_EXE_M_SOURCES}

#
# Executable Objective C++ .mm sources
#
EXE_MM_SOURCES += \
${uuid_EXE_MM_SOURCES}

########################################################################

#
# Executable libraries
#
LIBS += \
${uuid_LIBS}

########################################################################

#
# Executable depends
#
#EXEDEP += \
#$(PKG)/$(BLD)/libsomelib \
#
EXEDEP += \

#
# Executable depend dirs
#
#EXEDEP_DIRS += \
#../libsomelib
#
EXEDEP_DIRS += \

include $(PKG)/$(MAK)/Makerules

#
# Executable depend rules
#
#$(PKG)/$(BLD)/libsomelib.a:
#	@(echo Building libsomelib.a ...;\
#	  pushd ../libsomelib;\
#	  ((make) || (exit 1));\
#	  popd)
#


