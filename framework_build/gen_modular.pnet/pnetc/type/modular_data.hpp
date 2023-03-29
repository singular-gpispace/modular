// modular_data :: [data :: string, nb_prime :: unsigned long, hashlead :: string]
#ifndef _PNETC_TYPE_modular_data
#define _PNETC_TYPE_modular_data

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
    namespace modular_data
    {
      struct modular_data
      {
        std::string data;
        unsigned long nb_prime;
        std::string hashlead;
        modular_data()
          : data()
          , nb_prime()
          , hashlead()
        {}
        explicit modular_data
          ( std::string const& _data
          , unsigned long const& _nb_prime
          , std::string const& _hashlead
          )
          : data (_data)
          , nb_prime (_nb_prime)
          , hashlead (_hashlead)
        {}
        bool operator== (modular_data const& rhs) const
        {
          return true
            && pnetc_eq{} (this->data, rhs.data)
            && pnetc_eq{} (this->nb_prime, rhs.nb_prime)
            && pnetc_eq{} (this->hashlead, rhs.hashlead)
            ;
        }
        bool operator< (modular_data const& rhs) const
        {
          return pnetc_less (this->data, rhs.data) || (pnetc_eq{} (this->data, rhs.data) && (pnetc_less (this->nb_prime, rhs.nb_prime) || (pnetc_eq{} (this->nb_prime, rhs.nb_prime) && (pnetc_less (this->hashlead, rhs.hashlead)))));
        }
      };
    }
  }
}
#endif
