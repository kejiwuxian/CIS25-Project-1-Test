#include <iostream>
#include <iomanip>

using namespace std;

namespace user_interaction
{
	void print_help()
	{
		cout << "Calculate the unit price in different units and currencies." << endl << endl;
		cout << "Usage:" << endl;
		cout << "    unitprice [PRICE][ORIGINAL_CURRENCY]/[WEIGHT][ORIGINAL_UNIT] [TARGET_CURRENCY]/[TARGET_UNIT]" << endl;
		cout << endl;
		cout << left << setw(40) << "    PRICE" << "The original price in ORIGINAL_CURRENCY, needs to be a positive number" << endl;
		cout << left << setw(40) << "    ORIGINAL_CURRENCY" << "The original currency of PRICE, needs to be one of SUPPORTED_CURRENCIES" << endl;
		cout << left << setw(40) << "    WEIGHT" << "The original weight in ORIGINAL_UNIT, needs to be a positive number" << endl;
		cout << left << setw(40) << "    ORIGINAL_UNIT" << "The original unit of WEIGHT, needs to be one of SUPPORTED_UNITS" << endl;
		cout << left << setw(40) << "    TARGET_CURRENCY" << "The target currency of the unit price, needs to be one of SUPPORTED_CURRENCIES" << endl;
		cout << left << setw(40) << "    TARGET_UNIT" << "The target unit of the unit price, needs to be one of SUPPORTED_UNITS" << endl;
		cout << endl;
		cout << "Examples:" << endl;
		cout << left << setw(40) << "    unitprice 4.99USD/1LB EUR/KG" << "How much euros per kilogram of a product that costs $4.99 per pound is worth" << endl;
		cout << left << setw(40) << "    unitprice 1usd/2.5oz eur/g" << "How much euros per gram of a product that costs $1 per 2.5 ounces is worth" << endl;
		cout << endl;
		cout << "SUPPORTED_UNITS:" << endl;
		cout << endl;
		cout << "SUPPORTED_CURRENCIES:" << endl;
		cout << endl;
	}
}