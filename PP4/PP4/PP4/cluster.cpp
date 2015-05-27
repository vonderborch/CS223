#include "cluster.h"

Cluster::Cluster ()
{
	this->lastid = 0;
	this->processors = 1;
	this->maxprocessors = 1;
}

Cluster::Cluster (int p)
{
	this->lastid = 0;
	this->processors = p;
	this->maxprocessors = p;
}

Cluster::~Cluster ()
{
}

// is there a waiting queue?
bool Cluster::isWaiting()
{
	return !this->waiting.empty();
}

// is there a running queue?
bool Cluster::isRunning()
{
	return !this->running.empty();
}

// what was the last job added?
int Cluster::getLast()
{
	return this->lastid;
}

// insert a job if it's good or spit out a error message
bool Cluster::InsertJob(string desc, int n_proc, int n_ticks)
{
	bool isGood = false;
	if (n_proc > 0 && n_proc <= this->maxprocessors)
	{
		if (n_ticks > 0)
		{
			this->waiting.push(Job (this->lastid, desc, n_proc, n_ticks));
			this->lastid++;
		}
		else
		{
			cout << "Insertion Error: Too few ticks.\n";
		}
	}
	else
	{
		isGood = false;
		cout << "Insertion Error: Too many processes needed or less than 0.\n";
	}
	return isGood;
}

// find the shortest job if the queue isn't empty
Job Cluster::FindShortest()
{
	Job temp = Job (-1, "NULL", -1, -1);

	if (!this->waiting.empty())
	{
		temp = this->waiting.top();
	}

	return temp;
}

// check if enough processors are available
bool Cluster::CheckAvailability(int p)
{
	bool isGood = false;
	if (p <= this->processors)
		isGood = true;
	return isGood;
}

// remove top job
void Cluster::DeleteShortest()
{
	this->waiting.pop();
}

// add a job to the running queue
void Cluster::RunJob(int id, string desc, int n_proc, int n_ticks)
{
	this->processors -= n_proc;
	this->running.push_back (Job (id, desc, n_proc, n_ticks));
}

// decrement timers on all jobs
void Cluster::DecrementTimer()
{
  list<Job>::iterator it;

  for ( it=running.begin() ; it != running.end(); it++ )
	  it->num_ticks--;
}

// release processors (really bad algorithm for making not crash)
void Cluster::ReleaseProcessors()
{
  list<Job>::iterator it;
  bool isReleasing = true;

  while (isReleasing)
  {
	  for ( it=running.begin() ; it != running.end(); it++ )
	  {
		  if (it->num_ticks < 1)
		  {
			  cout << "Removed Job #" << it->id + 1 << " (" << it->description << ", " << it->num_proc << ", " 
					<< it->num_ticks << ") from running queue.\n";
			  this->processors += it->num_proc;
			  running.erase(it);
			  if (!running.empty())
				  it = running.begin();
			  else
				  break;
		  }
	  }
	  isReleasing = false;
  }
}