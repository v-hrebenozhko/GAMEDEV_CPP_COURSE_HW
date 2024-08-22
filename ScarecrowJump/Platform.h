#pragma once
#include "GameObjects.h"

class Platform : public GameObject
{
public:
    Platform() {};
    Platform(const sf::Texture& texture)
    {
        m_collisionEffect = CollisionEffect::Jump;
        m_sprite.setTexture(texture);
        m_sprite.setOrigin(m_sprite.getLocalBounds().width / 2, m_sprite.getGlobalBounds().height);
    }
    float getPlatformWidth() { return m_sprite.getGlobalBounds().width; }
    float getPlatformHeight() { return m_sprite.getGlobalBounds().height; }
    bool checkCollision(Player& player) override;
    virtual std::string getStringObjectData() const override;

};

class SpringPlatform : public Platform
{
public:
    SpringPlatform(const sf::Texture& texture)
    {
        m_collisionEffect = CollisionEffect::DoubleJump;
        m_sprite.setTexture(texture);
        //m_sprite.setScale(0.25, 0.2);
        m_sprite.setOrigin(m_sprite.getLocalBounds().width / 2, 0);
    }
    virtual std::string getStringObjectData() const override;
private:
};

class MovingPlatform : public Platform
{
public:
    using Platform::Platform;
    void update(float deltaTime, bool isWorldFalling, float speed, float windowXBound) override;
    virtual std::string getStringObjectData() const override;
private:
    float m_horizontalSpeed = 450;
    void floatX(float deltaTime, float windowXbound);
    bool isMovingRight = false;
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
    FakePlatform(const sf::Texture& texture)
    {
        m_collisionEffect = CollisionEffect::Nothing;
        m_sprite.setTexture(texture);
        //m_sprite.setScale(0.25, 0.02);
        m_sprite.setOrigin(m_sprite.getLocalBounds().width / 2, 0);
    }
    bool checkCollision(Player& player) override;
    virtual std::string getStringObjectData() const override;
};