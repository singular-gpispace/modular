#include <string>
#include <vector>
#include <optional>
#include<iostream>

#include <installation.hpp>

#include <drts/client.hpp>
#include <drts/drts.hpp>
#include <drts/scoped_rifd.hpp>

#include <util-generic/executable_path.hpp>
#include <util-generic/print_exception.hpp>
#include <util-generic/read_lines.hpp>

#include "Singular/libsingular.h"

#include "../../modular/singular_functions.hpp"

namespace
{
  template<std::size_t arg_index>
  leftv to_nth_arg (leftv args)
  {
    for (std::size_t index (arg_index); args && index > 0; --index)
    {
      args = args->next;
    }

    return args ? args : throw std::invalid_argument ("too few arguments");
  }

  template<std::size_t arg_index, typename T>
  T require_argument (leftv args, int type, std::string type_name,
    std::string argument_name)
  try
  {
    leftv arg (to_nth_arg<arg_index> (args));
    if (arg->Typ() != type)
    {
      throw std::invalid_argument ("expected " + type_name);
    }
    return reinterpret_cast<T> (arg->Data());
  }
  catch (...)
  {
    std::throw_with_nested
      ( std::invalid_argument
         ( "argument " + std::to_string (arg_index)
         + " '" + argument_name + "'"
         )
      );
  }

  template<std::size_t first_optional>
    std::vector<std::string> remaining_string_arguments (leftv args)
  {
    std::vector<std::string> strings;

    leftv it (to_nth_arg<first_optional - 1> (args)->next);
    while (it)
    {
      if (it->Typ() != STRING_CMD)
      {
        throw std::invalid_argument ("expected string");
      }
      strings.emplace_back (reinterpret_cast<char*> (it->Data()));
      //std::cout << "extra arg: " << strings.back() << "\n";

      it = it->next;
    }

    return strings;
  }

  template<std::size_t arg_index, typename T>
    T nth_list_arg (lists l)
  {
    return reinterpret_cast<T> (l->m[arg_index].data);
  }

  class ArgumentState {
    public:
      ArgumentState (leftv args);

      int outToken() const;
      int procsPerNode() const;
      std::size_t numTasks() const;

      std::string tmpDir() const;
      std::string nodeFile() const;
      std::string showStrategy() const;
      std::string baseFileName() const;
      std::string neededLibrary() const;
      std::string functionNameCompute() const;
			std::string functionNameLift() const;
      std::string functionNameSplit() const;
			std::string functionNameFarey() const;
      std::string functionNameAppend() const;
      std::string functionNameCompatible() const;
      std::string functionNameCompare() const;
      std::string functionNameGenNextPrime() const;
			long bal1() const;
			long bal2() const;
      unsigned long M1() const;
      unsigned long M2() const;

      singular_modular::installation singPI() const;
      lists argList() const;
      lists addArgsList() const;
			lists pList() const;
    private:
      lists arg_list;
      lists p_list;

      std::string tmpdir;
      std::string nodefile;
      int procspernode;
      std::string strategy;
      lists addargs_list;
			std::size_t num_tasks;
      
      std::string neededlibrary;
      std::string functionnamegennextprime;
      std::string functionnamecompute;
			std::string functionnamelift;
      std::string functionnamesplit;
			std::string functionnamefarey;
      std::string functionnameappend;
      std::string functionnamecompatible;
      std::string functionnamecompare;
      
			long bal1_value;
			long bal2_value;
      unsigned long M1_value;
      unsigned long M2_value;
      int out_token;
      std::string base_filename;

      singular_modular::installation singular_modular_installation;
  };


//  int ArgumentState::outToken() const {
 //   return out_token;
  //}

  int ArgumentState::procsPerNode() const {
    return procspernode;
  }

	long ArgumentState::bal1() const {
	  return bal1_value;
	}

	long ArgumentState::bal2() const {
	  return bal2_value;
	}

  unsigned long ArgumentState::M1() const {
    return M1_value;
  }

  unsigned long ArgumentState::M2() const {
    return M2_value;
  } 


  std::size_t ArgumentState::numTasks() const {
    return num_tasks;
  }

  
 // std::string ArgumentState::tmpDir() const {
   // return tmpdir;
  //}
  

