########################################################################
# Copyright (c) 1988-2019 $organization$
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
#   Date: 8/6/2019
#
# Thirdpary Makefile for libxslt
########################################################################

########################################################################
#
# libxml2 defs
#
########################################################################

#
# libxml2 version
#
LIBXML2_VERSION_MAJOR = 2
LIBXML2_VERSION_MINOR = 7
LIBXML2_VERSION_RELEASE = 8

LIBXML2_VERSION_SEPARATOR = .
LIBXML2_VERSION_MAJOR_SEPARATOR = $(LIBXML2_VERSION_SEPARATOR)
LIBXML2_VERSION_MINOR_SEPARATOR = $(LIBXML2_VERSION_SEPARATOR)

LIBXML2_VERSION_SHORT = $(LIBXML2_VERSION_MAJOR)$(LIBXML2_VERSION_MINOR)$(LIBXML2_VERSION_RELEASE)
LIBXML2_VERSION = $(LIBXML2_VERSION_MAJOR)$(LIBXML2_VERSION_MAJOR_SEPARATOR)$(LIBXML2_VERSION_MINOR)$(LIBXML2_VERSION_MINOR_SEPARATOR)$(LIBXML2_VERSION_RELEASE)

#
# libxml2 name
#
LIBXML2_NAME_SEPARATOR = -
LIBXML2_NAME_BASE = libxml2
LIBXML2_NAME = $(LIBXML2_NAME_BASE)$(LIBXML2_NAME_SEPARATOR)$(LIBXML2_VERSION)
LIBXML2_INSTALL_NAME_SEPARATOR = -
LIBXML2_INSTALL_NAME = $(LIBXML2_NAME_BASE)$(LIBXML2_INSTALL_NAME_SEPARATOR)$(LIBXML2_VERSION)
LIBXML2_DIR = $(LIBXML2_NAME)

########################################################################
#
# libxslt defs
#
########################################################################
LIBXSLT_MAKEDIR=$(PWD)

ifndef LIBXSLT_UNAME
LIBXSLT_UNAME = $(shell uname)
endif

ifndef LIBXSLT_OS
ifneq ($(LIBXSLT_UNAME), Darwin)
LIBXSLT_OS = linux
else
LIBXSLT_OS = macosx
endif
endif

#
# libxslt version
#
LIBXSLT_VERSION_MAJOR = 1
LIBXSLT_VERSION_MINOR = 1
LIBXSLT_VERSION_RELEASE = 26

LIBXSLT_VERSION_SEPARATOR = .
LIBXSLT_VERSION_MAJOR_SEPARATOR = $(LIBXSLT_VERSION_SEPARATOR)
LIBXSLT_VERSION_MINOR_SEPARATOR = $(LIBXSLT_VERSION_SEPARATOR)

LIBXSLT_VERSION_SHORT = $(LIBXSLT_VERSION_MAJOR)$(LIBXSLT_VERSION_MINOR)$(LIBXSLT_VERSION_RELEASE)
LIBXSLT_VERSION = $(LIBXSLT_VERSION_MAJOR)$(LIBXSLT_VERSION_MAJOR_SEPARATOR)$(LIBXSLT_VERSION_MINOR)$(LIBXSLT_VERSION_MINOR_SEPARATOR)$(LIBXSLT_VERSION_RELEASE)

#
# libxslt name
#
LIBXSLT_NAME_SEPARATOR = -
LIBXSLT_NAME_BASE = libxslt
LIBXSLT_NAME = $(LIBXSLT_NAME_BASE)$(LIBXSLT_NAME_SEPARATOR)$(LIBXSLT_VERSION)
LIBXSLT_INSTALL_NAME_SEPARATOR = -
LIBXSLT_INSTALL_NAME = $(LIBXSLT_NAME_BASE)$(LIBXSLT_INSTALL_NAME_SEPARATOR)$(LIBXSLT_VERSION)
LIBXSLT_DIR = $(LIBXSLT_NAME)

