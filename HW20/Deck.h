#pragma once
#include <vector>
#include<string>

template<typename T>

class Deck
{
public:
	Deck() {};
	Deck(const std::vector<T>& initDataBase) : m_initDataBase(initDataBase), m_availableDataBase(initDataBase) {};
	~Deck() {};

	T getRandomCard()
	{
		if (m_availableDataBase.empty())
		{
			resetDatabase();
		}
		int choice = std::rand() % m_availableDataBase.size();
		T monster = m_availableDataBase[choice];
		m_availableDataBase.erase(m_availableDataBase.begin() + choice);
		return monster;
	}
	void resetDatabase() { m_availableDataBase = m_initDataBase; }

protected:
	std::vector<T> m_initDataBase;
	std::vector<T> m_availableDataBase;

};


