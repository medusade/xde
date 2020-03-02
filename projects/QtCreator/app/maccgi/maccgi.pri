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
#   File: maccgi.pri
#
# Author: $author$
#   Date: 3/2/2020
#
# QtCreator .pri file for xde executable maccgi
########################################################################

########################################################################
# maccgi

# maccgi TARGET
#
maccgi_TARGET = maccgi

# maccgi INCLUDEPATH
#
maccgi_INCLUDEPATH += \
$${xde_INCLUDEPATH} \
$${medusade_INCLUDEPATH} \

# maccgi DEFINES
#
maccgi_DEFINES += \
$${xde_DEFINES} \

########################################################################
# maccgi OBJECTIVE_HEADERS
#
#maccgi_OBJECTIVE_HEADERS += \
#$${XDE_SRC}/xde/base/Base.hh \

# maccgi OBJECTIVE_SOURCES
#
#maccgi_OBJECTIVE_SOURCES += \
#$${XDE_SRC}/xde/base/Base.mm \

########################################################################
# maccgi HEADERS
#
maccgi_HEADERS += \
$${xde_crypto_HEADERS} \
$${XDE_SRC}/clib/ccgi/cgi.hxx \
$${XDE_SRC}/capp/ccgi/maccgi/cmaccgi.hxx \

# maccgi SOURCES
#
maccgi_SOURCES += \
$${xde_crypto_SOURCES} \
$${XDE_SRC}/clib/ccgi/cgi.cxx \
$${XDE_SRC}/capp/ccgi/maccgi/cmaccgi.cxx \

########################################################################
# maccgi FRAMEWORKS
#
maccgi_FRAMEWORKS += \
$${xde_FRAMEWORKS} \

# maccgi LIBS
#
maccgi_LIBS += \
$${xde_LIBS} \


