#include <iostream>

// Task 1
void BubbleSort(int Arr[],int Size)
{
	for (int i = 0; i < Size - 1; i++)
	{
		for (int j = 0; j < Size - i - 1; j++)
		{
			if (Arr[j] > Arr[j + 1])
			{
				std::swap(Arr[j], Arr[j + 1]);
			}
		}
	}
}


// Task 2

enum class sorting_direction
{
	ByRows,ByColumns
};
const int Rows = 2;
const int Columns = 4;

int Partition(int Arr[],int Low, int High)
{
	int Pivot = Arr[High];

	int i = Low - 1;

	for (int j = Low; j <= High; j++)
	{
		if (Arr[j] < Pivot)
		{
			i++;
			std::swap(Arr[i], Arr[j]);
		}
	}
	std::swap(Arr[i + 1], Arr[High]);
	return i + 1;
}

void QuickSort(int Arr[], int Low, int High)
{
	if (Low < High)
	{
		int PivotIndex = Partition(Arr, Low, High);
		QuickSort(Arr, Low, PivotIndex - 1);
		QuickSort(Arr, PivotIndex + 1, High);
	}
}


void Sort(int Arr[Rows][Columns], sorting_direction Direction)
{
	if (Direction == sorting_direction::ByColumns)
	{
		for (int i = 0; i < Columns; i++)
		{
			int Column[Rows];
			for (int j = 0; j < Rows; j++)
			{
				Column[j] = Arr[i][j];
			}
			QuickSort(Column, 0, Rows - 1);
			for (int j = 0; j < Rows; j++)
			{
				Arr[i][j] = Column[j];
			}
		}
	}

	if (Direction == sorting_direction::ByRows)
	{
		for (int i = 0; i < Rows; i++)
		{
			QuickSort(Arr[i], 0, Columns - 1);
		}
	}
}
