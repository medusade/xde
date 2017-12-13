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
#   File: Makefile
#
# Author: $author$
#   Date: 12/13/2017
#
# generic Gcc Makefile for xde Library libxde
########################################################################


#
# target
#
libxde_LIBTARGET = libxde.${LIBEXT}

########################################################################

#
# user c++ flags
#
libxde_USRCXXFLAGS += \
${xde_USRCXXFLAGS} 

#
# user defines
#
libxde_USRDEFINES += \
${xde_USRDEFINES} 

#
# user includes
#
libxde_USRINCLUDES += \
${xde_USRINCLUDES} 

#
# user libdirs
#
libxde_USRLIBDIRS += \
${xde_USRLIBDIRS} 

########################################################################

#
# Library .c sources
#
libxde_LIB_C_SOURCES += \
${XDE_SRC}/clib/cos/cplatform/cplatform_stat.c \
${XDE_SRC}/clib/cos/cplatform/cplatform_path.c \
${XDE_SRC}/clib/cos/cplatform/cplatform_file.c \
\
${XDE_SRC}/clib/cos/cplatform/cplatform_ipc.c \
${XDE_SRC}/clib/cos/cplatform/cplatform_msg.c \
${XDE_SRC}/clib/cos/cplatform/cplatform_semaphore.c \
${XDE_SRC}/clib/cos/cplatform/cplatform_mutex.c \
${XDE_SRC}/clib/cos/cplatform/cplatform_thread.c \
\
${XDE_SRC}/clib/cos/cplatform/cplatform_string.c \
${XDE_SRC}/clib/cos/cdebug_printf.c \
\
${XDE_SRC}/clib/cxttp/http.c \
${XDE_SRC}/clib/cxttp/xttp.c 

#
# Library .cc sources
#
#libxde_LIB_CC_SOURCES += \
#${XDE_SRC}/xde/base/Base.cc 

