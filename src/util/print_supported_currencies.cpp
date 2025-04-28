#include <iostream>	// For cout, endl
#include <iomanip>	// For left, setw
#include <array>	// For size

#include "util/currencies_names.hpp"			// For currencies::names
#include "util/currencies_descriptions.hpp"	// For currencies::descriptions

using namespace std;

// Namespace for everything related to the currencies
namespace currencies
{
	// Print all supported currencies, an example use of namespace
	void print_all()
	{
		cout << "supported_currencies:" << endl;
		for (int i = 0;i < size(names);i++)
		{
			cout << left << setw(40) << "    " + names[i] << descriptions[i] << endl;
		}
		cout << endl;
	}
}