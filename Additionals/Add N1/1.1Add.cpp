#include <iostream>

int main()
{
	int p1{ 0 }, p2{ 0 }, q1{ 0 }, q2{ 0 }, a{ 0 };
	int min{ 100000000 };
	
	std::cin >> q1 >> p1 >> q2 >> p2 >> a; // q - сколько может p- Цена за 1 поездку a-тонны для перевозки

	for (int i = 0; i <= int(double(a) / double(q1)); i++) 
	{
		for (int j = 0; j <= int(double(a) / double(q2)); j++) 
		{
			if ((i * q1 + j * q2 >= a) && (i * p1 + j * p2 < min) && (i * p1 + j * p2 > 0))
				min = i * p1 + j * p2;
		}
	}
	std::cout << min;
	return 0;

}
