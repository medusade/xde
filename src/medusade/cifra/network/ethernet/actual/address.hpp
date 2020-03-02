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
#ifndef _CIFRA_NETWORK_ETHERNET_ACTUAL_ADDRESS_HPP
#define _CIFRA_NETWORK_ETHERNET_ACTUAL_ADDRESS_HPP

#include "cifra/base/base.hpp"

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define NETWORK_ETHERNET_ACTUAL_ADDRESS_SIZE 6

///////////////////////////////////////////////////////////////////////
/// OUI group/indiviual bit
///////////////////////////////////////////////////////////////////////
#define NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BM_GROUP 0x01
#define NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BS_GROUP 0
#define NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BI_GROUP 0

#define NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BV_INDIVIDUAL 0x00
#define NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BV_GROUP      0x01

#define NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_INDIVIDUAL 0
#define NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_GROUP      1

///////////////////////////////////////////////////////////////////////
/// OUI local/global bit
///////////////////////////////////////////////////////////////////////
#define NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BM_LOCAL 0x02
#define NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BS_LOCAL 1
#define NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BI_LOCAL 0

#define NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BV_GLOBAL 0x00
#define NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BV_LOCAL  0x02

#define NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_GLOBAL 0
#define NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_LOCAL  1

///////////////////////////////////////////////////////////////////////
/// OUI multicast/unicast bit
///////////////////////////////////////////////////////////////////////
#define NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BM_MULTICAST NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BM_GROUP
#define NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BS_MULTICAST NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BS_GROUP
#define NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BI_MULTICAST NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BI_GROUP

#define NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BV_UNICAST   NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BV_INDIVIDUAL
#define NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BV_MULTICAST NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BV_GROUP

#define NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_UNICAST   NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_INDIVIDUAL
#define NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_MULTICAST NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_GROUP

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

namespace cifra {
namespace network {
namespace ethernet {
namespace actual {

#include "cifra/base/platform_packed_begin.hpp"
///////////////////////////////////////////////////////////////////////
///  Struct: address
///////////////////////////////////////////////////////////////////////
struct _PACKED_STRUCT address {
    typedef address Derives;
    
    ///////////////////////////////////////////////////////////////////////
    /// Union
    ///////////////////////////////////////////////////////////////////////
    union {
        uint8_t m_b[NETWORK_ETHERNET_ACTUAL_ADDRESS_SIZE];

        struct PACKED_STRUCT {
            struct PACKED_STRUCT {
                uint8_t m_b[NETWORK_ETHERNET_ACTUAL_ADDRESS_SIZE/2];
            } m_oui;

            struct PACKED_STRUCT {
                uint8_t m_b[NETWORK_ETHERNET_ACTUAL_ADDRESS_SIZE/2];
            } m_nic;
        };
    }; /// union

    ///////////////////////////////////////////////////////////////////////
    /// Struct: Oui
    ///////////////////////////////////////////////////////////////////////
    struct Oui {
        struct Grouped {
            typedef int Which;
            enum {
                Individual = NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_INDIVIDUAL,
                Group = NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_GROUP
            };
            enum {
                Index = NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BI_GROUP,
                Mask = NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BM_GROUP,
                Shift = NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BS_GROUP
            };
        };
        struct Located {
            typedef int Which;
            enum {
                Local = NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_LOCAL,
                Global = NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_GLOBAL 
            };
            enum {
                Index = NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BI_LOCAL,
                Mask = NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BM_LOCAL,
                Shift = NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BS_LOCAL
            };
        };
        struct Casted {
            typedef int Which;
            enum {
                Unicast = NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_UNICAST,
                Multicast = NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_MULTICAST
            };
            enum {
                Index = NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BI_MULTICAST,
                Mask = NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BM_MULTICAST,
                Shift = NETWORK_ETHERNET_ACTUAL_ADDRESS_OUI_BS_MULTICAST
            };
        };
    }; /// struct Oui

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    inline bool operator != (const Derives& to) const {
        return (0 != (memcmp(this, &to, sizeof(Derives))));
    }
    inline bool operator == (const Derives& to) const {
        return (0 != (memcmp(this, &to, sizeof(Derives))));
    }
    inline size_t size() const {
        return sizeof(Derives);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
}; /// struct _PACKED_STRUCT address
#include "cifra/base/platform_packed_end.hpp"

} /// namespace actual
} /// namespace ethernet
} /// namespace network
} /// namespace cifra

#endif /// _CIFRA_NETWORK_ETHERNET_ACTUAL_ADDRESS_HPP 
