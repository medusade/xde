/**
 **********************************************************************
 * Copyright (c) 1988-2020 $organization$
 *
 * This software is provided by the author and contributors ``as is'' 
 * and any express or implied warranties, including, but not limited to, 
 * the implied warranties of merchantability and fitness for a particular 
 * purpose are disclaimed. In no event shall the author or contributors 
 * be liable for any direct, indirect, incidental, special, exemplary, 
 * or consequential damages (including, but not limited to, procurement 
 * of substitute goods or services; loss of use, data, or profits; or 
 * business interruption) however caused and on any theory of liability, 
 * whether in contract, strict liability, or tort (including negligence 
 * or otherwise) arising in any way out of the use of this software, 
 * even if advised of the possibility of such damage.
 *
 *   File: ccryptohash.hxx
 *
 * Author: $author$
 *   Date: 2/7/2020
 **********************************************************************
 */
#ifndef CCRYPTOHASH_HXX
#define CCRYPTOHASH_HXX

#include "ccryptobase.hxx"

/**
 **********************************************************************
 *  Class: cCryptoHash
 *
 * Author: $author$
 *   Date: 2/7/2020
 **********************************************************************
 */
class cCryptoHash: virtual public cCryptoBase {
public:
    typedef cCryptoBase cImplements;
    typedef cCryptoHash cDerives;
    /**
     **********************************************************************
     *  Destructor: ~cCryptoHash
     *
     *      Author: $author$
     *        Date: 2/7/2020
     **********************************************************************
     */
    virtual ~cCryptoHash() {
    }
    /**
     **********************************************************************
     *  Initialize / Finalize / Hash / Size
     *
     *      Author: $author$
     *        Date: 2/7/2020
     **********************************************************************
     */
    virtual TLENGTH Initialize(const void* key, TSIZE length) { 
        cDerives* delegatedTo = 0;
        if ((delegatedTo = DelegatedTo())) {
            return delegatedTo->Initialize(key, length);
        }
        return 0; 
    }
    virtual TLENGTH Initialize(const void* key) { 
        cDerives* delegatedTo = 0;
        if ((delegatedTo = DelegatedTo())) {
            return delegatedTo->Initialize(key);
        }
        return 0; 
    }
    virtual TLENGTH Initialize() { 
        cDerives* delegatedTo = 0;
        if ((delegatedTo = DelegatedTo())) {
            return delegatedTo->Initialize();
        }
        return 0; 
    }
    virtual TLENGTH Finalize(void* out, TSIZE size) { 
        cDerives* delegatedTo = 0;
        if ((delegatedTo = DelegatedTo())) {
            return delegatedTo->Finalize(out, size);
        }
        return 0; 
    }
    virtual TLENGTH Hash(const void* in, TSIZE length) { 
        cDerives* delegatedTo = 0;
        if ((delegatedTo = DelegatedTo())) {
            return delegatedTo->Hash(in, length);
        }
        return 0; 
    }
    virtual TLENGTH Hash(const void* in) { 
        cDerives* delegatedTo = 0;
        if ((delegatedTo = DelegatedTo())) {
            return delegatedTo->Hash(in);
        }
        return 0; 
    }
    virtual TLENGTH Size() const { 
        cDerives* delegatedTo = 0;
        if ((delegatedTo = DelegatedTo())) {
            return delegatedTo->Size();
        }
        return 0; 
    }
    /**
     **********************************************************************
     *  DelegatedTo
     *
     *      Author: $author$
     *        Date: 2/7/2020
     **********************************************************************
     */
    virtual cDerives* DelegatedTo() const {
        return 0;
    }
}; /* class cCryptoHash */

/**
 **********************************************************************
 *  Class: cCryptoHashT
 *
 * Author: $author$
 *   Date: 2/7/2020
 **********************************************************************
 */
template <class THash>
class cCryptoHashT: virtual public cCryptoHash, public cBase {
public:
    typedef cCryptoHash cImplements;
    typedef cBase cExtends;
    typedef cCryptoHashT cDerives;
protected:
    THash m_hash;
public:
    /**
     **********************************************************************
     * cCryptoHashT / ~cCryptoHashT
     *
     *      Author: $author$
     *        Date: 2/7/2020
     **********************************************************************
     */
    cCryptoHashT() {
    }
    virtual ~cCryptoHashT() {
    }
    /**
     **********************************************************************
     *  Initialize / Finalize / Hash / Size
     *
     *      Author: $author$
     *        Date: 2/7/2020
     **********************************************************************
     */
    virtual TLENGTH Initialize(const void* key, TSIZE length) { 
        return m_hash.initialize(key, length); 
    }
    virtual TLENGTH Initialize(const void* key) { 
        return m_hash.initialize(key); 
    }
    virtual TLENGTH Initialize() { 
        return m_hash.initialize(); 
    }
    virtual TLENGTH Finalize(void* out, TSIZE size) { 
        return m_hash.finalize(out, size); 
    }
    virtual TLENGTH Hash(const void* in, TSIZE length) { 
        return m_hash.hash(in, length);
    }
    virtual TLENGTH Hash(const void* in) { 
        return m_hash.hash(in); 
    }
    virtual TLENGTH Size() const { 
        return m_hash.hash_size(); 
    }
}; /* class cCryptoHashT */

#endif /* ndef CCRYPTOHASH_HXX */
