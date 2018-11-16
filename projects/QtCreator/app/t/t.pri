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
#   File: t.pri
#
# Author: $author$
#   Date: 11/14/2018
#
# QtCreator .pri file for xde executable t
########################################################################

########################################################################
# t

# t TARGET
#
t_TARGET = t

# t INCLUDEPATH
#
t_INCLUDEPATH += \
$${xde_INCLUDEPATH} \

# t DEFINES
#
t_DEFINES += \
$${xde_DEFINES} \

########################################################################
# t OBJECTIVE_HEADERS
#
#t_OBJECTIVE_HEADERS += \
#$${XDE_SRC}/xde/base/Base.hh \

# t OBJECTIVE_SOURCES
#
#t_OBJECTIVE_SOURCES += \
#$${XDE_SRC}/xde/base/Base.mm \

########################################################################
# t HEADERS
#
t_HEADERS += \
$${XDE_SRC}/clib/ct/ctmain.hxx \
$${XDE_SRC}/clib/cos/argmain.hxx \

# t SOURCES
#
t_SOURCES += \
$${XDE_SRC}/clib/ct/ctmain.cxx \
$${XDE_SRC}/clib/cos/argmain.cxx \
$${xde_t_function_SOURCES} \

########################################################################
# t FRAMEWORKS
#
t_FRAMEWORKS += \
$${xde_FRAMEWORKS} \

# t LIBS
#
t_LIBS += \
$${xde_LIBS} \


