#include "ItemDeck.h"

#include "Item.h"


std::vector<Item*> ItemDeck::generateItems(int count) 
{
	//TODO: PICK AT RANDOM SEVERAL ITEMS FROM DATABASE AS A PLAYER HAND
	std::vector<Item*> generatedItems;
	for (int i = 0; i < count; i++)
	{
		generatedItems.push_back(getRandomCard());
	}
	return generatedItems;
}
