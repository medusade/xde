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
///   File: main_opt.hpp
///
/// Author: $author$
///   Date: 3/2/2018
///////////////////////////////////////////////////////////////////////
#ifndef _CIFRA_CONSOLE_MAIN_OPT_HPP
#define _CIFRA_CONSOLE_MAIN_OPT_HPP

#include "cifra/base/base.hpp"
#include "xos/base/getopt/main.hpp"

#define CIFRA_MAIN_OPT_ARGUMENT_NONE XOS_MAIN_OPT_ARGUMENT_NONE
#define CIFRA_MAIN_OPT_ARGUMENT_REQUIRED XOS_MAIN_OPT_ARGUMENT_REQUIRED
#define CIFRA_MAIN_OPT_ARGUMENT_OPTIONAL XOS_MAIN_OPT_ARGUMENT_OPTIONAL

#define CIFRA_MAIN_LOGGING_OPTVAL_C XOS_MAIN_LOGGING_OPTVAL_C
#define CIFRA_MAIN_LOGGING_OPTARG XOS_MAIN_LOGGING_OPTARG
#define CIFRA_MAIN_LOGGING_OPTUSE XOS_MAIN_LOGGING_OPTUSE

#define CIFRA_MAIN_HELP_OPTVAL_C XOS_MAIN_HELP_OPTVAL_C
#define CIFRA_MAIN_HELP_OPTARG XOS_MAIN_HELP_OPTARG
#define CIFRA_MAIN_HELP_OPTUSE XOS_MAIN_HELP_OPTUSE

#define CIFRA_CONSOLE_MAIN_LOGGING_LEVELS_OPT "logging"
#define CIFRA_CONSOLE_MAIN_LOGGING_LEVELS_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define CIFRA_CONSOLE_MAIN_LOGGING_LEVELS_OPTARG_RESULT 0
#define CIFRA_CONSOLE_MAIN_LOGGING_LEVELS_OPTARG CIFRA_MAIN_LOGGING_OPTARG
#define CIFRA_CONSOLE_MAIN_LOGGING_LEVELS_OPTUSE CIFRA_MAIN_LOGGING_OPTUSE
#define CIFRA_CONSOLE_MAIN_LOGGING_LEVELS_OPTVAL_S "l:"
#define CIFRA_CONSOLE_MAIN_LOGGING_LEVELS_OPTVAL_C 'l'
#define CIFRA_CONSOLE_MAIN_LOGGING_LEVELS_OPTION \
   {CIFRA_CONSOLE_MAIN_LOGGING_LEVELS_OPT, \
    CIFRA_CONSOLE_MAIN_LOGGING_LEVELS_OPTARG_REQUIRED, \
    CIFRA_CONSOLE_MAIN_LOGGING_LEVELS_OPTARG_RESULT, \
    CIFRA_CONSOLE_MAIN_LOGGING_LEVELS_OPTVAL_C}, \

#define CIFRA_CONSOLE_MAIN_HELP_OPT "help"
#define CIFRA_CONSOLE_MAIN_HELP_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define CIFRA_CONSOLE_MAIN_HELP_OPTARG_RESULT 0
#define CIFRA_CONSOLE_MAIN_HELP_OPTARG CIFRA_MAIN_HELP_OPTARG
#define CIFRA_CONSOLE_MAIN_HELP_OPTUSE CIFRA_MAIN_HELP_OPTUSE
#define CIFRA_CONSOLE_MAIN_HELP_OPTVAL_S "?"
#define CIFRA_CONSOLE_MAIN_HELP_OPTVAL_C '?'
#define CIFRA_CONSOLE_MAIN_HELP_OPTION \
   {CIFRA_CONSOLE_MAIN_HELP_OPT, \
    CIFRA_CONSOLE_MAIN_HELP_OPTARG_REQUIRED, \
    CIFRA_CONSOLE_MAIN_HELP_OPTARG_RESULT, \
    CIFRA_CONSOLE_MAIN_HELP_OPTVAL_C}, \

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define CIFRA_CONSOLE_MAIN_OPTIONS_CHARS \
    CIFRA_CONSOLE_MAIN_LOGGING_LEVELS_OPTVAL_S \
    CIFRA_CONSOLE_MAIN_HELP_OPTVAL_S \

#define CIFRA_CONSOLE_MAIN_OPTIONS_OPTIONS \
    CIFRA_CONSOLE_MAIN_LOGGING_LEVELS_OPTION \
    CIFRA_CONSOLE_MAIN_HELP_OPTION \

namespace cifra {

typedef int main_opt_argument_t;
enum {
    MAIN_OPT_ARGUMENT_NONE     = CIFRA_MAIN_OPT_ARGUMENT_NONE,
    MAIN_OPT_ARGUMENT_REQUIRED = CIFRA_MAIN_OPT_ARGUMENT_REQUIRED,
    MAIN_OPT_ARGUMENT_OPTIONAL = CIFRA_MAIN_OPT_ARGUMENT_OPTIONAL
};

namespace console {

typedef ::xos::base::getopt::main_implements main_opt_implements;
typedef ::xos::base::getopt::main main_opt_extends;
///////////////////////////////////////////////////////////////////////
///  Class: main_opt
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS main_opt
: virtual public main_opt_implements, public main_opt_extends {
public:
    typedef main_opt_implements Implements;
    typedef main_opt_extends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    main_opt() {
    }
    virtual ~main_opt() {
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int on_logging_levels_option
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc, char**argv, char**env) {
        int err = this->on_logging_option
        (CIFRA_MAIN_LOGGING_OPTVAL_C,
         optarg, optname, optind, argc, argv, env);
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int on_help_option
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc, char**argv, char**env) {
        int err = this->usage(argc, argv, env);
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int on_option
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc, char**argv, char**env) {
        int err = 0;
        switch(optval) {
        case CIFRA_CONSOLE_MAIN_LOGGING_LEVELS_OPTVAL_C:
            err = on_logging_levels_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case CIFRA_CONSOLE_MAIN_HELP_OPTVAL_C:
            err = on_help_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        default:
            err = Extends::on_option
            (optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char* option_usage
    (const char*& optarg, const struct option* longopt) {
        const char* chars = "";
        switch(longopt->val) {
        case CIFRA_CONSOLE_MAIN_LOGGING_LEVELS_OPTVAL_C:
            optarg = CIFRA_CONSOLE_MAIN_LOGGING_LEVELS_OPTARG;
            chars = CIFRA_CONSOLE_MAIN_LOGGING_LEVELS_OPTUSE;
            break;
        case CIFRA_CONSOLE_MAIN_HELP_OPTVAL_C:
            optarg = CIFRA_CONSOLE_MAIN_HELP_OPTARG;
            chars = CIFRA_CONSOLE_MAIN_HELP_OPTUSE;
            break;
        default:
            chars = Extends::option_usage(optarg, longopt);
        }
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char* options(const struct option*& longopts) {
        int err = 0;
        static const char* chars = CIFRA_CONSOLE_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            CIFRA_CONSOLE_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace console 
} // namespace cifra 

#endif // _CIFRA_CONSOLE_MAIN_OPT_HPP 
