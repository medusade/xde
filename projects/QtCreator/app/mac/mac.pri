########################################################################
# Copyright (c) 1988-2019 $organization$
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
#   File: mac.pri
#
# Author: $author$
#   Date: 12/16/2019
#
# generic QtCreator project for medusaxde executable mac
########################################################################

########################################################################
# mac

# mac TARGET
#
mac_TARGET = mac

# mac INCLUDEPATH
#
mac_INCLUDEPATH += \
$${medusaxde_INCLUDEPATH} \

# mac DEFINES
#
mac_DEFINES += \
$${medusaxde_DEFINES} \

########################################################################
# mac OBJECTIVE_HEADERS
#
#mac_OBJECTIVE_HEADERS += \
#$${MEDUSAXDE_SRC}/medusaxde/base/base.hh \

# mac OBJECTIVE_SOURCES
#
#mac_OBJECTIVE_SOURCES += \
#$${MEDUSAXDE_SRC}/medusaxde/base/base.mm \

########################################################################
# mac HEADERS
#
mac_HEADERS += \
$${MEDUSAXDE_SRC}/clib/cos/cnetwork/cMacAddress.hpp \
$${MEDUSAXDE_SRC}/clib/cos/cnetwork/cMacAddressString.hpp \
\
$${MEDUSAXDE_SRC}/capp/cconsole/cmac/cMacAddressMain.hpp \

# mac SOURCES
#
mac_SOURCES += \
$${MEDUSAXDE_SRC}/clib/cos/cnetwork/cMacAddressString.cpp \
$${MEDUSAXDE_SRC}/clib/cos/cnetwork/cMacAddress.cpp \
\
$${MEDUSAXDE_SRC}/clib/cos/cMain_main.cpp \
\
$${MEDUSAXDE_SRC}/capp/cconsole/cmac/cMacAddressMain.cpp \

########################################################################
# mac FRAMEWORKS
#
mac_FRAMEWORKS += \
$${medusaxde_FRAMEWORKS} \

# mac LIBS
#
mac_LIBS += \
$${medusaxde_LIBS} \


