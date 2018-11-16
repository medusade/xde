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
#   File: Makefile
#
# Author: $author$
#   Date: 11/14/2018
#
# build Gcc Makefile for xde
########################################################################

########################################################################
# libxml2
#
# pkg-config --cflags --libs libxml2
#

ifndef USE_HOME_BUILD_libxml2
USE_HOME_BUILD_libxml2 = yes
endif

ifeq ($(USE_HOME_BUILD_libxml2),yes)
#
# home build libxml2
#
build_libxml2_USRDEFINES += \

build_libxml2_USRINCLUDES += \
-I${HOME}/build/libxml2/include/libxml2 

build_libxml2_USRCXXFLAGS += \

build_libxml2_USRLIBDIRS += \
-L${HOME}/build/libxml2/lib 

build_libxml2_LIBS += \
-lxml2 

build_libxml2_FRAMEWORKS += \

else
#
# build libxml2
#
build_libxml2_USRDEFINES += \

build_libxml2_USRINCLUDES += \

build_libxml2_USRCXXFLAGS += \

build_libxml2_USRLIBDIRS += \

build_libxml2_LIBS += \

build_libxml2_FRAMEWORKS += \

endif

########################################################################
# libxslt
#
# pkg-config --cflags --libs libxslt
#

ifndef USE_HOME_BUILD_libxslt
USE_HOME_BUILD_libxslt = yes
endif

ifeq ($(USE_HOME_BUILD_libxslt),yes)
#
# home build libxslt
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

build_libxslt_FRAMEWORKS += \

else
#
# build libxslt
#
build_libxslt_USRDEFINES += \

build_libxslt_USRINCLUDES += \

build_libxslt_USRCXXFLAGS += \

build_libxslt_USRLIBDIRS += \

build_libxslt_LIBS += \

build_libxslt_FRAMEWORKS += \

endif

########################################################################
# xde

# build xde USRDEFINES
#
build_xde_USRDEFINES += \
${build_depends_USRDEFINES} \


# build xde USRINCLUDES
#
build_xde_USRINCLUDES += \
${build_depends_USRINCLUDES} \


# build xde USRCXXFLAGS
#
build_xde_USRCXXFLAGS += \
${build_depends_USRCXXFLAGS} \


# build xde USRLIBDIRS
#
build_xde_USRLIBDIRS += \
${build_depends_USRLIBDIRS} \


# build xde FRAMEWORKS
#
build_xde_FRAMEWORKS += \
${build_depends_FRAMEWORKS} \


# build xde LIBS
#
build_xde_LIBS += \
${build_depends_LIBS} \
${build_xde_FRAMEWORKS}


########################################################################
# medusaxde

# build medusaxde USRDEFINES
#
build_medusaxde_USRDEFINES += \
${build_xde_USRDEFINES} \
${build_libxml2_USRDEFINES} \
${build_libxslt_USRDEFINES} \


# build medusaxde USRINCLUDES
#
build_medusaxde_USRINCLUDES += \
${build_xde_USRINCLUDES} \
${build_libxslt_USRINCLUDES} \
${build_libxml2_USRINCLUDES} \


# build medusaxde USRCXXFLAGS
#
build_medusaxde_USRCXXFLAGS += \
${build_xde_USRCXXFLAGS} \
${build_libxml2_USRCXXFLAGS} \
${build_libxslt_USRCXXFLAGS} \


# build medusaxde USRLIBDIRS
#
build_medusaxde_USRLIBDIRS += \
${build_xde_USRLIBDIRS} \
${build_libxslt_USRLIBDIRS} \
${build_libxml2_USRLIBDIRS} \


# build medusaxde FRAMEWORKS
#
build_medusaxde_FRAMEWORKS += \
${build_xde_FRAMEWORKS} \
${build_libxslt_FRAMEWORKS} \
${build_libxml2_FRAMEWORKS} \


# build medusaxde LIBS
#
build_medusaxde_LIBS += \
${build_xde_LIBS} \
${build_libxslt_LIBS} \
${build_libxml2_LIBS} \
${build_medusaxde_FRAMEWORKS}
