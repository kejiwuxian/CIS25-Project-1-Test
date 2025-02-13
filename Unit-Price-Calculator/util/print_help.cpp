#include <iostream>	// For cout, endl
#include <iomanip>	// For left, setw

#include "supported_currencies.hpp"	// For currencies::print_all
#include "supported_units.hpp"		// For units::print_all

using namespace std;

// Namespace for everything related to user interaction
namespace user_interaction
{
	// Print the help message
	void print_help()
	{
		cout << "Calculate the unit price in different units and currencies." << endl << endl;
		cout << "Usage:" << endl;
		cout << "    unitprice [price]original_currency/[weight]original_unit target_currency/target_unit" << endl;
		cout << endl;
		cout << left << setw(40) << "    price" << "Optional original price in original_currency, needs to be a positive number" << endl;
		cout << left << setw(40) << "    original_currency" << "The original currency of [price], needs to be one of supported_currencies" << endl;
		cout << left << setw(40) << "    weight" << "Optional original weight in original_unit, needs to be a positive number" << endl;
		cout << left << setw(40) << "    original_unit" << "The original unit of [weight], needs to be one of supported_units" << endl;
		cout << left << setw(40) << "    target_currency" << "The target currency of the unit price, needs to be one of supported_currencies" << endl;
		cout << left << setw(40) << "    target_unit" << "The target unit of the unit price, needs to be one of supported_units" << endl;
		cout << endl;
		cout << "Examples:" << endl;
		cout << left << setw(40) << "    unitprice 4.99USD/1LB EUR/KG" << "How much euros per kilogram of a product that costs $4.99 per pound is worth" << endl;
		cout << left << setw(40) << "    unitprice 1usd/2.5oz eur/g" << "How much euros per gram of a product that costs $1 per 2.5 ounces is worth" << endl;
		cout << left << setw(40) << "    unitprice uSd/JiN eUr/kG" << "How much euros per kilogram of a product that costs $1 per pound is worth" << endl;
		cout << endl;
		// An example use of namespace
		currencies::print_all();
		units::print_all();
	}
}