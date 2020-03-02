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
///   Date: 3/18/2018
///////////////////////////////////////////////////////////////////////
#ifndef _CIFRA_CRYPTO_RSA_MB_PUBLIC_KEY_HPP
#define _CIFRA_CRYPTO_RSA_MB_PUBLIC_KEY_HPP

#include "cifra/crypto/rsa/public_key.hpp"
#include "cifra/crypto/rsa/mb/key.hpp"

namespace cifra {
namespace crypto {
namespace rsa {
namespace mb {

///////////////////////////////////////////////////////////////////////
///  Class: public_key_implementt
///////////////////////////////////////////////////////////////////////
template
<class TImplements = rsa::public_key_implement>

class _EXPORT_CLASS public_key_implementt: virtual public TImplements {
public:
    typedef TImplements Implements;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef public_key_implementt<> public_key_implement;

///////////////////////////////////////////////////////////////////////
///  Class: public_keyt
///////////////////////////////////////////////////////////////////////
template
<class TImplements = public_key_implement, 
 class TExtends = rsa::public_keyt<public_key_implement, key> >

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
    virtual ssize_t operator()
    (void* out, size_t outsize, const void* in, size_t insize) {
        const byte_t* i = 0;
        byte_t* o = 0;

        if ((o = (byte_t*)out) && (outsize) 
            && (i = (const byte_t*)in) && (insize)) {
            uint8 *modulus = 0, *exponent = 0;
            ssize_t modsize = 0, expsize = 0;

            if ((modulus = this->modulus()) && (modsize = this->modsize())
                && (exponent = this->exponent()) && (expsize = this->expsize())
                && (outsize >= modsize) && (insize <= modsize)) {
                uint8 out_[MBU_MAX], in_[MBU_MAX];
                
                // out = in ^ x mod n
                //
                LOG_DEBUG("::mbu_x(in_, i, insize, modsize)...");
                ::mbu_x(in_, i, insize, modsize);
                LOG_DEBUG("::mbu_mod_exp(out_, in_, modulus, exponent, modsize, expsize)...");
                ::mbu_mod_exp(out_, in_, modulus, exponent, modsize, expsize);
                LOG_DEBUG("::mbu_get(o, out_, modsize)...");
                ::mbu_get(o, out_, modsize);
                return modsize;
            }
        }
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t set_exponent(const unsigned& to, size_t tosize = sizeof(unsigned)) {
        uint8* exponent = 0;
        if ((exponent = this->exponent()) && (to) && (tosize)) {
            LOG_DEBUG("::mbu_set_u(exponent, to = " << to << ", tosize = " << tosize << ")...");
            ::mbu_set_u(exponent, to, tosize);
            this->set_expsize(tosize);
            return tosize;
        }
        return 0;
    }
    virtual ssize_t set_exponent_msb(const byte_t* to, size_t tosize) {
        uint8* exponent = 0;
        if ((exponent = this->exponent()) && (to) && (tosize) && (tosize <= MBU_MAX)) {
            LOG_DEBUG("::mbu_set(exponent, to = " << x_to_string(to, tosize) << ", tosize = " << tosize << ")...");
            ::mbu_set(exponent, to, tosize);
            this->set_expsize(tosize);
            return tosize;
        }
        return 0;
    }
    virtual ssize_t get_exponent_msb(byte_t* to, size_t tosize) const {
        uint8* exponent = 0;
        size_t size = 0;
        if ((exponent = this->exponent()) && (size = this->expsize()) && (to) && (tosize >= size)) {
            ::mbu_get(exponent, to, size);
            LOG_DEBUG("...::mbu_get(exponent, to = " << x_to_string(to, size) << ", size = " << size << ")");
            return size;
        }
        return 0;
    }
    virtual uint8* exponent() const {
        return (uint8*)exponent_;
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
    uint8 exponent_[MBU_MAX];
};
typedef public_keyt<> public_key;

} // namespace mb 
} // namespace rsa 
} // namespace crypto 
} // namespace cifra 

#endif // _CIFRA_CRYPTO_RSA_MB_PUBLIC_KEY_HPP 
