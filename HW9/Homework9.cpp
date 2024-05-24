#include <iostream>
#include <cstring>


// Task 1

void TranslateArray(int Numbers[], int Size)
{
	for (int i = 0; i < Size / sizeof(int); i++)
	{
		if (Numbers[i] > 0)
		{
			Numbers[i] *= 2;
		}
		else
		{
			Numbers[i] = 0;
		}
	}
}

// Task 2

void ToUppercase(char Str[])
{
	for (int i = 0;  ; i++)
	{
		if (Str[i] == '\0')
		{
			break;
		}
		if (Str[i] >= 97 && Str[i] <= 122)
		{
			std::cout << Str[i];
			Str[i] -= 32;

		}
	}
}

// Task 3
bool IsPalindrom(const char Str[])
{
	for (int ArraySize = 0;; ArraySize++)
	{
		if (Str[ArraySize] == '\0')
		{
			std::cout << Str[ArraySize];
			ArraySize -= 1;

			for (int j = 0; j < ArraySize / 2; j++)
			{
				if (Str[j] != Str[ArraySize - j])
				{
					return false;
				}
			}
			return true;

		}
	}
	
}

// Task 4

void ParseStringLetters(const char Str[], int& VowelsCount, int& ConstonantsCount)
{
	VowelsCount = 0;
	ConstonantsCount = 0;
	for (int i = 0;; i++)
	{
		if (Str[i] == '\0')
		{
			break;
		}
		if (isalpha(Str[i]))
		{
			if (
				Str[i] == 'A' || Str[i] == 'E' || Str[i] == 'I' ||
				Str[i] == 'O' || Str[i] == 'U' || Str[i] == 'Y' ||
				Str[i] == 'a' || Str[i] == 'e' || Str[i] == 'i' ||
				Str[i] == 'o' || Str[i] == 'u' || Str[i] == 'e')
			{
				VowelsCount++;
			}
			else
			{
				ConstonantsCount++;
			}
		}
	}
}

// Task 5

bool IsEqual(const char Str1[], const char Str2[])
{


	for (int i = 0;; i++)
	{
		if (Str1[i] != '\0' && Str2[i] != '\0')
		{
			if (Str1[i] != Str2[i])
			{
				return false;
			}
		}
		else if(Str1[i] == '\0' && Str2[i] == '\0')
		{
			return true;
		}
		else
		{
			return false;
		}
		
	}
}

int main()
{
// Task 1
	
	int NumbersArray[10];
	std::cout << "Enter 10 random numbers: ";
	for (int i = 0; i < sizeof(NumbersArray) / sizeof(int); i++)
	{
		std::cin >> NumbersArray[i];
	}
	TranslateArray(NumbersArray, sizeof(NumbersArray));
	for (int i = 0; i < sizeof(NumbersArray) / sizeof(int); i++)
	{
		std::cout << NumbersArray[i] << " ";
	}
	

// Task 2

	char String[10] = {0};
	for (int i = 0; i < sizeof(String) - 1; i++)
	{
		std::cin >> String[i];
	}
	std::cout << "Enter 10 random symbols: ";
	ToUppercase(String);
	for (int i = 0; i < sizeof(String) ; i++)
	{
		std::cout << String[i] << " ";
	}
}