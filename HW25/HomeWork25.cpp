#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

struct Boundaries
{
	float m_LeftEdge;
	float m_RightEdge;
	float m_UpEdge;
	float m_DownEdge;
	float m_BoundariePartion;
	Boundaries(const sf::RenderWindow& Window)
	{
		m_BoundariePartion = 5;
		m_LeftEdge = 0.0f + Window.getSize().x / m_BoundariePartion;
		m_RightEdge = Window.getSize().x - Window.getSize().x /m_BoundariePartion;
		m_UpEdge = 0.0f + Window.getSize().y / m_BoundariePartion;
		m_DownEdge = Window.getSize().y - Window.getSize().y/ m_BoundariePartion;
	}
	void SetNewBoundarie(const sf::RenderWindow& Window)
	{
		m_BoundariePartion = 5;
		m_LeftEdge = 0.0f + Window.getSize().x / m_BoundariePartion;
		m_RightEdge = Window.getSize().x - Window.getSize().x / m_BoundariePartion;
		m_UpEdge = 0.0f + Window.getSize().y / m_BoundariePartion;
		m_DownEdge = Window.getSize().y - Window.getSize().y / m_BoundariePartion;
	}
};

bool CheckBoundaries(float x, float y,Boundaries Boundary)
{
	if (x < Boundary.m_LeftEdge || x > Boundary.m_RightEdge || y < Boundary.m_UpEdge || y > Boundary.m_DownEdge)
	{
		return false;
	}
	else
	{
		return true;
	}

}

void HandleRotation(sf::Sprite& GameObject)
{
	const float RotationSpeed = 1.0f;
	float DeltaRotation = 0;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
	{
		DeltaRotation = RotationSpeed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
	{
		DeltaRotation = -RotationSpeed;
	}
	GameObject.setRotation(GameObject.getRotation() + DeltaRotation);
}

void HandleScale(sf::Sprite& GameObject)
{
	const float ScaleSpeed = 0.01f;
	float DeltaScale = 0;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
	{
		DeltaScale = -ScaleSpeed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
	{
		DeltaScale = ScaleSpeed;
	}
	GameObject.setScale(GameObject.getScale().x + DeltaScale, GameObject.getScale().y + DeltaScale);
}

void HandleMovement(sf::Sprite& GameObject,Boundaries& Boundary)
{
	float DeltaX = 0.0f;
	float DeltaY = 0.0f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{
		DeltaY = -10.0f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		DeltaY = 10.0f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		DeltaX = -10.0f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		DeltaX = 10.0f;
	}
	const sf::Vector2f OldPosition = GameObject.getPosition();
	if (CheckBoundaries(OldPosition.x + DeltaX, OldPosition.y + DeltaY,Boundary))
	{
		
		GameObject.setPosition({ OldPosition.x + DeltaX,OldPosition.y + DeltaY });
	}
}

int main()
{
	sf::RenderWindow Window(sf::VideoMode::getDesktopMode(), "HomeWork25");

	sf::Texture PlayerTexture;
	PlayerTexture.loadFromFile("Sponge.png");

	sf::Sprite Player;
	Player.setTexture(PlayerTexture);

	sf::Vector2f PlayerPosition = {Window.getSize().x/2.0f,Window.getSize().y/2.0f};
	Player.setPosition(PlayerPosition);
	Player.setOrigin(Player.getGlobalBounds().getSize().x / 2.0f, Player.getGlobalBounds().getSize().y / 2.0f);
	Boundaries Boundary(Window);

	while (Window.isOpen())
	{
		sf::Event MainEvent;
		while(Window.pollEvent(MainEvent))
		{
			switch (MainEvent.type)
			{
			case sf::Event::Closed:
			{
				Window.close();
				break;
			}
			case sf::Event::Resized:
			{
				sf::Vector2f PlayerPosition = { Window.getSize().x / 2.0f,Window.getSize().y / 2.0f };
				Player.setPosition(PlayerPosition);
				Boundary.SetNewBoundarie(Window);
			}
			}
		}
		HandleMovement(Player,Boundary);
		HandleRotation(Player);
		HandleScale(Player);
		Window.clear(sf::Color{ 0, 255, 0 });
		Window.draw(Player);
		Window.display();
	}

}
