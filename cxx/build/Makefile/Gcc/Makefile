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
# build Gcc Makefile for xde
########################################################################


########################################################################
# libxml2
#
# pkg-config --cflags --libs libxml2
#
build_libxml2_USRDEFINES += \

build_libxml2_USRINCLUDES += \
-I${HOME}/build/libxml2/include/libxml2 

build_libxml2_USRCXXFLAGS += \

build_libxml2_USRLIBDIRS += \
-L${HOME}/build/libxml2/lib 

build_libxml2_LIBS += \
-lxml2 


########################################################################
# libxslt
#
# pkg-config --cflags --libs libxslt
#
build_libxslt_USRDEFINES += \
${build_libxml2_USRDEFINES} 

build_libxslt_USRINCLUDES += \
-I${HOME}/build/libxslt/include \
${build_libxml2_USRINCLUDES} 

build_libxslt_USRCXXFLAGS += \
${build_libxml2_USRCXXFLAGS} 

build_libxslt_USRLIBDIRS += \
-L${HOME}/build/libxslt/lib \
${build_libxml2_USRLIBDIRS} 

build_libxslt_LIBS += \
-lxslt \
-lexslt \
${build_libxml2_LIBS} 

########################################################################
# rostra
#
# pkg-config --cflags --libs rostra
#
build_rostra_USRDEFINES += \

build_rostra_USRINCLUDES += \

build_rostra_USRCXXFLAGS += \

build_rostra_USRLIBDIRS += \

build_rostra_LIBS += \


########################################################################
# xde
build_xde_USRDEFINES += \
${build_libxslt_USRDEFINES} \
${build_rostra_USRDEFINES} 


build_xde_USRINCLUDES += \
${build_rostra_USRINCLUDES} \
${build_libxslt_USRINCLUDES} 


build_xde_USRCXXFLAGS += \
${build_libxslt_USRCXXFLAGS} \
${build_rostra_USRCXXFLAGS} 


build_xde_USRLIBDIRS += \
${build_rostra_USRLIBDIRS} \
${build_libxslt_USRLIBDIRS} 


build_xde_LIBS += \
${build_rostra_LIBS} 
