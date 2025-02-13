#include <iostream>	// For cerr, endl

#include "util/handle_arguments.hpp"	// For handle_arguments
#include "util/handle_interactions.hpp"	// For handle_interactions

using namespace std;

int main(int argc, char** argv)
{
	// An example of exception handling
	try
	{
		// Check if the user has entered any command line argument, an example use of conditional operator and const_cast
		argc > 1 ? user_interaction::handle_arguments(argc, const_cast<const char**>(argv)) : user_interaction::handle_interactions();
	}
	catch (exception& e)
	{
		// Output the error message
		cerr << e.what() << endl;
		return -1;
	}

	return 0;
}