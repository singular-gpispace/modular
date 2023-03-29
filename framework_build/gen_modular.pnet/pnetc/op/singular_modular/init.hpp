#ifndef _PNETC_OP_singular_modular_init
#define _PNETC_OP_singular_modular_init

#include <list>
#include <we/type/value.hpp>

namespace pnetc
{
  namespace op
  {
    namespace singular_modular
    {
      void init
        ( const int& input_bal1
        , const int& input_bal2
        , std::list<pnet::type::value::value_type>& bal1
        , std::list<pnet::type::value::value_type>& bal2
        );
    }
  }
}
#endif
