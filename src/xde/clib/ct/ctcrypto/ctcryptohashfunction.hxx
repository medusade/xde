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
 *   File: ctcryptohashfunction.hxx
 *
 * Author: $author$
 *   Date: 2/7/2020
 **********************************************************************
 */
#ifndef CTCRYPTOHASHFUNCTION_HXX
#define CTCRYPTOHASHFUNCTION_HXX

#include "ctfunction.hxx"
#include "ccryptohash.hxx"

/**
 **********************************************************************
 *  Class: cTCryptoHashFunction
 *
 * Author: $author$
 *   Date: 2/7/2020
 **********************************************************************
 */
class cTCryptoHashFunction: public cTFunction {
public:
    typedef cTFunction cExtends;
    typedef cTCryptoHashFunction cDerives;
    /**
     **********************************************************************
     * Constructor: cTCryptoHashFunction
     *
     *      Author: $author$
     *        Date: 2/7/2020
     **********************************************************************
     */
    cTCryptoHashFunction(const char* name, const char* description): cExtends(name, description) {
        static cTFunctionParameter parameter[] = {
        {"string,...",""},
        {0,0}};
        this->m_parameters = ((sizeof(parameter) / sizeof(cTFunctionParameter)) - 1);
        this->m_parameter = parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 2/7/2020
     **********************************************************************
     */
    virtual eError Expand
    (cCharStreamInterface &result, cTInterface &t, const cTFunctionArgumentList& arglist, cCryptoHash& hash) const {
        BYTE* bytes = 0; const char* chars = 0; TLENGTH count = 0; TLENGTH length = 0;
        cBYTEBuffer buffer; cCryptoString string;

        if (0 < (length = hash.Size())) {
            if (length <= (count = buffer.SetLength(length))) {
                if ((bytes = buffer.GetWriteBuffer(count))) {
                    if (0 <= (count = hash.Initialize())) {
                        TSIZE size = 0;
                        
                        for (cTFunctionArgument *arg = arglist.GetFirstItem(); arg; arg = arg->GetNextItem()) {
                            if ((chars = arg->GetBuffer(size, count))) {
                                if (0 <= (count = hash.Hash(chars, count))) {
                                }
                            }
                        }
                        if (0 <= (count = hash.Finalize(bytes, length))) {
                            if (0 <= (count = string.AssignHex(bytes, count))) {
                                if ((chars = string.HasChars(count))) {
                                    count = result.Write(chars, count);
                                }
                            }
                        }
                    }
                }
            }
        }
        return e_ERROR_NONE;
    }
}; /* class cTCryptoHashFunction */

/**
 **********************************************************************
 *  Class: cTCryptoHashFunctionT
 *
 * Author: $author$
 *   Date: 2/7/2020
 **********************************************************************
 */
template <class THash>
class cTCryptoHashFunctionT: public cTCryptoHashFunction {
public:
    typedef cTCryptoHashFunction cExtends;
    typedef cTCryptoHashFunctionT cDerives;
    /**
     **********************************************************************
     * Constructor: cTCryptoHashFunctionT
     *
     *      Author: $author$
     *        Date: 2/7/2020
     **********************************************************************
     */
    cTCryptoHashFunctionT(const char* name, const char* description): cExtends(name, description) {
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 2/7/2020
     **********************************************************************
     */
    using cExtends::Expand;
    virtual eError Expand
    (cCharStreamInterface &result, cTInterface &t, const cTFunctionArgumentList& arglist) const {
        THash hash; eError error = Expand(result, t, arglist, hash);
        return error;
    }
}; /* cTCryptoHashFunctionT */

#endif /* CTCRYPTOHASHFUNCTION_HXX /*/
