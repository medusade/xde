########################################################################
# Copyright (c) 1988-2015 $organization$
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
#   File: libccgi.pro
#
# Author: $author$
#   Date: 1/20/2015
########################################################################
include(../../../../QtCreator/xde.pri)
include(../../../../QtCreator/lib/libcxttp/libcxttp.pri)
include(../../../../QtCreator/lib/libccgi/libccgi.pri)

TARGET = ccgi

TEMPLATE = lib
CONFIG += staticlib

INCLUDEPATH += \
$${xde_INCLUDEPATH} \

DEFINES += \
$${xde_DEFINES} \

HEADERS += \
$${libcxttp_HEADERS} \
$${libccgi_HEADERS} \

SOURCES += \
$${libcxttp_SOURCES} \
$${libccgi_SOURCES} \
