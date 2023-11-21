#include <Singular/libsingular.h>

#include <share/include/modular_interface.hpp>

#include <iostream>
#include <stdexcept>
#include <unistd.h>

#include "config.hpp"
#include "singular_functions.hpp"
NO_NAME_MANGLING

std::pair<std::vector<std::string>, int> singular_modular_genNextPrime(std::string const& ideal_filename ,
                                                          int const& lastprime,
                                                          std::string const& function_name,
                                                          std::string const& needed_library,
                                                          std::string const& base_filename)
{
  init_singular (config::library().string());
  load_singular_library(needed_library);
  std::pair<int,lists> I;
  std::string ids = worker();
  std::vector<std::string> vec;
  I = deserialize(ideal_filename,ids);
  void* p =  (char*) (long) (lastprime);
  ScopedLeftv args( I.first, lCopy(I.second));
	ScopedLeftv arg(args,INT_CMD,p);
  std::pair<int, lists>  out = call_user_proc(function_name, needed_library, args);
  lists u = (lists)out.second->m[3].Data();//ring.fieldnames-lists.fieldnames-ring.data-lists.data
  for(int i (0); i<lSize(u); i++)
  {
    vec.push_back(serialize((lists)u->m[i].Data(), base_filename));
  } 
	int nextPrime = (int) (long)u->m[lSize(u)].Data();
  return {vec, nextPrime};

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
	p = deserialize(mod_input,ids);
	input = deserialize(input_filename,ids);
	ScopedLeftv args( input.first, lCopy(input.second));
	ScopedLeftv arg(args,p.first,lCopy(p.second));
	out = call_user_proc(function_name, needed_library, args);
	lists u = (lists)out.second->m[3].Data();//ring-lists-ring-lists
	std::string hash = (char*)u->m[3].Data();
	out_filename = serialize(out.second,base_filename);

	return {out_filename,hash};
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


/*std::string singular_modular_farey (std::string const& lifted_res
                                   , std::string const& function_name
                                   , std::string const& needed_library
                                   , std::string const& base_filename
                                   )
{
  init_singular (config::library().string());
  load_singular_library(needed_library);
  std::pair<int, lists> liftedres;
  std::pair<int, lists> out;
  std::string ids;
  std::string out_filename;
  ids = worker();
  liftedres = deserialize(lifted_res,ids);
  ScopedLeftv args( liftedres.first, lCopy(liftedres.second));
  out = call_user_proc(function_name, needed_library, args);
  out_filename = serialize(out.second, base_filename);
  return out_filename;
}*/

std::pair<std::vector<std::string>, unsigned long> singular_modular_split(std::string const& in,
                                                std::string const& function_name,
                                                std::string const& needed_library,
                                                std::string const& base_filename)
{
  init_singular (config::library().string());
  load_singular_library(needed_library);
  std::pair<int, lists> input;
  std::pair<int, lists> out;
  std::vector<std::string> vec;
  std::string ids;
  unsigned long total_generator;
	ids = worker();
  input = deserialize(in,ids);
  ScopedLeftv args( input.first, lCopy(input.second));
  out = call_user_proc(function_name, needed_library, args);
  lists u = (lists)out.second->m[3].Data();//ring-lists-ring-lists
  for(int i (0); i<lSize(u); i++)
  {
    vec.push_back(serialize((lists)u->m[i].Data(), base_filename));
  } 
  total_generator = (unsigned long) (int) (long) u->m[lSize(u)].Data();
  return {vec, total_generator};
}

std::pair<std::string, unsigned long> singular_modular_farey(std::string const& in,
                                                             std::string const& function_name,
                                                             std::string const& needed_library,
                                                             std::string const& base_filename)
{
  init_singular (config::library().string());
  load_singular_library(needed_library);
  std::pair<int, lists> input;
  std::pair<int, lists> out;
  std::string out_filename;
  std::string ids;
  unsigned long N;
	ids = worker();
  input = deserialize(in,ids);
  out = call_user_proc(function_name, needed_library, input.first, input.second);
  lists u = (lists) out.second->m[3].Data();
  N =(unsigned long) (int) (long) u->m[1].Data();
  out_filename = serialize(out.second, base_filename);
  return {out_filename,N};
}

std::string  singular_modular_append(std::string const& left
                                    , std::string const& right
                                    , std::string const& function_name
                                    , std::string const& needed_library
                                    , std::string const& base_filename)
{
  init_singular (config::library().string());
  load_singular_library(needed_library);
  std::pair<int, lists> leftt;
  std::pair<int,lists> rightt;
  std::pair<int, lists> out;
  std::string out_filename;
	std::string ids;
	ids = worker();
	leftt = deserialize(left,ids);
	rightt = deserialize(right,ids);
	ScopedLeftv args(leftt.first, lCopy(leftt.second));
	ScopedLeftv arg(args,rightt.first,lCopy(rightt.second));
  out = call_user_proc(function_name, needed_library, args);
  out_filename = serialize(out.second, base_filename);
  return out_filename;
}


bool singular_modular_compatible (std::string const& result_farey
                                   , std::string const& test_result
                                   , std::string const& function_name
                                   , std::string const& needed_library
                                   )
{
  init_singular (config::library().string());
  load_singular_library(needed_library);
  std::pair<int, lists> resultfarey;
  std::pair<int, lists> testresult;
  std::pair<int, lists> out;
  std::string ids;
  bool testt;
  ids = worker();
  resultfarey = deserialize(result_farey,ids);
  testresult = deserialize(test_result, ids);
  ScopedLeftv args( resultfarey.first, lCopy(resultfarey.second));
  ScopedLeftv arg(args,testresult.first,lCopy(testresult.second));
  out = call_user_proc(function_name, needed_library, args);
  lists u = (lists) out.second->m[3].Data();
  testt = (int) (long) u->m[0].Data();
  return testt;
}

bool singular_modular_compare (std::string const& result_farey
                                   , std::string const& test_result
                                   , std::string const& function_name
                                   , std::string const& needed_library
                                   )
{
  init_singular (config::library().string());
  load_singular_library(needed_library);
  std::pair<int, lists> resultfarey;
  std::pair<int, lists> testresult;
  std::pair<int, lists> out;
  std::string ids;
  bool testt;
  ids = worker();
  resultfarey = deserialize(result_farey,ids);
  testresult = deserialize(test_result, ids);
  ScopedLeftv args( resultfarey.first, lCopy(resultfarey.second));
  ScopedLeftv arg(args,testresult.first,lCopy(testresult.second));
  out = call_user_proc(function_name, needed_library, args);
  lists u = (lists) out.second->m[3].Data();
  testt = (int) (long) u->m[0].Data();
  return testt;
}


