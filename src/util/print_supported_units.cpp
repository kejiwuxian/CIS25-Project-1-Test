#include <iostream>	// For cout, endl
#include <iomanip>	// For left, setw
#include <array>	// For size

#include "util/units_names.hpp"			// For units::names
#include "util/units_descriptions.hpp"	// For units::descriptions

using namespace std;

// Namespace for everything related to the units
namespace units
{
	// Print all supported units, an example use of namespace
	void print_all()
	{
		cout << "supported_units:" << endl;
		for (int i = 0;i < size(names);i++)
		{
			cout << left << setw(40) << "    " + names[i] << descriptions[i] << endl;
		}
		cout << endl;
	}
}