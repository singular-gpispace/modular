// defined in [/home/hbn/Documents/AIMS/projet/master/github/modular_independent_sub5/workflow/structures.xpnet:7:2]

#include <pnetc/type/modular_data/op.hpp>
#include <we/field.hpp>
#include <we/signature_of.hpp>
#include <we/type/value/poke.hpp>
#include <we/type/value/show.hpp>
#include <iostream>

namespace pnetc
{
  namespace type
  {
    namespace modular_data
    {
      modular_data from_value (pnet::type::value::value_type const& v)
      {
        return modular_data
          ( pnet::field_as< std::string > ("data", v, std::string("string"))
          , pnet::field_as< unsigned long > ("nb_prime", v, std::string("unsigned long"))
          , pnet::field_as< std::string > ("hashlead", v, std::string("string"))
          );
      }
      pnet::type::value::value_type to_value (modular_data const& x)
      {
        pnet::type::value::value_type v;
        pnet::type::value::poke ("data", v, x.data);
        pnet::type::value::poke ("nb_prime", v, x.nb_prime);
        pnet::type::value::poke ("hashlead", v, x.hashlead);
        return v;
      }
      std::ostream& operator<< (std::ostream& os, modular_data const& x)
      {
        return os << pnet::type::value::show (to_value (x));
      }
    }
  }
}
