#include "Player.h"


Player::Player() : GameObject("ScareCrow 2.png")
{
	isFalling = true;
	//m_sprite.setScale(0.75, 0.75);
	m_sprite.setOrigin(m_sprite.getGlobalBounds().getSize().x / 2,
		m_sprite.getGlobalBounds().getSize().y / 2);
}

void Player::update(float deltaTime, bool isWorldFalling,float speed,float windowXBound)
{
	handleMovemenent(deltaTime,isWorldFalling,windowXBound);
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

void Player::resetPlayer()
{
	m_currentSpeed = m_defaultSpeed;
	isFalling = true;
	isFlying = false;
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

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
	{
		isFalling = false;
		m_currentSpeed = m_defaultSpeed;
		m_flightDuration = 100;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
	{
		
	}
	if (m_currentSpeed == 0)
	{
		isFalling = true;
	}
	if (isFlying)
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
			SoundManager::getInstance().stopDamage();
			if (isHelicopter)
			{
				isHelicopter = false;
			}
			isFlying = false;
			m_currentSpeed = m_defaultSpeed;
		}
	}
	else if (!isFalling)
	{
		m_currentSpeed-=5;
		if (!isWorldFalling)
		{
			deltaY -= MoveDeltaY;
		}
	}
	else if(isFalling)
	{
		if (m_currentSpeed < m_defaultSpeed)
		{
			m_currentSpeed += 5;
		}
		deltaY += MoveDeltaY;
	}

	updatePosition({ deltaX,deltaY },windowXBound);
}
