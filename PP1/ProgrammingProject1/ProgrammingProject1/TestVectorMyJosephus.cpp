#include "pa1.h"

// test the vector implementation with the values provided from the main menu and do the number of tests, changes to
//			N and M as needed. Also display all output on screen.
void testVectorOutput (int N, int M, int nPower, int mPower, int numTests, string outputFile)
{
	rTime gameTime, roundTime;
	float numMilliSeconds = 0.0f;
	int i = 1, j = 0, baseN = N, baseM = M;
	ofstream output;
	output.open (outputFile.c_str (), ios::out);

	cout << "STARTING JOSEPHUS VECTOR GAME TESTING...\n";
	output << "STARTING JOSEPHUS VECTOR GAME TESTING...\n";
	for (i = 1; i <= numTests; i++)
	{
		cout << "TEST GAME " << i << "\n";
		output << "TEST GAME " << i << "\n";
		cout << "N: " << N << ", M: " << M << "\n";
		output << "N: " << N << ", M: " << M << "\n";
		gameTime.resetStartTime ();
		j = 0;
		numMilliSeconds = 0;

		N = getIntPower (baseN, nPower, i);
		M = getIntPower (baseM, mPower, i);

		cout << "N = " << N << ", M = " << M << "\n\n";
		VectorMyJosephus vectorTestCircle (N, M);
		int k = 0;

		while (vectorTestCircle.currentSize () != 1)
		{
			roundTime.resetStartTime ();
			j++;
			cout << "Round " << j << "\n";
			k = vectorTestCircle.eliminateNext (k);
			vectorTestCircle.printAll ();
			numMilliSeconds += roundTime.getTimeElapsedMili ();
		}
		cout << "Game Winner: " << vectorTestCircle.returnWinner () << "\n";
		cout << "Time of Game: " << (float)(gameTime.getTimeElapsedMili ()) << " Millisecond(s)\n";
		cout << "Average Round Time: " << (float)(numMilliSeconds / (float)j) << " Millisecond(s)\n";
		output << "Game Winner: " << vectorTestCircle.returnWinner () << "\n";
		output << "Time of Game: " << (float)(gameTime.getTimeElapsedMili ()) << " Millisecond(s)\n";
		output << "Average Round Time: " << (float)(numMilliSeconds / (float)j) << " Millisecond(s)\n\n";
		system ("pause");
	}
	cout << "TESTING COMPLETE!\n";
	output << "TESTING COMPLETE!\n";
	output.close ();
}

// test the vector implementation with the values provided from the main menu and do the number of tests, changes to
//			N and M as needed. Also don't display all output on screen.
void testVectorNoOutput (int N, int M, int nPower, int mPower, int numTests, string outputFile)
{
	rTime gameTime, roundTime;
	float numMilliSeconds = 0.0f;
	int i = 1, j = 0, baseN = N, baseM = M;
	ofstream output;
	output.open (outputFile.c_str (), ios::out);

	cout << "STARTING JOSEPHUS VECTOR GAME TESTING...\n";
	output << "STARTING JOSEPHUS VECTOR GAME TESTING...\n";
	for (i = 1; i <= numTests; i++)
	{
		output << "TEST GAME " << i << "\n";
		output << "N: " << N << ", M: " << M << "\n";
		gameTime.resetStartTime ();
		j = 0;
		numMilliSeconds = 0;

		N = getIntPower (baseN, nPower, i);
		M = getIntPower (baseM, mPower, i);

		VectorMyJosephus vectorTestCircle (N, M);
		int k = 0;

		while (vectorTestCircle.currentSize () != 1)
		{
			roundTime.resetStartTime ();
			j++;
			k = vectorTestCircle.eliminateNext (k);
			numMilliSeconds += roundTime.getTimeElapsedMili ();
		}
		output << "Game Winner: " << vectorTestCircle.returnWinner () << "\n";
		output << "Time of Game: " << (gameTime.getTimeElapsedMili ()) << " Millisecond(s)\n";
		output << "Average Round Time: " << (numMilliSeconds / (float)j) << " Millisecond(s)\n\n";
		cout << ".";
	}
	cout << "TESTING COMPLETE!\n";
	output << "TESTING COMPLETE!\n";
	output.close ();
}