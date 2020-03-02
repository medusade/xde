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
///   Date: 2/27/2020
///////////////////////////////////////////////////////////////////////
#ifndef CIFRA_NETWORK_ETHERNET_APPLE_OSX_ADDRESS_HPP
#define CIFRA_NETWORK_ETHERNET_APPLE_OSX_ADDRESS_HPP

#include "cifra/network/ethernet/address.hpp"

#include <sys/socket.h>
#include <net/if.h>
#include <net/if_dl.h>
#include <net/if_types.h>
#include <ifaddrs.h>

namespace cifra {
namespace network {
namespace ethernet {
namespace apple {
namespace osx {

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
    
    typedef typename Extends::actual_t actual_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    addresst(const string_t& adapter_named) {
        if (!(this->set_to_adapter(adapter_named))) {
            throw exception(exception_failed);
        }
    }
    addresst(const addresst &copy): Extends(copy) {
    }
    addresst() {
    }
    virtual ~addresst() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    using Extends::set_to_adapter;
    virtual actual_t* set_to_adapter(const string_t& named) {
        const char* chars = 0;
        size_t length = 0;

        if ((chars = named.chars(length)) && (0 < (length))) {
            struct ifaddrs* ifa = 0;
            const actual_t* actual = 0;

            this->clear();

            if ((actual = this->get_first(ifa))) {
                struct sockaddr_dl* dl = 0;
                int unequal = 0;

                do {
                    if ((dl = (struct sockaddr_dl*)(ifa->ifa_addr))) {
                        if ((chars = (const char*)(dl->sdl_data)) 
                            && (0 < (length = (size_t)(dl->sdl_nlen)))) {
                            string_t name(chars, length);

                            if (!(unequal = name.compare(named))) {
                                this->set(*actual, name, dl->sdl_index);
                                return &this->actual();
                            }
                        }
                    }
                } while ((actual = this->get_next(ifa)));
            }
        } else {
            return this->set_to_first_adapter();
        }
        return 0;
    }
    virtual actual_t* set_to_adapter(int index) {
        struct ifaddrs* ifa = 0;
        const actual_t* actual = 0;
        int eindex = 0;

        this->clear();

        if ((actual = this->get_first(ifa))) {
            struct sockaddr_dl* dl = 0;
            const char* chars = 0;
            size_t length = 0;

            do {
                if ((dl = (struct sockaddr_dl*)(ifa->ifa_addr))) {
                    if ((chars = (const char*)(dl->sdl_data))
                         && (0 < (length = (size_t)(dl->sdl_nlen)))) {

                        if ((1 > index) || (eindex == index)/*((dl->sdl_index) && (index == dl->sdl_index))*/) {
                            string_t name(chars, length);
                            this->set(*actual, name, dl->sdl_index);
                            return &this->actual();
                        }
                        ++eindex;
                    }
                }
            } while ((actual = this->get_next(ifa)));

            if ((dl) && (chars) && (length)) {
                if ((0 > index)) {
                    string_t name(chars, length);
                    this->set(*actual, name, dl->sdl_index);
                    return &this->actual();
                }
            }
        }
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const actual_t* get_first() const {
        return this->get_next(0);
    }
    virtual const actual_t* get_next(const actual_t* to) const {
        struct ifaddrs* ifa = 0;
        const actual_t* actual = 0;
        if ((actual = this->get_first(ifa))) {
            if ((to)) {
                do {
                    if ((*to) == (*actual)) {
                        actual = this->get_next(ifa);
                        break;
                    }
                } while ((actual = this->get_next(ifa)));
            }
        }
        return actual;
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const actual_t* get_first(struct ifaddrs*& ifa) const {
        int err = 0;
        if (!(err = ::getifaddrs(&ifa)) && (ifa)) {
            const actual_t* actual = 0;
            do {
                if ((actual = this->get(ifa)))
                    return actual;
            } while ((ifa = ifa->ifa_next));
        } else {
        }
        return 0;
    }
    virtual const actual_t* get_next(struct ifaddrs*& ifa) const {
        if ((ifa)) {
            const actual_t* actual = 0;
            while ((ifa = ifa->ifa_next)) {
                if ((actual = this->get(ifa)))
                    return actual;
            }
        }
        return 0;
    }
    virtual const actual_t* get(struct ifaddrs*& ifa) const {
        if ((ifa)) {
            struct sockaddr* sa = 0;
            struct sockaddr_dl* dl = 0;
            const actual_t* actual = 0;
            const char* chars = 0;
            size_t length = 0;

            if ((sa = (ifa->ifa_addr))) {
                if ((AF_LINK == (sa->sa_family))
                    && (dl = (struct sockaddr_dl*)(ifa->ifa_addr))) {
                    if ((IFT_ETHER == (dl->sdl_type))
                         && (sizeof(actual_t) == (dl->sdl_alen))
                         && (actual = (const actual_t*)(LLADDR(dl)))
                         && (chars = (const char*)(dl->sdl_data))
                         && (0 < (length = (size_t)(dl->sdl_nlen)))) {
                        string_t name(chars, length);
                        return actual;
                    }
                }
            }
        }
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
}; /// class _EXPORT_CLASS addresst
typedef addresst<> address;

} /// namespace osx
} /// namespace apple
} /// namespace ethernet
} /// namespace network
} /// namespace cifra

#endif /// CIFRA_NETWORK_ETHERNET_APPLE_OSX_ADDRESS_HPP
