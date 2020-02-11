///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2019 $organization$
///
/// This software is provided by the author and contributors ``as is''
/// and any express or implied warranties, including, but not limited to,
/// the implied warranties of merchantability and fitness for a particular
/// purpose are disclaimed. In no event shall the author or contributors
/// be liable for any direct, indirect, incidental, special, exemplary,
/// or consequential damages (including, but not limited to, procurement
/// of substitute goods or services; loss of use, data, or profits; or
/// business interruption) however caused and on any theory of liability,
/// whether in contract, strict liability, or tort (including negligence
/// or otherwise) arising in any way out of the use of this software,
/// even if advised of the possibility of such damage.
///
///   File: main.hpp
///
/// Author: $author$
///   Date: 3/13/2019
///////////////////////////////////////////////////////////////////////
#ifndef _CIFRA_CONSOLE_LIB_CIFRA_VERSION_MAIN_HPP
#define _CIFRA_CONSOLE_LIB_CIFRA_VERSION_MAIN_HPP

#include "xos/console/lib/version/main.hpp"
#include "cifra/lib/cifra/version.hpp"
#include "cifra/console/main.hpp"

namespace cifra {
namespace console {
namespace lib {
namespace cifra {
namespace version {

typedef ::cifra::console::main::Implements maint_implements;
typedef ::cifra::console::main maint_extends;
///////////////////////////////////////////////////////////////////////
///  Class: maint
///////////////////////////////////////////////////////////////////////
template 
<class TImplements = maint_implements, class TExtend = maint_extends,
 class TVersion = ::cifra::lib::cifra::version,
 class TExtends = ::xos::console::lib::version::maint<TVersion, TImplements, TExtend> >

class _EXPORT_CLASS maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef maint Derives;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    maint() {
    }
    virtual ~maint() {
    }
private:
    maint(const maint& copy) {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
}; /// class _EXPORT_CLASS maint
typedef maint<> main;

} /// namespace version
} /// namespace cifra
} /// namespace lib
} /// namespace console
} /// namespace cifra

#endif /// ndef _CIFRA_CONSOLE_LIB_CIFRA_VERSION_MAIN_HPP
