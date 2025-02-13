#include <iostream>	// For cout, endl
#include <iomanip>	// For left, setw

#include "print_help.hpp"			// For print_help
#include "supported_currencies.hpp"	// For currencies
#include "get_exchange_rate.hpp"	// For get_exchange_rate

using namespace std;

// Namespace for everything related to user interaction
namespace user_interaction
{
	// Handle command line arguments
	void handle_arguments(const int argc, const char** argv)
	{
		print_help();
		cout << currencies::get_exchange_rate(currencies::currencies::usd, currencies::currencies::cny) << endl;
	}
}