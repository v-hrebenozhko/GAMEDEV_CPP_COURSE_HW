#include "NPC.h"
#include "Player.h"

void FloatingNPC::update(float deltaTime, bool isWorldFalling, float speed, float windowXBound)
{
	SoundManager::getInstance().unpauseFloatingNPC();
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

bool NPC::checkCollision(Player& player)
{
	if (m_sprite.getGlobalBounds().intersects(player.getBounds()))
	{
		if (player.getIsHelicopter() || player.getIsRocket())
		{
			m_isDestroyed = true;
			return false;
		}
		return true;
	}
	return false;
}

StaticNPC::StaticNPC(const sf::Texture& texture)
{
	m_sprite.setTexture(texture);
	m_sprite.setOrigin(m_sprite.getLocalBounds().width / 2, m_sprite.getLocalBounds().top);
	m_collisionEffect = CollisionEffect::GameOver;
	m_isDestroyable = true;
	SoundManager::getInstance().playStaticNPC();
}

void StaticNPC::update(float deltaTime, bool isWorldFalling, float speed, float windowXBound)
{
	GameObject::update(deltaTime, isWorldFalling, speed, windowXBound);
	SoundManager::getInstance().unpauseStaticNPC();
}

BigStaticNPC::BigStaticNPC(const sf::Texture& texture)
{
	m_sprite.setTexture(texture);
	m_sprite.setOrigin(m_sprite.getLocalBounds().width / 2, m_sprite.getLocalBounds().top);
	m_collisionEffect = CollisionEffect::GameOver;
	m_isDestroyable = true;
	SoundManager::getInstance().playBigStaticNPC();
}

void BigStaticNPC::update(float deltaTime, bool isWorldFalling, float speed, float windowXBound)
{
	GameObject::update(deltaTime, isWorldFalling, speed, windowXBound);
	SoundManager::getInstance().unpauseBigStaticNPC();
}

FloatingNPC::FloatingNPC(const sf::Texture& texture)
{
	m_sprite.setTexture(texture);
	m_sprite.setOrigin(m_sprite.getLocalBounds().width / 2, m_sprite.getLocalBounds().top);
	m_collisionEffect = CollisionEffect::GameOver;
	m_isDestroyable = true;
	SoundManager::getInstance().playFloatingNPC();
}
