#include <iostream>	// For cout, endl
#include <string>	// For string
#include <array>	// For size

#include "currencies_enum.hpp"		// For currencies::currencies
#include "currencies_names.hpp"		// For currencies::names
#include "units_enum.hpp"			// For units::units
#include "units_names.hpp"			// For units::names
#include "strip_and_to_lower.hpp"	// For strip_and_to_lower

using namespace std;

// Namespace for everything related to user interaction
namespace user_interaction
{
	// Try to process user inputted original price, currency, weight, and unit
	bool process_input(string input, double& price, currencies::currencies& currency, double& weight, units::units& unit)
	{
		// Process price
		util::strip_and_to_lower(input);
		size_t i = input.find_first_not_of("0123456789.");	// Find the end of the price
		if (i == string::npos)								// When the end of the price is not found
		{
			cout << "Please enter a valid currency after the price" << endl << endl;
			return false;
		}
		string str = input.substr(0, i);					// The string for the price
		if (str.empty())									// When the price is omitted by user
		{
			price = 1;										// Default to 1
		}
		else
		{
			try
			{
				price = stod(str);							// Convert the string for the price to double
				if (price <= 0)								// When the price entered is not a positive number
				{
					throw;
				}
			}
			catch (exception)
			{
				cout << "Please enter a valid positive number as price" << endl << endl;
				return false;
			}
		}

		input = input.substr(i);							// Skip the price

		// Process currency
		i = input.find('/');								// Find the end of the currency
		if (i == string::npos)								// When the end of the currency is not found
		{
			cout << "Please type '/' between currency and weight" << endl << endl;
			return false;
		}
		str = input.substr(0, i);							// The string for the currency
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

		// Process weight
		util::strip_and_to_lower(input);
		i = input.find_first_not_of("0123456789.");			// Find the end of the weight
		if (i == string::npos)								// When the end of the weight is not found
		{
			cout << "Please enter a valid unit after the weight" << endl << endl;
			return false;
		}
		str = input.substr(0, i);							// The string for the weight
		if (str.empty())									// When the weight is omitted by user
		{
			weight = 1;										// Default to 1
		}
		else
		{
			try
			{
				weight = stod(str);							// Convert the string for the weight to double
				if (weight <= 0)							// When the weight entered is not a positive number
				{
					throw;
				}
			}
			catch (exception)
			{
				cout << "Please enter a valid positive number as weight" << endl << endl;
				return false;
			}
		}
		input = input.substr(i);							// Skip the weight

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