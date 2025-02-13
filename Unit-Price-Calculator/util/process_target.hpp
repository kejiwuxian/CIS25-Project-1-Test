#pragma once

#include <string>	// For string

#include "supported_currencies.hpp"	// For currencies
#include "supported_units.hpp"		// For units

// Namespace for everything related to user interaction
namespace user_interaction
{
	// Try to process user inputted target currency and unit
	bool process_target(std::string input, currencies::currencies& currency, units::units& unit);
}