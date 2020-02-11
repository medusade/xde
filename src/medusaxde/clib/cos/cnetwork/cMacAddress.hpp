///////////////////////////////////////////////////////////////////////
// Copyright (c) 1988-2013 $organization$
//
// This software is provided by the author and contributors ``as is'' 
// and any express or implied warranties, including, but not limited to, 
// the implied warranties of merchantability and fitness for a particular 
// purpose are disclaimed. In no event shall the author or contributors 
// be liable for any direct, indirect, incidental, special, exemplary, 
// or consequential damages (including, but not limited to, procurement 
// of substitute goods or services; loss of use, data, or profits; or 
// business interruption) however caused and on any theory of liability, 
// whether in contract, strict liability, or tort (including negligence 
// or otherwise) arising in any way out of the use of this software, 
// even if advised of the possibility of such damage.
//
//   File: cMacAddress.hpp
//
// Author: $author$
//   Date: 8/20/2013
///////////////////////////////////////////////////////////////////////
#ifndef _CMACADDRESS_HPP
#define _CMACADDRESS_HPP

#include "cplatform_build.h"
#if defined(WINDOWS) 
// Windows 
#else // defined(WINDOWS) 
// Unix
#if defined(MACOSX)
//
// Mac OSX
//
#include <sys/sysctl.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <ifaddrs.h>
#include <net/if_dl.h>
#else // defined(MACOSX)
//
// Linux or other
//
#include <sys/ioctl.h>
#include <linux/if.h>
#endif // defined(MACOSX)
#endif // defined(WINDOWS) 
#include "cBases.hpp"
#include "cString.hpp"
#include "cDebug.hpp"

#define c_MAC_ADDRESS_SIZE 6

// OUI group/indiviual bit
//
#define c_MAC_ADDRESS_OUI_BM_GROUP 0x01
#define c_MAC_ADDRESS_OUI_BS_GROUP 0

#define c_MAC_ADDRESS_OUI_BV_INDIVIDUAL 0x00
#define c_MAC_ADDRESS_OUI_BV_GROUP      0x01

#define c_MAC_ADDRESS_OUI_INDIVIDUAL 0
#define c_MAC_ADDRESS_OUI_GROUP      1

// OUI local/global bit
//
#define c_MAC_ADDRESS_OUI_BM_LOCAL 0x02
#define c_MAC_ADDRESS_OUI_BS_LOCAL 1

#define c_MAC_ADDRESS_OUI_BV_GLOBAL 0x00
#define c_MAC_ADDRESS_OUI_BV_LOCAL  0x02

#define c_MAC_ADDRESS_OUI_GLOBAL 0
#define c_MAC_ADDRESS_OUI_LOCAL  1

// OUI multicast/unicast bit
//
#define c_MAC_ADDRESS_OUI_BM_MULTICAST c_MAC_ADDRESS_OUI_BM_GROUP
#define c_MAC_ADDRESS_OUI_BS_MULTICAST c_MAC_ADDRESS_OUI_BS_GROUP

#define c_MAC_ADDRESS_OUI_BV_UNICAST   c_MAC_ADDRESS_OUI_BV_INDIVIDUAL
#define c_MAC_ADDRESS_OUI_BV_MULTICAST c_MAC_ADDRESS_OUI_BV_GROUP

#define c_MAC_ADDRESS_OUI_UNICAST   c_MAC_ADDRESS_OUI_INDIVIDUAL
#define c_MAC_ADDRESS_OUI_MULTICAST c_MAC_ADDRESS_OUI_GROUP

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Struct: sMacAddress
//
// Author: $author$
//   Date: 8/20/2013
///////////////////////////////////////////////////////////////////////
#if defined(__MSC__)
// Visual C++
#pragma pack(push,1)
#define PACKED
#else // defined(__MSC__) 
// Gnu C++
#define PACKED __attribute__ ((packed))
#endif // defined(__MSC__) 
struct PACKED sMacAddress
{
    union {
        BYTE m_b[c_MAC_ADDRESS_SIZE];

