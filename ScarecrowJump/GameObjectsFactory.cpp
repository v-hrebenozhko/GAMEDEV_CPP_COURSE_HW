#include "GameObjectsFactory.h"

GameObjectFactory::GameObjectFactory(sf::RenderWindow* window)
{
	isNonPlatformObjectGenerated = false;

	m_SimplePlatformTextue.loadFromFile("SimplePlatform.png");
	m_SpringPlatformTexture.loadFromFile("SpringPlatform.png");
	m_helicopterTexture.loadFromFile("Helicopter.png");
	m_rocketFlightTexture.loadFromFile("Rocket.png");
	m_floatingNPCTexture.loadFromFile("FloatingNPC.png");
	m_movingPlatformTexture.loadFromFile("MovingPlatform.png");
	m_staticNPCTecture.loadFromFile("StaticNPC.png");
	m_bigStaticNPCTexture.loadFromFile("BigStaticNPC.png");
	m_fakePlatformTexture.loadFromFile("FakePlatform.png");
	m_oneCollisionPlatformTexture.loadFromFile("OneCollisionPlatform.png");
	Platform platform(m_SimplePlatformTextue);

	m_PlatformWidth = platform.getPlatformWidth();
	m_platformHeight = platform.getPlatformHeight();
}

void GameObjectFactory::resetGameObjectFactory()
{
	m_difficulty = 1;
	m_prevHeight = 0;

	m_minHeightPlatformGap = m_platformHeight;
	m_minWidthPlatformGap = m_PlatformWidth / 10.0f;
	m_maxHeightPlatformGap = m_platformHeight * 2;
	m_maxWidthPlatformGap = m_PlatformWidth;

	m_springPlatformSpawnChance = 10.0f;
	m_movingPlatformSpawnChance = 0.0f;
	m_fakePlatformSpawnChance = 5.0f;
	m_oneCollisionPlatformSpawnChance = 0.0f;

	m_staticNPCSpawnChance = 0.0f;
	m_bigStaticNPCSpawnChance = 0.0f;
	m_floatingNPCSpawnChance = 0.0f;

	m_helicopterModifierSpawnChance = 1.0f;
	m_rocketModifierSpawnChance = 0.5f;
}

void GameObjectFactory::generateInitGameObjects(std::vector<std::unique_ptr<GameObject>>& objects, sf::RenderWindow* window, int number)
{
	sf::Vector2f m_startObjectsPosition = { generateRandomFloatInRange(0,window->getSize().x), static_cast<float>(window->getSize().y) };
	for (int i = 0; i < number; i++)
	{

		m_startObjectsPosition = getRandomValidPosition(window, m_startObjectsPosition);
		objects.push_back(generateSimplePlatform());
		objects[objects.size() - 1]->setPosition(m_startObjectsPosition);

	}
}

void GameObjectFactory::generateGameObjects(std::vector<std::unique_ptr<GameObject>>& objects, sf::RenderWindow* window, int currentHeight)
{

	switchDifficulty(currentHeight);
	if (objects[objects.size() - 1]->getPosition().y > 0 - m_maxHeightPlatformGap)
	{
		generateRandomPlatform(objects, window);
		generateRandomNonPlatformObject(objects, window);
	}
}

void GameObjectFactory::generateLoadedGameObjects(const std::vector<std::string>& saveData, std::vector<std::unique_ptr<GameObject>>& objects)
{
	initDifficulty();

	sf::Vector2f pos;
	int counter = 0;
	for (int i = 5; i < saveData.size(); i++)
	{
		if (counter == 0)
		{
			objects.push_back(generateGameObjectByString(saveData[i]));
			counter++;
		}
		else if (counter == 1)
		{
			pos.x = std::stof(saveData[i]);
			counter++;
		}
		else
		{
			pos.y = std::stof(saveData[i]);
			objects[objects.size() - 1]->setPosition(pos);
			counter = 0;
		}
	}
}

bool GameObjectFactory::rollChance(float Percent)
{
	float randomValue = static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX);
	return randomValue <= (Percent / 100.0f);
}

