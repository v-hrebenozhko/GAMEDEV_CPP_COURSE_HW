#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "GameObjects.h"
#include "GameWorld.h"
#include "Menu.h"
#include "SaveManager.h"

class GameStateManager;

class GameState
{
public:
	GameState(GameStateManager& context) : m_gameStateManager(context) {}

	virtual void onEnter() {} //To add initialization during state enter
	virtual void onExit() {} //To add deinitialization during state exit

	virtual void updateState() = 0;
	virtual void update(sf::RenderWindow* window, float DeltaTime) = 0;
	virtual void draw(sf::RenderWindow* window) = 0;
	virtual void saveGame() = 0;

protected:
	GameStateManager& m_gameStateManager;
};

class GameState_Playing : public GameState
{
public:
	GameState_Playing(GameStateManager& context, GameWorld* gameWorld) : GameState(context), m_GameWorld(gameWorld) {}

	void onEnter() override;

	void updateState() override;
	void update(sf::RenderWindow* window, float DeltaTime) override;
	void draw(sf::RenderWindow* window) override;
	void saveGame() override;

private:
	GameWorld* m_GameWorld;

	bool m_pressedLastFrame = true;
	
};

class GameState_MainMenu : public GameState
{
public:
	GameState_MainMenu(GameStateManager& context, Menu* menu) : GameState(context), m_menu(menu) {}
	void onEnter() override;

	void updateState() override;
	void update(sf::RenderWindow* window, float DeltaTime) override;
	void draw(sf::RenderWindow* window) override;
	void saveGame() override;
private:
	Menu* m_menu;
};

class GameState_Pause : public GameState
{
public:
	GameState_Pause(GameStateManager& context, Menu* menu) : GameState(context), m_menu(menu) {}
	void onEnter() override;

	void updateState() override;
	void update(sf::RenderWindow* window, float DeltaTime) override;
	void draw(sf::RenderWindow* window) override;
	void saveGame() override;
private:
	Menu* m_menu;
};

class GameState_GameOver : public GameState
{
public:
	GameState_GameOver(GameStateManager& context, Menu* menu, GameWorld* gameWorld) : GameState(context), m_menu(menu), m_GameWorld(gameWorld) {}
	void onEnter() override;

	void updateState() override;
	void update(sf::RenderWindow* window, float DeltaTime) override;
	void draw(sf::RenderWindow* window) override;
	void saveGame() override;
private:
	Menu* m_menu;
	GameWorld* m_GameWorld;
};
