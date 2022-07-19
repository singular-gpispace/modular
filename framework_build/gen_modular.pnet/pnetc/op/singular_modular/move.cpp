#include <pnetc/op/singular_modular/move.hpp>
#include <string>
#include <pnetc/type/modular_data/op.hpp>
#include <iostream>

namespace pnetc
{
  namespace op
  {
    namespace singular_modular
    {
      void move
        ( const ::pnetc::type::modular_data::modular_data& mod_res1
        , std::string& mod_res2
        )
      {
#line 191 "/home/hbn/Documents/AIMS/projet/master/github/modular/workflow/modular.xpnet"

      mod_res2 = mod_res1.data;
			std::cout << "in transition_..._move "<< std::endl;
     
      }
    }
  }
}