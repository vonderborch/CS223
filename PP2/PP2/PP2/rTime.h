#ifndef RTIME
#define RTIME

#include <windows.h>

class rTime {
	public:
		rTime ();
		~rTime ();

		void init ();

		void resetStartTime (void);
		int returnStartTimeMicro (void);
		int getTimeElapsedMicro (void);
		int returnStartTimeMilli (void);
		int getTimeElapsedMili (void);
		int returnStartTicks (void);
		int getTicksElapsed (void);

	private:
		LARGE_INTEGER startTime;
		LARGE_INTEGER ticksPerSecond;
		static const int MILLITOSECONDS = 1000;
		static const int MICROTOSECONDS = 1000000;
};

#endif