#pragma once
#include "GameObjects.h"

class Player : public GameObject
{
public:
    Player();
    void update(float deltaTime, bool isWorldFalling, float speed,float windowXBound) override;
    sf::FloatRect getBounds() { return m_sprite.getGlobalBounds(); }
    void updatePosition(const sf::Vector2f& deltaPosition, float windowXBound) override;
    void Jump() 
    { 
        isFalling = false;
        m_currentSpeed = m_defaultSpeed;
        SoundManager::getInstance().playJump();
    }
    void doubleJump() 
    {
        isFalling = false;
        m_currentSpeed = m_defaultSpeed * 2.0f;
    }
    void helicopterFlight() 
    {
        m_flightDuration = 1600;
        m_currentSpeed = m_defaultSpeed*1.5f ;
        SoundManager::getInstance().playDamage();
        isHelicopter = true;
        isFalling = false;
        isFlying = true;
    }
    void rocketFlight()
    {
        m_flightDuration = 1600;
        m_currentSpeed = m_defaultSpeed * 2.5f;
        isFalling = false;
        isFlying = true;
    }
    void resetPlayer();
    bool getIsFalling() { return isFalling; }
    float getSpeed() { return m_currentSpeed; }
    virtual std::string getStringObjectData() const override;

private:
    void handleMovemenent(float deltaTime, bool isWorldFalling,float windowXbound);

private:
    float m_currentSpeed = 1150.0f;
    float m_defaultSpeed = 1150.0f;
    float m_flightDuration;
    bool isFalling;
    bool isFlying;
    bool isHelicopter = false;
};