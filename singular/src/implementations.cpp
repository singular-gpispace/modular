#include <Singular/libsingular.h>


#include <iostream>
#include <stdexcept>
#include <unistd.h>

#include "functions.hpp"

std::string  singular_modular_generate( std::string in_filename 
																			, std::string prime_filename
																			, std::string function_name
																			, std::string needed_library
																			)
{
	std::pair<int, lists> input;
	std::pair<int, lists> p;
	std::pair<int, lists> out;
	std::string ids;
	std::string out_filename;
	ids = worker();
	std::cout << ids << " in singular_..._generate" << std::endl;
	input = deserialize(in_filename,ids);
	p = deserialize(prime_filename,ids);
	scoped_leftv arg1( input.first, input.second);
	scoped_leftv arg (arg1, p.first, p.second);
	out = call_user_proc(function_name, needed_library, arg);
	out_filename  =  serialize(out.second);
	return out_filename;
}

