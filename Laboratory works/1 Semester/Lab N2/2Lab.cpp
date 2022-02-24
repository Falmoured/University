#include <iostream>

int main()
{
	int A, B, C;
	A = 0; B = 0; C = 0;
	std::cout << "Please enter A,B,C" << std::endl;
	std::cin >> A >> B >> C;
	
	if ((A < B) && (B < C))
	{
		std::cout << B - C - A << std::endl;
	}

	else if (A % C == 0)
	{
		std::cout << A / C + B << std::endl;
	}

	else
	{
		std::cout << A + B + C << std::endl;
	}
	
	return 0;
}
