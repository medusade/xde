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
#   File: xde.pri
#
# Author: $author$
#   Date: 12/8/2017
#
# QtCreator .pri file for xde
########################################################################

OTHER_PKG = ../../../../../../../..
OTHER_BLD = ..

########################################################################
# libxslt
libxslt_INCLUDEPATH += \
$${build_libxslt_INCLUDEPATH} \

libxslt_LIBS += \
$${build_libxslt_LIBS} \

########################################################################
# rostra
ROSTRA_PKG = $${OTHER_PKG}/rostra/cpp/xos
ROSTRA_PRJ = $${ROSTRA_PKG}
ROSTRA_SRC = $${ROSTRA_PKG}/src

_rostra_INCLUDEPATH += \
$${ROSTRA_SRC} \

rostra_DEFINES += \

rostra_LIBS += \

########################################################################
# xde
XDE_PKG = ../../../../..
XDE_BLD = ../..

XDE_PRJ = $${XDE_PKG}
XDE_BIN = $${XDE_BLD}/bin
XDE_LIB = $${XDE_BLD}/lib
XDE_SRC = $${XDE_PKG}/../c/src
XDE_CPP_SRC = $${XDE_PKG}/../cpp/src

CONFIG(debug, debug|release) {
BUILD_CONFIG = Debug
xde_DEFINES += DEBUG_BUILD
} else {
BUILD_CONFIG = Release
xde_DEFINES += RELEASE_BUILD
}

XDE_CPP_INCLUDES += \
$${XDE_CPP_SRC}/clib/clibc/clibxml2/clibxslt \
$${XDE_CPP_SRC}/clib/cxml/cxslt \
$${XDE_CPP_SRC}/clib/cxml \
$${XDE_CPP_SRC}/clib/cxttp \
$${XDE_CPP_SRC}/clib/cos \
$${XDE_CPP_SRC}/clib/cbase \

XDE_CSERVER_INCLUDES = \
$${XDE_SRC}/clib/cserver \
$${XDE_SRC}/clib/cservlet \
$${XDE_SRC}/clib/ccgi \
$${XDE_SRC}/clib/cxttp \

XDE_CXSL_INCLUDES = \
$${XDE_SRC}/clib/cxsl \

XDE_CT_INCLUDES = \
$${XDE_SRC}/clib/ct \
$${XDE_SRC}/clib/cyy \

XDE_CMPINT_INCLUDES = \
$${XDE_SRC}/clib/cmpint/bn \
$${XDE_SRC}/clib/cmpint/mp \
$${XDE_SRC}/clib/cmpint \

XDE_COS_INCLUDES += \
$${XDE_SRC}/clib/csocket \
$${XDE_SRC}/clib/cfs \
$${XDE_SRC}/clib/cos/cwin \
$${XDE_SRC}/clib/cos/cunix \
$${XDE_SRC}/clib/cos/cplatform \
$${XDE_SRC}/clib/cos \

XDE_CLIB_INCLUDES += \
$${XDE_SRC}/clib/cbase \
$${XDE_SRC}/clib \

XDE_INCLUDES += \
$${XDE_CSERVER_INCLUDES} \
$${XDE_CXSL_INCLUDES} \
$${XDE_CT_INCLUDES} \
$${XDE_COS_INCLUDES} \
$${XDE_CLIB_INCLUDES} \
$${XDE_CPP_INCLUDES} \

xde_INCLUDEPATH += \
$${XDE_INCLUDES} \
$${rostra_INCLUDEPATH} \
$${build_xde_INCLUDEPATH} \

xde_DEFINES += \
DB_PRINTF=platform_db_printf \
$${rostra_DEFINES} \
$${build_xde_DEFINES} \

xde_LIBS += \
-L$${XDE_LIB}/libxde \
-lxde \

xde_xttp_LIBS += \
-L$${XDE_LIB}/libxdexttp \
-lxdexttp \

xde_t_LIBS += \
-L$${XDE_LIB}/libxdet \
-lxdet \

xde_yy_LIBS += \
-L$${XDE_LIB}/libxdeyy \
-lxdeyy \
