#include <iostream>
#include <ctype.h>


int main()
{


	// Task 1

	int FirstSequenceTerm;
	int CommonDifference;
	int LastNumberOfSequence = 0;

	// Input

	std::cout << "Enter the first sequence term: ";
	std::cin >> FirstSequenceTerm;
	std::cout << "Enter common difference: ";
	std::cin >> CommonDifference;
	while (LastNumberOfSequence <= 0)
	{
		std::cout << "Enter last number of sequence: ";
		std::cin >> LastNumberOfSequence;
		if (LastNumberOfSequence <= 0)
		{
			std::cout << "Last number of sequence can't be negative or zero!\n";
		}
	}

	// Output

	std::cout << "Your arithmetic sequence: ";
	for (int i = 0; i < LastNumberOfSequence; i++)
	{
		std::cout << FirstSequenceTerm + CommonDifference * i;
		if (i != LastNumberOfSequence - 1)
		{
			std::cout << " ";
		}
		else
		{
			std::cout << "\n\n\n\n";
		}
	}


	// Task 2 

	int FibonacciNumber = 0;
	int PrevNumber = 0;
	int CurrentNumber = 1;
	int NextNumber = 0;

	// Input

	std::cout << "Enter Fibonacci number: ";
	while (FibonacciNumber <= 0)
	{
		std::cin >> FibonacciNumber;
		if (FibonacciNumber <= 0)
		{
			std::cout << "Fibonacci number can't be negative or zero!\n";
		}
	}

	// Output

	for (int i = 0; i < FibonacciNumber; i++)
	{
		if (i == FibonacciNumber - 1)
		{
			std::cout << "Your Fibonacci number value equals: " << CurrentNumber << "\n\n\n\n";
		}
		else
		{
			NextNumber = PrevNumber + CurrentNumber;
			PrevNumber = CurrentNumber;
			CurrentNumber = NextNumber;
		}
	}


	// Task 3
	int SomeNumber = -1;
	int SomeNumberFactorial = 1;

	// Input

	while (SomeNumber < 0)
	{
		std::cout << "Enter some positive number: ";
		std::cin >> SomeNumber;
		if (SomeNumber < 0)
		{
			std::cout << "You entered negative number!" << std::endl;
		}
	}

	// Output 

	if (SomeNumber == 0)
	{
		std::cout << "Factorial of your number equal: " << SomeNumberFactorial << "\n\n\n\n";
	}
	else
	{
		for (int i = 1; i < SomeNumber + 1; i++)
		{
			SomeNumberFactorial *= i;
		}
		std::cout << "Factorial of your number equal: " << SomeNumberFactorial << "\n\n\n\n";
	}


	// Task 4 

		// Input

	int Rows = 0;

	while (Rows <= 0)
	{
		std::cout << "Enter the number of rows: ";
		std::cin >> Rows;
		if (Rows <= 0)
		{
			std::cout << "Enter positive numbers!\n";
		}
	}

	// a.

	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Rows - i; j++)
		{
			std::cout << "*";
		}
		std::cout << std::endl;
	}
	std::cout << "\n\n";


	// b.

	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			std::cout << "*";
		}
		std::cout << std::endl;
	}
	std::cout << "\n\n";

	// c.

	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Rows; j++)
		{
			std::cout << "*";
		}
		std::cout << std::endl;
	}
	std::cout << "\n\n";

	// d.

	for (int i = 0; i < Rows; i++)
	{
		for (int s = 0; s < i; s++)
		{
			std::cout << " ";
		}
		for (int j = 0; j < Rows; j++)
		{

			std::cout << "*";
		}
		std::cout << std::endl;
	}
	std::cout << "\n\n";

	// e.

	bool Symbol;

	for (int i = 0; i < Rows; i++)
	{
		if (i % 2)
		{
			Symbol = false;
		}
		else
		{
			Symbol = true;
		}
		for (int j = 0; j < i + 1; j++)
		{
			std::cout << Symbol;
			if (Symbol)
			{
				Symbol = false;
			}
			else
			{
				Symbol = true;
			}
		}
		std::cout << std::endl;
	}
	std::cout << "\n\n";

	// Task 5

	int NumbersSum = 0;
	char Input = ' ';

	while (Input != '.')
	{
		std::cout << "Enter one symbol: ";
		std::cin >> Input;
		if (islower(Input))
		{
			std::cout << "Your symbol in uppercase: " << char(toupper(Input)) << std::endl;
		}

		else if (isdigit(Input))
		{
			NumbersSum += atoi(&Input);
			std::cout << "Sum of numbers entered: " << NumbersSum << std::endl;
		}
		else if (isupper(Input))
		{
			std::cout << "Your symbol: " << Input << std::endl;
		}
		else
		{
			std::cout << "Your symbol can'b be processed!" << std::endl;
		}
	}
}