  std::string ArgumentState::nodeFile() const {
    return nodefile;
  }

  std::string ArgumentState::showStrategy() const {
    return strategy;
  }

  std::string ArgumentState::baseFileName() const {
    return base_filename;
  }

  std::string ArgumentState::neededLibrary() const {
    return neededlibrary;
  }
  
  std::string ArgumentState::functionNameGenNextPrime() const{
    return functionnamegennextprime;
  }

  std::string ArgumentState::functionNameCompute() const {
    return functionnamecompute;
  }

	std::string ArgumentState::functionNameLift() const {
		return functionnamelift;
	}

  std::string ArgumentState::functionNameSplit() const {
		return functionnamesplit;
	}

	std::string ArgumentState::functionNameFarey() const {
		return functionnamefarey;
	}

  std::string ArgumentState::functionNameAppend() const {
		return functionnameappend;
	}

  std::string ArgumentState::functionNameCompatible() const {
    return functionnamecompatible;
  }

  std::string ArgumentState::functionNameCompare() const {
    return functionnamecompare;
  }

  singular_modular::installation ArgumentState::singPI() const {
    return singular_modular_installation;
  }

  lists ArgumentState::argList() const {
    return arg_list;
  }

  lists ArgumentState::addArgsList() const {
    return addargs_list;
  }

	lists ArgumentState::pList() const{
		return p_list;
	}

  int fetch_token_value_from_sing_scope (std::string token_s) {
    int token_v;
    blackboxIsCmd (token_s.c_str(), token_v);
    return token_v;
  }

  ArgumentState::ArgumentState (leftv args)
  : arg_list (require_argument<0, lists> (args,
                                          LIST_CMD,
                                          "list",
                                          "list of input structs"))
  , p_list (require_argument<1,lists> (args,
                                     LIST_CMD,
                                     "list",
                                     "prime list"))
  , tmpdir (require_argument<2, char*> (args,
                                        STRING_CMD,
                                        "string",
                                        "temp directory"))
  , nodefile (require_argument<3, char*> (args,
                                          STRING_CMD,
                                          "string",
                                          "nodefile"))
  , procspernode (require_argument<4, long> (args,
                                            INT_CMD,
                                            "int",
                                            "processes per node"))
  , strategy (require_argument<5, char*> (args,
                                          STRING_CMD,
                                          "string",
                                          "rif strategy"))
  , addargs_list (require_argument<6, lists> (args,
                                              LIST_CMD,
                                              "list",
                                              "additional arguments"))
	, num_tasks (p_list->nr + 1)
  , neededlibrary (require_argument<7, char*> (args,
                                                STRING_CMD,
                                                "string",
                                                "needed library"))
  , functionnamegennextprime (require_argument<8, char*> (args,
                                                           STRING_CMD,
                                                           "string",
                                                           "function name genNextPrime"))
  , functionnamecompute (require_argument<9, char*> (args,
                                               STRING_CMD,
                                               "string",
                                               "function name compute"))
  , functionnamelift (require_argument<10, char*> (args,
                                             STRING_CMD,
                                             "string",
                                             "function name lift"))
  , functionnamesplit (require_argument<11, char*> (args,
                                             STRING_CMD,
                                             "string",
                                             "function name split"))                                         
	, functionnamefarey (require_argument<12, char*> (args,
                                           STRING_CMD,
                                           "string",
                                           "function name farey"))
  , functionnameappend (require_argument<13, char*> (args,
                                             STRING_CMD,
                                             "string",
                                             "function name append"))
  , functionnamecompatible (require_argument<14, char*> (args,
                                            STRING_CMD,
                                            "string",
                                            "function name compatible"))
  , functionnamecompare (require_argument<15, char*> (args,
                                            STRING_CMD,
                                            "string",
                                            "function name compare"))
	, bal1_value (require_argument<16, long> (args,
                                         INT_CMD,
                                         "long",
                                         "number of tokens on bal1"))
	, bal2_value (require_argument<17, long> (args,
                                         INT_CMD,
                                         "long",
                                         "number of tokens on bal2"))
 
  , M1_value (require_argument<18, unsigned long> (args,
                                           INT_CMD,
                                           "int",
                                           "value of M1"))
  , M2_value (require_argument<19, unsigned long>(args,
                                          INT_CMD,
                                          "int",
                                          "value of M2"))

