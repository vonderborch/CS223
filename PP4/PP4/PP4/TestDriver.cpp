#include "TestDriver.h"

void testCluster ()
{
	Scheduler dasSchedule(20);
	string inputFile = "test.txt";
	ifstream input;
	input.open (inputFile.c_str (), ios::in);
	bool isTesting = true;

	while (isTesting)
	{
		string desc = "NULL";
		int procs = -1, ticks = -1;
		if (!input.eof())
		{
			input >> desc >> procs >> ticks;
		}

		isTesting = !dasSchedule.Tick(desc, procs, ticks);
	}

	input.close();
	system("pause");
}