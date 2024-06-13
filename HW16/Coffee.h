#pragma once

// Task 2

#include <iostream>

enum class coffee_type
{
	Espresso, Doppio, Latte,
	Cappuccino, Ristretto, FlatWhite
};

class coffee
{
private:
	int Cost;
	std::string Name;
	coffee_type m_CoffeeType;
public:
	coffee(coffee_type CoffeeType);
	void Prepare();
	int GetCost() const;
};

// Task 3

class coffee_shop
{
private:
	std::string m_Name;
	int m_TablesAmount;
	bool* m_TablesCount;
	coffee** m_Orders;
public:
	coffee_shop(std::string Name, int TableCount);
	int TakePlace();
	void Order(int TableNumber);
	bool Prepare(int TableNumber);
	bool GetReceipt(int TableNumber);
};