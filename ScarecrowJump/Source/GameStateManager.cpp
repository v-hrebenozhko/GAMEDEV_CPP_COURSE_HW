#include "GameStateManager.h"
#include "GameState.h"

GameStateManager::GameStateManager( Menu* mainMenu,GameWorld* gameWorld, GameStateId initialGameStateId)
{
	m_saveFileName = "SaveFile.txt";
	m_gameStates[static_cast<std::size_t>(GameStateId::Playing)] = new GameState_Playing(*this, gameWorld);
	m_gameStates[static_cast<std::size_t>(GameStateId::MainMenu)] = new GameState_MainMenu(*this,mainMenu);
	m_gameStates[static_cast<std::size_t>(GameStateId::Pause)] = new GameState_Pause(*this, mainMenu);
	m_gameStates[static_cast<std::size_t>(GameStateId::GameOver)] = new GameState_GameOver(*this, mainMenu,gameWorld);

	m_currentGameState = m_gameStates[static_cast<std::size_t>(initialGameStateId)];
	m_currentGameState->onEnter();
}

void GameStateManager::setGameState(GameStateId newGameState)
{
	m_currentGameState->onExit();
	m_currentGameState = m_gameStates[static_cast<std::size_t>(newGameState)];
	m_currentGameState->onEnter();
}

void GameStateManager::loadSave()
{
	m_saveManager.loadSave(m_saveFileName);
	m_highScore = m_saveManager.getHighScore();
}

//TODO Delete in d-tor
