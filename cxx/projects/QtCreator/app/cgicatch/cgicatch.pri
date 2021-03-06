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
#   File: cgicatch.pri
#
# Author: $author$
#   Date: 12/9/2017
#
# QtCreator .pri file for xde executable cgicatch
########################################################################

cgicatch_TARGET = xde-cgicatch

########################################################################
cgicatch_INCLUDEPATH += \
$${xde_INCLUDEPATH} \

cgicatch_DEFINES += \
$${xde_DEFINES} \

########################################################################
# xde
cgicatch_HEADERS += \
$${XDE_SRC}/capp/ccgi/cgicatch/ccgicatch.hxx \
$${XDE_SRC}/clib/ccgi/cgi.hxx \

cgicatch_SOURCES += \
$${XDE_SRC}/capp/ccgi/cgicatch/ccgicatch.cxx \
$${XDE_SRC}/clib/ccgi/cgi.cxx \

########################################################################
cgicatch_LIBS += \
$${xde_xttp_LIBS} \
$${xde_LIBS} \



