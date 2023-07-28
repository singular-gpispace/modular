#include <Singular/libsingular.h>

#include <share/include/modular_interface.hpp>

#include <iostream>
#include <stdexcept>
#include <unistd.h>

#include "config.hpp"
#include "singular_functions.hpp"
NO_NAME_MANGLING

std::pair<std::string, int> singular_modular_genNextPrime(std::string const& ideal_filename ,
                                                          int const& lastprime,
                                                          std::string const& function_name,
                                                          std::string const& needed_library,
                                                          std::string const& base_filename)
{
  init_singular (config::library().string());
  load_singular_library(needed_library);
  std::pair<int,lists> I;
  std::string ids = worker();
  I = deserialize(ideal_filename,ids);
  void* p =  (char*) (long) (lastprime);
  ScopedLeftv args( I.first, lCopy(I.second));
	ScopedLeftv arg(args,INT_CMD,p);
  std::pair<int, lists>  out = call_user_proc(function_name, needed_library, args);
  lists u = /*(lists)omAlloc0Bin(slists_bin); //extract the integer value in the token
	u->Init(2);
	u =*/ (lists)out.second->m[3].Data();//ring.fieldnames-lists.fieldnames-ring.data-lists.data
	int nextPrime = (int) (long)u->m[0].Data();
  std::string out_filename = serialize(out.second,base_filename);
  return {out_filename, nextPrime};

}

std::string filename_gen(std::string const& base_filename)
{
  init_singular (config::library().string());
  return base_filename+filename_generator();
}

std::pair<std::string,std::string>  singular_modular_compute( std::string const& input_filename 
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
	//std::cout << ids << " in singular_..._compute" << std::endl;
	p = deserialize(mod_input,ids);
	input = deserialize(input_filename,ids);
	ScopedLeftv args( input.first, lCopy(input.second));
	ScopedLeftv arg(args,p.first,lCopy(p.second));
	out = call_user_proc(function_name, needed_library, args);
	lists u = /*(lists)omAlloc0Bin(slists_bin);
	u->Init(2);
	u = */(lists)out.second->m[3].Data();//ring-lists-ring-lists
	std::string hash = (char*)u->m[3].Data();
	out_filename = serialize(out.second,base_filename);

	return {out_filename,hash};
}

std::string  singular_modular_lift1( std::string const& left
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
  out_filename = serialize(out.second, base_filename);
  return out_filename;
}

std::string  singular_modular_lift( std::string const& left
                                      , std::string const& right
                                      , std::string const& function_name
                                      , std::string const& needed_library
                                      , std::string const& base_filename
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
  l = deserialize(left,ids);
  r = deserialize(right,ids);
  ScopedLeftv args( l.first, lCopy(l.second));
  ScopedLeftv arg(args,r.first,lCopy(r.second));
  out = call_user_proc(function_name, needed_library, args);
  out_filename = serialize(out.second, base_filename);
  return out_filename;
}


std::pair<std::string,bool>  singular_modular_reconstest( std::string const& lifted_res
                                      , std::string const& one
                                      , std::string const& function_name
                                      , std::string const& needed_library
                                      , std::string const& base_filename
                                      )
{
  init_singular (config::library().string());
  load_singular_library(needed_library);
  std::pair<int, lists> lifted;
  std::pair<int,lists> test_token;
  std::pair<int, lists> out;
	bool testt;
	std::string ids;
	std::string out_filename;
	ids = worker();
	std::cout << " in singular_..._reconstest" << std::endl;
	lifted = deserialize(lifted_res,ids);
	test_token = deserialize(one,ids);
	ScopedLeftv args(lifted.first, lCopy(lifted.second));
	ScopedLeftv arg(args,test_token.first,lCopy(test_token.second));
	out = call_user_proc(function_name, needed_library, args);
	lists u = (lists)out.second->m[3].Data();//ring-lists-ring-lists
	testt = (int)(long)u->m[1].Data();
	out_filename = serialize(out.second,base_filename);
	return {out_filename,testt};

}
