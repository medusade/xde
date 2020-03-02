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
 *   File: ctparsefunction.hxx
 *
 * Author: $author$
 *   Date: 2/14/2020
 **********************************************************************
 */
#ifndef CTPARSEFUNCTION_HXX
#define CTPARSEFUNCTION_HXX

#include "ctfunction.hxx"
#include "cstring.hxx"

/**
 **********************************************************************
 * Class: cTParseFunction
 *
 * Author: $author$
 *   Date: 2/14/2020
 **********************************************************************
 */
class cTParseFunction: public cTFunction {
public:
    typedef cTFunction cExtends;
    typedef cTParseFunction cDerives;
    /**
     **********************************************************************
     * Constructor: cTParseFunction
     *
     * Author: $author$
     *   Date: 2/14/2020
     **********************************************************************
     */
    cTParseFunction(const char* name, const char* description): cExtends(name, description) {
        static cTFunctionParameter parameter[] = {
        {"string","string to parse"},
        {"delim","token delimiter"},
        {"(before)","do before each token"},
        {"(between)","do between each token"},
        {"(after)","do after each token"},
        {"(do)","do for each token"},
        {"var","variable set to each token"},
        {0,0}};
        this->m_parameters = ((sizeof(parameter) / sizeof(cTFunctionParameter)) - 1);
        this->m_parameter = parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     * Author: $author$
     *   Date: 2/14/2020
     **********************************************************************
     */
    virtual eError Expand
    (cCharStreamInterface &result, cTInterface &t, const cTFunctionArgumentList& arglist) const {
        return e_ERROR_NONE;
    }
}; /* class cTParseFunction */

#endif /* CTPARSEFUNCTION_HXX /*/
