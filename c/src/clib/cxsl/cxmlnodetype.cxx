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
 *   File: cxmlnodetype.cxx
 *
 * Author: $author$
 *   Date: 12/10/2017
 **********************************************************************
 */
#include "cxmlnodetype.hxx"

/**
 **********************************************************************
 *   Enum: eXMLNodeType
 *
 * Author: $author$
 *   Date: 3/15/2008
 **********************************************************************
 */
const char* eXMLNodeTypeName[e_COUNT_XML_NODE_TYPE] = 
{
    e_XML_NODE_TYPE_NAME_NONE,
    e_XML_NODE_TYPE_NAME_ELEMENT,
    e_XML_NODE_TYPE_NAME_ATTRIBUTE,
    e_XML_NODE_TYPE_NAME_TEXT,
    e_XML_NODE_TYPE_NAME_CDATA_SECTION,
    e_XML_NODE_TYPE_NAME_ENTITY_REFERENCE,
    e_XML_NODE_TYPE_NAME_ENTITY,
    e_XML_NODE_TYPE_NAME_PROCESSING_INSTRUCTION,
    e_XML_NODE_TYPE_NAME_COMMENT,
    e_XML_NODE_TYPE_NAME_DOCUMENT,
    e_XML_NODE_TYPE_NAME_DOCUMENT_TYPE,
    e_XML_NODE_TYPE_NAME_DOCUMENT_FRAGMENT,
    e_XML_NODE_TYPE_NAME_NOTATION
};

/**
 **********************************************************************
 *  Class: cXMLNodeType
 *
 * Author: $author$
 *   Date: 12/10/2017
 **********************************************************************
 */
