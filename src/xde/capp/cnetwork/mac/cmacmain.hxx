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
 *   File: cmacmain.hxx
 *
 * Author: $author$
 *   Date: 2/28/2020
 **********************************************************************
 */
#ifndef CMACMAIN_HXX
#define CMACMAIN_HXX

#include "cargmain.hxx"
#include "cifra/network/ethernet/actual/address.hpp"
#include "cifra/network/ethernet/address.hpp"
#include "cifra/network/ethernet/posix/address.hpp"

/**
 **********************************************************************
 * Class: cMACMain
 *
 * Author: $author$
 *   Date: 2/28/2020
 **********************************************************************
 */
class cMACMain: public cArgMain {
public:
    typedef cArgMain cExtends;
    typedef cMACMain cDerives;
    /**
     **********************************************************************
     * Constructor: cMACMain / Destructor: ~cMACMain
     **********************************************************************
     */
    cMACMain() {
    }
    virtual ~cMACMain() {
    }
    /**
     **********************************************************************
     * Function: Run
     **********************************************************************
     */
    virtual int Run(int argc, const char** argv, const char** env) {
        int err = 0;
        cifra::network::ethernet::actual::address *mac = 0;
        cifra::network::ethernet::posix::address address;

        if ((mac = address.set_to_adapter())) {
            const char *chars = 0; size_t length = 0;
            
            if ((chars = address.string().has_chars(length))) {
                this->Out(chars, length);
            }
        }
        return err;
    }
}; /* class cMACMain */

#endif /* ndef CMACMAIN_HXX */
