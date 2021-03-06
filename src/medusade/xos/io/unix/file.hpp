///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2015 $organization$
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
///   File: file.hpp
///
/// Author: $author$
///   Date: 4/16/2015
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_IO_UNIX_FILE_HPP
#define _XOS_NADIR_XOS_IO_UNIX_FILE_HPP

#include "xos/base/base.hpp"

namespace xos {
namespace io {
namespace unix {

typedef int fd_t;
typedef int invalid_fd_t;
enum { invalid_fd = 0 };

} // namespace unix
} // namespace io 
} // namespace xos 

#endif // _XOS_NADIR_XOS_IO_UNIX_FILE_HPP 
