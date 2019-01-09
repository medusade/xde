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
#   File: uuidcgi.pri
#
# Author: $author$
#   Date: 11/26/2018
#
# QtCreator .pri file for medusaxde executable uuidcgi
########################################################################

########################################################################
# uuidcgi

# uuidcgi TARGET
#
uuidcgi_TARGET = uuidcgi

# uuidcgi INCLUDEPATH
#
uuidcgi_INCLUDEPATH += \
$${medusaxde_INCLUDEPATH} \

# uuidcgi DEFINES
#
uuidcgi_DEFINES += \
$${medusaxde_DEFINES} \

########################################################################
# uuidcgi OBJECTIVE_HEADERS
#
#uuidcgi_OBJECTIVE_HEADERS += \
#$${MEDUSAXDE_SRC}/medusaxde/base/Base.hh \

# uuidcgi OBJECTIVE_SOURCES
#
#uuidcgi_OBJECTIVE_SOURCES += \
#$${MEDUSAXDE_SRC}/medusaxde/base/Base.mm \

########################################################################
# uuidcgi HEADERS
#
uuidcgi_HEADERS += \
$${MEDUSAXDE_SRC}/capp/ccgi/cuuidcgi/cUuidCgi.hpp \
\
$${MEDUSAXDE_SRC}/clib/cos/cnetwork/cMacAddress.hpp \
$${MEDUSAXDE_SRC}/clib/cos/cnetwork/cUuid.hpp \
$${XDE_SRC}/clib/ccgi/cgi.hxx \

# uuidcgi SOURCES
#
uuidcgi_SOURCES += \
$${MEDUSAXDE_SRC}/clib/cos/cnetwork/cMacAddress.cpp \
$${MEDUSAXDE_SRC}/clib/cos/cnetwork/cUuid.cpp \
$${XDE_SRC}/clib/ccgi/cgi.cxx \

########################################################################
# uuidcgi FRAMEWORKS
#
uuidcgi_FRAMEWORKS += \
$${medusaxde_FRAMEWORKS} \

# uuidcgi LIBS
#
uuidcgi_LIBS += \
$${medusaxde_LIBS} \
$${xde_LIBS} \


