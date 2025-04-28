// Export a module with the ModuleTest name
export module ModuleTest;

// Import any required other modules here
// import std is STILL experimental so just include instead
// import std.iostream;
// import std.string;
#include <iostream>
#include <string>

// Everything need to be in the module namespace
namespace ModuleTest
{
	// Functions without export cannot be used externally
	void OutputHelper(const std::string& s)
	{
		std::cout << s << "\n";
	}

	// Functions / classes with export can be used externally
	export void TryTestOutput(const std::string& s)
	{
		OutputHelper(s);
	}
}
