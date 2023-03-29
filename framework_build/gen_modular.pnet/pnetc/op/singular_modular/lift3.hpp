#ifndef _PNETC_OP_singular_modular_lift3
#define _PNETC_OP_singular_modular_lift3

#include <we/type/literal/control.hpp>
#include <pnetc/type/modular_data.hpp>
#include <string>

namespace pnetc
{
  namespace op
  {
    namespace singular_modular
    {
      void lift3
        ( const std::string& implementation
        , const ::pnetc::type::modular_data::modular_data& mod_res4
        , const ::pnetc::type::modular_data::modular_data& accumulator
        , const std::string& function_name
        , const std::string& needed_library
        , const std::string& base_filename
        , we::type::literal::control& up
        , long& counter
        , ::pnetc::type::modular_data::modular_data& out
        );
    }
  }
}
#endif
