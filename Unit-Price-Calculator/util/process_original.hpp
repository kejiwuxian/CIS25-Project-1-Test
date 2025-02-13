#pragma once

#include <string>	// For string

#include "supported_currencies.hpp"	// For currencies
#include "supported_units.hpp"		// For units

// Namespace for everything related to user interaction
namespace user_interaction
{
	// Try to process user inputted original price and weight
	bool process_original(std::string input, double& price, currencies::currencies& currency, double& weight, units::units& unit);
}