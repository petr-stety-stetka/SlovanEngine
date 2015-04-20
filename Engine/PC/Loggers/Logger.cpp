#include <iostream>
#include "../../ForUse/Loggers/Logger.h"

void Logger::printError(std::string text)
{
    std::cerr << "ERROR:   " << text << ";" << "\n";
}

void Logger::printWarning(std::string text)
{
    std::cout << "WARNING: " << text << ";" << "\n";
}

void Logger::printInfo(std::string text)
{
    std::cout << "INFO:    " << text << ";" << "\n";
}