#include "VictoryPolicy.h"

class ItemDeck;
class ModifierDeck;
class Munchkin;

void VictoryPolicy::apply(Munchkin* munchkin, ItemDeck& itemDeck, ModifierDeck& modifierDeck)
{
	munchkin->updateLevelBy(m_levelsCount);
	munchkin->addItems(itemDeck.generateItems(m_itemsCount));
	munchkin->addModifiers(modifierDeck.generateModifiers(m_modifiersCount));
}

std::string VictoryPolicy::getFullInfo() const
{
	return "Reward: " + std::to_string(m_levelsCount) + "levels, " + std::to_string(m_itemsCount) + " items, "
		+ std::to_string(m_modifiersCount) + " modifiers!\n";
}
