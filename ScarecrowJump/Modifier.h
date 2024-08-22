#pragma once
#include "GameObjects.h"

class Modifier : public GameObject
{
public:
    Modifier() {}
    bool checkCollision(Player& player) override;
    virtual std::string getStringObjectData() const = 0;
private:
};

class HelicopterModifier : public Modifier
{
public:
    HelicopterModifier(const sf::Texture& texture)
    {
        m_collisionEffect = CollisionEffect::HelicopterFlight;
        m_sprite.setTexture(texture);
        //m_sprite.setScale(0.25, 0.2);
        m_sprite.setOrigin(m_sprite.getLocalBounds().width / 2,0);
    }
    virtual std::string getStringObjectData() const override;
private:

};

class RocketModifier : public Modifier
{
public:
    RocketModifier(const sf::Texture& texture)
    {
        m_collisionEffect = CollisionEffect::RocketFlight;
        m_sprite.setTexture(texture);
        //m_sprite.setScale(0.25, 0.2);
        m_sprite.setOrigin(m_sprite.getLocalBounds().width / 2, 0);
    }
    virtual std::string getStringObjectData() const override;
private:

};