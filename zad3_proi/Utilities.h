#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>
#include <sstream>
#include <iostream>
#include <cstdlib>

class Utilities
{
public:
	static void putError(std::string error);
	static void putSuccess(std::string input);
	static void putWarning(std::string input);
	static void clear();
	static bool isInteger(std::string input);
	static bool containSpace(std::string input);
};

#endif