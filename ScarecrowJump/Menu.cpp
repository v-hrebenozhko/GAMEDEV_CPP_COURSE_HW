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
