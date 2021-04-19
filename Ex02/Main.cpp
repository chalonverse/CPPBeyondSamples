#include <iostream>
// These headers only exist in C++17
#include <filesystem>

int main()
{
	// Shortcut so we don't have to type out std::filesystem every time
	namespace fs = std::filesystem;

	// Get the size of a file (throws an exception if it doesn't exist)
	try
	{
		auto fileSize = fs::file_size("CMakeLists.txt");
		std::cout << "Size = " << fileSize << "\n";
	}
	catch (fs::filesystem_error& e)
	{
		std::cout << "Error from filesystem: " << e.what() << "\n";
	}

	try
	{
		auto fileSize = fs::file_size("asdf");
		std::cout << "Size = " << fileSize << "\n";
	}
	catch (fs::filesystem_error& e)
	{
		std::cout << "Error from filesystem: " << e.what() << "\n";
	}

	// Many filesystem functions instead support an alternative syntax which takes in an error code
	{
		std::error_code ec;
		auto fileSize = fs::file_size("asdf", ec);
		
		// A default error code means it's ok
		if (ec == std::error_code{})
		{
			std::cout << "Size = " << fileSize << "\n";
		}
		else
		{
			std::cout << "Error from filesystem: " << ec.message() << "\n";
		}
	}

	// Get a path to a single file
	{
		fs::path pathTest("CMakeLists.txt");

		// Does this file exist?
		if (fs::exists(pathTest))
		{
			std::cout << "File exists\n";
		}
		else
		{
			std::cout << "File does not exist\n";
		}
	}

	// Iterate over all files in a directory
	for (const auto& p : fs::directory_iterator("."))
	{
		std::cout << p.path() << "\n";
	}
	return 0;
}
