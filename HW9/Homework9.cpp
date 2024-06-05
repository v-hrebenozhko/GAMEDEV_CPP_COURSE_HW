#include <iostream>
#include <cstring>


// Task 1

void TranslateArray(int Numbers[], int Size)
{
	for (int i = 0; i < Size; i++)
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
	for (int i = 0; Str[i] != '\0'; i++)
	{
		if (Str[i] >= 'a' && Str[i] <= 'z')
		{
			Str[i] -= 32;

		}
	}
}

// Task 3
bool IsPalindrom(const char Str[])
{
	int ArraySize = 0;
	for (int i = 0; Str[i] != '\0'; i++)
	{
		ArraySize++;
	}
	for (int j = 0; j < ArraySize / 2; j++)
	{
		if (Str[j] != Str[ArraySize - j - 1])
		{
			return false;
		}
	}
	return true;


}

// Task 4

void ParseStringLetters(const char Str[], int& VowelsCount, int& ConstonantsCount)
{
	VowelsCount = 0;
	ConstonantsCount = 0;
	for (int i = 0; Str[i] != '\0'; i++)
	{
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
	int i = 0;
	for (; Str1[i] != '\0'; i++)
	{
		if (Str1[i] != Str2[i])
		{
			return false;
		}
	}
	if (Str2[i] != '\0')
	{
		return false;
	}
	return true;
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
	TranslateArray(NumbersArray, sizeof(NumbersArray) / sizeof(int));
	for (int i = 0; i < sizeof(NumbersArray) / sizeof(int); i++)
	{
		std::cout << NumbersArray[i] << " ";
	}


	// Task 2

	char String[10] = { 0 };
	std::cout << "Enter 10 random symbols: ";
	for (int i = 0; i < sizeof(String) - 1; i++)
	{
		std::cin >> String[i];
	}

	ToUppercase(String);
	for (int i = 0; i < sizeof(String); i++)
	{
		std::cout << String[i] << " ";
	}

}