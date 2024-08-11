#pragma once
#include <vector>
#include "Deck.h"

class Item;

class ItemDeck : Deck<Item*>
{
public:
	ItemDeck() {};
	~ItemDeck() {};

	std::vector<Item*> generateItems(int count);
	void addItem(Item* item) { m_initDataBase.push_back(item); };

private:
	std::vector<Item*> m_itemsDataBase;
};