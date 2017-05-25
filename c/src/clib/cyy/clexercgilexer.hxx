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
 *   File: clexercgilexer.hxx
 *
 * Author: $author$
 *   Date: 8/10/2008
 **********************************************************************
 */
#ifndef _CLEXERCGILEXER_HXX
#define _CLEXERCGILEXER_HXX

#undef yyIsLexer
#undef yyLexer
#undef cYYIsLexer
#define yyIsLexer cLexerCGIIsLexer
#define yyLexer cLexerCGILexer
#define cYYIsLexer cLexerCGILexerExtends
#include "cyylexer.hxx"
#include "clexerdelegate.hxx"
#include "clexer.hxx"

/**
 **********************************************************************
 *  Class: cLexerCGILexerDelegate
 *
 * Author: $author$
 *   Date: 8/10/2008
 **********************************************************************
 */
class cLexerCGILexerDelegate
: public cLexerDelegateT<cLexerCGILexerDelegate>
{
public:
    typedef cLexerDelegateT<cLexerCGILexerDelegate> cExtends;
    typedef cLexerCGILexerDelegate cDelegate;
};

/**
 **********************************************************************
 *  Class: cLexerCGILexer
 *
 * Author: $author$
 *   Date: 8/10/2008
 **********************************************************************
 */
class cLexerCGILexer
: public cLexerT
  <cLexerCGILexerDelegate,cLexerCGILexerExtends,
   cLexerSource,cCharStreamInterface>
{
public:
    typedef cLexerT
    <cLexerCGILexerDelegate,cLexerCGILexerExtends,
     cLexerSource,cCharStreamInterface> cExtends;
    typedef cLexerCGILexer cDerives;

    /**
     **********************************************************************
     * Constructor: cLexerCGILexer
     *
     *      Author: $author$
     *        Date: 8/10/2008
     **********************************************************************
     */
    cLexerCGILexer
    (cLexerCGILexerDelegate& delegate,
     cCharStreamInterface& out, 
     cCharStreamInterface& in, 
     cLexerSource &source)
    : cExtends(delegate, out, in, source) 
    {
    }
    /**
     **********************************************************************
     * Function: yylex
     *
     *   Author: $author$
     *     Date: 8/10/2008
     *
     * This function is generated by flex.
     **********************************************************************
     */
    virtual int yylex();
};

#endif /* _CLEXERCGILEXER_HXX */
