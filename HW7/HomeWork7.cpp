#include <iostream>
#include <iomanip>

int main()
{
	// Input
	int Rounds;
	int DrawCount = 0;
	int WinCount = 0;
	int LossCount = 0;
	char PlayerChoice;

	// Providing seed for rand
	srand((unsigned)time(0));

	while (true)
	{
		std::cout << "Hello! Welcome to 'Rock paper scissors' game for 2 players." << std::endl
			<< "Enter rounds number: (-1 to quit): ";
		std::cin >> Rounds;
		if (Rounds == -1)
		{
			std::cout << "BYE-BYE";
			break;
		}
		for (int i = 0; i < Rounds; i++)
		{
			std::cout << "To make your turn enter one of possible symbols!" << std::endl
				<< " \t r - rock \t p - paper \t s - scissors: ";
			std::cin >> PlayerChoice;

			if (PlayerChoice == 'r' || PlayerChoice == 'p' || PlayerChoice == 's')
			{
				char GeneratedChoice[] = {'r', 'p', 's'};
				int Index = rand() % 3;
				std::cout << "PC choice is " << GeneratedChoice[Index] << std::endl;
				// p - 112 r - 114 s - 115
				if (PlayerChoice == GeneratedChoice[Index])
				{
					std::cout << "It's DRAW" << std::endl;
					DrawCount++;
				}
				// Win(2,1,-3) Lose(3,-2,-1)
				else if (GeneratedChoice[Index] - PlayerChoice != 3
					&& GeneratedChoice[Index] - PlayerChoice != -1
					&& GeneratedChoice[Index] - PlayerChoice != -2)
				{
					std::cout << "You WIN" << std::endl;
					WinCount++;
				}
				else
				{
					std::cout << "You LOST" << std::endl;
					LossCount++;
				}
			}
			else
			{
				std::cout << "You entered wrong symbol!" << std::endl;
				i--;
			}
			
		}
		std::cout
			<< "Thanks for playing. Your final stats:" << std::endl
			<< "number of rounds - " << Rounds << std::endl
			<< "number of wins - " << WinCount << std::endl
			<< "number of losses - " << LossCount << std::endl
			<< "number of draws - " << DrawCount << std::endl;
		if (WinCount > LossCount)
		{
			std::cout << "---You are smarter than my PC algo!---" << std::endl;
		}
		else if (WinCount == LossCount)
		{
			std::cout << "---You are equal to my PC algo!---" << std::endl;
		}
		else
		{
			std::cout << "---You lost, try harder!---" << std::endl;
		}
		std::cout << std::setw(40) << std::setfill('-') << "\n\n\n\n" << std::endl;
	}
}