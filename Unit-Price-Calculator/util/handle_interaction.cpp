#include <iostream>	// For cout, endl
#include <iomanip>	// For left, setw

#include "print_help.hpp"			// For print_help
#include "supported_currencies.hpp"	// For currencies
#include "supported_units.hpp"		// For units
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
		print_help();
		cout << "Please enter [PRICE][ORIGINAL_CURRENCY]/[WEIGHT][ORIGINAL_UNIT]: ";
		string input;
		getline(cin, input);
		double price, weight;
		currencies::currencies currency_from;
		units::units unit_from;
		if (process_original(input, price, currency_from, weight, unit_from))
		{
			cout << price << endl;
			cout << currency_from << endl;
			cout << weight << endl;
			cout << unit_from << endl;
		}
		else
		{
			return;
		}
		cout << "Please enter [TARGET_CURRENCY]/[TARGET_UNIT]: ";
		getline(cin, input);
		currencies::currencies currency_to;
		units::units unit_to;
		if (process_target(input, currency_to, unit_to))
		{
			cout << currency_to << endl;
			cout << unit_to << endl;
		}
		else
		{
			return;
		}

		cout << currencies::convert_currency(price, currency_from, currency_to) << currencies::names[currency_to] << '/'
			<< units::convert_unit(weight, unit_from, unit_to) << units::names[unit_to] << endl;
		cout << currencies::convert_currency(price, currency_from, currency_to) / units::convert_unit(weight, unit_from, unit_to)
			<< currencies::names[currency_to] << '/' << units::names[unit_to] << endl;
	}
}