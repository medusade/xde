///////////////////////////////////////////////////////////////////////
// Copyright (c) 1988-2020 $organization$
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
//   File: cMacAddressString.hpp
//
// Author: $author$
//   Date: 1/24/2020
///////////////////////////////////////////////////////////////////////
#ifndef _CMACADDRESSSTRING_HPP
#define _CMACADDRESSSTRING_HPP

#include "cMacAddress.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
//  Class: cMacAddressString
//
// Author: $author$
//   Date: 1/24/2020
///////////////////////////////////////////////////////////////////////
class cMacAddressString: public cString {
public:
    typedef cString cExtends;

    ///////////////////////////////////////////////////////////////////////
    // Constructors
    ///////////////////////////////////////////////////////////////////////
    cMacAddressString(const cMacAddress& mac) {
        Append(mac);
    }
    cMacAddressString(const cString& copy): cExtends(copy) {
    }
    cMacAddressString() {
    }

    ///////////////////////////////////////////////////////////////////////
    // Assign / Append
    ///////////////////////////////////////////////////////////////////////
    using cExtends::Assign;
    virtual ssize_t Assign(const cMacAddress& mac) {
        Clear();
        return Append(mac);
    }
    using cExtends::Append;
    virtual ssize_t Append(const cMacAddress& mac) {
        ssize_t count = 0, amount = 0, length = 0;
        const BYTE* bytes = 0;
        if ((bytes = mac.Bytes(length))) {
            char_t chars[3] = {'X', 'X', ':'};
            if ((BtoX(chars, *bytes))) {
                Append(chars, 2);
            }
            for (++bytes, --length; 0 < length; --length, ++bytes) {
                if ((BtoX(chars, *bytes))) {
                    Append(chars + 2, 1);
                    Append(chars, 2);
                }
            }
        }
        return count;
    }
    
    ///////////////////////////////////////////////////////////////////////
    // BtoX
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* BtoX(char_t chars[3], BYTE byte) const {
        BYTE nibble1 = ((byte >> 4) & 15), nibble2 = (byte & 15);
        chars[0] = BtoX(nibble1);
        chars[1] = BtoX(nibble2);
        return chars;
    }
    virtual char_t BtoX(BYTE byte) const {
        char_t nibble = (byte < 10)?('0' + byte):((byte < 16)?('A' + (byte - 10)):('X'));
        return nibble;
    }
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _CMACADDRESSSTRING_HPP 
