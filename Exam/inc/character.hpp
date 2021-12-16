#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

namespace fal
{
	class Character
	{
	public:
		Character(int x0, int y0);

		~Character();

		void KeyboardMove();

		sf::Sprite* Get();

		int GetHeroDirection();
		float GetHeroSpeed();
		void ChangeHeroSpeed(float speed_x,float speed_y);

	private:
		int m_x0, m_y0, m_heroDirection;
		float m_speed{ 5 }, m_time{ 0 }, m_currentPic{ 0 };

		sf::Clock m_clock;
		sf::Image m_i_firstGuard;
		sf::Texture m_t_firstGuard;
		sf::Sprite m_s_firstGuard;
	};
}