#include "ModifierDeck.h"

#include "Modifier.h"


std::vector<Modifier*> ModifierDeck::generateModifiers(int count) 
{
	//#TODO: this call should return unique modifier every time
	//either for as long as the same game is being played
	//or unless ALL cards were generated from database to the game - in this case 
	//make ALL cards available again
	std::vector<Modifier*> generatedModifiers;
	for (int i = 0; i < count; i++)
	{
		generatedModifiers.push_back(getRandomCard());
	}
	return generatedModifiers;
	return m_initDataBase;
}