#
# libxslt archive
#
LIBXSLT_ARCHIVED = tar
LIBXSLT_COMPRESSED = gz
LIBXSLT_ARCHIVE_SEPARATOR = .
LIBXSLT_ARCHIVED_SEPARATOR = $(LIBXSLT_ARCHIVE_SEPARATOR)
LIBXSLT_COMPRESSED_SEPARATOR = $(LIBXSLT_ARCHIVE_SEPARATOR)

LIBXSLT_EXTRACT_DIR = $(LIBXSLT_NAME)
LIBXSLT_TGZ_PREFIX = 
LIBXSLT_TGZ = $(LIBXSLT_NAME)$(LIBXSLT_TGZ_PREFIX)$(LIBXSLT_ARCHIVED_SEPARATOR)$(LIBXSLT_ARCHIVED)$(LIBXSLT_COMPRESSED_SEPARATOR)$(LIBXSLT_COMPRESSED)
LIBXSLT_PATCH_TGZ_PREFIX = $(LIBXSLT_NAME_SEPARATOR)xde-windows-patch
LIBXSLT_PATCH_TGZ = $(LIBXSLT_NAME)$(LIBXSLT_PATCH_TGZ_PREFIX)$(LIBXSLT_ARCHIVED_SEPARATOR)$(LIBXSLT_ARCHIVED)$(LIBXSLT_COMPRESSED_SEPARATOR)$(LIBXSLT_COMPRESSED)
LIBXSLT_PATCHED_TGZ_PREFIX = $(LIBXSLT_PATCH_TGZ_PREFIX)ed
LIBXSLT_PATCHED_TGZ = $(LIBXSLT_NAME)$(LIBXSLT_PATCHED_TGZ_PREFIX)$(LIBXSLT_ARCHIVED_SEPARATOR)$(LIBXSLT_ARCHIVED)$(LIBXSLT_COMPRESSED_SEPARATOR)$(LIBXSLT_COMPRESSED)
LIBXSLT_DOCS_TGZ_PREFIX = $(LIBXSLT_NAME_SEPARATOR)docs
LIBXSLT_DOCS_TGZ = $(LIBXSLT_NAME)$(LIBXSLT_DOCS_TGZ_PREFIX)$(LIBXSLT_ARCHIVED_SEPARATOR)$(LIBXSLT_ARCHIVED)$(LIBXSLT_COMPRESSED_SEPARATOR)$(LIBXSLT_COMPRESSED)
LIBXSLT_BUILD_TGZ_PREFIX = $(LIBXSLT_NAME_SEPARATOR)build
LIBXSLT_BUILD_TGZ = $(LIBXSLT_NAME)$(LIBXSLT_BUILD_TGZ_PREFIX)$(LIBXSLT_ARCHIVED_SEPARATOR)$(LIBXSLT_ARCHIVED)$(LIBXSLT_COMPRESSED_SEPARATOR)$(LIBXSLT_COMPRESSED)

#
# libxslt extract
#
ifeq ($(LIBXSLT_ARCHIVED),tar)
ifeq ($(LIBXSLT_COMPRESSED),gz)
LIBXSLT_TAR_UNCOMPRESS = z
LIBXSLT_TAR_COMPRESS = z
else
ifeq ($(LIBXSLT_COMPRESSED),bz2)
LIBXSLT_TAR_UNCOMPRESS = j
LIBXSLT_TAR_COMPRESS = j
else
ifeq ($(LIBXSLT_COMPRESSED),xz)
LIBXSLT_TAR_UNCOMPRESS = J
LIBXSLT_TAR_COMPRESS = J
else
endif
endif
endif
LIBXSLT_LIST = tar -tv$(LIBXSLT_TAR_UNCOMPRESS)f
LIBXSLT_EXTRACT = tar -x$(LIBXSLT_TAR_UNCOMPRESS)f
LIBXSLT_ARCHIVE = tar -cv$(LIBXSLT_TAR_COMPRESS)f
else
ifeq ($(LIBXSLT_ARCHIVED),zip)
LIBXSLT_LIST = unzip -l
LIBXSLT_EXTRACT = unzip
LIBXSLT_ARCHIVE = zip
else
LIBXSLT_LIST = echo unable to list
LIBXSLT_EXTRACT = echo unable to extract
LIBXSLT_ARCHIVE = echo unable to archive
endif
endif

