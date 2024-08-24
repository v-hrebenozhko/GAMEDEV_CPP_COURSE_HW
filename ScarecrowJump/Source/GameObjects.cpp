#include "GameObjects.h"
#include "GameWorld.h"


GameObject::GameObject(const char* textureFileName)
{
		m_texture.loadFromFile(textureFileName);
	m_sprite.setTexture(m_texture);
}

void GameObject::update(float deltaTime, bool isWorldFalling, float speed, float windowXBound)
{
	if (isWorldFalling)
	{
		moveDown(deltaTime, speed,windowXBound);
	}
}

void GameObject::draw(sf::RenderWindow* window)
{
	window->draw(m_sprite);

}

void GameObject::moveDown(float deltaTime, float speed,float windowXBound)
{
	updatePosition(sf::Vector2f{ 0,deltaTime * speed },windowXBound);
}

bool GameObject::checkCollision(Player& player)
{
	return m_sprite.getGlobalBounds().intersects(player.getBounds());
}

void GameObject::setPosition(const sf::Vector2f& position)
{
	m_sprite.setPosition(position);
}

sf::Vector2f GameObject::getPosition() const
{
	return m_sprite.getPosition();
}

void GameObject::updatePosition(const sf::Vector2f& deltaPosition, float windowXBound)
{
	sf::Vector2f position = getPosition();
	position.x += deltaPosition.x;
	position.y += deltaPosition.y;
	setPosition(position);
}

sf::Vector2f GameObject::getSize() const
{
	return m_sprite.getLocalBounds().getSize();
}

sf::Sprite* GameObject::getSprite()
{
	return &m_sprite;
}
