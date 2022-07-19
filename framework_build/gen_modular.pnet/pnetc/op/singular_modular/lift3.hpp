#ifndef _PNETC_OP_singular_modular_lift3
#define _PNETC_OP_singular_modular_lift3

#include <string>

namespace pnetc
{
  namespace op
  {
    namespace singular_modular
    {
      void lift3
        ( const std::string& implementation
        , const std::string& mod_res2
        , const std::string& accumulator
        , const std::string& function_name
        , const std::string& needed_library
        , const std::string& base_filename
        , std::string& out
        );
    }
  }
}
#endif
