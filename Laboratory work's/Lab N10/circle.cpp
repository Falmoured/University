#include "circle.hpp"
#include <iostream>

namespace mt
{
	Circle::Circle(Point M, int R)
	{
		m_M = M;
		m_R = R;
		if (R <= 0)
		{
			std::cout << "poshel nahui s takim radiusom eblan" << std::endl;
			m_R = 1;
		}
		std::cout << "cons" << std::endl;
	}

	Circle::~Circle()
	{
		std::cout << " des " << std::endl;
	}

	double Circle::Square()
	{
		return m_R * m_R * PI;
	}

	void Circle::SetR(int R)
	{
		m_R = R;
		if (R <= 0)
		{
			std::cout << "poshel nahui s takim radiusom eblan" << std::endl;
			m_R = 0;
		}
	}

	void Circle::SetM(Point M)
	{
		m_M.x = M.x;
		m_M.y = M.y;
	}

}
