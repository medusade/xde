#############################################################################
# Copyright (c) 1988-2007 $organization$.
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
# Linux makefile for XDE
#
#############################################################################

PKG = $(PWD)/../../../..
PRJ = projects/linux/gcc
SRC = src

include $(PKG)/$(PRJ)/Makedefines

SRC_DIRS = \
$(PKG)/$(PRJ)/app/cgicatch \
$(PKG)/$(PRJ)/app/cgi \
$(PKG)/$(PRJ)/app/t \
$(PKG)/$(PRJ)/app/tcgi \
$(PKG)/$(PRJ)/app/cxxlcgi \
$(PKG)/$(PRJ)/app/bflex \
$(PKG)/$(PRJ)/app/byacc \

#$(PKG)/$(PRJ)/app/xslcgi \

include $(PKG)/$(PRJ)/Makedirs

install:
	@(echo Installing exes...;\
	  ((mkdir -p $(HOME)/build/xde) || (exit 1));\
	  ((cp -r $(PKGBLD)/bin $(HOME)/build/xde) || (exit 1));\
	  echo ...Installed exes)

