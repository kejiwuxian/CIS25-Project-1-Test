#include <iostream>	// For cout, endl
#include <iomanip>	// For left, setw
#include <string>	// For string
#include <cstdlib>	// For system

#include "util/print_help.hpp"				// For user_interaction::print_help
#include "util/currencies_enum.hpp"			// For currencies::currencies
#include "util/currencies_names.hpp"			// For currencies::names
#include "util/units_enum.hpp"				// For units::units
#include "util/units_names.hpp"				// For units::names
#include "util/process_input_original.hpp"	// For user_interaction::process_input
#include "util/process_input_target.hpp"		// For user_interaction::process_input
#include "util/convert_currency.hpp"			// For currencies::convert_currency
#include "util/convert_unit.hpp"				// For units::convert_unit

using namespace std;

// Namespace for everything related to user interaction
namespace user_interaction
{
	// Handle user interactions
	void handle_interactions()
	{
		string input;
		double price, weight;
		currencies::currencies original_currency, target_currency;
		units::units original_unit, target_unit;

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
			if (process_input(input, price, original_currency, weight, original_unit))
			{
				do
				{
					cout << "Please enter TARGET_CURRENCY/TARGET_UNIT: ";
					getline(cin, input);
				} while (!process_input(input, target_currency, target_unit));

				cout << left << setw(16) << setprecision(14) << currencies::convert_currency(price, original_currency, target_currency) / units::convert_unit(weight, original_unit, target_unit)
					<< currencies::names[static_cast<int>(target_currency)] << " per " << units::names[static_cast<int>(target_unit)] << endl << endl;
			}
		} while (true);
	}
}