#
# Library .cxx sources
#
libxde_LIB_CXX_SOURCES += \
${XDE_SRC}/clib/cbase/cbase.cxx \
${XDE_SRC}/clib/cbase/ccomparer.cxx \
${XDE_SRC}/clib/cbase/ccounter.cxx \
${XDE_SRC}/clib/cbase/cdigitizer.cxx \
${XDE_SRC}/clib/cbase/cerror.cxx \
${XDE_SRC}/clib/cbase/cinstance.cxx \
${XDE_SRC}/clib/cbase/cinstanceinterface.cxx \
${XDE_SRC}/clib/cbase/cinterface.cxx \
${XDE_SRC}/clib/cbase/cinterfacebase.cxx \
${XDE_SRC}/clib/cbase/cnamevalueeventinterface.cxx \
${XDE_SRC}/clib/cbase/cnamevaluewriter.cxx \
${XDE_SRC}/clib/cbase/cnamevaluewriterinterface.cxx \
${XDE_SRC}/clib/cbase/creference.cxx \
${XDE_SRC}/clib/cbase/creferenced.cxx \
${XDE_SRC}/clib/cbase/csingleinstance.cxx \
${XDE_SRC}/clib/cbase/cvector.cxx \
${XDE_SRC}/clib/cbase/cvectorinterface.cxx \
${XDE_SRC}/clib/cbase/cattached.cxx \
${XDE_SRC}/clib/cbase/cattachedinterface.cxx \
${XDE_SRC}/clib/cbase/cattachinterface.cxx \
${XDE_SRC}/clib/cbase/cbuffer.cxx \
${XDE_SRC}/clib/cbase/cbufferinterface.cxx \
${XDE_SRC}/clib/cbase/cccharstring.cxx \
${XDE_SRC}/clib/cbase/cchar.cxx \
${XDE_SRC}/clib/cbase/ccharinterface.cxx \
${XDE_SRC}/clib/cbase/ccreatedattached.cxx \
${XDE_SRC}/clib/cbase/ccreatedinterface.cxx \
${XDE_SRC}/clib/cbase/cdestroyinterface.cxx \
${XDE_SRC}/clib/cbase/clist.cxx \
${XDE_SRC}/clib/cbase/ccloseinterface.cxx \
${XDE_SRC}/clib/cbase/copened.cxx \
${XDE_SRC}/clib/cbase/copenedinterface.cxx \
${XDE_SRC}/clib/cbase/copeninterface.cxx \
${XDE_SRC}/clib/cbase/cbytestreaminterface.cxx \
${XDE_SRC}/clib/cbase/clookstream.cxx \
${XDE_SRC}/clib/cbase/creader.cxx \
${XDE_SRC}/clib/cbase/creaderinterface.cxx \
${XDE_SRC}/clib/cbase/cstream.cxx \
${XDE_SRC}/clib/cbase/cstreaminterface.cxx \
${XDE_SRC}/clib/cbase/cwriter.cxx \
${XDE_SRC}/clib/cbase/cwriterinterface.cxx \
${XDE_SRC}/clib/cbase/cstring.cxx \
${XDE_SRC}/clib/cbase/cstringbase.cxx \
${XDE_SRC}/clib/cbase/cstringinterface.cxx \
${XDE_SRC}/clib/cbase/cavltree.cxx \
${XDE_SRC}/clib/cbase/cbinarytree.cxx \
${XDE_SRC}/clib/cbase/credblacktree.cxx \
\
${XDE_SRC}/clib/cfs/cfilepatheventinterface.cxx \
${XDE_SRC}/clib/cfs/cfilepathinterface.cxx \
${XDE_SRC}/clib/cfs/ctofilepathwriter.cxx \
${XDE_SRC}/clib/cfs/cfilepath.cxx \
\
${XDE_SRC}/clib/cos/cmessagequeueinterface.cxx \
${XDE_SRC}/clib/cos/cmessagequeue.cxx \
${XDE_SRC}/clib/cos/csemaphoreinterface.cxx \
${XDE_SRC}/clib/cos/csemaphore.cxx \
${XDE_SRC}/clib/cos/cthreadinterface.cxx \
${XDE_SRC}/clib/cos/cthread.cxx \
\
${XDE_SRC}/clib/cos/cfileinterface.cxx \
${XDE_SRC}/clib/cos/cfile.cxx \
${XDE_SRC}/clib/cos/cdebug.cxx \
${XDE_SRC}/clib/cos/cdeviceinterface.cxx \
${XDE_SRC}/clib/cos/cdevice.cxx \
${XDE_SRC}/clib/cos/cmaininterface.cxx \
${XDE_SRC}/clib/cos/cmain.cxx \
${XDE_SRC}/clib/cos/cmainarginterface.cxx \
${XDE_SRC}/clib/cos/cmainarg.cxx \
${XDE_SRC}/clib/cos/cargmain.cxx \
\
${XDE_SRC}/clib/ct/ctvariableinterface.cxx \
${XDE_SRC}/clib/ct/ctvariable.cxx \
${XDE_SRC}/clib/ct/ctvalueinterface.cxx \
${XDE_SRC}/clib/ct/ctvalue.cxx \
${XDE_SRC}/clib/ct/ctfunctioninterface.cxx \
${XDE_SRC}/clib/ct/ctfunctionlist.cxx \
${XDE_SRC}/clib/ct/ctfunctiontree.cxx \
${XDE_SRC}/clib/ct/ctfunction.cxx \
${XDE_SRC}/clib/ct/ctfunctionparameter.cxx \
${XDE_SRC}/clib/ct/ctfunctionargument.cxx \
${XDE_SRC}/clib/ct/ctinterface.cxx \
${XDE_SRC}/clib/ct/ct.cxx \
\
${XDE_SRC}/clib/cxttp/chttpformfield.cxx \
${XDE_SRC}/clib/cxttp/chttpformfieldinterface.cxx \
${XDE_SRC}/clib/cxttp/chttpurlencodedformfieldwriter.cxx \
\
${XDE_SRC}/clib/ccgi/ccgiinterface.cxx \
${XDE_SRC}/clib/ccgi/ccgienv.cxx \
${XDE_SRC}/clib/ccgi/ccgi.cxx \
${XDE_SRC}/clib/ccgi/ccgistream.cxx \
${XDE_SRC}/clib/ccgi/cfilenamecgi.cxx \
${XDE_SRC}/clib/ccgi/ctemplatecgi.cxx \
${XDE_SRC}/clib/ccgi/cdocumenttemplatecgi.cxx \
${XDE_SRC}/clib/ccgi/ctemplatenamelist.cxx \
${XDE_SRC}/clib/ccgi/cdocumentnamelist.cxx \
${XDE_SRC}/clib/ccgi/ctemplatefilenameitems.cxx \
${XDE_SRC}/clib/ccgi/cdocumentfilenameitems.cxx \
\
${XDE_SRC}/clib/cyy/clexercgi.cxx \
${XDE_SRC}/clib/cyy/clexercgilex.cxx \
${XDE_SRC}/clib/cyy/clexersource.cxx \
${XDE_SRC}/clib/cyy/clexertoken.cxx \
${XDE_SRC}/clib/cyy/cyylexer.cxx 

#
# Library .cpp sources
#
#libxde_LIB_CPP_SOURCES += \
#${XDE_SRC}/xde/base/Base.cpp 

#
# Library .m sources
#
#libxde_LIB_M_SOURCES += \
#${XDE_SRC}/xde/base/Base.m 

#
# Library .mm sources
#
#libxde_LIB_MM_SOURCES += \
#${XDE_SRC}/xde/base/Base.mm 


########################################################################




