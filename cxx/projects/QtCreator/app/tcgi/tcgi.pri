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
#   File: tcgi.pri
#
# Author: $author$
#   Date: 12/9/2017
#
# QtCreator .pri file for xde executable tcgi
########################################################################

tcgi_TARGET = xde-tcgi

########################################################################
tcgi_INCLUDEPATH += \
$${xde_INCLUDEPATH} \

tcgi_DEFINES += \
$${xde_DEFINES} \

########################################################################
# xde
tcgi_HEADERS += \
$${XDE_SRC}/clib/ccgi/cgi.hxx \
$${XDE_SRC}/clib/ct/ctcgi.hxx \
$${XDE_SRC}/clib/ct/ctfunctions.hxx \
$${XDE_SRC}/clib/ct/ctfilefunctions.hxx \
$${XDE_SRC}/clib/ct/ctdatefunctions.hxx \
$${XDE_SRC}/clib/ct/ctconditionalfunctions.hxx \
$${XDE_SRC}/clib/ct/ctstringfunctions.hxx \

tcgi_SOURCES += \
$${XDE_SRC}/clib/ccgi/cgi.cxx \
$${XDE_SRC}/clib/ct/ctcgi.cxx \
$${XDE_SRC}/clib/ct/ctfunctions.cxx \
$${XDE_SRC}/clib/ct/ctfilefunctions.cxx \
$${XDE_SRC}/clib/ct/ctdatefunctions.cxx \
$${XDE_SRC}/clib/ct/ctconditionalfunctions.cxx \
$${XDE_SRC}/clib/ct/ctstringfunctions.cxx \

########################################################################
tcgi_LIBS += \
$${xde_t_LIBS} \
$${xde_xttp_LIBS} \
$${xde_LIBS} \



