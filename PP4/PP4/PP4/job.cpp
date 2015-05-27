#include "job.h"

Job::Job ()
{
}

Job::Job (int jid, string desc, int n_proc, int n_ticks)
{
	this->id = jid;
	this->description = desc;
	this->num_proc = n_proc;
	this->num_ticks = n_ticks;
}

Job::~Job ()
{
}