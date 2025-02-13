#include <iostream>	// For cout, endl
#include <string>	// For string
#include <array>	// For size

#include "supported_currencies.hpp"	// For currencies::names
#include "supported_units.hpp"		// For units::names
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
		size_t i = input.find_first_not_of("0123456789.");
		if (i == string::npos)
		{
			cout << "Please enter a valid currency after the price" << endl << endl;
			return false;
		}
		string str = input.substr(0, i);
		if (str.empty())
		{
			price = 1;
		}
		else
		{
			try
			{
				price = stod(str);
				if (price <= 0)
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

		input = input.substr(i);

		// Process currency
		i = input.find('/');
		if (i == string::npos)
		{
			cout << "Please type '/' between currency and weight" << endl << endl;
			return false;
		}
		str = input.substr(0, i);
		util::strip_and_to_lower(str);
		bool no_match = true;
		for (int j = 0;j < size(currencies::names);j++)
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
			for (auto name : currencies::names)
			{
				cout << name << ' ';
			}
			cout << endl << endl;
			return false;
		}
		input = input.substr(i + 1);

		// Process weight
		util::strip_and_to_lower(input);
		i = input.find_first_not_of("0123456789.");
		if (i == string::npos)
		{
			cout << "Please enter a valid unit after the weight" << endl << endl;
			return false;
		}
		str = input.substr(0, i);
		if (str.empty())
		{
			weight = 1;
		}
		else
		{
			try
			{
				weight = stod(str);
				if (weight <= 0)
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
		input = input.substr(i);

		// Process unit
		util::strip_and_to_lower(input);
		no_match = true;
		for (int j = 0;j < size(units::names);j++)
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
			for (auto name : units::names)
			{
				cout << name << ' ';
			}
			cout << endl << endl;
			return false;
		}

		return true;
	}
}