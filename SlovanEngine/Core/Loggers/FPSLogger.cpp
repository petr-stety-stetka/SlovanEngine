#include "FPSLogger.h"
#include "Logger.h"

#define ONE_SECOND 1000000000

std::chrono::nanoseconds::rep FPSLogger::getActualTimeInNs()
{
	using namespace std::chrono;
	return duration_cast <nanoseconds>(high_resolution_clock::now().time_since_epoch()).count();
}

void FPSLogger::init() {
	previousTime = getActualTimeInNs();
}

FPSLogger::FPSLogger()
{
	FPS = 0;
	//previousTime = getActualTimeInNs();
}

int FPSLogger::getFPS()
{
	return FPS;
}

void FPSLogger::logFrame(std::string text)
{
	FPS++;
	if(getActualTimeInNs() - previousTime >= ONE_SECOND)
	{
		Logger::printInfo(text + ": " + std::to_string(FPS));
		FPS = 0;
		previousTime = getActualTimeInNs();
	}
}