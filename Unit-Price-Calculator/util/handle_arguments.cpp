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
		case 3:
			double price, weight;
			currencies::currencies currency_from, currency_to;
			units::units unit_from, unit_to;

			// An example use of nested conditions
			if (process_input(string(argv[1]), price, currency_from, weight, unit_from))
			{
				if (process_input(string(argv[2]), currency_to, unit_to))
				{
					cout << left << setw(16) << setprecision(14) << currencies::convert_currency(price, currency_from, currency_to) / units::convert_unit(weight, unit_from, unit_to)
						<< currencies::names[static_cast<int>(currency_to)] << " per " << units::names[static_cast<int>(unit_to)] << endl << endl;
				}
			}
			break;
		default:
			print_help();
			break;
		}

	}
}