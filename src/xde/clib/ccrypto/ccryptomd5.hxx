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
 *   File: ccryptomd5.hxx
 *
 * Author: $author$
 *   Date: 2/7/2020
 **********************************************************************
 */
#ifndef CCRYPTOMD5_HXX
#define CCRYPTOMD5_HXX

#include "ccryptohash.hxx"
#include "cifra/crypto/hash/openssl/md5.hpp"

typedef cCryptoHashT<cifra::crypto::hash::openssl::md5> cCryptoMd5;

#endif /* ndef CCRYPTOMD5_HXX */
