#pragma once
#include <cstddef>
#include "SaveManager.h"

class GameState;
class GameWorld;
class Menu;
class SaveManager;

enum  class GameStateId
{
	Playing,
	MainMenu,
	Pause,
	GameOver,
	//Others
	Count
};

class GameStateManager
{
public:
	GameStateManager() {};
	GameStateManager(Menu* mainMenu, GameWorld* gameWorld, GameStateId initialGameStateId);

	void setGameState(GameStateId newGameState);
	void loadSave()
	{
		m_saveManager.loadSave(m_saveFileName);
		m_highScore = m_saveManager.getHighScore();
	}
	void saveGame(std::vector<std::string> saveData)
	{
		m_saveManager.save(m_saveFileName, saveData);
	}
	unsigned int getHighScore() { return m_highScore; }
	void setHighScore(unsigned int highScore) { m_highScore = highScore; }

	GameState* getCurrentGameState() const { return m_currentGameState; }

	const bool getIsNewGame() const { return isNewGame; }
	void changeIsNewGame() { isNewGame = !isNewGame; }

	const bool getIsFirstEntry() const { return isFirstEntry; }
	void changeIsFirstEntry() { isFirstEntry = !isFirstEntry; }

	const std::vector<std::string>& getSaveData() const { return m_saveManager.getSaveData(); }

private:
	std::string m_saveFileName;
	bool isNewGame = false;
	bool isFirstEntry = true;
	unsigned int m_highScore;
	SaveManager m_saveManager;
	GameState* m_currentGameState = nullptr;
	GameState* m_gameStates[static_cast<std::size_t>(GameStateId::Count)];
	
};