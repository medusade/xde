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
#   File: libxde.pri
#
# Author: $author$
#   Date: 12/8/2017
#
# QtCreator .pri file for xde library libxde
########################################################################

libxde_TARGET = xde

########################################################################
libxde_INCLUDEPATH += \
$${xde_INCLUDEPATH} \

libxde_DEFINES += \
$${xde_DEFINES} \

########################################################################
# xde
libxde_HEADERS += \
$${XDE_SRC}/clib/cbase/cbase.hxx \
$${XDE_SRC}/clib/cbase/ccomparer.hxx \
$${XDE_SRC}/clib/cbase/ccounter.hxx \
$${XDE_SRC}/clib/cbase/cdigitizer.hxx \
$${XDE_SRC}/clib/cbase/cerror.hxx \
$${XDE_SRC}/clib/cbase/cinstance.hxx \
$${XDE_SRC}/clib/cbase/cinstanceinterface.hxx \
$${XDE_SRC}/clib/cbase/cinterface.hxx \
$${XDE_SRC}/clib/cbase/cinterfacebase.hxx \
$${XDE_SRC}/clib/cbase/cnamevalueeventinterface.hxx \
$${XDE_SRC}/clib/cbase/cnamevaluewriter.hxx \
$${XDE_SRC}/clib/cbase/cnamevaluewriterinterface.hxx \
$${XDE_SRC}/clib/cbase/creference.hxx \
$${XDE_SRC}/clib/cbase/creferenced.hxx \
$${XDE_SRC}/clib/cbase/csingleinstance.hxx \
$${XDE_SRC}/clib/cbase/cvector.hxx \
$${XDE_SRC}/clib/cbase/cvectorinterface.hxx \
$${XDE_SRC}/clib/cbase/cattached.hxx \
$${XDE_SRC}/clib/cbase/cattachedinterface.hxx \
$${XDE_SRC}/clib/cbase/cattachinterface.hxx \
$${XDE_SRC}/clib/cbase/cbuffer.hxx \
$${XDE_SRC}/clib/cbase/cbufferinterface.hxx \
$${XDE_SRC}/clib/cbase/cccharstring.hxx \
$${XDE_SRC}/clib/cbase/cchar.hxx \
$${XDE_SRC}/clib/cbase/ccharinterface.hxx \
$${XDE_SRC}/clib/cbase/ccreatedattached.hxx \
$${XDE_SRC}/clib/cbase/ccreatedinterface.hxx \
$${XDE_SRC}/clib/cbase/cdestroyinterface.hxx \
$${XDE_SRC}/clib/cbase/clist.hxx \
$${XDE_SRC}/clib/cbase/ccloseinterface.hxx \
$${XDE_SRC}/clib/cbase/copened.hxx \
$${XDE_SRC}/clib/cbase/copenedinterface.hxx \
$${XDE_SRC}/clib/cbase/copeninterface.hxx \
$${XDE_SRC}/clib/cbase/cbytestreaminterface.hxx \
$${XDE_SRC}/clib/cbase/clookstream.hxx \
$${XDE_SRC}/clib/cbase/creader.hxx \
$${XDE_SRC}/clib/cbase/creaderinterface.hxx \
$${XDE_SRC}/clib/cbase/cstream.hxx \
$${XDE_SRC}/clib/cbase/cstreaminterface.hxx \
$${XDE_SRC}/clib/cbase/cwriter.hxx \
$${XDE_SRC}/clib/cbase/cwriterinterface.hxx \
$${XDE_SRC}/clib/cbase/cstring.hxx \
$${XDE_SRC}/clib/cbase/cstringbase.hxx \
$${XDE_SRC}/clib/cbase/cstringinterface.hxx \
$${XDE_SRC}/clib/cbase/cavltree.hxx \
$${XDE_SRC}/clib/cbase/cbinarytree.hxx \
$${XDE_SRC}/clib/cbase/credblacktree.hxx \

