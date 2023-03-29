// defined in [/home/hbn/Documents/AIMS/projet/master/github/modular_independent_sub5/workflow/structures.xpnet:13:2]
#ifndef _PNETC_TYPE_result_bool_type_OP
#define _PNETC_TYPE_result_bool_type_OP

#include <pnetc/type/result_bool_type.hpp>
#include <string>
#include <we/type/value.hpp>
#include <we/type/value/from_value.hpp>
#include <we/type/value/to_value.hpp>
#include <iosfwd>

namespace pnetc
{
  namespace type
  {
    namespace result_bool_type
    {
      result_bool_type from_value (pnet::type::value::value_type const&);
      pnet::type::value::value_type to_value (result_bool_type const&);
      std::ostream& operator<< (std::ostream&, result_bool_type const&);
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
        inline value_type to_value<pnetc::type::result_bool_type::result_bool_type> (pnetc::type::result_bool_type::result_bool_type const& x)
      {
        return pnetc::type::result_bool_type::to_value (x);
      }
      template<>
        inline pnetc::type::result_bool_type::result_bool_type from_value<pnetc::type::result_bool_type::result_bool_type> (value_type const& v)
      {
        return pnetc::type::result_bool_type::from_value (v);
      }
    }
  }
}
#endif
