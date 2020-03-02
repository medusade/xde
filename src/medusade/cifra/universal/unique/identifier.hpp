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
///   File: identifier.hpp
///
/// Author: $author$
///   Date: 2/10/2020
///////////////////////////////////////////////////////////////////////
#ifndef _CIFRA_UNIVERSAL_UNIQUE_IDENTIFIER_HPP
#define _CIFRA_UNIVERSAL_UNIQUE_IDENTIFIER_HPP

#include "cifra/universal/unique/actual/identifier.hpp"
#include "xos/base/wrapped.hpp"

namespace cifra {
namespace universal {
namespace unique {

///////////////////////////////////////////////////////////////////////
///  Class: identifiert
///////////////////////////////////////////////////////////////////////
template 
<class TExtends = xos::base::wrappedt<actual::identifier>, 
 class TImplements = typename TExtends::Implements>

class _EXPORT_CLASS identifiert: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef identifiert Derives;
    
    typedef typename Extends::wrapped_t actual_t;

    ///////////////////////////////////////////////////////////////////////
    ///  Class: Version
    ///////////////////////////////////////////////////////////////////////
    class _EXPORT_CLASS Version {
    public:
        typedef int Which;
        enum {
            None          = actual::identifier::VERSION_NONE,
            TimeBased     = actual::identifier::VERSION_TIME_BASED,
            DceSecurity   = actual::identifier::VERSION_DCE_SECURITY,
            NameBasedMd5  = actual::identifier::VERSION_NAME_BASED_MD5,
            Random        = actual::identifier::VERSION_RANDOM,
            NameBasedSha1 = actual::identifier::VERSION_NAME_BASED_SHA1
        };
        ///////////////////////////////////////////////////////////////////////
        /// constructors / destructor
        ///////////////////////////////////////////////////////////////////////
        Version(const Version& copy): m_which(copy.m_which) {}
        Version(Which which = None): m_which(which) {}
        operator Which () const { return m_which; }
    protected:
        Which m_which;
    }; /// class _EXPORT_CLASS Version

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    identifiert(const identifiert &copy) {
    }
    identifiert() {
    }
    virtual ~identifiert() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual actual_t* generate(typename Version::Which which) {
        if (Version::None == (which)) {
            return generate();
        }
        return 0;
    }
    virtual actual_t* generate() {
        return generate_time_based();
    }
    virtual actual_t* generate_time_based() {
        return 0;
    }
    virtual void clear() {
        memset(&this->actual(), 0, sizeof(actual_t));
        m_string.clear();
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual string_t& set_string(const actual_t& to) {
        io::string::writer writer(m_string);
        m_string.clear();
        WriteX(writer);
        return (string_t&)m_string;
    }
    virtual string_t& string() const {
        return (string_t&)m_string;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool operator != (const Derives& to) const {
        return (0 != (memcmp(&this->actual(), &to.actual(), sizeof(actual_t))));
    }
    virtual bool operator == (const Derives& to) const {
        return (0 == (memcmp(&this->actual(), &to.actual(), sizeof(actual_t))));
    }
    virtual actual_t& actual() const {
        return this->wrapped();
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t WriteX(io::string::writer& writer, char A = 'A', char separator = '-') const {
        actual_t& actual = this->actual();
        ssize_t count = 0, count2 = 0;

        if (0 < (count = WriteX
            (writer, actual.m_timeLow.m_b, sizeof(actual.m_timeLow.m_b), A, separator))) {

            if (0 < (count2 = WriteX
                (writer, actual.m_timeMid.m_b, sizeof(actual.m_timeMid.m_b), A, separator))) {
    
                count += count2;
                if (0 < (count2 = WriteX
                    (writer, actual.m_timeHiAndVersion.m_b, sizeof(actual.m_timeHiAndVersion.m_b), A, separator))) {
        
                    count += count2;
                    if (0 < (count2 = WriteX
                        (writer, actual.m_clockSeq.m_b, sizeof(actual.m_clockSeq.m_b), A, separator))) {
            
                        count += count2;
                        if (0 < (count2 = WriteX
                            (writer, actual.m_node.m_b, sizeof(actual.m_node.m_b), A))) {
                            count += count2;
                        }
                    }
                }
            }
        }
        return count;
    }
    virtual ssize_t WriteX
    (io::string::writer& writer, const uint8_t* value, size_t size, char A = 'A', char separator = 0) const {
        const bool upperCase = ('A' == A);
        ssize_t count = 0, count2 = 0;

        if (0 < (count = writer.writex(value, size, upperCase))) {
            if (separator) {
                if (0 < (count2 = writer.write(&separator, sizeof(separator)))) {
                    count += count2;
                }
            }
        }
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual uint8_t& TimeToMsb(actual_t& actual) {
        ToMsb(*actual.m_timeLow.m_b, actual.m_timeLow.m_l, sizeof(actual.m_timeLow.m_l));
        ToMsb(*actual.m_timeMid.m_b, actual.m_timeMid.m_w, sizeof(actual.m_timeMid.m_w));
        ToMsb(*actual.m_timeHiAndVersion.m_b, actual.m_timeHiAndVersion.m_w, sizeof(actual.m_timeHiAndVersion.m_w));
        return *actual.m_b;
    }
    virtual uint8_t& ToMsb(uint8_t& to, unsigned long value, size_t size) const {
        unsigned long msbValue = 0;
        for (int b = 0; b < size; ++b) {
            msbValue <<= 8;
            msbValue |= (value & 0xFF);
            value >>= 8;
        }
        for (int b = 0; b < size; ++b) {
            (&to)[b] = (msbValue & 0xFF);
            msbValue >>= 8;
        }
        return to;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    string_t m_string;
}; /// class _EXPORT_CLASS identifiert
typedef identifiert<> identifier;

} /// namespace unique
} /// namespace universal
} /// namespace cifra

#endif /// _CIFRA_UNIVERSAL_UNIQUE_IDENTIFIER_HPP 
