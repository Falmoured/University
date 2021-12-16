#include <SFML/Graphics.hpp>
#include <iostream>
#include "character.hpp"

namespace fal
{
	Character::Character(int x0, int y0)
	{
		m_x0 = x0;
		m_y0 = y0;

		m_i_firstGuard.loadFromFile("img/firstGuard.png");
		m_t_firstGuard.loadFromImage(m_i_firstGuard);
		m_s_firstGuard.setTexture(m_t_firstGuard);
		m_s_firstGuard.setPosition(m_x0, m_y0);
		m_s_firstGuard.setTextureRect(sf::IntRect(65, 0, 60, 70));
	}

	Character::~Character()
	{
	}

	void Character::KeyboardMove()
	{
		float m_time = m_clock.getElapsedTime().asMicroseconds();
		m_clock.restart();
		//std::cout << m_time << std::endl; //test
		m_time = m_time / 25000;
		//std::cout << m_time << std::endl; //test

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			m_heroDirection = 0;
			m_currentPic += 0.095 * m_time;
			//std::cout << m_currentPic << std::endl; //test
			if (m_currentPic > 3)
				m_currentPic -= 3;
			m_s_firstGuard.setTextureRect(sf::IntRect(int(m_currentPic) * 63, 85, 63, 85));
			m_s_firstGuard.move(-m_speed*m_time, 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			m_heroDirection = 1;
			m_currentPic += 0.095 * m_time;
			if (m_currentPic > 3)
				m_currentPic -= 3;
			m_s_firstGuard.setTextureRect(sf::IntRect(int(m_currentPic) * 63, 170, 63, 85));
			m_s_firstGuard.move(m_speed*m_time, 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			m_heroDirection = 2;
			m_currentPic += 0.095 * m_time;
			if (m_currentPic > 3)
				m_currentPic -= 3;
			m_s_firstGuard.setTextureRect(sf::IntRect(int(m_currentPic) * 63, 0, 63, 85));
			m_s_firstGuard.move(0, m_speed * m_time);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			m_heroDirection = 3;
			m_currentPic += 0.095 * m_time;
			if (m_currentPic > 3)
				m_currentPic -= 3;
			m_s_firstGuard.setTextureRect(sf::IntRect(int(m_currentPic) * 63, 255, 63, 85));
			m_s_firstGuard.move(0, -m_speed*m_time);
		}
	}

	sf::Sprite* Character::Get()
	{
		{return &m_s_firstGuard;}
	}

	int Character::GetHeroDirection() { return m_heroDirection; }
	float Character::GetHeroSpeed() { return m_speed * m_time; }


	void Character::ChangeHeroSpeed(float speed_x, float speed_y)
	{
		m_s_firstGuard.move(speed_x, speed_y);
	}

}