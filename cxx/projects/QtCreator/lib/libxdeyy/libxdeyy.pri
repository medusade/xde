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
#   File: libxdeyy.pri
#
# Author: $author$
#   Date: 12/9/2017
#
# QtCreator .pri file for xde library libxdeyy
########################################################################

libxdeyy_TARGET = xdeyy

########################################################################
libxdeyy_INCLUDEPATH += \
$${xde_INCLUDEPATH} \

libxdeyy_DEFINES += \
$${xde_DEFINES} \

########################################################################
# xde
libxdeyy_HEADERS += \
$${XDE_SRC}/clib/cyy/clexercgi.hxx \
$${XDE_SRC}/clib/cyy/clexercgilex.hxx \
$${XDE_SRC}/clib/cyy/clexersource.hxx \
$${XDE_SRC}/clib/cyy/clexertoken.hxx \
$${XDE_SRC}/clib/cyy/cyylexer.hxx \

libxdeyy_SOURCES += \
$${XDE_SRC}/clib/cyy/clexercgi.cxx \
$${XDE_SRC}/clib/cyy/clexercgilex.cxx \
$${XDE_SRC}/clib/cyy/clexersource.cxx \
$${XDE_SRC}/clib/cyy/clexertoken.cxx \
$${XDE_SRC}/clib/cyy/cyylexer.cxx \

########################################################################
