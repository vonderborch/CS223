#include "pa2.h"

//Displays menu and calls maxSubSequenceSum functions. Also asks user what input size to use.
int main(int argc, char* argv[])
{
	string inputFile = argv[0], fileID = "";

	int prog_state = 0,
		mainOption = 0, maxSubSumOption = 0,
		testCycles = 10;

	while (prog_state >= 0)
	{
		// Ask user which file size set to use.
		if (prog_state == 0)
		{
			string arraySize = "0", arrayNumber = "0";
			bool isSelecting = true;
			while (isSelecting)
			{
				system("cls");
				cout << "Input Size (8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192): ";
				cin >> arraySize;
				if (arraySize == "8" || arraySize == "16" || arraySize == "32" || arraySize == "64" || arraySize == "128" ||
					arraySize == "256" || arraySize == "512" || arraySize == "1024" || arraySize == "2048" || arraySize == "4096" || arraySize == "8192")
						isSelecting = false;
			}
			fileID = arraySize;

			prog_state = 1;
		}
		// main menu
		else if (prog_state == 1)
		{
			mainOption = display_menu (1, 0, ':', 1, 4, ";", "Programming Assignment 2 - Maximum Subsequence Sum",
				"Main Menu", "Run Test(s);Test Cycles;Choose Input Size;Quit");
			cin.clear();
			cin.ignore(500, '\n' );

			// analyze menu input
			if (mainOption == 1)
			{
				maxSubSumOption = display_menu (1, 0, ':', 1, 6, ";", "Programming Assignment 2 - Maximum Subsequence Sum",
					"Choose An Algorithm to Run", "Run All;Algorithm 1;Algorithm 2;Algorithm 3;Algorithm 4;Back");
				if (maxSubSumOption == 1)
				{
					testMaxSubSum1 (testCycles, fileID);
					testMaxSubSum2 (testCycles, fileID);
					testMaxSubSum3 (testCycles, fileID);
					testMaxSubSum4 (testCycles, fileID);
				}
				else if (maxSubSumOption == 2)
				{
					testMaxSubSum1 (testCycles, fileID);
				}
				else if (maxSubSumOption == 3)
				{
					testMaxSubSum2 (testCycles, fileID);
				}
				else if (maxSubSumOption == 4)
				{
					testMaxSubSum3 (testCycles, fileID);
				}
				else if (maxSubSumOption == 5)
				{
					testMaxSubSum4 (testCycles, fileID);
				}
			}
			else if (mainOption == 2)
			{
				bool isGood = false;
				while (!isGood)
				{
					system("cls");
					cout << "Number of Tests (Min = 1, Max = 10)? ";
					cin >> testCycles;
					if (testCycles > 0 && testCycles < 11)
						isGood = true;
				}
			}
			else if (mainOption == 3)
			{
				prog_state = 0;
			}
			else
			{
				prog_state = -1;
			}
		}
	}
}