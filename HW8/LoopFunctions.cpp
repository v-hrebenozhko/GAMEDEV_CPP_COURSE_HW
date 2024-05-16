#include "LoopFunctions.h"
#include <iostream>

// Task 1

void SignCounter(int NumbersAmount)
{
	int InputNumber;
	int PositiveCounter = 0;
	int NegativeCounter = 0;
	int ZeroesCounter = 0;
	for (int i = 0; i < NumbersAmount; i++)
	{
		std::cin >> InputNumber;
		if (InputNumber > 0)
		{
			PositiveCounter++;
		}
		else if (InputNumber < 0)
		{
			NegativeCounter++;
		}
		else
		{
			ZeroesCounter++;
		}
	}
	std::cout 
		<< "Positive: " << PositiveCounter 
		<< ", negative: " << NegativeCounter 
		<< ", zeroes: " << ZeroesCounter << std::endl;;
}

// Task 2

int LoopFactorial(int Count)
{
	int Factorial = 1;
	
	if (Count > 0)
	{
		for (int i = 1; i < Count + 1; i++)
		{
			Factorial *= i;
		}
		return Factorial;
	}
	else
	{
		std::cout << "LoopFactorial: INVALID INPUT" << std::endl;
	}
}

// Task 3

void PrintNaturalNumbersHigh(int Count)
{
	if (Count < 0)
	{
		std::cout << "PrintNaturalNumbersHigh: INVALID INPUT" << std::endl;
		return;
	}
	for (int i = 0; i < Count; i++)
	{
		std::cout << Count - i << " ";
	}
}


void PrintNaturalNumbersLow(int Count)
{
	if (Count < 0)
	{
		std::cout << "PrintNaturalNumbersLow: INVALID INPUT" << std::endl;
		return;
	}
	for (int i = 0; i < Count; i++)
	{
		std::cout <<  i+1 << " ";
	}
}