  , out_token (fetch_token_value_from_sing_scope ("token"))
  , base_filename (tmpdir + "/")
  , singular_modular_installation ()
  {
    if (out_token == 0)
    {
      throw std::invalid_argument ("struct does not exist");
    }
  }
}

void sggspc_print_current_exception (std::string s)
{
  WerrorS (("singular_modular: (" + s + ") " +
            fhg::util::current_exception_printer (": ").string()).c_str());
}

std::optional<std::multimap<std::string, pnet::type::value::value_type>>
                    gpis_launch_with_workflow (boost::filesystem::path workflow,
                    ArgumentState const &as)
try
{
  /*
  std::string debugout = as.tmpDir() + " " + as.nodeFile() + " " +
    std::to_string (as.procsPerNode()) + " " + as.showStrategy() + "\n" +
    as.inStructName() + " " + as.inStructDesc() + " " +
    as.outStructName() + " " + as.outStructDesc() + " " +
    as.neededLibrary() + " " + as.functionName() + "\n";
  */

  std::vector<std::string> options;
  std::size_t num_addargs = as.addArgsList()->nr + 1;
  //PrintS ((std::to_string (num_addargs) + " additional arguments\n").c_str());
  for (std::size_t i = 0; i < num_addargs; ++i)
  {
    int arg_type = as.addArgsList()->m[i].rtyp;
    if (arg_type != STRING_CMD)
    {
      throw std::invalid_argument ("wrong type of additional option "
        + std::to_string (i) + ", expected string got "
        + std::to_string (arg_type));
    }
    const std::string addarg_str
      (static_cast<char*> (as.addArgsList()->m[i].data));
    //debugout += addarg_str + "\n";
    options.push_back (addarg_str);
  }

  //PrintS (debugout.c_str());
  //PrintS (("have " + std::to_string (as.numTasks()) + " tasks\n").c_str());

  int io_token;
  blackboxIsCmd ("token", io_token);
  if (io_token ==  0)
  {
    throw std::invalid_argument ("struct does not exist");
  }

  for (std::size_t i = 0; i < as.numTasks(); ++i)
  {
    int task_type = as.pList()->m[i].rtyp;
    if (task_type != io_token)
    {
      throw std::invalid_argument ("wrong type of argument "
        + std::to_string (i) + ", expected " + std::to_string (io_token)
        + " got " + std::to_string (task_type));
    }
  }

  for (std::size_t i = 0; i < as.numTasks(); ++i)
  {
    si_link l = ssi_open_for_write (as.baseFileName() 
      + "p"+std::to_string (i));
    ssi_write_newstruct (l, io_token,
      static_cast<lists> (as.pList()->m[i].data));
    ssi_close_and_remove (l);
  }
	std::string in_filename = "input";
	si_link l = ssi_open_for_write (as.baseFileName()+in_filename);
	ssi_write_newstruct (l, io_token,
  static_cast<lists> (as.argList()->m[0].data));
	ssi_close_and_remove (l);


  // now prepare startup of GPI-Space
  // TODO: do this independent from actual call?

  std::string const topology_description
    ("worker:" + std::to_string (as.procsPerNode())); // here, only one type

  boost::filesystem::path const implementation
    (as.singPI().workflow_dir() /
     "libmodular_implementation.so");

  boost::program_options::options_description options_description;
  options_description.add_options() ("help", "Display this message");
  options_description.add (gspc::options::logging());
  options_description.add (gspc::options::scoped_rifd
                                      (gspc::options::rifd::rif_port));
  options_description.add (gspc::options::drts());

  boost::program_options::variables_map vm;
  boost::program_options::store
    ( boost::program_options::command_line_parser (options)
    . options (options_description).run()
    , vm
    );

  // help option left as is. If this is really to be used, it should be checked
  // earlier. Using std::cout is not really right, should rather write to
  // std::stringstream and use PrintS ...
  if (vm.count ("help"))
  {
    std::cout << options_description;
    return std::nullopt;
  }

  gspc::installation const gspc_installation
    (as.singPI().gspc_installation (vm));

  gspc::scoped_rifds const scoped_rifd
    ( gspc::rifd::strategy
        { [&]
          {
            using namespace boost::program_options;
            variables_map vm;
            vm.emplace ("rif-strategy"
                       , variable_value (as.showStrategy(), false));
            vm.emplace ( "rif-strategy-parameters"
                       , variable_value (std::vector<std::string>{}, true)
                       );
            return vm;
          }()
        }
    , gspc::rifd::hostnames
        { [&]
          {
            try
            {
              return fhg::util::read_lines (as.nodeFile());
            }
            catch (...)
            {
              std::throw_with_nested (std::runtime_error ("reading nodefile"));
            }
          }()
        }
    , gspc::rifd::port {vm}
    , gspc_installation
    );

  gspc::scoped_runtime_system drts ( vm
                                   , gspc_installation
                                   , topology_description
                                   , scoped_rifd.entry_points()
                                   );

	  std::multimap<std::string, pnet::type::value::value_type> values_on_ports;
		for(std::size_t j = 0; j < as.numTasks(); ++j)
		{
			  values_on_ports.emplace ("primes", as.baseFileName()+"p" + std::to_string(j));
		}
		values_on_ports.emplace("input", as.baseFileName()+in_filename);
    
    lists lastToken = static_cast<lists> (as.pList()->m[as.numTasks()-1].data);
    lists tokenvalue = (lists)lastToken->m[3].Data();//ring-lists-ring-lists
    values_on_ports.emplace("last_prime",(int) (long) tokenvalue->m[0].Data());

		values_on_ports.emplace("implementation", implementation.string());
    values_on_ports.emplace("function_name_genNextPrime",as.functionNameGenNextPrime());
		values_on_ports.emplace("function_name_compute", as.functionNameCompute());
		values_on_ports.emplace("function_name_lift", as.functionNameLift());
    values_on_ports.emplace("function_name_split", as.functionNameSplit());
		values_on_ports.emplace("function_name_farey", as.functionNameFarey());
    values_on_ports.emplace("function_name_append", as.functionNameAppend());
    values_on_ports.emplace("function_name_compatible", as.functionNameCompatible());
    values_on_ports.emplace("function_name_compare", as.functionNameCompare());
		values_on_ports.emplace("needed_library",as.neededLibrary());
		values_on_ports.emplace("base_filename", as.baseFileName());
		values_on_ports.emplace("input_bal1", as.bal1());
		values_on_ports.emplace("input_bal2",as.bal2());
    values_on_ports.emplace("input_M1",as.M1());
    values_on_ports.emplace("input_M2", as.M2());
  std::multimap<std::string, pnet::type::value::value_type> result
    ( gspc::client (drts).put_and_run
      ( gspc::workflow (workflow)
      , values_on_ports));
  return result;
}
catch (...)
{
  // need to check which resources must be tidied up
  sggspc_print_current_exception (std::string ("in gpis_launch_with_workflow"));
  return std::nullopt;
}

