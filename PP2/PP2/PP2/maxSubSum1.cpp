#include "common.h"

/*
 * Cubic Maximum Contiguous Subsequence Sum Algorithm
*/

int maxSubSum1 (const vector<int> &a)
{
	int maxSum = 0;

	for (int i = 0; i < a.size(); i++)
	{
		for (int j = i; j < a.size(); j++)
		{
			int thisSum = 0;

			for (int k = i; k <= j; k++)
				thisSum += a[k];

			if (thisSum > maxSum)
				maxSum = thisSum;
		}
	}

	return maxSum;
}

// Loads input file, runs maxSumSum1 algorithm on file contents, then outputs results to screen/output file.
void testMaxSubSum1 (int tests, string fileID)
{
	rTime cycleTime;
	vector<int> main;
	int totalTimeTaken = 0;

	string outputFile = "outputs/output_" + fileID + "_Algorithm1.txt";
	ofstream output;
	output.open (outputFile.c_str (), ios::out);

	cout << "ALGORITHM 1 (maxSubSum1) TEST" << endl << "Input Size (n):" << fileID << endl;
	output << "ALGORITHM 1 (maxSubSum1) TEST" << endl << "Input Size (n):" << fileID << endl;

	for (int i = 0; i < tests; i++)
	{
		int maxSum = 0, timeTaken = 0;
		string temp = toString(i);

		cout << "Testing on File " << fileID << "_" << i << endl;

		main = loadFile (fileID, temp);

		const vector<int> *working = &main;

		cycleTime.resetStartTime();
		maxSum = maxSubSum1(*working);
		timeTaken = cycleTime.getTimeElapsedMicro();
		totalTimeTaken += timeTaken;

		cout << "File: " << fileID << "_" << i << ", Max Sum: " << maxSum << ", Time Taken: " << timeTaken << " Microseconds" << endl << endl;
		output << "File: " << fileID << "_" << i << ", Max Sum: " << maxSum << ", Time Taken: " << timeTaken << " Microseconds" << endl << endl;
	}

	cout << "Average Time: " << totalTimeTaken / tests << " Microseconds" << endl;
	output << "Average Time: " << totalTimeTaken / tests << " Microseconds" << endl;

	output.close();
}