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
# generic Gcc Makefile for xde
########################################################################

OTHER_VERSION_PKG = ${PKG}
OTHER_DEPENDS_PKG = ${PKG}/..
OTHER_THIRDPARTY_NAME = thirdparty
OTHER_THIRDPARTY_VERSION_PKG = ${OTHER_VERSION_PKG}/${OTHER_THIRDPARTY_NAME}

########################################################################
# xde

XDE_PKG = ${PKG}
XDE_SRC = ${XDE_PKG}/src/xde
XDE_BLD = ${XDE_PKG}/${BLD}/${BUILD_TYPE}
XDE_LIB = ${XDE_BLD}/lib
XDE_BIN = ${XDE_BLD}/bin

# xde USRDEFINES
#
xde_USRDEFINES += \
${build_xde_USRDEFINES} \

# xde USRINCLUDES
#
xde_USRINCLUDES += \
-I${XDE_SRC}/clib/ccgi \
-I${XDE_SRC}/clib/cxttp \
-I${XDE_SRC}/clib/cyy \
-I${XDE_SRC}/clib/cxsl \
-I${XDE_SRC}/clib/ct \
\
-I${XDE_SRC}/clib/csocket \
-I${XDE_SRC}/clib/cfs \
-I${XDE_SRC}/clib/cos/cwin \
-I${XDE_SRC}/clib/cos/cunix \
-I${XDE_SRC}/clib/cos/cplatform \
-I${XDE_SRC}/clib/cos \
\
-I${XDE_SRC}/clib/cbase \
-I${XDE_SRC}/clib \
-I${XDE_SRC} \
${build_xde_USRINCLUDES} \

# xde USRCXXFLAGS
#
xde_USRCXXFLAGS += \
${build_xde_USRCXXFLAGS} \

# xde USRLIBDIRS
#
xde_USRLIBDIRS += \
-L${XDE_LIB} \
${build_xde_USRLIBDIRS} \

# xde LIBS
#
xde_LIBS += \
-lxde \
${build_xde_LIBS} \

# xde t functions CXX SOURCES
#
xde_t_functions_CXX_SOURCES += \
${XDE_SRC}/clib/ct/ctfunctions.cxx \
${XDE_SRC}/clib/ct/ctfilefunctions.cxx \
${XDE_SRC}/clib/ct/ctdatefunctions.cxx \
${XDE_SRC}/clib/ct/ctconditionalfunctions.cxx \
${XDE_SRC}/clib/ct/ctstringfunctions.cxx \

########################################################################
# medusaxde

MEDUSAXDE_PKG = ${PKG}
MEDUSAXDE_SRC = ${MEDUSAXDE_PKG}/src/medusaxde
MEDUSAXDE_BLD = ${MEDUSAXDE_PKG}/${BLD}/${BUILD_TYPE}
MEDUSAXDE_LIB = ${MEDUSAXDE_BLD}/lib
MEDUSAXDE_BIN = ${MEDUSAXDE_BLD}/bin

# medusaxde USRDEFINES
#
medusaxde_USRDEFINES += \
${xde_USRDEFINES} \
${build_medusaxde_USRDEFINES} \

# medusaxde USRINCLUDES
#
medusaxde_USRINCLUDES += \
${xde_USRINCLUDES} \
-I${MEDUSAXDE_SRC}/clib/clibc/clibxml2/clibxslt \
-I${MEDUSAXDE_SRC}/clib/cxml/cxslt \
-I${MEDUSAXDE_SRC}/clib/cxml \
-I${MEDUSAXDE_SRC}/clib/cxttp \
-I${MEDUSAXDE_SRC}/clib/cos \
-I${MEDUSAXDE_SRC}/clib/cbase \
-I${MEDUSAXDE_SRC}/clib \
-I${MEDUSAXDE_SRC} \
${build_medusaxde_USRINCLUDES} \

# medusaxde USRCXXFLAGS
#
medusaxde_USRCXXFLAGS += \
${xde_USRCXXFLAGS} \
${build_medusaxde_USRCXXFLAGS} \

# medusaxde USRLIBDIRS
#
medusaxde_USRLIBDIRS += \
-L${MEDUSAXDE_LIB} \
${xde_USRLIBDIRS} \
${build_medusaxde_USRLIBDIRS} \

# medusaxde LIBS
#
medusaxde_LIBS += \
-lmedusaxde \
${xde_LIBS} \
${build_medusaxde_LIBS} \

########################################################################

