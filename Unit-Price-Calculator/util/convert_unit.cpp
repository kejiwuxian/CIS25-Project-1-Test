#include "supported_units.hpp"	// For units, conversion_rates

// Namespace for everything related to the units
namespace units
{
	// Convert one unit to another, an example use of default argument
	double convert_unit(const double weight, const units from, const units to)
	{
		return weight * conversion_rates[static_cast<int>(from)][static_cast<int>(to)];
	}
}