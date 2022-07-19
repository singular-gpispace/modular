#ifndef _PNETC_OP_singular_modular_lift2
#define _PNETC_OP_singular_modular_lift2

#include <string>

namespace pnetc
{
  namespace op
  {
    namespace singular_modular
    {
      void lift2
        ( const std::string& implementation
        , const std::string& lhs
        , const std::string& rhs
        , const std::string& function_name
        , const std::string& needed_library
        , const std::string& base_filename
        , std::string& out
        );
    }
  }
}
#endif
