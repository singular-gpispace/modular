#ifndef _PNETC_OP_singular_modular_move
#define _PNETC_OP_singular_modular_move

#include <string>
#include <pnetc/type/modular_data.hpp>

namespace pnetc
{
  namespace op
  {
    namespace singular_modular
    {
      void move
        ( const ::pnetc::type::modular_data::modular_data& mod_res1
        , std::string& mod_res2
        );
    }
  }
}
#endif