sf::Vector2f GameObjectFactory::getRandomValidPosition(sf::RenderWindow* window, sf::Vector2f lastPlatformPosition)
{
	float x;
	float y;
	if (rollChance(50))
	{
		x = generateRandomFloatInRange(lastPlatformPosition.x - m_minWidthPlatformGap - m_maxWidthPlatformGap, lastPlatformPosition.x - m_minWidthPlatformGap);
		if (x < 0 + m_PlatformWidth / 2)
		{
			x = window->getSize().x + x;
			if (x > window->getSize().x - m_PlatformWidth / 2)
			{
				x = window->getSize().x - m_PlatformWidth;
			}
		}
	}
	else
	{
		x = generateRandomFloatInRange(lastPlatformPosition.x + m_minWidthPlatformGap + m_maxWidthPlatformGap, lastPlatformPosition.x + m_minWidthPlatformGap);
		if (x > window->getSize().x - m_PlatformWidth / 2)
		{
			x = x - window->getSize().x;
			if (x < m_PlatformWidth / 2)
			{
				x = m_PlatformWidth / 2;
			}
		}
	}
	y = generateRandomFloatInRange(lastPlatformPosition.y - m_minHeightPlatformGap - m_maxHeightPlatformGap, lastPlatformPosition.y - m_minHeightPlatformGap);
	sf::Vector2f pos = { x,y };
	return pos;
}

sf::Vector2f GameObjectFactory::getRandomValidPositionFromObject(sf::RenderWindow* window, sf::Vector2f lastPlatformPosition, std::unique_ptr<GameObject>& object)
{
	float x;
	float y;
	float minHeightPlatformGap;
	if (lastPlatformPosition.y -object->getPosition().y + m_platformHeight  > m_minHeightPlatformGap)
	{
		minHeightPlatformGap = lastPlatformPosition.y - object->getPosition().y ;
	}
	else
	{
		minHeightPlatformGap = m_minHeightPlatformGap;
	}

	if (rollChance(50))
	{
		x = generateRandomFloatInRange(lastPlatformPosition.x - m_minWidthPlatformGap - m_maxWidthPlatformGap, lastPlatformPosition.x - m_minWidthPlatformGap);
		if (x < 0 + m_PlatformWidth / 2)
		{
			x = window->getSize().x + x;
			if (x > window->getSize().x - m_PlatformWidth / 2)
			{
				x = window->getSize().x - m_PlatformWidth;
			}
		}
	}
	else
	{
		x = generateRandomFloatInRange(lastPlatformPosition.x + m_minWidthPlatformGap + m_maxWidthPlatformGap, lastPlatformPosition.x + m_minWidthPlatformGap);
		if (x > window->getSize().x - m_PlatformWidth / 2)
		{
			x = x - window->getSize().x;
			if (x < m_PlatformWidth / 2)
			{
				x = m_PlatformWidth / 2;
			}
		}
	}
	y = generateRandomFloatInRange(lastPlatformPosition.y - minHeightPlatformGap - m_maxHeightPlatformGap, lastPlatformPosition.y - minHeightPlatformGap);
	sf::Vector2f pos = { x,y };
	return pos;
}

void GameObjectFactory::generateRandomPlatform(std::vector<std::unique_ptr<GameObject>>& objects, sf::RenderWindow* window)
{
	sf::Vector2f randomValidPosition;
	isSimplePlatformGenerated = false;
	if (isNonPlatformObjectGenerated)
	{
		randomValidPosition = getRandomValidPositionFromObject(window, objects[objects.size() - 2]->getPosition(), objects[objects.size() - 1]);
	}
	else
	{
		randomValidPosition = getRandomValidPosition(window, objects[objects.size() - 1]->getPosition());
	}
	if (rollChance(m_movingPlatformSpawnChance))
	{
		objects.push_back(generateMovingPlatform());
	}
	else if (rollChance(m_oneCollisionPlatformSpawnChance))
	{
		objects.push_back(generateOneCollisionPlatform());
	}
	else
	{
		isSimplePlatformGenerated = true;
		objects.push_back(generateSimplePlatform());
	}
	objects[objects.size() - 1]->setPosition(randomValidPosition);
}

