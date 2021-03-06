/**
 **********************************************************************
 * Copyright (c) 1988-2017 $organization$
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
 *   File: cxsltransformerinstance.cxx
 *
 * Author: $author$
 *   Date: 12/10/2017
 **********************************************************************
 */
#include "cxsltransformerinstance.hxx"

/**
 **********************************************************************
 *  Class: cXSLTransformerInstance
 *
 * Author: $author$
 *   Date: 12/10/2017
 **********************************************************************
 */

/**
 **********************************************************************
 *  Class: cXSLTransformerInterface
 *
 * Author: $author$
 *   Date: 3/13/2008
 **********************************************************************
 */
/**
 **********************************************************************
 * Function: CreateInstance
 *
 *   Author: $author$
 *     Date: 3/13/2008
 **********************************************************************
 */
cXSLTransformerInterface* cXSLTransformerInterface::CreateInstance(eError &error)
{
    cXSLTransformerInterface* xslt = 0;
    xslt = new cXSLTransformerBase();
    return xslt;
}
/**
 **********************************************************************
 * Function: DestroyInstance
 *
 *   Author: $author$
 *     Date: 3/13/2008
 **********************************************************************
 */
eError cXSLTransformerInterface::DestroyInstance(cXSLTransformerInterface &instance)
{
    delete &instance;
    return e_ERROR_NONE;
}
