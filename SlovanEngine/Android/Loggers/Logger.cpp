#include "../../Core/Loggers/Logger.h"
#include <android/log.h>

void Logger::printError(std::string text) {
	__android_log_print(ANDROID_LOG_ERROR, "ERROR:   ", "%s", text.c_str());
}

void Logger::printWarning(std::string text) {
	__android_log_print(ANDROID_LOG_INFO, "WARNING: ", "%s", text.c_str());
}

void Logger::printInfo(std::string text) {
	__android_log_print(ANDROID_LOG_INFO, "INFO:    ", "%s", text.c_str());
}
