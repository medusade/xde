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
#   File: libxdeyy.pro
#
# Author: $author$
#   Date: 12/9/2017
#
# QtCreator .pro file for xde library libxdeyy
########################################################################
include(../../../../../build/QtCreator/xde.pri)
include(../../../../QtCreator/xde.pri)
include(../../xde.pri)
include(../../../../QtCreator/lib/libxdeyy/libxdeyy.pri)

TARGET = $${libxdeyy_TARGET}
TEMPLATE = lib
CONFIG += staticlib

########################################################################
INCLUDEPATH += \
$${libxdeyy_INCLUDEPATH} \

DEFINES += \
$${libxdeyy_DEFINES} \

########################################################################
HEADERS += \
$${libxdeyy_HEADERS} \

SOURCES += \
$${libxdeyy_SOURCES} \

########################################################################


