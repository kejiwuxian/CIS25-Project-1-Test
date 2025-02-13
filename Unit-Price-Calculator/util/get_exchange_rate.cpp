#include <string>	// For string, 
#include <stdexcept>// For runtime_error

#ifdef _WIN32 // Windows MSVC
#include <windows.h>// For _popen, _pclose
#define popen _popen
#define pclose _pclose
#else // Linux, MacOS
#include <stdio.h>	// For popen, pclose
#endif

#include "supported_currencies.hpp"	// For currencies, names

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
		char* buf = static_cast<char*>(malloc(1024));

		string cmd = "curl -s \"https://latest.currency-api.pages.dev/v1/currencies/" + from_currency + ".min.json\"";
		FILE* pipe = popen(cmd.c_str(), "r");
		string res;

		if (!pipe)
		{
			throw runtime_error("Error: Failed to execute curl command, please make sure curl is installed and added to path");
		}

		if (!buf)
		{
			throw runtime_error("Error: Failed to allocate memory, please make sure your system have enough aviliable RAM");
		}

		while (fgets(buf, 1024, pipe) != nullptr)
		{
			res += buf;
		}
		pclose(pipe);

		if (res.length() == 0)
		{
			throw runtime_error("Error: Failed to fetch exchange rate, please check your internet connection");
		}

		size_t s = res.find("\"" + to_currency + "\":");
		s += to_currency.length() + 3;
		size_t e = res.find(",", s);
		return stod(res.substr(s, e - s));
	}
}