        struct PACKED {
            struct PACKED {
                BYTE m_b[c_MAC_ADDRESS_SIZE/2];
            } m_oui;

            struct PACKED {
                BYTE m_b[c_MAC_ADDRESS_SIZE/2];
            } m_nic;
        };
    };
}
#if defined(__MSC__)
// Visual C++
#pragma pack(pop)
#else // defined(__MSC__) 
// Gnu C++
#undef PACKED
#endif // defined(__MSC__) 
;

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
//  Class: cMacAddress
//
// Author: $author$
//   Date: 11/28/2019
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cMacAddress
: virtual public cImplement, public cExtend {
public:
    typedef cImplement cImplements;
    typedef cExtend cExtends;

    sMacAddress m_macAddress;
    cString m_adapterName;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: cMacAddress
    //
    //      Author: $author$
    //        Date: 11/28/2019
    ///////////////////////////////////////////////////////////////////////
    cMacAddress() {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~cMacAddress
    //
    //     Author: $author$
    //       Date: 11/28/2019
    ///////////////////////////////////////////////////////////////////////
    virtual ~cMacAddress() {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: GetCurrent
    //
    //   Author: $author$
    //     Date: 11/28/2019
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetCurrent(const char* adapterName = 0) {
        bool success = false;
#if defined(WINDOWS)
//
// Windows
//
#else // defined(WINDOWS)
#if defined(MACOSX)
//
// Mac OSX
//
        struct ifaddrs *ifa = 0;  
        struct sockaddr_dl* dl = 0;
        LONG length = 0;
        int err = 0, unequal = 0;
        sMacAddress macAddress;

        if (adapterName) {
            if (0 > (length = m_adapterName.Assign(adapterName))) {
                return false;
            }
        }
        ::memset(macAddress.m_b, 0, sizeof(m_macAddress.m_b));

        c_DB_FUNC("::getifaddrs(&ifa)...");
        if (!(err = ::getifaddrs(&ifa))) {

            c_DB_FUNC("...::getifaddrs(&ifa)");
            for (success = false; ifa; ifa = ifa->ifa_next) {  

                if ((dl = (struct sockaddr_dl*)(ifa->ifa_addr))) {

                    if (0 < (dl->sdl_nlen)) {  

                        if (!(::memcmp(macAddress.m_b, (const void*)(LLADDR(dl)), sizeof(m_macAddress.m_b)))) {
                            continue;
                        }
                        if (adapterName) {
                            if ((unequal = m_adapterName.Compare(dl->sdl_data, dl->sdl_nlen))) {
                                continue;
                            }
                        }
                        if (0 > (length = m_adapterName.Assign(dl->sdl_data, dl->sdl_nlen))) {
                            break;
                        }
                        c_DB_FUNC("() ...found MAC of \"" << m_adapterName << "\"\n");
                        ::memcpy(m_macAddress.m_b, (const void*)(LLADDR(dl)), sizeof(m_macAddress.m_b));
                        success = true;
                        break;
                    }
                }
            }
        } else {
            c_DB_ERROR("() ...failed on ::getifaddrs()");
        }
#else // defined(MACOSX)
//
// Unix
//
#endif // defined(MACOSX)
#endif // defined(WINDOWS)
        return success;
    }

    ///////////////////////////////////////////////////////////////////////
    // Bytes
    ///////////////////////////////////////////////////////////////////////
    virtual const BYTE* Bytes(ssize_t& length) const {
        length = sizeof(m_macAddress.m_b);
        return m_macAddress.m_b;
    }
};

#if defined(WINDOWS)
//
// Windows
//
#else // defined(WINDOWS)
#if defined(MACOSX)
//
// Mac OSX
//
#else // defined(MACOSX)
//
// Unix
//
#endif // defined(MACOSX)
#endif // defined(WINDOWS)

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _CMACADDRESS_HPP 
