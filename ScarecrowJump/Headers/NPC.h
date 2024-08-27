#pragma once
#include "GameObjects.h"

class NPC : public GameObject
{
public:
    virtual std::string getStringObjectData() const = 0;
    bool checkCollision(Player& player) override;
};

class StaticNPC : public NPC
{
public:
    StaticNPC(const sf::Texture& texture);
    ~StaticNPC() { SoundManager::getInstance().pauseStaticNPC(); }

    void update(float deltaTime, bool isWorldFalling, float speed, float windowXBound) override;

    virtual std::string getStringObjectData() const override;
};

class BigStaticNPC : public NPC
{
public:
    BigStaticNPC(const sf::Texture& texture);
    ~BigStaticNPC() { SoundManager::getInstance().pauseBigStaticNPC(); }

    void update(float deltaTime, bool isWorldFalling, float speed, float windowXBound) override;

    virtual std::string getStringObjectData() const override;
};

class FloatingNPC : public NPC
{
public:
    FloatingNPC(const sf::Texture& texture);
    ~FloatingNPC() { SoundManager::getInstance().pauseFloatingNPC(); }

    void update(float deltaTime, bool isWorldFalling, float speed, float windowXBound) override;
    virtual std::string getStringObjectData() const override;

private:
    float m_horizontalSpeed = 550;
    float m_verticalSpeed = 250;
    void floatX(float deltaTime, float windowXbound);
    bool isMovingDown = false;
    bool isMovingRight = false;
    float movingDownDuration = 100;
    float m_defaultMovingDownDuration = 100;
};
