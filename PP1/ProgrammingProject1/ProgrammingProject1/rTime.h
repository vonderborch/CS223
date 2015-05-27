#ifndef RTIME
#define RTIME

#include <time.h>

class rTime {
	public:
		rTime ();
		~rTime ();

		void init ();

		void resetStartTime (void);
		float returnStartTimeMilli (void);
		float getTimeElapsedMili (void);
		float returnStartTicks (void);
		float getTicksElapsed (void);

	private:
		float startTime;
};

#endif