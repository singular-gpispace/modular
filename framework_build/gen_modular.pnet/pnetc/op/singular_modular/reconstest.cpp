#include <pnetc/op/singular_modular/reconstest.hpp>
#include <pnetc/type/result_bool_type/op.hpp>
#include <string>
#include <share/include/modular_interface.hpp>
#include <util-generic/dynamic_linking.hpp>

namespace pnetc
{
  namespace op
  {
    namespace singular_modular
    {
      void reconstest
        ( const std::string& implementation
        , const std::string& lifted_res
        , const std::string& mod_res2
        , const std::string& function_name
        , const std::string& needed_library
        , const std::string& base_filename
        , ::pnetc::type::result_bool_type::result_bool_type& out
        )
      {
#line 331 "/home/hbn/Documents/AIMS/projet/master/github/modular/workflow/modular.xpnet"

				 std::pair<std::string,bool> pair_result = fhg::util::scoped_dlhandle
				 (implementation, RTLD_GLOBAL | RTLD_NOW | RTLD_DEEPBIND)
				 .sym<decltype (singular_modular_reconstest)> ("singular_modular_reconstest")
				 ( lifted_res, mod_res2,function_name, needed_library,base_filename);
						out.farey_lift = pair_result.first;
						out.chr_lift = lifted_res;
						out.test = pair_result.second;
				 
      }
    }
  }
}