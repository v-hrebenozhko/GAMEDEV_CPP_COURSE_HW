#pragma once
#include "drink.h"

class coffee_shop
{
private:
	std::string m_Name;
	int m_TablesAmount;
	bool* m_TablesCount;
	drink** m_Orders;
public:
	coffee_shop(std::string Name, int TableCount);
	~coffee_shop();
	int TakePlace();
	void Order(int TableNumber);
	bool Prepare(int TableNumber);
	bool GetReceipt(int TableNumber);
	void RunCoffeeShop();
};
