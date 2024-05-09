#pragma once

#define NO_NAME_MANGLING extern "C"

#include <string>
#include <vector>

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