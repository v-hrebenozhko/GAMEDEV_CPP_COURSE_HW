#pragma once
#include "Munchkin.h"
#include "ItemDeck.h"
#include "MonsterDeck.h"
#include "ModifierDeck.h"
#include "Deck.h"

class Game
{
public:
	Game() = default;
	void run();

private:
	void generateMunchkinInitialCards();
	Monster* generateMonster();
	void createMonsters(std::vector<Monster*>& monsters)
	{
		m_monstersDeck = monsters;
	}
	void loadDataBase(std::string dataBaseFile);

private:
	Munchkin m_munchkin;
	ItemDeck m_itemsDeck;
	ModifierDeck m_modifiersDeck;
	MonsterDeck m_monstersDeck;
};