#pragma once
#include <vector>
#include "Deck.h"

class Monster;

class MonsterDeck: public Deck<Monster*>
{
public:
	MonsterDeck();
	MonsterDeck(const std::vector<Monster*>& monsters)
		: Deck(monsters) {}
	~MonsterDeck();
};