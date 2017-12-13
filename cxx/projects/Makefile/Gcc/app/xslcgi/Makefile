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
# generic Gcc Makefile for xde Executable xslcgi
########################################################################


#
# target
#
xslcgi_EXETARGET = xde-xslcgi

########################################################################

#
# user c++ flags
#
xslcgi_USRCXXFLAGS += \
${xde_USRCXXFLAGS} 

#
# user defines
#
xslcgi_USRDEFINES += \
${xde_USRDEFINES} 

#
# user includes
#
xslcgi_USRINCLUDES += \
${xde_USRINCLUDES} 

#
# user libdirs
#
xslcgi_USRLIBDIRS += \
${xde_USRLIBDIRS} \
${build_libxslt_USRLIBDIRS} 

########################################################################

#
# Executable .c sources
#
#xslcgi_EXE_C_SOURCES += \
#${XDE_SRC}/xde/base/Base.c \

#
# Executable .cc sources
#
#xslcgi_EXE_CC_SOURCES += \
#${XDE_SRC}/xde/base/Base.cc \

#
# Executable .cxx sources
#
xslcgi_EXE_CXX_SOURCES += \
${XDE_CPP_SRC}/clib/cxml/cxslt/cXslTransformer.cxx \
${XDE_SRC}/clib/cxsl/cxsltransformerinterface.cxx \
${XDE_SRC}/clib/cxsl/cxmlreaderinterface.cxx \
${XDE_SRC}/clib/cxsl/cxmlnodeinterface.cxx \
${XDE_SRC}/clib/cxsl/cxmlnodetype.cxx \
${XDE_SRC}/capp/ccgi/xslcgi/cxslcgi.cxx \
${XDE_SRC}/clib/ccgi/cgi.cxx

#
# Executable .cpp sources
#
xslcgi_EXE_CPP_SOURCES += \
${XDE_CPP_SRC}/clib/clibc/clibxml2/clibxslt/cLibXsltXsltProcessorImplemented.cpp \
${XDE_CPP_SRC}/clib/clibc/clibxml2/clibxslt/cLibXsltXsltProcessor.cpp \
${XDE_CPP_SRC}/clib/clibc/clibxml2/clibxslt/cLibXsltXsltProcessorInterface.cpp \
${XDE_CPP_SRC}/clib/clibc/clibxml2/clibxslt/cLibXsltXsltParams.cpp \
${XDE_CPP_SRC}/clib/cxml/cxslt/cXsltProcessor.cpp \
${XDE_CPP_SRC}/clib/cxml/cxslt/cXsltProcessorInterface.cpp \
${XDE_CPP_SRC}/clib/cxml/cxslt/cXsltParams.cpp \
${XDE_CPP_SRC}/clib/cxml/cxslt/cXsltParamsInterface.cpp \
${XDE_CPP_SRC}/clib/cxml/cxslt/cXsltParam.cpp \
${XDE_CPP_SRC}/clib/cxml/cxslt/cXsltParamInterface.cpp \
${XDE_CPP_SRC}/clib/cxml/cXmlAttributeEncoder.cpp \
${XDE_CPP_SRC}/clib/cxml/cXmlTextEncoder.cpp \
${XDE_CPP_SRC}/clib/cos/cDebugInstance.cpp \
${XDE_CPP_SRC}/clib/cos/cDebug.cpp \
${XDE_CPP_SRC}/clib/cos/cDebugInterface.cpp \
${XDE_CPP_SRC}/clib/cbase/cBase.cpp \
${XDE_SRC}/clib/cos/cplatform/cplatform.cpp \
${XDE_SRC}/clib/cos/cplatform/cnamespace.cpp

#
# Executable .m sources
#
#xslcgi_EXE_M_SOURCES += \
#${XDE_SRC}/xde/base/Base.m \

#
# Executable .mm sources
#
#xslcgi_EXE_MM_SOURCES += \
#${XDE_SRC}/xde/base/Base.mm \


########################################################################

#
# Executable libraries
#
xslcgi_LIBS += \
${xde_LIBS} \
${build_libxslt_LIBS}

