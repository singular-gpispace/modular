#include <we/loader/macros.hpp>

#include <pnetc/op/singular_modular/init.hpp>
#include <list>
#include <we/type/value.hpp>

namespace pnetc
{
  namespace op
  {
    namespace singular_modular
    {
      static void init
        ( drts::worker::context *
        , expr::eval::context const&_pnetc_input
        , expr::eval::context&_pnetc_output
        , std::map<std::string, void*> const&
        )
      {
        const int & input_bal1 (::boost::get< int > (_pnetc_input.value (std::list<std::string> (1, "input_bal1"))));
        const int & input_bal2 (::boost::get< int > (_pnetc_input.value (std::list<std::string> (1, "input_bal2"))));
        std::list<pnet::type::value::value_type> bal1;
        std::list<pnet::type::value::value_type> bal2;
        ::pnetc::op::singular_modular::init (input_bal1, input_bal2, bal1, bal2);
        _pnetc_output.bind_and_discard_ref (std::list<std::string> (1, "bal1"), bal1);
        _pnetc_output.bind_and_discard_ref (std::list<std::string> (1, "bal2"), bal2);
      }
    }
  }
}
#include <pnetc/op/singular_modular/lift.hpp>
#include <list>
#include <we/type/value.hpp>
#include <pnetc/type/modular_data/op.hpp>
#include <string>

namespace pnetc
{
  namespace op
  {
    namespace singular_modular
    {
      static void lift
        ( drts::worker::context *_pnetc_context
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
        std::list<pnet::type::value::value_type> bal2;
        ::pnetc::op::singular_modular::lift (_pnetc_context, implementation, lhs, rhs, function_name, needed_library, base_filename, out, bal2);
        _pnetc_output.bind_and_discard_ref (std::list<std::string> (1, "out"), ::pnetc::type::modular_data::to_value (out));
        _pnetc_output.bind_and_discard_ref (std::list<std::string> (1, "bal2"), bal2);
      }
    }
  }
}
#include <pnetc/op/singular_modular/counting2.hpp>

namespace pnetc
{
  namespace op
  {
    namespace singular_modular
    {
      static void counting2
        ( drts::worker::context *
        , expr::eval::context const&_pnetc_input
        , expr::eval::context&_pnetc_output
        , std::map<std::string, void*> const&
        )
      {
        long counter (::boost::get< long > (_pnetc_input.value (std::list<std::string> (1, "counter"))));
        ::pnetc::op::singular_modular::counting2 (counter);
        _pnetc_output.bind_and_discard_ref (std::list<std::string> (1, "counter"), counter);
      }
    }
  }
}
#include <pnetc/op/singular_modular/compute.hpp>
#include <we/type/literal/control.hpp>
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
        ( drts::worker::context *_pnetc_context
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
        we::type::literal::control bal1;
        ::pnetc::op::singular_modular::compute (_pnetc_context, implementation, mod_input, function_name, needed_library, base_filename, mod_res1, bal1);
        _pnetc_output.bind_and_discard_ref (std::list<std::string> (1, "mod_res1"), ::pnetc::type::modular_data::to_value (mod_res1));
        _pnetc_output.bind_and_discard_ref (std::list<std::string> (1, "bal1"), bal1);
      }
    }
  }
}
#include <pnetc/op/singular_modular/lift2.hpp>
#include <pnetc/type/modular_data/op.hpp>
#include <string>

namespace pnetc
{
  namespace op
  {
    namespace singular_modular
    {
      static void lift2
        ( drts::worker::context *_pnetc_context
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
        ::pnetc::op::singular_modular::lift2 (_pnetc_context, implementation, lhs, rhs, function_name, needed_library, base_filename, out);
        _pnetc_output.bind_and_discard_ref (std::list<std::string> (1, "out"), ::pnetc::type::modular_data::to_value (out));
      }
    }
  }
}
#include <pnetc/op/singular_modular/reconstest.hpp>
#include <pnetc/type/result_bool_type/op.hpp>
#include <pnetc/type/modular_data/op.hpp>
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
        const ::pnetc::type::modular_data::modular_data lifted_res (::pnetc::type::modular_data::from_value (_pnetc_input.value (std::list<std::string> (1, "lifted_res"))));
        const ::pnetc::type::modular_data::modular_data one (::pnetc::type::modular_data::from_value (_pnetc_input.value (std::list<std::string> (1, "one"))));
        const std::string & function_name (::boost::get< std::string > (_pnetc_input.value (std::list<std::string> (1, "function_name"))));
        const std::string & needed_library (::boost::get< std::string > (_pnetc_input.value (std::list<std::string> (1, "needed_library"))));
        const std::string & base_filename (::boost::get< std::string > (_pnetc_input.value (std::list<std::string> (1, "base_filename"))));
        ::pnetc::type::result_bool_type::result_bool_type out;
        ::pnetc::op::singular_modular::reconstest (implementation, lifted_res, one, function_name, needed_library, base_filename, out);
        _pnetc_output.bind_and_discard_ref (std::list<std::string> (1, "out"), ::pnetc::type::result_bool_type::to_value (out));
      }
    }
  }
}
#include <pnetc/op/singular_modular/lift3.hpp>
#include <we/type/literal/control.hpp>
#include <pnetc/type/modular_data/op.hpp>
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
        const ::pnetc::type::modular_data::modular_data mod_res4 (::pnetc::type::modular_data::from_value (_pnetc_input.value (std::list<std::string> (1, "mod_res4"))));
        const ::pnetc::type::modular_data::modular_data accumulator (::pnetc::type::modular_data::from_value (_pnetc_input.value (std::list<std::string> (1, "accumulator"))));
        const std::string & function_name (::boost::get< std::string > (_pnetc_input.value (std::list<std::string> (1, "function_name"))));
        const std::string & needed_library (::boost::get< std::string > (_pnetc_input.value (std::list<std::string> (1, "needed_library"))));
        const std::string & base_filename (::boost::get< std::string > (_pnetc_input.value (std::list<std::string> (1, "base_filename"))));
        we::type::literal::control up (::boost::get< we::type::literal::control > (_pnetc_input.value (std::list<std::string> (1, "up"))));
        long counter (::boost::get< long > (_pnetc_input.value (std::list<std::string> (1, "counter"))));
        ::pnetc::type::modular_data::modular_data out;
        ::pnetc::op::singular_modular::lift3 (implementation, mod_res4, accumulator, function_name, needed_library, base_filename, up, counter, out);
        _pnetc_output.bind_and_discard_ref (std::list<std::string> (1, "up"), up);
        _pnetc_output.bind_and_discard_ref (std::list<std::string> (1, "counter"), counter);
        _pnetc_output.bind_and_discard_ref (std::list<std::string> (1, "out"), ::pnetc::type::modular_data::to_value (out));
      }
    }
  }
}
WE_MOD_INITIALIZE_START()
{
  WE_REGISTER_FUN_AS (::pnetc::op::singular_modular::init,"init");
  WE_REGISTER_FUN_AS (::pnetc::op::singular_modular::lift,"lift");
  WE_REGISTER_FUN_AS (::pnetc::op::singular_modular::counting2,"counting2");
  WE_REGISTER_FUN_AS (::pnetc::op::singular_modular::compute,"compute");
  WE_REGISTER_FUN_AS (::pnetc::op::singular_modular::lift2,"lift2");
  WE_REGISTER_FUN_AS (::pnetc::op::singular_modular::reconstest,"reconstest");
  WE_REGISTER_FUN_AS (::pnetc::op::singular_modular::lift3,"lift3");
}
WE_MOD_INITIALIZE_END()
