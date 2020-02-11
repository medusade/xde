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
#   File: uuid.pri
#
# Author: $author$
#   Date: 11/28/2019
#
# QtCreator .pri file for medusaxde executable uuid
########################################################################

########################################################################
# uuid

# uuid TARGET
#
uuid_TARGET = uuid

# uuid INCLUDEPATH
#
uuid_INCLUDEPATH += \
$${medusaxde_INCLUDEPATH} \

# uuid DEFINES
#
uuid_DEFINES += \
$${medusaxde_DEFINES} \

########################################################################
# uuid OBJECTIVE_HEADERS
#
#uuid_OBJECTIVE_HEADERS += \
#$${MEDUSAXDE_SRC}/medusaxde/base/Base.hh \

# uuid OBJECTIVE_SOURCES
#
#uuid_OBJECTIVE_SOURCES += \
#$${MEDUSAXDE_SRC}/medusaxde/base/Base.mm \

########################################################################
# uuid HEADERS
#
uuid_HEADERS += \
$${MEDUSAXDE_SRC}/clib/cos/cnetwork/cMacAddress.hpp \
$${MEDUSAXDE_SRC}/clib/cos/cnetwork/cUuid.hpp \
\
$${MEDUSAXDE_SRC}/capp/cconsole/cuuid/cUuidMain.hpp \

# uuid SOURCES
#
uuid_SOURCES += \
$${MEDUSAXDE_SRC}/clib/cos/cnetwork/cMacAddress.cpp \
$${MEDUSAXDE_SRC}/clib/cos/cnetwork/cUuid.cpp \
\
$${MEDUSAXDE_SRC}/capp/cconsole/cuuid/cUuidMain.cpp \
$${MEDUSAXDE_SRC}/clib/cos/cMain_main.cpp \

########################################################################
# uuid FRAMEWORKS
#
uuid_FRAMEWORKS += \
$${medusaxde_FRAMEWORKS} \

# uuid LIBS
#
uuid_LIBS += \
$${medusaxde_LIBS} \


