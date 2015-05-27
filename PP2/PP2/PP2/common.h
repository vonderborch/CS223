#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <conio.h>
#include <list>
#include <vector>
#include <cmath>
#include <limits>
#include <sstream>
#include "menu_system.h"
#include "rTime.h"
using namespace std;

int maxSumRec (const vector<int> &a, int left, int right);
int max3 (int maxLeftSum, int maxRightSum, int maxBorderSum);

vector<int> loadFile (string fileSize, string fileNum);
string toString (int i);