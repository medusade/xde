########################################################################
# Copyright (c) 1988-2017 $organization$
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
#   File: libxdexttp.pri
#
# Author: $author$
#   Date: 12/8/2017
#
# QtCreator .pri file for xde library libxdexttp
########################################################################

libxdexttp_TARGET = xdexttp

########################################################################
libxdexttp_INCLUDEPATH += \
$${xde_INCLUDEPATH} \

libxdexttp_DEFINES += \
$${xde_DEFINES} \

########################################################################
# xde
libxdexttp_HEADERS += \
$${XDE_SRC}/clib/cxttp/chttp.h \
$${XDE_SRC}/clib/cxttp/cxttp.h \
$${XDE_SRC}/clib/cxttp/chttpformfield.hxx \
$${XDE_SRC}/clib/cxttp/chttpformfieldinterface.hxx \
$${XDE_SRC}/clib/cxttp/chttpurlencodedformfieldwriter.hxx \

libxdexttp_SOURCES += \
$${XDE_SRC}/clib/cxttp/http.c \
$${XDE_SRC}/clib/cxttp/xttp.c \
$${XDE_SRC}/clib/cxttp/chttpformfield.cxx \
$${XDE_SRC}/clib/cxttp/chttpformfieldinterface.cxx \
$${XDE_SRC}/clib/cxttp/chttpurlencodedformfieldwriter.cxx \

########################################################################
# xde
libxdexttp_HEADERS += \
$${XDE_SRC}/clib/ccgi/ccgiinterface.hxx \
$${XDE_SRC}/clib/ccgi/ccgienv.hxx \
$${XDE_SRC}/clib/ccgi/ccgi.hxx \
$${XDE_SRC}/clib/ccgi/ccgistream.hxx \
$${XDE_SRC}/clib/ccgi/cfilenamecgi.hxx \
$${XDE_SRC}/clib/ccgi/ctemplatecgi.hxx \
$${XDE_SRC}/clib/ccgi/cdocumenttemplatecgi.hxx \
$${XDE_SRC}/clib/ccgi/ctemplatenamelist.hxx \
$${XDE_SRC}/clib/ccgi/cdocumentnamelist.hxx \
$${XDE_SRC}/clib/ccgi/ctemplatefilenameitems.hxx \
$${XDE_SRC}/clib/ccgi/cdocumentfilenameitems.hxx \

libxdexttp_SOURCES += \
$${XDE_SRC}/clib/ccgi/ccgiinterface.cxx \
$${XDE_SRC}/clib/ccgi/ccgienv.cxx \
$${XDE_SRC}/clib/ccgi/ccgi.cxx \
$${XDE_SRC}/clib/ccgi/ccgistream.cxx \
$${XDE_SRC}/clib/ccgi/cfilenamecgi.cxx \
$${XDE_SRC}/clib/ccgi/ctemplatecgi.cxx \
$${XDE_SRC}/clib/ccgi/cdocumenttemplatecgi.cxx \
$${XDE_SRC}/clib/ccgi/ctemplatenamelist.cxx \
$${XDE_SRC}/clib/ccgi/cdocumentnamelist.cxx \
$${XDE_SRC}/clib/ccgi/ctemplatefilenameitems.cxx \
$${XDE_SRC}/clib/ccgi/cdocumentfilenameitems.cxx \

########################################################################
