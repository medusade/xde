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
#ifndef _CIFRA_CRYPTO_RANDOM_GENERATOR_HPP
#define _CIFRA_CRYPTO_RANDOM_GENERATOR_HPP

#include "cifra/base/base.hpp"

namespace cifra {
namespace crypto {
namespace random {

typedef implement_base generatort_implements;
///////////////////////////////////////////////////////////////////////
///  Class: generatort
///////////////////////////////////////////////////////////////////////
template <class TImplements = generatort_implements>
class _EXPORT_CLASS generatort: virtual public TImplements {
public:
    typedef TImplements Implements;
    typedef generatort Derives;
    
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t generate(void* out, size_t size) {
        return 0;
    }
    virtual ssize_t read(byte_t* bytes, size_t size) {
        return this->generate(bytes, size);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
}; /// class _EXPORT_CLASS generatort
typedef generatort<> generator;

} /// namespace random
} /// namespace crypto
} /// namespace cifra

#endif /// _CIFRA_CRYPTO_RANDOM_GENERATOR_HPP 
