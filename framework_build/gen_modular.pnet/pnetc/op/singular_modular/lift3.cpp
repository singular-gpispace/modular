#include <pnetc/op/singular_modular/lift3.hpp>
#include <we/type/literal/control.hpp>
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
      void lift3
        ( const std::string& implementation
        , const ::pnetc::type::modular_data::modular_data& mod_res4
        , const ::pnetc::type::modular_data::modular_data& accumulator
        , const std::string& function_name
        , const std::string& needed_library
        , const std::string& base_filename
        , we::type::literal::control& up
        , long& counter
        , ::pnetc::type::modular_data::modular_data& out
        )
      {
#line 526 "/home/hbn/Documents/AIMS/projet/master/github/modular_independent_sub5/workflow/modular.xpnet"

                    std::cout << " in singular_..._lift3 " << std::endl;
                    up = we::type::literal::control{};
                    counter = counter - 1;
                    if(mod_res4.hashlead.size() == accumulator.hashlead.size())
                    {
                        if(mod_res4.hashlead == accumulator.hashlead)
                        {
                            //usleep(200000);
                            std::string out_filename = fhg::util::scoped_dlhandle
                                (implementation, RTLD_GLOBAL | RTLD_NOW | RTLD_DEEPBIND)
                                .sym<decltype (singular_modular_lift)> ("singular_modular_lift")
                                ( mod_res4.data,accumulator.data,function_name,needed_library,base_filename);
                                out.data = out_filename;
                                out.nb_prime = mod_res4.nb_prime + accumulator.nb_prime;
                                out.hashlead = mod_res4.hashlead;
                        }
                        else
                        {
                            if(mod_res4.nb_prime >= accumulator.nb_prime)
                            {		
                                out.data = mod_res4.data;
                                out.nb_prime = mod_res4.nb_prime;
                                out.hashlead = mod_res4.hashlead;
                            }
                            else
                            {
                                out.data = accumulator.data;
                                out.nb_prime = accumulator.nb_prime;
                                out.hashlead = accumulator.hashlead;
                            }
                        }
                    }
                    else
                    {
                        if(mod_res4.nb_prime >= accumulator.nb_prime)
                        {
                            out.data = mod_res4.data;
                            out.nb_prime = mod_res4.nb_prime;
                            out.hashlead = mod_res4.hashlead;
                        }
                        else
                        {
                            out.data = accumulator.data;
                            out.nb_prime = accumulator.nb_prime;
                            out.hashlead = accumulator.hashlead;
                        }
                    }
                
      }
    }
  }
}