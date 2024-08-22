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
