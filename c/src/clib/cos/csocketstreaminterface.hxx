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
 *   File: csocketstreaminterface.hxx
 *
 * Author: $author$
 *   Date: 2/19/2008
 **********************************************************************
 */
#ifndef _CSOCKETSTREAMINTERFACE_HXX
#define _CSOCKETSTREAMINTERFACE_HXX

#include "cstreaminterface.hxx"
#include "csocketattachedinterface.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cSocketStreamInterfaceT"
/**
 **********************************************************************
 *  Class: cSocketStreamInterfaceT
 *
 * Author: $author$
 *   Date: 2/19/2008
 **********************************************************************
 */
template
<class TWhat=CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TStreamImplements=cStreamInterface,
 class TAttachedImplements=cSocketAttachedInterface>
 
class c_INTERFACE_CLASS cSocketStreamInterfaceT
: virtual public TStreamImplements,
  virtual public TAttachedImplements
{
public:
    typedef TStreamImplements cStreamImplements;
    typedef TAttachedImplements cAttachedImplements;
    typedef cSocketStreamInterfaceT cDerives;
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Typedef: cSocketStreamInterface
 *
 *  Author: $author$
 *    Date: 2/19/2008
 **********************************************************************
 */
typedef cSocketStreamInterfaceT
<CHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH,
 cStreamInterface,cSocketAttachedInterface>
cSocketStreamInterface;

/**
 **********************************************************************
 *  Typedef: cCharSocketStreamInterface
 *
 *  Author: $author$
 *    Date: 2/19/2008
 **********************************************************************
 */
typedef cSocketStreamInterfaceT
<char, TSIZE, TLENGTH, UNDEFINED_LENGTH,
 cCharStreamInterface, cSocketAttachedInterface>
cCharSocketStreamInterface;

/**
 **********************************************************************
 *  Typedef: cBYTESocketStreamInterface
 *
 *  Author: $author$
 *    Date: 2/19/2008
 **********************************************************************
 */
typedef cSocketStreamInterfaceT
<BYTE, TSIZE, TLENGTH, UNDEFINED_LENGTH,
 cBYTEStreamInterface, cSocketAttachedInterface>
cBYTESocketStreamInterface;

/**
 **********************************************************************
 *  Typedef: cTCHARSocketStreamInterface
 *
 *  Author: $author$
 *    Date: 2/19/2008
 **********************************************************************
 */
typedef cSocketStreamInterfaceT
<TCHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH,
 cTCHARStreamInterface, cSocketAttachedInterface>
cTCHARSocketStreamInterface;

/**
 **********************************************************************
 *  Typedef: cWCHARSocketStreamInterface
 *
 *  Author: $author$
 *    Date: 2/19/2008
 **********************************************************************
 */
typedef cSocketStreamInterfaceT
<WCHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH,
 cWCHARStreamInterface, cSocketAttachedInterface>
cWCHARSocketStreamInterface;

#endif /* _CSOCKETSTREAMINTERFACE_HXX */
