#include <pnetc/op/singular_modular/init.hpp>
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
        )
      {
#line 63 "/home/hbn/Documents/AIMS/projet/master/github/modular_independent_sub5/workflow/modular.xpnet"

                    for (int i (0); i<input_bal1; ++i)
                {
                    bal1.emplace_back(we::type::literal::control{});
                }
                for (int i (0); i<input_bal2; ++i)
                {
                    bal2.emplace_back(we::type::literal::control{});
                }
                 
      }
    }
  }
}