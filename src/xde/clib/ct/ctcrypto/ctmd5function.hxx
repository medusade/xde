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
 *   File: ctmd5function.hxx
 *
 * Author: $author$
 *   Date: 2/7/2020
 **********************************************************************
 */
#ifndef CTMD5FUNCTION_HXX
#define CTMD5FUNCTION_HXX

#include "ctcryptohashfunction.hxx"
#include "ccryptomd5.hxx"

typedef cTCryptoHashFunctionT<cCryptoMd5> cTMd5Function;

#endif /* ndef CTMD5FUNCTION_HXX */
