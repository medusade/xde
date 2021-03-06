///////////////////////////////////////////////////////////////////////
//   File: cevutctime.hpp
//
// Author: $author$
//   Date: 11/8/2009
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVUTCTIME_HPP
#define _CEVUTCTIME_HPP

#include "evplatform_time.h"
#include "cevbase.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvUTCTime
//
// Author: $author$
//   Date: 11/8/2009
///////////////////////////////////////////////////////////////////////
class CEvUTCTime
: public CEvBase
{
public:
    typedef CEvBase CExtends;
    typedef CEvUTCTime CDerives;

    time_t m_time;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvUTCTime
    //
    //       Author: $author$
    //         Date: 11/8/2009
    ///////////////////////////////////////////////////////////////////////
    CEvUTCTime(bool getCurrent=false) 
    : m_time(0)
    {
        if (getCurrent)
            GetCurrent();
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetCurrent
    //
    //   Author: $author$
    //     Date: 11/8/2009
    ///////////////////////////////////////////////////////////////////////
    virtual CEvUTCTime& GetCurrent() 
    {
        time(&m_time);
        return *this;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: operator time_t
    //
    //   Author: $author$
    //     Date: 11/8/2009
    ///////////////////////////////////////////////////////////////////////
    virtual operator time_t() const
    {
        return m_time;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: operator ULONG
    //
    //   Author: $author$
    //     Date: 11/8/2009
    ///////////////////////////////////////////////////////////////////////
    virtual operator ULONG() const
    {
        return (ULONG)(m_time);
    }
};
#endif // _CEVUTCTIME_HPP