LIBXSLT_LIST_TGZ = $(LIBXSLT_LIST) $(LIBXSLT_TGZ)
LIBXSLT_EXTRACT_TGZ = $(LIBXSLT_EXTRACT) $(LIBXSLT_TGZ)
LIBXSLT_TOUCH_EXTRACT = touch $(LIBXSLT_DIR)
LIBXSLT_REMOVE_DIR = $(LIBXSLT_REMOVE) $(LIBXSLT_DIR)

LIBXSLT_LIST_PATCH = $(LIBXSLT_LIST)
LIBXSLT_EXTRACT_PATCH = $(LIBXSLT_EXTRACT)
LIBXSLT_LIST_PATCH_TGZ = $(LIBXSLT_LIST_PATCH) $(LIBXSLT_PATCH_TGZ)
LIBXSLT_EXTRACT_PATCH_TGZ = $(LIBXSLT_EXTRACT_PATCH) $(LIBXSLT_PATCH_TGZ)

LIBXSLT_LIST_PATCHED = $(LIBXSLT_LIST)
LIBXSLT_EXTRACT_PATCHED = $(LIBXSLT_EXTRACT)
LIBXSLT_LIST_PATCHED_TGZ = $(LIBXSLT_LIST_PATCHED) $(LIBXSLT_PATCHED_TGZ)
LIBXSLT_EXTRACT_PATCHED_TGZ = $(LIBXSLT_EXTRACT_PATCHED) $(LIBXSLT_PATCHED_TGZ)

LIBXSLT_LIST_DOCS = $(LIBXSLT_LIST)
LIBXSLT_EXTRACT_DOCS = $(LIBXSLT_EXTRACT)
LIBXSLT_LIST_DOCS_TGZ = $(LIBXSLT_LIST_DOCS) $(LIBXSLT_DOCS_TGZ)
LIBXSLT_EXTRACT_DOCS_TGZ = $(LIBXSLT_EXTRACT_DOCS) $(LIBXSLT_DOCS_TGZ) -C$(LIBXSLT_DOCS_PREFIX)

LIBXSLT_LIST_BUILD = $(LIBXSLT_LIST)
LIBXSLT_EXTRACT_BUILD = $(LIBXSLT_EXTRACT)
LIBXSLT_LIST_BUILD_TGZ = $(LIBXSLT_LIST_BUILD) $(LIBXSLT_BUILD_TGZ)
LIBXSLT_EXTRACT_BUILD_TGZ = $(LIBXSLT_EXTRACT_BUILD) $(LIBXSLT_BUILD_TGZ)

#
# libxslt build
#
LIBXSLT_BUILD = $(LIBXSLT_MAKEDIR)/build
LIBXSLT_PREFIX = $(LIBXSLT_BUILD)/$(LIBXSLT_INSTALL_NAME)
LIBXSLT_EXEC_PREFIX = $(LIBXSLT_PREFIX)
LIBXSLT_CONF_PREFIX = $(LIBXSLT_PREFIX)
LIBXSLT_DOCS_PREFIX = $(LIBXSLT_PREFIX)
LIBXSLT_LINK_NAME = $(LIBXSLT_BUILD)/$(LIBXSLT_NAME_BASE)

LIBXSLT_MKDIR = mkdir -p
LIBXSLT_REMOVE = rm -r -f

LIBXSLT_MAKE_DIR = $(LIBXSLT_DIR)
LIBXSLT_MAKE_PUSHD = pushd $(LIBXSLT_MAKE_DIR)
LIBXSLT_MAKE = make

#
# libxslt configure
#
ifneq ($(LIBXSLT_UNAME), Darwin)
LIBXSLT_CONFIGURE_UNAME = --enable-shared=no
else
LIBXSLT_CONFIGURE_UNAME = --enable-shared=yes
endif
LIBXSLT_CONFIGURE_CONFIGURE = ./configure
LIBXSLT_CONFIGURE_HELP = $(LIBXSLT_CONFIGURE_CONFIGURE) --help
LIBXSLT_CONFIGURE_PUSHD = pushd $(LIBXSLT_MAKE_DIR)
LIBXSLT_CONFIGURE = $(LIBXSLT_CONFIGURE_CONFIGURE) \
--with-libxml-src=../../$(LIBXML2_NAME_BASE)/$(LIBXML2_NAME) \
$(LIBXSLT_CONFIGURE_UNAME) --prefix=$(LIBXSLT_PREFIX) --exec_prefix=$(LIBXSLT_EXEC_PREFIX)

