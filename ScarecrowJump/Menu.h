#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "FontManager.h"
#include "assert.h"
#include <iostream>

enum class MenuState
{
	MainMenu,
	PauseMenu,
	GameOverMenu,
	OptionsMenu
};
class Menu
{
public:
	Menu(sf::RenderWindow* window);

	~Menu(){};

	static void createInstance(sf::RenderWindow* window)
	{
		ms_menu = new Menu(window);
	}

	static void destroyInstance()
	{
		delete ms_menu;
	}

	static Menu* Instance()
	{
		assert(ms_menu && "MainMenu Instance wasn't properly created!");
		return ms_menu;
	}
	void cleatButtons()
	{
		isPlayButtonPressed = false;
		isExitButtonPressed = false;
		isResumeButtonPressed = false;
		isRestartButtonPressed = false;
		isMainMenuButtonPressed = false;
		isContinueButtonPressed = false;
	}
	bool getPlayButtonPressed() const { return isPlayButtonPressed; }
	bool getMainMenuButton() const { return isMainMenuButtonPressed; }
	bool getResumeButtonPressed() const { return isResumeButtonPressed; }
	bool getRestratButtonPressed() const { return isRestartButtonPressed; }
	bool getContinueButtonPressed() const { return isContinueButtonPressed; }
	void setMenuState(MenuState menuState)
	{
		m_MenuState = menuState;
	}

	void update(sf::RenderWindow* window)
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
	void draw(sf::RenderWindow* window)
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

private:
	
	bool checkMouseCollision(sf::Sprite text)
	{
		return text.getGlobalBounds().contains(static_cast<sf::Vector2f>(mouse.getPosition()));
	}
	
private:
	sf::Sprite m_playSprite;
	sf::Sprite m_optionsSprite;
	sf::Sprite m_exitSprite;
	sf::Sprite m_resumeSprite;
	sf::Sprite m_continueSprite;
	sf::Sprite m_mainMenuSprite;
	sf::Sprite m_restartSprite;
	sf::Sprite m_mainMenuBackGround;

	sf::Texture m_playTexture;
	sf::Texture m_optionsTexture;
	sf::Texture m_exitTexture;
	sf::Texture m_resumeTexture;
	sf::Texture m_continueTexture;
	sf::Texture m_mainMenuTexture;
	sf::Texture m_restartTexture;
	sf::Texture m_mainMenuBackGroundTexture;

	sf::Mouse mouse;
	bool isPlayButtonPressed = false;
	bool isExitButtonPressed = false;
	bool isResumeButtonPressed = false;
	bool isContinueButtonPressed = false;
	bool isRestartButtonPressed = false;
	bool isMainMenuButtonPressed = false;

	MenuState m_MenuState;

	static Menu* ms_menu;
};

