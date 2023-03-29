// defined in [/home/hbn/Documents/AIMS/projet/master/github/modular_independent_sub5/workflow/structures.xpnet:2:5]
#ifndef _PNETC_TYPE_mod_input_data_OP
#define _PNETC_TYPE_mod_input_data_OP

#include <pnetc/type/mod_input_data.hpp>
#include <string>
#include <we/type/value.hpp>
#include <we/type/value/from_value.hpp>
#include <we/type/value/to_value.hpp>
#include <iosfwd>

namespace pnetc
{
  namespace type
  {
    namespace mod_input_data
    {
      mod_input_data from_value (pnet::type::value::value_type const&);
      pnet::type::value::value_type to_value (mod_input_data const&);
      std::ostream& operator<< (std::ostream&, mod_input_data const&);
    }
  }
}
namespace pnet
{
  namespace type
  {
    namespace value
    {
      template<>
        inline value_type to_value<pnetc::type::mod_input_data::mod_input_data> (pnetc::type::mod_input_data::mod_input_data const& x)
      {
        return pnetc::type::mod_input_data::to_value (x);
      }
      template<>
        inline pnetc::type::mod_input_data::mod_input_data from_value<pnetc::type::mod_input_data::mod_input_data> (value_type const& v)
      {
        return pnetc::type::mod_input_data::from_value (v);
      }
    }
  }
}
#endif