libxde_SOURCES += \
$${XDE_SRC}/clib/cbase/cbase.cxx \
$${XDE_SRC}/clib/cbase/ccomparer.cxx \
$${XDE_SRC}/clib/cbase/ccounter.cxx \
$${XDE_SRC}/clib/cbase/cdigitizer.cxx \
$${XDE_SRC}/clib/cbase/cerror.cxx \
$${XDE_SRC}/clib/cbase/cinstance.cxx \
$${XDE_SRC}/clib/cbase/cinstanceinterface.cxx \
$${XDE_SRC}/clib/cbase/cinterface.cxx \
$${XDE_SRC}/clib/cbase/cinterfacebase.cxx \
$${XDE_SRC}/clib/cbase/cnamevalueeventinterface.cxx \
$${XDE_SRC}/clib/cbase/cnamevaluewriter.cxx \
$${XDE_SRC}/clib/cbase/cnamevaluewriterinterface.cxx \
$${XDE_SRC}/clib/cbase/creference.cxx \
$${XDE_SRC}/clib/cbase/creferenced.cxx \
$${XDE_SRC}/clib/cbase/csingleinstance.cxx \
$${XDE_SRC}/clib/cbase/cvector.cxx \
$${XDE_SRC}/clib/cbase/cvectorinterface.cxx \
$${XDE_SRC}/clib/cbase/cattached.cxx \
$${XDE_SRC}/clib/cbase/cattachedinterface.cxx \
$${XDE_SRC}/clib/cbase/cattachinterface.cxx \
$${XDE_SRC}/clib/cbase/cbuffer.cxx \
$${XDE_SRC}/clib/cbase/cbufferinterface.cxx \
$${XDE_SRC}/clib/cbase/cccharstring.cxx \
$${XDE_SRC}/clib/cbase/cchar.cxx \
$${XDE_SRC}/clib/cbase/ccharinterface.cxx \
$${XDE_SRC}/clib/cbase/ccreatedattached.cxx \
$${XDE_SRC}/clib/cbase/ccreatedinterface.cxx \
$${XDE_SRC}/clib/cbase/cdestroyinterface.cxx \
$${XDE_SRC}/clib/cbase/clist.cxx \
$${XDE_SRC}/clib/cbase/ccloseinterface.cxx \
$${XDE_SRC}/clib/cbase/copened.cxx \
$${XDE_SRC}/clib/cbase/copenedinterface.cxx \
$${XDE_SRC}/clib/cbase/copeninterface.cxx \
$${XDE_SRC}/clib/cbase/cbytestreaminterface.cxx \
$${XDE_SRC}/clib/cbase/clookstream.cxx \
$${XDE_SRC}/clib/cbase/creader.cxx \
$${XDE_SRC}/clib/cbase/creaderinterface.cxx \
$${XDE_SRC}/clib/cbase/cstream.cxx \
$${XDE_SRC}/clib/cbase/cstreaminterface.cxx \
$${XDE_SRC}/clib/cbase/cwriter.cxx \
$${XDE_SRC}/clib/cbase/cwriterinterface.cxx \
$${XDE_SRC}/clib/cbase/cstring.cxx \
$${XDE_SRC}/clib/cbase/cstringbase.cxx \
$${XDE_SRC}/clib/cbase/cstringinterface.cxx \
$${XDE_SRC}/clib/cbase/cavltree.cxx \
$${XDE_SRC}/clib/cbase/cbinarytree.cxx \
$${XDE_SRC}/clib/cbase/credblacktree.cxx \

########################################################################
# xde
libxde_HEADERS += \
$${XDE_SRC}/clib/cos/cplatform/cplatform_stat.h \
$${XDE_SRC}/clib/cos/cplatform/cplatform_path.h \
$${XDE_SRC}/clib/cos/cplatform/cplatform_file.h \

libxde_SOURCES += \
$${XDE_SRC}/clib/cos/cplatform/cplatform_stat.c \
$${XDE_SRC}/clib/cos/cplatform/cplatform_path.c \
$${XDE_SRC}/clib/cos/cplatform/cplatform_file.c \

########################################################################
# xde
libxde_HEADERS += \
$${XDE_SRC}/clib/cfs/cfilepatheventinterface.hxx \
$${XDE_SRC}/clib/cfs/cfilepathinterface.hxx \
$${XDE_SRC}/clib/cfs/ctofilepathwriter.hxx \
$${XDE_SRC}/clib/cfs/cfilepath.hxx \

