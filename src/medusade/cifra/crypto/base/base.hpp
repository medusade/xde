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
///   File: base.hpp
///
/// Author: $author$
///   Date: 3/2/2018
///////////////////////////////////////////////////////////////////////
#ifndef _CIFRA_CRYPTO_BASE_BASE_HPP
#define _CIFRA_CRYPTO_BASE_BASE_HPP

#include "cifra/base/base.hpp"

namespace cifra {
namespace crypto {

///////////////////////////////////////////////////////////////////////
/// Enum: error
///////////////////////////////////////////////////////////////////////
typedef int error;
enum {
    error_none = 0,

    error_failed,
    error_not_implemented,
    error_invalid_parameter,
    error_invalid_parameter_size,

    next_error,
    first_error = error_none,
    last_error = (next_error - 1)
};

typedef cifra::implement_base implement_baset_implements;
///////////////////////////////////////////////////////////////////////
///  Class: implement_baset
///////////////////////////////////////////////////////////////////////
template
<class TImplements = implement_baset_implements>

class _EXPORT_CLASS implement_baset: virtual public TImplements {
public:
    typedef TImplements Implements;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    inline uint64_t msb_to_uint64(const byte_t* bytes) const {
        return MSBToU64(bytes);
    }
    inline byte_t* uint64_to_msb(byte_t* bytes, uint64_t value) const {
        return U64ToMSB(bytes, value);
    }
    ///////////////////////////////////////////////////////////////////////
    inline uint64_t lsb_to_uint64(const byte_t* bytes) const {
        return LSBToU64(bytes);
    }
    inline byte_t* uint64_to_lsb(byte_t* bytes, uint64_t value) const {
        return U64ToLSB(bytes, value);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    inline uint32_t msb_to_uint32(const byte_t* bytes) const {
        return MSBToU32(bytes);
    }
    inline byte_t* uint32_to_msb(byte_t* bytes, uint32_t value) const {
        return U32ToMSB(bytes, value);
    }
    ///////////////////////////////////////////////////////////////////////
    inline uint32_t lsb_to_uint32(const byte_t* bytes) const {
        return LSBToU32(bytes);
    }
    inline byte_t* uint32_to_lsb(byte_t* bytes, uint32_t value) const {
        return U32ToLSB(bytes, value);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    inline byte_t *copy_8(byte_t *to, const byte_t *from) const {
        return Copy8(to, from);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    inline byte_t* copy_repeat
    (byte_t* to, size_t tosize, const byte_t* from, size_t fromsize) const {
        return CopyRepeat(to, tosize, from, fromsize);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    inline UINT64 MSBToU64(const BYTE* bytes) const {
        UINT64 value = (((((((((((((((UINT64)bytes[0])<<8) | bytes[1])<<8) | bytes[2])<<8) | bytes[3])<<8) | bytes[4])<<8) | bytes[5])<<8) | bytes[6])<<8) | bytes[7];
        return value;
    }
    inline BYTE* U64ToMSB(BYTE* bytes, UINT64 value) const {
        *(bytes+=7)=(BYTE)(value & 0xFF);
        *(--bytes)=(BYTE)((value>>=8) & 0xFF);
        *(--bytes)=(BYTE)((value>>=8) & 0xFF);
        *(--bytes)=(BYTE)((value>>=8) & 0xFF);
        *(--bytes)=(BYTE)((value>>=8) & 0xFF);
        *(--bytes)=(BYTE)((value>>=8) & 0xFF);
        *(--bytes)=(BYTE)((value>>=8) & 0xFF);
        *(--bytes)=(BYTE)((value>>=8) & 0xFF);
        return bytes;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    inline UINT64 LSBToU64(const BYTE* bytes) const {
        UINT64 value = (((((((((((((((UINT64)bytes[7])<<8) | bytes[6])<<8) | bytes[5])<<8) | bytes[4])<<8) | bytes[3])<<8) | bytes[2])<<8) | bytes[1])<<8) | bytes[0];
        return value;
    }
    inline BYTE* U64ToLSB(BYTE* bytes, UINT64 value) const {
        *(bytes)=(BYTE)(value & 0xFF);
        *(++bytes)=(BYTE)((value>>=8) & 0xFF);
        *(++bytes)=(BYTE)((value>>=8) & 0xFF);
        *(++bytes)=(BYTE)((value>>=8) & 0xFF);
        *(++bytes)=(BYTE)((value>>=8) & 0xFF);
        *(++bytes)=(BYTE)((value>>=8) & 0xFF);
        *(++bytes)=(BYTE)((value>>=8) & 0xFF);
        *(++bytes)=(BYTE)((value>>=8) & 0xFF);
        return bytes;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    inline UINT32 MSBToU32(const BYTE* bytes) const {
        UINT32 value = (((((((UINT32)bytes[0])<<8) | bytes[1])<<8) | bytes[2])<<8) | bytes[3];
        return value;
    }
    inline BYTE* U32ToMSB(BYTE* bytes, UINT32 value) const {
        *(bytes+=3)=(BYTE)(value & 0xFF);
        *(--bytes)=(BYTE)((value>>=8) & 0xFF);
        *(--bytes)=(BYTE)((value>>=8) & 0xFF);
        *(--bytes)=(BYTE)((value>>=8) & 0xFF);
        return bytes;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    inline UINT32 LSBToU32(const BYTE* bytes) const {
        UINT32 value = (((((((UINT32)bytes[3])<<8) | bytes[2])<<8) | bytes[1])<<8) | bytes[0];
        return value;
    }
    inline BYTE* U32ToLSB(BYTE* bytes, UINT32 value) const {
        *(bytes)=(BYTE)(value & 0xFF);
        *(++bytes)=(BYTE)((value>>=8) & 0xFF);
        *(++bytes)=(BYTE)((value>>=8) & 0xFF);
        *(++bytes)=(BYTE)((value>>=8) & 0xFF);
        return bytes;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    inline BYTE *Copy8(BYTE *to, const BYTE *from) const {
        *(to++) = *(from++);
        *(to++) = *(from++);
        *(to++) = *(from++);
        *(to++) = *(from++);
        *(to++) = *(from++);
        *(to++) = *(from++);
        *(to++) = *(from++);
        *(to++) = *(from++);
        return to;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    inline BYTE* CopyRepeat
    (BYTE* to, size_t tosize, const BYTE* from, size_t fromsize) const {
        for (size_t i=0; i<tosize; i+=fromsize)
        for (size_t j=0,k=i; (k<tosize) && (j<fromsize); k++,j++)
            to[k] = from[j];
        return to;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef implement_baset<> implement_base;

typedef implement_base baset_implements;
typedef cifra::base baset_extends;
///////////////////////////////////////////////////////////////////////
///  Class: baset
///////////////////////////////////////////////////////////////////////
template
<class TImplements = baset_implements, class TExtends = baset_extends>

class _EXPORT_CLASS baset: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    baset() {
    }
    virtual ~baset() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef baset<> base;

} // namespace crypto 
} // namespace cifra 

#endif // _CIFRA_CRYPTO_BASE_BASE_HPP 
