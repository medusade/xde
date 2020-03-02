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
///   Date: 3/18/2018
///////////////////////////////////////////////////////////////////////
#ifndef _CIFRA_CRYPTO_RSA_MB_PRIVATE_KEY_HPP
#define _CIFRA_CRYPTO_RSA_MB_PRIVATE_KEY_HPP

#include "cifra/crypto/rsa/private_key.hpp"
#include "cifra/crypto/rsa/mb/key.hpp"

namespace cifra {
namespace crypto {
namespace rsa {
namespace mb {

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
            uint8 *modulus = 0, *p = 0, *q = 0, *dmp1 = 0, *dmq1 = 0, *iqmp = 0;
            ssize_t modsize = 0, psize = 0;

            if ((modulus = this->modulus()) && (modsize = this->modsize())
                && (p = this->p()) && (psize = this->psize())
                && (q = this->q()) && (dmp1 = this->dmp1())
                && (dmq1 = this->dmq1()) && (iqmp = this->iqmp()) 
                && (outsize >= modsize) && (insize <= modsize)) {
                uint8 out[MBU_MAX], in[MBU_MAX], p1[MBU_MAX], p2[MBU_MAX], q2[MBU_MAX];
#ifdef ETIRIS_GENERIC_MBUINT_H
                mbu_montgomery mont;
#else // def ETIRIS_GENERIC_MBUINT_H
#endif // def ETIRIS_GENERIC_MBUINT_H
                
                // out = in ^ d mod n 
                //
                LOG_DEBUG("::mbu_x(in, i, insize, modsize)...");
                ::mbu_x(in, i, insize, modsize);

#ifndef ETIRIS_GENERIC_MBUINT_H
                LOG_DEBUG("::mbu_mod_exp_crt_montgomery(out, in, p, q, dmp1, dmq1, iqmp, psize)...");
                ::mbu_mod_exp_crt_montgomery(out, in, p, q, dmp1, dmq1, iqmp, psize);
#else // ndef ETIRIS_GENERIC_MBUINT_H
                // q2 = (in mod q) ^ dmq1 mod q
                //
                LOG_DEBUG("::mbu_x(q2, q, psize, modsize)...");
                ::mbu_x(q2, q, psize, modsize);
                LOG_DEBUG(":mbu_mod(out, in, q2, modsize)...");
                ::mbu_mod(out, in, q2, modsize);
#ifdef ETIRIS_GENERIC_MBUINT_H
                LOG_DEBUG("::mbu_init_montgomery(&mont, q, psize)...");
                ::mbu_init_montgomery(&mont, q, psize);
                LOG_DEBUG(":mbu_mod_exp_montgomery(q2+psize, out+psize, &mont, dmq1, psize)...");
                ::mbu_mod_exp_montgomery(q2+psize, out+psize, &mont, dmq1, psize);
#else // def ETIRIS_GENERIC_MBUINT_H
                LOG_DEBUG(".::mbu_mod_exp_montgomery(q2+psize, out+psize, q, dmq1, psize, psize)..");
                ::mbu_mod_exp_montgomery(q2+psize, out+psize, q, dmq1, psize, psize);
#endif // def ETIRIS_GENERIC_MBUINT_H
                
                // p2 = (in mod p) ^ dmp1 mod p
                //
                LOG_DEBUG("::mbu_x(p1, p, psize, modsize)...");
                ::mbu_x(p1, p, psize, modsize);
                LOG_DEBUG("::mbu_mod(out, in, p1, modsize)...");
                ::mbu_mod(out, in, p1, modsize);
#ifdef ETIRIS_GENERIC_MBUINT_H
                LOG_DEBUG("::mbu_init_montgomery(&mont, p, psize)...");
                ::mbu_init_montgomery(&mont, p, psize);
                LOG_DEBUG("::mbu_mod_exp_montgomery(p2+psize, out+psize, &mont, dmp1, psize)...");
                ::mbu_mod_exp_montgomery(p2+psize, out+psize, &mont, dmp1, psize);
#else // def ETIRIS_GENERIC_MBUINT_H
                LOG_DEBUG("::mbu_mod_exp_montgomery(p2+psize, out+psize, p, dmp1, psize, psize)...");
                ::mbu_mod_exp_montgomery(p2+psize, out+psize, p, dmp1, psize, psize);
#endif // def ETIRIS_GENERIC_MBUINT_H
                
                // p2 = ((p2 - q2) mod p) * iqmp mod p
                //
                LOG_DEBUG("::mbu_cmp(p2+psize, q2+psize, psize)...");
                if (::mbu_cmp(p2+psize, q2+psize, psize) < 0) {
                    LOG_DEBUG(":mbu_sub(out, q2+psize, p2+psize, psize)...");
                    ::mbu_sub(out, q2+psize, p2+psize, psize);
                    LOG_DEBUG("::mbu_mul_x(p2, out, iqmp, psize)...");
                    ::mbu_mul_x(p2, out, iqmp, psize);
                    LOG_DEBUG("::mbu_mod(out, p2, p1, modsize)...");
                    ::mbu_mod(out, p2, p1, modsize);
                    LOG_DEBUG("::mbu_sub(p2, p, out+psize, psize)...");
                    ::mbu_sub(p2, p, out+psize, psize);
                } else {
                    LOG_DEBUG("::mbu_sub(out, p2+psize, q2+psize, psize)...");
                    ::mbu_sub(out, p2+psize, q2+psize, psize);
                    LOG_DEBUG(":mbu_mul_x(in, out, iqmp, psize)...");
                    ::mbu_mul_x(in, out, iqmp, psize);
                    LOG_DEBUG("::mbu_mod(out, in, p1, modsize)...");
                    ::mbu_mod(out, in, p1, modsize);
                    LOG_DEBUG(":mbu_set(p2, out+psize, psize)...");
                    ::mbu_set(p2, out+psize, psize);
                }
                // out = q2 + q * p2
                //
                LOG_DEBUG("::mbu_mul_x(in, q, p2, psize)...");
                ::mbu_mul_x(in, q, p2, psize);
                LOG_DEBUG("::mbu_add(out, in, q2, modsize)...");
                ::mbu_add(out, in, q2, modsize);
#endif // ndef ETIRIS_GENERIC_MBUINT_H
                
                LOG_DEBUG("::mbu_get(o, out, modsize)...");
                ::mbu_get(o, out, modsize);
                return modsize;
            }
        }
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t set_d_msb(const byte_t* to, size_t tosize) {
        uint8* d = 0;
        if ((d = this->d()) && (to) && (tosize) && (tosize <= MBU_MAX)) {
            LOG_DEBUG("::mbu_set(d, to = " << x_to_string(to, tosize) << ", tosize = " << tosize << ")...");
            ::mbu_set(d, to, tosize);
            this->set_dsize(tosize);
            return tosize;
        }
        return 0;
    }
    virtual ssize_t get_d_msb(byte_t* to, size_t tosize) const {
        uint8* d = 0;
        size_t size = 0;
        if ((d = this->d()) && (size = this->dsize()) && (to) && (tosize >= size)) {
            ::mbu_get(d, to, size);
            LOG_DEBUG("...::mbu_get(d, to = " << x_to_string(to, size) << ", size = " << size << ")");
            return size;
        }
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t set_p_msb(const byte_t* to, size_t tosize) {
        uint8* p = 0;
        if ((p = this->p()) && (to) && (tosize) && (tosize <= MBU_MAX)) {
            LOG_DEBUG("::mbu_set(p, to = " << x_to_string(to, tosize) << ", tosize = " << tosize << ")...");
            ::mbu_set(p, to, tosize);
            this->set_psize(tosize);
            return tosize;
        }
        return 0;
    }
    virtual ssize_t get_p_msb(byte_t* to, size_t tosize) const {
        uint8* p = 0;
        size_t size = 0;
        if ((p = this->p()) && (size = this->psize()) && (to) && (tosize >= size)) {
            ::mbu_get(p, to, size);
            LOG_DEBUG("...::mbu_get(p, to = " << x_to_string(to, size) << ", size = " << size << ")");
            return size;
        }
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t set_q_msb(const byte_t* to, size_t tosize) {
        uint8* q = 0;
        if ((q = this->q()) && (to) && (tosize) && (tosize <= MBU_MAX)) {
            LOG_DEBUG("::mbu_set(q, to = " << x_to_string(to, tosize) << ", tosize = " << tosize << ")...");
            ::mbu_set(q, to, tosize);
            return tosize;
        }
        return 0;
    }
    virtual ssize_t get_q_msb(byte_t* to, size_t tosize) const {
        uint8* q = 0;
        size_t size = 0;
        if ((q = this->q()) && (size = this->psize()) && (to) && (tosize >= size)) {
            ::mbu_get(q, to, size);
            LOG_DEBUG("...::mbu_get(q, to = " << x_to_string(to, size) << ", size = " << size << ")");
            return size;
        }
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t set_dmp1_msb(const byte_t* to, size_t tosize) {
        uint8* dmp1 = 0;
        if ((dmp1 = this->dmp1()) && (to) && (tosize) && (tosize <= MBU_MAX)) {
            LOG_DEBUG("::mbu_set(dmp1, to = " << x_to_string(to, tosize) << ", tosize = " << tosize << ")...");
            ::mbu_set(dmp1, to, tosize);
            return tosize;
        }
        return 0;
    }
    virtual ssize_t get_dmp1_msb(byte_t* to, size_t tosize) const {
        uint8* dmp1 = 0;
        size_t size = 0;
        if ((dmp1 = this->dmp1()) && (size = this->psize()) && (to) && (tosize >= size)) {
            ::mbu_get(dmp1, to, size);
            LOG_DEBUG("...::mbu_get(dmp1, to = " << x_to_string(to, size) << ", size = " << size << ")");
            return size;
        }
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t set_dmq1_msb(const byte_t* to, size_t tosize) {
        uint8* dmq1 = 0;
        if ((dmq1 = this->dmq1()) && (to) && (tosize) && (tosize <= MBU_MAX)) {
            LOG_DEBUG("::mbu_set(dmq1, to = " << x_to_string(to, tosize) << ", tosize = " << tosize << ")...");
            ::mbu_set(dmq1, to, tosize);
            return tosize;
        }
        return 0;
    }
    virtual ssize_t get_dmq1_msb(byte_t* to, size_t tosize) const {
        uint8* dmq1 = 0;
        size_t size = 0;
        if ((dmq1 = this->dmq1()) && (size = this->psize()) && (to) && (tosize >= size)) {
            ::mbu_get(dmq1, to, size);
            LOG_DEBUG("...::mbu_get(dmq1, to = " << x_to_string(to, size) << ", size = " << size << ")");
            return size;
        }
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t set_iqmp_msb(const byte_t* to, size_t tosize) {
        uint8* iqmp = 0;
        if ((iqmp = this->iqmp()) && (to) && (tosize) && (tosize <= MBU_MAX)) {
            LOG_DEBUG("::mbu_set(iqmp, to = " << x_to_string(to, tosize) << ", tosize = " << tosize << ")...");
            ::mbu_set(iqmp, to, tosize);
            return tosize;
        }
        return 0;
    }
    virtual ssize_t get_iqmp_msb(byte_t* to, size_t tosize) const {
        uint8* iqmp = 0;
        size_t size = 0;
        if ((iqmp = this->iqmp()) && (size = this->psize()) && (to) && (tosize >= size)) {
            ::mbu_get(iqmp, to, size);
            LOG_DEBUG("...::mbu_get(iqmp, to = " << x_to_string(to, size) << ", size = " << size << ")");
            return size;
        }
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual uint8* d () const {
        return (uint8*) d_;
    }
    virtual uint8* p () const {
        return (uint8*) p_;
    }
    virtual uint8* q () const {
        return (uint8*) q_;
    }
    virtual uint8* dmp1 () const {
        return (uint8*) dmp1_;
    }
    virtual uint8* dmq1 () const {
        return (uint8*) dmq1_;
    }
    virtual uint8* iqmp () const {
        return (uint8*) iqmp_;
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
    uint8 d_[MBU_MAX], p_[MBU_MAX], q_[MBU_MAX], 
          dmp1_[MBU_MAX], dmq1_[MBU_MAX], iqmp_[MBU_MAX];
};
typedef private_keyt<> private_key;

} // namespace mb 
} // namespace rsa 
} // namespace crypto 
} // namespace cifra 

#endif // _CIFRA_CRYPTO_RSA_MB_PRIVATE_KEY_HPP 
