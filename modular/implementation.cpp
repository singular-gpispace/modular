#include <Singular/libsingular.h>

#include <share/include/modular_interface.hpp>

#include <iostream>
#include <stdexcept>
#include <unistd.h>

#include "config.hpp"
#include "singular_functions.hpp"

#include <fstream>
#include <vector>
#include <boost/variant.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <chrono>

NO_NAME_MANGLING

std::pair<std::vector<std::string>, int> singular_modular_genNextPrime(std::string const& ideal_filename ,
                                                          int const& lastprime,
                                                          long const& m,
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
  void* M = (char*) (long) (m);
  ScopedLeftv args( I.first, lCopy(I.second));
	ScopedLeftv arg(args,INT_CMD,p);
  ScopedLeftv argss(args,INT_CMD,M);
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


// for Buchberger test:

NO_NAME_MANGLING
std::pair<std::vector<std::vector<int>>,int> singular_buchberger_get_M_and_max_j( [[maybe_unused]] std::string const& singular_library_name,
                                                                                  [[maybe_unused]] std::string const& base_filename,
                                                                                  [[maybe_unused]] std::string const& input,
                                                                                  [[maybe_unused]] std::string* GB,
                                                                                  [[maybe_unused]] std::string* output)
{
  std::string ids = worker();
  init_singular (config::library().string());
	//load_singular_library(singular_library_name);

  std::pair<int,void*> input_ideal = deserialize(input, ids);
  ideal F_in = (ideal) ((lists) (((lists) input_ideal.second)->m[3]).data)->m[0].data;

  std::pair<int,void*> output_ideal = deserialize(*output, ids);
  ideal F = (ideal) ((lists) (((lists) output_ideal.second)->m[3]).data)->m[0].data;

  if (TEST_OPT_INTSTRATEGY) {
    for(int i=0; i<F->ncols; i++)
    {
      F->m[i] = p_Cleardenom(F->m[i], currRing);
    }
  }

  //writeIdealSSI(F, base_filename+"GB_for_BB_test.ssi");
  ((lists) (((lists) output_ideal.second)->m[3]).data)->m[1].data = (void*) (char*) 1; // initialize certificate with "true", will be set to "false" if a reduction is non-zero
  (*output) = serialize((lists) output_ideal.second, base_filename);

  ((lists) (((lists) output_ideal.second)->m[3]).data)->m[0].data = (void*) F; // save the ideal for reading in NF_of_spoly
  (*GB)     = serialize((lists) output_ideal.second, base_filename);

  std::vector<std::vector<int>> Mvec;
  for (int i=0; i<F->ncols; i++)
  {
    std::vector<int> Mjvec;
    for (int j=1; j<=currRing->N; j++)
    {
      Mjvec.emplace_back(p_GetExp(F->m[i],j,currRing));
    }
    Mjvec.emplace_back(p_GetComp(F->m[i],currRing)); // last entry = component
    Mvec.emplace_back(Mjvec);
  }

  return std::make_pair(Mvec,F_in->ncols);
}

NO_NAME_MANGLING
std::tuple<ideal,ideal,kStrategy> singular_buchberger_get_Fstrat( [[maybe_unused]] std::string const& singular_library_name,
                                                                  [[maybe_unused]] std::string const& base_filename,
                                                                  [[maybe_unused]] std::string const& input,
                                                                  [[maybe_unused]] std::string const& GB)
{
  std::string ids = worker();

  init_singular (config::library().string());
	//load_singular_library(singular_library_name);

  std::pair<int,void*> input_ideal = deserialize(input, ids);
  ideal F_in = (ideal) ((lists) (((lists) input_ideal.second)->m[3]).data)->m[0].data;

  std::pair<int,void*> output_ideal = deserialize(GB, ids);
  ideal F = (ideal) ((lists) (((lists) output_ideal.second)->m[3]).data)->m[0].data;

  kStrategy strat=new skStrategy;
  strat->ak = id_RankFreeModule(F,currRing);
  strat->kModW=kModW=NULL;
  strat->kHomW=kHomW=NULL;
  initBuchMoraCrit(strat);
  initBuchMoraPos(strat);
  initBba(strat);
  initBuchMora(F, currRing->qideal,strat);
  //initBuchMora:
  strat->tail = pInit();
  //- set s -
  strat->sl = -1;
  //- set L -
  strat->Lmax = ((IDELEMS(F)+setmaxLinc-1)/setmaxLinc)*setmaxLinc;
  strat->Ll = -1;
  strat->L = initL(strat->Lmax);
  //- set B -
  strat->Bmax = setmaxL;
  strat->Bl = -1;
  strat->B = initL();
  //- set T -
  strat->tl = -1;
  strat->tmax = setmaxT;
  strat->T = initT();
  strat->R = initR();
  strat->sevT = initsevT();
  //- init local data struct.----------------------------------------
  strat->P.ecart=0;
  strat->P.length=0;
  strat->P.pLength=0;
  initS(F, currRing->qideal,strat); //sets also S, ecartS, fromQ
  strat->fromT = FALSE;
  strat->noTailReduction = FALSE;
  // build pairs
  if (strat->fromQ!=NULL)
  {
    for(int i=1; i<=strat->sl;i++)
    {
      initenterpairs(strat->S[i],i-1,0,strat->fromQ[i],strat);
    }
  }
  else
  {
    for(int i=1; i<=strat->sl;i++)
    {
      initenterpairs(strat->S[i],i-1,0,FALSE,strat);
    }
  }

  return std::make_tuple(F,F_in,strat);
}

NO_NAME_MANGLING
void singular_buchberger_compute_NF( [[maybe_unused]] std::string const& singular_library_name,
                                     [[maybe_unused]] std::string const& base_filename,
                                     std::tuple<ideal,ideal,kStrategy> Fstrat,
                                     GpiList const& started_indices,
                                     GpiList* BB_test_fail,
                                     GpiMap* runtime)
{
  ideal F         = std::get<0>(Fstrat); // Gröbner basis
  ideal F_in      = std::get<1>(Fstrat); // original ideal generators
  kStrategy strat = std::get<2>(Fstrat);

	//// start Singular and load the specified library ////
  init_singular (config::library().string());
	//load_singular_library(singular_library_name);

  // calculate NF(spoly,F)
  long start_time,stop_time;
  int red_result=1;
  if(started_indices.size()==2) // reduce an s-polynomial
  {
    int i=boost::get<int>(started_indices.front());
    int j=boost::get<int>(started_indices.back());
    start_time = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count();

    // create s-polynomial
    LObject sPair;
    sPair.Init();
    sPair.p1=F->m[i-1];
    sPair.p2=F->m[j-1];
    ksCreateSpoly(&sPair);

    stop_time = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count();
    (*runtime)[(std::string) "building s-polynomials"] = GpiList({-1L, stop_time, stop_time-start_time, 1L});

    start_time = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count();
    poly NF_spoly;
    if ((sPair.p == NULL) && (sPair.t_p == NULL))
    {
      red_result = 0;
    }
    else
    {
      int sl=strat->sl;
      sPair.GetP();

      // the actual reduction:
      NF_spoly=redNF(sPair.p,sl,TRUE,strat);

      if (NF_spoly==NULL) red_result=0;
    }
    stop_time = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count();
    (*runtime)[(std::string) "reduction of s-polynomials"] = GpiList({-1L, stop_time, stop_time-start_time, 1L});
  }
  else // List '{j}' with one element: reduce the j-th generator of the original ideal
  {

    start_time = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count();
    int sl=strat->sl;
    poly NF_spoly=redNF(F_in->m[boost::get<int>(started_indices.front())-1],sl,TRUE,strat);
    if (NF_spoly==NULL) {red_result=0;}
    stop_time = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count();
    (*runtime)[(std::string) "building s-polynomials"] = GpiList({-1L, stop_time, 0L, 0L});
    (*runtime)[(std::string) "reduction of s-polynomials"] = GpiList({-1L, stop_time, stop_time-start_time, 1L});
  }

  if (red_result!=0) // reduction to non-zero polynomial ==> Buchberger Test fails
  {
    (*BB_test_fail).emplace_back(CONTROL_TOKEN);
  }
}

NO_NAME_MANGLING
void abort_BB_test([[maybe_unused]] std::string const& singular_library_name,
                   [[maybe_unused]] std::string const& base_filename,
                   [[maybe_unused]] std::string* output)
{
  std::string ids = worker();
  std::pair<int,void*> output_ideal = deserialize(*output, ids);
  ((lists) (((lists) output_ideal.second)->m[3]).data)->m[1].data = (void*) (char*) 0; // set certificate to "false" as a reduction was non-zero
  (*output) = serialize((lists) output_ideal.second, base_filename);
}
