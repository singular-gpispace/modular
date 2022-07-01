#include <Singular/libsingular.h>

#include <share/include/modular_interface.hpp>

#include <iostream>
#include <stdexcept>
#include <unistd.h>

#include "config.hpp"
#include "singular_functions.hpp"
NO_NAME_MANGLING

std::string  singular_modular_compute( std::string const& input_filename 
																			,	std::string const& mod_input
																			, std::string const& function_name
																			, std::string const& needed_library
																			, std::string const& base_filename
																			)
{
	init_singular (config::library().string());
	load_singular_library(needed_library);
	std::pair<int, lists> p;
	std::pair<int,lists> input;
	std::pair<int, lists> out;
	std::string ids;
	std::string out_filename;
	ids = worker();
	std::cout << ids << " in singular_..._compute" << std::endl;
	p = deserialize(mod_input,ids);
	input = deserialize(input_filename,ids);
	ScopedLeftv args( input.first, lCopy(input.second));
	ScopedLeftv arg(args,p.first,lCopy(p.second));
	out = call_user_proc(function_name, needed_library, args);
	out_filename = serialize(out.second, base_filename, ids);
	return out_filename;
}

std::string  singular_modular_lift( std::string const& left
                                      , std::string const& right
                                      , std::string const& function_name
                                      , std::string const& needed_library
                                      , std::string const& base_filename
																			, std::string const& number
                                      )
{
  init_singular (config::library().string());
  load_singular_library(needed_library);
  std::pair<int, lists> l;
  std::pair<int,lists> r;
  std::pair<int, lists> out;
  std::string ids;
  std::string out_filename;
  ids = worker();
  std::cout << ids << " in singular_..._lift"+number << std::endl;
  l = deserialize(left,ids);
  r = deserialize(right,ids);
  ScopedLeftv args( l.first, lCopy(l.second));
  ScopedLeftv arg(args,r.first,lCopy(r.second));
  out = call_user_proc(function_name, needed_library, args);
  out_filename = serialize(out.second, base_filename, ids);
  return out_filename;
}

