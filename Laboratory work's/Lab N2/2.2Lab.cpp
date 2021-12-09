#include <iostream>

int main()
{
	int N = 0;
	std::cout << "Please enter number of product" << std::endl;
	std::cin >> N;

	switch (N)
	{
	case 1: std::cout << "Bread" << std::endl;
		break;
	case 2: std::cout << "Carrot" << std::endl;
		break;
	case 3: std::cout << "Cucumber" << std::endl;
		break;
	case 4: std::cout << "Cheese" << std::endl;
		break;
	case 5: std::cout << "Pasta" << std::endl;
		break;
	default:
		std::cout << "There is no any product with this number" << std::endl;
	}
	return 0;
}
