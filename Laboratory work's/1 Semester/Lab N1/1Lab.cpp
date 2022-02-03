#include <iostream>
#include <iomanip> // cout - округялет число, приходиться подключать для этого setprecision

int main()
{
	double r,s;
	
	std::cout << "Please enter a radius of your circle" << std::endl;
	std::cin >> r;
	
	s = r * r * 3.141592653;

	std::cout << "Here is your area of a circle - " << std::setprecision(9) << s << std::endl;
	return 0;
}

