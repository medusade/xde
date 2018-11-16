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
#   File: cxxlcgi.pri
#
# Author: $author$
#   Date: 11/14/2018
#
# QtCreator .pri file for xde executable cxxlcgi
########################################################################

########################################################################
# cxxlcgi

# cxxlcgi TARGET
#
cxxlcgi_TARGET = cxxlcgi

# cxxlcgi INCLUDEPATH
#
cxxlcgi_INCLUDEPATH += \
$${xde_INCLUDEPATH} \

# cxxlcgi DEFINES
#
cxxlcgi_DEFINES += \
$${xde_DEFINES} \

########################################################################
# cxxlcgi OBJECTIVE_HEADERS
#
#cxxlcgi_OBJECTIVE_HEADERS += \
#$${XDE_SRC}/xde/base/Base.hh \

# cxxlcgi OBJECTIVE_SOURCES
#
#cxxlcgi_OBJECTIVE_SOURCES += \
#$${XDE_SRC}/xde/base/Base.mm \

########################################################################
# cxxlcgi HEADERS
#
cxxlcgi_HEADERS += \
$${XDE_SRC}/capp/ccgi/cxxlcgi/ccxxlcgi.hxx \
$${XDE_SRC}/capp/ccgi/cxxlcgi/ccxxlex.hxx \
$${XDE_SRC}/capp/ccgi/cxxlcgi/ccxxlexer.hxx \
$${XDE_SRC}/clib/ccgi/cgi.hxx \

# cxxlcgi SOURCES
#
cxxlcgi_SOURCES += \
$${XDE_SRC}/capp/ccgi/cxxlcgi/ccxxlcgi.cxx \
$${XDE_SRC}/capp/ccgi/cxxlcgi/ccxxlex.cxx \
$${XDE_SRC}/capp/ccgi/cxxlcgi/ccxxlexer.cxx \
$${XDE_SRC}/clib/ccgi/cgi.cxx \
$${xde_t_function_SOURCES} \

########################################################################
# cxxlcgi FRAMEWORKS
#
cxxlcgi_FRAMEWORKS += \
$${xde_FRAMEWORKS} \

# cxxlcgi LIBS
#
cxxlcgi_LIBS += \
$${xde_LIBS} \