void GameObjectFactory::generateRandomNonPlatformObject(std::vector<std::unique_ptr<GameObject>>& objects, sf::RenderWindow* window)
{

	isNonPlatformObjectGenerated = true;
	sf::Vector2f randomPosition = getRandomValidPosition(window, objects[objects.size() - 1]->getPosition());
	if (rollChance(m_springPlatformSpawnChance) && isSimplePlatformGenerated)
	{
		objects.push_back(generateSpringPlatform());
		setOnPlatform(objects[objects.size() - 2]->getPosition(), objects[objects.size() - 1]);
	}
	else if (rollChance(m_fakePlatformSpawnChance))
	{
		objects.push_back(generateFakePlatform());
		objects[objects.size() - 1]->setPosition(randomPosition);
	}
	else if (rollChance(m_helicopterModifierSpawnChance) && isSimplePlatformGenerated)
	{
		objects.push_back(generateHelicopter());
		setOnPlatform(objects[objects.size() - 2]->getPosition(), objects[objects.size() - 1]);
	}
	else if (rollChance(m_rocketModifierSpawnChance) && isSimplePlatformGenerated)
	{
		objects.push_back(generateRocket());
		setOnPlatform(objects[objects.size() - 2]->getPosition(), objects[objects.size() - 1]);
	}
	else if (rollChance(m_staticNPCSpawnChance))
	{
		objects.push_back(generateStaticNPC());
		objects[objects.size() - 1]->setPosition(randomPosition);
	}
	else if (rollChance(m_bigStaticNPCSpawnChance))
	{
		objects.push_back(generateBigStaticNPC());
		objects[objects.size() - 1]->setPosition(randomPosition);
	}
	else if (rollChance(m_floatingNPCSpawnChance))
	{
		objects.push_back(generateFloatingNPC());
		objects[objects.size() - 1]->setPosition(randomPosition);
	}
	else
	{
		isNonPlatformObjectGenerated = false;
	}
}

