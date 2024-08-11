#pragma once
#include <string>
#include "Tribe.h"
#include "Runaway.h"
#include "VictoryPolicy.h"

class Runaway;

class Monster
{
public:
	Monster(const std::string& name, int level = 1, Tribe tribe = Tribe::Human, Runaway* policy = nullptr, VictoryPolicy* Victory = nullptr)
		: m_name(name), m_level(level), m_tribe(tribe), m_RunawayPolicy(policy), m_VictoryPolicy(Victory) {}

	Tribe getTribe() const { return m_tribe; }
	unsigned int getLevel() const { return m_level; }
	const std::string& getName() const { return m_name; }

	Runaway* getRunawayPolicy() const { return m_RunawayPolicy; }
	VictoryPolicy* getVictoryPolicy() const { return m_VictoryPolicy; }

	std::string getFullInfo() const { return "Monster " + getName() + ", " + m_RunawayPolicy->getFullInfo(); }
	void ReduceLevelByHalf() {m_level /= 2;	}

private:
	unsigned int m_level = 1;
	Tribe m_tribe = Tribe::Human;
	std::string m_name;

	//#TODO: Add bonus victory policy for losing to munchkin similar to Runaway policies
	VictoryPolicy* m_VictoryPolicy = nullptr;
	Runaway* m_RunawayPolicy = nullptr;
};

//LOSING FLOW:
//Runaway* newRunaway = monster->getRunaway();
//newRunaway->apply(m_munchkin);