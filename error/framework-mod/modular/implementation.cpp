#include <Singular/libsingular.h>

#include <share/include/modular_interface.hpp>

#include <iostream>
#include <stdexcept>
#include <unistd.h>

#include "config.hpp"
#include "singular_functions.hpp"
NO_NAME_MANGLING
std::string  singular_modular_generate( std::string const& in_filename 
																			, std::string const& prime_filename
																			, std::string const& function_name
																			, std::string const& needed_library
																			)
{
	init_singular (config::library().string());
	std::pair<int, lists> input;
	std::pair<int, lists> p;
	std::pair<int, lists> out;
	std::string ids;
	std::string out_filename;
	ids = worker();
	std::cout << ids << " in singular_..._generate" << std::endl;
	input = deserialize(in_filename,ids);
	p = deserialize(prime_filename,ids);
	scoped_leftv arg1( input.first, lCopy(input.second));
	scoped_leftv arg (arg1, p.first, lCopy(p.second));
	std::cout << arg._->Data()<< std::endl;
	std::cout <<arg._->next->Data() <<std::endl;
	out = call_user_proc(function_name, needed_library, arg);
	out_filename  =  serialize(out.second);
	std::cout << out_filename << std::endl;
	return out_filename;
}