void GameObjectFactory::switchDifficulty(int currentHeight)
{

	if (currentHeight > m_prevHeight + m_difficultyHeightGap && m_difficulty != m_maxDifficulty)
	{
		if (m_difficulty <= m_maxDifficulty)
		{
			m_difficulty++;
		}
		m_prevHeight = currentHeight;

		switch (m_difficulty)
		{
		case 1:
		{
			m_minHeightPlatformGap = m_platformHeight;
			m_minWidthPlatformGap = m_PlatformWidth / 10.0f;
			m_maxHeightPlatformGap = m_platformHeight * 2;
			m_maxWidthPlatformGap = m_PlatformWidth/5.0f;

			m_springPlatformSpawnChance = 10.0f;
			m_movingPlatformSpawnChance = 0.0f;
			m_fakePlatformSpawnChance = 5.0f;
			m_oneCollisionPlatformSpawnChance = 0.0f;

			m_staticNPCSpawnChance = 0.0f;
			m_bigStaticNPCSpawnChance = 0.0f;
			m_floatingNPCSpawnChance = 0.0f;

			m_helicopterModifierSpawnChance = 1.0f;
			m_rocketModifierSpawnChance = 0.5f;
			break;
		}
		case 2:
		{
			m_maxWidthPlatformGap = m_PlatformWidth * 1.8f;
			m_maxHeightPlatformGap = m_platformHeight / 4.0f;
			m_minWidthPlatformGap = m_PlatformWidth / 8.0f;
			m_minHeightPlatformGap = m_platformHeight * 1.5f;

			m_springPlatformSpawnChance = 4.0f;
			m_movingPlatformSpawnChance = 1.0f;
			m_fakePlatformSpawnChance = 8.0f;
			m_oneCollisionPlatformSpawnChance = 0;

			m_staticNPCSpawnChance = 0.5f;
			m_bigStaticNPCSpawnChance = 0.1f;
			m_floatingNPCSpawnChance = 0.1f;

			m_helicopterModifierSpawnChance = 5.0f;
			m_rocketModifierSpawnChance = 5.0f;
			break;
		}
		case 3:
		{
			m_maxWidthPlatformGap = m_PlatformWidth / 2.0f;
			m_maxHeightPlatformGap = m_platformHeight * 2.5f;
			m_minWidthPlatformGap = m_PlatformWidth / 4.0f;
			m_minHeightPlatformGap = m_platformHeight * 2.0f;

			m_springPlatformSpawnChance = 3.0f;
			m_movingPlatformSpawnChance = 2.0f;
			m_fakePlatformSpawnChance = 5.0f;
			m_oneCollisionPlatformSpawnChance = 0.1f;

			m_staticNPCSpawnChance = 0.8f;
			m_bigStaticNPCSpawnChance = 0.4f;
			m_floatingNPCSpawnChance = 0.2f;

			m_helicopterModifierSpawnChance = 2.0f;
			m_rocketModifierSpawnChance = 1.0f;
			break;
		}
		case 4:
		{
			m_maxWidthPlatformGap = m_PlatformWidth;
			m_maxHeightPlatformGap = m_platformHeight * 2.2f;
			m_minWidthPlatformGap = m_PlatformWidth/2;
			m_minHeightPlatformGap = m_platformHeight * 2.2f;

			m_springPlatformSpawnChance = 3.0f;
			m_movingPlatformSpawnChance = 5.0f;
			m_fakePlatformSpawnChance = 5.0f;
			m_oneCollisionPlatformSpawnChance = 2.0f;

			m_staticNPCSpawnChance = 1.2f;
			m_bigStaticNPCSpawnChance = 0.8f;
			m_floatingNPCSpawnChance = 0.6;

			m_helicopterModifierSpawnChance = 2.0f;
			m_rocketModifierSpawnChance = 1.0f;
			break;
		}
		case 5:
		{
			m_maxWidthPlatformGap = m_PlatformWidth * 1.5f;
			m_maxHeightPlatformGap = m_platformHeight * 2.2f;
			m_minWidthPlatformGap = m_PlatformWidth ;
			m_minHeightPlatformGap = m_platformHeight * 2.2f;

			m_springPlatformSpawnChance = 3.0f;
			m_movingPlatformSpawnChance = 15.0f;
			m_fakePlatformSpawnChance = 3.0f;
			m_oneCollisionPlatformSpawnChance = 5.0f;

			m_staticNPCSpawnChance = 1.5f;
			m_bigStaticNPCSpawnChance = 1.2;
			m_floatingNPCSpawnChance = 1.0f;

			m_helicopterModifierSpawnChance = 2.0f;
			m_rocketModifierSpawnChance = 1.0f;
			break;
		}
		}
	}
}


