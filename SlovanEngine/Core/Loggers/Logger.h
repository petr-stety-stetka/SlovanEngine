#pragma once

#include "string"

class Logger
{
public:
	/** Print text as error */
	static void printError(std::string text);

	/** Print text as warning */
	static void printWarning(std::string text);

	/** Print text as info */
	static void printInfo(std::string text);
};
