#include "pa2.h"

// Loads a file into a vector array
vector<int> loadFile (string fileSize, string fileNum)
{
	vector<int> fileArray;
	int i = 0, sizeOfArray = atoi (fileSize.c_str());
	char temp, *altTemp = '\0';
	ifstream input;

	system("cls");
	cout << "Loading File...";

	string inputFile = "inputs/input_" + fileSize + "_" + fileNum + ".txt";
	input.open (inputFile.c_str (), ios::in);

	fileArray.resize(sizeOfArray);

	while (input.good() && i != sizeOfArray)
	{
		temp = input.get();
		//input >> fileArray[i];
		if (temp == '-')
		{
			temp = input.get();
			altTemp = &temp;
			fileArray[i] = - atoi(altTemp);
			i++;
		}
		else if (temp != '\n')
		{
			altTemp = &temp;
			fileArray[i] = atoi(altTemp);
			i++;
		}
	}

	cout << "File Loaded!...";
	input.close();

	return fileArray;
}

// Converts an integer to a string
string toString (int i)
{
	std::stringstream tempOut;
	tempOut << i;
	return tempOut.str();
}