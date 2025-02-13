#pragma once

#include "supported_currencies.hpp"	// For currencies

// Namespace for everything related to the currencies
namespace currencies
{
	// Convert one currency to another, an example use of default argument
	double convert_currency(const double weight, const currencies from, const currencies to = currencies::usd);
}