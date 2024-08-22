#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "GameObjectsFactory.h"
#include "Player.h"
#include "assert.h"
#include <memory>

class GameWorld
{
public:
	static void createInstance(sf::RenderWindow* window)
	{
		ms_gameWorld = new GameWorld(window);
	}

	static void destroyInstance()
	{
		delete ms_gameWorld;
	}

	void PostInit();

	static GameWorld* Instance()
	{
		assert(ms_gameWorld && "GameWorld Instance wasn't properly created!");
		return ms_gameWorld;
	}

	~GameWorld(); 

	void createGameObjects(sf::RenderWindow* window)
	{
		m_gameObjectsFactory.generateGameObjects(m_gameObjects, window,m_currentHeightCounter);
		m_prevHeightCounter = m_currentHeightCounter;
	}
	void proccesGameOverCondition(sf::RenderWindow* window);
	void applyCollisionEffect(CollisionEffect collisionEffect);
	void proccesCollisions();
	void update(float DeltaTime);
	void draw(sf::RenderWindow* window);
	void eraseObjects(sf::RenderWindow* window);
	void startNewGame(sf::RenderWindow* window)
	{
		SoundManager::getInstance().resetGameSound();
		m_speed = 750;
		m_isWorldFalling = false;
		m_gameOverCondition = false;
		m_prevHeightCounter = 0;
		m_currentHeightCounter = 0;
		player.setPosition(playerStartPosition);
		player.resetPlayer();
		m_gameObjectsFactory.resetGameObjectFactory();
		m_gameObjects.clear();
		m_gameObjectsFactory.generateInitGameObjects(m_gameObjects, window, 30);
	}
	std::vector<std::string> getGameData()
	{
		std::vector<std::string> gameData;
		gameData.push_back(std::to_string(m_highScore) + ";\n");
		gameData.push_back(std::to_string(m_currentHeightCounter) + ";\n");
		gameData.push_back(std::to_string(m_gameObjectsFactory.getDifficulty()) + ";\n");
		gameData.push_back(player.getStringObjectData() + "\n");
		for (std::unique_ptr<GameObject>& object : m_gameObjects)
		{
			gameData.push_back(object->getStringObjectData() + "\n");
		}
		return gameData;
	}
	void loadGame(const std::vector<std::string>& saveData)
	{
		m_speed = 750;
		m_isWorldFalling = false;
		m_gameOverCondition = false;
		m_prevHeightCounter = 0;
		m_currentHeightCounter = 0;
		player.resetPlayer();
		m_gameObjects.clear();
		m_highScore = std::stoi(saveData[0]);
		m_currentHeightCounter = std::stoi(saveData[1]);
		m_gameObjectsFactory.setDifficulty(std::stoi(saveData[2]));
		player.setPosition(sf::Vector2f{ std::stof(saveData[3]),std::stof(saveData[4]) });
		m_gameObjectsFactory.generateLoadedGameObjects(saveData, m_gameObjects);
	}
	void setHighScore(unsigned int highScore) { m_highScore = highScore; }
	unsigned int getHighScore() { return m_highScore; }

	bool getGameOverCondition() const { return m_gameOverCondition; }
	
	Player& GetPlayer() { return player; }

private:
	GameWorld(sf::RenderWindow* window);

	
	Player player;
	sf::Vector2f playerStartPosition;

	sf::Texture m_backgroundTexture;
	sf::Sprite m_backgroundSprite;

	bool m_isWorldFalling;
	bool m_gameOverCondition = false;
	float m_speed;
	float m_windowXBound;
	unsigned int m_highScore;
	unsigned int m_currentHeightCounter;
	unsigned int m_prevHeightCounter;
	float m_heightLine;

	GameObjectFactory m_gameObjectsFactory;

	std::vector<std::unique_ptr<GameObject>> m_gameObjects;

	

	sf::Font m_font;
	sf::Text m_text;
	sf::Text m_highScoreText;

	static GameWorld* ms_gameWorld;
};
