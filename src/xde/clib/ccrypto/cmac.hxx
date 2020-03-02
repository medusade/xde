/**
 **********************************************************************
 * Copyright (c) 1988-2020 $organization$
 *
 * This software is provided by the author and contributors ``as is'' 
 * and any express or implied warranties, including, but not limited to, 
 * the implied warranties of merchantability and fitness for a particular 
 * purpose are disclaimed. In no event shall the author or contributors 
 * be liable for any direct, indirect, incidental, special, exemplary, 
 * or consequential damages (including, but not limited to, procurement 
 * of substitute goods or services; loss of use, data, or profits; or 
 * business interruption) however caused and on any theory of liability, 
 * whether in contract, strict liability, or tort (including negligence 
 * or otherwise) arising in any way out of the use of this software, 
 * even if advised of the possibility of such damage.
 *
 *   File: cmac.hxx
 *
 * Author: $author$
 *   Date: 2/12/2020
 **********************************************************************
 */
#ifndef CMAC_HXX
#define CMAC_HXX

#include "ccryptobase.hxx"
#include "cifra/network/ethernet/os/address.hpp"

/**
 **********************************************************************
 *  Class: cMac
 *
 * Author: $author$
 *   Date: 2/12/2020
 **********************************************************************
 */
class cMac: public cCryptoBase {
protected:
    cifra::network::ethernet::os::address m_address;
public:
    typedef cCryptoBase cExtends;
    typedef cMac cDerives;
    /**
     **********************************************************************
     * Constructor: cMac / Destructor: ~cMac
     *
     * Author: $author$
     *   Date: 2/12/2020
     **********************************************************************
     */
    cMac() {
    }
    virtual ~cMac() {
    }
    /**
     **********************************************************************
     * Function: GetAddress
     *
     * Author: $author$
     *   Date: 2/12/2020
     **********************************************************************
     */
    virtual BOOL GetAddress(cString& string, const cString& adapter) {
        if ((m_address.set_to_adapter(adapter))) {
            const char* chars = 0; size_t length = 0;
            if ((chars = m_address.actual_name().has_chars(length))) {
                string.Assign(chars, length);
                return TRUE;
            }
        }
        return FALSE;
    }
    virtual BOOL GetAddress(cString& string) {
        if ((m_address.set_to_adapter())) {
            const char* chars = 0; size_t length = 0;
            if ((chars = m_address.actual_name().has_chars(length))) {
                string.Assign(chars, length);
                return TRUE;
            }
        }
        return FALSE;
    }
    /**
     **********************************************************************
     * Function: GetAdapter
     *
     * Author: $author$
     *   Date: 2/12/2020
     **********************************************************************
     */
    virtual BOOL GetAdapter(cString& string, const cString& adapter) {
        const char* cchars = 0; TLENGTH clength = 0;
        if ((cchars = adapter.HasChars(clength))) {
            cifra::string_t cstring(cchars, clength);
            int index = cstring.to_int();
            if (0 <= (index)) {
                if ((m_address.set_to_adapter(index))) {
                    const char* chars = 0; size_t length = 0;
                    if ((chars = m_address.adapter_name().has_chars(length))) {
                        string.Assign(chars, length);
                        return TRUE;
                    }
                }
            }
        } else {
            return GetAdapter(string);
        }
        return FALSE;
    }
    virtual BOOL GetAdapter(cString& string) {
        if ((m_address.set_to_adapter())) {
            const char* chars = 0; size_t length = 0;
            if ((chars = m_address.adapter_name().has_chars(length))) {
                string.Assign(chars, length);
                return TRUE;
            }
        }
        return FALSE;
    }
}; /* class cMac */

#endif /* ndef CMAC_HXX */
