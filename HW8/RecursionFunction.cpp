#include "RecursionFunctions.h"
#include <iostream>

 // Task 2

int RecursionFactorial(int Count)
{
	if (Count > 0)
	{
		return Count * RecursionFactorial(Count - 1);
	}
	else if (Count < 0)
	{
		std::cout << "RecursionFactorial: INVALID INPUT" << std::endl;
	}
	else
	{
		return 1;
	}
}

// Task 3

void PrintNaturalNumbersHigh(int Count)
{
	if (Count < 0)
	{
		std::cout << "PrintNaturalNumbersHigh: INVALID INPUT" << std::endl;
	}
	else if(Count > 0)
	{
		std::cout << Count << " ";
		PrintNaturalNumbersHigh(Count - 1);
		
	}
	else
	{
		return;
	}
}

void PrintNaturalNumbersLow(int Count)
{

	if (Count < 0)
	{
		std::cout << "PrintNaturalNumbersLow: INVALID INPUT" << std::endl;
	}
	else if(Count == 0)
	{
		return;
	}
	else
	{
		PrintNaturalNumbersLow(Count-1);
		std::cout << Count << " ";
	}
}