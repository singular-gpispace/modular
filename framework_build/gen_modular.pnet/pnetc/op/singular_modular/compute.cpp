#include <pnetc/op/singular_modular/compute.hpp>
#include <pnetc/type/modular_data/op.hpp>
#include <pnetc/type/mod_input_data/op.hpp>
#include <string>
#include <share/include/modular_interface.hpp>
#include <util-generic/dynamic_linking.hpp>

namespace pnetc
{
  namespace op
  {
    namespace singular_modular
    {
      void compute
        ( const std::string& implementation
        , const ::pnetc::type::mod_input_data::mod_input_data& mod_input
        , const std::string& function_name
        , const std::string& needed_library
        , const std::string& base_filename
        , ::pnetc::type::modular_data::modular_data& mod_res1
        )
      {
#line 81 "/home/hbn/Documents/AIMS/projet/master/github/modular/workflow/modular.xpnet"

              std::string out;
              out = fhg::util::scoped_dlhandle
  (implementation, RTLD_GLOBAL | RTLD_NOW | RTLD_DEEPBIND)
  .sym<decltype (singular_modular_compute)> ("singular_modular_compute")
            ( mod_input.input,mod_input.prime
            , function_name, needed_library, base_filename
            );
            mod_res1.data =   out ;
						mod_res1.nb_prime = 1UL;
            
      }
    }
  }
}