#
# libxslt help
#
LIBXSLT_HELP = $(LIBXSLT_CONFIGURE_HELP)

########################################################################
#
# rules
#
########################################################################

all: extract config build

test: test-libxslt

install-links: install-libxslt-links

install-docs: install-libxslt-docs

install-prefix: install-libxslt-prefix

install: install-libxslt

build: build-libxslt

clean: clean-libxslt

configed: configed-$(LIBXSLT_DIR)

config: config-$(LIBXSLT_DIR)

help: help-libxslt

list-docs: list-libxslt-docs

########################################################################
list-patch: list-libxslt-patch

extract-patch: extract-libxslt-patch

patch-extracted: libxslt-patch-extracted

########################################################################
list-patched: list-libxslt-patched

extract-patched: extract-libxslt-patched

archive-patched: archive-libxslt-patched

patched-archived: libxslt-patched-archived

patched-extracted: libxslt-patched-extracted

########################################################################
list-build: list-libxslt-build

extract-build: extract-libxslt-build

archive-build: archive-libxslt-build

build-archived: libxslt-build-archived

build-extracted: libxslt-build-extracted

########################################################################
list: list-libxslt

extract: extract-libxslt

unextract: unextract-libxslt

archive: archive-libxslt

linked: libxslt-linked

prefixed: libxslt-prefixed

archived: libxslt-archived

extracted: libxslt-extracted

########################################################################
#
# libxslt rules
#
########################################################################

#
# Test libxslt
#
test-libxslt:
	@($(LIBXSLT_MAKE_PUSHD);\
	  (($(LIBXSLT_MAKE) test) || (exit 1));\
	  popd)

#
# Install libxslt
#
install-libxslt: configed-$(LIBXSLT_DIR)
	@(echo Installing $(LIBXSLT_DIR)...;\
	  $(LIBXSLT_MAKE_PUSHD);\
	  (($(LIBXSLT_MAKE) install) || (exit 1)) && \
	  ((touch $(LIBXSLT_MAKEDIR)/configed-$(LIBXSLT_DIR)) || (exit 1));\
	  popd)
	  
#
# Build libxslt
#
build-libxslt: configed-$(LIBXSLT_DIR)
	@(echo Building $(LIBXSLT_DIR)...;\
	  $(LIBXSLT_MAKE_PUSHD);\
	  (($(LIBXSLT_MAKE)) || (exit 1)) && \
	  ((touch $(LIBXSLT_MAKEDIR)/configed-$(LIBXSLT_DIR)) || (exit 1));\
	  popd)
	  
#
# Clean libxslt
#
clean-libxslt: configed-$(LIBXSLT_DIR)
	@(echo Cleaning $(LIBXSLT_DIR)...;\
	  $(LIBXSLT_MAKE_PUSHD);\
	  (($(LIBXSLT_MAKE) clean) || (exit 1)) && \
	  ((touch $(LIBXSLT_MAKEDIR)/configed-$(LIBXSLT_DIR)) || (exit 1));\
	  popd)
	  
#
# Config libxslt
#
config-$(LIBXSLT_DIR): unconfig-$(LIBXSLT_DIR) configed-$(LIBXSLT_DIR)

unconfig-$(LIBXSLT_DIR):
	@(rm -f configed-$(LIBXSLT_DIR))

configed-$(LIBXSLT_DIR): $(LIBXSLT_DIR)
	@(echo Configing $(LIBXSLT_DIR)...;\
	  $(LIBXSLT_CONFIGURE_PUSHD);\
	  (($(LIBXSLT_CONFIGURE)) || (exit 1)) && \
	  ((touch $(LIBXSLT_DIR)) || (exit 1)) && \
	  ((touch $(LIBXSLT_MAKEDIR)/configed-$(LIBXSLT_DIR)) || (exit 1));\
	  popd)

