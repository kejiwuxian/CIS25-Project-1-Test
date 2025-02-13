#pragma once

#include <string>	// For string

// Namespace for everything related to the currencies
namespace currencies
{
	// Enum for the currencies, an example use of static_cast
	enum currencies
	{
		usd = 0,
		eur,
		gbp,
		cny,
		jpy
	};

	// A list of names for the currencies
	const std::string names[] = { "usd","eur","gbp","cny","jpy" };

	// A list of descriptions for the currencies
	const std::string descriptions[] = {
		"US Dollar",	// usd
		"Euro",			// eur
		"British Pound",// gbp
		"Chinese Yuan",	// cny
		"Japanese Yen"	// jpy
	};

	// Print all supported currencies, an example use of namespace
	void print_all();
}