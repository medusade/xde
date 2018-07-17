#############################################################################
# Copyright (c) 1988-2009 $organization$
#
# This software is provided by the author and contributors ``as is'' and
# any express or implied warranties, including, but not limited to, the
# implied warranties of merchantability and fitness for a particular purpose
# are disclaimed.  In no event shall the author or contributors be liable
# for any direct, indirect, incidental, special, exemplary, or consequential
# damages (including, but not limited to, procurement of substitute goods
# or services; loss of use, data, or profits; or business interruption)
# however caused and on any theory of liability, whether in contract, strict
# liability, or tort (including negligence or otherwise) arising in any way
# out of the use of this software, even if advised of the possibility of
# such damage.
#
#   File: Makefile
#
# Author: $author$
#   Date: 7/31/2009
#
# MaxOSX makefile for XDE adalcgi executable
#
#############################################################################

PKG = ../../../../..
BLD = build/macosx
PRJ = projects/macosx/gcc
SRC = src

include $(PKG)/$(PRJ)/Makedefines

#
# user includes
#
USRINCLUDES = \
-I$(PKG)/$(SRC)/clib/cfs \
-I$(PKG)/$(SRC)/clib/cyy \
-I$(PKG)/$(SRC)/clib/ccgi \
-I$(PKG)/$(SRC)/clib/cxttp \
-I$(PKG)/$(SRC)/clib/cos/cunix \
-I$(PKG)/$(SRC)/clib/cos/cplatform \
-I$(PKG)/$(SRC)/clib/cos \
-I$(PKG)/$(SRC)/clib/cbase \

#
# targets
#
EXETARGET = adalcgi

#
# executable C sources
#
EXE_C_SOURCES = \

#
# executable C++ .cxx sources
#
EXE_CXX_SOURCES = \
$(PKG)/$(SRC)/capp/ccgi/adalcgi/cadalex.cxx \
$(PKG)/$(SRC)/capp/ccgi/adalcgi/cadalexer.cxx \
$(PKG)/$(SRC)/capp/ccgi/adalcgi/cadacgi.cxx \
$(PKG)/$(SRC)/clib/ccgi/cgi.cxx \
$(PKG)/$(SRC)/clib/ccgi/ctemplatenamelist.cxx \
$(PKG)/$(SRC)/clib/ccgi/cdocumentnamelist.cxx \
$(PKG)/$(SRC)/clib/ccgi/ctemplatefilenameitems.cxx \
$(PKG)/$(SRC)/clib/ccgi/cdocumentfilenameitems.cxx \
$(PKG)/$(SRC)/clib/cyy/clexercgilex.cxx \
$(PKG)/$(SRC)/clib/cyy/clexersource.cxx \
$(PKG)/$(SRC)/clib/cyy/clexertoken.cxx \
$(PKG)/$(SRC)/clib/cyy/cyylexer.cxx \

#
# executable libs
#
LIBS = \
-lccgi \
-lcxttp \
-lcos \

EXEINSTALL = $(EXETARGET)-install

include $(PKG)/$(PRJ)/Makerules
