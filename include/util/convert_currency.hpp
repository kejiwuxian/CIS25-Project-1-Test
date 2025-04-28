#pragma once

#include "currencies_enum.hpp"	// For currencies::currencies

// Namespace for everything related to the currencies
namespace currencies
{
	// Convert one currency to another, an example use of default argument
	double convert_currency(const double value, const currencies from, const currencies to = currencies::usd);
}