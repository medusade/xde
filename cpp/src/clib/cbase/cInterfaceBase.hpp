///////////////////////////////////////////////////////////////////////
// Copyright (c) 1988-2011 $organization$
//
// This software is provided by the author and contributors ``as is'' 
// and any express or implied warranties, including, but not limited to, 
// the implied warranties of merchantability and fitness for a particular 
// purpose are disclaimed. In no event shall the author or contributors 
// be liable for any direct, indirect, incidental, special, exemplary, 
// or consequential damages (including, but not limited to, procurement 
// of substitute goods or services; loss of use, data, or profits; or 
// business interruption) however caused and on any theory of liability, 
// whether in contract, strict liability, or tort (including negligence 
// or otherwise) arising in any way out of the use of this software, 
// even if advised of the possibility of such damage.
//
//   File: cInterfaceBase.hpp
//
// Author: $author$
//   Date: 3/13/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CINTERFACEBASE_HPP) || defined(CINTERFACEBASE_MEMBERS_ONLY)
#if !defined(_CINTERFACEBASE_HPP) && !defined(CINTERFACEBASE_MEMBERS_ONLY)
#define _CINTERFACEBASE_HPP
#endif // !defined(_CINTERFACEBASE_HPP) && !defined(CINTERFACEBASE_MEMBERS_ONLY) 

#if !defined(CINTERFACEBASE_MEMBERS_ONLY)
#include "cError.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
//  Class: cInterfaceBase
//
// Author: $author$
//   Date: 3/13/2011
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cInterfaceBase
{
public:
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cInterfaceBase
    //
    //      Author: $author$
    //        Date: 12/11/2017
    ///////////////////////////////////////////////////////////////////////
    virtual ~cInterfaceBase()
    {
    }
#else // !defined(CINTERFACEBASE_MEMBERS_ONLY) 
#endif // !defined(CINTERFACEBASE_MEMBERS_ONLY) 

#if !defined(CINTERFACEBASE_MEMBERS_ONLY)
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CINTERFACEBASE_MEMBERS_ONLY) 
#endif // !defined(CINTERFACEBASE_MEMBERS_ONLY) 

#endif // !defined(_CINTERFACEBASE_HPP) || defined(CINTERFACEBASE_MEMBERS_ONLY) 
