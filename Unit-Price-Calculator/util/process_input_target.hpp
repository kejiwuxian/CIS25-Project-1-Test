#pragma once

#include <string>	// For string

#include "currencies_enum.hpp"	// For currencies::currencies
#include "units_enum.hpp"		// For units::units

// Namespace for everything related to user interaction
namespace user_interaction
{
	// Try to process user inputted target currency and unit
	bool process_input(std::string input, currencies::currencies& currency, units::units& unit);
}