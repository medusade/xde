/**
 **********************************************************************
 * Copyright (c) 1988-2008 $organization$
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
 *   File: cxmldocumentnode.hxx
 *
 * Author: $author$
 *   Date: 11/18/2008
 **********************************************************************
 */
#ifndef _CXMLDOCUMENTNODE_HXX
#define _CXMLDOCUMENTNODE_HXX

#include "cxmldocumentnodeinterface.hxx"
#include "cxmlparentnode.hxx"
#include "cxmlnodelist.hxx"
#include "cxmlnode.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cXMLDocumentNodeT"
/**
 **********************************************************************
 *  Class: cXMLDocumentNodeT
 *
 * Author: $author$
 *   Date: 11/18/2008
 **********************************************************************
 */
template
<class TXMLNode=cXMLNode,
 class TXMLNodeList=cXMLNodeList,
 class TXMLParentNode=cXMLParentNode,
 class TXMLDocumentNode=cXMLDocumentNode,
 class TXMLDocumentNodeInterface=cXMLDocumentNodeInterface,
 class TXMLDocumentNodeImplement=cXMLDocumentNodeImplement,
 class TImplements=TXMLDocumentNodeImplement,
 class TExtends=TXMLParentNode>
 
class cXMLDocumentNodeT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef cXMLDocumentNodeT cDerives;

    /**
     **********************************************************************
     * Constructor: cXMLDocumentNodeT
     *
     *      Author: $author$
     *        Date: 11/18/2008
     **********************************************************************
     */
    cXMLDocumentNodeT() 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cXMLDocumentNodeT
     *
     *     Author: $author$
     *       Date: 11/18/2008
     **********************************************************************
     */
    virtual ~cXMLDocumentNodeT()
    {
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cXMLDocumentNode
 *
 * Author: $author$
 *   Date: 11/18/2008
 **********************************************************************
 */
class cXMLDocumentNode
: public cXMLDocumentNodeT<>
{
public:
    typedef cXMLDocumentNodeT<> cExtends;
    typedef cXMLDocumentNode cDerives;
    /**
     **********************************************************************
     * Constructor: cXMLDocumentNode
     *
     *      Author: $author$
     *        Date: 11/18/2008
     **********************************************************************
     */
    cXMLDocumentNode()
    {
    }
};

#endif /* _CXMLDOCUMENTNODE_HXX */
