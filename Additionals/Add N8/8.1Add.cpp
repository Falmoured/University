#include <iostream>
#include "square.hpp"

int main()
{
	fal::Foursquare fsq1;
	
	int D;
	fal::Point M, M1;

	std::cin >> M.x >> M.y >> M1.x >> M1.y;

	fsq1.SetM(M);
	fsq1.SetM1(M1);
	//fsq1.GetD(); - вопрос про неудобство пользователю

	std::cout << "Side is " << fsq1.GetSide() << std::endl;
	std::cout << "Perimeter of your foursquare is " << fsq1.Perimeter() << std::endl;
	std::cout << "Square of your forusquare is " << fsq1.Square() << std::endl;

	return 0;
}