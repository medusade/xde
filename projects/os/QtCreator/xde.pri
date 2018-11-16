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
# Os QtCreator .pri file for xde
########################################################################
UNAME = $$system(uname)

#CONFIG += c++11
#CONFIG += c++0x

########################################################################
# medusaxde

contains(UNAME,Darwin) {
MEDUSAXDE_OS = macosx
} else {
MEDUSAXDE_OS = linux
}

# medusaxde INCLUDEPATH
#
medusaxde_INCLUDEPATH += \

# medusaxde DEFINES
#
medusaxde_DEFINES += \

# medusaxde LIBS
#
medusaxde_LIBS += \
$${build_medusaxde_LIBS} \
-lpthread \
-ldl \

contains(MEDUSAXDE_OS,linux) {
medusaxde_LIBS += \
-lrt
} else {
}

########################################################################
# xde

contains(UNAME,Darwin) {
XDE_OS = macosx
} else {
XDE_OS = linux
}

# xde INCLUDEPATH
#
xde_INCLUDEPATH += \

# xde DEFINES
#
xde_DEFINES += \

# xde LIBS
#
xde_LIBS += \
$${build_xde_LIBS} \
-lpthread \
-ldl \

contains(XDE_OS,linux) {
xde_LIBS += \
-lrt
} else {
}

