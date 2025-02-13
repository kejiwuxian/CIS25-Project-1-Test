#include <iostream>

#include "util/handle_arguments.hpp"
#include "util/handle_interaction.hpp"

using namespace std;

int main(int argc, char** argv)
{
	try
	{
		if (argc > 1)
		{
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