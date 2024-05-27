#include <iostream>

// Task 1
void Swap(int& a, int& b)
{
	int c = a;
	a = b;
	b = c;
}

void Swap(int* a, int* b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

// Task 2
bool CalculateSum(double* Arr, int ArrSize, double& Sum)
{
	//double* ArrIndex = Arr;
	if (ArrSize > 0)
	{
		for (int i = 0; i < ArrSize / sizeof(double); i++)
		{
			Sum += *Arr;
			Arr++;
		}
		return true;
	}
	else
	{
		return false;
	}
}

//Task 3

bool Find(int* Arr, int ArrSize, int Elem)
{

	for (int i = 0; i < ArrSize / sizeof(int); i++)
	{
		if (*Arr == Elem)
		{
				return true;
		}
			Arr++;
	}

	return false;
}
