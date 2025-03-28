#pragma once

#define NO_NAME_MANGLING extern "C"

#include <string>
#include <vector>
//#include <modular/config.hpp>
#include <boost/variant.hpp>

#include <iostream>

#include <we/type/literal/control.hpp>
#include <we/type/bitsetofint.hpp>
#include <we/type/bytearray.hpp>
#include <we/type/value.hpp>
#include <map>

#define CONTROL_TOKEN we::type::literal::control{}

#define RESOLVE_INTERFACE_FUNCTION(implementation, function) \
      (fhg::util::scoped_dlhandle \
      (implementation, \
      RTLD_GLOBAL | RTLD_NOW | RTLD_DEEPBIND) \
      .sym<decltype(function)> \
      (BOOST_PP_STRINGIZE(function)))


// types needed from SINGULAR
typedef struct sip_sideal *     ideal;
typedef struct skStrategy * kStrategy;

// types used by GPI-Space if you set the type of a place (or an "out-many" port) to "list", "set" or "map":
using GpiVariant = pnet::type::value::value_type;
using GpiStruct  = pnet::type::value::structured_type;
using GpiList    = std::list<GpiVariant>;
using GpiSet     = std::set<GpiVariant>;
using GpiMap     = std::map<GpiVariant,GpiVariant>;

// visitor functions to convert to proper lists, sets and maps:
template <typename T>
class variant_visitor : public boost::static_visitor<T&>
{
public:
  T& operator() (T& data) const
  {
    return data;
  }

  template <typename U>
  T& operator() (U&) const
  {
   static T instance{};
   return instance;
  }
};

inline GpiList& get_list(GpiVariant& v) {return boost::apply_visitor(variant_visitor<GpiList>(), v);}
inline GpiSet&  get_set (GpiVariant& v) {return boost::apply_visitor(variant_visitor<GpiSet >(), v);}
inline GpiMap&  get_map (GpiVariant& v) {return boost::apply_visitor(variant_visitor<GpiMap >(), v);}

inline GpiList const& get_list(GpiVariant  const& v) {return boost::apply_visitor(variant_visitor<GpiList const>(), v);}
inline GpiSet const&  get_set (GpiVariant  const& v) {return boost::apply_visitor(variant_visitor<GpiSet  const>(), v);}
inline GpiMap const&  get_map (GpiVariant  const& v) {return boost::apply_visitor(variant_visitor<GpiMap  const>(), v);}



inline std::vector<int> lcm(std::vector<int> const& m1, std::vector<int> const& m2)
{
  std::vector<int>::const_iterator it1 = m1.begin();
  std::vector<int>::const_iterator it2 = m2.begin();
  std::vector<int> res;
  for(; it1 != m1.end(); ++it1, ++it2)
  {
    res.emplace_back(std::max(*it1, *it2));
  }
  return res;
}
inline bool equal(std::vector<int> const& m1, std::vector<int> const& m2)
{
  std::vector<int>::const_iterator it1 = m1.begin();
  std::vector<int>::const_iterator it2 = m2.begin();
  std::vector<int> res;
  for(; it1 != m1.end(); ++it1, ++it2)
  {
    if(*it1!=*it2) {return false;}
  }
  return true;
}
inline bool divides_monom(std::vector<int> const& m1, std::vector<int> const& m2)
{
  if (m1.back()!=m2.back()) {return false;} // different components
  std::vector<int>::const_iterator it1 = m1.begin();
  std::vector<int>::const_iterator it2 = m2.begin();
  std::vector<int> res;
  for(; it1 != m1.end(); ++it1, ++it2)
  {
    if(*it1>*it2) {return false;}
  }
  return true;
}
inline bool coprime_monom(std::vector<int> const& m1, std::vector<int> const& m2)
{
  if (m1.back()!=m2.back()) {return false;} // different components
  std::vector<int>::const_iterator it1 = m1.begin();
  std::vector<int>::const_iterator it2 = m2.begin();
  std::vector<int> res;
  for(; it1 != m1.end(); ++it1, ++it2)
  {
    if(*it1!=0 && *it2!=0) {return false;}
  }
  return true;
}
inline bool test_PC(std::vector<int> const& Mi, std::vector<int> const& Mj)
{
  int Mi_comp = Mi.back();
  int Mj_comp = Mj.back();
  if(Mi_comp==0) // ideals & polynomials
  {
    return coprime_monom(Mi, Mj); // product-criterion: if mi and mj are coprime then (i,j) can be discarded
  }
  else // modules & vectors
  {
    return (Mi_comp!=Mj_comp); // for modules: test instead if the leads lie in different components (thus spoly=0 trivially)
  }
  return false;
}
inline bool test_CC(std::vector<int> const& lcm_i_j, std::vector<int> const& Mi, std::vector<int> const& Mj, std::vector<int> const& Mk)
{
  int Mi_comp = Mi.back();
  int Mj_comp = Mj.back();
  int Mk_comp = Mk.back();

  if(Mi_comp==Mj_comp && Mi_comp==Mk_comp)
  {
    return (divides_monom(Mk, lcm_i_j));  // chain-criterion: if mk divides lcm(mi,mj) then (i,j) can be discarded
  }
  return false;
}




