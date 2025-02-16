#include <iostream>	// For cout, endl
#include <iomanip>	// For left, setw
#include <string>	// For string

#include "print_help.hpp"				// For print_help
#include "currencies_enum.hpp"			// For currencies::currencies
#include "currencies_names.hpp"			// For currencies::names
#include "units_enum.hpp"				// For units::units
#include "units_names.hpp"				// For units::names
#include "process_input_original.hpp"	// For user_interaction::process_input
#include "process_input_target.hpp"		// For user_interaction::process_input
#include "convert_currency.hpp"			// For currencies::convert_currency
#include "convert_unit.hpp"				// For units::convert_unit

using namespace std;

// Namespace for everything related to user interaction
namespace user_interaction
{
	// Handle command line arguments
	void handle_arguments(const int argc, const char** argv)
	{
		// An example use of switch statement
		switch (argc)
		{
		case 3:	// Expected number of arguments
			double price, weight;
			currencies::currencies original_currency, target_currency;
			units::units original_unit, target_unit;

			// An example use of nested conditions and overloading functions
			if (process_input(string(argv[1]), price, original_currency, weight, original_unit))
			{
				if (process_input(string(argv[2]), target_currency, target_unit))
				{
					cout << left << setw(16) << setprecision(14) << currencies::convert_currency(price, original_currency, target_currency) / units::convert_unit(weight, original_unit, target_unit)
						<< currencies::names[static_cast<int>(target_currency)] << " per " << units::names[static_cast<int>(target_unit)] << endl << endl;
				}
			}
			break;
		default:// Unexpected number of arguments
			print_help();
			break;
		}

	}
}