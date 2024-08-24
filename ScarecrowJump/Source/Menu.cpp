#include "Menu.h"

Menu* Menu::ms_menu = nullptr;


Menu::Menu(sf::RenderWindow* window)
{
	m_mainMenuBackGroundTexture.loadFromFile("MainMenuBackground.jpg");
	m_mainMenuBackGround.setTexture(m_mainMenuBackGroundTexture);

	m_playTexture.loadFromFile("Play.png");
	m_playSprite.setTexture(m_playTexture);
	m_playSprite.setOrigin(m_playSprite.getLocalBounds().width / 2, m_playSprite.getLocalBounds().height / 2);
	m_playSprite.setPosition(window->getSize().x / 2, window->getSize().y * 0.65f);

	m_resumeTexture.loadFromFile("Resume.png");
	m_resumeSprite.setTexture(m_resumeTexture);
	m_resumeSprite.setOrigin(m_playSprite.getLocalBounds().width / 2, m_playSprite.getLocalBounds().height / 2);
	m_resumeSprite.setPosition(window->getSize().x / 2, window->getSize().y * 0.3);

	m_restartTexture.loadFromFile("Restart.png");
	m_restartSprite.setTexture(m_restartTexture);
	m_restartSprite.setOrigin(m_playSprite.getLocalBounds().width / 2, m_playSprite.getLocalBounds().height / 2);
	m_restartSprite.setPosition(window->getSize().x / 2, window->getSize().y * 0.5);

	m_mainMenuTexture.loadFromFile("MainMenu.png");
	m_mainMenuSprite.setTexture(m_mainMenuTexture);
	m_mainMenuSprite.setOrigin(m_playSprite.getLocalBounds().width / 2, m_playSprite.getLocalBounds().height / 2);
	m_mainMenuSprite.setPosition(window->getSize().x / 2, window->getSize().y * 0.5);

	m_continueTexture.loadFromFile("Continue.png");
	m_continueSprite.setTexture(m_continueTexture);
	m_continueSprite.setOrigin(m_playSprite.getLocalBounds().width / 2, m_playSprite.getLocalBounds().height / 2);
	m_continueSprite.setPosition(window->getSize().x / 2, window->getSize().y * 0.75f);

	
}

void Menu::clearButtons()
{
	isPlayButtonPressed = false;
	isExitButtonPressed = false;
	isResumeButtonPressed = false;
	isRestartButtonPressed = false;
	isMainMenuButtonPressed = false;
	isContinueButtonPressed = false;
}

void Menu::update(sf::RenderWindow* window)
{
	switch (m_MenuState)
	{
	case MenuState::MainMenu:
	{
		if (checkMouseCollision(m_playSprite) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			isPlayButtonPressed = true;
		}
		if (checkMouseCollision(m_continueSprite) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			isContinueButtonPressed = true;
		}
		break;
	}
	case MenuState::PauseMenu:
	{
		if (checkMouseCollision(m_resumeSprite) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			isResumeButtonPressed = true;
		}
		if (checkMouseCollision(m_mainMenuSprite) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			isMainMenuButtonPressed = true;
		}
		break;
	}
	case MenuState::GameOverMenu:
	{
		if (checkMouseCollision(m_restartSprite) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			isRestartButtonPressed = true;
		}
		break;
	}
	case MenuState::OptionsMenu:
	{
		break;
	}
	}
}

void Menu::draw(sf::RenderWindow* window)
{
	switch (m_MenuState)
	{
	case MenuState::MainMenu:
	{
		window->clear();
		window->draw(m_mainMenuBackGround);
		window->draw(m_playSprite);
		window->draw(m_continueSprite);
		break;
	}
	case MenuState::PauseMenu:
	{
		window->draw(m_resumeSprite);
		window->draw(m_mainMenuSprite);
		break;
	}
	case MenuState::GameOverMenu:
	{
		window->draw(m_restartSprite);
		break;
	}
	case MenuState::OptionsMenu:
	{
		break;
	}
	}
}

bool Menu::checkMouseCollision(sf::Sprite text)
{
	return text.getGlobalBounds().contains(static_cast<sf::Vector2f>(mouse.getPosition()));
}
