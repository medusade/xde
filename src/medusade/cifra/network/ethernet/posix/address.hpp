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
#ifndef _CIFRA_NETWORK_ETHERNET_POSIX_ADDRESS_HPP
#define _CIFRA_NETWORK_ETHERNET_POSIX_ADDRESS_HPP

#include "cifra/network/ethernet/address.hpp"

#include <sys/time.h>
#include <sys/socket.h>

#if defined(MACOSX)
#include <net/if.h>
#include <net/if_dl.h>
#include <net/if_types.h>
#include <ifaddrs.h>
#else /// defined(MACOSX)
#include <net/if.h>
#include <sys/ioctl.h>
#endif /// defined(MACOSX)

namespace cifra {
namespace network {
namespace ethernet {
namespace posix {

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
#if defined(MACOSX)
#else /// defined(MACOSX)
        free_if_nameindex();
#endif /// defined(MACOSX)
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    using Extends::set_to_adapter;
    virtual actual_t* set_to_adapter(const string_t& named) {
        const char* chars = 0;
        size_t length = 0;

        if ((chars = named.chars(length)) && (0 < (length))) {
#if defined(MACOSX)
            const actual_t* actual = 0;
            struct ifaddrs* ifa = 0;

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
#else /// defined(MACOSX)
            const actual_t *actual = 0;
            static struct if_nameindex *ifn = 0;
            struct ifreq ifr;

            this->clear();

            if ((actual = this->get_first(ifr, ifn))) {
                int unequal = 0;
                do {
                    string_t name(ifn->if_name);
                    if (!(unequal = name.compare(named))) {
                        this->set(*actual, name, ifn->if_index);
                        return &this->actual();
                    }
                } while ((actual = this->get_next(ifr, ifn)));
            }
#endif /// defined(MACOSX)
        } else {
            return this->set_to_first_adapter();
        }
        return 0;
    }
    virtual actual_t* set_to_adapter(int index) {
#if defined(MACOSX)
        const actual_t* actual = 0;
        struct ifaddrs* ifa = 0;
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

                        if ((1 > index) || (eindex == index)) {
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
#else /// defined(MACOSX)
        const actual_t *actual = 0, *last_actual = 0;
        static struct if_nameindex *ifn = 0, *last_ifn = 0;
        struct ifreq ifr;
        int eindex = 0;

        this->clear();

        if ((actual = this->get_first(ifr, ifn))) {
            do {
                if ((1 > index) || (eindex == index)) {
                    string_t name(ifn->if_name);
                    this->set(*actual, name, ifn->if_index);
                    return &this->actual();
                }
                last_actual = actual;
                last_ifn = ifn;
                ++eindex;
            } while ((actual = this->get_next(ifr, ifn)));

            if ((last_actual) && (last_ifn) && (0 > index)) {
                string_t name(last_ifn->if_name);
                this->set(*last_actual, name, last_ifn->if_index);
                return &this->actual();
            }
        }
#endif /// defined(MACOSX)
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const actual_t* get_first() const {
        const actual_t* actual = 0;
        actual = this->get_next(0);
        return actual;
    }
    virtual const actual_t* get_next(const actual_t* to) const {
        const actual_t* actual = 0;
#if defined(MACOSX)
        struct ifaddrs* ifa = 0;
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
#else /// defined(MACOSX)
        static struct if_nameindex* ifn = 0;
        struct ifreq ifr;
        if ((actual = this->get_first(ifr, ifn))) {
            if ((to)) {
                do {
                    if ((*to) == (*actual)) {
                        actual = this->get_next(ifr, ifn);
                        break;
                    }
                } while ((actual = this->get_next(ifr, ifn)));
            }
        }
#endif /// defined(MACOSX)
        return actual;
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
#if defined(MACOSX)
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
#else /// defined(MACOSX)
    virtual const actual_t* get_first(struct ifreq& ifr, struct if_nameindex*& ifn) const {
        free_if_nameindex();
        if ((ifn = get_if_nameindex()) && (*((char*)ifn))) {
            const actual_t* actual = 0;
            do {
                if ((actual = this->get(ifr, ifn))) {
                    return actual;
                }
            } while (*((char*)(++ifn)));
        }
        return 0;
    }
    virtual const actual_t* get_next(struct ifreq& ifr, struct if_nameindex*& ifn) const {
        if ((ifn) && (*((char*)ifn))) {
            const actual_t* actual = 0;

            for (++ifn; *((char*)ifn); ++ifn) {
                if ((actual = this->get(ifr, ifn))) {
                    return actual;
                }
            }
        }
        return 0;
    }
    virtual const actual_t* get(struct ifreq& ifr, struct if_nameindex*& ifn) const {
        if ((ifn) && (*((char*)ifn))) {
            const char *chars = 0;

            if ((chars = ifn->if_name) && (chars[0])) {

                ::memset(&ifr, 0, sizeof(ifr));
                ::strncpy(ifr.ifr_name, chars, IF_NAMESIZE);

                if (!(ifr.ifr_name[IF_NAMESIZE-1])) {
                    int sock = 0;

                    if (0 <= (sock = ::socket(PF_INET, SOCK_STREAM, 0))) {
                        int err = ::ioctl(sock, SIOCGIFHWADDR, &ifr);

                        ::close(sock);
                        if (!(err)) {
                            sa_family_t family = ifr.ifr_ifru.ifru_hwaddr.sa_family;

                            if ((AF_LOCAL == (family))) {
                                const actual_t* actual = (const actual_t*)(ifr.ifr_ifru.ifru_hwaddr.sa_data);

                                if ((actual)) {
                                    return actual;
                                }
                            }
                        }
                    }
                }
            }
        }
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void free_if_nameindex() const {
        struct if_nameindex*& ifn = if_nameindex();
        if ((ifn)) {
            ::if_freenameindex(ifn);
            ifn = 0;
        }
    }
    virtual struct if_nameindex* get_if_nameindex() const {
        struct if_nameindex*& ifn = if_nameindex();
        ifn = ::if_nameindex();
        return ifn;
    }
    virtual struct if_nameindex*& if_nameindex() const {
        static struct if_nameindex* ifn = 0;
        return ifn;
    }
#endif /// defined(MACOSX)

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
}; /// class _EXPORT_CLASS addresst
typedef addresst<> address;

} /// namespace posix
} /// namespace ethernet
} /// namespace network
} /// namespace cifra

#endif /// _CIFRA_NETWORK_ETHERNET_POSIX_ADDRESS_HPP 
