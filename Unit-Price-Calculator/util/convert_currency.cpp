#include "supported_currencies.hpp"	// For currencies
#include "get_exchange_rate.hpp"	// For get_exchange_rate

// Namespace for everything related to the currencies
namespace currencies
{
	// Convert one currency to another, an example use of default argument
	double convert_currency(const double weight, const currencies from, const currencies to)
	{
		return weight * get_exchange_rate(from, to);
	}
}