#include <pnetc/op/singular_modular/compute.hpp>
#include <we/type/literal/control.hpp>
#include <pnetc/type/modular_data/op.hpp>
#include <pnetc/type/mod_input_data/op.hpp>
#include <string>
#include <drts/worker/context.hpp>
#include <share/include/modular_interface.hpp>
#include <fstream>
#include <util-generic/dynamic_linking.hpp>
#include <iostream>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>

namespace pnetc
{
  namespace op
  {
    namespace singular_modular
    {
      void compute
        ( drts::worker::context *_pnetc_context, const std::string& implementation
        , const ::pnetc::type::mod_input_data::mod_input_data& mod_input
        , const std::string& function_name
        , const std::string& needed_library
        , const std::string& base_filename
        , ::pnetc::type::modular_data::modular_data& mod_res1
        , we::type::literal::control& bal1
        )
      {
#line 136 "/home/hbn/Documents/AIMS/projet/master/github/modular_independent_sub5/workflow/modular.xpnet"

                        std::cout << " in singular_..._compute " << std::endl;
                        std::string const filename (fhg::util::scoped_dlhandle
                                                        (implementation, RTLD_GLOBAL | RTLD_NOW | RTLD_DEEPBIND)
                                                        .sym<decltype (filename_gen)> ("filename_gen")
                                                         (base_filename));
                        bool cancelled (false) ;
                    
                            _pnetc_context->execute_and_kill_on_cancel_DO_NOT_OUTPUT_TO_STANDARD_STREAMS_FROM_WITHIN
                                ( [=]  // copy parameters
                                {
                                    std::ofstream of (filename);
                                    boost::archive::binary_oarchive oa (of);
                                    std::pair<std::string,std::string>  out
                                    (fhg::util::scoped_dlhandle
                                        (implementation, RTLD_GLOBAL | RTLD_NOW | RTLD_DEEPBIND)
                                        .sym<decltype (singular_modular_compute)> ("singular_modular_compute")
                                        ( mod_input.input, mod_input.prime, function_name, needed_library, base_filename));
                                    oa << out.first;
                                    oa << out.second; // save result
                                }
                                , [&]
                                {
                                    cancelled = true;
                                }
                                , &drts::worker::on_signal_unexpected
                                , [] (int exit_code)
                                {
                                    if (exit_code != 0)
                                    {
                                        drts::worker::on_exit_unexpected (exit_code);
                                    }     
                                }
                            );
                        if (!cancelled)
                        {
                            std::ifstream is (filename);
                            boost::archive::binary_iarchive ia (is);
                            ia >> mod_res1.data; // read saved result
                            ia >> mod_res1.hashlead;
                            mod_res1.nb_prime = 1UL;
                            bal1 = we::type::literal::control{};
                        }
                        
      }
    }
  }
}