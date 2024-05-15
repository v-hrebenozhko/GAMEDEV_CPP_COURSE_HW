#include <iostream>
#include <iomanip>

int main()
{
	// Input
	int Rounds;
	int DrawCount = 0;
	int WinCount = 0;
	int LossCount = 0;
	int GeneratedChoice;
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

			// Generated choice 0 = r, 1 = p, 2 = s
			GeneratedChoice = rand() % 3;

			if (PlayerChoice == 'r')
			{
				std::cout << "Your choice is R" << std::endl;

				if (GeneratedChoice == 0)
				{
					std::cout << "PC choice is R" << std::endl;
					std::cout << "It's DRAW" << std::endl;
					DrawCount++;
				}
				else if (GeneratedChoice == 1)
				{
					std::cout << "PC choice is P" << std::endl;
					std::cout << "You LOST" << std::endl;
					LossCount++;
				}
				else 
				{
					std::cout << "PC choice is S" << std::endl;
					std::cout << "You WIN" << std::endl;
					WinCount++;
				}
			}
			else if (PlayerChoice == 'p')
			{
				std::cout << "Your choice is P" << std::endl;
				if (GeneratedChoice == 0)
				{
					std::cout << "PC choice is R" << std::endl;
					std::cout << "You WIN" << std::endl;
					WinCount++;
				}
				else if (GeneratedChoice == 1)
				{
					std::cout << "PC choice is P" << std::endl;
					std::cout << "It's DRAW" << std::endl;
					DrawCount++;
				}
				else
				{
					std::cout << "PC choice is S" << std::endl;
					std::cout << "You LOST" << std::endl;
					LossCount++;
				}
			}
			else if (PlayerChoice == 's')
			{
				std::cout << "Your choice is S" << std::endl;
				if (GeneratedChoice == 0)
				{
					std::cout << "PC choice is R" << std::endl;
					std::cout << "You LOST" << std::endl;
					LossCount++;
				}
				else if (GeneratedChoice == 1)
				{
					std::cout << "PC choice is P" << std::endl;
					std::cout << "You WIN" << std::endl;
					WinCount++;
				}
				else
				{
					std::cout << "PC choice is S" << std::endl;
					std::cout << "It's DRAW" << std::endl;
					DrawCount++;
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
