#include <pnetc/op/singular_modular/lift1.hpp>
#include <pnetc/type/modular_data/op.hpp>
#include <string>
#include <share/include/modular_interface.hpp>
#include <util-generic/dynamic_linking.hpp>

namespace pnetc
{
  namespace op
  {
    namespace singular_modular
    {
      void lift1
        ( const std::string& implementation
        , const ::pnetc::type::modular_data::modular_data& lhs
        , const ::pnetc::type::modular_data::modular_data& rhs
        , const std::string& function_name
        , const std::string& needed_library
        , const std::string& base_filename
        , ::pnetc::type::modular_data::modular_data& out
        )
      {
#line 161 "/home/hbn/Documents/AIMS/projet/master/github/modular/workflow/modular.xpnet"

					std::string out_filename;
					out_filename = fhg::util::scoped_dlhandle
						(implementation, RTLD_GLOBAL | RTLD_NOW | RTLD_DEEPBIND)
							.sym<decltype (singular_modular_lift)> ("singular_modular_lift")
					  ( lhs.data,rhs.data,function_name,needed_library,base_filename,"1");
					out.data = out_filename;
					out.nb_prime = lhs.nb_prime + rhs.nb_prime;
					
      }
    }
  }
}