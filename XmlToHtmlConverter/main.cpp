#include <fstream>
#include <iostream>
#include <string>
#include "Xml2HtmlUtil.h"

// Main function call
int main(int argc, char* argv[]) noexcept
{
	try {
		if (argc != 2)
		{
			// Excetion thrown if num of args is not equal to 2
			throw std::invalid_argument("Only one argument must be passed.");
		}

		const std::string filename = (const char*)argv[1]; ;
		Xml2HtmlUtil converter(filename);
		converter.RunEngine();
		return 0;
	}
	catch (std::invalid_argument const& e)
	{
		std::cout << "Exception: Invalid number of arguments." << e.what() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	return 1;
}