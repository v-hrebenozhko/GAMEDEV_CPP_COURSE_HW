#pragma once
#include <vector>
#include "Deck.h"


//forward declaration to not include header into header which will increase compilation time
class Modifier;

class ModifierDeck : Deck<Modifier*>
{
public:
	ModifierDeck() {};
	~ModifierDeck() {};

	std::vector<Modifier*> generateModifiers(int count);
	void addModifier(Modifier* modifier) {	m_initDataBase.push_back(modifier);	}

};