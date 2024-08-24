#include "GameWorld.h"
#include "GameObjects.h"
#include "FontManager.h"

GameWorld* GameWorld::ms_gameWorld = nullptr;

GameWorld::GameWorld(sf::RenderWindow* window)
{

    m_backgroundTexture.loadFromFile("PlayingBackGround.jpg");
    m_backgroundSprite.setTexture(m_backgroundTexture);

    playerStartPosition = { window->getSize().x * 0.3f,0 };
    m_windowXBound = window->getSize().x;
    m_heightLine = window->getSize().y * 0.4;

    m_text.setFont(FontManager::getInstance().getDefaultFont());

    m_text.setCharacterSize(48); // in pixels, not points!
    m_text.setFillColor(sf::Color::White);

    m_highScoreText.setFont(FontManager::getInstance().getDefaultFont());

    m_highScoreText.setCharacterSize(48); // in pixels, not points!
    m_highScoreText.setFillColor(sf::Color::White);
    m_highScoreText.setPosition(0, window->getSize().y * 0.05f);

    m_gameObjectsFactory = GameObjectFactory(window);
    
}

void GameWorld::PostInit()
{
  
}

GameWorld::~GameWorld()
{
    //TODO, Bohdan: Delete memory used
}

void GameWorld::createGameObjects(sf::RenderWindow* window)
{
    m_gameObjectsFactory.generateGameObjects(m_gameObjects, window, m_currentHeightCounter);
}

void GameWorld::proccesGameOverCondition(sf::RenderWindow* window)
{
    if (player.getPosition().y > window->getSize().y)
    {
        m_gameOverCondition = true;
    }
}



void GameWorld::applyCollisionEffect(CollisionEffect collisionEffect)
{
    switch (collisionEffect)
    {
    case CollisionEffect::Jump:
    {
        player.Jump();
        break;
    }
    case CollisionEffect::DoubleJump:
    {
        player.doubleJump();
        break;
    }
    case CollisionEffect::HelicopterFlight:
    {
        player.helicopterFlight();
        break;
    }
    case CollisionEffect::RocketFlight:
    {
        player.rocketFlight();
        break;
    }
    case CollisionEffect::GameOver:
    {
        m_gameOverCondition = true;
        break;
    }
    }
}

void GameWorld::proccesCollisions()
{
    for (std::unique_ptr<GameObject>& gameObject : m_gameObjects)
    {
        if (gameObject->checkCollision(player))
        {
            applyCollisionEffect(gameObject->getCollisionEffect());
        }
    }
}

void GameWorld::proccesProjectiles(float deltaTime)
{
    m_gameObjectsFactory.generateProjectile(m_projectiles, player);
    for (std::unique_ptr<Projectile>& projectile : m_projectiles)
    {
        projectile.get()->update(deltaTime, m_isWorldFalling, m_speed, m_windowXBound);
        for (std::unique_ptr<GameObject>& object : m_gameObjects)
        {
            projectile.get()->checkIsAimed(object);
        }
    }
}


void GameWorld::update(float DeltaTime)
{
    if (m_currentHeightCounter > m_highScore)
    {
        m_highScore = m_currentHeightCounter;
    }
    if (player.getPosition().y < m_heightLine && !player.getIsFalling())
    {
        m_isWorldFalling = true;
        m_currentHeightCounter++;
    }
    else
    {
        m_isWorldFalling = false;
    }

    player.update(DeltaTime, m_isWorldFalling,m_speed,m_windowXBound);
    m_speed = player.getSpeed();

    for (std::unique_ptr<GameObject>& object : m_gameObjects)
    {
        object->update(DeltaTime,m_isWorldFalling,m_speed,m_windowXBound);
        if (object->checkCollision(player))
        {
            applyCollisionEffect(object->getCollisionEffect());
        }
    }

    proccesProjectiles(DeltaTime);

    m_text.setString("HeightCounter: " + std::to_string(m_currentHeightCounter) );
    m_highScoreText.setString("HighScore: " + std::to_string(m_highScore));
}

void GameWorld::draw(sf::RenderWindow* window)
{
    window->clear();
    window->draw(m_backgroundSprite);

    for (std::unique_ptr<GameObject>& object : m_gameObjects)
    {
        object->draw(window);
    }
    for (std::unique_ptr<Projectile>& projectile : m_projectiles)
    {
        projectile->draw(window);
    }
    window->draw(m_text);
    window->draw(m_highScoreText);
    player.draw(window);
}

void GameWorld::eraseObjects(sf::RenderWindow* window)
{
    float MaxY = window->getSize().y;
    m_gameObjects.erase(
        std::remove_if(m_gameObjects.begin(), m_gameObjects.end(), [MaxY](const std::unique_ptr<GameObject>& obj)
    {
        return obj->getPosition().y > MaxY || obj->getIsDestroyed();
    }
        ),
        m_gameObjects.end());

    m_projectiles.erase(std::remove_if(m_projectiles.begin(), m_projectiles.end(), [](const std::unique_ptr<Projectile>& projectile)
    {
        return projectile->getIsDestroyed();
    }), m_projectiles.end());
}

void GameWorld::startNewGame(sf::RenderWindow* window)
{
    SoundManager::getInstance().resetGameSound();

    m_isWorldFalling = false;
    m_gameOverCondition = false;

    m_currentHeightCounter = 0;

    player.resetPlayer();
    m_gameObjectsFactory.resetGameObjectFactory();
    m_gameObjects.clear();
    m_projectiles.clear();

    m_gameObjectsFactory.generateInitGameObjects(m_gameObjects, window, 30);

    player.setPosition(playerStartPosition);
}

void GameWorld::loadGame(const std::vector<std::string>& saveData)
{
    m_isWorldFalling = false;
    m_gameOverCondition = false;
    player.resetPlayer();
    player.setPosition(sf::Vector2f{ std::stof(saveData[3]),std::stof(saveData[4]) });

    m_highScore = std::stoi(saveData[0]);
    m_currentHeightCounter = std::stoi(saveData[1]);
    m_gameObjectsFactory.setDifficulty(std::stoi(saveData[2]));

    m_gameObjectsFactory.generateLoadedGameObjects(saveData, m_gameObjects);
}

std::vector<std::string> GameWorld::getGameData()
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

