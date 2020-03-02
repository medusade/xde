///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2020 $organization$
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
///   File: generator.hpp
///
/// Author: $author$
///   Date: 2/8/2020
///////////////////////////////////////////////////////////////////////
#ifndef _CIFRA_CRYPTO_RANDOM_PSEUDO_GENERATOR_HPP
#define _CIFRA_CRYPTO_RANDOM_PSEUDO_GENERATOR_HPP

#include "cifra/crypto/random/generator.hpp"
#include "thirdparty/gnu/glibc/stdlib/rand_r.h"

namespace cifra {
namespace crypto {
namespace random {
namespace pseudo {

///////////////////////////////////////////////////////////////////////
///  Class: generatort
///////////////////////////////////////////////////////////////////////
template <class TImplements = random::generator, class TExtends = base>
class _EXPORT_CLASS generatort: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef generatort Derives;
    
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    generatort(const generatort &copy): m_avail(0), m_seed(0), m_rand(0) {
    }
    generatort(): m_avail(0), m_seed(0), m_rand(0) {
    }
    virtual ~generatort() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t generate(void* out, size_t size) {
        uint8_t* bytes = 0;

        if ((bytes = (uint8_t*)(out))) {
            size_t i = 0, j = 0, count = 0, length = 0;

            for (length = 0; length < size; ) {

                if (1 > m_avail) {
                    if (!(m_seed)) {
                        time_t t = time(&t);
                        m_seed = (unsigned)(t);
                    }
                    m_rand = (unsigned)rand_r(&m_seed);
                    m_avail = sizeof(m_rand);
                }
                if ((count = size-length) > m_avail) {
                    count = m_avail;
                }
                for (j = 0, i = 0; i < count; ++i) {
                    if ((bytes[length+j] = (uint8_t)(m_rand & 0xFF))) {
                        ++j;
                    }
                    m_rand >>= 8;
                }
                length += j;
                m_avail -= count;
            }
            return size;
        }
        return 0;
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual unsigned seed(unsigned seed) {
        m_seed = seed;
        m_avail = 0;
        m_rand = 0;
        return m_seed;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    size_t m_avail;
    unsigned m_seed;
    unsigned m_rand;
}; /// class _EXPORT_CLASS generatort
typedef generatort<> generator;

} /// namespace pseudo
} /// namespace random
} /// namespace crypto
} /// namespace cifra

#endif /// _CIFRA_CRYPTO_RANDOM_PSEUDO_GENERATOR_HPP 
