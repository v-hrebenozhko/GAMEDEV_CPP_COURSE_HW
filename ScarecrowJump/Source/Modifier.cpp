#include "Modifier.h"
#include "Player.h"

bool Modifier::checkCollision(Player& player)
{
	if (m_sprite.getGlobalBounds().intersects(player.getBounds()))
	{
		m_isDestroyed = true;
		return true;
	}
}

std::string HelicopterModifier::getStringObjectData() const
{

	return "HelicopterModifier;\n" + std::to_string(getPosition().x) + ";\n" + std::to_string(getPosition().y) + ";\n";
}

std::string RocketModifier::getStringObjectData() const
{
	return "RocketModifier;\n" + std::to_string(getPosition().x) + ";\n" + std::to_string(getPosition().y) + ";\n";
}

HelicopterModifier::HelicopterModifier(const sf::Texture& texture)
{
	m_collisionEffect = CollisionEffect::HelicopterFlight;
	m_sprite.setTexture(texture);
	m_sprite.setOrigin(m_sprite.getLocalBounds().width / 2.0f, 0);
}

RocketModifier::RocketModifier(const sf::Texture& texture)
{
	m_collisionEffect = CollisionEffect::RocketFlight;
	m_sprite.setTexture(texture);
	m_sprite.setOrigin(m_sprite.getLocalBounds().width / 2.0f, 0);
}
