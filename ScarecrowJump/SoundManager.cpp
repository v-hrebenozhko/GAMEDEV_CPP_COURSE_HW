#include "SoundManager.h"

void SoundManager::playMainMenu()
{
	m_mainMenuSound.setLoop(true);
	m_mainMenuSound.play();
}

void SoundManager::playStaticNPC()
{
	m_staticNPCSound.setLoop(true);
	m_staticNPCSound.play();
}

void SoundManager::unpauseStaticNPC()
{
	if (m_staticNPCSound.getStatus() == sf::SoundSource::Paused)
	{
		m_staticNPCSound.play();
	}
}

void SoundManager::playBigStaticNPC()
{
	m_bigStaticNPCSound.setLoop(true);
	m_bigStaticNPCSound.play();
}

void SoundManager::unpauseBigStaticNPC()
{
	if (m_bigStaticNPCSound.getStatus() == sf::SoundSource::Paused)
	{
		m_bigStaticNPCSound.play();
	}
}

void SoundManager::playFloatingNPC()
{
	m_floatingNPCSound.setLoop(true);
	m_floatingNPCSound.play();
}

void SoundManager::unpauseFloatingNPC()
{
	if (m_floatingNPCSound.getStatus() == sf::SoundSource::Paused)
	{
		m_floatingNPCSound.play();
	}
}

void SoundManager::playHelicopter()
{
	m_helicopterSound.setLoop(true);
	m_helicopterSound.play();
}

void SoundManager::unpauseHelicopter()
{
	if (m_helicopterSound.getStatus() == sf::SoundSource::Paused)
	{
		m_helicopterSound.play();
	}
}

void SoundManager::playRocket()
{
	m_rocketSound.setLoop(true);
	m_rocketSound.play();
}

void SoundManager::unpauseRocket()
{
	if (m_rocketSound.getStatus() == sf::SoundSource::Paused)
	{
		m_rocketSound.play();
	}
}

void SoundManager::pauseGameSound()
{
	m_helicopterSound.pause();
	m_rocketSound.pause();
	pauseStaticNPC();
	pauseBigStaticNPC();
	pauseFloatingNPC();
}

void SoundManager::unpauseGameSound()
{
	unpauseRocket();
	unpauseHelicopter();
}

void SoundManager::resetGameSound()
{
	m_helicopterSound.stop();
	m_rocketSound.stop();
	m_staticNPCSound.stop();
	m_bigStaticNPCSound.stop();
	m_floatingNPCSound.stop();
}

