#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "FontManager.h"
#include "assert.h"
#include <iostream>
#include "SoundManager.h"

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
		assert(ms_menu && "Menu Instance wasn't properly created!");
		return ms_menu;
	}
	void clearButtons();

	bool getPlayButtonPressed() const { return isPlayButtonPressed; }
	bool getMainMenuButton() const { return isMainMenuButtonPressed; }
	bool getResumeButtonPressed() const { return isResumeButtonPressed; }
	bool getRestratButtonPressed() const { return isRestartButtonPressed; }
	bool getContinueButtonPressed() const { return isContinueButtonPressed; }

	void setMenuState(MenuState menuState) { m_MenuState = menuState; }

	void update(sf::RenderWindow* window);
	void draw(sf::RenderWindow* window);

private:
	bool checkMouseCollision(sf::Sprite text);
		
private:
	sf::Sprite m_playSprite;
	sf::Sprite m_exitSprite;
	sf::Sprite m_resumeSprite;
	sf::Sprite m_continueSprite;
	sf::Sprite m_mainMenuSprite;
	sf::Sprite m_restartSprite;
	sf::Sprite m_mainMenuBackGround;

	sf::Texture m_playTexture;
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

