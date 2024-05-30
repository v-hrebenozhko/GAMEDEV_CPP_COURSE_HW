#include <iostream>

// Task 1
const int ROWS = 4;
const int COLUMNS = 5;
bool Find(int Arr_2d[ROWS][COLUMNS], int ToFind)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			if (Arr_2d[i][j] == ToFind)
			{
				return true;
			}
		}
	}
	return false;
}

// Task 2

enum class sorting_direction
{
	Ascending , Discending
};

bool IsSorted(const int* Arr, int Size, sorting_direction Direction)
{
	if (Size == 1)
	{
		return true;
	}
	else if (Size > 1)
	{
		switch (Direction)
		{
		case sorting_direction::Ascending:
		{
			for (int i = 0; i < Size - 1; i++)
			{
				if (Arr[i] > Arr[i + 1])
				{
					return false;
				}
			}
			break;
		}

		case sorting_direction::Discending:
		{
			for (int i = 0; i < Size - 1; i++)
			{
				if (Arr[i] < Arr[i + 1])
				{
					return false;
				}
			}
			break;
		}
		}
		return true;
	}
	else
		return false;

	
}

// Task 3

const int Rows = 4;
const int Columns = 5;

void ArrayTraverseOne(int Arr_2d[Rows][Columns])
{
	for (int i = Columns - 1 ; i > -1; i--)
	{
		for (int j = 0; j < Rows; j++)
		{
			std::cout << Arr_2d[j][i];
		}
	}
}

void ArrayTraverseTwo(int Arr_2d[Rows][Columns])
{
	bool Handle = true;
	for (int i = Rows - 1; i > -1; i--)
	{
		if (Handle)
		{
			for (int j = 0; j < Columns; j++)
			{
				std::cout << Arr_2d[i][j];
			}
		}
		else
		{
			for (int j = Columns - 1; j > -1; j--)
			{
				std::cout << Arr_2d[i][j];
			}
		}
		Handle = !Handle;
	}
}

int main()
{
	int Array[Rows][Columns] = { {2,3,5,6,7},{2,3,4,5,6,},{2,5,6,7,8},{2,3,4,1,6} };
	ArrayTraverseOne(Array);
	std::cout << std::endl;
	ArrayTraverseTwo(Array);
	std::cout << Find(Array, 5);
	int Array2[5] = { 10,6,2,1,1 };
	sorting_direction Dir = sorting_direction::Discending;
	std::cout << IsSorted(Array2, 5, Dir);
}
