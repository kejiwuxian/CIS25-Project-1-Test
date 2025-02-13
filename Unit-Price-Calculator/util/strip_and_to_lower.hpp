#pragma once

#include <string>	// For string

// Namespace for all utility functions
namespace util
{
	// Removes leading, and trailing whitespaces, \r and \n then convert to lowercase
	void strip_and_to_lower(std::string& str);
}