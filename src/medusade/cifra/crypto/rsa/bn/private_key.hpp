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
///   File: private_key.hpp
///
/// Author: $author$
///   Date: 3/14/2018
///////////////////////////////////////////////////////////////////////
#ifndef _CIFRA_CRYPTO_RSA_BN_PRIVATE_KEY_HPP
#define _CIFRA_CRYPTO_RSA_BN_PRIVATE_KEY_HPP

#include "cifra/crypto/rsa/private_key.hpp"
#include "cifra/crypto/rsa/bn/key.hpp"

namespace cifra {
namespace crypto {
namespace rsa {
namespace bn {

///////////////////////////////////////////////////////////////////////
///  Class: private_key_implementt
///////////////////////////////////////////////////////////////////////
template
<class TImplements = rsa::private_key_implement>

class _EXPORT_CLASS private_key_implementt: virtual public TImplements {
public:
    typedef TImplements Implements;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef private_key_implementt<> private_key_implement;

///////////////////////////////////////////////////////////////////////
///  Class: private_keyt
///////////////////////////////////////////////////////////////////////
template
<class TImplements = private_key_implement, 
 class TExtends = rsa::private_keyt<private_key_implement, key> >

class _EXPORT_CLASS private_keyt: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    private_keyt
    (const byte_t* modulus, size_t modsize,
     const byte_t* d, size_t dsize, const byte_t* p, const byte_t* q,
     const byte_t* dmp1, const byte_t* dmq1, const byte_t* iqmp, size_t psize) {
        init();
        if ((this->create())) {
            this->set_msb(modulus, modsize, d, dsize, p, q, dmp1, dmq1, iqmp, psize);
        } else {
            creator_exception e = failed_to_create;
            fini();
            LOG_ERROR("...failed on this->create() throw (creator_exception e = failed_to_create)...");
            throw (e);
        }
    }
    private_keyt(const private_keyt& copy) {
        init();
        /*if ((this->create())) {
        } else*/ {
            creator_exception e = failed_to_create;
            fini();
            LOG_ERROR("...failed on this->create() throw (creator_exception e = failed_to_create)...");
            throw (e);
        }
    }
    private_keyt() {
        init();
        if (!(this->create())) {
            creator_exception e = failed_to_create;
            fini();
            LOG_ERROR("...failed on this->create() throw (creator_exception e = failed_to_create)...");
            throw (e);
        }
    }
    virtual ~private_keyt() {
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
            BN_CTX *ctx = 0;
            BIGNUM *modulus = 0, *p = 0, *q = 0, *dmp1 = 0, *dmq1 = 0, *iqmp = 0;
            ssize_t modsize = 0, psize = 0;

            if ((ctx = this->context()) 
                && (modulus = this->modulus()) && (modsize = this->modsize())
                && (p = this->p()) && (psize = this->psize())
                && (q = this->q()) && (dmp1 = this->dmp1())
                && (dmq1 = this->dmq1()) && (iqmp = this->iqmp()) 
                && (outsize >= modsize) && (insize == modsize)) {
                bool subtracted_p = false;
                ::numera::mp::bn::bignum out, in, q2, p2, k;
                
                // out = in ^ d mod n 
                //
                LOG_DEBUG("::BN_set_msb(in, i, insize)...");
                ::BN_set_msb(in, i, insize);

                // q2 = (in mod q) ^ dmq1 mod q
                //
                LOG_DEBUG("::BN_mod(out, in, q, ctx)...");
                ::BN_mod(out, in, q, ctx);

                LOG_DEBUG("::BN_mod_exp(q2, out, dmq1, q, ctx)...");
                ::BN_mod_exp(q2, out, dmq1, q, ctx);

                // p2 = (in mod p) ^ dmp1 mod p
                //
                LOG_DEBUG("::BN_mod(out, in, p, ctx)...");
                ::BN_mod(out, in, p, ctx);

                LOG_DEBUG("::BN_mod_exp(p2, out, dmp1, p, ctx)...");
                ::BN_mod_exp(p2, out, dmp1, p, ctx);

                // if q2 > p then q2 = q2 - p
                //
                if ((subtracted_p = (0 < ::BN_cmp(q2, p)))) {
                    LOG_DEBUG("::BN_sub(out, q2, p)...");
                    ::BN_sub(out, q2, p);

                    LOG_DEBUG("::BN_copy(p2, out)...");
                    ::BN_copy(p2, out);
                }

                // k = (((p2 + p) - q2) mod p) * iqmp mod p.
                //
                LOG_DEBUG("::BN_add(out, p2, p)...");
                ::BN_add(out, p2, p);

                LOG_DEBUG("::BN_sub(k, out, q2)...");
                ::BN_sub(k, out, q2);

                LOG_DEBUG(":BN_mul(out, k, iqmp)...");
                ::BN_mul(out, k, iqmp);

                LOG_DEBUG("::BN_mod(k, out, p, ctx)...");
                ::BN_mod(k, out, p, ctx);

                // out = q2 + q * k.
                //
                LOG_DEBUG("::BN_mul(p2, k, q)...");
                ::BN_mul(p2, k, q);

                LOG_DEBUG("::BN_add(out, p2, q2)...");
                ::BN_add(out, p2, q2);

                // if subtracted p then out = out + p
                //
                if (subtracted_p) {
                    LOG_DEBUG("::BN_add(p2, out, p)...");
                    ::BN_add(p2, out, p);

                    LOG_DEBUG("::BN_copy(out, p2)...");
                    ::BN_copy(out, p2);
                }
                LOG_DEBUG("::BN_get_msb(out, o, modsize)...");
                ::BN_get_msb(out, o, modsize);
                return modsize;
            }
        }
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t set_d_msb(const byte_t* to, size_t tosize) {
        BIGNUM* d = 0;
        if ((d = this->d()) && (to) && (tosize)) {
            LOG_DEBUG("::BN_set_msb(d, to = " << x_to_string(to, tosize) << ", tosize = " << tosize << ")...");
            ::BN_set_msb(d, to, tosize);
            this->set_dsize(tosize);
            return tosize;
        }
        return 0;
    }
    virtual ssize_t get_d_msb(byte_t* to, size_t tosize) const {
        BIGNUM* d = 0;
        size_t size = 0;
        if ((d = this->d()) && (size = this->dsize()) && (to) && (tosize <= size)) {
            ::BN_get_msb(d, to, size);
            LOG_DEBUG("...::BN_get_msb(d, to = " << x_to_string(to, size) << ", size = " << size << ")");
            return size;
        }
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t set_p_msb(const byte_t* to, size_t tosize) {
        BIGNUM* p = 0;
        if ((p = this->p()) && (to) && (tosize)) {
            LOG_DEBUG("::BN_set_msb(p, to = " << x_to_string(to, tosize) << ", tosize = " << tosize << ")...");
            ::BN_set_msb(p, to, tosize);
            this->set_psize(tosize);
            return tosize;
        }
        return 0;
    }
    virtual ssize_t get_p_msb(byte_t* to, size_t tosize) const {
        BIGNUM* p = 0;
        size_t size = 0;
        if ((p = this->p()) && (size = this->psize()) && (to) && (tosize <= size)) {
            ::BN_get_msb(p, to, size);
            LOG_DEBUG("...::BN_get_msb(p, to = " << x_to_string(to, size) << ", size = " << size << ")");
            return size;
        }
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t set_q_msb(const byte_t* to, size_t tosize) {
        BIGNUM* q = 0;
        if ((q = this->q()) && (to) && (tosize)) {
            LOG_DEBUG("::BN_set_msb(q, to = " << x_to_string(to, tosize) << ", tosize = " << tosize << ")...");
            ::BN_set_msb(q, to, tosize);
            return tosize;
        }
        return 0;
    }
    virtual ssize_t get_q_msb(byte_t* to, size_t tosize) const {
        BIGNUM* q = 0;
        size_t size = 0;
        if ((q = this->q()) && (size = this->psize()) && (to) && (tosize <= size)) {
            ::BN_get_msb(q, to, size);
            LOG_DEBUG("...::BN_get_msb(q, to = " << x_to_string(to, size) << ", size = " << size << ")");
            return size;
        }
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t set_dmp1_msb(const byte_t* to, size_t tosize) {
        BIGNUM* dmp1 = 0;
        if ((dmp1 = this->dmp1()) && (to) && (tosize)) {
            LOG_DEBUG("::BN_set_msb(dmp1, to = " << x_to_string(to, tosize) << ", tosize = " << tosize << ")...");
            ::BN_set_msb(dmp1, to, tosize);
            return tosize;
        }
        return 0;
    }
    virtual ssize_t get_dmp1_msb(byte_t* to, size_t tosize) const {
        BIGNUM* dmp1 = 0;
        size_t size = 0;
        if ((dmp1 = this->dmp1()) && (size = this->psize()) && (to) && (tosize <= size)) {
            ::BN_get_msb(dmp1, to, size);
            LOG_DEBUG("...::BN_get_msb(dmp1, to = " << x_to_string(to, size) << ", size = " << size << ")");
            return size;
        }
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t set_dmq1_msb(const byte_t* to, size_t tosize) {
        BIGNUM* dmq1 = 0;
        if ((dmq1 = this->dmq1()) && (to) && (tosize)) {
            LOG_DEBUG("::BN_set_msb(dmq1, to = " << x_to_string(to, tosize) << ", tosize = " << tosize << ")...");
            ::BN_set_msb(dmq1, to, tosize);
            return tosize;
        }
        return 0;
    }
    virtual ssize_t get_dmq1_msb(byte_t* to, size_t tosize) const {
        BIGNUM* dmq1 = 0;
        size_t size = 0;
        if ((dmq1 = this->dmq1()) && (size = this->psize()) && (to) && (tosize <= size)) {
            ::BN_get_msb(dmq1, to, size);
            LOG_DEBUG("...::BN_get_msb(dmq1, to = " << x_to_string(to, size) << ", size = " << size << ")");
            return size;
        }
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t set_iqmp_msb(const byte_t* to, size_t tosize) {
        BIGNUM* iqmp = 0;
        if ((iqmp = this->iqmp()) && (to) && (tosize)) {
            LOG_DEBUG("::BN_set_msb(iqmp, to = " << x_to_string(to, tosize) << ", tosize = " << tosize << ")...");
            ::BN_set_msb(iqmp, to, tosize);
            return tosize;
        }
        return 0;
    }
    virtual ssize_t get_iqmp_msb(byte_t* to, size_t tosize) const {
        BIGNUM* iqmp = 0;
        size_t size = 0;
        if ((iqmp = this->iqmp()) && (size = this->psize()) && (to) && (tosize <= size)) {
            ::BN_get_msb(iqmp, to, size);
            LOG_DEBUG("...::BN_get_msb(iqmp, to = " << x_to_string(to, size) << ", size = " << size << ")");
            return size;
        }
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual BIGNUM* d() const {
        return (BIGNUM*) d_;
    }
    virtual BIGNUM* p() const {
        return (BIGNUM*) p_;
    }
    virtual BIGNUM* q() const {
        return (BIGNUM*) q_;
    }
    virtual BIGNUM* dmp1() const {
        return (BIGNUM*) dmp1_;
    }
    virtual BIGNUM* dmq1() const {
        return (BIGNUM*) dmq1_;
    }
    virtual BIGNUM* iqmp() const {
        return (BIGNUM*) iqmp_;
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
    ::numera::mp::bn::bignum d_, p_, q_, dmp1_, dmq1_, iqmp_;
};
typedef private_keyt<> private_key;

} // namespace bn 
} // namespace rsa 
} // namespace crypto 
} // namespace cifra 

#endif // _CIFRA_CRYPTO_RSA_BN_PRIVATE_KEY_HPP 
