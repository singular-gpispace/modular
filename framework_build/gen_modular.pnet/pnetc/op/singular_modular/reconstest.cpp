#include <pnetc/op/singular_modular/reconstest.hpp>
#include <pnetc/type/result_bool_type/op.hpp>
#include <pnetc/type/modular_data/op.hpp>
#include <string>
#include <share/include/modular_interface.hpp>
#include <util-generic/dynamic_linking.hpp>
#include <iostream>
#include <unistd.h>

namespace pnetc
{
  namespace op
  {
    namespace singular_modular
    {
      void reconstest
        ( const std::string& implementation
        , const ::pnetc::type::modular_data::modular_data& lifted_res
        , const ::pnetc::type::modular_data::modular_data& one
        , const std::string& function_name
        , const std::string& needed_library
        , const std::string& base_filename
        , ::pnetc::type::result_bool_type::result_bool_type& out
        )
      {
#line 37 "/home/hbn/Documents/AIMS/projet/master/github/modular_independent_sub5/workflow/reconstest.xpnet"

                        //usleep(200000);
                        std::pair<std::string,bool> pair_result = fhg::util::scoped_dlhandle
                         (implementation, RTLD_GLOBAL | RTLD_NOW | RTLD_DEEPBIND)
                         .sym<decltype (singular_modular_reconstest)> ("singular_modular_reconstest")
                         ( lifted_res.data, one.data,function_name, needed_library,base_filename);
                        out.farey_lift = pair_result.first;
                        out.chr_lift = lifted_res.data;
                        out.hashlead = lifted_res.hashlead;
                        out.nb_prime = lifted_res.nb_prime;
                        out.test = pair_result.second;
                        std::cout << out.nb_prime;
                        
      }
    }
  }
}