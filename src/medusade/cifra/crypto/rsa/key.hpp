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
#ifndef _CIFRA_CRYPTO_RSA_KEY_HPP
#define _CIFRA_CRYPTO_RSA_KEY_HPP

#include "cifra/crypto/base/base.hpp"

namespace cifra {
namespace crypto {
namespace rsa {

///////////////////////////////////////////////////////////////////////
///  Class: key_implementt
///////////////////////////////////////////////////////////////////////
template
<class TImplement = implement_base,
 class TImplements = ::xos::base::creatort<TImplement> >

class _EXPORT_CLASS key_implementt: virtual public TImplements {
public:
    typedef TImplements Implements;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t encrypt
    (void* out, size_t outsize, const void* in, size_t insize) {
        return (*this)(out, outsize, in, insize);
    }
    virtual ssize_t dencrypt
    (void* out, size_t outsize, const void* in, size_t insize) {
        return (*this)(out, outsize, in, insize);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t operator()
    (void* out, size_t outsize, const void* in, size_t insize) {
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t set_modulus_msb(const byte_t* to, size_t tosize) {
        return 0;
    }
    virtual ssize_t get_modulus_msb(byte_t* to, size_t tosize) const {
        return 0;
    }
    virtual ssize_t set_modsize(size_t to) {
        return 0;
    }
    virtual ssize_t modsize() const {
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef key_implementt<> key_implement;

///////////////////////////////////////////////////////////////////////
///  Class: keyt
///////////////////////////////////////////////////////////////////////
template
<class TImplements = key_implement, class TExtend = base, 
 class TExtends = ::xos::base::created_baset<TImplements, TExtend> >

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
    virtual ssize_t set_modsize(size_t to) {
        modsize_ = to;
        return modsize_;
    }
    virtual ssize_t modsize() const {
        return modsize_;
    }
protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void init() {
        modsize_ = 0;
    }
    virtual void fini() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    size_t modsize_;
};
typedef keyt<> key;

} // namespace rsa 
} // namespace crypto 
} // namespace cifra 

#endif // _CIFRA_CRYPTO_RSA_KEY_HPP 
