#include <iostream>

#include <Singular/libsingular.h>

#include "functions.cpp"
#include "implementations.cpp"

int main()
{
	// init path names etc.
	siInit((char *)"/opt/Singular430/Singular/lib/libSingular.so");
	
	std::string in_filename = "input.ssi";
	std::string prime_filename = "prime.ssi";
	std::string out_filename;
	out_filename = singular_modular_generate( in_filename, prime_filename, "generate","modulargp.lib" );
	std::cout << out_filename << std::endl;
	return 0;
}
