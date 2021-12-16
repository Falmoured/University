#include <iostream>
#include "square.hpp"

namespace fal
{
	/*Foursquare::Foursquare(Point M, Point M1)
	{
		m_M = M;
		m_M1 = M1;
		m_D = sqrt((m_M.x - m_M1.x) * (m_M.x - m_M1.x) + (m_M.y - m_M1.y) * (m_M.y - m_M1.y));
	}*/

	Foursquare::~Foursquare() {}

	double Foursquare::Perimeter()
	{
		return m_S * 4;
	}

	double Foursquare::Square()
	{
		return m_S * m_S;
	}

	double Foursquare::GetSide()
	{
		m_D = sqrt((m_M.x - m_M1.x) * (m_M.x - m_M1.x) + (m_M.y - m_M1.y) * (m_M.y - m_M1.y));
		m_S = m_D / sqrt(2);
		return m_S;
	}

	double Foursquare::GetD()
	{
		m_D = sqrt((m_M.x - m_M1.x) * (m_M.x - m_M1.x) + (m_M.y - m_M1.y) * (m_M.y - m_M1.y));
		if (m_D <= 0)
		{
			std::cout << "Incorrect input / D <= 0, please, change your points" << std::endl;
			m_D = 1;
		}
		return m_D;
	}

	void Foursquare::SetM(Point M)
	{
		m_M.x = M.x;
		m_M.y = M.y;
	}

	void Foursquare::SetM1(Point M1)
	{
		m_M1.x = M1.x;
		m_M1.y = M1.y;
	}
}