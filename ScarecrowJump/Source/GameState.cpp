#include "GameState.h"
#include "GameStateManager.h"
#include "FontManager.h"
#include "SoundManager.h"

void GameState_Playing::onEnter()
{
	SoundManager::getInstance().unpauseGameSound();
	m_GameWorld->setHighScore(m_gameStateManager.getHighScore());
	SoundManager::getInstance().playGameStart();
}

void GameState_Playing::updateState()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		m_gameStateManager.setGameState(GameStateId::Pause);
	}
	if (m_GameWorld->getGameOverCondition())
	{
		m_gameStateManager.setGameState(GameStateId::GameOver);
	}
}

void GameState_Playing::update(sf::RenderWindow* window, float DeltaTime)
{
	if (m_gameStateManager.getIsFirstEntry() && !m_gameStateManager.getIsNewGame())
	{
		std::vector<std::string> saveData = m_gameStateManager.getSaveData();
		m_GameWorld->loadGame(saveData);
		m_gameStateManager.changeIsFirstEntry();
	}
	else if(m_gameStateManager.getIsNewGame())
	{
		m_GameWorld->startNewGame(window);
		m_gameStateManager.changeIsNewGame();
	}
	
	m_GameWorld->update(DeltaTime);
	m_GameWorld->eraseObjects(window);
	m_GameWorld->createGameObjects(window);
	m_GameWorld->proccesGameOverCondition(window);
}

void GameState_Playing::draw(sf::RenderWindow* window)
{
	m_GameWorld->draw(window);
}

void GameState_Playing::saveGame()
{
	m_gameStateManager.saveGame(m_GameWorld->getGameData());
}

void GameState_MainMenu::onEnter()
{
	SoundManager::getInstance().playMainMenu();
	if (m_gameStateManager.getIsFirstEntry())
	{
		m_gameStateManager.loadSave();
	}
	m_menu->clearButtons();
	m_menu->setMenuState(MenuState::MainMenu);
}

void GameState_MainMenu::updateState()
{
	if (m_menu->getPlayButtonPressed())
	{
		m_gameStateManager.changeIsNewGame();
		if (m_gameStateManager.getIsFirstEntry())
		{
			m_gameStateManager.changeIsFirstEntry();
		}
		SoundManager::getInstance().stopMainMenu();
		m_gameStateManager.setGameState(GameStateId::Playing);
	}
	if (m_menu->getContinueButtonPressed())
	{
		if (m_gameStateManager.getIsFirstEntry() && m_gameStateManager.getIsSaveValid() || !m_gameStateManager.getIsFirstEntry())
		{
			m_gameStateManager.setGameState(GameStateId::Playing);
			SoundManager::getInstance().stopMainMenu();
		}
		
	}
}


void GameState_MainMenu::update(sf::RenderWindow* window, float DeltaTime)
{
	m_menu->update(window);
}

void GameState_MainMenu::draw(sf::RenderWindow* window)
{
	m_menu->draw(window);
}

void GameState_MainMenu::saveGame()
{
	if (!m_gameStateManager.getIsFirstEntry())
	{
		m_gameStateManager.setGameState(GameStateId::Playing);
		m_gameStateManager.getCurrentGameState()->saveGame();
	}
}

void GameState_Pause::onEnter()
{
	SoundManager::getInstance().pauseGameSound();
	m_menu->setMenuState(MenuState::PauseMenu);
	m_menu->clearButtons();
}

void GameState_Pause::updateState()
{
	if (m_menu->getResumeButtonPressed())
	{
		m_gameStateManager.setGameState(GameStateId::Playing);
	}
	if(m_menu->getMainMenuButton())
	{
		m_gameStateManager.setGameState(GameStateId::MainMenu);
		m_menu->clearButtons();
	}
}

void GameState_Pause::update(sf::RenderWindow* window, float DeltaTime)
{
	m_menu->update(window);
}

void GameState_Pause::draw(sf::RenderWindow* window)
{
	m_menu->draw(window);
}

void GameState_Pause::saveGame()
{
	m_gameStateManager.setGameState(GameStateId::Playing);
	m_gameStateManager.getCurrentGameState()->saveGame();
}

void GameState_GameOver::onEnter()
{
	SoundManager::getInstance().resetGameSound();
	m_gameStateManager.setHighScore(m_GameWorld->getHighScore());
	m_menu->clearButtons();
	m_menu->setMenuState(MenuState::GameOverMenu);
}

void GameState_GameOver::updateState()
{
	if (m_menu->getRestratButtonPressed())
	{
		m_gameStateManager.changeIsNewGame();
		m_gameStateManager.setGameState(GameStateId::Playing);
	}
}

void GameState_GameOver::update(sf::RenderWindow* window, float DeltaTime)
{
	m_menu->update(window);
}

void GameState_GameOver::draw(sf::RenderWindow* window)
{
	m_menu->draw(window);
}

void GameState_GameOver::saveGame()
{
	std::vector < std::string> highScoreData;
	highScoreData.push_back(std::to_string(m_GameWorld->getHighScore()));
	m_gameStateManager.saveGame(highScoreData);
}
