#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

namespace fal
{
	class Stone
	{
	public:
		Stone(int x0, int y0);

		void Animate(int herodirect);

		~Stone();

		sf::Sprite* Get();

	private:
		int m_x0, m_y0, m_heroDirection;
		float m_speed{ 5 }, m_time{ 0 }, m_currentPic{ 0 };

		sf::Clock m_clock;
		sf::Image m_i_stone;
		sf::Texture m_t_stone;
		sf::Sprite m_s_stone;


	};
}