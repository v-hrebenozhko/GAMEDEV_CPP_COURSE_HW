#pragma once
#include <string>
#include "Munchkin.h"
#include "ItemDeck.h"
#include "ModifierDeck.h"

// forwad declaration
class Munchkin;

class VictoryPolicy
{
public:
	VictoryPolicy(int modifierCount, int itemsCount, int levelsCount) :
	 m_modifiersCount(modifierCount), m_itemsCount(itemsCount), m_levelsCount(levelsCount){}
	void apply(Munchkin* munchkin, ItemDeck& itemDeck,ModifierDeck& modifierDeck);

	std::string getFullInfo() const;
private:
	int m_weaponsCount;
	int m_modifiersCount;
	int m_itemsCount;
	int m_levelsCount;

};
