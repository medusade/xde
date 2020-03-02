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
 *   File: ctmacfunction.hxx
 *
 * Author: $author$
 *   Date: 2/12/2020
 **********************************************************************
 */
#ifndef CTMACFUNCTION_HXX
#define CTMACFUNCTION_HXX

#include "ctfunction.hxx"
#include "cmac.hxx"

/**
 **********************************************************************
 * Class: cTMacFunction
 *
 * Author: $author$
 *   Date: 2/12/2020
 **********************************************************************
 */
class cTMacFunction: public cTFunction {
protected:
    BOOL m_getAdapter;
public:
    typedef cTFunction cExtends;
    typedef cTMacFunction cDerives;
    /**
     **********************************************************************
     * Constructor: cTMacFunction
     *
     * Author: $author$
     *   Date: 2/12/2020
     **********************************************************************
     */
    cTMacFunction(const char* name, const char* description, BOOL getAdapter = false): cExtends(name, description), m_getAdapter(getAdapter) {
        static cTFunctionParameter parameter[] = {
        {"[en]", "ethernet adapter name"},
        {0,0}};
        static cTFunctionParameter adapter_parameter[] = {
        {"[index]", "ethernet adapter index"},
        {0,0}};
        if (getAdapter) {
            this->m_parameters = ((sizeof(adapter_parameter) / sizeof(cTFunctionParameter)) - 1);
            this->m_parameter = adapter_parameter;
        } else {
            this->m_parameters = ((sizeof(parameter) / sizeof(cTFunctionParameter)) - 1);
            this->m_parameter = parameter;
        }
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     * Author: $author$
     *   Date: 2/12/2020
     **********************************************************************
     */
    virtual eError Expand
    (cCharStreamInterface &result, cTInterface &t, const cTFunctionArgumentList& arglist) const {
        cTFunctionArgument* arg = 0; const char* chars = 0; TLENGTH length = 0; cString string; cMac mac;
        if ((arg = arglist.GetFirstItem())) {
            TSIZE size = 0; 
            if ((chars = arg->GetBuffer(size, length))) {
                string.Assign(chars, length);
            }
        }
        if (m_getAdapter) {
            if ((mac.GetAdapter(string, string))) {
                if ((chars = string.HasChars(length))) {
                    result.Write(chars, length);
                }
            }
        } else {
            if ((mac.GetAddress(string, string))) {
                if ((chars = string.HasChars(length))) {
                    result.Write(chars, length);
                }
            }
        }
        return e_ERROR_NONE;
    }
}; /* class cTMacFunction */

#endif /* CTMACFUNCTION_HXX /*/
