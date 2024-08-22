#pragma once
#include "GameObjects.h"


class StaticNPC : public GameObject
{
public:
    StaticNPC(const sf::Texture& texture)
    {
        m_sprite.setTexture(texture);
        m_sprite.setOrigin(m_sprite.getLocalBounds().width / 2, m_sprite.getLocalBounds().top);
        m_collisionEffect = CollisionEffect::GameOver;
    }
    virtual std::string getStringObjectData() const override;
private:
};

class BigStaticNPC : public GameObject
{
public:
    BigStaticNPC(const sf::Texture& texture)
    {
        m_sprite.setTexture(texture);
        m_sprite.setOrigin(m_sprite.getLocalBounds().width / 2, m_sprite.getLocalBounds().top);
        m_collisionEffect = CollisionEffect::GameOver;
    }
    virtual std::string getStringObjectData() const override;
};

class FloatingNPC : public GameObject
{
public:
    FloatingNPC(const sf::Texture& texture)
    {
        m_sprite.setTexture(texture);
        m_sprite.setOrigin(m_sprite.getLocalBounds().width / 2, m_sprite.getLocalBounds().top);
        m_collisionEffect = CollisionEffect::GameOver;
    }
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
