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
///   File: address.hpp
///
/// Author: $author$
///   Date: 2/10/2020
///////////////////////////////////////////////////////////////////////
#ifndef _CIFRA_NETWORK_ETHERNET_ADDRESS_HPP
#define _CIFRA_NETWORK_ETHERNET_ADDRESS_HPP

#include "cifra/network/ethernet/actual/address.hpp"
#include "cifra/base/base.hpp"
#include "xos/base/wrapped.hpp"

namespace cifra {
namespace network {
namespace ethernet {

typedef xos::base::wrappedt<actual::address> addresst_extends;
typedef addresst_extends::Implements addresst_implements;
///////////////////////////////////////////////////////////////////////
///  Class: addresst
///////////////////////////////////////////////////////////////////////
template <class TImplements = addresst_implements, class TExtends = addresst_extends>
class _EXPORT_CLASS addresst: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef addresst Derives;
    
    typedef typename Extends::wrapped_t actual_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    addresst(const addresst &copy)
    : Extends(copy), 
      m_actual_name(copy.m_actual_name), 
      m_adapter_name(copy.m_adapter_name), m_adapter_index(copy.m_adapter_index) {
    }
    addresst(): m_adapter_index(-1) {
    }
    virtual ~addresst() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual Derives set(const actual_t& actual, const string_t& adapter_name, int adapter_index) {
        memcpy(&this->actual(), &actual, sizeof(actual_t));
        this->set_actual_name(actual);
        m_adapter_name.assign(adapter_name);
        m_adapter_index = adapter_index;
        return *this;
    }
    virtual Derives clear() {
        memset(&this->actual(), 0, sizeof(actual_t));
        m_actual_name.clear();
        m_adapter_name.clear();
        m_adapter_index = -1;
        return *this;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual actual_t* set_to_adapter(const string_t& named) {
        return 0;
    }
    virtual actual_t* set_to_adapter(int index) {
        return 0;
    }
    virtual actual_t* set_to_adapter() {
        return set_to_first_adapter();
    }
    virtual actual_t* set_to_first_adapter() {
        return set_to_adapter(0);
    }
    virtual actual_t* set_to_last_adapter() {
        return set_to_adapter(-1);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const actual_t* get_first() const {
        return 0;
    }
    virtual const actual_t* get_last() const {
        return 0;
    }
    virtual const actual_t* get_next(const actual_t* to) const {
        return 0;
    }
    virtual const actual_t* get_prev(const actual_t* to) const {
        return 0;
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
    virtual size_t actual_size() const {
        return sizeof(actual_t);
    }
    virtual string_t& adapter_name() const {
        return (string_t&)(m_adapter_name);
    }
    virtual int& adapter_index() const {
        return (int&)(m_adapter_index);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual string_t& set_actual_name(const actual_t& actual) {
        const char *separator = 0, *separator_chars = ":";
        m_actual_name.clear();
        for (size_t i = 0; i < sizeof(actual_t); ++i) {
            if (separator) {
                m_actual_name.append(separator);
            } else {
                separator = separator_chars;
            }
            m_actual_name.appendx(actual.m_b + i, 1, true);
        }
        return (string_t&)(m_actual_name);
    }
    virtual string_t& actual_name() const {
        return (string_t&)(m_actual_name);
    }
    virtual string_t& set_string(const actual_t& actual) {
        return set_actual_name(actual);
    }
    virtual string_t& string() const {
        return actual_name();
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    string_t m_actual_name, m_adapter_name;
    int m_adapter_index;
}; /// class _EXPORT_CLASS addresst
typedef addresst<> address;

} /// namespace ethernet
} /// namespace network
} /// namespace cifra

#endif /// _CIFRA_NETWORK_ETHERNET_ADDRESS_HPP 
