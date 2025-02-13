#include <iostream>	// For cout, endl
#include <iomanip>	// For left, setw
#include <string>	// For string
#include <cstdlib>	// For system

#include "print_help.hpp"				// For user_interaction::print_help
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
	// Handle user interactions
	void handle_interactions()
	{
		string input;
		double price, weight;
		currencies::currencies currency_from, currency_to;
		units::units unit_from, unit_to;

		print_help();
		cout << "Press enter to continue...";
		getline(cin, input);

		// Clear console window, an example use of advanced features
		#ifdef _WIN32 // Windows MSVC
		system("cls");
		#else // Linux, MacOS
		system("clear");
		#endif

		// An example use of do-while loop
		do
		{
			cout << "Press enter without input to exit." << endl;
			cout << "Please enter [PRICE]ORIGINAL_CURRENCY/[WEIGHT]ORIGINAL_UNIT: ";
			getline(cin, input);

			if (input.empty())
			{
				return;
			}

			// An example use of nested conditions and overloading functions
			if (process_input(input, price, currency_from, weight, unit_from))
			{
				cout << "Please enter TARGET_CURRENCY/TARGET_UNIT: ";
				getline(cin, input);

				if (process_input(input, currency_to, unit_to))
				{
					cout << left << setw(16) << setprecision(14) << currencies::convert_currency(price, currency_from, currency_to) / units::convert_unit(weight, unit_from, unit_to)
						<< currencies::names[static_cast<int>(currency_to)] << " per " << units::names[static_cast<int>(unit_to)] << endl << endl;
				}
			}
		} while (true);
	}
}