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
 *   File: ctfunctionfunction.hxx
 *
 * Author: $author$
 *   Date: 2/14/2020
 **********************************************************************
 */
#ifndef CTFUNCTIONFUNCTION_HXX
#define CTFUNCTIONFUNCTION_HXX

#include "ctfunction.hxx"
#include "cstring.hxx"

/**
 **********************************************************************
 * Class: cTFunctionFunction
 *
 * Author: $author$
 *   Date: 2/14/2020
 **********************************************************************
 */
class cTFunctionFunction: public cTFunction {
public:
    typedef cTFunction cExtends;
    typedef cTFunctionFunction cDerives;
    /**
     **********************************************************************
     * Constructor: cTFunctionFunction
     *
     * Author: $author$
     *   Date: 2/14/2020
     **********************************************************************
     */
    cTFunctionFunction(const char* name, const char* description): cExtends(name, description) {
        static cTFunctionParameter parameter[] = {
        {"[name]","Name of function"},
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
        const char* chars = 0; TLENGTH length = 0;
        cTFunctionArgument* arg = 0; 

        if ((arg = arglist.GetFirstItem())) {
            if ((chars = arg->GetBuffer(length)) && (0 < (length))) {
                const cTFunctionParameter* parameter = 0; int parameters = 0;
                cTFunctionInterface* function = 0; 

                if ((function = t.FindFunction(chars, length))) {
                    if ((chars = function->GetDescription(parameter, parameters))) {
                        result.WriteL(chars, "\n", NULL);
                        if ((parameter) && (0 < (parameters))) {
                            for (; 0 < (parameters); --parameters, ++parameter) {
                                if ((chars = parameter->GetName())) {
                                    result.WriteL(" ", chars, NULL);
                                }
                                if ((chars = parameter->GetDescription()) && (chars[0])) {
                                    result.WriteL(" ", chars, NULL);
                                }
                                result.WriteL("\n", NULL);
                            }
                        }
                    }
                }
            }
        }
        return e_ERROR_NONE;
    }
}; /* class cTFunctionFunction */

#endif /* CTFUNCTIONFUNCTION_HXX /*/
