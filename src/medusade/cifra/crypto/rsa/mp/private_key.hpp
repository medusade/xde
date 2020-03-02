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
#ifndef _CIFRA_CRYPTO_RSA_MP_PRIVATE_KEY_HPP
#define _CIFRA_CRYPTO_RSA_MP_PRIVATE_KEY_HPP

#include "cifra/crypto/rsa/private_key.hpp"
#include "cifra/crypto/rsa/mp/key.hpp"

namespace cifra {
namespace crypto {
namespace rsa {
namespace mp {

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
            MP_INT *modulus = 0, *p = 0, *q = 0, *dmp1 = 0, *dmq1 = 0, *iqmp = 0;
            ssize_t modsize = 0, psize = 0;

            if ((modulus = this->modulus()) && (modsize = this->modsize())
                && (p = this->p()) && (psize = this->psize())
                && (q = this->q()) && (dmp1 = this->dmp1())
                && (dmq1 = this->dmq1()) && (iqmp = this->iqmp()) 
                && (outsize >= modsize) && (insize == modsize)) {
                bool subtracted_p = false;
                ::numera::mp::mp::mpint out, in, q2, p2, k;
                
                // out = in ^ d mod n 
                //
                LOG_DEBUG("::mpz_set_msb(in, i, insize)...");
                ::mpz_set_msb(in, i, insize);

                // q2 = (in mod q) ^ dmq1 mod q
                //
                LOG_DEBUG("::mpz_mod(out, in, q)...");
                ::mpz_mod(out, in, q);

                LOG_DEBUG("::mpz_powm(q2, out, dmq1, q)...");
                ::mpz_powm(q2, out, dmq1, q);

                // p2 = (in mod p) ^ dmp1 mod p
                //
                LOG_DEBUG("::mpz_mod(out, in, p)...");
                ::mpz_mod(out, in, p);

                LOG_DEBUG("::mpz_powm(p2, out, dmp1, p)...");
                ::mpz_powm(p2, out, dmp1, p);

                // if q2 > p then q2 = q2 - p
                //
                if ((subtracted_p = (0 < ::mpz_cmp(q2, p)))) {
                    LOG_DEBUG("::mpz_sub(out, q2, p)...");
                    ::mpz_sub(out, q2, p);

                    LOG_DEBUG("::mpz_set(p2, out)...");
                    ::mpz_set(p2, out);
                }

                // k = (((p2 + p) - q2) mod p) * iqmp mod p.
                //
                LOG_DEBUG("::mpz_add(out, p2, p)...");
                ::mpz_add(out, p2, p);

                LOG_DEBUG("::mpz_sub(k, out, q2)...");
                ::mpz_sub(k, out, q2);

                LOG_DEBUG(":BN_mul(out, k, iqmp)...");
                ::mpz_mul(out, k, iqmp);

                LOG_DEBUG("::mpz_mmod(k, out, p)...");
                ::mpz_mmod(k, out, p);

                // out = q2 + q * k.
                //
                LOG_DEBUG("::mpz_mul(p2, k, q)...");
                ::mpz_mul(p2, k, q);

                LOG_DEBUG("::mpz_add(out, p2, q2)...");
                ::mpz_add(out, p2, q2);

                // if subtracted p then out = out + p
                //
                if (subtracted_p) {
                    LOG_DEBUG("::mpz_add(p2, out, p)...");
                    ::mpz_add(p2, out, p);

                    LOG_DEBUG("::mpz_set(out, p2)...");
                    ::mpz_set(out, p2);
                }
                LOG_DEBUG("::mpz_get_msb(o, modsize, out)...");
                ::mpz_get_msb(o, modsize, out);
                return modsize;
            }
        }
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t set_d_msb(const byte_t* to, size_t tosize) {
        MP_INT* d = 0;
        if ((d = this->d()) && (to) && (tosize)) {
            LOG_DEBUG("::mpz_set_msb(d, to = " << x_to_string(to, tosize) << ", tosize = " << tosize << ")...");
            ::mpz_set_msb(d, to, tosize);
            this->set_dsize(tosize);
            return tosize;
        }
        return 0;
    }
    virtual ssize_t get_d_msb(byte_t* to, size_t tosize) const {
        MP_INT* d = 0;
        size_t size = 0;
        if ((d = this->d()) && (size = this->dsize()) && (to) && (tosize <= size)) {
            ::mpz_get_msb(to, size, d);
            LOG_DEBUG("...::mpz_get_msb(to = " << x_to_string(to, size) << ", size = " << size << ", d)");
            return size;
        }
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t set_p_msb(const byte_t* to, size_t tosize) {
        MP_INT* p = 0;
        if ((p = this->p()) && (to) && (tosize)) {
            LOG_DEBUG("::mpz_set_msb(p, to = " << x_to_string(to, tosize) << ", tosize = " << tosize << ")...");
            ::mpz_set_msb(p, to, tosize);
            this->set_psize(tosize);
            return tosize;
        }
        return 0;
    }
    virtual ssize_t get_p_msb(byte_t* to, size_t tosize) const {
        MP_INT* p = 0;
        size_t size = 0;
        if ((p = this->p()) && (size = this->psize()) && (to) && (tosize <= size)) {
            ::mpz_get_msb(to, size, p);
            LOG_DEBUG("...::mpz_get_msb(to = " << x_to_string(to, size) << ", size = " << size << ", p)");
            return size;
        }
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t set_q_msb(const byte_t* to, size_t tosize) {
        MP_INT* q = 0;
        if ((q = this->q()) && (to) && (tosize)) {
            LOG_DEBUG("::mpz_set_msb(q, to = " << x_to_string(to, tosize) << ", tosize = " << tosize << ")...");
            ::mpz_set_msb(q, to, tosize);
            //this->set_qsize(tosize);
            return tosize;
        }
        return 0;
    }
    virtual ssize_t get_q_msb(byte_t* to, size_t tosize) const {
        MP_INT* q = 0;
        size_t size = 0;
        if ((q = this->q()) && (size = this->psize()) && (to) && (tosize <= size)) {
            ::mpz_get_msb(to, size, q);
            LOG_DEBUG("...::mpz_get_msb(to = " << x_to_string(to, size) << ", size = " << size << ", q)");
            return size;
        }
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t set_dmp1_msb(const byte_t* to, size_t tosize) {
        MP_INT* dmp1 = 0;
        if ((dmp1 = this->dmp1()) && (to) && (tosize)) {
            LOG_DEBUG("::mpz_set_msb(dmp1, to = " << x_to_string(to, tosize) << ", tosize = " << tosize << ")...");
            ::mpz_set_msb(dmp1, to, tosize);
            //this->set_dmp1size(tosize);
            return tosize;
        }
        return 0;
    }
    virtual ssize_t get_dmp1_msb(byte_t* to, size_t tosize) const {
        MP_INT* dmp1 = 0;
        size_t size = 0;
        if ((dmp1 = this->dmp1()) && (size = this->psize()) && (to) && (tosize <= size)) {
            ::mpz_get_msb(to, size, dmp1);
            LOG_DEBUG("...::mpz_get_msb(to = " << x_to_string(to, size) << ", size = " << size << ", dmp1)");
            return size;
        }
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t set_dmq1_msb(const byte_t* to, size_t tosize) {
        MP_INT* dmq1 = 0;
        if ((dmq1 = this->dmq1()) && (to) && (tosize)) {
            LOG_DEBUG("::mpz_set_msb(dmq1, to = " << x_to_string(to, tosize) << ", tosize = " << tosize << ")...");
            ::mpz_set_msb(dmq1, to, tosize);
            //this->set_dmq1size(tosize);
            return tosize;
        }
        return 0;
    }
    virtual ssize_t get_dmq1_msb(byte_t* to, size_t tosize) const {
        MP_INT* dmq1 = 0;
        size_t size = 0;
        if ((dmq1 = this->dmq1()) && (size = this->psize()) && (to) && (tosize <= size)) {
            ::mpz_get_msb(to, size, dmq1);
            LOG_DEBUG("...::mpz_get_msb(to = " << x_to_string(to, size) << ", size = " << size << ", dmq1)");
            return size;
        }
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t set_iqmp_msb(const byte_t* to, size_t tosize) {
        MP_INT* iqmp = 0;
        if ((iqmp = this->iqmp()) && (to) && (tosize)) {
            LOG_DEBUG("::mpz_set_msb(iqmp, to = " << x_to_string(to, tosize) << ", tosize = " << tosize << ")...");
            ::mpz_set_msb(iqmp, to, tosize);
            //this->set_iqmpsize(tosize);
            return tosize;
        }
        return 0;
    }
    virtual ssize_t get_iqmp_msb(byte_t* to, size_t tosize) const {
        MP_INT* iqmp = 0;
        size_t size = 0;
        if ((iqmp = this->iqmp()) && (size = this->psize()) && (to) && (tosize <= size)) {
            ::mpz_get_msb(to, size, iqmp);
            LOG_DEBUG("...::mpz_get_msb(to = " << x_to_string(to, size) << ", size = " << size << ", iqmp)");
            return size;
        }
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual MP_INT* d () const {
        return (MP_INT*) d_;
    }
    virtual MP_INT* p () const {
        return (MP_INT*) p_;
    }
    virtual MP_INT* q () const {
        return (MP_INT*) q_;
    }
    virtual MP_INT* dmp1 () const {
        return (MP_INT*) dmp1_;
    }
    virtual MP_INT* dmq1 () const {
        return (MP_INT*) dmq1_;
    }
    virtual MP_INT* iqmp () const {
        return (MP_INT*) iqmp_;
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
    ::numera::mp::mp::mpint d_, p_, q_, dmp1_, dmq1_, iqmp_;
};
typedef private_keyt<> private_key;

} // namespace mp 
} // namespace rsa 
} // namespace crypto 
} // namespace cifra 

#endif // _CIFRA_CRYPTO_RSA_MP_PRIVATE_KEY_HPP 

        

