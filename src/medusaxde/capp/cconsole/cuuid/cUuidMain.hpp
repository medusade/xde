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
//   File: cUuidMain.hpp
//
// Author: $author$
//   Date: 11/28/2019
///////////////////////////////////////////////////////////////////////
#ifndef _CUUIDMAIN_HPP
#define _CUUIDMAIN_HPP

#include "cUuid.hpp"
#include "cOptMain.hpp"

#define CUUID_INVALID_UUID_STRING_0 "00000000-0000-0000-0000-000000000000"
#define CUUID_INVALID_UUID_STRING_F "FFFFFFFF-FFFF-FFFF-FFFF-FFFFFFFFFFFF"
#define CUUID_INVALID_UUID_STRING_f "ffffffff-ffff-ffff-ffff-ffffffffffff"
#define CUUID_INVALID_UUID_STRING CUUID_INVALID_UUID_STRING_0

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
//  Class: cUuidMain
//
// Author: $author$
//   Date: 11/28/2019
///////////////////////////////////////////////////////////////////////
class cUuidMain: public cOptMain {
public:
    typedef cOptMain cExtends;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: cUuidMain
    //
    //      Author: $author$
    //        Date: 11/28/2019
    ///////////////////////////////////////////////////////////////////////
    cUuidMain() {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~cUuidMain
    //
    //     Author: $author$
    //       Date: 11/28/2019
    ///////////////////////////////////////////////////////////////////////
    virtual ~cUuidMain() {
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: Run
    //
    //   Author: $author$
    //     Date: 11/28/2019
    ///////////////////////////////////////////////////////////////////////
    virtual int Run(int argc, char_t** argv, char** env) {
        int err = 0;
        cString uuidString(CUUID_INVALID_UUID_STRING);
        cUuid uuid;

        c_DB_FUNC("() uuid.Generate()...");
        if ((uuid.Generate())) {
            c_DB_FUNC("() ...uuid.Generate()");
        } else {
            c_DB_ERROR("() ...failed on uuid.Generate()");
        }
        OutL(uuidString.c_str(), "\n", NULL);
        return err;
    }
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // ndef _CUUIDMAIN_HPP
