#ifndef _PNETC_OP_singular_modular_lift2
#define _PNETC_OP_singular_modular_lift2

#include <drts/worker/context_fwd.hpp>
#include <pnetc/type/modular_data.hpp>
#include <string>

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
        );
    }
  }
}
#endif
