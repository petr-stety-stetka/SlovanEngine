#include "../../ForUse/Loggers/FPSLogger.h"
#include "../../ForUse/Loggers/Logger.h"
#define ONE_NANOSECOND 1000000000

std::chrono::nanoseconds::rep FPSLogger::getActualTimeInNs()
{
    using namespace std::chrono;
    return duration_cast <nanoseconds>(high_resolution_clock::now().time_since_epoch()).count();
}

FPSLogger::FPSLogger()
{
    FPS = 0;
    previousTime = getActualTimeInNs();
}

int FPSLogger::getFPS()
{
    return FPS;
}

void FPSLogger::logFrame(std::string text)
{
    FPS++;
    if(getActualTimeInNs() - previousTime >= ONE_NANOSECOND)
    {
        Logger::printInfo(text + ": " + std::to_string(FPS));
        FPS = 0;
        previousTime = getActualTimeInNs();
    }
}