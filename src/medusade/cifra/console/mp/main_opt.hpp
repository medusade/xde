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
///   Date: 3/14/2018
///////////////////////////////////////////////////////////////////////
#ifndef _CIFRA_CONSOLE_MP_MAIN_OPT_HPP
#define _CIFRA_CONSOLE_MP_MAIN_OPT_HPP

#include "cifra/console/main.hpp"

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define CIFRA_CONSOLE_MP_MAIN_MP_INTEGER_OPT "mp-integer"
#define CIFRA_CONSOLE_MP_MAIN_MP_INTEGER_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define CIFRA_CONSOLE_MP_MAIN_MP_INTEGER_OPTARG_RESULT 0
#define CIFRA_CONSOLE_MP_MAIN_MP_INTEGER_OPTARG_BN "(b)BIGNUM"
#define CIFRA_CONSOLE_MP_MAIN_MP_INTEGER_OPTARG_MP "(p)MP_INT"
#define CIFRA_CONSOLE_MP_MAIN_MP_INTEGER_OPTARG_MBU "(u)MB_UINT"
#define CIFRA_CONSOLE_MP_MAIN_MP_INTEGER_OPTARG_NULL "(n)null"
#define CIFRA_CONSOLE_MP_MAIN_MP_INTEGER_OPTARG \
    "{ " CIFRA_CONSOLE_MP_MAIN_MP_INTEGER_OPTARG_BN \
    " | " CIFRA_CONSOLE_MP_MAIN_MP_INTEGER_OPTARG_MP \
    " | " CIFRA_CONSOLE_MP_MAIN_MP_INTEGER_OPTARG_MBU \
    " | " CIFRA_CONSOLE_MP_MAIN_MP_INTEGER_OPTARG_NULL " }"
#define CIFRA_CONSOLE_MP_MAIN_MP_INTEGER_OPTUSE ""
#define CIFRA_CONSOLE_MP_MAIN_MP_INTEGER_OPTVAL_S "m:"
#define CIFRA_CONSOLE_MP_MAIN_MP_INTEGER_OPTVAL_C 'm'
#define CIFRA_CONSOLE_MP_MAIN_MP_INTEGER_OPTION \
   {CIFRA_CONSOLE_MP_MAIN_MP_INTEGER_OPT, \
    CIFRA_CONSOLE_MP_MAIN_MP_INTEGER_OPTARG_REQUIRED, \
    CIFRA_CONSOLE_MP_MAIN_MP_INTEGER_OPTARG_RESULT, \
    CIFRA_CONSOLE_MP_MAIN_MP_INTEGER_OPTVAL_C}, \

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define CIFRA_CONSOLE_MP_MAIN_OPTIONS_CHARS \
   CIFRA_CONSOLE_MP_MAIN_MP_INTEGER_OPTVAL_S \
   CIFRA_CONSOLE_MAIN_OPTIONS_CHARS

#define CIFRA_CONSOLE_MP_MAIN_OPTIONS_OPTIONS \
   CIFRA_CONSOLE_MP_MAIN_MP_INTEGER_OPTION \
   CIFRA_CONSOLE_MAIN_OPTIONS_OPTIONS

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define CIFRA_CONSOLE_MP_MAIN_ARGS 0
#define CIFRA_CONSOLE_MP_MAIN_ARGV

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

namespace cifra {
namespace console {
namespace mp {

typedef cifra::console::main_implements main_optt_implements;
typedef cifra::console::main main_optt_extends;
///////////////////////////////////////////////////////////////////////
///  Class: main_optt
///////////////////////////////////////////////////////////////////////
template
<class TImplements = main_optt_implements, class TExtends = main_optt_extends>

class _EXPORT_CLASS main_optt: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    main_optt() {
    }
    virtual ~main_optt() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int on_mp_bn_integer_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_mp_mp_integer_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_mp_mb_integer_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_mp_null_integer_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int on_mp_integer_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(optarg[0] != CIFRA_CONSOLE_MP_MAIN_MP_INTEGER_OPTARG_BN[1])) {
                err = this->on_mp_bn_integer_option
                (optval,optarg,optname,optind,argc,argv,env);
            } else {
                if (!(optarg[0] != CIFRA_CONSOLE_MP_MAIN_MP_INTEGER_OPTARG_MP[1])) {
                    err = this->on_mp_mp_integer_option
                    (optval,optarg,optname,optind,argc,argv,env);
                } else {
                    if (!(optarg[0] != CIFRA_CONSOLE_MP_MAIN_MP_INTEGER_OPTARG_MBU[1])) {
                        err = this->on_mp_mb_integer_option
                        (optval,optarg,optname,optind,argc,argv,env);
                    } else {
                        if (!(optarg[0] != CIFRA_CONSOLE_MP_MAIN_MP_INTEGER_OPTARG_NULL[1])) {
                            err = this->on_mp_null_integer_option
                            (optval,optarg,optname,optind,argc,argv,env);
                        } else {
                            err = this->on_invalid_option_arg
                            (optval,optarg,optname,optind,argc,argv,env);
                        }
                    }
                }
            }
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int on_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        switch(optval) {
        case CIFRA_CONSOLE_MP_MAIN_MP_INTEGER_OPTVAL_C:
            err = on_mp_integer_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        default:
            err = Extends::on_option
            (optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* option_usage
    (const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = "";
        switch(longopt->val) {
        case CIFRA_CONSOLE_MP_MAIN_MP_INTEGER_OPTVAL_C:
            optarg = CIFRA_CONSOLE_MP_MAIN_MP_INTEGER_OPTARG;
            chars = CIFRA_CONSOLE_MP_MAIN_MP_INTEGER_OPTUSE;
            break;
        default:
            chars = Extends::option_usage(optarg, longopt);
        }
        return chars;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* options(const struct option*& longopts) {
        int err = 0;
        static const char_t* chars = CIFRA_CONSOLE_MP_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            CIFRA_CONSOLE_MP_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }
    
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* arguments(const char_t**& argv) {
        static const char_t* _args = CIFRA_CONSOLE_MP_MAIN_ARGS;
        static const char_t* _argv[] = {
            CIFRA_CONSOLE_MP_MAIN_ARGV
            0};
        argv = _argv;
        return _args;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef main_optt<> main_opt;

} // namespace mp 
} // namespace console 
} // namespace cifra 

#endif // _CIFRA_CONSOLE_MP_MAIN_OPT_HPP 
