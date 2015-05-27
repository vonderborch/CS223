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
	this->startTime = clock ();
}

// reset the start time value to current clock.
void rTime::resetStartTime (void)
{
	init ();
}

// return the number of milliseconds of the start time.
float rTime::returnStartTimeMilli (void)
{
	return (this->startTime / (CLOCKS_PER_SEC / 1000));
}

// return the time elapsed since the start time in milliseconds
float rTime::getTimeElapsedMili (void)
{
	return ((clock () - this->startTime) / (CLOCKS_PER_SEC / 1000));
}

// return the number of ticks of the start time.
float rTime::returnStartTicks (void)
{
	return this->startTime;
}
// return the time elapsed since the start time in ticks
float rTime::getTicksElapsed (void)
{
	return (clock () - this->startTime);
}