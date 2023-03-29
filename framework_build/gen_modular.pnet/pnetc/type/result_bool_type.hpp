// result_bool_type :: [farey_lift :: string, chr_lift :: string, test :: bool, nb_prime :: unsigned long, hashlead :: string]
#ifndef _PNETC_TYPE_result_bool_type
#define _PNETC_TYPE_result_bool_type

#include <string>
// This file is part of GPI-Space.
// Copyright (C) 2022 Fraunhofer ITWM
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program. If not, see <https://www.gnu.org/licenses/>.

#ifndef GUARD_PNETC_COMPARE
#define GUARD_PNETC_COMPARE
#include <cmath>
#include <type_traits>
namespace pnetc
{
  namespace type
  {
    template<typename T>
      bool pnetc_less (T const& lhs, T const& rhs)
      {
        return lhs < rhs;
      }
    struct pnetc_eq
    {
      template< typename F
              , typename
              = typename std::enable_if<std::is_floating_point<F>::value>::type
              >
        bool operator() (F const& lhs, F const& rhs)
      {
        return !std::isnan (lhs)
            && !std::isnan (rhs)
            && !pnetc_less (lhs, rhs)
            && !pnetc_less (rhs, lhs)
            ;
      }
      template< typename T
              , typename
              = typename std::enable_if<!std::is_floating_point<T>::value>::type
              >
        bool operator() (T const& lhs, T const& rhs) const
        {
          return lhs == rhs;
        }
    };
  }
}
#endif

namespace pnetc
{
  namespace type
  {
    namespace result_bool_type
    {
      struct result_bool_type
      {
        std::string farey_lift;
        std::string chr_lift;
        bool test;
        unsigned long nb_prime;
        std::string hashlead;
        result_bool_type()
          : farey_lift()
          , chr_lift()
          , test()
          , nb_prime()
          , hashlead()
        {}
        explicit result_bool_type
          ( std::string const& _farey_lift
          , std::string const& _chr_lift
          , bool const& _test
          , unsigned long const& _nb_prime
          , std::string const& _hashlead
          )
          : farey_lift (_farey_lift)
          , chr_lift (_chr_lift)
          , test (_test)
          , nb_prime (_nb_prime)
          , hashlead (_hashlead)
        {}
        bool operator== (result_bool_type const& rhs) const
        {
          return true
            && pnetc_eq{} (this->farey_lift, rhs.farey_lift)
            && pnetc_eq{} (this->chr_lift, rhs.chr_lift)
            && pnetc_eq{} (this->test, rhs.test)
            && pnetc_eq{} (this->nb_prime, rhs.nb_prime)
            && pnetc_eq{} (this->hashlead, rhs.hashlead)
            ;
        }
        bool operator< (result_bool_type const& rhs) const
        {
          return pnetc_less (this->farey_lift, rhs.farey_lift) || (pnetc_eq{} (this->farey_lift, rhs.farey_lift) && (pnetc_less (this->chr_lift, rhs.chr_lift) || (pnetc_eq{} (this->chr_lift, rhs.chr_lift) && (pnetc_less (this->test, rhs.test) || (pnetc_eq{} (this->test, rhs.test) && (pnetc_less (this->nb_prime, rhs.nb_prime) || (pnetc_eq{} (this->nb_prime, rhs.nb_prime) && (pnetc_less (this->hashlead, rhs.hashlead)))))))));
        }
      };
    }
  }
}
#endif
