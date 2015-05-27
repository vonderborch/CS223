#include "common.h"

/*
 * Linear-time Maximum Contiguous Subsequence Sum Algorithm
*/

int maxSubSum4 (const vector<int> &a)
{
	int maxSum = 0, thisSum = 0;

	for (int j = 0; j < a.size(); j++)
	{
				thisSum += a[j];

			if (thisSum > maxSum)
				maxSum = thisSum;
			else if (thisSum < 0)
				thisSum = 0;
	}

	return maxSum;
}

// Loads input file, runs maxSumSum4 algorithm on file contents, then outputs results to screen/output file.
void testMaxSubSum4 (int tests, string fileID)
{
	rTime cycleTime;
	vector<int> main;
	int totalTimeTaken = 0;

	string outputFile = "outputs/output_" + fileID + "_Algorithm4.txt";
	ofstream output;
	output.open (outputFile.c_str (), ios::out);

	cout << "ALGORITHM 4 (maxSubSum4) TEST" << endl << "Input Size (n):" << fileID << endl;
	output << "ALGORITHM 4 (maxSubSum4) TEST" << endl << "Input Size (n):" << fileID << endl;

	for (int i = 0; i < tests; i++)
	{
		int maxSum = 0, timeTaken = 0;
		string temp = toString(i);

		cout << "Testing on File " << fileID << "_" << i << endl;

		main = loadFile (fileID, temp);

		const vector<int> *working = &main;

		cycleTime.resetStartTime();
		maxSum = maxSubSum4(*working);
		timeTaken = cycleTime.getTimeElapsedMicro();
		totalTimeTaken += timeTaken;

		cout << "File: " << fileID << "_" << i << ", Max Sum: " << maxSum << ", Time Taken: " << timeTaken << " Microseconds" << endl << endl;
		output << "File: " << fileID << "_" << i << ", Max Sum: " << maxSum << ", Time Taken: " << timeTaken << " Microseconds" << endl << endl;
	}

	cout << "Average Time: " << totalTimeTaken / tests << " Microseconds" << endl;
	output << "Average Time: " << totalTimeTaken / tests << " Microseconds" << endl;

	output.close();
}