libxde_SOURCES += \
$${XDE_SRC}/clib/cfs/cfilepatheventinterface.cxx \
$${XDE_SRC}/clib/cfs/cfilepathinterface.cxx \
$${XDE_SRC}/clib/cfs/ctofilepathwriter.cxx \
$${XDE_SRC}/clib/cfs/cfilepath.cxx \

########################################################################
# xde
libxde_HEADERS += \
$${XDE_SRC}/clib/cos/cplatform/cplatform_ipc.h \
$${XDE_SRC}/clib/cos/cplatform/cplatform_msg.h \
$${XDE_SRC}/clib/cos/cplatform/cplatform_semaphore.h \
$${XDE_SRC}/clib/cos/cplatform/cplatform_mutex.h \
$${XDE_SRC}/clib/cos/cplatform/cplatform_thread.h \

libxde_SOURCES += \
$${XDE_SRC}/clib/cos/cplatform/cplatform_ipc.c \
$${XDE_SRC}/clib/cos/cplatform/cplatform_msg.c \
$${XDE_SRC}/clib/cos/cplatform/cplatform_semaphore.c \
$${XDE_SRC}/clib/cos/cplatform/cplatform_mutex.c \
$${XDE_SRC}/clib/cos/cplatform/cplatform_thread.c \

########################################################################
# xde
libxde_HEADERS += \
$${XDE_SRC}/clib/cos/cmessagequeueinterface.hxx \
$${XDE_SRC}/clib/cos/cmessagequeue.hxx \
$${XDE_SRC}/clib/cos/csemaphoreinterface.hxx \
$${XDE_SRC}/clib/cos/csemaphore.hxx \
$${XDE_SRC}/clib/cos/cthreadinterface.hxx \
$${XDE_SRC}/clib/cos/cthread.hxx \

libxde_SOURCES += \
$${XDE_SRC}/clib/cos/cmessagequeueinterface.cxx \
$${XDE_SRC}/clib/cos/cmessagequeue.cxx \
$${XDE_SRC}/clib/cos/csemaphoreinterface.cxx \
$${XDE_SRC}/clib/cos/csemaphore.cxx \
$${XDE_SRC}/clib/cos/cthreadinterface.cxx \
$${XDE_SRC}/clib/cos/cthread.cxx \

########################################################################
# xde
libxde_HEADERS += \
$${XDE_SRC}/clib/cos/cplatform/cplatform_string.h \
$${XDE_SRC}/clib/cos/cdebug_printf.h \

libxde_SOURCES += \
$${XDE_SRC}/clib/cos/cplatform/cplatform_string.c \
$${XDE_SRC}/clib/cos/cdebug_printf.c \

########################################################################
# xde
libxde_HEADERS += \
$${XDE_SRC}/clib/cos/cfileinterface.hxx \
$${XDE_SRC}/clib/cos/cfile.hxx \
$${XDE_SRC}/clib/cos/cdebug.hxx \
$${XDE_SRC}/clib/cos/cdeviceinterface.hxx \
$${XDE_SRC}/clib/cos/cdevice.hxx \
$${XDE_SRC}/clib/cos/cmaininterface.hxx \
$${XDE_SRC}/clib/cos/cmain.hxx \
$${XDE_SRC}/clib/cos/cmainarginterface.hxx \
$${XDE_SRC}/clib/cos/cmainarg.hxx \
$${XDE_SRC}/clib/cos/cargmain.hxx \

libxde_SOURCES += \
$${XDE_SRC}/clib/cos/cfileinterface.cxx \
$${XDE_SRC}/clib/cos/cfile.cxx \
$${XDE_SRC}/clib/cos/cdebug.cxx \
$${XDE_SRC}/clib/cos/cdeviceinterface.cxx \
$${XDE_SRC}/clib/cos/cdevice.cxx \
$${XDE_SRC}/clib/cos/cmaininterface.cxx \
$${XDE_SRC}/clib/cos/cmain.cxx \
$${XDE_SRC}/clib/cos/cmainarginterface.cxx \
$${XDE_SRC}/clib/cos/cmainarg.cxx \
$${XDE_SRC}/clib/cos/cargmain.cxx \

########################################################################
