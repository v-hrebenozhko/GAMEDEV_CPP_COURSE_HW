#include "NPC.h"

void FloatingNPC::update(float deltaTime, bool isWorldFalling, float speed, float windowXBound)
{
	GameObject::update(deltaTime, isWorldFalling, speed, windowXBound);
	floatX(deltaTime, windowXBound);
}

std::string FloatingNPC::getStringObjectData() const
{
	return std::string(); return "FloatingNPC;\n" + std::to_string(getPosition().x) + ";\n" + std::to_string(getPosition().y) + ";\n";
}
void FloatingNPC::floatX(float deltaTime, float windowXbound)
{
	const float MoveDeltaX = deltaTime * m_horizontalSpeed;
	const float MoveDelatY = deltaTime * m_verticalSpeed;
	float DeltaX = 0;
	float DeltaY = 0;

	sf::Vector2f currentPosition = getPosition();
	if (currentPosition.x < 0 + m_sprite.getGlobalBounds().width / 2)
	{
		isMovingRight = true;
	}
	if (currentPosition.x > windowXbound - m_sprite.getGlobalBounds().width / 2)
	{
		isMovingRight = false;
	}
	if (isMovingRight)
	{
		DeltaX += MoveDeltaX;
	}
	else
	{
		DeltaX -= MoveDeltaX;
	}

	if (movingDownDuration == 0)
	{
		movingDownDuration = m_defaultMovingDownDuration;
		isMovingDown = !isMovingDown;
	}
	else
	{
		movingDownDuration--;
	}

	if (isMovingDown)
	{
		DeltaY += MoveDelatY;
	}
	else
	{
		DeltaY -= MoveDelatY;
	}

	updatePosition(sf::Vector2f{ DeltaX,DeltaY }, windowXbound);
}

std::string StaticNPC::getStringObjectData() const
{
	return "StaticNPC;\n" + std::to_string(getPosition().x) + ";\n" + std::to_string(getPosition().y) + ";\n";
}

std::string BigStaticNPC::getStringObjectData() const
{
	return "BigStaticNPC;\n" + std::to_string(getPosition().x) + ";\n" + std::to_string(getPosition().y) + ";\n";
}