void GameObjectFactory::initDifficulty()
{
	switch (m_difficulty)
	{
	case 1:
	{
		m_maxWidthPlatformGap = m_PlatformWidth * 1.5f;
		m_maxHeightPlatformGap = m_platformHeight * 5.0f;
		m_minWidthPlatformGap = m_PlatformWidth / 5.0f;
		m_minHeightPlatformGap = m_platformHeight * 2.0f;

		m_springPlatformSpawnChance = 10.0f;
		m_movingPlatformSpawnChance = 0.0f;
		m_fakePlatformSpawnChance = 5.0f;
		m_oneCollisionPlatformSpawnChance = 0.0f;

		m_staticNPCSpawnChance = 0.0f;
		m_bigStaticNPCSpawnChance = 0.0f;
		m_floatingNPCSpawnChance = 0.0f;

		m_helicopterModifierSpawnChance = 1.0f;
		m_rocketModifierSpawnChance = 0.5f;
		break;
	}
	case 2:
	{
		m_maxWidthPlatformGap = m_PlatformWidth * 1.8f;
		m_maxHeightPlatformGap = m_platformHeight * 5.0f;
		m_minWidthPlatformGap = m_PlatformWidth / 4.0f;
		m_minHeightPlatformGap = m_platformHeight * 2.0f;

		m_springPlatformSpawnChance = 4.0f;
		m_movingPlatformSpawnChance = 1.0f;
		m_fakePlatformSpawnChance = 8.0f;
		m_oneCollisionPlatformSpawnChance = 0;

		m_staticNPCSpawnChance = 0.5f;
		m_bigStaticNPCSpawnChance = 0.1f;
		m_floatingNPCSpawnChance = 0.1f;

		m_helicopterModifierSpawnChance = 5.0f;
		m_rocketModifierSpawnChance = 5.0f;
		break;
	}
	case 3:
	{
		m_maxWidthPlatformGap = m_PlatformWidth * 2.0f;
		m_maxHeightPlatformGap = m_platformHeight * 6.0f;
		m_minWidthPlatformGap = m_PlatformWidth / 2.0f;
		m_minHeightPlatformGap = m_platformHeight * 3.0f;

		m_springPlatformSpawnChance = 3.0f;
		m_movingPlatformSpawnChance = 2.0f;
		m_fakePlatformSpawnChance = 5.0f;
		m_oneCollisionPlatformSpawnChance = 0.1f;

		m_staticNPCSpawnChance = 0.8f;
		m_bigStaticNPCSpawnChance = 0.4f;
		m_floatingNPCSpawnChance = 0.2f;

		m_helicopterModifierSpawnChance = 2.0f;
		m_rocketModifierSpawnChance = 1.0f;
		break;
	}
	case 4:
	{
		m_maxWidthPlatformGap = m_PlatformWidth * 2.5f;
		m_maxHeightPlatformGap = m_platformHeight * 7.0f;
		m_minWidthPlatformGap = m_PlatformWidth;
		m_minHeightPlatformGap = m_platformHeight * 4.0f;

		m_springPlatformSpawnChance = 3.0f;
		m_movingPlatformSpawnChance = 5.0f;
		m_fakePlatformSpawnChance = 5.0f;
		m_oneCollisionPlatformSpawnChance = 2.0f;

		m_staticNPCSpawnChance = 1.2f;
		m_bigStaticNPCSpawnChance = 0.8f;
		m_floatingNPCSpawnChance = 0.6;

		m_helicopterModifierSpawnChance = 2.0f;
		m_rocketModifierSpawnChance = 1.0f;
		break;
	}
	case 5:
	{
		m_maxWidthPlatformGap = m_PlatformWidth * 2.5f;
		m_maxHeightPlatformGap = m_platformHeight * 8.0f;
		m_minWidthPlatformGap = m_PlatformWidth * 2.0f;
		m_minHeightPlatformGap = m_platformHeight * 7.0f;

		m_springPlatformSpawnChance = 3.0f;
		m_movingPlatformSpawnChance = 10.0f;
		m_fakePlatformSpawnChance = 3.0f;
		m_oneCollisionPlatformSpawnChance = 4.0f;

		m_staticNPCSpawnChance = 1.5f;
		m_bigStaticNPCSpawnChance = 1.2;
		m_floatingNPCSpawnChance = 1.0f;

		m_helicopterModifierSpawnChance = 2.0f;
		m_rocketModifierSpawnChance = 1.0f;
		break;
	}
	case 6:
	{
		m_maxWidthPlatformGap = m_PlatformWidth * 3.5f;
		m_maxHeightPlatformGap = m_platformHeight * 8.0f;
		m_minWidthPlatformGap = m_PlatformWidth * 2.2f;
		m_minHeightPlatformGap = m_platformHeight * 8.0f;

		m_springPlatformSpawnChance = 5.0f;
		m_movingPlatformSpawnChance = 0.0f;
		m_fakePlatformSpawnChance = 0.0f;
		m_oneCollisionPlatformSpawnChance = 0;

		m_staticNPCSpawnChance = 0;
		m_bigStaticNPCSpawnChance = 0;
		m_floatingNPCSpawnChance = 0;

		m_helicopterModifierSpawnChance = 0;
		m_rocketModifierSpawnChance = 0;
		break;
	}
	}
}


void GameObjectFactory::setOnPlatform(sf::Vector2f lastPlatformPosition, std::unique_ptr<GameObject>& gameObject)
{

	sf::Vector2f pos = { generateRandomFloatInRange(lastPlatformPosition.x - m_PlatformWidth / 2 + gameObject->getSize().x / 2
		,lastPlatformPosition.x + m_PlatformWidth / 2 - gameObject->getSize().x / 2), lastPlatformPosition.y - gameObject->getSprite()->getLocalBounds().height - m_platformHeight};
	gameObject->setPosition(pos);
}
