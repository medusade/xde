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
#   File: xslcgi.pri
#
# Author: $author$
#   Date: 12/10/2017
#
# QtCreator .pri file for xde executable xslcgi
########################################################################

xslcgi_TARGET = xde-xslcgi

########################################################################
xslcgi_INCLUDEPATH += \
$${xde_INCLUDEPATH} \

xslcgi_DEFINES += \
$${xde_DEFINES} \

########################################################################
# xde
xslcgi_HEADERS += \
$${XDE_SRC}/clib/cxsl/cxsltransformerinstance.hxx \
$${XDE_SRC}/clib/cxsl/cxsltransformerinterface.hxx \
$${XDE_SRC}/clib/cxsl/cxmlreaderinterface.hxx \
$${XDE_SRC}/clib/cxsl/cxmlnodeinterface.hxx \
$${XDE_SRC}/clib/cxsl/cxmlnodetype.hxx \

xslcgi_SOURCES += \
$${XDE_SRC}/clib/cxsl/cxsltransformerinstance.cxx \
$${XDE_SRC}/clib/cxsl/cxsltransformerinterface.cxx \
$${XDE_SRC}/clib/cxsl/cxmlreaderinterface.cxx \
$${XDE_SRC}/clib/cxsl/cxmlnodeinterface.cxx \
$${XDE_SRC}/clib/cxsl/cxmlnodetype.cxx \

########################################################################
# xde
xslcgi_HEADERS += \
$${XDE_SRC}/capp/ccgi/xslcgi/cxslcgi.hxx \
$${XDE_SRC}/clib/ccgi/cgi.hxx \

#$${XDE_SRC}/clib/cbase/cnamelist.hxx \

xslcgi_SOURCES += \
$${XDE_SRC}/capp/ccgi/xslcgi/cxslcgi.cxx \
$${XDE_SRC}/clib/ccgi/cgi.cxx \

#$${XDE_SRC}/clib/cbase/cnamelist.cxx \

########################################################################
xslcgi_LIBS += \
$${xde_t_LIBS} \
$${xde_xttp_LIBS} \
$${xde_LIBS} \



