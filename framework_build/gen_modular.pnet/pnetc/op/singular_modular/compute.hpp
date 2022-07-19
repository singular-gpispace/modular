#ifndef _PNETC_OP_singular_modular_compute
#define _PNETC_OP_singular_modular_compute

#include <pnetc/type/modular_data.hpp>
#include <pnetc/type/mod_input_data.hpp>
#include <string>

namespace pnetc
{
  namespace op
  {
    namespace singular_modular
    {
      void compute
        ( const std::string& implementation
        , const ::pnetc::type::mod_input_data::mod_input_data& mod_input
        , const std::string& function_name
        , const std::string& needed_library
        , const std::string& base_filename
        , ::pnetc::type::modular_data::modular_data& mod_res1
        );
    }
  }
}
#endif
