#pragma once
#include <SFML/Audio.hpp>

class SoundManager
{
public:
	void playDamage() {
		m_collisionSound.setLoop(true);
		m_collisionSound.play();
		m_isDamageSoundOn = true;
	}
	void stopDamage()
	{
		m_collisionSound.stop();
		m_isDamageSoundOn = false;
	}
	void pauseGameSound()
	{
		m_collisionSound.stop();
	}
	void unPauseGameSound()
	{
		if (m_isDamageSoundOn)
		{
			m_collisionSound.play();
		}
	}
	void resetGameSound()
	{
		m_collisionSound.stop();
		m_isDamageSoundOn = false;
	}
	void playJump() { m_jumpSound.play(); }
	void playGameStart() { m_startGameSound.play(); }

	static SoundManager& getInstance() 
	{
		static SoundManager instance; 
		return instance; 
	}

private:
	SoundManager()
	{
		m_damageBuffer.loadFromFile("damage.wav");
		m_jumpBuffer.loadFromFile("jump.wav");
		m_startGameBuffer.loadFromFile("game_start.wav");

		m_collisionSound.setBuffer(m_damageBuffer);
		m_jumpSound.setBuffer(m_jumpBuffer);
		m_startGameSound.setBuffer(m_startGameBuffer);
	}

	bool m_isDamageSoundOn = false;

	sf::Sound m_jumpSound;
	sf::Sound m_collisionSound;
	sf::Sound m_startGameSound;

	sf::SoundBuffer m_jumpBuffer;
	sf::SoundBuffer m_damageBuffer;
	sf::SoundBuffer m_startGameBuffer;
};