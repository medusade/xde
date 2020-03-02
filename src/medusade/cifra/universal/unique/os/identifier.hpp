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
#ifndef _CIFRA_UNIVERSAL_UNIQUE_OS_IDENTIFIER_HPP
#define _CIFRA_UNIVERSAL_UNIQUE_OS_IDENTIFIER_HPP

#include "cifra/universal/unique/identifier.hpp"
#include "cifra/universal/unique/os/os.hpp"

#if defined(WINDOWS)
#include "cifra/universal/unique/microsoft/windows/identifier.hpp"
#elif defined(MACOSX)
#include "cifra/universal/unique/apple/osx/identifier.hpp"
#else /// defined(WINDOWS)
#include "cifra/universal/unique/posix/identifier.hpp"
#endif /// defined(WINDOWS)

namespace cifra {
namespace universal {
namespace unique {
namespace os {

typedef os::identifier identifier;

} /// namespace os
} /// namespace unique
} /// namespace universal
} /// namespace cifra

#endif /// _CIFRA_UNIVERSAL_UNIQUE_OS_IDENTIFIER_HPP 
