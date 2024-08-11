#include "MonsterDeck.h"

#include "Monster.h"
#include "Runaway.h"

MonsterDeck::MonsterDeck()
{
	m_initDataBase =
	{
		//#TODO: Think of new monsters, feel free to use official Munchkin games as a reference
		new Monster{"Crazy Joe", 4,Tribe::Human,new Runaway_LevelDowngrade{1}, new VictoryPolicy{2,0,1}},
		new Monster{"Shiva destructor", 20, Tribe::God, new Runaway_LevelDowngradeIf{2, 5} , new VictoryPolicy{3,1,2} },
		new Monster{"Vampire", 15, Tribe::Undead, new Runaway_LevelDowngrade{1} , new VictoryPolicy{3,1,1}}
	};
	m_availableDataBase = m_initDataBase;
}

MonsterDeck::~MonsterDeck()
{
	//TODO: Clear memory
}