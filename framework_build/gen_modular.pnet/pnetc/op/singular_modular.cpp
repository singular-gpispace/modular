#include <we/loader/macros.hpp>

#include <pnetc/op/singular_modular/compute.hpp>
#include <pnetc/type/modular_data/op.hpp>
#include <pnetc/type/mod_input_data/op.hpp>
#include <string>

namespace pnetc
{
  namespace op
  {
    namespace singular_modular
    {
      static void compute
        ( drts::worker::context *
        , expr::eval::context const&_pnetc_input
        , expr::eval::context&_pnetc_output
        , std::map<std::string, void*> const&
        )
      {
        const std::string & implementation (::boost::get< std::string > (_pnetc_input.value (std::list<std::string> (1, "implementation"))));
        const ::pnetc::type::mod_input_data::mod_input_data mod_input (::pnetc::type::mod_input_data::from_value (_pnetc_input.value (std::list<std::string> (1, "mod_input"))));
        const std::string & function_name (::boost::get< std::string > (_pnetc_input.value (std::list<std::string> (1, "function_name"))));
        const std::string & needed_library (::boost::get< std::string > (_pnetc_input.value (std::list<std::string> (1, "needed_library"))));
        const std::string & base_filename (::boost::get< std::string > (_pnetc_input.value (std::list<std::string> (1, "base_filename"))));
        ::pnetc::type::modular_data::modular_data mod_res1;
        ::pnetc::op::singular_modular::compute (implementation, mod_input, function_name, needed_library, base_filename, mod_res1);
        _pnetc_output.bind_and_discard_ref (std::list<std::string> (1, "mod_res1"), ::pnetc::type::modular_data::to_value (mod_res1));
      }
    }
  }
}
#include <pnetc/op/singular_modular/move.hpp>
#include <string>
#include <pnetc/type/modular_data/op.hpp>

namespace pnetc
{
  namespace op
  {
    namespace singular_modular
    {
      static void move
        ( drts::worker::context *
        , expr::eval::context const&_pnetc_input
        , expr::eval::context&_pnetc_output
        , std::map<std::string, void*> const&
        )
      {
        const ::pnetc::type::modular_data::modular_data mod_res1 (::pnetc::type::modular_data::from_value (_pnetc_input.value (std::list<std::string> (1, "mod_res1"))));
        std::string mod_res2;
        ::pnetc::op::singular_modular::move (mod_res1, mod_res2);
        _pnetc_output.bind_and_discard_ref (std::list<std::string> (1, "mod_res2"), mod_res2);
      }
    }
  }
}
#include <pnetc/op/singular_modular/lift1.hpp>
#include <pnetc/type/modular_data/op.hpp>
#include <string>

namespace pnetc
{
  namespace op
  {
    namespace singular_modular
    {
      static void lift1
        ( drts::worker::context *
        , expr::eval::context const&_pnetc_input
        , expr::eval::context&_pnetc_output
        , std::map<std::string, void*> const&
        )
      {
        const std::string & implementation (::boost::get< std::string > (_pnetc_input.value (std::list<std::string> (1, "implementation"))));
        const ::pnetc::type::modular_data::modular_data lhs (::pnetc::type::modular_data::from_value (_pnetc_input.value (std::list<std::string> (1, "lhs"))));
        const ::pnetc::type::modular_data::modular_data rhs (::pnetc::type::modular_data::from_value (_pnetc_input.value (std::list<std::string> (1, "rhs"))));
        const std::string & function_name (::boost::get< std::string > (_pnetc_input.value (std::list<std::string> (1, "function_name"))));
        const std::string & needed_library (::boost::get< std::string > (_pnetc_input.value (std::list<std::string> (1, "needed_library"))));
        const std::string & base_filename (::boost::get< std::string > (_pnetc_input.value (std::list<std::string> (1, "base_filename"))));
        ::pnetc::type::modular_data::modular_data out;
        ::pnetc::op::singular_modular::lift1 (implementation, lhs, rhs, function_name, needed_library, base_filename, out);
        _pnetc_output.bind_and_discard_ref (std::list<std::string> (1, "out"), ::pnetc::type::modular_data::to_value (out));
      }
    }
  }
}
#include <pnetc/op/singular_modular/lift2.hpp>
#include <string>

