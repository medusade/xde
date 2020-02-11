///////////////////////////////////////////////////////////////////////
// Copyright (c) 1988-2019 $organization$
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
//   File: cMacAddressMain.hpp
//
// Author: $author$
//   Date: 12/16/2019
///////////////////////////////////////////////////////////////////////
#ifndef _CMACADDRESSMAIN_HPP
#define _CMACADDRESSMAIN_HPP

#include "cOptMain.hpp"
#include "cMacAddress.hpp"
#include "cMacAddressString.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
//  Class: cMacAddressMain
//
// Author: $author$
//   Date: 12/16/2019
///////////////////////////////////////////////////////////////////////
class cMacAddressMain: public cOptMain {
public:
    typedef cOptMain cExtends;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: cMacAddressMain
    //
    //      Author: $author$
    //        Date: 12/16/2019
    ///////////////////////////////////////////////////////////////////////
    cMacAddressMain() {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~cMacAddressMain
    //
    //     Author: $author$
    //       Date: 12/16/2019
    ///////////////////////////////////////////////////////////////////////
    virtual ~cMacAddressMain() {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Run
    //
    //   Author: $author$
    //     Date: 12/16/2019
    ///////////////////////////////////////////////////////////////////////
    virtual int Run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const char_t* adapterName = 0;
        cMacAddress macAddress;
        cMacAddressString macAddressString;
        
        if ((1 < (argc)) && (optind < argc)) {
            if ((adapterName = argv[optind])) {
                if (!(adapterName[0])) {
                    adapterName = 0;
                }
            }
        }
        c_DB_INFO("() macAddress.GetCurrent(adapterName = " << ((adapterName)?("\""):("")) << ((adapterName)?(adapterName):("0")) << ((adapterName)?("\""):("")) << ")...");
        if ((macAddress.GetCurrent(adapterName))) {
            c_DB_INFO("() ...macAddress.GetCurrent(adapterName = " << ((adapterName)?("\""):("")) << ((adapterName)?(adapterName):("0")) << ((adapterName)?("\""):("")) << ")");
            macAddressString.Assign(macAddress);
            this->OutL(macAddressString.Chars(), "\n", NULL);
        }
        return err;
    }
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _CMACADDRESSMAIN_HPP 

