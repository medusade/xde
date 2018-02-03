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
#   File: librt.pri
#
# Author: $author$
#   Date: 1/22/2018
#
# QtCreator .pri file for xde library librt
########################################################################

librt_TARGET = rt

########################################################################
librt_INCLUDEPATH += \
$${xde_INCLUDEPATH} \

librt_DEFINES += \
$${xde_DEFINES} \

########################################################################
# xde
librt_HEADERS += \
$${XDE_SRC}/clib/cbase/cbase.hxx \

librt_SOURCES += \
$${XDE_SRC}/clib/cbase/cbase.cxx \

########################################################################
