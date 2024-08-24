#pragma once
#include "GameObjects.h"

class Modifier : public GameObject
{
public:
    Modifier() {}
    bool checkCollision(Player& player) override;
    virtual std::string getStringObjectData() const = 0;
};

class HelicopterModifier : public Modifier
{
public:
    HelicopterModifier(const sf::Texture& texture);

    virtual std::string getStringObjectData() const override;
};

class RocketModifier : public Modifier
{
public:
    RocketModifier(const sf::Texture& texture);

    virtual std::string getStringObjectData() const override;
};