#pragma once
#include <SFML/Audio.hpp>

class SoundManager
{
public:
	void playMainMenu();
	void stopMainMenu() { m_mainMenuSound.stop(); };

	void playStaticNPC(); 
	void pauseStaticNPC() { m_staticNPCSound.pause(); };
	void unpauseStaticNPC();
	void stopStaticNPC() { m_staticNPCSound.stop(); }

	void playBigStaticNPC();
	void pauseBigStaticNPC() { m_bigStaticNPCSound.pause(); }
	void unpauseBigStaticNPC();
	void stopBigStaticNPC() { m_bigStaticNPCSound.stop(); }

	void playFloatingNPC();
	void pauseFloatingNPC() { m_floatingNPCSound.pause(); }
	void unpauseFloatingNPC();
	void stopFloatingNPC() { m_floatingNPCSound.stop(); }

	void playHelicopter(); 
	void unpauseHelicopter();
	void stopHelicopter() { m_helicopterSound.stop(); }

	void playRocket();
	void unpauseRocket();
	void stopRocket() { m_rocketSound.stop(); }

	void pauseGameSound();
	void unpauseGameSound();
	void resetGameSound();

	void playJump() { m_jumpSound.play(); }

	void playDoubleJump() { m_doubleJumpSound.play(); }

	void playGameStart() { m_startGameSound.play(); }

	static SoundManager& getInstance() 
	{
		static SoundManager instance; 
		return instance; 
	}

private:
	SoundManager()
	{
		m_helicopterBuffer.loadFromFile("HelicopterSound.wav");
		m_jumpBuffer.loadFromFile("jump.wav");
		m_doubleJumpBuffer.loadFromFile("DoubleJumpSound.mp3");
		m_rocketSoundBuffer.loadFromFile("RocketSound.mp3");
		m_startGameBuffer.loadFromFile("game_start.wav");
		m_mainMenuBuffer.loadFromFile("MainMenuSound.mp3");
		m_staticNPCBuffer.loadFromFile("StaticNPCSound.mp3");
		m_bigStaticNPCBuffer.loadFromFile("BigNPCSound.mp3");
		m_floatingNPCBuffer.loadFromFile("FloatingNPCSound.mp3");

		m_helicopterSound.setBuffer(m_helicopterBuffer);
		m_jumpSound.setBuffer(m_jumpBuffer);
		m_doubleJumpSound.setBuffer(m_doubleJumpBuffer);
		m_rocketSound.setBuffer(m_rocketSoundBuffer);
		m_startGameSound.setBuffer(m_startGameBuffer);
		m_mainMenuSound.setBuffer(m_mainMenuBuffer);
		m_staticNPCSound.setBuffer(m_staticNPCBuffer);
		m_bigStaticNPCSound.setBuffer(m_bigStaticNPCBuffer);
		m_floatingNPCSound.setBuffer(m_floatingNPCBuffer);
	}

	sf::Sound m_jumpSound;
	sf::Sound m_doubleJumpSound;
	sf::Sound m_rocketSound;
	sf::Sound m_helicopterSound;
	sf::Sound m_startGameSound;
	sf::Sound m_mainMenuSound;
	sf::Sound m_staticNPCSound;
	sf::Sound m_bigStaticNPCSound;
	sf::Sound m_floatingNPCSound;

	sf::SoundBuffer m_jumpBuffer;
	sf::SoundBuffer m_doubleJumpBuffer;
	sf::SoundBuffer m_rocketSoundBuffer;
	sf::SoundBuffer m_helicopterBuffer;
	sf::SoundBuffer m_startGameBuffer;
	sf::SoundBuffer m_mainMenuBuffer;
	sf::SoundBuffer m_staticNPCBuffer;
	sf::SoundBuffer m_bigStaticNPCBuffer;
	sf::SoundBuffer m_floatingNPCBuffer;
};