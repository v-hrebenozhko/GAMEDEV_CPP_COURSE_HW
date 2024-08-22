#include "Platform.h"
#include "Player.h"

bool Platform::checkCollision(Player& player)
{
	if (player.getIsFalling())
	{
		if (player.getBounds().top + player.getBounds().height <= m_sprite.getGlobalBounds().top + 3 && player.getBounds().top + player.getBounds().height >= m_sprite.getGlobalBounds().top - 3)
		{
			if (player.getBounds().left >= m_sprite.getGlobalBounds().left
				&& player.getBounds().left <= m_sprite.getGlobalBounds().left + m_sprite.getGlobalBounds().width)
			{
				return true;
			}
			else if ((player.getBounds().left + player.getBounds().width >= m_sprite.getGlobalBounds().left
				&& player.getBounds().left + player.getBounds().width <= m_sprite.getGlobalBounds().left + m_sprite.getGlobalBounds().width))
			{
				return true;
			}
		}
	}
	return false;
}

std::string Platform::getStringObjectData() const
{
	return "Platform;\n" + std::to_string(getPosition().x) + ";\n" + std::to_string(getPosition().y) + ";\n";
}


void MovingPlatform::update(float deltaTime, bool isWorldFalling, float speed, float windowXBound)
{
	GameObject::update(deltaTime, isWorldFalling, speed, windowXBound);
	floatX(deltaTime, windowXBound);
}

std::string MovingPlatform::getStringObjectData() const
{
	return "MovingPlatform;\n" + std::to_string(getPosition().x) + ";\n" + std::to_string(getPosition().y) + ";\n";
}

void MovingPlatform::floatX(float deltaTime, float windowXbound)
{
	const float MoveDeltaX = deltaTime * m_horizontalSpeed;
	float DeltaX = 0;
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

	updatePosition(sf::Vector2f{ DeltaX,0 }, windowXbound);
}

bool OneCollisionPlatform::checkCollision(Player& player)
{
	if (Platform::checkCollision(player))
	{
		m_isDestroyed = true;
		return true;
	}
	return false;
}

std::string OneCollisionPlatform::getStringObjectData() const
{
	return "OneCollisionPlatform;\n" + std::to_string(getPosition().x) + ";\n" + std::to_string(getPosition().y) + ";\n";
}

bool FakePlatform::checkCollision(Player& player)
{
	if (Platform::checkCollision(player))
	{
		m_isDestroyed = true;
		return true;
	}
	return false;
}

std::string FakePlatform::getStringObjectData() const
{
	return "FakePlatform;\n" + std::to_string(getPosition().x) + ";\n" + std::to_string(getPosition().y) + ";\n";
}

std::string SpringPlatform::getStringObjectData() const
{
	return "SpringPlatform;\n" + std::to_string(getPosition().x) + ";\n" + std::to_string(getPosition().y) + ";\n";
}
