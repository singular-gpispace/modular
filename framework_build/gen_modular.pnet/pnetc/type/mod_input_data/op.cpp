// defined in [/home/hbn/Documents/AIMS/projet/master/github/modular_independent_sub5/workflow/structures.xpnet:2:5]

#include <pnetc/type/mod_input_data/op.hpp>
#include <we/field.hpp>
#include <we/signature_of.hpp>
#include <we/type/value/poke.hpp>
#include <we/type/value/show.hpp>
#include <iostream>

namespace pnetc
{
  namespace type
  {
    namespace mod_input_data
    {
      mod_input_data from_value (pnet::type::value::value_type const& v)
      {
        return mod_input_data
          ( pnet::field_as< std::string > ("input", v, std::string("string"))
          , pnet::field_as< std::string > ("prime", v, std::string("string"))
          );
      }
      pnet::type::value::value_type to_value (mod_input_data const& x)
      {
        pnet::type::value::value_type v;
        pnet::type::value::poke ("input", v, x.input);
        pnet::type::value::poke ("prime", v, x.prime);
        return v;
      }
      std::ostream& operator<< (std::ostream& os, mod_input_data const& x)
      {
        return os << pnet::type::value::show (to_value (x));
      }
    }
  }
}
