///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2020 $organization$
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
///   File: identifier.hpp
///
/// Author: $author$
///   Date: 2/10/2020
///////////////////////////////////////////////////////////////////////
#ifndef _CIFRA_UNIVERSAL_UNIQUE_MICROSOFT_WINDOWS_IDENTIFIER_HPP
#define _CIFRA_UNIVERSAL_UNIQUE_MICROSOFT_WINDOWS_IDENTIFIER_HPP

#include "cifra/universal/unique/identifier.hpp"

namespace cifra {
namespace universal {
namespace unique {
namespace microsoft {
namespace windows {

typedef implement identifiert_implements;
typedef extend identifiert_extends;
///////////////////////////////////////////////////////////////////////
///  Class: identifiert
///////////////////////////////////////////////////////////////////////
template <class TImplements = identifiert_implements, class TExtends = identifiert_extends>
class _EXPORT_CLASS identifiert: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef identifiert derives;
    
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    identifiert(const identifiert &copy) {
    }
    identifiert() {
    }
    virtual ~identifiert() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
}; /// class _EXPORT_CLASS identifiert
typedef identifiert<> identifier;

} /// namespace windows
} /// namespace microsoft
} /// namespace unique
} /// namespace universal
} /// namespace cifra

#endif /// _CIFRA_UNIVERSAL_UNIQUE_MICROSOFT_WINDOWS_IDENTIFIER_HPP 