namespace pnetc
{
  namespace op
  {
    namespace singular_modular
    {
      static void lift2
        ( drts::worker::context *
        , expr::eval::context const&_pnetc_input
        , expr::eval::context&_pnetc_output
        , std::map<std::string, void*> const&
        )
      {
        const std::string & implementation (::boost::get< std::string > (_pnetc_input.value (std::list<std::string> (1, "implementation"))));
        const std::string & lhs (::boost::get< std::string > (_pnetc_input.value (std::list<std::string> (1, "lhs"))));
        const std::string & rhs (::boost::get< std::string > (_pnetc_input.value (std::list<std::string> (1, "rhs"))));
        const std::string & function_name (::boost::get< std::string > (_pnetc_input.value (std::list<std::string> (1, "function_name"))));
        const std::string & needed_library (::boost::get< std::string > (_pnetc_input.value (std::list<std::string> (1, "needed_library"))));
        const std::string & base_filename (::boost::get< std::string > (_pnetc_input.value (std::list<std::string> (1, "base_filename"))));
        std::string out;
        ::pnetc::op::singular_modular::lift2 (implementation, lhs, rhs, function_name, needed_library, base_filename, out);
        _pnetc_output.bind_and_discard_ref (std::list<std::string> (1, "out"), out);
      }
    }
  }
}
#include <pnetc/op/singular_modular/reconstest.hpp>
#include <pnetc/type/result_bool_type/op.hpp>
#include <string>

namespace pnetc
{
  namespace op
  {
    namespace singular_modular
    {
      static void reconstest
        ( drts::worker::context *
        , expr::eval::context const&_pnetc_input
        , expr::eval::context&_pnetc_output
        , std::map<std::string, void*> const&
        )
      {
        const std::string & implementation (::boost::get< std::string > (_pnetc_input.value (std::list<std::string> (1, "implementation"))));
        const std::string & lifted_res (::boost::get< std::string > (_pnetc_input.value (std::list<std::string> (1, "lifted_res"))));
        const std::string & mod_res2 (::boost::get< std::string > (_pnetc_input.value (std::list<std::string> (1, "mod_res2"))));
        const std::string & function_name (::boost::get< std::string > (_pnetc_input.value (std::list<std::string> (1, "function_name"))));
        const std::string & needed_library (::boost::get< std::string > (_pnetc_input.value (std::list<std::string> (1, "needed_library"))));
        const std::string & base_filename (::boost::get< std::string > (_pnetc_input.value (std::list<std::string> (1, "base_filename"))));
        ::pnetc::type::result_bool_type::result_bool_type out;
        ::pnetc::op::singular_modular::reconstest (implementation, lifted_res, mod_res2, function_name, needed_library, base_filename, out);
        _pnetc_output.bind_and_discard_ref (std::list<std::string> (1, "out"), ::pnetc::type::result_bool_type::to_value (out));
      }
    }
  }
}
#include <pnetc/op/singular_modular/lift3.hpp>
#include <string>

namespace pnetc
{
  namespace op
  {
    namespace singular_modular
    {
      static void lift3
        ( drts::worker::context *
        , expr::eval::context const&_pnetc_input
        , expr::eval::context&_pnetc_output
        , std::map<std::string, void*> const&
        )
      {
        const std::string & implementation (::boost::get< std::string > (_pnetc_input.value (std::list<std::string> (1, "implementation"))));
        const std::string & mod_res2 (::boost::get< std::string > (_pnetc_input.value (std::list<std::string> (1, "mod_res2"))));
        const std::string & accumulator (::boost::get< std::string > (_pnetc_input.value (std::list<std::string> (1, "accumulator"))));
        const std::string & function_name (::boost::get< std::string > (_pnetc_input.value (std::list<std::string> (1, "function_name"))));
        const std::string & needed_library (::boost::get< std::string > (_pnetc_input.value (std::list<std::string> (1, "needed_library"))));
        const std::string & base_filename (::boost::get< std::string > (_pnetc_input.value (std::list<std::string> (1, "base_filename"))));
        std::string out;
        ::pnetc::op::singular_modular::lift3 (implementation, mod_res2, accumulator, function_name, needed_library, base_filename, out);
        _pnetc_output.bind_and_discard_ref (std::list<std::string> (1, "out"), out);
      }
    }
  }
}
WE_MOD_INITIALIZE_START()
{
  WE_REGISTER_FUN_AS (::pnetc::op::singular_modular::compute,"compute");
  WE_REGISTER_FUN_AS (::pnetc::op::singular_modular::move,"move");
  WE_REGISTER_FUN_AS (::pnetc::op::singular_modular::lift1,"lift1");
  WE_REGISTER_FUN_AS (::pnetc::op::singular_modular::lift2,"lift2");
  WE_REGISTER_FUN_AS (::pnetc::op::singular_modular::reconstest,"reconstest");
  WE_REGISTER_FUN_AS (::pnetc::op::singular_modular::lift3,"lift3");
}
WE_MOD_INITIALIZE_END()
