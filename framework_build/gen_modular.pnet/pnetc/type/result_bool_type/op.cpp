// defined in [/home/hbn/Documents/AIMS/projet/master/github/modular_independent_sub5/workflow/structures.xpnet:13:2]

#include <pnetc/type/result_bool_type/op.hpp>
#include <we/field.hpp>
#include <we/signature_of.hpp>
#include <we/type/value/poke.hpp>
#include <we/type/value/show.hpp>
#include <iostream>

namespace pnetc
{
  namespace type
  {
    namespace result_bool_type
    {
      result_bool_type from_value (pnet::type::value::value_type const& v)
      {
        return result_bool_type
          ( pnet::field_as< std::string > ("farey_lift", v, std::string("string"))
          , pnet::field_as< std::string > ("chr_lift", v, std::string("string"))
          , pnet::field_as< bool > ("test", v, std::string("bool"))
          , pnet::field_as< unsigned long > ("nb_prime", v, std::string("unsigned long"))
          , pnet::field_as< std::string > ("hashlead", v, std::string("string"))
          );
      }
      pnet::type::value::value_type to_value (result_bool_type const& x)
      {
        pnet::type::value::value_type v;
        pnet::type::value::poke ("farey_lift", v, x.farey_lift);
        pnet::type::value::poke ("chr_lift", v, x.chr_lift);
        pnet::type::value::poke ("test", v, x.test);
        pnet::type::value::poke ("nb_prime", v, x.nb_prime);
        pnet::type::value::poke ("hashlead", v, x.hashlead);
        return v;
      }
      std::ostream& operator<< (std::ostream& os, result_bool_type const& x)
      {
        return os << pnet::type::value::show (to_value (x));
      }
    }
  }
}
