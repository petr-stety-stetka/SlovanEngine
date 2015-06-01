#include <iostream>
#include "../../Core/Loggers/Logger.h"

void Logger::printError(std::string text)
{
	std::string error("ERROR:   " + text + ";\n");
	std::cerr << error;
}

void Logger::printWarning(std::string text)
{
	std::string warning("WARNING: " + text + ";\n");
	std::cout << warning;
}

void Logger::printInfo(std::string text)
{
	std::string info("INFO:    " + text + ";\n");
	std::cout << info;
}