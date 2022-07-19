#include <pnetc/op/singular_modular/lift2.hpp>
#include <string>
#include <share/include/modular_interface.hpp>
#include <util-generic/dynamic_linking.hpp>

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
        )
      {
#line 254 "/home/hbn/Documents/AIMS/projet/master/github/modular/workflow/modular.xpnet"

				std::string filename;
         filename = fhg::util::scoped_dlhandle
         (implementation, RTLD_GLOBAL | RTLD_NOW | RTLD_DEEPBIND)
         .sym<decltype (singular_modular_lift)> ("singular_modular_lift")
          ( lhs,rhs,function_name, needed_library,base_filename,"2");
					out = filename;
     
      }
    }
  }
}