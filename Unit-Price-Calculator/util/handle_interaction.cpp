#include <iostream>	// For cout, endl
#include <iomanip>	// For left, setw

#include "print_help.hpp"			// For print_help
#include "supported_currencies.hpp"	// For currencies
#include "supported_units.hpp"		// For units
#include "get_exchange_rate.hpp"	// For get_exchange_rate
#include "process_original.hpp"		// For process_original
#include "process_target.hpp"		// For process_target

using namespace std;

// Namespace for everything related to user interaction
namespace user_interaction
{
	// Handle user interaction
	void handle_interaction()
	{
		print_help();
		cout << currencies::get_exchange_rate(currencies::currencies::usd, currencies::currencies::cny) << endl;
		cout << "Please enter [PRICE][ORIGINAL_CURRENCY]/[WEIGHT][ORIGINAL_UNIT]: ";
		string input;
		getline(cin, input);
		double price, weight;
		currencies::currencies currency;
		units::units unit;
		if (process_original(input, price, currency, weight, unit))
		{
			cout << price << endl;
			cout << currency << endl;
			cout << weight << endl;
			cout << unit << endl;
		}
		cout << "Please enter [TARGET_CURRENCY]/[TARGET_UNIT]: ";
		getline(cin, input);
		if (process_target(input, currency, unit))
		{
			cout << currency << endl;
			cout << unit << endl;
		}
	}
}