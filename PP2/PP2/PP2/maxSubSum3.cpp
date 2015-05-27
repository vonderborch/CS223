#include "common.h"

/*
 * Recursive Maximum Contiguous Subsequence Sum Algorithm
 * Finds maximum sum in subarray spanning a[left..right].
 * Does not attempt to maintain actual best sequence.
*/

int maxSubSum3 (const vector<int> &a)
{
	return maxSumRec (a, 0, a.size() - 1);
}

// recursive step of algorithm
int maxSumRec (const vector<int> &a, int left, int right)
{
	if (left == right) // base case
	{
		if (a[left] > 0)
			return a[left];
		else
			return 0;
	}

	int center = (left + right) / 2;
	int maxLeftSum = maxSumRec (a, left, center);
	int maxRightSum = maxSumRec (a, center + 1, right);

	int maxLeftBorderSum = 0, leftBorderSum = 0;
	for (int i = center; i >= left; i--)
	{
		leftBorderSum += a[i];
		if (leftBorderSum > maxLeftBorderSum)
			maxLeftBorderSum = leftBorderSum;
	}

	int maxRightBorderSum = 0, rightBorderSum = 0;
	for (int j = center + 1; j <= right; j++)
	{
		rightBorderSum += a[j];
		if (rightBorderSum > maxRightBorderSum)
			maxRightBorderSum = rightBorderSum;
	}

	return max3 (maxLeftSum, maxRightSum, maxLeftBorderSum + maxRightBorderSum);
}

// Returns the largest of three inputted sums
int max3 (int maxLeftSum, int maxRightSum, int maxBorderSum)
{
	int maxNum = maxLeftSum;

	if (maxRightSum > maxNum)
		maxNum = maxRightSum;

	if (maxBorderSum > maxNum)
		maxNum = maxBorderSum;

	return maxNum;
}

// Loads input file, runs maxSumSum3 algorithm on file contents, then outputs results to screen/output file.
void testMaxSubSum3 (int tests, string fileID)
{
	rTime cycleTime;
	vector<int> main;
	int totalTimeTaken = 0;

	string outputFile = "outputs/output_" + fileID + "_Algorithm3.txt";
	ofstream output;
	output.open (outputFile.c_str (), ios::out);

	cout << "ALGORITHM 3 (maxSubSum3) TEST" << endl << "Input Size (n):" << fileID << endl;
	output << "ALGORITHM 3 (maxSubSum3) TEST" << endl << "Input Size (n):" << fileID << endl;

	for (int i = 0; i < tests; i++)
	{
		int maxSum = 0, timeTaken = 0;
		string temp = toString(i);

		cout << "Testing on File " << fileID << "_" << i << endl;

		main = loadFile (fileID, temp);

		const vector<int> *working = &main;

		cycleTime.resetStartTime();
		maxSum = maxSubSum3(*working);
		timeTaken = cycleTime.getTimeElapsedMicro();
		totalTimeTaken += timeTaken;

		cout << "File: " << fileID << "_" << i << ", Max Sum: " << maxSum << ", Time Taken: " << timeTaken << " Microseconds" << endl << endl;
		output << "File: " << fileID << "_" << i << ", Max Sum: " << maxSum << ", Time Taken: " << timeTaken << " Microseconds" << endl << endl;
	}

	cout << "Average Time: " << totalTimeTaken / tests << " Microseconds" << endl;
	output << "Average Time: " << totalTimeTaken / tests << " Microseconds" << endl;

	output.close();
}