#include <string>	// For string, 
#include <stdexcept>// For runtime_error

#ifdef _WIN32 // Windows MSVC
#include <windows.h>// For _popen, _pclose
#define popen _popen
#define pclose _pclose
#else // Linux, MacOS
#include <stdio.h>	// For popen, pclose
#endif

#include "util/currencies_enum.hpp"	// For currencies::currencies
#include "util/currencies_names.hpp"	// For currencies::names

using namespace std;

// Namespace for everything related to the currencies
namespace currencies
{
	// Get the exchange rate between two currencies by calling an API, an example use of advanced features
	double get_exchange_rate(const currencies from, const currencies to)
	{
		// Example use of static_cast
		string from_currency = names[static_cast<int>(from)];
		string to_currency = names[static_cast<int>(to)];
		char* buf = static_cast<char*>(malloc(1024));		// Dynamically allocate memory and use it as a buffer of char type

		if (!buf)
		{
			throw runtime_error("Error: Failed to allocate memory, please make sure your system have enough aviliable RAM");
		}

		string cmd = "curl -s \"https://latest.currency-api.pages.dev/v1/currencies/" + from_currency + ".min.json\"";
		FILE* pipe = popen(cmd.c_str(), "r");				// Execute curl to fetch data from the API

		if (!pipe)
		{
			throw runtime_error("Error: Failed to execute curl command, please make sure curl is installed and added to PATH");
		}

		string res;
		while (fgets(buf, 1024, pipe) != nullptr)			// Read the output of curl until it is empty
		{
			res += buf;
		}
		free(static_cast<void*>(buf));						// Release dynamically allocated memory
		pclose(pipe);

		if (res.length() == 0)
		{
			throw runtime_error("Error: Failed to fetch exchange rate, please check your internet connection");
		}

		try
		{
			size_t s = res.find("\"" + to_currency + "\":");// Find the start of name/value pairs
			s += to_currency.length() + 3;					// Skip the name
			size_t e = res.find(",", s);					// Find the end of the name/value pairs
			return stod(res.substr(s, e - s));				// Convert the value to double
		}
		catch (exception)
		{
			throw runtime_error("Error: Failed to process fetched exchange rate");
		}
	}
}