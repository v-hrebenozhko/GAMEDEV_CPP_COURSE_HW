#pragma once
#include "Tribe.h"
#include <string>

class Item
{
public:
	virtual int getMunchkinModifier(Tribe monsterTribeModifier) const { return 1; }
	virtual int getEnemyModifier(Tribe monsterTribeModifier) const { return 1; }
	virtual int getBasePower() const { return 0; }

	void setName(const std::string& name) { m_name = name; }
	const std::string getName() const { return m_name; }
	virtual std::string getFullInfo() const = 0;

protected:
	std::string m_name;
	//other fields like description, image, category

private:
};

class Weapon : public Item
{
public:
	Weapon(const std::string& name, int power)
	{
		setName(name);
		m_power = power;
	}

	int getBasePower() const override
	{
		return m_power;
	}

	virtual std::string getFullInfo() const override
	{
		return "\"" + getName() + "\"" + ", power:" + std::to_string(getBasePower()) + ", skills: None\n";
	}

protected:
	int m_power = 0;
	int EnemyModifier = 1;
	int MunchkinModifier = 1;
};

class UndeadWeapon : public Weapon
{
public:
	UndeadWeapon(const std::string& name, int power) : Weapon(name, power) {}

	virtual int getMunchkinModifier(Tribe monsterTribeModifier) const override
	{
		if (monsterTribeModifier == Tribe::Undead)
		{
			return 2;
		}
		return MunchkinModifier;
	}

	virtual std::string getFullInfo() const override
	{
		return "\"" + getName() + "\"" + ", power:" + std::to_string(getBasePower()) + ", skills: x2 vs UNDEADS!\n";
	}
};

//TODO: Add new Item type with unique properties

class GodWeapon : public Weapon
{
public:
	GodWeapon(const std::string& name, int power) : Weapon(name, power) {}

	virtual int getEnemyModifier(Tribe monsterTribeModifier) const override
	{
		if (monsterTribeModifier != Tribe::God)
		{
			return 2;
		}
		return MunchkinModifier;
	}
	virtual int getMunchkinModifier(Tribe monsterTribeModifier) const override
	{
		if (monsterTribeModifier == Tribe::God)
		{
			return 0;
		}
		return MunchkinModifier;
	}
	

	virtual std::string getFullInfo() const override
	{
		return "\"" + getName() + "\"" + ", power:" + std::to_string(getBasePower()) + ", skills: Reduces enemy power by Half"
			+ "Totaly useless vs Gods!\n";
	}
};