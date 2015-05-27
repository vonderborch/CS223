#include "common.h"

/*
 * Quadratic Maximum Contiguous Subsequence Sum Algorithm
*/

int maxSubSum2 (const vector<int> &a)
{
	int maxSum = 0;

	for (int i = 0; i < a.size(); i++)
	{
		int thisSum = 0;

		for (int j = i; j < a.size(); j++)
		{
			thisSum += a[j];

			if (thisSum > maxSum)
				maxSum = thisSum;
		}
	}

	return maxSum;
}

// Loads input file, runs maxSumSum2 algorithm on file contents, then outputs results to screen/output file.
void testMaxSubSum2 (int tests, string fileID)
{
	rTime cycleTime;
	vector<int> main;
	int totalTimeTaken = 0;

	string outputFile = "outputs/output_" + fileID + "_Algorithm2.txt";
	ofstream output;
	output.open (outputFile.c_str (), ios::out);

	cout << "ALGORITHM 2 (maxSubSum2) TEST" << endl << "Input Size (n):" << fileID << endl;
	output << "ALGORITHM 2 (maxSubSum2) TEST" << endl << "Input Size (n):" << fileID << endl;

	for (int i = 0; i < tests; i++)
	{
		int maxSum = 0, timeTaken = 0;
		string temp = toString(i);

		cout << "Testing on File " << fileID << "_" << i << endl;

		main = loadFile (fileID, temp);

		const vector<int> *working = &main;

		cycleTime.resetStartTime();
		maxSum = maxSubSum2(*working);
		timeTaken = cycleTime.getTimeElapsedMicro();
		totalTimeTaken += timeTaken;

		cout << "File: " << fileID << "_" << i << ", Max Sum: " << maxSum << ", Time Taken: " << timeTaken << " Microseconds" << endl << endl;
		output << "File: " << fileID << "_" << i << ", Max Sum: " << maxSum << ", Time Taken: " << timeTaken << " Microseconds" << endl << endl;
	}

	cout << "Average Time: " << totalTimeTaken / tests << " Microseconds" << endl;
	output << "Average Time: " << totalTimeTaken / tests << " Microseconds" << endl;

	output.close();
}