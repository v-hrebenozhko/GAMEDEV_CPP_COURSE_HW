#pragma once
#include <SFML/Graphics.hpp>
#include "SoundManager.h"

class Component;
class Player;

//TODO: Bohdan
enum class VisibilityPriority
{
    p1, 
    p2,
    p3,
    p4,
    Background,
    Middle,
    Front
};

enum class CollisionEffect
{
    Jump,
    DoubleJump,
    HelicopterFlight,
    RocketFlight,
    Nothing,
    GameOver
};

class GameObject
{
public:
    GameObject() {}
    GameObject(const char* textureFileName);
    virtual ~GameObject() = default;

    virtual void update(float deltaTime, bool isWorldFalling, float speed,float windowXBound);
    virtual void draw(sf::RenderWindow* window);

    virtual void moveDown(float deltaTime, float speed, float windowXBound);
    virtual bool checkCollision(Player& player);
    CollisionEffect getCollisionEffect() const { return m_collisionEffect; }
    bool getIsDestroyed() const { return m_isDestroyed; }

    void setPosition(const sf::Vector2f& position);
    sf::Vector2f getPosition() const;

    virtual void updatePosition(const sf::Vector2f& deltaPosition, float windowXBound);

    virtual std::string getStringObjectData() const = 0;

    const bool getIsDestroyable() const { return m_isDestroyable; }
    void setIsDestroyed() { m_isDestroyed = true; }
    sf::Vector2f getSize() const;
    sf::Sprite* getSprite();

protected:
    sf::Texture m_texture;
    sf::Sprite m_sprite;
    CollisionEffect m_collisionEffect;
    bool m_isDestroyed = false;
    bool m_isDestroyable = false;
};








