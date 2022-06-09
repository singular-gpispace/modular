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
	std::string out_filename1;
	std::string out_filename2;
	out_filename1 = singular_modular_generate( in_filename, prime_filename, "generate","modulargp.lib" );
	out_filename2 = singular_modular_compute(out_filename1, "stdmodp","modulargp.lib");
	std::cout << out_filename2 << std::endl;
	return 0;
}
