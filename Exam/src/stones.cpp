#include <SFML/Graphics.hpp>
#include <iostream>
#include "stones.hpp"
#include "character.hpp"

namespace fal
{
	Stone::Stone(int x0, int y0)
	{
		m_x0 = x0;
		m_y0 = y0;

		m_i_stone.loadFromFile("img/roflan.png");
		m_t_stone.loadFromImage(m_i_stone);
		m_s_stone.setTexture(m_t_stone);
		m_s_stone.setPosition(100, 100);
		m_s_stone.setTextureRect(sf::IntRect(0, 0, 55, 53));
	}

	Stone::~Stone()
	{
	}

	void Stone::Animate(int herodirect)
	{
		m_currentPic += 0.055 * 2;
		if (m_currentPic > 4)
			m_currentPic -= 4;
		m_s_stone.setTextureRect(sf::IntRect(int(m_currentPic) * 55, herodirect*55, 55, 54));
	}

	sf::Sprite* Stone::Get()
	{
		{return &m_s_stone;}
	}

}