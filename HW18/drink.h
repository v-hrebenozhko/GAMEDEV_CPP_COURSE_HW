#pragma once
	
#include <iostream>

enum class drink_type
{
	BlackTea, GreenTea, Espresso,
	Americano, Latte, Cappuccino,
	InvalidType
};

enum class drink_size
{
	S, M, L, XL
};

class drink
{
protected:
	int m_Cost;
	drink_size m_DrinkSize;
	std::string m_Name;
public:
	virtual ~drink() {};
	virtual void Prepare() = 0;
	int GetCost() const;
	std::string GetName() const;

};

class black_tea : public drink
{
public:
	void Prepare() override;
	black_tea(drink_size DrinkSize);
};

class green_tea : public drink
{
public:
	void Prepare() override;
	green_tea(drink_size DrinkSize);
};

class espresso : public drink
{
public:
	void Prepare() override;
	espresso();
};

class americano : public drink
{
public:
	void Prepare() override;
	americano(drink_size DrinkSize);
};

class latte : public drink
{
public:
	void Prepare() override;
	latte(drink_size DrinkSize);
};

class cappuccino : public drink
{
public:
	void Prepare() override;
	cappuccino(drink_size DrinkSize);
};

drink_type ChoseType();
drink_size ChoseSize(drink_type DrinkType);
drink* CreateDrink(drink_type DrinkType);
