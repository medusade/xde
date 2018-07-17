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
#   File: adalcgi.pri
#
# Author: $author$
#   Date: 7/17/2018
#
# QtCreator .pri file for xde executable adalcgi
########################################################################

adalcgi_TARGET = xde-adalcgi

########################################################################
adalcgi_INCLUDEPATH += \
$${xde_INCLUDEPATH} \

adalcgi_DEFINES += \
$${xde_DEFINES} \

########################################################################
# xde
adalcgi_HEADERS += \
$${XDE_SRC}/capp/ccgi/adalcgi/cadalexer.hxx \
$${XDE_SRC}/capp/ccgi/adalcgi/cadacgi.hxx \
$${XDE_SRC}/clib/ccgi/cgi.hxx \

adalcgi_SOURCES += \
$${XDE_SRC}/capp/ccgi/adalcgi/cadalex.cxx \
$${XDE_SRC}/capp/ccgi/adalcgi/cadalexer.cxx \
$${XDE_SRC}/capp/ccgi/adalcgi/cadacgi.cxx \
$${XDE_SRC}/clib/cyy/clexercgilex.cxx \
$${XDE_SRC}/clib/cyy/clexersource.cxx \
$${XDE_SRC}/clib/cyy/clexertoken.cxx \
$${XDE_SRC}/clib/cyy/cyylexer.cxx \
$${XDE_SRC}/clib/ccgi/ctemplatenamelist.cxx \
$${XDE_SRC}/clib/ccgi/cdocumentnamelist.cxx \
$${XDE_SRC}/clib/ccgi/ctemplatefilenameitems.cxx \
$${XDE_SRC}/clib/ccgi/cdocumentfilenameitems.cxx \
$${XDE_SRC}/clib/ccgi/cgi.cxx \

########################################################################
adalcgi_LIBS += \
$${xde_yy_LIBS} \
$${xde_t_LIBS} \
$${xde_xttp_LIBS} \
$${xde_LIBS} \
