///////////////////////////////////////////////////////////////////////
//   File: evdll.hpp
//
// Author: $author$
//   Date: 4/11/2009
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _EVDLL_HPP
#define _EVDLL_HPP

#include "evplatform_dll.h"
#include "evreferenced.hpp"
#include "evattached.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: EvDllAttached
//
// Author: $author$
//   Date: 4/12/2009
///////////////////////////////////////////////////////////////////////
typedef EvAttached<DLL, EvBase> 
EvDllAttached;

///////////////////////////////////////////////////////////////////////
//  Class: EvDll
//
// Author: $author$
//   Date: 4/11/2009
///////////////////////////////////////////////////////////////////////
class EV_EXPORT_CLASS EvDll
: virtual public EvDllAttached
{
public:
    typedef EvDllAttached CImplements;
    typedef EvDll CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Function: Open
    //
    //   Author: $author$
    //     Date: 4/11/2009
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Open
    (const char* filename,
     bool resolve=true,
     bool global=false) = 0;
    ///////////////////////////////////////////////////////////////////////
    // Function: Close
    //
    //   Author: $author$
    //     Date: 4/11/2009
    ///////////////////////////////////////////////////////////////////////
    virtual EvError Close() = 0;
    ///////////////////////////////////////////////////////////////////////
    // Function: GetAddress
    //
    //   Author: $author$
    //     Date: 4/12/2009
    ///////////////////////////////////////////////////////////////////////
    virtual void* GetAddress
    (const char* symbol) const = 0;
};

#endif // _EVDLL_HPP
