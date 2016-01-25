#pragma once

#include <chrono>
#include <string>

/**
 * Counter frames per second.
 */
class FPSLogger
{
private:

	/** Frames Per Second */
	int FPS;

	/** Time at the end of the previous loop */
	std::chrono::nanoseconds::rep previousTime;

	/** Return actual time in nanoseconds */
	std::chrono::nanoseconds::rep getActualTimeInNs();

public:

	FPSLogger();

	void init();

	/** Write (log) number frames (FPS) with specific text */
	void logFrame(std::string text);

	/** Return number frames per second */
	int getFPS();
};