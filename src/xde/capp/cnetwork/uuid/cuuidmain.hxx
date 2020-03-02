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
 *   File: cuuidmain.hxx
 *
 * Author: $author$
 *   Date: 2/29/2020
 **********************************************************************
 */
#ifndef CUUIDMAIN_HXX
#define CUUIDMAIN_HXX

#include "cargmain.hxx"
#include "cifra/universal/unique/actual/identifier.hpp"
#include "cifra/universal/unique/identifier.hpp"
#include "cifra/universal/unique/os/identifier.hpp"

/**
 **********************************************************************
 * Class: cUUIDMain
 *
 * Author: $author$
 *   Date: 2/29/2020
 **********************************************************************
 */
class cUUIDMain: public cArgMain {
public:
    typedef cArgMain cExtends;
    typedef cUUIDMain cDerives;
    /**
     **********************************************************************
     * Constructor: cUUIDMain / Destructor: ~cUUIDMain
     **********************************************************************
     */
    cUUIDMain() {
    }
    virtual ~cUUIDMain() {
    }
    /**
     **********************************************************************
     * Function: Run
     **********************************************************************
     */
    virtual int Run(int argc, const char** argv, const char** env) {
        int err = 0;
        cifra::universal::unique::actual::identifier *uuid = 0;
        cifra::universal::unique::os::identifier identifier;

        if ((uuid = identifier.generate())) {
            const char *chars = 0; size_t length = 0;
            
            if ((chars = identifier.string().has_chars(length))) {
                this->Out(chars, length);
            }
        }
        return err;
    }
}; /* class cUUIDMain */

#endif /* ndef CUUIDMAIN_HXX */
