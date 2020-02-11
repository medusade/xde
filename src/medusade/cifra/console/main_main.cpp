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
///   File: main_main.cpp
///
/// Author: $author$
///   Date: 3/2/2018
///////////////////////////////////////////////////////////////////////
#include "cifra/console/main_main.hpp"
#include "xos/console/logger.hpp"

namespace cifra {
namespace console {

} // namespace console 
} // namespace cifra 

///////////////////////////////////////////////////////////////////////
/// Function: main
///////////////////////////////////////////////////////////////////////
int main(int argc, char** argv, char** env) {
    int err = 0;

    ERR_LOG_DEBUG("try {...")
    try {
        xos::console::logger logger();

        ERR_LOG_DEBUG("xos::base::main::the_main(argc, argv, env)...");
        err = xos::base::main::the_main(argc, argv, env);
        ERR_LOG_DEBUG("..." << err << " = xos::base::main::the_main(argc, argv, env)");
        ERR_LOG_DEBUG("...} try");
    } catch (...) {
        ERR_LOG_ERROR("...} catch (...)");
    }
    return err;
}
