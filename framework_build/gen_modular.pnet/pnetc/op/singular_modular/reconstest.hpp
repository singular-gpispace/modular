#ifndef _PNETC_OP_singular_modular_reconstest
#define _PNETC_OP_singular_modular_reconstest

#include <pnetc/type/result_bool_type.hpp>
#include <string>

namespace pnetc
{
  namespace op
  {
    namespace singular_modular
    {
      void reconstest
        ( const std::string& implementation
        , const std::string& lifted_res
        , const std::string& mod_res2
        , const std::string& function_name
        , const std::string& needed_library
        , const std::string& base_filename
        , ::pnetc::type::result_bool_type::result_bool_type& out
        );
    }
  }
}
#endif
