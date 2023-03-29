#include <pnetc/op/singular_modular/lift2.hpp>
#include <pnetc/type/modular_data/op.hpp>
#include <string>
#include <drts/worker/context.hpp>
#include <share/include/modular_interface.hpp>
#include <util-generic/dynamic_linking.hpp>
#include <iostream>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <fstream>

namespace pnetc
{
  namespace op
  {
    namespace singular_modular
    {
      void lift2
        ( drts::worker::context *_pnetc_context, const std::string& implementation
        , const ::pnetc::type::modular_data::modular_data& lhs
        , const ::pnetc::type::modular_data::modular_data& rhs
        , const std::string& function_name
        , const std::string& needed_library
        , const std::string& base_filename
        , ::pnetc::type::modular_data::modular_data& out
        )
      {
#line 385 "/home/hbn/Documents/AIMS/projet/master/github/modular_independent_sub5/workflow/modular.xpnet"

                        std::cout << " in singular_..._lift2 " << std::endl;
                        std::string const filename (fhg::util::scoped_dlhandle
                                                        (implementation, RTLD_GLOBAL | RTLD_NOW | RTLD_DEEPBIND)
                                                        .sym<decltype (filename_gen)> ("filename_gen")
                                                         (base_filename));
                        bool cancelled (false) ;
                        if(lhs.hashlead.size() == rhs.hashlead.size())
                        {
                            if(lhs.hashlead == rhs.hashlead)
                            {
                                _pnetc_context->execute_and_kill_on_cancel_DO_NOT_OUTPUT_TO_STANDARD_STREAMS_FROM_WITHIN
                                    ( [=]  // copy parameters
                                    {
                                        std::ofstream of (filename);
                                        boost::archive::binary_oarchive oa (of);
                                        std::string  out_name
                                        (fhg::util::scoped_dlhandle
                                            (implementation, RTLD_GLOBAL | RTLD_NOW | RTLD_DEEPBIND)
                                            .sym<decltype (singular_modular_lift)> ("singular_modular_lift")
                                            ( lhs.data,rhs.data,function_name,needed_library,base_filename));
                                        oa << out_name; // save result
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
                            }
                        }
                        if(!cancelled)
                        {
                            if(lhs.hashlead.size() == rhs.hashlead.size())
                            {
                                if(lhs.hashlead == rhs.hashlead)
                                {
                                    std::ifstream is (filename);
                                    boost::archive::binary_iarchive ia (is);
                                    ia >> out.data;
                                    out.nb_prime = lhs.nb_prime + rhs.nb_prime;
                                    out.hashlead = lhs.hashlead;
                                }
                                else
                                {
                                    if(lhs.nb_prime >= rhs.nb_prime)
                                    { 
                                        out = lhs;
                                    }
                                    else
                                    {
                                        out = rhs;
                                    }
                                }
                            }
                            else
                            {
                                if(lhs.nb_prime >= rhs.nb_prime)
                                { 
                                    out = lhs;
                                }
                                else
                                {
                                    out = rhs;
                                }
                            }
                        }
                        
      }
    }
  }
}