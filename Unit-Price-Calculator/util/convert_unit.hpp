#pragma once

#include "supported_units.hpp"	// For units

// Namespace for everything related to the units
namespace units
{
	// Convert one unit to another, an example use of default argument
	double convert_unit(const double weight, const units from, const units to = units::lb);
}