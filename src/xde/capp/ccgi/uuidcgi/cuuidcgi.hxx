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
 *   File: cuuidcgi.hxx
 *
 * Author: $author$
 *   Date: 3/2/2020
 **********************************************************************
 */
#ifndef CUUIDCGI_HXX
#define CUUIDCGI_HXX

#include "ccgi.hxx"
#include "cifra/universal/unique/actual/identifier.hpp"
#include "cifra/universal/unique/identifier.hpp"
#include "cifra/universal/unique/os/identifier.hpp"

/**
 **********************************************************************
 * Class: cUUIDCGI
 *
 * Author: $author$
 *   Date: 3/2/2020
 **********************************************************************
 */
class cUUIDCGI: public cCGI {
public:
    typedef cCGI cExtends;
    typedef cUUIDCGI cDerives;
    /**
     **********************************************************************
     * Constructor: cUUIDCGI / Destructor: ~cUUIDCGI
     **********************************************************************
     */
    cUUIDCGI() {
    }
    virtual ~cUUIDCGI() {
    }
    /**
     **********************************************************************
     * Function: RunCommandOrCGI
     **********************************************************************
     */
    virtual int RunCommandOrCGI(int argc, const char** argv, const char** env) {
        int err = 0;
        const char *name = 0, *value = 0;
        TLENGTH namelen = 0, valuelen = 0;
        cifra::universal::unique::actual::identifier *uuid = 0;
        cifra::universal::unique::os::identifier identifier;
        cHTTPFormFieldIterator i, end;
        cHTTPFormFieldReference f;

        if ((i = m_formFields.begin()) != (end = m_formFields.end())) {
            do {
                if ((f = (*i)) && (name = f->GetName(namelen)) && (value = f->GetValue(valuelen))) {
                    cString nameof(name, namelen);

                    if ((0 == (nameof.Compare("content_type"))) && (0 < (valuelen))) {
                        cString valueof(value, valuelen);
                        const char* chars = 0;
                        
                        if ((0 == (valueof.Compare(chars = GetContentTypeHTML())))) {
                            value = chars;
                        } else {
                            if ((0 == (valueof.Compare(chars = GetContentTypeXML())))) {
                                value = chars;
                            } else {
                                if ((0 == (valueof.Compare(chars = GetContentTypeText())))) {
                                    value = chars;
                                } else {
                                }
                            }
                        }
                        SetContentType(value);
                    }
                }
            } while ((++i) != end);
        }
        OutputContentType(GetContentType());
        
        if ((uuid = identifier.generate())) {
            const char *chars = 0;
            
            if ((chars = identifier.string().has_chars())) {
                OutputContentL(B_, chars, _B, NULL_POINTER);
            }
        }
        return err;
    }
}; /* class cUUIDCGI */

#endif /* ndef CUUIDCGI_HXX */
