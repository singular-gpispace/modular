#ifndef _PNETC_OP_singular_modular_reconstest
#define _PNETC_OP_singular_modular_reconstest

#include <pnetc/type/result_bool_type.hpp>
#include <pnetc/type/modular_data.hpp>
#include <string>

namespace pnetc
{
  namespace op
  {
    namespace singular_modular
    {
      void reconstest
        ( const std::string& implementation
        , const ::pnetc::type::modular_data::modular_data& lifted_res
        , const ::pnetc::type::modular_data::modular_data& one
        , const std::string& function_name
        , const std::string& needed_library
        , const std::string& base_filename
        , ::pnetc::type::result_bool_type::result_bool_type& out
        );
    }
  }
}
#endif