#
# Help libxslt
#
help-libxslt:
	@($(LIBXSLT_CONFIGURE_PUSHD);\
	  (($(LIBXSLT_HELP)) || (exit 1));\
	  popd)

#
# List libxslt Docs
#
list-libxslt-docs: $(LIBXSLT_DOCS_TGZ)
	@(echo Listing $(LIBXSLT_DOCS_TGZ)...;\
	  (($(LIBXSLT_LIST_DOCS_TGZ)) || (exit 1)))

#
# Install libxslt Docs
#
install-libxslt-docs: $(LIBXSLT_DOCS_PREFIX)
	@(echo Extracting $(LIBXSLT_DOCS_TGZ)...;\
	  (($(LIBXSLT_EXTRACT_DOCS_TGZ)) || (exit 1)))

########################################################################
#
# List libxslt Patch
#
list-libxslt-patch: $(LIBXSLT_PATCH_TGZ)
	@(echo Listing $(LIBXSLT_PATCH_TGZ)...;\
	  (($(LIBXSLT_LIST_PATCH_TGZ)) || (exit 1)))

#
# Extract libxslt patch
#
extract-libxslt-patch: $(LIBXSLT_DIR)
	@(echo Extracting $(LIBXSLT_PATCH_TGZ)...;\
	  (($(LIBXSLT_EXTRACT_PATCH_TGZ)) || (exit 1)))

########################################################################
#
# List libxslt patched
#
list-libxslt-patched: $(LIBXSLT_PATCHED_TGZ)
	@(echo Listing $(LIBXSLT_PATCHED_TGZ)...;\
	  (($(LIBXSLT_LIST_PATCHED_TGZ)) || (exit 1)))

#
# Extract libxslt patched
#
extract-libxslt-patched: $(LIBXSLT_PATCHED_TGZ)
	@(echo Extracting $(LIBXSLT_PATCHED_TGZ)...;\
	  (($(LIBXSLT_EXTRACT_PATCHED_TGZ)) || (exit 1)))

#
# Archive libxslt patched
#
archive-libxslt-patched: 
	@(echo Archiving $(LIBXSLT_DIR) to $(LIBXSLT_PATCHED_TGZ)...;\
	  (($(LIBXSLT_ARCHIVE) $(LIBXSLT_PATCHED_TGZ) $(LIBXSLT_DIR)) || (exit 1)))

########################################################################
#
# List libxslt build
#
list-libxslt-build: $(LIBXSLT_BUILD_TGZ)
	@(echo Listing $(LIBXSLT_BUILD_TGZ)...;\
	  (($(LIBXSLT_LIST_BUILD_TGZ)) || (exit 1)))

#
# Extract libxslt build
#
extract-libxslt-build: $(LIBXSLT_BUILD_TGZ)
	@(echo Extracting $(LIBXSLT_BUILD_TGZ)...;\
	  (($(LIBXSLT_EXTRACT_BUILD_TGZ)) || (exit 1)))

#
# Archive libxslt build
#
archive-libxslt-build: 
	@(echo Archiving $(LIBXSLT_DIR) to $(LIBXSLT_BUILD_TGZ)...;\
	  (($(LIBXSLT_ARCHIVE) $(LIBXSLT_BUILD_TGZ) $(LIBXSLT_DIR)) || (exit 1)))

########################################################################
#
# List libxslt
#
list-libxslt: 
	@(echo Listing $(LIBXSLT_TGZ)...;\
	  (($(LIBXSLT_LIST_TGZ)) || (exit 1)))

#
# Extract libxslt
#
extract-libxslt: unextract-libxslt $(LIBXSLT_DIR)

unextract-libxslt: 
	@(echo Removing $(LIBXSLT_DIR)...;\
	  (($(LIBXSLT_REMOVE_DIR)) || (exit 1)))

$(LIBXSLT_DIR): $(LIBXSLT_TGZ)
	@(echo Extracting $(LIBXSLT_TGZ)...;\
	  (($(LIBXSLT_EXTRACT_TGZ)) || (exit 1)) && \
	  (($(LIBXSLT_TOUCH_EXTRACT)) || (exit 1)))
	  
