#include <iostream>
#include "circle.hpp"

int main()
{
	// Создать 5 кругов
	mt::Circle circles[5];

	for (int i = 0; i < 5; i++)
	{
		int R;
		mt::Point M;
		std::cin >> R >> M.x >> M.y;
		circles[i].SetM(M);
		circles[i].SetR(R);

		std::cout << "For the " << i << " square is " << circles[i].Square() << std::endl;
	}
	/*
	Point p{ 0,5 };
	

	Circle circle(p,5);

	circle.SetR(10);
	std::cout << circle.Square() << std::endl;

	return 0;
	*/
}

/*
// Хранение данных
struct Point
{
	int x, y;
};

struct Rectangle
{
	Point p1, p2;
};

double Distance(Point p1, Point p2)
{
	return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

Point Centre(Point p1, Point p2)
{
	Point p3;

	p3.x = (p1.x + p2.x) / 2;
	p3.y = (p1.y + p2.y) / 2;
	
	return p3;
}

int main()
{
	Point p1;
	p1.x = 0;
	p1.y = 0;

	Point p2;
	p2.x = 10;
	p2.y = 10;	

	Point p3 = Centre(p1, p2);

	std::cout << p3.x << " " << p3.y << std::endl;

	return 0;
}
*/