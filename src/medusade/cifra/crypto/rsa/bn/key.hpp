///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2018 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: key.hpp
///
/// Author: $author$
///   Date: 3/14/2018
///////////////////////////////////////////////////////////////////////
#ifndef _CIFRA_CRYPTO_RSA_BN_KEY_HPP
#define _CIFRA_CRYPTO_RSA_BN_KEY_HPP

#include "cifra/crypto/rsa/key.hpp"
#include "numera/mp/bn/bignum.hpp"
#include "numera/mp/bn/context.hpp"

namespace cifra {
namespace crypto {
namespace rsa {
namespace bn {

///////////////////////////////////////////////////////////////////////
///  Class: key_implementt
///////////////////////////////////////////////////////////////////////
template
<class TImplements = rsa::key_implement>

class _EXPORT_CLASS key_implementt: virtual public TImplements {
public:
    typedef TImplements Implements;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef key_implementt<> key_implement;

///////////////////////////////////////////////////////////////////////
///  Class: keyt
///////////////////////////////////////////////////////////////////////
template
<class TImplements = key_implement, class TExtends = rsa::key>

class _EXPORT_CLASS keyt: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    keyt(const keyt& copy) {
        init();
    }
    keyt() {
        init();
    }
    virtual ~keyt() {
        fini();
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t set_modulus_msb(const byte_t* to, size_t tosize) {
        BIGNUM* modulus = 0;
        if ((modulus = this->modulus()) && (to) && (tosize)) {
            LOG_DEBUG("::BN_set_msb(modulus, to = " << x_to_string(to, tosize) << ", tosize = " << tosize << ")...");
            ::BN_set_msb(modulus, to, tosize);
            this->set_modsize(tosize);
            return tosize;
        }
        return 0;
    }
    virtual ssize_t get_modulus_msb(byte_t* to, size_t tosize) const {
        BIGNUM* modulus = 0;
        size_t size = 0;
        if ((modulus = this->modulus()) && (size = this->modsize()) && (to) && (tosize <= size)) {
            ::BN_get_msb(modulus, to, size);
            LOG_DEBUG("...::BN_get_msb(modulus, to = " << x_to_string(to, size) << ", size = " << size << ")");
            return size;
        }
        return 0;
    }
    virtual BIGNUM* modulus() const {
        return (BIGNUM*)modulus_;
    }
    virtual BN_CTX* context() const {
        return (BN_CTX*)context_;
    }
protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void init() {
    }
    virtual void fini() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    ::numera::mp::bn::bignum modulus_;
    ::numera::mp::bn::context context_;
};
typedef keyt<> key;

} // namespace bn 
} // namespace rsa 
} // namespace crypto 
} // namespace cifra 

#endif // _CIFRA_CRYPTO_RSA_BN_KEY_HPP 
