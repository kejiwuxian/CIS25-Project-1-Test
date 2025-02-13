#include <iostream>	// For cout, endl
#include <iomanip>	// For left, setw

#include "supported_currencies.hpp"	// For names, descriptions

using namespace std;

namespace currencies
{
	void print_all()
	{
		cout << "SUPPORTED_CURRENCIES:" << endl;
		for (int i = 0;i < size(names);i++)
		{
			cout << left << setw(40) << "    " + names[i] << descriptions[i] << endl;
		}
		cout << endl;
	}
}