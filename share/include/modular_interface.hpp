#pragma once

#define NO_NAME_MANGLING extern "C"

#include <string>

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
																			, std::string const&
                                      );

NO_NAME_MANGLING
std::pair<std::string,bool>  singular_modular_reconstest( std::string const& lifted_res
                                      , std::string const& mod_res2
                                      , std::string const& function_name
                                      , std::string const& needed_library
                                      , std::string const& base_filename
                                      );

