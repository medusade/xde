///////////////////////////////////////////////////////////////////////
// Copyright (c) 1988-2013 $organization$
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
//   File: cBases.hpp
//
// Author: $author$
//   Date: 8/20/2013
///////////////////////////////////////////////////////////////////////
#ifndef _CBASES_HPP
#define _CBASES_HPP

#include "cInterfaceBase.hpp"
#include "cImplementBase.hpp"
#include "cInstanceBase.hpp"
#include "cExportBase.hpp"
#include "cBase.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
//  Class: cImplement
//
// Author: $author$
//   Date: 11/28/2019
///////////////////////////////////////////////////////////////////////
class c_IMPLEMENT_CLASS cImplement: virtual public cImplementBase {
public:
    typedef cImplementBase cImplements;
};

///////////////////////////////////////////////////////////////////////
//  Class: cExtend
//
// Author: $author$
//   Date: 11/28/2019
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cExtend: virtual public cImplement, public cExportBase {
public:
    typedef cImplement cImplements;
    typedef cExportBase cExtends;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: cExtend
    //
    //      Author: $author$
    //        Date: 11/28/2019
    ///////////////////////////////////////////////////////////////////////
    cExtend() {
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~cExtend
    //
    //     Author: $author$
    //       Date: 11/28/2019
    ///////////////////////////////////////////////////////////////////////
    virtual ~cExtend() {
    }
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _CBASES_HPP 
