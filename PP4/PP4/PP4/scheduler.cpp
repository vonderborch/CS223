#include "scheduler.h"

Scheduler::Scheduler ()
{
	this->curr_tick = 0;
	this->comp = Cluster (10);
}

Scheduler::Scheduler (int p)
{
	this->curr_tick = 0;
	this->comp = Cluster (p);
}

Scheduler::~Scheduler ()
{
}

// runs a full scheduler tick
bool Scheduler::Tick(string desc, int procs, int ticks)
{
	bool isFinal = false;
	this->curr_tick++;
	cout << "CURRENT TICK: " << curr_tick << endl;

	// Event 1
	if (desc == "exit" || desc == "EXIT")
		isFinal = true;
	if (desc != "NULL" && isFinal == false)
	{
		bool good = this->comp.InsertJob(desc, procs, ticks);
		if (good)
			cout << "Added Job #" << comp.getLast() << " (" << desc << ", " << procs << ", " << ticks << ") to waiting queue.\n";
	}

	// Event 2
	if (this->comp.isWaiting())
	{
		bool isChecking = true;
		
		while (isChecking)
		{
			Job temp = this->comp.FindShortest();

			if (temp.id != -1)
			{
				if (this->comp.CheckAvailability(temp.num_proc))
				{
					cout << "Added Job #" << temp.id + 1 << " (" << temp.description << ", " << temp.num_proc << ", " 
						<< temp.num_ticks << ") to running queue.\n";
					this->comp.RunJob(temp.id, temp.description, temp.num_proc, temp.num_ticks);
					this->comp.DeleteShortest();
				}
				else
				{
					isChecking = false;
				}
			}
			else
			{
				isChecking = false;
			}
		}
	}

	// Event 3 & 4
	if (this->comp.isRunning())
	{
		this->comp.DecrementTimer();
		this->comp.ReleaseProcessors();
	}
	else
	{
		isFinal = true;
	}
	return isFinal;
}