NO_NAME_MANGLING
std::string filename_gen(std::string const&);

NO_NAME_MANGLING
std::pair<std::vector<std::string>,int> singular_modular_genNextPrime ( std::string const&
                                                            , int const&
                                                            , long const&
                                                            , std::string const&
															, std::string const&
														    , std::string const&
                                                            );

NO_NAME_MANGLING
std::pair<std::string,std::string> singular_modular_compute ( std::string const&
                                                            , std::string const&
                                                            , std::string const&
															, std::string const&
														    , std::string const&
                                                            );

NO_NAME_MANGLING
std::string  singular_modular_lift( std::string const&
                                      , std::string const&
                                      , std::string const&
                                      , std::string const&
                                      , std::string const&
                                      );
NO_NAME_MANGLING
std::pair<std::vector<std::string>, unsigned long> singular_modular_split(std::string const&
                                                , std::string const&
                                                , std::string const&
                                                , std::string const&
                                                );

/*NO_NAME_MANGLING
std::string singular_modular_farey (std::string const&
                                   , std::string const&
                                   , std::string const&
                                   , std::string const&
                                   );*/

NO_NAME_MANGLING
std::pair<std::string, unsigned long> singular_modular_farey(std::string const&
                                                             , std::string const&
                                                             , std::string const&
                                                             , std::string const&
                                                             );

NO_NAME_MANGLING
std::string  singular_modular_append(std::string const&
                                    , std::string const&
                                    , std::string const&
                                    , std::string const&
                                    , std::string const&
                                    );

NO_NAME_MANGLING
bool singular_modular_compatible (std::string const&
                                   , std::string const&
                                   , std::string const&
                                   , std::string const&
                                   );
NO_NAME_MANGLING
bool singular_modular_compare (std::string const&
                                , std::string const&
                                , std::string const&
                                , std::string const&
                               );

// for Buchberger test:

NO_NAME_MANGLING
std::pair<std::vector<std::vector<int>>,int> singular_buchberger_get_M_and_max_j( [[maybe_unused]] std::string const& singular_library_name,
                                                                                  [[maybe_unused]] std::string const& base_filename,
                                                                                  [[maybe_unused]] std::string const& input,
                                                                                  [[maybe_unused]] std::string* GB,
                                                                                  [[maybe_unused]] std::string* output);
NO_NAME_MANGLING
std::tuple<ideal,ideal,kStrategy> singular_buchberger_get_Fstrat( [[maybe_unused]] std::string const& singular_library_name,
                                                                  [[maybe_unused]] std::string const& base_filename,
                                                                  [[maybe_unused]] std::string const& input,
                                                                  [[maybe_unused]] std::string const& GB);
NO_NAME_MANGLING
void singular_buchberger_compute_NF( [[maybe_unused]] std::string const& singular_library_name,
                                     [[maybe_unused]] std::string const& base_filename,
                                     std::tuple<ideal,ideal,kStrategy> Fstrat,
                                     GpiList const& started_indices,
                                     GpiList* BB_test_fail,
                                     GpiMap* runtime);
NO_NAME_MANGLING
void abort_BB_test([[maybe_unused]] std::string const& singular_library_name,
                   [[maybe_unused]] std::string const& base_filename,
                   [[maybe_unused]] std::string* output);
