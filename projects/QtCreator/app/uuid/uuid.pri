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
$${xos_INCLUDEPATH} \
$${xde_INCLUDEPATH} \
$${medusade_INCLUDEPATH} \

# uuid DEFINES
#
uuid_DEFINES += \
$${medusade_DEFINES} \
$${xde_DEFINES} \
$${xos_DEFINES} \

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
$${xde_crypto_HEADERS} \
$${MEDUSADE_SRC}/cifra/network/ethernet/address.hpp \
$${MEDUSADE_SRC}/cifra/network/ethernet/actual/address.hpp \
$${MEDUSADE_SRC}/cifra/network/ethernet/posix/address.hpp \
$${MEDUSADE_SRC}/cifra/network/ethernet/apple/osx/address.hpp \
$${MEDUSADE_SRC}/cifra/network/ethernet/microsoft/windows/address.hpp \
$${MEDUSADE_SRC}/cifra/network/ethernet/os/address.hpp \
$${MEDUSADE_SRC}/cifra/universal/unique/identifier.hpp \
$${MEDUSADE_SRC}/cifra/universal/unique/posix/identifier.hpp \
$${MEDUSADE_SRC}/cifra/universal/unique/apple/osx/identifier.hpp \
$${MEDUSADE_SRC}/cifra/universal/unique/microsoft/windows/identifier.hpp \
$${MEDUSADE_SRC}/cifra/universal/unique/os/identifier.hpp \
$${XDE_SRC}/clib/cos/argmain.hxx \
$${XDE_SRC}/capp/cnetwork/uuid/cuuidmain.hxx \

# uuid SOURCES
#
uuid_SOURCES += \
$${xde_crypto_SOURCES} \
$${XDE_SRC}/clib/cos/argmain.cxx \
$${XDE_SRC}/capp/cnetwork/uuid/cuuidmain.cxx \

########################################################################
# uuid FRAMEWORKS
#
uuid_FRAMEWORKS += \
$${xos_FRAMEWORKS} \
$${xde_FRAMEWORKS} \
$${medusaxde_FRAMEWORKS} \

# uuid LIBS
#
uuid_LIBS += \
$${xos_LIBS} \
$${xde_LIBS} \
$${medusade_LIBS} \


