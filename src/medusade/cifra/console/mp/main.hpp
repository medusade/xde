///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2018 $organization$
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
///   Date: 3/14/2018
///////////////////////////////////////////////////////////////////////
#ifndef _CIFRA_CONSOLE_MP_MAIN_HPP
#define _CIFRA_CONSOLE_MP_MAIN_HPP

#include "cifra/console/mp/main_opt.hpp"

namespace cifra {
namespace console {
namespace mp {

typedef main_optt_implements maint_implements;
typedef main_opt maint_extends;
///////////////////////////////////////////////////////////////////////
///  Class: maint
///////////////////////////////////////////////////////////////////////
template
<class TImplements = maint_implements, class TExtends = maint_extends>

class _EXPORT_CLASS maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    maint() {
    }
    virtual ~maint() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual size_t random(unsigned char *buff, size_t len) const {
        static unsigned randnum = 0;
        static unsigned avail = 0;
        size_t i=0;
        
        for (i=0; i<len;) {
            if (avail<1) {
                randnum=(unsigned)rand();
                avail=sizeof(randnum);
            }
            if ((buff[i]=(char)(randnum&255))!=0) {
                i++;
            }
            if ((randnum>>=8)<1) {
                avail=0;
            } else {
                avail--;
            }
        }
        return i;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual size_t size_of(const unsigned char *buff, size_t len) const {
        for (size_t i=0; len>0; i++, --len) {
            if (buff[i]) {
                return len;
            }
        }
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef maint<> main;

} // namespace mp 
} // namespace console 
} // namespace cifra 

#endif // _CIFRA_CONSOLE_MP_MAIN_HPP 
