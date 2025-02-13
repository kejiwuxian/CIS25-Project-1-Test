#include <iostream>	// For cout, endl
#include <iomanip>	// For left, setw
#include <string>	// For string
#include <cstdlib>	// For system

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
	// Handle user interaction
	void handle_interaction()
	{
		string input;
		double price, weight;
		currencies::currencies currency_from, currency_to;
		units::units unit_from, unit_to;
		print_help();
		cout << "Press enter to continue...";
		getline(cin, input);
#ifdef _WIN32 // Windows MSVC
		system("cls");
#else // Linux, MacOS
		system("clear");
#endif
		while (true)
		{
			cout << "Press enter without input to exit." << endl;
			cout << "Please enter [PRICE]ORIGINAL_CURRENCY/[WEIGHT]ORIGINAL_UNIT: ";
			getline(cin, input);
			if (input.empty())
			{
				return;
			}
			if (!process_original(input, price, currency_from, weight, unit_from))
			{
				continue;
			}

			cout << "Please enter TARGET_CURRENCY/TARGET_UNIT: ";
			getline(cin, input);
			if (!process_target(input, currency_to, unit_to))
			{
				continue;
			}

			cout << left << setw(16) << setprecision(14) << currencies::convert_currency(price, currency_from, currency_to) / units::convert_unit(weight, unit_from, unit_to)
				<< currencies::names[static_cast<int>(currency_to)] << " per " << units::names[static_cast<int>(unit_to)] << endl << endl;
		}
	}
}