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
#   File: xde.pri
#
# Author: $author$
#   Date: 11/13/2018
#
# build QtCreator .pri file for xde
########################################################################
UNAME = $$system(uname)

contains(UNAME,Darwin) {
HOME = /Users/jboyd
} else {
HOME = /home/jboyd
}

########################################################################
# libxml2
#
# pkg-config --cflags --libs libxml2
#

# build libxml2 INCLUDEPATH
#
build_libxml2_INCLUDEPATH += \
$${HOME}/build/libxml2/include/libxml2 \

# build libxml2 DEFINES
#
build_libxml2_DEFINES += \

# build libxml2 LIBS
#
build_libxml2_LIBS += \
-L$${HOME}/build/libxml2/lib \
-lxml2 \

########################################################################
# libxslt
#
# pkg-config --cflags --libs libxslt
#

# build libxslt INCLUDEPATH
#
build_libxslt_INCLUDEPATH += \
$${HOME}/build/libxslt/include \
$${build_libxml2_INCLUDEPATH} \

# build libxslt DEFINES
#
build_libxslt_DEFINES += \

# build libxslt LIBS
#
build_libxslt_LIBS += \
-L$${HOME}/build/libxslt/lib \
-lxslt \
-lexslt \
$${build_libxml2_LIBS} \

########################################################################
# xde

# build xde INCLUDEPATH
#
build_xde_INCLUDEPATH += \


# build xde DEFINES
#
build_xde_DEFINES += \


# build xde LIBS
#
build_xde_LIBS += \

########################################################################
# medusaxde

# build medusaxde INCLUDEPATH
#
build_medusaxde_INCLUDEPATH += \
$${build_xde_INCLUDEPATH} \
$${build_libxslt_INCLUDEPATH} \
$${build_libxml2_INCLUDEPATH} \

# build medusaxde DEFINES
#
build_medusaxde_DEFINES += \
$${build_libxml2_DEFINES} \
$${build_libxslt_DEFINES} \


# build medusaxde LIBS
#
build_medusaxde_LIBS += \
$${build_libxslt_LIBS} \
$${build_libxml2_LIBS} \

