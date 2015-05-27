#ifndef SCHEDULER
#define SCHEDULER

#include "pp4.h"
#include "cluster.h"

class Scheduler {
	public:
		Scheduler ();
		Scheduler (int p);
		~Scheduler ();

		bool Tick(string desc, int procs, int ticks);

	private:
		Cluster comp;
		int curr_tick;
};

#endif