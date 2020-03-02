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
///   File: address.hpp
///
/// Author: $author$
///   Date: 2/10/2020
///////////////////////////////////////////////////////////////////////
#ifndef _CIFRA_NETWORK_ETHERNET_MICROSOFT_WINDOWS_ADDRESS_HPP
#define _CIFRA_NETWORK_ETHERNET_MICROSOFT_WINDOWS_ADDRESS_HPP

#include "cifra/network/ethernet/address.hpp"

namespace cifra {
namespace network {
namespace ethernet {
namespace microsoft {
namespace windows {

typedef ethernet::address addresst_extends;
typedef addresst_extends::Implements addresst_implements;
///////////////////////////////////////////////////////////////////////
///  Class: addresst
///////////////////////////////////////////////////////////////////////
template <class TImplements = addresst_implements, class TExtends = addresst_extends>
class _EXPORT_CLASS addresst: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef addresst Derives;
    
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    addresst(const addresst &copy): Extends(copy) {
    }
    addresst() {
    }
    virtual ~addresst() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
}; /// class _EXPORT_CLASS addresst
typedef addresst<> address;

} /// namespace windows
} /// namespace microsoft
} /// namespace ethernet
} /// namespace network
} /// namespace cifra

#endif /// _CIFRA_NETWORK_ETHERNET_MICROSOFT_WINDOWS_ADDRESS_HPP 
