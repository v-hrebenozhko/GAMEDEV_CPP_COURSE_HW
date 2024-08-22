#pragma once
#include "GameObjects.h"
#include "Modifier.h"
#include "NPC.h"
#include "Platform.h"
//#include <iostream>

class GameObjectFactory
{
public:
	GameObjectFactory() = default;
	GameObjectFactory(sf::RenderWindow* window);
	void resetGameObjectFactory();
	void generateInitGameObjects(std::vector<std::unique_ptr<GameObject>>& objects, sf::RenderWindow* window, int number);
	void generateGameObjects(std::vector<std::unique_ptr<GameObject>>& objects, sf::RenderWindow* window, int currentHeight);
	void generateLoadedGameObjects(const std::vector<std::string>& saveData, std::vector<std::unique_ptr<GameObject>>& objects);
	const unsigned int getDifficulty() const { return m_difficulty; }
	void setDifficulty(unsigned int difficulty) { m_difficulty = difficulty; }
	
private:
	bool rollChance(float Percent);
	float generateRandomFloatInRange(float min,float max) {return min + (std::rand() / (RAND_MAX + 1.0)) * (max - min);}
	sf::Vector2f getRandomValidPosition(sf::RenderWindow* window, sf::Vector2f lastPlatformPosition);
	sf::Vector2f getRandomValidPositionFromObject(sf::RenderWindow* window, sf::Vector2f lastPlatformPosition, std::unique_ptr<GameObject>& object);
	void setOnPlatform(sf::Vector2f lastPlatformPosition, std::unique_ptr<GameObject>& gameObject);

	void generateRandomPlatform(std::vector<std::unique_ptr<GameObject>>& objects, sf::RenderWindow* window);
	void generateRandomNonPlatformObject(std::vector<std::unique_ptr<GameObject>>& objects, sf::RenderWindow* window);
	void initDifficulty();
	void switchDifficulty(int currentHeight);

	
	std::unique_ptr<GameObject> generateGameObjectByString(const std::string& str)
	{
		if (str == "Platform")
		{
			return generateSimplePlatform();
		}
		else if (str == "MovingPlatform")
		{
			return generateMovingPlatform();
		}
		else if (str == "SpringPlatform")
		{
			return generateSpringPlatform();
		}
		else if (str == "OneCollisionPlatform")
		{
			return generateOneCollisionPlatform();
		}
		else if (str == "FakePlatform")
		{
			return generateFakePlatform();
		}
		else if (str == "HelicopterModifier")
		{
			return generateHelicopter();
		}
		else if (str == "RocketModifier")
		{
			return generateRocket();
		}
		else if (str == "FloatingNPC")
		{
			return generateFloatingNPC();
		}
		else if (str == "StaticNPC")
		{
			return generateStaticNPC();
		}
		else if (str == "BigStaticNPC")
		{
			return generateBigStaticNPC();
		}
		else
		{
			return nullptr;
		}
	}
	
	std::unique_ptr<GameObject> generateSimplePlatform() {return std::make_unique<Platform>(m_SimplePlatformTextue);}
	std::unique_ptr<GameObject> generateMovingPlatform() {return std::make_unique <MovingPlatform>(m_movingPlatformTexture);}
	std::unique_ptr<GameObject> generateSpringPlatform() {return std::make_unique<SpringPlatform>(m_SpringPlatformTexture);}
	std::unique_ptr<GameObject> generateOneCollisionPlatform() {return std::make_unique<OneCollisionPlatform>(m_oneCollisionPlatformTexture);}
	std::unique_ptr<GameObject> generateFakePlatform() {return std::make_unique<FakePlatform>(m_fakePlatformTexture);}

	std::unique_ptr<GameObject> generateHelicopter() {return std::make_unique<HelicopterModifier>(m_helicopterTexture);}
	std::unique_ptr<GameObject> generateRocket() {return std::make_unique<RocketModifier>(m_rocketFlightTexture);}

	std::unique_ptr<GameObject> generateFloatingNPC() {return std::make_unique<FloatingNPC>(m_floatingNPCTexture);}
	std::unique_ptr<GameObject> generateStaticNPC() {return std::make_unique<StaticNPC>(m_staticNPCTecture);}
	std::unique_ptr<GameObject> generateBigStaticNPC( ){return std::make_unique<BigStaticNPC>(m_bigStaticNPCTexture);}

private:
	bool isNonPlatformObjectGenerated;
	bool isSimplePlatformGenerated;
	int m_prevHeight = 0;
	int m_difficultyHeightGap = 3000;
	int m_difficulty = 1;
	int m_maxDifficulty = 5;

	sf::Vector2f m_prevPlatformPosition;
	sf::Texture m_SimplePlatformTextue;
	sf::Texture m_SpringPlatformTexture;
	sf::Texture m_oneCollisionPlatformTexture;
	sf::Texture m_fakePlatformTexture;

	sf::Texture m_helicopterTexture;
	sf::Texture m_rocketFlightTexture;

	sf::Texture m_staticNPCTecture;
	sf::Texture m_bigStaticNPCTexture;
	sf::Texture m_floatingNPCTexture;
	sf::Texture m_movingPlatformTexture;

	float m_platformHeight;
	float m_PlatformWidth;

	float m_maxWidthPlatformGap;
	float m_maxHeightPlatformGap;
	float m_minWidthPlatformGap;
	float m_minHeightPlatformGap;

	float m_springPlatformSpawnChance = 0.0f;
	float m_movingPlatformSpawnChance = 0.0f;
	float m_fakePlatformSpawnChance = 0.0f;
	float m_oneCollisionPlatformSpawnChance = 0.0f;

	float m_staticNPCSpawnChance = 0.0f;
	float m_bigStaticNPCSpawnChance = 0.0f;
	float m_floatingNPCSpawnChance = 0.0f;

	float m_helicopterModifierSpawnChance = 0.0f;
	float m_rocketModifierSpawnChance = 0.0f;
};