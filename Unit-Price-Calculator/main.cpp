#include <iostream>	// For cerr, endl

#include "util/handle_arguments.hpp"	// For handle_arguments
#include "util/handle_interaction.hpp"	// For handle_interaction

using namespace std;

int main(int argc, char** argv)
{
	// An example of exception handling
	try
	{
		if (argc > 1)
		{
			// An example use of const_cast
			user_interaction::handle_arguments(argc, const_cast<const char**>(argv));
		}
		else
		{
			user_interaction::handle_interaction();
		}
	}
	catch (exception& e)
	{
		cerr << e.what() << endl;
		return -1;
	}

	return 0;
}