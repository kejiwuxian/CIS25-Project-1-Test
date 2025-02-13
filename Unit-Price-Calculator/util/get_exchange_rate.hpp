#pragma once

#include "supported_currencies.hpp"	// For currencies

// Namespace for everything related to the currencies
namespace currencies
{
	// Get the exchange rate between two currencies by calling an API, an example use of advanced features
	double get_exchange_rate(const currencies from, const currencies to);
}