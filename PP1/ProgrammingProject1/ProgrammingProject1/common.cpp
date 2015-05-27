#include "common.h"

// get the power of the base, power value, and cycle inputted
int getIntPower (int base, int power, int cycle)
{
	int i = 0, answer = base, j = 0, k = 0;
	//cycle--;
	if (power != 1)
	{
			for (i = 0; i < cycle; i++)
			{
				answer *= power;
			}
	}
	return answer;
}