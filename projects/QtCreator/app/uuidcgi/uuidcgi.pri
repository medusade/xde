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
#   File: uuidcgi.pri
#
# Author: $author$
#   Date: 3/2/2020
#
# QtCreator .pri file for xde executable uuidcgi
########################################################################

########################################################################
# uuidcgi

# uuidcgi TARGET
#
uuidcgi_TARGET = uuidcgi

# uuidcgi INCLUDEPATH
#
uuidcgi_INCLUDEPATH += \
$${xde_INCLUDEPATH} \
$${medusade_INCLUDEPATH} \

# uuidcgi DEFINES
#
uuidcgi_DEFINES += \
$${xde_DEFINES} \

########################################################################
# uuidcgi OBJECTIVE_HEADERS
#
#uuidcgi_OBJECTIVE_HEADERS += \
#$${XDE_SRC}/xde/base/Base.hh \

# uuidcgi OBJECTIVE_SOURCES
#
#uuidcgi_OBJECTIVE_SOURCES += \
#$${XDE_SRC}/xde/base/Base.mm \

########################################################################
# uuidcgi HEADERS
#
uuidcgi_HEADERS += \
$${xde_crypto_HEADERS} \
$${XDE_SRC}/capp/ccgi/uuidcgi/cuuidcgi.hxx \
$${XDE_SRC}/clib/ccgi/cgi.hxx \

# uuidcgi SOURCES
#
uuidcgi_SOURCES += \
$${xde_crypto_SOURCES} \
$${XDE_SRC}/capp/ccgi/uuidcgi/cuuidcgi.cxx \
$${XDE_SRC}/clib/ccgi/cgi.cxx \

########################################################################
# uuidcgi FRAMEWORKS
#
uuidcgi_FRAMEWORKS += \
$${xde_FRAMEWORKS} \

# uuidcgi LIBS
#
uuidcgi_LIBS += \
$${xde_LIBS} \


