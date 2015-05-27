#include "pa1.h"

// Displays two menus, one at the beginning asking what type of output to make and then the main menu, allowing the
//		user to run either implementation and change what values to use for M and N, the powers of each to increase by,
//		the number of tests to run, and the output file to output to
int main (void)
{
	int prog_state = 0, option = 0, N = 5, M = 2, nPower = 1, mPower = 1, numTests = 1, simOption = 0;
	string outputFile = "output.txt";

	while (prog_state > -1)
	{
		// loading?
		if (prog_state == 0)
		{
			simOption = display_menu (1, 0, ':', 1, 2, ";", "Programming Assignment 1 - MyJosephus Problem",
				"Choose Output Method", "Display All Output and Record Partial Output;Only Record Partial Output");
			prog_state = 1;
		}
		else if (prog_state == 1)
		{
			option = display_menu (1, 0, ':', 1, 9, ";", "Programming Assignment 1 - MyJosephus Problem",
				"Main Menu", "Test List Implementation;Test Vector Implementation;Set Number of People;Set Elimination Jump Interval;Set Number of People Power Increase;Set Elimination Jump Interval Power Increase;Set Number of Test Cycles;Set Output File Name;Quit");
			cin.clear();
			cin.ignore(500, '\n' );
			if (option == 1)
			{
				if (simOption == 1)
					testListOutput (N, M, nPower, mPower, numTests, outputFile);
				else if (simOption == 2)
					testListNoOutput (N, M, nPower, mPower, numTests, outputFile);
			}
			else if (option == 2)
			{
				if (simOption == 1)
					testVectorOutput (N, M, nPower, mPower, numTests, outputFile);
				else if (simOption == 2)
					testVectorNoOutput (N, M, nPower, mPower, numTests, outputFile);
			}
			else if (option == 3)
			{
				system ("cls");
				cout << "Enter Number of People Playing: ";
				cin >> N;
			}
			else if (option == 4)
			{
				system ("cls");
				cout << "Enter Elimination Jump Interval: ";
				cin >> M;
			}
			else if (option == 5)
			{
				system ("cls");
				cout << "Enter Number of People Power Increase: ";
				cin >> nPower;
			}
			else if (option == 6)
			{
				system ("cls");
				cout << "Enter Elimination Jump Interval Power Increase: ";
				cin >> mPower;
			}
			else if (option == 7)
			{
				system ("cls");
				cout << "Enter Number of Test Cycles: ";
				cin >> numTests;
			}
			else if (option == 8)
			{
				system ("cls");
				cout << "Enter Output Filename (with file extension): ";
				cin >> outputFile;
			}
			else
			{
				prog_state = -1;
			}
		}
	}

	return 0;
}