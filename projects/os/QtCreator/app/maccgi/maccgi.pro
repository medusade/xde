########################################################################
# Copyright (c) 1988-2020 $organization$
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
#   File: maccgi.pro
#
# Author: $author$
#   Date: 3/2/2020
#
# QtCreator .pro file for xde executable maccgi
########################################################################
include(../../../../../build/QtCreator/xde.pri)
include(../../../../QtCreator/xde.pri)
include(../../xde.pri)
include(../../../../QtCreator/app/maccgi/maccgi.pri)

TARGET = $${maccgi_TARGET}

########################################################################
# INCLUDEPATH
#
INCLUDEPATH += \
$${maccgi_INCLUDEPATH} \

# DEFINES
# 
DEFINES += \
$${maccgi_DEFINES} \

########################################################################
# OBJECTIVE_HEADERS
#
OBJECTIVE_HEADERS += \
$${maccgi_OBJECTIVE_HEADERS} \

# OBJECTIVE_SOURCES
#
OBJECTIVE_SOURCES += \
$${maccgi_OBJECTIVE_SOURCES} \

########################################################################
# HEADERS
#
HEADERS += \
$${maccgi_HEADERS} \
$${OBJECTIVE_HEADERS} \

# SOURCES
#
SOURCES += \
$${maccgi_SOURCES} \

########################################################################
# FRAMEWORKS
#
FRAMEWORKS += \
$${maccgi_FRAMEWORKS} \

# LIBS
#
LIBS += \
$${maccgi_LIBS} \
$${FRAMEWORKS} \


