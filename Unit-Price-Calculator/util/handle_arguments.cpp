#include <iostream>	// For cout, endl
#include <iomanip>	// For left, setw
#include <string>	// For string

#include "print_help.hpp"			// For print_help
#include "supported_currencies.hpp"	// For currencies, currencies::names
#include "supported_units.hpp"		// For units, units::names
#include "process_original.hpp"		// For process_original
#include "process_target.hpp"		// For process_target
#include "convert_currency.hpp"		// For convert_currency
#include "convert_unit.hpp"			// For convert_unit

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