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
 *   File: ctleftparsefunction.hxx
 *
 * Author: $author$
 *   Date: 2/13/2020
 **********************************************************************
 */
#ifndef CTLEFTPARSEFUNCTION_HXX
#define CTLEFTPARSEFUNCTION_HXX

#include "ctparsefunction.hxx"

/**
 **********************************************************************
 * Class: cTLeftParseFunction
 *
 * Author: $author$
 *   Date: 2/13/2020
 **********************************************************************
 */
class cTLeftParseFunction: public cTParseFunction {
public:
    typedef cTParseFunction cExtends;
    typedef cTLeftParseFunction cDerives;
    /**
     **********************************************************************
     * Constructor: cTLeftParseFunction
     *
     * Author: $author$
     *   Date: 2/13/2020
     **********************************************************************
     */
    cTLeftParseFunction(const char* name, const char* description): cExtends(name, description) {
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     * Author: $author$
     *   Date: 2/13/2020
     **********************************************************************
     */
    virtual eError Expand
    (cCharStreamInterface &result, cTInterface &t, const cTFunctionArgumentList& arglist) const {
        cTFunctionArgument *arg = 0, *before = 0, *between = 0, *after = 0, *expr = 0, *var = 0;
        const char *string = 0, *delim = 0, *token = 0, *name = 0;
        TLENGTH delimLength = 0, length = 0;
        cTVariableInterface *variable = 0;

        if ((arg = arglist.GetFirstItem())) {
            if ((string = arg->GetBuffer(length)) && (0 < (length))) {
                if ((arg = arg->GetNextItem())) {
                    if ((delim = arg->GetBuffer(delimLength)) && (0 < (delimLength))) {

                        if ((before = (arg = arg->GetNextItem()))) {                            
                            if ((between = (arg = arg->GetNextItem()))) {                            
                                if ((after = (arg = arg->GetNextItem()))) {
                                    if ((expr = (arg = arg->GetNextItem()))) {                            
                                        if (!(var = (arg = arg->GetNextItem()))) {
                                            var = expr;
                                            expr = after;
                                            after = 0;
                                        }
                                        if ((name = var->GetBuffer())) {
                                            variable = t.GetVariable(name);
                                        }
                                    }
                                }
                            }
                        }

                        while ((token = strstr(string, delim))) {
                            if (variable) {
                                variable->PushValue(string, (TLENGTH)(token-string));
                            }
                            if ((before)  && (0 < (length = before->GetLength())) && (0 <= (length = before->Seek(0)))) {
                                t.Expand(result, *before);
                            }
                            if (expr) {
                                if ((0 < (length = expr->GetLength())) && (0 <= (length = expr->Seek(0)))) {
                                    t.Expand(result, *expr);
                                }
                            } else {
                                result.Write(string, (TLENGTH)(token-string));
                            }
                            if ((string = token+delimLength)[0]) {
                                if ((between)  && (0 < (length = between->GetLength())) && (0 <= (length = between->Seek(0)))) {
                                    t.Expand(result, *between);
                                }
                            }
                            if ((after)  && (0 < (length = after->GetLength())) && (0 <= (length = after->Seek(0)))) {
                                t.Expand(result, *after);
                            }
                            if (variable) {
                                variable->PopValue();
                            }
                        }
                        if (string[0]) {
                            if (variable) {
                                variable->PushValue(string);
                            }
                            if ((before)  && (0 < (length = before->GetLength())) && (0 <= (length = before->Seek(0)))) {
                                t.Expand(result, *before);
                            }
                            if (expr) {
                                if ((0 < (length = expr->GetLength())) && (0 <= (length = expr->Seek(0)))) {
                                    t.Expand(result, *expr);
                                }
                            } else {
                                result.Write(string);
                            }
                            if ((after)  && (0 < (length = after->GetLength())) && (0 <= (length = after->Seek(0)))) {
                                t.Expand(result, *after);
                            }
                            if (variable) {
                                variable->PopValue();
                            }
                        }
                    }
                }
            }
        }
        return e_ERROR_NONE;
    }
}; /* class cTLeftParseFunction */

#endif /* CTLEFTPARSEFUNCTION_HXX /*/
