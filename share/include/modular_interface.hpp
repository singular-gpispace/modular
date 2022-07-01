#pragma once

#define NO_NAME_MANGLING extern "C"

#include <string>

NO_NAME_MANGLING
std::string singular_modular_compute ( std::string const&
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
																			, std::string const&
                                      );

