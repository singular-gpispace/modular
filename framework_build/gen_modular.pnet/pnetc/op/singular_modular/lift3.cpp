#include <pnetc/op/singular_modular/lift3.hpp>
#include <string>
#include <share/include/modular_interface.hpp>
#include <util-generic/dynamic_linking.hpp>
#include <iostream>

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
        )
      {
#line 290 "/home/hbn/Documents/AIMS/projet/master/github/modular/workflow/modular.xpnet"

				 if(accumulator.empty())
				 {
					std::cout << "in transition_..._lift3" << std::endl;
					out = mod_res2;
				 }
				 else
				 {
					out = fhg::util::scoped_dlhandle
         (implementation, RTLD_GLOBAL | RTLD_NOW | RTLD_DEEPBIND)
         .sym<decltype (singular_modular_lift)> ("singular_modular_lift")
          ( mod_res2,accumulator,function_name, needed_library,base_filename,"3");
         }
        
      }
    }
  }
}