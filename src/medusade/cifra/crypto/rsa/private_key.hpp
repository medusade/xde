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
#ifndef _CIFRA_CRYPTO_RSA_PRIVATE_KEY_HPP
#define _CIFRA_CRYPTO_RSA_PRIVATE_KEY_HPP

#include "cifra/crypto/rsa/key.hpp"

namespace cifra {
namespace crypto {
namespace rsa {

///////////////////////////////////////////////////////////////////////
///  Class: private_key_implementt
///////////////////////////////////////////////////////////////////////
template
<class TImplements = key_implement>

class _EXPORT_CLASS private_key_implementt: virtual public TImplements {
public:
    typedef TImplements Implements;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t set_msb
    (const byte_t* modulus, size_t modsize,
     const byte_t* d, size_t dsize, const byte_t* p, const byte_t* q,
     const byte_t* dmp1, const byte_t* dmq1, const byte_t* iqmp, size_t psize) {
        ssize_t count = 0, amount = 0;
        if (0 <= (amount = this->set_modulus_msb(modulus, modsize))) {
            count += amount;
            if (0 <= (amount = this->set_d_msb(d, dsize))) {
                count += amount;
                if (0 <= (amount = this->set_p_msb(p, psize))) {
                    count += amount;
                    if (0 <= (amount = this->set_q_msb(q, psize))) {
                        count += amount;
                        if (0 <= (amount = this->set_dmp1_msb(dmp1, psize))) {
                            count += amount;
                            if (0 <= (amount = this->set_dmq1_msb(dmq1, psize))) {
                                count += amount;
                                if (0 <= (amount = this->set_iqmp_msb(iqmp, psize))) {
                                    count += amount;
                                    return count;
                                }
                            }
                        }
                    }
                }
            }
        }
        return 0;
    }
    virtual ssize_t get_msb
    (byte_t* modulus, size_t modsize,
     byte_t* d, size_t dsize, byte_t* p, byte_t* q,
     byte_t* dmp1, byte_t* dmq1, byte_t* iqmp, size_t psize) {
        ssize_t count = 0, amount = 0;
        if (0 <= (amount = this->get_modulus_msb(modulus, modsize))) {
            count += amount;
            if (0 <= (amount = this->get_d_msb(d, dsize))) {
                count += amount;
                if (0 <= (amount = this->get_p_msb(p, psize))) {
                    count += amount;
                    if (0 <= (amount = this->get_q_msb(q, psize))) {
                        count += amount;
                        if (0 <= (amount = this->get_dmp1_msb(dmp1, psize))) {
                            count += amount;
                            if (0 <= (amount = this->get_dmq1_msb(dmq1, psize))) {
                                count += amount;
                                if (0 <= (amount = this->get_iqmp_msb(iqmp, psize))) {
                                    count += amount;
                                    return count;
                                }
                            }
                        }
                    }
                }
            }
        }
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t set_d_msb(const byte_t* to, size_t tosize) {
        return 0;
    }
    virtual ssize_t get_d_msb(byte_t* to, size_t tosize) const {
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t set_p_msb(const byte_t* to, size_t tosize) {
        return 0;
    }
    virtual ssize_t get_p_msb(byte_t* to, size_t tosize) const {
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t set_q_msb(const byte_t* to, size_t tosize) {
        return 0;
    }
    virtual ssize_t get_q_msb(byte_t* to, size_t tosize) const {
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t set_dmp1_msb(const byte_t* to, size_t tosize) {
        return 0;
    }
    virtual ssize_t get_dmp1_msb(byte_t* to, size_t tosize) const {
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t set_dmq1_msb(const byte_t* to, size_t tosize) {
        return 0;
    }
    virtual ssize_t get_dmq1_msb(byte_t* to, size_t tosize) const {
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t set_iqmp_msb(const byte_t* to, size_t tosize) {
        return 0;
    }
    virtual ssize_t get_iqmp_msb(byte_t* to, size_t tosize) const {
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t set_dsize(size_t to) {
        return 0;
    }
    virtual ssize_t dsize() const {
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t set_psize(size_t to) {
        return 0;
    }
    virtual ssize_t psize() const {
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef private_key_implementt<> private_key_implement;

///////////////////////////////////////////////////////////////////////
///  Class: private_keyt
///////////////////////////////////////////////////////////////////////
template
<class TImplements = private_key_implement, class TExtends = key>

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
            this->set_msb(modulus, modsize, d, dsize, p, q, dmp1, dmq1, iqmp);
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
    virtual ssize_t set_dsize(size_t to) {
        dsize_ = to;
        return dsize_;
    }
    virtual ssize_t dsize() const {
        return dsize_;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t set_psize(size_t to) {
        psize_ = to;
        return psize_;
    }
    virtual ssize_t psize() const {
        return psize_;
    }
protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void init() {
        psize_ = dsize_ = 0;
    }
    virtual void fini() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    size_t dsize_, psize_;
};
typedef private_keyt<> private_key;

} // namespace rsa 
} // namespace crypto 
} // namespace cifra 

#endif // _CIFRA_CRYPTO_RSA_PRIVATE_KEY_HPP 