#
# Archive libxslt
#
archive-libxslt: 
	@(echo Archiving $(LIBXSLT_DIR) to $(LIBXSLT_TGZ)...;\
	  (($(LIBXSLT_ARCHIVE) $(LIBXSLT_TGZ) $(LIBXSLT_DIR)) || (exit 1)))

#
# Install libxslt links
#
install-libxslt-links: 
	@((echo removing $(LIBXSLT_LINK_NAME)) && \
	  ((rm -f $(LIBXSLT_LINK_NAME)) || (exit 1)) && \
	  (echo Linking $(LIBXSLT_LINK_NAME) "->" $(LIBXSLT_PREFIX)) && \
	  ((ln -s $(LIBXSLT_PREFIX) $(LIBXSLT_LINK_NAME)) || (exit 1)))
	  
#
# libxslt linked
#
libxslt-linked: 
	@echo link is $(LIBXSLT_LINK_NAME) "->" $(LIBXSLT_PREFIX)
	  
#
# Install libxslt prefix
#
install-libxslt-prefix: 
	@((echo makeing $(LIBXSLT_PREFIX)) && \
	  ((mkdir -p $(LIBXSLT_PREFIX)) || (exit 1)) && \
	  (echo makeing $(LIBXSLT_EXEC_PREFIX)) && \
	  ((mkdir -p $(LIBXSLT_EXEC_PREFIX)) || (exit 1)))
	  
#
# libxslt prefixed
#
libxslt-prefixed: 
	@((echo prefix is $(LIBXSLT_PREFIX)) && \
	  (echo exec prefix is $(LIBXSLT_EXEC_PREFIX)) && \
	  (echo conf prefix is $(LIBXSLT_CONF_PREFIX)) && \
	  (echo docs prefix is $(LIBXSLT_DOCS_PREFIX)))
	  
$(LIBXSLT_PREFIX):
	@(echo Makeing Directory $(LIBXSLT_PREFIX)...;\
	  (($(LIBXSLT_MKDIR) $(LIBXSLT_PREFIX)) || (exit 1)))

$(LIBXSLT_EXEC_PREFIX):
	@(echo Makeing Directory $(LIBXSLT_EXEC_PREFIX)...;\
	  (($(LIBXSLT_MKDIR) $(LIBXSLT_EXEC_PREFIX)) || (exit 1)))

$(LIBXSLT_CONF_PREFIX):
	@(echo Makeing Directory $(LIBXSLT_CONF_PREFIX)...;\
	  (($(LIBXSLT_MKDIR) $(LIBXSLT_CONF_PREFIX)) || (exit 1)))

$(LIBXSLT_DOCS_PREFIX):
	@(echo Makeing Directory $(LIBXSLT_DOCS_PREFIX)...;\
	  (($(LIBXSLT_MKDIR) $(LIBXSLT_DOCS_PREFIX)) || (exit 1)))

########################################################################
#
# libxslt patch extracted
#
libxslt-patch-extracted: 
	@(echo $(LIBXSLT_EXTRACT) $(LIBXSLT_PATCH_TGZ))

########################################################################
#
# libxslt patched archived
#
libxslt-patched-archived: 
	@(echo $(LIBXSLT_ARCHIVE) $(LIBXSLT_PATCHED_TGZ))
	  
#
# libxslt patched extracted
#
libxslt-patched-extracted: 
	@(echo $(LIBXSLT_EXTRACT) $(LIBXSLT_PATCHED_TGZ))

########################################################################
#
# libxslt build archived
#
libxslt-build-archived: 
	@(echo $(LIBXSLT_ARCHIVE) $(LIBXSLT_BUILD_TGZ))
	  
#
# libxslt build extracted
#
libxslt-build-extracted: 
	@(echo $(LIBXSLT_EXTRACT) $(LIBXSLT_BUILD_TGZ))

########################################################################
#
# libxslt archived
#
libxslt-archived: 
	@(echo $(LIBXSLT_ARCHIVE) $(LIBXSLT_TGZ))
	  
#
# libxslt extracted
#
libxslt-extracted: 
	@(echo $(LIBXSLT_EXTRACT) $(LIBXSLT_TGZ))

