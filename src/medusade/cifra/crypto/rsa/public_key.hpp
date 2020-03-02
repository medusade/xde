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
///   File: public_key.hpp
///
/// Author: $author$
///   Date: 3/14/2018
///////////////////////////////////////////////////////////////////////
#ifndef _CIFRA_CRYPTO_RSA_PUBLIC_KEY_HPP
#define _CIFRA_CRYPTO_RSA_PUBLIC_KEY_HPP

#include "cifra/crypto/rsa/key.hpp"

namespace cifra {
namespace crypto {
namespace rsa {

///////////////////////////////////////////////////////////////////////
///  Class: public_key_implementt
///////////////////////////////////////////////////////////////////////
template
<class TImplements = key_implement>

class _EXPORT_CLASS public_key_implementt: virtual public TImplements {
public:
    typedef TImplements Implements;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t set_msb
    (const byte_t* modulus, size_t modsize,
     const unsigned& exponent, size_t expsize = sizeof(unsigned)) {
        ssize_t count = 0, amount = 0;
        if (0 <= (amount = this->set_modulus_msb(modulus, modsize))) {
            count += amount;
            if (0 <= (amount = this->set_exponent(exponent, expsize))) {
                count += amount;
                return count;
            }
        }
        return 0;
    }
    virtual ssize_t set_msb
    (const byte_t* modulus, size_t modsize,
     const byte_t* exponent, size_t expsize) {
        ssize_t count = 0, amount = 0;
        if (0 <= (amount = this->set_modulus_msb(modulus, modsize))) {
            count += amount;
            if (0 <= (amount = this->set_exponent_msb(exponent, expsize))) {
                count += amount;
                return count;
            }
        }
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t set_exponent(const unsigned& to, size_t tosize = sizeof(unsigned)) {
        return 0;
    }
    virtual ssize_t set_exponent_msb(const byte_t* to, size_t tosize) {
        return 0;
    }
    virtual ssize_t get_exponent_msb(byte_t* to, size_t tosize) const {
        return 0;
    }
    virtual ssize_t set_expsize(size_t to) {
        return 0;
    }
    virtual ssize_t expsize() const {
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef public_key_implementt<> public_key_implement;

///////////////////////////////////////////////////////////////////////
///  Class: public_keyt
///////////////////////////////////////////////////////////////////////
template
<class TImplements = public_key_implement, class TExtends = key>

class _EXPORT_CLASS public_keyt: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    public_keyt
    (const byte_t* modulus, size_t modsize,
     const byte_t* exponent, size_t expsize) {
        init();
        if ((this->create())) {
            this->set_msb(modulus, modsize, exponent, expsize);
        } else {
            creator_exception e = failed_to_create;
            fini();
            LOG_ERROR("...failed on this->create() throw (creator_exception e = failed_to_create)...");
            throw (e);
        }
    }
    public_keyt
    (const byte_t* modulus, size_t modsize,
     const unsigned& exponent, size_t expsize) {
        init();
        if ((this->create())) {
            this->set_msb(modulus, modsize, exponent, expsize);
        } else {
            creator_exception e = failed_to_create;
            fini();
            LOG_ERROR("...failed on this->create() throw (creator_exception e = failed_to_create)...");
            throw (e);
        }
    }
    public_keyt(const public_keyt& copy) {
        init();
        /*if ((this->create())) {
        } else*/ {
            creator_exception e = failed_to_create;
            fini();
            LOG_ERROR("...failed on this->create() throw (creator_exception e = failed_to_create)...");
            throw (e);
        }
    }
    public_keyt() {
        init();
        if (!(this->create())) {
            creator_exception e = failed_to_create;
            fini();
            LOG_ERROR("...failed on this->create() throw (creator_exception e = failed_to_create)...");
            throw (e);
        }
    }
    virtual ~public_keyt() {
        if (!(this->destroyed())) {
            creator_exception e = failed_to_destroy;
            fini();
            LOG_ERROR("...failed on this->destroyed() throw (creator_exception e = failed_to_destroy)...");
            throw (e);
        }
        fini();
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t set_expsize(size_t to) {
        expsize_ = to;
        return expsize_;
    }
    virtual ssize_t expsize() const {
        return expsize_;
    }
protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void init() {
        expsize_ = 0;
    }
    virtual void fini() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    size_t expsize_;
};
typedef public_keyt<> public_key;

} // namespace rsa 
} // namespace crypto 
} // namespace cifra 

#endif // _CIFRA_CRYPTO_RSA_PUBLIC_KEY_HPP 
