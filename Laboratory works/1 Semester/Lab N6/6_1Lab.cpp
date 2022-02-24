#include <iostream>
#include "6_1Functions.h"
#define N 100

int main()
{
	int n, c;
	std::cin >> n;

	int** array = new int*[n];
	for (int i = 0; i < n; i++)
		array[i] = new int[n];

	fal::Read(n,array);
	
	std::cout << fal::diagonalCheck(n,array) << std::endl;

	c = fal::diagonalCheck(n, array);

	if (c == n)
		fal::changeMatrix(n, array);
	else
		std::cout << "The elemnts do not match the conditions" << std::endl;
	
	for (int i = 0; i < n; i++)
		delete[] array[n];
	delete array;

	return 0;
}