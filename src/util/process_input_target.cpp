#include <iostream>	// For cout, endl
#include <string>	// For string
#include <array>	// For size

#include "util/currencies_enum.hpp"		// For currencies::currencies
#include "util/currencies_names.hpp"		// For currencies::names
#include "util/units_enum.hpp"			// For units::units
#include "util/units_names.hpp"			// For units::names
#include "util/strip_and_to_lower.hpp"	// For strip_and_to_lower

using namespace std;

// Namespace for everything related to user interaction
namespace user_interaction
{
	// Try to process user inputted target currency and unit
	bool process_input(string input, currencies::currencies& currency, units::units& unit)
	{
		// Process currency
		util::strip_and_to_lower(input);
		size_t i = input.find('/');							// Find the end of the currency
		if (i == string::npos)								// When the end of the currency is not found
		{
			cout << "Please type '/' between currency and weight" << endl << endl;
			return false;
		}
		string str = input.substr(0, i);					// The string for the currency
		util::strip_and_to_lower(str);
		bool no_match = true;
		for (int j = 0;j < size(currencies::names);j++)		// Linear Search
		{
			if (str == currencies::names[j])
			{
				currency = static_cast<currencies::currencies>(j);
				no_match = false;
				break;
			}
		}
		if (no_match)
		{
			cout << "Currency \"" + str + "\" is not supported" << endl;
			cout << "Supported currencies: ";
			for (auto name : currencies::names)				// Iterate array with for each loop
			{
				cout << name << ' ';
			}
			cout << endl << endl;
			return false;
		}
		input = input.substr(i + 1);						// Skip the currency

		// Process unit
		util::strip_and_to_lower(input);
		no_match = true;
		for (int j = 0;j < size(units::names);j++)			// Linear Search
		{
			if (input == units::names[j])
			{
				unit = static_cast<units::units>(j);
				no_match = false;
				break;
			}
		}
		if (no_match)
		{
			cout << "Unit \"" + input + "\" is not supported" << endl;
			cout << "Supported units: ";
			for (auto name : units::names)					// Iterate array with for each loop
			{
				cout << name << ' ';
			}
			cout << endl << endl;
			return false;
		}

		return true;
	}
}