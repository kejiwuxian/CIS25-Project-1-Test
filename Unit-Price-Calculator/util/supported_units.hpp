#pragma once

#include <string>	// For string

// Namespace for everything related to the units
namespace units
{
	// Enum for the units, an example use of static_cast
	enum units
	{
		oz = 0,
		lb,
		kg,
		jin,
		g
	};

	// A list of names for the units, an example use of array
	const std::string names[] = { "oz","lb","kg","jin","g" };

	// A list of descriptions for the units, an example use of array
	const std::string descriptions[] =
	{
		"Ounce (US weight unit)",		// oz
		"Pound (US weight unit)",		// lb
		"Kilogram (metric weight unit)",// kg
		"Jin (Chinese weight unit)",	// jin
		"Gram (metric weight unit)"		// g
	};

	// A table of conversion rates for the units (With the help from DeepSeek R1), an example use of 2D array
	const double conversion_rates[5][5] =
	{
		// to oz          lb           kg              jin            g                    from
			{ 1.0,        0.0625,      0.028349523125, 0.05669904625, 28.349523125 },	// oz
			{ 16.0,       1.0,         0.45359237,     0.90718474,    453.59237 },		// lb
			{ 35.27396195,2.20462262,  1.0,            2.0,           1000.0 },			// kg
			{ 17.63698097,1.10231131,  0.5,            1.0,           500.0 },			// jin
			{ 0.03527396, 0.002204622, 0.001,          0.002,         1.0 }				// g
	};

	// Print all supported units, an example use of namespace
	void print_all();
}