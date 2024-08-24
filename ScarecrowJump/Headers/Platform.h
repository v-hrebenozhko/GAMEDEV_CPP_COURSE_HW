#pragma once
#include "GameObjects.h"

class Platform : public GameObject
{
public:
    Platform() {};
    Platform(const sf::Texture& texture);

    const float getPlatformWidth() const { return m_sprite.getGlobalBounds().width; }
    const float getPlatformHeight() const { return m_sprite.getGlobalBounds().height; }
    bool checkCollision(Player& player) override;
    virtual std::string getStringObjectData() const override;
};

class SpringPlatform : public Platform
{
public:
    SpringPlatform(const sf::Texture& texture);

    virtual std::string getStringObjectData() const override;
};

class MovingPlatform : public Platform
{
public:
    using Platform::Platform;
    void update(float deltaTime, bool isWorldFalling, float speed, float windowXBound) override;
    virtual std::string getStringObjectData() const override;

private:
    bool isMovingRight = false;
    float m_horizontalSpeed = 450;

    void floatX(float deltaTime, float windowXbound);
};

class OneCollisionPlatform : public Platform
{
public:
    using Platform::Platform;

    bool checkCollision(Player& player) override;
    virtual std::string getStringObjectData() const override;
};

class FakePlatform : public Platform
{
public:
    FakePlatform(const sf::Texture& texture);

    bool checkCollision(Player& player) override;
    virtual std::string getStringObjectData() const override;
};