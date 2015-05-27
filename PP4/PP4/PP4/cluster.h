#ifndef CLUSTER
#define CLUSTER

#include "pp4.h"
#include "job.h"

class Cluster {
	public:
		Cluster ();
		Cluster (int p);
		~Cluster ();

		bool isWaiting();
		bool isRunning();
		int getLast();

		bool InsertJob(string desc, int n_proc, int n_ticks);
		Job FindShortest();
		bool CheckAvailability(int p);
		void DeleteShortest();
		void RunJob(int id, string desc, int n_proc, int n_ticks);
		void DecrementTimer();
		void ReleaseProcessors();

	private:
		priority_queue<Job> waiting;
		list<Job> running;
		int processors;
		int maxprocessors;
		int lastid;
};

#endif