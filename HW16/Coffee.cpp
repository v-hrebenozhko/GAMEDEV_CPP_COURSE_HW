// Task 2

#include "Coffee.h"

coffee::coffee(coffee_type CoffeeType)
{
	m_CoffeeType = CoffeeType;
	switch (CoffeeType)
	{
	case coffee_type::Cappuccino:
	{
		Name = "Cappuccino";
		Cost = 40;
		break;
	}
	case coffee_type::Doppio:
	{
		Name = "Doppio";
		Cost = 40;
		break;
	}
	case coffee_type::Espresso:
	{
		Name = "Espresso";
		Cost = 30;
		break;
	}
	case coffee_type::FlatWhite:
	{
		Name = "FlatWhite";
		Cost = 50;
		break;
	}
	case coffee_type::Latte:
	{
		Name = "Latte";
		Cost = 40;
		break;
	}
	case coffee_type::Ristretto:
	{
		Name = "Ristretto";
		Cost = 35;
		break;
	}
	default:
		break;
	}
}

void coffee::Prepare()
{
	std::cout << "Prepairing " << Name << "!" << std::endl;
}

int coffee::GetCost() const
{
	return Cost;
}

// Task 3

coffee_shop::coffee_shop(std::string Name, int TablesAmount)
{
	m_Name = Name;
	m_TablesAmount = TablesAmount;
	m_TablesCount = new bool[m_TablesAmount]{};
	m_Orders = new coffee*[m_TablesAmount]{};
}

coffee_shop::~coffee_shop()
{
	delete[] m_TablesCount;
	delete[] m_Orders;
}

// Task 4

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
	if (TableNumber > 0 && TableNumber < m_TablesAmount)
	{
		std::cout
			<< "Menu: " << std::endl
			<< "1 - Espresso: 30  2 - Doppio: 40  3 - Latte: 40" << std::endl
			<< "4 - Cappuccino: 40  5 - Ristretto: 35  6 - FlatWhite: 50" << std::endl
			<< "Enter your order: ";
		int CustomerOrder;
		std::cin >> CustomerOrder;
		if (CustomerOrder > 0 && CustomerOrder < 7)
		{
			m_Orders[TableNumber] = new coffee((coffee_type)(CustomerOrder - 1));
		}
		else
		{
			std::cout << "You entered wrong number!" << std::endl;
		}
	}
	else
	{
		std::cout << "Find empty table first!" << std::endl;
	}
}

bool coffee_shop::Prepare(int TableNumber)
{
	if (TableNumber > 0 && TableNumber < m_TablesAmount)
	{
		if (m_Orders[TableNumber])
		{
			m_Orders[TableNumber]->Prepare();
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
	if (TableNumber > 0 && TableNumber < m_TablesAmount)
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
			return false;
		}
	}
	else
	{
		std::cout << "Find empty table first!" << std::endl;
	}
}