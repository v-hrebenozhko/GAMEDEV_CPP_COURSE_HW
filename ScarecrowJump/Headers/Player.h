#pragma once
#include "GameObjects.h"
#include <iostream>

class Player : public GameObject
{
public:
    Player();
    void update(float deltaTime, bool isWorldFalling, float speed,float windowXBound) override;
    sf::FloatRect getBounds() { return m_sprite.getGlobalBounds(); }
    void updatePosition(const sf::Vector2f& deltaPosition, float windowXBound) override;

    void Jump();
    void doubleJump();
    void helicopterFlight();
    void rocketFlight();
    bool launchProjectile();

    void resetPlayer();

    const bool getIsFalling() const { return m_IsFalling; }
    const bool getIsHelicopter() const { return m_IsHelicopter; }
    const bool getIsRocket() const { return m_IsRocket; }

    float getSpeed() { return m_currentSpeed; }
    virtual std::string getStringObjectData() const override;

private:
    bool m_IsFalling;
    bool m_IsFlying;
    bool m_IsHelicopter;
    bool m_IsRocket;

    unsigned int projectileCooldown;

    float m_currentSpeed = 1150.0f;
    float m_defaultSpeed = 1150.0f;
    float m_flightDuration;
  
    sf::Texture m_helicopterPlayerTexture;
    sf::Texture m_rocketPlayerTexture;
private:
    void handleMovemenent(float deltaTime, bool isWorldFalling, float windowXbound);
};

class Projectile : public GameObject
{
public:
    Projectile(const sf::Texture& texture);

    void update(float deltaTime, bool isWorldFalling, float speed, float windowXBound) override;

    void checkIsAimed(std::unique_ptr<GameObject>& gameObject);
    bool checkCollision(Player& player) override { return false; };

    std::string getStringObjectData() const override { return ""; }

private:
    float m_speed = 1250;
    unsigned int existanceDuration;

    void rotate(float deltaTime);
    void moveUp(float deltaTime, float windowXBound);

};