BOOLEAN sggspc_modular (leftv res, leftv args)
try {
  ArgumentState as (args);
  auto result = gpis_launch_with_workflow (as.singPI().workflow_all(), as);
  if (!result.has_value()) {
    res->rtyp = NONE;
    return FALSE;
  }
  std::multimap<std::string, pnet::type::value::value_type>::const_iterator
   sm_result_it (result.value().find ("output"));
  if (sm_result_it == result.value().end())
  {
    throw std::runtime_error ("Petri net has not finished correctly");
  }
  std::string out = boost::get<std::string> (sm_result_it->second);
  std::pair<int, lists> entry (deserialize(out,"Extraction of result"));

	res->rtyp = entry.first;
	res->data = entry.second;
  return FALSE;
}
catch (...)
{
  // need to check which resources must be tidied up
  sggspc_print_current_exception (std::string ("in sggspc_modular"));
  return TRUE;
}

extern "C" int mod_init (SModulFunctions* psModulFunctions)
{
  // TODO: explicit check if module has already been loaded?
  //PrintS ("DEBUG: in mod_init\n");

  psModulFunctions->iiAddCproc
    ((currPack->libname ? currPack->libname : ""),
      "sggspc_modular", FALSE, sggspc_modular);

  return MAX_TOK;
}
