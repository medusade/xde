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
# generic Gcc Makefile for xde
########################################################################

XDE_PKG = ${PKG}
XDE_SRC = ${XDE_PKG}/../c/src
XDE_CPP_SRC = ${XDE_PKG}/../cpp/src
XDE_BLD = ${XDE_PKG}/${BLD}/${BUILD_TYPE}
XDE_LIB = ${XDE_BLD}/lib
XDE_BIN = ${XDE_BLD}/bin

########################################################################
# rostra
ROSTRA_PKG = ${XDE_PKG}/../../../rostra/cpp/xos
ROSTRA_SRC = ${ROSTRA_PKG}/src
ROSTRA_BLD = ${ROSTRA_PKG}/${BLD}/${BUILD_TYPE}
ROSTRA_LIB = ${ROSTRA_BLD}/lib
ROSTRA_BIN = ${ROSTRA_BLD}/bin


########################################################################
# xde
xde_USRDEFINES += \
${build_xde_USRDEFINES} \

XDE_CPP_INCLUDES += \
-I${XDE_CPP_SRC}/clib/clibc/clibxml2/clibxslt \
-I${XDE_CPP_SRC}/clib/cxml/cxslt \
-I${XDE_CPP_SRC}/clib/cxml \
-I${XDE_CPP_SRC}/clib/cxttp \
-I${XDE_CPP_SRC}/clib/cos \
-I${XDE_CPP_SRC}/clib/cbase 

XDE_CSERVER_INCLUDES = \
-I${XDE_SRC}/clib/cserver \
-I${XDE_SRC}/clib/cservlet \
-I${XDE_SRC}/clib/ccgi \
-I${XDE_SRC}/clib/cxttp 

XDE_CXSL_INCLUDES = \
-I${XDE_SRC}/clib/cxsl 

XDE_CT_INCLUDES = \
-I${XDE_SRC}/clib/ct \
-I${XDE_SRC}/clib/cyy 

XDE_CMPINT_INCLUDES = \
-I${XDE_SRC}/clib/cmpint/bn \
-I${XDE_SRC}/clib/cmpint/mp \
-I${XDE_SRC}/clib/cmpint 

XDE_COS_INCLUDES += \
-I${XDE_SRC}/clib/csocket \
-I${XDE_SRC}/clib/cfs \
-I${XDE_SRC}/clib/cos/cwin \
-I${XDE_SRC}/clib/cos/cunix \
-I${XDE_SRC}/clib/cos/cplatform \
-I${XDE_SRC}/clib/cos 

XDE_CLIB_INCLUDES += \
-I${XDE_SRC}/clib/cbase \
-I${XDE_SRC}/clib 

XDE_INCLUDES += \
${XDE_CSERVER_INCLUDES} \
${XDE_CXSL_INCLUDES} \
${XDE_CT_INCLUDES} \
${XDE_COS_INCLUDES} \
${XDE_CLIB_INCLUDES} \
${XDE_CPP_INCLUDES} 

xde_USRINCLUDES += \
${XDE_INCLUDES} \
${build_xde_USRINCLUDES}

xde_USRCXXFLAGS += \
${build_xde_USRCXXFLAGS}

xde_USRLIBDIRS += \
-L${XDE_LIB} \
${build_xde_USRLIBDIRS}

xde_LIBS += \
-lxde \
${build_xde_LIBS}

xde_xttp_LIBS += \
-lxdexttp 

xde_t_LIBS += \
-lxdet 

xde_yy_LIBS += \
-lxdeyy 

xde_libxslt_LIBS += \
${build_libxslt_LIBS}

########################################################################
