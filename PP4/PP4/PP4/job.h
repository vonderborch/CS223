#ifndef JOB
#define JOB

#include "pp4.h"

class Job {
	public:
		Job ();
		Job (int jid, string desc, int n_proc, int n_ticks);
		~Job ();

		bool operator<(const Job& j) const { return j.num_ticks > num_ticks; }

		int id;
		string description;
		int num_proc;
		int num_ticks;
	private:
};

#endif