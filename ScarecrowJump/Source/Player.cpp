#include "Player.h"


Player::Player()
{
	m_IsFalling = true;
	projectileCooldown = 0;

	m_texture.loadFromFile("Player.png");
	m_helicopterPlayerTexture.loadFromFile("HelicopterPlayer.png");
	m_rocketPlayerTexture.loadFromFile("RocketPlayer.png");

	m_sprite.setTexture(m_texture);

	m_sprite.setOrigin(m_sprite.getGlobalBounds().getSize().x / 2,
		m_sprite.getGlobalBounds().getSize().y / 2);
}

void Player::update(float deltaTime, bool isWorldFalling,float speed,float windowXBound)
{
	handleMovemenent(deltaTime,isWorldFalling,windowXBound);
	if (projectileCooldown != 0)
	{
		projectileCooldown--;
	}
}

void Player::updatePosition(const sf::Vector2f& deltaPosition, float windowXBound)
{

	sf::Vector2f position = getPosition();
	position.x += deltaPosition.x;
	position.y += deltaPosition.y;
	if (position.x < 0 - m_sprite.getLocalBounds().width)
	{
		position.x = windowXBound;
	}
	if (position.x > windowXBound + m_sprite.getLocalBounds().width)
	{
		position.x = 0;
	}
	setPosition(position);
}

void Player::Jump()
{
	m_IsFalling = false;
	m_currentSpeed = m_defaultSpeed;
	SoundManager::getInstance().playJump();
}

void Player::doubleJump()
{
	m_IsFalling = false;
	m_currentSpeed = m_defaultSpeed * 2.0f;
	SoundManager::getInstance().playDoubleJump();
}

void Player::helicopterFlight()
{
	m_sprite.setTexture(m_helicopterPlayerTexture);
	m_flightDuration = 1600;
	m_currentSpeed = m_defaultSpeed * 1.5f;
	SoundManager::getInstance().playHelicopter();
	SoundManager::getInstance().stopRocket();
	m_IsFalling = false;
	m_IsHelicopter = true;
	m_IsRocket = false;
	m_IsFlying = true;
}

void Player::rocketFlight()
{
	m_sprite.setTexture(m_rocketPlayerTexture);
	SoundManager::getInstance().playRocket();
	SoundManager::getInstance().stopHelicopter();
	m_flightDuration = 1600;
	m_currentSpeed = m_defaultSpeed * 2.5f;

	m_IsHelicopter = false;
	m_IsRocket = true;
	m_IsFalling = false;
	m_IsFlying = true;
}

bool Player::launchProjectile()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
	{
		if (projectileCooldown == 0)
		{
			projectileCooldown = 200;
			return true;
		}
	}
	return false;
}

void Player::resetPlayer()
{
	m_currentSpeed = m_defaultSpeed;
	m_IsFalling = true;
	m_IsHelicopter = false;
	m_IsRocket = false;
	m_IsFlying = false;
}

std::string Player::getStringObjectData() const
{
	return std::to_string(getPosition().x) + ";\n" + std::to_string(getPosition().y) + ";\n";
}

void Player::handleMovemenent(float deltaTime,bool isWorldFalling,float windowXBound)
{
	const float MoveDeltaX = m_defaultSpeed/1.5 * deltaTime;
	const float MoveDeltaY = m_currentSpeed * deltaTime;

	float deltaX = 0;
	float deltaY = 0;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
	{
		deltaX += MoveDeltaX;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
	{
		deltaX -= MoveDeltaX;
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{
		m_IsFalling = false;
		m_currentSpeed = m_defaultSpeed;
		m_flightDuration = 100;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
	{
		
	}
	if (m_currentSpeed == 0)
	{
		m_IsFalling = true;
	}
	if (m_IsFlying)
	{
		if (m_flightDuration != 0)
		{
			m_flightDuration--;
			if (!isWorldFalling)
			{
				deltaY -= MoveDeltaY;
			}
		}
		else
		{
			SoundManager::getInstance().stopHelicopter();
			SoundManager::getInstance().stopRocket();
			m_sprite.setTexture(m_texture);
			m_IsHelicopter = false;
			m_IsRocket = false;
			m_IsFlying = false;
			m_currentSpeed = m_defaultSpeed;
		}
	}
	else if (!m_IsFalling)
	{
		m_currentSpeed-=5;
		if (!isWorldFalling)
		{
			deltaY -= MoveDeltaY;
		}
	}
	else if(m_IsFalling)
	{
		if (m_currentSpeed < m_defaultSpeed)
		{
			m_currentSpeed += 5;
		}
		deltaY += MoveDeltaY;
	}

	updatePosition({ deltaX,deltaY },windowXBound);
}

void Projectile::update(float deltaTime, bool isWorldFalling, float speed, float windowXBound)
{
	if (existanceDuration == 0)
	{
		m_isDestroyed = true;
	}
	existanceDuration--;
	moveUp(deltaTime, windowXBound);
	rotate(deltaTime);
}

void Projectile::checkIsAimed(std::unique_ptr<GameObject>& gameObject)
{
	
	if (gameObject.get()->getSprite()->getGlobalBounds().intersects(m_sprite.getGlobalBounds())
		&& gameObject.get()->getIsDestroyable())
	{
		m_isDestroyed = true;
		gameObject.get()->setIsDestroyed();
	}
}

void Projectile::moveUp(float deltaTime, float windowXBound)
{
	const float MoveDeltaY = m_speed * deltaTime;
	float deltaY = 0;
	deltaY -= MoveDeltaY;
	updatePosition({ 0,deltaY }, windowXBound);
}

void Projectile::rotate(float deltaTime)
{
	const float rotationDelta = 500.0f * deltaTime;
	m_sprite.rotate(rotationDelta);
}

Projectile::Projectile(const sf::Texture& texture)
{
	existanceDuration = 300;
	m_sprite.setTexture(texture);
	m_sprite.setOrigin(m_sprite.getLocalBounds().width / 2, m_sprite.getGlobalBounds().height);
	m_collisionEffect = CollisionEffect::Nothing;
}
