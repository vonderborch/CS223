#include "rTime.h"

// constructor
rTime::rTime ()
{
	init ();
}

// destructor
rTime::~rTime ()
{
}

// initialize start time value to current clock.
void rTime::init ()
{
	QueryPerformanceFrequency(&this->ticksPerSecond);
	QueryPerformanceCounter(&this->startTime);
}

// reset the start time value to current clock.
void rTime::resetStartTime (void)
{
	init ();
}

// return the number of microseconds of the start time.
int rTime::returnStartTimeMicro (void)
{
	return (this->startTime.QuadPart / (ticksPerSecond.QuadPart / MICROTOSECONDS));
}

// return the time elapsed since the start time in microseconds
int rTime::getTimeElapsedMicro (void)
{
	LARGE_INTEGER temp;
	QueryPerformanceCounter(&temp);
	return ((temp.QuadPart - this->startTime.QuadPart) / (ticksPerSecond.QuadPart / MICROTOSECONDS));
}

// return the number of milliseconds of the start time.
int rTime::returnStartTimeMilli (void)
{
	return (this->startTime.QuadPart / (ticksPerSecond.QuadPart / MILLITOSECONDS));
}

// return the time elapsed since the start time in milliseconds
int rTime::getTimeElapsedMili (void)
{
	LARGE_INTEGER temp;
	QueryPerformanceCounter(&temp);
	return ((temp.QuadPart - this->startTime.QuadPart) / (ticksPerSecond.QuadPart / MILLITOSECONDS));
}

// return the number of ticks of the start time.
int rTime::returnStartTicks (void)
{
	return this->startTime.QuadPart;
}
// return the time elapsed since the start time in ticks
int rTime::getTicksElapsed (void)
{
	LARGE_INTEGER temp;
	QueryPerformanceCounter(&temp);
	return (temp.QuadPart - this->startTime.QuadPart);
}