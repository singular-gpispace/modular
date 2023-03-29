// defined in [/home/hbn/Documents/AIMS/projet/master/github/modular_independent_sub5/workflow/structures.xpnet:7:2]
#ifndef _PNETC_TYPE_modular_data_OP
#define _PNETC_TYPE_modular_data_OP

#include <pnetc/type/modular_data.hpp>
#include <string>
#include <we/type/value.hpp>
#include <we/type/value/from_value.hpp>
#include <we/type/value/to_value.hpp>
#include <iosfwd>

namespace pnetc
{
  namespace type
  {
    namespace modular_data
    {
      modular_data from_value (pnet::type::value::value_type const&);
      pnet::type::value::value_type to_value (modular_data const&);
      std::ostream& operator<< (std::ostream&, modular_data const&);
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
        inline value_type to_value<pnetc::type::modular_data::modular_data> (pnetc::type::modular_data::modular_data const& x)
      {
        return pnetc::type::modular_data::to_value (x);
      }
      template<>
        inline pnetc::type::modular_data::modular_data from_value<pnetc::type::modular_data::modular_data> (value_type const& v)
      {
        return pnetc::type::modular_data::from_value (v);
      }
    }
  }
}
#endif
