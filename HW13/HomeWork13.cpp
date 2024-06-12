#include <iostream>
#include <time.h>
#include <string>
#include <fstream>


// Loading DataBase

void LoadDataBase(const char* FileName, std::string* DataBase, int DataBaseSize)
{
	std::ifstream File;
	File.open(FileName, std::ios::in);

	if (!File)
	{
		std::cout << "File not found!" << std::endl;
	}
	else
	{
		//File >> std::noskipws;
		for (int i = 0; i < DataBaseSize && !File.eof(); i++)
		{
			std::getline(File, DataBase[i]);
		}
	}
	File.close();
}

// Wordle Algorithm and Wordle Init

bool CheckMatch(const std::string& PlayerWord, std::string& Word)
{
	int MatchCount = 0;
	std::string Result(5, '*');

	for (int i = 0; i < Word.size(); i++)
	{
		Word[i] = std::toupper(Word[i]);
		if (Word[i] == PlayerWord[i])
		{
			Result[i] = Word[i];
			MatchCount++;
		}
		else
		{
			for (int j = 0; j < PlayerWord.size(); j++)
			{
				if (Word[i] == PlayerWord[j] && Result[j] == '*')
				{
					Result[j] = std::tolower(PlayerWord[j]);
					break;
				}
			}
		}
	}
	std::cout << "RESULT : " << Result << std::endl;

	if (MatchCount == 5)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void LaunchWordle( std::string* DataBase,int Index)
{
	if (DataBase[Index].size() == 5)
	{
		int TriesCount = 0;
		bool WinCondition = false;

		while (!WinCondition)
		{
			std::string PlayerWord(5, ' ');
			std::cout << std::endl << std::endl << "ENTER  : ";
			for (int i = 0; i < PlayerWord.size(); i++)
			{
				std::cin >> PlayerWord[i];
				PlayerWord[i] = std::toupper(PlayerWord[i]);
			}
			WinCondition = CheckMatch(PlayerWord, DataBase[Index]);
			TriesCount++;
		}

		std::cout << std::endl << std::endl << "That's right!" << std::endl;
		std::cout << "You made " << TriesCount << " tries!" << std::endl << std::endl << std::endl;
	}
}

// Wordle of Day

int GetDay(const std::tm* tmObj)
{
	return tmObj->tm_mday;
}

int GetMonth(const std::tm* tmObj)
{
	return tmObj->tm_mon + 1;
}

void LoadDateBase(const char* FileName,int* DateBase, int DateBaseSize)
{
	std::fstream File;
	File.open(FileName, std::ios::in);

	if (!File)
	{
		std::cout << "File not found!" << std::endl;
	}
	else
	{
		int x;
		for (int i = 0; i < DateBaseSize && !File.eof(); i++)
		{
			File >> x;
			DateBase[i] = x;
		}
	}
	File.close();
}

void MarkDayIndex(const char* FileName,int* DateBase,int DateBaseSize, int DayIndex)
{
	std::fstream File;
	File.open(FileName, std::ios::out);

	if (!File)
	{
		std::cout << "File not found!" << std::endl;
	}
	else
	{
		DateBase[DayIndex] = 0;
		for (int i = 0; i < DateBaseSize; i++)
		{
			File << DateBase[i] << " ";
		}
	}
	File.close();
}

void ChangeMonth(const char* FileName, int* DateBase, int DateBaseSize, int Month)
{
	std::fstream File;
	File.open(FileName, std::ios::out);

	if (!File)
	{
		std::cout << "File not found!" << std::endl;
	}
	else
	{
		for (int i = 0; i < DateBaseSize - 1; i++)
		{
			File << i + 1 << " ";
		}
		File << Month;
		std::cout << "Month changed! Please restart program!" << std::endl << std::endl << std::endl;
	}
	File.close();
}

void LaunchWordleDay(int* DateBase, int DateBaseSize ,std::string* DataBase)
{
	std::time_t t = std::time(nullptr);
	std::tm now;
	localtime_s(&now, &t);
	int DayIndex = GetDay(&now) - 1;
	
	if (DateBase[DateBaseSize - 1] != GetMonth(&now))
	{
		ChangeMonth("DateBase.txt", DateBase, DateBaseSize, GetMonth(&now));
	}
	else if (DateBase[DayIndex])
	{
		LaunchWordle(DataBase,DayIndex);
		MarkDayIndex("DateBase.txt",DateBase,DateBaseSize, DayIndex);
	}
	else
	{
		std::cout << "Already found! Come back tomorow!" << std::endl << std::endl << std::endl;
	}
}

// Random Wordle

void LaunchRandomWordle(std::string* DataBase)
{
	srand((unsigned)time(0));
	int RandomIndex = rand() % 30;
	LaunchWordle(DataBase, RandomIndex);
}


int main()
{
	constexpr int WordleDataBaseSize = 31;
	std::string WordleDataBase[WordleDataBaseSize];
	LoadDataBase("WordleDataBase.txt", WordleDataBase, WordleDataBaseSize);

	constexpr int WordleDateBaseSize = 32;
	int WordleDateBase[WordleDateBaseSize];
	LoadDateBase("DateBase.txt", WordleDateBase, WordleDateBaseSize);

	char PlayerChoice = '3';
	bool IsRunning = true;
	
	while (IsRunning)
	{
		std::cout
			<< "1 - Wordle of the day" << std::endl
			<< "2 - Random Wordle" << std::endl
			<< "0 - Exit" << std::endl;
		std::cout << "Enter: ";
		std::cin >> PlayerChoice;

		switch (PlayerChoice)
		{
		case '1':
		{
			LaunchWordleDay(WordleDateBase,WordleDateBaseSize,WordleDataBase);
			break;
		}
		case '2':
		{
			LaunchRandomWordle(WordleDataBase);
			break;
		}
		case '0':
		{
			IsRunning = false;
			break;
		}
		default:
		{
			std::cout << "You entered wrong symbol!" << std::endl;
			break;
		}
		}
	}
}