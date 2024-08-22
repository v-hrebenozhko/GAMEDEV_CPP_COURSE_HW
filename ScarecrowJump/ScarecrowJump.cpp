#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <algorithm>
#include <thread>
#include "GameObjects.h"
#include "Menu.h"

#include "GameState.h"
#include "GameWorld.h"
#include "GameStateManager.h"
#include "WindowHelper.h"


void handleSystemEvents(sf::RenderWindow& window,GameStateManager& gameStateManager)
{

    sf::Event event;
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
        {
            gameStateManager.getCurrentGameState()->saveGame();
            window.close();
            break;
        }
        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::Key::Escape)
                //window.close();
        default:
            break;
        }
    }
}

int main()
{
    srand(time(0));

    sf::RenderWindow& window = WindowHelper::Instance().GetRenderWindow();

    GameWorld::createInstance(&window);
    GameWorld::Instance()->PostInit();
    Menu::createInstance(&window);

    GameWorld* gameWorld = GameWorld::Instance();
    Menu* menu = Menu::Instance();
    GameStateManager gameStateManager(menu, gameWorld, GameStateId::MainMenu);

    sf::Clock clock;

    while (window.isOpen())
    {
        const float deltaTime = clock.restart().asSeconds();
        
        handleSystemEvents(window,gameStateManager);

        //gameStateManager.getCurrentGameState()->generateGameObjects(&window);
        gameStateManager.getCurrentGameState()->update(&window,deltaTime);
        gameStateManager.getCurrentGameState()->draw(&window);
        gameStateManager.getCurrentGameState()->updateState();

        window.display();
    }

    GameWorld::destroyInstance();

    return 0;
}
