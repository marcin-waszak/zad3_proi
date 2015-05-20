#include "Utilities.h"

void Utilities::putError(std::string error)
{
#ifdef _WIN32
	std::cout << error << std::endl;
#elif __linux__
	// ANSI escape code for color only on Linux
	std::cout << "\x1b[31m" << error << "\x1b[0m" << std::endl;
#endif
}

void Utilities::putSuccess(std::string input)
{
#ifdef _WIN32
	std::cout << input << std::endl;
#elif __linux__
	// ANSI escape code for color only on Linux
	std::cout << "\x1b[0;32m" << input << "\x1b[0m" << std::endl;
#endif
}

void Utilities::putWarning(std::string input)
{
#ifdef _WIN32
	std::cout << input << std::endl;
#elif __linux__
	// ANSI escape code for color only on Linux
	std::cout << "\x1b[33m" << input << "\x1b[0m" << std::endl;
#endif
}

void Utilities::clear()
{
#ifdef _WIN32
	system("cls");
#elif __linux__
	system("clear");
#endif	
}

bool Utilities::isInteger(std::string input)
{
	for(auto it : input)
		if(!isdigit(it))
			return false;
	return true;
}

bool Utilities::containSpace(std::string input)
{
	for(auto it : input)
	{
		if(isspace(it))
			return true;
	}
	return false;
}