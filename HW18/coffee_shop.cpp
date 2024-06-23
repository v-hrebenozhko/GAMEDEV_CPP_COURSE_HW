#include "coffee_shop.h"


coffee_shop::coffee_shop(std::string Name, int TablesAmount)
{
	m_Name = Name;
	m_TablesAmount = TablesAmount;
	m_TablesCount = new bool[m_TablesAmount] {};
	m_Orders = new drink * [m_TablesAmount] {};
}

coffee_shop::~coffee_shop()
{
	delete m_TablesCount;
	delete[] m_Orders;
}

int coffee_shop::TakePlace()
{
	for (int i = 0; i < m_TablesAmount; i++)
	{
		if (!m_TablesCount[i])
		{
			m_TablesCount[i] = true;
			return i;
		}
	}
	return -1;
}

void coffee_shop::Order(int TableNumber)
{
	if (TableNumber >= 0 && TableNumber < m_TablesAmount)
	{
		m_Orders[TableNumber] = CreateDrink(ChoseType());
		if (!m_Orders[TableNumber])
		{
			m_TablesCount[TableNumber] = false;
		}
	}
	else
	{
		std::cout << "Find empty table first!" << std::endl;
	}
}

bool coffee_shop::Prepare(int TableNumber)
{
	if (TableNumber >= 0 && TableNumber < m_TablesAmount)
	{
		if (m_Orders[TableNumber])
		{
			m_Orders[TableNumber]->Prepare();
			std::cout << "Here your cup of " << m_Orders[TableNumber]->GetName() << std::endl;
			return true;
		}
		else
		{
			std::cout << "Make order first!" << std::endl;
			return false;
		}
	}
	else
	{
		std::cout << "Find empty table first!" << std::endl;
	}
}

bool coffee_shop::GetReceipt(int TableNumber)
{
	if (TableNumber >= 0 && TableNumber < m_TablesAmount)
	{
		if (m_Orders[TableNumber])
		{
			std::cout << m_Orders[TableNumber]->GetCost() << " to be paid!" << std::endl;
			m_TablesCount[TableNumber] = false;
			delete m_Orders[TableNumber];
			m_Orders[TableNumber] = nullptr;
			return true;
		}
		else
		{
			std::cout << "Make order first!" << std::endl;
			m_TablesCount[TableNumber] = false;
			return false;
		}
	}
	else
	{
		std::cout << "Find empty table first!" << std::endl;
		return false;
	}
}

void coffee_shop::RunCoffeeShop()
{
	int Choice;
	int TableNumber;
	int* Tables = new int[m_TablesAmount];
	while (true)
	{
		std::cout << "1 - To order 2 - to get receipt 0 - exit " << std::endl;
		std::cin >> Choice;
		if (Choice == 1)
		{
			TableNumber = this->TakePlace();
			if (TableNumber != -1)
			{
				std::cout << "Your table is " << TableNumber << std::endl;
				this->Order(TableNumber);
				this->Prepare(TableNumber);
			}
			else
			{
				std::cout << "No free spaces!" << std::endl;
			}
		}
		else if (Choice == 2)
		{
			std::cout << "Please enter your table number: ";
			std::cin >> TableNumber;
			this->GetReceipt(TableNumber);
		}
		else if (Choice == 0)
		{
			std::cout << "Bye-Bye!" << std::endl;
			break;
		}
		else
		{
			std::cout << "You entered wrong number!" << std::endl;
		}
	}
}
